
// ========================================================================
// ?UnbindBufferObjects@@YAXXZ
// EA  : 0x828A7410
// RVA : 0x008A7410
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall UnbindBufferObjects()
{
  unsigned __int64 v0; // r10
  unsigned __int64 v1; // r10
  unsigned __int64 v2; // r10
  unsigned __int64 v3; // r10

  if ( !idLib::headless )
  {
    D3DDevice_SetIndices(pDevice: d3d, pIndexData: nullptr);
    D3DDevice_SetStreamSource(
      pDevice: d3d,
      StreamNumber: 0,
      pVertexBuffer: nullptr,
      OffsetInBytes: 0,
      StrideInBytes: 0,
      PendingMask3: v0);
    D3DDevice_SetVertexShaderConstantB(pDevice: d3d, StartRegister: 0, pConstantData: &_real_00000000, BoolCount: 1u);
    D3DDevice_SetStreamSource(
      pDevice: d3d,
      StreamNumber: 1u,
      pVertexBuffer: nullptr,
      OffsetInBytes: 0,
      StrideInBytes: 0,
      PendingMask3: v1);
    D3DDevice_SetVertexShaderConstantB(pDevice: d3d, StartRegister: 1u, pConstantData: &_real_00000000, BoolCount: 1u);
    D3DDevice_SetStreamSource(
      pDevice: d3d,
      StreamNumber: 2u,
      pVertexBuffer: nullptr,
      OffsetInBytes: 0,
      StrideInBytes: 0,
      PendingMask3: v2);
    D3DDevice_SetVertexShaderConstantB(pDevice: d3d, StartRegister: 2u, pConstantData: &_real_00000000, BoolCount: 1u);
    D3DDevice_SetStreamSource(
      pDevice: d3d,
      StreamNumber: 3u,
      pVertexBuffer: nullptr,
      OffsetInBytes: 0,
      StrideInBytes: 0,
      PendingMask3: v3);
  }
}


// ========================================================================
// ?FreeBufferObject@idVertexBuffer@@QAAXXZ
// EA  : 0x828A7510
// RVA : 0x008A7510
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall idVertexBuffer::FreeBufferObject(idVertexBuffer *this)
{
  void *apiObject; // r4
  D3DVertexBuffer *v3; // r30
  void *v4; // r29

  if ( this->offsetInOtherBuffer < 0 )
  {
    apiObject = this->apiObject;
    if ( apiObject == nullptr )
      return;
    if ( idLib::headless )
    {
      idMem::Free(this: &mem, ptr: apiObject, align: ALIGN_16);
      this->apiObject = nullptr;
      return;
    }
    if ( r_showBuffers.valueInteger != 0 )
      idLib::Printf(fmt: "vertex buffer free %p, api %p (%i bytes)\n", this, this->apiObject, this->size & 0x7FFFFFFF);
    v3 = (D3DVertexBuffer *)this->apiObject;
    v4 = D3DVertexBuffer_Lock(pVertexBuffer: v3, OffsetToLock: 0, SizeToLock: 0, Flags: 0);
    D3DVertexBuffer_Unlock(pVertexBuffer: v3);
    XMemFree(pAddress: v4, dwAllocAttributes: 0xB4560000);
    idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
  }
  this->apiObject = nullptr;
  this->offsetInOtherBuffer = 0x80000000;
  this->size = 0;
}


// ========================================================================
// ?Reference@idVertexBuffer@@QAAXABV1@@Z
// EA  : 0x828A7600
// RVA : 0x008A7600
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall idVertexBuffer::Reference(idVertexBuffer *this, const idVertexBuffer *other)
{
  idVertexBuffer::FreeBufferObject(this);
  this->size = other->size & 0x7FFFFFFF;
  this->offsetInOtherBuffer = other->offsetInOtherBuffer & 0x7FFFFFFF;
  this->apiObject = other->apiObject;
  this->usage = other->usage;
}


// ========================================================================
// ?Reference@idVertexBuffer@@QAAXABV1@HH@Z
// EA  : 0x828A7660
// RVA : 0x008A7660
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall idVertexBuffer::Reference(
        idVertexBuffer *this,
        const idVertexBuffer *other,
        int refOffset,
        int refSize)
{
  idVertexBuffer::FreeBufferObject(this);
  this->size = refSize;
  this->offsetInOtherBuffer = (other->offsetInOtherBuffer & 0x7FFFFFFF) + refOffset;
  this->apiObject = other->apiObject;
  this->usage = other->usage;
}


// ========================================================================
// ?Update@idVertexBuffer@@QBAXPBXHH@Z
// EA  : 0x828A76B0
// RVA : 0x008A76B0
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall idVertexBuffer::Update(idVertexBuffer *this, const void *data, int updateSize, int vertexMask)
{
  D3DVertexBuffer *apiObject; // r28
  char *v8; // r3

  if ( idLib::headless )
  {
    memcpy(Dst: this->apiObject, Src: data, Size: updateSize);
  }
  else
  {
    if ( updateSize > this->size )
      idLib::FatalError(fmt: "idVertexBuffer::Update: size overrun, %i > %i\n", updateSize, this->size & 0x7FFFFFFF);
    apiObject = (D3DVertexBuffer *)this->apiObject;
    v8 = (char *)D3DVertexBuffer_Lock(pVertexBuffer: apiObject, OffsetToLock: 0, SizeToLock: 0, Flags: 0);
    XMemCpyStreaming_WriteCombined(
      dest: &v8[this->offsetInOtherBuffer & 0x7FFFFFFF],
      src: data,
      count: (updateSize + 15) & 0xFFFFFFF0);
    D3DVertexBuffer_Unlock(pVertexBuffer: apiObject);
  }
}


// ========================================================================
// ?TryMapBuffer@idVertexBuffer@@QBAPAXW4bufferMapType_t@@@Z
// EA  : 0x828A7750
// RVA : 0x008A7750
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

D3DVertexBuffer *__fastcall idVertexBuffer::TryMapBuffer(idVertexBuffer *this, bufferMapType_t mapType)
{
  D3DVertexBuffer *result; // r3

  result = (D3DVertexBuffer *)this->apiObject;
  if ( idLib::headless
    || (result = (D3DVertexBuffer *)D3DVertexBuffer_Lock(
                                      pVertexBuffer: result,
                                      OffsetToLock: 0,
                                      SizeToLock: 0,
                                      Flags: mapType != BM_READ ? 0 : 0x1000)) != nullptr
    && (result = (D3DVertexBuffer *)((char *)result + (this->offsetInOtherBuffer & 0x7FFFFFFF))) != nullptr )
  {
    this->size |= 0x80000000;
  }
  return result;
}


// ========================================================================
// ?UnmapBuffer@idVertexBuffer@@QBAXXZ
// EA  : 0x828A77D0
// RVA : 0x008A77D0
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall idVertexBuffer::UnmapBuffer(idPixelUnpackBuffer *this)
{
  if ( !idLib::headless )
    D3DVertexBuffer_Unlock(pVertexBuffer: (D3DVertexBuffer *)this->apiObject);
  this->size &= ~0x80000000;
}


// ========================================================================
// ??0idIndexBuffer@@QAA@XZ
// EA  : 0x828A7820
// RVA : 0x008A7820
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

idIndexBuffer *__fastcall idIndexBuffer::idIndexBuffer(idIndexBuffer *this)
{
  this->usage = BU_DEFAULT;
  this->offsetInOtherBuffer = 0x80000000;
  this->apiObject = nullptr;
  this->size = 0;
  return this;
}


// ========================================================================
// ?FreeBufferObject@idIndexBuffer@@QAAXXZ
// EA  : 0x828A7840
// RVA : 0x008A7840
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall idIndexBuffer::FreeBufferObject(idIndexBuffer *this)
{
  void *apiObject; // r4
  D3DIndexBuffer *v3; // r30
  void *v4; // r29

  if ( this->offsetInOtherBuffer < 0 )
  {
    apiObject = this->apiObject;
    if ( apiObject == nullptr )
      return;
    if ( idLib::headless )
    {
      idMem::Free(this: &mem, ptr: apiObject, align: ALIGN_16);
      this->apiObject = nullptr;
      return;
    }
    if ( r_showBuffers.valueInteger != 0 )
      idLib::Printf(fmt: "index buffer free %p, api %p (%i bytes)\n", this, this->apiObject, this->size & 0x7FFFFFFF);
    v3 = (D3DIndexBuffer *)this->apiObject;
    v4 = D3DIndexBuffer_Lock(pIndexBuffer: v3, OffsetToLock: 0, SizeToLock: 0, Flags: 0);
    D3DIndexBuffer_Unlock(pIndexBuffer: v3);
    XMemFree(pAddress: v4, dwAllocAttributes: 0xB4560000);
    idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
  }
  this->apiObject = nullptr;
  this->offsetInOtherBuffer = 0x80000000;
  this->size = 0;
}


// ========================================================================
// ?Reference@idIndexBuffer@@QAAXABV1@@Z
// EA  : 0x828A7930
// RVA : 0x008A7930
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall idIndexBuffer::Reference(idIndexBuffer *this, const idIndexBuffer *other)
{
  idIndexBuffer::FreeBufferObject(this);
  this->size = other->size & 0x7FFFFFFF;
  this->offsetInOtherBuffer = other->offsetInOtherBuffer & 0x7FFFFFFF;
  this->apiObject = other->apiObject;
  this->usage = other->usage;
}


// ========================================================================
// ?Reference@idIndexBuffer@@QAAXABV1@HH@Z
// EA  : 0x828A7990
// RVA : 0x008A7990
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall idIndexBuffer::Reference(idIndexBuffer *this, const idIndexBuffer *other, int refOffset, int refSize)
{
  idIndexBuffer::FreeBufferObject(this);
  this->size = refSize;
  this->offsetInOtherBuffer = (other->offsetInOtherBuffer & 0x7FFFFFFF) + refOffset;
  this->apiObject = other->apiObject;
  this->usage = other->usage;
}


// ========================================================================
// ?Update@idIndexBuffer@@QBAXPBXH@Z
// EA  : 0x828A79E0
// RVA : 0x008A79E0
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall idIndexBuffer::Update(idIndexBuffer *this, const void *data, int updateSize)
{
  D3DIndexBuffer *apiObject; // r28
  char *v7; // r3

  if ( idLib::headless )
  {
    memcpy(Dst: this->apiObject, Src: data, Size: updateSize);
  }
  else
  {
    if ( updateSize > this->size )
      idLib::FatalError(fmt: "idIndexBuffer::Update: size overrun, %i > %i\n", updateSize, this->size & 0x7FFFFFFF);
    apiObject = (D3DIndexBuffer *)this->apiObject;
    v7 = (char *)D3DIndexBuffer_Lock(pIndexBuffer: apiObject, OffsetToLock: 0, SizeToLock: 0, Flags: 0);
    XMemCpyStreaming_WriteCombined(
      dest: &v7[this->offsetInOtherBuffer & 0x7FFFFFFF],
      src: data,
      count: (updateSize + 15) & 0xFFFFFFF0);
    D3DIndexBuffer_Unlock(pIndexBuffer: apiObject);
  }
}


// ========================================================================
// ?TryMapBuffer@idIndexBuffer@@QBAPAXW4bufferMapType_t@@@Z
// EA  : 0x828A7A80
// RVA : 0x008A7A80
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

D3DIndexBuffer *__fastcall idIndexBuffer::TryMapBuffer(idIndexBuffer *this, bufferMapType_t mapType)
{
  D3DIndexBuffer *result; // r3

  result = (D3DIndexBuffer *)this->apiObject;
  if ( idLib::headless
    || (result = (D3DIndexBuffer *)D3DIndexBuffer_Lock(
                                     pIndexBuffer: result,
                                     OffsetToLock: 0,
                                     SizeToLock: 0,
                                     Flags: mapType != BM_READ ? 0 : 0x1000)) != nullptr
    && (result = (D3DIndexBuffer *)((char *)result + (this->offsetInOtherBuffer & 0x7FFFFFFF))) != nullptr )
  {
    this->size |= 0x80000000;
  }
  return result;
}


// ========================================================================
// ?UnmapBuffer@idIndexBuffer@@QBAXXZ
// EA  : 0x828A7B00
// RVA : 0x008A7B00
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall idIndexBuffer::UnmapBuffer(idIndexBuffer *this)
{
  if ( !idLib::headless )
    D3DIndexBuffer_Unlock(pIndexBuffer: (D3DIndexBuffer *)this->apiObject);
  this->size &= ~0x80000000;
}


// ========================================================================
// ??0idJointBuffer@@QAA@XZ
// EA  : 0x828A7B50
// RVA : 0x008A7B50
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

idJointBuffer *__fastcall idJointBuffer::idJointBuffer(idJointBuffer *this)
{
  this->apiObject = nullptr;
  this->offsetInOtherBuffer = 0x80000000;
  this->flags = 0;
  this->numJoints = 0;
  return this;
}


// ========================================================================
// ?FreeBufferObject@idJointBuffer@@QAAXXZ
// EA  : 0x828A7B70
// RVA : 0x008A7B70
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall idJointBuffer::FreeBufferObject(idJointBuffer *this)
{
  void *apiObject; // r4
  D3DVertexBuffer *v3; // r30
  void *v4; // r29

  if ( this->offsetInOtherBuffer < 0 )
  {
    apiObject = this->apiObject;
    if ( apiObject == nullptr )
      return;
    if ( idLib::headless )
    {
      idMem::Free(this: &mem, ptr: apiObject, align: ALIGN_16);
      this->apiObject = nullptr;
      return;
    }
    if ( r_showBuffers.valueInteger != 0 )
      idLib::Printf(
        fmt: "joint buffer free %p, api %p (%i joints)\n",
        this,
        this->apiObject,
        this->numJoints & 0x7FFFFFFF);
    v3 = (D3DVertexBuffer *)this->apiObject;
    v4 = D3DVertexBuffer_Lock(pVertexBuffer: v3, OffsetToLock: 0, SizeToLock: 0, Flags: 0);
    D3DVertexBuffer_Unlock(pVertexBuffer: v3);
    XMemFree(pAddress: v4, dwAllocAttributes: 0xB4560000);
    idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
  }
  this->flags = 0;
  this->apiObject = nullptr;
  this->offsetInOtherBuffer = 0x80000000;
  this->numJoints = 0;
}


// ========================================================================
// ?Reference@idJointBuffer@@QAAXABV1@HH@Z
// EA  : 0x828A7C60
// RVA : 0x008A7C60
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall idJointBuffer::Reference(
        idJointBuffer *this,
        const idJointBuffer *other,
        int jointRefOffset,
        int numRefJoints)
{
  int flags; // r9

  idJointBuffer::FreeBufferObject(this);
  flags = this->flags;
  this->numJoints = numRefJoints;
  this->offsetInOtherBuffer = 16 * (((flags & 1) == 0) | 2) * jointRefOffset + (other->offsetInOtherBuffer & 0x7FFFFFFF);
  this->apiObject = other->apiObject;
  this->flags = other->flags;
}


// ========================================================================
// ?Update@idJointBuffer@@QBAXPBMH@Z
// EA  : 0x828A7CC8
// RVA : 0x008A7CC8
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall idJointBuffer::Update(idJointBuffer *this, const float *joints, int numUpdateJoints)
{
  int v4; // r4
  int v6; // r8
  unsigned int v7; // r30
  D3DVertexBuffer *apiObject; // r28
  char *v9; // r3

  v4 = numUpdateJoints;
  if ( numUpdateJoints > this->numJoints )
    idLib::FatalError(fmt: "idJointBuffer::Update: size overrun, %i > %i\n", numUpdateJoints, this->numJoints);
  v6 = ((this->flags & 1) == 0) | 2;
  v7 = 16 * v6 * v4;
  if ( idLib::headless )
  {
    memcpy(Dst: this->apiObject, Src: joints, Size: 16 * v6 * v4);
  }
  else
  {
    apiObject = (D3DVertexBuffer *)this->apiObject;
    v9 = (char *)D3DVertexBuffer_Lock(pVertexBuffer: apiObject, OffsetToLock: 0, SizeToLock: 0, Flags: 0);
    XMemCpyStreaming_WriteCombined(dest: &v9[this->offsetInOtherBuffer & 0x7FFFFFFF], src: joints, count: v7);
    D3DVertexBuffer_Unlock(pVertexBuffer: apiObject);
  }
}


// ========================================================================
// ?TryMapBuffer@idJointBuffer@@QBAPAMW4bufferMapType_t@@@Z
// EA  : 0x828A7D78
// RVA : 0x008A7D78
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

D3DVertexBuffer *__fastcall idJointBuffer::TryMapBuffer(idJointBuffer *this, bufferMapType_t mapType)
{
  int numJoints; // r11
  D3DVertexBuffer *result; // r3
  int v5; // r8
  int v6; // r9

  numJoints = this->numJoints;
  v5 = this->numJoints & 0x7FFFFFFF;
  v6 = 2 * this->numJoints;
  result = (D3DVertexBuffer *)this->apiObject;
  if ( idLib::headless )
  {
    this->numJoints = numJoints | 0x80000000;
  }
  else
  {
    result = (D3DVertexBuffer *)D3DVertexBuffer_Lock(
                                  pVertexBuffer: result,
                                  OffsetToLock: 0,
                                  SizeToLock: 16 * (v5 + v6),
                                  Flags: mapType != BM_READ ? 0 : 0x1000);
    if ( result != nullptr )
    {
      result = (D3DVertexBuffer *)((char *)result + (this->offsetInOtherBuffer & 0x7FFFFFFF));
      if ( result != nullptr )
        this->numJoints |= 0x80000000;
    }
  }
  return result;
}


// ========================================================================
// ?Swap@idJointBuffer@@QAAXAAV1@@Z
// EA  : 0x828A7E20
// RVA : 0x008A7E20
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall idJointBuffer::Swap(idJointBuffer *this, idJointBuffer *other)
{
  int numJoints; // r10
  int offsetInOtherBuffer; // r9
  void *apiObject; // r7
  int flags; // r5

  numJoints = other->numJoints;
  other->numJoints = this->numJoints;
  this->numJoints = numJoints;
  offsetInOtherBuffer = other->offsetInOtherBuffer;
  other->offsetInOtherBuffer = this->offsetInOtherBuffer;
  this->offsetInOtherBuffer = offsetInOtherBuffer;
  apiObject = other->apiObject;
  other->apiObject = this->apiObject;
  this->apiObject = apiObject;
  flags = other->flags;
  other->flags = this->flags;
  this->flags = flags;
}


// ========================================================================
// ??0idPixelUnpackBuffer@@QAA@XZ
// EA  : 0x828A7E68
// RVA : 0x008A7E68
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

idPixelUnpackBuffer *__fastcall idPixelUnpackBuffer::idPixelUnpackBuffer(idPixelUnpackBuffer *this)
{
  this->apiObject = nullptr;
  this->offsetInOtherBuffer = 0x80000000;
  this->size = 0;
  return this;
}


// ========================================================================
// ?FreeBufferObject@idPixelUnpackBuffer@@QAAXXZ
// EA  : 0x828A7E80
// RVA : 0x008A7E80
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __fastcall idPixelUnpackBuffer::FreeBufferObject(idPixelUnpackBuffer *this)
{
  void *apiObject; // r4
  D3DVertexBuffer *v3; // r30
  void *v4; // r29

  if ( this->offsetInOtherBuffer < 0 )
  {
    apiObject = this->apiObject;
    if ( apiObject == nullptr )
      return;
    if ( idLib::headless )
    {
      idMem::Free(this: &mem, ptr: apiObject, align: ALIGN_16);
      this->apiObject = nullptr;
      return;
    }
    if ( r_showBuffers.valueInteger != 0 )
      idLib::Printf(
        fmt: "pixel unpack buffer free %p, api %p (%i bytes)\n",
        this,
        this->apiObject,
        this->size & 0x7FFFFFFF);
    v3 = (D3DVertexBuffer *)this->apiObject;
    v4 = D3DVertexBuffer_Lock(pVertexBuffer: v3, OffsetToLock: 0, SizeToLock: 0, Flags: 0);
    D3DVertexBuffer_Unlock(pVertexBuffer: v3);
    XMemFree(pAddress: v4, dwAllocAttributes: 0xB4560000);
    idMem::Free(this: &mem, ptr: v3, align: ALIGN_16);
  }
  this->apiObject = nullptr;
  this->offsetInOtherBuffer = 0x80000000;
  this->size = 0;
}


// ========================================================================
// ??1idVertexBuffer@@QAA@XZ
// EA  : 0x828A7F70
// RVA : 0x008A7F70
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

// attributes: thunk
void __fastcall idVertexBuffer::~idVertexBuffer(idVertexBuffer *this)
{
  idVertexBuffer::FreeBufferObject(this);
}


// ========================================================================
// ?AllocBufferObject@idVertexBuffer@@QAA_NPBXHHW4bufferUsageType_t@@@Z
// EA  : 0x828A7F80
// RVA : 0x008A7F80
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

int __fastcall idVertexBuffer::AllocBufferObject(
        idVertexBuffer *this,
        const void *data,
        int allocSize,
        int vertexMask,
        bufferUsageType_t allocUsage)
{
  void *v9; // r24
  D3DVertexBuffer *v10; // r29

  if ( allocSize <= 0 )
    idLib::Error(fmt: "idVertexBuffer::AllocBufferObject: allocSize = %i", allocSize);
  this->size = allocSize;
  this->usage = allocUsage;
  if ( idLib::headless )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    this->apiObject = idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\engine\\renderer\\BufferObject.cpp(232) : TAG_DXBUFFER",
                        size: this->size,
                        tag: TAG_DXBUFFER,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
    if ( data != nullptr )
      idVertexBuffer::Update(this, data, updateSize: allocSize, vertexMask);
    idMem::PopHeap(this: &mem);
  }
  else
  {
    v9 = XMemAlloc(dwSize: ((allocSize & 0x7FFFFFFF) + 15) & 0xFFFFFFF0, dwAllocAttributes: 0xB4560000);
    v10 = (D3DVertexBuffer *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x20u,
                               tag: TAG_DXOBJECT,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    XGSetVertexBufferHeader(
      Length: ((allocSize & 0x7FFFFFFF) + 15) & 0xFFFFFFF0,
      Usage: 0,
      Pool: 0,
      Offset: 0,
      pVertexBuffer: v10);
    XGOffsetResourceAddress(pResource: v10, pBaseAddress: v9);
    this->apiObject = v10;
    if ( r_showBuffers.valueInteger != 0 )
      idLib::Printf(fmt: "vertex buffer alloc %p, api %p (%i bytes)\n", this, v10, this->size & 0x7FFFFFFF);
    if ( data != nullptr )
      idVertexBuffer::Update(this, data, updateSize: allocSize, vertexMask);
  }
  return 1;
}


// ========================================================================
// $LN25_0
// EA  : 0x828A8100
// RVA : 0x008A8100
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void _LN25_0()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 160 + 80));
}


// ========================================================================
// ?MapBuffer@idVertexBuffer@@QBAPAXW4bufferMapType_t@@@Z
// EA  : 0x828A8128
// RVA : 0x008A8128
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

D3DVertexBuffer *__fastcall idVertexBuffer::MapBuffer(idVertexBuffer *this, bufferMapType_t mapType)
{
  D3DVertexBuffer *v2; // r3
  D3DVertexBuffer *v3; // r31

  v2 = idVertexBuffer::TryMapBuffer(this, mapType);
  v3 = v2;
  if ( !idLib::headless && v2 == nullptr )
    idLib::Warning(fmt: "idVertexBuffer::MapBuffer: failed");
  return v3;
}


// ========================================================================
// ??1idIndexBuffer@@QAA@XZ
// EA  : 0x828A8180
// RVA : 0x008A8180
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

// attributes: thunk
void __fastcall idIndexBuffer::~idIndexBuffer(idIndexBuffer *this)
{
  idIndexBuffer::FreeBufferObject(this);
}


// ========================================================================
// ?AllocBufferObject@idIndexBuffer@@QAA_NPBXHW4bufferUsageType_t@@@Z
// EA  : 0x828A8190
// RVA : 0x008A8190
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

int __fastcall idIndexBuffer::AllocBufferObject(
        idIndexBuffer *this,
        const void *data,
        int allocSize,
        bufferUsageType_t allocUsage)
{
  void *v7; // r25
  D3DIndexBuffer *v8; // r29

  if ( allocSize <= 0 )
    idLib::Error(fmt: "idIndexBuffer::AllocBufferObject: allocSize = %i", allocSize);
  this->size = allocSize;
  this->usage = allocUsage;
  if ( idLib::headless )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    this->apiObject = idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\engine\\renderer\\BufferObject.cpp(863) : TAG_DXBUFFER",
                        size: this->size,
                        tag: TAG_DXBUFFER,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
    if ( data != nullptr )
      idIndexBuffer::Update(this, data, updateSize: allocSize);
    idMem::PopHeap(this: &mem);
  }
  else
  {
    v7 = XMemAlloc(dwSize: ((allocSize & 0x7FFFFFFF) + 15) & 0xFFFFFFF0, dwAllocAttributes: 0xB4560000);
    v8 = (D3DIndexBuffer *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x20u,
                             tag: TAG_DXOBJECT,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
    XGSetIndexBufferHeader(
      Length: ((allocSize & 0x7FFFFFFF) + 15) & 0xFFFFFFF0,
      Usage: 0,
      Format: D3DFMT_INDEX16,
      Pool: 0,
      Offset: 0,
      pIndexBuffer: v8);
    XGOffsetResourceAddress(pResource: v8, pBaseAddress: v7);
    this->apiObject = v8;
    if ( r_showBuffers.valueInteger != 0 )
      idLib::Printf(fmt: "index buffer alloc %p, api %p (%i bytes)\n", this, v8, this->size & 0x7FFFFFFF);
    if ( data != nullptr )
      idIndexBuffer::Update(this, data, updateSize: allocSize);
  }
  return 1;
}


// ========================================================================
// $LN25_1
// EA  : 0x828A8308
// RVA : 0x008A8308
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void _LN25_1()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 160 + 80));
}


// ========================================================================
// ?MapBuffer@idIndexBuffer@@QBAPAXW4bufferMapType_t@@@Z
// EA  : 0x828A8330
// RVA : 0x008A8330
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

D3DIndexBuffer *__fastcall idIndexBuffer::MapBuffer(idIndexBuffer *this, bufferMapType_t mapType)
{
  D3DIndexBuffer *v2; // r3
  D3DIndexBuffer *v3; // r31

  v2 = idIndexBuffer::TryMapBuffer(this, mapType);
  v3 = v2;
  if ( !idLib::headless && v2 == nullptr )
    idLib::Warning(fmt: "idIndexBuffer::MapBuffer: failed");
  return v3;
}


// ========================================================================
// ??1idJointBuffer@@QAA@XZ
// EA  : 0x828A8388
// RVA : 0x008A8388
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

// attributes: thunk
void __fastcall idJointBuffer::~idJointBuffer(idJointBuffer *this)
{
  idJointBuffer::FreeBufferObject(this);
}


// ========================================================================
// ?AllocBufferObject@idJointBuffer@@QAA_NPBMH@Z
// EA  : 0x828A8398
// RVA : 0x008A8398
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

int __fastcall idJointBuffer::AllocBufferObject(idJointBuffer *this, const float *joints, int numAllocJoints)
{
  int v6; // r8
  unsigned int v7; // r29
  void *v8; // r25
  D3DVertexBuffer *v9; // r27

  if ( numAllocJoints <= 0 )
    idLib::Error(fmt: "idJointBuffer::AllocBufferObject: joints = %i", numAllocJoints);
  this->numJoints = numAllocJoints;
  v6 = (numAllocJoints & 0x7FFFFFFF) + 2 * numAllocJoints;
  v7 = 16 * v6;
  if ( idLib::headless )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    this->apiObject = idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\engine\\renderer\\BufferObject.cpp(1741) : TAG_DXBUFFER",
                        size: v7,
                        tag: TAG_DXBUFFER,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
    if ( joints != nullptr )
      idJointBuffer::Update(this, joints, numUpdateJoints: numAllocJoints);
    idMem::PopHeap(this: &mem);
  }
  else
  {
    v8 = XMemAlloc(dwSize: 16 * v6, dwAllocAttributes: 0xB4560000);
    v9 = (D3DVertexBuffer *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x20u,
                              tag: TAG_DXOBJECT,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
    XGSetVertexBufferHeader(Length: v7, Usage: 0, Pool: 0, Offset: 0, pVertexBuffer: v9);
    XGOffsetResourceAddress(pResource: v9, pBaseAddress: v8);
    this->apiObject = v9;
    if ( r_showBuffers.valueInteger != 0 )
      idLib::Printf(fmt: "joint buffer alloc %p, api %p (%i joints)\n", this, v9, this->numJoints & 0x7FFFFFFF);
    if ( joints != nullptr )
      idJointBuffer::Update(this, joints, numUpdateJoints: numAllocJoints);
  }
  return 1;
}


// ========================================================================
// $LN25_2
// EA  : 0x828A850C
// RVA : 0x008A850C
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void _LN25_2()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 160 + 80));
}


// ========================================================================
// ?MapBuffer@idJointBuffer@@QBAPAMW4bufferMapType_t@@@Z
// EA  : 0x828A8538
// RVA : 0x008A8538
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

D3DVertexBuffer *__fastcall idJointBuffer::MapBuffer(idJointBuffer *this, bufferMapType_t mapType)
{
  D3DVertexBuffer *v2; // r3
  D3DVertexBuffer *v3; // r31

  v2 = idJointBuffer::TryMapBuffer(this, mapType);
  v3 = v2;
  if ( !idLib::headless && v2 == nullptr )
    idLib::Warning(fmt: "idJointBuffer::MapBuffer: failed");
  return v3;
}


// ========================================================================
// ??1idPixelUnpackBuffer@@QAA@XZ
// EA  : 0x828A8590
// RVA : 0x008A8590
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

// attributes: thunk
void __fastcall idPixelUnpackBuffer::~idPixelUnpackBuffer(idPixelUnpackBuffer *this)
{
  idPixelUnpackBuffer::FreeBufferObject(this);
}


// ========================================================================
// `dynamic initializer for 'r_showBuffers''
// EA  : 0x83346398
// RVA : 0x01346398
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_showBuffers__()
{
  idCVar::idCVar(
    this: &r_showBuffers,
    name: "r_showBuffers",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_showBuffers__);
}


// ========================================================================
// `dynamic initializer for 'bo_useUnsynchronizedPBOs''
// EA  : 0x833463F0
// RVA : 0x013463F0
// PDB : w:\tech5\engine\renderer\bufferobject.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bo_useUnsynchronizedPBOs__()
{
  idCVar::idCVar(
    this: &bo_useUnsynchronizedPBOs,
    name: "bo_useUnsynchronizedPBOs",
    value: "0",
    flags: 17,
    description: "use unsynchronized PBO updates on the PC",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bo_useUnsynchronizedPBOs__);
}

