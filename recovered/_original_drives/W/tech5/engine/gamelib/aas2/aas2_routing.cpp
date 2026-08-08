
// ========================================================================
// ?RoutingStats@idAAS2Local@@ABAXXZ
// EA  : 0x826B55B8
// RVA : 0x006B55B8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void __fastcall idAAS2Local::RoutingStats(idAAS2Local *this)
{
  idAASRoutingCache *cacheListStart; // r11
  int v3; // r31
  int v4; // r30
  int v5; // r29
  int i; // r8
  int v7; // r10

  cacheListStart = this->cacheListStart;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  for ( i = 0; cacheListStart != nullptr; cacheListStart = cacheListStart->time_next )
  {
    v7 = 3 * (cacheListStart->size + 16);
    if ( cacheListStart->type == 1 )
    {
      ++v4;
      i += v7;
    }
    else
    {
      ++v3;
      v5 += v7;
    }
  }
  idLib::Printf(fmt: "%6d area cache (%d kB)\n", v4, i >> 10);
  idLib::Printf(fmt: "%6d portal cache (%d kB)\n", v3, v5 >> 10);
  idLib::Printf(fmt: "%6d total cache (%d kB)\n", v3 + v4, this->totalCacheMemory >> 10);
  idLib::Printf(
    fmt: "%6d area travel times (%d kB)\n",
    this->numAreaTravelTimes,
    ((unsigned int)this->numAreaTravelTimes >> 9) & 0x3FFFFF);
  idLib::Printf(
    fmt: "%6d area cache entries (%d kB)\n",
    this->areaCacheIndexSize,
    ((unsigned int)this->areaCacheIndexSize >> 8) & 0x3FFFFF);
  idLib::Printf(
    fmt: "%6d portal cache entries (%d kB)\n",
    this->portalCacheIndexSize,
    ((unsigned int)this->portalCacheIndexSize >> 8) & 0x3FFFFF);
}


// ========================================================================
// ?UnlinkCache@idAAS2Local@@ABAXPAVidAASRoutingCache@@@Z
// EA  : 0x826B56A8
// RVA : 0x006B56A8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void __fastcall idAAS2Local::UnlinkCache(idAAS2Local *this, idAASRoutingCache *cache)
{
  idAASRoutingCache *time_next; // r11
  idAASRoutingCache *time_prev; // r11

  if ( cache != nullptr )
  {
    this->totalCacheMemory -= 3 * (cache->size + 16);
    time_next = cache->time_next;
    if ( time_next != nullptr )
      time_next->time_prev = cache->time_prev;
    else
      this->cacheListEnd = cache->time_prev;
    time_prev = cache->time_prev;
    if ( time_prev != nullptr )
      time_prev->time_next = cache->time_next;
    else
      this->cacheListStart = cache->time_next;
    cache->time_prev = nullptr;
    cache->time_next = nullptr;
  }
}


// ========================================================================
// ??0idAASRoutingCache@@QAA@H@Z
// EA  : 0x826B5728
// RVA : 0x006B5728
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

idAASRoutingCache *__fastcall idAASRoutingCache::idAASRoutingCache(idAASRoutingCache *this, unsigned int size)
{
  unsigned __int8 *v4; // r3
  unsigned int v5; // r5
  unsigned __int16 *v6; // r3

  this->size = size;
  this->areaNum = 0;
  this->cluster = 0;
  this->prev = nullptr;
  this->next = nullptr;
  this->time_prev = nullptr;
  this->time_next = nullptr;
  this->travelFlags = 0;
  this->startTravelTime = 0;
  this->type = 0;
  v4 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                            size,
                            tag: TAG_AAS,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  this->reachabilities = v4;
  memset(Dst: v4, Val: 0, Size: size);
  v5 = 2 * size;
  if ( size > 0x7FFFFFFF )
    v5 = -1;
  v6 = (unsigned __int16 *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
                             size: v5,
                             tag: TAG_AAS,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  this->travelTimes = v6;
  memset(Dst: v6, Val: 0, Size: 2 * size);
  return this;
}


// ========================================================================
// ?CalcTravelTime@idAAS2Local@@ABAGABVidVec3@@0H@Z
// EA  : 0x826B57F8
// RVA : 0x006B57F8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

int __fastcall idAAS2Local::CalcTravelTime(idAAS2Local *this, const idVec3 *start, const idVec3 *end, char travelFlags)
{
  double v4; // fp12
  double v5; // fp6
  double v6; // fp0
  double waterSpeedMultiplier; // fp13
  double v8; // fp0

  v4 = (float)(end->z - start->z);
  v5 = (float)(end->y - start->y);
  v6 = __fsqrts((float)((float)((float)v5 * (float)v5)
                      + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
                              + (float)((float)v4 * (float)v4))));
  if ( (travelFlags & 0x10) != 0 )
    waterSpeedMultiplier = this->waterSpeedMultiplier;
  else
    waterSpeedMultiplier = this->groundSpeedMultiplier;
  v8 = (float)((float)waterSpeedMultiplier * (float)v6);
  if ( v8 >= 1.0 )
    return (unsigned __int16)(int)v8;
  else
    return 1;
}


// ========================================================================
// ?ChangeReachabilityTravelFlags@idAAS2Local@@UAA_NPBDH_N@Z
// EA  : 0x826B5878
// RVA : 0x006B5878
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

int __fastcall idAAS2Local::ChangeReachabilityTravelFlags(idAAS2Local *this, const char *name, int travelFlag, int set)
{
  unsigned __int16 v8; // [sp+50h] [-30h] BYREF

  if ( this->file != nullptr
    && (idAAS2File::FindReachabilityByName(
          this: (idAAS2File *)&v8,
          result: (idIndex<short,enum invalidReachability_t> *)this->file,
          name),
        (v8 & 0x8000u) == 0) )
  {
    return ((int (__fastcall *)(idAAS2Local *, _DWORD, int, int))this->ChangeReachabilityTravelFlags_2)(
             a1: this,
             a2: v8,
             a3: travelFlag,
             a4: set);
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?LinkCache@idAAS2Local@@ABAXPAVidAASRoutingCache@@@Z
// EA  : 0x826B58F0
// RVA : 0x006B58F0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void __fastcall idAAS2Local::LinkCache(idAAS2Local *this, idAASRoutingCache *cache)
{
  idAASRoutingCache *cacheListEnd; // r11
  idAASRoutingCache *cacheListStart; // r11

  if ( cache != nullptr )
  {
    if ( cache->time_next != nullptr || cache->time_prev != nullptr || this->cacheListStart == cache )
      idAAS2Local::UnlinkCache(this, cache);
    this->totalCacheMemory += 3 * (cache->size + 16);
    cache->time_next = nullptr;
    cache->time_prev = this->cacheListEnd;
    cacheListEnd = this->cacheListEnd;
    if ( cacheListEnd != nullptr )
      cacheListEnd->time_next = cache;
    cacheListStart = this->cacheListStart;
    this->cacheListEnd = cache;
    if ( cacheListStart == nullptr )
      this->cacheListStart = cache;
  }
}


// ========================================================================
// ?TravelTimeToGoalArea@idAAS2Local@@UBAHHABVidVec3@@H0HABVidAAS2TravelSpeeds@@@Z
// EA  : 0x826B5990
// RVA : 0x006B5990
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

int __fastcall idAAS2Local::TravelTimeToGoalArea(
        idAAS2Local *this,
        int startAreaNum,
        const idVec3 *startOrigin,
        int goalAreaNum,
        const idVec3 *goalOrigin,
        int travelFlags,
        const idAAS2TravelSpeeds *travelSpeeds)
{
  idAAS2File *file; // r11
  bool v9; // r3
  __int16 v10; // [sp+50h] [-10h] BYREF
  int v11; // [sp+54h] [-Ch] BYREF

  file = this->file;
  v10 = -1;
  if ( file == nullptr )
    return 0;
  v9 = this->RouteToGoalArea(
         this,
         a2: startAreaNum,
         a3: startOrigin,
         a4: goalAreaNum,
         a5: goalOrigin,
         a6: travelFlags,
         a7: &v11,
         a8: (idIndex<short,enum invalidReachability_t> *)&v10);
  return !v9 ? 0 : v11;
}


// ========================================================================
// ?AreaTravelTime@idAAS2Local@@ABAGHABVidVec3@@0@Z
// EA  : 0x826B5A00
// RVA : 0x006B5A00
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

int __fastcall idAAS2Local::AreaTravelTime(idAAS2Local *this, int areaNum, const idVec3 *start, const idVec3 *end)
{
  idAAS2File *file; // r10

  file = this->file;
  if ( file != nullptr )
    return idAAS2Local::CalcTravelTime(this, start, end, travelFlags: file->areas.list[areaNum].travelFlags);
  else
    return 0;
}


// ========================================================================
// ?CalculateAreaTravelTimes@idAAS2Local@@AAAXXZ
// EA  : 0x826B5A38
// RVA : 0x006B5A38
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAAS2Local::CalculateAreaTravelTimes(idAAS2Local *this)
{
  idAAS2File *file; // r7
  int v3; // r5
  int v4; // r6
  aas2Area_t *v5; // r9
  int v6; // r8
  int value; // r11
  __int16 v8; // r4
  int v9; // r10
  int v10; // r11
  __int16 v11; // r4
  unsigned __int16 *v12; // r3
  idAAS2File *v13; // r8
  int v14; // r29
  int v15; // r4
  int i; // r27
  idAAS2File *v17; // r11
  aas2Area_t *v18; // r28
  unsigned __int16 v19; // r30
  int v20; // r3
  int v21; // r10
  int v22; // r5
  aas2Reachability_t *list; // r10
  int v24; // r7
  int v25; // r9
  aas2Reachability_t *v26; // r6
  int v27; // r8
  int v28; // r23 OVERLAPPED
  __int64 v29; // r25
  double v30; // fp6
  double v31; // fp7
  __int64 v32; // r25 OVERLAPPED
  __int64 v33; // r10
  unsigned __int16 v34; // r10
  double v35; // fp0
  double v36; // fp12
  double v37; // fp0
  double waterSpeedMultiplier; // fp13
  double v39; // fp0
  int v40; // r9
  __int16 v41; // r7
  int cluster; // r10
  idAAS2Local *v43; // r3
  __int64 v44; // [sp+68h] [-88h]

  file = this->file;
  if ( file == nullptr )
    return;
  v3 = 0;
  this->numAreaTravelTimes = 0;
  if ( file->areas.num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = &file->areas.list[v4];
      if ( (v5->flags & 2) != 0 )
      {
        v6 = 0;
        value = v5->reach.value;
        if ( value >= 0 )
        {
          do
          {
            ++v6;
            v8 = file->reachabilities.list[value].next.value;
            value = v8;
          }
          while ( v8 >= 0 );
        }
        v9 = 0;
        v10 = v5->rev_reach.value;
        if ( v10 >= 0 )
        {
          do
          {
            ++v9;
            v11 = file->reachabilities.list[v10].rev_next.value;
            v10 = v11;
          }
          while ( v11 >= 0 );
        }
        this->numAreaTravelTimes += v9 * v6;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->file->areas.num );
  }
  v12 = (unsigned __int16 *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\engine\\gamelib\\aas2\\AAS2_routing.cpp(149) : TAG_AAS",
                              size: 2 * this->numAreaTravelTimes,
                              tag: TAG_AAS,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  v13 = this->file;
  this->areaTravelTimes = v12;
  v14 = 0;
  v15 = 0;
  if ( v13->areas.num <= 0 )
    return;
  for ( i = 0; ; ++i )
  {
    v17 = this->file;
    v18 = &v17->areas.list[i];
    if ( (v18->flags & 2) != 0 )
      break;
LABEL_33:
    if ( ++v15 >= this->file->areas.num )
      return;
  }
  v19 = 0;
  v20 = 0;
  v21 = v18->reach.value;
  if ( v21 < 0 )
  {
LABEL_31:
    cluster = v18->cluster;
    if ( cluster < 0 )
      v17->portals.list[-cluster].maxAreaTravelTime = v19;
    goto LABEL_33;
  }
  while ( 1 )
  {
    v22 = v21;
    list = v17->reachabilities.list;
    v24 = 0;
    v25 = v18->rev_reach.value;
    v26 = &list[v22];
    if ( v25 >= 0 )
    {
      v27 = v14;
      do
      {
        HIDWORD(v33) = 32 * v25;
        LODWORD(v33) = (char *)list + HIDWORD(v33);
        v28 = (unsigned __int16)v26->start[2];
        LODWORD(v29) = v26->start[0];
        HIDWORD(v29) = v26->start[1];
        v30 = (double)v29;
        LODWORD(v29) = *(__int16 *)(v33 + 18);
        v31 = (double)*(__int64 *)(&v28 - 1);
        v44 = v29;
        HIDWORD(v32) = *(__int16 *)(v33 + 20);
        LODWORD(v32) = (__int16)v28;
        LODWORD(v33) = *(__int16 *)(v33 + 22);
        if ( v17 != nullptr )
        {
          v35 = (float)((float)v44 - (float)v30);
          v36 = (float)((float)*(__int64 *)((char *)&v32 + 4) - (float)v31);
          v37 = __fsqrts((float)((float)((float)v36 * (float)v36)
                               + (float)((float)((float)((float)v33 - (float)v32) * (float)((float)v33 - (float)v32))
                                       + (float)((float)v35 * (float)v35))));
          if ( (v17->areas.list[i].travelFlags & 0x10) != 0 )
            waterSpeedMultiplier = this->waterSpeedMultiplier;
          else
            waterSpeedMultiplier = this->groundSpeedMultiplier;
          v39 = (float)((float)waterSpeedMultiplier * (float)v37);
          if ( v39 >= 1.0 )
            v34 = (int)v39;
          else
            v34 = 1;
        }
        else
        {
          v34 = 0;
        }
        this->areaTravelTimes[v27] = v34 + 1;
        if ( v34 > (unsigned int)v19 )
          v19 = v34;
        v17 = this->file;
        ++v24;
        ++v27;
        list = v17->reachabilities.list;
        v25 = *(__int16 *)((char *)&list->rev_next.value + HIDWORD(v33));
      }
      while ( v25 >= 0 );
    }
    if ( v20 >= 0x1000000 )
      break;
    if ( v20 >= 256 )
      goto _LN148;
    v40 = (v20++ << 24) | v14;
    v14 += v24;
    list[v22].areaTTOfsAndNumber = v40;
    v17 = this->file;
    v41 = v17->reachabilities.list[v22].next.value;
    v21 = v41;
    if ( v41 < 0 )
      goto LABEL_31;
  }
  idLib::Error(fmt: "more than %d area travel times", 0x1000000);
_LN148:
  idLib::Error(fmt: "area %d has more than %d reachabilities", v15, 256);
  idAAS2Local::SetupRoutingCache(this: v43);
}


// ========================================================================
// ?SetupRoutingCache@idAAS2Local@@AAAXXZ
// EA  : 0x826B5DC0
// RVA : 0x006B5DC0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void __fastcall idAAS2Local::SetupRoutingCache(idAAS2Local *this)
{
  idAAS2File *file; // r9
  int v3; // r11
  int v4; // r10
  aas2Cluster_t *v5; // r8
  idAASRoutingCache ***v6; // r3
  idAAS2File *v7; // r11
  int v8; // r10
  int num; // r4
  idAASRoutingCache **v10; // r9
  int v11; // r7
  int v12; // r8
  aas2Cluster_t *v13; // r4
  int v14; // r11

  file = this->file;
  this->areaCacheIndexSize = 0;
  v3 = 0;
  if ( file->clusters.num > 0 )
  {
    v4 = 0;
    do
    {
      ++v3;
      v5 = &file->clusters.list[v4++];
      this->areaCacheIndexSize += v5->numReachableAreas;
    }
    while ( v3 < this->file->clusters.num );
  }
  v6 = (idAASRoutingCache ***)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\engine\\gamelib\\aas2\\AAS2_routing.cpp(227) : TAG_AAS",
                                size: 4 * (file->clusters.num + this->areaCacheIndexSize),
                                tag: TAG_AAS,
                                zeroBuffer: true,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v7 = this->file;
  this->areaCacheIndex = v6;
  v8 = 0;
  num = v7->clusters.num;
  v10 = (idAASRoutingCache **)&v6[num];
  if ( num > 0 )
  {
    v11 = 0;
    v12 = 0;
    do
    {
      ++v8;
      this->areaCacheIndex[v12++] = v10;
      v7 = this->file;
      v13 = &v7->clusters.list[v11++];
      v10 += v13->numReachableAreas;
    }
    while ( v8 < v7->clusters.num );
  }
  v14 = v7->areas.num;
  this->portalCacheIndexSize = v14;
  this->portalCacheIndex = (idAASRoutingCache **)idMem::AllocWithLocation(
                                                   this: &mem,
                                                   location: "w:\\tech5\\engine\\gamelib\\aas2\\AAS2_routing.cpp(235) : TAG_AAS",
                                                   size: 4 * v14,
                                                   tag: TAG_AAS,
                                                   zeroBuffer: true,
                                                   align: ALIGN_16,
                                                   heap: HEAP_DEFAULTHEAP);
  this->areaUpdate = (idRoutingUpdate *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\engine\\gamelib\\aas2\\AAS2_routing.cpp(237) : TAG_AAS",
                                          size: 40 * this->file->areas.num,
                                          tag: TAG_AAS,
                                          zeroBuffer: true,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
  this->portalUpdate = (idRoutingUpdate *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\engine\\gamelib\\aas2\\AAS2_routing.cpp(238) : TAG_AAS",
                                            size: 40 * (this->file->portals.num + 1),
                                            tag: TAG_AAS,
                                            zeroBuffer: true,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
  this->goalAreaTravelTimes = (unsigned __int16 *)idMem::AllocWithLocation(
                                                    this: &mem,
                                                    location: "w:\\tech5\\engine\\gamelib\\aas2\\AAS2_routing.cpp(239) : TAG_AAS",
                                                    size: 2 * this->file->areas.num,
                                                    tag: TAG_AAS,
                                                    zeroBuffer: true,
                                                    align: ALIGN_16,
                                                    heap: HEAP_DEFAULTHEAP);
  this->cacheListEnd = nullptr;
  this->cacheListStart = nullptr;
  this->totalCacheMemory = 0;
}


// ========================================================================
// ?DeleteClusterCache@idAAS2Local@@AAAXH@Z
// EA  : 0x826B5FA8
// RVA : 0x006B5FA8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void __fastcall idAAS2Local::DeleteClusterCache(idAAS2Local *this, int clusterNum)
{
  idAASRoutingCache ***areaCacheIndex; // r10
  int v4; // r24
  int v5; // r25
  int v6; // r26
  int v7; // r29
  idAASRoutingCache **v8; // r11
  idAASRoutingCache *i; // r31
  idAASRoutingCache *time_next; // r11
  idAASRoutingCache *time_prev; // r11

  areaCacheIndex = this->areaCacheIndex;
  if ( areaCacheIndex != nullptr )
  {
    v4 = clusterNum;
    v5 = 0;
    if ( this->file->clusters.list[clusterNum].numReachableAreas > 0 )
    {
      v6 = clusterNum;
      v7 = 0;
      do
      {
        v8 = areaCacheIndex[v6];
        for ( i = v8[v7]; i != nullptr; i = v8[v7] )
        {
          v8[v7] = i->next;
          this->totalCacheMemory -= 3 * (i->size + 16);
          time_next = i->time_next;
          if ( time_next != nullptr )
            time_next->time_prev = i->time_prev;
          else
            this->cacheListEnd = i->time_prev;
          time_prev = i->time_prev;
          if ( time_prev != nullptr )
            time_prev->time_next = i->time_next;
          else
            this->cacheListStart = i->time_next;
          i->time_prev = nullptr;
          i->time_next = nullptr;
          idMem::Free(this: &mem, ptr: i->reachabilities, align: ALIGN_16);
          idMem::Free(this: &mem, ptr: i->travelTimes, align: ALIGN_16);
          idMem::Free(this: &mem, ptr: i, align: ALIGN_16);
          areaCacheIndex = this->areaCacheIndex;
          v8 = areaCacheIndex[v6];
        }
        ++v5;
        ++v7;
      }
      while ( v5 < this->file->clusters.list[v4].numReachableAreas );
    }
  }
}


// ========================================================================
// ?DeletePortalCache@idAAS2Local@@AAAXXZ
// EA  : 0x826B60E0
// RVA : 0x006B60E0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void __fastcall idAAS2Local::DeletePortalCache(idAAS2Local *this)
{
  int v2; // r26
  int v3; // r29
  idAASRoutingCache **portalCacheIndex; // r11
  idAASRoutingCache *i; // r31
  idAASRoutingCache *time_next; // r11
  idAASRoutingCache *time_prev; // r11

  v2 = 0;
  if ( this->file->areas.num > 0 )
  {
    v3 = 0;
    do
    {
      portalCacheIndex = this->portalCacheIndex;
      for ( i = portalCacheIndex[v3]; i != nullptr; i = portalCacheIndex[v3] )
      {
        portalCacheIndex[v3] = i->next;
        this->totalCacheMemory -= 3 * (i->size + 16);
        time_next = i->time_next;
        if ( time_next != nullptr )
          time_next->time_prev = i->time_prev;
        else
          this->cacheListEnd = i->time_prev;
        time_prev = i->time_prev;
        if ( time_prev != nullptr )
          time_prev->time_next = i->time_next;
        else
          this->cacheListStart = i->time_next;
        i->time_prev = nullptr;
        i->time_next = nullptr;
        idMem::Free(this: &mem, ptr: i->reachabilities, align: ALIGN_16);
        idMem::Free(this: &mem, ptr: i->travelTimes, align: ALIGN_16);
        idMem::Free(this: &mem, ptr: i, align: ALIGN_16);
        portalCacheIndex = this->portalCacheIndex;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->file->areas.num );
  }
}


// ========================================================================
// ?ShutdownRoutingCache@idAAS2Local@@AAAXXZ
// EA  : 0x826B61F0
// RVA : 0x006B61F0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void __fastcall idAAS2Local::ShutdownRoutingCache(idAAS2Local *this)
{
  int i; // r30

  for ( i = 0; i < this->file->clusters.num; ++i )
    idAAS2Local::DeleteClusterCache(this, clusterNum: i);
  idAAS2Local::DeletePortalCache(this);
  idMem::Free(this: &mem, ptr: this->areaCacheIndex, align: ALIGN_16);
  this->areaCacheIndex = nullptr;
  this->areaCacheIndexSize = 0;
  idMem::Free(this: &mem, ptr: this->portalCacheIndex, align: ALIGN_16);
  this->portalCacheIndex = nullptr;
  this->portalCacheIndexSize = 0;
  idMem::Free(this: &mem, ptr: this->areaUpdate, align: ALIGN_16);
  this->areaUpdate = nullptr;
  idMem::Free(this: &mem, ptr: this->portalUpdate, align: ALIGN_16);
  this->portalUpdate = nullptr;
  idMem::Free(this: &mem, ptr: this->goalAreaTravelTimes, align: ALIGN_16);
  this->goalAreaTravelTimes = nullptr;
  this->cacheListEnd = nullptr;
  this->cacheListStart = nullptr;
  this->totalCacheMemory = 0;
}


// ========================================================================
// ?SetupRouting@idAAS2Local@@AAA_NXZ
// EA  : 0x826B62C8
// RVA : 0x006B62C8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

int __fastcall idAAS2Local::SetupRouting(idAAS2Local *this)
{
  idAAS2File *file; // r11

  file = this->file;
  this->groundSpeedMultiplier = (float)100.0 / file->settings.groundSpeed;
  this->waterSpeedMultiplier = (float)100.0 / file->settings.waterSpeed;
  idAAS2Local::CalculateAreaTravelTimes(this);
  idAAS2Local::SetupRoutingCache(this);
  return 1;
}


// ========================================================================
// ?ShutdownRouting@idAAS2Local@@AAAXXZ
// EA  : 0x826B6328
// RVA : 0x006B6328
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void __fastcall idAAS2Local::ShutdownRouting(idAAS2Local *this)
{
  idMem::Free(this: &mem, ptr: this->areaTravelTimes, align: ALIGN_16);
  this->areaTravelTimes = nullptr;
  this->numAreaTravelTimes = 0;
  idAAS2Local::ShutdownRoutingCache(this);
}


// ========================================================================
// ?RemoveRoutingCacheUsingArea@idAAS2Local@@AAAXH@Z
// EA  : 0x826B6378
// RVA : 0x006B6378
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void __fastcall idAAS2Local::RemoveRoutingCacheUsingArea(idAAS2Local *this, int areaNum)
{
  idAAS2Local *v2; // r31
  idAAS2File *file; // r11
  __int16 cluster; // r8
  int v5; // r4
  int v6; // r30

  v2 = this;
  file = this->file;
  cluster = file->areas.list[areaNum].cluster;
  v5 = cluster;
  if ( cluster <= 0 )
  {
    v6 = 12 * cluster;
    idAAS2Local::DeleteClusterCache(this, clusterNum: file->portals.list[v6 / 0xFFFFFFF4].clusters[0]);
    this = v2;
    v5 = v2->file->portals.list[v6 / 0xFFFFFFF4].clusters[1];
  }
  idAAS2Local::DeleteClusterCache(this, clusterNum: v5);
  idAAS2Local::DeletePortalCache(this: v2);
}


// ========================================================================
// ?ChangeAreaTravelFlags_r@idAAS2Local@@AAA_NHABVidBounds@@HH_N@Z
// EA  : 0x826B6418
// RVA : 0x006B6418
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

int __fastcall idAAS2Local::ChangeAreaTravelFlags_r(
        idAAS2Local *this,
        int nodeNum,
        idBounds *bounds,
        int areaFlags,
        int travelFlags,
        bool set)
{
  int v11; // r25
  bool v12; // cr56
  idAAS2File *file; // r11
  aas2Node_t *v14; // r31
  int v15; // r3
  unsigned __int8 v16; // r11
  aas2Area_t *list; // r11
  int v19; // r4
  int v20; // r10
  unsigned int v21; // r9
  int v22; // r8

  v11 = 0;
  if ( nodeNum == 0 )
    return v11;
  v12 = nodeNum < 0;
  while ( !v12 )
  {
    file = this->file;
    v14 = &file->nodes.list[nodeNum];
    v15 = idBounds::PlaneSide(this: bounds, plane: &file->planes.list[v14->planeNum], epsilon: 0.1);
    if ( v15 == 1 )
    {
      nodeNum = v14->children[1];
    }
    else
    {
      if ( v15 != 0 )
      {
        if ( idAAS2Local::ChangeAreaTravelFlags_r(this, nodeNum: v14->children[1], bounds, areaFlags, travelFlags, set)
          || (v16 = 0, (_BYTE)v11 != 0) )
        {
          v16 = 1;
        }
        v11 = v16;
      }
      nodeNum = v14->children[0];
    }
    v12 = nodeNum < 0;
    if ( nodeNum == 0 )
      return v11;
  }
  list = this->file->areas.list;
  if ( (list[-nodeNum].flags & (unsigned __int16)areaFlags) == 0 )
    return v11;
  v19 = -nodeNum;
  v20 = v19;
  v21 = list[v19].travelFlags;
  v22 = v21 & travelFlags;
  if ( set )
  {
    if ( v22 == 0 )
    {
      list[v20].travelFlags = v21 | travelFlags;
      idAAS2Local::RemoveRoutingCacheUsingArea(this, areaNum: v19);
      return 1;
    }
  }
  else if ( v22 != 0 )
  {
    list[v20].travelFlags &= ~travelFlags;
    idAAS2Local::RemoveRoutingCacheUsingArea(this, areaNum: v19);
  }
  return 1;
}


// ========================================================================
// ?ChangeAreaTravelFlags@idAAS2Local@@UAA_NABVidBounds@@HH_N@Z
// EA  : 0x826B6588
// RVA : 0x006B6588
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

int __fastcall idAAS2Local::ChangeAreaTravelFlags(
        idAAS2Local *this,
        const idBounds *bounds,
        int areaFlags,
        int travelFlags,
        bool set)
{
  float *file; // r10
  double x; // fp11
  double y; // fp10
  double v9; // fp5
  double v10; // fp4
  double v11; // fp12
  double v12; // fp11
  idBounds v13; // [sp+50h] [-20h] BYREF

  if ( this->file == nullptr )
    return 0;
  file = (float *)this->file;
  x = bounds->b[1].x;
  y = bounds->b[1].y;
  v9 = (float)(bounds->b[0].y - file[44]);
  v10 = (float)(bounds->b[0].z - file[45]);
  v13.b[0].x = bounds->b[0].x - file[43];
  v13.b[0].y = v9;
  v13.b[0].z = v10;
  v11 = (float)((float)x - file[40]);
  v12 = (float)(bounds->b[1].z - file[42]);
  v13.b[1].y = (float)y - file[41];
  v13.b[1].x = v11;
  v13.b[1].z = v12;
  return idAAS2Local::ChangeAreaTravelFlags_r(this, nodeNum: 1, bounds: &v13, areaFlags, travelFlags, set);
}


// ========================================================================
// ?ChangeReachabilityTravelFlags@idAAS2Local@@UAA_NV?$idIndex@FW4invalidReachability_t@@@@H_N@Z
// EA  : 0x826B6648
// RVA : 0x006B6648
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

int __fastcall idAAS2Local::ChangeReachabilityTravelFlags(
        idAAS2Local *this,
        idIndex<short,enum invalidReachability_t> *index,
        int travelFlag,
        bool set)
{
  idAAS2File *file; // r11
  aas2Reachability_t *list; // r11
  int v8; // r31
  unsigned int travelFlags; // r10
  int v10; // r9

  file = this->file;
  if ( file == nullptr || (__int16)index < 0 )
    return 0;
  list = file->reachabilities.list;
  v8 = (__int16)index;
  travelFlags = list[v8].travelFlags;
  v10 = travelFlags | travelFlag;
  if ( !set )
    v10 = travelFlags & ~travelFlag;
  list[(__int16)index].travelFlags = v10;
  idAAS2Local::RemoveRoutingCacheUsingArea(this, areaNum: this->file->reachabilities.list[v8].fromAreaNum);
  idAAS2Local::RemoveRoutingCacheUsingArea(this, areaNum: this->file->reachabilities.list[v8].toAreaNum);
  return 1;
}


// ========================================================================
// ?GetAreaReachability@idAAS2Local@@ABA?AV?$idIndex@FW4invalidReachability_t@@@@HH@Z
// EA  : 0x826B66F0
// RVA : 0x006B66F0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

idAAS2Local *__fastcall idAAS2Local::GetAreaReachability(
        idAAS2Local *this,
        idIndex<short,enum invalidReachability_t> *result,
        int areaNum,
        int reachabilityNum)
{
  int v4; // r9
  __int16 v5; // r10
  int v6; // r11

  v4 = *(_DWORD *)&result[2].value;
  v5 = *(_WORD *)(*(_DWORD *)(v4 + 448) + 40 * areaNum + 20);
  v6 = v5;
  if ( v5 < 0 )
  {
LABEL_4:
    HIWORD(this->__vftable) = -1;
  }
  else
  {
    while ( --reachabilityNum >= 0 )
    {
      v5 = *(_WORD *)(*(_DWORD *)(v4 + 432) + 32 * v6 + 28);
      v6 = v5;
      if ( v5 < 0 )
        goto LABEL_4;
    }
    HIWORD(this->__vftable) = v5;
  }
  return this;
}


// ========================================================================
// ?ClusterAreaNum@idAAS2Local@@ABAHHH@Z
// EA  : 0x826B6750
// RVA : 0x006B6750
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

int __fastcall idAAS2Local::ClusterAreaNum(idAAS2Local *this, int clusterNum, int areaNum)
{
  idAAS2File *file; // r10
  int v4; // r9
  int v5; // r11

  file = this->file;
  v4 = (int)&file->areas.list[areaNum];
  v5 = *(__int16 *)(v4 + 12);
  if ( v5 <= 0 )
    return file->portals.list->clusterAreaNum[(clusterNum != file->portals.list[-v5].clusters[0]) - 6 * v5];
  else
    return *(unsigned __int16 *)(v4 + 14);
}


// ========================================================================
// ?FindNearestGoal@idAAS2Local@@UBA_NAAUidAAS2Goal@@HABVidVec3@@HAAVidAAS2Callback@@@Z
// EA  : 0x826B67C8
// RVA : 0x006B67C8
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idAAS2Local::FindNearestGoal(
        idAAS2Local *this,
        idAAS2Goal *goal,
        int startAreaNum,
        const idVec3 *startOrigin,
        int travelFlags,
        idAAS2Callback *callback)
{
  idAAS2Goal *v7; // r28
  int result; // r3
  int v13; // r2 OVERLAPPED
  unsigned __int16 v14; // r19
  int v15; // r14
  idRoutingUpdate *v16; // r15
  idRoutingUpdate *v17; // r16
  idRoutingUpdate *next; // r11
  idRoutingUpdate *v19; // r22
  idAAS2File *file; // r11
  int value; // r10
  int v22; // r20
  int v23; // r31
  int v24; // r25
  aas2Area_t *list; // r10
  int v26; // r26
  char *v27; // r23
  int v28; // r9
  __int64 v29; // r9
  __int64 v30; // r4
  __int64 v31; // r4 OVERLAPPED
  __int64 v32; // r7
  __int16 v33; // r9
  unsigned __int16 tmpTravelTime; // r11
  __int64 v35; // fp13
  int v36; // r5
  __int16 v37; // r10
  idAAS2Callback_vtbl *v38; // r9
  int (__fastcall *AdditionalTravelTimeForPath)(idAAS2Callback *, const idAAS2 *, const idVec3 *, const idVec3 *); // r9
  int v40; // r27
  int v41; // r3
  __int64 v42; // r8
  unsigned __int16 v43; // r27
  __int64 v44; // r11
  int v45; // r3
  idAAS2Callback_vtbl *v46; // r4
  bool (__fastcall *PathValid)(idAAS2Callback *, const idAAS2 *, const idVec3 *, const idVec3 *); // ctr
  char *v48; // r11
  __int64 v49; // r4
  __int16 v50; // r10
  int v51; // r10
  __int64 v52; // r9 OVERLAPPED
  __int64 v53; // r11
  idAAS2Local_vtbl *v54; // r6
  idVec3 *(__fastcall *AreaCenter)(struct idAAS2Local *, idVec3 *, int); // ctr
  const idVec3 *v56; // r3
  idAAS2File *v57; // r10
  __int16 v58; // r3
  unsigned __int16 v59; // r29
  __int64 v60; // r9
  __int64 v61; // r11
  int v62; // r3
  idAAS2Callback_vtbl *v63; // r5
  bool (__fastcall *AreaIsGoal)(idAAS2Callback *, const idAAS2 *, int, const idVec3 *); // ctr
  __int16 v65; // r9
  idVec3 *v66; // r3
  float v67[4]; // [sp+50h] [-190h] BYREF
  float v68[4]; // [sp+60h] [-180h] BYREF
  float v69[4]; // [sp+70h] [-170h] BYREF
  idVec3 v70; // [sp+80h] [-160h] BYREF
  idVec3 v71; // [sp+90h] [-150h] BYREF
  __int64 v72; // [sp+A0h] [-140h]
  __int64 v73; // [sp+A8h] [-138h]
  __int64 v74; // [sp+B0h] [-130h]
  __int64 v75; // [sp+B8h] [-128h]
  __int64 v76; // [sp+C0h] [-120h]
  __int64 v77; // [sp+C8h] [-118h]
  __int64 v78; // [sp+D0h] [-110h]
  __int64 v79; // [sp+D8h] [-108h]
  __int64 v80; // [sp+E0h] [-100h]
  __int64 v81; // [sp+E8h] [-F8h]
  __int64 v82; // [sp+F0h] [-F0h]
  __int64 v83; // [sp+F8h] [-E8h]
  __int64 v84; // [sp+100h] [-E0h]
  __int64 v85; // [sp+108h] [-D8h]
  __int64 v86; // [sp+110h] [-D0h]
  __int64 v87; // [sp+118h] [-C8h]
  __int64 v88; // [sp+120h] [-C0h]
  __int64 v89; // [sp+128h] [-B8h]
  struct idAAS2Local v90; // [sp+130h] [-B0h] BYREF

  v7 = goal;
  if ( this->file == nullptr || startAreaNum <= 0 || this->goalAreaTravelTimes == nullptr || this->areaUpdate == nullptr )
  {
    result = 0;
    goto LABEL_48;
  }
  if ( ((unsigned __int8 (__fastcall *)(idAAS2Callback *, idAAS2Local *))callback->AreaIsGoal)(a1: callback, a2: this) != 0 )
  {
    result = 1;
LABEL_48:
    v7->areaNum = startAreaNum;
    v7->origin.x = startOrigin->x;
    v7->origin.y = startOrigin->y;
    v7->origin.z = startOrigin->z;
    return result;
  }
  memset(Dst: this->goalAreaTravelTimes, Val: 0, Size: 2 * this->file->areas.num);
  v14 = 0;
  v15 = 0;
  v16 = &this->areaUpdate[startAreaNum];
  v17 = v16;
  v16->areaNum = startAreaNum;
  v16->tmpTravelTime = 0;
  v16->start.x = startOrigin->x;
  v16->start.y = startOrigin->y;
  v16->start.z = startOrigin->z;
  v16->next = nullptr;
  v16->prev = nullptr;
  do
  {
    next = v16->next;
    v19 = v16;
    if ( next != nullptr )
      next->prev = nullptr;
    else
      v17 = nullptr;
    v16 = v16->next;
    v19->isInList = false;
    if ( v14 == 0 || v19->tmpTravelTime < (unsigned int)v14 )
    {
      file = this->file;
      value = file->areas.list[v19->areaNum].reach.value;
      if ( value >= 0 )
      {
        do
        {
          v22 = value;
          v23 = (int)&file->reachabilities.list[value];
          if ( (*(_DWORD *)v23 & travelFlags) != 0 && (~travelFlags & *(_DWORD *)v23) == 0 )
          {
            v24 = *(unsigned __int16 *)(v23 + 8);
            list = file->areas.list;
            v26 = 8 * (v24 + __ROL4__(v24, 2));
            v27 = (char *)list + v26;
            v28 = *(unsigned int *)((char *)&list->travelFlags + v26);
            if ( (v28 & travelFlags) != 0 && (v28 & ~travelFlags) == 0 )
            {
              HIDWORD(v29) = *(unsigned __int16 *)(v23 + 16);
              LODWORD(v30) = *(__int16 *)(v23 + 14);
              HIDWORD(v30) = SWORD1(v29);
              LODWORD(v29) = *(__int16 *)(v23 + 12);
              v79 = v30;
              v82 = *(_QWORD *)(&v13 - 1);
              v80 = v29;
              v70.y = (float)v30;
              v70.x = (float)v29;
              v70.z = (float)*(__int64 *)(&v13 - 1);
              HIDWORD(v31) = file != nullptr
                           ? idAAS2Local::CalcTravelTime(
                               this,
                               start: &v19->start,
                               end: &v70,
                               travelFlags: list[v19->areaNum].travelFlags)
                           : 0;
              HIDWORD(v32) = v67;
              LODWORD(v31) = *(__int16 *)(v23 + 20);
              v33 = *(_WORD *)(v23 + 22);
              LODWORD(v32) = *(__int16 *)(v23 + 18);
              tmpTravelTime = v19->tmpTravelTime;
              v86 = v31;
              v35 = v31;
              v88 = v32;
              v36 = v33;
              v37 = *(_WORD *)(v23 + 4);
              v38 = callback->__vftable;
              LODWORD(v31) = this;
              v84 = *(__int64 *)((char *)&v31 - 4);
              AdditionalTravelTimeForPath = v38->AdditionalTravelTimeForPath;
              v67[2] = (float)*(__int64 *)((char *)&v31 - 4);
              v40 = (unsigned __int16)(v37 + tmpTravelTime + WORD1(v31));
              v67[0] = (float)v32;
              v67[1] = (float)v35;
              v41 = AdditionalTravelTimeForPath(this: callback, a2: this, a3: &v19->start, a4: (const idVec3 *)v67);
              HIDWORD(v42) = v41 + v40;
              v43 = v41 + v40;
              if ( v14 == 0 || v43 < (unsigned int)v14 )
              {
                if ( this->goalAreaTravelTimes[v24] == 0 || v43 < (unsigned int)this->goalAreaTravelTimes[v24] )
                {
                  HIDWORD(v44) = *(unsigned __int16 *)(v23 + 22);
                  v45 = *(__int16 *)(v23 + 20);
                  LOWORD(v42) = *(_WORD *)(v23 + 18);
                  LODWORD(v44) = SWORD1(v44);
                  v46 = callback->__vftable;
                  v89 = *(_QWORD *)(&v13 - 1);
                  LODWORD(v42) = (__int16)v42;
                  v75 = v44;
                  v83 = v42;
                  v69[0] = (float)v42;
                  PathValid = v46->PathValid;
                  v69[1] = (float)*(__int64 *)(&v13 - 1);
                  v69[2] = (float)v44;
                  if ( PathValid(this: callback, a2: this, a3: &v19->start, a4: (const idVec3 *)v69) )
                  {
                    this->goalAreaTravelTimes[v24] = v43;
                    v48 = (char *)this->areaUpdate + v26;
                    *((_WORD *)v48 + 4) = v43;
                    *((_DWORD *)v48 + 1) = v24;
                    LODWORD(v52) = *(unsigned __int16 *)(v23 + 22);
                    HIDWORD(v49) = (__int16)v52;
                    v50 = *(_WORD *)(v23 + 20);
                    WORD1(v52) = *(_WORD *)(v23 + 18);
                    v72 = *(_QWORD *)(&v13 - 1);
                    LODWORD(v49) = v50;
                    v51 = SWORD1(v52);
                    *((float *)v48 + 6) = (float)*(__int64 *)(&v13 - 1);
                    v77 = v49;
                    v87 = *(__int64 *)((char *)&v52 - 4);
                    *((float *)v48 + 5) = (float)v49;
                    *((float *)v48 + 4) = (float)*(__int64 *)((char *)&v52 - 4);
                    HIDWORD(v52) = (char *)this->file->areas.list + v26;
                    if ( (*(_WORD *)(HIDWORD(v52) + 4) & 1) != 0 )
                      *((_WORD *)v48 + 4) += 250;
                    if ( v48[36] == 0 )
                    {
                      *((_DWORD *)v48 + 8) = v17;
                      *((_DWORD *)v48 + 7) = 0;
                      if ( v17 != nullptr )
                        v17->next = (idRoutingUpdate *)v48;
                      else
                        v16 = (idRoutingUpdate *)v48;
                      v17 = (idRoutingUpdate *)v48;
                      v48[36] = 1;
                    }
                    if ( (*((_WORD *)v27 + 2) & 1) == 0 )
                    {
                      LODWORD(v53) = *(__int16 *)(v23 + 18);
                      HIDWORD(v53) = *(__int16 *)(v23 + 22);
                      v54 = this->__vftable;
                      LODWORD(v52) = *(__int16 *)(v23 + 20);
                      v85 = v53;
                      v81 = *(__int64 *)((char *)&v52 - 4);
                      v73 = v52;
                      AreaCenter = v54->AreaCenter;
                      v71.x = (float)v53;
                      v71.z = (float)*(__int64 *)((char *)&v52 - 4);
                      v71.y = (float)v52;
                      v56 = AreaCenter(this: &v90, result: (idVec3 *)this, a3: v24);
                      v57 = this->file;
                      v58 = v57 != nullptr
                          ? idAAS2Local::CalcTravelTime(
                              this,
                              start: &v71,
                              end: v56,
                              travelFlags: *(&v57->areas.list->travelFlags
                              + 2 * *(unsigned __int16 *)(v23 + 8)
                              + 2 * __ROL4__(*(unsigned __int16 *)(v23 + 8), 2)))
                          : 0;
                      v59 = v58 + v43;
                      if ( v14 == 0 || (unsigned __int16)(v58 + v43) < (unsigned int)v14 )
                      {
                        HIDWORD(v60) = *(unsigned __int16 *)(v23 + 20);
                        LODWORD(v60) = SWORD1(v60);
                        HIDWORD(v61) = *(unsigned __int16 *)(v23 + 18);
                        v62 = *(__int16 *)(v23 + 22);
                        v63 = callback->__vftable;
                        v74 = v60;
                        LODWORD(v61) = SWORD1(v61);
                        v76 = *(_QWORD *)(&v13 - 1);
                        v78 = v61;
                        v68[0] = (float)v61;
                        AreaIsGoal = v63->AreaIsGoal;
                        v68[1] = (float)v60;
                        v68[2] = (float)*(__int64 *)(&v13 - 1);
                        if ( AreaIsGoal(
                               this: callback,
                               a2: this,
                               a3: *(unsigned __int16 *)(v23 + 8),
                               a4: (const idVec3 *)v68) )
                        {
                          v15 = *(unsigned __int16 *)(v23 + 8);
                          v14 = v59;
                        }
                      }
                    }
                  }
                }
                v7 = goal;
              }
            }
          }
          file = this->file;
          v65 = file->reachabilities.list[v22].next.value;
          value = v65;
        }
        while ( v65 >= 0 );
      }
    }
  }
  while ( v16 != nullptr );
  if ( v15 == 0 )
    return 0;
  v7->areaNum = v15;
  v66 = this->AreaCenter(this: &v90, result: this, a3: v15);
  v7->origin.x = v66->x;
  v7->origin.y = v66->y;
  v7->origin.z = v66->z;
  return 1;
}


// ========================================================================
// ?NearestPointReachable@idAAS2Local@@UBA_NV?$idIndex@HW4invalidAASTree_t@@@@ABVidVec3@@H1ABVidBounds@@HAAUidAAS2NearestReachable@@@Z
// EA  : 0x826B6E30
// RVA : 0x006B6E30
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

int __fastcall idAAS2Local::NearestPointReachable(
        idAAS2Local *this,
        idIndex<int,enum invalidAASTree_t> *tree,
        const idVec3 *src,
        int srcAreaNum,
        const idVec3 *dst,
        __int64 travelFlags,
        idAAS2NearestReachable *nearestInfo)
{
  __int64 v7; // r26
  char *v9; // r10
  int v10; // r21
  int v12; // ctr
  int v16; // r3
  int v17; // r19
  int v18; // r27
  double v19; // fp31
  double v20; // fp27
  int v21; // r23
  double v22; // fp26
  int v23; // r20
  double v24; // fp25
  double v25; // fp30
  double v26; // fp29
  double v27; // fp28
  int *v28; // r31
  int i; // r18
  float y; // r10
  float z; // r9
  idAAS2Local_vtbl *v32; // r8
  int v33; // r4
  unsigned __int8 v34; // r11
  __int16 v36; // [sp+50h] [-180h] BYREF
  int v37; // [sp+54h] [-17Ch] BYREF
  float x; // [sp+58h] [-178h] BYREF
  float v39; // [sp+5Ch] [-174h]
  float v40; // [sp+60h] [-170h]
  __int64 v41; // [sp+70h] [-160h]
  __int64 v42; // [sp+78h] [-158h]
  __int64 v43; // [sp+80h] [-150h]
  __int64 v44; // [sp+88h] [-148h]
  __int64 v45; // [sp+90h] [-140h]
  char v46; // [sp+98h] [-138h] BYREF
  int v47[46]; // [sp+A0h] [-130h] BYREF

  LODWORD(v7) = 0;
  v9 = &v46;
  v10 = travelFlags;
  v12 = 16;
  LODWORD(travelFlags) = 0;
  do
  {
    v9 += 8;
    *(_QWORD *)v9 = travelFlags;
    --v12;
  }
  while ( v12 != 0 );
  v16 = idAAS2File::BoundsAreaNums(
          this: this->file,
          (int)tree,
          bounds: (idBounds *)HIDWORD(travelFlags),
          areas: v47,
          maxAreas: 32);
  if ( v16 == 0 || srcAreaNum == 0 )
    return 0;
  v17 = 0x7FFFFFFF;
  v41 = v7;
  v18 = 0x7FFFFFFF;
  v42 = v7;
  v43 = v7;
  v19 = 3.4028235e38;
  v44 = v7;
  v45 = v7;
  v20 = *(float *)&v7;
  v21 = 0;
  v22 = 0.0;
  v23 = HIDWORD(v7);
  v24 = *(float *)&v7;
  v25 = 0.0;
  v26 = *(float *)&v7;
  v27 = 0.0;
  if ( v16 > 0 )
  {
    v28 = v47;
    for ( i = v16; i != 0; --i )
    {
      v36 = -1;
      v37 = 0;
      if ( this->RouteToGoalArea(
             this,
             a2: srcAreaNum,
             a3: src,
             a4: *v28,
             a5: dst,
             a6: v10,
             a7: &v37,
             a8: (idIndex<short,enum invalidReachability_t> *)&v36) )
      {
        y = dst->y;
        z = dst->z;
        v32 = this->__vftable;
        v33 = *v28;
        x = dst->x;
        v39 = y;
        v40 = z;
        v32->PushPointIntoAreaNum(this, a2: v33, a3: (idVec3 *)&x);
        if ( v37 < v18 )
        {
          v21 = *v28;
          v18 = v37;
          v24 = x;
          v22 = v39;
          v20 = v40;
        }
        if ( (float)((float)((float)(dst->x - x) * (float)(dst->x - x))
                   + (float)((float)((float)(dst->z - v40) * (float)(dst->z - v40))
                           + (float)((float)(dst->y - v39) * (float)(dst->y - v39)))) < v19 )
        {
          v23 = *v28;
          v19 = (float)((float)((float)(dst->x - x) * (float)(dst->x - x))
                      + (float)((float)((float)(dst->z - v40) * (float)(dst->z - v40))
                              + (float)((float)(dst->y - v39) * (float)(dst->y - v39))));
          v17 = v37;
          v27 = x;
          v26 = v39;
          v25 = v40;
        }
      }
      ++v28;
    }
  }
  nearestInfo->nearestDestArea = v23;
  nearestInfo->nearestDestPos.x = v27;
  nearestInfo->nearestDestPos.y = v26;
  nearestInfo->nearestDestPos.z = v25;
  nearestInfo->nearestTravelTime = v17;
  nearestInfo->quickestDestArea = v21;
  nearestInfo->quickestDestPos.x = v24;
  nearestInfo->quickestDestPos.y = v22;
  nearestInfo->quickestDestPos.z = v20;
  nearestInfo->quickestTravelTime = v18;
  if ( v21 == 0 )
    return 0;
  v34 = 1;
  if ( v23 == 0 )
    return 0;
  return v34;
}


// ========================================================================
// ?DeleteOldestCache@idAAS2Local@@ABAXXZ
// EA  : 0x826B7058
// RVA : 0x006B7058
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void __fastcall idAAS2Local::DeleteOldestCache(idAAS2Local *this)
{
  idAASRoutingCache *cacheListStart; // r31
  idAAS2Local *v2; // r3
  idAASRoutingCache *next; // r11
  idAASRoutingCache *prev; // r11
  idAASRoutingCache ***areaCacheIndex; // r30
  int cluster; // r29
  idAASRoutingCache **portalCacheIndex; // r11

  cacheListStart = this->cacheListStart;
  if ( cacheListStart != nullptr )
  {
    idAAS2Local::UnlinkCache(this, cache: this->cacheListStart);
    next = cacheListStart->next;
    if ( next != nullptr )
      next->prev = cacheListStart->prev;
    prev = cacheListStart->prev;
    if ( prev != nullptr )
    {
      prev->next = cacheListStart->next;
    }
    else if ( cacheListStart->type == 1 )
    {
      areaCacheIndex = v2->areaCacheIndex;
      if ( areaCacheIndex != nullptr )
      {
        cluster = cacheListStart->cluster;
        areaCacheIndex[cluster][idAAS2Local::ClusterAreaNum(
                                  this: v2,
                                  clusterNum: cluster,
                                  areaNum: cacheListStart->areaNum)] = cacheListStart->next;
      }
    }
    else if ( cacheListStart->type == 2 )
    {
      portalCacheIndex = v2->portalCacheIndex;
      if ( portalCacheIndex != nullptr )
        portalCacheIndex[cacheListStart->areaNum] = cacheListStart->next;
    }
    idMem::Free(this: &mem, ptr: cacheListStart->reachabilities, align: ALIGN_16);
    idMem::Free(this: &mem, ptr: cacheListStart->travelTimes, align: ALIGN_16);
    idMem::Free(this: &mem, ptr: cacheListStart, align: ALIGN_16);
  }
}


// ========================================================================
// ?UpdateAreaRoutingCache@idAAS2Local@@ABAXPAVidAASRoutingCache@@@Z
// EA  : 0x826B7150
// RVA : 0x006B7150
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void __fastcall idAAS2Local::UpdateAreaRoutingCache(idAAS2Local *this, idAASRoutingCache *areaCache)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  int cluster; // r4
  int numReachableAreas; // r19
  int v8; // r3
  int v9; // r30
  idRoutingUpdate *v10; // r22
  idRoutingUpdate *v11; // r20
  idRoutingUpdate *next; // r11
  idRoutingUpdate *v13; // r25
  idAAS2File *file; // r11
  int value; // r10
  int v16; // r24
  int v17; // r23
  int travelFlags; // r10
  int v19; // r30
  int v20; // r9
  int v21; // r29
  int v22; // r27
  char *v23; // r9
  int v24; // r11
  int v25; // r3
  unsigned __int16 *travelTimes; // r9
  unsigned __int16 v27; // r10
  idRoutingUpdate *v28; // r11
  __int16 v29; // r9
  idPLogScope v30[2]; // [sp+50h] [-290h] BYREF
  _BYTE v31[512]; // [sp+60h] [-280h] BYREF

  RD_EventBegin(name: "idAAS2Local::UpdateAreaRoutingCache");
  LODWORD(v4) = "idAAS2Local::UpdateAreaRoutingCache";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: v30, pl: &pLog, gMask: v4, label: v5);
  if ( this->areaUpdate != nullptr && this->areaTravelTimes != nullptr )
  {
    cluster = areaCache->cluster;
    numReachableAreas = this->file->clusters.list[cluster].numReachableAreas;
    v8 = idAAS2Local::ClusterAreaNum(this, clusterNum: cluster, areaNum: areaCache->areaNum);
    v9 = v8;
    if ( v8 < numReachableAreas )
    {
      areaCache->travelTimes[v8] = areaCache->startTravelTime;
      memset(Dst: v31, Val: 0, Size: sizeof(v31));
      v10 = &this->areaUpdate[v9];
      v11 = v10;
      v10->areaNum = areaCache->areaNum;
      v10->areaTravelTimes = (unsigned __int16 *)v31;
      v10->tmpTravelTime = areaCache->startTravelTime;
      v10->next = nullptr;
      v10->prev = nullptr;
      do
      {
        next = v10->next;
        v13 = v10;
        if ( next != nullptr )
          next->prev = nullptr;
        else
          v11 = nullptr;
        v10->isInList = false;
        file = this->file;
        v10 = v10->next;
        value = file->areas.list[v13->areaNum].rev_reach.value;
        if ( value >= 0 )
        {
          v16 = 0;
          do
          {
            v17 = value;
            v19 = (int)&file->reachabilities.list[value];
            v20 = *(_DWORD *)v19;
            travelFlags = areaCache->travelFlags;
            if ( (*(_DWORD *)v19 & travelFlags) != 0
              && (~travelFlags & v20) == 0
              && ((v20 & 0x2400000) == 0 || (v20 & 0x1870000) != 0) )
            {
              v21 = *(unsigned __int16 *)(v19 + 6);
              v22 = 8 * (v21 + __ROL4__(v21, 2));
              v23 = (char *)file->areas.list + v22;
              if ( (*(_DWORD *)v23 & travelFlags) != 0 && (*(_DWORD *)v23 & ~travelFlags) == 0 )
              {
                v24 = *((__int16 *)v23 + 6);
                if ( v24 <= 0 || v24 == areaCache->cluster )
                {
                  v25 = idAAS2Local::ClusterAreaNum(
                          this,
                          clusterNum: areaCache->cluster,
                          areaNum: *(unsigned __int16 *)(v19 + 6));
                  if ( v25 < numReachableAreas )
                  {
                    travelTimes = areaCache->travelTimes;
                    v27 = v13->areaTravelTimes[v16] + *(_WORD *)(v19 + 4) + v13->tmpTravelTime;
                    if ( travelTimes[v25] == 0
                      || (unsigned __int16)(v13->areaTravelTimes[v16] + *(_WORD *)(v19 + 4) + v13->tmpTravelTime) < (unsigned int)travelTimes[v25] )
                    {
                      travelTimes[v25] = v27;
                      areaCache->reachabilities[v25] = *(_BYTE *)(v19 + 24);
                      v28 = &this->areaUpdate[v25];
                      v28->areaNum = v21;
                      v28->tmpTravelTime = v27;
                      v28->areaTravelTimes = (unsigned __int16 *)((char *)this->areaTravelTimes
                                                                + ((2 * *(_DWORD *)(v19 + 24)) & 0x1FFFFFE));
                      if ( (*(unsigned __int16 *)((_BYTE *)&this->file->areas.list->flags + v22) & 1) != 0 )
                        v28->tmpTravelTime = v27 + 250;
                      if ( !v28->isInList )
                      {
                        v28->prev = v11;
                        v28->next = nullptr;
                        if ( v11 != nullptr )
                          v11->next = v28;
                        else
                          v10 = v28;
                        v11 = v28;
                        v28->isInList = true;
                      }
                    }
                  }
                }
              }
            }
            file = this->file;
            ++v16;
            v29 = file->reachabilities.list[v17].rev_next.value;
            value = v29;
          }
          while ( v29 >= 0 );
        }
      }
      while ( v10 != nullptr );
    }
  }
  idPLogScope::~idPLogScope(this: v30);
  RD_EventEnd();
}


// ========================================================================
// __unwind$248999
// EA  : 0x826B7474
// RVA : 0x006B7474
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void _unwind_248999()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 736 + 608));
}


// ========================================================================
// __unwind$249000
// EA  : 0x826B749C
// RVA : 0x006B749C
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void _unwind_249000()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 736 + 80));
}


// ========================================================================
// ?GetAreaRoutingCache@idAAS2Local@@ABAPAVidAASRoutingCache@@HHH@Z
// EA  : 0x826B74D0
// RVA : 0x006B74D0
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

idAASRoutingCache *__fastcall idAAS2Local::GetAreaRoutingCache(
        idAAS2Local *this,
        int clusterNum,
        int areaNum,
        int travelFlags)
{
  idAASRoutingCache ***areaCacheIndex; // r29
  int v10; // r23
  int v11; // r22
  idAASRoutingCache *v12; // r28
  idAASRoutingCache *v13; // r29
  int v14; // r21
  idAASRoutingCache *v15; // r3
  idAASRoutingCache *v16; // r4
  unsigned __int64 v17; // r4
  double v18; // [sp+18h] [-A8h]

  areaCacheIndex = this->areaCacheIndex;
  if ( areaCacheIndex == nullptr )
    return nullptr;
  v10 = clusterNum;
  v11 = idAAS2Local::ClusterAreaNum(this, clusterNum, areaNum);
  v12 = areaCacheIndex[clusterNum][v11];
  v13 = v12;
  if ( v12 != nullptr )
  {
    while ( v13->travelFlags != travelFlags )
    {
      v13 = v13->next;
      if ( v13 == nullptr )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v14 = 0;
    if ( aas_showCacheMisses.valueInteger != 0 )
      v14 = Sys_Microseconds() >> 32;
    v15 = (idAASRoutingCache *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x30u,
                                 tag: TAG_AAS,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
    if ( v15 != nullptr )
      v16 = idAASRoutingCache::idAASRoutingCache(
              this: v15,
              size: this->file->clusters.list[clusterNum].numReachableAreas);
    else
      v16 = nullptr;
    v16->cluster = clusterNum;
    v16->areaNum = areaNum;
    v13 = v16;
    v16->type = 1;
    v16->startTravelTime = 1;
    v16->travelFlags = travelFlags;
    v16->prev = nullptr;
    v16->next = v12;
    if ( v12 != nullptr )
      v12->prev = v16;
    this->areaCacheIndex[v10][v11] = v16;
    idAAS2Local::UpdateAreaRoutingCache(this, areaCache: v16);
    if ( aas_showCacheMisses.valueInteger != 0 )
    {
      v17 = Sys_Microseconds();
      v18 = (float)((float)_u64tod(a1: HIDWORD(v17) - v14, a2: v17) * (float)0.001);
      idLib::Warning(fmt: (const char *)HIDWORD(v18), LODWORD(v18), areaNum);
    }
  }
  idAAS2Local::LinkCache(this, cache: v13);
  return v13;
}


// ========================================================================
// __unwind$249117
// EA  : 0x826B7660
// RVA : 0x006B7660
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void _unwind_249117()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 80), tag: TAG_AAS);
}


// ========================================================================
// ?UpdatePortalRoutingCache@idAAS2Local@@ABAXPAVidAASRoutingCache@@@Z
// EA  : 0x826B7690
// RVA : 0x006B7690
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void __fastcall idAAS2Local::UpdatePortalRoutingCache(idAAS2Local *this, idAASRoutingCache *portalCache)
{
  idRoutingUpdate *portalUpdate; // r9
  idRoutingUpdate *v5; // r27
  idRoutingUpdate *v6; // r26
  idRoutingUpdate *next; // r11
  idRoutingUpdate *v8; // r30
  int cluster; // r4
  aas2Cluster_t *v10; // r28
  idAASRoutingCache *AreaRoutingCache; // r3
  int i; // r4
  idAAS2File *file; // r9
  aas2Area_t *list; // r8
  int v15; // r11
  aas2Portal_t *v16; // r7
  int v17; // r9
  __int16 v18; // r6
  int v19; // r5
  unsigned __int16 v20; // r6
  unsigned __int16 *travelTimes; // r9
  unsigned __int16 v22; // r8
  __int16 v23; // r6
  idRoutingUpdate *v24; // r11
  unsigned __int16 v25; // r9
  BOOL isInList; // r8

  portalUpdate = this->portalUpdate;
  if ( portalUpdate != nullptr )
  {
    v5 = &portalUpdate[this->file->portals.num];
    v6 = v5;
    v5->cluster = portalCache->cluster;
    v5->areaNum = portalCache->areaNum;
    v5->tmpTravelTime = portalCache->startTravelTime;
    v5->next = nullptr;
    v5->prev = nullptr;
    do
    {
      next = v5->next;
      v8 = v5;
      if ( next != nullptr )
        next->prev = nullptr;
      else
        v6 = nullptr;
      v5->isInList = false;
      cluster = v5->cluster;
      v5 = v5->next;
      v10 = &this->file->clusters.list[v8->cluster];
      AreaRoutingCache = idAAS2Local::GetAreaRoutingCache(
                           this,
                           clusterNum: cluster,
                           areaNum: v8->areaNum,
                           travelFlags: portalCache->travelFlags);
      for ( i = 0; i < v10->numPortals; ++i )
      {
        file = this->file;
        list = file->areas.list;
        v15 = file->portalIndex.list[v10->firstPortal + i];
        v16 = &file->portals.list[v15];
        v17 = 8 * (v16->areaNum + __ROL4__(v16->areaNum, 2));
        v18 = *(__int16 *)((char *)&list->cluster + v17);
        if ( v18 <= 0 )
          v19 = this->file->portals.list->clusterAreaNum[(v8->cluster != this->file->portals.list[-v18].clusters[0])
                                                       - 6 * v18];
        else
          v19 = *(unsigned __int16 *)((char *)&this->file->areas.list->clusterAreaNum + v17);
        if ( v19 < v10->numReachableAreas )
        {
          v20 = AreaRoutingCache->travelTimes[v19];
          if ( v20 != 0 )
          {
            travelTimes = portalCache->travelTimes;
            v22 = v8->tmpTravelTime + v20;
            if ( travelTimes[v15] == 0 || (unsigned __int16)(v8->tmpTravelTime + v20) < (unsigned int)travelTimes[v15] )
            {
              travelTimes[v15] = v22;
              portalCache->reachabilities[v15] = AreaRoutingCache->reachabilities[v19];
              v23 = v16->clusters[0];
              v24 = &this->portalUpdate[v15];
              v24->cluster = v23 == v8->cluster ? v16->clusters[1] : v23;
              v25 = v22;
              isInList = v24->isInList;
              v24->areaNum = v16->areaNum;
              v24->tmpTravelTime = v16->maxAreaTravelTime + v25;
              if ( !isInList )
              {
                v24->prev = v6;
                v24->next = nullptr;
                if ( v6 != nullptr )
                  v6->next = v24;
                else
                  v5 = v24;
                v6 = v24;
                v24->isInList = true;
              }
            }
          }
        }
      }
    }
    while ( v5 != nullptr );
  }
}


// ========================================================================
// ?GetPortalRoutingCache@idAAS2Local@@ABAPAVidAASRoutingCache@@HHH@Z
// EA  : 0x826B7910
// RVA : 0x006B7910
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

idAASRoutingCache *__fastcall idAAS2Local::GetPortalRoutingCache(
        idAAS2Local *this,
        int clusterNum,
        int areaNum,
        int travelFlags)
{
  idAASRoutingCache **portalCacheIndex; // r11
  int v10; // r28
  idAASRoutingCache *v11; // r29
  idAASRoutingCache *v12; // r3
  idAASRoutingCache *v13; // r4
  idAASRoutingCache **v14; // r6

  portalCacheIndex = this->portalCacheIndex;
  if ( portalCacheIndex == nullptr )
    return nullptr;
  v10 = areaNum;
  v11 = portalCacheIndex[areaNum];
  if ( v11 != nullptr )
  {
    while ( v11->travelFlags != travelFlags )
    {
      v11 = v11->next;
      if ( v11 == nullptr )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v12 = (idAASRoutingCache *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0x30u,
                                 tag: TAG_AAS,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
    if ( v12 != nullptr )
      v13 = idAASRoutingCache::idAASRoutingCache(this: v12, size: this->file->portals.num);
    else
      v13 = nullptr;
    v13->cluster = clusterNum;
    v13->areaNum = areaNum;
    v13->type = 2;
    v11 = v13;
    v13->startTravelTime = 1;
    v13->travelFlags = travelFlags;
    v13->prev = nullptr;
    v13->next = this->portalCacheIndex[v10];
    v14 = this->portalCacheIndex;
    if ( v14[v10] != nullptr )
      v14[v10]->prev = v13;
    this->portalCacheIndex[v10] = v13;
    idAAS2Local::UpdatePortalRoutingCache(this, portalCache: v13);
  }
  idAAS2Local::LinkCache(this, cache: v11);
  return v11;
}


// ========================================================================
// __unwind$249264
// EA  : 0x826B7A30
// RVA : 0x006B7A30
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void _unwind_249264()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_AAS);
}


// ========================================================================
// ?GetClusterRoute@idAAS2Local@@ABA_NHABVidVec3@@HHHAAHAAV?$idIndex@FW4invalidReachability_t@@@@@Z
// EA  : 0x826B7A60
// RVA : 0x006B7A60
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idAAS2Local::GetClusterRoute(
        idAAS2Local *this,
        int startAreaNum,
        const idVec3 *startOrigin,
        int startClusterNum,
        int goalAreaNum,
        int travelFlags,
        int *travelTime,
        idIndex<short,enum invalidReachability_t> *bestReachIndex)
{
  idAASRoutingCache *AreaRoutingCache; // r23
  int v16; // r11
  int v18; // r8
  __int16 *AreaReachability; // r3
  int v20; // r9
  idAAS2File *file; // r10
  aas2Reachability_t *v22; // r11
  int v23; // r4 OVERLAPPED
  __int64 v24; // r6
  __int64 v25; // r3 OVERLAPPED
  unsigned __int16 v26; // r3
  idAAS2File *v27; // r29
  __int16 value; // r24
  int i; // r11
  int v30; // r22
  aas2Reachability_t *list; // r26
  aas2Reachability_t *v32; // r30
  unsigned int v33; // r11
  int toAreaNum; // r31
  aas2Area_t *v35; // r27
  int v36; // r11
  __int64 v37; // r9 OVERLAPPED
  int v38; // r2 OVERLAPPED
  aas2Reachability_t *v39; // r11
  int v40; // r7 OVERLAPPED
  __int128 v41; // r6 OVERLAPPED
  int v42; // r10
  unsigned __int16 v43; // r3
  __int64 v44; // r7
  int v45; // r11
  int v46; // r3
  int v47; // r11
  int v48; // r10
  unsigned __int16 v49; // r3
  int v50; // r11
  idAAS2Local v51; // [sp+50h] [-110h] BYREF

  AreaRoutingCache = idAAS2Local::GetAreaRoutingCache(
                       this,
                       clusterNum: startClusterNum,
                       areaNum: goalAreaNum,
                       travelFlags);
  v16 = idAAS2Local::ClusterAreaNum(this, clusterNum: startClusterNum, areaNum: startAreaNum);
  if ( AreaRoutingCache->travelTimes[v16] == 0 )
    return 0;
  AreaReachability = (__int16 *)idAAS2Local::GetAreaReachability(
                                  this: &v51,
                                  result: (idIndex<short,enum invalidReachability_t> *)this,
                                  areaNum: startAreaNum,
                                  reachabilityNum: AreaRoutingCache->reachabilities[v16]);
  v20 = *AreaReachability;
  bestReachIndex->value = *AreaReachability;
  file = this->file;
  v22 = &file->reachabilities.list[v20];
  v23 = (unsigned __int16)v22->start[2];
  LODWORD(v24) = (__int16)v23;
  HIDWORD(v24) = v22->start[1];
  LODWORD(v25) = v22->start[0];
  *(_QWORD *)&v51.name.len = v25;
  *(float *)&v51.cacheListStart = (float)v24;
  *(float *)&v51.numAreaTravelTimes = (float)*(__int64 *)(&v23 - 1);
  *(float *)&v51.areaTravelTimes = (float)v25;
  if ( file != nullptr )
    v26 = idAAS2Local::CalcTravelTime(
            this,
            start: startOrigin,
            end: (const idVec3 *)&v51.areaTravelTimes,
            travelFlags: file->areas.list[startAreaNum].travelFlags);
  else
    v26 = 0;
  *travelTime = *(unsigned __int16 *)((char *)AreaRoutingCache->travelTimes + v18) + v26;
  v27 = this->file;
  value = v27->areas.list[startAreaNum].reach.value;
  for ( i = value; value >= 0; i = value )
  {
    v30 = i;
    list = v27->reachabilities.list;
    v32 = &list[i];
    if ( i != bestReachIndex->value )
    {
      v33 = v32->travelFlags;
      if ( (v32->travelFlags & travelFlags) != 0
        && (v33 & ~travelFlags) == 0
        && ((v33 & 0x2400000) == 0 || (v33 & 0x1870000) != 0) )
      {
        toAreaNum = v32->toAreaNum;
        v35 = v27->areas.list;
        if ( *(&v35->cluster + 4 * toAreaNum + 4 * __ROL4__(toAreaNum, 2)) == startClusterNum )
        {
          v36 = idAAS2Local::ClusterAreaNum(this, clusterNum: startClusterNum, areaNum: v32->toAreaNum);
          if ( AreaRoutingCache->travelTimes[v36] != 0 )
          {
            LOWORD(v37) = HIWORD(idAAS2Local::GetAreaReachability(
                                   this: &v51,
                                   result: (idIndex<short,enum invalidReachability_t> *)this,
                                   areaNum: toAreaNum,
                                   reachabilityNum: AreaRoutingCache->reachabilities[v36])->__vftable);
            if ( (__int16)v37 != -1 )
            {
              v39 = &list[(__int16)v37];
              if ( v39->toAreaNum != startAreaNum )
              {
                v40 = v32->end[1];
                HIDWORD(v41) = (unsigned __int16)v39->start[2];
                LODWORD(v41) = v32->end[2];
                DWORD1(v41) = v39->start[1];
                LOWORD(v37) = v32->end[0];
                DWORD2(v41) = SWORD1(v41);
                v42 = v39->start[0];
                *(_QWORD *)&v51.name.allocedAndFlag = v41;
                LODWORD(v37) = (__int16)v37;
                *(_QWORD *)&v51.name.baseBuffer[12] = *(_QWORD *)((char *)&v41 + 4);
                *(_QWORD *)&v51.areaCacheIndexSize = *(__int64 *)((char *)&v37 - 4);
                *(_QWORD *)&v51.defaulted = v37;
                *(_QWORD *)&v51.name.baseBuffer[4] = *(_QWORD *)&v41;
                *(_QWORD *)&v51.name.len = *(_QWORD *)&v40;
                *(float *)&v51.obstaclePVSAreaNum = (float)*(__int64 *)&v40;
                v51.waterSpeedMultiplier = (float)*(__int64 *)((char *)&v41 + 4);
                v51.groundSpeedMultiplier = (float)*(__int64 *)&v41;
                *(float *)&v51.areaClipModels = (float)(__int64)v41;
                *(float *)&v51.obstaclePVS = (float)v37;
                *(float *)&v51.totalCacheMemory = (float)*(__int64 *)((char *)&v37 - 4);
                if ( v27 != nullptr )
                  v43 = idAAS2Local::CalcTravelTime(
                          this,
                          start: (const idVec3 *)&v51.obstaclePVS,
                          end: (const idVec3 *)&v51.totalCacheMemory,
                          travelFlags: v35[toAreaNum].travelFlags);
                else
                  v43 = 0;
                LODWORD(v44) = v32->start[0];
                HIDWORD(v44) = (unsigned __int16)v32->start[1];
                LODWORD(v37) = v32->start[2];
                v45 = v32->travelTime;
                *(_QWORD *)&v51.areaTravelTimes = v44;
                *(_QWORD *)&v51.portalUpdate = v37;
                v47 = v45 + v43;
                v46 = SWORD1(v44);
                *(_QWORD *)&v51.portalCacheIndexSize = *(_QWORD *)(&v38 - 1);
                v48 = v47 + HIDWORD(v37);
                *(float *)&v51.clipModelLinkAllocator.total = (float)*(__int64 *)(&v38 - 1);
                *(float *)&v51.clipModelLinkAllocator.free = (float)v44;
                *(float *)&v51.clipModelLinkAllocator.active = (float)v37;
                if ( v27 != nullptr )
                  v49 = idAAS2Local::CalcTravelTime(
                          this,
                          start: startOrigin,
                          end: (const idVec3 *)&v51.clipModelLinkAllocator.free,
                          travelFlags: v35[startAreaNum].travelFlags);
                else
                  v49 = 0;
                v50 = v49 + v48;
                if ( v50 < *travelTime )
                {
                  *travelTime = v50;
                  bestReachIndex->value = value;
                }
              }
            }
          }
        }
      }
    }
    v27 = this->file;
    value = v27->reachabilities.list[v30].next.value;
  }
  return 1;
}


// ========================================================================
// ?RouteToGoalArea@idAAS2Local@@UBA_NHABVidVec3@@H0HAAHAAV?$idIndex@FW4invalidReachability_t@@@@@Z
// EA  : 0x826B7E50
// RVA : 0x006B7E50
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idAAS2Local::RouteToGoalArea(
        idAAS2Local *this,
        int startAreaNum,
        const idVec3 *startOrigin,
        int goalAreaNum,
        const idVec3 *goalOrigin,
        int travelFlags,
        int *travelTime,
        idIndex<short,enum invalidReachability_t> *reachIndex)
{
  idAAS2File *file; // r11
  int num; // r11
  idAAS2File *v18; // r9
  aas2Area_t *list; // r11
  __int16 cluster; // r3
  int v21; // r30
  int v22; // r4
  idAASRoutingCache *v23; // r3
  int v24; // r8
  __int16 *AreaReachability; // r3
  int v26; // r9
  idAAS2File *v27; // r10
  aas2Reachability_t *v28; // r11
  __int128 v29; // r6 OVERLAPPED
  unsigned __int16 v30; // r3
  int x_low; // r22
  __int16 value; // r19
  aas2Portal_t *v33; // r11
  aas2Area_t *v34; // r11
  __int16 v35; // r8
  int v36; // r4
  int v37; // r26
  idAASRoutingCache *PortalRoutingCache; // r27
  aas2Cluster_t *v39; // r25
  int i; // r24
  idAAS2File *v41; // r10
  int v42; // r11
  int v43; // r29
  aas2Portal_t *v44; // r30
  int maxAreaTravelTime; // r10
  idIndex<short,enum invalidReachability_t> v46[4]; // [sp+50h] [-A0h] BYREF
  idVec3 v47[12]; // [sp+58h] [-98h] BYREF

  *travelTime = 0;
  reachIndex->value = -1;
  file = this->file;
  if ( file == nullptr )
    return 0;
  if ( startAreaNum == goalAreaNum )
  {
    *travelTime = (unsigned __int16)idAAS2Local::CalcTravelTime(
                                      this,
                                      start: startOrigin,
                                      end: goalOrigin,
                                      travelFlags: file->areas.list[startAreaNum].travelFlags);
    return 1;
  }
  if ( startAreaNum <= 0 || (num = file->areas.num, startAreaNum >= num) )
  {
    idLib::Warning(fmt: "RouteToGoalArea: startAreaNum %d out of range.", startAreaNum);
    idLib::Warning(fmt: "Start Origin: X: %0.f, Y: %0.f, Z: %0.f", startOrigin->x, startOrigin->y, startOrigin->z);
    return 0;
  }
  if ( goalAreaNum <= 0 || goalAreaNum >= num )
  {
    idLib::Warning(fmt: "RouteToGoalArea: goalAreaNum %d out of range", goalAreaNum);
    return 0;
  }
  while ( this->totalCacheMemory > 0x200000 )
    idAAS2Local::DeleteOldestCache(this);
  v18 = this->file;
  list = v18->areas.list;
  cluster = list[goalAreaNum].cluster;
  v21 = list[startAreaNum].cluster;
  v22 = cluster;
  if ( v21 >= 0 )
  {
    x_low = 0;
    v47[0].x = 0.0;
    value = -1;
    v46[0].value = -1;
    if ( cluster < 0 )
    {
      v33 = &this->file->portals.list[-cluster];
      if ( v33->clusters[0] == v21 || v33->clusters[1] == v21 )
        v22 = v21;
    }
    if ( v21 > 0 && v22 > 0 && v21 == v22 )
    {
      idAAS2Local::GetClusterRoute(
        this,
        startAreaNum,
        startOrigin,
        startClusterNum: v21,
        goalAreaNum,
        travelFlags,
        travelTime: (int *)v47,
        bestReachIndex: v46);
      x_low = LODWORD(v47[0].x);
      value = v46[0].value;
    }
    v34 = this->file->areas.list;
    v35 = v34[goalAreaNum].cluster;
    v36 = v35;
    v37 = v34[startAreaNum].cluster;
    if ( v35 < 0 )
      v36 = this->file->portals.list[-v35].clusters[0];
    PortalRoutingCache = idAAS2Local::GetPortalRoutingCache(this, clusterNum: v36, areaNum: goalAreaNum, travelFlags);
    v39 = &this->file->clusters.list[v37];
    if ( idAAS2Local::ClusterAreaNum(this, clusterNum: v37, areaNum: startAreaNum) < v39->numReachableAreas )
    {
      for ( i = 0; i < v39->numPortals; ++i )
      {
        v41 = this->file;
        v42 = v41->portalIndex.list[v39->firstPortal + i];
        v43 = v42;
        if ( PortalRoutingCache->travelTimes[v42] != 0 )
        {
          v47[0].x = 0.0;
          v46[0].value = -1;
          v44 = &v41->portals.list[v42];
          if ( (unsigned __int8)idAAS2Local::GetClusterRoute(
                                  this,
                                  startAreaNum,
                                  startOrigin,
                                  startClusterNum: v37,
                                  goalAreaNum: v44->areaNum,
                                  travelFlags,
                                  travelTime: (int *)v47,
                                  bestReachIndex: v46) != 0 )
          {
            maxAreaTravelTime = v44->maxAreaTravelTime;
            if ( x_low == 0 || PortalRoutingCache->travelTimes[v43] + maxAreaTravelTime + LODWORD(v47[0].x) < x_low )
            {
              value = v46[0].value;
              x_low = PortalRoutingCache->travelTimes[v43] + maxAreaTravelTime + LODWORD(v47[0].x);
            }
          }
        }
      }
      if ( value >= 0 )
      {
        reachIndex->value = value;
        *travelTime = x_low;
        return 1;
      }
    }
    return 0;
  }
  if ( cluster < 0 )
    v22 = v18->portals.list[-cluster].clusters[0];
  v23 = idAAS2Local::GetPortalRoutingCache(this, clusterNum: v22, areaNum: goalAreaNum, travelFlags);
  AreaReachability = (__int16 *)idAAS2Local::GetAreaReachability(
                                  this: (idAAS2Local *)v46,
                                  result: (idIndex<short,enum invalidReachability_t> *)this,
                                  areaNum: startAreaNum,
                                  reachabilityNum: v23->reachabilities[-v21]);
  v26 = *AreaReachability;
  reachIndex->value = *AreaReachability;
  v27 = this->file;
  v28 = &v27->reachabilities.list[v26];
  DWORD1(v29) = (unsigned __int16)v28->start[2];
  LODWORD(v29) = SWORD3(v29);
  DWORD2(v29) = v28->start[1];
  HIDWORD(v29) = v28->start[0];
  v47[0].z = (float)(__int64)v29;
  v47[0].y = (float)*(__int64 *)((char *)&v29 + 4);
  v47[0].x = (float)*(__int64 *)((char *)&v29 + 12);
  if ( v27 != nullptr )
    v30 = idAAS2Local::CalcTravelTime(
            this,
            start: startOrigin,
            end: v47,
            travelFlags: v27->areas.list[startAreaNum].travelFlags);
  else
    v30 = 0;
  *travelTime = *(unsigned __int16 *)(*(_DWORD *)(v24 + 44) - 2 * v21) + v30;
  return 1;
}


// ========================================================================
// `dynamic initializer for 'aas_showCacheMisses''
// EA  : 0x8333E518
// RVA : 0x0133E518
// PDB : w:\tech5\engine\gamelib\aas2\aas2_routing.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aas_showCacheMisses__()
{
  idCVar::idCVar(
    this: &aas_showCacheMisses,
    name: "aas_showCacheMisses",
    value: "0",
    flags: 1,
    description: "show cache misses and time to cache",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aas_showCacheMisses__);
}

