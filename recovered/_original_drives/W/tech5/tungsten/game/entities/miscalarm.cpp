
// ========================================================================
// ?AllocPresentable@idAlarm@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C7B398
// RVA : 0x00C7B398
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

idPresentable *__fastcall idAlarm::AllocPresentable(idAlarm *this, idTreeAnimator *renderModel_)
{
  idPresentable *v4; // r3

  v4 = (idPresentable *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x4B0u,
                          tag: TAG_PRESENTABLE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    return idPresentable::idPresentable(
             this: v4,
             e: this,
             renderModel_,
             entityNumber_: this->entityNumber,
             fxDecl_: this->fxDecl);
  else
    return nullptr;
}


// ========================================================================
// __unwind$488554
// EA  : 0x82C7B408
// RVA : 0x00C7B408
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void _unwind_488554()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?SetupBreakable@idAlarm@@AAAXXZ
// EA  : 0x82C7B440
// RVA : 0x00C7B440
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void __fastcall idAlarm::SetupBreakable(idAlarm *this)
{
  idRenderModel *v2; // r3
  idRenderModel *RenderModelFromPresentable; // r3
  idRenderModelDiscreteAnimation *v4; // r3
  idRenderModelDiscreteAnimation *v5; // r29
  idRenderModel *v6; // r3
  idRenderModel *v7; // r3
  idEffectPhysicsBreakable *v8; // r3
  idEffectPhysicsBreakable *v9; // r3
  idRenderModel *v10; // r3
  idPresentableBreakable *v11; // r3
  idPresentableBreakable *v12; // r3
  idRenderModel *brokenModel; // r3
  int v14; // r10
  int v15; // r9
  int v16; // r8
  int v17; // r7
  idPhysics *Physics; // r3
  int v19; // r3
  int v20; // r10
  int v21; // r8
  int v22; // r7
  int v23; // r6
  int v24; // r5
  int v25; // r10
  int v26; // r9
  int v27; // r8
  int v28; // r7
  idSoundEmitter *SoundEmitter; // r3
  const idDeclImpactSound *impactSoundTable; // r6
  double v31; // fp13
  idPhysics *v32; // r28
  idPhysics *v33; // r27
  int GameMsPerFrame; // r26
  const idMat3 *v35; // r28
  const idVec3 *v36; // r3
  int v37; // [sp+8h] [-B8h]
  int v38; // [sp+8h] [-B8h]
  int v39; // [sp+Ch] [-B4h]
  int v40; // [sp+Ch] [-B4h]
  int v41; // [sp+10h] [-B0h]
  int v42; // [sp+10h] [-B0h]
  int v43; // [sp+14h] [-ACh]
  int v44; // [sp+14h] [-ACh]
  int v45; // [sp+18h] [-A8h]
  int v46; // [sp+18h] [-A8h]
  idPresentable *v47; // [sp+1Ch] [-A4h]
  idPresentable *v48; // [sp+1Ch] [-A4h]
  idEffectPhysicsBreakable::breakablePieceSound_t v49; // [sp+60h] [-60h] BYREF

  if ( this->breakModel.len != 0 )
  {
    v2 = clientGame->renderWorld->AllocRenderModel(
           this: clientGame->renderWorld,
           a2: this->breakModel.data,
           a3: 1,
           a4: -1);
    this->brokenModel = v2;
    if ( v2 != nullptr )
    {
      RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
      if ( RenderModelFromPresentable != nullptr )
      {
        *((_BYTE *)&this->brokenModel->g + 107) = (16 * ((*((_BYTE *)&RenderModelFromPresentable->g + 107) & 0x10) != 0))
                                                & 0x10
                                                | *((_BYTE *)&this->brokenModel->g + 107) & 0xEF;
        *((_BYTE *)&this->brokenModel->g + 105) = (*((_BYTE *)&RenderModelFromPresentable->g + 105) >> 7 << 7)
                                                | *((_BYTE *)&this->brokenModel->g + 105) & 0x7F;
        *((_BYTE *)&this->brokenModel->g + 105) = (32 * ((*((_BYTE *)&RenderModelFromPresentable->g + 105) & 0x20) != 0))
                                                & 0x20
                                                | *((_BYTE *)&this->brokenModel->g + 105) & 0xDF;
        *((_BYTE *)&this->brokenModel->g + 104) = (((*((_BYTE *)&RenderModelFromPresentable->g + 104) & 0x40) != 0) << 6)
                                                & 0x40
                                                | *((_BYTE *)&this->brokenModel->g + 104) & 0xBF;
        *((_BYTE *)&this->brokenModel->g + 105) = (16 * ((*((_BYTE *)&RenderModelFromPresentable->g + 105) & 0x10) != 0))
                                                & 0x10
                                                | *((_BYTE *)&this->brokenModel->g + 105) & 0xEF;
        *((_BYTE *)&this->brokenModel->g + 104) = (*((_BYTE *)&RenderModelFromPresentable->g + 104) >> 7 << 7)
                                                | *((_BYTE *)&this->brokenModel->g + 104) & 0x7F;
        *((_BYTE *)&this->brokenModel->g + 106) = *((_BYTE *)&RenderModelFromPresentable->g + 106) & 1
                                                | *((_BYTE *)&this->brokenModel->g + 106) & 0xFE;
        this->brokenModel->g.dimShadowClipZ = RenderModelFromPresentable->g.dimShadowClipZ;
        this->brokenModel->g.maxVisibleRange = RenderModelFromPresentable->g.maxVisibleRange;
        this->brokenModel->g.fadeVisibilityOver = RenderModelFromPresentable->g.fadeVisibilityOver;
      }
      v4 = (idRenderModelDiscreteAnimation *)_RTDynamicCast(
                                               inptr: this->brokenModel,
                                               VfDelta: 0,
                                               SrcType: &idRenderModel `RTTI Type Descriptor',
                                               TargetType: &idRenderModelDiscreteAnimation `RTTI Type Descriptor',
                                               isReference: 0);
      v5 = v4;
      if ( v4 != nullptr )
      {
        if ( v4->declBreakable != nullptr )
        {
          v8 = (idEffectPhysicsBreakable *)idMem::AllocWithLocation(
                                             this: &mem,
                                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                             size: 0x124u,
                                             tag: TAG_GAME,
                                             zeroBuffer: false,
                                             align: ALIGN_16,
                                             heap: HEAP_DEFAULTHEAP);
          if ( v8 != nullptr )
            v9 = idEffectPhysicsBreakable::idEffectPhysicsBreakable(this: v8);
          else
            v9 = nullptr;
          this->breakablePhysics = v9;
          if ( v9 != nullptr )
          {
            v11 = (idPresentableBreakable *)idMem::AllocWithLocation(
                                              this: &mem,
                                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                              size: 0x628u,
                                              tag: TAG_PRESENTABLE,
                                              zeroBuffer: false,
                                              align: ALIGN_16,
                                              heap: HEAP_DEFAULTHEAP);
            if ( v11 != nullptr )
              v12 = idPresentableBreakable::idPresentableBreakable(
                      this: v11,
                      ent: this,
                      renderModel_: (idTreeAnimator *)this->brokenModel,
                      entityNumber_: 0x1FFF,
                      fxDecl_: nullptr);
            else
              v12 = nullptr;
            this->breakablePresentable = v12;
            if ( v12 != nullptr )
            {
              idPresentableBreakable::SetInitProperties(
                this: v12,
                impactTable_: this->impactSoundTable,
                pieceMinBounceVelocity_: this->pieceMinBounceVelocity);
              idPresentable::SetClipModelInfo(
                this: this->breakablePresentable,
                clipModelInfo_: &this->clipModelInfo,
                clipModelSpawnPos_: &this->spawnPosition,
                clipModelSpawnAxis_: &this->spawnOrientation,
                a5: v17,
                a6: v16,
                a7: v15,
                a8: v14,
                a9: v37,
                a10: v39,
                a11: v41,
                a12: v43,
                a13: v45,
                a14: v47);
              Physics = idEntity::GetPhysics(this);
              v19 = (int)Physics->GetClipModel(this: Physics, a2: 0);
              idPresentable::SetClipModelContents(
                this: this->breakablePresentable,
                newContents: *(_DWORD *)(v19 + 128),
                a3: v24,
                a4: v23,
                a5: v22,
                a6: v21,
                a7: v19,
                a8: v20);
              idClientGame::AddPresentable(
                this: clientGame,
                presentable: this->breakablePresentable,
                index: -1,
                skipReplication: true,
                a5: v28,
                a6: v27,
                a7: v26,
                a8: v25,
                a9: v38,
                a10: v40,
                a11: v42,
                a12: v44,
                a13: v46,
                a14: v48);
              memset(&v49, 0, 12);
              v49.nextSoundTime = 0;
              v49.minBounceVelSqr = 0.0;
              v49.soundWorld = clientGame->soundWorld;
              SoundEmitter = idEntity::GetSoundEmitter(this, alloc: true);
              impactSoundTable = this->impactSoundTable;
              v31 = (float)(this->pieceMinBounceVelocity * this->pieceMinBounceVelocity);
              v49.emitter = SoundEmitter;
              v49.channel = SND_CHANNEL_FX;
              v49.minBounceVelSqr = v31;
              v49.impactTable = impactSoundTable;
              idEffectPhysicsBreakable::Init(
                this: this->breakablePhysics,
                clip: &clientGame->clip,
                tmc: &clientGame->traceModelCache,
                _gameLibEffects: &clientGame->gameLibEffects,
                model_: v5,
                entNum: this->entityNumber,
                _soundInfo: &v49);
              v32 = idEntity::GetPhysics(this);
              v33 = idEntity::GetPhysics(this);
              GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                                 this: &clientGame->gameTimeManager,
                                 type: GAMETIME_SCALED);
              v35 = v32->GetAxis(this: v32, a2: 0);
              v36 = v33->GetOrigin(this: v33, a2: 0);
              idEffectPhysicsBreakable::UpdateModel(
                this: this->breakablePhysics,
                origin: v36,
                axis: v35,
                gameMsPerFrame: GameMsPerFrame);
              if ( !v5->deferredPositionInitialized || !v5->useDeferredPosition )
                v5->g.origin = vec3_origin;
              v5->deferredOrigin = vec3_origin;
              idRenderModel::SetAxis(this: v5, a: &mat3_identity);
              if ( !v5->unlinked )
              {
                idRenderModel::CommitThisFrame(this: v5);
                v5->unlinked = true;
              }
            }
            else
            {
              idLib::Warning(fmt: "%s could not allocate breakable presentable", this->name.data);
              brokenModel = this->brokenModel;
              brokenModel->unlinked = true;
              brokenModel->deleteOnSync = true;
              idRenderModel::CommitThisFrame(this: brokenModel);
            }
          }
          else
          {
            idLib::Warning(fmt: "%s could not allocate breakable physics", this->name.data);
            v10 = this->brokenModel;
            v10->unlinked = true;
            v10->deleteOnSync = true;
            idRenderModel::CommitThisFrame(this: v10);
          }
        }
        else
        {
          idLib::Warning(fmt: "%s does not specify a breakable decl", this->name.data);
          v7 = this->brokenModel;
          v7->unlinked = true;
          v7->deleteOnSync = true;
          idRenderModel::CommitThisFrame(this: v7);
        }
      }
      else
      {
        idLib::Warning(fmt: "%s does not use a breakable model '%s'", this->name.data, this->breakModel.data);
        v6 = this->brokenModel;
        v6->unlinked = true;
        v6->deleteOnSync = true;
        idRenderModel::CommitThisFrame(this: v6);
      }
    }
    else
    {
      idLib::Warning(fmt: "%s couldn't allocate render model '%s'", this->name.data, this->breakModel.data);
    }
  }
}


// ========================================================================
// __unwind$488589
// EA  : 0x82C7B8F0
// RVA : 0x00C7B8F0
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void _unwind_488589()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 80), tag: TAG_GAME);
}


// ========================================================================
// __unwind$488590
// EA  : 0x82C7B91C
// RVA : 0x00C7B91C
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void _unwind_488590()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?Think@idAlarm@@UAAXXZ
// EA  : 0x82C7B948
// RVA : 0x00C7B948
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void __fastcall idAlarm::Think(idAlarm *this)
{
  idPhysics *Physics; // r3
  float *v3; // r3
  idPresentableBreakable *breakablePresentable; // r11
  idPhysics *v5; // r3
  float *v6; // r3
  float *p_axis; // r11
  idClientGame *v8; // r10
  idPhysics *v9; // r28
  idPhysics *v10; // r27
  int GameMs; // r26
  const idMat3 *v12; // r28
  const idVec3 *v13; // r3
  idPhysics *v14; // r28
  idPhysics *v15; // r27
  idGameTimeManager *p_gameTimeManager; // r26
  int v17; // r25
  const char *GameMsPerFrame; // r24
  int v19; // r23
  double RealMsPerFrame; // fp31
  const idMat3 *v21; // r28
  const idVec3 *v22; // r3
  int idCombatStage_useRelaxedChatterVO; // r10
  int v24; // r9
  int v25; // r8
  int v26; // r7
  int v27; // r6
  int v28; // r5
  idPhysics *v29; // r28
  idPhysics *v30; // r27
  int v31; // r30
  const idMat3 *v32; // r28
  const idVec3 *v33; // r3
  idPhysics *v34; // r3
  idBounds *v35; // r3
  int v36; // [sp+8h] [-A8h]
  int v37; // [sp+Ch] [-A4h]
  int v38; // [sp+10h] [-A0h]
  int v39; // [sp+14h] [-9Ch]
  int v40; // [sp+18h] [-98h]
  idEffectPhysicsBroadPhase *v41; // [sp+1Ch] [-94h]

  if ( (unsigned __int8)idEntity::UpdateDormant(this) == 0 )
  {
    idDynamicEntity::Think(this);
    if ( (this->thinkFlags & 2) != 0 && this->breakablePhysics != nullptr )
    {
      Physics = idEntity::GetPhysics(this);
      v3 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      breakablePresentable = this->breakablePresentable;
      breakablePresentable->origin.x = *v3;
      breakablePresentable->origin.y = v3[1];
      breakablePresentable->origin.z = v3[2];
      v5 = idEntity::GetPhysics(this);
      v6 = (float *)v5->GetAxis(this: v5, a2: 0);
      p_axis = (float *)&this->breakablePresentable->axis;
      v8 = clientGame;
      *p_axis = *v6;
      p_axis[1] = v6[1];
      p_axis[2] = v6[2];
      p_axis[3] = v6[3];
      p_axis[4] = v6[4];
      p_axis[5] = v6[5];
      p_axis[6] = v6[6];
      p_axis[7] = v6[7];
      p_axis[8] = v6[8];
      if ( this->brokenFrame == idAccolade::Count(this: &v8->gameTimeManager) )
      {
        v9 = idEntity::GetPhysics(this);
        v10 = idEntity::GetPhysics(this);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v12 = v9->GetAxis(this: v9, a2: 0);
        v13 = v10->GetOrigin(this: v10, a2: 0);
        idEffectPhysicsBreakable::StartExplosions(
          this: this->breakablePhysics,
          origin: v13,
          axis: v12,
          currentTime: GameMs);
      }
      if ( this->brokenTime != -1 )
      {
        v14 = idEntity::GetPhysics(this);
        v15 = idEntity::GetPhysics(this);
        p_gameTimeManager = &clientGame->gameTimeManager;
        v17 = idAccolade::Count(this: &clientGame->gameTimeManager);
        GameMsPerFrame = (const char *)idGameTimeManager::GetGameMsPerFrame(
                                         this: &clientGame->gameTimeManager,
                                         type: GAMETIME_SCALED);
        v19 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        RealMsPerFrame = idGameTimeManager::GetRealMsPerFrame(this: p_gameTimeManager, type: GAMETIME_SCALED);
        v21 = v14->GetAxis(this: v14, a2: 0);
        v22 = v15->GetOrigin(this: v15, a2: 0);
        idEffectPhysicsBreakable::UpdateSimulation(
          this: this->breakablePhysics,
          origin: v22,
          axis: v21,
          currentTime: v19,
          gameMsPerFrame: GameMsPerFrame,
          frameNum: v17,
          msPerFrame: RealMsPerFrame,
          dampening: 0.0);
        idCombatStage_useRelaxedChatterVO = (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this);
        if ( idCombatStage_useRelaxedChatterVO == 0 )
        {
          v29 = idEntity::GetPhysics(this);
          v30 = idEntity::GetPhysics(this);
          v31 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v32 = v29->GetAxis(this: v29, a2: 0);
          v33 = v30->GetOrigin(this: v30, a2: 0);
          idEffectPhysicsBreakable::UpdateModel(
            this: this->breakablePhysics,
            origin: v33,
            axis: v32,
            gameMsPerFrame: v31);
        }
        idClientGame::AddSimulatingEffectPhysics(
          this: clientGame,
          broadPhase: &this->breakablePhysics->broadPhase,
          a3: v28,
          a4: v27,
          a5: v26,
          a6: v25,
          a7: v24,
          a8: idCombatStage_useRelaxedChatterVO,
          a9: v36,
          a10: v37,
          a11: v38,
          a12: v39,
          a13: v40,
          a14: v41);
      }
    }
    v34 = idEntity::GetPhysics(this);
    v35 = (idBounds *)v34->GetAbsBounds(this: v34, a2: -1);
    idEntity::UpdatePVSAreas(this, bounds: v35);
  }
}


// ========================================================================
// ?StartFX@idAlarm@@IAAXW4fxCondition_t@@@Z
// EA  : 0x82C7BC70
// RVA : 0x00C7BC70
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void __fastcall idAlarm::StartFX(idAnimatedEntity *this, fxCondition_t condition)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  presentable->StartFX(this: presentable, a2: condition, a3: FX_EXTRA_COND_NONE);
}


// ========================================================================
// ?ToggleAlarm@idAlarm@@AAAX_N@Z
// EA  : 0x82C7BCD8
// RVA : 0x00C7BCD8
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void __fastcall idAlarm::ToggleAlarm(idAlarm *this, bool enable)
{
  const idSoundShader *alarmSound; // r5
  idColor *p_colorActive; // r4
  idPresentable *presentable; // r11

  if ( this->alarmActive == enable )
    return;
  if ( enable )
  {
    if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) != 0 )
      this->Show(this);
    if ( this->brokenTime != -1 )
      goto LABEL_13;
    idEventReceiver::PostEventMS(this, ev: &EV_ActivateColorModulate, time: 0);
    idAlarm::StartFX((idAnimatedEntity *)this, condition: this->fxConditionActivate);
    alarmSound = this->alarmSound;
    if ( alarmSound != nullptr )
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_VOICE,
        shader: alarmSound,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    p_colorActive = &this->colorActive;
  }
  else
  {
    idEventReceiver::PostEventMS(this, ev: &EV_DeactivateColorModulate, time: 0);
    idAnimatedEntity::StopFX((idAnimatedEntity *)this, condition: this->fxConditionActivate);
    if ( this->alarmSound != nullptr )
      idEntity::StopSound(this, channel: SND_CHANNEL_VOICE, peerMask: 0);
    p_colorActive = &this->colorInactive;
  }
  this->SetColor_2(this, a2: p_colorActive);
LABEL_13:
  presentable = this->presentable;
  this->alarmActive = enable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  presentable->Present(this: presentable);
}


// ========================================================================
// ?OnActivate@idAlarm@@UAAXPAVidEntity@@@Z
// EA  : 0x82C7BE20
// RVA : 0x00C7BE20
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void __fastcall idAlarm::OnActivate(idAlarm *this, idEntity *activator)
{
  idAlarm::ToggleAlarm(this, enable: true);
}


// ========================================================================
// ?OnMakeActivatable@idAlarm@@UAAX_N@Z
// EA  : 0x82C7BE28
// RVA : 0x00C7BE28
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void __fastcall idAlarm::OnMakeActivatable(idAlarm *this, const bool activatable)
{
  if ( !activatable )
    idAlarm::ToggleAlarm(this, enable: false);
}


// ========================================================================
// ?GetSoundTransform@idAlarm@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C7BE40
// RVA : 0x00C7BE40
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void __fastcall idAlarm::GetSoundTransform(idAlarm *this, idVec3 *soundOrigin, idMat3 *soundAxis)
{
  idMat3 v5; // [sp+50h] [-40h] BYREF

  idEntity::GetSoundTransform(this, soundOrigin, soundAxis);
  *soundAxis = *idMat3::operator*(this: &v5, result: &this->soundTransform, a: soundAxis);
  idMat3::OrthoNormalizeSelf(this: soundAxis);
}


// ========================================================================
// ??1idAlarm@@UAA@XZ
// EA  : 0x82C7BEE0
// RVA : 0x00C7BEE0
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void __fastcall idAlarm::~idAlarm(idAlarm *this)
{
  idPresentableBreakable *breakablePresentable; // r3
  idRenderModel *brokenModel; // r3
  idEffectPhysicsBreakable *breakablePhysics; // r29

  this->__vftable = (idAlarm_vtbl *)&idAlarm::`vftable';
  breakablePresentable = this->breakablePresentable;
  if ( breakablePresentable != nullptr )
  {
    idPresentable::Delete(this: breakablePresentable);
    this->breakablePresentable = nullptr;
  }
  brokenModel = this->brokenModel;
  if ( brokenModel != nullptr )
  {
    brokenModel->unlinked = true;
    brokenModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: brokenModel);
    this->brokenModel = nullptr;
  }
  breakablePhysics = this->breakablePhysics;
  if ( breakablePhysics != nullptr )
  {
    idEffectPhysicsBreakable::~idEffectPhysicsBreakable(this: this->breakablePhysics);
    idMem::Free(this: &mem, ptr: breakablePhysics, align: ALIGN_16);
    this->breakablePhysics = nullptr;
  }
  this->alarmHealth.__vftable = (idSimpleHealth_vtbl *)&idBaseHealth::`vftable';
  idStr::FreeData(this: &this->breakModel);
  this->__vftable = (idAlarm_vtbl *)&idDynamicEntity::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$489235_0
// EA  : 0x82C7BFA0
// RVA : 0x00C7BFA0
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void _unwind_489235_0()
{
  int v0; // r12

  idDynamicEntity::~idDynamicEntity(this: *(idDynamicEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489236_0
// EA  : 0x82C7BFC8
// RVA : 0x00C7BFC8
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void _unwind_489236_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 880));
}


// ========================================================================
// __unwind$489237_0
// EA  : 0x82C7BFF4
// RVA : 0x00C7BFF4
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void _unwind_489237_0()
{
  int v0; // r12

  idSimpleHealth::~idSimpleHealth(this: (idAIHealth *)(*(_DWORD *)(v0 - 128 + 148) + 956));
}


// ========================================================================
// ?Spawn@idAlarm@@QAAXXZ
// EA  : 0x82C7C028
// RVA : 0x00C7C028
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void __fastcall idAlarm::Spawn(idAlarm *this)
{
  this->SetColor_2(this, a2: &this->colorInactive);
  idAlarm::SetupBreakable(this);
}


// ========================================================================
// ?Break@idAlarm@@AAAXXZ
// EA  : 0x82C7C070
// RVA : 0x00C7C070
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

void __fastcall idAlarm::Break(idAlarm *this)
{
  idPresentable *presentable; // r3
  idPhysics *Physics; // r3
  float *v4; // r3
  idPresentableBreakable *breakablePresentable; // r11
  idPhysics *v6; // r3
  float *v7; // r3
  float *p_axis; // r11
  idPresentable *v9; // r11
  idPhysics *v10; // r3
  idClipModel *v11; // r3
  const idSoundShader *alarmBreakSound; // r5

  if ( this->brokenTime == -1 )
  {
    if ( this->breakablePresentable != nullptr )
    {
      presentable = this->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      presentable->Hide(this: presentable, a2: false);
      this->breakablePresentable->Show(this: this->breakablePresentable);
      Physics = idEntity::GetPhysics(this);
      v4 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      breakablePresentable = this->breakablePresentable;
      breakablePresentable->origin.x = *v4;
      breakablePresentable->origin.y = v4[1];
      breakablePresentable->origin.z = v4[2];
      v6 = idEntity::GetPhysics(this);
      v7 = (float *)v6->GetAxis(this: v6, a2: 0);
      p_axis = (float *)&this->breakablePresentable->axis;
      *p_axis = *v7;
      p_axis[1] = v7[1];
      p_axis[2] = v7[2];
      p_axis[3] = v7[3];
      p_axis[4] = v7[4];
      p_axis[5] = v7[5];
      p_axis[6] = v7[6];
      p_axis[7] = v7[7];
      p_axis[8] = v7[8];
      idPresentableBreakable::Break(this: this->breakablePresentable, activator: nullptr);
      this->breakablePresentable->Present(this: this->breakablePresentable);
      v9 = this->presentable;
      if ( v9 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v9 = this->presentable;
      }
      v9->Present(this: v9);
    }
    this->brokenTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->brokenFrame = idAccolade::Count(this: &clientGame->gameTimeManager) + 1;
    v10 = idEntity::GetPhysics(this);
    v11 = v10->GetClipModel(this: v10, a2: 0);
    idClipModel::Unlink(this: v11);
    if ( idEntity::IsPlayingSound(this, channel: SND_CHANNEL_VOICE) )
      alarmBreakSound = this->alarmBreakSound;
    else
      alarmBreakSound = this->breakSound;
    if ( alarmBreakSound != nullptr )
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_VOICE2,
        shader: alarmBreakSound,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    idAlarm::StartFX((idAnimatedEntity *)this, condition: this->fxConditionBreak);
    if ( this->breakablePhysics != nullptr )
    {
      idEntity::ForceDormancy(this, dormant: false, durationMS: 10000);
      idEntity::BecomeActive(this, flags: 2);
    }
  }
}


// ========================================================================
// ?Damage@idAlarm@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82C7C2A0
// RVA : 0x00C7C2A0
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

float __fastcall idAlarm::Damage(
        idAlarm *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace)
{
  double v9; // fp1
  double v10; // fp1
  idSimpleHealth_vtbl *v11; // r10
  double v12; // fp31
  int v13; // r4
  float v15[2]; // [sp+50h] [-20h] BYREF

  if ( this->brokenTime == -1 )
  {
    v10 = idDeclDamage::DamageAmount(this: damageDef);
    v11 = this->alarmHealth.__vftable;
    v12 = (float)((float)v10 * (float)damageScale);
    v15[0] = 0.0;
    if ( ((unsigned __int8 (__fastcall *)(idSimpleHealth *, int, int, float *, double))v11->Damage_Impl)(
           a1: &this->alarmHealth,
           a2: v13,
           a3: 1,
           a4: v15,
           a5: v12) != 0 )
    {
      idAlarm::ToggleAlarm(this, enable: false);
      idAlarm::Break(this);
    }
    v9 = v12;
  }
  else
  {
    v9 = 0.0;
  }
  return *((float *)&v9 + 1);
}


// ========================================================================
// ??0idAlarm@@QAA@XZ
// EA  : 0x82C7C348
// RVA : 0x00C7C348
// PDB : w:\tech5\tungsten\game\entities\miscalarm.cpp
// ========================================================================

idAlarm *__fastcall idAlarm::idAlarm(idAlarm *this)
{
  int v2; // ctr
  float *p_pieceMinBounceVelocity; // r8
  float *p_y; // r9
  char flags; // r10

  idDynamicEntity::idDynamicEntity(this);
  this->__vftable = (idAlarm_vtbl *)&idAlarm::`vftable';
  this->breakModel.data = this->breakModel.baseBuffer;
  this->breakModel.len = 0;
  this->breakModel.allocedAndFlag = 20;
  this->breakModel.baseBuffer[0] = 0;
  this->alarmSound = nullptr;
  this->alarmBreakSound = nullptr;
  this->breakSound = nullptr;
  this->colorInactive = idColor::colorBlack;
  v2 = 9;
  this->colorActive = idColor::colorWhite;
  p_pieceMinBounceVelocity = &this->pieceMinBounceVelocity;
  p_y = &mat2_identity.mat[1].y;
  this->alarmHealth.components[0].max = 100.0;
  this->alarmHealth.components[0].cur = 100.0;
  this->alarmHealth.components[0].type = SIMPLE_HEALTH_MAX;
  this->alarmHealth.killThreshold = 0.0;
  this->alarmHealth.accumulatedDamageFrame = -1;
  this->alarmHealth.killingBlowDamage = 0.0;
  this->alarmHealth.isDead = false;
  this->alarmHealth.accumulatedFrameDamage = 0.0;
  this->alarmHealth.components[0].type = SIMPLE_HEALTH_HITPOINTS;
  this->alarmHealth.components[0].cur = 1.0;
  this->alarmHealth.__vftable = (idSimpleHealth_vtbl *)&idSimpleHealth::`vftable';
  this->alarmHealth.components[0].max = 1.0;
  this->fxDecl = nullptr;
  this->pieceMinBounceVelocity = 40.0;
  this->fxConditionActivate = FX_NONE;
  this->fxConditionBreak = FX_PROP_BREAK;
  this->impactSoundTable = nullptr;
  do
  {
    *++p_pieceMinBounceVelocity = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  flags = (char)this->flags;
  this->alarmActive = false;
  this->brokenTime = -1;
  this->brokenFrame = -1;
  this->breakablePhysics = nullptr;
  this->brokenModel = nullptr;
  this->breakablePresentable = nullptr;
  *(_BYTE *)&this->flags = flags | 0x40;
  return this;
}

