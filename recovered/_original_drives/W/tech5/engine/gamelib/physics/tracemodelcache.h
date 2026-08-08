
// ========================================================================
// ??0trmCache_t@idTraceModelCache@@QAA@XZ
// EA  : 0x82768CB8
// RVA : 0x00768CB8
// PDB : w:\tech5\engine\gamelib\physics\tracemodelcache.h
// ========================================================================

idTraceModelCache::trmCache_t *__fastcall idTraceModelCache::trmCache_t::trmCache_t(
        idTraceModelCache::trmCache_t *this)
{
  int v2; // r9
  int v3; // r11
  int i; // ctr
  int v5; // r8

  this->waterPoints.list = nullptr;
  this->waterPoints.granularity = 0;
  this->waterPoints.memTag = 54;
  this->waterPoints.listStatic = 0;
  this->waterPoints.size = 0;
  this->waterPoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->waterPoints);
  this->trm = nullptr;
  v2 = 6;
  this->refCount = 1;
  this->volume = 0.0;
  this->centerOfMass.z = 0.0;
  this->centerOfMass.y = 0.0;
  this->centerOfMass.x = 0.0;
  do
  {
    v3 = 0;
    for ( i = 3; i != 0; --i )
    {
      v5 = 4 * (v2 + v3++);
      *(float *)((char *)&this->trm + v5) = 0.0;
    }
    v2 += 3;
  }
  while ( v2 < 15 );
  this->material = nullptr;
  this->collisionModel = nullptr;
  this->hasWater = false;
  return this;
}


// ========================================================================
// ??0idTraceModelCache@@QAA@XZ
// EA  : 0x82B51A48
// RVA : 0x00B51A48
// PDB : w:\tech5\engine\gamelib\physics\tracemodelcache.h
// ========================================================================

idTraceModelCache *__fastcall idTraceModelCache::idTraceModelCache(idTraceModelCache *this)
{
  this->mapName.len = 0;
  this->mapName.data = this->mapName.baseBuffer;
  this->mapName.allocedAndFlag = 20;
  this->mapName.baseBuffer[0] = 0;
  this->cacheAllocator.blocks = nullptr;
  this->cacheAllocator.free = nullptr;
  this->cacheAllocator.total = 0;
  this->cacheAllocator.active = 0;
  this->cacheAllocator.allowAllocs = true;
  this->cacheAllocator.clearAllocs = false;
  this->cache.list = nullptr;
  this->cache.granularity = 0;
  this->cache.memTag = 13;
  this->cache.listStatic = 0;
  this->cache.size = 0;
  this->cache.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cache);
  this->hash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->hash, initialHashSize: 1024, initialIndexSize: 1024);
  return this;
}


// ========================================================================
// __unwind$501010
// EA  : 0x82B51B00
// RVA : 0x00B51B00
// PDB : w:\tech5\engine\gamelib\physics\tracemodelcache.h
// ========================================================================

void _unwind_501010()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$501011
// EA  : 0x82B51B28
// RVA : 0x00B51B28
// PDB : w:\tech5\engine\gamelib\physics\tracemodelcache.h
// ========================================================================

void _unwind_501011()
{
  int v0; // r12

  idBlockAlloc<idTraceModelCache::trmCache_t,64,13>::~idBlockAlloc<idTraceModelCache::trmCache_t,64,13>(this: (idBlockAlloc<idTraceModelCache::trmCache_t,64,13> *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}


// ========================================================================
// __unwind$501012
// EA  : 0x82B51B54
// RVA : 0x00B51B54
// PDB : w:\tech5\engine\gamelib\physics\tracemodelcache.h
// ========================================================================

void _unwind_501012()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 52));
}

