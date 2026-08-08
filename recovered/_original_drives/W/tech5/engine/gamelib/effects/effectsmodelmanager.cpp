
// ========================================================================
// ?RecycleParticleFxModel@idEffectsModelManager@@QAAXPBVidDeclParticle@@PAVidRenderModelParticle@@@Z
// EA  : 0x82708720
// RVA : 0x00708720
// PDB : w:\tech5\engine\gamelib\effects\effectsmodelmanager.cpp
// ========================================================================

void __fastcall idEffectsModelManager::RecycleParticleFxModel(
        idEffectsModelManager *this,
        const idDeclParticle *particleDecl,
        idRenderModelParticle *model)
{
  const char *str; // r4
  int v6; // r30
  unsigned __int8 v7; // r9
  unsigned __int8 *v8; // r10
  int hashMask; // r9
  int lookupMask; // r10
  int v11; // r31
  idEffectsModelManager::fxPrtModel_t *v12; // r11
  int num; // r31
  const char *v14; // r30
  int Spread; // r29
  int v16; // r3

  if ( model != nullptr && particleDecl != nullptr )
  {
    str = particleDecl->name.str;
    v6 = 0;
    v7 = *str;
    if ( *str != 0 )
    {
      v8 = (unsigned __int8 *)str;
      do
      {
        ++v8;
        v6 = 31 * v6 + v7;
        v7 = *v8;
      }
      while ( *v8 != 0 );
    }
    hashMask = this->activePrtModelHash.hashMask;
    lookupMask = this->activePrtModelHash.lookupMask;
    v11 = this->activePrtModelHash.hash[hashMask & lookupMask & hashMask & v6];
    if ( v11 == -1 )
    {
LABEL_10:
      if ( g_showEffectsModelRecyclerStats.valueInteger == 0 )
        return;
      idLib::Printf(
        fmt: "idEffectsModelManager::RecycleParticleFxModel : model %s not found in active list for recycling\n",
        str);
    }
    else
    {
      while ( 1 )
      {
        v12 = &this->fxPrtModels.list[v11];
        if ( v12->pDecl == particleDecl && v12->pmodel == model )
          break;
        v11 = this->activePrtModelHash.indexChain[lookupMask & v11];
        if ( v11 == -1 )
          goto LABEL_10;
      }
      idHashIndex::Remove(this: &this->activePrtModelHash, key: hashMask & v6, index: v11);
      idHashIndex::Add(this: &this->inactivePrtModelHash, key: this->inactivePrtModelHash.hashMask & v6, index: v11);
    }
    if ( g_showEffectsModelRecyclerStats.valueInteger != 0 )
    {
      num = this->fxPrtModels.num;
      v14 = particleDecl->name.str;
      Spread = idHashIndex::GetSpread(this: &this->activePrtModelHash);
      v16 = idHashIndex::GetSpread(this: &this->inactivePrtModelHash);
      idLib::Printf(
        fmt: "Recycling model %s, total models allocated %d inactive models spread %d active models spread %d\n",
        v14,
        num,
        v16,
        Spread);
    }
  }
  else
  {
    idLib::Warning(fmt: "idFXModelRecycler::RecycleEffectModel : invalid model");
  }
}


// ========================================================================
// ?Init@idEffectsModelManager@@QAAXXZ
// EA  : 0x827088A0
// RVA : 0x007088A0
// PDB : w:\tech5\engine\gamelib\effects\effectsmodelmanager.cpp
// ========================================================================

void __fastcall idEffectsModelManager::Init(idEffectsModelManager *this)
{
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  idHashIndex::Clear(this: &this->activePrtModelHash);
  this->activePrtModelHash.memTag = TAG_PARTICLE;
  idHashIndex::Clear(this: &this->inactivePrtModelHash);
  this->inactivePrtModelHash.memTag = TAG_PARTICLE;
}


// ========================================================================
// ?Shutdown@idEffectsModelManager@@QAAXXZ
// EA  : 0x827088F0
// RVA : 0x007088F0
// PDB : w:\tech5\engine\gamelib\effects\effectsmodelmanager.cpp
// ========================================================================

void __fastcall idEffectsModelManager::Shutdown(idEffectsModelManager *this)
{
  int v2; // r28
  int v3; // r30
  idRenderModelParticle *pmodel; // r3

  idHashIndex::Clear(this: &this->activePrtModelHash);
  idHashIndex::Clear(this: &this->inactivePrtModelHash);
  v2 = 0;
  if ( this->fxPrtModels.num > 0 )
  {
    v3 = 0;
    do
    {
      pmodel = this->fxPrtModels.list[v3].pmodel;
      if ( pmodel != nullptr )
      {
        pmodel->unlinked = true;
        pmodel->deleteOnSync = true;
        idRenderModel::CommitThisFrame(this: pmodel);
        this->fxPrtModels.list[v3].pmodel = nullptr;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->fxPrtModels.num );
  }
  if ( this->fxPrtModels.listStatic == 0 || this->fxPrtModels.listStatic == 2 )
  {
    if ( this->fxPrtModels.list != nullptr )
      idMem::Free(this: &mem, ptr: this->fxPrtModels.list, align: ALIGN_16);
    this->fxPrtModels.list = nullptr;
    this->fxPrtModels.size = 0;
  }
  this->fxPrtModels.num = 0;
}


// ========================================================================
// ??1idEffectsModelManager@@QAA@XZ
// EA  : 0x827089B0
// RVA : 0x007089B0
// PDB : w:\tech5\engine\gamelib\effects\effectsmodelmanager.cpp
// ========================================================================

void __fastcall idEffectsModelManager::~idEffectsModelManager(idEffectsModelManager *this)
{
  idEffectsModelManager::Shutdown(this);
  idHashIndex::Free(this: &this->inactivePrtModelHash);
  idHashIndex::Free(this: &this->activePrtModelHash);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$246141
// EA  : 0x82708A04
// RVA : 0x00708A04
// PDB : w:\tech5\engine\gamelib\effects\effectsmodelmanager.cpp
// ========================================================================

void _unwind_246141()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$246142_0
// EA  : 0x82708A2C
// RVA : 0x00708A2C
// PDB : w:\tech5\engine\gamelib\effects\effectsmodelmanager.cpp
// ========================================================================

void _unwind_246142_0()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 3216));
}


// ========================================================================
// __unwind$246143
// EA  : 0x82708A58
// RVA : 0x00708A58
// PDB : w:\tech5\engine\gamelib\effects\effectsmodelmanager.cpp
// ========================================================================

void _unwind_246143()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 3248));
}


// ========================================================================
// ??0idEffectsModelManager@@QAA@XZ
// EA  : 0x82708A90
// RVA : 0x00708A90
// PDB : w:\tech5\engine\gamelib\effects\effectsmodelmanager.cpp
// ========================================================================

idEffectsModelManager *__fastcall idEffectsModelManager::idEffectsModelManager(idEffectsModelManager *this)
{
  this->fxPrtModels.granularity = 1;
  this->fxPrtModels.list = this->fxPrtModels.staticList;
  this->fxPrtModels.size = 400;
  this->fxPrtModels.num = 0;
  this->fxPrtModels.memTag = 5;
  this->fxPrtModels.listStatic = 1;
  this->activePrtModelHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->activePrtModelHash, initialHashSize: 1024, initialIndexSize: 1024);
  this->inactivePrtModelHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->inactivePrtModelHash, initialHashSize: 1024, initialIndexSize: 1024);
  return this;
}


// ========================================================================
// __unwind$246198
// EA  : 0x82708B0C
// RVA : 0x00708B0C
// PDB : w:\tech5\engine\gamelib\effects\effectsmodelmanager.cpp
// ========================================================================

void _unwind_246198()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$246199
// EA  : 0x82708B34
// RVA : 0x00708B34
// PDB : w:\tech5\engine\gamelib\effects\effectsmodelmanager.cpp
// ========================================================================

void _unwind_246199()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 3216));
}


// ========================================================================
// ?GetNextParticleEffectModel@idEffectsModelManager@@QAAPAVidRenderModelParticle@@PBVidDeclParticle@@@Z
// EA  : 0x82708B68
// RVA : 0x00708B68
// PDB : w:\tech5\engine\gamelib\effects\effectsmodelmanager.cpp
// ========================================================================

idRenderModelParticle *__fastcall idEffectsModelManager::GetNextParticleEffectModel(
        idEffectsModelManager *this,
        const idMaterial *particleDecl)
{
  const char *str; // r4
  int v6; // r29
  unsigned __int8 v7; // r9
  const char *v8; // r10
  int hashMask; // r11
  int lookupMask; // r9
  int v11; // r8
  int v12; // r30
  int v13; // r25
  idEffectsModelManager::fxPrtModel_t *v14; // r11
  int v15; // r30
  const char *v16; // r29
  int v17; // r27
  int v18; // r3
  idRenderWorld *v19; // r3
  idRenderModel *v20; // r3
  const idMaterial *v21; // r3
  int v22; // r27
  int num; // r30
  const char *v24; // r29
  int Spread; // r25
  int v26; // r3
  idRenderModelParticle *pmodel; // r30
  idSkinMapping v28; // [sp+50h] [-80h] BYREF
  idStr v29[3]; // [sp+60h] [-70h] BYREF

  if ( particleDecl != nullptr )
  {
    str = particleDecl->name.str;
    v6 = 0;
    v7 = *str;
    if ( *str != 0 )
    {
      v8 = particleDecl->name.str;
      do
      {
        ++v8;
        v6 = 31 * v6 + v7;
        v7 = *v8;
      }
      while ( *v8 != 0 );
    }
    hashMask = this->inactivePrtModelHash.hashMask;
    lookupMask = this->inactivePrtModelHash.lookupMask;
    v11 = hashMask & v6;
    v12 = this->inactivePrtModelHash.hash[hashMask & lookupMask & hashMask & v6];
    if ( v12 == -1 )
    {
LABEL_10:
      if ( this->fxPrtModels.num < this->fxPrtModels.size )
      {
        v28.from = (const idMaterial *)particleDecl->name.str;
        idStr::idStr(this: v29, text: str);
        idStr::SetFileExtension(this: v29, extension: "prt");
        if ( common->RW(this: common) != nullptr
          && (v19 = common->RW(this: common),
              v20 = v19->AllocRenderModel(this: v19, a2: v29[0].data, a3: true, a4: -1),
              (v21 = (const idMaterial *)_RTDynamicCast(
                                           inptr: v20,
                                           VfDelta: 0,
                                           SrcType: &idRenderModel `RTTI Type Descriptor',
                                           TargetType: &idRenderModelParticle `RTTI Type Descriptor',
                                           isReference: 0)) != nullptr) )
        {
          v28.from = v21;
          v28.to = particleDecl;
          v22 = idList<cachedPageFile_t,5>::Append((idList<idSkinMapping,46> *)this, obj: &v28);
          idHashIndex::Add(this: &this->activePrtModelHash, key: this->activePrtModelHash.hashMask & v6, index: v22);
          if ( g_showEffectsModelRecyclerStats.valueInteger != 0 )
          {
            num = this->fxPrtModels.num;
            v24 = particleDecl->name.str;
            Spread = idHashIndex::GetSpread(this: &this->activePrtModelHash);
            v26 = idHashIndex::GetSpread(this: &this->inactivePrtModelHash);
            idLib::Printf(
              fmt: "Allocated new model %s for active list, total models allocated %d inactive models spread %d active models spread %d\n",
              v24,
              num,
              v26,
              Spread);
          }
          pmodel = this->fxPrtModels.list[v22].pmodel;
          idStr::FreeData(this: v29);
          return pmodel;
        }
        else
        {
          idLib::Warning(
            fmt: "idFXModelRecycler::GetParticleFxModel: Could not allocate a rendermodel for '%s'",
            particleDecl->name.str);
          idStr::FreeData(this: v29);
          return nullptr;
        }
      }
      else
      {
        idLib::Warning(fmt: "idFXModelRecycler::GetParticleFxModel: Could not allocate model %s, out of slots", str);
        return nullptr;
      }
    }
    else
    {
      while ( 1 )
      {
        v13 = v12;
        v14 = &this->fxPrtModels.list[v12];
        if ( (const idMaterial *)v14->pDecl == particleDecl && v14->pmodel != nullptr )
          break;
        v12 = this->inactivePrtModelHash.indexChain[lookupMask & v12];
        if ( v12 == -1 )
          goto LABEL_10;
      }
      idHashIndex::Remove(this: &this->inactivePrtModelHash, key: v11, index: v12);
      idHashIndex::Add(this: &this->activePrtModelHash, key: this->activePrtModelHash.hashMask & v6, index: v12);
      if ( g_showEffectsModelRecyclerStats.valueInteger != 0 )
      {
        v15 = this->fxPrtModels.num;
        v16 = particleDecl->name.str;
        v17 = idHashIndex::GetSpread(this: &this->activePrtModelHash);
        v18 = idHashIndex::GetSpread(this: &this->inactivePrtModelHash);
        idLib::Printf(
          fmt: "Found model %s in inactive list, total models allocated %d inactive models spread %d active models spread %d\n",
          v16,
          v15,
          v18,
          v17);
      }
      return this->fxPrtModels.list[v13].pmodel;
    }
  }
  else
  {
    idLib::Warning(fmt: "idEffectsModelManager::GetNextParticleEffectModel : particleDecl NULL");
    return nullptr;
  }
}


// ========================================================================
// __unwind$246250
// EA  : 0x82708E3C
// RVA : 0x00708E3C
// PDB : w:\tech5\engine\gamelib\effects\effectsmodelmanager.cpp
// ========================================================================

void _unwind_246250()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// `dynamic initializer for 'g_showEffectsModelRecyclerStats''
// EA  : 0x8333F740
// RVA : 0x0133F740
// PDB : w:\tech5\engine\gamelib\effects\effectsmodelmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showEffectsModelRecyclerStats__()
{
  idCVar::idCVar(
    this: &g_showEffectsModelRecyclerStats,
    name: "g_showEffectsModelRecyclerStats",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showEffectsModelRecyclerStats__);
}

