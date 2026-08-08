
// ========================================================================
// ?Hide@idBreakable@@UAAXXZ
// EA  : 0x82C0C5B8
// RVA : 0x00C0C5B8
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __fastcall idBreakable::Hide(idBreakable *this)
{
  idPhysics *Physics; // r3

  idEntity::Hide(this);
  Physics = idEntity::GetPhysics(this);
  Physics->DisableClip(this: Physics);
  if ( this->isPooled )
    idEntity::BecomeInactive(this, flags: 7);
}


// ========================================================================
// ?Spawn@idBreakable@@QAAXXZ
// EA  : 0x82C0C618
// RVA : 0x00C0C618
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __fastcall idBreakable::Spawn(idBreakable *this)
{
  idRenderModel *RenderModelFromPresentable; // r3
  idRenderModelDiscreteAnimation *v3; // r3
  idRenderModelDiscreteAnimation *v4; // r30
  const idDeclBreakable *declBreakable; // r11
  idPhysics *Physics; // r3
  int v7; // r10
  int v8; // r9
  int v9; // r8
  int v10; // r7
  idPresentable *presentable; // r11
  int v12; // r10
  int v13; // r9
  int v14; // r8
  int v15; // r7
  int v16; // r6
  int v17; // r5
  idPresentable *v18; // r3
  idSoundEmitter *SoundEmitter; // r3
  const idDeclImpactSound *impactSoundTable; // r8
  double v21; // fp13
  idPhysics *v22; // r27
  idPhysics *v23; // r29
  int GameMsPerFrame; // r26
  const idMat3 *v25; // r27
  const idVec3 *v26; // r3
  idPhysics *v27; // r3
  float *v28; // r3
  int v29; // [sp+8h] [-98h]
  int v30; // [sp+Ch] [-94h]
  int v31; // [sp+10h] [-90h]
  int v32; // [sp+14h] [-8Ch]
  int v33; // [sp+18h] [-88h]
  idPresentable *v34; // [sp+1Ch] [-84h]
  idEffectPhysicsBreakable::breakablePieceSound_t v35[3]; // [sp+50h] [-50h] BYREF

  this->currentHealth = this->health;
  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
  v3 = (idRenderModelDiscreteAnimation *)_RTDynamicCast(
                                           inptr: RenderModelFromPresentable,
                                           VfDelta: 0,
                                           SrcType: &idRenderModel `RTTI Type Descriptor',
                                           TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
                                           isReference: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    declBreakable = v3->declBreakable;
    if ( declBreakable != nullptr )
    {
      this->maxSimulationTime = (int)(float)(declBreakable->settings.maxSimulationTime * (float)1000.0);
      Physics = idEntity::GetPhysics(this);
      Physics->SetContents(this: Physics, a2: 1, a3: -1);
      presentable = this->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      idPresentable::SetClipModelInfo(
        this: presentable,
        clipModelInfo_: &this->clipModelInfo,
        clipModelSpawnPos_: &this->spawnPosition,
        clipModelSpawnAxis_: &this->spawnOrientation,
        a5: v10,
        a6: v9,
        a7: v8,
        a8: v7,
        a9: v29,
        a10: v30,
        a11: v31,
        a12: v32,
        a13: v33,
        a14: v34);
      v18 = this->presentable;
      if ( v18 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v18 = this->presentable;
      }
      idPresentable::SetClipModelContents(
        this: v18,
        newContents: 1,
        a3: v17,
        a4: v16,
        a5: v15,
        a6: v14,
        a7: v13,
        a8: v12);
      memset(v35, 0, 12);
      v35[0].nextSoundTime = 0;
      v35[0].minBounceVelSqr = 0.0;
      v35[0].soundWorld = clientGame->soundWorld;
      SoundEmitter = idEntity::GetSoundEmitter(this, alloc: true);
      impactSoundTable = this->impactSoundTable;
      v21 = (float)(this->pieceMinBounceVelocity * this->pieceMinBounceVelocity);
      v35[0].emitter = SoundEmitter;
      v35[0].channel = SND_CHANNEL_FX;
      v35[0].minBounceVelSqr = v21;
      v35[0].impactTable = impactSoundTable;
      idEffectPhysicsBreakable::Init(
        this: &this->breakablePhysics,
        clip: &clientGame->clip,
        tmc: &clientGame->traceModelCache,
        _gameLibEffects: &clientGame->gameLibEffects,
        model_: v4,
        entNum: this->entityNumber,
        _soundInfo: v35);
      if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) == 0 )
      {
        v22 = idEntity::GetPhysics(this);
        v23 = idEntity::GetPhysics(this);
        GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v25 = v22->GetAxis(this: v22, a2: 0);
        v26 = v23->GetOrigin(this: v23, a2: 0);
        idEffectPhysicsBreakable::UpdateModel(
          this: &this->breakablePhysics,
          origin: v26,
          axis: v25,
          gameMsPerFrame: GameMsPerFrame);
      }
      if ( !v4->deferredPositionInitialized || !v4->useDeferredPosition )
        v4->g.origin = vec3_origin;
      v4->deferredOrigin = vec3_origin;
      idRenderModel::SetAxis(this: v4, a: &mat3_identity);
      idRenderModel::CommitThisFrame(this: v4);
      idEntity::BecomeActive(this, flags: 1);
      if ( g_showBreakableCollision.valueInteger != 0 )
        idEntity::BecomeActive(this, flags: 4);
      v27 = idEntity::GetPhysics(this);
      v28 = (float *)v27->GetOrigin(this: v27, a2: 0);
      this->oldOrigin.x = *v28;
      this->oldOrigin.y = v28[1];
      this->oldOrigin.z = v28[2];
      this->velocity = vec3_origin;
    }
    else
    {
      idLib::Warning(fmt: "%s does not use a breakable decl", this->name.data);
    }
  }
  else
  {
    idLib::Warning(fmt: "%s does not use a breakable model", this->name.data);
  }
}


// ========================================================================
// ?AllocPresentable@idBreakable@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C0C920
// RVA : 0x00C0C920
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

idPresentableBreakable *__fastcall idBreakable::AllocPresentable(idBreakable *this, idTreeAnimator *renderModel_)
{
  idPresentableBreakable *v4; // r3
  idPresentableBreakable *v5; // r29

  v4 = (idPresentableBreakable *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x628u,
                                   tag: TAG_PRESENTABLE,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idPresentableBreakable::idPresentableBreakable(
           this: v4,
           ent: this,
           renderModel_,
           entityNumber_: this->entityNumber,
           fxDecl_: nullptr);
  else
    v5 = nullptr;
  idPresentableBreakable::SetInitProperties(
    this: v5,
    impactTable_: this->impactSoundTable,
    pieceMinBounceVelocity_: this->pieceMinBounceVelocity);
  return v5;
}


// ========================================================================
// __unwind$488613_0
// EA  : 0x82C0C9A8
// RVA : 0x00C0C9A8
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void _unwind_488613_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?PostBind@idBreakable@@UAAXXZ
// EA  : 0x82C0C9D8
// RVA : 0x00C0C9D8
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __fastcall idBreakable::PostBind(idBreakable *this)
{
  idPhysics *Physics; // r3

  idEntity::BecomeActive(this, flags: 2);
  Physics = idEntity::GetPhysics(this);
  this->oldOrigin = *Physics->GetOrigin(this: Physics, a2: 0);
  this->velocity = vec3_origin;
}


// ========================================================================
// ?GetModelTransform@idBreakable@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C0CA60
// RVA : 0x00C0CA60
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __fastcall idBreakable::GetModelTransform(idBreakable *this, idVec3 *modelOrigin, idMat3 *modelAxis)
{
  idPhysics *Physics; // r3
  idPhysics *v7; // r3

  Physics = idEntity::GetPhysics(this);
  *modelOrigin = *Physics->GetOrigin(this: Physics, a2: 0);
  v7 = idEntity::GetPhysics(this);
  *modelAxis = *v7->GetAxis(this: v7, a2: 0);
}


// ========================================================================
// ?Reset@idBreakable@@QAAXXZ
// EA  : 0x82C0CB18
// RVA : 0x00C0CB18
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __fastcall idBreakable::Reset(idBreakable *this)
{
  idEffectPhysicsBreakable *p_breakablePhysics; // r30
  idPhysics *Physics; // r29
  idPhysics *v4; // r28
  int GameMsPerFrame; // r27
  const idMat3 *v6; // r29
  const idVec3 *v7; // r3
  idPresentable *presentable; // r11
  idPresentable *v9; // r11

  if ( this->brokenStartTime != -1 )
  {
    p_breakablePhysics = &this->breakablePhysics;
    idEffectPhysicsBreakable::Reset(this: &this->breakablePhysics, skipModelReset: false);
    if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) == 0 )
    {
      Physics = idEntity::GetPhysics(this);
      v4 = idEntity::GetPhysics(this);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v6 = Physics->GetAxis(this: Physics, a2: 0);
      v7 = v4->GetOrigin(this: v4, a2: 0);
      idEffectPhysicsBreakable::UpdateModel(
        this: p_breakablePhysics,
        origin: v7,
        axis: v6,
        gameMsPerFrame: GameMsPerFrame);
    }
    idEntity::BecomeInactive(this, flags: 2);
    this->currentHealth = this->health;
    this->brokenStartTime = -1;
    this->brokenFrame = -1;
    this->fade.fadeStartTime = 0;
    this->fade.fadeFrom = 0.0;
    this->fade.fadeEndTime = 0;
    this->fade.fadeTo = 0.0;
    this->fade.noStippleFade = false;
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::SetParm(this: presentable, parm: rp->coverage, scalar: 1.0);
    v9 = this->presentable;
    if ( v9 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v9 = this->presentable;
    }
    idRenderModel::SetModelFade(this: v9->model, v: 1.0);
    if ( g_showBreakableCollision.valueInteger != 0 )
      idEntity::BecomeActive(this, flags: 4);
  }
}


// ========================================================================
// ?ResetRigidBodies@idBreakable@@QAAXXZ
// EA  : 0x82C0CCA0
// RVA : 0x00C0CCA0
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __fastcall idBreakable::ResetRigidBodies(idBreakable *this)
{
  idPresentable *presentable; // r11
  idPresentable *v3; // r11

  idEffectPhysicsBreakable::Reset(this: &this->breakablePhysics, skipModelReset: true);
  idEntity::BecomeInactive(this, flags: 2);
  this->brokenStartTime = -1;
  this->brokenFrame = -1;
  this->fade.fadeStartTime = 0;
  this->fade.fadeFrom = 0.0;
  this->fade.fadeEndTime = 0;
  this->fade.fadeTo = 0.0;
  this->fade.noStippleFade = false;
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::SetParm(this: presentable, parm: rp->coverage, scalar: 1.0);
  v3 = this->presentable;
  if ( v3 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v3 = this->presentable;
  }
  idRenderModel::SetModelFade(this: v3->model, v: 1.0);
  if ( g_showBreakableCollision.valueInteger != 0 )
    idEntity::BecomeActive(this, flags: 4);
}


// ========================================================================
// ?Show@idBreakable@@UAAXXZ
// EA  : 0x82C0CD90
// RVA : 0x00C0CD90
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __fastcall idBreakable::Show(idBreakable *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r30
  idPhysics *v4; // r29
  int GameMsPerFrame; // r28
  const idMat3 *v6; // r30
  const idVec3 *v7; // r3

  idEntity::Show(this);
  Physics = idEntity::GetPhysics(this);
  Physics->EnableClip(this: Physics);
  idEntity::BecomeActive(this, flags: 1);
  v3 = idEntity::GetPhysics(this);
  v4 = idEntity::GetPhysics(this);
  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v6 = v3->GetAxis(this: v3, a2: 0);
  v7 = v4->GetOrigin(this: v4, a2: 0);
  idEffectPhysicsBreakable::UpdateModel(
    this: &this->breakablePhysics,
    origin: v7,
    axis: v6,
    gameMsPerFrame: GameMsPerFrame);
}


// ========================================================================
// ?Break@idBreakable@@AAAXPAVidEntity@@@Z
// EA  : 0x82C0CE50
// RVA : 0x00C0CE50
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __fastcall idBreakable::Break(idBreakable *this, idVehicle *activator)
{
  idPresentable *presentable; // r3
  int v5; // r31
  idPhysics *Physics; // r3
  float *v7; // r3
  idPhysics *v8; // r3
  float *v9; // r3
  idPresentable *v10; // r4
  idPhysics *v11; // r3
  idClipModel *v12; // r3
  idVehicle *v13; // r3
  idPhysics *v14; // r3
  int v15; // r3
  float v16; // r7
  float v17; // r6
  idPhysics *v18; // r3
  float *v19; // r3
  idEffectPhysicsBreakable::idExplosion *list; // r7
  const idDeclParticle *particle; // r27
  double valueFloat; // fp31
  int v23; // r16
  double v24; // fp30
  int v25; // r15
  double v26; // fp29
  double v27; // fp28
  int GameMs; // r3
  int v29; // r10
  bool v30; // r9
  int v31; // r8
  int v32; // r7
  double v33; // fp28
  double v34; // fp30
  double v35; // fp27
  double v36; // fp29
  int v37; // r31
  int v38; // r3
  int v39; // r10
  bool v40; // r9
  int v41; // r8
  int v42; // r7
  double v43; // fp30
  int v44; // r25
  double v45; // fp31
  int v46; // r16
  double v47; // fp29
  double v48; // fp28
  int v49; // r3
  int v50; // r10
  bool v51; // r9
  int v52; // r8
  int v53; // r7
  double v54; // fp30
  double v55; // fp29
  double v56; // fp28
  int v57; // r31
  double v58; // fp27
  int v59; // r3
  int v60; // r10
  bool v61; // r9
  int v62; // r8
  int v63; // r7
  idPhysics *v64; // r31
  idPhysics *v65; // r29
  double v66; // fp10
  double v67; // fp8
  const idMat3 *v68; // r31
  const idVec3 *v69; // r3
  idPhysics *v70; // r3
  bool v71; // [sp+Bh] [-175h]
  bool v72; // [sp+Bh] [-175h]
  bool v73; // [sp+Bh] [-175h]
  const idVec3 *v74; // [sp+Ch] [-174h]
  const idVec3 *v75; // [sp+Ch] [-174h]
  const idVec3 *v76; // [sp+Ch] [-174h]
  bool v77; // [sp+13h] [-16Dh]
  bool v78; // [sp+13h] [-16Dh]
  bool v79; // [sp+13h] [-16Dh]
  int v80; // [sp+14h] [-16Ch]
  int v81; // [sp+14h] [-16Ch]
  int v82; // [sp+14h] [-16Ch]
  int v83; // [sp+18h] [-168h]
  int v84; // [sp+18h] [-168h]
  int v85; // [sp+18h] [-168h]
  int v86; // [sp+1Ch] [-164h]
  int v87; // [sp+1Ch] [-164h]
  int v88; // [sp+1Ch] [-164h]
  int v89; // [sp+20h] [-160h]
  int v90; // [sp+20h] [-160h]
  int v91; // [sp+20h] [-160h]
  int v92; // [sp+24h] [-15Ch]
  int v93; // [sp+24h] [-15Ch]
  int v94; // [sp+24h] [-15Ch]
  int v95; // [sp+28h] [-158h]
  int v96; // [sp+28h] [-158h]
  int v97; // [sp+28h] [-158h]
  int v98; // [sp+2Ch] [-154h]
  int v99; // [sp+2Ch] [-154h]
  int v100; // [sp+2Ch] [-154h]
  int v101; // [sp+30h] [-150h]
  int v102; // [sp+30h] [-150h]
  int v103; // [sp+30h] [-150h]
  int v104; // [sp+34h] [-14Ch]
  int v105; // [sp+34h] [-14Ch]
  int v106; // [sp+34h] [-14Ch]
  int v107; // [sp+38h] [-148h]
  int v108; // [sp+38h] [-148h]
  int v109; // [sp+38h] [-148h]
  int v110; // [sp+3Ch] [-144h]
  int v111; // [sp+3Ch] [-144h]
  int v112; // [sp+3Ch] [-144h]
  int v113; // [sp+40h] [-140h]
  int v114; // [sp+40h] [-140h]
  int v115; // [sp+40h] [-140h]
  int v116; // [sp+44h] [-13Ch]
  int v117; // [sp+44h] [-13Ch]
  int v118; // [sp+44h] [-13Ch]
  int v119; // [sp+48h] [-138h]
  int v120; // [sp+48h] [-138h]
  int v121; // [sp+48h] [-138h]
  int v122; // [sp+4Ch] [-134h]
  int v123; // [sp+4Ch] [-134h]
  int v124; // [sp+4Ch] [-134h]
  int v125; // [sp+50h] [-130h]
  int v126; // [sp+50h] [-130h]
  int v127; // [sp+50h] [-130h]
  int v128; // [sp+58h] [-128h]
  int v129; // [sp+58h] [-128h]
  int v130; // [sp+58h] [-128h]
  int v131; // [sp+60h] [-120h]
  int v132; // [sp+60h] [-120h]
  int v133; // [sp+60h] [-120h]
  int v134; // [sp+68h] [-118h]
  int v135; // [sp+68h] [-118h]
  int v136; // [sp+68h] [-118h]
  int v137; // [sp+70h] [-110h]
  int v138; // [sp+70h] [-110h]
  int v139; // [sp+70h] [-110h]
  int v140; // [sp+74h] [-10Ch]
  int v141; // [sp+74h] [-10Ch]
  int v142; // [sp+74h] [-10Ch]
  int v143; // [sp+78h] [-108h]
  int v144; // [sp+78h] [-108h]
  int v145; // [sp+78h] [-108h]
  int v146; // [sp+80h] [-100h]
  int v147; // [sp+80h] [-100h]
  int v148; // [sp+80h] [-100h]
  int v149; // [sp+88h] [-F8h]
  int v150; // [sp+88h] [-F8h]
  int v151; // [sp+88h] [-F8h]
  int v152; // [sp+98h] [-E8h] BYREF
  int v153; // [sp+9Ch] [-E4h]
  idVec3 v154; // [sp+A8h] [-D8h] BYREF
  idVec3 v155; // [sp+B8h] [-C8h] BYREF

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v5 = (int)presentable->GetBreakableInterface(this: presentable);
  idEntity::ForceDormancy(this, dormant: false, durationMS: 10000);
  Physics = idEntity::GetPhysics(this);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  *(float *)(v5 + 120) = *v7;
  *(float *)(v5 + 124) = v7[1];
  *(float *)(v5 + 128) = v7[2];
  v8 = idEntity::GetPhysics(this);
  v9 = (float *)v8->GetAxis(this: v8, a2: 0);
  *(float *)(v5 + 132) = *v9;
  *(float *)(v5 + 136) = v9[1];
  *(float *)(v5 + 140) = v9[2];
  *(float *)(v5 + 144) = v9[3];
  *(float *)(v5 + 148) = v9[4];
  *(float *)(v5 + 152) = v9[5];
  *(float *)(v5 + 156) = v9[6];
  *(float *)(v5 + 160) = v9[7];
  *(float *)(v5 + 164) = v9[8];
  if ( activator != nullptr )
  {
    v10 = activator->presentable;
    if ( v10 == nullptr )
    {
      idEntity::InitPresentableInternal(this: activator);
      v10 = activator->presentable;
    }
  }
  else
  {
    v10 = nullptr;
  }
  idPresentableBreakable::Break(this: (idPresentableBreakable *)v5, activator: v10);
  if ( this->brokenStartTime == -1 )
  {
    this->brokenStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->brokenFrame = idAccolade::Count(this: &clientGame->gameTimeManager) + 1;
    v11 = idEntity::GetPhysics(this);
    v12 = v11->GetClipModel(this: v11, a2: 0);
    idClipModel::Unlink(this: v12);
    v13 = idVehicle::CastTo(c: activator);
    if ( v13 != nullptr )
    {
      v14 = idEntity::GetPhysics(this: v13);
      v15 = (int)v14->GetOrigin(this: v14, a2: 0);
      v16 = *(float *)(v15 + 4);
      v17 = *(float *)(v15 + 8);
      v154.x = *(float *)v15;
      v154.y = v16;
      v154.z = v17;
      v18 = idEntity::GetPhysics(this);
      v19 = (float *)v18->GetOrigin(this: v18, a2: 0);
      v154.x = v154.x - *v19;
      v154.y = v154.y - v19[1];
      list = this->breakablePhysics.explosions.list;
      v154.z = (float)(v154.z - v19[2]) + g_breakableOffset.valueFloat;
      particle = list->decl.particle;
      if ( g_breakableExplosion.valueInteger == 1 )
      {
        idEffectPhysicsBreakable::RemoveExplosions(this: &this->breakablePhysics);
        valueFloat = g_breakableAngular.valueFloat;
        v23 = (int)(float)(g_breakableDuration.valueFloat * (float)1000.0);
        v24 = g_breakableFalloff.valueFloat;
        v25 = (int)(float)(g_breakableDelay.valueFloat * (float)1000.0);
        v26 = g_breakableImpulse.valueFloat;
        v27 = g_breakableRadius.valueFloat;
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idEffectPhysicsBreakable::AddExplosion(
          this: &this->breakablePhysics,
          particle,
          time: GameMs,
          position: &v154,
          radius: v27,
          impulse: v26,
          falloff: v24,
          angular: valueFloat,
          delay: v32,
          duration: v31,
          startNow: v30,
          activateAllDelay: v29,
          distTimeScaleDelay: 0.0,
          useLinear: v71,
          endLinear: v74,
          localSpace: v77,
          a17: v80,
          a18: v83,
          a19: v86,
          a20: v89,
          a21: v92,
          a22: v95,
          a23: v98,
          a24: v101,
          a25: v104,
          a26: v107,
          a27: v110,
          a28: v113,
          a29: v116,
          a30: v119,
          a31: v122,
          a32: v125,
          a33: v25,
          a34: v128,
          a35: v23,
          a36: v131,
          a37: 0,
          a38: v134,
          a39: 0,
          a40: v137,
          delay_0: v140,
          a42: v143,
          duration_0_3: false,
          a44: v146,
          a45: &vec3_origin.x,
          a46: v149,
          activateAllDelay_0_3: true);
        v33 = (float)(g_breakableImpulse.valueFloat * (float)0.1);
        v34 = g_breakableAngular.valueFloat;
        v35 = (float)(g_breakableRadius.valueFloat * (float)3.0);
        v36 = g_breakableFalloff.valueFloat;
        v37 = (int)(float)(g_breakableDuration.valueFloat * 1000.0);
        v153 = (int)(float)((float)(g_breakableDelay.valueFloat + (float)0.1) * 1000.0);
        v38 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idEffectPhysicsBreakable::AddExplosion(
          this: &this->breakablePhysics,
          particle,
          time: v38,
          position: &v154,
          radius: v35,
          impulse: v33,
          falloff: v36,
          angular: v34,
          delay: v42,
          duration: v41,
          startNow: v40,
          activateAllDelay: v39,
          distTimeScaleDelay: 0.0,
          useLinear: v72,
          endLinear: v75,
          localSpace: v78,
          a17: v81,
          a18: v84,
          a19: v87,
          a20: v90,
          a21: v93,
          a22: v96,
          a23: v99,
          a24: v102,
          a25: v105,
          a26: v108,
          a27: v111,
          a28: v114,
          a29: v117,
          a30: v120,
          a31: v123,
          a32: v126,
          a33: v153,
          a34: v129,
          a35: v37,
          a36: v132,
          a37: 0,
          a38: v135,
          a39: 0,
          a40: v138,
          delay_0: v141,
          a42: v144,
          duration_0_3: false,
          a44: v147,
          a45: &vec3_origin.x,
          a46: v150,
          activateAllDelay_0_3: true);
      }
      else if ( g_breakableExplosion.valueInteger == 2 )
      {
        idEffectPhysicsBreakable::RemoveExplosions(this: &this->breakablePhysics);
        v43 = g_breakableAngular.valueFloat;
        v44 = (int)(float)(g_breakableDuration.valueFloat * (float)1000.0);
        v45 = g_breakableFalloff.valueFloat;
        v46 = (int)(float)(g_breakableDelay.valueFloat * (float)1000.0);
        v47 = g_breakableImpulse.valueFloat;
        v48 = g_breakableRadius.valueFloat;
        v49 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idEffectPhysicsBreakable::AddExplosion(
          this: &this->breakablePhysics,
          particle,
          time: v49,
          position: &v154,
          radius: v48,
          impulse: v47,
          falloff: v45,
          angular: v43,
          delay: v53,
          duration: v52,
          startNow: v51,
          activateAllDelay: v50,
          distTimeScaleDelay: 0.0,
          useLinear: v71,
          endLinear: v74,
          localSpace: v77,
          a17: v80,
          a18: v83,
          a19: v86,
          a20: v89,
          a21: v92,
          a22: v95,
          a23: v98,
          a24: v101,
          a25: v104,
          a26: v107,
          a27: v110,
          a28: v113,
          a29: v116,
          a30: v119,
          a31: v122,
          a32: v125,
          a33: v46,
          a34: v128,
          a35: v44,
          a36: v131,
          a37: 0,
          a38: v134,
          a39: 0,
          a40: v137,
          delay_0: v140,
          a42: v143,
          duration_0_3: false,
          a44: v146,
          a45: &vec3_origin.x,
          a46: v149,
          activateAllDelay_0_3: true);
        v154.z = 0.0;
        v154.y = 0.0;
        v54 = g_breakableAngular.valueFloat;
        v55 = g_breakableFalloff.valueFloat;
        v56 = g_breakableImpulse.valueFloat;
        v154.x = 0.0;
        v57 = (int)(float)(g_breakableDuration.valueFloat * 1000.0);
        v153 = (int)(float)((float)(g_breakableDelay.valueFloat + (float)0.5) * 1000.0);
        v58 = (float)(g_breakableRadius.valueFloat * (float)3.0);
        v59 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idEffectPhysicsBreakable::AddExplosion(
          this: &this->breakablePhysics,
          particle,
          time: v59,
          position: &v154,
          radius: v58,
          impulse: v56,
          falloff: v55,
          angular: v54,
          delay: v63,
          duration: v62,
          startNow: v61,
          activateAllDelay: v60,
          distTimeScaleDelay: 0.0,
          useLinear: v73,
          endLinear: v76,
          localSpace: v79,
          a17: v82,
          a18: v85,
          a19: v88,
          a20: v91,
          a21: v94,
          a22: v97,
          a23: v100,
          a24: v103,
          a25: v106,
          a26: v109,
          a27: v112,
          a28: v115,
          a29: v118,
          a30: v121,
          a31: v124,
          a32: v127,
          a33: v153,
          a34: v130,
          a35: v57,
          a36: v133,
          a37: 0,
          a38: v136,
          a39: 0,
          a40: v139,
          delay_0: v142,
          a42: v145,
          duration_0_3: false,
          a44: v148,
          a45: &vec3_origin.x,
          a46: v151,
          activateAllDelay_0_3: true);
      }
    }
    v64 = idEntity::GetPhysics(this);
    v65 = idEntity::GetPhysics(this);
    v66 = (float)(this->velocity.z * this->velocityScale);
    v67 = (float)(this->velocity.y * this->velocityScale);
    v155.x = this->velocity.x * this->velocityScale;
    v155.z = v66;
    v155.y = v67;
    v68 = v64->GetAxis(this: v64, a2: 0);
    v69 = v65->GetOrigin(this: v65, a2: 0);
    idEffectPhysicsBreakable::ApplyForce(this: &this->breakablePhysics, origin: v69, axis: v68, force: &v155);
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_CRASH,
      shader: this->soundExplosion,
      soundShaderFlags: 0,
      peerMask: 0xFFu);
    idEntity::BecomeActive(this, flags: 2);
    this->ActivateTargets(this, a2: activator);
    v70 = idEntity::GetPhysics(this);
    ((void (__fastcall *)(int *))v70->GetLinearVelocity)(a1: &v152);
  }
}


// ========================================================================
// ?ApplyImpulse@idBreakable@@UAAXHHABVidVec3@@0@Z
// EA  : 0x82C0D4C8
// RVA : 0x00C0D4C8
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __fastcall idBreakable::ApplyImpulse(
        idBreakable *this,
        int physId,
        const int bodyId,
        const idVec3 *point,
        const idVec3 *impulse)
{
  idPhysics *PhysicsForId; // r3
  idPhysics *v7; // r31
  idTarget_ApplyImpulse *v8; // r30
  idTarget_ApplyImpulse *v9; // r11
  double breakableRadius; // fp31
  double breakableImpulse; // fp30
  double breakableFalloff; // fp29
  double breakableAngular; // fp28
  double breakableDelay; // fp27
  double breakableDuration; // fp26
  idPhysics *Physics; // r3
  float *v17; // r28
  float *v18; // r3
  double v19; // fp9
  double v20; // fp7
  int GameMs; // r3
  bool v22; // [sp+Bh] [-F5h]
  const idVec3 *v23; // [sp+Ch] [-F4h]
  bool v24; // [sp+13h] [-EDh]
  int v25; // [sp+14h] [-ECh]
  int v26; // [sp+18h] [-E8h]
  int v27; // [sp+1Ch] [-E4h]
  int v28; // [sp+20h] [-E0h]
  int v29; // [sp+24h] [-DCh]
  int v30; // [sp+28h] [-D8h]
  int v31; // [sp+2Ch] [-D4h]
  int v32; // [sp+30h] [-D0h]
  int v33; // [sp+34h] [-CCh]
  int v34; // [sp+38h] [-C8h]
  int v35; // [sp+3Ch] [-C4h]
  int v36; // [sp+40h] [-C0h]
  int v37; // [sp+44h] [-BCh]
  int v38; // [sp+48h] [-B8h]
  int v39; // [sp+4Ch] [-B4h]
  int v40; // [sp+50h] [-B0h]
  int v41; // [sp+58h] [-A8h]
  int v42; // [sp+60h] [-A0h]
  int v43; // [sp+68h] [-98h]
  int v44; // [sp+70h] [-90h]
  int v45; // [sp+74h] [-8Ch]
  int v46; // [sp+78h] [-88h]
  int v47; // [sp+80h] [-80h]
  int v48; // [sp+88h] [-78h]
  idVec3 v49; // [sp+98h] [-68h] BYREF

  PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: physId);
  v7 = PhysicsForId;
  if ( PhysicsForId != nullptr )
  {
    v8 = (idTarget_ApplyImpulse *)gameLocal->entities.ptr[PhysicsForId->entityNumber];
    v9 = idTarget_ApplyImpulse::CastTo(c: v8);
    if ( v9 != nullptr )
    {
      breakableRadius = v9->breakableRadius;
      breakableImpulse = v9->breakableImpulse;
      breakableFalloff = v9->breakableFalloff;
      breakableAngular = v9->breakableAngular;
      breakableDelay = v9->breakableDelay;
      breakableDuration = v9->breakableDuration;
      Physics = idEntity::GetPhysics(this);
      v17 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v18 = (float *)v7->GetOrigin(this: v7, a2: 0);
      v19 = (float)(v18[2] - v17[2]);
      v20 = (float)(v18[1] - v17[1]);
      v49.x = *v18 - *v17;
      v49.z = v19;
      v49.y = v20;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idEffectPhysicsBreakable::AddExplosion(
        this: &this->breakablePhysics,
        particle: nullptr,
        time: GameMs,
        position: &v49,
        radius: breakableRadius,
        impulse: breakableImpulse,
        falloff: breakableFalloff,
        angular: breakableAngular,
        delay: (const int)&vec3_origin,
        duration: (int)breakableDuration,
        startNow: (const bool)allocationCurrent[242],
        activateAllDelay: (int)breakableDelay,
        distTimeScaleDelay: 0.0,
        useLinear: v22,
        endLinear: v23,
        localSpace: v24,
        a17: v25,
        a18: v26,
        a19: v27,
        a20: v28,
        a21: v29,
        a22: v30,
        a23: v31,
        a24: v32,
        a25: v33,
        a26: v34,
        a27: v35,
        a28: v36,
        a29: v37,
        a30: v38,
        a31: v39,
        a32: v40,
        a33: (int)breakableDelay,
        a34: v41,
        a35: (int)breakableDuration,
        a36: v42,
        a37: 0,
        a38: v43,
        a39: 0,
        a40: v44,
        delay_0: v45,
        a42: v46,
        duration_0_3: false,
        a44: v47,
        a45: &vec3_origin.x,
        a46: v48,
        activateAllDelay_0_3: true);
      idBreakable::Break(this, activator: (idVehicle *)v8);
    }
  }
}


// ========================================================================
// ?Damage@idBreakable@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82C0D648
// RVA : 0x00C0D648
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

float __fastcall idBreakable::Damage(
        idBreakable *this,
        idEntity *inflictor,
        idVehicle *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        int a8)
{
  double v15; // fp1
  double v16; // fp1
  double v17; // fp0
  idPhysics *Physics; // r3
  double v19; // fp30
  double v20; // fp29
  double v21; // fp28
  float *v22; // r3
  double v23; // fp8
  double v24; // fp6
  idPhysics *v25; // r3
  float *v26; // r3
  double valueFloat; // fp30
  double v28; // fp29
  double v29; // fp28
  int GameMs; // r3
  int v31; // r8
  int v32; // r11
  idPhysics *v33; // r3
  int v34; // r9
  float v35; // r8
  idPhysics *v36; // r3
  double v37; // fp30
  double v38; // fp29
  double v39; // fp28
  float *v40; // r3
  double v41; // fp27
  double v42; // fp26
  double v43; // fp25
  double v44; // fp28
  idPhysics *v45; // r3
  float *v46; // r3
  double v47; // fp30
  double v48; // fp29
  double v49; // fp3
  double v50; // fp12
  double v51; // fp13
  double v52; // fp11
  int v53; // r3
  bool v55; // [sp+Bh] [-135h]
  const idVec3 *v56; // [sp+Ch] [-134h]
  bool v57; // [sp+13h] [-12Dh]
  int v58; // [sp+14h] [-12Ch]
  int v59; // [sp+18h] [-128h]
  int v60; // [sp+1Ch] [-124h]
  int v61; // [sp+20h] [-120h]
  int v62; // [sp+24h] [-11Ch]
  int v63; // [sp+28h] [-118h]
  int v64; // [sp+2Ch] [-114h]
  int v65; // [sp+30h] [-110h]
  int v66; // [sp+34h] [-10Ch]
  int v67; // [sp+38h] [-108h]
  int v68; // [sp+3Ch] [-104h]
  int v69; // [sp+40h] [-100h]
  int v70; // [sp+44h] [-FCh]
  int v71; // [sp+48h] [-F8h]
  int v72; // [sp+4Ch] [-F4h]
  int v73; // [sp+50h] [-F0h]
  int v74; // [sp+58h] [-E8h]
  int v75; // [sp+60h] [-E0h]
  int v76; // [sp+68h] [-D8h]
  int v77; // [sp+70h] [-D0h]
  int v78; // [sp+74h] [-CCh]
  int v79; // [sp+78h] [-C8h]
  int v80; // [sp+80h] [-C0h]
  int v81; // [sp+88h] [-B8h]
  float v82[2]; // [sp+90h] [-B0h] BYREF
  float v83; // [sp+98h] [-A8h]
  int v84; // [sp+9Ch] [-A4h]
  float v85; // [sp+A0h] [-A0h]
  idVec3 v86; // [sp+A8h] [-98h] BYREF
  idVec3 v87; // [sp+B8h] [-88h] BYREF

  if ( this->TakesDamage(this) && this->brokenStartTime == -1 )
  {
    v82[0] = 0.0;
    if ( damageDef != nullptr
      && (v16 = idDeclDamage::DamageAmount(this: damageDef),
          v17 = (float)((float)v16 * (float)damageScale),
          v82[0] = (float)v16 * (float)damageScale,
          v17 != 0.0)
      && (damageDef->damageTypes & ~this->ignoreDamageType) != 0 )
    {
      if ( this->currentHealth <= v17 )
      {
        this->currentHealth = 0.0;
        if ( g_breakableAddVehicleExplosion.valueInteger != 0 )
        {
          Physics = idEntity::GetPhysics(this);
          v19 = (float)(trace->fraction * g_breakableVehicleOffset.valueFloat);
          v20 = (float)(trace->endpos.x * g_breakableVehicleOffset.valueFloat);
          v21 = (float)(trace->endpos.y * g_breakableVehicleOffset.valueFloat);
          v22 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          v23 = (float)(v22[2] + (float)v21);
          v24 = (float)(v22[1] + (float)v20);
          v86.x = *v22 + (float)v19;
          v86.z = v23;
          v86.y = v24;
          v25 = idEntity::GetPhysics(this);
          v26 = (float *)v25->GetOrigin(this: v25, a2: 0);
          v86.x = v86.x - *v26;
          v86.y = v86.y - v26[1];
          v86.z = v86.z - v26[2];
          valueFloat = g_breakableAngular.valueFloat;
          v28 = g_breakableFalloff.valueFloat;
          v29 = g_breakableVehicleImpulse.valueFloat;
          v84 = (int)(float)(g_breakableDuration.valueFloat * (float)1000.0);
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idEffectPhysicsBreakable::AddExplosion(
            this: &this->breakablePhysics,
            particle: nullptr,
            time: GameMs,
            position: &v86,
            radius: 1024.0,
            impulse: v29,
            falloff: v28,
            angular: valueFloat,
            delay: (const int)&off_82040000,
            duration: v31,
            startNow: true,
            activateAllDelay: (const int)&vec3_origin,
            distTimeScaleDelay: 0.0,
            useLinear: v55,
            endLinear: v56,
            localSpace: v57,
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
            a28: v69,
            a29: v70,
            a30: v71,
            a31: v72,
            a32: v73,
            a33: 0,
            a34: v74,
            a35: v84,
            a36: v75,
            a37: 0,
            a38: v76,
            a39: 0,
            a40: v77,
            delay_0: v78,
            a42: v79,
            duration_0_3: false,
            a44: v80,
            a45: &vec3_origin.x,
            a46: v81,
            activateAllDelay_0_3: true);
        }
        else
        {
          if ( a8 != 0 )
          {
            v32 = a8 + 4;
          }
          else
          {
            v33 = idEntity::GetPhysics(this);
            v32 = (int)v33->GetOrigin(this: v33, a2: 0);
          }
          v34 = *(int *)(v32 + 4);
          v35 = *(float *)(v32 + 8);
          v83 = *(float *)v32;
          v84 = v34;
          v85 = v35;
          v36 = idEntity::GetPhysics(this);
          v37 = (float)(v83 - (float)(trace->fraction * g_breakableCharOffset.valueFloat));
          v38 = (float)(*(float *)&v84 - (float)(trace->endpos.x * g_breakableCharOffset.valueFloat));
          v39 = (float)(v85 - (float)(trace->endpos.y * g_breakableCharOffset.valueFloat));
          v40 = (float *)v36->GetOrigin(this: v36, a2: 0);
          v41 = (float)((float)v37 - *v40);
          v42 = (float)(damageDef->ragdollImpulseMag * g_breakableCharImpulseScale.valueFloat);
          v43 = (float)((float)v38 - v40[1]);
          v44 = (float)((float)v39 - v40[2]);
          v45 = idEntity::GetPhysics(this);
          v46 = (float *)v45->GetAxis(this: v45, a2: 0);
          v47 = g_breakableCharAngular.valueFloat;
          v48 = g_breakableCharRadius.valueFloat;
          v49 = v46[3];
          v50 = *v46;
          v51 = (float)((float)(v46[5] * (float)v44) + (float)(v46[4] * (float)v43));
          v52 = (float)((float)(v46[2] * (float)v44) + (float)(v46[1] * (float)v43));
          v87.z = (float)(v46[6] * (float)v41) + (float)((float)(v46[8] * (float)v44) + (float)(v46[7] * (float)v43));
          v87.y = (float)((float)v49 * (float)v41) + (float)v51;
          v87.x = (float)((float)v50 * (float)v41) + (float)v52;
          v84 = (int)(float)(g_breakableDuration.valueFloat * (float)1000.0);
          v53 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idEffectPhysicsBreakable::AddExplosion(
            this: &this->breakablePhysics,
            particle: nullptr,
            time: v53,
            position: &v87,
            radius: v48,
            impulse: v42,
            falloff: 0.2,
            angular: v47,
            delay: (const int)allocationCurrent[242],
            duration: (const int)&off_82040000,
            startNow: true,
            activateAllDelay: (const int)&vec3_origin,
            distTimeScaleDelay: 0.0,
            useLinear: v55,
            endLinear: v56,
            localSpace: v57,
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
            a28: v69,
            a29: v70,
            a30: v71,
            a31: v72,
            a32: v73,
            a33: 0,
            a34: v74,
            a35: v84,
            a36: v75,
            a37: 0,
            a38: v76,
            a39: 0,
            a40: v77,
            delay_0: v78,
            a42: v79,
            duration_0_3: false,
            a44: v80,
            a45: &vec3_origin.x,
            a46: v81,
            activateAllDelay_0_3: true);
        }
        idBreakable::Break(this, activator: attacker);
        v15 = v82[0];
      }
      else
      {
        this->currentHealth = this->currentHealth - (float)((float)v16 * (float)damageScale);
        if ( attacker != nullptr )
          attacker->DamageFeedback(this: attacker, a2: this, a3: inflictor, a4: damageDef, a5: v82);
        else
          idLib::Warning(fmt: "NULL attacker in idBreakable::Damage");
        v15 = v82[0];
      }
    }
    else
    {
      v15 = 0.0;
    }
  }
  else
  {
    v15 = 0.0;
  }
  return *((float *)&v15 + 1);
}


// ========================================================================
// ?AddExplosion@idBreakable@@QAA?AVidVec3@@ABV2@M@Z
// EA  : 0x82C0DB18
// RVA : 0x00C0DB18
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

idBreakable *__fastcall idBreakable::AddExplosion(
        idBreakable *this,
        idBreakable *result,
        const idVec3 *pos,
        double impulse)
{
  idPhysics *Physics; // r3
  float *v9; // r3
  double v10; // fp31
  double v11; // fp30
  double v12; // fp28
  idPhysics *v13; // r3
  float *v14; // r3
  double v15; // fp12
  double v16; // fp11
  double v17; // fp9
  double v18; // fp8
  idGameTimeManager *p_gameTimeManager; // r3
  double v20; // fp7
  double valueFloat; // fp31
  int v22; // r29
  double v23; // fp30
  int GameMs; // r3
  int v25; // r8
  bool v27; // [sp+Bh] [-D5h]
  const idVec3 *v28; // [sp+Ch] [-D4h]
  bool v29; // [sp+13h] [-CDh]
  int v30; // [sp+14h] [-CCh]
  int v31; // [sp+18h] [-C8h]
  int v32; // [sp+1Ch] [-C4h]
  int v33; // [sp+20h] [-C0h]
  int v34; // [sp+24h] [-BCh]
  int v35; // [sp+28h] [-B8h]
  int v36; // [sp+2Ch] [-B4h]
  int v37; // [sp+30h] [-B0h]
  int v38; // [sp+34h] [-ACh]
  int v39; // [sp+38h] [-A8h]
  int v40; // [sp+3Ch] [-A4h]
  int v41; // [sp+40h] [-A0h]
  int v42; // [sp+44h] [-9Ch]
  int v43; // [sp+48h] [-98h]
  int v44; // [sp+4Ch] [-94h]
  int v45; // [sp+50h] [-90h]
  int v46; // [sp+58h] [-88h]
  int v47; // [sp+60h] [-80h]
  int v48; // [sp+68h] [-78h]
  int v49; // [sp+70h] [-70h]
  int v50; // [sp+74h] [-6Ch]
  int v51; // [sp+78h] [-68h]
  int v52; // [sp+80h] [-60h]
  int v53; // [sp+88h] [-58h]

  Physics = idEntity::GetPhysics(this: result);
  v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v10 = (float)(pos->x - *v9);
  v11 = (float)(pos->y - v9[1]);
  v12 = (float)(pos->z - v9[2]);
  v13 = idEntity::GetPhysics(this: result);
  v14 = (float *)v13->GetAxis(this: v13, a2: 0);
  v15 = v14[3];
  v16 = *v14;
  v17 = (float)((float)(v14[5] * (float)v12) + (float)(v14[4] * (float)v11));
  v18 = (float)((float)(v14[2] * (float)v12) + (float)(v14[1] * (float)v11));
  v20 = (float)((float)(v14[6] * (float)v10) + (float)((float)(v14[8] * (float)v12) + (float)(v14[7] * (float)v11)));
  p_gameTimeManager = &clientGame->gameTimeManager;
  *(float *)&this->listeningToList = v20;
  *(float *)&this->listenerList = (float)((float)v15 * (float)v10) + (float)v17;
  *(float *)&this->__vftable = (float)((float)v16 * (float)v10) + (float)v18;
  valueFloat = g_breakableCharAngular.valueFloat;
  v22 = (int)(float)(g_breakableDuration.valueFloat * (float)1000.0);
  v23 = g_breakableCharRadius.valueFloat;
  GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
  idEffectPhysicsBreakable::AddExplosion(
    this: &result->breakablePhysics,
    particle: nullptr,
    time: GameMs,
    position: (const idVec3 *)this,
    radius: v23,
    impulse,
    falloff: 0.2,
    angular: valueFloat,
    delay: (const int)&off_82040000,
    duration: v25,
    startNow: true,
    activateAllDelay: (const int)&vec3_origin,
    distTimeScaleDelay: 0.0,
    useLinear: v27,
    endLinear: v28,
    localSpace: v29,
    a17: v30,
    a18: v31,
    a19: v32,
    a20: v33,
    a21: v34,
    a22: v35,
    a23: v36,
    a24: v37,
    a25: v38,
    a26: v39,
    a27: v40,
    a28: v41,
    a29: v42,
    a30: v43,
    a31: v44,
    a32: v45,
    a33: 0,
    a34: v46,
    a35: v22,
    a36: v47,
    a37: 0,
    a38: v48,
    a39: 0,
    a40: v49,
    delay_0: v50,
    a42: v51,
    duration_0_3: false,
    a44: v52,
    a45: &vec3_origin.x,
    a46: v53,
    activateAllDelay_0_3: true);
  idBreakable::Break(this: result, activator: nullptr);
  return this;
}


// ========================================================================
// ?OnActivate@idBreakable@@EAAXPAVidEntity@@@Z
// EA  : 0x82C0DCC0
// RVA : 0x00C0DCC0
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

// attributes: thunk
void __fastcall idBreakable::OnActivate(idBreakable *this, idVehicle *activator)
{
  idBreakable::Break(this, activator);
}


// ========================================================================
// ??0idBreakable@@QAA@XZ
// EA  : 0x82C0DCD0
// RVA : 0x00C0DCD0
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

idBreakable *__fastcall idBreakable::idBreakable(idBreakable *this)
{
  float z; // r6

  idEntity::idEntity(this);
  this->soundExplosion = nullptr;
  this->__vftable = (idBreakable_vtbl *)&idBreakable::`vftable';
  this->pieceMinBounceVelocity = 40.0;
  this->impactSoundTable = nullptr;
  this->targetable = false;
  this->ignoreDamageType = DAMAGETYPE_NONE;
  this->isPooled = false;
  this->breakState.list = nullptr;
  this->breakState.granularity = 0;
  this->breakState.memTag = 5;
  this->breakState.listStatic = 0;
  this->breakState.size = 0;
  this->breakState.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->breakState);
  idEffectPhysicsBreakable::idEffectPhysicsBreakable(this: &this->breakablePhysics);
  this->soundOffset.x = vec3_origin.x;
  this->soundOffset.y = vec3_origin.y;
  z = vec3_origin.z;
  this->currentHealth = 0.0;
  this->soundOffset.z = z;
  this->health = 0.0;
  this->fadeTime = 1.0;
  this->maxSimulationTime = 0;
  this->fadeDelay = 0.0;
  this->brokenStartTime = -1;
  this->velocityScale = 1.0;
  this->brokenFrame = -1;
  this->fadeBroken = false;
  this->fade.fadeFrom = 0.0;
  this->fade.fadeTo = 0.0;
  this->fade.fadeStartTime = 0;
  this->fade.fadeEndTime = 0;
  this->fade.noStippleFade = false;
  this->oldOrigin = vec3_origin;
  this->velocity = vec3_origin;
  this->fade.fadeFrom = 0.0;
  this->fade.fadeTo = 0.0;
  this->fade.fadeStartTime = 0;
  this->fade.fadeEndTime = 0;
  this->fade.noStippleFade = false;
  *(_BYTE *)&this->flags |= 0x42u;
  return this;
}


// ========================================================================
// __unwind$489477_0
// EA  : 0x82C0DE24
// RVA : 0x00C0DE24
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void _unwind_489477_0()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489478_0
// EA  : 0x82C0DE4C
// RVA : 0x00C0DE4C
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void _unwind_489478_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 824));
}


// ========================================================================
// ??1idBreakable@@UAA@XZ
// EA  : 0x82C0DEC8
// RVA : 0x00C0DEC8
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __fastcall idBreakable::~idBreakable(idBreakable *this)
{
  this->__vftable = (idBreakable_vtbl *)&idBreakable::`vftable';
  idClientGame::RemoveSimulatingEffectPhysics(this: clientGame, broadPhase: &this->breakablePhysics.broadPhase);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->breakablePhysics);
  idEffectPhysicsBreakable::~idEffectPhysicsBreakable(this: &this->breakablePhysics);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->breakState);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$489731
// EA  : 0x82C0DF28
// RVA : 0x00C0DF28
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void _unwind_489731()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489732
// EA  : 0x82C0DF50
// RVA : 0x00C0DF50
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void _unwind_489732()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 824));
}


// ========================================================================
// __unwind$489733
// EA  : 0x82C0DF7C
// RVA : 0x00C0DF7C
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void _unwind_489733()
{
  int v0; // r12

  idEffectPhysicsBreakable::~idEffectPhysicsBreakable(this: (idEffectPhysicsBreakable *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                       + 840));
}


// ========================================================================
// ?Think@idBreakable@@UAAXXZ
// EA  : 0x82C0E010
// RVA : 0x00C0E010
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __fastcall idBreakable::Think(idBreakable *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPhysics *Physics; // r29
  idPhysics *v5; // r26
  int GameMs; // r25
  const idMat3 *v7; // r29
  const idVec3 *v8; // r3
  float *presentable; // r29
  idPhysics *v10; // r3
  float *v11; // r3
  idPhysics *v12; // r3
  float *v13; // r3
  double v14; // fp9
  double v15; // fp7
  idPhysics *v16; // r26
  idPhysics *v17; // r24
  idGameTimeManager *p_gameTimeManager; // r29
  int v19; // r23
  const char *v20; // r22
  int v21; // r21
  double RealMsPerFrame; // fp30
  const idMat3 *v23; // r26
  const idVec3 *v24; // r3
  int v25; // r10
  int v26; // r9
  int v27; // r8
  int idCombatStage_useRelaxedChatterVO; // r7
  int v29; // r6
  int v30; // r5
  idPhysics *v31; // r26
  idPhysics *v32; // r24
  int v33; // r23
  const idMat3 *v34; // r26
  const idVec3 *v35; // r3
  int maxSimulationTime; // r10
  int brokenStartTime; // r9
  idPhysics *v38; // r29
  idPhysics *v39; // r26
  int GameMsPerFrame; // r24
  const idMat3 *v41; // r29
  const idVec3 *v42; // r3
  idPhysics *v43; // r3
  const idBounds *v44; // r3
  int v45; // r11
  idCommon_vtbl *v46; // r9
  int v47; // r26
  int v48; // r29
  idPresentable *v49; // r3
  int v50; // r3
  int fadeEndTime; // r11
  double v52; // fp12
  idPresentable *v53; // r4
  idRenderModelEffects *effectsModel; // r16
  int v55; // r17
  int v56; // r20
  int v57; // r22
  int v58; // r29
  int v59; // r18
  __int64 v60; // r5
  int i; // r19
  breakState_t *v62; // r10
  signed int smokeSystemRate; // r11
  unsigned int v64; // r9
  double v65; // fp31
  idPhysics *v66; // r3
  int v67; // r3
  idVec3 *v68; // r10
  float *v69; // r9
  int j; // ctr
  idPhysics *v71; // r3
  breakState_t *v72; // r11
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // r8
  double y; // fp8
  double v75; // fp29
  double v76; // fp28
  double v77; // fp27
  float *v78; // r3
  breakState_t *list; // r7
  double v80; // fp7
  double v81; // fp6
  idPhysics *v82; // r29
  __int64 v83; // r11
  double v84; // fp31
  float *v85; // r3
  double x; // fp11
  double z; // fp10
  double v88; // fp8
  double v89; // fp3
  double v90; // fp2
  idPhysics *v91; // r3
  float *v92; // r3
  idPlayer *Player; // r28
  idPhysics *v94; // r27
  idPhysics *v95; // r28
  float *v96; // r27
  float *v97; // r3
  double v98; // fp10
  double v99; // fp6
  unsigned int v100; // r29
  idPhysics *v101; // r28
  idPhysics *v102; // r27
  const idMat3 *v103; // r28
  const idVec3 *v104; // r3
  int v105; // [sp+8h] [-168h]
  int v106; // [sp+Ch] [-164h]
  int v107; // [sp+10h] [-160h]
  int v108; // [sp+14h] [-15Ch]
  int v109; // [sp+18h] [-158h]
  idEffectPhysicsBroadPhase *v110; // [sp+1Ch] [-154h]
  int v111; // [sp+20h] [-150h]
  int v112; // [sp+24h] [-14Ch]
  int v113; // [sp+28h] [-148h]
  int v114; // [sp+2Ch] [-144h]
  int v115; // [sp+30h] [-140h]
  int v116; // [sp+34h] [-13Ch]
  int v117; // [sp+38h] [-138h]
  int v118; // [sp+3Ch] [-134h]
  int v119; // [sp+40h] [-130h]
  int v120; // [sp+44h] [-12Ch]
  int v121; // [sp+48h] [-128h]
  int v122; // [sp+4Ch] [-124h]
  int v123; // [sp+50h] [-120h]
  float v124; // [sp+60h] [-110h] BYREF
  __int64 v125; // [sp+68h] [-108h] BYREF
  __int64 v126; // [sp+70h] [-100h] BYREF
  idPLogScope v127; // [sp+78h] [-F8h] BYREF
  idMat3 v128; // [sp+80h] [-F0h] BYREF
  float v129; // [sp+A4h] [-CCh]
  float v130; // [sp+A8h] [-C8h]
  float v131; // [sp+ACh] [-C4h]
  float v132; // [sp+B0h] [-C0h]

  RD_EventBegin(name: "idBreakable::Think");
  LODWORD(v2) = "idBreakable::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v127, pl: &pLog, gMask: v2, label: v3);
  if ( idEntity::UpdateDormant(this) )
    goto LABEL_54;
  if ( this->brokenFrame == idAccolade::Count(this: &clientGame->gameTimeManager) )
  {
    Physics = idEntity::GetPhysics(this);
    v5 = idEntity::GetPhysics(this);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v7 = Physics->GetAxis(this: Physics, a2: 0);
    v8 = v5->GetOrigin(this: v5, a2: 0);
    idEffectPhysicsBreakable::StartExplosions(this: &this->breakablePhysics, origin: v8, axis: v7, currentTime: GameMs);
  }
  if ( (this->thinkFlags & 2) != 0 )
  {
    presentable = (float *)this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = (float *)this->presentable;
    }
    v10 = idEntity::GetPhysics(this);
    v11 = (float *)v10->GetOrigin(this: v10, a2: 0);
    HIDWORD(v126) = presentable + 30;
    presentable[30] = *v11;
    presentable[31] = v11[1];
    presentable[32] = v11[2];
    v12 = idEntity::GetPhysics(this);
    v13 = (float *)v12->GetAxis(this: v12, a2: 0);
    presentable[33] = *v13;
    presentable[34] = v13[1];
    v14 = v13[2];
    LODWORD(v124) = v13 + 3;
    presentable[35] = v14;
    presentable[36] = v13[3];
    LODWORD(v124) = v13 + 6;
    v15 = v13[4];
    LODWORD(v124) = presentable + 39;
    presentable[37] = v15;
    presentable[38] = v13[5];
    presentable[39] = v13[6];
    presentable[40] = v13[7];
    presentable[41] = v13[8];
    if ( this->brokenStartTime == -1 )
    {
      if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) == 0 )
      {
        v38 = idEntity::GetPhysics(this);
        v39 = idEntity::GetPhysics(this);
        GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v41 = v38->GetAxis(this: v38, a2: 0);
        v42 = v39->GetOrigin(this: v39, a2: 0);
        idEffectPhysicsBreakable::UpdateModel(
          this: &this->breakablePhysics,
          origin: v42,
          axis: v41,
          gameMsPerFrame: GameMsPerFrame);
      }
      if ( idEntity::IsBound(this) )
        goto LABEL_17;
    }
    else
    {
      v16 = idEntity::GetPhysics(this);
      v17 = idEntity::GetPhysics(this);
      p_gameTimeManager = &clientGame->gameTimeManager;
      HIDWORD(v126) = &clientGame->gameTimeManager;
      v19 = idAccolade::Count(this: &clientGame->gameTimeManager);
      v20 = (const char *)idGameTimeManager::GetGameMsPerFrame(
                            this: &clientGame->gameTimeManager,
                            type: GAMETIME_SCALED);
      v21 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      RealMsPerFrame = idGameTimeManager::GetRealMsPerFrame(this: p_gameTimeManager, type: GAMETIME_SCALED);
      v23 = v16->GetAxis(this: v16, a2: 0);
      v24 = v17->GetOrigin(this: v17, a2: 0);
      idEffectPhysicsBreakable::UpdateSimulation(
        this: &this->breakablePhysics,
        origin: v24,
        axis: v23,
        currentTime: v21,
        gameMsPerFrame: v20,
        frameNum: v19,
        msPerFrame: RealMsPerFrame,
        dampening: 0.0);
      idCombatStage_useRelaxedChatterVO = (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this);
      if ( idCombatStage_useRelaxedChatterVO == 0 )
      {
        v31 = idEntity::GetPhysics(this);
        v32 = idEntity::GetPhysics(this);
        v33 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v34 = v31->GetAxis(this: v31, a2: 0);
        v35 = v32->GetOrigin(this: v32, a2: 0);
        idEffectPhysicsBreakable::UpdateModel(
          this: &this->breakablePhysics,
          origin: v35,
          axis: v34,
          gameMsPerFrame: v33);
      }
      idClientGame::AddSimulatingEffectPhysics(
        this: clientGame,
        broadPhase: &this->breakablePhysics.broadPhase,
        a3: v30,
        a4: v29,
        a5: idCombatStage_useRelaxedChatterVO,
        a6: v27,
        a7: v26,
        a8: v25,
        a9: v105,
        a10: v106,
        a11: v107,
        a12: v108,
        a13: v109,
        a14: v110);
      maxSimulationTime = this->maxSimulationTime;
      brokenStartTime = this->brokenStartTime;
      LODWORD(v126) = (int)(float)(this->fadeDelay * 1000.0);
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < (int)v126 + maxSimulationTime + brokenStartTime )
        goto LABEL_17;
      if ( this->fadeBroken )
        idEntity::BecomeActive(this, flags: 1);
    }
    idEntity::BecomeInactive(this, flags: 2);
LABEL_17:
    v43 = idEntity::GetPhysics(this);
    v44 = v43->GetAbsBounds(this: v43, a2: -1);
    idEntity::UpdatePVSAreas(this, bounds: v44);
  }
  if ( (this->thinkFlags & 1) != 0 )
  {
    v45 = this->brokenStartTime;
    if ( v45 == -1 )
    {
      effectsModel = clientGame->gameLibEffects.effectsModel;
      if ( effectsModel != nullptr )
      {
        LODWORD(v126) = (int)(float)((float)(this->currentHealth / this->health) * (float)100.0);
        v55 = v126;
        v56 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v57 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v58 = 0;
        v59 = idAccolade::Count(this: &clientGame->gameTimeManager);
        for ( i = 0; i < this->breakState.num; ++v58 )
        {
          v62 = &this->breakState.list[v58];
          if ( v55 <= v62->healthPercent )
          {
            smokeSystemRate = v62->smokeSystemRate;
            if ( smokeSystemRate <= 1
              || (HIDWORD(v60) = smokeSystemRate & ~(__ROL4__(v59, 1) - 1),
                  __twllei(smokeSystemRate, 0),
                  __twlgei(HIDWORD(v60), 0xFFFFFFFF),
                  v59 % smokeSystemRate == 0) )
            {
              if ( v62->startTime == 0 )
                v62->startTime = v57;
              v64 = 1664525 * clientGame->random.seed;
              clientGame->random.seed = v64 + 1013904223;
              LODWORD(v60) = ((v64 + 1013904223) >> 10) & 0x7FFF;
              v125 = v60;
              v65 = (float)((float)v60 * (float)0.000030518509);
              v66 = idEntity::GetPhysics(this);
              v67 = (int)v66->GetAxis(this: v66, a2: 0);
              v68 = &v128.mat[1];
              v69 = (float *)(v67 - 4);
              for ( j = 9; j != 0; --j )
              {
                ++v69;
                v68 = (idVec3 *)((char *)v68 + 4);
                v68->x = *v69;
              }
              v71 = idEntity::GetPhysics(this);
              v72 = &this->breakState.list[v58];
              GetOrigin = v71->GetOrigin;
              y = v72->offset.y;
              HIDWORD(v126) = &v72->offset;
              v75 = (float)((float)(v128.mat[1].y * v72->offset.x)
                          + (float)((float)(v130 * v72->offset.z) + (float)(v128.mat[2].y * (float)y)));
              v76 = (float)((float)(v129 * (float)y)
                          + (float)((float)(v128.mat[2].x * v72->offset.x) + (float)(v132 * v72->offset.z)));
              v77 = (float)((float)(v128.mat[2].z * (float)y)
                          + (float)((float)(v128.mat[1].z * v72->offset.x) + (float)(v131 * v72->offset.z)));
              v78 = (float *)GetOrigin(this: v71, a2: 0);
              HIDWORD(v126) = -1;
              list = this->breakState.list;
              v80 = *v78;
              v81 = (float)(v78[1] + (float)v77);
              v128.mat[0].z = v78[2] + (float)v76;
              v128.mat[0].x = (float)v75 + (float)v80;
              v128.mat[0].y = v81;
              idRenderModelEffects::AddParticles(
                this: effectsModel,
                particle: list[v58].particle,
                systemStartTime: v57,
                gameMsPerFrame: v56,
                diversity: v65,
                origin: (const idVec3 *)list,
                axis: &v128,
                velocity: (const idVec3 *)&v128.mat[1].y,
                color: &vec3_origin.x,
                a10: v105,
                a11: v106,
                a12: v107,
                a13: v108,
                a14: v109,
                a15: (int)v110,
                a16: v111,
                a17: v112,
                a18: v113,
                a19: v114,
                a20: v115,
                a21: v116,
                a22: v117,
                a23: v118,
                a24: v119,
                a25: v120,
                a26: v121,
                a27: v122,
                a28: v123,
                a29: (unsigned int *)&v126);
            }
          }
          ++i;
        }
      }
    }
    else
    {
      v46 = common->__vftable;
      v47 = (int)(float)(this->fadeDelay * 1000.0) + v45;
      LODWORD(v126) = (int)(float)((float)(this->fadeTime + this->fadeDelay) * 1000.0);
      v48 = v126 + v45;
      if ( v46->IsMultiplayer(this: common) )
      {
        v49 = this->presentable;
        if ( v49 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v49 = this->presentable;
        }
        v50 = (int)v49->GetBreakableInterface(this: v49);
        if ( this->fadeBroken )
        {
          *(_DWORD *)(v50 + 1544) = (int)(float)(this->fadeTime * 1000.0);
          *(_DWORD *)(v50 + 1548) = (int)(float)(this->fadeDelay * 1000.0);
          if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= v48 )
            this->Hide_2(this);
        }
        else
        {
          *(_DWORD *)(v50 + 1544) = 0;
          *(_DWORD *)(v50 + 1548) = 0;
        }
      }
      if ( this->fadeBroken
        && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= v47 )
      {
        fadeEndTime = this->fade.fadeEndTime;
        if ( fadeEndTime == -1 )
        {
          this->Hide_2(this);
        }
        else if ( fadeEndTime > 0 )
        {
          v53 = this->presentable;
          if ( v53 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v53 = this->presentable;
          }
          idFadeHelper::Update(this: &this->fade, presentable: v53);
        }
        else
        {
          v52 = (float)(this->fadeTime * 1000.0);
          v124 = 0.0;
          *(float *)&v125 = 1.0;
          LODWORD(v126) = (int)v52;
          HIDWORD(v126) = (int)v52;
          idFadeHelper::Fade(
            this: &this->fade,
            from: (float *)&v125,
            to: &v124,
            time: (const int *)&v126,
            _noStippleFade: false);
        }
      }
    }
  }
  v82 = idEntity::GetPhysics(this);
  LODWORD(v83) = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  HIDWORD(v83) = v82->__vftable;
  v126 = v83;
  v84 = (float)((float)v83 * (float)0.001);
  v85 = (float *)(*(int (__fastcall **)(idPhysics *, _DWORD))(HIDWORD(v83) + 64))(a1: v82, a2: 0);
  x = this->oldOrigin.x;
  z = this->oldOrigin.z;
  v88 = this->oldOrigin.y;
  HIDWORD(v126) = &this->velocity;
  v89 = (float)(v85[2] - (float)z);
  v90 = (float)(v85[1] - (float)v88);
  this->velocity.x = (float)((float)1.0 / (float)v84) * (float)(*v85 - (float)x);
  this->velocity.z = (float)((float)1.0 / (float)v84) * (float)v89;
  this->velocity.y = (float)((float)1.0 / (float)v84) * (float)v90;
  v91 = idEntity::GetPhysics(this);
  v92 = (float *)v91->GetOrigin(this: v91, a2: 0);
  this->oldOrigin.x = *v92;
  this->oldOrigin.y = v92[1];
  this->oldOrigin.z = v92[2];
  if ( g_showBreakableCollision.valueInteger != 0 )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    if ( Player != nullptr )
    {
      v94 = idEntity::GetPhysics(this);
      v95 = idEntity::GetPhysics(this: Player);
      v96 = (float *)v94->GetOrigin(this: v94, a2: 0);
      v97 = (float *)v95->GetOrigin(this: v95, a2: 0);
      v98 = (float)(v97[1] - v96[1]);
      v99 = (float)(v97[2] - v96[2]);
      if ( (float)((float)((float)v99 * (float)v99)
                 + (float)((float)((float)(*v97 - *v96) * (float)(*v97 - *v96)) + (float)((float)v98 * (float)v98))) < 1000000.0 )
      {
        if ( g_showBreakableCollision.valueInteger >= 0 )
          v100 = -1;
        else
          v100 = abs32(g_showBreakableCollision.valueInteger) - 1;
        v101 = idEntity::GetPhysics(this);
        v102 = idEntity::GetPhysics(this);
        v103 = v101->GetAxis(this: v101, a2: 0);
        v104 = v102->GetOrigin(this: v102, a2: 0);
        idEffectPhysicsBreakable::DrawCollisionModels(
          this: &this->breakablePhysics,
          single: v100,
          offset: v104,
          axis: v103);
      }
    }
  }
LABEL_54:
  idPLogScope::~idPLogScope(this: &v127);
  RD_EventEnd();
}


// ========================================================================
// __unwind$489810_0
// EA  : 0x82C0EAE8
// RVA : 0x00C0EAE8
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void _unwind_489810_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 368 + 180));
}


// ========================================================================
// __unwind$489811_0
// EA  : 0x82C0EB10
// RVA : 0x00C0EB10
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void _unwind_489811_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 368 + 120));
}


// ========================================================================
// `dynamic initializer for 'g_showBreakableCollision''
// EA  : 0x83375080
// RVA : 0x01375080
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showBreakableCollision__()
{
  idCVar::idCVar(
    this: &g_showBreakableCollision,
    name: "g_showBreakableCollision",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showBreakableCollision__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableImpulse''
// EA  : 0x833750D8
// RVA : 0x013750D8
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableImpulse__()
{
  idCVar::idCVar(
    this: &g_breakableImpulse,
    name: "g_breakableImpulse",
    value: "1000000",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableImpulse__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableVehicleImpulse''
// EA  : 0x83375130
// RVA : 0x01375130
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableVehicleImpulse__()
{
  idCVar::idCVar(
    this: &g_breakableVehicleImpulse,
    name: "g_breakableVehicleImpulse",
    value: "500000",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableVehicleImpulse__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableOffset''
// EA  : 0x83375188
// RVA : 0x01375188
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableOffset__()
{
  idCVar::idCVar(
    this: &g_breakableOffset,
    name: "g_breakableOffset",
    value: "-192",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableOffset__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableVehicleOffset''
// EA  : 0x833751E0
// RVA : 0x013751E0
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableVehicleOffset__()
{
  idCVar::idCVar(
    this: &g_breakableVehicleOffset,
    name: "g_breakableVehicleOffset",
    value: "192",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableVehicleOffset__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableFalloff''
// EA  : 0x83375238
// RVA : 0x01375238
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableFalloff__()
{
  idCVar::idCVar(
    this: &g_breakableFalloff,
    name: "g_breakableFalloff",
    value: "0.2",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableFalloff__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableAngular''
// EA  : 0x83375290
// RVA : 0x01375290
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableAngular__()
{
  idCVar::idCVar(
    this: &g_breakableAngular,
    name: "g_breakableAngular",
    value: "0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableAngular__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableDelay''
// EA  : 0x833752E8
// RVA : 0x013752E8
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableDelay__()
{
  idCVar::idCVar(
    this: &g_breakableDelay,
    name: "g_breakableDelay",
    value: "0.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableDelay__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableDuration''
// EA  : 0x83375340
// RVA : 0x01375340
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableDuration__()
{
  idCVar::idCVar(
    this: &g_breakableDuration,
    name: "g_breakableDuration",
    value: "5",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableDuration__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableRadius''
// EA  : 0x83375398
// RVA : 0x01375398
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableRadius__()
{
  idCVar::idCVar(
    this: &g_breakableRadius,
    name: "g_breakableRadius",
    value: "450",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableRadius__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableExplosion''
// EA  : 0x833753F0
// RVA : 0x013753F0
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableExplosion__()
{
  idCVar::idCVar(
    this: &g_breakableExplosion,
    name: "g_breakableExplosion",
    value: "0",
    flags: 2,
    description: "set to zero to disable code based explosions on the sign",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableExplosion__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableAddVehicleExplosion''
// EA  : 0x83375448
// RVA : 0x01375448
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableAddVehicleExplosion__()
{
  idCVar::idCVar(
    this: &g_breakableAddVehicleExplosion,
    name: "g_breakableAddVehicleExplosion",
    value: "0",
    flags: 1,
    description: "turn off to disable the vehicle adding an explosion based on velocity and direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableAddVehicleExplosion__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableCharDefaultImpulse''
// EA  : 0x833754A0
// RVA : 0x013754A0
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableCharDefaultImpulse__()
{
  idCVar::idCVar(
    this: &g_breakableCharDefaultImpulse,
    name: "g_breakableCharDefaultImpulse",
    value: "1000",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableCharDefaultImpulse__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableCharAngular''
// EA  : 0x833754F8
// RVA : 0x013754F8
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableCharAngular__()
{
  idCVar::idCVar(
    this: &g_breakableCharAngular,
    name: "g_breakableCharAngular",
    value: "5",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableCharAngular__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableCharOffset''
// EA  : 0x83375550
// RVA : 0x01375550
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableCharOffset__()
{
  idCVar::idCVar(
    this: &g_breakableCharOffset,
    name: "g_breakableCharOffset",
    value: "30",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableCharOffset__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableCharRadius''
// EA  : 0x833755A8
// RVA : 0x013755A8
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableCharRadius__()
{
  idCVar::idCVar(
    this: &g_breakableCharRadius,
    name: "g_breakableCharRadius",
    value: "512",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableCharRadius__);
}


// ========================================================================
// `dynamic initializer for 'g_breakableCharImpulseScale''
// EA  : 0x83375600
// RVA : 0x01375600
// PDB : w:\tech5\tungsten\game\entities\breakable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_breakableCharImpulseScale__()
{
  idCVar::idCVar(
    this: &g_breakableCharImpulseScale,
    name: "g_breakableCharImpulseScale",
    value: "3",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_breakableCharImpulseScale__);
}

