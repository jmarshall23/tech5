
// ========================================================================
// ??1idResourceList@@UAA@XZ
// EA  : 0x825AE6D8
// RVA : 0x005AE6D8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void __fastcall idResourceList::~idResourceList(idResourceList *this)
{
  this->__vftable = (idResourceList_vtbl *)&idResourceList::`vftable';
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidAAS2DebugAreaModel@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x825AE940
// RVA : 0x005AE940
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idAAS2DebugAreaModel *__fastcall idTypedResourceList<idAAS2DebugAreaModel>::Alloc(
        idTypedResourceList<idAAS2DebugAreaModel> *this,
        const char *name)
{
  idAAS2DebugAreaModel *v3; // r3
  idAAS2DebugAreaModel *v4; // r30

  v3 = (idAAS2DebugAreaModel *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x48u,
                                 tag: TAG_RESOURCE,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idAAS2DebugAreaModel::idAAS2DebugAreaModel(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$219851
// EA  : 0x825AE9B0
// RVA : 0x005AE9B0
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_219851()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?AllocSize@?$idTypedResourceList@VidAAS2File@@@@UBAHXZ
// EA  : 0x825B1398
// RVA : 0x005B1398
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

int __fastcall idTypedResourceList<idAAS2File>::AllocSize(idTypedResourceList<idAAS2File> *this)
{
  return 736;
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidAAS2File@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x825B5188
// RVA : 0x005B5188
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idAAS2File *__fastcall idTypedResourceList<idAAS2File>::Alloc(idTypedResourceList<idAAS2File> *this, const char *name)
{
  idAAS2File *v3; // r3
  idAAS2File *v4; // r30

  v3 = (idAAS2File *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x2E0u,
                       tag: TAG_RESOURCE,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idAAS2File::idAAS2File(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$239821
// EA  : 0x825B51F8
// RVA : 0x005B51F8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_239821()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?AllocSize@?$idTypedResourceList@VidCollisionGridLocal@@@@UBAHXZ
// EA  : 0x825BDB40
// RVA : 0x005BDB40
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

int __fastcall idTypedResourceList<idCollisionGridLocal>::AllocSize(idTypedResourceList<idCollisionGridLocal> *this)
{
  return 176;
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidCollisionGridLocal@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x825BEE70
// RVA : 0x005BEE70
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idCollisionGridLocal *__fastcall idTypedResourceList<idCollisionGridLocal>::Alloc(
        idTypedResourceList<idCollisionGridLocal> *this,
        const char *name)
{
  idCollisionGridLocal *v3; // r3
  idCollisionGridLocal *v4; // r30

  v3 = (idCollisionGridLocal *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xB0u,
                                 tag: TAG_RESOURCE,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idCollisionGridLocal::idCollisionGridLocal(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$228802
// EA  : 0x825BEEE0
// RVA : 0x005BEEE0
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_228802()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidCollisionModelLocal@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x825C0E88
// RVA : 0x005C0E88
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idCollisionModelLocal *__fastcall idTypedResourceList<idCollisionModelLocal>::Alloc(
        idTypedResourceList<idCollisionModelLocal> *this,
        const char *name)
{
  idCollisionModelLocal *v3; // r3
  idCollisionModelLocal *v4; // r30

  v3 = (idCollisionModelLocal *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x74u,
                                  tag: TAG_RESOURCE,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idCollisionModelLocal::idCollisionModelLocal(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$226918
// EA  : 0x825C0EF8
// RVA : 0x005C0EF8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_226918()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?AllocSize@?$idTypedResourceList@VidVoiceTrack@@@@UBAHXZ
// EA  : 0x826373A8
// RVA : 0x006373A8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

int __fastcall idTypedResourceList<idVoiceTrack>::AllocSize(idTypedResourceList<idVoiceTrack> *this)
{
  return 292;
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidVoiceTrack@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82638B18
// RVA : 0x00638B18
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idVoiceTrack *__fastcall idTypedResourceList<idVoiceTrack>::Alloc(
        idTypedResourceList<idVoiceTrack> *this,
        const char *name)
{
  idVoiceTrack *v3; // r3
  idVoiceTrack *v4; // r30

  v3 = (idVoiceTrack *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x124u,
                         tag: TAG_RESOURCE,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idVoiceTrack::idVoiceTrack(this: v3, defaultVisemeSetName: idVoiceTrack::DEFAULT_VISEME_SET_NAME);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idResource, _name: name);
  return v4;
}


// ========================================================================
// __unwind$226953
// EA  : 0x82638B90
// RVA : 0x00638B90
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_226953()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidFileResource@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82677FB8
// RVA : 0x00677FB8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idResource *__fastcall idTypedResourceList<idFileResource>::Alloc(
        idTypedResourceList<idFileResource> *this,
        const char *name)
{
  idResource *v3; // r3
  idResource *v4; // r30

  v3 = (idResource *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x30u,
                       tag: TAG_RESOURCE,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idResource::idResource(this: v3);
    v4[1].trackedMemory = 0;
    v4[1].__vftable = (idResource_vtbl *)-1;
    v4->__vftable = (idResource_vtbl *)&idFileResource::`vftable';
    v4[1].name.str = nullptr;
  }
  else
  {
    v4 = nullptr;
  }
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$237430
// EA  : 0x82678048
// RVA : 0x00678048
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_237430()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidFont@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x8276CED8
// RVA : 0x0076CED8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idResource *__fastcall idTypedResourceList<idFont>::Alloc(idTypedResourceList<idFont> *this, const char *name)
{
  idResource *v3; // r3
  idResource *v4; // r30

  v3 = (idResource *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x30u,
                       tag: TAG_RESOURCE,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idResource::idResource(this: v3);
    v4[1].__vftable = nullptr;
    v4->__vftable = (idResource_vtbl *)&idFont::`vftable';
    v4[1].trackedMemory = 0;
    v4[1].name.str = (const char *)-1;
  }
  else
  {
    v4 = nullptr;
  }
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$220676
// EA  : 0x8276CF68
// RVA : 0x0076CF68
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_220676()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?AllocSize@?$idTypedResourceList@VidRenderModelCuttableResource@@@@UBAHXZ
// EA  : 0x827C78E0
// RVA : 0x007C78E0
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

int __fastcall idTypedResourceList<idRenderModelCuttableResource>::AllocSize(
        idTypedResourceList<idRenderModelCuttableResource> *this)
{
  return 192;
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidRenderModelCuttableResource@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x827C8610
// RVA : 0x007C8610
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idRenderModelCuttableResource *__fastcall idTypedResourceList<idRenderModelCuttableResource>::Alloc(
        idTypedResourceList<idRenderModelCuttableResource> *this,
        const char *name)
{
  idRenderModelCuttableResource *v3; // r3
  idRenderModelCuttableResource *v4; // r30

  v3 = (idRenderModelCuttableResource *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                          size: 0xC0u,
                                          tag: TAG_RESOURCE,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idRenderModelCuttableResource::idRenderModelCuttableResource(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$221860
// EA  : 0x827C8680
// RVA : 0x007C8680
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_221860()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidDetailModel@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x827CBB08
// RVA : 0x007CBB08
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idDetailModel *__fastcall idTypedResourceList<idDetailModel>::Alloc(
        idTypedResourceList<idDetailModel> *this,
        const char *name)
{
  idDetailModel *v3; // r3
  idDetailModel *v4; // r30

  v3 = (idDetailModel *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x50u,
                          tag: TAG_RESOURCE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDetailModel::idDetailModel(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$235550
// EA  : 0x827CBB78
// RVA : 0x007CBB78
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_235550()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?AllocSize@?$idTypedResourceList@VidDetailModelData@@@@UBAHXZ
// EA  : 0x827CBC80
// RVA : 0x007CBC80
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

int __fastcall idTypedResourceList<idDetailModelData>::AllocSize(idTypedResourceList<idDetailModelData> *this)
{
  return 44;
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidDetailModelData@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x827CC640
// RVA : 0x007CC640
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idDetailModelData *__fastcall idTypedResourceList<idDetailModelData>::Alloc(
        idTypedResourceList<idDetailModelData> *this,
        const char *name)
{
  idDetailModelData *v3; // r3
  idDetailModelData *v4; // r30

  v3 = (idDetailModelData *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x2Cu,
                              tag: TAG_RESOURCE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDetailModelData::idDetailModelData(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$231437
// EA  : 0x827CC6B0
// RVA : 0x007CC6B0
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_231437()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidDiscreteAnimationModelData@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x827D0C60
// RVA : 0x007D0C60
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idDiscreteAnimationModelData *__fastcall idTypedResourceList<idDiscreteAnimationModelData>::Alloc(
        idTypedResourceList<idDiscreteAnimationModelData> *this,
        const char *name)
{
  idDiscreteAnimationModelData *v3; // r3
  idDiscreteAnimationModelData *v4; // r30

  v3 = (idDiscreteAnimationModelData *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                         size: 0x8Cu,
                                         tag: TAG_RESOURCE,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idDiscreteAnimationModelData::idDiscreteAnimationModelData(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idResource, _name: name);
  return v4;
}


// ========================================================================
// __unwind$227571
// EA  : 0x827D0CD0
// RVA : 0x007D0CD0
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_227571()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidFoliageModel@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x827D71A0
// RVA : 0x007D71A0
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idFoliageModel *__fastcall idTypedResourceList<idFoliageModel>::Alloc(
        idTypedResourceList<idFoliageModel> *this,
        const char *name)
{
  idFoliageModel *v3; // r3
  idFoliageModel *v4; // r30

  v3 = (idFoliageModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x50u,
                           tag: TAG_RESOURCE,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idFoliageModel::idFoliageModel(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$233354
// EA  : 0x827D7210
// RVA : 0x007D7210
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_233354()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidMorphVertices@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x827DC418
// RVA : 0x007DC418
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idMorphVertices *__fastcall idTypedResourceList<idMorphVertices>::Alloc(
        idTypedResourceList<idMorphVertices> *this,
        const char *name)
{
  idMorphVertices *v3; // r3
  idMorphVertices *v4; // r30

  v3 = (idMorphVertices *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x3Cu,
                            tag: TAG_RESOURCE,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idMorphVertices::idMorphVertices(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$235330
// EA  : 0x827DC488
// RVA : 0x007DC488
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_235330()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidStaticParticleModelData@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x827EC660
// RVA : 0x007EC660
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idStaticParticleModelData *__fastcall idTypedResourceList<idStaticParticleModelData>::Alloc(
        idTypedResourceList<idStaticParticleModelData> *this,
        const char *name)
{
  idStaticParticleModelData *v3; // r3
  idStaticParticleModelData *v4; // r30

  v3 = (idStaticParticleModelData *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x30u,
                                      tag: TAG_RESOURCE,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idStaticParticleModelData::idStaticParticleModelData(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idResource, _name: name);
  return v4;
}


// ========================================================================
// __unwind$231292
// EA  : 0x827EC6D0
// RVA : 0x007EC6D0
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_231292()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?AllocSize@?$idTypedResourceList@VidJointResource@@@@UBAHXZ
// EA  : 0x828021A8
// RVA : 0x008021A8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

int __fastcall idTypedResourceList<idJointResource>::AllocSize(idTypedResourceList<idJointResource> *this)
{
  return 36;
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidJointResource@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x828021C8
// RVA : 0x008021C8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idResource *__fastcall idTypedResourceList<idJointResource>::Alloc(
        idTypedResourceList<idJointResource> *this,
        const char *name)
{
  idResource *v3; // r3
  idResource *v4; // r30

  v3 = (idResource *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x24u,
                       tag: TAG_RESOURCE,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idResource::idResource(this: v3);
    v4->__vftable = (idResource_vtbl *)&idJointResource::`vftable';
  }
  else
  {
    v4 = nullptr;
  }
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$228327
// EA  : 0x82802244
// RVA : 0x00802244
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_228327()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidJointConversion@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82807E88
// RVA : 0x00807E88
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idJointConversion *__fastcall idTypedResourceList<idJointConversion>::Alloc(
        idTypedResourceList<idJointConversion> *this,
        const char *name)
{
  idJointConversion *v3; // r3
  idJointConversion *v4; // r30

  v3 = (idJointConversion *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x50u,
                              tag: TAG_RESOURCE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idJointConversion::idJointConversion(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$237483
// EA  : 0x82807EF8
// RVA : 0x00807EF8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_237483()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidMD6Anim@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82828AC8
// RVA : 0x00828AC8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idMD6Anim *__fastcall idTypedResourceList<idMD6Anim>::Alloc(idTypedResourceList<idMD6Anim> *this, const char *name)
{
  idMD6Anim *v3; // r3
  idMD6Anim *v4; // r30

  v3 = (idMD6Anim *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x84u,
                      tag: TAG_RESOURCE,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idMD6Anim::idMD6Anim(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idResource, _name: name);
  return v4;
}


// ========================================================================
// __unwind$232957
// EA  : 0x82828B38
// RVA : 0x00828B38
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_232957()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?AllocSize@?$idTypedResourceList@VidMD6Model@@@@UBAHXZ
// EA  : 0x82845230
// RVA : 0x00845230
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

int __fastcall idTypedResourceList<idMD6Model>::AllocSize(idTypedResourceList<idMD6Model> *this)
{
  return 240;
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidMD6Model@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82846238
// RVA : 0x00846238
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idMD6Model *__fastcall idTypedResourceList<idMD6Model>::Alloc(idTypedResourceList<idMD6Model> *this, const char *name)
{
  idMD6Model *v3; // r3
  idMD6Model *v4; // r30

  v3 = (idMD6Model *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0xF0u,
                       tag: TAG_RESOURCE,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idMD6Model::idMD6Model(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idResource, _name: name);
  return v4;
}


// ========================================================================
// __unwind$229263
// EA  : 0x828462A8
// RVA : 0x008462A8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_229263()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?AllocSize@?$idTypedResourceList@VidMD6Skel@@@@UBAHXZ
// EA  : 0x82853D68
// RVA : 0x00853D68
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

int __fastcall idTypedResourceList<idMD6Skel>::AllocSize(idTypedResourceList<idMD6Skel> *this)
{
  return 52;
}


// ========================================================================
// ?AllocSize@?$idTypedResourceList@VidMD6SkeletonConfig@@@@UBAHXZ
// EA  : 0x82853D70
// RVA : 0x00853D70
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

int __fastcall idTypedResourceList<idMD6SkeletonConfig>::AllocSize(idTypedResourceList<idMD6SkeletonConfig> *this)
{
  return 56;
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidMD6Skel@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82853DD8
// RVA : 0x00853DD8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idMD6Skel *__fastcall idTypedResourceList<idMD6Skel>::Alloc(idTypedResourceList<idMD6Skel> *this, const char *name)
{
  idMD6Skel *v3; // r3
  idMD6Skel *v4; // r30

  v3 = (idMD6Skel *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x34u,
                      tag: TAG_RESOURCE,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idMD6Skel::idMD6Skel(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idResource, _name: name);
  return v4;
}


// ========================================================================
// __unwind$226251_0
// EA  : 0x82853E48
// RVA : 0x00853E48
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_226251_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidMD6SkeletonConfig@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82854D38
// RVA : 0x00854D38
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idMD6SkeletonConfig *__fastcall idTypedResourceList<idMD6SkeletonConfig>::Alloc(
        idTypedResourceList<idMD6SkeletonConfig> *this,
        const char *name)
{
  idMD6SkeletonConfig *v3; // r3
  idMD6SkeletonConfig *v4; // r30

  v3 = (idMD6SkeletonConfig *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x38u,
                                tag: TAG_RESOURCE,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idMD6SkeletonConfig::idMD6SkeletonConfig(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$228146
// EA  : 0x82854DA8
// RVA : 0x00854DA8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_228146()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidStaticModel@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82869D90
// RVA : 0x00869D90
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idStaticModel *__fastcall idTypedResourceList<idStaticModel>::Alloc(
        idTypedResourceList<idStaticModel> *this,
        const char *name)
{
  idStaticModel *v3; // r3
  idStaticModel *v4; // r30

  v3 = (idStaticModel *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x194u,
                          tag: TAG_RESOURCE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idStaticModel::idStaticModel(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$235671
// EA  : 0x82869E00
// RVA : 0x00869E00
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_235671()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?AllocSize@?$idTypedResourceList@VidIESfile@@@@UBAHXZ
// EA  : 0x828C1140
// RVA : 0x008C1140
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

int __fastcall idTypedResourceList<idIESfile>::AllocSize(idTypedResourceList<idIESfile> *this)
{
  return 492;
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidIESfile@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x828C1688
// RVA : 0x008C1688
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idIESfile *__fastcall idTypedResourceList<idIESfile>::Alloc(idTypedResourceList<idIESfile> *this, const char *name)
{
  idIESfile *v3; // r3
  idIESfile *v4; // r30

  v3 = (idIESfile *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x1ECu,
                      tag: TAG_RESOURCE,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idIESfile::idIESfile(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idResource, _name: name);
  return v4;
}


// ========================================================================
// __unwind$221415_1
// EA  : 0x828C16F8
// RVA : 0x008C16F8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_221415_1()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?AllocSize@?$idTypedResourceList@VidImage@@@@UBAHXZ
// EA  : 0x828C3898
// RVA : 0x008C3898
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

int __fastcall idTypedResourceList<idImage>::AllocSize(idTypedResourceList<idImage> *this)
{
  return 324;
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidImage@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x828C38A8
// RVA : 0x008C38A8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idImage *__fastcall idTypedResourceList<idImage>::Alloc(idTypedResourceList<idImage> *this, const char *name)
{
  idImage *v3; // r3
  idImage *v4; // r30

  v3 = (idImage *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                    size: 0x144u,
                    tag: TAG_RESOURCE,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idImage::idImage(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: &v4->idResource, _name: name);
  return v4;
}


// ========================================================================
// __unwind$231259
// EA  : 0x828C3918
// RVA : 0x008C3918
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_231259()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?AllocSize@?$idDeclInfoTemplate@VidDeclTrackingParms@@@@UBAHXZ
// EA  : 0x828C4448
// RVA : 0x008C4448
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

int __fastcall idDeclInfoTemplate<idDeclTrackingParms>::AllocSize(idDeclInfoTemplate<idDeclGameTime> *this)
{
  return 80;
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidAtlasResource@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x828C4458
// RVA : 0x008C4458
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idResource *__fastcall idTypedResourceList<idAtlasResource>::Alloc(
        idTypedResourceList<idAtlasResource> *this,
        const char *name)
{
  idResource *v3; // r3
  idResource *v4; // r30

  v3 = (idResource *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x50u,
                       tag: TAG_RESOURCE,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idResource::idResource(this: v3);
    v4[1].staleCount = 0;
    v4->__vftable = (idResource_vtbl *)&idAtlasResource::`vftable';
    *((_DWORD *)&v4[1] + 8) = 0;
    v4[1].resourceError = nullptr;
    v4[1].networkID = 0;
  }
  else
  {
    v4 = nullptr;
  }
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$222055_0
// EA  : 0x828C44E8
// RVA : 0x008C44E8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_222055_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidInGameVideoFile@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x828D1DC8
// RVA : 0x008D1DC8
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idResource *__fastcall idTypedResourceList<idInGameVideoFile>::Alloc(
        idTypedResourceList<idInGameVideoFile> *this,
        const char *name)
{
  idResource *v3; // r3
  idResource *v4; // r30

  v3 = (idResource *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x28u,
                       tag: TAG_RESOURCE,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idResource::idResource(this: v3);
    v4[1].__vftable = nullptr;
    v4->__vftable = (idResource_vtbl *)&idInGameVideoFile::`vftable';
  }
  else
  {
    v4 = nullptr;
  }
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$229722
// EA  : 0x828D1E4C
// RVA : 0x008D1E4C
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_229722()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidSoundSample@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82990380
// RVA : 0x00990380
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idResource *__fastcall idTypedResourceList<idSoundSample>::Alloc(
        idTypedResourceList<idSoundSample> *this,
        const char *name)
{
  idSoundSample_XAudio2 *v3; // r3
  idResource *v4; // r30

  v3 = (idSoundSample_XAudio2 *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x98u,
                                  tag: TAG_RESOURCE,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  v4 = v3;
  if ( v3 != nullptr )
  {
    idSoundSample_XAudio2::idSoundSample_XAudio2(this: v3);
    v4->__vftable = (idResource_vtbl *)&idSoundSample::`vftable';
  }
  else
  {
    v4 = nullptr;
  }
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$225266
// EA  : 0x829903FC
// RVA : 0x009903FC
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_225266()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?AllocSize@?$idTypedResourceList@VidCoverPoints@@@@UBAHXZ
// EA  : 0x82DE6860
// RVA : 0x00DE6860
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

int __fastcall idTypedResourceList<idCoverPoints>::AllocSize(idTypedResourceList<idCoverPoints> *this)
{
  return 108;
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidCoverPoints@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82DE6BA0
// RVA : 0x00DE6BA0
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idCoverPoints *__fastcall idTypedResourceList<idCoverPoints>::Alloc(
        idTypedResourceList<idCoverPoints> *this,
        const char *name)
{
  idCoverPoints *v3; // r3
  idCoverPoints *v4; // r30

  v3 = (idCoverPoints *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x6Cu,
                          tag: TAG_RESOURCE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idCoverPoints::idCoverPoints(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$489123
// EA  : 0x82DE6C10
// RVA : 0x00DE6C10
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_489123()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}


// ========================================================================
// ?Alloc@?$idTypedResourceList@VidNavigationMesh@@@@UBAPAVidResource@@PBD@Z
// EA  : 0x82DEEA90
// RVA : 0x00DEEA90
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

idNavigationMesh *__fastcall idTypedResourceList<idNavigationMesh>::Alloc(
        idTypedResourceList<idNavigationMesh> *this,
        const char *name)
{
  idNavigationMesh *v3; // r3
  idNavigationMesh *v4; // r30

  v3 = (idNavigationMesh *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x50u,
                             tag: TAG_RESOURCE,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idNavigationMesh::idNavigationMesh(this: v3);
  else
    v4 = nullptr;
  idResource::SetName(this: v4, _name: name);
  return v4;
}


// ========================================================================
// __unwind$489983
// EA  : 0x82DEEB00
// RVA : 0x00DEEB00
// PDB : w:\tech5\engine\framework\resourcelist.h
// ========================================================================

void _unwind_489983()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RESOURCE);
}

