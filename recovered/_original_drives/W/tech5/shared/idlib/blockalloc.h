
// ========================================================================
// ?Shutdown@?$idBlockAlloc@VidTypeInfoNode@@$0CA@$0HC@@@QAAXXZ
// EA  : 0x825C3A40
// RVA : 0x005C3A40
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idTypeInfoNode,32,114>::Shutdown(idBlockAlloc<idTypeInfoNode,32,114> *this)
{
  idBlockAlloc<idTypeInfoNode,32,114>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ??1?$idBlockAlloc@VidTypeInfoNode@@$0CA@$0HC@@@QAA@XZ
// EA  : 0x825C7728
// RVA : 0x005C7728
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<idTypeInfoNode,32,114>::~idBlockAlloc<idTypeInfoNode,32,114>(
        idBlockAlloc<idTypeInfoNode,32,114> *this)
{
  idBlockAlloc<idTypeInfoNode,32,114>::Shutdown(this);
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@VidAASClipLink@@$0IA@$0CF@@@AAAXXZ
// EA  : 0x826B4770
// RVA : 0x006B4770
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idAASClipLink,128,37>::AllocNewBlock(idBlockAlloc<idAASClipLink,128,37> *this)
{
  idBlockAlloc<idAASClipLink,128,37>::idBlock *v2; // r3
  idBlockAlloc<idAASClipLink,128,37>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idAASClipLink,128,37>::element_t *free; // r7

  v2 = (idBlockAlloc<idAASClipLink,128,37>::idBlock *)idMem::AllocWithLocation(
                                                        this: &mem,
                                                        location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                        size: 0x100Cu,
                                                        tag: TAG_AAS,
                                                        zeroBuffer: false,
                                                        align: ALIGN_16,
                                                        heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 32; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idAASClipLink *)v3;
    v3[-1].data = (idAASClipLink *)&v3[-2];
    v3->data = (idAASClipLink *)&v3[-1];
    v3[-2].data = (idAASClipLink *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 128;
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@VidMD6LeafPause@@$03$0BC@@@QAAXXZ
// EA  : 0x826F28B8
// RVA : 0x006F28B8
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6LeafPause,4,18>::Shutdown(idBlockAlloc<idMD6LeafPause,4,18> *this)
{
  idBlockAlloc<idMD6LeafPause,4,18>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@VidMD6Branch@@$0BA@$0BC@@@QAAXXZ
// EA  : 0x826F2938
// RVA : 0x006F2938
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6Branch,16,18>::Shutdown(idBlockAlloc<idMD6Branch,16,18> *this)
{
  idBlockAlloc<idMD6Branch,16,18>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@VidMD6BlendBranch@@$0BA@$0BC@@@QAAXXZ
// EA  : 0x826F29B8
// RVA : 0x006F29B8
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6BlendBranch,16,18>::Shutdown(idBlockAlloc<idMD6BlendBranch,16,18> *this)
{
  idBlockAlloc<idMD6BlendBranch,16,18>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@VidSWFSpriteInstance@@$0BA@$0EI@@@QAAXXZ
// EA  : 0x826F2A38
// RVA : 0x006F2A38
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idSWFSpriteInstance,16,72>::Shutdown(idBlockAlloc<idMD6BestLeaf,16,18> *this)
{
  idBlockAlloc<idMD6BestLeaf,16,18>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@VidMD6FusionBranch@@$0BA@$0BC@@@QAAXXZ
// EA  : 0x826F2AB8
// RVA : 0x006F2AB8
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6FusionBranch,16,18>::Shutdown(idBlockAlloc<idMD6FusionBranch,16,18> *this)
{
  idBlockAlloc<idMD6FusionBranch,16,18>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@VidMD6TagFilter@@$0BA@$0BC@@@QAAXXZ
// EA  : 0x826F2B38
// RVA : 0x006F2B38
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6TagFilter,16,18>::Shutdown(idBlockAlloc<idMD6TagFilter,16,18> *this)
{
  idBlockAlloc<idMD6TagFilter,16,18>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ??1?$idBlockAlloc@VidMD6LeafPause@@$03$0BC@@@QAA@XZ
// EA  : 0x826F3260
// RVA : 0x006F3260
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<idMD6LeafPause,4,18>::~idBlockAlloc<idMD6LeafPause,4,18>(
        idBlockAlloc<idMD6LeafPause,4,18> *this)
{
  idBlockAlloc<idMD6LeafPause,4,18>::Shutdown(this);
}


// ========================================================================
// ??1?$idBlockAlloc@VidMD6Branch@@$0BA@$0BC@@@QAA@XZ
// EA  : 0x826F3268
// RVA : 0x006F3268
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<idMD6Branch,16,18>::~idBlockAlloc<idMD6Branch,16,18>(
        idBlockAlloc<idMD6Branch,16,18> *this)
{
  idBlockAlloc<idMD6Branch,16,18>::Shutdown(this);
}


// ========================================================================
// ??1?$idBlockAlloc@VidMD6BlendBranch@@$0BA@$0BC@@@QAA@XZ
// EA  : 0x826F3270
// RVA : 0x006F3270
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<idMD6BlendBranch,16,18>::~idBlockAlloc<idMD6BlendBranch,16,18>(
        idBlockAlloc<idMD6BlendBranch,16,18> *this)
{
  idBlockAlloc<idMD6BlendBranch,16,18>::Shutdown(this);
}


// ========================================================================
// ??1?$idBlockAlloc@VidMD6BestLeaf@@$0BA@$0BC@@@QAA@XZ
// EA  : 0x826F3278
// RVA : 0x006F3278
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<idMD6BestLeaf,16,18>::~idBlockAlloc<idMD6BestLeaf,16,18>(
        idBlockAlloc<idMD6BestLeaf,16,18> *this)
{
  idBlockAlloc<idSWFSpriteInstance,16,72>::Shutdown(this);
}


// ========================================================================
// ??1?$idBlockAlloc@VidMD6FusionBranch@@$0BA@$0BC@@@QAA@XZ
// EA  : 0x826F3280
// RVA : 0x006F3280
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<idMD6FusionBranch,16,18>::~idBlockAlloc<idMD6FusionBranch,16,18>(
        idBlockAlloc<idMD6FusionBranch,16,18> *this)
{
  idBlockAlloc<idMD6FusionBranch,16,18>::Shutdown(this);
}


// ========================================================================
// ??1?$idBlockAlloc@VidMD6TagFilter@@$0BA@$0BC@@@QAA@XZ
// EA  : 0x826F3288
// RVA : 0x006F3288
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<idMD6TagFilter,16,18>::~idBlockAlloc<idMD6TagFilter,16,18>(
        idBlockAlloc<idMD6TagFilter,16,18> *this)
{
  idBlockAlloc<idMD6TagFilter,16,18>::Shutdown(this);
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@UclipLink_t@@$0BAA@$0N@@@QAAXXZ
// EA  : 0x8272B980
// RVA : 0x0072B980
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<clipLink_t,256,13>::Shutdown(idBlockAlloc<clipLink_t,256,13> *this)
{
  idBlockAlloc<clipLink_t,256,13>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ??1?$idBlockAlloc@UclipLink_t@@$0BAA@$0N@@@QAA@XZ
// EA  : 0x8272C7F0
// RVA : 0x0072C7F0
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<clipLink_t,256,13>::~idBlockAlloc<clipLink_t,256,13>(
        idBlockAlloc<clipLink_t,256,13> *this)
{
  idBlockAlloc<clipLink_t,256,13>::Shutdown(this);
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@UclipLink_t@@$0BAA@$0N@@@AAAXXZ
// EA  : 0x82738978
// RVA : 0x00738978
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<clipLink_t,256,13>::AllocNewBlock(idBlockAlloc<clipLink_t,256,13> *this)
{
  idBlockAlloc<clipLink_t,256,13>::idBlock *v2; // r3
  idBlockAlloc<clipLink_t,256,13>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<clipLink_t,256,13>::element_t *free; // r7

  v2 = (idBlockAlloc<clipLink_t,256,13>::idBlock *)idMem::AllocWithLocation(
                                                     this: &mem,
                                                     location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                     size: 0x200Cu,
                                                     tag: TAG_COLLISION,
                                                     zeroBuffer: false,
                                                     align: ALIGN_16,
                                                     heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 64; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (clipLink_t *)v3;
    v3[-1].data = (clipLink_t *)&v3[-2];
    v3->data = (clipLink_t *)&v3[-1];
    v3[-2].data = (clipLink_t *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 256;
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@UclipLink_t@@$0BAA@$0N@@@QAAPAUclipLink_t@@XZ
// EA  : 0x82738E90
// RVA : 0x00738E90
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<clipLink_t,256,13>::element_t *__fastcall idBlockAlloc<clipLink_t,256,13>::Alloc(
        idBlockAlloc<clipLink_t,256,13> *this)
{
  idBlockAlloc<clipLink_t,256,13>::element_t *result; // r3

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<clipLink_t,256,13>::AllocNewBlock(this);
  }
  result = this->free;
  ++this->active;
  this->free = (idBlockAlloc<clipLink_t,256,13>::element_t *)result->data;
  result->data = nullptr;
  if ( this->clearAllocs )
  {
    result->data = nullptr;
    *(_DWORD *)&result->buffer[4] = 0;
    *(_DWORD *)&result->buffer[8] = 0;
    *(_DWORD *)&result->buffer[12] = 0;
    *(_DWORD *)&result->buffer[16] = 0;
  }
  return result;
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@UtrmCache_t@idTraceModelCache@@$0EA@$0N@@@AAAXXZ
// EA  : 0x82768668
// RVA : 0x00768668
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::AllocNewBlock(
        idBlockAlloc<idTraceModelCache::trmCache_t,64,13> *this)
{
  idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::idBlock *v2; // r3
  idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::element_t *free; // r7

  v2 = (idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::idBlock *)idMem::AllocWithLocation(
                                                                       this: &mem,
                                                                       location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                                       size: 0x180Cu,
                                                                       tag: TAG_COLLISION,
                                                                       zeroBuffer: false,
                                                                       align: ALIGN_16,
                                                                       heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 16; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idTraceModelCache::trmCache_t *)v3;
    v3[-1].data = (idTraceModelCache::trmCache_t *)&v3[-2];
    v3->data = (idTraceModelCache::trmCache_t *)&v3[-1];
    v3[-2].data = (idTraceModelCache::trmCache_t *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 64;
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@UtrmCache_t@idTraceModelCache@@$0EA@$0N@@@QAAXXZ
// EA  : 0x82768708
// RVA : 0x00768708
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::Shutdown(
        idBlockAlloc<idTraceModelCache::trmCache_t,64,13> *this)
{
  idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@UtrmCache_t@idTraceModelCache@@$0EA@$0N@@@QAAPAUtrmCache_t@idTraceModelCache@@XZ
// EA  : 0x82768D80
// RVA : 0x00768D80
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::element_t *__fastcall idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::Alloc(
        idBlockAlloc<idTraceModelCache::trmCache_t,64,13> *this)
{
  idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::element_t *free; // r29

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::AllocNewBlock(this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
    memset(Dst: free, Val: 0, Size: 0x58u);
  idTraceModelCache::trmCache_t::trmCache_t(this: (idTraceModelCache::trmCache_t *)free);
  return free;
}


// ========================================================================
// __unwind$247856
// EA  : 0x82768E14
// RVA : 0x00768E14
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_247856()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@VidRecycledTraceModel@@$0EA@$0N@@@AAAXXZ
// EA  : 0x82769A20
// RVA : 0x00769A20
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idRecycledTraceModel,64,13>::AllocNewBlock(idBlockAlloc<idRecycledTraceModel,64,13> *this)
{
  idBlockAlloc<idRecycledTraceModel,64,13>::idBlock *v2; // r3
  idBlockAlloc<idRecycledTraceModel,64,13>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idRecycledTraceModel,64,13>::element_t *free; // r7

  v2 = (idBlockAlloc<idRecycledTraceModel,64,13>::idBlock *)idMem::AllocWithLocation(
                                                              this: &mem,
                                                              location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                              size: 0x40Cu,
                                                              tag: TAG_COLLISION,
                                                              zeroBuffer: false,
                                                              align: ALIGN_16,
                                                              heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 16; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idRecycledTraceModel *)v3;
    v3[-1].data = (idRecycledTraceModel *)&v3[-2];
    v3->data = (idRecycledTraceModel *)&v3[-1];
    v3[-2].data = (idRecycledTraceModel *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 64;
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@VidMD6LeafPlay@@$0CA@$0BC@@@QAAXXZ
// EA  : 0x82769AC0
// RVA : 0x00769AC0
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6LeafPlay,32,18>::Shutdown(idBlockAlloc<idMD6LeafPlay,32,18> *this)
{
  idBlockAlloc<idMD6LeafPlay,32,18>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@VidRecycledTraceModel@@$0EA@$0N@@@QAAPAVidRecycledTraceModel@@XZ
// EA  : 0x82769B40
// RVA : 0x00769B40
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idRecycledTraceModel,64,13>::element_t *__fastcall idBlockAlloc<idRecycledTraceModel,64,13>::Alloc(
        idBlockAlloc<idRecycledTraceModel,64,13> *this)
{
  idBlockAlloc<idRecycledTraceModel,64,13>::element_t *result; // r3

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idRecycledTraceModel,64,13>::AllocNewBlock(this);
  }
  result = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idRecycledTraceModel,64,13>::element_t *)result->data;
  result->data = nullptr;
  if ( this->clearAllocs )
  {
    result->data = nullptr;
    *(_DWORD *)&result->buffer[4] = 0;
  }
  result->data = nullptr;
  *(_DWORD *)&result->buffer[4] = -1;
  return result;
}


// ========================================================================
// ??1?$idBlockAlloc@VidRecycledTraceModel@@$0EA@$0N@@@QAA@XZ
// EA  : 0x82769BE0
// RVA : 0x00769BE0
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<idRecycledTraceModel,64,13>::~idBlockAlloc<idRecycledTraceModel,64,13>(
        idBlockAlloc<idMD6LeafPlay,32,18> *this)
{
  idBlockAlloc<idMD6LeafPlay,32,18>::Shutdown(this);
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@VidSWFSpriteInstance@@$0BA@$0EI@@@AAAXXZ
// EA  : 0x82776260
// RVA : 0x00776260
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idSWFSpriteInstance,16,72>::AllocNewBlock(idBlockAlloc<idSWFSpriteInstance,16,72> *this)
{
  idBlockAlloc<idSWFSpriteInstance,16,72>::idBlock *v2; // r3
  idBlockAlloc<idSWFSpriteInstance,16,72>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idSWFSpriteInstance,16,72>::element_t *free; // r7

  v2 = (idBlockAlloc<idSWFSpriteInstance,16,72>::idBlock *)idMem::AllocWithLocation(
                                                             this: &mem,
                                                             location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                             size: 0x60Cu,
                                                             tag: TAG_SWF,
                                                             zeroBuffer: false,
                                                             align: ALIGN_16,
                                                             heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 4; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idSWFSpriteInstance *)v3;
    v3[-1].data = (idSWFSpriteInstance *)&v3[-2];
    v3->data = (idSWFSpriteInstance *)&v3[-1];
    v3[-2].data = (idSWFSpriteInstance *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 16;
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@VidSWFTextInstance@@$0BA@$0EI@@@QAAXXZ
// EA  : 0x82776300
// RVA : 0x00776300
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idSWFTextInstance,16,72>::Shutdown(idBlockAlloc<idSWFTextInstance,16,72> *this)
{
  idBlockAlloc<idSWFTextInstance,16,72>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@VidSWFSpriteInstance@@$0BA@$0EI@@@QAAPAVidSWFSpriteInstance@@XZ
// EA  : 0x82776A90
// RVA : 0x00776A90
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idSWFSpriteInstance,16,72>::element_t *__fastcall idBlockAlloc<idSWFSpriteInstance,16,72>::Alloc(
        idBlockAlloc<idSWFSpriteInstance,16,72> *this)
{
  idBlockAlloc<idSWFSpriteInstance,16,72>::element_t *free; // r29

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idSWFSpriteInstance,16,72>::AllocNewBlock(this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idSWFSpriteInstance,16,72>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
    memset(Dst: free, Val: 0, Size: sizeof(idBlockAlloc<idSWFSpriteInstance,16,72>::element_t));
  idSWFSpriteInstance::idSWFSpriteInstance(this: (idSWFSpriteInstance *)free);
  return free;
}


// ========================================================================
// __unwind$225184
// EA  : 0x82776B24
// RVA : 0x00776B24
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_225184()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ??1?$idBlockAlloc@VidSWFTextInstance@@$0BA@$0EI@@@QAA@XZ
// EA  : 0x82776B50
// RVA : 0x00776B50
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<idSWFTextInstance,16,72>::~idBlockAlloc<idSWFTextInstance,16,72>(
        idBlockAlloc<idSWFTextInstance,16,72> *this)
{
  idBlockAlloc<idSWFTextInstance,16,72>::Shutdown(this);
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@VidSWFTextInstance@@$0BA@$0EI@@@AAAXXZ
// EA  : 0x827915A8
// RVA : 0x007915A8
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idSWFTextInstance,16,72>::AllocNewBlock(idBlockAlloc<idSWFTextInstance,16,72> *this)
{
  idBlockAlloc<idSWFTextInstance,16,72>::idBlock *v2; // r3
  idBlockAlloc<idSWFTextInstance,16,72>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idSWFTextInstance,16,72>::element_t *free; // r7

  v2 = (idBlockAlloc<idSWFTextInstance,16,72>::idBlock *)idMem::AllocWithLocation(
                                                           this: &mem,
                                                           location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                           size: 0x1C0Cu,
                                                           tag: TAG_SWF,
                                                           zeroBuffer: false,
                                                           align: ALIGN_16,
                                                           heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 4; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idSWFTextInstance *)v3;
    v3[-1].data = (idSWFTextInstance *)&v3[-2];
    v3->data = (idSWFTextInstance *)&v3[-1];
    v3[-2].data = (idSWFTextInstance *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 16;
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@VidSWFTextInstance@@$0BA@$0EI@@@QAAPAVidSWFTextInstance@@XZ
// EA  : 0x82792370
// RVA : 0x00792370
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idSWFTextInstance,16,72>::element_t *__fastcall idBlockAlloc<idSWFTextInstance,16,72>::Alloc(
        idBlockAlloc<idSWFTextInstance,16,72> *this)
{
  idBlockAlloc<idSWFTextInstance,16,72>::element_t *free; // r29

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idSWFTextInstance,16,72>::AllocNewBlock(this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idSWFTextInstance,16,72>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
    memset(Dst: free, Val: 0, Size: 0x1B4u);
  idSWFTextInstance::idSWFTextInstance(this: (idSWFTextInstance *)free);
  return free;
}


// ========================================================================
// __unwind$225682
// EA  : 0x82792404
// RVA : 0x00792404
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_225682()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@VidMD6LeafPlay@@$0CA@$0BC@@@AAAXXZ
// EA  : 0x82842780
// RVA : 0x00842780
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6LeafPlay,32,18>::AllocNewBlock(idBlockAlloc<idMD6LeafPlay,32,18> *this)
{
  idBlockAlloc<idMD6LeafPlay,32,18>::idBlock *v2; // r3
  idBlockAlloc<idMD6LeafPlay,32,18>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idMD6LeafPlay,32,18>::element_t *free; // r7

  v2 = (idBlockAlloc<idMD6LeafPlay,32,18>::idBlock *)idMem::AllocWithLocation(
                                                       this: &mem,
                                                       location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                       size: 0x40Cu,
                                                       tag: TAG_MD6_NODES,
                                                       zeroBuffer: false,
                                                       align: ALIGN_16,
                                                       heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 8; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idMD6LeafPlay *)v3;
    v3[-1].data = (idMD6LeafPlay *)&v3[-2];
    v3->data = (idMD6LeafPlay *)&v3[-1];
    v3[-2].data = (idMD6LeafPlay *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 32;
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@VidMD6LeafPause@@$03$0BC@@@AAAXXZ
// EA  : 0x82842820
// RVA : 0x00842820
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6LeafPause,4,18>::AllocNewBlock(idBlockAlloc<idMD6LeafPause,4,18> *this)
{
  idBlockAlloc<idMD6LeafPause,4,18>::idBlock *v2; // r3

  v2 = (idBlockAlloc<idMD6LeafPause,4,18>::idBlock *)idMem::AllocWithLocation(
                                                       this: &mem,
                                                       location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                       size: 0x14Cu,
                                                       tag: TAG_MD6_NODES,
                                                       zeroBuffer: false,
                                                       align: ALIGN_16,
                                                       heap: HEAP_DEFAULTHEAP);
  v2->next = this->blocks;
  this->blocks = v2;
  v2->elements[0].data = (idMD6LeafPause *)this->free;
  v2->elements[1].data = (idMD6LeafPause *)v2;
  v2->elements[2].data = (idMD6LeafPause *)&v2->elements[1];
  v2->elements[3].data = (idMD6LeafPause *)&v2->elements[2];
  this->free = &v2->elements[3];
  this->total += 4;
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@VidMD6Branch@@$0BA@$0BC@@@AAAXXZ
// EA  : 0x828428B0
// RVA : 0x008428B0
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6Branch,16,18>::AllocNewBlock(idBlockAlloc<idMD6Branch,16,18> *this)
{
  idBlockAlloc<idMD6Branch,16,18>::idBlock *v2; // r3
  idBlockAlloc<idMD6Branch,16,18>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idMD6Branch,16,18>::element_t *free; // r7

  v2 = (idBlockAlloc<idMD6Branch,16,18>::idBlock *)idMem::AllocWithLocation(
                                                     this: &mem,
                                                     location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                     size: 0x30Cu,
                                                     tag: TAG_MD6_NODES,
                                                     zeroBuffer: false,
                                                     align: ALIGN_16,
                                                     heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 4; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idMD6Branch *)v3;
    v3[-1].data = (idMD6Branch *)&v3[-2];
    v3->data = (idMD6Branch *)&v3[-1];
    v3[-2].data = (idMD6Branch *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 16;
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@VidMD6BlendBranch@@$0BA@$0BC@@@AAAXXZ
// EA  : 0x82842950
// RVA : 0x00842950
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6BlendBranch,16,18>::AllocNewBlock(idBlockAlloc<idMD6BlendBranch,16,18> *this)
{
  idBlockAlloc<idMD6BlendBranch,16,18>::idBlock *v2; // r3
  idBlockAlloc<idMD6BlendBranch,16,18>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idMD6BlendBranch,16,18>::element_t *free; // r7

  v2 = (idBlockAlloc<idMD6BlendBranch,16,18>::idBlock *)idMem::AllocWithLocation(
                                                          this: &mem,
                                                          location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                          size: 0xA0Cu,
                                                          tag: TAG_MD6_NODES,
                                                          zeroBuffer: false,
                                                          align: ALIGN_16,
                                                          heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 4; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idMD6BlendBranch *)v3;
    v3[-1].data = (idMD6BlendBranch *)&v3[-2];
    v3->data = (idMD6BlendBranch *)&v3[-1];
    v3[-2].data = (idMD6BlendBranch *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 16;
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@VidMD6BestLeaf@@$0BA@$0BC@@@AAAXXZ
// EA  : 0x828429F0
// RVA : 0x008429F0
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6BestLeaf,16,18>::AllocNewBlock(idBlockAlloc<idMD6BestLeaf,16,18> *this)
{
  idBlockAlloc<idMD6BestLeaf,16,18>::idBlock *v2; // r3
  idBlockAlloc<idMD6BestLeaf,16,18>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idMD6BestLeaf,16,18>::element_t *free; // r7

  v2 = (idBlockAlloc<idMD6BestLeaf,16,18>::idBlock *)idMem::AllocWithLocation(
                                                       this: &mem,
                                                       location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                       size: 0x60Cu,
                                                       tag: TAG_MD6_NODES,
                                                       zeroBuffer: false,
                                                       align: ALIGN_16,
                                                       heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 4; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idMD6BestLeaf *)v3;
    v3[-1].data = (idMD6BestLeaf *)&v3[-2];
    v3->data = (idMD6BestLeaf *)&v3[-1];
    v3[-2].data = (idMD6BestLeaf *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 16;
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@VidMD6FusionBranch@@$0BA@$0BC@@@AAAXXZ
// EA  : 0x82842A90
// RVA : 0x00842A90
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6FusionBranch,16,18>::AllocNewBlock(idBlockAlloc<idMD6FusionBranch,16,18> *this)
{
  idBlockAlloc<idMD6FusionBranch,16,18>::idBlock *v2; // r3
  idBlockAlloc<idMD6FusionBranch,16,18>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idMD6FusionBranch,16,18>::element_t *free; // r7

  v2 = (idBlockAlloc<idMD6FusionBranch,16,18>::idBlock *)idMem::AllocWithLocation(
                                                           this: &mem,
                                                           location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                           size: 0xB0Cu,
                                                           tag: TAG_MD6_NODES,
                                                           zeroBuffer: false,
                                                           align: ALIGN_16,
                                                           heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 4; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idMD6FusionBranch *)v3;
    v3[-1].data = (idMD6FusionBranch *)&v3[-2];
    v3->data = (idMD6FusionBranch *)&v3[-1];
    v3[-2].data = (idMD6FusionBranch *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 16;
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@VidMD6TagFilter@@$0BA@$0BC@@@AAAXXZ
// EA  : 0x82842B30
// RVA : 0x00842B30
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6TagFilter,16,18>::AllocNewBlock(idBlockAlloc<idMD6TagFilter,16,18> *this)
{
  idBlockAlloc<idMD6TagFilter,16,18>::idBlock *v2; // r3
  idBlockAlloc<idMD6TagFilter,16,18>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idMD6TagFilter,16,18>::element_t *free; // r7

  v2 = (idBlockAlloc<idMD6TagFilter,16,18>::idBlock *)idMem::AllocWithLocation(
                                                        this: &mem,
                                                        location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                        size: 0x10Cu,
                                                        tag: TAG_MD6_NODES,
                                                        zeroBuffer: false,
                                                        align: ALIGN_16,
                                                        heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 4; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idMD6TagFilter *)v3;
    v3[-1].data = (idMD6TagFilter *)&v3[-2];
    v3->data = (idMD6TagFilter *)&v3[-1];
    v3[-2].data = (idMD6TagFilter *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 16;
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@VidMD6LeafPlay@@$0CA@$0BC@@@QAAPAVidMD6LeafPlay@@XZ
// EA  : 0x82842BD8
// RVA : 0x00842BD8
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idMD6LeafPlay,32,18>::element_t *__fastcall idBlockAlloc<idMD6LeafPlay,32,18>::Alloc(
        idBlockAlloc<idMD6LeafPlay,32,18> *this)
{
  idBlockAlloc<idMD6LeafPlay,32,18>::element_t *free; // r30
  unsigned __int8 *v4; // r11
  int i; // ctr

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idMD6LeafPlay,32,18>::AllocNewBlock(this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idMD6LeafPlay,32,18>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
  {
    v4 = &free[-1].buffer[28];
    for ( i = 6; i != 0; --i )
    {
      v4 += 4;
      *(_DWORD *)v4 = 0;
    }
  }
  idMD6Leaf::idMD6Leaf(this: (idMD6Leaf *)free, type_: NODE_LEAF_PLAY);
  *(_DWORD *)&free->buffer[12] = 0;
  free->buffer[20] = 0;
  free->buffer[21] = 0;
  *(float *)&free->buffer[16] = 1.0;
  return free;
}


// ========================================================================
// __unwind$220611
// EA  : 0x82842C90
// RVA : 0x00842C90
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_220611()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@VidMD6Branch@@$0BA@$0BC@@@QAAPAVidMD6Branch@@XZ
// EA  : 0x82842CC0
// RVA : 0x00842CC0
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idMD6Branch,16,18>::element_t *__fastcall idBlockAlloc<idMD6Branch,16,18>::Alloc(
        idBlockAlloc<idMD6Branch,16,18> *this)
{
  idBlockAlloc<idMD6Branch,16,18>::element_t *result; // r3
  unsigned __int8 *v3; // r10
  int i; // ctr

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idMD6Branch,16,18>::AllocNewBlock(this);
  }
  result = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idMD6Branch,16,18>::element_t *)result->data;
  result->data = nullptr;
  if ( this->clearAllocs )
  {
    v3 = &result[-1].buffer[44];
    for ( i = 10; i != 0; --i )
    {
      v3 += 4;
      *(_DWORD *)v3 = 0;
    }
  }
  result->buffer[0] = 0;
  *(_DWORD *)&result->buffer[4] = 0;
  *(_DWORD *)&result->buffer[8] = 0;
  *(_DWORD *)&result->buffer[12] = -1;
  *(_DWORD *)&result->buffer[16] = -1;
  result->buffer[20] = 8;
  *(float *)&result->buffer[24] = 0.0;
  result->buffer[21] = 10;
  *(float *)&result->buffer[28] = 0.0;
  result->buffer[22] = 0;
  *(float *)&result->buffer[32] = 0.0;
  *(_DWORD *)&result->buffer[36] = 0;
  return result;
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@VidMD6BestLeaf@@$0BA@$0BC@@@QAAPAVidMD6BestLeaf@@XZ
// EA  : 0x82842DA8
// RVA : 0x00842DA8
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idMD6BestLeaf,16,18>::element_t *__fastcall idBlockAlloc<idMD6BestLeaf,16,18>::Alloc(
        idBlockAlloc<idMD6BestLeaf,16,18> *this)
{
  idBlockAlloc<idMD6BestLeaf,16,18>::element_t *free; // r29

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idMD6BestLeaf,16,18>::AllocNewBlock(this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idMD6BestLeaf,16,18>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
    memset(Dst: free, Val: 0, Size: 0x5Cu);
  idMD6BestLeaf::idMD6BestLeaf(this: (idMD6BestLeaf *)free);
  return free;
}


// ========================================================================
// __unwind$220662
// EA  : 0x82842E3C
// RVA : 0x00842E3C
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_220662()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@VidMD6TagFilter@@$0BA@$0BC@@@QAAPAVidMD6TagFilter@@XZ
// EA  : 0x82842E70
// RVA : 0x00842E70
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idMD6TagFilter,16,18>::element_t *__fastcall idBlockAlloc<idMD6TagFilter,16,18>::Alloc(
        idBlockAlloc<idMD6TagFilter,16,18> *this)
{
  idBlockAlloc<idMD6TagFilter,16,18>::element_t *free; // r30

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idMD6TagFilter,16,18>::AllocNewBlock(this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idMD6TagFilter,16,18>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
  {
    free->data = nullptr;
    *(_DWORD *)&free->buffer[4] = 0;
    *(_DWORD *)&free->buffer[8] = 0;
    *(_DWORD *)&free->buffer[12] = 0;
  }
  idMD6TagFilter::idMD6TagFilter(this: (idMD6TagFilter *)free);
  return free;
}


// ========================================================================
// __unwind$220688
// EA  : 0x82842F04
// RVA : 0x00842F04
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_220688()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ?Free@?$idBlockAlloc@VidMD6LeafPause@@$03$0BC@@@QAAXPAVidMD6LeafPause@@@Z
// EA  : 0x82842FA8
// RVA : 0x00842FA8
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6LeafPause,4,18>::Free(idBlockAlloc<idMD6LeafPause,4,18> *this, idMD6LeafPause *t)
{
  if ( t != nullptr )
  {
    idMD6LeafPause::~idMD6LeafPause(this: t);
    *(_DWORD *)&t->type = this->free;
    this->free = (idBlockAlloc<idMD6LeafPause,4,18>::element_t *)t;
    --this->active;
  }
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@VidMD6LeafPause@@$03$0BC@@@QAAPAVidMD6LeafPause@@XZ
// EA  : 0x828434A8
// RVA : 0x008434A8
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idMD6LeafPause,4,18>::element_t *__fastcall idBlockAlloc<idMD6LeafPause,4,18>::Alloc(
        idBlockAlloc<idMD6LeafPause,4,18> *this)
{
  idBlockAlloc<idMD6LeafPause,4,18>::element_t *free; // r29

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idMD6LeafPause,4,18>::AllocNewBlock(this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idMD6LeafPause,4,18>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
    memset(Dst: free, Val: 0, Size: sizeof(idBlockAlloc<idMD6LeafPause,4,18>::element_t));
  idMD6LeafPause::idMD6LeafPause(this: (idMD6LeafPause *)free);
  return free;
}


// ========================================================================
// __unwind$221632
// EA  : 0x8284353C
// RVA : 0x0084353C
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_221632()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@VidMD6BlendAdditiveBranch@@$0BA@$0BC@@@QAAPAVidMD6BlendAdditiveBranch@@XZ
// EA  : 0x82843570
// RVA : 0x00843570
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idMD6BlendAdditiveBranch,16,18>::element_t *__fastcall idBlockAlloc<idMD6BlendAdditiveBranch,16,18>::Alloc(
        idBlockAlloc<idMD6BlendAdditiveBranch,16,18> *this)
{
  idBlockAlloc<idMD6BlendAdditiveBranch,16,18>::element_t *free; // r30

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idMD6BestLeaf,16,18>::AllocNewBlock((idBlockAlloc<idMD6BestLeaf,16,18> *)this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idMD6BlendAdditiveBranch,16,18>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
    memset(Dst: free, Val: 0, Size: 0x54u);
  idMD6BlendBranch_Base::idMD6BlendBranch_Base(this: (idMD6BlendBranch_Base *)free, nodeType: NODE_BLENDA_BRANCH);
  *(_DWORD *)&free->buffer[80] = 0;
  *(float *)&free->buffer[72] = 0.0;
  *(float *)&free->buffer[76] = 0.0;
  return free;
}


// ========================================================================
// __unwind$221655_0
// EA  : 0x8284361C
// RVA : 0x0084361C
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_221655_0()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@VidMD6BlendBranch@@$0BA@$0BC@@@QAAPAVidMD6BlendBranch@@XZ
// EA  : 0x828436C8
// RVA : 0x008436C8
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idMD6BlendBranch,16,18>::element_t *__fastcall idBlockAlloc<idMD6BlendBranch,16,18>::Alloc(
        idBlockAlloc<idMD6BlendBranch,16,18> *this)
{
  idBlockAlloc<idMD6BlendBranch,16,18>::element_t *free; // r29

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idMD6BlendBranch,16,18>::AllocNewBlock(this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idMD6BlendBranch,16,18>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
    memset(Dst: free, Val: 0, Size: 0x9Cu);
  idMD6BlendBranch::idMD6BlendBranch(this: (idMD6BlendBranch *)free);
  return free;
}


// ========================================================================
// __unwind$221871
// EA  : 0x8284375C
// RVA : 0x0084375C
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_221871()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ?Free@?$idBlockAlloc@VidMD6BlendBranch@@$0BA@$0BC@@@QAAXPAVidMD6BlendBranch@@@Z
// EA  : 0x82843788
// RVA : 0x00843788
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6BlendBranch,16,18>::Free(
        idBlockAlloc<idMD6BlendBranch,16,18> *this,
        idMD6BlendBranch *t)
{
  if ( t != nullptr )
  {
    idMD6BlendBranch::~idMD6BlendBranch(this: t);
    *(_DWORD *)&t->type = this->free;
    this->free = (idBlockAlloc<idMD6BlendBranch,16,18>::element_t *)t;
    --this->active;
  }
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@VidMD6FusionBranch@@$0BA@$0BC@@@QAAPAVidMD6FusionBranch@@XZ
// EA  : 0x828437F0
// RVA : 0x008437F0
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idMD6FusionBranch,16,18>::element_t *__fastcall idBlockAlloc<idMD6FusionBranch,16,18>::Alloc(
        idBlockAlloc<idMD6FusionBranch,16,18> *this)
{
  idBlockAlloc<idMD6FusionBranch,16,18>::element_t *free; // r29

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idMD6FusionBranch,16,18>::AllocNewBlock(this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idMD6FusionBranch,16,18>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
    memset(Dst: free, Val: 0, Size: 0xACu);
  idMD6FusionBranch::idMD6FusionBranch(this: (idMD6FusionBranch *)free);
  return free;
}


// ========================================================================
// __unwind$221909
// EA  : 0x82843884
// RVA : 0x00843884
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_221909()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ?Free@?$idBlockAlloc@VidMD6BestLeaf@@$0BA@$0BC@@@QAAXPAVidMD6BestLeaf@@@Z
// EA  : 0x828438B0
// RVA : 0x008438B0
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6BestLeaf,16,18>::Free(idBlockAlloc<idMD6BestLeaf,16,18> *this, idMD6BestLeaf *t)
{
  if ( t != nullptr )
  {
    idMD6BestLeaf::~idMD6BestLeaf(this: t);
    *(_DWORD *)&t->type = this->free;
    this->free = (idBlockAlloc<idMD6BestLeaf,16,18>::element_t *)t;
    --this->active;
  }
}


// ========================================================================
// ?Free@?$idBlockAlloc@VidMD6BlendAdditiveBranch@@$0BA@$0BC@@@QAAXPAVidMD6BlendAdditiveBranch@@@Z
// EA  : 0x828439E8
// RVA : 0x008439E8
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6BlendAdditiveBranch,16,18>::Free(
        idBlockAlloc<idMD6BlendAdditiveBranch,16,18> *this,
        idSWFText *t)
{
  if ( t != nullptr )
  {
    idSWFText::~idSWFText(this: t);
    LODWORD(t->bounds.tl.x) = this->free;
    this->free = (idBlockAlloc<idMD6BlendAdditiveBranch,16,18>::element_t *)t;
    --this->active;
  }
}


// ========================================================================
// ?Free@?$idBlockAlloc@VidMD6FusionBranch@@$0BA@$0BC@@@QAAXPAVidMD6FusionBranch@@@Z
// EA  : 0x82843A48
// RVA : 0x00843A48
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idMD6FusionBranch,16,18>::Free(
        idBlockAlloc<idMD6FusionBranch,16,18> *this,
        idMD6FusionBranch *t)
{
  if ( t != nullptr )
  {
    idMD6FusionBranch::~idMD6FusionBranch(this: t);
    *(_DWORD *)&t->type = this->free;
    this->free = (idBlockAlloc<idMD6FusionBranch,16,18>::element_t *)t;
    --this->active;
  }
}


// ========================================================================
// ?AllocInternal@?$idDynamicBlockAlloc@E$0BAAAAA@$0BA@$0DM@@@AAAPAV?$idDynamicBlock@E$0DM@@@H@Z
// EA  : 0x8287D538
// RVA : 0x0087D538
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idDynamicBlock<unsigned char,60> *__fastcall idDynamicBlockAlloc<unsigned char,1048576,16,60>::AllocInternal(
        idDynamicBlockAlloc<unsigned char,1048576,16,60> *this,
        const int num)
{
  unsigned int v3; // r29
  idDynamicBlock<unsigned char,60> *SmallestLargerEqual; // r3
  idDynamicBlock<unsigned char,60> *v5; // r30
  idDynamicBlock<unsigned char,60> *result; // r3
  int v7; // r11
  unsigned int v8; // r30
  idDynamicBlock<unsigned char,60> *lastBlock; // r11
  int v10; // r10

  v3 = (num + 15) & 0xFFFFFFF0;
  SmallestLargerEqual = idBTree<idDynamicBlock<char,119>,int,4>::FindSmallestLargerEqual(this: &this->freeTree, key: v3);
  v5 = SmallestLargerEqual;
  if ( SmallestLargerEqual != nullptr )
  {
    idDynamicBlockAlloc<unsigned char,1024,16,89>::UnlinkFreeInternal(this, block: SmallestLargerEqual);
    return v5;
  }
  if ( !this->allowAllocs )
    return v5;
  v7 = v3 + 16;
  if ( (int)(v3 + 16) < 0x100000 )
    v7 = 0x100000;
  v8 = (v7 + 0xFFFF) & 0xFFFF0000;
  result = (idDynamicBlock<unsigned char,60> *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(887) : _memTag_",
                                                 size: v8,
                                                 tag: TAG_LWO,
                                                 zeroBuffer: false,
                                                 align: ALIGN_16,
                                                 heap: HEAP_DEFAULTHEAP);
  result->next = nullptr;
  result->size = 16 - v8;
  result->prev = this->lastBlock;
  lastBlock = this->lastBlock;
  if ( lastBlock != nullptr )
    lastBlock->next = result;
  else
    this->firstBlock = result;
  this->lastBlock = result;
  result->node = nullptr;
  v10 = v8 + this->baseBlockMemory;
  ++this->numBaseBlocks;
  this->baseBlockMemory = v10;
  return result;
}


// ========================================================================
// ?FreeEmptyBaseBlocks@?$idDynamicBlockAlloc@E$0BAAAAA@$0BA@$0DM@@@QAAXXZ
// EA  : 0x8287D630
// RVA : 0x0087D630
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeEmptyBaseBlocks(
        idDynamicBlockAlloc<unsigned char,1048576,16,60> *this)
{
  idDynamicBlock<unsigned char,60> *firstBlock; // r31
  int *p_size; // r29
  idBTreeNode<idDynamicBlock<unsigned char,60>,int> *node; // r4
  int freeBlockMemory; // r7
  idDynamicBlock<unsigned char,60> *prev; // r11
  idDynamicBlock<unsigned char,60> *next; // r11
  int baseBlockMemory; // r10

  firstBlock = this->firstBlock;
  if ( this->firstBlock != nullptr )
  {
    do
    {
      p_size = &firstBlock->next->size;
      if ( firstBlock->size < 0 )
      {
        node = firstBlock->node;
        if ( node != nullptr && (p_size == nullptr || *p_size < 0) )
        {
          idBTree<idDynamicBlock<char,119>,int,4>::Remove(this: &this->freeTree, node);
          firstBlock->node = nullptr;
          freeBlockMemory = this->freeBlockMemory;
          --this->numFreeBlocks;
          this->freeBlockMemory = freeBlockMemory - abs32(firstBlock->size);
          prev = firstBlock->prev;
          if ( prev != nullptr )
            prev->next = firstBlock->next;
          else
            this->firstBlock = firstBlock->next;
          next = firstBlock->next;
          if ( next != nullptr )
            next->prev = firstBlock->prev;
          else
            this->lastBlock = firstBlock->prev;
          baseBlockMemory = this->baseBlockMemory;
          --this->numBaseBlocks;
          this->baseBlockMemory = baseBlockMemory - abs32(firstBlock->size) - 16;
          idMem::Free(this: &mem, ptr: firstBlock, align: ALIGN_16);
        }
      }
      firstBlock = (idDynamicBlock<unsigned char,60> *)p_size;
    }
    while ( p_size != nullptr );
  }
}


// ========================================================================
// ?ResizeInternal@?$idDynamicBlockAlloc@E$0BAAAAA@$0BA@$0DM@@@AAAPAV?$idDynamicBlock@E$0DM@@@PAV2@H@Z
// EA  : 0x8287D750
// RVA : 0x0087D750
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idDynamicBlock<unsigned char,60> *__fastcall idDynamicBlockAlloc<unsigned char,1048576,16,60>::ResizeInternal(
        idDynamicBlockAlloc<unsigned char,1048576,16,60> *this,
        idDynamicBlock<unsigned char,60> *block,
        int num)
{
  signed int v4; // r29
  idDynamicBlock<unsigned char,60> *v5; // r31
  signed int v6; // r10
  idDynamicBlock<unsigned char,60> *next; // r30
  unsigned int v8; // r11
  idDynamicBlock<unsigned char,60> *v9; // r11
  idDynamicBlock<unsigned char,60> *result; // r3
  signed int v12; // r11
  idDynamicBlock<unsigned char,60> *v13; // r10
  idDynamicBlock<unsigned char,60> *v14; // r4
  idDynamicBlock<unsigned char,60> *v15; // r11
  int v16; // r11
  bool v17; // cr56

  v4 = (num + 15) & 0xFFFFFFF0;
  v5 = block;
  v6 = abs32(block->size);
  if ( v4 > v6 )
  {
    next = block->next;
    if ( next != nullptr && next->size >= 0 && next->node != nullptr && (int)(abs32(next->size) + v6 + 16) >= v4 )
    {
      idDynamicBlockAlloc<unsigned char,1024,16,89>::UnlinkFreeInternal(this, block: block->next);
      v8 = abs32(next->size) + abs32(v5->size) + 16;
      if ( v5->size < 0 )
        v8 = -v8;
      v5->size = v8;
      v5->next = next->next;
      v9 = next->next;
      if ( v9 != nullptr )
        v9->prev = v5;
      else
        this->lastBlock = v5;
    }
    else
    {
      result = idDynamicBlockAlloc<unsigned char,1048576,16,60>::AllocInternal(this, num);
      v5 = result;
      if ( result == nullptr )
        return result;
      memcpy(Dst: &result[1], Src: &block[1], Size: abs32(block->size));
      idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(this, block);
    }
  }
  v12 = abs32(v5->size) + -16 - v4;
  if ( v12 >= 16 )
  {
    v13 = (idDynamicBlock<unsigned char,60> *)((char *)v5 + v4);
    v14 = v13 + 1;
    v13[1].size = v12;
    v15 = v5->next;
    v13[1].next = v15;
    v13[1].prev = v5;
    if ( v15 != nullptr )
      v15->prev = v14;
    else
      this->lastBlock = v14;
    v13[1].node = nullptr;
    v16 = -v4;
    v17 = v5->size < 0;
    v5->next = v14;
    if ( !v17 )
      v16 = v4;
    v5->size = v16;
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(this, block: v14);
  }
  return v5;
}


// ========================================================================
// ?Alloc@?$idDynamicBlockAlloc@E$0BAAAAA@$0BA@$0DM@@@QAAPAEH@Z
// EA  : 0x8287D900
// RVA : 0x0087D900
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idDynamicBlock<unsigned char,60> *__fastcall idDynamicBlockAlloc<unsigned char,1048576,16,60>::Alloc(
        idDynamicBlockAlloc<unsigned char,1048576,16,60> *this,
        signed int num)
{
  idDynamicBlock<unsigned char,60> *v5; // r4
  idDynamicBlock<unsigned char,60> *v6; // r3
  idDynamicBlock<unsigned char,60> *v7; // r30
  int usedBlockMemory; // r10
  BOOL clearAllocs; // r9

  ++this->numAllocs;
  if ( num <= 0 )
    return nullptr;
  v5 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::AllocInternal(this, num);
  if ( v5 == nullptr )
    return nullptr;
  v6 = idDynamicBlockAlloc<unsigned char,1048576,16,60>::ResizeInternal(this, block: v5, num);
  v7 = v6;
  if ( v6 == nullptr )
    return nullptr;
  usedBlockMemory = this->usedBlockMemory;
  clearAllocs = this->clearAllocs;
  ++this->numUsedBlocks;
  this->usedBlockMemory = abs32(v6->size) + usedBlockMemory;
  if ( clearAllocs )
    memset(Dst: &v6[1], Val: 0, Size: num);
  return v7 + 1;
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@UobjectState_t@idSnapShot@@$0BA@$0DJ@@@QAAXXZ
// EA  : 0x8289DCE0
// RVA : 0x0089DCE0
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idSnapShot::objectState_t,16,57>::Shutdown(
        idBlockAlloc<idSnapShot::objectState_t,16,57> *this)
{
  idBlockAlloc<idSnapShot::objectState_t,16,57>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@UobjectState_t@idSnapShot@@$0BA@$0DJ@@@AAAXXZ
// EA  : 0x8289DD60
// RVA : 0x0089DD60
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idSnapShot::objectState_t,16,57>::AllocNewBlock(
        idBlockAlloc<idSnapShot::objectState_t,16,57> *this)
{
  idBlockAlloc<idSnapShot::objectState_t,16,57>::idBlock *v2; // r3
  idBlockAlloc<idSnapShot::objectState_t,16,57>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idSnapShot::objectState_t,16,57>::element_t *free; // r7

  v2 = (idBlockAlloc<idSnapShot::objectState_t,16,57>::idBlock *)idMem::AllocWithLocation(
                                                                   this: &mem,
                                                                   location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                                   size: 0x20Cu,
                                                                   tag: TAG_NETWORKING,
                                                                   zeroBuffer: false,
                                                                   align: ALIGN_16,
                                                                   heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 4; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idSnapShot::objectState_t *)v3;
    v3[-1].data = (idSnapShot::objectState_t *)&v3[-2];
    v3->data = (idSnapShot::objectState_t *)&v3[-1];
    v3[-2].data = (idSnapShot::objectState_t *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 16;
}


// ========================================================================
// ??1?$idBlockAlloc@UobjectState_t@idSnapShot@@$0BA@$0DJ@@@QAA@XZ
// EA  : 0x8289E470
// RVA : 0x0089E470
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<idSnapShot::objectState_t,16,57>::~idBlockAlloc<idSnapShot::objectState_t,16,57>(
        idBlockAlloc<idSnapShot::objectState_t,16,57> *this)
{
  idBlockAlloc<idSnapShot::objectState_t,16,57>::Shutdown(this);
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@UobjectState_t@idSnapShot@@$0BA@$0DJ@@@QAAPAUobjectState_t@idSnapShot@@XZ
// EA  : 0x8289E478
// RVA : 0x0089E478
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idSnapShot::objectState_t,16,57>::element_t *__fastcall idBlockAlloc<idSnapShot::objectState_t,16,57>::Alloc(
        idBlockAlloc<idSnapShot::objectState_t,16,57> *this)
{
  idBlockAlloc<idSnapShot::objectState_t,16,57>::element_t *result; // r3
  unsigned __int8 *v3; // r10
  int i; // ctr

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idSnapShot::objectState_t,16,57>::AllocNewBlock(this);
  }
  result = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idSnapShot::objectState_t,16,57>::element_t *)result->data;
  result->data = nullptr;
  if ( this->clearAllocs )
  {
    v3 = &result[-1].buffer[28];
    for ( i = 8; i != 0; --i )
    {
      v3 += 4;
      *(_DWORD *)v3 = 0;
    }
  }
  HIWORD(result->data) = 0;
  *(_DWORD *)&result->buffer[4] = 0;
  *(_DWORD *)&result->buffer[8] = 0;
  *(_DWORD *)&result->buffer[12] = -1;
  result->buffer[16] = 0;
  result->buffer[17] = 0;
  *(_DWORD *)&result->buffer[20] = 0;
  *(_DWORD *)&result->buffer[24] = 0;
  result->buffer[28] = 0;
  return result;
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@VidSoundEmitterLocal@@$0BA@$0CG@@@QAAXXZ
// EA  : 0x82993F00
// RVA : 0x00993F00
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idSoundEmitterLocal,16,38>::Shutdown(idBlockAlloc<idSoundEmitterLocal,16,38> *this)
{
  idBlockAlloc<idSoundEmitterLocal,16,38>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@VidSoundChannel@@$0BA@$0CG@@@QAAXXZ
// EA  : 0x82993F80
// RVA : 0x00993F80
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idSoundChannel,16,38>::Shutdown(idBlockAlloc<idSoundChannel,16,38> *this)
{
  idBlockAlloc<idSoundChannel,16,38>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@VidSoundEmitterLocal@@$0BA@$0CG@@@AAAXXZ
// EA  : 0x829940D0
// RVA : 0x009940D0
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idSoundEmitterLocal,16,38>::AllocNewBlock(idBlockAlloc<idSoundEmitterLocal,16,38> *this)
{
  idBlockAlloc<idSoundEmitterLocal,16,38>::idBlock *v2; // r3
  idBlockAlloc<idSoundEmitterLocal,16,38>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idSoundEmitterLocal,16,38>::element_t *free; // r7

  v2 = (idBlockAlloc<idSoundEmitterLocal,16,38>::idBlock *)idMem::AllocWithLocation(
                                                             this: &mem,
                                                             location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                             size: 0xD0Cu,
                                                             tag: TAG_SOUND,
                                                             zeroBuffer: false,
                                                             align: ALIGN_16,
                                                             heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 4; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idSoundEmitterLocal *)v3;
    v3[-1].data = (idSoundEmitterLocal *)&v3[-2];
    v3->data = (idSoundEmitterLocal *)&v3[-1];
    v3[-2].data = (idSoundEmitterLocal *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 16;
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@VidSoundChannel@@$0BA@$0CG@@@AAAXXZ
// EA  : 0x82994170
// RVA : 0x00994170
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idSoundChannel,16,38>::AllocNewBlock(idBlockAlloc<idSoundChannel,16,38> *this)
{
  idBlockAlloc<idSoundChannel,16,38>::idBlock *v2; // r3
  idBlockAlloc<idSoundChannel,16,38>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idSoundChannel,16,38>::element_t *free; // r7

  v2 = (idBlockAlloc<idSoundChannel,16,38>::idBlock *)idMem::AllocWithLocation(
                                                        this: &mem,
                                                        location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                        size: 0x110Cu,
                                                        tag: TAG_SOUND,
                                                        zeroBuffer: false,
                                                        align: ALIGN_16,
                                                        heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 4; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idSoundChannel *)v3;
    v3[-1].data = (idSoundChannel *)&v3[-2];
    v3->data = (idSoundChannel *)&v3[-1];
    v3[-2].data = (idSoundChannel *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 16;
}


// ========================================================================
// ??1?$idBlockAlloc@VidSoundEmitterLocal@@$0BA@$0CG@@@QAA@XZ
// EA  : 0x82995548
// RVA : 0x00995548
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<idSoundEmitterLocal,16,38>::~idBlockAlloc<idSoundEmitterLocal,16,38>(
        idBlockAlloc<idSoundEmitterLocal,16,38> *this)
{
  idBlockAlloc<idSoundEmitterLocal,16,38>::Shutdown(this);
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@VidSoundEmitterLocal@@$0BA@$0CG@@@QAAPAVidSoundEmitterLocal@@XZ
// EA  : 0x82995558
// RVA : 0x00995558
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idSoundEmitterLocal,16,38>::element_t *__fastcall idBlockAlloc<idSoundEmitterLocal,16,38>::Alloc(
        idBlockAlloc<idSoundEmitterLocal,16,38> *this)
{
  idBlockAlloc<idSoundEmitterLocal,16,38>::element_t *free; // r29

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idSoundEmitterLocal,16,38>::AllocNewBlock(this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idSoundEmitterLocal,16,38>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
    memset(Dst: free, Val: 0, Size: 0xCCu);
  idSoundEmitterLocal::idSoundEmitterLocal(this: (idSoundEmitterLocal *)free);
  return free;
}


// ========================================================================
// __unwind$236231
// EA  : 0x829955EC
// RVA : 0x009955EC
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_236231()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ??1?$idBlockAlloc@VidSoundChannel@@$0BA@$0CG@@@QAA@XZ
// EA  : 0x82995618
// RVA : 0x00995618
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<idSoundChannel,16,38>::~idBlockAlloc<idSoundChannel,16,38>(
        idBlockAlloc<idSoundChannel,16,38> *this)
{
  idBlockAlloc<idSoundChannel,16,38>::Shutdown(this);
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@VidSoundChannel@@$0BA@$0CG@@@QAAPAVidSoundChannel@@XZ
// EA  : 0x82995628
// RVA : 0x00995628
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idSoundChannel,16,38>::element_t *__fastcall idBlockAlloc<idSoundChannel,16,38>::Alloc(
        idBlockAlloc<idSoundChannel,16,38> *this)
{
  idBlockAlloc<idSoundChannel,16,38>::element_t *free; // r29

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idSoundChannel,16,38>::AllocNewBlock(this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idSoundChannel,16,38>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
    memset(Dst: free, Val: 0, Size: 0x104u);
  idSoundChannel::idSoundChannel(this: (idSoundChannel *)free);
  return free;
}


// ========================================================================
// __unwind$236257
// EA  : 0x829956BC
// RVA : 0x009956BC
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_236257()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@VidQueuePacket@idSessionLocal@@$0EA@$0DJ@@@QAAXXZ
// EA  : 0x829C0D88
// RVA : 0x009C0D88
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::Shutdown(
        idBlockAlloc<idSessionLocal::idQueuePacket,64,57> *this)
{
  idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@VidQueuePacket@idSessionLocal@@$0EA@$0DJ@@@AAAXXZ
// EA  : 0x829C0E00
// RVA : 0x009C0E00
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::AllocNewBlock(
        idBlockAlloc<idSessionLocal::idQueuePacket,64,57> *this)
{
  idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::idBlock *v2; // r3
  idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::element_t *v3; // r11
  int v4; // ctr
  idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::element_t *free; // r7

  v2 = (idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::idBlock *)idMem::AllocWithLocation(
                                                                       this: &mem,
                                                                       location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                                       size: 0x1400Cu,
                                                                       tag: TAG_NETWORKING,
                                                                       zeroBuffer: false,
                                                                       align: ALIGN_16,
                                                                       heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v4 = 16;
  v2->next = this->blocks;
  this->blocks = v2;
  do
  {
    free = this->free;
    v3[1].data = (idSessionLocal::idQueuePacket *)v3;
    v3[-1].data = (idSessionLocal::idQueuePacket *)&v3[-2];
    v3->data = (idSessionLocal::idQueuePacket *)&v3[-1];
    v3[-2].data = (idSessionLocal::idQueuePacket *)free;
    this->free = v3 + 1;
    v3 += 4;
    --v4;
  }
  while ( v4 != 0 );
  this->total += 64;
}


// ========================================================================
// ??1?$idBlockAlloc@VidQueuePacket@idSessionLocal@@$0EA@$0DJ@@@QAA@XZ
// EA  : 0x829C3B80
// RVA : 0x009C3B80
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::~idBlockAlloc<idSessionLocal::idQueuePacket,64,57>(
        idBlockAlloc<idSessionLocal::idQueuePacket,64,57> *this)
{
  idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::Shutdown(this);
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@VidQueuePacket@idSessionLocal@@$0EA@$0DJ@@@QAAPAVidQueuePacket@idSessionLocal@@XZ
// EA  : 0x829C5358
// RVA : 0x009C5358
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::element_t *__fastcall idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::Alloc(
        idBlockAlloc<idSessionLocal::idQueuePacket,64,57> *this)
{
  idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::element_t *free; // r31
  unsigned __int8 *v4; // r11
  int i; // ctr

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::AllocNewBlock(this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idSessionLocal::idQueuePacket,64,57>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
    memset(Dst: free, Val: 0, Size: 0x4FCu);
  *(_DWORD *)&free->buffer[1248] = 0;
  *(_DWORD *)&free->buffer[1252] = 0;
  *(_DWORD *)&free->buffer[1256] = 0;
  *(_DWORD *)&free->buffer[1248] = 0;
  free->buffer[1200] = 0;
  memset(Dst: &free->buffer[1201], Val: 0, Size: 0x24u);
  v4 = &free->buffer[1236];
  for ( i = 8; i != 0; --i )
    *++v4 = 0;
  *(_DWORD *)&free->buffer[1272] = 0;
  return free;
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@UaiLatchedState_t@@$0BAA@$0DP@@@QAAXXZ
// EA  : 0x82AFBC18
// RVA : 0x00AFBC18
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<aiLatchedState_t,256,63>::Shutdown(idBlockAlloc<aiLatchedState_t,256,63> *this)
{
  idBlockAlloc<aiLatchedState_t,256,63>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@UaiLatchedEvent_t@@$0EA@$0DP@@@QAAXXZ
// EA  : 0x82AFBC98
// RVA : 0x00AFBC98
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<aiLatchedEvent_t,64,63>::Shutdown(idBlockAlloc<aiLatchedEvent_t,64,63> *this)
{
  idBlockAlloc<aiLatchedEvent_t,64,63>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@UaiLatchedState_t@@$0BAA@$0DP@@@AAAXXZ
// EA  : 0x82AFBD18
// RVA : 0x00AFBD18
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<aiLatchedState_t,256,63>::AllocNewBlock(idBlockAlloc<aiLatchedState_t,256,63> *this)
{
  idBlockAlloc<aiLatchedState_t,256,63>::idBlock *v2; // r3
  idBlockAlloc<aiLatchedState_t,256,63>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<aiLatchedState_t,256,63>::element_t *free; // r7

  v2 = (idBlockAlloc<aiLatchedState_t,256,63>::idBlock *)idMem::AllocWithLocation(
                                                           this: &mem,
                                                           location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                           size: 0x700Cu,
                                                           tag: TAG_AI_GAMESTATE,
                                                           zeroBuffer: false,
                                                           align: ALIGN_16,
                                                           heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 64; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (aiLatchedState_t *)v3;
    v3[-1].data = (aiLatchedState_t *)&v3[-2];
    v3->data = (aiLatchedState_t *)&v3[-1];
    v3[-2].data = (aiLatchedState_t *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 256;
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@UaiLatchedEvent_t@@$0EA@$0DP@@@AAAXXZ
// EA  : 0x82AFBDB8
// RVA : 0x00AFBDB8
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<aiLatchedEvent_t,64,63>::AllocNewBlock(idBlockAlloc<aiLatchedEvent_t,64,63> *this)
{
  idBlockAlloc<aiLatchedEvent_t,64,63>::idBlock *v2; // r3
  idBlockAlloc<aiLatchedEvent_t,64,63>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<aiLatchedEvent_t,64,63>::element_t *free; // r7

  v2 = (idBlockAlloc<aiLatchedEvent_t,64,63>::idBlock *)idMem::AllocWithLocation(
                                                          this: &mem,
                                                          location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                          size: 0xC0Cu,
                                                          tag: TAG_AI_GAMESTATE,
                                                          zeroBuffer: false,
                                                          align: ALIGN_16,
                                                          heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 16; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (aiLatchedEvent_t *)v3;
    v3[-1].data = (aiLatchedEvent_t *)&v3[-2];
    v3->data = (aiLatchedEvent_t *)&v3[-1];
    v3[-2].data = (aiLatchedEvent_t *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 64;
}


// ========================================================================
// ??1?$idBlockAlloc@UaiLatchedState_t@@$0BAA@$0DP@@@QAA@XZ
// EA  : 0x82AFC020
// RVA : 0x00AFC020
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<aiLatchedState_t,256,63>::~idBlockAlloc<aiLatchedState_t,256,63>(
        idBlockAlloc<aiLatchedState_t,256,63> *this)
{
  idBlockAlloc<aiLatchedState_t,256,63>::Shutdown(this);
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@UaiLatchedState_t@@$0BAA@$0DP@@@QAAPAUaiLatchedState_t@@XZ
// EA  : 0x82AFC030
// RVA : 0x00AFC030
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<aiLatchedState_t,256,63>::element_t *__fastcall idBlockAlloc<aiLatchedState_t,256,63>::Alloc(
        idBlockAlloc<aiLatchedState_t,256,63> *this)
{
  idBlockAlloc<aiLatchedState_t,256,63>::element_t *free; // r29

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<aiLatchedState_t,256,63>::AllocNewBlock(this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<aiLatchedState_t,256,63>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
    memset(Dst: free, Val: 0, Size: 0x6Cu);
  aiLatchedState_t::aiLatchedState_t(this: (aiLatchedState_t *)free);
  return free;
}


// ========================================================================
// __unwind$488247
// EA  : 0x82AFC0C4
// RVA : 0x00AFC0C4
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_488247()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ??1?$idBlockAlloc@UaiLatchedEvent_t@@$0EA@$0DP@@@QAA@XZ
// EA  : 0x82AFC0F0
// RVA : 0x00AFC0F0
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<aiLatchedEvent_t,64,63>::~idBlockAlloc<aiLatchedEvent_t,64,63>(
        idBlockAlloc<aiLatchedEvent_t,64,63> *this)
{
  idBlockAlloc<aiLatchedEvent_t,64,63>::Shutdown(this);
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@UaiLatchedEvent_t@@$0EA@$0DP@@@QAAPAUaiLatchedEvent_t@@XZ
// EA  : 0x82AFC100
// RVA : 0x00AFC100
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<aiLatchedEvent_t,64,63>::element_t *__fastcall idBlockAlloc<aiLatchedEvent_t,64,63>::Alloc(
        idBlockAlloc<aiLatchedEvent_t,64,63> *this)
{
  idBlockAlloc<aiLatchedEvent_t,64,63>::element_t *free; // r29
  unsigned __int8 *v4; // r11
  int i; // ctr

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<aiLatchedEvent_t,64,63>::AllocNewBlock(this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<aiLatchedEvent_t,64,63>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
  {
    v4 = &free[-1].buffer[44];
    for ( i = 9; i != 0; --i )
    {
      v4 += 4;
      *(_DWORD *)v4 = 0;
    }
  }
  aiLatchedEvent_t::aiLatchedEvent_t(this: (aiLatchedEvent_t *)free);
  return free;
}


// ========================================================================
// __unwind$488275
// EA  : 0x82AFC198
// RVA : 0x00AFC198
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_488275()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ??1?$idBlockAlloc@UtrmCache_t@idTraceModelCache@@$0EA@$0N@@@QAA@XZ
// EA  : 0x82B4DB70
// RVA : 0x00B4DB70
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::~idBlockAlloc<idTraceModelCache::trmCache_t,64,13>(
        idBlockAlloc<idTraceModelCache::trmCache_t,64,13> *this)
{
  idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::Shutdown(this);
}


// ========================================================================
// ?Shutdown@?$idBlockAlloc@V?$idBTreeNode@Vnode_t@idBinaryTreeTest@@H@@$0IA@$0CM@@@QAAXXZ
// EA  : 0x82EF4F60
// RVA : 0x00EF4F60
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::Shutdown(
        idBlockAlloc<idAASClipLink,128,37> *this)
{
  idBlockAlloc<idAASClipLink,128,37>::idBlock *blocks; // r4

  while ( this->blocks != nullptr )
  {
    blocks = this->blocks;
    this->blocks = this->blocks->next;
    idMem::Free(this: &mem, ptr: blocks, align: ALIGN_16);
  }
  this->blocks = nullptr;
  this->free = nullptr;
  this->active = 0;
  this->total = 0;
}


// ========================================================================
// ??1?$idBlockAlloc@V?$idBTreeNode@Vnode_t@idBinaryTreeTest@@H@@$0IA@$0CM@@@QAA@XZ
// EA  : 0x82EF52C0
// RVA : 0x00EF52C0
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

// attributes: thunk
void __fastcall idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::~idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>(
        idBlockAlloc<idAASClipLink,128,37> *this)
{
  idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::Shutdown(this);
}


// ========================================================================
// ?AllocInternal@?$idDynamicBlockAlloc@E$0BJAAA@$0BA@$05@@AAAPAV?$idDynamicBlock@E$05@@H@Z
// EA  : 0x82EF5E10
// RVA : 0x00EF5E10
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idDynamicBlock<unsigned char,6> *__fastcall idDynamicBlockAlloc<unsigned char,102400,16,6>::AllocInternal(
        idDynamicBlockAlloc<unsigned char,102400,16,6> *this,
        const int num)
{
  unsigned int v3; // r29
  idDynamicBlock<unsigned char,60> *SmallestLargerEqual; // r3
  idDynamicBlock<unsigned char,60> *v5; // r30
  idDynamicBlock<unsigned char,6> *result; // r3
  int v7; // r11
  unsigned int v8; // r30
  idDynamicBlock<unsigned char,6> *lastBlock; // r11
  int v10; // r10

  v3 = (num + 15) & 0xFFFFFFF0;
  SmallestLargerEqual = idBTree<idDynamicBlock<char,119>,int,4>::FindSmallestLargerEqual(
                          this: (idBTree<idDynamicBlock<unsigned char,60>,int,4> *)&this->freeTree,
                          key: v3);
  v5 = SmallestLargerEqual;
  if ( SmallestLargerEqual != nullptr )
  {
    idDynamicBlockAlloc<unsigned char,1024,16,89>::UnlinkFreeInternal(
      (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this,
      block: SmallestLargerEqual);
    return (idDynamicBlock<unsigned char,6> *)v5;
  }
  if ( !this->allowAllocs )
    return (idDynamicBlock<unsigned char,6> *)v5;
  v7 = v3 + 16;
  if ( (int)(v3 + 16) < 102400 )
    v7 = 102400;
  v8 = (v7 + 0xFFFF) & 0xFFFF0000;
  result = (idDynamicBlock<unsigned char,6> *)idMem::AllocWithLocation(
                                                this: &mem,
                                                location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(887) : _memTag_",
                                                size: v8,
                                                tag: TAG_TEMP,
                                                zeroBuffer: false,
                                                align: ALIGN_16,
                                                heap: HEAP_DEFAULTHEAP);
  result->next = nullptr;
  result->size = 16 - v8;
  result->prev = this->lastBlock;
  lastBlock = this->lastBlock;
  if ( lastBlock != nullptr )
    lastBlock->next = result;
  else
    this->firstBlock = result;
  this->lastBlock = result;
  result->node = nullptr;
  v10 = v8 + this->baseBlockMemory;
  ++this->numBaseBlocks;
  this->baseBlockMemory = v10;
  return result;
}


// ========================================================================
// ?ResizeInternal@?$idDynamicBlockAlloc@E$0BJAAA@$0BA@$05@@AAAPAV?$idDynamicBlock@E$05@@PAV2@H@Z
// EA  : 0x82EF5F08
// RVA : 0x00EF5F08
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idDynamicBlock<unsigned char,6> *__fastcall idDynamicBlockAlloc<unsigned char,102400,16,6>::ResizeInternal(
        idDynamicBlockAlloc<unsigned char,102400,16,6> *this,
        idDynamicBlock<unsigned char,60> *block,
        int num)
{
  signed int v4; // r29
  idDynamicBlock<unsigned char,6> *v5; // r31
  signed int v6; // r10
  idDynamicBlock<unsigned char,6> *next; // r30
  unsigned int v8; // r11
  idDynamicBlock<unsigned char,6> *v9; // r11
  idDynamicBlock<unsigned char,6> *result; // r3
  signed int v12; // r11
  idDynamicBlock<unsigned char,6> *v13; // r10
  idDynamicBlock<unsigned char,6> *v14; // r4
  idDynamicBlock<unsigned char,6> *v15; // r11
  int v16; // r11
  bool v17; // cr56

  v4 = (num + 15) & 0xFFFFFFF0;
  v5 = (idDynamicBlock<unsigned char,6> *)block;
  v6 = abs32(block->size);
  if ( v4 > v6 )
  {
    next = (idDynamicBlock<unsigned char,6> *)block->next;
    if ( next != nullptr && next->size >= 0 && next->node != nullptr && (int)(abs32(next->size) + v6 + 16) >= v4 )
    {
      idDynamicBlockAlloc<unsigned char,1024,16,89>::UnlinkFreeInternal(
        (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this,
        block: block->next);
      v8 = abs32(next->size) + abs32(v5->size) + 16;
      if ( v5->size < 0 )
        v8 = -v8;
      v5->size = v8;
      v5->next = next->next;
      v9 = next->next;
      if ( v9 != nullptr )
        v9->prev = v5;
      else
        this->lastBlock = v5;
    }
    else
    {
      result = idDynamicBlockAlloc<unsigned char,102400,16,6>::AllocInternal(this, num);
      v5 = result;
      if ( result == nullptr )
        return result;
      memcpy(Dst: &result[1], Src: &block[1], Size: abs32(block->size));
      idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
        (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this,
        block);
    }
  }
  v12 = abs32(v5->size) + -16 - v4;
  if ( v12 >= 16 )
  {
    v13 = (idDynamicBlock<unsigned char,6> *)((char *)v5 + v4);
    v14 = v13 + 1;
    v13[1].size = v12;
    v15 = v5->next;
    v13[1].next = v15;
    v13[1].prev = v5;
    if ( v15 != nullptr )
      v15->prev = v14;
    else
      this->lastBlock = v14;
    v13[1].node = nullptr;
    v16 = -v4;
    v17 = v5->size < 0;
    v5->next = v14;
    if ( !v17 )
      v16 = v4;
    v5->size = v16;
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this,
      block: (idDynamicBlock<unsigned char,60> *)v14);
  }
  return v5;
}


// ========================================================================
// ?Alloc@?$idDynamicBlockAlloc@E$0BJAAA@$0BA@$05@@QAAPAEH@Z
// EA  : 0x82EF6460
// RVA : 0x00EF6460
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idDynamicBlock<unsigned char,6> *__fastcall idDynamicBlockAlloc<unsigned char,102400,16,6>::Alloc(
        idDynamicBlockAlloc<unsigned char,102400,16,6> *this,
        signed int num)
{
  idDynamicBlock<unsigned char,60> *v5; // r4
  idDynamicBlock<unsigned char,6> *v6; // r3
  idDynamicBlock<unsigned char,6> *v7; // r30
  int usedBlockMemory; // r10
  BOOL clearAllocs; // r9

  ++this->numAllocs;
  if ( num <= 0 )
    return nullptr;
  v5 = (idDynamicBlock<unsigned char,60> *)idDynamicBlockAlloc<unsigned char,102400,16,6>::AllocInternal(this, num);
  if ( v5 == nullptr )
    return nullptr;
  v6 = idDynamicBlockAlloc<unsigned char,102400,16,6>::ResizeInternal(this, block: v5, num);
  v7 = v6;
  if ( v6 == nullptr )
    return nullptr;
  usedBlockMemory = this->usedBlockMemory;
  clearAllocs = this->clearAllocs;
  ++this->numUsedBlocks;
  this->usedBlockMemory = abs32(v6->size) + usedBlockMemory;
  if ( clearAllocs )
    memset(Dst: &v6[1], Val: 0, Size: num);
  return v7 + 1;
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@V?$idBTreeNode@V?$idDynamicBlock@E$0DM@@@H@@$0IA@$0CM@@@AAAXXZ
// EA  : 0x82EFAF88
// RVA : 0x00EFAF88
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::AllocNewBlock(
        idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44> *this)
{
  idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::idBlock *v2; // r3
  idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::element_t *free; // r7

  v2 = (idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::idBlock *)idMem::AllocWithLocation(
                                                                                            this: &mem,
                                                                                            location: "w:\\tech5\\shared\\idlib\\Bl"
                                                                                            "ockAlloc.h(207) : _memTag_",
                                                                                            size: 0x100Cu,
                                                                                            tag: TAG_IDLIB,
                                                                                            zeroBuffer: false,
                                                                                            align: ALIGN_16,
                                                                                            heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 32; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)v3;
    v3[-1].data = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)&v3[-2];
    v3->data = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)&v3[-1];
    v3[-2].data = (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 128;
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@V?$idBTreeNode@V?$idDynamicBlock@D$0HH@@@H@@$0IA@$0CM@@@QAAPAV?$idBTreeNode@V?$idDynamicBlock@D$0HH@@@H@@XZ
// EA  : 0x82EFB028
// RVA : 0x00EFB028
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::element_t *__fastcall idBlockAlloc<idBTreeNode<idDynamicBlock<char,119>,int>,128,44>::Alloc(
        idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44> *this)
{
  idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::element_t *result; // r3
  unsigned __int8 *v3; // r11
  int i; // ctr

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::AllocNewBlock(this);
  }
  result = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::element_t *)result->data;
  result->data = nullptr;
  if ( this->clearAllocs )
  {
    v3 = &result[-1].buffer[28];
    for ( i = 8; i != 0; --i )
    {
      v3 += 4;
      *(_DWORD *)v3 = 0;
    }
  }
  return result;
}


// ========================================================================
// ?LinkFreeInternal@?$idDynamicBlockAlloc@E$0EAA@$0BA@$0FJ@@@AAAXPAV?$idDynamicBlock@E$0FJ@@@@Z
// EA  : 0x82F2D5A0
// RVA : 0x00F2D5A0
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idDynamicBlockAlloc<unsigned char,1024,16,89>::LinkFreeInternal(
        idDynamicBlockAlloc<unsigned char,1048576,16,60> *this,
        idDynamicBlock<unsigned char,60> *block)
{
  int freeBlockMemory; // r10

  block->node = idBTree<idDynamicBlock<unsigned char,89>,int,4>::Add(
                  this: &this->freeTree,
                  object: block,
                  key: (idBTreeNode<idDynamicBlock<unsigned char,60>,int> *)abs32(block->size));
  freeBlockMemory = this->freeBlockMemory;
  ++this->numFreeBlocks;
  this->freeBlockMemory = abs32(block->size) + freeBlockMemory;
}


// ========================================================================
// ?AllocInternal@?$idDynamicBlockAlloc@D$0BJAAA@$0BA@$0HH@@@AAAPAV?$idDynamicBlock@D$0HH@@@H@Z
// EA  : 0x82F2D618
// RVA : 0x00F2D618
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idDynamicBlock<char,119> *__fastcall idDynamicBlockAlloc<char,102400,16,119>::AllocInternal(
        idDynamicBlockAlloc<char,102400,16,119> *this,
        const int num)
{
  unsigned int v3; // r29
  idDynamicBlock<unsigned char,60> *SmallestLargerEqual; // r3
  idDynamicBlock<unsigned char,60> *v5; // r30
  idDynamicBlock<char,119> *result; // r3
  int v7; // r11
  unsigned int v8; // r30
  idDynamicBlock<char,119> *lastBlock; // r11
  int v10; // r10

  v3 = (num + 15) & 0xFFFFFFF0;
  SmallestLargerEqual = idBTree<idDynamicBlock<char,119>,int,4>::FindSmallestLargerEqual(
                          this: (idBTree<idDynamicBlock<unsigned char,60>,int,4> *)&this->freeTree,
                          key: v3);
  v5 = SmallestLargerEqual;
  if ( SmallestLargerEqual != nullptr )
  {
    idDynamicBlockAlloc<unsigned char,1024,16,89>::UnlinkFreeInternal(
      (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this,
      block: SmallestLargerEqual);
    return (idDynamicBlock<char,119> *)v5;
  }
  if ( !this->allowAllocs )
    return (idDynamicBlock<char,119> *)v5;
  v7 = v3 + 16;
  if ( (int)(v3 + 16) < 102400 )
    v7 = 102400;
  v8 = (v7 + 0xFFFF) & 0xFFFF0000;
  result = (idDynamicBlock<char,119> *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(887) : _memTag_",
                                         size: v8,
                                         tag: TAG_LANGDICT,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
  result->next = nullptr;
  result->size = 16 - v8;
  result->prev = this->lastBlock;
  lastBlock = this->lastBlock;
  if ( lastBlock != nullptr )
    lastBlock->next = result;
  else
    this->firstBlock = result;
  this->lastBlock = result;
  result->node = nullptr;
  v10 = v8 + this->baseBlockMemory;
  ++this->numBaseBlocks;
  this->baseBlockMemory = v10;
  return result;
}


// ========================================================================
// ?FreeInternal@?$idDynamicBlockAlloc@E$0BAAAAA@$0BA@$0DM@@@AAAXPAV?$idDynamicBlock@E$0DM@@@@Z
// EA  : 0x82F2D710
// RVA : 0x00F2D710
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
        idDynamicBlockAlloc<unsigned char,1048576,16,60> *this,
        idDynamicBlock<unsigned char,60> *block)
{
  idDynamicBlock<unsigned char,60> *next; // r30
  int v5; // r11
  idDynamicBlock<unsigned char,60> *v6; // r11
  idDynamicBlock<unsigned char,60> *prev; // r30
  unsigned int v8; // r11
  idDynamicBlock<unsigned char,60> *v9; // r11

  next = block->next;
  if ( next != nullptr && next->size >= 0 && next->node != nullptr )
  {
    idDynamicBlockAlloc<unsigned char,1024,16,89>::UnlinkFreeInternal(this, block: block->next);
    v5 = abs32(next->size) + abs32(block->size) + 16;
    if ( block->size < 0 )
      v5 = -v5;
    block->size = v5;
    block->next = next->next;
    v6 = next->next;
    if ( v6 != nullptr )
      v6->prev = block;
    else
      this->lastBlock = block;
  }
  prev = block->prev;
  if ( prev != nullptr && block->size >= 0 && prev->node != nullptr )
  {
    idDynamicBlockAlloc<unsigned char,1024,16,89>::UnlinkFreeInternal(this, block: block->prev);
    v8 = abs32(block->size) + abs32(prev->size) + 16;
    if ( prev->size < 0 )
      v8 = -v8;
    prev->size = v8;
    prev->next = block->next;
    v9 = block->next;
    if ( v9 != nullptr )
      v9->prev = prev;
    else
      this->lastBlock = prev;
    idDynamicBlockAlloc<unsigned char,1024,16,89>::LinkFreeInternal(this, block: prev);
  }
  else
  {
    idDynamicBlockAlloc<unsigned char,1024,16,89>::LinkFreeInternal(this, block);
  }
}


// ========================================================================
// ?Shutdown@?$idDynamicBlockAlloc@E$0BJAAA@$0BA@$05@@QAAXXZ
// EA  : 0x82F2D868
// RVA : 0x00F2D868
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idDynamicBlockAlloc<unsigned char,102400,16,6>::Shutdown(
        idDynamicBlockAlloc<unsigned char,1048576,16,60> *this)
{
  idDynamicBlock<unsigned char,60> *i; // r30
  idDynamicBlock<unsigned char,60> *j; // r4

  for ( i = this->firstBlock; i != nullptr; i = i->next )
  {
    if ( i->node == nullptr )
      idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(this, block: i);
  }
  for ( j = this->firstBlock; this->firstBlock != nullptr; j = this->firstBlock )
  {
    this->firstBlock = j->next;
    idMem::Free(this: &mem, ptr: j, align: ALIGN_16);
  }
  idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::Shutdown(this: (idBlockAlloc<idAASClipLink,128,37> *)&this->freeTree.nodeAllocator);
  this->freeTree.root = nullptr;
  this->lastBlock = nullptr;
  this->firstBlock = nullptr;
  this->allowAllocs = true;
  this->numBaseBlocks = 0;
  this->baseBlockMemory = 0;
  this->numUsedBlocks = 0;
  this->usedBlockMemory = 0;
  this->numFreeBlocks = 0;
  this->freeBlockMemory = 0;
  this->numAllocs = 0;
  this->numResizes = 0;
  this->numFrees = 0;
}


// ========================================================================
// ?ResizeInternal@?$idDynamicBlockAlloc@D$0BJAAA@$0BA@$0HH@@@AAAPAV?$idDynamicBlock@D$0HH@@@PAV2@H@Z
// EA  : 0x82F2D948
// RVA : 0x00F2D948
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idDynamicBlock<char,119> *__fastcall idDynamicBlockAlloc<char,102400,16,119>::ResizeInternal(
        idDynamicBlockAlloc<char,102400,16,119> *this,
        idDynamicBlock<unsigned char,60> *block,
        int num)
{
  signed int v4; // r29
  idDynamicBlock<char,119> *v5; // r31
  signed int v6; // r10
  idDynamicBlock<char,119> *next; // r30
  unsigned int v8; // r11
  idDynamicBlock<char,119> *v9; // r11
  idDynamicBlock<char,119> *result; // r3
  signed int v12; // r11
  idDynamicBlock<char,119> *v13; // r10
  idDynamicBlock<char,119> *v14; // r4
  idDynamicBlock<char,119> *v15; // r11
  int v16; // r11
  bool v17; // cr56

  v4 = (num + 15) & 0xFFFFFFF0;
  v5 = (idDynamicBlock<char,119> *)block;
  v6 = abs32(block->size);
  if ( v4 > v6 )
  {
    next = (idDynamicBlock<char,119> *)block->next;
    if ( next != nullptr && next->size >= 0 && next->node != nullptr && (int)(abs32(next->size) + v6 + 16) >= v4 )
    {
      idDynamicBlockAlloc<unsigned char,1024,16,89>::UnlinkFreeInternal(
        (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this,
        block: block->next);
      v8 = abs32(next->size) + abs32(v5->size) + 16;
      if ( v5->size < 0 )
        v8 = -v8;
      v5->size = v8;
      v5->next = next->next;
      v9 = next->next;
      if ( v9 != nullptr )
        v9->prev = v5;
      else
        this->lastBlock = v5;
    }
    else
    {
      result = idDynamicBlockAlloc<char,102400,16,119>::AllocInternal(this, num);
      v5 = result;
      if ( result == nullptr )
        return result;
      memcpy(Dst: &result[1], Src: &block[1], Size: abs32(block->size));
      idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
        (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this,
        block);
    }
  }
  v12 = abs32(v5->size) + -16 - v4;
  if ( v12 >= 16 )
  {
    v13 = (idDynamicBlock<char,119> *)((char *)v5 + v4);
    v14 = v13 + 1;
    v13[1].size = v12;
    v15 = v5->next;
    v13[1].next = v15;
    v13[1].prev = v5;
    if ( v15 != nullptr )
      v15->prev = v14;
    else
      this->lastBlock = v14;
    v13[1].node = nullptr;
    v16 = -v4;
    v17 = v5->size < 0;
    v5->next = v14;
    if ( !v17 )
      v16 = v4;
    v5->size = v16;
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this,
      block: (idDynamicBlock<unsigned char,60> *)v14);
  }
  return v5;
}


// ========================================================================
// ??1?$idDynamicBlockAlloc@E$0EAA@$0BA@$0FJ@@@QAA@XZ
// EA  : 0x82F2DC90
// RVA : 0x00F2DC90
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idDynamicBlockAlloc<unsigned char,1024,16,89>::~idDynamicBlockAlloc<unsigned char,1024,16,89>(
        idDynamicBlockAlloc<unsigned char,1048576,16,60> *this)
{
  idDynamicBlockAlloc<unsigned char,102400,16,6>::Shutdown(this);
  idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::Shutdown(this: (idBlockAlloc<idAASClipLink,128,37> *)&this->freeTree.nodeAllocator);
  this->freeTree.root = nullptr;
  idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::Shutdown(this: (idBlockAlloc<idAASClipLink,128,37> *)&this->freeTree.nodeAllocator);
}


// ========================================================================
// __unwind$224549_0
// EA  : 0x82F2DCD8
// RVA : 0x00F2DCD8
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_224549_0()
{
  int v0; // r12

  idBTree<idDynamicBlock<char,119>,int,4>::~idBTree<idDynamicBlock<char,119>,int,4>(this: (idBTree<idDynamicBlock<unsigned char,60>,int,4> *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$224551
// EA  : 0x82F2DD04
// RVA : 0x00F2DD04
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void _unwind_224551()
{
  int v0; // r12

  idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>::~idBlockAlloc<idBTreeNode<idBinaryTreeTest::node_t,int>,128,44>(this: (idBlockAlloc<idAASClipLink,128,37> *)(*(_DWORD *)(v0 - 128 + 80) + 4));
}


// ========================================================================
// ?Alloc@?$idDynamicBlockAlloc@D$0BJAAA@$0BA@$0HH@@@QAAPADH@Z
// EA  : 0x82F2DD30
// RVA : 0x00F2DD30
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idDynamicBlock<char,119> *__fastcall idDynamicBlockAlloc<char,102400,16,119>::Alloc(
        idDynamicBlockAlloc<char,102400,16,119> *this,
        signed int num)
{
  idDynamicBlock<unsigned char,60> *v5; // r4
  idDynamicBlock<char,119> *v6; // r3
  idDynamicBlock<char,119> *v7; // r30
  int usedBlockMemory; // r10
  BOOL clearAllocs; // r9

  ++this->numAllocs;
  if ( num <= 0 )
    return nullptr;
  v5 = (idDynamicBlock<unsigned char,60> *)idDynamicBlockAlloc<char,102400,16,119>::AllocInternal(this, num);
  if ( v5 == nullptr )
    return nullptr;
  v6 = idDynamicBlockAlloc<char,102400,16,119>::ResizeInternal(this, block: v5, num);
  v7 = v6;
  if ( v6 == nullptr )
    return nullptr;
  usedBlockMemory = this->usedBlockMemory;
  clearAllocs = this->clearAllocs;
  ++this->numUsedBlocks;
  this->usedBlockMemory = abs32(v6->size) + usedBlockMemory;
  if ( clearAllocs )
    memset(Dst: &v6[1], Val: 0, Size: num);
  return v7 + 1;
}


// ========================================================================
// ?UnlinkFreeInternal@?$idDynamicBlockAlloc@E$0EAA@$0BA@$0FJ@@@AAAXPAV?$idDynamicBlock@E$0FJ@@@@Z
// EA  : 0x82F41400
// RVA : 0x00F41400
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idDynamicBlockAlloc<unsigned char,1024,16,89>::UnlinkFreeInternal(
        idDynamicBlockAlloc<unsigned char,1048576,16,60> *this,
        idDynamicBlock<unsigned char,60> *block)
{
  int freeBlockMemory; // r9

  idBTree<idDynamicBlock<char,119>,int,4>::Remove(
    this: &this->freeTree,
    node: (idBlockAlloc<idBTreeNode<idDynamicBlock<unsigned char,60>,int>,128,44>::element_t *)block->node);
  block->node = nullptr;
  freeBlockMemory = this->freeBlockMemory;
  --this->numFreeBlocks;
  this->freeBlockMemory = freeBlockMemory - abs32(block->size);
}


// ========================================================================
// ?AllocInternal@?$idDynamicBlockAlloc@E$0EAA@$0BA@$0FJ@@@AAAPAV?$idDynamicBlock@E$0FJ@@@H@Z
// EA  : 0x82F414D0
// RVA : 0x00F414D0
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idDynamicBlock<unsigned char,89> *__fastcall idDynamicBlockAlloc<unsigned char,1024,16,89>::AllocInternal(
        idDynamicBlockAlloc<unsigned char,1024,16,89> *this,
        const int num)
{
  unsigned int v3; // r29
  idDynamicBlock<unsigned char,60> *SmallestLargerEqual; // r3
  idDynamicBlock<unsigned char,60> *v5; // r30
  idDynamicBlock<unsigned char,89> *result; // r3
  int v7; // r11
  unsigned int v8; // r30
  idDynamicBlock<unsigned char,89> *lastBlock; // r11
  int v10; // r10

  v3 = (num + 15) & 0xFFFFFFF0;
  SmallestLargerEqual = idBTree<idDynamicBlock<char,119>,int,4>::FindSmallestLargerEqual(
                          this: (idBTree<idDynamicBlock<unsigned char,60>,int,4> *)&this->freeTree,
                          key: v3);
  v5 = SmallestLargerEqual;
  if ( SmallestLargerEqual != nullptr )
  {
    idDynamicBlockAlloc<unsigned char,1024,16,89>::UnlinkFreeInternal(
      (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this,
      block: SmallestLargerEqual);
    return (idDynamicBlock<unsigned char,89> *)v5;
  }
  if ( !this->allowAllocs )
    return (idDynamicBlock<unsigned char,89> *)v5;
  v7 = v3 + 16;
  if ( (int)(v3 + 16) < 1024 )
    v7 = 1024;
  v8 = (v7 + 0xFFFF) & 0xFFFF0000;
  result = (idDynamicBlock<unsigned char,89> *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(887) : _memTag_",
                                                 size: v8,
                                                 tag: TAG_AMQP,
                                                 zeroBuffer: false,
                                                 align: ALIGN_16,
                                                 heap: HEAP_DEFAULTHEAP);
  result->next = nullptr;
  result->size = 16 - v8;
  result->prev = this->lastBlock;
  lastBlock = this->lastBlock;
  if ( lastBlock != nullptr )
    lastBlock->next = result;
  else
    this->firstBlock = result;
  this->lastBlock = result;
  result->node = nullptr;
  v10 = v8 + this->baseBlockMemory;
  ++this->numBaseBlocks;
  this->baseBlockMemory = v10;
  return result;
}


// ========================================================================
// ?ResizeInternal@?$idDynamicBlockAlloc@E$0EAA@$0BA@$0FJ@@@AAAPAV?$idDynamicBlock@E$0FJ@@@PAV2@H@Z
// EA  : 0x82F415C0
// RVA : 0x00F415C0
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idDynamicBlock<unsigned char,89> *__fastcall idDynamicBlockAlloc<unsigned char,1024,16,89>::ResizeInternal(
        idDynamicBlockAlloc<unsigned char,1024,16,89> *this,
        idDynamicBlock<unsigned char,60> *block,
        int num)
{
  signed int v4; // r29
  idDynamicBlock<unsigned char,89> *v5; // r31
  signed int v6; // r10
  idDynamicBlock<unsigned char,89> *next; // r30
  unsigned int v8; // r11
  idDynamicBlock<unsigned char,89> *v9; // r11
  idDynamicBlock<unsigned char,89> *result; // r3
  signed int v12; // r11
  idDynamicBlock<unsigned char,89> *v13; // r10
  idDynamicBlock<unsigned char,89> *v14; // r4
  idDynamicBlock<unsigned char,89> *v15; // r11
  int v16; // r11
  bool v17; // cr56

  v4 = (num + 15) & 0xFFFFFFF0;
  v5 = (idDynamicBlock<unsigned char,89> *)block;
  v6 = abs32(block->size);
  if ( v4 > v6 )
  {
    next = (idDynamicBlock<unsigned char,89> *)block->next;
    if ( next != nullptr && next->size >= 0 && next->node != nullptr && (int)(abs32(next->size) + v6 + 16) >= v4 )
    {
      idDynamicBlockAlloc<unsigned char,1024,16,89>::UnlinkFreeInternal(
        (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this,
        block: block->next);
      v8 = abs32(next->size) + abs32(v5->size) + 16;
      if ( v5->size < 0 )
        v8 = -v8;
      v5->size = v8;
      v5->next = next->next;
      v9 = next->next;
      if ( v9 != nullptr )
        v9->prev = v5;
      else
        this->lastBlock = v5;
    }
    else
    {
      result = idDynamicBlockAlloc<unsigned char,1024,16,89>::AllocInternal(this, num);
      v5 = result;
      if ( result == nullptr )
        return result;
      memcpy(Dst: &result[1], Src: &block[1], Size: abs32(block->size));
      idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
        (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this,
        block);
    }
  }
  v12 = abs32(v5->size) + -16 - v4;
  if ( v12 >= 16 )
  {
    v13 = (idDynamicBlock<unsigned char,89> *)((char *)v5 + v4);
    v14 = v13 + 1;
    v13[1].size = v12;
    v15 = v5->next;
    v13[1].next = v15;
    v13[1].prev = v5;
    if ( v15 != nullptr )
      v15->prev = v14;
    else
      this->lastBlock = v14;
    v13[1].node = nullptr;
    v16 = -v4;
    v17 = v5->size < 0;
    v5->next = v14;
    if ( !v17 )
      v16 = v4;
    v5->size = v16;
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)this,
      block: (idDynamicBlock<unsigned char,60> *)v14);
  }
  return v5;
}


// ========================================================================
// ?Alloc@?$idDynamicBlockAlloc@E$0EAA@$0BA@$0FJ@@@QAAPAEH@Z
// EA  : 0x82F417C8
// RVA : 0x00F417C8
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idDynamicBlock<unsigned char,89> *__fastcall idDynamicBlockAlloc<unsigned char,1024,16,89>::Alloc(
        idDynamicBlockAlloc<unsigned char,1024,16,89> *this,
        signed int num)
{
  idDynamicBlock<unsigned char,60> *v5; // r4
  idDynamicBlock<unsigned char,89> *v6; // r3
  idDynamicBlock<unsigned char,89> *v7; // r30
  int usedBlockMemory; // r10
  BOOL clearAllocs; // r9

  ++this->numAllocs;
  if ( num <= 0 )
    return nullptr;
  v5 = (idDynamicBlock<unsigned char,60> *)idDynamicBlockAlloc<unsigned char,1024,16,89>::AllocInternal(this, num);
  if ( v5 == nullptr )
    return nullptr;
  v6 = idDynamicBlockAlloc<unsigned char,1024,16,89>::ResizeInternal(this, block: v5, num);
  v7 = v6;
  if ( v6 == nullptr )
    return nullptr;
  usedBlockMemory = this->usedBlockMemory;
  clearAllocs = this->clearAllocs;
  ++this->numUsedBlocks;
  this->usedBlockMemory = abs32(v6->size) + usedBlockMemory;
  if ( clearAllocs )
    memset(Dst: &v6[1], Val: 0, Size: num);
  return v7 + 1;
}


// ========================================================================
// ?AllocNewBlock@?$idBlockAlloc@VidTypeInfoNode@@$0CA@$0HC@@@AAAXXZ
// EA  : 0x82FA1880
// RVA : 0x00FA1880
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

void __fastcall idBlockAlloc<idTypeInfoNode,32,114>::AllocNewBlock(idBlockAlloc<idTypeInfoNode,32,114> *this)
{
  idBlockAlloc<idTypeInfoNode,32,114>::idBlock *v2; // r3
  idBlockAlloc<idTypeInfoNode,32,114>::element_t *v3; // r11
  int i; // ctr
  idBlockAlloc<idTypeInfoNode,32,114>::element_t *free; // r7

  v2 = (idBlockAlloc<idTypeInfoNode,32,114>::idBlock *)idMem::AllocWithLocation(
                                                         this: &mem,
                                                         location: "w:\\tech5\\shared\\idlib\\BlockAlloc.h(207) : _memTag_",
                                                         size: 0x160Cu,
                                                         tag: TAG_TYPEINFO,
                                                         zeroBuffer: false,
                                                         align: ALIGN_16,
                                                         heap: HEAP_DEFAULTHEAP);
  v3 = &v2->elements[2];
  v2->next = this->blocks;
  this->blocks = v2;
  for ( i = 8; i != 0; --i )
  {
    free = this->free;
    v3[1].data = (idTypeInfoNode *)v3;
    v3[-1].data = (idTypeInfoNode *)&v3[-2];
    v3->data = (idTypeInfoNode *)&v3[-1];
    v3[-2].data = (idTypeInfoNode *)free;
    this->free = v3 + 1;
    v3 += 4;
  }
  this->total += 32;
}


// ========================================================================
// ?Alloc@?$idBlockAlloc@VidTypeInfoNode@@$0CA@$0HC@@@QAAPAVidTypeInfoNode@@XZ
// EA  : 0x82FA2018
// RVA : 0x00FA2018
// PDB : w:\tech5\shared\idlib\blockalloc.h
// ========================================================================

idBlockAlloc<idTypeInfoNode,32,114>::element_t *__fastcall idBlockAlloc<idTypeInfoNode,32,114>::Alloc(
        idBlockAlloc<idTypeInfoNode,32,114> *this)
{
  idBlockAlloc<idTypeInfoNode,32,114>::element_t *free; // r31

  if ( this->free == nullptr )
  {
    if ( !this->allowAllocs )
      return nullptr;
    idBlockAlloc<idTypeInfoNode,32,114>::AllocNewBlock(this);
  }
  free = this->free;
  ++this->active;
  this->free = (idBlockAlloc<idTypeInfoNode,32,114>::element_t *)free->data;
  free->data = nullptr;
  if ( this->clearAllocs )
    memset(Dst: free, Val: 0, Size: sizeof(idBlockAlloc<idTypeInfoNode,32,114>::element_t));
  free->data = nullptr;
  *(_DWORD *)&free->buffer[8] = 20;
  *(_DWORD *)&free->buffer[4] = &free->buffer[12];
  free->buffer[12] = 0;
  *(_DWORD *)&free->buffer[36] = &free->buffer[44];
  *(_DWORD *)&free->buffer[40] = 20;
  *(_DWORD *)&free->buffer[32] = 0;
  free->buffer[44] = 0;
  *(_DWORD *)&free->buffer[68] = &free->buffer[76];
  *(_DWORD *)&free->buffer[72] = 20;
  *(_DWORD *)&free->buffer[64] = 0;
  free->buffer[76] = 0;
  *(_DWORD *)&free->buffer[100] = &free->buffer[108];
  *(_DWORD *)&free->buffer[104] = 20;
  *(_DWORD *)&free->buffer[96] = 0;
  free->buffer[108] = 0;
  *(_DWORD *)&free->buffer[136] = 20;
  *(_DWORD *)&free->buffer[132] = &free->buffer[140];
  *(_DWORD *)&free->buffer[128] = 0;
  free->buffer[140] = 0;
  return free;
}

