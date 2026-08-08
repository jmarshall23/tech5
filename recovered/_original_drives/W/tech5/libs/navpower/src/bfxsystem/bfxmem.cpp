
// ========================================================================
// ?bfxMemDefaultMalloc@MemoryManager@bfx@@AAAPAXIW4bfxMemTag@2@I@Z
// EA  : 0x8326D068
// RVA : 0x0126D068
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmem.cpp
// ========================================================================

unsigned int __fastcall bfx::MemoryManager::bfxMemDefaultMalloc(
        bfx::MemoryManager *this,
        unsigned int size,
        int tag,
        unsigned int alignment)
{
  unsigned int m_debugHeadSize; // r9
  int *v8; // r29
  unsigned int v9; // r27
  int v10; // r8
  int *v12; // r28
  bfx::bfxMemTag v13; // r11
  char *v14; // r11
  _DWORD *v15; // r31
  int v16; // r10
  int v17; // r11
  unsigned int v18; // r3
  unsigned int v19; // r4
  unsigned int v20; // r11
  unsigned int v21; // r3
  unsigned int v22; // r31

  m_debugHeadSize = this->m_debugHeadSize;
  if ( m_debugHeadSize != 0 || alignment <= 8 )
  {
    v10 = alignment - 4;
    if ( alignment <= 4 )
      v10 = 0;
    v8 = (int *)bfx::mspace_malloc(
                  msp: this->m_pMallocSpace,
                  bytes: m_debugHeadSize + this->m_debugTailSize + v10 + size);
    v9 = ((unsigned int)v8 + alignment + this->m_debugHeadSize - 1) & ~(alignment - 1);
  }
  else
  {
    v8 = (int *)bfx::mspace_memalign(msp: this->m_pMallocSpace, alignment, bytes: this->m_debugTailSize + size);
    v9 = (unsigned int)v8;
  }
  if ( v8 == nullptr )
    return 0;
  v12 = v8;
  if ( (this->m_debugFlags & 2) != 0 )
  {
    v12 = v8 + 1;
    *v8 = 53025141;
  }
  if ( (this->m_debugFlags & 1) != 0 )
    *v12++ = this->m_allocID & 0x7FFFFFFF;
  if ( (this->m_debugFlags & 4) != 0 )
  {
    *v12++ = tag & 0x7FFFFFFF;
    v13 = tag;
    if ( tag >= 255 )
      v13 = 254;
    v14 = &this->m_zeroHeader[24 * v13];
    v15 = v14 + 60;
    v16 = *((_DWORD *)v14 + 15);
    v17 = *((_DWORD *)v14 + 16);
    *v15 = v16 + 1;
    v15[1] = v17 + 1;
    v18 = bfx::mspace_malloc_usable_size(msp: this->m_pMallocSpace, mem: v8);
    v19 = v15[4];
    v20 = v15[3] + v18;
    v21 = v15[2] - this->m_debugTailSize - this->m_debugHeadSize + v18;
    v15[3] = v20;
    v15[2] = v21;
    if ( v21 > v19 )
      v15[4] = v21;
    if ( v20 > v15[5] )
      v15[5] = v20;
  }
  if ( (this->m_debugFlags & 2) != 0 )
  {
    v22 = bfx::mspace_malloc_usable_size(msp: this->m_pMallocSpace, mem: v8);
    memset(Dst: (char *)v8 + this->m_debugHeadSize, Val: 205, Size: v22 - this->m_debugHeadSize - this->m_debugTailSize);
    *(int *)((char *)v8 + v22 - 4) = -33686019;
  }
  if ( this->m_debugHeadSize != 0 && (unsigned int)v12 < v9 )
    *(_DWORD *)(v9 - 4) = (v9 - (_DWORD)v12) | 0x80000000;
  ++this->m_allocID;
  return v9;
}


// ========================================================================
// ?bfxMemDefaultFree@MemoryManager@bfx@@AAAXPAX@Z
// EA  : 0x8326D288
// RVA : 0x0126D288
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmem.cpp
// ========================================================================

void __fastcall bfx::MemoryManager::bfxMemDefaultFree(bfx::MemoryManager *this, char *ptr)
{
  unsigned int m_debugHeadSize; // r10
  char *v4; // r29
  int v5; // r11
  char *v6; // r31
  unsigned int v7; // r3
  unsigned int v8; // r4
  size_t v9; // r3

  if ( ptr != nullptr )
  {
    m_debugHeadSize = this->m_debugHeadSize;
    v4 = ptr;
    if ( m_debugHeadSize != 0 )
    {
      v5 = *((_DWORD *)ptr - 1);
      if ( v5 < 0 )
        v4 = &ptr[-(v5 & 0x7FFFFFFF)];
      v4 -= m_debugHeadSize;
    }
    if ( (this->m_debugFlags & 4) != 0 )
    {
      v6 = &this->m_zeroHeader[24 * *(_DWORD *)&v4[2 * ((2 * this->m_debugFlags) & 2) + 2 * (this->m_debugFlags & 2)]];
      --*((_DWORD *)v6 + 15);
      v7 = bfx::mspace_malloc_usable_size(msp: this->m_pMallocSpace, mem: v4);
      v8 = this->m_debugTailSize - v7 + *((_DWORD *)v6 + 17) + this->m_debugHeadSize;
      *((_DWORD *)v6 + 18) -= v7;
      *((_DWORD *)v6 + 17) = v8;
    }
    if ( (this->m_debugFlags & 2) != 0 )
    {
      v9 = bfx::mspace_malloc_usable_size(msp: this->m_pMallocSpace, mem: v4);
      memset(Dst: v4, Val: 221, Size: v9);
    }
    bfx::mspace_free(msp: this->m_pMallocSpace, mem: v4);
    ++this->m_freeID;
  }
}


// ========================================================================
// ?GetStats@MemoryManager@bfx@@QAA_NAAI00@Z
// EA  : 0x8326D390
// RVA : 0x0126D390
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmem.cpp
// ========================================================================

int __fastcall bfx::MemoryManager::GetStats(
        bfx::MemoryManager *this,
        unsigned int *allocatedBytes,
        unsigned int *freeBytes,
        unsigned int *totalBytes)
{
  bfx::mallinfo *v7; // r3
  char *v8; // r10
  unsigned int *p_keepcost; // r11
  int i; // ctr
  unsigned int v12; // r10
  unsigned int v13; // r9
  char v14; // [sp+4Ch] [-84h] BYREF
  unsigned int v15; // [sp+64h] [-6Ch]
  unsigned int v16; // [sp+6Ch] [-64h]
  unsigned int v17; // [sp+70h] [-60h]
  bfx::mallinfo v18[2]; // [sp+80h] [-50h] BYREF

  if ( this->m_pCustomAllocator != nullptr )
    return 0;
  v7 = bfx::mspace_mallinfo(result: v18, msp: this->m_pMallocSpace);
  v8 = &v14;
  p_keepcost = &v7[-1].keepcost;
  for ( i = 10; i != 0; --i )
  {
    ++p_keepcost;
    v8 += 4;
    *(_DWORD *)v8 = *p_keepcost;
  }
  v12 = v17;
  v13 = v15;
  *allocatedBytes = v16;
  *freeBytes = v12;
  *totalBytes = v13;
  return 1;
}


// ========================================================================
// ?Malloc@MemoryManager@bfx@@QAAPAXIW4bfxMemTag@2@@Z
// EA  : 0x8326D410
// RVA : 0x0126D410
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmem.cpp
// ========================================================================

int __fastcall bfx::MemoryManager::Malloc(bfx::MemoryManager *this, unsigned int size, int tag)
{
  bfx::CustomAllocator *m_pCustomAllocator; // r11
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  __int64 v9; // r4
  int v10; // r29
  void (*m_pOutOfMemCB)(void); // r11

  m_pCustomAllocator = this->m_pCustomAllocator;
  if ( m_pCustomAllocator != nullptr )
    HIDWORD(v9) = ((int (*)(void))m_pCustomAllocator->CustomMalloc)();
  else
    HIDWORD(v9) = bfx::MemoryManager::bfxMemDefaultMalloc(this, size, tag, alignment: 4u);
  v10 = HIDWORD(v9);
  if ( size != 0 && HIDWORD(v9) == 0 )
  {
    m_pOutOfMemCB = this->m_pOutOfMemCB;
    if ( m_pOutOfMemCB != nullptr )
    {
      m_pOutOfMemCB();
      return v10;
    }
    bfx::OutOfMemoryCrash(this: v9, a2: v8, a3: v7, a4: v6);
  }
  return v10;
}


// ========================================================================
// ?Memalign@MemoryManager@bfx@@QAAPAXIIW4bfxMemTag@2@@Z
// EA  : 0x8326D498
// RVA : 0x0126D498
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmem.cpp
// ========================================================================

int __fastcall bfx::MemoryManager::Memalign(
        bfx::MemoryManager *this,
        unsigned int alignment,
        unsigned int size,
        int tag)
{
  bfx::CustomAllocator *m_pCustomAllocator; // r11
  __int64 v8; // r6
  __int64 v9; // r4
  __int64 v10; // r10
  int v11; // r30
  __int64 v12; // r8
  void (*m_pOutOfMemCB)(void); // r11
  int v15; // [sp+8h] [-78h]
  int v16; // [sp+Ch] [-74h]
  int v17; // [sp+10h] [-70h]
  int v18; // [sp+14h] [-6Ch]

  m_pCustomAllocator = this->m_pCustomAllocator;
  if ( m_pCustomAllocator != nullptr )
  {
    HIDWORD(v9) = ((int (*)(void))m_pCustomAllocator->CustomAlignedMalloc)();
    HIDWORD(v10) = HIDWORD(v9) / alignment;
    v11 = HIDWORD(v9);
    LODWORD(v12) = HIDWORD(v9) / alignment * alignment;
    __twllei(alignment, 0);
    HIDWORD(v12) = HIDWORD(v9) % alignment;
    if ( HIDWORD(v9) % alignment != 0 )
    {
      HIDWORD(v9) = "CustomAlignedMalloc returned an improperly aligned block of memory and will crash\n";
      bfx::InternalWarning(fmt: v9, a2: v8, a3: v12, a4: v10, a5: v15, a6: v16, a7: v17, a8: v18);
      __trap();
      LODWORD(v10) = 0;
      MEMORY[0] = 0;
    }
  }
  else
  {
    HIDWORD(v9) = bfx::MemoryManager::bfxMemDefaultMalloc(this, size, tag, alignment);
    v11 = HIDWORD(v9);
  }
  if ( size != 0 && v11 == 0 )
  {
    m_pOutOfMemCB = this->m_pOutOfMemCB;
    if ( m_pOutOfMemCB != nullptr )
    {
      m_pOutOfMemCB();
      return 0;
    }
    bfx::OutOfMemoryCrash(this: v9, a2: v8, a3: v12, a4: v10);
  }
  return v11;
}


// ========================================================================
// ?Free@MemoryManager@bfx@@QAAXPAX@Z
// EA  : 0x8326D560
// RVA : 0x0126D560
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmem.cpp
// ========================================================================

void __fastcall bfx::MemoryManager::Free(bfx::MemoryManager *this, char *ptr)
{
  bfx::CustomAllocator *m_pCustomAllocator; // r11

  m_pCustomAllocator = this->m_pCustomAllocator;
  if ( m_pCustomAllocator != nullptr )
    ((void (*)(void))m_pCustomAllocator->CustomFree)();
  else
    bfx::MemoryManager::bfxMemDefaultFree(this, ptr);
}


// ========================================================================
// ?RegisterMemTag@bfx@@YA?AW4bfxMemTag@1@PBD@Z
// EA  : 0x8326D588
// RVA : 0x0126D588
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmem.cpp
// ========================================================================

bfx::bfxMemTag __fastcall bfx::RegisterMemTag(const char *tagName)
{
  bfx::bfxMemTag result; // r3

  result = ++s_lastTag;
  *(const char **)((char *)s_memTag + ((4 * s_lastTag) & 0x3FC)) = tagName;
  return result;
}


// ========================================================================
// ?GetTagStats@MemoryManager@bfx@@QAAIAAPBQBDAAPBUTagInfo@12@@Z
// EA  : 0x8326D5B8
// RVA : 0x0126D5B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxmem.cpp
// ========================================================================

unsigned int __fastcall bfx::MemoryManager::GetTagStats(
        bfx::MemoryManager *this,
        const char *const **tagLabels,
        bfx::MemoryManager::TagInfo **tagInfo)
{
  int v3; // r11

  if ( (this->m_debugFlags & 4) != 0 )
  {
    v3 = s_lastTag;
    *tagLabels = s_memTag;
    *tagInfo = this->m_memTagInfo;
    return v3 + 1;
  }
  else
  {
    *tagLabels = nullptr;
    *tagInfo = nullptr;
    return 0;
  }
}

