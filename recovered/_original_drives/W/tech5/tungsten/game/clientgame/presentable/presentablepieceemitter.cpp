
// ========================================================================
// ?SetInitProperties@idPresentablePieceEmitter@@QAAXPBVidDeclImpactSound@@MHMMMMM@Z
// EA  : 0x82B72B60
// RVA : 0x00B72B60
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepieceemitter.cpp
// ========================================================================

void __fastcall idPresentablePieceEmitter::SetInitProperties(
        idPresentablePieceEmitter *this,
        const idDeclImpactSound *impactTable_,
        double pieceMinBounceVelocity_,
        int pieceLifeSpan_,
        double pieceFriction_,
        double emitFovScale_,
        double emitModelDepthHack_,
        double pieceCollisionAgeDecay_,
        double pieceCollisionVolumeDecay_,
        int a10)
{
  this->pieceMinBounceVelocity = pieceMinBounceVelocity_;
  this->impactTable = impactTable_;
  this->pieceFriction = pieceFriction_;
  this->pieceLifeSpan = a10;
  this->pieceCollisionAgeDecay = pieceCollisionAgeDecay_;
  this->pieceCollisionVolumeDecay = pieceCollisionVolumeDecay_;
  this->emitFovScale = emitFovScale_;
  this->emitModelDepthHack = emitModelDepthHack_;
}


// ========================================================================
// ??0idPresentablePieceEmitter@@QAA@PAVidPieceEmitter@@PAVidRenderModel@@@Z
// EA  : 0x82B72B90
// RVA : 0x00B72B90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepieceemitter.cpp
// ========================================================================

idPresentablePieceEmitter *__fastcall idPresentablePieceEmitter::idPresentablePieceEmitter(
        idPresentablePieceEmitter *this,
        idPieceEmitter *ent,
        idTreeAnimator *renderModel_)
{
  float *p_pieceCollisionVolumeDecay; // r11
  idRenderModelEffects **p_modelEffects; // r8
  int i; // ctr

  idPresentable::idPresentable(this, e: ent, renderModel_, entityNumber_: 0x1FFF, fxDecl_: nullptr);
  this->__vftable = (idPresentablePieceEmitter_vtbl *)&idPresentablePieceEmitter::`vftable';
  idEffectPhysicsPieceEmitter::idEffectPhysicsPieceEmitter(this: &this->piecePhysics);
  p_pieceCollisionVolumeDecay = &this->pieceCollisionVolumeDecay;
  p_modelEffects = &this->piecePhysics.modelEffects;
  for ( i = 10; i != 0; --i )
  {
    p_modelEffects += 18;
    *p_modelEffects = (idRenderModelEffects *)LODWORD(vec3_origin.x);
    p_pieceCollisionVolumeDecay[2] = vec3_origin.y;
    p_pieceCollisionVolumeDecay[3] = vec3_origin.z;
    *(idMat3 *)(p_pieceCollisionVolumeDecay + 4) = mat3_identity;
    *(idVec3 *)(p_pieceCollisionVolumeDecay + 13) = vec3_origin;
    p_pieceCollisionVolumeDecay[16] = vec3_origin.x;
    p_pieceCollisionVolumeDecay[17] = vec3_origin.y;
    p_pieceCollisionVolumeDecay += 18;
    *p_pieceCollisionVolumeDecay = vec3_origin.z;
  }
  this->impactTable = nullptr;
  this->pieceLifeSpan = 0;
  this->pieceMinBounceVelocity = 1.0;
  this->emitPieceBufferPos = 0;
  this->pieceFriction = 15.0;
  this->emitFovScale = 1.0;
  this->emitModelDepthHack = 0.0;
  this->pieceCollisionAgeDecay = 0.0;
  this->pieceCollisionVolumeDecay = 0.0;
  memset(Dst: this->emitPieceBuffer, Val: 0, Size: sizeof(this->emitPieceBuffer));
  return this;
}


// ========================================================================
// __unwind$488422
// EA  : 0x82B72CF4
// RVA : 0x00B72CF4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepieceemitter.cpp
// ========================================================================

void _unwind_488422()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idPresentablePieceEmitter@@UAA@XZ
// EA  : 0x82B72D28
// RVA : 0x00B72D28
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepieceemitter.cpp
// ========================================================================

void __fastcall idPresentablePieceEmitter::~idPresentablePieceEmitter(idPresentablePieceEmitter *this)
{
  this->__vftable = (idPresentablePieceEmitter_vtbl *)&idPresentablePieceEmitter::`vftable';
  idClientGame::RemoveSimulatingEffectPhysics(this: clientGame, broadPhase: &this->piecePhysics.broadPhase);
  idEffectPhysicsPieceEmitter::~idEffectPhysicsPieceEmitter(this: &this->piecePhysics);
  idPresentable::~idPresentable(this);
}


// ========================================================================
// __unwind$488537
// EA  : 0x82B72D8C
// RVA : 0x00B72D8C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepieceemitter.cpp
// ========================================================================

void _unwind_488537()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488538
// EA  : 0x82B72DB4
// RVA : 0x00B72DB4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepieceemitter.cpp
// ========================================================================

void _unwind_488538()
{
  int v0; // r12

  idEffectPhysicsPieceEmitter::~idEffectPhysicsPieceEmitter(this: (idEffectPhysicsPieceEmitter *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                                + 1200));
}


// ========================================================================
// ?Present@idPresentablePieceEmitter@@UAAXXZ
// EA  : 0x82B72DE0
// RVA : 0x00B72DE0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepieceemitter.cpp
// ========================================================================

void __fastcall idPresentablePieceEmitter::Present(idPresentablePieceEmitter *this)
{
  idPresentablePlayer *LocalPresentablePlayer; // r3
  float *v3; // r3
  double v4; // fp10
  double v5; // fp8
  double v6; // fp6
  int v7; // r4

  idPresentable::Present(this);
  if ( g_showPieceCollision.valueInteger != 0 )
  {
    LocalPresentablePlayer = idClientGame::GetLocalPresentablePlayer(this: clientGame);
    if ( LocalPresentablePlayer != nullptr )
    {
      v3 = (float *)LocalPresentablePlayer->physicsObj.GetOrigin(this: &LocalPresentablePlayer->physicsObj, a2: 0);
      v4 = (float)(v3[1] - this->origin.y);
      v5 = (float)(v3[2] - this->origin.z);
      v6 = (float)(*v3 - this->origin.x);
      if ( (float)((float)((float)v6 * (float)v6)
                 + (float)((float)((float)v5 * (float)v5) + (float)((float)v4 * (float)v4))) < 1000000.0 )
      {
        v7 = -1 - g_showPieceCollision.valueInteger;
        if ( g_showPieceCollision.valueInteger >= 0 )
          v7 = -1;
        idEffectPhysicsPieceEmitter::DrawCollisionModels(
          this: &this->piecePhysics,
          single: v7,
          offset: &this->origin,
          axis: &this->axis);
      }
    }
  }
}


// ========================================================================
// ?Interpolate@idPresentablePieceEmitter@@UAAXHM@Z
// EA  : 0x82B72EA8
// RVA : 0x00B72EA8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepieceemitter.cpp
// ========================================================================

void __fastcall idPresentablePieceEmitter::Interpolate(idPresentablePieceEmitter *this, int curTime, double fraction)
{
  const char *GameMsPerFrame; // r28
  signed int GameMs; // r3
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r7
  int v10; // r6
  int v11; // r5
  int v12; // [sp+8h] [-88h]
  int v13; // [sp+Ch] [-84h]
  int v14; // [sp+10h] [-80h]
  int v15; // [sp+14h] [-7Ch]
  int v16; // [sp+18h] [-78h]
  idEffectPhysicsBroadPhase *v17; // [sp+1Ch] [-74h]
  idVec3 v18; // [sp+50h] [-40h] BYREF

  idPresentable::Interpolate(this, curTime, fraction);
  GameMsPerFrame = (const char *)idGameTimeManager::GetGameMsPerFrame(
                                   this: &clientGame->gameTimeManager,
                                   type: GAMETIME_SCALED);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idEffectPhysicsPieceEmitter::UpdateSimulation(
    this: &this->piecePhysics,
    origin: &this->origin,
    axis: &this->axis,
    currentTime: GameMs,
    gameMsPerFrame: GameMsPerFrame);
  v18.x = 1.0;
  v18.y = 1.0;
  v18.z = 1.0;
  idEffectPhysicsPieceEmitter::UpdateModel(this: &this->piecePhysics, activeDrawScale3D: &v18);
  idClientGame::AddSimulatingEffectPhysics(
    this: clientGame,
    broadPhase: &this->piecePhysics.broadPhase,
    a3: v11,
    a4: v10,
    a5: v9,
    a6: v8,
    a7: v7,
    a8: v6,
    a9: v12,
    a10: v13,
    a11: v14,
    a12: v15,
    a13: v16,
    a14: v17);
  if ( this->piecePhysics.numPiecesInUse == 0 )
    idEffectPhysicsPieceEmitter::Reset(this: &this->piecePhysics);
}


// ========================================================================
// ?GetWorldTransform@idPresentablePieceEmitter@@UAAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82B72F50
// RVA : 0x00B72F50
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepieceemitter.cpp
// ========================================================================

void __fastcall idPresentablePieceEmitter::GetWorldTransform(
        idPresentablePieceEmitter *this,
        idVec3 *outOrigin,
        idMat3 *outAxis)
{
  *outOrigin = vec3_origin;
  *outAxis = mat3_identity;
}


// ========================================================================
// ?EmitPiece@idPresentablePieceEmitter@@QAAXHABVidVec3@@ABVidMat3@@00@Z
// EA  : 0x82B72FC8
// RVA : 0x00B72FC8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepieceemitter.cpp
// ========================================================================

void __fastcall idPresentablePieceEmitter::EmitPiece(
        idPresentablePieceEmitter *this,
        const int emitTime,
        const idVec3 *pos,
        const idMat3 *axes,
        const idVec3 *impulsePoint,
        const idVec3 *impulse)
{
  char *v6; // r11

  v6 = (char *)this + 72 * this->emitPieceBufferPos;
  *(idVec3 *)(v6 + 1400) = *pos;
  *(idMat3 *)(v6 + 1412) = *axes;
  *(idVec3 *)(v6 + 1448) = *impulsePoint;
  *(idVec3 *)(v6 + 1460) = *impulse;
  this->emitPieceBufferPos = (this->emitPieceBufferPos + 1) % 10;
}


// ========================================================================
// ?Serialize@idPresentablePieceEmitter@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B73308
// RVA : 0x00B73308
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepieceemitter.cpp
// ========================================================================

void __fastcall idPresentablePieceEmitter::Serialize(idPresentablePieceEmitter *this, idSerializer *ser)
{
  idRenderModel *model; // r28
  idBitMsg *msg; // r3
  idBitMsg *v6; // r3
  idBitMsg *v7; // r3
  idBitMsg *v8; // r3
  idBitMsg *v9; // r3
  idBitMsg *v10; // r3
  idBitMsg *v11; // r3
  idRenderModel *v12; // r3
  idRenderModelDiscreteAnimation *v13; // r3
  const idDeclImpactSound *impactTable; // r8
  double v15; // fp13
  idRenderModelDiscreteAnimation *v16; // r30
  idTraceModelCache *traceModelCache; // r27
  idRenderModelEffects *MergeBranch; // r3
  int pieceLifeSpan; // r10
  double pieceCollisionAgeDecay; // fp11
  double pieceCollisionVolumeDecay; // fp10
  int emitPieceBufferPos; // r26
  idBitMsg *v23; // r3
  unsigned int v24; // r10
  idVec3 *p_impulsePoint; // r30
  int i; // r28
  idVec3 *v27; // r4
  idBitMsg *v28; // r3
  __int64 v29; // r8
  idBitMsg *v30; // r3
  idVec3 *v31; // r4
  idBitMsg *v32; // r3
  char *v33; // r11
  const idVec3 *v34; // r30
  const idVec3 *v35; // r24
  const idVec3 *v36; // r23
  const idMat3 *v37; // r22
  int GameMs; // r3
  int v39; // r11
  idVec3 v40; // [sp+58h] [-88h] BYREF
  idEffectPhysicsPieceEmitter::pieceEmitterSound_t v41; // [sp+70h] [-70h] BYREF

  model = this->model;
  idPresentable::Serialize(this, ser);
  idSerializer::Serialize<idDeclImpactSound>(this: ser, decl: &this->impactTable);
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: COERCE_INT(this->pieceMinBounceVelocity), numBits: 32);
  else
    LODWORD(this->pieceMinBounceVelocity) = idBitMsg::ReadBits(this: msg, numBits: 32);
  v6 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v6, value: COERCE_INT(this->pieceCollisionAgeDecay), numBits: 32);
  else
    LODWORD(this->pieceCollisionAgeDecay) = idBitMsg::ReadBits(this: v6, numBits: 32);
  v7 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v7, value: COERCE_INT(this->pieceCollisionVolumeDecay), numBits: 32);
  else
    LODWORD(this->pieceCollisionVolumeDecay) = idBitMsg::ReadBits(this: v7, numBits: 32);
  v8 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v8, value: this->pieceLifeSpan, numBits: 32);
  else
    this->pieceLifeSpan = idBitMsg::ReadBits(this: v8, numBits: 32);
  v9 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v9, value: COERCE_INT(this->pieceFriction), numBits: 32);
  else
    LODWORD(this->pieceFriction) = idBitMsg::ReadBits(this: v9, numBits: 32);
  v10 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v10, value: COERCE_INT(this->emitFovScale), numBits: 32);
  else
    LODWORD(this->emitFovScale) = idBitMsg::ReadBits(this: v10, numBits: 32);
  v11 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v11, value: COERCE_INT(this->emitModelDepthHack), numBits: 32);
  else
    LODWORD(this->emitModelDepthHack) = idBitMsg::ReadBits(this: v11, numBits: 32);
  v12 = this->model;
  if ( (model != v12 || this->serializeCount == 1) && !ser->writing )
  {
    v13 = (idRenderModelDiscreteAnimation *)_RTDynamicCast(
                                              inptr: v12,
                                              VfDelta: 0,
                                              SrcType: &idRenderModel `RTTI Type Descriptor',
                                              TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
                                              isReference: 0);
    impactTable = this->impactTable;
    v15 = (float)(this->pieceMinBounceVelocity * this->pieceMinBounceVelocity);
    v41.impactTable = nullptr;
    v16 = v13;
    v41.soundWorld = nullptr;
    v41.minBounceVelSqr = 0.0;
    v41.nextSoundTime = 0;
    v41.soundWorld = clientGame->soundWorld;
    v41.minBounceVelSqr = v15;
    v41.impactTable = impactTable;
    traceModelCache = clientGame->clip.traceModelCache;
    MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
    idEffectPhysicsPieceEmitter::Init(
      this: &this->piecePhysics,
      clip: &clientGame->clip,
      tmc: traceModelCache,
      model: v16,
      modelEffects: MergeBranch,
      soundInfo: &v41,
      entNum: -1);
    pieceLifeSpan = this->pieceLifeSpan;
    pieceCollisionAgeDecay = this->pieceCollisionAgeDecay;
    pieceCollisionVolumeDecay = this->pieceCollisionVolumeDecay;
    this->piecePhysics.pieceFriction = this->pieceFriction;
    v40.x = 1.0;
    this->piecePhysics.pieceLifeTime = pieceLifeSpan;
    v40.y = 1.0;
    v40.z = 1.0;
    this->piecePhysics.pieceCollisionAgeDecay = pieceCollisionAgeDecay;
    this->piecePhysics.pieceCollisionVolumeDecay = pieceCollisionVolumeDecay;
    idEffectPhysicsPieceEmitter::UpdateModel(this: &this->piecePhysics, activeDrawScale3D: &v40);
    if ( !v16->deferredPositionInitialized || !v16->useDeferredPosition )
      v16->g.origin = vec3_origin;
    v16->deferredOrigin = vec3_origin;
    idRenderModel::SetAxis(this: v16, a: &mat3_identity);
    v16->g.fovScale = this->emitFovScale;
    v16->g.modelDepthHack = this->emitModelDepthHack;
    this->Hide(this, a2: true);
    idEffectPhysicsPieceEmitter::Reset(this: &this->piecePhysics);
  }
  emitPieceBufferPos = this->emitPieceBufferPos;
  v23 = ser->msg;
  v24 = _cntlzw(9u);
  if ( ser->writing )
    idBitMsg::WriteBits(this: v23, value: this->emitPieceBufferPos, numBits: 32 - v24);
  else
    emitPieceBufferPos = idBitMsg::ReadBits(this: v23, numBits: 32 - v24);
  p_impulsePoint = &this->emitPieceBuffer[0].impulsePoint;
  for ( i = 10; i != 0; --i )
  {
    v27 = p_impulsePoint - 4;
    v28 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteQuantizedVector<idVec3,32768,12>(this: v28, v: v27);
    else
      idBitMsg::ReadQuantizedVector<idVec3,32768,12>(this: v28, v: v27);
    idSerializer::SerializeQ(this: ser, axis: (idQuat *)&p_impulsePoint[-3], bits: 15, a4: v29);
    v30 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteQuantizedVector<idVec3,32768,12>(this: v30, v: p_impulsePoint);
    else
      idBitMsg::ReadQuantizedVector<idVec3,32768,12>(this: v30, v: p_impulsePoint);
    v31 = p_impulsePoint + 1;
    v32 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteQuantizedVector<idVec3,4096,8>(this: v32, v: v31);
    else
      idBitMsg::ReadQuantizedVector<idVec3,4096,8>(this: v32, v: v31);
    p_impulsePoint += 6;
  }
  if ( this->emitPieceBufferPos != emitPieceBufferPos )
  {
    do
    {
      v33 = (char *)this + 72 * this->emitPieceBufferPos;
      v34 = (const idVec3 *)(v33 + 1400);
      v35 = (const idVec3 *)(v33 + 1460);
      v36 = (const idVec3 *)(v33 + 1448);
      v37 = (const idMat3 *)(v33 + 1412);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idEffectPhysicsPieceEmitter::EmitPiece(
        this: &this->piecePhysics,
        emitTime: GameMs,
        pos: v34,
        axes: v37,
        impulsePoint: v36,
        impulse: v35);
      v39 = this->emitPieceBufferPos + 1;
      this->emitPieceBufferPos = v39 % 10;
    }
    while ( v39 % 10 != emitPieceBufferPos );
  }
  this->emitPieceBufferPos = emitPieceBufferPos;
}

