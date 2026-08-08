
// ========================================================================
// ?FreeTraceModel@idTraceModelCache@@QAAXH@Z
// EA  : 0x82768788
// RVA : 0x00768788
// PDB : w:\tech5\engine\gamelib\physics\tracemodelcache.cpp
// ========================================================================

void __fastcall idTraceModelCache::FreeTraceModel(idTraceModelCache *this, int traceModelIndex)
{
  idTraceModelCache::trmCache_t *v2; // r11
  int refCount; // r9

  if ( traceModelIndex < 0
    || traceModelIndex >= this->cache.num
    || (v2 = this->cache.list[traceModelIndex], (refCount = v2->refCount) <= 0) )
  {
    idLib::Warning(fmt: "idClipModel::FreeTraceModel: tried to free uncached trace model");
  }
  else
  {
    v2->refCount = refCount - 1;
  }
}


// ========================================================================
// ?CopyTraceModel@idTraceModelCache@@QAAHH@Z
// EA  : 0x827687D0
// RVA : 0x007687D0
// PDB : w:\tech5\engine\gamelib\physics\tracemodelcache.cpp
// ========================================================================

int __fastcall idTraceModelCache::CopyTraceModel(idTraceModelCache *this, int traceModelIndex)
{
  idTraceModelCache::trmCache_t *v2; // r11
  int refCount; // r9

  if ( traceModelIndex < 0
    || traceModelIndex >= this->cache.num
    || (v2 = this->cache.list[traceModelIndex], (refCount = v2->refCount) <= 0) )
  {
    idLib::Warning(fmt: "idClipModel::CopyTraceModel: tried to copy an uncached trace model");
    return -1;
  }
  else
  {
    v2->refCount = refCount + 1;
    return traceModelIndex;
  }
}


// ========================================================================
// ?GetMassProperties@idTraceModelCache@@QBAXHMAAMAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82768848
// RVA : 0x00768848
// PDB : w:\tech5\engine\gamelib\physics\tracemodelcache.cpp
// ========================================================================

void __fastcall idTraceModelCache::GetMassProperties(
        idTraceModelCache *this,
        const int traceModelIndex,
        double density,
        float *mass,
        idVec3 *centerOfMass,
        idMat3 *inertiaTensor,
        float *a7)
{
  float *v7; // r9
  double v8; // fp9
  double v9; // fp8
  double v10; // fp7
  double v11; // fp6
  double v12; // fp5
  double v13; // fp4
  double v14; // fp3
  double v15; // fp2

  v7 = (float *)this->cache.list[traceModelIndex];
  centerOfMass->x = v7[2] * (float)density;
  inertiaTensor->mat[0].x = v7[3];
  inertiaTensor->mat[0].y = v7[4];
  inertiaTensor->mat[0].z = v7[5];
  v8 = v7[9];
  v9 = v7[8];
  v10 = v7[7];
  v11 = v7[10];
  v12 = v7[11];
  v13 = v7[12];
  v14 = v7[13];
  v15 = v7[14];
  *a7 = v7[6] * (float)density;
  a7[3] = (float)v8 * (float)density;
  a7[1] = (float)v10 * (float)density;
  a7[2] = (float)v9 * (float)density;
  a7[4] = (float)v11 * (float)density;
  a7[5] = (float)v12 * (float)density;
  a7[6] = (float)v13 * (float)density;
  a7[7] = (float)v14 * (float)density;
  a7[8] = (float)v15 * (float)density;
}


// ========================================================================
// ?ClearTraceModelCache@idTraceModelCache@@QAAXXZ
// EA  : 0x827688E8
// RVA : 0x007688E8
// PDB : w:\tech5\engine\gamelib\physics\tracemodelcache.cpp
// ========================================================================

void __fastcall idTraceModelCache::ClearTraceModelCache(idTraceModelCache *this)
{
  int v2; // r27
  int v3; // r30
  idCollisionModel *collisionModel; // r3
  idTraceModelCache::trmCache_t *v5; // r29
  traceModelWater_t *list; // r4
  idTraceModelCache::trmCache_t *v7; // r11
  idTraceModelCache::trmCache_t **v8; // r4

  v2 = 0;
  if ( this->cache.num > 0 )
  {
    v3 = 0;
    do
    {
      collisionModel = this->cache.list[v3]->collisionModel;
      if ( collisionModel != nullptr )
      {
        ((void (__fastcall *)(idCollisionModel *, int))collisionModel->dtr_idResource)(a1: collisionModel, a2: 1);
        this->cache.list[v3]->collisionModel = nullptr;
      }
      v5 = this->cache.list[v3];
      if ( v5->waterPoints.listStatic == 0 || v5->waterPoints.listStatic == 2 )
      {
        list = v5->waterPoints.list;
        if ( list != nullptr )
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        v5->waterPoints.list = nullptr;
        v5->waterPoints.size = 0;
      }
      v5->waterPoints.num = 0;
      v7 = this->cache.list[v3];
      if ( v7->trm != nullptr )
      {
        idTraceModel::operator delete(p: v7->trm);
        this->cache.list[v3]->trm = nullptr;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->cache.num );
  }
  idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::Shutdown(this: &this->cacheAllocator);
  if ( this->cache.listStatic == 0 || this->cache.listStatic == 2 )
  {
    v8 = this->cache.list;
    if ( v8 != nullptr )
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    this->cache.list = nullptr;
    this->cache.size = 0;
  }
  this->cache.num = 0;
  idHashIndex::Free(this: &this->hash);
}


// ========================================================================
// ?SetupWaterPoints@idTraceModelCache@@AAAXPAUtrmCache_t@1@@Z
// EA  : 0x82768F18
// RVA : 0x00768F18
// PDB : w:\tech5\engine\gamelib\physics\tracemodelcache.cpp
// ========================================================================

void __fastcall idTraceModelCache::SetupWaterPoints(idTraceModelCache *this, idTraceModelCache::trmCache_t *entry)
{
  float *vertsX; // r11
  long double v4; // fp4
  __int64 v5; // r9
  signed int numVerts; // r29
  int v7; // r26
  double v8; // fp22
  double v9; // fp20
  long double v10; // fp2
  int v11; // r3
  long double v12; // fp2
  double v13; // fp26
  int v14; // r27
  double v15; // fp24
  double v16; // fp28
  double v17; // fp25
  double v18; // fp0
  int v19; // r28
  double v20; // fp0
  double v21; // fp29
  int v22; // r30
  double v23; // fp0
  double v24; // fp31
  idTraceModel *trm; // r3
  __int64 v26; // r11
  __int64 v27; // r9
  __int64 v28; // r11
  __int64 v29; // fp0
  double v30; // fp31
  idVehicleState **list; // r4
  double v32; // fp13
  int v33; // r5
  int v34; // r7
  int v35; // r11
  float *v36; // r6
  float *v37; // r10
  int v38; // ctr
  double v39; // fp7
  double v40; // fp4
  float *v41; // r11
  double v42; // fp8
  double v43; // fp6
  float *v44; // r10
  idVehicleState **v45; // r11
  int v46; // r30
  int num; // r11
  float *v48; // r11
  double v49; // fp0
  double v50; // fp13
  int size; // r11
  char **p_waterPoints; // r30
  char *v53; // r3
  char v54; // r11
  int v55; // r11
  int v56; // r11
  int v57; // r7
  int v58; // r10
  int v59; // r11
  float *v60; // r9
  char *v61; // r8
  idVec3 v62; // [sp+58h] [-1508h] BYREF
  __int64 v63; // [sp+68h] [-14F8h]
  __int64 v64; // [sp+70h] [-14F0h]
  __int64 v65; // [sp+78h] [-14E8h]
  idList<idVehicleState *,5> v66; // [sp+80h] [-14E0h] BYREF
  int v67; // [sp+90h] [-14D0h] BYREF

  *(_QWORD *)&v66.num = 256;
  v66.list = (idVehicleState **)&v67;
  *(_DWORD *)&v66.granularity = 66817;
  vertsX = entry->trm->vertsX;
  if ( !entry->trm->isConvex )
  {
    entry->hasWater = false;
_M248618:
    idList<idThread *,58>::Clear(this: &v66);
    return;
  }
  if ( vertsX[376] >= (double)vertsX[379]
    || vertsX[377] >= (double)vertsX[380]
    || vertsX[378] >= (double)vertsX[381]
    || (float)((float)((float)(vertsX[381] - vertsX[378]) * (float)(vertsX[380] - vertsX[377]))
             * (float)(vertsX[379] - vertsX[376])) == 0.0 )
  {
    entry->hasWater = false;
    goto _M248618;
  }
  if ( common->IsMultiplayer(this: common) )
  {
    entry->hasWater = false;
    goto _M248618;
  }
  HIDWORD(v5) = 0x82000000;
  numVerts = entry->trm->numVerts;
  v7 = 64 - numVerts;
  v8 = 1.0;
  LODWORD(v5) = 64 - numVerts;
  v9 = (float)v5;
  while ( 1 )
  {
    *((double *)&v10 + 1) = 0.3333333432674408;
    *(double *)&v10 = (float)((float)v9 * (float)v8);
    v12 = pow(x: v10, y: v4);
    v13 = (float)*(double *)&v12;
    v14 = 0;
    v15 = (float)((float)(entry->trm->bounds.b[1].x - entry->trm->bounds.b[0].x)
                * (float)((float)1.0 / (float)*(double *)&v12));
    v16 = (float)((float)(entry->trm->bounds.b[1].z - entry->trm->bounds.b[0].z)
                * (float)((float)1.0 / (float)*(double *)&v12));
    v17 = (float)((float)(entry->trm->bounds.b[1].y - entry->trm->bounds.b[0].y)
                * (float)((float)1.0 / (float)*(double *)&v12));
    if ( v13 > 0.0 )
    {
      v18 = 0.0;
      do
      {
        v19 = 0;
        v21 = (float)((float)((float)v18 + (float)0.5) * (float)v15);
        v20 = 0.0;
        do
        {
          v22 = 0;
          v24 = (float)((float)((float)v20 + (float)0.5) * (float)v17);
          v23 = 0.0;
          do
          {
            trm = entry->trm;
            v62.x = v21;
            v62.y = v24;
            v62.z = (float)((float)v23 + (float)0.5) * (float)v16;
            v62.x = trm->bounds.b[0].x + (float)v21;
            v62.y = trm->bounds.b[0].y + (float)v24;
            v62.z = trm->bounds.b[0].z + v62.z;
            v11 = idTraceModel::ContainsPoint(this: trm, point: &v62);
            HIDWORD(v26) = (unsigned __int8)v11;
            if ( (_BYTE)v11 != 0 )
            {
              v11 = idList<waterPoint_t,5>::PreAllocateWithGranularity(
                      this: (idList<waterPoint_t,5> *)&v66,
                      newSize: v66.num + 1);
              v26 = __PAIR64__(v66.size, v66.num);
              if ( v66.num >= v66.size )
              {
                LODWORD(v26) = &v66.list[5 * v66.size - 5];
              }
              else
              {
                HIDWORD(v26) = 4 * v66.num++;
                LODWORD(v26) = &v66.list[5 * v26];
              }
              *(idVec3 *)v26 = v62;
              *(float *)(v26 + 12) = 1.0;
              *(float *)(v26 + 16) = 1.0;
            }
            LODWORD(v26) = ++v22;
            v65 = v26;
            v23 = (float)v26;
          }
          while ( v23 < v13 );
          LODWORD(v26) = ++v19;
          v64 = v26;
          v20 = (float)v26;
        }
        while ( v20 < v13 );
        LODWORD(v26) = ++v14;
        v63 = v26;
        v18 = (float)v26;
      }
      while ( v18 < v13 );
    }
    HIDWORD(v27) = v66.num;
    if ( v66.num >= v7 )
      break;
    if ( v66.listStatic == 0 || v66.listStatic == 2 )
    {
      if ( v66.list != nullptr )
        idMem::Free(this: &mem, ptr: v66.list, align: ALIGN_16);
      v66.list = nullptr;
      v66.size = 0;
    }
    v8 = (float)((float)v8 * (float)2.0);
    v66.num = 0;
    if ( v8 > 16.0 )
    {
      entry->hasWater = false;
      goto _M248618;
    }
  }
  v28 = (unsigned int)(v66.num + numVerts);
  LODWORD(v27) = v66.num + numVerts;
  v63 = v27;
  v29 = v27;
  v30 = (float)((float)1.0 / (float)v27);
  if ( v66.num <= 0 )
  {
    list = v66.list;
  }
  else
  {
    LODWORD(v28) = 0;
    LODWORD(v27) = v66.list;
    do
    {
      *(float *)(v27 + 12) = (float)1.0 / (float)v29;
      ++HIDWORD(v28);
      *(float *)((char *)v66.list + v28 + 16) = (float)v30 * (float)v30;
      LODWORD(v28) = v28 + 20;
      list = v66.list;
      LODWORD(v27) = (char *)v66.list + v28;
      HIDWORD(v27) = v66.num;
    }
    while ( SHIDWORD(v28) < v66.num );
  }
  for ( ; SHIDWORD(v27) > v7; list = v66.list )
  {
    v32 = 1.0e30;
    v33 = 0;
    v34 = 0;
    v35 = 0;
    if ( SHIDWORD(v27) > 0 )
    {
      v11 = (int)(list + 1);
      do
      {
        LODWORD(v27) = v35;
        if ( v35 < SHIDWORD(v27) )
        {
          v36 = (float *)(v11 - 4);
          v37 = (float *)v11;
          v38 = HIDWORD(v27) - v35;
          do
          {
            v39 = (float)(*v36 - *(v37 - 1));
            v40 = (float)(v36[2] - v37[1]);
            if ( (float)((float)((float)((float)((float)v40 * (float)v40)
                                       + (float)((float)((float)v39 * (float)v39)
                                               + (float)((float)(*(float *)v11 - *v37) * (float)(*(float *)v11 - *v37))))
                               * v37[3])
                       * *(float *)(v11 + 12)) < v32 )
            {
              v32 = (float)((float)((float)((float)((float)v40 * (float)v40)
                                          + (float)((float)((float)v39 * (float)v39)
                                                  + (float)((float)(*(float *)v11 - *v37) * (float)(*(float *)v11 - *v37))))
                                  * v37[3])
                          * *(float *)(v11 + 12));
              v33 = v35;
              v34 = v27;
            }
            LODWORD(v27) = v27 + 1;
            v37 += 5;
            --v38;
          }
          while ( v38 != 0 );
        }
        ++v35;
        v11 += 20;
      }
      while ( v35 < SHIDWORD(v27) );
    }
    LODWORD(v27) = 20 * v34;
    v41 = (float *)&list[5 * v33];
    v42 = (float)(v41[2] + *(float *)&list[5 * v34 + 2]);
    v43 = (float)(v41[1] + *(float *)&list[5 * v34 + 1]);
    *v41 = (float)(*v41 + *(float *)&list[5 * v34]) * (float)0.5;
    v41[2] = (float)v42 * (float)0.5;
    v41[1] = (float)v43 * (float)0.5;
    *(float *)&v66.list[5 * v33 + 3] = *(float *)&v66.list[5 * v34 + 3] + *(float *)&v66.list[5 * v33 + 3];
    *(float *)&v66.list[5 * v33 + 4] = *(float *)&v66.list[5 * v33 + 3] * *(float *)&v66.list[5 * v33 + 3];
    HIDWORD(v27) = v66.num;
    if ( v34 >= 0 && v34 < v66.num )
    {
      HIDWORD(v27) = v66.num - 1;
      v66.num = HIDWORD(v27);
      if ( v34 != HIDWORD(v27) )
      {
        v44 = (float *)((char *)v66.list + v27);
        v45 = &v66.list[5 * HIDWORD(v27)];
        *(idVehicleState **)((char *)v66.list + v27) = *v45;
        v44[1] = *((float *)v45 + 1);
        v44[2] = *((float *)v45 + 2);
        v44[3] = *((float *)v45 + 3);
        v44[4] = *((float *)v45 + 4);
        HIDWORD(v27) = v66.num;
      }
    }
  }
  if ( numVerts > 0 )
  {
    v46 = 32;
    do
    {
      v11 = idList<waterPoint_t,5>::PreAllocateWithGranularity(
              this: (idList<waterPoint_t,5> *)&v66,
              newSize: HIDWORD(v27) + 1);
      num = v66.num;
      if ( v66.num >= v66.size )
      {
        v48 = (float *)&v66.list[5 * v66.size - 5];
      }
      else
      {
        ++v66.num;
        v48 = (float *)&v66.list[5 * num];
      }
      --numVerts;
      v49 = entry->trm->vertsX[v46];
      v50 = entry->trm->vertsY[v46];
      *v48 = entry->trm->vertsX[v46 - 32];
      ++v46;
      v48[1] = v49;
      v48[3] = v30;
      v48[2] = v50;
      v48[4] = (float)v30 * (float)v30;
      HIDWORD(v27) = v66.num;
    }
    while ( numVerts != 0 );
    list = v66.list;
  }
  size = entry->waterPoints.size;
  p_waterPoints = (char **)&entry->waterPoints;
  if ( size >= 64 )
    goto LABEL_71;
  if ( entry->waterPoints.listStatic == 0 )
  {
    if ( size > 0 || entry->waterPoints.granularity == 64 )
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)v11);
    v53 = idListArrayResize<idSphere>(
            voldptr: *p_waterPoints,
            oldNum: entry->waterPoints.size,
            newNum: 64,
            tag: (memTag_t)entry->waterPoints.memTag,
            zeroBuffer: false);
    *p_waterPoints = v53;
    if ( v53 == nullptr )
    {
      HIDWORD(v27) = v66.num;
      v54 = 0;
      list = v66.list;
      goto LABEL_70;
    }
    v55 = entry->waterPoints.num;
    entry->waterPoints.size = 64;
    if ( v55 > 64 )
      entry->waterPoints.num = 64;
    HIDWORD(v27) = v66.num;
    list = v66.list;
  }
  v54 = 1;
LABEL_70:
  if ( v54 != 0 )
  {
LABEL_71:
    v56 = entry->waterPoints.size;
    if ( v56 > 64 )
      v56 = 64;
    entry->waterPoints.num = v56;
  }
  v57 = 0;
  if ( SHIDWORD(v27) > 0 )
  {
    v58 = 0;
    v59 = 0;
    do
    {
      ++v57;
      v60 = (float *)&(*p_waterPoints)[v58];
      *v60 = *(float *)&list[v59];
      v60[1] = *(float *)&list[v59 + 1];
      v60[2] = *(float *)&list[v59 + 2];
      v61 = &(*p_waterPoints)[v58];
      v58 += 16;
      *((float *)v61 + 3) = *(float *)&v66.list[v59 + 3];
      v59 += 5;
      list = v66.list;
    }
    while ( v57 < v66.num );
  }
  entry->hasWater = true;
  if ( (v66.listStatic == 0 || v66.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
}


// ========================================================================
// $M248620
// EA  : 0x827696D8
// RVA : 0x007696D8
// PDB : w:\tech5\engine\gamelib\physics\tracemodelcache.cpp
// ========================================================================

void _M248620()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 5472 + 128));
}


// ========================================================================
// ?AllocTraceModel@idTraceModelCache@@QAAHABVidTraceModel@@PBVidMaterial@@@Z
// EA  : 0x82769708
// RVA : 0x00769708
// PDB : w:\tech5\engine\gamelib\physics\tracemodelcache.cpp
// ========================================================================

int __fastcall idTraceModelCache::AllocTraceModel(
        idTraceModelCache *this,
        const idTraceModel *trm,
        const idMaterial *material)
{
  idHashIndex *p_hash; // r30
  unsigned __int32 v7; // r25
  int v8; // r29
  idTraceModelCache::trmCache_t *v9; // r11
  int num; // r28
  int indexSize; // r11
  int v13; // r6
  idList<idTraceModelCache::trmCache_t *,13> *p_cache; // r29
  idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::element_t *v15; // r30
  int size; // r10
  int v17; // r11
  idTraceModelCache::trmCache_t **list; // r10
  idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::element_t **v19; // r11
  idTraceModelCache::trmCache_t *v20; // r3
  int *p_refCount; // r9
  idSysMutex *p_viewNoteMutex; // r10
  int v23; // ctr
  float *v24; // r4
  __int64 v25; // r10
  __int64 v26; // r6
  __int64 v27; // r8
  __int64 v28; // r6
  __int64 v29; // r10
  int v30; // r7
  idStr *MapModelName; // r3
  int v32; // [sp+8h] [-10C8h]
  __int64 v33; // [sp+8h] [-10C8h]
  int v34; // [sp+Ch] [-10C4h]
  int v35; // [sp+10h] [-10C0h]
  int v36; // [sp+14h] [-10BCh]
  int v37; // [sp+18h] [-10B8h]
  int v38; // [sp+1Ch] [-10B4h]
  idStr v39; // [sp+60h] [-1070h] BYREF
  va v40; // [sp+80h] [-1050h] BYREF

  p_hash = &this->hash;
  v7 = (4 * ((4 * ((16 * trm->type) ^ trm->numVerts)) ^ trm->numEdges))
     ^ trm->numPolys
     ^ LODWORD(trm->bounds.b[0].z)
     ^ LODWORD(trm->bounds.b[0].y)
     ^ LODWORD(trm->bounds.b[0].x);
  v8 = this->hash.hash[this->hash.hashMask & v7 & this->hash.lookupMask];
  if ( v8 == -1 )
  {
LABEL_5:
    num = this->cache.num;
    indexSize = p_hash->indexSize;
    if ( p_hash->hash == idHashIndex::INVALID_INDEX )
    {
      if ( num >= indexSize )
        indexSize = num + 1;
      idHashIndex::Allocate(this: p_hash, newHashSize: p_hash->hashSize, newIndexSize: indexSize);
    }
    else if ( num >= indexSize )
    {
      idHashIndex::ResizeIndex(this: p_hash, newIndexSize: num + 1);
    }
    v13 = p_hash->hashMask & v7;
    p_hash->indexChain[num] = p_hash->hash[v13];
    p_hash->hash[v13] = num;
    p_cache = &this->cache;
    v15 = idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::Alloc(this: &this->cacheAllocator);
    idList<idMD6Node *,5>::PreAllocateWithGranularity(
      this: (idList<idMD6Filter *,5> *)&this->cache,
      newSize: this->cache.num + 1);
    size = this->cache.size;
    v17 = this->cache.num;
    if ( v17 >= size )
    {
      v19 = (idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::element_t **)&p_cache->list[size - 1];
    }
    else
    {
      list = p_cache->list;
      this->cache.num = v17 + 1;
      v19 = (idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::element_t **)&list[v17];
    }
    *v19 = v15;
    v20 = (idTraceModelCache::trmCache_t *)idTraceModel::operator new(size: 0x600u);
    if ( v20 != nullptr )
    {
      v20[16].collisionModel = nullptr;
      p_refCount = &v20[17].refCount;
      *(_DWORD *)&v20[16].hasWater = 0;
      p_viewNoteMutex = &analysisClient.viewNoteMutex;
      v20[16].waterPoints.list = nullptr;
      v23 = 6;
      v20[16].waterPoints.num = 0;
      v20[16].waterPoints.size = 0;
      *(float *)&v20[16].waterPoints.granularity = 0.0;
      *(float *)&v20[17].trm = 0.0;
      *(float *)&v20[17].refCount = 0.0;
      do
      {
        ++p_viewNoteMutex;
        *++p_refCount = (int)p_viewNoteMutex->handle;
        --v23;
      }
      while ( v23 != 0 );
      v20[17].inertiaTensor.mat[0].z = 0.0;
      HIBYTE(v20[17].inertiaTensor.mat[1].x) = 0;
      LOBYTE(v20[17].inertiaTensor.mat[1].x) = 0;
      BYTE2(v20[17].inertiaTensor.mat[1].x) = 0;
      BYTE1(v20[17].inertiaTensor.mat[1].x) = 0;
    }
    else
    {
      v20 = nullptr;
    }
    v15->data = v20;
    idTraceModel::operator=(this: (idTraceModel *)v20, __that: trm);
    idTraceModel::ClearUnused(this: (idTraceModel *)v15->data);
    idTraceModel::GetMassProperties(
      this: (idTraceModel *)v15->data,
      density: 1.0,
      mass: v24,
      centerOfMass: (idVec3 *)&v15->buffer[8],
      inertiaTensor: (idMat3 *)&v15->buffer[12]);
    LODWORD(v25) = 1;
    *(_DWORD *)&v15->buffer[60] = material;
    HIDWORD(v25) = &unk_821F0000;
    *(_DWORD *)&v15->buffer[4] = 1;
    HIDWORD(v26) = num;
    HIDWORD(v28) = va::va(
                     this: &v40,
                     fmt: "traceModel%d",
                     a3: v26,
                     a4: v27,
                     a5: v25,
                     a6: v32,
                     a7: v34,
                     a8: v35,
                     a9: v36,
                     a10: v37,
                     a11: v38);
    MapModelName = idMapFile::GetMapModelName(result: &v39, entityName: v28, a3: v30, a4: v29, a5: v33);
    *(_DWORD *)&v15->buffer[64] = idCollisionModelManager::ModelFromTrm(
                                    this: collisionModelManager,
                                    modelName: MapModelName->data,
                                    trm: (const idTraceModel *)v15->data,
                                    material);
    idStr::FreeData(this: &v39);
    idTraceModelCache::SetupWaterPoints(this, entry: (idTraceModelCache::trmCache_t *)v15);
    return num;
  }
  else
  {
    while ( 1 )
    {
      if ( idTraceModel::Compare(this: this->cache.list[v8]->trm, trm) )
      {
        v9 = this->cache.list[v8];
        if ( v9->material == material )
          break;
      }
      v8 = p_hash->indexChain[v8 & p_hash->lookupMask];
      if ( v8 == -1 )
        goto LABEL_5;
    }
    ++v9->refCount;
    return v8;
  }
}


// ========================================================================
// __unwind$248640
// EA  : 0x827699F4
// RVA : 0x007699F4
// PDB : w:\tech5\engine\gamelib\physics\tracemodelcache.cpp
// ========================================================================

void _unwind_248640()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4304 + 96));
}

