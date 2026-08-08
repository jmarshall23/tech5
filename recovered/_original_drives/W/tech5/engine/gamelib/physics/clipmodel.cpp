
// ========================================================================
// ?Delete@idClipModel@@QAAXXZ
// EA  : 0x82738928
// RVA : 0x00738928
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::Delete(idClipModel *this)
{
  idClip *clip; // r3

  clip = this->clip;
  this->deleted = true;
  idClip::DeleteClipModel(this: clip, clipModel: this);
}


// ========================================================================
// ?NoTraceModelWarning@idClipModel@@ABAPAVidCollisionModel@@XZ
// EA  : 0x82738940
// RVA : 0x00738940
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

idCollisionModel *__fastcall idClipModel::NoTraceModelWarning(idClipModel *this)
{
  idLib::Warning(
    fmt: "idClipModel::GetCollisionModel: clip model %d on entity %d is not a collision or trace model",
    this->bodyId,
    this->entityNumber);
  return nullptr;
}


// ========================================================================
// ?GetMassProperties@idClipModel@@QBAXMAAMAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82738A18
// RVA : 0x00738A18
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::GetMassProperties(
        idClipModel *this,
        double density,
        float *mass,
        idVec3 *centerOfMass,
        idMat3 *inertiaTensor,
        float *a6)
{
  int num; // r11
  int v12; // r9
  int v13; // r11
  int i; // ctr
  int v15; // r8
  int v16; // r28
  int v17; // r26
  double x; // fp0
  double y; // fp10
  double z; // fp3
  double v21; // fp5
  double v22; // fp4
  int v23; // r28
  double v24; // fp11
  double v25; // fp10
  double v26; // fp9
  int v27; // r26
  double v28; // fp7
  double v29; // fp6
  const idVec3 *v30; // r4
  double v31; // fp6
  double v32; // fp4
  double v33; // fp1
  double v34; // fp2
  double v35; // fp0
  double v36; // fp13
  double v37; // fp12
  double v38; // fp11
  double v39; // fp9
  double v40; // fp5
  double v41; // fp1
  double v42; // fp13
  double v43; // fp12
  idVec3 v44; // [sp+50h] [-A0h] BYREF
  float v45; // [sp+5Ch] [-94h]
  float v46; // [sp+60h] [-90h]
  float v47; // [sp+68h] [-88h]
  float v48; // [sp+6Ch] [-84h]
  float v49; // [sp+70h] [-80h]
  idMat3 v50; // [sp+80h] [-70h] BYREF

  num = this->traceModels.num;
  if ( num == 0 )
    idLib::Error(
      fmt: "idClipModel::GetMassProperties: clip model %d on entity %d is not a trace model\n",
      this->bodyId,
      this->entityNumber);
  if ( num == 1 )
  {
    idTraceModelCache::GetMassProperties(
      this: this->clip->traceModelCache,
      traceModelIndex: *this->traceModels.list,
      density,
      mass: (float *)0x28074,
      centerOfMass,
      inertiaTensor);
  }
  else
  {
    v12 = 0;
    centerOfMass->x = 0.0;
    inertiaTensor->mat[0].x = 0.0;
    inertiaTensor->mat[0].z = 0.0;
    inertiaTensor->mat[0].y = 0.0;
    do
    {
      v13 = 0;
      for ( i = 3; i != 0; --i )
      {
        v15 = v12 + v13++;
        a6[v15] = 0.0;
      }
      v12 += 3;
    }
    while ( v12 < 9 );
    v16 = 0;
    if ( this->traceModels.num > 0 )
    {
      v17 = 0;
      do
      {
        idTraceModelCache::GetMassProperties(
          this: this->clip->traceModelCache,
          traceModelIndex: this->traceModels.list[v17],
          density,
          mass: &centerOfMass->x,
          centerOfMass: &v44,
          inertiaTensor: (idMat3 *)&v44.z);
        x = v44.x;
        ++v16;
        ++v17;
        centerOfMass->x = centerOfMass->x + v44.x;
        y = inertiaTensor->mat[0].y;
        z = inertiaTensor->mat[0].z;
        v21 = (float)(v45 * (float)x);
        v22 = (float)(v46 * (float)x);
        inertiaTensor->mat[0].x = inertiaTensor->mat[0].x + (float)(v44.z * (float)x);
        inertiaTensor->mat[0].z = (float)z + (float)v22;
        inertiaTensor->mat[0].y = (float)y + (float)v21;
      }
      while ( v16 < this->traceModels.num );
    }
    v23 = 0;
    v24 = inertiaTensor->mat[0].y;
    v25 = inertiaTensor->mat[0].z;
    v26 = (float)((float)1.0 / centerOfMass->x);
    inertiaTensor->mat[0].x = inertiaTensor->mat[0].x * (float)((float)1.0 / centerOfMass->x);
    inertiaTensor->mat[0].y = (float)v24 * (float)v26;
    inertiaTensor->mat[0].z = (float)v25 * (float)v26;
    if ( this->traceModels.num > 0 )
    {
      v27 = 0;
      do
      {
        idTraceModelCache::GetMassProperties(
          this: this->clip->traceModelCache,
          traceModelIndex: this->traceModels.list[v27],
          density,
          mass: &centerOfMass->x,
          centerOfMass: &v44,
          inertiaTensor: (idMat3 *)&v44.z);
        v28 = (float)(inertiaTensor->mat[0].y - v45);
        v29 = (float)(inertiaTensor->mat[0].z - v46);
        v47 = inertiaTensor->mat[0].x - v44.z;
        v48 = v28;
        v49 = v29;
        idMat3::InertiaTranslateSelf(this: &v50, mass: v44.x, centerOfMass: v30, translation: (idVec3 *)&v44.z);
        ++v23;
        v31 = (float)(a6[1] + v50.mat[0].y);
        ++v27;
        v32 = (float)(a6[2] + v50.mat[0].z);
        v33 = a6[4];
        v34 = a6[3];
        v35 = a6[5];
        v36 = a6[6];
        v37 = a6[7];
        v38 = a6[8];
        *a6 = *a6 + v50.mat[0].x;
        a6[1] = v31;
        a6[2] = v32;
        v39 = (float)((float)v33 + v50.mat[1].y);
        v40 = (float)((float)v35 + v50.mat[1].z);
        v41 = (float)((float)v36 + v50.mat[2].x);
        v42 = (float)((float)v37 + v50.mat[2].y);
        v43 = (float)((float)v38 + v50.mat[2].z);
        a6[3] = (float)v34 + v50.mat[1].x;
        a6[4] = v39;
        a6[5] = v40;
        a6[6] = v41;
        a6[7] = v42;
        a6[8] = v43;
      }
      while ( v23 < this->traceModels.num );
    }
  }
}


// ========================================================================
// ?LinkIntoAASes@idClipModel@@AAAXW4aasType_t@@@Z
// EA  : 0x82738CE8
// RVA : 0x00738CE8
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::LinkIntoAASes(idClipModel *this, const aasType_t aasType)
{
  char *v3; // r29
  int i; // r31
  int v5; // r3
  idAAS2 *v6; // r3

  if ( aasType == AAS_FILE_EXTENSION_MAX )
  {
    v3 = (char *)this - 163740;
    for ( i = 163924; i < 163956; i += 4 )
    {
      v5 = *(int *)((char *)&this->clip->world + i);
      if ( v5 != 0 )
        *(_DWORD *)&v3[i] = (*(int (__fastcall **)(int, idClipModel *))(*(_DWORD *)v5 + 252))(a1: v5, a2: this);
    }
  }
  else
  {
    v6 = this->clip->aases[aasType];
    if ( v6 != nullptr )
      this->aasLinks[aasType] = v6->LinkClipModel(this: v6, a2: this);
  }
}


// ========================================================================
// ?SetContents@idClipModel@@QAAXH@Z
// EA  : 0x82738DA0
// RVA : 0x00738DA0
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::SetContents(idClipModel *this, int newContents)
{
  char *v4; // r29
  int i; // r30
  int v6; // r3
  idAASClipLink **aasLinks; // r30
  int v8; // r28
  int v9; // r29
  int v10; // r3

  if ( (this->contents & 0x20000) == (newContents & 0x20000) )
  {
LABEL_13:
    this->contents = newContents;
    return;
  }
  if ( (newContents & 0x20000) == 0 || this->clipLinks == nullptr )
  {
    aasLinks = this->aasLinks;
    v8 = 8;
    v9 = 163740 - (_DWORD)this;
    do
    {
      v10 = *(int *)((char *)&this->clip->world + v9 + (unsigned int)aasLinks);
      if ( v10 != 0 )
        *aasLinks = (idAASClipLink *)(*(int (__fastcall **)(int, idAASClipLink *))(*(_DWORD *)v10 + 256))(
                                       a1: v10,
                                       a2: *aasLinks);
      --v8;
      ++aasLinks;
    }
    while ( v8 != 0 );
    goto LABEL_13;
  }
  v4 = (char *)this - 163740;
  for ( i = 163924; i < 163956; i += 4 )
  {
    v6 = *(int *)((char *)&this->clip->world + i);
    if ( v6 != 0 )
      *(_DWORD *)&v4[i] = (*(int (__fastcall **)(int, idClipModel *))(*(_DWORD *)v6 + 252))(a1: v6, a2: this);
  }
  this->contents = newContents;
}


// ========================================================================
// ?FreeModel@idClipModel@@AAAXXZ
// EA  : 0x82738F30
// RVA : 0x00738F30
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::FreeModel(idClipModel *this)
{
  int v2; // r29
  int v3; // r30
  int *list; // r4

  v2 = 0;
  if ( this->traceModels.num > 0 )
  {
    v3 = 0;
    do
    {
      idTraceModelCache::FreeTraceModel(this: this->clip->traceModelCache, traceModelIndex: this->traceModels.list[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->traceModels.num );
  }
  if ( this->traceModels.listStatic == 0 || this->traceModels.listStatic == 2 )
  {
    list = this->traceModels.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->traceModels.list = nullptr;
    this->traceModels.size = 0;
  }
  this->traceModels.num = 0;
}


// ========================================================================
// ?LoadCollisionModel@idClipModel@@AAA_NPBDPBVidMaterial@@@Z
// EA  : 0x82738FD8
// RVA : 0x00738FD8
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

int __fastcall idClipModel::LoadCollisionModel(
        idClipModel *this,
        const char *name,
        const idMaterial *overrideClipMaterial)
{
  idCollisionModel *collisionModel; // r3

  idClipModel::FreeModel(this);
  if ( name != nullptr && *name != 0 )
    this->collisionModel = idCollisionModelManager::LoadModel(this: collisionModelManager, modelName: name);
  collisionModel = this->collisionModel;
  if ( collisionModel != nullptr )
  {
    collisionModel->GetBounds(this: collisionModel, a2: &this->bounds);
    this->collisionModel->GetContents(this: this->collisionModel, a2: &this->contents);
    if ( overrideClipMaterial != nullptr )
      this->contents = idParmBlock::GetInteger(this: &overrideClipMaterial->parmBlock, parm: rp->contentFlags);
    return 1;
  }
  else
  {
    this->bounds.b[1].z = 0.0;
    this->bounds.b[1].y = 0.0;
    this->bounds.b[1].x = 0.0;
    this->bounds.b[0].z = 0.0;
    this->bounds.b[0].y = 0.0;
    this->bounds.b[0].x = 0.0;
    return 0;
  }
}


// ========================================================================
// ?LoadCollisionModel@idClipModel@@AAAXPAVidCollisionModel@@@Z
// EA  : 0x827390B0
// RVA : 0x007390B0
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::LoadCollisionModel(idClipModel *this, idCollisionModel *model)
{
  idClipModel::FreeModel(this);
  this->collisionModel = model;
  model->GetBounds(this: model, a2: &this->bounds);
  this->collisionModel->GetContents(this: this->collisionModel, a2: &this->contents);
}


// ========================================================================
// ?LoadAnimator@idClipModel@@AAAXPAVidTreeAnimator@@@Z
// EA  : 0x82739120
// RVA : 0x00739120
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::LoadAnimator(idClipModel *this, idTreeAnimator *animatedModel)
{
  idCollisionModel *Model; // r3

  idClipModel::FreeModel(this);
  this->animatedModel = animatedModel;
  Model = idCollisionModelManager::LoadModel(this: collisionModelManager, modelName: animatedModel->decl->name.str);
  this->collisionModel = Model;
  Model->GetBounds(this: Model, a2: &this->bounds);
  this->collisionModel->GetContents(this: this->collisionModel, a2: &this->contents);
}


// ========================================================================
// ?Init@idClipModel@@AAAXPAVidClip@@@Z
// EA  : 0x827391A0
// RVA : 0x007391A0
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::Init(idClipModel *this, idClip *clip)
{
  idClipModel **p_nextDeleted; // r11
  int i; // ctr

  this->deleted = false;
  this->physicsId = 0;
  this->bodyId = 0;
  this->bodyMask = 0;
  this->enabled = true;
  this->entityNumber = 0x1FFF;
  this->ownerNumber = 0x1FFF;
  this->origin.z = 0.0;
  this->origin.y = 0.0;
  this->origin.x = 0.0;
  this->axis.mat[2].z = 1.0;
  this->axis.mat[1].y = 1.0;
  this->axis.mat[0].x = 1.0;
  this->axis.mat[1].z = 0.0;
  this->axis.mat[0].z = 0.0;
  this->axis.mat[0].y = 0.0;
  this->axis.mat[2].y = 0.0;
  this->axis.mat[2].x = 0.0;
  this->axis.mat[1].x = 0.0;
  this->bounds.b[1].z = 0.0;
  this->bounds.b[1].y = 0.0;
  this->bounds.b[1].x = 0.0;
  this->bounds.b[0].z = 0.0;
  this->bounds.b[0].y = 0.0;
  this->bounds.b[0].x = 0.0;
  this->absBounds.b[1].z = 0.0;
  this->absBounds.b[1].y = 0.0;
  this->absBounds.b[1].x = 0.0;
  this->absBounds.b[0].z = 0.0;
  this->absBounds.b[0].y = 0.0;
  this->absBounds.b[0].x = 0.0;
  this->collisionModel = nullptr;
  this->contents = 0x80000000;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->traceModels);
  this->animatedModel = nullptr;
  this->clipLinks = nullptr;
  this->clip = clip;
  this->touchCount = -1;
  p_nextDeleted = &this->nextDeleted;
  for ( i = 8; i != 0; --i )
    *++p_nextDeleted = nullptr;
  this->nextDeleted = nullptr;
}


// ========================================================================
// ?Serialize@idClipModel@@QAAXAAVidSerializer@@@Z
// EA  : 0x827392A0
// RVA : 0x007392A0
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::Serialize(idClipModel *this, idSerializer *ser)
{
  int v3[4]; // [sp+50h] [-20h] BYREF

  if ( ser->writing )
  {
    idSerializer::Serialize(this: ser, value: &this->contents);
  }
  else
  {
    idSerializer::Serialize(this: ser, value: v3);
    idClipModel::SetContents(this, newContents: v3[0]);
  }
}


// ========================================================================
// ?RelinkIntoAASes@idClipModel@@AAAXW4aasType_t@@@Z
// EA  : 0x82739308
// RVA : 0x00739308
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::RelinkIntoAASes(idClipModel *this, aasType_t aasType)
{
  idClipModel **p_nextDeleted; // r11
  int i; // ctr

  if ( aasType == AAS_FILE_EXTENSION_MAX )
  {
    p_nextDeleted = &this->nextDeleted;
    for ( i = 8; i != 0; --i )
      *++p_nextDeleted = nullptr;
  }
  else
  {
    this->aasLinks[aasType] = nullptr;
  }
  idClipModel::LinkIntoAASes(this, aasType);
}


// ========================================================================
// ?Unlink@idClipModel@@QAAXXZ
// EA  : 0x82739348
// RVA : 0x00739348
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::Unlink(idClipModel *this)
{
  clipLink_t *i; // r11
  clipLink_t *prevInSector; // r10
  clipLink_t *nextInSector; // r9
  clipLink_t *v5; // r10
  idBlockAlloc<clipLink_t,256,13> *p_clipLinkAllocator; // r10
  idAASClipLink **aasLinks; // r31
  int v8; // r29
  int v9; // r28
  int v10; // r11
  int v11; // r3

  for ( i = this->clipLinks; i != nullptr; i = this->clipLinks )
  {
    this->clipLinks = i->nextLink;
    prevInSector = i->prevInSector;
    nextInSector = i->nextInSector;
    if ( prevInSector != nullptr )
      prevInSector->nextInSector = nextInSector;
    else
      i->sector->clipLinks = nextInSector;
    v5 = i->nextInSector;
    if ( v5 != nullptr )
      v5->prevInSector = i->prevInSector;
    p_clipLinkAllocator = &this->clip->clipLinkAllocator;
    i->clipModel = (idClipModel *)this->clip->clipLinkAllocator.free;
    p_clipLinkAllocator->free = (idBlockAlloc<clipLink_t,256,13>::element_t *)i;
    --p_clipLinkAllocator->active;
  }
  if ( (this->contents & 0x20000) != 0 )
  {
    aasLinks = this->aasLinks;
    v8 = 8;
    v9 = 163740 - (_DWORD)this;
    v10 = 163924;
    do
    {
      v11 = *(int *)((char *)&this->clip->world + v10);
      if ( v11 != 0 )
        *aasLinks = (idAASClipLink *)(*(int (__fastcall **)(int, idAASClipLink *))(*(_DWORD *)v11 + 256))(
                                       a1: v11,
                                       a2: *aasLinks);
      ++aasLinks;
      --v8;
      v10 = (int)aasLinks + v9;
    }
    while ( v8 != 0 );
  }
}


// ========================================================================
// ?LoadTraceModel@idClipModel@@AAAXPBVidTraceModel@@HPBVidMaterial@@@Z
// EA  : 0x82739438
// RVA : 0x00739438
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::LoadTraceModel(
        idClipModel *this,
        const idTraceModel *trm,
        const int numTraceModels,
        const idMaterial *material)
{
  idBounds *p_bounds; // r31
  int v9; // r27
  float *p_z; // r30
  double y; // fp11
  double z; // fp10
  double x; // fp9
  double v15; // fp8
  double v16; // fp7
  idCollisionModel *collisionModel; // r3
  encounterGroupRole_t v29[24]; // [sp+50h] [-60h] BYREF

  p_bounds = &this->bounds;
  idClipModel::FreeModel(this);
  this->contents = 0x80000000;
  this->bounds.b[0].z = 1.0e30;
  this->bounds.b[0].y = 1.0e30;
  this->bounds.b[0].x = 1.0e30;
  this->bounds.b[1].z = -1.0e30;
  this->bounds.b[1].y = -1.0e30;
  this->bounds.b[1].x = -1.0e30;
  if ( numTraceModels > 0 )
  {
    v9 = 0;
    p_z = &trm->bounds.b[0].z;
    do
    {
      v29[0] = idTraceModelCache::AllocTraceModel(
                 this: this->clip->traceModelCache,
                 trm: (const idTraceModel *)(p_z - 378),
                 material);
      idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->traceModels, obj: v29);
      _FP12 = (float)(p_bounds->b[0].x - *(p_z - 2));
      y = this->bounds.b[0].y;
      z = this->bounds.b[0].z;
      x = this->bounds.b[1].x;
      v15 = this->bounds.b[1].y;
      v16 = this->bounds.b[1].z;
      __asm { fsel      f6, f12, f0, f13 }
      p_bounds->b[0].x = _FP6;
      _FP4 = (float)((float)y - *(p_z - 1));
      __asm { fsel      f3, f4, f5, f11 }
      this->bounds.b[0].y = _FP3;
      _FP1 = (float)((float)z - *p_z);
      __asm { fsel      f0, f1, f2, f10 }
      this->bounds.b[0].z = _FP0;
      _FP12 = (float)(p_z[1] - (float)x);
      __asm { fsel      f11, f12, f13, f9 }
      this->bounds.b[1].x = _FP11;
      _FP9 = (float)(p_z[2] - (float)v15);
      __asm { fsel      f8, f9, f10, f8 }
      this->bounds.b[1].y = _FP8;
      _FP5 = (float)(p_z[3] - (float)v16);
      __asm { fsel      f4, f5, f6, f7 }
      this->bounds.b[1].z = _FP4;
      collisionModel = this->clip->traceModelCache->cache.list[this->traceModels.list[v9]]->collisionModel;
      if ( collisionModel != nullptr )
      {
        v29[0] = ROLE_NONE;
        collisionModel->GetContents(this: collisionModel, a2: (int *)v29);
        this->contents = this->contents & 0x7FFFFFFF | v29[0];
      }
      --numTraceModels;
      p_z += 384;
      ++v9;
    }
    while ( numTraceModels != 0 );
  }
}


// ========================================================================
// ??0idClipModel@@QAA@XZ
// EA  : 0x827395D0
// RVA : 0x007395D0
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

idClipModel *__fastcall idClipModel::idClipModel(idClipModel *this)
{
  unsigned __int64 v1; // r29

  LODWORD(v1) = 0;
  this->__vftable = (idClipModel_vtbl *)&idClipModel::`vftable';
  this->traceModels.list = nullptr;
  this->traceModels.granularity = 0;
  this->traceModels.memTag = 13;
  this->traceModels.listStatic = 0;
  this->traceModels.size = 0;
  this->traceModels.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->traceModels);
  this->collisionQuery.offset = v1;
  idClipModel::Init(this, clip: nullptr);
  return this;
}


// ========================================================================
// __unwind$247593
// EA  : 0x82739640
// RVA : 0x00739640
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void _unwind_247593()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// ??0idClipModel@@QAA@PAVidClip@@PBDPBVidMaterial@@@Z
// EA  : 0x82739678
// RVA : 0x00739678
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

idClipModel *__fastcall idClipModel::idClipModel(
        idClipModel *this,
        idClip *clip,
        const char *name,
        const idMaterial *overrideClipMaterial)
{
  unsigned __int64 v5; // r29

  LODWORD(v5) = 0;
  this->__vftable = (idClipModel_vtbl *)&idClipModel::`vftable';
  this->traceModels.list = nullptr;
  HIDWORD(v5) = clip;
  this->traceModels.granularity = 0;
  this->traceModels.memTag = 13;
  this->traceModels.listStatic = 0;
  this->traceModels.size = 0;
  this->traceModels.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->traceModels);
  this->collisionQuery.offset = v5;
  idClipModel::Init(this, clip: (idClip *)HIDWORD(v5));
  idClipModel::LoadCollisionModel(this, name, overrideClipMaterial);
  return this;
}


// ========================================================================
// __unwind$247621
// EA  : 0x82739704
// RVA : 0x00739704
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void _unwind_247621()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 136));
}


// ========================================================================
// ??0idClipModel@@QAA@PAVidClip@@PAVidCollisionModel@@@Z
// EA  : 0x82739738
// RVA : 0x00739738
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

idClipModel *__fastcall idClipModel::idClipModel(idClipModel *this, idClip *clip, idCollisionModel *model)
{
  unsigned __int64 v4; // r29

  LODWORD(v4) = 0;
  this->__vftable = (idClipModel_vtbl *)&idClipModel::`vftable';
  this->traceModels.list = nullptr;
  HIDWORD(v4) = clip;
  this->traceModels.granularity = 0;
  this->traceModels.memTag = 13;
  this->traceModels.listStatic = 0;
  this->traceModels.size = 0;
  this->traceModels.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->traceModels);
  this->collisionQuery.offset = v4;
  idClipModel::Init(this, clip: (idClip *)HIDWORD(v4));
  idClipModel::FreeModel(this);
  this->collisionModel = model;
  model->GetBounds(this: model, a2: &this->bounds);
  this->collisionModel->GetContents(this: this->collisionModel, a2: &this->contents);
  return this;
}


// ========================================================================
// __unwind$247650
// EA  : 0x827397EC
// RVA : 0x007397EC
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void _unwind_247650()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 136));
}


// ========================================================================
// ??0idClipModel@@QAA@PAVidClip@@PBVidTraceModel@@HPBVidMaterial@@@Z
// EA  : 0x82739820
// RVA : 0x00739820
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

idClipModel *__fastcall idClipModel::idClipModel(
        idClipModel *this,
        idClip *clip,
        const idTraceModel *trm,
        int numTraceModels,
        const idMaterial *material)
{
  unsigned __int64 v6; // r29

  LODWORD(v6) = 0;
  this->__vftable = (idClipModel_vtbl *)&idClipModel::`vftable';
  this->traceModels.list = nullptr;
  HIDWORD(v6) = clip;
  this->traceModels.granularity = 0;
  this->traceModels.memTag = 13;
  this->traceModels.listStatic = 0;
  this->traceModels.size = 0;
  this->traceModels.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->traceModels);
  this->collisionQuery.offset = v6;
  idClipModel::Init(this, clip: (idClip *)HIDWORD(v6));
  idClipModel::LoadTraceModel(this, trm, numTraceModels, material);
  return this;
}


// ========================================================================
// __unwind$247680
// EA  : 0x827398B4
// RVA : 0x007398B4
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void _unwind_247680()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 136));
}


// ========================================================================
// ??0idClipModel@@QAA@PAVidClip@@PAVidTreeAnimator@@@Z
// EA  : 0x827398E8
// RVA : 0x007398E8
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

idClipModel *__fastcall idClipModel::idClipModel(idClipModel *this, idClip *clip, idTreeAnimator *animatedModel)
{
  unsigned __int64 v4; // r29

  LODWORD(v4) = 0;
  this->__vftable = (idClipModel_vtbl *)&idClipModel::`vftable';
  this->traceModels.list = nullptr;
  HIDWORD(v4) = clip;
  this->traceModels.granularity = 0;
  this->traceModels.memTag = 13;
  this->traceModels.listStatic = 0;
  this->traceModels.size = 0;
  this->traceModels.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->traceModels);
  this->collisionQuery.offset = v4;
  idClipModel::Init(this, clip: (idClip *)HIDWORD(v4));
  idClipModel::LoadAnimator(this, animatedModel);
  return this;
}


// ========================================================================
// __unwind$247707
// EA  : 0x8273996C
// RVA : 0x0073996C
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void _unwind_247707()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 136));
}


// ========================================================================
// ??0idClipModel@@QAA@PAVidClip@@PBV0@@Z
// EA  : 0x827399A0
// RVA : 0x007399A0
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

idClipModel *__fastcall idClipModel::idClipModel(idClipModel *this, idClip *clip, const idClipModel *model)
{
  unsigned __int64 v3; // r26
  idList<idSpawnArea::GeneratedPosition *,5> *p_traceModels; // r28
  idCollisionModel *collisionModel; // r11
  int num; // r27
  int size; // r11
  int v11; // r25
  int v12; // r27
  idTreeAnimator *animatedModel; // r8
  idClipModel **p_nextDeleted; // r11
  int i; // ctr

  LODWORD(v3) = 0;
  this->__vftable = (idClipModel_vtbl *)&idClipModel::`vftable';
  p_traceModels = (idList<idSpawnArea::GeneratedPosition *,5> *)&this->traceModels;
  this->traceModels.list = nullptr;
  this->traceModels.granularity = 0;
  this->traceModels.memTag = 13;
  this->traceModels.listStatic = 0;
  this->traceModels.size = 0;
  this->traceModels.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->traceModels);
  this->collisionQuery.offset = v3;
  this->enabled = model->enabled;
  this->deleted = model->deleted;
  this->entityNumber = model->entityNumber;
  this->ownerNumber = model->ownerNumber;
  this->physicsId = model->physicsId;
  this->bodyId = model->bodyId;
  this->bodyMask = model->bodyMask;
  this->origin = model->origin;
  this->axis = model->axis;
  this->bounds = model->bounds;
  this->absBounds = model->absBounds;
  this->contents = model->contents;
  this->collisionModel = nullptr;
  collisionModel = model->collisionModel;
  if ( collisionModel != nullptr )
    this->collisionModel = idCollisionModelManager::LoadModel(
                             this: collisionModelManager,
                             modelName: collisionModel->name.str);
  num = model->traceModels.num;
  if ( num <= p_traceModels->size
    || idList<idNavSpline *,5>::Resize(this: p_traceModels, newsize: model->traceModels.num) )
  {
    size = p_traceModels->size;
    if ( num < size )
      size = num;
    p_traceModels->num = size;
  }
  v11 = 0;
  if ( model->traceModels.num > 0 )
  {
    v12 = 0;
    do
    {
      ++v11;
      p_traceModels->list[v12] = (idSpawnArea::GeneratedPosition *)idTraceModelCache::CopyTraceModel(
                                                                     this: clip->traceModelCache,
                                                                     traceModelIndex: model->traceModels.list[v12]);
      ++v12;
    }
    while ( v11 < model->traceModels.num );
  }
  animatedModel = model->animatedModel;
  this->clip = clip;
  this->clipLinks = nullptr;
  this->touchCount = -1;
  p_nextDeleted = &this->nextDeleted;
  this->animatedModel = animatedModel;
  for ( i = 8; i != 0; --i )
    *++p_nextDeleted = nullptr;
  this->nextDeleted = nullptr;
  return this;
}


// ========================================================================
// __unwind$247734
// EA  : 0x82739C68
// RVA : 0x00739C68
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void _unwind_247734()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 136));
}


// ========================================================================
// ??1idClipModel@@EAA@XZ
// EA  : 0x82739CA0
// RVA : 0x00739CA0
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::~idClipModel(idClipModel *this)
{
  this->__vftable = (idClipModel_vtbl *)&idClipModel::`vftable';
  idClipModel::FreeModel(this);
  this->collisionModel = nullptr;
  this->animatedModel = nullptr;
  this->clip = nullptr;
  this->clipLinks = nullptr;
  this->nextDeleted = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->traceModels);
}


// ========================================================================
// __unwind$247888
// EA  : 0x82739D08
// RVA : 0x00739D08
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void _unwind_247888()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// ?Link_r@idClipModel@@AAAXPAUclipSector_t@@@Z
// EA  : 0x82739D38
// RVA : 0x00739D38
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::Link_r(idClipModel *this, clipSector_t *node)
{
  clipSector_t *v3; // r31
  double dist; // fp0
  clipLink_t *v5; // r3
  clipLink_t *clipLinks; // r11

  v3 = node;
  while ( v3->axis != -1 )
  {
    dist = v3->dist;
    if ( *(&this->absBounds.b[0].x + v3->axis) <= dist )
    {
      if ( *(&this->absBounds.b[1].x + v3->axis) >= dist )
        idClipModel::Link_r(this, node: v3->children[0]);
      v3 = v3->children[1];
    }
    else
    {
      v3 = v3->children[0];
    }
  }
  v5 = (clipLink_t *)idBlockAlloc<clipLink_t,256,13>::Alloc(this: &this->clip->clipLinkAllocator);
  v5->clipModel = this;
  v5->sector = v3;
  v5->nextInSector = v3->clipLinks;
  v5->prevInSector = nullptr;
  clipLinks = v3->clipLinks;
  if ( clipLinks != nullptr )
    clipLinks->prevInSector = v5;
  v3->clipLinks = v5;
  v5->nextLink = this->clipLinks;
  this->clipLinks = v5;
}


// ========================================================================
// ?Link@idClipModel@@QAAXXZ
// EA  : 0x82739E10
// RVA : 0x00739E10
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::Link(idClipModel *this)
{
  char v2; // r11
  double v3; // fp7
  double v4; // fp6
  double y; // fp3
  double v6; // fp2
  double v7; // fp13
  double v8; // fp10
  double v9; // fp9
  double v10; // fp7
  double v11; // fp3
  int i; // r30
  int v13; // r3

  if ( this->clipLinks != nullptr )
    idClipModel::Unlink(this);
  if ( this->bounds.b[0].x <= (double)this->bounds.b[1].x )
  {
    if ( this->axis.mat[0].x != 1.0 || this->axis.mat[1].y != 1.0 || (v2 = 0, this->axis.mat[2].z != 1.0) )
      v2 = 1;
    if ( v2 != 0 )
    {
      idBounds::FromTransformedBounds(
        this: &this->absBounds,
        bounds: &this->bounds,
        origin: &this->origin,
        axis: &this->axis);
    }
    else
    {
      v3 = (float)(this->bounds.b[0].y + this->origin.y);
      v4 = (float)(this->bounds.b[0].z + this->origin.z);
      this->absBounds.b[0].x = this->bounds.b[0].x + this->origin.x;
      this->absBounds.b[0].y = v3;
      this->absBounds.b[0].z = v4;
      y = this->bounds.b[1].y;
      v6 = this->origin.y;
      v7 = (float)(this->bounds.b[1].z + this->origin.z);
      this->absBounds.b[1].x = this->bounds.b[1].x + this->origin.x;
      this->absBounds.b[1].y = (float)y + (float)v6;
      this->absBounds.b[1].z = v7;
    }
    v8 = (float)(this->absBounds.b[0].y - (float)1.0);
    v9 = (float)(this->absBounds.b[0].z - (float)1.0);
    this->absBounds.b[0].x = this->absBounds.b[0].x - (float)1.0;
    this->absBounds.b[0].y = v8;
    this->absBounds.b[0].z = v9;
    v10 = this->absBounds.b[1].y;
    v11 = (float)(this->absBounds.b[1].z + (float)1.0);
    this->absBounds.b[1].x = this->absBounds.b[1].x + (float)1.0;
    this->absBounds.b[1].z = v11;
    this->absBounds.b[1].y = (float)v10 + (float)1.0;
    idClipModel::Link_r(this, node: this->clip->clipSectors.list);
    if ( (this->contents & 0x20000) != 0 )
    {
      for ( i = 163924; i < 163956; i += 4 )
      {
        v13 = *(int *)((char *)&this->clip->world + i);
        if ( v13 != 0 )
          *(_DWORD *)((char *)this + i - 163740) = (*(int (__fastcall **)(int, idClipModel *))(*(_DWORD *)v13 + 252))(
                                                     a1: v13,
                                                     a2: this);
      }
    }
  }
}


// ========================================================================
// ?Link@idClipModel@@QAAXHHHABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82739FD8
// RVA : 0x00739FD8
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::Link(
        idClipModel *this,
        int newEntityNumber,
        int newPhysicsId,
        int newBodyId,
        const idVec3 *newOrigin,
        const idMat3 *newAxis)
{
  this->entityNumber = newEntityNumber;
  this->physicsId = newPhysicsId;
  this->bodyId = newBodyId;
  this->origin = *newOrigin;
  this->axis = *newAxis;
  idClipModel::Link(this);
}


// ========================================================================
// ?Link@idClipModel@@QAAXHHHABVidVec3@@ABVidMat3@@ABVidBounds@@@Z
// EA  : 0x8273A050
// RVA : 0x0073A050
// PDB : w:\tech5\engine\gamelib\physics\clipmodel.cpp
// ========================================================================

void __fastcall idClipModel::Link(
        idClipModel *this,
        int newEntityNumber,
        int newPhysicsId,
        int newBodyId,
        const idVec3 *newOrigin,
        const idMat3 *newAxis,
        const idBounds *newBounds)
{
  this->entityNumber = newEntityNumber;
  this->physicsId = newPhysicsId;
  this->bodyId = newBodyId;
  this->origin = *newOrigin;
  this->axis = *newAxis;
  this->bounds = *newBounds;
  idClipModel::Link(this);
}

