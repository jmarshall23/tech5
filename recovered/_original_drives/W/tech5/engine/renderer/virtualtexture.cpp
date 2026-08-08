
// ========================================================================
// ?GetPhysicalPagesPool@idVirtualTexture@@QBA?AW4physicalPagesPool_t@@XZ
// EA  : 0x82978218
// RVA : 0x00978218
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

physicalPagesPool_t __fastcall idVirtualTexture::GetPhysicalPagesPool(idVirtualTexture *this)
{
  return this->physicalPages->physicalPagesPool;
}


// ========================================================================
// ?GetToBeLockedPhysicalPages@idVirtualTexture@@QAAXHPAUpageIndices_t@@@Z
// EA  : 0x82978228
// RVA : 0x00978228
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void __fastcall idVirtualTexture::GetToBeLockedPhysicalPages(
        idVirtualTexture *this,
        int numTexturePages,
        __int64 pageIndices)
{
  unsigned int v3; // r7
  __int64 v4; // r10
  unsigned int i; // r8
  unsigned int v6; // r11
  __int64 v7; // r31
  int v8; // r10
  __int64 v9; // r6

  v3 = 1;
  for ( HIDWORD(v4) = this->header.numLevels - 1; numTexturePages > 0; v3 *= 2 )
  {
    for ( i = 0; i < v3; ++i )
    {
      if ( numTexturePages <= 0 )
        break;
      v6 = 0;
      do
      {
        if ( numTexturePages <= 0 )
          break;
        --numTexturePages;
        LODWORD(v7) = (16 * (this->pageSource | (HIDWORD(v4) << 20))) | 0x100 | HIDWORD(v4);
        HIDWORD(v7) = i;
        v7 <<= 11;
        v8 = 8 * (*(_DWORD *)(HIDWORD(pageIndices) + 4) + 5);
        LODWORD(pageIndices) = v7 | v6++;
        v9 = pageIndices << 11;
        LODWORD(v9) = v9 | HIDWORD(v7);
        pageIndices = 4 * v9;
        *(_QWORD *)(v8 + HIDWORD(pageIndices)) = pageIndices;
        v4 = *(_QWORD *)HIDWORD(pageIndices);
        LODWORD(v4) = *(_DWORD *)(HIDWORD(pageIndices) + 4) + 1;
        *(_QWORD *)HIDWORD(pageIndices) = v4;
      }
      while ( v6 < v3 );
    }
    if ( HIDWORD(v4) == 0 )
      break;
    --HIDWORD(v4);
  }
}


// ========================================================================
// ?EmptyCache@idVirtualTexture@@QAAXXZ
// EA  : 0x82978300
// RVA : 0x00978300
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void __fastcall idVirtualTexture::EmptyCache(idVirtualTexture *this)
{
  idPhysicalPages::FreePageTree_r(
    this: this->physicalPages,
    vt: this,
    page: this->rootTexturePage,
    deferredUnmap: nullptr);
}


// ========================================================================
// ?PageCompressionForString@@YA?AW4pageCompression_t@@PBD@Z
// EA  : 0x82978318
// RVA : 0x00978318
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

pageCompression_t __fastcall PageCompressionForString(const char *str)
{
  int v2; // r31
  const char **v3; // r11
  int v4; // r29

  v2 = 0;
  if ( compressionStrings[0] == nullptr )
    return COMP_DCT;
  v3 = compressionStrings;
  v4 = 0;
  while ( idStr::Icmp(s1: str, s2: *v3) != 0 )
  {
    v4 = ++v2;
    v3 = &compressionStrings[v2];
    if ( *v3 == nullptr )
      return COMP_DCT;
  }
  return compressionForString[v4];
}


// ========================================================================
// ??0idVirtualTexture@@QAA@XZ
// EA  : 0x829783A0
// RVA : 0x009783A0
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

idVirtualTexture *__fastcall idVirtualTexture::idVirtualTexture(idVirtualTexture *this)
{
  __int64 v1; // r29
  idVirtualTexture *v3; // r10
  __int64 v4; // r9
  int i; // ctr
  idImage **p_pageTableImage; // r11
  int j; // ctr

  this->__vftable = (idVirtualTexture_vtbl *)&idVirtualTexture::`vftable';
  LODWORD(v1) = 0;
  this->pageFilePath.allocedAndFlag = 20;
  this->pageFilePath.baseBuffer[0] = 0;
  this->pageFilePath.buffer[0] = 0;
  this->pageFilePath.len = 0;
  this->pageFilePath.data = this->pageFilePath.buffer;
  this->pageFilePath.allocedAndFlag = -2147483392;
  this->baseName.allocedAndFlag = 20;
  this->baseName.baseBuffer[0] = 0;
  this->baseName.buffer[0] = 0;
  this->baseName.len = 0;
  this->baseName.data = this->baseName.buffer;
  this->baseName.allocedAndFlag = -2147483392;
  this->pageSource = PAGESOURCE_INVALID;
  this->layoutVersion = 0;
  this->pageFile = nullptr;
  this->pageFileInstalled = nullptr;
  this->VIRTUAL_PAGES_WIDE_LOG2 = 0;
  this->VIRTUAL_TEXELS_WIDE = 0;
  this->VIRTUAL_MAPPING_PAGES_WIDE = 0;
  this->minMipLevelInstalled = 16;
  this->mapName.allocedAndFlag = 20;
  this->mapName.baseBuffer[0] = 0;
  this->mapName.buffer[0] = 0;
  this->mapName.len = 0;
  this->mapName.data = this->mapName.buffer;
  this->mapName.allocedAndFlag = -2147483520;
  this->dirtyPages.merges = 0;
  this->dirtyPages.layoutVersion = 0;
  this->dirtyPages.width = 0;
  this->dirtyPages.coarsestLevel = 0;
  this->dirtyPages.bitArraySize = v1;
  this->dirtyPages.bits = nullptr;
  memset(Dst: this->dirtyPages.levelOffset, Val: 0, Size: sizeof(this->dirtyPages.levelOffset));
  this->physicalPages = nullptr;
  this->rootTexturePage = nullptr;
  this->pageTableImage = nullptr;
  this->enlargedPageTableAllocationFailed = false;
  this->isDirectMapped = false;
  Sys_MutexCreate(handle: &this->headerMutex.handle);
  this->skipFlush = false;
  v3 = this;
  LODWORD(v4) = 0;
  for ( i = 9; i != 0; --i )
  {
    v3 = (idVirtualTexture *)((char *)v3 + 8);
    *(_QWORD *)&v3->__vftable = v4;
  }
  p_pageTableImage = &this->pageTableImage;
  for ( j = 6; j != 0; --j )
  {
    p_pageTableImage += 2;
    *(_QWORD *)p_pageTableImage = v1;
  }
  return this;
}


// ========================================================================
// __unwind$232224
// EA  : 0x829784E4
// RVA : 0x009784E4
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void _unwind_232224()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 80));
}


// ========================================================================
// __unwind$232225
// EA  : 0x82978510
// RVA : 0x00978510
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void _unwind_232225()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 368));
}


// ========================================================================
// __unwind$232226
// EA  : 0x8297853C
// RVA : 0x0097853C
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void _unwind_232226()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 720));
}


// ========================================================================
// __unwind$232227
// EA  : 0x82978568
// RVA : 0x00978568
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void _unwind_232227()
{
  int v0; // r12

  idSeenBits::~idSeenBits(this: (idSeenBits *)(*(_DWORD *)(v0 - 112 + 132) + 880));
}


// ========================================================================
// ?GetFeedbackVec4@idVirtualTexture@@QBA?AVidVec4@@XZ
// EA  : 0x82978598
// RVA : 0x00978598
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idVec4 *__fastcall idVirtualTexture::GetFeedbackVec4(idVirtualTexture *this, idVec4 *result, __int64 a3)
{
  __int64 v3; // r8
  int v4; // r5
  double v5; // fp11
  __int64 v6; // r4
  idVec4 *v7; // r3

  *(float *)&v3 = result[41].x;
  LODWORD(v3) = LODWORD(result->w);
  LODWORD(a3) = HIDWORD(v3);
  v5 = (double)a3;
  v4 = *(_DWORD *)(LODWORD(result[73].x) + 92);
  *(float *)(HIDWORD(v6) + 12) = 0.0;
  LODWORD(v6) = v4;
  *(float *)(HIDWORD(v6) + 4) = (float)v3;
  *(float *)HIDWORD(v6) = v5;
  *(float *)(HIDWORD(v6) + 8) = (float)v6;
  return v7;
}


// ========================================================================
// ?Print@idVirtualTexture@@QBAXXZ
// EA  : 0x82978600
// RVA : 0x00978600
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void __fastcall idVirtualTexture::Print(idVirtualTexture *this)
{
  int v2; // r30
  bool *p_enlargedPageTableAllocationFailed; // r29
  int NumResidentPagesForSource; // r3
  int NumLockedPagesForSource; // r3

  if ( this->pageTableImage != nullptr && this->pageFile != nullptr )
  {
    this->pageTableImage->Print(this: this->pageTableImage);
    idLib::Printf(fmt: "Page file: %s\n", this->pageFilePath.data);
    idLib::Printf(fmt: "header.magic: 0x%x\n", this->header.magic);
    idLib::Printf(fmt: "header.pagesWide: %4i\n", this->header.pagesWide);
    idLib::Printf(fmt: "header.numLevels: %4i\n", this->header.numLevels);
    idLib::Printf(fmt: "header.layoutVersion: %4i\n", this->header.layoutVersion);
    idLib::Printf(fmt: "header.diskOffsetScale: %4i\n", this->header.diskOffsetScale);
    idLib::Printf(fmt: "Pages resident per level: ");
    v2 = 0;
    if ( this->VIRTUAL_PAGES_WIDE_LOG2 + 1 > 0 )
    {
      p_enlargedPageTableAllocationFailed = &this->enlargedPageTableAllocationFailed;
      do
      {
        p_enlargedPageTableAllocationFailed += 4;
        idLib::Printf(fmt: "%3d ", *(_DWORD *)p_enlargedPageTableAllocationFailed);
        ++v2;
      }
      while ( v2 < this->VIRTUAL_PAGES_WIDE_LOG2 + 1 );
    }
    idLib::Printf(fmt: "\n");
    NumResidentPagesForSource = idPhysicalPages::GetNumResidentPagesForSource(
                                  this: this->physicalPages,
                                  src: this->pageSource);
    idLib::Printf(fmt: "Pages resident: %i\n", NumResidentPagesForSource);
    NumLockedPagesForSource = idPhysicalPages::GetNumLockedPagesForSource(
                                this: this->physicalPages,
                                src: this->pageSource);
    idLib::Printf(fmt: "Pages locked: %i\n", NumLockedPagesForSource);
  }
  else
  {
    idLib::Printf(fmt: "No source set.\n");
  }
}


// ========================================================================
// ?GetNewDiskPageCompression@idVirtualTexture@@QBA?AW4pageCompression_t@@XZ
// EA  : 0x82978750
// RVA : 0x00978750
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

pageCompression_t __fastcall idVirtualTexture::GetNewDiskPageCompression(idVirtualTexture *this)
{
  pageCompression_t result; // r3
  idCVar *v3; // r10

  result = this->forcedPageCompression;
  if ( result == 0 )
  {
    if ( strstr(str1: this->pageFilePath.data, str2: "_U.") != nullptr )
      return COMP_NONE;
    if ( this->pageSource == PAGESOURCE_VMTR )
    {
      if ( vt_uncompressedVmtr.valueInteger != 0 )
        return COMP_NONE;
      v3 = &vt_vmtrCompression;
    }
    else
    {
      v3 = &mt_genCompression;
    }
    return PageCompressionForString(str: v3->valueString.data);
  }
  return result;
}


// ========================================================================
// ?FreeData@idVirtualTexture@@UAAXXZ
// EA  : 0x829787F0
// RVA : 0x009787F0
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void __fastcall idVirtualTexture::FreeData(idVirtualTexture *this)
{
  __int64 v2; // r30
  idImage *pageTableImage; // r3
  unsigned __int8 *bits; // r11
  idVirtualTexture *v5; // r11
  int i; // ctr
  char *data; // r4
  size_t v8; // r5
  char *v9; // r3
  char *v10; // r4
  size_t v11; // r5
  char *v12; // r3
  idStrStatic<256> v13; // [sp+50h] [-260h] BYREF
  idStrStatic<256> v14; // [sp+170h] [-140h] BYREF

  LODWORD(v2) = 0;
  HIDWORD(v2) = &virtualTextureSystem;
  if ( this->pageSource != PAGESOURCE_INVALID )
  {
    idPhysicalPages::FreePageTree_r(
      this: this->physicalPages,
      vt: this,
      page: this->rootTexturePage,
      deferredUnmap: nullptr);
    virtualTextureSystem.vtPtrs[this->pageSource] = nullptr;
  }
  if ( this->pageFile != nullptr )
  {
    idStreamFileCache::Flush(this: streamFileCache);
    idVirtualTextureSystem::CloseCachedPagesFile(this: &virtualTextureSystem, file: this->pageFile);
    this->pageFile = nullptr;
  }
  if ( this->pageFileInstalled != nullptr )
    this->pageFileInstalled = nullptr;
  pageTableImage = this->pageTableImage;
  this->physicalPages = nullptr;
  this->rootTexturePage = nullptr;
  if ( pageTableImage != nullptr )
  {
    idImage::PurgeImage(this: pageTableImage);
    this->pageTableImage = nullptr;
  }
  bits = this->dirtyPages.bits;
  this->enlargedPageTableAllocationFailed = false;
  this->isDirectMapped = false;
  if ( bits != nullptr )
    idSeenBits::~idSeenBits(this: &this->dirtyPages);
  this->skipFlush = false;
  this->pageFileIsLocal = false;
  v5 = this;
  this->layoutVersion = 0;
  for ( i = 9; i != 0; --i )
  {
    v5 = (idVirtualTexture *)((char *)v5 + 8);
    *(_QWORD *)&v5->__vftable = v2;
  }
  idStrStatic<256>::idStrStatic<256>(this: &v13, text: &byte_8200D768);
  data = v13.data;
  v8 = v13.len + 1;
  v9 = this->pageFilePath.data;
  this->pageFilePath.len = v13.len;
  memcpy(Dst: v9, Src: data, Size: v8);
  idStr::FreeData(this: &v13);
  idStrStatic<256>::idStrStatic<256>(this: &v14, text: &byte_8200D768);
  v10 = v14.data;
  v11 = v14.len + 1;
  v12 = this->baseName.data;
  this->baseName.len = v14.len;
  memcpy(Dst: v12, Src: v10, Size: v11);
  idStr::FreeData(this: &v14);
}


// ========================================================================
// ?ReleaseSource@idVirtualTexture@@QAAXXZ
// EA  : 0x82978938
// RVA : 0x00978938
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void __fastcall idVirtualTexture::ReleaseSource(idVirtualTexture *this)
{
  char *data; // r4
  size_t v3; // r5
  char *v4; // r3
  char *v5; // r4
  size_t v6; // r5
  char *v7; // r3
  __int64 v8; // r9
  idVirtualTexture *v9; // r11
  int i; // ctr
  idStrStatic<256> v11; // [sp+50h] [-260h] BYREF
  idStrStatic<256> v12; // [sp+170h] [-140h] BYREF

  if ( this->pageTableImage != nullptr )
  {
    idVirtualTextureSystem::SyncFeedback(this: &virtualTextureSystem);
    this->FreeData(this);
    idStrStatic<256>::idStrStatic<256>(this: &v11, text: &byte_8200D768);
    data = v11.data;
    v3 = v11.len + 1;
    v4 = this->baseName.data;
    this->baseName.len = v11.len;
    memcpy(Dst: v4, Src: data, Size: v3);
    idStr::FreeData(this: &v11);
    idStrStatic<256>::idStrStatic<256>(this: &v12, text: &byte_8200D768);
    v5 = v12.data;
    v6 = v12.len + 1;
    v7 = this->pageFilePath.data;
    this->pageFilePath.len = v12.len;
    memcpy(Dst: v7, Src: v5, Size: v6);
    idStr::FreeData(this: &v12);
    LODWORD(v8) = 0;
    v9 = this;
    for ( i = 9; i != 0; --i )
    {
      v9 = (idVirtualTexture *)((char *)v9 + 8);
      *(_QWORD *)&v9->__vftable = v8;
    }
    this->VIRTUAL_PAGES_WIDE_LOG2 = 0;
    this->VIRTUAL_TEXELS_WIDE = 0;
    this->VIRTUAL_MAPPING_PAGES_WIDE = 0;
  }
}


// ========================================================================
// ?ValidatePageTable@idVirtualTexture@@QAA_NXZ
// EA  : 0x82978A18
// RVA : 0x00978A18
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

int __fastcall idVirtualTexture::ValidatePageTable(idVirtualTexture *this)
{
  int v2; // r30
  int numLevels; // r27
  idImageData *ImageData; // r31
  unsigned __int8 *data; // r4
  float *floatData; // r4
  unsigned __int8 *v8; // r4
  float *v9; // r4

  v2 = 0;
  numLevels = this->pageTableImage->opts.numLevels;
  if ( numLevels <= 0 )
    return 1;
  while ( 1 )
  {
    ImageData = idImage::GetImageData(this: this->pageTableImage, mipLevel: v2, z: 0);
    if ( (unsigned __int8)XGComparePixelShaders() == 0 )
      break;
    if ( ImageData != nullptr )
    {
      data = ImageData->data;
      if ( data != nullptr )
        idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
      floatData = ImageData->floatData;
      if ( floatData != nullptr )
        idMem::Free(this: &mem, ptr: floatData, align: ALIGN_16);
      idMem::Free(this: &mem, ptr: ImageData, align: ALIGN_16);
    }
    if ( ++v2 >= numLevels )
      return 1;
  }
  if ( ImageData != nullptr )
  {
    v8 = ImageData->data;
    if ( v8 != nullptr )
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    v9 = ImageData->floatData;
    if ( v9 != nullptr )
      idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
    idMem::Free(this: &mem, ptr: ImageData, align: ALIGN_16);
  }
  return 0;
}


// ========================================================================
// ??1idVirtualTexture@@UAA@XZ
// EA  : 0x82978E70
// RVA : 0x00978E70
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void __fastcall idVirtualTexture::~idVirtualTexture(idVirtualTexture *this)
{
  this->__vftable = (idVirtualTexture_vtbl *)&idVirtualTexture::`vftable';
  idVirtualTexture::FreeData(this);
  Sys_MutexDestroy(handle: &this->headerMutex.handle);
  idSeenBits::~idSeenBits(this: &this->dirtyPages);
  idStr::FreeData(this: &this->mapName);
  idStr::FreeData(this: &this->baseName);
  idStr::FreeData(this: &this->pageFilePath);
}


// ========================================================================
// __unwind$234254
// EA  : 0x82978EE0
// RVA : 0x00978EE0
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void _unwind_234254()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 80));
}


// ========================================================================
// __unwind$234255
// EA  : 0x82978F0C
// RVA : 0x00978F0C
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void _unwind_234255()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 368));
}


// ========================================================================
// __unwind$234256
// EA  : 0x82978F38
// RVA : 0x00978F38
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void _unwind_234256()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 720));
}


// ========================================================================
// __unwind$234257
// EA  : 0x82978F64
// RVA : 0x00978F64
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void _unwind_234257()
{
  int v0; // r12

  idSeenBits::~idSeenBits(this: (idSeenBits *)(*(_DWORD *)(v0 - 112 + 132) + 880));
}


// ========================================================================
// __unwind$234258
// EA  : 0x82978F90
// RVA : 0x00978F90
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void _unwind_234258()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 1232));
}


// ========================================================================
// ?SetSource@idVirtualTexture@@QAA_NPBD0W4physicalPagesPool_t@@@Z
// EA  : 0x82978FC8
// RVA : 0x00978FC8
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

int __fastcall idVirtualTexture::SetSource(
        idVirtualTexture *this,
        const char *baseName_,
        const char *pageFilePath_,
        unsigned int physicalPagesPool)
{
  char *data; // r4
  size_t v9; // r5
  char *v10; // r3
  char *v11; // r4
  idStrStatic<256> *p_pageFilePath; // r20
  size_t v13; // r5
  char *v14; // r3
  pageFileHeader_t *p_header; // r26
  __int64 v16; // r9
  idVirtualTexture *v17; // r10
  int i; // ctr
  idFile *pageFile; // r3
  int v20; // r29
  char *v21; // r21
  const char *v22; // r3
  __int64 v23; // r10
  __int64 v24; // r8
  va *v25; // r3
  idFile *v26; // r3
  char *v27; // r4
  size_t v28; // r5
  char *v29; // r3
  char *v30; // r4
  size_t v31; // r5
  char *v32; // r3
  char *v33; // r4
  size_t v34; // r5
  char *v35; // r3
  int v37; // r29
  int v38; // r27
  int v39; // r3
  void *v40; // r28
  int v41; // r21
  int v42; // r3
  void *v43; // r7
  const void *v44; // r27
  volatile bool *v45; // r10
  int v46; // r8
  idVirtualTexture *v47; // r11
  __int64 v48; // r9
  int k; // ctr
  __int16 layoutVersion; // r11
  int v51; // r4
  idVirtualTexture *v52; // r10
  __int64 v53; // r9
  int j; // ctr
  idFile *v55; // r3
  char installedMipAndOffset_high; // r10
  int valueInteger; // r11
  int pagesWide; // r9
  __int16 numLevels; // r11
  int v60; // r15
  __int16 v61; // r10
  int v62; // r16
  int v63; // r11
  int v64; // ctr
  _WORD *v65; // r10
  __int64 v66; // r6
  int v67; // r8
  int v68; // r11
  __int16 v69; // r10
  idStr *v70; // r3
  idPhysicalPages *v71; // r11
  idStr *v72; // r3
  idStr *v73; // r3
  idImage *pageTableImage; // r3
  idImage *v75; // r3
  int v76; // [sp+8h] [-1788h]
  int v77; // [sp+Ch] [-1784h]
  int v78; // [sp+10h] [-1780h]
  int v79; // [sp+14h] [-177Ch]
  int v80; // [sp+18h] [-1778h]
  int v81; // [sp+1Ch] [-1774h]
  int v82; // [sp+50h] [-1740h]
  idImageOpts v83; // [sp+60h] [-1730h] BYREF
  __int64 v84; // [sp+B0h] [-16E0h]
  idStr v85; // [sp+C0h] [-16D0h] BYREF
  idStr v86; // [sp+E0h] [-16B0h] BYREF
  idStr v87; // [sp+100h] [-1690h] BYREF
  idStr v88; // [sp+120h] [-1670h] BYREF
  idStrStatic<256> v89; // [sp+140h] [-1650h] BYREF
  idStrStatic<256> v90; // [sp+260h] [-1530h] BYREF
  idStrStatic<256> v91; // [sp+380h] [-1410h] BYREF
  idStrStatic<256> v92; // [sp+4A0h] [-12F0h] BYREF
  idStrStatic<256> v93; // [sp+5C0h] [-11D0h] BYREF
  va v94; // [sp+6E0h] [-10B0h] BYREF

  idVirtualTextureSystem::SyncFeedback(this: &virtualTextureSystem);
  this->FreeData(this);
  idStrStatic<256>::idStrStatic<256>(this: &v89, text: baseName_);
  data = v89.data;
  v9 = v89.len + 1;
  v10 = this->baseName.data;
  this->baseName.len = v89.len;
  memcpy(Dst: v10, Src: data, Size: v9);
  idStr::FreeData(this: &v89);
  idStrStatic<256>::idStrStatic<256>(this: &v91, text: pageFilePath_);
  v11 = v91.data;
  p_pageFilePath = &this->pageFilePath;
  v13 = v91.len + 1;
  v14 = this->pageFilePath.data;
  this->pageFilePath.len = v91.len;
  memcpy(Dst: v14, Src: v11, Size: v13);
  idStr::FreeData(this: &v91);
  p_header = &this->header;
  this->pageFileIsLocal = false;
  LODWORD(v16) = 0;
  this->skipFlush = false;
  v17 = this;
  for ( i = 9; i != 0; --i )
  {
    v17 = (idVirtualTexture *)((char *)v17 + 8);
    *(_QWORD *)&v17->__vftable = v16;
  }
  pageFile = idVirtualTextureSystem::OpenCachedPagesFile(this: &virtualTextureSystem, path: this->pageFilePath.data);
  this->pageFile = pageFile;
  if ( pageFile == nullptr )
  {
    v20 = 0;
    if ( session->GetNumContentPackages(this: session) > 0 )
    {
      while ( 1 )
      {
        v21 = this->baseName.data;
        v22 = session->GetContentPackagePath(this: session, a2: v20);
        v25 = va::va(
                this: &v94,
                fmt: "%s/virtualtextures/%s.pages",
                a3: __SPAIR64__((unsigned int)v22, (unsigned int)v21),
                a4: v24,
                a5: v23,
                a6: v76,
                a7: v77,
                a8: v78,
                a9: v79,
                a10: v80,
                a11: v81);
        idStr::idStr(this: &v85, text: v25);
        v26 = idVirtualTextureSystem::OpenCachedPagesFile(this: &virtualTextureSystem, path: v85.data);
        this->pageFile = v26;
        if ( v26 != nullptr )
          break;
        idStr::FreeData(this: &v85);
        if ( ++v20 >= session->GetNumContentPackages(this: session) )
          goto LABEL_9;
      }
      idStrStatic<256>::idStrStatic<256>(this: &v93, text: &v85);
      v27 = v93.data;
      v28 = v93.len + 1;
      v29 = this->pageFilePath.data;
      p_pageFilePath->len = v93.len;
      memcpy(Dst: v29, Src: v27, Size: v28);
      idStr::FreeData(this: &v93);
      idStr::FreeData(this: &v85);
    }
LABEL_9:
    pageFile = this->pageFile;
    if ( pageFile == nullptr )
    {
      if ( idStr::Cmp(s1: this->pageFilePath.data, s2: &byte_8200D768) != 0 )
        idLib::Warning(fmt: "idVirtualTexture::SetSource: Couldn't open '%s'", this->pageFilePath.data);
      idStrStatic<256>::idStrStatic<256>(this: &v90, text: &byte_8200D768);
      v30 = v90.data;
      v31 = v90.len + 1;
      v32 = this->pageFilePath.data;
      p_pageFilePath->len = v90.len;
      memcpy(Dst: v32, Src: v30, Size: v31);
      idStr::FreeData(this: &v90);
      idStrStatic<256>::idStrStatic<256>(this: &v92, text: &byte_8200D768);
      v33 = v92.data;
      v34 = v92.len + 1;
      v35 = this->baseName.data;
      this->baseName.len = v92.len;
      memcpy(Dst: v35, Src: v33, Size: v34);
      idStr::FreeData(this: &v92);
      return 0;
    }
  }
  v37 = ~(pageFile->GetSectorSize(this: pageFile) - 1);
  v38 = (this->pageFile->GetSectorSize(this: this->pageFile) + 4095) & v37;
  v39 = this->pageFile->GetSectorSize(this: this->pageFile);
  v40 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\engine\\renderer\\VirtualTexture.cpp(278) : TAG_VIRTUALTEXTURE",
          size: v39 + v38,
          tag: TAG_VIRTUALTEXTURE,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  v41 = (int)v40 + this->pageFile->GetSectorSize(this: this->pageFile) - 1;
  v42 = this->pageFile->GetSectorSize(this: this->pageFile);
  v43 = (void *)v38;
  v44 = (const void *)(v41 & ~(v42 - 1));
  if ( (unsigned int)idStreamFileCache::UncachedScheduledRead(
                       this: streamFileCache,
                       file: this->pageFile,
                       ofs: (unsigned int)v44,
                       dest: v43,
                       length: v46,
                       a6: v42 - 1,
                       a7: v45) < 0x48 )
    idLib::Error(fmt: "idVirtualTexture::SetSource: Failed to read header for '%s'", this->pageFilePath.data);
  memcpy(Dst: &this->header, Src: v44, Size: sizeof(this->header));
  pageFileHeader_t::Swap(this: &this->header);
  idMem::Free(this: &mem, ptr: v40, align: ALIGN_16);
  if ( this->header.diskOffsetScale == 0 )
    this->header.diskOffsetScale = 64;
  if ( p_header->magic == 1999870212 )
  {
    layoutVersion = this->header.layoutVersion;
    if ( layoutVersion <= 0 || (v51 = this->layoutVersion) <= 0 || v51 == layoutVersion )
    {
      v55 = idVirtualTextureSystem::OpenInstalledCachedPagesFile(
              this: &virtualTextureSystem,
              path: this->pageFilePath.data);
      installedMipAndOffset_high = HIBYTE(this->header.installedMipAndOffset);
      this->pageFileInstalled = v55;
      valueInteger = installedMipAndOffset_high;
      if ( installedMipAndOffset_high <= vt_minMipLevelInstalled.valueInteger )
        valueInteger = vt_minMipLevelInstalled.valueInteger;
      pagesWide = this->header.pagesWide;
      this->minMipLevelInstalled = valueInteger;
      numLevels = this->header.numLevels;
      v60 = numLevels;
      this->VIRTUAL_MAPPING_PAGES_WIDE = pagesWide;
      if ( vt_genMissingPages.valueInteger != 0 )
      {
        v61 = numLevels + 5;
        if ( numLevels + 5 >= 12 )
          v61 = 12;
        if ( numLevels <= v61 )
          numLevels = v61;
        this->header.numLevels = numLevels;
      }
      v62 = 0;
      while ( 1 )
      {
        v63 = 0;
        v64 = 16;
        v65 = (_WORD *)&this->VIRTUAL_MAPPING_PAGES_WIDE + 1;
        LODWORD(v66) = 1 << (this->header.numLevels - 1);
        this->header.pagesWide = v66;
        HIDWORD(v66) = 120 * v66;
        v84 = v66;
        this->VIRTUAL_TEXELS_WIDE = 120 * v66;
        *(float *)&v82 = (float)v66;
        this->VIRTUAL_PAGES_WIDE_LOG2 = (unsigned __int8)(v82 >> 23) - 127;
        do
        {
          v67 = this->header.pagesWide >> v63++;
          *++v65 = v67;
          --v64;
        }
        while ( v64 != 0 );
        v68 = this->header.pagesWide;
        v69 = this->header.numLevels;
        v83.border.x = 0.0;
        v83.colorFormat = CFM_DEFAULT;
        v83.border.y = 0.0;
        v83.border.z = 0.0;
        v83.cubeFilter = false;
        v83.border.w = 0.0;
        v83.depth = 0;
        v83.lodMinClamp = 0.0;
        v83.textureType = TT_2D;
        v83.aniso = 0.0;
        v83.packedTail = true;
        v83.lodBias = vt_lodBias.valueFloat + (float)7.0;
        v83.readback = false;
        v83.lodMaxClamp = 6.0;
        v83.forceBias = false;
        v83.depthCompareMode = false;
        v83.overlayMemory = false;
        v83.startPurged = false;
        v83.filter = TF_NEAREST_MIPMAP_NEAREST;
        v83.repeat = TR_CLAMP;
        v83.format = FMT_RGB565;
        v83.numLevels = v69;
        v83.width = v68;
        v83.height = v68;
        v83.linear = true;
        if ( physicalPagesPool <= 3 )
        {
          if ( physicalPagesPool == 1 )
          {
            this->pageTableImage = idImageManager::ScratchImage(
                                     this: globalImages,
                                     _name: this->pageFilePath.data,
                                     imgOpts: &v83);
            v71 = &virtualTextureSystem.physicalPagesPool[1];
          }
          else if ( physicalPagesPool == 2 )
          {
            v72 = operator+(result: &v86, a: &this->pageFilePath, b: "_do");
            this->pageTableImage = idImageManager::ScratchImage(this: globalImages, _name: v72->data, imgOpts: &v83);
            idStr::FreeData(this: &v86);
            v71 = &virtualTextureSystem.physicalPagesPool[2];
          }
          else if ( physicalPagesPool != 0 )
          {
            v73 = operator+(result: &v87, a: &this->pageFilePath, b: "_do2");
            this->pageTableImage = idImageManager::ScratchImage(this: globalImages, _name: v73->data, imgOpts: &v83);
            idStr::FreeData(this: &v87);
            v71 = &virtualTextureSystem.physicalPagesPool[3];
          }
          else
          {
            if ( this->pageSource == PAGESOURCE_VMTR )
            {
              this->pageTableImage = idImageManager::ScratchImage(
                                       this: globalImages,
                                       _name: "_vmtrPageTable",
                                       imgOpts: &v83);
            }
            else
            {
              v70 = operator+(result: &v88, a: &this->pageFilePath, b: "_vmtr");
              this->pageTableImage = idImageManager::ScratchImage(this: globalImages, _name: v70->data, imgOpts: &v83);
              idStr::FreeData(this: &v88);
            }
            v71 = virtualTextureSystem.physicalPagesPool;
          }
          this->physicalPages = v71;
        }
        pageTableImage = this->pageTableImage;
        this->isDirectMapped = false;
        if ( pageTableImage->allocationFailed )
        {
          if ( this->header.numLevels == v60 )
          {
            idLib::Warning(fmt: "idVirtualTexture::SetSource: Failed to allocate page table image for '%s'", baseName_);
            this->FreeData(this);
            return 0;
          }
          this->enlargedPageTableAllocationFailed = true;
        }
        else
        {
          this->isDirectMapped = XGComparePixelShaders();
        }
        if ( this->enlargedPageTableAllocationFailed )
        {
          v75 = this->pageTableImage;
          if ( v75 != nullptr )
          {
            idImage::PurgeImage(this: v75);
            this->pageTableImage = nullptr;
          }
          ++v62;
          this->header.numLevels = v60;
          if ( v62 < 2 )
            continue;
        }
        virtualTextureSystem.vtPtrs[this->pageSource] = this;
        return 1;
      }
    }
    idLib::Warning(
      fmt: "idVirtualTexture::SetSource: Layout version mismatch (material: %d, vt: %d) for '%s'",
      v51,
      layoutVersion,
      baseName_);
    v52 = this;
    LODWORD(v53) = 0;
    for ( j = 9; j != 0; --j )
    {
      v52 = (idVirtualTexture *)((char *)v52 + 8);
      *(_QWORD *)&v52->__vftable = v53;
    }
  }
  else
  {
    idLib::Warning(fmt: "idVirtualTexture::SetSource: Bad magic %d for '%s'", p_header->magic, this->pageFilePath.data);
    v47 = this;
    LODWORD(v48) = 0;
    for ( k = 9; k != 0; --k )
    {
      v47 = (idVirtualTexture *)((char *)v47 + 8);
      *(_QWORD *)&v47->__vftable = v48;
    }
  }
  idStreamFileCache::Flush(this: streamFileCache);
  idVirtualTextureSystem::CloseCachedPagesFile(this: &virtualTextureSystem, file: this->pageFile);
  this->pageFile = nullptr;
  return 0;
}


// ========================================================================
// $LN226_0
// EA  : 0x829797CC
// RVA : 0x009797CC
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void _LN226_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6032 + 192));
}


// ========================================================================
// __unwind$234353
// EA  : 0x829797F4
// RVA : 0x009797F4
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void _unwind_234353()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6032 + 288));
}


// ========================================================================
// __unwind$234357
// EA  : 0x8297981C
// RVA : 0x0097981C
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void _unwind_234357()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6032 + 224));
}


// ========================================================================
// __unwind$234361
// EA  : 0x82979844
// RVA : 0x00979844
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void _unwind_234361()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6032 + 256));
}


// ========================================================================
// `dynamic initializer for 'vt_usePageFileCache''
// EA  : 0x8335E6C0
// RVA : 0x0135E6C0
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_usePageFileCache__()
{
  idCVar::idCVar(
    this: &vt_usePageFileCache,
    name: "vt_usePageFileCache",
    value: "1",
    flags: 17,
    description: "Use the pageFileCache for all reads",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_usePageFileCache__);
}


// ========================================================================
// `dynamic initializer for 'vt_minMipLevelInstalled''
// EA  : 0x8335E718
// RVA : 0x0135E718
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_minMipLevelInstalled__()
{
  idCVar::idCVar(
    this: &vt_minMipLevelInstalled,
    name: "vt_minMipLevelInstalled",
    value: "0",
    flags: 18,
    description: "minimum mip level installed on the hard disk (2 = all mips except finest two installed, 16 = no mips installed)",
    valueMin: 0.0,
    valueMax: 16.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"olor specular",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_minMipLevelInstalled__);
}


// ========================================================================
// `dynamic initializer for 'mt_genCompression''
// EA  : 0x8335E780
// RVA : 0x0135E780
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mt_genCompression__()
{
  idCVar::idCVar(
    this: &mt_genCompression,
    name: "mt_genCompression",
    value: "DCT",
    flags: 16,
    description: "Compression method for generated pages.",
    valueStrings: compressionStrings,
    valueCompletion: idCmdSystem::ArgCompletion_String<&char const * * compressionStrings>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mt_genCompression__);
}


// ========================================================================
// `dynamic initializer for 'vt_vmtrCompression''
// EA  : 0x8335E7E0
// RVA : 0x0135E7E0
// PDB : w:\tech5\engine\renderer\virtualtexture.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_vmtrCompression__()
{
  idCVar::idCVar(
    this: &vt_vmtrCompression,
    name: "vt_vmtrCompression",
    value: "DCT",
    flags: 16,
    description: "Compression method for vmtr pages.",
    valueStrings: compressionStrings,
    valueCompletion: idCmdSystem::ArgCompletion_String<&char const * * compressionStrings>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_vmtrCompression__);
}

