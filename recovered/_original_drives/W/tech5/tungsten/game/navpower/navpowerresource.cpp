
// ========================================================================
// ?CreateSpace@idNavigationSpaceImpl@@QAAXXZ
// EA  : 0x82DEE2B0
// RVA : 0x00DEE2B0
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationSpaceImpl::CreateSpace(idNavigationSpaceImpl *this)
{
  const bfx::SpaceHandle *Space; // r3
  bfx::SpaceHandle v3[2]; // [sp+50h] [-20h] BYREF

  if ( bfx::VolumeHandle::IsValid(this: &this->spaceHandle) )
    idLib::Warning(fmt: "idNavigationSpace::CreateSpace called when a space is already allocated");
  Space = bfx::CreateSpace(result: v3);
  bfx::ObstacleHandle::operator=(this: &this->spaceHandle, rhs: Space);
  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: v3);
}


// ========================================================================
// __unwind$489091
// EA  : 0x82DEE31C
// RVA : 0x00DEE31C
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_489091()
{
  int v0; // r12

  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: (bfx::SpaceHandle *)(v0 - 112 + 80));
}


// ========================================================================
// ?CreateSpace@idNavigationSpace@@QAAXXZ
// EA  : 0x82DEE348
// RVA : 0x00DEE348
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationSpace::CreateSpace(idNavigationSpace *this)
{
  idNavigationSpaceImpl *impl; // r3

  impl = this->impl;
  if ( impl != nullptr )
    idNavigationSpaceImpl::CreateSpace(this: impl);
}


// ========================================================================
// ?SetActiveSpace@idNavigationSpace@@QBAXXZ
// EA  : 0x82DEE360
// RVA : 0x00DEE360
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationSpace::SetActiveSpace(idNavigationSpace *this)
{
  if ( this->impl != nullptr )
    bfx::ObstacleHandle::operator=(this: &activeSpaceHandle, rhs: &this->impl->spaceHandle);
}


// ========================================================================
// ?CopyFrom@idNavigationMeshImpl@@QAAXPBV1@@Z
// EA  : 0x82DEE380
// RVA : 0x00DEE380
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationMeshImpl::CopyFrom(idNavigationMeshImpl *this, const idNavigationMeshImpl *src)
{
  unsigned int ResourceSize; // r29
  char *v5; // r3

  ResourceSize = bfx::GetResourceSize(pBinaryImage: src->navigationBinaryBlob);
  v5 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\tungsten\\game\\navpower\\NavPowerResource.cpp(355) : TAG_NAVPOWER",
                 size: ResourceSize,
                 tag: TAG_NAVPOWER,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  this->navigationBinaryBlob = v5;
  memcpy(Dst: v5, Src: src->navigationBinaryBlob, Size: ResourceSize);
}


// ========================================================================
// ?RemoveFromNavPower@idNavigationMeshImpl@@QAAXXZ
// EA  : 0x82DEE3E0
// RVA : 0x00DEE3E0
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationMeshImpl::RemoveFromNavPower(idNavigationMeshImpl *this)
{
  bfx::SpaceHandle *p_navigationSpaceHandle; // r30
  BOOL navigationAdded; // r10

  if ( this->navigationBinaryBlob != nullptr )
  {
    p_navigationSpaceHandle = &this->navigationSpaceHandle;
    bfx::RemoveResource(spaceHandle: &this->navigationSpaceHandle, pBinaryImage: this->navigationBinaryBlob);
    idMem::Free(this: &mem, ptr: this->navigationBinaryBlob, align: ALIGN_16);
    navigationAdded = this->navigationAdded;
    this->navigationBinaryBlob = nullptr;
    if ( navigationAdded )
      bfx::VolumeHandle::Release(this: p_navigationSpaceHandle);
    this->navigationAdded = false;
  }
}


// ========================================================================
// ??0idNavigationMeshImpl@@QAA@XZ
// EA  : 0x82DEE448
// RVA : 0x00DEE448
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

idNavigationMeshImpl *__fastcall idNavigationMeshImpl::idNavigationMeshImpl(idNavigationMeshImpl *this)
{
  this->navigationBinaryBlob = nullptr;
  bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: &this->navigationSpaceHandle);
  this->navigationAdded = false;
  return this;
}


// ========================================================================
// ?RemoveFromNavPower@idNavigationMesh@@QAAXXZ
// EA  : 0x82DEE490
// RVA : 0x00DEE490
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationMesh::RemoveFromNavPower(idNavigationMesh *this)
{
  idNavigationMeshImpl *impl; // r3

  impl = this->impl;
  if ( impl != nullptr )
    idNavigationMeshImpl::RemoveFromNavPower(this: impl);
}


// ========================================================================
// ?UpdateTransform@idNavigationSpaceImpl@@QAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82DEE600
// RVA : 0x00DEE600
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationSpaceImpl::UpdateTransform(
        idNavigationSpaceImpl *this,
        const idVec3 *origin,
        const idMat3 *axis)
{
  double y; // fp13
  const bfx::Quaternion *v6; // r3
  bfx::Vector3 v7; // [sp+50h] [-40h] BYREF
  bfx::Quaternion v8; // [sp+60h] [-30h] BYREF

  y = origin->y;
  v7.m_x = origin->x;
  v7.m_y = y;
  v7.m_z = origin->z;
  bfx::SpaceHandle::SetPos(this: &this->spaceHandle, pos: &v7);
  v6 = Convert(result: &v8, axis);
  bfx::SpaceHandle::SetRot(this: &this->spaceHandle, rot: v6);
}


// ========================================================================
// ?UpdateTransform@idNavigationSpace@@QAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82DEE670
// RVA : 0x00DEE670
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationSpace::UpdateTransform(idNavigationSpace *this, const idVec3 *origin, const idMat3 *axis)
{
  idNavigationSpaceImpl *impl; // r3

  impl = this->impl;
  if ( impl != nullptr && bfx::VolumeHandle::IsValid(this: &impl->spaceHandle) )
    idNavigationSpaceImpl::UpdateTransform(this: this->impl, origin, axis);
}


// ========================================================================
// ??4idNavigationSpace@@QAAAAV0@ABV0@@Z
// EA  : 0x82DEE6C0
// RVA : 0x00DEE6C0
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

idNavigationSpace *__fastcall idNavigationSpace::operator=(
        idNavigationSpace *this,
        const idNavigationSpace *otherSpace)
{
  if ( gameLocal->navPowerInstance != nullptr && this != otherSpace )
    bfx::ObstacleHandle::operator=(this: &this->impl->spaceHandle, rhs: &otherSpace->impl->spaceHandle);
  return this;
}


// ========================================================================
// ?AddNavigation@idNavigationMeshImpl@@QAA_NPAVidNavigationMesh@@@Z
// EA  : 0x82DEE720
// RVA : 0x00DEE720
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

int __fastcall idNavigationMeshImpl::AddNavigation(idNavigationMeshImpl *this, idNavigationMesh *resource)
{
  const bfx::ResourceOffset *v3; // r3
  bfx::ResourceOffset v5; // [sp+50h] [-40h] BYREF

  if ( this->navigationAdded )
    idLib::Warning(fmt: "Navigation '%s' already added", resource->name.str);
  if ( this->navigationAdded )
    return 0;
  bfx::ObstacleHandle::operator=(this: &this->navigationSpaceHandle, rhs: &activeSpaceHandle);
  if ( this->navigationBinaryBlob != nullptr )
  {
    v3 = bfx::ResourceOffset::ResourceOffset(this: &v5);
    bfx::AddResource(spaceHandle: &this->navigationSpaceHandle, pBinaryImage: this->navigationBinaryBlob, offset: v3);
  }
  this->navigationAdded = true;
  return 1;
}


// ========================================================================
// ?LoadFromFile@idNavigationMeshImpl@@QAA?AW4navLoadStatus_t@1@PAVidNavigationMesh@@PAVidFile@@@Z
// EA  : 0x82DEE7C8
// RVA : 0x00DEE7C8
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

int __fastcall idNavigationMeshImpl::LoadFromFile(idNavigationMeshImpl *this, idNavigationMesh *resource, idFile *file)
{
  unsigned int v5; // r28
  char *v6; // r3
  int v7; // r29
  unsigned int v8; // r3

  v5 = file->Length(this: file);
  v6 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\tungsten\\game\\navpower\\NavPowerResource.cpp(329) : TAG_NAVPOWER",
                 size: v5,
                 tag: TAG_NAVPOWER,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  this->navigationBinaryBlob = v6;
  v8 = file->Read(this: file, a2: v6, a3: v5);
  v7 = 0;
  if ( v8 != v5 )
  {
    v7 = 1;
    goto LABEL_6;
  }
  if ( idLib::production == PROD_DEVELOPMENT && !bfx::IsResourceUpToDate(pBinaryImage: this->navigationBinaryBlob) )
  {
    v7 = 2;
LABEL_6:
    idMem::Free(this: &mem, ptr: this->navigationBinaryBlob, align: ALIGN_16);
    this->navigationBinaryBlob = nullptr;
  }
  return v7;
}


// ========================================================================
// ?FreeData@idNavigationMeshImpl@@QAAXXZ
// EA  : 0x82DEE8A0
// RVA : 0x00DEE8A0
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationMeshImpl::FreeData(idNavigationMeshImpl *this)
{
  bfx::SpaceHandle *p_navigationSpaceHandle; // r30
  BOOL navigationAdded; // r11
  char *navigationBinaryBlob; // r4

  if ( this->navigationBinaryBlob != nullptr )
  {
    p_navigationSpaceHandle = &this->navigationSpaceHandle;
    bfx::RemoveResource(spaceHandle: &this->navigationSpaceHandle, pBinaryImage: this->navigationBinaryBlob);
    idMem::Free(this: &mem, ptr: this->navigationBinaryBlob, align: ALIGN_16);
    navigationAdded = this->navigationAdded;
    this->navigationBinaryBlob = nullptr;
    if ( navigationAdded )
      bfx::VolumeHandle::Release(this: p_navigationSpaceHandle);
    navigationBinaryBlob = this->navigationBinaryBlob;
    this->navigationAdded = false;
    if ( navigationBinaryBlob != nullptr )
    {
      idMem::Free(this: &mem, ptr: navigationBinaryBlob, align: ALIGN_16);
      this->navigationBinaryBlob = nullptr;
    }
  }
}


// ========================================================================
// ??1idNavigationMeshImpl@@QAA@XZ
// EA  : 0x82DEE930
// RVA : 0x00DEE930
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationMeshImpl::~idNavigationMeshImpl(idNavigationMeshImpl *this)
{
  idNavigationMeshImpl::FreeData(this);
  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: &this->navigationSpaceHandle);
}


// ========================================================================
// __unwind$489720
// EA  : 0x82DEE974
// RVA : 0x00DEE974
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_489720()
{
  int v0; // r12

  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: (bfx::SpaceHandle *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??0idNavigationMesh@@QAA@XZ
// EA  : 0x82DEE9A0
// RVA : 0x00DEE9A0
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

idNavigationMesh *__fastcall idNavigationMesh::idNavigationMesh(idNavigationMesh *this)
{
  idResource::idResource(this);
  this->timestamp = 0;
  this->__vftable = (idNavigationMesh_vtbl *)&idNavigationMesh::`vftable';
  this->resourceDependency.allocedAndFlag = 20;
  this->resourceDependency.data = this->resourceDependency.baseBuffer;
  this->resourceDependency.len = 0;
  this->resourceDependency.baseBuffer[0] = 0;
  this->impl = nullptr;
  return this;
}


// ========================================================================
// ?AddNavigation@idNavigationMesh@@QAA_NPAVidNavigationSpaceImpl@@@Z
// EA  : 0x82DEEA18
// RVA : 0x00DEEA18
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

int __fastcall idNavigationMesh::AddNavigation(idNavigationMesh *this, idNavigationSpaceImpl *space)
{
  int v3; // r31

  if ( this->impl == nullptr )
    return 0;
  bfx::ObstacleHandle::operator=(this: &activeSpaceHandle, rhs: &space->spaceHandle);
  v3 = idNavigationMeshImpl::AddNavigation(this: this->impl, resource: this);
  bfx::VolumeHandle::Release(this: &activeSpaceHandle);
  return v3;
}


// ========================================================================
// ?HasResourceLoaded@idNavigationSpaceImpl@@QAA_NPAVidNavigationMesh@@@Z
// EA  : 0x82DEEB30
// RVA : 0x00DEEB30
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

BOOL __fastcall idNavigationSpaceImpl::HasResourceLoaded(idNavigationSpaceImpl *this, idNavigationMesh *resource)
{
  int num; // r8
  int v3; // r10
  idNavigationMesh **list; // r9
  int i; // r11

  num = this->loadedResources.num;
  v3 = 0;
  if ( num <= 0 )
    return false;
  list = this->loadedResources.list;
  for ( i = 0; list[i] != resource; ++i )
  {
    if ( ++v3 >= num )
      return false;
  }
  return v3 >= 0 && &list[v3] != nullptr;
}


// ========================================================================
// ?HasResourceLoaded@idNavigationSpace@@QAA_NPAVidNavigationMesh@@@Z
// EA  : 0x82DEEB90
// RVA : 0x00DEEB90
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

BOOL __fastcall idNavigationSpace::HasResourceLoaded(idNavigationSpace *this, idNavigationMesh *resource)
{
  idNavigationSpaceImpl *impl; // r3
  bool IsValid; // r3
  BOOL result; // r3

  result = gameLocal->navPowerInstance != nullptr
        && ((impl = this->impl) == nullptr
          ? (IsValid = false)
          : (IsValid = bfx::VolumeHandle::IsValid(this: &impl->spaceHandle)),
            IsValid)
        && idNavigationSpaceImpl::HasResourceLoaded(this: this->impl, resource);
  return result;
}


// ========================================================================
// ?ReloadFrom@idNavigationMeshImpl@@QAAXPBV1@@Z
// EA  : 0x82DEEC18
// RVA : 0x00DEEC18
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationMeshImpl::ReloadFrom(idNavigationMeshImpl *this, const idNavigationMeshImpl *src)
{
  unsigned int ResourceSize; // r29
  char *v5; // r3
  const bfx::ResourceOffset *v6; // r3
  bfx::ResourceOffset v7[2]; // [sp+50h] [-40h] BYREF

  idNavigationMeshImpl::FreeData(this);
  ResourceSize = bfx::GetResourceSize(pBinaryImage: src->navigationBinaryBlob);
  v5 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\tungsten\\game\\navpower\\NavPowerResource.cpp(355) : TAG_NAVPOWER",
                 size: ResourceSize,
                 tag: TAG_NAVPOWER,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  this->navigationBinaryBlob = v5;
  memcpy(Dst: v5, Src: src->navigationBinaryBlob, Size: ResourceSize);
  v6 = bfx::ResourceOffset::ResourceOffset(this: v7);
  bfx::AddResource(spaceHandle: &this->navigationSpaceHandle, pBinaryImage: this->navigationBinaryBlob, offset: v6);
  this->navigationAdded = true;
}


// ========================================================================
// ??1idNavigationMesh@@UAA@XZ
// EA  : 0x82DEECA8
// RVA : 0x00DEECA8
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationMesh::~idNavigationMesh(idNavigationMesh *this)
{
  idNavigationMeshImpl *impl; // r29

  this->__vftable = (idNavigationMesh_vtbl *)&idNavigationMesh::`vftable';
  impl = this->impl;
  if ( impl != nullptr )
  {
    idNavigationMeshImpl::~idNavigationMeshImpl(this: this->impl);
    idMem::Free(this: &mem, ptr: impl, align: ALIGN_16);
  }
  idStr::FreeData(this: &this->resourceDependency);
  idResource::~idResource(this);
}


// ========================================================================
// __unwind$490109_0
// EA  : 0x82DEED0C
// RVA : 0x00DEED0C
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_490109_0()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490110_0
// EA  : 0x82DEED34
// RVA : 0x00DEED34
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_490110_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 44));
}


// ========================================================================
// ?Instance@idNavigationMesh@@QAAPAV1@XZ
// EA  : 0x82DEED68
// RVA : 0x00DEED68
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

idNavigationMesh *__fastcall idNavigationMesh::Instance(
        idNavigationMesh *this,
        int a2,
        int a3,
        int a4,
        __int64 a5,
        __int64 a6)
{
  idNavigationMeshImpl *impl; // r11
  idNavigationMesh *result; // r3
  __int64 v9; // r6
  va *v10; // r3
  idNavigationMesh *v11; // r29
  idNavigationMeshImpl *v12; // r3
  idNavigationMeshImpl *v13; // r3
  int v14; // [sp+8h] [-1078h]
  int v15; // [sp+Ch] [-1074h]
  int v16; // [sp+10h] [-1070h]
  int v17; // [sp+14h] [-106Ch]
  int v18; // [sp+18h] [-1068h]
  int v19; // [sp+1Ch] [-1064h]
  va v20; // [sp+60h] [-1020h] BYREF

  impl = this->impl;
  result = nullptr;
  if ( impl != nullptr && !impl->navigationAdded )
  {
    LODWORD(v9) = this->instanceCount;
    HIDWORD(v9) = this->name.str;
    LODWORD(a6) = v9 + 1;
    this->instanceCount = v9 + 1;
    v10 = va::va(
            this: &v20,
            fmt: "%s_i%3d",
            a3: v9,
            a4: a5,
            a5: a6,
            a6: v14,
            a7: v15,
            a8: v16,
            a9: v17,
            a10: v18,
            a11: v19);
    v11 = idTypedResourceList<idNavigationMesh>::Alloc(this: &idNavigationMesh::resourceList, name: v10->buffer);
    v11->timestamp = this->timestamp;
    v12 = (idNavigationMeshImpl *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0xCu,
                                    tag: TAG_NAVPOWER,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
    if ( v12 != nullptr )
      v13 = idNavigationMeshImpl::idNavigationMeshImpl(this: v12);
    else
      v13 = nullptr;
    v11->impl = v13;
    idStr::operator=(this: &v11->resourceDependency, text: this->name.str);
    idNavigationMeshImpl::CopyFrom(this: v11->impl, src: this->impl);
    return v11;
  }
  return result;
}


// ========================================================================
// __unwind$490150
// EA  : 0x82DEEE40
// RVA : 0x00DEEE40
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_490150()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 4224 + 80), tag: TAG_NAVPOWER);
}


// ========================================================================
// ?LoadResource@idNavigationMesh@@UAAXXZ
// EA  : 0x82DEEE78
// RVA : 0x00DEEE78
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationMesh::LoadResource(idNavigationMesh *this, int a2, __int64 a3, __int64 a4)
{
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  idResource *Existing; // r3
  idResource *v9; // r29
  unsigned int v10; // r11
  idNavigationMeshImpl *impl; // r3
  va *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r6
  __int64 v15; // r8
  va *v16; // r3
  idNavigationMeshImpl *v17; // r29
  production_t v18; // r11
  unsigned int v19; // r28
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  idFile *v23; // r3
  idNavigationMeshImpl *v24; // r3
  idFile *file; // r5
  int v26; // r3
  const char *v27; // r4
  int v28; // [sp+8h] [-20C8h]
  int v29; // [sp+8h] [-20C8h]
  int v30; // [sp+8h] [-20C8h]
  int v31; // [sp+Ch] [-20C4h]
  int v32; // [sp+Ch] [-20C4h]
  int v33; // [sp+Ch] [-20C4h]
  int v34; // [sp+10h] [-20C0h]
  int v35; // [sp+10h] [-20C0h]
  int v36; // [sp+10h] [-20C0h]
  int v37; // [sp+14h] [-20BCh]
  int v38; // [sp+14h] [-20BCh]
  int v39; // [sp+14h] [-20BCh]
  int v40; // [sp+18h] [-20B8h]
  int v41; // [sp+18h] [-20B8h]
  int v42; // [sp+18h] [-20B8h]
  int v43; // [sp+1Ch] [-20B4h]
  int v44; // [sp+1Ch] [-20B4h]
  int v45; // [sp+1Ch] [-20B4h]
  idFileLocal v46; // [sp+50h] [-2080h] BYREF
  idFileLocal v47; // [sp+54h] [-207Ch] BYREF
  idFileLocal v48[2]; // [sp+58h] [-2078h] BYREF
  idStr v49; // [sp+60h] [-2070h] BYREF
  idStr v50; // [sp+80h] [-2050h] BYREF
  va v51; // [sp+A0h] [-2030h] BYREF
  va v52; // [sp+10A0h] [-1030h] BYREF

  LODWORD(a4) = gameLocal->navPowerInstance;
  if ( (_DWORD)a4 != 0 )
  {
    if ( this->resourceDependency.len != 0 )
    {
      Existing = idResourceList::FindExisting(
                   this: &idNavigationMesh::resourceList,
                   name: this->resourceDependency.data,
                   skipStaleCheck: false);
      v9 = Existing;
      if ( Existing != nullptr )
      {
        v10 = (unsigned int)Existing[1].__vftable;
        impl = this->impl;
        this->timestamp = v10;
        idNavigationMeshImpl::ReloadFrom(this: impl, src: (const idNavigationMeshImpl *)v9[2].trackedMemory);
        this->trackedMemory = 92;
        this->trackedMemory = v9->trackedMemory + 92;
      }
      else
      {
        HIDWORD(v7) = this->name.str;
        idResource::SetResourceError(
          this,
          fmt: "idNavigationMesh '%s' dependency not found",
          a3: v7,
          a4: v6,
          a5: v5,
          a6: v28,
          a7: v31,
          a8: v34,
          a9: v37,
          a10: v40,
          a11: v43);
      }
      return;
    }
    HIDWORD(a3) = this->name.str;
    v12 = va::va(
            this: &v51,
            fmt: "%s_x32.nav",
            a3,
            a4,
            a5: 0x1AB340001A0000LL,
            a6: v28,
            a7: v31,
            a8: v34,
            a9: v37,
            a10: v40,
            a11: v43);
    idStr::idStr(this: &v49, text: v12);
    LODWORD(v13) = &unk_82340000;
    HIDWORD(v14) = this->name.str;
    v16 = va::va(
            this: &v52,
            fmt: "%s_x64.nav",
            a3: v14,
            a4: v15,
            a5: v13,
            a6: v29,
            a7: v32,
            a8: v35,
            a9: v38,
            a10: v41,
            a11: v44);
    idStr::idStr(this: &v50, text: v16);
    v17 = this->impl;
    if ( v17 != nullptr )
    {
      idNavigationMeshImpl::~idNavigationMeshImpl(this: this->impl);
      idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
    }
    this->impl = nullptr;
    v18 = idLib::production;
    if ( idLib::production == PROD_BUILDING )
    {
      v48[0].file = fileSystem->OpenFileRead(this: fileSystem, a2: v49.data, a3: 1, a4: 0);
      v47.file = fileSystem->OpenFileRead(this: fileSystem, a2: v50.data, a3: 1, a4: 0);
      idFileLocal::~idFileLocal(this: &v47);
      idFileLocal::~idFileLocal(this: v48);
      v18 = idLib::production;
    }
    v19 = 0;
    if ( v18 == PROD_DEVELOPMENT )
      v19 = fileSystem->GetTimestamp(this: fileSystem, a2: v49.data, a3: false);
    v46.file = fileSystem->OpenFileRead(this: fileSystem, a2: v49.data, a3: 1, a4: 0);
    this->timestamp = v19;
    v23 = (idFile *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0xCu,
                      tag: TAG_NAVPOWER,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
    v48[1].file = v23;
    if ( v23 != nullptr )
      v24 = idNavigationMeshImpl::idNavigationMeshImpl(this: (idNavigationMeshImpl *)v23);
    else
      v24 = nullptr;
    file = v46.file;
    this->impl = v24;
    this->trackedMemory = 92;
    if ( file != nullptr )
    {
      v26 = idNavigationMeshImpl::LoadFromFile(this: v24, resource: this, file);
      switch ( v26 )
      {
        case 0:
          this->trackedMemory += v46.file->Length(this: v46.file) + 80;
LABEL_24:
          idFileLocal::~idFileLocal(this: &v46);
          idStr::FreeData(this: &v50);
          idStr::FreeData(this: &v49);
          return;
        case 2:
          v27 = "idNavigationMesh '%s' wrong resource version, needs rebuilt";
          break;
        case 1:
          v27 = "idNavigationMesh '%s' bad file size, needs rebuilt";
          break;
        default:
          goto LABEL_24;
      }
    }
    else
    {
      v27 = "idNavigationMesh '%s' file not found";
    }
    HIDWORD(v22) = this->name.str;
    idResource::SetResourceError(
      this,
      fmt: v27,
      a3: v22,
      a4: v21,
      a5: v20,
      a6: v30,
      a7: v33,
      a8: v36,
      a9: v39,
      a10: v42,
      a11: v45);
    goto LABEL_24;
  }
}


// ========================================================================
// __unwind$490205
// EA  : 0x82DEF144
// RVA : 0x00DEF144
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_490205()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8400 + 96));
}


// ========================================================================
// __unwind$490206
// EA  : 0x82DEF16C
// RVA : 0x00DEF16C
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_490206()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8400 + 128));
}


// ========================================================================
// __unwind$490207
// EA  : 0x82DEF194
// RVA : 0x00DEF194
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_490207()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 8400 + 88));
}


// ========================================================================
// __unwind$490209
// EA  : 0x82DEF1BC
// RVA : 0x00DEF1BC
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_490209()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 8400 + 80));
}


// ========================================================================
// __unwind$490210
// EA  : 0x82DEF1E4
// RVA : 0x00DEF1E4
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_490210()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 8400 + 92), tag: TAG_NAVPOWER);
}


// ========================================================================
// ?ReloadIfStale@idNavigationMesh@@UAA_NXZ
// EA  : 0x82DEF218
// RVA : 0x00DEF218
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

int __fastcall idNavigationMesh::ReloadIfStale(idNavigationMesh *this, int a2, __int64 a3, __int64 a4)
{
  va *v5; // r3
  __int64 v6; // r10
  __int64 v7; // r6
  __int64 v8; // r8
  va *v9; // r3
  unsigned int v10; // r29
  bool v11; // r28
  idResource *Existing; // r3
  const bfx::Quaternion *v14; // r3
  int v15; // [sp+8h] [-2108h]
  int v16; // [sp+8h] [-2108h]
  int v17; // [sp+Ch] [-2104h]
  int v18; // [sp+Ch] [-2104h]
  int v19; // [sp+10h] [-2100h]
  int v20; // [sp+10h] [-2100h]
  int v21; // [sp+14h] [-20FCh]
  int v22; // [sp+14h] [-20FCh]
  int v23; // [sp+18h] [-20F8h]
  int v24; // [sp+18h] [-20F8h]
  int v25; // [sp+1Ch] [-20F4h]
  int v26; // [sp+1Ch] [-20F4h]
  bfx::Quaternion v27; // [sp+50h] [-20C0h] BYREF
  float z; // [sp+60h] [-20B0h]
  bfx::Vector3 v29[2]; // [sp+68h] [-20A8h] BYREF
  idStr v30; // [sp+80h] [-2090h] BYREF
  bfx::Quaternion v31; // [sp+A0h] [-2070h] BYREF
  idStr v32; // [sp+B0h] [-2060h] BYREF
  bfx::Quaternion v33; // [sp+D0h] [-2040h] BYREF
  va v34; // [sp+E0h] [-2030h] BYREF
  va v35; // [sp+10E0h] [-1030h] BYREF

  LODWORD(a4) = gameLocal->navPowerInstance;
  if ( (_DWORD)a4 == 0 )
    return 0;
  HIDWORD(a3) = this->name.str;
  v5 = va::va(
         this: &v34,
         fmt: "%s_x32.nav",
         a3,
         a4,
         a5: 0x1AB340001A0000LL,
         a6: v15,
         a7: v17,
         a8: v19,
         a9: v21,
         a10: v23,
         a11: v25);
  idStr::idStr(this: &v30, text: v5);
  LODWORD(v6) = &unk_82340000;
  HIDWORD(v7) = this->name.str;
  v9 = va::va(
         this: &v35,
         fmt: "%s_x64.nav",
         a3: v7,
         a4: v8,
         a5: v6,
         a6: v16,
         a7: v18,
         a8: v20,
         a9: v22,
         a10: v24,
         a11: v26);
  idStr::idStr(this: &v32, text: v9);
  v10 = fileSystem->GetTimestamp(this: fileSystem, a2: v30.data, a3: false);
  v11 = false;
  if ( this->resourceDependency.len != 0 )
  {
    Existing = idResourceList::FindExisting(
                 this: &idNavigationMesh::resourceList,
                 name: this->resourceDependency.data,
                 skipStaleCheck: false);
    if ( Existing != nullptr )
      v11 = Existing[1].__vftable != (idResource_vtbl *)this->timestamp;
  }
  if ( this->timestamp == v10 && !v11 )
  {
    idStr::FreeData(this: &v32);
    idStr::FreeData(this: &v30);
    return 0;
  }
  bfx::MultiPathRCPtr::MultiPathRCPtr(this: (bfx::SpaceHandle *)&v27, rhs: &this->impl->navigationSpaceHandle);
  this->LoadResource(this);
  if ( this->resourceError == nullptr )
  {
    bfx::SpaceHandle::GetPos(this: (bfx::SpaceHandle *)v29, result: (bfx::Vector3 *)&v27);
    bfx::SpaceHandle::GetRot(this: (bfx::SpaceHandle *)&v31, result: &v27);
    v27.m_y = vec3_origin.x;
    v27.m_z = vec3_origin.y;
    z = vec3_origin.z;
    bfx::SpaceHandle::SetPos(this: (bfx::SpaceHandle *)&v27, pos: (const bfx::Vector3 *)&v27.m_y);
    v14 = Convert(result: &v33, axis: &mat3_identity);
    bfx::SpaceHandle::SetRot(this: (bfx::SpaceHandle *)&v27, rot: v14);
    bfx::ObstacleHandle::operator=(this: &activeSpaceHandle, rhs: (const bfx::SpaceHandle *)&v27);
    idNavigationMeshImpl::AddNavigation(this: this->impl, resource: this);
    bfx::VolumeHandle::Release(this: &activeSpaceHandle);
    bfx::SpaceHandle::SetPos(this: (bfx::SpaceHandle *)&v27, pos: v29);
    bfx::SpaceHandle::SetRot(this: (bfx::SpaceHandle *)&v27, rot: &v31);
  }
  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: (bfx::SpaceHandle *)&v27);
  idStr::FreeData(this: &v32);
  idStr::FreeData(this: &v30);
  return 1;
}


// ========================================================================
// __unwind$490422
// EA  : 0x82DEF418
// RVA : 0x00DEF418
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_490422()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8464 + 128));
}


// ========================================================================
// __unwind$490423
// EA  : 0x82DEF440
// RVA : 0x00DEF440
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_490423()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8464 + 176));
}


// ========================================================================
// __unwind$490424
// EA  : 0x82DEF468
// RVA : 0x00DEF468
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_490424()
{
  int v0; // r12

  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: (bfx::SpaceHandle *)(v0 - 8464 + 80));
}


// ========================================================================
// ??0idNavigationSpaceImpl@@QAA@XZ
// EA  : 0x82DEF498
// RVA : 0x00DEF498
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

idNavigationSpaceImpl *__fastcall idNavigationSpaceImpl::idNavigationSpaceImpl(idNavigationSpaceImpl *this)
{
  bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: &this->spaceHandle);
  this->loadedResources.list = nullptr;
  this->loadedResources.granularity = 0;
  this->loadedResources.memTag = 5;
  this->loadedResources.listStatic = 0;
  this->loadedResources.size = 0;
  this->loadedResources.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->loadedResources);
  return this;
}


// ========================================================================
// __unwind$490562
// EA  : 0x82DEF500
// RVA : 0x00DEF500
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_490562()
{
  int v0; // r12

  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: *(bfx::SpaceHandle **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idNavigationSpaceImpl@@QAA@XZ
// EA  : 0x82DEF530
// RVA : 0x00DEF530
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationSpaceImpl::~idNavigationSpaceImpl(idNavigationSpaceImpl *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->loadedResources);
  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: &this->spaceHandle);
}


// ========================================================================
// __unwind$490583_0
// EA  : 0x82DEF578
// RVA : 0x00DEF578
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_490583_0()
{
  int v0; // r12

  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: *(bfx::SpaceHandle **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idNavigationSpace@@QAA@XZ
// EA  : 0x82DEF5A8
// RVA : 0x00DEF5A8
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

idNavigationSpace *__fastcall idNavigationSpace::idNavigationSpace(idNavigationSpace *this)
{
  idNavigationSpaceImpl *v2; // r3
  idNavigationSpaceImpl *v3; // r3

  this->impl = nullptr;
  if ( gameLocal != nullptr && gameLocal->navPowerInstance != nullptr )
  {
    v2 = (idNavigationSpaceImpl *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x14u,
                                    tag: TAG_NAVPOWER,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
    if ( v2 != nullptr )
      v3 = idNavigationSpaceImpl::idNavigationSpaceImpl(this: v2);
    else
      v3 = nullptr;
    this->impl = v3;
  }
  return this;
}


// ========================================================================
// __unwind$490608_0
// EA  : 0x82DEF650
// RVA : 0x00DEF650
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void _unwind_490608_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_NAVPOWER);
}


// ========================================================================
// ?LoadResource@idNavigationSpaceImpl@@QAA_NPAVidNavigationMesh@@@Z
// EA  : 0x82DEF7A8
// RVA : 0x00DEF7A8
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

int __fastcall idNavigationSpaceImpl::LoadResource(
        idNavigationSpaceImpl *this,
        idNavigationMesh *resource,
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
        idNavigationMesh *a14)
{
  a14 = resource;
  if ( resource != nullptr )
  {
    idNavigationMesh::AddNavigation(this: resource, space: this);
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->loadedResources,
      obj: (encounterGroupRole_t *)&a14);
  }
  return 0;
}


// ========================================================================
// ??1idNavigationSpace@@QAA@XZ
// EA  : 0x82DEF7F8
// RVA : 0x00DEF7F8
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationSpace::~idNavigationSpace(idNavigationSpace *this)
{
  idNavigationSpaceImpl *impl; // r31

  impl = this->impl;
  if ( this->impl != nullptr )
  {
    idNavigationSpaceImpl::~idNavigationSpaceImpl(this: this->impl);
    idMem::Free(this: &mem, ptr: impl, align: ALIGN_16);
    this->impl = nullptr;
  }
  else
  {
    this->impl = nullptr;
  }
}


// ========================================================================
// ?LoadResource@idNavigationSpace@@QAA_NPAVidNavigationMesh@@@Z
// EA  : 0x82DEF868
// RVA : 0x00DEF868
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

int __fastcall idNavigationSpace::LoadResource(idNavigationSpace *this, idNavigationMesh *resource)
{
  idNavigationSpaceImpl *impl; // r3
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r7
  int v10; // r6
  int v11; // r5
  int result; // r3
  bool v13; // zf
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+Ch] [-64h]
  int v16; // [sp+10h] [-60h]
  int v17; // [sp+14h] [-5Ch]
  int v18; // [sp+18h] [-58h]
  idNavigationMesh *v19; // [sp+1Ch] [-54h]

  if ( gameLocal->navPowerInstance == nullptr )
    return 0;
  impl = this->impl;
  if ( impl == nullptr || !bfx::VolumeHandle::IsValid(this: &impl->spaceHandle) )
    return 0;
  if ( idNavigationSpace::HasResourceLoaded(this, resource) )
    return 0;
  v13 = (unsigned __int8)idNavigationSpaceImpl::LoadResource(
                           this: this->impl,
                           resource,
                           a3: v11,
                           a4: v10,
                           a5: v9,
                           a6: v8,
                           a7: v7,
                           a8: v6,
                           a9: v14,
                           a10: v15,
                           a11: v16,
                           a12: v17,
                           a13: v18,
                           a14: v19) != 0;
  result = 1;
  if ( !v13 )
    return 0;
  return result;
}


// ========================================================================
// ?InstanceResource@idNavigationSpace@@QAA_NPAVidNavigationMesh@@@Z
// EA  : 0x82DEF918
// RVA : 0x00DEF918
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

int __fastcall idNavigationSpace::InstanceResource(
        idNavigationSpace *this,
        idNavigationMesh *resource,
        int a3,
        int a4,
        __int64 a5)
{
  __int64 v5; // r10
  idNavigationSpaceImpl *impl; // r3
  idNavigationMesh *v10; // r3
  idNavigationSpaceImpl *v11; // r31
  idNavigationMesh *v13; // [sp+50h] [-20h] BYREF

  v5 = 0x1AB340001A0000LL;
  LODWORD(a5) = gameLocal->navPowerInstance;
  if ( (_DWORD)a5 != 0 )
  {
    impl = this->impl;
    if ( impl != nullptr && bfx::VolumeHandle::IsValid(this: &impl->spaceHandle) )
    {
      v10 = idNavigationMesh::Instance(this: resource, a2: (int)resource, a3, a4, a5, a6: v5);
      v11 = this->impl;
      v13 = v10;
      if ( v10 != nullptr )
      {
        idNavigationMesh::AddNavigation(this: v10, space: v11);
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&v11->loadedResources,
          obj: (encounterGroupRole_t *)&v13);
      }
    }
  }
  return 0;
}


// ========================================================================
// ?DestroySpace@idNavigationSpaceImpl@@QAAXXZ
// EA  : 0x82DEFBF8
// RVA : 0x00DEFBF8
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationSpaceImpl::DestroySpace(idNavigationSpaceImpl *this)
{
  int v2; // r29
  int v3; // r30
  idNavigationMeshImpl *impl; // r3
  idNavigationMesh **list; // r4

  if ( idLib::production >= PROD_PRODUCTION )
  {
    v2 = 0;
    if ( this->loadedResources.num > 0 )
    {
      v3 = 0;
      do
      {
        impl = this->loadedResources.list[v3]->impl;
        if ( impl != nullptr )
          idNavigationMeshImpl::FreeData(this: impl);
        ++v2;
        ++v3;
      }
      while ( v2 < this->loadedResources.num );
    }
    if ( this->loadedResources.listStatic == 0 || this->loadedResources.listStatic == 2 )
    {
      list = this->loadedResources.list;
      if ( list != nullptr )
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      this->loadedResources.list = nullptr;
      this->loadedResources.size = 0;
    }
    this->loadedResources.num = 0;
  }
  else
  {
    idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->loadedResources);
  }
  if ( bfx::VolumeHandle::IsValid(this: &this->spaceHandle)
    && idList<bfx::SpaceHandle,5>::FindIndex(this: &deleteSpaces, obj: &this->spaceHandle, startIndex: 0) < 0 )
  {
    idList<bfx::SpaceHandle,5>::Append(this: &deleteSpaces, obj: &this->spaceHandle);
  }
  bfx::VolumeHandle::Release(this: &this->spaceHandle);
}


// ========================================================================
// ?DestroySpace@idNavigationSpace@@QAAXXZ
// EA  : 0x82DEFCF8
// RVA : 0x00DEFCF8
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __fastcall idNavigationSpace::DestroySpace(idNavigationSpace *this)
{
  idNavigationSpaceImpl *impl; // r3

  impl = this->impl;
  if ( impl != nullptr )
    idNavigationSpaceImpl::DestroySpace(this: impl);
}


// ========================================================================
// `dynamic initializer for 'idNavigationMesh::resourceList''
// EA  : 0x83386038
// RVA : 0x01386038
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idNavigationMesh::resourceList__()
{
  idResourceList::idResourceList(this: &idNavigationMesh::resourceList, typeName: "nav");
  idNavigationMesh::resourceList.__vftable = (idTypedResourceList<idNavigationMesh>_vtbl *)&idTypedResourceList<idNavigationMesh>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idNavigationMesh::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'activeSpaceHandle''
// EA  : 0x83386088
// RVA : 0x01386088
// PDB : w:\tech5\tungsten\game\navpower\navpowerresource.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__activeSpaceHandle__()
{
  bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: &activeSpaceHandle);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__activeSpaceHandle__);
}

