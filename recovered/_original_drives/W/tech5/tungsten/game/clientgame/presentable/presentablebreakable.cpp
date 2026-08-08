
// ========================================================================
// ?SetInitProperties@idPresentableBreakable@@QAAXPBVidDeclImpactSound@@M@Z
// EA  : 0x82B6C3A0
// RVA : 0x00B6C3A0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __fastcall idPresentableBreakable::SetInitProperties(
        idPresentableBreakable *this,
        const idDeclImpactSound *impactTable_,
        double pieceMinBounceVelocity_)
{
  this->impactTable = impactTable_;
  this->pieceMinBounceVelocity = pieceMinBounceVelocity_;
}


// ========================================================================
// ??1idPresentableBreakable@@UAA@XZ
// EA  : 0x82B6C3B8
// RVA : 0x00B6C3B8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __fastcall idPresentableBreakable::~idPresentableBreakable(idPresentableBreakable *this)
{
  this->__vftable = (idPresentableBreakable_vtbl *)&idPresentableBreakable::`vftable';
  idClientGame::RemoveSimulatingEffectPhysics(this: clientGame, broadPhase: &this->breakablePhysics.broadPhase);
  idEffectPhysicsBreakable::~idEffectPhysicsBreakable(this: &this->breakablePhysics);
  idPresentable::~idPresentable(this);
}


// ========================================================================
// __unwind$488586
// EA  : 0x82B6C41C
// RVA : 0x00B6C41C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void _unwind_488586()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488587
// EA  : 0x82B6C444
// RVA : 0x00B6C444
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void _unwind_488587()
{
  int v0; // r12

  idEffectPhysicsBreakable::~idEffectPhysicsBreakable(this: (idEffectPhysicsBreakable *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                       + 1244));
}


// ========================================================================
// ?GibDefault@idPresentableBreakable@@AAAXH@Z
// EA  : 0x82B6C470
// RVA : 0x00B6C470
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __fastcall idPresentableBreakable::GibDefault(idPresentableBreakable *this, int curTime)
{
  idEffectPhysicsBreakable *p_breakablePhysics; // r30
  int GameMsPerFrame; // r3
  idClipModel *clipModel; // r3
  int GameMs; // r3
  bool v8; // [sp+Bh] [-C5h]
  const idVec3 *v9; // [sp+Ch] [-C4h]
  bool v10; // [sp+13h] [-BDh]
  int v11; // [sp+14h] [-BCh]
  int v12; // [sp+18h] [-B8h]
  int v13; // [sp+1Ch] [-B4h]
  int v14; // [sp+20h] [-B0h]
  int v15; // [sp+24h] [-ACh]
  int v16; // [sp+28h] [-A8h]
  int v17; // [sp+2Ch] [-A4h]
  int v18; // [sp+30h] [-A0h]
  int v19; // [sp+34h] [-9Ch]
  int v20; // [sp+38h] [-98h]
  int v21; // [sp+3Ch] [-94h]
  int v22; // [sp+40h] [-90h]
  int v23; // [sp+44h] [-8Ch]
  int v24; // [sp+48h] [-88h]
  int v25; // [sp+4Ch] [-84h]
  int v26; // [sp+50h] [-80h]
  int v27; // [sp+58h] [-78h]
  int v28; // [sp+60h] [-70h]
  int v29; // [sp+68h] [-68h]
  int v30; // [sp+70h] [-60h]
  int v31; // [sp+74h] [-5Ch]
  int v32; // [sp+78h] [-58h]
  int v33; // [sp+80h] [-50h]
  int v34; // [sp+88h] [-48h]

  p_breakablePhysics = &this->breakablePhysics;
  idEffectPhysicsBreakable::Reset(this: &this->breakablePhysics, skipModelReset: false);
  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idEffectPhysicsBreakable::UpdateModel(
    this: p_breakablePhysics,
    origin: &this->origin,
    axis: &this->axis,
    gameMsPerFrame: GameMsPerFrame);
  idEffectPhysicsBreakable::AddExplosion(
    this: p_breakablePhysics,
    particle: nullptr,
    time: curTime,
    position: &vec3_origin,
    radius: g_breakableRadius.valueFloat,
    impulse: g_gibImpulse.valueFloat,
    falloff: g_breakableFalloff.valueFloat,
    angular: g_breakableAngular.valueFloat,
    delay: (const int)&g_breakableFalloff,
    duration: (const int)&g_breakableAngular,
    startNow: 0x82000000,
    activateAllDelay: (const int)&idDeclAiEvent::resourceList.staticID,
    distTimeScaleDelay: 0.0,
    useLinear: v8,
    endLinear: v9,
    localSpace: v10,
    a17: v11,
    a18: v12,
    a19: v13,
    a20: v14,
    a21: v15,
    a22: v16,
    a23: v17,
    a24: v18,
    a25: v19,
    a26: v20,
    a27: v21,
    a28: v22,
    a29: v23,
    a30: v24,
    a31: v25,
    a32: v26,
    a33: 0,
    a34: v27,
    a35: (int)(float)(g_breakableDuration.valueFloat * (float)1000.0),
    a36: v28,
    a37: 0,
    a38: v29,
    a39: 0,
    a40: v30,
    delay_0: v31,
    a42: v32,
    duration_0_3: false,
    a44: v33,
    a45: &vec3_origin.x,
    a46: v34,
    activateAllDelay_0_3: true);
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Unlink(this: clipModel);
  if ( presentable_breakable_debug.valueInteger != 0 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "^4[%d][%d]::GibDefault \n", this->index, GameMs);
  }
}


// ========================================================================
// ?GetWorldTransform@idPresentableBreakable@@UAAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82B6C5B0
// RVA : 0x00B6C5B0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __fastcall idPresentableBreakable::GetWorldTransform(
        idPresentableBreakable *this,
        idVec3 *outOrigin,
        idMat3 *outAxis)
{
  if ( this->isRenderModelDiscreteAnimation )
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
// ?ShouldLinkPresentableCollision@idPresentableBreakable@@UAA_NXZ
// EA  : 0x82B6C638
// RVA : 0x00B6C638
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

int __fastcall idPresentableBreakable::ShouldLinkPresentableCollision(idPresentableBreakable *this)
{
  unsigned __int8 v1; // r11

  if ( this->hidden )
    return 0;
  v1 = 1;
  if ( this->broken )
    return 0;
  return v1;
}


// ========================================================================
// ?Break@idPresentableBreakable@@QAAXPBVidPresentable@@@Z
// EA  : 0x82B6C660
// RVA : 0x00B6C660
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __fastcall idPresentableBreakable::Break(idPresentableBreakable *this, const idPresentable *activator)
{
  int v3; // r10
  int explodeFrame; // r11
  int v5; // r8
  int v6; // r7
  int GameMs; // r3
  int v8; // [sp+8h] [-68h]
  int v9; // [sp+Ch] [-64h]
  int v10; // [sp+10h] [-60h]
  int v11; // [sp+14h] [-5Ch]
  int v12; // [sp+18h] [-58h]
  idPresentable *v13; // [sp+1Ch] [-54h]

  if ( activator != nullptr )
    v3 = activator->index + 1;
  else
    v3 = 0;
  explodeFrame = this->explodeFrame;
  this->activatorIndex = v3;
  ++explodeFrame;
  this->broken = true;
  v5 = explodeFrame >> 5;
  v6 = explodeFrame / 32;
  explodeFrame %= 32;
  this->explodeFrame = explodeFrame;
  this->currentExplodeFrame = explodeFrame;
  idClientGame::MarkPresentableSerialized(
    this: clientGame,
    presentable: this,
    serialized: true,
    deleted: false,
    a5: v6,
    a6: v5,
    a7: 1,
    a8: v3,
    a9: v8,
    a10: v9,
    a11: v10,
    a12: v11,
    a13: v12,
    a14: v13);
  if ( presentable_breakable_debug.valueInteger != 0 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "^4[%d][%d]::Break \n", this->index, GameMs);
  }
}


// ========================================================================
// ?PredictHitScanHit@idPresentableBreakable@@UAAXPAVidPresentable@@MABVidVec3@@1PBVidDeclProjectile@@PAUtrace_t@@@Z
// EA  : 0x82B6C728
// RVA : 0x00B6C728
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __fastcall idPresentableBreakable::PredictHitScanHit(
        idPresentableBreakable *this,
        idPresentable *attacker,
        double damage,
        const idVec3 *hitPos,
        const idVec3 *projDir,
        const idDeclProjectile *projDecl,
        trace_t *trace,
        float *a8)
{
  int trackedMemory; // r10
  const char *str; // r9
  float v12; // r7
  float v13; // r5
  double y; // fp13
  double z; // fp12
  double v16; // fp11
  double x; // fp30
  double v18; // fp13
  double v19; // fp10
  double v20; // fp7
  double v21; // fp5
  int GameMsPerFrame; // r3
  double valueFloat; // fp31
  double v24; // fp30
  double v25; // fp29
  int y_low; // r24
  double v27; // fp28
  int GameMs; // r3
  bool v29; // r9
  int v30; // r8
  int v31; // r7
  int v32; // r3
  int v33; // r3
  idClipModel *clipModel; // r3
  bool v35; // [sp+Bh] [-115h]
  const idVec3 *v36; // [sp+Ch] [-114h]
  bool v37; // [sp+13h] [-10Dh]
  int v38; // [sp+14h] [-10Ch]
  int v39; // [sp+18h] [-108h]
  int v40; // [sp+1Ch] [-104h]
  int v41; // [sp+20h] [-100h]
  int v42; // [sp+24h] [-FCh]
  int v43; // [sp+28h] [-F8h]
  int v44; // [sp+2Ch] [-F4h]
  int v45; // [sp+30h] [-F0h]
  int v46; // [sp+34h] [-ECh]
  int v47; // [sp+38h] [-E8h]
  int v48; // [sp+3Ch] [-E4h]
  int v49; // [sp+40h] [-E0h]
  int v50; // [sp+44h] [-DCh]
  int v51; // [sp+48h] [-D8h]
  int v52; // [sp+4Ch] [-D4h]
  int v53; // [sp+50h] [-D0h]
  int v54; // [sp+58h] [-C8h]
  int v55; // [sp+60h] [-C0h]
  int v56; // [sp+68h] [-B8h]
  int v57; // [sp+70h] [-B0h]
  int v58; // [sp+74h] [-ACh]
  int v59; // [sp+78h] [-A8h]
  int v60; // [sp+80h] [-A0h]
  int v61; // [sp+88h] [-98h]
  idVec3 v62; // [sp+90h] [-90h] BYREF
  idVec3 v63; // [sp+A0h] [-80h] BYREF

  if ( a8 != nullptr && !this->broken && presentable_breakable_disablePredict.valueInteger == 0 )
  {
    trackedMemory = projDecl->trackedMemory;
    str = projDecl->name.str;
    LODWORD(v62.x) = projDecl->__vftable;
    LODWORD(v62.y) = trackedMemory;
    LODWORD(v62.z) = str;
    idVec3::NormalizeFast(this: &v62);
    v12 = a8[1];
    v13 = a8[2];
    y = this->origin.y;
    z = this->origin.z;
    v16 = this->axis.mat[0].y;
    v63.z = a8[3];
    v63.x = v12;
    v63.y = v13;
    x = this->axis.mat[2].x;
    v18 = (float)((float)(v13 - (float)(v62.y * g_breakableCharOffset.valueFloat)) - (float)y);
    v19 = (float)((float)(v12 - (float)(g_breakableCharOffset.valueFloat * v62.x)) - this->origin.x);
    v20 = (float)((float)(this->axis.mat[2].z
                        * (float)((float)(v63.z - (float)(v62.z * g_breakableCharOffset.valueFloat)) - (float)z))
                + (float)(this->axis.mat[2].y * (float)v18));
    v21 = (float)((float)(this->axis.mat[1].x
                        * (float)((float)(v12 - (float)(g_breakableCharOffset.valueFloat * v62.x)) - this->origin.x))
                + (float)((float)(this->axis.mat[1].z
                                * (float)((float)(v63.z - (float)(v62.z * g_breakableCharOffset.valueFloat)) - (float)z))
                        + (float)(this->axis.mat[1].y * (float)v18)));
    v63.x = (float)((float)((float)(v12 - (float)(g_breakableCharOffset.valueFloat * v62.x)) - this->origin.x)
                  * this->axis.mat[0].x)
          + (float)((float)(this->axis.mat[0].z
                          * (float)((float)(v63.z - (float)(v62.z * g_breakableCharOffset.valueFloat)) - (float)z))
                  + (float)((float)v16 * (float)v18));
    v63.y = v21;
    v63.z = (float)((float)x * (float)v19) + (float)v20;
    idEffectPhysicsBreakable::Reset(this: &this->breakablePhysics, skipModelReset: false);
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idEffectPhysicsBreakable::UpdateModel(
      this: &this->breakablePhysics,
      origin: &this->origin,
      axis: &this->axis,
      gameMsPerFrame: GameMsPerFrame);
    valueFloat = g_breakableAngular.valueFloat;
    v24 = g_breakableFalloff.valueFloat;
    LODWORD(v62.y) = (int)(float)(g_breakableDuration.valueFloat * (float)1000.0);
    v25 = g_defaultImpulse.valueFloat;
    y_low = LODWORD(v62.y);
    v27 = g_breakableRadius.valueFloat;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idEffectPhysicsBreakable::AddExplosion(
      this: &this->breakablePhysics,
      particle: nullptr,
      time: GameMs,
      position: &v63,
      radius: v27,
      impulse: v25,
      falloff: v24,
      angular: valueFloat,
      delay: v31,
      duration: v30,
      startNow: v29,
      activateAllDelay: (const int)&vec3_origin,
      distTimeScaleDelay: 0.0,
      useLinear: v35,
      endLinear: v36,
      localSpace: v37,
      a17: v38,
      a18: v39,
      a19: v40,
      a20: v41,
      a21: v42,
      a22: v43,
      a23: v44,
      a24: v45,
      a25: v46,
      a26: v47,
      a27: v48,
      a28: v49,
      a29: v50,
      a30: v51,
      a31: v52,
      a32: v53,
      a33: 0,
      a34: v54,
      a35: y_low,
      a36: v55,
      a37: 0,
      a38: v56,
      a39: 0,
      a40: v57,
      delay_0: v58,
      a42: v59,
      duration_0_3: false,
      a44: v60,
      a45: &vec3_origin.x,
      a46: v61,
      activateAllDelay_0_3: true);
    v32 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idEffectPhysicsBreakable::StartExplosions(
      this: &this->breakablePhysics,
      origin: &this->origin,
      axis: &this->axis,
      currentTime: v32);
    this->broken = true;
    if ( presentable_breakable_debug.valueInteger != 0 )
    {
      v33 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLib::Printf(fmt: "^4[%d][%d]::PredictHitScanHit \n", this->index, v33);
    }
    clipModel = this->clipModel;
    if ( clipModel != nullptr )
      idClipModel::Unlink(this: clipModel);
  }
}


// ========================================================================
// ?StopAllFX@idPresentableBreakable@@UAAXXZ
// EA  : 0x82B6C9D0
// RVA : 0x00B6C9D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __fastcall idPresentableBreakable::StopAllFX(idPresentableBreakable *this)
{
  int GameMs; // r3

  idPresentable::StopAllFX(this);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idEffectPhysicsBreakable::StopExplosionFX(this: &this->breakablePhysics, currTime: GameMs);
}


// ========================================================================
// ?SetRenderModel@idPresentableBreakable@@UAAXPAVidRenderModel@@_N@Z
// EA  : 0x82B6CA20
// RVA : 0x00B6CA20
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __fastcall idPresentableBreakable::SetRenderModel(
        idPresentableBreakable *this,
        idTreeAnimator *renderModel_,
        bool inheritTransform)
{
  idPresentable::SetRenderModel(this, renderModel_, inheritTransform);
  this->isRenderModelDiscreteAnimation = _RTDynamicCast(
                                           inptr: this->model,
                                           VfDelta: 0,
                                           SrcType: &idRenderModel `RTTI Type Descriptor',
                                           TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
                                           isReference: 0) != nullptr;
}


// ========================================================================
// ??0idPresentableBreakable@@QAA@PAVidEntity@@PAVidRenderModel@@HPBVidDeclFX@@@Z
// EA  : 0x82B6CB40
// RVA : 0x00B6CB40
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

idPresentableBreakable *__fastcall idPresentableBreakable::idPresentableBreakable(
        idPresentableBreakable *this,
        idEntity *ent,
        idTreeAnimator *renderModel_,
        int entityNumber_,
        const idDeclFX *fxDecl_)
{
  idPresentable::idPresentable(this, e: ent, renderModel_, entityNumber_, fxDecl_);
  this->__vftable = (idPresentableBreakable_vtbl *)&idPresentableBreakable::`vftable';
  idEffectPhysicsBreakable::idEffectPhysicsBreakable(this: &this->breakablePhysics);
  this->breakableParent.spawnId = 0;
  this->fade.fadeStartTime = 0;
  this->fade.fadeEndTime = 0;
  this->fade.fadeFrom = 0.0;
  this->fade.noStippleFade = false;
  this->fade.fadeTo = 0.0;
  if ( this->model == nullptr )
    this->isRenderModelDiscreteAnimation = false;
  this->explodeFrame = 0;
  this->activatorIndex = 0;
  this->currentExplodeFrame = 0;
  this->serializeFrame = 0;
  this->impactTable = nullptr;
  this->pieceMinBounceVelocity = 1.0;
  this->localExplosionOrigin.x = 0.0;
  this->localExplosionOrigin.y = 0.0;
  this->localExplosionOrigin.z = 0.0;
  this->boneToOrientGibTo = -2;
  this->broken = false;
  this->clipModelDynamic = true;
  this->brokenStartTime = 0;
  this->fadeTimeMS = 0;
  this->fadeDelayMS = 0;
  return this;
}


// ========================================================================
// __unwind$489299
// EA  : 0x82B6CC2C
// RVA : 0x00B6CC2C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void _unwind_489299()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 112 + 132));
}


// ========================================================================
// ?GibWithActivator@idPresentableBreakable@@AAAXHPBVidPresentable@@@Z
// EA  : 0x82B6CC58
// RVA : 0x00B6CC58
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __fastcall idPresentableBreakable::GibWithActivator(
        idPresentableBreakable *this,
        int curTime,
        const idPresentable *activator)
{
  idEffectPhysicsBreakable *p_breakablePhysics; // r29
  int GameMsPerFrame; // r3
  const idDeclParticle *particle; // r25
  int GameMs; // r3
  double z; // fp0
  float y; // r10
  float v12; // r8
  double x; // fp13
  double v14; // fp12
  idClipModel *clipModel; // r3
  bool v16; // [sp+Bh] [-115h]
  bool v17; // [sp+Bh] [-115h]
  const idVec3 *v18; // [sp+Ch] [-114h]
  const idVec3 *v19; // [sp+Ch] [-114h]
  bool v20; // [sp+13h] [-10Dh]
  bool v21; // [sp+13h] [-10Dh]
  int v22; // [sp+14h] [-10Ch]
  int v23; // [sp+14h] [-10Ch]
  int v24; // [sp+18h] [-108h]
  int v25; // [sp+18h] [-108h]
  int v26; // [sp+1Ch] [-104h]
  int v27; // [sp+1Ch] [-104h]
  int v28; // [sp+20h] [-100h]
  int v29; // [sp+20h] [-100h]
  int v30; // [sp+24h] [-FCh]
  int v31; // [sp+24h] [-FCh]
  int v32; // [sp+28h] [-F8h]
  int v33; // [sp+28h] [-F8h]
  int v34; // [sp+2Ch] [-F4h]
  int v35; // [sp+2Ch] [-F4h]
  int v36; // [sp+30h] [-F0h]
  int v37; // [sp+30h] [-F0h]
  int v38; // [sp+34h] [-ECh]
  int v39; // [sp+34h] [-ECh]
  int v40; // [sp+38h] [-E8h]
  int v41; // [sp+38h] [-E8h]
  int v42; // [sp+3Ch] [-E4h]
  int v43; // [sp+3Ch] [-E4h]
  int v44; // [sp+40h] [-E0h]
  int v45; // [sp+40h] [-E0h]
  int v46; // [sp+44h] [-DCh]
  int v47; // [sp+44h] [-DCh]
  int v48; // [sp+48h] [-D8h]
  int v49; // [sp+48h] [-D8h]
  int v50; // [sp+4Ch] [-D4h]
  int v51; // [sp+4Ch] [-D4h]
  int v52; // [sp+50h] [-D0h]
  int v53; // [sp+50h] [-D0h]
  int v54; // [sp+58h] [-C8h]
  int v55; // [sp+58h] [-C8h]
  int v56; // [sp+60h] [-C0h]
  int v57; // [sp+60h] [-C0h]
  int v58; // [sp+68h] [-B8h]
  int v59; // [sp+68h] [-B8h]
  int v60; // [sp+70h] [-B0h]
  int v61; // [sp+70h] [-B0h]
  int v62; // [sp+74h] [-ACh]
  int v63; // [sp+74h] [-ACh]
  int v64; // [sp+78h] [-A8h]
  int v65; // [sp+78h] [-A8h]
  int v66; // [sp+80h] [-A0h]
  int v67; // [sp+80h] [-A0h]
  int v68; // [sp+88h] [-98h]
  int v69; // [sp+88h] [-98h]
  idVec3 v70; // [sp+98h] [-88h] BYREF

  p_breakablePhysics = &this->breakablePhysics;
  idEffectPhysicsBreakable::Reset(this: &this->breakablePhysics, skipModelReset: false);
  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idEffectPhysicsBreakable::UpdateModel(
    this: p_breakablePhysics,
    origin: &this->origin,
    axis: &this->axis,
    gameMsPerFrame: GameMsPerFrame);
  particle = this->breakablePhysics.explosions.list->decl.particle;
  if ( presentable_breakable_debug.valueInteger != 0 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "^4[%d][%d]::GibWithActivator \n", this->index, GameMs);
  }
  z = this->origin.z;
  y = activator->origin.y;
  v12 = activator->origin.z;
  x = this->origin.x;
  v14 = this->origin.y;
  v70.x = activator->origin.x;
  v70.z = (float)(v12 - (float)z) + g_breakableOffset.valueFloat;
  v70.x = v70.x - (float)x;
  v70.y = y - (float)v14;
  idEffectPhysicsBreakable::RemoveExplosions(this: p_breakablePhysics);
  idEffectPhysicsBreakable::AddExplosion(
    this: p_breakablePhysics,
    particle,
    time: curTime,
    position: &v70,
    radius: g_breakableRadius.valueFloat,
    impulse: g_breakableImpulse.valueFloat,
    falloff: g_breakableFalloff.valueFloat,
    angular: g_breakableAngular.valueFloat,
    delay: (const int)&g_breakableImpulse,
    duration: 0x82000000,
    startNow: (const bool)&idDeclAiEvent::resourceList.staticID,
    activateAllDelay: (const int)&idDeclAiEvent::resourceList.staticID,
    distTimeScaleDelay: 0.0,
    useLinear: v16,
    endLinear: v18,
    localSpace: v20,
    a17: v22,
    a18: v24,
    a19: v26,
    a20: v28,
    a21: v30,
    a22: v32,
    a23: v34,
    a24: v36,
    a25: v38,
    a26: v40,
    a27: v42,
    a28: v44,
    a29: v46,
    a30: v48,
    a31: v50,
    a32: v52,
    a33: (int)(float)(g_breakableDelay.valueFloat * (float)1000.0),
    a34: v54,
    a35: (int)(float)(g_breakableDuration.valueFloat * (float)1000.0),
    a36: v56,
    a37: 0,
    a38: v58,
    a39: 0,
    a40: v60,
    delay_0: v62,
    a42: v64,
    duration_0_3: false,
    a44: v66,
    a45: &vec3_origin.x,
    a46: v68,
    activateAllDelay_0_3: true);
  idEffectPhysicsBreakable::AddExplosion(
    this: p_breakablePhysics,
    particle,
    time: curTime,
    position: &v70,
    radius: (float)(g_breakableRadius.valueFloat * (float)3.0),
    impulse: (float)(g_gibImpulse.valueFloat * (float)0.1),
    falloff: g_breakableFalloff.valueFloat,
    angular: g_breakableAngular.valueFloat,
    delay: (const int)&off_82040000,
    duration: (const int)&ai_useTurnTransitions.valueString.baseBuffer[12],
    startNow: (int)(float)(g_breakableDuration.valueFloat * 1000.0),
    activateAllDelay: (int)(float)((float)(g_breakableDelay.valueFloat + (float)0.1) * (float)1000.0),
    distTimeScaleDelay: 0.0,
    useLinear: v17,
    endLinear: v19,
    localSpace: v21,
    a17: v23,
    a18: v25,
    a19: v27,
    a20: v29,
    a21: v31,
    a22: v33,
    a23: v35,
    a24: v37,
    a25: v39,
    a26: v41,
    a27: v43,
    a28: v45,
    a29: v47,
    a30: v49,
    a31: v51,
    a32: v53,
    a33: (int)(float)((float)(g_breakableDelay.valueFloat + (float)0.1) * (float)1000.0),
    a34: v55,
    a35: (int)(float)(g_breakableDuration.valueFloat * 1000.0),
    a36: v57,
    a37: 0,
    a38: v59,
    a39: 0,
    a40: v61,
    delay_0: v63,
    a42: v65,
    duration_0_3: false,
    a44: v67,
    a45: &vec3_origin.x,
    a46: v69,
    activateAllDelay_0_3: true);
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Unlink(this: clipModel);
}


// ========================================================================
// ?PostSerializeRead@idPresentableBreakable@@UAAX_N@Z
// EA  : 0x82B6CF40
// RVA : 0x00B6CF40
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __fastcall idPresentableBreakable::PostSerializeRead(idPresentableBreakable *this, bool firstClientFrame)
{
  idPresentable::PostSerializeRead(this, firstClientFrame);
  if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->breakableParent) )
  {
    this->origin = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->breakableParent)->origin;
    this->axis = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->breakableParent)->axis;
  }
}


// ========================================================================
// ?Serialize@idPresentableBreakable@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B6D008
// RVA : 0x00B6D008
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __fastcall idPresentableBreakable::Serialize(idPresentableBreakable *this, idSerializer *ser)
{
  idRenderModel *model; // r28
  idRenderModel *v5; // r3
  idRenderModelDiscreteAnimation *v6; // r27
  idSoundEmitter *SoundEmitter; // r3
  const idDeclImpactSound *impactTable; // r8
  double v9; // fp13
  int GameMsPerFrame; // r3
  idBitMsg *msg; // r3
  unsigned int v12; // r10
  idBitMsg *v13; // r3
  unsigned int v14; // r9
  idVec3 *p_localExplosionOrigin; // r4
  idBitMsg *v16; // r3
  idBitMsg *v17; // r3
  idBitMsg *v18; // r3
  idEffectPhysicsBreakable::breakablePieceSound_t v19; // [sp+50h] [-70h] BYREF

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
    if ( presentable_breakable_debug.valueInteger != 0 )
      idLib::Printf(fmt: "^4[%d]::Serialize -> Creating render model\n", this->index);
    idPresentable::SetParm(this, parm: rp->coverage, scalar: 1.0);
    idRenderModel::SetModelFade(this: this->model, v: 1.0);
    this->fade.fadeFrom = 0.0;
    this->fade.fadeStartTime = 0;
    this->fade.fadeTo = 0.0;
    this->fade.fadeEndTime = 0;
    this->fade.noStippleFade = false;
    v19.minBounceVelSqr = 0.0;
    memset(&v19, 0, 12);
    v19.nextSoundTime = 0;
    v19.soundWorld = clientGame->soundWorld;
    SoundEmitter = idPresentable::GetSoundEmitter(this, alloc: true);
    impactTable = this->impactTable;
    v9 = (float)(this->pieceMinBounceVelocity * this->pieceMinBounceVelocity);
    v19.emitter = SoundEmitter;
    v19.channel = SND_CHANNEL_FX;
    v19.minBounceVelSqr = v9;
    v19.impactTable = impactTable;
    idEffectPhysicsBreakable::Init(
      this: &this->breakablePhysics,
      clip: &clientGame->clip,
      tmc: clientGame->clip.traceModelCache,
      _gameLibEffects: &clientGame->gameLibEffects,
      model_: v6,
      entNum: -1,
      _soundInfo: &v19);
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idEffectPhysicsBreakable::UpdateModel(
      this: &this->breakablePhysics,
      origin: &this->origin,
      axis: &this->axis,
      gameMsPerFrame: GameMsPerFrame);
    this->Hide(this, a2: true);
  }
  msg = ser->msg;
  v12 = _cntlzw(0x1Fu);
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->explodeFrame, numBits: 32 - v12);
  else
    this->explodeFrame = idBitMsg::ReadBits(this: msg, numBits: 32 - v12);
  v13 = ser->msg;
  v14 = _cntlzw(0xFFFFu);
  if ( ser->writing )
    idBitMsg::WriteBits(this: v13, value: this->activatorIndex, numBits: 32 - v14);
  else
    this->activatorIndex = idBitMsg::ReadBits(this: v13, numBits: 32 - v14);
  p_localExplosionOrigin = &this->localExplosionOrigin;
  v16 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteQuantizedVector<idVec3,512,8>(this: v16, v: p_localExplosionOrigin);
  else
    idBitMsg::ReadQuantizedVector<idVec3,512,8>(this: v16, v: p_localExplosionOrigin);
  v17 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v17, value: this->boneToOrientGibTo + 2, numBits: 32 - _cntlzw(0x102u));
  else
    this->boneToOrientGibTo = idBitMsg::ReadBits(this: v17, numBits: 32 - _cntlzw(0x102u)) - 2;
  v18 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v18, value: this->breakableParent.spawnId, numBits: 32);
  else
    this->breakableParent.spawnId = idBitMsg::ReadBits(this: v18, numBits: 32);
  idSerializer::SerializePacked(this: ser, original: &this->fadeTimeMS);
  idSerializer::SerializePacked(this: ser, original: &this->fadeDelayMS);
  if ( !ser->writing && gameLocal->numSnapshotsSerialized < 10 )
    this->currentExplodeFrame = this->explodeFrame;
  if ( !ser->writing && this->currentExplodeFrame != this->explodeFrame )
  {
    this->broken = false;
    this->fade.fadeFrom = 0.0;
    this->fade.fadeTo = 0.0;
    this->fade.fadeStartTime = 0;
    this->fade.fadeEndTime = 0;
    this->fade.noStippleFade = false;
    if ( presentable_breakable_debug.valueInteger != 0 )
      idLib::Printf(
        fmt: "^4[%d]::Serialize -> Reset broken flag (%d != %d)l\n",
        this->index,
        this->currentExplodeFrame,
        this->explodeFrame);
  }
  ++this->serializeFrame;
}


// ========================================================================
// ?GibOrientedBodies@idPresentableBreakable@@AAAXHPAVidPresentable@@@Z
// EA  : 0x82B6D510
// RVA : 0x00B6D510
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __fastcall idPresentableBreakable::GibOrientedBodies(
        idPresentableBreakable *this,
        int curTime,
        idPresentable *activator)
{
  idPresentableAnimatedEntity *v6; // r3
  idTreeAnimator *TreeAnimator; // r23
  idPresentableAnimatedEntity *v8; // r3
  int GameMs; // r3
  const idDeclMD6 *decl; // r11
  const idJointGroup *JointGroupForIndex; // r29
  int v12; // r11
  int v13; // r10
  int v14; // r7
  int v15; // r9
  double v16; // fp0
  idVec3 *p_origin; // r28
  idBreakableManager *p_breakableManager; // r29
  idRenderModelDiscreteAnimation *v19; // r3
  idList<idVehicleState *,5> *v20; // r3
  breakableJoint_t *v21; // r3
  int boneToOrientGibTo; // r8
  idBreakableManager *v23; // r29
  idRenderModelDiscreteAnimation *v24; // r3
  int v25; // r24
  double valueFloat; // fp31
  double v27; // fp30
  int v28; // r3
  int v29; // r10
  idClipModel *clipModel; // r3
  bool v31; // [sp+Bh] [-135h]
  const idVec3 *v32; // [sp+Ch] [-134h]
  bool v33; // [sp+13h] [-12Dh]
  int v34; // [sp+14h] [-12Ch]
  int v35; // [sp+18h] [-128h]
  int v36; // [sp+1Ch] [-124h]
  int v37; // [sp+20h] [-120h]
  int v38; // [sp+24h] [-11Ch]
  int v39; // [sp+28h] [-118h]
  int v40; // [sp+2Ch] [-114h]
  int v41; // [sp+30h] [-110h]
  int v42; // [sp+34h] [-10Ch]
  int v43; // [sp+38h] [-108h]
  int v44; // [sp+3Ch] [-104h]
  int v45; // [sp+40h] [-100h]
  int v46; // [sp+44h] [-FCh]
  int v47; // [sp+48h] [-F8h]
  int v48; // [sp+4Ch] [-F4h]
  int v49; // [sp+50h] [-F0h]
  int v50; // [sp+58h] [-E8h]
  int v51; // [sp+60h] [-E0h]
  int v52; // [sp+68h] [-D8h]
  int v53; // [sp+70h] [-D0h]
  int v54; // [sp+74h] [-CCh]
  int v55; // [sp+78h] [-C8h]
  int v56; // [sp+80h] [-C0h]
  int v57; // [sp+88h] [-B8h]
  idList<idDeclVehicleUpgrade const *,5> v58; // [sp+A0h] [-A0h] BYREF
  idList<breakableJoint_t,5> v59; // [sp+B0h] [-90h] BYREF
  __int16 v60; // [sp+C0h] [-80h] BYREF

  if ( activator != nullptr && activator->GetAnimatedEntityInterface(this: activator) != nullptr )
  {
    v6 = activator->GetAnimatedEntityInterface(this: activator);
    TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v6);
    v8 = activator->GetAnimatedEntityInterface(this: activator);
    idPresentable::UpdateModelTransform(this: v8);
    if ( TreeAnimator != nullptr )
    {
      if ( presentable_breakable_debug.valueInteger != 0 )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idLib::Printf(fmt: "^4[%d][%d]::GibOrientedBodies \n", this->index, GameMs);
      }
      this->axis.mat[0].x = this->axes[1].mat[0].x;
      this->axis.mat[0].y = this->axes[1].mat[0].y;
      this->axis.mat[0].z = this->axes[1].mat[0].z;
      this->axis.mat[1].x = this->axes[1].mat[1].x;
      this->axis.mat[1].y = this->axes[1].mat[1].y;
      this->axis.mat[1].z = this->axes[1].mat[1].z;
      this->axis.mat[2].x = this->axes[1].mat[2].x;
      this->axis.mat[2].y = this->axes[1].mat[2].y;
      this->axis.mat[2].z = this->axes[1].mat[2].z;
      if ( this->boneToOrientGibTo == -1 )
      {
        decl = TreeAnimator->decl;
        if ( decl == nullptr || decl == (const idDeclMD6 *)-144 )
        {
          idLib::Warning(
            fmt: "GetJointGroupCollection was null in idPresentableBreakable::GibOrientedBodies for TA %s",
            TreeAnimator->name.str);
          return;
        }
        JointGroupForIndex = idJointGroupCollection::GetJointGroupForIndex(
                               this: &decl->jointGroupCollection,
                               type: 4,
                               index: 0);
        if ( JointGroupForIndex == nullptr )
        {
          idLib::Warning(
            fmt: "jointGroup was null in idPresentableBreakable::GibOrientedBodies for TA %s",
            TreeAnimator->name.str);
          return;
        }
        idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v58);
        idList<breakableJoint_t,5>::SetNum(
          this: (idList<breakableJoint_t,5> *)&v58,
          newNum: JointGroupForIndex->joints.num);
        v12 = 0;
        if ( JointGroupForIndex->joints.num > 0 )
        {
          v13 = 0;
          v14 = 0;
          v15 = 0;
          do
          {
            HIWORD(v58.list[v13]) = JointGroupForIndex->joints.list[v15].value;
            if ( v12 < 0 || v12 >= JointGroupForIndex->jointScalars.num )
              v16 = 1.0;
            else
              v16 = JointGroupForIndex->jointScalars.list[v14];
            ++v12;
            ++v15;
            ++v14;
            v58.list[v13 + 1] = (const idDeclVehicleUpgrade *)(int)(float)((float)v16 - (float)1.0);
            v13 += 2;
          }
          while ( v12 < JointGroupForIndex->joints.num );
        }
        p_origin = &this->origin;
        p_breakableManager = &gameLocal->breakableManager;
        v19 = (idRenderModelDiscreteAnimation *)_RTDynamicCast(
                                                  inptr: this->model,
                                                  VfDelta: 0,
                                                  SrcType: &idRenderModel `RTTI Type Descriptor',
                                                  TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
                                                  isReference: 0);
        idBreakableManager::OrientBodies(
          this: p_breakableManager,
          ta: TreeAnimator,
          breakableModel: v19,
          breakableOrigin: &this->origin,
          breakableAxis: &this->axis,
          jointList: (const idList<breakableJoint_t,5> *)&v58);
        v20 = (idList<idVehicleState *,5> *)&v58;
      }
      else
      {
        v59.size = 1;
        v59.granularity = 1;
        v59.num = 0;
        v59.list = (breakableJoint_t *)&v60;
        v59.memTag = 5;
        v59.listStatic = 1;
        v60 = -1;
        v21 = idList<breakableJoint_t,5>::Alloc(this: &v59);
        boneToOrientGibTo = this->boneToOrientGibTo;
        v21->pieceIndex = 0;
        v21->jointIndex.value = boneToOrientGibTo;
        p_origin = &this->origin;
        v23 = &gameLocal->breakableManager;
        v24 = (idRenderModelDiscreteAnimation *)_RTDynamicCast(
                                                  inptr: this->model,
                                                  VfDelta: 0,
                                                  SrcType: &idRenderModel `RTTI Type Descriptor',
                                                  TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
                                                  isReference: 0);
        idBreakableManager::OrientBodies(
          this: v23,
          ta: TreeAnimator,
          breakableModel: v24,
          breakableOrigin: &this->origin,
          breakableAxis: &this->axis,
          jointList: &v59);
        v20 = (idList<idVehicleState *,5> *)&v59;
      }
      idList<idThread *,58>::Clear(this: v20);
      idEffectPhysicsBreakable::Reset(this: &this->breakablePhysics, skipModelReset: true);
      v25 = (int)(float)(g_breakableDuration.valueFloat * (float)1000.0);
      valueFloat = g_breakableCharAngular.valueFloat;
      v27 = g_breakableCharRadius.valueFloat;
      v28 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idEffectPhysicsBreakable::AddExplosion(
        this: &this->breakablePhysics,
        particle: nullptr,
        time: v28,
        position: &this->localExplosionOrigin,
        radius: v27,
        impulse: 2000.0,
        falloff: 0.2,
        angular: valueFloat,
        delay: 0x82000000,
        duration: (const int)&off_82040000,
        startNow: (const bool)&unk_822D0000,
        activateAllDelay: v29,
        distTimeScaleDelay: 0.0,
        useLinear: v31,
        endLinear: v32,
        localSpace: v33,
        a17: v34,
        a18: v35,
        a19: v36,
        a20: v37,
        a21: v38,
        a22: v39,
        a23: v40,
        a24: v41,
        a25: v42,
        a26: v43,
        a27: v44,
        a28: v45,
        a29: v46,
        a30: v47,
        a31: v48,
        a32: v49,
        a33: 0,
        a34: v50,
        a35: v25,
        a36: v51,
        a37: 0,
        a38: v52,
        a39: 0,
        a40: v53,
        delay_0: v54,
        a42: v55,
        duration_0_3: false,
        a44: v56,
        a45: &vec3_origin.x,
        a46: v57,
        activateAllDelay_0_3: true);
      idEffectPhysicsBreakable::StartExplosions(
        this: &this->breakablePhysics,
        origin: p_origin,
        axis: &this->axis,
        currentTime: curTime);
      clipModel = this->clipModel;
      if ( clipModel != nullptr )
        idClipModel::Unlink(this: clipModel);
    }
  }
}


// ========================================================================
// __unwind$490053_0
// EA  : 0x82B6D930
// RVA : 0x00B6D930
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void _unwind_490053_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 320 + 160));
}


// ========================================================================
// __unwind$490054
// EA  : 0x82B6D958
// RVA : 0x00B6D958
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void _unwind_490054()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 320 + 176));
}


// ========================================================================
// ?Interpolate@idPresentableBreakable@@UAAXHM@Z
// EA  : 0x82B6D980
// RVA : 0x00B6D980
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __fastcall idPresentableBreakable::Interpolate(idPresentableBreakable *this, int curTime, double fraction)
{
  int v5; // r10
  int v6; // r8
  int v7; // r7
  int activatorIndex; // r11
  idPresentable *PresentableByIndex; // r28
  BOOL hidden; // r26
  int GameMs; // r3
  BOOL v12; // r10
  int v13; // r3
  idGameTimeManager *p_gameTimeManager; // r28
  int v15; // r23
  const char *GameMsPerFrame; // r22
  double RealMsPerFrame; // fp1
  int v18; // r3
  int v19; // r10
  int v20; // r9
  int v21; // r8
  int v22; // r7
  int v23; // r6
  int v24; // r5
  int fadeEndTime; // r11
  idFadeHelper *p_fade; // r3
  int v27; // r3
  __int64 v28; // [sp+8h] [-D8h]
  __int64 v29; // [sp+10h] [-D0h]
  __int64 v30; // [sp+18h] [-C8h]
  __int64 v31; // [sp+20h] [-C0h]
  __int64 v32; // [sp+28h] [-B8h]
  float v33; // [sp+50h] [-90h] BYREF
  float v34[5]; // [sp+54h] [-8Ch] BYREF
  __int64 v35; // [sp+68h] [-78h]

  idPresentable::Interpolate(this, curTime, fraction);
  if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->breakableParent) )
  {
    this->origin = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->breakableParent)->origin;
    this->axis = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->breakableParent)->axis;
  }
  if ( !this->broken && this->currentExplodeFrame != this->explodeFrame )
  {
    this->Show(this);
    idEffectPhysicsBreakable::RemoveExplosions(this: &this->breakablePhysics);
    idEffectPhysicsBreakable::Reset(this: &this->breakablePhysics, skipModelReset: false);
    v34[3] = 1.0;
    v34[4] = 1.0;
    *(float *)&v35 = 1.0;
    *((float *)&v35 + 1) = 1.0;
    idPresentable::SetParm(
      this,
      parm: rp->Color,
      v4: v35,
      a4: v7,
      a5: v6,
      a6: (int)&r_cuttablemodel_freecpudata.description,
      a7: v5,
      a8: v28,
      a9: v29,
      a10: v30,
      a11: v31,
      a12: v32);
    activatorIndex = this->activatorIndex;
    if ( activatorIndex <= 0 )
      PresentableByIndex = nullptr;
    else
      PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: activatorIndex - 1);
    if ( presentable_breakable_debug.valueInteger != 0 )
    {
      hidden = this->hidden;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLib::Printf(
        fmt: "^4[%d][%d]::Interpolate -> Exploding. Activator: %d fadeTimeMS %d  fadeDelayMS %d  IsHidden %d\n",
        this->index,
        GameMs,
        this->activatorIndex,
        this->fadeTimeMS,
        this->fadeDelayMS,
        hidden);
    }
    if ( this->boneToOrientGibTo != -2 )
    {
      if ( PresentableByIndex == nullptr )
        goto LABEL_16;
      if ( PresentableByIndex->GetAnimatedEntityInterface(this: PresentableByIndex) != nullptr )
      {
        idPresentableBreakable::GibOrientedBodies(this, curTime, activator: PresentableByIndex);
LABEL_17:
        idEffectPhysicsBreakable::StartExplosions(
          this: &this->breakablePhysics,
          origin: &this->origin,
          axis: &this->axis,
          currentTime: curTime);
        this->broken = true;
        this->brokenStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        goto LABEL_18;
      }
    }
    if ( PresentableByIndex != nullptr )
    {
      idPresentableBreakable::GibWithActivator(this, curTime, activator: PresentableByIndex);
      goto LABEL_17;
    }
LABEL_16:
    idPresentableBreakable::GibDefault(this, curTime);
    goto LABEL_17;
  }
LABEL_18:
  v12 = this->hidden;
  this->currentExplodeFrame = this->explodeFrame;
  if ( !v12 )
  {
    if ( presentable_breakable_debug.valueInteger != 0 )
    {
      v13 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLib::Printf(
        fmt: "^4[%d][%d]::UpdatingSimulation serializeFrame %d  (%d - %d ) broken %d\n",
        this->index,
        v13,
        this->serializeFrame,
        this->currentExplodeFrame,
        this->explodeFrame,
        this->broken);
    }
    p_gameTimeManager = &clientGame->gameTimeManager;
    v15 = idAccolade::Count(this: &clientGame->gameTimeManager);
    GameMsPerFrame = (const char *)idGameTimeManager::GetGameMsPerFrame(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED);
    RealMsPerFrame = idGameTimeManager::GetRealMsPerFrame(this: p_gameTimeManager, type: GAMETIME_SCALED);
    idEffectPhysicsBreakable::UpdateSimulation(
      this: &this->breakablePhysics,
      origin: &this->origin,
      axis: &this->axis,
      currentTime: curTime,
      gameMsPerFrame: GameMsPerFrame,
      frameNum: v15,
      msPerFrame: RealMsPerFrame,
      dampening: 0.0);
    v18 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idEffectPhysicsBreakable::UpdateModel(
      this: &this->breakablePhysics,
      origin: &this->origin,
      axis: &this->axis,
      gameMsPerFrame: v18);
    idClientGame::AddSimulatingEffectPhysics(
      this: clientGame,
      broadPhase: &this->breakablePhysics.broadPhase,
      a3: v24,
      a4: v23,
      a5: v22,
      a6: v21,
      a7: v20,
      a8: v19,
      a9: SHIDWORD(v28),
      a10: v28,
      a11: SHIDWORD(v29),
      a12: v29,
      a13: SHIDWORD(v30),
      a14: (idEffectPhysicsBroadPhase *)v30);
    if ( this->brokenStartTime > 0
      && this->fadeTimeMS > 0
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->fadeDelayMS + this->brokenStartTime )
    {
      fadeEndTime = this->fade.fadeEndTime;
      if ( fadeEndTime == -1 )
      {
        if ( presentable_breakable_debug.valueInteger != 0 )
        {
          v27 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idLib::Printf(fmt: "^4[%d][%d]::Interpolate fade Done  \n", this->index, v27);
        }
        this->Hide(this, a2: true);
      }
      else
      {
        p_fade = &this->fade;
        if ( fadeEndTime > 0 )
        {
          idFadeHelper::Update(this: p_fade, presentable: this);
        }
        else
        {
          v33 = 0.0;
          v34[0] = 1.0;
          idFadeHelper::Fade(this: p_fade, from: v34, to: &v33, time: &this->fadeTimeMS, _noStippleFade: false);
        }
      }
    }
  }
}


// ========================================================================
// `dynamic initializer for 'g_gibImpulse''
// EA  : 0x8336DA50
// RVA : 0x0136DA50
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_gibImpulse__()
{
  idCVar::idCVar(
    this: &g_gibImpulse,
    name: "g_gibImpulse",
    value: "50000",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_gibImpulse__);
}


// ========================================================================
// `dynamic initializer for 'g_defaultImpulse''
// EA  : 0x8336DAA8
// RVA : 0x0136DAA8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_defaultImpulse__()
{
  idCVar::idCVar(
    this: &g_defaultImpulse,
    name: "g_defaultImpulse",
    value: "5000",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_defaultImpulse__);
}


// ========================================================================
// `dynamic initializer for 'presentable_breakable_debug''
// EA  : 0x8336DB00
// RVA : 0x0136DB00
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__presentable_breakable_debug__()
{
  idCVar::idCVar(
    this: &presentable_breakable_debug,
    name: "presentable_breakable_debug",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__presentable_breakable_debug__);
}


// ========================================================================
// `dynamic initializer for 'presentable_breakable_disablePredict''
// EA  : 0x8336DB58
// RVA : 0x0136DB58
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablebreakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__presentable_breakable_disablePredict__()
{
  idCVar::idCVar(
    this: &presentable_breakable_disablePredict,
    name: "presentable_breakable_disablePredict",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__presentable_breakable_disablePredict__);
}

