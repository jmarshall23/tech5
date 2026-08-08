
// ========================================================================
// ?Free@idMD6Allocator_New@@UAAXPAVidMD6Node@@@Z
// EA  : 0x82826C90
// RVA : 0x00826C90
// PDB : w:\tech5\engine\models\skeletalanimation\md6allocator.cpp
// ========================================================================

void __fastcall idMD6Allocator_New::Free(idMD6Allocator_New *this, idMD6Node *node)
{
  int num; // r9
  int v3; // r31
  idMD6Node **list; // r10
  idList<idMD6Node *,19> *p_nodes; // r30
  int i; // r11
  int v7; // r11
  int v8; // r11

  num = this->nodes.num;
  v3 = 0;
  if ( num > 0 )
  {
    list = this->nodes.list;
    p_nodes = &this->nodes;
    for ( i = 0; list[i] != node; ++i )
    {
      if ( ++v3 >= num )
        return;
    }
    idMem::Free(this: &mem, ptr: list[v3], align: ALIGN_16);
    if ( v3 >= 0 )
    {
      v7 = p_nodes->num;
      if ( v3 < v7 )
      {
        v8 = v7 - 1;
        p_nodes->num = v8;
        if ( v3 != v8 )
          p_nodes->list[v3] = p_nodes->list[v8];
      }
    }
  }
}


// ========================================================================
// ?Size@idMD6Allocator_New@@UBAIXZ
// EA  : 0x82826D30
// RVA : 0x00826D30
// PDB : w:\tech5\engine\models\skeletalanimation\md6allocator.cpp
// ========================================================================

unsigned int __fastcall idMD6Allocator_New::Size(idMD6Allocator_New *this)
{
  int num; // r10
  unsigned int result; // r3
  idMD6Node **list; // r8
  int v5; // r9
  idMD6Node *v6; // r11
  unsigned int type; // r11

  num = this->nodes.num;
  result = 0;
  if ( num > 0 )
  {
    list = this->nodes.list;
    v5 = 0;
    do
    {
      v6 = list[v5];
      if ( v6 != nullptr )
      {
        type = v6->type;
        if ( type <= 7 )
        {
          switch ( type )
          {
            case 1u:
              result += 80;
              break;
            case 2u:
              result += 24;
              break;
            case 3u:
              result += 156;
              break;
            case 4u:
              result += 84;
              break;
            case 5u:
              result += 172;
              break;
            case 6u:
              result += 92;
              break;
            default:
              if ( type != 0 )
                result += 16;
              else
                result += 40;
              break;
          }
        }
      }
      --num;
      ++v5;
    }
    while ( num != 0 );
  }
  return result;
}


// ========================================================================
// ??1idMD6Allocator_New@@UAA@XZ
// EA  : 0x82826DE0
// RVA : 0x00826DE0
// PDB : w:\tech5\engine\models\skeletalanimation\md6allocator.cpp
// ========================================================================

void __fastcall idMD6Allocator_New::~idMD6Allocator_New(idMD6Allocator_New *this)
{
  int v2; // r28
  int v3; // r29
  idMD6Node **list; // r4
  idMD6Node **v5; // r4

  this->__vftable = (idMD6Allocator_New_vtbl *)&idMD6Allocator_New::`vftable';
  v2 = 0;
  if ( this->nodes.num > 0 )
  {
    v3 = 0;
    do
    {
      idMem::Free(this: &mem, ptr: this->nodes.list[v3], align: ALIGN_16);
      ++v2;
      this->nodes.list[v3++] = nullptr;
    }
    while ( v2 < this->nodes.num );
  }
  if ( this->nodes.listStatic == 0 || this->nodes.listStatic == 2 )
  {
    list = this->nodes.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->nodes.list = nullptr;
    this->nodes.size = 0;
  }
  this->nodes.num = 0;
  if ( this->nodes.listStatic == 0 || this->nodes.listStatic == 2 )
  {
    v5 = this->nodes.list;
    if ( v5 != nullptr )
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    this->nodes.list = nullptr;
    this->nodes.size = 0;
  }
  this->nodes.num = 0;
  this->__vftable = (idMD6Allocator_New_vtbl *)&idMD6Allocator::`vftable';
}


// ========================================================================
// __unwind$219927
// EA  : 0x82826EE0
// RVA : 0x00826EE0
// PDB : w:\tech5\engine\models\skeletalanimation\md6allocator.cpp
// ========================================================================

void _unwind_219927()
{
  int v0; // r12

  idMD6Allocator::~idMD6Allocator(this: *(idMD6Allocator **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$219928
// EA  : 0x82826F08
// RVA : 0x00826F08
// PDB : w:\tech5\engine\models\skeletalanimation\md6allocator.cpp
// ========================================================================

void _unwind_219928()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 4));
}


// ========================================================================
// ?Alloc@idMD6Allocator_New@@UAAPAVidMD6Node@@W4nodeType_t@2@@Z
// EA  : 0x828275D8
// RVA : 0x008275D8
// PDB : w:\tech5\engine\models\skeletalanimation\md6allocator.cpp
// ========================================================================

idMD6FusionBranch *__fastcall idMD6Allocator_New::Alloc(idMD6Allocator_New *this, unsigned int type)
{
  idMD6FusionBranch *v2; // r30
  idMD6FusionBranch *v4; // r3
  idMD6LeafPause *v5; // r3
  idMD6LeafPlay *v6; // r3
  idMD6BlendBranch *v7; // r3
  idMD6BlendAdditiveBranch *v8; // r3
  idMD6FusionBranch *v9; // r3
  idMD6BestLeaf *v10; // r3
  idMD6TagFilter *v11; // r3
  _DWORD *p_type; // [sp+50h] [-30h] BYREF

  v2 = nullptr;
  p_type = nullptr;
  if ( type <= 7 )
  {
    switch ( type )
    {
      case 1u:
        v5 = (idMD6LeafPause *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                 size: 0x50u,
                                 tag: TAG_NEW,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
        p_type = &v5->type;
        if ( v5 != nullptr )
          v2 = (idMD6FusionBranch *)idMD6LeafPause::idMD6LeafPause(this: v5);
        p_type = &v2->type;
        break;
      case 2u:
        v6 = (idMD6LeafPlay *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x18u,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
        p_type = &v6->type;
        if ( v6 != nullptr )
          v2 = (idMD6FusionBranch *)idMD6LeafPlay::idMD6LeafPlay(this: v6);
        p_type = &v2->type;
        break;
      case 3u:
        v7 = (idMD6BlendBranch *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                   size: 0x9Cu,
                                   tag: TAG_NEW,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
        p_type = &v7->type;
        if ( v7 != nullptr )
          v2 = (idMD6FusionBranch *)idMD6BlendBranch::idMD6BlendBranch(this: v7);
        p_type = &v2->type;
        break;
      case 4u:
        v8 = (idMD6BlendAdditiveBranch *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                           size: 0x54u,
                                           tag: TAG_NEW,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
        p_type = &v8->type;
        if ( v8 != nullptr )
          v2 = (idMD6FusionBranch *)idMD6BlendAdditiveBranch::idMD6BlendAdditiveBranch(this: v8);
        p_type = &v2->type;
        break;
      case 5u:
        v9 = (idMD6FusionBranch *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                    size: 0xACu,
                                    tag: TAG_NEW,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
        p_type = &v9->type;
        if ( v9 != nullptr )
          v2 = idMD6FusionBranch::idMD6FusionBranch(this: v9);
        p_type = &v2->type;
        break;
      case 6u:
        v10 = (idMD6BestLeaf *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                 size: 0x5Cu,
                                 tag: TAG_NEW,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
        p_type = &v10->type;
        if ( v10 != nullptr )
          v2 = (idMD6FusionBranch *)idMD6BestLeaf::idMD6BestLeaf(this: v10);
        p_type = &v2->type;
        break;
      default:
        if ( type != 0 )
        {
          v11 = (idMD6TagFilter *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                    size: 0x10u,
                                    tag: TAG_NEW,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
          p_type = &v11->type;
          if ( v11 != nullptr )
            v2 = (idMD6FusionBranch *)idMD6TagFilter::idMD6TagFilter(this: v11);
          p_type = &v2->type;
        }
        else
        {
          v4 = (idMD6FusionBranch *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                      size: 0x28u,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
          if ( v4 != nullptr )
          {
            v4->type = 0;
            v4->left = nullptr;
            v4->right = nullptr;
            v4->originBlend = 0;
            v4->blendType = BLEND_LINEAR;
            v4->leftTimeOverride = -1;
            v4->currentAlpha = 0.0;
            v4->rightTimeOverride = -1;
            v4->targetAlpha = 0.0;
            v4->filterGroup = 8;
            v4->alphaRate = 0.0;
            v4->op = 10;
            v2 = v4;
            p_type = &v4->type;
          }
          else
          {
            p_type = nullptr;
          }
        }
        break;
    }
  }
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->nodes,
    obj: (const encounterGroupRole_t *)&p_type);
  return v2;
}


// ========================================================================
// __unwind$220441
// EA  : 0x828278A0
// RVA : 0x008278A0
// PDB : w:\tech5\engine\models\skeletalanimation\md6allocator.cpp
// ========================================================================

void __fastcall _unwind_220441(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// __unwind$220442
// EA  : 0x828278C8
// RVA : 0x008278C8
// PDB : w:\tech5\engine\models\skeletalanimation\md6allocator.cpp
// ========================================================================

void __fastcall _unwind_220442(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// __unwind$220443
// EA  : 0x828278F0
// RVA : 0x008278F0
// PDB : w:\tech5\engine\models\skeletalanimation\md6allocator.cpp
// ========================================================================

void __fastcall _unwind_220443(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// __unwind$220444
// EA  : 0x82827918
// RVA : 0x00827918
// PDB : w:\tech5\engine\models\skeletalanimation\md6allocator.cpp
// ========================================================================

void __fastcall _unwind_220444(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// __unwind$220445
// EA  : 0x82827940
// RVA : 0x00827940
// PDB : w:\tech5\engine\models\skeletalanimation\md6allocator.cpp
// ========================================================================

void __fastcall _unwind_220445(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// __unwind$220446
// EA  : 0x82827968
// RVA : 0x00827968
// PDB : w:\tech5\engine\models\skeletalanimation\md6allocator.cpp
// ========================================================================

void __fastcall _unwind_220446(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// __unwind$220447
// EA  : 0x82827990
// RVA : 0x00827990
// PDB : w:\tech5\engine\models\skeletalanimation\md6allocator.cpp
// ========================================================================

void __fastcall _unwind_220447(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?Condense@idMD6Allocator_New@@UAAXXZ
// EA  : 0x828279B8
// RVA : 0x008279B8
// PDB : w:\tech5\engine\models\skeletalanimation\md6allocator.cpp
// ========================================================================

void __fastcall idMD6Allocator_New::Condense(idMD6Allocator_New *this)
{
  idList<idNavSpline *,5>::Resize(
    this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->nodes,
    newsize: this->nodes.num);
}

