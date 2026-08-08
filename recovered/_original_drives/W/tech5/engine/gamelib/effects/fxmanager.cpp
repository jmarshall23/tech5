
// ========================================================================
// ?GetVector@idFXManager@@ABA?AVidVec4@@PBVidDeclRenderParm@@@Z
// EA  : 0x8270B118
// RVA : 0x0070B118
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

idFXManager *__fastcall idFXManager::GetVector(idFXManager *this, idVec4 *result, const idDeclRenderParm *parm)
{
  float w; // r3
  idVec4 *ParmBlock; // r3

  w = result->w;
  if ( w == 0.0 || idRenderModel::GetParmBlock(this: (idRenderModel *)LODWORD(w)) == nullptr )
  {
    *(idVec4 *)&this->initialized = vec4_origin;
    return this;
  }
  else
  {
    ParmBlock = (idVec4 *)idRenderModel::GetParmBlock(this: (idRenderModel *)LODWORD(result->w));
    idParmBlock::GetVector((idParmBlock *)this, result: ParmBlock, parm);
    return this;
  }
}


// ========================================================================
// ?RecycleParticleFxModel@idFXModelRecycler@@QAAXPBVidDeclParticle@@PAVidRenderModelParticle@@@Z
// EA  : 0x8270B498
// RVA : 0x0070B498
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXModelRecycler::RecycleParticleFxModel(
        idFXModelRecycler *this,
        const idDeclParticle *particleDecl,
        idRenderModelParticle *model)
{
  const char *str; // r10
  int v6; // r30
  unsigned __int8 i; // r9
  int hashMask; // r11
  int lookupMask; // r9
  int v10; // r4
  int v11; // r31
  idFXModelRecycler::fxPrtModel_t *v12; // r11
  int num; // r31
  const char *v14; // r30
  int Spread; // r29
  int v16; // r3

  if ( model != nullptr && particleDecl != nullptr )
  {
    str = particleDecl->name.str;
    v6 = 0;
    for ( i = *str; *str != 0; i = *str )
    {
      ++str;
      v6 = 31 * v6 + i;
    }
    hashMask = this->activePrtModelHash.hashMask;
    lookupMask = this->activePrtModelHash.lookupMask;
    v10 = hashMask & v6;
    v11 = this->activePrtModelHash.hash[hashMask & lookupMask & hashMask & v6];
    if ( v11 != -1 )
    {
      while ( 1 )
      {
        v12 = &this->fxPrtModels.list[v11];
        if ( v12->pDecl == particleDecl && v12->pmodel == model )
          break;
        v11 = this->activePrtModelHash.indexChain[lookupMask & v11];
        if ( v11 == -1 )
          goto LABEL_11;
      }
      idHashIndex::Remove(this: &this->activePrtModelHash, key: v10, index: v11);
      idHashIndex::Add(this: &this->inactivePrtModelHash, key: this->inactivePrtModelHash.hashMask & v6, index: v11);
    }
LABEL_11:
    if ( g_showFxModelRecyclerStats.valueInteger != 0 )
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
// ?RecycleStaticFxModel@idFXModelRecycler@@QAAXABVidAtomicString@@PAVidRenderModel@@@Z
// EA  : 0x8270B5F8
// RVA : 0x0070B5F8
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXModelRecycler::RecycleStaticFxModel(
        idFXModelRecycler *this,
        const idAtomicString *name,
        idRenderModel *model)
{
  const char *str; // r10
  int v7; // r29
  unsigned __int8 v8; // r9
  int hashMask; // r11
  int v10; // r26
  int v11; // r31
  int num; // r31
  const char *v13; // r30
  int Spread; // r29
  int v15; // r3

  if ( model != nullptr )
  {
    str = name->str;
    v7 = 0;
    v8 = *name->str;
    if ( v8 != 0 )
    {
      do
      {
        ++str;
        v7 = 31 * v7 + v8;
        v8 = *str;
      }
      while ( *str != 0 );
    }
    hashMask = this->activeStaticModelHash.hashMask;
    v10 = hashMask & v7;
    v11 = this->activeStaticModelHash.hash[hashMask & this->activeStaticModelHash.lookupMask & hashMask & v7];
    if ( v11 != -1 )
    {
      while ( idStr::Cmp(s1: this->fxStaticModels.list[v11].modelName.str, s2: name->str) != 0
           || this->fxStaticModels.list[v11].rmodel != model )
      {
        v11 = this->activeStaticModelHash.indexChain[this->activeStaticModelHash.lookupMask & v11];
        if ( v11 == -1 )
          goto LABEL_11;
      }
      idHashIndex::Remove(this: &this->activeStaticModelHash, key: v10, index: v11);
      idHashIndex::Add(
        this: &this->inactiveStaticModelHash,
        key: this->inactiveStaticModelHash.hashMask & v7,
        index: v11);
    }
LABEL_11:
    if ( g_showFxModelRecyclerStats.valueInteger != 0 )
    {
      num = this->fxStaticModels.num;
      v13 = name->str;
      Spread = idHashIndex::GetSpread(this: &this->activeStaticModelHash);
      v15 = idHashIndex::GetSpread(this: &this->inactiveStaticModelHash);
      idLib::Printf(
        fmt: "Recycling model %s, total models allocated %d inactive models spread %d active models spread %d\n",
        v13,
        num,
        v15,
        Spread);
    }
  }
  else
  {
    idLib::Warning(fmt: "idFXModelRecycler::RecycleStaticFxModel : invalid model");
  }
}


// ========================================================================
// ?GetTableColor@idFXManager@@ABA?AVidVec4@@ABVidFXSingleAction@@M@Z
// EA  : 0x8270B768
// RVA : 0x0070B768
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

idFXManager *__fastcall idFXManager::GetTableColor(
        idFXManager *this,
        idVec4 *result,
        const idFXSingleAction *fxaction,
        double pct)
{
  const idDeclTable *colorTableRGB; // r11
  double v8; // fp31
  double v9; // fp30
  double v10; // fp29
  double v11; // fp27
  const idDeclTable *colorTableA; // r11

  colorTableRGB = fxaction->colorTableRGB;
  v8 = 1.0;
  v9 = 1.0;
  v10 = 1.0;
  v11 = 1.0;
  if ( colorTableRGB != nullptr )
  {
    v8 = idLookupTable::TableLookup(this: colorTableRGB->table, time: pct, fastSearch: (bool)result);
    v9 = v8;
    v10 = v8;
  }
  colorTableA = fxaction->colorTableA;
  if ( colorTableA != nullptr )
    v11 = idLookupTable::TableLookup(this: colorTableA->table, time: pct, fastSearch: (bool)result);
  *(float *)&this->initialized = v8;
  *(float *)&this->fxDecl = v9;
  *(float *)&this->gameLibEffects = v10;
  *(float *)&this->ta = v11;
  return this;
}


// ========================================================================
// ?IsStopped@idFXManager@@QBA_NH@Z
// EA  : 0x8270B820
// RVA : 0x0070B820
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

int __fastcall idFXManager::IsStopped(idFXManager *this, int time)
{
  int num; // r10
  int result; // r3
  fxActionState_t *list; // r8
  int v6; // r11
  int v7; // ctr
  fxActionState_t *v8; // r10

  num = this->actionState.num;
  result = 1;
  if ( num > 0 )
  {
    list = this->actionState.list;
    v7 = num;
    v8 = list;
    v6 = 0;
    do
    {
      ++v6;
      result = (unsigned __int8)result & (time >= v8->stopTime);
      v8 = &list[v6];
      --v7;
    }
    while ( v7 != 0 );
  }
  return result;
}


// ========================================================================
// ?GetWorldSpaceTagVelocity@idFXManager@@AAA_NABUtagData_t@@HAAVidVec3@@@Z
// EA  : 0x8270B870
// RVA : 0x0070B870
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

BOOL __fastcall idFXManager::GetWorldSpaceTagVelocity(
        idFXManager *this,
        const tagData_t *tag,
        unsigned int gameMsPerFrame,
        idVec3 *tagVel)
{
  idTreeAnimator *ta; // r3
  float *p_deferredAxis; // r31
  double v9; // fp31
  double v10; // fp30
  double v11; // fp29
  double v12; // fp28
  BOOL result; // r3
  double v14; // fp4
  double v15; // fp3
  idIndex<short,enum invalidJointIndex_t> v16[4]; // [sp+50h] [-D0h] BYREF
  idVec3 v17; // [sp+58h] [-C8h] BYREF
  idVec3 v18; // [sp+68h] [-B8h] BYREF
  idMat3 v19; // [sp+80h] [-A0h] BYREF
  idMat3 v20[2]; // [sp+B0h] [-70h] BYREF

  ta = this->ta;
  if ( ta == nullptr )
    return false;
  p_deferredAxis = (float *)&ta->deferredAxis;
  if ( !ta->useDeferredPosition )
    p_deferredAxis = (float *)&ta->g.axis;
  *(_QWORD *)&v17.x = __PAIR64__(&unk_82390000, gameMsPerFrame);
  v9 = (float)((float)1.0 / (float)((float)__SPAIR64__(&unk_82390000, gameMsPerFrame) * (float)0.001));
  idTreeAnimator::GetLastOriginDeltas(this: ta, rot: &v19, trans: &v17);
  v10 = (float)((float)(p_deferredAxis[1] * (float)(v17.x * (float)v9))
              + (float)((float)(p_deferredAxis[7] * (float)(v17.z * (float)v9))
                      + (float)(p_deferredAxis[4] * (float)(v17.y * (float)v9))));
  v11 = (float)((float)(*p_deferredAxis * (float)(v17.x * (float)v9))
              + (float)((float)(p_deferredAxis[3] * (float)(v17.y * (float)v9))
                      + (float)(p_deferredAxis[6] * (float)(v17.z * (float)v9))));
  v12 = (float)((float)((float)(v17.x * (float)v9) * p_deferredAxis[2])
              + (float)((float)(p_deferredAxis[8] * (float)(v17.z * (float)v9))
                      + (float)(p_deferredAxis[5] * (float)(v17.y * (float)v9))));
  idTreeAnimator::GetJointIndex(
    this: (idTreeAnimator *)v16,
    result: (idIndex<short,enum invalidJointIndex_t> *)this->ta,
    jointHandle: &tag->parentJoint);
  result = idTreeAnimator::GetModelSpaceJointFrameDeltas(
             this: this->ta,
             indices: v16,
             numIndices: 1,
             transDeltas: &v18,
             rotDeltas: v20);
  v14 = (float)((float)(p_deferredAxis[1] * (float)(v18.x * (float)v9))
              + (float)((float)(p_deferredAxis[7] * (float)(v18.z * (float)v9))
                      + (float)(p_deferredAxis[4] * (float)(v18.y * (float)v9))));
  v15 = (float)((float)((float)(v18.x * (float)v9) * p_deferredAxis[2])
              + (float)((float)(p_deferredAxis[8] * (float)(v18.z * (float)v9))
                      + (float)(p_deferredAxis[5] * (float)(v18.y * (float)v9))));
  tagVel->x = (float)((float)(p_deferredAxis[6] * (float)(v18.z * (float)v9))
                    + (float)((float)(p_deferredAxis[3] * (float)(v18.y * (float)v9))
                            + (float)(*p_deferredAxis * (float)(v18.x * (float)v9))))
            + (float)v11;
  tagVel->y = (float)v14 + (float)v10;
  tagVel->z = (float)v15 + (float)v12;
  return result;
}


// ========================================================================
// ?GetName@idFXManager@@ABAPBDXZ
// EA  : 0x8270BA10
// RVA : 0x0070BA10
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

const char *__fastcall idFXManager::GetName(idFXManager *this)
{
  idTreeAnimator *ta; // r11
  const idDeclMD6 *decl; // r11

  ta = this->ta;
  if ( ta != nullptr && (decl = ta->decl) != nullptr )
    return decl->name.str;
  else
    return "NULL";
}


// ========================================================================
// ?Init@idFXModelRecycler@@QAAXXZ
// EA  : 0x8270BB70
// RVA : 0x0070BB70
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXModelRecycler::Init(idFXModelRecycler *this)
{
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  idHashIndex::Clear(this: &this->activePrtModelHash);
  this->activePrtModelHash.memTag = TAG_FX;
  idHashIndex::Clear(this: &this->inactivePrtModelHash);
  this->inactivePrtModelHash.memTag = TAG_FX;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->fxStaticModels);
  idHashIndex::Clear(this: &this->activeStaticModelHash);
  this->activeStaticModelHash.memTag = TAG_FX;
  idHashIndex::Clear(this: &this->inactiveStaticModelHash);
  this->inactiveStaticModelHash.memTag = TAG_FX;
}


// ========================================================================
// ?Shutdown@idFXModelRecycler@@QAAXXZ
// EA  : 0x8270BBE0
// RVA : 0x0070BBE0
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXModelRecycler::Shutdown(idFXModelRecycler *this)
{
  int v2; // r29
  int v3; // r30
  idRenderModelParticle *pmodel; // r3
  int *hash; // r3
  int *indexChain; // r3
  int *v7; // r3
  int *v8; // r3
  int v9; // r29
  int v10; // r30
  idRenderModel *rmodel; // r3
  idFXModelRecycler::fxStaticModel_t *list; // r4

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
  hash = this->activeStaticModelHash.hash;
  if ( hash != idHashIndex::INVALID_INDEX )
    memset(Dst: hash, Val: 255, Size: 4 * this->activeStaticModelHash.hashSize);
  indexChain = this->activeStaticModelHash.indexChain;
  if ( indexChain != idHashIndex::INVALID_INDEX )
    memset(Dst: indexChain, Val: 255, Size: 4 * this->activeStaticModelHash.indexSize);
  v7 = this->inactiveStaticModelHash.hash;
  if ( v7 != idHashIndex::INVALID_INDEX )
    memset(Dst: v7, Val: 255, Size: 4 * this->inactiveStaticModelHash.hashSize);
  v8 = this->inactiveStaticModelHash.indexChain;
  if ( v8 != idHashIndex::INVALID_INDEX )
    memset(Dst: v8, Val: 255, Size: 4 * this->inactiveStaticModelHash.indexSize);
  v9 = 0;
  if ( this->fxStaticModels.num > 0 )
  {
    v10 = 0;
    do
    {
      rmodel = this->fxStaticModels.list[v10].rmodel;
      if ( rmodel != nullptr )
      {
        rmodel->unlinked = true;
        rmodel->deleteOnSync = true;
        idRenderModel::CommitThisFrame(this: rmodel);
        this->fxStaticModels.list[v10].rmodel = nullptr;
      }
      ++v9;
      ++v10;
    }
    while ( v9 < this->fxStaticModels.num );
  }
  if ( this->fxStaticModels.listStatic == 0 || this->fxStaticModels.listStatic == 2 )
  {
    list = this->fxStaticModels.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->fxStaticModels.list = nullptr;
    this->fxStaticModels.size = 0;
  }
  this->fxStaticModels.num = 0;
}


// ========================================================================
// ?ApplyFade@idFXManager@@AAAXABVidFXSingleAction@@AAVidFXAction@@AAUfxActionState_t@@HM@Z
// EA  : 0x8270BD98
// RVA : 0x0070BD98
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idFXManager::ApplyFade(
        idFXManager *this,
        const idFXSingleAction *fxaction,
        idFXAction *laction,
        fxActionState_t *state,
        __int64 time,
        double pct)
{
  double fadeInTime; // fp0
  int v10; // r5
  int v11; // r30
  int v12; // r6
  int v13; // r28
  signed int v14; // r27
  idTreeAnimator *ta; // r3
  double v16; // fp31
  int v17; // r6
  int v18; // r11
  int v19; // r6
  int v20; // r6
  char v21; // r11
  char v22; // r26
  int v23; // r6
  __int64 v24; // r7
  __int64 v25; // r10
  __int64 v26; // fp12
  int v27; // r5
  idRenderModel *v28; // r3
  const idDeclRenderParm *Color; // r24
  idVec4 *ParmBlock; // r3
  idRenderModel *v31; // r3
  float *TableColor; // r3
  double v33; // fp12
  idRenderLight *v34; // r3
  double v35; // fp5
  double v36; // fp3
  double v37; // fp1
  double v38; // fp0
  int v39; // r11
  soundChannel_t channel; // r10
  __int64 v41; // r6
  __int64 v42; // r6
  int v43; // r10
  int v44; // r8
  float v45; // r6
  float v46; // r5
  int y_low; // r11
  int z_low; // r4
  float w; // r30
  idTreeAnimator *v50; // r3
  idTreeAnimator *v51; // r3
  idVec4 v52; // [sp+50h] [-A0h] BYREF
  __int64 v53; // [sp+60h] [-90h]
  float v54; // [sp+68h] [-88h]
  float v55; // [sp+6Ch] [-84h]
  idParmBlock v56; // [sp+70h] [-80h] BYREF

  fadeInTime = fxaction->fadeInTime;
  v11 = v10;
  v13 = v12;
  v14 = HIDWORD(time);
  if ( fadeInTime == 0.0 && fxaction->fadeOutTime == 0.0 )
  {
    if ( fxaction->type == FX_RENDERPARM )
    {
      ta = this->ta;
      if ( ta != nullptr )
        idRenderModel::SetParm(this: ta, parm: fxaction->renderParmParms.declRenderParm, v4: &fxaction->color);
    }
  }
  else
  {
    v16 = 1.0;
    if ( fadeInTime != 0.0 )
    {
      v18 = *(_DWORD *)(v17 + 20);
      if ( SHIDWORD(time) <= v18 )
      {
        v53 = *(_QWORD *)(v19 + 16);
        time = v53;
        *(_QWORD *)&v52.x = *(__int64 *)((char *)&time + 4);
        v16 = (float)((float)((float)__SPAIR64__(v18, v14) - (float)*(__int64 *)((char *)&time + 4))
                    / (float)((float)v53 - (float)*(__int64 *)((char *)&time + 4)));
      }
    }
    if ( !fxaction->looping || (v21 = 0, *(_BYTE *)(v20 + 15) != 0) )
      v21 = 1;
    v22 = v21;
    if ( fxaction->fadeOutTime != 0.0 && v21 != 0 && v14 >= *(_DWORD *)(v23 + 24) )
    {
      HIDWORD(v25) = *(_DWORD *)(HIDWORD(v24) + 8);
      LODWORD(v25) = v14;
      LODWORD(time) = *(_DWORD *)(HIDWORD(v24) + 24);
      v26 = time;
      LODWORD(v24) = HIDWORD(v25);
      v53 = v24;
      v16 = (float)((float)((float)1.0 - (float)((float)((float)v25 - (float)v26) / (float)((float)v24 - (float)v26)))
                  * (float)v16);
    }
    v28 = *(idRenderModel **)(v27 + 56);
    if ( v28 != nullptr )
    {
      Color = rp->Color;
      ParmBlock = (idVec4 *)idRenderModel::GetParmBlock(this: v28);
      idParmBlock::GetVector(this: &v56, result: ParmBlock, parm: Color);
      *(float *)&v56.ops.granularity = v16;
      idRenderModel::SetParm(this: *(idRenderModel **)(v11 + 56), parm: rp->Color, v4: (const idVec4 *)&v56);
      idRenderModel::CommitThisFrame(this: *(idRenderModel **)(v11 + 56));
    }
    v31 = *(idRenderModel **)(v11 + 60);
    if ( v31 != nullptr )
    {
      idRenderModel::SetParm(this: v31, parm: rp->coverage, scalar: v16);
      idRenderModel::CommitThisFrame(this: *(idRenderModel **)(v11 + 60));
    }
    if ( *(_DWORD *)(v11 + 52) != 0 )
    {
      TableColor = (float *)idFXManager::GetTableColor(this: (idFXManager *)&v56, result: (idVec4 *)this, fxaction, pct);
      v33 = (float)(fxaction->lightParms.intensity * (float)v16);
      v35 = (float)(fxaction->color.w * TableColor[3]);
      v36 = (float)(fxaction->color.z * TableColor[2]);
      v37 = (float)(fxaction->color.y * TableColor[1]);
      v38 = (float)((float)(fxaction->color.x * *TableColor) * (float)(fxaction->lightParms.intensity * (float)v16));
      v34 = *(idRenderLight **)(v11 + 52);
      v52.w = (float)v35 * (float)(fxaction->lightParms.intensity * (float)v16);
      v52.x = v38;
      v52.z = (float)v36 * (float)v33;
      v52.y = (float)v37 * (float)v33;
      idRenderLight::SetParm(this: v34, parm: rp->lightColor, v4: &v52);
      idRenderLight::CommitThisFrame(this: *(idRenderLight **)(v11 + 52));
    }
    if ( fxaction->type == FX_SOUND && fxaction->soundParms.sound != nullptr && v22 != 0 )
    {
      v39 = *(_DWORD *)(v13 + 24);
      if ( v14 >= v39 )
      {
        LODWORD(time) = this->soundInfo.emitter;
        channel = fxaction->soundParms.channel;
        LODWORD(v41) = *(_DWORD *)(v13 + 8) - v39;
        v53 = v41;
        if ( (_DWORD)time != 0 )
        {
          if ( channel == SND_CHANNEL_ANY )
            channel = this->soundInfo.channel;
          ((void (__fastcall *)(idSoundEmitter *, soundChannel_t, double, double, double))this->soundInfo.emitter->FadeSound)(
            a1: this->soundInfo.emitter,
            a2: channel,
            a3: -60.0,
            a4: (float)((float)v42 * (float)0.001),
            a5: 0.0);
        }
      }
    }
    idLensFlareManager::ApplyFade(this: (idLensFlareManager *)(v11 + 68), f: v16);
    if ( fxaction->type == FX_RENDERPARM )
    {
      v43 = *(_DWORD *)(v11 + 152);
      v44 = *(_DWORD *)(v11 + 156);
      v45 = *(float *)(v11 + 160);
      v46 = *(float *)(v11 + 164);
      y_low = SLODWORD(fxaction->color.y);
      z_low = SLODWORD(fxaction->color.z);
      w = fxaction->color.w;
      v56.ops.list = (expOp_t *)LODWORD(fxaction->color.x);
      HIDWORD(v53) = v43;
      v56.ops.num = y_low;
      v56.ops.size = z_low;
      *(float *)&v56.ops.granularity = w;
      LODWORD(v53) = v44;
      v54 = v45;
      v55 = v46;
      v50 = this->ta;
      *(float *)&v56.constants.list = (float)((float)(*(float *)&v56.ops.list - *(float *)&v53) * (float)v16)
                                    + *(float *)&v53;
      *(float *)&v56.constants.num = (float)((float)(*(float *)&y_low - *((float *)&v53 + 1)) * (float)v16)
                                   + *((float *)&v53 + 1);
      *(float *)&v56.constants.size = (float)((float)(*(float *)&z_low - v45) * (float)v16) + v45;
      *(float *)&v56.constants.granularity = (float)((float)(w - v46) * (float)v16) + v46;
      if ( v50 != nullptr )
        idRenderModel::SetParm(
          this: v50,
          parm: fxaction->renderParmParms.declRenderParm,
          v4: (const idVec4 *)&v56.constants);
    }
    if ( fxaction->type == FX_FADE_PARENT )
    {
      v51 = this->ta;
      if ( v51 != nullptr )
        idRenderModel::SetModelFade(this: v51, v: v16);
    }
  }
}


// ========================================================================
// ?StartSound@idFXManager@@AAAHW4soundChannel_t@@PBVidSoundShader@@@Z
// EA  : 0x8270C1E8
// RVA : 0x0070C1E8
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

int __fastcall idFXManager::StartSound(idFXManager *this, soundChannel_t channel, const idSoundShader *shader)
{
  soundChannel_t v5; // r30
  idSoundEmitter *emitter; // r3
  soundShaderParms_t v8; // [sp+50h] [-C0h] BYREF

  if ( this->soundInfo.emitter != nullptr )
  {
    v5 = channel;
    if ( channel == SND_CHANNEL_ANY )
      v5 = this->soundInfo.channel;
    soundShaderParms_t::Clear(this: &v8);
    emitter = this->soundInfo.emitter;
    v8.soundShaderFlags = 0;
    emitter->StartSound(this: emitter, a2: v5, a3: shader, a4: &v8);
  }
  return 0;
}


// ========================================================================
// ??1idFXModelRecycler@@QAA@XZ
// EA  : 0x8270C260
// RVA : 0x0070C260
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXModelRecycler::~idFXModelRecycler(idFXModelRecycler *this)
{
  idFXModelRecycler::Shutdown(this);
  idHashIndex::Free(this: &this->inactiveStaticModelHash);
  idHashIndex::Free(this: &this->activeStaticModelHash);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->fxStaticModels);
  idHashIndex::Free(this: &this->inactivePrtModelHash);
  idHashIndex::Free(this: &this->activePrtModelHash);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$251270
// EA  : 0x8270C2CC
// RVA : 0x0070C2CC
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_251270()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$251271
// EA  : 0x8270C2F4
// RVA : 0x0070C2F4
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_251271()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 2064));
}


// ========================================================================
// __unwind$251272
// EA  : 0x8270C320
// RVA : 0x0070C320
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_251272()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 2096));
}


// ========================================================================
// __unwind$251273
// EA  : 0x8270C34C
// RVA : 0x0070C34C
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_251273()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 2128));
}


// ========================================================================
// __unwind$251274
// EA  : 0x8270C378
// RVA : 0x0070C378
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_251274()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 2656));
}


// ========================================================================
// __unwind$251275
// EA  : 0x8270C3A4
// RVA : 0x0070C3A4
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_251275()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 112 + 132) + 2688));
}


// ========================================================================
// ??0idFXModelRecycler@@QAA@XZ
// EA  : 0x8270C558
// RVA : 0x0070C558
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

idFXModelRecycler *__fastcall idFXModelRecycler::idFXModelRecycler(idFXModelRecycler *this)
{
  int v2; // ctr
  __int16 *p_granularity; // r9

  this->fxPrtModels.granularity = 1;
  this->fxPrtModels.num = 0;
  this->fxPrtModels.memTag = 5;
  this->fxPrtModels.size = 256;
  this->fxPrtModels.list = this->fxPrtModels.staticList;
  this->fxPrtModels.listStatic = 1;
  this->activePrtModelHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->activePrtModelHash, initialHashSize: 1024, initialIndexSize: 1024);
  this->inactivePrtModelHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->inactivePrtModelHash, initialHashSize: 1024, initialIndexSize: 1024);
  this->fxStaticModels.num = 0;
  this->fxStaticModels.size = 64;
  this->fxStaticModels.granularity = 1;
  this->fxStaticModels.memTag = 5;
  v2 = 64;
  this->fxStaticModels.list = this->fxStaticModels.staticList;
  p_granularity = &this->fxStaticModels.granularity;
  this->fxStaticModels.listStatic = 1;
  do
  {
    p_granularity += 4;
    *(_DWORD *)p_granularity = &byte_8200D768;
    --v2;
  }
  while ( v2 != 0 );
  this->activeStaticModelHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->activeStaticModelHash, initialHashSize: 1024, initialIndexSize: 1024);
  this->inactiveStaticModelHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->inactiveStaticModelHash, initialHashSize: 1024, initialIndexSize: 1024);
  idFXModelRecycler::Init(this);
  return this;
}


// ========================================================================
// __unwind$251571
// EA  : 0x8270C644
// RVA : 0x0070C644
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_251571()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$251572
// EA  : 0x8270C66C
// RVA : 0x0070C66C
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_251572()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 144 + 164) + 2064));
}


// ========================================================================
// __unwind$251573
// EA  : 0x8270C698
// RVA : 0x0070C698
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_251573()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 144 + 164) + 2096));
}


// ========================================================================
// __unwind$251574
// EA  : 0x8270C6C4
// RVA : 0x0070C6C4
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_251574()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2128));
}


// ========================================================================
// __unwind$251575
// EA  : 0x8270C6F0
// RVA : 0x0070C6F0
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_251575()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 144 + 164) + 2656));
}


// ========================================================================
// __unwind$251576
// EA  : 0x8270C71C
// RVA : 0x0070C71C
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_251576()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 144 + 164) + 2688));
}


// ========================================================================
// ?GetParticleFxModel@idFXModelRecycler@@QAAPAVidRenderModelParticle@@PBVidDeclParticle@@PAVidRenderWorld@@@Z
// EA  : 0x8270C750
// RVA : 0x0070C750
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

idRenderModelParticle *__fastcall idFXModelRecycler::GetParticleFxModel(
        idFXModelRecycler *this,
        const idMaterial *particleDecl,
        idRenderWorld *rw)
{
  const idMaterial *str; // r4
  int v7; // r29
  unsigned __int8 v8; // r9
  const idMaterial *v9; // r10
  int hashMask; // r11
  int lookupMask; // r9
  int v12; // r8
  int v13; // r30
  int v14; // r25
  idFXModelRecycler::fxPrtModel_t *v15; // r11
  int v17; // r30
  const char *v18; // r29
  int v19; // r27
  int v20; // r3
  idRenderModel *v21; // r3
  const idMaterial *v22; // r3
  int v23; // r27
  int num; // r30
  const char *v25; // r29
  int Spread; // r25
  int v27; // r3
  idRenderModelParticle *pmodel; // r30
  idSkinMapping v29; // [sp+50h] [-80h] BYREF
  idStr v30[3]; // [sp+60h] [-70h] BYREF

  str = (const idMaterial *)particleDecl->name.str;
  v7 = 0;
  v8 = HIBYTE(str->__vftable);
  if ( HIBYTE(str->__vftable) != 0 )
  {
    v9 = str;
    do
    {
      v9 = (const idMaterial *)((char *)v9 + 1);
      v7 = 31 * v7 + v8;
      v8 = HIBYTE(v9->__vftable);
    }
    while ( HIBYTE(v9->__vftable) != 0 );
  }
  hashMask = this->inactivePrtModelHash.hashMask;
  lookupMask = this->inactivePrtModelHash.lookupMask;
  v12 = hashMask & v7;
  v13 = this->inactivePrtModelHash.hash[hashMask & lookupMask & hashMask & v7];
  if ( v13 == -1 )
  {
LABEL_8:
    if ( this->fxPrtModels.num < this->fxPrtModels.size )
    {
      v29.from = str;
      idStr::idStr(this: v30, text: (const char *)str);
      idStr::SetFileExtension(this: v30, extension: "prt");
      if ( rw != nullptr
        && (v21 = rw->AllocRenderModel(this: rw, a2: v30[0].data, a3: 1, a4: -1),
            (v22 = (const idMaterial *)_RTDynamicCast(
                                         inptr: v21,
                                         VfDelta: 0,
                                         SrcType: &idRenderModel `RTTI Type Descriptor',
                                         TargetType: &idRenderModelParticle `RTTI Type Descriptor',
                                         isReference: 0)) != nullptr) )
      {
        v29.from = v22;
        v29.to = particleDecl;
        v23 = idList<cachedPageFile_t,5>::Append((idList<idSkinMapping,46> *)this, obj: &v29);
        idHashIndex::Add(this: &this->activePrtModelHash, key: this->activePrtModelHash.hashMask & v7, index: v23);
        if ( g_showFxModelRecyclerStats.valueInteger != 0 )
        {
          num = this->fxPrtModels.num;
          v25 = particleDecl->name.str;
          Spread = idHashIndex::GetSpread(this: &this->activePrtModelHash);
          v27 = idHashIndex::GetSpread(this: &this->inactivePrtModelHash);
          idLib::Printf(
            fmt: "Allocated new model %s for active list, total models allocated %d inactive models spread %d active models spread %d\n",
            v25,
            num,
            v27,
            Spread);
        }
        pmodel = this->fxPrtModels.list[v23].pmodel;
        idStr::FreeData(this: v30);
        return pmodel;
      }
      else
      {
        idLib::Warning(
          fmt: "idFXModelRecycler::GetParticleFxModel: Could not allocate a rendermodel for '%s'",
          particleDecl->name.str);
        idStr::FreeData(this: v30);
        return nullptr;
      }
    }
    else
    {
      idLib::Warning(
        fmt: "idFXModelRecycler::GetParticleFxModel: Could not allocate model %s, out of slots",
        (const char *)str);
      return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v14 = v13;
      v15 = &this->fxPrtModels.list[v13];
      if ( (const idMaterial *)v15->pDecl == particleDecl && v15->pmodel != nullptr )
        break;
      v13 = this->inactivePrtModelHash.indexChain[lookupMask & v13];
      if ( v13 == -1 )
        goto LABEL_8;
    }
    idHashIndex::Remove(this: &this->inactivePrtModelHash, key: v12, index: v13);
    idHashIndex::Add(this: &this->activePrtModelHash, key: this->activePrtModelHash.hashMask & v7, index: v13);
    if ( g_showFxModelRecyclerStats.valueInteger != 0 )
    {
      v17 = this->fxPrtModels.num;
      v18 = particleDecl->name.str;
      v19 = idHashIndex::GetSpread(this: &this->activePrtModelHash);
      v20 = idHashIndex::GetSpread(this: &this->inactivePrtModelHash);
      idLib::Printf(
        fmt: "Found model %s in inactive list, total models allocated %d inactive models spread %d active models spread %d\n",
        v18,
        v17,
        v20,
        v19);
    }
    return this->fxPrtModels.list[v14].pmodel;
  }
}


// ========================================================================
// __unwind$251683
// EA  : 0x8270C9E4
// RVA : 0x0070C9E4
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_251683()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 96));
}


// ========================================================================
// ?GetViewCallbacks@idFXManager@@AAAABV?$idList@PAVidViewCallbacks@@$0GN@@@XZ
// EA  : 0x8270CA18
// RVA : 0x0070CA18
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

idList<idViewCallbacks *,5> *__fastcall idFXManager::GetViewCallbacks(idFXManager *this)
{
  idGame *v1; // r3
  idGame *v2; // r3

  if ( (_S13_11 & 1) == 0 )
  {
    _S13_11 |= 1u;
    emptyFallBackList.memTag = 5;
    emptyFallBackList.list = nullptr;
    emptyFallBackList.granularity = 0;
    emptyFallBackList.listStatic = 0;
    emptyFallBackList.size = 0;
    emptyFallBackList.num = 0;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&emptyFallBackList);
    atexit(func: (void (__fastcall *)())_idFXManager::GetViewCallbacks_::_2_::_dynamic_atexit_destructor_for__emptyFallBackList__);
  }
  if ( common->Game(this: common) == nullptr )
    return &emptyFallBackList;
  v1 = common->Game(this: common);
  if ( !v1->IsGameActive(this: v1) )
    return &emptyFallBackList;
  v2 = common->Game(this: common);
  return v2->GetViewCallbacks(this: v2);
}


// ========================================================================
// __unwind$251837
// EA  : 0x8270CB0C
// RVA : 0x0070CB0C
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_251837()
{
  _S13_11 &= ~1u;
}


// ========================================================================
// ?StopAction@idFXManager@@AAAXHH_N_N@Z
// EA  : 0x8270CB30
// RVA : 0x0070CB30
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::StopAction(
        idFXManager *this,
        const int i,
        int time,
        bool stopImmediate,
        const bool recycleResources)
{
  idFXSingleAction *v9; // r24
  fxActionState_t *v10; // r22
  idFXAction *v11; // r28
  int v12; // r4
  idList<idViewCallbacks *,5> *ViewCallbacks; // r3
  idList<idViewCallbacks *,5> *v14; // r31
  double fadeOutTime; // fp2
  idRenderLight *rLight; // r3
  int v17; // r26
  int viewCallbacksID; // r27
  int v19; // r29
  idRenderModelParticle *rParticle; // r31
  idRenderModel *v21; // r31
  idRenderModel *rModel; // r3
  idRibbon *ribbon; // r3
  int RemainingTime; // r31
  int v25; // r29
  int v26; // r30
  idViewCallbacks *v27; // r3
  int v28; // r29
  int v29; // r30
  idSoundEmitter *emitter; // r11
  soundChannel_t channel; // r4
  int v32; // r29
  int v33; // r30
  int v34; // r26
  int v35; // r27
  int v36; // r29
  int v37; // r30
  idViewCallbacks *v38; // r3
  float v39[6]; // [sp+58h] [-A8h] BYREF
  float v40[6]; // [sp+70h] [-90h] BYREF

  v9 = &this->fxDecl->events.list[i];
  v10 = &this->actionState.list[i];
  v11 = &this->actions.list[i];
  ViewCallbacks = idFXManager::GetViewCallbacks(this);
  v14 = ViewCallbacks;
  if ( v10->startTime >= 0 )
  {
    fadeOutTime = v9->fadeOutTime;
    if ( fadeOutTime <= 0.0
      || v9->type == FX_SOUND
      || stopImmediate
      || v10->forceStop
      || v10->stopTime - time <= 0 && !v9->looping )
    {
      switch ( v9->type )
      {
        case FX_LIGHT:
          rLight = v11->rLight;
          if ( rLight != nullptr )
            idRenderLight::Unlink(this: rLight);
          goto LABEL_79;
        case FX_PARTICLE:
          if ( v11->rParticle == nullptr )
            goto LABEL_79;
          if ( !v9->particleParms.isScreenPrt )
            goto LABEL_23;
          v17 = 0;
          if ( ViewCallbacks->num <= 0 )
            goto LABEL_23;
          viewCallbacksID = v11->viewCallbacksID;
          v19 = 0;
          break;
        case FX_DECAL2:
          rModel = v11->rModel;
          if ( rModel != nullptr )
          {
            rModel->unlinked = true;
            rModel->deleteOnSync = true;
            idRenderModel::CommitThisFrame(this: rModel);
            v11->rModel = nullptr;
          }
          goto LABEL_79;
        case FX_MODEL:
          v21 = v11->rModel;
          if ( v21 != nullptr )
          {
            if ( !v21->unlinked )
            {
              idRenderModel::CommitThisFrame(this: v11->rModel);
              v21->unlinked = true;
            }
            if ( recycleResources )
            {
              idFXModelRecycler::RecycleStaticFxModel(
                this: &this->gameLibEffects->fxModelRecycler,
                name: &v9->modelParms.modelName,
                model: v11->rModel);
              v11->rModel = nullptr;
            }
          }
          goto LABEL_79;
        case FX_SOUND:
          if ( v9->soundParms.sound != nullptr )
          {
            emitter = this->soundInfo.emitter;
            channel = v9->soundParms.channel;
            if ( fadeOutTime <= 0.0 )
            {
              if ( emitter != nullptr )
              {
                if ( channel == SND_CHANNEL_ANY )
                  channel = this->soundInfo.channel;
                this->soundInfo.emitter->StopSound(this: this->soundInfo.emitter, a2: channel);
              }
            }
            else if ( emitter != nullptr )
            {
              if ( channel == SND_CHANNEL_ANY )
                channel = this->soundInfo.channel;
              ((void (__fastcall *)(idSoundEmitter *, soundChannel_t, double))this->soundInfo.emitter->FadeSound)(
                a1: this->soundInfo.emitter,
                a2: channel,
                a3: -60.0);
            }
          }
          goto LABEL_79;
        case FX_SCREEN_SHAKE:
          v25 = 0;
          if ( ViewCallbacks->num > 0 )
          {
            v26 = 0;
            do
            {
              if ( v11->viewCallbacksID < 0 || v11->viewCallbacksID == v14->list[v26]->GetViewID(this: v14->list[v26]) )
              {
                v27 = v14->list[v26];
                v39[0] = 0.0;
                v39[1] = 0.0;
                v39[2] = 0.0;
                ((void (__fastcall *)(idViewCallbacks *, int, float *, idVec3 *, double))v27->ApplyScreenShake)(
                  a1: v27,
                  a2: v12,
                  a3: v39,
                  a4: &vec3_origin,
                  a5: 0.0);
              }
              ++v25;
              ++v26;
            }
            while ( v25 < v14->num );
          }
          goto LABEL_79;
        case FX_CONTROLLER_SHAKE:
          v28 = 0;
          if ( ViewCallbacks->num > 0 )
          {
            v29 = 0;
            do
            {
              if ( v11->viewCallbacksID < 0 || v11->viewCallbacksID == v14->list[v29]->GetViewID(this: v14->list[v29]) )
                v14->list[v29]->ApplyControllerShake(this: v14->list[v29], a2: 0.0, a3: 0.0, a4: 0.0, a5: 0.0);
              ++v28;
              ++v29;
            }
            while ( v28 < v14->num );
          }
          goto LABEL_79;
        case FX_ENV_OVERRIDE:
          v32 = 0;
          if ( ViewCallbacks->num > 0 )
          {
            v33 = 0;
            do
            {
              if ( v11->viewCallbacksID < 0 || v11->viewCallbacksID == v14->list[v33]->GetViewID(this: v14->list[v33]) )
                v14->list[v33]->ApplyDynEnvOverride(this: v14->list[v33], a2: nullptr, a3: v9->fadeOutTime);
              ++v32;
              ++v33;
            }
            while ( v32 < v14->num );
          }
          goto LABEL_79;
        case FX_ENV_CHANGE:
          v34 = 0;
          if ( ViewCallbacks->num > 0 )
          {
            v35 = 0;
            do
            {
              if ( v11->viewCallbacksID < 0 || v11->viewCallbacksID == v14->list[v35]->GetViewID(this: v14->list[v35]) )
              {
                v36 = 0;
                if ( v9->envParms.envRenderParm.num > 0 )
                {
                  v37 = 0;
                  do
                  {
                    v38 = v14->list[v35];
                    v40[2] = 0.0;
                    v40[3] = 0.0;
                    v40[0] = 0.0;
                    v40[1] = 0.0;
                    v38->ApplyDynEnvParmOverride(
                      this: v38,
                      a2: v9->envParms.envRenderParm.list[v37].parm,
                      a3: (const idVec4 *)v40,
                      a4: true,
                      a5: v9->fadeOutTime);
                    ++v36;
                    ++v37;
                  }
                  while ( v36 < v9->envParms.envRenderParm.num );
                }
              }
              ++v34;
              ++v35;
            }
            while ( v34 < v14->num );
          }
          goto LABEL_79;
        case FX_FLARE:
          idLensFlareManager::StopFlare(this: &v11->flareManager);
          goto LABEL_79;
        case FX_RIBBON:
          ribbon = v11->ribbonManager.ribbon;
          if ( ribbon == nullptr || (RemainingTime = idRibbon::GetRemainingTime(this: ribbon, currentTime: time)) <= 500 )
            RemainingTime = 500;
          idRibbonManager::StopRibbon(this: &v11->ribbonManager);
          if ( v10->forceStop )
            goto LABEL_79;
          v10->stopTime = RemainingTime + time;
          v10->forceStop = true;
          return;
        default:
          goto LABEL_79;
      }
      while ( viewCallbacksID >= 0 )
      {
        viewCallbacksID = v11->viewCallbacksID;
        if ( viewCallbacksID == v14->list[v19]->GetViewID(this: v14->list[v19]) )
          break;
        ++v17;
        ++v19;
        if ( v17 >= v14->num )
          goto LABEL_23;
      }
      v14->list[v17]->RemoveScreenParticle(
        this: v14->list[v17],
        a2: v11->screenPrtHandle,
        a3: (int)(float)(v9->fadeOutTime * (float)1000.0));
      v11->screenPrtHandle = -1;
LABEL_23:
      rParticle = v11->rParticle;
      if ( !rParticle->unlinked )
      {
        idRenderModel::CommitThisFrame(this: v11->rParticle);
        rParticle->unlinked = true;
      }
      if ( recycleResources )
      {
        idFXModelRecycler::RecycleParticleFxModel(
          this: &this->gameLibEffects->fxModelRecycler,
          particleDecl: v9->particleParms.declPrt,
          model: v11->rParticle);
        v11->rParticle = nullptr;
      }
LABEL_79:
      if ( v9->triggered )
        v10->hidden = true;
      v10->started = false;
      v10->startTime = -1;
      v10->stopTime = 0;
      v10->fadeInStartTime = -1;
      v10->fadeInEndTime = 0;
      v10->fadeOutStartTime = 0;
      v10->forceStop = false;
      v11->lastParticleDropPos.z = 0.0;
      v11->lastParticleDropPos.y = 0.0;
      v11->lastParticleDropPos.x = 0.0;
      v11->randomAngles = ang_zero;
      v11->startAxis = mat3_identity;
      v11->startOrg = vec3_origin;
    }
    else
    {
      if ( time < v10->fadeOutStartTime )
      {
        v10->fadeOutStartTime = time;
        v10->stopTime = (int)(float)(v9->fadeOutTime * (float)1000.0) + time;
      }
      v10->forceStop = true;
    }
  }
}


// ========================================================================
// ?RestartAction@idFXManager@@AAAXHH@Z
// EA  : 0x8270D210
// RVA : 0x0070D210
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idFXManager::RestartAction(idFXManager *this, int i, int time)
{
  idFXAction *v3; // r31
  int v5; // ctr
  idFXSingleAction *v6; // r30
  fxActionState_t *v7; // r28
  float *v9; // r10
  idFXAction *p_z; // r11
  int v11; // r2 OVERLAPPED
  idRandom2 *p_random; // r27
  double v13; // fp13
  unsigned int v14; // r6
  double v15; // fp12
  double v16; // fp11
  __int64 v17; // r4
  int v18; // r23
  int num; // r11
  double v20; // fp0
  unsigned int v21; // r6
  double v22; // fp11
  double v23; // fp2
  __int128 v24; // r5
  double v25; // fp8
  double v26; // fp12
  double v27; // fp10
  double v28; // fp9
  unsigned int v29; // r6
  int v30; // r9
  double v31; // fp12
  double v32; // fp10
  double v33; // fp8
  double v34; // fp7
  double v35; // fp1
  float x; // [sp+58h] [-A8h]
  float y; // [sp+5Ch] [-A4h]
  float z; // [sp+60h] [-A0h]
  float v39[11]; // [sp+6Ch] [-94h] BYREF

  v3 = &this->actions.list[i];
  v5 = 9;
  x = v3->startOrg.x;
  y = v3->startOrg.y;
  z = v3->startOrg.z;
  v6 = &this->fxDecl->events.list[i];
  v7 = &this->actionState.list[i];
  v9 = v39;
  p_z = (idFXAction *)&v3->startOrg.z;
  do
  {
    p_z = (idFXAction *)((char *)p_z + 4);
    *++v9 = *(float *)&p_z->tagIndex;
    --v5;
  }
  while ( v5 != 0 );
  idFXManager::StopAction(this, i, time, stopImmediate: true, recycleResources: false);
  p_random = &this->random;
  v13 = v6->delay.x;
  v14 = 1664525 * p_random->seed + 1013904223;
  p_random->seed = v14;
  v15 = v6->delay.y;
  v16 = v6->delay.x;
  LODWORD(v17) = (v14 >> 10) & 0x7FFF;
  v3->tagIndex = 0;
  v18 = (int)(float)((float)((float)((float)((float)v17 * (float)((float)v15 - (float)v16)) * (float)0.000030518509)
                           + (float)v13)
                   * (float)1000.0);
  if ( v6->multiTagUseType == FX_MULTI_TAG_USE_RND )
  {
    num = v3->tagData.num;
    if ( num > 1 )
      v3->tagIndex = idRandom2::RandomInt(this: p_random, max: num - 1);
  }
  v20 = v6->rndRotY.x;
  v21 = 1664525 * p_random->seed + 1013904223;
  p_random->seed = v21;
  v22 = v6->rndRotZ.x;
  v23 = (float)(v6->rndRotY.y - v6->rndRotY.x);
  DWORD2(v24) = 1664525 * v21 + 1013904223;
  LODWORD(v24) = (v21 >> 10) & 0x7FFF;
  p_random->seed = *(_DWORD *)((unsigned int)&v24 + 8);
  DWORD1(v24) = (DWORD2(v24) >> 10) & 0x7FFF;
  v25 = v6->rndRotX.x;
  v26 = (double)(__int64)v24;
  v27 = v6->rndRotZ.y;
  v28 = v6->rndRotZ.x;
  v29 = 1664525 * DWORD2(v24) + 1013904223;
  p_random->seed = v29;
  DWORD2(v24) = (v29 >> 10) & 0x7FFF;
  v3->randomAngles.roll = (float)((float)((float)*(__int64 *)((char *)&v24 + 4) * (float)(v6->rndRotX.y - v6->rndRotX.x))
                                * (float)0.000030518509)
                        + (float)v25;
  v3->randomAngles.pitch = (float)((float)((float)v26 * (float)v23) * (float)0.000030518509) + (float)v20;
  v3->randomAngles.yaw = (float)((float)((float)*(__int64 *)(&v11 - 1) * (float)((float)v27 - (float)v28))
                               * (float)0.000030518509)
                       + (float)v22;
  v7->startDelay = v18;
  v7->startTime = time;
  v30 = (int)(float)(1000.0 * v6->duration) + v18 + time;
  v7->fadeInStartTime = time;
  v7->stopTime = v30;
  v7->fadeInEndTime = (int)(float)(v6->fadeInTime * 1000.0) + v18 + time;
  v31 = (float)(v6->duration - v6->fadeOutTime);
  v7->shouldTrigger = true;
  v7->forceStop = false;
  v7->started = false;
  v32 = v39[1];
  v7->fadeOutStartTime = (int)(float)((float)v31 * (float)1000.0) + v18 + time;
  v3->lastParticleDropPos.z = 0.0;
  v3->lastParticleDropPos.y = 0.0;
  v3->lastParticleDropPos.x = 0.0;
  v3->screenPrtHandle = -1;
  v3->startAxis.mat[0].x = v32;
  v33 = v39[2];
  v34 = v39[3];
  v3->startAxis.mat[1].x = v39[4];
  v3->startAxis.mat[0].y = v33;
  v3->startAxis.mat[0].z = v34;
  v3->startAxis.mat[1].y = v39[5];
  v3->startAxis.mat[1].z = v39[6];
  v3->startAxis.mat[2].x = v39[7];
  v35 = v39[9];
  v3->startAxis.mat[2].y = v39[8];
  v3->startAxis.mat[2].z = v35;
  v3->startOrg.x = x;
  v3->startOrg.y = y;
  v3->startOrg.z = z;
}


// ========================================================================
// ?Serialize@idFXManager@@QAAXAAVidSerializer@@@Z
// EA  : 0x8270D520
// RVA : 0x0070D520
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::Serialize(idFXManager *this, idSerializer *ser)
{
  int actionBufferPos; // r23
  idBitMsg *msg; // r3
  idBitMsg *v6; // r3
  idBitMsg *v7; // r3
  int v8; // r27
  int v9; // r25
  int v10; // r24
  idFXManager::fxActionCall_t *actionBuffer; // r30
  int i; // r28
  idBitMsg *v13; // r3
  __int64 v14; // r8
  idBitMsg *v15; // r3
  int condition; // r29
  int actionType; // r29
  idBitMsg *v18; // r3
  int extraCondition; // r29
  idBitMsg *v20; // r3
  idBitMsg *v21; // r3
  idBitMsg *v22; // r3
  bool immediate; // r29
  idBitMsg *v24; // r3
  int v25; // r4
  int v26; // r6
  const idDeclFX *v27; // r11
  const char *v28; // r8
  int j; // r31
  idFXManager::fxActionCall_t *v30; // r30
  const enumValueInfo_t *EnumValueInfo; // r3
  const idDeclFX *fxDecl; // r11
  const char *str; // r4

  actionBufferPos = this->actionBufferPos;
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: actionBufferPos, numBits: 32);
  else
    actionBufferPos = idBitMsg::ReadBits(this: msg, numBits: 32);
  v6 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v6, value: this->allowSurfaceOnlyInViewID, numBits: 32);
  else
    this->allowSurfaceOnlyInViewID = idBitMsg::ReadBits(this: v6, numBits: 32);
  v7 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v7, value: this->suppressSurfaceInViewID, numBits: 32);
  else
    this->suppressSurfaceInViewID = idBitMsg::ReadBits(this: v7, numBits: 32);
  v8 = 32 - _cntlzw(0xC6u);
  v9 = 32 - _cntlzw(3u);
  v10 = 32 - _cntlzw(0x10000u);
  actionBuffer = this->actionBuffer;
  for ( i = 8; i != 0; --i )
  {
    v13 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteQuantizedVector<idVec3,32768,12>(this: v13, v: &actionBuffer->org);
    else
      idBitMsg::ReadQuantizedVector<idVec3,32768,12>(this: v13, v: &actionBuffer->org);
    idSerializer::SerializeQ(this: ser, axis: (idQuat *)&actionBuffer->axis, bits: 15, a4: v14);
    v15 = ser->msg;
    condition = actionBuffer->condition;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v15, value: actionBuffer->condition, numBits: v8);
    else
      condition = idBitMsg::ReadBits(this: v15, numBits: v8);
    actionBuffer->condition = condition;
    actionType = actionBuffer->actionType;
    v18 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v18, value: actionBuffer->actionType, numBits: v9);
    else
      actionType = idBitMsg::ReadBits(this: v18, numBits: v9);
    actionBuffer->actionType = actionType;
    extraCondition = actionBuffer->extraCondition;
    v20 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v20, value: actionBuffer->extraCondition, numBits: v10);
    else
      extraCondition = idBitMsg::ReadBits(this: v20, numBits: v10);
    actionBuffer->extraCondition = extraCondition;
    v21 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v21, value: actionBuffer->tagIdx, numBits: 32);
    else
      actionBuffer->tagIdx = idBitMsg::ReadBits(this: v21, numBits: 32);
    v22 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v22, value: actionBuffer->viewCallbacksID, numBits: 32);
    else
      actionBuffer->viewCallbacksID = idBitMsg::ReadBits(this: v22, numBits: 32);
    immediate = actionBuffer->immediate;
    v24 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v24, value: actionBuffer->immediate, numBits: 1);
    else
      immediate = (_cntlzw(idBitMsg::ReadBits(this: v24, numBits: 1) - 1) & 0x20) != 0;
    actionBuffer->immediate = immediate;
    ++actionBuffer;
  }
  v25 = this->actionBufferPos;
  v26 = actionBufferPos - v25;
  this->serializeActionCount = actionBufferPos - v25;
  if ( actionBufferPos - v25 <= 8 )
  {
    if ( v26 < 0 )
    {
      fxDecl = this->fxDecl;
      if ( fxDecl != nullptr )
        str = fxDecl->name.str;
      else
        str = "NULL";
      idLib::Warning(fmt: "Client got ahead of FX serialization. %s", str);
      this->actionBufferPos = actionBufferPos;
      this->serializeActionCount = 0;
    }
  }
  else
  {
    v27 = this->fxDecl;
    if ( v27 != nullptr )
      v28 = v27->name.str;
    else
      v28 = "NULL";
    idLib::Warning(
      fmt: "Too many FX Actions serialized [actionBufferPos %d -> newActionBufferPos %d ] (%d), dropping all but last %d! %s",
      v25,
      actionBufferPos,
      v26,
      8,
      v28);
    this->actionBufferPos = actionBufferPos - 8;
    this->serializeActionCount = 8;
    if ( g_debugFX.valueInteger > 2 )
    {
      for ( j = 0; j < 8; ++j )
      {
        v30 = &this->actionBuffer[(this->actionBufferPos - j) % 8];
        EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                          this: typeInfoTools,
                          enumName: "fxCondition_t",
                          value: v30->condition,
                          defaultIfNotFound: true);
        idLib::Printf(
          fmt: "Action[%d] condition: %s actionType: %d \n",
          this->actionBufferPos - j,
          EnumValueInfo->name,
          v30->actionType);
      }
      idLib::Printf(fmt: "\n");
    }
  }
}


// ========================================================================
// ?GetStaticFxModel@idFXModelRecycler@@QAAPAVidRenderModel@@ABVidAtomicString@@PAVidRenderWorld@@@Z
// EA  : 0x8270DB40
// RVA : 0x0070DB40
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

idRenderModel *__fastcall idFXModelRecycler::GetStaticFxModel(
        idFXModelRecycler *this,
        const idAtomicString *name,
        idRenderWorld *rw)
{
  const char *str; // r10
  int v7; // r29
  unsigned __int8 v8; // r9
  int hashMask; // r11
  idHashIndex *p_inactiveStaticModelHash; // r27
  int v11; // r28
  int v12; // r30
  int v13; // r26
  int v15; // r30
  const char *v16; // r29
  int v17; // r28
  int v18; // r3
  idRenderModel *v19; // r3
  idStaticList<idFXModelRecycler::fxStaticModel_t,64> *p_fxStaticModels; // r28
  int v21; // r26
  idHashIndex *p_activeStaticModelHash; // r3
  int num; // r31
  const char *v24; // r30
  int Spread; // r29
  int v26; // r3
  idFXModelRecycler::fxStaticModel_t v27; // [sp+50h] [-50h] BYREF

  str = name->str;
  v7 = 0;
  v8 = *name->str;
  if ( v8 != 0 )
  {
    do
    {
      ++str;
      v7 = 31 * v7 + v8;
      v8 = *str;
    }
    while ( *str != 0 );
  }
  hashMask = this->inactiveStaticModelHash.hashMask;
  p_inactiveStaticModelHash = &this->inactiveStaticModelHash;
  v11 = hashMask & v7;
  v12 = this->inactiveStaticModelHash.hash[hashMask & this->inactiveStaticModelHash.lookupMask & hashMask & v7];
  if ( v12 == -1 )
  {
LABEL_7:
    if ( this->fxStaticModels.num < this->fxStaticModels.size )
    {
      if ( rw != nullptr && (v19 = rw->AllocRenderModel(this: rw, a2: name->str, a3: 1, a4: -1)) != nullptr )
      {
        p_fxStaticModels = &this->fxStaticModels;
        v27.modelName = (idAtomicString)name->str;
        v27.rmodel = v19;
        v21 = idList<idFXModelRecycler::fxStaticModel_t,5>::Append(this: &this->fxStaticModels, obj: &v27);
        idHashIndex::Add(this: &this->activeStaticModelHash, key: this->activeStaticModelHash.hashMask & v7, index: v21);
        if ( g_showFxModelRecyclerStats.valueInteger != 0 )
        {
          p_activeStaticModelHash = &this->activeStaticModelHash;
          num = this->fxStaticModels.num;
          v24 = name->str;
          Spread = idHashIndex::GetSpread(this: p_activeStaticModelHash);
          v26 = idHashIndex::GetSpread(this: p_inactiveStaticModelHash);
          idLib::Printf(
            fmt: "Allocated new model %s for active list, total models allocated %d inactive models spread %d active models spread %d\n",
            v24,
            num,
            v26,
            Spread);
        }
        return p_fxStaticModels->list[v21].rmodel;
      }
      else
      {
        idLib::Warning(
          fmt: "idFXModelRecycler::GetParticleFxModel: Could not allocate a rendermodel for '%s'",
          name->str);
        return nullptr;
      }
    }
    else
    {
      idLib::Warning(fmt: "idFXModelRecycler::GetParticleFxModel: Could not allocate model %s, out of slots", name->str);
      return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v13 = v12;
      if ( idStr::Cmp(s1: this->fxStaticModels.list[v12].modelName.str, s2: name->str) == 0
        && this->fxStaticModels.list[v13].rmodel != nullptr )
      {
        break;
      }
      v12 = this->inactiveStaticModelHash.indexChain[this->inactiveStaticModelHash.lookupMask & v12];
      if ( v12 == -1 )
        goto LABEL_7;
    }
    idHashIndex::Remove(this: &this->inactiveStaticModelHash, key: v11, index: v12);
    idHashIndex::Add(this: &this->activeStaticModelHash, key: this->activeStaticModelHash.hashMask & v7, index: v12);
    if ( g_showFxModelRecyclerStats.valueInteger != 0 )
    {
      v15 = this->fxStaticModels.num;
      v16 = name->str;
      v17 = idHashIndex::GetSpread(this: &this->activeStaticModelHash);
      v18 = idHashIndex::GetSpread(this: &this->inactiveStaticModelHash);
      idLib::Printf(
        fmt: "Found model %s in inactive list, total models allocated %d inactive models spread %d active models spread %d\n",
        v16,
        v15,
        v18,
        v17);
    }
    return this->fxStaticModels.list[v13].rmodel;
  }
}


// ========================================================================
// ?StopActions@idFXManager@@AAAXHW4fxCondition_t@@W4fxExtraCondition_t@@_N2@Z
// EA  : 0x8270DDA8
// RVA : 0x0070DDA8
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::StopActions(
        idFXManager *this,
        int time,
        int stopCondition,
        const fxExtraCondition_t extraCondition,
        bool stopAll,
        bool stopImmediate)
{
  int num; // r10
  const idDeclFX *fxDecl; // r11
  int v13; // r9
  int v14; // r28
  BOOL v15; // r21
  int v16; // r30
  int v17; // r27
  char v18; // r6
  int v19; // r10
  idFXSingleAction *v20; // r8
  int v21; // r9
  int v22; // r11
  int v23; // r10
  int v24; // r9
  fxExtraCondition_t *list; // r8
  int v26; // r11
  int i; // ctr
  fxExtraCondition_t v28; // r10
  const idDeclFX *v29; // r10
  const char *str; // r19
  idFXSingleAction *v31; // r31
  const char *v32; // r18
  const char *v33; // r3

  num = this->actions.num;
  if ( num != 0 )
  {
    fxDecl = this->fxDecl;
    v13 = fxDecl->events.num;
    if ( num == v13 )
    {
      v14 = 0;
      if ( v13 > 0 )
      {
        v15 = stopAll;
        v16 = 0;
        v17 = 0;
        do
        {
          v18 = 0;
          v19 = 0;
          v20 = &fxDecl->events.list[v16];
          v21 = v20->stopCondition.num;
          if ( v21 > 0 )
          {
            v22 = 0;
            while ( v20->stopCondition.list[v22] != stopCondition )
            {
              ++v19;
              ++v22;
              if ( v19 >= v21 )
                goto LABEL_11;
            }
            v18 = 1;
          }
LABEL_11:
          v23 = v20->extraCondition.num;
          v24 = 0;
          if ( v23 > 0 )
          {
            list = v20->extraCondition.list;
            v26 = 0;
            for ( i = v23; i != 0; --i )
            {
              v28 = list[v26++];
              v24 |= v28;
            }
          }
          if ( v15 || v18 != 0 && v24 == extraCondition )
          {
            if ( g_debugFX.valueInteger == 1 && this->actionState.list[v17].startTime > 0 )
            {
              v29 = this->fxDecl;
              str = v29->name.str;
              v31 = &v29->events.list[v16];
              v32 = idDeclFX::FXConditionToName(condition: stopCondition);
              v33 = idDeclFX::FXActionTypeToName(type: v31->type);
              idLib::Printf(
                fmt: "Stopping FX on %s, event %d, action type %s, start condition %s\n",
                str,
                v14,
                v33,
                v32);
            }
            idFXManager::StopAction(this, i: v14, time, stopImmediate, recycleResources: true);
          }
          fxDecl = this->fxDecl;
          ++v14;
          ++v17;
          ++v16;
        }
        while ( v14 < fxDecl->events.num );
      }
    }
  }
}


// ========================================================================
// ?LocalStopFX@idFXManager@@QAAXHW4fxCondition_t@@_N@Z
// EA  : 0x8270DF38
// RVA : 0x0070DF38
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::LocalStopFX(idFXManager *this, int time, int stop, bool immediateStop)
{
  if ( g_skipFXManager.valueInteger == 0 && this->initialized )
    idFXManager::StopActions(
      this,
      time,
      stopCondition: stop,
      extraCondition: FX_EXTRA_COND_NONE,
      stopAll: false,
      stopImmediate: immediateStop);
}


// ========================================================================
// ?LocalStopAllFX@idFXManager@@QAAXH_N@Z
// EA  : 0x8270DF70
// RVA : 0x0070DF70
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::LocalStopAllFX(idFXManager *this, int time, bool immediateStop)
{
  if ( g_skipFXManager.valueInteger == 0 && this->initialized )
    idFXManager::StopActions(
      this,
      time,
      stopCondition: 0,
      extraCondition: FX_EXTRA_COND_NONE,
      stopAll: true,
      stopImmediate: immediateStop);
}


// ========================================================================
// ?InternalStopFX@idFXManager@@AAAXABUfxActionCall_t@1@@Z
// EA  : 0x8270DFA8
// RVA : 0x0070DFA8
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::InternalStopFX(idFXManager *this, const idFXManager::fxActionCall_t *actionCall)
{
  idFXManager::StopActions(
    this,
    time: actionCall->time,
    stopCondition: actionCall->condition,
    extraCondition: (const fxExtraCondition_t)actionCall->extraCondition,
    stopAll: (_cntlzw(actionCall->actionType - 2) & 0x20) != 0,
    stopImmediate: actionCall->immediate);
  ++this->actionBufferPos;
}


// ========================================================================
// ?StartAction@idFXManager@@AAAXHABVidVec3@@ABVidMat3@@HH@Z
// EA  : 0x8270E228
// RVA : 0x0070E228
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::StartAction(
        idFXManager *this,
        const int i,
        const idVec3 *org,
        const idMat3 *axis,
        unsigned int time,
        int tagIdx)
{
  unsigned __int64 v12; // r6
  const char *v13; // r7
  fxActionState_t *v14; // r21
  idFXSingleAction *v15; // r30
  idFXAction *v16; // r29
  idGame *v17; // r3
  int v18; // r3
  _DWORD *v19; // r25
  int v20; // r23
  int viewCallbacksID; // r26
  int v22; // r27
  int startDelay; // r11
  __int64 v24; // r5
  int v25; // r6
  __int64 v26; // r8
  double v27; // fp5
  idRandom2 *p_random; // r27
  unsigned int v29; // r8
  double x; // fp13
  double v31; // fp10
  double v32; // fp8
  double v33; // fp7
  unsigned int v34; // r10
  double y; // fp6
  double v36; // fp4
  double v37; // fp1
  double v38; // fp3
  double v39; // fp9
  double v40; // fp12
  double v41; // fp3
  float v42; // r7
  int *v43; // r10
  float z; // r6
  _DWORD *p_z; // r11
  int v46; // ctr
  int *v47; // r10
  int v48; // ctr
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *p_parentJoint; // r11
  idTreeAnimator *ta; // r3
  fxRotationType_t rotationType; // r11
  double v52; // fp13
  double v53; // fp12
  double v54; // fp11
  double v55; // fp10
  double v56; // fp9
  double v57; // fp8
  double v58; // fp7
  double v59; // fp6
  idMat3 *v60; // r3
  float *v61; // r3
  double v62; // fp0
  double v63; // fp13
  double v64; // fp12
  double v65; // fp11
  double v66; // fp10
  double v67; // fp9
  double v68; // fp8
  double v69; // fp7
  double v70; // fp6
  double v71; // fp6
  double v72; // fp12
  double v73; // fp10
  double v74; // fp9
  double v75; // fp8
  unsigned int type; // r11
  unsigned __int64 v77; // r6
  const char *v78; // r7
  idRenderWorld *v79; // r11
  int v80; // r3
  idPLog *y_low; // r8
  float v82; // r9
  idRenderLight *rLight; // r11
  float *TableColor; // r3
  double v85; // fp13
  float *v86; // r11
  double v87; // fp0
  int v88; // r5
  double v89; // fp12
  double v90; // fp11
  double v91; // fp10
  double v92; // fp9
  double v93; // fp8
  double v94; // fp0
  double v95; // fp7
  double v96; // fp13
  float *p_w; // r7
  double v98; // fp4
  int *v99; // r9
  double v100; // fp12
  int v101; // ctr
  double v102; // fp11
  idVec3 *mat; // r11
  double v104; // fp9
  double v105; // fp8
  double v106; // fp7
  double v107; // fp6
  idAutoRenderParms *v108; // r10
  double intensity; // fp1
  double v110; // fp12
  double v111; // fp11
  idRenderLight *v112; // r3
  unsigned __int64 v113; // r6
  const char *v114; // r7
  const idSoundShader *sound; // r11
  __int64 v116; // r8
  soundChannel_t channel; // r4
  soundChannel_t v118; // r4
  unsigned __int64 v119; // r6
  const char *v120; // r7
  idRenderWorld *rw; // r5
  idRenderModelParticle *rParticle; // r11
  float *v123; // r11
  double size; // fp11
  double v125; // fp10
  double v126; // fp8
  float w; // r3
  double v128; // fp9
  float v129; // r6
  double v130; // fp7
  int v131; // r8
  __int64 v132; // r5
  idRenderModel *v133; // r3
  idRenderModel *v134; // r3
  double v135; // fp1
  idRenderModelParticle *v136; // r11
  char v137; // r11
  idRenderModelParticle *v138; // r30
  unsigned __int64 v139; // r6
  const char *v140; // r7
  idRenderWorld *v141; // r5
  idRenderModel *StaticFxModel; // r3
  float v143; // r8
  double v144; // fp0
  int x_low; // r7
  double v146; // fp13
  float v147; // r6
  double v148; // fp12
  double v149; // fp11
  float v150; // r6
  double v151; // fp0
  int v152; // r10
  double v153; // fp13
  float v154; // r8
  double v155; // fp12
  double v156; // fp11
  idRenderModel *v157; // r11
  float *v158; // r11
  double v159; // fp11
  idRenderModel *v160; // r11
  idRenderModel *v161; // r30
  unsigned __int64 v162; // r6
  const char *v163; // r7
  idRenderWorld *v164; // r10
  int v165; // r3
  idRenderModel *rModel; // r11
  float *v167; // r11
  double v168; // fp11
  idRenderModel *v169; // r11
  int num; // [sp+50h] [-1E0h]
  idVec3 v171; // [sp+58h] [-1D8h] BYREF
  unsigned __int64 v172; // [sp+70h] [-1C0h] BYREF
  float v173; // [sp+78h] [-1B8h]
  float v174; // [sp+7Ch] [-1B4h]
  idPLogScope v175; // [sp+80h] [-1B0h] BYREF
  float v176; // [sp+88h] [-1A8h]
  int v177; // [sp+8Ch] [-1A4h] BYREF
  idMat3 v178; // [sp+90h] [-1A0h] BYREF
  idPLogScope v179; // [sp+B8h] [-178h] BYREF
  idVec4 v180; // [sp+C0h] [-170h] BYREF
  idVec4 v181; // [sp+D0h] [-160h] BYREF
  idVec4 v182; // [sp+E0h] [-150h] BYREF
  idVec4 v183; // [sp+F0h] [-140h] BYREF
  idMat3 v184; // [sp+100h] [-130h] BYREF
  int v185; // [sp+12Ch] [-104h] BYREF
  tagData_t v186; // [sp+130h] [-100h] BYREF
  int v187; // [sp+150h] [-E0h] BYREF
  idMat3 v188; // [sp+160h] [-D0h] BYREF

  RD_EventBegin(name: "idFX::StartAction");
  LODWORD(v12) = "idFX::StartAction";
  HIDWORD(v12) = 2;
  idPLogScope::idPLogScope(this: &v179, pl: &pLog, gMask: v12, label: v13);
  v14 = &this->actionState.list[i];
  v16 = &this->actions.list[i];
  v15 = &this->fxDecl->events.list[i];
  if ( v14->startTime >= 0 && v15->looping )
    goto _M253978;
  if ( common->Game(this: common) != nullptr )
  {
    v17 = common->Game(this: common);
    v18 = (int)v17->GetViewCallbacks(this: v17);
    v19 = (_DWORD *)v18;
    if ( v15->particleParms.isScreenPrt && v16->screenPrtHandle >= 0 && v16->rParticle != nullptr )
    {
      v20 = 0;
      if ( *(int *)(v18 + 4) > 0 )
      {
        viewCallbacksID = v16->viewCallbacksID;
        v22 = 0;
        while ( viewCallbacksID >= 0 )
        {
          viewCallbacksID = v16->viewCallbacksID;
          if ( (*(int (__fastcall **)(_DWORD))(**(_DWORD **)(*v19 + v22) + 4))(a1: *(_DWORD *)(*v19 + v22)) == viewCallbacksID )
            break;
          ++v20;
          v22 += 4;
          if ( v20 >= v19[1] )
            goto LABEL_15;
        }
        (*(void (__fastcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(4 * v20 + *v19) + 40))(
          a1: *(_DWORD *)(4 * v20 + *v19),
          a2: v16->screenPrtHandle,
          a3: 0);
      }
    }
  }
LABEL_15:
  v14->startTime = time;
  startDelay = v14->startDelay;
  HIDWORD(v24) = &v16->lastParticleDropPos;
  v25 = (int)(float)(v15->duration * (float)1000.0) + v14->startDelay + time;
  v14->fadeInStartTime = time;
  v14->stopTime = v25;
  HIDWORD(v26) = 1013841920;
  v14->fadeInEndTime = (int)(float)(v15->fadeInTime * (float)1000.0) + startDelay + time;
  v27 = (float)(v15->duration - v15->fadeOutTime);
  v14->shouldTrigger = true;
  v14->forceStop = false;
  p_random = &this->random;
  v14->started = false;
  v14->fadeOutStartTime = (int)(float)((float)v27 * (float)1000.0) + startDelay + time;
  v16->lastParticleDropPos.x = org->x;
  v16->lastParticleDropPos.y = org->y;
  v16->lastParticleDropPos.z = org->z;
  v16->viewCallbacksID = this->viewCallbacksID;
  v29 = 1664525 * this->random.seed + 1013904223;
  x = v15->rndRotY.x;
  LODWORD(v24) = (v29 >> 10) & 0x7FFF;
  this->random.seed = v29;
  v31 = v15->rndRotZ.x;
  v32 = (float)(v15->rndRotY.y - v15->rndRotY.x);
  v33 = (double)v24;
  HIDWORD(v24) = 1664525 * v29;
  v34 = 1664525 * v29 + 1013904223;
  this->random.seed = v34;
  LODWORD(v26) = (v34 >> 10) & 0x7FFF;
  y = v15->rndRotZ.y;
  v36 = v15->rndRotZ.x;
  v37 = v15->rndRotX.x;
  v38 = (double)v26;
  HIDWORD(v26) = 1664525 * v34 + 1013904223;
  LODWORD(v24) = (HIDWORD(v26) >> 10) & 0x7FFF;
  this->random.seed = HIDWORD(v26);
  v39 = (float)v38;
  v40 = v15->rndRotX.x;
  v41 = v15->rndRotX.y;
  v16->randomAngles.pitch = (float)((float)((float)v33 * (float)v32) * (float)0.000030518509) + (float)x;
  v16->randomAngles.yaw = (float)((float)((float)v39 * (float)((float)y - (float)v36)) * (float)0.000030518509)
                        + (float)v31;
  v16->randomAngles.roll = (float)((float)((float)v24 * (float)((float)v41 - (float)v40)) * (float)0.000030518509)
                         + (float)v37;
  if ( !v15->triggered || !v14->hidden )
  {
    if ( tagIdx < 0 || tagIdx >= v16->tagData.num )
    {
      v16->tagIndex = 0;
      if ( v15->multiTagUseType == FX_MULTI_TAG_USE_RND )
      {
        num = v16->tagData.num;
        if ( num > 1 )
          v16->tagIndex = idRandom2::RandomInt(this: &this->random, max: num - 1);
      }
    }
    else
    {
      v16->tagIndex = tagIdx;
    }
    v42 = org->y;
    v43 = &v177;
    z = org->z;
    p_z = (_DWORD *)&axis[-1].mat[2].z;
    v171.x = org->x;
    v46 = 9;
    v171.y = v42;
    v171.z = z;
    do
    {
      *++v43 = *++p_z;
      --v46;
    }
    while ( v46 != 0 );
    if ( v16->tagData.num > 0 )
    {
      v47 = &v185;
      v48 = 8;
      p_parentJoint = &v16->tagData.list[v16->tagIndex - 1].parentJoint;
      do
      {
        p_parentJoint += 2;
        *++v47 = *(_DWORD *)&p_parentJoint->value;
        --v48;
      }
      while ( v48 != 0 );
      ta = this->ta;
      if ( ta != nullptr )
        idTreeAnimator::GetWorldSpaceTagTransform(this: ta, tagData: &v186, origin: &v171, axis: &v178);
    }
    if ( (unsigned __int8)idMat3::IsOrthoNormal(this: &v178, epsilon: 0.1) == 0 )
      goto _M253978;
    rotationType = v15->rotationType;
    if ( rotationType == FX_ROT_START_AXIS_PARENT )
    {
      v52 = axis->mat[0].y;
      v53 = axis->mat[0].z;
      v54 = axis->mat[1].x;
      v55 = axis->mat[1].y;
      v56 = axis->mat[1].z;
      v57 = axis->mat[2].x;
      v58 = axis->mat[2].y;
      v59 = axis->mat[2].z;
      v178.mat[0].x = axis->mat[0].x;
      v178.mat[0].y = v52;
      v178.mat[0].z = v53;
      v178.mat[1].x = v54;
      v178.mat[1].y = v55;
      v178.mat[1].z = v56;
      v178.mat[2].x = v57;
      v178.mat[2].y = v58;
    }
    else
    {
      if ( rotationType != FX_ROT_EXPLICIT_ANGLES )
      {
LABEL_37:
        v60 = idAngles::ToMat3(this: (idAngles *)&v188, result: (idMat3 *)&v16->randomAngles);
        idMat3::operator*(this: &v184, result: v60, a: &v15->rotOffset);
        v61 = (float *)idMat3::operator*(this: &v188, result: &v184, a: &v178);
        v62 = *v61;
        v178.mat[0].x = *v61;
        v63 = v61[1];
        v178.mat[0].y = v61[1];
        v64 = v61[2];
        v178.mat[0].z = v61[2];
        v65 = v61[3];
        v178.mat[1].x = v61[3];
        v66 = v61[4];
        v178.mat[1].y = v61[4];
        v67 = v61[5];
        v178.mat[1].z = v61[5];
        v68 = v61[6];
        v178.mat[2].x = v61[6];
        v69 = v61[7];
        v178.mat[2].y = v61[7];
        v70 = v61[8];
        v178.mat[2].z = v61[8];
        v71 = (float)((float)((float)v64 * v15->offset.x) + (float)((float)v70 * v15->offset.z));
        v72 = (float)((float)((float)v68 * v15->offset.z) + (float)((float)v65 * v15->offset.y));
        v73 = (float)((float)((float)v66 * v15->offset.y)
                    + (float)((float)((float)v63 * v15->offset.x) + (float)((float)v69 * v15->offset.z)));
        v75 = (float)(v171.z + (float)((float)((float)v67 * v15->offset.y) + (float)v71));
        v74 = (float)((float)((float)v62 * v15->offset.x) + (float)v72);
        v171.z = v75;
        v171.y = v171.y + (float)v73;
        v171.x = (float)v74 + v171.x;
        v16->startAxis.mat[0].x = v62;
        v16->startAxis.mat[0].y = v178.mat[0].y;
        v16->startAxis.mat[0].z = v178.mat[0].z;
        v16->startAxis.mat[1] = v178.mat[1];
        v16->startAxis.mat[2] = v178.mat[2];
        v16->startOrg = v171;
        type = v15->type;
        if ( type > 5 )
          goto _M253978;
        switch ( type )
        {
          case 1u:
            RD_EventBegin(name: "idFX::StartAction - FX_PARTICLE");
            LODWORD(v119) = "idFX::StartAction - FX_PARTICLE";
            HIDWORD(v119) = 2;
            idPLogScope::idPLogScope(this: &v175, pl: &pLog, gMask: v119, label: v120);
            if ( !v15->particleParms.useSmokeSystem )
            {
              if ( v16->rParticle == nullptr )
              {
                rw = this->rw;
                if ( rw != nullptr )
                  v16->rParticle = idFXModelRecycler::GetParticleFxModel(
                                     this: &this->gameLibEffects->fxModelRecycler,
                                     particleDecl: (const idMaterial *)v15->particleParms.declPrt,
                                     rw);
              }
              rParticle = v16->rParticle;
              if ( rParticle != nullptr )
              {
                if ( !rParticle->deferredPositionInitialized || !rParticle->useDeferredPosition )
                  rParticle->g.origin = v171;
                rParticle->deferredOrigin = v171;
                idRenderModel::SetAxis(this: v16->rParticle, a: &v178);
                v123 = (float *)v16->rParticle;
                size = v15->size;
                v123[42] = v15->size;
                v123[41] = size;
                v123[43] = size;
                *(float *)&v172 = this->systemColor.x;
                v125 = v15->color.y;
                v126 = v15->color.x;
                w = this->systemColor.w;
                v128 = v15->color.w;
                v129 = this->systemColor.z;
                v130 = v15->color.z;
                LODWORD(v172) = LODWORD(this->systemColor.y);
                v174 = w;
                v173 = v129;
                v180.y = (float)v125 * *((float *)&v172 + 1);
                v180.x = *(float *)&v172 * (float)v126;
                v180.z = (float)v130 * v129;
                v180.w = (float)v128 * w;
                idRenderModel::SetParm(this: v16->rParticle, parm: rp->Color, v4: &v180);
                v131 = 1664525 * p_random->seed;
                p_random->seed = v131 + 1013904223;
                LODWORD(v132) = ((unsigned int)(v131 + 1013904223) >> 10) & 0x7FFF;
                v133 = v16->rParticle;
                v172 = v132;
                idRenderModel::SetParm(
                  this: v133,
                  parm: rp->Diversity,
                  scalar: (float)((float)v132 * (float)0.000030518509));
                idRenderModel::SetParm(this: v16->rParticle, parm: rp->TimeStop, scalar: 0.0);
                v134 = v16->rParticle;
                v172 = __PAIR64__(&unk_82390000, time);
                idRenderModel::SetParm(
                  this: v134,
                  parm: rp->TimeOffset,
                  scalar: (float)((float)__SPAIR64__(&unk_82390000, time) * (float)0.001));
                if ( v15->noshadows )
                  v135 = 1.0;
                else
                  v135 = 0.0;
                idRenderModel::SetParm(this: v16->rParticle, parm: rp->NoShadows, scalar: v135);
                idRenderModel::SetParm(
                  this: v16->rParticle,
                  parm: (const idDeclRenderParm *)rpParticleVel.r,
                  v3: &vec3_origin);
                v136 = v16->rParticle;
                if ( v136 != nullptr )
                {
                  v136->g.allowSurfaceOnlyInViewID = this->allowSurfaceOnlyInViewID;
                  v136->g.suppressSurfaceInViewID = this->suppressSurfaceInViewID;
                }
                if ( v15->rotationType == FX_ROT_TRACK_LOCAL_AXIS
                  || (v137 = 0, v15->originType == FX_ORG_TRACK_LOCAL_POS) )
                {
                  v137 = 1;
                }
                if ( v137 != 0 || v15->particleParms.isScreenPrt || v14->startDelay != 0 )
                {
                  v138 = v16->rParticle;
                  if ( !v138->unlinked )
                  {
                    idRenderModel::CommitThisFrame(this: v16->rParticle);
                    v138->unlinked = true;
                  }
                }
                else
                {
                  idRenderModel::CommitThisFrame(this: v16->rParticle);
                }
              }
            }
            break;
          case 2u:
_M253978:
            idPLogScope::~idPLogScope(this: &v179);
            goto LABEL_125;
          case 3u:
            RD_EventBegin(name: "idFX::StartAction - FX_DECAL2");
            LODWORD(v162) = "idFX::StartAction - FX_DECAL2";
            HIDWORD(v162) = 2;
            idPLogScope::idPLogScope(this: &v175, pl: &pLog, gMask: v162, label: v163);
            v164 = this->rw;
            if ( v164 != nullptr && v16->rModel == nullptr )
            {
              v165 = ((int (*)(void))v164->AllocRenderModel)();
              v16->rModel = (idRenderModel *)v165;
              if ( v165 != 0 )
              {
                *(_DWORD *)(v165 + 176) = v15->decalParms.decalMtr;
                *((_BYTE *)&v16->rModel->g + 105) |= 0x80u;
              }
            }
            rModel = v16->rModel;
            if ( rModel == nullptr )
              break;
            if ( !rModel->deferredPositionInitialized || !rModel->useDeferredPosition )
              rModel->g.origin = v171;
            rModel->deferredOrigin = v171;
            idRenderModel::SetAxis(this: v16->rModel, a: &v178);
            v167 = (float *)v16->rModel;
            v168 = v15->size;
            v167[43] = v15->decalParms.depth;
            v167[41] = v168;
            v167[42] = v168;
            v169 = v16->rModel;
            if ( v169 != nullptr )
            {
              v169->g.allowSurfaceOnlyInViewID = this->allowSurfaceOnlyInViewID;
              v169->g.suppressSurfaceInViewID = this->suppressSurfaceInViewID;
            }
            if ( v14->startDelay == 0 )
            {
              idRenderModel::CommitThisFrame(this: v16->rModel);
              break;
            }
            v161 = v16->rModel;
            if ( !v161->unlinked )
              goto LABEL_120;
            break;
          case 4u:
            RD_EventBegin(name: "idFX::StartAction - FX_MODEL");
            LODWORD(v139) = "idFX::StartAction - FX_MODEL";
            HIDWORD(v139) = 2;
            idPLogScope::idPLogScope(this: &v175, pl: &pLog, gMask: v139, label: v140);
            v141 = this->rw;
            if ( v141 != nullptr && v16->rModel == nullptr )
            {
              StaticFxModel = idFXModelRecycler::GetStaticFxModel(
                                this: &this->gameLibEffects->fxModelRecycler,
                                name: &v15->modelParms.modelName,
                                rw: v141);
              v16->rModel = StaticFxModel;
              if ( StaticFxModel != nullptr )
              {
                v143 = this->systemColor.w;
                v144 = v15->color.w;
                x_low = SLODWORD(this->systemColor.x);
                v146 = v15->color.z;
                v147 = this->systemColor.y;
                v148 = v15->color.y;
                v149 = v15->color.x;
                v173 = this->systemColor.z;
                v174 = v143;
                HIDWORD(v172) = x_low;
                *((float *)&v172 + 1) = v147;
                v182.z = (float)v146 * v173;
                v182.w = (float)v144 * v143;
                v182.x = *(float *)&x_low * (float)v149;
                v182.y = (float)v148 * v147;
                idRenderModel::SetParm(this: v16->rModel, parm: rp->Color, v4: &v182);
                v16->rModel->g.customMaterial = v15->modelParms.customMaterial;
                *((_BYTE *)&v16->rModel->g + 105) = (v15->noshadows << 7) | *((_BYTE *)&v16->rModel->g + 105) & 0x7F;
              }
            }
            if ( v16->rModel != nullptr )
            {
              v150 = this->systemColor.w;
              v151 = v15->color.w;
              v152 = SLODWORD(this->systemColor.x);
              v153 = v15->color.z;
              v154 = this->systemColor.y;
              v155 = v15->color.y;
              v156 = v15->color.x;
              v173 = this->systemColor.z;
              v174 = v150;
              HIDWORD(v172) = v152;
              *((float *)&v172 + 1) = v154;
              v181.w = (float)v151 * v150;
              v181.x = *(float *)&v152 * (float)v156;
              v181.z = (float)v153 * v173;
              v181.y = (float)v155 * v154;
              idRenderModel::SetParm(this: v16->rModel, parm: rp->Color, v4: &v181);
              v157 = v16->rModel;
              if ( !v157->deferredPositionInitialized || !v157->useDeferredPosition )
                v157->g.origin = v171;
              v157->deferredOrigin = v171;
              idRenderModel::SetAxis(this: v16->rModel, a: &v178);
              v158 = (float *)v16->rModel;
              v159 = v15->size;
              v158[41] = v15->size;
              v158[43] = v159;
              v158[42] = v159;
              v160 = v16->rModel;
              if ( v160 != nullptr )
              {
                v160->g.allowSurfaceOnlyInViewID = this->allowSurfaceOnlyInViewID;
                v160->g.suppressSurfaceInViewID = this->suppressSurfaceInViewID;
              }
              if ( v14->startDelay == 0 )
              {
                idRenderModel::CommitThisFrame(this: v16->rModel);
                break;
              }
              v161 = v16->rModel;
              if ( !v161->unlinked )
              {
LABEL_120:
                idRenderModel::CommitThisFrame(this: v16->rModel);
                v161->unlinked = true;
              }
            }
            break;
          default:
            if ( type != 0 )
            {
              RD_EventBegin(name: "idFX::StartAction - FX_SOUND");
              LODWORD(v113) = "idFX::StartAction - FX_SOUND";
              HIDWORD(v113) = 2;
              idPLogScope::idPLogScope(this: (idPLogScope *)&v172, pl: &pLog, gMask: v113, label: v114);
              if ( v14->startDelay == 0 && v15->soundParms.sound != nullptr )
              {
                v14->started = true;
                if ( !this->remote || (sound = v15->soundParms.sound->remoteSound) == nullptr )
                  sound = v15->soundParms.sound;
                idFXManager::StartSound(this, channel: v15->soundParms.channel, shader: sound);
                if ( v15->fadeInTime != 0.0 )
                {
                  channel = v15->soundParms.channel;
                  if ( this->soundInfo.emitter != nullptr )
                  {
                    if ( channel == SND_CHANNEL_ANY )
                      channel = this->soundInfo.channel;
                    this->soundInfo.emitter->SetVolume(this: this->soundInfo.emitter, a2: channel, a3: -60.0);
                  }
                  v118 = v15->soundParms.channel;
                  if ( this->soundInfo.emitter != nullptr )
                  {
                    if ( v118 == SND_CHANNEL_ANY )
                      v118 = this->soundInfo.channel;
                    ((void (__fastcall *)(idSoundEmitter *, soundChannel_t, double, double, double))this->soundInfo.emitter->FadeSound)(
                      a1: this->soundInfo.emitter,
                      a2: v118,
                      a3: 0.0,
                      a4: v15->fadeInTime,
                      a5: 0.0);
                  }
                }
                HIDWORD(v116) = time;
                idFXManager::ApplyFade(this, fxaction: v15, laction: v16, state: v14, time: v116, pct: 0.0);
              }
            }
            else
            {
              RD_EventBegin(name: "idFX::StartAction - FX_LIGHT");
              LODWORD(v77) = "idFX::StartAction - FX_LIGHT";
              HIDWORD(v77) = 2;
              idPLogScope::idPLogScope(this: (idPLogScope *)&v172, pl: &pLog, gMask: v77, label: v78);
              if ( v16->rLight == nullptr )
              {
                v79 = this->rw;
                if ( v79 != nullptr )
                {
                  v80 = ((int (*)(void))v79->AllocRenderLight)();
                  v16->rLight = (idRenderLight *)v80;
                  if ( v80 != 0 )
                  {
                    *(_DWORD *)(v80 + 56) = 0;
                    v16->rLight->g.lightClass = LIGHT_BLENDED_ONLY;
                    y_low = (idPLog *)LODWORD(v15->lightParms.radius.y);
                    v82 = v15->lightParms.radius.z;
                    v175.logIndex = LODWORD(v15->lightParms.radius.x);
                    v175.pLog = y_low;
                    v176 = v82;
                    rLight = v16->rLight;
                    *(idPLogScope *)&rLight->g.lightRadius.x = v175;
                    rLight->g.lightRadius.z = v82;
                    v16->rLight->g.shader = v15->lightParms.lightMtr;
                    v16->rLight->g.noShadows = v15->noshadows;
                    v16->rLight->g.allowLightOnlyInViewID = this->allowSurfaceOnlyInViewID;
                    v16->rLight->g.suppressLightInViewID = this->suppressSurfaceInViewID;
                  }
                }
              }
              if ( v16->rLight != nullptr )
              {
                TableColor = (float *)idFXManager::GetTableColor(
                                        this: (idFXManager *)&v187,
                                        result: (idVec4 *)this,
                                        fxaction: v15,
                                        pct: 0.0);
                v85 = TableColor[3];
                v86 = (float *)v16->rLight;
                v87 = v15->color.w;
                v88 = LODWORD(v171.x);
                v89 = TableColor[2];
                v175.pLog = (idPLog *)LODWORD(v171.y);
                v90 = v15->color.z;
                v91 = TableColor[1];
                v92 = v15->color.y;
                v176 = v171.z;
                v93 = *TableColor;
                v94 = (float)((float)v85 * (float)v87);
                v95 = v15->color.x;
                v96 = (float)((float)v89 * (float)v90);
                p_w = &v183.w;
                v98 = v171.z;
                v86[9] = v171.x;
                v175.logIndex = v88;
                v86[11] = v98;
                v99 = &v177;
                v100 = (float)((float)v91 * (float)v92);
                v86[10] = *(float *)&v175.pLog;
                v101 = 9;
                v102 = (float)((float)v93 * (float)v95);
                do
                {
                  *(_DWORD *)++p_w = *++v99;
                  --v101;
                }
                while ( v101 != 0 );
                mat = v16->rLight->g.axis.mat;
                v104 = v184.mat[1].x;
                v105 = v184.mat[0].y;
                v106 = v184.mat[0].z;
                v107 = v184.mat[1].y;
                mat->x = v178.mat[0].x;
                mat[1].x = v104;
                v108 = rp;
                mat->y = v105;
                mat->z = v106;
                mat[1].y = v107;
                mat[1].z = v184.mat[1].z;
                mat[2] = v184.mat[2];
                intensity = v15->lightParms.intensity;
                v110 = (float)(v15->lightParms.intensity * (float)v100);
                v111 = (float)(v15->lightParms.intensity * (float)v102);
                v183.w = v15->lightParms.intensity * (float)v94;
                v183.x = v111;
                v183.y = v110;
                v183.z = (float)intensity * (float)v96;
                idRenderLight::SetParm(this: v16->rLight, parm: v108->lightColor, v4: &v183);
                v112 = v16->rLight;
                if ( v14->startDelay != 0 )
                  idRenderLight::Unlink(this: v112);
                else
                  idRenderLight::CommitThisFrame(this: v112);
              }
            }
            idPLogScope::~idPLogScope(this: (idPLogScope *)&v172);
            goto LABEL_123;
        }
        idPLogScope::~idPLogScope(this: &v175);
LABEL_123:
        RD_EventEnd();
        goto _M253978;
      }
      v178.mat[0].x = v15->axis.mat[0].x;
      v178.mat[0].y = v15->axis.mat[0].y;
      v178.mat[0].z = v15->axis.mat[0].z;
      v178.mat[1] = v15->axis.mat[1];
      v178.mat[2].x = v15->axis.mat[2].x;
      v178.mat[2].y = v15->axis.mat[2].y;
      v59 = v15->axis.mat[2].z;
    }
    v178.mat[2].z = v59;
    goto LABEL_37;
  }
  v14->startTime = -1;
  idPLogScope::~idPLogScope(this: &v179);
LABEL_125:
  RD_EventEnd();
}


// ========================================================================
// __unwind$253184
// EA  : 0x8270F30C
// RVA : 0x0070F30C
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_253184()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 560 + 388));
}


// ========================================================================
// __unwind$253185
// EA  : 0x8270F334
// RVA : 0x0070F334
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_253185()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 560 + 184));
}


// ========================================================================
// __unwind$253186
// EA  : 0x8270F35C
// RVA : 0x0070F35C
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_253186()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 560 + 389));
}


// ========================================================================
// __unwind$253187
// EA  : 0x8270F384
// RVA : 0x0070F384
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_253187()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 560 + 112));
}


// ========================================================================
// __unwind$253188
// EA  : 0x8270F3AC
// RVA : 0x0070F3AC
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_253188()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 560 + 390));
}


// ========================================================================
// __unwind$253189
// EA  : 0x8270F3D4
// RVA : 0x0070F3D4
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_253189()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 560 + 112));
}


// ========================================================================
// __unwind$253190
// EA  : 0x8270F3FC
// RVA : 0x0070F3FC
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_253190()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 560 + 391));
}


// ========================================================================
// __unwind$253191
// EA  : 0x8270F424
// RVA : 0x0070F424
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_253191()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 560 + 128));
}


// ========================================================================
// __unwind$253192
// EA  : 0x8270F44C
// RVA : 0x0070F44C
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_253192()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 560 + 392));
}


// ========================================================================
// __unwind$253193
// EA  : 0x8270F474
// RVA : 0x0070F474
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_253193()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 560 + 128));
}


// ========================================================================
// __unwind$253194
// EA  : 0x8270F49C
// RVA : 0x0070F49C
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_253194()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 560 + 393));
}


// ========================================================================
// __unwind$253195
// EA  : 0x8270F4C4
// RVA : 0x0070F4C4
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_253195()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 560 + 128));
}


// ========================================================================
// ?StopAllFX@idFXManager@@QAAXH_N@Z
// EA  : 0x8270F4F0
// RVA : 0x0070F4F0
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::StopAllFX(idFXManager *this, int time, bool immediateStop)
{
  idFXManager::fxActionCall_t *v6; // r4

  if ( g_skipFXManager.valueInteger == 0 && this->initialized )
  {
    if ( common->IsServer(this: common) )
    {
      v6 = &this->actionBuffer[this->actionBufferPos % 8];
      v6->time = time;
      v6->condition = FX_NONE;
      v6->extraCondition = FX_EXTRA_COND_NONE;
      v6->actionType = FXACTION_STOP_ALL;
      v6->immediate = immediateStop;
      idFXManager::InternalStopFX(this, actionCall: v6);
    }
    else
    {
      idFXManager::StopActions(
        this,
        time,
        stopCondition: 0,
        extraCondition: FX_EXTRA_COND_NONE,
        stopAll: true,
        stopImmediate: immediateStop);
    }
  }
}


// ========================================================================
// ?StopFX@idFXManager@@QAAXHW4fxCondition_t@@_N@Z
// EA  : 0x8270F5B8
// RVA : 0x0070F5B8
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::StopFX(idFXManager *this, int time, int stopCondition, bool immediateStop)
{
  idFXManager::fxActionCall_t *v8; // r4

  if ( g_skipFXManager.valueInteger == 0 && this->initialized )
  {
    if ( common->IsServer(this: common) )
    {
      v8 = &this->actionBuffer[this->actionBufferPos % 8];
      v8->time = time;
      v8->condition = stopCondition;
      v8->extraCondition = FX_EXTRA_COND_NONE;
      v8->actionType = FXACTION_STOP;
      v8->immediate = immediateStop;
      idFXManager::InternalStopFX(this, actionCall: v8);
    }
    else
    {
      idFXManager::StopActions(
        this,
        time,
        stopCondition,
        extraCondition: FX_EXTRA_COND_NONE,
        stopAll: false,
        stopImmediate: immediateStop);
    }
  }
}


// ========================================================================
// ?StopFX@idFXManager@@QAAXHW4fxCondition_t@@W4fxExtraCondition_t@@_N@Z
// EA  : 0x8270F688
// RVA : 0x0070F688
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::StopFX(
        idFXManager *this,
        int time,
        int stopCondition,
        fxExtraCondition_t extraCondition,
        bool immediateStop)
{
  idFXManager::fxActionCall_t *v10; // r4

  if ( g_skipFXManager.valueInteger == 0 && this->initialized )
  {
    if ( common->IsServer(this: common) )
    {
      v10 = &this->actionBuffer[this->actionBufferPos % 8];
      v10->time = time;
      v10->condition = stopCondition;
      v10->extraCondition = extraCondition;
      v10->actionType = FXACTION_STOP;
      v10->immediate = immediateStop;
      idFXManager::InternalStopFX(this, actionCall: v10);
    }
    else
    {
      idFXManager::StopActions(this, time, stopCondition, extraCondition, stopAll: false, stopImmediate: immediateStop);
    }
  }
}


// ========================================================================
// ?EnumerateTags@idFXManager@@AAAXABV?$idList@VidAtomicString@@$0GN@@@AAV?$idList@UtagData_t@@$0GN@@@@Z
// EA  : 0x8270F758
// RVA : 0x0070F758
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::EnumerateTags(
        idFXManager *this,
        const idList<idAtomicString,109> *tagNames,
        idList<tagData_t,109> *tagData)
{
  int v6; // r25
  int v7; // r31
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r3
  const tagData_t *Tag; // r3
  char *v11; // r10
  idHandle<unsigned short,enum invalidJointHandle_t,65535> *p_parentJoint; // r9
  int i; // ctr
  char v14; // [sp+4Ch] [-74h] BYREF
  tagData_t v15; // [sp+50h] [-70h] BYREF

  if ( this->ta != nullptr )
  {
    v6 = 0;
    if ( tagNames->num > 0 )
    {
      v7 = 0;
      do
      {
        decl = this->ta->decl;
        p_props = &decl->props;
        if ( decl == nullptr )
          p_props = nullptr;
        Tag = idPropsCollection::GetTag(
                this: p_props,
                propName: idPropInfo::INFO_PROP_NAME,
                tagName: tagNames->list[v7].str);
        v11 = &v14;
        p_parentJoint = &Tag[-1].parentJoint;
        for ( i = 8; i != 0; --i )
        {
          p_parentJoint += 2;
          v11 += 4;
          *(_DWORD *)v11 = *(_DWORD *)&p_parentJoint->value;
        }
        idList<tagData_t,109>::Append(this: tagData, obj: &v15);
        if ( v15.parentJoint.value == 0xFFFF )
          idLib::WarningIf(
            condition: fx_verbose.valueInteger != 0,
            fmt: "idFXManager::CreateAction cannot find tag %s for %s",
            tagNames->list[v7].str,
            this->fxDecl->name.str);
        ++v6;
        ++v7;
      }
      while ( v6 < tagNames->num );
    }
  }
}


// ========================================================================
// ?ResetTreeAnimator@idFXManager@@QAAXPAVidTreeAnimator@@@Z
// EA  : 0x8270F900
// RVA : 0x0070F900
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::ResetTreeAnimator(idFXManager *this, idTreeAnimator *_ta)
{
  const idDeclFX *fxDecl; // r11
  int num; // r10
  int v5; // r11
  int v6; // r26
  int v7; // r27
  int v8; // r28
  idList<tagData_t,109> *p_tagData; // r30
  idFXSingleAction *v10; // r29

  fxDecl = this->fxDecl;
  this->ta = _ta;
  if ( fxDecl != nullptr )
  {
    num = this->actions.num;
    if ( num != 0 )
    {
      v5 = fxDecl->events.num;
      if ( num == v5 )
      {
        v6 = 0;
        if ( v5 > 0 )
        {
          v7 = 0;
          v8 = 0;
          do
          {
            p_tagData = &this->actions.list[v7].tagData;
            v10 = &this->fxDecl->events.list[v8];
            idList<tagData_t,109>::SetNum(this: p_tagData, newNum: 0);
            if ( v10->tagNames.num > 0 )
              idFXManager::EnumerateTags(this, tagNames: &v10->tagNames, tagData: p_tagData);
            ++v6;
            ++v8;
            ++v7;
          }
          while ( v6 < this->fxDecl->events.num );
        }
      }
    }
  }
}


// ========================================================================
// ?UpdateActions@idFXManager@@AAAXABVidVec3@@ABVidMat3@@0HHHMM@Z
// EA  : 0x8270F9B8
// RVA : 0x0070F9B8
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idFXManager::UpdateActions(
        idFXManager *this,
        const idVec3 *org,
        const idMat3 *axis,
        const idVec3 *vel,
        signed int time,
        unsigned int gameMsPerFrame,
        const int frameNum,
        double fovScale,
        double depthHack)
{
  const idVec3 *v10; // r27
  const idMat3 *v11; // r28
  const idVec3 *v13; // r25
  unsigned __int64 v16; // r6
  const char *v17; // r7
  idList<idViewCallbacks *,5> *ViewCallbacks; // r3
  const idDeclFX *fxDecl; // r5
  idList<idViewCallbacks *,5> *v20; // r20
  int v21; // r4
  const float *v22; // r26
  __int128 v23; // r9 OVERLAPPED
  idCVar *v24; // r22
  fxActionState_t *v25; // r21
  int startTime; // r11
  signed int v27; // r29
  idFXSingleAction *list; // r10
  double v29; // fp29
  idFXSingleAction *v30; // r30
  double v31; // fp28
  double v32; // fp27
  float y; // r7
  float z; // r6
  idFXAction *v35; // r10
  int v36; // ctr
  idFXAction *v37; // r24
  float *p_y; // r10
  _DWORD *p_z; // r11
  float v40; // r10
  idMat3 *p_axis; // r8
  int v42; // ctr
  float *p_value; // r11
  idTreeAnimator *ta; // r3
  float *v45; // r10
  _DWORD *v46; // r11
  int i; // ctr
  fxRotationType_t rotationType; // r11
  double v49; // fp0
  double v50; // fp13
  double v51; // fp12
  double v52; // fp11
  double v53; // fp10
  double v54; // fp9
  double v55; // fp8
  double v56; // fp7
  double v57; // fp6
  idMat3 *v58; // r3
  const idDeclTable *rotateTablePitch; // r11
  double v60; // fp30
  const idDeclTable *rotateTableYaw; // r11
  double v62; // fp31
  const idDeclTable *rotateTableRoll; // r11
  double v64; // fp1
  idMat3 *v65; // r3
  idMat3 *v66; // r3
  BOOL v67; // r4
  float *v68; // r3
  float v69; // r11
  double v70; // fp5
  float v71; // r10
  double v72; // fp6
  double v73; // fp7
  double v74; // fp8
  double v75; // fp9
  double v76; // fp10
  double v77; // fp11
  double v78; // fp12
  fxOriginType_t originType; // r11
  double v80; // fp13
  double v81; // fp4
  double v82; // fp30
  double v83; // fp4
  int valueInteger; // r11
  double v85; // fp2
  double v86; // fp6
  double v87; // fp4
  double v88; // fp0
  idRenderWorld *v89; // r3
  char v90; // r22
  double v91; // fp31
  int v92; // r27
  int v93; // r28
  float *v94; // r29
  double v95; // fp13
  char *str; // r11
  char v97; // r11
  bool v98; // zf
  const idDeclFX *v99; // r11
  int v100; // r28
  int v101; // r26
  int v102; // r27
  fxActionState_t *v103; // r29
  float *rLight; // r11
  char v105; // r10
  float v106; // r7
  float v107; // r6
  float v108; // r4
  idVec3 *v109; // r10
  int v110; // ctr
  float *v111; // r11
  float *v112; // r11
  double v113; // fp13
  double v114; // fp12
  double v115; // fp11
  double v116; // fp10
  double v117; // fp9
  double v118; // fp8
  double v119; // fp7
  double v120; // fp6
  float *TableColor; // r3
  double v122; // fp8
  double v123; // fp6
  double v124; // fp7
  double v125; // fp0
  double v126; // fp12
  double intensity; // fp3
  double v128; // fp1
  idRenderLight *v129; // r3
  const idSoundShader *sound; // r11
  soundChannel_t channel; // r4
  soundChannel_t v132; // r4
  idSoundEmitter *emitter; // r11
  fxRotationType_t v134; // r10
  double v135; // fp11
  double v136; // fp8
  idGameLibEffects *v137; // r29
  double size; // fp13
  idRenderModel *rModel; // r11
  float v140; // r7
  double v141; // fp0
  float v142; // r6
  double v143; // fp13
  float v144; // r10
  double v145; // fp12
  double v146; // fp11
  idRenderModel *v147; // r11
  float v148; // r8
  double v149; // fp0
  float v150; // r7
  double v151; // fp13
  float v152; // r6
  double v153; // fp12
  double v154; // fp11
  idRenderModel *v155; // r11
  const idDeclTable *customTable1; // r11
  const idDeclTable *customTable2; // r11
  int v158; // r28
  const char *v159; // r25
  int v160; // r29
  idCVar *v161; // r22
  float *v162; // r27
  int v163; // r28
  int v164; // r29
  float *v165; // r27
  __int64 v166; // r8
  float *v167; // r10
  float *v168; // r11
  int j; // ctr
  double v170; // fp6
  double v171; // fp4
  const idDeclFlare *declFlare; // r29
  double v173; // fp31
  idRenderWorld *v174; // r3
  const idVec3 *v175; // r6
  double v176; // fp8
  double v177; // fp6
  double v178; // fp4
  double v181; // fp31
  double v182; // fp30
  double v183; // fp29
  double v184; // fp28
  float *v185; // r3
  double v186; // fp4
  double v187; // fp2
  double v188; // fp0
  fxRotationType_t v189; // r11
  bool v190; // r8
  idRenderModelParticle *rParticle; // r11
  int v192; // r28
  float v193; // r25
  int v194; // r29
  idCVar *v195; // r22
  float *v196; // r27
  idRenderWorld *v197; // r3
  double w; // fp6
  double v199; // fp9
  double v200; // fp1
  double v201; // fp7
  double v202; // fp9
  idRenderModelParticle *v203; // r11
  double v204; // fp0
  unsigned int v205; // r6
  __int64 v206; // r4
  double v207; // fp1
  idCodeResource<idDeclRenderParm> *v208; // r29
  __int64 v209; // r10
  float v210; // r8
  double velocityScale; // fp0
  idRenderModelParticle *v212; // r11
  double v213; // fp0
  double v214; // fp13
  double v215; // fp12
  float v216; // r9
  float v217; // r8
  double v218; // fp11
  double v219; // fp8
  double v220; // fp7
  double v221; // fp13
  float *p_x; // r29
  double v223; // fp12
  __int64 v224; // r11
  __int64 v225; // r5
  int v226; // r2 OVERLAPPED
  double v227; // fp1
  double trailSpacing; // fp0
  double v229; // fp31
  double v230; // fp30
  int v231; // r28
  double v232; // fp29
  int v233; // r27
  __int64 v234; // r11
  double v235; // fp13
  double v236; // fp12
  double v237; // fp11
  double v238; // fp10
  double v239; // fp0
  unsigned int v240; // r8
  idGameLibEffects *gameLibEffects; // r3
  double v242; // fp0
  double v243; // fp13
  double v244; // fp12
  double v245; // fp11
  signed int smokeSystemRate; // r11
  char v247; // r11
  double v248; // fp0
  unsigned int v249; // r8
  unsigned int v250; // r3
  idRenderModel *v251; // r11
  float v252; // r8
  double v253; // fp0
  float v254; // r7
  double v255; // fp13
  float v256; // r6
  double v257; // fp12
  double v258; // fp11
  idRenderModel *v259; // r11
  int y_low; // r8
  double v261; // fp0
  int z_low; // r7
  double v263; // fp13
  float v264; // r6
  double v265; // fp12
  double v266; // fp11
  idRenderModel *v267; // r11
  const idDeclTable *v268; // r11
  const idDeclTable *v269; // r11
  int v270; // r28
  int v271; // r29
  float *v272; // r27
  int v273; // r26
  int v274; // r27
  float *v275; // r25
  int v276; // r28
  int v277; // r29
  int v278; // r27
  int v279; // r29
  idMat3 *v280; // r28
  float *Vector; // r3
  int num; // r10
  idPLog *pLog; // r29
  idPLog::logEntry_t *v286; // r30
  int v287; // r3
  __int64 totalTicks; // r11
  __int64 v289; // r9
  idMat3 v290; // [sp+68h] [-698h] BYREF
  idVec3 v291; // [sp+8Ch] [-674h]
  float x; // [sp+98h] [-668h]
  float v293; // [sp+9Ch] [-664h]
  float v294; // [sp+A0h] [-660h]
  const idVec3 *v295; // [sp+A4h] [-65Ch]
  idCVar *v296; // [sp+A8h] [-658h]
  idVec3 v297; // [sp+B0h] [-650h] BYREF
  idVec3 v298; // [sp+C0h] [-640h] BYREF
  idCodeResource<idDeclRenderParm> *v299; // [sp+CCh] [-634h]
  int v300; // [sp+D0h] [-630h]
  const float *v301; // [sp+D4h] [-62Ch]
  float v302[4]; // [sp+D8h] [-628h] BYREF
  idVec3 v303; // [sp+E8h] [-618h] BYREF
  idVec3 v304; // [sp+F8h] [-608h] BYREF
  idVec3 v305; // [sp+108h] [-5F8h] BYREF
  idVec4 v306; // [sp+120h] [-5E0h] BYREF
  float v307[10]; // [sp+130h] [-5D0h] BYREF
  idVec3 v308; // [sp+158h] [-5A8h] BYREF
  idVec3 v309; // [sp+168h] [-598h] BYREF
  idPLogScope v310; // [sp+178h] [-588h] BYREF
  int v312; // [sp+184h] [-57Ch]
  const char *v313; // [sp+188h] [-578h]
  idVec3 v314; // [sp+18Ch] [-574h] BYREF
  idVec4 v315; // [sp+1A0h] [-560h] BYREF
  idMat3 v316; // [sp+1B0h] [-550h] BYREF
  float v317; // [sp+1D4h] [-52Ch]
  float v318; // [sp+1D8h] [-528h]
  float v319; // [sp+1DCh] [-524h]
  float v320; // [sp+1E0h] [-520h]
  float v321; // [sp+1E4h] [-51Ch]
  float v322; // [sp+1E8h] [-518h]
  float v323; // [sp+1ECh] [-514h]
  float v324; // [sp+1F0h] [-510h]
  idVec3 v325; // [sp+1F8h] [-508h] BYREF
  idMat3 v326; // [sp+208h] [-4F8h] BYREF
  float v327; // [sp+22Ch] [-4D4h]
  float v328; // [sp+230h] [-4D0h]
  float v329; // [sp+234h] [-4CCh]
  float v330; // [sp+238h] [-4C8h]
  float v331; // [sp+23Ch] [-4C4h]
  idVec4 v332; // [sp+240h] [-4C0h] BYREF
  float v333; // [sp+250h] [-4B0h]
  float v334; // [sp+254h] [-4ACh]
  float v335; // [sp+258h] [-4A8h]
  float v336; // [sp+25Ch] [-4A4h]
  idVec4 v337; // [sp+260h] [-4A0h] BYREF
  idVec4 v338; // [sp+270h] [-490h] BYREF
  idVec4 v339; // [sp+280h] [-480h] BYREF
  idFXManager v340; // [sp+290h] [-470h] BYREF

  v10 = org;
  v11 = axis;
  v13 = vel;
  RD_EventBegin(name: "idFX::Update");
  LODWORD(v16) = "idFX::Update";
  HIDWORD(v16) = 2;
  idPLogScope::idPLogScope(this: &v310, pl: &::pLog, gMask: v16, label: v17);
  if ( this->fxDecl == nullptr )
  {
    idPLogScope::~idPLogScope(this: &v310);
    goto LABEL_281;
  }
  ViewCallbacks = idFXManager::GetViewCallbacks(this);
  fxDecl = this->fxDecl;
  v20 = ViewCallbacks;
  v21 = 0;
  v300 = 0;
  if ( fxDecl->events.num > 0 )
  {
    v22 = &MAX_RAND_FINV_12;
    v301 = &MAX_RAND_FINV_12;
    HIDWORD(v23) = &r_cuttablemodel_freecpudata.description;
    v299 = &rpParticleVel;
    LODWORD(v314.z) = &idColor::colorRed;
    v313 = "Starting screen shake: %s - %s \n";
    v24 = &g_debugFX;
    v295 = &vec3_origin;
    v296 = &g_debugFX;
    while ( 1 )
    {
      if ( v21 >= this->actions.num )
        goto LABEL_278;
      v25 = &this->actionState.list[v21];
      startTime = v25->startTime;
      v27 = v25->startDelay + startTime;
      if ( startTime < 0 || time < v27 || v25->hidden )
        goto LABEL_278;
      DWORD2(v23) = time;
      list = fxDecl->events.list;
      DWORD1(v23) = v25->stopTime;
      *(_QWORD *)&v340.externalPosition.x = *(_QWORD *)((char *)&v23 + 4);
      *(_QWORD *)&v340.actionBuffer[1].axis.mat[1].y = __PAIR64__(time, v27);
      *(_QWORD *)&v340.externalRotation.mat[1].z = *(_QWORD *)&v23;
      v29 = (float)__SPAIR64__(time, v27);
      v30 = &list[v21];
      v31 = (float)*(__int64 *)((char *)&v23 + 4);
      v32 = (float)((float)((float)*(__int64 *)((char *)&v23 + 4) - (float)__SPAIR64__(time, v27))
                  / (float)((float)*(__int64 *)&v23 - (float)__SPAIR64__(time, v27)));
      if ( v32 >= 1.0 )
      {
        if ( !v30->looping || v25->forceStop )
        {
          if ( !v30->restart || v25->forceStop )
            idFXManager::StopAction(this, i: v21, time, stopImmediate: false, recycleResources: true);
          else
            idFXManager::RestartAction(this, i: v21, time);
        }
        else
        {
          v25->startTime = time;
          v25->stopTime = (int)(float)(v30->duration * (float)1000.0) + time;
          v25->fadeOutStartTime = (int)(float)((float)(v30->duration - v30->fadeOutTime) * (float)1000.0) + time;
        }
        goto LABEL_278;
      }
      y = v10->y;
      z = v10->z;
      v35 = this->actions.list;
      v36 = 9;
      v304.x = v10->x;
      v304.y = y;
      v304.z = z;
      v37 = &v35[v21];
      p_y = &v316.mat[2].y;
      p_z = (_DWORD *)&v11[-1].mat[2].z;
      do
      {
        *++p_y = *(float *)++p_z;
        --v36;
      }
      while ( v36 != 0 );
      v40 = v13->y;
      LODWORD(v23) = LODWORD(v13->z);
      DWORD2(v23) = v37->tagData.num;
      v298.x = v13->x;
      v298.y = v40;
      LODWORD(v298.z) = v23;
      if ( SDWORD2(v23) <= 0 )
        goto LABEL_28;
      p_axis = &v340.actionBuffer[2].axis;
      v42 = 8;
      p_value = (float *)&v37->tagData.list[v37->tagIndex - 1].parentJoint.value;
      do
      {
        ++p_value;
        p_axis = (idMat3 *)((char *)p_axis + 4);
        p_axis->mat[0].x = *p_value;
        --v42;
      }
      while ( v42 != 0 );
      ta = this->ta;
      if ( ta != nullptr )
        idTreeAnimator::GetWorldSpaceTagTransform(
          this: ta,
          tagData: (const tagData_t *)&v340.actionBuffer[2].axis.mat[0].y,
          origin: &v304,
          axis: (idMat3 *)&v316.mat[2].z);
      if ( (unsigned __int8)idMat3::IsOrthoNormal(this: (idMat3 *)&v316.mat[2].z, epsilon: 0.000099999997) != 0 )
        break;
LABEL_278:
      fxDecl = this->fxDecl;
      v21 = v300 + 1;
      num = fxDecl->events.num;
      v300 = v21;
      if ( v21 >= num )
        goto LABEL_279;
      v24 = v296;
      v13 = vel;
      v11 = axis;
      v10 = org;
    }
    if ( v30->particleParms.trackVelocity )
      idFXManager::GetWorldSpaceTagVelocity(
        this,
        tag: (const tagData_t *)&v340.actionBuffer[2].axis.mat[0].y,
        gameMsPerFrame,
        tagVel: &v298);
LABEL_28:
    v45 = &v290.mat[1].z;
    v46 = (_DWORD *)&v11[-1].mat[2].z;
    for ( i = 9; i != 0; --i )
      *++v45 = *(float *)++v46;
    rotationType = v30->rotationType;
    if ( rotationType == FX_ROT_TRACK_AXIS )
    {
      v49 = v316.mat[2].z;
      v50 = v317;
      v51 = v318;
      v52 = v319;
      v53 = v320;
      v54 = v321;
      v55 = v322;
      v56 = v323;
      v57 = v324;
    }
    else
    {
      if ( rotationType != FX_ROT_TRACK_AXIS_PARENT )
      {
        switch ( rotationType )
        {
          case FX_ROT_EXPLICIT_ANGLES:
            v290.mat[2] = v30->axis.mat[0];
            v291 = v30->axis.mat[1];
            x = v30->axis.mat[2].x;
            v293 = v30->axis.mat[2].y;
            v57 = v30->axis.mat[2].z;
            break;
          case FX_ROT_EXPLICIT_TABLES:
          case FX_ROT_EXPLICIT_TABLES_LOCAL:
            rotateTablePitch = v30->rotateTablePitch;
            if ( rotateTablePitch != nullptr )
              v60 = idLookupTable::TableLookup(this: rotateTablePitch->table, time: v32, fastSearch: v21);
            else
              v60 = 0.0;
            rotateTableYaw = v30->rotateTableYaw;
            if ( rotateTableYaw != nullptr )
              v62 = idLookupTable::TableLookup(this: rotateTableYaw->table, time: v32, fastSearch: v21);
            else
              v62 = 0.0;
            rotateTableRoll = v30->rotateTableRoll;
            if ( rotateTableRoll != nullptr )
              v64 = idLookupTable::TableLookup(this: rotateTableRoll->table, time: v32, fastSearch: v21);
            else
              v64 = 0.0;
            LODWORD(v23) = time - v27;
            *(_QWORD *)&v340.actionBuffer[0].axis.mat[1].x = v23;
            v316.mat[0].z = (float)((float)(__int64)v23 * (float)0.001) * (float)v64;
            v316.mat[0].y = (float)((float)(__int64)v23 * (float)0.001) * (float)v62;
            v316.mat[0].x = (float)((float)(__int64)v23 * (float)0.001) * (float)v60;
            idAngles::Normalize360(this: (idAngles *)&v316);
            idAngles::ToMat3(this: (idAngles *)&v340.remote, result: &v316);
            if ( v30->rotationType != FX_ROT_EXPLICIT_TABLES_LOCAL )
            {
              v49 = *(float *)&v340.remote;
              v50 = *(float *)&v340.allowSurfaceOnlyInViewID;
              v51 = *(float *)&v340.suppressSurfaceInViewID;
              v52 = *(float *)&v340.viewCallbacksID;
              v53 = *(float *)&v340.declChangeId;
              v54 = v340.externalRotation.mat[0].x;
              v55 = v340.externalRotation.mat[0].y;
              v56 = v340.externalRotation.mat[0].z;
              v57 = v340.externalRotation.mat[1].x;
              goto LABEL_54;
            }
            v65 = idMat3::operator*(
                    this: (idMat3 *)&v340.actionBuffer[1].axis.mat[2].z,
                    result: (idMat3 *)&v340.remote,
                    a: (idMat3 *)&v316.mat[2].z);
            v290.mat[2].x = v65->mat[0].x;
            v290.mat[2].y = v65->mat[0].y;
            v290.mat[2].z = v65->mat[0].z;
            v291 = v65->mat[1];
            x = v65->mat[2].x;
            v293 = v65->mat[2].y;
            v57 = v65->mat[2].z;
            break;
          case FX_ROT_EXTERNALROT:
            v49 = this->externalRotation.mat[0].x;
            v50 = this->externalRotation.mat[0].y;
            v51 = this->externalRotation.mat[0].z;
            v52 = this->externalRotation.mat[1].x;
            v53 = this->externalRotation.mat[1].y;
            v54 = this->externalRotation.mat[1].z;
            v55 = this->externalRotation.mat[2].x;
            v56 = this->externalRotation.mat[2].y;
            v57 = this->externalRotation.mat[2].z;
            goto LABEL_54;
          case FX_ROT_TRACK_LOCAL_AXIS:
            v58 = idMat3::operator*(
                    this: (idMat3 *)&v340.actionBuffer[1].axis.mat[2].z,
                    result: &v37->startAxis,
                    a: v11);
            v290.mat[2] = v58->mat[0];
            v291 = v58->mat[1];
            x = v58->mat[2].x;
            v293 = v58->mat[2].y;
            v57 = v58->mat[2].z;
            break;
          default:
            goto LABEL_56;
        }
LABEL_55:
        v294 = v57;
LABEL_56:
        v66 = idAngles::ToMat3(
                this: (idAngles *)&v340.actionBuffer[1].axis.mat[2].z,
                result: (idMat3 *)&v37->randomAngles);
        idMat3::operator*(this: (idMat3 *)&v340.actionBuffer[3].immediate, result: v66, a: &v30->rotOffset);
        v68 = (float *)idMat3::operator*(
                         this: (idMat3 *)&v340.actionBuffer[1].axis.mat[2].z,
                         result: (idMat3 *)&v340.actionBuffer[3].immediate,
                         a: (const idMat3 *)&v290.mat[2]);
        v290.mat[2].x = *v68;
        v69 = v10->x;
        v70 = v68[1];
        v71 = v10->y;
        v290.mat[2].y = v68[1];
        DWORD2(v23) = LODWORD(v10->z);
        v72 = v68[2];
        v290.mat[2].z = v68[2];
        v73 = v68[3];
        v291.x = v68[3];
        v74 = v68[4];
        v291.y = v68[4];
        v75 = v68[5];
        v291.z = v68[5];
        v76 = v68[6];
        x = v68[6];
        v77 = v68[7];
        v293 = v68[7];
        v78 = v68[8];
        v294 = v68[8];
        v290.mat[0].x = v69;
        v290.mat[0].y = v71;
        v290.mat[0].z = *((float *)&v23 + 2);
        originType = v30->originType;
        switch ( originType )
        {
          case FX_ORG_TRACK_POS:
            v80 = v304.y;
            v290.mat[0].x = v304.x;
            v290.mat[0].z = v304.z;
            break;
          case FX_ORG_EXTERNALPOS:
            v81 = this->externalPosition.z;
            v80 = this->externalPosition.y;
            v290.mat[0].x = this->externalPosition.x;
            v290.mat[0].z = v81;
            break;
          case FX_ORG_TRACK_LOCAL_POS:
            v82 = v10->x;
            v83 = (float)((float)(v37->startOrg.x * v11->mat[0].x)
                        + (float)((float)(v11->mat[1].x * v37->startOrg.y) + (float)(v11->mat[2].x * v37->startOrg.z)));
            v80 = (float)(v10->y
                        + (float)((float)(v11->mat[2].y * v37->startOrg.z)
                                + (float)((float)(v11->mat[0].y * v37->startOrg.x)
                                        + (float)(v11->mat[1].y * v37->startOrg.y))));
            v290.mat[0].z = v10->z
                          + (float)((float)(v11->mat[2].z * v37->startOrg.z)
                                  + (float)((float)(v11->mat[0].z * v37->startOrg.x)
                                          + (float)(v11->mat[1].z * v37->startOrg.y)));
            v290.mat[0].x = (float)v83 + (float)v82;
            break;
          default:
LABEL_63:
            valueInteger = v24->valueInteger;
            v85 = v30->offset.y;
            v86 = (float)((float)(v30->offset.x * (float)v72) + (float)(v30->offset.z * (float)v78));
            v87 = (float)((float)(v30->offset.x * v290.mat[2].x) + (float)(v30->offset.z * (float)v76));
            v290.mat[0].y = (float)((float)(v30->offset.y * (float)v74)
                                  + (float)((float)(v30->offset.x * (float)v70) + (float)(v30->offset.z * (float)v77)))
                          + v290.mat[0].y;
            v290.mat[0].z = (float)((float)((float)v85 * (float)v75) + (float)v86) + v290.mat[0].z;
            v88 = (float)((float)((float)((float)v85 * (float)v73) + (float)v87) + v290.mat[0].x);
            v290.mat[0].x = (float)((float)((float)v85 * (float)v73) + (float)v87) + v290.mat[0].x;
            if ( valueInteger == 1 )
            {
              v89 = common->RW(this: common);
              v89->DebugAxis_2(this: v89, a2: v290.mat, a3: (const idMat3 *)&v290.mat[2], a4: 0, a5: false);
              v88 = v290.mat[0].x;
            }
            v90 = 0;
            v91 = (float)(v30->distance * v30->distance);
            v92 = 0;
            if ( v20->num > 0 )
            {
              v93 = 0;
              v94 = &v340.actionBuffer[4].axis.mat[2].z;
              do
              {
                v20->list[v93]->GetViewPosition(this: v20->list[v93], a2: (idVec3 *)(v94 - 1), a3: (idMat3 *)(v94 + 2));
                v88 = v290.mat[0].x;
                v95 = (float)((float)((float)(v94[1] - v290.mat[0].z) * (float)(v94[1] - v290.mat[0].z))
                            + (float)((float)((float)(*(v94 - 1) - v290.mat[0].x) * (float)(*(v94 - 1) - v290.mat[0].x))
                                    + (float)((float)(*v94 - v290.mat[0].y) * (float)(*v94 - v290.mat[0].y))));
                v94[11] = (float)((float)(v94[1] - v290.mat[0].z) * (float)(v94[1] - v290.mat[0].z))
                        + (float)((float)((float)(*(v94 - 1) - v290.mat[0].x) * (float)(*(v94 - 1) - v290.mat[0].x))
                                + (float)((float)(*v94 - v290.mat[0].y) * (float)(*v94 - v290.mat[0].y)));
                if ( v30->distance == -1.0 || v95 < v91 )
                {
                  v90 = 1;
                  *((_BYTE *)v94 + 48) = 1;
                }
                else
                {
                  *((_BYTE *)v94 + 48) = 0;
                }
                ++v92;
                ++v93;
                v94 += 14;
              }
              while ( v92 < v20->num );
            }
            str = (char *)v30->fire.str;
            if ( str == &byte_8200D768 || (v98 = *str != 0, v97 = 0, !v98) )
              v97 = 1;
            if ( v97 == 0 && v25->shouldTrigger )
            {
              v99 = this->fxDecl;
              v100 = 0;
              if ( v99->events.num > 0 )
              {
                v101 = 0;
                v102 = 0;
                do
                {
                  v103 = &this->actionState.list[v102];
                  if ( idStr::Icmp(s1: v99->events.list[v101].name.str, s2: v30->fire.str) == 0 && v103->hidden )
                  {
                    v103->startTime = time;
                    v103->startDelay = 0;
                    v103->hidden = false;
                    v103->shouldTrigger = true;
                    v103->forceStop = false;
                    idFXManager::StartAction(
                      this,
                      i: v100,
                      org: v290.mat,
                      axis: (const idMat3 *)&v290.mat[2],
                      time,
                      tagIdx: -1);
                  }
                  v99 = this->fxDecl;
                  ++v100;
                  ++v102;
                  ++v101;
                }
                while ( v100 < v99->events.num );
              }
              v25->shouldTrigger = false;
              v88 = v290.mat[0].x;
              v22 = v301;
            }
            switch ( v30->type )
            {
              case FX_LIGHT:
                rLight = (float *)v37->rLight;
                if ( rLight != nullptr )
                {
                  v105 = 0;
                  if ( v30->originType != FX_ORG_START_POS )
                  {
                    v106 = v290.mat[0].y;
                    v107 = v290.mat[0].z;
                    v108 = v290.mat[0].x;
                    rLight[9] = v88;
                    v109 = &v340.actionBuffer[0].axis.mat[2];
                    v316.mat[1].z = v106;
                    v316.mat[2].x = v107;
                    v110 = 9;
                    v316.mat[1].y = v108;
                    rLight[11] = v107;
                    rLight[10] = v106;
                    v111 = &v290.mat[1].z;
                    do
                    {
                      ++v111;
                      v109 = (idVec3 *)((char *)v109 + 4);
                      v109->x = *v111;
                      --v110;
                    }
                    while ( v110 != 0 );
                    v112 = (float *)v37->rLight;
                    v113 = *(float *)&v340.actionBuffer[0].time;
                    v105 = 1;
                    v114 = v340.actionBuffer[0].axis.mat[2].z;
                    v115 = *(float *)&v340.actionBuffer[0].condition;
                    DWORD2(v23) = v112 + 6;
                    v116 = *(float *)&v340.actionBuffer[0].extraCondition;
                    *v112 = v290.mat[2].x;
                    v112[3] = v113;
                    v112[1] = v114;
                    v112[2] = v115;
                    v117 = *(float *)&v340.actionBuffer[0].tagIdx;
                    v112[4] = v116;
                    v118 = *(float *)&v340.actionBuffer[0].actionType;
                    v112[5] = v117;
                    v119 = *(float *)&v340.actionBuffer[0].immediate;
                    v112[6] = v118;
                    v120 = *(float *)&v340.actionBuffer[0].viewCallbacksID;
                    v112[7] = v119;
                    v112[8] = v120;
                  }
                  if ( v30->colorTableRGB != nullptr || v30->colorTableA != nullptr )
                  {
                    TableColor = (float *)idFXManager::GetTableColor(
                                            this: (idFXManager *)&v340.actionBuffer[3].org.y,
                                            result: (idVec4 *)this,
                                            fxaction: v30,
                                            pct: v32);
                    v122 = (float)(v30->color.w * TableColor[3]);
                    v123 = (float)(v30->color.z * TableColor[2]);
                    v124 = TableColor[1];
                    v125 = (float)(v30->color.x * *TableColor);
                    v126 = v30->color.y;
                    v306.x = v30->color.x * *TableColor;
                    v306.z = v123;
                    v306.w = v122;
                    v306.y = (float)v126 * (float)v124;
                    intensity = v30->lightParms.intensity;
                    v128 = (float)(v306.y * v30->lightParms.intensity);
                    v306.x = (float)v125 * v30->lightParms.intensity;
                    v306.y = v128;
                    v306.w = (float)v122 * (float)intensity;
                    v306.z = (float)v123 * (float)intensity;
                    idRenderLight::SetParm(this: v37->rLight, parm: rp->lightColor, v4: &v306);
                    v105 = 1;
                  }
                  v129 = v37->rLight;
                  if ( v129->unlinked )
                    v105 = 1;
                  if ( v105 != 0 )
                    idRenderLight::CommitThisFrame(this: v129);
                  goto LABEL_277;
                }
                goto LABEL_278;
              case FX_PARTICLE:
                if ( v30->particleParms.useSmokeSystem )
                {
                  if ( v90 != 0 )
                  {
                    if ( !v25->started )
                    {
                      v37->lastParticleDropPos.x = v88;
                      v37->lastParticleDropPos.y = v290.mat[0].y;
                      v37->lastParticleDropPos.z = v290.mat[0].z;
                      v25->started = true;
                      v88 = v290.mat[0].x;
                    }
                    v216 = v295->y;
                    v217 = v295->z;
                    v302[0] = v295->x;
                    v302[1] = v216;
                    v302[2] = v217;
                    if ( !v30->particleParms.trackVelocity
                      || (v218 = (float)(v298.y * v30->particleParms.velocityScale),
                          v219 = (float)(v30->particleParms.velocityScale * v298.x),
                          v220 = (float)(v298.z * v30->particleParms.velocityScale),
                          v302[2] = v298.z * v30->particleParms.velocityScale,
                          v302[1] = v218,
                          v302[0] = v219,
                          (float)((float)((float)v220 * (float)v220)
                                + (float)((float)((float)v219 * (float)v219) + (float)((float)v218 * (float)v218))) >= (double)(float)(v30->particleParms.minVelocity * v30->particleParms.minVelocity)) )
                    {
                      v221 = v37->lastParticleDropPos.z;
                      p_x = &v37->lastParticleDropPos.x;
                      v223 = v37->lastParticleDropPos.y;
                      v305.x = (float)v88 - v37->lastParticleDropPos.x;
                      v305.z = v290.mat[0].z - (float)v221;
                      v305.y = v290.mat[0].y - (float)v223;
                      v227 = idVec3::NormalizeFast(this: &v305);
                      trailSpacing = v30->particleParms.trailSpacing;
                      if ( trailSpacing <= 0.0 || v227 <= 0.00000011920929 )
                      {
                        smokeSystemRate = v30->particleParms.smokeSystemRate;
                        if ( smokeSystemRate == 0
                          || (__twllei(smokeSystemRate, 0),
                              HIDWORD(v23) = __ROL4__(frameNum, 1) - 1,
                              __twlgei(smokeSystemRate & ~HIDWORD(v23), 0xFFFFFFFF),
                              v98 = frameNum % smokeSystemRate != 0,
                              v247 = 0,
                              !v98) )
                        {
                          v247 = 1;
                        }
                        if ( v247 != 0 )
                        {
                          v248 = *v22;
                          v249 = 1664525 * this->random.seed;
                          v314.y = NAN;
                          v250 = ((v249 + 1013904223) >> 10) & 0x7FFF;
                          this->random.seed = v249 + 1013904223;
                          *(_QWORD *)&v340.actionBuffer[0].org.z = *(_QWORD *)(&v226 - 1);
                          idRenderModelEffects::AddParticles(
                            this: this->gameLibEffects->effectsModel,
                            particle: v30->particleParms.declPrt,
                            systemStartTime: time,
                            gameMsPerFrame,
                            diversity: (float)((float)*(__int64 *)(&v226 - 1) * (float)v248),
                            origin: (const idVec3 *)(v249 + 1013904223),
                            axis: &v290,
                            velocity: &v290.mat[2],
                            color: (const unsigned int *)v302);
                        }
                      }
                      else if ( v227 > trailSpacing )
                      {
                        v229 = v305.z;
                        v230 = v305.y;
                        v231 = 1;
                        v232 = v305.x;
                        v312 = (int)(float)((float)v227 / v30->particleParms.trailSpacing);
                        v233 = v312;
                        if ( v312 >= 1 )
                        {
                          do
                          {
                            LODWORD(v234) = v231;
                            HIDWORD(v234) = this->random.seed;
                            v235 = v30->particleParms.trailSpacing;
                            *(_QWORD *)&v340.externalRotation.mat[2].y = v234;
                            v236 = v37->lastParticleDropPos.z;
                            v314.x = NAN;
                            v237 = *p_x;
                            v238 = v37->lastParticleDropPos.y;
                            v239 = *v22;
                            v240 = 1664525 * HIDWORD(v234) + 1013904223;
                            LODWORD(v225) = (v240 >> 10) & 0x7FFF;
                            this->random.seed = v240;
                            *(_QWORD *)&v340.actionBuffer[1].org.y = v225;
                            gameLibEffects = this->gameLibEffects;
                            v326.mat[0].z = (float)v236
                                          + (float)((float)v229
                                                  * (float)((float)*(__int64 *)&v340.externalRotation.mat[2].y
                                                          * (float)v235));
                            v326.mat[0].x = (float)v237
                                          + (float)((float)v232
                                                  * (float)((float)*(__int64 *)&v340.externalRotation.mat[2].y
                                                          * (float)v235));
                            v326.mat[0].y = (float)v238
                                          + (float)((float)v230
                                                  * (float)((float)*(__int64 *)&v340.externalRotation.mat[2].y
                                                          * (float)v235));
                            idRenderModelEffects::AddParticles(
                              this: gameLibEffects->effectsModel,
                              particle: v30->particleParms.declPrt,
                              systemStartTime: time,
                              gameMsPerFrame,
                              diversity: (float)((float)v225 * (float)v239),
                              origin: &v314,
                              axis: &v326,
                              velocity: &v290.mat[2],
                              color: (const unsigned int *)v302);
                            ++v231;
                          }
                          while ( v231 <= v233 );
                        }
                        LODWORD(v224) = v233;
                        v242 = v30->particleParms.trailSpacing;
                        v243 = *p_x;
                        *(_QWORD *)&v340.actionBuffer[0].axis.mat[0].y = v224;
                        v244 = v37->lastParticleDropPos.y;
                        v245 = v37->lastParticleDropPos.z;
                        *p_x = (float)v243 + (float)((float)((float)v224 * (float)v242) * (float)v232);
                        v37->lastParticleDropPos.z = (float)v245
                                                   + (float)((float)v229 * (float)((float)v224 * (float)v242));
                        v37->lastParticleDropPos.y = (float)v244
                                                   + (float)((float)v230 * (float)((float)v224 * (float)v242));
                      }
                    }
                  }
                }
                else
                {
                  if ( v37->rParticle == nullptr )
                    v37->rParticle = idFXModelRecycler::GetParticleFxModel(
                                       this: &this->gameLibEffects->fxModelRecycler,
                                       particleDecl: (const idMaterial *)v30->particleParms.declPrt,
                                       rw: this->rw);
                  rParticle = v37->rParticle;
                  if ( rParticle != nullptr )
                  {
                    rParticle->g.allowSurfaceOnlyInViewID = this->allowSurfaceOnlyInViewID;
                    rParticle->g.suppressSurfaceInViewID = this->suppressSurfaceInViewID;
                    if ( !v30->particleParms.isScreenPrt )
                    {
                      idFXManager::GetTableColor(this: &v340, result: (idVec4 *)this, fxaction: v30, pct: v32);
                      w = v30->color.w;
                      v199 = (float)(v30->color.x * *(float *)&v340.initialized);
                      v200 = (float)(v30->color.z * *(float *)&v340.gameLibEffects);
                      v201 = this->systemColor.x;
                      v315.y = this->systemColor.y * (float)(v30->color.y * *(float *)&v340.fxDecl);
                      v315.x = (float)v201 * (float)v199;
                      v202 = (float)(this->systemColor.z * (float)v200);
                      v315.w = this->systemColor.w * (float)((float)w * *(float *)&v340.ta);
                      v315.z = v202;
                      v203 = v37->rParticle;
                      if ( v203->unlinked )
                      {
                        if ( !v203->deferredPositionInitialized || !v203->useDeferredPosition )
                          v203->g.origin = v290.mat[0];
                        v203->deferredOrigin = v290.mat[0];
                        idRenderModel::SetAxis(this: v37->rParticle, a: (const idMat3 *)&v290.mat[2]);
                        v204 = *v22;
                        v205 = 1664525 * this->random.seed + 1013904223;
                        LODWORD(v206) = (v205 >> 10) & 0x7FFF;
                        this->random.seed = v205;
                        *(_QWORD *)&v340.actionBuffer[0].org.x = v206;
                        idRenderModel::SetParm(
                          this: v37->rParticle,
                          parm: rp->Diversity,
                          scalar: (float)((float)v206 * (float)v204));
                        idRenderModel::SetParm(this: v37->rParticle, parm: rp->TimeStop, scalar: 0.0);
                        idRenderModel::SetParm(
                          this: v37->rParticle,
                          parm: rp->TimeOffset,
                          scalar: (float)((float)v31 * (float)0.001));
                        if ( v30->noshadows )
                          v207 = 1.0;
                        else
                          v207 = 0.0;
                        idRenderModel::SetParm(this: v37->rParticle, parm: rp->NoShadows, scalar: v207);
                        v208 = v299;
                        idRenderModel::SetParm(this: v37->rParticle, parm: (const idDeclRenderParm *)v299->r, v3: v295);
                        idRenderModel::SetParm(this: v37->rParticle, parm: rp->Color, v4: &v315);
                        idRenderModel::CommitThisFrame(this: v37->rParticle);
                      }
                      else
                      {
                        v208 = v299;
                      }
                      if ( v30->originType != FX_ORG_START_POS )
                      {
                        *(float *)&v209 = v295->y;
                        v210 = v295->z;
                        v297.x = v295->x;
                        v297.y = *(float *)&v209;
                        v297.z = v210;
                        if ( v30->particleParms.trackVelocity )
                        {
                          velocityScale = v30->particleParms.velocityScale;
                          LODWORD(v209) = gameMsPerFrame;
                          v297.x = (float)(v298.x * v30->particleParms.velocityScale)
                                 * (float)((float)1.0 / (float)v209);
                          *(_QWORD *)&v340.actionBuffer[1].axis.mat[0].z = v209;
                          v297.y = (float)(v298.y * (float)velocityScale) * (float)((float)1.0 / (float)v209);
                          v297.z = (float)(v298.z * (float)velocityScale) * (float)((float)1.0 / (float)v209);
                        }
                        v212 = v37->rParticle;
                        v213 = (float)(v297.z + v290.mat[0].z);
                        v214 = (float)(v297.y + v290.mat[0].y);
                        v215 = (float)(v290.mat[0].x + v297.x);
                        if ( !v212->deferredPositionInitialized || !v212->useDeferredPosition )
                        {
                          v212->g.origin.x = v290.mat[0].x + v297.x;
                          v212->g.origin.y = v214;
                          v212->g.origin.z = v213;
                        }
                        v212->deferredOrigin.z = v213;
                        v212->deferredOrigin.x = v215;
                        v212->deferredOrigin.y = v214;
                        idRenderModel::SetAxis(this: v37->rParticle, a: (const idMat3 *)&v290.mat[2]);
                        v37->rParticle->g.fovScale = fovScale;
                        v37->rParticle->g.modelDepthHack = depthHack;
                        idRenderModel::SetParm(this: v37->rParticle, parm: (const idDeclRenderParm *)v208->r, v3: &v297);
                        idRenderModel::SetParm(this: v37->rParticle, parm: rp->Color, v4: &v315);
                        idRenderModel::CommitThisFrame(this: v37->rParticle);
                      }
                      if ( v30->colorTableRGB != nullptr || v30->colorTableA != nullptr )
                      {
                        idRenderModel::SetParm(this: v37->rParticle, parm: rp->Color, v4: &v315);
                        idRenderModel::CommitThisFrame(this: v37->rParticle);
                      }
                      goto LABEL_277;
                    }
                    if ( !v25->started )
                    {
                      v192 = 0;
                      if ( v20->num > 0 )
                      {
                        v193 = v314.z;
                        v194 = 0;
                        v195 = v296;
                        v196 = &v340.actionBuffer[5].axis.mat[0].y;
                        while ( 1 )
                        {
                          if ( v195->valueInteger == 2 )
                          {
                            v197 = common->RW(this: common);
                            ((void (__fastcall *)(idRenderWorld *, double, idMat3 *, idVec3 *, int, _DWORD))v197->DebugAxis)(
                              a1: v197,
                              a2: COERCE_DOUBLE(LODWORD(v193)),
                              a3: &v290,
                              a4: &v290.mat[2],
                              a5: 10000,
                              a6: 0);
                          }
                          if ( *(_BYTE *)v196 != 0
                            && (v37->viewCallbacksID < 0
                             || v20->list[v194]->GetViewID(this: v20->list[v194]) == v37->viewCallbacksID) )
                          {
                            break;
                          }
                          ++v192;
                          v196 += 14;
                          ++v194;
                          if ( v192 >= v20->num )
                          {
                            v25->started = true;
                            goto LABEL_278;
                          }
                        }
                        v37->screenPrtHandle = v20->list[v192]->AddScreenParticle(
                                                 this: v20->list[v192],
                                                 a2: v37->rParticle,
                                                 a3: v30->particleParms.screenPrtExcludeAngle);
                      }
                      v25->started = true;
                    }
                  }
                }
                break;
              case FX_DECAL:
                if ( !v25->started && v30->decalParms.decalMtr != nullptr && this->gameLibEffects->decalModel != nullptr )
                {
                  v25->started = true;
                  v134 = v30->rotationType;
                  v135 = (float)(v30->fadeOutTime * (float)1000.0);
                  v136 = (float)(v30->fadeInTime * (float)1000.0);
                  LODWORD(v340.actionBuffer[1].axis.mat[0].y) = (int)(float)(v30->duration * (float)1000.0);
                  v312 = (int)v136;
                  if ( v134 == FX_ROT_START_AXIS )
                  {
                    v290.mat[2] = v37->startAxis.mat[0];
                    v291 = v37->startAxis.mat[1];
                    x = v37->startAxis.mat[2].x;
                    v293 = v37->startAxis.mat[2].y;
                    v294 = v37->startAxis.mat[2].z;
                  }
                  v307[2] = 32.0;
                  v307[3] = 32.0;
                  LODWORD(v307[6]) = 2000;
                  v307[4] = 0.0;
                  LODWORD(v307[5]) = 10000;
                  v307[1] = 8.0;
                  HIBYTE(v307[8]) = 0;
                  v307[0] = 0.0;
                  v307[7] = 0.0;
                  v325 = v290.mat[2];
                  v137 = this->gameLibEffects;
                  v307[0] = *(float *)&v30->decalParms.decalMtr;
                  v307[1] = v30->decalParms.depth;
                  size = v30->size;
                  v307[2] = v30->size;
                  v307[3] = size;
                  v307[4] = v30->decalParms.angle;
                  v307[5] = v340.actionBuffer[1].axis.mat[0].y;
                  HIBYTE(v307[8]) = 0;
                  LODWORD(v307[7]) = (int)v136;
                  LODWORD(v307[6]) = (int)v135;
                  v137->decalModel->AddDecalFromPoint(
                    this: (idRenderModel *)&v340.externalPosition.z,
                    result: (idHandle<int,enum invalidDecalHandle_t,-1> *)v137->decalModel,
                    a3: (const decalParams_t *)v307,
                    a4: time,
                    a5: v290.mat,
                    a6: &v325,
                    a7: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)NULL_JOINT_INDEX.value);
                }
                goto LABEL_278;
              case FX_DECAL2:
                rModel = v37->rModel;
                if ( rModel != nullptr )
                {
                  if ( rModel->unlinked )
                  {
                    v140 = this->systemColor.z;
                    v141 = v30->color.w;
                    v142 = this->systemColor.w;
                    v143 = v30->color.z;
                    v144 = this->systemColor.x;
                    v145 = v30->color.y;
                    v146 = v30->color.x;
                    v334 = this->systemColor.y;
                    v335 = v140;
                    v336 = v142;
                    v333 = v144;
                    v326.mat[2].z = (float)v143 * v140;
                    v327 = (float)v141 * v142;
                    v326.mat[2].x = (float)v146 * v144;
                    v326.mat[2].y = (float)v145 * v334;
                    idRenderModel::SetParm(this: v37->rModel, parm: rp->Color, v4: (const idVec4 *)&v326.mat[2]);
                    v147 = v37->rModel;
                    if ( !v147->deferredPositionInitialized || !v147->useDeferredPosition )
                      v147->g.origin = v290.mat[0];
                    v147->deferredOrigin = v290.mat[0];
                    idRenderModel::SetAxis(this: v37->rModel, a: (const idMat3 *)&v290.mat[2]);
                    idRenderModel::CommitThisFrame(this: v37->rModel);
                  }
                  if ( v30->originType != FX_ORG_START_POS )
                  {
                    v148 = this->systemColor.y;
                    v149 = v30->color.w;
                    v150 = this->systemColor.z;
                    v151 = v30->color.z;
                    v152 = this->systemColor.w;
                    v153 = v30->color.y;
                    v154 = v30->color.x;
                    v340.rw = (idRenderWorld *)LODWORD(this->systemColor.x);
                    v340.systemColor.x = v148;
                    v340.systemColor.y = v150;
                    v340.systemColor.z = v152;
                    v339.x = *(float *)&v340.rw * (float)v154;
                    v339.w = (float)v149 * v152;
                    v339.z = (float)v151 * v150;
                    v339.y = (float)v153 * v148;
                    idRenderModel::SetParm(this: v37->rModel, parm: rp->Color, v4: &v339);
                    v155 = v37->rModel;
                    if ( !v155->deferredPositionInitialized || !v155->useDeferredPosition )
                      v155->g.origin = v290.mat[0];
                    v155->deferredOrigin = v290.mat[0];
                    idRenderModel::SetAxis(this: v37->rModel, a: (const idMat3 *)&v290.mat[2]);
                    v37->rModel->g.fovScale = fovScale;
                    v37->rModel->g.modelDepthHack = depthHack;
                    idRenderModel::CommitThisFrame(this: v37->rModel);
                  }
                  if ( v30->customRenderParm != nullptr )
                  {
                    v308.y = 0.0;
                    v308.z = 0.0;
                    v308.x = 0.0;
                    customTable1 = v30->customTable1;
                    if ( customTable1 != nullptr )
                      v308.x = idLookupTable::TableLookup(this: customTable1->table, time: v32, fastSearch: v67);
                    customTable2 = v30->customTable2;
                    if ( customTable2 != nullptr )
                      v308.y = idLookupTable::TableLookup(this: customTable2->table, time: v32, fastSearch: v67);
                    idRenderModel::SetParm(this: v37->rModel, parm: v30->customRenderParm, v3: &v308);
                    idRenderModel::CommitThisFrame(this: v37->rModel);
                  }
                  goto LABEL_277;
                }
                goto LABEL_278;
              case FX_MODEL:
                if ( v37->rModel == nullptr )
                  v37->rModel = idFXModelRecycler::GetStaticFxModel(
                                  this: &this->gameLibEffects->fxModelRecycler,
                                  name: &v30->modelParms.modelName,
                                  rw: this->rw);
                v251 = v37->rModel;
                if ( v251 != nullptr )
                {
                  if ( v251->unlinked )
                  {
                    v252 = this->systemColor.y;
                    v253 = v30->color.w;
                    v254 = this->systemColor.z;
                    v255 = v30->color.z;
                    v256 = this->systemColor.w;
                    v257 = v30->color.y;
                    v258 = v30->color.x;
                    v328 = this->systemColor.x;
                    v329 = v252;
                    v330 = v254;
                    v331 = v256;
                    v340.systemColor.w = (float)v258 * v328;
                    *(float *)&v340.soundInfo.channel = (float)v253 * v256;
                    *(float *)&v340.soundInfo.emitter = (float)v255 * v254;
                    *(float *)&v340.random.seed = (float)v257 * v252;
                    idRenderModel::SetParm(this: v37->rModel, parm: rp->Color, v4: (const idVec4 *)&v340.systemColor.w);
                    v259 = v37->rModel;
                    if ( !v259->deferredPositionInitialized || !v259->useDeferredPosition )
                      v259->g.origin = v290.mat[0];
                    v259->deferredOrigin = v290.mat[0];
                    idRenderModel::SetAxis(this: v37->rModel, a: (const idMat3 *)&v290.mat[2]);
                    idRenderModel::CommitThisFrame(this: v37->rModel);
                  }
                  if ( v30->originType != FX_ORG_START_POS )
                  {
                    y_low = SLODWORD(this->systemColor.y);
                    v261 = v30->color.w;
                    z_low = SLODWORD(this->systemColor.z);
                    v263 = v30->color.z;
                    v264 = this->systemColor.w;
                    v265 = v30->color.y;
                    v266 = v30->color.x;
                    v340.actionState.list = (fxActionState_t *)LODWORD(this->systemColor.x);
                    v340.actionState.num = y_low;
                    v340.actionState.size = z_low;
                    *(float *)&v340.actionState.granularity = v264;
                    v337.x = *(float *)&v340.actionState.list * (float)v266;
                    v337.w = (float)v261 * v264;
                    v337.z = (float)v263 * *(float *)&z_low;
                    v337.y = (float)v265 * *(float *)&y_low;
                    idRenderModel::SetParm(this: v37->rModel, parm: rp->Color, v4: &v337);
                    v267 = v37->rModel;
                    if ( !v267->deferredPositionInitialized || !v267->useDeferredPosition )
                      v267->g.origin = v290.mat[0];
                    v267->deferredOrigin = v290.mat[0];
                    idRenderModel::SetAxis(this: v37->rModel, a: (const idMat3 *)&v290.mat[2]);
                    v37->rModel->g.fovScale = fovScale;
                    v37->rModel->g.modelDepthHack = depthHack;
                    idRenderModel::CommitThisFrame(this: v37->rModel);
                  }
                  if ( v30->customRenderParm != nullptr )
                  {
                    v309.x = 0.0;
                    v309.y = 0.0;
                    v309.z = 0.0;
                    v268 = v30->customTable1;
                    if ( v268 != nullptr )
                      v309.x = idLookupTable::TableLookup(this: v268->table, time: v32, fastSearch: v67);
                    v269 = v30->customTable2;
                    if ( v269 != nullptr )
                      v309.y = idLookupTable::TableLookup(this: v269->table, time: v32, fastSearch: v67);
                    idRenderModel::SetParm(this: v37->rModel, parm: v30->customRenderParm, v3: &v309);
                    idRenderModel::CommitThisFrame(this: v37->rModel);
                  }
                  goto LABEL_277;
                }
                goto LABEL_278;
              case FX_SOUND:
                if ( v30->soundParms.sound != nullptr )
                {
                  if ( v25->started )
                  {
                    if ( v30->originType != FX_ORG_TRACK_POS )
                    {
                      emitter = this->soundInfo.emitter;
                      if ( emitter != nullptr )
                        ((void (*)(void))emitter->UpdateEmitter)();
                    }
                  }
                  else
                  {
                    v25->started = true;
                    if ( !this->remote || (sound = v30->soundParms.sound->remoteSound) == nullptr )
                      sound = v30->soundParms.sound;
                    idFXManager::StartSound(this, channel: v30->soundParms.channel, shader: sound);
                    if ( v30->fadeInTime != 0.0 )
                    {
                      channel = v30->soundParms.channel;
                      if ( this->soundInfo.emitter != nullptr )
                      {
                        if ( channel == SND_CHANNEL_ANY )
                          channel = this->soundInfo.channel;
                        this->soundInfo.emitter->SetVolume(this: this->soundInfo.emitter, a2: channel, a3: v22[1]);
                      }
                      v132 = v30->soundParms.channel;
                      if ( this->soundInfo.emitter != nullptr )
                      {
                        if ( v132 == SND_CHANNEL_ANY )
                          v132 = this->soundInfo.channel;
                        ((void (__fastcall *)(idSoundEmitter *, soundChannel_t, double, double, double))this->soundInfo.emitter->FadeSound)(
                          a1: this->soundInfo.emitter,
                          a2: v132,
                          a3: 0.0,
                          a4: v30->fadeInTime,
                          a5: 0.0);
                      }
                    }
                  }
                  goto LABEL_277;
                }
                goto LABEL_278;
              case FX_SCREEN_SHAKE:
                if ( !v25->started )
                {
                  v158 = 0;
                  if ( v20->num > 0 )
                  {
                    v159 = v313;
                    v160 = 0;
                    v161 = v296;
                    v162 = &v340.actionBuffer[5].axis.mat[0].y;
                    do
                    {
                      if ( *(_BYTE *)v162 != 0
                        && (v37->viewCallbacksID < 0
                         || v37->viewCallbacksID == v20->list[v160]->GetViewID(this: v20->list[v160])) )
                      {
                        if ( v161->valueInteger == 1 )
                          idLib::Printf(fmt: v159, this->fxDecl->name.str, v30->name.str);
                        ((void (__fastcall *)(idViewCallbacks *, BOOL, float *, float *, double))v20->list[v160]->ApplyScreenShake)(
                          a1: v20->list[v160],
                          a2: v67,
                          a3: &v30->screenShakeParms.maxAngles.pitch,
                          a4: &v30->screenShakeParms.maxOffset.x,
                          a5: v30->screenShakeParms.magnitude);
                      }
                      ++v158;
                      v162 += 14;
                      ++v160;
                    }
                    while ( v158 < v20->num );
                  }
                  v25->started = true;
                }
                goto LABEL_278;
              case FX_CONTROLLER_SHAKE:
                if ( !v25->started )
                {
                  v163 = 0;
                  if ( v20->num > 0 )
                  {
                    v164 = 0;
                    v165 = &v340.actionBuffer[5].axis.mat[0].y;
                    do
                    {
                      if ( *(_BYTE *)v165 != 0
                        && (v37->viewCallbacksID < 0
                         || v37->viewCallbacksID == v20->list[v164]->GetViewID(this: v20->list[v164])) )
                      {
                        v20->list[v164]->ApplyControllerShake(
                          this: v20->list[v164],
                          a2: v30->controllerShakeParms.highDuration,
                          a3: v30->controllerShakeParms.lowDuration,
                          a4: v30->controllerShakeParms.highMag,
                          a5: v30->controllerShakeParms.lowMag);
                      }
                      ++v163;
                      v165 += 14;
                      ++v164;
                    }
                    while ( v163 < v20->num );
                  }
                  v25->started = true;
                }
                goto LABEL_278;
              case FX_RENDERPARM:
                if ( v25->started )
                  goto LABEL_277;
                Vector = (float *)idFXManager::GetVector(
                                    this: (idFXManager *)&v340.actionBuffer[2].condition,
                                    result: (idVec4 *)this,
                                    parm: v30->renderParmParms.declRenderParm);
                v37->renderParmStartValue.x = *Vector;
                v37->renderParmStartValue.y = Vector[1];
                v37->renderParmStartValue.z = Vector[2];
                v37->renderParmStartValue.w = Vector[3];
                goto LABEL_276;
              case FX_ENV_OVERRIDE:
                if ( !v25->started )
                {
                  v270 = 0;
                  if ( v20->num > 0 )
                  {
                    v271 = 0;
                    v272 = &v340.actionBuffer[5].axis.mat[0].y;
                    do
                    {
                      if ( *(_BYTE *)v272 != 0
                        && (v37->viewCallbacksID < 0
                         || v37->viewCallbacksID == v20->list[v271]->GetViewID(this: v20->list[v271])) )
                      {
                        v20->list[v271]->ApplyDynEnvOverride(
                          this: v20->list[v271],
                          a2: v30->envParms.declEnv,
                          a3: v30->fadeInTime);
                      }
                      ++v270;
                      v272 += 14;
                      ++v271;
                    }
                    while ( v270 < v20->num );
                  }
                  v25->started = true;
                }
                goto LABEL_278;
              case FX_ENV_CHANGE:
                if ( !v25->started )
                {
                  v273 = 0;
                  if ( v20->num > 0 )
                  {
                    v274 = 0;
                    v275 = &v340.actionBuffer[5].axis.mat[0].y;
                    do
                    {
                      if ( *(_BYTE *)v275 != 0
                        && (v37->viewCallbacksID < 0
                         || v37->viewCallbacksID == v20->list[v274]->GetViewID(this: v20->list[v274])) )
                      {
                        v276 = 0;
                        if ( v30->envParms.envRenderParm.num > 0 )
                        {
                          v277 = 0;
                          do
                          {
                            v20->list[v274]->ApplyDynEnvParmOverride(
                              this: v20->list[v274],
                              a2: v30->envParms.envRenderParm.list[v277].parm,
                              a3: &v30->envParms.envRenderParm.list[v277].value,
                              a4: false,
                              a5: v30->fadeInTime);
                            ++v276;
                            ++v277;
                          }
                          while ( v276 < v30->envParms.envRenderParm.num );
                        }
                      }
                      ++v273;
                      v275 += 14;
                      ++v274;
                    }
                    while ( v273 < v20->num );
                  }
                  v22 = v301;
                  v25->started = true;
                }
                goto LABEL_278;
              case FX_FLARE:
                LODWORD(v166) = &v290.mat[2];
                v167 = &v340.actionBuffer[3].axis.mat[0].y;
                v168 = &v290.mat[1].z;
                v303 = v290.mat[0];
                for ( j = 9; j != 0; --j )
                  *++v167 = *++v168;
                if ( v30->originType == FX_ORG_TRACK_POS )
                {
                  v170 = (float)((float)(v30->flareParms.position.y * v291.z)
                               + (float)((float)(v30->flareParms.position.x * v290.mat[2].z)
                                       + (float)(v30->flareParms.position.z * v294)));
                  v171 = (float)((float)(v30->flareParms.position.y * v291.x)
                               + (float)((float)(v290.mat[2].x * v30->flareParms.position.x)
                                       + (float)(v30->flareParms.position.z * x)));
                  v303.y = v290.mat[0].y
                         + (float)((float)(v30->flareParms.position.y * v291.y)
                                 + (float)((float)(v30->flareParms.position.x * v290.mat[2].y)
                                         + (float)(v30->flareParms.position.z * v293)));
                  v303.z = v290.mat[0].z + (float)v170;
                  v303.x = (float)v88 + (float)v171;
                }
                if ( !v37->flareManager.isInitialized )
                {
                  declFlare = v30->flareParms.declFlare;
                  if ( declFlare != nullptr )
                  {
                    v173 = v30->size;
                    v174 = common->RW(this: common);
                    idLensFlareManager::Init(
                      this: &v37->flareManager,
                      renderWorld: v174,
                      flareDecl: declFlare,
                      quadSize: v173,
                      _sunDirection: v175,
                      _occlusionOffset: v295,
                      _isAutosprited: (bool)v295);
                  }
                }
                if ( !v25->started )
                {
                  v176 = (float)(v30->color.w * this->systemColor.w);
                  v177 = (float)(v30->color.z * this->systemColor.z);
                  v178 = (float)(v30->color.y * this->systemColor.y);
                  v332.x = v30->color.x * this->systemColor.x;
                  v332.w = v176;
                  v332.z = v177;
                  v332.y = v178;
                  _FP0 = -v30->distance;
                  __asm { fsel      f2, f0, f26, f2# fadeEndRange }
                  idLensFlareManager::StartFlare(
                    this: &v37->flareManager,
                    org: &v303,
                    axis: (const idMat3 *)&v290.mat[2],
                    color: &v332,
                    fadeStartRange: v30->fadeStartDistance,
                    fadeEndRange: _FP2);
                  v25->started = true;
                }
                if ( v30->colorTableRGB != nullptr || v30->colorTableA != nullptr )
                {
                  v181 = (float)(v30->color.w * this->systemColor.w);
                  v182 = (float)(v30->color.z * this->systemColor.z);
                  v183 = (float)(v30->color.y * this->systemColor.y);
                  v184 = (float)(this->systemColor.x * v30->color.x);
                  v185 = (float *)idFXManager::GetTableColor(
                                    this: (idFXManager *)&v340.actionBuffer[2].actionType,
                                    result: (idVec4 *)this,
                                    fxaction: v30,
                                    pct: v32);
                  v186 = (float)(v185[3] * (float)v181);
                  v187 = (float)(v185[2] * (float)v182);
                  v188 = (float)(v185[1] * (float)v183);
                  v338.x = *v185 * (float)v184;
                  v338.w = v186;
                  v338.z = v187;
                  v338.y = v188;
                  idLensFlareManager::ApplyColor(this: &v37->flareManager, color: &v338);
                }
                HIDWORD(v166) = time;
                idFXManager::ApplyFade(this, fxaction: v30, laction: v37, state: v25, time: v166, pct: v32);
                v189 = v30->rotationType;
                if ( v189 == FX_ROT_TRACK_AXIS || (v190 = false, v189 == FX_ROT_TRACK_AXIS_PARENT) )
                  v190 = true;
                idLensFlareManager::Update(
                  this: &v37->flareManager,
                  org: &v303,
                  axis: (const idMat3 *)&v340.actionBuffer[3].axis.mat[0].z,
                  time,
                  bindOrg: (_cntlzw(v30->originType - 1) & 0x20) != 0,
                  bindAxis: v190);
                goto LABEL_278;
              case FX_RADIAL_BLUR:
                if ( !v25->started )
                {
                  v278 = 0;
                  if ( v20->num > 0 )
                  {
                    v279 = 0;
                    v280 = &v340.actionBuffer[5].axis;
                    do
                    {
                      if ( (v30->distance == -1.0 || v280->mat[0].x < v91)
                        && (v37->viewCallbacksID < 0
                         || v37->viewCallbacksID == v20->list[v279]->GetViewID(this: v20->list[v279])) )
                      {
                        _FP12 = (float)((float)(v280->mat[0].x / (float)v91) - (float)1.0);
                        __asm { fsel      f11, f12, f25, f13 }
                        v20->list[v279]->ApplyRadialBlur(
                          this: v20->list[v279],
                          a2: org,
                          a3: (float)((float)v29 * (float)0.001),
                          a4: v30->duration,
                          a5: (float)((float)1.0 - (float)_FP11),
                          a6: 0.0,
                          a7: v30->radialBlurParms.maxScale);
                      }
                      ++v278;
                      v280 = (idMat3 *)((char *)v280 + 56);
                      ++v279;
                    }
                    while ( v278 < v20->num );
                  }
                  v25->started = true;
                }
                goto LABEL_278;
              case FX_RIBBON:
                if ( !v37->ribbonManager.isInitialized )
                  idRibbonManager::Init(
                    this: &v37->ribbonManager,
                    _ribbonDecl: v30->ribbonParms.declRibbon,
                    _beamModel: this->gameLibEffects->beamModel,
                    _modelManager: &this->gameLibEffects->ribbonModelManager);
                if ( !v25->started )
                {
                  idRibbonManager::StartRibbon(this: &v37->ribbonManager, spawnTime: time, spawnOrg: v290.mat);
                  v25->started = true;
                }
                *(float *)&v340.actions.list = 1.0;
                *(float *)&v340.actions.num = 1.0;
                *(float *)&v340.actions.size = 1.0;
                *(float *)&v340.actions.granularity = 1.0;
                idRibbonManager::UpdateRibbon(
                  this: &v37->ribbonManager,
                  time,
                  org: v290.mat,
                  axis: (const idMat3 *)&v290.mat[2],
                  vel: v295,
                  color: (const idVec4 *)&v340.actions,
                  translate: v295);
                goto LABEL_278;
              case FX_FADE_PARENT:
                if ( !v25->started )
LABEL_276:
                  v25->started = true;
LABEL_277:
                DWORD1(v23) = time;
                idFXManager::ApplyFade(
                  this,
                  fxaction: v30,
                  laction: v37,
                  state: v25,
                  time: *(__int64 *)((char *)&v23 + 4),
                  pct: v32);
                goto LABEL_278;
              default:
                goto LABEL_278;
            }
            goto LABEL_278;
        }
        v290.mat[0].y = v80;
        goto LABEL_63;
      }
      v49 = v11->mat[0].x;
      v50 = v11->mat[0].y;
      v51 = v11->mat[0].z;
      v52 = v11->mat[1].x;
      v53 = v11->mat[1].y;
      v54 = v11->mat[1].z;
      v55 = v11->mat[2].x;
      v56 = v11->mat[2].y;
      v57 = v11->mat[2].z;
    }
LABEL_54:
    v293 = v56;
    x = v55;
    v291.z = v54;
    v291.y = v53;
    v291.x = v52;
    v290.mat[2].z = v51;
    v290.mat[2].y = v50;
    v290.mat[2].x = v49;
    goto LABEL_55;
  }
LABEL_279:
  if ( v310.logIndex >= 0 )
  {
    pLog = v310.pLog;
    v286 = &v310.pLog->logEntries.list[v310.logIndex];
    v287 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v286->totalTicks;
    HIDWORD(totalTicks) = v286->parent;
    LODWORD(v289) = v287 - totalTicks;
    v286->totalTicks = v289;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
LABEL_281:
  RD_EventEnd();
}


// ========================================================================
// __unwind$254237
// EA  : 0x82711D80
// RVA : 0x00711D80
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_254237()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1792 + 1488));
}


// ========================================================================
// __unwind$254238
// EA  : 0x82711DA8
// RVA : 0x00711DA8
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_254238()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1792 + 376));
}


// ========================================================================
// ?StartActions@idFXManager@@AAAHABVidVec3@@ABVidMat3@@HW4fxCondition_t@@W4fxExtraCondition_t@@H@Z
// EA  : 0x82711DD8
// RVA : 0x00711DD8
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

int __fastcall idFXManager::StartActions(
        idFXManager *this,
        const idVec3 *org,
        const idMat3 *axis,
        unsigned int time,
        int startCondition,
        const fxExtraCondition_t extraCondition,
        int explicitTagIdx)
{
  unsigned __int64 v14; // r6
  const char *v15; // r7
  const idDeclFX *fxDecl; // r11
  int num; // r9
  int v18; // r25
  int v19; // r29
  int v20; // r28
  char v21; // r6
  int v22; // r9
  idFXSingleAction *v23; // r7
  int v24; // r11
  int v25; // r9
  int v26; // r8
  fxExtraCondition_t *list; // r7
  int v28; // r10
  int v29; // r11
  fxExtraCondition_t v30; // r5
  const idDeclFX *v31; // r10
  const char *str; // r17
  idFXSingleAction *v33; // r30
  const char *v34; // r16
  const char *v35; // r3
  int v37; // [sp+50h] [-A0h]
  int v38; // [sp+50h] [-A0h]
  idPLogScope v39[19]; // [sp+58h] [-98h] BYREF

  RD_EventBegin(name: "idFX::StartActions");
  LODWORD(v14) = "idFX::StartActions";
  HIDWORD(v14) = 2;
  idPLogScope::idPLogScope(this: v39, pl: &pLog, gMask: v14, label: v15);
  fxDecl = this->fxDecl;
  if ( fxDecl == nullptr )
  {
    idLib::Warning(fmt: "idFX::StartActions - fxDecl is NULL!");
    idPLogScope::~idPLogScope(this: v39);
LABEL_24:
    RD_EventEnd();
    return 0;
  }
  num = this->actions.num;
  if ( num == 0 || (v37 = fxDecl->events.num, num != v37) )
  {
    idPLogScope::~idPLogScope(this: v39);
    goto LABEL_24;
  }
  v18 = 0;
  v19 = 0;
  if ( v37 > 0 )
  {
    v20 = 0;
    do
    {
      v21 = 0;
      v22 = 0;
      v23 = &fxDecl->events.list[v20];
      v38 = v23->startCondition.num;
      if ( v38 > 0 )
      {
        v24 = 0;
        while ( v23->startCondition.list[v24] != startCondition )
        {
          ++v22;
          ++v24;
          if ( v22 >= v38 )
            goto LABEL_13;
        }
        v21 = 1;
      }
LABEL_13:
      v26 = 0;
      v25 = v23->extraCondition.num;
      if ( v25 > 0 )
      {
        list = v23->extraCondition.list;
        v28 = 0;
        v29 = 0;
        do
        {
          v30 = list[v29];
          ++v28;
          ++v29;
          v26 |= v30;
        }
        while ( v28 < v25 );
      }
      if ( v21 != 0 && v26 == extraCondition )
      {
        if ( g_debugFX.valueInteger == 1 )
        {
          v31 = this->fxDecl;
          str = v31->name.str;
          v33 = &v31->events.list[v20];
          v34 = idDeclFX::FXConditionToName(condition: startCondition);
          v35 = idDeclFX::FXActionTypeToName(type: v33->type);
          idLib::Printf(fmt: "Starting FX on %s, event %d, action type %s, start condition %s\n", str, v19, v35, v34);
        }
        idFXManager::StartAction(this, i: v19, org, axis, time, tagIdx: explicitTagIdx);
        ++v18;
      }
      fxDecl = this->fxDecl;
      ++v19;
      ++v20;
    }
    while ( v19 < fxDecl->events.num );
  }
  idPLogScope::~idPLogScope(this: v39);
  RD_EventEnd();
  return v18;
}


// ========================================================================
// __unwind$255592
// EA  : 0x82711FE4
// RVA : 0x00711FE4
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_255592()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$255593
// EA  : 0x8271200C
// RVA : 0x0071200C
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_255593()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 88));
}


// ========================================================================
// ?CreateAction@idFXManager@@AAAXHPAVidRenderWorld@@@Z
// EA  : 0x82712040
// RVA : 0x00712040
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::CreateAction(idFXManager *this, int i, idRenderWorld *rw)
{
  unsigned __int64 v5; // r6
  const char *v6; // r7
  fxActionState_t *list; // r8
  idFXAction *v8; // r7
  __int64 v9; // r5
  idFXSingleAction *v10; // r29
  double x; // fp11
  unsigned int v12; // r11
  double y; // fp10
  double v14; // fp9
  fxActionState_t *v15; // r10
  idFXAction *v16; // r11
  unsigned __int64 v17; // r6
  const char *v18; // r7
  idPLogScope v19; // [sp+50h] [-50h] BYREF
  idPLogScope v20[9]; // [sp+58h] [-48h] BYREF

  RD_EventBegin(name: "idFX::CreateAction");
  LODWORD(v5) = "idFX::CreateAction";
  HIDWORD(v5) = 2;
  idPLogScope::idPLogScope(this: v20, pl: &pLog, gMask: v5, label: v6);
  if ( i < this->actions.num )
  {
    list = this->actionState.list;
    v8 = this->actions.list;
    HIDWORD(v9) = 1664525;
    v10 = &this->fxDecl->events.list[i];
    x = v10->delay.x;
    v12 = 1664525 * this->random.seed + 1013904223;
    this->random.seed = v12;
    y = v10->delay.y;
    v14 = v10->delay.x;
    LODWORD(v9) = (v12 >> 10) & 0x7FFF;
    v19.pLog = (idPLog *)v9;
    v15 = &list[i];
    v15->forceStop = false;
    v15->started = false;
    v15->startTime = -1;
    v16 = &v8[i];
    v15->shouldTrigger = true;
    v19.logIndex = (int)&v16->randomAngles;
    v15->startDelay = (int)(float)((float)((float)((float)((float)v9 * (float)((float)y - (float)v14))
                                                 * (float)0.000030518509)
                                         + (float)x)
                                 * (float)1000.0);
    v16->lastParticleDropPos.z = 0.0;
    v16->lastParticleDropPos.y = 0.0;
    v16->lastParticleDropPos.x = 0.0;
    v16->randomAngles = ang_zero;
    v16->screenPrtHandle = -1;
    if ( v10->triggered )
      v15->hidden = true;
    v16->tagIndex = 0;
    if ( v10->tagNames.num > 0 )
      idFXManager::EnumerateTags(this, tagNames: &v10->tagNames, tagData: &v16->tagData);
    if ( v10->type == FX_MODEL )
    {
      RD_EventBegin(name: "idFX::CreateAction - FX_MODEL");
      LODWORD(v17) = "idFX::CreateAction - FX_MODEL";
      HIDWORD(v17) = 2;
      idPLogScope::idPLogScope(this: &v19, pl: &pLog, gMask: v17, label: v18);
      staticModelManager->FindStaticModel(this: staticModelManager, a2: v10->modelParms.modelName.str, a3: true);
      idPLogScope::~idPLogScope(this: &v19);
      RD_EventEnd();
    }
  }
  idPLogScope::~idPLogScope(this: v20);
  RD_EventEnd();
}


// ========================================================================
// __unwind$255718
// EA  : 0x82712234
// RVA : 0x00712234
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_255718()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$255719
// EA  : 0x8271225C
// RVA : 0x0071225C
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_255719()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$255720
// EA  : 0x82712284
// RVA : 0x00712284
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_255720()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 97));
}


// ========================================================================
// __unwind$255721
// EA  : 0x827122AC
// RVA : 0x007122AC
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_255721()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?FreeActions@idFXManager@@AAAXXZ
// EA  : 0x827122D8
// RVA : 0x007122D8
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::FreeActions(idFXManager *this)
{
  int v2; // r28
  int v3; // r30
  idFXAction *v4; // r31
  idRenderLight *rLight; // r3
  tagData_t *list; // r4
  idFXAction *v7; // r28
  int size; // r31
  idFXAction *v9; // r30
  fxActionState_t *v10; // r4

  v2 = 0;
  if ( this->actions.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->actions.list[v3];
      rLight = v4->rLight;
      if ( rLight != nullptr )
      {
        idRenderLight::Delete(this: rLight);
        v4->rLight = nullptr;
      }
      idLensFlareManager::~idLensFlareManager(this: &v4->flareManager);
      idRibbonManager::Shutdown(this: &v4->ribbonManager);
      if ( v4->tagData.listStatic == 0 || v4->tagData.listStatic == 2 )
      {
        list = v4->tagData.list;
        if ( list != nullptr )
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        v4->tagData.list = nullptr;
        v4->tagData.size = 0;
      }
      ++v2;
      v4->tagData.num = 0;
      ++v3;
    }
    while ( v2 < this->actions.num );
  }
  if ( this->actions.listStatic == 0 || this->actions.listStatic == 2 )
  {
    v7 = this->actions.list;
    if ( v7 != nullptr )
    {
      size = this->actions.size;
      if ( size > 0 )
      {
        v9 = this->actions.list;
        do
        {
          idFXAction::~idFXAction(this: v9);
          --size;
          ++v9;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    }
    this->actions.list = nullptr;
    this->actions.size = 0;
  }
  this->actions.num = 0;
  if ( this->actionState.listStatic == 0 || this->actionState.listStatic == 2 )
  {
    v10 = this->actionState.list;
    if ( v10 != nullptr )
      idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    this->actionState.list = nullptr;
    this->actionState.size = 0;
  }
  this->actionState.num = 0;
}


// ========================================================================
// ?Shutdown@idFXManager@@QAAXXZ
// EA  : 0x82712420
// RVA : 0x00712420
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::Shutdown(idFXManager *this)
{
  int num; // r11
  int v3; // r24
  int v4; // r26
  int v5; // r27
  idFXAction *v6; // r31
  idRenderModelParticle *rParticle; // r29
  idFXSingleAction *v8; // r28
  idRenderModel *rModel; // r29

  if ( this->initialized )
  {
    idFXManager::StopAllFX(this, time: -1, immediateStop: true);
    num = this->actions.num;
    v3 = 0;
    this->initialized = false;
    if ( num > 0 )
    {
      v4 = 0;
      v5 = 0;
      do
      {
        v6 = &this->actions.list[v4];
        rParticle = v6->rParticle;
        v8 = &this->fxDecl->events.list[v5];
        if ( rParticle != nullptr )
        {
          if ( !rParticle->unlinked )
          {
            idRenderModel::CommitThisFrame(this: v6->rParticle);
            rParticle->unlinked = true;
          }
          idFXModelRecycler::RecycleParticleFxModel(
            this: &this->gameLibEffects->fxModelRecycler,
            particleDecl: v8->particleParms.declPrt,
            model: v6->rParticle);
          v6->rParticle = nullptr;
        }
        rModel = v6->rModel;
        if ( rModel != nullptr )
        {
          if ( !rModel->unlinked )
          {
            idRenderModel::CommitThisFrame(this: v6->rModel);
            rModel->unlinked = true;
          }
          idFXModelRecycler::RecycleStaticFxModel(
            this: &this->gameLibEffects->fxModelRecycler,
            name: &v8->modelParms.modelName,
            model: v6->rModel);
          v6->rModel = nullptr;
        }
        ++v3;
        ++v5;
        ++v4;
      }
      while ( v3 < this->actions.num );
    }
    idFXManager::FreeActions(this);
    this->ta = nullptr;
  }
}


// ========================================================================
// ?LocalStartFX@idFXManager@@QAAXABVidVec3@@ABVidMat3@@HW4fxCondition_t@@@Z
// EA  : 0x82712528
// RVA : 0x00712528
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::LocalStartFX(
        idFXManager *this,
        const idVec3 *org,
        const idMat3 *axis,
        unsigned int time,
        int start)
{
  if ( g_skipFXManager.valueInteger == 0 && this->initialized )
    idFXManager::StartActions(
      this,
      org,
      axis,
      time,
      startCondition: start,
      extraCondition: FX_EXTRA_COND_NONE,
      explicitTagIdx: -1);
}


// ========================================================================
// ?InternalStartFX@idFXManager@@AAAHABUfxActionCall_t@1@@Z
// EA  : 0x82712558
// RVA : 0x00712558
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

int __fastcall idFXManager::InternalStartFX(idFXManager *this, const idFXManager::fxActionCall_t *actionCall)
{
  BOOL initialized; // r11
  int result; // r3

  initialized = this->initialized;
  result = 0;
  if ( initialized )
  {
    result = idFXManager::StartActions(
               this,
               org: &actionCall->org,
               axis: &actionCall->axis,
               time: actionCall->time,
               startCondition: actionCall->condition,
               extraCondition: (const fxExtraCondition_t)actionCall->extraCondition,
               explicitTagIdx: actionCall->tagIdx);
    ++this->actionBufferPos;
  }
  return result;
}


// ========================================================================
// ??0idFXManager@@QAA@XZ
// EA  : 0x82712630
// RVA : 0x00712630
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

idFXManager *__fastcall idFXManager::idFXManager(idFXManager *this)
{
  idList<idFXAction,109> *p_actions; // r28
  idList<fxActionState_t,109> *p_actionState; // r27
  bool *p_hasExternalPositionAndRotation; // r11
  int v5; // ctr
  __int16 *p_granularity; // r7
  int v7; // r9
  int v8; // r11
  int i; // ctr
  int v10; // r8

  this->initialized = false;
  this->fxDecl = nullptr;
  this->gameLibEffects = nullptr;
  this->ta = nullptr;
  this->rw = nullptr;
  this->systemColor.x = 1.0;
  this->systemColor.y = 1.0;
  p_actions = &this->actions;
  this->systemColor.z = 1.0;
  this->systemColor.w = 1.0;
  this->random.seed = 0;
  this->soundInfo.emitter = nullptr;
  this->soundInfo.channel = SND_CHANNEL_ANY;
  this->actions.granularity = 0;
  this->actions.memTag = 109;
  this->actions.listStatic = 0;
  this->actions.list = nullptr;
  this->actions.size = 0;
  this->actions.num = 0;
  this->actionState.list = nullptr;
  this->actionState.granularity = 0;
  p_actionState = &this->actionState;
  this->actionState.memTag = 109;
  this->actionState.listStatic = 0;
  this->actionState.size = 0;
  this->actionState.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->actionState);
  this->remote = false;
  this->allowSurfaceOnlyInViewID = 0;
  p_hasExternalPositionAndRotation = &this->hasExternalPositionAndRotation;
  this->suppressSurfaceInViewID = 0;
  v5 = 8;
  p_granularity = &this->actionState.granularity;
  this->viewCallbacksID = -1;
  this->declChangeId = -1;
  do
  {
    p_granularity += 38;
    *(float *)p_granularity = vec3_origin.x;
    *((float *)p_hasExternalPositionAndRotation + 2) = vec3_origin.y;
    *((float *)p_hasExternalPositionAndRotation + 3) = vec3_origin.z;
    *(idMat3 *)(p_hasExternalPositionAndRotation + 16) = mat3_identity;
    *((_DWORD *)p_hasExternalPositionAndRotation + 13) = 0;
    *((_DWORD *)p_hasExternalPositionAndRotation + 14) = 0;
    *((_DWORD *)p_hasExternalPositionAndRotation + 15) = 0;
    *((_DWORD *)p_hasExternalPositionAndRotation + 16) = -1;
    *((_DWORD *)p_hasExternalPositionAndRotation + 17) = 0;
    p_hasExternalPositionAndRotation[72] = false;
    p_hasExternalPositionAndRotation += 76;
    *(_DWORD *)p_hasExternalPositionAndRotation = -1;
    --v5;
  }
  while ( v5 != 0 );
  this->actionBufferPos = 0;
  this->serializeActionCount = 0;
  if ( p_actions->listStatic == 0 || p_actions->listStatic == 2 )
  {
    if ( p_actions->list != nullptr )
      idListArrayDelete<idFXAction>(ptr: p_actions->list, num: p_actions->size);
    p_actions->list = nullptr;
    p_actions->size = 0;
  }
  p_actions->num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_actionState);
  v7 = 25;
  this->externalPosition.z = 0.0;
  this->externalPosition.y = 0.0;
  this->externalPosition.x = 0.0;
  do
  {
    v8 = 0;
    for ( i = 3; i != 0; --i )
    {
      v10 = 4 * (v7 + v8++);
      *(float *)(&this->initialized + v10) = 0.0;
    }
    v7 += 3;
  }
  while ( v7 < 34 );
  this->hasExternalPositionAndRotation = false;
  memset(Dst: this->actionBuffer, Val: 0, Size: sizeof(this->actionBuffer));
  return this;
}


// ========================================================================
// __unwind$256100
// EA  : 0x82712858
// RVA : 0x00712858
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_256100()
{
  int v0; // r12

  idList<idFXAction,109>::Clear(this: (idList<idFXAction,109> *)(*(_DWORD *)(v0 - 144 + 164) + 48));
}


// ========================================================================
// __unwind$256101
// EA  : 0x82712884
// RVA : 0x00712884
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_256101()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 64));
}


// ========================================================================
// ??1idFXManager@@QAA@XZ
// EA  : 0x827128B8
// RVA : 0x007128B8
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::~idFXManager(idFXManager *this)
{
  idFXAction *list; // r3

  idFXManager::Shutdown(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->actionState);
  if ( this->actions.listStatic == 0 || this->actions.listStatic == 2 )
  {
    list = this->actions.list;
    if ( list != nullptr )
      idListArrayDelete<idFXAction>(ptr: list, num: this->actions.size);
    this->actions.list = nullptr;
    this->actions.size = 0;
  }
  this->actions.num = 0;
}


// ========================================================================
// __unwind$256260
// EA  : 0x8271293C
// RVA : 0x0071293C
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_256260()
{
  int v0; // r12

  idList<idFXAction,109>::Clear(this: (idList<idFXAction,109> *)(*(_DWORD *)(v0 - 112 + 132) + 48));
}


// ========================================================================
// __unwind$256261
// EA  : 0x82712968
// RVA : 0x00712968
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _unwind_256261()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// ?Init@idFXManager@@QAAXPBVidDeclFX@@PAVidRenderWorld@@PAUfxEmitterSound_t@@PAVidGameLibEffects@@MPAVidTreeAnimator@@@Z
// EA  : 0x82712998
// RVA : 0x00712998
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::Init(
        idFXManager *this,
        const idDeclFX *declFX,
        idRenderWorld *_rw,
        fxEmitterSound_t *_soundInfo,
        idGameLibEffects *_gameLibEffects,
        double diversity,
        idTreeAnimator *_ta,
        idTreeAnimator *a8)
{
  const idDeclFX *fxDecl; // r11
  int v11; // r30

  if ( declFX != nullptr && g_skipFXManager.valueInteger == 0 )
  {
    this->gameLibEffects = _gameLibEffects;
    this->ta = a8;
    this->fxDecl = declFX;
    this->rw = _rw;
    this->random.seed = (int)(float)((float)diversity * (float)65535.0);
    idList<idFXAction,109>::SetNum(this: &this->actions, newNum: declFX->events.num);
    idList<fxActionState_t,109>::SetNum(this: &this->actionState, newNum: this->fxDecl->events.num);
    fxDecl = this->fxDecl;
    this->declChangeId = fxDecl->changeId;
    if ( _soundInfo != nullptr )
    {
      this->soundInfo.emitter = _soundInfo->emitter;
      this->soundInfo.channel = _soundInfo->channel;
    }
    v11 = 0;
    if ( fxDecl->events.num > 0 )
    {
      do
        idFXManager::CreateAction(this, i: v11++, rw: this->rw);
      while ( v11 < this->fxDecl->events.num );
    }
    this->initialized = true;
  }
}


// ========================================================================
// ?Update@idFXManager@@QAAXABVidVec3@@ABVidMat3@@0HHHMM@Z
// EA  : 0x82712A90
// RVA : 0x00712A90
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __fastcall idFXManager::Update(
        idFXManager *this,
        const idVec3 *parentOrigin,
        const idMat3 *parentAxis,
        const idVec3 *parentVel,
        int time,
        unsigned int gameMsPerFrame,
        int frameNum,
        double fovScale,
        double depthHack)
{
  const char *Name; // r3
  int v19; // r6
  const char *v20; // r4
  int actionBufferPos; // r10
  int v22; // r11
  bool *v23; // r10
  unsigned int v24; // r10
  idFXManager::fxActionCall_t *v25; // r11
  idFXManager::fxActionCall_t *v26; // r4

  if ( g_skipFXManager.valueInteger == 0 && this->initialized )
  {
    while ( this->serializeActionCount > 0 )
    {
      if ( g_debugFX.valueInteger > 3 )
      {
        Name = idFXManager::GetName(this);
        idLib::Printf(fmt: "%s %s Catching up on serialized event. serializeActionCount:%d \n", v20, Name, v19);
      }
      actionBufferPos = this->actionBufferPos;
      --this->serializeActionCount;
      this->actionBuffer[actionBufferPos % 8].time = time;
      v22 = this->actionBufferPos % 8;
      v23 = &this->initialized + 76 * v22;
      this->viewCallbacksID = *((_DWORD *)v23 + 56);
      v24 = *((_DWORD *)v23 + 54);
      if ( v24 != 0 )
      {
        if ( v24 < 3 )
        {
          v25 = &this->actionBuffer[v22];
          idFXManager::StopActions(
            this,
            time: v25->time,
            stopCondition: v25->condition,
            extraCondition: (const fxExtraCondition_t)v25->extraCondition,
            stopAll: (_cntlzw(v25->actionType - 2) & 0x20) != 0,
            stopImmediate: v25->immediate);
          ++this->actionBufferPos;
        }
      }
      else if ( this->initialized )
      {
        v26 = &this->actionBuffer[v22];
        idFXManager::StartActions(
          this,
          org: &v26->org,
          axis: &v26->axis,
          time: v26->time,
          startCondition: v26->condition,
          extraCondition: (const fxExtraCondition_t)v26->extraCondition,
          explicitTagIdx: v26->tagIdx);
        ++this->actionBufferPos;
      }
    }
    idFXManager::UpdateActions(
      this,
      org: parentOrigin,
      axis: parentAxis,
      vel: parentVel,
      time,
      gameMsPerFrame,
      frameNum,
      fovScale,
      depthHack);
  }
}


// ========================================================================
// ?StartFX@idFXManager@@QAAHABVidVec3@@ABVidMat3@@HW4fxCondition_t@@HH@Z
// EA  : 0x82712C78
// RVA : 0x00712C78
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

int __fastcall idFXManager::StartFX(
        idFXManager *this,
        const idVec3 *org,
        const idMat3 *axis,
        const int time,
        int startCondition,
        int explicitTagIdx,
        const int delay)
{
  idFXManager::fxActionCall_t *v14; // r4

  if ( g_skipFXManager.valueInteger != 0 || !this->initialized )
    return 0;
  if ( !common->IsServer(this: common) )
    return idFXManager::StartActions(
             this,
             org,
             axis,
             time: time + delay,
             startCondition,
             extraCondition: FX_EXTRA_COND_NONE,
             explicitTagIdx);
  v14 = &this->actionBuffer[this->actionBufferPos % 8];
  v14->org.x = org->x;
  v14->org.y = org->y;
  v14->org.z = org->z;
  v14->axis.mat[0].x = axis->mat[0].x;
  v14->axis.mat[0].y = axis->mat[0].y;
  v14->axis.mat[0].z = axis->mat[0].z;
  v14->axis.mat[1].x = axis->mat[1].x;
  v14->axis.mat[1].y = axis->mat[1].y;
  v14->axis.mat[1].z = axis->mat[1].z;
  v14->axis.mat[2].x = axis->mat[2].x;
  v14->axis.mat[2].y = axis->mat[2].y;
  v14->axis.mat[2].z = axis->mat[2].z;
  v14->time = time + delay;
  v14->condition = startCondition;
  v14->extraCondition = FX_EXTRA_COND_NONE;
  v14->tagIdx = explicitTagIdx;
  v14->actionType = FXACTION_START;
  v14->immediate = false;
  v14->viewCallbacksID = this->viewCallbacksID;
  return idFXManager::InternalStartFX(this, actionCall: v14);
}


// ========================================================================
// ?StartFX@idFXManager@@QAAHABVidVec3@@ABVidMat3@@HW4fxCondition_t@@W4fxExtraCondition_t@@@Z
// EA  : 0x82712DD0
// RVA : 0x00712DD0
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

int __fastcall idFXManager::StartFX(
        idFXManager *this,
        const idVec3 *org,
        const idMat3 *axis,
        unsigned int time,
        int startCondition,
        __int32 extraCond)
{
  idFXManager::fxActionCall_t *v12; // r4

  if ( g_skipFXManager.valueInteger != 0 || !this->initialized )
    return 0;
  if ( !common->IsServer(this: common) )
    return idFXManager::StartActions(
             this,
             org,
             axis,
             time,
             startCondition,
             extraCondition: (const fxExtraCondition_t)extraCond,
             explicitTagIdx: -1);
  v12 = &this->actionBuffer[this->actionBufferPos % 8];
  v12->org.x = org->x;
  v12->org.y = org->y;
  v12->org.z = org->z;
  v12->axis.mat[0].x = axis->mat[0].x;
  v12->axis.mat[0].y = axis->mat[0].y;
  v12->axis.mat[0].z = axis->mat[0].z;
  v12->axis.mat[1].x = axis->mat[1].x;
  v12->axis.mat[1].y = axis->mat[1].y;
  v12->axis.mat[1].z = axis->mat[1].z;
  v12->axis.mat[2].x = axis->mat[2].x;
  v12->axis.mat[2].y = axis->mat[2].y;
  v12->axis.mat[2].z = axis->mat[2].z;
  v12->tagIdx = -1;
  v12->time = time;
  v12->condition = startCondition;
  v12->extraCondition = extraCond;
  v12->actionType = FXACTION_START;
  v12->immediate = false;
  v12->viewCallbacksID = this->viewCallbacksID;
  return idFXManager::InternalStartFX(this, actionCall: v12);
}


// ========================================================================
// ?StartFX@idFXManager@@QAAHABVidVec3@@ABVidMat3@@HW4fxCondition_t@@@Z
// EA  : 0x82712F28
// RVA : 0x00712F28
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

int __fastcall idFXManager::StartFX(
        idFXManager *this,
        const idVec3 *org,
        const idMat3 *axis,
        int time,
        int startCondition)
{
  return idFXManager::StartFX(this, org, axis, time, startCondition, explicitTagIdx: -1, delay: 0);
}


// ========================================================================
// `dynamic initializer for 'g_skipFXManager''
// EA  : 0x8333F7F0
// RVA : 0x0133F7F0
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_skipFXManager__()
{
  idCVar::idCVar(
    this: &g_skipFXManager,
    name: "g_skipFXManager",
    value: "0",
    flags: 2,
    description: "skip fx",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_skipFXManager__);
}


// ========================================================================
// `dynamic initializer for 'g_debugFX''
// EA  : 0x8333F848
// RVA : 0x0133F848
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugFX__()
{
  idCVar::idCVar(
    this: &g_debugFX,
    name: "g_debugFX",
    value: "0",
    flags: 2,
    description: "1 = fx start/stop debug, 2 = distance debug, 3+ = serialization",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugFX__);
}


// ========================================================================
// `dynamic initializer for 'fx_verbose''
// EA  : 0x8333F8A0
// RVA : 0x0133F8A0
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__fx_verbose__()
{
  idCVar::idCVar(
    this: &fx_verbose,
    name: "fx_verbose",
    value: "0",
    flags: 1,
    description: "print verbose warnings for fx",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__fx_verbose__);
}


// ========================================================================
// `dynamic initializer for 'g_showFxModelRecyclerStats''
// EA  : 0x8333F8F8
// RVA : 0x0133F8F8
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showFxModelRecyclerStats__()
{
  idCVar::idCVar(
    this: &g_showFxModelRecyclerStats,
    name: "g_showFxModelRecyclerStats",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showFxModelRecyclerStats__);
}


// ========================================================================
// `dynamic initializer for 'rpParticleVel''
// EA  : 0x8333F950
// RVA : 0x0133F950
// PDB : w:\tech5\engine\gamelib\effects\fxmanager.cpp
// ========================================================================

void _dynamic_initializer_for__rpParticleVel__()
{
  rpParticleVel.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpParticleVel;
}

