
// ========================================================================
// ??0idDynamicSceneEntity@@QAA@XZ
// EA  : 0x82C6E130
// RVA : 0x00C6E130
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idDynamicSceneEntity *__fastcall idDynamicSceneEntity::idDynamicSceneEntity(idDynamicSceneEntity *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idDynamicSceneEntity_vtbl *)&idDynamicSceneEntity::`vftable';
  return this;
}


// ========================================================================
// ??0idBinaryModel@@QAA@XZ
// EA  : 0x82C6E170
// RVA : 0x00C6E170
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idBinaryModel *__fastcall idBinaryModel::idBinaryModel(idBinaryModel *this)
{
  idEntity::idEntity(this);
  this->invisible = false;
  this->__vftable = (idBinaryModel_vtbl *)&idBinaryModel::`vftable';
  return this;
}


// ========================================================================
// ?IsVisible@idBinaryModel@@EAA_NXZ
// EA  : 0x82C6E1B8
// RVA : 0x00C6E1B8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

BOOL __fastcall idBinaryModel::IsVisible(idBinaryModel *this)
{
  return (_cntlzw(this->invisible) & 0x20) != 0;
}


// ========================================================================
// ?Event_IsHidden@idBinaryModel@@AAA?AVeventInt@@XZ
// EA  : 0x82C6E1C8
// RVA : 0x00C6E1C8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idBinaryModel *__fastcall idBinaryModel::Event_IsHidden(idBinaryModel *this, eventInt *result)
{
  eventInt::eventInt((eventInt *)this, i: HIBYTE(result[200].value));
  return this;
}


// ========================================================================
// ?ShowEditingDialog@idParticleEmitter@@UAAXXZ
// EA  : 0x82C6E200
// RVA : 0x00C6E200
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idParticleEmitter::ShowEditingDialog(idParticleEmitter *this)
{
  common->InitTool(this: common, a2: EDITOR_PARTICLE);
}


// ========================================================================
// ?UpdateEditingDialog@idParticleEmitter@@UAAXXZ
// EA  : 0x82C6E220
// RVA : 0x00C6E220
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idParticleEmitter::UpdateEditingDialog(idParticleEmitter *this)
{
  common->UpdateTool(this: common, a2: EDITOR_PARTICLE);
}


// ========================================================================
// ?TurnOn@idRegimeTile@@AAAXXZ
// EA  : 0x82C6E240
// RVA : 0x00C6E240
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idRegimeTile::TurnOn(idRegimeTile *this)
{
  float v2; // [sp+50h] [-20h] BYREF
  float v3[3]; // [sp+54h] [-1Ch] BYREF

  idEntity::StartSoundShader(
    this,
    channel: SND_CHANNEL_AMBIENT,
    shader: this->sndReactivate,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  this->Show(this);
  if ( this->shouldFadeOnActivate )
  {
    v2 = 1.0;
    v3[0] = 0.0;
    idFadeHelper::Fade(this: &this->fade, from: v3, to: &v2, time: &this->fadeTime, _noStippleFade: false);
    idEntity::BecomeActive(this, flags: 1);
  }
  this->health = this->maxHealth;
  this->powered = true;
  idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// ?Show@idFuncWind@@UAAXXZ
// EA  : 0x82C6E2F8
// RVA : 0x00C6E2F8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idFuncWind::Show(idWindEmitter *this)
{
  idEntity::Show(this);
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?Hide@idFuncWind@@UAAXXZ
// EA  : 0x82C6E330
// RVA : 0x00C6E330
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idFuncWind::Hide(idWindEmitter *this)
{
  idEntity::Hide(this);
  idEntity::BecomeInactive(this, flags: 1);
  if ( idEntity::GetBindMaster(this) != nullptr )
    idEntity::Unbind(this);
}


// ========================================================================
// ?SetModelByName@idDebrisEntity@@UAAXPBD@Z
// EA  : 0x82C6E380
// RVA : 0x00C6E380
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

// attributes: thunk
void __fastcall idDebrisEntity::SetModelByName(idDebrisEntity *this, const char *modelName)
{
  idEntity::SetModelByName(this, modelname: modelName);
}


// ========================================================================
// ?IsEverUsable@idGuiEntity@@UBA_NPBVidEntity@@@Z
// EA  : 0x82C6E388
// RVA : 0x00C6E388
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

BOOL __fastcall idGuiEntity::IsEverUsable(idGuiEntity *this, const idEntity *activator)
{
  return this->usable;
}


// ========================================================================
// ?Spawn@idReferenceMap@@QAAXXZ
// EA  : 0x82C6E390
// RVA : 0x00C6E390
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idReferenceMap::Spawn(idFuncShadowCaster *this)
{
  idPhysics *Physics; // r3

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0, a3: -1);
  idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
}


// ========================================================================
// ??0idDynamicJob@@QAA@XZ
// EA  : 0x82C6E3E8
// RVA : 0x00C6E3E8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idDynamicJob *__fastcall idDynamicJob::idDynamicJob(idDynamicJob *this)
{
  idEntity::idEntity(this);
  this->jobDecl = nullptr;
  this->__vftable = (idDynamicJob_vtbl *)&idDynamicJob::`vftable';
  *(_WORD *)&this->endJob = 1;
  return this;
}


// ========================================================================
// ?OnActivate@idDynamicJob@@EAAXPAVidEntity@@@Z
// EA  : 0x82C6E438
// RVA : 0x00C6E438
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDynamicJob::OnActivate(idDynamicJob *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r3
  const idDeclJob *jobDecl; // r4

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  if ( PlayerFromEntity != nullptr
    || this->forceActivateOnPlayer && (PlayerFromEntity = idGameLocal::GetPlayer(this: gameLocal, i: 0)) != nullptr )
  {
    jobDecl = this->jobDecl;
    if ( jobDecl != nullptr )
    {
      if ( this->endJob )
        idPlayer::StartRemovalOfDynamicJob(this: PlayerFromEntity, job: jobDecl);
      else
        idPlayer::OfferDynamicJob(this: PlayerFromEntity, job: jobDecl);
    }
  }
}


// ========================================================================
// ?Spawn@idInformationEntity@@QAAXXZ
// EA  : 0x82C6E4C0
// RVA : 0x00C6E4C0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idInformationEntity::Spawn(idInformationEntity *this)
{
  idPhysics *Physics; // r29
  idPhysics_vtbl *v3; // r31
  idClipModel *MoveableClipModel; // r3
  idPhysics *v5; // r3
  idPhysics *v6; // r3

  Physics = idEntity::GetPhysics(this);
  v3 = Physics->__vftable;
  MoveableClipModel = idEntity::CreateMoveableClipModel(this, barrelCollision: false, overrideRadius: -1.0);
  ((void (__fastcall *)(idPhysics *, idClipModel *, double))v3->SetClipModel)(
    a1: Physics,
    a2: MoveableClipModel,
    a3: 1.0);
  v5 = idEntity::GetPhysics(this);
  v5->SetContents(this: v5, a2: 2113536, a3: -1);
  v6 = idEntity::GetPhysics(this);
  v6->EnableClip(this: v6);
}


// ========================================================================
// ?Spawn@idWorldClipBounds@@QAAXXZ
// EA  : 0x82C6E558
// RVA : 0x00C6E558
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idWorldClipBounds::Spawn(idWorldClipBounds *this)
{
  idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
}


// ========================================================================
// ??0idHorizonScale@@QAA@XZ
// EA  : 0x82C6E568
// RVA : 0x00C6E568
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idHorizonScale *__fastcall idHorizonScale::idHorizonScale(idHorizonScale *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idHorizonScale_vtbl *)&idHorizonScale::`vftable';
  this->radiusInner = 1024.0;
  this->radiusOuter = 2048.0;
  return this;
}


// ========================================================================
// ??0idStaticEntity@@QAA@XZ
// EA  : 0x82C6E708
// RVA : 0x00C6E708
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idStaticEntity *__fastcall idStaticEntity::idStaticEntity(idStaticEntity *this)
{
  char flags; // r8

  idEntity::idEntity(this);
  flags = (char)this->flags;
  this->bsp = false;
  this->__vftable = (idStaticEntity_vtbl *)&idStaticEntity::`vftable';
  this->aas = false;
  *(_BYTE *)&this->flags = flags | 4;
  return this;
}


// ========================================================================
// ?UpdateColorModulate@idDynamicEntity@@AAAXXZ
// EA  : 0x82C6E7C8
// RVA : 0x00C6E7C8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDynamicEntity::UpdateColorModulate(idDynamicEntity *this)
{
  int GameMs; // r3
  bool v3; // r4
  int v4; // r10
  int v5; // r9
  int v6; // r8
  int v7; // r7
  double v8; // fp1
  idPresentable *presentable; // r3
  idPresentable *v10; // r11
  __int64 v11; // [sp+8h] [-68h]
  __int64 v12; // [sp+10h] [-60h]
  __int64 v13; // [sp+18h] [-58h]
  __int64 v14; // [sp+20h] [-50h]
  __int64 v15; // [sp+28h] [-48h]
  __int64 v16; // [sp+58h] [-18h]

  if ( this->colorModulateTable != nullptr && this->colorModulateActive )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v8 = idLookupTable::TableLookup(
           this: this->colorModulateTable->table,
           time: (float)((float)((float)__SPAIR64__(&unk_82390000, GameMs) * (float)0.001) * this->colorModulateTimeScale),
           fastSearch: v3);
    presentable = this->presentable;
    if ( presentable != nullptr )
    {
      *((float *)&v16 + 1) = this->colorPreModulate.w * (float)v8;
      *(float *)&v16 = this->colorPreModulate.z * (float)v8;
      idPresentable::SetParm(
        this: presentable,
        parm: rp->Color,
        v4: v16,
        a4: v7,
        a5: v6,
        a6: v5,
        a7: v4,
        a8: v11,
        a9: v12,
        a10: v13,
        a11: v14,
        a12: v15);
      v10 = this->presentable;
      if ( v10 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v10 = this->presentable;
      }
      v10->Present(this: v10);
    }
  }
}


// ========================================================================
// ?Hide@idDynamicEntity@@UAAXXZ
// EA  : 0x82C6E8D8
// RVA : 0x00C6E8D8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDynamicEntity::Hide(idDynamicEntity *this)
{
  idPhysics *Physics; // r3
  int v3; // r10
  int v4; // r9
  int v5; // r8
  int v6; // r7
  int v7; // r6
  int v8; // r5
  idPresentable *presentable; // r3
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  idPresentable *v14; // r4
  int v15; // [sp+8h] [-58h]
  int v16; // [sp+Ch] [-54h]
  int v17; // [sp+10h] [-50h]
  int v18; // [sp+14h] [-4Ch]
  int v19; // [sp+18h] [-48h]
  idPresentable *v20; // [sp+1Ch] [-44h]

  idEntity::Hide(this);
  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0, a3: -1);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::SetClipModelContents(this: presentable, newContents: 0, a3: v8, a4: v7, a5: v6, a6: v5, a7: v4, a8: v3);
  v14 = this->presentable;
  if ( v14 != nullptr )
    idClientGame::MarkPresentableSerialized(
      this: clientGame,
      presentable: v14,
      serialized: true,
      deleted: false,
      a5: v13,
      a6: v12,
      a7: v11,
      a8: v10,
      a9: v15,
      a10: v16,
      a11: v17,
      a12: v18,
      a13: v19,
      a14: v20);
}


// ========================================================================
// ?Show@idDynamicEntity@@UAAXXZ
// EA  : 0x82C6E968
// RVA : 0x00C6E968
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDynamicEntity::Show(idDynamicEntity *this)
{
  idPhysics *Physics; // r3
  int v3; // r10
  int v4; // r9
  int v5; // r8
  int v6; // r7
  int v7; // r6
  int v8; // r5
  idPresentable *presentable; // r3
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  idPresentable *v14; // r4
  int v15; // [sp+8h] [-58h]
  int v16; // [sp+Ch] [-54h]
  int v17; // [sp+10h] [-50h]
  int v18; // [sp+14h] [-4Ch]
  int v19; // [sp+18h] [-48h]
  idPresentable *v20; // [sp+1Ch] [-44h]

  idEntity::Show(this);
  if ( this->solid )
  {
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 1, a3: -1);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::SetClipModelContents(
      this: presentable,
      newContents: 1,
      a3: v8,
      a4: v7,
      a5: v6,
      a6: v5,
      a7: v4,
      a8: v3);
    v14 = this->presentable;
    if ( v14 != nullptr )
      idClientGame::MarkPresentableSerialized(
        this: clientGame,
        presentable: v14,
        serialized: true,
        deleted: false,
        a5: v13,
        a6: v12,
        a7: v11,
        a8: v10,
        a9: v15,
        a10: v16,
        a11: v17,
        a12: v18,
        a13: v19,
        a14: v20);
  }
}


// ========================================================================
// ?OnActivate@idDynamicEntity@@EAAXPAVidEntity@@@Z
// EA  : 0x82C6EA00
// RVA : 0x00C6EA00
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDynamicEntity::OnActivate(idDynamicEntity *this, idEntity *activator)
{
  int GameMs; // r3
  unsigned int active; // r10
  int idCombatStage_useRelaxedChatterVO; // r7
  idDynamicEntity_vtbl *v6; // r11
  __int64 v7; // r9
  idPresentable *presentable; // r3
  double v9; // fp31
  idPresentable *v10; // r11

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  active = this->active;
  this->spawnTime = GameMs;
  this->active = (_cntlzw(active) & 0x20) != 0;
  idCombatStage_useRelaxedChatterVO = (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this);
  v6 = this->__vftable;
  if ( idCombatStage_useRelaxedChatterVO != 0 )
    v6->Show(this);
  else
    v6->Hide_2(this);
  presentable = this->presentable;
  LODWORD(v7) = this->spawnTime;
  v9 = (float)((float)v7 * (float)0.001);
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::SetParm(this: presentable, parm: rp->TimeOffset, scalar: -v9);
  v10 = this->presentable;
  if ( v10 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v10 = this->presentable;
  }
  v10->Present(this: v10);
}


// ========================================================================
// ?Event_Fade@idDynamicEntity@@AAA?AVeventVoid@@MMM@Z
// EA  : 0x82C6EB08
// RVA : 0x00C6EB08
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idDynamicEntity *__fastcall idDynamicEntity::Event_Fade(
        idDynamicEntity *this,
        idEntity *result,
        double from,
        double to,
        double secs,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        float a11,
        float a12,
        float a13,
        float a14,
        float a15,
        float a16,
        float a17,
        float a18,
        float a19,
        float a20)
{
  int v23; // [sp+50h] [-20h] BYREF
  int v24; // [sp+54h] [-1Ch]

  a18 = from;
  a20 = to;
  v24 = (int)(float)((float)1000.0 * (float)secs);
  v23 = v24;
  idFadeHelper::Fade(
    this: (idFadeHelper *)&result[1].name.baseBuffer[16],
    from: &a18,
    to: &a20,
    time: &v23,
    _noStippleFade: false);
  idEntity::BecomeActive(this: result, flags: 1);
  return this;
}


// ========================================================================
// ?Event_FadeNoStipple@idDynamicEntity@@AAA?AVeventVoid@@MMM@Z
// EA  : 0x82C6EB88
// RVA : 0x00C6EB88
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idDynamicEntity *__fastcall idDynamicEntity::Event_FadeNoStipple(
        idDynamicEntity *this,
        idEntity *result,
        double from,
        double to,
        double secs,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        float a11,
        float a12,
        float a13,
        float a14,
        float a15,
        float a16,
        float a17,
        float a18,
        float a19,
        float a20)
{
  int v23; // [sp+50h] [-20h] BYREF
  int v24; // [sp+54h] [-1Ch]

  a18 = from;
  a20 = to;
  v24 = (int)(float)((float)1000.0 * (float)secs);
  v23 = v24;
  idFadeHelper::Fade(
    this: (idFadeHelper *)&result[1].name.baseBuffer[16],
    from: &a18,
    to: &a20,
    time: &v23,
    _noStippleFade: true);
  idEntity::BecomeActive(this: result, flags: 1);
  return this;
}


// ========================================================================
// ?Event_ActivateColorModulate@idDynamicEntity@@AAA?AVeventVoid@@XZ
// EA  : 0x82C6EC08
// RVA : 0x00C6EC08
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idDynamicEntity *__fastcall idDynamicEntity::Event_ActivateColorModulate(
        idDynamicEntity *this,
        idDynamicEntity *result)
{
  const idDeclTable *colorModulateTable; // r11

  if ( !result->colorModulateActive )
  {
    colorModulateTable = result->colorModulateTable;
    result->colorModulateActive = true;
    if ( colorModulateTable != nullptr )
    {
      idEntity::BecomeActive(this: result, flags: 1);
      idDynamicEntity::UpdateColorModulate(this: result);
    }
  }
  return this;
}


// ========================================================================
// ?Event_DeactivateColorModulate@idDynamicEntity@@AAA?AVeventVoid@@XZ
// EA  : 0x82C6EC78
// RVA : 0x00C6EC78
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idDynamicEntity *__fastcall idDynamicEntity::Event_DeactivateColorModulate(
        idDynamicEntity *this,
        idEntity *result,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idPresentable *presentable; // r3
  idPresentable *v11; // r11
  __int64 v13; // [sp+8h] [-68h]
  __int64 v14; // [sp+10h] [-60h]
  __int64 v15; // [sp+18h] [-58h]
  __int64 v16; // [sp+20h] [-50h]
  __int64 v17; // [sp+28h] [-48h]

  if ( result[1].name.baseBuffer[4] != 0 )
  {
    presentable = result->presentable;
    result[1].name.baseBuffer[4] = 0;
    if ( presentable != nullptr )
    {
      idPresentable::SetParm(
        this: presentable,
        parm: rp->Color,
        v4: *(_QWORD *)(LODWORD(result[1].spawnOrientation.mat[0].y) + 868),
        a4: a5,
        a5: a6,
        a6: a7,
        a7: a8,
        a8: v13,
        a9: v14,
        a10: v15,
        a11: v16,
        a12: v17);
      v11 = result->presentable;
      if ( v11 == nullptr )
      {
        idEntity::InitPresentableInternal(this: result);
        v11 = result->presentable;
      }
      v11->Present(this: v11);
    }
  }
  return this;
}


// ========================================================================
// ?Spawn@idDynamicSceneEntity@@QAAXXZ
// EA  : 0x82C6ED18
// RVA : 0x00C6ED18
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDynamicSceneEntity::Spawn(idDynamicSceneEntity *this)
{
  idRenderModel *RenderModelFromPresentable; // r3

  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
  if ( RenderModelFromPresentable != nullptr )
    *((_BYTE *)&RenderModelFromPresentable->g + 104) |= 4u;
}


// ========================================================================
// ?Spawn@idBinaryModel@@QAAXXZ
// EA  : 0x82C6ED50
// RVA : 0x00C6ED50
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idBinaryModel::Spawn(idBinaryModel *this)
{
  clientGame->renderWorld->SetBinaryModelState(
    this: clientGame->renderWorld,
    a2: this->name.data,
    a3: (_cntlzw(this->invisible) & 0x20) != 0);
}


// ========================================================================
// ?OnActivate@idBinaryModel@@EAAXPAVidEntity@@@Z
// EA  : 0x82C6ED80
// RVA : 0x00C6ED80
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idBinaryModel::OnActivate(idBinaryModel *this, idEntity *activator)
{
  char *data; // r4
  BOOL v3; // r8

  data = this->name.data;
  v3 = (_cntlzw(this->invisible) & 0x20) != 0;
  this->invisible = v3;
  clientGame->renderWorld->SetBinaryModelState(this: clientGame->renderWorld, a2: data, a3: (_cntlzw(v3) & 0x20) != 0);
}


// ========================================================================
// ?Hide@idBinaryModel@@EAAXXZ
// EA  : 0x82C6EDB8
// RVA : 0x00C6EDB8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idBinaryModel::Hide(idBinaryModel *this)
{
  char *data; // r4

  if ( !this->invisible )
  {
    data = this->name.data;
    this->invisible = true;
    clientGame->renderWorld->SetBinaryModelState(this: clientGame->renderWorld, a2: data, a3: false);
  }
}


// ========================================================================
// ?Show@idBinaryModel@@EAAXXZ
// EA  : 0x82C6EDF8
// RVA : 0x00C6EDF8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idBinaryModel::Show(idBinaryModel *this)
{
  char *data; // r4

  if ( this->invisible )
  {
    data = this->name.data;
    this->invisible = false;
    clientGame->renderWorld->SetBinaryModelState(this: clientGame->renderWorld, a2: data, a3: true);
  }
}


// ========================================================================
// ??1idParticleEmitter@@UAA@XZ
// EA  : 0x82C6EE40
// RVA : 0x00C6EE40
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idParticleEmitter::~idParticleEmitter(idParticleEmitter *this)
{
  this->__vftable = (idParticleEmitter_vtbl *)&idParticleEmitter::`vftable';
  idEntity::FreeRenderModel(this);
  this->__vftable = (idParticleEmitter_vtbl *)&idDynamicEntity::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$496214
// EA  : 0x82C6EE9C
// RVA : 0x00C6EE9C
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_496214()
{
  int v0; // r12

  idDynamicEntity::~idDynamicEntity(this: *(idDynamicEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?AllocPresentable@idParticleEmitter@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C6EED0
// RVA : 0x00C6EED0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idPresentableParticleEmitter *__fastcall idParticleEmitter::AllocPresentable(
        idParticleEmitter *this,
        idTreeAnimator *renderModel_)
{
  idPresentableParticleEmitter *v4; // r3

  v4 = (idPresentableParticleEmitter *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                         size: 0x518u,
                                         tag: TAG_PRESENTABLE,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    return idPresentableParticleEmitter::idPresentableParticleEmitter(
             this: v4,
             ps: this->particleSystem,
             e: this,
             renderModel_,
             entityNumber_: this->entityNumber,
             fxDecl_: nullptr);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496240
// EA  : 0x82C6EF44
// RVA : 0x00C6EF44
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_496240()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?Hide@idParticleEmitter@@UAAXXZ
// EA  : 0x82C6EF70
// RVA : 0x00C6EF70
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idParticleEmitter::Hide(idRibbonEmitter *this)
{
  idDynamicEntity::Hide(this);
  idEntity::BecomeInactive(this, flags: 1);
  this->hidden = true;
  if ( idEntity::GetBindMaster(this) != nullptr )
    idEntity::Unbind(this);
}


// ========================================================================
// ?GetScale@idParticleEmitter@@UBAXAAVidVec3@@@Z
// EA  : 0x82C6EFC8
// RVA : 0x00C6EFC8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idParticleEmitter::GetScale(idParticleEmitter *this, idVec3 *out)
{
  *out = this->distributionScale;
}


// ========================================================================
// ?UpdatePresentable@idParticleEmitter@@AAAXXZ
// EA  : 0x82C6EFE8
// RVA : 0x00C6EFE8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idParticleEmitter::UpdatePresentable(idParticleEmitter *this)
{
  idPresentable *presentable; // r3
  int v3; // r31
  float v4[6]; // [sp+50h] [-30h] BYREF

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v3 = (int)presentable->GetParticleEmitterInterface(this: presentable);
  if ( common->IsMultiplayer(this: common) && v3 != 0 )
  {
    this->GetColor(this, a2: (idVec4 *)v4);
    *(float *)(v3 + 1280) = v4[0];
    *(float *)(v3 + 1284) = v4[1];
    *(float *)(v3 + 1288) = v4[2];
    *(float *)(v3 + 1292) = v4[3];
    *(_BYTE *)(v3 + 1296) = this->useGlobalShadows;
    *(_BYTE *)(v3 + 1297) = this->useSmokeSystem;
    *(float *)(v3 + 1240) = this->fadeIn;
    *(float *)(v3 + 1244) = this->fadeOut;
    *(float *)(v3 + 1248) = this->alphaScale;
    *(float *)(v3 + 1256) = this->distributionScale.x;
    *(float *)(v3 + 1260) = this->distributionScale.y;
    *(float *)(v3 + 1264) = this->distributionScale.z;
    *(_DWORD *)(v3 + 1252) = this->smokeSystemRate;
  }
}


// ========================================================================
// ?OnActivate@idParticleEmitter@@UAAXPAVidEntity@@@Z
// EA  : 0x82C6F0F0
// RVA : 0x00C6F0F0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idParticleEmitter::OnActivate(idParticleEmitter *this, idEntity *activator)
{
  idPresentable *presentable; // r3
  int v4; // r3
  double fadeOut; // fp13
  int startDelay; // r5
  const idEventDef *v7; // r4
  int v8; // [sp+50h] [-20h] BYREF
  int v9; // [sp+54h] [-1Ch]
  float v10; // [sp+58h] [-18h] BYREF
  float v11; // [sp+5Ch] [-14h] BYREF

  if ( this->cycleTrigger || this->hidden )
  {
    startDelay = this->startDelay;
    v7 = &EV_TriggerShow;
  }
  else
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v4 = ((int (__fastcall *)(idPresentable *, idEntity *))presentable->GetParticleEmitterInterface)(
           a1: presentable,
           a2: activator);
    if ( v4 != 0 )
      (*(void (__fastcall **)(int))(*(_DWORD *)v4 + 328))(a1: v4);
    fadeOut = this->fadeOut;
    if ( fadeOut == 0.0 )
    {
      this->Hide_2(this);
      return;
    }
    v10 = 0.0;
    v11 = 1.0;
    v9 = (int)(float)((float)fadeOut * (float)1000.0);
    v8 = v9;
    idFadeHelper::Fade(this: &this->fade, from: &v11, to: &v10, time: &v8, _noStippleFade: false);
    idEntity::BecomeActive(this, flags: 1);
    startDelay = v8 + 50;
    v7 = &EV_Hide;
  }
  idEventReceiver::PostEventMS(this, ev: v7, time: startDelay);
}


// ========================================================================
// ?AllocPresentable@idElectricBoltEmitter@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C6F230
// RVA : 0x00C6F230
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idPresentableEBoltEmitter *__fastcall idElectricBoltEmitter::AllocPresentable(
        idElectricBoltEmitter *this,
        idTreeAnimator *renderModel_)
{
  idPresentableEBoltEmitter *v4; // r3
  const idSoundShader *v6; // [sp+8h] [-A8h]
  const idVec2 *v7; // [sp+Ch] [-A4h]
  const idList<idEntityPtr<idEntity>,5> *v8; // [sp+10h] [-A0h]
  int v9; // [sp+14h] [-9Ch]
  int v10; // [sp+18h] [-98h]
  int v11; // [sp+1Ch] [-94h]
  int v12; // [sp+20h] [-90h]
  int v13; // [sp+24h] [-8Ch]
  int v14; // [sp+28h] [-88h]
  int v15; // [sp+2Ch] [-84h]
  int v16; // [sp+30h] [-80h]
  int v17; // [sp+34h] [-7Ch]
  int v18; // [sp+38h] [-78h]
  int v19; // [sp+3Ch] [-74h]
  int v20; // [sp+40h] [-70h]
  int v21; // [sp+44h] [-6Ch]
  int v22; // [sp+48h] [-68h]
  int v23; // [sp+4Ch] [-64h]
  int v24; // [sp+50h] [-60h]
  int v25; // [sp+58h] [-58h]
  int v26; // [sp+5Ch] [-54h]
  int v27; // [sp+60h] [-50h]
  int v28; // [sp+68h] [-48h]

  v4 = (idPresentableEBoltEmitter *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x500u,
                                      tag: TAG_PRESENTABLE,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    return idPresentableEBoltEmitter::idPresentableEBoltEmitter(
             this: v4,
             e: this,
             renderModel_,
             minResetTime_: this->minResetTime,
             maxResetTime_: this->maxResetTime,
             startOff_: this->startOff,
             electricBoltSystem_: this->electricBoltSystem,
             sndPowerDown_: this->sndPowerDown,
             maxConeAngle_: this->maxConeAngle,
             sndPowerUp_: v6,
             length_: v7,
             targets_: v8,
             a13: v9,
             a14: v10,
             a15: v11,
             a16: v12,
             a17: v13,
             a18: v14,
             a19: v15,
             a20: v16,
             a21: v17,
             a22: v18,
             a23: v19,
             a24: v20,
             a25: v21,
             a26: v22,
             a27: v23,
             a28: v24,
             a29: this->sndPowerUp,
             a30: v25,
             a31: v26,
             a32: v27,
             a33: &this->length,
             a34: v28,
             a35: (const idList<idEntityPtr<idAISearchHintGroup>,5> *)&this->targets);
  else
    return nullptr;
}


// ========================================================================
// __unwind$496337_0
// EA  : 0x82C6F2C8
// RVA : 0x00C6F2C8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_496337_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 176 + 112), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?GetNextEndPos@idElectricBoltEmitter@@AAA?AVidVec3@@PAVidEntity@@@Z
// EA  : 0x82C6F2F8
// RVA : 0x00C6F2F8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idElectricBoltEmitter *__fastcall idElectricBoltEmitter::GetNextEndPos(
        idElectricBoltEmitter *this,
        idEntity *result,
        idAI2 *target)
{
  idAI2 *v6; // r3
  idEntity *v7; // r29
  float *RenderModelFromPresentable; // r3
  double v9; // fp8
  double v10; // fp6
  idRenderModel *v11; // r3
  float z; // r8
  float x; // r7
  idPhysics *Physics; // r3
  float *v16; // r3
  double v17; // fp8
  double v18; // fp6
  float y; // r10
  float v20; // r9
  idPhysics *v21; // r3
  int v22; // r3
  float v23; // r7
  float v24; // r6
  __int64 v25; // r10
  unsigned int v26; // r6
  const idMat3 *v27; // r3
  __int64 v28; // r4
  unsigned int v29; // r8
  double v30; // fp2
  const idMat3 *v31; // r3
  idPhysics *v32; // r3
  double v33; // fp11
  double v34; // fp9
  __int64 v35; // r9
  idPhysics_vtbl *v36; // r6
  double v37; // fp31
  double v38; // fp30
  double v39; // fp29
  float *v40; // r3
  double v41; // fp10
  double v42; // fp9
  idVec3 v43; // [sp+50h] [-180h] BYREF
  idMat3 v44; // [sp+60h] [-170h] BYREF
  float v45; // [sp+84h] [-14Ch]
  float v46; // [sp+88h] [-148h]
  float v47; // [sp+8Ch] [-144h]
  float v48; // [sp+90h] [-140h]
  float v49; // [sp+94h] [-13Ch]
  float v50; // [sp+98h] [-138h]
  float v51; // [sp+9Ch] [-134h]
  float v52; // [sp+A0h] [-130h]
  float v53; // [sp+A4h] [-12Ch]
  float v54; // [sp+A8h] [-128h]
  float v55; // [sp+ACh] [-124h]
  float v56; // [sp+B0h] [-120h]
  float v57; // [sp+B4h] [-11Ch]
  float v58; // [sp+B8h] [-118h]
  float v59; // [sp+BCh] [-114h]
  char v60; // [sp+C0h] [-110h]
  idRotation v61; // [sp+D0h] [-100h] BYREF
  idMat3 v62[2]; // [sp+120h] [-B0h] BYREF

  if ( target != nullptr )
  {
    v6 = idAI2::CastTo(c: target);
    v7 = v6;
    if ( v6 != nullptr && idEntity::GetRenderModelFromPresentable(this: v6) != nullptr )
    {
      RenderModelFromPresentable = (float *)idEntity::GetRenderModelFromPresentable(this: v7);
      v9 = (float)(RenderModelFromPresentable[27] + RenderModelFromPresentable[24]);
      v10 = (float)(RenderModelFromPresentable[28] + RenderModelFromPresentable[25]);
      v43.x = (float)(RenderModelFromPresentable[26] + RenderModelFromPresentable[23]) * (float)0.5;
      v43.y = (float)v9 * (float)0.5;
      v43.z = (float)v10 * (float)0.5;
      v11 = idEntity::GetRenderModelFromPresentable(this: v7);
      idRenderModel::LocalPointToGlobal(this: v11, in: &v43, out: (idVec3 *)&v44.mat[1].y);
      z = v44.mat[1].z;
      x = v44.mat[2].x;
      this->__vftable = (idElectricBoltEmitter_vtbl *)LODWORD(v44.mat[1].y);
      *(float *)&this->listenerList = z;
      *(float *)&this->listeningToList = x;
      return this;
    }
    else
    {
      if ( idEntity::GetPhysics(this: target) != nullptr )
      {
        Physics = idEntity::GetPhysics(this: target);
        v16 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
        v17 = (float)(v16[4] + v16[1]);
        v18 = (float)(v16[5] + v16[2]);
        *(float *)&this->__vftable = (float)(v16[3] + *v16) * (float)0.5;
        *(float *)&this->listenerList = (float)v17 * (float)0.5;
        *(float *)&this->listeningToList = (float)v18 * (float)0.5;
      }
      else
      {
        y = target->spawnPosition.y;
        v20 = target->spawnPosition.z;
        this->__vftable = (idElectricBoltEmitter_vtbl *)LODWORD(target->spawnPosition.x);
        *(float *)&this->listenerList = y;
        *(float *)&this->listeningToList = v20;
      }
      return this;
    }
  }
  else
  {
    v21 = idEntity::GetPhysics(this: result);
    v22 = (int)v21->GetAxis(this: v21, a2: 0);
    v23 = *(float *)(v22 + 4);
    v24 = *(float *)(v22 + 8);
    v44.mat[0].x = *(float *)v22;
    v44.mat[0].y = v23;
    v44.mat[0].z = v24;
    idVec3::ToMat3(this: v62[0].mat, result: &v44);
    HIDWORD(v25) = 0x82000000;
    v26 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v26 + 1013904223;
    v60 = 0;
    LODWORD(v25) = ((v26 + 1013904223) >> 10) & 0x7FFF;
    *(_QWORD *)&v43.x = v25;
    v48 = v44.mat[0].y;
    v44.mat[2].z = vec3_origin.x;
    v45 = vec3_origin.y;
    v46 = vec3_origin.z;
    v47 = v44.mat[0].x;
    v49 = v44.mat[0].z;
    v51 = mat3_identity.mat[0].x;
    v52 = mat3_identity.mat[0].y;
    v53 = mat3_identity.mat[0].z;
    v54 = mat3_identity.mat[1].x;
    v55 = mat3_identity.mat[1].y;
    v56 = mat3_identity.mat[1].z;
    v57 = mat3_identity.mat[2].x;
    v58 = mat3_identity.mat[2].y;
    v59 = mat3_identity.mat[2].z;
    v50 = (float)((float)((float)v25 * (float)0.000061037019) - (float)1.0) * (float)360.0;
    v27 = idRotation::ToMat3(this: (idRotation *)&v44.mat[2].z);
    idMat3::operator*=(this: v62, a: v27);
    HIDWORD(v28) = &v61;
    v29 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v29 + 1013904223;
    v61.axisValid = false;
    LODWORD(v28) = ((v29 + 1013904223) >> 10) & 0x7FFF;
    v30 = *(float *)&result[1].targets.size;
    *(_QWORD *)&v43.x = v28;
    v61.origin.x = vec3_origin.x;
    v61.origin.y = vec3_origin.y;
    v61.origin.z = vec3_origin.z;
    v61.vec.y = v62[0].mat[1].y;
    v61.vec.x = v62[0].mat[1].x;
    v61.vec.z = v62[0].mat[1].z;
    v61.axis.mat[0].x = mat3_identity.mat[0].x;
    v61.axis.mat[0].y = mat3_identity.mat[0].y;
    v61.axis.mat[0].z = mat3_identity.mat[0].z;
    v61.axis.mat[1].x = mat3_identity.mat[1].x;
    v61.axis.mat[1].y = mat3_identity.mat[1].y;
    v61.axis.mat[1].z = mat3_identity.mat[1].z;
    v61.axis.mat[2].x = mat3_identity.mat[2].x;
    v61.axis.mat[2].y = mat3_identity.mat[2].y;
    v61.axis.mat[2].z = mat3_identity.mat[2].z;
    v61.angle = (float)((float)((float)v28 * (float)0.000061037019) - (float)1.0) * (float)v30;
    v31 = idRotation::ToMat3(this: &v61);
    idMat3::operator*=(this: v62, a: v31);
    v32 = idEntity::GetPhysics(this: result);
    v33 = *(float *)&result[1].targets.granularity;
    v34 = (float)(*(float *)&result[1].renderModelInfo.model - *(float *)&result[1].targets.granularity);
    HIDWORD(v35) = 1664525 * clientGame->random.seed;
    clientGame->random.seed = HIDWORD(v35) + 1013904223;
    v36 = v32->__vftable;
    LODWORD(v35) = ((unsigned int)(HIDWORD(v35) + 1013904223) >> 10) & 0x7FFF;
    *(_QWORD *)&v43.x = v35;
    v37 = (float)(v62[0].mat[0].x
                * (float)((float)((float)((float)v35 * (float)v34) * (float)0.000030518509) + (float)v33));
    v38 = (float)(v62[0].mat[0].y
                * (float)((float)((float)((float)v35 * (float)v34) * (float)0.000030518509) + (float)v33));
    v39 = (float)(v62[0].mat[0].z
                * (float)((float)((float)((float)v35 * (float)v34) * (float)0.000030518509) + (float)v33));
    v40 = (float *)v36->GetOrigin(this: v32, a2: 0);
    v41 = (float)(v40[1] + (float)v38);
    v42 = (float)(v40[2] + (float)v39);
    *(float *)&this->__vftable = *v40 + (float)v37;
    *(float *)&this->listenerList = v41;
    *(float *)&this->listeningToList = v42;
    return this;
  }
}


// ========================================================================
// ?Hide@idElectricBoltEmitter@@UAAXXZ
// EA  : 0x82C6F758
// RVA : 0x00C6F758
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idElectricBoltEmitter::Hide(idElectricBoltEmitter *this)
{
  idDynamicEntity::Hide(this);
  idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// ?Show@idElectricBoltEmitter@@UAAXXZ
// EA  : 0x82C6F790
// RVA : 0x00C6F790
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idElectricBoltEmitter::Show(idElectricBoltEmitter *this)
{
  idDynamicEntity::Show(this);
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?Event_Deactivate@idElectricBoltEmitter@@QAA?AVeventVoid@@XZ
// EA  : 0x82C6F7C8
// RVA : 0x00C6F7C8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idElectricBoltEmitter *__fastcall idElectricBoltEmitter::Event_Deactivate(
        idElectricBoltEmitter *this,
        idEntity *result)
{
  const idSoundShader *list; // r5

  list = (const idSoundShader *)result[1].targets.list;
  if ( list != nullptr )
    idEntity::StartSoundShader(
      this: result,
      channel: SND_CHANNEL_ANY,
      shader: list,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
  idEntity::BecomeInactive(this: result, flags: 1);
  return this;
}


// ========================================================================
// ??1idRibbonEmitter@@UAA@XZ
// EA  : 0x82C6F838
// RVA : 0x00C6F838
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idRibbonEmitter::~idRibbonEmitter(idRibbonEmitter *this)
{
  this->__vftable = (idRibbonEmitter_vtbl *)&idRibbonEmitter::`vftable';
  idEntity::FreeRenderModel(this);
  idRibbonManager::Shutdown(this: &this->ribbonManager);
  idRibbonManager::~idRibbonManager(this: &this->ribbonManager);
  this->__vftable = (idRibbonEmitter_vtbl *)&idDynamicEntity::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$496807
// EA  : 0x82C6F890
// RVA : 0x00C6F890
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_496807()
{
  int v0; // r12

  idDynamicEntity::~idDynamicEntity(this: *(idDynamicEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$496808
// EA  : 0x82C6F8B8
// RVA : 0x00C6F8B8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_496808()
{
  int v0; // r12

  idRibbonManager::~idRibbonManager(this: (idRibbonManager *)(*(_DWORD *)(v0 - 112 + 132) + 888));
}


// ========================================================================
// ?Spawn@idRibbonEmitter@@QAAXXZ
// EA  : 0x82C6F8E8
// RVA : 0x00C6F8E8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idRibbonEmitter::Spawn(idRibbonEmitter *this)
{
  idRibbonModelManager *p_ribbonModelManager; // r29
  idRenderModelBeam *NumContacts; // r3
  idPhysics *Physics; // r29
  int GameMs; // r28
  const idVec3 *v6; // r3

  if ( this->startOff )
  {
    this->hidden = true;
    idEntity::FreeRenderModel(this);
    idEntity::UpdateVisuals(this);
  }
  else
  {
    this->hidden = false;
    p_ribbonModelManager = &clientGame->gameLibEffects.ribbonModelManager;
    NumContacts = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: (idAnimator_ChannelWeight *)clientGame);
    idRibbonManager::Init(
      this: &this->ribbonManager,
      _ribbonDecl: this->declRibbon,
      _beamModel: NumContacts,
      _modelManager: p_ribbonModelManager);
    Physics = idEntity::GetPhysics(this);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v6 = Physics->GetOrigin(this: Physics, a2: 0);
    idRibbonManager::StartRibbon(this: &this->ribbonManager, spawnTime: GameMs, spawnOrg: v6);
    idEntity::BecomeActive(this, flags: 1);
  }
}


// ========================================================================
// ?Show@idRibbonEmitter@@UAAXXZ
// EA  : 0x82C6F9B0
// RVA : 0x00C6F9B0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idRibbonEmitter::Show(idRibbonEmitter *this)
{
  idDynamicEntity::Show(this);
  idEntity::BecomeActive(this, flags: 1);
  this->hidden = false;
}


// ========================================================================
// ?OnActivate@idRibbonEmitter@@UAAXPAVidEntity@@@Z
// EA  : 0x82C6F9F0
// RVA : 0x00C6F9F0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idRibbonEmitter::OnActivate(idRibbonEmitter *this, idEntity *activator)
{
  idRibbonModelManager *p_ribbonModelManager; // r29
  idRenderModelBeam *NumContacts; // r3
  idPhysics *Physics; // r29
  int GameMs; // r28
  const idVec3 *v7; // r3

  if ( this->cycleTrigger || this->hidden )
  {
    this->Show(this);
    p_ribbonModelManager = &clientGame->gameLibEffects.ribbonModelManager;
    NumContacts = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: (idAnimator_ChannelWeight *)clientGame);
    idRibbonManager::Init(
      this: &this->ribbonManager,
      _ribbonDecl: this->declRibbon,
      _beamModel: NumContacts,
      _modelManager: p_ribbonModelManager);
    Physics = idEntity::GetPhysics(this);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v7 = Physics->GetOrigin(this: Physics, a2: 0);
    idRibbonManager::StartRibbon(this: &this->ribbonManager, spawnTime: GameMs, spawnOrg: v7);
    idEntity::BecomeActive(this, flags: 1);
  }
  else
  {
    this->Hide_2(this);
  }
}


// ========================================================================
// ??1idLensFlare@@UAA@XZ
// EA  : 0x82C6FAD8
// RVA : 0x00C6FAD8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idLensFlare::~idLensFlare(idLensFlare *this)
{
  this->__vftable = (idLensFlare_vtbl *)&idLensFlare::`vftable';
  idLensFlareManager::~idLensFlareManager(this: &this->flareManager);
  this->__vftable = (idLensFlare_vtbl *)&idDynamicEntity::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$496877
// EA  : 0x82C6FB38
// RVA : 0x00C6FB38
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_496877()
{
  int v0; // r12

  idDynamicEntity::~idDynamicEntity(this: *(idDynamicEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?Hide@idLensFlare@@UAAXXZ
// EA  : 0x82C6FB60
// RVA : 0x00C6FB60
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idLensFlare::Hide(idLensFlare *this)
{
  idDynamicEntity::Hide(this);
  idEntity::BecomeInactive(this, flags: 1);
  idLensFlareManager::StopFlare(this: &this->flareManager);
}


// ========================================================================
// ?Show@idLensFlare@@UAAXXZ
// EA  : 0x82C6FBA0
// RVA : 0x00C6FBA0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idLensFlare::Show(idLensFlare *this)
{
  idPhysics *Physics; // r30
  idPhysics *v3; // r29
  double fadeEnd; // fp31
  double fadeStart; // fp30
  const idMat3 *v6; // r30
  const idVec3 *v7; // r3
  idVec4 v8; // [sp+50h] [-40h] BYREF

  idDynamicEntity::Show(this);
  idEntity::BecomeActive(this, flags: 1);
  this->GetColor(this, a2: &v8);
  Physics = idEntity::GetPhysics(this);
  v3 = idEntity::GetPhysics(this);
  fadeEnd = this->fadeEnd;
  fadeStart = this->fadeStart;
  v6 = Physics->GetAxis(this: Physics, a2: 0);
  v7 = v3->GetOrigin(this: v3, a2: 0);
  idLensFlareManager::StartFlare(
    this: &this->flareManager,
    org: v7,
    axis: v6,
    color: &v8,
    fadeStartRange: fadeStart,
    fadeEndRange: fadeEnd);
}


// ========================================================================
// ??0idGodRays@@QAA@XZ
// EA  : 0x82C6FC60
// RVA : 0x00C6FC60
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idGodRays *__fastcall idGodRays::idGodRays(idGodRays *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idGodRays_vtbl *)&idGodRays::`vftable';
  this->isRelativeToCamera = true;
  this->direction.x = -512.0;
  this->direction.y = 264.0;
  this->direction.z = 536.0;
  this->sourceSize = 256;
  this->size = 1280;
  this->color.r = 1.0;
  this->color.g = 1.0;
  this->color.b = 1.0;
  this->color.a = 1.0;
  this->texture = nullptr;
  this->colorScale = 0.015;
  this->enabled = false;
  return this;
}


// ========================================================================
// ??1idGodRays@@UAA@XZ
// EA  : 0x82C6FD10
// RVA : 0x00C6FD10
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idGodRays::~idGodRays(idGodRays *this)
{
  int i; // r30
  idPlayer *Player; // r3
  idPresentable *presentable; // r3
  int v5; // r3

  this->__vftable = (idGodRays_vtbl *)&idGodRays::`vftable';
  for ( i = 0; i < 6; ++i )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i);
    if ( Player != nullptr )
    {
      presentable = Player->presentable;
      if ( presentable != nullptr )
        v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v5 = 0;
      *(_BYTE *)(v5 + 19476) = 0;
    }
  }
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$496937_0
// EA  : 0x82C6FD98
// RVA : 0x00C6FD98
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_496937_0()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// ?OnActivate@idGodRays@@UAAXPAVidEntity@@@Z
// EA  : 0x82C6FDC0
// RVA : 0x00C6FDC0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idGodRays::OnActivate(idGodRays *this, idEntity *activator)
{
  int v3; // r29
  idPlayer *Player; // r3
  idPlayer *v5; // r30
  idVec3 *p_direction; // r3
  idPhysics *Physics; // r3
  idPresentable *presentable; // r3
  double v9; // fp31
  double v10; // fp30
  double v11; // fp29
  int v12; // r3
  bool isRelativeToCamera; // r10
  const idMaterial *texture; // r9
  int sourceSize; // r8
  int size; // r7
  idPresentable *v17; // r3
  int v18; // r3
  float x; // [sp+50h] [-60h]
  float y; // [sp+54h] [-5Ch]
  float z; // [sp+58h] [-58h]

  v3 = 0;
  this->enabled = (_cntlzw(this->enabled) & 0x20) != 0;
  do
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i: v3);
    v5 = Player;
    if ( Player != nullptr )
    {
      if ( this->enabled )
      {
        if ( this->isRelativeToCamera )
        {
          p_direction = &this->direction;
        }
        else
        {
          Physics = idEntity::GetPhysics(this);
          p_direction = (idVec3 *)Physics->GetOrigin(this: Physics, a2: 0);
        }
        x = p_direction->x;
        y = p_direction->y;
        z = p_direction->z;
        presentable = v5->presentable;
        v9 = (float)((float)(this->color.r * this->color.a) * this->colorScale);
        v10 = (float)((float)(this->color.g * this->color.a) * this->colorScale);
        v11 = (float)((float)(this->color.b * this->color.a) * this->colorScale);
        if ( presentable != nullptr )
          v12 = (int)presentable->GetPlayerInterface_2(this: presentable);
        else
          v12 = 0;
        isRelativeToCamera = this->isRelativeToCamera;
        texture = this->texture;
        sourceSize = this->sourceSize;
        size = this->size;
        *(_BYTE *)(v12 + 19476) = 1;
        *(_BYTE *)(v12 + 19477) = isRelativeToCamera;
        *(_DWORD *)(v12 + 19512) = texture;
        *(float *)(v12 + 19500) = v9;
        *(float *)(v12 + 19504) = v10;
        *(float *)(v12 + 19508) = v11;
        *(float *)(v12 + 19480) = x;
        *(float *)(v12 + 19484) = y;
        *(float *)(v12 + 19488) = z;
        *(_DWORD *)(v12 + 19492) = size;
        *(_DWORD *)(v12 + 19496) = sourceSize;
      }
      else
      {
        v17 = Player->presentable;
        if ( v17 != nullptr )
          v18 = (int)v17->GetPlayerInterface_2(this: v17);
        else
          v18 = 0;
        *(_BYTE *)(v18 + 19476) = 0;
      }
    }
    ++v3;
  }
  while ( v3 < 6 );
}


// ========================================================================
// ?GetCurrentWindDirection@idFuncWind@@QBA?AVidVec3@@XZ
// EA  : 0x82C6FF50
// RVA : 0x00C6FF50
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idFuncWind *__fastcall idFuncWind::GetCurrentWindDirection(idFuncWind *this, idVec3 *result)
{
  idVec3 v4; // [sp+50h] [-20h] BYREF

  v4.y = result[70].y;
  v4.x = 0.0;
  v4.z = 0.0;
  idAngles::ToForward((idAngles *)this, result: &v4);
  return this;
}


// ========================================================================
// ??1idWindEmitter@@UAA@XZ
// EA  : 0x82C6FFA8
// RVA : 0x00C6FFA8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idWindEmitter::~idWindEmitter(idWindEmitter *this)
{
  idPresentable *presentable; // r4

  this->__vftable = (idWindEmitter_vtbl *)&idWindEmitter::`vftable';
  presentable = this->presentable;
  if ( presentable != nullptr )
    idInfluenceTrailManager::FreeInfluenceTrail(this: &clientGame->influenceTrailManager, presentable);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$497117
// EA  : 0x82C70018
// RVA : 0x00C70018
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_497117()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetNextGustOverlay@idWindEmitter@@ABAHXZ
// EA  : 0x82C70040
// RVA : 0x00C70040
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

int __fastcall idWindEmitter::GetNextGustOverlay(idWindEmitter *this)
{
  __int64 v2; // r11
  int result; // r3
  unsigned int v4; // r4
  double gustWeight; // fp13
  unsigned int v6; // r4

  HIDWORD(v2) = 1013904223;
  v4 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v4 + 1013904223;
  gustWeight = this->gustWeight;
  result = -1;
  LODWORD(v2) = ((v4 + 1013904223) >> 10) & 0x7FFF;
  if ( gustWeight < (float)((float)v2 * (float)0.000030518509) )
  {
    v6 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v6 + 1013904223;
    result = (((v6 + 1013904223) >> 10) & 0x7FFF)
           - 3 * ((unsigned __int64)(1431655766LL * (((v6 + 1013904223) >> 10) & 0x7FFF)) >> 32);
    if ( result == this->currGustOverlayIdx )
      return -1;
  }
  return result;
}


// ========================================================================
// ?GetCurrentWindDirection@idWindEmitter@@QBA?AVidVec3@@XZ
// EA  : 0x82C700F0
// RVA : 0x00C700F0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idWindEmitter *__fastcall idWindEmitter::GetCurrentWindDirection(idWindEmitter *this, idVec3 *result)
{
  idVec3 v4; // [sp+50h] [-20h] BYREF

  v4.y = result[71].y;
  v4.x = 0.0;
  v4.z = 0.0;
  idAngles::ToForward((idAngles *)this, result: &v4);
  return this;
}


// ========================================================================
// ?Spawn@idInventoryStorage@@QAAXXZ
// EA  : 0x82C70140
// RVA : 0x00C70140
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idInventoryStorage::Spawn(idInventoryStorage *this)
{
  int v2; // r27
  int v3; // r28
  idInventoryAttachmentDef *v4; // r30
  const idDeclJob *inventoryDecl; // r29
  idJobManager *v6; // r3
  idInventoryItem *JobByDecl; // r3
  idPresentable *presentable; // r29
  int count; // r26
  const idDeclInventory *v10; // r25
  idInventoryCollection *v11; // r3

  v2 = 0;
  if ( this->startingInventory.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->startingInventory.list[v3];
      inventoryDecl = (const idDeclJob *)v4->inventoryDecl;
      if ( inventoryDecl != nullptr )
      {
        v6 = (idJobManager *)this->GetInventory_2(this);
        JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v6, jobDecl: inventoryDecl);
        if ( JobByDecl == nullptr )
        {
          presentable = this->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
          }
          count = v4->count;
          v10 = v4->inventoryDecl;
          v11 = this->GetInventory_2(this);
          JobByDecl = idInventoryCollection::GiveItem(
                        this: v11,
                        owner: presentable,
                        decl: v10,
                        count,
                        forceCount: false,
                        canIntro: false);
        }
        JobByDecl->forSale = v4->forSale;
        JobByDecl->lootable = v4->lootable;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->startingInventory.num );
  }
}


// ========================================================================
// ?Spawn@idDebrisEntity@@QAAXXZ
// EA  : 0x82C70218
// RVA : 0x00C70218
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDebrisEntity::Spawn(idDebrisEntity *this)
{
  *((_BYTE *)&this->flags + 1) |= 4u;
}


// ========================================================================
// ?SetScale@idDebrisEntity@@UAAXABVidVec3@@@Z
// EA  : 0x82C70230
// RVA : 0x00C70230
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDebrisEntity::SetScale(idDebrisEntity *this, const idVec3 *scale)
{
  idPresentable *presentable; // r11
  float *model; // r10
  double v6; // fp31
  double v7; // fp30
  double v8; // fp29
  float *v9; // r11
  double v10; // fp9
  double v11; // fp7
  double v12; // fp6
  idPresentable *v13; // r11
  float *v14; // r11
  idClipModel *v15; // r3
  idClipModel *v16; // r30
  idPhysics *Physics; // r3
  idPhysics *v18; // r3
  idPhysics *v19; // r3
  idPhysics *v20; // r3
  idPhysics *v21; // r3
  float v22[6]; // [sp+58h] [-678h] BYREF
  idBounds v23; // [sp+70h] [-660h] BYREF
  idTraceModel v24; // [sp+90h] [-640h] BYREF

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  model = (float *)presentable->model;
  v6 = (float)(model[25] * scale->z);
  v7 = (float)(model[24] * scale->y);
  v8 = (float)(model[23] * scale->x);
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v9 = (float *)presentable->model;
  v10 = (float)(v9[26] * scale->x);
  v11 = (float)(v9[28] * scale->z);
  v12 = (float)(v9[27] * scale->y);
  v23.b[0].x = v8;
  v23.b[0].y = v7;
  v23.b[0].z = v6;
  v23.b[1].z = v11;
  v23.b[1].y = v12;
  v23.b[1].x = v10;
  idTraceModel::InitBox(this: &v24);
  idTraceModel::SetupBox(this: &v24, boxBounds: &v23);
  v13 = this->presentable;
  if ( v13 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v13 = this->presentable;
  }
  v14 = (float *)v13->model;
  v14[41] = scale->x;
  v14[42] = scale->y;
  v14[43] = scale->z;
  v15 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v15 != nullptr )
    v16 = idClipModel::idClipModel(this: v15, clip: &clientGame->clip, trm: &v24, numTraceModels: 1, material: nullptr);
  else
    v16 = nullptr;
  Physics = idEntity::GetPhysics(this);
  ((void (__fastcall *)(idPhysics *, idClipModel *, double))Physics->SetClipModel)(
    a1: Physics,
    a2: v16,
    a3: 0.0040000002);
  v18 = idEntity::GetPhysics(this);
  v18->SetContents(this: v18, a2: 0, a3: -1);
  v19 = idEntity::GetPhysics(this);
  v22[0] = 0.0;
  v22[1] = 0.0;
  v22[2] = -100.0;
  v19->SetGravity(this: v19, a2: (const idVec3 *)v22);
  v20 = idEntity::GetPhysics(this);
  v20->SetClipMask(this: v20, a2: 1, a3: -1);
  v21 = idEntity::GetPhysics(this);
  v21->PutToRest(this: v21);
}


// ========================================================================
// __unwind$497222
// EA  : 0x82C70460
// RVA : 0x00C70460
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_497222()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1744 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ??0idReferenceMap@@QAA@XZ
// EA  : 0x82C70490
// RVA : 0x00C70490
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idReferenceMap *__fastcall idReferenceMap::idReferenceMap(idReferenceMap *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idReferenceMap_vtbl *)&idReferenceMap::`vftable';
  this->mapname.len = 0;
  this->mapname.allocedAndFlag = 20;
  this->mapname.data = this->mapname.baseBuffer;
  this->mapname.baseBuffer[0] = 0;
  this->zeroTransform = false;
  return this;
}


// ========================================================================
// ?Activate@idAnnouncementManager@@AAAXXZ
// EA  : 0x82C705D8
// RVA : 0x00C705D8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idAnnouncementManager::Activate(idAnnouncementManager *this)
{
  __int64 v2; // r5
  unsigned int v3; // r9
  double v4; // fp31

  this->active = true;
  this->playedFirst = false;
  HIDWORD(v2) = 1;
  v3 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v3 + 1013904223;
  LODWORD(v2) = ((v3 + 1013904223) >> 10) & 0x7FFF;
  v4 = (float)((float)((float)((float)((float)v2 * (float)0.000061037019) - (float)1.0) * this->startDelayVariance)
             + this->startDelay);
  this->nextPlayTime = ((int (*)(void))gameLocal->GetGameMs)() - (int)(float)((float)v4 * (float)-1000.0);
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?UpdateGuiModel@idGuiEntity@@AAAXXZ
// EA  : 0x82C706C0
// RVA : 0x00C706C0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idGuiEntity::UpdateGuiModel(idGuiEntity *this)
{
  idRenderModel *RenderModelFromPresentable; // r3
  idRenderModel *v3; // r30
  int v4; // r9
  int v5; // r8
  int v6; // r7
  __int64 v7; // r6
  int v8; // r7
  unsigned __int64 v9; // r6
  idSWF *v10; // r29
  idSWF *guiSwf; // r30
  int GameMs; // r3
  const char *v13; // r7
  __int64 v14; // [sp+8h] [-78h]

  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
  v3 = RenderModelFromPresentable;
  if ( RenderModelFromPresentable != nullptr && idRenderModel::IsRendered(this: RenderModelFromPresentable) )
  {
    v3->g.referenceModel = this->guiModel;
    HIDWORD(v7) = (int)this->guiSwf->frameHeight;
    idRenderModelGui::SetVirtualSize(this: this->guiModel, height: v7, a3: v6, a4: v5, a5: v4, a6: v14);
    idRenderModelGui::Clear(
      this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
      a2: defaultExtraGLState,
      bits: v9,
      a4: v8);
    if ( gameLocal->IsGameActive(this: gameLocal) )
    {
      if ( !gameLocal->GetGamePaused(this: gameLocal) || (v10 = this->guiSwf)->paused )
      {
        if ( !gameLocal->GetGamePaused(this: gameLocal) )
        {
          guiSwf = this->guiSwf;
          if ( guiSwf->paused )
          {
            idSWFSpriteInstance::Play(this: guiSwf->mainspriteInstance);
            guiSwf->paused = false;
          }
        }
      }
      else
      {
        idSWFSpriteInstance::Stop(this: v10->mainspriteInstance);
        v10->paused = true;
      }
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idSWF::Render(this: this->guiSwf, gui: this->guiModel, time: GameMs, isSplitscreen: false, a5: v13);
    }
    idRenderModel::CommitThisFrame(this: this->guiModel);
  }
}


// ========================================================================
// ?PauseThink@idGuiEntity@@UAAXXZ
// EA  : 0x82C70818
// RVA : 0x00C70818
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idGuiEntity::PauseThink(idGuiEntity *this)
{
  if ( this->guiSwf->atlasImage->d3dTexture != nullptr )
    idGuiEntity::UpdateGuiModel(this);
}


// ========================================================================
// ?IsGuiActive@idGuiEntity@@QBA_NXZ
// EA  : 0x82C70838
// RVA : 0x00C70838
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

BOOL __fastcall idGuiEntity::IsGuiActive(idGuiEntity *this)
{
  idSWF *guiSwf; // r11

  guiSwf = this->guiSwf;
  return guiSwf != nullptr && guiSwf->isActive;
}


// ========================================================================
// ?Event_ResetGuiEntity@idGuiEntity@@QAA?AVeventVoid@@XZ
// EA  : 0x82C70858
// RVA : 0x00C70858
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idGuiEntity *__fastcall idGuiEntity::Event_ResetGuiEntity(idGuiEntity *this, eventVoid *result)
{
  idSWF *v3; // r3
  int v5; // r10

  v3 = *(idSWF **)&result[900];
  if ( v3 != nullptr )
  {
    idSWF::Activate(this: v3, b: false);
    idSWF::Activate(this: *(idSWF **)&result[900], b: true);
    v5 = *(_DWORD *)&result[884];
    *(_DWORD *)&result[888] = -1;
    *(_DWORD *)&result[892] = v5;
  }
  return this;
}


// ========================================================================
// ?Event_MoveToState@idGuiEntity@@QAA?AVeventVoid@@W4idGuiEntityInitialState@1@@Z
// EA  : 0x82C708C0
// RVA : 0x00C708C0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idGuiEntity::Event_MoveToState@<r4>(
        idGuiEntity *this@<r3>,
        int result@<r4>,
        idGuiEntity::idGuiEntityInitialState state@<r5>)
{
  if ( *(_DWORD *)(result + 888) != 1 )
    *(_DWORD *)(result + 892) = state;
  return result;
}


// ========================================================================
// ?Event_EnableInteract@idGuiEntity@@QAA?AVeventVoid@@_N@Z
// EA  : 0x82C708D8
// RVA : 0x00C708D8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idGuiEntity::Event_EnableInteract@<r4>(idGuiEntity *this@<r3>, int result@<r4>, bool enable@<r5>)
{
  int v3; // r11

  v3 = 3;
  if ( enable )
    v3 = 0;
  *(_DWORD *)(result + 892) = v3;
  return result;
}


// ========================================================================
// ?ModifyCrosshairInfo@idGuiEntity@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C708F8
// RVA : 0x00C708F8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

int __fastcall idGuiEntity::ModifyCrosshairInfo(
        idGuiEntity *this,
        const idEntity *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  crosshairColorState_t v5; // r9
  crosshairTextColorState_t v6; // r8
  crosshairMaterial_t v7; // r6
  idColor v9; // 0:^50.16
  idColor v10; // 0:^60.16

  v5 = CROSSHAIR_COLOR_NORMAL;
  v6 = CROSSHAIR_TEXT_COLOR_NORMAL;
  v7 = CHMATERIAL_DOOR;
  v9 = idCrosshairInfo::DEFAULT_COLOR;
  v10 = idCrosshairInfo::DEFAULT_TEXT_COLOR;
  if ( this->used )
  {
    v5 = CROSSHAIR_COLOR_NEGATIVE;
    v6 = CROSSHAIR_TEXT_COLOR_NEGATIVE;
    v7 = CHMATERIAL_PROP;
    v9 = idCrosshairInfo::DEFAULT_COLOR;
    v10 = idCrosshairInfo::DEFAULT_TEXT_COLOR;
  }
  info->colorState = v5;
  info->textColorState = v6;
  info->material = v7;
  info->color = v9;
  info->textColor = v10;
  idStrId::Set(this: &info->text, key: &byte_8200D768);
  return 1;
}


// ========================================================================
// ??0idInformationEntity@@QAA@XZ
// EA  : 0x82C70AA8
// RVA : 0x00C70AA8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idInformationEntity *__fastcall idInformationEntity::idInformationEntity(idInformationEntity *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idInformationEntity_vtbl *)&idInformationEntity::`vftable';
  this->message.index = -1;
  this->customIcon = nullptr;
  this->clipModelInfo.type = CLIPMODEL_RENDERMODEL;
  return this;
}


// ========================================================================
// ?ModifyCrosshairInfo@idInformationEntity@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C70B68
// RVA : 0x00C70B68
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

int __fastcall idInformationEntity::ModifyCrosshairInfo(
        idInformationEntity *this,
        const idEntity *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  unsigned int v5; // r11
  crosshairColorState_t v6; // r11
  crosshairTextColorState_t v7; // r10
  crosshairMaterial_t v8; // r9
  const idMaterial *customIcon; // r11
  int result; // r3

  v5 = _S18_14;
  if ( (_S18_14 & 1) == 0 )
  {
    v5 = _S18_14 | 1;
    _S18_14 |= 1u;
    color = idCrosshairInfo::DEFAULT_COLOR;
  }
  if ( (v5 & 2) == 0 )
  {
    _S18_14 = v5 | 2;
    textColor = idCrosshairInfo::DEFAULT_TEXT_COLOR;
  }
  info->color.r = color.r;
  v6 = colorState;
  v7 = textColorState;
  info->color.g = color.g;
  v8 = material;
  info->color.b = color.b;
  info->color.a = color.a;
  info->colorState = v6;
  info->textColor = textColor;
  info->textColorState = v7;
  info->material = v8;
  info->text.index = this->message.index;
  customIcon = this->customIcon;
  result = 0;
  if ( customIcon != nullptr )
  {
    info->icons.list->material = customIcon;
    info->material = CHMATERIAL_CUSTOM;
  }
  return result;
}


// ========================================================================
// ?Spawn@idStaticEntity@@QAAXXZ
// EA  : 0x82C71058
// RVA : 0x00C71058
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idStaticEntity::Spawn(idStaticEntity *this)
{
  idPresentable *presentable; // r11
  char v3; // r11
  bool v4; // zf
  idPhysics *Physics; // r3
  idPresentable *v6; // r11
  char v7; // r10
  idPhysics *v8; // r3

  presentable = this->presentable;
  if ( presentable == nullptr || (v4 = presentable->model != nullptr, v3 = 1, !v4) )
    v3 = 0;
  if ( v3 == 0 )
  {
    Physics = idEntity::GetPhysics(this);
    Physics->GetClipModel(this: Physics, a2: 0);
  }
  v6 = this->presentable;
  if ( v6 == nullptr || (v7 = 1, v6->model == nullptr) )
    v7 = 0;
  if ( v7 != 0 )
  {
    if ( v6 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v6 = this->presentable;
    }
    *((_BYTE *)&v6->model->g + 104) |= 0x20u;
  }
  v8 = idEntity::GetPhysics(this);
  v8->SetContents(this: v8, a2: 1, a3: -1);
}


// ========================================================================
// ??0idDynamicEntity@@QAA@XZ
// EA  : 0x82C71140
// RVA : 0x00C71140
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idDynamicEntity *__fastcall idDynamicEntity::idDynamicEntity(idDynamicEntity *this)
{
  float z; // r7
  float w; // r6
  char flags; // r11

  idEntity::idEntity(this);
  this->hide = false;
  this->castsDimShadows = false;
  this->__vftable = (idDynamicEntity_vtbl *)&idDynamicEntity::`vftable';
  this->solid = true;
  this->megaModelSpawnPosition.x = vec3_origin.x;
  this->megaModelSpawnPosition.y = vec3_origin.y;
  z = vec3_origin.z;
  this->colorModulateTimeScale = 1.0;
  this->highlightColor = HIGHLIGHT_COLOR_NONE;
  this->colorModulateTable = nullptr;
  this->colorModulateActive = false;
  this->spawnTime = 0;
  this->active = false;
  this->runGui = false;
  this->megaModelSpawnPosition.z = z;
  this->fade.fadeFrom = 0.0;
  this->fade.fadeTo = 0.0;
  this->fade.fadeStartTime = 0;
  this->fade.fadeEndTime = 0;
  this->fade.noStippleFade = false;
  this->colorPreModulate.x = vec4_origin.x;
  this->colorPreModulate.y = vec4_origin.y;
  this->colorPreModulate.z = vec4_origin.z;
  w = vec4_origin.w;
  flags = (char)this->flags;
  this->clipModelInfo.type = CLIPMODEL_RENDERMODEL;
  *(_BYTE *)&this->flags = flags | 4;
  this->colorPreModulate.w = w;
  idEntity::SetClipReplicationFlags(this, dynamicClipReplication: true, dynamicClipReplicationAxis: true);
  return this;
}


// ========================================================================
// __unwind$498833
// EA  : 0x82C71250
// RVA : 0x00C71250
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_498833()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?Spawn@idDynamicEntity@@QAAXXZ
// EA  : 0x82C71278
// RVA : 0x00C71278
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDynamicEntity::Spawn(idDynamicEntity *this)
{
  idPhysics *v2; // r3
  int v3; // r10
  int v4; // r9
  int v5; // r8
  int v6; // r7
  int v7; // r6
  int v8; // r5
  idPresentable *v9; // r11
  idPhysics *Physics; // r3
  int v11; // r10
  int v12; // r9
  int v13; // r8
  int v14; // r7
  int v15; // r6
  int v16; // r5
  idPresentable *presentable; // r3
  idPresentable *v18; // r11
  char v19; // r10
  idPresentable *v20; // r11
  highlightColor_t highlightColor; // r10
  idRenderModel *model; // r9
  char v23; // r11

  if ( !this->solid || this->hide )
  {
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 0, a3: -1);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::SetClipModelContents(
      this: presentable,
      newContents: 0,
      a3: v16,
      a4: v15,
      a5: v14,
      a6: v13,
      a7: v12,
      a8: v11);
    if ( this->hide )
      this->Hide_2(this);
  }
  else
  {
    v2 = idEntity::GetPhysics(this);
    v2->SetContents(this: v2, a2: 1, a3: -1);
    v9 = this->presentable;
    if ( v9 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v9 = this->presentable;
    }
    idPresentable::SetClipModelContents(this: v9, newContents: 1, a3: v8, a4: v7, a5: v6, a6: v5, a7: v4, a8: v3);
  }
  v18 = this->presentable;
  if ( v18 == nullptr || (v19 = 1, v18->model == nullptr) )
    v19 = 0;
  if ( v19 != 0 )
  {
    if ( this->castsDimShadows )
    {
      if ( v18 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v18 = this->presentable;
      }
      v18->model->g.castDimShadows = DIMSHADOW_ON;
    }
    v20 = this->presentable;
    if ( v20 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v20 = this->presentable;
    }
    highlightColor = this->highlightColor;
    model = v20->model;
    v20->highlightColor = highlightColor;
    model->g.highlightColor = highlightColor;
  }
  if ( (gameLocal->GetGameFlags(this: gameLocal) & 2) == 0 && idEntity::IsMegaModel(this) )
  {
    if ( this->megaModelSpawnPosition.x != vec3_origin.x
      || this->megaModelSpawnPosition.y != vec3_origin.y
      || (v23 = 1, this->megaModelSpawnPosition.z != vec3_origin.z) )
    {
      v23 = 0;
    }
    if ( v23 == 0 )
      idEntity::SetOrigin(this, org: &this->megaModelSpawnPosition);
  }
  this->spawnTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->active = false;
  this->fade.fadeStartTime = 0;
  this->fade.fadeEndTime = 0;
  this->fade.noStippleFade = false;
  this->fade.fadeFrom = 0.0;
  this->fade.fadeTo = 0.0;
  if ( this->colorModulateTable != nullptr && this->colorModulateActive )
    idEntity::BecomeActive(this, flags: 1);
  this->GetColor(this, a2: &this->colorPreModulate);
}


// ========================================================================
// ?SetColor@idDynamicEntity@@UAAXMMMM@Z
// EA  : 0x82C714F0
// RVA : 0x00C714F0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDynamicEntity::SetColor(
        idDynamicEntity *this,
        double red,
        double green,
        double blue,
        double alpha,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12)
{
  idPresentable *presentable; // r3
  char v14; // r11
  idPresentable *v15; // r11
  __int64 v16; // [sp+8h] [-58h]
  __int64 v17; // [sp+10h] [-50h]
  __int64 v18; // [sp+18h] [-48h]
  __int64 v19; // [sp+20h] [-40h]
  __int64 v20; // [sp+28h] [-38h]

  this->colorPreModulate.x = red;
  this->colorPreModulate.y = green;
  this->colorPreModulate.z = blue;
  this->colorPreModulate.w = alpha;
  presentable = this->presentable;
  if ( presentable == nullptr || (v14 = 1, presentable->model == nullptr) )
    v14 = 0;
  if ( v14 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::SetParm(
      this: presentable,
      parm: rp->Color,
      v4: *(_QWORD *)&this->colorPreModulate.z,
      a4: a9,
      a5: a10,
      a6: a11,
      a7: a12,
      a8: v16,
      a9: v17,
      a10: v18,
      a11: v19,
      a12: v20);
    v15 = this->presentable;
    if ( v15 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v15 = this->presentable;
    }
    v15->Present(this: v15);
  }
}


// ========================================================================
// ?SetColor@idDynamicEntity@@UAAXMMM@Z
// EA  : 0x82C715B0
// RVA : 0x00C715B0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDynamicEntity::SetColor(
        idDynamicEntity *this,
        double red,
        double green,
        double blue,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  idPresentable *presentable; // r3
  char v13; // r11
  idPresentable *v14; // r11
  __int64 v15; // [sp+8h] [-58h]
  __int64 v16; // [sp+10h] [-50h]
  __int64 v17; // [sp+18h] [-48h]
  __int64 v18; // [sp+20h] [-40h]
  __int64 v19; // [sp+28h] [-38h]

  this->colorPreModulate.x = red;
  this->colorPreModulate.y = green;
  this->colorPreModulate.z = blue;
  this->colorPreModulate.w = 1.0;
  presentable = this->presentable;
  if ( presentable == nullptr || (v13 = 1, presentable->model == nullptr) )
    v13 = 0;
  if ( v13 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::SetParm(
      this: presentable,
      parm: rp->Color,
      v4: *(_QWORD *)&this->colorPreModulate.z,
      a4: a8,
      a5: a9,
      a6: a10,
      a7: a11,
      a8: v15,
      a9: v16,
      a10: v17,
      a11: v18,
      a12: v19);
    v14 = this->presentable;
    if ( v14 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v14 = this->presentable;
    }
    v14->Present(this: v14);
  }
}


// ========================================================================
// ?SetColor@idDynamicEntity@@UAAXABVidVec3@@@Z
// EA  : 0x82C71678
// RVA : 0x00C71678
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDynamicEntity::SetColor(
        idDynamicEntity *this,
        const idVec3 *color,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  double z; // fp13
  double y; // fp12
  idPresentable *presentable; // r3
  char v12; // r11
  idPresentable *v13; // r11
  __int64 v14; // [sp+8h] [-58h]
  __int64 v15; // [sp+10h] [-50h]
  __int64 v16; // [sp+18h] [-48h]
  __int64 v17; // [sp+20h] [-40h]
  __int64 v18; // [sp+28h] [-38h]

  z = color->z;
  y = color->y;
  this->colorPreModulate.x = color->x;
  this->colorPreModulate.y = y;
  this->colorPreModulate.z = z;
  this->colorPreModulate.w = 1.0;
  presentable = this->presentable;
  if ( presentable == nullptr || (v12 = 1, presentable->model == nullptr) )
    v12 = 0;
  if ( v12 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::SetParm(
      this: presentable,
      parm: rp->Color,
      v4: *(_QWORD *)&this->colorPreModulate.z,
      a4: a5,
      a5: a6,
      a6: a7,
      a7: a8,
      a8: v14,
      a9: v15,
      a10: v16,
      a11: v17,
      a12: v18);
    v13 = this->presentable;
    if ( v13 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v13 = this->presentable;
    }
    v13->Present(this: v13);
  }
}


// ========================================================================
// ?SetColor@idDynamicEntity@@UAAXABVidVec4@@@Z
// EA  : 0x82C71748
// RVA : 0x00C71748
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDynamicEntity::SetColor(
        idDynamicEntity *this,
        const idVec4 *color,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idPresentable *presentable; // r3
  char v10; // r11
  idPresentable *v11; // r11
  __int64 v12; // [sp+8h] [-58h]
  __int64 v13; // [sp+10h] [-50h]
  __int64 v14; // [sp+18h] [-48h]
  __int64 v15; // [sp+20h] [-40h]
  __int64 v16; // [sp+28h] [-38h]

  this->colorPreModulate = *color;
  presentable = this->presentable;
  if ( presentable == nullptr || (v10 = 1, presentable->model == nullptr) )
    v10 = 0;
  if ( v10 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::SetParm(
      this: presentable,
      parm: rp->Color,
      v4: *(_QWORD *)&this->colorPreModulate.z,
      a4: a5,
      a5: a6,
      a6: a7,
      a7: a8,
      a8: v12,
      a9: v13,
      a10: v14,
      a11: v15,
      a12: v16);
    v11 = this->presentable;
    if ( v11 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v11 = this->presentable;
    }
    v11->Present(this: v11);
  }
}


// ========================================================================
// ?SetColor@idDynamicEntity@@UAAXABVidColor@@@Z
// EA  : 0x82C71818
// RVA : 0x00C71818
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDynamicEntity::SetColor(
        idDynamicEntity *this,
        const idColor *color,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  double g; // fp13
  double b; // fp12
  double a; // fp11
  idPresentable *presentable; // r3
  char v13; // r11
  idPresentable *v14; // r11
  __int64 v15; // [sp+8h] [-58h]
  __int64 v16; // [sp+10h] [-50h]
  __int64 v17; // [sp+18h] [-48h]
  __int64 v18; // [sp+20h] [-40h]
  __int64 v19; // [sp+28h] [-38h]

  g = color->g;
  b = color->b;
  a = color->a;
  this->colorPreModulate.x = color->r;
  this->colorPreModulate.y = g;
  this->colorPreModulate.z = b;
  this->colorPreModulate.w = a;
  presentable = this->presentable;
  if ( presentable == nullptr || (v13 = 1, presentable->model == nullptr) )
    v13 = 0;
  if ( v13 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::SetParm(
      this: presentable,
      parm: rp->Color,
      v4: *(_QWORD *)&this->colorPreModulate.z,
      a4: a5,
      a5: a6,
      a6: a7,
      a7: a8,
      a8: v15,
      a9: v16,
      a10: v17,
      a11: v18,
      a12: v19);
    v14 = this->presentable;
    if ( v14 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v14 = this->presentable;
    }
    v14->Present(this: v14);
  }
}


// ========================================================================
// ?GetColor@idMover@@UBAXAAVidVec3@@@Z
// EA  : 0x82C718E8
// RVA : 0x00C718E8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idMover::GetColor(idDynamicEntity *this, idVec3 *out)
{
  idPresentable *presentable; // r3
  char v5; // r11
  idStaticParmBlock<32> *ParmBlock; // r3
  float *Vector; // r3
  idParmBlock v8; // [sp+50h] [-30h] BYREF

  presentable = this->presentable;
  if ( presentable == nullptr || (v5 = 1, presentable->model == nullptr) )
    v5 = 0;
  if ( v5 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    ParmBlock = idPresentable::GetParmBlock(this: presentable);
    Vector = (float *)idParmBlock::GetVector(this: &v8, result: ParmBlock, parm: rp->Color);
    out->x = *Vector;
    out->y = Vector[1];
    out->z = Vector[2];
  }
  else
  {
    idEntity::GetColor(this, out);
  }
}


// ========================================================================
// ?GetColor@idDynamicEntity@@UBAXAAVidColor@@@Z
// EA  : 0x82C719A0
// RVA : 0x00C719A0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDynamicEntity::GetColor(idDynamicEntity *this, idColor *color)
{
  idPresentable *presentable; // r3
  char v5; // r11
  idStaticParmBlock<32> *ParmBlock; // r3
  double v7; // fp13
  double v8; // fp12
  double v9; // fp11
  idParmBlock v10; // [sp+50h] [-30h] BYREF

  presentable = this->presentable;
  if ( presentable == nullptr || (v5 = 1, presentable->model == nullptr) )
    v5 = 0;
  if ( v5 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    ParmBlock = idPresentable::GetParmBlock(this: presentable);
    idParmBlock::GetVector(this: &v10, result: ParmBlock, parm: rp->Color);
    v7 = *(float *)&v10.ops.num;
    v8 = *(float *)&v10.ops.size;
    v9 = *(float *)&v10.ops.granularity;
    color->r = *(float *)&v10.ops.list;
    color->g = v7;
    color->b = v8;
    color->a = v9;
  }
  else
  {
    idEntity::GetColor(this, out: color);
  }
}


// ========================================================================
// ?GetColor@idMover@@UBAXAAVidVec4@@@Z
// EA  : 0x82C71A60
// RVA : 0x00C71A60
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idMover::GetColor(idDynamicEntity *this, idVec4 *out)
{
  idPresentable *presentable; // r3
  char v5; // r11
  idStaticParmBlock<32> *ParmBlock; // r3
  idParmBlock v7; // [sp+50h] [-30h] BYREF

  presentable = this->presentable;
  if ( presentable == nullptr || (v5 = 1, presentable->model == nullptr) )
    v5 = 0;
  if ( v5 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    ParmBlock = idPresentable::GetParmBlock(this: presentable);
    *out = (idVec4)idParmBlock::GetVector(this: &v7, result: ParmBlock, parm: rp->Color)->ops;
  }
  else
  {
    idEntity::GetColor(this, out);
  }
}


// ========================================================================
// ??0idParticleEmitter@@QAA@XZ
// EA  : 0x82C71B20
// RVA : 0x00C71B20
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idParticleEmitter *__fastcall idParticleEmitter::idParticleEmitter(idParticleEmitter *this)
{
  idDynamicEntity::idDynamicEntity(this);
  this->__vftable = (idParticleEmitter_vtbl *)&idParticleEmitter::`vftable';
  this->fadeIn = 0.5;
  this->hidden = false;
  this->fadeOut = 0.5;
  this->startOff = false;
  this->alphaScale = 1.0;
  this->cycleTrigger = false;
  this->useGlobalShadows = false;
  this->useSmokeSystem = false;
  this->startDelay = 0;
  this->distributionScale.x = 1.0;
  this->distributionScale.y = 1.0;
  this->distributionScale.z = 1.0;
  this->smokeSystemRate = 1;
  this->masterVelocityScale = 1.0;
  this->inheritMasterVelocity = false;
  this->particleSystem = nullptr;
  this->clipModelInfo.type = CLIPMODEL_NONE;
  return this;
}


// ========================================================================
// ?Show@idParticleEmitter@@UAAXXZ
// EA  : 0x82C71C18
// RVA : 0x00C71C18
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idParticleEmitter::Show(idParticleEmitter *this)
{
  idDynamicEntity::Show(this);
  idEntity::BecomeActive(this, flags: 1);
  this->hidden = false;
  idParticleEmitter::UpdatePresentable(this);
}


// ========================================================================
// ?SetScale@idParticleEmitter@@UAAXABVidVec3@@@Z
// EA  : 0x82C71C60
// RVA : 0x00C71C60
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idParticleEmitter::SetScale(
        idParticleEmitter *this,
        const idVec3 *scale,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  idPresentable *presentable; // r3
  char v9; // r11
  idCodeResource<idDeclRenderParm> *v10; // r10
  __int128 v11; // r6
  __int64 v12; // [sp+8h] [-68h]
  __int64 v13; // [sp+10h] [-60h]
  __int64 v14; // [sp+18h] [-58h]
  __int64 v15; // [sp+20h] [-50h]
  __int64 v16; // [sp+28h] [-48h]

  this->distributionScale = *scale;
  presentable = this->presentable;
  if ( presentable == nullptr || (v9 = 1, presentable->model == nullptr) )
    v9 = 0;
  if ( v9 != 0 )
  {
    v10 = &rpParticleScale_1;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    *(_QWORD *)((char *)&v11 + 4) = *(_QWORD *)&this->distributionScale.x;
    LODWORD(v11) = __ROL4__(LODWORD(this->distributionScale.z), 32);
    idPresentable::SetParm(
      this: presentable,
      parm: (const idDeclRenderParm *)LODWORD(this->distributionScale.x),
      v3: v11,
      a4: a5,
      a5: a6,
      a6: a7,
      a7: (int)v10,
      a8: v12,
      a9: v13,
      a10: v14,
      a11: v15,
      a12: v16);
  }
}


// ========================================================================
// ?SetParticle@idParticleEmitter@@AAAXPBVidDeclParticle@@@Z
// EA  : 0x82C71D10
// RVA : 0x00C71D10
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idParticleEmitter::SetParticle(idParticleEmitter *this, const idDeclParticle *particleDecl)
{
  bool v4; // r29
  idPresentable *presentable; // r11
  idRenderModel *model; // r10
  int v7; // r10
  int v8; // r9
  int v9; // r8
  int v10; // r7
  idPresentable *v11; // r3
  idPresentable *v12; // r28
  idParmBlock *Vector; // r3
  int v14; // r10
  int v15; // r8
  int v16; // r7
  __int64 v17; // r9
  unsigned int v18; // r3
  idPresentable *v19; // r11
  double v20; // fp31
  double v21; // fp31
  int GameMs; // r3
  idPresentable *v23; // r11
  double v24; // fp30
  idPresentable *v25; // r3
  int v26; // r8
  int v27; // r7
  idPresentable *v28; // r11
  idCodeResource<idDeclRenderParm> *v29; // r9
  int z_low; // r10
  __int128 v31; // r6
  int v32; // r7
  idPresentable *v33; // r11
  idPresentable *v34; // r11
  const idDeclRenderParm *r; // r29
  idPresentable *v36; // r11
  double z; // fp0
  double y; // fp13
  double x; // fp12
  double v40; // fp31
  double v41; // fp30
  double v42; // fp29
  double v43; // fp28
  double v44; // fp27
  double v45; // fp26
  idRenderModel *v46; // r11
  idPresentable *v47; // r3
  __int64 v48; // [sp+8h] [-E8h]
  __int64 v49; // [sp+8h] [-E8h]
  __int64 v50; // [sp+8h] [-E8h]
  __int64 v51; // [sp+8h] [-E8h]
  __int64 v52; // [sp+10h] [-E0h]
  __int64 v53; // [sp+10h] [-E0h]
  __int64 v54; // [sp+10h] [-E0h]
  __int64 v55; // [sp+10h] [-E0h]
  __int64 v56; // [sp+18h] [-D8h]
  __int64 v57; // [sp+18h] [-D8h]
  __int64 v58; // [sp+18h] [-D8h]
  __int64 v59; // [sp+18h] [-D8h]
  __int64 v60; // [sp+20h] [-D0h]
  __int64 v61; // [sp+20h] [-D0h]
  __int64 v62; // [sp+20h] [-D0h]
  __int64 v63; // [sp+20h] [-D0h]
  __int64 v64; // [sp+28h] [-C8h]
  __int64 v65; // [sp+28h] [-C8h]
  __int64 v66; // [sp+28h] [-C8h]
  __int64 v67; // [sp+28h] [-C8h]
  idParmBlock v68; // [sp+50h] [-A0h] BYREF
  int v69; // [sp+78h] [-78h]
  char v70; // [sp+7Ch] [-74h] BYREF

  if ( particleDecl != nullptr )
  {
    if ( particleDecl->resourceError != nullptr )
      idLib::Warning(fmt: "Particle decl error: '%s' - using default.", particleDecl->name.str);
    v4 = false;
    v68.thread = THREAD_INVALID;
    v69 = 20;
    *(_DWORD *)&v68.usingTempOps = &v70;
    v70 = 0;
    idRenderModelParticle::DeclNameToModelName(declName: particleDecl->name.str, modelName: (idStr *)&v68.thread);
    idEntity::SetModelByName(this, modelname: *(const char **)&v68.usingTempOps);
    idEntity::SetNoShadows(this, set: true);
    idEntity::InitRenderModel(this);
    presentable = this->presentable;
    if ( presentable != nullptr )
    {
      model = presentable->model;
      v68.ops.list = (expOp_t *)this->presentable;
      v4 = model != nullptr;
    }
    if ( v4 )
    {
      this->GetColor(this, a2: (idVec4 *)&v68.constants);
      v11 = this->presentable;
      if ( v11 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v11 = this->presentable;
      }
      idPresentable::SetParm(
        this: v11,
        parm: rp->Color,
        v4: *(__int64 *)&v68.constants.size,
        a4: v10,
        a5: v9,
        a6: v8,
        a7: v7,
        a8: v48,
        a9: v52,
        a10: v56,
        a11: v60,
        a12: v64);
      v12 = this->presentable;
      if ( v12 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v12 = this->presentable;
      }
      Vector = idParmBlock::GetVector(this: &v68, result: &gameLocal->renderParmBlock, parm: rp->Wind);
      idPresentable::SetParm(
        this: v12,
        parm: (const idDeclRenderParm *)Vector->ops.list,
        v4: *(_QWORD *)&Vector->ops.size,
        a4: v16,
        a5: v15,
        a6: (int)Vector,
        a7: v14,
        a8: v49,
        a9: v53,
        a10: v57,
        a11: v61,
        a12: v65);
      HIDWORD(v17) = 1638400;
      v18 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v18;
      LODWORD(v17) = (v18 >> 10) & 0x7FFF;
      v19 = this->presentable;
      *(_QWORD *)&v68.ops.list = v17;
      v20 = (float)((float)v17 * (float)0.000030518509);
      if ( v19 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v19 = this->presentable;
      }
      idPresentable::SetParm(this: v19, parm: rp->Diversity, scalar: v20);
      if ( this->presentable == nullptr )
        idEntity::InitPresentableInternal(this);
      v21 = 0.0;
      idPresentable::SetParm(this: this->presentable, parm: rp->TimeStop, scalar: 0.0);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v23 = this->presentable;
      *(_QWORD *)&v68.ops.list = __PAIR64__(&unk_82390000, GameMs);
      v24 = (float)((float)__SPAIR64__(&unk_82390000, GameMs) * (float)0.001);
      if ( v23 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v23 = this->presentable;
      }
      idPresentable::SetParm(this: v23, parm: rp->TimeOffset, scalar: v24);
      if ( !this->useGlobalShadows )
        v21 = 1.0;
      v25 = this->presentable;
      if ( v25 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v25 = this->presentable;
      }
      idPresentable::SetParm(this: v25, parm: rp->NoShadows, scalar: v21);
      v28 = this->presentable;
      v29 = &rpParticleScale_1;
      if ( v28 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v28 = this->presentable;
      }
      z_low = LODWORD(this->distributionScale.z);
      *(_QWORD *)((char *)&v31 + 4) = *(_QWORD *)&this->distributionScale.x;
      LODWORD(v31) = __ROL4__(z_low, 32);
      idPresentable::SetParm(
        this: v28,
        parm: (const idDeclRenderParm *)LODWORD(this->distributionScale.x),
        v3: v31,
        a4: v27,
        a5: v26,
        a6: (int)v29,
        a7: z_low,
        a8: v50,
        a9: v54,
        a10: v58,
        a11: v62,
        a12: v66);
      v33 = this->presentable;
      if ( v33 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v33 = this->presentable;
      }
      idPresentable::SetParm(
        this: v33,
        parm: (const idDeclRenderParm *)LODWORD(vec3_origin.x),
        v3: __SPAIR64__(LODWORD(vec3_origin.y), __ROL4__(LODWORD(vec3_origin.z), 32)),
        a4: v32,
        a5: SLODWORD(vec3_origin.z),
        a6: (int)&vec3_origin,
        a7: (int)allocationCurrent[242],
        a8: v51,
        a9: v55,
        a10: v59,
        a11: v63,
        a12: v67);
      v34 = this->presentable;
      r = (const idDeclRenderParm *)rpParticleAlphaScale_1.r;
      if ( v34 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v34 = this->presentable;
      }
      idPresentable::SetParm(this: v34, parm: r, scalar: (float)((float)1.0 / this->alphaScale));
      if ( this->distributionScale.x > 1.0 || this->distributionScale.y > 1.0 || this->distributionScale.z > 1.0 )
      {
        v36 = this->presentable;
        z = this->distributionScale.z;
        y = this->distributionScale.y;
        x = this->distributionScale.x;
        v40 = (float)(particleDecl->bounds.b[1].z + this->distributionScale.z);
        v68.ops.list = (expOp_t *)&particleDecl->bounds.b[1];
        v41 = (float)(particleDecl->bounds.b[1].y + (float)y);
        v42 = (float)((float)x + particleDecl->bounds.b[1].x);
        v43 = (float)(particleDecl->bounds.b[0].z - (float)z);
        v44 = (float)(particleDecl->bounds.b[0].y - (float)y);
        v45 = (float)(particleDecl->bounds.b[0].x - (float)x);
        if ( v36 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v36 = this->presentable;
        }
        v46 = v36->model;
        v46->referenceBounds.b[0].x = v45;
        v46->referenceBounds.b[0].y = v44;
        v68.ops.list = (expOp_t *)&v46->referenceBounds.b[1];
        v46->referenceBounds.b[0].z = v43;
        v46->referenceBounds.b[1].x = v42;
        v46->referenceBounds.b[1].y = v41;
        v46->referenceBounds.b[1].z = v40;
      }
      v47 = this->presentable;
      if ( v47 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v47 = this->presentable;
      }
      v47->Present(this: v47);
    }
    idStr::FreeData(this: (idStr *)&v68.thread);
  }
}


// ========================================================================
// __unwind$499406
// EA  : 0x82C72154
// RVA : 0x00C72154
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_499406()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// ??0idElectricBoltEmitter@@QAA@XZ
// EA  : 0x82C72180
// RVA : 0x00C72180
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idElectricBoltEmitter *__fastcall idElectricBoltEmitter::idElectricBoltEmitter(idElectricBoltEmitter *this)
{
  idDynamicEntity::idDynamicEntity(this);
  this->maxConeAngle = 360.0;
  this->minResetTime = 500;
  this->__vftable = (idElectricBoltEmitter_vtbl *)&idElectricBoltEmitter::`vftable';
  this->maxResetTime = 1250;
  this->startOff = false;
  this->electricBoltSystem = nullptr;
  this->sndPowerDown = nullptr;
  this->sndPowerUp = nullptr;
  this->length.x = 10.0;
  this->length.y = 20.0;
  this->controlPath.spawnId.value = 0x1FFF;
  this->loopControlPath = false;
  this->controlPathGrowTime = 0;
  this->ebolt = nullptr;
  this->spline = nullptr;
  this->nextResetTime = -1;
  this->clipModelInfo.type = CLIPMODEL_NONE;
  return this;
}


// ========================================================================
// ??1idElectricBoltEmitter@@UAA@XZ
// EA  : 0x82C72230
// RVA : 0x00C72230
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idElectricBoltEmitter::~idElectricBoltEmitter(idElectricBoltEmitter *this)
{
  idElectricBolt *ebolt; // r29
  idCurve_Spline<idVec3> *spline; // r3

  this->__vftable = (idElectricBoltEmitter_vtbl *)&idElectricBoltEmitter::`vftable';
  ebolt = this->ebolt;
  if ( ebolt != nullptr )
  {
    idElectricBolt::~idElectricBolt(this: this->ebolt);
    idMem::Free(this: &mem, ptr: ebolt, align: ALIGN_16);
  }
  spline = this->spline;
  this->ebolt = nullptr;
  if ( spline != nullptr )
    ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))spline->dtr_idCurve<idVec3>)(a1: spline, a2: 1);
  this->spline = nullptr;
  this->__vftable = (idElectricBoltEmitter_vtbl *)&idDynamicEntity::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$499765
// EA  : 0x82C722C4
// RVA : 0x00C722C4
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_499765()
{
  int v0; // r12

  idDynamicEntity::~idDynamicEntity(this: *(idDynamicEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?SetControlPath@idElectricBoltEmitter@@AAAXPAVidSplinePath@@@Z
// EA  : 0x82C722F0
// RVA : 0x00C722F0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idElectricBoltEmitter::SetControlPath(idElectricBoltEmitter *this, idSplinePath *controlPath)
{
  idCurve_Spline<idVec3> *spline; // r3
  int v5; // r7
  int v6; // r6
  int v7; // r5
  int v8; // r4
  idCurve_Spline<idVec3> *v9; // r3
  __int64 v10; // r11 OVERLAPPED
  __int64 v11; // r8
  int GameMs; // r3
  idCurve_Spline<idVec3> *v13; // r11
  int v14; // r10
  int v15; // r9
  double v16; // fp0
  float *v17; // r8

  if ( controlPath != nullptr )
  {
    spline = this->spline;
    if ( spline != nullptr )
    {
      ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))spline->dtr_idCurve<idVec3>)(a1: spline, a2: 1);
      this->spline = nullptr;
    }
    v9 = idSplinePath::AllocSpline(this: controlPath);
    LODWORD(v10) = this->controlPathGrowTime;
    this->spline = v9;
    if ( (int)v10 > 0 )
      idCurve<idAngles>::MakeUniform(
        this: v9,
        totalTime: (float)v10,
        a3: v8,
        a4: v7,
        a5: v6,
        a6: v5,
        a7: *(__int64 *)((char *)&v10 + 4));
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v13 = this->spline;
    v14 = 0;
    if ( v13->times.num > 0 )
    {
      LODWORD(v11) = GameMs;
      v15 = 0;
      v16 = (float)((float)v11 - *v13->times.list);
      do
      {
        ++v14;
        v17 = &v13->times.list[v15++];
        *v17 = *v17 + (float)v16;
      }
      while ( v14 < v13->times.num );
    }
    v13->changed = true;
  }
}


// ========================================================================
// ??0idRibbonEmitter@@QAA@XZ
// EA  : 0x82C72410
// RVA : 0x00C72410
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idRibbonEmitter *__fastcall idRibbonEmitter::idRibbonEmitter(idRibbonEmitter *this)
{
  idDynamicEntity::idDynamicEntity(this);
  this->hidden = false;
  this->__vftable = (idRibbonEmitter_vtbl *)&idRibbonEmitter::`vftable';
  this->startOff = false;
  this->cycleTrigger = false;
  this->declRibbon = nullptr;
  idRibbonManager::idRibbonManager(this: &this->ribbonManager);
  this->clipModelInfo.type = CLIPMODEL_NONE;
  return this;
}


// ========================================================================
// __unwind$499841_0
// EA  : 0x82C72464
// RVA : 0x00C72464
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_499841_0()
{
  int v0; // r12

  idDynamicEntity::~idDynamicEntity(this: *(idDynamicEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idLensFlare@@QAA@XZ
// EA  : 0x82C724F8
// RVA : 0x00C724F8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idLensFlare *__fastcall idLensFlare::idLensFlare(idLensFlare *this)
{
  idDynamicEntity::idDynamicEntity(this);
  this->quadSize = 16.0;
  this->fadeStart = 400.0;
  this->fadeEnd = 0.0;
  this->__vftable = (idLensFlare_vtbl *)&idLensFlare::`vftable';
  this->startOff = false;
  this->cycleTrigger = false;
  this->declFlare = nullptr;
  this->sunDirection.x = 0.0;
  this->sunDirection.y = 0.0;
  this->sunDirection.z = 0.0;
  this->sunGlareEnvFadeOutTime = 1000;
  this->sunGlareEnvDotThreshold = 0.89999998;
  this->sunGlareSnd = nullptr;
  this->modulateTimeScale = 1.0;
  this->sunGlareSndVolumeTbl = nullptr;
  this->sunGlareSndPitchTbl = nullptr;
  this->sunGlareEnv = nullptr;
  this->colorModulateTbl = nullptr;
  this->occlusionQuadOffset.x = 0.0;
  this->occlusionQuadOffset.y = 0.0;
  this->occlusionQuadOffset.z = 0.0;
  this->autospriteOcclusionQuad = false;
  this->maxSunGlareScale = 2.0;
  this->sunGlareEnvActive = false;
  idLensFlareManager::idLensFlareManager(this: &this->flareManager);
  this->clipModelInfo.type = CLIPMODEL_NONE;
  return this;
}


// ========================================================================
// __unwind$499871
// EA  : 0x82C725DC
// RVA : 0x00C725DC
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_499871()
{
  int v0; // r12

  idDynamicEntity::~idDynamicEntity(this: *(idDynamicEntity **)(v0 - 128 + 148));
}


// ========================================================================
// ?SetFlare@idLensFlare@@AAAXXZ
// EA  : 0x82C72668
// RVA : 0x00C72668
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idLensFlare::SetFlare(idLensFlare *this)
{
  const idDeclFlare *declFlare; // r30
  bool autospriteOcclusionQuad; // r28
  double quadSize; // fp31
  idLensFlareManager *p_flareManager; // r29
  idVec3 *p_occlusionQuadOffset; // r27
  idRenderWorld *v7; // r3
  const idVec3 *v8; // r6
  idPresentable *presentable; // r11
  char v10; // r11
  bool v11; // zf
  double v12; // fp31
  idRenderModel *RenderModelFromPresentable; // r3
  idPhysics *Physics; // r30
  idPhysics *v15; // r28
  double fadeEnd; // fp31
  double fadeStart; // fp30
  const idMat3 *v18; // r31
  const idVec3 *v19; // r3
  idVec4 v20; // [sp+50h] [-50h] BYREF

  declFlare = this->declFlare;
  if ( declFlare != nullptr && !this->flareManager.isInitialized )
  {
    autospriteOcclusionQuad = this->autospriteOcclusionQuad;
    quadSize = this->quadSize;
    p_flareManager = &this->flareManager;
    p_occlusionQuadOffset = &this->occlusionQuadOffset;
    v7 = common->RW(this: common);
    idLensFlareManager::Init(
      this: p_flareManager,
      renderWorld: v7,
      flareDecl: declFlare,
      quadSize,
      _sunDirection: v8,
      _occlusionOffset: &this->sunDirection,
      _isAutosprited: p_occlusionQuadOffset,
      a8: autospriteOcclusionQuad);
    this->SetModel(this, a2: this->flareManager.flareOcclusionQuadModel);
    idEntity::InitRenderModel(this);
    presentable = this->presentable;
    if ( presentable == nullptr || (v11 = presentable->model != nullptr, v10 = 1, !v11) )
      v10 = 0;
    if ( v10 != 0 )
    {
      v12 = this->quadSize;
      RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
      RenderModelFromPresentable->g.scale.x = v12;
      RenderModelFromPresentable->g.scale.y = v12;
      RenderModelFromPresentable->g.scale.z = v12;
    }
    this->GetColor(this, a2: &v20);
    Physics = idEntity::GetPhysics(this);
    v15 = idEntity::GetPhysics(this);
    fadeEnd = this->fadeEnd;
    fadeStart = this->fadeStart;
    v18 = Physics->GetAxis(this: Physics, a2: 0);
    v19 = v15->GetOrigin(this: v15, a2: 0);
    idLensFlareManager::StartFlare(
      this: p_flareManager,
      org: v19,
      axis: v18,
      color: &v20,
      fadeStartRange: fadeStart,
      fadeEndRange: fadeEnd);
  }
}


// ========================================================================
// ?OnActivate@idLensFlare@@UAAXPAVidEntity@@@Z
// EA  : 0x82C727E0
// RVA : 0x00C727E0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idLensFlare::OnActivate(idLensFlare *this, idEntity *activator)
{
  idLensFlare *v2; // r31

  v2 = this;
  if ( this->cycleTrigger )
  {
    if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) == 0
      && v2->flareManager.isInitialized )
    {
      v2->Hide_2(this: v2);
      return;
    }
    this = v2;
  }
  idLensFlare::SetFlare(this);
  v2->Show(this: v2);
}


// ========================================================================
// ?Spawn@idGodRays@@QAAXXZ
// EA  : 0x82C728B8
// RVA : 0x00C728B8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idGodRays::Spawn(idGodRays *this)
{
  int sourceSize; // r11
  idEventArg *v3; // r3
  idEventArg v4; // [sp+50h] [-30h] BYREF

  if ( this->texture == nullptr )
    this->texture = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                          this: &idMaterial::resourceList,
                                          name: "textures/sfx/godrays/sunray",
                                          makeDefault: true);
  sourceSize = this->sourceSize;
  if ( sourceSize < 0 || this->size < sourceSize )
  {
    idLib::Error(fmt: "idGodRay '%s' has invalid data", this->name.data);
    JUMPOUT(0x82C72964);
  }
  v3 = idEventArg::idEventArg(this: &v4, data: this);
  idEventReceiver::PostEventMS(
    this,
    ev: &EV_Activate,
    time: *(_DWORD *)&v3->type,
    arg1: (const idEventArg *)LODWORD(v3->value.v[1]));
}


// ========================================================================
// ?Spawn@idRegimeTile@@QAAXXZ
// EA  : 0x82C72968
// RVA : 0x00C72968
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idRegimeTile::Spawn(idRegimeTile *this)
{
  BOOL damageable; // r11
  idLinkList<idRegimeTile> *head; // r5

  damageable = this->damageable;
  *(_BYTE *)&this->flags = (2 * damageable) & 2 | 0x40 | *(_BYTE *)&this->flags & 0xFD;
  if ( damageable )
  {
    head = gameLocal->regimePowerSources.head;
    this->controlNode.prev->next = this->controlNode.next;
    this->controlNode.next->prev = this->controlNode.prev;
    this->controlNode.prev = &this->controlNode;
    this->controlNode.head = &this->controlNode;
    this->controlNode.next = head;
    this->controlNode.prev = head->prev;
    head->prev = &this->controlNode;
    this->controlNode.prev->next = &this->controlNode;
    this->controlNode.head = head->head;
    this->controlNode.owner = this;
  }
  if ( this->damageable || this->master )
  {
    if ( this->startOff )
    {
      this->Hide_2(this);
      this->powered = false;
    }
    else
    {
      idRegimeTile::TurnOn(this);
    }
    idEventReceiver::PostEventMS(this, ev: &EV_PostSpawn, time: 0);
  }
}


// ========================================================================
// ?Damage@idRegimeTile@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82C72A70
// RVA : 0x00C72A70
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

float __fastcall idRegimeTile::Damage(
        idRegimeTile *this,
        idTrigger_TakeDamage *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace)
{
  double v11; // fp31
  double v12; // fp1
  double v13; // fp1
  int v14; // r10
  int v15; // r9
  int v16; // r8
  int v17; // r7
  idDynamicEntity *Entity; // r3
  idEntity *v19; // r30
  idPresentable *presentable; // r3
  char v21; // r11
  __int64 v23; // [sp+8h] [-98h]
  __int64 v24; // [sp+10h] [-90h]
  __int64 v25; // [sp+18h] [-88h]
  __int64 v26; // [sp+20h] [-80h]
  __int64 v27; // [sp+28h] [-78h]
  __int64 v28; // [sp+58h] [-48h]

  v11 = 0.0;
  if ( this->damageable && this->powered && damageDef != nullptr )
  {
    if ( this->takeTriggerDmgOnly && idTrigger_TakeDamage::CastTo(c: inflictor) == nullptr )
    {
      if ( g_DebugRegimeTiles.valueInteger != 0 )
        idLib::Printf(
          fmt: "0 damage to idRegimeTile '%s' - Not caused by an emp or idTrigger_TakeDamage\n",
          this->name.data);
      v12 = 0.0;
      return *((float *)&v12 + 1);
    }
    v13 = idDeclDamage::DamageAmount(this: damageDef);
    v11 = (float)(this->nonEMPDamageScale * (float)((float)v13 * (float)damageScale));
    this->health = this->health - (float)(this->nonEMPDamageScale * (float)((float)v13 * (float)damageScale));
    Entity = idEntityPtr<idDynamicEntity>::GetEntity(this: &this->healthReadout);
    v19 = Entity;
    if ( Entity != nullptr )
    {
      presentable = Entity->presentable;
      if ( presentable == nullptr || (v21 = 1, presentable->model == nullptr) )
        v21 = 0;
      if ( v21 != 0 )
      {
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this: v19);
          presentable = v19->presentable;
        }
        *((float *)&v28 + 1) = 1.0;
        *(float *)&v28 = 1.0;
        idPresentable::SetParm(
          this: presentable,
          parm: rp->Color,
          v4: v28,
          a4: v17,
          a5: v16,
          a6: v15,
          a7: v14,
          a8: v23,
          a9: v24,
          a10: v25,
          a11: v26,
          a12: v27);
        idEntity::UpdateVisuals(this: v19);
      }
    }
    if ( this->health <= 0.0 )
      this->OnActivate(this, a2: inflictor);
  }
  if ( g_DebugRegimeTiles.valueInteger != 0 )
    idLib::Printf(
      fmt: "%f damage to idRegimeTile '%s' - caused by '%s'\n",
      v11,
      (const char *)LODWORD(v11),
      this->name.data);
  v12 = v11;
  return *((float *)&v12 + 1);
}


// ========================================================================
// ?TurnOff@idRegimeTile@@AAAXXZ
// EA  : 0x82C72C58
// RVA : 0x00C72C58
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idRegimeTile::TurnOff(idRegimeTile *this)
{
  BOOL shouldFadeOnActivate; // r9
  int value; // r10
  idDynamicEntity *v4; // r3
  idDynamicEntity *v5; // r3
  idEntity *v6; // r30
  idPresentable *presentable; // r3
  char v8; // r11
  float v9; // [sp+50h] [-30h] BYREF
  float v10[3]; // [sp+54h] [-2Ch] BYREF

  idEntity::StopSound(this, channel: SND_CHANNEL_AMBIENT, peerMask: 0xFFu);
  idEntity::StartSoundShader(
    this,
    channel: SND_CHANNEL_ANY,
    shader: this->sndPowerDown,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  shouldFadeOnActivate = this->shouldFadeOnActivate;
  this->powered = false;
  if ( shouldFadeOnActivate )
  {
    v9 = 0.0;
    v10[0] = 1.0;
    idFadeHelper::Fade(this: &this->fade, from: v10, to: &v9, time: &this->fadeTime, _noStippleFade: false);
    idEntity::BecomeActive(this, flags: 1);
    idEventReceiver::PostEventMS(this, ev: &EV_Hide, time: this->fadeTime);
  }
  value = this->healthReadout.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v4 = (idDynamicEntity *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v4 != nullptr )
    {
      v5 = idDynamicEntity::CastTo(c: v4);
      v6 = v5;
      if ( v5 != nullptr )
      {
        presentable = v5->presentable;
        if ( presentable == nullptr || (v8 = 1, presentable->model == nullptr) )
          v8 = 0;
        if ( v8 != 0 )
        {
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this: v6);
            presentable = v6->presentable;
          }
          idPresentable::SetParm(this: presentable, parm: rp->Color, scalar: 0.0);
          idEntity::UpdateVisuals(this: v6);
        }
      }
    }
  }
  idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// ??0idFuncWind@@QAA@XZ
// EA  : 0x82C72DD0
// RVA : 0x00C72DD0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idFuncWind *__fastcall idFuncWind::idFuncWind(idFuncWind *this)
{
  idEntity::idEntity(this);
  this->maxGustDuration = 15000;
  this->minWindVolume = -60.0;
  this->__vftable = (idFuncWind_vtbl *)&idFuncWind::`vftable';
  this->maxWindVolume = -30.0;
  this->minGustDuration = 10000;
  this->minDistance = 1024.0;
  this->maxDistance = 2048.0;
  this->sndWindLevel1 = nullptr;
  this->windStrengthStartVal = 10.0;
  this->sndWindLevel2 = nullptr;
  this->windStrengthEndVal = 30.0;
  this->sndWindLevel3 = nullptr;
  this->windAngle = 0.0;
  this->startOff = false;
  this->cycleTrigger = false;
  this->globalWind = false;
  this->fadeOut = 0;
  this->windStrength.extrapolate.duration = 0.0;
  this->windStrength.extrapolate.extrapolationType = EXTRAPOLATION_NONE;
  this->windStrength.extrapolate.startTime = 0.0;
  this->windStrength.extrapolate.startValue = 0.0;
  this->windStrength.extrapolate.baseSpeed = 0.0;
  this->windStrength.extrapolate.speed = 0.0;
  this->windStrength.extrapolate.currentTime = -1.0;
  this->windStrength.extrapolate.currentValue = this->windStrength.extrapolate.startValue;
  this->globalWindNode.owner = nullptr;
  this->windStrength.decelTime = 0.0;
  this->globalWindNode.head = &this->globalWindNode;
  this->windStrength.linearTime = 0.0;
  this->globalWindNode.next = &this->globalWindNode;
  this->windStrength.accelTime = 0.0;
  this->globalWindNode.prev = &this->globalWindNode;
  this->windStrength.startTime = 0.0;
  this->windStrength.startValue = 0.0;
  this->windStrength.endValue = this->windStrength.startValue;
  this->globalWindNode.owner = this;
  return this;
}


// ========================================================================
// ?StartWind@idFuncWind@@AAAXXZ
// EA  : 0x82C72F08
// RVA : 0x00C72F08
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idFuncWind::StartWind(idFuncWind *this)
{
  double maxDistance; // fp13
  __int64 v3; // r10
  idClientGame *v4; // r11
  signed int v5; // r4
  signed int v6; // r6
  double v7; // fp31
  double v8; // fp30
  __int64 v9; // r7
  const float *v10; // r5
  const float *v11; // r4
  soundShaderParms_t v12; // [sp+60h] [-D0h] BYREF

  soundShaderParms_t::Clear(this: &v12);
  maxDistance = this->maxDistance;
  v12.minDistance = this->minDistance;
  v12.soundShaderFlags = SSF_LOOPING;
  v12.maxDistance = maxDistance;
  idEntity::StartSoundShader(this, channel: SND_CHANNEL_WIND, shader: this->sndWindLevel1, parms: &v12, peerMask: 0xFFu);
  idEntity::StartSoundShader(
    this,
    channel: SND_CHANNEL_WIND2,
    shader: this->sndWindLevel2,
    parms: &v12,
    peerMask: 0xFFu);
  idEntity::StartSoundShader(
    this,
    channel: SND_CHANNEL_WIND3,
    shader: this->sndWindLevel3,
    parms: &v12,
    peerMask: 0xFFu);
  idEntity::SetSoundVolume(this, channel: SND_CHANNEL_WIND, volume: -60.0);
  idEntity::SetSoundVolume(this, channel: SND_CHANNEL_WIND2, volume: -60.0);
  idEntity::SetSoundVolume(this, channel: SND_CHANNEL_WIND3, volume: -60.0);
  HIDWORD(v3) = this->maxGustDuration;
  LODWORD(v3) = this->minGustDuration;
  v4 = clientGame;
  if ( (int)v3 < SHIDWORD(v3) )
  {
    v5 = HIDWORD(v3) - v3 + 1;
    HIDWORD(v3) = 1664525 * clientGame->random.seed + 1013907456;
    __twllei(v5, 0);
    clientGame->random.seed = HIDWORD(v3) - 3233;
    v4 = clientGame;
    v6 = ((unsigned int)(HIDWORD(v3) - 3233) >> 10) & 0x7FFF;
    __twlgei(v5 & ~(__ROL4__(v6, 1) - 1), 0xFFFFFFFF);
    LODWORD(v3) = v6 % v5 + v3;
  }
  HIDWORD(v3) = &unk_82390000;
  v7 = (float)((float)v3 * (float)0.001);
  v8 = (float)((float)((float)v3 * (float)0.001) * (float)0.5);
  LODWORD(v9) = idGameTimeManager::GetGameMs(this: &v4->gameTimeManager, type: GAMETIME_SCALED);
  idInterpolateAccelDecelSine<float>::Init(
    this: &this->windStrength,
    startTime: (float)v9,
    accelTime: v8,
    decelTime: v8,
    duration: v7,
    startValue: v11,
    endValue: v10,
    a8: SHIDWORD(v9),
    a9: v9,
    a10: &this->windStrengthStartVal,
    a11: &this->windStrengthEndVal);
}


// ========================================================================
// ?OnActivate@idFuncWind@@EAAXPAVidEntity@@@Z
// EA  : 0x82C730B0
// RVA : 0x00C730B0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idFuncWind::OnActivate(idFuncWind *this, idEntity *activator)
{
  __int64 v3; // r9
  bool v4; // r5
  double v5; // fp31
  bool v6; // r5
  bool v7; // r5
  int v8; // r6
  const float *v9; // r5
  const float *v10; // r4
  float v11[2]; // [sp+50h] [-30h] BYREF
  float v12; // [sp+58h] [-28h] BYREF
  int fadeOut; // [sp+5Ch] [-24h]

  if ( this->cycleTrigger || (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) != 0 )
  {
    ((void (__fastcall *)(idFuncWind *, idEntity *))this->Show)(a1: this, a2: activator);
    idFuncWind::StartWind(this);
  }
  else
  {
    fadeOut = this->fadeOut;
    LODWORD(v3) = fadeOut;
    v5 = (float)((float)v3 * (float)0.001);
    idEntity::FadeSound(this, channel: SND_CHANNEL_WIND, to: -60.0, over: v5, additive: v4);
    idEntity::FadeSound(this, channel: SND_CHANNEL_WIND2, to: -60.0, over: v5, additive: v6);
    idEntity::FadeSound(this, channel: SND_CHANNEL_WIND3, to: -60.0, over: v5, additive: v7);
    v11[0] = 0.0;
    v12 = 0.0;
    idInterpolateAccelDecelSine<float>::Init(
      this: &this->windStrength,
      startTime: 0.0,
      accelTime: 0.0,
      decelTime: 0.0,
      duration: 0.0,
      startValue: v10,
      endValue: v9,
      a8: v8,
      a9: 0x82000000,
      a10: &v12,
      a11: v11);
    idEventReceiver::PostEventMS(this, ev: &EV_Hide, time: this->fadeOut);
  }
}


// ========================================================================
// ??0idWindEmitter@@QAA@XZ
// EA  : 0x82C731D8
// RVA : 0x00C731D8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idWindEmitter *__fastcall idWindEmitter::idWindEmitter(idWindEmitter *this)
{
  idEntity::idEntity(this);
  this->gustWeight = 0.5;
  this->minWindVolume = -60.0;
  this->maxWindVolume = -30.0;
  this->minDistance = 1024.0;
  this->__vftable = (idWindEmitter_vtbl *)&idWindEmitter::`vftable';
  this->minGustDuration = 10000;
  this->maxDistance = 2048.0;
  this->windStrengthStartVal = 10.0;
  this->sndBaseWind = nullptr;
  this->windStrengthEndVal = 30.0;
  this->maxGustDuration = 15000;
  this->windAngle = 0.0;
  this->gustCrossFadeTime = 1500;
  this->influence.innerRadius = 32.0;
  this->influence.trailDist = 32.0;
  this->influence.outerRadius = 64.0;
  this->influence.angle = 0.0;
  this->influence.trailFadeInTime = 0.25;
  this->influence.trailFadeOutTime = 2.0;
  this->startOff = false;
  this->fadeOut = 0.0;
  this->cycleTrigger = false;
  this->windStrength.extrapolate.duration = 0.0;
  this->windStrength.extrapolate.extrapolationType = EXTRAPOLATION_NONE;
  this->windStrength.extrapolate.startTime = 0.0;
  this->windStrength.extrapolate.startValue = 0.0;
  this->windStrength.extrapolate.baseSpeed = 0.0;
  this->windStrength.extrapolate.speed = 0.0;
  this->windStrength.extrapolate.currentTime = -1.0;
  this->windStrength.extrapolate.currentValue = this->windStrength.extrapolate.startValue;
  this->windStrength.decelTime = 0.0;
  this->windStrength.linearTime = 0.0;
  this->windStrength.accelTime = 0.0;
  this->windStrength.startTime = 0.0;
  this->windStrength.startValue = 0.0;
  this->windStrength.endValue = this->windStrength.startValue;
  this->currGustOverlayIdx = -1;
  this->sndGustOverlay[0] = nullptr;
  this->sndGustOverlay[1] = nullptr;
  this->sndGustOverlay[2] = nullptr;
  return this;
}


// ========================================================================
// ?StartWind@idWindEmitter@@AAAXXZ
// EA  : 0x82C733B8
// RVA : 0x00C733B8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idWindEmitter::StartWind(idWindEmitter *this)
{
  double maxDistance; // fp13
  soundChannel_t v3; // r30
  const idSoundShader **sndGustOverlay; // r29
  int i; // r28
  const idSoundShader *sndBaseWind; // r5
  __int64 v7; // r10
  idClientGame *v8; // r11
  signed int v9; // r4
  signed int v10; // r6
  double v11; // fp31
  double v12; // fp30
  __int64 v13; // r7
  const float *v14; // r5
  const float *v15; // r4
  soundShaderParms_t v16; // [sp+60h] [-E0h] BYREF

  soundShaderParms_t::Clear(this: &v16);
  maxDistance = this->maxDistance;
  v3 = SND_CHANNEL_WIND2;
  v16.minDistance = this->minDistance;
  sndGustOverlay = this->sndGustOverlay;
  v16.maxDistance = maxDistance;
  for ( i = 3; i != 0; --i )
  {
    if ( *sndGustOverlay != nullptr )
    {
      idEntity::StartSoundShader(this, channel: v3, shader: *sndGustOverlay, parms: &v16, peerMask: 0xFFu);
      idEntity::SetSoundVolume(this, channel: v3, volume: -60.0);
    }
    ++sndGustOverlay;
    ++v3;
  }
  sndBaseWind = this->sndBaseWind;
  v16.soundShaderFlags = SSF_LOOPING;
  idEntity::StartSoundShader(this, channel: SND_CHANNEL_WIND, shader: sndBaseWind, parms: &v16, peerMask: 0xFFu);
  idEntity::SetSoundVolume(this, channel: SND_CHANNEL_WIND, volume: -60.0);
  HIDWORD(v7) = this->maxGustDuration;
  LODWORD(v7) = this->minGustDuration;
  v8 = clientGame;
  if ( (int)v7 < SHIDWORD(v7) )
  {
    v9 = HIDWORD(v7) - v7 + 1;
    HIDWORD(v7) = 1664525 * clientGame->random.seed + 1013907456;
    __twllei(v9, 0);
    clientGame->random.seed = HIDWORD(v7) - 3233;
    v8 = clientGame;
    v10 = ((unsigned int)(HIDWORD(v7) - 3233) >> 10) & 0x7FFF;
    __twlgei(v9 & ~(__ROL4__(v10, 1) - 1), 0xFFFFFFFF);
    LODWORD(v7) = v10 % v9 + v7;
  }
  HIDWORD(v7) = &unk_82390000;
  v11 = (float)((float)v7 * (float)0.001);
  v12 = (float)((float)((float)v7 * (float)0.001) * (float)0.5);
  LODWORD(v13) = idGameTimeManager::GetGameMs(this: &v8->gameTimeManager, type: GAMETIME_SCALED);
  idInterpolateAccelDecelSine<float>::Init(
    this: &this->windStrength,
    startTime: (float)v13,
    accelTime: v12,
    decelTime: v12,
    duration: v11,
    startValue: v15,
    endValue: v14,
    a8: SHIDWORD(v13),
    a9: v13,
    a10: &this->windStrengthStartVal,
    a11: &this->windStrengthEndVal);
}


// ========================================================================
// ?OnActivate@idWindEmitter@@EAAXPAVidEntity@@@Z
// EA  : 0x82C73558
// RVA : 0x00C73558
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idWindEmitter::OnActivate(idWindEmitter *this, idEntity *activator)
{
  bool v3; // r5
  double v4; // fp31
  int v5; // r7
  int v6; // r6
  const float *v7; // r5
  const float *v8; // r4
  int currGustOverlayIdx; // r11
  float v10[2]; // [sp+50h] [-30h] BYREF
  float v11; // [sp+58h] [-28h] BYREF
  int fadeOut; // [sp+5Ch] [-24h]

  if ( this->cycleTrigger || (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) != 0 )
  {
    ((void (__fastcall *)(idWindEmitter *, idEntity *))this->Show)(a1: this, a2: activator);
    idWindEmitter::StartWind(this);
  }
  else
  {
    v4 = (float)(this->fadeOut * (float)0.001);
    idEntity::FadeSound(this, channel: SND_CHANNEL_WIND, to: -60.0, over: v4, additive: v3);
    currGustOverlayIdx = this->currGustOverlayIdx;
    if ( currGustOverlayIdx >= 0 && this->sndGustOverlay[currGustOverlayIdx] != nullptr )
      idEntity::FadeSound(
        this,
        channel: (soundChannel_t)(currGustOverlayIdx + 43),
        to: -60.0,
        over: v4,
        additive: (bool)v7);
    v10[0] = 0.0;
    v11 = 0.0;
    idInterpolateAccelDecelSine<float>::Init(
      this: &this->windStrength,
      startTime: 0.0,
      accelTime: 0.0,
      decelTime: 0.0,
      duration: 0.0,
      startValue: v8,
      endValue: v7,
      a8: v6,
      a9: v5,
      a10: &v11,
      a11: v10);
    fadeOut = (int)this->fadeOut;
    idEventReceiver::PostEventMS(this, ev: &EV_Hide, time: fadeOut);
  }
}


// ========================================================================
// ?Spawn@idEntityImposter@@QAAXXZ
// EA  : 0x82C73680
// RVA : 0x00C73680
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idEntityImposter::Spawn(idEntityImposter *this)
{
  idEntity::FreeRenderModel(this);
  if ( gameLocal->spawnIds.ptr[this->original.spawnId.value & 0x1FFF] == this->original.spawnId.value >> 13 )
    idEventReceiver::PostEventMS(this, ev: &EV_MimicEntity, time: 10);
}


// ========================================================================
// ?Event_MimicEntity@idEntityImposter@@AAA?AVeventVoid@@XZ
// EA  : 0x82C736E8
// RVA : 0x00C736E8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idEntityImposter *__fastcall idEntityImposter::Event_MimicEntity(idEntityImposter *this, idEntity *result)
{
  idEntity_vtbl *v2; // r30
  idRenderModel *v5; // r3
  idPresentable *presentable; // r11
  char v7; // r11
  bool v8; // zf
  idRenderModel *RenderModelFromPresentable; // r3
  int x_low; // r10
  idRenderModelImposter *v11; // r29
  idEntity *v12; // r3
  idEntity *v13; // r3
  int v14; // r9
  idEntity *v15; // r3
  idEntity *v16; // r3
  idRenderModel *v17; // r3
  idPresentable *v18; // r3

  v2 = result->__vftable;
  v5 = clientGame->renderWorld->AllocRenderModel(this: clientGame->renderWorld, a2: "_imposterStatic", a3: 1, a4: -1);
  v2->SetModel(this: result, a2: v5);
  presentable = result->presentable;
  if ( presentable == nullptr || (v8 = presentable->model != nullptr, v7 = 1, !v8) )
    v7 = 0;
  if ( v7 != 0 )
  {
    RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: result);
    x_low = LODWORD(result[1].spawnOrientation.mat[2].x);
    v11 = (idRenderModelImposter *)RenderModelFromPresentable;
    if ( gameLocal->spawnIds.ptr[x_low & 0x1FFF] == x_low >> 13
      && (v12 = gameLocal->entities.ptr[x_low & 0x1FFF]) != nullptr )
    {
      v13 = idEntity::CastTo(c: v12);
    }
    else
    {
      v13 = nullptr;
    }
    if ( idEntity::GetRenderModelFromPresentable(this: v13) != nullptr )
    {
      v14 = LODWORD(result[1].spawnOrientation.mat[2].x);
      if ( gameLocal->spawnIds.ptr[v14 & 0x1FFF] == v14 >> 13
        && (v15 = gameLocal->entities.ptr[v14 & 0x1FFF]) != nullptr )
      {
        v16 = idEntity::CastTo(c: v15);
      }
      else
      {
        v16 = nullptr;
      }
      v17 = idEntity::GetRenderModelFromPresentable(this: v16);
      idRenderModelImposter::MimicRenderModel(this: v11, parentModel: v17);
      idEntity::InitRenderModel(this: result);
      v18 = result->presentable;
      if ( v18 == nullptr )
      {
        idEntity::InitPresentableInternal(this: result);
        v18 = result->presentable;
      }
      v18->Present(this: v18);
      idEntity::BecomeActive(this: result, flags: 1);
    }
  }
  return this;
}


// ========================================================================
// ??0idDebrisEntity@@QAA@XZ
// EA  : 0x82C73870
// RVA : 0x00C73870
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idDebrisEntity *__fastcall idDebrisEntity::idDebrisEntity(idDebrisEntity *this)
{
  idDynamicEntity::idDynamicEntity(this);
  this->__vftable = (idDebrisEntity_vtbl *)&idDebrisEntity::`vftable';
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->physicsObj);
  this->solid = false;
  this->hide = false;
  this->dieTime = 0;
  this->clipModelInfo.type = CLIPMODEL_NONE;
  return this;
}


// ========================================================================
// __unwind$500497
// EA  : 0x82C738D8
// RVA : 0x00C738D8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_500497()
{
  int v0; // r12

  idDynamicEntity::~idDynamicEntity(this: *(idDynamicEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?SetModel@idDebrisEntity@@UAAXPAVidRenderModel@@@Z
// EA  : 0x82C739F8
// RVA : 0x00C739F8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDebrisEntity::SetModel(idDebrisEntity *this, idRenderModel *renderModel)
{
  idPresentable *presentable; // r11
  char v5; // r10
  idPhysics_RigidBody *p_physicsObj; // r30
  idClipModel *v7; // r3
  idClipModel *v8; // r4
  void (__fastcall *SetGravity)(struct idPhysics_RigidBody *, const idVec3 *); // r5
  int v10; // r5
  float v11[6]; // [sp+58h] [-648h] BYREF
  idTraceModel v12; // [sp+70h] [-630h] BYREF

  idEntity::SetModel(this, model: renderModel);
  presentable = this->presentable;
  if ( presentable == nullptr || (v5 = 1, presentable->model == nullptr) )
    v5 = 0;
  if ( v5 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->model->g.castDimShadows = DIMSHADOW_OFF;
  }
  idTraceModel::InitBox(this: &v12);
  idTraceModel::SetupBox(this: &v12, boxBounds: &renderModel->referenceBounds);
  p_physicsObj = &this->physicsObj;
  idPhysics::InitPhysics(
    this: &this->physicsObj,
    clip_: &clientGame->clip,
    callbacks_: &this->physicsCallbacks,
    entityNumber_: this->entityNumber);
  v7 = (idClipModel *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0xD8u,
                        tag: TAG_CLIPMODEL,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
    v8 = idClipModel::idClipModel(this: v7, clip: &clientGame->clip, trm: &v12, numTraceModels: 1, material: nullptr);
  else
    v8 = nullptr;
  ((void (__fastcall *)(idPhysics_RigidBody *, idClipModel *, double))p_physicsObj->SetClipModel)(
    a1: &this->physicsObj,
    a2: v8,
    a3: 0.0040000002);
  SetGravity = p_physicsObj->SetGravity;
  v11[0] = 0.0;
  v11[1] = 0.0;
  v11[2] = -100.0;
  SetGravity(this: &this->physicsObj, a2: (const idVec3 *)v11);
  p_physicsObj->SetContents(this: &this->physicsObj, a2: 0, a3: -1);
  p_physicsObj->SetClipMask(this: &this->physicsObj, a2: 1, a3: -1);
  p_physicsObj->PutToRest(this: &this->physicsObj);
  idEntity::SetPhysics(this, phys: &this->physicsObj, a3: v10);
}


// ========================================================================
// __unwind$500554
// EA  : 0x82C73BA8
// RVA : 0x00C73BA8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_500554()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1696 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?Show@idAnnouncementManager@@UAAXXZ
// EA  : 0x82C73BD8
// RVA : 0x00C73BD8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idAnnouncementManager::Show(idAnnouncementManager *this)
{
  idEntity::Show(this);
  if ( !this->active )
    idAnnouncementManager::Activate(this);
}


// ========================================================================
// ?Spawn@idAnnouncementManager@@QAAXXZ
// EA  : 0x82C73C18
// RVA : 0x00C73C18
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idAnnouncementManager::Spawn(idAnnouncementManager *this)
{
  if ( this->startActive )
    idAnnouncementManager::Activate(this);
}


// ========================================================================
// ?Deactivate@idAnnouncementManager@@AAAXXZ
// EA  : 0x82C73C30
// RVA : 0x00C73C30
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idAnnouncementManager::Deactivate(idAnnouncementManager *this)
{
  int v2; // r28
  int v3; // r30
  int value; // r9
  idEntity *v5; // r3
  idSound *v6; // r3
  idSound *v7; // r3

  this->active = false;
  idEntity::BecomeInactive(this, flags: 1);
  v2 = 0;
  if ( this->targets.num > 0 )
  {
    v3 = 0;
    do
    {
      value = this->targets.list[v3].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v6 = (idSound *)idEntity::CastTo(c: v5);
      }
      else
      {
        v6 = nullptr;
      }
      v7 = idSound::CastTo(c: v6);
      if ( v7 != nullptr )
        idEventReceiver::PostEventMS(this: v7, ev: &EV_Off, time: 0);
      ++v2;
      ++v3;
    }
    while ( v2 < this->targets.num );
  }
}


// ========================================================================
// ?PlayVoiceOver@idAnnouncementManager@@AAAXXZ
// EA  : 0x82C73CF0
// RVA : 0x00C73CF0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idAnnouncementManager::PlayVoiceOver(idAnnouncementManager *this)
{
  const idDeclVoiceOver *firstAnnouncementVO; // r21
  signed int num; // r11
  unsigned int seed; // r7
  unsigned int v5; // r3
  int v6; // r8
  unsigned int v7; // r4
  int v8; // r11
  signed int v9; // r8
  unsigned int v10; // r4
  const idDeclVoiceOver **list; // r10
  int v12; // r4
  int v13; // r22
  const idVoiceTrack *v14; // r11
  const idSoundShader *soundShader; // r23
  int v16; // r25
  int v17; // r30
  int value; // r9
  idEntity *v19; // r3
  idSound *v20; // r3
  idSound *v21; // r3
  idEventReceiver *v22; // r31
  idStrId v23; // [sp+50h] [-90h] BYREF
  int v24; // [sp+60h] [-80h]
  const idSoundShader *v25; // [sp+64h] [-7Ch]
  const idEventArg *v26; // [sp+68h] [-78h]

  firstAnnouncementVO = nullptr;
  if ( this->playedFirst || this->firstAnnouncementVO == nullptr )
  {
    num = this->announcementsVO.num;
    if ( num > 0 )
    {
      seed = clientGame->random.seed;
      __twllei(num, 0);
      v5 = 1664525 * seed + 1013904223;
      clientGame->random.seed = v5;
      v6 = (v5 >> 10) & 0x7FFF;
      v7 = num & ~(__ROL4__(v6, 1) - 1);
      v8 = v6 % num;
      __twlgei(v7, 0xFFFFFFFF);
      if ( v8 == this->lastAnnouncement )
      {
        v9 = this->announcementsVO.num;
        v10 = v9 & ~(__ROL4__(v8 + 1, 1) - 1);
        __twllei(v9, 0);
        v8 = (v8 + 1) % v9;
        __twlgei(v10, 0xFFFFFFFF);
      }
      list = this->announcementsVO.list;
      this->lastAnnouncement = v8;
      firstAnnouncementVO = list[v8];
    }
  }
  else
  {
    firstAnnouncementVO = this->firstAnnouncementVO;
  }
  this->playedFirst = true;
  if ( firstAnnouncementVO != nullptr )
  {
    v12 = firstAnnouncementVO->tracks.num;
    v13 = 0;
    if ( v12 > 1 && (v13 = idRandom2::RandomInt(this: &clientGame->random, max: v12)) < 0
      || v13 >= firstAnnouncementVO->tracks.num )
    {
      v14 = nullptr;
    }
    else
    {
      v14 = firstAnnouncementVO->tracks.list[v13];
    }
    soundShader = v14->soundShader;
    v16 = 0;
    if ( this->targets.num > 0 )
    {
      v17 = 0;
      do
      {
        value = this->targets.list[v17].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v19 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v20 = (idSound *)idEntity::CastTo(c: v19);
        }
        else
        {
          v20 = nullptr;
        }
        v21 = idSound::CastTo(c: v20);
        v22 = v21;
        if ( v21 != nullptr )
        {
          v25 = soundShader;
          HIBYTE(v24) = 100;
          idEventReceiver::PostEventMS(this: v21, ev: &EV_SetSoundShader, time: v24, arg1: v26);
          idEventReceiver::PostEventMS(this: v22, ev: &EV_On, time: 0);
        }
        ++v16;
        ++v17;
      }
      while ( v16 < this->targets.num );
    }
    v23.index = this->talkerName.index;
    idGameLocal::PlayedVoiceOver(
      this: gameLocal,
      whoStartedMe: nullptr,
      target: nullptr,
      vo: firstAnnouncementVO,
      voiceTrackIndex: v13,
      whoStartedMeText: &v23);
  }
}


// ========================================================================
// ?Spawn@idHorizonScale@@QAAXXZ
// EA  : 0x82C73F20
// RVA : 0x00C73F20
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idHorizonScale::Spawn(idHorizonScale *this)
{
  if ( this->targets.num > 0 )
    idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?RandomPath@idPathCorner@@SAPAV1@PBVidEntity@@0@Z
// EA  : 0x82C74028
// RVA : 0x00C74028
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idPathCorner *__fastcall idPathCorner::RandomPath(
        const idEntity *source,
        const idEntity *ignore,
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
  __int64 v28; // r4
  int v29; // r29
  idEntity *v30; // r24
  signed int v31; // r27
  int v32; // r28
  int v33; // r30
  int *v34; // r25
  int v35; // r9
  idEntity *v36; // r3
  idEntity *v37; // r31
  unsigned int v39; // r4
  int v40; // r3

  v28 = ((__int64 (*)(void))RtlCheckStack12)();
  v29 = HIDWORD(v28);
  v30 = (idEntity *)v28;
  a27 = 0;
  memset(Dst: &a28, Val: 0, Size: 0x7FFCu);
  v31 = 0;
  v32 = 0;
  if ( *(int *)(v29 + 100) <= 0 )
    return nullptr;
  v33 = 0;
  v34 = &a26;
  do
  {
    v35 = *(_DWORD *)(*(_DWORD *)(v29 + 96) + v33);
    if ( gameLocal->spawnIds.ptr[v35 & 0x1FFF] == v35 >> 13 && (v36 = gameLocal->entities.ptr[v35 & 0x1FFF]) != nullptr )
      v37 = idEntity::CastTo(c: v36);
    else
      v37 = nullptr;
    if ( v37 != v30 && (unsigned __int8)idPathCorner::IsTypeOf(c: v37) != 0 )
    {
      ++v31;
      *++v34 = (int)v37;
      if ( v31 >= 0x2000 )
        break;
    }
    ++v32;
    v33 += 4;
  }
  while ( v32 < *(_DWORD *)(v29 + 100) );
  if ( v31 == 0 )
    return nullptr;
  __twllei(v31, 0);
  v39 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v39;
  v40 = (v39 >> 10) & 0x7FFF;
  __twlgei(v31 & ~(__ROL4__(v40, 1) - 1), 0xFFFFFFFF);
  return (idPathCorner *)*(&a27 + v40 % v31);
}


// ========================================================================
// ?Event_RandomPath@idPathCorner@@AAA?AVeventEntity@@XZ
// EA  : 0x82C74190
// RVA : 0x00C74190
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idPathCorner *__fastcall idPathCorner::Event_RandomPath(
        idPathCorner *this,
        const idEntity *result,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idPathCorner *v9; // r3
  int v11; // [sp+8h] [-58h]
  int v12; // [sp+Ch] [-54h]
  int v13; // [sp+10h] [-50h]
  int v14; // [sp+14h] [-4Ch]
  int v15; // [sp+18h] [-48h]
  int v16; // [sp+1Ch] [-44h]
  int v17; // [sp+20h] [-40h]
  int v18; // [sp+24h] [-3Ch]
  int v19; // [sp+28h] [-38h]
  int v20; // [sp+2Ch] [-34h]
  int v21; // [sp+30h] [-30h]
  int v22; // [sp+34h] [-2Ch]
  int v23; // [sp+38h] [-28h]
  int v24; // [sp+3Ch] [-24h]
  int v25; // [sp+40h] [-20h]
  int v26; // [sp+44h] [-1Ch]
  int v27; // [sp+48h] [-18h]
  int v28; // [sp+4Ch] [-14h]
  int v29; // [sp+50h] [-10h]
  int v30; // [sp+54h] [-Ch]

  v9 = idPathCorner::RandomPath(
         source: result,
         ignore: nullptr,
         a3,
         a4,
         a5,
         a6,
         a7,
         a8,
         a9: v11,
         a10: v12,
         a11: v13,
         a12: v14,
         a13: v15,
         a14: v16,
         a15: v17,
         a16: v18,
         a17: v19,
         a18: v20,
         a19: v21,
         a20: v22,
         a21: v23,
         a22: v24,
         a23: v25,
         a24: v26,
         a25: v27,
         a26: v28,
         a27: v29,
         a28: v30);
  eventEntity::eventEntity((eventEntity *)this, e: v9);
  return this;
}


// ========================================================================
// ?Spawn@idParticleEmitter@@QAAXXZ
// EA  : 0x82C741D8
// RVA : 0x00C741D8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idParticleEmitter::Spawn(idParticleEmitter *this)
{
  BOOL useSmokeSystem; // r11

  if ( !this->useSmokeSystem )
    idParticleEmitter::SetParticle(this, particleDecl: this->particleSystem);
  if ( this->startOff )
  {
    this->hidden = true;
    idEntity::FreeRenderModel(this);
    idEntity::UpdateVisuals(this);
  }
  else
  {
    useSmokeSystem = this->useSmokeSystem;
    this->hidden = false;
    if ( useSmokeSystem )
      idEntity::BecomeActive(this, flags: 1);
    idParticleEmitter::UpdatePresentable(this);
  }
}


// ========================================================================
// ?Event_TriggerShow@idParticleEmitter@@AAA?AVeventVoid@@XZ
// EA  : 0x82C74278
// RVA : 0x00C74278
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idParticleEmitter *__fastcall idParticleEmitter::Event_TriggerShow(idParticleEmitter *this, idParticleEmitter *result)
{
  idPresentable *presentable; // r11
  char v5; // r11
  bool v6; // zf
  idPresentable *v7; // r3
  char v8; // r11
  int GameMs; // r3
  idPresentable *v10; // r11
  double v11; // fp30
  int v12; // r8
  int v13; // r7
  idPresentable *v14; // r11
  idCodeResource<idDeclRenderParm> *v15; // r9
  int z_low; // r10
  __int128 v17; // r6
  int v18; // r7
  idPresentable *v19; // r11
  idPresentable *v20; // r11
  const idDeclRenderParm *r; // r30
  idPresentable *v22; // r3
  double fadeIn; // fp13
  idPresentable *v24; // r3
  idPresentable *v25; // r3
  int v26; // r30
  __int64 v28; // [sp+8h] [-98h]
  __int64 v29; // [sp+8h] [-98h]
  __int64 v30; // [sp+10h] [-90h]
  __int64 v31; // [sp+10h] [-90h]
  __int64 v32; // [sp+18h] [-88h]
  __int64 v33; // [sp+18h] [-88h]
  __int64 v34; // [sp+20h] [-80h]
  __int64 v35; // [sp+20h] [-80h]
  __int64 v36; // [sp+28h] [-78h]
  __int64 v37; // [sp+28h] [-78h]
  float v38; // [sp+50h] [-50h] BYREF
  float v39; // [sp+54h] [-4Ch] BYREF
  int v40; // [sp+58h] [-48h] BYREF
  unsigned __int64 v41; // [sp+60h] [-40h]

  result->Show(this: result);
  if ( result->useSmokeSystem )
  {
    idEntity::BecomeActive(this: result, flags: 1);
  }
  else
  {
    presentable = result->presentable;
    if ( presentable == nullptr || (v6 = presentable->model != nullptr, v5 = 1, !v6) )
      v5 = 0;
    if ( v5 == 0 )
      idParticleEmitter::SetParticle(this: result, particleDecl: result->particleSystem);
  }
  v7 = result->presentable;
  if ( v7 == nullptr || (v8 = 1, v7->model == nullptr) )
    v8 = 0;
  if ( v8 != 0 )
  {
    if ( v7 == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      v7 = result->presentable;
    }
    idPresentable::SetParm(this: v7, parm: rp->TimeStop, scalar: 0.0);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v10 = result->presentable;
    v41 = __PAIR64__(&unk_82390000, GameMs);
    v11 = (float)((float)__SPAIR64__(&unk_82390000, GameMs) * (float)0.001);
    if ( v10 == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      v10 = result->presentable;
    }
    idPresentable::SetParm(this: v10, parm: rp->TimeOffset, scalar: v11);
    v14 = result->presentable;
    v15 = &rpParticleScale_1;
    if ( v14 == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      v14 = result->presentable;
    }
    z_low = LODWORD(result->distributionScale.z);
    *(_QWORD *)((char *)&v17 + 4) = *(_QWORD *)&result->distributionScale.x;
    LODWORD(v17) = __ROL4__(z_low, 32);
    idPresentable::SetParm(
      this: v14,
      parm: (const idDeclRenderParm *)LODWORD(result->distributionScale.x),
      v3: v17,
      a4: v13,
      a5: v12,
      a6: (int)v15,
      a7: z_low,
      a8: v28,
      a9: v30,
      a10: v32,
      a11: v34,
      a12: v36);
    v19 = result->presentable;
    if ( v19 == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      v19 = result->presentable;
    }
    idPresentable::SetParm(
      this: v19,
      parm: (const idDeclRenderParm *)LODWORD(vec3_origin.x),
      v3: __SPAIR64__(LODWORD(vec3_origin.y), __ROL4__(LODWORD(vec3_origin.z), 32)),
      a4: v18,
      a5: SLODWORD(vec3_origin.z),
      a6: (int)&vec3_origin,
      a7: (int)allocationCurrent[242],
      a8: v29,
      a9: v31,
      a10: v33,
      a11: v35,
      a12: v37);
    v20 = result->presentable;
    r = (const idDeclRenderParm *)rpParticleAlphaScale_1.r;
    if ( v20 == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      v20 = result->presentable;
    }
    idPresentable::SetParm(this: v20, parm: r, scalar: (float)((float)1.0 / result->alphaScale));
    if ( result->fadeIn != 0.0 )
    {
      v22 = result->presentable;
      if ( v22 == nullptr )
      {
        idEntity::InitPresentableInternal(this: result);
        v22 = result->presentable;
      }
      idPresentable::SetParm(this: v22, parm: rp->coverage, scalar: 0.0);
      fadeIn = result->fadeIn;
      v38 = 1.0;
      v39 = 0.0;
      LODWORD(v41) = (int)(float)((float)fadeIn * (float)1000.0);
      v40 = v41;
      idFadeHelper::Fade(this: &result->fade, from: &v39, to: &v38, time: &v40, _noStippleFade: false);
      idEntity::BecomeActive(this: result, flags: 1);
    }
    v24 = result->presentable;
    if ( v24 == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      v24 = result->presentable;
    }
    v24->Present(this: v24);
    v25 = result->presentable;
    if ( v25 == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      v25 = result->presentable;
    }
    v26 = (int)v25->GetParticleEmitterInterface(this: v25);
    idParticleEmitter::UpdatePresentable(this: result);
    if ( common->IsMultiplayer(this: common) && v26 != 0 )
      (*(void (__fastcall **)(int))(*(_DWORD *)v26 + 324))(a1: v26);
  }
  result->ActivateTargets(this: result, a2: result);
  return this;
}


// ========================================================================
// ?UpdateModifiedProperties@idParticleEmitter@@UAAXXZ
// EA  : 0x82C745C8
// RVA : 0x00C745C8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idParticleEmitter::UpdateModifiedProperties(idParticleEmitter *this)
{
  idPresentable *presentable; // r3
  char v3; // r11
  int GameMs; // r3
  idPresentable *v5; // r11
  double v6; // fp31
  int v7; // r8
  int v8; // r7
  idPresentable *v9; // r11
  idCodeResource<idDeclRenderParm> *v10; // r9
  int z_low; // r10
  __int128 v12; // r6
  int v13; // r7
  idPresentable *v14; // r11
  idPresentable *v15; // r11
  const idDeclRenderParm *r; // r30
  __int64 v17; // [sp+8h] [-78h]
  __int64 v18; // [sp+8h] [-78h]
  __int64 v19; // [sp+10h] [-70h]
  __int64 v20; // [sp+10h] [-70h]
  __int64 v21; // [sp+18h] [-68h]
  __int64 v22; // [sp+18h] [-68h]
  __int64 v23; // [sp+20h] [-60h]
  __int64 v24; // [sp+20h] [-60h]
  __int64 v25; // [sp+28h] [-58h]
  __int64 v26; // [sp+28h] [-58h]

  idEntity::FreeRenderModel(this);
  idParticleEmitter::SetParticle(this, particleDecl: this->particleSystem);
  presentable = this->presentable;
  if ( presentable == nullptr || (v3 = 1, presentable->model == nullptr) )
    v3 = 0;
  if ( v3 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::SetParm(this: presentable, parm: rp->TimeStop, scalar: 0.0);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v5 = this->presentable;
    v6 = (float)((float)__SPAIR64__(&unk_82390000, GameMs) * (float)0.001);
    if ( v5 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v5 = this->presentable;
    }
    idPresentable::SetParm(this: v5, parm: rp->TimeOffset, scalar: v6);
    v9 = this->presentable;
    v10 = &rpParticleScale_1;
    if ( v9 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v9 = this->presentable;
    }
    z_low = LODWORD(this->distributionScale.z);
    *(_QWORD *)((char *)&v12 + 4) = *(_QWORD *)&this->distributionScale.x;
    LODWORD(v12) = __ROL4__(z_low, 32);
    idPresentable::SetParm(
      this: v9,
      parm: (const idDeclRenderParm *)LODWORD(this->distributionScale.x),
      v3: v12,
      a4: v8,
      a5: v7,
      a6: (int)v10,
      a7: z_low,
      a8: v17,
      a9: v19,
      a10: v21,
      a11: v23,
      a12: v25);
    v14 = this->presentable;
    if ( v14 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v14 = this->presentable;
    }
    idPresentable::SetParm(
      this: v14,
      parm: (const idDeclRenderParm *)LODWORD(vec3_origin.x),
      v3: __SPAIR64__(LODWORD(vec3_origin.y), __ROL4__(LODWORD(vec3_origin.z), 32)),
      a4: v13,
      a5: SLODWORD(vec3_origin.z),
      a6: (int)&vec3_origin,
      a7: (int)allocationCurrent[242],
      a8: v18,
      a9: v20,
      a10: v22,
      a11: v24,
      a12: v26);
    v15 = this->presentable;
    r = (const idDeclRenderParm *)rpParticleAlphaScale_1.r;
    if ( v15 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v15 = this->presentable;
    }
    idPresentable::SetParm(this: v15, parm: r, scalar: (float)((float)1.0 / this->alphaScale));
  }
}


// ========================================================================
// ?GetNextTarget@idElectricBoltEmitter@@AAAPAVidEntity@@XZ
// EA  : 0x82C747F0
// RVA : 0x00C747F0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idEntity *__fastcall idElectricBoltEmitter::GetNextTarget(idElectricBoltEmitter *this)
{
  signed int num; // r11
  unsigned int v2; // r5
  int v3; // r4
  int v4; // r9
  unsigned int v5; // r5
  int v6; // r11
  int value; // r9
  idEntity *v8; // r3

  num = this->targets.num;
  if ( num == 0 )
    return nullptr;
  __twllei(num, 0);
  v2 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v2;
  v3 = this->targets.num;
  v4 = (v2 >> 10) & 0x7FFF;
  v5 = num & ~(__ROL4__(v4, 1) - 1);
  v6 = v4 % num;
  __twlgei(v5, 0xFFFFFFFF);
  if ( v6 >= v3 )
    return nullptr;
  value = this->targets.list[v6].spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[this->targets.list[v6].spawnId.value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v8);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?ResetTarget@idElectricBoltEmitter@@AAAXXZ
// EA  : 0x82C748D0
// RVA : 0x00C748D0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idElectricBoltEmitter::ResetTarget(idElectricBoltEmitter *this)
{
  idAI2 *NextTarget; // r27
  idPhysics *Physics; // r25
  __int64 v4; // r9
  unsigned int v5; // r6
  double v6; // fp31
  int GameMs; // r24
  const idVec3 *v8; // r3
  int v9; // r3
  int maxResetTime; // r9
  int minResetTime; // r11
  signed int v12; // r5
  unsigned int v13; // r4
  int v14; // r9
  idVec3 v15[2]; // [sp+58h] [-68h] BYREF

  if ( this->ebolt != nullptr )
  {
    NextTarget = (idAI2 *)idElectricBoltEmitter::GetNextTarget(this);
    idElectricBoltEmitter::GetNextEndPos(this: (idElectricBoltEmitter *)v15, result: this, target: NextTarget);
    Physics = idEntity::GetPhysics(this);
    HIDWORD(v4) = &off_822E0000;
    v5 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v5 + 1013904223;
    LODWORD(v4) = ((v5 + 1013904223) >> 10) & 0x7FFF;
    v6 = (float)((float)v4 * (float)0.000030518509);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v8 = Physics->GetOrigin(this: Physics, a2: 0);
    idElectricBolt::StartElectricBolt(
      this: this->ebolt,
      _startTime: GameMs,
      _startPos: v8,
      _endPos: v15,
      _diversity: v6);
    v9 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    maxResetTime = this->maxResetTime;
    minResetTime = this->minResetTime;
    if ( minResetTime < maxResetTime )
    {
      v12 = maxResetTime - minResetTime + 1;
      v13 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v13;
      __twllei(v12, 0);
      v14 = (v13 >> 10) & 0x7FFF;
      __twlgei(v12 & ~(__ROL4__(v14, 1) - 1), 0xFFFFFFFF);
      minResetTime += v14 % v12;
    }
    this->nextResetTime = minResetTime + v9;
    if ( NextTarget != nullptr )
      NextTarget->ActivateTargets(this: NextTarget, a2: this);
  }
}


// ========================================================================
// ?Spawn@idLensFlare@@QAAXXZ
// EA  : 0x82C74A48
// RVA : 0x00C74A48
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idLensFlare::Spawn(idLensFlare *this)
{
  const idSoundShader *sunGlareSnd; // r5

  if ( this->startOff )
  {
    idEntity::FreeRenderModel(this);
    idEntity::UpdateVisuals(this);
  }
  else
  {
    idLensFlare::SetFlare(this);
    idEntity::BecomeActive(this, flags: 1);
  }
  if ( ((LODWORD(this->sunDirection.y) | LODWORD(this->sunDirection.z) | LODWORD(this->sunDirection.x)) & 0x7FFFFFFF) == 0 )
    *(_BYTE *)&this->flags |= 0x40u;
  if ( ((LODWORD(this->sunDirection.y) | LODWORD(this->sunDirection.z) | LODWORD(this->sunDirection.x)) & 0x7FFFFFFF) != 0 )
  {
    sunGlareSnd = this->sunGlareSnd;
    if ( sunGlareSnd != nullptr )
    {
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_AMBIENT,
        shader: sunGlareSnd,
        parms: &sunGlareSnd->parms,
        peerMask: 0xFFu);
      idEntity::SetSoundVolume(this, channel: SND_CHANNEL_AMBIENT, volume: -60.0);
    }
  }
}


// ========================================================================
// ?Think@idLensFlare@@UAAXXZ
// EA  : 0x82C74B20
// RVA : 0x00C74B20
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idLensFlare::Think(idLensFlare *this)
{
  idPhysics *Physics; // r3
  float *v3; // r3
  double v4; // fp3
  double v5; // fp7
  double v6; // fp5
  double v7; // fp1
  double v8; // fp0
  idPhysics *v9; // r30
  idPhysics *v10; // r27
  int GameMs; // r26
  idLensFlareManager *p_flareManager; // r30
  int v13; // r3
  const idMat3 *v14; // r25
  const idVec3 *v15; // r3
  __int64 v16; // r11
  bool v17; // r4
  double v18; // fp1
  int i; // r24
  idPlayer *Player; // r3
  idPlayer *v21; // r30
  idPresentable *presentable; // r3
  int v23; // r11
  float y; // r8
  float z; // r7
  float v26; // r6
  float v27; // r4
  __int64 v28; // r10
  int v29; // r5
  double v30; // fp1
  double v31; // fp29
  idPresentable *v32; // r3
  idRenderModelFlareOcclusionQuad *flareOcclusionQuadModel; // r29
  int v34; // r30
  int v35; // r5
  idPresentable *v36; // r3
  double v37; // fp30
  int v38; // r3
  double v39; // fp30
  int v42; // r28
  int v43; // r29
  int value; // r9
  idEntity *v45; // r3
  idEntity *v46; // r3
  idRenderModel *RenderModelFromPresentable; // r3
  idRenderModel *v48; // r30
  idVec3 v49; // [sp+58h] [-D8h] BYREF
  float v50; // [sp+68h] [-C8h]
  float v51; // [sp+6Ch] [-C4h]
  float v52; // [sp+70h] [-C0h]
  idBounds v53; // [sp+80h] [-B0h] BYREF

  if ( (unsigned __int8)idEntity::UpdateDormant(this) == 0 )
  {
    idEntity::RunPhysics(this);
    this->UpdateFX(this);
    if ( this->flareManager.flareOcclusionQuadModel != nullptr )
    {
      Physics = idEntity::GetPhysics(this);
      v3 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v4 = (float)(*v3 + this->flareManager.flareOcclusionQuadModel->referenceBounds.b[0].x);
      v5 = (float)(this->flareManager.flareOcclusionQuadModel->referenceBounds.b[1].y + v3[1]);
      v6 = (float)(this->flareManager.flareOcclusionQuadModel->referenceBounds.b[1].z + v3[2]);
      v7 = (float)(this->flareManager.flareOcclusionQuadModel->referenceBounds.b[0].y + v3[1]);
      v8 = (float)(this->flareManager.flareOcclusionQuadModel->referenceBounds.b[0].z + v3[2]);
      v53.b[1].x = *v3 + this->flareManager.flareOcclusionQuadModel->referenceBounds.b[1].x;
      v53.b[1].y = v5;
      v53.b[1].z = v6;
      v53.b[0].x = v4;
      v53.b[0].y = v7;
      v53.b[0].z = v8;
      idEntity::UpdatePVSAreas(this, bounds: &v53);
    }
    if ( (this->thinkFlags & 1) != 0 )
    {
      v9 = idEntity::GetPhysics(this);
      v10 = idEntity::GetPhysics(this);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v13 = (int)v9->GetAxis(this: v9, a2: 0);
      p_flareManager = &this->flareManager;
      v14 = (const idMat3 *)v13;
      v15 = v10->GetOrigin(this: v10, a2: 0);
      idLensFlareManager::Update(
        this: &this->flareManager,
        org: v15,
        axis: v14,
        time: GameMs,
        bindOrg: true,
        bindAxis: true);
      if ( this->colorModulateTbl != nullptr && p_flareManager->flareRenderModel != nullptr )
      {
        LODWORD(v16) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        HIDWORD(v16) = this->colorModulateTbl;
        v18 = idLookupTable::TableLookup(
                this: *(idLookupTable **)(HIDWORD(v16) + 64),
                time: (float)((float)((float)v16 * (float)0.001) * this->modulateTimeScale),
                fastSearch: v17);
        idRenderModel::SetParm(this: p_flareManager->flareRenderModel, parm: rp->lightScale, scalar: v18);
        idRenderModel::CommitThisFrame(this: p_flareManager->flareRenderModel);
      }
      if ( ((LODWORD(this->sunDirection.z) | LODWORD(this->sunDirection.y) | LODWORD(this->sunDirection.x)) & 0x7FFFFFFF) != 0 )
      {
        for ( i = 0; i < 6; ++i )
        {
          Player = idGameLocal::GetPlayer(this: gameLocal, i);
          v21 = Player;
          if ( Player != nullptr )
          {
            if ( this->flareManager.flareOcclusionQuadModel != nullptr )
            {
              presentable = Player->presentable;
              if ( presentable != nullptr )
                v23 = (int)presentable->GetPlayerInterface_2(this: presentable);
              else
                v23 = 0;
              y = this->sunDirection.y;
              z = this->sunDirection.z;
              v26 = *(float *)(v23 + 46544);
              v49.x = this->sunDirection.x;
              v49.y = y;
              v49.z = z;
              v27 = *(float *)(v23 + 46552);
              v51 = *(float *)(v23 + 46548);
              v50 = v26;
              v52 = v27;
              v30 = idVec3::NormalizeFast(this: &v49);
              v31 = (float)((float)(v49.x * v50) + (float)((float)(v51 * v49.y) + (float)(v52 * v49.z)));
              if ( this->sunGlareEnv != nullptr )
              {
                if ( v31 > this->sunGlareEnvDotThreshold
                  && idRenderModel::IsRendered(this: this->flareManager.flareOcclusionQuadModel) )
                {
                  if ( !this->sunGlareEnvActive )
                  {
                    v32 = v21->presentable;
                    flareOcclusionQuadModel = this->flareManager.flareOcclusionQuadModel;
                    if ( v32 != nullptr )
                      v34 = (int)v32->GetPlayerInterface_2(this: v32);
                    else
                      v34 = 0;
                    idRenderModel::GetIndex(this: flareOcclusionQuadModel);
                    idView::SetEnvironmentOverride(
                      this: (idView *)(v34 + 16224),
                      env: this->sunGlareEnv,
                      blendDuration: -1.0,
                      modelIndex: v35);
                    this->sunGlareEnvActive = true;
                  }
                }
                else if ( this->sunGlareEnvActive )
                {
                  v36 = v21->presentable;
                  LODWORD(v28) = this->sunGlareEnvFadeOutTime;
                  v37 = (float)((float)v28 * 0.001);
                  if ( v36 != nullptr )
                    v38 = ((int (__fastcall *)(idPresentable *, double))v36->GetPlayerInterface_2)(a1: v36, a2: v30);
                  else
                    v38 = 0;
                  idView::SetEnvironmentOverride(
                    this: (idView *)(v38 + 16224),
                    env: nullptr,
                    blendDuration: v37,
                    modelIndex: v29);
                  this->sunGlareEnvActive = false;
                }
              }
              if ( this->targets.num > 0 )
              {
                v39 = 1.0;
                if ( idRenderModel::IsRendered(this: this->flareManager.flareOcclusionQuadModel)
                  && this->sunGlareEnvDotThreshold < 1.0 )
                {
                  _FP9 = (float)((float)__fabs(v31) - this->sunGlareEnvDotThreshold);
                  __asm { fsel      f8, f9, f9, f28 }
                  v39 = (float)((float)((float)((float)_FP8 / (float)((float)1.0 - this->sunGlareEnvDotThreshold))
                                      * (float)(this->maxSunGlareScale - (float)1.0))
                              + (float)1.0);
                }
                v42 = 0;
                if ( this->targets.num > 0 )
                {
                  v43 = 0;
                  do
                  {
                    if ( v42 < this->targets.num
                      && (value = this->targets.list[v43].spawnId.value,
                          gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
                      && (v45 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
                    {
                      v46 = idEntity::CastTo(c: v45);
                    }
                    else
                    {
                      v46 = nullptr;
                    }
                    if ( v46 != nullptr && v46->presentable != nullptr )
                    {
                      RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: v46);
                      v48 = RenderModelFromPresentable;
                      if ( RenderModelFromPresentable != nullptr )
                      {
                        idRenderModel::SetParm(
                          this: RenderModelFromPresentable,
                          parm: (const idDeclRenderParm *)rp_exposure.r,
                          scalar: v39);
                        idRenderModel::CommitThisFrame(this: v48);
                      }
                    }
                    ++v42;
                    ++v43;
                  }
                  while ( v42 < this->targets.num );
                }
              }
            }
            idEntity::SetSoundVolume(this, channel: SND_CHANNEL_AMBIENT, volume: -60.0);
            idEntity::SetSoundPitch(this, channel: SND_CHANNEL_AMBIENT, pitch: 0.0);
          }
        }
      }
    }
  }
}


// ========================================================================
// ??0idFuncCloth@@QAA@XZ
// EA  : 0x82C75058
// RVA : 0x00C75058
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idFuncCloth *__fastcall idFuncCloth::idFuncCloth(idFuncCloth *this)
{
  idEntity::idEntity(this);
  this->clothType = CLOTH_GENERATED;
  this->__vftable = (idFuncCloth_vtbl *)&idFuncCloth::`vftable';
  this->attachPoints.list = nullptr;
  this->attachPoints.granularity = 0;
  this->attachPoints.memTag = 5;
  this->attachPoints.listStatic = 0;
  this->attachPoints.size = 0;
  this->attachPoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->attachPoints);
  this->clothSystem = nullptr;
  this->widthOverride = 0;
  this->heightOverride = 0;
  this->hSpacingOverride = 0.0;
  this->vSpacingOverride = 0.0;
  this->sphereCollision.list = nullptr;
  this->sphereCollision.granularity = 0;
  this->sphereCollision.memTag = 5;
  this->sphereCollision.listStatic = 0;
  this->sphereCollision.size = 0;
  this->sphereCollision.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sphereCollision);
  this->collidesWithPlayers = true;
  *(_WORD *)&this->collidesWithAI = 1;
  this->influencedByBullets = true;
  this->clothModel = nullptr;
  this->clipModelInfo.type = CLIPMODEL_NONE;
  return this;
}


// ========================================================================
// __unwind$502651
// EA  : 0x82C75110
// RVA : 0x00C75110
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_502651()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$502652
// EA  : 0x82C75138
// RVA : 0x00C75138
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_502652()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 804));
}


// ========================================================================
// ??1idFuncCloth@@UAA@XZ
// EA  : 0x82C75170
// RVA : 0x00C75170
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idFuncCloth::~idFuncCloth(idFuncCloth *this)
{
  idRenderModelCloth *clothModel; // r3

  this->__vftable = (idFuncCloth_vtbl *)&idFuncCloth::`vftable';
  clothModel = this->clothModel;
  if ( clothModel != nullptr )
  {
    clothModel->unlinked = true;
    clothModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: clothModel);
    this->clothModel = nullptr;
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sphereCollision);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->attachPoints);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$502686
// EA  : 0x82C751F4
// RVA : 0x00C751F4
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_502686()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$502687
// EA  : 0x82C7521C
// RVA : 0x00C7521C
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_502687()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 804));
}


// ========================================================================
// __unwind$502688
// EA  : 0x82C75248
// RVA : 0x00C75248
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_502688()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 840));
}


// ========================================================================
// ??1idRegimeTile@@UAA@XZ
// EA  : 0x82C75280
// RVA : 0x00C75280
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idRegimeTile::~idRegimeTile(idRegimeTile *this)
{
  int v2; // r28
  int v3; // r29
  idPresentable *presentable; // r3
  idRegimeTileChild_t *list; // r4

  this->__vftable = (idRegimeTile_vtbl *)&idRegimeTile::`vftable';
  if ( this->damageable )
  {
    this->controlNode.prev->next = this->controlNode.next;
    this->controlNode.next->prev = this->controlNode.prev;
    this->controlNode.next = &this->controlNode;
    this->controlNode.prev = &this->controlNode;
    this->controlNode.head = &this->controlNode;
  }
  v2 = 0;
  if ( this->tileChildren.num > 0 )
  {
    v3 = 0;
    do
    {
      presentable = this->tileChildren.list[v3].presentable;
      if ( presentable != nullptr )
      {
        idPresentable::Delete(this: presentable);
        this->tileChildren.list[v3].presentable = nullptr;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->tileChildren.num );
  }
  if ( this->tileChildren.listStatic == 0 || this->tileChildren.listStatic == 2 )
  {
    list = this->tileChildren.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->tileChildren.list = nullptr;
    this->tileChildren.size = 0;
  }
  this->tileChildren.num = 0;
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->controlNode);
  this->__vftable = (idRegimeTile_vtbl *)&idDynamicEntity::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$502731
// EA  : 0x82C75384
// RVA : 0x00C75384
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_502731()
{
  int v0; // r12

  idDynamicEntity::~idDynamicEntity(this: *(idDynamicEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$502732
// EA  : 0x82C753AC
// RVA : 0x00C753AC
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_502732()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                           + 928));
}


// ========================================================================
// __unwind$502733
// EA  : 0x82C753D8
// RVA : 0x00C753D8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_502733()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 948));
}


// ========================================================================
// ?OnActivate@idRegimeTile@@EAAXPAVidEntity@@@Z
// EA  : 0x82C75408
// RVA : 0x00C75408
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idRegimeTile::OnActivate(idRegimeTile *this, idEntity *activator, __int64 a3, __int64 a4, __int64 a5)
{
  va *v6; // r3
  BOOL powered; // r11
  const idEventDef *v8; // r4
  int v9; // [sp+8h] [-1058h]
  int v10; // [sp+Ch] [-1054h]
  int v11; // [sp+10h] [-1050h]
  int v12; // [sp+14h] [-104Ch]
  int v13; // [sp+18h] [-1048h]
  int v14; // [sp+1Ch] [-1044h]
  va v15; // [sp+50h] [-1010h] BYREF

  LODWORD(a5) = &g_DebugRegimeTiles;
  if ( g_DebugRegimeTiles.valueInteger != 0 )
  {
    HIDWORD(a3) = this->name.data;
    v6 = va::va(
           this: &v15,
           fmt: "Activating idRegimeTile %s =========================\n",
           a3,
           a4,
           a5,
           a6: v9,
           a7: v10,
           a8: v11,
           a9: v12,
           a10: v13,
           a11: v14);
    idLib::Printf(fmt: v6->buffer);
  }
  powered = this->powered;
  this->nextActivateIdx = 0;
  if ( powered )
  {
    idRegimeTile::TurnOff(this);
    if ( this->tileChildren.num <= 0 )
      return;
    v8 = &EV_PowerDown;
  }
  else
  {
    idRegimeTile::TurnOn(this);
    if ( this->tileChildren.num <= 0 )
      return;
    v8 = &EV_PowerUp;
  }
  idEventReceiver::PostEventMS(this, ev: v8, time: this->propogationDelay);
}


// ========================================================================
// ?Event_PowerDown@idRegimeTile@@AAA?AVeventVoid@@XZ
// EA  : 0x82C754B8
// RVA : 0x00C754B8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idRegimeTile *__fastcall idRegimeTile::Event_PowerDown(idRegimeTile *this, idEntity *result)
{
  int r_low; // r4
  char v5; // r11
  int num; // r11
  int v8; // r27
  int v9; // r23
  int v10; // r29
  int v11; // r11
  int v12; // r9
  __int64 v13; // r8
  idEntity *v14; // r3
  int v15; // r30
  __int64 v16; // r10
  __int64 v17; // r8
  idEntity *v18; // r3
  idEntity *v19; // r3
  __int64 v20; // r6
  va *v21; // r3
  int v22; // r9
  idEntity *v23; // r3
  idEntity *v24; // r30
  idEventArg *v25; // r3
  _DWORD *v26; // r11
  __int64 v27; // r10
  __int64 v28; // r6
  va *v29; // r3
  int v30; // r11
  float r; // r11
  int v32; // [sp+8h] [-1178h]
  int v33; // [sp+Ch] [-1174h]
  int v34; // [sp+10h] [-1170h]
  int v35; // [sp+14h] [-116Ch]
  int v36; // [sp+18h] [-1168h]
  int v37; // [sp+1Ch] [-1164h]
  idEventArg v38; // [sp+50h] [-1130h] BYREF
  soundShaderParms_t v39; // [sp+70h] [-1110h] BYREF
  va v40; // [sp+110h] [-1070h] BYREF

  if ( g_DebugRegimeTiles.valueInteger != 0 )
    idLib::Printf(fmt: "Event_PowerDown() =========================\n");
  r_low = LODWORD(result[1].renderModelInfo.color.r);
  if ( r_low <= 0 || (v5 = 1, result[1].renderModelInfo.renderParms.num >= r_low) )
    v5 = 0;
  if ( v5 != 0 )
  {
    num = result[1].renderModelInfo.renderParms.num;
    v8 = num;
    v9 = *(_DWORD *)(20 * num + LODWORD(result[1].renderModelInfo.scale.z) + 8);
    if ( num < r_low )
    {
      v10 = 20 * num;
      do
      {
        v11 = v10 + LODWORD(result[1].renderModelInfo.scale.z);
        if ( *(_DWORD *)(v11 + 8) != v9 )
          break;
        v12 = *(_DWORD *)(v11 + 4);
        LODWORD(v13) = v12 >> 13;
        if ( gameLocal->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13
          && (v14 = gameLocal->entities.ptr[v12 & 0x1FFF]) != nullptr
          && idEntity::CastTo(c: v14) != nullptr )
        {
          if ( g_DebugRegimeTiles.valueInteger != 0 )
          {
            LODWORD(v16) = gameLocal;
            v15 = v10 + LODWORD(result[1].renderModelInfo.scale.z);
            HIDWORD(v16) = *(_DWORD *)(v15 + 4);
            LODWORD(v17) = (WORD1(v16) & 0x1FFF) + 29755;
            if ( *((_DWORD *)&gameLocal->__vftable + v17) == SHIDWORD(v16) >> 13
              && (HIDWORD(v16) = 4 * ((WORD1(v16) & 0x1FFF) + 21563),
                  (v18 = *(idEntity **)((char *)&gameLocal->__vftable + HIDWORD(v16))) != nullptr) )
            {
              v19 = idEntity::CastTo(c: v18);
            }
            else
            {
              v19 = nullptr;
            }
            LODWORD(v20) = v19->name.data;
            HIDWORD(v20) = v8;
            HIDWORD(v17) = *(_DWORD *)(v15 + 8);
            v21 = va::va(
                    this: &v40,
                    fmt: "\t%d: Powering Down Entity %s at %d\n",
                    a3: v20,
                    a4: v17,
                    a5: v16,
                    a6: v32,
                    a7: v33,
                    a8: v34,
                    a9: v35,
                    a10: v36,
                    a11: v37);
            idLib::Printf(fmt: v21->buffer);
          }
          v22 = *(_DWORD *)(v10 + LODWORD(result[1].renderModelInfo.scale.z) + 4);
          if ( gameLocal->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13
            && (v23 = gameLocal->entities.ptr[*(_DWORD *)(v10 + LODWORD(result[1].renderModelInfo.scale.z) + 4) & 0x1FFF]) != nullptr )
          {
            v24 = idEntity::CastTo(c: v23);
          }
          else
          {
            v24 = nullptr;
          }
          v25 = idEventArg::idEventArg(this: &v38, data: result);
          idEventReceiver::PostEventMS(
            this: v24,
            ev: &EV_Activate,
            time: *(_DWORD *)&v25->type,
            arg1: (const idEventArg *)LODWORD(v25->value.v[1]));
        }
        else
        {
          v26 = (_DWORD *)(v10 + LODWORD(result[1].renderModelInfo.scale.z));
          if ( *v26 == 0 )
            return this;
          if ( g_DebugRegimeTiles.valueInteger != 0 )
          {
            LODWORD(v27) = *v26;
            HIDWORD(v28) = v8;
            HIDWORD(v13) = v26[2];
            HIDWORD(v27) = *(_DWORD *)(*v26 + 168);
            LODWORD(v28) = *(_DWORD *)(HIDWORD(v27) + 16);
            v29 = va::va(
                    this: &v40,
                    fmt: "\t%d: Powering Rendermodel %s at %d\n",
                    a3: v28,
                    a4: v13,
                    a5: v27,
                    a6: v32,
                    a7: v33,
                    a8: v34,
                    a9: v35,
                    a10: v36,
                    a11: v37);
            idLib::Printf(fmt: v29->buffer);
          }
          (*(void (__fastcall **)(_DWORD, int))(**(_DWORD **)(v10 + LODWORD(result[1].renderModelInfo.scale.z)) + 196))(
            a1: *(_DWORD *)(v10 + LODWORD(result[1].renderModelInfo.scale.z)),
            a2: 1);
          v30 = v10 + LODWORD(result[1].renderModelInfo.scale.z);
          if ( *(_DWORD *)(v30 + 12) != 0 && *(_DWORD *)(*(_DWORD *)v30 + 1060) != 0 )
          {
            idPresentable::StopSound(this: *(idPresentable **)v30, channel: SND_CHANNEL_ANY, peerMask: 0);
            soundShaderParms_t::Clear(this: &v39);
            v39.soundShaderFlags = 0;
            idPresentable::StartSoundShader(
              this: *(idPresentable **)(v10 + LODWORD(result[1].renderModelInfo.scale.z)),
              channel: SND_CHANNEL_AMBIENT,
              shader: *(const idSoundShader **)(v10 + LODWORD(result[1].renderModelInfo.scale.z) + 12),
              parms: &v39,
              peerMask: 0);
          }
        }
        ++v8;
        v10 += 20;
      }
      while ( v8 < SLODWORD(result[1].renderModelInfo.color.r) );
    }
    r = result[1].renderModelInfo.color.r;
    result[1].renderModelInfo.renderParms.num = v8;
    if ( v8 < SLODWORD(r) )
      idEventReceiver::PostEventMS(
        this: result,
        ev: &EV_PowerDown,
        time: (int)result[1].renderModelInfo.renderParms.list);
    if ( g_DebugRegimeTiles.valueInteger != 0 )
      idLib::Printf(fmt: "=========================\n");
    return this;
  }
  else
  {
    idLib::Warning(
      fmt: "Failed to powerDown.  NumChildren = %d, nextActivateIdx = %d",
      r_low,
      result[1].renderModelInfo.renderParms.num);
    return this;
  }
}


// ========================================================================
// ?Event_PowerUp@idRegimeTile@@AAA?AVeventVoid@@XZ
// EA  : 0x82C757F8
// RVA : 0x00C757F8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idRegimeTile *__fastcall idRegimeTile::Event_PowerUp(idRegimeTile *this, idEntity *result)
{
  int r_low; // r4
  char v5; // r11
  int num; // r11
  int v8; // r27
  int v9; // r23
  int v10; // r29
  int v11; // r11
  int v12; // r9
  __int64 v13; // r8
  idEntity *v14; // r3
  int v15; // r30
  __int64 v16; // r10
  __int64 v17; // r8
  idEntity *v18; // r3
  idEntity *v19; // r3
  __int64 v20; // r6
  va *v21; // r3
  int v22; // r9
  idEntity *v23; // r3
  idEntity *v24; // r30
  idEventArg *v25; // r3
  _DWORD *v26; // r11
  __int64 v27; // r10
  __int64 v28; // r6
  va *v29; // r3
  int v30; // r11
  float r; // r11
  int v32; // [sp+8h] [-1178h]
  int v33; // [sp+Ch] [-1174h]
  int v34; // [sp+10h] [-1170h]
  int v35; // [sp+14h] [-116Ch]
  int v36; // [sp+18h] [-1168h]
  int v37; // [sp+1Ch] [-1164h]
  idEventArg v38; // [sp+50h] [-1130h] BYREF
  soundShaderParms_t v39; // [sp+70h] [-1110h] BYREF
  va v40; // [sp+110h] [-1070h] BYREF

  if ( g_DebugRegimeTiles.valueInteger != 0 )
    idLib::Printf(fmt: "Event_PowerUp() =========================\n");
  r_low = LODWORD(result[1].renderModelInfo.color.r);
  if ( r_low <= 0 || (v5 = 1, result[1].renderModelInfo.renderParms.num >= r_low) )
    v5 = 0;
  if ( v5 != 0 )
  {
    num = result[1].renderModelInfo.renderParms.num;
    v8 = num;
    v9 = *(_DWORD *)(20 * num + LODWORD(result[1].renderModelInfo.scale.z) + 8);
    if ( num < r_low )
    {
      v10 = 20 * num;
      do
      {
        v11 = v10 + LODWORD(result[1].renderModelInfo.scale.z);
        if ( *(_DWORD *)(v11 + 8) != v9 )
          break;
        v12 = *(_DWORD *)(v11 + 4);
        LODWORD(v13) = v12 >> 13;
        if ( gameLocal->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13
          && (v14 = gameLocal->entities.ptr[v12 & 0x1FFF]) != nullptr
          && idEntity::CastTo(c: v14) != nullptr )
        {
          if ( g_DebugRegimeTiles.valueInteger != 0 )
          {
            LODWORD(v16) = gameLocal;
            v15 = v10 + LODWORD(result[1].renderModelInfo.scale.z);
            HIDWORD(v16) = *(_DWORD *)(v15 + 4);
            LODWORD(v17) = (WORD1(v16) & 0x1FFF) + 29755;
            if ( *((_DWORD *)&gameLocal->__vftable + v17) == SHIDWORD(v16) >> 13
              && (HIDWORD(v16) = 4 * ((WORD1(v16) & 0x1FFF) + 21563),
                  (v18 = *(idEntity **)((char *)&gameLocal->__vftable + HIDWORD(v16))) != nullptr) )
            {
              v19 = idEntity::CastTo(c: v18);
            }
            else
            {
              v19 = nullptr;
            }
            LODWORD(v20) = v19->name.data;
            HIDWORD(v20) = v8;
            HIDWORD(v17) = *(_DWORD *)(v15 + 8);
            v21 = va::va(
                    this: &v40,
                    fmt: "\t%d: Powering Up Entity %s at %d\n",
                    a3: v20,
                    a4: v17,
                    a5: v16,
                    a6: v32,
                    a7: v33,
                    a8: v34,
                    a9: v35,
                    a10: v36,
                    a11: v37);
            idLib::Printf(fmt: v21->buffer);
          }
          v22 = *(_DWORD *)(v10 + LODWORD(result[1].renderModelInfo.scale.z) + 4);
          if ( gameLocal->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13
            && (v23 = gameLocal->entities.ptr[*(_DWORD *)(v10 + LODWORD(result[1].renderModelInfo.scale.z) + 4) & 0x1FFF]) != nullptr )
          {
            v24 = idEntity::CastTo(c: v23);
          }
          else
          {
            v24 = nullptr;
          }
          v25 = idEventArg::idEventArg(this: &v38, data: result);
          idEventReceiver::PostEventMS(
            this: v24,
            ev: &EV_Activate,
            time: *(_DWORD *)&v25->type,
            arg1: (const idEventArg *)LODWORD(v25->value.v[1]));
        }
        else
        {
          v26 = (_DWORD *)(v10 + LODWORD(result[1].renderModelInfo.scale.z));
          if ( *v26 == 0 )
            return this;
          if ( g_DebugRegimeTiles.valueInteger != 0 )
          {
            LODWORD(v27) = *v26;
            HIDWORD(v28) = v8;
            HIDWORD(v13) = v26[2];
            HIDWORD(v27) = *(_DWORD *)(*v26 + 168);
            LODWORD(v28) = *(_DWORD *)(HIDWORD(v27) + 16);
            v29 = va::va(
                    this: &v40,
                    fmt: "\t%d: Powering Rendermodel %s at %d\n",
                    a3: v28,
                    a4: v13,
                    a5: v27,
                    a6: v32,
                    a7: v33,
                    a8: v34,
                    a9: v35,
                    a10: v36,
                    a11: v37);
            idLib::Printf(fmt: v29->buffer);
          }
          (*(void (__fastcall **)(_DWORD))(**(_DWORD **)(v10 + LODWORD(result[1].renderModelInfo.scale.z)) + 200))(a1: *(_DWORD *)(v10 + LODWORD(result[1].renderModelInfo.scale.z)));
          v30 = v10 + LODWORD(result[1].renderModelInfo.scale.z);
          if ( *(_DWORD *)(v30 + 16) != 0 && *(_DWORD *)(*(_DWORD *)v30 + 1060) != 0 )
          {
            idPresentable::StopSound(this: *(idPresentable **)v30, channel: SND_CHANNEL_ANY, peerMask: 0);
            soundShaderParms_t::Clear(this: &v39);
            v39.soundShaderFlags = 0;
            idPresentable::StartSoundShader(
              this: *(idPresentable **)(v10 + LODWORD(result[1].renderModelInfo.scale.z)),
              channel: SND_CHANNEL_AMBIENT,
              shader: *(const idSoundShader **)(v10 + LODWORD(result[1].renderModelInfo.scale.z) + 16),
              parms: &v39,
              peerMask: 0);
          }
        }
        ++v8;
        v10 += 20;
      }
      while ( v8 < SLODWORD(result[1].renderModelInfo.color.r) );
    }
    r = result[1].renderModelInfo.color.r;
    result[1].renderModelInfo.renderParms.num = v8;
    if ( v8 < SLODWORD(r) )
      idEventReceiver::PostEventMS(this: result, ev: &EV_PowerUp, time: (int)result[1].renderModelInfo.renderParms.list);
    if ( g_DebugRegimeTiles.valueInteger != 0 )
      idLib::Printf(fmt: "=========================\n");
    return this;
  }
  else
  {
    idLib::Warning(
      fmt: "Failed to powerDown.  NumChildren = %d, nextActivateIdx = %d",
      r_low,
      result[1].renderModelInfo.renderParms.num);
    return this;
  }
}


// ========================================================================
// ?Spawn@idFuncWind@@QAAXXZ
// EA  : 0x82C75BD0
// RVA : 0x00C75BD0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idFuncWind::Spawn(idFuncWind *this)
{
  idLinkList<idFuncWind> *head; // r5

  if ( this->globalWind )
  {
    head = gameLocal->globalWindEntities.head;
    this->globalWindNode.prev->next = this->globalWindNode.next;
    this->globalWindNode.next->prev = this->globalWindNode.prev;
    this->globalWindNode.prev = &this->globalWindNode;
    this->globalWindNode.head = &this->globalWindNode;
    this->globalWindNode.next = head;
    this->globalWindNode.prev = head->prev;
    head->prev = &this->globalWindNode;
    this->globalWindNode.prev->next = &this->globalWindNode;
    this->globalWindNode.head = head->head;
  }
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  if ( this->startOff )
  {
    this->Hide_2(this);
    idEntity::UpdateVisuals(this);
  }
  else
  {
    idFuncWind::StartWind(this);
    this->Show(this);
  }
}


// ========================================================================
// ?Think@idFuncWind@@UAAXXZ
// EA  : 0x82C75CC8
// RVA : 0x00C75CC8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idFuncWind::Think(idFuncWind *this)
{
  __int64 v2; // r10
  double v3; // fp30
  double CurrentValue; // fp31
  int v5; // r7
  int v6; // r6
  const float *v7; // r5
  const float *v8; // r4
  int v9; // r3
  double windStrengthStartVal; // fp0
  double v11; // fp3
  double v12; // fp30
  idPhysics *Physics; // r30
  idPhysics *v14; // r28
  idRenderWorld *v15; // r27
  idPhysics *v16; // r3
  idRenderWorld_vtbl *v17; // r30
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  int v19; // r26
  int v20; // r3
  idPhysics *v21; // r30
  idPhysics *v22; // r29
  idRenderWorld *v23; // r28
  double v24; // fp30
  double v25; // fp29
  double v26; // fp31
  float *v27; // r3
  double v28; // fp9
  double v29; // fp7
  idRenderWorld_vtbl *v30; // r30
  int v31; // r3
  unsigned __int64 v32; // [sp+50h] [-80h] BYREF
  __int64 v33; // [sp+58h] [-78h] BYREF
  float v34[4]; // [sp+60h] [-70h] BYREF
  float v35[4]; // [sp+70h] [-60h] BYREF

  idEntity::Think(this);
  if ( (this->thinkFlags & 1) != 0
    && (float)((float)(this->windStrength.decelTime + this->windStrength.linearTime) + this->windStrength.accelTime) > 0.0 )
  {
    LODWORD(v2) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v33 = v2;
    v3 = (float)v2;
    idInterpolateAccelDecelSine<float>::SetPhase(this: &this->windStrength, time: v3);
    CurrentValue = idExtrapolate<float>::GetCurrentValue(this: &this->windStrength.extrapolate, time: v3);
    if ( v3 >= (float)((float)((float)(this->windStrength.decelTime + this->windStrength.startTime)
                             + this->windStrength.linearTime)
                     + this->windStrength.accelTime) )
    {
      v9 = idRandom2::RandomInt(this: &clientGame->random, min: this->minGustDuration, max: this->maxGustDuration);
      windStrengthStartVal = this->windStrengthStartVal;
      *(float *)&v33 = CurrentValue;
      v32 = __PAIR64__(&unk_82390000, v9);
      if ( CurrentValue <= windStrengthStartVal )
        windStrengthStartVal = this->windStrengthEndVal;
      *(float *)&v32 = windStrengthStartVal;
      v11 = (float)((float)((float)__SPAIR64__(&unk_82390000, v9) * (float)0.001) * (float)0.5);
      idInterpolateAccelDecelSine<float>::Init(
        this: &this->windStrength,
        startTime: v3,
        accelTime: v11,
        decelTime: v11,
        duration: (float)__SPAIR64__(&unk_82390000, v9),
        startValue: v8,
        endValue: v7,
        a8: v6,
        a9: v5,
        a10: (float *)&v33,
        a11: (float *)&v32);
    }
    v12 = (float)(this->minWindVolume + (float)CurrentValue);
    idEntity::SetSoundVolume(
      this,
      channel: SND_CHANNEL_WIND,
      volume: (float)(this->maxWindVolume + (float)CurrentValue));
    idEntity::SetSoundVolume(this, channel: SND_CHANNEL_WIND2, volume: v12);
    idEntity::SetSoundVolume(this, channel: SND_CHANNEL_WIND3, volume: v12);
    if ( g_showWindDebug.valueInteger == 1 )
    {
      Physics = idEntity::GetPhysics(this);
      v14 = idEntity::GetPhysics(this);
      v15 = common->RW(this: common);
      v16 = Physics;
      GetAxis = Physics->GetAxis;
      v17 = v15->__vftable;
      v19 = (int)GetAxis(this: v16, a2: 0);
      v20 = (int)v14->GetOrigin(this: v14, a2: 0);
      v17->DebugAxis_2(this: v15, a2: (const idVec3 *)v20, a3: (const idMat3 *)v19, a4: 0, a5: false);
      idFuncWind::GetCurrentWindDirection(this: (idFuncWind *)v34, result: (idVec3 *)this);
      v21 = idEntity::GetPhysics(this);
      v22 = idEntity::GetPhysics(this);
      v23 = common->RW(this: common);
      v24 = (float)(v34[0] * (float)CurrentValue);
      v25 = (float)(v34[1] * (float)CurrentValue);
      v26 = (float)(v34[2] * (float)CurrentValue);
      v27 = (float *)v21->GetOrigin(this: v21, a2: 0);
      v28 = (float)(v27[2] + (float)v26);
      v29 = (float)(v27[1] + (float)v25);
      v35[0] = *v27 + (float)v24;
      v35[2] = v28;
      v35[1] = v29;
      v30 = v23->__vftable;
      v31 = (int)v22->GetOrigin(this: v22, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v30->DebugArrow)(
        a1: v23,
        a2: &idColor::colorCyan,
        a3: v31,
        a4: v35,
        a5: 2.0);
    }
  }
  idEntity::UpdateVisuals(this);
}


// ========================================================================
// ?GetCurrentWindStrength@idFuncWind@@QBAMXZ
// EA  : 0x82C75FE8
// RVA : 0x00C75FE8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

float __fastcall idFuncWind::GetCurrentWindStrength(idFuncWind *this)
{
  __int64 v1; // r10
  idInterpolateAccelDecelSine<float> *p_windStrength; // r31
  double v3; // fp31
  double CurrentValue; // fp1

  p_windStrength = &this->windStrength;
  LODWORD(v1) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v3 = (float)v1;
  idInterpolateAccelDecelSine<float>::SetPhase(this: p_windStrength, time: v3);
  CurrentValue = idExtrapolate<float>::GetCurrentValue(this: &p_windStrength->extrapolate, time: v3);
  return *((float *)&CurrentValue + 1);
}


// ========================================================================
// ?Spawn@idWindEmitter@@QAAXXZ
// EA  : 0x82C76060
// RVA : 0x00C76060
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idWindEmitter::Spawn(
        idWindEmitter *this,
        int a2,
        int a3,
        int a4,
        idPresentable *a5,
        const idSoundShader *a6)
{
  idPresentable *presentable; // r4
  idWindEmitter_vtbl *v8; // r11

  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  presentable = this->presentable;
  if ( presentable != nullptr )
    idInfluenceTrailManager::Enable(
      this: &clientGame->influenceTrailManager,
      presentable,
      trail: &this->influence,
      sndFoliage: nullptr,
      a5,
      a6);
  v8 = this->__vftable;
  if ( this->startOff )
  {
    v8->Hide_2(this);
    idEntity::UpdateVisuals(this);
  }
  else
  {
    v8->Show(this);
    idWindEmitter::StartWind(this);
  }
}


// ========================================================================
// ?Think@idWindEmitter@@UAAXXZ
// EA  : 0x82C76110
// RVA : 0x00C76110
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idWindEmitter::Think(idWindEmitter *this)
{
  __int64 v2; // r10
  double v3; // fp30
  double CurrentValue; // fp31
  __int64 v5; // r10
  int v6; // r7
  int v7; // r6
  const float *v8; // r5
  const float *v9; // r4
  double windStrengthStartVal; // fp0
  double v11; // fp3
  __int64 v12; // r9
  bool v13; // r5
  int NextGustOverlay; // r3
  int currGustOverlayIdx; // r11
  int v16; // r28
  const idSoundShader *v17; // r29
  double maxDistance; // fp13
  __int64 v19; // r10
  bool v20; // r5
  int valueInteger; // r11
  idPhysics *Physics; // r29
  idPhysics *v23; // r27
  idRenderWorld *v24; // r23
  idPhysics *v25; // r3
  idRenderWorld_vtbl *v26; // r29
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  int v28; // r22
  int v29; // r3
  idPhysics *v30; // r29
  idPhysics *v31; // r28
  idRenderWorld *v32; // r27
  double v33; // fp30
  double v34; // fp29
  double v35; // fp31
  float *v36; // r3
  double v37; // fp9
  double v38; // fp7
  idRenderWorld_vtbl *v39; // r29
  int v40; // r3
  idPhysics *v41; // r30
  int GameMs; // r28
  idPresentable *presentable; // r29
  idPhysics *v44; // r3
  idInfluenceTrailManager *p_influenceTrailManager; // r30
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v47; // r3
  __int64 v48; // [sp+50h] [-140h] BYREF
  float v49[2]; // [sp+58h] [-138h] BYREF
  float v50[4]; // [sp+60h] [-130h] BYREF
  float v51[4]; // [sp+70h] [-120h] BYREF
  soundShaderParms_t v52; // [sp+80h] [-110h] BYREF

  idEntity::Think(this);
  if ( (this->thinkFlags & 1) != 0 )
  {
    if ( (float)((float)(this->windStrength.decelTime + this->windStrength.linearTime) + this->windStrength.accelTime) > 0.0 )
    {
      LODWORD(v2) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v48 = v2;
      v3 = (float)v2;
      idInterpolateAccelDecelSine<float>::SetPhase(this: &this->windStrength, time: v3);
      CurrentValue = idExtrapolate<float>::GetCurrentValue(this: &this->windStrength.extrapolate, time: v3);
      if ( v3 >= (float)((float)((float)(this->windStrength.decelTime + this->windStrength.startTime)
                               + this->windStrength.linearTime)
                       + this->windStrength.accelTime) )
      {
        idLib::Printf(fmt: "Starting new wind cycle\n");
        LODWORD(v5) = idRandom2::RandomInt(
                        this: &clientGame->random,
                        min: this->minGustDuration,
                        max: this->maxGustDuration);
        windStrengthStartVal = this->windStrengthStartVal;
        LODWORD(v48) = v5;
        *(float *)&v48 = CurrentValue;
        if ( CurrentValue <= windStrengthStartVal )
          windStrengthStartVal = this->windStrengthEndVal;
        v49[0] = windStrengthStartVal;
        v11 = (float)((float)((float)v5 * (float)0.001) * (float)0.5);
        idInterpolateAccelDecelSine<float>::Init(
          this: &this->windStrength,
          startTime: v3,
          accelTime: v11,
          decelTime: v11,
          duration: (float)v5,
          startValue: v9,
          endValue: v8,
          a8: v7,
          a9: v6,
          a10: (float *)&v48,
          a11: v49);
        NextGustOverlay = idWindEmitter::GetNextGustOverlay(this);
        currGustOverlayIdx = this->currGustOverlayIdx;
        v16 = NextGustOverlay;
        if ( currGustOverlayIdx >= 0 )
        {
          LODWORD(v12) = this->gustCrossFadeTime;
          v48 = v12;
          idEntity::FadeSound(
            this,
            channel: (soundChannel_t)(currGustOverlayIdx + 43),
            to: -60.0,
            over: (float)((float)v12 * 0.001),
            additive: v13);
        }
        if ( v16 >= 0 )
        {
          v17 = this->sndGustOverlay[v16];
          if ( v17 != nullptr )
          {
            soundShaderParms_t::Clear(this: &v52);
            maxDistance = this->maxDistance;
            v52.minDistance = this->minDistance;
            v52.maxDistance = maxDistance;
            idEntity::StartSoundShader(
              this,
              channel: (soundChannel_t)(v16 + 43),
              shader: v17,
              parms: &v52,
              peerMask: 0xFFu);
            idEntity::SetSoundVolume(this, channel: (soundChannel_t)(v16 + 43), volume: -60.0);
            LODWORD(v19) = this->gustCrossFadeTime;
            v48 = v19;
            idEntity::FadeSound(
              this,
              channel: (soundChannel_t)(v16 + 43),
              to: 0.0,
              over: (float)((float)v19 * 0.001),
              additive: v20);
          }
        }
        this->currGustOverlayIdx = v16;
      }
      idEntity::SetSoundVolume(
        this,
        channel: SND_CHANNEL_WIND,
        volume: (float)(this->maxWindVolume + (float)CurrentValue));
      valueInteger = g_showWindDebug.valueInteger;
      if ( g_showWindDebug.valueInteger == 1 )
      {
        Physics = idEntity::GetPhysics(this);
        v23 = idEntity::GetPhysics(this);
        v24 = common->RW(this: common);
        v25 = Physics;
        GetAxis = Physics->GetAxis;
        v26 = v24->__vftable;
        v28 = (int)GetAxis(this: v25, a2: 0);
        v29 = (int)v23->GetOrigin(this: v23, a2: 0);
        v26->DebugAxis_2(this: v24, a2: (const idVec3 *)v29, a3: (const idMat3 *)v28, a4: 0, a5: false);
        idWindEmitter::GetCurrentWindDirection(this: (idWindEmitter *)v50, result: (idVec3 *)this);
        v30 = idEntity::GetPhysics(this);
        v31 = idEntity::GetPhysics(this);
        v32 = common->RW(this: common);
        v33 = (float)(v50[0] * (float)CurrentValue);
        v34 = (float)(v50[1] * (float)CurrentValue);
        v35 = (float)(v50[2] * (float)CurrentValue);
        v36 = (float *)v30->GetOrigin(this: v30, a2: 0);
        v37 = (float)(v36[2] + (float)v35);
        v38 = (float)(v36[1] + (float)v34);
        v51[0] = *v36 + (float)v33;
        v51[2] = v37;
        v51[1] = v38;
        v39 = v32->__vftable;
        v40 = (int)v31->GetOrigin(this: v31, a2: 0);
        ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v39->DebugArrow)(
          a1: v32,
          a2: &idColor::colorCyan,
          a3: v40,
          a4: v51,
          a5: 2.0);
        valueInteger = g_showWindDebug.valueInteger;
      }
      if ( valueInteger == 2 )
        idEntity::SetSoundVolume(this, channel: SND_CHANNEL_WIND, volume: -60.0);
    }
    v41 = idEntity::GetPhysics(this);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    if ( this->presentable == nullptr )
      idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
    v44 = v41;
    GetOrigin = v41->GetOrigin;
    p_influenceTrailManager = &clientGame->influenceTrailManager;
    v47 = GetOrigin(this: v44, a2: 0);
    idInfluenceTrailManager::UpdatePosition(
      this: p_influenceTrailManager,
      trail: &presentable->influenceHandle,
      position: v47,
      time: GameMs);
    idEntity::UpdateVisuals(this);
  }
}


// ========================================================================
// ??0idEntityImposter@@QAA@XZ
// EA  : 0x82C76598
// RVA : 0x00C76598
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idEntityImposter *__fastcall idEntityImposter::idEntityImposter(idEntityImposter *this)
{
  idDynamicEntity::idDynamicEntity(this);
  this->__vftable = (idEntityImposter_vtbl *)&idEntityImposter::`vftable';
  this->original.spawnId.value = 0x1FFF;
  this->animated = false;
  this->clipModelInfo.type = CLIPMODEL_NONE;
  return this;
}


// ========================================================================
// ??0idAnnouncementManager@@QAA@XZ
// EA  : 0x82C765F0
// RVA : 0x00C765F0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idAnnouncementManager *__fastcall idAnnouncementManager::idAnnouncementManager(idAnnouncementManager *this)
{
  idEntity::idEntity(this);
  this->startDelay = 0.0;
  this->__vftable = (idAnnouncementManager_vtbl *)&idAnnouncementManager::`vftable';
  this->startDelayVariance = 0.0;
  this->startActive = true;
  this->iterationDelay = 120.0;
  this->doVoiceOver = true;
  this->iterationVariance = 0.0;
  this->firstAnnouncement = nullptr;
  this->chancePerIteration = 1.0;
  this->announcements.list = nullptr;
  this->announcements.granularity = 0;
  this->announcements.memTag = 5;
  this->announcements.listStatic = 0;
  this->announcements.size = 0;
  this->announcements.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->announcements);
  this->firstAnnouncementVO = nullptr;
  this->announcementsVO.list = nullptr;
  this->announcementsVO.granularity = 0;
  this->announcementsVO.memTag = 5;
  this->announcementsVO.listStatic = 0;
  this->announcementsVO.size = 0;
  this->announcementsVO.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->announcementsVO);
  this->talkerName.index = -1;
  this->active = false;
  this->playedFirst = false;
  this->nextPlayTime = 0;
  this->lastAnnouncement = -1;
  return this;
}


// ========================================================================
// __unwind$503824
// EA  : 0x82C766CC
// RVA : 0x00C766CC
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_503824()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$503825
// EA  : 0x82C766F4
// RVA : 0x00C766F4
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_503825()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 828));
}


// ========================================================================
// ?Hide@idAnnouncementManager@@UAAXXZ
// EA  : 0x82C76720
// RVA : 0x00C76720
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idAnnouncementManager::Hide(idAnnouncementManager *this)
{
  idEntity::Hide(this);
  if ( this->active )
    idAnnouncementManager::Deactivate(this);
}


// ========================================================================
// ?OnActivate@idAnnouncementManager@@UAAXPAVidEntity@@@Z
// EA  : 0x82C76760
// RVA : 0x00C76760
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idAnnouncementManager::OnActivate(idAnnouncementManager *this, idEntity *activator)
{
  if ( this->active )
    idAnnouncementManager::Deactivate(this);
  else
    idAnnouncementManager::Activate(this);
}


// ========================================================================
// ?PlaySound@idAnnouncementManager@@AAAXXZ
// EA  : 0x82C76778
// RVA : 0x00C76778
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idAnnouncementManager::PlaySound(idAnnouncementManager *this)
{
  const idSoundShader *firstAnnouncement; // r23
  int num; // r4
  int v4; // r3
  idClientGame *v5; // r10
  signed int v6; // r11
  unsigned int seed; // r9
  unsigned int v8; // r4
  int v9; // r3
  int v10; // r5
  const idSoundShader **list; // r11
  int v12; // r24
  int v13; // r29
  int value; // r9
  idEntity *v15; // r3
  idSound *v16; // r3
  idSound *v17; // r3
  idEventReceiver *v18; // r31
  int v19; // [sp+50h] [-70h]
  const idEventArg *v20; // [sp+58h] [-68h]

  if ( this->doVoiceOver )
  {
    idAnnouncementManager::PlayVoiceOver(this);
  }
  else
  {
    firstAnnouncement = nullptr;
    if ( this->playedFirst || this->firstAnnouncement == nullptr )
    {
      num = this->announcements.num;
      if ( num > 0 )
      {
        v4 = idRandom2::RandomInt(this: &clientGame->random, max: num);
        if ( this->announcements.num > 1 )
        {
          v5 = clientGame;
          do
          {
            if ( v4 != this->lastAnnouncement )
              break;
            v6 = this->announcements.num;
            if ( v6 != 0 )
            {
              seed = v5->random.seed;
              __twllei(v6, 0);
              v8 = 1664525 * seed + 1013904223;
              v5->random.seed = v8;
              v5 = clientGame;
              v9 = (v8 >> 10) & 0x7FFF;
              v10 = __ROL4__(v9, 1) - 1;
              v4 = v9 % v6;
              __twlgei(v6 & ~v10, 0xFFFFFFFF);
            }
            else
            {
              v4 = 0;
            }
          }
          while ( this->announcements.num > 1 );
        }
        list = this->announcements.list;
        this->lastAnnouncement = v4;
        firstAnnouncement = list[v4];
      }
    }
    else
    {
      firstAnnouncement = this->firstAnnouncement;
    }
    this->playedFirst = true;
    if ( firstAnnouncement != nullptr )
    {
      v12 = 0;
      if ( this->targets.num > 0 )
      {
        v13 = 0;
        do
        {
          value = this->targets.list[v13].spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v15 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v16 = (idSound *)idEntity::CastTo(c: v15);
          }
          else
          {
            v16 = nullptr;
          }
          v17 = idSound::CastTo(c: v16);
          v18 = v17;
          if ( v17 != nullptr )
          {
            HIBYTE(v19) = 100;
            idEventReceiver::PostEventMS(this: v17, ev: &EV_SetSoundShader, time: v19, arg1: v20);
            idEventReceiver::PostEventMS(this: v18, ev: &EV_On, time: 0);
          }
          ++v12;
          ++v13;
        }
        while ( v12 < this->targets.num );
      }
    }
  }
}


// ========================================================================
// ??0idGuiEntity@@QAA@XZ
// EA  : 0x82C76968
// RVA : 0x00C76968
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idGuiEntity *__fastcall idGuiEntity::idGuiEntity(idGuiEntity *this)
{
  idRenderModelGui *v2; // r3
  idRenderModelGui *v3; // r3

  idDynamicEntity::idDynamicEntity(this);
  this->initialState = INIT_STATE_INVALID;
  this->activeState = INIT_STATE_INVALID;
  this->nextState = INIT_STATE_INVALID;
  this->__vftable = (idGuiEntity_vtbl *)&idGuiEntity::`vftable';
  this->used = false;
  this->usable = false;
  this->guiSwf = nullptr;
  this->guiModel = nullptr;
  this->target.spawnId.value = 0x1FFF;
  this->initializedGuis = false;
  this->triggeredSound = nullptr;
  this->disableSaves = false;
  this->controlNode.head = &this->controlNode;
  this->controlNode.owner = nullptr;
  this->controlNode.next = &this->controlNode;
  this->controlNode.prev = &this->controlNode;
  *(_BYTE *)&this->flags |= 0x40u;
  v2 = (idRenderModelGui *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xA410u,
                             tag: TAG_GUI_MODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idRenderModelGui::idRenderModelGui(this: v2);
  else
    v3 = nullptr;
  this->guiModel = v3;
  return this;
}


// ========================================================================
// __unwind$503962
// EA  : 0x82C76A44
// RVA : 0x00C76A44
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_503962()
{
  int v0; // r12

  idDynamicEntity::~idDynamicEntity(this: *(idDynamicEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$503963
// EA  : 0x82C76A6C
// RVA : 0x00C76A6C
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_503963()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                           + 924));
}


// ========================================================================
// __unwind$503964
// EA  : 0x82C76A98
// RVA : 0x00C76A98
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_503964()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_GUI_MODEL);
}


// ========================================================================
// ?GiveItems@idCoopStartingInventory@@QAAXPAVidPlayer@@@Z
// EA  : 0x82C76AC8
// RVA : 0x00C76AC8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idCoopStartingInventory::GiveItems(idCoopStartingInventory *this, idPlayer *player)
{
  idPresentable *presentable; // r30
  idInventoryCollection *v5; // r3
  idList<idCoopStartingInventory::itemListElement_t,5> *p_playerOneItemList; // r28
  int v7; // r25
  int v8; // r30
  const idDeclJob *item; // r29
  idJobManager *v10; // r3
  idJob *JobByDecl; // r3
  idCoopStartingInventory::itemListElement_t *list; // r10
  idPresentable *v13; // r11
  idInventoryItem *v14; // r26
  idCoopStartingInventory::itemListElement_t *v15; // r29
  idPresentable *v16; // r27
  int v17; // r26
  const idDeclInventory *v18; // r29
  idInventoryCollection *v19; // r3
  idCoopStartingInventory::itemListElement_t *v20; // r27
  idPresentable *v21; // r29
  int count; // r27
  idInventoryCollection *v23; // r3

  if ( player != nullptr )
  {
    presentable = player->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: player);
      presentable = player->presentable;
    }
    v5 = player->GetInventory_2(this: player);
    idInventoryCollection::FreeInventory(this: v5, owner: presentable);
    p_playerOneItemList = &this->playerOneItemList;
    if ( player->entityNumber > 0 && !this->mirrorPlayerOne )
      idList<idCoopStartingInventory::itemListElement_t,5>::operator=(
        this: &this->playerOneItemList,
        other: &this->playerTwoItemList);
    v7 = 0;
    if ( this->playerOneItemList.num > 0 )
    {
      v8 = 0;
      do
      {
        item = (const idDeclJob *)p_playerOneItemList->list[v8].item;
        v10 = (idJobManager *)player->GetInventory_2(this: player);
        JobByDecl = idJobManager::FindJobByDecl(this: v10, jobDecl: item);
        list = p_playerOneItemList->list;
        v13 = player->presentable;
        v14 = (idInventoryItem *)JobByDecl;
        if ( JobByDecl != nullptr )
        {
          v20 = &list[v8];
          if ( v13 == nullptr )
            idEntity::InitPresentableInternal(this: player);
          v21 = player->presentable;
          count = v20->count;
          v23 = player->GetInventory_2(this: player);
          idInventoryCollection::SetItemCount(this: v23, owner: v21, item: v14, count, forceCount: true);
        }
        else
        {
          v15 = &list[v8];
          if ( v13 == nullptr )
            idEntity::InitPresentableInternal(this: player);
          v16 = player->presentable;
          v17 = v15->count;
          v18 = v15->item;
          v19 = player->GetInventory_2(this: player);
          idInventoryCollection::GiveItem(
            this: v19,
            owner: v16,
            decl: v18,
            count: v17,
            forceCount: false,
            canIntro: false);
        }
        ++v7;
        ++v8;
      }
      while ( v7 < p_playerOneItemList->num );
    }
  }
  else
  {
    idLib::Warning(fmt: "idCoopStartingInventory can only be used with a player entity.");
  }
}


// ========================================================================
// ??0idCoopStartingInventory@@QAA@XZ
// EA  : 0x82C76C68
// RVA : 0x00C76C68
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idCoopStartingInventory *__fastcall idCoopStartingInventory::idCoopStartingInventory(idCoopStartingInventory *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idCoopStartingInventory_vtbl *)&idCoopStartingInventory::`vftable';
  this->playerOneItemList.list = nullptr;
  this->playerOneItemList.granularity = 0;
  this->playerOneItemList.memTag = 5;
  this->playerOneItemList.listStatic = 0;
  this->playerOneItemList.size = 0;
  this->playerOneItemList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->playerOneItemList);
  this->playerTwoItemList.list = nullptr;
  this->playerTwoItemList.granularity = 0;
  this->playerTwoItemList.memTag = 5;
  this->playerTwoItemList.listStatic = 0;
  this->playerTwoItemList.size = 0;
  this->playerTwoItemList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->playerTwoItemList);
  this->mirrorPlayerOne = false;
  return this;
}


// ========================================================================
// __unwind$504068
// EA  : 0x82C76CE8
// RVA : 0x00C76CE8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_504068()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$504069
// EA  : 0x82C76D10
// RVA : 0x00C76D10
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_504069()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 800));
}


// ========================================================================
// ?Think@idHorizonScale@@UAAXXZ
// EA  : 0x82C76D40
// RVA : 0x00C76D40
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idHorizonScale::Think(idHorizonScale *this)
{
  double v1; // fp28
  double v3; // fp25
  idPhysics *Physics; // r3
  int v5; // r3
  int v6; // r28
  float v7; // r7
  int v8; // r6
  int num; // r11
  double v10; // fp27
  double v11; // fp26
  int v12; // r29
  int value; // r9
  idEntity *v14; // r3
  idEntity *v15; // r31
  idPhysics *v16; // r3
  int v17; // r3
  float v18; // r8
  int v19; // r7
  double v20; // fp0
  bool v21; // r11
  idPresentable *presentable; // r11
  float *model; // r11
  idPresentable *v24; // r11
  float v25; // [sp+50h] [-A0h] BYREF
  float v26; // [sp+54h] [-9Ch]
  float v27; // [sp+58h] [-98h]
  float v28; // [sp+60h] [-90h]
  float v29; // [sp+64h] [-8Ch]
  int v30; // [sp+68h] [-88h]
  float v31[20]; // [sp+70h] [-80h] BYREF

  v1 = (float)(this->radiusInner * this->radiusInner);
  v3 = (float)((float)1.0
             / (float)((float)(this->radiusOuter * this->radiusOuter) - (float)(this->radiusInner * this->radiusInner)));
  Physics = idEntity::GetPhysics(this);
  v5 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v6 = 0;
  v7 = *(float *)(v5 + 4);
  v8 = *(_DWORD *)(v5 + 8);
  num = this->targets.num;
  v28 = *(float *)v5;
  v29 = v7;
  v30 = v8;
  if ( num > 0 )
  {
    v10 = v29;
    v11 = v28;
    v12 = 0;
    do
    {
      value = this->targets.list[v12].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v14 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v15 = idEntity::CastTo(c: v14);
      }
      else
      {
        v15 = nullptr;
      }
      if ( v15 != nullptr && v15->IsVisible(this: v15) )
      {
        v16 = idEntity::GetPhysics(this: v15);
        v17 = (int)v16->GetOrigin(this: v16, a2: 0);
        v18 = *(float *)v17;
        v19 = *(_DWORD *)(v17 + 8);
        v29 = *(float *)(v17 + 4);
        v28 = v18;
        v30 = v19;
        v20 = (float)((float)((float)((float)((float)(v29 - (float)v10) * (float)(v29 - (float)v10))
                                    + (float)((float)(v18 - (float)v11) * (float)(v18 - (float)v11)))
                            - (float)v1)
                    * (float)v3);
        if ( v20 >= 0.0 )
        {
          if ( v20 > 1.0 )
            v20 = 1.0;
        }
        else
        {
          v20 = 0.0;
        }
        v25 = (float)((float)v20 * (float)-0.99989998) + (float)1.0;
        v26 = v25;
        v27 = v25;
        v15->GetScale(this: v15, a2: (idVec3 *)v31);
        v21 = false;
        if ( __fabs((float)(v25 - v31[0])) <= 0.000099999997 && __fabs((float)(v26 - v31[1])) <= 0.000099999997 )
          v21 = __fabs((float)(v27 - v31[2])) <= 0.000099999997;
        if ( !v21 )
        {
          v15->SetScale(this: v15, a2: (const idVec3 *)&v25);
          if ( idEntity::GetRenderModelFromPresentable(this: v15) != nullptr )
          {
            presentable = v15->presentable;
            if ( presentable == nullptr )
            {
              idEntity::InitPresentableInternal(this: v15);
              presentable = v15->presentable;
            }
            model = (float *)presentable->model;
            model[41] = v25;
            model[42] = v26;
            model[43] = v27;
            v24 = v15->presentable;
            if ( v24 == nullptr )
            {
              idEntity::InitPresentableInternal(this: v15);
              v24 = v15->presentable;
            }
            v24->Present(this: v24);
          }
        }
      }
      ++v6;
      ++v12;
    }
    while ( v6 < this->targets.num );
  }
}


// ========================================================================
// ?Think@idDynamicEntity@@UAAXXZ
// EA  : 0x82C77300
// RVA : 0x00C77300
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDynamicEntity::Think(idDynamicEntity *this)
{
  idPresentable *presentable; // r4
  char v3; // r11
  idLinkList<idFuncWind> *next; // r11
  idFuncWind *owner; // r31
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r7
  double CurrentWindStrength; // fp1
  idPresentable *v11; // r3
  idPresentable *v12; // r11
  __int64 v13; // [sp+8h] [-88h]
  __int64 v14; // [sp+10h] [-80h]
  __int64 v15; // [sp+18h] [-78h]
  __int64 v16; // [sp+20h] [-70h]
  __int64 v17; // [sp+28h] [-68h]
  float v18[6]; // [sp+50h] [-40h] BYREF
  __int64 v19; // [sp+68h] [-28h]

  idEntity::Think(this);
  if ( (this->thinkFlags & 1) != 0 )
  {
    presentable = this->presentable;
    if ( presentable == nullptr || (v3 = 1, presentable->model == nullptr) )
      v3 = 0;
    if ( v3 != 0 )
    {
      if ( this->fade.fadeEndTime > 0 )
      {
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          presentable = this->presentable;
        }
        idFadeHelper::Update(this: &this->fade, presentable);
      }
      next = gameLocal->globalWindEntities.next;
      if ( next != nullptr && next != gameLocal->globalWindEntities.head )
      {
        owner = next->owner;
        if ( owner != nullptr )
        {
          idFuncWind::GetCurrentWindDirection(this: (idFuncWind *)v18, result: (idVec3 *)next->owner);
          CurrentWindStrength = idFuncWind::GetCurrentWindStrength(this: owner);
          v11 = this->presentable;
          v18[4] = v18[0];
          v18[5] = v18[1];
          *(float *)&v19 = v18[2];
          *((float *)&v19 + 1) = CurrentWindStrength;
          if ( v11 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v11 = this->presentable;
          }
          idPresentable::SetParm(
            this: v11,
            parm: rp->Wind,
            v4: v19,
            a4: v9,
            a5: v8,
            a6: v7,
            a7: v6,
            a8: v13,
            a9: v14,
            a10: v15,
            a11: v16,
            a12: v17);
          v12 = this->presentable;
          if ( v12 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v12 = this->presentable;
          }
          v12->Present(this: v12);
        }
      }
      idDynamicEntity::UpdateColorModulate(this);
    }
  }
}


// ========================================================================
// ?Think@idParticleEmitter@@UAAXXZ
// EA  : 0x82C77460
// RVA : 0x00C77460
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idParticleEmitter::Think(idParticleEmitter *this)
{
  int v2; // r3
  signed int smokeSystemRate; // r8
  char v4; // r11
  BOOL inheritMasterVelocity; // r10
  idParticleEmitter *BindMaster; // r3
  bool v7; // zf
  idPhysics *Physics; // r3
  float *v9; // r3
  double v10; // fp12
  idPresentable *presentable; // r3
  double masterVelocityScale; // fp11
  double v13; // fp9
  int v14; // r3
  idPhysics *v15; // r29
  idPhysics *v16; // r27
  __int64 v17; // r9
  unsigned int v18; // r5
  double v19; // fp31
  int GameMsPerFrame; // r26
  int GameMs; // r30
  const idVec3 *v22; // r29
  const idMat3 *v23; // r28
  const idDeclParticle *particleSystem; // r31
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v26; // r7
  int v27; // [sp+8h] [-C8h]
  int v28; // [sp+Ch] [-C4h]
  int v29; // [sp+10h] [-C0h]
  int v30; // [sp+14h] [-BCh]
  int v31; // [sp+18h] [-B8h]
  int v32; // [sp+1Ch] [-B4h]
  int v33; // [sp+20h] [-B0h]
  int v34; // [sp+24h] [-ACh]
  int v35; // [sp+28h] [-A8h]
  int v36; // [sp+2Ch] [-A4h]
  int v37; // [sp+30h] [-A0h]
  int v38; // [sp+34h] [-9Ch]
  int v39; // [sp+38h] [-98h]
  int v40; // [sp+3Ch] [-94h]
  int v41; // [sp+40h] [-90h]
  int v42; // [sp+44h] [-8Ch]
  int v43; // [sp+48h] [-88h]
  int v44; // [sp+4Ch] [-84h]
  int v45; // [sp+50h] [-80h]
  unsigned int v46; // [sp+60h] [-70h] BYREF
  __int64 v47; // [sp+68h] [-68h] BYREF
  idVec3 v48; // [sp+78h] [-58h] BYREF

  idDynamicEntity::Think(this);
  if ( (this->thinkFlags & 1) != 0 )
  {
    if ( this->smokeSystemRate == 0
      || (v2 = gameLocal->GetGameFrame(this: gameLocal),
          smokeSystemRate = this->smokeSystemRate,
          __twllei(smokeSystemRate, 0),
          __twlgei(smokeSystemRate & ~(__ROL4__(v2, 1) - 1), 0xFFFFFFFF),
          v4 = 0,
          v2 % smokeSystemRate == 0) )
    {
      v4 = 1;
    }
    if ( this->useSmokeSystem && v4 != 0 )
    {
      inheritMasterVelocity = this->inheritMasterVelocity;
      v48 = vec3_origin;
      if ( inheritMasterVelocity )
      {
        v7 = idEntity::GetBindMaster(this) == nullptr;
        BindMaster = this;
        if ( !v7 )
          BindMaster = (idParticleEmitter *)idEntity::GetBindMaster(this);
        Physics = idEntity::GetPhysics(this: BindMaster);
        v9 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v47, result: (idVec3 *)Physics, a3: 0);
        v48.x = *v9;
        v48.y = v9[1];
        v10 = v9[2];
        presentable = this->presentable;
        masterVelocityScale = this->masterVelocityScale;
        v13 = (float)(v48.y * this->masterVelocityScale);
        v48.x = this->masterVelocityScale * v48.x;
        v48.y = v13;
        v48.z = (float)v10 * (float)masterVelocityScale;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          presentable = this->presentable;
        }
        v14 = (int)presentable->GetParticleEmitterInterface(this: presentable);
        if ( v14 != 0 )
          *(idVec3 *)(v14 + 1268) = v48;
      }
      v46 = -1;
      v15 = idEntity::GetPhysics(this);
      v16 = idEntity::GetPhysics(this);
      HIDWORD(v17) = 1664525;
      v18 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v18 + 1013904223;
      LODWORD(v17) = ((v18 + 1013904223) >> 10) & 0x7FFF;
      v47 = v17;
      v19 = (float)((float)v17 * (float)0.000030518509);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v22 = (const idVec3 *)v15->GetAxis(this: v15, a2: 0);
      v23 = (const idMat3 *)v16->GetOrigin(this: v16, a2: 0);
      particleSystem = this->particleSystem;
      MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
      idRenderModelEffects::AddParticles(
        this: MergeBranch,
        particle: particleSystem,
        systemStartTime: GameMs,
        gameMsPerFrame: GameMsPerFrame,
        diversity: v19,
        origin: v26,
        axis: v23,
        velocity: v22,
        color: &v48.x,
        a10: v27,
        a11: v28,
        a12: v29,
        a13: v30,
        a14: v31,
        a15: v32,
        a16: v33,
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
        a29: &v46);
    }
  }
}


// ========================================================================
// ?TurnOn@idElectricBoltEmitter@@AAAXXZ
// EA  : 0x82C776F0
// RVA : 0x00C776F0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idElectricBoltEmitter::TurnOn(idElectricBoltEmitter *this)
{
  const idSoundShader *sndPowerUp; // r5
  __int64 v3; // r10
  unsigned int v4; // r8
  double v5; // fp31
  int GameMs; // r3
  idStaticList<eboltControlNode_t,32> v7; // [sp+60h] [-330h] BYREF

  sndPowerUp = this->sndPowerUp;
  if ( sndPowerUp != nullptr )
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_AMBIENT,
      shader: sndPowerUp,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
  if ( this->spline != nullptr )
  {
    v7.granularity = 1;
    v7.size = 32;
    v7.num = 0;
    v7.list = v7.staticList;
    v7.memTag = 5;
    v7.listStatic = 1;
    HIDWORD(v3) = clientGame->random.seed;
    v4 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v4 + 1013904223;
    LODWORD(v3) = ((v4 + 1013904223) >> 10) & 0x7FFF;
    v5 = (float)((float)v3 * (float)0.000030518509);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idElectricBolt::StartElectricBolt(this: this->ebolt, _startTime: GameMs, _controlNodes: &v7, _diversity: v5);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v7);
  }
  else
  {
    idElectricBoltEmitter::ResetTarget(this);
  }
}


// ========================================================================
// __unwind$505004
// EA  : 0x82C77804
// RVA : 0x00C77804
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_505004()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 912 + 96));
}


// ========================================================================
// ?OnActivate@idElectricBoltEmitter@@UAAXPAVidEntity@@@Z
// EA  : 0x82C77838
// RVA : 0x00C77838
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idElectricBoltEmitter::OnActivate(idElectricBoltEmitter *this, idEntity *activator)
{
  idElectricBolt *v3; // r3
  idElectricBolt *v4; // r3
  const idDeclElectricBolt *electricBoltSystem; // r29
  idRenderModelBeam *NumContacts; // r3
  int value; // r10
  idSplinePath *v8; // r3
  idSplinePath *v9; // r4
  char idCombatStage_useRelaxedChatterVO; // r3
  idElectricBoltEmitter_vtbl *v11; // r11

  if ( this->ebolt == nullptr )
  {
    v3 = (idElectricBolt *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0x320u,
                             tag: TAG_PARTICLE,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
    v4 = v3 != nullptr ? idElectricBolt::idElectricBolt(this: v3) : nullptr;
    this->ebolt = v4;
    if ( v4 != nullptr )
    {
      electricBoltSystem = this->electricBoltSystem;
      NumContacts = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: (idAnimator_ChannelWeight *)clientGame);
      idElectricBolt::Init(this: this->ebolt, _beamModel: NumContacts, _eboltDecl: electricBoltSystem);
    }
  }
  if ( this->ebolt != nullptr )
  {
    value = this->controlPath.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v8 = (idSplinePath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v9 = idSplinePath::CastTo(c: v8);
    }
    else
    {
      v9 = nullptr;
    }
    idElectricBoltEmitter::SetControlPath(this, controlPath: v9);
    idCombatStage_useRelaxedChatterVO = Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this);
    v11 = this->__vftable;
    if ( idCombatStage_useRelaxedChatterVO != 0 )
    {
      v11->Show(this);
      idElectricBoltEmitter::TurnOn(this);
    }
    else
    {
      v11->Hide_2(this);
    }
  }
}


// ========================================================================
// __unwind$505074
// EA  : 0x82C77974
// RVA : 0x00C77974
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_505074()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PARTICLE);
}


// ========================================================================
// ?Think@idRibbonEmitter@@UAAXXZ
// EA  : 0x82C779A0
// RVA : 0x00C779A0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idRibbonEmitter::Think(idRibbonEmitter *this)
{
  idPhysics *Physics; // r30
  idPhysics *v3; // r29
  int GameMs; // r28
  const idMat3 *v5; // r30
  const idVec3 *v6; // r3
  idVec4 v7; // [sp+50h] [-40h] BYREF

  idDynamicEntity::Think(this);
  if ( (this->thinkFlags & 1) != 0 )
  {
    Physics = idEntity::GetPhysics(this);
    v3 = idEntity::GetPhysics(this);
    v7.x = 1.0;
    v7.y = 1.0;
    v7.z = 1.0;
    v7.w = 1.0;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v5 = Physics->GetAxis(this: Physics, a2: 0);
    v6 = v3->GetOrigin(this: v3, a2: 0);
    idRibbonManager::UpdateRibbon(
      this: &this->ribbonManager,
      time: GameMs,
      org: v6,
      axis: v5,
      vel: &vec3_origin,
      color: &v7,
      translate: &vec3_origin);
  }
}


// ========================================================================
// ?InitialSetup@idFuncCloth@@QAAXXZ
// EA  : 0x82C77AD0
// RVA : 0x00C77AD0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idFuncCloth::InitialSetup(idFuncCloth *this)
{
  BOOL influencedByWind; // r10
  double v3; // fp30
  idLinkList<idFuncWind> *next; // r11
  idFuncWind *owner; // r31
  double CurrentWindStrength; // fp1
  double pitch; // fp27
  double yaw; // fp28
  double roll; // fp29
  idClothSim *clothSimulation; // r31
  idPhysics *Physics; // r29
  idPhysics *v12; // r3
  const idVec3 *v13; // r28
  const idMat3 *v14; // r3
  double gravity; // fp10
  idVec3 v16; // [sp+50h] [-70h] BYREF
  idAngles v17; // [sp+60h] [-60h] BYREF

  influencedByWind = this->influencedByWind;
  v3 = 0.0;
  v16 = vec3_origin;
  if ( influencedByWind
    && (next = gameLocal->globalWindEntities.next) != nullptr
    && next != gameLocal->globalWindEntities.head
    && (owner = next->owner) != nullptr )
  {
    CurrentWindStrength = idFuncWind::GetCurrentWindStrength(this: next->owner);
    v16.y = owner->windAngle;
    v16.x = 0.0;
    v16.z = 0.0;
    v3 = CurrentWindStrength;
    idAngles::ToForward(this: &v17, result: &v16);
    pitch = v17.pitch;
    yaw = v17.yaw;
    roll = v17.roll;
  }
  else
  {
    roll = v16.z;
    yaw = v16.y;
    pitch = v16.x;
  }
  clothSimulation = this->clothModel->clothSimulation;
  Physics = idEntity::GetPhysics(this);
  v12 = idEntity::GetPhysics(this);
  v13 = v12->GetOrigin(this: v12, a2: 0);
  v14 = Physics->GetAxis(this: Physics, a2: 0);
  idClothSim::SetOriginAxis(this: clothSimulation, newOrigin: v13, newAxis: v14, updateParticles: false);
  clothSimulation->numIterations = 100;
  clothSimulation->windDirection.x = (float)pitch * (float)v3;
  clothSimulation->windDirection.y = (float)yaw * (float)v3;
  clothSimulation->windDirection.z = (float)roll * (float)v3;
  clothSimulation->timeDelta = idGameTimeManager::GetRealMsPerFrame(
                                 this: &clientGame->gameTimeManager,
                                 type: GAMETIME_SCALED)
                             * (float)0.001;
  gravity = this->clothSystem->gravity;
  clothSimulation->gravity.x = 0.0;
  clothSimulation->gravity.y = 0.0;
  clothSimulation->gravity.z = gravity;
}


// ========================================================================
// ??0idRegimeTile@@QAA@XZ
// EA  : 0x82C77C70
// RVA : 0x00C77C70
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idRegimeTile *__fastcall idRegimeTile::idRegimeTile(idRegimeTile *this)
{
  idDynamicEntity::idDynamicEntity(this);
  this->maxHealth = 70.0;
  this->nonEMPDamageScale = 0.0;
  this->powerDownTime = 5000;
  this->__vftable = (idRegimeTile_vtbl *)&idRegimeTile::`vftable';
  this->sndPowerDown = nullptr;
  this->sndReactivate = nullptr;
  this->propogationDelay = 150;
  this->fadeTime = 1500;
  this->pulseOnTime = 3000;
  this->pulseOffTime = 250;
  this->healthReadout.spawnId.value = 0x1FFF;
  *(_WORD *)&this->startOff = 1;
  this->ignoresPulse = false;
  this->damageable = false;
  this->takeTriggerDmgOnly = false;
  *(_WORD *)&this->master = 1;
  this->controlNode.head = &this->controlNode;
  this->controlNode.owner = nullptr;
  this->controlNode.next = &this->controlNode;
  this->controlNode.prev = &this->controlNode;
  this->tileType = REGIME_TILE_CHILD;
  this->tileChildren.list = nullptr;
  this->tileChildren.granularity = 0;
  this->tileChildren.memTag = 5;
  this->tileChildren.listStatic = 0;
  this->tileChildren.size = 0;
  this->tileChildren.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tileChildren);
  this->health = 0.0;
  this->childPropagationDelay = 1500;
  this->nextActivateIdx = 0;
  this->powered = false;
  return this;
}


// ========================================================================
// __unwind$505242
// EA  : 0x82C77D74
// RVA : 0x00C77D74
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_505242()
{
  int v0; // r12

  idDynamicEntity::~idDynamicEntity(this: *(idDynamicEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$505243
// EA  : 0x82C77D9C
// RVA : 0x00C77D9C
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_505243()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                           + 928));
}


// ========================================================================
// ??0idInventoryStorage@@QAA@XZ
// EA  : 0x82C77E30
// RVA : 0x00C77E30
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idInventoryStorage *__fastcall idInventoryStorage::idInventoryStorage(idInventoryStorage *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idInventoryStorage_vtbl *)&idInventoryStorage::`vftable';
  idInventoryCollection::idInventoryCollection(this: &this->inventory);
  this->startingInventory.list = nullptr;
  this->startingInventory.granularity = 0;
  this->startingInventory.memTag = 5;
  this->startingInventory.listStatic = 0;
  this->startingInventory.size = 0;
  this->startingInventory.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->startingInventory);
  return this;
}


// ========================================================================
// __unwind$505361
// EA  : 0x82C77EAC
// RVA : 0x00C77EAC
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_505361()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$505362
// EA  : 0x82C77ED4
// RVA : 0x00C77ED4
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_505362()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 800));
}


// ========================================================================
// ?Think@idEntityImposter@@UAAXXZ
// EA  : 0x82C78018
// RVA : 0x00C78018
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idEntityImposter::Think(idEntityImposter *this)
{
  idRenderModel *RenderModelFromPresentable; // r3
  idPresentable *presentable; // r3

  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
  if ( RenderModelFromPresentable != nullptr && idRenderModel::IsRendered(this: RenderModelFromPresentable) )
  {
    idDynamicEntity::Think(this);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->Present(this: presentable);
  }
}


// ========================================================================
// ?Think@idDebrisEntity@@UAAXXZ
// EA  : 0x82C78090
// RVA : 0x00C78090
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idDebrisEntity::Think(idDebrisEntity *this)
{
  idDynamicEntity::Think(this);
  if ( this->dieTime < gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
  {
    this->Hide_2(this);
    idEntity::BecomeInactive(this, flags: 3);
  }
  idEntity::RunPhysics(this);
}


// ========================================================================
// ?Think@idAnnouncementManager@@UAAXXZ
// EA  : 0x82C78110
// RVA : 0x00C78110
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idAnnouncementManager::Think(idAnnouncementManager *this)
{
  __int64 v2; // r4
  unsigned int v3; // r7
  __int64 v4; // r10
  unsigned int v5; // r7
  double v6; // fp31

  if ( this->active )
  {
    HIDWORD(v2) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    if ( this->nextPlayTime < SHIDWORD(v2) )
    {
      if ( !this->playedFirst
        || (v3 = 1664525 * clientGame->random.seed + 1013904223,
            clientGame->random.seed = v3,
            LODWORD(v2) = (v3 >> 10) & 0x7FFF,
            (float)((float)v2 * (float)0.000030518509) <= (double)this->chancePerIteration) )
      {
        idAnnouncementManager::PlaySound(this);
      }
      HIDWORD(v4) = 0x82000000;
      v5 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v5 + 1013904223;
      LODWORD(v4) = ((v5 + 1013904223) >> 10) & 0x7FFF;
      v6 = (float)((float)((float)((float)((float)v4 * (float)0.000061037019) - (float)1.0) * this->iterationVariance)
                 + this->iterationDelay);
      this->nextPlayTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
                         - (int)(float)((float)v6 * (float)-1000.0);
    }
  }
}


// ========================================================================
// ??1idGuiEntity@@UAA@XZ
// EA  : 0x82C78260
// RVA : 0x00C78260
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idGuiEntity::~idGuiEntity(idGuiEntity *this)
{
  idRenderModelGui *guiModel; // r3
  idSWF *guiSwf; // r29
  idEntityPtr<idAI2> v4[12]; // [sp+50h] [-30h] BYREF

  this->__vftable = (idGuiEntity_vtbl *)&idGuiEntity::`vftable';
  if ( gameLocal != nullptr )
  {
    v4[0] = (idEntityPtr<idAI2>)this->entityNumber;
    v4[0].spawnId.value |= gameLocal->spawnIds.ptr[v4[0].spawnId.value] << 13;
    idList<idEntityPtr<idPlayer>,5>::Remove(this: (idList<idEntityPtr<idAI2>,5> *)&gameLocal->pauseThinkers, obj: v4);
    v4[0] = (idEntityPtr<idAI2>)this->entityNumber;
    v4[0].spawnId.value |= gameLocal->spawnIds.ptr[v4[0].spawnId.value] << 13;
    idList<idEntityPtr<idPlayer>,5>::Remove(this: (idList<idEntityPtr<idAI2>,5> *)&gameLocal->guiEntities, obj: v4);
  }
  idEntity::FreeRenderModel(this);
  guiModel = this->guiModel;
  if ( guiModel != nullptr )
  {
    v4[0] = (idEntityPtr<idAI2>)this->guiModel;
    guiModel->unlinked = true;
    guiModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: guiModel);
    this->guiModel = nullptr;
  }
  guiSwf = this->guiSwf;
  if ( guiSwf != nullptr )
  {
    v4[0] = (idEntityPtr<idAI2>)this->guiSwf;
    idSWF::~idSWF(this: (idSWF *)v4[0].spawnId.value);
    idMem::Free(this: &mem, ptr: guiSwf, align: ALIGN_16);
    this->guiSwf = nullptr;
  }
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->controlNode);
  this->__vftable = (idGuiEntity_vtbl *)&idDynamicEntity::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$505499
// EA  : 0x82C78384
// RVA : 0x00C78384
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_505499()
{
  int v0; // r12

  idDynamicEntity::~idDynamicEntity(this: *(idDynamicEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$505500
// EA  : 0x82C783AC
// RVA : 0x00C783AC
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_505500()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                           + 924));
}


// ========================================================================
// ?SetupGuiCallbacks@idGuiEntity@@AAAXXZ
// EA  : 0x82C783E0
// RVA : 0x00C783E0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idGuiEntity::SetupGuiCallbacks(idGuiEntity *this)
{
  idPresentable *presentable; // r11
  idRenderModel *model; // r10
  char v4; // r11
  idSWF *v5; // r3
  idSWF *v6; // r3
  idSWFScriptFunction *v7; // r3
  idSWFScriptFunction *v8; // r4
  idSWFScriptFunction *v9; // r3
  idSWFScriptFunction *v10; // r4
  idSWFScriptFunction *v11; // r29
  int value; // r10
  idEntity *v13; // r3
  idEntity *v14; // r3
  idSWFScriptFunction *v15; // r4
  idSWFScriptFunction *v16; // r3
  idSWFScriptFunction *v17; // r4
  idSWFScriptFunction *v18; // r3
  idSWFScriptFunction *v19; // r4
  idSWFScriptVar v20; // [sp+58h] [-68h] BYREF
  idSWFScriptVar v21; // [sp+60h] [-60h] BYREF
  idSWFScriptVar v22; // [sp+68h] [-58h] BYREF
  idSWFScriptVar v23; // [sp+70h] [-50h] BYREF
  idSWFScriptVar v24[9]; // [sp+78h] [-48h] BYREF

  presentable = this->presentable;
  if ( presentable == nullptr || (model = presentable->model, v4 = 1, model == nullptr) )
    v4 = 0;
  if ( v4 != 0 )
  {
    if ( this->guiSwf == nullptr )
    {
      idLib::Warning(
        fmt: "idGuiEntity::Spawn: Please provide at least one swf GUI file for idGuiEntity '%s'!",
        this->name.data);
      v5 = (idSWF *)idMem::AllocWithLocation(
                      this: &mem,
                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                      size: 0x27Cu,
                      tag: TAG_SWF,
                      zeroBuffer: false,
                      align: ALIGN_16,
                      heap: HEAP_DEFAULTHEAP);
      if ( v5 != nullptr )
        v6 = idSWF::idSWF(this: v5, filename_: "default", soundWorld: clientGame->soundWorld, atlasPurgable_: true);
      else
        v6 = nullptr;
      this->guiSwf = v6;
    }
    v7 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0xCu,
                                  tag: TAG_SWF,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
    if ( v7 != nullptr )
    {
      v7[2].__vftable = (idSWFScriptFunction_vtbl *)this;
      v7[1].__vftable = nullptr;
      v8 = v7;
      v7->__vftable = (idSWFScriptFunction_vtbl *)&`idGuiEntity::SetupGuiCallbacks'::`8'::idSWFScriptFunction_ReactivateUsable::`vftable';
    }
    else
    {
      v8 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: &v20, nf: v8);
    idSWFScriptObject::Set(this: this->guiSwf->globals, name: "ReactivateUse", value: &v20);
    idSWFScriptVar::Free(this: &v20);
    v9 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0xCu,
                                  tag: TAG_SWF,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
    if ( v9 != nullptr )
    {
      v9[2].__vftable = (idSWFScriptFunction_vtbl *)this;
      v9[1].__vftable = nullptr;
      v10 = v9;
      v9->__vftable = (idSWFScriptFunction_vtbl *)&`idGuiEntity::SetupGuiCallbacks'::`9'::idSWFScriptFunction_Trigger::`vftable';
    }
    else
    {
      v10 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: &v21, nf: v10);
    idSWFScriptObject::Set(this: this->guiSwf->globals, name: "trigger", value: &v21);
    idSWFScriptVar::Free(this: &v21);
    v11 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x10u,
                                   tag: TAG_SWF,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
    if ( v11 != nullptr )
    {
      value = this->target.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v13 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v13 != nullptr )
          v14 = idEntity::CastTo(c: v13);
        else
          v14 = nullptr;
      }
      else
      {
        v14 = nullptr;
      }
      v11[2].__vftable = (idSWFScriptFunction_vtbl *)this;
      v11[3].__vftable = (idSWFScriptFunction_vtbl *)v14;
      v15 = v11;
      v11[1].__vftable = nullptr;
      v11->__vftable = (idSWFScriptFunction_vtbl *)&`idGuiEntity::SetupGuiCallbacks'::`10'::idSWFScriptFunction_TriggerTarget::`vftable';
    }
    else
    {
      v15 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: &v22, nf: v15);
    idSWFScriptObject::Set(this: this->guiSwf->globals, name: "triggerTarget", value: &v22);
    idSWFScriptVar::Free(this: &v22);
    v16 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 8u,
                                   tag: TAG_SWF,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
    if ( v16 != nullptr )
    {
      v16[1].__vftable = nullptr;
      v17 = v16;
      v16->__vftable = (idSWFScriptFunction_vtbl *)&`idGuiEntity::SetupGuiCallbacks'::`12'::idSWFScriptFunction_PostEvent::`vftable';
    }
    else
    {
      v17 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: &v23, nf: v17);
    idSWFScriptObject::Set(this: this->guiSwf->globals, name: "postEvent", value: &v23);
    idSWFScriptVar::Free(this: &v23);
    v18 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0xCu,
                                   tag: TAG_SWF,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
    if ( v18 != nullptr )
    {
      v18[2].__vftable = (idSWFScriptFunction_vtbl *)this;
      v18[1].__vftable = nullptr;
      v19 = v18;
      v18->__vftable = (idSWFScriptFunction_vtbl *)&`idGuiEntity::SetupGuiCallbacks'::`11'::idSWFScriptFunction_PlayGuiSound::`vftable';
    }
    else
    {
      v19 = nullptr;
    }
    idSWFScriptVar::idSWFScriptVar(this: v24, nf: v19);
    idSWFScriptObject::Set(this: this->guiSwf->globals, name: "playGuiSound", value: v24);
    idSWFScriptVar::Free(this: v24);
    idSWF::Activate(this: this->guiSwf, b: true);
    this->initializedGuis = true;
  }
  else
  {
    idLib::Warning(fmt: "idGuiEntity::Spawn: Missing renderModel for idGuiEntity '%s'!", this->name.data);
  }
}


// ========================================================================
// __unwind$505725_0
// EA  : 0x82C78768
// RVA : 0x00C78768
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_505725_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$505727
// EA  : 0x82C78794
// RVA : 0x00C78794
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_505727()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 192 + 88));
}


// ========================================================================
// __unwind$505729
// EA  : 0x82C787BC
// RVA : 0x00C787BC
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_505729()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$505730
// EA  : 0x82C787E4
// RVA : 0x00C787E4
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_505730()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$505731
// EA  : 0x82C78810
// RVA : 0x00C78810
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_505731()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 192 + 104));
}


// ========================================================================
// __unwind$505733
// EA  : 0x82C78838
// RVA : 0x00C78838
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_505733()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$505735
// EA  : 0x82C78860
// RVA : 0x00C78860
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_505735()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 192 + 120));
}


// ========================================================================
// `idGuiEntity::SetupGuiCallbacks'::`8'::idSWFScriptFunction_ReactivateUsable::Call
// EA  : 0x82C78888
// RVA : 0x00C78888
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idGuiEntity::SetupGuiCallbacks_::_8_::idSWFScriptFunction_ReactivateUsable::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int num; // r11

  num = thisObject->variables.num;
  result->type = SWF_VAR_UNDEF;
  *(_BYTE *)(num + 880) = 0;
  return result;
}


// ========================================================================
// `idGuiEntity::SetupGuiCallbacks'::`11'::idSWFScriptFunction_PlayGuiSound::Call
// EA  : 0x82C788A0
// RVA : 0x00C788A0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idGuiEntity::SetupGuiCallbacks_::_11_::idSWFScriptFunction_PlayGuiSound::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int num; // r11

  num = thisObject->variables.num;
  if ( *(_DWORD *)(num + 916) != 0 )
    idEntity::StartSoundShader(
      this: (idEntity *)num,
      channel: SND_CHANNEL_ITEM,
      shader: *(const idSoundShader **)(num + 916),
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?Spawn@idCoopStartingInventory@@QAAXXZ
// EA  : 0x82C78900
// RVA : 0x00C78900
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idCoopStartingInventory::Spawn(idCoopStartingInventory *this)
{
  idEntityPtr<idCoopStartingInventory> *p_coopStartingInventory; // r9

  if ( gameLocal != nullptr )
  {
    p_coopStartingInventory = &gameLocal->coopStartingInventory;
    if ( this != nullptr )
      p_coopStartingInventory->spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
    else
      p_coopStartingInventory->spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?Spawn@idElectricBoltEmitter@@QAAXXZ
// EA  : 0x82C78B78
// RVA : 0x00C78B78
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idElectricBoltEmitter::Spawn(idElectricBoltEmitter *this)
{
  idElectricBolt *ebolt; // r30
  idElectricBolt *v3; // r3
  idElectricBolt *v4; // r3
  const idDeclElectricBolt *electricBoltSystem; // r28
  idElectricBolt *v6; // r30
  idRenderModelBeam *NumContacts; // r3
  int value; // r10
  idSplinePath *v9; // r3
  idSplinePath *v10; // r4

  ebolt = this->ebolt;
  if ( ebolt != nullptr )
  {
    idElectricBolt::~idElectricBolt(this: this->ebolt);
    idMem::Free(this: &mem, ptr: ebolt, align: ALIGN_16);
    this->ebolt = nullptr;
  }
  v3 = (idElectricBolt *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x320u,
                           tag: TAG_PARTICLE,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idElectricBolt::idElectricBolt(this: v3);
  else
    v4 = nullptr;
  this->ebolt = v4;
  if ( v4 != nullptr )
  {
    electricBoltSystem = this->electricBoltSystem;
    v6 = v4;
    NumContacts = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: (idAnimator_ChannelWeight *)clientGame);
    idElectricBolt::Init(this: v6, _beamModel: NumContacts, _eboltDecl: electricBoltSystem);
  }
  value = this->controlPath.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = (idSplinePath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = idSplinePath::CastTo(c: v9);
  }
  else
  {
    v10 = nullptr;
  }
  idElectricBoltEmitter::SetControlPath(this, controlPath: v10);
  if ( this->startOff )
  {
    this->Hide_2(this);
  }
  else
  {
    idElectricBoltEmitter::TurnOn(this);
    idEntity::BecomeActive(this, flags: 1);
  }
}


// ========================================================================
// __unwind$506300
// EA  : 0x82C78CCC
// RVA : 0x00C78CCC
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_506300()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PARTICLE);
}


// ========================================================================
// ?UpdateControlPath@idElectricBoltEmitter@@AAAXPAV?$idCurve_Spline@VidVec3@@@@@Z
// EA  : 0x82C78D00
// RVA : 0x00C78D00
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idElectricBoltEmitter::UpdateControlPath(idElectricBoltEmitter *this, idCurve_Spline<idVec3> *spline)
{
  __int64 v4; // r8
  __int64 v5; // r9
  int GameMs; // r3
  int v7; // r11
  int v8; // r10
  double v9; // fp0
  float *v10; // r9
  __int64 v11; // r10
  int v12; // r3
  idVec3 *list; // r7
  double z; // fp29
  int v15; // r28
  double y; // fp30
  int v17; // r29
  double x; // fp31
  idVec3 *v19; // r11
  float v20; // r7
  float v21; // r8
  eboltControlNode_t v22; // [sp+60h] [-380h] BYREF
  idStaticList<eboltControlNode_t,32> v23; // [sp+80h] [-360h] BYREF

  if ( spline != nullptr )
  {
    LODWORD(v4) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    if ( spline->IsDone(this: spline, a2: (float)v4) && this->loopControlPath )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v7 = 0;
      if ( spline->times.num > 0 )
      {
        LODWORD(v5) = GameMs;
        v8 = 0;
        v9 = (float)((float)v5 - *spline->times.list);
        do
        {
          ++v7;
          v10 = &spline->times.list[v8++];
          *v10 = *v10 + (float)v9;
        }
        while ( v7 < spline->times.num );
      }
      spline->changed = true;
      idElectricBolt::StopElectricBolt(this: this->ebolt);
    }
    LODWORD(v11) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v12 = idCurve<idVec3>::IndexForTime(this: (idCurve<idVec1> *)spline, time: (float)v11);
    if ( v12 >= 2 )
    {
      v23.granularity = 1;
      v23.listStatic = 1;
      v23.size = 32;
      v23.list = v23.staticList;
      v23.num = 0;
      v23.memTag = 5;
      list = spline->values.list;
      z = list->z;
      v15 = 1;
      y = list->y;
      v17 = v12 - 1;
      x = list->x;
      do
      {
        v19 = spline->values.list;
        v22.startPos.z = z;
        v22.startPos.x = x;
        v22.startPos.y = y;
        v20 = v19[v15].z;
        v21 = v19[v15].y;
        x = v19[v15].x;
        z = v20;
        v22.endPos.x = v19[v15].x;
        y = v21;
        v22.endPos.y = v21;
        v22.endPos.z = v20;
        idList<eboltControlNode_t,5>::Append(this: &v23, obj: &v22);
        --v17;
        ++v15;
      }
      while ( v17 != 0 );
      spline->GetBoundaryType(this: spline);
      idElectricBolt::UpdateControlNodes(this: this->ebolt, _controlNodes: &v23);
      if ( (v23.listStatic == 0 || v23.listStatic == 2) && v23.list != nullptr )
        idMem::Free(this: &mem, ptr: v23.list, align: ALIGN_16);
    }
  }
}


// ========================================================================
// __unwind$506362
// EA  : 0x82C78F60
// RVA : 0x00C78F60
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_506362()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 992 + 128));
}


// ========================================================================
// ?Think@idElectricBoltEmitter@@UAAXXZ
// EA  : 0x82C78F88
// RVA : 0x00C78F88
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idElectricBoltEmitter::Think(idElectricBoltEmitter *this)
{
  int GameMs; // r3

  idDynamicEntity::Think(this);
  if ( (this->thinkFlags & 1) != 0 && this->ebolt != nullptr )
  {
    idElectricBoltEmitter::UpdateControlPath(this, spline: this->spline);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idElectricBolt::Update(this: this->ebolt, currTime: GameMs);
    if ( this->nextResetTime > 0
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->nextResetTime )
    {
      idElectricBoltEmitter::ResetTarget(this);
    }
  }
}


// ========================================================================
// ?Spawn@idFuncCloth@@QAAXXZ
// EA  : 0x82C79030
// RVA : 0x00C79030
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idFuncCloth::Spawn(idFuncCloth *this)
{
  idRenderModel *v2; // r3
  idPresentable *presentable; // r3
  int v4; // r28
  int v5; // r29
  idRenderModelChain::splinePoint_t *v6; // r3
  idFuncCloth::sphereCollisionInfo_t *v7; // r11
  double radius; // fp0
  double z; // fp13
  double y; // fp12
  idList<idVec4,5> v11[4]; // [sp+60h] [-40h] BYREF

  if ( this->clothSystem != nullptr )
  {
    if ( this->clothType == CLOTH_INVALID )
      idLib::Error(fmt: "'%s' has an invalid cloth type", this->name.data);
    v2 = clientGame->renderWorld->AllocRenderModel(this: clientGame->renderWorld, a2: "_cloth", a3: 1, a4: -1);
    this->clothModel = (idRenderModelCloth *)_RTDynamicCast(
                                               inptr: v2,
                                               VfDelta: 0,
                                               SrcType: &idRenderModel `RTTI Type Descriptor',
                                               TargetType: &idRenderModelCloth `RTTI Type Descriptor',
                                               isReference: 0);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->SetRenderModel(this: presentable, a2: this->clothModel, a3: false);
    if ( this->clothModel == nullptr )
      idLib::Error(fmt: "'%s' failed to spawn a cloth render model", this->name.data);
    idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)v11);
    v4 = 0;
    if ( this->sphereCollision.num > 0 )
    {
      v5 = 0;
      do
      {
        v6 = idList<idVec4,5>::Alloc(this: (idList<idRenderModelChain::splinePoint_t,85> *)v11);
        ++v4;
        v7 = &this->sphereCollision.list[v5++];
        radius = v7->radius;
        z = v7->center.z;
        y = v7->center.y;
        v6->value.x = v7->center.x;
        v6->value.y = y;
        v6->value.z = z;
        v6->time = radius;
      }
      while ( v4 < this->sphereCollision.num );
    }
    idRenderModelCloth::CreateClothSim(
      this: this->clothModel,
      clothDecl: this->clothSystem,
      clothType: this->clothType,
      attachPoints: &this->attachPoints,
      collisionSpheres: v11,
      widthOverride: this->widthOverride,
      heightOverride: this->heightOverride,
      hSpacingOverride: this->hSpacingOverride,
      vSpacingOverride: this->vSpacingOverride);
    idEntity::BecomeActive(this, flags: 1);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v11);
  }
}


// ========================================================================
// $LN37_0
// EA  : 0x82C791A8
// RVA : 0x00C791A8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _LN37_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 160 + 96));
}


// ========================================================================
// `idGuiEntity::SetupGuiCallbacks'::`9'::idSWFScriptFunction_Trigger::Call
// EA  : 0x82C79238
// RVA : 0x00C79238
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idGuiEntity::SetupGuiCallbacks_::_9_::idSWFScriptFunction_Trigger::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        __int64 parms,
        __int64 a4,
        __int64 a5)
{
  idSWFScriptVar *v7; // r3
  idEntity *v8; // r29
  idStr v10[2]; // [sp+60h] [-50h] BYREF

  if ( *(_DWORD *)(parms + 4) != 0 )
  {
    v7 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v10, result: *(idStr **)parms, a3: parms, a4, a5);
    v8 = gameLocal->FindEntity(this: gameLocal, a2: v7->value.i);
    idStr::FreeData(this: v10);
    if ( v8 != nullptr )
    {
      idEntity::Activate(this: v8, activator: (idEntity *)thisObject->variables.num);
      result->type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: result);
      result->value.b = true;
    }
    else
    {
      result->type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: result);
      result->value.b = false;
    }
    result->type = SWF_VAR_BOOL;
  }
  else
  {
    idLib::Warning(fmt: "swf trigger: expected entity name");
    result->type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: result);
    result->value.b = false;
    result->type = SWF_VAR_BOOL;
  }
  return result;
}


// ========================================================================
// __unwind$506666
// EA  : 0x82C7931C
// RVA : 0x00C7931C
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_506666()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// `idGuiEntity::SetupGuiCallbacks'::`10'::idSWFScriptFunction_TriggerTarget::Call
// EA  : 0x82C79348
// RVA : 0x00C79348
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idGuiEntity::SetupGuiCallbacks_::_10_::idSWFScriptFunction_TriggerTarget::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idEntity *size; // r3

  size = (idEntity *)thisObject->variables.size;
  if ( size != nullptr )
    idEntity::Activate(this: size, activator: (idEntity *)thisObject->variables.num);
  result->type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: result);
  result->type = SWF_VAR_BOOL;
  result->value.b = true;
  return result;
}


// ========================================================================
// `idGuiEntity::SetupGuiCallbacks'::`12'::idSWFScriptFunction_PostEvent::Call
// EA  : 0x82C793B0
// RVA : 0x00C793B0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idGuiEntity::SetupGuiCallbacks_::_12_::idSWFScriptFunction_PostEvent::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        __int64 parms,
        __int64 a4,
        __int64 a5)
{
  idSWFScriptVar *v5; // r27
  int v6; // r26
  idSWFScriptVar *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  idSWFScriptVar *v11; // r3
  const idEventDef *Event; // r29
  __int64 v13; // r8
  __int64 v14; // r6
  int v15; // r4
  int v16; // r30
  const char *formatspec; // r11
  __int64 v18; // r10
  char *v19; // r14
  idEventArg *v20; // r25
  unsigned int v21; // r11
  idStr *v22; // r4
  idSWFScriptVar *v23; // r3
  _DWORD *v24; // r10
  _DWORD *v25; // r9
  int ii; // ctr
  __int64 v28; // r10
  idSWFScriptVar *v29; // r29
  double v30; // fp31
  __int64 v31; // r10
  int v32; // r8
  int v33; // r7
  int v34; // r6
  int v35; // r5
  int v36; // r4
  double v37; // fp30
  __int64 v38; // r10
  int v39; // r8
  int v40; // r7
  int v41; // r6
  int v42; // r5
  int v43; // r4
  double v44; // fp1
  int n; // ctr
  idStr *v46; // r4
  idSWFScriptVar *v47; // r3
  const idEntity *v48; // r3
  int *v49; // r10
  _DWORD *v50; // r9
  int k; // ctr
  int v52; // r24
  int v53; // r29
  int v54; // r28
  idDeclInfo *v55; // r27
  idStr *v56; // r4
  __int64 v57; // r10
  __int64 v58; // r8
  __int64 v59; // r6
  const char *v60; // r4
  const idDecl *v61; // r27
  int v62; // ctr
  int *v63; // r11
  idSWFScriptVar *v64; // r3
  double v65; // fp1
  int j; // ctr
  idSWFScriptVar *v67; // r3
  int v68; // r3
  int m; // ctr
  __int64 v70; // r10
  idSWFScriptVar *v71; // r29
  double v72; // fp31
  __int64 v73; // r10
  int v74; // r8
  int v75; // r7
  int v76; // r6
  int v77; // r5
  int v78; // r4
  double v79; // fp30
  __int64 v80; // r10
  int v81; // r8
  int v82; // r7
  int v83; // r6
  int v84; // r5
  int v85; // r4
  double v86; // fp1
  int i; // ctr
  idSWFScriptVar *v88; // r3
  idSWFScriptVar *v89; // r3
  int v90; // r6
  int v91; // r5
  int v92; // r4
  int v93; // r3
  const idEventDef *v94; // [sp+50h] [-320h]
  idEventArg *v95; // [sp+54h] [-31Ch]
  float v96[8]; // [sp+5Ch] [-314h] BYREF
  float v97[8]; // [sp+7Ch] [-2F4h] BYREF
  _DWORD v98[8]; // [sp+9Ch] [-2D4h] BYREF
  int v99; // [sp+BCh] [-2B4h] BYREF
  _DWORD v100[7]; // [sp+C0h] [-2B0h] BYREF
  _DWORD v101[8]; // [sp+DCh] [-294h] BYREF
  float v102[8]; // [sp+FCh] [-274h] BYREF
  int v103; // [sp+11Ch] [-254h] BYREF
  idEventArg v104; // [sp+120h] [-250h] BYREF
  idEventArg v105; // [sp+140h] [-230h] BYREF
  char v106; // [sp+154h] [-21Ch]
  int v107; // [sp+158h] [-218h]
  char v108; // [sp+168h] [-208h]
  int v109; // [sp+16Ch] [-204h]
  char v110; // [sp+17Ch] [-1F4h]
  int v111; // [sp+180h] [-1F0h]
  char v112; // [sp+190h] [-1E0h]
  int v113; // [sp+194h] [-1DCh]
  char v114; // [sp+1A4h] [-1CCh]
  int v115; // [sp+1A8h] [-1C8h]
  char v116; // [sp+1B8h] [-1B8h]
  int v117; // [sp+1BCh] [-1B4h]
  char v118; // [sp+1CCh] [-1A4h]
  int v119; // [sp+1D0h] [-1A0h]
  idStr v120; // [sp+1E0h] [-190h] BYREF
  idStr v121; // [sp+200h] [-170h] BYREF
  idStr v122; // [sp+220h] [-150h] BYREF
  idStr v123; // [sp+240h] [-130h] BYREF
  idStr v124; // [sp+260h] [-110h] BYREF
  idStr v125; // [sp+280h] [-F0h] BYREF
  idStr v126; // [sp+2A0h] [-D0h] BYREF

  v5 = result;
  v6 = parms;
  if ( *(int *)(parms + 4) < 2 )
  {
    idLib::Warning(fmt: "swf post event: expected entity name and event name");
    v5->type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: v5);
    v5->value.b = false;
LABEL_21:
    v5->type = SWF_VAR_BOOL;
    return v5;
  }
  v7 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v126, result: *(idStr **)parms, a3: parms, a4, a5);
  v95 = (idEventArg *)gameLocal->FindEntity(this: gameLocal, a2: v7->value.i);
  idStr::FreeData(this: &v126);
  if ( v95 != nullptr )
  {
    v11 = idSWFScriptVar::ToString(
            this: (idSWFScriptVar *)&v120,
            result: (idStr *)(*(_DWORD *)v6 + 8),
            a3: v10,
            a4: v9,
            a5: v8);
    Event = idEventDef::FindEvent(name: (const char *)v11->value.i);
    v94 = Event;
    idStr::FreeData(this: &v120);
    v105.type = 0;
    v105.value.i = 0;
    v16 = 2;
    v106 = 0;
    v107 = 0;
    v108 = 0;
    v109 = 0;
    v110 = 0;
    v111 = 0;
    v112 = 0;
    v113 = 0;
    v114 = 0;
    v115 = 0;
    v116 = 0;
    v117 = 0;
    v118 = 0;
    v119 = 0;
    formatspec = Event->formatspec;
    LODWORD(v18) = *(unsigned __int8 *)formatspec;
    if ( *formatspec != 0 )
    {
      v19 = (char *)Event->formatspec;
      v20 = &v105;
      while ( v16 < *(_DWORD *)(v6 + 4) )
      {
        v21 = (unsigned __int8)*v19;
        if ( v21 > 0x66 )
        {
          switch ( *v19 )
          {
            case 'i':
              goto LABEL_47;
            case 'l':
              v88 = idSWFScriptVar::ToString(
                      this: (idSWFScriptVar *)&v122,
                      result: *(idStr **)v6,
                      a3: v14,
                      a4: v13,
                      a5: v18);
              idLib::Warning(
                fmt: "swf post event (%s): cannot call event with a script list",
                (const char *)v88->value.i);
              idStr::FreeData(this: &v122);
              idSWFScriptVar::idSWFScriptVar(this: v5, b: false);
              return v5;
            case 's':
              goto LABEL_16;
            case 'v':
              LODWORD(v70) = 8 * v16;
              HIDWORD(v70) = 8 * (v16 + 2);
              v71 = (idSWFScriptVar *)(8 * v16 + *(_DWORD *)v6);
              v72 = idSWFScriptVar::ToFloat(
                      this: (idSWFScriptVar *)(HIDWORD(v70) + *(_DWORD *)v6),
                      a2: v15,
                      a3: SHIDWORD(v14),
                      a4: v14,
                      a5: SHIDWORD(v13),
                      a6: v13,
                      a7: v70);
              v79 = idSWFScriptVar::ToFloat(this: v71 + 1, a2: v78, a3: v77, a4: v76, a5: v75, a6: v74, a7: v73);
              v86 = idSWFScriptVar::ToFloat(this: v71, a2: v85, a3: v84, a4: v83, a5: v82, a6: v81, a7: v80);
              LODWORD(v18) = v97;
              v97[3] = v79;
              v97[4] = v72;
              HIBYTE(v97[1]) = 118;
              v97[2] = v86;
              HIDWORD(v18) = (char *)v20 - 4;
              for ( i = 5; i != 0; --i )
              {
                LODWORD(v18) = v18 + 4;
                HIDWORD(v18) += 4;
                *(_DWORD *)HIDWORD(v18) = *(_DWORD *)v18;
              }
              v16 += 3;
              goto LABEL_19;
            case 'x':
              v89 = idSWFScriptVar::ToString(
                      this: (idSWFScriptVar *)&v124,
                      result: *(idStr **)v6,
                      a3: v14,
                      a4: v13,
                      a5: v18);
              idLib::Warning(
                fmt: "swf post event (%s): cannot call event with a variable args",
                (const char *)v89->value.i);
              idStr::FreeData(this: &v124);
              idSWFScriptVar::idSWFScriptVar(this: v5, b: false);
              return v5;
            default:
              goto LABEL_55;
          }
        }
        if ( v21 == 102 )
        {
          LODWORD(v18) = 8 * v16;
          v64 = (idSWFScriptVar *)(8 * v16 + *(_DWORD *)v6);
          HIBYTE(v102[1]) = 102;
          ++v16;
          v65 = idSWFScriptVar::ToFloat(
                  this: v64,
                  a2: v15,
                  a3: SHIDWORD(v14),
                  a4: v14,
                  a5: SHIDWORD(v13),
                  a6: v13,
                  a7: v18);
          LODWORD(v18) = v102;
          v102[2] = v65;
          HIDWORD(v18) = (char *)v20 - 4;
          for ( j = 5; j != 0; --j )
          {
            LODWORD(v18) = v18 + 4;
            HIDWORD(v18) += 4;
            *(_DWORD *)HIDWORD(v18) = *(_DWORD *)v18;
          }
        }
        else if ( v21 > 0x62 )
        {
          if ( v21 == 100 )
          {
            v52 = declManager->GetNumDeclTypes(this: declManager);
            v53 = 0;
            if ( v52 > 0 )
            {
              v54 = 8 * v16;
              while ( 1 )
              {
                v55 = declManager->GetDeclType_2(this: declManager, a2: v53);
                v56 = (idStr *)(v54 + *(_DWORD *)v6);
                ++v16;
                v54 += 8;
                v60 = (const char *)idSWFScriptVar::ToString(
                                      this: (idSWFScriptVar *)&v123,
                                      result: v56,
                                      a3: v59,
                                      a4: v58,
                                      a5: v57)->value.i;
                v61 = v60 != nullptr
                    ? idDeclInfo::FindWithInheritance(this: v55, name: v60, makeDefault: false)
                    : nullptr;
                idStr::FreeData(this: &v123);
                if ( v61 != nullptr )
                  break;
                if ( ++v53 >= v52 )
                {
                  v5 = result;
                  goto LABEL_19;
                }
              }
              v100[1] = v61;
              HIBYTE(v100[0]) = 100;
              LODWORD(v13) = v100;
              v62 = 5;
              v63 = &v99;
              LODWORD(v18) = (char *)&v105 + 20 * v53 - 4;
              do
              {
                HIDWORD(v18) = *++v63;
                LODWORD(v18) = v18 + 4;
                *(_DWORD *)v18 = *v63;
                --v62;
              }
              while ( v62 != 0 );
              v5 = result;
            }
          }
          else
          {
            if ( v21 != 101 )
              goto LABEL_55;
            LODWORD(v18) = 8 * v16;
            v46 = (idStr *)(8 * v16++ + *(_DWORD *)v6);
            v47 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v125, result: v46, a3: v14, a4: v13, a5: v18);
            v48 = gameLocal->FindEntity(this: gameLocal, a2: v47->value.i);
            idEventArg::idEventArg(this: &v104, data: v48);
            v49 = &v103;
            v50 = (_DWORD *)&v20[-1].value.q[3];
            for ( k = 5; k != 0; --k )
              *++v50 = *++v49;
            idStr::FreeData(this: &v125);
          }
        }
        else if ( v21 == 98 )
        {
LABEL_47:
          v67 = (idSWFScriptVar *)(8 * v16 + *(_DWORD *)v6);
          HIBYTE(v101[1]) = 105;
          ++v16;
          v68 = idSWFScriptVar::ToInteger(this: v67);
          LODWORD(v18) = v101;
          v101[2] = v68;
          HIDWORD(v18) = (char *)v20 - 4;
          for ( m = 5; m != 0; --m )
          {
            LODWORD(v18) = v18 + 4;
            HIDWORD(v18) += 4;
            *(_DWORD *)HIDWORD(v18) = *(_DWORD *)v18;
          }
        }
        else if ( v21 > 0x35 )
        {
          if ( v21 != 97 )
            goto LABEL_55;
          LODWORD(v28) = 8 * v16;
          HIDWORD(v28) = 8 * (v16 + 2);
          v29 = (idSWFScriptVar *)(8 * v16 + *(_DWORD *)v6);
          v30 = idSWFScriptVar::ToFloat(
                  this: (idSWFScriptVar *)(HIDWORD(v28) + *(_DWORD *)v6),
                  a2: v15,
                  a3: SHIDWORD(v14),
                  a4: v14,
                  a5: SHIDWORD(v13),
                  a6: v13,
                  a7: v28);
          v37 = idSWFScriptVar::ToFloat(this: v29 + 1, a2: v36, a3: v35, a4: v34, a5: v33, a6: v32, a7: v31);
          v44 = idSWFScriptVar::ToFloat(this: v29, a2: v43, a3: v42, a4: v41, a5: v40, a6: v39, a7: v38);
          LODWORD(v18) = v96;
          v96[3] = v37;
          v96[4] = v30;
          HIBYTE(v96[1]) = 97;
          v96[2] = v44;
          HIDWORD(v18) = (char *)v20 - 4;
          for ( n = 5; n != 0; --n )
          {
            LODWORD(v18) = v18 + 4;
            HIDWORD(v18) += 4;
            *(_DWORD *)HIDWORD(v18) = *(_DWORD *)v18;
          }
          v16 += 3;
        }
        else
        {
          if ( v21 != 53 && (v21 < 0x31 || v21 > 0x32) )
          {
LABEL_55:
            idLib::Error(fmt: "Invalid arg format string for '%s' event.", Event->name);
            return _LN211(a1: v93, a2: v92, a3: v91, a4: v90);
          }
LABEL_16:
          LODWORD(v18) = 8 * v16;
          v22 = (idStr *)(8 * v16++ + *(_DWORD *)v6);
          v23 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v121, result: v22, a3: v14, a4: v13, a5: v18);
          v24 = v98;
          v25 = (_DWORD *)&v20[-1].value.q[3];
          v98[2] = v23->value.i;
          HIBYTE(v98[1]) = 115;
          for ( ii = 5; ii != 0; --ii )
            *++v25 = *++v24;
          idStr::FreeData(this: &v121);
          v20->type = *v19;
        }
LABEL_19:
        ++v19;
        ++v20;
        Event = v94;
        if ( *v19 == 0 )
          break;
      }
    }
    idEventReceiver::ProcessEventArgPtr(this: (idEventReceiver *)&v104, result: v95, ev: Event, args: &v105);
    v5->type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: v5);
    v5->value.b = true;
    goto LABEL_21;
  }
  v5->type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: v5);
  v5->value.b = false;
  v5->type = SWF_VAR_BOOL;
  return v5;
}


// ========================================================================
// $LN211
// EA  : 0x82C79998
// RVA : 0x00C79998
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _LN211()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 880 + 672));
}


// ========================================================================
// __unwind$506772
// EA  : 0x82C799C0
// RVA : 0x00C799C0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_506772()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 880 + 480));
}


// ========================================================================
// __unwind$506774
// EA  : 0x82C799E8
// RVA : 0x00C799E8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_506774()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 880 + 640));
}


// ========================================================================
// __unwind$506775
// EA  : 0x82C79A10
// RVA : 0x00C79A10
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_506775()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 880 + 576));
}


// ========================================================================
// __unwind$506776
// EA  : 0x82C79A38
// RVA : 0x00C79A38
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_506776()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 880 + 544));
}


// ========================================================================
// __unwind$506777
// EA  : 0x82C79A60
// RVA : 0x00C79A60
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_506777()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 880 + 608));
}


// ========================================================================
// ?SetFloat@idGuiEntity@@QAAXPBDM@Z
// EA  : 0x82C79A90
// RVA : 0x00C79A90
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idGuiEntity::SetFloat(idGuiEntity *this, char *name, double value)
{
  idSWFScriptVar v6; // [sp+50h] [-30h] BYREF

  v6.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v6);
  v6.value.f = value;
  v6.type = SWF_VAR_FLOAT;
  idSWFScriptObject::Set(this: this->guiSwf->globals, name, value: &v6);
  idSWFScriptVar::Free(this: &v6);
}


// ========================================================================
// __unwind$507093
// EA  : 0x82C79AF4
// RVA : 0x00C79AF4
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_507093()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetString@idGuiEntity@@QAAXPBD0@Z
// EA  : 0x82C79B28
// RVA : 0x00C79B28
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idGuiEntity::SetString(idGuiEntity *this, char *name, const char *str)
{
  idSWFScriptVar v5[6]; // [sp+50h] [-30h] BYREF

  idSWFScriptVar::idSWFScriptVar(this: v5, s: str);
  idSWFScriptObject::Set(this: this->guiSwf->globals, name, value: v5);
  idSWFScriptVar::Free(this: v5);
}


// ========================================================================
// __unwind$507127
// EA  : 0x82C79B70
// RVA : 0x00C79B70
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_507127()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 128 + 80));
}


// ========================================================================
// ?UpdateCloth@idFuncCloth@@IAAXXZ
// EA  : 0x82C79C60
// RVA : 0x00C79C60
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idFuncCloth::UpdateCloth(idFuncCloth *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idRenderModelCloth *clothModel; // r11
  idPhysics *Physics; // r3
  const idMat3 *v6; // r3
  BOOL influencedByWind; // r5
  unsigned int v8; // r10
  __int64 v9; // r6
  idLinkList<idFuncWind> *next; // r11
  idFuncWind *owner; // r30
  float *CurrentWindDirection; // r3
  double v13; // fp13
  double v14; // fp12
  double valueFloat; // fp31
  double CurrentWindStrength; // fp1
  double z; // fp29
  double y; // fp28
  double x; // fp27
  idRenderModelCloth *v20; // r10
  idClothSim *clothSimulation; // r28
  int v22; // r26
  const idMat3 *p_deferredAxis; // r6
  const idVec3 *p_deferredOrigin; // r5
  idWeaponTraceManager *WeaponTraceMgr; // r3
  bool v26; // r6
  int v27; // r29
  const idVec3 *v28; // r4
  idVehicleState *v29; // r11
  idPhysics *v30; // r30
  idPhysics *v31; // r23
  float *v32; // r3
  float *v33; // r30
  double v34; // fp26
  double v35; // fp25
  double v36; // fp24
  double v37; // fp23
  double v38; // fp22
  double v39; // fp21
  double v40; // fp20
  double v41; // fp19
  double v42; // fp18
  float *v43; // r3
  double v44; // fp8
  double v45; // fp5
  double v47; // fp2
  double v48; // fp1
  double v50; // fp1
  double v51; // fp0
  double v52; // fp13
  double v53; // fp11
  double v54; // fp10
  double v55; // fp8
  double v56; // fp7
  double v57; // fp13
  idPhysics *v58; // r30
  idPhysics *v59; // r3
  const idVec3 *v60; // r29
  const idMat3 *v61; // r3
  idRenderModelCloth *v62; // r3
  idVec3 v63; // [sp+50h] [-310h] BYREF
  idBounds v64; // [sp+60h] [-300h] BYREF
  __int64 v65; // [sp+78h] [-2E8h] BYREF
  idPLogScope v66; // [sp+88h] [-2D8h] BYREF
  idSphere v67; // [sp+90h] [-2D0h] BYREF
  idList<idVehicleState *,5> v68; // [sp+A0h] [-2C0h] BYREF
  _DWORD v69[104]; // [sp+B0h] [-2B0h] BYREF
  idRotation v70[2]; // [sp+250h] [-110h] BYREF

  RD_EventBegin(name: "idFuncCloth::UpdateCloth");
  LODWORD(v2) = "idFuncCloth::UpdateCloth";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v66, pl: &pLog, gMask: v2, label: v3);
  clothModel = this->clothModel;
  if ( clothModel != nullptr && clothModel->clothSimulation != nullptr && g_skipCloth.valueInteger == 0 )
  {
    Physics = idEntity::GetPhysics(this);
    v6 = Physics->GetAxis(this: Physics, a2: 0);
    idRenderModel::SetAxis(this: this->clothModel, a: v6);
    influencedByWind = this->influencedByWind;
    v63 = vec3_origin;
    if ( !influencedByWind )
      goto LABEL_9;
    v8 = 1664525 * clientGame->random.seed;
    HIDWORD(v9) = &vec3_up;
    clientGame->random.seed = v8 + 1013904223;
    LODWORD(v9) = ((v8 + 1013904223) >> 10) & 0x7FFF;
    v65 = v9;
    idRotation::idRotation(
      this: v70,
      rotationOrigin: &vec3_origin,
      rotationVec: &vec3_up,
      rotationAngle: (float)((float)((float)((float)v9 * (float)0.000061037019) - (float)1.0) * (float)22.5));
    next = gameLocal->globalWindEntities.next;
    if ( next == nullptr )
      goto LABEL_9;
    if ( next != gameLocal->globalWindEntities.head && (owner = next->owner) != nullptr )
    {
      CurrentWindDirection = (float *)idFuncWind::GetCurrentWindDirection(
                                        this: (idFuncWind *)&v65,
                                        result: (idVec3 *)next->owner);
      v13 = CurrentWindDirection[1];
      v14 = CurrentWindDirection[2];
      v63.x = *CurrentWindDirection;
      v63.y = v13;
      v63.z = v14;
      operator*=(v: &v63, r: v70);
      valueFloat = cloth_windStrength.valueFloat;
      CurrentWindStrength = idFuncWind::GetCurrentWindStrength(this: owner);
      z = (float)(v63.z * (float)((float)CurrentWindStrength * (float)valueFloat));
      y = (float)(v63.y * (float)((float)CurrentWindStrength * (float)valueFloat));
      x = (float)((float)((float)CurrentWindStrength * (float)valueFloat) * v63.x);
    }
    else
    {
LABEL_9:
      z = v63.z;
      y = v63.y;
      x = v63.x;
    }
    v20 = this->clothModel;
    clothSimulation = v20->clothSimulation;
    if ( this->influencedByBullets )
    {
      v22 = 0;
      v69[12] = 0x1FFF;
      v68.granularity = 1;
      v68.num = 0;
      v68.size = 6;
      v68.list = (idVehicleState **)v69;
      v68.memTag = 5;
      v68.listStatic = 1;
      v69[13] = 0x1FFF;
      v69[29] = 0x1FFF;
      v69[30] = 0x1FFF;
      v69[46] = 0x1FFF;
      v69[47] = 0x1FFF;
      v69[63] = 0x1FFF;
      v69[64] = 0x1FFF;
      v69[80] = 0x1FFF;
      v69[81] = 0x1FFF;
      v69[97] = 0x1FFF;
      v69[98] = 0x1FFF;
      p_deferredAxis = &v20->deferredAxis;
      if ( !v20->useDeferredPosition )
        p_deferredAxis = &v20->g.axis;
      p_deferredOrigin = &v20->deferredOrigin;
      if ( !v20->useDeferredPosition )
        p_deferredOrigin = &v20->g.origin;
      idBounds::FromTransformedBounds(
        this: &v64,
        bounds: &clothSimulation->clothBounds,
        origin: p_deferredOrigin,
        axis: p_deferredAxis);
      v64.b[0].x = v64.b[0].x - (float)5.0;
      v64.b[0].y = v64.b[0].y - (float)5.0;
      v64.b[0].z = v64.b[0].z - (float)5.0;
      v64.b[1].x = v64.b[1].x + (float)5.0;
      v64.b[1].y = v64.b[1].y + (float)5.0;
      v64.b[1].z = v64.b[1].z + (float)5.0;
      WeaponTraceMgr = idClientGame::GetWeaponTraceMgr(this: clientGame);
      idWeaponTraceManager::GetCollisions(this: WeaponTraceMgr, inBounds: &v64, outTraces: &v68);
      if ( v68.num > 0 )
      {
        v27 = 0;
        do
        {
          v28 = (const idVec3 *)&v68.list[v27];
          v29 = v68.list[v27 + 16];
          if ( v29 == (idVehicleState *)2 )
          {
            v30 = idEntity::GetPhysics(this);
            v31 = idEntity::GetPhysics(this);
            v32 = (float *)v30->GetAxis(this: v30, a2: 0);
            v33 = (float *)&v68.list[v27];
            v34 = v32[8];
            v35 = v32[5];
            v36 = v32[2];
            v37 = v32[7];
            v38 = v32[4];
            v39 = v32[1];
            v40 = v32[6];
            v41 = v32[3];
            v42 = *v32;
            v43 = (float *)v31->GetOrigin(this: v31, a2: 0);
            v44 = (float)(*v33 - *v43);
            v45 = (float)(v33[2] - v43[2]);
            _FP4 = (float)((float)25.0 - *(float *)&v68.list[v27 + 15]);
            v47 = (float)((float)(v33[1] - v43[1]) * (float)v37);
            v48 = (float)((float)(v33[1] - v43[1]) * (float)v38);
            __asm { fsel      f0, f4, f30, f6 }
            v67.origin.x = (float)((float)(v33[2] - v43[2]) * (float)v36)
                         + (float)((float)((float)(*v33 - *v43) * (float)v42)
                                 + (float)((float)(v33[1] - v43[1]) * (float)v39));
            v67.radius = _FP0;
            v67.origin.z = (float)((float)v45 * (float)v34) + (float)((float)((float)v44 * (float)v40) + (float)v47);
            v67.origin.y = (float)((float)v45 * (float)v35) + (float)((float)((float)v44 * (float)v41) + (float)v48);
            idClothSim::AddCollisionSphere(this: clothSimulation, collisionSphere: &v67, isAPermanentSphere: false);
          }
          else
          {
            v50 = cloth_weaponPower.valueFloat;
            if ( v29 != (idVehicleState *)1 )
              goto LABEL_22;
            v51 = v28[1].y;
            v52 = v28->y;
            HIDWORD(v65) = &v68.list[v27];
            v53 = v28[1].x;
            v54 = v28->x;
            HIDWORD(v65) = &v68.list[v27];
            v55 = v28[1].z;
            v56 = v28->z;
            HIDWORD(v65) = v28 + 1;
            v57 = (float)((float)(v28[5].x * v28[5].x)
                        - (float)((float)((float)((float)v55 - (float)v56) * (float)((float)v55 - (float)v56))
                                + (float)((float)((float)((float)v53 - (float)v54) * (float)((float)v53 - (float)v54))
                                        + (float)((float)((float)v51 - (float)v52) * (float)((float)v51 - (float)v52)))));
            if ( v57 > 0.0 )
            {
              v50 = (float)((float)(cloth_explosionScale.valueFloat * (float)((float)v57 / (float)(v28[5].x * v28[5].x)))
                          * cloth_weaponPower.valueFloat);
LABEL_22:
              idClothSim::AddWeaponTrace(
                this: clothSimulation,
                start: v28,
                dir: v28 + 3,
                strength: v50,
                causesHoles: v26,
                a6: v29 != (idVehicleState *)1);
            }
          }
          ++v22;
          v27 += 17;
        }
        while ( v22 < v68.num );
      }
      idList<idThread *,58>::Clear(this: &v68);
    }
    v58 = idEntity::GetPhysics(this);
    v59 = idEntity::GetPhysics(this);
    v60 = v59->GetOrigin(this: v59, a2: 0);
    v61 = v58->GetAxis(this: v58, a2: 0);
    idClothSim::SetOriginAxis(this: clothSimulation, newOrigin: v60, newAxis: v61, updateParticles: false);
    clothSimulation->windDirection.x = x;
    clothSimulation->windDirection.y = y;
    clothSimulation->windDirection.z = z;
    v62 = this->clothModel;
    HIDWORD(v65) = &clothSimulation->windDirection;
    idRenderModel::CommitThisFrame(this: v62);
    idPLogScope::~idPLogScope(this: &v66);
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v66);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$507189
// EA  : 0x82C7A1C8
// RVA : 0x00C7A1C8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_507189()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 864 + 660));
}


// ========================================================================
// __unwind$507190
// EA  : 0x82C7A1F0
// RVA : 0x00C7A1F0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_507190()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 864 + 136));
}


// ========================================================================
// __unwind$507191
// EA  : 0x82C7A218
// RVA : 0x00C7A218
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_507191()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 864 + 160));
}


// ========================================================================
// ?UpdateCollisions@idFuncCloth@@IAAXXZ
// EA  : 0x82C7A248
// RVA : 0x00C7A248
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idFuncCloth::UpdateCollisions(idFuncCloth *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idRenderModelCloth *clothModel; // r11
  idClothSim *clothSimulation; // r25
  int i; // r28
  idPlayer *Player; // r3
  idPlayer *v8; // r30
  idPhysics *Physics; // r30
  idPhysics *v10; // r24
  float *v11; // r3
  double v12; // fp31
  double v13; // fp30
  double v14; // fp29
  double v15; // fp28
  double v16; // fp27
  double v17; // fp26
  double v18; // fp25
  double v19; // fp24
  double v20; // fp23
  float *v21; // r3
  double v22; // fp9
  double v23; // fp7
  double v24; // fp6
  double v25; // fp12
  idPLogScope v26; // [sp+58h] [-C8h] BYREF
  float v27; // [sp+60h] [-C0h] BYREF
  float v28; // [sp+64h] [-BCh]
  float v29; // [sp+68h] [-B8h]
  idSphere v30; // [sp+70h] [-B0h] BYREF

  RD_EventBegin(name: "idFuncCloth::UpdateCollisions");
  LODWORD(v2) = "idFuncCloth::UpdateCollisions";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v26, pl: &pLog, gMask: v2, label: v3);
  clothModel = this->clothModel;
  if ( clothModel != nullptr )
  {
    clothSimulation = clothModel->clothSimulation;
    if ( clothSimulation != nullptr && this->collidesWithPlayers )
    {
      for ( i = 0; i < 6; ++i )
      {
        Player = idGameLocal::GetPlayer(this: gameLocal, i);
        v8 = Player;
        if ( Player != nullptr && idEntity::GetPhysics(this: Player) != nullptr )
        {
          v8->GetEyePos(this: v8, a2: (idVec3 *)&v27);
          Physics = idEntity::GetPhysics(this);
          v10 = idEntity::GetPhysics(this);
          v11 = (float *)Physics->GetAxis(this: Physics, a2: 0);
          v12 = v11[8];
          v13 = v11[5];
          v14 = v11[2];
          v15 = v11[7];
          v16 = v11[4];
          v17 = v11[1];
          v18 = v11[6];
          v19 = v11[3];
          v20 = *v11;
          v21 = (float *)v10->GetOrigin(this: v10, a2: 0);
          v22 = (float)(v28 - v21[1]);
          v23 = (float)(v27 - *v21);
          v24 = v21[2];
          v25 = (float)((float)((float)(v29 - v21[2]) * (float)v14)
                      + (float)((float)((float)(v27 - *v21) * (float)v20) + (float)((float)(v28 - v21[1]) * (float)v17)));
          v27 = (float)((float)(v29 - v21[2]) * (float)v14)
              + (float)((float)((float)(v27 - *v21) * (float)v20) + (float)((float)(v28 - v21[1]) * (float)v17));
          v30.radius = cloth_playerCollisionSize.valueFloat;
          v28 = (float)((float)(v29 - (float)v24) * (float)v13)
              + (float)((float)((float)v23 * (float)v19) + (float)((float)v22 * (float)v16));
          v30.origin.y = v28;
          v29 = (float)((float)(v29 - (float)v24) * (float)v12)
              + (float)((float)((float)v23 * (float)v18) + (float)((float)v22 * (float)v15));
          v30.origin.z = v29;
          v30.origin.x = v25;
          idClothSim::AddCollisionSphere(this: clothSimulation, collisionSphere: &v30, isAPermanentSphere: false);
        }
      }
    }
  }
  idPLogScope::~idPLogScope(this: &v26);
  RD_EventEnd();
}


// ========================================================================
// __unwind$507814
// EA  : 0x82C7A420
// RVA : 0x00C7A420
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_507814()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 288 + 128));
}


// ========================================================================
// __unwind$507815
// EA  : 0x82C7A448
// RVA : 0x00C7A448
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_507815()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 288 + 88));
}


// ========================================================================
// ?Think@idFuncCloth@@UAAXXZ
// EA  : 0x82C7A548
// RVA : 0x00C7A548
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idFuncCloth::Think(idFuncCloth *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPhysics *Physics; // r28
  idPhysics *v5; // r27
  int valueInteger; // r29
  idPhysics *v7; // r3
  idClothSim *clothSimulation; // r28
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  idRenderWorld *renderWorld; // r26
  const idMat3 *v11; // r25
  const idVec3 *v12; // r3
  idPLogScope v13[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idFuncCloth::Think");
  LODWORD(v2) = "idFuncCloth::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v13, pl: &pLog, gMask: v2, label: v3);
  if ( g_skipCloth.valueInteger != 0 )
  {
    idPLogScope::~idPLogScope(this: v13);
  }
  else
  {
    if ( g_showCloth.valueInteger > 0 )
    {
      Physics = idEntity::GetPhysics(this);
      v5 = idEntity::GetPhysics(this);
      valueInteger = g_showCloth.valueInteger;
      v7 = Physics;
      GetAxis = Physics->GetAxis;
      clothSimulation = this->clothModel->clothSimulation;
      renderWorld = clientGame->renderWorld;
      v11 = GetAxis(this: v7, a2: 0);
      v12 = v5->GetOrigin(this: v5, a2: 0);
      idClothSim::DebugDraw(this: clothSimulation, offset: v12, axis: v11, renderWorld, debugLevel: valueInteger);
    }
    idEntity::Think(this);
    idFuncCloth::UpdateCollisions(this);
    idFuncCloth::UpdateCloth(this);
    idEntity::UpdateVisuals(this);
    idPLogScope::~idPLogScope(this: v13);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$508103
// EA  : 0x82C7A668
// RVA : 0x00C7A668
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_508103()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$508104
// EA  : 0x82C7A690
// RVA : 0x00C7A690
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_508104()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?Spawn@idGuiEntity@@QAAXXZ
// EA  : 0x82C7A6B8
// RVA : 0x00C7A6B8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idGuiEntity::Spawn(idGuiEntity *this)
{
  idGuiEntity::idGuiEntityInitialState initialState; // r11
  idEntityPtr<idEntity> v3[2]; // [sp+50h] [-20h] BYREF

  idGuiEntity::SetupGuiCallbacks(this);
  if ( this->guiSwf != nullptr )
  {
    initialState = this->initialState;
    this->nextState = initialState;
    if ( initialState != INIT_STATE_READY )
      this->used = true;
    v3[0].spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
    idList<idEntityPtr<idEntity>,58>::Append(
      this: (idList<idEntityPtr<idEntity>,58> *)&gameLocal->pauseThinkers,
      obj: v3);
    v3[0].spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
    idList<idEntityPtr<idEntity>,58>::Append(this: (idList<idEntityPtr<idEntity>,58> *)&gameLocal->guiEntities, obj: v3);
    idEntity::BecomeActive(this, flags: 1);
  }
  else
  {
    idLib::Warning(
      fmt: "idGuiEntity '%s' is missing guiSwf setting and won't function properly, removing from world.",
      this->name.data);
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
  }
}


// ========================================================================
// ?Event_PostSpawn@idRegimeTile@@AAA?AVeventVoid@@XZ
// EA  : 0x82C7A840
// RVA : 0x00C7A840
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

idRegimeTile *__fastcall idRegimeTile::Event_PostSpawn(idRegimeTile *this, idEntity *result)
{
  __int64 v3; // r8
  __int64 v4; // r6
  int v5; // r15
  __int64 v6; // r10
  va *v7; // r3
  int v8; // r20
  int v9; // r22
  int v10; // r23
  int v11; // r21
  int v12; // r25
  _DWORD *v13; // r30
  int v14; // r11
  int v15; // r9
  idEntity *v16; // r3
  idRegimeTile *v17; // r28
  idRegimeTileChild_t *v18; // r27
  idRegimeTile *v19; // r26
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  va *v23; // r3
  idRenderModel *RenderModelFromPresentable; // r29
  idRenderModel *v25; // r30
  idPhysics *Physics; // r3
  float *v27; // r11
  idPhysics *v28; // r3
  const idMat3 *v29; // r3
  char v30; // r10
  char v31; // r15
  char v32; // r14
  char v33; // r10
  char v34; // r10
  idPresentable *v35; // r3
  idPresentable *v36; // r3
  idPhysics *v37; // r3
  float *v38; // r3
  float *presentable; // r11
  idPhysics *v40; // r3
  float *v41; // r10
  idClientGame *v42; // r3
  float *p_axis; // r11
  int v44; // r9
  int v45; // r26
  int v46; // r30
  int v47; // r11
  int v48; // r11
  float z; // r11
  idEventReceiver **v50; // r29
  int v51; // r30
  int v53; // [sp+8h] [-15B8h]
  int v54; // [sp+Ch] [-15B4h]
  int v55; // [sp+10h] [-15B0h]
  int v56; // [sp+14h] [-15ACh]
  int v57; // [sp+18h] [-15A8h]
  idPresentable *v58; // [sp+1Ch] [-15A4h]
  int v59; // [sp+54h] [-156Ch]
  int v60; // [sp+58h] [-1568h]
  soundShaderParms_t v61; // [sp+70h] [-1550h] BYREF
  idEntity *v62; // [sp+110h] [-14B0h] BYREF
  int v63; // [sp+114h] [-14ACh]
  _BYTE v64[504]; // [sp+118h] [-14A8h] BYREF
  _DWORD v65[128]; // [sp+310h] [-12B0h] BYREF
  va v66; // [sp+510h] [-10B0h] BYREF

  v62 = result;
  v63 = 0;
  memset(Dst: v64, Val: 0, Size: sizeof(v64));
  v65[0] = -1;
  memset(Dst: &v65[1], Val: 0, Size: 0x1FCu);
  v60 = 0;
  v5 = 1;
  LODWORD(v6) = g_DebugRegimeTiles.valueInteger;
  if ( g_DebugRegimeTiles.valueInteger != 0 )
  {
    HIDWORD(v4) = result->name.data;
    v7 = va::va(
           this: &v66,
           fmt: "idRegimeTile %s =========================\n",
           a3: v4,
           a4: v3,
           a5: v6,
           a6: v53,
           a7: v54,
           a8: v55,
           a9: v56,
           a10: v57,
           a11: (int)v58);
    idLib::Printf(fmt: v7->buffer);
  }
  if ( LOBYTE(result[1].renderModelInfo.maxTexelDensity) != 0 || BYTE1(result[1].renderModelInfo.maxVisibleRange) != 0 )
  {
    v8 = 0;
    do
    {
      if ( v8 >= 128 )
        break;
      v9 = 0;
      v10 = v65[v8] + 1;
      if ( *(idEntity **)((char *)&v62 + v8 * 4) != nullptr )
      {
        v11 = 0;
        v12 = v5;
        do
        {
          v13 = *(idEntity **)((char *)&v62 + v8 * 4);
          v14 = v13[25];
          if ( v9 >= v14 || v12 >= 128 )
            break;
          if ( v9 < v14
            && (v15 = *(_DWORD *)(v13[24] + v11), gameLocal->spawnIds.ptr[v15 & 0x1FFF] == v15 >> 13)
            && (v16 = gameLocal->entities.ptr[v15 & 0x1FFF]) != nullptr )
          {
            v17 = (idRegimeTile *)idEntity::CastTo(c: v16);
          }
          else
          {
            v17 = nullptr;
          }
          if ( v17 != nullptr )
          {
            v18 = idList<idRegimeTileChild_t,5>::Alloc(this: (idList<idRegimeTileChild_t,5> *)&result[1].renderModelInfo.scale.z);
            v18->index = v10;
            v19 = idRegimeTile::CastTo(c: v17);
            if ( g_DebugRegimeTiles.valueInteger != 0 )
            {
              HIDWORD(v22) = v17->name.data;
              LODWORD(v22) = v18->index;
              v23 = va::va(
                      this: &v66,
                      fmt: "\tAdding child %s with index %d\n",
                      a3: v22,
                      a4: v21,
                      a5: v20,
                      a6: v53,
                      a7: v54,
                      a8: v55,
                      a9: v56,
                      a10: v57,
                      a11: (int)v58);
              idLib::Printf(fmt: v23->buffer);
            }
            if ( v19 != nullptr )
            {
              v59 = v5 + 1;
              v65[v12] = v10;
              *(idEntity **)((char *)&v62 + v12 * 4) = v19;
              ++v12;
              RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this: v17);
              v25 = clientGame->renderWorld->AllocRenderModel(
                      this: clientGame->renderWorld,
                      a2: RenderModelFromPresentable->name.str,
                      a3: 1,
                      a4: -1);
              Physics = idEntity::GetPhysics(this: v17);
              v27 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
              if ( !v25->deferredPositionInitialized || !v25->useDeferredPosition )
              {
                v25->g.origin.x = *v27;
                v25->g.origin.y = v27[1];
                v25->g.origin.z = v27[2];
              }
              v25->deferredOrigin.x = *v27;
              v25->deferredOrigin.y = v27[1];
              v25->deferredOrigin.z = v27[2];
              v28 = idEntity::GetPhysics(this: v17);
              v29 = v28->GetAxis(this: v28, a2: 0);
              idRenderModel::SetAxis(this: v25, a: v29);
              v25->g.scale.x = RenderModelFromPresentable->g.scale.x;
              v25->g.scale.y = RenderModelFromPresentable->g.scale.y;
              v25->g.scale.z = RenderModelFromPresentable->g.scale.z;
              v30 = *((_BYTE *)&v25->g + 105);
              v31 = *((_BYTE *)&v25->g + 104);
              v32 = *((_BYTE *)&v25->g + 106);
              *((_BYTE *)&v25->g + 107) = (16 * ((*((_BYTE *)&RenderModelFromPresentable->g + 107) & 0x10) != 0)) & 0x10
                                        | *((_BYTE *)&v25->g + 107) & 0xEF;
              v33 = (*((_BYTE *)&RenderModelFromPresentable->g + 105) >> 7 << 7) | v30 & 0x7F;
              *((_BYTE *)&v25->g + 105) = v33;
              v34 = (32 * ((*((_BYTE *)&RenderModelFromPresentable->g + 105) & 0x20) != 0)) & 0x20 | v33 & 0xDF;
              *((_BYTE *)&v25->g + 105) = v34;
              *((_BYTE *)&v25->g + 104) = (*((_BYTE *)&RenderModelFromPresentable->g + 104) >> 7 << 7) | v31 & 0x7F;
              *((_BYTE *)&v25->g + 106) = v32 & 0xFE | *((_BYTE *)&RenderModelFromPresentable->g + 106) & 1;
              *((_BYTE *)&v25->g + 105) = (8 * ((*((_BYTE *)&RenderModelFromPresentable->g + 105) & 8) != 0)) & 8
                                        | v34 & 0xF7;
              v25->g.maxTexelDensity = RenderModelFromPresentable->g.maxTexelDensity;
              v25->g.customMaterial = RenderModelFromPresentable->g.customMaterial;
              v25->g.dimShadowClipZ = RenderModelFromPresentable->g.dimShadowClipZ;
              v25->g.maxVisibleRange = RenderModelFromPresentable->g.maxVisibleRange;
              v35 = (idPresentable *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x4B0u,
                                       tag: TAG_PRESENTABLE,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
              v36 = v35 != nullptr
                  ? idPresentable::idPresentable(
                      this: v35,
                      e: nullptr,
                      renderModel_: (idTreeAnimator *)v25,
                      entityNumber_: 0x1FFF,
                      fxDecl_: nullptr)
                  : nullptr;
              v18->presentable = v36;
              v36->Show(this: v36);
              v37 = idEntity::GetPhysics(this: v17);
              v38 = (float *)v37->GetOrigin(this: v37, a2: 0);
              presentable = (float *)v18->presentable;
              presentable[30] = *v38;
              presentable[31] = v38[1];
              presentable[32] = v38[2];
              v40 = idEntity::GetPhysics(this: v17);
              v41 = (float *)v40->GetAxis(this: v40, a2: 0);
              p_axis = (float *)&v18->presentable->axis;
              v42 = clientGame;
              v44 = (int)&v18->presentable->axis.mat[1];
              *p_axis = *v41;
              p_axis[1] = v41[1];
              p_axis[2] = v41[2];
              p_axis[3] = v41[3];
              p_axis[4] = v41[4];
              p_axis[5] = v41[5];
              p_axis[6] = v41[6];
              p_axis[7] = v41[7];
              p_axis[8] = v41[8];
              idClientGame::AddPresentable(
                this: v42,
                presentable: v18->presentable,
                index: -1,
                skipReplication: false,
                a5: (int)(p_axis + 6),
                a6: (int)(v41 + 6),
                a7: v44,
                a8: (int)v41,
                a9: v53,
                a10: v54,
                a11: v55,
                a12: v56,
                a13: v57,
                a14: v58);
              v5 = v59;
              v18->sndPowerDown = v19->sndPowerDown;
              v18->sndReactivate = v19->sndReactivate;
            }
            else
            {
              v18->childEntity.spawnId.value = (gameLocal->spawnIds.ptr[v17->entityNumber] << 13) | v17->entityNumber;
            }
          }
          else
          {
            idLib::Warning(fmt: "%s has a null entity in it's target list in idx %d", v13[4], v9);
          }
          ++v9;
          v11 += 4;
        }
        while ( *(idEntity **)((char *)&v62 + v8 * 4) != nullptr );
      }
      ++v8;
      ++v60;
    }
    while ( v60 < v5 );
    if ( v63 != 0 )
      result[1].renderModelInfo.renderParms.list = *(idRenderParm **)(v63 + 892);
    if ( HIBYTE(result[1].renderModelInfo.maxTexelDensity) == 0 )
    {
      v45 = 0;
      if ( SLODWORD(result[1].renderModelInfo.color.r) > 0 )
      {
        v46 = 0;
        do
        {
          v47 = LODWORD(result[1].renderModelInfo.scale.z) + v46;
          if ( *(_DWORD *)(v47 + 16) != 0 || *(_DWORD *)(v47 + 12) != 0 )
          {
            idPresentable::GetSoundEmitter(this: *(idPresentable **)v47, alloc: true);
            idPresentable::UpdateSound(
              this: *(idPresentable **)(LODWORD(result[1].renderModelInfo.scale.z) + v46),
              origin: (const idVec3 *)(*(_DWORD *)(LODWORD(result[1].renderModelInfo.scale.z) + v46) + 120),
              axis: &mat3_identity,
              velocity: &vec3_origin,
              listenerId: *(_DWORD *)(*(_DWORD *)(LODWORD(result[1].renderModelInfo.scale.z) + v46) + 1076) + 1);
            v48 = LODWORD(result[1].renderModelInfo.scale.z) + v46;
            if ( *(_DWORD *)(v48 + 16) != 0 && idSoundShader::GetMaxLength(this: *(idSoundShader **)(v48 + 16)) == 0 )
            {
              memset(&v61.shakeFalloff, 0, 16);
              v61.minDistance = 0.0;
              v61.maxDistance = 0.0;
              v61.falloff = nullptr;
              v61.distanceFactor = 1.0;
              v61.wetFalloff = nullptr;
              v61.wetMinDistanceOffset = 0.0;
              memset(&v61.maxPlay, 0, 12);
              v61.wetMaxDistanceOffset = 0.0;
              v61.coneAttenuation.innerAngle = 0.0;
              v61.coneAttenuation.outerAngle = 0.0;
              v61.coneAttenuation.outerVolume = -60.0;
              v61.volume.min = 0.0;
              z = result[1].renderModelInfo.scale.z;
              v61.wetVolume = 0.0;
              v61.shakes = 0.0;
              v61.loopFadeInDuration = 0.0;
              v61.headroom = 0.0;
              v61.volume.max = 0.0;
              v61.minShakeDistance = 0.0;
              v61.pitch.granularity = 0.0;
              v61.lowPassMinDistance = 0.0;
              v61.lowPassStrength = 0.0;
              v61.distanceBasedRanges.farMaxRange = 0.0;
              v61.pitch.min = 0.0;
              v61.loopFadeOutDuration = 0.0;
              v61.lfeVolume = -60.0;
              v61.volume.granularity = 0.0;
              v61.pitch.max = 0.0;
              v61.dopplerMultiplier = 1.0;
              v61.maxShakeDistance = 0.0;
              v61.centerChannel = 0.0;
              v61.distanceBasedRanges.nearMinRange = 0.0;
              idPresentable::StartSoundShader(
                this: *(idPresentable **)(LODWORD(z) + v46),
                channel: SND_CHANNEL_AMBIENT,
                shader: *(const idSoundShader **)(LODWORD(z) + v46 + 16),
                parms: &v61,
                peerMask: 0);
            }
          }
          ++v45;
          v46 += 20;
        }
        while ( v45 < SLODWORD(result[1].renderModelInfo.color.r) );
      }
    }
    if ( v60 >= 128 || v5 >= 128 )
      idLib::Warning(fmt: "idRegimeTile '%s' has more than %d nodes", result->name.data, 128);
  }
  if ( g_DebugRegimeTiles.valueInteger != 0 )
    idLib::Printf(fmt: "=========================\n");
  if ( v5 > 1 )
  {
    v50 = &v62;
    v51 = v5 - 1;
    do
    {
      idEventReceiver::PostEventMS(this: *++v50, ev: &EV_Remove, time: 0);
      --v51;
    }
    while ( v51 != 0 );
  }
  idEntity::BecomeInactive(this: result, flags: 1);
  return this;
}


// ========================================================================
// __unwind$508391
// EA  : 0x82C7AFA8
// RVA : 0x00C7AFA8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_508391()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 5568 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?UpdateGuiState@idGuiEntity@@QAAXXZ
// EA  : 0x82C7AFE0
// RVA : 0x00C7AFE0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idGuiEntity::UpdateGuiState(idGuiEntity *this)
{
  idGuiEntity::idGuiEntityInitialState activeState; // r11
  idStaticList<idSWFScriptVar,16> *v3; // r3
  idStaticList<idSWFScriptVar,16> v4; // [sp+50h] [-140h] BYREF
  idStaticList<idSWFScriptVar,16> v5; // [sp+E0h] [-B0h] BYREF

  activeState = this->activeState;
  if ( this->nextState != activeState && this->guiSwf != nullptr )
  {
    if ( activeState == INIT_STATE_INVALID )
    {
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v5);
      idSWFParmList::Append(this: (idSWFParmList *)&v5, i: (idSWFScriptVar::swfScriptVarValue_t *)this->nextState);
      idSWF::Invoke(this: this->guiSwf, functionName: "setState", parms: (const idSWFParmList *)&v5);
      idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v5);
      v3 = &v5;
    }
    else
    {
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v4);
      idSWFParmList::Append(this: (idSWFParmList *)&v4, i: (idSWFScriptVar::swfScriptVarValue_t *)this->activeState);
      idSWFParmList::Append(this: (idSWFParmList *)&v4, i: (idSWFScriptVar::swfScriptVarValue_t *)this->nextState);
      idSWF::Invoke(this: this->guiSwf, functionName: "changeState", parms: (const idSWFParmList *)&v4);
      idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v4);
      v3 = &v4;
    }
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: v3);
    this->activeState = this->nextState;
  }
}


// ========================================================================
// __unwind$508839
// EA  : 0x82C7B0BC
// RVA : 0x00C7B0BC
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_508839()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 400 + 224));
}


// ========================================================================
// __unwind$508840
// EA  : 0x82C7B0E4
// RVA : 0x00C7B0E4
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_508840()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 400 + 80));
}


// ========================================================================
// ?OnActivate@idGuiEntity@@UAAXPAVidEntity@@@Z
// EA  : 0x82C7B118
// RVA : 0x00C7B118
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idGuiEntity::OnActivate(idGuiEntity *this, idEntity *activator)
{
  char *data; // r4
  idStaticList<idSWFScriptVar,16> v5; // [sp+50h] [-B0h] BYREF

  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v5);
  if ( activator != nullptr )
    data = activator->name.data;
  else
    data = &byte_8200D768;
  idSWFParmList::Append(this: (idSWFParmList *)&v5, s: data);
  idSWF::Invoke(this: this->guiSwf, functionName: "triggered", parms: (const idSWFParmList *)&v5);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v5);
}


// ========================================================================
// __unwind$508882
// EA  : 0x82C7B17C
// RVA : 0x00C7B17C
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_508882()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 256 + 80));
}


// ========================================================================
// ?Use@idGuiEntity@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C7B1B0
// RVA : 0x00C7B1B0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

int __fastcall idGuiEntity::Use(idGuiEntity *this, idEntity *activator, const usableState_t usable)
{
  int value; // r9
  idEntity *v7; // r3
  int v8; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3
  idStaticList<idSWFScriptVar,16> v11; // [sp+50h] [-C0h] BYREF

  if ( this->used )
    return 0;
  this->used = true;
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v11);
  idSWFParmList::Append(this: (idSWFParmList *)&v11, s: activator->name.data);
  idSWF::Invoke(this: this->guiSwf, functionName: "use", parms: (const idSWFParmList *)&v11);
  value = this->target.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v7 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v7 != nullptr && idEntity::CastTo(c: v7) != nullptr )
    {
      v8 = this->target.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13 && (v9 = gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
        v10 = idEntity::CastTo(c: v9);
      else
        v10 = nullptr;
      idEntity::Activate(this: v10, activator);
    }
  }
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v11);
  return 1;
}


// ========================================================================
// __unwind$508918
// EA  : 0x82C7B2B4
// RVA : 0x00C7B2B4
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _unwind_508918()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 272 + 80));
}


// ========================================================================
// ?Think@idGuiEntity@@UAAXXZ
// EA  : 0x82C7B2E0
// RVA : 0x00C7B2E0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __fastcall idGuiEntity::Think(idGuiEntity *this)
{
  if ( this->initializedGuis )
  {
    if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) == 0
      && (unsigned __int8)idEntity::UpdateDormant(this) == 0 )
    {
      idGuiEntity::UpdateGuiModel(this);
      idEntity::RunPhysics(this);
      this->UpdateFX(this);
      idEntity::UpdateVisuals(this);
      idEntity::UpdatePVSAreas(this);
      idGuiEntity::UpdateGuiState(this);
    }
  }
  else
  {
    idGuiEntity::SetupGuiCallbacks(this);
  }
}


// ========================================================================
// `dynamic initializer for 'rpParticleAlphaScale''_1
// EA  : 0x833779F8
// RVA : 0x013779F8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _dynamic_initializer_for__rpParticleAlphaScale___1()
{
  rpParticleAlphaScale_1.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpParticleAlphaScale_1;
}


// ========================================================================
// `dynamic initializer for 'rpParticleScale''_1
// EA  : 0x83377A18
// RVA : 0x01377A18
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _dynamic_initializer_for__rpParticleScale___1()
{
  rpParticleScale_1.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpParticleScale_1;
}


// ========================================================================
// `dynamic initializer for 'rpParticleVel''_2
// EA  : 0x83377A38
// RVA : 0x01377A38
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _dynamic_initializer_for__rpParticleVel___2()
{
  rpParticleVel_2.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpParticleVel_2;
}


// ========================================================================
// `dynamic initializer for 'rp_exposure''
// EA  : 0x83377A58
// RVA : 0x01377A58
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void _dynamic_initializer_for__rp_exposure__()
{
  rp_exposure.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rp_exposure;
}


// ========================================================================
// `dynamic initializer for 'cloth_windStrength''
// EA  : 0x83377A78
// RVA : 0x01377A78
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cloth_windStrength__()
{
  idCVar::idCVar(
    this: &cloth_windStrength,
    name: "cloth_windStrength",
    value: "300.0",
    flags: 4,
    description: "strength of cloth response to wind",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cloth_windStrength__);
}


// ========================================================================
// `dynamic initializer for 'cloth_weaponPower''
// EA  : 0x83377AD0
// RVA : 0x01377AD0
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cloth_weaponPower__()
{
  idCVar::idCVar(
    this: &cloth_weaponPower,
    name: "cloth_weaponPower",
    value: "900000.0",
    flags: 4,
    description: "strength of weapon traces",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cloth_weaponPower__);
}


// ========================================================================
// `dynamic initializer for 'cloth_explosionScale''
// EA  : 0x83377B28
// RVA : 0x01377B28
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cloth_explosionScale__()
{
  idCVar::idCVar(
    this: &cloth_explosionScale,
    name: "cloth_explosionScale",
    value: "5.0",
    flags: 4,
    description: "strength of weapon traces",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cloth_explosionScale__);
}


// ========================================================================
// `dynamic initializer for 'cloth_playerCollisionSize''
// EA  : 0x83377B80
// RVA : 0x01377B80
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cloth_playerCollisionSize__()
{
  idCVar::idCVar(
    this: &cloth_playerCollisionSize,
    name: "cloth_playerCollisionSize",
    value: "25.0",
    flags: 4,
    description: "size of player's collision with flags",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cloth_playerCollisionSize__);
}


// ========================================================================
// `dynamic initializer for 'g_DebugRegimeTiles''
// EA  : 0x83377BD8
// RVA : 0x01377BD8
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_DebugRegimeTiles__()
{
  idCVar::idCVar(
    this: &g_DebugRegimeTiles,
    name: "g_DebugRegimeTiles",
    value: "0",
    flags: 1,
    description: "Debug regime tile",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_DebugRegimeTiles__);
}


// ========================================================================
// `dynamic initializer for 'g_showWindDebug''
// EA  : 0x83377C30
// RVA : 0x01377C30
// PDB : w:\tech5\tungsten\game\entities\misc.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showWindDebug__()
{
  idCVar::idCVar(
    this: &g_showWindDebug,
    name: "g_showWindDebug",
    value: "0",
    flags: 2,
    description: "1 = render wind debug, 2 = sound debug",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showWindDebug__);
}

