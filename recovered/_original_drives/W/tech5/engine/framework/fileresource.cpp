
// ========================================================================
// ?FreeData@idFileResource@@QAAXXZ
// EA  : 0x82677AB8
// RVA : 0x00677AB8
// PDB : w:\tech5\engine\framework\fileresource.cpp
// ========================================================================

void __fastcall idFileResource::FreeData(idFileResource *this)
{
  void *data; // r4

  data = this->data;
  if ( data != nullptr )
  {
    idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
    this->data = nullptr;
    this->length = 0;
    this->timestamp = -1;
  }
}


// ========================================================================
// ??1idFileResource@@UAA@XZ
// EA  : 0x82677B28
// RVA : 0x00677B28
// PDB : w:\tech5\engine\framework\fileresource.cpp
// ========================================================================

void __fastcall idFileResource::~idFileResource(idFileResource *this)
{
  void *data; // r4

  this->__vftable = (idFileResource_vtbl *)&idFileResource::`vftable';
  data = this->data;
  if ( data != nullptr )
  {
    idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
    this->data = nullptr;
    this->length = 0;
    this->timestamp = -1;
  }
  idResource::~idResource(this);
}


// ========================================================================
// __unwind$237282
// EA  : 0x82677BA4
// RVA : 0x00677BA4
// PDB : w:\tech5\engine\framework\fileresource.cpp
// ========================================================================

void _unwind_237282()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ?LoadResource@idFileResource@@UAAXXZ
// EA  : 0x82677BD0
// RVA : 0x00677BD0
// PDB : w:\tech5\engine\framework\fileresource.cpp
// ========================================================================

void __fastcall idFileResource::LoadResource(idFileResource *this)
{
  void *data; // r4
  const char *str; // r4
  idFile_Memory *v4; // r3
  idFile_Memory *v5; // r30
  unsigned int v6; // r3
  void *v7; // r3
  unsigned int length; // r5

  data = this->data;
  if ( data != nullptr )
  {
    idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
    this->data = nullptr;
    this->length = 0;
    this->timestamp = -1;
  }
  str = this->name.str;
  if ( idLib::production == PROD_LOADED )
    v4 = resourceManager->LoadCacheFile(this: resourceManager, a2: str);
  else
    v4 = (idFile_Memory *)fileSystem->OpenFileRead(this: fileSystem, a2: str, a3: 1, a4: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    this->timestamp = v4->Timestamp(this: v4);
    v6 = v5->Length(this: v5);
    this->length = v6;
    v7 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\engine\\framework\\FileResource.cpp(79) : TAG_FILE_RESOURCE",
           size: v6,
           tag: TAG_FILE_RESOURCE,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    length = this->length;
    this->data = v7;
    v5->Read(this: v5, a2: v7, a3: length);
    ((void (__fastcall *)(idFile_Memory *, int))v5->dtr_idFile)(a1: v5, a2: 1);
  }
  else
  {
    idResource::SetResourceError(this, fmt: "FileResource '%s' File not found", this->name.str);
  }
}


// ========================================================================
// ?GetFileReadOnly@idFileResource@@QAAPAVidFile_Memory@@XZ
// EA  : 0x82677D30
// RVA : 0x00677D30
// PDB : w:\tech5\engine\framework\fileresource.cpp
// ========================================================================

idFile_Memory *__fastcall idFileResource::GetFileReadOnly(idFileResource *this)
{
  idFile_Memory *v2; // r28
  idFile_Memory *result; // r3
  idFile_Memory *v4; // r29
  void *v5; // r3
  unsigned int length; // r5
  idFile_Memory *v7; // r3

  v2 = nullptr;
  if ( this->data != nullptr )
    goto LABEL_5;
  result = resourceManager->LoadCacheFile(this: resourceManager, a2: this->name.str);
  v4 = result;
  if ( result == nullptr )
    return result;
  this->timestamp = result->Timestamp(this: result);
  this->length = v4->Length(this: v4);
  v2 = (idFile_Memory *)_RTDynamicCast(
                          inptr: v4,
                          VfDelta: 0,
                          SrcType: &idFile `RTTI Type Descriptor',
                          TargetType: &idFile_Memory `RTTI Type Descriptor',
                          isReference: 0);
  if ( v2 == nullptr )
  {
    v5 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\engine\\framework\\FileResource.cpp(108) : TAG_FILE_RESOURCE",
           size: this->length,
           tag: TAG_FILE_RESOURCE,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    length = this->length;
    this->data = v5;
    v4->Read(this: v4, a2: v5, a3: length);
    ((void (__fastcall *)(idFile_Memory *, int))v4->dtr_idFile)(a1: v4, a2: 1);
LABEL_5:
    if ( this->data == nullptr )
      return v2;
    v7 = (idFile_Memory *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x14Cu,
                            tag: TAG_FILE_RESOURCE,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
    v2 = v7 != nullptr ? idFile_Memory::idFile_Memory(this: v7, name: this->name.str) : nullptr;
    idFile_Memory::SetReadOnlyData(this: v2, data: (const char *)this->data, length: this->length);
    if ( v2 == nullptr )
      return v2;
  }
  v2->Seek(this: v2, a2: 0, a3: FS_SEEK_SET);
  this->data = nullptr;
  v2->ownsData = true;
  return v2;
}


// ========================================================================
// __unwind$237360
// EA  : 0x82677EE0
// RVA : 0x00677EE0
// PDB : w:\tech5\engine\framework\fileresource.cpp
// ========================================================================

void _unwind_237360()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_FILE_RESOURCE);
}


// ========================================================================
// ?FileExists@idFileResource@@SA_NPBD@Z
// EA  : 0x82677F10
// RVA : 0x00677F10
// PDB : w:\tech5\engine\framework\fileresource.cpp
// ========================================================================

idFile_Memory *__fastcall idFileResource::FileExists(const char *name)
{
  idFile_Memory *result; // r3

  if ( idLib::production == PROD_LOADED )
    result = resourceManager->LoadCacheFile(this: resourceManager, a2: name);
  else
    result = (idFile_Memory *)fileSystem->OpenFileRead(this: fileSystem, a2: name, a3: 1, a4: 0);
  if ( result != nullptr )
  {
    ((void (__fastcall *)(idFile_Memory *, int))result->dtr_idFile)(a1: result, a2: 1);
    return (idFile_Memory *)1;
  }
  return result;
}


// ========================================================================
// `dynamic initializer for 'idFileResource::resourceList''
// EA  : 0x8333B838
// RVA : 0x0133B838
// PDB : w:\tech5\engine\framework\fileresource.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idFileResource::resourceList__()
{
  idResourceList::idResourceList(this: &idFileResource::resourceList, typeName: "file");
  idFileResource::resourceList.__vftable = (idTypedResourceList<idFileResource>_vtbl *)&idTypedResourceList<idFileResource>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idFileResource::resourceList__);
}

