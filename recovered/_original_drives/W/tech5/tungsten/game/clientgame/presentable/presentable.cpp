
// ========================================================================
// ?Delete@idPresentable@@QAAXXZ
// EA  : 0x82B65598
// RVA : 0x00B65598
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::Delete(idPresentable *this)
{
  int v2; // r10
  int v3; // r8
  int v4; // r7
  int v5; // r6
  int v6; // r5
  int v7; // [sp+8h] [-58h]
  int v8; // [sp+Ch] [-54h]
  int v9; // [sp+10h] [-50h]
  int v10; // [sp+14h] [-4Ch]
  int v11; // [sp+18h] [-48h]
  lobbyUser_t *v12; // [sp+1Ch] [-44h]

  this->Shutdown(this);
  idClientGame::RemovePresentable(
    this: clientGame,
    presentable: (lobbyUser_t *)this,
    a3: v6,
    a4: v5,
    a5: v4,
    a6: v3,
    a7: (int)&ai_useTurnTransitions.valueString.baseBuffer[12],
    a8: v2,
    a9: v7,
    a10: v8,
    a11: v9,
    a12: v10,
    a13: v11,
    a14: v12);
  ((void (__fastcall *)(idPresentable *, int))this->dtr_idPresentable)(a1: this, a2: 1);
}


// ========================================================================
// ?PostSerializeRead@idPresentable@@UAAX_N@Z
// EA  : 0x82B655F8
// RVA : 0x00B655F8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::PostSerializeRead(idPresentable *this, bool firstClientFrame)
{
  int shouldPresentCounter; // r11

  if ( !this->shouldPresent )
  {
    shouldPresentCounter = this->shouldPresentCounter;
    if ( shouldPresentCounter > 0 )
      this->shouldPresentCounter = shouldPresentCounter - 1;
  }
}


// ========================================================================
// ?ShouldLinkPresentableCollision@idPresentable@@MAA_NXZ
// EA  : 0x82B65620
// RVA : 0x00B65620
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

BOOL __fastcall idPresentable::ShouldLinkPresentableCollision(idPresentable *this)
{
  return (_cntlzw(this->hidden) & 0x20) != 0;
}


// ========================================================================
// ?SetClipModelContents@idPresentable@@QAAXH@Z
// EA  : 0x82B65630
// RVA : 0x00B65630
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SetClipModelContents(
        idPresentable *this,
        int newContents,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  int v10; // [sp+8h] [-68h]
  int v11; // [sp+Ch] [-64h]
  int v12; // [sp+10h] [-60h]
  int v13; // [sp+14h] [-5Ch]
  int v14; // [sp+18h] [-58h]
  idPresentable *v15; // [sp+1Ch] [-54h]

  if ( newContents != this->clipModelContents )
    idClientGame::MarkPresentableSerialized(
      this: clientGame,
      presentable: this,
      serialized: true,
      deleted: false,
      a5,
      a6,
      a7,
      a8,
      a9: v10,
      a10: v11,
      a11: v12,
      a12: v13,
      a13: v14,
      a14: v15);
  this->clipModelContents = newContents;
}


// ========================================================================
// ?GetCurrentSoundShader@idPresentable@@QBAPBVidSoundShader@@W4soundChannel_t@@@Z
// EA  : 0x82B65690
// RVA : 0x00B65690
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

const idSoundShader *__fastcall idPresentable::GetCurrentSoundShader(idPresentable *this, const soundChannel_t channel)
{
  idSoundEmitter *soundEmitter; // r11

  soundEmitter = this->soundEmitter;
  if ( soundEmitter != nullptr )
    return ((const idSoundShader *(*)(void))soundEmitter->GetCurrentSoundShader)();
  else
    return nullptr;
}


// ========================================================================
// ?FreeSoundEmitter@idPresentable@@QAAX_N@Z
// EA  : 0x82B656B8
// RVA : 0x00B656B8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::FreeSoundEmitter(idPresentable *this, BOOL immediate)
{
  idSoundEmitter *soundEmitter; // r3

  soundEmitter = this->soundEmitter;
  if ( soundEmitter != nullptr )
  {
    soundEmitter->StopSound(this: soundEmitter, a2: SND_CHANNEL_ANY);
    this->soundEmitter->Free(this: this->soundEmitter, a2: immediate);
    this->soundEmitter = nullptr;
  }
}


// ========================================================================
// ?Show@idPresentable@@UAAXXZ
// EA  : 0x82B65730
// RVA : 0x00B65730
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::Show(idPresentable *this)
{
  idRenderModel *model; // r3
  int v3; // r10
  int v4; // r9
  int v5; // r8
  int v6; // r7
  int v7; // [sp+8h] [-58h]
  int v8; // [sp+Ch] [-54h]
  int v9; // [sp+10h] [-50h]
  int v10; // [sp+14h] [-4Ch]
  int v11; // [sp+18h] [-48h]
  idPresentable *v12; // [sp+1Ch] [-44h]

  model = this->model;
  if ( model != nullptr )
  {
    idRenderModel::CommitThisFrame(this: model);
    idClientGame::MarkPresentableSerialized(
      this: clientGame,
      presentable: this,
      serialized: true,
      deleted: false,
      a5: v6,
      a6: v5,
      a7: v4,
      a8: v3,
      a9: v7,
      a10: v8,
      a11: v9,
      a12: v10,
      a13: v11,
      a14: v12);
  }
  this->StartFX(this, a2: FX_NONE, a3: FX_EXTRA_COND_NONE);
  this->hidden = false;
}


// ========================================================================
// ?ShutdownFXMgr@idPresentable@@IAAXAAVidFXManager@@@Z
// EA  : 0x82B657A8
// RVA : 0x00B657A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::ShutdownFXMgr(idPresentable *this, idFXManager *fxManager)
{
  idFXManager::Shutdown(this: fxManager);
}


// ========================================================================
// ?SetLocalClipModelContents@idPresentable@@QAAXH@Z
// EA  : 0x82B657B0
// RVA : 0x00B657B0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SetLocalClipModelContents(idPresentable *this, int newContents)
{
  idClipModel *clipModel; // r3
  int v4; // r10
  int v5; // r9
  int v6; // r8
  int v7; // r7
  int v8; // [sp+8h] [-58h]
  int v9; // [sp+Ch] [-54h]
  int v10; // [sp+10h] [-50h]
  int v11; // [sp+14h] [-4Ch]
  int v12; // [sp+18h] [-48h]
  idPresentable *v13; // [sp+1Ch] [-44h]

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
  {
    idClipModel::SetContents(this: clipModel, newContents);
    idClientGame::MarkPresentableSerialized(
      this: clientGame,
      presentable: this,
      serialized: true,
      deleted: false,
      a5: v7,
      a6: v6,
      a7: v5,
      a8: v4,
      a9: v8,
      a10: v9,
      a11: v10,
      a12: v11,
      a13: v12,
      a14: v13);
  }
}


// ========================================================================
// ?SetParm@idPresentable@@QAAXPBVidDeclRenderParm@@M@Z
// EA  : 0x82B65800
// RVA : 0x00B65800
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SetParm(idPresentable *this, const idDeclRenderParm *parm, double scalar)
{
  idRenderModel *model; // r3

  model = this->model;
  if ( model != nullptr )
    idRenderModel::SetParm(this: model, parm, scalar);
}


// ========================================================================
// ?SetParm@idPresentable@@QAAXPBVidDeclRenderParm@@VidVec3@@@Z
// EA  : 0x82B65818
// RVA : 0x00B65818
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPresentable::SetParm(
        idPresentable *this,
        const idDeclRenderParm *parm,
        __int64 v3,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  idRenderModel *model; // r3

  model = this->model;
  a11 = *(__int64 *)((char *)&v3 + 4);
  a12 = v3;
  if ( model != nullptr )
    idRenderModel::SetParm(this: model, parm, v3: (const idVec3 *)&a11);
}


// ========================================================================
// ?SetParm@idPresentable@@QAAXPBVidDeclRenderParm@@VidVec4@@@Z
// EA  : 0x82B65850
// RVA : 0x00B65850
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPresentable::SetParm(
        idPresentable *this,
        const idDeclRenderParm *parm,
        __int64 v4,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  idRenderModel *model; // r3

  model = this->model;
  a11 = *(__int64 *)((char *)&v4 + 4);
  a12 = v4;
  if ( model != nullptr )
    idRenderModel::SetParm(this: model, parm, v4: (const idVec4 *)&a11);
}


// ========================================================================
// ?GetParmBlock@idPresentable@@QAAPAVidParmBlock@@XZ
// EA  : 0x82B65888
// RVA : 0x00B65888
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

idStaticParmBlock<32> *__fastcall idPresentable::GetParmBlock(idPresentable *this)
{
  idRenderModel *model; // r11
  idStaticParmBlock<32> *result; // r3

  model = this->model;
  result = nullptr;
  if ( model != nullptr )
    return idRenderModel::GetParmBlock(this: model);
  return result;
}


// ========================================================================
// ?FreeRenderModel@idPresentable@@IAAXXZ
// EA  : 0x82B658A8
// RVA : 0x00B658A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::FreeRenderModel(idPresentable *this)
{
  idRenderModel *model; // r3

  model = this->model;
  if ( model != nullptr )
  {
    model->unlinked = true;
    model->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: model);
  }
  this->SetRenderModel(this, a2: nullptr, a3: true);
}


// ========================================================================
// ?Shutdown@idPresentable@@UAAXXZ
// EA  : 0x82B65908
// RVA : 0x00B65908
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::Shutdown(idPresentable *this)
{
  this->ShutdownFXMgr(this);
  idPresentable::FreeSoundEmitter(this, immediate: false);
}


// ========================================================================
// ?UpdateClientCollision@idPresentable@@MAAXABVidVec3@@ABVidMat3@@01@Z
// EA  : 0x82B65950
// RVA : 0x00B65950
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::UpdateClientCollision(
        idPresentable *this,
        const idVec3 *oldOrigin,
        const idMat3 *oldAxis,
        const idVec3 *newOrigin,
        const idMat3 *newAxis)
{
  idMat3 *p_axis; // r8

  if ( this->clipModel != nullptr && this->clipModelDynamic && !this->overridingClipContents )
  {
    if ( ((unsigned __int8 (__fastcall *)(idPresentable *, const idVec3 *, const idMat3 *, const idVec3 *, const idMat3 *))this->ShouldLinkPresentableCollision)(
           a1: this,
           a2: oldOrigin,
           a3: oldAxis,
           a4: newOrigin,
           a5: newAxis) != 0 )
    {
      if ( this->clipModelDynamicAxis )
        p_axis = &this->axis;
      else
        p_axis = &mat3_identity;
      idClipModel::Link(
        this: this->clipModel,
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->clipModelPhysID,
        newBodyId: 0,
        newOrigin: &this->origin,
        newAxis: p_axis);
    }
    else
    {
      idClipModel::Unlink(this: this->clipModel);
    }
  }
}


// ========================================================================
// ?InheritPropertiesFromModel@idPresentable@@QAAX_N@Z
// EA  : 0x82B65A08
// RVA : 0x00B65A08
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::InheritPropertiesFromModel(idPresentable *this, bool inheritTransform)
{
  idRenderModel *model; // r11
  idVec3 *p_deferredOrigin; // r11
  idRenderModel *v4; // r11
  idMat3 *p_deferredAxis; // r11
  idRenderModel *v6; // r11
  double v7; // fp6
  double v8; // fp4
  idVec3 v9; // [sp+50h] [-20h] BYREF

  model = this->model;
  if ( (int)model <= 10000 )
  {
    this->radius = idPresentable::DEFAULT_PRESENTABLE_RADIUS;
  }
  else
  {
    if ( inheritTransform )
    {
      if ( model->useDeferredPosition )
        p_deferredOrigin = &model->deferredOrigin;
      else
        p_deferredOrigin = &model->g.origin;
      this->origin = *p_deferredOrigin;
      v4 = this->model;
      if ( v4->useDeferredPosition )
        p_deferredAxis = &v4->deferredAxis;
      else
        p_deferredAxis = &v4->g.axis;
      this->axis = *p_deferredAxis;
    }
    v6 = this->model;
    v7 = (float)(v6->referenceBounds.b[1].x + v6->referenceBounds.b[0].x);
    v8 = (float)((float)(v6->referenceBounds.b[0].y + v6->referenceBounds.b[1].y) * (float)0.5);
    v9.z = (float)(v6->referenceBounds.b[0].z + v6->referenceBounds.b[1].z) * (float)0.5;
    v9.y = v8;
    v9.x = (float)v7 * (float)0.5;
    this->radius = idBounds::GetRadius(this: &v6->referenceBounds, center: &v9);
  }
}


// ========================================================================
// ?UpdateModelTransform@idPresentable@@QAAXXZ
// EA  : 0x82B65B60
// RVA : 0x00B65B60
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::UpdateModelTransform(idPresentable *this)
{
  idRenderModel *model; // r3
  float v3; // [sp+50h] [-50h] BYREF
  float v4; // [sp+54h] [-4Ch]
  float v5; // [sp+58h] [-48h]
  idMat3 v6; // [sp+60h] [-40h] BYREF

  if ( this->model != nullptr )
  {
    this->GetWorldTransform(this, a2: (idVec3 *)&v3, a3: &v6);
    model = this->model;
    if ( !model->deferredPositionInitialized || !model->useDeferredPosition )
    {
      model->g.origin.x = v3;
      model->g.origin.y = v4;
      model->g.origin.z = v5;
    }
    model->deferredOrigin.x = v3;
    model->deferredOrigin.y = v4;
    model->deferredOrigin.z = v5;
    idRenderModel::SetAxis(this: model, a: &v6);
  }
}


// ========================================================================
// ?ClientOverrideClipContents@idPresentable@@QAAXH@Z
// EA  : 0x82B65C00
// RVA : 0x00B65C00
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::ClientOverrideClipContents(idPresentable *this, int newContents)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  this->clipModelContents = newContents;
  this->overridingClipContents = true;
  if ( clipModel != nullptr )
  {
    idClipModel::SetContents(this: clipModel, newContents);
    this->clipModel->enabled = true;
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: -1,
      newBodyId: 0,
      newOrigin: &this->origin,
      newAxis: &this->axis);
  }
}


// ========================================================================
// ?GetSoundEmitter@idPresentable@@QAAPAVidSoundEmitter@@_N@Z
// EA  : 0x82B65C70
// RVA : 0x00B65C70
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

idSoundEmitter *__fastcall idPresentable::GetSoundEmitter(idPresentable *this, bool alloc)
{
  idSoundEmitter *v3; // r3

  if ( this->soundEmitter == nullptr && alloc )
  {
    v3 = clientGame->soundWorld->AllocSoundEmitter(this: clientGame->soundWorld);
    this->soundEmitter = v3;
    if ( v3 != nullptr )
      v3->SetDebugName(this: v3, a2: this->debugName);
  }
  return this->soundEmitter;
}


// ========================================================================
// ?UpdateSound@idPresentable@@QAAXABVidVec3@@ABVidMat3@@0H@Z
// EA  : 0x82B65CF0
// RVA : 0x00B65CF0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::UpdateSound(
        idPresentable *this,
        const idVec3 *origin,
        const idMat3 *axis,
        const idVec3 *velocity,
        int listenerId)
{
  idSoundEmitter *SoundEmitter; // r3

  if ( idPresentable::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    SoundEmitter = idPresentable::GetSoundEmitter(this, alloc: false);
    SoundEmitter->UpdateEmitter(this: SoundEmitter, a2: origin, a3: axis, a4: velocity, a5: listenerId);
  }
}


// ========================================================================
// ?IsPlayingSound@idPresentable@@QBA_NW4soundChannel_t@@@Z
// EA  : 0x82B65D58
// RVA : 0x00B65D58
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

BOOL __fastcall idPresentable::IsPlayingSound(idPresentable *this, soundChannel_t channel)
{
  idSoundEmitter *soundEmitter; // r3

  soundEmitter = this->soundEmitter;
  return soundEmitter != nullptr && soundEmitter->IsCurrentlyPlaying(this: soundEmitter, a2: channel);
}


// ========================================================================
// ?FadeSound@idPresentable@@QAAXW4soundChannel_t@@MM@Z
// EA  : 0x82B65D80
// RVA : 0x00B65D80
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::FadeSound(idPresentable *this, soundChannel_t channel, double to, double over)
{
  idSoundEmitter *SoundEmitter; // r3

  if ( idPresentable::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    SoundEmitter = idPresentable::GetSoundEmitter(this, alloc: false);
    ((void (__fastcall *)(idSoundEmitter *, soundChannel_t, double, double, double))SoundEmitter->FadeSound)(
      a1: SoundEmitter,
      a2: channel,
      a3: to,
      a4: over,
      a5: 0.0);
  }
}


// ========================================================================
// ?FadePitch@idPresentable@@QAAXW4soundChannel_t@@MM@Z
// EA  : 0x82B65E10
// RVA : 0x00B65E10
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::FadePitch(idPresentable *this, soundChannel_t channel, double to, double over)
{
  idSoundEmitter *SoundEmitter; // r3

  if ( idPresentable::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    SoundEmitter = idPresentable::GetSoundEmitter(this, alloc: false);
    SoundEmitter->FadePitch(this: SoundEmitter, a2: channel, a3: to, a4: over, a5: 0.0);
  }
}


// ========================================================================
// ?UpdateSound@idPresentable@@QAAXXZ
// EA  : 0x82B65EA0
// RVA : 0x00B65EA0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::UpdateSound(idPresentable *this)
{
  int entityNumber; // r30
  idSoundEmitter *SoundEmitter; // r3

  entityNumber = this->entityNumber;
  if ( idPresentable::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    SoundEmitter = idPresentable::GetSoundEmitter(this, alloc: false);
    SoundEmitter->UpdateEmitter(
      this: SoundEmitter,
      a2: &this->origin,
      a3: &this->axis,
      a4: &vec3_origin,
      a5: entityNumber + 1);
  }
}


// ========================================================================
// ?StartSoundShader@idPresentable@@QAAHW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@E@Z
// EA  : 0x82B65F18
// RVA : 0x00B65F18
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

int __fastcall idPresentable::StartSoundShader(
        idPresentable *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        const soundShaderParms_t *parms,
        unsigned __int8 peerMask)
{
  idSoundEmitter *SoundEmitter; // r3

  if ( shader == nullptr )
    return 0;
  idPresentable::GetSoundEmitter(this, alloc: true);
  if ( idPresentable::GetSoundEmitter(this, alloc: false) == nullptr )
    return 0;
  if ( peerMask != 0 )
    idClientGame::ReplicatePlaySound(
      this: clientGame,
      channel,
      shader,
      parms,
      presentableIndex: this->index,
      pos: &vec3_infinity,
      peerMask);
  SoundEmitter = idPresentable::GetSoundEmitter(this, alloc: false);
  return SoundEmitter->StartSound(this: SoundEmitter, a2: channel, a3: shader, a4: parms);
}


// ========================================================================
// ?SetSoundVolume@idPresentable@@QAAXW4soundChannel_t@@ME@Z
// EA  : 0x82B65FD8
// RVA : 0x00B65FD8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SetSoundVolume(
        idPresentable *this,
        soundChannel_t channel,
        double volume,
        unsigned __int8 peerMask,
        unsigned __int8 a5)
{
  idSoundEmitter *SoundEmitter; // r29
  idSoundEmitter *v10; // r27
  int index; // r26
  int v12; // r29
  const idSoundShader *v13; // r3
  idSoundEmitter *v14; // r3

  if ( idPresentable::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    if ( a5 != 0 )
    {
      SoundEmitter = idPresentable::GetSoundEmitter(this, alloc: false);
      v10 = idPresentable::GetSoundEmitter(this, alloc: false);
      index = this->index;
      v12 = (int)SoundEmitter->GetCurrentSoundShader(this: SoundEmitter, a2: channel);
      v13 = v10->GetCurrentSoundShader(this: v10, a2: channel);
      idClientGame::ReplicateSoundVolume(
        this: clientGame,
        channel,
        shader: v13,
        parms: (const soundShaderParms_t *)(v12 + 64),
        volume,
        presentableIndex: (unsigned __int16)&ai_useTurnTransitions.valueString.baseBuffer[12],
        peerMask: index,
        a8: a5);
    }
    v14 = idPresentable::GetSoundEmitter(this, alloc: false);
    v14->SetVolume(this: v14, a2: channel, a3: volume);
  }
}


// ========================================================================
// ?SetSoundPitch@idPresentable@@QAAXW4soundChannel_t@@ME@Z
// EA  : 0x82B660C0
// RVA : 0x00B660C0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SetSoundPitch(
        idPresentable *this,
        soundChannel_t channel,
        double pitch,
        unsigned __int8 peerMask,
        unsigned __int8 a5)
{
  idSoundEmitter *SoundEmitter; // r29
  idSoundEmitter *v10; // r27
  int index; // r26
  int v12; // r29
  const idSoundShader *v13; // r3
  idSoundEmitter *v14; // r3

  if ( idPresentable::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    if ( a5 != 0 )
    {
      SoundEmitter = idPresentable::GetSoundEmitter(this, alloc: false);
      v10 = idPresentable::GetSoundEmitter(this, alloc: false);
      index = this->index;
      v12 = (int)SoundEmitter->GetCurrentSoundShader(this: SoundEmitter, a2: channel);
      v13 = v10->GetCurrentSoundShader(this: v10, a2: channel);
      idClientGame::ReplicateSoundPitch(
        this: clientGame,
        channel,
        shader: v13,
        parms: (const soundShaderParms_t *)(v12 + 64),
        pitch,
        presentableIndex: (unsigned __int16)&ai_useTurnTransitions.valueString.baseBuffer[12],
        peerMask: index,
        a8: a5);
    }
    v14 = idPresentable::GetSoundEmitter(this, alloc: false);
    v14->SetPitch(this: v14, a2: channel, a3: pitch);
  }
}


// ========================================================================
// ?ModifySound@idPresentable@@QAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@E@Z
// EA  : 0x82B661A8
// RVA : 0x00B661A8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::ModifySound(
        idPresentable *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        const soundShaderParms_t *parms,
        unsigned __int8 peerMask)
{
  idSoundEmitter *SoundEmitter; // r3

  if ( idPresentable::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    if ( peerMask != 0 )
      idClientGame::ReplicateSoundModify(
        this: clientGame,
        channel,
        shader,
        parms,
        presentableIndex: this->index,
        peerMask);
    SoundEmitter = idPresentable::GetSoundEmitter(this, alloc: false);
    SoundEmitter->ModifySound(this: SoundEmitter, a2: channel, a3: shader, a4: parms);
  }
}


// ========================================================================
// ?SetVolumeAdjustment@idPresentable@@QAAXW4soundChannel_t@@ME@Z
// EA  : 0x82B66238
// RVA : 0x00B66238
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SetVolumeAdjustment(
        idPresentable *this,
        soundChannel_t channel,
        double adjustment,
        unsigned __int8 peerMask,
        unsigned __int8 a5)
{
  idSoundEmitter *SoundEmitter; // r29
  idSoundEmitter *v10; // r27
  int index; // r26
  int v12; // r29
  const idSoundShader *v13; // r3
  idSoundEmitter *v14; // r3

  if ( idPresentable::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    if ( a5 != 0 )
    {
      SoundEmitter = idPresentable::GetSoundEmitter(this, alloc: false);
      v10 = idPresentable::GetSoundEmitter(this, alloc: false);
      index = this->index;
      v12 = (int)SoundEmitter->GetCurrentSoundShader(this: SoundEmitter, a2: channel);
      v13 = v10->GetCurrentSoundShader(this: v10, a2: channel);
      idClientGame::ReplicateSoundVolumeAdjustment(
        this: clientGame,
        channel,
        shader: v13,
        parms: (const soundShaderParms_t *)(v12 + 64),
        adjustment,
        presentableIndex: (unsigned __int16)&ai_useTurnTransitions.valueString.baseBuffer[12],
        peerMask: index,
        a8: a5);
    }
    v14 = idPresentable::GetSoundEmitter(this, alloc: false);
    v14->SetVolumeAdjustment(this: v14, a2: adjustment);
  }
}


// ========================================================================
// ?SetClearVolumeAdjustment@idPresentable@@QAAXW4soundChannel_t@@E@Z
// EA  : 0x82B66320
// RVA : 0x00B66320
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SetClearVolumeAdjustment(
        idPresentable *this,
        soundChannel_t channel,
        unsigned __int8 peerMask)
{
  idSoundEmitter *SoundEmitter; // r29
  idSoundEmitter *v7; // r27
  int index; // r26
  int v9; // r29
  const idSoundShader *v10; // r3
  idSoundEmitter *v11; // r3

  if ( idPresentable::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    if ( peerMask != 0 )
    {
      SoundEmitter = idPresentable::GetSoundEmitter(this, alloc: false);
      v7 = idPresentable::GetSoundEmitter(this, alloc: false);
      index = this->index;
      v9 = (int)SoundEmitter->GetCurrentSoundShader(this: SoundEmitter, a2: channel);
      v10 = v7->GetCurrentSoundShader(this: v7, a2: channel);
      idClientGame::ReplicateSoundClearVolumeAdjustment(
        this: clientGame,
        channel,
        shader: v10,
        parms: (const soundShaderParms_t *)(v9 + 64),
        presentableIndex: index,
        peerMask);
    }
    v11 = idPresentable::GetSoundEmitter(this, alloc: false);
    v11->ClearVolumeAdjustment(this: v11);
  }
}


// ========================================================================
// ?StopSound@idPresentable@@QAAXW4soundChannel_t@@E@Z
// EA  : 0x82B663F0
// RVA : 0x00B663F0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::StopSound(idPresentable *this, soundChannel_t channel, unsigned __int8 peerMask)
{
  idSoundEmitter *SoundEmitter; // r3
  idSoundEmitter *v7; // r3

  if ( idPresentable::GetSoundEmitter(this, alloc: false) != nullptr )
  {
    if ( peerMask != 0 )
    {
      SoundEmitter = idPresentable::GetSoundEmitter(this, alloc: false);
      if ( SoundEmitter->IsCurrentlyPlaying(this: SoundEmitter, a2: channel) )
        idClientGame::ReplicateStopSound(this: clientGame, channel, presentableIndex: this->index, peerMask);
    }
    v7 = idPresentable::GetSoundEmitter(this, alloc: false);
    v7->StopSound(this: v7, a2: channel);
  }
}


// ========================================================================
// ?Hide@idPresentable@@UAAX_N@Z
// EA  : 0x82B66498
// RVA : 0x00B66498
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::Hide(idPresentable *this, bool stopFx, int a3, int a4, int a5, int a6, int a7, int a8)
{
  idRenderModel *model; // r31
  int v11; // [sp+8h] [-78h]
  int v12; // [sp+Ch] [-74h]
  int v13; // [sp+10h] [-70h]
  int v14; // [sp+14h] [-6Ch]
  int v15; // [sp+18h] [-68h]
  idPresentable *v16; // [sp+1Ch] [-64h]

  model = this->model;
  if ( model != nullptr )
  {
    if ( !model->unlinked )
    {
      idRenderModel::CommitThisFrame(this: this->model);
      model->unlinked = true;
    }
    idClientGame::MarkPresentableSerialized(
      this: clientGame,
      presentable: this,
      serialized: true,
      deleted: false,
      a5,
      a6,
      a7,
      a8,
      a9: v11,
      a10: v12,
      a11: v13,
      a12: v14,
      a13: v15,
      a14: v16);
  }
  if ( stopFx )
    this->StopAllFX(this);
  this->hidden = true;
  this->hideDuringFirstSSInterval = false;
}


// ========================================================================
// ?ResetFXMgr@idPresentable@@QAAXPBVidDeclFX@@@Z
// EA  : 0x82B66520
// RVA : 0x00B66520
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::ResetFXMgr(idPresentable *this, const idDeclFX *fxDecl_)
{
  idTreeAnimator *v3; // r4

  if ( this->fxDecl == fxDecl_ )
  {
    if ( fxDecl_ != nullptr )
    {
      v3 = (idTreeAnimator *)_RTDynamicCast(
                               inptr: this->model,
                               VfDelta: 0,
                               SrcType: &idRenderModel `RTTI Type Descriptor',
                               TargetType: &idTreeAnimator `RTTI Type Descriptor',
                               isReference: 0);
      if ( v3 != this->fxManager.ta )
        idFXManager::ResetTreeAnimator(this: &this->fxManager, _ta: v3);
    }
  }
  else
  {
    this->fxDecl = fxDecl_;
    this->ShutdownFXMgr(this);
    this->InitFXMgr(this, a2: this->fxDecl);
  }
}


// ========================================================================
// ?StartFX@idPresentable@@UAAXW4fxCondition_t@@W4fxExtraCondition_t@@@Z
// EA  : 0x82B665D8
// RVA : 0x00B665D8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::StartFX(idPresentable *this, int condition, __int32 extraCondition)
{
  unsigned int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idFXManager::StartFX(
    this: &this->fxManager,
    org: &this->origin,
    axis: &this->axis,
    time: GameMs,
    startCondition: condition,
    extraCond: extraCondition);
}


// ========================================================================
// ?LocalStartFX@idPresentable@@UAAXW4fxCondition_t@@@Z
// EA  : 0x82B66630
// RVA : 0x00B66630
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::LocalStartFX(idPresentable *this, int condition)
{
  unsigned int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idFXManager::LocalStartFX(
    this: &this->fxManager,
    org: &this->origin,
    axis: &this->axis,
    time: GameMs,
    start: condition);
}


// ========================================================================
// ?StopFX@idPresentable@@QAAXW4fxCondition_t@@W4fxExtraCondition_t@@@Z
// EA  : 0x82B66698
// RVA : 0x00B66698
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::StopFX(idPresentable *this, int condition, fxExtraCondition_t extraCondition)
{
  int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idFXManager::StopFX(
    this: &this->fxManager,
    time: GameMs,
    stopCondition: condition,
    extraCondition,
    immediateStop: false);
}


// ========================================================================
// ?LocalStopFX@idPresentable@@QAAXW4fxCondition_t@@@Z
// EA  : 0x82B666E8
// RVA : 0x00B666E8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::LocalStopFX(idPresentable *this, int condition)
{
  int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idFXManager::LocalStopFX(this: &this->fxManager, time: GameMs, stop: condition, immediateStop: false);
}


// ========================================================================
// ?StopAllFX@idPresentable@@UAAXXZ
// EA  : 0x82B66748
// RVA : 0x00B66748
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::StopAllFX(idPresentable *this)
{
  int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idFXManager::StopAllFX(this: &this->fxManager, time: GameMs, immediateStop: true);
}


// ========================================================================
// ?LocalStopAllFX@idPresentable@@QAAXXZ
// EA  : 0x82B66798
// RVA : 0x00B66798
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::LocalStopAllFX(idPresentable *this)
{
  int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idFXManager::LocalStopAllFX(this: &this->fxManager, time: GameMs, immediateStop: true);
}


// ========================================================================
// ?UpdateFX@idPresentable@@QAAXMMAAVidFXManager@@@Z
// EA  : 0x82B667E8
// RVA : 0x00B667E8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::UpdateFX(
        idPresentable *this,
        double fovScale,
        double depthHack,
        idFXManager *fxManager,
        int a5,
        idFXManager *a6)
{
  _BYTE v10[16]; // [sp+50h] [-60h] BYREF
  _BYTE v11[40]; // [sp+60h] [-50h] BYREF

  if ( a6->initialized )
  {
    this->GetWorldTransform(this, a2: (idVec3 *)v10, a3: (idMat3 *)v11);
    this->UpdateFX(this, a2: (const idVec3 *)v10, a3: (const idMat3 *)v11, a4: a6, a5: fovScale, a6: depthHack);
  }
}


// ========================================================================
// ?UpdateFX@idPresentable@@UAAXABVidVec3@@ABVidMat3@@AAVidFXManager@@MM@Z
// EA  : 0x82B66880
// RVA : 0x00B66880
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::UpdateFX(
        idPresentable *this,
        const idVec3 *origin,
        const idMat3 *axis,
        idFXManager *fxManager,
        double fovScale,
        double depthHack)
{
  int v12; // r25
  unsigned int GameMsPerFrame; // r26
  int GameMs; // r3
  double v15; // fp8
  double v16; // fp6
  idVec3 v17; // [sp+60h] [-60h] BYREF

  v12 = idAccolade::Count(this: &clientGame->gameTimeManager);
  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v15 = (float)(this->origins[1].y - this->origins[0].y);
  v16 = (float)(this->origins[1].z - this->origins[0].z);
  v17.x = this->origins[1].x - this->origins[0].x;
  v17.y = v15;
  v17.z = v16;
  idFXManager::Update(
    this: fxManager,
    parentOrigin: origin,
    parentAxis: axis,
    parentVel: &v17,
    time: GameMs,
    gameMsPerFrame: GameMsPerFrame,
    frameNum: v12,
    fovScale,
    depthHack);
}


// ========================================================================
// ?GetLocalPlayerTeamNumber@idPresentable@@ABAHXZ
// EA  : 0x82B66958
// RVA : 0x00B66958
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

gameTeam_t __fastcall idPresentable::GetLocalPlayerTeamNumber(idPresentable *this)
{
  if ( clientGame != nullptr && idClientGame::GetLocalPresentablePlayer(this: clientGame) != nullptr )
    return idClientGame::GetLocalPresentablePlayer(this: clientGame)->team;
  else
    return -1;
}


// ========================================================================
// ?IdentifyFriendFoeNeutral@idPresentable@@AAAXXZ
// EA  : 0x82B669B8
// RVA : 0x00B669B8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::IdentifyFriendFoeNeutral(idPresentable *this)
{
  gameTeam_t team; // r11
  int ownerPlayerIndex; // r4

  if ( clientGame != nullptr
    && idClientGame::GetLocalPresentablePlayer(this: clientGame) != nullptr
    && idClientGame::GetLocalPresentablePlayer(this: clientGame)->team != -1 )
  {
    team = this->team;
    this->curIFF = IFFN_NEUTRAL;
    if ( team != TEAM_NONE )
    {
      this->curIFF = ((_cntlzw(idPresentable::GetLocalPlayerTeamNumber(this) - this->team) & 0x20) == 0) + 1;
    }
    else
    {
      ownerPlayerIndex = this->ownerPlayerIndex;
      if ( ownerPlayerIndex != -1 )
        this->curIFF = ((_cntlzw((unsigned __int8)idClientGame::PlayerIndexIsLocal(
                                                    this: clientGame,
                                                    playerNum: ownerPlayerIndex))
                       & 0x20) != 0)
                     + 1;
    }
  }
  else
  {
    this->curIFF = IFFN_UNINITIALIZED;
  }
}


// ========================================================================
// ?InitFXMgr@idPresentable@@IAAXPBVidDeclFX@@AAVidFXManager@@@Z
// EA  : 0x82B66A88
// RVA : 0x00B66A88
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::InitFXMgr(idPresentable *this, const idDeclFX *_fxDecl, idFXManager *fxManager)
{
  __int64 v6; // r10
  idClientGame *v7; // r7
  idRenderWorld *renderWorld; // r5
  fxEmitterSound_t v9[6]; // [sp+50h] [-30h] BYREF

  if ( _fxDecl != nullptr )
  {
    v9[0].emitter = idPresentable::GetSoundEmitter(this, alloc: true);
    v9[0].channel = SND_CHANNEL_FX;
    HIDWORD(v6) = _RTDynamicCast(
                    inptr: this->model,
                    VfDelta: 0,
                    SrcType: &idRenderModel `RTTI Type Descriptor',
                    TargetType: &idTreeAnimator `RTTI Type Descriptor',
                    isReference: 0);
    v7 = clientGame;
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    LODWORD(v6) = (v7->random.seed >> 10) & 0x7FFF;
    renderWorld = clientGame->renderWorld;
    v9[1] = (fxEmitterSound_t)v6;
    idFXManager::Init(
      this: fxManager,
      declFX: _fxDecl,
      _rw: renderWorld,
      _soundInfo: v9,
      _gameLibEffects: &clientGame->gameLibEffects,
      diversity: (float)((float)v6 * (float)0.000030518509),
      _ta: (idTreeAnimator *)&ai_useTurnTransitions.valueString.baseBuffer[12],
      a8: (idTreeAnimator *)HIDWORD(v6));
  }
}


// ========================================================================
// ?ShutdownFXMgr@idPresentable@@MAAXXZ
// EA  : 0x82B66B60
// RVA : 0x00B66B60
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::ShutdownFXMgr(idPresentable *this)
{
  idFXManager::Shutdown(this: &this->fxManager);
}


// ========================================================================
// ?SetTeam@idPresentable@@QAAXW4gameTeam_t@@@Z
// EA  : 0x82B66B68
// RVA : 0x00B66B68
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SetTeam(idPresentable *this, gameTeam_t newTeam)
{
  unsigned int GameMs; // r3

  this->team = newTeam;
  idPresentable::IdentifyFriendFoeNeutral(this);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idFXManager::StartFX(
    this: &this->fxManager,
    org: &this->origin,
    axis: &this->axis,
    time: GameMs,
    startCondition: 46,
    extraCond: 0);
}


// ========================================================================
// ?SetOwnerPlayerIndex@idPresentable@@QAAXH@Z
// EA  : 0x82B66BD0
// RVA : 0x00B66BD0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SetOwnerPlayerIndex(idPresentable *this, int value)
{
  this->ownerPlayerIndex = value;
  idPresentable::IdentifyFriendFoeNeutral(this);
}


// ========================================================================
// ?CreateMoveableClipModel@idPresentable@@SAPAVidClipModel@@ABVidClipModelInfo@@PAVidRenderModel@@ABVidVec3@@_NMPBD@Z
// EA  : 0x82B66BE0
// RVA : 0x00B66BE0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

idClipModel *__fastcall idPresentable::CreateMoveableClipModel(
        const idClipModelInfo *clipModelInfo,
        idRenderModel *renderModel,
        const idVec3 *renderModelScale,
        bool barrelCollision,
        double overrideRadius,
        const char *debugName,
        const char *a7)
{
  float *p_z; // r9
  int v10; // ctr
  double z; // fp31
  idSysMutex *p_viewNoteMutex; // r10
  float *v17; // r9
  int v18; // ctr
  idSysMutex *v19; // r10
  float *v20; // r9
  int v21; // ctr
  idSysMutex *v22; // r10
  float *v23; // r9
  int v24; // ctr
  idSysMutex *v25; // r10
  float *v26; // r9
  int v27; // ctr
  idSysMutex *v28; // r10
  float *v29; // r9
  int v30; // ctr
  idSysMutex *v31; // r10
  float *v32; // r9
  int v33; // ctr
  idSysMutex *v34; // r10
  float *v35; // r9
  int v36; // ctr
  idSysMutex *v37; // r10
  float *v38; // r9
  int v39; // ctr
  idSysMutex *v40; // r10
  idSysMutex *v41; // r11
  int v42; // ctr
  float *v43; // r10
  idClipModelInfo::clipModelType_t type; // r11
  int v45; // r27
  char *str; // r4
  char v48; // r11
  int v49; // r3
  bool v50; // cr58
  double x; // fp30
  double y; // fp29
  double v53; // fp28
  double v54; // fp27
  double v55; // fp26
  const char *v56; // r4
  idClipModelInfo::clipModelType_t v57; // r11
  double v58; // fp10
  double v59; // fp9
  double v60; // fp8
  double v61; // fp7
  double v62; // fp6
  double v63; // fp5
  double v64; // fp4
  double v65; // fp3
  bool v66; // cr58
  int numSides; // r29
  const idMat3 *v68; // r3
  int v69; // r5
  idTraceModel *v70; // r28
  int i; // r29
  idClipModel *v72; // r3
  idBounds v73; // [sp+50h] [-3CF0h] BYREF
  unsigned __int64 v74; // [sp+68h] [-3CD8h]
  idRotation v75; // [sp+70h] [-3CD0h] BYREF
  idTraceModel v76; // [sp+C0h] [-3C80h] BYREF
  idTraceModel v77; // [sp+6C0h] [-3680h] BYREF
  int v78; // [sp+1280h] [-2AC0h]
  int v79; // [sp+1284h] [-2ABCh]
  int v80; // [sp+1288h] [-2AB8h]
  int v81; // [sp+128Ch] [-2AB4h]
  int v82; // [sp+1290h] [-2AB0h]
  float v83; // [sp+1294h] [-2AACh]
  float v84; // [sp+1298h] [-2AA8h]
  float v85[8]; // [sp+129Ch] [-2AA4h] BYREF
  __int16 v86; // [sp+12BCh] [-2A84h]
  __int16 v87; // [sp+12BEh] [-2A82h]
  int v88; // [sp+1880h] [-24C0h]
  int v89; // [sp+1884h] [-24BCh]
  int v90; // [sp+1888h] [-24B8h]
  int v91; // [sp+188Ch] [-24B4h]
  int v92; // [sp+1890h] [-24B0h]
  float v93; // [sp+1894h] [-24ACh]
  float v94; // [sp+1898h] [-24A8h]
  float v95[8]; // [sp+189Ch] [-24A4h] BYREF
  __int16 v96; // [sp+18BCh] [-2484h]
  __int16 v97; // [sp+18BEh] [-2482h]
  int v98; // [sp+1E80h] [-1EC0h]
  int v99; // [sp+1E84h] [-1EBCh]
  int v100; // [sp+1E88h] [-1EB8h]
  int v101; // [sp+1E8Ch] [-1EB4h]
  int v102; // [sp+1E90h] [-1EB0h]
  float v103; // [sp+1E94h] [-1EACh]
  float v104; // [sp+1E98h] [-1EA8h]
  float v105[8]; // [sp+1E9Ch] [-1EA4h] BYREF
  __int16 v106; // [sp+1EBCh] [-1E84h]
  __int16 v107; // [sp+1EBEh] [-1E82h]
  int v108; // [sp+2480h] [-18C0h]
  int v109; // [sp+2484h] [-18BCh]
  int v110; // [sp+2488h] [-18B8h]
  int v111; // [sp+248Ch] [-18B4h]
  int v112; // [sp+2490h] [-18B0h]
  float v113; // [sp+2494h] [-18ACh]
  float v114; // [sp+2498h] [-18A8h]
  float v115[8]; // [sp+249Ch] [-18A4h] BYREF
  __int16 v116; // [sp+24BCh] [-1884h]
  __int16 v117; // [sp+24BEh] [-1882h]
  int v118; // [sp+2A80h] [-12C0h]
  int v119; // [sp+2A84h] [-12BCh]
  int v120; // [sp+2A88h] [-12B8h]
  int v121; // [sp+2A8Ch] [-12B4h]
  int v122; // [sp+2A90h] [-12B0h]
  float v123; // [sp+2A94h] [-12ACh]
  float v124; // [sp+2A98h] [-12A8h]
  float v125[8]; // [sp+2A9Ch] [-12A4h] BYREF
  __int16 v126; // [sp+2ABCh] [-1284h]
  __int16 v127; // [sp+2ABEh] [-1282h]
  int v128; // [sp+3080h] [-CC0h]
  int v129; // [sp+3084h] [-CBCh]
  int v130; // [sp+3088h] [-CB8h]
  int v131; // [sp+308Ch] [-CB4h]
  int v132; // [sp+3090h] [-CB0h]
  float v133; // [sp+3094h] [-CACh]
  float v134; // [sp+3098h] [-CA8h]
  float v135[8]; // [sp+309Ch] [-CA4h] BYREF
  __int16 v136; // [sp+30BCh] [-C84h]
  __int16 v137; // [sp+30BEh] [-C82h]
  int v138; // [sp+3680h] [-6C0h]
  int v139; // [sp+3684h] [-6BCh]
  int v140; // [sp+3688h] [-6B8h]
  int v141; // [sp+368Ch] [-6B4h]
  int v142; // [sp+3690h] [-6B0h]
  float v143; // [sp+3694h] [-6ACh]
  float v144; // [sp+3698h] [-6A8h]
  float v145[8]; // [sp+369Ch] [-6A4h] BYREF
  __int16 v146; // [sp+36BCh] [-684h]
  __int16 v147; // [sp+36BEh] [-682h]
  int v148; // [sp+3C80h] [-C0h]
  int v149; // [sp+3C84h] [-BCh]
  int v150; // [sp+3C88h] [-B8h]
  int v151; // [sp+3C8Ch] [-B4h]
  int v152; // [sp+3C90h] [-B0h]
  float v153; // [sp+3C94h] [-ACh]
  float v154; // [sp+3C98h] [-A8h]
  float v155[8]; // [sp+3C9Ch] [-A4h] BYREF
  __int16 v156; // [sp+3CBCh] [-84h]
  __int16 v157; // [sp+3CBEh] [-82h]

  p_z = &v76.offset.z;
  v10 = 6;
  z = 0.0;
  v76.offset.x = 0.0;
  v76.offset.y = 0.0;
  v76.offset.z = 0.0;
  memset(&v76.type, 0, 20);
  p_viewNoteMutex = &analysisClient.viewNoteMutex;
  do
  {
    ++p_viewNoteMutex;
    *++p_z = *(float *)&p_viewNoteMutex->handle;
    --v10;
  }
  while ( v10 != 0 );
  v76.radius = 0.0;
  v17 = &v77.offset.z;
  v77.offset.x = 0.0;
  v77.offset.y = 0.0;
  v76.isConvex = false;
  v77.offset.z = 0.0;
  v76.pad[2] = 0;
  v76.pad[1] = 0;
  v18 = 6;
  v76.pad[0] = 0;
  memset(&v77.type, 0, 20);
  v19 = &analysisClient.viewNoteMutex;
  do
  {
    ++v19;
    *++v17 = *(float *)&v19->handle;
    --v18;
  }
  while ( v18 != 0 );
  v77.radius = 0.0;
  v20 = v85;
  v83 = 0.0;
  v84 = 0.0;
  v77.isConvex = false;
  v85[0] = 0.0;
  v77.pad[2] = 0;
  v77.pad[1] = 0;
  v21 = 6;
  v77.pad[0] = 0;
  v78 = 0;
  v22 = &analysisClient.viewNoteMutex;
  v79 = 0;
  v80 = 0;
  v81 = 0;
  v82 = 0;
  do
  {
    ++v22;
    *++v20 = *(float *)&v22->handle;
    --v21;
  }
  while ( v21 != 0 );
  v85[7] = 0.0;
  v23 = v95;
  v93 = 0.0;
  v94 = 0.0;
  v95[0] = 0.0;
  v87 = 0;
  v24 = 6;
  v86 = 0;
  v88 = 0;
  v25 = &analysisClient.viewNoteMutex;
  v89 = 0;
  v90 = 0;
  v91 = 0;
  v92 = 0;
  do
  {
    ++v25;
    *++v23 = *(float *)&v25->handle;
    --v24;
  }
  while ( v24 != 0 );
  v95[7] = 0.0;
  v26 = v105;
  v103 = 0.0;
  v104 = 0.0;
  v105[0] = 0.0;
  v97 = 0;
  v27 = 6;
  v96 = 0;
  v98 = 0;
  v28 = &analysisClient.viewNoteMutex;
  v99 = 0;
  v100 = 0;
  v101 = 0;
  v102 = 0;
  do
  {
    ++v28;
    *++v26 = *(float *)&v28->handle;
    --v27;
  }
  while ( v27 != 0 );
  v105[7] = 0.0;
  v29 = v115;
  v113 = 0.0;
  v114 = 0.0;
  v115[0] = 0.0;
  v107 = 0;
  v30 = 6;
  v106 = 0;
  v108 = 0;
  v31 = &analysisClient.viewNoteMutex;
  v109 = 0;
  v110 = 0;
  v111 = 0;
  v112 = 0;
  do
  {
    ++v31;
    *++v29 = *(float *)&v31->handle;
    --v30;
  }
  while ( v30 != 0 );
  v115[7] = 0.0;
  v32 = v125;
  v123 = 0.0;
  v124 = 0.0;
  v125[0] = 0.0;
  v117 = 0;
  v33 = 6;
  v116 = 0;
  v118 = 0;
  v34 = &analysisClient.viewNoteMutex;
  v119 = 0;
  v120 = 0;
  v121 = 0;
  v122 = 0;
  do
  {
    ++v34;
    *++v32 = *(float *)&v34->handle;
    --v33;
  }
  while ( v33 != 0 );
  v125[7] = 0.0;
  v35 = v135;
  v133 = 0.0;
  v134 = 0.0;
  v135[0] = 0.0;
  v127 = 0;
  v36 = 6;
  v126 = 0;
  v128 = 0;
  v37 = &analysisClient.viewNoteMutex;
  v129 = 0;
  v130 = 0;
  v131 = 0;
  v132 = 0;
  do
  {
    ++v37;
    *++v35 = *(float *)&v37->handle;
    --v36;
  }
  while ( v36 != 0 );
  v135[7] = 0.0;
  v38 = v145;
  v143 = 0.0;
  v144 = 0.0;
  v145[0] = 0.0;
  v137 = 0;
  v39 = 6;
  v136 = 0;
  v138 = 0;
  v40 = &analysisClient.viewNoteMutex;
  v139 = 0;
  v140 = 0;
  v141 = 0;
  v142 = 0;
  do
  {
    ++v40;
    *++v38 = *(float *)&v40->handle;
    --v39;
  }
  while ( v39 != 0 );
  v145[7] = 0.0;
  v153 = 0.0;
  v154 = 0.0;
  v147 = 0;
  v41 = &analysisClient.viewNoteMutex;
  v146 = 0;
  v42 = 6;
  v43 = v155;
  v155[0] = 0.0;
  v148 = 0;
  v149 = 0;
  v150 = 0;
  v151 = 0;
  v152 = 0;
  do
  {
    ++v41;
    *++v43 = *(float *)&v41->handle;
    --v42;
  }
  while ( v42 != 0 );
  type = clipModelInfo->type;
  v155[7] = 0.0;
  v45 = 0;
  v157 = 0;
  v156 = 0;
  if ( type == CLIPMODEL_NONE )
    return nullptr;
  if ( type == CLIPMODEL_CUSTOM )
  {
    str = (char *)clipModelInfo->clipModelName.str;
    if ( str == &byte_8200D768 || (v48 = 0, *str == 0) )
      v48 = 1;
    if ( v48 != 0 )
      goto LABEL_36;
    HIDWORD(v74) = clipModelInfo->clipModelName.str;
    v45 = idCollisionModelManager::CompoundTrmFromModel(
            this: collisionModelManager,
            modelName: str,
            trms: &v76,
            maxTrms: 10,
            invalidSubmodelIndices: nullptr,
            numInvalidIndices: nullptr);
  }
  else
  {
    if ( type != CLIPMODEL_RENDERMODEL || renderModel == nullptr )
    {
LABEL_36:
      if ( clipModelInfo->type == CLIPMODEL_BOUNDINGBOX && renderModel != nullptr
        || ((LODWORD(clipModelInfo->size.z) | LODWORD(clipModelInfo->size.y) | LODWORD(clipModelInfo->size.x))
          & 0x7FFFFFFF) == 0
        && renderModel != nullptr )
      {
        x = renderModel->referenceBounds.b[0].x;
        y = renderModel->referenceBounds.b[0].y;
        HIDWORD(v74) = &renderModel->referenceBounds;
        z = renderModel->referenceBounds.b[0].z;
        v53 = renderModel->referenceBounds.b[1].x;
        HIDWORD(v74) = &renderModel->referenceBounds.b[1];
        v54 = renderModel->referenceBounds.b[1].y;
        v55 = renderModel->referenceBounds.b[1].z;
      }
      else
      {
        v54 = (float)(clipModelInfo->size.y * 0.5);
        v53 = (float)(clipModelInfo->size.x * 0.5);
        v55 = clipModelInfo->size.z;
        y = (float)(clipModelInfo->size.y * (float)-0.5);
        x = (float)(clipModelInfo->size.x * (float)-0.5);
      }
      v73.b[0].y = y;
      v73.b[1].y = v54;
      v73.b[0].x = x;
      v73.b[1].z = v55;
      v73.b[1].x = v53;
      v73.b[0].z = z;
      if ( idBounds::GetVolume(this: &v73) < 0.0099999998 )
      {
        if ( a7 != nullptr )
          v56 = a7;
        else
          v56 = "NULL";
        idLib::Warning(fmt: "%s has an invalid bounds", v56);
        x = -8.0;
        y = -8.0;
        v53 = 8.0;
        v54 = 8.0;
        z = -8.0;
        v55 = 8.0;
      }
      v57 = clipModelInfo->type;
      v58 = (float)(renderModelScale->x * (float)v53);
      v59 = (float)(renderModelScale->z * (float)z);
      v60 = clipModelInfo->offset.x;
      v61 = (float)(renderModelScale->y * (float)y);
      v62 = clipModelInfo->offset.y;
      v63 = (float)(renderModelScale->z * (float)v55);
      v64 = clipModelInfo->offset.z;
      v65 = (float)(renderModelScale->y * (float)v54);
      v66 = clipModelInfo->type == CLIPMODEL_CYLINDER;
      v73.b[0].x = clipModelInfo->offset.x + (float)(renderModelScale->x * (float)x);
      HIDWORD(v74) = &clipModelInfo->offset;
      v73.b[1].x = (float)v60 + (float)v58;
      v73.b[0].z = (float)v64 + (float)v59;
      v73.b[0].y = (float)v62 + (float)v61;
      v73.b[1].z = (float)v64 + (float)v63;
      v73.b[1].y = (float)v62 + (float)v65;
      if ( v66 )
      {
        numSides = clipModelInfo->numSides;
        if ( numSides < 3 )
          numSides = 3;
        v45 = 1;
        idTraceModel::SetupCylinder(this: &v76, cylBounds: &v73, numSides);
        if ( barrelCollision )
        {
          v74 = __PAIR64__(&unk_821D0000, numSides);
          idTraceModel::SetupCylinder(this: &v77, cylBounds: &v73, numSides);
          idRotation::idRotation(
            this: &v75,
            rotationOrigin: &vec3_origin,
            rotationVec: &vec3_up,
            rotationAngle: (float)((float)180.0 / (float)__SPAIR64__(&unk_821D0000, numSides)));
          v45 = 2;
          v68 = idRotation::ToMat3(this: &v75);
          idTraceModel::Rotate(this: &v77, rotation: v68);
        }
      }
      else if ( v57 == CLIPMODEL_CONE )
      {
        v69 = clipModelInfo->numSides;
        if ( v69 < 3 )
          v69 = 3;
        v45 = 1;
        idTraceModel::SetupCone(this: &v76, coneBounds: &v73, numSides: v69);
      }
      else if ( v57 == CLIPMODEL_BOUNDINGBOX || v57 == CLIPMODEL_BOX )
      {
        v45 = 1;
        idTraceModel::SetupBox(this: &v76, boxBounds: &v73);
      }
      else
      {
        idLib::Warning(fmt: "Invalid clip-model type on '%s'", a7);
      }
      goto LABEL_60;
    }
    v49 = idCollisionModelManager::CompoundTrmFromModel(
            this: collisionModelManager,
            modelName: renderModel->name.str,
            trms: &v76,
            maxTrms: 10,
            invalidSubmodelIndices: nullptr,
            numInvalidIndices: nullptr);
    v45 = v49;
    if ( overrideRadius > 0.0 )
    {
      v50 = v49 == 0;
      if ( v49 <= 0 )
        goto LABEL_35;
      v76.radius = overrideRadius;
    }
  }
  v50 = v45 == 0;
LABEL_35:
  if ( v50 )
    goto LABEL_36;
LABEL_60:
  if ( clipModelInfo->clipShrink && v45 > 0 )
  {
    v70 = &v76;
    for ( i = v45; i != 0; --i )
      idTraceModel::Shrink(this: v70++, m: 0.5);
  }
  v72 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  HIDWORD(v74) = v72;
  if ( v72 != nullptr )
    return idClipModel::idClipModel(
             this: v72,
             clip: &clientGame->clip,
             trm: &v76,
             numTraceModels: v45,
             material: clipModelInfo->overrideClipMaterial);
  else
    return nullptr;
}


// ========================================================================
// __unwind$490862_0
// EA  : 0x82B67334
// RVA : 0x00B67334
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void _unwind_490862_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 15680 + 104), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?BecomeReplicated@idPresentable@@UAAXXZ
// EA  : 0x82B67360
// RVA : 0x00B67360
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::BecomeReplicated(idPresentable *this)
{
  float v2[4]; // [sp+50h] [-20h] BYREF

  this->becameReplicated = true;
  if ( g_projectileDebug.valueInteger != 0 )
  {
    v2[0] = 0.0;
    v2[1] = 0.0;
    v2[2] = 1.0;
    ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *, double))clientGame->renderWorld->DebugCircle)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorGreen,
      a3: &this->origin,
      a4: v2,
      a5: 5.0);
  }
  this->origins[0].x = this->origin.x;
  this->origins[0].y = this->origin.y;
  this->origins[0].z = this->origin.z;
  this->axes[0].mat[0].x = this->axis.mat[0].x;
  this->axes[0].mat[0].y = this->axis.mat[0].y;
  this->axes[0].mat[0].z = this->axis.mat[0].z;
  this->axes[0].mat[1].x = this->axis.mat[1].x;
  this->axes[0].mat[1].y = this->axis.mat[1].y;
  this->axes[0].mat[1].z = this->axis.mat[1].z;
  this->axes[0].mat[2].x = this->axis.mat[2].x;
  this->axes[0].mat[2].y = this->axis.mat[2].y;
  this->axes[0].mat[2].z = this->axis.mat[2].z;
  this->origins[1].x = this->origin.x;
  this->origins[1].y = this->origin.y;
  this->origins[1].z = this->origin.z;
  this->axes[1].mat[0].x = this->axis.mat[0].x;
  this->axes[1].mat[0].y = this->axis.mat[0].y;
  this->axes[1].mat[0].z = this->axis.mat[0].z;
  this->axes[1].mat[1].x = this->axis.mat[1].x;
  this->axes[1].mat[1].y = this->axis.mat[1].y;
  this->axes[1].mat[1].z = this->axis.mat[1].z;
  this->axes[1].mat[2].x = this->axis.mat[2].x;
  this->axes[1].mat[2].y = this->axis.mat[2].y;
  this->axes[1].mat[2].z = this->axis.mat[2].z;
}


// ========================================================================
// ?AddToEntityLUT@idPresentable@@QAAXXZ
// EA  : 0x82B674D8
// RVA : 0x00B674D8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::AddToEntityLUT(idPresentable *this)
{
  int index; // r30
  int entityNumber; // r31
  char v3; // r11
  presentableType_t v4; // r3
  int v5; // r10

  index = this->index;
  if ( index != -1 )
  {
    entityNumber = this->entityNumber;
    if ( entityNumber != 0x1FFF )
    {
      if ( entityNumber < 0 || (v3 = 1, entityNumber >= 0x2000) )
        v3 = 0;
      if ( v3 != 0 )
      {
        v5 = 4 * (entityNumber + 117818);
        if ( *(unsigned int *)((char *)&clientGame->random.seed + v5) != index )
        {
          *(unsigned int *)((char *)&clientGame->random.seed + v5) = index;
          this->entityNumAdded = true;
        }
      }
      else
      {
        v4 = this->GetType(this);
        idLib::Warning(
          fmt: "idPresentable::AddToEntityLUT invalid entityNum %d. index %d type %d",
          entityNumber,
          index,
          v4);
      }
    }
  }
}


// ========================================================================
// ?RemoveFromEntityLUT@idPresentable@@QAAXXZ
// EA  : 0x82B67598
// RVA : 0x00B67598
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::RemoveFromEntityLUT(idPresentable *this)
{
  int index; // r30
  int entityNumber; // r31
  char v3; // r11
  presentableType_t v4; // r3
  int v5; // r10

  index = this->index;
  if ( index != -1 )
  {
    entityNumber = this->entityNumber;
    if ( entityNumber != 0x1FFF )
    {
      if ( entityNumber < 0 || (v3 = 1, entityNumber >= 0x2000) )
        v3 = 0;
      if ( v3 != 0 )
      {
        v5 = 4 * (entityNumber + 117818);
        if ( *(unsigned int *)((char *)&clientGame->random.seed + v5) == index )
        {
          *(unsigned int *)((char *)&clientGame->random.seed + v5) = -1;
          this->entityNumAdded = false;
        }
      }
      else
      {
        v4 = this->GetType(this);
        idLib::Warning(
          fmt: "idPresentable::RemoveFromEntityLUT invalid entityNum %d. index %d type %d",
          entityNumber,
          index,
          v4);
      }
    }
  }
}


// ========================================================================
// ?GetBounds@idPresentable@@UBA?AVidBounds@@H@Z
// EA  : 0x82B67660
// RVA : 0x00B67660
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

idPresentable *__fastcall idPresentable::GetBounds(idPresentable *this, idBounds *result, int bodyId)
{
  float x; // r3
  float y; // r3
  idPhysics *Physics; // r3
  idPresentable_vtbl **v7; // r11
  idPresentable *v8; // r10
  int i; // ctr

  x = result[11].b[1].x;
  if ( x == 0.0
    && ((y = result[45].b[1].y) == 0.0
     || (Physics = idEntity::GetPhysics(this: (idEntity *)LODWORD(y)),
         (x = COERCE_FLOAT((int)Physics->GetClipModel(this: Physics, a2: 0))) == 0.0)) )
  {
    *(idVec3 *)&this->__vftable = vec3_origin;
    *(idVec3 *)&this->clipModelDynamic = vec3_origin;
  }
  else
  {
    v7 = (idPresentable_vtbl **)(LODWORD(x) + 76);
    v8 = (idPresentable *)((char *)this - 4);
    for ( i = 6; i != 0; --i )
    {
      ++v7;
      v8 = (idPresentable *)((char *)v8 + 4);
      v8->__vftable = *v7;
    }
  }
  return this;
}


// ========================================================================
// ?GetAbsBounds@idPresentable@@UBA?AVidBounds@@H@Z
// EA  : 0x82B67720
// RVA : 0x00B67720
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

idPresentable *__fastcall idPresentable::GetAbsBounds(idPresentable *this, idBounds *result, int bodyId)
{
  float x; // r3
  float y; // r3
  idPhysics *Physics; // r3
  idPresentable_vtbl **v7; // r11
  idPresentable *v8; // r10
  int i; // ctr

  x = result[11].b[1].x;
  if ( x == 0.0
    && ((y = result[45].b[1].y) == 0.0
     || (Physics = idEntity::GetPhysics(this: (idEntity *)LODWORD(y)),
         (x = COERCE_FLOAT((int)Physics->GetClipModel(this: Physics, a2: 0))) == 0.0)) )
  {
    *(idVec3 *)&this->__vftable = vec3_origin;
    *(idVec3 *)&this->clipModelDynamic = vec3_origin;
  }
  else
  {
    v7 = (idPresentable_vtbl **)(LODWORD(x) + 100);
    v8 = (idPresentable *)((char *)this - 4);
    for ( i = 6; i != 0; --i )
    {
      ++v7;
      v8 = (idPresentable *)((char *)v8 + 4);
      v8->__vftable = *v7;
    }
  }
  return this;
}


// ========================================================================
// ?GetPlayerEntity@idPresentable@@QBAPAVidPlayer@@XZ
// EA  : 0x82B677E0
// RVA : 0x00B677E0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

idPlayer *__fastcall idPresentable::GetPlayerEntity(idPresentable *this)
{
  return idPlayer::CastTo(c: (idPlayer *)this->entity);
}


// ========================================================================
// ?IsTargetLockable@idPresentable@@UBA_NPBVidDeclAmmo@@@Z
// EA  : 0x82B677E8
// RVA : 0x00B677E8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

BOOL __fastcall idPresentable::IsTargetLockable(idPresentable *this, const idDeclAmmo *ammo)
{
  idEntity *entity; // r3

  entity = this->entity;
  return entity != nullptr && entity->IsTargetLockable(this: entity, a2: ammo);
}


// ========================================================================
// ?Clear@idClipModelInfo@@QAAXXZ
// EA  : 0x82B67810
// RVA : 0x00B67810
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idClipModelInfo::Clear(idClipModelInfo *this)
{
  this->type = CLIPMODEL_NONE;
  this->size.z = 0.0;
  this->size.y = 0.0;
  this->size.x = 0.0;
  this->offset.z = 0.0;
  this->offset.y = 0.0;
  this->offset.x = 0.0;
  this->numSides = 0;
  this->clipShrink = false;
  this->allowInline = false;
  this->softObstacle = false;
  this->overrideClipMaterial = nullptr;
}


// ========================================================================
// ?GetOnlineUsableState@idPresentable@@UBA?AW4usableState_t@@PAVidPresentablePlayer@@H@Z
// EA  : 0x82B67850
// RVA : 0x00B67850
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

usableState_t __fastcall idPresentable::GetOnlineUsableState(
        idPresentable *this,
        idPresentablePlayer *user,
        int clientGameFrame)
{
  idEntity *entity; // r31
  int FocusTracker; // r3

  entity = this->entity;
  if ( entity == nullptr || user->entity == nullptr )
    return this->usableState;
  FocusTracker = idPlayer::GetFocusTracker(this: (idPlayer *)user->entity);
  return entity->GetUsableState(this: entity, a2: user->entity, a3: (const idFocusTrace *)(FocusTracker + 112));
}


// ========================================================================
// ?GetOnlineModifiedCrosshairInfo@idPresentable@@UAAXPBV1@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82B678C8
// RVA : 0x00B678C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::GetOnlineModifiedCrosshairInfo(
        idPresentable *this,
        const idPresentable *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  float v5; // r3
  crosshairMaterial_t v6; // r9
  float a; // r3
  float v8; // r3
  float v9; // r3
  float v10; // r3
  float v11; // r6
  float v12; // r3
  float v13; // r6
  float v14; // r3

  switch ( usable )
  {
    case USABLE_LOOT:
      v6 = CHMATERIAL_LOOT;
      if ( ((1 << activator->entityNumber) & this->usablePlayerMask) == 0 )
        goto LABEL_18;
      info->color.r = idColor::colorGreen.r;
      info->color.g = idColor::colorGreen.g;
      info->color.b = idColor::colorGreen.b;
      a = idColor::colorGreen.a;
      info->colorState = CROSSHAIR_COLOR_NORMAL;
      info->textColorState = CROSSHAIR_TEXT_COLOR_NORMAL;
      info->material = CHMATERIAL_LOOT;
      info->color.a = a;
      break;
    case USABLE_PROP:
      v6 = CHMATERIAL_PROP;
      if ( usable == USABLE_NOT_USABLE )
        goto LABEL_18;
      info->color.r = idColor::colorGreen.r;
      info->color.g = idColor::colorGreen.g;
      info->color.b = idColor::colorGreen.b;
      v8 = idColor::colorGreen.a;
      info->colorState = CROSSHAIR_COLOR_NORMAL;
      info->textColorState = CROSSHAIR_TEXT_COLOR_NORMAL;
      info->material = CHMATERIAL_PROP;
      info->color.a = v8;
      break;
    case USABLE_AI_TALK:
    case USABLE_AI_TOWN:
    case USABLE_AI_TAGGABLE:
    case USABLE_VEHICLE_DRIVE:
    case USABLE_VEHICLE_GUNNER:
    case USABLE_DISASSEMBLE:
      return;
    case USABLE_DOOR:
      if ( ((1 << activator->entityNumber) & this->usablePlayerMask) == 0 )
      {
        v6 = CHMATERIAL_DOOR;
        goto LABEL_18;
      }
      info->color.r = idCrosshairInfo::DEFAULT_COLOR.r;
      info->color.g = idCrosshairInfo::DEFAULT_COLOR.g;
      info->color.b = idCrosshairInfo::DEFAULT_COLOR.b;
      v9 = idCrosshairInfo::DEFAULT_COLOR.a;
      info->colorState = CROSSHAIR_COLOR_NORMAL;
      info->color.a = v9;
      info->textColor = idCrosshairInfo::DEFAULT_TEXT_COLOR;
      info->textColorState = CROSSHAIR_TEXT_COLOR_NORMAL;
      info->material = CHMATERIAL_DOOR;
      break;
    case USABLE_MOVER:
      if ( ((1 << activator->entityNumber) & this->usablePlayerMask) == 0 )
      {
        v6 = CHMATERIAL_MOVER;
        goto LABEL_18;
      }
      info->color.r = idCrosshairInfo::DEFAULT_COLOR.r;
      info->color.g = idCrosshairInfo::DEFAULT_COLOR.g;
      info->color.b = idCrosshairInfo::DEFAULT_COLOR.b;
      v10 = idCrosshairInfo::DEFAULT_COLOR.a;
      info->colorState = CROSSHAIR_COLOR_NORMAL;
      info->color.a = v10;
      info->textColor.r = idCrosshairInfo::DEFAULT_TEXT_COLOR.r;
      info->textColor.g = idCrosshairInfo::DEFAULT_TEXT_COLOR.g;
      info->textColor.b = idCrosshairInfo::DEFAULT_TEXT_COLOR.b;
      v11 = idCrosshairInfo::DEFAULT_TEXT_COLOR.a;
      info->textColorState = CROSSHAIR_TEXT_COLOR_NORMAL;
      info->material = CHMATERIAL_MOVER;
      info->textColor.a = v11;
      break;
    case USABLE_RC_PICKUP:
      if ( ((1 << activator->entityNumber) & this->usablePlayerMask) == 0 )
      {
        v6 = CHMATERIAL_RC_PICKUP;
        goto LABEL_18;
      }
      info->color.r = idCrosshairInfo::DEFAULT_COLOR.r;
      info->color.g = idCrosshairInfo::DEFAULT_COLOR.g;
      info->color.b = idCrosshairInfo::DEFAULT_COLOR.b;
      v12 = idCrosshairInfo::DEFAULT_COLOR.a;
      info->colorState = CROSSHAIR_COLOR_NORMAL;
      info->color.a = v12;
      info->textColor.r = idCrosshairInfo::DEFAULT_TEXT_COLOR.r;
      info->textColor.g = idCrosshairInfo::DEFAULT_TEXT_COLOR.g;
      info->textColor.b = idCrosshairInfo::DEFAULT_TEXT_COLOR.b;
      v13 = idCrosshairInfo::DEFAULT_TEXT_COLOR.a;
      info->textColorState = CROSSHAIR_TEXT_COLOR_NORMAL;
      info->material = CHMATERIAL_RC_PICKUP;
      info->textColor.a = v13;
      break;
    case USABLE_AMMO_REFILL:
      if ( ((1 << activator->entityNumber) & this->usablePlayerMask) != 0 )
      {
        info->color.r = idColor::colorGreen.r;
        info->color.g = idColor::colorGreen.g;
        info->color.b = idColor::colorGreen.b;
        v5 = idColor::colorGreen.a;
        info->colorState = CROSSHAIR_COLOR_NORMAL;
        info->textColorState = CROSSHAIR_TEXT_COLOR_NORMAL;
        info->material = CHMATERIAL_AMMO_REFILL;
        info->color.a = v5;
      }
      else
      {
        v6 = CHMATERIAL_LOOT;
LABEL_18:
        info->color.r = idColor::colorRed.r;
        info->color.g = idColor::colorRed.g;
        info->color.b = idColor::colorRed.b;
        v14 = idColor::colorRed.a;
        info->textColorState = CROSSHAIR_TEXT_COLOR_NEGATIVE;
        info->colorState = CROSSHAIR_COLOR_NEGATIVE;
        info->material = v6;
        info->color.a = v14;
      }
      break;
  }
}


// ========================================================================
// ?GetShouldPresent@idPresentable@@QBA_NXZ
// EA  : 0x82B67BC8
// RVA : 0x00B67BC8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

unsigned int __fastcall idPresentable::GetShouldPresent(idPresentable *this)
{
  idLobbyBase *v3; // r3

  if ( common->IsMultiplayer(this: common)
    && (v3 = session->GetActingGameStateLobbyBase(this: session), v3->IsHost(this: v3) == 0)
    && this->index < 0x2000
    && cg_optimizePresents.valueInteger != 0 )
  {
    return (-this->shouldPresentCounter & (unsigned int)~this->shouldPresentCounter) >> 31;
  }
  else
  {
    return 1;
  }
}


// ========================================================================
// ??0idPresentable@@QAA@XZ
// EA  : 0x82B67CF0
// RVA : 0x00B67CF0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

idPresentable *__fastcall idPresentable::idPresentable(idPresentable *this)
{
  unsigned __int64 v1; // r30
  double x; // fp0
  int valueInteger; // r9

  LODWORD(v1) = 0;
  this->__vftable = (idPresentable_vtbl *)&idPresentable::`vftable';
  this->groupMaster.spawnId = 0;
  this->clipModelDynamic = false;
  this->clipModelDynamicAxis = false;
  this->model = nullptr;
  this->hidden = false;
  this->entityNumber = 0x1FFF;
  this->clipModelInfo.clipModelName.str = &byte_8200D768;
  this->clipModelInfo.type = CLIPMODEL_NONE;
  this->clipModelInfo.size.z = 0.0;
  this->clipModelInfo.size.y = 0.0;
  this->clipModelInfo.size.x = 0.0;
  this->clipModelInfo.offset.z = 0.0;
  this->clipModelInfo.offset.y = 0.0;
  this->clipModelInfo.offset.x = 0.0;
  this->clipModelInfo.numSides = 0;
  this->clipModelInfo.clipShrink = false;
  this->clipModelInfo.allowInline = false;
  this->clipModelInfo.softObstacle = false;
  this->clipModelInfo.overrideClipMaterial = nullptr;
  this->clipModel = nullptr;
  this->overridingClipContents = false;
  idFXManager::idFXManager(this: &this->fxManager);
  this->fxDecl = nullptr;
  this->soundEmitter = nullptr;
  this->parent.spawnId = 0;
  this->parentJoint = NULL_JOINT_INDEX;
  this->controller.spawnId = 0;
  this->index = -1;
  this->activeIndex = -1;
  this->serializedIndex = -1;
  this->debugName = nullptr;
  this->entity = nullptr;
  this->spawnId = 0;
  this->team = TEAM_NONE;
  this->ownerPlayerIndex = -1;
  this->influenceHandle.value = -1;
  this->predictedKey = -1;
  this->highlightColor = HIGHLIGHT_COLOR_NONE;
  this->entityNumAdded = false;
  this->serverPermanetSoundChannels = v1;
  this->hideDuringFirstSSInterval = false;
  this->queueForDelete = false;
  this->csInterface = nullptr;
  this->usablePlayerMask = 0;
  this->usableState = USABLE_NOT_USABLE;
  this->lastUsedTime = 0;
  this->origins[1] = vec3_origin;
  x = this->origins[1].x;
  this->origins[0] = this->origins[1];
  this->origin.x = x;
  this->origin.y = this->origins[0].y;
  this->origin.z = this->origins[0].z;
  this->axes[1] = mat3_identity;
  this->axes[0] = this->axes[1];
  this->axis = this->axes[0];
  this->serializeCount = 0;
  this->radius = idPresentable::DEFAULT_PRESENTABLE_RADIUS;
  this->peerInRangeMask[0] = -1;
  this->peerInRangeMask[1] = -1;
  this->changedCount = 0;
  this->stopSerializeCount = 0;
  this->clientThink = true;
  this->shouldPresent = true;
  valueInteger = cg_optimizePresentsCountdown.valueInteger;
  this->clipModelInfo.type = CLIPMODEL_NONE;
  this->shouldPresentCounter = valueInteger;
  this->clipModelInfo.size = vec3_origin;
  this->clipModelInfo.offset = vec3_origin;
  this->clipModelInfo.numSides = 0;
  this->clipModelInfo.clipShrink = false;
  this->clipModelInfo.overrideClipMaterial = nullptr;
  this->clipModelContents = 1;
  this->clipModelPhysID = -1;
  this->curIFF = IFFN_UNINITIALIZED;
  this->entityTypeFlags = 0;
  this->becameReplicated = false;
  return this;
}


// ========================================================================
// ??1idPresentable@@UAA@XZ
// EA  : 0x82B68038
// RVA : 0x00B68038
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::~idPresentable(idPresentable *this)
{
  idClipModel *clipModel; // r3
  idRenderModel *model; // r3
  idFXManager *p_fxManager; // r30

  this->__vftable = (idPresentable_vtbl *)&idPresentable::`vftable';
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
  {
    if ( !clipModel->deleted )
      idClipModel::Delete(this: clipModel);
    this->clipModel = nullptr;
  }
  model = this->model;
  if ( model != nullptr )
  {
    model->unlinked = true;
    model->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: model);
  }
  this->SetRenderModel(this, a2: nullptr, a3: true);
  p_fxManager = &this->fxManager;
  idFXManager::Shutdown(this: p_fxManager);
  idFXManager::~idFXManager(this: p_fxManager);
}


// ========================================================================
// __unwind$492237
// EA  : 0x82B680F0
// RVA : 0x00B680F0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void _unwind_492237()
{
  int v0; // r12

  idFXManager::~idFXManager(this: (idFXManager *)(*(_DWORD *)(v0 - 112 + 132) + 288));
}


// ========================================================================
// ?SetParent@idPresentable@@QAAXPAV1@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82B68120
// RVA : 0x00B68120
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SetParent(
        idPresentable *this,
        idPresentable *p,
        idIndex<short,enum invalidJointIndex_t> *j)
{
  unsigned int spawnId; // r11

  spawnId = 0;
  if ( p != nullptr )
    spawnId = p->spawnId;
  this->parent.spawnId = spawnId;
  this->parentJoint.value = (__int16)j;
}


// ========================================================================
// ?Interpolate@idPresentable@@UAAXHM@Z
// EA  : 0x82B68140
// RVA : 0x00B68140
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::Interpolate(idPresentable *this, int curTime, double fraction)
{
  float y; // r7
  idMat3 *p_axis; // r29
  float z; // r6
  float *p_w; // r10
  idVec3 *p_origin; // r30
  float *p_z; // r11
  int v11; // ctr
  const idQuat *v12; // r28
  const idQuat *v13; // r3
  idMat3 *v14; // r3
  float v15; // r9
  float v16; // r7
  float x; // r6
  float v18; // r10
  float v19; // r8
  double v20; // fp10
  idMat3 v21; // [sp+50h] [-D0h] BYREF
  float v22; // [sp+74h] [-ACh]
  float v23; // [sp+78h] [-A8h]
  idQuat v24; // [sp+80h] [-A0h] BYREF
  _BYTE v25[48]; // [sp+90h] [-90h] BYREF
  idQuat v26; // [sp+C0h] [-60h] BYREF

  y = this->origin.y;
  p_axis = &this->axis;
  z = this->origin.z;
  p_w = &v24.w;
  p_origin = &this->origin;
  p_z = &this->origin.z;
  v11 = 9;
  v21.mat[2].z = this->origin.x;
  v22 = y;
  v23 = z;
  do
  {
    *++p_w = *++p_z;
    --v11;
  }
  while ( v11 != 0 );
  v12 = idMat3::ToQuat(this: (idMat3 *)&v21.mat[1].y, result: (idQuat *)&this->axes[1]);
  v13 = idMat3::ToQuat(this: &v21, result: (idQuat *)this->axes);
  v14 = (idMat3 *)idQuat::Slerp(this: &v24, from: v13, to: v12, t: fraction);
  *p_axis = *idQuat::ToMat3(this: &v26, result: v14);
  v15 = this->origins[0].y;
  v16 = this->origins[1].y;
  x = this->origins[0].x;
  v18 = this->origins[1].z;
  v19 = this->origins[0].z;
  v21.mat[0].x = this->origins[1].x;
  v21.mat[1].z = v15;
  v21.mat[0].y = v16;
  v21.mat[1].y = x;
  v21.mat[0].z = v18;
  v21.mat[2].x = v19;
  v20 = (float)((float)(v21.mat[0].x - x) * (float)fraction);
  p_origin->z = (float)((float)(v18 - v19) * (float)fraction) + v19;
  p_origin->x = (float)v20 + x;
  p_origin->y = (float)((float)(v16 - v15) * (float)fraction) + v15;
  if ( !this->ShouldInterpolate(this) )
  {
    p_origin->x = this->origins[1].x;
    p_origin->y = this->origins[1].y;
    p_origin->z = this->origins[1].z;
  }
  idPresentable::UpdateModelTransform(this);
  this->UpdateClientCollision(
    this,
    a2: (const idVec3 *)&v21.mat[2].z,
    a3: (const idMat3 *)v25,
    a4: p_origin,
    a5: p_axis);
}


// ========================================================================
// ?ClientThink@idPresentable@@UAAXHM_N@Z
// EA  : 0x82B68308
// RVA : 0x00B68308
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::ClientThink(idPresentable *this, int curTime, double fraction, bool predict, char a5)
{
  if ( this->index < 0x2000 )
  {
    ((void (__fastcall *)(idPresentable *))this->Interpolate)(a1: this);
    if ( a5 == 1 )
      this->ClientPredict(this, a2: curTime, a3: fraction);
    this->UpdateFX_3(this, a2: 1.0, a3: 0.0);
    idPresentable::UpdateSound(this);
    this->Present(this);
  }
}


// ========================================================================
// ?SetRenderModel@idPresentable@@UAAXPAVidRenderModel@@_N@Z
// EA  : 0x82B683B8
// RVA : 0x00B683B8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SetRenderModel(idPresentable *this, idTreeAnimator *renderModel_, bool inheritTransform)
{
  idTreeAnimator *ta; // r11

  ta = this->fxManager.ta;
  this->model = renderModel_;
  if ( ta != nullptr )
    idFXManager::ResetTreeAnimator(this: &this->fxManager, _ta: renderModel_);
  if ( this->model != nullptr )
    idPresentable::InheritPropertiesFromModel(this, inheritTransform);
}


// ========================================================================
// ?SetClipModelInfo@idPresentable@@QAAXABVidClipModelInfo@@ABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82B68420
// RVA : 0x00B68420
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SetClipModelInfo(
        idPresentable *this,
        const idClipModelInfo *clipModelInfo_,
        const idVec3 *clipModelSpawnPos_,
        const idMat3 *clipModelSpawnAxis_,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idPresentable *a14)
{
  BOOL softObstacle; // r10
  const idMaterial *overrideClipMaterial; // r7
  idClientGame *v18; // r3

  this->clipModelInfo.type = clipModelInfo_->type;
  this->clipModelInfo.size = clipModelInfo_->size;
  this->clipModelInfo.offset = clipModelInfo_->offset;
  this->clipModelInfo.numSides = clipModelInfo_->numSides;
  this->clipModelInfo.clipModelName.str = clipModelInfo_->clipModelName.str;
  this->clipModelInfo.clipShrink = clipModelInfo_->clipShrink;
  this->clipModelInfo.allowInline = clipModelInfo_->allowInline;
  softObstacle = clipModelInfo_->softObstacle;
  this->clipModelInfo.softObstacle = softObstacle;
  overrideClipMaterial = clipModelInfo_->overrideClipMaterial;
  this->clipModelInfo.overrideClipMaterial = overrideClipMaterial;
  this->clipModelSpawnPos.x = clipModelSpawnPos_->x;
  v18 = clientGame;
  this->clipModelSpawnPos.y = clipModelSpawnPos_->y;
  this->clipModelSpawnPos.z = clipModelSpawnPos_->z;
  this->clipModelSpawnAxis = *clipModelSpawnAxis_;
  idClientGame::MarkPresentableSerialized(
    this: v18,
    presentable: this,
    serialized: true,
    deleted: false,
    a5: (int)overrideClipMaterial,
    a6: (int)clipModelSpawnAxis_,
    a7: (int)clipModelSpawnPos_,
    a8: softObstacle,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14);
}


// ========================================================================
// ?SetClipModelInfo_DynamicRenderModel@idPresentable@@QAAXABVidVec3@@ABVidMat3@@H@Z
// EA  : 0x82B68518
// RVA : 0x00B68518
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SetClipModelInfo_DynamicRenderModel(
        idPresentable *this,
        const idVec3 *clipModelSpawnPos_,
        const idMat3 *clipModelSpawnAxis_,
        int contents)
{
  int v4; // r8
  int v5; // r10
  idClipModelInfo *p_clipModelInfo; // r9
  int clipModelContents; // r7
  int v10; // [sp+8h] [-68h]
  int v11; // [sp+Ch] [-64h]
  int v12; // [sp+10h] [-60h]
  int v13; // [sp+14h] [-5Ch]
  int v14; // [sp+18h] [-58h]
  idPresentable *v15; // [sp+1Ch] [-54h]

  v4 = 0x82000000;
  v5 = 1;
  this->clipModelInfo.type = CLIPMODEL_NONE;
  this->clipModelInfo.size.z = 0.0;
  p_clipModelInfo = &this->clipModelInfo;
  this->clipModelInfo.size.y = 0.0;
  this->clipModelInfo.size.x = 0.0;
  this->clipModelInfo.offset.z = 0.0;
  this->clipModelInfo.offset.y = 0.0;
  this->clipModelInfo.offset.x = 0.0;
  this->clipModelInfo.numSides = 0;
  this->clipModelInfo.clipShrink = false;
  this->clipModelInfo.allowInline = false;
  this->clipModelInfo.softObstacle = false;
  this->clipModelInfo.overrideClipMaterial = nullptr;
  this->clipModelInfo.type = CLIPMODEL_RENDERMODEL;
  this->clipModelSpawnPos = *clipModelSpawnPos_;
  this->clipModelSpawnAxis = *clipModelSpawnAxis_;
  this->clipModelDynamic = true;
  clipModelContents = this->clipModelContents;
  this->clipModelDynamicAxis = true;
  if ( contents != clipModelContents )
    idClientGame::MarkPresentableSerialized(
      this: clientGame,
      presentable: this,
      serialized: true,
      deleted: false,
      a5: clipModelContents,
      a6: 0x82000000,
      a7: (int)p_clipModelInfo,
      a8: 1,
      a9: v10,
      a10: v11,
      a11: v12,
      a12: v13,
      a13: v14,
      a14: v15);
  this->clipModelContents = contents;
  idClientGame::MarkPresentableSerialized(
    this: clientGame,
    presentable: this,
    serialized: true,
    deleted: false,
    a5: clipModelContents,
    a6: v4,
    a7: (int)p_clipModelInfo,
    a8: v5,
    a9: v10,
    a10: v11,
    a11: v12,
    a12: v13,
    a13: v14,
    a14: v15);
}


// ========================================================================
// ?StartSoundShader@idPresentable@@QAAHW4soundChannel_t@@PBVidSoundShader@@HE@Z
// EA  : 0x82B68628
// RVA : 0x00B68628
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

int __fastcall idPresentable::StartSoundShader(
        idPresentable *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        soundShaderFlags_t soundShaderFlags,
        unsigned __int8 peerMask)
{
  soundShaderParms_t v11; // [sp+50h] [-D0h] BYREF

  soundShaderParms_t::Clear(this: &v11);
  v11.soundShaderFlags = soundShaderFlags;
  return idPresentable::StartSoundShader(this, channel, shader, parms: &v11, peerMask);
}


// ========================================================================
// ?InitFXMgr@idPresentable@@MAAXPBVidDeclFX@@@Z
// EA  : 0x82B68678
// RVA : 0x00B68678
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::InitFXMgr(idPresentable *this, const idDeclFX *_fxDecl)
{
  idPresentable::InitFXMgr(this, _fxDecl, fxManager: &this->fxManager);
}


// ========================================================================
// ?SetEntityNumber@idPresentable@@QAAXH@Z
// EA  : 0x82B68680
// RVA : 0x00B68680
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SetEntityNumber(idPresentable *this, int value)
{
  idPresentable::RemoveFromEntityLUT(this);
  this->entityNumber = value;
  idPresentable::AddToEntityLUT(this);
}


// ========================================================================
// ??0idPresentable@@QAA@PAVidEntity@@PAVidRenderModel@@HPBVidDeclFX@@@Z
// EA  : 0x82B688C8
// RVA : 0x00B688C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

idPresentable *__fastcall idPresentable::idPresentable(
        idPresentable *this,
        idEntity *e,
        idTreeAnimator *renderModel_,
        int entityNumber_,
        const idDeclFX *fxDecl_)
{
  idFXManager *p_fxManager; // r27
  double x; // fp0
  idTreeAnimator *ta; // r6

  this->__vftable = (idPresentable_vtbl *)&idPresentable::`vftable';
  this->groupMaster.spawnId = 0;
  this->entityNumber = entityNumber_;
  this->clipModelDynamic = false;
  this->clipModelDynamicAxis = false;
  p_fxManager = &this->fxManager;
  this->hidden = false;
  this->model = nullptr;
  this->clipModelInfo.clipModelName.str = &byte_8200D768;
  this->clipModelInfo.type = CLIPMODEL_NONE;
  this->clipModelInfo.size.z = 0.0;
  this->clipModelInfo.size.y = 0.0;
  this->clipModelInfo.size.x = 0.0;
  this->clipModelInfo.offset.z = 0.0;
  this->clipModelInfo.offset.y = 0.0;
  this->clipModelInfo.offset.x = 0.0;
  this->clipModelInfo.numSides = 0;
  this->clipModelInfo.clipShrink = false;
  this->clipModelInfo.allowInline = false;
  this->clipModelInfo.softObstacle = false;
  this->clipModelInfo.overrideClipMaterial = nullptr;
  this->clipModel = nullptr;
  this->overridingClipContents = false;
  idFXManager::idFXManager(this: &this->fxManager);
  this->fxDecl = fxDecl_;
  this->soundEmitter = nullptr;
  this->parent.spawnId = 0;
  this->parentJoint = NULL_JOINT_INDEX;
  this->controller.spawnId = 0;
  this->index = -1;
  this->activeIndex = -1;
  this->serializedIndex = -1;
  this->debugName = nullptr;
  this->entity = nullptr;
  this->spawnId = 0;
  this->team = TEAM_NONE;
  this->ownerPlayerIndex = -1;
  this->influenceHandle.value = -1;
  this->predictedKey = -1;
  this->usablePlayerMask = 0;
  this->usableState = USABLE_NOT_USABLE;
  this->lastUsedTime = 0;
  this->highlightColor = HIGHLIGHT_COLOR_NONE;
  this->entityNumAdded = false;
  this->hideDuringFirstSSInterval = false;
  this->queueForDelete = false;
  this->csInterface = nullptr;
  this->origins[1] = vec3_origin;
  x = this->origins[1].x;
  this->origins[0] = this->origins[1];
  this->origin.x = x;
  this->origin.y = this->origins[0].y;
  this->origin.z = this->origins[0].z;
  this->axes[1] = mat3_identity;
  this->axes[0] = this->axes[1];
  this->axis = this->axes[0];
  this->serializeCount = 0;
  this->radius = idPresentable::DEFAULT_PRESENTABLE_RADIUS;
  this->peerInRangeMask[0] = -1;
  this->peerInRangeMask[1] = -1;
  this->changedCount = 0;
  this->stopSerializeCount = 0;
  this->clientThink = true;
  this->shouldPresent = true;
  this->shouldPresentCounter = cg_optimizePresentsCountdown.valueInteger;
  this->entity = e;
  this->clipModelInfo.type = CLIPMODEL_NONE;
  this->clipModelInfo.size = vec3_origin;
  this->clipModelInfo.offset = vec3_origin;
  this->clipModelInfo.numSides = 0;
  ta = this->fxManager.ta;
  this->clipModelInfo.clipShrink = false;
  this->clipModelInfo.overrideClipMaterial = nullptr;
  this->clipModelContents = 1;
  this->clipModelPhysID = -1;
  this->curIFF = IFFN_UNINITIALIZED;
  this->entityTypeFlags = 0;
  this->becameReplicated = false;
  this->model = renderModel_;
  if ( ta != nullptr )
    idFXManager::ResetTreeAnimator(this: p_fxManager, _ta: renderModel_);
  if ( this->model != nullptr )
    idPresentable::InheritPropertiesFromModel(this, inheritTransform: true);
  idPresentable::InitFXMgr(this, _fxDecl: this->fxDecl, fxManager: p_fxManager);
  return this;
}


// ========================================================================
// __unwind$492890
// EA  : 0x82B68C9C
// RVA : 0x00B68C9C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void _unwind_492890()
{
  int v0; // r12

  idFXManager::~idFXManager(this: (idFXManager *)(*(_DWORD *)(v0 - 208 + 228) + 288));
}


// ========================================================================
// ?GetParent@idPresentable@@QBAPAV1@XZ
// EA  : 0x82B68CC8
// RVA : 0x00B68CC8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

idPresentable *__fastcall idPresentable::GetParent(idPresentable *this)
{
  unsigned int spawnId; // r11
  int v3; // r30
  idPresentable *result; // r3

  spawnId = this->parent.spawnId;
  v3 = spawnId & 0x3FFF;
  if ( spawnId == 0 )
    return nullptr;
  if ( !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF) )
    return nullptr;
  result = idClientGame::GetPresentableByIndex(this: clientGame, index: v3);
  if ( result->spawnId != this->parent.spawnId )
    return nullptr;
  return result;
}


// ========================================================================
// ?SerializeFX@idPresentable@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B68D30
// RVA : 0x00B68D30
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SerializeFX(idPresentable *this, idSerializer *ser)
{
  const idDeclFX *fxDecl; // r11
  const idDecl **p_fxDecl; // r28
  idBitMsg *msg; // r3
  bool v7; // r29
  idTreeAnimator *v8; // r3

  fxDecl = this->fxDecl;
  p_fxDecl = &this->fxDecl;
  msg = ser->msg;
  v7 = fxDecl != nullptr;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: fxDecl != nullptr, numBits: 1);
  else
    v7 = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  if ( v7 )
  {
    idSerializer::Serialize<idDeclFX>(this: ser, decl: p_fxDecl);
    v8 = (idTreeAnimator *)_RTDynamicCast(
                             inptr: this->model,
                             VfDelta: 0,
                             SrcType: &idRenderModel `RTTI Type Descriptor',
                             TargetType: &idTreeAnimator `RTTI Type Descriptor',
                             isReference: 0);
    if ( this->fxManager.initialized && this->fxManager.ta != v8 )
      this->ShutdownFXMgr(this);
    if ( !this->fxManager.initialized )
      this->InitFXMgr(this, a2: (const idDeclFX *)*p_fxDecl);
    idFXManager::Serialize(this: &this->fxManager, ser);
  }
}


// ========================================================================
// ?UpdateModelGroupMaster@idPresentable@@QAAXXZ
// EA  : 0x82B68E28
// RVA : 0x00B68E28
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::UpdateModelGroupMaster(idPresentable *this)
{
  idPresentablePtr<idPresentable> *p_groupMaster; // r31
  unsigned int Index; // r30
  idPresentable *v4; // r3

  if ( this->model != nullptr )
  {
    p_groupMaster = &this->groupMaster;
    Index = -1;
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &this->groupMaster) != nullptr
      && idPresentablePtr<idPresentableProjectile>::operator->(this: p_groupMaster)->model != nullptr )
    {
      v4 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_groupMaster);
      Index = idRenderModel::GetIndex(this: v4->model);
    }
    this->model->g.groupMasterIndex = Index;
  }
}


// ========================================================================
// ?GetWorldTransformInternal@idPresentable@@QBAXABVidVec3@@ABVidMat3@@AAV2@AAV3@@Z
// EA  : 0x82B68E98
// RVA : 0x00B68E98
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::GetWorldTransformInternal(
        idPresentable *this,
        const idVec3 *inOrigin,
        idMat3 *inAxis,
        idVec3 *outOrigin,
        idMat3 *outAxis)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_parent; // r27
  int v12; // r25
  idPresentable *v13; // r3
  idPresentableAnimatedEntity *v14; // r3
  idTreeAnimator *TreeAnimator; // r27
  idQuat *v16; // r4
  const idIndex<short,enum invalidJointIndex_t> *value; // r30
  idMat3 *v18; // r3
  idVec3 *p_origin; // r26
  idPresentable *v20; // r3
  double y; // fp7
  double z; // fp31
  double v23; // fp13
  double v24; // fp12
  idMat3 v25; // [sp+50h] [-90h] BYREF

  spawnId = this->parent.spawnId;
  p_parent = &this->parent;
  v12 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v12)->spawnId == p_parent->spawnId )
  {
    if ( (unsigned __int16)this->parentJoint.value == 0xFFFF )
    {
      p_origin = &idPresentablePtr<idPresentableProjectile>::operator->(this: p_parent)->origin;
      v20 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_parent);
      y = p_origin->y;
      z = p_origin->z;
      v23 = (float)((float)(v20->axis.mat[2].y * inOrigin->z)
                  + (float)((float)(v20->axis.mat[0].y * inOrigin->x) + (float)(v20->axis.mat[1].y * inOrigin->y)));
      v24 = (float)((float)(v20->axis.mat[2].z * inOrigin->z)
                  + (float)((float)(v20->axis.mat[0].z * inOrigin->x) + (float)(v20->axis.mat[1].z * inOrigin->y)));
      outOrigin->x = p_origin->x
                   + (float)((float)(v20->axis.mat[0].x * inOrigin->x)
                           + (float)((float)(v20->axis.mat[1].x * inOrigin->y)
                                   + (float)(v20->axis.mat[2].x * inOrigin->z)));
      outOrigin->y = (float)y + (float)v23;
      outOrigin->z = (float)z + (float)v24;
      *outAxis = *idMat3::operator*(this: (idMat3 *)&v25.mat[1].y, result: &v20->axis, a: inAxis);
    }
    else
    {
      v13 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_parent);
      v14 = v13->GetAnimatedEntityInterface(this: v13);
      TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v14);
      v16 = (idQuat *)inAxis;
      value = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->parentJoint.value;
      v18 = (idMat3 *)idMat3::ToQuat(this: &v25, result: v16);
      idTreeAnimator::GetWorldSpaceAttachmentTransform(
        this: TreeAnimator,
        jointIndex: value,
        translationOffset: inOrigin,
        rotationOffset: v18,
        origin: outOrigin,
        axis: outAxis);
    }
  }
  else
  {
    outOrigin->x = inOrigin->x;
    outOrigin->y = inOrigin->y;
    outOrigin->z = inOrigin->z;
    outAxis->mat[0].x = inAxis->mat[0].x;
    outAxis->mat[0].y = inAxis->mat[0].y;
    outAxis->mat[0].z = inAxis->mat[0].z;
    outAxis->mat[1].x = inAxis->mat[1].x;
    outAxis->mat[1].y = inAxis->mat[1].y;
    outAxis->mat[1].z = inAxis->mat[1].z;
    outAxis->mat[2].x = inAxis->mat[2].x;
    outAxis->mat[2].y = inAxis->mat[2].y;
    outAxis->mat[2].z = inAxis->mat[2].z;
  }
}


// ========================================================================
// ?Present@idPresentable@@UAAXXZ
// EA  : 0x82B69150
// RVA : 0x00B69150
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::Present(idPresentable *this)
{
  idLobbyBase *v2; // r3
  int v3; // r10
  int v4; // r9
  int v5; // r8
  int v6; // r7
  idRenderModel *model; // r31
  int v8; // [sp+8h] [-68h]
  int v9; // [sp+Ch] [-64h]
  int v10; // [sp+10h] [-60h]
  int v11; // [sp+14h] [-5Ch]
  int v12; // [sp+18h] [-58h]
  idPresentable *v13; // [sp+1Ch] [-54h]

  v2 = session->GetActingGameStateLobbyBase(this: session);
  if ( v2->IsHost(this: v2) != 0 )
  {
    idClientGame::MarkPresentableSerialized(
      this: clientGame,
      presentable: this,
      serialized: true,
      deleted: false,
      a5: v6,
      a6: v5,
      a7: v4,
      a8: v3,
      a9: v8,
      a10: v9,
      a11: v10,
      a12: v11,
      a13: v12,
      a14: v13);
    this->shouldPresent = true;
  }
  if ( (unsigned __int8)idPresentable::GetShouldPresent(this) != 0 && this->model != nullptr )
  {
    idPresentable::UpdateModelTransform(this);
    idPresentable::UpdateModelGroupMaster(this);
    if ( this->hidden )
    {
      model = this->model;
      if ( !model->unlinked )
      {
        idRenderModel::CommitThisFrame(this: model);
        model->unlinked = true;
      }
    }
    else
    {
      idRenderModel::CommitThisFrame(this: this->model);
    }
  }
}


// ========================================================================
// ?Serialize@idPresentable@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B69240
// RVA : 0x00B69240
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::Serialize(idPresentable *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  idMat3 *p_axis; // r21
  int *v6; // r9
  idVec3 *origins; // r24
  double y; // fp7
  float *p_z; // r11
  int v10; // ctr
  float x; // r6
  float v12; // r5
  idBitMsg *v13; // r3
  __int64 v14; // r8
  double v15; // fp0
  double v16; // fp13
  double z; // fp12
  double v18; // fp11
  double w; // fp10
  double v20; // fp9
  double v21; // fp8
  double v22; // fp7
  double v23; // fp6
  double v24; // fp5
  double v25; // fp4
  double v26; // fp3
  idBitMsg *v27; // r3
  int value; // r11
  unsigned __int16 Bits; // r29
  idBitMsg *v30; // r3
  idIndex<short,enum invalidJointIndex_t> *v31; // r11
  idBitMsg *v32; // r3
  idBitMsg *v33; // r3
  gameTeam_t team; // r28
  idBitMsg *v35; // r3
  gameTeam_t v36; // r29
  unsigned int v37; // r10
  int v38; // r22
  int ownerPlayerIndex; // r29
  idBitMsg *v40; // r3
  idBitMsg *v41; // r3
  usableState_t usableState; // r29
  idBitMsg *v43; // r3
  unsigned int v44; // r10
  bool shouldPresent; // r29
  idBitMsg *v46; // r3
  idBitMsg *v47; // r3
  bool v48; // r29
  BOOL v49; // r26
  idBitMsg *v50; // r3
  idBitMsg *v51; // r3
  const char *str; // r29
  idRenderModel *model; // r11
  idRenderWorld *v54; // r3
  idPresentable_vtbl *v55; // r29
  int v56; // r3
  idRenderModel *v57; // r11
  double v58; // fp13
  idRenderModel *v59; // r29
  idRenderModel_vtbl *v60; // r28
  int v61; // r3
  highlightColor_t highlightColor; // r28
  idBitMsg *v63; // r3
  highlightColor_t v64; // r29
  idRenderModel *v65; // r11
  idClipModelInfo::clipModelType_t type; // r26
  idVec3 *p_size; // r28
  int clipModelContents; // r19
  int *p_clipModelContents; // r20
  int *p_numSides; // r27
  const idMaterial **p_overrideClipMaterial; // r25
  idVec3 *p_clipModelSpawnPos; // r22
  idMat3 *p_clipModelSpawnAxis; // r24
  idClipModelInfo::clipModelType_t v74; // r11
  idBitMsg *v75; // r3
  idClipModelInfo::clipModelType_t v76; // r8
  float *v77; // r10
  int v78; // ctr
  idSysMutex *p_viewNoteMutex; // r11
  idRenderModel *v80; // r11
  idRenderModel *v81; // r11
  const char *v82; // r29
  const char *v83; // r3
  idVec3 *v84; // r11
  int i; // ctr
  double v86; // fp12
  double v87; // fp11
  idClipModelInfo::clipModelType_t v88; // r11
  int v89; // r5
  idClipModel *v90; // r3
  idClipModel *v91; // r3
  int v92; // r4
  char *v93; // r11
  char v94; // r11
  bool v95; // zf
  idClipModel *v96; // r3
  idClipModel *v97; // r3
  char *v98; // r11
  char v99; // r11
  idClipModel *v100; // r3
  idClipModel *v101; // r3
  idClipModel *v102; // r3
  idClipModel *v103; // r3
  idClipModel *v104; // r3
  idClipModel *clipModel; // r11
  idClipModel *v106; // r3
  idClipModel *v107; // r3
  idVec3 *p_origin; // [sp+50h] [-800h] BYREF
  idVec3 v109[2]; // [sp+58h] [-7F8h] BYREF
  idBounds v110; // [sp+70h] [-7E0h] BYREF
  int v111; // [sp+8Ch] [-7C4h] BYREF
  idQuat v112; // [sp+90h] [-7C0h] BYREF
  float v113; // [sp+A0h] [-7B0h]
  float v114; // [sp+A4h] [-7ACh]
  float v115; // [sp+A8h] [-7A8h]
  float v116; // [sp+ACh] [-7A4h]
  float v117; // [sp+B0h] [-7A0h]
  char v118[256]; // [sp+C0h] [-790h] BYREF
  idTraceModel v119; // [sp+1C0h] [-690h] BYREF

  ++this->serializeCount;
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->entityTypeFlags, numBits: 32);
  else
    this->entityTypeFlags = idBitMsg::ReadBits(this: msg, numBits: 32);
  this->origins[0].x = this->origins[1].x;
  this->origins[0].y = this->origins[1].y;
  this->origins[0].z = this->origins[1].z;
  p_axis = &this->axis;
  this->axes[0].mat[0].x = this->axes[1].mat[0].x;
  v6 = &v111;
  this->axes[0].mat[0].y = this->axes[1].mat[0].y;
  p_origin = &this->axes[0].mat[1];
  this->axes[0].mat[0].z = this->axes[1].mat[0].z;
  p_origin = &this->axes[1].mat[1];
  this->axes[0].mat[1].x = this->axes[1].mat[1].x;
  origins = this->origins;
  y = this->axes[1].mat[1].y;
  p_origin = &this->axes[0].mat[2];
  this->axes[0].mat[1].y = y;
  p_z = &this->origin.z;
  this->axes[0].mat[1].z = this->axes[1].mat[1].z;
  v10 = 9;
  this->axes[0].mat[2].x = this->axes[1].mat[2].x;
  this->axes[0].mat[2].y = this->axes[1].mat[2].y;
  this->axes[0].mat[2].z = this->axes[1].mat[2].z;
  x = this->origin.x;
  v12 = this->origin.y;
  v109[0].z = this->origin.z;
  v109[0].y = v12;
  v109[0].x = x;
  do
  {
    *++v6 = *(_DWORD *)++p_z;
    --v10;
  }
  while ( v10 != 0 );
  if ( this->GetType(this) == PRESENTABLE_PLAYER || this->GetType(this) == PRESENTABLE_PUSHER )
  {
    idSerializer::Serialize(this: ser, value: v109);
  }
  else
  {
    v13 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteQuantizedVector<idVec3,32768,17>(this: v13, v: v109);
    else
      idBitMsg::ReadQuantizedVector<idVec3,32768,17>(this: v13, v: v109);
  }
  idSerializer::SerializeQ(this: ser, axis: &v112, bits: 15, a4: v14);
  v15 = v109[0].x;
  v16 = v109[0].y;
  z = v109[0].z;
  this->origins[1].x = v109[0].x;
  this->origins[1].y = v16;
  this->origins[1].z = z;
  p_origin = &this->axes[1].mat[2];
  v18 = v112.x;
  this->axes[1].mat[0].x = v112.x;
  w = v112.w;
  v20 = v112.y;
  v21 = v112.z;
  this->axes[1].mat[1].x = v112.w;
  this->axes[1].mat[0].y = v20;
  this->axes[1].mat[0].z = v21;
  v22 = v113;
  this->axes[1].mat[1].y = v113;
  v23 = v114;
  v24 = v115;
  this->axes[1].mat[1].z = v114;
  v25 = v116;
  this->axes[1].mat[2].x = v24;
  v26 = v117;
  this->axes[1].mat[2].y = v25;
  this->axes[1].mat[2].z = v26;
  if ( this->serializeCount == 1 && !ser->writing && !this->becameReplicated )
  {
    this->origin.x = v15;
    this->origin.y = v16;
    this->origin.z = z;
    p_axis->mat[0].x = v18;
    this->axis.mat[1].x = w;
    this->axis.mat[0].y = v20;
    p_origin = &this->axes[0].mat[2];
    this->axis.mat[0].z = v21;
    this->axis.mat[1].y = v22;
    this->axis.mat[1].z = v23;
    this->axis.mat[2].x = v24;
    this->axis.mat[2].y = v25;
    this->axis.mat[2].z = v26;
    origins->x = v15;
    this->origins[0].y = v16;
    this->origins[0].z = z;
    this->axes[0].mat[0].x = v18;
    this->axes[0].mat[1].x = w;
    this->axes[0].mat[0].y = v20;
    this->axes[0].mat[0].z = v21;
    this->axes[0].mat[1].y = v22;
    this->axes[0].mat[1].z = v23;
    this->axes[0].mat[2].x = v24;
    this->axes[0].mat[2].y = v25;
    this->axes[0].mat[2].z = v26;
  }
  v27 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v27, value: this->parent.spawnId, numBits: 32);
  else
    this->parent.spawnId = idBitMsg::ReadBits(this: v27, numBits: 32);
  value = this->parentJoint.value;
  if ( value == NULL_JOINT_INDEX.value )
    LOWORD(value) = -1;
  Bits = value;
  v30 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v30, (unsigned __int16)value, numBits: 16);
  else
    Bits = idBitMsg::ReadBits(this: v30, numBits: 16);
  if ( Bits == 0xFFFF )
  {
    v31 = &NULL_JOINT_INDEX;
  }
  else
  {
    HIWORD(p_origin) = Bits;
    v31 = (idIndex<short,enum invalidJointIndex_t> *)&p_origin;
  }
  this->parentJoint = (idIndex<short,enum invalidJointIndex_t>)v31->value;
  v32 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v32, value: this->controller.spawnId, numBits: 32);
  else
    this->controller.spawnId = idBitMsg::ReadBits(this: v32, numBits: 32);
  v33 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v33, value: this->entityNumber, numBits: 32);
  else
    this->entityNumber = idBitMsg::ReadBits(this: v33, numBits: 32);
  if ( !ser->writing && this->index >= 12288 )
    this->entityNumber = 0x1FFF;
  team = this->team;
  v35 = ser->msg;
  v36 = team;
  v37 = _cntlzw(5u);
  v38 = 32 - v37;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v35, value: this->team, numBits: 32 - v37);
  else
    v36 = idBitMsg::ReadBits(this: v35, numBits: 32 - v37);
  this->team = v36;
  ownerPlayerIndex = this->ownerPlayerIndex;
  v40 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v40, value: this->ownerPlayerIndex, numBits: 32);
  else
    this->ownerPlayerIndex = idBitMsg::ReadBits(this: v40, numBits: 32);
  if ( !ser->writing && (team != this->team || ownerPlayerIndex != this->ownerPlayerIndex) )
    idPresentable::IdentifyFriendFoeNeutral(this);
  v41 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v41, value: this->usablePlayerMask, numBits: 8);
  else
    this->usablePlayerMask = idBitMsg::ReadBits(this: v41, numBits: 8);
  usableState = this->usableState;
  v43 = ser->msg;
  v44 = _cntlzw(0xEu);
  if ( ser->writing )
    idBitMsg::WriteBits(this: v43, value: this->usableState, numBits: 32 - v44);
  else
    usableState = idBitMsg::ReadBits(this: v43, numBits: 32 - v44);
  this->usableState = usableState;
  shouldPresent = this->shouldPresent;
  v46 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v46, value: this->shouldPresent, numBits: 1);
  else
    shouldPresent = (_cntlzw(idBitMsg::ReadBits(this: v46, numBits: 1) - 1) & 0x20) != 0;
  this->shouldPresent = shouldPresent;
  if ( ser->writing )
  {
    HIBYTE(p_origin) = ser->writing;
    this->shouldPresent = false;
  }
  else if ( shouldPresent )
  {
    this->shouldPresentCounter = cg_optimizePresentsCountdown.valueInteger;
  }
  v47 = ser->msg;
  v48 = this->model != nullptr;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v47, value: this->model != nullptr, numBits: 1);
  else
    v48 = (_cntlzw(idBitMsg::ReadBits(this: v47, numBits: 1) - 1) & 0x20) != 0;
  v49 = v48;
  if ( v48 )
  {
    v51 = ser->msg;
    if ( ser->writing )
    {
      str = this->model->name.str;
      idBitMsg::WriteString(this: v51, s: str, maxLength: -1, make7Bit: true);
      if ( *str == 0 )
      {
        idLib::Warning(
          fmt: "Presentable::Serialize() %d %s has a model with no name",
          this->entityNumber,
          this->entity->name.data);
        return;
      }
    }
    else
    {
      idBitMsg::ReadString(this: v51, buffer: v118, bufferSize: 256);
      model = this->model;
      if ( model != nullptr && idStr::Cmp(s1: model->name.str, s2: v118) != 0 )
        idPresentable::FreeRenderModel(this);
      if ( v118[0] == 0 )
      {
        idLib::Warning(fmt: "Presentable::Serialize() %d received a model with no name", this->entityNumber);
        return;
      }
      if ( this->model == nullptr )
      {
        v54 = common->RW(this: common);
        v55 = this->__vftable;
        v56 = (int)v54->AllocRenderModel(this: v54, a2: v118, a3: true, a4: -1);
        v55->SetRenderModel(this, a2: (idRenderModel *)v56, a3: false);
        v57 = this->model;
        if ( v57 == nullptr )
        {
          idLib::Error(fmt: "AllocRenderModel failed in Presentable::Serialize() for model %s", v118);
          goto _LN515;
        }
        if ( !v57->deferredPositionInitialized || !v57->useDeferredPosition )
        {
          v57->g.origin.x = origins->x;
          p_origin = &v57->g.origin;
          v57->g.origin.y = this->origins[0].y;
          v57->g.origin.z = this->origins[0].z;
        }
        v57->deferredOrigin.x = origins->x;
        v58 = this->origins[0].y;
        p_origin = &v57->deferredOrigin;
        v57->deferredOrigin.y = v58;
        v57->deferredOrigin.z = this->origins[0].z;
        idRenderModel::SetAxis(this: this->model, a: this->axes);
      }
    }
  }
  else
  {
    idPresentable::FreeRenderModel(this);
  }
  if ( this->ShouldSerializeHidden(this) )
    this->hidden = idSerializer::SerializeBoolNonRef(this: ser, value: this->hidden);
  v50 = ser->msg;
  if ( ser->writing )
  {
    idBitMsg::WriteBits(this: v50, value: this->groupMaster.spawnId, numBits: 32);
    goto LABEL_83;
  }
_LN515:
  this->groupMaster.spawnId = idBitMsg::ReadBits(this: v50, numBits: 32);
LABEL_83:
  if ( v49 )
  {
    v59 = this->model;
    v60 = v59->__vftable;
    v61 = ((int (__fastcall *)(idPresentable *))this->ShouldSerializeRenderModelParms)(a1: this);
    v60->SerializeSnapshot(this: v59, a2: ser, a3: v61);
  }
  highlightColor = this->highlightColor;
  v63 = ser->msg;
  v64 = highlightColor;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v63, value: this->highlightColor, numBits: v38);
  else
    v64 = idBitMsg::ReadBits(this: v63, numBits: v38);
  this->highlightColor = v64;
  if ( !ser->writing && highlightColor != v64 && v49 )
  {
    v65 = this->model;
    this->highlightColor = v64;
    v65->g.highlightColor = v64;
  }
  if ( common->TimeTrialPlaying(this: common)
    || common->TimeTrialRecording(this: common)
    || common->DemoPlaying(this: common)
    || common->DemoRecording(this: common) )
  {
    goto LABEL_181;
  }
  type = this->clipModelInfo.type;
  this->clipModelInfo.type = idSerializer::SerializeUMaxNonRef(this: ser, value: type, maxSize: 5u);
  p_size = &this->clipModelInfo.size;
  clipModelContents = this->clipModelContents;
  p_clipModelContents = &this->clipModelContents;
  idSerializer::Serialize(this: ser, value: &this->clipModelInfo.size);
  p_numSides = &this->clipModelInfo.numSides;
  idSerializer::Serialize(this: ser, value: &this->clipModelInfo.numSides);
  this->clipModelInfo.clipShrink = idSerializer::SerializeBoolNonRef(this: ser, value: this->clipModelInfo.clipShrink);
  this->clipModelDynamic = idSerializer::SerializeBoolNonRef(this: ser, value: this->clipModelDynamic);
  this->clipModelDynamicAxis = idSerializer::SerializeBoolNonRef(this: ser, value: this->clipModelDynamicAxis);
  p_overrideClipMaterial = &this->clipModelInfo.overrideClipMaterial;
  idSerializer::Serialize<idMaterial>(this: ser, decl: &this->clipModelInfo.overrideClipMaterial);
  idSerializer::Serialize(this: ser, value: &this->clipModelContents);
  if ( this->clipModelDynamic || this->clipModelDynamicAxis )
  {
    p_clipModelSpawnAxis = &this->clipModelSpawnAxis;
    this->clipModelSpawnPos.x = this->origin.x;
    p_clipModelSpawnPos = &this->clipModelSpawnPos;
    p_origin = &this->clipModelSpawnAxis.mat[2];
    this->clipModelSpawnPos.y = this->origin.y;
    this->clipModelSpawnPos.z = this->origin.z;
    this->clipModelSpawnAxis.mat[0].x = p_axis->mat[0].x;
    this->clipModelSpawnAxis.mat[0].y = this->axis.mat[0].y;
    this->clipModelSpawnAxis.mat[0].z = this->axis.mat[0].z;
    this->clipModelSpawnAxis.mat[1].x = this->axis.mat[1].x;
    this->clipModelSpawnAxis.mat[1].y = this->axis.mat[1].y;
    this->clipModelSpawnAxis.mat[1].z = this->axis.mat[1].z;
    this->clipModelSpawnAxis.mat[2].x = this->axis.mat[2].x;
    this->clipModelSpawnAxis.mat[2].y = this->axis.mat[2].y;
    this->clipModelSpawnAxis.mat[2].z = this->axis.mat[2].z;
  }
  else
  {
    p_clipModelSpawnPos = &this->clipModelSpawnPos;
    idSerializer::Serialize(this: ser, value: &this->clipModelSpawnPos);
    p_clipModelSpawnAxis = &this->clipModelSpawnAxis;
    idSerializer::Serialize(this: ser, axis: &this->clipModelSpawnAxis);
  }
  v74 = this->clipModelInfo.type;
  if ( v74 == CLIPMODEL_CUSTOM || v74 == CLIPMODEL_RENDERMODEL )
  {
    v75 = ser->msg;
    if ( ser->writing )
    {
      idBitMsg::WriteString(this: v75, s: this->clipModelInfo.clipModelName.str, maxLength: -1, make7Bit: true);
    }
    else
    {
      idBitMsg::ReadString(this: v75, buffer: v118, bufferSize: 256);
      idAtomicString::Set(this: &this->clipModelInfo.clipModelName, str_: v118);
    }
  }
  v76 = this->clipModelInfo.type;
  if ( v76 != CLIPMODEL_NONE )
  {
    memset(&v119.type, 0, 20);
    v77 = &v119.offset.z;
    v78 = 6;
    p_viewNoteMutex = &analysisClient.viewNoteMutex;
    v119.offset.x = 0.0;
    v119.offset.y = 0.0;
    v119.offset.z = 0.0;
    do
    {
      ++p_viewNoteMutex;
      *++v77 = *(float *)&p_viewNoteMutex->handle;
      --v78;
    }
    while ( v78 != 0 );
    v119.radius = 0.0;
    v119.isConvex = false;
    v119.pad[2] = 0;
    v119.pad[1] = 0;
    v119.pad[0] = 0;
    if ( v76 == CLIPMODEL_BOUNDINGBOX && (v80 = this->model) != nullptr
      || ((LODWORD(this->clipModelInfo.size.z) | LODWORD(this->clipModelInfo.size.y) | LODWORD(p_size->x)) & 0x7FFFFFFF) == 0
      && (v80 = this->model) != nullptr )
    {
      v110.b[0].x = v80->referenceBounds.b[0].x;
      p_origin = &v80->referenceBounds.b[1];
      v110.b[0].y = v80->referenceBounds.b[0].y;
      v110.b[0].z = v80->referenceBounds.b[0].z;
      v110.b[1] = v80->referenceBounds.b[1];
    }
    else
    {
      if ( p_size->x <= 0.0 || this->clipModelInfo.size.y <= 0.0 || this->clipModelInfo.size.z <= 0.0 )
      {
        v81 = this->model;
        if ( v81 != nullptr )
          v82 = v81->name.str;
        else
          v82 = this->clipModelInfo.clipModelName.str;
        v83 = idVec3::ToString(this: (idAngles *)&this->clipModelInfo.size, precision: 2);
        idLib::Warning(fmt: "invalid clip model size '%s' on entity '%s'", v83, v82);
        v84 = &this->clipModelInfo.size;
        for ( i = 3; i != 0; --i )
        {
          if ( v84->x <= 0.0 )
            v84->x = 1.0;
          v84 = (idVec3 *)((char *)v84 + 4);
        }
      }
      v86 = this->clipModelInfo.size.y;
      v87 = p_size->x;
      v110.b[1].z = this->clipModelInfo.size.z;
      v110.b[0].z = 0.0;
      v110.b[0].y = (float)v86 * (float)-0.5;
      v110.b[0].x = (float)v87 * (float)-0.5;
      v110.b[1].x = (float)v87 * (float)0.5;
      v110.b[1].y = (float)v86 * (float)0.5;
    }
    if ( ser->writing || this->clipModel != nullptr )
      goto LABEL_174;
    v88 = this->clipModelInfo.type;
    if ( v88 == CLIPMODEL_BOX || v88 == CLIPMODEL_BOUNDINGBOX )
    {
      idTraceModel::SetupBox(this: &v119, boxBounds: &v110);
      v104 = (idClipModel *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0xD8u,
                              tag: TAG_CLIPMODEL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
      p_origin = (idVec3 *)v104;
      if ( v104 != nullptr )
        v91 = idClipModel::idClipModel(
                this: v104,
                clip: &clientGame->clip,
                trm: &v119,
                numTraceModels: 1,
                material: nullptr);
      else
        v91 = nullptr;
      v92 = *p_clipModelContents;
      this->clipModel = v91;
    }
    else if ( v88 == CLIPMODEL_CYLINDER )
    {
      v89 = *p_numSides;
      if ( *p_numSides < 3 )
        v89 = 3;
      idTraceModel::SetupCylinder(this: &v119, cylBounds: &v110, numSides: v89);
      v90 = (idClipModel *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xD8u,
                             tag: TAG_CLIPMODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      p_origin = (idVec3 *)v90;
      if ( v90 != nullptr )
        v91 = idClipModel::idClipModel(
                this: v90,
                clip: &clientGame->clip,
                trm: &v119,
                numTraceModels: 1,
                material: nullptr);
      else
        v91 = nullptr;
      v92 = *p_clipModelContents;
      this->clipModel = v91;
    }
    else
    {
      if ( v88 != CLIPMODEL_CUSTOM && v88 != CLIPMODEL_RENDERMODEL || type == v88 )
      {
LABEL_172:
        clipModel = this->clipModel;
        if ( clipModel != nullptr )
        {
          clipModel->enabled = true;
          idClipModel::Link(
            this: this->clipModel,
            newEntityNumber: this->entityNumber,
            newPhysicsId: -1,
            newBodyId: 0,
            newOrigin: p_clipModelSpawnPos,
            newAxis: p_clipModelSpawnAxis);
        }
LABEL_174:
        v106 = this->clipModel;
        if ( v106 != nullptr && !this->overridingClipContents && clipModelContents != *p_clipModelContents )
          idClipModel::SetContents(this: v106, newContents: *p_clipModelContents);
        goto LABEL_178;
      }
      if ( v88 == CLIPMODEL_CUSTOM )
      {
        v93 = (char *)this->clipModelInfo.clipModelName.str;
        if ( v93 == &byte_8200D768 || (v95 = *v93 != 0, v94 = 0, !v95) )
          v94 = 1;
        if ( v94 == 0 )
        {
          v96 = (idClipModel *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xD8u,
                                 tag: TAG_CLIPMODEL,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
          p_origin = (idVec3 *)v96;
          v97 = v96 != nullptr
              ? idClipModel::idClipModel(
                  this: v96,
                  clip: &clientGame->clip,
                  name: this->clipModelInfo.clipModelName.str,
                  overrideClipMaterial: *p_overrideClipMaterial)
              : nullptr;
          this->clipModel = v97;
          if ( v97 != nullptr )
            idLib::Printf(fmt: " CLIPMODEL 1: %s \n", this->clipModelInfo.clipModelName.str);
        }
      }
      else
      {
        v98 = (char *)this->clipModelInfo.clipModelName.str;
        if ( v98 == &byte_8200D768 || (v95 = *v98 != 0, v99 = 0, !v95) )
          v99 = 1;
        if ( v99 == 0 )
        {
          v100 = (idClipModel *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0xD8u,
                                  tag: TAG_CLIPMODEL,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
          p_origin = (idVec3 *)v100;
          v101 = v100 != nullptr
               ? idClipModel::idClipModel(
                   this: v100,
                   clip: &clientGame->clip,
                   name: this->clipModelInfo.clipModelName.str,
                   overrideClipMaterial: *p_overrideClipMaterial)
               : nullptr;
          this->clipModel = v101;
          if ( v101 != nullptr )
            idLib::Printf(fmt: " CLIPMODEL 2: %s \n", this->clipModelInfo.clipModelName.str);
        }
        if ( this->clipModel == nullptr && this->model != nullptr )
        {
          v102 = (idClipModel *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0xD8u,
                                  tag: TAG_CLIPMODEL,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
          p_origin = (idVec3 *)v102;
          v103 = v102 != nullptr
               ? idClipModel::idClipModel(
                   this: v102,
                   clip: &clientGame->clip,
                   name: this->model->name.str,
                   overrideClipMaterial: *p_overrideClipMaterial)
               : nullptr;
          this->clipModel = v103;
          if ( v103 != nullptr )
            idLib::Printf(fmt: " CLIPMODEL 3: %s \n", this->model->name.str);
        }
      }
      v91 = this->clipModel;
      if ( v91 == nullptr )
      {
        idLib::Printf(
          fmt: " CLIPMODEL FAILED: %s type: %i \n",
          this->clipModelInfo.clipModelName.str,
          this->clipModelInfo.type);
        goto LABEL_172;
      }
      v92 = *p_clipModelContents;
    }
    idClipModel::SetContents(this: v91, newContents: v92);
    goto LABEL_172;
  }
LABEL_178:
  if ( this->clipModelInfo.type == CLIPMODEL_NONE )
  {
    v107 = this->clipModel;
    if ( v107 != nullptr )
    {
      idClipModel::Delete(this: v107);
      this->clipModel = nullptr;
    }
  }
LABEL_181:
  if ( this->hideDuringFirstSSInterval )
  {
    if ( this->serializeCount != 1 || ser->writing )
    {
      if ( this->hideDuringFirstSSInterval && this->serializeCount == 2 && !ser->writing )
        this->Show(this);
    }
    else if ( this->hidden )
    {
      this->hideDuringFirstSSInterval = false;
    }
    else
    {
      this->Hide(this, a2: true);
      this->hideDuringFirstSSInterval = true;
    }
  }
  this->SerializeFX(this, a2: ser);
}


// ========================================================================
// $LN488
// EA  : 0x82B6A2A4
// RVA : 0x00B6A2A4
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void _LN488()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2128 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$493533
// EA  : 0x82B6A2D0
// RVA : 0x00B6A2D0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void _unwind_493533()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2128 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$493534
// EA  : 0x82B6A2FC
// RVA : 0x00B6A2FC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void _unwind_493534()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2128 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$493535
// EA  : 0x82B6A328
// RVA : 0x00B6A328
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void _unwind_493535()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2128 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$493531
// EA  : 0x82B6A354
// RVA : 0x00B6A354
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void _unwind_493531()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2128 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?SetGroupMaster@idPresentable@@QAAXPAV1@@Z
// EA  : 0x82B6A380
// RVA : 0x00B6A380
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::SetGroupMaster(idPresentable *this, idPresentable *pres)
{
  idPresentablePtr<idPresentable> *p_groupMaster; // r31
  unsigned int spawnId; // r11
  unsigned int Index; // r30
  idPresentable *v6; // r3

  p_groupMaster = &this->groupMaster;
  spawnId = 0;
  if ( pres != nullptr )
    spawnId = pres->spawnId;
  p_groupMaster->spawnId = spawnId;
  if ( this->model != nullptr )
  {
    Index = -1;
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &this->groupMaster) != nullptr
      && idPresentablePtr<idPresentableProjectile>::operator->(this: p_groupMaster)->model != nullptr )
    {
      v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_groupMaster);
      Index = idRenderModel::GetIndex(this: v6->model);
    }
    this->model->g.groupMasterIndex = Index;
  }
}


// ========================================================================
// ?GetWorldTransform@idPresentable@@UAAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82B6A400
// RVA : 0x00B6A400
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __fastcall idPresentable::GetWorldTransform(idPresentable *this, idVec3 *outOrigin, idMat3 *outAxis)
{
  idPresentable::GetWorldTransformInternal(this, inOrigin: &this->origin, inAxis: &this->axis, outOrigin, outAxis);
}


// ========================================================================
// `dynamic initializer for 'cg_optimizePresents''
// EA  : 0x8336D8F0
// RVA : 0x0136D8F0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_optimizePresents__()
{
  idCVar::idCVar(
    this: &cg_optimizePresents,
    name: "cg_optimizePresents",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_optimizePresents__);
}


// ========================================================================
// `dynamic initializer for 'cg_optimizePresentsCountdown''
// EA  : 0x8336D948
// RVA : 0x0136D948
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_optimizePresentsCountdown__()
{
  idCVar::idCVar(
    this: &cg_optimizePresentsCountdown,
    name: "cg_optimizePresentsCountdown",
    value: "5",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_optimizePresentsCountdown__);
}

