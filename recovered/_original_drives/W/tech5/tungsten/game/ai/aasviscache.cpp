
// ========================================================================
// ?Init@idAASVisCache@@QAAXPBVidAAS2@@HM@Z
// EA  : 0x829EE968
// RVA : 0x009EE968
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void __fastcall idAASVisCache::Init(idAASVisCache *this, const idAAS2 *aas, int subDivisionSize, double eyeHeight)
{
  this->eyeHeight = eyeHeight;
  this->aas = aas;
  this->subDivisionSize = subDivisionSize;
}


// ========================================================================
// ?FindVisPoint@idAASVisCache@@AAAPAVidAASVisPoint@@ABVidVec3@@@Z
// EA  : 0x829EE978
// RVA : 0x009EE978
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

idAASVisPoint *__fastcall idAASVisCache::FindVisPoint(idAASVisCache *this, const idVec3 *eyePoint)
{
  int num; // r7
  int v3; // r9
  idAASVisPoint **list; // r8
  int i; // r10
  float *p_x; // r11
  double v7; // fp13
  char v8; // r11

  num = this->visPoints.num;
  v3 = 0;
  if ( num <= 0 )
    return nullptr;
  list = this->visPoints.list;
  for ( i = 0; ; ++i )
  {
    p_x = &list[i]->eyePoint.x;
    if ( *p_x != eyePoint->x || p_x[1] != eyePoint->y || (v7 = p_x[2], v8 = 1, v7 != eyePoint->z) )
      v8 = 0;
    if ( v8 != 0 )
      break;
    if ( ++v3 >= num )
      return nullptr;
  }
  return list[v3];
}


// ========================================================================
// ?FindOldest@idAASVisCache@@ABAHXZ
// EA  : 0x829EEA00
// RVA : 0x009EEA00
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

int __fastcall idAASVisCache::FindOldest(idAASVisCache *this)
{
  int num; // r11
  int result; // r3
  idAASVisPoint **list; // r7
  int v4; // r9
  int cacheTime; // r10
  int v6; // r8
  int v7; // ctr

  num = this->visPoints.num;
  if ( num == 0 )
    return -1;
  list = this->visPoints.list;
  result = 0;
  v4 = 1;
  cacheTime = (*list)->cacheTime;
  if ( num > 1 )
  {
    v6 = 1;
    v7 = num - 1;
    do
    {
      if ( list[v6]->cacheTime < cacheTime )
      {
        result = v4;
        cacheTime = list[v6]->cacheTime;
      }
      ++v4;
      ++v6;
      --v7;
    }
    while ( v7 != 0 );
  }
  return result;
}


// ========================================================================
// ?GetNumCachedAreas@idAASVisCache@@QBAHXZ
// EA  : 0x829EEA68
// RVA : 0x009EEA68
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

int __fastcall idAASVisCache::GetNumCachedAreas(idAASVisCache *this)
{
  int num; // r4
  int v2; // r9
  int v3; // r8
  int v4; // r10
  idAASVisPoint **list; // r7
  int v6; // r11
  idAASVisPoint *v7; // r30
  idAASVisPoint *v8; // r29

  num = this->visPoints.num;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  if ( num >= 2 )
  {
    list = this->visPoints.list;
    v6 = 0;
    do
    {
      v7 = list[v6];
      v4 += 2;
      v8 = list[v6 + 1];
      v6 += 2;
      v2 += v7->visAreas.num;
      v3 += v8->visAreas.num;
    }
    while ( v4 < num - 1 );
  }
  if ( v4 >= num )
    return v3 + v2;
  else
    return v3 + v2 + this->visPoints.list[v4]->visAreas.num;
}


// ========================================================================
// ?IsPointVisible@idAASVisArea@@QAA_NPBVidAASVisCache@@PBVidAASVisPoint@@ABVidVec3@@@Z
// EA  : 0x829EEAF0
// RVA : 0x009EEAF0
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

BOOL __fastcall idAASVisArea::IsPointVisible(
        idAASVisArea *this,
        const idAASVisCache *visCache,
        const idAASVisPoint *visPoint,
        const idVec3 *testPoint)
{
  int v6; // [sp+50h] [-20h] BYREF
  _DWORD v7[3]; // [sp+54h] [-1Ch] BYREF

  if ( this->areaNum <= 0 || this->cellVis.bits == 0 )
    return false;
  visCache->aas->WorldPosToCellPos(
    this: (idAAS2 *)visCache->aas,
    a2: this->areaNum,
    a3: visCache->subDivisionSize,
    a4: testPoint,
    a5: &v6,
    a6: v7);
  return idBitArray::Get(this: &this->cellVis, bitNum: this->xcells * v7[0] + v6);
}


// ========================================================================
// ??0idAASVisPoint@@QAA@ABVidVec3@@H@Z
// EA  : 0x829EEB88
// RVA : 0x009EEB88
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

idAASVisPoint *__fastcall idAASVisPoint::idAASVisPoint(idAASVisPoint *this, const idVec3 *eyePoint, int time)
{
  this->eyePoint = *eyePoint;
  this->visAreas.list = nullptr;
  this->visAreas.granularity = 0;
  this->visAreas.memTag = 5;
  this->visAreas.listStatic = 0;
  this->visAreas.size = 0;
  this->visAreas.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->visAreas);
  this->cacheTime = time;
  return this;
}


// ========================================================================
// ?Free@idAASVisPoint@@AAAXXZ
// EA  : 0x829EEC08
// RVA : 0x009EEC08
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void __fastcall idAASVisPoint::Free(idAASVisPoint *this)
{
  int v2; // r25
  int v3; // r29
  idAASVisArea *v4; // r30
  unsigned __int8 *buffer; // r4

  v2 = 0;
  if ( this->visAreas.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->visAreas.list[v3];
      if ( v4 != nullptr )
      {
        buffer = v4->cellVis.buffer;
        if ( buffer != nullptr && v4->cellVis.free )
        {
          idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
          v4->cellVis.buffer = nullptr;
          v4->cellVis.bits = 0;
          v4->cellVis.free = false;
        }
        idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->visAreas.num );
  }
}


// ========================================================================
// ??0idAASVisCache@@QAA@XZ
// EA  : 0x829EECA8
// RVA : 0x009EECA8
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

idAASVisCache *__fastcall idAASVisCache::idAASVisCache(idAASVisCache *this)
{
  this->aas = nullptr;
  this->eyeHeight = 0.0;
  this->subDivisionSize = 0;
  this->visPoints.list = nullptr;
  this->visPoints.granularity = 0;
  this->visPoints.memTag = 93;
  this->visPoints.listStatic = 0;
  this->visPoints.size = 0;
  this->visPoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->visPoints);
  return this;
}


// ========================================================================
// ?Size@idAASVisCache@@QBAIXZ
// EA  : 0x829EED10
// RVA : 0x009EED10
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

unsigned int __fastcall idAASVisCache::Size(idAASVisCache *this)
{
  int num; // r10
  unsigned int result; // r3
  idAASVisPoint **list; // r7
  int i; // r6
  int v6; // r9
  int v7; // r11
  int v8; // ctr
  unsigned int bits; // r5
  unsigned int v10; // r10

  num = this->visPoints.num;
  result = 28;
  if ( num > 0 )
  {
    list = this->visPoints.list;
    for ( i = num; i != 0; --i )
    {
      v6 = 32;
      if ( (*list)->visAreas.num > 0 )
      {
        v7 = 0;
        v8 = (*list)->visAreas.num;
        do
        {
          bits = (*list)->visAreas.list[v7]->cellVis.bits;
          v10 = bits >> 3;
          if ( (bits & 7) != 0 )
            ++v10;
          ++v7;
          v6 += v10 + 40;
          --v8;
        }
        while ( v8 != 0 );
      }
      result += v6;
      ++list;
    }
  }
  return result;
}


// ========================================================================
// ?Cmd_VisCacheInfo_f@idAASVisCache@@SAXABVidCmdArgs@@@Z
// EA  : 0x829EED90
// RVA : 0x009EED90
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void __fastcall idAASVisCache::Cmd_VisCacheInfo_f(const idCmdArgs *args)
{
  idAASVisCache *p_aasVisCache; // r31
  unsigned int v2; // r3
  int NumCachedAreas; // r3

  p_aasVisCache = &gameLocal->aasVisCache;
  idLib::Printf(fmt: "AAS Visibility Cache info:\n");
  idLib::Printf(fmt: "  eyeHeight: %.2f\n", p_aasVisCache->eyeHeight);
  v2 = idAASVisCache::Size(this: p_aasVisCache);
  idLib::Printf(fmt: "  bytes: %d\n", v2);
  idLib::Printf(fmt: "  cached points: %d\n", p_aasVisCache->visPoints.num);
  NumCachedAreas = idAASVisCache::GetNumCachedAreas(this: p_aasVisCache);
  idLib::Printf(fmt: "  cached areas: %d\n", NumCachedAreas);
}


// ========================================================================
// ??1idAASVisPoint@@QAA@XZ
// EA  : 0x829EEE30
// RVA : 0x009EEE30
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void __fastcall idAASVisPoint::~idAASVisPoint(idAASVisPoint *this)
{
  idAASVisPoint::Free(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->visAreas);
}


// ========================================================================
// __unwind$488982
// EA  : 0x829EEE74
// RVA : 0x009EEE74
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void _unwind_488982()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 12));
}


// ========================================================================
// ?RemoveOldest@idAASVisCache@@AAAXXZ
// EA  : 0x829EEEA0
// RVA : 0x009EEEA0
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void __fastcall idAASVisCache::RemoveOldest(idAASVisCache *this)
{
  int v1; // r6
  int Oldest; // r3
  int v3; // r30
  int v4; // r11
  int v5; // r28
  _DWORD *v6; // r31
  void *v7; // r29
  int v8; // r11
  int v9; // r11

  Oldest = idAASVisCache::FindOldest(this);
  v3 = Oldest;
  if ( Oldest >= 0 )
  {
    v4 = *(_DWORD *)(v1 + 12);
    v5 = 4 * Oldest;
    v6 = (_DWORD *)(v1 + 12);
    v7 = *(void **)(v4 + 4 * Oldest);
    if ( v7 != nullptr )
    {
      idAASVisPoint::~idAASVisPoint(this: *(idAASVisPoint **)(v4 + 4 * Oldest));
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    }
    v8 = v6[1];
    if ( v3 < v8 )
    {
      v9 = v8 - 1;
      v6[1] = v9;
      if ( v3 != v9 )
        *(_DWORD *)(*v6 + v5) = *(_DWORD *)(4 * v9 + *v6);
    }
    idLib::Printf(fmt: "idAASVisCache::RemoveOldest - removed index %d\n", v3);
  }
}


// ========================================================================
// ?AddVisArea@idAASVisPoint@@AAAPAVidAASVisArea@@H@Z
// EA  : 0x829EEF38
// RVA : 0x009EEF38
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

idAASVisArea *__fastcall idAASVisPoint::AddVisArea(idAASVisPoint *this, int areaNum)
{
  float *v4; // r3
  int v5; // r5
  float v6; // r29
  int v8; // r10
  int v9; // r11
  idVec1 v10; // [sp+50h] [-30h] BYREF

  v4 = (float *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                  size: 0x1Cu,
                  tag: TAG_AI_VISCACHE,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  v5 = 0;
  if ( v4 != nullptr )
  {
    *v4 = 0.0;
    v4[1] = 0.0;
    v4[2] = 0.0;
    v6 = *(float *)&v4;
    v4[3] = 0.0;
    v4[4] = 0.0;
    v4[5] = 0.0;
    *((_WORD *)v4 + 12) = 93;
    *((_BYTE *)v4 + 26) = 0;
  }
  else
  {
    v6 = 0.0;
  }
  v10.x = v6;
  if ( v6 == 0.0 )
  {
    idLib::Warning(fmt: "idAASVisPoint::AddVisArea - failed to allocate idAASVisArea");
    return nullptr;
  }
  else
  {
    v8 = this->visAreas.num - 1;
    if ( v8 > 0 )
    {
      do
      {
        v9 = (v8 + v5) >> 1;
        if ( this->visAreas.list[v9]->areaNum >= areaNum )
          v8 = (v8 + v5) >> 1;
        else
          v5 = v9 + 1;
      }
      while ( v5 < v8 );
    }
    idList<idVec1,116>::Insert(this: (idList<idVec1,116> *)&this->visAreas, obj: &v10, index: v5);
    return (idAASVisArea *)LODWORD(v6);
  }
}


// ========================================================================
// ?Free@idAASVisCache@@AAAXXZ
// EA  : 0x829EF040
// RVA : 0x009EF040
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void __fastcall idAASVisCache::Free(idAASVisCache *this)
{
  int v2; // r27
  int v3; // r28
  idAASVisArea **list; // r4
  idAASVisPoint **v5; // r4
  idAASVisPoint *v6; // [sp+50h] [-50h]

  v2 = 0;
  if ( this->visPoints.num > 0 )
  {
    v3 = 0;
    do
    {
      v6 = this->visPoints.list[v3];
      if ( v6 != nullptr )
      {
        idAASVisPoint::Free(this: v6);
        if ( v6->visAreas.listStatic == 0 || v6->visAreas.listStatic == 2 )
        {
          list = v6->visAreas.list;
          if ( list != nullptr )
            idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
          v6->visAreas.list = nullptr;
          v6->visAreas.size = 0;
        }
        v6->visAreas.num = 0;
        idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->visPoints.num );
  }
  if ( this->visPoints.listStatic == 0 || this->visPoints.listStatic == 2 )
  {
    v5 = this->visPoints.list;
    if ( v5 != nullptr )
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    this->visPoints.list = nullptr;
    this->visPoints.size = 0;
  }
  this->visPoints.num = 0;
}


// ========================================================================
// __unwind$489117
// EA  : 0x829EF134
// RVA : 0x009EF134
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void _unwind_489117()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 80) + 12));
}


// ========================================================================
// ?Shutdown@idAASVisCache@@QAAXXZ
// EA  : 0x829EF160
// RVA : 0x009EF160
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void __fastcall idAASVisCache::Shutdown(idAASVisCache *this)
{
  this->aas = nullptr;
  idAASVisCache::Free(this);
}


// ========================================================================
// ?AddVisPoint@idAASVisCache@@AAAPAVidAASVisPoint@@ABVidVec3@@@Z
// EA  : 0x829EF178
// RVA : 0x009EF178
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

idAASVisPoint *__fastcall idAASVisCache::AddVisPoint(idAASVisCache *this, const idVec3 *eyePoint)
{
  unsigned int v4; // r30
  idAASVisPoint *v5; // r30
  int GameMs; // r3
  idAASVisPoint *v7; // r30
  idAASVisPoint *v9; // [sp+50h] [-30h] BYREF

  v4 = idAASVisCache::Size(this);
  if ( v4 > 0x7D000 )
  {
    idAASVisCache::RemoveOldest(this);
    idLib::Printf(fmt: "AddVisPoint - num %d, size = %d\n", this->visPoints.num, v4);
  }
  v5 = (idAASVisPoint *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x20u,
                          tag: TAG_AI_VISCACHE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  v9 = v5;
  if ( v5 != nullptr )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v7 = idAASVisPoint::idAASVisPoint(this: v5, eyePoint, time: GameMs);
  }
  else
  {
    v7 = nullptr;
  }
  v9 = v7;
  if ( v7 != nullptr )
  {
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->visPoints,
      obj: (const encounterGroupRole_t *)&v9);
    return v7;
  }
  else
  {
    idLib::Warning(fmt: "idAASVisCache::AddVisPoint - Failed to allocate idAASVisPoint");
    return nullptr;
  }
}


// ========================================================================
// __unwind$489244
// EA  : 0x829EF268
// RVA : 0x009EF268
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void _unwind_489244()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_AI_VISCACHE);
}


// ========================================================================
// ?CacheVisibilities@idAASVisArea@@QAAXPBVidAASVisCache@@PBVidAASVisPoint@@H@Z
// EA  : 0x829EF2A0
// RVA : 0x009EF2A0
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void __fastcall idAASVisArea::CacheVisibilities(
        idAASVisArea *this,
        const idAASVisCache *visCache,
        const idAASVisPoint *visPoint,
        int areaNum)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  const idAAS2 *aas; // r27
  idBitArray *p_cellVis; // r26
  int *p_ycells; // r16
  int *p_xcells; // r20
  int subDivisionSize; // r25
  _BYTE v15[12]; // r11
  bool v16; // cr57
  int v17; // r14
  int v18; // r28
  int v19; // r30
  double v20; // fp31
  double v21; // fp8
  unsigned int v22; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v24; // r30
  int v25; // r3
  __int64 totalTicks; // r11
  __int64 v27; // r9
  int v28; // [sp+8h] [-1D8h]
  bool v29; // [sp+Fh] [-1D1h]
  const char *v30; // [sp+10h] [-1D0h]
  int v31; // [sp+14h] [-1CCh]
  int v32; // [sp+18h] [-1C8h]
  int v33; // [sp+1Ch] [-1C4h]
  int v34; // [sp+20h] [-1C0h]
  int v35; // [sp+24h] [-1BCh]
  int v36; // [sp+28h] [-1B8h]
  int v37; // [sp+2Ch] [-1B4h]
  int v38; // [sp+30h] [-1B0h]
  int v39; // [sp+34h] [-1ACh]
  int v40; // [sp+38h] [-1A8h]
  int v41; // [sp+3Ch] [-1A4h]
  int v42; // [sp+40h] [-1A0h]
  int v43; // [sp+44h] [-19Ch]
  int v44; // [sp+48h] [-198h]
  int v45; // [sp+4Ch] [-194h]
  int v46; // [sp+50h] [-190h]
  int v47; // [sp+58h] [-188h]
  int v48; // [sp+60h] [-180h]
  idVec3 v49; // [sp+70h] [-170h] BYREF
  idPLogScope v50; // [sp+80h] [-160h] BYREF
  __int64 v51; // [sp+88h] [-158h]
  __int64 v52; // [sp+90h] [-150h] BYREF
  trace_t v53; // [sp+A0h] [-140h] BYREF

  RD_EventBegin(name: "idAASVisArea::CacheVisibilities");
  LODWORD(v8) = "idAASVisArea::CacheVisibilities";
  HIDWORD(v8) = 6;
  idPLogScope::idPLogScope(this: &v50, pl: &::pLog, gMask: v8, label: v9);
  aas = visCache->aas;
  if ( visCache->aas != nullptr )
  {
    p_cellVis = &this->cellVis;
    idBitArray::~idBitArray(this: &this->cellVis);
    p_ycells = &this->ycells;
    p_xcells = &this->xcells;
    subDivisionSize = visCache->subDivisionSize;
    if ( aas->GetAreaCells(this: (idAAS2 *)aas, a2: areaNum, a3: subDivisionSize, a4: &this->xcells, a5: &this->ycells) )
    {
      idBitArray::Alloc(this: &this->cellVis, numBits: *p_xcells * *p_ycells);
      *(_DWORD *)v15 = 0x82000000;
      v16 = *p_ycells > 0;
      v17 = 0;
      v18 = 0;
      this->visRatio = 0.0;
      if ( v16 )
      {
        *(_DWORD *)&v15[4] = 0x82000000;
        *(_DWORD *)v15 = 0x82000000;
        do
        {
          v19 = 0;
          if ( *p_xcells > 0 )
          {
            *(_DWORD *)&v15[8] = subDivisionSize;
            v51 = *(_QWORD *)&v15[4];
            v20 = (float)((float)*(__int64 *)&v15[4] * (float)0.5);
            do
            {
              aas->CellPosToWorldPos(
                this: (idAAS2 *)aas,
                a2: areaNum,
                a3: subDivisionSize,
                a4: v19,
                a5: v18,
                a6: &v49,
                a7: true);
              v21 = (float)(visCache->eyeHeight + v49.z);
              v49.x = (float)v20 + v49.x;
              v49.y = (float)v20 + v49.y;
              v49.z = v21;
              idClip::Translation(
                this: (idClip *)&v52,
                result: &clientGame->clip,
                a3: &v53,
                start: &visPoint->eyePoint,
                end: &v49,
                clipModel: nullptr,
                startAxis: &mat3_identity,
                clipMask: 3,
                passEntityNumber: v28,
                moveClipModel: v29,
                userName: v30,
                a12: v31,
                a13: v32,
                a14: v33,
                a15: v34,
                a16: v35,
                a17: v36,
                a18: v37,
                a19: v38,
                a20: v39,
                a21: v40,
                a22: v41,
                a23: v42,
                a24: v43,
                a25: v44,
                a26: v45,
                a27: v46,
                a28: 0x1FFF,
                a29: v47,
                a30: false,
                a31: v48,
                a32: 0);
              if ( v53.fraction == 1.0 )
              {
                v22 = *p_xcells * v18 + v19;
                if ( v22 >= this->cellVis.bits )
                {
                  *(_DWORD *)&v15[8] = 0;
                  *(_DWORD *)&v15[4] = 0;
                  v15[3] = 0;
                }
                else
                {
                  *(_DWORD *)&v15[4] = (unsigned __int8)(1 << (v22 & 7));
                  *(_DWORD *)&v15[8] = &p_cellVis->buffer[v22 >> 3];
                  v15[3] = 1;
                }
                *(_DWORD *)v15 = v15[3];
                if ( v15[3] != 0 )
                {
                  *(_DWORD *)v15 = (unsigned __int8)**(_BYTE **)&v15[8];
                  **(_BYTE **)&v15[8] = v15[3] | v15[7];
                }
                ++v17;
              }
              ++v19;
            }
            while ( v19 < *p_xcells );
          }
          ++v18;
        }
        while ( v18 < *p_ycells );
      }
      *(_DWORD *)&v15[8] = *p_xcells * *p_ycells;
      if ( *(int *)&v15[8] > 0 )
      {
        *(_DWORD *)&v15[4] = v17;
        v51 = *(_QWORD *)v15;
        v52 = *(_QWORD *)&v15[4];
        this->visRatio = (float)*(__int64 *)v15 / (float)*(__int64 *)&v15[4];
      }
      if ( v17 == 0 && p_cellVis->buffer != nullptr && this->cellVis.free )
      {
        idMem::Free(this: &mem, ptr: p_cellVis->buffer, align: ALIGN_16);
        p_cellVis->buffer = nullptr;
        this->cellVis.bits = 0;
        this->cellVis.free = false;
      }
      this->areaNum = areaNum;
      if ( v50.logIndex >= 0 )
      {
        pLog = v50.pLog;
        v24 = &v50.pLog->logEntries.list[v50.logIndex];
        v25 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        totalTicks = v24->totalTicks;
        HIDWORD(totalTicks) = v24->parent;
        LODWORD(v27) = v25 - totalTicks;
        v24->totalTicks = v27;
        pLog->lastEntry = HIDWORD(totalTicks);
      }
    }
    else
    {
      this->areaNum = areaNum;
      idPLogScope::~idPLogScope(this: &v50);
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v50);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$489287
// EA  : 0x829EF5CC
// RVA : 0x009EF5CC
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void _unwind_489287()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 480 + 288));
}


// ========================================================================
// __unwind$489288
// EA  : 0x829EF5F4
// RVA : 0x009EF5F4
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void _unwind_489288()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 480 + 128));
}


// ========================================================================
// ?GetVisArea@idAASVisPoint@@AAAPAVidAASVisArea@@H@Z
// EA  : 0x829EF628
// RVA : 0x009EF628
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

idAASVisArea *__fastcall idAASVisPoint::GetVisArea(idAASVisPoint *this, int areaNum)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  int v6; // r9
  int v7; // r10
  int v8; // r11
  idAASVisArea *v9; // r30
  idPLogScope v11[7]; // [sp+58h] [-38h] BYREF

  RD_EventBegin(name: "idAASVisPoint::GetVisArea");
  LODWORD(v4) = "idAASVisPoint::GetVisArea";
  HIDWORD(v4) = 6;
  idPLogScope::idPLogScope(this: v11, pl: &pLog, gMask: v4, label: v5);
  v6 = 0;
  v7 = this->visAreas.num - 1;
  if ( v7 > 0 )
  {
    do
    {
      v8 = (v7 + v6) >> 1;
      if ( this->visAreas.list[v8]->areaNum >= areaNum )
        v7 = (v7 + v6) >> 1;
      else
        v6 = v8 + 1;
    }
    while ( v6 < v7 );
  }
  if ( v6 == v7 && (v9 = this->visAreas.list[v6])->areaNum == areaNum )
  {
    idPLogScope::~idPLogScope(this: v11);
    RD_EventEnd();
    return v9;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v11);
    RD_EventEnd();
    return nullptr;
  }
}


// ========================================================================
// __unwind$489409
// EA  : 0x829EF700
// RVA : 0x009EF700
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void _unwind_489409()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 96));
}


// ========================================================================
// __unwind$489410
// EA  : 0x829EF728
// RVA : 0x009EF728
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void _unwind_489410()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 88));
}


// ========================================================================
// ??1idAASVisCache@@QAA@XZ
// EA  : 0x829EF758
// RVA : 0x009EF758
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void __fastcall idAASVisCache::~idAASVisCache(idAASVisCache *this)
{
  idAASVisCache::Free(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->visPoints);
}


// ========================================================================
// __unwind$489467
// EA  : 0x829EF79C
// RVA : 0x009EF79C
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void _unwind_489467()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 12));
}


// ========================================================================
// ?IsPointVisible@idAASVisPoint@@QAA_NPBVidAASVisCache@@ABVidVec3@@H@Z
// EA  : 0x829EF7C8
// RVA : 0x009EF7C8
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

BOOL __fastcall idAASVisPoint::IsPointVisible(
        idAASVisPoint *this,
        const idAASVisCache *visCache,
        const idVec3 *testPoint,
        int testPointAreaNum)
{
  const idAAS2 *aas; // r3
  float y; // r9
  float z; // r8
  idAASVisArea *VisArea; // r31
  idAASVisArea *v12; // r3
  idVec3 v13[5]; // [sp+50h] [-40h] BYREF

  aas = visCache->aas;
  if ( visCache->aas == nullptr )
    return false;
  y = testPoint->y;
  z = testPoint->z;
  v13[0].x = testPoint->x;
  v13[0].y = y;
  v13[0].z = z;
  aas->PushPointIntoAreaNum(this: (idAAS2 *)aas, a2: testPointAreaNum, a3: v13);
  VisArea = idAASVisPoint::GetVisArea(this, areaNum: testPointAreaNum);
  if ( VisArea == nullptr )
  {
    v12 = idAASVisPoint::AddVisArea(this, areaNum: testPointAreaNum);
    VisArea = v12;
    if ( v12 == nullptr )
      return false;
    idAASVisArea::CacheVisibilities(this: v12, visCache, visPoint: this, areaNum: testPointAreaNum);
  }
  return idAASVisArea::IsPointVisible(this: VisArea, visCache, visPoint: this, testPoint: v13);
}


// ========================================================================
// ?VisibilityRatio@idAASVisPoint@@QAAMPBVidAASVisCache@@H@Z
// EA  : 0x829EF888
// RVA : 0x009EF888
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

float __fastcall idAASVisPoint::VisibilityRatio(idAASVisPoint *this, const idAASVisCache *visCache, int areaNum)
{
  double visRatio; // fp1
  idAASVisArea *VisArea; // r31
  idAASVisArea *v8; // r3

  if ( visCache->aas != nullptr )
  {
    VisArea = idAASVisPoint::GetVisArea(this, areaNum);
    if ( VisArea == nullptr )
    {
      v8 = idAASVisPoint::AddVisArea(this, areaNum);
      VisArea = v8;
      if ( v8 == nullptr )
        goto LABEL_2;
      idAASVisArea::CacheVisibilities(this: v8, visCache, visPoint: this, areaNum);
    }
    if ( areaNum > 0 && VisArea->cellVis.bits != 0 )
    {
      visRatio = VisArea->visRatio;
      return *((float *)&visRatio + 1);
    }
  }
LABEL_2:
  visRatio = 0.0;
  return *((float *)&visRatio + 1);
}


// ========================================================================
// ?IsPointVisible@idAASVisCache@@QAA_NABVidVec3@@0PBVidAAS2@@H@Z
// EA  : 0x829EF928
// RVA : 0x009EF928
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

int __fastcall idAASVisCache::IsPointVisible(
        idAASVisCache *this,
        const idVec3 *eyePoint,
        const idVec3 *destPoint,
        const idAAS2 *aas,
        int destAreaNum)
{
  unsigned __int64 v10; // r6
  const char *v11; // r7
  const idVec3 *v12; // r4
  idAASVisPoint *VisPoint; // r3
  BOOL IsPointVisible; // r30
  idPLogScope v16[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idAASVisCace::IsPointVisible()");
  LODWORD(v10) = "idAASVisCace::IsPointVisible()";
  HIDWORD(v10) = 6;
  idPLogScope::idPLogScope(this: v16, pl: &pLog, gMask: v10, label: v11);
  if ( aas != nullptr
    && this->aas == aas
    && ((VisPoint = idAASVisCache::FindVisPoint(this, eyePoint)) != nullptr
     || (VisPoint = idAASVisCache::AddVisPoint(this, eyePoint: v12)) != nullptr) )
  {
    IsPointVisible = idAASVisPoint::IsPointVisible(
                       this: VisPoint,
                       visCache: this,
                       testPoint: destPoint,
                       testPointAreaNum: destAreaNum);
    idPLogScope::~idPLogScope(this: v16);
    RD_EventEnd();
    return IsPointVisible;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v16);
    RD_EventEnd();
    return 1;
  }
}


// ========================================================================
// __unwind$489530
// EA  : 0x829EFA14
// RVA : 0x009EFA14
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void _unwind_489530()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$489531
// EA  : 0x829EFA3C
// RVA : 0x009EFA3C
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void _unwind_489531()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?VisibilityRatio@idAASVisCache@@QAAMABVidVec3@@PBVidAAS2@@H@Z
// EA  : 0x829EFA70
// RVA : 0x009EFA70
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

float __fastcall idAASVisCache::VisibilityRatio(
        idAASVisCache *this,
        const idVec3 *eyePoint,
        const idAAS2 *aas,
        int areaNum)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  const idVec3 *v10; // r4
  idAASVisPoint *VisPoint; // r3
  double v12; // fp1
  double v13; // fp31
  idPLogScope v15[2]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "VisibilityRatio(2)");
  LODWORD(v8) = "VisibilityRatio(2)";
  HIDWORD(v8) = 6;
  idPLogScope::idPLogScope(this: v15, pl: &pLog, gMask: v8, label: v9);
  if ( aas != nullptr
    && this->aas == aas
    && ((VisPoint = idAASVisCache::FindVisPoint(this, eyePoint)) != nullptr
     || (VisPoint = idAASVisCache::AddVisPoint(this, eyePoint: v10)) != nullptr) )
  {
    v13 = idAASVisPoint::VisibilityRatio(this: VisPoint, visCache: this, areaNum);
    idPLogScope::~idPLogScope(this: v15);
    RD_EventEnd();
    v12 = v13;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v15);
    RD_EventEnd();
    v12 = 0.0;
  }
  return *((float *)&v12 + 1);
}


// ========================================================================
// __unwind$489658
// EA  : 0x829EFB68
// RVA : 0x009EFB68
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void _unwind_489658()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$489659
// EA  : 0x829EFB90
// RVA : 0x009EFB90
// PDB : w:\tech5\tungsten\game\ai\aasviscache.cpp
// ========================================================================

void _unwind_489659()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}

