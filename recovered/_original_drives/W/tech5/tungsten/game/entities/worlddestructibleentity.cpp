
// ========================================================================
// ?Spawn@idTarget_ShakeTrigger@@QAAXXZ
// EA  : 0x82D55E00
// RVA : 0x00D55E00
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void __fastcall idTarget_ShakeTrigger::Spawn(idAITest_Rotation *this)
{
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?Think@idWorldDestructibleEntity@@UAAXXZ
// EA  : 0x82D55E08
// RVA : 0x00D55E08
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void __fastcall idWorldDestructibleEntity::Think(idWorldDestructibleEntity *this)
{
  idPhysics *Physics; // r3
  idBounds *v3; // r3
  idPhysics *v4; // r3
  const idVec3 *v5; // r27
  idPhysics *v6; // r3
  const idMat3 *v7; // r26
  idGameTimeManager *p_gameTimeManager; // r28
  int v9; // r25
  const char *GameMsPerFrame; // r24
  int GameMs; // r23
  double RealMsPerFrame; // fp1
  int v13; // r3
  int v14; // r10
  int v15; // r9
  int v16; // r8
  int v17; // r7
  int v18; // r6
  int v19; // r5
  int v20; // r27
  int v21; // r28
  __int64 v22; // r10
  idWorldDestructibleEntity::destructiblePiece_t *v23; // r11
  const idDeclDestructiblePieceInfo::pieceInfo_t *pieceInfo; // r11
  __int64 v25; // r8
  int v26; // [sp+8h] [-B8h]
  int v27; // [sp+Ch] [-B4h]
  int v28; // [sp+10h] [-B0h]
  int v29; // [sp+14h] [-ACh]
  int v30; // [sp+18h] [-A8h]
  idEffectPhysicsBroadPhase *v31; // [sp+1Ch] [-A4h]

  if ( (unsigned __int8)idEntity::UpdateDormant(this) == 0 )
  {
    Physics = idEntity::GetPhysics(this);
    v3 = (idBounds *)Physics->GetAbsBounds(this: Physics, a2: -1);
    idEntity::UpdatePVSAreas(this, bounds: v3);
    v4 = idEntity::GetPhysics(this);
    v5 = v4->GetOrigin(this: v4, a2: 0);
    v6 = idEntity::GetPhysics(this);
    v7 = v6->GetAxis(this: v6, a2: 0);
    p_gameTimeManager = &clientGame->gameTimeManager;
    v9 = idAccolade::Count(this: &clientGame->gameTimeManager);
    GameMsPerFrame = (const char *)idGameTimeManager::GetGameMsPerFrame(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    RealMsPerFrame = idGameTimeManager::GetRealMsPerFrame(this: p_gameTimeManager, type: GAMETIME_SCALED);
    idEffectPhysicsBreakable::UpdateSimulation(
      this: &this->breakablePhysics,
      origin: v5,
      axis: v7,
      currentTime: GameMs,
      gameMsPerFrame: GameMsPerFrame,
      frameNum: v9,
      msPerFrame: RealMsPerFrame,
      dampening: 0.0);
    v13 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idEffectPhysicsBreakable::UpdateModel(this: &this->breakablePhysics, origin: v5, axis: v7, gameMsPerFrame: v13);
    idClientGame::AddSimulatingEffectPhysics(
      this: clientGame,
      broadPhase: &this->breakablePhysics.broadPhase,
      a3: v19,
      a4: v18,
      a5: v17,
      a6: v16,
      a7: v15,
      a8: v14,
      a9: v26,
      a10: v27,
      a11: v28,
      a12: v29,
      a13: v30,
      a14: v31);
    v20 = 0;
    if ( this->destructiblePieces.num > 0 )
    {
      v21 = 0;
      do
      {
        if ( this->destructiblePieces.list[v21].timeWhenBroken > 0 )
        {
          LODWORD(v22) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v23 = &this->destructiblePieces.list[v21];
          LODWORD(v25) = v23->timeWhenBroken;
          pieceInfo = v23->pieceInfo;
          if ( (float)v22 > (double)(float)((float)(pieceInfo->breakDelay * (float)1000.0) + (float)v25)
            && pieceInfo->behavior == ZERO_OUT )
          {
            idRenderModelDiscreteAnimation::CollapsePiece(this: this->breakableModel, index: v20);
          }
        }
        ++v20;
        ++v21;
      }
      while ( v20 < this->destructiblePieces.num );
    }
    idEntity::UpdateVisuals(this);
    this->UpdateFX(this);
    this->numPiecesBrokenThisFrame = 0;
  }
}


// ========================================================================
// ?SetupPhysics@idWorldDestructibleEntity@@AAAXXZ
// EA  : 0x82D56030
// RVA : 0x00D56030
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void __fastcall idWorldDestructibleEntity::SetupPhysics(idWorldDestructibleEntity *this)
{
  idPhysics_StaticMulti *p_physicsObj; // r27
  idRenderModelDiscreteAnimation *breakableModel; // r7
  int v4; // r28
  int num; // r24
  int v6; // r26
  float *p_z; // r10
  int v8; // ctr
  idSysMutex *p_viewNoteMutex; // r11
  idClipModel *v10; // r3
  idClipModel *v11; // r4
  float *v24; // r10
  int v25; // ctr
  idSysMutex *v26; // r11
  idClipModel *v27; // r3
  idClipModel *v28; // r4
  const idDiscreteAnimationModelData *modelData; // r5
  idCollisionModel *baseModel; // r28
  idClipModel *v31; // r3
  idClipModel *v32; // r3
  idPhysics *Physics; // r3
  idBounds v34; // [sp+50h] [-CF0h] BYREF
  idClipModel *v35; // [sp+68h] [-CD8h]
  idVec3 v36; // [sp+70h] [-CD0h] BYREF
  idMat3 v37; // [sp+80h] [-CC0h] BYREF
  idTraceModel v38; // [sp+B0h] [-C90h] BYREF
  idTraceModel v39; // [sp+6B0h] [-690h] BYREF

  if ( this->breakableModel == nullptr )
    idLib::Error(fmt: "idWorldDestructibleEntity::SetupPhysics() called with a NULL breakableModel");
  p_physicsObj = &this->physicsObj;
  idPhysics::InitPhysics(
    this: &this->physicsObj,
    clip_: &clientGame->clip,
    callbacks_: &this->physicsCallbacks,
    entityNumber_: this->entityNumber);
  breakableModel = this->breakableModel;
  v34.b[0].z = 1.0e30;
  v34.b[0].y = 1.0e30;
  v4 = 0;
  v34.b[0].x = 1.0e30;
  v34.b[1].z = -1.0e30;
  v34.b[1].y = v34.b[1].z;
  v34.b[1].x = v34.b[1].z;
  num = breakableModel->modelData->traceModels.num;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      v38.offset.x = 0.0;
      p_z = &v38.offset.z;
      v38.offset.y = 0.0;
      v38.offset.z = 0.0;
      memset(&v38.type, 0, 20);
      v8 = 6;
      p_viewNoteMutex = &analysisClient.viewNoteMutex;
      do
      {
        ++p_viewNoteMutex;
        *++p_z = *(float *)&p_viewNoteMutex->handle;
        --v8;
      }
      while ( v8 != 0 );
      v38.radius = 0.0;
      v38.isConvex = false;
      v38.pad[2] = 0;
      v38.pad[1] = 0;
      v38.pad[0] = 0;
      idRenderModelDiscreteAnimation::GetPieceTraceModel(this: this->breakableModel, index: v4, traceModel: &v38);
      idRenderModelDiscreteAnimation::GetPiecePosition(
        this: this->breakableModel,
        index: v4,
        position: &v36,
        orientation: &v37);
      idTraceModel::Rotate(this: &v38, rotation: &v37);
      idTraceModel::Translate(this: &v38, translation: &v36);
      v10 = (idClipModel *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xD8u,
                             tag: TAG_CLIPMODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      v35 = v10;
      if ( v10 != nullptr )
        v11 = idClipModel::idClipModel(
                this: v10,
                clip: &clientGame->clip,
                trm: &v38,
                numTraceModels: 1,
                material: this->clipModelInfo.overrideClipMaterial);
      else
        v11 = nullptr;
      ((void (__fastcall *)(idPhysics_StaticMulti *, idClipModel *, double))p_physicsObj->SetClipModel)(
        a1: &this->physicsObj,
        a2: v11,
        a3: this->destructiblePieces.list[v6].pieceInfo->density);
      p_physicsObj->SetContents(this: &this->physicsObj, a2: 0x2000, a3: v4++);
      ++v6;
      _FP2 = (float)(v34.b[0].x - v38.bounds.b[0].x);
      _FP1 = (float)(v34.b[0].y - v38.bounds.b[0].y);
      _FP30 = (float)(v34.b[0].z - v38.bounds.b[0].z);
      _FP29 = (float)(v38.bounds.b[1].x - v34.b[1].x);
      _FP28 = (float)(v38.bounds.b[1].y - v34.b[1].y);
      _FP27 = (float)(v38.bounds.b[1].z - v34.b[1].z);
      __asm { fsel      f0, f2, f13, f0 }
      v34.b[0].x = _FP0;
      __asm { fsel      f13, f1, f11, f12 }
      v34.b[0].y = _FP13;
      __asm { fsel      f12, f30, f9, f10 }
      v34.b[0].z = _FP12;
      __asm { fsel      f11, f29, f8, f7 }
      v34.b[1].x = _FP11;
      __asm { fsel      f10, f28, f6, f5 }
      v34.b[1].y = _FP10;
      __asm { fsel      f9, f27, f4, f3 }
      v34.b[1].z = _FP9;
    }
    while ( v4 < num );
  }
  v39.offset.x = 0.0;
  v24 = &v39.offset.z;
  v39.offset.y = 0.0;
  v39.offset.z = 0.0;
  memset(&v39.type, 0, 20);
  v25 = 6;
  v26 = &analysisClient.viewNoteMutex;
  do
  {
    ++v26;
    *++v24 = *(float *)&v26->handle;
    --v25;
  }
  while ( v25 != 0 );
  v39.radius = 0.0;
  v39.isConvex = false;
  v39.pad[2] = 0;
  v39.pad[1] = 0;
  v39.pad[0] = 0;
  idTraceModel::SetupBox(this: &v39, boxBounds: &v34);
  v27 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v35 = v27;
  if ( v27 != nullptr )
    v28 = idClipModel::idClipModel(this: v27, clip: &clientGame->clip, trm: &v39, numTraceModels: 1, material: nullptr);
  else
    v28 = nullptr;
  ((void (__fastcall *)(idPhysics_StaticMulti *, idClipModel *, double))p_physicsObj->SetClipModel)(
    a1: &this->physicsObj,
    a2: v28,
    a3: 1.0);
  p_physicsObj->SetContents(this: &this->physicsObj, a2: 0x20000, a3: num);
  modelData = this->breakableModel->modelData;
  baseModel = modelData->baseModel;
  if ( baseModel != nullptr )
  {
    v31 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    v35 = v31;
    if ( v31 != nullptr )
      v32 = idClipModel::idClipModel(this: v31, clip: &clientGame->clip, model: baseModel);
    else
      v32 = nullptr;
    this->staticBaseClipModel = v32;
    idClipModel::SetContents(this: v32, newContents: 1);
    Physics = idEntity::GetPhysics(this);
    idClipModel::Link(
      this: this->staticBaseClipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: Physics->physicsId,
      newBodyId: num,
      newOrigin: &this->spawnPosition,
      newAxis: &this->spawnOrientation);
  }
  idEntity::SetPhysics(this, phys: &this->physicsObj, a3: (int)modelData);
}


// ========================================================================
// $LN129
// EA  : 0x82D56428
// RVA : 0x00D56428
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void _LN129()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 3392 + 104), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$489102
// EA  : 0x82D56454
// RVA : 0x00D56454
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void _unwind_489102()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 3392 + 104), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$489103_1
// EA  : 0x82D56480
// RVA : 0x00D56480
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void _unwind_489103_1()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 3392 + 104), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?DisablePiece@idWorldDestructibleEntity@@AAAXH@Z
// EA  : 0x82D564B0
// RVA : 0x00D564B0
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void __fastcall idWorldDestructibleEntity::DisablePiece(idWorldDestructibleEntity *this, int index)
{
  int v4; // r27
  idWorldDestructibleEntity::destructiblePiece_t *v5; // r26
  idPhysics *Physics; // r3
  int numPiecesBrokenThisFrame; // r9
  idWorldDestructibleEntity::destructiblePiece_t *v8; // r5
  const idDeclParticle *particleSystem; // r27
  idPhysics *v10; // r3
  const idMat3 *v11; // r25
  __int64 v12; // r7
  unsigned int v13; // r10
  double v14; // fp31
  int GameMsPerFrame; // r24
  int GameMs; // r29
  idMat3 *v17; // r30
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v19; // r7
  idSoundEmitter *SoundEmitter; // r30
  int v21; // [sp+8h] [-1C8h]
  int v22; // [sp+Ch] [-1C4h]
  int v23; // [sp+10h] [-1C0h]
  int v24; // [sp+14h] [-1BCh]
  int v25; // [sp+18h] [-1B8h]
  int v26; // [sp+1Ch] [-1B4h]
  int v27; // [sp+20h] [-1B0h]
  int v28; // [sp+24h] [-1ACh]
  int v29; // [sp+28h] [-1A8h]
  int v30; // [sp+2Ch] [-1A4h]
  int v31; // [sp+30h] [-1A0h]
  int v32; // [sp+34h] [-19Ch]
  int v33; // [sp+38h] [-198h]
  int v34; // [sp+3Ch] [-194h]
  int v35; // [sp+40h] [-190h]
  int v36; // [sp+44h] [-18Ch]
  int v37; // [sp+48h] [-188h]
  int v38; // [sp+4Ch] [-184h]
  int v39; // [sp+50h] [-180h]
  unsigned int v40; // [sp+60h] [-170h] BYREF
  __int64 v41; // [sp+68h] [-168h]
  idMat3 v42; // [sp+70h] [-160h] BYREF
  idMat3 v43; // [sp+B0h] [-120h] BYREF
  soundShaderParms_t v44; // [sp+E0h] [-F0h] BYREF

  if ( index < 0 || index >= this->destructiblePieces.num )
  {
    idLib::Warning(fmt: "Event_BreakPiece called on %s with invalid index %d", this->name.data, index);
  }
  else
  {
    v4 = index;
    v5 = &this->destructiblePieces.list[index];
    v5->timeWhenBroken = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 0, a3: index);
    numPiecesBrokenThisFrame = this->numPiecesBrokenThisFrame;
    v8 = &this->destructiblePieces.list[v4];
    ++this->numPiecesBroken;
    this->numPiecesBrokenThisFrame = numPiecesBrokenThisFrame + 1;
    particleSystem = v8->pieceInfo->particleSystem;
    if ( particleSystem != nullptr )
    {
      idRenderModelDiscreteAnimation::GetPiecePosition(
        this: this->breakableModel,
        index,
        position: v42.mat,
        orientation: &v43);
      v40 = -1;
      v10 = idEntity::GetPhysics(this);
      v11 = v10->GetAxis(this: v10, a2: 0);
      HIDWORD(v12) = 1664525;
      v13 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v13;
      LODWORD(v12) = (v13 >> 10) & 0x7FFF;
      v41 = v12;
      v14 = (float)((float)v12 * (float)0.000030518509);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v17 = idMat3::operator*(this: (idMat3 *)&v42.mat[1].y, result: &v5->pieceInfo->particleAxis, a: v11);
      MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
      idRenderModelEffects::AddParticles(
        this: MergeBranch,
        particle: particleSystem,
        systemStartTime: GameMs,
        gameMsPerFrame: GameMsPerFrame,
        diversity: v14,
        origin: v19,
        axis: &v42,
        velocity: v17->mat,
        color: &vec3_origin.x,
        a10: v21,
        a11: v22,
        a12: v23,
        a13: v24,
        a14: v25,
        a15: v26,
        a16: v27,
        a17: v28,
        a18: v29,
        a19: v30,
        a20: v31,
        a21: v32,
        a22: v33,
        a23: v34,
        a24: v35,
        a25: v36,
        a26: v37,
        a27: v38,
        a28: v39,
        a29: &v40);
    }
    if ( v5->pieceInfo->soundToPlayWhenBroken != nullptr )
    {
      SoundEmitter = idEntity::GetSoundEmitter(this, alloc: true);
      if ( SoundEmitter != nullptr )
      {
        soundShaderParms_t::Clear(this: &v44);
        SoundEmitter->StartSound(
          this: SoundEmitter,
          a2: SND_CHANNEL_ANY,
          a3: v5->pieceInfo->soundToPlayWhenBroken,
          a4: &v44);
      }
    }
    if ( g_DebugWorldDestructibleEntity.valueInteger > 0 )
      idLib::Printf(fmt: "idWorldDestructibleEntity %s disabled piece with index %d\n", this->name.data, index);
    idEntity::BecomeActive(this, flags: 1);
  }
}


// ========================================================================
// ?Event_BreakPiece@idWorldDestructibleEntity@@QAA?AVeventVoid@@HABVidVec3@@@Z
// EA  : 0x82D56710
// RVA : 0x00D56710
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

idWorldDestructibleEntity *__fastcall idWorldDestructibleEntity::Event_BreakPiece(
        idWorldDestructibleEntity *this,
        idWorldDestructibleEntity *result,
        int pieceIndex,
        const idVec3 *impulse)
{
  const idPhysics *Physics; // r3
  idVec3 v10; // [sp+50h] [-60h] BYREF
  idMat3 v11[2]; // [sp+60h] [-50h] BYREF

  if ( pieceIndex < 0 || pieceIndex >= result->destructiblePieces.num )
  {
    idLib::Warning(fmt: "Event_BreakPiece called on %s with invalid index %d", result->name.data, pieceIndex);
  }
  else
  {
    idWorldDestructibleEntity::DisablePiece(this: result, index: pieceIndex);
    if ( result->destructiblePieces.list[pieceIndex].pieceInfo->behavior != ZERO_OUT )
    {
      idRenderModelDiscreteAnimation::GetPiecePosition(
        this: result->breakableModel,
        index: pieceIndex,
        position: &v10,
        orientation: v11);
      Physics = idEntity::GetPhysics(this: result);
      idEffectPhysicsBreakable::ApplyImpulseToBody(
        this: &result->breakablePhysics,
        bodyNum: pieceIndex,
        physics: Physics,
        pos: &v10,
        impulse);
      return this;
    }
  }
  return this;
}


// ========================================================================
// ??0idWorldDestructibleEntity@@QAA@XZ
// EA  : 0x82D567D8
// RVA : 0x00D567D8
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

idWorldDestructibleEntity *__fastcall idWorldDestructibleEntity::idWorldDestructibleEntity(
        idWorldDestructibleEntity *this)
{
  char flags; // r4

  idEntity::idEntity(this);
  this->health = 100.0;
  this->__vftable = (idWorldDestructibleEntity_vtbl *)&idWorldDestructibleEntity::`vftable';
  this->firstBreakHealthPercentage = 1.0;
  this->canBeDamagedByPlayer = true;
  this->totalBreakHealthPercentage = -1.0;
  this->noClipHealthPercentage = -1.0;
  this->destructiblePieces.list = nullptr;
  this->destructiblePieces.granularity = 0;
  this->destructiblePieces.memTag = 5;
  this->destructiblePieces.listStatic = 0;
  this->destructiblePieces.size = 0;
  this->destructiblePieces.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->destructiblePieces);
  this->maxHealth = 100.0;
  this->destructiblePieceDef = nullptr;
  this->numPiecesBroken = 0;
  this->numPiecesBrokenThisFrame = 0;
  this->numPiecesThatUseOverallHealth = 0;
  this->nextPieceBreakHealth = 0.0;
  this->activeDecals.list = nullptr;
  this->activeDecals.granularity = 0;
  this->activeDecals.memTag = 5;
  this->activeDecals.listStatic = 0;
  this->activeDecals.size = 0;
  this->activeDecals.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activeDecals);
  idPhysics_StaticMulti::idPhysics_StaticMulti(this: &this->physicsObj);
  this->staticBaseClipModel = nullptr;
  idEffectPhysicsBreakable::idEffectPhysicsBreakable(this: &this->breakablePhysics);
  flags = (char)this->flags;
  this->breakableModel = nullptr;
  *(_BYTE *)&this->flags = flags | 0x42;
  return this;
}


// ========================================================================
// __unwind$489571
// EA  : 0x82D568D0
// RVA : 0x00D568D0
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void _unwind_489571()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489572
// EA  : 0x82D568F8
// RVA : 0x00D568F8
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void _unwind_489572()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 820));
}


// ========================================================================
// __unwind$489573
// EA  : 0x82D56924
// RVA : 0x00D56924
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void _unwind_489573()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 860));
}


// ========================================================================
// __unwind$489574
// EA  : 0x82D56950
// RVA : 0x00D56950
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void _unwind_489574()
{
  int v0; // r12

  idPhysics_StaticMulti::~idPhysics_StaticMulti(this: (idPhysics_StaticMulti *)(*(_DWORD *)(v0 - 128 + 148) + 880));
}


// ========================================================================
// ??1idWorldDestructibleEntity@@UAA@XZ
// EA  : 0x82D56988
// RVA : 0x00D56988
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void __fastcall idWorldDestructibleEntity::~idWorldDestructibleEntity(idWorldDestructibleEntity *this)
{
  idPhysics *Physics; // r3
  idClipModel *staticBaseClipModel; // r3

  this->__vftable = (idWorldDestructibleEntity_vtbl *)&idWorldDestructibleEntity::`vftable';
  idClientGame::RemoveSimulatingEffectPhysics(this: clientGame, broadPhase: &this->breakablePhysics.broadPhase);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->breakablePhysics);
  if ( idEntity::GetPhysics(this) != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    Physics->UnlinkClip(this: Physics);
  }
  staticBaseClipModel = this->staticBaseClipModel;
  if ( staticBaseClipModel != nullptr )
    idClipModel::Delete(this: staticBaseClipModel);
  idEffectPhysicsBreakable::~idEffectPhysicsBreakable(this: &this->breakablePhysics);
  idPhysics_StaticMulti::~idPhysics_StaticMulti(this: &this->physicsObj);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activeDecals);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->destructiblePieces);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$489829
// EA  : 0x82D56A30
// RVA : 0x00D56A30
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void _unwind_489829()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489830
// EA  : 0x82D56A58
// RVA : 0x00D56A58
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void _unwind_489830()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 820));
}


// ========================================================================
// __unwind$489831
// EA  : 0x82D56A84
// RVA : 0x00D56A84
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void _unwind_489831()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 860));
}


// ========================================================================
// __unwind$489832
// EA  : 0x82D56AB0
// RVA : 0x00D56AB0
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void _unwind_489832()
{
  int v0; // r12

  idPhysics_StaticMulti::~idPhysics_StaticMulti(this: (idPhysics_StaticMulti *)(*(_DWORD *)(v0 - 112 + 132) + 880));
}


// ========================================================================
// __unwind$489833
// EA  : 0x82D56ADC
// RVA : 0x00D56ADC
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void _unwind_489833()
{
  int v0; // r12

  idEffectPhysicsBreakable::~idEffectPhysicsBreakable(this: (idEffectPhysicsBreakable *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                       + 1036));
}


// ========================================================================
// ?Damage@idWorldDestructibleEntity@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82D56B08
// RVA : 0x00D56B08
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

float __fastcall idWorldDestructibleEntity::Damage(
        idWorldDestructibleEntity *this,
        idPlayer *inflictor,
        idPlayer *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        int a8)
{
  double v13; // fp25
  double v14; // fp1
  double maxHealth; // fp13
  double v16; // fp23
  double v17; // fp0
  double v18; // fp24
  double totalBreakHealthPercentage; // fp0
  int v20; // r26
  int v21; // r25
  idWorldDestructibleEntity::destructiblePiece_t *v22; // r27
  idPhysics *Physics; // r3
  idClientGame *v24; // r10
  __int64 v25; // r7
  __int128 v26; // r11
  int v27; // r27
  const idPhysics *v28; // r3
  idPhysics *v29; // r3
  int v30; // r3
  double radius; // fp26
  float v32; // r7
  int v33; // r30
  float v34; // r6
  int num; // r9
  int v36; // r28
  idWorldDestructibleEntity::destructiblePiece_t *v37; // r29
  idPhysics *v38; // r3
  int v39; // r3
  float *p_radius; // r10
  _DWORD *v41; // r11
  int i; // ctr
  double v43; // fp11
  double v44; // fp10
  double v45; // fp9
  double v46; // fp5
  double v47; // fp0
  double v48; // fp31
  double v49; // fp13
  idPhysics *v50; // r3
  float *v51; // r3
  double v52; // fp9
  double v53; // fp7
  double v54; // fp13
  double v55; // fp11
  const idPhysics *v56; // r3
  double firstBreakHealthPercentage; // fp0
  int v58; // r11
  char v59; // r8
  idWorldDestructibleEntity::destructiblePiece_t *v60; // r30
  __int64 v61; // r10
  double v62; // fp13
  double v63; // fp11
  idDeclDestructiblePieceInfo::destructiblePieceBreakBehavior_t behavior; // r11
  idPhysics *v65; // r3
  float *v66; // r3
  const idVec3 *v67; // r29
  double v68; // fp7
  double v69; // fp6
  const idDeclDestructiblePieceInfo::pieceInfo_t *pieceInfo; // r6
  double v71; // fp1
  double v72; // fp12
  const idPhysics *v73; // r3
  const idVec3 *v74; // r7
  idPhysics *v75; // r3
  float *v76; // r3
  double v77; // fp7
  double v78; // fp6
  const idDeclDestructiblePieceInfo::pieceInfo_t *v79; // r6
  double v80; // fp1
  double v81; // fp12
  double noClipHealthPercentage; // fp0
  int j; // r30
  idPhysics *v84; // r3
  idPhysics *v85; // r3
  idVec3 v87; // [sp+60h] [-110h] BYREF
  idVec3 v88; // [sp+70h] [-100h] BYREF
  idVec3 v89; // [sp+80h] [-F0h] BYREF
  idVec3 v90; // [sp+90h] [-E0h] BYREF
  float v91[4]; // [sp+A0h] [-D0h] BYREF
  float v92[4]; // [sp+B0h] [-C0h] BYREF
  idSphere v93; // [sp+C0h] [-B0h] BYREF
  idBounds v94; // [sp+D0h] [-A0h] BYREF

  if ( damageDef == nullptr || this->numPiecesBroken >= this->destructiblePieces.num )
  {
    v14 = 0.0;
    return *((float *)&v14 + 1);
  }
  v13 = (float)(idDeclDamage::DamageAmount(this: damageDef) * (float)damageScale);
  if ( v13 == 0.0
    || !this->canBeDamagedByPlayer
    && (idPlayer::CastTo(c: inflictor) != nullptr || idPlayer::CastTo(c: attacker) != nullptr) )
  {
    goto LABEL_4;
  }
  maxHealth = this->maxHealth;
  if ( maxHealth <= 0.0 )
    v16 = 0.0;
  else
    v16 = (float)(this->health / this->maxHealth);
  v17 = (float)(this->health - (float)v13);
  this->health = this->health - (float)v13;
  if ( maxHealth <= 0.0 )
    v18 = 0.0;
  else
    v18 = (float)((float)v17 / (float)maxHealth);
  totalBreakHealthPercentage = this->totalBreakHealthPercentage;
  if ( totalBreakHealthPercentage >= 0.0 && v18 < totalBreakHealthPercentage )
  {
    v20 = 0;
    if ( this->destructiblePieces.num > 0 )
    {
      v21 = 0;
      do
      {
        v22 = &this->destructiblePieces.list[v21];
        if ( v22->timeWhenBroken <= 0 )
        {
          idWorldDestructibleEntity::DisablePiece(this, index: v20);
          if ( v22->pieceInfo->behavior != ZERO_OUT )
          {
            Physics = idEntity::GetPhysics(this);
            v24 = clientGame;
            clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
            HIDWORD(v25) = v24->random.seed;
            LODWORD(v25) = (v24->random.seed >> 10) & 0x7FFF;
            DWORD1(v26) = 1664525 * clientGame->random.seed;
            clientGame->random.seed = DWORD1(v26) + 1013904223;
            DWORD2(v26) = ((unsigned int)(DWORD1(v26) + 1013904223) >> 10) & 0x7FFF;
            HIDWORD(v26) = 1664525 * clientGame->random.seed;
            clientGame->random.seed = HIDWORD(v26) + 1013904223;
            v90.z = (float)((float)((float)v25 * (float)0.000061037019) - (float)1.0) * (float)1000.0;
            LODWORD(v26) = ((unsigned int)(HIDWORD(v26) + 1013904223) >> 10) & 0x7FFF;
            *(_QWORD *)&v87.x = v26;
            v90.y = (float)((float)((float)*(__int64 *)((char *)&v26 + 4) * (float)0.000061037019) - (float)1.0)
                  * (float)1500.0;
            v90.x = (float)((float)((float)(__int64)v26 * (float)0.000061037019) - (float)1.0) * (float)1500.0;
            v27 = (int)Physics->GetClipModel(this: Physics, a2: 0);
            v28 = idEntity::GetPhysics(this);
            idEffectPhysicsBreakable::ApplyImpulseToBody(
              this: &this->breakablePhysics,
              bodyNum: v20,
              physics: v28,
              pos: (const idVec3 *)(v27 + 32),
              impulse: &v90);
          }
        }
        ++v20;
        ++v21;
      }
      while ( v20 < this->destructiblePieces.num );
    }
    goto LABEL_59;
  }
  if ( this->health < 0.0 && inflictor != nullptr && (damageDef->damageSource & 0x40) != 0 )
  {
    if ( damageDef->radius > 0.0 )
    {
      v29 = idEntity::GetPhysics(this: inflictor);
      v30 = (int)v29->GetOrigin(this: v29, a2: 0);
      radius = damageDef->radius;
      v32 = *(float *)(v30 + 4);
      v33 = 0;
      v34 = *(float *)(v30 + 8);
      num = this->destructiblePieces.num;
      v88.x = *(float *)v30;
      v88.y = v32;
      v88.z = v34;
      if ( num > 0 )
      {
        v36 = 0;
        do
        {
          v37 = &this->destructiblePieces.list[v36];
          if ( v37->timeWhenBroken <= 0 )
          {
            v38 = idEntity::GetPhysics(this);
            v39 = (int)v38->GetClipModel(this: v38, a2: v33);
            p_radius = &v93.radius;
            v41 = (_DWORD *)(v39 + 100);
            for ( i = 6; i != 0; --i )
              *++p_radius = *(float *)++v41;
            v93.origin.x = v88.x;
            v93.origin.y = v88.y;
            v93.origin.z = v88.z;
            v93.radius = radius;
            if ( idBounds::SphereIntersection(this: &v94, s: &v93) )
            {
              v43 = (float)((float)((float)(v94.b[0].z + v94.b[1].z) * (float)0.5) - v88.z);
              v44 = (float)((float)((float)(v94.b[0].x + v94.b[1].x) * (float)0.5) - v88.x);
              v45 = (float)((float)((float)(v94.b[0].y + v94.b[1].y) * (float)0.5) - v88.y);
              v46 = __fsqrts((float)((float)((float)v45 * (float)v45)
                                   + (float)((float)((float)v44 * (float)v44) + (float)((float)v43 * (float)v43))));
              v47 = (float)((float)1.0 - (float)((float)v46 / (float)((float)radius * (float)2.0)));
              if ( v47 >= 0.0 )
                v48 = v47 <= 1.0 ? (float)((float)1.0 - (float)((float)v46 / (float)((float)radius * (float)2.0))) : 1.0;
              else
                v48 = 0.0;
              v49 = (float)-(float)((float)((float)v48 * (float)v13) - v37->health);
              v37->health = -(float)((float)((float)v48 * (float)v13) - v37->health);
              if ( v49 <= 0.0 )
              {
                idWorldDestructibleEntity::DisablePiece(this, index: v33);
                if ( v37->pieceInfo->behavior != ZERO_OUT )
                {
                  v50 = idEntity::GetPhysics(this);
                  v51 = (float *)v50->GetClipModel(this: v50, a2: v33);
                  v52 = (float)(v51[10] - v88.z);
                  v53 = (float)(v51[9] - v88.y);
                  v89.x = v51[8] - v88.x;
                  v89.z = v52;
                  v89.y = v53;
                  idVec3::NormalizeFast(this: &v89);
                  v54 = (float)(v89.z * damageDef->ragdollImpulseMag);
                  v55 = (float)((float)(v89.y * damageDef->ragdollImpulseMag) * (float)v48);
                  v89.x = (float)(v89.x * damageDef->ragdollImpulseMag) * (float)v48;
                  v89.y = v55;
                  v89.z = (float)v54 * (float)v48;
                  v56 = idEntity::GetPhysics(this);
                  idEffectPhysicsBreakable::ApplyImpulseToBody(
                    this: &this->breakablePhysics,
                    bodyNum: v33,
                    physics: v56,
                    pos: &v88,
                    impulse: &v89);
                }
              }
            }
          }
          ++v33;
          ++v36;
        }
        while ( v33 < this->destructiblePieces.num );
      }
      goto LABEL_59;
    }
LABEL_4:
    v14 = 0.0;
    return *((float *)&v14 + 1);
  }
  if ( a8 == 0 )
    goto LABEL_59;
  firstBreakHealthPercentage = this->firstBreakHealthPercentage;
  if ( v18 >= firstBreakHealthPercentage )
    goto LABEL_59;
  v58 = *(_DWORD *)(a8 + 116);
  if ( v58 < 0 || v58 >= this->breakablePhysics.rigidBodies.num )
    goto LABEL_59;
  v59 = 0;
  v60 = &this->destructiblePieces.list[v58];
  LODWORD(v61) = v60->pieceInfo;
  HIDWORD(v61) = *(unsigned __int8 *)(v61 + 4);
  if ( *(_BYTE *)(v61 + 4) != 0 )
  {
    v63 = (float)(this->nextPieceBreakHealth - (float)v13);
    this->nextPieceBreakHealth = this->nextPieceBreakHealth - (float)v13;
    if ( v63 < 0.0 )
    {
      LODWORD(v61) = this->numPiecesThatUseOverallHealth;
      *(_QWORD *)&v87.x = v61;
      this->nextPieceBreakHealth = (float)((float)maxHealth * (float)firstBreakHealthPercentage) / (float)v61;
LABEL_52:
      v59 = 1;
    }
  }
  else
  {
    v62 = (float)(v60->health - (float)v13);
    v60->health = v60->health - (float)v13;
    if ( v62 <= 0.0 )
      goto LABEL_52;
  }
  if ( v59 == 0 )
    goto LABEL_59;
  idWorldDestructibleEntity::DisablePiece(this, index: *(_DWORD *)(a8 + 116));
  behavior = v60->pieceInfo->behavior;
  if ( behavior == BREAK_AWAY_FROM_CENTER )
  {
    v65 = idEntity::GetPhysics(this);
    v66 = (float *)v65->GetOrigin(this: v65, a2: 0);
    v67 = (const idVec3 *)(a8 + 4);
    v68 = (float)(*(float *)(a8 + 8) - v66[1]);
    v69 = (float)(*(float *)(a8 + 12) - v66[2]);
    v87.x = *(float *)(a8 + 4) - *v66;
    v87.y = v68;
    v87.z = v69;
    idVec3::NormalizeFast(this: &v87);
    pieceInfo = v60->pieceInfo;
    v71 = (float)((float)((float)((float)(v87.z + vec3_up.z) * (float)10.0) * (float)v13) * pieceInfo->density);
    v72 = (float)((float)((float)((float)((float)(v87.y + vec3_up.y) * (float)10.0) * (float)v13) * pieceInfo->density)
                * (float)3000.0);
    v91[0] = (float)((float)((float)((float)(v87.x + vec3_up.x) * (float)10.0) * (float)v13) * pieceInfo->density)
           * (float)3000.0;
    v91[1] = v72;
    v91[2] = (float)v71 * (float)3000.0;
    v73 = idEntity::GetPhysics(this);
    v74 = (const idVec3 *)v91;
  }
  else
  {
    if ( behavior != BREAK_WITH_DAMAGE )
      goto LABEL_59;
    v75 = idEntity::GetPhysics(this);
    v76 = (float *)v75->GetOrigin(this: v75, a2: 0);
    v67 = (const idVec3 *)(a8 + 4);
    v77 = (float)(*(float *)(a8 + 8) - v76[1]);
    v78 = (float)(*(float *)(a8 + 12) - v76[2]);
    v87.x = *(float *)(a8 + 4) - *v76;
    v87.y = v77;
    v87.z = v78;
    idVec3::NormalizeFast(this: &v87);
    v79 = v60->pieceInfo;
    v80 = (float)((float)((float)((float)(v87.z + vec3_up.z) * (float)10.0) * (float)v13) * v79->density);
    v81 = (float)((float)((float)((float)((float)(v87.y + vec3_up.y) * (float)10.0) * (float)v13) * v79->density)
                * (float)3000.0);
    v92[0] = (float)((float)((float)((float)(v87.x + vec3_up.x) * (float)10.0) * (float)v13) * v79->density)
           * (float)3000.0;
    v92[1] = v81;
    v92[2] = (float)v80 * (float)3000.0;
    v73 = idEntity::GetPhysics(this);
    v74 = (const idVec3 *)v92;
  }
  idEffectPhysicsBreakable::ApplyImpulseToBody(
    this: &this->breakablePhysics,
    bodyNum: *(_DWORD *)(a8 + 116),
    physics: v73,
    pos: v67,
    impulse: v74);
LABEL_59:
  noClipHealthPercentage = this->noClipHealthPercentage;
  if ( noClipHealthPercentage >= 0.0 && v16 >= noClipHealthPercentage && v18 <= noClipHealthPercentage )
  {
    for ( j = 0; j < this->breakableModel->modelData->traceModels.num; ++j )
    {
      v84 = idEntity::GetPhysics(this);
      if ( v84->GetContents(this: v84, a2: j) != 0 )
      {
        v85 = idEntity::GetPhysics(this);
        v85->SetContents(this: v85, a2: 128, a3: j);
      }
    }
  }
  v14 = v13;
  return *((float *)&v14 + 1);
}


// ========================================================================
// ?Spawn@idWorldDestructibleEntity@@QAAXXZ
// EA  : 0x82D575A0
// RVA : 0x00D575A0
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void __fastcall idWorldDestructibleEntity::Spawn(idWorldDestructibleEntity *this)
{
  double firstBreakHealthPercentage; // fp0
  idRenderModel *RenderModelFromPresentable; // r3
  idRenderModelDiscreteAnimation *v4; // r3
  idRenderModelDiscreteAnimation *v5; // r11
  idList<idWorldDestructibleEntity::destructiblePiece_t,5> *p_destructiblePieces; // r30
  __int64 v7; // r11
  int v8; // r6
  idWorldDestructibleEntity::destructiblePiece_t *list; // r8
  int v10; // r7
  const idDeclDestructiblePieceInfo *destructiblePieceDef; // r11
  int num; // r9
  int entityNumber; // r8
  int GameMsPerFrame; // r29
  idPhysics *Physics; // r3
  const idMat3 *v16; // r28
  idPhysics *v17; // r3
  const idVec3 *v18; // r3
  idEffectPhysicsBreakable::breakablePieceSound_t v19; // [sp+60h] [-50h] BYREF

  firstBreakHealthPercentage = this->firstBreakHealthPercentage;
  if ( firstBreakHealthPercentage < 0.0 || firstBreakHealthPercentage > 1.0 )
  {
_LN80_2:
    idLib::Error(fmt: "idWorldDestructibleEntity %s has bad data in firstBreakHealthPercentage", this->name.data);
    JUMPOUT(0x82D5786C);
  }
  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
  v4 = (idRenderModelDiscreteAnimation *)_RTDynamicCast(
                                           inptr: RenderModelFromPresentable,
                                           VfDelta: 0,
                                           SrcType: &idRenderModel `RTTI Type Descriptor',
                                           TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
                                           isReference: 0);
  v5 = v4;
  this->breakableModel = v4;
  if ( v4 == nullptr || v4->transforms.num == 0 )
  {
    idLib::Error(fmt: "idWorldDestructibleEntity %s does not have a render model", this->name.data);
    goto _LN80_2;
  }
  if ( this->destructiblePieceDef == nullptr )
    idLib::Error(fmt: "idWorldDestructibleEntity %s needs a destructiblePieceDef specified", this->name.data);
  p_destructiblePieces = &this->destructiblePieces;
  this->maxHealth = this->health;
  idList<idWorldDestructibleEntity::destructiblePiece_t,5>::SetNum(
    this: &this->destructiblePieces,
    newNum: v5->modelData->traceModels.num);
  HIDWORD(v7) = this->destructiblePieces.num;
  v8 = 0;
  if ( SHIDWORD(v7) > 0 )
  {
    list = p_destructiblePieces->list;
    HIDWORD(v7) = 0;
    v10 = 0;
    do
    {
      destructiblePieceDef = this->destructiblePieceDef;
      num = destructiblePieceDef->destructiblePieceInfo.num;
      if ( num != 0 )
      {
        if ( v8 < 0 || v8 >= num )
          LODWORD(v7) = destructiblePieceDef->destructiblePieceInfo.list;
        else
          LODWORD(v7) = &destructiblePieceDef->destructiblePieceInfo.list[v10];
      }
      else
      {
        LODWORD(v7) = &idDeclDestructiblePieceInfo::defaultPiece;
      }
      *(const idDeclDestructiblePieceInfo::pieceInfo_t **)((char *)&list->pieceInfo + HIDWORD(v7)) = (const idDeclDestructiblePieceInfo::pieceInfo_t *)v7;
      *(float *)((char *)&p_destructiblePieces->list->health + HIDWORD(v7)) = **(float **)((char *)&p_destructiblePieces->list->pieceInfo
                                                                                         + HIDWORD(v7));
      list = p_destructiblePieces->list;
      if ( (*(const idDeclDestructiblePieceInfo::pieceInfo_t **)((char *)&p_destructiblePieces->list->pieceInfo
                                                               + HIDWORD(v7)))->useOverallHealthInstead )
        ++this->numPiecesThatUseOverallHealth;
      ++v8;
      ++v10;
      HIDWORD(v7) += 12;
    }
    while ( v8 < this->destructiblePieces.num );
  }
  LODWORD(v7) = this->numPiecesThatUseOverallHealth;
  if ( (int)v7 > 0 )
    this->nextPieceBreakHealth = (float)(this->maxHealth * this->firstBreakHealthPercentage) / (float)v7;
  idWorldDestructibleEntity::SetupPhysics(this);
  memset(&v19, 0, 20);
  v19.minBounceVelSqr = 0.0;
  v19.soundWorld = clientGame->soundWorld;
  v19.emitter = idEntity::GetSoundEmitter(this, alloc: true);
  v19.channel = SND_CHANNEL_FX;
  entityNumber = this->entityNumber;
  v19.minBounceVelSqr = 1600.0;
  idEffectPhysicsBreakable::Init(
    this: &this->breakablePhysics,
    clip: &clientGame->clip,
    tmc: &clientGame->traceModelCache,
    _gameLibEffects: &clientGame->gameLibEffects,
    model_: this->breakableModel,
    entNum: entityNumber,
    _soundInfo: &v19);
  this->SetAxis(this, a2: &this->spawnOrientation);
  idEntity::SetOrigin(this, org: &this->spawnPosition);
  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  Physics = idEntity::GetPhysics(this);
  v16 = Physics->GetAxis(this: Physics, a2: 0);
  v17 = idEntity::GetPhysics(this);
  v18 = v17->GetOrigin(this: v17, a2: 0);
  idEffectPhysicsBreakable::UpdateModel(
    this: &this->breakablePhysics,
    origin: v18,
    axis: v16,
    gameMsPerFrame: GameMsPerFrame);
}


// ========================================================================
// ?UpdateFX@idWorldDestructibleEntity@@EAAXXZ
// EA  : 0x82D57870
// RVA : 0x00D57870
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void __fastcall idWorldDestructibleEntity::UpdateFX(idWorldDestructibleEntity *this)
{
  idRenderModelDiscreteAnimation *breakableModel; // r10
  int numPiecesBrokenThisFrame; // r8
  int v4; // r29
  const idDeclBreakable *declBreakable; // r16
  int num; // r4
  int v7; // r18
  int v8; // r28
  int v9; // r19
  int v10; // r3
  __int64 v11; // r6
  idBreakablePieceDecal *v12; // r30
  int v13; // r26
  int *list; // r6
  __int64 v15; // r8
  int v16; // r11
  __int64 v17; // r11
  int v18; // r11
  int v19; // r11
  __int64 v20; // r11
  int v21; // r11
  int *v22; // r7
  int v23; // r8
  int v24; // ctr
  int v25; // r11
  idPhysics *Physics; // r3
  float *v27; // r26
  idPhysics *v28; // r3
  float *v29; // r3
  double v30; // fp6
  double v31; // fp28
  double v32; // fp8
  double v33; // fp5
  idPhysics *v34; // r3
  float *v35; // r3
  double v36; // fp13
  double v37; // fp12
  double v38; // fp9
  double v39; // fp8
  const idMD6Branch *MergeBranch; // r26
  idHandle<int,enum invalidDecalHandle_t,-1> *v41; // r30
  int GameMs; // r3
  const idMD6Branch *v43; // r3
  int v44; // r27
  int v45; // r28
  float *v46; // r30
  idPhysics *v47; // r3
  float *v48; // r23
  idPhysics *v49; // r3
  float *v50; // r3
  double v51; // fp30
  double v52; // fp29
  double v53; // fp28
  idPhysics *v54; // r3
  float *v55; // r3
  double v56; // fp11
  double v57; // fp0
  double v58; // fp13
  double v59; // fp10
  double v60; // fp9
  double v61; // fp12
  double v64; // fp6
  double v65; // fp2
  double v66; // fp12
  double v67; // fp6
  double v68; // fp4
  double v69; // fp3
  idHandle<int,enum invalidDecalHandle_t,-1> v70[4]; // [sp+50h] [-1A0h] BYREF
  const idMaterial *material; // [sp+60h] [-190h] BYREF
  float depth; // [sp+64h] [-18Ch]
  float x; // [sp+68h] [-188h]
  float y; // [sp+6Ch] [-184h]
  float angle; // [sp+70h] [-180h]
  int v76; // [sp+74h] [-17Ch]
  int v77; // [sp+78h] [-178h]
  int v78; // [sp+7Ch] [-174h]
  char v79; // [sp+80h] [-170h]
  float v80[4]; // [sp+88h] [-168h] BYREF
  float v81[6]; // [sp+98h] [-158h] BYREF
  float v82[16]; // [sp+B0h] [-140h] BYREF
  __int64 v83; // [sp+F0h] [-100h]
  __int64 v84; // [sp+F8h] [-F8h]
  __int64 v85; // [sp+100h] [-F0h]
  __int64 v86; // [sp+108h] [-E8h]
  __int64 v87; // [sp+110h] [-E0h]

  breakableModel = this->breakableModel;
  numPiecesBrokenThisFrame = this->numPiecesBrokenThisFrame;
  v70[0].value = -1;
  v4 = 0;
  declBreakable = breakableModel->declBreakable;
  if ( numPiecesBrokenThisFrame > 0 )
  {
    num = declBreakable->pieceDecals.num;
    if ( num > 0 )
    {
      if ( this->activeDecals.num == 0 )
        idList<idHandle<int,enum invalidDecalHandle_t,-1>,5>::SetNum(
          this: &this->activeDecals,
          newNum: num,
          initValue: v70);
      v7 = 0;
      if ( declBreakable->pieceDecals.num > 0 )
      {
        v8 = 0;
        v9 = 0;
        do
        {
          v10 = 0;
          HIDWORD(v11) = 0;
          v12 = &declBreakable->pieceDecals.list[v9];
          v13 = v12->affectedPieces.num;
          if ( v13 >= 4 )
          {
            list = v12->affectedPieces.list;
            HIDWORD(v15) = 0;
            do
            {
              v16 = *(int *)((char *)list + HIDWORD(v15));
              if ( v16 >= 0 && v16 < this->destructiblePieces.num )
              {
                HIDWORD(v17) = &this->destructiblePieces.list[v16];
                LODWORD(v17) = *(_DWORD *)(HIDWORD(v17) + 4);
                v85 = v17;
                if ( (float)v17 >= 0.0 )
                  ++v10;
              }
              v18 = *(int *)((char *)list + HIDWORD(v15) + 4);
              if ( v18 >= 0 && v18 < this->destructiblePieces.num )
              {
                LODWORD(v15) = this->destructiblePieces.list[v18].timeWhenBroken;
                v86 = v15;
                if ( (float)v15 >= 0.0 )
                  ++v10;
              }
              v19 = *(int *)((char *)list + HIDWORD(v15) + 8);
              if ( v19 >= 0 && v19 < this->destructiblePieces.num )
              {
                HIDWORD(v20) = &this->destructiblePieces.list[v19];
                LODWORD(v20) = *(_DWORD *)(HIDWORD(v20) + 4);
                v84 = v20;
                if ( (float)v20 >= 0.0 )
                  ++v10;
              }
              v21 = *(int *)((char *)list + HIDWORD(v15) + 12);
              if ( v21 >= 0 && v21 < this->destructiblePieces.num )
              {
                LODWORD(v15) = this->destructiblePieces.list[v21].timeWhenBroken;
                v83 = v15;
                if ( (float)v15 >= 0.0 )
                  ++v10;
              }
              HIDWORD(v11) += 4;
              HIDWORD(v15) += 16;
            }
            while ( SHIDWORD(v11) < v13 - 3 );
          }
          if ( SHIDWORD(v11) < v13 )
          {
            v22 = v12->affectedPieces.list;
            v23 = HIDWORD(v11);
            v24 = v13 - HIDWORD(v11);
            do
            {
              v25 = v22[v23];
              if ( v25 >= 0 && v25 < this->destructiblePieces.num )
              {
                LODWORD(v11) = this->destructiblePieces.list[v25].timeWhenBroken;
                v87 = v11;
                if ( (float)v11 >= 0.0 )
                  ++v10;
              }
              ++v23;
              --v24;
            }
            while ( v24 != 0 );
          }
          if ( this->activeDecals.list[v8].value == -1 )
          {
            if ( v10 > 0 && v10 < v13 )
            {
              v76 = 10000;
              depth = 8.0;
              v78 = 0;
              x = 32.0;
              y = 32.0;
              v77 = 2000;
              angle = 0.0;
              material = nullptr;
              v79 = 0;
              material = v12->material;
              depth = v12->depth;
              x = v12->size.x;
              y = v12->size.y;
              angle = v12->angle;
              v76 = -1;
              v77 = -1;
              v78 = 0;
              Physics = idEntity::GetPhysics(this);
              v27 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
              v28 = idEntity::GetPhysics(this);
              v29 = (float *)v28->GetAxis(this: v28, a2: 0);
              v30 = v27[2];
              v31 = v27[1];
              v32 = (float)((float)(v29[7] * v12->position.z)
                          + (float)((float)(v29[1] * v12->position.x) + (float)(v29[4] * v12->position.y)));
              v33 = (float)((float)(v29[8] * v12->position.z)
                          + (float)((float)(v29[2] * v12->position.x) + (float)(v29[5] * v12->position.y)));
              v81[0] = (float)((float)(*v29 * v12->position.x)
                             + (float)((float)(v29[3] * v12->position.y) + (float)(v29[6] * v12->position.z)))
                     + *v27;
              v81[1] = (float)v31 + (float)v32;
              v81[2] = (float)v30 + (float)v33;
              v34 = idEntity::GetPhysics(this);
              v35 = (float *)v34->GetAxis(this: v34, a2: 0);
              v36 = v12->direction.x;
              v37 = *v35;
              v38 = (float)((float)(v35[3] * v12->direction.y) + (float)(v35[6] * v12->direction.z));
              v39 = (float)((float)(v35[8] * v12->direction.z)
                          + (float)((float)(v35[2] * v12->direction.x) + (float)(v35[5] * v12->direction.y)));
              v80[1] = (float)(v35[7] * v12->direction.z)
                     + (float)((float)(v35[1] * v12->direction.x) + (float)(v35[4] * v12->direction.y));
              v80[2] = v39;
              v80[0] = (float)((float)v37 * (float)v36) + (float)v38;
              MergeBranch = idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
              v41 = this->activeDecals.list;
              GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
              v41[v8] = *(idHandle<int,enum invalidDecalHandle_t,-1> *)(*(int (__fastcall **)(idHandle<int,enum invalidDecalHandle_t,-1> *, const idMD6Branch *, const idMaterial **, int, float *, float *, _DWORD))(*(_DWORD *)&MergeBranch->type + 16))(
                                                                         a1: v70,
                                                                         a2: MergeBranch,
                                                                         a3: &material,
                                                                         a4: GameMs,
                                                                         a5: v81,
                                                                         a6: v80,
                                                                         a7: (unsigned __int16)NULL_JOINT_INDEX.value);
              if ( g_DebugWorldDestructibleEntity.valueInteger > 0 )
                idLib::Printf(fmt: "idWorldDestructibleEntity %s activated decal with index %d\n", this->name.data, v7);
            }
          }
          else if ( v10 == 0 || v10 == v13 )
          {
            v43 = idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
            (*(void (__fastcall **)(const idMD6Branch *, int))(*(_DWORD *)&v43->type + 20))(
              a1: v43,
              a2: this->activeDecals.list[v8].value);
            this->activeDecals.list[v8].value = -1;
            if ( g_DebugWorldDestructibleEntity.valueInteger > 0 )
              idLib::Printf(fmt: "idWorldDestructibleEntity %s deactivated decal with index %d\n", this->name.data, v7);
          }
          ++v7;
          ++v9;
          ++v8;
        }
        while ( v7 < declBreakable->pieceDecals.num );
      }
    }
  }
  if ( g_DebugWorldDestructibleEntity.valueInteger > 1 )
  {
    v44 = 0;
    if ( this->activeDecals.num > 0 )
    {
      v45 = 0;
      do
      {
        if ( this->activeDecals.list[v45].value != -1 )
        {
          v46 = (float *)&declBreakable->pieceDecals.list[v4];
          v47 = idEntity::GetPhysics(this);
          v48 = (float *)v47->GetOrigin(this: v47, a2: 0);
          v49 = idEntity::GetPhysics(this);
          v50 = (float *)v49->GetAxis(this: v49, a2: 0);
          v51 = (float)(*v48
                      + (float)((float)(*v50 * v46[5]) + (float)((float)(v50[3] * v46[6]) + (float)(v50[6] * v46[7]))));
          v52 = (float)(v48[1]
                      + (float)((float)(v50[7] * v46[7]) + (float)((float)(v50[1] * v46[5]) + (float)(v50[4] * v46[6]))));
          v53 = (float)(v48[2]
                      + (float)((float)(v50[8] * v46[7]) + (float)((float)(v50[2] * v46[5]) + (float)(v50[5] * v46[6]))));
          v54 = idEntity::GetPhysics(this);
          v55 = (float *)v54->GetAxis(this: v54, a2: 0);
          v56 = 0.0;
          v57 = (float)((float)(*v55 * v46[8]) + (float)((float)(v55[3] * v46[9]) + (float)(v55[6] * v46[10])));
          v58 = (float)((float)(v55[7] * v46[10]) + (float)((float)(v55[1] * v46[8]) + (float)(v55[4] * v46[9])));
          v59 = 1.0;
          v60 = (float)((float)(v55[8] * v46[10]) + (float)((float)(v55[2] * v46[8]) + (float)(v55[5] * v46[9])));
          v61 = (float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57));
          if ( v61 != 0.0 )
          {
            _FP8 = (float)((float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57))
                         - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm { fsel      f7, f8, f12, f11 }
            v64 = __frsqrte(_FP7);
            v65 = (float)((float)-(float)((float)((float)((float)((float)((float)((float)v58 * (float)v58)
                                                                        + (float)((float)v57 * (float)v57))
                                                                * (float)0.5)
                                                        * (float)v64)
                                                * (float)v64)
                                        - (float)1.5)
                        * (float)v64);
            v66 = (float)-(float)((float)((float)((float)((float)v61 * (float)0.5)
                                                * (float)((float)-(float)((float)((float)((float)((float)v61 * (float)0.5)
                                                                                        * (float)v64)
                                                                                * (float)v64)
                                                                        - (float)1.5)
                                                        * (float)v64))
                                        * (float)((float)-(float)((float)((float)((float)((float)v61 * (float)0.5)
                                                                                * (float)v64)
                                                                        * (float)v64)
                                                                - (float)1.5)
                                                * (float)v64))
                                - (float)1.5);
            v56 = (float)((float)((float)(*v55 * v46[8]) + (float)((float)(v55[3] * v46[9]) + (float)(v55[6] * v46[10])))
                        * (float)((float)-(float)((float)((float)((float)((float)((float)((float)v58 * (float)v58)
                                                                                + (float)((float)v57 * (float)v57))
                                                                        * (float)0.5)
                                                                * (float)((float)v66 * (float)v65))
                                                        * (float)((float)v66 * (float)v65))
                                                - (float)1.5)
                                * (float)((float)v66 * (float)v65)));
            v59 = -(float)((float)((float)(v55[7] * v46[10])
                                 + (float)((float)(v55[1] * v46[8]) + (float)(v55[4] * v46[9])))
                         * (float)((float)-(float)((float)((float)((float)((float)((float)((float)v58 * (float)v58)
                                                                                 + (float)((float)v57 * (float)v57))
                                                                         * (float)0.5)
                                                                 * (float)((float)v66 * (float)v65))
                                                         * (float)((float)v66 * (float)v65))
                                                 - (float)1.5)
                                 * (float)((float)v66 * (float)v65)));
          }
          v67 = v46[1];
          v68 = v46[2];
          v69 = (float)(v46[3] * (float)0.5);
          v82[12] = (float)(*v55 * v46[8]) + (float)((float)(v55[3] * v46[9]) + (float)(v55[6] * v46[10]));
          v82[13] = v58;
          v82[0] = v51;
          v82[1] = v52;
          v82[6] = v59;
          v82[14] = v60;
          v82[3] = v67;
          v82[9] = (float)((float)v58 * (float)0.0) - (float)((float)v56 * (float)v60);
          v82[11] = (float)((float)v56 * (float)v57) - (float)((float)v59 * (float)v58);
          v82[2] = v53;
          v82[7] = v56;
          v82[8] = 0.0;
          v82[4] = v68;
          v82[5] = v69;
          v82[10] = (float)((float)v59 * (float)v60) - (float)((float)v57 * (float)0.0);
          clientGame->renderWorld->DebugBox(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorRed,
            a3: (const idBox *)v82,
            a4: 0,
            a5: false);
        }
        ++v44;
        ++v45;
        ++v4;
      }
      while ( v44 < this->activeDecals.num );
    }
  }
}


// ========================================================================
// `dynamic initializer for 'g_DebugWorldDestructibleEntity''
// EA  : 0x83380100
// RVA : 0x01380100
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_DebugWorldDestructibleEntity__()
{
  idCVar::idCVar(
    this: &g_DebugWorldDestructibleEntity,
    name: "g_DebugWorldDestructibleEntity",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_DebugWorldDestructibleEntity__);
}


// ========================================================================
// `dynamic initializer for 'idDeclDestructiblePieceInfo::defaultPiece''
// EA  : 0x83380158
// RVA : 0x01380158
// PDB : w:\tech5\tungsten\game\entities\worlddestructibleentity.cpp
// ========================================================================

void _dynamic_initializer_for__idDeclDestructiblePieceInfo::defaultPiece__()
{
  const idDeclParticle **p_particleSystem; // r10
  float *p_y; // r11
  int i; // ctr

  p_particleSystem = &idDeclDestructiblePieceInfo::defaultPiece.particleSystem;
  p_y = &mat2_identity.mat[1].y;
  for ( i = 9; i != 0; --i )
    *++p_particleSystem = *(const idDeclParticle **)++p_y;
}

