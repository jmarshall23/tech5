
// ========================================================================
// ?GetResourceList@idFileResource@@UBAPAVidResourceList@@XZ
// EA  : 0x82677B10
// RVA : 0x00677B10
// PDB : w:\tech5\engine\framework\fileresource.h
// ========================================================================

idTypedResourceList<idFileResource> *__fastcall idFileResource::GetResourceList(idFileResource *this)
{
  return &idFileResource::resourceList;
}


// ========================================================================
// ?GetFile@idFileResource@@QBAPAVidFile_Memory@@XZ
// EA  : 0x8276A338
// RVA : 0x0076A338
// PDB : w:\tech5\engine\framework\fileresource.h
// ========================================================================

idFile_Memory *__fastcall idFileResource::GetFile(idFileResource *this)
{
  idFile_Memory *v2; // r3
  idFile_Memory *v3; // r30

  v2 = (idFile_Memory *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x14Cu,
                          tag: TAG_FILE_RESOURCE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idFile_Memory::idFile_Memory(this: v2, name: this->name.str);
  else
    v3 = nullptr;
  idFile_Memory::SetReadOnlyData(this: v3, data: (const char *)this->data, length: this->length);
  return v3;
}


// ========================================================================
// __unwind$246515
// EA  : 0x8276A3B0
// RVA : 0x0076A3B0
// PDB : w:\tech5\engine\framework\fileresource.h
// ========================================================================

void _unwind_246515()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_FILE_RESOURCE);
}

