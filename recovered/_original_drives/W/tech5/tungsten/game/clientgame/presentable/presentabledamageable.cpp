
// ========================================================================
// ?SetInitProperties@idPresentableDamageable@@QAAXPBVidDeclImpactSound@@M@Z
// EA  : 0x82B6DFD8
// RVA : 0x00B6DFD8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledamageable.cpp
// ========================================================================

void __fastcall idPresentableDamageable::SetInitProperties(
        idPresentableDamageable *this,
        const idDeclImpactSound *impactTable_,
        double pieceMinBounceVelocity_)
{
  this->impactTable = impactTable_;
  this->pieceMinBounceVelocity = pieceMinBounceVelocity_;
}


// ========================================================================
// ?Present@idPresentableDamageable@@UAAXXZ
// EA  : 0x82B6DFE8
// RVA : 0x00B6DFE8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledamageable.cpp
// ========================================================================

// attributes: thunk
void __fastcall idPresentableDamageable::Present(idPresentableBreakable *this)
{
  idPresentable::Present(this);
}


// ========================================================================
// ?StartExplosions@idPresentableDamageable@@QAAXXZ
// EA  : 0x82B6DFF0
// RVA : 0x00B6DFF0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledamageable.cpp
// ========================================================================

void __fastcall idPresentableDamageable::StartExplosions(idPresentableDamageable *this)
{
  int v1; // r11

  v1 = this->explosionFrame + 1;
  this->explosionFrame = v1 % 16;
  this->currentExplosionFrame = v1 % 16;
}


// ========================================================================
// ?ActivateAllNow@idPresentableDamageable@@QAAXXZ
// EA  : 0x82B6E018
// RVA : 0x00B6E018
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledamageable.cpp
// ========================================================================

void __fastcall idPresentableDamageable::ActivateAllNow(idPresentableDamageable *this)
{
  int v1; // r11

  v1 = this->activateAllNowFrame + 1;
  this->activateAllNowFrame = v1 % 16;
  this->currentActivateAllNowFrame = v1 % 16;
}


// ========================================================================
// ??0idPresentableDamageable@@QAA@PAVidDamageableEntity@@PAVidRenderModel@@@Z
// EA  : 0x82B6E048
// RVA : 0x00B6E048
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledamageable.cpp
// ========================================================================

idPresentableDamageable *__fastcall idPresentableDamageable::idPresentableDamageable(
        idPresentableDamageable *this,
        idDamageableEntity *ent,
        idTreeAnimator *renderModel_)
{
  idPresentable::idPresentable(this, e: ent, renderModel_, entityNumber_: 0x1FFF, fxDecl_: nullptr);
  this->__vftable = (idPresentableDamageable_vtbl *)&idPresentableDamageable::`vftable';
  this->rayImpactBuffer[0].start = vec3_origin;
  this->rayImpactBuffer[0].end = vec3_origin;
  this->rayImpactBuffer[1].start = vec3_origin;
  this->rayImpactBuffer[1].end = vec3_origin;
  this->rayImpactBuffer[2].start = vec3_origin;
  this->rayImpactBuffer[2].end = vec3_origin;
  this->rayImpactBuffer[3].start = vec3_origin;
  this->rayImpactBuffer[3].end = vec3_origin;
  this->rayImpactBuffer[4].start = vec3_origin;
  this->rayImpactBuffer[4].end = vec3_origin;
  this->rayImpactBuffer[5].start = vec3_origin;
  this->rayImpactBuffer[5].end = vec3_origin;
  this->rayImpactBuffer[6].start = vec3_origin;
  this->rayImpactBuffer[6].end = vec3_origin;
  this->rayImpactBuffer[7].start = vec3_origin;
  this->rayImpactBuffer[7].end = vec3_origin;
  this->rayImpactBuffer[8].start = vec3_origin;
  this->rayImpactBuffer[8].end = vec3_origin;
  this->rayImpactBuffer[9].start = vec3_origin;
  this->rayImpactBuffer[9].end = vec3_origin;
  idEffectPhysicsBreakable::idEffectPhysicsBreakable(this: &this->breakablePhysics);
  this->rayImpactBufferPos = 0;
  this->pieceMinBounceVelocity = 1.0;
  this->explosionFrame = 0;
  this->activateAllNowFrame = 0;
  this->currentExplosionFrame = 0;
  this->currentActivateAllNowFrame = 0;
  this->impactTable = nullptr;
  memset(Dst: this->rayImpactBuffer, Val: 0, Size: sizeof(this->rayImpactBuffer));
  this->clipModelDynamic = true;
  this->clipModelDynamicAxis = true;
  return this;
}


// ========================================================================
// __unwind$487832
// EA  : 0x82B6E310
// RVA : 0x00B6E310
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledamageable.cpp
// ========================================================================

void _unwind_487832()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idPresentableDamageable@@UAA@XZ
// EA  : 0x82B6E340
// RVA : 0x00B6E340
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledamageable.cpp
// ========================================================================

void __fastcall idPresentableDamageable::~idPresentableDamageable(idPresentableDamageable *this)
{
  this->__vftable = (idPresentableDamageable_vtbl *)&idPresentableDamageable::`vftable';
  idClientGame::RemoveSimulatingEffectPhysics(this: clientGame, broadPhase: &this->breakablePhysics.broadPhase);
  idEffectPhysicsBreakable::~idEffectPhysicsBreakable(this: &this->breakablePhysics);
  idPresentable::~idPresentable(this);
}


// ========================================================================
// __unwind$487912
// EA  : 0x82B6E3A4
// RVA : 0x00B6E3A4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledamageable.cpp
// ========================================================================

void _unwind_487912()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$487913
// EA  : 0x82B6E3CC
// RVA : 0x00B6E3CC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledamageable.cpp
// ========================================================================

void _unwind_487913()
{
  int v0; // r12

  idEffectPhysicsBreakable::~idEffectPhysicsBreakable(this: (idEffectPhysicsBreakable *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                       + 1468));
}


// ========================================================================
// ?Interpolate@idPresentableDamageable@@UAAXHM@Z
// EA  : 0x82B6E3F8
// RVA : 0x00B6E3F8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledamageable.cpp
// ========================================================================

void __fastcall idPresentableDamageable::Interpolate(idPresentableDamageable *this, int curTime, double fraction)
{
  __int64 v5; // r6
  idGameTimeManager *p_gameTimeManager; // r29
  int v7; // r25
  const char *GameMsPerFrame; // r24
  int GameMs; // r23
  double RealMsPerFrame; // fp1
  int v11; // r3
  int v12; // r10
  int v13; // r9
  int v14; // r8
  int v15; // r7
  int v16; // r6
  int v17; // r5
  int v18; // [sp+8h] [-98h]
  int v19; // [sp+Ch] [-94h]
  int v20; // [sp+10h] [-90h]
  int v21; // [sp+14h] [-8Ch]
  int v22; // [sp+18h] [-88h]
  idEffectPhysicsBroadPhase *v23; // [sp+1Ch] [-84h]

  idPresentable::Interpolate(this, curTime, fraction);
  if ( _RTDynamicCast(
         inptr: this->model,
         VfDelta: 0,
         SrcType: &idRenderModel `RTTI Type Descriptor',
         TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    if ( this->currentExplosionFrame != this->explosionFrame )
    {
      idPresentable::SetLocalClipModelContents(this, newContents: 0);
      idEffectPhysicsBreakable::StartExplosions(
        this: &this->breakablePhysics,
        origin: &this->origin,
        axis: &this->axis,
        currentTime: curTime);
      this->currentExplosionFrame = this->explosionFrame;
    }
    if ( this->currentActivateAllNowFrame != this->activateAllNowFrame )
    {
      idPresentable::SetLocalClipModelContents(this, newContents: 0);
      HIDWORD(v5) = &this->axis;
      idEffectPhysicsBreakable::ActivateAllNow(this: &this->breakablePhysics, origin: &this->origin, axis: v5);
      this->currentActivateAllNowFrame = this->activateAllNowFrame;
    }
    if ( !this->hidden )
    {
      p_gameTimeManager = &clientGame->gameTimeManager;
      v7 = idAccolade::Count(this: &clientGame->gameTimeManager);
      GameMsPerFrame = (const char *)idGameTimeManager::GetGameMsPerFrame(
                                       this: &clientGame->gameTimeManager,
                                       type: GAMETIME_SCALED);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      RealMsPerFrame = idGameTimeManager::GetRealMsPerFrame(this: p_gameTimeManager, type: GAMETIME_SCALED);
      idEffectPhysicsBreakable::UpdateSimulation(
        this: &this->breakablePhysics,
        origin: &this->origin,
        axis: &this->axis,
        currentTime: GameMs,
        gameMsPerFrame: GameMsPerFrame,
        frameNum: v7,
        msPerFrame: RealMsPerFrame,
        dampening: 0.0);
      v11 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idEffectPhysicsBreakable::UpdateModel(
        this: &this->breakablePhysics,
        origin: &this->origin,
        axis: &this->axis,
        gameMsPerFrame: v11);
      idClientGame::AddSimulatingEffectPhysics(
        this: clientGame,
        broadPhase: &this->breakablePhysics.broadPhase,
        a3: v17,
        a4: v16,
        a5: v15,
        a6: v14,
        a7: v13,
        a8: v12,
        a9: v18,
        a10: v19,
        a11: v20,
        a12: v21,
        a13: v22,
        a14: v23);
    }
  }
}


// ========================================================================
// ?GetWorldTransform@idPresentableDamageable@@UAAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82B6E570
// RVA : 0x00B6E570
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledamageable.cpp
// ========================================================================

void __fastcall idPresentableDamageable::GetWorldTransform(
        idPresentableDamageable *this,
        idVec3 *outOrigin,
        idMat3 *outAxis)
{
  if ( _RTDynamicCast(
         inptr: this->model,
         VfDelta: 0,
         SrcType: &idRenderModel `RTTI Type Descriptor',
         TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    *outOrigin = vec3_origin;
    *outAxis = mat3_identity;
  }
  else
  {
    idPresentable::GetWorldTransform(this, outOrigin, outAxis);
  }
}


// ========================================================================
// ?AddRayImpact@idPresentableDamageable@@QAAXABVidVec3@@0@Z
// EA  : 0x82B6E640
// RVA : 0x00B6E640
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledamageable.cpp
// ========================================================================

void __fastcall idPresentableDamageable::AddRayImpact(
        idPresentableDamageable *this,
        const idVec3 *start,
        const idVec3 *end)
{
  this->rayImpactBuffer[this->rayImpactBufferPos].start = *start;
  this->rayImpactBuffer[this->rayImpactBufferPos].end = *end;
  this->rayImpactBufferPos = (this->rayImpactBufferPos + 1) % 10;
}


// ========================================================================
// ?Serialize@idPresentableDamageable@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B6E738
// RVA : 0x00B6E738
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentabledamageable.cpp
// ========================================================================

void __fastcall idPresentableDamageable::Serialize(idPresentableDamageable *this, idSerializer *ser)
{
  idRenderModel *model; // r30
  idRenderModel *v5; // r3
  idRenderModelDiscreteAnimation *v6; // r29
  idSoundEmitter *SoundEmitter; // r3
  const idDeclImpactSound *impactTable; // r7
  double v9; // fp13
  int GameMsPerFrame; // r3
  int rayImpactBufferPos; // r23
  idBitMsg *msg; // r3
  unsigned int v13; // r10
  idBitMsg *v14; // r3
  unsigned int v15; // r10
  int v16; // r30
  idBitMsg *v17; // r3
  idPresentableDamageable::rayBufferItem_t *rayImpactBuffer; // r26
  int i; // r22
  float *p_z; // r29
  idBitMsg *v21; // r28
  int v22; // r30
  float *v23; // r29
  idBitMsg *v24; // r28
  int v25; // r30
  idPresentableDamageable::rayBufferItem_t *v26; // r30
  int GameMs; // r3
  int v28; // r11
  idEffectPhysicsBreakable::breakablePieceSound_t v29[5]; // [sp+60h] [-80h] BYREF

  model = this->model;
  idPresentable::Serialize(this, ser);
  v5 = this->model;
  if ( model != v5 && !ser->writing )
  {
    v6 = (idRenderModelDiscreteAnimation *)_RTDynamicCast(
                                             inptr: v5,
                                             VfDelta: 0,
                                             SrcType: &idRenderModel `RTTI Type Descriptor',
                                             TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
                                             isReference: 0);
    if ( v6 != nullptr )
    {
      memset(v29, 0, 12);
      v29[0].minBounceVelSqr = 0.0;
      v29[0].nextSoundTime = 0;
      v29[0].soundWorld = clientGame->soundWorld;
      SoundEmitter = idPresentable::GetSoundEmitter(this, alloc: true);
      impactTable = this->impactTable;
      v9 = (float)(this->pieceMinBounceVelocity * this->pieceMinBounceVelocity);
      v29[0].emitter = SoundEmitter;
      v29[0].channel = SND_CHANNEL_FX;
      v29[0].minBounceVelSqr = v9;
      v29[0].impactTable = impactTable;
      idEffectPhysicsBreakable::Init(
        this: &this->breakablePhysics,
        clip: &clientGame->clip,
        tmc: &clientGame->traceModelCache,
        _gameLibEffects: &clientGame->gameLibEffects,
        model_: v6,
        entNum: -1,
        _soundInfo: v29);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idEffectPhysicsBreakable::UpdateModel(
        this: &this->breakablePhysics,
        origin: &this->origin,
        axis: &this->axis,
        gameMsPerFrame: GameMsPerFrame);
    }
  }
  rayImpactBufferPos = this->rayImpactBufferPos;
  msg = ser->msg;
  v13 = _cntlzw(9u);
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->rayImpactBufferPos, numBits: 32 - v13);
  else
    rayImpactBufferPos = idBitMsg::ReadBits(this: msg, numBits: 32 - v13);
  v14 = ser->msg;
  v15 = _cntlzw(0xFu);
  v16 = 32 - v15;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v14, value: this->explosionFrame, numBits: 32 - v15);
  else
    this->explosionFrame = idBitMsg::ReadBits(this: v14, numBits: 32 - v15);
  v17 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v17, value: this->activateAllNowFrame, numBits: v16);
  else
    this->activateAllNowFrame = idBitMsg::ReadBits(this: v17, numBits: v16);
  rayImpactBuffer = this->rayImpactBuffer;
  for ( i = 10; i != 0; --i )
  {
    p_z = &rayImpactBuffer->start.z;
    v21 = ser->msg;
    v22 = 3;
    if ( ser->writing )
    {
      do
      {
        idBitMsg::WriteBits(this: v21, value: COERCE_INT(*++p_z), numBits: 32);
        --v22;
      }
      while ( v22 != 0 );
    }
    else
    {
      do
      {
        --v22;
        *(_DWORD *)++p_z = idBitMsg::ReadBits(this: v21, numBits: 32);
      }
      while ( v22 != 0 );
    }
    v23 = &rayImpactBuffer[-1].end.z;
    v24 = ser->msg;
    v25 = 3;
    if ( ser->writing )
    {
      do
      {
        idBitMsg::WriteBits(this: v24, value: COERCE_INT(*++v23), numBits: 32);
        --v25;
      }
      while ( v25 != 0 );
    }
    else
    {
      do
      {
        --v25;
        *(_DWORD *)++v23 = idBitMsg::ReadBits(this: v24, numBits: 32);
      }
      while ( v25 != 0 );
    }
    ++rayImpactBuffer;
  }
  if ( !ser->writing
    && _RTDynamicCast(
         inptr: this->model,
         VfDelta: 0,
         SrcType: &idRenderModel `RTTI Type Descriptor',
         TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
         isReference: 0) != nullptr
    && this->rayImpactBufferPos != rayImpactBufferPos )
  {
    do
    {
      v26 = &this->rayImpactBuffer[this->rayImpactBufferPos];
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idEffectPhysicsBreakable::AddRayImpact(
        this: &this->breakablePhysics,
        time: GameMs,
        origin: &this->origin,
        axis: &this->axis,
        start: &v26->start,
        end: &v26->end,
        ignoreActivePieces: false);
      v28 = this->rayImpactBufferPos + 1;
      this->rayImpactBufferPos = v28 % 10;
    }
    while ( v28 % 10 != rayImpactBufferPos );
  }
  this->rayImpactBufferPos = rayImpactBufferPos;
}

