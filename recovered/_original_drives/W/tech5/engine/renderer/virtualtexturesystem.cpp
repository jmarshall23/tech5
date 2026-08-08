
// ========================================================================
// ??1idPhysicalPageList@@QAA@XZ
// EA  : 0x8297B3F8
// RVA : 0x0097B3F8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idPhysicalPageList::~idPhysicalPageList(idPhysicalPageList *this)
{
  idMem::Free(this: &mem, ptr: this->physicalPageNums, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->sortParms, align: ALIGN_16);
}


// ========================================================================
// ?Init@idPhysicalPageList@@QAAXH@Z
// EA  : 0x8297B450
// RVA : 0x0097B450
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idPhysicalPageList::Init(idPhysicalPageList *this, int size)
{
  __int64 *physicalPageNums; // r4

  physicalPageNums = this->physicalPageNums;
  if ( physicalPageNums != nullptr )
    idMem::Free(this: &mem, ptr: physicalPageNums, align: ALIGN_128);
  this->indexMask = size - 1;
  this->firstPageIndex = 0;
  this->lastPageIndex = -1;
  this->physicalPageNums = (__int64 *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(231) : TAG_VIRTUALTEXTURE",
                                        size: 8 * size,
                                        tag: TAG_VIRTUALTEXTURE,
                                        zeroBuffer: false,
                                        align: ALIGN_128,
                                        heap: HEAP_DEFAULTHEAP);
  this->sortDone = 1;
  this->sortParms = (pageSortParms_t *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(233) : TAG_VIRTUALTEXTURE",
                                         size: 0x24u,
                                         tag: TAG_VIRTUALTEXTURE,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
}


// ========================================================================
// ?Remove@idPhysicalPageList@@QAAXH@Z
// EA  : 0x8297B4F8
// RVA : 0x0097B4F8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idPhysicalPageList::Remove(idPhysicalPageList *this, int physicalPageNum)
{
  int firstPageIndex; // r7
  int v3; // r11
  int indexMask; // r9
  __int64 *physicalPageNums; // r8
  int v7; // r5
  __int64 v8; // r4
  int v9; // r10
  int v10; // r9
  __int64 v11; // r9

  firstPageIndex = this->firstPageIndex;
  v3 = this->firstPageIndex;
  if ( this->firstPageIndex <= this->lastPageIndex )
  {
    indexMask = this->indexMask;
    physicalPageNums = this->physicalPageNums;
    while ( 1 )
    {
      v7 = indexMask & v3;
      v8 = physicalPageNums[v7];
      if ( LODWORD(physicalPageNums[v7]) == physicalPageNum )
        break;
      if ( ++v3 > *(_DWORD *)(HIDWORD(v8) + 4) )
        return;
    }
    v9 = v3;
    if ( v3 > firstPageIndex )
    {
      do
      {
        v10 = *(_DWORD *)(HIDWORD(v8) + 8);
        LODWORD(v8) = 8 * (v10 & v9);
        v11 = *(_QWORD *)(8 * ((v9 - 1) & v10) + *(_DWORD *)(HIDWORD(v8) + 12));
        *(_QWORD *)(v8 + HIDWORD(v11)) = v11;
        --v9;
      }
      while ( v9 > *(_DWORD *)HIDWORD(v8) );
    }
    ++*(_DWORD *)HIDWORD(v8);
  }
}


// ========================================================================
// ?Sort@idPhysicalPageList@@QAAXHPBH0PAVidParallelJobList@@H@Z
// EA  : 0x8297B598
// RVA : 0x0097B598
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idPhysicalPageList::Sort(
        idPhysicalPageList *this,
        int frameNum,
        const int *pagePriority,
        const int *pageFrameNum,
        idParallelJobList *jobList,
        int useJobs)
{
  int *p_lastPageIndex; // r10
  pageSortParms_t *sortParms; // r3

  p_lastPageIndex = &this->lastPageIndex;
  if ( this->lastPageIndex >= this->firstPageIndex )
  {
    sortParms = this->sortParms;
    this->sortDone = 0;
    sortParms->frameNum = frameNum;
    this->sortParms->pagePriority = pagePriority;
    this->sortParms->pageFrameNum = pageFrameNum;
    this->sortParms->physicalPageNums = this->physicalPageNums;
    this->sortParms->firstPageIndex = &this->firstPageIndex;
    this->sortParms->lastPageIndex = p_lastPageIndex;
    this->sortParms->indexMask = this->indexMask;
    this->sortParms->sortedPhysicalPageNums = this->physicalPageNums;
    this->sortParms->done = &this->sortDone;
    if ( useJobs == 1 )
      idParallelJobList::AddJob(
        this: jobList,
        function: (void (__fastcall *)(void *))PageSortJob,
        data: this->sortParms);
    else
      PageSortJob(parms: this->sortParms);
  }
}


// ========================================================================
// ??1idPhysicalPageHash@@QAA@XZ
// EA  : 0x8297B670
// RVA : 0x0097B670
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idPhysicalPageHash::~idPhysicalPageHash(idPhysicalPageHash *this)
{
  idMem::Free(this: &mem, ptr: this->pageHashTable, align: ALIGN_128);
  idMem::Free(this: &mem, ptr: this->pageHashIndex, align: ALIGN_128);
}


// ========================================================================
// ?Init@idPhysicalPageHash@@QAAXHH@Z
// EA  : 0x8297B6C8
// RVA : 0x0097B6C8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idPhysicalPageHash::Init(idPhysicalPageHash *this, int hashSize, int indexSize)
{
  unsigned int v3; // r10
  unsigned __int16 *pageHashTable; // r4
  unsigned int v8; // r29
  unsigned __int16 *v9; // r3
  idPhysicalPageHash::pageHashEntry_t *pageHashIndex; // r4

  v3 = hashSize - 1;
  pageHashTable = this->pageHashTable;
  this->hashMask = v3;
  if ( pageHashTable != nullptr )
    idMem::Free(this: &mem, ptr: pageHashTable, align: ALIGN_128);
  v8 = 2 * hashSize;
  v9 = (unsigned __int16 *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(336) : TAG_VIRTUALTEXTURE",
                             size: v8,
                             tag: TAG_VIRTUALTEXTURE,
                             zeroBuffer: false,
                             align: ALIGN_128,
                             heap: HEAP_DEFAULTHEAP);
  this->pageHashTable = v9;
  memset(Dst: v9, Val: 255, Size: v8);
  pageHashIndex = this->pageHashIndex;
  if ( pageHashIndex != nullptr )
    idMem::Free(this: &mem, ptr: pageHashIndex, align: ALIGN_128);
  this->pageHashIndex = (idPhysicalPageHash::pageHashEntry_t *)idMem::AllocWithLocation(
                                                                 this: &mem,
                                                                 location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(3"
                                                                 "42) : TAG_VIRTUALTEXTURE",
                                                                 size: 8 * indexSize,
                                                                 tag: TAG_VIRTUALTEXTURE,
                                                                 zeroBuffer: true,
                                                                 align: ALIGN_128,
                                                                 heap: HEAP_DEFAULTHEAP);
}


// ========================================================================
// ?RemovePage@idPhysicalPageHash@@QAAXPAUtexturePage_t@@@Z
// EA  : 0x8297B788
// RVA : 0x0097B788
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idPhysicalPageHash::RemovePage(idPhysicalPageHash *this, texturePage_t *page)
{
  int pageLevel; // r10
  int pageY; // r8
  int v4; // r7
  int pageX; // r6
  __int32 v6; // r10
  unsigned int v7; // r4
  int v8; // r9
  unsigned __int16 *v9; // r11
  char *v10; // r10

  pageLevel = page->pageLevel;
  pageY = page->pageY;
  v4 = __ROL4__(pageLevel, 11);
  pageX = page->pageX;
  v6 = (((16 * page->pageSource) | pageLevel) << 11) | pageY;
  v7 = 1664525 * (((v4 | pageY) << 11) | pageX) + 1013904223;
  v8 = (v6 << 11) | pageX;
  v9 = &this->pageHashTable[((((v7 >> 11) ^ v7) >> 11) ^ v7) & this->hashMask];
  if ( *v9 != 0xFFFF )
  {
    while ( 1 )
    {
      v10 = (char *)this->pageHashIndex + __ROL4__(*v9, 3);
      if ( *(_DWORD *)v10 == v8 )
        break;
      v9 = (unsigned __int16 *)(v10 + 6);
      if ( *((unsigned __int16 *)v10 + 3) == 0xFFFF )
        return;
    }
    *v9 = *((_WORD *)v10 + 3);
  }
}


// ========================================================================
// ?HashStats@idPhysicalPageHash@@QBAXAAH00000@Z
// EA  : 0x8297B840
// RVA : 0x0097B840
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idPhysicalPageHash::HashStats(
        idPhysicalPageHash *this,
        int *total,
        int *c0,
        int *c1,
        int *c2,
        int *c3,
        int *cX)
{
  unsigned int v7; // r28
  int v8; // r29
  int v9; // r11
  int i; // r10

  *cX = 0;
  v7 = 0;
  *c3 = 0;
  v8 = 0;
  *c2 = 0;
  *c1 = 0;
  *c0 = 0;
  *total = 0;
  do
  {
    v9 = 0;
    for ( i = this->pageHashTable[v8]; i != 0xFFFF; i = this->pageHashIndex[i].next )
      ++v9;
    *total += v9;
    if ( v9 != 0 )
    {
      if ( v9 == 1 )
      {
        ++*c1;
      }
      else if ( v9 == 2 )
      {
        ++*c1;
        ++*c2;
      }
      else
      {
        ++*c1;
        ++*c2;
        ++*c3;
        if ( v9 != 3 )
          *cX = *cX + v9 - 3;
      }
    }
    else
    {
      ++*c0;
    }
    ++v7;
    ++v8;
  }
  while ( v7 <= this->hashMask );
}


// ========================================================================
// ??0idPhysicalPages@@QAA@XZ
// EA  : 0x8297B978
// RVA : 0x0097B978
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

idPhysicalPages *__fastcall idPhysicalPages::idPhysicalPages(idPhysicalPages *this)
{
  this->pages = nullptr;
  this->physicalPagesPool = PHYSICAL_PAGES_POOL_MAX;
  this->pagePriority = nullptr;
  this->pageFrameNum = nullptr;
  this->pageHash.hashMask = 0;
  this->pageHash.pageHashTable = nullptr;
  this->pageHash.pageHashIndex = nullptr;
  this->freePageList.firstPageIndex = 0;
  this->freePageList.lastPageIndex = 0;
  this->freePageList.indexMask = 0;
  this->freePageList.physicalPageNums = nullptr;
  this->freePageList.sortDone = 1;
  this->freePageList.sortParms = nullptr;
  this->unlockedPageList.firstPageIndex = 0;
  this->unlockedPageList.lastPageIndex = 0;
  this->unlockedPageList.indexMask = 0;
  this->unlockedPageList.physicalPageNums = nullptr;
  this->unlockedPageList.sortDone = 1;
  this->unlockedPageList.sortParms = nullptr;
  this->feedbackDynamicLodBias = 0.0;
  this->oldFeedbackDynamicLodBias = 0.0;
  this->numLockedPages = 0;
  this->pageImageCompressed = false;
  this->isDirectMapped = false;
  this->PHYSICAL_TEXELS_WIDE = 1;
  this->PHYSICAL_TEXELS_HIGH = 1;
  this->PHYSICAL_PAGES_WIDE = 1;
  this->PHYSICAL_PAGES_HIGH = 1;
  this->NUM_PHYSICAL_PAGES = 1;
  this->physicalPagesImage0 = nullptr;
  this->physicalPagesImage1 = nullptr;
  this->physicalPagesImage2 = nullptr;
  this->physicalMappingsImage0 = nullptr;
  this->feedbackNumPages = 0;
  this->rpPhysicalFilterParms = nullptr;
  return this;
}


// ========================================================================
// ?LockPage@idPhysicalPages@@QAAXPAUtexturePage_t@@@Z
// EA  : 0x8297BA20
// RVA : 0x0097BA20
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idPhysicalPages::LockPage(idPhysicalPages *this, texturePage_t *page)
{
  int physicalPageNum; // r4

  if ( !page->locked )
  {
    physicalPageNum = page->physicalPageNum;
    page->locked = true;
    idPhysicalPageList::Remove(this: &this->unlockedPageList, physicalPageNum);
    ++this->numLockedPages;
  }
}


// ========================================================================
// ?GetNumResidentPagesForSource@idPhysicalPages@@QBAHW4pageSource_t@@@Z
// EA  : 0x8297BA78
// RVA : 0x0097BA78
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

int __fastcall idPhysicalPages::GetNumResidentPagesForSource(idPhysicalPages *this, pageSource_t src)
{
  int NUM_PHYSICAL_PAGES; // r10
  int result; // r3
  texturePage_t *pages; // r9
  int v6; // r11
  int v7; // ctr
  texturePage_t *v8; // r10

  NUM_PHYSICAL_PAGES = this->NUM_PHYSICAL_PAGES;
  result = 0;
  if ( NUM_PHYSICAL_PAGES > 0 )
  {
    pages = this->pages;
    v7 = NUM_PHYSICAL_PAGES;
    v8 = pages;
    v6 = 0;
    do
    {
      if ( v8->pageSource == src )
        ++result;
      v8 = &pages[++v6];
      --v7;
    }
    while ( v7 != 0 );
  }
  return result;
}


// ========================================================================
// ?GetNumLockedPagesForSource@idPhysicalPages@@QBAHW4pageSource_t@@@Z
// EA  : 0x8297BAC0
// RVA : 0x0097BAC0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

int __fastcall idPhysicalPages::GetNumLockedPagesForSource(idPhysicalPages *this, pageSource_t src)
{
  int NUM_PHYSICAL_PAGES; // r10
  int result; // r3
  texturePage_t *pages; // r8
  int v6; // r9
  int i; // ctr

  NUM_PHYSICAL_PAGES = this->NUM_PHYSICAL_PAGES;
  result = 0;
  if ( NUM_PHYSICAL_PAGES > 0 )
  {
    pages = this->pages;
    v6 = 0;
    for ( i = NUM_PHYSICAL_PAGES; i != 0; --i )
    {
      if ( pages[v6].pageSource == src && pages[v6].locked )
        ++result;
      ++v6;
    }
  }
  return result;
}


// ========================================================================
// ?ValidateCache@idPhysicalPages@@QBAXXZ
// EA  : 0x8297BB10
// RVA : 0x0097BB10
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idPhysicalPages::ValidateCache(idPhysicalPages *this)
{
  int v2; // r22
  int v3; // r30
  int v4; // r26
  int NUM_PHYSICAL_PAGES; // r11
  int v6; // r27
  int v7; // r28
  texturePage_t *v8; // r11
  unsigned int pageLevel; // r4
  unsigned __int32 v10; // r9
  int v11; // r5
  unsigned __int32 v12; // r10
  signed int v13; // r31
  int v14; // r5
  int v15; // r9
  int v16; // r7
  int v17; // r4
  int v18; // r10
  int v19; // r7
  int v20; // r5
  int v21; // [sp+50h] [-880h] BYREF
  int v22; // [sp+54h] [-87Ch] BYREF
  int v23; // [sp+58h] [-878h] BYREF
  int v24; // [sp+5Ch] [-874h] BYREF
  int v25; // [sp+60h] [-870h] BYREF
  int v26[539]; // [sp+64h] [-86Ch] BYREF

  while ( this->unlockedPageList.sortDone == 0 )
    Sys_Yield();
  idLib::Printf(fmt: "%s\n", physicalPoolNames[this->physicalPagesPool]);
  idLib::Printf(fmt: "------------------------\n");
  v2 = 0;
  v3 = 0;
  v4 = 0;
  memset(Dst: &v26[3], Val: 0, Size: 0x800u);
  NUM_PHYSICAL_PAGES = this->NUM_PHYSICAL_PAGES;
  v6 = 0;
  if ( NUM_PHYSICAL_PAGES > 0 )
  {
    v7 = 0;
    do
    {
      v8 = &this->pages[v7];
      if ( !v8->mapped )
        ++v2;
      if ( v8->locked )
        ++v4;
      if ( v8->pageSource < PAGESOURCE_TOTAL )
      {
        pageLevel = v8->pageLevel;
        if ( pageLevel < 0x10 )
        {
          v10 = 16 * v8->pageSource + pageLevel;
          v11 = virtualTextureSystem.feedbackFrameNum
              - *(int *)((char *)this->pageFrameNum + __ROL4__(v8->physicalPageNum, 2));
          ++v26[v10 + 3];
          if ( v11 < 3 )
          {
            ++v3;
            v12 = 16 * v8->pageSource + pageLevel;
            ++v26[v12 + 259];
          }
        }
        else
        {
          idLib::Printf(fmt: "Bad level: %i\n", pageLevel);
        }
      }
      else
      {
        idLib::Printf(fmt: "Bad pageSource\n");
      }
      NUM_PHYSICAL_PAGES = this->NUM_PHYSICAL_PAGES;
      ++v6;
      ++v7;
    }
    while ( v6 < NUM_PHYSICAL_PAGES );
  }
  if ( this->freePageList.lastPageIndex
     + this->unlockedPageList.lastPageIndex
     - this->unlockedPageList.firstPageIndex
     - this->freePageList.firstPageIndex
     + v4
     + 2 != NUM_PHYSICAL_PAGES )
    idLib::Warning(fmt: "unlockedPageListCount + freePageListCount + lockedPages != NUM_PHYSICAL_PAGES");
  idLib::Printf(fmt: "total  : %4i\n", this->NUM_PHYSICAL_PAGES);
  idLib::Printf(fmt: "locked : %4i\n", v4);
  idLib::Printf(fmt: "current: %4i\n", v3);
  idLib::Printf(fmt: "free   : %4i\n", v2);
  idPhysicalPageHash::HashStats(this: &this->pageHash, total: &v22, c0: v26, c1: &v24, c2: &v21, c3: &v23, cX: &v25);
  v13 = v22;
  if ( v22 == 0 )
    v13 = 1;
  idLib::Printf(fmt: "%4i %% empty hash table entries\n", (unsigned int)(100 * v26[0] + 1024) >> 11);
  v14 = 100 * v24 + v13 / 2;
  __twllei(v13, 0);
  __twlgei(v13 & ~(__ROL4__(v14, 1) - 1), 0xFFFFFFFF);
  idLib::Printf(fmt: "%4i %% pages 0 steps down the hash chain\n", v14 / v13);
  v15 = v21;
  __twllei(v13, 0);
  v16 = 100 * v15 + v13 / 2;
  __twlgei(v13 & ~(__ROL4__(v16, 1) - 1), 0xFFFFFFFF);
  idLib::Printf(fmt: "%4i %% pages 1 step down the hash chain\n", v16 / v13);
  v17 = v23;
  __twllei(v13, 0);
  v18 = 100 * v17 + v13 / 2;
  __twlgei(v13 & ~(__ROL4__(v18, 1) - 1), 0xFFFFFFFF);
  idLib::Printf(fmt: "%4i %% pages 2 steps down the hash chain\n", v18 / v13);
  v19 = v25;
  __twllei(v13, 0);
  v20 = 100 * v19 + v13 / 2;
  __twlgei(v13 & ~(__ROL4__(v20, 1) - 1), 0xFFFFFFFF);
  idLib::Printf(fmt: "%4i %% pages > 2 steps down the hash chain\n", v20 / v13);
  idLib::Printf(fmt: "------------------------\n");
}


// ========================================================================
// ?FreeLockedPages@idVirtualTextureSystem@@QAAXXZ
// EA  : 0x8297BF68
// RVA : 0x0097BF68
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::FreeLockedPages(idVirtualTextureSystem *this)
{
  idVirtualTexture *v1; // r30
  int i; // r31

  v1 = &this->vts[2];
  for ( i = 14; i != 0; --i )
    idVirtualTexture::EmptyCache(this: v1++);
}


// ========================================================================
// ?FreeDynamicMedia@idVirtualTextureSystem@@QAAXXZ
// EA  : 0x8297BFB0
// RVA : 0x0097BFB0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::FreeDynamicMedia(idVirtualTextureSystem *this)
{
  idVirtualTexture *v1; // r31
  int i; // r30

  v1 = &this->vts[2];
  for ( i = 14; i != 0; --i )
  {
    v1->FreeData(this: v1);
    ++v1;
  }
}


// ========================================================================
// ParseDimensions
// EA  : 0x8297C008
// RVA : 0x0097C008
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall ParseDimensions(const char *str, int *width, int *height)
{
  int v5; // r3

  v5 = sscanf(string: str, format: "%i %i", width, height);
  if ( v5 != 0 )
  {
    if ( v5 == 1 )
      *height = *width;
    if ( *width < 1024 )
      *width = 1024;
  }
  else
  {
    *height = 4096;
    *width = 4096;
  }
  if ( *height < 1024 )
    *height = 1024;
}


// ========================================================================
// ?SetContainerPath@idVirtualTextureSystem@@QAAXPBD@Z
// EA  : 0x8297C0A0
// RVA : 0x0097C0A0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::SetContainerPath(idVirtualTextureSystem *this, const char *path)
{
  idStr::Copynz(dest: this->containerPath, src: path, destsize: 256);
}


// ========================================================================
// ?AddToReferencedVirtualTextures@idVirtualTextureSystem@@QAAXPBD0@Z
// EA  : 0x8297C0B0
// RVA : 0x0097C0B0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::AddToReferencedVirtualTextures(
        idVirtualTextureSystem *this,
        const char *name,
        const char *path)
{
  int numReferencedVirtualTextures; // r5
  int v6; // r7
  char *v7; // r8
  const char *v8; // r10
  char *v9; // r11
  int v10; // r9
  int v11; // r9
  bool v12; // zf

  numReferencedVirtualTextures = this->numReferencedVirtualTextures;
  v6 = 0;
  if ( numReferencedVirtualTextures <= 0 )
  {
LABEL_8:
    if ( numReferencedVirtualTextures == 100 )
    {
      idLib::Printf(fmt: "MAX_REFERENCED_VIRTUAL_TEXTURES", name, 100, 46216, v6);
    }
    else
    {
      strncpy(dest: this->referencedVTName[numReferencedVirtualTextures], source: name, count: 0x1Fu);
      strncpy(dest: this->referencedVTPath[this->numReferencedVirtualTextures], source: path, count: 0xFFu);
      ++this->numReferencedVirtualTextures;
    }
  }
  else
  {
    v7 = this->referencedVTName[0];
    while ( 1 )
    {
      v8 = name;
      v9 = v7;
      do
      {
        v10 = (unsigned __int8)*v9;
        v12 = v10 == 0;
        v11 = v10 - *(unsigned __int8 *)v8;
        if ( v12 )
          break;
        ++v9;
        ++v8;
      }
      while ( v11 == 0 );
      if ( v11 == 0 )
        break;
      ++v6;
      v7 += 32;
      if ( v6 >= this->numReferencedVirtualTextures )
        goto LABEL_8;
    }
  }
}


// ========================================================================
// ?WaitForLastAnalyzeFeedback@idVirtualTextureSystem@@AAAXXZ
// EA  : 0x8297C1A0
// RVA : 0x0097C1A0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::WaitForLastAnalyzeFeedback(idVirtualTextureSystem *this)
{
  idParallelJobList **p_analyzeJobList; // r30
  unsigned int v3; // r11

  p_analyzeJobList = &this->analyzeJobList;
  if ( idParallelJobList::IsSubmitted(this: this->analyzeJobList) )
  {
    idParallelJobList::Wait(this: *p_analyzeJobList);
    v3 = this->currentPageIndices ^ 1;
    this->currentPageIndices = v3;
    this->numExplicitPages[v3] = 0;
  }
}


// ========================================================================
// ?StringForPageCompression@@YAPBDW4pageCompression_t@@@Z
// EA  : 0x8297C218
// RVA : 0x0097C218
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

const char *__fastcall StringForPageCompression(pageCompression_t c)
{
  if ( (unsigned int)(c - 1) > 5 )
    return "BAD";
  switch ( c )
  {
    case COMP_DXT:
      return "DXT";
    case COMP_LZW:
      return "LZW";
    case COMP_DCT:
      return "DCT";
    case COMP_HDP:
      return "HDP";
    case COMP_NONE:
      return "UNC";
    default:
      break;
  }
  return "JXR";
}


// ========================================================================
// SortCacheLinesOnOffset
// EA  : 0x8297C298
// RVA : 0x0097C298
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall SortCacheLinesOnOffset(_QWORD *a, _QWORD *b)
{
  __int64 v2; // r11 OVERLAPPED
  int result; // r3

  v2 = a[1];
  *(__int64 *)((char *)&v2 + 4) = b[1];
  if ( (unsigned int)v2 > HIDWORD(v2) )
    return 1;
  result = -1;
  if ( (unsigned int)v2 >= HIDWORD(v2) )
    return 0;
  return result;
}


// ========================================================================
// ?ClearFeedback@idVirtualTextureSystem@@QAAXXZ
// EA  : 0x8297C2C0
// RVA : 0x0097C2C0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::ClearFeedback(idVirtualTextureSystem *this)
{
  int *p_feedbackBufferPitch; // r29
  idPixelPackBuffer **p_feedbackBufferObject; // r30
  int i; // r31
  int v5; // r9
  __int64 v6; // r11
  _QWORD *v7; // r8

  if ( this->feedbackBuffer != nullptr )
  {
    p_feedbackBufferPitch = &this->feedbackBufferPitch;
    p_feedbackBufferObject = &this->feedbackBufferObject;
    for ( i = 3; i != 0; --i )
      memset(Dst: *(void **)((*++p_feedbackBufferObject)[1].size + 152), Val: 0, Size: *p_feedbackBufferPitch << 7);
    v5 = 2;
    HIDWORD(v6) = &this->explicitPages[1];
    LODWORD(v6) = 0;
    do
    {
      v7 = *(_QWORD **)(HIDWORD(v6) - 12);
      --v5;
      v7[1] = v6;
      v7[2] = v6;
      v7[3] = v6;
      v7[4] = v6;
      *(_QWORD *)*(_DWORD *)(HIDWORD(v6) - 12) = v6;
      HIDWORD(v6) += 4;
      *(_DWORD *)HIDWORD(v6) = 0;
    }
    while ( v5 != 0 );
  }
}


// ========================================================================
// ?CreatePhysicalImages@idPhysicalPages@@QAA_NW4physicalPagesPool_t@@PBDHHPBV?$idCodeResource@VidDeclRenderParm@@@@@Z
// EA  : 0x8297C520
// RVA : 0x0097C520
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

int __fastcall idPhysicalPages::CreatePhysicalImages(
        idPhysicalPages *this,
        physicalPagesPool_t pool,
        const char *name,
        int pageImageWidth,
        int pageImageHeight,
        const idCodeResource<idDeclRenderParm> *rpPhysicalFilterParms_)
{
  texturePage_t *pages; // r4
  texturePage_t *v13; // r3
  int *pagePriority; // r4
  int *v15; // r3
  int *pageFrameNum; // r4
  char v17; // r27
  int v18; // r11
  int v19; // r10
  int v20; // r9
  __int64 v21; // r6
  texturePage_t *v22; // r8
  __int64 *physicalPageNums; // r7
  int v24; // r8
  int PHYSICAL_TEXELS_WIDE; // r9
  __int64 v26; // r8
  __int64 v27; // r6
  int v28; // r26
  unsigned int valueInteger; // r11
  char v30; // r4
  __int64 v31; // r10
  va *v32; // r3
  idImage *v33; // r3
  __int64 v34; // r6
  int pageImageCompressed; // r11
  __int64 v36; // r10
  __int64 v37; // r8
  va *v38; // r3
  __int64 v39; // r6
  idImage *v40; // r3
  int v41; // r11
  __int64 v42; // r10
  __int64 v43; // r8
  va *v44; // r3
  idImage *v45; // r3
  int v47; // [sp+8h] [-10F8h]
  int v48; // [sp+8h] [-10F8h]
  int v49; // [sp+8h] [-10F8h]
  int v50; // [sp+Ch] [-10F4h]
  int v51; // [sp+Ch] [-10F4h]
  int v52; // [sp+Ch] [-10F4h]
  int v53; // [sp+10h] [-10F0h]
  int v54; // [sp+10h] [-10F0h]
  int v55; // [sp+10h] [-10F0h]
  int v56; // [sp+14h] [-10ECh]
  int v57; // [sp+14h] [-10ECh]
  int v58; // [sp+14h] [-10ECh]
  int v59; // [sp+18h] [-10E8h]
  int v60; // [sp+18h] [-10E8h]
  int v61; // [sp+18h] [-10E8h]
  int v62; // [sp+1Ch] [-10E4h]
  int v63; // [sp+1Ch] [-10E4h]
  int v64; // [sp+1Ch] [-10E4h]
  idImageOpts v65; // [sp+50h] [-10B0h] BYREF
  va v66; // [sp+A0h] [-1060h] BYREF

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  pages = this->pages;
  this->physicalPagesPool = pool;
  this->PHYSICAL_TEXELS_HIGH = pageImageHeight;
  this->PHYSICAL_TEXELS_WIDE = pageImageWidth;
  this->PHYSICAL_PAGES_WIDE = pageImageWidth / 128;
  this->PHYSICAL_PAGES_HIGH = pageImageHeight / 128;
  this->NUM_PHYSICAL_PAGES = pageImageHeight / 128 * (pageImageWidth / 128);
  if ( pages != nullptr )
    idMem::Free(this: &mem, ptr: pages, align: ALIGN_128);
  v13 = (texturePage_t *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(521) : TAG_VIRTUALTEXTURE",
                           size: 72 * this->NUM_PHYSICAL_PAGES,
                           tag: TAG_VIRTUALTEXTURE,
                           zeroBuffer: true,
                           align: ALIGN_128,
                           heap: HEAP_DEFAULTHEAP);
  pagePriority = this->pagePriority;
  this->pages = v13;
  if ( pagePriority != nullptr )
    idMem::Free(this: &mem, ptr: pagePriority, align: ALIGN_128);
  v15 = (int *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(526) : TAG_VIRTUALTEXTURE",
                 size: 4 * this->NUM_PHYSICAL_PAGES,
                 tag: TAG_VIRTUALTEXTURE,
                 zeroBuffer: true,
                 align: ALIGN_128,
                 heap: HEAP_DEFAULTHEAP);
  pageFrameNum = this->pageFrameNum;
  this->pagePriority = v15;
  if ( pageFrameNum != nullptr )
    idMem::Free(this: &mem, ptr: pageFrameNum, align: ALIGN_128);
  this->pageFrameNum = (int *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(531) : TAG_VIRTUALTEXTURE",
                                size: 4 * this->NUM_PHYSICAL_PAGES,
                                tag: TAG_VIRTUALTEXTURE,
                                zeroBuffer: true,
                                align: ALIGN_128,
                                heap: HEAP_DEFAULTHEAP);
  idPhysicalPageHash::Init(this: &this->pageHash, hashSize: 2048, indexSize: this->NUM_PHYSICAL_PAGES);
  idPhysicalPageList::Init(this: &this->freePageList, size: this->NUM_PHYSICAL_PAGES);
  idPhysicalPageList::Init(this: &this->unlockedPageList, size: this->NUM_PHYSICAL_PAGES);
  v17 = 1;
  v18 = 0;
  if ( this->NUM_PHYSICAL_PAGES > 0 )
  {
    v19 = 0;
    v20 = 0;
    do
    {
      LODWORD(v21) = v18;
      v22 = &this->pages[v20++];
      v22->physicalPageNum = v18++;
      this->pagePriority[v19] = 0;
      this->pageFrameNum[v19++] = 1;
      physicalPageNums = this->freePageList.physicalPageNums;
      v24 = this->freePageList.lastPageIndex + 1;
      HIDWORD(v21) = v24 & this->freePageList.indexMask;
      this->freePageList.lastPageIndex = v24;
      physicalPageNums[HIDWORD(v21)] = v21;
    }
    while ( v18 < this->NUM_PHYSICAL_PAGES );
  }
  this->numLockedPages = 0;
  PHYSICAL_TEXELS_WIDE = this->PHYSICAL_TEXELS_WIDE;
  v65.colorFormat = CFM_DEFAULT;
  HIDWORD(v26) = 0x82000000;
  v65.cubeFilter = false;
  v65.depth = 0;
  LODWORD(v27) = "olor specular";
  v65.packedTail = true;
  HIDWORD(v27) = name;
  v65.width = PHYSICAL_TEXELS_WIDE;
  v65.height = PHYSICAL_TEXELS_WIDE;
  v65.border.x = 0.0;
  v65.readback = false;
  v65.border.y = 0.0;
  v65.forceBias = false;
  v65.border.z = 0.0;
  v65.depthCompareMode = false;
  v65.border.w = 0.0;
  v65.overlayMemory = false;
  v65.lodBias = 0.0;
  v65.startPurged = false;
  v65.lodMinClamp = 0.0;
  v65.numLevels = 1;
  v65.aniso = 0.0;
  v65.repeat = TR_CLAMP;
  v65.lodMaxClamp = 1.0;
  v65.filter = TF_LINEAR;
  v65.textureType = TT_2D;
  v28 = 1;
  v65.linear = true;
  valueInteger = vt_uncompressedPhysicalImages.valueInteger;
  this->isDirectMapped = true;
  v30 = _cntlzw(valueInteger);
  this->pageImageCompressed = (v30 & 0x20) != 0;
  LODWORD(v31) = -((v30 & 0x20) != 0);
  HIDWORD(v31) = ((v30 & 0x20) == 0) - 1;
  LODWORD(v26) = (BYTE3(v31) & 8) + 3;
  v65.format = v26;
  v32 = va::va(
          this: &v66,
          fmt: "_physical%sPages1",
          a3: v27,
          a4: v26,
          a5: v31,
          a6: v47,
          a7: v50,
          a8: v53,
          a9: v56,
          a10: v59,
          a11: v62);
  v33 = idImageManager::ScratchImage(this: globalImages, _name: v32->buffer, imgOpts: &v65);
  this->physicalPagesImage1 = v33;
  LODWORD(v34) = v33->allocationFailed;
  if ( v33->allocationFailed )
  {
    v28 = 0;
LABEL_13:
    this->isDirectMapped = false;
    goto LABEL_14;
  }
  if ( (unsigned __int8)XGComparePixelShaders() == 0 )
    goto LABEL_13;
LABEL_14:
  if ( this->physicalPagesPool != PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY
    && this->physicalPagesPool != PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY2 )
  {
    v17 = 0;
  }
  if ( v17 != 0 )
    goto LABEL_26;
  pageImageCompressed = this->pageImageCompressed;
  LODWORD(v36) = "olor specular";
  HIDWORD(v34) = name;
  HIDWORD(v36) = -pageImageCompressed;
  LODWORD(v37) = (pageImageCompressed == 0) - 1;
  HIDWORD(v37) = (v37 & 7) + 3;
  v65.format = HIDWORD(v37);
  v38 = va::va(
          this: &v66,
          fmt: "_physical%sPages0",
          a3: v34,
          a4: v37,
          a5: v36,
          a6: v48,
          a7: v51,
          a8: v54,
          a9: v57,
          a10: v60,
          a11: v63);
  v40 = idImageManager::ScratchImage(this: globalImages, _name: v38->buffer, imgOpts: &v65);
  this->physicalPagesImage0 = v40;
  if ( v40->allocationFailed )
  {
    v28 = 0;
LABEL_21:
    this->isDirectMapped = false;
    goto LABEL_22;
  }
  if ( (unsigned __int8)XGComparePixelShaders() == 0 )
    goto LABEL_21;
LABEL_22:
  v41 = this->pageImageCompressed;
  LODWORD(v42) = "olor specular";
  HIDWORD(v39) = name;
  HIDWORD(v42) = -v41;
  LODWORD(v43) = (v41 == 0) - 1;
  HIDWORD(v43) = (v43 & 8) + 3;
  v65.format = HIDWORD(v43);
  v44 = va::va(
          this: &v66,
          fmt: "_physical%sPages2",
          a3: v39,
          a4: v43,
          a5: v42,
          a6: v49,
          a7: v52,
          a8: v55,
          a9: v58,
          a10: v61,
          a11: v64);
  v45 = idImageManager::ScratchImage(this: globalImages, _name: v44->buffer, imgOpts: &v65);
  this->physicalPagesImage2 = v45;
  if ( v45->allocationFailed )
  {
    v28 = 0;
LABEL_25:
    this->isDirectMapped = false;
    goto LABEL_26;
  }
  if ( (unsigned __int8)XGComparePixelShaders() == 0 )
    goto LABEL_25;
LABEL_26:
  this->rpPhysicalFilterParms = rpPhysicalFilterParms_;
  idMem::PopHeap(this: &mem);
  return v28;
}


// ========================================================================
// __unwind$237233_0
// EA  : 0x8297C920
// RVA : 0x0097C920
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_237233_0()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 4352 + 4256));
}


// ========================================================================
// ?CreatePageImagesUpdate@idPhysicalPages@@QAAXPBVidVirtualTexture@@PBUtexturePage_t@@PAU3@PBXPBEAAUpageImagesUpdate_t@@@Z
// EA  : 0x8297C948
// RVA : 0x0097C948
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idPhysicalPages::CreatePageImagesUpdate(
        idPhysicalPages *this,
        idVirtualTexture *vt,
        const texturePage_t *physPage,
        texturePage_t *virtPage,
        const void *pageDataPBO,
        const unsigned __int8 *pageData,
        pageImagesUpdate_t *update)
{
  int physicalPageNum; // r9
  signed int PHYSICAL_PAGES_WIDE; // r10
  signed int v16; // r4
  unsigned int v17; // r3
  int v18; // r10
  bool pageImageCompressed; // r11
  __int16 pageLevel; // r5
  int v21; // r4
  __int64 v22; // r7
  signed int PHYSICAL_PAGES_HIGH; // r27
  __int16 v24; // r8
  int *p_bytePitch; // r11
  int v26; // r6
  int v27; // ctr
  int v28; // r9
  int v29; // r11
  unsigned __int16 v30; // r8
  int v31; // [sp+50h] [-50h]

  memset(Dst: update, Val: 0, Size: sizeof(pageImagesUpdate_t));
  update->physicalPagesPool = idVirtualTexture::GetPhysicalPagesPool(this: vt);
  update->physicalPageNum = physPage->physicalPageNum;
  physicalPageNum = physPage->physicalPageNum;
  PHYSICAL_PAGES_WIDE = this->PHYSICAL_PAGES_WIDE;
  __twllei(PHYSICAL_PAGES_WIDE, 0);
  update->physX = physicalPageNum % PHYSICAL_PAGES_WIDE;
  v16 = this->PHYSICAL_PAGES_WIDE;
  v17 = PHYSICAL_PAGES_WIDE & ~(__ROL4__(physicalPageNum, 1) - 1);
  v18 = physPage->physicalPageNum;
  __twllei(v16, 0);
  update->physY = v18 / v16;
  __twlgei(v17, 0xFFFFFFFF);
  __twlgei(v16 & ~(__ROL4__(v18, 1) - 1), 0xFFFFFFFF);
  if ( pageDataPBO != nullptr || pageData != nullptr )
  {
    pageImageCompressed = this->pageImageCompressed;
    update->pageDataPBO = pageDataPBO;
    update->pageData = pageData;
    update->compressed = pageImageCompressed;
    update->physicalPagesImage0 = this->physicalPagesImage0;
    update->physicalPagesImage1 = this->physicalPagesImage1;
    update->physicalPagesImage2 = this->physicalPagesImage2;
  }
  if ( physPage != virtPage || !virtPage->mapped )
  {
    pageLevel = physPage->pageLevel;
    v21 = 32 * update->physX;
    HIDWORD(v22) = this->PHYSICAL_PAGES_WIDE;
    LODWORD(v22) = vt->header.pagesWide;
    *(float *)&v31 = (float)v22;
    LODWORD(v22) = update->physY;
    PHYSICAL_PAGES_HIGH = this->PHYSICAL_PAGES_HIGH;
    __twllei(HIDWORD(v22), 0);
    __twllei(PHYSICAL_PAGES_HIGH, 0);
    v24 = (32 * (((unsigned __int8)(v31 >> 23) - pageLevel - 127) | ((unsigned __int16)(v21 / SHIDWORD(v22)) << 6)))
        | (32 * (int)v22 / PHYSICAL_PAGES_HIGH);
    LOBYTE(pageLevel) = (32 * (((v31 >> 23) - pageLevel - 127) | ((unsigned __int8)(v21 / SHIDWORD(v22)) << 6)))
                      | (32 * (int)v22 / PHYSICAL_PAGES_HIGH);
    update->pageSpot[2] = pageLevel;
    update->pageSpot[3] = HIBYTE(v24);
    __twlgei(HIDWORD(v22) & ~(__ROL4__(v21, 1) - 1), 0xFFFFFFFF);
    update->pageSpot[1] = HIBYTE(v24);
    __twlgei(PHYSICAL_PAGES_HIGH & ~(__ROL4__(32 * v22, 1) - 1), 0xFFFFFFFF);
    update->pageSpot[0] = pageLevel;
    update->spotX = virtPage->pageX;
    update->spotY = virtPage->pageY;
    update->effectivePageLevel = virtPage->pageLevel - vt->header.numLevels + vt->pageTableImage->opts.numLevels;
    if ( vt_useDirectTextureAccess.valueInteger != 0 )
    {
      p_bytePitch = &update->pageTableImageInfo[0].bytePitch;
      v26 = -108 - (_DWORD)update;
      v27 = 7;
      v28 = 152;
      do
      {
        *(p_bytePitch - 1) = *(int *)((char *)&vt->pageTableImage->__vftable + v28);
        *p_bytePitch = *(int *)((char *)p_bytePitch + v26 + (unsigned int)vt->pageTableImage + 148);
        p_bytePitch[1] = *(int *)((char *)p_bytePitch + 52 - (_DWORD)update + (unsigned int)vt->pageTableImage);
        p_bytePitch[2] = *(int *)((char *)p_bytePitch + v26 + (unsigned int)vt->pageTableImage + 156);
        p_bytePitch += 4;
        v28 = (int)p_bytePitch + 44 - (_DWORD)update;
        --v27;
      }
      while ( v27 != 0 );
    }
    if ( update->pageTableImageInfo[0].bits == nullptr )
      update->pageTableImage = vt->pageTableImage;
    v29 = __ROL4__(virtPage->physicalPageNum, 3);
    v30 = (_cntlzw((char *)physPage - (char *)virtPage) & 0x20) != 0;
    virtPage->mapped = v30;
    *(unsigned __int16 *)((char *)&this->pageHash.pageHashIndex->mapped + v29) = v30;
  }
}


// ========================================================================
// ?GetDirectMappedPhysicalPagePointers@idPhysicalPages@@QBAXHQAPAEQAH@Z
// EA  : 0x8297CBC8
// RVA : 0x0097CBC8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idPhysicalPages::GetDirectMappedPhysicalPagePointers(
        idPhysicalPages *this,
        int physicalPageNum,
        unsigned __int8 **physicalPagePtr,
        int *physicalBytePitch)
{
  signed int PHYSICAL_PAGES_WIDE; // r9
  physicalPagesPool_t physicalPagesPool; // r8
  int v6; // r10
  int v7; // r11
  char v8; // r8
  bool v9; // zf
  unsigned __int8 *v10; // r11
  int v11; // r10
  unsigned __int8 *v12; // r9

  PHYSICAL_PAGES_WIDE = this->PHYSICAL_PAGES_WIDE;
  physicalPagesPool = this->physicalPagesPool;
  v6 = (physicalPageNum % PHYSICAL_PAGES_WIDE) << 7 >> 2;
  __twllei(PHYSICAL_PAGES_WIDE, 0);
  __twllei(PHYSICAL_PAGES_WIDE, 0);
  __twlgei(PHYSICAL_PAGES_WIDE & ~(__ROL4__(physicalPageNum, 1) - 1), 0xFFFFFFFF);
  __twlgei(PHYSICAL_PAGES_WIDE & ~(__ROL4__(physicalPageNum, 1) - 1), 0xFFFFFFFF);
  v7 = (physicalPageNum / PHYSICAL_PAGES_WIDE) << 7 >> 2;
  if ( physicalPagesPool == PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY
    || (v9 = physicalPagesPool != PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY2, v8 = 0, !v9) )
  {
    v8 = 1;
  }
  if ( v8 != 0 )
  {
    *physicalPagePtr = nullptr;
    v10 = (unsigned __int8 *)this->physicalPagesImage1->lockRect[0].pBits
        + 16 * v6
        + this->physicalPagesImage1->lockRect[0].Pitch * v7;
    physicalPagePtr[2] = nullptr;
    physicalPagePtr[1] = v10;
    *physicalBytePitch = 0;
    physicalBytePitch[1] = this->physicalPagesImage1->lockRect[0].Pitch;
    physicalBytePitch[2] = 0;
  }
  else
  {
    v12 = (unsigned __int8 *)this->physicalPagesImage0->lockRect[0].pBits
        + 8 * v6
        + this->physicalPagesImage0->lockRect[0].Pitch * v7;
    v11 = 16 * v6;
    *physicalPagePtr = v12;
    physicalPagePtr[1] = (unsigned __int8 *)this->physicalPagesImage1->lockRect[0].pBits
                       + this->physicalPagesImage1->lockRect[0].Pitch * v7
                       + v11;
    physicalPagePtr[2] = (unsigned __int8 *)this->physicalPagesImage2->lockRect[0].pBits
                       + this->physicalPagesImage2->lockRect[0].Pitch * v7
                       + v11;
    *physicalBytePitch = this->physicalPagesImage0->lockRect[0].Pitch;
    physicalBytePitch[1] = this->physicalPagesImage1->lockRect[0].Pitch;
    physicalBytePitch[2] = this->physicalPagesImage2->lockRect[0].Pitch;
  }
}


// ========================================================================
// ?ValidateCache_f@idVirtualTextureSystem@@CAXABVidCmdArgs@@@Z
// EA  : 0x8297CD18
// RVA : 0x0097CD18
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::ValidateCache_f(const idCmdArgs *args)
{
  volatile int *p_sortDone; // r25
  volatile int *v2; // r31
  int v3; // r24
  int v4; // r30
  int v5; // r27
  int v6; // r11
  int v7; // r28
  int v8; // r29
  int v9; // r11
  unsigned int v10; // r4
  int v11; // r10
  int v12; // r5
  int v13; // r11
  signed int v14; // r31
  int v15; // r7
  int v16; // r4
  int v17; // r10
  int v18; // r7
  int v19; // r6
  int v20; // r10
  int v21; // r9
  char **p_data; // r31
  const char *v23; // r3
  bool v24; // zf
  int v25; // [sp+50h] [-8D0h] BYREF
  const char *v26; // [sp+54h] [-8CCh]
  int v27; // [sp+58h] [-8C8h] BYREF
  int v28; // [sp+5Ch] [-8C4h] BYREF
  const char *v29; // [sp+60h] [-8C0h]
  int v30; // [sp+64h] [-8BCh] BYREF
  const char *v31; // [sp+68h] [-8B8h]
  int v32; // [sp+6Ch] [-8B4h] BYREF
  const char *v33; // [sp+70h] [-8B0h]
  int v34; // [sp+74h] [-8ACh] BYREF
  const char *v35; // [sp+78h] [-8A8h]
  _BYTE v36[2208]; // [sp+80h] [-8A0h] BYREF

  v26 = "locked : %4i\n";
  p_sortDone = &virtualTextureSystem.physicalPagesPool[0].unlockedPageList.sortDone;
  v33 = "total  : %4i\n";
  v29 = "unlockedPageListCount + freePageListCount + lockedPages != NUM_PHYSICAL_PAGES";
  v35 = "Bad level: %i\n";
  v31 = "Bad pageSource\n";
  do
  {
    v2 = p_sortDone - 17;
    while ( *p_sortDone == 0 )
      Sys_Yield();
    idLib::Printf(fmt: "%s\n", physicalPoolNames[*v2]);
    idLib::Printf(fmt: "------------------------\n");
    v3 = 0;
    v4 = 0;
    v5 = 0;
    memset(Dst: v36, Val: 0, Size: 0x800u);
    v6 = *((_DWORD *)v2 + 25);
    v7 = 0;
    if ( v6 > 0 )
    {
      v8 = 0;
      do
      {
        v9 = v8 + *((_DWORD *)v2 + 1);
        if ( *(_BYTE *)v9 == 0 )
          ++v3;
        if ( *(_BYTE *)(v9 + 1) != 0 )
          ++v5;
        if ( *(int *)(v9 + 16) < 16 )
        {
          v10 = *(unsigned __int8 *)(v9 + 3);
          if ( v10 < 0x10 )
          {
            v11 = 4 * (16 * *(_DWORD *)(v9 + 16) + v10);
            v12 = virtualTextureSystem.feedbackFrameNum
                - *(_DWORD *)(__ROL4__(*(unsigned __int16 *)(v9 + 8), 2) + *((_DWORD *)v2 + 3));
            ++*(_DWORD *)&v36[v11];
            if ( v12 < 3 )
            {
              ++v4;
              v13 = 4 * (16 * *(_DWORD *)(v9 + 16) + v10);
              ++*(_DWORD *)&v36[v13 + 1024];
            }
          }
          else
          {
            idLib::Printf(fmt: v35);
          }
        }
        else
        {
          idLib::Printf(fmt: v31);
        }
        v6 = *((_DWORD *)v2 + 25);
        ++v7;
        v8 += 72;
      }
      while ( v7 < v6 );
    }
    if ( *((_DWORD *)v2 + 8) + *((_DWORD *)v2 + 14) - *((_DWORD *)v2 + 7) - *((_DWORD *)v2 + 13) + v5 + 2 != v6 )
      idLib::Warning(fmt: v29);
    idLib::Printf(fmt: v33, *((_DWORD *)v2 + 25));
    idLib::Printf(fmt: v26, v5);
    idLib::Printf(fmt: "current: %4i\n", v4);
    idLib::Printf(fmt: "free   : %4i\n", v3);
    idPhysicalPageHash::HashStats(
      this: (idPhysicalPageHash *)(v2 + 4),
      total: &v25,
      c0: &v27,
      c1: &v28,
      c2: &v30,
      c3: &v32,
      cX: &v34);
    v14 = v25;
    if ( v25 == 0 )
    {
      v14 = 1;
      v25 = 1;
    }
    idLib::Printf(fmt: "%4i %% empty hash table entries\n", (unsigned int)(100 * v27 + 1024) >> 11);
    v15 = 100 * v28 + v14 / 2;
    __twllei(v14, 0);
    __twlgei(v14 & ~(__ROL4__(v15, 1) - 1), 0xFFFFFFFF);
    idLib::Printf(fmt: "%4i %% pages 0 steps down the hash chain\n", v15 / v14);
    v16 = v30;
    __twllei(v14, 0);
    v17 = 100 * v16 + v14 / 2;
    __twlgei(v14 & ~(__ROL4__(v17, 1) - 1), 0xFFFFFFFF);
    idLib::Printf(fmt: "%4i %% pages 1 step down the hash chain\n", v17 / v14);
    v18 = v32;
    __twllei(v14, 0);
    v19 = 100 * v18 + v14 / 2;
    __twlgei(v14 & ~(__ROL4__(v19, 1) - 1), 0xFFFFFFFF);
    idLib::Printf(fmt: "%4i %% pages 2 steps down the hash chain\n", v19 / v14);
    v20 = v34;
    __twllei(v14, 0);
    v21 = 100 * v20 + v14 / 2;
    __twlgei(v14 & ~(__ROL4__(v21, 1) - 1), 0xFFFFFFFF);
    idLib::Printf(fmt: "%4i %% pages > 2 steps down the hash chain\n", v21 / v14);
    idLib::Printf(fmt: "------------------------\n");
    p_sortDone += 34;
  }
  while ( (int)p_sortDone < (int)&virtualTextureSystem.containerPath[65] );
  p_data = &virtualTextureSystem.vts[1].pageFilePath.data;
  do
  {
    if ( **p_data != 0 )
    {
      idLib::Printf(fmt: "Validating %s page table... ", *p_data);
      v24 = (unsigned __int8)idVirtualTexture::ValidatePageTable(this: (idVirtualTexture *)(p_data - 21)) != 0;
      v23 = "successful\n";
      if ( !v24 )
        v23 = "failed\n";
      idLib::Printf(fmt: v23);
    }
    p_data += 312;
  }
  while ( (int)p_data < (int)&virtualTextureSystem.numReferencedVirtualTextures );
}


// ========================================================================
// ?VisualBenchmark_f@idVirtualTextureSystem@@CAXABVidCmdArgs@@@Z
// EA  : 0x8297D0F8
// RVA : 0x0097D0F8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::VisualBenchmark_f(const idCmdArgs *args)
{
  if ( args->argc > 1 )
    atol(nptr: args->argv[1]);
}


// ========================================================================
// ?CreatePhysicalImages@idVirtualTextureSystem@@QAA_N_N00@Z
// EA  : 0x8297D110
// RVA : 0x0097D110
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

BOOL __fastcall idVirtualTextureSystem::CreatePhysicalImages(
        idVirtualTextureSystem *this,
        bool mapHasSpecularPages_,
        bool mapHasDiffuseOnlyPages_,
        bool mapHasDiffuseOnly2Pages_)
{
  bool *p_mapHasSpecularPages; // r17
  bool *p_mapHasDiffuseOnlyPages; // r16
  bool *p_mapHasDiffuseOnly2Pages; // r15
  BOOL v8; // r9
  BOOL v9; // r11
  BOOL v10; // r11
  unsigned __int8 v11; // r20
  int i; // r18
  idImage *physicalPagesImage0; // r3
  idImage *physicalPagesImage1; // r3
  idImage *physicalPagesImage2; // r3
  idImage *v16; // r3
  idImage *v17; // r3
  idImage *v18; // r3
  idImage *v19; // r3
  idImage *v20; // r3
  idImage *v21; // r3
  int v23; // [sp+50h] [-B0h] BYREF
  int v24; // [sp+54h] [-ACh] BYREF
  int v25; // [sp+58h] [-A8h] BYREF
  int v26; // [sp+5Ch] [-A4h] BYREF
  int v27; // [sp+60h] [-A0h] BYREF
  int v28; // [sp+64h] [-9Ch] BYREF
  int v29; // [sp+68h] [-98h] BYREF
  int v30; // [sp+6Ch] [-94h] BYREF

  p_mapHasSpecularPages = &this->mapHasSpecularPages;
  p_mapHasDiffuseOnlyPages = &this->mapHasDiffuseOnlyPages;
  p_mapHasDiffuseOnly2Pages = &this->mapHasDiffuseOnly2Pages;
  this->mapHasSpecularPages = mapHasSpecularPages_;
  this->mapHasDiffuseOnlyPages = mapHasDiffuseOnlyPages_;
  this->mapHasDiffuseOnly2Pages = mapHasDiffuseOnly2Pages_;
  v29 = 128;
  v30 = 128;
  ParseDimensions(str: vt_pageImageSizeVmtr.valueString.data, width: &v29, height: &v30);
  v8 = *p_mapHasSpecularPages;
  v24 = 128;
  v23 = 128;
  if ( v8 )
    ParseDimensions(str: vt_pageImageSizeUnique.valueString.data, width: &v24, height: &v23);
  v9 = *p_mapHasDiffuseOnlyPages;
  v26 = 128;
  v25 = 128;
  if ( v9 )
    ParseDimensions(str: vt_pageImageSizeUniqueDiffuseOnly.valueString.data, width: &v26, height: &v25);
  v10 = *p_mapHasDiffuseOnly2Pages;
  v28 = 128;
  v27 = 128;
  if ( v10 )
    ParseDimensions(str: vt_pageImageSizeUniqueDiffuseOnly2.valueString.data, width: &v28, height: &v27);
  v11 = 0;
  for ( i = 0; i < 2; ++i )
  {
    if ( i != 0 )
    {
      if ( *p_mapHasSpecularPages )
      {
        v24 = 4096;
        v23 = 4096;
      }
      if ( *p_mapHasDiffuseOnlyPages )
      {
        v26 = 4096;
        v25 = 4096;
      }
      if ( *p_mapHasDiffuseOnly2Pages )
      {
        v28 = 4096;
        v27 = 4096;
      }
    }
    physicalPagesImage0 = this->physicalPagesPool[1].physicalPagesImage0;
    if ( physicalPagesImage0 != nullptr )
      idImage::PurgeImage(this: physicalPagesImage0);
    physicalPagesImage1 = this->physicalPagesPool[1].physicalPagesImage1;
    if ( physicalPagesImage1 != nullptr )
      idImage::PurgeImage(this: physicalPagesImage1);
    physicalPagesImage2 = this->physicalPagesPool[1].physicalPagesImage2;
    if ( physicalPagesImage2 != nullptr )
      idImage::PurgeImage(this: physicalPagesImage2);
    this->physicalPagesPool[1].isDirectMapped = false;
    v16 = this->physicalPagesPool[2].physicalPagesImage0;
    if ( v16 != nullptr )
      idImage::PurgeImage(this: v16);
    v17 = this->physicalPagesPool[2].physicalPagesImage1;
    if ( v17 != nullptr )
      idImage::PurgeImage(this: v17);
    v18 = this->physicalPagesPool[2].physicalPagesImage2;
    if ( v18 != nullptr )
      idImage::PurgeImage(this: v18);
    this->physicalPagesPool[2].isDirectMapped = false;
    v19 = this->physicalPagesPool[3].physicalPagesImage0;
    if ( v19 != nullptr )
      idImage::PurgeImage(this: v19);
    v20 = this->physicalPagesPool[3].physicalPagesImage1;
    if ( v20 != nullptr )
      idImage::PurgeImage(this: v20);
    v21 = this->physicalPagesPool[3].physicalPagesImage2;
    if ( v21 != nullptr )
      idImage::PurgeImage(this: v21);
    this->physicalPagesPool[3].isDirectMapped = false;
    if ( (unsigned __int8)idPhysicalPages::CreatePhysicalImages(
                            this: &this->physicalPagesPool[1],
                            pool: PHYSICAL_PAGES_POOL_UNIQUE,
                            name: "Unique",
                            pageImageWidth: v24,
                            pageImageHeight: v23,
                            rpPhysicalFilterParms_: &rpPhysicalUniqueFilterParms) == 0 )
      v11 = 1;
    if ( (unsigned __int8)idPhysicalPages::CreatePhysicalImages(
                            this: &this->physicalPagesPool[2],
                            pool: PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY,
                            name: "UniqueDiffuseOnly",
                            pageImageWidth: v26,
                            pageImageHeight: v25,
                            rpPhysicalFilterParms_: &rpPhysicalUniqueDiffuseOnlyFilterParms) == 0 )
      v11 = 1;
    if ( (unsigned __int8)idPhysicalPages::CreatePhysicalImages(
                            this: &this->physicalPagesPool[3],
                            pool: PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY2,
                            name: "UniqueDiffuseOnly2",
                            pageImageWidth: v28,
                            pageImageHeight: v27,
                            rpPhysicalFilterParms_: &rpPhysicalUniqueDiffuseOnly2FilterParms) == 0 )
      v11 = 1;
    if ( v11 == 0 )
      break;
  }
  this->feedbackFrameNum += 1024;
  return (_cntlzw(v11) & 0x20) != 0;
}


// ========================================================================
// ?VirtualTextureInfo_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8297D3E8
// RVA : 0x0097D3E8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall VirtualTextureInfo_f(const idCmdArgs *args)
{
  idImage **p_physicalPagesImage1; // r31
  int v2; // r11
  char v3; // r11
  bool v4; // zf
  unsigned int v5; // r29
  int v6; // r30
  idImage **p_pageTableImage; // r31
  double v8; // r4

  p_physicalPagesImage1 = &virtualTextureSystem.physicalPagesPool[0].physicalPagesImage1;
  do
  {
    if ( *p_physicalPagesImage1 != nullptr )
    {
      (*p_physicalPagesImage1)->Print(this: *p_physicalPagesImage1);
      v2 = (int)*(p_physicalPagesImage1 - 27);
      if ( v2 == 2 || (v4 = v2 != 3, v3 = 0, !v4) )
        v3 = 1;
      if ( v3 == 0 )
      {
        (*(p_physicalPagesImage1 - 1))->Print(this: *(p_physicalPagesImage1 - 1));
        p_physicalPagesImage1[1]->Print(this: p_physicalPagesImage1[1]);
      }
    }
    p_physicalPagesImage1 += 34;
  }
  while ( (int)p_physicalPagesImage1 < (int)&virtualTextureSystem.containerPath[105] );
  idLib::Printf(fmt: "vmtr path: %s\n", virtualTextureSystem.vmtrPath);
  idLib::Printf(fmt: "num vmtrs: %i\n", virtualTextureSystem.vmtrs.num);
  v5 = 0;
  v6 = 1;
  p_pageTableImage = &virtualTextureSystem.vts[1].pageTableImage;
  do
  {
    if ( *p_pageTableImage != nullptr )
    {
      v5 += idImage::StorageSize(this: *p_pageTableImage);
      idLib::Printf(fmt: "\nvirtual texture %i:\n", v6);
      idVirtualTexture::Print(this: (idVirtualTexture *)(p_pageTableImage - 294));
    }
    p_pageTableImage += 312;
    ++v6;
  }
  while ( (int)p_pageTableImage < (int)&virtualTextureSystem.referencedVTPath[4][64] );
  v8 = (float)((float)__SPAIR64__(&unk_821C0000, v5) * (float)0.00000095367432);
  idLib::Printf(fmt: (const char *)HIDWORD(v8), LODWORD(v8));
}


// ========================================================================
// ?OpenCachedPagesFile@idVirtualTextureSystem@@QAAPAVidFile@@PBD@Z
// EA  : 0x8297D530
// RVA : 0x0097D530
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

idFile *__fastcall idVirtualTextureSystem::OpenCachedPagesFile(idVirtualTextureSystem *this, const char *path)
{
  int v4; // r29
  int v5; // r31
  idFile *file; // r3
  const char *v7; // r3
  int v8; // r31
  idFile *v9; // r30
  int v10; // r3

  idLib::Printf(fmt: "OpenCachedPagesFile: %s\n", path);
  v4 = 0;
  if ( this->cachedPagesFiles.num <= 0 )
  {
LABEL_6:
    v8 = Sys_Milliseconds();
    v9 = fileSystem->OpenFileRead(this: fileSystem, a2: path, a3: 0, a4: 1);
    v10 = Sys_Milliseconds();
    idLib::Printf(fmt: "%d milliseconds to open %s\n", v10 - v8, path);
    return v9;
  }
  else
  {
    v5 = 0;
    while ( 1 )
    {
      file = this->cachedPagesFiles.list[v5].file;
      if ( file != nullptr )
      {
        v7 = file->GetName(this: file);
        if ( idStr::IcmpPath(s1: path, s2: v7) == 0 )
          return this->cachedPagesFiles.list[v4].file;
      }
      ++v4;
      ++v5;
      if ( v4 >= this->cachedPagesFiles.num )
        goto LABEL_6;
    }
  }
}


// ========================================================================
// ?OpenInstalledCachedPagesFile@idVirtualTextureSystem@@QAAPAVidFile@@PBD@Z
// EA  : 0x8297D618
// RVA : 0x0097D618
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

idFile *__fastcall idVirtualTextureSystem::OpenInstalledCachedPagesFile(idVirtualTextureSystem *this, const char *path)
{
  int v4; // r29
  int i; // r30
  cachedPageFile_t *v6; // r11
  const char *v7; // r3

  idLib::Printf(fmt: "OpenInstalledCachedPagesFile: %s\n", path);
  v4 = 0;
  if ( this->cachedPagesFiles.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v6 = &this->cachedPagesFiles.list[i];
    if ( v6->fileInstalled != nullptr )
    {
      v7 = v6->file->GetName(this: v6->file);
      if ( idStr::IcmpPath(s1: path, s2: v7) == 0 )
        break;
    }
    if ( ++v4 >= this->cachedPagesFiles.num )
      return nullptr;
  }
  return this->cachedPagesFiles.list[v4].fileInstalled;
}


// ========================================================================
// ?CloseCachedPagesFile@idVirtualTextureSystem@@QAAXPAVidFile@@@Z
// EA  : 0x8297D6C0
// RVA : 0x0097D6C0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::CloseCachedPagesFile(idVirtualTextureSystem *this, idFile *file)
{
  int v4; // r29
  int v5; // r31
  const char *v6; // r27
  const char *v7; // r3

  v4 = 0;
  if ( this->cachedPagesFiles.num <= 0 )
  {
LABEL_5:
    if ( file != nullptr )
      ((void (__fastcall *)(idFile *, int))file->dtr_idFile)(a1: file, a2: 1);
  }
  else
  {
    v5 = 0;
    while ( 1 )
    {
      v6 = this->cachedPagesFiles.list[v5].file->GetName(this: this->cachedPagesFiles.list[v5].file);
      v7 = file->GetName(this: file);
      if ( idStr::IcmpPath(s1: v7, s2: v6) == 0 )
        break;
      ++v4;
      ++v5;
      if ( v4 >= this->cachedPagesFiles.num )
        goto LABEL_5;
    }
  }
}


// ========================================================================
// ?VirtualTextureForMaterial@idVirtualTextureSystem@@QAAPAVidVirtualTexture@@PBVidMaterial@@@Z
// EA  : 0x8297D768
// RVA : 0x0097D768
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

idVirtualTexture *__fastcall idVirtualTextureSystem::VirtualTextureForMaterial(
        idVirtualTextureSystem *this,
        const idMaterial *mtr)
{
  const char *pageFileName; // r27
  physicalPagesPool_t physicalPagesPool; // r26
  int v6; // r30
  idVirtualTexture *v7; // r31
  int v8; // r11
  char **p_data; // r10
  int Integer; // r3
  __int16 layoutVersion; // r9
  idVirtualTexture *v13; // r31
  int v14; // r3
  char v15; // r3
  char *containerPath; // r5
  int v17; // r11
  char v18[320]; // [sp+50h] [-140h] BYREF

  pageFileName = mtr->pageFileName;
  if ( pageFileName == nullptr || *pageFileName == 0 )
    return nullptr;
  physicalPagesPool = mtr->physicalPagesPool;
  v6 = 1;
  v7 = &this->vts[1];
  do
  {
    if ( idStr::Icmp(s1: v7->baseName.data, s2: pageFileName) == 0
      && v7->physicalPages != nullptr
      && idVirtualTexture::GetPhysicalPagesPool(this: v7) == physicalPagesPool )
    {
      if ( v6 > 1 && v7->layoutVersion == 0 )
      {
        Integer = idParmBlock::GetInteger(this: &mtr->parmBlock, parm: (const idDeclRenderParm *)rpLandLayoutVersion.r);
        layoutVersion = v7->header.layoutVersion;
        v7->layoutVersion = Integer;
        if ( layoutVersion != 0 && Integer != 0 && Integer != layoutVersion )
          idLib::Warning(
            fmt: "Material layoutVersion (%d) differs from Virtual Texture layoutVersion (%d).",
            Integer,
            layoutVersion);
      }
      return v7;
    }
    ++v6;
    ++v7;
  }
  while ( v6 < 16 );
  v8 = 2;
  p_data = &this->vts[3].pageFilePath.data;
  while ( **(p_data - 312) != 0 )
  {
    if ( **p_data == 0 )
    {
      ++v8;
      break;
    }
    v8 += 2;
    p_data += 624;
    if ( v8 >= 16 )
      break;
  }
  if ( v8 == 16 )
    idLib::Error(fmt: "idVirtualTextureSystem::VirtualTextureForMaterial: PAGESOURCE_TOTAL exceeded");
  v13 = &this->vts[v8];
  v14 = idParmBlock::GetInteger(this: &mtr->parmBlock, parm: (const idDeclRenderParm *)rpLandLayoutVersion.r);
  v13->layoutVersion = v14;
  if ( vt_packPageFiles.valueInteger != 2 || com_production.valueInteger != 0 )
    sprintf_0(string: v18, format: "%s/%s_v%03d.pages", vt_filePath.valueString.data, pageFileName, v14);
  else
    sprintf_0(string: v18, format: "%s/%s.pages", vt_filePath.valueString.data, pageFileName);
  v15 = 0;
  containerPath = this->containerPath;
  v17 = 0;
  if ( this->containerPath[0] != 0 )
  {
    do
      ++v17;
    while ( containerPath[v17] != 0 );
    if ( v17 != 0 && vt_containers.valueInteger != 0 )
      v15 = idVirtualTexture::SetSource(
              this: v13,
              baseName_: pageFileName,
              pageFilePath_: containerPath,
              physicalPagesPool);
  }
  if ( v15 == 0
    && (unsigned __int8)idVirtualTexture::SetSource(
                          this: v13,
                          baseName_: pageFileName,
                          pageFilePath_: v18,
                          physicalPagesPool) == 0 )
  {
    idLib::Error(fmt: "Couldn't open page file '%s'", v18);
  }
  idVirtualTextureSystem::AddToReferencedVirtualTextures(this, name: pageFileName, path: v18);
  return v13;
}


// ========================================================================
// ?LoadMaterialPagesInBackground@idVirtualTextureSystem@@QAAXPBVidMaterial@@H@Z
// EA  : 0x8297D9F0
// RVA : 0x0097D9F0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::LoadMaterialPagesInBackground(
        idVirtualTextureSystem *this,
        const idMaterial *mtr,
        char lod)
{
  __int64 v3; // r10
  int VIRTUAL_TEXELS_WIDE; // r11
  double v5; // fp4
  int v6; // fp3
  int v7; // r31
  int v8; // r8
  int v9; // r30
  int v10; // r4
  int v11; // r10
  unsigned int *p_currentPageIndices; // r9
  int v13; // r6
  int v14; // r27
  unsigned __int8 *v15; // r11
  int back_chain_4; // [sp+4h] [-5Ch]

  if ( vt_skipExplicitPageFeedback.valueInteger == 0 )
  {
    HIDWORD(v3) = (LODWORD(mtr->virtualMapping.z)
                 | LODWORD(mtr->virtualMapping.w)
                 | LODWORD(mtr->virtualMapping.y)
                 | LODWORD(mtr->virtualMapping.x))
                & 0x7FFFFFFF;
    if ( HIDWORD(v3) != 0 )
    {
      VIRTUAL_TEXELS_WIDE = this->vmtrMega->VIRTUAL_TEXELS_WIDE;
      __twllei(120 << lod, 0);
      __twllei(120 << lod, 0);
      LODWORD(v3) = VIRTUAL_TEXELS_WIDE;
      __twllei(120 << lod, 0);
      __twllei(120 << lod, 0);
      v5 = (float)((float)v3 * mtr->virtualMapping.z);
      v6 = (int)(float)((float)v3 * mtr->virtualMapping.y);
      back_chain_4 = (int)(float)((float)v3 * mtr->virtualMapping.w);
      v7 = (int)(float)((float)v3 * mtr->virtualMapping.x) + (int)v5;
      v8 = back_chain_4 / (120 << lod);
      v9 = (v6 + back_chain_4) / (120 << lod);
      __twlgei((120 << lod) & ~(__ROL4__((int)v5, 1) - 1), 0xFFFFFFFF);
      v10 = v7 / (120 << lod);
      __twlgei((120 << lod) & ~(__ROL4__(v7, 1) - 1), 0xFFFFFFFF);
      __twlgei((120 << lod) & ~(__ROL4__(v6 + back_chain_4, 1) - 1), 0xFFFFFFFF);
      __twlgei((120 << lod) & ~(__ROL4__(back_chain_4, 1) - 1), 0xFFFFFFFF);
      for ( ; v8 <= v9; ++v8 )
      {
        v11 = (int)v5 / (120 << lod);
        if ( v11 <= v10 )
        {
          p_currentPageIndices = &this->currentPageIndices;
          do
          {
            v13 = 4 * this->numExplicitPages[*p_currentPageIndices];
            if ( v13 >= 0x2000 )
              break;
            v14 = ((unsigned int)v8 >> 4) & 0xF0 | ((unsigned int)v11 >> 8) & 0xF;
            ++this->numExplicitPages[*p_currentPageIndices];
            v15 = &this->explicitPages[*p_currentPageIndices][v13];
            *v15 = v11++;
            v15[1] = v8;
            v15[2] = v14;
            v15[3] = lod & 0xF | 0x10;
          }
          while ( v11 <= v10 );
        }
      }
    }
  }
}


// ========================================================================
// ?ShowFeedbackAnalysis@idVirtualTextureSystem@@AAAXPBXHHH@Z
// EA  : 0x8297DBC8
// RVA : 0x0097DBC8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::ShowFeedbackAnalysis(
        idVirtualTextureSystem *this,
        unsigned __int8 *data,
        int width,
        int height,
        int bytePitch)
{
  int v6; // r26
  unsigned __int8 *v7; // r31
  int i; // r30
  unsigned __int8 *v9; // r11
  int j; // ctr
  int v11; // r9
  int v12; // r10
  unsigned int v13; // r28
  int v14; // r6
  int v15; // r8
  int v16; // r4
  unsigned int v17; // r3
  unsigned int *v18; // r9
  int v19; // r10
  int v20; // r30
  int v21; // r24
  unsigned int *v22; // r25
  int v23; // r27
  int v24; // r28
  idVirtualMaterial *v25; // r5
  int v26; // r9
  int allocY; // r10
  int allocX; // r11
  int allocHeight; // r10
  int allocWidth; // r11
  int v31; // r7
  int k; // r11
  int v33; // r10
  int v34; // r9
  _DWORD v35[2]; // [sp+50h] [-80h] BYREF
  _DWORD v36[30]; // [sp+58h] [-78h] BYREF

  v6 = 0;
  if ( data != nullptr )
  {
    if ( height > 0 )
    {
      v7 = data;
      for ( i = height; i != 0; --i )
      {
        v9 = v7;
        if ( width > 0 )
        {
          for ( j = width; j != 0; --j )
          {
            v11 = v9[2];
            v12 = 0;
            v13 = v9[3];
            v14 = ((16 * v11) & 0xF00) + v9[1];
            v15 = ((v11 << 8) & 0xF00) + *v9;
            v16 = v13 & 0xF;
            v17 = v13 >> 4;
            if ( v6 > 0 )
            {
              v18 = &uniques[0][1];
              do
              {
                if ( *(v18 - 1) == v15 && *v18 == v14 && v18[1] == v16 && v18[2] == v17 )
                  break;
                ++v12;
                v18 += 5;
              }
              while ( v12 < v6 );
            }
            if ( v12 == v6 && v6 < 2000 )
            {
              v19 = v12;
              ++v6;
              uniques[v19][0] = v15;
              uniques[v19][1] = v14;
              uniques[v19][2] = v16;
              uniques[v19][3] = v17;
              uniques[v19][4] = *(_DWORD *)v9;
            }
            v9 += 4;
          }
        }
        v7 += bytePitch;
      }
    }
    if ( v6 > 0 )
    {
      v20 = 0;
      v21 = v6;
      v22 = &uniques[0][1];
      do
      {
        idLib::Printf(fmt: "0x%8x %4i %4i %4i %4i ", v22[3], *(v22 - 1), *v22, v22[1], v22[2]);
        if ( v22[2] == 1 )
        {
          v23 = 0;
          if ( this->vmtrs.num > 0 )
          {
            v24 = 0;
            do
            {
              v25 = this->vmtrs.list[v24];
              v26 = v25->flags & 2;
              if ( v26 != 0 )
                allocY = v25->allocY;
              else
                allocY = v25->allocY + 16;
              allocX = v25->allocX;
              if ( v26 == 0 )
                allocX += 16;
              v35[0] = allocX;
              v35[1] = allocY;
              if ( v26 != 0 )
                allocHeight = v25->allocHeight;
              else
                allocHeight = v25->allocHeight - 32;
              allocWidth = v25->allocWidth;
              if ( v26 == 0 )
                allocWidth -= 32;
              v36[0] = allocWidth;
              v31 = 0;
              v36[1] = allocHeight;
              for ( k = 0; k < 2; ++k )
              {
                v33 = v35[k];
                v34 = uniques[v20][v31];
                if ( (v36[k] + v33 - 1) / 120 < v34 )
                  break;
                if ( v33 / 120 > v34 )
                  break;
                ++v31;
              }
              if ( v31 == 2 )
                idLib::Printf(fmt: "%s ", v25->materialName.str);
              ++v23;
              ++v24;
            }
            while ( v23 < this->vmtrs.num );
          }
        }
        idLib::Printf(fmt: "\n");
        --v21;
        v22 += 5;
        ++v20;
      }
      while ( v21 != 0 );
    }
    idLib::Printf(fmt: "%i unique base pages\n", v6);
  }
}


// ========================================================================
// ?SubmitTranscodeJob@idVirtualTextureSystem@@AAAXPAVidParallelJobList@@ABUtranscodeParms_t@@H@Z
// EA  : 0x8297DE68
// RVA : 0x0097DE68
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::SubmitTranscodeJob(
        idVirtualTextureSystem *this,
        idParallelJobList *list,
        transcodeParms_t *parms,
        int useTranscodeJobs)
{
  unsigned int LastError; // r3

  if ( vt_skipTranscode.valueInteger == 0 )
  {
    if ( useTranscodeJobs == 1 )
    {
      idParallelJobList::AddJob(
        this: list,
        function: (void (__fastcall *)(void *))parms->TranscodePageFunc,
        data: parms);
    }
    else
    {
      if ( vt_recordTrace.valueInteger != 0 )
      {
        idCVar::SetBool(this: &vt_recordTrace, newValue: false, force: true);
        LastError = GetLastError();
        idLib::Printf(fmt: "BeginTraceRecording: error %d\n", LastError);
      }
      parms->TranscodePageFunc(a1: parms);
    }
  }
}


// ========================================================================
// ?LogMetrics@idVirtualTextureSystem@@QAAXXZ
// EA  : 0x8297DF10
// RVA : 0x0097DF10
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::LogMetrics(idVirtualTextureSystem *this)
{
  idSysMutex *p_metricMutex; // r30

  if ( com_logMetrics.valueInteger != 0 )
  {
    p_metricMutex = &this->metricMutex;
    if ( Sys_MutexLock(handle: &this->metricMutex.handle, blocking: false) )
    {
      idGaugeMetric::CheckPushState(this: &this->vmtrTotalPagesMetric);
      idGaugeMetric::CheckPushState(this: &this->vmtrBiasMetric);
      idGaugeMetric::CheckPushState(this: &this->specTotalPagesMetric);
      idGaugeMetric::CheckPushState(this: &this->specBiasMetric);
      idGaugeMetric::CheckPushState(this: &this->diffuseTotalPagesMetric);
      idGaugeMetric::CheckPushState(this: &this->diffuseBiasMetric);
      Sys_MutexUnlock(handle: &p_metricMutex->handle);
    }
  }
}


// ========================================================================
// ?StreamFeedback@idVirtualTextureSystem@@AAAXPBUpageIndices_t@@@Z
// EA  : 0x8297DFC8
// RVA : 0x0097DFC8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idVirtualTextureSystem::StreamFeedback(
        idVirtualTextureSystem *this,
        const pageIndices_t *transcodePageIndices,
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
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27)
{
  __int64 v27; // r4
  int v28; // r21
  int v29; // r31
  int v30; // r27
  char v31; // r18
  int v32; // ctr
  _QWORD *v33; // r20
  __int128 v34; // r10 OVERLAPPED
  int v35; // r11
  unsigned __int64 v36; // r3
  int v37; // r26
  int v38; // r29
  int v39; // r30
  unsigned int v40; // r10
  unsigned int v41; // r3
  int v42; // r25
  unsigned int v43; // r9
  _DWORD *v44; // r4
  int v45; // r7
  int v46; // r6
  int v47; // r5
  unsigned int v48; // r9
  int v49; // r8
  int v50; // r11
  int v51; // r9
  int v52; // r8
  unsigned int v53; // r7
  int v54; // r8
  int v55; // r11
  int v56; // r9
  int v57; // r11
  int v58; // r9
  int v59; // r8
  int v60; // r11
  int v61; // r9
  __int64 v62; // r11 OVERLAPPED
  int v63; // r8
  unsigned int v64; // r30
  __int64 v65; // r9
  signed int v66; // r28
  signed int v67; // r6
  int *v68; // r31
  unsigned int *v69; // r9
  int v70; // r3
  char v71; // r7
  int v72; // r5
  int v73; // r10
  int v74; // r11
  signed int v75; // r8
  int v76; // r10

  v27 = ((__int64 (*)(void))RtlCheckStack12)();
  v28 = HIDWORD(v27);
  v29 = v27;
  v30 = 0;
  memset(Dst: &STACK[0xD0B0], Val: -1, Size: 0x1000u);
  if ( vt_usePageFileCache.valueInteger == 0 || (v31 = 1, vt_skipStreaming.valueInteger != 0) )
    v31 = 0;
  if ( *(int *)(v29 + 4) > 0 )
  {
    v32 = *(_DWORD *)(v29 + 4);
    v33 = (_QWORD *)(v29 + 40);
    do
    {
      *((_QWORD *)&v34 + 1) = *v33;
      *(_QWORD *)((char *)&v34 + 4) = *v33 >> 28;
      v35 = BYTE11(v34) & 0xF;
      *(_QWORD *)((char *)&v34 + 12) = (unsigned __int64)v34 >> 24;
      v36 = (unsigned __int64)v34 >> 13;
      *(_QWORD *)((char *)&v34 + 4) = DWORD2(v34);
      v37 = BYTE7(v34) & 0x1F;
      v38 = BYTE3(v34) & 0xF;
      v39 = *(_DWORD *)(((unsigned __int64)v34 >> 2 >> 32) + v28);
      v40 = ((unsigned __int64)v34 >> 2) & 0x7FF;
      v41 = v36 & 0x7FF;
      v42 = WORD5(v34);
      if ( v39 != 0 )
      {
        v43 = *(unsigned __int16 *)(2 * (v38 + 344) + v39);
        if ( v40 < v43 && v41 < v43 )
        {
          v44 = *(_DWORD **)(v39 + 1168);
          v45 = 16 * v35;
          v46 = v44[4];
          v47 = v44[5];
          v48 = 1664525 * ((((v38 << 11) | v41) << 11) | v40) + 1013904223;
          v49 = (((((16 * v35) | v38) << 11) | v41) << 11) | v40;
          v50 = *(unsigned __int16 *)(2 * (((((v48 >> 11) ^ v48) >> 11) ^ v48) & v46) + v47);
          if ( v50 == 0xFFFF )
            goto LABEL_12;
          while ( 1 )
          {
            v51 = 8 * v50 + v44[6];
            if ( *(_DWORD *)v51 == v49 )
              break;
            v50 = *(unsigned __int16 *)(v51 + 6);
            if ( v50 == 0xFFFF )
              goto LABEL_12;
          }
          v57 = __ROL4__(*(unsigned __int16 *)(v51 + 4), 16) | v50;
          if ( v57 == -1 )
          {
LABEL_12:
            if ( v38 < (unsigned int)(*(__int16 *)(v39 + 20) - 1) && v31 != 0 )
            {
              v52 = (v45 | (v38 + 1)) << 11;
              v53 = 1664525 * (((((v38 + 1) << 11) | (v41 >> 1)) << 11) | (v40 >> 1)) + 1013904223;
              v54 = ((v52 | (v41 >> 1)) << 11) | (v40 >> 1);
              v55 = *(unsigned __int16 *)(2 * (((((v53 >> 11) ^ v53) >> 11) ^ v53) & v46) + v47);
              if ( v55 != 0xFFFF )
              {
                while ( 1 )
                {
                  v56 = 8 * v55 + v44[6];
                  if ( *(_DWORD *)v56 == v54 )
                    break;
                  v55 = *(unsigned __int16 *)(v56 + 6);
                  if ( v55 == 0xFFFF )
                    goto LABEL_50;
                }
                v60 = __ROL4__(*(unsigned __int16 *)(v56 + 4), 16) | v55;
                if ( v60 != -1 && (v60 & 0xFFFF0000) != 0 )
                {
                  v61 = (2 * v41) & 2 | v40 & 1;
                  LODWORD(v62) = 8 * ((unsigned __int16)v60 + ((8 * v60) & 0x7FFF8)) + v44[1];
                  HIDWORD(v62) = *(_DWORD *)(v39 + 28);
                  v63 = (_DWORD)v62 != 0
                      ? *(unsigned __int16 *)(2 * (v61 + 32) + v62) * HIDWORD(v62)
                      : *(unsigned __int16 *)(v39 + 64) * HIDWORD(v62);
                  if ( v63 > 0 )
                  {
                    HIDWORD(v62) *= (_DWORD)v62 != 0 ? *(_DWORD *)(4 * (v61 + 12) + v62) : *(_DWORD *)(v39 + 48);
                    v64 = *(_DWORD *)(v39 + 668) != 0 && v38 >= *(_DWORD *)(v39 + 672)
                        ? *(_DWORD *)(v39 + 668)
                        : *(_DWORD *)(v39 + 664);
                    if ( v64 != 0 )
                    {
                      LODWORD(v62) = v63 + HIDWORD(v62) - 1;
                      v65 = v62 >> 16;
                      v67 = *(__int64 *)((char *)&v62 + 4) >> 16;
                      v66 = v62 >> 16;
                      if ( v67 <= v66 )
                      {
                        v68 = &a27 + v30 - 1;
                        v69 = &STACK[0xE0B4] + 4 * v30 - 2;
                        do
                        {
                          v70 = (4 * v67) & 0xFFC;
                          v71 = 0;
                          v72 = *(unsigned int *)((char *)&STACK[0xD0B0] + v70);
                          v73 = v72;
                          if ( v72 != -1 )
                          {
                            while ( 1 )
                            {
                              v74 = 16 * v73;
                              if ( *(&STACK[0xE0B4] + 4 * v73) == v67
                                && *(unsigned int *)((char *)&STACK[0xE0B0] + v74) == v64 )
                              {
                                break;
                              }
                              v73 = *(&a27 + v73);
                              if ( v73 == -1 )
                                goto LABEL_47;
                            }
                            v75 = (v37 << 15) + v42;
                            if ( *(int *)((char *)&STACK[0xE0B8] + v74) > v75 )
                              v75 = *(unsigned int *)((char *)&STACK[0xE0B8] + v74);
                            *(unsigned int *)((char *)&STACK[0xE0B8] + v74) = v75;
                            v76 = 64 << (v38 + 4);
                            if ( *(int *)((char *)&STACK[0xE0BC] + v74) > v76 )
                              v76 = *(unsigned int *)((char *)&STACK[0xE0BC] + v74);
                            *(unsigned int *)((char *)&STACK[0xE0BC] + v74) = v76;
                            v71 = 1;
                          }
LABEL_47:
                          if ( v71 == 0 )
                          {
                            v69[1] = v64;
                            v69[2] = v67;
                            *(unsigned int *)((char *)&STACK[0xD0B0] + v70) = v30;
                            *++v68 = v72;
                            v69[3] = (v37 << 15) + v42;
                            ++v30;
                            v69 += 4;
                            *v69 = 64 << (v38 + 4);
                          }
                          ++v67;
                        }
                        while ( v67 <= v66 );
                      }
                    }
                  }
                }
              }
            }
          }
          else if ( (v57 & 0xFFFF0000) != 0 )
          {
            v58 = (4 * v57) & 0x3FFFC;
            v59 = *(_DWORD *)(v28 + 50256);
            *(_DWORD *)(v44[2] + v58) = v37;
            *(_DWORD *)(v44[3] + v58) = v59;
          }
        }
      }
LABEL_50:
      ++v33;
      --v32;
    }
    while ( v32 != 0 );
    if ( v30 != 0 )
    {
      idStreamFileCache::BatchRequestCacheLines(
        this: streamFileCache,
        requests: (const cacheLineRequest_t *)&STACK[0xE0B0],
        numRequests: v30);
      idStreamFileCache::SignalWork(this: streamFileCache);
    }
  }
}


// ========================================================================
// ?SyncFeedback@idVirtualTextureSystem@@QAAXXZ
// EA  : 0x8297E450
// RVA : 0x0097E450
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::SyncFeedback(idVirtualTextureSystem *this)
{
  int v2; // r27
  int *p_currentTranscodeJobList; // r30
  char *v4; // r6
  char *v5; // r31
  int v6; // r11

  if ( this->feedbackBuffer != nullptr )
  {
    idVirtualTextureSystem::WaitForLastAnalyzeFeedback(this);
    v2 = 2;
    p_currentTranscodeJobList = &this->currentTranscodeJobList;
    do
    {
      idParallelJobList::Wait(this: this->transcodeJobList[*p_currentTranscodeJobList].parallelJobList);
      v4 = &this->vmtrPath[64 * *p_currentTranscodeJobList];
      *p_currentTranscodeJobList ^= 1u;
      v5 = v4 + 50360;
      if ( v4[50420] != 0 )
      {
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(v4 + 50388));
        v6 = *((_DWORD *)v5 + 4);
        v5[60] = 0;
        if ( v6 < 0 )
          idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)(v5 + 16));
      }
      --v2;
    }
    while ( v2 != 0 );
  }
}


// ========================================================================
// ?FreePage@idPhysicalPages@@QAAXPAVidVirtualTexture@@PAUtexturePage_t@@PAUpageImagesUpdateParms_t@@@Z
// EA  : 0x8297E618
// RVA : 0x0097E618
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idPhysicalPages::FreePage(idPhysicalPages *this, __int64 page, pageImagesUpdateParms_t *deferredUnmap)
{
  idVirtualTexture *v4; // r26
  int v5; // r31
  __int64 *physicalPageNums; // r9
  int v8; // r10
  int v9; // r8
  int v10; // r7
  const texturePage_t *v11; // r5
  int numUpdates; // r11
  pageImagesUpdate_t *updates; // r10
  _WORD *v14; // r9
  __int64 *v15; // r7
  _DWORD *v16; // r10
  int v17; // ctr
  __int64 v18; // r4
  int v19; // r11
  int v20; // r5
  int v21; // r11
  bfx::BinaryReplayLogOut v22[12]; // [sp+50h] [-150h] BYREF

  v4 = (idVirtualTexture *)HIDWORD(page);
  v5 = page;
  while ( this->unlockedPageList.sortDone == 0 )
    Sys_Yield();
  if ( *(_BYTE *)(v5 + 1) != 0 )
  {
    *(_BYTE *)(v5 + 1) = 0;
    physicalPageNums = this->unlockedPageList.physicalPageNums;
    v8 = this->unlockedPageList.lastPageIndex + 1;
    v9 = this->unlockedPageList.indexMask & v8;
    v10 = *(unsigned __int16 *)(v5 + 8);
    this->unlockedPageList.lastPageIndex = v8;
    LODWORD(page) = v10;
    physicalPageNums[v9] = page;
    --this->numLockedPages;
  }
  v11 = *(const texturePage_t **)(v5 + 28);
  if ( v11 != nullptr )
  {
    if ( *(_BYTE *)v5 != 0 )
    {
      if ( deferredUnmap != nullptr )
      {
        numUpdates = deferredUnmap->numUpdates;
        updates = deferredUnmap->updates;
        deferredUnmap->numUpdates = numUpdates + 1;
        idPhysicalPages::CreatePageImagesUpdate(
          this,
          vt: v4,
          physPage: *(const texturePage_t **)(v5 + 28),
          virtPage: (texturePage_t *)v5,
          pageDataPBO: nullptr,
          pageData: nullptr,
          update: &updates[numUpdates]);
      }
      else
      {
        idPhysicalPages::CreatePageImagesUpdate(
          this,
          vt: v4,
          physPage: v11,
          virtPage: (texturePage_t *)v5,
          pageDataPBO: nullptr,
          pageData: nullptr,
          update: (pageImagesUpdate_t *)&v22[0].m_buf.m_size);
        v22[0].m_pLogDevice = (bfx::LogDevice *const)1;
        v22[0].m_startTime = 0.0;
        v22[0].__vftable = (bfx::BinaryReplayLogOut_vtbl *)&v22[0].m_buf.m_size;
        v22[0].m_buf.m_data = (unsigned __int8 *)0x1000000;
        UpdatePageImagesJob(parms: (const pageImagesUpdateParms_t *)v22);
        idPhysics_StaticMulti::UpdateTime(this: v22);
      }
    }
    *(_DWORD *)(4 * (*(_DWORD *)(v5 + 24) + 8) + *(_DWORD *)(v5 + 28)) = 0;
  }
  idPhysicalPageHash::RemovePage(this: &this->pageHash, page: (texturePage_t *)v5);
  idPhysicalPageList::Remove(this: &this->unlockedPageList, physicalPageNum: *(unsigned __int16 *)(v5 + 8));
  v14 = (_WORD *)(v5 + 62);
  v15 = this->freePageList.physicalPageNums;
  v16 = (_DWORD *)(v5 + 44);
  v17 = 4;
  LODWORD(v18) = *(unsigned __int16 *)(v5 + 8);
  v19 = this->freePageList.lastPageIndex + 1;
  v20 = this->freePageList.indexMask & v19;
  this->freePageList.lastPageIndex = v19;
  HIDWORD(v18) = 8 * v20;
  *(__int64 *)((char *)v15 + HIDWORD(v18)) = v18;
  *(_DWORD *)(v5 + 16) = 0;
  *(_DWORD *)(v5 + 20) = 1;
  *(_DWORD *)(v5 + 28) = 0;
  *(_BYTE *)v5 = 0;
  *(_BYTE *)(v5 + 1) = 0;
  do
  {
    *(v16 - 3) = 0;
    *++v16 = 0;
    *++v14 = 0;
    --v17;
  }
  while ( v17 != 0 );
  if ( (texturePage_t *)v5 == v4->rootTexturePage )
    v4->rootTexturePage = nullptr;
  v21 = 4 * (*(unsigned __int8 *)(v5 + 3) + 296);
  --*(idVirtualTexture_vtbl **)((char *)&v4->__vftable + v21);
}


// ========================================================================
// ?FreePageTree_r@idPhysicalPages@@QAAXPAVidVirtualTexture@@PAUtexturePage_t@@PAUpageImagesUpdateParms_t@@@Z
// EA  : 0x8297E7F8
// RVA : 0x0097E7F8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idPhysicalPages::FreePageTree_r(
        idPhysicalPages *this,
        idVirtualTexture *vt,
        texturePage_t *page,
        pageImagesUpdateParms_t *deferredUnmap)
{
  texturePage_t **p_coarser; // r28
  int i; // r29
  __int64 v10; // r5
  __int64 *physicalPageNums; // r9
  int v12; // r10
  int v13; // r8
  int physicalPageNum; // r7
  texturePage_t *coarser; // r5
  int numUpdates; // r11
  pageImagesUpdate_t *updates; // r10
  _WORD *v18; // r9
  __int64 *v19; // r7
  texturePage_t **v20; // r10
  int v21; // ctr
  __int64 v22; // r4
  int v23; // r11
  int v24; // r5
  int v25; // r11
  bfx::BinaryReplayLogOut v26[12]; // [sp+50h] [-150h] BYREF

  if ( page != nullptr )
  {
    p_coarser = &page->coarser;
    for ( i = 4; i != 0; --i )
      idPhysicalPages::FreePageTree_r(this, vt, page: *++p_coarser, deferredUnmap);
    while ( this->unlockedPageList.sortDone == 0 )
      Sys_Yield();
    if ( page->locked )
    {
      page->locked = false;
      physicalPageNums = this->unlockedPageList.physicalPageNums;
      v12 = this->unlockedPageList.lastPageIndex + 1;
      v13 = this->unlockedPageList.indexMask & v12;
      physicalPageNum = page->physicalPageNum;
      this->unlockedPageList.lastPageIndex = v12;
      LODWORD(v10) = physicalPageNum;
      physicalPageNums[v13] = v10;
      --this->numLockedPages;
    }
    coarser = page->coarser;
    if ( coarser != nullptr )
    {
      if ( page->mapped )
      {
        if ( deferredUnmap != nullptr )
        {
          numUpdates = deferredUnmap->numUpdates;
          updates = deferredUnmap->updates;
          deferredUnmap->numUpdates = numUpdates + 1;
          idPhysicalPages::CreatePageImagesUpdate(
            this,
            vt,
            physPage: page->coarser,
            virtPage: page,
            pageDataPBO: nullptr,
            pageData: nullptr,
            update: &updates[numUpdates]);
        }
        else
        {
          idPhysicalPages::CreatePageImagesUpdate(
            this,
            vt,
            physPage: coarser,
            virtPage: page,
            pageDataPBO: nullptr,
            pageData: nullptr,
            update: (pageImagesUpdate_t *)&v26[0].m_buf.m_size);
          v26[0].m_pLogDevice = (bfx::LogDevice *const)1;
          v26[0].m_startTime = 0.0;
          v26[0].__vftable = (bfx::BinaryReplayLogOut_vtbl *)&v26[0].m_buf.m_size;
          v26[0].m_buf.m_data = (unsigned __int8 *)0x1000000;
          UpdatePageImagesJob(parms: (const pageImagesUpdateParms_t *)v26);
          idPhysics_StaticMulti::UpdateTime(this: v26);
        }
      }
      page->coarser->finer[page->quadrant] = nullptr;
    }
    idPhysicalPageHash::RemovePage(this: &this->pageHash, page);
    idPhysicalPageList::Remove(this: &this->unlockedPageList, physicalPageNum: page->physicalPageNum);
    v18 = (_WORD *)&page->finerDiskOffset[3] + 1;
    v19 = this->freePageList.physicalPageNums;
    v20 = &page->finer[3];
    v21 = 4;
    LODWORD(v22) = page->physicalPageNum;
    v23 = this->freePageList.lastPageIndex + 1;
    v24 = this->freePageList.indexMask & v23;
    this->freePageList.lastPageIndex = v23;
    HIDWORD(v22) = 8 * v24;
    *(__int64 *)((char *)v19 + HIDWORD(v22)) = v22;
    page->pageSource = PAGESOURCE_INVALID;
    page->pageCompression = COMP_NONE;
    page->coarser = nullptr;
    page->mapped = false;
    page->locked = false;
    do
    {
      *(v20 - 3) = nullptr;
      *++v20 = nullptr;
      *++v18 = 0;
      --v21;
    }
    while ( v21 != 0 );
    if ( page == vt->rootTexturePage )
      vt->rootTexturePage = nullptr;
    v25 = 4 * (page->pageLevel + 296);
    --*(idVirtualTexture_vtbl **)((char *)&vt->__vftable + v25);
  }
}


// ========================================================================
// ?UpdateFilterParms@idPhysicalPages@@QAAX_N@Z
// EA  : 0x8297EA00
// RVA : 0x0097EA00
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idPhysicalPages::UpdateFilterParms(
        idPhysicalPages *this,
        bool forceUpdateFilterParms,
        long double _FP2)
{
  char v5; // r31
  double valueFloat; // fp30
  idImage *physicalPagesImage1; // r29
  int v8; // r10
  int v9; // r9
  int v10; // r8
  int v11; // r7
  int v12; // r6
  int v13; // r5
  int v14; // r4
  char v15; // r11
  idImage *physicalPagesImage0; // r29
  int v17; // r10
  int v18; // r9
  int v19; // r8
  int v20; // r7
  int v21; // r6
  int v22; // r5
  int v23; // r4
  idImage *physicalPagesImage2; // r29
  int v25; // r10
  int v26; // r9
  int v27; // r8
  int v28; // r7
  int v29; // r6
  int v30; // r5
  int v31; // r4
  idImage *v32; // r29
  int v33; // r10
  int v34; // r9
  int v35; // r8
  int v36; // r7
  int v37; // r6
  int v38; // r5
  int v39; // r4
  idImage *v40; // r31
  int v41; // r10
  int v42; // r9
  int v43; // r8
  int v44; // r7
  int v45; // r6
  int v46; // r5
  int v47; // r4
  idImage *v48; // r31
  int v49; // r10
  int v50; // r9
  int v51; // r8
  int v52; // r7
  int v53; // r6
  int v54; // r5
  int v55; // r4
  int feedbackNumPages; // r11
  __int64 v57; // r7
  int v58; // r10
  __int64 v59; // r9
  __int64 v60; // r8
  __int64 v61; // r11
  double v67; // fp30
  long double v68; // fp2
  int v69; // [sp+8h] [-118h]
  int v70; // [sp+8h] [-118h]
  int v71; // [sp+8h] [-118h]
  int v72; // [sp+8h] [-118h]
  idImageOpts v73; // [sp+60h] [-C0h] BYREF

  v5 = 0;
  if ( (vt_maxAniso.flags & 0x20000) != 0 )
  {
    if ( vt_maxAniso.valueFloat >= 1.0 )
    {
      valueFloat = 4.0;
      if ( vt_maxAniso.valueFloat <= 4.0 )
        valueFloat = vt_maxAniso.valueFloat;
    }
    else
    {
      valueFloat = 1.0;
    }
    v73.border.x = 0.0;
    v73.format = FMT_NONE;
    v73.border.y = 0.0;
    v73.colorFormat = CFM_DEFAULT;
    v73.border.z = 0.0;
    v73.filter = TF_DEFAULT;
    v73.border.w = 0.0;
    v73.repeat = TR_REPEAT;
    v73.lodBias = 0.0;
    v73.cubeFilter = false;
    v73.lodMinClamp = 0.0;
    v73.lodMaxClamp = 13.0;
    v73.aniso = 0.0;
    memset(&v73, 0, 20);
    v73.packedTail = true;
    v73.readback = false;
    v73.linear = false;
    v73.forceBias = false;
    v73.depthCompareMode = false;
    v73.overlayMemory = false;
    v73.startPurged = false;
    idImageOpts::operator=(this: &v73, __that: &this->physicalPagesImage1->opts);
    v73.aniso = valueFloat;
    physicalPagesImage1 = this->physicalPagesImage1;
    idImageOpts::operator=(this: &physicalPagesImage1->opts, __that: &v73);
    idImage::DetermineSamplerStateFromOpts(
      this: physicalPagesImage1,
      a2: v14,
      a3: v13,
      a4: v12,
      a5: v11,
      a6: v10,
      a7: v9,
      a8: v8,
      a9: v69);
    GL_ResetTextureState();
    if ( this->physicalPagesPool == PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY
      || (v15 = 0, this->physicalPagesPool == PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY2) )
    {
      v15 = 1;
    }
    if ( v15 == 0 )
    {
      idImageOpts::operator=(this: &v73, __that: &this->physicalPagesImage0->opts);
      v73.aniso = valueFloat;
      physicalPagesImage0 = this->physicalPagesImage0;
      idImageOpts::operator=(this: &physicalPagesImage0->opts, __that: &v73);
      idImage::DetermineSamplerStateFromOpts(
        this: physicalPagesImage0,
        a2: v23,
        a3: v22,
        a4: v21,
        a5: v20,
        a6: v19,
        a7: v18,
        a8: v17,
        a9: v69);
      GL_ResetTextureState();
      idImageOpts::operator=(this: &v73, __that: &this->physicalPagesImage2->opts);
      v73.aniso = valueFloat;
      physicalPagesImage2 = this->physicalPagesImage2;
      idImageOpts::operator=(this: &physicalPagesImage2->opts, __that: &v73);
      idImage::DetermineSamplerStateFromOpts(
        this: physicalPagesImage2,
        a2: v31,
        a3: v30,
        a4: v29,
        a5: v28,
        a6: v27,
        a7: v26,
        a8: v25,
        a9: v70);
      GL_ResetTextureState();
    }
  }
  if ( (vt_filter.flags & 0x20000) != 0 )
  {
    v73.border.x = 0.0;
    v73.format = FMT_NONE;
    v73.border.y = 0.0;
    v73.colorFormat = CFM_DEFAULT;
    v73.border.z = 0.0;
    v73.filter = TF_DEFAULT;
    v73.border.w = 0.0;
    v73.repeat = TR_REPEAT;
    v73.lodBias = 0.0;
    v73.cubeFilter = false;
    v73.lodMinClamp = 0.0;
    v73.lodMaxClamp = 13.0;
    v73.aniso = 0.0;
    memset(&v73, 0, 20);
    v73.packedTail = true;
    v73.readback = false;
    v73.linear = false;
    v73.forceBias = false;
    v73.depthCompareMode = false;
    v73.overlayMemory = false;
    v73.startPurged = false;
    idImageOpts::operator=(this: &v73, __that: &this->physicalPagesImage1->opts);
    v73.filter = (_cntlzw(vt_filter.valueInteger) & 0x20) != 0;
    v32 = this->physicalPagesImage1;
    idImageOpts::operator=(this: &v32->opts, __that: &v73);
    idImage::DetermineSamplerStateFromOpts(
      this: v32,
      a2: v39,
      a3: v38,
      a4: v37,
      a5: v36,
      a6: v35,
      a7: v34,
      a8: v33,
      a9: v69);
    GL_ResetTextureState();
    if ( this->physicalPagesPool == PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY
      || this->physicalPagesPool == PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY2 )
    {
      v5 = 1;
    }
    if ( v5 == 0 )
    {
      idImageOpts::operator=(this: &v73, __that: &this->physicalPagesImage0->opts);
      v73.filter = (_cntlzw(vt_filter.valueInteger) & 0x20) != 0;
      v40 = this->physicalPagesImage0;
      idImageOpts::operator=(this: &v40->opts, __that: &v73);
      idImage::DetermineSamplerStateFromOpts(
        this: v40,
        a2: v47,
        a3: v46,
        a4: v45,
        a5: v44,
        a6: v43,
        a7: v42,
        a8: v41,
        a9: v71);
      GL_ResetTextureState();
      idImageOpts::operator=(this: &v73, __that: &this->physicalPagesImage2->opts);
      v73.filter = (_cntlzw(vt_filter.valueInteger) & 0x20) != 0;
      v48 = this->physicalPagesImage2;
      idImageOpts::operator=(this: &v48->opts, __that: &v73);
      idImage::DetermineSamplerStateFromOpts(
        this: v48,
        a2: v55,
        a3: v54,
        a4: v53,
        a5: v52,
        a6: v51,
        a7: v50,
        a8: v49,
        a9: v72);
      GL_ResetTextureState();
    }
  }
  if ( vt_feedbackLODIncrement.valueFloat <= 0.0 || vt_showPageUsage.valueInteger > 0 || forceUpdateFilterParms )
  {
    this->feedbackDynamicLodBias = 0.0;
  }
  else
  {
    feedbackNumPages = this->feedbackNumPages;
    LODWORD(v57) = this->NUM_PHYSICAL_PAGES;
    HIDWORD(v57) = &vt_feedbackHighWater;
    v58 = (int)(float)((float)(vt_feedbackHighWater.valueFloat * (float)0.0099999998) * (float)v57);
    HIDWORD(v59) = (int)(float)((float)(vt_feedbackLowWater.valueFloat * (float)0.0099999998) * (float)v57);
    if ( feedbackNumPages <= v58 || (HIDWORD(v60) = 0x82000000, this->feedbackDynamicLodBias >= 10.0) )
    {
      if ( feedbackNumPages < SHIDWORD(v59) )
      {
        LODWORD(v59) = HIDWORD(v59) - feedbackNumPages;
        _FP4 = (float)((float)1.0
                     - (float)((float)v59 / (float)__SPAIR64__(HIDWORD(v59) - feedbackNumPages, HIDWORD(v59))));
        __asm { fsel      f3, f4, f5, f29 }
        *((double *)&_FP2 + 1) = (float)-(float)((float)((float)_FP3 * vt_feedbackLODIncrement.valueFloat)
                                               - this->feedbackDynamicLodBias);
        *(double *)&_FP2 = -*((double *)&_FP2 + 1);
        __asm { fsel      f0, f1, f31, f2 }
        this->feedbackDynamicLodBias = _FP0;
      }
    }
    else
    {
      LODWORD(v61) = feedbackNumPages - v58;
      HIDWORD(v61) = this->NUM_PHYSICAL_PAGES - v58;
      LODWORD(v60) = HIDWORD(v61);
      _FP4 = (float)((float)1.0 - (float)((float)v61 / (float)v60));
      __asm { fsel      f3, f4, f5, f29 }
      *((double *)&_FP2 + 1) = (float)((float)((float)_FP3 * vt_feedbackLODIncrement.valueFloat)
                                     + this->feedbackDynamicLodBias);
      this->feedbackDynamicLodBias = (float)((float)_FP3 * vt_feedbackLODIncrement.valueFloat)
                                   + this->feedbackDynamicLodBias;
    }
  }
  if ( __fabs((float)(this->feedbackDynamicLodBias - this->oldFeedbackDynamicLodBias)) > 0.0099999998
    || (vt_maxAniso.flags & 0x20000) != 0
    || (vt_lodBias.flags & 0x20000) != 0
    || (vt_feedbackLodBias.flags & 0x20000) != 0
    || forceUpdateFilterParms )
  {
    *(double *)&_FP2 = vt_maxAniso.valueFloat;
    v67 = (float)(this->feedbackDynamicLodBias + vt_feedbackLodBias.valueFloat);
    v68 = log(x: _FP2);
    idDeclRenderParm::Set(
      this: (idDeclRenderParm *)this->rpPhysicalFilterParms->r,
      x: vt_lodBias.valueFloat,
      y: v67,
      z: (float)((float)((float)1.0 / (float)0.69314718) * (float)*(double *)&v68),
      w: 0.0);
    this->oldFeedbackDynamicLodBias = this->feedbackDynamicLodBias;
  }
}


// ========================================================================
// ?EmptyCache@idVirtualTextureSystem@@QAAX_N@Z
// EA  : 0x8297EF08
// RVA : 0x0097EF08
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::EmptyCache(idVirtualTextureSystem *this, bool skipVmtrCache)
{
  int v3; // r11
  int v4; // r27
  int v5; // r30
  idVirtualTexture *v6; // r29
  int v7; // r14
  idPhysicalPages *v8; // r29
  char *v9; // r23
  int i; // r7
  int v11; // r10
  int j; // ctr
  char *v13; // r11
  char *v14; // r24
  char *v15; // r25
  unsigned __int8 *v16; // r21
  unsigned __int8 *v17; // r22
  int PHYSICAL_PAGES_HIGH; // r10
  int v19; // r26
  int PHYSICAL_PAGES_WIDE; // r11
  int k; // r30
  char v22; // r11
  int v23; // r26
  int v24; // r11
  int m; // r30
  int v26; // r26
  int v27; // r11
  int n; // r30
  int v29; // [sp+8h] [-128h]
  idDxtEncoder v30[8]; // [sp+80h] [-B0h] BYREF

  v3 = 1;
  v4 = 0;
  if ( skipVmtrCache )
  {
    v3 = 2;
    v4 = 1;
  }
  v5 = 16 - v3;
  v6 = &this->vts[v3];
  do
  {
    idVirtualTexture::EmptyCache(this: v6);
    --v5;
    ++v6;
  }
  while ( v5 != 0 );
  v7 = 4 - v4;
  v8 = &this->physicalPagesPool[v4];
  do
  {
    if ( v8->physicalPagesImage1 != nullptr )
    {
      v9 = (char *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                     size: 0x10000u,
                     tag: TAG_TEMP,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
      memset(Dst: v9, Val: 255, Size: 0x10000u);
      for ( i = 0; i < 128; ++i )
      {
        v11 = 0;
        for ( j = 128; j != 0; --j )
        {
          v13 = &v9[512 * i + 4 * v11];
          *v13 = v11++;
          v13[1] = i;
          *((_WORD *)v13 + 1) = 255;
        }
      }
      v14 = v9;
      v15 = v9;
      v16 = (unsigned __int8 *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                                 size: 0x2000u,
                                 tag: TAG_TEMP,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
      v17 = (unsigned __int8 *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                                 size: 0x4000u,
                                 tag: TAG_TEMP,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
      if ( v8->pageImageCompressed )
      {
        v30[0].dstPadding = 0;
        v30[0].srcPadding = 0;
        v14 = (char *)v16;
        v15 = (char *)v17;
        idDxtEncoder::CompressImageDXT1Fast_Xenon(
          this: v30,
          inBuf: (const unsigned __int8 *)v9,
          outBuf: v16,
          width: 128,
          height: 128);
        idDxtEncoder::CompressImageDXT5Fast_Xenon(
          this: v30,
          inBuf: (const unsigned __int8 *)v9,
          outBuf: v17,
          width: 128,
          height: 128);
      }
      PHYSICAL_PAGES_HIGH = v8->PHYSICAL_PAGES_HIGH;
      v19 = 0;
      if ( PHYSICAL_PAGES_HIGH > 0 )
      {
        PHYSICAL_PAGES_WIDE = v8->PHYSICAL_PAGES_WIDE;
        do
        {
          for ( k = 0; k < PHYSICAL_PAGES_WIDE; ++k )
          {
            idImage::SubImageUpload(
              this: v8->physicalPagesImage1,
              mipLevel: 0,
              destX: k << 7,
              destY: v19 << 7,
              destZ: D3DCUBEMAP_FACE_POSITIVE_X,
              width: 128,
              height: 128,
              pic: v15,
              pixelPitch: v29);
            PHYSICAL_PAGES_WIDE = v8->PHYSICAL_PAGES_WIDE;
          }
          PHYSICAL_PAGES_HIGH = v8->PHYSICAL_PAGES_HIGH;
          ++v19;
        }
        while ( v19 < PHYSICAL_PAGES_HIGH );
      }
      if ( v8->physicalPagesPool == PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY
        || (v22 = 0, v8->physicalPagesPool == PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY2) )
      {
        v22 = 1;
      }
      if ( v22 == 0 )
      {
        v23 = 0;
        if ( PHYSICAL_PAGES_HIGH > 0 )
        {
          v24 = v8->PHYSICAL_PAGES_WIDE;
          do
          {
            for ( m = 0; m < v24; ++m )
            {
              idImage::SubImageUpload(
                this: v8->physicalPagesImage0,
                mipLevel: 0,
                destX: m << 7,
                destY: v23 << 7,
                destZ: D3DCUBEMAP_FACE_POSITIVE_X,
                width: 128,
                height: 128,
                pic: v14,
                pixelPitch: v29);
              v24 = v8->PHYSICAL_PAGES_WIDE;
            }
            PHYSICAL_PAGES_HIGH = v8->PHYSICAL_PAGES_HIGH;
            ++v23;
          }
          while ( v23 < PHYSICAL_PAGES_HIGH );
        }
        v26 = 0;
        if ( PHYSICAL_PAGES_HIGH > 0 )
        {
          v27 = v8->PHYSICAL_PAGES_WIDE;
          do
          {
            for ( n = 0; n < v27; ++n )
            {
              idImage::SubImageUpload(
                this: v8->physicalPagesImage2,
                mipLevel: 0,
                destX: n << 7,
                destY: v26 << 7,
                destZ: D3DCUBEMAP_FACE_POSITIVE_X,
                width: 128,
                height: 128,
                pic: v15,
                pixelPitch: v29);
              v27 = v8->PHYSICAL_PAGES_WIDE;
            }
            ++v26;
          }
          while ( v26 < v8->PHYSICAL_PAGES_HIGH );
        }
      }
      if ( v17 != nullptr )
        idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
      if ( v16 != nullptr )
        idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
      if ( v9 != nullptr )
        idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
    }
    --v7;
    ++v8;
  }
  while ( v7 != 0 );
  this->emptyCacheTime = Sys_Milliseconds();
}


// ========================================================================
// __unwind$239679
// EA  : 0x8297F2B8
// RVA : 0x0097F2B8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_239679()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 304 + 96));
}


// ========================================================================
// __unwind$239680
// EA  : 0x8297F2E0
// RVA : 0x0097F2E0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_239680()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 304 + 104));
}


// ========================================================================
// __unwind$239681
// EA  : 0x8297F308
// RVA : 0x0097F308
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_239681()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 304 + 112));
}


// ========================================================================
// ?UpdateFilterParms@idVirtualTextureSystem@@QAAX_N@Z
// EA  : 0x8297F330
// RVA : 0x0097F330
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::UpdateFilterParms(
        idVirtualTextureSystem *this,
        bool forceUpdateFilterParms,
        long double a3)
{
  double valueFloat; // fp30
  long double v6; // fp2
  double v7; // fp29
  idImage **p_pageTableImage; // r31
  int v9; // r28
  double v10; // fp31
  idImage *v11; // r30
  int v12; // r10
  int v13; // r9
  int v14; // r8
  int v15; // r7
  int v16; // r6
  int v17; // r5
  int v18; // r4
  int v19; // r31
  idPhysicalPages *physicalPagesPool; // r30
  int v21; // [sp+8h] [-F8h]
  idImageOpts opts; // [sp+50h] [-B0h] BYREF

  if ( (vt_lodBias.flags & 0x20000) != 0 || (vt_maxAniso.flags & 0x20000) != 0 )
  {
    forceUpdateFilterParms = true;
    if ( vt_showPageUsage.valueInteger > 0 )
      valueFloat = 0.0;
    else
      valueFloat = vt_lodBias.valueFloat;
    *(double *)&a3 = vt_maxAniso.valueFloat;
    v6 = log(x: a3);
    v7 = (float)((float)((float)1.0 / (float)0.69314718) * (float)*(double *)&v6);
    *(_QWORD *)&v6 = 0x405E000000000000LL;
    a3 = log(x: v6);
    v9 = 15;
    v10 = (float)((float)((float)((float)((float)1.0 / 0.69314718) * (float)*(double *)&a3) - (float)v7)
                + (float)valueFloat);
    p_pageTableImage = &this->vts[1].pageTableImage;
    do
    {
      v11 = *p_pageTableImage;
      if ( *p_pageTableImage != nullptr )
      {
        opts = v11->opts;
        opts.lodBias = v10;
        idImageOpts::operator=(this: &v11->opts, __that: &opts);
        idImage::DetermineSamplerStateFromOpts(
          this: v11,
          a2: v18,
          a3: v17,
          a4: v16,
          a5: v15,
          a6: v14,
          a7: v13,
          a8: v12,
          a9: v21);
        GL_ResetTextureState();
      }
      --v9;
      p_pageTableImage += 312;
    }
    while ( v9 != 0 );
  }
  v19 = 4;
  physicalPagesPool = this->physicalPagesPool;
  do
  {
    idPhysicalPages::UpdateFilterParms(this: physicalPagesPool, forceUpdateFilterParms, _FP2: a3);
    --v19;
    ++physicalPagesPool;
  }
  while ( v19 != 0 );
  vt_maxAniso.flags &= ~0x20000u;
  vt_lodBias.flags &= ~0x20000u;
  vt_filter.flags &= ~0x20000u;
  vt_feedbackLodBias.flags &= ~0x20000u;
}


// ========================================================================
// ?Shutdown@idVirtualTextureSystem@@QAAXXZ
// EA  : 0x8297F4B0
// RVA : 0x0097F4B0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::Shutdown(idVirtualTextureSystem *this)
{
  int v2; // r27
  transcodeJobList_t *transcodeJobList; // r30
  int v4; // r28
  int v5; // r30
  idFile *file; // r3
  idFile *fileInstalled; // r3
  cachedPageFile_t *v8; // r11
  cachedPageFile_t *list; // r4

  idVirtualTexturePreloader::EndPreloading(this: &virtualTexturePreloader);
  if ( this->analyzeJobList != nullptr )
  {
    ((void (__fastcall *)(idParallelJobManager *))parallelJobManager->FreeJobList)(a1: parallelJobManager);
    this->analyzeJobList = nullptr;
  }
  v2 = 2;
  transcodeJobList = this->transcodeJobList;
  do
  {
    if ( transcodeJobList->parallelJobList != nullptr )
    {
      ((void (__fastcall *)(idParallelJobManager *))parallelJobManager->FreeJobList)(a1: parallelJobManager);
      transcodeJobList->parallelJobList = nullptr;
    }
    --v2;
    ++transcodeJobList;
  }
  while ( v2 != 0 );
  this->vts[1].FreeData(this: &this->vts[1]);
  idVirtualTextureSystem::FreeDynamicMedia(this);
  idVirtualTextureSystem::EmptyCache(this, skipVmtrCache: false);
  v4 = 0;
  if ( this->cachedPagesFiles.num > 0 )
  {
    v5 = 0;
    do
    {
      file = this->cachedPagesFiles.list[v5].file;
      if ( file != nullptr )
        ((void (__fastcall *)(idFile *, int))file->dtr_idFile)(a1: file, a2: 1);
      this->cachedPagesFiles.list[v5].file = nullptr;
      fileInstalled = this->cachedPagesFiles.list[v5].fileInstalled;
      if ( fileInstalled != nullptr )
        ((void (__fastcall *)(idFile *, int))fileInstalled->dtr_idFile)(a1: fileInstalled, a2: 1);
      ++v4;
      v8 = &this->cachedPagesFiles.list[v5++];
      v8->fileInstalled = nullptr;
    }
    while ( v4 < this->cachedPagesFiles.num );
  }
  if ( this->cachedPagesFiles.listStatic == 0 || this->cachedPagesFiles.listStatic == 2 )
  {
    list = this->cachedPagesFiles.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->cachedPagesFiles.list = nullptr;
    this->cachedPagesFiles.size = 0;
  }
  this->cachedPagesFiles.num = 0;
}


// ========================================================================
// ?VisualizeFeedbackBuffer@idVirtualTextureSystem@@AAAXPBXHHH@Z
// EA  : 0x8297F638
// RVA : 0x0097F638
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::VisualizeFeedbackBuffer(
        idVirtualTextureSystem *this,
        const void *data,
        signed int width,
        signed int height,
        unsigned int bytePitch)
{
  unsigned int v10; // r29
  char *buffer; // r22
  char *v12; // r30
  int v13; // r24
  int v14; // r25
  signed int i; // r19
  int v16; // r26
  char *v17; // r4
  signed int v18; // ctr
  char *v19; // r3
  int v20; // r27
  unsigned __int8 *v21; // r10
  int v22; // r11
  int v23; // r5
  unsigned int v24; // r16
  unsigned int v25; // r6
  unsigned int v26; // r5
  char v27; // r10
  idImage **p_feedbackVisualize; // r29
  int v29; // [sp+8h] [-168h]
  tagPOINT v30; // [sp+60h] [-110h] BYREF
  idTempArray<char> v31; // [sp+68h] [-108h] BYREF
  idTempArray<char> v32; // [sp+70h] [-100h] BYREF
  tagRECT v33; // [sp+80h] [-F0h] BYREF
  idImageOpts v34; // [sp+90h] [-E0h] BYREF

  if ( data != nullptr )
  {
    v10 = 4 * width * height;
    idTempArray<char>::idTempArray<char>(this: &v31, num: v10);
    v33.right = width;
    v33.bottom = height;
    v30.x = 0;
    v30.y = 0;
    v33.left = 0;
    v33.top = 0;
    buffer = v31.buffer;
    XGUntileSurface(
      pDestination: v31.buffer,
      RowPitch: bytePitch,
      pPoint: &v30,
      pSource: data,
      Width: width,
      Height: height,
      pRect: &v33,
      TexelPitch: 4u);
    idTempArray<char>::idTempArray<char>(this: &v32, num: v10);
    v12 = v32.buffer;
    if ( height > 0 )
    {
      v13 = 0;
      v14 = 0;
      for ( i = height; i != 0; --i )
      {
        v16 = 0;
        if ( width > 0 )
        {
          v17 = v12 + 1;
          v18 = width;
          v19 = v12 + 2;
          v20 = 0;
          do
          {
            v21 = (unsigned __int8 *)&buffer[v14 + v20];
            v22 = 4 * (v13 + v16);
            v23 = v21[2];
            v24 = v21[3];
            v25 = ((v23 << 8) & 0xF00) + *v21;
            v26 = ((16 * v23) & 0xF00) + v21[1];
            v27 = v24 & 0xF;
            if ( vt_showFeedbackBuffer.valueInteger == 4 )
            {
              v12[v22] = ((v24 & 1) == 0) - 1;
              v17[v22] = ((v24 & 2) == 0) - 1;
              v19[v22] = ((v24 & 4) == 0) - 1;
            }
            else if ( vt_showFeedbackBuffer.valueInteger == 3 )
            {
              v12[v22] = ((v24 & 0x10) == 0) - 1;
              v17[v22] = (((v24 >> 4) & 2) == 0) - 1;
              v19[v22] = (((v24 >> 4) & 4) == 0) - 1;
            }
            else
            {
              if ( vt_showFeedbackBuffer.valueInteger == 2 )
              {
                v12[v22] = 32 * (v25 >> v27);
                v17[v22] = 32 * (v26 >> v27);
              }
              else
              {
                v12[v22] = 32 * v25;
                v17[v22] = 32 * v26;
              }
              v19[v22] = 0;
            }
            v12[v22 + 3] = -1;
            ++v16;
            v20 += 4;
            --v18;
          }
          while ( v18 != 0 );
        }
        v14 += bytePitch;
        v13 += width;
      }
    }
    p_feedbackVisualize = &this->feedbackVisualize;
    if ( this->feedbackVisualize == nullptr )
    {
      v34.width = width;
      v34.height = height;
      v34.colorFormat = CFM_DEFAULT;
      v34.repeat = TR_REPEAT;
      v34.cubeFilter = false;
      v34.depth = 0;
      v34.numLevels = 0;
      v34.border.x = 0.0;
      v34.textureType = TT_2D;
      v34.border.y = 0.0;
      v34.packedTail = true;
      v34.border.z = 0.0;
      v34.readback = false;
      v34.border.w = 0.0;
      v34.linear = false;
      v34.lodBias = 0.0;
      v34.forceBias = false;
      v34.lodMinClamp = 0.0;
      v34.depthCompareMode = false;
      v34.lodMaxClamp = 13.0;
      v34.overlayMemory = false;
      v34.aniso = 0.0;
      v34.startPurged = false;
      v34.format = FMT_RGBA8;
      v34.filter = TF_NEAREST;
      *p_feedbackVisualize = idImageManager::ScratchImage(this: globalImages, _name: "_pageVisualize", imgOpts: &v34);
    }
    idImage::SubImageUpload(
      this: *p_feedbackVisualize,
      mipLevel: 0,
      destX: 0,
      destY: 0,
      destZ: D3DCUBEMAP_FACE_POSITIVE_X,
      width,
      height,
      pic: v12,
      pixelPitch: v29);
    if ( v12 != nullptr )
      idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$240131
// EA  : 0x8297F944
// RVA : 0x0097F944
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_240131()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 368 + 104));
}


// ========================================================================
// __unwind$240132
// EA  : 0x8297F96C
// RVA : 0x0097F96C
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_240132()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 368 + 112));
}


// ========================================================================
// ?ShowFeedbackStreaming@idVirtualTextureSystem@@AAAXPBXHHH@Z
// EA  : 0x8297F9A0
// RVA : 0x0097F9A0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::ShowFeedbackStreaming(
        idVirtualTextureSystem *this,
        const void *data,
        signed int width,
        signed int height,
        const int bytePitch)
{
  D3DTexture *d3dTexture; // r29
  unsigned int v10; // r30
  char *buffer; // r21
  double v12; // fp31
  __int64 v13; // r10
  char *v14; // r28
  signed int v15; // ctr
  int v16; // r30
  unsigned __int8 *v17; // r24
  unsigned __int8 *v18; // r29
  signed int i; // r4
  int v20; // r11
  unsigned int v21; // r18
  int v22; // r7
  unsigned int v23; // r11
  unsigned int v24; // r5
  unsigned int v25; // r6
  unsigned int v26; // r8
  char *v27; // r11
  int v28; // r11
  int v29; // r7
  int valueInteger; // r11
  _BYTE *v31; // r11
  unsigned int j; // r10
  unsigned int v33; // r8
  __int64 v34; // r7
  idImage **p_feedbackStreaming; // r30
  idImage *feedbackStreaming; // r8
  const void *v37; // [sp+8h] [-198h]
  int v38; // [sp+8h] [-198h]
  const tagRECT *v39; // [sp+Ch] [-194h]
  idImageOpts v40; // [sp+70h] [-130h] BYREF
  idTempArray<char> v41; // [sp+C0h] [-E0h] BYREF
  idTempArray<char> v42; // [sp+C8h] [-D8h] BYREF
  _XGTEXTURE_DESC v43; // [sp+D0h] [-D0h] BYREF

  if ( data != nullptr )
  {
    d3dTexture = this->renderDestFeedback[0]->targetImage[0]->d3dTexture;
    XGGetTextureDesc(pTexture: d3dTexture, Level: 0, pDesc: &v43);
    v10 = (d3dTexture->Format.dword[5] & 0x800) == 0;
    if ( (d3dTexture->Format.dword[3] & 0x80000000) != 0 )
      v10 |= 2u;
    idTempArray<char>::idTempArray<char>(this: &v41, num: 4 * v43.Height * v43.Width);
    buffer = v41.buffer;
    XGUntileTextureLevel(
      Width: v43.Width,
      Height: v43.Height,
      Level: 0,
      GpuFormat: v43.Format & 0x3F,
      Flags: v10,
      pDestination: v41.buffer,
      RowPitch: 4 * v43.Width,
      pPoint: nullptr,
      pSource: v37,
      pRect: v39);
    v12 = 0.0;
    idTempArray<char>::idTempArray<char>(this: &v42, num: 0x14000u);
    v14 = v42.buffer;
    if ( height > 0 )
    {
      v15 = height;
      v16 = 0;
      v17 = (unsigned __int8 *)buffer;
      do
      {
        v18 = v17;
        for ( i = 0; i < width; v18 += 4 )
        {
          v20 = v18[2];
          v21 = v18[3];
          v22 = (16 * v20) & 0xF00;
          HIDWORD(v13) = (v20 << 8) & 0xF00;
          v23 = v21 >> 4;
          v24 = v22 + v18[1];
          v25 = HIDWORD(v13) + *v18;
          v26 = v21 & 0xF;
          if ( v21 >> 4 != 0 )
          {
            if ( v23 < 0x10 )
            {
              HIDWORD(v13) = (char *)this + 1248 * v23;
              v28 = *(_DWORD *)(HIDWORD(v13) + 1736);
              v29 = *(__int16 *)(HIDWORD(v13) + 580);
              if ( v28 != 0 )
              {
                valueInteger = v29 - *(_DWORD *)(v28 + 76);
                if ( valueInteger <= vt_minLod.valueInteger )
                  valueInteger = vt_minLod.valueInteger;
              }
              else
              {
                valueInteger = vt_minLod.valueInteger;
              }
              if ( v26 < valueInteger || (valueInteger = v29 - 1, v26 > v29 - 1) )
                v26 = valueInteger;
              if ( *(int *)(HIDWORD(v13) + 572) >> v26 != 0 )
              {
                v31 = *(_BYTE **)(HIDWORD(v13) + 1732);
                for ( j = *(__int16 *)(HIDWORD(v13) + 580);
                      v31 != nullptr;
                      v31 = *(_BYTE **)&v31[4 * ((2 * (unsigned __int8)(v24 >> (j - 1))) & 2 | (v25 >> (j - 1)) & 1)
                                          + 32] )
                {
                  if ( *v31 == 0 )
                    break;
                  j = (unsigned __int8)v31[3];
                }
                if ( j <= v26 )
                  j = v26;
                v33 = j - v26;
                __twllei(v29 - 1, 0);
                HIDWORD(v13) = 255 * v33 / (v29 - 1);
                if ( ((HIDWORD(v13) - 64) & 0x40000000) != 0 )
                {
                  LODWORD(v13) = 0;
                }
                else
                {
                  LODWORD(v13) = 255;
                  if ( 2 * (HIDWORD(v13) - 64) <= 255 )
                    LODWORD(v13) = 2 * (HIDWORD(v13) - 64);
                }
                HIDWORD(v34) = v13;
                v27 = &v14[4 * v16 + 4 * i];
                *v27 = v13;
                LODWORD(v13) = 255 - 2 * HIDWORD(v13);
                if ( (int)v13 >= 0 )
                {
                  if ( (int)v13 > 255 )
                    LOBYTE(v13) = -1;
                }
                else
                {
                  LOBYTE(v13) = 0;
                }
                v27[1] = v13;
                v27[2] = BYTE3(v13);
                LODWORD(v34) = v33 * v33;
                v12 = (float)((float)v34 + (float)v12);
              }
              else
              {
                v27 = &v14[4 * v16 + 4 * i];
                *v27 = -1;
                *(_WORD *)(v27 + 1) = 255;
              }
            }
            else
            {
              v27 = &v14[4 * v16 + 4 * i];
              *v27 = -1;
              v27[1] = 0;
              v27[2] = 0;
            }
          }
          else
          {
            v27 = &v14[4 * v16 + 4 * i];
            *v27 = 0;
            v27[1] = 0;
            v27[2] = 0;
          }
          ++i;
          v27[3] = -1;
        }
        v17 += bytePitch;
        v16 += width;
        --v15;
      }
      while ( v15 != 0 );
    }
    LODWORD(v13) = width;
    p_feedbackStreaming = &this->feedbackStreaming;
    feedbackStreaming = this->feedbackStreaming;
    this->mipLevelMSE = (float)v12 / (float)((float)v13 * (float)__SPAIR64__(width, height));
    if ( feedbackStreaming == nullptr )
    {
      v40.border.x = 0.0;
      v40.border.y = 0.0;
      v40.border.z = 0.0;
      v40.border.w = 0.0;
      v40.colorFormat = CFM_DEFAULT;
      v40.lodBias = 0.0;
      v40.cubeFilter = false;
      v40.lodMinClamp = 0.0;
      v40.depth = 0;
      v40.aniso = 0.0;
      v40.numLevels = 0;
      v40.lodMaxClamp = 0.0;
      v40.textureType = TT_2D;
      v40.packedTail = true;
      v40.readback = false;
      v40.linear = false;
      v40.forceBias = false;
      v40.depthCompareMode = false;
      v40.overlayMemory = false;
      v40.startPurged = false;
      v40.width = 160;
      v40.height = 128;
      v40.filter = TF_NEAREST;
      v40.repeat = TR_CLAMP;
      v40.format = FMT_RGBA8;
      *p_feedbackStreaming = idImageManager::ScratchImage(
                               this: globalImages,
                               _name: "_feedbackStreaming",
                               imgOpts: &v40);
    }
    idImage::SubImageUpload(
      this: *p_feedbackStreaming,
      mipLevel: 0,
      destX: 0,
      destY: 0,
      destZ: D3DCUBEMAP_FACE_POSITIVE_X,
      width: 160,
      height: 128,
      pic: v14,
      pixelPitch: v38);
    if ( v14 != nullptr )
      idMem::Free(this: &mem, ptr: v14, align: ALIGN_16);
    if ( buffer != nullptr )
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$240312
// EA  : 0x8297FE14
// RVA : 0x0097FE14
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_240312()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 416 + 192));
}


// ========================================================================
// __unwind$240313
// EA  : 0x8297FE3C
// RVA : 0x0097FE3C
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_240313()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 416 + 200));
}


// ========================================================================
// ?VisaulizeFeedback@idVirtualTextureSystem@@QAAXXZ
// EA  : 0x8297FE68
// RVA : 0x0097FE68
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::VisaulizeFeedback(idVirtualTextureSystem *this)
{
  idImage *feedbackVisualize; // r27
  signed int ScanoutWidth; // r31
  signed int Height; // r30
  bool v4; // r7
  idODSObject<idDeclRenderProg> v5; // [sp+50h] [-40h] BYREF
  idODSObject<idTriangles> v6; // [sp+54h] [-3Ch] BYREF

  feedbackVisualize = this->feedbackVisualize;
  if ( feedbackVisualize != nullptr || (feedbackVisualize = this->feedbackStreaming) != nullptr )
  {
    GL_SetDefaultState();
    ScanoutWidth = idRenderSystemLocal::GetScanoutWidth(this: &tr);
    Height = idRenderSystemLocal::GetHeight(this: &tr);
    GL_Viewport(x: ScanoutWidth / 8, y: Height / 8, w: 6 * ScanoutWidth / 8, h: 6 * Height / 8);
    GL_Scissor(x: 0, y: 0, w: ScanoutWidth, h: Height);
    idParmState::SetPositionToViewTexture(
      this: renderThreadParmState,
      windowWidth: 6 * ScanoutWidth / 8,
      windowHeight: 6 * Height / 8,
      renderWidth: 6 * ScanoutWidth / 8,
      renderHeight: 6 * Height / 8);
    idParmState::SetMVPMatrix(this: renderThreadParmState, mvp: &renderMatrix_identity);
    idDeclRenderParm::SetImage(this: (idDeclRenderParm *)rpViewColor_1.r, image: feedbackVisualize);
    idParmState::VirtualEvaluateParmBlock(
      this: renderThreadParmState,
      localParmBlock: (const idParmBlock *)&progViewColorIdentity_1.r[2].resourceListPtr,
      parmBlock: (const idParmBlock *)&progViewColorIdentity_1.r[2].resourceListPtr);
    v5.objectPtr = (const idDeclRenderProg *)progViewColorIdentity_1.r;
    v6.objectPtr = tr.unitSquareTris;
    GL_DrawElements(prog: &v5, tri: &v6, extraState: 0, skipDetailTriangles: v4);
    idParmState::VirtualRollbackParmBlock(
      this: renderThreadParmState,
      localParmBlock: (const idParmBlock *)&progViewColorIdentity_1.r[2].resourceListPtr,
      parmBlock: (const idParmBlock *)&progViewColorIdentity_1.r[2].resourceListPtr);
  }
}


// ========================================================================
// ?CancelObsoleteTranscodes@idVirtualTextureSystem@@AAAXXZ
// EA  : 0x8297FFB8
// RVA : 0x0097FFB8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::CancelObsoleteTranscodes(idVirtualTextureSystem *this)
{
  int *p_numUpdates; // r29
  int v3; // r28
  int i; // r19
  int v5; // r20
  int v6; // r31
  int v7; // r21
  int v8; // r30
  int v9; // r11
  char *v10; // r8
  __int64 v11; // r6
  int v12; // r10
  int v13; // r11
  int v14; // r8
  int v15; // r9
  int v16; // r11
  int v17; // r9

  if ( vt_cancelObsoleteTranscodes.valueInteger != 0 )
  {
    p_numUpdates = &this->transcodeJobList[0].pageImagesUpdateParms.numUpdates;
    v3 = 0;
    for ( i = 2; i != 0; --i )
    {
      v5 = *p_numUpdates - 1;
      v6 = *(p_numUpdates - 11) - 1;
      if ( v5 >= 0 )
      {
        v7 = v5 << 8;
        do
        {
          v8 = *(p_numUpdates - 1) + v7;
          if ( *(_BYTE *)(v8 + 16) == 0 )
          {
            v9 = *(_DWORD *)(v8 + 4);
            v10 = &this->vmtrPath[136 * *(_DWORD *)v8];
            if ( *(_DWORD *)(4 * v9 + *((_DWORD *)v10 + 12357)) != this->feedbackFrameNum )
            {
              HIDWORD(v11) = 72 * v9 + *((_DWORD *)v10 + 12355);
              if ( *(_BYTE *)HIDWORD(v11) != 0
                && *(_QWORD *)(HIDWORD(v11) + 32) == 0
                && *(_QWORD *)(HIDWORD(v11) + 40) == 0 )
              {
                *(_BYTE *)(v8 + 16) = 1;
                ++p_numUpdates[1];
                LODWORD(v11) = 0;
                *(_BYTE *)HIDWORD(v11) = 0;
                idPhysicalPages::FreePage(
                  this: (idPhysicalPages *)(v10 + 49416),
                  page: v11,
                  deferredUnmap: (pageImagesUpdateParms_t *)(4 * v9));
                if ( v6 >= 0 )
                {
                  v12 = *(p_numUpdates - 10);
                  v13 = v6 << 7;
                  v14 = *(_DWORD *)(v8 + 4);
                  v15 = (v6 << 7) + v12;
                  while ( *(_DWORD *)(v15 + 28) != v14 )
                  {
                    v13 -= 128;
                    --v6;
                    v15 = v13 + v12;
                    if ( v6 < 0 )
                      goto LABEL_18;
                  }
                  v16 = v6 << 7;
                  v17 = (v6 << 7) + v12;
                  do
                  {
                    if ( *(_DWORD *)(v17 + 28) != v14 )
                      break;
                    v16 -= 128;
                    --v6;
                    ++v3;
                    v17 = v16 + v12;
                  }
                  while ( v6 >= 0 );
                }
              }
            }
          }
LABEL_18:
          --v5;
          v7 -= 256;
        }
        while ( v5 >= 0 );
      }
      p_numUpdates += 16;
    }
    if ( v3 != 0 && vt_cancelObsoleteTranscodes.valueInteger == 2 )
      idLib::Printf(fmt: "%d: cancelled %d obsolete transcode jobs\n", this->feedbackFrameNum, v3);
  }
}


// ========================================================================
// ?AllocPage@idPhysicalPages@@QAAPAUtexturePage_t@@PAVidVirtualTexture@@PAU2@W4pageQuadrant_t@@PAUpageImagesUpdateParms_t@@@Z
// EA  : 0x82980478
// RVA : 0x00980478
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
texturePage_t *__fastcall idPhysicalPages::AllocPage(
        idPhysicalPages *this,
        idVirtualTexture *vt,
        texturePage_t *coarser,
        pageQuadrant_t quadrant,
        pageImagesUpdateParms_t *deferredUnmap)
{
  int firstPageIndex; // r9
  int indexMask; // r8
  __int64 *physicalPageNums; // r7
  int v13; // r4 OVERLAPPED
  __int64 v14; // r6
  int v15; // r10
  __int64 v16; // r7
  __int64 v17; // r5
  __int64 *v18; // r3
  int v19; // r9
  texturePage_t *v20; // r31
  __int16 numLevels; // r11
  __int32 v22; // r11
  __int32 v23; // r11
  _WORD *v24; // r10
  texturePage_t **v25; // r11
  int i; // ctr
  int v27; // r11
  int pageY; // r5
  int pageLevel; // r6
  unsigned int pageX; // r10
  int v32; // r7
  int v33; // r6
  unsigned int hashMask; // r4
  unsigned int v35; // r9

  while ( this->unlockedPageList.sortDone == 0 )
    Sys_Yield();
  if ( this->freePageList.lastPageIndex - this->freePageList.firstPageIndex == -1 )
  {
    firstPageIndex = this->unlockedPageList.firstPageIndex;
    if ( firstPageIndex <= this->unlockedPageList.lastPageIndex )
    {
      indexMask = this->unlockedPageList.indexMask;
      physicalPageNums = this->unlockedPageList.physicalPageNums;
      while ( 1 )
      {
        *(_QWORD *)(&v13 - 1) = physicalPageNums[indexMask & firstPageIndex];
        HIDWORD(v14) = &this->pages[LODWORD(physicalPageNums[indexMask & firstPageIndex])];
        if ( (texturePage_t *)HIDWORD(v14) != coarser
          && *(_QWORD *)(HIDWORD(v14) + 32) == 0
          && *(_QWORD *)(HIDWORD(v14) + 40) == 0 )
        {
          break;
        }
        if ( ++firstPageIndex > v13 )
          goto LABEL_11;
      }
      LODWORD(v14) = deferredUnmap;
      idPhysicalPages::FreePage(this, page: v14, deferredUnmap: (pageImagesUpdateParms_t *)physicalPageNums);
    }
  }
LABEL_11:
  v15 = this->freePageList.firstPageIndex;
  HIDWORD(v16) = 8 * (this->freePageList.indexMask & v15);
  v17 = *(__int64 *)((char *)this->freePageList.physicalPageNums + HIDWORD(v16));
  this->freePageList.firstPageIndex = v15 + 1;
  HIDWORD(v17) = this->unlockedPageList.indexMask;
  v18 = this->unlockedPageList.physicalPageNums;
  v19 = this->unlockedPageList.lastPageIndex + 1;
  this->unlockedPageList.lastPageIndex = v19;
  LODWORD(v16) = v17;
  v18[HIDWORD(v17) & v19] = v16;
  v20 = &this->pages[v17];
  v20->mapped = false;
  v20->coarser = coarser;
  v20->locked = false;
  v20->maxLevel = vt->header.numLevels - 1;
  if ( coarser != nullptr )
    LOBYTE(numLevels) = coarser->pageLevel;
  else
    numLevels = vt->header.numLevels;
  v20->pageLevel = numLevels - 1;
  if ( coarser != nullptr )
    v22 = __ROL4__(coarser->pageX, 1) + (quadrant & 1);
  else
    LOWORD(v22) = 0;
  v20->pageX = v22;
  if ( coarser != nullptr )
    v23 = __ROL4__(coarser->pageY, 1) + ((quadrant >> 1) & 1);
  else
    LOWORD(v23) = 0;
  v20->pageY = v23;
  v20->pageSource = vt->pageSource;
  v20->quadrant = quadrant;
  v20->pageCompression = idVirtualTexture::GetNewDiskPageCompression(this: vt);
  v24 = (_WORD *)&v20->finerDiskOffset[3] + 1;
  v25 = &v20->finer[3];
  for ( i = 4; i != 0; --i )
  {
    *(v25 - 3) = nullptr;
    *++v25 = nullptr;
    *++v24 = 0;
  }
  *(int *)((char *)this->pagePriority + __ROL4__(v20->physicalPageNum, 2)) = 0;
  *(int *)((char *)this->pageFrameNum + __ROL4__(v20->physicalPageNum, 2)) = 0;
  if ( coarser != nullptr )
    coarser->finer[quadrant] = v20;
  else
    vt->rootTexturePage = v20;
  v27 = 4 * (v20->pageLevel + 296);
  ++*(idVirtualTexture_vtbl **)((char *)&vt->__vftable + v27);
  pageY = v20->pageY;
  pageLevel = v20->pageLevel;
  pageX = v20->pageX;
  v32 = ((16 * v20->pageSource) | pageLevel) << 11;
  v33 = __ROL4__(pageLevel, 11);
  hashMask = this->pageHash.hashMask;
  *(unsigned int *)((char *)&this->pageHash.pageHashIndex->pageID + __ROL4__(v20->physicalPageNum, 3)) = ((v32 | pageY) << 11) | pageX;
  *(unsigned __int16 *)((char *)&this->pageHash.pageHashIndex->mapped + __ROL4__(v20->physicalPageNum, 3)) = 0;
  v35 = (((((1664525 * (((v33 | pageY) << 11) | pageX) + 1013904223) >> 11)
         ^ (1664525 * (((v33 | pageY) << 11) | pageX) + 1013904223)) >> 11)
       ^ (1664525 * (((v33 | pageY) << 11) | pageX) + 1013904223))
      & hashMask;
  *(unsigned __int16 *)((char *)&this->pageHash.pageHashIndex->next + __ROL4__(v20->physicalPageNum, 3)) = this->pageHash.pageHashTable[v35];
  this->pageHash.pageHashTable[v35] = v20->physicalPageNum;
  return v20;
}


// ========================================================================
// ??0idVirtualTextureSystem@@QAA@XZ
// EA  : 0x82980B38
// RVA : 0x00980B38
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

idVirtualTextureSystem *__fastcall idVirtualTextureSystem::idVirtualTextureSystem(idVirtualTextureSystem *this)
{
  __int64 v2; // r29
  idBitBlockAllocator **p_bitBlock; // r10
  int i; // ctr
  idVirtualTexture **p_vmtrMega; // r11
  int j; // ctr
  idStr v8; // [sp+50h] [-1B0h] BYREF
  idStr v9; // [sp+70h] [-190h] BYREF
  idStr v10; // [sp+90h] [-170h] BYREF
  idStr v11; // [sp+B0h] [-150h] BYREF
  idStr v12; // [sp+D0h] [-130h] BYREF
  idStr v13; // [sp+F0h] [-110h] BYREF
  idStr v14; // [sp+110h] [-F0h] BYREF
  idStr v15; // [sp+130h] [-D0h] BYREF
  idStr v16; // [sp+150h] [-B0h] BYREF
  idStr v17; // [sp+170h] [-90h] BYREF
  idStr v18; // [sp+190h] [-70h] BYREF
  idStr v19[2]; // [sp+1B0h] [-50h] BYREF

  LODWORD(v2) = 0;
  this->vmtrs.list = nullptr;
  this->vmtrs.granularity = 0;
  this->vmtrs.memTag = 5;
  this->vmtrs.listStatic = 0;
  this->vmtrs.size = 0;
  this->vmtrs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vmtrs);
  this->vmtrHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->vmtrHash, initialHashSize: 1024, initialIndexSize: 1024);
  HIDWORD(v2) = this->vts;
  `eh vector constructor iterator'(
    ptr: this->vts,
    size: 0x4E0u,
    count: 16,
    pCtor: (void (__fastcall *)(void *))idVirtualTexture::idVirtualTexture,
    pDtor: (void (__fastcall *)(void *))idVirtualTexture::~idVirtualTexture);
  this->vmtrMega = &this->vts[1];
  this->cachedPagesFiles.list = nullptr;
  this->cachedPagesFiles.granularity = 0;
  this->cachedPagesFiles.memTag = 5;
  this->cachedPagesFiles.listStatic = 0;
  this->cachedPagesFiles.size = 0;
  this->cachedPagesFiles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cachedPagesFiles);
  this->numReferencedVirtualTextures = 0;
  `eh vector constructor iterator'(
    ptr: this->physicalPagesPool,
    size: 0x88u,
    count: 4,
    pCtor: (void (__fastcall *)(void *))idPhysicalPages::idPhysicalPages,
    pDtor: (void (__fastcall *)(void *))idPhysicalPages::~idPhysicalPages);
  this->mapHasSpecularPages = false;
  this->mapHasDiffuseOnlyPages = false;
  this->mapHasDiffuseOnly2Pages = false;
  this->feedbackBufferObject = nullptr;
  this->feedbackBuffer = nullptr;
  this->feedbackBufferPitch = 0;
  *(_QWORD *)this->renderDestFeedback = v2;
  this->renderDestFeedback[2] = nullptr;
  this->feedbackVisualize = nullptr;
  this->feedbackStreaming = nullptr;
  this->mipLevelMSE = 0.0;
  this->feedbackFrameNum = 0;
  this->flushNextFeedback = false;
  this->pageTranscodeCount = 0;
  this->pageUploadCount = 0;
  this->emptyCacheTime = 0;
  this->vmtrBatchBuild = BATCH_NONE;
  this->bitBlock = nullptr;
  p_bitBlock = &this->bitBlock;
  for ( i = 10; i != 0; --i )
    *++p_bitBlock = nullptr;
  this->vtInfo = nullptr;
  this->currentPageIndices = 0;
  this->pageIndices[0] = nullptr;
  this->pageIndices[1] = nullptr;
  this->explicitPages[0] = nullptr;
  this->explicitPages[1] = nullptr;
  this->numExplicitPages[0] = 0;
  this->numExplicitPages[1] = 0;
  this->analyzeJobList = nullptr;
  `eh vector constructor iterator'(
    ptr: this->transcodeJobList,
    size: 0x40u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))transcodeJobList_t::transcodeJobList_t,
    pDtor: (void (__fastcall *)(void *))transcodeJobList_t::~transcodeJobList_t);
  this->currentTranscodeJobList = 0;
  this->cancelToTerminate = false;
  Sys_MutexCreate(handle: &this->metricMutex.handle);
  idStr::idStr(this: &v10, text: "total vmtr pages in view");
  idStr::idStr(this: &v14, text: "vmtrTotalPages");
  idGaugeMetric::idGaugeMetric(this: &this->vmtrTotalPagesMetric, _shortName: &v14, _description: &v10);
  idStr::FreeData(this: &v14);
  idStr::FreeData(this: &v10);
  idStr::idStr(this: &v12, text: "vmtr dynamic LOD bias");
  idStr::idStr(this: &v18, text: "vmtrBias");
  idGaugeMetric::idGaugeMetric(this: &this->vmtrBiasMetric, _shortName: &v18, _description: &v12);
  idStr::FreeData(this: &v18);
  idStr::FreeData(this: &v12);
  idStr::idStr(this: &v8, text: "total diffuse+specular pages in view");
  idStr::idStr(this: &v16, text: "specTotalPages");
  idGaugeMetric::idGaugeMetric(this: &this->specTotalPagesMetric, _shortName: &v16, _description: &v8);
  idStr::FreeData(this: &v16);
  idStr::FreeData(this: &v8);
  idStr::idStr(this: &v11, text: "diffuse+specular LOD bias");
  idStr::idStr(this: &v9, text: "specBias");
  idGaugeMetric::idGaugeMetric(this: &this->specBiasMetric, _shortName: &v9, _description: &v11);
  idStr::FreeData(this: &v9);
  idStr::FreeData(this: &v11);
  idStr::idStr(this: &v15, text: "total diffuse only pages in view");
  idStr::idStr(this: &v13, text: "diffuseTotalPages");
  idGaugeMetric::idGaugeMetric(this: &this->diffuseTotalPagesMetric, _shortName: &v13, _description: &v15);
  idStr::FreeData(this: &v13);
  idStr::FreeData(this: &v15);
  idStr::idStr(this: v19, text: "diffuse only LOD bias");
  idStr::idStr(this: &v17, text: "diffuseBias");
  idGaugeMetric::idGaugeMetric(this: &this->diffuseBiasMetric, _shortName: &v17, _description: v19);
  idStr::FreeData(this: &v17);
  idStr::FreeData(this: v19);
  memset(Dst: this, Val: 0, Size: 0x100u);
  memset(Dst: this->vmtrName, Val: 0, Size: sizeof(this->vmtrName));
  memset(Dst: this->containerPath, Val: 0, Size: sizeof(this->containerPath));
  memset(Dst: this->referencedVTPath, Val: 0, Size: sizeof(this->referencedVTPath));
  memset(Dst: this->referencedVTName, Val: 0, Size: sizeof(this->referencedVTName));
  memset(Dst: this->transcodeJobList, Val: 0, Size: sizeof(this->transcodeJobList));
  p_vmtrMega = &this->vmtrMega;
  for ( j = 16; j != 0; --j )
  {
    *++p_vmtrMega = (idVirtualTexture *)HIDWORD(v2);
    HIDWORD(v2) += 1248;
  }
  return this;
}


// ========================================================================
// __unwind$241605
// EA  : 0x82980FC0
// RVA : 0x00980FC0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241605()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 512 + 532) + 512));
}


// ========================================================================
// __unwind$241606
// EA  : 0x82980FEC
// RVA : 0x00980FEC
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241606()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 512 + 532) + 528));
}


// ========================================================================
// __unwind$241607
// EA  : 0x82981018
// RVA : 0x00981018
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241607()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 512 + 532) + 560),
    size: 0x4E0u,
    count: 16,
    pDtor: (void (__fastcall *)(void *))idVirtualTexture::~idVirtualTexture);
}


// ========================================================================
// __unwind$241608
// EA  : 0x82981054
// RVA : 0x00981054
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241608()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 512 + 532) + 20596));
}


// ========================================================================
// __unwind$241609
// EA  : 0x82981080
// RVA : 0x00981080
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241609()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 512 + 532) + 49416),
    size: 0x88u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idPhysicalPages::~idPhysicalPages);
}


// ========================================================================
// __unwind$241610
// EA  : 0x829810C4
// RVA : 0x009810C4
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241610()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 512 + 532) + 50360),
    size: 0x40u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))transcodeJobList_t::~transcodeJobList_t);
}


// ========================================================================
// __unwind$241611
// EA  : 0x82981108
// RVA : 0x00981108
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241611()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 512 + 532) + 50496));
}


// ========================================================================
// __unwind$241612
// EA  : 0x8298113C
// RVA : 0x0098113C
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241612()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 144));
}


// ========================================================================
// __unwind$241613
// EA  : 0x82981164
// RVA : 0x00981164
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241613()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 272));
}


// ========================================================================
// __unwind$241614
// EA  : 0x8298118C
// RVA : 0x0098118C
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241614()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 512 + 532) + 50500));
}


// ========================================================================
// __unwind$241615
// EA  : 0x829811C0
// RVA : 0x009811C0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241615()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 208));
}


// ========================================================================
// __unwind$241616
// EA  : 0x829811E8
// RVA : 0x009811E8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241616()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 400));
}


// ========================================================================
// __unwind$241617
// EA  : 0x82981210
// RVA : 0x00981210
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241617()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 512 + 532) + 50604));
}


// ========================================================================
// __unwind$241618
// EA  : 0x82981244
// RVA : 0x00981244
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241618()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 80));
}


// ========================================================================
// __unwind$241619
// EA  : 0x8298126C
// RVA : 0x0098126C
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241619()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 336));
}


// ========================================================================
// __unwind$241620
// EA  : 0x82981294
// RVA : 0x00981294
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241620()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 512 + 532) + 50708));
}


// ========================================================================
// __unwind$241621
// EA  : 0x829812C8
// RVA : 0x009812C8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241621()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 176));
}


// ========================================================================
// __unwind$241622
// EA  : 0x829812F0
// RVA : 0x009812F0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241622()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 112));
}


// ========================================================================
// __unwind$241623
// EA  : 0x82981318
// RVA : 0x00981318
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241623()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 512 + 532) + 50812));
}


// ========================================================================
// __unwind$241624
// EA  : 0x8298134C
// RVA : 0x0098134C
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241624()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 304));
}


// ========================================================================
// __unwind$241625
// EA  : 0x82981374
// RVA : 0x00981374
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241625()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 240));
}


// ========================================================================
// __unwind$241626
// EA  : 0x8298139C
// RVA : 0x0098139C
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241626()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 512 + 532) + 50916));
}


// ========================================================================
// __unwind$241627
// EA  : 0x829813D0
// RVA : 0x009813D0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241627()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 432));
}


// ========================================================================
// __unwind$241628
// EA  : 0x829813F8
// RVA : 0x009813F8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241628()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 512 + 368));
}


// ========================================================================
// __unwind$241629
// EA  : 0x82981420
// RVA : 0x00981420
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241629()
{
  int v0; // r12

  idMetricsFramework::MachineInfo::~MachineInfo(this: (idGaugeMetric *)(*(_DWORD *)(v0 - 512 + 532) + 51020));
}


// ========================================================================
// ?SetupLoadedVirtualMaterials@idVirtualTextureSystem@@QAAXXZ
// EA  : 0x82981460
// RVA : 0x00981460
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::SetupLoadedVirtualMaterials(idVirtualTextureSystem *this)
{
  int v1; // r30
  int i; // r29
  idList<idVehicleState *,5> v3[3]; // [sp+50h] [-30h] BYREF

  v1 = 0;
  memset(v3, 0, 14);
  v3[0].listStatic = 0;
  v3[0].memTag = 99;
  idList<idThread *,58>::Clear(this: v3);
  idResourceList::GetLoadedResources(this: &idMaterial::resourceList, resourceList: v3);
  for ( i = 0; i < v3[0].num; ++v1 )
  {
    idMaterial::SetupVirtualTexture(this: (idMaterial *)v3[0].list[v1]);
    ++i;
  }
  if ( (v3[0].listStatic == 0 || v3[0].listStatic == 2) && v3[0].list != nullptr )
    idMem::Free(this: &mem, ptr: v3[0].list, align: ALIGN_16);
}


// ========================================================================
// __unwind$241857
// EA  : 0x82981510
// RVA : 0x00981510
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_241857()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 128 + 80));
}


// ========================================================================
// ?EmptyCache_f@idVirtualTextureSystem@@CAXABVidCmdArgs@@@Z
// EA  : 0x82981538
// RVA : 0x00981538
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::EmptyCache_f(const idCmdArgs *args)
{
  idVirtualTextureSystem::EmptyCache(this: &virtualTextureSystem, skipVmtrCache: false);
}


// ========================================================================
// ?Restart_f@idVirtualTextureSystem@@CAXABVidCmdArgs@@@Z
// EA  : 0x82981548
// RVA : 0x00981548
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::Restart_f(const idCmdArgs *args)
{
  idVirtualTextureSystem::SyncFeedback(this: &virtualTextureSystem);
  idVirtualTextureSystem::EmptyCache(this: &virtualTextureSystem, skipVmtrCache: false);
  if ( !idVirtualTextureSystem::CreatePhysicalImages(
          this: &virtualTextureSystem,
          mapHasSpecularPages_: virtualTextureSystem.mapHasSpecularPages,
          mapHasDiffuseOnlyPages_: virtualTextureSystem.mapHasDiffuseOnlyPages,
          mapHasDiffuseOnly2Pages_: virtualTextureSystem.mapHasDiffuseOnly2Pages) )
    idLib::Warning(fmt: "failed to allocate larger physical textures");
}


// ========================================================================
// ?AnalyzeFeedback@idVirtualTextureSystem@@AAAXPBXHHH_N@Z
// EA  : 0x829815D0
// RVA : 0x009815D0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::AnalyzeFeedback(
        idVirtualTextureSystem *this,
        void *data,
        int width,
        int height,
        unsigned int bytePitch,
        bool forceHighestDetail)
{
  idParallelJobList **p_analyzeJobList; // r24
  unsigned int v13; // r10
  int v14; // r10
  virtualTextureInfo_t **p_vtInfo; // r11
  int v16; // ctr
  __int16 *p_numLevels; // r9
  int valueInteger; // r7
  int v19; // r6
  int v20; // r5
  virtualTextureInfo_t *v21; // r8
  int v22; // r5
  int v23; // r6
  int v24; // r7
  virtualTextureInfo_t *v25; // r7
  int v26; // r8
  int v27; // r7
  __int16 v28; // r6
  int v29; // r7
  const virtualTextureInfo_t *v30; // r9
  unsigned int v31; // r11
  pageIndices_t *v32; // r4
  int v33; // r25
  int v34; // r11
  unsigned int *p_currentPageIndices; // r28
  int v36; // r27
  int **p_pagePriority; // r29
  idImage **p_feedbackVisualize; // r29
  idImage *feedbackVisualize; // r3
  idImage **p_feedbackStreaming; // r30

  p_analyzeJobList = &this->analyzeJobList;
  console->AddJobListTimeRange(
    this: console,
    a2: RANGE_JBL_ANLZ,
    a3: &idColor::colorLtGrey,
    a4: this->analyzeJobList,
    a5: 0);
  if ( data != nullptr && width > 0 && height > 0
    || (v13 = this->currentPageIndices ^ 1, this->numExplicitPages[v13] > 0) )
  {
    v14 = 0;
    p_vtInfo = &this->vtInfo;
    v16 = 4;
    p_numLevels = &this->vts[0].header.numLevels;
    do
    {
      if ( *((_DWORD *)p_numLevels + 289) != 0 )
      {
        (*p_vtInfo)[v14].numLevels = *p_numLevels;
        valueInteger = vt_minLod.valueInteger;
        v19 = *p_numLevels;
        v20 = *(_DWORD *)(*((_DWORD *)p_numLevels + 289) + 76);
        if ( v19 - v20 > vt_minLod.valueInteger )
          valueInteger = v19 - v20;
        (*p_vtInfo)[v14].baseLevel = valueInteger;
        (*p_vtInfo)[v14].pagesWide = *((_DWORD *)p_numLevels - 2);
        (*p_vtInfo)[v14].physicalPagesPool = **((_DWORD **)p_numLevels + 287);
        (*p_vtInfo)[v14].priorityBias = 0;
      }
      else
      {
        (*p_vtInfo)[v14].numLevels = 0;
        (*p_vtInfo)[v14].baseLevel = vt_minLod.valueInteger;
        (*p_vtInfo)[v14].pagesWide = 0;
        (*p_vtInfo)[v14].physicalPagesPool = 0;
        (*p_vtInfo)[v14].priorityBias = 0;
      }
      v21 = *p_vtInfo;
      if ( *((_DWORD *)p_numLevels + 601) != 0 )
      {
        v21[v14 + 1].numLevels = p_numLevels[624];
        v22 = *(_DWORD *)(*((_DWORD *)p_numLevels + 601) + 76);
        v23 = p_numLevels[624];
        v24 = vt_minLod.valueInteger;
        if ( v23 - v22 > vt_minLod.valueInteger )
          v24 = v23 - v22;
        (*p_vtInfo)[v14 + 1].baseLevel = v24;
        (*p_vtInfo)[v14 + 1].pagesWide = *((_DWORD *)p_numLevels + 310);
        (*p_vtInfo)[v14 + 1].physicalPagesPool = **((_DWORD **)p_numLevels + 599);
        (*p_vtInfo)[v14 + 1].priorityBias = 0;
      }
      else
      {
        v21[v14 + 1].numLevels = 0;
        (*p_vtInfo)[v14 + 1].baseLevel = vt_minLod.valueInteger;
        (*p_vtInfo)[v14 + 1].pagesWide = 0;
        (*p_vtInfo)[v14 + 1].physicalPagesPool = 0;
        (*p_vtInfo)[v14 + 1].priorityBias = 0;
      }
      v25 = *p_vtInfo;
      v26 = v14 * 16 + 48;
      if ( *((_DWORD *)p_numLevels + 913) != 0 )
      {
        *(unsigned int *)((char *)&v25[-1].numLevels + v26) = p_numLevels[1248];
        v27 = p_numLevels[1248] - *(_DWORD *)(*((_DWORD *)p_numLevels + 913) + 76);
        if ( v27 <= vt_minLod.valueInteger )
          v27 = vt_minLod.valueInteger;
        (*p_vtInfo)[v14 + 2].baseLevel = v27;
        (*p_vtInfo)[v14 + 2].pagesWide = *((_DWORD *)p_numLevels + 622);
        (*p_vtInfo)[v14 + 2].physicalPagesPool = **((_DWORD **)p_numLevels + 911);
        (*p_vtInfo)[v14 + 2].priorityBias = 0;
      }
      else
      {
        *(unsigned int *)((char *)&v25[-1].numLevels + v26) = 0;
        (*p_vtInfo)[v14 + 2].baseLevel = vt_minLod.valueInteger;
        (*p_vtInfo)[v14 + 2].pagesWide = 0;
        (*p_vtInfo)[v14 + 2].physicalPagesPool = 0;
        (*p_vtInfo)[v14 + 2].priorityBias = 0;
      }
      if ( *((_DWORD *)p_numLevels + 1225) != 0 )
      {
        *(unsigned int *)((char *)&(*p_vtInfo)->numLevels + v26) = p_numLevels[1872];
        v28 = p_numLevels[1872];
        v29 = vt_minLod.valueInteger;
        if ( v28 - *(_DWORD *)(*((_DWORD *)p_numLevels + 1225) + 76) > vt_minLod.valueInteger )
          v29 = v28 - *(_DWORD *)(*((_DWORD *)p_numLevels + 1225) + 76);
        (*p_vtInfo)[v14 + 3].baseLevel = v29;
        (*p_vtInfo)[v14 + 3].pagesWide = *((_DWORD *)p_numLevels + 934);
        (*p_vtInfo)[v14 + 3].physicalPagesPool = **((_DWORD **)p_numLevels + 1223);
        (*p_vtInfo)[v14 + 3].priorityBias = 0;
      }
      else
      {
        *(unsigned int *)((char *)&(*p_vtInfo)->numLevels + v26) = 0;
        (*p_vtInfo)[v14 + 3].baseLevel = vt_minLod.valueInteger;
        (*p_vtInfo)[v14 + 3].pagesWide = 0;
        (*p_vtInfo)[v14 + 3].physicalPagesPool = 0;
        (*p_vtInfo)[v14 + 3].priorityBias = 0;
      }
      p_numLevels += 2496;
      v14 += 4;
      --v16;
    }
    while ( v16 != 0 );
    v30 = *p_vtInfo;
    v31 = this->currentPageIndices ^ 1;
    this->analyzeParms.analyzeFrame = this->feedbackFrameNum;
    v32 = this->pageIndices[v31];
    this->analyzeParms.width = width;
    this->analyzeParms.bytePitch = bytePitch;
    this->analyzeParms.data = data;
    v33 = 4 * (v31 + 12585);
    this->analyzeParms.pageIndices = v32;
    this->analyzeParms.height = height;
    this->analyzeParms.vtInfo = v30;
    v34 = 4 * (v31 + 12587);
    p_currentPageIndices = &this->currentPageIndices;
    this->analyzeParms.data2 = *(const void **)&this->vmtrPath[v33];
    this->analyzeParms.data2Width = *(_DWORD *)&this->vmtrPath[v34];
    this->analyzeParms.forceHighestDetail = forceHighestDetail;
    if ( vt_showExplicitPages.valueInteger != 0 )
      idLib::Printf(fmt: "Explicit pages: %i\n", *(_DWORD *)&this->vmtrPath[v34]);
    if ( vt_useAnalyzeJobs.valueInteger == 1 )
      idParallelJobList::AddJob(
        this: *p_analyzeJobList,
        function: (void (__fastcall *)(void *))FeedbackAnalysisJob,
        data: &this->analyzeParms);
    else
      FeedbackAnalysisJob(parms: &this->analyzeParms);
    v36 = 4;
    p_pagePriority = &this->physicalPagesPool[0].pagePriority;
    do
    {
      idPhysicalPageList::Sort(
        this: (idPhysicalPageList *)(p_pagePriority + 11),
        frameNum: this->feedbackFrameNum,
        pagePriority: *p_pagePriority,
        pageFrameNum: p_pagePriority[1],
        jobList: *p_analyzeJobList,
        useJobs: vt_usePageSortJobs.valueInteger);
      --v36;
      p_pagePriority += 34;
    }
    while ( v36 != 0 );
    idParallelJobList::Submit(this: *p_analyzeJobList, waitForJobList: nullptr, parallelism: -1);
    this->physicalPagesPool[0].feedbackNumPages = this->pageIndices[*p_currentPageIndices]->pageStats[0].numPages;
    this->physicalPagesPool[1].feedbackNumPages = this->pageIndices[*p_currentPageIndices]->pageStats[1].numPages;
    this->physicalPagesPool[2].feedbackNumPages = this->pageIndices[*p_currentPageIndices]->pageStats[2].numPages;
    this->physicalPagesPool[3].feedbackNumPages = this->pageIndices[*p_currentPageIndices]->pageStats[3].numPages;
    if ( vt_showFeedbackAnalysis.valueInteger != 0 )
    {
      idCVar::SetBool(this: &vt_showFeedbackAnalysis, newValue: false, force: true);
      idVirtualTextureSystem::ShowFeedbackAnalysis(this, (unsigned __int8 *)data, width, height, bytePitch);
    }
    if ( vt_showFeedbackBuffer.valueInteger != 0 )
    {
      idVirtualTextureSystem::VisualizeFeedbackBuffer(this, data, width, height, bytePitch);
    }
    else if ( vt_showFeedbackStreaming.valueInteger != 0 )
    {
      idVirtualTextureSystem::ShowFeedbackStreaming(this, data, width, height, bytePitch);
    }
    else
    {
      p_feedbackVisualize = &this->feedbackVisualize;
      feedbackVisualize = this->feedbackVisualize;
      if ( feedbackVisualize != nullptr )
        ((void (__fastcall *)(idImage *, int))feedbackVisualize->dtr_idResource)(a1: feedbackVisualize, a2: 1);
      p_feedbackStreaming = &this->feedbackStreaming;
      if ( *p_feedbackStreaming != nullptr )
        ((void (__fastcall *)(idImage *, int))(*p_feedbackStreaming)->dtr_idResource)(a1: *p_feedbackStreaming, a2: 1);
      *p_feedbackVisualize = nullptr;
      *p_feedbackStreaming = nullptr;
    }
  }
  else
  {
    this->currentPageIndices = v13;
  }
}


// ========================================================================
// ?SetSource_f@idVirtualTextureSystem@@CAXABVidCmdArgs@@@Z
// EA  : 0x82982070
// RVA : 0x00982070
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::SetSource_f(const idCmdArgs *args)
{
  int v2; // r3
  int v3; // r28
  const char *v4; // r4
  const char *v5; // r4
  idStr v6; // [sp+60h] [-90h] BYREF
  idStr v7; // [sp+80h] [-70h] BYREF
  idStr v8[2]; // [sp+A0h] [-50h] BYREF

  if ( args->argc == 3 )
  {
    v2 = atol(nptr: args->argv[1]);
    v3 = v2;
    if ( v2 <= 0 || v2 >= 16 )
    {
      if ( args->argc <= 1 )
        v5 = &byte_8200D768;
      else
        v5 = args->argv[1];
      idLib::Printf(fmt: "'%s' is not a valid pageSource\n", v5);
    }
    else
    {
      if ( args->argc <= 2 )
        v4 = &byte_8200D768;
      else
        v4 = args->argv[2];
      idStr::idStr(this: &v7, text: v4);
      idStr::StripFileExtension(this: &v7);
      v6.len = 0;
      v6.allocedAndFlag = 20;
      v6.data = v6.baseBuffer;
      v6.baseBuffer[0] = 0;
      if ( *v7.data == 47 || *v7.data == 92 || v7.data[1] == 58 )
        idStr::Format(this: &v6, fmt: "%s.pages", v7.data);
      else
        idStr::Format(this: &v6, fmt: "%s/%s.pages", vt_filePath.valueString.data, v7.data);
      if ( fileSystem->GetTimestamp(this: fileSystem, a2: v6.data, a3: false) == -1 )
      {
        idLib::Printf(fmt: "'%s' does not exist!\n", v6.data);
        idStr::FreeData(this: &v6);
        idStr::FreeData(this: &v7);
      }
      else
      {
        idStr::idStr(this: v8, text: virtualTextureSystem.vts[v3].baseName.data);
        if ( v8[0].len == 0 )
          idStr::operator=(this: v8, text: &v7);
        if ( (unsigned __int8)idVirtualTexture::SetSource(
                                this: &virtualTextureSystem.vts[v3],
                                baseName_: v8[0].data,
                                pageFilePath_: v6.data,
                                physicalPagesPool: -1 - ((v3 == 1) - 2)) == 0 )
          idLib::FatalError(fmt: "Error opening vmtr page file '%s'", v6.data);
        idVirtualTextureSystem::SetupLoadedVirtualMaterials(this: &virtualTextureSystem);
        idLib::Printf(fmt: "successfully set '%s'\n", v6.data);
        idStr::FreeData(this: v8);
        idStr::FreeData(this: &v6);
        idStr::FreeData(this: &v7);
      }
    }
  }
  else
  {
    idLib::Printf(fmt: "usage: vt_setSource <pageSrc_t 1-63> <pageFilePath>\n");
  }
}


// ========================================================================
// $LN85_0
// EA  : 0x82982294
// RVA : 0x00982294
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _LN85_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$242289
// EA  : 0x829822BC
// RVA : 0x009822BC
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_242289()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$242290
// EA  : 0x829822E4
// RVA : 0x009822E4
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_242290()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 160));
}


// ========================================================================
// ?CacheAllPagesFiles@idVirtualTextureSystem@@AAAXPBD0@Z
// EA  : 0x82982318
// RVA : 0x00982318
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::CacheAllPagesFiles(
        idVirtualTextureSystem *this,
        const char *virtualTexturePath,
        const char *virtualTextureInstallPath)
{
  int v6; // r19
  int v7; // r21
  int v8; // r28
  idFile_Permanent *v9; // r3
  const idMaterial *v10; // r29
  idFile_Permanent *v11; // r3
  idFile_Permanent *v12; // r30
  int v13; // r3
  idSkinMapping v14; // [sp+58h] [-C8h] BYREF
  idList<idStr,5> v15; // [sp+60h] [-C0h] BYREF
  idStr v16; // [sp+70h] [-B0h] BYREF
  idStr v17[4]; // [sp+90h] [-90h] BYREF

  if ( idStr::Icmpn(s1: virtualTexturePath, s2: "mtp:", n: 4) != 0 )
  {
    v6 = Sys_Milliseconds();
    *(_WORD *)&v15.memTag = 1280;
    memset(&v15, 0, 14);
    Sys_ListFiles(directory: virtualTexturePath, extension: ".pages", list: &v15);
    v7 = 0;
    if ( v15.num > 0 )
    {
      v8 = 0;
      do
      {
        idStr::idStr(this: &v16, text: virtualTexturePath);
        idStr::AppendPath(this: &v16, text: v15.list[v8].data);
        v9 = (idFile_Permanent *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x68u,
                                   tag: TAG_FILE,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
        if ( v9 != nullptr )
          v10 = (const idMaterial *)idFile_Permanent::idFile_Permanent(
                                      this: v9,
                                      relativePath: v16.data,
                                      osPath: v16.data,
                                      m: FS_READ_NO_BUFFERING,
                                      create: false);
        else
          v10 = nullptr;
        if ( idFile_Permanent::IsOpen(this: (idFile_Permanent *)v10) )
        {
          idStr::idStr(this: v17, text: virtualTextureInstallPath);
          idStr::AppendPath(this: v17, text: v15.list[v8].data);
          v11 = (idFile_Permanent *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x68u,
                                      tag: TAG_FILE,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
          if ( v11 != nullptr )
            v12 = idFile_Permanent::idFile_Permanent(
                    this: v11,
                    relativePath: v17[0].data,
                    osPath: v17[0].data,
                    m: FS_READ_NO_BUFFERING,
                    create: false);
          else
            v12 = nullptr;
          if ( !idFile_Permanent::IsOpen(this: v12) )
          {
            if ( v12 != nullptr )
              ((void (__fastcall *)(idFile_Permanent *, int))v12->dtr_idFile)(a1: v12, a2: 1);
            v12 = nullptr;
            idLib::Warning(fmt: "failed to open %s", v17[0].data);
          }
          v14.from = v10;
          v14.to = (const idMaterial *)v12;
          idList<cachedPageFile_t,5>::Append(this: (idList<idSkinMapping,46> *)&this->cachedPagesFiles, obj: &v14);
          idStr::FreeData(this: v17);
        }
        else
        {
          if ( v10 != nullptr )
            ((void (__fastcall *)(const idMaterial *, int))v10->dtr_idResource)(a1: v10, a2: 1);
          idLib::Warning(fmt: "failed to open %s", v16.data);
        }
        idStr::FreeData(this: &v16);
        ++v7;
        ++v8;
      }
      while ( v7 < v15.num );
    }
    v13 = Sys_Milliseconds();
    idLib::Printf(fmt: "%d milliseconds to open %d pages files\n", v13 - v6, this->cachedPagesFiles.num);
    if ( (v15.listStatic == 0 || v15.listStatic == 2) && v15.list != nullptr )
      idListArrayDelete<idStr>(ptr: v15.list, num: v15.size);
  }
}


// ========================================================================
// __unwind$242483
// EA  : 0x82982598
// RVA : 0x00982598
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_242483()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 288 + 96));
}


// ========================================================================
// __unwind$242484
// EA  : 0x829825C0
// RVA : 0x009825C0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_242484()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$242485_0
// EA  : 0x829825E8
// RVA : 0x009825E8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_242485_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 288 + 80), tag: TAG_FILE);
}


// ========================================================================
// __unwind$242486
// EA  : 0x82982614
// RVA : 0x00982614
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_242486()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 144));
}


// ========================================================================
// __unwind$242487
// EA  : 0x8298263C
// RVA : 0x0098263C
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_242487()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 288 + 80), tag: TAG_FILE);
}


// ========================================================================
// ?ListVirtualTextures_f@idVirtualTextureSystem@@CAXABVidCmdArgs@@@Z
// EA  : 0x82982670
// RVA : 0x00982670
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::ListVirtualTextures_f(const idCmdArgs *args)
{
  int v1; // r30
  idStr *list; // r26
  __int64 v3; // r10
  int v4; // r8
  int v5; // r7
  int v6; // r6
  char *v7; // r29
  signed int num; // r27
  const char **p_data; // r29
  signed int i; // r30
  int size; // r30
  idStr *v12; // r29
  idSort_Quick<idStr,idSort_PathStr> v13; // [sp+50h] [-A0h] BYREF
  idList<idStr,5> v14; // [sp+60h] [-90h] BYREF
  idStr v15; // [sp+70h] [-80h] BYREF
  idStr v16[3]; // [sp+90h] [-60h] BYREF

  v1 = 0;
  *(_WORD *)&v14.memTag = 1280;
  memset(&v14, 0, 14);
  idStr::idStr(this: &v15, text: virtualTextureSystem.vmtrPath);
  idList<idStr,5>::Append(this: &v14, obj: &v15);
  idStr::FreeData(this: &v15);
  list = v14.list;
  idStr::BackSlashesToSlashes(this: v14.list);
  if ( virtualTextureSystem.numReferencedVirtualTextures <= 0 )
  {
    num = v14.num;
  }
  else
  {
    v7 = virtualTextureSystem.referencedVTPath[0];
    do
    {
      idStr::idStr(this: v16, text: v7);
      idList<idStr,5>::Append(this: &v14, obj: v16);
      idStr::FreeData(this: v16);
      num = v14.num;
      list = v14.list;
      idStr::BackSlashesToSlashes(this: &v14.list[v14.num - 1]);
      ++v1;
      v7 += 256;
    }
    while ( v1 < virtualTextureSystem.numReferencedVirtualTextures );
  }
  v13.__vftable = (idSort_Quick<idStr,idSort_PathStr>_vtbl *)&idSort_PathStr::`vftable';
  if ( list != nullptr )
    idSort_Quick<idStr,idSort_PathStr>::Sort(this: &v13, base: list, num, a4: v6, a5: v5, a6: v4, a7: v3);
  v13.__vftable = (idSort_Quick<idStr,idSort_PathStr>_vtbl *)&idSort<idStr>::`vftable';
  idLib::Printf(fmt: "Referenced virtual textures:\n");
  idLib::Printf(fmt: "----------------------------\n");
  if ( num > 0 )
  {
    p_data = (const char **)&list[-1].data;
    for ( i = num; i != 0; --i )
    {
      p_data += 8;
      idLib::Printf(fmt: "%s\n", *p_data);
    }
  }
  idLib::Printf(fmt: "----------------------------\n");
  idLib::Printf(fmt: "Done\n");
  if ( (v14.listStatic == 0 || v14.listStatic == 2) && list != nullptr )
  {
    size = v14.size;
    if ( v14.size > 0 )
    {
      v12 = list;
      do
      {
        idStr::FreeData(this: v12);
        --size;
        ++v12;
      }
      while ( size != 0 );
    }
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$242647
// EA  : 0x82982828
// RVA : 0x00982828
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_242647()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$242648_0
// EA  : 0x82982850
// RVA : 0x00982850
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_242648_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$242649_0
// EA  : 0x82982878
// RVA : 0x00982878
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_242649_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// __unwind$242650
// EA  : 0x829828A0
// RVA : 0x009828A0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_242650()
{
  int v0; // r12

  idSort_QuickDefault<idStr>::~idSort_QuickDefault<idStr>(this: (idSort_QuickDefault<idStr> *)(v0 - 240 + 80));
}


// ========================================================================
// ?GetDiskStatsForFeedback@idVirtualTextureSystem@@AAAXPBUpageIndices_t@@AAH1@Z
// EA  : 0x82982D28
// RVA : 0x00982D28
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idVirtualTextureSystem::GetDiskStatsForFeedback(
        idVirtualTextureSystem *this,
        const pageIndices_t *transcodePageIndices,
        int *numCacheLines,
        int *numSeekAndReadMsec)
{
  int *v7; // r21
  int v8; // r2 OVERLAPPED
  char *list; // r15
  int num; // r17
  int totalNumPages; // r22
  int v12; // r16
  unsigned __int64 v13; // r27
  const char **p_data; // r28
  int v15; // r29
  const char *v16; // r11
  int v17; // r9
  const char **v18; // r30
  size_t v19; // r30
  int v20; // r4
  unsigned __int64 *indices; // r20
  __int128 v22; // r11
  int v23; // r6
  int v24; // r11
  unsigned int v25; // r26
  unsigned int v26; // r25
  idVirtualTexture *v27; // r24
  unsigned int v28; // r10
  idPhysicalPages *physicalPages; // r9
  int v30; // r5
  unsigned int v31; // r11
  int v32; // r11
  int v33; // r10
  int v34; // r11
  int v35; // r30
  int v36; // r28
  const char **v37; // r27
  const char **v38; // r29
  char *v39; // r11
  idList<cacheLineStat_t,5> *v40; // r30
  idList<cacheLineStat_t,5> *v41; // r3
  unsigned __int64 v42; // r11
  unsigned int *v43; // r30
  int i; // r29
  int j; // r27
  int *v46; // r29
  int k; // r26
  int v48; // r28
  int v49; // r30
  const cacheLineStat_t *v50; // r4
  int v51; // r11
  int v52; // r8
  idVehicleState **v53; // r30
  __int64 *v54; // r9
  int v55; // ctr
  __int64 v56; // r11
  __int64 v57; // r11 OVERLAPPED
  int v58; // r9 OVERLAPPED
  int v59; // r3
  idList<pageFileStats_t,5> v60; // [sp+60h] [-110h] BYREF
  idList<idVehicleState *,5> v61; // [sp+70h] [-100h] BYREF
  cacheLineStat_t v62; // [sp+80h] [-F0h] BYREF
  pageFileStats_t v63[3]; // [sp+90h] [-E0h] BYREF

  *numCacheLines = 0;
  *numSeekAndReadMsec = 0;
  memset(&v61, 0, 14);
  *(_WORD *)&v61.memTag = 1280;
  v7 = numSeekAndReadMsec;
  idList<idThread *,58>::Clear(this: &v61);
  list = nullptr;
  num = 0;
  totalNumPages = transcodePageIndices->totalNumPages;
  *(_WORD *)&v60.memTag = 1280;
  memset(&v60, 0, 14);
  v12 = 0;
  v13 = 0xE00000000LL;
  p_data = (const char **)&this->vts[2].pageFilePath.data;
  do
  {
    v15 = 0;
    v16 = *p_data;
    do
      v17 = *(unsigned __int8 *)v16++;
    while ( v17 != 0 );
    if ( v16 - *p_data != 1 )
    {
      if ( num > 0 )
      {
        v18 = (const char **)(list + 4);
        do
        {
          if ( idStr::Cmp(s1: *v18, s2: *p_data) == 0 )
            break;
          ++v15;
          v18 += 16;
        }
        while ( v15 < num );
      }
      if ( v15 == num )
      {
        if ( *((__int16 *)p_data - 32) > v12 )
          v12 = *((__int16 *)p_data - 32);
        pageFileStats_t::pageFileStats_t(this: v63);
        v19 = (size_t)*(p_data - 1);
        v20 = v19 + 1;
        if ( v63[0].path.allocedAndFlag >= 0 )
        {
          if ( v20 > (v63[0].path.allocedAndFlag & 0x7FFFFFFF) )
            idStr::ReAllocate(this: &v63[0].path, amount: v20, keepold: false);
        }
        else if ( v20 > (v63[0].path.allocedAndFlag & 0x7FFFFFFF)
               && AssertFailed(
                    file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                    line: 463,
                    expression: "amount <= GetAlloced()",
                    inlineBreak: true) )
        {
          __trap();
        }
        memcpy(Dst: v63[0].path.data, Src: *p_data, Size: v19);
        v63[0].path.data[v19] = 0;
        v63[0].length = *(_QWORD *)(p_data - 13);
        v63[0].path.len = v19;
        v63[0].diskOffset = v13;
        idList<pageFileStats_t,5>::Append(this: &v60, obj: v63);
        LODWORD(v13) = LODWORD(v63[0].length) + v13;
        if ( v63[0].cacheLines.listStatic == 0 || v63[0].cacheLines.listStatic == 2 )
        {
          if ( v63[0].cacheLines.list != nullptr )
            idMem::Free(this: &mem, ptr: v63[0].cacheLines.list, align: ALIGN_16);
          v63[0].cacheLines.list = nullptr;
          v63[0].cacheLines.size = 0;
        }
        v63[0].cacheLines.num = 0;
        idStr::FreeData(this: &v63[0].path);
        num = v60.num;
        list = (char *)v60.list;
      }
    }
    --HIDWORD(v13);
    p_data += 312;
  }
  while ( HIDWORD(v13) != 0 );
  if ( totalNumPages > 0 )
  {
    indices = transcodePageIndices->indices;
    do
    {
      *((_QWORD *)&v22 + 1) = *indices;
      *(_QWORD *)((char *)&v22 + 4) = *indices >> 28;
      v23 = BYTE11(v22) & 0xF;
      v25 = (unsigned __int64)v22 >> 24 >> 32;
      v26 = ((unsigned __int64)v22 >> 13) & 0x7FF;
      v24 = ((unsigned __int64)v22 >> 24) & 0xF;
      v27 = this->vtPtrs[v23];
      if ( v27 != nullptr )
      {
        v28 = v27->mipLevelPagesWide[v24];
        if ( v25 < v28 && v26 < v28 )
        {
          physicalPages = v27->physicalPages;
          v30 = (((16 * v23) | v24) << 11) | v26;
          v31 = 1664525 * ((((v24 << 11) | v26) << 11) | v25) + 1013904223;
          v32 = physicalPages->pageHash.pageHashTable[((((v31 >> 11) ^ v31) >> 11)
                                                     ^ v31)
                                                    & physicalPages->pageHash.hashMask];
          if ( v32 != 0xFFFF )
          {
            while ( 1 )
            {
              v33 = (int)&physicalPages->pageHash.pageHashIndex[v32];
              if ( *(_DWORD *)v33 == ((v30 << 11) | v25) )
                break;
              v32 = *(unsigned __int16 *)(v33 + 6);
              if ( v32 == 0xFFFF )
                goto LABEL_44;
            }
            v34 = __ROL4__(*(unsigned __int16 *)(v33 + 4), 16) | v32;
            if ( v34 != -1 && (v34 & 0xFFFF0000) != 0 )
            {
              v35 = 0;
              v36 = (int)physicalPages->pages + 8 * (unsigned __int16)v34 + 8 * ((8 * v34) & 0x7FFF8);
              if ( num > 0 )
              {
                v37 = (const char **)((char *)this + 1248 * v23);
                v38 = (const char **)(list + 4);
                while ( idStr::Cmp(s1: *v38, s2: v37[161]) != 0 )
                {
                  ++v35;
                  v38 += 16;
                  if ( v35 >= num )
                    goto LABEL_44;
                }
                if ( v35 != -1 )
                {
                  v62.mipLevel = *(unsigned __int8 *)(v36 + 3);
                  v62.fileID = v35;
                  v39 = &list[64 * v35];
                  v40 = (idList<cacheLineStat_t,5> *)(v39 + 48);
                  v41 = (idList<cacheLineStat_t,5> *)(v39 + 48);
                  v42 = *((_QWORD *)v39 + 5);
                  LODWORD(v42) = v42 + HIDWORD(v42);
                  v62.diskCacheLine = v42 >> 16;
                  if ( idList<cacheLineStat_t,5>::FindIndex(this: v41, obj: &v62, startIndex: 0) < 0 )
                    idList<cacheLineStat_t,5>::Append(this: v40, obj: &v62);
                }
              }
            }
          }
        }
      }
LABEL_44:
      --totalNumPages;
      ++indices;
    }
    while ( totalNumPages != 0 );
    v7 = numSeekAndReadMsec;
  }
  if ( num > 0 )
  {
    v43 = (unsigned int *)(list + 52);
    for ( i = num; i != 0; --i )
    {
      if ( *v43 != 0 )
        qsort(
          base: (void *)*(v43 - 1),
          num: *v43,
          width: 0x10u,
          comp: (int (__fastcall *)(const void *, const void *))SortCacheLinesOnOffset);
      v43 += 16;
    }
  }
  for ( j = v12; j >= 0; --j )
  {
    if ( num > 0 )
    {
      v46 = (int *)(list + 52);
      for ( k = num; k != 0; --k )
      {
        v48 = 0;
        if ( *v46 > 0 )
        {
          v49 = 0;
          do
          {
            v50 = (const cacheLineStat_t *)(*(v46 - 1) + v49);
            if ( v50->mipLevel == j )
              idList<cacheLineStat_t,5>::Append(this: (idList<cacheLineStat_t,5> *)&v61, obj: v50);
            ++v48;
            v49 += 16;
          }
          while ( v48 < *v46 );
        }
        v46 += 16;
      }
    }
  }
  v51 = v61.num;
  v52 = 0;
  v53 = v61.list;
  *numCacheLines = v61.num;
  if ( v51 > 1 )
  {
    v54 = (__int64 *)(v53 + 2);
    v55 = v51 - 1;
    do
    {
      v56 = *v54;
      *(__int64 *)((char *)&v57 + 4) = v54[2];
      LODWORD(v57) = HIDWORD(v57) - v56 - 1;
      if ( (int)v57 < 0 || (int)v57 >= vt_noSeekCacheLines.valueInteger )
      {
        *(__int64 *)((char *)&v57 + 4) = v57 >> 63;
        LODWORD(v57) = 220 * ((v57 ^ HIDWORD(v57)) - HIDWORD(v57));
        *(__int64 *)((char *)&v57 + 4) = (unsigned __int64)(v57 >> 15) >> 48;
        v59 = HIDWORD(v57) + v57;
        LODWORD(v57) = (*(__int64 *)(&v8 - 1) >> 16) + 20;
      }
      else
      {
        *(__int64 *)((char *)&v57 + 4) = 2 * v57;
        LODWORD(v57) = 2 * (v57 + HIDWORD(v57));
      }
      v54 = (__int64 *)(v58 + 16);
      v52 += v57 + 6;
      --v55;
    }
    while ( v55 != 0 );
  }
  *v7 = v52;
  if ( (v60.listStatic == 0 || v60.listStatic == 2) && list != nullptr )
    idListArrayDelete<pageFileStats_t>(ptr: list, num: v60.size);
  if ( (v61.listStatic == 0 || v61.listStatic == 2) && v53 != nullptr )
    idMem::Free(this: &mem, ptr: v53, align: ALIGN_16);
}


// ========================================================================
// __unwind$243037
// EA  : 0x82983310
// RVA : 0x00983310
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_243037()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 368 + 112));
}


// ========================================================================
// __unwind$243038
// EA  : 0x82983338
// RVA : 0x00983338
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_243038()
{
  int v0; // r12

  idList<pageFileStats_t,5>::Clear(this: (idList<pageFileStats_t,5> *)(v0 - 368 + 96));
}


// ========================================================================
// __unwind$243039
// EA  : 0x82983360
// RVA : 0x00983360
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_243039()
{
  int v0; // r12

  pageFileStats_t::~pageFileStats_t(this: (pageFileStats_t *)(v0 - 368 + 144));
}


// ========================================================================
// __unwind$243132
// EA  : 0x82983388
// RVA : 0x00983388
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_243132()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 144));
}


// ========================================================================
// ?UpdateStats@idVirtualTextureSystem@@AAAXPBUpageIndices_t@@HHH@Z
// EA  : 0x829833B0
// RVA : 0x009833B0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idVirtualTextureSystem::UpdateStats(
        idVirtualTextureSystem *this,
        const pageIndices_t *transcodePageIndices,
        int numTranscodePages,
        int maxTranscodePagesPerFrame,
        int totalStreamedPageData)
{
  int v10; // r3
  int v11; // r2 OVERLAPPED
  double v12; // fp0
  __int64 v13; // r7
  int v14; // r28
  double v15; // fp13
  double v16; // fp12
  int v17; // ctr
  int v18; // r11
  int v19; // r11
  __int128 v20; // r5
  __int128 v21; // r5
  __int128 v22; // r5
  double v23; // fp1
  __int128 v24; // r5
  __int64 v25; // r5
  int v26; // r3
  __int64 v27; // r5
  int v28; // r3
  __int64 v29; // r5
  int v30; // r3
  __int64 v31; // r5
  int v32; // r3
  double v33; // fp30
  int v34; // r2 OVERLAPPED
  __int128 v35; // r11
  int renderWidth; // r3
  int v37; // r3
  idDebugGraph *v38; // r11
  __int128 v39; // r7
  __int64 v40; // r3
  __int64 v41; // r10
  bool v42; // r4
  bool v43; // r4
  __int64 v44; // r8
  bool v45; // r4
  bool v46; // r4
  __int64 v47; // r6
  bool v48; // r4
  bool v49; // r4
  int v50; // r11
  char *data; // r31
  const char *v52; // r3
  idFile *v53; // r3
  bool v54; // zf
  __int64 v55; // [sp+148h] [-1A8h] BYREF
  __int64 v56; // [sp+150h] [-1A0h] BYREF
  __int64 v57; // [sp+158h] [-198h]
  __int64 v58; // [sp+160h] [-190h]
  __int64 v59; // [sp+168h] [-188h]
  __int64 v60; // [sp+170h] [-180h]
  __int64 v61; // [sp+178h] [-178h]
  __int64 v62; // [sp+180h] [-170h]
  __int64 v63; // [sp+188h] [-168h]
  __int64 v64; // [sp+190h] [-160h]
  __int64 v65; // [sp+198h] [-158h]
  __int64 v66; // [sp+1A0h] [-150h]
  __int64 v67; // [sp+1A8h] [-148h]
  __int64 v68; // [sp+1B0h] [-140h]
  __int64 v69; // [sp+1B8h] [-138h]
  __int64 v70; // [sp+1C0h] [-130h]
  __int64 v71; // [sp+1C8h] [-128h]
  __int64 v72; // [sp+1D0h] [-120h]
  __int64 v73; // [sp+1D8h] [-118h]
  __int64 v74; // [sp+1E0h] [-110h]
  __int64 v75; // [sp+1E8h] [-108h]
  __int64 v76; // [sp+1F0h] [-100h]
  __int64 v77; // [sp+1F8h] [-F8h]
  __int64 v78; // [sp+200h] [-F0h]
  __int64 v79; // [sp+208h] [-E8h]
  __int64 v80; // [sp+210h] [-E0h]
  __int64 v81; // [sp+218h] [-D8h]
  __int64 v82; // [sp+220h] [-D0h]
  __int64 v83; // [sp+228h] [-C8h]

  v10 = Sys_Milliseconds();
  v12 = 0.0;
  v13 = __PAIR64__(transcodeJobHistoryTime, lastTranscodeTime);
  lastTranscodeTime = v10;
  v14 = (4 * transcodeJobHistoryIndex) & 0x3C;
  v15 = 0.0;
  v16 = 0.0;
  v17 = 2;
  v18 = transcodeJobHistoryIndex + 1;
  *(int *)((char *)transcodeJobHistoryTime + v14) = v10 - v13;
  transcodeJobHistoryIndex = v18;
  *(int *)((char *)transcodeJobHistoryPages + v14) = numTranscodePages;
  v19 = 0;
  *(int *)((char *)transcodeJobHistoryBytes + v14) = totalStreamedPageData;
  do
  {
    if ( *(int *)(v19 * 4 + HIDWORD(v13)) > 0 )
    {
      DWORD2(v20) = *(_DWORD *)(v19 * 4 + HIDWORD(v13));
      LODWORD(v20) = transcodeJobHistoryPages[v19];
      DWORD1(v20) = transcodeJobHistoryBytes[v19];
      LODWORD(v13) = transcodeJobHistoryGPUTime[v19];
      v73 = *(_QWORD *)((char *)&v20 + 4);
      v56 = v20;
      v55 = *(_QWORD *)(&v11 - 1);
      v68 = v13;
      v12 = (float)((float)((float)(__int64)v20 * (float)((float)1000.0 / (float)*(__int64 *)((char *)&v20 + 4)))
                  + (float)v12);
      v15 = (float)((float)((float)*(__int64 *)(&v11 - 1)
                          * (float)((float)1000.0 / (float)*(__int64 *)((char *)&v20 + 4)))
                  + (float)v15);
      v16 = (float)((float)v13 + (float)v16);
    }
    LODWORD(v13) = *(_DWORD *)(v19 * 4 + HIDWORD(v13) + 4);
    if ( (int)v13 > 0 )
    {
      v79 = v13;
      LODWORD(v21) = transcodeJobHistoryGPUTime[v19 + 1];
      DWORD2(v21) = transcodeJobHistoryPages[v19 + 1];
      DWORD1(v21) = transcodeJobHistoryBytes[v19 + 1];
      v75 = v21;
      v77 = *(_QWORD *)((char *)&v21 + 4);
      v81 = *(_QWORD *)(&v11 - 1);
      v16 = (float)((float)(__int64)v21 + (float)v16);
      v12 = (float)((float)((float)*(__int64 *)((char *)&v21 + 4) * (float)((float)1000.0 / (float)v13)) + (float)v12);
      v15 = (float)((float)((float)*(__int64 *)(&v11 - 1) * (float)((float)1000.0 / (float)v13)) + (float)v15);
    }
    LODWORD(v13) = *(_DWORD *)(v19 * 4 + HIDWORD(v13) + 8);
    if ( (int)v13 > 0 )
    {
      v62 = v13;
      DWORD2(v22) = transcodeJobHistoryGPUTime[v19 + 2];
      DWORD1(v22) = transcodeJobHistoryPages[v19 + 2];
      v23 = (float)v13;
      LODWORD(v13) = transcodeJobHistoryBytes[v19 + 2];
      LODWORD(v22) = DWORD1(v22);
      v78 = *(_QWORD *)((char *)&v22 + 4);
      v64 = v13;
      v83 = v22;
      v16 = (float)((float)*(__int64 *)((char *)&v22 + 4) + (float)v16);
      v12 = (float)((float)((float)(__int64)v22 * (float)((float)1000.0 / (float)v23)) + (float)v12);
      v15 = (float)((float)((float)v13 * (float)((float)1000.0 / (float)v23)) + (float)v15);
    }
    LODWORD(v13) = *(_DWORD *)(v19 * 4 + HIDWORD(v13) + 12);
    if ( (int)v13 > 0 )
    {
      v66 = v13;
      DWORD2(v24) = transcodeJobHistoryPages[v19 + 3];
      DWORD1(v24) = transcodeJobHistoryGPUTime[v19 + 3];
      LODWORD(v13) = transcodeJobHistoryBytes[v19 + 3];
      LODWORD(v24) = DWORD1(v24);
      v82 = *(_QWORD *)((char *)&v24 + 4);
      v60 = v13;
      v74 = v24;
      v16 = (float)((float)(__int64)v24 + (float)v16);
      v12 = (float)((float)((float)*(__int64 *)((char *)&v24 + 4) * (float)((float)1000.0 / (float)v66)) + (float)v12);
      v15 = (float)((float)((float)v13 * (float)((float)1000.0 / (float)v66)) + (float)v15);
    }
    LODWORD(v13) = *(_DWORD *)(v19 * 4 + HIDWORD(v13) + 16);
    if ( (int)v13 > 0 )
    {
      v76 = v13;
      HIDWORD(v25) = transcodeJobHistoryGPUTime[v19 + 4];
      v26 = transcodeJobHistoryPages[v19 + 4];
      LODWORD(v13) = transcodeJobHistoryBytes[v19 + 4];
      LODWORD(v25) = HIDWORD(v25);
      v70 = *(_QWORD *)(&v11 - 1);
      v80 = v13;
      v72 = v25;
      v16 = (float)((float)v25 + (float)v16);
      v12 = (float)((float)((float)*(__int64 *)(&v11 - 1) * (float)((float)1000.0 / (float)v76)) + (float)v12);
      v15 = (float)((float)((float)v13 * (float)((float)1000.0 / (float)v76)) + (float)v15);
    }
    LODWORD(v13) = *(_DWORD *)(v19 * 4 + HIDWORD(v13) + 20);
    if ( (int)v13 > 0 )
    {
      v61 = v13;
      HIDWORD(v27) = transcodeJobHistoryGPUTime[v19 + 5];
      v28 = transcodeJobHistoryPages[v19 + 5];
      LODWORD(v13) = transcodeJobHistoryBytes[v19 + 5];
      LODWORD(v27) = HIDWORD(v27);
      v63 = *(_QWORD *)(&v11 - 1);
      v65 = v13;
      v67 = v27;
      v12 = (float)((float)((float)*(__int64 *)(&v11 - 1) * (float)((float)1000.0 / (float)v61)) + (float)v12);
      v15 = (float)((float)((float)v13 * (float)((float)1000.0 / (float)v61)) + (float)v15);
      v16 = (float)((float)v27 + (float)v16);
    }
    LODWORD(v13) = *(_DWORD *)(v19 * 4 + HIDWORD(v13) + 24);
    if ( (int)v13 > 0 )
    {
      v69 = v13;
      HIDWORD(v29) = transcodeJobHistoryGPUTime[v19 + 6];
      v30 = transcodeJobHistoryPages[v19 + 6];
      LODWORD(v13) = transcodeJobHistoryBytes[v19 + 6];
      LODWORD(v29) = HIDWORD(v29);
      v71 = *(_QWORD *)(&v11 - 1);
      v57 = v13;
      v58 = v29;
      v12 = (float)((float)((float)*(__int64 *)(&v11 - 1) * (float)((float)1000.0 / (float)v69)) + (float)v12);
      v15 = (float)((float)((float)v13 * (float)((float)1000.0 / (float)v69)) + (float)v15);
      v16 = (float)((float)v29 + (float)v16);
    }
    LODWORD(v13) = *(_DWORD *)(v19 * 4 + HIDWORD(v13) + 28);
    if ( (int)v13 > 0 )
    {
      v59 = v13;
      HIDWORD(v31) = transcodeJobHistoryGPUTime[v19 + 7];
      v32 = transcodeJobHistoryPages[v19 + 7];
      LODWORD(v31) = HIDWORD(v31);
      v12 = (float)((float)((float)*(__int64 *)(&v11 - 1) * (float)((float)1000.0 / (float)v13)) + (float)v12);
      LODWORD(v13) = transcodeJobHistoryBytes[v19 + 7];
      v15 = (float)((float)((float)v13 * (float)((float)1000.0 / (float)v59)) + (float)v15);
      v16 = (float)((float)v31 + (float)v16);
    }
    v19 += 8;
    --v17;
  }
  while ( v17 != 0 );
  v33 = (float)((float)v12 * (float)0.0625);
  if ( vt_showStats.valueInteger != 0 )
  {
    HIDWORD(v56) = 0;
    HIDWORD(v55) = 0;
    idVirtualTextureSystem::GetDiskStatsForFeedback(
      this,
      transcodePageIndices,
      numCacheLines: (int *)&v56,
      numSeekAndReadMsec: (int *)&v55);
    if ( (_S13_29 & 1) == 0 )
    {
      handle_3.time = 0;
      _S13_29 |= 1u;
      handle_3.index = -1;
    }
    DWORD1(v35) = &tr;
    DWORD2(v35) = transcodePageIndices->pageStats[0].numVisPages;
    v59 = *(_QWORD *)((char *)&v35 + 4);
    renderWidth = tr.renderWidth;
    LODWORD(v35) = tr.renderHeight;
    v58 = *(_QWORD *)(&v34 - 1);
    DWORD2(v35) = transcodePageIndices->pageStats[0].numTopPages;
    v57 = v35;
    ((void (__fastcall *)(double, double))console->PrintOverlay)(a1: 1.0, a2: 1.0);
    if ( transcodeDebugGraph == nullptr )
    {
      transcodeDebugGraph = console->CreateGraph(this: console, a2: 100);
      transcodeDebugGraph->bgColor = idColor::colorBlack;
    }
    v37 = renderSystem->GetWidth(this: renderSystem);
    v38 = transcodeDebugGraph;
    LODWORD(v39) = numTranscodePages;
    DWORD2(v39) = v37 - 250;
    DWORD1(v39) = "olor specular";
    LODWORD(v40) = maxTranscodePagesPerFrame;
    transcodeDebugGraph->position.y = 340.0;
    v38->position.z = 100.0;
    v38->position.w = 100.0;
    v38->position.x = (float)*(__int64 *)((char *)&v39 + 4);
    v38->enable = true;
    idDebugGraph::SetValue(
      this: v38,
      b: -1,
      value: (float)((float)(__int64)v39 / (float)v40),
      color: (const idColor *)"olor specular",
      a5: &idColor::colorRed.r);
  }
  else if ( transcodeDebugGraph != nullptr )
  {
    transcodeDebugGraph->enable = false;
  }
  if ( com_logMetrics.valueInteger != 0 )
  {
    Sys_MutexLock(handle: &this->metricMutex.handle, blocking: true);
    LODWORD(v41) = this->physicalPagesPool[0].NUM_PHYSICAL_PAGES;
    idGaugeMetric::Log(this: &this->vmtrTotalPagesMetric, x: (float)v41, skipPush: v42);
    idGaugeMetric::Log(this: &this->vmtrBiasMetric, x: this->physicalPagesPool[0].feedbackDynamicLodBias, skipPush: v43);
    LODWORD(v44) = this->physicalPagesPool[1].NUM_PHYSICAL_PAGES;
    idGaugeMetric::Log(this: &this->specTotalPagesMetric, x: (float)v44, skipPush: v45);
    idGaugeMetric::Log(this: &this->specBiasMetric, x: this->physicalPagesPool[1].feedbackDynamicLodBias, skipPush: v46);
    LODWORD(v47) = this->physicalPagesPool[2].NUM_PHYSICAL_PAGES;
    HIDWORD(v47) = 1;
    idGaugeMetric::Log(this: &this->diffuseTotalPagesMetric, x: (float)v47, skipPush: v48);
    idGaugeMetric::Log(
      this: &this->diffuseBiasMetric,
      x: this->physicalPagesPool[2].feedbackDynamicLodBias,
      skipPush: v49);
    Sys_MutexUnlock(handle: &this->metricMutex.handle);
  }
  v50 = 0;
  data = vt_recordStats.valueString.data;
  if ( *vt_recordStats.valueString.data != 0 )
  {
    do
      ++v50;
    while ( vt_recordStats.valueString.data[v50] != 0 );
    if ( v50 != 0 )
    {
      if ( file_0 != nullptr )
      {
        v52 = file_0->GetName(this: file_0);
        v54 = idStr::Icmp(s1: v52, s2: data) == 0;
        v53 = file_0;
        if ( v54 )
          goto LABEL_38;
        if ( file_0 != nullptr )
          ((void (__fastcall *)(idFile *, int))file_0->dtr_idFile)(a1: file_0, a2: 1);
        data = vt_recordStats.valueString.data;
      }
      v53 = fileSystem->OpenFileWrite(this: fileSystem, a2: data, a3: 2);
      file_0 = v53;
LABEL_38:
      if ( v53 != nullptr )
        v53->WriteFloatString(this: v53, a2: "%f\r\n", LODWORD(v33), v33);
      return;
    }
  }
  if ( file_0 != nullptr )
  {
    file_0->Flush(this: file_0);
    if ( file_0 != nullptr )
      ((void (__fastcall *)(idFile *, int))file_0->dtr_idFile)(a1: file_0, a2: 1);
    file_0 = nullptr;
  }
}


// ========================================================================
// ?TranscodeFeedback@idVirtualTextureSystem@@AAA_NPBUpageIndices_t@@AAH_N2@Z
// EA  : 0x82983E68
// RVA : 0x00983E68
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idVirtualTextureSystem::TranscodeFeedback(
        idVirtualTextureSystem *this,
        const pageIndices_t *transcodePageIndices,
        int *transcodePageIndicesOffset,
        bool blocking,
        bool lockPages)
{
  idVirtualTextureSystem *v5; // r26
  __int64 v9; // r14
  int *p_currentTranscodeJobList; // r24
  int v11; // r11
  char *v12; // r10
  char *v13; // r29
  int v14; // r11
  int v15; // r21
  char v17; // r11
  int v18; // r10
  bool *p_pageImageCompressed; // r9
  char v20; // r11
  int v21; // r10
  bool v22; // r4
  int v23; // r15
  int v24; // r16
  __int128 v25; // r7 OVERLAPPED
  int v26; // r18
  unsigned __int64 v27; // r11
  __int64 v28; // r25
  idVirtualTexture *v29; // r23
  unsigned int v30; // r22
  unsigned __int16 v31; // r8
  int v32; // r6
  int v33; // r17
  unsigned int v34; // r11
  idPhysicalPages *physicalPages; // r26
  unsigned int v36; // r7
  texturePage_t *v37; // r19
  int v38; // r11
  int v39; // r10
  unsigned int v40; // r5
  int v41; // r11
  int v42; // r10
  int v43; // r30
  int v44; // r11
  int v45; // r4
  int v46; // r8
  int feedbackFrameNum; // r5
  int v48; // r11
  __int64 v49; // r8
  bool v50; // r11
  int v51; // r20
  int diskOffsetScale; // r8
  int v53; // r4
  int v54; // r10
  int v55; // r30
  int v56; // r27
  texturePage_t *v57; // r10
  texturePage_t *coarser; // r11
  unsigned __int16 pageY; // r9
  unsigned __int16 pageX; // r7
  int v61; // r9
  int v62; // r11
  char v63; // r11
  idFile *pageFileInstalled; // r3
  pageHeader_t *p_header; // r29
  bool v66; // r28
  unsigned __int16 level; // r9
  unsigned __int16 y; // r10
  unsigned __int16 x; // r11
  pageCompression_t pageCompression; // r28
  texturePage_t *v71; // r3
  texturePage_t *v72; // r30
  int v73; // r9
  int v74; // r8
  unsigned __int16 v75; // r10
  unsigned int v76; // r9
  unsigned __int16 v77; // r8
  unsigned int v78; // r7
  unsigned __int16 v79; // r6
  unsigned int v80; // r5
  unsigned __int16 v81; // r4
  _WORD *v82; // r10
  texturePage_t **v83; // r11
  int i; // ctr
  int v85; // r11
  int v86; // r10
  char v87; // r11
  int v88; // r5
  pageCompression_t v89; // r11
  const unsigned __int8 *v90; // r9
  char v91; // r9
  int v92; // r18
  bool v93; // xer_ca
  char v94; // r3
  char v95; // r3
  char v96; // r3
  char v97; // r8
  char v98; // r5
  int v99; // r29
  int v100; // r24
  int v101; // r3
  __int128 v102; // r8
  unsigned __int64 v103; // r11
  int v104; // r3 OVERLAPPED
  char v105; // r11
  pageCompression_t inPageCompression; // r11
  const unsigned __int8 *inPageHeader; // r7
  int v108; // r6
  int v109; // r11
  void (__fastcall *v110)(const transcodeParms_t *); // r11
  int v111; // r11
  void (__fastcall *TranscodePageFunc)(const transcodeParms_t *); // r11
  int v113; // r11
  int v114; // r9
  transcodeParms_t *v115; // r29
  int v116; // r6
  transcodeParms_t *v117; // r5
  int v118; // r11
  int v119; // r4
  int v120; // r30
  idParallelJobList **p_parallelJobList; // r30
  bool v122; // r3
  idParallelJobList *v123; // r4
  int v124; // [sp+8h] [-208h]
  pfcRequest_t v125; // [sp+Ch] [-204h]
  unsigned __int8 v126; // [sp+60h] [-1B0h]
  char v127; // [sp+61h] [-1AFh]
  int *v128; // [sp+64h] [-1ACh]
  int v129; // [sp+68h] [-1A8h]
  char v130; // [sp+6Ch] [-1A4h]
  char v131; // [sp+6Dh] [-1A3h]
  unsigned int v132; // [sp+70h] [-1A0h]
  pageHeader_t *v133; // [sp+74h] [-19Ch]
  int v134; // [sp+78h] [-198h]
  int v135; // [sp+7Ch] [-194h]
  int v136; // [sp+80h] [-190h]
  int v137; // [sp+84h] [-18Ch]
  int v138; // [sp+88h] [-188h]
  int v139; // [sp+8Ch] [-184h]
  int v140; // [sp+94h] [-17Ch]
  int valueInteger; // [sp+98h] [-178h]
  int v142; // [sp+9Ch] [-174h]
  BOOL v143; // [sp+A0h] [-170h]
  int v144; // [sp+A8h] [-168h]
  int v145; // [sp+DCh] [-134h]
  int v146; // [sp+E4h] [-12Ch]
  int v147; // [sp+108h] [-108h]
  texturePage_t *v148; // [sp+11Ch] [-F4h]
  int totalNumPages; // [sp+120h] [-F0h]
  transcodeParms_t *v150; // [sp+124h] [-ECh]
  pageHeader_t v151; // [sp+130h] [-E0h] BYREF
  _BYTE v152[16]; // [sp+160h] [-B0h] BYREF
  rangeId_t v153; // [sp+170h] [-A0h]

  v5 = this;
  idStreamFileCache::NewFrame(this: streamFileCache);
  if ( vt_singleStep.valueInteger >= 0 )
  {
    if ( vt_singleStep.valueInteger == 0 )
      return 0;
    idCVar::SetInteger(this: &vt_singleStep, newValue: vt_singleStep.valueInteger - 1, force: true);
  }
  LODWORD(v9) = 0;
  v143 = blocking;
  if ( blocking )
  {
    p_currentTranscodeJobList = &v5->currentTranscodeJobList;
    v128 = &v5->currentTranscodeJobList;
    idParallelJobList::Wait(this: v5->transcodeJobList[v5->currentTranscodeJobList].parallelJobList);
    goto LABEL_11;
  }
  v11 = 0;
  if ( *vt_recordStats.valueString.data != 0 )
  {
    do
      ++v11;
    while ( vt_recordStats.valueString.data[v11] != 0 );
    if ( v11 != 0 )
    {
      p_currentTranscodeJobList = &v5->currentTranscodeJobList;
      v128 = &v5->currentTranscodeJobList;
      idParallelJobList::Wait(this: v5->transcodeJobList[v5->currentTranscodeJobList].parallelJobList);
LABEL_10:
      ++v5->feedbackFrameNum;
LABEL_11:
      v12 = &v5->vmtrPath[64 * *p_currentTranscodeJobList];
      v13 = v12 + 50360;
      if ( v12[50420] != 0 && idParallelJobList::TryWait(this: *(idParallelJobList **)v13) )
      {
        ((void (__fastcall *)(_BYTE *))console->GetTimeRangeColor)(a1: v152);
        v153 = RANGE_RENDER;
        console->BeginTimeRange(this: console, a2: RANGE_RENDER, a3: &idColor::colorOrange);
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)v13 + 1);
        v13[60] = 0;
        console->BeginTimeRange(this: console, a2: v153, a3: (const idColor *)v152);
      }
      v14 = *p_currentTranscodeJobList << 6;
      *p_currentTranscodeJobList ^= 1u;
      v15 = (int)v5->transcodeJobList + v14;
      v139 = v15;
      v5->pageUploadCount = v5->pageUploadCount
                          - *(int *)((char *)&v5->transcodeJobList[0].pageImagesUpdateParms.numCancelled + v14)
                          + *(int *)((char *)&v5->transcodeJobList[0].pageImagesUpdateParms.numUpdates + v14);
      console->AddJobListTimeRange(
        this: console,
        a2: RANGE_JBL_VIRT,
        a3: &idColor::colorLtGrey,
        a4: *(const idParallelJobList **)v15,
        a5: 0);
      totalNumPages = transcodePageIndices->totalNumPages;
      if ( *transcodePageIndicesOffset >= totalNumPages )
      {
        idVirtualTextureSystem::UpdateStats(
          this: v5,
          transcodePageIndices,
          numTranscodePages: 0,
          maxTranscodePagesPerFrame: 1,
          totalStreamedPageData: 0);
        return 1;
      }
      v17 = 1;
      v18 = 0;
      p_pageImageCompressed = &v5->physicalPagesPool[0].pageImageCompressed;
      valueInteger = vt_maxPPF.valueInteger;
      while ( *p_pageImageCompressed )
      {
        ++v18;
        p_pageImageCompressed += 136;
        if ( v18 >= 4 )
          goto LABEL_24;
      }
      v17 = 0;
LABEL_24:
      if ( v17 == 0
        || vt_stripPageBorders.valueInteger != 0
        || vt_showPageSources.valueInteger != 0
        || vt_showPageMips.valueInteger != 0
        || vt_showPageColors.valueInteger != 0
        || vt_showPageNumbers.valueInteger != 0
        || vt_showPageInfo.valueInteger != 0
        || vt_showPageBorders.valueInteger != 0
        || vt_showPageSizes.valueInteger != 0
        || (v20 = 0, vt_showPageUsage.valueInteger != 0) )
      {
        v20 = 1;
      }
      v130 = v20;
      v21 = vt_useTranscodeJobs.valueInteger;
      v134 = vt_useTranscodeJobs.valueInteger;
      if ( v20 != 0 )
      {
        if ( vt_useTranscodeJobs.valueInteger >= 0 )
        {
          if ( vt_useTranscodeJobs.valueInteger <= 1 )
            goto LABEL_41;
          v21 = 1;
        }
        else
        {
          v21 = 0;
        }
        v134 = v21;
      }
LABEL_41:
      *(_DWORD *)(v15 + 36) = 0;
      *(_DWORD *)(v15 + 32) = 0;
      *(_BYTE *)(v15 + 40) = 0;
      *(_BYTE *)(v15 + 41) = vt_usePageTablePBOs.valueInteger != 0;
      *(_BYTE *)(v15 + 42) = vt_useUnsynchronizedPageTablePBOs.valueInteger != 0;
      v22 = vt_skipPhysicalTextureUploads.valueInteger != 0;
      *(_DWORD *)(v15 + 48) = 0;
      *(_DWORD *)(v15 + 52) = 0;
      *(_BYTE *)(v15 + 56) = 0;
      *(_BYTE *)(v15 + 43) = v22;
      *(_BYTE *)(v15 + 57) = vt_usePageTablePBOs.valueInteger != 0;
      *(_BYTE *)(v15 + 58) = vt_useUnsynchronizedPageTablePBOs.valueInteger != 0;
      *(_BYTE *)(v15 + 59) = vt_skipPhysicalTextureUploads.valueInteger != 0;
      if ( v21 == 1 )
      {
        idParallelJobList::AddJob(
          this: *(idParallelJobList **)v15,
          function: (void (__fastcall *)(void *))UpdatePageImagesJob,
          data: (void *)(v15 + 28));
        idParallelJobList::InsertSyncPoint(this: *(idParallelJobList **)v15, syncType: SYNC_SIGNAL);
        idParallelJobList::InsertSyncPoint(this: *(idParallelJobList **)v15, syncType: SYNC_SYNCHRONIZE);
        *(_BYTE *)(v15 + 40) = 1;
      }
      v23 = *(_DWORD *)(v15 + 12);
      *(_DWORD *)(v15 + 4) = 0;
      v24 = *transcodePageIndicesOffset;
      v142 = v23;
      v136 = 0;
      v135 = 0;
      v126 = 1;
      v127 = 1;
      v137 = *transcodePageIndicesOffset;
      if ( *transcodePageIndicesOffset >= totalNumPages )
        goto LABEL_188;
      while ( 1 )
      {
        *((_QWORD *)&v25 + 1) = transcodePageIndices->indices[v24];
        *(_QWORD *)((char *)&v25 + 4) = (unsigned __int64)v25 >> 28;
        *(_QWORD *)&v25 = (unsigned __int64)v25 >> 24;
        v26 = BYTE11(v25) & 0xF;
        *(_QWORD *)((char *)&v25 + 12) = (unsigned __int64)v25 >> 2;
        v27 = (unsigned __int64)v25 >> 13;
        *(_QWORD *)((char *)&v25 - 4) = DWORD2(v25);
        *((_QWORD *)&v25 + 1) = WORD4(v25);
        v28 = *(_QWORD *)&v25 & 0x7FF0000000FLL;
        v29 = this->vtPtrs[v26];
        v30 = v27 & 0x7FF;
        v32 = v31;
        v145 = BYTE7(v25) & 0xF;
        v146 = WORD1(v25) & 0x7FF;
        v33 = v25 & 0x1F;
        v147 = v31;
        if ( v29 != nullptr )
        {
          v34 = v29->mipLevelPagesWide[v28];
          if ( HIDWORD(v28) < v34 && v30 < v34 )
          {
            physicalPages = v29->physicalPages;
            v36 = 1664525 * (((((_DWORD)v28 << 11) | v30) << 11) | HIDWORD(v28)) + 1013904223;
            v37 = nullptr;
            v38 = physicalPages->pageHash.pageHashTable[((((v36 >> 11) ^ v36) >> 11)
                                                       ^ v36)
                                                      & physicalPages->pageHash.hashMask];
            if ( v38 != 0xFFFF )
            {
              while ( 1 )
              {
                v39 = (int)&physicalPages->pageHash.pageHashIndex[v38];
                if ( *(_DWORD *)v39 == ((((((16 * v26) | (unsigned int)v28) << 11) | v30) << 11) | HIDWORD(v28)) )
                  break;
                v38 = *(unsigned __int16 *)(v39 + 6);
                if ( v38 == 0xFFFF )
                  goto LABEL_50;
              }
              v43 = __ROL4__(*(unsigned __int16 *)(v39 + 4), 16) | v38;
              if ( v43 != -1 )
              {
                if ( (v43 & 0xFFFF0000) != 0 )
                {
                  if ( lockPages )
                  {
                    v44 = (int)physicalPages->pages + 8 * (unsigned __int16)v43 + 8 * ((8 * v43) & 0x7FFF8);
                    if ( *(_BYTE *)(v44 + 1) == 0 )
                    {
                      v45 = *(unsigned __int16 *)(v44 + 8);
                      *(_BYTE *)(v44 + 1) = 1;
                      idPhysicalPageList::Remove(this: &physicalPages->unlockedPageList, physicalPageNum: v45);
                      ++physicalPages->numLockedPages;
                    }
                  }
                  v46 = (4 * v43) & 0x3FFFC;
                  feedbackFrameNum = this->feedbackFrameNum;
                  *(int *)((char *)physicalPages->pagePriority + v46) = v33;
                  *(int *)((char *)physicalPages->pageFrameNum + v46) = feedbackFrameNum;
                }
                goto LABEL_184;
              }
            }
LABEL_50:
            if ( (unsigned int)v28 < v29->header.numLevels - 1 )
            {
              v40 = 1664525 * ((((((_DWORD)v28 + 1) << 11) | (v30 >> 1)) << 11) | (HIDWORD(v28) >> 1)) + 1013904223;
              v41 = physicalPages->pageHash.pageHashTable[((((v40 >> 11) ^ v40) >> 11)
                                                         ^ v40)
                                                        & physicalPages->pageHash.hashMask];
              if ( v41 == 0xFFFF )
                goto LABEL_184;
              while ( 1 )
              {
                v42 = (int)&physicalPages->pageHash.pageHashIndex[v41];
                if ( *(_DWORD *)v42 == ((((((16 * v26) | ((_DWORD)v28 + 1)) << 11) | (v30 >> 1)) << 11)
                                      | (HIDWORD(v28) >> 1)) )
                  break;
                v41 = *(unsigned __int16 *)(v42 + 6);
                if ( v41 == 0xFFFF )
                  goto LABEL_184;
              }
              v48 = __ROL4__(*(unsigned __int16 *)(v42 + 4), 16) | v41;
              if ( v48 == -1 || (v48 & 0xFFFF0000) == 0 )
                goto LABEL_184;
              v37 = (texturePage_t *)((char *)physicalPages->pages
                                    + 8 * (unsigned __int16)v48
                                    + 8 * ((8 * v48) & 0x7FFF8));
            }
            v50 = false;
            if ( physicalPages->freePageList.lastPageIndex - physicalPages->freePageList.firstPageIndex == -1 )
            {
              v49 = physicalPages->unlockedPageList.physicalPageNums[physicalPages->unlockedPageList.indexMask
                                                                   & physicalPages->unlockedPageList.firstPageIndex];
              if ( physicalPages->pageFrameNum[v49] >= virtualTextureSystem.feedbackFrameNum - 1
                && ((v33 & 0x10) == 0 || (physicalPages->pagePriority[v49] & 0x10) != 0) )
              {
                v50 = true;
              }
            }
            if ( !v50
              && (v37 == nullptr
               || (unsigned int)v28 >= vt_reducePopping.valueInteger
               || v37->transcodeFrameNum != this->feedbackFrameNum) )
            {
              break;
            }
          }
        }
LABEL_184:
        v137 = ++v24;
        ++*transcodePageIndicesOffset;
        if ( v24 >= totalNumPages )
          goto LABEL_187;
      }
      v51 = (2 * v30) & 2 | BYTE3(v28) & 1;
      diskOffsetScale = v29->header.diskOffsetScale;
      if ( v37 != nullptr )
      {
        v53 = v37->finerDiskOffset[v51] * diskOffsetScale;
        v54 = v37->finerDiskLength[v51] * diskOffsetScale;
      }
      else
      {
        v53 = v29->header.subRoot.finerDiskOffset[0] * diskOffsetScale;
        v54 = v29->header.subRoot.finerDiskLength[0] * diskOffsetScale;
      }
      v55 = v54;
      v138 = 0;
      v56 = 0;
      v129 = v54;
      v144 = -1;
      v140 = -1;
      if ( vt_genMissingPages.valueInteger == 1 && v37 != nullptr )
      {
        v57 = v37;
        if ( v55 == 0 )
        {
          do
          {
            coarser = v57->coarser;
            if ( coarser == nullptr )
              break;
            pageY = v57->pageY;
            ++v56;
            pageX = v57->pageX;
            v57 = v57->coarser;
            v61 = (2 * (_BYTE)pageY) & 2 | pageX & 1;
            v55 = coarser->finerDiskLength[v61] * diskOffsetScale;
            v53 = coarser->finerDiskOffset[v61] * diskOffsetScale;
          }
          while ( v55 == 0 );
          v138 = v56;
          v129 = v55;
        }
        v62 = (1 << v56) - 1;
        v144 = v62 & HIDWORD(v28);
        v140 = v62 & v30;
      }
      v132 = (v55 + 135) & 0xFFFFFF80;
      if ( v132 + v23 + 16 < *(_DWORD *)(v15 + 12) + 0x100000 )
      {
        if ( !physicalPages->isDirectMapped
          || !v29->isDirectMapped
          || (v63 = 1, vt_useDirectTextureAccess.valueInteger == 0) )
        {
          v63 = 0;
        }
        pageFileInstalled = v29->pageFileInstalled;
        p_header = (pageHeader_t *)(v23 + 8);
        v131 = v63;
        v133 = (pageHeader_t *)(v23 + 8);
        v66 = true;
        if ( pageFileInstalled == nullptr || (int)v28 < v29->minMipLevelInstalled )
          pageFileInstalled = v29->pageFile;
        if ( pageFileInstalled == nullptr )
          goto LABEL_184;
        if ( vt_skipStreaming.valueInteger != 0 )
        {
          defaultDCTPage.header.magic = -893391612;
          defaultDCTPage.header.pageCompression = COMP_DCT;
          defaultDCTPage.header.x = WORD1(v28);
          defaultDCTPage.header.y = v30;
          defaultDCTPage.header.level = v28;
          pageHeader_t::Swap(this: &defaultDCTPage.header);
          p_header = &defaultDCTPage.header;
          v133 = &defaultDCTPage.header;
          v129 = (v29->header.diskOffsetScale + 2639) & ~(v29->header.diskOffsetScale - 1);
        }
        else if ( v55 != 0 )
        {
          if ( vt_usePageFileCache.valueInteger != 0 )
          {
            if ( idStreamFileCache::ReadCachedData(
                   this: streamFileCache,
                   cacheFile: pageFileInstalled,
                   ofs: __SPAIR64__(v53, v55),
                   length: (unsigned __int8 *)(v23 + 8),
                   dest: blocking,
                   blockingRead: (idStreamControlThread_vtbl *)((v33 << 15) + v32),
                   priority: (idStreamControlThread_vtbl *)(64 << (v28 + 4)),
                   persistence: v124,
                   pfc: v125) == v55 )
            {
              v136 += v55;
            }
            else
            {
              v126 = 0;
              v66 = false;
            }
          }
          else
          {
            v66 = (_cntlzw(v55 - pageFileInstalled->ReadOfs(
                                   this: pageFileInstalled,
                                   a2: v53,
                                   a3: (void *)(v23 + 8),
                                   a4: v55))
                 & 0x20) != 0;
          }
          if ( vt_showPageLoads.valueInteger != 0 )
            idLib::Printf(
              fmt: "Frame %i: page x %i y %i level %i source %i\n",
              this->feedbackFrameNum,
              HIDWORD(v28),
              v30,
              (_DWORD)v28,
              v26);
        }
        else
        {
          v66 = false;
        }
        if ( !v66 )
          goto LABEL_184;
        if ( p_header != nullptr )
        {
          pageHeader_t::CopySwap(this: &v151, src: p_header);
          if ( v151.magic != -893391612 )
            goto LABEL_184;
          level = v151.level;
          y = v151.y;
          x = v151.x;
          pageCompression = v151.pageCompression;
        }
        else
        {
          *(_QWORD *)&v151.magic = v9;
          *(_QWORD *)v151.finerDiskOffset = v9;
          *(_QWORD *)&v151.finerDiskOffset[2] = v9;
          *(_QWORD *)v151.finerDiskLength = v9;
          *(_QWORD *)&v151.x = v9;
          v151.pageCompression = idVirtualTexture::GetNewDiskPageCompression(this: v29);
          x = HIDWORD(v28) >> v56;
          y = v30 >> v56;
          pageCompression = v151.pageCompression;
          level = v56 + v28;
        }
        if ( x != HIDWORD(v28) >> v56
          || y != v30 >> v56
          || level != v56 + (_DWORD)v28 && vt_genMissingPages.valueInteger == 0
          || (unsigned int)pageCompression > COMP_JXR )
        {
          goto LABEL_184;
        }
        v71 = idPhysicalPages::AllocPage(
                this: physicalPages,
                vt: v29,
                coarser: v37,
                quadrant: (pageQuadrant_t)((2 * v30) & 2 | BYTE3(v28) & 1),
                deferredUnmap: (pageImagesUpdateParms_t *)(v15 + 28));
        v72 = v71;
        v148 = v71;
        v71->transcodeFrameNum = this->feedbackFrameNum;
        if ( lockPages && !v71->locked )
          idPhysicalPages::LockPage(this: physicalPages, page: v71);
        v73 = __ROL4__(v72->physicalPageNum, 2);
        v74 = this->feedbackFrameNum;
        *(int *)((char *)physicalPages->pagePriority + v73) = v33;
        *(int *)((char *)physicalPages->pageFrameNum + v73) = v74;
        v72->pageCompression = pageCompression;
        if ( v56 != 0 )
        {
          v82 = (_WORD *)&v72->finerDiskOffset[3] + 1;
          v83 = &v72->finer[3];
          for ( i = 4; i != 0; --i )
          {
            *++v83 = nullptr;
            *++v82 = 0;
          }
        }
        else
        {
          v75 = v151.finerDiskLength[0];
          v76 = v151.finerDiskOffset[1];
          v77 = v151.finerDiskLength[1];
          v78 = v151.finerDiskOffset[2];
          v79 = v151.finerDiskLength[2];
          v80 = v151.finerDiskOffset[3];
          v72->finerDiskOffset[0] = v151.finerDiskOffset[0];
          v81 = v151.finerDiskLength[3];
          v72->finerDiskLength[0] = v75;
          v72->finerDiskOffset[1] = v76;
          v72->finerDiskLength[1] = v77;
          v72->finerDiskOffset[2] = v78;
          v72->finerDiskLength[2] = v79;
          v72->finerDiskOffset[3] = v80;
          v72->finerDiskLength[3] = v81;
        }
        v85 = *(_DWORD *)(v15 + 4);
        v86 = *(_DWORD *)(v15 + 8);
        *(_DWORD *)(v15 + 4) = v85 + 1;
        v150 = (transcodeParms_t *)((v85 << 7) + v86);
        __asm { dcbz128   0, r11 }
        if ( physicalPages->physicalPagesPool == PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY
          || (v87 = 0, physicalPages->physicalPagesPool == PHYSICAL_PAGES_POOL_UNIQUE_DIFFUSE_ONLY2) )
        {
          v87 = 1;
        }
        v88 = (v87 == 0) - 1;
        v89 = v151.pageCompression;
        v150->imageFlags = (v88 & 0xFFFFFFFB) + 7;
        v150->layoutVersion = v29->layoutVersion;
        v150->numLevels = v29->header.numLevels;
        v150->pageSource = v26;
        v150->pageLevel = v145;
        v150->physicalPageNum = v148->physicalPageNum;
        v150->pageX = v146;
        v150->pageY = v30;
        v150->inPageCompression = v89;
        v150->pageHeaderSize = 40;
        if ( v89 == COMP_DCT )
        {
          v150->inPageDataLength = v129 - 56;
          v150->inPageHeader = (const unsigned __int8 *)&v133[1];
          v150->inPageData = (const unsigned __int8 *)&v133[1].finerDiskOffset[2];
        }
        else if ( v89 == COMP_HDP )
        {
          v150->inPageDataLength = v129 - 56;
          v150->inPageHeader = (const unsigned __int8 *)&v133[1];
          v150->inPageData = (const unsigned __int8 *)&v133[1].finerDiskOffset[2];
        }
        else
        {
          v90 = (const unsigned __int8 *)&v133[1];
          if ( v89 == COMP_JXR )
          {
            v150->inPageHeader = v90;
            v150->inPageData = (const unsigned __int8 *)&v133[1].finerDiskOffset[2];
            v150->inPageDataLength = v129 - 56;
          }
          else
          {
            v150->inPageHeader = nullptr;
            v150->inPageData = v90;
            v150->inPageDataLength = v129 - 40;
          }
        }
        v91 = _cntlzw(physicalPages->pageImageCompressed);
        v150->outPageDataLength = 0;
        v150->outPageCompression = ((v91 & 0x20) == 0) + 1;
        v92 = v29->header.diskOffsetScale;
        v150->tempSize = 0;
        v150->diskOffsetScale = v92;
        v150->tempData = nullptr;
        v93 = !physicalPages->pageImageCompressed;
        v150->upsampleX = v144;
        v150->targetBytePitch[1] = 512;
        v150->targetBytePitch[2] = 512;
        v150->upsampleY = v140;
        v150->upsampleLevel = v138;
        v150->targetBytePitch[0] = v93 ? 512 : 256;
        v94 = *((_BYTE *)v150 + 94);
        v150->upsampleFilter = vt_upsampleFilter.valueInteger;
        v150->upsampleSharpen = vt_upsampleSharpen.valueInteger;
        v150->upsampleNoise = vt_upsampleNoise.valueInteger;
        v150->startedExecution = false;
        v150->stripPageBorders = vt_stripPageBorders.valueInteger != 0;
        v95 = ((vt_showPageSources.valueInteger != 0) << 7) | v94 & 0x7F;
        *((_BYTE *)v150 + 94) = v95;
        v150->dbgShowPageMips = vt_showPageMips.valueInteger;
        v96 = ((vt_showPageColors.valueInteger != 0) << 6) & 0x40 | v95 & 0xBF;
        *((_BYTE *)v150 + 94) = v96;
        v97 = (32 * (vt_showPageNumbers.valueInteger != 0)) & 0x20 | v96 & 0xDF;
        *((_BYTE *)v150 + 94) = v97;
        v98 = (8 * (vt_showPageBorders.valueInteger != 0)) & 8 | v97 & 0xF7;
        *((_BYTE *)v150 + 94) = v98;
        *((_BYTE *)v150 + 94) = (16 * (vt_showPageInfo.valueInteger != 0)) & 0x10 | v98 & 0xEF;
        v150->dbgShowPageSizes = vt_showPageSizes.valueInteger;
        v99 = vt_showPageUsage.valueInteger;
        if ( vt_showPageUsage.valueInteger != 0 )
        {
          v100 = renderSystem->GetHeight(this: renderSystem);
          v101 = renderSystem->GetWidth(this: renderSystem);
          DWORD2(v102) = 160;
          HIDWORD(v103) = v101 * v99 * v147 * v100;
          LODWORD(v103) = 120;
          LODWORD(v102) = 255 * HIDWORD(v103);
          *(_QWORD *)&v102 = (unsigned __int64)v102 / v103;
          *(_QWORD *)&v104 = ((unsigned __int64)v102 / v103 / v103 / *(_QWORD *)((char *)&v102 + 4)) >> 7;
          v105 = v104;
          if ( v104 >= 1 )
          {
            if ( v104 > 255 )
              v105 = -1;
            v150->dbgShowPageUsage = v105;
          }
          else
          {
            v150->dbgShowPageUsage = 1;
          }
        }
        else
        {
          v150->dbgShowPageUsage = 0;
        }
        if ( v131 != 0 )
          idPhysicalPages::GetDirectMappedPhysicalPagePointers(
            this: physicalPages,
            physicalPageNum: v150->physicalPageNum,
            physicalPagePtr: v150->targetImage,
            physicalBytePitch: v150->targetBytePitch);
        v150->tempSize = 196608;
        v150->TranscodePageFunc = TranscodePage;
        if ( v130 != 0 )
          goto LABEL_167;
        inPageCompression = v150->inPageCompression;
        if ( inPageCompression == COMP_DXT )
        {
          v150->tempSize = v138 == 0 ? 0 : 0x4400;
          if ( v138 != 0 )
            v150->TranscodePageFunc = TranscodePage_DXT_DXT_upsample;
          else
            v150->TranscodePageFunc = TranscodePage_DXT_DXT;
          v150->inPageDataLength = 40960;
          goto LABEL_167;
        }
        if ( inPageCompression == COMP_DCT )
        {
          v150->tempSize = v138 == 0 ? 3072 : 19456;
          inPageHeader = v150->inPageHeader;
          if ( v138 != 0 )
            v150->TranscodePageFunc = TranscodePage_DCT_DXT_upsample;
          else
            v150->TranscodePageFunc = TranscodePage_DCT_DXT;
          v108 = inPageHeader[5];
        }
        else
        {
          if ( inPageCompression == COMP_HDP )
          {
            if ( v138 != 0 )
              v109 = 54272;
            else
              v109 = 37888;
            v150->tempSize = v109;
            if ( v138 != 0 )
              v110 = TranscodePage_HDP_DXT_upsample;
            else
              v110 = TranscodePage_HDP_DXT;
          }
          else
          {
            if ( inPageCompression != COMP_JXR )
            {
LABEL_167:
              if ( v150->imageFlags == 7
                && ((TranscodePageFunc = v150->TranscodePageFunc) == TranscodePage_DCT_DXT
                 || TranscodePageFunc == TranscodePage_DCT_DXT_upsample
                 || TranscodePageFunc == TranscodePage_HDP_DXT
                 || TranscodePageFunc == TranscodePage_HDP_DXT_upsample
                 || TranscodePageFunc == TranscodePage_JXR_DXT
                 || TranscodePageFunc == TranscodePage_JXR_DXT_upsample)
                && vt_splitTranscodeJobs.valueInteger != 0 )
              {
                v15 = v139;
                v113 = *(_DWORD *)(v139 + 4);
                v114 = *(_DWORD *)(v139 + 8);
                *(_DWORD *)(v139 + 4) = v113 + 1;
                v115 = (transcodeParms_t *)((v113 << 7) + v114);
                memcpy(Dst: v115, Src: v150, Size: sizeof(transcodeParms_t));
                v150->imageFlags = 5;
                v115->imageFlags = 2;
                idVirtualTextureSystem::SubmitTranscodeJob(
                  this,
                  list: *(idParallelJobList **)v139,
                  parms: v150,
                  useTranscodeJobs: v134);
                v116 = v134;
                v117 = v115;
              }
              else
              {
                v15 = v139;
                v117 = v150;
                v116 = v134;
              }
              idVirtualTextureSystem::SubmitTranscodeJob(
                this,
                list: *(idParallelJobList **)v15,
                parms: v117,
                useTranscodeJobs: v116);
              v118 = *(_DWORD *)(v15 + 48);
              v119 = *(_DWORD *)(v15 + 44);
              *(_DWORD *)(v15 + 48) = v118 + 1;
              v120 = v135 + 1;
              v23 = v132 + v142;
              v127 = v131 == 0 ? 0 : v127;
              ++v135;
              v142 += v132;
              idPhysicalPages::CreatePageImagesUpdate(
                this: physicalPages,
                vt: v29,
                physPage: v148,
                virtPage: v148,
                pageDataPBO: nullptr,
                pageData: nullptr,
                update: (pageImagesUpdate_t *)((v118 << 8) + v119));
              if ( *(int *)(v15 + 32) >= 64
                || *(int *)(v15 + 48) >= 64
                || *(int *)(v15 + 4) >= 127
                || !v143 && !lockPages && v120 >= valueInteger )
              {
                goto LABEL_186;
              }
              v24 = v137;
              goto LABEL_184;
            }
            if ( v138 != 0 )
              v111 = 151552;
            else
              v111 = 135168;
            v150->tempSize = v111;
            if ( v138 != 0 )
              v110 = TranscodePage_JXR_DXT_upsample;
            else
              v110 = TranscodePage_JXR_DXT;
          }
          v150->TranscodePageFunc = v110;
          inPageHeader = v150->inPageHeader;
          v108 = inPageHeader[4];
        }
        v150->inPageDataLength = ((v108 << 8) & 0x800)
                               + *((unsigned __int16 *)inPageHeader + 6)
                               + *((unsigned __int16 *)inPageHeader + 5)
                               + *((unsigned __int16 *)inPageHeader + 4)
                               + *((unsigned __int16 *)inPageHeader + 3);
        goto LABEL_167;
      }
LABEL_186:
      v126 = 0;
LABEL_187:
      p_currentTranscodeJobList = v128;
      v5 = this;
LABEL_188:
      v5->pageTranscodeCount += v135;
      if ( vt_skipUpdatePageImages.valueInteger != 0 )
      {
        *(_DWORD *)(v15 + 32) = 0;
        *(_DWORD *)(v15 + 48) = 0;
      }
      if ( v127 != 0 )
      {
        if ( v134 == 1 )
        {
          idParallelJobList::InsertSyncPoint(this: *(idParallelJobList **)v15, syncType: SYNC_SIGNAL);
          idParallelJobList::InsertSyncPoint(this: *(idParallelJobList **)v15, syncType: SYNC_SYNCHRONIZE);
          idParallelJobList::AddJob(
            this: *(idParallelJobList **)v15,
            function: (void (__fastcall *)(void *))UpdatePageImagesJob,
            data: (void *)(v15 + 44));
        }
        else
        {
          UpdatePageImagesJob(parms: (const pageImagesUpdateParms_t *)(v15 + 28));
          *(_BYTE *)(v15 + 40) = 1;
          UpdatePageImagesJob(parms: (const pageImagesUpdateParms_t *)(v15 + 44));
        }
        *(_BYTE *)(v15 + 56) = 1;
      }
      *(_BYTE *)(v15 + 60) = 1;
      idStreamFileCache::SignalWork(this: streamFileCache);
      p_parallelJobList = &v5->transcodeJobList[*p_currentTranscodeJobList].parallelJobList;
      v122 = idParallelJobList::TryWait(this: *p_parallelJobList);
      v123 = nullptr;
      if ( !v122 )
        v123 = *p_parallelJobList;
      idParallelJobList::Submit(this: *(idParallelJobList **)v15, waitForJobList: v123, parallelism: -1);
      idVirtualTextureSystem::UpdateStats(
        this: v5,
        transcodePageIndices,
        numTranscodePages: v135,
        maxTranscodePagesPerFrame: valueInteger,
        totalStreamedPageData: v136);
      return v143 ? 0 : v126;
    }
  }
  p_currentTranscodeJobList = &v5->currentTranscodeJobList;
  v128 = &v5->currentTranscodeJobList;
  if ( idParallelJobList::TryWait(this: v5->transcodeJobList[v5->currentTranscodeJobList].parallelJobList) )
    goto LABEL_10;
  idVirtualTextureSystem::UpdateStats(
    this: v5,
    transcodePageIndices,
    numTranscodePages: 0,
    maxTranscodePagesPerFrame: 1,
    totalStreamedPageData: 0);
  return 0;
}


// ========================================================================
// __unwind$243667
// EA  : 0x829853F4
// RVA : 0x009853F4
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_243667()
{
  int v0; // r12

  idScopedConsoleTimeRange::~idScopedConsoleTimeRange(this: (idScopedConsoleTimeRange *)(v0 - 528 + 352));
}


// ========================================================================
// ?FinishFeedback@idVirtualTextureSystem@@QAAX_NH@Z
// EA  : 0x82985420
// RVA : 0x00985420
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::FinishFeedback(
        idVirtualTextureSystem *this,
        bool lockPages,
        int maxWaitTimeInSeconds)
{
  int v6; // r23
  int v7; // r8
  int v8; // r7
  int v9; // r6
  int v10; // r5
  int v11; // r30
  __int64 v12; // r7
  double v13; // r4
  int v14; // [sp+8h] [-A8h]
  int v15; // [sp+Ch] [-A4h]
  int v16; // [sp+10h] [-A0h]
  int v17; // [sp+14h] [-9Ch]
  int v18; // [sp+18h] [-98h]
  int v19; // [sp+1Ch] [-94h]
  int v20; // [sp+20h] [-90h]
  int v21; // [sp+24h] [-8Ch]
  int v22; // [sp+28h] [-88h]
  int v23; // [sp+2Ch] [-84h]
  int v24; // [sp+30h] [-80h]
  int v25; // [sp+34h] [-7Ch]
  int v26; // [sp+38h] [-78h]
  int v27; // [sp+3Ch] [-74h]
  int v28; // [sp+40h] [-70h]
  int v29; // [sp+44h] [-6Ch]
  int v30; // [sp+48h] [-68h]
  int v31; // [sp+4Ch] [-64h]
  int v32[24]; // [sp+50h] [-60h] BYREF

  v6 = Sys_Microseconds() >> 32;
  idVirtualTextureSystem::WaitForLastAnalyzeFeedback(this);
  if ( this->cancelToTerminate )
  {
LABEL_6:
    idLib::Printf(fmt: "VTS: CANCEL TO TERMINATE!\n");
  }
  else
  {
    while ( maxWaitTimeInSeconds <= 0
         || (unsigned int)((Sys_Microseconds() >> 32) - v6) <= 1000000 * maxWaitTimeInSeconds )
    {
      v32[0] = 0;
      if ( (unsigned __int8)idVirtualTextureSystem::TranscodeFeedback(
                              this,
                              transcodePageIndices: this->pageIndices[this->currentPageIndices],
                              transcodePageIndicesOffset: v32,
                              blocking: false,
                              lockPages) != 0 )
        goto LABEL_8;
      idVirtualTextureSystem::StreamFeedback(
        this,
        transcodePageIndices: this->pageIndices[this->currentPageIndices],
        a3: v10,
        a4: v9,
        a5: v8,
        a6: v7,
        a7: 0,
        a8: 4 * (this->currentPageIndices + 12583),
        a9: v14,
        a10: v15,
        a11: v16,
        a12: v17,
        a13: v18,
        a14: v19,
        a15: v20,
        a16: v21,
        a17: v22,
        a18: v23,
        a19: v24,
        a20: v25,
        a21: v26,
        a22: v27,
        a23: v28,
        a24: v29,
        a25: v30,
        a26: v31,
        a27: v32[0]);
      mgthread_sleep(ms: 16);
      if ( this->cancelToTerminate )
        goto LABEL_6;
    }
    idLib::Printf(fmt: "FinishFeedback: Terminated due to maximum time allowed.\n");
  }
LABEL_8:
  v11 = 2;
  v32[0] = this->pageIndices[this->currentPageIndices]->totalNumPages;
  do
  {
    idVirtualTextureSystem::TranscodeFeedback(
      this,
      transcodePageIndices: this->pageIndices[this->currentPageIndices],
      transcodePageIndicesOffset: v32,
      blocking: true,
      lockPages);
    --v11;
  }
  while ( v11 != 0 );
  this->physicalPagesPool[0].feedbackDynamicLodBias = 0.0;
  this->physicalPagesPool[1].feedbackDynamicLodBias = 0.0;
  this->physicalPagesPool[2].feedbackDynamicLodBias = 0.0;
  this->physicalPagesPool[3].feedbackDynamicLodBias = 0.0;
  LODWORD(v12) = (Sys_Microseconds() >> 32) - v6;
  *(_QWORD *)v32 = v12;
  v13 = (float)((float)v12 * (float)0.000001);
  idLib::Printf(fmt: (const char *)HIDWORD(v13), LODWORD(v13));
}


// ========================================================================
// ?RunTranscodeBenchmark@idVirtualTextureSystem@@QAA_NAAM0@Z
// EA  : 0x829855E8
// RVA : 0x009855E8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idVirtualTextureSystem::RunTranscodeBenchmark(
        idVirtualTextureSystem *this,
        float *megaTexelsPerSecond,
        float *score)
{
  pageStats_t v3; // r28
  const char *v7; // r3
  int v9; // r11
  char **p_data; // r10
  char *v11; // r11
  idVirtualTexture *v12; // r21
  unsigned int *p_currentPageIndices; // r29
  pageIndices_t *v14; // r11
  __int64 v15; // r6
  int v16; // r24
  unsigned int v17; // r25
  int *p_pageTranscodeCount; // r27
  int i; // r23
  int v20; // r3
  int v21; // r26
  int v22; // r9
  int v23; // r8
  int v24; // r7
  int v25; // r6
  int v26; // r5
  unsigned __int64 v27; // r4
  double v28; // fp1
  __int64 v29; // r9
  double v30; // fp0
  double v31; // fp0
  const char *v32; // r29
  const char *ProcessorString; // r3
  __int64 v34; // r10
  __int64 v35; // r6
  __int64 v36; // r8
  va *v37; // r3
  __int64 v38; // r3 OVERLAPPED
  __int64 v39; // r10
  __int64 v40; // r8
  double v41; // r5 OVERLAPPED
  va *v42; // r3
  __int64 v43; // r8
  __int64 v44; // r6
  __int64 v45; // r10
  va *v46; // r3
  __int64 v47; // r6
  __int64 v48; // r10
  __int64 v49; // r8
  va *v50; // r3
  __int64 v51; // r6
  __int64 v52; // r10
  __int64 v53; // r8
  va *v54; // r3
  __int64 v55; // r10
  __int64 v56; // r8
  __int64 v57; // r6
  va *v58; // r3
  __int64 v59; // r8
  __int64 v60; // r10
  __int64 v61; // r6
  va *v62; // r3
  __int64 v63; // r6
  __int64 v64; // r10
  __int64 v65; // r8
  va *v66; // r3
  __int64 v67; // r6
  __int64 v68; // r10
  __int64 v69; // r8
  va *v70; // r3
  int v71; // [sp+8h] [-1178h]
  int v72; // [sp+8h] [-1178h]
  int v73; // [sp+8h] [-1178h]
  int v74; // [sp+8h] [-1178h]
  int v75; // [sp+8h] [-1178h]
  int v76; // [sp+8h] [-1178h]
  int v77; // [sp+8h] [-1178h]
  int v78; // [sp+8h] [-1178h]
  int v79; // [sp+8h] [-1178h]
  int v80; // [sp+Ch] [-1174h]
  int v81; // [sp+Ch] [-1174h]
  int v82; // [sp+Ch] [-1174h]
  int v83; // [sp+Ch] [-1174h]
  int v84; // [sp+Ch] [-1174h]
  int v85; // [sp+Ch] [-1174h]
  int v86; // [sp+Ch] [-1174h]
  int v87; // [sp+Ch] [-1174h]
  int v88; // [sp+Ch] [-1174h]
  int v89; // [sp+10h] [-1170h]
  int v90; // [sp+10h] [-1170h]
  int v91; // [sp+10h] [-1170h]
  int v92; // [sp+10h] [-1170h]
  int v93; // [sp+10h] [-1170h]
  int v94; // [sp+10h] [-1170h]
  int v95; // [sp+10h] [-1170h]
  int v96; // [sp+10h] [-1170h]
  int v97; // [sp+10h] [-1170h]
  int v98; // [sp+14h] [-116Ch]
  int v99; // [sp+14h] [-116Ch]
  int v100; // [sp+14h] [-116Ch]
  int v101; // [sp+14h] [-116Ch]
  int v102; // [sp+14h] [-116Ch]
  int v103; // [sp+14h] [-116Ch]
  int v104; // [sp+14h] [-116Ch]
  int v105; // [sp+14h] [-116Ch]
  int v106; // [sp+14h] [-116Ch]
  int v107; // [sp+18h] [-1168h]
  int v108; // [sp+18h] [-1168h]
  int v109; // [sp+18h] [-1168h]
  int v110; // [sp+18h] [-1168h]
  int v111; // [sp+18h] [-1168h]
  int v112; // [sp+18h] [-1168h]
  int v113; // [sp+18h] [-1168h]
  int v114; // [sp+18h] [-1168h]
  int v115; // [sp+18h] [-1168h]
  int v116; // [sp+1Ch] [-1164h]
  int v117; // [sp+1Ch] [-1164h]
  int v118; // [sp+1Ch] [-1164h]
  int v119; // [sp+1Ch] [-1164h]
  int v120; // [sp+1Ch] [-1164h]
  int v121; // [sp+1Ch] [-1164h]
  int v122; // [sp+1Ch] [-1164h]
  int v123; // [sp+1Ch] [-1164h]
  int v124; // [sp+1Ch] [-1164h]
  int v125; // [sp+20h] [-1160h]
  double v126; // [sp+20h] [-1160h]
  int v127; // [sp+24h] [-115Ch]
  int v128; // [sp+28h] [-1158h]
  int v129; // [sp+2Ch] [-1154h]
  int v130; // [sp+30h] [-1150h]
  int v131; // [sp+34h] [-114Ch]
  int v132; // [sp+38h] [-1148h]
  int v133; // [sp+3Ch] [-1144h]
  int v134; // [sp+40h] [-1140h]
  int v135; // [sp+44h] [-113Ch]
  int v136; // [sp+48h] [-1138h]
  int v137; // [sp+4Ch] [-1134h]
  int v138; // [sp+50h] [-1130h] BYREF
  int v139; // [sp+54h] [-112Ch] BYREF
  __int64 v140; // [sp+58h] [-1128h] BYREF
  idStr v141; // [sp+60h] [-1120h] BYREF
  __int64 v142; // [sp+80h] [-1100h] BYREF
  idStr v143; // [sp+90h] [-10F0h] BYREF
  idStr v144; // [sp+B0h] [-10D0h] BYREF
  idStr v145; // [sp+D0h] [-10B0h] BYREF
  va v146; // [sp+F0h] [-1090h] BYREF

  *megaTexelsPerSecond = 0.0;
  *score = 0.0;
  idStr::idStr(this: &v144, text: "wellspring");
  *(_DWORD *)&v3.numTopPages = 0;
  v143.len = 0;
  v143.allocedAndFlag = 20;
  v143.data = v143.baseBuffer;
  v143.baseBuffer[0] = 0;
  if ( com_multiplayer.valueInteger != 0 )
  {
    v7 = fileSystem->GetBasePathStr(this: fileSystem, a2: 0);
    idStr::idStr(this: &v145, text: v7);
    idStr::StripTrailingOnce(this: &v145, string: "mp");
    idStr::AppendPath(this: &v145, text: "virtualtextures");
    idStr::Format(this: &v143, fmt: "%s/%s.pages", v145.data, v144.data);
    idStr::FreeData(this: &v145);
  }
  else
  {
    idStr::Format(this: &v143, fmt: "%s/%s.pages", vt_filePath.valueString.data, v144.data);
  }
  if ( fileSystem->GetTimestamp(this: fileSystem, a2: v143.data, a3: false) == -1 )
  {
    idLib::Printf(fmt: "'%s' does not exist!\n", v143.data);
    idStr::FreeData(this: &v143);
    idStr::FreeData(this: &v144);
    return 0;
  }
  else
  {
    v9 = 2;
    p_data = &this->vts[2].pageFilePath.data;
    while ( **p_data != 0 )
    {
      ++v9;
      p_data += 312;
      if ( v9 >= 16 )
        goto LABEL_12;
    }
    v11 = &this->vmtrPath[1248 * v9];
    v12 = (idVirtualTexture *)(v11 + 560);
    if ( v11 == (char *)-560
      || (unsigned __int8)idVirtualTexture::SetSource(
                            this: (idVirtualTexture *)(v11 + 560),
                            baseName_: v144.data,
                            pageFilePath_: v143.data,
                            physicalPagesPool: 0) == 0 )
    {
LABEL_12:
      idStr::FreeData(this: &v143);
      idStr::FreeData(this: &v144);
      return 0;
    }
    idCVar::SetBool(this: &vt_skipUpdatePageImages, newValue: true, force: true);
    if ( vt_genMissingPages.valueInteger == 1 )
      idCVar::SetInteger(this: &vt_genMissingPages, newValue: 2, force: true);
    parallelJobManager->WaitForAllJobLists(this: parallelJobManager);
    idVirtualTextureSystem::WaitForLastAnalyzeFeedback(this);
    p_currentPageIndices = &this->currentPageIndices;
    v14 = this->pageIndices[this->currentPageIndices];
    v14->pageStats[0] = v3;
    v14->pageStats[1] = v3;
    v14->pageStats[2] = v3;
    v14->pageStats[3] = v3;
    LODWORD(v15) = this->currentPageIndices + 12583;
    *(pageStats_t *)*(_DWORD *)&this->vmtrPath[4 * v15] = v3;
    HIDWORD(v15) = this->pageIndices[this->currentPageIndices];
    idVirtualTexture::GetToBeLockedPhysicalPages(this: v12, numTexturePages: 1024, pageIndices: v15);
    v16 = 0;
    v17 = 0x40000000;
    p_pageTranscodeCount = &this->pageTranscodeCount;
    for ( i = 4; i != 0; --i )
    {
      idVirtualTextureSystem::EmptyCache(this, skipVmtrCache: false);
      v20 = Sys_Microseconds() >> 32;
      *p_pageTranscodeCount = 0;
      HIDWORD(v140) = 0;
      v21 = v20;
      v22 = (unsigned __int8)idVirtualTextureSystem::TranscodeFeedback(
                               this,
                               transcodePageIndices: this->pageIndices[*p_currentPageIndices],
                               transcodePageIndicesOffset: (int *)&v140,
                               blocking: true,
                               lockPages: false);
      if ( v22 == 0 )
      {
        do
        {
          idVirtualTextureSystem::StreamFeedback(
            this,
            transcodePageIndices: this->pageIndices[*p_currentPageIndices],
            a3: v26,
            a4: v25,
            a5: v24,
            a6: v23,
            a7: v22,
            a8: 4 * (*p_currentPageIndices + 12583),
            a9: v71,
            a10: v80,
            a11: v89,
            a12: v98,
            a13: v107,
            a14: v116,
            a15: v125,
            a16: v127,
            a17: v128,
            a18: v129,
            a19: v130,
            a20: v131,
            a21: v132,
            a22: v133,
            a23: v134,
            a24: v135,
            a25: v136,
            a26: v137,
            a27: v138);
          v24 = (unsigned __int8)idVirtualTextureSystem::TranscodeFeedback(
                                   this,
                                   transcodePageIndices: this->pageIndices[*p_currentPageIndices],
                                   transcodePageIndicesOffset: (int *)&v140,
                                   blocking: true,
                                   lockPages: false);
        }
        while ( v24 == 0 );
      }
      v27 = Sys_Microseconds();
      if ( HIDWORD(v27) - v21 < v17 )
      {
        v16 = *p_pageTranscodeCount;
        v17 = HIDWORD(v27) - v21;
      }
    }
    v28 = _u64tod(a1: v17, a2: v27);
    LODWORD(v29) = v16 << 14;
    HIDWORD(v29) = &off_82040000;
    v142 = v29;
    v30 = (float)((float)v29 / (float)((float)((float)v28 * (float)0.000001) * (float)1000000.0));
    if ( v30 >= 0.0 )
    {
      if ( v30 > 999.0 )
        v30 = 999.0;
    }
    else
    {
      v30 = 0.0;
    }
    *megaTexelsPerSecond = v30;
    v31 = (float)((float)v30 * (float)0.0099999998);
    if ( v31 >= 0.0 )
    {
      if ( v31 > 1.0 )
        v31 = 1.0;
    }
    else
    {
      v31 = 0.0;
    }
    *score = v31;
    if ( v31 <= 0.80000001 )
    {
      if ( v31 <= 0.60000002 )
      {
        if ( v31 <= 0.40000001 )
        {
          if ( v31 <= 0.2 )
            v32 = "POOR";
          else
            v32 = "FAIR";
        }
        else
        {
          v32 = "GOOD";
        }
      }
      else
      {
        v32 = "GREAT";
      }
    }
    else
    {
      v32 = "EXCELLENT";
    }
    v139 = 0;
    v138 = 0;
    HIDWORD(v142) = 0;
    Sys_CPUCount(numLogicalCPUCores: &v139, numPhysicalCPUCores: &v138, numCPUPackages: (int *)&v142);
    v141.allocedAndFlag = 20;
    v141.data = v141.baseBuffer;
    v141.len = 0;
    v141.baseBuffer[0] = 0;
    ProcessorString = Sys_GetProcessorString();
    LODWORD(v34) = "olor specular";
    HIDWORD(v35) = ProcessorString;
    v37 = va::va(
            this: &v146,
            fmt: "CPU type = %s\n",
            a3: v35,
            a4: v36,
            a5: v34,
            a6: v71,
            a7: v80,
            a8: v89,
            a9: v98,
            a10: v107,
            a11: v116);
    idStr::Append(this: &v141, text: v37);
    LODWORD(v38) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
    v140 = v38;
    HIDWORD(v39) = "olor specular";
    LODWORD(v40) = "olor specular";
    v41 = (float)((float)v38 * (float)9.9999997e-10);
    v42 = va::va(
            this: &v146,
            fmt: (const char *)HIDWORD(v41),
            a3: *(__int64 *)((char *)&v41 - 4),
            a4: v40,
            a5: v39,
            a6: v72,
            a7: v81,
            a8: v90,
            a9: v99,
            a10: v108,
            a11: v117);
    idStr::Append(this: &v141, text: v42);
    HIDWORD(v43) = "olor specular";
    HIDWORD(v44) = v138;
    v46 = va::va(
            this: &v146,
            fmt: "CPU physical cores = %d\n",
            a3: v44,
            a4: v43,
            a5: v45,
            a6: v73,
            a7: v82,
            a8: v91,
            a9: v100,
            a10: v109,
            a11: v118);
    idStr::Append(this: &v141, text: v46);
    LODWORD(v47) = "olor specular";
    HIDWORD(v47) = v139;
    v50 = va::va(
            this: &v146,
            fmt: "CPU logical cores = %d\n",
            a3: v47,
            a4: v49,
            a5: v48,
            a6: v74,
            a7: v83,
            a8: v92,
            a9: v101,
            a10: v110,
            a11: v119);
    idStr::Append(this: &v141, text: v50);
    HIDWORD(v51) = jobs_numThreads.valueInteger;
    v54 = va::va(
            this: &v146,
            fmt: "CPU threads = %d\n",
            a3: v51,
            a4: v53,
            a5: v52,
            a6: v75,
            a7: v84,
            a8: v93,
            a9: v102,
            a10: v111,
            a11: v120);
    idStr::Append(this: &v141, text: v54);
    LODWORD(v55) = &virtualTextureSystem.referencedVTPath[86][216];
    HIDWORD(v55) = "olor specular";
    LODWORD(v56) = &vt_maxPPF;
    HIDWORD(v57) = vt_maxPPF.valueInteger;
    v58 = va::va(
            this: &v146,
            fmt: "Max PPF = %d\n",
            a3: v57,
            a4: v56,
            a5: v55,
            a6: v76,
            a7: v85,
            a8: v94,
            a9: v103,
            a10: v112,
            a11: v121);
    idStr::Append(this: &v141, text: v58);
    HIDWORD(v59) = "olor specular";
    v62 = va::va(
            this: &v146,
            fmt: "----------------\n",
            a3: v61,
            a4: v59,
            a5: v60,
            a6: v77,
            a7: v86,
            a8: v95,
            a9: v104,
            a10: v113,
            a11: v122);
    idStr::Append(this: &v141, text: v62);
    v126 = *megaTexelsPerSecond;
    HIDWORD(v63) = LODWORD(v126);
    LODWORD(v63) = "olor specular";
    v66 = va::va(
            this: &v146,
            fmt: "%1.0f Mega Texels per Second\n",
            a3: v63,
            a4: v65,
            a5: v64,
            a6: v78,
            a7: v87,
            a8: v96,
            a9: v105,
            a10: v114,
            a11: v123);
    idStr::Append(this: &v141, text: v66);
    HIDWORD(v67) = v32;
    v70 = va::va(
            this: &v146,
            fmt: "Benchmark Score: %s\n",
            a3: v67,
            a4: v69,
            a5: v68,
            a6: v79,
            a7: v88,
            a8: v97,
            a9: v106,
            a10: v115,
            a11: v124);
    idStr::Append(this: &v141, text: v70);
    idLib::Printf(fmt: v141.data);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)v141.data);
    idCVar::SetBool(this: &vt_skipUpdatePageImages, newValue: false, force: true);
    if ( vt_genMissingPages.valueInteger == 2 )
      idCVar::SetInteger(this: &vt_genMissingPages, newValue: 1, force: true);
    idVirtualTexture::ReleaseSource(this: v12);
    idVirtualTextureSystem::EmptyCache(this, skipVmtrCache: false);
    idStr::FreeData(this: &v141);
    idStr::FreeData(this: &v143);
    idStr::FreeData(this: &v144);
    return 1;
  }
}


// ========================================================================
// __unwind$244219
// EA  : 0x82985C58
// RVA : 0x00985C58
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_244219()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 176));
}


// ========================================================================
// __unwind$244220
// EA  : 0x82985C80
// RVA : 0x00985C80
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_244220()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 144));
}


// ========================================================================
// __unwind$244221
// EA  : 0x82985CA8
// RVA : 0x00985CA8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_244221()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 208));
}


// ========================================================================
// __unwind$244222
// EA  : 0x82985CD0
// RVA : 0x00985CD0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_244222()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 96));
}


// ========================================================================
// ?TranscodeBenchmark_f@idVirtualTextureSystem@@CAXABVidCmdArgs@@@Z
// EA  : 0x82985CF8
// RVA : 0x00985CF8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::TranscodeBenchmark_f(const idCmdArgs *args)
{
  float v1; // [sp+50h] [-10h] BYREF
  float v2; // [sp+54h] [-Ch] BYREF

  v1 = 0.0;
  v2 = 0.0;
  idVirtualTextureSystem::RunTranscodeBenchmark(this: &virtualTextureSystem, megaTexelsPerSecond: &v1, score: &v2);
}


// ========================================================================
// ?LockPhysicalPages@idVirtualTextureSystem@@QAAXQAPAVidVirtualTexture@@HH@Z
// EA  : 0x82985D38
// RVA : 0x00985D38
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::LockPhysicalPages(
        idVirtualTextureSystem *this,
        idVirtualTexture **virtualTextures,
        int numVirtualTextures,
        int maxLockedPages)
{
  idVirtualTexture **v5; // r22
  unsigned __int64 v8; // r26
  int *v9; // r11
  char **p_data; // r10
  int i; // ctr
  int v12; // r11
  idVirtualTexture **v13; // r10
  idVirtualTexture **v14; // r31
  int j; // r30
  physicalPagesPool_t PhysicalPagesPool; // r3
  int v17; // r19
  unsigned int v18; // r11
  unsigned int currentPageIndices; // r11
  pageIndices_t *v20; // r11
  int k; // r21
  idVirtualTexture *v22; // r29
  physicalPagesPool_t v23; // r30
  signed int v24; // r9
  int totalPages; // r11
  int v26; // r28
  int v27; // r11
  __int64 v28; // r6
  int v29; // r31
  int v30; // r27
  int v31; // r29
  _DWORD *v32; // r28
  idPhysicalPages *v33; // r30
  int m; // r31
  __int64 v35; // r9
  double v36; // r4
  __int64 v37; // [sp+50h] [-E0h] BYREF
  int v38; // [sp+58h] [-D8h]
  int v39; // [sp+5Ch] [-D4h]
  _DWORD v40[7]; // [sp+60h] [-D0h] BYREF
  int v41; // [sp+7Ch] [-B4h] BYREF
  char v42; // [sp+80h] [-B0h] BYREF

  v5 = virtualTextures;
  LODWORD(v8) = 0;
  if ( virtualTextures == nullptr )
  {
    v9 = &v41;
    v5 = (idVirtualTexture **)&v42;
    numVirtualTextures = 0;
    p_data = &this->vts[3].pageFilePath.data;
    for ( i = 7; i != 0; --i )
    {
      if ( **(p_data - 312) != 0 )
      {
        ++numVirtualTextures;
        v9[1] = (int)(p_data - 333);
        ++v9;
      }
      if ( **p_data != 0 )
      {
        ++numVirtualTextures;
        *++v9 = (int)(p_data - 21);
      }
      p_data += 624;
    }
  }
  v12 = 0;
  if ( numVirtualTextures <= 0 )
  {
LABEL_12:
    v37 = 0;
    v38 = 0;
    v39 = 0;
    if ( numVirtualTextures > 0 )
    {
      v14 = v5 - 1;
      for ( j = numVirtualTextures; j != 0; --j )
      {
        PhysicalPagesPool = idVirtualTexture::GetPhysicalPagesPool(this: v14[1]);
        *((_DWORD *)&v37 + PhysicalPagesPool) += (*++v14)->header.totalPages;
      }
    }
    v17 = Sys_Milliseconds();
    if ( maxLockedPages < 0 )
      maxLockedPages = vt_maxLockedPages.valueInteger;
    if ( idParallelJobList::IsSubmitted(this: this->analyzeJobList) )
    {
      idParallelJobList::Wait(this: this->analyzeJobList);
      v18 = this->currentPageIndices ^ 1;
      this->currentPageIndices = v18;
      this->numExplicitPages[v18] = 0;
    }
    currentPageIndices = this->currentPageIndices;
    memset(v40, 0, sizeof(v40));
    HIDWORD(v8) = &this->currentPageIndices;
    v20 = this->pageIndices[currentPageIndices];
    v41 = 0;
    v20->pageStats[0] = (pageStats_t)v8;
    v20->pageStats[1] = (pageStats_t)v8;
    v20->pageStats[2] = (pageStats_t)v8;
    v20->pageStats[3] = (pageStats_t)v8;
    this->pageIndices[this->currentPageIndices]->totalNumPages = v8;
    if ( numVirtualTextures > 0 )
    {
      for ( k = numVirtualTextures; k != 0; --k )
      {
        v22 = *v5;
        v23 = idVirtualTexture::GetPhysicalPagesPool(this: *v5);
        v24 = *(_DWORD *)((char *)&v37 + v23 * 4);
        if ( v24 != 0 )
        {
          totalPages = v22->header.totalPages;
          __twllei(v24, 0);
          v26 = v40[v23];
          v27 = totalPages + v40[v23 + 4];
          v40[v23 + 4] = v27;
          LODWORD(v28) = __ROL4__(v27 * maxLockedPages, 1) - 1;
          v29 = v27 * maxLockedPages / v24 - v26;
          __twlgei(v24 & ~(_DWORD)v28, 0xFFFFFFFF);
          if ( v29 < 1 )
            v29 = 1;
          HIDWORD(v28) = this->pageIndices[*(_DWORD *)HIDWORD(v8)];
          idVirtualTexture::GetToBeLockedPhysicalPages(this: v22, numTexturePages: v29, pageIndices: v28);
          idLib::Printf(fmt: "%3i pages locked in %s\n", v29, v22->pageFilePath.data);
          v40[v23] = v26 + v29;
        }
        ++v5;
      }
    }
    idVirtualTextureSystem::FinishFeedback(this, lockPages: true, maxWaitTimeInSeconds: 0);
    v30 = Sys_Milliseconds();
    v31 = 0;
    v32 = v40;
    v33 = &this->physicalPagesPool[1];
    for ( m = 3; m != 0; --m )
    {
      v31 += *++v32;
      idPhysicalPages::ValidateCache(this: v33++);
    }
    LODWORD(v35) = v30 - v17;
    HIDWORD(v35) = "olor specular";
    v37 = v35;
    v36 = (float)((float)v35 * (float)0.001);
    idLib::Printf(fmt: (const char *)HIDWORD(v36), LODWORD(v36), v31);
  }
  else
  {
    v13 = v5;
    while ( (*v13)->physicalPages != nullptr )
    {
      ++v12;
      ++v13;
      if ( v12 >= numVirtualTextures )
        goto LABEL_12;
    }
  }
}


// ========================================================================
// ?PushFeedback@idVirtualTextureSystem@@QAAXPBXHHH_N@Z
// EA  : 0x82986048
// RVA : 0x00986048
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::PushFeedback(
        idVirtualTextureSystem *this,
        void *data,
        int width,
        int height,
        unsigned int bytePitch,
        bool forceHighestDetail)
{
  unsigned int *p_currentPageIndices; // r24
  int v13; // r10
  int v14; // r7
  int v15; // r6
  int v16; // r5
  int v17; // [sp+8h] [-98h]
  int v18; // [sp+Ch] [-94h]
  int v19; // [sp+10h] [-90h]
  int v20; // [sp+14h] [-8Ch]
  int v21; // [sp+18h] [-88h]
  int v22; // [sp+1Ch] [-84h]
  int v23; // [sp+20h] [-80h]
  int v24; // [sp+24h] [-7Ch]
  int v25; // [sp+28h] [-78h]
  int v26; // [sp+2Ch] [-74h]
  int v27; // [sp+30h] [-70h]
  int v28; // [sp+34h] [-6Ch]
  int v29; // [sp+38h] [-68h]
  int v30; // [sp+3Ch] [-64h]
  int v31; // [sp+40h] [-60h]
  int v32; // [sp+44h] [-5Ch]
  int v33; // [sp+48h] [-58h]
  int v34; // [sp+4Ch] [-54h]
  int v35; // [sp+50h] [-50h] BYREF

  v35 = 0;
  p_currentPageIndices = &this->currentPageIndices;
  idVirtualTextureSystem::WaitForLastAnalyzeFeedback(this);
  idVirtualTextureSystem::TranscodeFeedback(
    this,
    transcodePageIndices: this->pageIndices[this->currentPageIndices],
    transcodePageIndicesOffset: &v35,
    blocking: false,
    lockPages: false);
  idVirtualTextureSystem::StreamFeedback(
    this,
    transcodePageIndices: this->pageIndices[*p_currentPageIndices],
    a3: v16,
    a4: v15,
    a5: v14,
    a6: 4 * (*p_currentPageIndices + 12583),
    a7: *p_currentPageIndices + 12583,
    a8: v13,
    a9: v17,
    a10: v18,
    a11: v19,
    a12: v20,
    a13: v21,
    a14: v22,
    a15: v23,
    a16: v24,
    a17: v25,
    a18: v26,
    a19: v27,
    a20: v28,
    a21: v29,
    a22: v30,
    a23: v31,
    a24: v32,
    a25: v33,
    a26: v34,
    a27: v35);
  idVirtualTextureSystem::CancelObsoleteTranscodes(this);
  idVirtualTextureSystem::AnalyzeFeedback(this, data, width, height, bytePitch, forceHighestDetail);
  if ( this->flushNextFeedback )
  {
    this->flushNextFeedback = false;
    idVirtualTextureSystem::FinishFeedback(this, lockPages: false, maxWaitTimeInSeconds: 0);
  }
}


// ========================================================================
// ?LockPages_f@idVirtualTextureSystem@@CAXABVidCmdArgs@@@Z
// EA  : 0x82986110
// RVA : 0x00986110
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::LockPages_f(const idCmdArgs *args)
{
  idVirtualTextureSystem::LockPhysicalPages(
    this: &virtualTextureSystem,
    virtualTextures: nullptr,
    numVirtualTextures: 0,
    maxLockedPages: -1);
}


// ========================================================================
// ?ReloadVirtualTextures@idVirtualTextureSystem@@QAA_NXZ
// EA  : 0x82986130
// RVA : 0x00986130
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

BOOL __fastcall idVirtualTextureSystem::ReloadVirtualTextures(idVirtualTextureSystem *this)
{
  int v2; // r26
  char *v3; // r24
  unsigned __int8 v4; // r25
  int i; // r29
  char *v6; // r11
  idVirtualTexture *v7; // r30
  physicalPagesPool_t PhysicalPagesPool; // r28
  bool enlargedPageTableAllocationFailed; // r11
  idStr v11; // [sp+50h] [-D0h] BYREF
  idStr v12; // [sp+70h] [-B0h] BYREF
  idVirtualTexture *v13; // [sp+90h] [-90h] BYREF

  idVirtualTextureSystem::SyncFeedback(this);
  v2 = 0;
  v3 = &v12.baseBuffer[16];
  v4 = 0;
  for ( i = 1; i < 16; ++i )
  {
    v6 = &this->vmtrPath[1248 * i];
    v7 = (idVirtualTexture *)(v6 + 560);
    if ( **((_BYTE **)v6 + 161) != 0 )
    {
      idStr::idStr(this: &v12, text: *((const char **)v6 + 233));
      idStr::idStr(this: &v11, text: v7->pageFilePath.data);
      PhysicalPagesPool = idVirtualTexture::GetPhysicalPagesPool(this: v7);
      if ( i == 1 )
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      idVirtualTexture::SetSource(
        this: v7,
        baseName_: v12.data,
        pageFilePath_: v11.data,
        physicalPagesPool: PhysicalPagesPool);
      if ( i == 1 )
        idMem::PopHeap(this: &mem);
      enlargedPageTableAllocationFailed = v7->enlargedPageTableAllocationFailed;
      v3 += 4;
      *(_DWORD *)v3 = v7;
      ++v2;
      v4 |= enlargedPageTableAllocationFailed;
      idStr::FreeData(this: &v11);
      idStr::FreeData(this: &v12);
    }
  }
  idVirtualTextureSystem::LockPhysicalPages(this, virtualTextures: &v13, numVirtualTextures: v2, maxLockedPages: 21);
  idVirtualTextureSystem::SetupLoadedVirtualMaterials(this);
  return (_cntlzw(v4) & 0x20) != 0;
}


// ========================================================================
// __unwind$244585
// EA  : 0x8298623C
// RVA : 0x0098623C
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_244585()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$244586
// EA  : 0x82986264
// RVA : 0x00986264
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_244586()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 80));
}


// ========================================================================
// ?Reload_f@idVirtualTextureSystem@@CAXABVidCmdArgs@@@Z
// EA  : 0x82986290
// RVA : 0x00986290
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::Reload_f(const idCmdArgs *args)
{
  if ( !idVirtualTextureSystem::ReloadVirtualTextures(this: &virtualTextureSystem) )
    idLib::Warning(fmt: "failed to allocate larger page tables for more texture detail");
}


// ========================================================================
// ?Init@idVirtualTextureSystem@@QAAXXZ
// EA  : 0x829862D8
// RVA : 0x009862D8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __fastcall idVirtualTextureSystem::Init(idVirtualTextureSystem *this)
{
  _DWORD *v2; // r10
  int v3; // r11
  int v4; // ctr
  unsigned __int8 *v5; // r3
  idImage *v6; // r30
  idVirtualTexture *v7; // r3
  idRenderDestination *v8; // r3
  idRenderDestination *v9; // r11
  idParallelJobList **p_analyzeJobList; // r30
  signed int v11; // r27
  const char *v12; // r3
  const char *v13; // r3
  int v14; // r11
  char *data; // r10
  char valueInteger; // r11
  int v17; // r11
  char *vmtrName; // r3
  production_t v19; // r27
  bool v20; // r6
  bool v21; // r5
  bool v22; // r4
  int v23; // r3
  int v24; // r6
  int v25; // r7
  int v26; // [sp+50h] [-A60h] BYREF
  int v27; // [sp+54h] [-A5Ch] BYREF
  idVirtualTexture *vmtrMega; // [sp+58h] [-A58h] BYREF
  idStr v29; // [sp+60h] [-A50h] BYREF
  idImageOpts v30; // [sp+80h] [-A30h] BYREF
  idStr v31; // [sp+D0h] [-9E0h] BYREF
  idStr v32; // [sp+F0h] [-9C0h] BYREF
  idCmdArgs v33; // [sp+110h] [-9A0h] BYREF

  v2 = (_DWORD *)((char *)this - 32);
  v3 = 0;
  v4 = 16;
  this->cancelToTerminate = false;
  do
  {
    v2 += 312;
    *v2 = v3++;
    --v4;
  }
  while ( v4 != 0 );
  this->vtInfo = (virtualTextureInfo_t *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(2296) : TAG_VIRTUALTEXTURE",
                                           size: 0x100u,
                                           tag: TAG_VIRTUALTEXTURE,
                                           zeroBuffer: true,
                                           align: ALIGN_128,
                                           heap: HEAP_DEFAULTHEAP);
  this->currentPageIndices = 0;
  this->pageIndices[0] = (pageIndices_t *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(2299) : TAG_VIRTUALTEXTURE",
                                            size: 0x4008u,
                                            tag: TAG_VIRTUALTEXTURE,
                                            zeroBuffer: true,
                                            align: ALIGN_128,
                                            heap: HEAP_DEFAULTHEAP);
  this->pageIndices[1] = (pageIndices_t *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(2300) : TAG_VIRTUALTEXTURE",
                                            size: 0x4008u,
                                            tag: TAG_VIRTUALTEXTURE,
                                            zeroBuffer: true,
                                            align: ALIGN_128,
                                            heap: HEAP_DEFAULTHEAP);
  this->explicitPages[0] = (unsigned __int8 *)idMem::AllocWithLocation(
                                                this: &mem,
                                                location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(2302) : TAG_VIRTUALTEXTURE",
                                                size: 0x2000u,
                                                tag: TAG_VIRTUALTEXTURE,
                                                zeroBuffer: true,
                                                align: ALIGN_128,
                                                heap: HEAP_DEFAULTHEAP);
  v5 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(2303) : TAG_VIRTUALTEXTURE",
                            size: 0x2000u,
                            tag: TAG_VIRTUALTEXTURE,
                            zeroBuffer: true,
                            align: ALIGN_128,
                            heap: HEAP_DEFAULTHEAP);
  v30.colorFormat = CFM_DEFAULT;
  v30.cubeFilter = false;
  v30.depth = 0;
  v30.numLevels = 0;
  v30.textureType = TT_2D;
  v30.border.x = 0.0;
  this->explicitPages[1] = v5;
  v30.border.y = 0.0;
  v30.border.z = 0.0;
  v30.border.w = 0.0;
  v30.lodBias = 0.0;
  v30.lodMinClamp = 0.0;
  v30.aniso = 0.0;
  v30.lodMaxClamp = 0.0;
  v30.packedTail = true;
  v30.linear = false;
  v30.format = FMT_RGBA8;
  v30.forceBias = false;
  v30.depthCompareMode = false;
  v30.overlayMemory = false;
  v30.startPurged = false;
  v30.width = 160;
  v30.height = 128;
  v30.filter = TF_NEAREST;
  v30.repeat = TR_CLAMP;
  v30.readback = true;
  v6 = idImageManager::ScratchImage(this: globalImages, _name: "_feedbackBuffer", imgOpts: &v30);
  memset(Dst: v6->lockRect[0].pBits, Val: 0, Size: v6->lockRect[0].Pitch << 7);
  v7 = (idVirtualTexture *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x38u,
                             tag: TAG_VIRTUALTEXTURE,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  vmtrMega = v7;
  if ( v7 != nullptr )
    v8 = idRenderDestination::idRenderDestination(this: (idRenderDestination *)v7);
  else
    v8 = nullptr;
  this->renderDestFeedback[0] = v8;
  idRenderDestination::CreateFromImages(
    this: v8,
    color: v6,
    depth: nullptr,
    stencil: nullptr,
    colorSurf: xenSurf.pFeedbackDownsampleSurface,
    depthSurf: nullptr);
  v9 = this->renderDestFeedback[0];
  this->renderDestFeedback[1] = v9;
  this->renderDestFeedback[2] = v9;
  this->feedbackBuffer = v9->targetImage[0]->lockRect[0].pBits;
  this->feedbackBufferPitch = v9->targetImage[0]->lockRect[0].Pitch;
  p_analyzeJobList = &this->analyzeJobList;
  this->analyzeJobList = parallelJobManager->AllocJobList(
                           this: parallelJobManager,
                           a2: 5,
                           a3: 2,
                           a4: 256,
                           a5: 2,
                           a6: &idColor::colorLtGrey);
  v11 = 0;
  do
  {
    p_analyzeJobList[1] = parallelJobManager->AllocJobList(
                            this: parallelJobManager,
                            a2: ((_cntlzw(v11) & 0x20) == 0) + 6,
                            a3: 1,
                            a4: 130,
                            a5: 2,
                            a6: &idColor::colorLtGrey);
    p_analyzeJobList[2] = nullptr;
    p_analyzeJobList[3] = (idParallelJobList *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(2378) : TAG_VIRTUALTEXTURE",
                                                 size: 0x4000u,
                                                 tag: TAG_VIRTUALTEXTURE,
                                                 zeroBuffer: true,
                                                 align: ALIGN_128,
                                                 heap: HEAP_DEFAULTHEAP);
    p_analyzeJobList[4] = (idParallelJobList *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(2379) : TAG_VIRTUALTEXTURE",
                                                 size: 0x100000u,
                                                 tag: TAG_VIRTUALTEXTURE,
                                                 zeroBuffer: false,
                                                 align: ALIGN_128,
                                                 heap: HEAP_DEFAULTHEAP);
    p_analyzeJobList[8] = (idParallelJobList *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(2384) : TAG_VIRTUALTEXTURE",
                                                 size: 0x4080u,
                                                 tag: TAG_VIRTUALTEXTURE,
                                                 zeroBuffer: true,
                                                 align: ALIGN_128,
                                                 heap: HEAP_DEFAULTHEAP);
    p_analyzeJobList[9] = nullptr;
    p_analyzeJobList[10] = nullptr;
    *((_BYTE *)p_analyzeJobList + 44) = 0;
    *((_BYTE *)p_analyzeJobList + 45) = vt_usePageTablePBOs.valueInteger != 0;
    *((_BYTE *)p_analyzeJobList + 46) = vt_useUnsynchronizedPageTablePBOs.valueInteger != 0;
    *((_BYTE *)p_analyzeJobList + 47) = vt_skipPhysicalTextureUploads.valueInteger != 0;
    p_analyzeJobList[12] = (idParallelJobList *)idMem::AllocWithLocation(
                                                  this: &mem,
                                                  location: "w:\\tech5\\engine\\renderer\\VirtualTextureSystem.cpp(2392) : TAG_VIRTUALTEXTURE",
                                                  size: 0x4080u,
                                                  tag: TAG_VIRTUALTEXTURE,
                                                  zeroBuffer: true,
                                                  align: ALIGN_128,
                                                  heap: HEAP_DEFAULTHEAP);
    p_analyzeJobList[13] = nullptr;
    ++v11;
    p_analyzeJobList[14] = nullptr;
    *((_BYTE *)p_analyzeJobList + 60) = 0;
    *((_BYTE *)p_analyzeJobList + 61) = vt_usePageTablePBOs.valueInteger != 0;
    *((_BYTE *)p_analyzeJobList + 62) = vt_useUnsynchronizedPageTablePBOs.valueInteger != 0;
    *((_BYTE *)p_analyzeJobList + 63) = vt_skipPhysicalTextureUploads.valueInteger != 0;
    p_analyzeJobList += 16;
    *(_BYTE *)p_analyzeJobList = 0;
  }
  while ( v11 < 2 );
  v29.len = 0;
  v29.baseBuffer[0] = 0;
  v29.allocedAndFlag = 20;
  v29.data = v29.baseBuffer;
  if ( idLib::production == PROD_DEVELOPMENT
    || com_production.valueInteger != 0
    || vt_useNetworkPagesWithPreload.valueInteger != 0 )
  {
    v14 = 0;
    data = vt_filePathVmtrOverride.valueString.data;
    if ( *vt_filePathVmtrOverride.valueString.data == 0 )
      goto LABEL_15;
    do
      ++v14;
    while ( vt_filePathVmtrOverride.valueString.data[v14] != 0 );
    if ( v14 <= 0 )
LABEL_15:
      data = vt_filePath.valueString.data;
    idStr::operator=(this: &v29, text: data);
  }
  else
  {
    v12 = fileSystem->GetBasePathStr(this: fileSystem, a2: 3);
    idStr::operator=(this: &v29, text: v12);
    idStr::AppendPath(this: &v29, text: "virtualtextures");
    idCVar::SetString(this: &vt_filePathVmtrOverride, newValue: v29.data, force: true);
    v13 = fileSystem->GetBasePathStr(this: fileSystem, a2: 0);
    idStr::idStr(this: &v32, text: v13);
    idStr::AppendPath(this: &v32, text: "virtualtextures");
    idCVar::SetString(this: &vt_filePath, newValue: v32.data, force: true);
    idStr::FreeData(this: &v32);
  }
  idStreamFileCache::Init(this: streamFileCache);
  if ( idLib::production != PROD_DEVELOPMENT )
    idVirtualTextureSystem::CacheAllPagesFiles(
      this,
      virtualTexturePath: vt_filePath.valueString.data,
      virtualTextureInstallPath: v29.data);
  idVirtualTextureSystem::EmptyCache(this, skipVmtrCache: false);
  if ( (idLib::production != PROD_DEVELOPMENT || com_production.valueInteger != 0)
    && vt_useNetworkPagesWithPreload.valueInteger == 0 )
  {
    idCVar::SetInteger(this: &vt_virtualSizeLog2, newValue: 9, force: true);
    idCVar::SetBool(this: &vt_uncompressedVmtr, newValue: false, force: true);
    idCVar::SetInteger(this: &vt_packPageFiles, newValue: 2, force: true);
  }
  valueInteger = vt_virtualSizeLog2.valueInteger;
  if ( vt_virtualSizeLog2.valueInteger >= 7 )
  {
    if ( vt_virtualSizeLog2.valueInteger > 11 )
      valueInteger = 11;
  }
  else
  {
    valueInteger = 7;
  }
  v17 = 1 << valueInteger;
  vmtrName = this->vmtrName;
  if ( vt_packPageFiles.valueInteger != 0 )
    sprintf_0(string: vmtrName, format: "_vmtr");
  else
    sprintf_0(
      string: vmtrName,
      format: "_vmtr_v%02i_%i_%c",
      25,
      v17 / 8,
      vt_uncompressedVmtr.valueInteger == 0 ? 67 : 85);
  sprintf_0(string: this->vmtrPath, format: "%s/%s.vmtr", v29.data, this->vmtrName);
  idStr::idStr(this: &v31, text: this->vmtrPath);
  idStr::SetFileExtension(this: &v31, extension: ".pages");
  if ( (unsigned __int8)idVirtualTexture::SetSource(
                          this: this->vmtrMega,
                          baseName_: this->vmtrName,
                          pageFilePath_: v31.data,
                          physicalPagesPool: 0) == 0 )
    idLib::FatalError(fmt: "Couldn't open vmtr page file '%s'", v31.data);
  idVirtualTextureSystem::AddToReferencedVirtualTextures(this, name: this->vmtrName, path: v31.data);
  v19 = idLib::production;
  if ( idLib::production != PROD_PRODUCTION && r_skipVmtrs.valueInteger == 0 )
  {
    idVirtualTextureSystem::ReadVmtrFile(this);
    v19 = idLib::production;
  }
  vt_upsampleFilter.flags &= ~0x20000u;
  vt_upsampleSharpen.flags &= ~0x20000u;
  vt_upsampleNoise.flags &= ~0x20000u;
  vt_showPageSources.flags &= ~0x20000u;
  vt_showPageMips.flags &= ~0x20000u;
  vt_showPageColors.flags &= ~0x20000u;
  vt_showPageNumbers.flags &= ~0x20000u;
  vt_showPageInfo.flags &= ~0x20000u;
  vt_showPageBorders.flags &= ~0x20000u;
  vt_showPageSizes.flags &= ~0x20000u;
  vt_showPageUsage.flags &= ~0x20000u;
  if ( v19 == PROD_PRODUCTION )
  {
    v20 = false;
    v21 = false;
    v22 = false;
  }
  else
  {
    v20 = true;
    v21 = true;
    v22 = true;
  }
  idVirtualTextureSystem::CreatePhysicalImages(
    this,
    mapHasSpecularPages_: v22,
    mapHasDiffuseOnlyPages_: v21,
    mapHasDiffuseOnly2Pages_: v20);
  v23 = sscanf(string: vt_pageImageSizeVmtr.valueString.data, format: "%i %i", &v27, &v26);
  if ( v23 == 0 )
  {
    v24 = 4096;
    v25 = 4096;
    v27 = 4096;
LABEL_47:
    v26 = v25;
    goto LABEL_48;
  }
  v24 = v27;
  if ( v23 == 1 )
  {
    v25 = v27;
    v26 = v27;
  }
  else
  {
    v25 = v26;
  }
  if ( v27 < 1024 )
  {
    v24 = 1024;
    v27 = 1024;
  }
  if ( v25 < 1024 )
  {
    v25 = 1024;
    goto LABEL_47;
  }
LABEL_48:
  idPhysicalPages::CreatePhysicalImages(
    this: this->physicalPagesPool,
    pool: PHYSICAL_PAGES_POOL_VMTR,
    name: "Vmtr",
    pageImageWidth: v24,
    pageImageHeight: v25,
    rpPhysicalFilterParms_: &rpPhysicalVmtrFilterParms);
  if ( this->vmtrMega->header.diskOffsetScale == 2 )
  {
    vmtrMega = this->vmtrMega;
    idVirtualTextureSystem::LockPhysicalPages(
      this,
      virtualTextures: &vmtrMega,
      numVirtualTextures: 1,
      maxLockedPages: 21);
  }
  v33.argc = 0;
  VirtualTextureInfo_f(args: &v33);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "vt_info",
    a3: VirtualTextureInfo_f,
    a4: "Reports information on the current virtual texture system",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "vt_emptyCache",
    a3: idVirtualTextureSystem::EmptyCache_f,
    a4: "empties and zeros the physical images",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "vt_lockPages",
    a3: idVirtualTextureSystem::LockPages_f,
    a4: "locks physical pages",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "vt_restart",
    a3: idVirtualTextureSystem::Restart_f,
    a4: "reallocates the physical images for changes in size or compression",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "vt_reload",
    a3: idVirtualTextureSystem::Reload_f,
    a4: "reload all the currently loaded virtual textures",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "vt_validateCache",
    a3: idVirtualTextureSystem::ValidateCache_f,
    a4: "consistency checks the page buffers",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "vt_setSource",
    a3: idVirtualTextureSystem::SetSource_f,
    a4: "Explicitly change the page file for a virtual material to compare",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "vt_benchmark",
    a3: idVirtualTextureSystem::VisualBenchmark_f,
    a4: "Benchmark the virtual texture transcoding",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "vt_visualBenchmark",
    a3: idVirtualTextureSystem::VisualBenchmark_f,
    a4: "Benchmark the virtual texture transcoding",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "vt_transcodeBenchmark",
    a3: idVirtualTextureSystem::TranscodeBenchmark_f,
    a4: "Benchmark the virtual texture transcoding",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "printVirtualMaterial",
    a3: idVirtualTextureSystem::PrintVirtualMaterial_f,
    a4: "prints data on a virtual material",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listVirtualTextures",
    a3: idVirtualTextureSystem::ListVirtualTextures_f,
    a4: "lists all the referenced virtual texture pagefile pathnames",
    a5: nullptr);
  idStr::FreeData(this: &v31);
  idStr::FreeData(this: &v29);
}


// ========================================================================
// $LN208
// EA  : 0x82986E6C
// RVA : 0x00986E6C
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _LN208()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2736 + 88), tag: TAG_VIRTUALTEXTURE);
}


// ========================================================================
// __unwind$244676
// EA  : 0x82986E98
// RVA : 0x00986E98
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_244676()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2736 + 96));
}


// ========================================================================
// __unwind$244677
// EA  : 0x82986EC0
// RVA : 0x00986EC0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_244677()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2736 + 240));
}


// ========================================================================
// __unwind$244678
// EA  : 0x82986EE8
// RVA : 0x00986EE8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _unwind_244678()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2736 + 208));
}


// ========================================================================
// `dynamic initializer for 'rpLandLayoutVersion''
// EA  : 0x8335E878
// RVA : 0x0135E878
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _dynamic_initializer_for__rpLandLayoutVersion__()
{
  rpLandLayoutVersion.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpLandLayoutVersion;
}


// ========================================================================
// `dynamic initializer for 'vt_uncompressedPhysicalImages''
// EA  : 0x8335E898
// RVA : 0x0135E898
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_uncompressedPhysicalImages__()
{
  idCVar::idCVar(
    this: &vt_uncompressedPhysicalImages,
    name: "vt_uncompressedPhysicalImages",
    value: "0",
    flags: 17,
    description: "Use uncompressed physical page images. vt_restart after changing this.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_uncompressedPhysicalImages__);
}


// ========================================================================
// `dynamic initializer for 'vt_filter''
// EA  : 0x8335E8F0
// RVA : 0x0135E8F0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_filter__()
{
  idCVar::idCVar(
    this: &vt_filter,
    name: "vt_filter",
    value: "1",
    flags: 17,
    description: "filter physical images",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_filter__);
}


// ========================================================================
// `dynamic initializer for 'vt_maxAniso''
// EA  : 0x8335E948
// RVA : 0x0135E948
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_maxAniso__()
{
  idCVar::idCVar(
    this: &vt_maxAniso,
    name: "vt_maxAniso",
    value: "2",
    flags: 20,
    description: "Floating point max ansio for physical textures.",
    valueMin: 1.0,
    valueMax: 4.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))off_82010000,
    a9: (int)"olor specular",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_maxAniso__);
}


// ========================================================================
// `dynamic initializer for 'vt_pageBorderAdjust''
// EA  : 0x8335E9B0
// RVA : 0x0135E9B0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_pageBorderAdjust__()
{
  idCVar::idCVar(
    this: &vt_pageBorderAdjust,
    name: "vt_pageBorderAdjust",
    value: "0",
    flags: 20,
    description: "Debug adjustment of a page's mapping about it's center",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_pageBorderAdjust__);
}


// ========================================================================
// `dynamic initializer for 'vt_feedbackLodBias''
// EA  : 0x8335EA08
// RVA : 0x0135EA08
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_feedbackLodBias__()
{
  idCVar::idCVar(
    this: &vt_feedbackLodBias,
    name: "vt_feedbackLodBias",
    value: "0",
    flags: 20,
    description: "Additional floating point bias for feedback LOD",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_feedbackLodBias__);
}


// ========================================================================
// `dynamic initializer for 'vt_feedbackHighWater''
// EA  : 0x8335EA60
// RVA : 0x0135EA60
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_feedbackHighWater__()
{
  idCVar::idCVar(
    this: &vt_feedbackHighWater,
    name: "vt_feedbackHighWater",
    value: "90",
    flags: 20,
    description: "More than this percentage of pages needed this frame and we consider ourselves oversubscribed.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_feedbackHighWater__);
}


// ========================================================================
// `dynamic initializer for 'vt_feedbackLowWater''
// EA  : 0x8335EAB8
// RVA : 0x0135EAB8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_feedbackLowWater__()
{
  idCVar::idCVar(
    this: &vt_feedbackLowWater,
    name: "vt_feedbackLowWater",
    value: "80",
    flags: 20,
    description: "Less than this percentage of pages needed this frame and we consider ourselves undersubscribed.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_feedbackLowWater__);
}


// ========================================================================
// `dynamic initializer for 'vt_feedbackLODIncrement''
// EA  : 0x8335EB10
// RVA : 0x0135EB10
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_feedbackLODIncrement__()
{
  idCVar::idCVar(
    this: &vt_feedbackLODIncrement,
    name: "vt_feedbackLODIncrement",
    value: "0.125",
    flags: 20,
    description: "Base increment value for adjusting dynamic LOD bias.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_feedbackLODIncrement__);
}


// ========================================================================
// `dynamic initializer for 'vt_lodBias''
// EA  : 0x8335EB68
// RVA : 0x0135EB68
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_lodBias__()
{
  idCVar::idCVar(
    this: &vt_lodBias,
    name: "vt_lodBias",
    value: "0",
    flags: 20,
    description: "Additional floating point bias for virtual texture page tables",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_lodBias__);
}


// ========================================================================
// `dynamic initializer for 'vt_useDirectTextureAccess''
// EA  : 0x8335EBC0
// RVA : 0x0135EBC0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_useDirectTextureAccess__()
{
  idCVar::idCVar(
    this: &vt_useDirectTextureAccess,
    name: "vt_useDirectTextureAccess",
    value: "1",
    flags: 17,
    description: "Use direct texture access extension on the PC if available.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_useDirectTextureAccess__);
}


// ========================================================================
// `dynamic initializer for 'virtualTextureSystem''
// EA  : 0x8335EC18
// RVA : 0x0135EC18
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__virtualTextureSystem__()
{
  idVirtualTextureSystem::idVirtualTextureSystem(this: &virtualTextureSystem);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__virtualTextureSystem__);
}


// ========================================================================
// `dynamic initializer for 'vt_useNonBufferedIO''
// EA  : 0x8335EC50
// RVA : 0x0135EC50
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_useNonBufferedIO__()
{
  idCVar::idCVar(
    this: &vt_useNonBufferedIO,
    name: "vt_useNonBufferedIO",
    value: "0",
    flags: 17,
    description: "use non-buffered IO",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_useNonBufferedIO__);
}


// ========================================================================
// `dynamic initializer for 'vt_showPageLoads''
// EA  : 0x8335ECA8
// RVA : 0x0135ECA8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_showPageLoads__()
{
  idCVar::idCVar(
    this: &vt_showPageLoads,
    name: "vt_showPageLoads",
    value: "0",
    flags: 18,
    description: "Print each page that is loaded",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_showPageLoads__);
}


// ========================================================================
// `dynamic initializer for 'vt_showFeedbackAnalysis''
// EA  : 0x8335ED00
// RVA : 0x0135ED00
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_showFeedbackAnalysis__()
{
  idCVar::idCVar(
    this: &vt_showFeedbackAnalysis,
    name: "vt_showFeedbackAnalysis",
    value: "0",
    flags: 18,
    description: "Report all the unique pages visible",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_showFeedbackAnalysis__);
}


// ========================================================================
// `dynamic initializer for 'vt_showFeedbackBuffer''
// EA  : 0x8335ED58
// RVA : 0x0135ED58
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_showFeedbackBuffer__()
{
  idCVar::idCVar(
    this: &vt_showFeedbackBuffer,
    name: "vt_showFeedbackBuffer",
    value: "0",
    flags: 18,
    description: "visualize the feedback buffer",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_showFeedbackBuffer__);
}


// ========================================================================
// `dynamic initializer for 'vt_showFeedbackStreaming''
// EA  : 0x8335EDB0
// RVA : 0x0135EDB0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_showFeedbackStreaming__()
{
  idCVar::idCVar(
    this: &vt_showFeedbackStreaming,
    name: "vt_showFeedbackStreaming",
    value: "0",
    flags: 18,
    description: "Display the feedback pages as they are streamed in",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_showFeedbackStreaming__);
}


// ========================================================================
// `dynamic initializer for 'vt_uncompressedVmtr''
// EA  : 0x8335EE08
// RVA : 0x0135EE08
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_uncompressedVmtr__()
{
  idCVar::idCVar(
    this: &vt_uncompressedVmtr,
    name: "vt_uncompressedVmtr",
    value: "0",
    flags: 17,
    description: "Use uncompressed vmtr data.  Only read at startup.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_uncompressedVmtr__);
}


// ========================================================================
// `dynamic initializer for 'vt_maxLockedPages''
// EA  : 0x8335EE60
// RVA : 0x0135EE60
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_maxLockedPages__()
{
  idCVar::idCVar(
    this: &vt_maxLockedPages,
    name: "vt_maxLockedPages",
    value: "64",
    flags: 18,
    description: "Don't lock more than pages than this.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_maxLockedPages__);
}


// ========================================================================
// `dynamic initializer for 'vt_skipStreaming''
// EA  : 0x8335EEB8
// RVA : 0x0135EEB8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_skipStreaming__()
{
  idCVar::idCVar(
    this: &vt_skipStreaming,
    name: "vt_skipStreaming",
    value: "0",
    flags: 17,
    description: "Skip streaming but still transcode and update the page tables",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_skipStreaming__);
}


// ========================================================================
// `dynamic initializer for 'vt_skipTranscode''
// EA  : 0x8335EF10
// RVA : 0x0135EF10
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_skipTranscode__()
{
  idCVar::idCVar(
    this: &vt_skipTranscode,
    name: "vt_skipTranscode",
    value: "0",
    flags: 17,
    description: "Skip transcoding (but don't skip reading)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_skipTranscode__);
}


// ========================================================================
// `dynamic initializer for 'vt_skipUpdatePageImages''
// EA  : 0x8335EF68
// RVA : 0x0135EF68
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_skipUpdatePageImages__()
{
  idCVar::idCVar(
    this: &vt_skipUpdatePageImages,
    name: "vt_skipUpdatePageImages",
    value: "0",
    flags: 17,
    description: "Skip updating page table and physical images on the PC (but still read/transcode)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_skipUpdatePageImages__);
}


// ========================================================================
// `dynamic initializer for 'vt_nopreload''
// EA  : 0x8335EFC0
// RVA : 0x0135EFC0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_nopreload__()
{
  idCVar::idCVar(
    this: &vt_nopreload,
    name: "vt_nopreload",
    value: "0",
    flags: 17,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_nopreload__);
}


// ========================================================================
// `dynamic initializer for 'vt_minLod''
// EA  : 0x8335F018
// RVA : 0x0135F018
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_minLod__()
{
  idCVar::idCVar(
    this: &vt_minLod,
    name: "vt_minLod",
    value: "0",
    flags: 18,
    description: "Set the finest mip that can be accessed.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_minLod__);
}


// ========================================================================
// `dynamic initializer for 'vt_genMissingPages''
// EA  : 0x8335F070
// RVA : 0x0135F070
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_genMissingPages__()
{
  idCVar::idCVar(
    this: &vt_genMissingPages,
    name: "vt_genMissingPages",
    value: "0",
    flags: 18,
    description: "Gen a page in memory for pages that don't exist on disk.",
    valueMin: 0.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"olor specular",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_genMissingPages__);
}


// ========================================================================
// `dynamic initializer for 'vt_showStats''
// EA  : 0x8335F0D8
// RVA : 0x0135F0D8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_showStats__()
{
  idCVar::idCVar(
    this: &vt_showStats,
    name: "vt_showStats",
    value: "0",
    flags: 17,
    description: "show virtual texture system statistics",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_showStats__);
}


// ========================================================================
// `dynamic initializer for 'vt_noSeekCacheLines''
// EA  : 0x8335F130
// RVA : 0x0135F130
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_noSeekCacheLines__()
{
  idCVar::idCVar(
    this: &vt_noSeekCacheLines,
    name: "vt_noSeekCacheLines",
    value: "4",
    flags: 18,
    description: "number of cache lines we can skip without seeking",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_noSeekCacheLines__);
}


// ========================================================================
// `dynamic initializer for 'vt_recordStats''
// EA  : 0x8335F188
// RVA : 0x0135F188
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_recordStats__()
{
  idCVar::idCVar(
    this: &vt_recordStats,
    name: "vt_recordStats",
    value: &byte_8200D768,
    flags: 16,
    description: "record virtual texture system statistics to the given file name",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_recordStats__);
}


// ========================================================================
// `dynamic initializer for 'vt_singleStep''
// EA  : 0x8335F1E0
// RVA : 0x0135F1E0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_singleStep__()
{
  idCVar::idCVar(
    this: &vt_singleStep,
    name: "vt_singleStep",
    value: "-1",
    flags: 18,
    description: "single step through the transcode process",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_singleStep__);
}


// ========================================================================
// `dynamic initializer for 'vt_splitTranscodeJobs''
// EA  : 0x8335F238
// RVA : 0x0135F238
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_splitTranscodeJobs__()
{
  idCVar::idCVar(
    this: &vt_splitTranscodeJobs,
    name: "vt_splitTranscodeJobs",
    value: "1",
    flags: 17,
    description: "split transcode jobs into two jobs per page",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_splitTranscodeJobs__);
}


// ========================================================================
// `dynamic initializer for 'vt_usePageTablePBOs''
// EA  : 0x8335F290
// RVA : 0x0135F290
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_usePageTablePBOs__()
{
  idCVar::idCVar(
    this: &vt_usePageTablePBOs,
    name: "vt_usePageTablePBOs",
    value: "1",
    flags: 17,
    description: "use the PBOs for page table updates on the PC",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_usePageTablePBOs__);
}


// ========================================================================
// `dynamic initializer for 'vt_useUnsynchronizedPageTablePBOs''
// EA  : 0x8335F2E8
// RVA : 0x0135F2E8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_useUnsynchronizedPageTablePBOs__()
{
  idCVar::idCVar(
    this: &vt_useUnsynchronizedPageTablePBOs,
    name: "vt_useUnsynchronizedPageTablePBOs",
    value: "0",
    flags: 17,
    description: "use unsynchronized PBOs for page table updates on the PC",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_useUnsynchronizedPageTablePBOs__);
}


// ========================================================================
// `dynamic initializer for 'vt_skipPhysicalTextureUploads''
// EA  : 0x8335F340
// RVA : 0x0135F340
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_skipPhysicalTextureUploads__()
{
  idCVar::idCVar(
    this: &vt_skipPhysicalTextureUploads,
    name: "vt_skipPhysicalTextureUploads",
    value: "0",
    flags: 17,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_skipPhysicalTextureUploads__);
}


// ========================================================================
// `dynamic initializer for 'vt_cancelObsoleteTranscodes''
// EA  : 0x8335F398
// RVA : 0x0135F398
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_cancelObsoleteTranscodes__()
{
  idCVar::idCVar(
    this: &vt_cancelObsoleteTranscodes,
    name: "vt_cancelObsoleteTranscodes",
    value: "0",
    flags: 18,
    description: &byte_8200D768,
    valueMin: 0.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)off_82010000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_cancelObsoleteTranscodes__);
}


// ========================================================================
// `dynamic initializer for 'vt_upsampleFilter''
// EA  : 0x8335F400
// RVA : 0x0135F400
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_upsampleFilter__()
{
  idCVar::idCVar(
    this: &vt_upsampleFilter,
    name: "vt_upsampleFilter",
    value: "3",
    flags: 18,
    description: "0 = nearest, 1 = bilinear, 2 = biquadratic, 3 = bicubic, 4 = sinc+hamming, 5 = sinc+blackman, 6 = sinc+lanczos, 7 = sinc+kaiser",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_upsampleFilter__);
}


// ========================================================================
// `dynamic initializer for 'vt_upsampleSharpen''
// EA  : 0x8335F458
// RVA : 0x0135F458
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_upsampleSharpen__()
{
  idCVar::idCVar(
    this: &vt_upsampleSharpen,
    name: "vt_upsampleSharpen",
    value: "96",
    flags: 18,
    description: "amount of sharpening to apply to upsampled texture pages",
    valueMin: 0.0,
    valueMax: 255.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"olor specular",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_upsampleSharpen__);
}


// ========================================================================
// `dynamic initializer for 'vt_upsampleNoise''
// EA  : 0x8335F4C0
// RVA : 0x0135F4C0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_upsampleNoise__()
{
  idCVar::idCVar(
    this: &vt_upsampleNoise,
    name: "vt_upsampleNoise",
    value: "8",
    flags: 18,
    description: "amount of noise to add to upsampled texture pages",
    valueMin: 0.0,
    valueMax: 255.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"olor specular",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_upsampleNoise__);
}


// ========================================================================
// `dynamic initializer for 'vt_reducePopping''
// EA  : 0x8335F528
// RVA : 0x0135F528
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_reducePopping__()
{
  idCVar::idCVar(
    this: &vt_reducePopping,
    name: "vt_reducePopping",
    value: "3",
    flags: 18,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_reducePopping__);
}


// ========================================================================
// `dynamic initializer for 'vt_showPageSources''
// EA  : 0x8335F580
// RVA : 0x0135F580
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_showPageSources__()
{
  idCVar::idCVar(
    this: &vt_showPageSources,
    name: "vt_showPageSources",
    value: "0",
    flags: 17,
    description: "Shades vmtr and unique pages differently",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_showPageSources__);
}


// ========================================================================
// `dynamic initializer for 'vt_stripPageBorders''
// EA  : 0x8335F5D8
// RVA : 0x0135F5D8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_stripPageBorders__()
{
  idCVar::idCVar(
    this: &vt_stripPageBorders,
    name: "vt_stripPageBorders",
    value: "0",
    flags: 17,
    description: "Strip the page border by upscaling the center",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_stripPageBorders__);
}


// ========================================================================
// `dynamic initializer for 'vt_showPageMips''
// EA  : 0x8335F630
// RVA : 0x0135F630
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_showPageMips__()
{
  idCVar::idCVar(
    this: &vt_showPageMips,
    name: "vt_showPageMips",
    value: "0",
    flags: 18,
    description: "Colorize pages by virtual mip level, if > 1, only color pages beyond that level-1",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_showPageMips__);
}


// ========================================================================
// `dynamic initializer for 'vt_showPageColors''
// EA  : 0x8335F688
// RVA : 0x0135F688
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_showPageColors__()
{
  idCVar::idCVar(
    this: &vt_showPageColors,
    name: "vt_showPageColors",
    value: "0",
    flags: 17,
    description: "use a random color for each page",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_showPageColors__);
}


// ========================================================================
// `dynamic initializer for 'vt_showPageNumbers''
// EA  : 0x8335F6E0
// RVA : 0x0135F6E0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_showPageNumbers__()
{
  idCVar::idCVar(
    this: &vt_showPageNumbers,
    name: "vt_showPageNumbers",
    value: "0",
    flags: 17,
    description: "Draw page numbers",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_showPageNumbers__);
}


// ========================================================================
// `dynamic initializer for 'vt_showPageInfo''
// EA  : 0x8335F738
// RVA : 0x0135F738
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_showPageInfo__()
{
  idCVar::idCVar(
    this: &vt_showPageInfo,
    name: "vt_showPageInfo",
    value: "0",
    flags: 17,
    description: "Shows page info: source #, layout #, compression, mono/color specular",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_showPageInfo__);
}


// ========================================================================
// `dynamic initializer for 'vt_showPageBorders''
// EA  : 0x8335F790
// RVA : 0x0135F790
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_showPageBorders__()
{
  idCVar::idCVar(
    this: &vt_showPageBorders,
    name: "vt_showPageBorders",
    value: "0",
    flags: 17,
    description: "Shows the page borders",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_showPageBorders__);
}


// ========================================================================
// `dynamic initializer for 'vt_showPageSizes''
// EA  : 0x8335F7E8
// RVA : 0x0135F7E8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_showPageSizes__()
{
  idCVar::idCVar(
    this: &vt_showPageSizes,
    name: "vt_showPageSizes",
    value: "0",
    flags: 18,
    description: "Draw page sizes (1 = show size in bytes, 2 = color green to red from small to large)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_showPageSizes__);
}


// ========================================================================
// `dynamic initializer for 'vt_showPageUsage''
// EA  : 0x8335F840
// RVA : 0x0135F840
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_showPageUsage__()
{
  idCVar::idCVar(
    this: &vt_showPageUsage,
    name: "vt_showPageUsage",
    value: "0",
    flags: 18,
    description: "color each page from red to green based on the percentage of the page texels that are actually visible",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_showPageUsage__);
}


// ========================================================================
// `dynamic initializer for 'vt_pageImageSizeVmtr''
// EA  : 0x8335F898
// RVA : 0x0135F898
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_pageImageSizeVmtr__()
{
  idCVar::idCVar(
    this: &vt_pageImageSizeVmtr,
    name: "vt_pageImageSizeVmtr",
    value: "2048",
    flags: 18,
    description: "Dimensions of the physical page images.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_pageImageSizeVmtr__);
}


// ========================================================================
// `dynamic initializer for 'vt_pageImageSizeUnique''
// EA  : 0x8335F8F0
// RVA : 0x0135F8F0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_pageImageSizeUnique__()
{
  idCVar::idCVar(
    this: &vt_pageImageSizeUnique,
    name: "vt_pageImageSizeUnique",
    value: "4096",
    flags: 18,
    description: "Dimensions of the physical page images.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_pageImageSizeUnique__);
}


// ========================================================================
// `dynamic initializer for 'vt_pageImageSizeUniqueDiffuseOnly''
// EA  : 0x8335F948
// RVA : 0x0135F948
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_pageImageSizeUniqueDiffuseOnly__()
{
  idCVar::idCVar(
    this: &vt_pageImageSizeUniqueDiffuseOnly,
    name: "vt_pageImageSizeUniqueDiffuseOnly",
    value: "4096",
    flags: 18,
    description: "Dimensions of the physical page images.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_pageImageSizeUniqueDiffuseOnly__);
}


// ========================================================================
// `dynamic initializer for 'vt_pageImageSizeUniqueDiffuseOnly2''
// EA  : 0x8335F9A0
// RVA : 0x0135F9A0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_pageImageSizeUniqueDiffuseOnly2__()
{
  idCVar::idCVar(
    this: &vt_pageImageSizeUniqueDiffuseOnly2,
    name: "vt_pageImageSizeUniqueDiffuseOnly2",
    value: "4096",
    flags: 18,
    description: "Dimensions of the physical page images.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_pageImageSizeUniqueDiffuseOnly2__);
}


// ========================================================================
// `dynamic initializer for 'vt_virtualSizeLog2''
// EA  : 0x8335F9F8
// RVA : 0x0135F9F8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_virtualSizeLog2__()
{
  idCVar::idCVar(
    this: &vt_virtualSizeLog2,
    name: "vt_virtualSizeLog2",
    value: "11",
    flags: 18,
    description: "Log2 of the virtualTexture dimensions for general texture allocation. Must be set on the command line.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_virtualSizeLog2__);
}


// ========================================================================
// `dynamic initializer for 'vt_useAnalyzeJobs''
// EA  : 0x8335FA50
// RVA : 0x0135FA50
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_useAnalyzeJobs__()
{
  idCVar::idCVar(
    this: &vt_useAnalyzeJobs,
    name: "vt_useAnalyzeJobs",
    value: "1",
    flags: 18,
    description: "0 = off, 1 = threaded",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)byte_821B0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_useAnalyzeJobs__);
}


// ========================================================================
// `dynamic initializer for 'vt_usePageSortJobs''
// EA  : 0x8335FAB8
// RVA : 0x0135FAB8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_usePageSortJobs__()
{
  idCVar::idCVar(
    this: &vt_usePageSortJobs,
    name: "vt_usePageSortJobs",
    value: "1",
    flags: 18,
    description: "0 = off, 1 = threaded",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)byte_821B0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_usePageSortJobs__);
}


// ========================================================================
// `dynamic initializer for 'vt_useTranscodeJobs''
// EA  : 0x8335FB20
// RVA : 0x0135FB20
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_useTranscodeJobs__()
{
  idCVar::idCVar(
    this: &vt_useTranscodeJobs,
    name: "vt_useTranscodeJobs",
    value: "1",
    flags: 18,
    description: "0 = off, 1 = threaded",
    valueMin: 0.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&off_82020000,
    a9: (int)byte_821B0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_useTranscodeJobs__);
}


// ========================================================================
// `dynamic initializer for 'vt_maxPPF''
// EA  : 0x8335FB88
// RVA : 0x0135FB88
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_maxPPF__()
{
  idCVar::idCVar(
    this: &vt_maxPPF,
    name: "vt_maxPPF",
    value: "16",
    flags: 18,
    description: "maximum number of transcoded pages per frame",
    valueMin: 0.0,
    valueMax: 128.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"olor specular",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_maxPPF__);
}


// ========================================================================
// `dynamic initializer for 'mt_sizeOverride''
// EA  : 0x8335FBF0
// RVA : 0x0135FBF0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mt_sizeOverride__()
{
  idCVar::idCVar(
    this: &mt_sizeOverride,
    name: "mt_sizeOverride",
    value: "0",
    flags: 2,
    description: "Override the default landscape resolution, specified in kiloTexels",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mt_sizeOverride__);
}


// ========================================================================
// `dynamic initializer for 'vt_skipExplicitPageFeedback''
// EA  : 0x8335FC48
// RVA : 0x0135FC48
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_skipExplicitPageFeedback__()
{
  idCVar::idCVar(
    this: &vt_skipExplicitPageFeedback,
    name: "vt_skipExplicitPageFeedback",
    value: "0",
    flags: 17,
    description: "don't append explicit pages from gui surfaces.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_skipExplicitPageFeedback__);
}


// ========================================================================
// `dynamic initializer for 'vt_showExplicitPages''
// EA  : 0x8335FCA0
// RVA : 0x0135FCA0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_showExplicitPages__()
{
  idCVar::idCVar(
    this: &vt_showExplicitPages,
    name: "vt_showExplicitPages",
    value: "0",
    flags: 17,
    description: "Report the number of explicit pages each frame.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_showExplicitPages__);
}


// ========================================================================
// `dynamic initializer for 'vt_containers''
// EA  : 0x8335FCF8
// RVA : 0x0135FCF8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_containers__()
{
  idCVar::idCVar(
    this: &vt_containers,
    name: "vt_containers",
    value: "0",
    flags: 17,
    description: "Set to enable loading from containers",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_containers__);
}


// ========================================================================
// `dynamic initializer for 'vt_packPageFiles''
// EA  : 0x8335FD50
// RVA : 0x0135FD50
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_packPageFiles__()
{
  idCVar::idCVar(
    this: &vt_packPageFiles,
    name: "vt_packPageFiles",
    value: "0",
    flags: 18,
    description: "Use the virtual texture file name without any suffixes, 0 = version vmtr and megas, 1 = version megas, 2 = version none ",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_packPageFiles__);
}


// ========================================================================
// `dynamic initializer for 'vt_useNetworkPagesWithPreload''
// EA  : 0x8335FDA8
// RVA : 0x0135FDA8
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_useNetworkPagesWithPreload__()
{
  idCVar::idCVar(
    this: &vt_useNetworkPagesWithPreload,
    name: "vt_useNetworkPagesWithPreload",
    value: "0",
    flags: 17,
    description: "Use the network page files and vmtr even when using linear preload files",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_useNetworkPagesWithPreload__);
}


// ========================================================================
// `dynamic initializer for 'vt_filePath''
// EA  : 0x8335FE00
// RVA : 0x0135FE00
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_filePath__()
{
  idCVar::idCVar(
    this: &vt_filePath,
    name: "vt_filePath",
    value: "mtp:/",
    flags: 16,
    description: "Path for the virtual texture",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_filePath__);
}


// ========================================================================
// `dynamic initializer for 'vt_filePathVmtrOverride''
// EA  : 0x8335FE58
// RVA : 0x0135FE58
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_filePathVmtrOverride__()
{
  idCVar::idCVar(
    this: &vt_filePathVmtrOverride,
    name: "vt_filePathVmtrOverride",
    value: "generated/pagefiles",
    flags: 16,
    description: "Optionally get vmtr files from a different source than vt_filePath",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_filePathVmtrOverride__);
}


// ========================================================================
// `dynamic initializer for 'vt_recordTrace''
// EA  : 0x8335FEB0
// RVA : 0x0135FEB0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_recordTrace__()
{
  idCVar::idCVar(
    this: &vt_recordTrace,
    name: "vt_recordTrace",
    value: "0",
    flags: 17,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_recordTrace__);
}


// ========================================================================
// `dynamic initializer for 'vt_createPagesFile''
// EA  : 0x8335FF08
// RVA : 0x0135FF08
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vt_createPagesFile__()
{
  idCVar::idCVar(
    this: &vt_createPagesFile,
    name: "vt_createPagesFile",
    value: "1",
    flags: 1,
    description: "1 = Create a new pages file if there is none for the specified material",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vt_createPagesFile__);
}


// ========================================================================
// `dynamic initializer for 'rpPhysicalVmtrFilterParms''
// EA  : 0x8335FF60
// RVA : 0x0135FF60
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _dynamic_initializer_for__rpPhysicalVmtrFilterParms__()
{
  rpPhysicalVmtrFilterParms.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpPhysicalVmtrFilterParms;
}


// ========================================================================
// `dynamic initializer for 'rpPhysicalUniqueFilterParms''
// EA  : 0x8335FF80
// RVA : 0x0135FF80
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _dynamic_initializer_for__rpPhysicalUniqueFilterParms__()
{
  rpPhysicalUniqueFilterParms.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpPhysicalUniqueFilterParms;
}


// ========================================================================
// `dynamic initializer for 'rpPhysicalUniqueDiffuseOnlyFilterParms''
// EA  : 0x8335FFA0
// RVA : 0x0135FFA0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _dynamic_initializer_for__rpPhysicalUniqueDiffuseOnlyFilterParms__()
{
  rpPhysicalUniqueDiffuseOnlyFilterParms.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpPhysicalUniqueDiffuseOnlyFilterParms;
}


// ========================================================================
// `dynamic initializer for 'rpPhysicalUniqueDiffuseOnly2FilterParms''
// EA  : 0x8335FFC0
// RVA : 0x0135FFC0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _dynamic_initializer_for__rpPhysicalUniqueDiffuseOnly2FilterParms__()
{
  rpPhysicalUniqueDiffuseOnly2FilterParms.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpPhysicalUniqueDiffuseOnly2FilterParms;
}


// ========================================================================
// `dynamic initializer for 'rpViewColor''_1
// EA  : 0x8335FFE0
// RVA : 0x0135FFE0
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _dynamic_initializer_for__rpViewColor___1()
{
  rpViewColor_1.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpViewColor_1;
}


// ========================================================================
// `dynamic initializer for 'progViewColorIdentity''_1
// EA  : 0x83360000
// RVA : 0x01360000
// PDB : w:\tech5\engine\renderer\virtualtexturesystem.cpp
// ========================================================================

void _dynamic_initializer_for__progViewColorIdentity___1()
{
  progViewColorIdentity_1.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = &progViewColorIdentity_1;
}

