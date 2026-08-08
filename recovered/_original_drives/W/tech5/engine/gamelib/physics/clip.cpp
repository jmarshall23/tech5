
// ========================================================================
// ?DeleteClipModels@idClip@@QAAXXZ
// EA  : 0x8272B730
// RVA : 0x0072B730
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::DeleteClipModels(idClip *this)
{
  idTraceModelRecycler *traceModelRecycler; // r3
  idClipModel **p_deletedClipModels; // r31
  idClipModel *v4; // r3
  bool v5; // cr58

  traceModelRecycler = this->traceModelRecycler;
  if ( traceModelRecycler != nullptr )
    idTraceModelRecycler::UpdateDeferredFreed(this: traceModelRecycler);
  p_deletedClipModels = &this->deletedClipModels;
  while ( *p_deletedClipModels != nullptr )
  {
    v4 = *p_deletedClipModels;
    v5 = *p_deletedClipModels == nullptr;
    *p_deletedClipModels = (*p_deletedClipModels)->nextDeleted;
    if ( !v5 )
      ((void (__fastcall *)(idClipModel *, int))v4->dtr_idClipModel)(a1: v4, a2: 1);
  }
}


// ========================================================================
// ?StartQueryFrame@idClip@@QAAXXZ
// EA  : 0x8272B7B8
// RVA : 0x0072B7B8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idClip::StartQueryFrame(idClip *this)
{
  __int128 v1; // r11 OVERLAPPED
  int v2; // r7

  *((_QWORD *)&v1 + 1) = this->gatherResultLastAllocedIndex;
  *(_QWORD *)((char *)&v1 + 4) = *(_QWORD *)((char *)&this->world + HIDWORD(this->gatherQueryLastAllocedIndex));
  *(_QWORD *)&v1 = this->residencyQueryLastAllocedIndex;
  ++DWORD2(v1);
  v2 = 427472;
  this->collisionQueryFirstAllocedIndex = *(_QWORD *)((char *)&v1 + 4);
  DWORD2(v1) = DWORD1(v1) + 1;
  ++HIDWORD(v1);
  LODWORD(v1) = v1 + 1;
  this->gatherQueryFirstAllocedIndex = *(_QWORD *)((char *)&v1 + 12);
  DWORD1(v1) = &consoleFont[21088];
  this->gatherResultFirstAllocedIndex = v1;
  this->residencyQueryFirstAllocedIndex = *(_QWORD *)((char *)&v1 + 4);
  idCollisionModelManager::StartQueryFrame(this: collisionModelManager);
}


// ========================================================================
// ?EndQueryFrame@idClip@@QAAXXZ
// EA  : 0x8272B860
// RVA : 0x0072B860
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::EndQueryFrame(idClip *this)
{
  unsigned __int64 collisionQueryFirstAllocedIndex; // r9
  unsigned __int64 gatherQueryFirstAllocedIndex; // r7
  __int128 v3; // r5

  collisionQueryFirstAllocedIndex = this->collisionQueryFirstAllocedIndex;
  gatherQueryFirstAllocedIndex = this->gatherQueryFirstAllocedIndex;
  *((_QWORD *)&v3 + 1) = this->gatherResultFirstAllocedIndex;
  *(_QWORD *)((char *)&v3 + 4) = *(_QWORD *)((char *)&this->world + DWORD2(v3));
  HIDWORD(collisionQueryFirstAllocedIndex) = 427456;
  HIDWORD(gatherQueryFirstAllocedIndex) = 460256;
  *(_QWORD *)(DWORD1(v3) + 377208) = collisionQueryFirstAllocedIndex;
  *(_QWORD *)(DWORD1(v3) + 394656) = gatherQueryFirstAllocedIndex;
  *(_QWORD *)(DWORD1(v3) + 427456) = v3;
  *(_QWORD *)(DWORD1(v3) + 460256) = *(_QWORD *)((char *)&v3 + 4);
  idCollisionModelManager::EndQueryFrame(this: collisionModelManager);
}


// ========================================================================
// ?UpdateClipQueryStats@@YAXPBDQAUclipQueryStats_t@@@Z
// EA  : 0x8272B8F0
// RVA : 0x0072B8F0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall UpdateClipQueryStats(const char *userName, clipQueryStats_t *stats)
{
  int v2; // r10
  clipQueryStats_t *v3; // r9
  int v4; // r9
  clipQueryStats_t *v5; // r11

  v2 = 0;
  if ( numClipQueryStats <= 0 )
  {
LABEL_5:
    if ( numClipQueryStats < 512 )
    {
      v4 = numClipQueryStats;
      v5 = &stats[numClipQueryStats++];
      stats[v4].userName = userName;
      v5->count = 1;
      v5->max = 1;
    }
  }
  else
  {
    v3 = clipQueryStats;
    while ( v3->userName != userName )
    {
      ++v2;
      ++v3;
      if ( v2 >= numClipQueryStats )
        goto LABEL_5;
    }
    ++clipQueryStats[v2].count;
  }
}


// ========================================================================
// ?Shutdown@idClip@@QAAXXZ
// EA  : 0x8272BAB0
// RVA : 0x0072BAB0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::Shutdown(idClip *this)
{
  idClipModel *defaultClipModel; // r3
  idClipModel *playerMeleeClipModel; // r3
  idClipModel *clip8x8; // r3
  idClipModel *clip8x8x8; // r3
  idClipModel *clip16x16; // r3
  idClipModel *clip16x16x16; // r3
  idClipModel *clip24x24; // r3
  idClipModel *clip32x32; // r3
  idClipModel *clip8x16; // r3
  idClipModel *clip48x48; // r3
  idClipModel *clip96x96; // r3
  idClipModel *clip24x24x96; // r3
  idClipModel *clip32x32x96; // r3
  idClipModel *clip48x48x96; // r3

  idClip::DeleteClipModels(this);
  if ( this->world != nullptr )
    ((void (__fastcall *)(idClipModel *, int))this->world->dtr_idClipModel)(a1: this->world, a2: 1);
  defaultClipModel = this->defaultClipModel;
  this->world = nullptr;
  if ( defaultClipModel != nullptr )
    ((void (__fastcall *)(idClipModel *, int))defaultClipModel->dtr_idClipModel)(a1: defaultClipModel, a2: 1);
  playerMeleeClipModel = this->playerMeleeClipModel;
  this->defaultClipModel = nullptr;
  if ( playerMeleeClipModel != nullptr )
    ((void (__fastcall *)(idClipModel *, int))playerMeleeClipModel->dtr_idClipModel)(a1: playerMeleeClipModel, a2: 1);
  clip8x8 = this->clip8x8;
  this->playerMeleeClipModel = nullptr;
  if ( clip8x8 != nullptr )
    ((void (__fastcall *)(idClipModel *, int))clip8x8->dtr_idClipModel)(a1: clip8x8, a2: 1);
  clip8x8x8 = this->clip8x8x8;
  if ( clip8x8x8 != nullptr )
    ((void (__fastcall *)(idClipModel *, int))clip8x8x8->dtr_idClipModel)(a1: clip8x8x8, a2: 1);
  clip16x16 = this->clip16x16;
  if ( clip16x16 != nullptr )
    ((void (__fastcall *)(idClipModel *, int))clip16x16->dtr_idClipModel)(a1: clip16x16, a2: 1);
  clip16x16x16 = this->clip16x16x16;
  if ( clip16x16x16 != nullptr )
    ((void (__fastcall *)(idClipModel *, int))clip16x16x16->dtr_idClipModel)(a1: clip16x16x16, a2: 1);
  clip24x24 = this->clip24x24;
  if ( clip24x24 != nullptr )
    ((void (__fastcall *)(idClipModel *, int))clip24x24->dtr_idClipModel)(a1: clip24x24, a2: 1);
  clip32x32 = this->clip32x32;
  if ( clip32x32 != nullptr )
    ((void (__fastcall *)(idClipModel *, int))clip32x32->dtr_idClipModel)(a1: clip32x32, a2: 1);
  clip8x16 = this->clip8x16;
  if ( clip8x16 != nullptr )
    ((void (__fastcall *)(idClipModel *, int))clip8x16->dtr_idClipModel)(a1: clip8x16, a2: 1);
  clip48x48 = this->clip48x48;
  if ( clip48x48 != nullptr )
    ((void (__fastcall *)(idClipModel *, int))clip48x48->dtr_idClipModel)(a1: clip48x48, a2: 1);
  clip96x96 = this->clip96x96;
  if ( clip96x96 != nullptr )
    ((void (__fastcall *)(idClipModel *, int))clip96x96->dtr_idClipModel)(a1: clip96x96, a2: 1);
  clip24x24x96 = this->clip24x24x96;
  if ( clip24x24x96 != nullptr )
    ((void (__fastcall *)(idClipModel *, int))clip24x24x96->dtr_idClipModel)(a1: clip24x24x96, a2: 1);
  clip32x32x96 = this->clip32x32x96;
  if ( clip32x32x96 != nullptr )
    ((void (__fastcall *)(idClipModel *, int))clip32x32x96->dtr_idClipModel)(a1: clip32x32x96, a2: 1);
  clip48x48x96 = this->clip48x48x96;
  if ( clip48x48x96 != nullptr )
    ((void (__fastcall *)(idClipModel *, int))clip48x48x96->dtr_idClipModel)(a1: clip48x48x96, a2: 1);
  this->clip8x8 = nullptr;
  this->clip8x8x8 = nullptr;
  this->clip16x16 = nullptr;
  this->clip16x16x16 = nullptr;
  this->clip24x24 = nullptr;
  this->clip32x32 = nullptr;
  this->clip8x16 = nullptr;
  this->clip48x48 = nullptr;
  this->clip96x96 = nullptr;
  this->clip24x24x96 = nullptr;
  this->clip32x32x96 = nullptr;
  this->clip48x48x96 = nullptr;
  idBlockAlloc<clipLink_t,256,13>::Shutdown(this: &this->clipLinkAllocator);
}


// ========================================================================
// ?InitializeAASLinks_r@idClip@@AAAXW4aasType_t@@PBUclipSector_t@@@Z
// EA  : 0x8272BD10
// RVA : 0x0072BD10
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::InitializeAASLinks_r(idClip *this, aasType_t aasType, const clipSector_t *node)
{
  const clipSector_t *i; // r31
  clipLink_t *clipLinks; // r31
  int *p_touchCount; // r30
  idClipModel *clipModel; // r11

  for ( i = node; i->axis != -1; i = i->children[1] )
    idClip::InitializeAASLinks_r(this, aasType, node: i->children[0]);
  clipLinks = i->clipLinks;
  if ( clipLinks != nullptr )
  {
    p_touchCount = &this->touchCount;
    do
    {
      clipModel = clipLinks->clipModel;
      if ( clipLinks->clipModel->touchCount != *p_touchCount && (clipModel->contents & 0x20000) != 0 )
      {
        clipModel->touchCount = *p_touchCount;
        idClipModel::RelinkIntoAASes(this: clipLinks->clipModel, aasType);
      }
      clipLinks = clipLinks->nextInSector;
    }
    while ( clipLinks != nullptr );
  }
}


// ========================================================================
// ?InitializeAASLinks@idClip@@QAAXW4aasType_t@@@Z
// EA  : 0x8272BDB0
// RVA : 0x0072BDB0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::InitializeAASLinks(idClip *this, __int32 aasType)
{
  int v4; // r29
  idAAS2 **aases; // r31
  idAAS2 *v6; // r10
  clipSector_t *list; // r31
  int *p_touchCount; // r29
  clipLink_t *i; // r31
  idClipModel *clipModel; // r11

  if ( aasType == 8 )
  {
    v4 = 8;
    aases = this->aases;
    do
    {
      if ( *aases != nullptr )
        (*aases)->FreeClipLinks(this: *aases);
      --v4;
      ++aases;
    }
    while ( v4 != 0 );
  }
  else
  {
    v6 = this->aases[aasType];
    if ( v6 != nullptr )
      ((void (*)(void))v6->FreeClipLinks)();
  }
  list = this->clipSectors.list;
  p_touchCount = &this->touchCount;
  ++this->touchCount;
  for ( ; list->axis != -1; list = list->children[1] )
    idClip::InitializeAASLinks_r(this, (aasType_t)aasType, node: list->children[0]);
  for ( i = list->clipLinks; i != nullptr; i = i->nextInSector )
  {
    clipModel = i->clipModel;
    if ( i->clipModel->touchCount != *p_touchCount && (clipModel->contents & 0x20000) != 0 )
    {
      clipModel->touchCount = *p_touchCount;
      idClipModel::RelinkIntoAASes(this: i->clipModel, (const aasType_t)aasType);
    }
  }
}


// ========================================================================
// ?GetWorldBounds@idClip@@QBAABVidBounds@@XZ
// EA  : 0x8272BED0
// RVA : 0x0072BED0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

const idBounds *__fastcall idClip::GetWorldBounds(idClip *this)
{
  return &this->world->bounds;
}


// ========================================================================
// ?DeleteClipModel@idClip@@QAAXPAVidClipModel@@@Z
// EA  : 0x8272BEE0
// RVA : 0x0072BEE0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::DeleteClipModel(idClip *this, idClipModel *clipModel)
{
  idClipModel **p_deletedClipModels; // r30
  idClipModel *deletedClipModels; // r11

  if ( clipModel != nullptr )
  {
    p_deletedClipModels = &this->deletedClipModels;
    deletedClipModels = this->deletedClipModels;
    if ( deletedClipModels != nullptr )
    {
      while ( deletedClipModels != clipModel )
      {
        deletedClipModels = deletedClipModels->nextDeleted;
        if ( deletedClipModels == nullptr )
          goto LABEL_5;
      }
      idLib::Warning(
        fmt: "Tried to add clipModel 0x%p from entity %d twice to delete list",
        clipModel,
        clipModel->entityNumber);
    }
    else
    {
LABEL_5:
      idClipModel::Unlink(this: clipModel);
      clipModel->nextDeleted = *p_deletedClipModels;
      *p_deletedClipModels = clipModel;
    }
  }
}


// ========================================================================
// ?TraceBoundsFromLocalSpaceBounds@idClip@@ABAXAAVidBounds@@ABV2@W4type_t@idClipCollisionQuery@1@ABVidClipQueryParms@1@@Z
// EA  : 0x8272BF70
// RVA : 0x0072BF70
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::TraceBoundsFromLocalSpaceBounds(
        idClip *this,
        idBounds *traceBounds,
        const idBounds *localBounds,
        idClip::idClipCollisionQuery::type_t type,
        const idClip::idClipQueryParms *parms)
{
  double v8; // fp7
  double v9; // fp6
  float y; // r10
  float z; // r9
  float x; // r8
  float v13; // r7
  float v14; // r5
  float v15; // r6
  double v16; // fp12
  double v18; // fp11
  double v20; // fp10
  double v32; // fp2
  double v34; // fp12
  double v36; // fp11
  double v44; // fp5
  double v50; // fp10
  double v60; // fp10
  idVec3 v70; // [sp+50h] [-B0h] BYREF
  float v71; // [sp+60h] [-A0h]
  float v72; // [sp+64h] [-9Ch]
  float v73; // [sp+68h] [-98h]
  float v74; // [sp+70h] [-90h]
  float v75; // [sp+74h] [-8Ch]
  float v76; // [sp+78h] [-88h]
  idVec3 v77; // [sp+80h] [-80h] BYREF
  idRotation v78; // [sp+90h] [-70h] BYREF

  switch ( type )
  {
    case QUERY_SUBMITTED_TRANSLATION:
      v8 = (float)(parms->end.y - parms->start.y);
      v9 = (float)(parms->end.z - parms->start.z);
      v77.x = parms->end.x - parms->start.x;
      v77.y = v8;
      v77.z = v9;
      idBounds::FromBoundsTranslation(
        this: traceBounds,
        bounds: localBounds,
        boundsOrigin: &parms->start,
        boundsAxis: &parms->startAxis,
        translation: &v77);
      break;
    case QUERY_SUBMITTED_ROTATION:
      idRotation::idRotation(
        this: &v78,
        rotationOrigin: &parms->origin,
        rotationVec: &parms->vec,
        rotationAngle: parms->f1);
      idBounds::FromBoundsRotation(
        this: traceBounds,
        bounds: localBounds,
        boundsOrigin: &parms->start,
        boundsAxis: &parms->startAxis,
        rotation: &v78);
      break;
    case QUERY_SUBMITTED_MOTION:
    case QUERY_SUBMITTED_MOTION_CONTACTS:
      idRotation::idRotation(
        this: &v78,
        rotationOrigin: &parms->origin,
        rotationVec: &parms->vec,
        rotationAngle: parms->f1);
      idBounds::FromBoundsRotation(
        this: traceBounds,
        bounds: localBounds,
        boundsOrigin: &parms->start,
        boundsAxis: &parms->startAxis,
        rotation: &v78);
      idBounds::AddTranslation(this: traceBounds, start: &parms->start, end: &parms->end);
      break;
    case QUERY_SUBMITTED_STEPMOVE:
    case QUERY_SUBMITTED_STEPMOVE_CONTACTS:
      idBounds::FromTransformedBounds(
        this: traceBounds,
        bounds: localBounds,
        origin: &parms->start,
        axis: &parms->startAxis);
      _FP11 = (float)(parms->vec.x * parms->f2);
      _FP7 = (float)(parms->vec.y * parms->f2);
      _FP6 = (float)(parms->vec.z * parms->f2);
      __asm
      {
        fsel      f5, f11, f0, f11
        fsel      f4, f11, f11, f0
        fsel      f3, f7, f0, f7
        fsel      f2, f7, f7, f0
        fsel      f1, f6, f0, f6
        fsel      f13, f6, f6, f0
      }
      traceBounds->b[0].x = (float)_FP5 + traceBounds->b[0].x;
      traceBounds->b[1].x = (float)_FP4 + traceBounds->b[1].x;
      traceBounds->b[0].y = (float)_FP3 + traceBounds->b[0].y;
      traceBounds->b[1].y = (float)_FP2 + traceBounds->b[1].y;
      traceBounds->b[0].z = (float)_FP1 + traceBounds->b[0].z;
      traceBounds->b[1].z = (float)_FP13 + traceBounds->b[1].z;
      v60 = -parms->f1;
      _FP9 = (float)(parms->vec.x * (float)v60);
      _FP7 = (float)(parms->vec.y * (float)v60);
      _FP6 = (float)(parms->vec.z * (float)v60);
      __asm
      {
        fsel      f5, f9, f0, f9
        fsel      f4, f9, f9, f0
        fsel      f3, f7, f0, f7
        fsel      f2, f7, f7, f0
        fsel      f1, f6, f0, f6
        fsel      f0, f6, f6, f0
      }
      traceBounds->b[0].x = (float)_FP5 + traceBounds->b[0].x;
      traceBounds->b[1].x = (float)_FP4 + traceBounds->b[1].x;
      traceBounds->b[0].y = (float)_FP3 + traceBounds->b[0].y;
      traceBounds->b[1].y = (float)_FP2 + traceBounds->b[1].y;
      traceBounds->b[0].z = (float)_FP1 + traceBounds->b[0].z;
      traceBounds->b[1].z = (float)_FP0 + traceBounds->b[1].z;
      break;
    case QUERY_SUBMITTED_SLIDEMOVE:
    case QUERY_SUBMITTED_SLIDEMOVE_CONTACTS:
      y = parms->vec.y;
      z = parms->vec.z;
      x = parms->end.x;
      v13 = parms->end.y;
      v14 = parms->vec.x;
      v70.y = parms->vec.y;
      v70.z = z;
      v70.x = v14;
      v15 = parms->end.z;
      v71 = x;
      v72 = v13;
      v74 = v14;
      v75 = y;
      v73 = v15;
      v76 = z;
      idVec3::NormalizeFast(this: &v70);
      idBounds::FromTransformedBounds(
        this: traceBounds,
        bounds: localBounds,
        origin: &parms->start,
        axis: &parms->startAxis);
      v16 = v70.x;
      _FP6 = (float)(v70.x * parms->f2);
      v18 = v70.y;
      _FP4 = (float)(v70.y * parms->f2);
      v20 = v70.z;
      _FP3 = (float)(v70.z * parms->f2);
      _FP13 = v74;
      __asm
      {
        fsel      f9, f13, f0, f13
        fsel      f8, f13, f13, f0
      }
      _FP13 = v75;
      __asm
      {
        fsel      f2, f6, f0, f6
        fsel      f1, f6, f6, f0
        fsel      f7, f4, f0, f4
        fsel      f6, f4, f4, f0
        fsel      f4, f3, f0, f3
        fsel      f3, f3, f3, f0
      }
      traceBounds->b[0].x = (float)_FP2 + traceBounds->b[0].x;
      traceBounds->b[1].x = (float)_FP1 + traceBounds->b[1].x;
      traceBounds->b[0].y = (float)_FP7 + traceBounds->b[0].y;
      traceBounds->b[1].y = (float)_FP6 + traceBounds->b[1].y;
      traceBounds->b[0].z = (float)_FP4 + traceBounds->b[0].z;
      traceBounds->b[1].z = (float)_FP3 + traceBounds->b[1].z;
      v32 = -parms->f1;
      _FP1 = (float)((float)v32 * (float)v16);
      v34 = v73;
      _FP7 = (float)((float)v18 * (float)v32);
      v36 = v72;
      _FP6 = (float)((float)v20 * (float)v32);
      __asm
      {
        fsel      f5, f1, f0, f1
        fsel      f3, f1, f1, f0
        fsel      f2, f7, f0, f7
        fsel      f1, f7, f7, f0
        fsel      f7, f6, f0, f6
        fsel      f6, f6, f6, f0
      }
      traceBounds->b[0].x = (float)_FP5 + traceBounds->b[0].x;
      traceBounds->b[1].x = (float)_FP3 + traceBounds->b[1].x;
      v44 = (float)((float)v34 * (float)v34);
      traceBounds->b[0].y = (float)_FP2 + traceBounds->b[0].y;
      __asm { fsel      f2, f13, f0, f13 }
      _FP12 = v76;
      __asm
      {
        fsel      f13, f13, f13, f0
        fsel      f4, f12, f0, f12
      }
      __asm { fsel      f0, f12, f12, f0 }
      v50 = __fsqrts((float)((float)(v71 * v71) + (float)((float)((float)v36 * (float)v36) + (float)v44)));
      traceBounds->b[1].y = (float)_FP1 + traceBounds->b[1].y;
      traceBounds->b[0].z = (float)_FP7 + traceBounds->b[0].z;
      traceBounds->b[1].z = (float)_FP6 + traceBounds->b[1].z;
      traceBounds->b[0].x = (float)_FP9 + traceBounds->b[0].x;
      traceBounds->b[1].x = (float)_FP8 + traceBounds->b[1].x;
      traceBounds->b[0].y = (float)_FP2 + traceBounds->b[0].y;
      traceBounds->b[1].y = (float)_FP13 + traceBounds->b[1].y;
      traceBounds->b[0].z = (float)_FP4 + traceBounds->b[0].z;
      traceBounds->b[1].z = (float)_FP0 + traceBounds->b[1].z;
      traceBounds->b[0].x = traceBounds->b[0].x - (float)v50;
      traceBounds->b[0].y = traceBounds->b[0].y - (float)v50;
      traceBounds->b[0].z = traceBounds->b[0].z - (float)v50;
      traceBounds->b[1].x = traceBounds->b[1].x + (float)v50;
      traceBounds->b[1].y = traceBounds->b[1].y + (float)v50;
      traceBounds->b[1].z = traceBounds->b[1].z + (float)v50;
      break;
    default:
      break;
  }
  traceBounds->b[0].x = traceBounds->b[0].x - (float)1.0;
  traceBounds->b[0].y = traceBounds->b[0].y - (float)1.0;
  traceBounds->b[0].z = traceBounds->b[0].z - (float)1.0;
  traceBounds->b[1].x = traceBounds->b[1].x + (float)1.0;
  traceBounds->b[1].y = traceBounds->b[1].y + (float)1.0;
  traceBounds->b[1].z = traceBounds->b[1].z + (float)1.0;
}


// ========================================================================
// ?GatherTouchingBounds@idClip@@QAA?AVidGatherQuery@@ABVidBounds@@HHPBD@Z
// EA  : 0x8272C428
// RVA : 0x0072C428
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

idClip *__fastcall idClip::GatherTouchingBounds(
        idClip *this,
        idGatherQuery *result,
        const idBounds *bounds,
        int clipMask,
        __int16 passEntityNumber,
        const char *userName)
{
  unsigned __int64 v6; // r11
  unsigned __int64 index; // r9
  double x; // fp13
  idGatherQuery *v9; // r4

  if ( HIDWORD(result->index) != 0
    && (index = result[49332].index, (unsigned int)((v6 = result[49335].index) - index + 1) <= 0x100) )
  {
    LODWORD(index) = v6 + 1;
    *(_QWORD *)HIDWORD(v6) = index;
    x = bounds->b[0].x;
    *((_DWORD *)&result[47156].index + (unsigned __int8)(v6 + 1)) = HIDWORD(index);
    v9 = (idGatherQuery *)((char *)result + ((*(_DWORD *)(HIDWORD(v6) + 4) << 6) & 0x3FC0) + 378272);
    *(float *)&v9->index = x;
    *((float *)&v9->index + 1) = bounds->b[0].y;
    v9[1].index = *(unsigned __int64 *)&bounds->b[0].z;
    v9[2].index = *(unsigned __int64 *)&bounds->b[1].y;
    *(float *)&v9[4].index = 0.0;
    *((float *)&v9[3].index + 1) = 0.0;
    *(float *)&v9[3].index = 0.0;
    *((float *)&v9[5].index + 1) = 0.0;
    *(float *)&v9[5].index = 0.0;
    *((float *)&v9[4].index + 1) = 0.0;
    HIDWORD(v9[6].index) = clipMask;
    WORD2(v9[6].index) = passEntityNumber;
    LOWORD(v9[6].index) = 0;
    HIWORD(v9[7].index) = 0;
    WORD1(v9[7].index) = 0;
    LODWORD(v9[7].index) = 0;
    *(_QWORD *)&this->world = *(_QWORD *)HIDWORD(v6);
  }
  else
  {
    LODWORD(v6) = 0;
    *(_QWORD *)&this->world = v6;
  }
  return this;
}


// ========================================================================
// ?GatherTouchingClipModel@idClip@@QAA?AVidGatherQuery@@ABVidVec3@@PBVidClipModel@@ABVidMat3@@HHPBD@Z
// EA  : 0x8272C510
// RVA : 0x0072C510
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idClip *__fastcall idClip::GatherTouchingClipModel(
        idClip *this,
        idGatherQuery *result,
        const idVec3 *start,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber)
{
  __int64 userName; // r11 OVERLAPPED
  int v8; // r31 OVERLAPPED
  int v9; // r30
  unsigned int v10; // r31
  double x; // fp0
  char *v12; // r4
  __int16 v13; // r9

  if ( HIDWORD(result->index) != 0
    && (LODWORD(userName) = result + 49335, *(idGatherQuery *)&v8 = result[49335], (unsigned int)(v8 - v9 + 1) <= 0x100) )
  {
    v10 = v8 + 1;
    *(_QWORD *)userName = v10;
    x = start->x;
    *((_DWORD *)&result[47156].index + (unsigned __int8)v10) = HIDWORD(userName);
    *(__int64 *)((char *)&userName + 4) = *(_QWORD *)userName;
    v12 = (char *)result + ((LODWORD(result[49335].index) << 6) & 0x3FC0);
    *((float *)v12 + 94568) = x;
    *((float *)v12 + 94569) = start->y;
    *((float *)v12 + 94570) = start->z;
    *(idMat3 *)(v12 + 378284) = *startAxis;
    *((_WORD *)v12 + 189162) = v13;
    *((_DWORD *)v12 + 94580) = clipMask;
    *((_WORD *)v12 + 189163) = 2;
    *((_WORD *)v12 + 189164) = 0;
    *((_WORD *)v12 + 189165) = 0;
    *((_DWORD *)v12 + 94583) = clipModel;
    *(_QWORD *)&this->world = *(_QWORD *)userName;
  }
  else
  {
    LODWORD(userName) = 0;
    *(_QWORD *)&this->world = userName;
  }
  return this;
}


// ========================================================================
// ?TestResidency@idClip@@QAA?AVidResidencyQuery@@ABVidBounds@@@Z
// EA  : 0x8272C618
// RVA : 0x0072C618
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

idClip *__fastcall idClip::TestResidency(idClip *this, idResidencyQuery *result, const idBounds *absBounds)
{
  unsigned __int64 index; // r11

  if ( HIDWORD(result->index) != 0
    && (unsigned int)((index = result[57535].index) - LODWORD(result[57532].index) + 1) <= 0x400 )
  {
    LODWORD(index) = index + 1;
    *(_QWORD *)HIDWORD(index) = index;
    LODWORD(index) = &result[4 * (index & 0x3FF) + 53436];
    *(idBounds *)index = *absBounds;
    *(_BYTE *)(index + 24) = 0;
    *(_QWORD *)&this->world = *(_QWORD *)HIDWORD(index);
  }
  else
  {
    LODWORD(index) = 0;
    *(_QWORD *)&this->world = index;
  }
  return this;
}


// ========================================================================
// ?LinksPerClipSector_r@idClip@@ABAXPBUclipSector_t@@ABVidBounds@@@Z
// EA  : 0x8272C6B8
// RVA : 0x0072C6B8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::LinksPerClipSector_r(idClip *this, const clipSector_t *node, const idBounds *bounds)
{
  int axis; // r8
  char *v6; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  char *v9; // r10
  _DWORD *v10; // r11
  int j; // ctr
  int v12; // r11
  double dist; // fp0
  const clipSector_t *v14; // r4
  clipLink_t *clipLinks; // r11
  int v16; // r4
  char v17; // [sp+4Ch] [-54h] BYREF
  idBounds v18; // [sp+50h] [-50h] BYREF
  char v19; // [sp+6Ch] [-34h] BYREF
  idBounds v20; // [sp+70h] [-30h] BYREF

  axis = node->axis;
  if ( node->axis == -1 )
  {
    clipLinks = node->clipLinks;
    v16 = 0;
    if ( clipLinks != nullptr )
    {
      do
      {
        clipLinks = clipLinks->nextInSector;
        ++v16;
      }
      while ( clipLinks != nullptr );
      if ( v16 > 16 )
        idLib::Printf(
          fmt: "%d clip models linked at '%1.0f %1.0f %1.0f'\n",
          (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5))),
          (float)((float)(bounds->b[1].x + bounds->b[0].x) * (float)0.5),
          (float)((float)(bounds->b[1].y + bounds->b[0].y) * (float)0.5),
          (float)((float)(bounds->b[1].z + bounds->b[0].z) * (float)0.5));
    }
  }
  else
  {
    v6 = &v17;
    p_z = (_DWORD *)&bounds[-1].b[1].z;
    for ( i = 6; i != 0; --i )
    {
      ++p_z;
      v6 += 4;
      *(_DWORD *)v6 = *p_z;
    }
    v9 = &v19;
    v10 = (_DWORD *)&bounds[-1].b[1].z;
    for ( j = 6; j != 0; --j )
    {
      ++v10;
      v9 += 4;
      *(_DWORD *)v9 = *v10;
    }
    v12 = 4 * axis;
    dist = node->dist;
    v14 = node->children[0];
    *(float *)((char *)&v18.b[0].x + v12) = node->dist;
    *(float *)((char *)&v20.b[1].x + v12) = dist;
    idClip::LinksPerClipSector_r(this, node: v14, bounds: &v18);
    idClip::LinksPerClipSector_r(this, node: node->children[1], bounds: &v20);
  }
}


// ========================================================================
// ?FindStreamArea@idClip@@QAAHPBVidClipModel@@@Z
// EA  : 0x8272C7F8
// RVA : 0x0072C7F8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

int __fastcall idClip::FindStreamArea(idClip *this, idClipModel *clipModel)
{
  idCollisionModel *collisionModel; // r3
  idClipModel *world; // r11
  const char *str; // r31
  idCollisionModel *v6; // r10

  collisionModel = clipModel->collisionModel;
  if ( collisionModel == nullptr )
  {
    if ( clipModel->traceModels.num <= 0 )
      collisionModel = idClipModel::NoTraceModelWarning(this: clipModel);
    else
      collisionModel = clipModel->clip->traceModelCache->cache.list[*clipModel->traceModels.list]->collisionModel;
  }
  world = this->world;
  v6 = this->world->collisionModel;
  str = collisionModel->name.str;
  if ( v6 == nullptr )
  {
    if ( world->traceModels.num <= 0 )
      v6 = idClipModel::NoTraceModelWarning(this: world);
    else
      v6 = world->clip->traceModelCache->cache.list[*world->traceModels.list]->collisionModel;
  }
  return idCollisionModelManager::FindStreamArea(this: collisionModelManager, model: v6, areaName: str);
}


// ========================================================================
// ?SetupDeferredQuery@idClip@@AAAXPAVidClipCollisionQuery@1@W4type_t@21@PBVidClipModel@@ABVidBounds@@ABVidCollisionQuery@@_N@Z
// EA  : 0x8272C980
// RVA : 0x0072C980
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::SetupDeferredQuery(
        idClip *this,
        idClip::idClipCollisionQuery *query,
        idClip::idClipCollisionQuery::type_t type,
        idClipModel *clipModel,
        const idBounds *absBounds,
        const idCollisionQuery *cq,
        bool moveClipModel)
{
  unsigned __int64 offset; // r11

  query->type = type;
  offset = cq->offset;
  query->clipModel = (idClipModel *)HIDWORD(cq->offset);
  query->query.offset = offset;
  if ( moveClipModel && clipModel != nullptr )
  {
    query->clipModel = clipModel;
    clipModel->collisionQuery = (idCollisionQuery)cq->offset;
    clipModel->absBounds = *absBounds;
    if ( clipModel->clipLinks != nullptr )
    {
      idClipModel::Unlink(this: clipModel);
      idClipModel::Link_r(this: clipModel, node: this->clipSectors.list);
      if ( (clipModel->contents & 0x20000) != 0 )
        idClipModel::LinkIntoAASes(this: clipModel, aasType: AAS_FILE_EXTENSION_MAX);
    }
  }
}


// ========================================================================
// ?MoveClipModel@idClip@@AAAXPBVidClipModel@@PAUtrace_t@@@Z
// EA  : 0x8272CA58
// RVA : 0x0072CA58
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::MoveClipModel(idClip *this, idClipModel *clipModel, trace_t *result)
{
  double y; // fp1
  double z; // fp0
  double x; // fp13
  double v9; // fp12
  double v10; // fp11
  idBounds v11; // [sp+50h] [-40h] BYREF

  idBounds::FromTransformedBounds(
    this: &v11,
    bounds: &clipModel->bounds,
    origin: &result->endpos,
    axis: &result->endAxis);
  clipModel->origin = result->endpos;
  clipModel->axis = result->endAxis;
  y = v11.b[0].y;
  z = v11.b[0].z;
  x = v11.b[1].x;
  clipModel->absBounds.b[0].x = v11.b[0].x;
  v9 = v11.b[1].y;
  clipModel->absBounds.b[0].y = y;
  clipModel->absBounds.b[0].z = z;
  clipModel->absBounds.b[1].x = x;
  v10 = v11.b[1].z;
  clipModel->absBounds.b[1].y = v9;
  clipModel->absBounds.b[1].z = v10;
  if ( clipModel->clipLinks != nullptr )
  {
    idClipModel::Unlink(this: clipModel);
    idClipModel::Link_r(this: clipModel, node: this->clipSectors.list);
    if ( (clipModel->contents & 0x20000) != 0 )
      idClipModel::LinkIntoAASes(this: clipModel, aasType: AAS_FILE_EXTENSION_MAX);
  }
}


// ========================================================================
// ?TranslationTraceModelInternal@idClip@@AAAXPAUtrace_t@@PAVidClipCollisionQuery@1@ABVidVec3@@2PBVidClipModel@@2ABVidMat3@@HPBD@Z
// EA  : 0x8272CB68
// RVA : 0x0072CB68
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::TranslationTraceModelInternal(
        idClip *this,
        trace_t *result,
        idClip::idClipCollisionQuery *query,
        const idVec3 *start,
        const idVec3 *end,
        idClipModel *model,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis,
        int clipMask,
        const char *userName,
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
        int a27,
        int a28)
{
  __int64 v28; // r21
  int v36; // ctr
  __int64 *v45; // r11
  int v47; // r26
  float *p_z; // r31
  int v49; // r25
  idCollisionModel *collisionModel; // r3
  double y; // fp13
  int entityNumber; // r11
  double z; // fp12
  int physicsId; // r10
  int bodyId; // r9
  double v56; // fp10
  double v57; // fp9
  unsigned __int64 v58; // r11
  const idMat3 *v59; // [sp+8h] [-2938h]
  int v60; // [sp+Ch] [-2934h]
  const idPositionedCollisionModel *v61; // [sp+10h] [-2930h]
  int v62; // [sp+14h] [-292Ch]
  const char *v63; // [sp+18h] [-2928h]
  int v64; // [sp+1Ch] [-2924h]
  int v65; // [sp+20h] [-2920h]
  int v66; // [sp+24h] [-291Ch]
  int v67; // [sp+28h] [-2918h]
  int v68; // [sp+2Ch] [-2914h]
  int v69; // [sp+30h] [-2910h]
  int v70; // [sp+34h] [-290Ch]
  int v71; // [sp+38h] [-2908h]
  int v72; // [sp+3Ch] [-2904h]
  int v73; // [sp+40h] [-2900h]
  int v74; // [sp+44h] [-28FCh]
  int v75; // [sp+48h] [-28F8h]
  int v76; // [sp+4Ch] [-28F4h]
  int v77; // [sp+50h] [-28F0h]
  int v78; // [sp+58h] [-28E8h]
  int v79; // [sp+60h] [-28E0h]
  int v80; // [sp+68h] [-28D8h]
  const idTraceModel *v81; // [sp+80h] [-28C0h] BYREF
  idBounds v82; // [sp+90h] [-28B0h] BYREF
  __int64 v83; // [sp+A8h] [-2898h] BYREF
  _BYTE v84[40]; // [sp+B0h] [-2890h] BYREF

  _FP10 = (float)(end->x - start->x);
  _FP5 = (float)(end->z - start->z);
  _FP7 = (float)(end->y - start->y);
  LODWORD(v28) = 0;
  __asm { fsel      f3, f10, f12, f13 }
  v36 = 128;
  __asm { fsel      f4, f10, f13, f4 }
  v81 = nullptr;
  __asm { fsel      f13, f5, f6, f8 }
  __asm { fsel      f1, f7, f9, f11 }
  __asm { fsel      f2, f7, f11, f2 }
  v45 = &v83;
  __asm { fsel      f12, f5, f8, f6 }
  v82.b[0].x = (float)_FP3 - (float)1.0;
  v82.b[1].x = (float)_FP4 + (float)1.0;
  v82.b[0].z = (float)_FP13 - (float)1.0;
  v82.b[0].y = (float)_FP1 - (float)1.0;
  v82.b[1].y = (float)_FP2 + (float)1.0;
  v82.b[1].z = (float)_FP12 + (float)1.0;
  do
  {
    v45 += 10;
    *v45 = v28;
    --v36;
  }
  while ( v36 != 0 );
  v47 = 0;
  if ( idClipModel::GetNumCollisionModels(this: model) > 0 )
  {
    p_z = &v82.b[1].z;
    v49 = 0;
    do
    {
      collisionModel = model->collisionModel;
      if ( collisionModel == nullptr )
      {
        if ( v47 >= model->traceModels.num )
          collisionModel = idClipModel::NoTraceModelWarning(this: model);
        else
          collisionModel = model->clip->traceModelCache->cache.list[model->traceModels.list[v49]]->collisionModel;
      }
      *((_DWORD *)p_z + 3) = collisionModel;
      y = modelOrigin->y;
      entityNumber = model->entityNumber;
      z = modelOrigin->z;
      physicsId = model->physicsId;
      p_z[5] = modelOrigin->x;
      bodyId = model->bodyId;
      p_z[6] = y;
      p_z[7] = z;
      ++v47;
      ++v49;
      p_z[8] = modelAxis->mat[0].x;
      v56 = modelAxis->mat[0].y;
      v57 = modelAxis->mat[0].z;
      p_z[11] = modelAxis->mat[1].x;
      p_z[9] = v56;
      p_z[10] = v57;
      p_z[12] = modelAxis->mat[1].y;
      p_z[13] = modelAxis->mat[1].z;
      p_z[14] = modelAxis->mat[2].x;
      p_z[15] = modelAxis->mat[2].y;
      p_z[16] = modelAxis->mat[2].z;
      *((_DWORD *)p_z + 17) = entityNumber;
      *((_DWORD *)p_z + 18) = physicsId;
      *((_DWORD *)p_z + 19) = bodyId;
      p_z += 20;
      *p_z = 0.0;
    }
    while ( v47 < idClipModel::GetNumCollisionModels(this: model) );
  }
  idCollisionModelManager::Translation(
    this: (idCollisionModelManager *)&v83,
    result: (idCollisionQuery *)collisionModelManager,
    a3: result,
    start,
    end,
    globalBounds: &v82,
    trms: &v81,
    numTrms: 1,
    trmAxis: v59,
    contentMask: v60,
    models: v61,
    numModels: v62,
    userName: v63,
    a14: v64,
    a15: v65,
    a16: v66,
    a17: v67,
    a18: v68,
    a19: v69,
    a20: v70,
    a21: v71,
    a22: v72,
    a23: v73,
    a24: v74,
    a25: v75,
    a26: v76,
    a27: v77,
    a28: &mat3_identity,
    a29: v78,
    a30: a28,
    a31: v79,
    a32: (int)v84,
    a33: v80,
    a34: v47);
  if ( query != nullptr )
  {
    v58 = (unsigned int)v83 | 0x200000000LL;
    query->clipModel = nullptr;
    query->type = QUERY_SUBMITTED_TRANSLATION;
    query->query.offset = v58;
  }
}


// ========================================================================
// ?TranslationModel@idClip@@QBAXAAUtrace_t@@ABVidVec3@@1PBVidClipModel@@ABVidMat3@@H213@Z
// EA  : 0x8272CDD8
// RVA : 0x0072CDD8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::TranslationModel(
        idClip *this,
        trace_t *result,
        const idVec3 *start,
        const idVec3 *end,
        const idClipModel *trm,
        idMat3 *trmAxis,
        int clipMask,
        idClipModel *model,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis,
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
        int a27,
        float *a28,
        int a29,
        float *a30)
{
  int num; // r9
  __int64 v32; // r23
  int v37; // r19
  int v38; // r8
  int v39; // r11
  int v40; // ctr
  idTraceModel *v41; // r10
  char *v42; // r11
  int i; // ctr
  int v44; // r26
  int v45; // r25
  float *v46; // r31
  idCollisionModel *collisionModel; // r3
  double v48; // fp13
  int entityNumber; // r11
  double v50; // fp12
  int physicsId; // r10
  int bodyId; // r9
  double v53; // fp10
  double v54; // fp9
  const idMat3 *v55; // [sp+8h] [-2998h]
  int v56; // [sp+Ch] [-2994h]
  const idPositionedCollisionModel *v57; // [sp+10h] [-2990h]
  int v58; // [sp+14h] [-298Ch]
  const char *v59; // [sp+18h] [-2988h]
  int v60; // [sp+1Ch] [-2984h]
  int v61; // [sp+20h] [-2980h]
  int v62; // [sp+24h] [-297Ch]
  int v63; // [sp+28h] [-2978h]
  int v64; // [sp+2Ch] [-2974h]
  int v65; // [sp+30h] [-2970h]
  int v66; // [sp+34h] [-296Ch]
  int v67; // [sp+38h] [-2968h]
  int v68; // [sp+3Ch] [-2964h]
  int v69; // [sp+40h] [-2960h]
  int v70; // [sp+44h] [-295Ch]
  int v71; // [sp+48h] [-2958h]
  int v72; // [sp+4Ch] [-2954h]
  int v73; // [sp+50h] [-2950h]
  int v74; // [sp+58h] [-2948h]
  int v75; // [sp+60h] [-2940h]
  int v76; // [sp+68h] [-2938h]
  idCollisionModelManager v77; // [sp+80h] [-2920h] BYREF
  const idTraceModel *v78[29]; // [sp+90h] [-2910h] BYREF
  int v79; // [sp+104h] [-289Ch] BYREF
  char v80; // [sp+108h] [-2898h] BYREF
  _BYTE v81[40]; // [sp+110h] [-2890h] BYREF

  num = trm->traceModels.num;
  HIDWORD(v32) = result;
  if ( num == 0 )
    idLib::Error(
      fmt: "idClip::TranslationModel: clip model %d of entity '%d' is not a trace model\n",
      trm->bodyId,
      trm->entityNumber);
  if ( (model->contents & clipMask) != 0 )
  {
    LODWORD(v32) = 0;
    v37 = 0;
    v38 = 0;
    if ( num > 0 )
    {
      v39 = 0;
      v40 = num;
      v37 = num;
      do
      {
        if ( v38 >= num )
          v41 = nullptr;
        else
          v41 = trm->clip->traceModelCache->cache.list[trm->traceModels.list[v39]]->trm;
        ++v38;
        v78[v39++] = v41;
        --v40;
      }
      while ( v40 != 0 );
    }
    v42 = &v80;
    for ( i = 128; i != 0; --i )
    {
      v42 += 80;
      *(_QWORD *)v42 = v32;
    }
    v44 = 0;
    if ( idClipModel::GetNumCollisionModels(this: model) > 0 )
    {
      v45 = 0;
      v46 = (float *)&v79;
      do
      {
        collisionModel = model->collisionModel;
        if ( collisionModel == nullptr )
        {
          if ( v44 >= model->traceModels.num )
            collisionModel = idClipModel::NoTraceModelWarning(this: model);
          else
            collisionModel = model->clip->traceModelCache->cache.list[model->traceModels.list[v45]]->collisionModel;
        }
        *((_DWORD *)v46 + 3) = collisionModel;
        v48 = a28[1];
        entityNumber = model->entityNumber;
        v50 = a28[2];
        physicsId = model->physicsId;
        v46[5] = *a28;
        bodyId = model->bodyId;
        v46[6] = v48;
        v46[7] = v50;
        ++v44;
        ++v45;
        v46[8] = *a30;
        v53 = a30[1];
        v54 = a30[2];
        v46[11] = a30[3];
        v46[9] = v53;
        v46[10] = v54;
        v46[12] = a30[4];
        v46[13] = a30[5];
        v46[14] = a30[6];
        v46[15] = a30[7];
        v46[16] = a30[8];
        *((_DWORD *)v46 + 17) = entityNumber;
        *((_DWORD *)v46 + 18) = physicsId;
        *((_DWORD *)v46 + 19) = bodyId;
        v46 += 20;
        *v46 = 0.0;
      }
      while ( v44 < idClipModel::GetNumCollisionModels(this: model) );
    }
    idCollisionModelManager::Translation(
      this: &v77,
      result: (idCollisionQuery *)collisionModelManager,
      a3: (trace_t *)HIDWORD(v32),
      start,
      end,
      globalBounds: &bounds_zero,
      trms: v78,
      numTrms: v37,
      trmAxis: v55,
      contentMask: v56,
      models: v57,
      numModels: v58,
      userName: v59,
      a14: v60,
      a15: v61,
      a16: v62,
      a17: v63,
      a18: v64,
      a19: v65,
      a20: v66,
      a21: v67,
      a22: v68,
      a23: v69,
      a24: v70,
      a25: v71,
      a26: v72,
      a27: v73,
      a28: trmAxis,
      a29: v74,
      a30: clipMask,
      a31: v75,
      a32: (int)v81,
      a33: v76,
      a34: v44);
  }
  else
  {
    *(float *)HIDWORD(v32) = 1.0;
    *(float *)(HIDWORD(v32) + 4) = end->x;
    *(float *)(HIDWORD(v32) + 8) = end->y;
    *(float *)(HIDWORD(v32) + 12) = end->z;
    *(float *)(HIDWORD(v32) + 16) = trmAxis->mat[0].x;
    *(float *)(HIDWORD(v32) + 20) = trmAxis->mat[0].y;
    *(float *)(HIDWORD(v32) + 24) = trmAxis->mat[0].z;
    *(float *)(HIDWORD(v32) + 28) = trmAxis->mat[1].x;
    *(float *)(HIDWORD(v32) + 32) = trmAxis->mat[1].y;
    *(float *)(HIDWORD(v32) + 36) = trmAxis->mat[1].z;
    *(float *)(HIDWORD(v32) + 40) = trmAxis->mat[2].x;
    *(float *)(HIDWORD(v32) + 44) = trmAxis->mat[2].y;
    *(float *)(HIDWORD(v32) + 48) = trmAxis->mat[2].z;
    memset(Dst: (void *)(HIDWORD(v32) + 52), Val: 0, Size: 0x4Cu);
  }
}


// ========================================================================
// ?RotationModel@idClip@@QBAXAAUtrace_t@@ABVidVec3@@ABVidRotation@@PBVidClipModel@@ABVidMat3@@H314@Z
// EA  : 0x8272D098
// RVA : 0x0072D098
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::RotationModel(
        idClip *this,
        trace_t *result,
        const idMat3 *start,
        idRotation *rotation,
        const idClipModel *trm,
        idMat3 *trmAxis,
        const idVec3 *clipMask,
        idClipModel *model,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis,
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
        int a27,
        float *a28,
        int a29,
        float *a30)
{
  int num; // r9
  double y; // fp13
  double z; // fp12
  const idMat3 *v39; // r3
  int v40; // r20
  int v41; // r8
  int v42; // r11
  int v43; // ctr
  idTraceModel *v44; // r10
  char *v45; // r11
  int i; // ctr
  int v47; // r26
  int v48; // r25
  float *v49; // r31
  idCollisionModel *collisionModel; // r3
  double v51; // fp13
  int entityNumber; // r11
  double v53; // fp12
  int physicsId; // r10
  int bodyId; // r9
  double v56; // fp10
  double v57; // fp9
  const idMat3 *v58; // [sp+8h] [-29C8h]
  int v59; // [sp+Ch] [-29C4h]
  const idPositionedCollisionModel *v60; // [sp+10h] [-29C0h]
  int v61; // [sp+14h] [-29BCh]
  const char *v62; // [sp+18h] [-29B8h]
  int v63; // [sp+1Ch] [-29B4h]
  int v64; // [sp+20h] [-29B0h]
  int v65; // [sp+24h] [-29ACh]
  int v66; // [sp+28h] [-29A8h]
  int v67; // [sp+2Ch] [-29A4h]
  int v68; // [sp+30h] [-29A0h]
  int v69; // [sp+34h] [-299Ch]
  int v70; // [sp+38h] [-2998h]
  int v71; // [sp+3Ch] [-2994h]
  int v72; // [sp+40h] [-2990h]
  int v73; // [sp+44h] [-298Ch]
  int v74; // [sp+48h] [-2988h]
  int v75; // [sp+4Ch] [-2984h]
  int v76; // [sp+50h] [-2980h]
  int v77; // [sp+58h] [-2978h]
  int v78; // [sp+60h] [-2970h]
  int v79; // [sp+68h] [-2968h]
  idRotation v80[2]; // [sp+80h] [-2950h] BYREF
  int v81; // [sp+134h] [-289Ch] BYREF
  char v82; // [sp+138h] [-2898h] BYREF
  _BYTE v83[40]; // [sp+140h] [-2890h] BYREF

  num = trm->traceModels.num;
  if ( num == 0 )
    idLib::Error(
      fmt: "idClip::RotationModel: clip model %d of entity '%d' is not a trace model\n",
      trm->bodyId,
      trm->entityNumber);
  if ( (model->contents & (unsigned int)clipMask) != 0 )
  {
    v40 = 0;
    v41 = 0;
    if ( num > 0 )
    {
      v42 = 0;
      v43 = num;
      v40 = num;
      do
      {
        if ( v41 >= num )
          v44 = nullptr;
        else
          v44 = trm->clip->traceModelCache->cache.list[trm->traceModels.list[v42]]->trm;
        ++v41;
        *(_DWORD *)(&v80[0].axisValid + v42 * 4) = v44;
        ++v42;
        --v43;
      }
      while ( v43 != 0 );
    }
    v45 = &v82;
    for ( i = 128; i != 0; --i )
    {
      v45 += 80;
      *(_QWORD *)v45 = 0x2807400000000LL;
    }
    v47 = 0;
    if ( idClipModel::GetNumCollisionModels(this: model) > 0 )
    {
      v48 = 0;
      v49 = (float *)&v81;
      do
      {
        collisionModel = model->collisionModel;
        if ( collisionModel == nullptr )
        {
          if ( v47 >= model->traceModels.num )
            collisionModel = idClipModel::NoTraceModelWarning(this: model);
          else
            collisionModel = model->clip->traceModelCache->cache.list[model->traceModels.list[v48]]->collisionModel;
        }
        *((_DWORD *)v49 + 3) = collisionModel;
        v51 = a28[1];
        entityNumber = model->entityNumber;
        v53 = a28[2];
        physicsId = model->physicsId;
        v49[5] = *a28;
        bodyId = model->bodyId;
        v49[6] = v51;
        v49[7] = v53;
        ++v47;
        ++v48;
        v49[8] = *a30;
        v56 = a30[1];
        v57 = a30[2];
        v49[11] = a30[3];
        v49[9] = v56;
        v49[10] = v57;
        v49[12] = a30[4];
        v49[13] = a30[5];
        v49[14] = a30[6];
        v49[15] = a30[7];
        v49[16] = a30[8];
        *((_DWORD *)v49 + 17) = entityNumber;
        *((_DWORD *)v49 + 18) = physicsId;
        *((_DWORD *)v49 + 19) = bodyId;
        v49 += 20;
        *v49 = 0.0;
      }
      while ( v47 < idClipModel::GetNumCollisionModels(this: model) );
    }
    idCollisionModelManager::Rotation(
      this: (idCollisionModelManager *)v80,
      result: (idCollisionQuery *)collisionModelManager,
      a3: result,
      start,
      rotation,
      globalBounds: &bounds_zero,
      trms: (const idMat3 **)&v80[0].axisValid,
      numTrms: v40,
      trmAxis: v58,
      contentMask: v59,
      models: v60,
      numModels: v61,
      userName: v62,
      a14: v63,
      a15: v64,
      a16: v65,
      a17: v66,
      a18: v67,
      a19: v68,
      a20: v69,
      a21: v70,
      a22: v71,
      a23: v72,
      a24: v73,
      a25: v74,
      a26: v75,
      a27: v76,
      a28: trmAxis,
      a29: v77,
      a30: clipMask,
      a31: v78,
      a32: (int)v83,
      a33: v79,
      a34: v47);
  }
  else
  {
    result->fraction = 1.0;
    idRotation::operator*(this: v80, result: rotation, v: start->mat);
    y = v80[0].origin.y;
    z = v80[0].origin.z;
    result->endpos.x = v80[0].origin.x;
    result->endpos.y = y;
    result->endpos.z = z;
    v39 = idRotation::ToMat3(this: rotation);
    result->endAxis = *idMat3::operator*(this: (idMat3 *)&v80[0].vec.y, result: trmAxis, a: v39);
    memset(Dst: &result->c, Val: 0, Size: sizeof(result->c));
  }
}


// ========================================================================
// ?ContentsModel@idClip@@QBAXAAUtrace_t@@ABVidVec3@@PBVidClipModel@@ABVidMat3@@H213@Z
// EA  : 0x8272D380
// RVA : 0x0072D380
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::ContentsModel(
        idClip *this,
        trace_t *result,
        const idVec3 *start,
        const idClipModel *trm,
        const idMat3 *trmAxis,
        int clipMask,
        idClipModel *model,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis,
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
        int a27,
        float *a28)
{
  __int64 v34; // r20
  int num; // r9
  int v36; // r8
  int v37; // r11
  int v38; // ctr
  idTraceModel *v39; // r10
  char *v40; // r11
  int i; // ctr
  int v42; // r25
  int v43; // r26
  int *v44; // r31
  idCollisionModel *collisionModel; // r3
  double y; // fp13
  int entityNumber; // r11
  double z; // fp12
  int physicsId; // r10
  int bodyId; // r9
  int v51; // r8
  double v52; // fp10
  double v53; // fp9
  double v54; // fp3
  int contents; // r11
  int v56; // [sp+8h] [-2978h]
  const idPositionedCollisionModel *v57; // [sp+Ch] [-2974h]
  int v58; // [sp+10h] [-2970h]
  const char *v59; // [sp+14h] [-296Ch]
  int v60; // [sp+18h] [-2968h]
  int v61; // [sp+1Ch] [-2964h]
  int v62; // [sp+20h] [-2960h]
  int v63; // [sp+24h] [-295Ch]
  int v64; // [sp+28h] [-2958h]
  int v65; // [sp+2Ch] [-2954h]
  int v66; // [sp+30h] [-2950h]
  int v67; // [sp+34h] [-294Ch]
  int v68; // [sp+38h] [-2948h]
  int v69; // [sp+3Ch] [-2944h]
  int v70; // [sp+40h] [-2940h]
  int v71; // [sp+44h] [-293Ch]
  int v72; // [sp+48h] [-2938h]
  int v73; // [sp+4Ch] [-2934h]
  int v74; // [sp+50h] [-2930h]
  int v75; // [sp+58h] [-2928h]
  int v76; // [sp+60h] [-2920h]
  idCollisionModelManager v77; // [sp+70h] [-2910h] BYREF
  const idTraceModel *v78[29]; // [sp+80h] [-2900h] BYREF
  int v79; // [sp+F4h] [-288Ch] BYREF
  char v80; // [sp+F8h] [-2888h] BYREF
  _BYTE v81[40]; // [sp+100h] [-2880h] BYREF

  if ( (clipMask & model->contents) != 0 )
  {
    v34 = 0;
    if ( trm != nullptr )
    {
      num = trm->traceModels.num;
      if ( num == 0 )
        idLib::Error(
          fmt: "idClip::ContentsModel: clip model %d of entity '%d' is not a trace model\n",
          trm->bodyId,
          trm->entityNumber);
      v36 = 0;
      if ( num > 0 )
      {
        v37 = 0;
        v38 = num;
        HIDWORD(v34) = num;
        do
        {
          if ( v36 >= num )
            v39 = nullptr;
          else
            v39 = trm->clip->traceModelCache->cache.list[trm->traceModels.list[v37]]->trm;
          ++v36;
          v78[v37++] = v39;
          --v38;
        }
        while ( v38 != 0 );
      }
    }
    else
    {
      HIDWORD(v34) = 1;
      v78[0] = nullptr;
    }
    v40 = &v80;
    for ( i = 128; i != 0; --i )
    {
      v40 += 80;
      *(_QWORD *)v40 = v34;
    }
    v42 = 0;
    if ( idClipModel::GetNumCollisionModels(this: model) > 0 )
    {
      v43 = 0;
      v44 = &v79;
      do
      {
        collisionModel = model->collisionModel;
        if ( collisionModel == nullptr )
        {
          if ( v42 >= model->traceModels.num )
            collisionModel = idClipModel::NoTraceModelWarning(this: model);
          else
            collisionModel = model->clip->traceModelCache->cache.list[model->traceModels.list[v43]]->collisionModel;
        }
        v44[3] = (int)collisionModel;
        y = modelOrigin->y;
        entityNumber = model->entityNumber;
        z = modelOrigin->z;
        physicsId = model->physicsId;
        v44[5] = SLODWORD(modelOrigin->x);
        bodyId = model->bodyId;
        *((float *)v44 + 6) = y;
        v51 = model->traceModels.num;
        *((float *)v44 + 7) = z;
        v44[8] = *(int *)a28;
        v52 = a28[1];
        v53 = a28[2];
        v44[11] = *((int *)a28 + 3);
        *((float *)v44 + 9) = v52;
        *((float *)v44 + 10) = v53;
        v44[12] = *((int *)a28 + 4);
        v44[13] = *((int *)a28 + 5);
        v44[14] = *((int *)a28 + 6);
        v54 = a28[8];
        v44[15] = *((int *)a28 + 7);
        *((float *)v44 + 16) = v54;
        v44[17] = entityNumber;
        v44[18] = physicsId;
        v44[19] = bodyId;
        if ( v51 != 0 )
          contents = model->contents;
        else
          contents = 0;
        v44 += 20;
        *v44 = contents;
        ++v42;
        ++v43;
      }
      while ( v42 < idClipModel::GetNumCollisionModels(this: model) );
    }
    idCollisionModelManager::Contents(
      this: &v77,
      result: (idCollisionQuery *)collisionModelManager,
      a3: result,
      start,
      globalBounds: &bounds_zero,
      trms: v78,
      numTrms: SHIDWORD(v34),
      trmAxis,
      contentMask: v56,
      models: v57,
      numModels: v58,
      userName: v59,
      a13: v60,
      a14: v61,
      a15: v62,
      a16: v63,
      a17: v64,
      a18: v65,
      a19: v66,
      a20: v67,
      a21: v68,
      a22: v69,
      a23: v70,
      a24: v71,
      a25: v72,
      a26: v73,
      a27: v74,
      a28: clipMask,
      a29: v75,
      a30: (int)v81,
      a31: v76,
      a32: v42);
  }
  else
  {
    result->fraction = 1.0;
    result->endpos = *start;
    result->endAxis = *trmAxis;
    memset(Dst: &result->c, Val: 0, Size: sizeof(result->c));
  }
}


// ========================================================================
// ?GetGatheredClipModels@idClip@@QAAHABVidGatherQuery@@PAPAVidClipModel@@H@Z
// EA  : 0x8272D660
// RVA : 0x0072D660
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

int __fastcall idClip::GetGatheredClipModels(
        idClip *this,
        const idGatherQuery *query,
        idClipModel **clipModelList,
        int maxCount)
{
  unsigned __int64 index; // r11
  int v8; // r26
  char *v9; // r11
  int v10; // r28
  char *v11; // r29
  idClipModel **v12; // r25
  int v13; // r8
  char *v14; // r30
  idPhysics *PhysicsForId; // r3
  idPhysics *v16; // r31
  int v17; // r30
  int v18; // r3
  trace_t v19; // [sp+50h] [-D0h] BYREF

  index = query->index;
  if ( (idClipModel *)LODWORD(query->index) < *(idClipModel **)((char *)&this->temporaryClipModel
                                                              + (HIDWORD(query->index) | 0x5E0))
    && (unsigned int)index > LODWORD(this->residencyQueryLastSubmittedIndex) )
  {
    return 0;
  }
  v8 = 0;
  v9 = (char *)this + (((_DWORD)index << 6) & 0x3FC0);
  v10 = 0;
  v11 = v9 + 378272;
  if ( *((_WORD *)v9 + 189165) != 0 )
  {
    v12 = clipModelList - 1;
    do
    {
      v13 = ((*((unsigned __int16 *)v11 + 28) + v10) & 0x7FF) + 24668;
      v14 = (char *)this + 16 * v13;
      if ( *((_WORD *)v11 + 27) != 2
        || (idCollisionModelManager::GetContentsResult(
              this: collisionModelManager,
              result: &v19,
              query: (idCollisionQuery *)this + 2 * v13,
              peek: false),
            (*((_DWORD *)v11 + 12) & v19.c.contentFlags) != 0) )
      {
        PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: *((_DWORD *)v14 + 2));
        v16 = PhysicsForId;
        if ( PhysicsForId != nullptr )
        {
          v17 = *((__int16 *)v14 + 6);
          if ( v17 < PhysicsForId->GetNumClipModels(this: PhysicsForId) )
          {
            v18 = (int)v16->GetClipModel(this: v16, a2: v17);
            if ( v18 != 0 )
            {
              ++v8;
              *++v12 = (idClipModel *)v18;
              if ( v8 >= maxCount )
                break;
            }
          }
        }
      }
      ++v10;
    }
    while ( v10 < *((unsigned __int16 *)v11 + 29) );
  }
  return v8;
}


// ========================================================================
// ?ResolveCollisionQueries@idClip@@QAAXXZ
// EA  : 0x8272D7A8
// RVA : 0x0072D7A8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::ResolveCollisionQueries(idClip *this)
{
  __int64 v1; // r25
  unsigned __int64 *p_collisionQueryLastSubmittedIndex; // r27
  unsigned int v4; // r29
  idCollisionQuery *v5; // r31
  unsigned __int64 offset; // r11
  char v7; // r11
  bool v8; // zf
  trace_t v9; // [sp+50h] [-D0h] BYREF

  HIDWORD(v1) = &this->collisionQueryLastResolvedIndex;
  p_collisionQueryLastSubmittedIndex = &this->collisionQueryLastSubmittedIndex;
  v4 = LODWORD(this->collisionQueryLastResolvedIndex) + 1;
  if ( v4 <= LODWORD(this->collisionQueryLastSubmittedIndex) )
  {
    LODWORD(v1) = 0;
    do
    {
      v5 = (idCollisionQuery *)&this->collisionQueries[v4 & 0xFFF];
      if ( HIDWORD(v5[1].offset) == 0 || HIDWORD(v5->offset) == 1 )
        goto LABEL_22;
      offset = v5[2].offset;
      if ( (unsigned int)offset < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
        || (v8 = (unsigned int)offset < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v7 = 1, !v8) )
      {
        v7 = 0;
      }
      if ( v7 == 0 )
        goto LABEL_22;
      if ( (unsigned int)(HIDWORD(offset) - 2) <= 7 )
      {
        if ( HIDWORD(offset) == 3 || HIDWORD(offset) == 4 )
          goto LABEL_18;
        if ( HIDWORD(offset) != 5 )
        {
          if ( HIDWORD(offset) != 6 && (HIDWORD(offset) == 7 || HIDWORD(offset) != 8 && HIDWORD(offset) != 2) )
          {
            idCollisionModelManager::GetStepMoveContactsResult(
              this: collisionModelManager,
              result: &v9,
              contacts: nullptr,
              query: v5 + 2,
              peek: true);
            goto LABEL_21;
          }
LABEL_18:
          idCollisionModelManager::GetContentsResult(
            this: collisionModelManager,
            result: &v9,
            query: v5 + 2,
            peek: true);
          goto LABEL_21;
        }
        idCollisionModelManager::GetMotionContactsResult(
          this: collisionModelManager,
          result: &v9,
          contacts: nullptr,
          query: v5 + 2,
          peek: true);
      }
LABEL_21:
      *(idVec3 *)(HIDWORD(v5[1].offset) + 32) = v9.endpos;
      *(idMat3 *)(HIDWORD(v5[1].offset) + 44) = v9.endAxis;
      *(_QWORD *)(HIDWORD(v5[1].offset) + 168) = v1;
LABEL_22:
      ++v4;
    }
    while ( v4 <= *((_DWORD *)p_collisionQueryLastSubmittedIndex + 1) );
  }
  *(_QWORD *)HIDWORD(v1) = *p_collisionQueryLastSubmittedIndex;
  idCollisionModelManager::WaitForAllQueries(this: collisionModelManager);
}


// ========================================================================
// ?PrintStatistics@idClip@@QAAXXZ
// EA  : 0x8272D9D0
// RVA : 0x0072D9D0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::PrintStatistics(idClip *this)
{
  if ( this->world != nullptr )
    idClip::LinksPerClipSector_r(this, node: this->clipSectors.list, bounds: &this->world->bounds);
}


// ========================================================================
// ?DrawWorld@idClip@@QAAXABVidVec3@@ABVidMat3@@M_N@Z
// EA  : 0x8272D9F0
// RVA : 0x0072D9F0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::DrawWorld(
        idClip *this,
        const idVec3 *viewOrigin,
        const idMat3 *viewAxis,
        double radius,
        const bool subModels,
        char a6)
{
  double v8; // fp31
  idClipModel *world; // r3
  idTreeAnimator *animatedModel; // r11
  const idJointMat *v11; // r31
  idCollisionModel *collisionModel; // r4
  int v13; // [sp+8h] [-78h]
  int v14; // [sp+Ch] [-74h]
  int v15; // [sp+10h] [-70h]
  int v16; // [sp+14h] [-6Ch]
  int v17; // [sp+18h] [-68h]
  int v18; // [sp+1Ch] [-64h]
  int v19; // [sp+20h] [-60h]
  int v20; // [sp+24h] [-5Ch]
  int v21; // [sp+28h] [-58h]
  int v22; // [sp+2Ch] [-54h]
  int v23; // [sp+30h] [-50h]
  int v24; // [sp+34h] [-4Ch]
  int v25; // [sp+38h] [-48h]
  int v26; // [sp+3Ch] [-44h]
  int v27; // [sp+40h] [-40h]
  int v28; // [sp+44h] [-3Ch]
  int v29; // [sp+48h] [-38h]
  int v30; // [sp+4Ch] [-34h]
  int v31; // [sp+50h] [-30h]

  if ( a6 != 0 )
    v8 = 0.0;
  else
    v8 = radius;
  world = this->world;
  animatedModel = world->animatedModel;
  if ( animatedModel != nullptr )
    v11 = animatedModel->joints[1];
  else
    v11 = nullptr;
  collisionModel = world->collisionModel;
  if ( collisionModel == nullptr )
  {
    if ( world->traceModels.num <= 0 )
      collisionModel = idClipModel::NoTraceModelWarning(this: world);
    else
      collisionModel = world->clip->traceModelCache->cache.list[*world->traceModels.list]->collisionModel;
  }
  idCollisionModelManager::DrawCollisionModel(
    this: collisionModelManager,
    model: collisionModel,
    modelJoints: v11,
    modelOrigin: &vec3_origin,
    modelAxis: &mat3_identity,
    viewOrigin,
    viewAxis,
    radius: v8,
    lifeTime: (int)&si_vector_decode_cat_0[184],
    a10: v13,
    a11: v14,
    a12: v15,
    a13: v16,
    a14: v17,
    a15: v18,
    a16: v19,
    a17: v20,
    a18: v21,
    a19: v22,
    a20: v23,
    a21: v24,
    a22: v25,
    a23: v26,
    a24: v27,
    a25: v28,
    a26: v29,
    a27: v30,
    a28: v31,
    a29: 0);
}


// ========================================================================
// ?DrawSingleClipModel@idClip@@QAAXPAVidClipModel@@ABVidVec3@@ABVidMat3@@H@Z
// EA  : 0x8272DAD0
// RVA : 0x0072DAD0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::DrawSingleClipModel(
        idClip *this,
        idClipModel *clipModel,
        const idVec3 *origin,
        const idMat3 *axis,
        int lifeTime)
{
  idTreeAnimator *animatedModel; // r11
  const idJointMat *v9; // r31
  idCollisionModel *collisionModel; // r4
  int v11; // [sp+8h] [-78h]
  int v12; // [sp+Ch] [-74h]
  int v13; // [sp+10h] [-70h]
  int v14; // [sp+14h] [-6Ch]
  int v15; // [sp+18h] [-68h]
  int v16; // [sp+1Ch] [-64h]
  int v17; // [sp+20h] [-60h]
  int v18; // [sp+24h] [-5Ch]
  int v19; // [sp+28h] [-58h]
  int v20; // [sp+2Ch] [-54h]
  int v21; // [sp+30h] [-50h]
  int v22; // [sp+34h] [-4Ch]
  int v23; // [sp+38h] [-48h]
  int v24; // [sp+3Ch] [-44h]
  int v25; // [sp+40h] [-40h]
  int v26; // [sp+44h] [-3Ch]
  int v27; // [sp+48h] [-38h]
  int v28; // [sp+4Ch] [-34h]
  int v29; // [sp+50h] [-30h]

  animatedModel = clipModel->animatedModel;
  if ( animatedModel != nullptr )
    v9 = animatedModel->joints[1];
  else
    v9 = nullptr;
  if ( clipModel->collisionModel != nullptr )
  {
    collisionModel = clipModel->collisionModel;
  }
  else if ( clipModel->traceModels.num <= 0 )
  {
    collisionModel = idClipModel::NoTraceModelWarning(this: clipModel);
  }
  else
  {
    collisionModel = clipModel->clip->traceModelCache->cache.list[*clipModel->traceModels.list]->collisionModel;
  }
  idCollisionModelManager::DrawCollisionModel(
    this: collisionModelManager,
    model: collisionModel,
    modelJoints: v9,
    modelOrigin: origin,
    modelAxis: axis,
    viewOrigin: &vec3_origin,
    viewAxis: &mat3_identity,
    radius: 0.0,
    lifeTime: 0x82000000,
    a10: v11,
    a11: v12,
    a12: v13,
    a13: v14,
    a14: v15,
    a15: v16,
    a16: v17,
    a17: v18,
    a18: v19,
    a19: v20,
    a20: v21,
    a21: v22,
    a22: v23,
    a23: v24,
    a24: v25,
    a25: v26,
    a26: v27,
    a27: v28,
    a28: v29,
    a29: lifeTime);
}


// ========================================================================
// ??1idClip@@QAA@XZ
// EA  : 0x8272DC60
// RVA : 0x0072DC60
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::~idClip(idClip *this)
{
  idMem::Free(this: &mem, ptr: this->queryParms, align: ALIGN_128);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->translationTraceModelQueries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->localContentsQueries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->localTranslationQueries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->clipQueries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contactsQueries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contentsQueries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->slideMoveContactsQueries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->slideMoveQueries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stepMoveContactsQueries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stepMoveQueries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->motionContactsQueries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->motionQueries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->rotationQueries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->translationQueries);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->streamAreas);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->clipSectors);
  idBlockAlloc<clipLink_t,256,13>::Shutdown(this: &this->clipLinkAllocator);
}


// ========================================================================
// __unwind$254796
// EA  : 0x8272DD78
// RVA : 0x0072DD78
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254796()
{
  int v0; // r12

  idBlockAlloc<clipLink_t,256,13>::~idBlockAlloc<clipLink_t,256,13>(this: (idBlockAlloc<clipLink_t,256,13> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// __unwind$254797
// EA  : 0x8272DDA4
// RVA : 0x0072DDA4
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254797()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 84));
}


// ========================================================================
// __unwind$254798
// EA  : 0x8272DDD0
// RVA : 0x0072DDD0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254798()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 163968));
}


// ========================================================================
// __unwind$254799
// EA  : 0x8272DE04
// RVA : 0x0072DE04
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254799()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 163992));
}


// ========================================================================
// __unwind$254800
// EA  : 0x8272DE38
// RVA : 0x0072DE38
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254800()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 172200));
}


// ========================================================================
// __unwind$254801
// EA  : 0x8272DE6C
// RVA : 0x0072DE6C
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254801()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 180408));
}


// ========================================================================
// __unwind$254802
// EA  : 0x8272DEA0
// RVA : 0x0072DEA0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254802()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 188616));
}


// ========================================================================
// __unwind$254803
// EA  : 0x8272DED4
// RVA : 0x0072DED4
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254803()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 196824));
}


// ========================================================================
// __unwind$254804
// EA  : 0x8272DF08
// RVA : 0x0072DF08
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254804()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 205032));
}


// ========================================================================
// __unwind$254805
// EA  : 0x8272DF3C
// RVA : 0x0072DF3C
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254805()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 213240));
}


// ========================================================================
// __unwind$254806
// EA  : 0x8272DF70
// RVA : 0x0072DF70
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254806()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 221448));
}


// ========================================================================
// __unwind$254807
// EA  : 0x8272DFA4
// RVA : 0x0072DFA4
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254807()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 229656));
}


// ========================================================================
// __unwind$254808
// EA  : 0x8272DFD8
// RVA : 0x0072DFD8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254808()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 237864));
}


// ========================================================================
// __unwind$254809
// EA  : 0x8272E00C
// RVA : 0x0072E00C
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254809()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 246072));
}


// ========================================================================
// __unwind$254810
// EA  : 0x8272E040
// RVA : 0x0072E040
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254810()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 254280));
}


// ========================================================================
// __unwind$254811
// EA  : 0x8272E074
// RVA : 0x0072E074
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254811()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 262488));
}


// ========================================================================
// __unwind$254812
// EA  : 0x8272E0A8
// RVA : 0x0072E0A8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_254812()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 270696));
}


// ========================================================================
// ?ClearStreamAreas@idClip@@QAAXXZ
// EA  : 0x8272E0E0
// RVA : 0x0072E0E0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::ClearStreamAreas(idClip *this)
{
  idList<int,13> *p_streamAreas; // r31

  p_streamAreas = &this->streamAreas;
  if ( this->streamAreas.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->streamAreas);
  p_streamAreas->num = __CFADD__(-p_streamAreas->size, p_streamAreas->size ^ 0x80000000) ? 0 : p_streamAreas->size;
}


// ========================================================================
// ?GetGatheredEntities@idClip@@QAAHABVidGatherQuery@@PAHH@Z
// EA  : 0x8272E140
// RVA : 0x0072E140
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

int __fastcall idClip::GetGatheredEntities(idClip *this, const idGatherQuery *query, int *entityList, int maxCount)
{
  unsigned __int64 index; // r11
  int v9; // r30
  char *v10; // r11
  int v11; // r28
  char *v12; // r29
  int *v13; // r26
  int v14; // r8
  char *v15; // r31
  char v16; // r8
  int v17; // r10
  int *v18; // r11
  trace_t v19; // [sp+50h] [-D0h] BYREF

  index = query->index;
  if ( (idClipModel *)LODWORD(query->index) < *(idClipModel **)((char *)&this->temporaryClipModel
                                                              + (HIDWORD(query->index) | 0x5E0))
    && (unsigned int)index > LODWORD(this->residencyQueryLastSubmittedIndex) )
  {
    return 0;
  }
  v9 = 0;
  v10 = (char *)this + (((_DWORD)index << 6) & 0x3FC0);
  v11 = 0;
  v12 = v10 + 378272;
  if ( *((_WORD *)v10 + 189165) != 0 )
  {
    v13 = entityList - 1;
    do
    {
      v14 = ((*((unsigned __int16 *)v12 + 28) + v11) & 0x7FF) + 24668;
      v15 = (char *)this + 16 * v14;
      if ( *((_WORD *)v12 + 27) != 2
        || (idCollisionModelManager::GetContentsResult(
              this: collisionModelManager,
              result: &v19,
              query: (idCollisionQuery *)this + 2 * v14,
              peek: false),
            (*((_DWORD *)v12 + 12) & v19.c.contentFlags) != 0) )
      {
        v16 = 0;
        v17 = 0;
        if ( v9 > 0 )
        {
          v18 = entityList;
          while ( *v18 != *((__int16 *)v15 + 7) )
          {
            ++v17;
            ++v18;
            if ( v17 >= v9 )
              goto LABEL_14;
          }
          v16 = 1;
        }
LABEL_14:
        if ( v16 == 0 )
        {
          ++v9;
          *++v13 = *((__int16 *)v15 + 7);
          if ( v9 >= maxCount )
            break;
        }
      }
      ++v11;
    }
    while ( v11 < *((unsigned __int16 *)v12 + 29) );
  }
  return v9;
}


// ========================================================================
// ?GetModelContactFeature@idClip@@QBA_NABUcontactInfo_t@@PBVidClipModel@@AAVidFixedWinding@@@Z
// EA  : 0x8272E288
// RVA : 0x0072E288
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

int __fastcall idClip::GetModelContactFeature(
        idClip *this,
        const contactInfo_t *contact,
        idClipModel *clipModel,
        idFixedWinding *winding)
{
  idCollisionModel *collisionModel; // r3
  contactType_t type; // r11
  const idVec3 *v10; // r4
  int v11; // r7
  int v12; // r9
  idVec5 *v13; // r10
  double z; // fp5
  double y; // fp1
  double v16; // fp0
  double v17; // fp12
  double v18; // fp11
  idVec5 *v19; // r10
  double v20; // fp7
  double v21; // fp6
  idVec3 v22; // [sp+50h] [-50h] BYREF
  idVec3 v23; // [sp+60h] [-40h] BYREF
  _BYTE v24[48]; // [sp+70h] [-30h] BYREF

  winding->Clear(this: winding);
  if ( clipModel == nullptr )
    return 0;
  collisionModel = clipModel->collisionModel;
  if ( collisionModel != nullptr
    || (clipModel->traceModels.num <= 0
      ? (collisionModel = idClipModel::NoTraceModelWarning(this: clipModel))
      : (collisionModel = clipModel->clip->traceModelCache->cache.list[*clipModel->traceModels.list]->collisionModel),
        collisionModel != nullptr) )
  {
    type = contact->type;
    if ( contact->type == CONTACT_EDGE )
    {
      collisionModel->GetEdge(this: collisionModel, a2: contact->modelFeature, a3: &v23, a4: (idVec3 *)v24);
      idWinding::AddPoint(this: winding, v: &v23);
      v10 = (const idVec3 *)v24;
    }
    else
    {
      if ( type != CONTACT_MODELVERTEX )
      {
        if ( type == CONTACT_TRMVERTEX )
          collisionModel->GetPolygon(this: collisionModel, a2: contact->modelFeature, a3: winding);
        goto LABEL_15;
      }
      collisionModel->GetVertex(this: collisionModel, a2: contact->modelFeature, a3: &v22);
      v10 = &v22;
    }
    idWinding::AddPoint(this: winding, v: v10);
  }
LABEL_15:
  v11 = 0;
  if ( winding->numPoints > 0 )
  {
    v12 = 0;
    do
    {
      ++v11;
      v13 = &winding->p[v12];
      z = v13->z;
      y = clipModel->axis.mat[2].y;
      v16 = clipModel->axis.mat[2].z;
      v17 = (float)((float)(clipModel->axis.mat[0].y * v13->x) + (float)(clipModel->axis.mat[1].y * v13->y));
      v18 = (float)((float)(v13->x * clipModel->axis.mat[0].z) + (float)(v13->y * clipModel->axis.mat[1].z));
      v13->x = (float)(clipModel->axis.mat[0].x * v13->x)
             + (float)((float)(v13->z * clipModel->axis.mat[2].x) + (float)(v13->y * clipModel->axis.mat[1].x));
      v13->y = (float)((float)y * (float)z) + (float)v17;
      v13->z = (float)((float)z * (float)v16) + (float)v18;
      v19 = &winding->p[v12];
      v20 = v19->y;
      ++v12;
      v21 = v19->z;
      v19->x = v19->x + clipModel->origin.x;
      v19->y = clipModel->origin.y + (float)v20;
      v19->z = (float)v21 + clipModel->origin.z;
    }
    while ( v11 < winding->numPoints );
  }
  return 1;
}


// ========================================================================
// ?ShowCollisionPoint@idClip@@QAAXABUcontactInfo_t@@PBVidTypeInfoTools@@@Z
// EA  : 0x8272E490
// RVA : 0x0072E490
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::ShowCollisionPoint(idClip *this, const contactInfo_t *contact, const idTypeInfoTools *tools)
{
  idPhysics *PhysicsForId; // r3
  idClipModel *world; // r30
  idRenderWorld *v7; // r3
  idRenderWorld *v8; // r3
  idFixedWinding v9; // [sp+50h] [-540h] BYREF

  PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: contact->physicsId);
  if ( PhysicsForId != nullptr || contact->physicsId == 0 )
  {
    if ( contact->physicsId != 0 )
      world = PhysicsForId->GetClipModel(this: PhysicsForId, a2: contact->bodyId);
    else
      world = this->world;
    if ( world != nullptr )
    {
      v9.numPoints = 0;
      v9.__vftable = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
      v9.p = v9.data;
      v9.allocedSize = 64;
      idClip::GetModelContactFeature(this, contact, clipModel: world, winding: &v9);
      v7 = common->RW(this: common);
      v7->DebugWinding(
        this: v7,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: &v9,
        a4: &world->origin,
        a5: &world->axis,
        a6: 0,
        a7: false);
      v8 = common->RW(this: common);
      v8->DebugPoint(this: v8, a2: (const idVec4 *)&idColor::colorRed, a3: &contact->point, a4: 0, a5: false);
      idFixedWinding::~idFixedWinding(this: &v9);
    }
  }
}


// ========================================================================
// __unwind$256149_0
// EA  : 0x8272E5BC
// RVA : 0x0072E5BC
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256149_0()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 1424 + 80));
}


// ========================================================================
// ??0idClip@@QAA@XZ
// EA  : 0x8272E6C0
// RVA : 0x0072E6C0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

idClip *__fastcall idClip::idClip(idClip *this)
{
  unsigned __int64 v1; // r28
  unsigned int *v3; // r9
  int i; // ctr
  int v5; // ctr
  unsigned __int64 *p_gatherQueryFirstAllocedIndex; // r11
  int *p_touchCount; // r11
  int j; // ctr

  LODWORD(v1) = 1;
  this->world = nullptr;
  this->temporaryClipModel = nullptr;
  this->defaultClipModel = nullptr;
  this->playerMeleeClipModel = nullptr;
  this->clip8x8 = nullptr;
  this->clip8x8x8 = nullptr;
  this->clip16x16 = nullptr;
  this->clip16x16x16 = nullptr;
  this->clip24x24 = nullptr;
  this->clip32x32 = nullptr;
  this->clip8x16 = nullptr;
  this->clip48x48 = nullptr;
  this->clip96x96 = nullptr;
  this->clip24x24x96 = nullptr;
  this->clip32x32x96 = nullptr;
  this->clip48x48x96 = nullptr;
  this->clipLinkAllocator.blocks = nullptr;
  this->clipLinkAllocator.free = nullptr;
  this->clipLinkAllocator.total = 0;
  this->clipLinkAllocator.active = 0;
  this->clipLinkAllocator.allowAllocs = true;
  this->clipLinkAllocator.clearAllocs = false;
  this->clipSectors.num = 0;
  this->clipSectors.granularity = 1;
  this->clipSectors.memTag = 5;
  this->clipSectors.size = 0x1FFF;
  this->clipSectors.list = this->clipSectors.staticList;
  this->clipSectors.listStatic = 1;
  this->touchCount = 0;
  this->traceModelCache = nullptr;
  this->traceModelRecycler = nullptr;
  this->deletedClipModels = nullptr;
  this->streamAreas.list = nullptr;
  this->streamAreas.granularity = 0;
  this->streamAreas.memTag = 13;
  this->streamAreas.listStatic = 0;
  this->streamAreas.size = 0;
  this->streamAreas.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->streamAreas);
  this->numQueryParms = 0;
  this->translationQueries.size = 2048;
  this->translationQueries.num = 0;
  this->translationQueries.granularity = 1;
  this->translationQueries.list = this->translationQueries.staticList;
  this->translationQueries.memTag = 5;
  this->translationQueries.listStatic = 1;
  this->rotationQueries.size = 2048;
  this->rotationQueries.num = 0;
  this->rotationQueries.granularity = 1;
  this->rotationQueries.list = this->rotationQueries.staticList;
  this->rotationQueries.memTag = 5;
  this->rotationQueries.listStatic = 1;
  this->motionQueries.size = 2048;
  this->motionQueries.num = 0;
  this->motionQueries.granularity = 1;
  this->motionQueries.list = this->motionQueries.staticList;
  this->motionQueries.memTag = 5;
  this->motionQueries.listStatic = 1;
  this->motionContactsQueries.size = 2048;
  this->motionContactsQueries.num = 0;
  this->motionContactsQueries.granularity = 1;
  this->motionContactsQueries.list = this->motionContactsQueries.staticList;
  this->motionContactsQueries.memTag = 5;
  this->motionContactsQueries.listStatic = 1;
  this->stepMoveQueries.size = 2048;
  this->stepMoveQueries.num = 0;
  this->stepMoveQueries.granularity = 1;
  this->stepMoveQueries.list = this->stepMoveQueries.staticList;
  this->stepMoveQueries.memTag = 5;
  this->stepMoveQueries.listStatic = 1;
  this->stepMoveContactsQueries.size = 2048;
  this->stepMoveContactsQueries.num = 0;
  this->stepMoveContactsQueries.granularity = 1;
  this->stepMoveContactsQueries.list = this->stepMoveContactsQueries.staticList;
  this->stepMoveContactsQueries.memTag = 5;
  this->stepMoveContactsQueries.listStatic = 1;
  this->slideMoveQueries.size = 2048;
  this->slideMoveQueries.num = 0;
  this->slideMoveQueries.granularity = 1;
  this->slideMoveQueries.list = this->slideMoveQueries.staticList;
  this->slideMoveQueries.memTag = 5;
  this->slideMoveQueries.listStatic = 1;
  this->slideMoveContactsQueries.size = 2048;
  this->slideMoveContactsQueries.num = 0;
  this->slideMoveContactsQueries.granularity = 1;
  this->slideMoveContactsQueries.list = this->slideMoveContactsQueries.staticList;
  this->slideMoveContactsQueries.memTag = 5;
  this->slideMoveContactsQueries.listStatic = 1;
  this->contentsQueries.size = 2048;
  this->contentsQueries.num = 0;
  this->contentsQueries.granularity = 1;
  this->contentsQueries.list = this->contentsQueries.staticList;
  this->contentsQueries.memTag = 5;
  this->contentsQueries.listStatic = 1;
  this->contactsQueries.size = 2048;
  this->contactsQueries.num = 0;
  this->contactsQueries.granularity = 1;
  this->contactsQueries.list = this->contactsQueries.staticList;
  this->contactsQueries.memTag = 5;
  this->contactsQueries.listStatic = 1;
  this->clipQueries.size = 2048;
  this->clipQueries.num = 0;
  this->clipQueries.granularity = 1;
  this->clipQueries.list = this->clipQueries.staticList;
  this->clipQueries.memTag = 5;
  this->clipQueries.listStatic = 1;
  this->localTranslationQueries.size = 2048;
  this->localTranslationQueries.num = 0;
  this->localTranslationQueries.granularity = 1;
  this->localTranslationQueries.list = this->localTranslationQueries.staticList;
  this->localTranslationQueries.memTag = 5;
  this->localTranslationQueries.listStatic = 1;
  this->localContentsQueries.size = 2048;
  this->localContentsQueries.num = 0;
  this->localContentsQueries.granularity = 1;
  this->localContentsQueries.list = this->localContentsQueries.staticList;
  this->localContentsQueries.memTag = 5;
  this->localContentsQueries.listStatic = 1;
  this->translationTraceModelQueries.size = 2048;
  this->translationTraceModelQueries.num = 0;
  this->translationTraceModelQueries.granularity = 1;
  this->translationTraceModelQueries.list = this->translationTraceModelQueries.staticList;
  this->translationTraceModelQueries.memTag = 5;
  this->translationTraceModelQueries.listStatic = 1;
  v3 = &this->translationTraceModelQueries.staticList[2046];
  for ( i = 4096; i != 0; --i )
  {
    v3 += 6;
    *(_QWORD *)v3 = 0x100000000LL;
  }
  v5 = 2048;
  this->collisionQueryFirstSubmittedIndex = 0x500000001LL;
  HIDWORD(v1) = 393216;
  this->gatherQueryFirstAllocedIndex = v1;
  this->collisionQueryLastSubmittedIndex = 0x100000000LL;
  this->collisionQueryFirstAllocedIndex = v1;
  this->collisionQueryLastAllocedIndex = 0x100000000LL;
  p_gatherQueryFirstAllocedIndex = &this->gatherQueryFirstAllocedIndex;
  this->collisionQueryLastResolvedIndex = 0x100000000LL;
  this->gatherQueryFirstSubmittedIndex = v1;
  this->gatherQueryLastSubmittedIndex = 0x100000000LL;
  this->gatherQueryLastAllocedIndex = 0x100000000LL;
  do
  {
    p_gatherQueryFirstAllocedIndex += 2;
    *p_gatherQueryFirstAllocedIndex = 0x100000000LL;
    --v5;
  }
  while ( v5 != 0 );
  this->gatherResultLastSubmittedIndex = 0x100000000LL;
  this->gatherResultLastAllocedIndex = 0x100000000LL;
  this->residencyQueryLastSubmittedIndex = 0x100000000LL;
  this->residencyQueryLastAllocedIndex = 0x100000000LL;
  this->gatherResultFirstSubmittedIndex = v1;
  this->gatherResultFirstAllocedIndex = v1;
  this->residencyQueryFirstSubmittedIndex = v1;
  this->residencyQueryFirstAllocedIndex = v1;
  p_touchCount = &this->touchCount;
  for ( j = 8; j != 0; --j )
    *++p_touchCount = 0;
  this->queryParms = (idClip::idClipQueryParms *)idMem::AllocWithLocation(
                                                   this: &mem,
                                                   location: "w:\\tech5\\engine\\gamelib\\physics\\Clip.cpp(122) : TAG_COLLISION",
                                                   size: 0x40000u,
                                                   tag: TAG_COLLISION,
                                                   zeroBuffer: false,
                                                   align: ALIGN_128,
                                                   heap: HEAP_DEFAULTHEAP);
  return this;
}


// ========================================================================
// __unwind$256276
// EA  : 0x8272EB20
// RVA : 0x0072EB20
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256276()
{
  int v0; // r12

  idBlockAlloc<clipLink_t,256,13>::~idBlockAlloc<clipLink_t,256,13>(this: (idBlockAlloc<clipLink_t,256,13> *)(*(_DWORD *)(v0 - 144 + 164) + 64));
}


// ========================================================================
// __unwind$256277
// EA  : 0x8272EB4C
// RVA : 0x0072EB4C
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256277()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 84));
}


// ========================================================================
// __unwind$256278
// EA  : 0x8272EB78
// RVA : 0x0072EB78
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256278()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 163968));
}


// ========================================================================
// __unwind$256279
// EA  : 0x8272EBAC
// RVA : 0x0072EBAC
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256279()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 163992));
}


// ========================================================================
// __unwind$256280
// EA  : 0x8272EBE0
// RVA : 0x0072EBE0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256280()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 172200));
}


// ========================================================================
// __unwind$256281
// EA  : 0x8272EC14
// RVA : 0x0072EC14
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256281()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 180408));
}


// ========================================================================
// __unwind$256282
// EA  : 0x8272EC48
// RVA : 0x0072EC48
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256282()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 188616));
}


// ========================================================================
// __unwind$256283
// EA  : 0x8272EC7C
// RVA : 0x0072EC7C
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256283()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 196824));
}


// ========================================================================
// __unwind$256284
// EA  : 0x8272ECB0
// RVA : 0x0072ECB0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256284()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 205032));
}


// ========================================================================
// __unwind$256285
// EA  : 0x8272ECE4
// RVA : 0x0072ECE4
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256285()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 213240));
}


// ========================================================================
// __unwind$256286
// EA  : 0x8272ED18
// RVA : 0x0072ED18
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256286()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 221448));
}


// ========================================================================
// __unwind$256287
// EA  : 0x8272ED4C
// RVA : 0x0072ED4C
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256287()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 229656));
}


// ========================================================================
// __unwind$256288
// EA  : 0x8272ED80
// RVA : 0x0072ED80
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256288()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 237864));
}


// ========================================================================
// __unwind$256289
// EA  : 0x8272EDB4
// RVA : 0x0072EDB4
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256289()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 246072));
}


// ========================================================================
// __unwind$256290
// EA  : 0x8272EDE8
// RVA : 0x0072EDE8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256290()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 254280));
}


// ========================================================================
// __unwind$256291
// EA  : 0x8272EE1C
// RVA : 0x0072EE1C
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256291()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 262488));
}


// ========================================================================
// __unwind$256292
// EA  : 0x8272EE50
// RVA : 0x0072EE50
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_256292()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 270696));
}


// ========================================================================
// ?AddStreamArea@idClip@@QAAXH@Z
// EA  : 0x8272EE88
// RVA : 0x0072EE88
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::AddStreamArea(
        idClip *this,
        int areaNum,
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
        int a14)
{
  int v14; // r10
  idList<enum encounterGroupRole_t,5> *p_streamAreas; // r3
  int num; // r9
  int v17; // r11

  a14 = areaNum;
  v14 = 0;
  p_streamAreas = (idList<enum encounterGroupRole_t,5> *)&this->streamAreas;
  num = p_streamAreas->num;
  if ( num <= 0 )
    goto LABEL_7;
  v17 = 0;
  while ( p_streamAreas->list[v17] != areaNum )
  {
    ++v14;
    ++v17;
    if ( v14 >= num )
      goto LABEL_7;
  }
  if ( v14 < 0 )
LABEL_7:
    idList<idAnimWebBlendTree *,5>::Append(this: p_streamAreas, obj: (const encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?CreateClipSectors_r@idClip@@AAAPAUclipSector_t@@HABVidBounds@@AAVidVec3@@@Z
// EA  : 0x8272EF88
// RVA : 0x0072EF88
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

clipSector_t *__fastcall idClip::CreateClipSectors_r(
        idClip *this,
        const int depth,
        const idBounds *bounds,
        idVec3 *maxSector)
{
  clipSector_t *result; // r3
  clipSector_t *v9; // r30
  double v10; // fp0
  double v11; // fp13
  double v12; // fp12
  int v13; // r11
  int v14; // ctr
  int *v15; // r10
  _DWORD *p_z; // r11
  char *v17; // r10
  _DWORD *v18; // r11
  int i; // ctr
  double dist; // fp13
  int v21; // [sp+4Ch] [-74h] BYREF
  idBounds v22; // [sp+50h] [-70h] BYREF
  char v23; // [sp+6Ch] [-54h] BYREF
  idBounds v24[3]; // [sp+70h] [-50h] BYREF

  result = idList<clipSector_t,5>::Alloc(this: &this->clipSectors);
  v9 = result;
  if ( depth == 12
    || bounds->b[0].x >= (double)bounds->b[1].x
    || bounds->b[0].y >= (double)bounds->b[1].y
    || bounds->b[0].z >= (double)bounds->b[1].z
    || (float)((float)((float)(bounds->b[1].z - bounds->b[0].z) * (float)(bounds->b[1].y - bounds->b[0].y))
             * (float)(bounds->b[1].x - bounds->b[0].x)) < 262144.0 )
  {
    result->children[1] = nullptr;
    result->axis = -1;
    result->children[0] = nullptr;
    if ( (float)(bounds->b[1].x - bounds->b[0].x) > (double)maxSector->x )
      maxSector->x = bounds->b[1].x - bounds->b[0].x;
    if ( (float)(bounds->b[1].y - bounds->b[0].y) > (double)maxSector->y )
      maxSector->y = bounds->b[1].y - bounds->b[0].y;
    if ( (float)(bounds->b[1].z - bounds->b[0].z) > (double)maxSector->z )
      maxSector->z = bounds->b[1].z - bounds->b[0].z;
  }
  else
  {
    v10 = (float)(bounds->b[1].x - bounds->b[0].x);
    v11 = (float)(bounds->b[1].y - bounds->b[0].y);
    v12 = (float)(bounds->b[1].z - bounds->b[0].z);
    if ( v10 < v11 || v10 < v12 )
    {
      if ( v11 < v10 || (v13 = 1, v11 < v12) )
        v13 = 2;
    }
    else
    {
      v13 = 0;
    }
    result->axis = v13;
    v14 = 6;
    v15 = &v21;
    result->dist = (float)(*(&bounds->b[1].x + v13) + *(&bounds->b[0].x + v13)) * (float)0.5;
    p_z = (_DWORD *)&bounds[-1].b[1].z;
    do
    {
      *++v15 = *++p_z;
      --v14;
    }
    while ( v14 != 0 );
    v17 = &v23;
    v18 = (_DWORD *)&bounds[-1].b[1].z;
    for ( i = 6; i != 0; --i )
    {
      ++v18;
      v17 += 4;
      *(_DWORD *)v17 = *v18;
    }
    dist = result->dist;
    *(&v24[0].b[1].x + result->axis) = result->dist;
    *(&v22.b[0].x + result->axis) = dist;
    result->children[0] = idClip::CreateClipSectors_r(this, depth: depth + 1, bounds: &v22, maxSector);
    v9->children[1] = idClip::CreateClipSectors_r(this, depth: depth + 1, bounds: v24, maxSector);
    return v9;
  }
  return result;
}


// ========================================================================
// ?Init@idClip@@QAAXPAVidCollisionModel@@PAVidTraceModelCache@@PAVidTraceModelRecycler@@@Z
// EA  : 0x8272F1C0
// RVA : 0x0072F1C0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
void __fastcall idClip::Init(
        idClip *this,
        idCollisionModel *worldCM,
        idTraceModelCache *tmc,
        idTraceModelRecycler *tmr)
{
  __int64 v4; // r4
  idClip *v5; // r30
  int v6; // r5
  idCollisionModel *v7; // r28
  int v8; // r6
  int v9; // r11
  idClipModel *v10; // r3
  idClipModel *v11; // r3
  idClipModel *world; // r11
  int contents; // r10
  const char *v14; // r4
  const char *v15; // r6
  const char *v16; // r5
  double v17; // r5
  idClipModel *v18; // r3
  idClipModel *v19; // r3
  idClipModel *v20; // r3
  idClipModel *v21; // r3
  idClipModel *v22; // r3
  idClipModel *v23; // r3
  idClipModel *v24; // r3
  idClipModel *v25; // r3
  idClipModel *v26; // r3
  idClipModel *v27; // r3
  idClipModel *v28; // r3
  idClipModel *v29; // r3
  idClipModel *v30; // r3
  idClipModel *v31; // r3
  idClipModel *v32; // r3
  idClipModel *v33; // r3
  idClipModel *v34; // r3
  idClipModel *v35; // r3
  idClipModel *v36; // r3
  idClipModel *v37; // r3
  idClipModel *v38; // r3
  idClipModel *v39; // r3
  idClipModel *v40; // r3
  idClipModel *v41; // r3
  idClipModel *v42; // r3
  idClipModel *v43; // r3
  idClipModel *v44; // r3
  idClipModel *v45; // r3
  int *p_touchCount; // r11
  int i; // ctr
  idVec3 v48; // [sp+58h] [-5658h] BYREF
  idBounds v49; // [sp+70h] [-5640h] BYREF
  idBounds v50; // [sp+90h] [-5620h] BYREF
  idBounds v51; // [sp+B0h] [-5600h] BYREF
  idBounds v52; // [sp+D0h] [-55E0h] BYREF
  idBounds v53; // [sp+F0h] [-55C0h] BYREF
  idBounds v54; // [sp+110h] [-55A0h] BYREF
  idBounds v55; // [sp+130h] [-5580h] BYREF
  idBounds v56; // [sp+150h] [-5560h] BYREF
  idBounds v57; // [sp+170h] [-5540h] BYREF
  idBounds v58; // [sp+190h] [-5520h] BYREF
  idBounds v59; // [sp+1B0h] [-5500h] BYREF
  idBounds v60; // [sp+1D0h] [-54E0h] BYREF
  idBounds v61; // [sp+1F0h] [-54C0h] BYREF
  idBounds v62; // [sp+210h] [-54A0h] BYREF
  idTraceModel v63; // [sp+230h] [-5480h] BYREF
  idTraceModel v64; // [sp+830h] [-4E80h] BYREF
  idTraceModel v65; // [sp+E30h] [-4880h] BYREF
  idTraceModel v66; // [sp+1430h] [-4280h] BYREF
  idTraceModel v67; // [sp+1A30h] [-3C80h] BYREF
  idTraceModel v68; // [sp+2030h] [-3680h] BYREF
  idTraceModel v69; // [sp+2630h] [-3080h] BYREF
  idTraceModel v70; // [sp+2C30h] [-2A80h] BYREF
  idTraceModel v71; // [sp+3230h] [-2480h] BYREF
  idTraceModel v72; // [sp+3830h] [-1E80h] BYREF
  idTraceModel v73; // [sp+3E30h] [-1880h] BYREF
  idTraceModel v74; // [sp+4430h] [-1280h] BYREF
  idTraceModel v75; // [sp+4A30h] [-C80h] BYREF
  idTraceModel v76; // [sp+5030h] [-680h] BYREF

  v4 = ((__int64 (*)(void))RtlCheckStack12)();
  v5 = (idClip *)HIDWORD(v4);
  *(_DWORD *)(HIDWORD(v4) + 163956) = v6;
  v7 = (idCollisionModel *)v4;
  *(_DWORD *)(HIDWORD(v4) + 163960) = v8;
  v9 = *(_DWORD *)(HIDWORD(v4) + 92);
  HIDWORD(v4) = *(_DWORD *)(HIDWORD(v4) + 84);
  v48.x = 0.0;
  v48.y = 0.0;
  v48.z = 0.0;
  memset(Dst: (void *)HIDWORD(v4), Val: 0, Size: 20 * v9);
  v5->touchCount = -1;
  v10 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v10 != nullptr )
    v11 = idClipModel::idClipModel(this: v10);
  else
    v11 = nullptr;
  v5->world = v11;
  v11->clip = v5;
  idClipModel::LoadCollisionModel(this: v5->world, model: v7);
  v5->world->entityNumber = 8190;
  v5->world->physicsId = 0;
  v5->world->bodyId = 0;
  world = v5->world;
  contents = v5->world->contents;
  if ( (contents & 0x9400) != 0 )
  {
    v14 = &byte_8200D768;
    if ( (contents & 0x1000) != 0 )
      v15 = " CONTENTS_CORPSE";
    else
      v15 = &byte_8200D768;
    if ( (contents & 0x8000) != 0 )
      v16 = " CONTENTS_PLAYER";
    else
      v16 = &byte_8200D768;
    if ( (contents & 0x400) != 0 )
      v14 = " CONTENTS_AI";
    idLib::Error(
      fmt: "world collision model may not use CONTENTS_AI or CONTENTS_PLAYER or CONTENTS_CORPSE. (%s%s%s )",
      v14,
      v16,
      v15);
  }
  idClip::CreateClipSectors_r(this: v5, depth: 0, bounds: &world->bounds, maxSector: &v48);
  v17 = (float)(v5->world->bounds.b[1].y - v5->world->bounds.b[0].y);
  idLib::Printf(
    fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64((float)(v5->world->bounds.b[1].x - v5->world->bounds.b[0].x))),
    HIDWORD(v17),
    LODWORD(v17),
    (unsigned int)COERCE_UNSIGNED_INT64((float)(v5->world->bounds.b[1].z - v5->world->bounds.b[0].z)));
  idLib::Printf(fmt: "max clip sector is (%1.1f, %1.1f, %1.1f)\n", v48.x, v48.y, v48.z);
  v60.b[0].x = -8.0;
  v60.b[0].y = -8.0;
  v60.b[0].z = -8.0;
  v60.b[1].x = 8.0;
  v60.b[1].y = 8.0;
  v60.b[1].z = 8.0;
  idTraceModel::InitBox(this: &v65);
  idTraceModel::SetupBox(this: &v65, boxBounds: &v60);
  v18 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v18 != nullptr )
    v19 = idClipModel::idClipModel(this: v18, clip: v5, trm: &v65, numTraceModels: 1, material: nullptr);
  else
    v19 = nullptr;
  v5->defaultClipModel = v19;
  v51.b[1].z = 0.0;
  v51.b[0].x = -4.0;
  v51.b[0].y = -4.0;
  v51.b[0].z = -4.0;
  v51.b[1].x = 4.0;
  v51.b[1].y = 4.0;
  idTraceModel::InitBox(this: &v63);
  idTraceModel::SetupBox(this: &v63, boxBounds: &v51);
  v63.radius = 8.0;
  v20 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v20 != nullptr )
    v21 = idClipModel::idClipModel(this: v20, clip: v5, trm: &v63, numTraceModels: 1, material: nullptr);
  else
    v21 = nullptr;
  v5->playerMeleeClipModel = v21;
  v57.b[0].x = -4.0;
  v57.b[0].y = -4.0;
  v57.b[0].z = -4.0;
  v57.b[1].x = 4.0;
  v57.b[1].y = 4.0;
  v57.b[1].z = 4.0;
  idTraceModel::InitBox(this: &v71);
  idTraceModel::SetupBox(this: &v71, boxBounds: &v57);
  v22 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v22 != nullptr )
    v23 = idClipModel::idClipModel(this: v22, clip: v5, trm: &v71, numTraceModels: 1, material: nullptr);
  else
    v23 = nullptr;
  v5->clip8x8 = v23;
  v53.b[0].x = -4.0;
  v53.b[0].y = -4.0;
  v53.b[0].z = 0.0;
  v53.b[1].x = 4.0;
  v53.b[1].y = 4.0;
  v53.b[1].z = 4.0;
  idTraceModel::InitBox(this: &v67);
  idTraceModel::SetupBox(this: &v67, boxBounds: &v53);
  v24 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v24 != nullptr )
    v25 = idClipModel::idClipModel(this: v24, clip: v5, trm: &v67, numTraceModels: 1, material: nullptr);
  else
    v25 = nullptr;
  v5->clip8x8x8 = v25;
  v61.b[0].x = -8.0;
  v61.b[0].y = -8.0;
  v61.b[0].z = -8.0;
  v61.b[1].x = 8.0;
  v61.b[1].y = 8.0;
  v61.b[1].z = 8.0;
  idTraceModel::InitBox(this: &v75);
  idTraceModel::SetupBox(this: &v75, boxBounds: &v61);
  v26 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v26 != nullptr )
    v27 = idClipModel::idClipModel(this: v26, clip: v5, trm: &v75, numTraceModels: 1, material: nullptr);
  else
    v27 = nullptr;
  v5->clip16x16 = v27;
  v55.b[0].x = -8.0;
  v55.b[0].y = -8.0;
  v55.b[0].z = 0.0;
  v55.b[1].x = 8.0;
  v55.b[1].y = 8.0;
  v55.b[1].z = 8.0;
  idTraceModel::InitBox(this: &v69);
  idTraceModel::SetupBox(this: &v69, boxBounds: &v55);
  v28 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v28 != nullptr )
    v29 = idClipModel::idClipModel(this: v28, clip: v5, trm: &v69, numTraceModels: 1, material: nullptr);
  else
    v29 = nullptr;
  v5->clip16x16x16 = v29;
  v59.b[0].x = -12.0;
  v59.b[0].y = -12.0;
  v59.b[0].z = -12.0;
  v59.b[1].x = 12.0;
  v59.b[1].y = 12.0;
  v59.b[1].z = 12.0;
  idTraceModel::InitBox(this: &v73);
  idTraceModel::SetupBox(this: &v73, boxBounds: &v59);
  v30 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v30 != nullptr )
    v31 = idClipModel::idClipModel(this: v30, clip: v5, trm: &v73, numTraceModels: 1, material: nullptr);
  else
    v31 = nullptr;
  v5->clip24x24 = v31;
  v50.b[0].x = -16.0;
  v50.b[0].y = -16.0;
  v50.b[0].z = -16.0;
  v50.b[1].x = 16.0;
  v50.b[1].y = 16.0;
  v50.b[1].z = 16.0;
  idTraceModel::InitBox(this: &v64);
  idTraceModel::SetupBox(this: &v64, boxBounds: &v50);
  v32 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v32 != nullptr )
    v33 = idClipModel::idClipModel(this: v32, clip: v5, trm: &v64, numTraceModels: 1, material: nullptr);
  else
    v33 = nullptr;
  v5->clip32x32 = v33;
  v52.b[0].x = -4.0;
  v52.b[0].y = -4.0;
  v52.b[0].z = -8.0;
  v52.b[1].x = 4.0;
  v52.b[1].y = 4.0;
  v52.b[1].z = 8.0;
  idTraceModel::InitBox(this: &v66);
  idTraceModel::SetupBox(this: &v66, boxBounds: &v52);
  v34 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v34 != nullptr )
    v35 = idClipModel::idClipModel(this: v34, clip: v5, trm: &v66, numTraceModels: 1, material: nullptr);
  else
    v35 = nullptr;
  v5->clip8x16 = v35;
  v54.b[0].x = -24.0;
  v54.b[0].y = -24.0;
  v54.b[0].z = -24.0;
  v54.b[1].x = 24.0;
  v54.b[1].y = 24.0;
  v54.b[1].z = 24.0;
  idTraceModel::InitBox(this: &v68);
  idTraceModel::SetupBox(this: &v68, boxBounds: &v54);
  v36 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0xD8u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v36 != nullptr )
    v37 = idClipModel::idClipModel(this: v36, clip: v5, trm: &v68, numTraceModels: 1, material: nullptr);
  else
    v37 = nullptr;
  v5->clip48x48 = v37;
  v56.b[0].x = -48.0;
  v56.b[0].y = -48.0;
  v56.b[0].z = -48.0;
  v56.b[1].x = 48.0;
  v56.b[1].y = 48.0;
  v56.b[1].z = 48.0;
  idTraceModel::InitBox(this: &v70);
  idTraceModel::SetupBox(this: &v70, boxBounds: &v56);
  v38 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0xD8u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v38 != nullptr )
    v39 = idClipModel::idClipModel(this: v38, clip: v5, trm: &v70, numTraceModels: 1, material: nullptr);
  else
    v39 = nullptr;
  v5->clip96x96 = v39;
  v58.b[0].x = -12.0;
  v58.b[0].y = -12.0;
  v58.b[0].z = 0.0;
  v58.b[1].x = 12.0;
  v58.b[1].y = 12.0;
  v58.b[1].z = 96.0;
  idTraceModel::InitBox(this: &v72);
  idTraceModel::SetupBox(this: &v72, boxBounds: &v58);
  v40 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v40 != nullptr )
    v41 = idClipModel::idClipModel(this: v40, clip: v5, trm: &v72, numTraceModels: 1, material: nullptr);
  else
    v41 = nullptr;
  v5->clip24x24x96 = v41;
  v49.b[0].x = -16.0;
  v49.b[0].y = -16.0;
  v49.b[0].z = 0.0;
  v49.b[1].x = 16.0;
  v49.b[1].y = 16.0;
  v49.b[1].z = 96.0;
  idTraceModel::InitBox(this: &v74);
  idTraceModel::SetupBox(this: &v74, boxBounds: &v49);
  v42 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v42 != nullptr )
    v43 = idClipModel::idClipModel(this: v42, clip: v5, trm: &v74, numTraceModels: 1, material: nullptr);
  else
    v43 = nullptr;
  v5->clip32x32x96 = v43;
  v62.b[0].x = -24.0;
  v62.b[0].y = -24.0;
  v62.b[0].z = 0.0;
  v62.b[1].x = 24.0;
  v62.b[1].y = 24.0;
  v62.b[1].z = 96.0;
  idTraceModel::InitBox(this: &v76);
  idTraceModel::SetupBox(this: &v76, boxBounds: &v62);
  v44 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v44 != nullptr )
    v45 = idClipModel::idClipModel(this: v44, clip: v5, trm: &v76, numTraceModels: 1, material: nullptr);
  else
    v45 = nullptr;
  v5->clip48x48x96 = v45;
  p_touchCount = &v5->touchCount;
  for ( i = 8; i != 0; --i )
    *++p_touchCount = 0;
}


// ========================================================================
// $LN507
// EA  : 0x8272FB1C
// RVA : 0x0072FB1C
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _LN507()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 22192 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$257151
// EA  : 0x8272FB48
// RVA : 0x0072FB48
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_257151()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 22192 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$257152
// EA  : 0x8272FB74
// RVA : 0x0072FB74
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_257152()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 22192 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$257153
// EA  : 0x8272FBA0
// RVA : 0x0072FBA0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_257153()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 22192 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$257154
// EA  : 0x8272FBCC
// RVA : 0x0072FBCC
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_257154()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 22192 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$257155
// EA  : 0x8272FBF8
// RVA : 0x0072FBF8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_257155()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 22192 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$257156
// EA  : 0x8272FC24
// RVA : 0x0072FC24
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_257156()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 22192 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$257157
// EA  : 0x8272FC50
// RVA : 0x0072FC50
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_257157()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 22192 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$257158
// EA  : 0x8272FC7C
// RVA : 0x0072FC7C
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_257158()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 22192 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$257159
// EA  : 0x8272FCA8
// RVA : 0x0072FCA8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_257159()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 22192 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$257160
// EA  : 0x8272FCD4
// RVA : 0x0072FCD4
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall _unwind_257160(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 22192 + 80), tag: a2);
}


// ========================================================================
// __unwind$257161
// EA  : 0x8272FCFC
// RVA : 0x0072FCFC
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall _unwind_257161(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 22192 + 80), tag: a2);
}


// ========================================================================
// __unwind$257162
// EA  : 0x8272FD24
// RVA : 0x0072FD24
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_257162()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 22192 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$257163
// EA  : 0x8272FD50
// RVA : 0x0072FD50
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_257163()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 22192 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$257164
// EA  : 0x8272FD7C
// RVA : 0x0072FD7C
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_257164()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 22192 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?GetClipModelsTouchingBounds@idClip@@QBAHABVidBounds@@HPAPAVidClipModel@@H@Z
// EA  : 0x8272FDB0
// RVA : 0x0072FDB0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

const char *__fastcall idClip::GetClipModelsTouchingBounds(
        idClip *this,
        const idBounds *bounds,
        int clipMask,
        idClipModel **clipModelList,
        const char *maxCount)
{
  unsigned __int64 v9; // r6
  clipSector_t *list; // r11
  int *p_touchCount; // r28
  int v14; // r27
  const char *v15; // r29
  clipSector_t **v16; // r3
  double z; // fp12
  double y; // fp11
  double x; // fp10
  double v23; // fp9
  double v24; // fp4
  int axis; // r10
  double dist; // fp0
  clipSector_t *v27; // r10
  clipLink_t *clipLinks; // r7
  idClipModel **v29; // r8
  idClipModel *clipModel; // r10
  char v36; // cr56
  char v37; // cr57
  idPLogScope v39[2]; // [sp+50h] [-D0h] BYREF
  float v40[8]; // [sp+60h] [-C0h] BYREF
  int v41; // [sp+80h] [-A0h] BYREF

  LODWORD(v9) = "idClip::GetClipModelsTouchingBounds";
  HIDWORD(v9) = 1;
  idPLogScope::idPLogScope(this: v39, pl: &pLog, gMask: v9, label: maxCount);
  if ( bounds->b[0].x <= (double)bounds->b[1].x
    && bounds->b[0].y <= (double)bounds->b[1].y
    && bounds->b[0].z <= (double)bounds->b[1].z
    && this->clipSectors.num != 0 )
  {
    list = this->clipSectors.list;
    p_touchCount = &this->touchCount;
    v14 = 0;
    v16 = (clipSector_t **)&v41;
    _R4 = 16;
    _R5 = 24;
    _R6 = 8;
    ++this->touchCount;
    v15 = nullptr;
    z = bounds->b[0].z;
    y = bounds->b[0].y;
    x = bounds->b[1].x;
    v23 = bounds->b[0].x;
    v24 = (float)(bounds->b[1].y + (float)1.0);
    v40[5] = bounds->b[1].z + (float)1.0;
    v40[4] = v24;
    v40[3] = (float)x + (float)1.0;
    v40[2] = (float)z - (float)1.0;
    v40[1] = (float)y - (float)1.0;
    v40[0] = (float)v23 - (float)1.0;
    while ( 1 )
    {
      while ( list->axis != -1 )
      {
        axis = list->axis;
        dist = list->dist;
        if ( v40[axis] <= dist )
        {
          if ( v40[axis + 3] >= dist )
          {
            v27 = list->children[1];
            ++v14;
            list = list->children[0];
            *v16++ = v27;
          }
          else
          {
            list = list->children[1];
          }
        }
        else
        {
          list = list->children[0];
        }
      }
      clipLinks = list->clipLinks;
      if ( clipLinks != nullptr )
      {
        v29 = &clipModelList[(_DWORD)v15 - 1];
        do
        {
          clipModel = clipLinks->clipModel;
          if ( clipLinks->clipModel->enabled
            && clipModel->touchCount != *p_touchCount
            && (clipModel->contents & clipMask) != 0 )
          {
            _R11 = &clipModel->absBounds;
            __asm { vspltisw128 v63, 0 }
            _R30 = v40;
            _R23 = v40;
            _R22 = v40;
            _R21 = v40;
            __asm
            {
              lvlx128   v62, r0, r11
              lvrx128   v61, r4, r11
              lvrx128   v60, r4, r30
              vor128    v59, v94, v61
              lvlx128   v58, r0, r23
              lvrx128   v56, r5, r11
              vor128    v57, v90, v60
              lvlx128   v55, r6, r11
              lvrx128   v54, r5, r22
              vor128    v52, v87, v56
              lvlx128   v53, r6, r21
              vrlimi128 v59, v63, 1, 0
              vor128    v51, v85, v54
              vrlimi128 v57, v63, 1, 0
              vsldoi128 v50, v84, v63, 4
              vsldoi128 v49, v83, v63, 4
              vcmpgtfp128 v48, v89, v50
              vcmpgtfp128 v47, v91, v49
              vor128    v46, v79, v48
              vcmpequw128. v45, v78, v63
            }
            if ( ((unsigned __int8)(v36 << 7) | (v37 << 6) & 0x80) != 0 )
            {
              if ( (int)v15 >= (int)maxCount )
                break;
              clipModel->touchCount = *p_touchCount;
              ++v15;
              *++v29 = clipModel;
            }
          }
          clipLinks = clipLinks->nextInSector;
        }
        while ( clipLinks != nullptr );
      }
      if ( v14 == 0 )
        break;
      list = *--v16;
      --v14;
    }
    if ( (int)v15 >= (int)maxCount )
      idLib::Warning(fmt: "idClip::ClipModelsTouchingBounds: more than %d clip models", maxCount);
    idPLogScope::~idPLogScope(this: v39);
    return v15;
  }
  else
  {
    idPLogScope::~idPLogScope(this: v39);
    return nullptr;
  }
}


// ========================================================================
// __unwind$258510
// EA  : 0x8273003C
// RVA : 0x0073003C
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_258510()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 288 + 80));
}


// ========================================================================
// ?GetClipModelsTouchingLine@idClip@@QBAHABVidVec3@@0HPAPAVidClipModel@@H@Z
// EA  : 0x82730070
// RVA : 0x00730070
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

int __fastcall idClip::GetClipModelsTouchingLine(
        idClip *this,
        const idVec3 *start,
        const idVec3 *end,
        int clipMask,
        idClipModel **clipModelList,
        int maxCount)
{
  unsigned __int64 v10; // r6
  int *p_touchCount; // r29
  int touchCount; // r7
  int v21; // r3
  int v22; // r28
  int *v26; // r5
  char v35; // cr56
  char v36; // cr56
  char v37; // cr57
  char v38; // cr56
  char v39; // cr57
  BOOL v40; // r11
  int v41; // r9
  char v42; // cr56
  clipLink_t *clipLinks; // r4
  idClipModel **v44; // r8
  idClipModel *clipModel; // r10
  char v47; // cr56
  char v48; // cr57
  idPLog *pLog; // r29
  idPLog::logEntry_t *v51; // r30
  int v52; // r3
  __int64 totalTicks; // r11
  __int64 v54; // r9
  idPLogScope v56; // [sp+58h] [-2A8h] BYREF
  _DWORD v57[4]; // [sp+60h] [-2A0h] BYREF
  _DWORD v58[4]; // [sp+70h] [-290h] BYREF
  _DWORD v59[4]; // [sp+80h] [-280h] BYREF
  _DWORD v60[12]; // [sp+90h] [-270h] BYREF
  int v61; // [sp+C0h] [-240h] BYREF
  int v62; // [sp+100h] [-200h] BYREF
  int v63; // [sp+110h] [-1F0h] BYREF

  _R27 = start;
  _R26 = end;
  LODWORD(v10) = "idClip::GetClipModelsTouchingLine";
  HIDWORD(v10) = 1;
  idPLogScope::idPLogScope(this: &v56, pl: &::pLog, gMask: v10, label: (const char *)clipModelList);
  _R8 = this->clipSectors.list;
  p_touchCount = &this->touchCount;
  v58[3] = 0;
  _R4 = v58;
  memset(v58, 255, 12);
  touchCount = this->touchCount;
  v57[0] = 0;
  _R5 = &_vmx_00000000000000000000000000000000;
  this->touchCount = touchCount + 1;
  _R30 = 16;
  _R7 = &_vmx_2edbe6ff2edbe6ff2edbe6ff2edbe6ff;
  memset(&v57[1], 0, 12);
  v21 = 0;
  v22 = 0;
  v59[0] = 0x7FFFFFFF;
  __asm { lvx128    v58, r0, r5 }
  v59[1] = 0x7FFFFFFF;
  __asm { lvx128    v57, r0, r7 }
  v59[2] = 0x7FFFFFFF;
  _R6 = &v63;
  v59[3] = 0x7FFFFFFF;
  _R9 = v59;
  v60[0] = -1;
  _R7 = &v62;
  v60[5] = -1;
  v26 = &v61;
  v60[10] = -1;
  _R10 = v57;
  memset(&v60[1], 0, 16);
  _R21 = 4;
  _R25 = 24;
  memset(&v60[6], 0, 16);
  __asm { lvx128    v63, r0, r4 }
  v60[11] = 0;
  __asm { lvrx128   v62, r30, r27 }
  _R4 = 16;
  __asm { lvlx128   v61, r0, r27 }
  _R27 = &vector_float_half_0;
  __asm
  {
    lvlx128   v56, r0, r26
    vor128    v59, v93, v62
    lvrx128   v60, r30, r26
  }
  _R26 = 8;
  __asm
  {
    vor128    v55, v88, v60
    lvx128    v7, r0, r10
    lvx128    v56, r0, r9
    vand128   v11, v91, v63
    vand128   v63, v87, v63
    lvx128    v59, r0, r27
    lvx128    v62, r27, r4
  }
  while ( 1 )
  {
    while ( _R8->axis != -1 )
    {
      _R11 = 16 * _R8->axis;
      __asm { lvlx128   v54, r8, r21 }
      _R10 = v60;
      __asm
      {
        vspltw128 v53, v54, 0
        lvx128    v52, r11, r10
        vand128   v51, v11, v52
        vand128   v50, v95, v52
        vsldoi128 v49, v83, v51, 4
        vsldoi128 v48, v82, v50, 4
        vor128    v47, v83, v49
        vor128    v46, v82, v48
        vsldoi128 v45, v79, v47, 8
        vsldoi128 v44, v78, v46, 8
        vor128    v43, v79, v45
        vor128    v42, v78, v44
        vsubfp128 v61, v75, v53
        vsubfp128 v60, v74, v53
        vcmpgtfp128 v0, v90, v61
        vcmpgtfp128 v41, v90, v60
        vcmpequw128. v40, v0, v41
      }
      if ( v35 != 0 )
      {
        __asm { vcmpgtuw. v0, v0, v7 }
        _R8 = _R8->children[(unsigned __int8)((v36 << 7) | (v37 << 6) & 0x80) != 0];
      }
      else
      {
        __asm { vcmpgtfp128. v39, v92, v61 }
        v40 = (unsigned __int8)((v38 << 7) | (v39 << 6) & 0x80) != 0;
        __asm
        {
          vsubfp128 v60, v93, v60
          vor128    v0, v95, v63
        }
        v41 = 4 * (((unsigned __int8)((v38 << 7) | (v39 << 6) & 0x80) == 0) + 2);
        __asm
        {
          vand128   v38, v92, v56
          vcmpgtfp128. v37, v70, v57
        }
        *v26 = *(int *)((char *)&_R8->axis + v41);
        if ( v42 != 0 )
        {
          __asm
          {
            vrefp128  v36, v60
            vsubfp128 v12, v95, v11
            vmulfp128 v0, v92, v36
            vor128    v13, v68, v36
            vaddfp128 v10, v68, v36
            vnmsubfp  v10, v0, v10, v13
            vmulfp128 v0, v93, v10
            vmaddfp   v0, v0, v11, v12
          }
        }
        __asm
        {
          stvx128   v63, r0, r6
          stvx128   v0, r0, r7
        }
        ++v21;
        __asm { vmr128    v63, v0 }
        ++v26;
        _R7 += 8;
        _R6 += 8;
        _R8 = _R8->children[v40];
      }
    }
    clipLinks = _R8->clipLinks;
    if ( clipLinks != nullptr )
    {
      v44 = &clipModelList[v22 - 1];
      do
      {
        clipModel = clipLinks->clipModel;
        if ( clipLinks->clipModel->enabled
          && clipModel->touchCount != *p_touchCount
          && (clipModel->contents & clipMask) != 0 )
        {
          _R11 = &clipModel->absBounds;
          __asm
          {
            vsubfp128 v34, v95, v11
            vspltisw128 v35, 0
            lvlx128   v33, r0, r11
            lvrx128   v32, r30, r11
            lvrx128   v60, r25, r11
            vor128    v61, v65, v32
            lvlx128   v55, r26, r11
            vor128    v54, v87, v60
            vrlimi128 v61, v35, 1, 0
            vmulfp128 v52, v66, v59
            vsldoi128 v53, v86, v35, 4
            vaddfp128 v51, v93, v53
            vaddfp128 v50, v11, v52
            vand128   v0, v84, v62
            vpermwi128 v12, v52, 0x63 # 'c'
            vpermwi128 v49, v0, 0x63 # 'c'
            vmulfp128 v48, v83, v59
            vsubfp128 v13, v82, v48
            vsubfp128 v47, v85, v48
            vpermwi128 v46, v13, 0x63 # 'c'
            vand128   v45, v13, v62
            vmulfp128 v10, v79, v49
            vpermwi128 v9, v47, 0x63 # 'c'
            vmulfp128 v8, v84, v46
            vsubfp128 v44, v77, v0
            vmaddfp   v0, v0, v10, v9
            vnmsubfp  v10, v13, v8, v12
            vcmpgtfp128 v43, v76, v47
            vand128   v42, v10, v62
            vcmpgtfp128 v41, v74, v0
            vor128    v40, v75, v41
            vcmpequw128. v39, v72, v35
          }
          if ( ((unsigned __int8)(v47 << 7) | (v48 << 6) & 0x80) != 0 )
          {
            if ( v22 >= maxCount )
              break;
            _R11 = 16;
            clipModel->touchCount = *p_touchCount;
            *++v44 = clipModel;
            ++v22;
            __asm { lvx128    v62, r27, r11 }
          }
        }
        clipLinks = clipLinks->nextInSector;
      }
      while ( clipLinks != nullptr );
    }
    if ( v21 == 0 )
      break;
    _R7 -= 8;
    _R8 = (clipSector_t *)*--v26;
    _R6 -= 8;
    --v21;
    __asm
    {
      lvx128    v11, r0, r7
      lvx128    v63, r0, r6
    }
  }
  if ( v22 >= maxCount )
    idLib::Warning(fmt: "idClip::ClipModelsTouchingLine: more than %d clip models", maxCount);
  if ( v56.logIndex >= 0 )
  {
    pLog = v56.pLog;
    v51 = &v56.pLog->logEntries.list[v56.logIndex];
    v52 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v51->totalTicks;
    HIDWORD(totalTicks) = v51->parent;
    LODWORD(v54) = v52 - totalTicks;
    v51->totalTicks = v54;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  return v22;
}


// ========================================================================
// __unwind$258804
// EA  : 0x82730450
// RVA : 0x00730450
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_258804()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 768 + 88));
}


// ========================================================================
// ?GetEntitiesTouchingBounds@idClip@@QBAHABVidBounds@@HPAHH@Z
// EA  : 0x82730480
// RVA : 0x00730480
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
int __fastcall idClip::GetEntitiesTouchingBounds(
        idClip *this,
        const idBounds *bounds,
        int clipMask,
        int *entityList,
        int maxCount)
{
  __int64 v5; // r30
  int v6; // r5
  int v7; // r28
  _DWORD *v8; // r6
  _DWORD *v9; // r27
  unsigned __int64 v10; // r6
  const char *v11; // r7
  const char *v12; // r26
  const char *ClipModelsTouchingBounds; // r3
  int v14; // r29
  int v15; // r7
  _DWORD *v16; // r6
  idClipModel **v17; // r8
  int v18; // r10
  _DWORD *v19; // r11
  idPLog *pLog; // r28
  idPLog::logEntry_t *v22; // r30
  int v23; // r3
  __int64 totalTicks; // r11
  __int64 v25; // r9
  idPLogScope v26[2]; // [sp+50h] [-8050h] BYREF
  idClipModel *v27[8208]; // [sp+60h] [-8040h] BYREF

  v5 = ((__int64 (*)(void))RtlCheckStack12)();
  v7 = v6;
  v9 = v8;
  LODWORD(v10) = "idClip::EntitiesTouchingBounds";
  HIDWORD(v10) = 1;
  v12 = v11;
  idPLogScope::idPLogScope(this: v26, pl: &::pLog, gMask: v10, label: v11);
  if ( *(float *)v5 > (double)*(float *)(v5 + 12)
    || *(float *)(v5 + 4) > (double)*(float *)(v5 + 16)
    || *(float *)(v5 + 8) > (double)*(float *)(v5 + 20) )
  {
    idPLogScope::~idPLogScope(this: v26);
    return 0;
  }
  ClipModelsTouchingBounds = idClip::GetClipModelsTouchingBounds(
                               this: (idClip *)HIDWORD(v5),
                               bounds: (const idBounds *)v5,
                               clipMask: v7,
                               clipModelList: v27,
                               maxCount: (const char *)0x2000);
  v14 = 0;
  v15 = 0;
  if ( (int)ClipModelsTouchingBounds <= 0 )
  {
LABEL_15:
    idPLogScope::~idPLogScope(this: v26);
    return v14;
  }
  v16 = v9 - 1;
  v17 = v27;
  while ( 1 )
  {
    v18 = 0;
    if ( v14 > 0 )
    {
      v19 = v9;
      while ( *v19 != (*v17)->entityNumber )
      {
        ++v18;
        ++v19;
        if ( v18 >= v14 )
          goto LABEL_12;
      }
      if ( v18 < v14 )
        goto LABEL_14;
    }
LABEL_12:
    if ( v14 >= (int)v12 )
      break;
    ++v14;
    *++v16 = (*v17)->entityNumber;
LABEL_14:
    ++v15;
    ++v17;
    if ( v15 >= (int)ClipModelsTouchingBounds )
      goto LABEL_15;
  }
  idLib::Warning(fmt: "idClip::GetEntitiesTouchingBounds: more than %d entities", v12);
  if ( v26[0].logIndex >= 0 )
  {
    pLog = v26[0].pLog;
    v22 = &v26[0].pLog->logEntries.list[v26[0].logIndex];
    v23 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v22->totalTicks;
    HIDWORD(totalTicks) = v22->parent;
    LODWORD(v25) = v23 - totalTicks;
    v22->totalTicks = v25;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  return v14;
}


// ========================================================================
// __unwind$258998
// EA  : 0x8273060C
// RVA : 0x0073060C
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_258998()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 4086);
}


// ========================================================================
// ?GetEntitiesTouchingLine@idClip@@QBAHABVidVec3@@0HPAHH@Z
// EA  : 0x82730640
// RVA : 0x00730640
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
int __fastcall idClip::GetEntitiesTouchingLine(
        idClip *this,
        const idVec3 *start,
        const idVec3 *end,
        int clipMask,
        int *entityList,
        int maxCount)
{
  __int64 v6; // r4
  idClip *v7; // r28
  const idVec3 *v8; // r27
  const idVec3 *v9; // r5
  const idVec3 *v10; // r26
  int v11; // r6
  int v12; // r25
  unsigned __int64 v13; // r6
  const char *v14; // r7
  const char *v15; // r30
  int v16; // r8
  int v17; // r29
  int ClipModelsTouchingLine; // r3
  int v19; // r28
  int v20; // r7
  const char *v21; // r6
  idClipModel **v22; // r8
  int v23; // r10
  const char *v24; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v26; // r30
  __int64 v27; // r9
  idPLogScope v29; // [sp+50h] [-8050h] BYREF
  idClipModel *v30[8208]; // [sp+60h] [-8040h] BYREF

  v6 = ((__int64 (*)(void))RtlCheckStack12)();
  v7 = (idClip *)HIDWORD(v6);
  v8 = (const idVec3 *)v6;
  v10 = v9;
  v12 = v11;
  LODWORD(v13) = "idClip::GetEntitiesTouchingLine";
  HIDWORD(v13) = 1;
  v15 = v14;
  v17 = v16;
  idPLogScope::idPLogScope(this: &v29, pl: &::pLog, gMask: v13, label: v14);
  ClipModelsTouchingLine = idClip::GetClipModelsTouchingLine(
                             this: v7,
                             start: v8,
                             end: v10,
                             clipMask: v12,
                             clipModelList: v30,
                             maxCount: 0x2000);
  v19 = 0;
  v20 = 0;
  if ( ClipModelsTouchingLine > 0 )
  {
    v21 = v15 - 4;
    v22 = v30;
    do
    {
      v23 = 0;
      if ( v19 <= 0 )
        goto LABEL_9;
      v24 = v15;
      while ( *(_DWORD *)v24 != (*v22)->entityNumber )
      {
        ++v23;
        v24 += 4;
        if ( v23 >= v19 )
          goto LABEL_9;
      }
      if ( v23 >= v19 )
      {
LABEL_9:
        if ( v19 >= v17 )
        {
          idLib::Warning(fmt: "idClip::GetEntitiesTouchingLine: more than %d entities", v17);
          if ( v29.logIndex >= 0 )
          {
            pLog = v29.pLog;
            v26 = &v29.pLog->logEntries.list[v29.logIndex];
LABEL_14:
            LODWORD(v27) = ((unsigned __int64)Sys_GetClockTicks() >> 32) - LODWORD(v26->totalTicks);
            v26->totalTicks = v27;
            pLog->lastEntry = v26->parent;
          }
          return v19;
        }
        ++v19;
        v21 += 4;
        *(_DWORD *)v21 = (*v22)->entityNumber;
      }
      ++v20;
      ++v22;
    }
    while ( v20 < ClipModelsTouchingLine );
  }
  if ( v29.logIndex >= 0 )
  {
    pLog = v29.pLog;
    v26 = &v29.pLog->logEntries.list[v29.logIndex];
    goto LABEL_14;
  }
  return v19;
}


// ========================================================================
// __unwind$259117
// EA  : 0x827307A4
// RVA : 0x007307A4
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_259117()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 4086);
}


// ========================================================================
// ?GetPositionedModelsInternal@idClip@@ABAHABVidVec3@@0_NHHHHHPAVidPositionedCollisionModel@@H@Z
// EA  : 0x827307D8
// RVA : 0x007307D8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
int __fastcall idClip::GetPositionedModelsInternal(
        idClip *this,
        const idVec3 *v1,
        const idVec3 *v2,
        bool isLine,
        int clipMask,
        const int passEntityNumber,
        const int passOwnerNumber,
        const int physicsId,
        const int bodyMask,
        idPositionedCollisionModel *models,
        int maxModels,
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
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32)
{
  __int64 v32; // r4
  int v33; // r10
  int v34; // r15
  idClip *v35; // r29
  const idVec3 *v36; // r25
  const idVec3 *v37; // r5
  const idVec3 *v38; // r24
  char v39; // r6
  char v40; // r23
  unsigned __int64 v41; // r6
  const char *v42; // r7
  int v43; // r20
  int v44; // r8
  int v45; // r18
  int v46; // r9
  int v47; // r17
  int v48; // r26
  int v49; // r28
  int i; // r30
  idClipModel *world; // r3
  int num; // r11
  idCollisionModel *collisionModel; // r3
  idTreeAnimator *animatedModel; // r11
  idJointMat *v55; // r11
  idClipModel *v56; // r11
  float *p_axis; // r11
  double y; // fp13
  double z; // fp12
  double x; // fp11
  const char *ClipModelsTouchingLine; // r3
  idClipModel **v62; // r25
  const char *j; // r24
  idClipModel *v64; // r30
  int v65; // r27
  int v66; // r28
  int v67; // r29
  idCollisionModel *v68; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v70; // r30
  int v71; // r3
  __int64 totalTicks; // r11
  __int64 v73; // r9
  int entityNumber; // [sp+50h] [-80D0h]
  int ownerNumber; // [sp+50h] [-80D0h]
  idPLogScope v77; // [sp+58h] [-80C8h] BYREF
  idBounds v78; // [sp+60h] [-80C0h] BYREF
  idClipModel *v79[8232]; // [sp+80h] [-80A0h] BYREF

  v32 = ((__int64 (*)(void))RtlCheckStack12)();
  v34 = v33;
  v35 = (idClip *)HIDWORD(v32);
  v36 = (const idVec3 *)v32;
  v38 = v37;
  v40 = v39;
  LODWORD(v41) = "idClip::GetPositionedModelsInternal";
  HIDWORD(v41) = 1;
  v43 = (int)v42;
  v45 = v44;
  v47 = v46;
  idPLogScope::idPLogScope(this: &v77, pl: &::pLog, gMask: v41, label: v42);
  v48 = 0;
  if ( v35->world != nullptr && v45 != 8190 && (v35->world->contents & v43) != 0 )
  {
    v49 = 0;
    for ( i = a30 - 8; ; *(_QWORD *)i = 0x2807400000000LL )
    {
      world = v35->world;
      num = 1;
      if ( v35->world->collisionModel == nullptr )
        num = world->traceModels.num;
      if ( v48 >= num || v48 >= a32 )
        break;
      if ( world->collisionModel != nullptr )
      {
        collisionModel = world->collisionModel;
      }
      else if ( v48 >= world->traceModels.num )
      {
        collisionModel = idClipModel::NoTraceModelWarning(this: world);
      }
      else
      {
        collisionModel = world->clip->traceModelCache->cache.list[world->traceModels.list[v49]]->collisionModel;
      }
      *(_DWORD *)(i + 8) = collisionModel;
      animatedModel = v35->world->animatedModel;
      if ( animatedModel != nullptr )
        v55 = animatedModel->joints[1];
      else
        v55 = nullptr;
      *(_DWORD *)(i + 12) = v55;
      ++v48;
      ++v49;
      v56 = v35->world;
      *(float *)(i + 16) = v35->world->origin.x;
      *(float *)(i + 20) = v56->origin.y;
      *(float *)(i + 24) = v56->origin.z;
      p_axis = (float *)&v35->world->axis;
      *(float *)(i + 28) = *p_axis;
      *(float *)(i + 32) = p_axis[1];
      *(float *)(i + 36) = p_axis[2];
      *(float *)(i + 40) = p_axis[3];
      *(float *)(i + 44) = p_axis[4];
      *(float *)(i + 48) = p_axis[5];
      *(float *)(i + 52) = p_axis[6];
      *(float *)(i + 56) = p_axis[7];
      *(float *)(i + 60) = p_axis[8];
      *(_DWORD *)(i + 64) = 8190;
      *(_QWORD *)(i + 68) = 0;
      *(_DWORD *)(i + 76) = 0;
      i += 80;
    }
  }
  if ( v45 == 0x2000 )
  {
    idPLogScope::~idPLogScope(this: &v77);
    return v48;
  }
  if ( v40 != 0 )
  {
    ClipModelsTouchingLine = (const char *)idClip::GetClipModelsTouchingLine(
                                             this: v35,
                                             start: v36,
                                             end: v38,
                                             clipMask: v43,
                                             clipModelList: v79,
                                             maxCount: 0x2000);
  }
  else
  {
    y = v36->y;
    v78.b[0].x = v36->x;
    z = v36->z;
    v78.b[0].y = y;
    x = v38->x;
    v78.b[0].z = z;
    v78.b[1].y = v38->y;
    v78.b[1].x = x;
    v78.b[1].z = v38->z;
    ClipModelsTouchingLine = idClip::GetClipModelsTouchingBounds(
                               this: v35,
                               bounds: &v78,
                               clipMask: v43,
                               clipModelList: v79,
                               maxCount: (const char *)0x2000);
  }
  if ( (int)ClipModelsTouchingLine > 0 )
  {
    v62 = v79;
    for ( j = ClipModelsTouchingLine; j != nullptr; --j )
    {
      v64 = *v62;
      if ( ((*v62)->contents & v43) != 0 )
      {
        entityNumber = v64->entityNumber;
        if ( entityNumber != v45 && entityNumber != v47 )
        {
          ownerNumber = v64->ownerNumber;
          if ( ownerNumber == 0x1FFF )
          {
            if ( a28 == 0 || v64->physicsId != v34 || ((1 << v64->bodyId) & a28) == 0 )
            {
LABEL_35:
              v65 = 0;
              if ( idClipModel::GetNumCollisionModels(this: v64) > 0 )
              {
                v66 = 0;
                v67 = 80 * v48 + a30 - 8;
                do
                {
                  if ( v48 >= a32 )
                    break;
                  v68 = v64->collisionModel;
                  if ( v68 == nullptr )
                  {
                    if ( v65 >= v64->traceModels.num )
                      v68 = idClipModel::NoTraceModelWarning(this: v64);
                    else
                      v68 = v64->clip->traceModelCache->cache.list[v64->traceModels.list[v66]]->collisionModel;
                  }
                  *(_DWORD *)(v67 + 8) = v68;
                  *(_DWORD *)(v67 + 12) = idClipModel::GetModelJoints(this: v64);
                  *(float *)(v67 + 16) = v64->origin.x;
                  *(float *)(v67 + 20) = v64->origin.y;
                  *(float *)(v67 + 24) = v64->origin.z;
                  *(float *)(v67 + 28) = v64->axis.mat[0].x;
                  *(float *)(v67 + 32) = v64->axis.mat[0].y;
                  ++v48;
                  ++v65;
                  *(float *)(v67 + 36) = v64->axis.mat[0].z;
                  ++v66;
                  *(float *)(v67 + 40) = v64->axis.mat[1].x;
                  *(float *)(v67 + 44) = v64->axis.mat[1].y;
                  *(float *)(v67 + 48) = v64->axis.mat[1].z;
                  *(float *)(v67 + 52) = v64->axis.mat[2].x;
                  *(float *)(v67 + 56) = v64->axis.mat[2].y;
                  *(float *)(v67 + 60) = v64->axis.mat[2].z;
                  *(_DWORD *)(v67 + 64) = v64->entityNumber;
                  *(_DWORD *)(v67 + 68) = v64->physicsId;
                  *(_DWORD *)(v67 + 72) = v64->bodyId;
                  *(_DWORD *)(v67 + 76) = v64->contents;
                  v67 += 80;
                  *(_QWORD *)v67 = v64->collisionQuery.offset;
                }
                while ( v65 < idClipModel::GetNumCollisionModels(this: v64) );
              }
            }
          }
          else if ( ownerNumber != v45 && ownerNumber != v47 )
          {
            goto LABEL_35;
          }
        }
      }
      ++v62;
    }
  }
  if ( v48 >= a32 )
    idLib::Warning(fmt: "idClip::GetPositionedModelsInternal: more than %d clip models", a32);
  if ( v77.logIndex >= 0 )
  {
    pLog = v77.pLog;
    v70 = &v77.pLog->logEntries.list[v77.logIndex];
    v71 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v70->totalTicks;
    HIDWORD(totalTicks) = v70->parent;
    LODWORD(v73) = v71 - totalTicks;
    v70->totalTicks = v73;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  return v48;
}


// ========================================================================
// __unwind$259176
// EA  : 0x82730C9C
// RVA : 0x00730C9C
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_259176()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 4071);
}


// ========================================================================
// ?LocalTranslation@idClip@@QAA?AVidClipQuery@@V2@ABVidVec3@@1PBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x82730CD0
// RVA : 0x00730CD0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

idClip *__fastcall idClip::LocalTranslation(
        idClip *this,
        idClipQuery *result,
        idClipQuery *localSpace,
        const idVec3 *start,
        const idVec3 *end,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        __int16 a28,
        int a29,
        unsigned __int8 a30,
        int a31,
        int a32)
{
  unsigned __int64 v37; // r6
  idClipQuery *v41; // r27
  _DWORD *v42; // r28
  __int128 v43; // r11
  int v44; // r11
  double y; // fp7
  unsigned int v46; // r6
  encounterGroupRole_t v48[2]; // [sp+50h] [-70h] BYREF
  idPLogScope v49[13]; // [sp+58h] [-68h] BYREF

  LODWORD(v37) = "idClip::LocalTranslation";
  HIDWORD(v37) = 1;
  v41 = result + 47154;
  v42 = (_DWORD *)&result[20498].index + 1;
  idPLogScope::idPLogScope(this: v49, pl: &pLog, gMask: v37, label: (const char *)end);
  *((idClipQuery *)&v43 + 1) = result[47154];
  HIDWORD(v43) = result[20498].index;
  LODWORD(v43) = v43 + 1;
  result[47154].index = v43;
  LODWORD(v43) = (v43 & 0xFFF) + 11621;
  DWORD1(v43) = 2 * v43;
  LODWORD(v43) = &result[3 * v43];
  *(_DWORD *)v43 = DWORD2(v43);
  *(_DWORD *)(v43 + 4) = HIDWORD(v43);
  *(_DWORD *)(v43 + 8) = DWORD2(v43);
  *(_QWORD *)(v43 + 16) = *(_QWORD *)((char *)&v43 + 4);
  v48[0] = result[20498].index;
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&result[31785], obj: v48);
  if ( *v42 >= 0x800u )
    idLib::Error(fmt: "MAX_CLIP_QUERIES");
  __asm { dcbz128   r9, r8 }
  v44 = ((*v42)++ << 7) + HIDWORD(result[20498].index);
  *(float *)v44 = start->x;
  *(float *)(v44 + 4) = start->y;
  *(float *)(v44 + 8) = start->z;
  *(float *)(v44 + 12) = end->x;
  v48[0] = v44 + 68;
  *(float *)(v44 + 16) = end->y;
  *(float *)(v44 + 20) = end->z;
  *(_DWORD *)(v44 + 116) = clipModel;
  *(float *)(v44 + 56) = startAxis->mat[0].x;
  v48[0] = v44 + 12;
  y = startAxis->mat[0].y;
  v48[0] = v44 + 80;
  *(float *)(v44 + 60) = y;
  *(float *)(v44 + 64) = startAxis->mat[0].z;
  *(float *)(v44 + 68) = startAxis->mat[1].x;
  *(float *)(v44 + 72) = startAxis->mat[1].y;
  *(float *)(v44 + 76) = startAxis->mat[1].z;
  *(float *)(v44 + 80) = startAxis->mat[2].x;
  *(float *)(v44 + 84) = startAxis->mat[2].y;
  *(float *)(v44 + 88) = startAxis->mat[2].z;
  *(_WORD *)(v44 + 96) = a28;
  *(_DWORD *)(v44 + 92) = clipMask;
  *(_DWORD *)(v44 + 112) = v41->index;
  v46 = (a30 << 15) & 0x7F8000
      | result[((unsigned __int16)localSpace & 0xFFF) + 34863 + ((2 * (int)localSpace) & 0x1FFE)].index & 0xFF807FFF;
  *(_DWORD *)(v44 + 124) = a32;
  *(_WORD *)(v44 + 98) = v46;
  *(idClipQuery *)&this->world = (idClipQuery)v41->index;
  idPLogScope::~idPLogScope(this: v49);
  return this;
}


// ========================================================================
// $LN51_1
// EA  : 0x82730ED4
// RVA : 0x00730ED4
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _LN51_1()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 88));
}


// ========================================================================
// ?TranslationTraceModel@idClip@@QAA?AVidClipQuery@@PAUtrace_t@@ABVidVec3@@1PBVidClipModel@@1ABVidMat3@@HPBD@Z
// EA  : 0x82730F08
// RVA : 0x00730F08
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

idClip *__fastcall idClip::TranslationTraceModel(
        idClip *this,
        idClip *result,
        trace_t *a3,
        const idVec3 *start,
        const idVec3 *end,
        idClipModel *model,
        const idVec3 *modelOrigin,
        const idMat3 *modelAxis,
        int clipMask,
        const char *userName,
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
        int a27,
        int a28)
{
  unsigned __int64 v33; // r6
  idClipQuery *p_collisionQueryLastAllocedIndex; // r27
  int *p_numQueryParms; // r28
  __int128 v39; // r11
  int v40; // r3
  int v41; // r11
  double x; // fp0
  double z; // fp12
  double y; // fp10
  unsigned __int64 index; // r9
  __int64 v46; // r11
  int v48; // [sp+8h] [-C8h]
  const char *v49; // [sp+Ch] [-C4h]
  int v50; // [sp+10h] [-C0h]
  int v51; // [sp+14h] [-BCh]
  int v52; // [sp+18h] [-B8h]
  int v53; // [sp+1Ch] [-B4h]
  int v54; // [sp+20h] [-B0h]
  int v55; // [sp+24h] [-ACh]
  int v56; // [sp+28h] [-A8h]
  int v57; // [sp+2Ch] [-A4h]
  int v58; // [sp+30h] [-A0h]
  int v59; // [sp+34h] [-9Ch]
  int v60; // [sp+38h] [-98h]
  int v61; // [sp+3Ch] [-94h]
  int v62; // [sp+40h] [-90h]
  int v63; // [sp+44h] [-8Ch]
  int v64; // [sp+48h] [-88h]
  int v65; // [sp+4Ch] [-84h]
  int v66; // [sp+50h] [-80h]
  idVec3 *numQueryParms; // [sp+60h] [-70h] BYREF
  idPLogScope v68[13]; // [sp+68h] [-68h] BYREF

  LODWORD(v33) = "idClip::TranslationTraceModel";
  HIDWORD(v33) = 1;
  idPLogScope::idPLogScope(this: v68, pl: &pLog, gMask: v33, label: (const char *)end);
  if ( a3 != nullptr )
  {
    idClip::TranslationTraceModelInternal(
      this: result,
      result: a3,
      query: nullptr,
      start,
      end,
      model,
      modelOrigin,
      modelAxis,
      clipMask: v48,
      userName: v49,
      a11: v50,
      a12: v51,
      a13: v52,
      a14: v53,
      a15: v54,
      a16: v55,
      a17: v56,
      a18: v57,
      a19: v58,
      a20: v59,
      a21: v60,
      a22: v61,
      a23: v62,
      a24: v63,
      a25: v64,
      a26: v65,
      a27: v66,
      a28);
    LODWORD(v46) = 0;
    *(_QWORD *)&this->world = v46;
  }
  else
  {
    p_collisionQueryLastAllocedIndex = (idClipQuery *)&result->collisionQueryLastAllocedIndex;
    p_numQueryParms = &result->numQueryParms;
    *((_QWORD *)&v39 + 1) = result->collisionQueryLastAllocedIndex;
    HIDWORD(v39) = result->numQueryParms;
    LODWORD(v39) = v39 + 1;
    result->collisionQueryLastAllocedIndex = v39;
    LODWORD(v39) = (v39 & 0xFFF) + 11621;
    DWORD1(v39) = 2 * v39;
    LODWORD(v39) = (char *)result + 24 * v39;
    *(_DWORD *)v39 = DWORD2(v39);
    *(_DWORD *)(v39 + 4) = HIDWORD(v39);
    *(_DWORD *)(v39 + 8) = DWORD2(v39);
    *(_QWORD *)(v39 + 16) = *(_QWORD *)((char *)&v39 + 4);
    numQueryParms = (idVec3 *)result->numQueryParms;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&result->translationTraceModelQueries,
      obj: (const encounterGroupRole_t *)&numQueryParms);
    if ( result->numQueryParms >= 0x800u )
      idLib::Error(fmt: "MAX_CLIP_QUERIES");
    __asm { dcbz128   r9, r8 }
    v40 = *p_numQueryParms + 1;
    v41 = (int)&result->queryParms[*p_numQueryParms];
    numQueryParms = &modelAxis->mat[1];
    *p_numQueryParms = v40;
    x = start->x;
    numQueryParms = &modelAxis->mat[2];
    *(float *)v41 = x;
    *(float *)(v41 + 4) = start->y;
    z = start->z;
    numQueryParms = (idVec3 *)(v41 + 68);
    *(float *)(v41 + 8) = z;
    *(float *)(v41 + 12) = end->x;
    numQueryParms = (idVec3 *)(v41 + 24);
    y = end->y;
    numQueryParms = (idVec3 *)(v41 + 80);
    *(float *)(v41 + 16) = y;
    *(float *)(v41 + 20) = end->z;
    *(_DWORD *)(v41 + 116) = model;
    *(float *)(v41 + 24) = modelOrigin->x;
    *(float *)(v41 + 28) = modelOrigin->y;
    *(float *)(v41 + 32) = modelOrigin->z;
    *(float *)(v41 + 56) = modelAxis->mat[0].x;
    *(float *)(v41 + 60) = modelAxis->mat[0].y;
    *(float *)(v41 + 64) = modelAxis->mat[0].z;
    *(float *)(v41 + 68) = modelAxis->mat[1].x;
    *(float *)(v41 + 72) = modelAxis->mat[1].y;
    *(float *)(v41 + 76) = modelAxis->mat[1].z;
    *(float *)(v41 + 80) = modelAxis->mat[2].x;
    *(float *)(v41 + 84) = modelAxis->mat[2].y;
    *(float *)(v41 + 88) = modelAxis->mat[2].z;
    *(_DWORD *)(v41 + 92) = a28;
    index = p_collisionQueryLastAllocedIndex->index;
    *(_DWORD *)(v41 + 112) = result->collisionQueryLastAllocedIndex;
    *(_WORD *)(v41 + 98) = 0x7FFF;
    *(_DWORD *)(v41 + 124) = HIDWORD(index);
    *(idClipQuery *)&this->world = (idClipQuery)p_collisionQueryLastAllocedIndex->index;
  }
  idPLogScope::~idPLogScope(this: v68);
  return this;
}


// ========================================================================
// $LN56_1
// EA  : 0x82731148
// RVA : 0x00731148
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _LN56_1()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 104));
}


// ========================================================================
// ?LocalContents@idClip@@QAA?AVidClipQuery@@V2@ABVidVec3@@PBVidClipModel@@ABVidMat3@@HHPBD@Z
// EA  : 0x82731178
// RVA : 0x00731178
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

idClip *__fastcall idClip::LocalContents(
        idClip *this,
        idClipQuery *result,
        idClipQuery *localSpace,
        const idVec3 *start,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        __int16 passEntityNumber,
        const char *userName,
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
        int a27,
        int a28)
{
  unsigned __int64 v33; // r6
  idClipQuery *v37; // r27
  _DWORD *v38; // r28
  __int128 v39; // r11
  int v40; // r11
  double z; // fp12
  double v42; // fp9
  double x; // fp8
  unsigned __int64 v44; // r9
  int v45; // r4
  idVec3 *index; // [sp+50h] [-70h] BYREF
  idPLogScope v48[13]; // [sp+58h] [-68h] BYREF

  LODWORD(v33) = "idClip::LocalContents";
  HIDWORD(v33) = 1;
  v37 = result + 47154;
  v38 = (_DWORD *)&result[20498].index + 1;
  idPLogScope::idPLogScope(this: v48, pl: &pLog, gMask: v33, label: (const char *)clipModel);
  *((idClipQuery *)&v39 + 1) = result[47154];
  HIDWORD(v39) = result[20498].index;
  LODWORD(v39) = v39 + 1;
  result[47154].index = v39;
  LODWORD(v39) = (v39 & 0xFFF) + 11621;
  DWORD1(v39) = 2 * v39;
  LODWORD(v39) = &result[3 * v39];
  *(_DWORD *)v39 = DWORD2(v39);
  *(_DWORD *)(v39 + 4) = HIDWORD(v39);
  *(_DWORD *)(v39 + 8) = DWORD2(v39);
  *(_QWORD *)(v39 + 16) = *(_QWORD *)((char *)&v39 + 4);
  index = (idVec3 *)result[20498].index;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&result[32811],
    obj: (const encounterGroupRole_t *)&index);
  if ( *v38 >= 0x800u )
    idLib::Error(fmt: "MAX_CLIP_QUERIES");
  __asm { dcbz128   r9, r8 }
  v40 = ((*v38)++ << 7) + HIDWORD(result[20498].index);
  *(float *)v40 = start->x;
  *(float *)(v40 + 4) = start->y;
  z = start->z;
  *(_DWORD *)(v40 + 116) = clipModel;
  *(float *)(v40 + 8) = z;
  *(float *)(v40 + 56) = startAxis->mat[0].x;
  *(float *)(v40 + 60) = startAxis->mat[0].y;
  index = (idVec3 *)(v40 + 68);
  v42 = startAxis->mat[0].z;
  index = &startAxis->mat[2];
  *(float *)(v40 + 64) = v42;
  x = startAxis->mat[1].x;
  index = (idVec3 *)(v40 + 80);
  *(float *)(v40 + 68) = x;
  *(float *)(v40 + 72) = startAxis->mat[1].y;
  *(float *)(v40 + 76) = startAxis->mat[1].z;
  *(float *)(v40 + 80) = startAxis->mat[2].x;
  *(float *)(v40 + 84) = startAxis->mat[2].y;
  *(float *)(v40 + 88) = startAxis->mat[2].z;
  *(_WORD *)(v40 + 96) = passEntityNumber;
  *(_DWORD *)(v40 + 92) = clipMask;
  v44 = v37->index;
  *(_DWORD *)(v40 + 112) = result[47154].index;
  v45 = *(_DWORD *)((char *)&result[((unsigned __int16)localSpace & 0xFFF) + ((2 * (int)localSpace) & 0x1FFE)].index
                  + HIDWORD(v44));
  *(_DWORD *)(v40 + 124) = a28;
  *(_WORD *)(v40 + 98) = v45 & 0x7FFF;
  *(idClipQuery *)&this->world = (idClipQuery)v37->index;
  idPLogScope::~idPLogScope(this: v48);
  return this;
}


// ========================================================================
// $LN47_1
// EA  : 0x82731350
// RVA : 0x00731350
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _LN47_1()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 88));
}


// ========================================================================
// ?TranslationInternal@idClip@@AAAXPAUtrace_t@@PAVidClipCollisionQuery@1@ABVidVec3@@2PBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x82731658
// RVA : 0x00731658
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::TranslationInternal(
        idClip *this,
        trace_t *result,
        idClip::idClipCollisionQuery *query,
        const idVec3 *start,
        const idVec3 *end,
        idClipModel *clipModel,
        idMat3 *startAxis,
        int clipMask,
        const int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        int a28,
        int a29,
        bool a30)
{
  __int64 v30; // r28
  char *v31; // r10
  int v34; // ctr
  int v40; // r26
  int PositionedModelsInternal; // r3
  double v51; // fp8
  double v52; // fp6
  int num; // r9
  int v54; // r8
  int v55; // ctr
  int v56; // r11
  idTraceModel *trm; // r10
  int v58; // [sp+8h] [-2998h]
  const idMat3 *v59; // [sp+8h] [-2998h]
  idPositionedCollisionModel *v60; // [sp+Ch] [-2994h]
  int v61; // [sp+Ch] [-2994h]
  int v62; // [sp+10h] [-2990h]
  const idPositionedCollisionModel *v63; // [sp+10h] [-2990h]
  int v64; // [sp+14h] [-298Ch]
  int v65; // [sp+14h] [-298Ch]
  int v66; // [sp+18h] [-2988h]
  const char *v67; // [sp+18h] [-2988h]
  int v68; // [sp+1Ch] [-2984h]
  int v69; // [sp+1Ch] [-2984h]
  int v70; // [sp+20h] [-2980h]
  int v71; // [sp+20h] [-2980h]
  int v72; // [sp+24h] [-297Ch]
  int v73; // [sp+24h] [-297Ch]
  int v74; // [sp+28h] [-2978h]
  int v75; // [sp+28h] [-2978h]
  int v76; // [sp+2Ch] [-2974h]
  int v77; // [sp+2Ch] [-2974h]
  int v78; // [sp+30h] [-2970h]
  int v79; // [sp+30h] [-2970h]
  int v80; // [sp+34h] [-296Ch]
  int v81; // [sp+34h] [-296Ch]
  int v82; // [sp+38h] [-2968h]
  int v83; // [sp+38h] [-2968h]
  int v84; // [sp+3Ch] [-2964h]
  int v85; // [sp+3Ch] [-2964h]
  int v86; // [sp+40h] [-2960h]
  int v87; // [sp+40h] [-2960h]
  int v88; // [sp+44h] [-295Ch]
  int v89; // [sp+44h] [-295Ch]
  int v90; // [sp+48h] [-2958h]
  int v91; // [sp+48h] [-2958h]
  int v92; // [sp+4Ch] [-2954h]
  int v93; // [sp+4Ch] [-2954h]
  int v94; // [sp+50h] [-2950h]
  int v95; // [sp+50h] [-2950h]
  int v96; // [sp+58h] [-2948h]
  int v97; // [sp+58h] [-2948h]
  int v98; // [sp+60h] [-2940h]
  int v99; // [sp+60h] [-2940h]
  int v100; // [sp+68h] [-2938h]
  idBounds v101; // [sp+80h] [-2920h] BYREF
  idVec3 v102; // [sp+98h] [-2908h] BYREF
  idCollisionQuery v103; // [sp+A8h] [-28F8h] BYREF
  const idTraceModel *v104[30]; // [sp+B0h] [-28F0h] BYREF
  char v105; // [sp+128h] [-2878h] BYREF
  _BYTE v106[2160]; // [sp+130h] [-2870h] BYREF

  HIDWORD(v30) = clipMask;
  LODWORD(v30) = 0;
  v31 = &v105;
  v34 = 128;
  v40 = 0;
  do
  {
    v31 += 80;
    *(_QWORD *)v31 = v30;
    --v34;
  }
  while ( v34 != 0 );
  if ( clipModel != nullptr )
  {
    v51 = (float)(end->y - start->y);
    v52 = (float)(end->z - start->z);
    v102.x = end->x - start->x;
    v102.y = v51;
    v102.z = v52;
    idBounds::FromBoundsTranslation(
      this: &v101,
      bounds: &clipModel->bounds,
      boundsOrigin: start,
      boundsAxis: startAxis,
      translation: &v102);
    num = clipModel->traceModels.num;
    v54 = 0;
    v101.b[0].x = v101.b[0].x - (float)1.0;
    v101.b[0].y = v101.b[0].y - (float)1.0;
    v101.b[0].z = v101.b[0].z - (float)1.0;
    v101.b[1].x = v101.b[1].x + (float)1.0;
    v101.b[1].y = v101.b[1].y + (float)1.0;
    v101.b[1].z = v101.b[1].z + (float)1.0;
    if ( num > 0 )
    {
      v55 = num;
      v56 = 0;
      v40 = num;
      do
      {
        if ( v54 >= num )
          trm = nullptr;
        else
          trm = clipModel->clip->traceModelCache->cache.list[clipModel->traceModels.list[v56]]->trm;
        ++v54;
        v104[v56++] = trm;
        --v55;
      }
      while ( v55 != 0 );
    }
    PositionedModelsInternal = idClip::GetPositionedModelsInternal(
                                 this,
                                 v1: v101.b,
                                 v2: &v101.b[1],
                                 isLine: false,
                                 clipMask: SHIDWORD(v30),
                                 passEntityNumber: a28,
                                 passOwnerNumber: clipModel->ownerNumber,
                                 physicsId: clipModel->physicsId,
                                 bodyMask: v58,
                                 models: v60,
                                 maxModels: v62,
                                 a12: v64,
                                 a13: v66,
                                 a14: v68,
                                 a15: v70,
                                 a16: v72,
                                 a17: v74,
                                 a18: v76,
                                 a19: v78,
                                 a20: v80,
                                 a21: v82,
                                 a22: v84,
                                 a23: v86,
                                 a24: v88,
                                 a25: v90,
                                 a26: v92,
                                 a27: v94,
                                 a28: clipModel->bodyMask,
                                 a29: v96,
                                 a30: (int)v106,
                                 a31: v98,
                                 a32: 128);
  }
  else
  {
    _FP10 = (float)(end->x - start->x);
    _FP5 = (float)(end->z - start->z);
    _FP7 = (float)(end->y - start->y);
    __asm { fsel      f3, f10, f12, f13 }
    __asm { fsel      f4, f10, f13, f4 }
    __asm { fsel      f13, f5, f6, f8 }
    __asm { fsel      f1, f7, f9, f11 }
    __asm
    {
      fsel      f2, f7, f11, f2
      fsel      f12, f5, f8, f6
    }
    v101.b[0].x = (float)_FP3 - (float)1.0;
    v101.b[1].x = (float)_FP4 + (float)1.0;
    v101.b[0].z = (float)_FP13 - (float)1.0;
    v101.b[0].y = (float)_FP1 - (float)1.0;
    v101.b[1].y = (float)_FP2 + (float)1.0;
    v101.b[1].z = (float)_FP12 + (float)1.0;
    PositionedModelsInternal = idClip::GetPositionedModelsInternal(
                                 this,
                                 v1: start,
                                 v2: end,
                                 isLine: true,
                                 clipMask: SHIDWORD(v30),
                                 passEntityNumber: a28,
                                 passOwnerNumber: 0x1FFF,
                                 physicsId: -1,
                                 bodyMask: v58,
                                 models: v60,
                                 maxModels: v62,
                                 a12: v64,
                                 a13: v66,
                                 a14: v68,
                                 a15: v70,
                                 a16: v72,
                                 a17: v74,
                                 a18: v76,
                                 a19: v78,
                                 a20: v80,
                                 a21: v82,
                                 a22: v84,
                                 a23: v86,
                                 a24: v88,
                                 a25: v90,
                                 a26: v92,
                                 a27: v94,
                                 a28: 0,
                                 a29: v96,
                                 a30: (int)v106,
                                 a31: v98,
                                 a32: 128);
    v104[0] = nullptr;
    v40 = 1;
  }
  idCollisionModelManager::Translation(
    this: (idCollisionModelManager *)&v103,
    result: (idCollisionQuery *)collisionModelManager,
    a3: result,
    start,
    end,
    globalBounds: &v101,
    trms: v104,
    numTrms: v40,
    trmAxis: v59,
    contentMask: v61,
    models: v63,
    numModels: v65,
    userName: v67,
    a14: v69,
    a15: v71,
    a16: v73,
    a17: v75,
    a18: v77,
    a19: v79,
    a20: v81,
    a21: v83,
    a22: v85,
    a23: v87,
    a24: v89,
    a25: v91,
    a26: v93,
    a27: v95,
    a28: startAxis,
    a29: v97,
    a30: SHIDWORD(v30),
    a31: v99,
    a32: (int)v106,
    a33: v100,
    a34: PositionedModelsInternal);
  if ( query != nullptr )
  {
    idClip::SetupDeferredQuery(
      this,
      query,
      type: QUERY_SUBMITTED_TRANSLATION,
      clipModel,
      absBounds: &v101,
      cq: &v103,
      moveClipModel: a30);
  }
  else if ( a30 )
  {
    idClip::MoveClipModel(this, clipModel, result);
  }
}


// ========================================================================
// ?Translation@idClip@@QAA?AVidClipQuery@@PAUtrace_t@@ABVidVec3@@1PBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x82731970
// RVA : 0x00731970
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

idClip *__fastcall idClip::Translation(
        idClip *this,
        idClip *result,
        trace_t *a3,
        const idVec3 *start,
        const idVec3 *end,
        idClipModel *clipModel,
        idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        int a28,
        int a29,
        bool a30,
        int a31,
        int a32)
{
  unsigned __int64 v37; // r6
  int *p_numQueryParms; // r28
  __int128 v42; // r11
  int v43; // r11
  double x; // fp0
  __int64 v45; // r11
  int v47; // [sp+8h] [-D8h]
  bool v48; // [sp+Fh] [-D1h]
  const char *v49; // [sp+10h] [-D0h]
  int v50; // [sp+14h] [-CCh]
  int v51; // [sp+18h] [-C8h]
  int v52; // [sp+1Ch] [-C4h]
  int v53; // [sp+20h] [-C0h]
  int v54; // [sp+24h] [-BCh]
  int v55; // [sp+28h] [-B8h]
  int v56; // [sp+2Ch] [-B4h]
  int v57; // [sp+30h] [-B0h]
  int v58; // [sp+34h] [-ACh]
  int v59; // [sp+38h] [-A8h]
  int v60; // [sp+3Ch] [-A4h]
  int v61; // [sp+40h] [-A0h]
  int v62; // [sp+44h] [-9Ch]
  int v63; // [sp+48h] [-98h]
  int v64; // [sp+4Ch] [-94h]
  int v65; // [sp+50h] [-90h]
  int v66; // [sp+58h] [-88h]
  idVec3 *numQueryParms; // [sp+70h] [-70h] BYREF
  idPLogScope v68[13]; // [sp+78h] [-68h] BYREF

  LODWORD(v37) = "idClip::Translation";
  HIDWORD(v37) = 1;
  idPLogScope::idPLogScope(this: v68, pl: &pLog, gMask: v37, label: (const char *)end);
  if ( a3 != nullptr )
  {
    idClip::TranslationInternal(
      this: result,
      result: a3,
      query: nullptr,
      start,
      end,
      clipModel,
      startAxis,
      clipMask,
      passEntityNumber: v47,
      moveClipModel: v48,
      userName: v49,
      a12: v50,
      a13: v51,
      a14: v52,
      a15: v53,
      a16: v54,
      a17: v55,
      a18: v56,
      a19: v57,
      a20: v58,
      a21: v59,
      a22: v60,
      a23: v61,
      a24: v62,
      a25: v63,
      a26: v64,
      a27: v65,
      a28,
      a29: v66,
      a30);
    LODWORD(v45) = 0;
    *(_QWORD *)&this->world = v45;
  }
  else
  {
    p_numQueryParms = &result->numQueryParms;
    *((_QWORD *)&v42 + 1) = result->collisionQueryLastAllocedIndex;
    HIDWORD(v42) = result->numQueryParms;
    LODWORD(v42) = v42 + 1;
    result->collisionQueryLastAllocedIndex = v42;
    LODWORD(v42) = (v42 & 0xFFF) + 11621;
    DWORD1(v42) = 2 * v42;
    LODWORD(v42) = (char *)result + 24 * v42;
    *(_DWORD *)v42 = DWORD2(v42);
    *(_DWORD *)(v42 + 4) = HIDWORD(v42);
    *(_DWORD *)(v42 + 8) = DWORD2(v42);
    *(_QWORD *)(v42 + 16) = *(_QWORD *)((char *)&v42 + 4);
    numQueryParms = (idVec3 *)result->numQueryParms;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&result->translationQueries,
      obj: (const encounterGroupRole_t *)&numQueryParms);
    if ( result->numQueryParms >= 0x800u )
      idLib::Error(fmt: "MAX_CLIP_QUERIES");
    __asm { dcbz128   r9, r8 }
    v43 = (int)&result->queryParms[(*p_numQueryParms)++];
    x = start->x;
    numQueryParms = &startAxis->mat[1];
    *(float *)v43 = x;
    *(float *)(v43 + 4) = start->y;
    *(float *)(v43 + 8) = start->z;
    *(float *)(v43 + 12) = end->x;
    numQueryParms = &startAxis->mat[2];
    *(float *)(v43 + 16) = end->y;
    numQueryParms = (idVec3 *)(v43 + 80);
    *(float *)(v43 + 20) = end->z;
    *(_DWORD *)(v43 + 116) = clipModel;
    *(float *)(v43 + 56) = startAxis->mat[0].x;
    *(float *)(v43 + 60) = startAxis->mat[0].y;
    *(float *)(v43 + 64) = startAxis->mat[0].z;
    *(float *)(v43 + 68) = startAxis->mat[1].x;
    *(float *)(v43 + 72) = startAxis->mat[1].y;
    *(float *)(v43 + 76) = startAxis->mat[1].z;
    *(float *)(v43 + 80) = startAxis->mat[2].x;
    *(float *)(v43 + 84) = startAxis->mat[2].y;
    *(float *)(v43 + 88) = startAxis->mat[2].z;
    *(_WORD *)(v43 + 96) = a28;
    *(_DWORD *)(v43 + 92) = clipMask;
    *(_DWORD *)(v43 + 112) = result->collisionQueryLastAllocedIndex;
    *(_WORD *)(v43 + 98) = (a30 << 15) | 0x7FFF;
    *(_DWORD *)(v43 + 124) = a32;
    *(_QWORD *)&this->world = result->collisionQueryLastAllocedIndex;
  }
  idPLogScope::~idPLogScope(this: v68);
  return this;
}


// ========================================================================
// $LN54
// EA  : 0x82731BA8
// RVA : 0x00731BA8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _LN54()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 120));
}


// ========================================================================
// ?LocalTranslationInternal@idClip@@AAAXHPAVidClipCollisionQuery@1@ABVidVec3@@1PBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x82731BD0
// RVA : 0x00731BD0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::LocalTranslationInternal(
        idClip *this,
        int parmIndex,
        idClip::idClipCollisionQuery *query,
        const idVec3 *start,
        const idVec3 *end,
        idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        int a28,
        int a29,
        bool a30)
{
  idClip::idClipQueryParms *v33; // r30
  int ownerNumber; // r26
  int v38; // r19
  int physicsId; // r25
  int bodyMask; // r24
  __int64 v41; // r21
  double v51; // fp8
  double v52; // fp6
  int num; // r9
  int v54; // r8
  int v55; // ctr
  int v56; // r11
  idTraceModel *trm; // r10
  char *v58; // r11
  int i; // ctr
  double y; // fp11
  double v61; // fp10
  double v62; // fp29
  double v63; // fp28
  double z; // fp8
  double v65; // fp6
  double v66; // fp27
  double v67; // fp26
  double x; // fp3
  double v69; // fp2
  double v70; // fp1
  double v71; // fp31
  double v72; // fp23
  double v77; // fp24
  double v78; // fp12
  double v79; // fp24
  double v80; // fp12
  double v81; // fp24
  double v82; // fp12
  double v83; // fp24
  double v84; // fp12
  double v85; // fp9
  double v86; // fp5
  double v87; // fp13
  double v88; // fp9
  double v89; // fp5
  double v90; // fp3
  int v91; // [sp+8h] [-2A58h]
  const idMat3 *v92; // [sp+8h] [-2A58h]
  idPositionedCollisionModel *v93; // [sp+Ch] [-2A54h]
  int v94; // [sp+Ch] [-2A54h]
  int v95; // [sp+10h] [-2A50h]
  const idPositionedCollisionModel *v96; // [sp+10h] [-2A50h]
  int v97; // [sp+14h] [-2A4Ch]
  int v98; // [sp+14h] [-2A4Ch]
  int v99; // [sp+18h] [-2A48h]
  const char *v100; // [sp+18h] [-2A48h]
  int v101; // [sp+1Ch] [-2A44h]
  int v102; // [sp+20h] [-2A40h]
  int v103; // [sp+24h] [-2A3Ch]
  int v104; // [sp+28h] [-2A38h]
  int v105; // [sp+2Ch] [-2A34h]
  int v106; // [sp+30h] [-2A30h]
  int v107; // [sp+34h] [-2A2Ch]
  int v108; // [sp+38h] [-2A28h]
  int v109; // [sp+3Ch] [-2A24h]
  int v110; // [sp+40h] [-2A20h]
  int v111; // [sp+44h] [-2A1Ch]
  int v112; // [sp+48h] [-2A18h]
  int v113; // [sp+4Ch] [-2A14h]
  int v114; // [sp+50h] [-2A10h]
  int v115; // [sp+58h] [-2A08h]
  int v116; // [sp+60h] [-2A00h]
  idBounds v117; // [sp+80h] [-29E0h] BYREF
  idBounds v118; // [sp+A0h] [-29C0h] BYREF
  idVec3 v119; // [sp+B8h] [-29A8h] BYREF
  idVec3 v120; // [sp+C8h] [-2998h] BYREF
  idVec3 v121; // [sp+D8h] [-2988h] BYREF
  idCollisionQuery v122; // [sp+E8h] [-2978h] BYREF
  const idTraceModel *v123[30]; // [sp+F0h] [-2970h] BYREF
  char v124; // [sp+168h] [-28F8h] BYREF
  _BYTE v125[2288]; // [sp+170h] [-28F0h] BYREF

  LODWORD(v41) = 0;
  v33 = &this->queryParms[parmIndex];
  ownerNumber = 0x1FFF;
  v38 = 0;
  physicsId = -1;
  bodyMask = 0;
  HIDWORD(v41) = &this->collisionQueries[v33->queryIndex & 0xFFF];
  if ( clipModel != nullptr )
  {
    v51 = (float)(end->y - start->y);
    v52 = (float)(end->z - start->z);
    v121.x = end->x - start->x;
    v121.y = v51;
    v121.z = v52;
    idBounds::FromBoundsTranslation(
      this: &v117,
      bounds: &clipModel->bounds,
      boundsOrigin: start,
      boundsAxis: startAxis,
      translation: &v121);
    num = clipModel->traceModels.num;
    v54 = 0;
    if ( num > 0 )
    {
      v55 = clipModel->traceModels.num;
      v56 = 0;
      v38 = v55;
      do
      {
        if ( v54 >= num )
          trm = nullptr;
        else
          trm = clipModel->clip->traceModelCache->cache.list[clipModel->traceModels.list[v56]]->trm;
        ++v54;
        v123[v56++] = trm;
        --v55;
      }
      while ( v55 != 0 );
    }
    ownerNumber = clipModel->ownerNumber;
    physicsId = clipModel->physicsId;
    bodyMask = clipModel->bodyMask;
  }
  else
  {
    v38 = 1;
    _FP11 = (float)(end->y - start->y);
    _FP8 = (float)(end->z - start->z);
    _FP6 = (float)(end->x - start->x);
    v123[0] = nullptr;
    __asm { fsel      f2, f11, f13, f0 }
    v117.b[0].y = _FP2;
    __asm { fsel      f3, f11, f0, f3 }
    v117.b[1].y = _FP3;
    __asm { fsel      f0, f8, f10, f12 }
    v117.b[0].z = _FP0;
    __asm { fsel      f13, f8, f12, f10 }
    v117.b[1].z = _FP13;
    __asm { fsel      f12, f6, f9, f7 }
    v117.b[1].x = _FP12;
    __asm { fsel      f11, f6, f7, f9 }
    v117.b[0].x = _FP11;
  }
  v58 = &v124;
  for ( i = 128; i != 0; --i )
  {
    v58 += 80;
    *(_QWORD *)v58 = v41;
  }
  if ( clipModel != nullptr )
    goto LABEL_15;
  y = end->y;
  v61 = start->y;
  v62 = (float)(end->y - start->y);
  v63 = (float)(v33->end.y - v33->start.y);
  z = end->z;
  v65 = start->z;
  v66 = (float)(end->z - start->z);
  v67 = (float)(v33->end.z - v33->start.z);
  x = end->x;
  v69 = start->x;
  v70 = v33->end.x;
  v71 = v33->start.x;
  v72 = (float)(v33->end.x - v33->start.x);
  _FP21 = (float)((float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
                        + (float)((float)((float)v66 * (float)v66) + (float)((float)v62 * (float)v62)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  _FP19 = (float)((float)((float)((float)v72 * (float)v72)
                        + (float)((float)((float)v67 * (float)v67) + (float)((float)v63 * (float)v63)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm
  {
    fsel      f24, f21, f24, f12
    fsel      f12, f19, f22, f12
  }
  v77 = __frsqrte(_FP24);
  v78 = __frsqrte(_FP12);
  v79 = (float)((float)-(float)((float)((float)((float)v77
                                              * (float)((float)((float)((float)(end->x - start->x)
                                                                      * (float)(end->x - start->x))
                                                              + (float)((float)((float)v66 * (float)v66)
                                                                      + (float)((float)v62 * (float)v62)))
                                                      * (float)0.5))
                                      * (float)v77)
                              - (float)1.5)
              * (float)v77);
  v80 = (float)((float)-(float)((float)((float)((float)v78
                                              * (float)((float)((float)((float)v72 * (float)v72)
                                                              + (float)((float)((float)v67 * (float)v67)
                                                                      + (float)((float)v63 * (float)v63)))
                                                      * (float)0.5))
                                      * (float)v78)
                              - (float)1.5)
              * (float)v78);
  v81 = (float)((float)-(float)((float)((float)((float)v79
                                              * (float)((float)((float)((float)(end->x - start->x)
                                                                      * (float)(end->x - start->x))
                                                              + (float)((float)((float)v66 * (float)v66)
                                                                      + (float)((float)v62 * (float)v62)))
                                                      * (float)0.5))
                                      * (float)v79)
                              - (float)1.5)
              * (float)v79);
  v82 = (float)((float)-(float)((float)((float)((float)v80
                                              * (float)((float)((float)((float)v72 * (float)v72)
                                                              + (float)((float)((float)v67 * (float)v67)
                                                                      + (float)((float)v63 * (float)v63)))
                                                      * (float)0.5))
                                      * (float)v80)
                              - (float)1.5)
              * (float)v80);
  v83 = (float)((float)-(float)((float)((float)((float)v81
                                              * (float)((float)((float)((float)(end->x - start->x)
                                                                      * (float)(end->x - start->x))
                                                              + (float)((float)((float)v66 * (float)v66)
                                                                      + (float)((float)v62 * (float)v62)))
                                                      * (float)0.5))
                                      * (float)v81)
                              - (float)1.5)
              * (float)v81);
  v84 = (float)((float)-(float)((float)((float)((float)v82
                                              * (float)((float)((float)((float)v72 * (float)v72)
                                                              + (float)((float)((float)v67 * (float)v67)
                                                                      + (float)((float)v63 * (float)v63)))
                                                      * (float)0.5))
                                      * (float)v82)
                              - (float)1.5)
              * (float)v82);
  if ( (float)((float)((float)((float)(end->y - start->y) * (float)v83)
                     * (float)((float)(v33->end.y - v33->start.y) * (float)v84))
             + (float)((float)((float)((float)(end->z - start->z) * (float)v83)
                             * (float)((float)(v33->end.z - v33->start.z) * (float)v84))
                     + (float)((float)((float)v84 * (float)(v33->end.x - v33->start.x))
                             * (float)((float)(end->x - start->x) * (float)v83)))) <= 0.99989998 )
  {
LABEL_15:
    idClip::TraceBoundsFromLocalSpaceBounds(
      this,
      traceBounds: &v118,
      localBounds: &v117,
      type: *(idClip::idClipCollisionQuery::type_t *)HIDWORD(v41),
      parms: v33);
    idClip::GetPositionedModelsInternal(
      this,
      v1: v118.b,
      v2: &v118.b[1],
      isLine: false,
      clipMask,
      passEntityNumber: a28,
      passOwnerNumber: ownerNumber,
      physicsId,
      bodyMask: v91,
      models: v93,
      maxModels: v95,
      a12: v97,
      a13: v99,
      a14: v101,
      a15: v102,
      a16: v103,
      a17: v104,
      a18: v105,
      a19: v106,
      a20: v107,
      a21: v108,
      a22: v109,
      a23: v110,
      a24: v111,
      a25: v112,
      a26: v113,
      a27: v114,
      a28: bodyMask,
      a29: v115,
      a30: (int)v125,
      a31: v116,
      a32: 128);
  }
  else
  {
    v85 = (float)((float)(v33->end.y + v33->start.y) * (float)0.5);
    v86 = (float)((float)(v33->end.z + v33->start.z) * (float)0.5);
    v118.b[1].y = v117.b[1].y + (float)((float)(v33->end.y + v33->start.y) * (float)0.5);
    v118.b[1].x = v117.b[1].x + (float)((float)((float)v70 + (float)v71) * (float)0.5);
    v118.b[1].z = v117.b[1].z + (float)v86;
    v118.b[0].x = v117.b[0].x + (float)((float)((float)v70 + (float)v71) * (float)0.5);
    v118.b[0].y = v117.b[0].y + (float)v85;
    v118.b[0].z = v117.b[0].z + (float)v86;
    v87 = v33->start.z;
    v88 = v33->start.y;
    v89 = (float)((float)x + v33->start.x);
    v90 = (float)((float)v69 + v33->start.x);
    v120.y = (float)y + v33->start.y;
    v120.x = v89;
    v120.z = (float)z + (float)v87;
    v119.x = v90;
    v119.y = (float)v61 + (float)v88;
    v119.z = (float)v65 + (float)v87;
    idClip::GetPositionedModelsInternal(
      this,
      v1: &v119,
      v2: &v120,
      isLine: true,
      clipMask,
      passEntityNumber: a28,
      passOwnerNumber: 0x1FFF,
      physicsId: -1,
      bodyMask: v91,
      models: v93,
      maxModels: v95,
      a12: v97,
      a13: v99,
      a14: v101,
      a15: v102,
      a16: v103,
      a17: v104,
      a18: v105,
      a19: v106,
      a20: v107,
      a21: v108,
      a22: v109,
      a23: v110,
      a24: v111,
      a25: v112,
      a26: v113,
      a27: v114,
      a28: 0,
      a29: v115,
      a30: (int)v125,
      a31: v116,
      a32: 128);
  }
  idCollisionModelManager::LocalTranslation(
    this: (idCollisionModelManager *)&v122,
    result: (idCollisionQuery *)collisionModelManager,
    localSpace: *(idCollisionQuery **)(HIDWORD(v41) + 20),
    start,
    end,
    globalBounds: &v118,
    trms: v123,
    numTrms: v38,
    trmAxis: v92,
    contentMask: v94,
    models: v96,
    numModels: v98,
    userName: v100);
  if ( query != nullptr )
    idClip::SetupDeferredQuery(
      this,
      query,
      type: QUERY_SUBMITTED_TRANSLATION,
      clipModel,
      absBounds: &v118,
      cq: &v122,
      moveClipModel: a30);
}


// ========================================================================
// ?RotationInternal@idClip@@AAAXPAUtrace_t@@PAVidClipCollisionQuery@1@ABVidVec3@@ABVidRotation@@PBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x82732060
// RVA : 0x00732060
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::RotationInternal(
        idClip *this,
        trace_t *result,
        idClip::idClipCollisionQuery *query,
        const idMat3 *start,
        idRotation *rotation,
        idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        const int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        int a28,
        int a29,
        bool a30)
{
  __int64 v37; // r26
  int v38; // r28
  int ownerNumber; // r9
  int physicsId; // r10
  int bodyMask; // r4
  int num; // r7
  int v43; // r6
  int v44; // ctr
  int v45; // r11
  idTraceModel *trm; // r8
  char *v47; // r11
  int i; // ctr
  int PositionedModelsInternal; // r3
  int v50; // [sp+8h] [-2978h]
  const idMat3 *v51; // [sp+8h] [-2978h]
  idPositionedCollisionModel *v52; // [sp+Ch] [-2974h]
  int v53; // [sp+Ch] [-2974h]
  int v54; // [sp+10h] [-2970h]
  const idPositionedCollisionModel *v55; // [sp+10h] [-2970h]
  int v56; // [sp+14h] [-296Ch]
  int v57; // [sp+14h] [-296Ch]
  int v58; // [sp+18h] [-2968h]
  const char *v59; // [sp+18h] [-2968h]
  int v60; // [sp+1Ch] [-2964h]
  int v61; // [sp+1Ch] [-2964h]
  int v62; // [sp+20h] [-2960h]
  int v63; // [sp+20h] [-2960h]
  int v64; // [sp+24h] [-295Ch]
  int v65; // [sp+24h] [-295Ch]
  int v66; // [sp+28h] [-2958h]
  int v67; // [sp+28h] [-2958h]
  int v68; // [sp+2Ch] [-2954h]
  int v69; // [sp+2Ch] [-2954h]
  int v70; // [sp+30h] [-2950h]
  int v71; // [sp+30h] [-2950h]
  int v72; // [sp+34h] [-294Ch]
  int v73; // [sp+34h] [-294Ch]
  int v74; // [sp+38h] [-2948h]
  int v75; // [sp+38h] [-2948h]
  int v76; // [sp+3Ch] [-2944h]
  int v77; // [sp+3Ch] [-2944h]
  int v78; // [sp+40h] [-2940h]
  int v79; // [sp+40h] [-2940h]
  int v80; // [sp+44h] [-293Ch]
  int v81; // [sp+44h] [-293Ch]
  int v82; // [sp+48h] [-2938h]
  int v83; // [sp+48h] [-2938h]
  int v84; // [sp+4Ch] [-2934h]
  int v85; // [sp+4Ch] [-2934h]
  int v86; // [sp+50h] [-2930h]
  int v87; // [sp+50h] [-2930h]
  int v88; // [sp+58h] [-2928h]
  int v89; // [sp+58h] [-2928h]
  int v90; // [sp+60h] [-2920h]
  int v91; // [sp+60h] [-2920h]
  int v92; // [sp+68h] [-2918h]
  idBounds v93; // [sp+80h] [-2900h] BYREF
  idCollisionQuery v94; // [sp+98h] [-28E8h] BYREF
  const idMat3 *v95[30]; // [sp+A0h] [-28E0h] BYREF
  char v96; // [sp+118h] [-2868h] BYREF
  _BYTE v97[2144]; // [sp+120h] [-2860h] BYREF

  LODWORD(v37) = 0;
  HIDWORD(v37) = clipMask;
  v38 = 0;
  if ( clipModel != nullptr )
  {
    idBounds::FromBoundsRotation(
      this: &v93,
      bounds: &clipModel->bounds,
      boundsOrigin: start->mat,
      boundsAxis: startAxis,
      rotation);
    num = clipModel->traceModels.num;
    ownerNumber = clipModel->ownerNumber;
    physicsId = clipModel->physicsId;
    bodyMask = clipModel->bodyMask;
    v43 = 0;
    v93.b[0].x = v93.b[0].x - (float)1.0;
    v93.b[0].y = v93.b[0].y - (float)1.0;
    v93.b[0].z = v93.b[0].z - (float)1.0;
    v93.b[1].x = v93.b[1].x + (float)1.0;
    v93.b[1].y = v93.b[1].y + (float)1.0;
    v93.b[1].z = v93.b[1].z + (float)1.0;
    if ( num > 0 )
    {
      v44 = num;
      v45 = 0;
      v38 = num;
      do
      {
        if ( v43 >= num )
          trm = nullptr;
        else
          trm = clipModel->clip->traceModelCache->cache.list[clipModel->traceModels.list[v45]]->trm;
        ++v43;
        v95[v45++] = (const idMat3 *)trm;
        --v44;
      }
      while ( v44 != 0 );
    }
  }
  else
  {
    idBounds::FromPointRotation(this: &v93, point: start->mat, rotation);
    ownerNumber = 0x1FFF;
    v95[0] = nullptr;
    physicsId = -1;
    bodyMask = 0;
    v38 = 1;
    v93.b[0].x = v93.b[0].x - (float)1.0;
    v93.b[0].y = v93.b[0].y - (float)1.0;
    v93.b[0].z = v93.b[0].z - (float)1.0;
    v93.b[1].x = v93.b[1].x + (float)1.0;
    v93.b[1].y = v93.b[1].y + (float)1.0;
    v93.b[1].z = v93.b[1].z + (float)1.0;
  }
  v47 = &v96;
  for ( i = 128; i != 0; --i )
  {
    v47 += 80;
    *(_QWORD *)v47 = v37;
  }
  PositionedModelsInternal = idClip::GetPositionedModelsInternal(
                               this,
                               v1: v93.b,
                               v2: &v93.b[1],
                               isLine: false,
                               clipMask: SHIDWORD(v37),
                               passEntityNumber: a28,
                               passOwnerNumber: ownerNumber,
                               physicsId,
                               bodyMask: v50,
                               models: v52,
                               maxModels: v54,
                               a12: v56,
                               a13: v58,
                               a14: v60,
                               a15: v62,
                               a16: v64,
                               a17: v66,
                               a18: v68,
                               a19: v70,
                               a20: v72,
                               a21: v74,
                               a22: v76,
                               a23: v78,
                               a24: v80,
                               a25: v82,
                               a26: v84,
                               a27: v86,
                               a28: bodyMask,
                               a29: v88,
                               a30: (int)v97,
                               a31: v90,
                               a32: 128);
  idCollisionModelManager::Rotation(
    this: (idCollisionModelManager *)&v94,
    result: (idCollisionQuery *)collisionModelManager,
    a3: result,
    start,
    rotation,
    globalBounds: &v93,
    trms: v95,
    numTrms: v38,
    trmAxis: v51,
    contentMask: v53,
    models: v55,
    numModels: v57,
    userName: v59,
    a14: v61,
    a15: v63,
    a16: v65,
    a17: v67,
    a18: v69,
    a19: v71,
    a20: v73,
    a21: v75,
    a22: v77,
    a23: v79,
    a24: v81,
    a25: v83,
    a26: v85,
    a27: v87,
    a28: startAxis,
    a29: v89,
    a30: (const idVec3 *)HIDWORD(v37),
    a31: v91,
    a32: (int)v97,
    a33: v92,
    a34: PositionedModelsInternal);
  if ( query != nullptr )
  {
    idClip::SetupDeferredQuery(
      this,
      query,
      type: QUERY_SUBMITTED_ROTATION,
      clipModel,
      absBounds: &v93,
      cq: &v94,
      moveClipModel: a30);
  }
  else if ( a30 )
  {
    idClip::MoveClipModel(this, clipModel, result);
  }
}


// ========================================================================
// ?Rotation@idClip@@QAA?AVidClipQuery@@PAUtrace_t@@ABVidVec3@@ABVidRotation@@PBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x827322D8
// RVA : 0x007322D8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

idClip *__fastcall idClip::Rotation(
        idClip *this,
        idClip *result,
        trace_t *a3,
        const idMat3 *start,
        idRotation *rotation,
        idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        int a28,
        int a29,
        bool a30,
        int a31,
        int a32)
{
  unsigned __int64 v37; // r6
  int *p_numQueryParms; // r27
  __int128 v42; // r11
  int v43; // r11
  double x; // fp0
  double v45; // fp11
  double y; // fp10
  double angle; // fp5
  __int64 v48; // r11
  int v50; // [sp+8h] [-D8h]
  bool v51; // [sp+Fh] [-D1h]
  const char *v52; // [sp+10h] [-D0h]
  int v53; // [sp+14h] [-CCh]
  int v54; // [sp+18h] [-C8h]
  int v55; // [sp+1Ch] [-C4h]
  int v56; // [sp+20h] [-C0h]
  int v57; // [sp+24h] [-BCh]
  int v58; // [sp+28h] [-B8h]
  int v59; // [sp+2Ch] [-B4h]
  int v60; // [sp+30h] [-B0h]
  int v61; // [sp+34h] [-ACh]
  int v62; // [sp+38h] [-A8h]
  int v63; // [sp+3Ch] [-A4h]
  int v64; // [sp+40h] [-A0h]
  int v65; // [sp+44h] [-9Ch]
  int v66; // [sp+48h] [-98h]
  int v67; // [sp+4Ch] [-94h]
  int v68; // [sp+50h] [-90h]
  int v69; // [sp+58h] [-88h]
  idVec3 *numQueryParms; // [sp+70h] [-70h] BYREF
  idPLogScope v71[13]; // [sp+78h] [-68h] BYREF

  LODWORD(v37) = "idClip::Rotation";
  HIDWORD(v37) = 1;
  idPLogScope::idPLogScope(this: v71, pl: &pLog, gMask: v37, label: (const char *)rotation);
  if ( a3 != nullptr )
  {
    idClip::RotationInternal(
      this: result,
      result: a3,
      query: nullptr,
      start,
      rotation,
      clipModel,
      startAxis,
      clipMask,
      passEntityNumber: v50,
      moveClipModel: v51,
      userName: v52,
      a12: v53,
      a13: v54,
      a14: v55,
      a15: v56,
      a16: v57,
      a17: v58,
      a18: v59,
      a19: v60,
      a20: v61,
      a21: v62,
      a22: v63,
      a23: v64,
      a24: v65,
      a25: v66,
      a26: v67,
      a27: v68,
      a28,
      a29: v69,
      a30);
    LODWORD(v48) = 0;
    *(_QWORD *)&this->world = v48;
  }
  else
  {
    p_numQueryParms = &result->numQueryParms;
    *((_QWORD *)&v42 + 1) = result->collisionQueryLastAllocedIndex;
    HIDWORD(v42) = result->numQueryParms;
    LODWORD(v42) = v42 + 1;
    result->collisionQueryLastAllocedIndex = v42;
    LODWORD(v42) = (v42 & 0xFFF) + 11621;
    DWORD1(v42) = 2 * v42;
    LODWORD(v42) = (char *)result + 24 * v42;
    *(_DWORD *)v42 = DWORD2(v42);
    *(_DWORD *)(v42 + 4) = HIDWORD(v42);
    *(_DWORD *)(v42 + 8) = DWORD2(v42);
    *(_QWORD *)(v42 + 16) = *(_QWORD *)((char *)&v42 + 4);
    numQueryParms = (idVec3 *)result->numQueryParms;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&result->rotationQueries,
      obj: (const encounterGroupRole_t *)&numQueryParms);
    if ( result->numQueryParms >= 0x800u )
      idLib::Error(fmt: "MAX_CLIP_QUERIES");
    __asm { dcbz128   r9, r8 }
    v43 = (int)&result->queryParms[(*p_numQueryParms)++];
    x = start->mat[0].x;
    numQueryParms = &startAxis->mat[1];
    *(float *)v43 = x;
    *(float *)(v43 + 4) = start->mat[0].y;
    *(float *)(v43 + 8) = start->mat[0].z;
    v45 = rotation->origin.x;
    numQueryParms = (idVec3 *)(v43 + 68);
    *(float *)(v43 + 24) = v45;
    y = rotation->origin.y;
    numQueryParms = &rotation->vec;
    *(float *)(v43 + 28) = y;
    *(float *)(v43 + 32) = rotation->origin.z;
    numQueryParms = (idVec3 *)(v43 + 24);
    *(float *)(v43 + 36) = rotation->vec.x;
    numQueryParms = (idVec3 *)(v43 + 80);
    *(float *)(v43 + 40) = rotation->vec.y;
    *(float *)(v43 + 44) = rotation->vec.z;
    angle = rotation->angle;
    *(_DWORD *)(v43 + 116) = clipModel;
    *(float *)(v43 + 48) = angle;
    *(float *)(v43 + 56) = startAxis->mat[0].x;
    *(float *)(v43 + 60) = startAxis->mat[0].y;
    *(float *)(v43 + 64) = startAxis->mat[0].z;
    *(float *)(v43 + 68) = startAxis->mat[1].x;
    *(float *)(v43 + 72) = startAxis->mat[1].y;
    *(float *)(v43 + 76) = startAxis->mat[1].z;
    *(float *)(v43 + 80) = startAxis->mat[2].x;
    *(float *)(v43 + 84) = startAxis->mat[2].y;
    *(float *)(v43 + 88) = startAxis->mat[2].z;
    *(_WORD *)(v43 + 96) = a28;
    *(_DWORD *)(v43 + 92) = clipMask;
    *(_DWORD *)(v43 + 112) = result->collisionQueryLastAllocedIndex;
    *(_WORD *)(v43 + 98) = (a30 << 15) | 0x7FFF;
    *(_DWORD *)(v43 + 124) = a32;
    *(_QWORD *)&this->world = result->collisionQueryLastAllocedIndex;
  }
  idPLogScope::~idPLogScope(this: v71);
  return this;
}


// ========================================================================
// $LN66_0
// EA  : 0x82732540
// RVA : 0x00732540
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _LN66_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 120));
}


// ========================================================================
// ?MotionInternal@idClip@@AAAXPAUtrace_t@@PAVidClipCollisionQuery@1@ABVidVec3@@2ABVidRotation@@PBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x82732568
// RVA : 0x00732568
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::MotionInternal(
        idClip *this,
        trace_t *result,
        idClip::idClipCollisionQuery *query,
        const idMat3 *start,
        const idVec3 *end,
        idRotation *rotation,
        idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        const int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        const idVec3 *a28,
        int a29,
        int a30,
        int a31,
        bool a32)
{
  int num; // r10
  __int64 v43; // r6
  int v45; // r25
  int v46; // r8
  int v53; // ctr
  int v54; // r11
  idTraceModel *trm; // r9
  char *v56; // r11
  int i; // ctr
  int PositionedModelsInternal; // r3
  int v59; // [sp+8h] [-2978h]
  int v60; // [sp+8h] [-2978h]
  idPositionedCollisionModel *v61; // [sp+Ch] [-2974h]
  const idMat3 *v62; // [sp+Ch] [-2974h]
  int v63; // [sp+10h] [-2970h]
  int v64; // [sp+10h] [-2970h]
  int v65; // [sp+14h] [-296Ch]
  const idPositionedCollisionModel *v66; // [sp+14h] [-296Ch]
  int v67; // [sp+18h] [-2968h]
  int v68; // [sp+18h] [-2968h]
  int v69; // [sp+1Ch] [-2964h]
  const char *v70; // [sp+1Ch] [-2964h]
  int v71; // [sp+20h] [-2960h]
  int v72; // [sp+20h] [-2960h]
  int v73; // [sp+24h] [-295Ch]
  int v74; // [sp+24h] [-295Ch]
  int v75; // [sp+28h] [-2958h]
  int v76; // [sp+28h] [-2958h]
  int v77; // [sp+2Ch] [-2954h]
  int v78; // [sp+2Ch] [-2954h]
  int v79; // [sp+30h] [-2950h]
  int v80; // [sp+30h] [-2950h]
  int v81; // [sp+34h] [-294Ch]
  int v82; // [sp+34h] [-294Ch]
  int v83; // [sp+38h] [-2948h]
  int v84; // [sp+38h] [-2948h]
  int v85; // [sp+3Ch] [-2944h]
  int v86; // [sp+3Ch] [-2944h]
  int v87; // [sp+40h] [-2940h]
  int v88; // [sp+40h] [-2940h]
  int v89; // [sp+44h] [-293Ch]
  int v90; // [sp+44h] [-293Ch]
  int v91; // [sp+48h] [-2938h]
  int v92; // [sp+48h] [-2938h]
  int v93; // [sp+4Ch] [-2934h]
  int v94; // [sp+4Ch] [-2934h]
  int v95; // [sp+50h] [-2930h]
  int v96; // [sp+50h] [-2930h]
  int v97; // [sp+58h] [-2928h]
  int v98; // [sp+58h] [-2928h]
  int v99; // [sp+60h] [-2920h]
  int v100; // [sp+60h] [-2920h]
  int v101; // [sp+68h] [-2918h]
  int v102; // [sp+70h] [-2910h]
  idBounds v103; // [sp+80h] [-2900h] BYREF
  idCollisionQuery v104; // [sp+98h] [-28E8h] BYREF
  const idTraceModel *v105[30]; // [sp+A0h] [-28E0h] BYREF
  char v106; // [sp+118h] [-2868h] BYREF
  _BYTE v107[2144]; // [sp+120h] [-2860h] BYREF

  idBounds::FromBoundsRotation(
    this: &v103,
    bounds: &clipModel->bounds,
    boundsOrigin: start->mat,
    boundsAxis: startAxis,
    rotation);
  _FP9 = (float)(end->x - start->mat[0].x);
  num = clipModel->traceModels.num;
  _FP6 = (float)(end->y - start->mat[0].y);
  LODWORD(v43) = 0;
  _FP4 = (float)(end->z - start->mat[0].z);
  v45 = 0;
  v46 = 0;
  __asm
  {
    fsel      f8, f9, f0, f9
    fsel      f7, f9, f9, f0
    fsel      f5, f6, f0, f6
    fsel      f9, f6, f6, f0
    fsel      f6, f4, f0, f4
    fsel      f4, f4, f4, f0
  }
  v103.b[0].x = (float)((float)_FP8 + v103.b[0].x) - (float)1.0;
  v103.b[1].x = (float)((float)_FP7 + v103.b[1].x) + (float)1.0;
  v103.b[0].y = (float)((float)_FP5 + v103.b[0].y) - (float)1.0;
  v103.b[1].y = (float)((float)_FP9 + v103.b[1].y) + (float)1.0;
  v103.b[0].z = (float)((float)_FP6 + v103.b[0].z) - (float)1.0;
  v103.b[1].z = (float)((float)_FP4 + v103.b[1].z) + (float)1.0;
  if ( num > 0 )
  {
    v53 = num;
    v54 = 0;
    v45 = num;
    do
    {
      if ( v46 >= num )
        trm = nullptr;
      else
        trm = clipModel->clip->traceModelCache->cache.list[clipModel->traceModels.list[v54]]->trm;
      HIDWORD(v43) = v105;
      ++v46;
      v105[v54++] = trm;
      --v53;
    }
    while ( v53 != 0 );
  }
  v56 = &v106;
  for ( i = 128; i != 0; --i )
  {
    v56 += 80;
    *(_QWORD *)v56 = v43;
  }
  PositionedModelsInternal = idClip::GetPositionedModelsInternal(
                               this,
                               v1: v103.b,
                               v2: &v103.b[1],
                               isLine: false,
                               clipMask: (int)a28,
                               passEntityNumber: a30,
                               passOwnerNumber: clipModel->ownerNumber,
                               physicsId: clipModel->physicsId,
                               bodyMask: v59,
                               models: v61,
                               maxModels: v63,
                               a12: v65,
                               a13: v67,
                               a14: v69,
                               a15: v71,
                               a16: v73,
                               a17: v75,
                               a18: v77,
                               a19: v79,
                               a20: v81,
                               a21: v83,
                               a22: v85,
                               a23: v87,
                               a24: v89,
                               a25: v91,
                               a26: v93,
                               a27: v95,
                               a28: clipModel->bodyMask,
                               a29: v97,
                               a30: (int)v107,
                               a31: v99,
                               a32: 128);
  idCollisionModelManager::Motion(
    this: (idCollisionModelManager *)&v104,
    result: (idCollisionQuery *)collisionModelManager,
    a3: result,
    start,
    end,
    rotation,
    globalBounds: &v103,
    trms: v105,
    numTrms: v60,
    trmAxis: v62,
    contentMask: v64,
    models: v66,
    numModels: v68,
    userName: v70,
    a15: v72,
    a16: v74,
    a17: v76,
    a18: v78,
    a19: v80,
    a20: v82,
    a21: v84,
    a22: v86,
    a23: v88,
    a24: v90,
    a25: v92,
    a26: v94,
    a27: v96,
    a28: v45,
    a29: v98,
    a30: (int)startAxis,
    a31: v100,
    a32: a28,
    a33: v101,
    a34: (int)v107,
    a35: v102,
    numTrmsa: PositionedModelsInternal);
  if ( query != nullptr )
  {
    idClip::SetupDeferredQuery(
      this,
      query,
      type: QUERY_SUBMITTED_MOTION,
      clipModel,
      absBounds: &v103,
      cq: &v104,
      moveClipModel: a32);
  }
  else if ( a32 )
  {
    idClip::MoveClipModel(this, clipModel, result);
  }
}


// ========================================================================
// ?MotionContactsInternal@idClip@@AAAXPAUtrace_t@@PAUcontactsResult_t@@PAVidClipCollisionQuery@1@ABVidVec3@@3ABVidRotation@@MPBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x827327C0
// RVA : 0x007327C0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::MotionContactsInternal(
        idClip *this,
        trace_t *result,
        contactsResult_t *contacts,
        idClip::idClipCollisionQuery *query,
        const idMat3 *start,
        const idVec3 *end,
        idRotation *rotation,
        double depth,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        const int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        int a28,
        idClipModel *a29,
        int a30,
        const idMat3 *a31,
        int a32,
        const idBounds *a33,
        int a34,
        int a35,
        int a36,
        bool clipModel_0_3,
        int a38,
        const idMat3 *startAxisa)
{
  int num; // r11
  __int64 v50; // r6
  const idMat3 *v52; // r26
  int v53; // r8
  int v60; // ctr
  int v61; // r10
  const idTraceModel *trm; // r9
  char *v63; // r11
  int i; // ctr
  int PositionedModelsInternal; // r3
  int v66; // [sp+8h] [-2998h]
  const idTraceModel **v67; // [sp+8h] [-2998h]
  idPositionedCollisionModel *v68; // [sp+Ch] [-2994h]
  int v69; // [sp+Ch] [-2994h]
  int v70; // [sp+10h] [-2990h]
  const idMat3 *v71; // [sp+10h] [-2990h]
  int v72; // [sp+14h] [-298Ch]
  int v73; // [sp+14h] [-298Ch]
  int v74; // [sp+18h] [-2988h]
  const idPositionedCollisionModel *v75; // [sp+18h] [-2988h]
  int v76; // [sp+1Ch] [-2984h]
  int v77; // [sp+1Ch] [-2984h]
  int v78; // [sp+20h] [-2980h]
  const char *v79; // [sp+20h] [-2980h]
  int v80; // [sp+24h] [-297Ch]
  int v81; // [sp+24h] [-297Ch]
  int v82; // [sp+28h] [-2978h]
  int v83; // [sp+28h] [-2978h]
  int v84; // [sp+2Ch] [-2974h]
  int v85; // [sp+2Ch] [-2974h]
  int v86; // [sp+30h] [-2970h]
  int v87; // [sp+30h] [-2970h]
  int v88; // [sp+34h] [-296Ch]
  int v89; // [sp+34h] [-296Ch]
  int v90; // [sp+38h] [-2968h]
  int v91; // [sp+38h] [-2968h]
  int v92; // [sp+3Ch] [-2964h]
  int v93; // [sp+3Ch] [-2964h]
  int v94; // [sp+40h] [-2960h]
  int v95; // [sp+40h] [-2960h]
  int v96; // [sp+44h] [-295Ch]
  int v97; // [sp+44h] [-295Ch]
  int v98; // [sp+48h] [-2958h]
  int v99; // [sp+48h] [-2958h]
  int v100; // [sp+4Ch] [-2954h]
  int v101; // [sp+4Ch] [-2954h]
  int v102; // [sp+50h] [-2950h]
  int v103; // [sp+50h] [-2950h]
  int v104; // [sp+58h] [-2948h]
  int v105; // [sp+58h] [-2948h]
  int v106; // [sp+60h] [-2940h]
  int v107; // [sp+60h] [-2940h]
  int v108; // [sp+68h] [-2938h]
  int v109; // [sp+70h] [-2930h]
  int v110; // [sp+78h] [-2928h]
  int v111; // [sp+80h] [-2920h]
  idBounds v112; // [sp+90h] [-2910h] BYREF
  idCollisionQuery v113; // [sp+A8h] [-28F8h] BYREF
  const idTraceModel *v114[30]; // [sp+B0h] [-28F0h] BYREF
  char v115; // [sp+128h] [-2878h] BYREF
  const idTraceModel *v116[540]; // [sp+130h] [-2870h] BYREF

  idBounds::FromBoundsRotation(this: &v112, bounds: &a29->bounds, boundsOrigin: start->mat, boundsAxis: a31, rotation);
  _FP9 = (float)(end->x - start->mat[0].x);
  num = a29->traceModels.num;
  _FP6 = (float)(end->y - start->mat[0].y);
  LODWORD(v50) = 0;
  _FP4 = (float)(end->z - start->mat[0].z);
  v52 = nullptr;
  v53 = 0;
  __asm
  {
    fsel      f8, f9, f0, f9
    fsel      f7, f9, f9, f0
    fsel      f5, f6, f0, f6
    fsel      f9, f6, f6, f0
    fsel      f6, f4, f0, f4
    fsel      f4, f4, f4, f0
  }
  v112.b[0].x = (float)((float)_FP8 + v112.b[0].x) - (float)((float)depth + (float)1.0);
  v112.b[1].x = (float)((float)_FP7 + v112.b[1].x) + (float)((float)depth + (float)1.0);
  v112.b[0].y = (float)((float)_FP5 + v112.b[0].y) - (float)((float)depth + (float)1.0);
  v112.b[1].y = (float)((float)_FP9 + v112.b[1].y) + (float)((float)depth + (float)1.0);
  v112.b[0].z = (float)((float)_FP6 + v112.b[0].z) - (float)((float)depth + (float)1.0);
  v112.b[1].z = (float)((float)_FP4 + v112.b[1].z) + (float)((float)depth + (float)1.0);
  if ( num > 0 )
  {
    v60 = num;
    v61 = 0;
    v52 = (const idMat3 *)num;
    do
    {
      if ( v53 >= num )
        trm = nullptr;
      else
        trm = a29->clip->traceModelCache->cache.list[a29->traceModels.list[v61]]->trm;
      HIDWORD(v50) = v114;
      ++v53;
      v114[v61++] = trm;
      --v60;
    }
    while ( v60 != 0 );
  }
  v63 = &v115;
  for ( i = 128; i != 0; --i )
  {
    v63 += 80;
    *(_QWORD *)v63 = v50;
  }
  PositionedModelsInternal = idClip::GetPositionedModelsInternal(
                               this,
                               v1: v112.b,
                               v2: &v112.b[1],
                               isLine: false,
                               clipMask: (int)a33,
                               passEntityNumber: a35,
                               passOwnerNumber: a29->ownerNumber,
                               physicsId: a29->physicsId,
                               bodyMask: v66,
                               models: v68,
                               maxModels: v70,
                               a12: v72,
                               a13: v74,
                               a14: v76,
                               a15: v78,
                               a16: v80,
                               a17: v82,
                               a18: v84,
                               a19: v86,
                               a20: v88,
                               a21: v90,
                               a22: v92,
                               a23: v94,
                               a24: v96,
                               a25: v98,
                               a26: v100,
                               a27: v102,
                               a28: a29->bodyMask,
                               a29: v104,
                               a30: (int)v116,
                               a31: v106,
                               a32: 128);
  idCollisionModelManager::MotionContacts(
    this: (idCollisionModelManager *)&v113,
    result: (idCollisionQuery *)collisionModelManager,
    a3: result,
    contacts,
    start,
    end,
    rotation,
    depth,
    globalBounds: (const idBounds *)startAxisa,
    trms: v67,
    numTrms: v69,
    trmAxis: v71,
    contentMask: v73,
    models: v75,
    numModels: v77,
    userName: v79,
    a17: v81,
    a18: v83,
    a19: v85,
    a20: v87,
    a21: v89,
    a22: v91,
    a23: v93,
    a24: v95,
    a25: v97,
    a26: v99,
    a27: v101,
    a28: v103,
    a29: &v112,
    a30: v105,
    a31: v114,
    a32: v107,
    a33: v52,
    a34: v108,
    a35: (int)a31,
    a36: v109,
    globalBounds_0: a33,
    a38: v110,
    trmsa: v116,
    a40: v111,
    numTrmsa: PositionedModelsInternal);
  if ( query != nullptr )
  {
    idClip::SetupDeferredQuery(
      this,
      query,
      type: QUERY_SUBMITTED_MOTION_CONTACTS,
      clipModel: a29,
      absBounds: &v112,
      cq: &v113,
      moveClipModel: clipModel_0_3);
  }
  else if ( clipModel_0_3 )
  {
    idClip::MoveClipModel(this, clipModel: a29, result);
  }
}


// ========================================================================
// ?MotionContacts@idClip@@QAA?AVidClipQuery@@PAUtrace_t@@PAUcontactsResult_t@@ABVidVec3@@2ABVidRotation@@MPBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x82732A48
// RVA : 0x00732A48
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

idClip *__fastcall idClip::MotionContacts(
        idClip *this,
        idClip *result,
        trace_t *a3,
        contactsResult_t *contacts,
        const idVec3 *start,
        const idVec3 *end,
        idRotation *rotation,
        double depth,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        int a28,
        idClipModel *a29,
        int a30,
        int a31,
        int a32,
        const idBounds *a33,
        int a34,
        int a35,
        int a36,
        bool clipModel_0_3,
        int a38,
        const idMat3 *startAxisa)
{
  unsigned __int64 v44; // r6
  idClipQuery *p_collisionQueryLastAllocedIndex; // r27
  int *p_numQueryParms; // r29
  __int128 v50; // r11
  int v51; // r11
  double z; // fp12
  double x; // fp11
  double y; // fp10
  double v55; // fp9
  double v56; // fp5
  double angle; // fp2
  unsigned __int64 index; // r6
  __int64 v59; // r9
  const idMat3 *v61; // [sp+8h] [-F8h]
  int v62; // [sp+Ch] [-F4h]
  int v63; // [sp+10h] [-F0h]
  bool v64; // [sp+17h] [-E9h]
  const char *v65; // [sp+18h] [-E8h]
  int v66; // [sp+1Ch] [-E4h]
  int v67; // [sp+20h] [-E0h]
  int v68; // [sp+24h] [-DCh]
  int v69; // [sp+28h] [-D8h]
  int v70; // [sp+2Ch] [-D4h]
  int v71; // [sp+30h] [-D0h]
  int v72; // [sp+34h] [-CCh]
  int v73; // [sp+38h] [-C8h]
  int v74; // [sp+3Ch] [-C4h]
  int v75; // [sp+40h] [-C0h]
  int v76; // [sp+44h] [-BCh]
  int v77; // [sp+48h] [-B8h]
  int v78; // [sp+4Ch] [-B4h]
  int v79; // [sp+50h] [-B0h]
  int v80; // [sp+58h] [-A8h]
  int v81; // [sp+60h] [-A0h]
  int v82; // [sp+68h] [-98h]
  int v83; // [sp+70h] [-90h]
  int v84; // [sp+78h] [-88h]
  idVec3 *numQueryParms; // [sp+80h] [-80h] BYREF
  idPLogScope v86[2]; // [sp+88h] [-78h] BYREF

  LODWORD(v44) = "idClip::MotionContacts";
  HIDWORD(v44) = 1;
  idPLogScope::idPLogScope(this: v86, pl: &pLog, gMask: v44, label: (const char *)start);
  if ( a3 != nullptr )
  {
    idClip::MotionContactsInternal(
      this: result,
      result: a3,
      contacts,
      query: nullptr,
      (const idMat3 *)start,
      end,
      rotation,
      depth,
      clipModel: (const idClipModel *)clipModel_0_3,
      startAxis: v61,
      clipMask: v62,
      passEntityNumber: v63,
      moveClipModel: v64,
      userName: v65,
      a15: v66,
      a16: v67,
      a17: v68,
      a18: v69,
      a19: v70,
      a20: v71,
      a21: v72,
      a22: v73,
      a23: v74,
      a24: v75,
      a25: v76,
      a26: v77,
      a27: v78,
      a28: v79,
      a29,
      a30: v80,
      (const idMat3 *)a31,
      a32: v81,
      a33,
      a34: v82,
      a35,
      a36: v83,
      clipModel_0_3,
      a38: v84,
      startAxisa);
    LODWORD(v59) = 0;
    *(_QWORD *)&this->world = v59;
  }
  else
  {
    p_collisionQueryLastAllocedIndex = (idClipQuery *)&result->collisionQueryLastAllocedIndex;
    p_numQueryParms = &result->numQueryParms;
    *((_QWORD *)&v50 + 1) = result->collisionQueryLastAllocedIndex;
    HIDWORD(v50) = result->numQueryParms;
    LODWORD(v50) = v50 + 1;
    result->collisionQueryLastAllocedIndex = v50;
    LODWORD(v50) = (v50 & 0xFFF) + 11621;
    DWORD1(v50) = 2 * v50;
    LODWORD(v50) = (char *)result + 24 * v50;
    *(_DWORD *)v50 = DWORD2(v50);
    *(_DWORD *)(v50 + 4) = HIDWORD(v50);
    *(_DWORD *)(v50 + 8) = DWORD2(v50);
    *(_QWORD *)(v50 + 16) = *(_QWORD *)((char *)&v50 + 4);
    numQueryParms = (idVec3 *)result->numQueryParms;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&result->motionContactsQueries,
      obj: (const encounterGroupRole_t *)&numQueryParms);
    if ( result->numQueryParms >= 0x800u )
      idLib::Error(fmt: "MAX_CLIP_QUERIES");
    __asm { dcbz128   r9, r8 }
    v51 = (int)&result->queryParms[(*p_numQueryParms)++];
    *(float *)v51 = start->x;
    *(float *)(v51 + 4) = start->y;
    z = start->z;
    numQueryParms = (idVec3 *)(a31 + 12);
    *(float *)(v51 + 8) = z;
    x = end->x;
    numQueryParms = (idVec3 *)(v51 + 68);
    *(float *)(v51 + 12) = x;
    y = end->y;
    numQueryParms = &rotation->vec;
    *(float *)(v51 + 16) = y;
    v55 = end->z;
    numQueryParms = (idVec3 *)(a31 + 24);
    *(float *)(v51 + 20) = v55;
    *(float *)(v51 + 24) = rotation->origin.x;
    numQueryParms = (idVec3 *)(v51 + 12);
    *(float *)(v51 + 28) = rotation->origin.y;
    numQueryParms = (idVec3 *)(v51 + 36);
    *(float *)(v51 + 32) = rotation->origin.z;
    v56 = rotation->vec.x;
    numQueryParms = (idVec3 *)(v51 + 80);
    *(float *)(v51 + 36) = v56;
    *(float *)(v51 + 40) = rotation->vec.y;
    *(float *)(v51 + 44) = rotation->vec.z;
    angle = rotation->angle;
    *(_DWORD *)(v51 + 116) = a29;
    *(float *)(v51 + 48) = angle;
    *(float *)(v51 + 52) = depth;
    *(float *)(v51 + 56) = *(float *)a31;
    *(float *)(v51 + 60) = *(float *)(a31 + 4);
    *(float *)(v51 + 64) = *(float *)(a31 + 8);
    *(float *)(v51 + 68) = *(float *)(a31 + 12);
    *(float *)(v51 + 72) = *(float *)(a31 + 16);
    *(float *)(v51 + 76) = *(float *)(a31 + 20);
    *(float *)(v51 + 80) = *(float *)(a31 + 24);
    *(float *)(v51 + 84) = *(float *)(a31 + 28);
    *(float *)(v51 + 88) = *(float *)(a31 + 32);
    *(_WORD *)(v51 + 96) = a35;
    *(_DWORD *)(v51 + 92) = a33;
    index = p_collisionQueryLastAllocedIndex->index;
    *(_WORD *)(v51 + 98) = (clipModel_0_3 << 15) | 0x7FFF;
    *(_DWORD *)(v51 + 112) = index;
    *(_DWORD *)(v51 + 124) = startAxisa;
    *(idClipQuery *)&this->world = (idClipQuery)p_collisionQueryLastAllocedIndex->index;
  }
  idPLogScope::~idPLogScope(this: v86);
  return this;
}


// ========================================================================
// $LN72_0
// EA  : 0x82732D00
// RVA : 0x00732D00
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _LN72_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 136));
}


// ========================================================================
// ?StepMoveInternal@idClip@@AAAXPAUtrace_t@@PAVidClipCollisionQuery@1@ABVidVec3@@22MMPBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x82732D28
// RVA : 0x00732D28
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::StepMoveInternal(
        idClip *this,
        trace_t *result,
        idClip::idClipCollisionQuery *query,
        const idVec3 *start,
        const idVec3 *end,
        const idVec3 *downNormal,
        double stepUp,
        double stepDown,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        const int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        int a28,
        int a29,
        idClipModel *a30,
        int a31,
        const idMat3 *a32,
        int a33,
        const idBounds *a34,
        int a35,
        int a36,
        int a37,
        bool clipModel_0_3,
        int a39,
        const idTraceModel **startAxis_0)
{
  double v46; // fp7
  double v47; // fp6
  int num; // r10
  __int64 v54; // r6
  int v55; // r26
  int v56; // r8
  double v68; // fp8
  int v73; // ctr
  int v74; // r11
  const idTraceModel *trm; // r9
  char *v76; // r11
  int i; // ctr
  int PositionedModelsInternal; // r3
  int v79; // [sp+8h] [-29D8h]
  int v80; // [sp+8h] [-29D8h]
  idPositionedCollisionModel *v81; // [sp+Ch] [-29D4h]
  const idMat3 *v82; // [sp+Ch] [-29D4h]
  int v83; // [sp+10h] [-29D0h]
  int v84; // [sp+10h] [-29D0h]
  int v85; // [sp+14h] [-29CCh]
  const idPositionedCollisionModel *v86; // [sp+14h] [-29CCh]
  int v87; // [sp+18h] [-29C8h]
  int v88; // [sp+18h] [-29C8h]
  int v89; // [sp+1Ch] [-29C4h]
  const char *v90; // [sp+1Ch] [-29C4h]
  int v91; // [sp+20h] [-29C0h]
  int v92; // [sp+20h] [-29C0h]
  int v93; // [sp+24h] [-29BCh]
  int v94; // [sp+24h] [-29BCh]
  int v95; // [sp+28h] [-29B8h]
  int v96; // [sp+28h] [-29B8h]
  int v97; // [sp+2Ch] [-29B4h]
  int v98; // [sp+2Ch] [-29B4h]
  int v99; // [sp+30h] [-29B0h]
  int v100; // [sp+30h] [-29B0h]
  int v101; // [sp+34h] [-29ACh]
  int v102; // [sp+34h] [-29ACh]
  int v103; // [sp+38h] [-29A8h]
  int v104; // [sp+38h] [-29A8h]
  int v105; // [sp+3Ch] [-29A4h]
  int v106; // [sp+3Ch] [-29A4h]
  int v107; // [sp+40h] [-29A0h]
  int v108; // [sp+40h] [-29A0h]
  int v109; // [sp+44h] [-299Ch]
  int v110; // [sp+44h] [-299Ch]
  int v111; // [sp+48h] [-2998h]
  int v112; // [sp+48h] [-2998h]
  int v113; // [sp+4Ch] [-2994h]
  int v114; // [sp+4Ch] [-2994h]
  int v115; // [sp+50h] [-2990h]
  int v116; // [sp+50h] [-2990h]
  int v117; // [sp+58h] [-2988h]
  int v118; // [sp+58h] [-2988h]
  int v119; // [sp+60h] [-2980h]
  int v120; // [sp+60h] [-2980h]
  int v121; // [sp+68h] [-2978h]
  int v122; // [sp+70h] [-2970h]
  int v123; // [sp+78h] [-2968h]
  int v124; // [sp+80h] [-2960h]
  int v125; // [sp+88h] [-2958h]
  idBounds v126; // [sp+90h] [-2950h] BYREF
  idVec3 v127; // [sp+A8h] [-2938h] BYREF
  idCollisionQuery v128; // [sp+B8h] [-2928h] BYREF
  const idTraceModel *v129[30]; // [sp+C0h] [-2920h] BYREF
  char v130; // [sp+138h] [-28A8h] BYREF
  idBounds v131[92]; // [sp+140h] [-28A0h] BYREF

  v46 = (float)(end->y - start->y);
  v47 = (float)(end->z - start->z);
  v127.x = end->x - start->x;
  v127.y = v46;
  v127.z = v47;
  idBounds::FromBoundsTranslation(
    this: &v126,
    bounds: &a30->bounds,
    boundsOrigin: start,
    boundsAxis: a32,
    translation: &v127);
  _FP2 = (float)(downNormal->x * (float)stepDown);
  _FP12 = (float)(downNormal->y * (float)stepDown);
  _FP11 = (float)(downNormal->z * (float)stepDown);
  num = a30->traceModels.num;
  LODWORD(v54) = 0;
  v55 = 0;
  v56 = 0;
  __asm { fsel      f29, f2, f0, f2 }
  _FP9 = (float)(downNormal->x * (float)-stepUp);
  __asm
  {
    fsel      f2, f2, f2, f0
    fsel      f28, f12, f0, f12
    fsel      f27, f11, f0, f11
  }
  _FP7 = (float)(downNormal->y * (float)-stepUp);
  __asm
  {
    fsel      f12, f12, f12, f0
    fsel      f11, f11, f11, f0
  }
  _FP5 = (float)(downNormal->z * (float)-stepUp);
  __asm { fsel      f26, f9, f0, f9 }
  __asm { fsel      f9, f9, f9, f0 }
  v68 = (float)((float)_FP2 + v126.b[1].x);
  __asm { fsel      f25, f7, f0, f7 }
  __asm
  {
    fsel      f7, f7, f7, f0
    fsel      f2, f5, f0, f5
    fsel      f0, f5, f5, f0
  }
  v126.b[0].x = (float)((float)_FP26 + (float)((float)_FP29 + v126.b[0].x)) - (float)1.0;
  v126.b[1].x = (float)((float)_FP9 + (float)v68) + (float)1.0;
  v126.b[0].y = (float)((float)_FP25 + (float)((float)_FP28 + v126.b[0].y)) - (float)1.0;
  v126.b[1].y = (float)((float)_FP7 + (float)((float)_FP12 + v126.b[1].y)) + (float)1.0;
  v126.b[0].z = (float)((float)_FP2 + (float)((float)_FP27 + v126.b[0].z)) - (float)1.0;
  v126.b[1].z = (float)((float)_FP0 + (float)((float)_FP11 + v126.b[1].z)) + (float)1.0;
  if ( num > 0 )
  {
    v73 = num;
    v74 = 0;
    v55 = num;
    do
    {
      if ( v56 >= num )
        trm = nullptr;
      else
        trm = a30->clip->traceModelCache->cache.list[a30->traceModels.list[v74]]->trm;
      HIDWORD(v54) = v129;
      ++v56;
      v129[v74++] = trm;
      --v73;
    }
    while ( v73 != 0 );
  }
  v76 = &v130;
  for ( i = 128; i != 0; --i )
  {
    v76 += 80;
    *(_QWORD *)v76 = v54;
  }
  PositionedModelsInternal = idClip::GetPositionedModelsInternal(
                               this,
                               v1: v126.b,
                               v2: &v126.b[1],
                               isLine: false,
                               clipMask: (int)a34,
                               passEntityNumber: a36,
                               passOwnerNumber: a30->ownerNumber,
                               physicsId: a30->physicsId,
                               bodyMask: v79,
                               models: v81,
                               maxModels: v83,
                               a12: v85,
                               a13: v87,
                               a14: v89,
                               a15: v91,
                               a16: v93,
                               a17: v95,
                               a18: v97,
                               a19: v99,
                               a20: v101,
                               a21: v103,
                               a22: v105,
                               a23: v107,
                               a24: v109,
                               a25: v111,
                               a26: v113,
                               a27: v115,
                               a28: a30->bodyMask,
                               a29: v117,
                               a30: (int)v131,
                               a31: v119,
                               a32: 128);
  idCollisionModelManager::StepMove(
    this: (idCollisionModelManager *)&v128,
    result: (idCollisionQuery *)collisionModelManager,
    a3: result,
    start,
    end,
    downNormal,
    stepUp,
    stepDown,
    globalBounds: v131,
    trms: startAxis_0,
    numTrms: v80,
    trmAxis: v82,
    contentMask: v84,
    models: v86,
    numModels: v88,
    userName: v90,
    a17: v92,
    a18: v94,
    a19: v96,
    a20: v98,
    a21: v100,
    a22: v102,
    a23: v104,
    a24: v106,
    a25: v108,
    a26: v110,
    a27: v112,
    a28: v114,
    a29: v116,
    a30: (int)&v126,
    a31: v118,
    a32: v129,
    a33: v120,
    a34: v55,
    a35: v121,
    a36: a32,
    a37: v122,
    globalBounds_0: a34,
    a39: v123,
    trms_0: (const idTraceModel **)v131,
    a41: v124,
    numTrmsa: PositionedModelsInternal,
    a43: v125,
    trmAxisa: startAxis_0);
  if ( query != nullptr )
  {
    idClip::SetupDeferredQuery(
      this,
      query,
      type: QUERY_SUBMITTED_STEPMOVE,
      clipModel: a30,
      absBounds: &v126,
      cq: &v128,
      moveClipModel: clipModel_0_3);
  }
  else if ( clipModel_0_3 )
  {
    idClip::MoveClipModel(this, clipModel: a30, result);
  }
}


// ========================================================================
// ?StepMove@idClip@@QAA?AVidClipQuery@@PAUtrace_t@@ABVidVec3@@11MMPBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x82733020
// RVA : 0x00733020
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

idClip *__fastcall idClip::StepMove(
        idClip *this,
        idClip *result,
        trace_t *a3,
        const idVec3 *start,
        const idVec3 *end,
        const idVec3 *downNormal,
        double stepUp,
        double stepDown,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        int a28,
        int a29,
        idClipModel *a30,
        int a31,
        int a32,
        int a33,
        const idBounds *a34,
        int a35,
        const idClipModel *a36,
        int a37,
        bool clipModel_0_3,
        int a39,
        const idTraceModel **startAxis_0)
{
  unsigned __int64 v46; // r6
  int *p_numQueryParms; // r30
  __int128 v50; // r11
  int v51; // r11
  double z; // fp9
  double v53; // fp6
  __int64 v54; // r8
  int v56; // [sp+8h] [-E8h]
  int v57; // [sp+Ch] [-E4h]
  bool v58; // [sp+13h] [-DDh]
  const char *v59; // [sp+14h] [-DCh]
  int v60; // [sp+18h] [-D8h]
  int v61; // [sp+1Ch] [-D4h]
  int v62; // [sp+20h] [-D0h]
  int v63; // [sp+24h] [-CCh]
  int v64; // [sp+28h] [-C8h]
  int v65; // [sp+2Ch] [-C4h]
  int v66; // [sp+30h] [-C0h]
  int v67; // [sp+34h] [-BCh]
  int v68; // [sp+38h] [-B8h]
  int v69; // [sp+3Ch] [-B4h]
  int v70; // [sp+40h] [-B0h]
  int v71; // [sp+44h] [-ACh]
  int v72; // [sp+48h] [-A8h]
  int v73; // [sp+4Ch] [-A4h]
  int v74; // [sp+50h] [-A0h]
  int v75; // [sp+58h] [-98h]
  int v76; // [sp+60h] [-90h]
  int v77; // [sp+68h] [-88h]
  int v78; // [sp+70h] [-80h]
  int v79; // [sp+78h] [-78h]
  encounterGroupRole_t v80[2]; // [sp+80h] [-70h] BYREF
  idPLogScope v81; // [sp+88h] [-68h] BYREF

  LODWORD(v46) = "idClip::StepMove";
  HIDWORD(v46) = 1;
  idPLogScope::idPLogScope(this: &v81, pl: &pLog, gMask: v46, label: (const char *)end);
  if ( a3 != nullptr )
  {
    idClip::StepMoveInternal(
      this: result,
      result: a3,
      query: nullptr,
      start,
      end,
      downNormal,
      stepUp,
      stepDown,
      clipModel: a36,
      startAxis: (const idMat3 *)clipModel_0_3,
      clipMask: v56,
      passEntityNumber: v57,
      moveClipModel: v58,
      userName: v59,
      a15: v60,
      a16: v61,
      a17: v62,
      a18: v63,
      a19: v64,
      a20: v65,
      a21: v66,
      a22: v67,
      a23: v68,
      a24: v69,
      a25: v70,
      a26: v71,
      a27: v72,
      a28: v73,
      a29: v74,
      a30,
      a31: v75,
      (const idMat3 *)a32,
      a33: v76,
      a34,
      a35: v77,
      (int)a36,
      a37: v78,
      clipModel_0_3,
      a39: v79,
      startAxis_0);
    LODWORD(v54) = 0;
    *(_QWORD *)&this->world = v54;
  }
  else
  {
    p_numQueryParms = &result->numQueryParms;
    *((_QWORD *)&v50 + 1) = result->collisionQueryLastAllocedIndex;
    HIDWORD(v50) = result->numQueryParms;
    LODWORD(v50) = v50 + 1;
    result->collisionQueryLastAllocedIndex = v50;
    LODWORD(v50) = (v50 & 0xFFF) + 11621;
    DWORD1(v50) = 2 * v50;
    LODWORD(v50) = (char *)result + 24 * v50;
    *(_DWORD *)v50 = DWORD2(v50);
    *(_DWORD *)(v50 + 4) = HIDWORD(v50);
    *(_DWORD *)(v50 + 8) = DWORD2(v50);
    *(_QWORD *)(v50 + 16) = *(_QWORD *)((char *)&v50 + 4);
    v80[0] = (encounterGroupRole_t)result->numQueryParms;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&result->stepMoveQueries,
      obj: v80);
    if ( result->numQueryParms >= 0x800u )
      idLib::Error(fmt: "MAX_CLIP_QUERIES");
    __asm { dcbz128   r9, r8 }
    v51 = (int)&result->queryParms[(*p_numQueryParms)++];
    *(float *)v51 = start->x;
    *(float *)(v51 + 4) = start->y;
    *(float *)(v51 + 8) = start->z;
    *(float *)(v51 + 12) = end->x;
    *(float *)(v51 + 16) = end->y;
    v80[0] = a32 + 12;
    z = end->z;
    v80[0] = v51 + 68;
    *(float *)(v51 + 20) = z;
    *(float *)(v51 + 36) = downNormal->x;
    v80[0] = a32 + 24;
    *(float *)(v51 + 40) = downNormal->y;
    v80[0] = v51 + 36;
    v53 = downNormal->z;
    v80[0] = v51 + 80;
    *(float *)(v51 + 44) = v53;
    *(_DWORD *)(v51 + 116) = a30;
    *(float *)(v51 + 48) = stepUp;
    *(float *)(v51 + 52) = stepDown;
    *(float *)(v51 + 56) = *(float *)a32;
    *(float *)(v51 + 60) = *(float *)(a32 + 4);
    *(float *)(v51 + 64) = *(float *)(a32 + 8);
    *(float *)(v51 + 68) = *(float *)(a32 + 12);
    *(float *)(v51 + 72) = *(float *)(a32 + 16);
    *(float *)(v51 + 76) = *(float *)(a32 + 20);
    *(float *)(v51 + 80) = *(float *)(a32 + 24);
    *(float *)(v51 + 84) = *(float *)(a32 + 28);
    *(float *)(v51 + 88) = *(float *)(a32 + 32);
    *(_WORD *)(v51 + 96) = (_WORD)a36;
    *(_DWORD *)(v51 + 92) = a34;
    *(_DWORD *)(v51 + 112) = result->collisionQueryLastAllocedIndex;
    *(_WORD *)(v51 + 98) = (clipModel_0_3 << 15) | 0x7FFF;
    *(_DWORD *)(v51 + 124) = startAxis_0;
    *(_QWORD *)&this->world = result->collisionQueryLastAllocedIndex;
  }
  idPLogScope::~idPLogScope(this: &v81);
  return this;
}


// ========================================================================
// $LN62
// EA  : 0x827332B4
// RVA : 0x007332B4
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _LN62()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 136));
}


// ========================================================================
// ?StepMoveContactsInternal@idClip@@AAAXPAUtrace_t@@PAUcontactsResult_t@@PAVidClipCollisionQuery@1@ABVidVec3@@33MMPBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x827332E0
// RVA : 0x007332E0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::StepMoveContactsInternal(
        idClip *this,
        trace_t *result,
        contactsResult_t *contacts,
        idClip::idClipCollisionQuery *query,
        idVec3 *start,
        const idVec3 *end,
        const idVec3 *downNormal,
        double stepUp,
        double stepDown,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        const int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        idClipModel *a32,
        int a33,
        const idMat3 *a34,
        int a35,
        const idBounds *a36,
        int a37,
        int a38,
        int a39,
        bool clipModel_0_3,
        int a41,
        idMat3 *startAxisa)
{
  double v44; // fp7
  double v45; // fp6
  int num; // r11
  __int64 v57; // r6
  const idMat3 *v58; // r26
  int v59; // r8
  double v71; // fp8
  int v76; // ctr
  int v77; // r10
  const idTraceModel *trm; // r9
  char *v79; // r11
  int i; // ctr
  int PositionedModelsInternal; // r3
  int v82; // [sp+8h] [-29E8h]
  const idTraceModel **v83; // [sp+8h] [-29E8h]
  idPositionedCollisionModel *v84; // [sp+Ch] [-29E4h]
  int v85; // [sp+Ch] [-29E4h]
  int v86; // [sp+10h] [-29E0h]
  const idMat3 *v87; // [sp+10h] [-29E0h]
  int v88; // [sp+14h] [-29DCh]
  int v89; // [sp+14h] [-29DCh]
  int v90; // [sp+18h] [-29D8h]
  const idPositionedCollisionModel *v91; // [sp+18h] [-29D8h]
  int v92; // [sp+1Ch] [-29D4h]
  int v93; // [sp+1Ch] [-29D4h]
  int v94; // [sp+20h] [-29D0h]
  const char *v95; // [sp+20h] [-29D0h]
  int v96; // [sp+24h] [-29CCh]
  int v97; // [sp+24h] [-29CCh]
  int v98; // [sp+28h] [-29C8h]
  int v99; // [sp+28h] [-29C8h]
  int v100; // [sp+2Ch] [-29C4h]
  int v101; // [sp+2Ch] [-29C4h]
  int v102; // [sp+30h] [-29C0h]
  int v103; // [sp+30h] [-29C0h]
  int v104; // [sp+34h] [-29BCh]
  int v105; // [sp+34h] [-29BCh]
  int v106; // [sp+38h] [-29B8h]
  int v107; // [sp+38h] [-29B8h]
  int v108; // [sp+3Ch] [-29B4h]
  int v109; // [sp+3Ch] [-29B4h]
  int v110; // [sp+40h] [-29B0h]
  int v111; // [sp+40h] [-29B0h]
  int v112; // [sp+44h] [-29ACh]
  int v113; // [sp+44h] [-29ACh]
  int v114; // [sp+48h] [-29A8h]
  int v115; // [sp+48h] [-29A8h]
  int v116; // [sp+4Ch] [-29A4h]
  int v117; // [sp+4Ch] [-29A4h]
  int v118; // [sp+50h] [-29A0h]
  int v119; // [sp+50h] [-29A0h]
  int v120; // [sp+54h] [-299Ch]
  int v121; // [sp+58h] [-2998h]
  int v122; // [sp+58h] [-2998h]
  int v123; // [sp+60h] [-2990h]
  int v124; // [sp+60h] [-2990h]
  int v125; // [sp+68h] [-2988h]
  int v126; // [sp+70h] [-2980h]
  int v127; // [sp+78h] [-2978h]
  int v128; // [sp+80h] [-2970h]
  int v129; // [sp+88h] [-2968h]
  int v130; // [sp+90h] [-2960h]
  idBounds v131; // [sp+A0h] [-2950h] BYREF
  idVec3 v132; // [sp+B8h] [-2938h] BYREF
  idCollisionQuery v133; // [sp+C8h] [-2928h] BYREF
  const idTraceModel *v134[30]; // [sp+D0h] [-2920h] BYREF
  char v135; // [sp+148h] [-28A8h] BYREF
  const idTraceModel *v136[552]; // [sp+150h] [-28A0h] BYREF

  v44 = (float)(end->y - start->y);
  v45 = (float)(end->z - start->z);
  v132.x = end->x - start->x;
  v132.y = v44;
  v132.z = v45;
  idBounds::FromBoundsTranslation(
    this: &v131,
    bounds: &a32->bounds,
    boundsOrigin: start,
    boundsAxis: a34,
    translation: &v132);
  _FP2 = (float)(downNormal->x * (float)stepDown);
  _FP12 = (float)(downNormal->y * (float)stepDown);
  _FP11 = (float)(downNormal->z * (float)stepDown);
  num = a32->traceModels.num;
  LODWORD(v57) = 0;
  v58 = nullptr;
  v59 = 0;
  __asm { fsel      f29, f2, f0, f2 }
  _FP9 = (float)(downNormal->x * (float)-stepUp);
  __asm
  {
    fsel      f2, f2, f2, f0
    fsel      f28, f12, f0, f12
  }
  _FP7 = (float)(downNormal->y * (float)-stepUp);
  __asm
  {
    fsel      f27, f11, f0, f11
    fsel      f12, f12, f12, f0
  }
  _FP5 = (float)(downNormal->z * (float)-stepUp);
  __asm { fsel      f11, f11, f11, f0 }
  __asm { fsel      f26, f9, f0, f9 }
  __asm { fsel      f9, f9, f9, f0 }
  v71 = (float)((float)_FP2 + v131.b[1].x);
  __asm { fsel      f25, f7, f0, f7 }
  __asm
  {
    fsel      f7, f7, f7, f0
    fsel      f2, f5, f0, f5
  }
  __asm { fsel      f0, f5, f5, f0 }
  v131.b[0].x = (float)((float)_FP26 + (float)((float)_FP29 + v131.b[0].x)) - (float)1.5;
  v131.b[1].x = (float)((float)_FP9 + (float)v71) + (float)1.5;
  v131.b[0].y = (float)((float)_FP25 + (float)((float)_FP28 + v131.b[0].y)) - (float)1.5;
  v131.b[1].y = (float)((float)_FP7 + (float)((float)_FP12 + v131.b[1].y)) + (float)1.5;
  v131.b[0].z = (float)((float)_FP2 + (float)((float)_FP27 + v131.b[0].z)) - (float)1.5;
  v131.b[1].z = (float)((float)_FP0 + (float)((float)_FP11 + v131.b[1].z)) + (float)1.5;
  if ( num > 0 )
  {
    v76 = num;
    v77 = 0;
    v58 = (const idMat3 *)num;
    do
    {
      if ( v59 >= num )
        trm = nullptr;
      else
        trm = a32->clip->traceModelCache->cache.list[a32->traceModels.list[v77]]->trm;
      HIDWORD(v57) = v134;
      ++v59;
      v134[v77++] = trm;
      --v76;
    }
    while ( v76 != 0 );
  }
  v79 = &v135;
  for ( i = 128; i != 0; --i )
  {
    v79 += 80;
    *(_QWORD *)v79 = v57;
  }
  PositionedModelsInternal = idClip::GetPositionedModelsInternal(
                               this,
                               v1: v131.b,
                               v2: &v131.b[1],
                               isLine: false,
                               clipMask: (int)a36,
                               passEntityNumber: a38,
                               passOwnerNumber: a32->ownerNumber,
                               physicsId: a32->physicsId,
                               bodyMask: v82,
                               models: v84,
                               maxModels: v86,
                               a12: v88,
                               a13: v90,
                               a14: v92,
                               a15: v94,
                               a16: v96,
                               a17: v98,
                               a18: v100,
                               a19: v102,
                               a20: v104,
                               a21: v106,
                               a22: v108,
                               a23: v110,
                               a24: v112,
                               a25: v114,
                               a26: v116,
                               a27: v118,
                               a28: a32->bodyMask,
                               a29: v121,
                               a30: (int)v136,
                               a31: v123,
                               a32: 128);
  idCollisionModelManager::StepMoveContacts(
    this: (idCollisionModelManager *)&v133,
    result: (idCollisionQuery *)collisionModelManager,
    a3: result,
    contacts,
    start,
    end,
    downNormal,
    stepUp,
    stepDown,
    globalBounds: (const idBounds *)startAxisa,
    trms: v83,
    numTrms: v85,
    trmAxis: v87,
    contentMask: v89,
    models: v91,
    numModels: v93,
    userName: v95,
    a18: v97,
    a19: v99,
    a20: v101,
    a21: v103,
    a22: v105,
    a23: v107,
    a24: v109,
    a25: v111,
    a26: v113,
    a27: v115,
    a28: v117,
    a29: v119,
    a30: v120,
    a31: v122,
    a32: (const idTraceModel **)&v131,
    a33: v124,
    a34: v134,
    a35: v125,
    a36: v58,
    a37: v126,
    a38: a34,
    a39: v127,
    globalBounds_0: a36,
    a41: v128,
    trmsa: v136,
    a43: v129,
    numTrmsa: PositionedModelsInternal,
    a45: v130,
    trmAxisa: (const idTraceModel **)startAxisa);
  if ( query != nullptr )
  {
    idClip::SetupDeferredQuery(
      this,
      query,
      type: QUERY_SUBMITTED_STEPMOVE_CONTACTS,
      clipModel: a32,
      absBounds: &v131,
      cq: &v133,
      moveClipModel: clipModel_0_3);
  }
  else if ( clipModel_0_3 )
  {
    idClip::MoveClipModel(this, clipModel: a32, result);
  }
}


// ========================================================================
// ?StepMoveContacts@idClip@@QAA?AVidClipQuery@@PAUtrace_t@@PAUcontactsResult_t@@ABVidVec3@@22MMPBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x827335E0
// RVA : 0x007335E0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

idClip *__fastcall idClip::StepMoveContacts(
        idClip *this,
        idClip *result,
        trace_t *a3,
        contactsResult_t *contacts,
        idVec3 *start,
        const idVec3 *end,
        const idVec3 *downNormal,
        double stepUp,
        double stepDown,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        idClipModel *a32,
        int a33,
        int a34,
        int a35,
        const idBounds *a36,
        int a37,
        int a38,
        int a39,
        bool clipModel_0_3,
        int a41,
        idMat3 *startAxisa)
{
  unsigned __int64 v48; // r6
  int *p_numQueryParms; // r30
  __int128 v53; // r11
  int v54; // r11
  double z; // fp9
  double v56; // fp6
  __int64 v57; // r9
  const idMat3 *v59; // [sp+8h] [-F8h]
  int v60; // [sp+Ch] [-F4h]
  int v61; // [sp+10h] [-F0h]
  bool v62; // [sp+17h] [-E9h]
  const char *v63; // [sp+18h] [-E8h]
  int v64; // [sp+1Ch] [-E4h]
  int v65; // [sp+20h] [-E0h]
  int v66; // [sp+24h] [-DCh]
  int v67; // [sp+28h] [-D8h]
  int v68; // [sp+2Ch] [-D4h]
  int v69; // [sp+30h] [-D0h]
  int v70; // [sp+34h] [-CCh]
  int v71; // [sp+38h] [-C8h]
  int v72; // [sp+3Ch] [-C4h]
  int v73; // [sp+40h] [-C0h]
  int v74; // [sp+44h] [-BCh]
  int v75; // [sp+48h] [-B8h]
  int v76; // [sp+4Ch] [-B4h]
  int v77; // [sp+50h] [-B0h]
  int v78; // [sp+54h] [-ACh]
  int v79; // [sp+58h] [-A8h]
  int v80; // [sp+60h] [-A0h]
  int v81; // [sp+68h] [-98h]
  int v82; // [sp+70h] [-90h]
  int v83; // [sp+78h] [-88h]
  int v84; // [sp+80h] [-80h]
  encounterGroupRole_t v85[2]; // [sp+90h] [-70h] BYREF
  idPLogScope v86; // [sp+98h] [-68h] BYREF

  LODWORD(v48) = "idClip::StepMoveContacts";
  HIDWORD(v48) = 1;
  idPLogScope::idPLogScope(this: &v86, pl: &pLog, gMask: v48, label: (const char *)start);
  if ( a3 != nullptr )
  {
    idClip::StepMoveContactsInternal(
      this: result,
      result: a3,
      contacts,
      query: nullptr,
      start,
      end,
      downNormal,
      stepUp,
      stepDown,
      clipModel: (const idClipModel *)clipModel_0_3,
      startAxis: v59,
      clipMask: v60,
      passEntityNumber: v61,
      moveClipModel: v62,
      userName: v63,
      a16: v64,
      a17: v65,
      a18: v66,
      a19: v67,
      a20: v68,
      a21: v69,
      a22: v70,
      a23: v71,
      a24: v72,
      a25: v73,
      a26: v74,
      a27: v75,
      a28: v76,
      a29: v77,
      a30: v78,
      a31: v79,
      a32,
      a33: v80,
      (const idMat3 *)a34,
      a35: v81,
      a36,
      a37: v82,
      a38,
      a39: v83,
      clipModel_0_3,
      a41: v84,
      startAxisa);
    LODWORD(v57) = 0;
    *(_QWORD *)&this->world = v57;
  }
  else
  {
    p_numQueryParms = &result->numQueryParms;
    *((_QWORD *)&v53 + 1) = result->collisionQueryLastAllocedIndex;
    HIDWORD(v53) = result->numQueryParms;
    LODWORD(v53) = v53 + 1;
    result->collisionQueryLastAllocedIndex = v53;
    LODWORD(v53) = (v53 & 0xFFF) + 11621;
    DWORD1(v53) = 2 * v53;
    LODWORD(v53) = (char *)result + 24 * v53;
    *(_DWORD *)v53 = DWORD2(v53);
    *(_DWORD *)(v53 + 4) = HIDWORD(v53);
    *(_DWORD *)(v53 + 8) = DWORD2(v53);
    *(_QWORD *)(v53 + 16) = *(_QWORD *)((char *)&v53 + 4);
    v85[0] = (encounterGroupRole_t)result->numQueryParms;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&result->stepMoveContactsQueries,
      obj: v85);
    if ( result->numQueryParms >= 0x800u )
      idLib::Error(fmt: "MAX_CLIP_QUERIES");
    __asm { dcbz128   r9, r8 }
    v54 = (int)&result->queryParms[(*p_numQueryParms)++];
    *(float *)v54 = start->x;
    *(float *)(v54 + 4) = start->y;
    *(float *)(v54 + 8) = start->z;
    *(float *)(v54 + 12) = end->x;
    *(float *)(v54 + 16) = end->y;
    v85[0] = a34 + 12;
    z = end->z;
    v85[0] = v54 + 68;
    *(float *)(v54 + 20) = z;
    *(float *)(v54 + 36) = downNormal->x;
    v85[0] = a34 + 24;
    *(float *)(v54 + 40) = downNormal->y;
    v85[0] = v54 + 36;
    v56 = downNormal->z;
    v85[0] = v54 + 80;
    *(float *)(v54 + 44) = v56;
    *(_DWORD *)(v54 + 116) = a32;
    *(float *)(v54 + 48) = stepUp;
    *(float *)(v54 + 52) = stepDown;
    *(float *)(v54 + 56) = *(float *)a34;
    *(float *)(v54 + 60) = *(float *)(a34 + 4);
    *(float *)(v54 + 64) = *(float *)(a34 + 8);
    *(float *)(v54 + 68) = *(float *)(a34 + 12);
    *(float *)(v54 + 72) = *(float *)(a34 + 16);
    *(float *)(v54 + 76) = *(float *)(a34 + 20);
    *(float *)(v54 + 80) = *(float *)(a34 + 24);
    *(float *)(v54 + 84) = *(float *)(a34 + 28);
    *(float *)(v54 + 88) = *(float *)(a34 + 32);
    *(_WORD *)(v54 + 96) = a38;
    *(_DWORD *)(v54 + 92) = a36;
    *(_DWORD *)(v54 + 112) = result->collisionQueryLastAllocedIndex;
    *(_WORD *)(v54 + 98) = (clipModel_0_3 << 15) | 0x7FFF;
    *(_DWORD *)(v54 + 124) = startAxisa;
    *(_QWORD *)&this->world = result->collisionQueryLastAllocedIndex;
  }
  idPLogScope::~idPLogScope(this: &v86);
  return this;
}


// ========================================================================
// $LN62_0
// EA  : 0x8273387C
// RVA : 0x0073387C
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _LN62_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 152));
}


// ========================================================================
// ?SlideMoveInternal@idClip@@AAAXPAUtrace_t@@PAVidClipCollisionQuery@1@ABVidVec3@@22MMPBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x827338A8
// RVA : 0x007338A8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::SlideMoveInternal(
        idClip *this,
        trace_t *result,
        idClip::idClipCollisionQuery *query,
        const idVec3 *start,
        const idVec3 *velocity,
        const idVec3 *gravityVector,
        double stepUp,
        double stepDown,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        int a28,
        int a29,
        idClipModel *a30,
        int a31,
        const idMat3 *a32,
        int a33,
        const idBounds *a34,
        int a35,
        int a36,
        int a37,
        bool clipModel_0_3,
        int a39,
        const idTraceModel **startAxis_0)
{
  float x; // r9
  double v51; // fp3
  double v52; // fp6
  double v53; // fp3
  double v54; // fp29
  double v55; // fp28
  double v56; // fp27
  int num; // r10
  __int64 v79; // r6
  int v81; // r26
  int v84; // r8
  double v88; // fp7
  double v89; // fp4
  double v90; // fp12
  double v91; // fp8
  int v92; // ctr
  int v93; // r11
  const idTraceModel *trm; // r9
  char *v95; // r11
  int i; // ctr
  const idTraceModel **PositionedModelsInternal; // r3
  int v98; // [sp+8h] [-29F8h]
  int v99; // [sp+8h] [-29F8h]
  idPositionedCollisionModel *v100; // [sp+Ch] [-29F4h]
  const idMat3 *v101; // [sp+Ch] [-29F4h]
  int v102; // [sp+10h] [-29F0h]
  int v103; // [sp+10h] [-29F0h]
  int v104; // [sp+14h] [-29ECh]
  const idPositionedCollisionModel *v105; // [sp+14h] [-29ECh]
  int v106; // [sp+18h] [-29E8h]
  int v107; // [sp+18h] [-29E8h]
  int v108; // [sp+1Ch] [-29E4h]
  const char *v109; // [sp+1Ch] [-29E4h]
  int v110; // [sp+20h] [-29E0h]
  int v111; // [sp+20h] [-29E0h]
  int v112; // [sp+24h] [-29DCh]
  int v113; // [sp+24h] [-29DCh]
  int v114; // [sp+28h] [-29D8h]
  int v115; // [sp+28h] [-29D8h]
  int v116; // [sp+2Ch] [-29D4h]
  int v117; // [sp+2Ch] [-29D4h]
  int v118; // [sp+30h] [-29D0h]
  int v119; // [sp+30h] [-29D0h]
  int v120; // [sp+34h] [-29CCh]
  int v121; // [sp+34h] [-29CCh]
  int v122; // [sp+38h] [-29C8h]
  int v123; // [sp+38h] [-29C8h]
  int v124; // [sp+3Ch] [-29C4h]
  int v125; // [sp+3Ch] [-29C4h]
  int v126; // [sp+40h] [-29C0h]
  int v127; // [sp+40h] [-29C0h]
  int v128; // [sp+44h] [-29BCh]
  int v129; // [sp+44h] [-29BCh]
  int v130; // [sp+48h] [-29B8h]
  int v131; // [sp+48h] [-29B8h]
  int v132; // [sp+4Ch] [-29B4h]
  int v133; // [sp+4Ch] [-29B4h]
  int v134; // [sp+50h] [-29B0h]
  int v135; // [sp+50h] [-29B0h]
  int v136; // [sp+58h] [-29A8h]
  int v137; // [sp+58h] [-29A8h]
  int v138; // [sp+60h] [-29A0h]
  int v139; // [sp+60h] [-29A0h]
  int v140; // [sp+68h] [-2998h]
  int v141; // [sp+70h] [-2990h]
  int v142; // [sp+78h] [-2988h]
  int v143; // [sp+80h] [-2980h]
  idBounds v144; // [sp+90h] [-2970h] BYREF
  idCollisionQuery v145; // [sp+A8h] [-2958h] BYREF
  float z; // [sp+B0h] [-2950h]
  const idTraceModel *v147[30]; // [sp+C0h] [-2940h] BYREF
  char v148; // [sp+138h] [-28C8h] BYREF
  idBounds v149[93]; // [sp+140h] [-28C0h] BYREF

  x = gravityVector->x;
  z = gravityVector->z;
  *(float *)&v145.offset = x;
  LODWORD(v145.offset) = LODWORD(gravityVector->y);
  _FP6 = (float)((float)((float)(x * x)
                       + (float)((float)(z * z) + (float)(*((float *)&v145.offset + 1) * *((float *)&v145.offset + 1))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f13 }
  v51 = __frsqrte(_FP4);
  v52 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v51
                                                                                      * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v145.offset + 1) * *((float *)&v145.offset + 1))))
                                                                                              * (float)0.5))
                                                                              * (float)v51)
                                                                      - (float)1.5)
                                                      * (float)v51)
                                              * (float)((float)((float)(x * x)
                                                              + (float)((float)(z * z)
                                                                      + (float)(*((float *)&v145.offset + 1)
                                                                              * *((float *)&v145.offset + 1))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v51
                                                                              * (float)((float)((float)(x * x)
                                                                                              + (float)((float)(z * z) + (float)(*((float *)&v145.offset + 1) * *((float *)&v145.offset + 1))))
                                                                                      * (float)0.5))
                                                                      * (float)v51)
                                                              - (float)1.5)
                                              * (float)v51))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v51
                                                      * (float)((float)((float)(x * x)
                                                                      + (float)((float)(z * z)
                                                                              + (float)(*((float *)&v145.offset + 1)
                                                                                      * *((float *)&v145.offset + 1))))
                                                              * (float)0.5))
                                              * (float)v51)
                                      - (float)1.5)
                      * (float)v51));
  v53 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v51 * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v145.offset + 1) * *((float *)&v145.offset + 1)))) * (float)0.5)) * (float)v51) - (float)1.5)
                                                                                              * (float)v51)
                                                                                      * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v145.offset + 1) * *((float *)&v145.offset + 1))))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v51 * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v145.offset + 1) * *((float *)&v145.offset + 1)))) * (float)0.5)) * (float)v51) - (float)1.5)
                                                                                      * (float)v51))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v51
                                                                                              * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v145.offset + 1) * *((float *)&v145.offset + 1)))) * (float)0.5))
                                                                                      * (float)v51)
                                                                              - (float)1.5)
                                                              * (float)v51))
                                              * (float)((float)((float)(x * x)
                                                              + (float)((float)(z * z)
                                                                      + (float)(*((float *)&v145.offset + 1)
                                                                              * *((float *)&v145.offset + 1))))
                                                      * (float)0.5))
                                      * (float)v52)
                              - (float)1.5)
              * (float)v52);
  v54 = (float)(x * (float)v53);
  v55 = (float)(*((float *)&v145.offset + 1) * (float)v53);
  v56 = (float)(z * (float)v53);
  idBounds::FromTransformedBounds(this: &v144, bounds: &a30->bounds, origin: start, axis: a32);
  _FP1 = (float)((float)v54 * (float)stepDown);
  HIDWORD(v79) = 0x82000000;
  _FP13 = (float)((float)v55 * (float)stepDown);
  _FP12 = (float)((float)v56 * (float)stepDown);
  __asm
  {
    fsel      f10, f1, f0, f1
    fsel      f9, f1, f1, f0
    fsel      f8, f13, f0, f13
  }
  _FP11 = (float)((float)v54 * (float)-stepUp);
  _FP3 = (float)((float)v56 * (float)-stepUp);
  _FP4 = (float)((float)v55 * (float)-stepUp);
  __asm
  {
    fsel      f7, f13, f13, f0
    fsel      f6, f12, f0, f12
    fsel      f5, f12, f12, f0
  }
  _FP2 = gravityVector->x;
  _FP1 = gravityVector->y;
  __asm { fsel      f12, f2, f0, f2 }
  __asm { fsel      f28, f1, f0, f1 }
  __asm { fsel      f2, f2, f2, f0 }
  __asm { fsel      f1, f1, f1, f0 }
  __asm { fsel      f24, f11, f0, f11 }
  __asm { fsel      f11, f11, f11, f0 }
  num = a30->traceModels.num;
  __asm { fsel      f22, f3, f0, f3 }
  LODWORD(v79) = 0;
  __asm { fsel      f3, f3, f3, f0 }
  v81 = 0;
  _FP29 = gravityVector->z;
  __asm { fsel      f23, f4, f0, f4 }
  v84 = 0;
  __asm { fsel      f4, f4, f4, f0 }
  __asm
  {
    fsel      f21, f29, f0, f29
    fsel      f0, f29, f29, f0
  }
  v88 = (float)((float)_FP4 + (float)((float)_FP7 + v144.b[1].y));
  v89 = (float)((float)_FP12 + (float)((float)_FP24 + (float)((float)_FP10 + v144.b[0].x)));
  v90 = (float)((float)_FP28 + (float)((float)_FP23 + (float)((float)_FP8 + v144.b[0].y)));
  v91 = __fsqrts((float)((float)(velocity->z * velocity->z)
                       + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))));
  v144.b[0].x = (float)v89 - (float)((float)v91 + (float)1.0);
  v144.b[0].y = (float)v90 - (float)((float)v91 + (float)1.0);
  v144.b[0].z = (float)((float)_FP21 + (float)((float)_FP22 + (float)((float)_FP6 + v144.b[0].z)))
              - (float)((float)v91 + (float)1.0);
  v144.b[1].x = (float)((float)_FP2 + (float)((float)_FP11 + (float)((float)_FP9 + v144.b[1].x)))
              + (float)((float)v91 + (float)1.0);
  v144.b[1].y = (float)((float)_FP1 + (float)v88) + (float)((float)v91 + (float)1.0);
  v144.b[1].z = (float)((float)_FP0 + (float)((float)_FP3 + (float)((float)_FP5 + v144.b[1].z)))
              + (float)((float)v91 + (float)1.0);
  if ( num > 0 )
  {
    v92 = num;
    v93 = 0;
    v81 = num;
    do
    {
      if ( v84 >= num )
        trm = nullptr;
      else
        trm = a30->clip->traceModelCache->cache.list[a30->traceModels.list[v93]]->trm;
      HIDWORD(v79) = v147;
      ++v84;
      v147[v93++] = trm;
      --v92;
    }
    while ( v92 != 0 );
  }
  v95 = &v148;
  for ( i = 128; i != 0; --i )
  {
    v95 += 80;
    *(_QWORD *)v95 = v79;
  }
  PositionedModelsInternal = (const idTraceModel **)idClip::GetPositionedModelsInternal(
                                                      this,
                                                      v1: v144.b,
                                                      v2: &v144.b[1],
                                                      isLine: false,
                                                      clipMask: (int)a34,
                                                      passEntityNumber: a36,
                                                      passOwnerNumber: a30->ownerNumber,
                                                      physicsId: a30->physicsId,
                                                      bodyMask: v98,
                                                      models: v100,
                                                      maxModels: v102,
                                                      a12: v104,
                                                      a13: v106,
                                                      a14: v108,
                                                      a15: v110,
                                                      a16: v112,
                                                      a17: v114,
                                                      a18: v116,
                                                      a19: v118,
                                                      a20: v120,
                                                      a21: v122,
                                                      a22: v124,
                                                      a23: v126,
                                                      a24: v128,
                                                      a25: v130,
                                                      a26: v132,
                                                      a27: v134,
                                                      a28: a30->bodyMask,
                                                      a29: v136,
                                                      a30: (int)v149,
                                                      a31: v138,
                                                      a32: 128);
  idCollisionModelManager::SlideMove(
    this: (idCollisionModelManager *)&v145,
    result: (idCollisionQuery *)collisionModelManager,
    a3: result,
    start,
    velocity,
    gravityVector,
    stepUp,
    stepDown,
    globalBounds: v149,
    trms: startAxis_0,
    numTrms: v99,
    trmAxis: v101,
    contentMask: v103,
    models: v105,
    numModels: v107,
    userName: v109,
    a17: v111,
    a18: v113,
    a19: v115,
    a20: v117,
    a21: v119,
    a22: v121,
    a23: v123,
    a24: v125,
    a25: v127,
    a26: v129,
    a27: v131,
    a28: v133,
    a29: v135,
    a30: (int)&v144,
    a31: v137,
    a32: v147,
    a33: v139,
    a34: v81,
    a35: v140,
    a36: a32,
    a37: v141,
    globalBounds_0: a34,
    a39: v142,
    trms_0: (const idTraceModel **)v149,
    a41: v143,
    numTrmsa: PositionedModelsInternal);
  if ( query != nullptr )
  {
    idClip::SetupDeferredQuery(
      this,
      query,
      type: QUERY_SUBMITTED_SLIDEMOVE,
      clipModel: a30,
      absBounds: &v144,
      cq: &v145,
      moveClipModel: clipModel_0_3);
  }
  else if ( clipModel_0_3 )
  {
    idClip::MoveClipModel(this, clipModel: a30, result);
  }
}


// ========================================================================
// ?SlideMoveContactsInternal@idClip@@AAAXPAUtrace_t@@PAUcontactsResult_t@@PAVidClipCollisionQuery@1@ABVidVec3@@33MMPBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x82733C40
// RVA : 0x00733C40
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::SlideMoveContactsInternal(
        idClip *this,
        trace_t *result,
        contactsResult_t *contacts,
        idClip::idClipCollisionQuery *query,
        const idVec3 *start,
        const idVec3 *velocity,
        const idBounds *gravityVector,
        double stepUp,
        double stepDown,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        idClipModel *a32,
        int a33,
        const idMat3 *a34,
        int a35,
        const idBounds *a36,
        int a37,
        int a38,
        int a39,
        bool clipModel_0_3,
        int a41,
        const idTraceModel **startAxisa)
{
  float z; // r11
  float x; // r9
  double v55; // fp4
  double v56; // fp8
  double v57; // fp28
  double v58; // fp27
  double v59; // fp26
  int num; // r11
  __int64 v81; // r6
  const idMat3 *v84; // r26
  int v87; // r8
  double v89; // fp13
  double v92; // fp11
  int v93; // ctr
  int v94; // r10
  const idTraceModel *trm; // r9
  char *v96; // r11
  int i; // ctr
  const idTraceModel **PositionedModelsInternal; // r3
  int v99; // [sp+8h] [-2A08h]
  const idTraceModel **v100; // [sp+8h] [-2A08h]
  idPositionedCollisionModel *v101; // [sp+Ch] [-2A04h]
  int v102; // [sp+Ch] [-2A04h]
  int v103; // [sp+10h] [-2A00h]
  const idMat3 *v104; // [sp+10h] [-2A00h]
  int v105; // [sp+14h] [-29FCh]
  int v106; // [sp+14h] [-29FCh]
  int v107; // [sp+18h] [-29F8h]
  const idPositionedCollisionModel *v108; // [sp+18h] [-29F8h]
  int v109; // [sp+1Ch] [-29F4h]
  int v110; // [sp+1Ch] [-29F4h]
  int v111; // [sp+20h] [-29F0h]
  const char *v112; // [sp+20h] [-29F0h]
  int v113; // [sp+24h] [-29ECh]
  int v114; // [sp+24h] [-29ECh]
  int v115; // [sp+28h] [-29E8h]
  int v116; // [sp+28h] [-29E8h]
  int v117; // [sp+2Ch] [-29E4h]
  int v118; // [sp+2Ch] [-29E4h]
  int v119; // [sp+30h] [-29E0h]
  int v120; // [sp+30h] [-29E0h]
  int v121; // [sp+34h] [-29DCh]
  int v122; // [sp+34h] [-29DCh]
  int v123; // [sp+38h] [-29D8h]
  int v124; // [sp+38h] [-29D8h]
  int v125; // [sp+3Ch] [-29D4h]
  int v126; // [sp+3Ch] [-29D4h]
  int v127; // [sp+40h] [-29D0h]
  int v128; // [sp+40h] [-29D0h]
  int v129; // [sp+44h] [-29CCh]
  int v130; // [sp+44h] [-29CCh]
  int v131; // [sp+48h] [-29C8h]
  int v132; // [sp+48h] [-29C8h]
  int v133; // [sp+4Ch] [-29C4h]
  int v134; // [sp+4Ch] [-29C4h]
  int v135; // [sp+50h] [-29C0h]
  int v136; // [sp+50h] [-29C0h]
  int v137; // [sp+54h] [-29BCh]
  int v138; // [sp+58h] [-29B8h]
  int v139; // [sp+58h] [-29B8h]
  int v140; // [sp+60h] [-29B0h]
  int v141; // [sp+60h] [-29B0h]
  int v142; // [sp+68h] [-29A8h]
  int v143; // [sp+70h] [-29A0h]
  int v144; // [sp+78h] [-2998h]
  int v145; // [sp+80h] [-2990h]
  int v146; // [sp+88h] [-2988h]
  idBounds v147; // [sp+A0h] [-2970h] BYREF
  idCollisionQuery v148; // [sp+B8h] [-2958h] BYREF
  float v149; // [sp+C0h] [-2950h]
  const idTraceModel *v150[30]; // [sp+D0h] [-2940h] BYREF
  char v151; // [sp+148h] [-28C8h] BYREF
  const idTraceModel *v152[560]; // [sp+150h] [-28C0h] BYREF

  z = gravityVector->b[0].z;
  x = gravityVector->b[0].x;
  v149 = z;
  *(float *)&v148.offset = x;
  LODWORD(v148.offset) = LODWORD(gravityVector->b[0].y);
  _FP7 = (float)((float)((float)(x * x)
                       + (float)((float)(z * z) + (float)(*((float *)&v148.offset + 1) * *((float *)&v148.offset + 1))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f5, f7, f8, f0 }
  v55 = __frsqrte(_FP5);
  v56 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55
                                                                                      * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v148.offset + 1) * *((float *)&v148.offset + 1))))
                                                                                              * (float)0.5))
                                                                              * (float)v55)
                                                                      - (float)1.5)
                                                      * (float)v55)
                                              * (float)((float)((float)(x * x)
                                                              + (float)((float)(z * z)
                                                                      + (float)(*((float *)&v148.offset + 1)
                                                                              * *((float *)&v148.offset + 1))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v55
                                                                              * (float)((float)((float)(x * x)
                                                                                              + (float)((float)(z * z) + (float)(*((float *)&v148.offset + 1) * *((float *)&v148.offset + 1))))
                                                                                      * (float)0.5))
                                                                      * (float)v55)
                                                              - (float)1.5)
                                              * (float)v55))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v55
                                                      * (float)((float)((float)(x * x)
                                                                      + (float)((float)(z * z)
                                                                              + (float)(*((float *)&v148.offset + 1)
                                                                                      * *((float *)&v148.offset + 1))))
                                                              * (float)0.5))
                                              * (float)v55)
                                      - (float)1.5)
                      * (float)v55));
  v57 = (float)(x
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v148.offset + 1) * *((float *)&v148.offset + 1)))) * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55)
                                                                                              * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v148.offset + 1) * *((float *)&v148.offset + 1)))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v148.offset + 1) * *((float *)&v148.offset + 1)))) * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                              * (float)v55))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v148.offset + 1) * *((float *)&v148.offset + 1)))) * (float)0.5))
                                                                                              * (float)v55)
                                                                                      - (float)1.5)
                                                                      * (float)v55))
                                                      * (float)((float)((float)(x * x)
                                                                      + (float)((float)(z * z)
                                                                              + (float)(*((float *)&v148.offset + 1)
                                                                                      * *((float *)&v148.offset + 1))))
                                                              * (float)0.5))
                                              * (float)v56)
                                      - (float)1.5)
                      * (float)v56));
  v58 = (float)(*((float *)&v148.offset + 1)
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v148.offset + 1) * *((float *)&v148.offset + 1)))) * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55)
                                                                                              * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v148.offset + 1) * *((float *)&v148.offset + 1)))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v148.offset + 1) * *((float *)&v148.offset + 1)))) * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                              * (float)v55))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v148.offset + 1) * *((float *)&v148.offset + 1)))) * (float)0.5))
                                                                                              * (float)v55)
                                                                                      - (float)1.5)
                                                                      * (float)v55))
                                                      * (float)((float)((float)(x * x)
                                                                      + (float)((float)(z * z)
                                                                              + (float)(*((float *)&v148.offset + 1)
                                                                                      * *((float *)&v148.offset + 1))))
                                                              * (float)0.5))
                                              * (float)v56)
                                      - (float)1.5)
                      * (float)v56));
  v59 = (float)(z
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v148.offset + 1) * *((float *)&v148.offset + 1)))) * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55)
                                                                                              * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v148.offset + 1) * *((float *)&v148.offset + 1)))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v148.offset + 1) * *((float *)&v148.offset + 1)))) * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                              * (float)v55))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(*((float *)&v148.offset + 1) * *((float *)&v148.offset + 1)))) * (float)0.5))
                                                                                              * (float)v55)
                                                                                      - (float)1.5)
                                                                      * (float)v55))
                                                      * (float)((float)((float)(x * x)
                                                                      + (float)((float)(z * z)
                                                                              + (float)(*((float *)&v148.offset + 1)
                                                                                      * *((float *)&v148.offset + 1))))
                                                              * (float)0.5))
                                              * (float)v56)
                                      - (float)1.5)
                      * (float)v56));
  idBounds::FromTransformedBounds(this: &v147, bounds: &a32->bounds, origin: start, axis: a34);
  _FP3 = (float)((float)v57 * (float)stepDown);
  HIDWORD(v81) = 0x82000000;
  _FP2 = (float)((float)v58 * (float)stepDown);
  _FP1 = (float)((float)v59 * (float)stepDown);
  __asm
  {
    fsel      f12, f3, f0, f3
    fsel      f11, f3, f3, f0
    fsel      f10, f2, f0, f2
  }
  _FP13 = (float)((float)v57 * (float)-stepUp);
  _FP6 = (float)((float)v58 * (float)-stepUp);
  _FP5 = (float)((float)v59 * (float)-stepUp);
  __asm
  {
    fsel      f8, f1, f0, f1
    fsel      f7, f1, f1, f0
    fsel      f9, f2, f2, f0
  }
  _FP4 = gravityVector->b[0].x;
  _FP3 = gravityVector->b[0].y;
  __asm { fsel      f2, f4, f0, f4 }
  __asm { fsel      f27, f3, f0, f3 }
  __asm { fsel      f4, f4, f4, f0 }
  __asm { fsel      f3, f3, f3, f0 }
  __asm
  {
    fsel      f24, f13, f0, f13
    fsel      f13, f13, f13, f0
  }
  num = a32->traceModels.num;
  LODWORD(v81) = 0;
  __asm { fsel      f22, f5, f0, f5 }
  __asm { fsel      f5, f5, f5, f0 }
  v84 = nullptr;
  _FP28 = gravityVector->b[0].z;
  __asm { fsel      f23, f6, f0, f6 }
  v87 = 0;
  __asm { fsel      f6, f6, f6, f0 }
  v89 = (float)((float)_FP13 + (float)((float)_FP11 + v147.b[1].x));
  __asm
  {
    fsel      f21, f28, f0, f28
    fsel      f0, f28, f28, f0
  }
  v92 = __fsqrts((float)((float)(velocity->z * velocity->z)
                       + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))));
  v147.b[0].x = (float)((float)_FP2 + (float)((float)_FP24 + (float)((float)_FP12 + v147.b[0].x)))
              - (float)((float)v92 + (float)1.5);
  v147.b[1].x = (float)((float)_FP4 + (float)v89) + (float)((float)v92 + (float)1.5);
  v147.b[0].y = (float)((float)_FP27 + (float)((float)_FP23 + (float)((float)_FP10 + v147.b[0].y)))
              - (float)((float)v92 + (float)1.5);
  v147.b[0].z = (float)((float)_FP21 + (float)((float)_FP22 + (float)((float)_FP8 + v147.b[0].z)))
              - (float)((float)v92 + (float)1.5);
  v147.b[1].y = (float)((float)_FP3 + (float)((float)_FP6 + (float)((float)_FP9 + v147.b[1].y)))
              + (float)((float)v92 + (float)1.5);
  v147.b[1].z = (float)((float)_FP0 + (float)((float)_FP5 + (float)((float)_FP7 + v147.b[1].z)))
              + (float)((float)v92 + (float)1.5);
  if ( num > 0 )
  {
    v93 = num;
    v94 = 0;
    v84 = (const idMat3 *)num;
    do
    {
      if ( v87 >= num )
        trm = nullptr;
      else
        trm = a32->clip->traceModelCache->cache.list[a32->traceModels.list[v94]]->trm;
      HIDWORD(v81) = v150;
      ++v87;
      v150[v94++] = trm;
      --v93;
    }
    while ( v93 != 0 );
  }
  v96 = &v151;
  for ( i = 128; i != 0; --i )
  {
    v96 += 80;
    *(_QWORD *)v96 = v81;
  }
  PositionedModelsInternal = (const idTraceModel **)idClip::GetPositionedModelsInternal(
                                                      this,
                                                      v1: v147.b,
                                                      v2: &v147.b[1],
                                                      isLine: false,
                                                      clipMask: (int)a36,
                                                      passEntityNumber: a38,
                                                      passOwnerNumber: a32->ownerNumber,
                                                      physicsId: a32->physicsId,
                                                      bodyMask: v99,
                                                      models: v101,
                                                      maxModels: v103,
                                                      a12: v105,
                                                      a13: v107,
                                                      a14: v109,
                                                      a15: v111,
                                                      a16: v113,
                                                      a17: v115,
                                                      a18: v117,
                                                      a19: v119,
                                                      a20: v121,
                                                      a21: v123,
                                                      a22: v125,
                                                      a23: v127,
                                                      a24: v129,
                                                      a25: v131,
                                                      a26: v133,
                                                      a27: v135,
                                                      a28: a32->bodyMask,
                                                      a29: v138,
                                                      a30: (int)v152,
                                                      a31: v140,
                                                      a32: 128);
  idCollisionModelManager::SlideMoveContacts(
    this: (idCollisionModelManager *)&v148,
    result: (idCollisionQuery *)collisionModelManager,
    a3: result,
    contacts,
    start,
    velocity,
    gravityVector,
    stepUp,
    stepDown,
    globalBounds: startAxisa,
    trms: v100,
    numTrms: v102,
    trmAxis: v104,
    contentMask: v106,
    models: v108,
    numModels: v110,
    userName: v112,
    a18: v114,
    a19: v116,
    a20: v118,
    a21: v120,
    a22: v122,
    a23: v124,
    a24: v126,
    a25: v128,
    a26: v130,
    a27: v132,
    a28: v134,
    a29: v136,
    a30: v137,
    a31: v139,
    a32: (const idTraceModel **)&v147,
    a33: v141,
    a34: v150,
    a35: v142,
    a36: v84,
    a37: v143,
    a38: a34,
    a39: v144,
    globalBounds_0: a36,
    a41: v145,
    trmsa: v152,
    a43: v146,
    numTrmsa: PositionedModelsInternal);
  if ( query != nullptr )
  {
    idClip::SetupDeferredQuery(
      this,
      query,
      type: QUERY_SUBMITTED_SLIDEMOVE_CONTACTS,
      clipModel: a32,
      absBounds: &v147,
      cq: &v148,
      moveClipModel: clipModel_0_3);
  }
  else if ( clipModel_0_3 )
  {
    idClip::MoveClipModel(this, clipModel: a32, result);
  }
}


// ========================================================================
// ?SlideMoveContacts@idClip@@QAA?AVidClipQuery@@PAUtrace_t@@PAUcontactsResult_t@@ABVidVec3@@22MMPBVidClipModel@@ABVidMat3@@HH_NPBD@Z
// EA  : 0x82733FE0
// RVA : 0x00733FE0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

idClip *__fastcall idClip::SlideMoveContacts(
        idClip *this,
        idClip *result,
        trace_t *a3,
        contactsResult_t *contacts,
        const idVec3 *start,
        const idVec3 *velocity,
        const idBounds *gravityVector,
        double stepUp,
        double stepDown,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        bool moveClipModel,
        const char *userName,
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
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        idClipModel *a32,
        int a33,
        int a34,
        int a35,
        const idBounds *a36,
        int a37,
        int a38,
        int a39,
        bool clipModel_0_3,
        int a41,
        const idTraceModel **startAxisa)
{
  unsigned __int64 v48; // r6
  int *p_numQueryParms; // r30
  __int128 v53; // r11
  int v54; // r11
  double z; // fp9
  double v56; // fp6
  __int64 v57; // r9
  const idMat3 *v59; // [sp+8h] [-F8h]
  int v60; // [sp+Ch] [-F4h]
  int v61; // [sp+10h] [-F0h]
  bool v62; // [sp+17h] [-E9h]
  const char *v63; // [sp+18h] [-E8h]
  int v64; // [sp+1Ch] [-E4h]
  int v65; // [sp+20h] [-E0h]
  int v66; // [sp+24h] [-DCh]
  int v67; // [sp+28h] [-D8h]
  int v68; // [sp+2Ch] [-D4h]
  int v69; // [sp+30h] [-D0h]
  int v70; // [sp+34h] [-CCh]
  int v71; // [sp+38h] [-C8h]
  int v72; // [sp+3Ch] [-C4h]
  int v73; // [sp+40h] [-C0h]
  int v74; // [sp+44h] [-BCh]
  int v75; // [sp+48h] [-B8h]
  int v76; // [sp+4Ch] [-B4h]
  int v77; // [sp+50h] [-B0h]
  int v78; // [sp+54h] [-ACh]
  int v79; // [sp+58h] [-A8h]
  int v80; // [sp+60h] [-A0h]
  int v81; // [sp+68h] [-98h]
  int v82; // [sp+70h] [-90h]
  int v83; // [sp+78h] [-88h]
  int v84; // [sp+80h] [-80h]
  encounterGroupRole_t v85[2]; // [sp+90h] [-70h] BYREF
  idPLogScope v86; // [sp+98h] [-68h] BYREF

  LODWORD(v48) = "idClip::SlideMoveContacts";
  HIDWORD(v48) = 1;
  idPLogScope::idPLogScope(this: &v86, pl: &pLog, gMask: v48, label: (const char *)start);
  if ( a3 != nullptr )
  {
    idClip::SlideMoveContactsInternal(
      this: result,
      result: a3,
      contacts,
      query: nullptr,
      start,
      velocity,
      gravityVector,
      stepUp,
      stepDown,
      clipModel: (const idClipModel *)clipModel_0_3,
      startAxis: v59,
      clipMask: v60,
      passEntityNumber: v61,
      moveClipModel: v62,
      userName: v63,
      a16: v64,
      a17: v65,
      a18: v66,
      a19: v67,
      a20: v68,
      a21: v69,
      a22: v70,
      a23: v71,
      a24: v72,
      a25: v73,
      a26: v74,
      a27: v75,
      a28: v76,
      a29: v77,
      a30: v78,
      a31: v79,
      a32,
      a33: v80,
      (const idMat3 *)a34,
      a35: v81,
      a36,
      a37: v82,
      a38,
      a39: v83,
      clipModel_0_3,
      a41: v84,
      startAxisa);
    LODWORD(v57) = 0;
    *(_QWORD *)&this->world = v57;
  }
  else
  {
    p_numQueryParms = &result->numQueryParms;
    *((_QWORD *)&v53 + 1) = result->collisionQueryLastAllocedIndex;
    HIDWORD(v53) = result->numQueryParms;
    LODWORD(v53) = v53 + 1;
    result->collisionQueryLastAllocedIndex = v53;
    LODWORD(v53) = (v53 & 0xFFF) + 11621;
    DWORD1(v53) = 2 * v53;
    LODWORD(v53) = (char *)result + 24 * v53;
    *(_DWORD *)v53 = DWORD2(v53);
    *(_DWORD *)(v53 + 4) = HIDWORD(v53);
    *(_DWORD *)(v53 + 8) = DWORD2(v53);
    *(_QWORD *)(v53 + 16) = *(_QWORD *)((char *)&v53 + 4);
    v85[0] = (encounterGroupRole_t)result->numQueryParms;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&result->slideMoveContactsQueries,
      obj: v85);
    if ( result->numQueryParms >= 0x800u )
      idLib::Error(fmt: "MAX_CLIP_QUERIES");
    __asm { dcbz128   r9, r8 }
    v54 = (int)&result->queryParms[(*p_numQueryParms)++];
    *(float *)v54 = start->x;
    *(float *)(v54 + 4) = start->y;
    *(float *)(v54 + 8) = start->z;
    *(float *)(v54 + 12) = velocity->x;
    *(float *)(v54 + 16) = velocity->y;
    v85[0] = a34 + 12;
    z = velocity->z;
    v85[0] = v54 + 68;
    *(float *)(v54 + 20) = z;
    *(float *)(v54 + 36) = gravityVector->b[0].x;
    v85[0] = a34 + 24;
    *(float *)(v54 + 40) = gravityVector->b[0].y;
    v85[0] = v54 + 36;
    v56 = gravityVector->b[0].z;
    v85[0] = v54 + 80;
    *(float *)(v54 + 44) = v56;
    *(_DWORD *)(v54 + 116) = a32;
    *(float *)(v54 + 48) = stepUp;
    *(float *)(v54 + 52) = stepDown;
    *(float *)(v54 + 56) = *(float *)a34;
    *(float *)(v54 + 60) = *(float *)(a34 + 4);
    *(float *)(v54 + 64) = *(float *)(a34 + 8);
    *(float *)(v54 + 68) = *(float *)(a34 + 12);
    *(float *)(v54 + 72) = *(float *)(a34 + 16);
    *(float *)(v54 + 76) = *(float *)(a34 + 20);
    *(float *)(v54 + 80) = *(float *)(a34 + 24);
    *(float *)(v54 + 84) = *(float *)(a34 + 28);
    *(float *)(v54 + 88) = *(float *)(a34 + 32);
    *(_WORD *)(v54 + 96) = a38;
    *(_DWORD *)(v54 + 92) = a36;
    *(_DWORD *)(v54 + 112) = result->collisionQueryLastAllocedIndex;
    *(_WORD *)(v54 + 98) = (clipModel_0_3 << 15) | 0x7FFF;
    *(_DWORD *)(v54 + 124) = startAxisa;
    *(_QWORD *)&this->world = result->collisionQueryLastAllocedIndex;
  }
  idPLogScope::~idPLogScope(this: &v86);
  return this;
}


// ========================================================================
// $LN62_1
// EA  : 0x8273427C
// RVA : 0x0073427C
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _LN62_1()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 152));
}


// ========================================================================
// ?ContentsInternal@idClip@@AAAXPAUtrace_t@@PAVidClipCollisionQuery@1@ABVidVec3@@PBVidClipModel@@ABVidMat3@@HHPBD@Z
// EA  : 0x827342A8
// RVA : 0x007342A8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::ContentsInternal(
        idClip *this,
        trace_t *result,
        idClip::idClipCollisionQuery *query,
        const idVec3 *start,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        const char *userName)
{
  __int64 v9; // r25
  int v17; // r29
  double x; // fp13
  double y; // fp12
  int ownerNumber; // r9
  double z; // fp11
  int physicsId; // r10
  int bodyMask; // r4
  int num; // r7
  int v25; // r6
  int v26; // ctr
  int v27; // r11
  idTraceModel *trm; // r8
  char *v29; // r11
  int i; // ctr
  int PositionedModelsInternal; // r3
  unsigned __int64 v32; // r11
  int v33; // [sp+8h] [-2968h]
  int v34; // [sp+8h] [-2968h]
  idPositionedCollisionModel *v35; // [sp+Ch] [-2964h]
  const idPositionedCollisionModel *v36; // [sp+Ch] [-2964h]
  int v37; // [sp+10h] [-2960h]
  int v38; // [sp+10h] [-2960h]
  int v39; // [sp+14h] [-295Ch]
  const char *v40; // [sp+14h] [-295Ch]
  int v41; // [sp+18h] [-2958h]
  int v42; // [sp+18h] [-2958h]
  int v43; // [sp+1Ch] [-2954h]
  int v44; // [sp+1Ch] [-2954h]
  int v45; // [sp+20h] [-2950h]
  int v46; // [sp+20h] [-2950h]
  int v47; // [sp+24h] [-294Ch]
  int v48; // [sp+24h] [-294Ch]
  int v49; // [sp+28h] [-2948h]
  int v50; // [sp+28h] [-2948h]
  int v51; // [sp+2Ch] [-2944h]
  int v52; // [sp+2Ch] [-2944h]
  int v53; // [sp+30h] [-2940h]
  int v54; // [sp+30h] [-2940h]
  int v55; // [sp+34h] [-293Ch]
  int v56; // [sp+34h] [-293Ch]
  int v57; // [sp+38h] [-2938h]
  int v58; // [sp+38h] [-2938h]
  int v59; // [sp+3Ch] [-2934h]
  int v60; // [sp+3Ch] [-2934h]
  int v61; // [sp+40h] [-2930h]
  int v62; // [sp+40h] [-2930h]
  int v63; // [sp+44h] [-292Ch]
  int v64; // [sp+44h] [-292Ch]
  int v65; // [sp+48h] [-2928h]
  int v66; // [sp+48h] [-2928h]
  int v67; // [sp+4Ch] [-2924h]
  int v68; // [sp+4Ch] [-2924h]
  int v69; // [sp+50h] [-2920h]
  int v70; // [sp+50h] [-2920h]
  int v71; // [sp+58h] [-2918h]
  int v72; // [sp+58h] [-2918h]
  int v73; // [sp+60h] [-2910h]
  int v74; // [sp+60h] [-2910h]
  idBounds v75; // [sp+70h] [-2900h] BYREF
  __int64 v76; // [sp+88h] [-28E8h] BYREF
  const idTraceModel *v77[30]; // [sp+90h] [-28E0h] BYREF
  char v78; // [sp+108h] [-2868h] BYREF
  _BYTE v79[2144]; // [sp+110h] [-2860h] BYREF

  LODWORD(v9) = 0;
  HIDWORD(v9) = this;
  v17 = 0;
  if ( clipModel != nullptr )
  {
    idBounds::FromTransformedBounds(this: &v75, bounds: &clipModel->bounds, origin: start, axis: startAxis);
    num = clipModel->traceModels.num;
    ownerNumber = clipModel->ownerNumber;
    physicsId = clipModel->physicsId;
    bodyMask = clipModel->bodyMask;
    v25 = 0;
    v75.b[0].x = v75.b[0].x - (float)1.0;
    v75.b[0].y = v75.b[0].y - (float)1.0;
    v75.b[0].z = v75.b[0].z - (float)1.0;
    v75.b[1].x = v75.b[1].x + (float)1.0;
    v75.b[1].y = v75.b[1].y + (float)1.0;
    v75.b[1].z = v75.b[1].z + (float)1.0;
    if ( num > 0 )
    {
      v26 = num;
      v27 = 0;
      v17 = num;
      do
      {
        if ( v25 >= num )
          trm = nullptr;
        else
          trm = clipModel->clip->traceModelCache->cache.list[clipModel->traceModels.list[v27]]->trm;
        ++v25;
        v77[v27++] = trm;
        --v26;
      }
      while ( v26 != 0 );
    }
  }
  else
  {
    x = start->x;
    y = start->y;
    ownerNumber = 0x1FFF;
    z = start->z;
    physicsId = -1;
    bodyMask = 0;
    v17 = 1;
    v75.b[0].x = start->x - (float)1.0;
    v77[0] = nullptr;
    v75.b[0].y = (float)y - (float)1.0;
    v75.b[0].z = (float)z - (float)1.0;
    v75.b[1].x = (float)x + (float)1.0;
    v75.b[1].y = (float)y + (float)1.0;
    v75.b[1].z = (float)z + (float)1.0;
  }
  v29 = &v78;
  for ( i = 128; i != 0; --i )
  {
    v29 += 80;
    *(_QWORD *)v29 = v9;
  }
  PositionedModelsInternal = idClip::GetPositionedModelsInternal(
                               this: (idClip *)HIDWORD(v9),
                               v1: v75.b,
                               v2: &v75.b[1],
                               isLine: false,
                               clipMask,
                               passEntityNumber,
                               passOwnerNumber: ownerNumber,
                               physicsId,
                               bodyMask: v33,
                               models: v35,
                               maxModels: v37,
                               a12: v39,
                               a13: v41,
                               a14: v43,
                               a15: v45,
                               a16: v47,
                               a17: v49,
                               a18: v51,
                               a19: v53,
                               a20: v55,
                               a21: v57,
                               a22: v59,
                               a23: v61,
                               a24: v63,
                               a25: v65,
                               a26: v67,
                               a27: v69,
                               a28: bodyMask,
                               a29: v71,
                               a30: (int)v79,
                               a31: v73,
                               a32: 128);
  idCollisionModelManager::Contents(
    this: (idCollisionModelManager *)&v76,
    result: (idCollisionQuery *)collisionModelManager,
    a3: result,
    start,
    globalBounds: &v75,
    trms: v77,
    numTrms: v17,
    trmAxis: startAxis,
    contentMask: v34,
    models: v36,
    numModels: v38,
    userName: v40,
    a13: v42,
    a14: v44,
    a15: v46,
    a16: v48,
    a17: v50,
    a18: v52,
    a19: v54,
    a20: v56,
    a21: v58,
    a22: v60,
    a23: v62,
    a24: v64,
    a25: v66,
    a26: v68,
    a27: v70,
    a28: clipMask,
    a29: v72,
    a30: (int)v79,
    a31: v74,
    a32: PositionedModelsInternal);
  if ( query != nullptr )
  {
    v32 = (unsigned int)v76 | 0xA00000000LL;
    query->clipModel = nullptr;
    query->type = QUERY_SUBMITTED_CONTENTS;
    query->query.offset = v32;
  }
}


// ========================================================================
// ?Contents@idClip@@QAA?AVidClipQuery@@PAUtrace_t@@ABVidVec3@@PBVidClipModel@@ABVidMat3@@HHPBD@Z
// EA  : 0x827344D0
// RVA : 0x007344D0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

idClip *__fastcall idClip::Contents(
        idClip *this,
        idClip *result,
        trace_t *a3,
        const idVec3 *start,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        const char *userName,
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
        int a27,
        int a28)
{
  unsigned __int64 v33; // r6
  int *p_numQueryParms; // r28
  __int128 v38; // r11
  int v39; // r3
  int v40; // r11
  double z; // fp12
  double x; // fp11
  __int64 v43; // r10
  const char *v45; // [sp+8h] [-C8h]
  idVec3 *numQueryParms; // [sp+60h] [-70h] BYREF
  idPLogScope v47[13]; // [sp+68h] [-68h] BYREF

  LODWORD(v33) = "idClip::Contents";
  HIDWORD(v33) = 1;
  idPLogScope::idPLogScope(this: v47, pl: &pLog, gMask: v33, label: (const char *)clipModel);
  if ( a3 != nullptr )
  {
    idClip::ContentsInternal(
      this: result,
      result: a3,
      query: nullptr,
      start,
      clipModel,
      startAxis,
      clipMask,
      passEntityNumber,
      userName: v45);
    LODWORD(v43) = 0;
    *(_QWORD *)&this->world = v43;
  }
  else
  {
    p_numQueryParms = &result->numQueryParms;
    *((_QWORD *)&v38 + 1) = result->collisionQueryLastAllocedIndex;
    HIDWORD(v38) = result->numQueryParms;
    LODWORD(v38) = v38 + 1;
    result->collisionQueryLastAllocedIndex = v38;
    LODWORD(v38) = (v38 & 0xFFF) + 11621;
    DWORD1(v38) = 2 * v38;
    LODWORD(v38) = (char *)result + 24 * v38;
    *(_DWORD *)v38 = DWORD2(v38);
    *(_DWORD *)(v38 + 4) = HIDWORD(v38);
    *(_DWORD *)(v38 + 8) = DWORD2(v38);
    *(_QWORD *)(v38 + 16) = *(_QWORD *)((char *)&v38 + 4);
    numQueryParms = (idVec3 *)result->numQueryParms;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&result->contentsQueries,
      obj: (const encounterGroupRole_t *)&numQueryParms);
    if ( result->numQueryParms >= 0x800u )
      idLib::Error(fmt: "MAX_CLIP_QUERIES");
    __asm { dcbz128   r9, r8 }
    v39 = *p_numQueryParms + 1;
    v40 = (int)&result->queryParms[*p_numQueryParms];
    numQueryParms = &startAxis->mat[2];
    *p_numQueryParms = v39;
    *(float *)v40 = start->x;
    *(float *)(v40 + 4) = start->y;
    z = start->z;
    *(_DWORD *)(v40 + 116) = clipModel;
    *(float *)(v40 + 8) = z;
    numQueryParms = (idVec3 *)(v40 + 68);
    x = startAxis->mat[0].x;
    numQueryParms = (idVec3 *)(v40 + 80);
    *(float *)(v40 + 56) = x;
    *(float *)(v40 + 60) = startAxis->mat[0].y;
    *(float *)(v40 + 64) = startAxis->mat[0].z;
    *(float *)(v40 + 68) = startAxis->mat[1].x;
    *(float *)(v40 + 72) = startAxis->mat[1].y;
    *(float *)(v40 + 76) = startAxis->mat[1].z;
    *(float *)(v40 + 80) = startAxis->mat[2].x;
    *(float *)(v40 + 84) = startAxis->mat[2].y;
    *(float *)(v40 + 88) = startAxis->mat[2].z;
    *(_WORD *)(v40 + 96) = passEntityNumber;
    *(_DWORD *)(v40 + 92) = clipMask;
    *(_DWORD *)(v40 + 112) = result->collisionQueryLastAllocedIndex;
    *(_DWORD *)(v40 + 124) = a28;
    *(_QWORD *)&this->world = result->collisionQueryLastAllocedIndex;
  }
  idPLogScope::~idPLogScope(this: v47);
  return this;
}


// ========================================================================
// $LN48_0
// EA  : 0x827346C0
// RVA : 0x007346C0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _LN48_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 104));
}


// ========================================================================
// ?LocalContentsInternal@idClip@@AAAXHPAVidClipCollisionQuery@1@ABVidVec3@@PBVidClipModel@@ABVidMat3@@HHPBD@Z
// EA  : 0x827346E8
// RVA : 0x007346E8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::LocalContentsInternal(
        idClip *this,
        int parmIndex,
        idClip::idClipCollisionQuery *query,
        const idVec3 *start,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        const char *userName)
{
  __int64 v9; // r18
  idClip::idClipQueryParms *v14; // r26
  int ownerNumber; // r29
  int v19; // r24
  int physicsId; // r28
  int bodyMask; // r27
  idClip::idClipCollisionQuery *v22; // r23
  double x; // fp0
  double y; // fp13
  double z; // fp12
  int num; // r9
  int v27; // r8
  int v28; // ctr
  int v29; // r11
  idTraceModel *trm; // r10
  char *v31; // r11
  int i; // ctr
  unsigned __int64 v33; // r11
  int v34; // [sp+8h] [-29A8h]
  int v35; // [sp+8h] [-29A8h]
  idPositionedCollisionModel *v36; // [sp+Ch] [-29A4h]
  const idPositionedCollisionModel *v37; // [sp+Ch] [-29A4h]
  int v38; // [sp+10h] [-29A0h]
  int v39; // [sp+10h] [-29A0h]
  int v40; // [sp+14h] [-299Ch]
  const char *v41; // [sp+14h] [-299Ch]
  int v42; // [sp+18h] [-2998h]
  int v43; // [sp+1Ch] [-2994h]
  int v44; // [sp+20h] [-2990h]
  int v45; // [sp+24h] [-298Ch]
  int v46; // [sp+28h] [-2988h]
  int v47; // [sp+2Ch] [-2984h]
  int v48; // [sp+30h] [-2980h]
  int v49; // [sp+34h] [-297Ch]
  int v50; // [sp+38h] [-2978h]
  int v51; // [sp+3Ch] [-2974h]
  int v52; // [sp+40h] [-2970h]
  int v53; // [sp+44h] [-296Ch]
  int v54; // [sp+48h] [-2968h]
  int v55; // [sp+4Ch] [-2964h]
  int v56; // [sp+50h] [-2960h]
  int v57; // [sp+58h] [-2958h]
  int v58; // [sp+60h] [-2950h]
  idBounds v59; // [sp+70h] [-2940h] BYREF
  __int64 v60; // [sp+88h] [-2928h] BYREF
  idBounds v61; // [sp+90h] [-2920h] BYREF
  const idTraceModel *v62[30]; // [sp+B0h] [-2900h] BYREF
  char v63; // [sp+128h] [-2888h] BYREF
  _BYTE v64[2176]; // [sp+130h] [-2880h] BYREF

  LODWORD(v9) = 0;
  v14 = &this->queryParms[parmIndex];
  ownerNumber = 0x1FFF;
  v19 = 0;
  physicsId = -1;
  bodyMask = 0;
  v22 = &this->collisionQueries[v14->queryIndex & 0xFFF];
  if ( clipModel != nullptr )
  {
    idBounds::FromTransformedBounds(this: &v59, bounds: &clipModel->bounds, origin: start, axis: startAxis);
    num = clipModel->traceModels.num;
    v27 = 0;
    if ( num > 0 )
    {
      v28 = clipModel->traceModels.num;
      v29 = 0;
      v19 = v28;
      do
      {
        if ( v27 >= num )
          trm = nullptr;
        else
          trm = clipModel->clip->traceModelCache->cache.list[clipModel->traceModels.list[v29]]->trm;
        ++v27;
        v62[v29++] = trm;
        --v28;
      }
      while ( v28 != 0 );
    }
    ownerNumber = clipModel->ownerNumber;
    physicsId = clipModel->physicsId;
    bodyMask = clipModel->bodyMask;
  }
  else
  {
    x = start->x;
    v19 = 1;
    y = start->y;
    v62[0] = nullptr;
    z = start->z;
    v59.b[0].x = x;
    v59.b[0].y = y;
    v59.b[0].z = z;
    v59.b[1].x = x;
    v59.b[1].y = y;
    v59.b[1].z = z;
  }
  idClip::TraceBoundsFromLocalSpaceBounds(this, traceBounds: &v61, localBounds: &v59, type: v22->type, parms: v14);
  v31 = &v63;
  for ( i = 128; i != 0; --i )
  {
    v31 += 80;
    *(_QWORD *)v31 = v9;
  }
  idClip::GetPositionedModelsInternal(
    this,
    v1: v61.b,
    v2: &v61.b[1],
    isLine: false,
    clipMask,
    passEntityNumber,
    passOwnerNumber: ownerNumber,
    physicsId,
    bodyMask: v34,
    models: v36,
    maxModels: v38,
    a12: v40,
    a13: v42,
    a14: v43,
    a15: v44,
    a16: v45,
    a17: v46,
    a18: v47,
    a19: v48,
    a20: v49,
    a21: v50,
    a22: v51,
    a23: v52,
    a24: v53,
    a25: v54,
    a26: v55,
    a27: v56,
    a28: bodyMask,
    a29: v57,
    a30: (int)v64,
    a31: v58,
    a32: 128);
  idCollisionModelManager::LocalContents(
    this: (idCollisionModelManager *)&v60,
    result: (idCollisionQuery *)collisionModelManager,
    localSpace: (idCollisionQuery *)v22->query.offset,
    start,
    globalBounds: &v61,
    trms: v62,
    numTrms: v19,
    trmAxis: startAxis,
    contentMask: v35,
    models: v37,
    numModels: v39,
    userName: v41);
  if ( query != nullptr )
  {
    v33 = (unsigned int)v60 | 0xA00000000LL;
    query->clipModel = nullptr;
    query->type = QUERY_SUBMITTED_CONTENTS;
    query->query.offset = v33;
  }
}


// ========================================================================
// ?ContactsInternal@idClip@@AAAXPAUcontactsResult_t@@PAVidClipCollisionQuery@1@ABVidVec3@@2MPBVidClipModel@@ABVidMat3@@HHPBD@Z
// EA  : 0x827348E8
// RVA : 0x007348E8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __fastcall idClip::ContactsInternal(
        idClip *this,
        contactsResult_t *result,
        idClip::idClipCollisionQuery *query,
        const idVec3 *start,
        const idVec3 *dir,
        double depth,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        const idMat3 *clipMask,
        const int passEntityNumber,
        const char *userName,
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
        int a27,
        int a28,
        const idBounds *a29,
        int a30,
        int a31)
{
  __int64 v32; // r26
  int v39; // r29
  float y; // r9
  float v41; // r10
  int y_low; // r4
  double v43; // fp13
  double v44; // fp12
  double v45; // fp11
  double v46; // fp10
  double v47; // fp9
  double v48; // fp0
  float z; // r7
  int v50; // r6
  float v51; // ctr
  int v52; // r11
  int v53; // r8
  char *v54; // r11
  int i; // ctr
  int PositionedModelsInternal; // r3
  const idBounds *v57; // r8
  unsigned __int64 v58; // r11
  int v59; // [sp+8h] [-2978h]
  const idMat3 *v60; // [sp+8h] [-2978h]
  idPositionedCollisionModel *v61; // [sp+Ch] [-2974h]
  int v62; // [sp+Ch] [-2974h]
  int v63; // [sp+10h] [-2970h]
  const idPositionedCollisionModel *v64; // [sp+10h] [-2970h]
  int v65; // [sp+14h] [-296Ch]
  int v66; // [sp+14h] [-296Ch]
  int v67; // [sp+18h] [-2968h]
  const char *v68; // [sp+18h] [-2968h]
  int v69; // [sp+1Ch] [-2964h]
  int v70; // [sp+1Ch] [-2964h]
  int v71; // [sp+20h] [-2960h]
  int v72; // [sp+20h] [-2960h]
  int v73; // [sp+24h] [-295Ch]
  int v74; // [sp+24h] [-295Ch]
  int v75; // [sp+28h] [-2958h]
  int v76; // [sp+28h] [-2958h]
  int v77; // [sp+2Ch] [-2954h]
  int v78; // [sp+2Ch] [-2954h]
  int v79; // [sp+30h] [-2950h]
  int v80; // [sp+30h] [-2950h]
  int v81; // [sp+34h] [-294Ch]
  int v82; // [sp+34h] [-294Ch]
  int v83; // [sp+38h] [-2948h]
  int v84; // [sp+38h] [-2948h]
  int v85; // [sp+3Ch] [-2944h]
  int v86; // [sp+3Ch] [-2944h]
  int v87; // [sp+40h] [-2940h]
  int v88; // [sp+40h] [-2940h]
  int v89; // [sp+44h] [-293Ch]
  int v90; // [sp+44h] [-293Ch]
  int v91; // [sp+48h] [-2938h]
  int v92; // [sp+48h] [-2938h]
  int v93; // [sp+4Ch] [-2934h]
  int v94; // [sp+4Ch] [-2934h]
  int v95; // [sp+50h] [-2930h]
  int v96; // [sp+50h] [-2930h]
  int v97; // [sp+58h] [-2928h]
  int v98; // [sp+58h] [-2928h]
  int v99; // [sp+60h] [-2920h]
  int v100; // [sp+60h] [-2920h]
  int v101; // [sp+68h] [-2918h]
  int v102; // [sp+70h] [-2910h]
  idBounds v103; // [sp+80h] [-2900h] BYREF
  __int64 v104; // [sp+98h] [-28E8h] BYREF
  _DWORD v105[30]; // [sp+A0h] [-28E0h] BYREF
  char v106; // [sp+118h] [-2868h] BYREF
  _BYTE v107[2144]; // [sp+120h] [-2860h] BYREF

  LODWORD(v32) = 0;
  HIDWORD(v32) = this;
  v39 = 0;
  if ( startAxis != nullptr )
  {
    idBounds::FromTransformedBounds(
      this: &v103,
      bounds: (const idBounds *)&startAxis[2].mat[0].z,
      origin: start,
      axis: clipMask);
    z = startAxis[3].mat[2].z;
    y = startAxis->mat[1].y;
    v41 = startAxis->mat[1].z;
    y_low = LODWORD(startAxis->mat[2].y);
    v50 = 0;
    v43 = (float)(v103.b[0].x - (float)1.0);
    v44 = (float)(v103.b[0].y - (float)1.0);
    v45 = (float)(v103.b[0].z - (float)1.0);
    v103.b[0].x = v103.b[0].x - (float)1.0;
    v46 = (float)(v103.b[1].x + (float)1.0);
    v103.b[0].y = v103.b[0].y - (float)1.0;
    v47 = (float)(v103.b[1].y + (float)1.0);
    v103.b[0].z = v103.b[0].z - (float)1.0;
    v48 = (float)(v103.b[1].z + (float)1.0);
    v103.b[1].x = v103.b[1].x + (float)1.0;
    v103.b[1].y = v103.b[1].y + (float)1.0;
    v103.b[1].z = v103.b[1].z + (float)1.0;
    if ( SLODWORD(z) > 0 )
    {
      v51 = z;
      v52 = 0;
      v39 = LODWORD(z);
      do
      {
        if ( v50 >= SLODWORD(z) )
          v53 = 0;
        else
          v53 = **(_DWORD **)(4 * *(_DWORD *)(LODWORD(startAxis[3].mat[2].y) + v52 * 4)
                            + *(_DWORD *)(*(_DWORD *)(LODWORD(startAxis[4].mat[1].x) + 163956) + 52));
        ++v50;
        v105[v52++] = v53;
        --LODWORD(v51);
      }
      while ( v51 != 0.0 );
    }
  }
  else
  {
    LODWORD(y) = 0x1FFF;
    v41 = NAN;
    y_low = 0;
    v39 = 1;
    v43 = (float)(start->x - (float)1.0);
    v44 = (float)(start->y - (float)1.0);
    v45 = (float)(start->z - (float)1.0);
    v46 = (float)(start->x + (float)1.0);
    v47 = (float)(start->y + (float)1.0);
    v48 = (float)(start->z + (float)1.0);
    v105[0] = 0;
  }
  v54 = &v106;
  v103.b[0].x = (float)v43 - (float)depth;
  v103.b[0].y = (float)v44 - (float)depth;
  v103.b[0].z = (float)v45 - (float)depth;
  v103.b[1].x = (float)v46 + (float)depth;
  v103.b[1].y = (float)v47 + (float)depth;
  v103.b[1].z = (float)v48 + (float)depth;
  for ( i = 128; i != 0; --i )
  {
    v54 += 80;
    *(_QWORD *)v54 = v32;
  }
  PositionedModelsInternal = idClip::GetPositionedModelsInternal(
                               this: (idClip *)HIDWORD(v32),
                               v1: v103.b,
                               v2: &v103.b[1],
                               isLine: false,
                               clipMask: (int)a29,
                               passEntityNumber: a31,
                               passOwnerNumber: SLODWORD(y),
                               physicsId: SLODWORD(v41),
                               bodyMask: v59,
                               models: v61,
                               maxModels: v63,
                               a12: v65,
                               a13: v67,
                               a14: v69,
                               a15: v71,
                               a16: v73,
                               a17: v75,
                               a18: v77,
                               a19: v79,
                               a20: v81,
                               a21: v83,
                               a22: v85,
                               a23: v87,
                               a24: v89,
                               a25: v91,
                               a26: v93,
                               a27: v95,
                               a28: y_low,
                               a29: v97,
                               a30: (int)v107,
                               a31: v99,
                               a32: 128);
  idCollisionModelManager::Contacts(
    this: (idCollisionModelManager *)&v104,
    result: (idCollisionQuery *)collisionModelManager,
    a3: result,
    start,
    dir,
    depth,
    globalBounds: v57,
    trms: (const idTraceModel **)&v103,
    a9: (const int)v105,
    trmAxis: v60,
    contentMask: v62,
    models: v64,
    numModels: v66,
    userName: v68,
    a15: v70,
    a16: v72,
    a17: v74,
    a18: v76,
    a19: v78,
    a20: v80,
    a21: v82,
    a22: v84,
    a23: v86,
    a24: v88,
    a25: v90,
    a26: v92,
    a27: v94,
    a28: v96,
    a29: (const idMat3 *)v39,
    a30: v98,
    a31: (int)clipMask,
    a32: v100,
    a33: a29,
    a34: v101,
    a35: (int)v107,
    a36: v102,
    numTrms_0: PositionedModelsInternal);
  if ( query != nullptr )
  {
    v58 = (unsigned int)v104 | 0xB00000000LL;
    query->clipModel = nullptr;
    query->type = QUERY_SUBMITTED_CONTACTS;
    query->query.offset = v58;
  }
}


// ========================================================================
// ?Contacts@idClip@@QAA?AVidClipQuery@@PAUcontactsResult_t@@ABVidVec3@@1MPBVidClipModel@@ABVidMat3@@HHPBD@Z
// EA  : 0x82734B40
// RVA : 0x00734B40
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

idClip *__fastcall idClip::Contacts(
        idClip *this,
        idClip *result,
        contactsResult_t *a3,
        const idVec3 *start,
        const idVec3 *dir,
        double depth,
        const idClipModel *clipModel,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        const char *userName,
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
        int a27,
        int a28,
        const idBounds *a29,
        int a30,
        const idClipModel *a31,
        int a32,
        int a33)
{
  unsigned __int64 v39; // r6
  int *p_numQueryParms; // r29
  __int128 v43; // r11
  int v44; // r11
  double x; // fp0
  double y; // fp10
  __int64 v47; // r7
  int v49; // [sp+8h] [-D8h]
  const char *v50; // [sp+Ch] [-D4h]
  int v51; // [sp+10h] [-D0h]
  int v52; // [sp+14h] [-CCh]
  int v53; // [sp+18h] [-C8h]
  int v54; // [sp+1Ch] [-C4h]
  int v55; // [sp+20h] [-C0h]
  int v56; // [sp+24h] [-BCh]
  int v57; // [sp+28h] [-B8h]
  int v58; // [sp+2Ch] [-B4h]
  int v59; // [sp+30h] [-B0h]
  int v60; // [sp+34h] [-ACh]
  int v61; // [sp+38h] [-A8h]
  int v62; // [sp+3Ch] [-A4h]
  int v63; // [sp+40h] [-A0h]
  int v64; // [sp+44h] [-9Ch]
  int v65; // [sp+48h] [-98h]
  int v66; // [sp+4Ch] [-94h]
  int v67; // [sp+50h] [-90h]
  int v68; // [sp+58h] [-88h]
  encounterGroupRole_t v69[2]; // [sp+70h] [-70h] BYREF
  idPLogScope v70[2]; // [sp+78h] [-68h] BYREF

  LODWORD(v39) = "idClip::Contacts";
  HIDWORD(v39) = 1;
  idPLogScope::idPLogScope(this: v70, pl: &pLog, gMask: v39, label: (const char *)dir);
  if ( a3 != nullptr )
  {
    idClip::ContactsInternal(
      this: result,
      result: a3,
      query: nullptr,
      start,
      dir,
      depth,
      clipModel: a31,
      startAxis,
      (const idMat3 *)clipMask,
      passEntityNumber: v49,
      userName: v50,
      a12: v51,
      a13: v52,
      a14: v53,
      a15: v54,
      a16: v55,
      a17: v56,
      a18: v57,
      a19: v58,
      a20: v59,
      a21: v60,
      a22: v61,
      a23: v62,
      a24: v63,
      a25: v64,
      a26: v65,
      a27: v66,
      a28: v67,
      a29,
      a30: v68,
      (int)a31);
    LODWORD(v47) = 0;
    *(_QWORD *)&this->world = v47;
  }
  else
  {
    p_numQueryParms = &result->numQueryParms;
    *((_QWORD *)&v43 + 1) = result->collisionQueryLastAllocedIndex;
    HIDWORD(v43) = result->numQueryParms;
    LODWORD(v43) = v43 + 1;
    result->collisionQueryLastAllocedIndex = v43;
    LODWORD(v43) = (v43 & 0xFFF) + 11621;
    DWORD1(v43) = 2 * v43;
    LODWORD(v43) = (char *)result + 24 * v43;
    *(_DWORD *)v43 = DWORD2(v43);
    *(_DWORD *)(v43 + 4) = HIDWORD(v43);
    *(_DWORD *)(v43 + 8) = DWORD2(v43);
    *(_QWORD *)(v43 + 16) = *(_QWORD *)((char *)&v43 + 4);
    v69[0] = (encounterGroupRole_t)result->numQueryParms;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&result->contactsQueries,
      obj: v69);
    if ( result->numQueryParms >= 0x800u )
      idLib::Error(fmt: "MAX_CLIP_QUERIES");
    __asm { dcbz128   r9, r8 }
    v44 = (int)&result->queryParms[(*p_numQueryParms)++];
    x = start->x;
    v69[0] = clipMask + 12;
    *(float *)v44 = x;
    *(float *)(v44 + 4) = start->y;
    *(float *)(v44 + 8) = start->z;
    v69[0] = clipMask + 24;
    *(float *)(v44 + 36) = dir->x;
    v69[0] = v44 + 36;
    y = dir->y;
    v69[0] = v44 + 80;
    *(float *)(v44 + 40) = y;
    *(float *)(v44 + 44) = dir->z;
    *(_DWORD *)(v44 + 116) = startAxis;
    *(float *)(v44 + 52) = depth;
    *(float *)(v44 + 56) = *(float *)clipMask;
    *(float *)(v44 + 60) = *(float *)(clipMask + 4);
    *(float *)(v44 + 64) = *(float *)(clipMask + 8);
    *(float *)(v44 + 68) = *(float *)(clipMask + 12);
    *(float *)(v44 + 72) = *(float *)(clipMask + 16);
    *(float *)(v44 + 76) = *(float *)(clipMask + 20);
    *(float *)(v44 + 80) = *(float *)(clipMask + 24);
    *(float *)(v44 + 84) = *(float *)(clipMask + 28);
    *(float *)(v44 + 88) = *(float *)(clipMask + 32);
    *(_WORD *)(v44 + 96) = (_WORD)a31;
    *(_DWORD *)(v44 + 92) = a29;
    *(_DWORD *)(v44 + 112) = result->collisionQueryLastAllocedIndex;
    *(_DWORD *)(v44 + 124) = a33;
    *(_QWORD *)&this->world = result->collisionQueryLastAllocedIndex;
  }
  idPLogScope::~idPLogScope(this: v70);
  return this;
}


// ========================================================================
// $LN54_0
// EA  : 0x82734D74
// RVA : 0x00734D74
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _LN54_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 120));
}


// ========================================================================
// ?ClipInternal@idClip@@AAAXPAUclipResult_t@@PAVidClipCollisionQuery@1@ABVidVec3@@PBVidTraceModel@@ABVidMat3@@HHPBD@Z
// EA  : 0x82734DA0
// RVA : 0x00734DA0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idClip::ClipInternal(
        idClip *this,
        clipResult_t *result,
        idClip::idClipCollisionQuery *query,
        const idVec3 *start,
        const idTraceModel *trm,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        const char *userName)
{
  char *v17; // r10
  int v18; // r31 OVERLAPPED
  int i; // ctr
  int PositionedModelsInternal; // r3
  unsigned __int64 v21; // r11
  int v22; // [sp+8h] [-28E8h]
  int v23; // [sp+8h] [-28E8h]
  idPositionedCollisionModel *v24; // [sp+Ch] [-28E4h]
  const idPositionedCollisionModel *v25; // [sp+Ch] [-28E4h]
  int v26; // [sp+10h] [-28E0h]
  int v27; // [sp+10h] [-28E0h]
  int v28; // [sp+14h] [-28DCh]
  const char *v29; // [sp+14h] [-28DCh]
  int v30; // [sp+18h] [-28D8h]
  int v31; // [sp+18h] [-28D8h]
  int v32; // [sp+1Ch] [-28D4h]
  int v33; // [sp+1Ch] [-28D4h]
  int v34; // [sp+20h] [-28D0h]
  int v35; // [sp+20h] [-28D0h]
  int v36; // [sp+24h] [-28CCh]
  int v37; // [sp+24h] [-28CCh]
  int v38; // [sp+28h] [-28C8h]
  int v39; // [sp+28h] [-28C8h]
  int v40; // [sp+2Ch] [-28C4h]
  int v41; // [sp+2Ch] [-28C4h]
  int v42; // [sp+30h] [-28C0h]
  int v43; // [sp+30h] [-28C0h]
  int v44; // [sp+34h] [-28BCh]
  int v45; // [sp+34h] [-28BCh]
  int v46; // [sp+38h] [-28B8h]
  int v47; // [sp+38h] [-28B8h]
  int v48; // [sp+3Ch] [-28B4h]
  int v49; // [sp+3Ch] [-28B4h]
  int v50; // [sp+40h] [-28B0h]
  int v51; // [sp+40h] [-28B0h]
  int v52; // [sp+44h] [-28ACh]
  int v53; // [sp+44h] [-28ACh]
  int v54; // [sp+48h] [-28A8h]
  int v55; // [sp+48h] [-28A8h]
  int v56; // [sp+4Ch] [-28A4h]
  int v57; // [sp+4Ch] [-28A4h]
  int v58; // [sp+50h] [-28A0h]
  int v59; // [sp+50h] [-28A0h]
  int v60; // [sp+58h] [-2898h]
  int v61; // [sp+58h] [-2898h]
  int v62; // [sp+60h] [-2890h]
  int v63; // [sp+60h] [-2890h]
  idBounds v64; // [sp+70h] [-2880h] BYREF
  const idTraceModel *v65; // [sp+88h] [-2868h] BYREF
  __int64 v66; // [sp+90h] [-2860h] BYREF
  char v67; // [sp+98h] [-2858h] BYREF
  _BYTE v68[2128]; // [sp+A0h] [-2850h] BYREF

  idBounds::FromTransformedBounds(this: &v64, bounds: &trm->bounds, origin: start, axis: startAxis);
  v17 = &v67;
  v65 = trm;
  v18 = 0;
  v64.b[0].x = v64.b[0].x - (float)1.0;
  v64.b[0].y = v64.b[0].y - (float)1.0;
  v64.b[0].z = v64.b[0].z - (float)1.0;
  v64.b[1].x = v64.b[1].x + (float)1.0;
  v64.b[1].y = v64.b[1].y + (float)1.0;
  v64.b[1].z = v64.b[1].z + (float)1.0;
  for ( i = 128; i != 0; --i )
  {
    v17 += 80;
    *(_QWORD *)v17 = *(_QWORD *)&v18;
  }
  PositionedModelsInternal = idClip::GetPositionedModelsInternal(
                               this,
                               v1: v64.b,
                               v2: &v64.b[1],
                               isLine: false,
                               clipMask,
                               passEntityNumber,
                               passOwnerNumber: 0x1FFF,
                               physicsId: -1,
                               bodyMask: v22,
                               models: v24,
                               maxModels: v26,
                               a12: v28,
                               a13: v30,
                               a14: v32,
                               a15: v34,
                               a16: v36,
                               a17: v38,
                               a18: v40,
                               a19: v42,
                               a20: v44,
                               a21: v46,
                               a22: v48,
                               a23: v50,
                               a24: v52,
                               a25: v54,
                               a26: v56,
                               a27: v58,
                               a28: 0,
                               a29: v60,
                               a30: (int)v68,
                               a31: v62,
                               a32: 128);
  idCollisionModelManager::Clip(
    this: (idCollisionModelManager *)&v66,
    result: (idCollisionQuery *)collisionModelManager,
    a3: result,
    start,
    globalBounds: &v64,
    trms: &v65,
    numTrms: 1,
    trmAxis: startAxis,
    contentMask: v23,
    models: v25,
    numModels: v27,
    userName: v29,
    a13: v31,
    a14: v33,
    a15: v35,
    a16: v37,
    a17: v39,
    a18: v41,
    a19: v43,
    a20: v45,
    a21: v47,
    a22: v49,
    a23: v51,
    a24: v53,
    a25: v55,
    a26: v57,
    a27: v59,
    a28: clipMask,
    a29: v61,
    a30: (int)v68,
    a31: v63,
    a32: PositionedModelsInternal);
  if ( query != nullptr )
  {
    v21 = (unsigned int)v66 | 0xC00000000LL;
    query->clipModel = nullptr;
    query->type = QUERY_SUBMITTED_CLIP;
    query->query.offset = v21;
  }
}


// ========================================================================
// ?Clip@idClip@@QAA?AVidClipQuery@@PAUclipResult_t@@ABVidVec3@@PBVidTraceModel@@ABVidMat3@@HHPBD@Z
// EA  : 0x82734EF8
// RVA : 0x00734EF8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

idClip *__fastcall idClip::Clip(
        idClip *this,
        idClip *result,
        clipResult_t *a3,
        const idVec3 *start,
        const idTraceModel *trm,
        const idMat3 *startAxis,
        int clipMask,
        int passEntityNumber,
        const char *userName,
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
        int a27,
        int a28)
{
  unsigned __int64 v33; // r6
  int *p_numQueryParms; // r28
  __int128 v38; // r11
  int v39; // r3
  int v40; // r11
  double z; // fp12
  double x; // fp11
  __int64 v43; // r10
  const char *v45; // [sp+8h] [-C8h]
  idVec3 *numQueryParms; // [sp+60h] [-70h] BYREF
  idPLogScope v47[13]; // [sp+68h] [-68h] BYREF

  LODWORD(v33) = "idClip::Clip";
  HIDWORD(v33) = 1;
  idPLogScope::idPLogScope(this: v47, pl: &pLog, gMask: v33, label: (const char *)trm);
  if ( a3 != nullptr )
  {
    idClip::ClipInternal(
      this: result,
      result: a3,
      query: nullptr,
      start,
      trm,
      startAxis,
      clipMask,
      passEntityNumber,
      userName: v45);
    LODWORD(v43) = 0;
    *(_QWORD *)&this->world = v43;
  }
  else
  {
    p_numQueryParms = &result->numQueryParms;
    *((_QWORD *)&v38 + 1) = result->collisionQueryLastAllocedIndex;
    HIDWORD(v38) = result->numQueryParms;
    LODWORD(v38) = v38 + 1;
    result->collisionQueryLastAllocedIndex = v38;
    LODWORD(v38) = (v38 & 0xFFF) + 11621;
    DWORD1(v38) = 2 * v38;
    LODWORD(v38) = (char *)result + 24 * v38;
    *(_DWORD *)v38 = DWORD2(v38);
    *(_DWORD *)(v38 + 4) = HIDWORD(v38);
    *(_DWORD *)(v38 + 8) = DWORD2(v38);
    *(_QWORD *)(v38 + 16) = *(_QWORD *)((char *)&v38 + 4);
    numQueryParms = (idVec3 *)result->numQueryParms;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&result->clipQueries,
      obj: (const encounterGroupRole_t *)&numQueryParms);
    if ( result->numQueryParms >= 0x800u )
      idLib::Error(fmt: "MAX_CLIP_QUERIES");
    __asm { dcbz128   r9, r8 }
    v39 = *p_numQueryParms + 1;
    v40 = (int)&result->queryParms[*p_numQueryParms];
    numQueryParms = &startAxis->mat[2];
    *p_numQueryParms = v39;
    *(float *)v40 = start->x;
    *(float *)(v40 + 4) = start->y;
    z = start->z;
    *(_DWORD *)(v40 + 120) = trm;
    *(float *)(v40 + 8) = z;
    numQueryParms = (idVec3 *)(v40 + 68);
    x = startAxis->mat[0].x;
    numQueryParms = (idVec3 *)(v40 + 80);
    *(float *)(v40 + 56) = x;
    *(float *)(v40 + 60) = startAxis->mat[0].y;
    *(float *)(v40 + 64) = startAxis->mat[0].z;
    *(float *)(v40 + 68) = startAxis->mat[1].x;
    *(float *)(v40 + 72) = startAxis->mat[1].y;
    *(float *)(v40 + 76) = startAxis->mat[1].z;
    *(float *)(v40 + 80) = startAxis->mat[2].x;
    *(float *)(v40 + 84) = startAxis->mat[2].y;
    *(float *)(v40 + 88) = startAxis->mat[2].z;
    *(_WORD *)(v40 + 96) = passEntityNumber;
    *(_DWORD *)(v40 + 92) = clipMask;
    *(_DWORD *)(v40 + 112) = result->collisionQueryLastAllocedIndex;
    *(_DWORD *)(v40 + 124) = a28;
    *(_QWORD *)&this->world = result->collisionQueryLastAllocedIndex;
  }
  idPLogScope::~idPLogScope(this: v47);
  return this;
}


// ========================================================================
// $LN48_1
// EA  : 0x827350E8
// RVA : 0x007350E8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _LN48_1()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 104));
}


// ========================================================================
// $LN1619
// EA  : 0x82737B40
// RVA : 0x00737B40
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _LN1619()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 18064));
}


// ========================================================================
// __unwind$266017
// EA  : 0x82737B68
// RVA : 0x00737B68
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266017()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65360);
}


// ========================================================================
// __unwind$266018
// EA  : 0x82737B98
// RVA : 0x00737B98
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266018()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// __unwind$266019
// EA  : 0x82737BC0
// RVA : 0x00737BC0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266019()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65361);
}


// ========================================================================
// __unwind$266020
// EA  : 0x82737BF0
// RVA : 0x00737BF0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266020()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// __unwind$266021
// EA  : 0x82737C18
// RVA : 0x00737C18
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266021()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65362);
}


// ========================================================================
// __unwind$266022
// EA  : 0x82737C48
// RVA : 0x00737C48
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266022()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// __unwind$266023
// EA  : 0x82737C70
// RVA : 0x00737C70
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266023()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65363);
}


// ========================================================================
// __unwind$266024
// EA  : 0x82737CA0
// RVA : 0x00737CA0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266024()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// __unwind$266025
// EA  : 0x82737CC8
// RVA : 0x00737CC8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266025()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65364);
}


// ========================================================================
// __unwind$266026
// EA  : 0x82737CF8
// RVA : 0x00737CF8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266026()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// __unwind$266027
// EA  : 0x82737D20
// RVA : 0x00737D20
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266027()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65365);
}


// ========================================================================
// __unwind$266028
// EA  : 0x82737D50
// RVA : 0x00737D50
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266028()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// __unwind$266029
// EA  : 0x82737D78
// RVA : 0x00737D78
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266029()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65366);
}


// ========================================================================
// __unwind$266030
// EA  : 0x82737DA8
// RVA : 0x00737DA8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266030()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// __unwind$266031
// EA  : 0x82737DD0
// RVA : 0x00737DD0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266031()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65367);
}


// ========================================================================
// __unwind$266032
// EA  : 0x82737E00
// RVA : 0x00737E00
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266032()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// __unwind$266033
// EA  : 0x82737E28
// RVA : 0x00737E28
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266033()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65368);
}


// ========================================================================
// __unwind$266034
// EA  : 0x82737E58
// RVA : 0x00737E58
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266034()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// __unwind$266035
// EA  : 0x82737E80
// RVA : 0x00737E80
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266035()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65369);
}


// ========================================================================
// __unwind$266036
// EA  : 0x82737EB0
// RVA : 0x00737EB0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266036()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// __unwind$266037
// EA  : 0x82737ED8
// RVA : 0x00737ED8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266037()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65370);
}


// ========================================================================
// __unwind$266038
// EA  : 0x82737F08
// RVA : 0x00737F08
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266038()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// __unwind$266039
// EA  : 0x82737F30
// RVA : 0x00737F30
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266039()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65371);
}


// ========================================================================
// __unwind$266040
// EA  : 0x82737F60
// RVA : 0x00737F60
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266040()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// __unwind$266041
// EA  : 0x82737F88
// RVA : 0x00737F88
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266041()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65372);
}


// ========================================================================
// __unwind$266042
// EA  : 0x82737FB8
// RVA : 0x00737FB8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266042()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// __unwind$266043
// EA  : 0x82737FE0
// RVA : 0x00737FE0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266043()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65373);
}


// ========================================================================
// __unwind$266044
// EA  : 0x82738010
// RVA : 0x00738010
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266044()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// __unwind$266045
// EA  : 0x82738038
// RVA : 0x00738038
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266045()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65374);
}


// ========================================================================
// __unwind$266046
// EA  : 0x82738068
// RVA : 0x00738068
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266046()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// __unwind$266047
// EA  : 0x82738090
// RVA : 0x00738090
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266047()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65375);
}


// ========================================================================
// __unwind$266048
// EA  : 0x827380C0
// RVA : 0x007380C0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_266048()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 2208);
}


// ========================================================================
// ?ShowCollisionSurfaces@idClip@@QAAXABVidVec3@@ABVidMat3@@HHPBVidTypeInfoTools@@@Z
// EA  : 0x827380F0
// RVA : 0x007380F0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idClip::ShowCollisionSurfaces(
        idClip *this,
        const idVec3 *viewOrigin,
        const idMat3 *viewAxis,
        int passEntityNumber,
        int type,
        idTypeInfoTools *tools)
{
  int v12; // r30
  double y; // fp6
  double v14; // fp9
  double x; // fp5
  double v16; // fp8
  idRenderWorld *v17; // r3
  idPhysics *PhysicsForId; // r3
  idClipModel *world; // r30
  idCollisionModel *CollisionModel; // r3
  __int64 v21; // r4 OVERLAPPED
  int v22; // r5
  __int64 v23; // r11
  idRenderWorld *v24; // r3
  const enumTypeInfo_t *v25; // r9
  int v26; // r28
  const enumValueInfo_t *values; // r11
  int v28; // r10
  const enumValueInfo_t *v29; // r10
  int value; // r11
  char v31; // r8
  idStr *v32; // r25
  size_t len; // r30
  int v34; // r11
  const enumValueInfo_t *v35; // r9
  const enumValueInfo_t *v36; // r10
  const enumTypeInfo_t *v37; // r9
  int v38; // r27
  const enumValueInfo_t *v39; // r11
  int v40; // r10
  const enumValueInfo_t *v41; // r11
  idStr *v42; // r29
  size_t v43; // r30
  int v44; // r4
  idRenderWorld *v45; // r3
  __int64 v46; // r10
  idRenderWorld *v47; // r30
  va *v48; // r3
  int v49; // [sp+8h] [-17A8h]
  int v50; // [sp+Ch] [-17A4h]
  int v51; // [sp+10h] [-17A0h]
  int v52; // [sp+14h] [-179Ch]
  int v53; // [sp+18h] [-1798h]
  int v54; // [sp+1Ch] [-1794h]
  float v55[4]; // [sp+70h] [-1740h] BYREF
  idVec3 v56; // [sp+80h] [-1730h] BYREF
  float v57[4]; // [sp+90h] [-1720h] BYREF
  idStr v58; // [sp+A0h] [-1710h] BYREF
  idStr v59; // [sp+C0h] [-16F0h] BYREF
  idStr v60; // [sp+E0h] [-16D0h] BYREF
  idStr v61; // [sp+100h] [-16B0h] BYREF
  idVec3 v62; // [sp+120h] [-1690h] BYREF
  float v63; // [sp+12Ch] [-1684h]
  float v64; // [sp+130h] [-1680h]
  float v65; // [sp+134h] [-167Ch]
  float v66; // [sp+138h] [-1678h]
  float v67; // [sp+13Ch] [-1674h]
  float v68; // [sp+140h] [-1670h]
  idStr v69; // [sp+150h] [-1660h] BYREF
  trace_t v70; // [sp+170h] [-1640h] BYREF
  idStr v71; // [sp+1F0h] [-15C0h] BYREF
  idStr v72; // [sp+210h] [-15A0h] BYREF
  idFixedWinding v73; // [sp+230h] [-1580h] BYREF
  va v74; // [sp+740h] [-1070h] BYREF

  if ( contentsFlags == nullptr )
  {
    contentsFlags = idTypeInfoTools::FindEnumInfo(this: tools, typeName: "contentsFlags_t");
    surfaceTypes = idTypeInfoTools::FindEnumInfo(this: tools, typeName: "surfTypes_t");
    surfaceFlags = idTypeInfoTools::FindEnumInfo(this: tools, typeName: "surfaceFlags_t");
  }
  v12 = -1;
  if ( type == 2 )
    v12 = 8462469;
  idClip::ResolveCollisionQueries(this);
  y = viewOrigin->y;
  v14 = (float)(viewAxis->mat[0].y * (float)4096.0);
  x = viewOrigin->x;
  v16 = (float)(viewAxis->mat[0].x * (float)4096.0);
  v56.z = viewOrigin->z + (float)(viewAxis->mat[0].z * (float)4096.0);
  v56.y = (float)y + (float)v14;
  v56.x = (float)x + (float)v16;
  idClip::TracePoint(this, result: &v70, start: viewOrigin, end: &v56, clipMask: v12, passEntityNumber);
  if ( v70.fraction >= 1.0 )
    return;
  if ( v70.c.type != CONTACT_SPHERE )
  {
    PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: v70.c.physicsId);
    if ( PhysicsForId != nullptr )
    {
      if ( v70.c.physicsId != 0 )
        world = PhysicsForId->GetClipModel(this: PhysicsForId, a2: v70.c.bodyId);
      else
        world = this->world;
    }
    else
    {
      if ( v70.c.physicsId != 0 )
        goto LABEL_18;
      world = this->world;
    }
    if ( world != nullptr )
    {
      v73.numPoints = 0;
      v73.p = v73.data;
      v73.__vftable = (idFixedWinding_vtbl *)&idFixedWinding::`vftable';
      v73.allocedSize = 64;
      CollisionModel = idClipModel::GetCollisionModel(this: world, index: 0);
      CollisionModel->GetPolygon(this: CollisionModel, a2: v70.c.modelFeature, a3: &v73);
      HIDWORD(v21) = &cm_drawSurfaceColor;
      v55[0] = idColor::colorRed.r;
      v55[1] = idColor::colorRed.g;
      v55[2] = idColor::colorRed.b;
      v55[3] = idColor::colorRed.a;
      if ( cm_drawSurfaceColor.valueInteger != 0 )
      {
        v22 = v70.c.surfaceColor[0];
        HIDWORD(v23) = byte_821B0000;
        LODWORD(v21) = v70.c.surfaceColor[1];
        v55[3] = 1.0;
        LODWORD(v23) = v70.c.surfaceColor[2];
        v55[2] = (float)v23 * (float)0.0039215689;
        v55[1] = (float)v21 * (float)0.0039215689;
        v55[0] = (float)*(__int64 *)((char *)&v21 - 4) * (float)0.0039215689;
      }
      v24 = common->RW(this: common);
      v24->DebugWinding(
        this: v24,
        a2: (const idVec4 *)v55,
        a3: &v73,
        a4: &world->origin,
        a5: &world->axis,
        a6: 0,
        a7: false);
      idFixedWinding::~idFixedWinding(this: &v73);
    }
    goto LABEL_18;
  }
  v17 = common->RW(this: common);
  v17->DebugPoint(this: v17, a2: (const idVec4 *)&idColor::colorRed, a3: &v70.c.point, a4: 0, a5: false);
LABEL_18:
  idVec3::ToMat3(this: &v62, result: (idMat3 *)&v70.c.normal);
  v65 = -v65;
  v63 = -v63;
  v64 = -v64;
  v58.len = 0;
  v58.allocedAndFlag = 20;
  v58.data = v58.baseBuffer;
  v58.baseBuffer[0] = 0;
  v25 = contentsFlags;
  v26 = 0;
  values = contentsFlags->values;
  if ( values->name != nullptr )
  {
    v28 = 0;
    do
    {
      v29 = &values[v28];
      value = v29->value;
      if ( ((value - 1) & value) != 0 || (v31 = 1, value <= 0) )
        v31 = 0;
      if ( v31 != 0 && (value & v70.c.contentFlags) != 0 )
      {
        idStr::idStr(this: &v69, text: v29->name);
        idStr::StripLeading(this: &v69, string: "CONTENTS_");
        v32 = operator+(result: &v71, a: ", ", b: &v69);
        len = v32->len;
        idStr::EnsureAlloced(this: &v69, amount: v32->len + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: v69.data, Src: v32->data, Size: len);
        v69.data[len] = 0;
        v69.len = len;
        idStr::FreeData(this: &v71);
        idStr::Append(this: &v58, text: &v69);
        idStr::FreeData(this: &v69);
        v25 = contentsFlags;
      }
      ++v26;
      values = v25->values;
      v28 = v26;
    }
    while ( values[v26].name != nullptr );
  }
  idStr::StripLeading(this: &v58, string: ", ");
  idStr::ToLower(this: &v58);
  v60.allocedAndFlag = 20;
  v60.data = v60.baseBuffer;
  v60.len = 0;
  v60.baseBuffer[0] = 0;
  v34 = 0;
  v35 = surfaceTypes->values;
  if ( v35->name != nullptr )
  {
    v36 = surfaceTypes->values;
    while ( v70.c.surfaceType != v36->value )
    {
      v36 = &v35[++v34];
      if ( v36->name == nullptr )
        goto LABEL_33;
    }
    idStr::operator=(this: &v60, text: v36->name);
    idStr::StripLeading(this: &v60, string: "SURFTYPE_");
    idStr::ToLower(this: &v60);
  }
LABEL_33:
  v61.allocedAndFlag = 20;
  v61.len = 0;
  v61.data = v61.baseBuffer;
  v61.baseBuffer[0] = 0;
  v37 = surfaceFlags;
  v38 = 0;
  v39 = surfaceFlags->values;
  if ( v39->name != nullptr )
  {
    v40 = 0;
    do
    {
      v41 = &v39[v40];
      if ( (v41->value & v70.c.surfaceFlags) != 0 )
      {
        idStr::idStr(this: &v59, text: v41->name);
        idStr::StripLeading(this: &v59, string: "SURF_");
        v42 = operator+(result: &v72, a: ", ", b: &v59);
        v43 = v42->len;
        v44 = v42->len + 1;
        if ( v59.allocedAndFlag >= 0 )
        {
          if ( v44 > (v59.allocedAndFlag & 0x7FFFFFFF) )
            idStr::ReAllocate(this: &v59, amount: v44, keepold: false);
        }
        else if ( v44 > (v59.allocedAndFlag & 0x7FFFFFFF)
               && AssertFailed(
                    file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                    line: 463,
                    expression: "amount <= GetAlloced()",
                    inlineBreak: true) )
        {
          __trap();
        }
        memcpy(Dst: v59.data, Src: v42->data, Size: v43);
        v59.data[v43] = 0;
        v59.len = v43;
        idStr::FreeData(this: &v72);
        idStr::Append(this: &v61, text: &v59);
        idStr::FreeData(this: &v59);
        v37 = surfaceFlags;
      }
      ++v38;
      v39 = v37->values;
      v40 = v38;
    }
    while ( v39[v38].name != nullptr );
  }
  idStr::StripLeading(this: &v61, string: ", ");
  idStr::ToLower(this: &v61);
  v45 = common->RW(this: common);
  HIDWORD(v46) = &off_82010000;
  v47 = v45;
  v57[2] = v70.c.point.z - (float)(v68 * (float)4.0);
  v57[1] = v70.c.point.y - (float)(v67 * (float)4.0);
  v57[0] = v70.c.point.x - (float)(v66 * (float)4.0);
  v48 = va::va(
          this: &v74,
          fmt: "contents = %s\nsurface type = %s\nsurface flags = %s\nentityNum = %d",
          a3: __SPAIR64__((unsigned int)v58.data, (unsigned int)v60.data),
          a4: __SPAIR64__((unsigned int)v61.data, v70.c.entityNum),
          a5: v46,
          a6: v49,
          a7: v50,
          a8: v51,
          a9: v52,
          a10: v53,
          a11: v54);
  ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, idVec3 *, int, _DWORD, double))v47->DebugText_2)(
    a1: v47,
    a2: v48,
    a3: v57,
    a4: v47->__vftable,
    a5: &idColor::colorWhite,
    a6: &v62,
    a7: 1,
    a8: 0,
    a9: 0.1);
  idStr::FreeData(this: &v61);
  idStr::FreeData(this: &v60);
  idStr::FreeData(this: &v58);
}


// ========================================================================
// __unwind$269966
// EA  : 0x827387E8
// RVA : 0x007387E8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_269966()
{
  int v0; // r12

  idFixedWinding::~idFixedWinding(this: (idFixedWinding *)(v0 - 6064 + 560));
}


// ========================================================================
// __unwind$269967
// EA  : 0x82738810
// RVA : 0x00738810
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_269967()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6064 + 160));
}


// ========================================================================
// __unwind$269968
// EA  : 0x82738838
// RVA : 0x00738838
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_269968()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6064 + 336));
}


// ========================================================================
// __unwind$269969
// EA  : 0x82738860
// RVA : 0x00738860
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_269969()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6064 + 496));
}


// ========================================================================
// __unwind$269970
// EA  : 0x82738888
// RVA : 0x00738888
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_269970()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6064 + 224));
}


// ========================================================================
// __unwind$269971
// EA  : 0x827388B0
// RVA : 0x007388B0
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_269971()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6064 + 256));
}


// ========================================================================
// __unwind$269972
// EA  : 0x827388D8
// RVA : 0x007388D8
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_269972()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6064 + 192));
}


// ========================================================================
// __unwind$269973
// EA  : 0x82738900
// RVA : 0x00738900
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void _unwind_269973()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 6064 + 528));
}


// ========================================================================
// `dynamic initializer for 'g_showCollisionQueries''
// EA  : 0x83340298
// RVA : 0x01340298
// PDB : w:\tech5\engine\gamelib\physics\clip.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showCollisionQueries__()
{
  idCVar::idCVar(
    this: &g_showCollisionQueries,
    name: "g_showCollisionQueries",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showCollisionQueries__);
}

