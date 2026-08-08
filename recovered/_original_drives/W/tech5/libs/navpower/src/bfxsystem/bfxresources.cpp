
// ========================================================================
// ?EndianSwap@ResourceHeader@bfx@@QAAXXZ
// EA  : 0x8326C1D0
// RVA : 0x0126C1D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

void __fastcall bfx::ResourceHeader::EndianSwap(bfx::ResourceHeader *this)
{
  this->m_endianFlag = (this->m_endianFlag != 0) - 1;
  bfx::EndianSwapLong(val: &this->m_version);
  bfx::EndianSwapLong(val: &this->m_imageSize);
  bfx::EndianSwapLong(val: &this->m_checksum);
}


// ========================================================================
// ?ComputeBigEndianChecksum@bfx@@YAIPBEH@Z
// EA  : 0x8326C228
// RVA : 0x0126C228
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

unsigned int __fastcall bfx::ComputeBigEndianChecksum(const unsigned __int8 *pCharBuf, int numBytes)
{
  const unsigned __int8 *v2; // r6
  const unsigned __int8 *v3; // r11
  unsigned int result; // r3
  const unsigned __int8 *v5; // r5
  bool v6; // zf
  int v7; // r10
  int v8; // r9
  int v9; // r8

  v2 = &pCharBuf[numBytes & 0xFFFFFFF0];
  v3 = pCharBuf;
  v5 = &pCharBuf[4 * (numBytes / 4)];
  v6 = pCharBuf >= v2;
  result = 0;
  if ( !v6 )
  {
    do
    {
      result += *((_DWORD *)v3 + 3) + *((_DWORD *)v3 + 2) + *((_DWORD *)v3 + 1) + *(_DWORD *)v3;
      v3 += 16;
    }
    while ( v3 < v2 );
  }
  v7 = 0;
  v8 = 0;
  if ( v3 < v5 )
  {
    if ( (v5 - v3 + 3) / 4 >= 2 )
    {
      do
      {
        v9 = *((_DWORD *)v3 + 1);
        v7 += *(_DWORD *)v3;
        v3 += 8;
        v8 += v9;
      }
      while ( (int)v3 < (int)(v5 - 4) );
    }
    if ( v3 < v5 )
      result += *(_DWORD *)v3;
    result += v8 + v7;
  }
  return result;
}


// ========================================================================
// ??0ResourceConstCursor@bfx@@QAA@PBD@Z
// EA  : 0x8326C2E0
// RVA : 0x0126C2E0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

bfx::ResourceConstCursor *__fastcall bfx::ResourceConstCursor::ResourceConstCursor(
        bfx::ResourceConstCursor *this,
        const char *pBinaryImage)
{
  char v4; // r10
  BOOL m_swapEndian; // r10
  unsigned int v6; // r11
  unsigned int v8[2]; // [sp+50h] [-20h] BYREF

  v4 = _cntlzw(*(_DWORD *)pBinaryImage);
  this->m_swapEndian = (v4 & 0x20) != 0;
  v8[0] = *((_DWORD *)pBinaryImage + 1);
  if ( (v4 & 0x20) != 0 )
    bfx::EndianSwapLong(val: v8);
  if ( v8[0] == 2 )
  {
    m_swapEndian = this->m_swapEndian;
    v8[0] = *((_DWORD *)pBinaryImage + 2);
    if ( m_swapEndian )
      bfx::EndianSwapLong(val: v8);
    v6 = v8[0];
    this->m_pCurResourceSection = pBinaryImage + 24;
  }
  else
  {
    v6 = 0;
    this->m_pCurResourceSection = nullptr;
  }
  this->m_bytesRemainingInSections = v6;
  return this;
}


// ========================================================================
// ??EResourceConstCursor@bfx@@QAAXXZ
// EA  : 0x8326C388
// RVA : 0x0126C388
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

void __fastcall bfx::ResourceConstCursor::operator++(bfx::ResourceConstCursor *this)
{
  BOOL m_swapEndian; // r10
  unsigned int v3; // r11
  unsigned int m_bytesRemainingInSections; // r10
  bool v5; // cr56
  unsigned int v6; // r11
  unsigned int v7[4]; // [sp+50h] [-20h] BYREF

  m_swapEndian = this->m_swapEndian;
  v7[0] = *((_DWORD *)this->m_pCurResourceSection + 1);
  if ( m_swapEndian )
    bfx::EndianSwapLong(val: v7);
  v3 = v7[0] + 12;
  m_bytesRemainingInSections = this->m_bytesRemainingInSections;
  v5 = m_bytesRemainingInSections < v7[0] + 12;
  this->m_pCurResourceSection += v7[0] + 12;
  v6 = m_bytesRemainingInSections - v3;
  if ( v5 )
    v6 = 0;
  this->m_bytesRemainingInSections = v6;
}


// ========================================================================
// ?GetResourceSize@bfx@@YAHPBD@Z
// EA  : 0x8326C408
// RVA : 0x0126C408
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

unsigned int __fastcall bfx::GetResourceSize(const char *pBinaryImage)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r4
  unsigned int v7; // r29
  int v8; // [sp+8h] [-98h]
  int v9; // [sp+Ch] [-94h]
  int v10; // [sp+10h] [-90h]
  int v11; // [sp+14h] [-8Ch]
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-50h]
  bfx::ResourceHeader v13; // [sp+60h] [-40h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::BinaryImageIn::GetResourceHeader(pBinaryImage, header: &v13);
  if ( v13.m_version == 2 )
  {
    v7 = v13.m_imageSize + 24;
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return v7;
  }
  else
  {
    HIDWORD(v5) = "ResourceHeader version is out of date. AddResource aborted.\n";
    bfx::InternalWarning(fmt: v5, a2: v4, a3: v3, a4: v2, a5: v8, a6: v9, a7: v10, a8: v11);
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return -1;
  }
}


// ========================================================================
// __unwind$72499
// EA  : 0x8326C49C
// RVA : 0x0126C49C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

void _unwind_72499()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 160 + 80));
}


// ========================================================================
// ?AddResourceSection@ResourceManager@bfx@@AAA_NPAVSpace@2@IAAVBinaryImageIn@2@ABVResourceOffset@2@@Z
// EA  : 0x8326C528
// RVA : 0x0126C528
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

BOOL __fastcall bfx::ResourceManager::AddResourceSection(
        bfx::ResourceManager *this,
        bfx::Space *pSpace,
        unsigned int id,
        bfx::BinaryImageIn *image,
        const bfx::ResourceOffset *offset)
{
  int v8; // r9
  int m_size; // r8
  bfx::ResourceManager::Registration *m_data; // r4
  int v11; // r11
  const char *ComponentName; // r30
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  __int64 v16; // r4
  int v18; // [sp+8h] [-68h]
  int v19; // [sp+Ch] [-64h]
  int v20; // [sp+10h] [-60h]
  int v21; // [sp+14h] [-5Ch]

  v8 = 0;
  m_size = this->m_registry.m_size;
  if ( m_size <= 0 )
  {
LABEL_5:
    ComponentName = bfx::ComponentManager::GetComponentName(componentID: (bfx::ComponentID)HIWORD(id));
    LODWORD(v13) = bfx::ComponentManager::IsComponentRegistered(
                     this: bfx::g_pCurInstance->m_pComponentManager,
                     id: (bfx::ComponentID)HIWORD(id));
    LODWORD(v16) = ComponentName;
    if ( (_DWORD)v13 != 0 )
    {
      HIDWORD(v15) = (unsigned __int16)id;
      HIDWORD(v16) = "AddResource(): component \"%s\" has no resource type 0x%04X registered!\n";
    }
    else
    {
      HIDWORD(v16) = "AddResource(): component \"%s\" has not been registered!\n";
    }
    bfx::InternalWarning(fmt: v16, a2: v15, a3: v14, a4: v13, a5: v18, a6: v19, a7: v20, a8: v21);
    return false;
  }
  else
  {
    m_data = this->m_registry.m_data;
    v11 = 0;
    while ( m_data[v11].m_id != id )
    {
      ++v8;
      ++v11;
      if ( v8 >= m_size )
        goto LABEL_5;
    }
    return m_data[v11].m_initCB(a1: pSpace, a2: id, a3: image, a4: offset);
  }
}


// ========================================================================
// ?IsResourceUpToDate@bfx@@YA_NPBD@Z
// EA  : 0x8326C618
// RVA : 0x0126C618
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

int __fastcall bfx::IsResourceUpToDate(const char *pBinaryImage)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r27
  unsigned int v4; // r3
  const char *m_pCurResourceSection; // r30
  BOOL m_swapEndian; // r28
  int v7; // r6
  signed int v8; // r8
  bfx::ResourceManager *m_pResourceManager; // r11
  bfx::ResourceManager::Registration *m_data; // r7
  int v11; // r11
  bool v12; // r3
  int m_size; // [sp+50h] [-70h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-6Ch]
  bfx::ResourceConstCursor v15[2]; // [sp+58h] [-68h] BYREF
  bfx::ResourceHeader v16; // [sp+70h] [-50h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::BinaryImageIn::GetResourceHeader(pBinaryImage, header: &v16);
  if ( v16.m_version != 2 )
  {
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return 0;
  }
  v4 = bfx::ComputeBigEndianChecksum(pCharBuf: (const unsigned __int8 *)pBinaryImage + 24, numBytes: v16.m_imageSize);
  if ( v4 != v16.m_checksum )
  {
    if ( m_pGlobalCS == nullptr )
      return 0;
    goto LABEL_25;
  }
  bfx::ResourceConstCursor::ResourceConstCursor(this: v15, pBinaryImage);
  if ( v15[0].m_bytesRemainingInSections != 0 )
  {
    while ( 1 )
    {
      m_pCurResourceSection = v15[0].m_pCurResourceSection;
      m_swapEndian = v15[0].m_swapEndian;
      v7 = *(_DWORD *)v15[0].m_pCurResourceSection;
      m_size = *(_DWORD *)v15[0].m_pCurResourceSection;
      if ( v15[0].m_swapEndian )
      {
        bfx::EndianSwapLong(val: (unsigned int *)&m_size);
        v7 = m_size;
      }
      v8 = 0;
      m_pResourceManager = bfx::g_pCurInstance->m_pResourceManager;
      m_size = m_pResourceManager->m_registry.m_size;
      if ( m_size <= 0 )
      {
LABEL_17:
        v12 = false;
      }
      else
      {
        m_data = m_pResourceManager->m_registry.m_data;
        v11 = 0;
        while ( m_data[v11].m_id != v7 )
        {
          ++v8;
          ++v11;
          if ( v8 >= m_size )
            goto LABEL_17;
        }
        v12 = m_data[v11].m_isUpToDateCB(a1: m_swapEndian, a2: m_pCurResourceSection + 12);
      }
      if ( !v12 )
        break;
      bfx::ResourceConstCursor::operator++(this: v15);
      if ( v15[0].m_bytesRemainingInSections == 0 )
        goto LABEL_20;
    }
    if ( p_m_criticalSection == nullptr )
      return 0;
LABEL_25:
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return 0;
  }
LABEL_20:
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return 1;
}


// ========================================================================
// __unwind$72880
// EA  : 0x8326C79C
// RVA : 0x0126C79C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

void _unwind_72880()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 192 + 84));
}


// ========================================================================
// ?RegisterResourceType@ResourceManager@bfx@@QAA_NIP6A_NPAVSpace@2@IAAVBinaryImageIn@2@ABVResourceOffset@2@@ZP6AX0I1@ZP6A_N_NPBD@Z@Z
// EA  : 0x8326C880
// RVA : 0x0126C880
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

int __fastcall bfx::ResourceManager::RegisterResourceType(
        bfx::ResourceManager *this,
        unsigned int id,
        bool (__fastcall *initCB)(bfx::Space *, unsigned int, bfx::BinaryImageIn *, const bfx::ResourceOffset *),
        void (__fastcall *termCB)(bfx::Space *, unsigned int, bfx::BinaryImageIn *),
        bool (__fastcall *isUpToDateCB)(bool, const char *))
{
  bfx::ResourceManager::Registration v11; // [sp+50h] [-40h] BYREF

  if ( bfx::ResourceManager::IsResourceTypeRegistered(this, id) )
    return 0;
  v11.m_id = id;
  v11.m_initCB = initCB;
  v11.m_termCB = termCB;
  v11.m_isUpToDateCB = isUpToDateCB;
  bfx::Array<bfx::Plane>::push_back(this: &this->m_registry, val: &v11);
  return 1;
}


// ========================================================================
// ?DeleteResourceUsingBinaryImage@ResourceManager@bfx@@AAAXPAD@Z
// EA  : 0x8326C8E8
// RVA : 0x0126C8E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

void __fastcall bfx::ResourceManager::DeleteResourceUsingBinaryImage(bfx::ResourceManager *this, char *pBinaryImage)
{
  bfx::Array<bfx::ResourceImpl *> *p_m_resources; // r31
  int v3; // r30
  int i; // r11
  bfx::ResourceImpl *v5; // r3
  unsigned int v6; // r3
  unsigned int v7; // r11

  p_m_resources = &this->m_resources;
  v3 = 0;
  if ( this->m_resources.m_size > 0 )
  {
    for ( i = 0; ; ++i )
    {
      v5 = p_m_resources->m_data[i];
      if ( v5->m_pBinaryImage == pBinaryImage )
        break;
      if ( ++v3 >= p_m_resources->m_size )
        return;
    }
    ((void (__fastcall *)(bfx::ResourceImpl *, int))v5->dtr_HandleTargetBase)(a1: v5, a2: 1);
    v6 = (unsigned int)&p_m_resources->m_data[v3];
    v7 = (unsigned int)&p_m_resources->m_data[p_m_resources->m_size - 1];
    if ( v6 < v7 )
      blkmov(a1: v6, a2: v6 + 4, a3: 4 * (((v7 - v6 - 1) >> 2) + 1));
    --p_m_resources->m_size;
  }
}


// ========================================================================
// ?AddResourceImage@ResourceManager@bfx@@QAAPAVResourceImpl@2@PAVSpace@2@PADABVResourceOffset@2@@Z
// EA  : 0x8326C9C8
// RVA : 0x0126C9C8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
bfx::Space *__fastcall bfx::ResourceManager::AddResourceImage(
        bfx::ResourceManager *this,
        bfx::Space *pSpace,
        __int64 offset,
        __int64 a4,
        __int64 a5)
{
  int v5; // r3
  int v6; // r26
  unsigned int v8; // r27
  const bfx::ResourceOffset *v9; // r24
  const char *v10; // r3
  int v11; // r3
  int v12; // r3
  int v13; // r11
  char v14; // r11
  const char *v15; // r3
  unsigned int v16; // r30
  const char *v17; // r3
  const char *v18; // r3
  const char *v19; // r3
  unsigned int v20; // r3
  const char *v21; // r3
  __int64 v22; // r10
  __int64 v23; // r8
  __int64 v24; // r6
  const bfx::ResourceSectionHeader *v25; // r3
  __int64 v26; // r4
  bfx::Space *v27; // r3
  bfx::Space *v28; // r30
  const char *v30; // r3
  int v31; // [sp+8h] [-E8h]
  int v32; // [sp+Ch] [-E4h]
  int v33; // [sp+10h] [-E0h]
  int v34; // [sp+14h] [-DCh]
  unsigned int v35; // [sp+50h] [-A0h] BYREF
  bfx::Space *v36; // [sp+54h] [-9Ch] BYREF
  bfx::ResourceHeader v37; // [sp+60h] [-90h] BYREF
  bfx::BinaryImageIn v38[3]; // [sp+80h] [-70h] BYREF

  v6 = v5;
  v8 = HIDWORD(offset);
  v9 = (const bfx::ResourceOffset *)offset;
  if ( (offset & 0x300000000LL) != 0 )
  {
    v10 = "Binary image must have at least four byte alignment. AddResource aborted.\n";
LABEL_32:
    bfx::InternalWarning(fmt: *(__int64 *)&pSpace, a2: offset, a3: a4, a4: a5, a5: v31, a6: v32, a7: v33, a8: v34);
    return nullptr;
  }
  LODWORD(a5) = 0;
  v36 = *(bfx::Space **)(v11 + 20);
  HIDWORD(a5) = v36;
  if ( (int)v36 <= 0 )
  {
LABEL_7:
    v14 = 0;
  }
  else
  {
    LODWORD(a4) = *(_DWORD *)(v12 + 16);
    v13 = 0;
    while ( 1 )
    {
      HIDWORD(a4) = *(_DWORD *)(v13 + a4);
      LODWORD(offset) = *(_DWORD *)(HIDWORD(a4) + 8);
      if ( (_DWORD)offset == HIDWORD(offset) )
        break;
      LODWORD(a5) = a5 + 1;
      v13 += 4;
      if ( (int)a5 >= (int)v36 )
        goto LABEL_7;
    }
    v14 = 1;
  }
  if ( v14 != 0 )
  {
    v15 = "AddResource() was called on a resource which was already in use. AddResource aborted.\n";
    goto LABEL_32;
  }
  v35 = *(_DWORD *)HIDWORD(offset);
  v16 = v35;
  bfx::EndianSwapLong(val: &v35);
  if ( v16 == -1160008262 || (LODWORD(a5) = v35, v35 == -1160008262) )
  {
    v30 = "AddResource called with NavGraphImage instead of NavGraphImage->GetPtr(). AddResource aborted.\n";
    goto LABEL_32;
  }
  bfx::BinaryImageIn::GetResourceHeader(pBinaryImage: (const char *)v8, header: &v37);
  if ( v37.m_version != 2 )
  {
    if ( v37.m_version <= 0xFF )
      v18 = "ResourceHeader version is out of date. AddResource aborted.\n";
    else
      v17 = "The binary image header is corrupted. AddResource aborted.\n";
    goto LABEL_32;
  }
  LODWORD(a5) = v37.m_runtimeFlags & 1;
  if ( (v37.m_runtimeFlags & 1) != 0 )
  {
    v19 = "This resource has been used previously and cannot be added again. AddResource aborted.\n";
    goto LABEL_32;
  }
  v20 = bfx::ComputeBigEndianChecksum(pCharBuf: (const unsigned __int8 *)(v8 + 24), numBytes: v37.m_imageSize);
  if ( v20 != v37.m_checksum )
  {
    v21 = "Checksum error. AddResource aborted.\n";
    goto LABEL_32;
  }
  *(_DWORD *)(v8 + 16) |= 1u;
  bfx::BinaryImageIn::BinaryImageIn(this: v38, pBinaryImage: (char *)v8, bEndianFixed: false);
  while ( v38[0].m_pRead < &v38[0].m_pImage[v38[0].m_imageSize] )
  {
    v25 = bfx::BinaryImageIn::PushSection(this: v38);
    if ( v25->m_pointerSize != 0 )
    {
      HIDWORD(v24) = "32";
      LODWORD(v26) = "64";
      HIDWORD(v26) = "Resource created using %s bit pointers is being loaded on a %s bit pointer machine. AddResource aborted.\n";
      bfx::InternalWarning(fmt: v26, a2: v24, a3: v23, a4: v22, a5: v31, a6: v32, a7: v33, a8: v34);
    }
    else if ( v25->m_size != 0 )
    {
      bfx::ResourceManager::AddResourceSection(
        this: (bfx::ResourceManager *)v6,
        pSpace,
        id: v25->m_id,
        image: v38,
        offset: v9);
    }
    bfx::BinaryImageIn::PopSection(this: v38);
  }
  v27 = (bfx::Space *)bfx::MemoryManager::Malloc(
                        this: bfx::g_pCurInstance->m_pMemoryManager,
                        size: 0xCu,
                        tag: bfx::MEM_BFXSYSTEM);
  if ( v27 != nullptr )
  {
    v27->m_spaceID = v8;
    v27->m_pProxy = nullptr;
    v28 = v27;
    v27->__vftable = (bfx::Space_vtbl *)&bfx::ResourceImpl::`vftable';
  }
  else
  {
    v28 = nullptr;
  }
  v36 = v28;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)(v6 + 16), val: &v36);
  bfx::BinaryImageIn::~BinaryImageIn(this: v38);
  return v28;
}


// ========================================================================
// __unwind$73674
// EA  : 0x8326CC40
// RVA : 0x0126CC40
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

void _unwind_73674()
{
  int v0; // r12

  bfx::BinaryImageIn::~BinaryImageIn(this: (bfx::BinaryImageIn *)(v0 - 240 + 128));
}


// ========================================================================
// ?RemoveResourceImage@ResourceManager@bfx@@QAAXPAVSpace@2@PAD@Z
// EA  : 0x8326CC70
// RVA : 0x0126CC70
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

void __fastcall bfx::ResourceManager::RemoveResourceImage(
        bfx::ResourceManager *this,
        bfx::Space *pSpace,
        char *pBinaryImage)
{
  int v6; // r10
  int v7; // r11
  char v8; // r11
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  const bfx::ResourceSectionHeader *v12; // r3
  int v13; // r9
  bfx::ResourceManager::Registration *m_data; // r7
  int v15; // r11
  __int64 v16; // r4
  int v17; // [sp+8h] [-B8h]
  int v18; // [sp+Ch] [-B4h]
  int v19; // [sp+10h] [-B0h]
  int v20; // [sp+14h] [-ACh]
  int m_size; // [sp+50h] [-70h]
  int v22; // [sp+50h] [-70h]
  bfx::BinaryImageIn v23[3]; // [sp+60h] [-60h] BYREF

  v6 = 0;
  m_size = this->m_resources.m_size;
  if ( m_size <= 0 )
  {
LABEL_5:
    v8 = 0;
  }
  else
  {
    v7 = 0;
    while ( this->m_resources.m_data[v7]->m_pBinaryImage != pBinaryImage )
    {
      ++v6;
      ++v7;
      if ( v6 >= m_size )
        goto LABEL_5;
    }
    v8 = 1;
  }
  if ( v8 != 0 )
  {
    bfx::BinaryImageIn::BinaryImageIn(this: v23, pBinaryImage, bEndianFixed: true);
    while ( v23[0].m_pRead < &v23[0].m_pImage[v23[0].m_imageSize] )
    {
      v12 = bfx::BinaryImageIn::PushSection(this: v23);
      if ( v12->m_pointerSize != 0 )
      {
        HIDWORD(v11) = "32";
        LODWORD(v16) = "64";
        HIDWORD(v16) = "Resource created using %s bit pointers is being used on a %s bit pointer machine. RemoveResource aborted.\n";
        bfx::InternalWarning(fmt: v16, a2: v11, a3: v10, a4: v9, a5: v17, a6: v18, a7: v19, a8: v20);
      }
      else if ( v12->m_size != 0 )
      {
        v13 = 0;
        v22 = this->m_registry.m_size;
        if ( v22 > 0 )
        {
          m_data = this->m_registry.m_data;
          v15 = 0;
          while ( m_data[v15].m_id != v12->m_id )
          {
            ++v13;
            ++v15;
            if ( v13 >= v22 )
              goto LABEL_18;
          }
          ((void (__fastcall *)(bfx::Space *))m_data[v15].m_termCB)(a1: pSpace);
        }
      }
LABEL_18:
      bfx::BinaryImageIn::PopSection(this: v23);
    }
    bfx::ResourceManager::DeleteResourceUsingBinaryImage(this, pBinaryImage);
    v23[0].m_sectionStack.m_size = 0;
    if ( v23[0].m_sectionStack.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v23[0].m_sectionStack.m_data);
  }
}


// ========================================================================
// __unwind$73775
// EA  : 0x8326CE04
// RVA : 0x0126CE04
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

void _unwind_73775()
{
  int v0; // r12

  bfx::BinaryImageIn::~BinaryImageIn(this: (bfx::BinaryImageIn *)(v0 - 192 + 96));
}


// ========================================================================
// ?AddResourceInternal@bfx@@YAPAVResourceImpl@1@AAVSpaceHandle@1@PADABVResourceOffset@1@@Z
// EA  : 0x8326CE38
// RVA : 0x0126CE38
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

bfx::Space *__fastcall bfx::AddResourceInternal(
        bfx::SpaceHandle *spaceHandle,
        char *pBinaryImage,
        const bfx::ResourceOffset *offset)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r26
  __int64 v7; // r10
  __int64 v8; // r8
  bfx::Space *Volume; // r4
  bfx::Space *v10; // r30
  bfx::FTimerOb v12; // [sp+50h] [-40h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-3Ch]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v12, timerEntry: &bfx::addResourceTimer);
  bfx::LogAddResource(spaceHandle, pBinaryImage, offset);
  Volume = bfx::GetVolume(spaceHandle);
  if ( Volume != nullptr )
  {
    v10 = bfx::ResourceManager::AddResourceImage(
            this: bfx::g_pCurInstance->m_pResourceManager,
            pSpace: Volume,
            offset: __SPAIR64__((unsigned int)pBinaryImage, (unsigned int)offset),
            a4: v8,
            a5: v7);
    if ( v12.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v12.m_pFTimer);
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return v10;
  }
  else
  {
    if ( v12.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v12.m_pFTimer);
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return nullptr;
  }
}


// ========================================================================
// __unwind$73936
// EA  : 0x8326CF14
// RVA : 0x0126CF14
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

void _unwind_73936()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 144 + 84));
}


// ========================================================================
// __unwind$73937
// EA  : 0x8326CF3C
// RVA : 0x0126CF3C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

void _unwind_73937()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 144 + 80));
}


// ========================================================================
// ?AddResource@bfx@@YAXAAVSpaceHandle@1@PADABVResourceOffset@1@@Z
// EA  : 0x8326CF68
// RVA : 0x0126CF68
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

// attributes: thunk
void __fastcall bfx::AddResource(bfx::SpaceHandle *spaceHandle, char *pBinaryImage, const bfx::ResourceOffset *offset)
{
  bfx::AddResourceInternal(spaceHandle, pBinaryImage, offset);
}


// ========================================================================
// ?RemoveResource@bfx@@YAXAAVSpaceHandle@1@PAD@Z
// EA  : 0x8326CF78
// RVA : 0x0126CF78
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

void __fastcall bfx::RemoveResource(bfx::SpaceHandle *spaceHandle, char *pBinaryImage)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r27
  bfx::Space *Volume; // r4
  bfx::FTimerOb v6; // [sp+50h] [-40h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-3Ch]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v6, timerEntry: &bfx::addResourceTimer);
  bfx::LogRemoveResource(spaceHandle, pBinaryImage);
  Volume = bfx::GetVolume(spaceHandle);
  if ( Volume != nullptr )
    bfx::ResourceManager::RemoveResourceImage(
      this: bfx::g_pCurInstance->m_pResourceManager,
      pSpace: Volume,
      pBinaryImage);
  if ( v6.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v6.m_pFTimer);
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
}


// ========================================================================
// __unwind$74022
// EA  : 0x8326D018
// RVA : 0x0126D018
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

void _unwind_74022()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 144 + 84));
}


// ========================================================================
// __unwind$74023
// EA  : 0x8326D040
// RVA : 0x0126D040
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

void _unwind_74023()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 144 + 80));
}


// ========================================================================
// bfx::`dynamic initializer for 'addResourceTimer''
// EA  : 0x83398700
// RVA : 0x01398700
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__addResourceTimer__()
{
  int v0; // r9

  v0 = bfx::g_nextFTimerEntryID;
  bfx::addResourceTimer.m_pNext = bfx::g_pFTimerEntryHead;
  bfx::addResourceTimer.m_timerID = bfx::g_nextFTimerEntryID;
  if ( bfx::g_pFTimerEntryHead != nullptr )
  {
    bfx::g_pFTimerEntryHead->m_pPrev = &bfx::addResourceTimer;
    v0 = bfx::g_nextFTimerEntryID;
  }
  bfx::g_pFTimerEntryHead = &bfx::addResourceTimer;
  bfx::g_nextFTimerEntryID = v0 + 1;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__addResourceTimer__);
}

