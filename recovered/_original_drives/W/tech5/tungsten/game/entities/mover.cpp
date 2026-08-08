
// ========================================================================
// ?SnapTimeToPhysicsFrame@@YAHH@Z
// EA  : 0x82C7CC88
// RVA : 0x00C7CC88
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

int __fastcall SnapTimeToPhysicsFrame(int t)
{
  int v1; // r31
  signed int v2; // r3

  v1 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED) + t - 1;
  v2 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  __twllei(v2, 0);
  __twlgei(v2 & ~(__ROL4__(v1, 1) - 1), 0xFFFFFFFF);
  return v1 / v2 * v2;
}


// ========================================================================
// ??1navSpace_t@idMover@@QAA@XZ
// EA  : 0x82C7CD20
// RVA : 0x00C7CD20
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::navSpace_t::~navSpace_t(idMover::navSpace_t *this)
{
  idNavigationSpace::~idNavigationSpace(this: &this->navSpace);
}


// ========================================================================
// ?IsCrosshairDisabled@idMover@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@@Z
// EA  : 0x82C7CD28
// RVA : 0x00C7CD28
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

int __fastcall idMover::IsCrosshairDisabled(
        idMover *this,
        idActor *activator,
        const idFocusTrace *ft,
        usableState_t usable)
{
  if ( this->lastCommand != MOVER_NONE )
    return 0;
  else
    return idEntity::IsCrosshairDisabled(this, activator, ft, usable);
}


// ========================================================================
// ?GetOnlineUsableState@idMover@@UBA?AW4usableState_t@@XZ
// EA  : 0x82C7CD40
// RVA : 0x00C7CD40
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

usableState_t __fastcall idMover::GetOnlineUsableState(idMover *this)
{
  char ForceDormant; // r30
  idScriptObject *v3; // r3
  idScriptObject *v4; // r3
  usableState_t result; // r3
  idScriptFunction v6; // [sp+50h] [-160h] BYREF

  ForceDormant = idEntity::GetForceDormant(this);
  v3 = (idScriptObject *)this->GetScriptObject(this);
  if ( !idScriptObject::HasObject(this: v3) )
    return USABLE_NOT_USABLE;
  if ( ForceDormant != 0 )
    return USABLE_NOT_USABLE;
  idScriptFunction::idScriptFunction(this: &v6);
  v4 = (idScriptObject *)this->GetScriptObject(this);
  if ( idScriptObject::GetFunction(this: v4, name: "use") == nullptr )
    return USABLE_NOT_USABLE;
  result = USABLE_MOVER;
  if ( this->lastCommand != MOVER_NONE )
    return USABLE_NOT_USABLE;
  return result;
}


// ========================================================================
// ?UpdateRotationSound@idMover@@IAAXW4moveStage_t@1@@Z
// EA  : 0x82C7CDF0
// RVA : 0x00C7CDF0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::UpdateRotationSound(idMover *this, idMover::moveStage_t stage)
{
  this->move.currentStage = stage;
  if ( (unsigned int)stage <= FINISHED_STAGE )
  {
    if ( stage == LINEAR_STAGE )
    {
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY,
        shader: this->sndMove,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    }
    else if ( stage == DECELERATION_STAGE )
    {
      idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY2,
        shader: this->sndDecel,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    }
    else if ( stage != ACCELERATION_STAGE )
    {
      idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
    }
    else
    {
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY2,
        shader: this->sndAccel,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY,
        shader: this->sndMove,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    }
  }
}


// ========================================================================
// ?Event_IsMoving@idMover@@AAA?AVeventInt@@XZ
// EA  : 0x82C7CEF8
// RVA : 0x00C7CEF8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_IsMoving(idMover *this, eventInt *result)
{
  eventInt::eventInt((eventInt *)this, i: result[544].value != 0);
  return this;
}


// ========================================================================
// ?Event_IsRotating@idMover@@AAA?AVeventInt@@XZ
// EA  : 0x82C7CF38
// RVA : 0x00C7CF38
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_IsRotating(idMover *this, eventInt *result)
{
  int v3; // r4

  v3 = idPhysics_Parametric::GetAngularExtrapolationType(this: (idPhysics_Parametric *)&result[200]) != EXTRAPOLATION_NONE;
  eventInt::eventInt((eventInt *)this, i: v3);
  return this;
}


// ========================================================================
// ??1idFuncRotate@@UAA@XZ
// EA  : 0x82C7CF90
// RVA : 0x00C7CF90
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idFuncRotate::~idFuncRotate(idFuncRotate *this)
{
  this->__vftable = (idFuncRotate_vtbl *)&idFuncRotate::`vftable';
  idPhysics_Parametric::~idPhysics_Parametric(this: &this->physicsObj);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$498058
// EA  : 0x82C7CFE4
// RVA : 0x00C7CFE4
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_498058()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?Think@idFuncRotate@@UAAXXZ
// EA  : 0x82C7D010
// RVA : 0x00C7D010
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idFuncRotate::Think(idFuncRotate *this)
{
  if ( (unsigned __int8)idEntity::UpdateDormant(this) == 0 )
  {
    idEntity::RunPhysics(this);
    this->UpdateFX(this);
    idEntity::UpdatePVSAreas(this);
  }
}


// ========================================================================
// ??1idFuncSwing@@UAA@XZ
// EA  : 0x82C7D078
// RVA : 0x00C7D078
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idFuncSwing::~idFuncSwing(idFuncSwing *this)
{
  this->__vftable = (idFuncSwing_vtbl *)&idFuncSwing::`vftable';
  idPhysics_Parametric::~idPhysics_Parametric(this: &this->physicsObj);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$498083
// EA  : 0x82C7D0CC
// RVA : 0x00C7D0CC
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_498083()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?OnActivate@idFuncSwing@@EAAXPAVidEntity@@@Z
// EA  : 0x82C7D0F8
// RVA : 0x00C7D0F8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idFuncSwing::OnActivate(idFuncSwing *this, idEntity *activator)
{
  idEntity::ForceDormancy(this, dormant: false, durationMS: 30000);
}


// ========================================================================
// ?Hide@idMoverMM@@UAAXXZ
// EA  : 0x82C7D108
// RVA : 0x00C7D108
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::Hide(idMoverMM *this)
{
  idEntity::BecomeInactive(this, flags: 7);
  idEntity::Hide(this);
  this->physicsObj.SetContents(this: &this->physicsObj, a2: 0, a3: -1);
}


// ========================================================================
// ?Show@idMoverMM@@UAAXXZ
// EA  : 0x82C7D160
// RVA : 0x00C7D160
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::Show(idMoverMM *this)
{
  int v2; // r5

  idEntity::BecomeActive(this, flags: 1);
  idEntity::BecomeActive(this, flags: 2);
  idEntity::Show(this);
  this->physicsObj.SetContents(this: &this->physicsObj, a2: this->contentsFlags, a3: -1);
  idEntity::SetPhysics(this, phys: &this->physicsObj, a3: v2);
}


// ========================================================================
// ?Event_SetCallback@idMoverMM@@AAA?AVeventInt@@XZ
// EA  : 0x82C7D1D8
// RVA : 0x00C7D1D8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_SetCallback(idMoverMM *this, eventInt *result)
{
  int value; // r11
  int v5; // r4

  value = result[1835].value;
  if ( value == 1 || value == 2 || value == 3 )
  {
    v5 = 1;
    result[1835].value = 0;
  }
  else
  {
    v5 = 0;
  }
  eventInt::eventInt((eventInt *)this, i: v5);
  return this;
}


// ========================================================================
// ?DoneMoving@idMoverMM@@MAAXXZ
// EA  : 0x82C7D240
// RVA : 0x00C7D240
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::DoneMoving(idMoverMM *this)
{
  idVec3 *p_dest_position; // r30
  int v3; // r3

  if ( this->lastCommand != MOVER_SPLINE )
  {
    p_dest_position = &this->dest_position;
    v3 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idPhysics_ParametricMM::SetLinearExtrapolation(
      this: &this->physicsObj,
      type: EXTRAPOLATION_NONE,
      currentTime: v3,
      duration: (unsigned int)p_dest_position,
      base: &vec3_origin,
      speed: &vec3_origin);
  }
  this->lastCommand = MOVER_NONE;
  idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
}


// ========================================================================
// ?UpdateMoveSound@idMoverMM@@IAAXW4moveStage_t@1@@Z
// EA  : 0x82C7D2E0
// RVA : 0x00C7D2E0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::UpdateMoveSound(idMoverMM *this, unsigned int stage)
{
  if ( stage <= 3 )
  {
    if ( stage == 1 )
    {
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY,
        shader: this->sndMove,
        soundShaderFlags: (soundShaderFlags_t)this->soundFlags,
        peerMask: 0xFFu);
    }
    else if ( stage == 2 )
    {
      idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY2,
        shader: this->sndDecel,
        soundShaderFlags: (soundShaderFlags_t)(this->soundFlags | 0x400),
        peerMask: 0xFFu);
    }
    else if ( stage != 0 )
    {
      idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
      idEntity::StopSound(this, channel: SND_CHANNEL_BODY2, peerMask: 0xFFu);
    }
    else
    {
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY2,
        shader: this->sndAccel,
        soundShaderFlags: (soundShaderFlags_t)(this->soundFlags | 0x400),
        peerMask: 0xFFu);
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY,
        shader: this->sndMove,
        soundShaderFlags: (soundShaderFlags_t)this->soundFlags,
        peerMask: 0xFFu);
    }
  }
}


// ========================================================================
// ?DoneRotating@idMoverMM@@MAAXXZ
// EA  : 0x82C7D3F8
// RVA : 0x00C7D3F8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::DoneRotating(idMoverMM *this)
{
  this->lastCommand = MOVER_NONE;
  idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
}


// ========================================================================
// ?UpdateRotationSound@idMoverMM@@IAAXW4moveStage_t@1@@Z
// EA  : 0x82C7D410
// RVA : 0x00C7D410
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::UpdateRotationSound(idMoverMM *this, unsigned int stage)
{
  if ( stage <= 3 )
  {
    if ( stage == 1 )
    {
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY,
        shader: this->sndMove,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    }
    else if ( stage == 2 )
    {
      idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY2,
        shader: this->sndDecel,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    }
    else if ( stage != 0 )
    {
      idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
    }
    else
    {
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY2,
        shader: this->sndAccel,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY,
        shader: this->sndMove,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    }
  }
}


// ========================================================================
// ?Event_IsMoving@idMoverMM@@AAA?AVeventInt@@XZ
// EA  : 0x82C7D510
// RVA : 0x00C7D510
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_IsMoving(idMoverMM *this, eventInt *result)
{
  eventInt::eventInt((eventInt *)this, i: result[1835].value != 0);
  return this;
}


// ========================================================================
// ?StopSpline@idMoverMM@@QAAXXZ
// EA  : 0x82C7D550
// RVA : 0x00C7D550
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::StopSpline(idMoverMM *this, int a2, int a3, bool a4)
{
  idPhysics_ParametricMM::SetSpline(
    this: &this->physicsObj,
    spline: nullptr,
    startTime: 0,
    totalTime: 0.0,
    useSplineAngles: a4,
    startAtEnd: this->useSplineAngles,
    startSplineTime: -1.0,
    a8: 0);
  this->spline = nullptr;
  this->splinePath = nullptr;
}


// ========================================================================
// ?UpdateAnimationControllers@idMoverMM@@UAA_NXZ
// EA  : 0x82C7D5B0
// RVA : 0x00C7D5B0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

int __fastcall idMoverMM::UpdateAnimationControllers(idMoverMM *this, int a2, int a3, int a4, int a5)
{
  ((void (__fastcall *)(idMoverMM *, idPhysics_ParametricMM *, int *, moverModifierFunction_t, int, _DWORD, double))this->UpdateMoverModifier)(
    a1: this,
    a2: &this->physicsObj,
    a3: &this->splineModifierIndex,
    a4: this->modifierIgnoreFlags,
    a5,
    a6: 0,
    a7: this->splineModifierLengthOffset);
  return 0;
}


// ========================================================================
// ?Event_IsRotating@idMoverMM@@AAA?AVeventInt@@XZ
// EA  : 0x82C7D5F8
// RVA : 0x00C7D5F8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_IsRotating(idMoverMM *this, eventInt *result)
{
  int v3; // r4

  v3 = idPhysics_ParametricMM::GetAngularExtrapolationType(this: (idPhysics_ParametricMM *)&result[1300]) != EXTRAPOLATION_NONE;
  eventInt::eventInt((eventInt *)this, i: v3);
  return this;
}


// ========================================================================
// ?HandleMoverModifier_SpawnEntity@idMoverMM@@MAAXABUsplineMoverModifier_t@@AAVidPhysics_ParametricMM@@MM@Z
// EA  : 0x82C7D648
// RVA : 0x00C7D648
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::HandleMoverModifier_SpawnEntity(
        idMoverMM *this,
        const splineMoverModifier_t *mod,
        idPhysics_ParametricMM *physObj,
        double currentSplinePosition,
        double splineTotalLength)
{
  ((void (__fastcall *)(idMoverMM *, const splineMoverModifier_t *, idPhysics_ParametricMM *, double, double))this->SpawnModifierEntity)(
    a1: this,
    a2: mod,
    a3: physObj,
    a4: currentSplinePosition,
    a5: splineTotalLength);
}


// ========================================================================
// ??1idMoverAttachment@@UAA@XZ
// EA  : 0x82C7D660
// RVA : 0x00C7D660
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverAttachment::~idMoverAttachment(idMoverAttachment *this)
{
  this->__vftable = (idMoverAttachment_vtbl *)&idMoverAttachment::`vftable';
  idAnimator_VehicleCar::~idAnimator_VehicleCar(this: &this->vehicleAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->channelAnimator);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$498205
// EA  : 0x82C7D6BC
// RVA : 0x00C7D6BC
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_498205()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$498206
// EA  : 0x82C7D6E4
// RVA : 0x00C7D6E4
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_498206()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 5200));
}


// ========================================================================
// ?AllocPresentable@idMover@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C7D7E0
// RVA : 0x00C7D7E0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idPresentablePusher *__fastcall idMover::AllocPresentable(idMover *this, idTreeAnimator *renderModel_)
{
  idPresentablePusher *v4; // r3

  v4 = (idPresentablePusher *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x988u,
                                tag: TAG_PRESENTABLE,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    return idPresentablePusher::idPresentablePusher(this: v4, owner: this, renderModel_);
  else
    return nullptr;
}


// ========================================================================
// __unwind$500122
// EA  : 0x82C7D848
// RVA : 0x00C7D848
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_500122()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?GetModelTransform@idMover@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C7D878
// RVA : 0x00C7D878
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::GetModelTransform(idMover *this, idVec3 *modelOrigin, idMat3 *modelAxis)
{
  if ( this->smoothMovement == 0.0 )
  {
    idEntity::GetModelTransform(this, modelOrigin, modelAxis);
  }
  else
  {
    *modelOrigin = this->averageModelOrigin;
    *modelAxis = this->averageModelAxis;
  }
}


// ========================================================================
// ?Use@idMover@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C7D8F8
// RVA : 0x00C7D8F8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

BOOL __fastcall idMover::Use(idMover *this, idEntity *activator, usableState_t usable)
{
  return (this->lastCommand == MOVER_NONE || !common->IsMultiplayer(this: common))
      && idEntity::Use(this, activator, usable);
}


// ========================================================================
// ?Hide@idMover@@UAAXXZ
// EA  : 0x82C7D968
// RVA : 0x00C7D968
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::Hide(idMover *this)
{
  int v2; // r10
  int v3; // r9
  int v4; // r8
  int v5; // r7
  int v6; // r6
  int v7; // r5
  idPresentable *presentable; // r11
  int v9; // r10
  int v10; // r9
  int v11; // r8
  int v12; // r7
  idPresentable *v13; // r4
  int v14; // [sp+8h] [-58h]
  int v15; // [sp+Ch] [-54h]
  int v16; // [sp+10h] [-50h]
  int v17; // [sp+14h] [-4Ch]
  int v18; // [sp+18h] [-48h]
  idPresentable *v19; // [sp+1Ch] [-44h]

  idEntity::Hide(this);
  this->physicsObj.SetContents(this: &this->physicsObj, a2: 0, a3: -1);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::SetClipModelContents(this: presentable, newContents: 0, a3: v7, a4: v6, a5: v5, a6: v4, a7: v3, a8: v2);
  v13 = this->presentable;
  if ( v13 != nullptr )
    idClientGame::MarkPresentableSerialized(
      this: clientGame,
      presentable: v13,
      serialized: true,
      deleted: false,
      a5: v12,
      a6: v11,
      a7: v10,
      a8: v9,
      a9: v14,
      a10: v15,
      a11: v16,
      a12: v17,
      a13: v18,
      a14: v19);
}


// ========================================================================
// ?Show@idMover@@UAAXXZ
// EA  : 0x82C7D9F8
// RVA : 0x00C7D9F8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::Show(idMover *this)
{
  int v2; // r5
  int v3; // r10
  int v4; // r9
  int v5; // r8
  int v6; // r7
  int v7; // r6
  int v8; // r5
  idPresentable *presentable; // r11
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
    this->physicsObj.SetContents(this: &this->physicsObj, a2: 1, a3: -1);
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
  idEntity::SetPhysics(this, phys: &this->physicsObj, a3: v2);
}


// ========================================================================
// ?Damage@idMover@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82C7DAA0
// RVA : 0x00C7DAA0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

float __fastcall idMover::Damage(
        idMover *this,
        idWorldspawn *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace)
{
  double v11; // fp1
  double v12; // fp12
  idMover_vtbl *v13; // r10
  float v15; // [sp+50h] [-30h] BYREF

  if ( this->TakesDamage(this) )
  {
    if ( inflictor == nullptr )
      inflictor = gameLocal->world;
    v11 = idDeclDamage::DamageAmount(this: damageDef);
    v15 = v11;
    if ( attacker != nullptr )
    {
      attacker->DamageFeedback(this: attacker, a2: this, a3: inflictor, a4: damageDef, a5: &v15);
      v11 = v15;
    }
    if ( v11 != 0.0 )
    {
      v12 = (float)(this->health - (float)v11);
      this->health = this->health - (float)v11;
      if ( v12 <= 0.0 )
      {
        v13 = this->__vftable;
        *(_BYTE *)&this->flags &= ~2u;
        v13->ActivateTargets(this, a2: attacker);
        v11 = v15;
      }
    }
  }
  else
  {
    v11 = 0.0;
  }
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?VectorForDir@idMover@@AAAXMAAVidVec3@@@Z
// EA  : 0x82C7DB98
// RVA : 0x00C7DB98
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::VectorForDir(idMover *this, double angle, idVec3 *vec, idVec3 *a4)
{
  const idAngles *v6; // r3
  double v7; // fp11
  const idAngles *v8; // r3
  double v9; // fp11
  const idAngles *v10; // r3
  const idAngles *v11; // r3
  double v12; // fp11
  const idAngles *v13; // r3
  double v14; // fp10
  double v15; // fp8
  const idAngles *v16; // r3
  const idAngles *v17; // r3
  const idAngles *LocalAngles; // r3
  idVec3 *v19; // r3
  double y; // fp10
  double z; // fp9
  const idVec3 *v22; // r3
  idVec3 v23; // [sp+50h] [-B0h] BYREF
  idAngles v24; // [sp+60h] [-A0h] BYREF
  idAngles v25; // [sp+70h] [-90h] BYREF
  idAngles v26; // [sp+80h] [-80h] BYREF
  idAngles v27; // [sp+90h] [-70h] BYREF
  idAngles v28; // [sp+A0h] [-60h] BYREF
  idAngles v29; // [sp+B0h] [-50h] BYREF
  idAngles v30; // [sp+C0h] [-40h] BYREF
  char v31; // [sp+D0h] [-30h] BYREF

  LODWORD(v23.y) = (int)angle;
  switch ( (int)angle )
  {
    case -12:
      LocalAngles = idPhysics_Parametric::GetLocalAngles(this: &this->physicsObj);
      v23.x = LocalAngles->pitch;
      v23.y = LocalAngles->yaw;
      v23.z = LocalAngles->roll;
      v19 = idAngles::ToForward(this: &v29, result: &v23);
      y = v19->y;
      z = v19->z;
      a4->x = v19->x * (float)-1.0;
      a4->y = (float)y * (float)-1.0;
      a4->z = (float)z * (float)-1.0;
      break;
    case -11:
      v17 = idPhysics_Parametric::GetLocalAngles(this: &this->physicsObj);
      v23.x = v17->pitch;
      v23.y = v17->yaw;
      v23.z = v17->roll;
      *a4 = *idAngles::ToForward(this: &v28, result: &v23);
      break;
    case -10:
      v16 = idPhysics_Parametric::GetLocalAngles(this: &this->physicsObj);
      v23.x = v16->pitch;
      v23.y = v16->yaw;
      v23.z = v16->roll;
      idAngles::ToVectors(this: (idAngles *)&v23, forward: nullptr, right: a4, up: nullptr);
      break;
    case -9:
      v13 = idPhysics_Parametric::GetLocalAngles(this: &this->physicsObj);
      v23.x = v13->pitch;
      v23.y = v13->yaw;
      v23.z = v13->roll;
      idAngles::ToVectors(this: (idAngles *)&v23, forward: nullptr, right: a4, up: nullptr);
      v14 = a4->y;
      v15 = a4->z;
      a4->x = a4->x * (float)-1.0;
      a4->y = (float)v14 * (float)-1.0;
      a4->z = (float)v15 * (float)-1.0;
      break;
    case -8:
    case -2:
      a4->x = 0.0;
      a4->y = 0.0;
      a4->z = -1.0;
      break;
    case -7:
    case -1:
      a4->x = 0.0;
      a4->y = 0.0;
      a4->z = 1.0;
      break;
    case -6:
      v11 = idPhysics_Parametric::GetLocalAngles(this: &this->physicsObj);
      v23.x = v11->pitch;
      v12 = (float)(v11->yaw + (float)180.0);
      v23.x = 0.0;
      v23.z = 0.0;
      v23.y = v12;
      *a4 = *idAngles::ToForward(this: &v27, result: &v23);
      break;
    case -5:
      v10 = idPhysics_Parametric::GetLocalAngles(this: &this->physicsObj);
      v23.x = v10->pitch;
      v23.y = v10->yaw;
      v23.x = 0.0;
      v23.z = 0.0;
      *a4 = *idAngles::ToForward(this: &v26, result: &v23);
      break;
    case -4:
      v8 = idPhysics_Parametric::GetLocalAngles(this: &this->physicsObj);
      v23.x = v8->pitch;
      v9 = (float)(v8->yaw - (float)90.0);
      v23.x = 0.0;
      v23.z = 0.0;
      v23.y = v9;
      *a4 = *idAngles::ToForward(this: &v25, result: &v23);
      break;
    case -3:
      v6 = idPhysics_Parametric::GetLocalAngles(this: &this->physicsObj);
      v23.x = v6->pitch;
      v7 = (float)(v6->yaw + (float)90.0);
      v23.x = 0.0;
      v23.z = 0.0;
      v23.y = v7;
      *a4 = *idAngles::ToForward(this: &v24, result: &v23);
      break;
    default:
      v23.y = angle;
      v23.x = 0.0;
      v23.z = 0.0;
      v22 = idAngles::ToForward(this: &v30, result: &v23);
      *(idEventReceiver *)a4 = idEntity::GetWorldVector(this: (idEntity *)&v31, result: this, vec: v22)->idEventReceiver;
      break;
  }
}


// ========================================================================
// ?Event_StopMoving@idMover@@AAA?AVeventVoid@@XZ
// EA  : 0x82C7DF78
// RVA : 0x00C7DF78
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_StopMoving(idMover *this, eventVoid *result)
{
  const idVec3 *LocalOrigin; // r3

  LocalOrigin = idPhysics_Parametric::GetLocalOrigin(this: (idPhysics_Parametric *)&result[800]);
  *(float *)&result[2132] = LocalOrigin->x;
  *(float *)&result[2136] = LocalOrigin->y;
  *(float *)&result[2140] = LocalOrigin->z;
  (*(void (__fastcall **)(eventVoid *))(*(_DWORD *)result + 632))(a1: result);
  return this;
}


// ========================================================================
// ?DoneMoving@idMover@@MAAXXZ
// EA  : 0x82C7DFE8
// RVA : 0x00C7DFE8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::DoneMoving(idMover *this)
{
  idVec3 *p_dest_position; // r30
  idPhysics_Parametric *p_physicsObj; // r29
  int v4; // r3
  idPhysics *Physics; // r3
  float *v6; // r3
  idPhysics *v7; // r3
  idAngles *v8; // r3
  idAngles *v9; // r3
  idClientGame *v10; // r11
  int GameMs; // r3
  int v12; // r3
  const idHandle<int,enum invalidThreadHandle_t,0> *value; // r4
  idMat3 v14[2]; // [sp+50h] [-50h] BYREF

  if ( this->lastCommand == MOVER_SPLINE )
  {
    Physics = idEntity::GetPhysics(this);
    v6 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    this->dest_position.x = *v6;
    this->dest_position.y = v6[1];
    this->dest_position.z = v6[2];
    v7 = idEntity::GetPhysics(this);
    v8 = (idAngles *)v7->GetAxis(this: v7, a2: 0);
    v9 = idMat3::ToAngles(this: v14, result: v8);
    this->dest_angles.pitch = v9->pitch;
    this->dest_angles.yaw = v9->yaw;
    v10 = clientGame;
    this->dest_angles.roll = v9->roll;
    p_physicsObj = &this->physicsObj;
    GameMs = idGameTimeManager::GetGameMs(this: &v10->gameTimeManager, type: GAMETIME_SCALED);
    idPhysics_Parametric::SetLinearExtrapolation(
      this: &this->physicsObj,
      type: EXTRAPOLATION_NONE,
      currentTime: GameMs,
      duration: (unsigned int)&this->dest_position,
      base: &vec3_origin,
      speed: &vec3_origin);
    v12 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idPhysics_Parametric::SetAngularExtrapolation(
      this: &this->physicsObj,
      type: EXTRAPOLATION_NONE,
      currentTime: v12,
      duration: (unsigned int)&this->dest_angles,
      base: &ang_zero,
      speed: &ang_zero);
  }
  else
  {
    p_dest_position = &this->dest_position;
    p_physicsObj = &this->physicsObj;
    v4 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idPhysics_Parametric::SetLinearExtrapolation(
      this: p_physicsObj,
      type: EXTRAPOLATION_NONE,
      currentTime: v4,
      duration: (unsigned int)p_dest_position,
      base: &vec3_origin,
      speed: &vec3_origin);
  }
  if ( this->resetPathOnCompletion && idPhysics_Parametric::GetSpline(this: p_physicsObj) != nullptr )
    idPhysics_Parametric::SetSpline(
      this: p_physicsObj,
      spline: nullptr,
      accelTime: 0,
      decelTime: nullptr,
      useSplineAngles: false,
      angularSpline: nullptr);
  value = (const idHandle<int,enum invalidThreadHandle_t,0> *)this->move_thread.value;
  this->lastCommand = MOVER_NONE;
  idThreadManager::ObjectMoveDone(this: &gameLocal->program.threadManager, threadHandle: value, obj: this);
  this->move_thread.value = 0;
  idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
}


// ========================================================================
// ?UpdateMoveSound@idMover@@IAAXW4moveStage_t@1@@Z
// EA  : 0x82C7E1D0
// RVA : 0x00C7E1D0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::UpdateMoveSound(idMover *this, idMover::moveStage_t stage)
{
  const idSoundShader *sndDecel; // r5

  this->move.currentStage = stage;
  if ( stage != ACCELERATION_STAGE )
  {
    if ( stage == DECELERATION_STAGE )
    {
      sndDecel = this->sndDecel;
      if ( sndDecel != nullptr )
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_BODY2,
          shader: sndDecel,
          soundShaderFlags: (soundShaderFlags_t)(this->soundFlags | 0x400),
          peerMask: 0xFFu);
      idEntity::FadeSound(
        this,
        channel: SND_CHANNEL_BODY,
        to: -60.0,
        over: (float)((float)(unsigned int)this->deceltime * (float)0.001),
        additive: (bool)sndDecel);
    }
    else if ( stage == FINISHED_STAGE )
    {
      idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
      idEntity::StopSound(this, channel: SND_CHANNEL_BODY2, peerMask: 0xFFu);
    }
  }
  else
  {
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_BODY2,
      shader: this->sndAccel,
      soundShaderFlags: (soundShaderFlags_t)(this->soundFlags | 0x400),
      peerMask: 0xFFu);
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_BODY,
      shader: this->sndMove,
      soundShaderFlags: (soundShaderFlags_t)this->soundFlags,
      peerMask: 0xFFu);
  }
}


// ========================================================================
// ?UpdateNavigationSpace@idMover@@IAAXXZ
// EA  : 0x82C7E2E8
// RVA : 0x00C7E2E8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::UpdateNavigationSpace(idMover *this)
{
  idNavigationSpace *p_navSpace; // r30
  idPhysics *Physics; // r3
  int v4; // r3
  float v5; // r7
  float v6; // r6
  idPhysics *v7; // r3
  int v8; // r3
  char *v9; // r10
  _DWORD *v10; // r11
  int i; // ctr
  idVec3 v12; // [sp+50h] [-50h] BYREF
  char v13; // [sp+5Ch] [-44h] BYREF
  idMat3 v14; // [sp+60h] [-40h] BYREF

  p_navSpace = &this->navigationSpace.navSpace;
  if ( idNavigationSpace::IsValid(this: (idNpLink *)&this->navigationSpace.navSpace) )
  {
    Physics = idEntity::GetPhysics(this);
    v4 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v5 = *(float *)(v4 + 4);
    v6 = *(float *)(v4 + 8);
    v12.x = *(float *)v4;
    v12.y = v5;
    v12.z = v6;
    v7 = idEntity::GetPhysics(this);
    v8 = (int)v7->GetAxis(this: v7, a2: 0);
    v9 = &v13;
    v10 = (_DWORD *)(v8 - 4);
    for ( i = 9; i != 0; --i )
    {
      ++v10;
      v9 += 4;
      *(_DWORD *)v9 = *v10;
    }
    idNavigationSpace::UpdateTransform(this: p_navSpace, origin: &v12, axis: &v14);
  }
}


// ========================================================================
// ?Event_ReachedPos@idMover@@AAA?AVeventVoid@@XZ
// EA  : 0x82C7E3B0
// RVA : 0x00C7E3B0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_ReachedPos(idMover *this, eventVoid *result)
{
  idPhysics_Parametric *v2; // r29
  const idVec3 *LocalOrigin; // r3
  float y; // r9
  float z; // r8
  unsigned int v8; // r11
  int v9; // r3
  __int64 v10; // r8
  int GameMs; // r3
  __int64 v12; // r8
  idMover *v13; // r3
  int v14; // r3
  __int64 v15; // r8
  const char *v16; // r30
  int v17; // r3
  _DWORD v18[16]; // [sp+50h] [-40h] BYREF

  v2 = (idPhysics_Parametric *)&result[800];
  LocalOrigin = idPhysics_Parametric::GetLocalOrigin(this: (idPhysics_Parametric *)&result[800]);
  y = LocalOrigin->y;
  z = LocalOrigin->z;
  v8 = *(_DWORD *)&result[2032];
  v18[0] = LODWORD(LocalOrigin->x);
  *(float *)&v18[1] = y;
  *(float *)&v18[2] = z;
  if ( v8 > 3 )
    return this;
  if ( v8 == 1 )
  {
    idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    HIDWORD(v12) = *(_DWORD *)&result[2044];
    LODWORD(v12) = v18;
    idPhysics_Parametric::SetLinearExtrapolation(
      this: v2,
      type: EXTRAPOLATION_LINEAR,
      currentTime: GameMs,
      duration: v12,
      base: (const idVec3 *)&result[2052],
      speed: &vec3_origin);
    *(_DWORD *)&result[2032] = ((_cntlzw(*(_DWORD *)&result[2048]) & 0x20) != 0) + 2;
    return this;
  }
  if ( v8 == 2 )
  {
    idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v14 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    HIDWORD(v15) = *(_DWORD *)&result[2048];
    LODWORD(v15) = v18;
    idPhysics_Parametric::SetLinearExtrapolation(
      this: v2,
      type: EXTRAPOLATION_DECELLINEAR,
      currentTime: v14,
      duration: v15,
      base: (const idVec3 *)&result[2052],
      speed: &vec3_origin);
    *(_DWORD *)&result[2032] = 3;
    return this;
  }
  if ( v8 != 0 )
  {
    if ( g_debugMover.valueInteger != 0 )
    {
      v16 = *(const char **)&result[16];
      v17 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLib::Printf(fmt: "%d: '%s' move done\n", v17, v16);
    }
    (*(void (__fastcall **)(eventVoid *))(*(_DWORD *)result + 632))(a1: result);
    return this;
  }
  idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v9 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  HIDWORD(v10) = *(_DWORD *)&result[2040];
  LODWORD(v10) = v18;
  idPhysics_Parametric::SetLinearExtrapolation(
    this: v2,
    type: EXTRAPOLATION_ACCELLINEAR,
    currentTime: v9,
    duration: v10,
    base: (const idVec3 *)&result[2052],
    speed: &vec3_origin);
  if ( *(int *)&result[2044] <= 0 )
  {
    v13 = this;
    if ( *(int *)&result[2048] <= 0 )
      *(_DWORD *)&result[2032] = 3;
    else
      *(_DWORD *)&result[2032] = 2;
  }
  else
  {
    *(_DWORD *)&result[2032] = 1;
    return this;
  }
  return v13;
}


// ========================================================================
// ?BeginMove@idMover@@MAAXPAVidThread@@@Z
// EA  : 0x82C7E600
// RVA : 0x00C7E600
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMover::BeginMove(idMover *this, idThread *thread)
{
  idMover::moveStage_t v3; // r29
  const idVec3 *LocalOrigin; // r3
  float z; // r9
  double x; // fp0
  float v7; // r8
  double y; // fp10
  idVec3 *p_move_delta; // r30
  double v10; // fp9
  double v11; // fp12
  char v12; // r11
  idPhysics_Parametric *Physics; // r3
  int v14; // r3
  int acceltime; // r10
  int move_time; // r9
  int deceltime; // r3
  int v18; // r8
  __int64 v19; // r9
  int v20; // r3
  int v21; // r7
  int v22; // r6
  double move_speed; // fp12
  int v24; // r11
  double v25; // fp0
  __int64 v26; // r7 OVERLAPPED
  int v27; // r3
  int v28; // r11
  int v29; // r8
  int v30; // r10
  signed int v31; // r9
  int v32; // r3
  __int64 v33; // r9
  double v34; // fp12
  double v35; // fp11
  double v36; // fp9
  idEventReceiver v37; // [sp+60h] [-40h] BYREF

  v3 = ACCELERATION_STAGE;
  this->move_thread.value = 0;
  this->lastCommand = MOVER_MOVING;
  LocalOrigin = idPhysics_Parametric::GetLocalOrigin(this: &this->physicsObj);
  z = LocalOrigin->z;
  x = this->dest_position.x;
  v7 = LocalOrigin->x;
  y = this->dest_position.y;
  p_move_delta = &this->move_delta;
  v10 = this->dest_position.z;
  v37.listenerList = (idList<idEventReceiver *,5> *)LODWORD(LocalOrigin->y);
  v11 = *(float *)&v37.listenerList;
  *(float *)&v37.listeningToList = z;
  *(float *)&v37.__vftable = v7;
  this->move_delta.x = (float)x - v7;
  this->move_delta.y = (float)y - (float)v11;
  this->move_delta.z = (float)v10 - z;
  if ( (float)((float)x - v7) != vec3_origin.x
    || this->move_delta.y != vec3_origin.y
    || (v12 = 1, this->move_delta.z != vec3_origin.z) )
  {
    v12 = 0;
  }
  if ( v12 != 0 )
  {
    this->DoneMoving(this);
  }
  else
  {
    this->lastOrigin.x = v7;
    this->lastOrigin.y = v11;
    this->lastOrigin.z = z;
    if ( idEntity::GetPhysics(this)->type == PHYSICS_PARAMETRIC )
    {
      Physics = (idPhysics_Parametric *)idEntity::GetPhysics(this);
      if ( idPhysics_Parametric::IsPusher(this: Physics) )
        idBreakableManager::ReactToMover(this: &gameLocal->breakableManager);
    }
    v14 = SnapTimeToPhysicsFrame(t: this->acceltime);
    acceltime = this->acceltime;
    move_time = this->move_time;
    this->acceltime = v14;
    v18 = move_time - acceltime + v14;
    deceltime = this->deceltime;
    this->move_time = v18;
    v20 = SnapTimeToPhysicsFrame(t: deceltime);
    v21 = this->move_time;
    v22 = this->deceltime;
    move_speed = this->move_speed;
    this->deceltime = v20;
    this->move_time = v21 - v22 + v20;
    if ( move_speed != 0.0 )
    {
      v24 = v20 + this->acceltime;
      LODWORD(v19) = v24;
      v25 = __fsqrts((float)((float)(p_move_delta->x * p_move_delta->x)
                           + (float)((float)(p_move_delta->y * p_move_delta->y)
                                   + (float)(p_move_delta->z * p_move_delta->z))));
      if ( (float)((float)((float)v19 * (float)move_speed) * (float)0.00050000002) < v25 )
        this->move_time = v24
                        - (int)(float)((float)((float)((float)v25
                                                     - (float)((float)((float)v19 * (float)move_speed)
                                                             * (float)0.00050000002))
                                             / (float)move_speed)
                                     * (float)-1000.0);
      else
        this->move_time = v24;
    }
    v27 = SnapTimeToPhysicsFrame(t: this->move_time);
    v28 = this->acceltime;
    v29 = v27;
    this->move_time = v27;
    if ( v28 == 0 )
    {
      v3 = DECELERATION_STAGE;
      if ( v27 > this->deceltime )
        v3 = LINEAR_STAGE;
    }
    v30 = this->deceltime;
    v31 = v30 + v28;
    if ( v30 + v28 > v27 )
    {
      __twllei(v31, 0);
      __twlgei(v31 & ~(__ROL4__(v27 * v28, 1) - 1), 0xFFFFFFFF);
      v32 = SnapTimeToPhysicsFrame(t: v27 * v28 / v31);
      v29 = this->move_time;
      v28 = v32;
      v30 = v29 - v32;
    }
    v33 = __PAIR64__(v28, v29);
    v34 = p_move_delta->x;
    v35 = this->move_delta.y;
    LODWORD(v26) = v30;
    *(_QWORD *)&v37.__vftable = *(__int64 *)((char *)&v26 - 4);
    v36 = this->move_delta.z;
    p_move_delta->x = (float)v34
                    * (float)((float)1000.0
                            / (float)-(float)((float)((float)((float)v26 + (float)*(__int64 *)((char *)&v26 - 4))
                                                    * (float)0.5)
                                            - (float)v33));
    this->move_delta.y = (float)((float)1000.0
                               / (float)-(float)((float)((float)((float)v26 + (float)*(__int64 *)((char *)&v26 - 4))
                                                       * (float)0.5)
                                               - (float)v33))
                       * (float)v35;
    this->move_delta.z = (float)((float)1000.0
                               / (float)-(float)((float)((float)((float)v26 + (float)*(__int64 *)((char *)&v26 - 4))
                                                       * (float)0.5)
                                               - (float)v33))
                       * (float)v36;
    this->move.stage = v3;
    this->move.acceleration = v28;
    this->move.deceleration = v30;
    this->move.movetime = this->move_time - v30 - v28;
    this->move.dir.x = p_move_delta->x;
    this->move.dir.y = this->move_delta.y;
    this->move.dir.z = this->move_delta.z;
    idEventReceiver::ProcessEvent(this: &v37, result: (idEventArg *)this, ev: &EV_ReachedPos);
  }
}


// ========================================================================
// ?Event_StopRotating@idMover@@AAA?AVeventVoid@@XZ
// EA  : 0x82C7E938
// RVA : 0x00C7E938
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_StopRotating(idMover *this, eventVoid *result)
{
  idPhysics_Parametric *v2; // r30
  const idAngles *LocalAngles; // r3
  idClientGame *v6; // r11
  int GameMs; // r3

  v2 = (idPhysics_Parametric *)&result[800];
  LocalAngles = idPhysics_Parametric::GetLocalAngles(this: (idPhysics_Parametric *)&result[800]);
  *(float *)&result[2108] = LocalAngles->pitch;
  *(float *)&result[2112] = LocalAngles->yaw;
  v6 = clientGame;
  *(float *)&result[2116] = LocalAngles->roll;
  GameMs = idGameTimeManager::GetGameMs(this: &v6->gameTimeManager, type: GAMETIME_SCALED);
  idPhysics_Parametric::SetAngularExtrapolation(
    this: v2,
    type: EXTRAPOLATION_NONE,
    currentTime: GameMs,
    duration: (unsigned int)&result[2108],
    base: &ang_zero,
    speed: &ang_zero);
  (*(void (__fastcall **)(eventVoid *))(*(_DWORD *)result + 636))(a1: result);
  return this;
}


// ========================================================================
// ?DoneRotating@idMover@@MAAXXZ
// EA  : 0x82C7E9D8
// RVA : 0x00C7E9D8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::DoneRotating(idMover *this)
{
  const idHandle<int,enum invalidThreadHandle_t,0> *value; // r4

  value = (const idHandle<int,enum invalidThreadHandle_t,0> *)this->rotate_thread.value;
  this->lastCommand = MOVER_NONE;
  idThreadManager::ObjectMoveDone(this: &gameLocal->program.threadManager, threadHandle: value, obj: this);
  this->rotate_thread.value = 0;
  idEntity::StopSound(this, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
}


// ========================================================================
// ?Event_ReachedAng@idMover@@AAA?AVeventVoid@@XZ
// EA  : 0x82C7EA40
// RVA : 0x00C7EA40
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_ReachedAng(idMover *this, idMover *result)
{
  idPhysics_Parametric *p_physicsObj; // r29
  const idAngles *LocalAngles; // r3
  idMover::moveStage_t stage; // r4
  float yaw; // r9
  float roll; // r8
  unsigned int v9; // r11
  int v10; // r3
  __int64 v11; // r8
  int v12; // r3
  extrapolation_t v13; // r4
  __int64 v14; // r8
  int GameMs; // r3
  __int64 v16; // r8
  idMover *v17; // r3
  BOOL stopRotation; // r11
  int v19; // r3
  int v20; // r3
  const char *data; // r29
  int v22; // r3
  _DWORD v23[20]; // [sp+50h] [-50h] BYREF

  p_physicsObj = &result->physicsObj;
  LocalAngles = idPhysics_Parametric::GetLocalAngles(this: &result->physicsObj);
  stage = result->rot.stage;
  yaw = LocalAngles->yaw;
  roll = LocalAngles->roll;
  v23[0] = LODWORD(LocalAngles->pitch);
  *(float *)&v23[1] = yaw;
  *(float *)&v23[2] = roll;
  idMover::UpdateRotationSound(this: result, stage);
  v9 = result->rot.stage;
  if ( v9 > 3 )
    return this;
  if ( v9 != 1 )
  {
    if ( v9 == 2 )
    {
      idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      HIDWORD(v16) = result->rot.deceleration;
      LODWORD(v16) = v23;
      idPhysics_Parametric::SetAngularExtrapolation(
        this: p_physicsObj,
        type: EXTRAPOLATION_DECELLINEAR,
        currentTime: GameMs,
        duration: v16,
        base: &result->rot.rot,
        speed: &ang_zero);
      result->rot.stage = FINISHED_STAGE;
      return this;
    }
    if ( v9 == 0 )
    {
      idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v10 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      HIDWORD(v11) = result->rot.acceleration;
      LODWORD(v11) = v23;
      idPhysics_Parametric::SetAngularExtrapolation(
        this: p_physicsObj,
        type: EXTRAPOLATION_ACCELLINEAR,
        currentTime: v10,
        duration: v11,
        base: &result->rot.rot,
        speed: &ang_zero);
      if ( result->rot.movetime <= 0 )
      {
        v17 = this;
        if ( result->rot.deceleration <= 0 )
          result->rot.stage = FINISHED_STAGE;
        else
          result->rot.stage = DECELERATION_STAGE;
      }
      else
      {
        result->rot.stage = LINEAR_STAGE;
        return this;
      }
      return v17;
    }
    stopRotation = result->stopRotation;
    result->lastCommand = MOVER_NONE;
    if ( stopRotation )
    {
      idAngles::Normalize360(this: &result->dest_angles);
      v19 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idPhysics_Parametric::SetAngularExtrapolation(
        this: p_physicsObj,
        type: EXTRAPOLATION_NONE,
        currentTime: v19,
        duration: (unsigned int)&result->dest_angles,
        base: &ang_zero,
        speed: &ang_zero);
      result->stopRotation = false;
    }
    else if ( idPhysics_Parametric::GetAngularExtrapolationType(this: p_physicsObj) == EXTRAPOLATION_ACCELLINEAR )
    {
      idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v20 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idPhysics_Parametric::SetAngularExtrapolation(
        this: p_physicsObj,
        type: EXTRAPOLATION_LINEAR|EXTRAPOLATION_NOSTOP,
        currentTime: v20,
        duration: (unsigned int)v23,
        base: &result->rot.rot,
        speed: &ang_zero);
    }
    if ( g_debugMover.valueInteger != 0 )
    {
      data = result->name.data;
      v22 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLib::Printf(fmt: "%d: '%s' rotation done\n", v22, data);
    }
    result->DoneRotating(this: result);
    return this;
  }
  if ( result->stopRotation || result->rot.deceleration != 0 )
  {
    idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v12 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v13 = EXTRAPOLATION_LINEAR;
  }
  else
  {
    idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v12 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v13 = EXTRAPOLATION_LINEAR|EXTRAPOLATION_NOSTOP;
  }
  HIDWORD(v14) = result->rot.movetime;
  LODWORD(v14) = v23;
  idPhysics_Parametric::SetAngularExtrapolation(
    this: p_physicsObj,
    type: v13,
    currentTime: v12,
    duration: v14,
    base: &result->rot.rot,
    speed: &ang_zero);
  result->rot.stage = ((_cntlzw(result->rot.deceleration) & 0x20) != 0) + 2;
  return this;
}


// ========================================================================
// ?BeginRotation@idMover@@MAAXPAVidThread@@_N@Z
// EA  : 0x82C7EDB0
// RVA : 0x00C7EDB0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMover::BeginRotation(idMover *this, idThread *thread, bool stopwhendone)
{
  int move_time; // r11
  const idAngles *LocalAngles; // r3
  float yaw; // r8
  double pitch; // fp0
  float v9; // r9
  double v10; // fp13
  idAngles *p_angle_delta; // r30
  double roll; // fp12
  double v13; // fp11
  char v14; // r11
  int GameMs; // r3
  int v16; // r3
  int v17; // r11
  int v18; // r10
  int deceltime; // r3
  int v20; // r3
  int v21; // r8
  int v22; // r11
  _BYTE v23[12]; // r8 OVERLAPPED
  int v24; // r3
  int acceltime; // r11
  idMover::moveStage_t v26; // r29
  int v27; // r10
  signed int v28; // r9
  int v29; // r3
  int v30; // r9
  double v31; // fp12
  double v32; // fp11
  __int64 v33; // fp9
  double v34; // fp8
  double v35; // fp9
  bool v36; // r9
  int v37; // r8
  idEventReceiver v38; // [sp+50h] [-60h] BYREF

  move_time = this->move_time;
  this->lastCommand = MOVER_ROTATING;
  this->rotate_thread.value = 0;
  if ( move_time == 0 )
    this->move_time = 1;
  LocalAngles = idPhysics_Parametric::GetLocalAngles(this: &this->physicsObj);
  yaw = LocalAngles->yaw;
  pitch = this->dest_angles.pitch;
  v9 = LocalAngles->pitch;
  v10 = this->dest_angles.yaw;
  p_angle_delta = &this->angle_delta;
  roll = this->dest_angles.roll;
  v38.listeningToList = (idList<idEventReceiver *,5> *)LODWORD(LocalAngles->roll);
  v13 = *(float *)&v38.listeningToList;
  *(float *)&v38.listenerList = yaw;
  *(float *)&v38.__vftable = v9;
  this->angle_delta.pitch = (float)pitch - v9;
  this->angle_delta.yaw = (float)v10 - yaw;
  this->angle_delta.roll = (float)roll - (float)v13;
  if ( ang_zero.pitch != (float)((float)pitch - v9)
    || ang_zero.yaw != this->angle_delta.yaw
    || (v14 = 1, ang_zero.roll != this->angle_delta.roll) )
  {
    v14 = 0;
  }
  if ( v14 != 0 )
  {
    idAngles::Normalize360(this: &this->dest_angles);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idPhysics_Parametric::SetAngularExtrapolation(
      this: &this->physicsObj,
      type: EXTRAPOLATION_NONE,
      currentTime: GameMs,
      duration: (unsigned int)&this->dest_angles,
      base: &ang_zero,
      speed: &ang_zero);
    this->stopRotation = false;
    this->DoneRotating(this);
  }
  else
  {
    v16 = SnapTimeToPhysicsFrame(t: this->acceltime);
    v17 = this->move_time;
    v18 = v16 - this->acceltime;
    this->acceltime = v16;
    deceltime = this->deceltime;
    this->move_time = v18 + v17;
    v20 = SnapTimeToPhysicsFrame(t: deceltime);
    v21 = this->deceltime;
    v22 = this->move_time;
    this->deceltime = v20;
    this->move_time = v20 - v21 + v22;
    v24 = SnapTimeToPhysicsFrame(t: v20 - v21 + v22);
    acceltime = this->acceltime;
    this->move_time = v24;
    if ( acceltime != 0 )
    {
      v26 = ACCELERATION_STAGE;
    }
    else
    {
      v26 = DECELERATION_STAGE;
      if ( v24 > this->deceltime )
        v26 = LINEAR_STAGE;
    }
    v27 = this->deceltime;
    *(_DWORD *)&v23[8] = v24;
    v28 = v27 + acceltime;
    if ( v27 + acceltime > v24 )
    {
      __twllei(v28, 0);
      __twlgei(v28 & ~(__ROL4__(v24 * acceltime, 1) - 1), 0xFFFFFFFF);
      v29 = SnapTimeToPhysicsFrame(t: v24 * acceltime / v28);
      *(_DWORD *)&v23[8] = this->move_time;
      acceltime = v29;
      v27 = *(_DWORD *)&v23[8] - v29;
    }
    v30 = acceltime;
    v31 = p_angle_delta->pitch;
    v32 = this->angle_delta.yaw;
    v33 = *(_QWORD *)&v23[4];
    *(_DWORD *)&v23[4] = v27;
    *(_QWORD *)&v38.__vftable = *(_QWORD *)v23;
    v34 = this->angle_delta.roll;
    v35 = (float)-(float)((float)((float)((float)*(__int64 *)v23 + (float)*(__int64 *)&v23[-4]) * (float)0.5)
                        - (float)v33);
    p_angle_delta->pitch = (float)v31 * (float)((float)1000.0 / (float)v35);
    this->angle_delta.yaw = (float)((float)1000.0 / (float)v35) * (float)v32;
    this->angle_delta.roll = (float)((float)1000.0 / (float)v35) * (float)v34;
    if ( stopwhendone || (v36 = false, v27 != 0) )
      v36 = true;
    v37 = this->move_time;
    this->rot.acceleration = acceltime;
    this->stopRotation = v36;
    this->rot.currentStage = v26;
    this->rot.stage = v26;
    this->rot.deceleration = v27;
    this->rot.movetime = v37 - v27 - acceltime;
    this->rot.rot.pitch = p_angle_delta->pitch;
    this->rot.rot.yaw = this->angle_delta.yaw;
    this->rot.rot.roll = this->angle_delta.roll;
    idEventReceiver::ProcessEvent(this: &v38, result: (idEventArg *)this, ev: &EV_ReachedAng);
  }
}


// ========================================================================
// ?Event_TeamBlocked@idMover@@AAA?AVeventVoid@@PAVidEntity@@0@Z
// EA  : 0x82C7F098
// RVA : 0x00C7F098
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_TeamBlocked(
        idMover *this,
        eventVoid *result,
        idEntity *blockedEntity,
        idEntity *blockingEntity)
{
  const char *v5; // r30
  char *data; // r29
  char *v7; // r28
  int GameMs; // r3

  if ( g_debugMover.valueInteger != 0 )
  {
    v5 = *(const char **)&result[16];
    data = blockingEntity->name.data;
    v7 = blockedEntity->name.data;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "%d: '%s' stopped due to team member '%s' blocked by '%s'\n", GameMs, v5, v7, data);
  }
  return this;
}


// ========================================================================
// ?Event_PartBlocked@idMover@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82C7F110
// RVA : 0x00C7F110
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_PartBlocked(idMover *this, idEntity *result, idActor *blockingEntity)
{
  idActor *v8; // r3
  int v9; // r3
  idActor *v10; // r3
  int v11; // r3
  int v12; // r3
  const idSoundShader *x_low; // r5
  char *data; // r30
  const char *v15; // r31
  int GameMs; // r3

  if ( LODWORD(result[2].defaultPhysicsObj.current.worldOrigin.z) != 0 )
  {
    _FP6 = (float)((float)((float)(result[2].dormancy.distance * result[2].dormancy.distance)
                         + (float)((float)(*(float *)&result[2].dormancy.becomeDormantTime
                                         * *(float *)&result[2].dormancy.becomeDormantTime)
                                 + (float)(*(float *)&result[2].dormancy.lastTimeInPlayerPVS
                                         * *(float *)&result[2].dormancy.lastTimeInPlayerPVS)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f7, f13 }
    if ( blockingEntity != nullptr )
    {
      if ( (unsigned __int8)idActor::IsTypeOf(c: blockingEntity) != 0 )
      {
        v8 = idActor::CastTo(c: blockingEntity);
        if ( v8 != nullptr )
        {
          v9 = (int)v8->GetHealthComponent(this: v8);
          if ( v9 != 0 && (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v9 + 88))(a1: v9) == 0 )
            idEntity::StartSoundShader(
              this: result,
              channel: SND_CHANNEL_ANY,
              shader: (const idSoundShader *)LODWORD(result[2].defaultPhysicsObj.current.worldAxis.mat[0].x),
              soundShaderFlags: (soundShaderFlags_t)0,
              peerMask: 0xFFu);
        }
      }
      if ( ((double (__fastcall *)(idActor *, idEntity *, idEntity *, _DWORD, double))blockingEntity->Damage)(
             a1: blockingEntity,
             a2: result,
             a3: result,
             a4: LODWORD(result[2].defaultPhysicsObj.current.worldOrigin.z),
             a5: 1.0) > 0.0
        && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) > SLODWORD(result[2].defaultPhysicsObj.current.worldOrigin.y)
        && (unsigned __int8)idActor::IsTypeOf(c: blockingEntity) != 0 )
      {
        v10 = idActor::CastTo(c: blockingEntity);
        if ( v10 != nullptr )
        {
          v11 = (int)v10->GetHealthComponent(this: v10);
          if ( v11 != 0 && (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v11 + 88))(a1: v11) == 0 )
          {
            v12 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
            x_low = (const idSoundShader *)LODWORD(result[2].defaultPhysicsObj.current.worldAxis.mat[0].x);
            LODWORD(result[2].defaultPhysicsObj.current.worldOrigin.y) = v12 + 500;
            idEntity::StartSoundShader(
              this: result,
              channel: SND_CHANNEL_ANY,
              shader: x_low,
              soundShaderFlags: (soundShaderFlags_t)0,
              peerMask: 0xFFu);
          }
        }
      }
    }
  }
  if ( g_debugMover.valueInteger != 0 )
  {
    if ( blockingEntity != nullptr )
      data = blockingEntity->name.data;
    else
      data = "<null>";
    v15 = result->name.data;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "%d: '%s' blocked by '%s'\n", GameMs, v15, data);
  }
  return this;
}


// ========================================================================
// ?Event_RestConstraint@idMover@@AAA?AVeventVoid@@XZ
// EA  : 0x82C7F3A8
// RVA : 0x00C7F3A8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_RestConstraint(idMover *this, idEntity *result)
{
  idPhysics *Physics; // r3

  if ( *((_BYTE *)&result[2].physics + 4) != 0 )
  {
    Physics = idEntity::GetPhysics(this: result);
    Physics->SetContents(this: Physics, a2: HIDWORD(result[2].touchTriggersQuery.index), a3: -1);
    *((_BYTE *)&result[2].physics + 4) = 0;
  }
  return this;
}


// ========================================================================
// ?Event_Speed@idMover@@AAA?AVeventVoid@@M@Z
// EA  : 0x82C7F418
// RVA : 0x00C7F418
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_Speed(idMover *this, eventVoid *result, double speed)
{
  double v3; // fp31

  v3 = speed;
  if ( speed <= 0.0 )
  {
    v3 = 0.001;
    idGameLocal::MapError(this: gameLocal, fmt: "Cannot set speed less than or equal to 0.");
  }
  *(float *)&result[2156] = v3;
  *(_DWORD *)&result[2160] = 0;
  return this;
}


// ========================================================================
// ?Event_Time@idMover@@AAA?AVeventVoid@@M@Z
// EA  : 0x82C7F498
// RVA : 0x00C7F498
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_Time(idMover *this, eventVoid *result, double time)
{
  double v3; // fp31

  v3 = time;
  if ( time <= 0.0 )
  {
    v3 = 0.001;
    idGameLocal::MapError(this: gameLocal, fmt: "Cannot set time less than or equal to 0.");
  }
  *(float *)&result[2156] = 0.0;
  *(_DWORD *)&result[2160] = (int)(float)((float)1000.0 * (float)v3);
  return this;
}


// ========================================================================
// ?Event_AccelTime@idMover@@AAA?AVeventVoid@@M@Z
// EA  : 0x82C7F530
// RVA : 0x00C7F530
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_AccelTime(idMover *this, eventVoid *result, double time)
{
  double v3; // fp31

  v3 = time;
  if ( time < 0.0 )
  {
    v3 = 0.001;
    idGameLocal::MapError(this: gameLocal, fmt: "Cannot set acceleration time less than 0.");
  }
  *(_DWORD *)&result[2168] = (int)(float)((float)1000.0 * (float)v3);
  return this;
}


// ========================================================================
// ?Event_DecelTime@idMover@@AAA?AVeventVoid@@M@Z
// EA  : 0x82C7F5B8
// RVA : 0x00C7F5B8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_DecelTime(idMover *this, eventVoid *result, double time)
{
  double v3; // fp31

  v3 = time;
  if ( time < 0.0 )
  {
    v3 = 0.001;
    idGameLocal::MapError(this: gameLocal, fmt: "Cannot set deceleration time less than 0.");
  }
  *(_DWORD *)&result[2164] = (int)(float)((float)1000.0 * (float)v3);
  return this;
}


// ========================================================================
// ?Event_SetParmsForTime@idMover@@AAA?AVeventVoid@@MMM@Z
// EA  : 0x82C7F640
// RVA : 0x00C7F640
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_SetParmsForTime(
        idMover *this,
        eventVoid *result,
        double time,
        double in_acceltime,
        double in_deceltime)
{
  double v5; // fp28

  v5 = time;
  if ( time <= 0.0 )
  {
    v5 = 0.001;
    idGameLocal::MapError(this: gameLocal, fmt: "Cannot set time less than or equal to 0.");
  }
  if ( in_acceltime < 0.0 )
  {
    in_acceltime = 0.0;
    idGameLocal::MapError(this: gameLocal, fmt: "Cannot set acceleration time less than 0.");
  }
  if ( in_deceltime < 0.0 )
  {
    in_deceltime = 0.0;
    idGameLocal::MapError(this: gameLocal, fmt: "Cannot set deceleration time less than 0.");
  }
  *(float *)&result[2156] = 0.0;
  *(_DWORD *)&result[2160] = (int)(float)((float)1000.0 * (float)v5);
  *(_DWORD *)&result[2168] = (int)(float)((float)1000.0 * (float)in_acceltime);
  *(_DWORD *)&result[2164] = (int)(float)((float)1000.0 * (float)in_deceltime);
  return this;
}


// ========================================================================
// ?Event_SetParmsForSpeed@idMover@@AAA?AVeventVoid@@MMM@Z
// EA  : 0x82C7F728
// RVA : 0x00C7F728
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_SetParmsForSpeed(
        idMover *this,
        eventVoid *result,
        double speed,
        double in_acceltime,
        double in_deceltime)
{
  double v5; // fp28

  v5 = speed;
  if ( speed <= 0.0 )
  {
    v5 = 0.001;
    idGameLocal::MapError(this: gameLocal, fmt: "Cannot set speed less than or equal to 0.");
  }
  if ( in_acceltime < 0.0 )
  {
    in_acceltime = 0.0;
    idGameLocal::MapError(this: gameLocal, fmt: "Cannot set acceleration time less than 0.");
  }
  if ( in_deceltime < 0.0 )
  {
    in_deceltime = 0.0;
    idGameLocal::MapError(this: gameLocal, fmt: "Cannot set deceleration time less than 0.");
  }
  *(float *)&result[2156] = v5;
  *(_DWORD *)&result[2160] = 0;
  *(_DWORD *)&result[2168] = (int)(float)((float)1000.0 * (float)in_acceltime);
  *(_DWORD *)&result[2164] = (int)(float)((float)1000.0 * (float)in_deceltime);
  return this;
}


// ========================================================================
// ?Event_MoveTo@idMover@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82C7F800
// RVA : 0x00C7F800
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_MoveTo(idMover *this, idEntity *result, idEntity *ent)
{
  idPhysics *Physics; // r3
  const idVec3 *v6; // r3
  float *LocalCoordinates; // r3
  idGameLocal *v8; // r11
  idThread *currentThread; // r4
  char v11; // [sp+50h] [-30h] BYREF

  if ( ent != nullptr )
  {
    Physics = idEntity::GetPhysics(this: ent);
    v6 = Physics->GetOrigin(this: Physics, a2: 0);
    LocalCoordinates = (float *)idEntity::GetLocalCoordinates(this: (idEntity *)&v11, result, vec: v6);
    result[2].defaultPhysicsObj.callbacks = *(idPhysicsCallbacks **)LocalCoordinates;
    v8 = gameLocal;
    *(float *)&result[2].defaultPhysicsObj.residencyQuery.index = LocalCoordinates[1];
    currentThread = v8->program.threadManager.currentThread;
    *((float *)&result[2].defaultPhysicsObj.residencyQuery.index + 1) = LocalCoordinates[2];
    result->__vftable[1].RespondsTo(this: result, a2: (const idEventDef *)currentThread);
  }
  else
  {
    idLib::Warning(fmt: "Entity not found");
  }
  return this;
}


// ========================================================================
// ?Event_MoveToPos@idMover@@AAA?AVeventVoid@@ABVidVec3@@@Z
// EA  : 0x82C7F8C0
// RVA : 0x00C7F8C0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_MoveToPos(idMover *this, idEntity *result, const idVec3 *pos)
{
  float *LocalCoordinates; // r3
  char v7; // [sp+50h] [-30h] BYREF

  LocalCoordinates = (float *)idEntity::GetLocalCoordinates(this: (idEntity *)&v7, result, vec: pos);
  result[2].defaultPhysicsObj.callbacks = *(idPhysicsCallbacks **)LocalCoordinates;
  *(float *)&result[2].defaultPhysicsObj.residencyQuery.index = LocalCoordinates[1];
  *((float *)&result[2].defaultPhysicsObj.residencyQuery.index + 1) = LocalCoordinates[2];
  result->__vftable[1].RespondsTo(this: result, a2: nullptr);
  return this;
}


// ========================================================================
// ?Event_Move@idMover@@AAA?AVeventVoid@@MM@Z
// EA  : 0x82C7F930
// RVA : 0x00C7F930
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_Move(idMover *this, idMover *result, double angle, double distance)
{
  idVec3 *v8; // r4
  double v9; // fp7
  double v10; // fp6
  idGameLocal *v11; // r11
  idVec3 v13; // [sp+60h] [-40h] BYREF
  const idVec3 v14; // 0:^50.12

  v14 = *idPhysics_Parametric::GetLocalOrigin(this: &result->physicsObj);
  idMover::VectorForDir(this: result, angle, vec: v8, a4: &v13);
  v9 = (float)(v13.y * (float)distance);
  v10 = (float)(v13.z * (float)distance);
  v11 = gameLocal;
  result->dest_position.x = (float)(v13.x * (float)distance) + v14.x;
  result->dest_position.y = v14.y + (float)v9;
  result->dest_position.z = v14.z + (float)v10;
  result->BeginMove(this: result, a2: v11->program.threadManager.currentThread);
  return this;
}


// ========================================================================
// ?Event_MoveAbsolute@idMover@@AAA?AVeventVoid@@MM@Z
// EA  : 0x82C7FA18
// RVA : 0x00C7FA18
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_MoveAbsolute(idMover *this, idMover *result, double angle, double distance)
{
  char *v7; // r10
  eventVoid *p_z; // r11
  int v9; // ctr
  idThread *currentThread; // r4
  double v11; // fp1
  double v12; // fp0
  float x; // [sp+50h] [-70h]
  float y; // [sp+54h] [-6Ch]
  float z; // [sp+58h] [-68h]
  idVec3 v17; // [sp+60h] [-60h] BYREF
  char v18; // [sp+6Ch] [-54h] BYREF
  float v19; // [sp+70h] [-50h]
  float v20; // [sp+74h] [-4Ch]
  float v21; // [sp+78h] [-48h]
  float v22; // [sp+7Ch] [-44h]
  float v23; // [sp+80h] [-40h]
  float v24; // [sp+84h] [-3Ch]
  float v25; // [sp+88h] [-38h]
  float v26; // [sp+8Ch] [-34h]
  float v27; // [sp+90h] [-30h]

  idMover::VectorForDir(this: result, angle, vec: (idVec3 *)result, a4: &v17);
  v7 = &v18;
  p_z = (eventVoid *)&result->spawnPosition.z;
  v9 = 9;
  y = result->spawnPosition.y;
  z = result->spawnPosition.z;
  x = result->spawnPosition.x;
  do
  {
    p_z += 4;
    v7 += 4;
    *(_DWORD *)v7 = *(_DWORD *)p_z;
    --v9;
  }
  while ( v9 != 0 );
  currentThread = gameLocal->program.threadManager.currentThread;
  v11 = (float)((float)(v20 * (float)(v17.x * (float)distance))
              + (float)((float)(v26 * (float)(v17.z * (float)distance)) + (float)(v23 * (float)(v17.y * (float)distance))));
  v12 = (float)((float)(v21 * (float)(v17.x * (float)distance))
              + (float)((float)(v27 * (float)(v17.z * (float)distance)) + (float)(v24 * (float)(v17.y * (float)distance))));
  result->dest_position.x = (float)((float)((float)(v17.x * (float)distance) * v19)
                                  + (float)((float)(v25 * (float)(v17.z * (float)distance))
                                          + (float)(v22 * (float)(v17.y * (float)distance))))
                          + x;
  result->dest_position.y = y + (float)v11;
  result->dest_position.z = z + (float)v12;
  result->BeginMove(this: result, a2: currentThread);
  return this;
}


// ========================================================================
// ?Event_AccelTo@idMover@@AAA?AVeventVoid@@MM@Z
// EA  : 0x82C7FB48
// RVA : 0x00C7FB48
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_AccelTo(idMover *this, idEntity *result, double speed, double time)
{
  double v5; // fp29
  double v10; // fp2
  double v11; // fp3
  double v12; // fp2
  double v13; // fp31
  int v14; // r30
  const idVec3 *LocalOrigin; // r3
  float x; // r8
  const idSoundShader *x_low; // r5
  float y; // r10
  float z; // r9
  int GameMs; // r3
  __int64 v21; // r8
  float v23; // [sp+58h] [-98h] BYREF
  float v24; // [sp+5Ch] [-94h]
  float v25; // [sp+60h] [-90h]
  idVec3 v26; // [sp+68h] [-88h] BYREF
  idVec3 v27; // [sp+78h] [-78h] BYREF
  _DWORD v28[14]; // [sp+88h] [-68h] BYREF

  v5 = time;
  if ( time < 0.0 )
  {
    v5 = 0.001;
    idGameLocal::MapError(this: gameLocal, fmt: "idMover::Event_AccelTo: cannot set acceleration time less than 0.");
  }
  ((void (__fastcall *)(float *, idEntity *, _DWORD))result[1].SetModel)(a1: &v23, a2: &result[1], a3: 0);
  _FP5 = (float)((float)((float)(v23 * v23) + (float)((float)(v25 * v25) + (float)(v24 * v24)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f12 }
  v10 = __frsqrte(_FP3);
  v11 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)(v23 * v23) + (float)((float)(v25 * v25) + (float)(v24 * v24)))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10)
                                              * (float)((float)((float)(v23 * v23)
                                                              + (float)((float)(v25 * v25) + (float)(v24 * v24)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v10
                                                                              * (float)((float)((float)(v23 * v23)
                                                                                              + (float)((float)(v25 * v25) + (float)(v24 * v24)))
                                                                                      * (float)0.5))
                                                                      * (float)v10)
                                                              - (float)1.5)
                                              * (float)v10))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v10
                                                      * (float)((float)((float)(v23 * v23)
                                                                      + (float)((float)(v25 * v25) + (float)(v24 * v24)))
                                                              * (float)0.5))
                                              * (float)v10)
                                      - (float)1.5)
                      * (float)v10));
  v12 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                              * (float)((float)((float)(v23 * v23) + (float)((float)(v25 * v25) + (float)(v24 * v24))) * (float)0.5))
                                                                                      * (float)v10)
                                                                              - (float)1.5)
                                                              * (float)v10)
                                                      * (float)((float)((float)(v23 * v23)
                                                                      + (float)((float)(v25 * v25) + (float)(v24 * v24)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)(v23 * v23) + (float)((float)(v25 * v25) + (float)(v24 * v24)))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v10
                                                              * (float)((float)((float)(v23 * v23)
                                                                              + (float)((float)(v25 * v25)
                                                                                      + (float)(v24 * v24)))
                                                                      * (float)0.5))
                                                      * (float)v10)
                                              - (float)1.5)
                              * (float)v10))
              * (float)((float)((float)(v23 * v23) + (float)((float)(v25 * v25) + (float)(v24 * v24))) * (float)0.5));
  v13 = (float)((float)((float)-(float)((float)((float)v12 * (float)v11) - (float)1.5) * (float)v11)
              * (float)((float)(v23 * v23) + (float)((float)(v25 * v25) + (float)(v24 * v24))));
  v23 = v23 * (float)((float)-(float)((float)((float)v12 * (float)v11) - (float)1.5) * (float)v11);
  v24 = v24 * (float)((float)-(float)((float)((float)v12 * (float)v11) - (float)1.5) * (float)v11);
  v25 = v25 * (float)((float)-(float)((float)((float)v12 * (float)v11) - (float)1.5) * (float)v11);
  if ( v13 == 0.0 )
  {
    v13 = 0.001;
    idGameLocal::MapError(this: gameLocal, fmt: "idMover::Event_AccelTo: not moving.");
  }
  if ( v13 < speed )
  {
    v14 = SnapTimeToPhysicsFrame(t: (int)(float)((float)1000.0 * (float)v5));
    LODWORD(result[2].defaultPhysicsObj.current.worldOrigin.x) = 2;
    LocalOrigin = idPhysics_Parametric::GetLocalOrigin(this: (idPhysics_Parametric *)&result[1]);
    x = LocalOrigin->x;
    x_low = (const idSoundShader *)LODWORD(result[2].defaultPhysicsObj.current.worldAxis.mat[1].x);
    y = LocalOrigin->y;
    z = LocalOrigin->z;
    result[2].bindInfo.bindTag.rot.y = 0.0;
    result[2].bindInfo.bindTag.rot.z = 0.0;
    LODWORD(result[2].bindInfo.bindTag.rot.w) = v14;
    *(_DWORD *)&result[2].bindInfo.bindTag.parentJoint.value = 0;
    result[2].dormancy.delay = 0.0;
    *(float *)v28 = x;
    *(float *)&v28[1] = y;
    *(float *)&v28[2] = z;
    idEntity::StartSoundShader(
      this: result,
      channel: SND_CHANNEL_BODY2,
      shader: x_low,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    idEntity::StartSoundShader(
      this: result,
      channel: SND_CHANNEL_BODY,
      shader: (const idSoundShader *)LODWORD(result[2].defaultPhysicsObj.current.worldAxis.mat[1].z),
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    v26.x = v23 * (float)v13;
    v26.y = v24 * (float)v13;
    v26.z = v25 * (float)v13;
    v27.x = (float)((float)speed - (float)v13) * v23;
    v27.y = v24 * (float)((float)speed - (float)v13);
    v27.z = v25 * (float)((float)speed - (float)v13);
    idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    *(float *)&v21 = result[2].bindInfo.bindTag.rot.w;
    LODWORD(v21) = v28;
    idPhysics_Parametric::SetLinearExtrapolation(
      this: (idPhysics_Parametric *)&result[1],
      type: EXTRAPOLATION_ACCELLINEAR,
      currentTime: GameMs,
      duration: v21,
      base: &v27,
      speed: &v26);
  }
  return this;
}


// ========================================================================
// ?Event_DecelTo@idMover@@AAA?AVeventVoid@@MM@Z
// EA  : 0x82C7FDA0
// RVA : 0x00C7FDA0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_DecelTo(idMover *this, idEntity *result, double speed, double time)
{
  double v5; // fp28
  double v10; // fp2
  double v11; // fp3
  double v12; // fp2
  double v13; // fp31
  int v14; // r27
  const idVec3 *LocalOrigin; // r3
  float x; // r9
  const idSoundShader *y_low; // r5
  float y; // r8
  float z; // r10
  int GameMs; // r3
  __int64 v21; // r8
  float v23; // [sp+58h] [-98h] BYREF
  float v24; // [sp+5Ch] [-94h]
  float v25; // [sp+60h] [-90h]
  idVec3 v26; // [sp+68h] [-88h] BYREF
  idVec3 v27; // [sp+78h] [-78h] BYREF
  _DWORD v28[14]; // [sp+88h] [-68h] BYREF

  v5 = time;
  if ( time < 0.0 )
  {
    v5 = 0.001;
    idGameLocal::MapError(this: gameLocal, fmt: "idMover::Event_DecelTo: cannot set deceleration time less than 0.");
  }
  ((void (__fastcall *)(float *, idEntity *, _DWORD))result[1].SetModel)(a1: &v23, a2: &result[1], a3: 0);
  _FP5 = (float)((float)((float)(v23 * v23) + (float)((float)(v25 * v25) + (float)(v24 * v24)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f12 }
  v10 = __frsqrte(_FP3);
  v11 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)(v23 * v23) + (float)((float)(v25 * v25) + (float)(v24 * v24)))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10)
                                              * (float)((float)((float)(v23 * v23)
                                                              + (float)((float)(v25 * v25) + (float)(v24 * v24)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v10
                                                                              * (float)((float)((float)(v23 * v23)
                                                                                              + (float)((float)(v25 * v25) + (float)(v24 * v24)))
                                                                                      * (float)0.5))
                                                                      * (float)v10)
                                                              - (float)1.5)
                                              * (float)v10))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v10
                                                      * (float)((float)((float)(v23 * v23)
                                                                      + (float)((float)(v25 * v25) + (float)(v24 * v24)))
                                                              * (float)0.5))
                                              * (float)v10)
                                      - (float)1.5)
                      * (float)v10));
  v12 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                              * (float)((float)((float)(v23 * v23) + (float)((float)(v25 * v25) + (float)(v24 * v24))) * (float)0.5))
                                                                                      * (float)v10)
                                                                              - (float)1.5)
                                                              * (float)v10)
                                                      * (float)((float)((float)(v23 * v23)
                                                                      + (float)((float)(v25 * v25) + (float)(v24 * v24)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)(v23 * v23) + (float)((float)(v25 * v25) + (float)(v24 * v24)))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v10
                                                              * (float)((float)((float)(v23 * v23)
                                                                              + (float)((float)(v25 * v25)
                                                                                      + (float)(v24 * v24)))
                                                                      * (float)0.5))
                                                      * (float)v10)
                                              - (float)1.5)
                              * (float)v10))
              * (float)((float)((float)(v23 * v23) + (float)((float)(v25 * v25) + (float)(v24 * v24))) * (float)0.5));
  v13 = (float)((float)((float)-(float)((float)((float)v12 * (float)v11) - (float)1.5) * (float)v11)
              * (float)((float)(v23 * v23) + (float)((float)(v25 * v25) + (float)(v24 * v24))));
  v23 = v23 * (float)((float)-(float)((float)((float)v12 * (float)v11) - (float)1.5) * (float)v11);
  v24 = v24 * (float)((float)-(float)((float)((float)v12 * (float)v11) - (float)1.5) * (float)v11);
  v25 = v25 * (float)((float)-(float)((float)((float)v12 * (float)v11) - (float)1.5) * (float)v11);
  if ( v13 == 0.0 )
  {
    v13 = 0.001;
    idGameLocal::MapError(this: gameLocal, fmt: "idMover::Event_DecelTo: not moving.");
  }
  if ( v13 > speed )
  {
    v14 = SnapTimeToPhysicsFrame(t: (int)(float)((float)1000.0 * (float)v5));
    LODWORD(result[2].defaultPhysicsObj.current.worldOrigin.x) = 2;
    LocalOrigin = idPhysics_Parametric::GetLocalOrigin(this: (idPhysics_Parametric *)&result[1]);
    x = LocalOrigin->x;
    y_low = (const idSoundShader *)LODWORD(result[2].defaultPhysicsObj.current.worldAxis.mat[1].y);
    y = LocalOrigin->y;
    z = LocalOrigin->z;
    LODWORD(result[2].bindInfo.bindTag.rot.y) = 2;
    LODWORD(result[2].bindInfo.bindTag.rot.z) = 2;
    result[2].bindInfo.bindTag.rot.w = 0.0;
    *(_DWORD *)&result[2].bindInfo.bindTag.parentJoint.value = 0;
    LODWORD(result[2].dormancy.delay) = v14;
    *(float *)v28 = x;
    *(float *)&v28[1] = y;
    *(float *)&v28[2] = z;
    idEntity::StartSoundShader(
      this: result,
      channel: SND_CHANNEL_BODY2,
      shader: y_low,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    idEntity::StartSoundShader(
      this: result,
      channel: SND_CHANNEL_BODY,
      shader: (const idSoundShader *)LODWORD(result[2].defaultPhysicsObj.current.worldAxis.mat[1].z),
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    v26.x = v23 * (float)speed;
    v26.y = v24 * (float)speed;
    v26.z = v25 * (float)speed;
    v27.x = (float)((float)v13 - (float)speed) * v23;
    v27.y = v24 * (float)((float)v13 - (float)speed);
    v27.z = v25 * (float)((float)v13 - (float)speed);
    idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    *(float *)&v21 = result[2].dormancy.delay;
    LODWORD(v21) = v28;
    idPhysics_Parametric::SetLinearExtrapolation(
      this: (idPhysics_Parametric *)&result[1],
      type: EXTRAPOLATION_DECELLINEAR,
      currentTime: GameMs,
      duration: v21,
      base: &v27,
      speed: &v26);
  }
  return this;
}


// ========================================================================
// ?Event_RotateDownTo@idMover@@AAA?AVeventVoid@@HM@Z
// EA  : 0x82C7FFF8
// RVA : 0x00C7FFF8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_RotateDownTo(idMover *this, eventVoid *result, unsigned int axis, double angle)
{
  unsigned int v7; // r31
  const idAngles *LocalAngles; // r3
  float yaw; // r7
  float roll; // r6
  double v11; // fp13
  float *v12; // r11
  _DWORD v14[4]; // [sp+50h] [-40h] BYREF

  v7 = axis;
  if ( axis > 2 )
  {
    v7 = 0;
    idGameLocal::MapError(this: gameLocal, fmt: "Invalid axis");
  }
  LocalAngles = idPhysics_Parametric::GetLocalAngles(this: (idPhysics_Parametric *)&result[800]);
  yaw = LocalAngles->yaw;
  roll = LocalAngles->roll;
  v14[0] = LODWORD(LocalAngles->pitch);
  *(float *)&v14[1] = yaw;
  *(float *)&v14[2] = roll;
  v11 = *(float *)&v14[v7];
  v12 = (float *)&result[4 * v7 + 2108];
  if ( (float)((float)angle + (float)360.0) >= v11 )
    *v12 = angle;
  else
    *v12 = (float)angle + (float)360.0;
  if ( *v12 > v11 )
    *v12 = *v12 - (float)360.0;
  (*(void (__fastcall **)(eventVoid *, idThread *, int))(*(_DWORD *)result + 644))(
    a1: result,
    a2: gameLocal->program.threadManager.currentThread,
    a3: 1);
  return this;
}


// ========================================================================
// ?Event_RotateUpTo@idMover@@AAA?AVeventVoid@@HM@Z
// EA  : 0x82C800E8
// RVA : 0x00C800E8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_RotateUpTo(idMover *this, eventVoid *result, unsigned int axis, double angle)
{
  unsigned int v7; // r31
  const idAngles *LocalAngles; // r3
  float yaw; // r7
  float roll; // r6
  double v11; // fp13
  float *v12; // r11
  _DWORD v14[4]; // [sp+50h] [-40h] BYREF

  v7 = axis;
  if ( axis > 2 )
  {
    v7 = 0;
    idGameLocal::MapError(this: gameLocal, fmt: "Invalid axis");
  }
  LocalAngles = idPhysics_Parametric::GetLocalAngles(this: (idPhysics_Parametric *)&result[800]);
  yaw = LocalAngles->yaw;
  roll = LocalAngles->roll;
  v14[0] = LODWORD(LocalAngles->pitch);
  *(float *)&v14[1] = yaw;
  *(float *)&v14[2] = roll;
  v11 = *(float *)&v14[v7];
  v12 = (float *)&result[4 * v7 + 2108];
  if ( (float)((float)angle - (float)360.0) <= v11 )
    *v12 = angle;
  else
    *v12 = (float)angle - (float)360.0;
  if ( *v12 < v11 )
    *v12 = *v12 + (float)360.0;
  (*(void (__fastcall **)(eventVoid *, idThread *, int))(*(_DWORD *)result + 644))(
    a1: result,
    a2: gameLocal->program.threadManager.currentThread,
    a3: 1);
  return this;
}


// ========================================================================
// ?Event_RotateTo@idMover@@AAA?AVeventVoid@@ABVidAngles@@@Z
// EA  : 0x82C801D8
// RVA : 0x00C801D8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_RotateTo(idMover *this, eventVoid *result, const idAngles *angles)
{
  int v3; // r10
  idGameLocal *v4; // r11

  *(float *)&result[2108] = angles->pitch;
  v3 = *(_DWORD *)result;
  *(float *)&result[2112] = angles->yaw;
  v4 = gameLocal;
  *(float *)&result[2116] = angles->roll;
  (*(void (__fastcall **)(eventVoid *, idThread *, int))(v3 + 644))(
    a1: result,
    a2: v4->program.threadManager.currentThread,
    a3: 1);
  return this;
}


// ========================================================================
// ?Event_Rotate@idMover@@AAA?AVeventVoid@@ABVidAngles@@@Z
// EA  : 0x82C80250
// RVA : 0x00C80250
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_Rotate(idMover *this, eventVoid *result, const idAngles *angles)
{
  const idAngles *LocalAngles; // r3
  __int64 v7; // r7
  idThread *currentThread; // r4
  double v9; // fp13
  double v10; // fp12
  float yaw; // [sp+5Ch] [-34h]
  float roll; // [sp+60h] [-30h]

  if ( *(_DWORD *)&result[2104] != 0 )
    (*(void (__fastcall **)(eventVoid *))(*(_DWORD *)result + 636))(a1: result);
  LocalAngles = idPhysics_Parametric::GetLocalAngles(this: (idPhysics_Parametric *)&result[800]);
  yaw = LocalAngles->yaw;
  roll = LocalAngles->roll;
  LODWORD(v7) = *(_DWORD *)&result[2160] - (*(_DWORD *)&result[2168] + *(_DWORD *)&result[2164]) / 2;
  HIDWORD(v7) = 0x20000;
  currentThread = gameLocal->program.threadManager.currentThread;
  v9 = (float)((float)(angles->yaw * (float)v7) * (float)0.001);
  v10 = (float)((float)(angles->roll * (float)v7) * (float)0.001);
  *(float *)&result[2108] = (float)((float)(angles->pitch * (float)v7) * (float)0.001) + LocalAngles->pitch;
  *(float *)&result[2112] = yaw + (float)v9;
  *(float *)&result[2116] = roll + (float)v10;
  (*(void (__fastcall **)(eventVoid *, idThread *, _DWORD))(*(_DWORD *)result + 644))(
    a1: result,
    a2: currentThread,
    a3: 0);
  return this;
}


// ========================================================================
// ?Event_RotateOnce@idMover@@AAA?AVeventVoid@@ABVidAngles@@@Z
// EA  : 0x82C80360
// RVA : 0x00C80360
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_RotateOnce(idMover *this, eventVoid *result, const idAngles *angles)
{
  const idAngles *LocalAngles; // r3
  double pitch; // fp0
  double yaw; // fp13
  float v9; // r6
  float v10; // r4

  if ( *(_DWORD *)&result[2104] != 0 )
    (*(void (__fastcall **)(eventVoid *))(*(_DWORD *)result + 636))(a1: result);
  LocalAngles = idPhysics_Parametric::GetLocalAngles(this: (idPhysics_Parametric *)&result[800]);
  pitch = angles->pitch;
  yaw = angles->yaw;
  v9 = LocalAngles->pitch;
  v10 = LocalAngles->yaw;
  *(float *)&result[2116] = angles->roll + LocalAngles->roll;
  *(float *)&result[2112] = (float)yaw + v10;
  *(float *)&result[2108] = (float)pitch + v9;
  (*(void (__fastcall **)(eventVoid *, idThread *, int))(*(_DWORD *)result + 644))(
    a1: result,
    a2: gameLocal->program.threadManager.currentThread,
    a3: 1);
  return this;
}


// ========================================================================
// ?Event_Bob@idMover@@AAA?AVeventVoid@@MMABVidVec3@@@Z
// EA  : 0x82C80428
// RVA : 0x00C80428
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_Bob(
        idMover *this,
        eventVoid *result,
        double speed,
        double phase,
        const idVec3 *depth,
        int a6,
        float *a7)
{
  idPhysics_Parametric *v7; // r30
  const idVec3 *LocalOrigin; // r3
  float x; // r10
  float y; // r9
  float z; // r8
  double v15; // fp10
  double v16; // fp9
  int GameMs; // r3
  __int64 v18; // r8
  _DWORD v20[4]; // [sp+58h] [-58h] BYREF
  idVec3 v21; // [sp+68h] [-48h] BYREF

  v7 = (idPhysics_Parametric *)&result[800];
  LocalOrigin = idPhysics_Parametric::GetLocalOrigin(this: (idPhysics_Parametric *)&result[800]);
  x = LocalOrigin->x;
  y = LocalOrigin->y;
  z = LocalOrigin->z;
  v15 = (float)(a7[1] * (float)speed);
  v16 = (float)(a7[2] * (float)speed);
  v21.x = *a7 * (float)speed;
  v21.y = v15;
  v21.z = v16;
  *(float *)v20 = x;
  *(float *)&v20[1] = y;
  *(float *)&v20[2] = z;
  idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  HIDWORD(v18) = (int)(float)((float)1000.0 / (float)speed);
  LODWORD(v18) = v20;
  idPhysics_Parametric::SetLinearExtrapolation(
    this: v7,
    type: EXTRAPOLATION_DECELSINE|EXTRAPOLATION_NOSTOP,
    currentTime: GameMs,
    duration: v18,
    base: &v21,
    speed: &vec3_origin);
  return this;
}


// ========================================================================
// ?Event_Sway@idMover@@AAA?AVeventVoid@@MMABVidAngles@@@Z
// EA  : 0x82C80508
// RVA : 0x00C80508
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_Sway(
        idMover *this,
        eventVoid *result,
        double speed,
        double phase,
        const idAngles *depth,
        int a6,
        float *a7)
{
  idPhysics_Parametric *v7; // r31
  const idAngles *LocalAngles; // r3
  double v12; // fp8
  double v13; // fp7
  double v14; // fp6
  float yaw; // r6
  float roll; // r5
  double v17; // fp5
  double v18; // fp3
  int GameMs; // r3
  __int64 v20; // r8
  int v22; // [sp+5Ch] [-54h]
  _DWORD v23[4]; // [sp+60h] [-50h] BYREF
  idAngles v24; // [sp+70h] [-40h] BYREF

  v7 = (idPhysics_Parametric *)&result[800];
  LocalAngles = idPhysics_Parametric::GetLocalAngles(this: (idPhysics_Parametric *)&result[800]);
  v12 = *a7;
  v13 = a7[1];
  v14 = a7[2];
  yaw = LocalAngles->yaw;
  roll = LocalAngles->roll;
  v17 = (float)((float)(*a7 * *a7) + (float)(a7[1] * a7[1]));
  v23[0] = LODWORD(LocalAngles->pitch);
  *(float *)&v23[1] = yaw;
  *(float *)&v23[2] = roll;
  v18 = __fsqrts((float)((float)((float)v14 * (float)v14) + (float)v17));
  v22 = (int)(float)((float)((float)v18 / (float)speed) * (float)1000.0);
  v24.pitch = (float)v12 * (float)((float)1.0 / (float)((float)0.70710677 * (float)((float)v18 / (float)speed)));
  v24.yaw = (float)v13 * (float)((float)1.0 / (float)((float)0.70710677 * (float)((float)v18 / (float)speed)));
  v24.roll = (float)v14 * (float)((float)1.0 / (float)((float)0.70710677 * (float)((float)v18 / (float)speed)));
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  HIDWORD(v20) = v22;
  LODWORD(v20) = v23;
  idPhysics_Parametric::SetAngularExtrapolation(
    this: v7,
    type: EXTRAPOLATION_DECELSINE|EXTRAPOLATION_NOSTOP,
    currentTime: GameMs,
    duration: v20,
    base: &v24,
    speed: &ang_zero);
  return this;
}


// ========================================================================
// ?Event_AccelSound@idMover@@AAA?AVeventVoid@@PBVidSoundShader@@@Z
// EA  : 0x82C80628
// RVA : 0x00C80628
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idMover::Event_AccelSound@<r4>(idMover *this@<r3>, int result@<r4>, const idSoundShader *sound@<r5>)
{
  *(_DWORD *)(result + 2200) = sound;
  return result;
}


// ========================================================================
// ?Event_DecelSound@idMover@@AAA?AVeventVoid@@PBVidSoundShader@@@Z
// EA  : 0x82C80630
// RVA : 0x00C80630
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idMover::Event_DecelSound@<r4>(idMover *this@<r3>, int result@<r4>, const idSoundShader *sound@<r5>)
{
  *(_DWORD *)(result + 2204) = sound;
  return result;
}


// ========================================================================
// ?Event_MoveSound@idMover@@AAA?AVeventVoid@@PBVidSoundShader@@@Z
// EA  : 0x82C80638
// RVA : 0x00C80638
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idMover::Event_MoveSound@<r4>(idMover *this@<r3>, int result@<r4>, const idSoundShader *sound@<r5>)
{
  *(_DWORD *)(result + 2208) = sound;
  return result;
}


// ========================================================================
// ?Event_EnableSplineAngles@idMover@@AAA?AVeventVoid@@XZ
// EA  : 0x82C80640
// RVA : 0x00C80640
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idMover::Event_EnableSplineAngles(idMover *this)
{
  __int64 result; // r4 OVERLAPPED

  *(_BYTE *)(result + 2174) = 1;
  return result;
}


// ========================================================================
// ?Event_DisableSplineAngles@idMover@@AAA?AVeventVoid@@XZ
// EA  : 0x82C80650
// RVA : 0x00C80650
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idMover::Event_DisableSplineAngles(idMover *this)
{
  __int64 result; // r4 OVERLAPPED

  *(_BYTE *)(result + 2174) = 0;
  return result;
}


// ========================================================================
// ?Event_RemoveInitialSplineAngles@idMover@@AAA?AVeventVoid@@XZ
// EA  : 0x82C80660
// RVA : 0x00C80660
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_RemoveInitialSplineAngles(idMover *this, eventVoid *result)
{
  idPhysics_Parametric *v2; // r31
  idCurve_Spline<idVec3> *Spline; // r4
  idAngles *v7; // r3
  idAngles *v8; // r3
  double yaw; // fp13
  double roll; // fp11
  int GameMs; // r3
  float v12[4]; // [sp+50h] [-50h] BYREF
  _BYTE v13[16]; // [sp+60h] [-40h] BYREF
  idVec3 v14[4]; // [sp+70h] [-30h] BYREF

  v2 = (idPhysics_Parametric *)&result[800];
  Spline = idPhysics_Parametric::GetSpline(this: (idPhysics_Parametric *)&result[800]);
  if ( Spline != nullptr )
  {
    v7 = (idAngles *)((int (__fastcall *)(_BYTE *, double))Spline->GetCurrentFirstDerivative)(a1: v13, a2: 0.0);
    v8 = idVec3::ToAngles(this: v14, result: v7);
    yaw = v8->yaw;
    roll = v8->roll;
    v12[0] = -v8->pitch;
    v12[1] = -yaw;
    v12[2] = -roll;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idPhysics_Parametric::SetAngularExtrapolation(
      this: v2,
      type: EXTRAPOLATION_NONE,
      currentTime: GameMs,
      duration: (unsigned int)v12,
      base: &ang_zero,
      speed: &ang_zero);
  }
  else
  {
    idLib::Warning(fmt: "removeIntialSplineAngles called for '%s' before startSpline!", *(const char **)&result[16]);
  }
  return this;
}


// ========================================================================
// ?Event_UpdateMoveSound@idMover@@AAA?AVeventVoid@@H@Z
// EA  : 0x82C80740
// RVA : 0x00C80740
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_UpdateMoveSound(idMover *this, idMover *result, idMover::moveStage_t stage)
{
  idMover::UpdateMoveSound(this: result, stage);
  return this;
}


// ========================================================================
// ?Event_StopSpline@idMover@@AAA?AVeventVoid@@XZ
// EA  : 0x82C80778
// RVA : 0x00C80778
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_StopSpline(idMover *this, eventVoid *result)
{
  idPhysics_Parametric::SetSpline(
    this: (idPhysics_Parametric *)&result[800],
    spline: nullptr,
    accelTime: 0,
    decelTime: nullptr,
    useSplineAngles: *(_BYTE *)&result[2174],
    angularSpline: nullptr);
  return this;
}


// ========================================================================
// ?Event_EnableInfluence@idMover@@AAA?AVeventVoid@@XZ
// EA  : 0x82C807C8
// RVA : 0x00C807C8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_EnableInfluence(
        idMover *this,
        idEntity *result,
        int a3,
        int a4,
        idPresentable *a5,
        const idSoundShader *a6)
{
  idPresentable *presentable; // r4

  presentable = result->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idInfluenceTrailManager::Enable(
    this: &clientGame->influenceTrailManager,
    presentable,
    trail: (const idEntityInfluenceTrail *)&result[2].defaultPhysicsObj.current.worldAxis.mat[2].y,
    sndFoliage: (const idSoundShader *const)LODWORD(result[2].defaultPhysicsObj.current.worldAxis.mat[2].x),
    a5,
    a6);
  return this;
}


// ========================================================================
// ?Event_DisableInfluence@idMover@@AAA?AVeventVoid@@XZ
// EA  : 0x82C80838
// RVA : 0x00C80838
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_DisableInfluence(idMover *this, idEntity *result)
{
  idPresentable *presentable; // r11

  presentable = result->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idInfluenceTrailManager::FreeInfluenceTrail(this: &clientGame->influenceTrailManager, presentable);
  return this;
}


// ========================================================================
// ?SetControlPoint@idSplinePath@@QAAXHVidVec3@@@Z
// EA  : 0x82C808A0
// RVA : 0x00C808A0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idSplinePath::SetControlPoint(idSplinePath *this, int index, idVec3 *point)
{
  int num; // r6
  idVec3 *v4; // r11

  num = this->controlPoints.num;
  if ( index >= num )
  {
    idLib::Warning(
      fmt: "%s - cannot set invalid index %d (num control points = %d)",
      "idSplinePath::SetControlPoint",
      index,
      num);
  }
  else
  {
    v4 = &this->controlPoints.list[index];
    v4->x = *(float *)&index;
    v4->y = *(float *)&point;
    v4->z = *(float *)&point;
  }
}


// ========================================================================
// ??0idFuncRotate@@QAA@XZ
// EA  : 0x82C80930
// RVA : 0x00C80930
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idFuncRotate *__fastcall idFuncRotate::idFuncRotate(idFuncRotate *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idFuncRotate_vtbl *)&idFuncRotate::`vftable';
  idPhysics_Parametric::idPhysics_Parametric(this: &this->physicsObj);
  this->solid = false;
  this->noPush = true;
  this->running = false;
  this->rotateSpeed.pitch = 180.0;
  this->rotateSpeed.yaw = 0.0;
  this->rotateSpeed.roll = 0.0;
  *(_BYTE *)&this->flags |= 0x40u;
  return this;
}


// ========================================================================
// __unwind$501788
// EA  : 0x82C809C8
// RVA : 0x00C809C8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_501788()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?OnActivate@idFuncRotate@@EAAXPAVidEntity@@@Z
// EA  : 0x82C80A50
// RVA : 0x00C80A50
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idFuncRotate::OnActivate(idFuncRotate *this, idEntity *activator)
{
  idGameTimeManager *p_gameTimeManager; // r3
  int GameMs; // r3
  bool v5; // r9
  int v6; // r3

  idEntity::ForceDormancy(this, dormant: false, durationMS: 30000);
  p_gameTimeManager = &clientGame->gameTimeManager;
  if ( this->running )
  {
    GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    idPhysics_Parametric::SetAngularExtrapolation(
      this: &this->physicsObj,
      type: EXTRAPOLATION_LINEAR|EXTRAPOLATION_DECELSINE,
      currentTime: GameMs,
      duration: (unsigned int)&ang_zero,
      base: &ang_zero,
      speed: &ang_zero);
    v5 = false;
  }
  else
  {
    v6 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    idPhysics_Parametric::SetAngularExtrapolation(
      this: &this->physicsObj,
      type: EXTRAPOLATION_LINEAR|EXTRAPOLATION_NOSTOP,
      currentTime: v6,
      duration: (unsigned int)&ang_zero,
      base: &this->rotateSpeed,
      speed: &ang_zero);
    v5 = true;
  }
  this->running = v5;
}


// ========================================================================
// ?Action_SetRotateSpeed@idFuncRotate@@QAA?AVeventVoid@@HHH@Z
// EA  : 0x82C80B18
// RVA : 0x00C80B18
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idFuncRotate *__fastcall idFuncRotate::Action_SetRotateSpeed(
        idFuncRotate *this,
        eventVoid *result,
        unsigned int pitch,
        const int yaw,
        unsigned int roll)
{
  __int128 v5; // r10
  const idAngles *v7; // r29
  idAngles *v8; // r30
  int GameMs; // r3
  int v10; // r3
  _QWORD v12[9]; // [sp+58h] [-48h] BYREF

  *(_QWORD *)((char *)&v5 + 4) = __PAIR64__(pitch, roll);
  LODWORD(v5) = yaw;
  HIDWORD(v5) = (unsigned __int8)result[2048];
  v12[0] = v5;
  *(float *)&result[2044] = (float)*(__int64 *)((char *)&v5 + 4);
  v7 = (const idAngles *)&result[2036];
  *(float *)&result[2036] = (float)*(__int64 *)&v5;
  *(float *)&result[2040] = (float)(__int64)v5;
  if ( HIDWORD(v5) != 0 )
  {
    v8 = (idAngles *)&result[800];
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idPhysics_Parametric::GetCurrentAngularExtrapolationAngles(
      this: (idPhysics_Parametric *)v12,
      result: v8,
      time: GameMs);
    idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v10 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idPhysics_Parametric::SetAngularExtrapolation(
      this: (idPhysics_Parametric *)v8,
      type: EXTRAPOLATION_LINEAR|EXTRAPOLATION_NOSTOP,
      currentTime: v10,
      duration: (unsigned int)v12,
      base: v7,
      speed: &ang_zero);
  }
  return this;
}


// ========================================================================
// ??0idFuncSwing@@QAA@XZ
// EA  : 0x82C80C18
// RVA : 0x00C80C18
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idFuncSwing *__fastcall idFuncSwing::idFuncSwing(idFuncSwing *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idFuncSwing_vtbl *)&idFuncSwing::`vftable';
  idPhysics_Parametric::idPhysics_Parametric(this: &this->physicsObj);
  this->solid = false;
  this->noPush = true;
  this->swingSpeed = 1.0;
  this->swingExtents.pitch = 15.0;
  this->swingExtents.yaw = 0.0;
  this->swingExtents.roll = 0.0;
  this->running = false;
  return this;
}


// ========================================================================
// __unwind$501863
// EA  : 0x82C80CB0
// RVA : 0x00C80CB0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_501863()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?Damage@idMoverMM@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PBUtrace_t@@@Z
// EA  : 0x82C80D38
// RVA : 0x00C80D38
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

float __fastcall idMoverMM::Damage(
        idMoverMM *this,
        idWorldspawn *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        const trace_t *trace)
{
  double v11; // fp1
  double v12; // fp12
  idMoverMM_vtbl *v13; // r10
  float v15; // [sp+50h] [-30h] BYREF

  if ( this->TakesDamage(this) )
  {
    if ( inflictor == nullptr )
      inflictor = gameLocal->world;
    v15 = idDeclDamage::DamageAmount(this: damageDef);
    attacker->DamageFeedback(this: attacker, a2: this, a3: inflictor, a4: damageDef, a5: &v15);
    v11 = v15;
    if ( v15 != 0.0 )
    {
      v12 = (float)(this->health - v15);
      this->health = this->health - v15;
      if ( v12 <= 0.0 )
      {
        v13 = this->__vftable;
        *(_BYTE *)&this->flags &= ~2u;
        v13->ActivateTargets(this, a2: attacker);
        v11 = v15;
      }
    }
  }
  else
  {
    v11 = 0.0;
  }
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?VectorForDir@idMoverMM@@AAAXMAAVidVec3@@@Z
// EA  : 0x82C80E28
// RVA : 0x00C80E28
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::VectorForDir(idMoverMM *this, double angle, idVec3 *vec, float *a4)
{
  idAngles *v6; // r3
  double v7; // fp11
  idAngles *v8; // r3
  double v9; // fp11
  idAngles *v10; // r3
  idAngles *v11; // r3
  double v12; // fp11
  double z; // fp12
  double v14; // fp10
  double v15; // fp9
  double v16; // fp10
  double v17; // fp9
  double v18; // fp10
  double v19; // fp9
  const idVec3 *v20; // r3
  float *WorldVector; // r3
  idVec3 v22; // [sp+50h] [-D0h] BYREF
  idMat3 v23; // [sp+60h] [-C0h] BYREF
  idAngles v24; // [sp+90h] [-90h] BYREF
  idMat3 v25; // [sp+A0h] [-80h] BYREF
  idAngles v26; // [sp+D0h] [-50h] BYREF
  idAngles v27; // [sp+E0h] [-40h] BYREF
  char v28; // [sp+F0h] [-30h] BYREF

  LODWORD(v22.y) = (int)angle;
  switch ( (int)angle )
  {
    case -12:
      v18 = -this->physicsObj.current.localAxis.mat[0].y;
      v19 = -this->physicsObj.current.localAxis.mat[0].z;
      *a4 = -this->physicsObj.current.localAxis.mat[0].x;
      a4[1] = v18;
      a4[2] = v19;
      return;
    case -11:
      *a4 = this->physicsObj.current.localAxis.mat[0].x;
      a4[1] = this->physicsObj.current.localAxis.mat[0].y;
      z = this->physicsObj.current.localAxis.mat[0].z;
      goto LABEL_15;
    case -10:
      *a4 = this->physicsObj.current.localAxis.mat[1].x;
      a4[1] = this->physicsObj.current.localAxis.mat[1].y;
      z = this->physicsObj.current.localAxis.mat[1].z;
      goto LABEL_15;
    case -9:
      v16 = -this->physicsObj.current.localAxis.mat[1].y;
      v17 = -this->physicsObj.current.localAxis.mat[1].z;
      *a4 = -this->physicsObj.current.localAxis.mat[1].x;
      a4[1] = v16;
      a4[2] = v17;
      return;
    case -8:
      v14 = -this->physicsObj.current.localAxis.mat[2].y;
      v15 = -this->physicsObj.current.localAxis.mat[2].z;
      *a4 = -this->physicsObj.current.localAxis.mat[2].x;
      a4[1] = v14;
      a4[2] = v15;
      return;
    case -7:
      *a4 = this->physicsObj.current.localAxis.mat[2].x;
      a4[1] = this->physicsObj.current.localAxis.mat[2].y;
      z = this->physicsObj.current.localAxis.mat[2].z;
      goto LABEL_15;
    case -6:
      v11 = idMat3::ToAngles(this: (idMat3 *)&v25.mat[2].z, result: (idAngles *)&this->physicsObj.current.localAxis);
      v22.x = v11->pitch;
      v12 = (float)(v11->yaw + (float)180.0);
      v22.x = 0.0;
      v22.z = 0.0;
      v22.y = v12;
      *(idVec3 *)a4 = *idAngles::ToForward(this: &v26, result: &v22);
      return;
    case -5:
      v10 = idMat3::ToAngles(this: &v25, result: (idAngles *)&this->physicsObj.current.localAxis);
      v22.x = v10->pitch;
      v22.y = v10->yaw;
      v22.x = 0.0;
      v22.z = 0.0;
      *(idVec3 *)a4 = *idAngles::ToForward(this: (idAngles *)&v25.mat[1].y, result: &v22);
      return;
    case -4:
      v8 = idMat3::ToAngles(this: (idMat3 *)&v23.mat[2].z, result: (idAngles *)&this->physicsObj.current.localAxis);
      v22.x = v8->pitch;
      v9 = (float)(v8->yaw - (float)90.0);
      v22.x = 0.0;
      v22.z = 0.0;
      v22.y = v9;
      *(idVec3 *)a4 = *idAngles::ToForward(this: &v24, result: &v22);
      return;
    case -3:
      v6 = idMat3::ToAngles(this: &v23, result: (idAngles *)&this->physicsObj.current.localAxis);
      v22.x = v6->pitch;
      v7 = (float)(v6->yaw + (float)90.0);
      v22.x = 0.0;
      v22.z = 0.0;
      v22.y = v7;
      *(idVec3 *)a4 = *idAngles::ToForward(this: (idAngles *)&v23.mat[1].y, result: &v22);
      return;
    case -2:
      *a4 = 0.0;
      a4[1] = 0.0;
      a4[2] = -1.0;
      return;
    case -1:
      *a4 = 0.0;
      a4[1] = 0.0;
      a4[2] = 1.0;
      return;
    default:
      v22.y = angle;
      v22.x = 0.0;
      v22.z = 0.0;
      v20 = idAngles::ToForward(this: &v27, result: &v22);
      WorldVector = (float *)idEntity::GetWorldVector(this: (idEntity *)&v28, result: this, vec: v20);
      *a4 = *WorldVector;
      a4[1] = WorldVector[1];
      z = WorldVector[2];
LABEL_15:
      a4[2] = z;
      return;
  }
}


// ========================================================================
// ?DrawDebugAxis@idMoverMM@@AAAXXZ
// EA  : 0x82C81188
// RVA : 0x00C81188
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::DrawDebugAxis(idMoverMM *this)
{
  idRenderWorld *v2; // r30
  idPhysics *Physics; // r3
  int v4; // r28
  idPhysics *v5; // r3
  int v6; // r3
  idMoverMM *TeamMaster; // r3
  idMoverAttachment *i; // r31
  int v9; // r11
  char v10; // r11
  bool v11; // zf
  idMoverAttachment *v12; // r28
  idRenderWorld *v13; // r27
  idPhysics *v14; // r3
  int v15; // r26
  idPhysics *v16; // r3
  int v17; // r3

  if ( g_debugShowMoverAttachmentAxis.valueInteger != 0 )
  {
    v2 = gameLocal->GetRenderWorld(this: gameLocal);
    Physics = idEntity::GetPhysics(this);
    v4 = (int)Physics->GetAxis(this: Physics, a2: 0);
    v5 = idEntity::GetPhysics(this);
    v6 = (int)v5->GetOrigin(this: v5, a2: 0);
    v2->DebugAxis_2(this: v2, a2: (const idVec3 *)v6, a3: (const idMat3 *)v4, a4: 2000, a5: false);
    TeamMaster = (idMoverMM *)idEntity::GetTeamMaster(this);
    if ( TeamMaster == this )
    {
      for ( i = (idMoverAttachment *)TeamMaster->bindInfo.teamChain;
            i != nullptr;
            i = (idMoverAttachment *)i->bindInfo.teamChain )
      {
        v9 = *(_DWORD *)(i->GetType(this: i) + 36);
        if ( v9 < idMoverAttachment::Type.typeNum || (v11 = v9 <= idMoverAttachment::Type.lastChild, v10 = 1, !v11) )
          v10 = 0;
        if ( v10 != 0 )
        {
          v12 = idMoverAttachment::CastTo(c: i);
          v13 = gameLocal->GetRenderWorld(this: gameLocal);
          v14 = idEntity::GetPhysics(this: v12);
          v15 = (int)v14->GetAxis(this: v14, a2: 0);
          v16 = idEntity::GetPhysics(this: v12);
          v17 = (int)v16->GetOrigin(this: v16, a2: 0);
          v13->DebugAxis_2(this: v13, a2: (const idVec3 *)v17, a3: (const idMat3 *)v15, a4: 2000, a5: false);
        }
      }
    }
  }
}


// ========================================================================
// ?Event_StopMoving@idMoverMM@@AAA?AVeventVoid@@XZ
// EA  : 0x82C81330
// RVA : 0x00C81330
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_StopMoving(idMoverMM *this, eventVoid *result)
{
  int v2; // r11
  void (__fastcall *v4)(eventVoid *); // r10

  v2 = *(_DWORD *)result;
  *(float *)&result[7284] = *(float *)&result[5384];
  *(float *)&result[7288] = *(float *)&result[5388];
  v4 = *(void (__fastcall **)(eventVoid *))(v2 + 680);
  *(float *)&result[7292] = *(float *)&result[5392];
  v4(a1: result);
  return this;
}


// ========================================================================
// ?Event_ReachedPos@idMoverMM@@AAA?AVeventVoid@@XZ
// EA  : 0x82C81388
// RVA : 0x00C81388
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_ReachedPos(idMoverMM *this, idMoverMM *result)
{
  eventVoid *p_localOrigin; // r30
  unsigned int stage; // r11
  int acceleration; // r27
  int v7; // r3
  int movetime; // r27
  int v9; // r3
  idMoverMM *v10; // r3
  int deceleration; // r27
  int v12; // r3
  const char *data; // r30
  int v14; // r3

  p_localOrigin = (eventVoid *)&result->physicsObj.current.localOrigin;
  idMoverMM::UpdateMoveSound(this: result, stage: result->move.stage);
  stage = result->move.stage;
  if ( stage > 3 )
    return this;
  if ( stage == 1 )
  {
    movetime = result->move.movetime;
    gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v9 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idPhysics_ParametricMM::SetLinearExtrapolation(
      this: &result->physicsObj,
      type: EXTRAPOLATION_LINEAR,
      currentTime: v9,
      duration: __SPAIR64__(movetime, (unsigned int)p_localOrigin),
      base: &result->move.dir,
      speed: &vec3_origin);
    result->move.stage = ((_cntlzw(result->move.deceleration) & 0x20) != 0) + 2;
    return this;
  }
  if ( stage == 2 )
  {
    deceleration = result->move.deceleration;
    gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v12 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idPhysics_ParametricMM::SetLinearExtrapolation(
      this: &result->physicsObj,
      type: EXTRAPOLATION_DECELLINEAR,
      currentTime: v12,
      duration: __SPAIR64__(deceleration, (unsigned int)p_localOrigin),
      base: &result->move.dir,
      speed: &vec3_origin);
    result->move.stage = FINISHED_STAGE;
    return this;
  }
  if ( stage != 0 )
  {
    if ( g_debugMover.valueInteger != 0 )
    {
      data = result->name.data;
      v14 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idLib::Printf(fmt: "%d: '%s' move done\n", v14, data);
    }
    result->DoneMoving(this: result);
    return this;
  }
  acceleration = result->move.acceleration;
  gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v7 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idPhysics_ParametricMM::SetLinearExtrapolation(
    this: &result->physicsObj,
    type: EXTRAPOLATION_ACCELLINEAR,
    currentTime: v7,
    duration: __SPAIR64__(acceleration, (unsigned int)p_localOrigin),
    base: &result->move.dir,
    speed: &vec3_origin);
  if ( result->move.movetime <= 0 )
  {
    v10 = this;
    if ( result->move.deceleration <= 0 )
      result->move.stage = FINISHED_STAGE;
    else
      result->move.stage = DECELERATION_STAGE;
  }
  else
  {
    result->move.stage = LINEAR_STAGE;
    return this;
  }
  return v10;
}


// ========================================================================
// ?BeginMove@idMoverMM@@MAAXXZ
// EA  : 0x82C81600
// RVA : 0x00C81600
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::BeginMove(idMoverMM *this)
{
  idMoverMM::moveStage_t v1; // r29
  double y; // fp12
  double v3; // fp11
  idVec3 *p_move_delta; // r30
  double v6; // fp6
  double v7; // fp8
  char v8; // r11
  int v9; // r3
  int acceltime; // r10
  int move_time; // r9
  int deceltime; // r3
  int v13; // r8
  __int64 v14; // r9
  int v15; // r3
  int v16; // r7
  int v17; // r6
  double move_speed; // fp12
  int v19; // r11
  double v20; // fp0
  int v21; // r3
  int v22; // r11
  __int64 v23; // r8
  int v24; // r10
  signed int v25; // r9
  int v26; // r3
  double z; // fp11
  __int64 v28; // r7
  double v29; // fp10
  __int64 v30; // [sp+50h] [-50h]
  idEventReceiver v31[5]; // [sp+60h] [-40h] BYREF

  v1 = DECELERATION_STAGE;
  this->lastCommand = MOVER_MOVING;
  y = this->dest_position.y;
  v3 = this->physicsObj.current.localOrigin.y;
  p_move_delta = &this->move_delta;
  v6 = (float)(this->dest_position.x - this->physicsObj.current.localOrigin.x);
  v7 = (float)(this->dest_position.z - this->physicsObj.current.localOrigin.z);
  this->move_delta.x = this->dest_position.x - this->physicsObj.current.localOrigin.x;
  this->move_delta.y = (float)y - (float)v3;
  this->move_delta.z = v7;
  if ( v6 != vec3_origin.x || this->move_delta.y != vec3_origin.y || (v8 = 1, this->move_delta.z != vec3_origin.z) )
    v8 = 0;
  if ( v8 != 0 )
  {
    this->DoneMoving(this);
  }
  else
  {
    v9 = SnapTimeToPhysicsFrame(t: this->acceltime);
    acceltime = this->acceltime;
    move_time = this->move_time;
    this->acceltime = v9;
    v13 = move_time - acceltime + v9;
    deceltime = this->deceltime;
    this->move_time = v13;
    v15 = SnapTimeToPhysicsFrame(t: deceltime);
    v16 = this->move_time;
    v17 = this->deceltime;
    move_speed = this->move_speed;
    this->deceltime = v15;
    this->move_time = v16 - v17 + v15;
    if ( move_speed != 0.0 )
    {
      v19 = v15 + this->acceltime;
      LODWORD(v14) = v19;
      v20 = __fsqrts((float)((float)(p_move_delta->x * p_move_delta->x)
                           + (float)((float)(p_move_delta->y * p_move_delta->y)
                                   + (float)(p_move_delta->z * p_move_delta->z))));
      if ( (float)((float)((float)v14 * (float)move_speed) * (float)0.00050000002) < v20 )
        this->move_time = v19
                        - (int)(float)((float)((float)((float)v20
                                                     - (float)((float)((float)v14 * (float)move_speed)
                                                             * (float)0.00050000002))
                                             / (float)move_speed)
                                     * (float)-1000.0);
      else
        this->move_time = v19;
    }
    v21 = SnapTimeToPhysicsFrame(t: this->move_time);
    v22 = this->acceltime;
    LODWORD(v23) = v21;
    this->move_time = v21;
    if ( v22 != 0 )
    {
      v1 = ACCELERATION_STAGE;
    }
    else if ( v21 > this->deceltime )
    {
      v1 = LINEAR_STAGE;
    }
    v24 = this->deceltime;
    v25 = v24 + v22;
    if ( v24 + v22 > v21 )
    {
      __twllei(v25, 0);
      __twlgei(v25 & ~(__ROL4__(v21 * v22, 1) - 1), 0xFFFFFFFF);
      v26 = SnapTimeToPhysicsFrame(t: v21 * v22 / v25);
      LODWORD(v23) = this->move_time;
      v22 = v26;
      v24 = v23 - v26;
    }
    z = p_move_delta->z;
    v30 = v23;
    HIDWORD(v28) = 0x82000000;
    v29 = p_move_delta->y;
    LODWORD(v28) = v24 + v22;
    p_move_delta->x = p_move_delta->x
                    * (float)((float)1000.0 / (float)-(float)((float)((float)v28 * (float)0.5) - (float)v30));
    p_move_delta->z = (float)z * (float)((float)1000.0 / (float)-(float)((float)((float)v28 * (float)0.5) - (float)v30));
    p_move_delta->y = (float)v29
                    * (float)((float)1000.0 / (float)-(float)((float)((float)v28 * (float)0.5) - (float)v30));
    LODWORD(v28) = this->move_time;
    this->move.acceleration = v22;
    this->move.stage = v1;
    this->move.deceleration = v24;
    this->move.movetime = v28 - v24 - v22;
    this->move.dir.x = p_move_delta->x;
    this->move.dir.y = p_move_delta->y;
    this->move.dir.z = p_move_delta->z;
    idEventReceiver::ProcessEvent(this: v31, result: (idEventArg *)this, ev: &EV_ReachedPos);
  }
}


// ========================================================================
// ?Event_StopRotating@idMoverMM@@AAA?AVeventVoid@@XZ
// EA  : 0x82C818B8
// RVA : 0x00C818B8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_StopRotating(idMoverMM *this, eventVoid *result)
{
  const idMat3 *v4; // r29
  int v5; // r3
  __int64 v6; // r10

  v4 = (const idMat3 *)&result[5396];
  v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  HIDWORD(v6) = &vec3_origin;
  idPhysics_ParametricMM::SetAngularExtrapolation(
    this: (idPhysics_ParametricMM *)&result[5200],
    type: EXTRAPOLATION_NONE,
    currentTime: v5,
    time: 0,
    duration: 0,
    base: v4,
    vec: v6,
    speed: 0.0);
  (*(void (__fastcall **)(eventVoid *))(*(_DWORD *)result + 684))(a1: result);
  return this;
}


// ========================================================================
// ?Event_ReachedAng@idMoverMM@@AAA?AVeventVoid@@XZ
// EA  : 0x82C81938
// RVA : 0x00C81938
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_ReachedAng(idMoverMM *this, idMoverMM *result)
{
  const idMat3 *p_localAxis; // r29
  unsigned int stage; // r11
  double v6; // fp31
  unsigned int acceleration; // r28
  unsigned int v8; // r30
  int v9; // r3
  __int64 v10; // r10
  double v11; // fp31
  unsigned int movetime; // r28
  eventVoid *p_vec; // r26
  unsigned int v14; // r30
  __int64 v15; // r10
  int v16; // r3
  extrapolation_t v17; // r4
  double speed; // fp31
  unsigned int deceleration; // r28
  unsigned int v20; // r30
  int v21; // r3
  __int64 v22; // r10
  idMoverMM *v23; // r3
  BOOL stopRotation; // r11
  idMat3 *v25; // r3
  int v26; // r3
  __int64 v27; // r10
  double v28; // fp31
  unsigned int v29; // r26
  int v30; // r3
  __int64 v31; // r10
  const char *data; // r30
  int v33; // r3
  idMat3 v34; // [sp+50h] [-70h] BYREF

  p_localAxis = &result->physicsObj.current.localAxis;
  idMoverMM::UpdateRotationSound(this: result, stage: result->rot.stage);
  stage = result->rot.stage;
  if ( stage > 3 )
    return this;
  if ( stage != 1 )
  {
    if ( stage == 2 )
    {
      speed = result->rot.speed;
      deceleration = result->rot.deceleration;
      v20 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      v21 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      HIDWORD(v22) = &result->rot.vec;
      idPhysics_ParametricMM::SetAngularExtrapolation(
        this: &result->physicsObj,
        type: EXTRAPOLATION_DECELLINEAR,
        currentTime: v21,
        time: v20,
        duration: deceleration,
        base: p_localAxis,
        vec: v22,
        speed);
      result->rot.stage = FINISHED_STAGE;
      return this;
    }
    if ( stage == 0 )
    {
      v6 = result->rot.speed;
      acceleration = result->rot.acceleration;
      v8 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      v9 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      HIDWORD(v10) = &result->rot.vec;
      idPhysics_ParametricMM::SetAngularExtrapolation(
        this: &result->physicsObj,
        type: EXTRAPOLATION_ACCELLINEAR,
        currentTime: v9,
        time: v8,
        duration: acceleration,
        base: p_localAxis,
        vec: v10,
        speed: v6);
      if ( result->rot.movetime <= 0 )
      {
        v23 = this;
        if ( result->rot.deceleration <= 0 )
          result->rot.stage = FINISHED_STAGE;
        else
          result->rot.stage = DECELERATION_STAGE;
      }
      else
      {
        result->rot.stage = LINEAR_STAGE;
        return this;
      }
      return v23;
    }
    stopRotation = result->stopRotation;
    result->lastCommand = MOVER_NONE;
    if ( stopRotation )
    {
      v25 = (idMat3 *)idQuat::Normalize(this: &result->dest_quat);
      idQuat::ToMat3(this: (idQuat *)&v34, result: v25);
      v26 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      HIDWORD(v27) = &vec3_origin;
      idPhysics_ParametricMM::SetAngularExtrapolation(
        this: &result->physicsObj,
        type: EXTRAPOLATION_NONE,
        currentTime: v26,
        time: 0,
        duration: 0,
        base: &v34,
        vec: v27,
        speed: 0.0);
      result->stopRotation = false;
    }
    else if ( idPhysics_ParametricMM::GetAngularExtrapolationType(this: &result->physicsObj) == EXTRAPOLATION_ACCELLINEAR )
    {
      v28 = result->rot.speed;
      v29 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      v30 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      HIDWORD(v31) = &result->rot.vec;
      idPhysics_ParametricMM::SetAngularExtrapolation(
        this: &result->physicsObj,
        type: EXTRAPOLATION_LINEAR|EXTRAPOLATION_NOSTOP,
        currentTime: v30,
        time: v29,
        duration: 0,
        base: p_localAxis,
        vec: v31,
        speed: v28);
    }
    if ( g_debugMover.valueInteger != 0 )
    {
      data = result->name.data;
      v33 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idLib::Printf(fmt: "%d: '%s' rotation done\n", v33, data);
    }
    result->DoneRotating(this: result);
    return this;
  }
  if ( result->stopRotation || result->rot.deceleration != 0 )
  {
    v11 = result->rot.speed;
    movetime = result->rot.movetime;
    p_vec = (eventVoid *)&result->rot.vec;
    v14 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v16 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v17 = EXTRAPOLATION_LINEAR;
  }
  else
  {
    v11 = result->rot.speed;
    movetime = result->rot.movetime;
    p_vec = (eventVoid *)&result->rot.vec;
    v14 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v16 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v17 = EXTRAPOLATION_LINEAR|EXTRAPOLATION_NOSTOP;
  }
  HIDWORD(v15) = p_vec;
  idPhysics_ParametricMM::SetAngularExtrapolation(
    this: &result->physicsObj,
    type: v17,
    currentTime: v16,
    time: v14,
    duration: movetime,
    base: p_localAxis,
    vec: v15,
    speed: v11);
  result->rot.stage = ((_cntlzw(result->rot.deceleration) & 0x20) != 0) + 2;
  return this;
}


// ========================================================================
// ?BeginRotation@idMoverMM@@MAAX_N@Z
// EA  : 0x82C81D20
// RVA : 0x00C81D20
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMoverMM::BeginRotation(idMoverMM *this, bool stopwhendone)
{
  int move_time; // r11
  idMat3 *p_localAxis; // r30
  int v6; // r3
  int v7; // r11
  int acceltime; // r10
  int v9; // r9
  int deceltime; // r3
  int v11; // r3
  int v12; // r8
  int v13; // r7
  int v14; // r3
  int v15; // r11
  idMoverMM::moveStage_t v16; // r24
  int v17; // r27
  int v18; // r28
  int v19; // r10
  signed int v20; // r11
  int v21; // r3
  bool v22; // r11
  float yaw; // r10
  __int64 v24; // r7 OVERLAPPED
  float roll; // r5 OVERLAPPED
  float pitch; // r3
  idAngles *p_dest_angles; // r29
  double v28; // fp31
  double v29; // fp12
  double v30; // fp10
  double v31; // fp9
  double v32; // fp8
  double v33; // fp4
  double v34; // fp1
  double v35; // fp0
  double v36; // fp13
  double v37; // fp31
  double w; // fp30
  double v39; // fp29
  double v40; // fp28
  double v41; // fp12
  double v42; // fp11
  double v43; // fp9
  double y; // fp6
  double v45; // fp5
  double z; // fp4
  double v47; // fp3
  double v48; // fp2
  double v49; // fp29
  double v50; // fp27
  int v51; // ctr
  int *v52; // r10
  double v53; // fp11
  float *p_y; // r11
  double v55; // fp6
  double v56; // fp12
  double v57; // fp6
  double v58; // fp5
  double v59; // fp4
  double v61; // fp11
  double v63; // fp8
  double v64; // fp12
  double v65; // fp8
  const idMat3 *v66; // r3
  int v67; // r11
  char v68; // [sp+50h] [-180h] BYREF
  idRotation v69; // [sp+60h] [-170h] BYREF
  float v70; // [sp+A4h] [-12Ch]
  float v71; // [sp+A8h] [-128h]
  char v72; // [sp+D0h] [-100h]
  int v73; // [sp+DCh] [-F4h] BYREF
  idMat3 v74; // [sp+E0h] [-F0h] BYREF
  idQuat v75; // [sp+110h] [-C0h] BYREF
  float v76; // [sp+120h] [-B0h]
  float v77; // [sp+124h] [-ACh]
  float v78; // [sp+128h] [-A8h]
  char v79; // [sp+150h] [-80h]

  move_time = this->move_time;
  this->lastCommand = MOVER_ROTATING;
  if ( move_time == 0 )
    this->move_time = 1;
  p_localAxis = &this->physicsObj.current.localAxis;
  idMat3::ToQuat(this: (idMat3 *)&v69.axis.mat[0].y, result: (idQuat *)&this->physicsObj.current.localAxis);
  v6 = SnapTimeToPhysicsFrame(t: this->acceltime);
  v7 = this->move_time;
  acceltime = this->acceltime;
  this->acceltime = v6;
  v9 = v7 - acceltime + v6;
  deceltime = this->deceltime;
  this->move_time = v9;
  v11 = SnapTimeToPhysicsFrame(t: deceltime);
  v12 = this->move_time;
  v13 = this->deceltime;
  this->deceltime = v11;
  this->move_time = v12 - v13 + v11;
  v14 = SnapTimeToPhysicsFrame(t: v12 - v13 + v11);
  v15 = this->acceltime;
  this->move_time = v14;
  if ( v15 != 0 )
  {
    v16 = ACCELERATION_STAGE;
  }
  else
  {
    v16 = DECELERATION_STAGE;
    if ( v14 > this->deceltime )
      v16 = LINEAR_STAGE;
  }
  v17 = this->deceltime;
  v18 = v15;
  v19 = v14;
  v20 = v17 + v15;
  if ( v20 > v14 )
  {
    __twllei(v20, 0);
    __twlgei(v20 & ~(__ROL4__(v14 * v18, 1) - 1), 0xFFFFFFFF);
    v21 = SnapTimeToPhysicsFrame(t: v14 * v18 / v20);
    v19 = this->move_time;
    v18 = v21;
    v17 = v19 - v21;
  }
  if ( stopwhendone || (v22 = false, v17 != 0) )
    v22 = true;
  this->stopRotation = v22;
  HIDWORD(v24) = v19;
  yaw = this->dest_angles.yaw;
  LODWORD(v24) = v17 + v18;
  roll = this->dest_angles.roll;
  pitch = this->dest_angles.pitch;
  *(_QWORD *)&v69.vec.y = *(__int64 *)((char *)&v24 + 4);
  p_dest_angles = &this->dest_angles;
  v28 = (float)((float)1000.0 / (float)-(float)((float)((float)v24 * (float)0.5) - (float)*(__int64 *)((char *)&v24 + 4)));
  if ( ((LODWORD(roll) | LODWORD(pitch) | LODWORD(yaw)) & 0x7FFFFFFF) != 0 )
  {
    v41 = (float)(p_dest_angles->pitch
                * (float)((float)1000.0
                        / (float)-(float)((float)((float)v24 * (float)0.5) - (float)*(__int64 *)((char *)&v24 + 4))));
    v42 = (float)(this->dest_angles.roll
                * (float)((float)1000.0
                        / (float)-(float)((float)((float)v24 * (float)0.5) - (float)*(__int64 *)((char *)&v24 + 4))));
    v43 = (float)((float)((float)1000.0
                        / (float)-(float)((float)((float)v24 * (float)0.5) - (float)*(__int64 *)((char *)&v24 + 4)))
                * this->dest_angles.yaw);
    y = this->physicsObj.current.localAxis.mat[0].y;
    v45 = this->physicsObj.current.localAxis.mat[1].y;
    z = this->physicsObj.current.localAxis.mat[0].z;
    v47 = this->physicsObj.current.localAxis.mat[1].z;
    v48 = this->physicsObj.current.localAxis.mat[2].y;
    v69.axis.mat[2].y = vec3_origin.z;
    v72 = 0;
    v49 = -v41;
    v50 = -v42;
    v69.axis.mat[1].z = vec3_origin.x;
    v69.axis.mat[2].x = vec3_origin.y;
    v51 = 9;
    v52 = &v73;
    v53 = (float)((float)y * (float)-v42);
    p_y = &mat2_identity.mat[1].y;
    v55 = (float)((float)v47 * (float)-v41);
    v56 = (float)((float)((float)v45 * (float)-v41) + (float)v53);
    v58 = (float)((float)((float)v55 + (float)((float)z * (float)v50))
                + (float)(this->physicsObj.current.localAxis.mat[2].z * (float)-v43));
    v57 = (float)((float)v56 + (float)((float)v48 * (float)-v43));
    v59 = (float)((float)((float)(this->physicsObj.current.localAxis.mat[1].x * (float)v49)
                        + (float)(this->physicsObj.current.localAxis.mat[0].x * (float)v50))
                + (float)(this->physicsObj.current.localAxis.mat[2].x * (float)-v43));
    _FP12 = (float)((float)((float)((float)v59 * (float)v59)
                          + (float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    v61 = (float)((float)((float)((float)v59 * (float)v59)
                        + (float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57)))
                * (float)0.5);
    __asm { fsel      f10, f12, f1, f13 }
    v63 = __frsqrte(_FP10);
    v64 = (float)((float)-(float)((float)((float)((float)v63
                                                * (float)((float)((float)((float)v59 * (float)v59)
                                                                + (float)((float)((float)v58 * (float)v58)
                                                                        + (float)((float)v57 * (float)v57)))
                                                        * (float)0.5))
                                        * (float)v63)
                                - (float)1.5)
                * (float)v63);
    v65 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v63 * (float)v61) * (float)v63)
                                                                - (float)1.5)
                                                * (float)v63)
                                        * (float)v61)
                                * (float)((float)-(float)((float)((float)((float)v63 * (float)v61) * (float)v63)
                                                        - (float)1.5)
                                        * (float)v63))
                        - (float)1.5);
    v37 = (float)((float)((float)-(float)((float)((float)((float)((float)v65 * (float)v64)
                                                        * (float)((float)((float)((float)v59 * (float)v59)
                                                                        + (float)((float)((float)v58 * (float)v58)
                                                                                + (float)((float)v57 * (float)v57)))
                                                                * (float)0.5))
                                                * (float)((float)v65 * (float)v64))
                                        - (float)1.5)
                        * (float)((float)v65 * (float)v64))
                * (float)((float)((float)v59 * (float)v59)
                        + (float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57))));
    w = (float)((float)((float)((float)(p_localAxis->mat[1].x * (float)v49) + (float)(p_localAxis->mat[0].x * (float)v50))
                      + (float)(p_localAxis->mat[2].x * (float)-v43))
              * (float)((float)-(float)((float)((float)((float)((float)v65 * (float)v64)
                                                      * (float)((float)((float)((float)v59 * (float)v59)
                                                                      + (float)((float)((float)v58 * (float)v58)
                                                                              + (float)((float)v57 * (float)v57)))
                                                              * (float)0.5))
                                              * (float)((float)v65 * (float)v64))
                                      - (float)1.5)
                      * (float)((float)v65 * (float)v64)));
    v69.axis.mat[2].z = (float)((float)((float)(p_localAxis->mat[1].x * (float)v49)
                                      + (float)(p_localAxis->mat[0].x * (float)v50))
                              + (float)(p_localAxis->mat[2].x * (float)-v43))
                      * (float)((float)-(float)((float)((float)((float)((float)v65 * (float)v64)
                                                              * (float)((float)((float)((float)v59 * (float)v59)
                                                                              + (float)((float)((float)v58 * (float)v58)
                                                                                      + (float)((float)v57 * (float)v57)))
                                                                      * (float)0.5))
                                                      * (float)((float)v65 * (float)v64))
                                              - (float)1.5)
                              * (float)((float)v65 * (float)v64));
    v39 = (float)((float)v57
                * (float)((float)-(float)((float)((float)((float)((float)v65 * (float)v64)
                                                        * (float)((float)((float)((float)v59 * (float)v59)
                                                                        + (float)((float)((float)v58 * (float)v58)
                                                                                + (float)((float)v57 * (float)v57)))
                                                                * (float)0.5))
                                                * (float)((float)v65 * (float)v64))
                                        - (float)1.5)
                        * (float)((float)v65 * (float)v64)));
    *(float *)&v69.axisValid = (float)v57
                             * (float)((float)-(float)((float)((float)((float)((float)v65 * (float)v64)
                                                                     * (float)((float)((float)((float)v59 * (float)v59)
                                                                                     + (float)((float)((float)v58 * (float)v58)
                                                                                             + (float)((float)v57 * (float)v57)))
                                                                             * (float)0.5))
                                                             * (float)((float)v65 * (float)v64))
                                                     - (float)1.5)
                                     * (float)((float)v65 * (float)v64));
    v40 = (float)((float)v58
                * (float)((float)-(float)((float)((float)((float)((float)v65 * (float)v64)
                                                        * (float)((float)((float)((float)v59 * (float)v59)
                                                                        + (float)((float)((float)v58 * (float)v58)
                                                                                + (float)((float)v57 * (float)v57)))
                                                                * (float)0.5))
                                                * (float)((float)v65 * (float)v64))
                                        - (float)1.5)
                        * (float)((float)v65 * (float)v64)));
    v71 = (float)((float)((float)((float)-(float)((float)((float)((float)((float)v65 * (float)v64)
                                                                * (float)((float)((float)((float)v59 * (float)v59)
                                                                                + (float)((float)((float)v58 * (float)v58)
                                                                                        + (float)((float)v57 * (float)v57)))
                                                                        * (float)0.5))
                                                        * (float)((float)v65 * (float)v64))
                                                - (float)1.5)
                                * (float)((float)v65 * (float)v64))
                        * (float)((float)((float)v59 * (float)v59)
                                + (float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57))))
                * (float)-(float)((float)((float)v24 * (float)0.5) - (float)*(__int64 *)((char *)&v24 + 4)))
        * (float)0.001;
    v70 = (float)v58
        * (float)((float)-(float)((float)((float)((float)((float)v65 * (float)v64)
                                                * (float)((float)((float)((float)v59 * (float)v59)
                                                                + (float)((float)((float)v58 * (float)v58)
                                                                        + (float)((float)v57 * (float)v57)))
                                                        * (float)0.5))
                                        * (float)((float)v65 * (float)v64))
                                - (float)1.5)
                * (float)((float)v65 * (float)v64));
    do
    {
      *++v52 = *(_DWORD *)++p_y;
      --v51;
    }
    while ( v51 != 0 );
    v66 = idRotation::ToMat3(this: (idRotation *)&v69.axis.mat[1].z);
    idMat3::operator*=(this: &v74, a: v66);
    idMat3::operator*=(this: &v74, a: &this->physicsObj.current.localAxis);
    this->dest_angles.roll = 0.0;
    this->dest_angles.yaw = 0.0;
    p_dest_angles->pitch = 0.0;
    this->dest_quat = *idMat3::ToQuat(this: (idMat3 *)&v69.vec.y, result: (idQuat *)&v74);
  }
  else
  {
    v29 = -v69.axis.mat[0].y;
    v30 = -v69.axis.mat[0].z;
    v31 = -v69.axis.mat[1].x;
    v32 = this->dest_quat.y;
    v33 = this->dest_quat.z;
    v34 = (float)-(float)((float)(this->dest_quat.y * (float)v30)
                        - (float)((float)(this->dest_quat.w * v69.axis.mat[1].y)
                                - (float)(this->dest_quat.x * (float)v29)));
    v35 = (float)((float)(this->dest_quat.w * (float)v31)
                + (float)((float)(this->dest_quat.z * v69.axis.mat[1].y) + (float)(this->dest_quat.x * (float)v30)));
    v36 = (float)((float)(this->dest_quat.w * (float)v29)
                + (float)((float)(this->dest_quat.x * v69.axis.mat[1].y) + (float)(this->dest_quat.y * (float)v31)));
    v69.origin.y = -(float)((float)(this->dest_quat.x * (float)v31)
                          - (float)((float)(this->dest_quat.z * (float)v29)
                                  + (float)((float)(this->dest_quat.w * (float)v30)
                                          + (float)(this->dest_quat.y * v69.axis.mat[1].y))));
    v69.vec.x = -(float)((float)((float)v33 * (float)v31) - (float)v34);
    v69.origin.z = -(float)((float)((float)v32 * (float)v29) - (float)v35);
    v69.origin.x = -(float)((float)((float)v33 * (float)v30) - (float)v36);
    idQuat::ToRotation(this: &v75, result: &v69);
    v37 = (float)(v78 * (float)v28);
    v78 = v37;
    v79 = 0;
    w = v75.w;
    v39 = v76;
    v40 = v77;
  }
  v67 = this->move_time;
  this->rot.stage = v16;
  this->rot.acceleration = v18;
  this->rot.deceleration = v17;
  this->rot.movetime = v67 - v17 - v18;
  this->rot.vec.x = w;
  this->rot.vec.y = v39;
  this->rot.vec.z = v40;
  this->rot.speed = v37;
  idMoverMM::Event_ReachedAng(this: (idMoverMM *)&v68, result: this);
}


// ========================================================================
// ?Event_TeamBlocked@idMoverMM@@AAA?AVeventVoid@@PAVidEntity@@0@Z
// EA  : 0x82C82150
// RVA : 0x00C82150
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_TeamBlocked(
        idMoverMM *this,
        eventVoid *result,
        idEntity *blockedEntity,
        idEntity *blockingEntity)
{
  char *data; // r30
  char *v6; // r29
  const char *v7; // r28
  int v8; // r3

  if ( g_debugMover.valueInteger != 0 )
  {
    data = blockingEntity->name.data;
    v6 = blockedEntity->name.data;
    v7 = *(const char **)&result[16];
    v8 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idLib::Printf(fmt: "%d: '%s' stopped due to team member '%s' blocked by '%s'\n", v8, v7, v6, data);
  }
  return this;
}


// ========================================================================
// ?Event_PartBlocked@idMoverMM@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82C821C8
// RVA : 0x00C821C8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_PartBlocked(idMoverMM *this, idEntity *result, idActor *blockingEntity)
{
  idActor *v8; // r3
  int v9; // r3
  idBaseHealth *v10; // r3
  int v11; // r3
  const idSoundShader *type; // r5
  char *data; // r30
  const char *v14; // r31
  int v15; // r3

  if ( result[9].renderModelInfo.next != nullptr )
  {
    _FP6 = (float)((float)((float)(*(float *)&result[8].removeNode.prev * *(float *)&result[8].removeNode.prev)
                         + (float)((float)(*(float *)&result[8].removeNode.owner * *(float *)&result[8].removeNode.owner)
                                 + (float)(*(float *)&result[8].removeNode.next * *(float *)&result[8].removeNode.next)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f7, f13 }
    if ( blockingEntity != nullptr )
    {
      if ( (unsigned __int8)idClass::IsType(this: blockingEntity, superclass: &idActor::Type) != 0 )
      {
        v8 = idActor::CastTo(c: blockingEntity);
        if ( v8 != nullptr )
        {
          v9 = (int)v8->GetHealthComponent(this: v8);
          if ( v9 != 0 && (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v9 + 88))(a1: v9) == 0 )
            idEntity::StartSoundShader(
              this: result,
              channel: SND_CHANNEL_ANY,
              shader: (const idSoundShader *)result[9].clipModelInfo.type,
              soundShaderFlags: (soundShaderFlags_t)0,
              peerMask: 0xFFu);
        }
      }
      if ( ((double (__fastcall *)(idActor *, idEntity *, idEntity *, idRenderModelInfo *, double))blockingEntity->Damage)(
             a1: blockingEntity,
             a2: result,
             a3: result,
             a4: result[9].renderModelInfo.next,
             a5: 1.0) > 0.0
        && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) > *(_DWORD *)&result[9].renderModelInfo.ownedByPresentable
        && (unsigned __int8)idClass::IsType(this: blockingEntity, superclass: &idActor::Type) != 0 )
      {
        v10 = blockingEntity->GetHealthComponent_2(this: blockingEntity);
        if ( v10 != nullptr && !v10->IsDead_Impl(this: v10) )
        {
          v11 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          type = (const idSoundShader *)result[9].clipModelInfo.type;
          *(_DWORD *)&result[9].renderModelInfo.ownedByPresentable = v11 + 500;
          idEntity::StartSoundShader(
            this: result,
            channel: SND_CHANNEL_ANY,
            shader: type,
            soundShaderFlags: (soundShaderFlags_t)0,
            peerMask: 0xFFu);
        }
      }
      if ( g_debugMover.valueInteger != 0 )
      {
        data = blockingEntity->name.data;
        v14 = result->name.data;
        v15 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        idLib::Printf(fmt: "%d: '%s' blocked by '%s'\n", v15, v14, data);
      }
    }
  }
  return this;
}


// ========================================================================
// ?Event_Crush@idMoverMM@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82C82450
// RVA : 0x00C82450
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_Crush(idMoverMM *this, idEntity *result, idActor *blockingEntity)
{
  idActor *v8; // r3
  int v9; // r3
  idActor *v10; // r3
  int v11; // r3
  int v12; // r3
  const idSoundShader *type; // r5
  char *data; // r30
  const char *v15; // r31
  int v16; // r3

  if ( result[9].renderModelInfo.next != nullptr )
  {
    _FP6 = (float)((float)((float)(*(float *)&result[8].removeNode.prev * *(float *)&result[8].removeNode.prev)
                         + (float)((float)(*(float *)&result[8].removeNode.owner * *(float *)&result[8].removeNode.owner)
                                 + (float)(*(float *)&result[8].removeNode.next * *(float *)&result[8].removeNode.next)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f7, f13 }
    if ( blockingEntity != nullptr )
    {
      if ( (unsigned __int8)idClass::IsType(this: blockingEntity, superclass: &idActor::Type) != 0 )
      {
        v8 = idActor::CastTo(c: blockingEntity);
        if ( v8 != nullptr )
        {
          v9 = (int)v8->GetHealthComponent(this: v8);
          if ( v9 != 0 && (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v9 + 88))(a1: v9) == 0 )
            idEntity::StartSoundShader(
              this: result,
              channel: SND_CHANNEL_ANY,
              shader: (const idSoundShader *)result[9].clipModelInfo.type,
              soundShaderFlags: (soundShaderFlags_t)0,
              peerMask: 0xFFu);
        }
      }
      if ( ((double (__fastcall *)(idActor *, idEntity *, idEntity *, idRenderModelInfo *, double))blockingEntity->Damage)(
             a1: blockingEntity,
             a2: result,
             a3: result,
             a4: result[9].renderModelInfo.next,
             a5: 1.0) > 0.0
        && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) > *(_DWORD *)&result[9].renderModelInfo.ownedByPresentable
        && (unsigned __int8)idClass::IsType(this: blockingEntity, superclass: &idActor::Type) != 0 )
      {
        v10 = idActor::CastTo(c: blockingEntity);
        if ( v10 != nullptr )
        {
          v11 = (int)v10->GetHealthComponent(this: v10);
          if ( v11 != 0 && (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v11 + 88))(a1: v11) == 0 )
          {
            v12 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
            type = (const idSoundShader *)result[9].clipModelInfo.type;
            *(_DWORD *)&result[9].renderModelInfo.ownedByPresentable = v12 + 500;
            idEntity::StartSoundShader(
              this: result,
              channel: SND_CHANNEL_ANY,
              shader: type,
              soundShaderFlags: (soundShaderFlags_t)0,
              peerMask: 0xFFu);
          }
        }
      }
      if ( g_debugMover.valueInteger != 0 )
      {
        data = blockingEntity->name.data;
        v15 = result->name.data;
        v16 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        idLib::Printf(fmt: "%d: '%s' blocked by '%s'\n", v16, v15, data);
      }
    }
  }
  return this;
}


// ========================================================================
// ?Event_Speed@idMoverMM@@AAA?AVeventVoid@@M@Z
// EA  : 0x82C826E8
// RVA : 0x00C826E8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::Event_Speed(idMoverMM *this, eventVoid *result, double speed)
{
  if ( speed > 0.0 )
  {
    *(float *)&result[7236] = speed;
    *(_DWORD *)&result[7240] = 0;
  }
  else
  {
    idLib::Error(fmt: "Cannot set speed less than or equal to 0.", result);
  }
}


// ========================================================================
// ?Event_Time@idMoverMM@@AAA?AVeventVoid@@M@Z
// EA  : 0x82C82718
// RVA : 0x00C82718
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::Event_Time(idMoverMM *this, eventVoid *result, double time)
{
  if ( time > 0.0 )
  {
    *(float *)&result[7236] = 0.0;
    *(_DWORD *)&result[7240] = (int)(float)((float)1000.0 * (float)time);
  }
  else
  {
    idLib::Error(fmt: "Cannot set time less than or equal to 0.", result);
  }
}


// ========================================================================
// ?Event_AccelTime@idMoverMM@@AAA?AVeventVoid@@M@Z
// EA  : 0x82C82758
// RVA : 0x00C82758
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::Event_AccelTime(idMoverMM *this, eventVoid *result, double time)
{
  if ( time >= 0.0 )
    *(_DWORD *)&result[7248] = (int)(float)((float)1000.0 * (float)time);
  else
    idLib::Error(fmt: "Cannot set acceleration time less than 0.", result);
}


// ========================================================================
// ?Event_DecelTime@idMoverMM@@AAA?AVeventVoid@@M@Z
// EA  : 0x82C82790
// RVA : 0x00C82790
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::Event_DecelTime(idMoverMM *this, eventVoid *result, double time)
{
  if ( time >= 0.0 )
    *(_DWORD *)&result[7244] = (int)(float)((float)1000.0 * (float)time);
  else
    idLib::Error(fmt: "Cannot set deceleration time less than 0.", result);
}


// ========================================================================
// ?Event_MoveTo@idMoverMM@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82C827C8
// RVA : 0x00C827C8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_MoveTo(idMoverMM *this, idEntity *result, idEntity *ent)
{
  idPhysics *Physics; // r3
  const idVec3 *v7; // r3
  char v9; // [sp+50h] [-30h] BYREF

  if ( ent != nullptr && idEntity::GetPhysics(this: ent) != nullptr )
  {
    Physics = idEntity::GetPhysics(this: ent);
    v7 = Physics->GetOrigin(this: Physics, a2: 0);
    *(idEventReceiver *)&result[9].spawnOrientation.mat[2].y = idEntity::GetLocalCoordinates(
                                                                 this: (idEntity *)&v9,
                                                                 result,
                                                                 vec: v7)->idEventReceiver;
    result->__vftable[1].DormantBegin(this: result);
    return this;
  }
  else
  {
    idLib::Warning(fmt: "Entity not found");
    return this;
  }
}


// ========================================================================
// ?Event_MoveToPos@idMoverMM@@AAA?AVeventVoid@@ABVidVec3@@@Z
// EA  : 0x82C82878
// RVA : 0x00C82878
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_MoveToPos(idMoverMM *this, idEntity *result, const idVec3 *pos)
{
  float *LocalCoordinates; // r3
  char v7; // [sp+50h] [-30h] BYREF

  LocalCoordinates = (float *)idEntity::GetLocalCoordinates(this: (idEntity *)&v7, result, vec: pos);
  result[9].spawnOrientation.mat[2].y = *LocalCoordinates;
  result[9].spawnOrientation.mat[2].z = LocalCoordinates[1];
  *(float *)&result[9].flags = LocalCoordinates[2];
  result->__vftable[1].DormantBegin(this: result);
  return this;
}


// ========================================================================
// ?Event_Move@idMoverMM@@AAA?AVeventVoid@@MM@Z
// EA  : 0x82C828E8
// RVA : 0x00C828E8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_Move(idMoverMM *this, idMoverMM *result, double angle, double distance)
{
  double v7; // fp10
  double v8; // fp9
  double y; // fp7
  double z; // fp6
  float v12[4]; // [sp+50h] [-30h] BYREF

  idMoverMM::VectorForDir(this: result, angle, vec: (idVec3 *)result, a4: v12);
  v7 = (float)(v12[1] * (float)distance);
  v8 = (float)(v12[2] * (float)distance);
  y = result->physicsObj.current.localOrigin.y;
  z = result->physicsObj.current.localOrigin.z;
  result->dest_position.x = result->physicsObj.current.localOrigin.x + (float)(v12[0] * (float)distance);
  result->dest_position.y = (float)y + (float)v7;
  result->dest_position.z = (float)z + (float)v8;
  result->BeginMove(this: result);
  return this;
}


// ========================================================================
// ?Event_AccelTo@idMoverMM@@AAA?AVeventVoid@@MM@Z
// EA  : 0x82C82988
// RVA : 0x00C82988
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_AccelTo(idMoverMM *this, idEntity *result, double speed, double time)
{
  idPhysics_ParametricMM *p_bindMaster; // r30
  double v11; // fp2
  double v12; // fp3
  double v13; // fp2
  double v14; // fp31
  const idSoundShader *y_low; // r5
  eventVoid *p_z; // r27
  idLinkList<idEntity> *prev; // r31
  int v18; // r3
  float v20; // [sp+58h] [-88h] BYREF
  float v21; // [sp+5Ch] [-84h]
  float v22; // [sp+60h] [-80h]
  idVec3 v23; // [sp+68h] [-78h] BYREF
  idVec3 v24; // [sp+78h] [-68h] BYREF

  if ( time < 0.0 )
    idLib::Error(fmt: "idMover::Event_AccelTo: cannot set acceleration time less than 0.");
  p_bindMaster = (idPhysics_ParametricMM *)&result[6].bindInfo.bindMaster;
  ((void (__fastcall *)(float *, idEntity **, _DWORD))LODWORD(result[6].bindInfo.bindMaster->spawnOrientation.mat[2].z))(
    a1: &v20,
    a2: &result[6].bindInfo.bindMaster,
    a3: 0);
  _FP5 = (float)((float)((float)(v20 * v20) + (float)((float)(v22 * v22) + (float)(v21 * v21)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f12 }
  v11 = __frsqrte(_FP3);
  v12 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11
                                                                                      * (float)((float)((float)(v20 * v20) + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                                                              * (float)0.5))
                                                                              * (float)v11)
                                                                      - (float)1.5)
                                                      * (float)v11)
                                              * (float)((float)((float)(v20 * v20)
                                                              + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v11
                                                                              * (float)((float)((float)(v20 * v20)
                                                                                              + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                                                      * (float)0.5))
                                                                      * (float)v11)
                                                              - (float)1.5)
                                              * (float)v11))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v11
                                                      * (float)((float)((float)(v20 * v20)
                                                                      + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                              * (float)0.5))
                                              * (float)v11)
                                      - (float)1.5)
                      * (float)v11));
  v13 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11
                                                                                              * (float)((float)((float)(v20 * v20) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5))
                                                                                      * (float)v11)
                                                                              - (float)1.5)
                                                              * (float)v11)
                                                      * (float)((float)((float)(v20 * v20)
                                                                      + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v11
                                                                                      * (float)((float)((float)(v20 * v20) + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                                                              * (float)0.5))
                                                                              * (float)v11)
                                                                      - (float)1.5)
                                                      * (float)v11))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v11
                                                              * (float)((float)((float)(v20 * v20)
                                                                              + (float)((float)(v22 * v22)
                                                                                      + (float)(v21 * v21)))
                                                                      * (float)0.5))
                                                      * (float)v11)
                                              - (float)1.5)
                              * (float)v11))
              * (float)((float)((float)(v20 * v20) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5));
  v14 = (float)((float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12)
              * (float)((float)(v20 * v20) + (float)((float)(v22 * v22) + (float)(v21 * v21))));
  v20 = v20 * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12);
  v21 = v21 * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12);
  v22 = v22 * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12);
  if ( v14 == 0.0 )
    idLib::Error(fmt: "idMover::Event_AccelTo: not moving.");
  if ( v14 < speed )
  {
    result[8].activeNode.prev = (idLinkList<idEntity> *)SnapTimeToPhysicsFrame(t: (int)(float)((float)1000.0
                                                                                             * (float)time));
    y_low = (const idSoundShader *)LODWORD(result[9].clipModelInfo.size.y);
    result[8].activeNode.next = nullptr;
    LODWORD(result[9].renderModelInfo.scale.x) = 2;
    result[8].activeNode.owner = nullptr;
    result[8].removeNode.head = nullptr;
    idEntity::StartSoundShader(
      this: result,
      channel: SND_CHANNEL_BODY2,
      shader: y_low,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    idEntity::StartSoundShader(
      this: result,
      channel: SND_CHANNEL_BODY,
      shader: (const idSoundShader *)LODWORD(result[9].clipModelInfo.offset.x),
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    v24.x = v20 * (float)v14;
    v24.y = v21 * (float)v14;
    v24.z = v22 * (float)v14;
    p_z = (eventVoid *)&result[6].defaultPhysicsObj.current.worldOrigin.z;
    v23.x = (float)((float)speed - (float)v14) * v20;
    v23.y = v21 * (float)((float)speed - (float)v14);
    v23.z = v22 * (float)((float)speed - (float)v14);
    prev = result[8].activeNode.prev;
    gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v18 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idPhysics_ParametricMM::SetLinearExtrapolation(
      this: p_bindMaster,
      type: EXTRAPOLATION_ACCELLINEAR,
      currentTime: v18,
      duration: __SPAIR64__((unsigned int)prev, (unsigned int)p_z),
      base: &v23,
      speed: &v24);
  }
  return this;
}


// ========================================================================
// ?Event_DecelTo@idMoverMM@@AAA?AVeventVoid@@MM@Z
// EA  : 0x82C82BB0
// RVA : 0x00C82BB0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_DecelTo(idMoverMM *this, idEntity *result, double speed, double time)
{
  idPhysics_ParametricMM *p_bindMaster; // r30
  double v11; // fp2
  double v12; // fp3
  double v13; // fp2
  double v14; // fp31
  const idSoundShader *z_low; // r5
  eventVoid *p_z; // r27
  idLinkList<idEntity> *head; // r31
  int v18; // r3
  float v20; // [sp+58h] [-88h] BYREF
  float v21; // [sp+5Ch] [-84h]
  float v22; // [sp+60h] [-80h]
  idVec3 v23; // [sp+68h] [-78h] BYREF
  idVec3 v24; // [sp+78h] [-68h] BYREF

  if ( time < 0.0 )
    idLib::Error(fmt: "idMover::Event_DecelTo: cannot set deceleration time less than 0.");
  p_bindMaster = (idPhysics_ParametricMM *)&result[6].bindInfo.bindMaster;
  ((void (__fastcall *)(float *, idEntity **, _DWORD))LODWORD(result[6].bindInfo.bindMaster->spawnOrientation.mat[2].z))(
    a1: &v20,
    a2: &result[6].bindInfo.bindMaster,
    a3: 0);
  _FP5 = (float)((float)((float)(v20 * v20) + (float)((float)(v22 * v22) + (float)(v21 * v21)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f12 }
  v11 = __frsqrte(_FP3);
  v12 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11
                                                                                      * (float)((float)((float)(v20 * v20) + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                                                              * (float)0.5))
                                                                              * (float)v11)
                                                                      - (float)1.5)
                                                      * (float)v11)
                                              * (float)((float)((float)(v20 * v20)
                                                              + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v11
                                                                              * (float)((float)((float)(v20 * v20)
                                                                                              + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                                                      * (float)0.5))
                                                                      * (float)v11)
                                                              - (float)1.5)
                                              * (float)v11))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v11
                                                      * (float)((float)((float)(v20 * v20)
                                                                      + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                              * (float)0.5))
                                              * (float)v11)
                                      - (float)1.5)
                      * (float)v11));
  v13 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11
                                                                                              * (float)((float)((float)(v20 * v20) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5))
                                                                                      * (float)v11)
                                                                              - (float)1.5)
                                                              * (float)v11)
                                                      * (float)((float)((float)(v20 * v20)
                                                                      + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v11
                                                                                      * (float)((float)((float)(v20 * v20) + (float)((float)(v22 * v22) + (float)(v21 * v21)))
                                                                                              * (float)0.5))
                                                                              * (float)v11)
                                                                      - (float)1.5)
                                                      * (float)v11))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v11
                                                              * (float)((float)((float)(v20 * v20)
                                                                              + (float)((float)(v22 * v22)
                                                                                      + (float)(v21 * v21)))
                                                                      * (float)0.5))
                                                      * (float)v11)
                                              - (float)1.5)
                              * (float)v11))
              * (float)((float)((float)(v20 * v20) + (float)((float)(v22 * v22) + (float)(v21 * v21))) * (float)0.5));
  v14 = (float)((float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12)
              * (float)((float)(v20 * v20) + (float)((float)(v22 * v22) + (float)(v21 * v21))));
  v20 = v20 * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12);
  v21 = v21 * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12);
  v22 = v22 * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12);
  if ( v14 == 0.0 )
    idLib::Error(fmt: "idMover::Event_DecelTo: not moving.");
  if ( v14 > speed )
  {
    result[8].removeNode.head = (idLinkList<idEntity> *)SnapTimeToPhysicsFrame(t: (int)(float)((float)1000.0
                                                                                             * (float)time));
    z_low = (const idSoundShader *)LODWORD(result[9].clipModelInfo.size.z);
    LODWORD(result[9].renderModelInfo.scale.x) = 2;
    result[8].activeNode.next = (idLinkList<idEntity> *)2;
    result[8].activeNode.prev = nullptr;
    result[8].activeNode.owner = nullptr;
    idEntity::StartSoundShader(
      this: result,
      channel: SND_CHANNEL_BODY2,
      shader: z_low,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    idEntity::StartSoundShader(
      this: result,
      channel: SND_CHANNEL_BODY,
      shader: (const idSoundShader *)LODWORD(result[9].clipModelInfo.offset.x),
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    v24.x = v20 * (float)speed;
    v24.y = v21 * (float)speed;
    v24.z = v22 * (float)speed;
    p_z = (eventVoid *)&result[6].defaultPhysicsObj.current.worldOrigin.z;
    v23.x = (float)((float)v14 - (float)speed) * v20;
    v23.y = v21 * (float)((float)v14 - (float)speed);
    v23.z = v22 * (float)((float)v14 - (float)speed);
    head = result[8].removeNode.head;
    gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v18 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idPhysics_ParametricMM::SetLinearExtrapolation(
      this: p_bindMaster,
      type: EXTRAPOLATION_DECELLINEAR,
      currentTime: v18,
      duration: __SPAIR64__((unsigned int)head, (unsigned int)p_z),
      base: &v23,
      speed: &v24);
  }
  return this;
}


// ========================================================================
// ?Event_RotateDownTo@idMoverMM@@AAA?AVeventVoid@@HM@Z
// EA  : 0x82C82DD8
// RVA : 0x00C82DD8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_RotateDownTo(
        idMoverMM *this,
        eventVoid *result,
        unsigned int axis,
        double angle)
{
  idAngles *v8; // r3
  idAngles *v9; // r3
  float pitch; // r11
  float yaw; // r10
  float roll; // r9
  int v13; // r11
  double v14; // fp6
  double v15; // fp5
  int v17; // r5
  eventVoid *v18; // r4
  idMoverMM *v19; // r3
  double v20; // fp1
  idAngles v21; // [sp+50h] [-50h] BYREF
  idMat3 v22; // [sp+60h] [-40h] BYREF

  if ( axis > 2 )
  {
    idLib::Error(fmt: "Invalid axis");
    return (idMoverMM *)idMoverMM::Event_RotateUpTo(this: v19, result: v18, axis: v17, angle: v20);
  }
  else
  {
    v8 = idMat3::ToAngles(this: &v22, result: (idAngles *)&result[5396]);
    v9 = idAngles::Normalize180(this: v8);
    yaw = v9->yaw;
    roll = v9->roll;
    v21.pitch = v9->pitch;
    pitch = v21.pitch;
    v21.yaw = yaw;
    v21.roll = roll;
    *(&v21.pitch + axis) = angle;
    v22.mat[0].x = pitch;
    v22.mat[0].y = yaw;
    v22.mat[0].z = roll;
    idAngles::Normalize180(this: &v21);
    v13 = 4 * (axis + 1814);
    v14 = (float)(v21.yaw - v22.mat[0].y);
    v15 = (float)(v21.roll - v22.mat[0].z);
    *(float *)&result[7256] = v21.pitch - v22.mat[0].x;
    *(float *)&result[7260] = v14;
    *(float *)&result[7264] = v15;
    if ( *(float *)&result[v13] >= 0.0 )
      *(float *)&result[v13] = *(float *)&result[v13] - (float)360.0;
    (*(void (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 692))(a1: result, a2: 1);
    return this;
  }
}


// ========================================================================
// ?Event_RotateUpTo@idMoverMM@@AAA?AVeventVoid@@HM@Z
// EA  : 0x82C82EE8
// RVA : 0x00C82EE8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_RotateUpTo(idMoverMM *this, eventVoid *result, unsigned int axis, double angle)
{
  idAngles *v8; // r3
  idAngles *v9; // r3
  float pitch; // r11
  float yaw; // r10
  float roll; // r9
  int v13; // r11
  double v14; // fp6
  double v15; // fp5
  const idAngles *v17; // r5
  eventVoid *v18; // r4
  idMoverMM *v19; // r3
  idAngles v20; // [sp+50h] [-50h] BYREF
  idMat3 v21; // [sp+60h] [-40h] BYREF

  if ( axis > 2 )
  {
    idLib::Error(fmt: "Invalid axis");
    return (idMoverMM *)idMoverMM::Event_RotateTo(this: v19, result: v18, angles: v17);
  }
  else
  {
    v8 = idMat3::ToAngles(this: &v21, result: (idAngles *)&result[5396]);
    v9 = idAngles::Normalize180(this: v8);
    yaw = v9->yaw;
    roll = v9->roll;
    v20.pitch = v9->pitch;
    pitch = v20.pitch;
    v20.yaw = yaw;
    v20.roll = roll;
    *(&v20.pitch + axis) = angle;
    v21.mat[0].x = pitch;
    v21.mat[0].y = yaw;
    v21.mat[0].z = roll;
    idAngles::Normalize180(this: &v20);
    v13 = 4 * (axis + 1814);
    v14 = (float)(v20.yaw - v21.mat[0].y);
    v15 = (float)(v20.roll - v21.mat[0].z);
    *(float *)&result[7256] = v20.pitch - v21.mat[0].x;
    *(float *)&result[7260] = v14;
    *(float *)&result[7264] = v15;
    if ( *(float *)&result[v13] <= 0.0 )
      *(float *)&result[v13] = *(float *)&result[v13] + (float)360.0;
    (*(void (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 692))(a1: result, a2: 1);
    return this;
  }
}


// ========================================================================
// ?Event_RotateTo@idMoverMM@@AAA?AVeventVoid@@ABVidAngles@@@Z
// EA  : 0x82C82FF8
// RVA : 0x00C82FF8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_RotateTo(idMoverMM *this, eventVoid *result, const idAngles *angles)
{
  idAngles *v6; // r3
  idAngles *v7; // r3
  float yaw; // r9
  float roll; // r8
  float pitch; // r7
  float v11; // r6
  float v12; // r5
  double v13; // fp7
  double v14; // fp6
  idAngles v16; // [sp+50h] [-40h] BYREF
  idMat3 v17; // [sp+60h] [-30h] BYREF

  v6 = idMat3::ToAngles(this: &v17, result: (idAngles *)&result[5396]);
  v7 = idAngles::Normalize180(this: v6);
  yaw = angles->yaw;
  roll = angles->roll;
  pitch = v7->pitch;
  v11 = v7->yaw;
  v12 = v7->roll;
  v16.pitch = angles->pitch;
  v16.yaw = yaw;
  v16.roll = roll;
  v17.mat[0].x = pitch;
  v17.mat[0].y = v11;
  v17.mat[0].z = v12;
  idAngles::Normalize180(this: &v16);
  v13 = (float)(v16.yaw - v17.mat[0].y);
  v14 = (float)(v16.roll - v17.mat[0].z);
  *(float *)&result[7256] = v16.pitch - v17.mat[0].x;
  *(float *)&result[7260] = v13;
  *(float *)&result[7264] = v14;
  (*(void (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 692))(a1: result, a2: 1);
  return this;
}


// ========================================================================
// ?Event_RotateToShortest@idMoverMM@@AAA?AVeventVoid@@ABVidAngles@@@Z
// EA  : 0x82C830B0
// RVA : 0x00C830B0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_RotateToShortest(idMoverMM *this, eventVoid *result, idQuat *angles)
{
  double yaw; // fp13
  double pitch; // fp0
  double roll; // fp12
  double v9; // fp11
  idAngles v11; // [sp+50h] [-40h] BYREF
  float v12; // [sp+5Ch] [-34h]
  idMat3 v13; // [sp+60h] [-30h] BYREF

  idMat3::ToQuat(this: &v13, result: (idQuat *)&result[5396]);
  idAngles::ToQuat(this: &v11, result: angles);
  yaw = v11.yaw;
  pitch = v11.pitch;
  roll = v11.roll;
  if ( (float)((float)(v11.roll * v13.mat[0].z)
             + (float)((float)(v11.pitch * v13.mat[0].x) + (float)(v11.yaw * v13.mat[0].y))) < 0.0 )
  {
    pitch = -pitch;
    yaw = -yaw;
    v11.pitch = pitch;
    roll = -roll;
    v11.yaw = yaw;
    v12 = -v12;
    v11.roll = roll;
  }
  v9 = v12;
  *(float *)&result[7268] = pitch;
  *(float *)&result[7272] = yaw;
  *(float *)&result[7276] = roll;
  *(float *)&result[7280] = v9;
  *(float *)&result[7264] = 0.0;
  *(float *)&result[7260] = 0.0;
  *(float *)&result[7256] = 0.0;
  (*(void (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 692))(a1: result, a2: 1);
  return this;
}


// ========================================================================
// ?Event_Rotate@idMoverMM@@AAA?AVeventVoid@@ABVidAngles@@@Z
// EA  : 0x82C83180
// RVA : 0x00C83180
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_Rotate(idMoverMM *this, eventVoid *result, const idAngles *angles)
{
  __int64 v6; // r11
  double yaw; // fp12
  double roll; // fp11

  (*(void (__fastcall **)(eventVoid *))(*(_DWORD *)result + 684))(a1: result);
  HIDWORD(v6) = *(_DWORD *)&result[7248];
  yaw = angles->yaw;
  roll = angles->roll;
  LODWORD(v6) = *(_DWORD *)&result[7240] - (HIDWORD(v6) + *(_DWORD *)&result[7244]) / 2;
  *(float *)&result[7256] = angles->pitch * (float)((float)v6 * (float)0.001);
  *(float *)&result[7260] = (float)yaw * (float)((float)v6 * (float)0.001);
  *(float *)&result[7264] = (float)roll * (float)((float)v6 * (float)0.001);
  (*(void (__fastcall **)(eventVoid *, _DWORD))(*(_DWORD *)result + 692))(a1: result, a2: 0);
  return this;
}


// ========================================================================
// ?Event_RotateOnce@idMoverMM@@AAA?AVeventVoid@@ABVidAngles@@@Z
// EA  : 0x82C83230
// RVA : 0x00C83230
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_RotateOnce(idMoverMM *this, eventVoid *result, const idAngles *angles)
{
  __int64 v6; // r11
  double yaw; // fp12
  double roll; // fp11

  (*(void (__fastcall **)(eventVoid *))(*(_DWORD *)result + 684))(a1: result);
  HIDWORD(v6) = *(_DWORD *)&result[7248];
  yaw = angles->yaw;
  roll = angles->roll;
  LODWORD(v6) = *(_DWORD *)&result[7240] - (HIDWORD(v6) + *(_DWORD *)&result[7244]) / 2;
  *(float *)&result[7256] = angles->pitch * (float)((float)v6 * (float)0.001);
  *(float *)&result[7260] = (float)yaw * (float)((float)v6 * (float)0.001);
  *(float *)&result[7264] = (float)roll * (float)((float)v6 * (float)0.001);
  (*(void (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 692))(a1: result, a2: 1);
  return this;
}


// ========================================================================
// ?Event_Bob@idMoverMM@@AAA?AVeventVoid@@MMABVidVec3@@@Z
// EA  : 0x82C832E0
// RVA : 0x00C832E0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_Bob(
        idMoverMM *this,
        eventVoid *result,
        double speed,
        double phase,
        const idVec3 *depth,
        int a6,
        float *a7)
{
  double v7; // fp10
  double v8; // fp9
  eventVoid *v11; // r29
  int v12; // r3
  int v14; // [sp+5Ch] [-34h]
  idVec3 v15; // [sp+60h] [-30h] BYREF

  v7 = (float)(a7[1] * (float)speed);
  v8 = (float)(a7[2] * (float)speed);
  v15.x = *a7 * (float)speed;
  v15.y = v7;
  v15.z = v8;
  v11 = result + 5384;
  v14 = (int)(float)((float)1000.0 / (float)speed);
  v12 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idPhysics_ParametricMM::SetLinearExtrapolation(
    this: (idPhysics_ParametricMM *)&result[5200],
    type: EXTRAPOLATION_DECELSINE|EXTRAPOLATION_NOSTOP,
    currentTime: v12,
    duration: __SPAIR64__(v14, (unsigned int)v11),
    base: &v15,
    speed: &vec3_origin);
  return this;
}


// ========================================================================
// ?Event_Sway@idMoverMM@@AAA?AVeventVoid@@MMABVidAngles@@@Z
// EA  : 0x82C83390
// RVA : 0x00C83390
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_Sway(
        idMoverMM *this,
        eventVoid *result,
        double speed,
        double phase,
        const idAngles *depth,
        int a6,
        float *a7)
{
  double v10; // fp7
  double v11; // fp4
  double v12; // fp30
  double v13; // fp2
  double v14; // fp1
  double v15; // fp10
  double x; // fp31
  int v17; // r3
  __int64 v18; // r10
  unsigned int v20; // [sp+54h] [-9Ch]
  idRotation v21; // [sp+60h] [-90h] BYREF

  v10 = a7[2];
  v11 = __fsqrts((float)((float)(a7[2] * a7[2]) + (float)((float)(*a7 * *a7) + (float)(a7[1] * a7[1]))));
  v12 = (float)((float)v11 / (float)speed);
  v13 = (float)((float)1.0 / (float)((float)0.70710677 * (float)((float)v11 / (float)speed)));
  v14 = (float)(*a7 * (float)((float)1.0 / (float)((float)0.70710677 * (float)((float)v11 / (float)speed))));
  v21.origin.y = a7[1] * (float)v13;
  v21.origin.x = v14;
  v21.origin.z = (float)v13 * (float)v10;
  idAngles::ToRotation(this: (idAngles *)&v21.vec.y, result: &v21);
  v15 = (float)((float)((float)v12 * (float)phase) * (float)1000.0);
  x = v21.axis.mat[1].x;
  v20 = (int)v15;
  v17 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  HIDWORD(v18) = &v21.axis;
  idPhysics_ParametricMM::SetAngularExtrapolation(
    this: (idPhysics_ParametricMM *)&result[5200],
    type: EXTRAPOLATION_DECELSINE|EXTRAPOLATION_NOSTOP,
    currentTime: v17,
    time: v20,
    duration: (int)(float)((float)v12 * (float)1000.0),
    base: (const idMat3 *)&result[5396],
    vec: v18,
    speed: x);
  return this;
}


// ========================================================================
// ?Event_AccelSound@idMoverMM@@AAA?AVeventVoid@@PBVidSoundShader@@@Z
// EA  : 0x82C83498
// RVA : 0x00C83498
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idMoverMM::Event_AccelSound@<r4>(idMoverMM *this@<r3>, int result@<r4>, const idSoundShader *sound@<r5>)
{
  *(_DWORD *)(result + 7448) = sound;
  return result;
}


// ========================================================================
// ?Event_DecelSound@idMoverMM@@AAA?AVeventVoid@@PBVidSoundShader@@@Z
// EA  : 0x82C834A0
// RVA : 0x00C834A0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idMoverMM::Event_DecelSound@<r4>(idMoverMM *this@<r3>, int result@<r4>, const idSoundShader *sound@<r5>)
{
  *(_DWORD *)(result + 7452) = sound;
  return result;
}


// ========================================================================
// ?Event_MoveSound@idMoverMM@@AAA?AVeventVoid@@PBVidSoundShader@@@Z
// EA  : 0x82C834A8
// RVA : 0x00C834A8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idMoverMM::Event_MoveSound@<r4>(idMoverMM *this@<r3>, int result@<r4>, const idSoundShader *sound@<r5>)
{
  *(_DWORD *)(result + 7456) = sound;
  return result;
}


// ========================================================================
// ?Event_EnableSplineAngles@idMoverMM@@AAA?AVeventVoid@@XZ
// EA  : 0x82C834B0
// RVA : 0x00C834B0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idMoverMM::Event_EnableSplineAngles(idMoverMM *this)
{
  __int64 result; // r4 OVERLAPPED

  *(_BYTE *)(result + 7320) = 1;
  return result;
}


// ========================================================================
// ?Event_DisableSplineAngles@idMoverMM@@AAA?AVeventVoid@@XZ
// EA  : 0x82C834C0
// RVA : 0x00C834C0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idMoverMM::Event_DisableSplineAngles(idMoverMM *this)
{
  __int64 result; // r4 OVERLAPPED

  *(_BYTE *)(result + 7320) = 0;
  return result;
}


// ========================================================================
// ?Event_RemoveInitialSplineAngles@idMoverMM@@AAA?AVeventVoid@@XZ
// EA  : 0x82C834D0
// RVA : 0x00C834D0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_RemoveInitialSplineAngles(idMoverMM *this, eventVoid *result)
{
  idPhysics_ParametricMM *v2; // r31
  idCurve_Spline<idVec3> *Spline; // r4
  idMat3 *v7; // r3
  const idMat3 *v8; // r29
  int v9; // r3
  __int64 v10; // r10
  _BYTE v11[16]; // [sp+50h] [-90h] BYREF
  idMat3 v12; // [sp+60h] [-80h] BYREF
  idMat3 v13; // [sp+90h] [-50h] BYREF

  v2 = (idPhysics_ParametricMM *)&result[5200];
  Spline = idPhysics_ParametricMM::GetSpline(this: (idPhysics_ParametricMM *)&result[5200]);
  if ( Spline != nullptr )
  {
    v7 = (idMat3 *)((int (__fastcall *)(_BYTE *, double))Spline->GetCurrentFirstDerivative)(a1: v11, a2: 0.0);
    idVec3::ToMat3(this: v12.mat, result: v7);
    v8 = idMat3::Inverse(this: &v13, result: &v12);
    v9 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    HIDWORD(v10) = &vec3_origin;
    idPhysics_ParametricMM::SetAngularExtrapolation(
      this: v2,
      type: EXTRAPOLATION_NONE,
      currentTime: v9,
      time: 0,
      duration: 0,
      base: v8,
      vec: v10,
      speed: 0.0);
  }
  else
  {
    idLib::Warning(fmt: "removeIntialSplineAngles called for '%s' before startSpline!", *(const char **)&result[16]);
  }
  return this;
}


// ========================================================================
// ?Event_StartSpline@idMoverMM@@IAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82C835B0
// RVA : 0x00C835B0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_StartSpline(idMoverMM *this, eventVoid *result, idEntity *splineEntity)
{
  if ( (*(unsigned __int8 (__fastcall **)(eventVoid *, idEntity *, _DWORD, double))(*(_DWORD *)result + 712))(
         a1: result,
         a2: splineEntity,
         a3: 0,
         a4: -1.0) != 0 )
    (*(void (__fastcall **)(eventVoid *, _DWORD))(*(_DWORD *)result + 720))(a1: result, a2: 0);
  return this;
}


// ========================================================================
// ?Event_TravelSpline@idMoverMM@@IAA?AVeventVoid@@PAVidEntity@@_N1@Z
// EA  : 0x82C83630
// RVA : 0x00C83630
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_TravelSpline(
        idMoverMM *this,
        eventVoid *result,
        idEntity *splineEntity,
        bool forward,
        bool setSplineAngle)
{
  (*(void (__fastcall **)(eventVoid *, idEntity *, double))(*(_DWORD *)result + 696))(
    a1: result,
    a2: splineEntity,
    a3: -1.0);
  return this;
}


// ========================================================================
// ?Event_PauseSpline@idMoverMM@@IAA?AVeventVoid@@_N@Z
// EA  : 0x82C83680
// RVA : 0x00C83680
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_PauseSpline(idMoverMM *this, idEntity *result, bool pause)
{
  idEntity *bindMaster; // r29
  int v7; // r3

  if ( pause )
  {
    idEntity::BecomeInactive(this: result, flags: 2);
  }
  else
  {
    bindMaster = result[6].bindInfo.bindMaster;
    v7 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    (*(void (__fastcall **)(idEntity **, int))&bindMaster->renderModelInfo.renderParms.granularity)(
      a1: &result[6].bindInfo.bindMaster,
      a2: v7);
    idEntity::BecomeActive(this: result, flags: 2);
  }
  return this;
}


// ========================================================================
// ?TravelSpline@idMoverMM@@UAA_NPAVidEntity@@M_N1@Z
// EA  : 0x82C83708
// RVA : 0x00C83708
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

int __fastcall idMoverMM::TravelSpline(
        idMoverMM *this,
        idEntity *splinePath,
        double startTime,
        bool forward,
        bool setSplineAngle,
        char a6)
{
  BOOL v6; // r29
  __int64 v11; // r10
  int v12; // r8
  int v13; // r7
  int v14; // r6
  const float *v15; // r5
  const float *v16; // r4
  double v17; // fp1
  const idList<splineMoverModifier_t,5> *splineMoverModifiers; // r11
  int v19; // r10
  int v20; // r11
  double v21; // fp31
  idPhysics_ParametricMM *p_physicsObj; // r31
  float *SplineDirection; // r3
  double v24; // fp11
  double v25; // fp9
  idPhysics_ParametricMM_vtbl *v26; // r30
  idMat3 *v27; // r3
  _DWORD v28[4]; // [sp+50h] [-80h] BYREF
  idMat3 v29; // [sp+60h] [-70h] BYREF

  this->forwardSpline = setSplineAngle;
  v6 = setSplineAngle;
  if ( ((unsigned __int8 (__fastcall *)(idMoverMM *))this->StartSpline)(a1: this) == 0 )
    return 0;
  this->HandleInitialModifiers(this, a2: nullptr);
  if ( !v6 )
  {
    v17 = idPhysics_ParametricMM::SetSplineContinue(
            this: &this->physicsObj,
            endPos: 0.0,
            a3: v16,
            a4: v15,
            a5: v14,
            a6: v13,
            a7: v12,
            a8: v11);
    splineMoverModifiers = this->splineMoverModifiers;
    if ( splineMoverModifiers != nullptr )
      v19 = splineMoverModifiers->num - 1;
    else
      v19 = 0;
    v20 = this->splineModifierIndex - 2;
    if ( v20 >= 0 )
    {
      if ( v20 > v19 )
        v20 = v19;
    }
    else
    {
      v20 = 0;
    }
    this->splineModifierIndex = v20;
    ((void (__fastcall *)(idPhysics_ParametricMM *, double))this->physicsObj.Activate)(a1: &this->physicsObj, a2: v17);
  }
  if ( a6 != 0 )
  {
    if ( v6 )
      v21 = 1.0;
    else
      v21 = -1.0;
    v28[1] = (int)startTime;
    p_physicsObj = &this->physicsObj;
    SplineDirection = (float *)idPhysics_ParametricMM::GetSplineDirection(
                                 this: (idPhysics_ParametricMM *)v28,
                                 result: p_physicsObj,
                                 time: (int)startTime);
    v24 = (float)(SplineDirection[2] * (float)v21);
    v25 = (float)(SplineDirection[1] * (float)v21);
    v29.mat[0].x = *SplineDirection * (float)v21;
    v29.mat[0].z = v24;
    v29.mat[0].y = v25;
    v26 = p_physicsObj->__vftable;
    v27 = idVec3::ToMat3(this: (idVec3 *)&v29.mat[1].y, result: &v29);
    v26->SetAxis(this: p_physicsObj, a2: v27, a3: -1);
  }
  return 1;
}


// ========================================================================
// ?Event_StopSpline@idMoverMM@@AAA?AVeventVoid@@XZ
// EA  : 0x82C83898
// RVA : 0x00C83898
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_StopSpline(idMoverMM *this, eventVoid *result, int a3, bool a4)
{
  idPhysics_ParametricMM::SetSpline(
    this: (idPhysics_ParametricMM *)&result[5200],
    spline: nullptr,
    startTime: 0,
    totalTime: 0.0,
    useSplineAngles: a4,
    startAtEnd: *(_BYTE *)&result[7320],
    startSplineTime: -1.0,
    a8: 0);
  *(_DWORD *)&result[7296] = 0;
  *(_DWORD *)&result[7300] = 0;
  return this;
}


// ========================================================================
// ?Event_IsDone@idMoverMM@@AAA?AVeventBool@@XZ
// EA  : 0x82C83908
// RVA : 0x00C83908
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_IsDone(idMoverMM *this, eventBool *result)
{
  char SplineAtRest; // r3

  SplineAtRest = idPhysics_ParametricMM::GetSplineAtRest(this: (idPhysics_ParametricMM *)&result[5200]);
  eventBool::eventBool((eventBool *)this, b: SplineAtRest);
  return this;
}


// ========================================================================
// ?Event_EmitSmokeDecl@idMoverMM@@AAA?AVeventVoid@@PBVidDeclParticle@@HMABVidVec3@@@Z
// EA  : 0x82C83948
// RVA : 0x00C83948
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_EmitSmokeDecl(
        idMoverMM *this,
        idEntity *result,
        const idDeclParticle *decl,
        int timeOffsetSecs,
        double diversity,
        const idVec3 *offset,
        float *a7)
{
  idPhysics *Physics; // r3
  float *v13; // r3
  double v14; // fp9
  double v15; // fp7
  int v16; // r3
  int v17; // r31
  int v18; // r28
  idRenderModelEffects *MergeBranch; // r3
  int v21; // [sp+8h] [-A8h]
  int v22; // [sp+Ch] [-A4h]
  int v23; // [sp+10h] [-A0h]
  int v24; // [sp+14h] [-9Ch]
  int v25; // [sp+18h] [-98h]
  int v26; // [sp+1Ch] [-94h]
  int v27; // [sp+20h] [-90h]
  int v28; // [sp+24h] [-8Ch]
  int v29; // [sp+28h] [-88h]
  int v30; // [sp+2Ch] [-84h]
  int v31; // [sp+30h] [-80h]
  int v32; // [sp+34h] [-7Ch]
  int v33; // [sp+38h] [-78h]
  int v34; // [sp+3Ch] [-74h]
  int v35; // [sp+40h] [-70h]
  int v36; // [sp+44h] [-6Ch]
  int v37; // [sp+48h] [-68h]
  int v38; // [sp+4Ch] [-64h]
  int v39; // [sp+50h] [-60h]
  unsigned int v40; // [sp+60h] [-50h] BYREF
  idMat3 v41; // [sp+68h] [-48h] BYREF

  if ( decl != nullptr )
  {
    Physics = idEntity::GetPhysics(this: result);
    v13 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v14 = (float)(v13[2] + a7[2]);
    v15 = (float)(v13[1] + a7[1]);
    v41.mat[0].x = *v13 + *a7;
    v41.mat[0].z = v14;
    v41.mat[0].y = v15;
    v16 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v40 = -1;
    v17 = v16 + 1000 * timeOffsetSecs;
    v18 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
    idRenderModelEffects::AddParticles(
      this: MergeBranch,
      particle: decl,
      systemStartTime: v17,
      gameMsPerFrame: v18,
      diversity,
      origin: (const idVec3 *)allocationCurrent[242],
      axis: &v41,
      velocity: mat3_identity.mat,
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
  return this;
}


// ========================================================================
// ?SetSplineOffset@idMoverMM@@UAAXVidVec3@@M@Z
// EA  : 0x82C83A58
// RVA : 0x00C83A58
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::SetSplineOffset(
        idMoverMM *this,
        idVec3 *newOffset,
        double splinePos,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8)
{
  LODWORD(a8) = newOffset;
  idPhysics_ParametricMM::SetLocalOffset(
    this: &this->physicsObj,
    newOffset,
    startTime: this->physicsObj.current.length,
    duration: splinePos,
    a5: __ROL4__(newOffset, 32),
    a6: a5,
    a7: a6,
    a8: a7,
    a9: a8);
}


// ========================================================================
// ?SetSplineOffsetScale@idMoverMM@@UAAXVidVec3@@M@Z
// EA  : 0x82C83A98
// RVA : 0x00C83A98
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::SetSplineOffsetScale(
        idMoverMM *this,
        idVec3 *newScale,
        double splinePos,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8)
{
  idPhysics_ParametricMM::SetLocalScale(
    this: &this->physicsObj,
    newScale,
    startTime: this->physicsObj.current.length,
    duration: (float)((float)splinePos - this->physicsObj.current.length),
    a5: __ROL4__(newScale, 32),
    a6: a5,
    a7: a6,
    a8: a7,
    a9: a8);
}


// ========================================================================
// ?UpdateMoverModifier@idMoverMM@@MAAXAAVidPhysics_ParametricMM@@AAHW4moverModifierFunction_t@@M_N@Z
// EA  : 0x82C83AD8
// RVA : 0x00C83AD8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::UpdateMoverModifier(
        idMoverMM *this,
        idPhysics_ParametricMM *physObj,
        int *modifierIndex,
        moverModifierFunction_t ignoreFlags,
        double lengthOffset,
        bool suppressScriptFunctions)
{
  idCurve_Spline<idVec3> *spline; // r11
  const idList<splineMoverModifier_t,5> *splineMoverModifiers; // r9
  int v10; // r11
  splineMoverModifier_t *list; // r9
  double length; // fp2
  double v13; // fp1
  splineMoverModifier_t *v14; // r4

  spline = this->spline;
  if ( spline != nullptr )
  {
    splineMoverModifiers = this->splineMoverModifiers;
    if ( splineMoverModifiers != nullptr )
    {
      v10 = *modifierIndex;
      if ( *modifierIndex >= 0 && v10 < splineMoverModifiers->num )
      {
        list = splineMoverModifiers->list;
        length = physObj->current.length;
        v13 = (float)(list[v10].length + (float)lengthOffset);
        v14 = &list[v10];
        if ( (float)(this->splineTotalLength + (float)0.1) < v13 )
          return;
        if ( this->forwardSpline )
        {
          if ( length >= v13 )
          {
            *modifierIndex = v10 + 1;
            ((void (__fastcall *)(idMoverMM *, splineMoverModifier_t *, idPhysics_ParametricMM *, moverModifierFunction_t))this->HandleMoverModifier)(
              a1: this,
              a2: v14,
              a3: physObj,
              a4: ignoreFlags);
            return;
          }
        }
        else if ( length <= v13 )
        {
          *modifierIndex = v10 - 1;
          ((void (__fastcall *)(idMoverMM *, splineMoverModifier_t *, idPhysics_ParametricMM *, moverModifierFunction_t))this->HandleMoverModifier)(
            a1: this,
            a2: v14,
            a3: physObj,
            a4: ignoreFlags);
          return;
        }
      }
      if ( (unsigned __int8)idPhysics_ParametricMM::GetSplineAtRest(this: physObj) != 0
        && g_debugMoverModifiers.valueInteger != 0 )
      {
        idLib::Printf(fmt: "Setting Mover \"%s\" to rest.", this->name.data);
      }
    }
  }
}


// ========================================================================
// ?HandleMoverModifier_Oscillation@idMoverMM@@MAAXABUsplineMoverModifier_t@@AAVidPhysics_ParametricMM@@MM@Z
// EA  : 0x82C83C28
// RVA : 0x00C83C28
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMoverMM::HandleMoverModifier_Oscillation(
        idMoverMM *this,
        const splineMoverModifier_t *mod,
        __int64 physObj,
        double currentSplinePosition,
        double splineTotalLength)
{
  int v5; // r2 OVERLAPPED
  idClientGame *v7; // r3
  __int64 v8; // r4
  double y; // fp4
  double x; // fp5
  double v11; // fp3
  double v12; // fp2
  double v13; // fp9
  double v14; // fp6
  double v15; // fp5
  double v16; // fp3
  double v17; // fp2
  double v18; // fp1
  __int64 v19; // fp8
  double v20; // fp11
  double v21; // fp12
  double v22; // fp9
  double v23; // fp4
  double v24; // fp10
  double v25; // fp5
  double v26; // fp8
  unsigned int v27; // r6
  __int64 v28; // r6
  __int64 v29; // [sp+60h] [-40h]
  __int64 v30; // [sp+60h] [-40h]
  float v31; // [sp+68h] [-38h]
  float v32; // [sp+6Ch] [-34h]
  __int64 v33; // [sp+78h] [-28h]

  if ( mod->Oscillation.setNewOscillation )
  {
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    v7 = clientGame;
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    LODWORD(physObj) = (v7->random.seed >> 10) & 0x7FFF;
    HIDWORD(v8) = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = HIDWORD(v8);
    LODWORD(v8) = (HIDWORD(v8) >> 10) & 0x7FFF;
    y = mod->Oscillation.rangeRand.y;
    x = mod->Oscillation.rangeRand.x;
    v11 = mod->Oscillation.range.x;
    v12 = mod->Oscillation.range.y;
    v13 = (double)v8;
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    LODWORD(v8) = clientGame;
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    LODWORD(v8) = (*(_DWORD *)v8 >> 10) & 0x7FFF;
    HIDWORD(v8) = clientGame;
    v31 = (float)v11 + (float)((float)((float)v13 * (float)0.000030518509) * (float)x);
    v14 = (float)v8;
    v32 = (float)v12 + (float)((float)y * (float)((float)physObj * (float)0.000030518509));
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    v15 = mod->Oscillation.rangeRand.y;
    v16 = mod->Oscillation.periodRand.x;
    HIDWORD(v8) = (*(_DWORD *)HIDWORD(v8) >> 10) & 0x7FFF;
    LODWORD(v8) = 1664525 * clientGame->random.seed + 1013904223;
    v17 = mod->Oscillation.period.y;
    v18 = mod->Oscillation.period.x;
    v29 = *(_QWORD *)(&v5 - 1);
    clientGame->random.seed = v8;
    HIDWORD(v8) = v8;
    LODWORD(v8) = ((unsigned int)v8 >> 10) & 0x7FFF;
    v19 = v29;
    v30 = v8;
    HIDWORD(v8) = clientGame;
    clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
    v20 = (float)((float)v15 * (float)((float)v14 * (float)0.000030518509));
    HIDWORD(v8) = (*(_DWORD *)HIDWORD(v8) >> 10) & 0x7FFF;
    v21 = (float)((float)v19 * (float)0.000030518509);
    v22 = (float)*(__int64 *)(&v5 - 1);
    HIDWORD(v8) = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = HIDWORD(v8);
    v23 = mod->Oscillation.phaseShiftRnd.x;
    LODWORD(v8) = (HIDWORD(v8) >> 10) & 0x7FFF;
    v24 = mod->Oscillation.phaseShiftRnd.y;
    v25 = (float)v8;
    v26 = (float)(mod->Oscillation.phaseShiftRnd.z * (float)((float)v30 * (float)0.000030518509));
    v27 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v27;
    HIDWORD(v8) = (v27 >> 10) & 0x7FFF;
    *((float *)&v33 + 1) = (float)v17 + (float)v20;
    *(float *)&v33 = (float)v18 + (float)((float)v21 * (float)v16);
    v28 = v33;
    *(float *)&v33 = (float)(mod->Oscillation.phaseShift.x
                           + (float)(mod->Oscillation.phaseShiftRndUni
                                   * (float)((float)*(__int64 *)(&v5 - 1) * (float)0.000030518509)))
                   + (float)((float)((float)v25 * (float)0.000030518509) * (float)v23);
    *((float *)&v33 + 1) = (float)(mod->Oscillation.phaseShift.y
                                 + (float)(mod->Oscillation.phaseShiftRndUni
                                         * (float)((float)*(__int64 *)(&v5 - 1) * (float)0.000030518509)))
                         + (float)((float)v24 * (float)((float)v22 * (float)0.000030518509));
    idPhysics_ParametricMM::SetOscillation(
      this: (idPhysics_ParametricMM *)LODWORD(v31),
      range: (idVec3 *)LODWORD(v32),
      period: (idVec3 *)HIDWORD(v28),
      phaseShift: (idVec3 *)v28,
      zAxisPointsToLocalOrigin: v33,
      a6: __ROL4__(
        (float)(mod->Oscillation.phaseShift.z
              + (float)(mod->Oscillation.phaseShiftRndUni * (float)((float)*(__int64 *)(&v5 - 1) * (float)0.000030518509)))
      + (float)v26,
        32),
      a7: mod->Oscillation.zAxisPointsToLocalOrigin);
  }
}


// ========================================================================
// ?GetBestSoundEmitter@idMoverMM@@IAAPAVidSoundEmitter@@PAVidEntity@@@Z
// EA  : 0x82C83F78
// RVA : 0x00C83F78
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idSoundEmitter *__fastcall idMoverMM::GetBestSoundEmitter(idMoverMM *this, idEntity *ent)
{
  idSoundEmitter *result; // r3
  idSoundEmitter *SoundEmitter; // r31

  if ( ent == nullptr
    || idEntity::GetSoundEmitter(this: ent, alloc: true) == nullptr
    || (result = idEntity::GetSoundEmitter(this: ent, alloc: false)) == nullptr )
  {
    SoundEmitter = idEntity::GetSoundEmitter(this, alloc: true);
    if ( SoundEmitter == nullptr )
      idLib::Warning(fmt: "Unable to get sound emitter for mover: %s", this->name.data);
    return SoundEmitter;
  }
  return result;
}


// ========================================================================
// ?HandleMoverModifier_Script@idMoverMM@@MAAXABUsplineMoverModifier_t@@AAVidPhysics_ParametricMM@@MM@Z
// EA  : 0x82C84008
// RVA : 0x00C84008
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::HandleMoverModifier_Script(
        idMoverMM *this,
        const splineMoverModifier_t *mod,
        idPhysics_ParametricMM *physObj,
        double currentSplinePosition,
        double splineTotalLength)
{
  char *str; // r11
  char v8; // r11
  bool v9; // zf

  if ( g_debugMoverModifiers.valueInteger != 0 )
    idLib::Printf(fmt: "Calling script function: %s\n ", mod->Script.scriptFunction.str);
  idSuperScriptSystem::InvokeNamedFunction(this: &gameLocal->superScript, callStr: mod->Script.scriptFunction.str);
  str = (char *)mod->Script.notifyData.str;
  if ( str == &byte_8200D768 || (v9 = *str != 0, v8 = 0, !v9) )
    v8 = 1;
  if ( v8 == 0 )
    idEntity::SendNotify_OnMoverNotify(this, message: (char *)mod->Script.notifyData.str);
}


// ========================================================================
// ?HandleMoverModifier_Pause@idMoverMM@@MAAXABUsplineMoverModifier_t@@AAVidPhysics_ParametricMM@@MM@Z
// EA  : 0x82C840B8
// RVA : 0x00C840B8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::HandleMoverModifier_Pause(
        idMoverMM *this,
        const splineMoverModifier_t *mod,
        idPhysics_ParametricMM *physObj,
        double currentSplinePosition,
        double splineTotalLength)
{
  idPhysics_ParametricMM::PauseParametricUntil(
    this: physObj,
    resumeTime: (int)(float)((float)1000.0 * mod->Pause.pauseTime) + physObj->current.time);
  if ( g_debugMoverModifiers.valueInteger != 0 )
    idLib::Printf(
      fmt: "Pausing for %f. Will resume at gametime: %d\n ",
      mod->Pause.pauseTime,
      (unsigned int)COERCE_UNSIGNED_INT64(mod->Pause.pauseTime));
}


// ========================================================================
// ?HandleMoverModifier_Reverse@idMoverMM@@MAAXABUsplineMoverModifier_t@@AAVidPhysics_ParametricMM@@MM@Z
// EA  : 0x82C84148
// RVA : 0x00C84148
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::HandleMoverModifier_Reverse(
        idMoverMM *this,
        const splineMoverModifier_t *mod,
        idPhysics_ParametricMM *physObj,
        double currentSplinePosition,
        double splineTotalLength,
        int a6,
        int a7,
        int a8,
        __int64 a9)
{
  char v12; // r11
  int v13; // r11
  bool v14; // cr32

  if ( this->forwardSpline )
  {
    if ( mod->length == 0.0 )
      return;
  }
  else if ( mod->length == splineTotalLength )
  {
    return;
  }
  v12 = _cntlzw(this->forwardSpline);
  LODWORD(a9) = (v12 & 0x20) != 0;
  this->forwardSpline = a9;
  if ( (v12 & 0x20) != 0 )
  {
    idPhysics_ParametricMM::SetSplineContinue(
      this: physObj,
      endPos: splineTotalLength,
      a3: &mod->length,
      a4: (const float *)physObj,
      a5: a6,
      a6: a7,
      a7: a8,
      a8: a9);
    v13 = this->splineModifierIndex + 2;
    v14 = v13 < 0;
  }
  else
  {
    idPhysics_ParametricMM::SetSplineContinue(
      this: physObj,
      endPos: 0.0,
      a3: &mod->length,
      a4: (const float *)physObj,
      a5: a6,
      a6: a7,
      a7: a8,
      a8: a9);
    v13 = this->splineModifierIndex - 2;
    v14 = v13 < 0;
  }
  if ( v14 )
  {
    v13 = 0;
  }
  else if ( v13 > this->splineMoverModifiers->num - 1 )
  {
    v13 = this->splineMoverModifiers->num - 1;
  }
  this->splineModifierIndex = v13;
  if ( (this->modifierIgnoreFlags & 4) == 0 )
    this->HandleNextMoverModifier_Orientation(
      this,
      a2: &this->physicsObj,
      a3: currentSplinePosition,
      a4: splineTotalLength);
  if ( (this->modifierIgnoreFlags & 2) == 0 )
    this->HandleNextMoverModifier_Speed(this, a2: &this->physicsObj, a3: currentSplinePosition, a4: splineTotalLength);
  if ( (this->modifierIgnoreFlags & 8) == 0 )
    this->HandleNextMoverModifier_Offset(this, a2: &this->physicsObj, a3: currentSplinePosition, a4: splineTotalLength);
}


// ========================================================================
// ?Event_GetNumSplineChildren@idSplinePathMM@@QBA?AVeventInt@@XZ
// EA  : 0x82C84380
// RVA : 0x00C84380
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idSplinePathMM *__fastcall idSplinePathMM::Event_GetNumSplineChildren(idSplinePathMM *this, eventInt *result)
{
  eventInt::eventInt((eventInt *)this, i: result[248].value);
  return this;
}


// ========================================================================
// ?Event_GetSplineLength@idSplinePathMM@@QBA?AVeventFloat@@XZ
// EA  : 0x82C843B8
// RVA : 0x00C843B8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idSplinePathMM *__fastcall idSplinePathMM::Event_GetSplineLength(idSplinePathMM *this, eventFloat *result)
{
  eventFloat::eventFloat((eventFloat *)this, f: result[245].value);
  return this;
}


// ========================================================================
// ??0idMoverAttachment@@QAA@XZ
// EA  : 0x82C843F8
// RVA : 0x00C843F8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverAttachment *__fastcall idMoverAttachment::idMoverAttachment(idMoverAttachment *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idMoverAttachment_vtbl *)&idMoverAttachment::`vftable';
  idAnimator_Channel::idAnimator_Channel(this: &this->channelAnimator);
  this->currentAnimationHandle.value = -1;
  this->endOfAnimationScriptFunction.str = &byte_8200D768;
  this->bindParentThinkFlags = 7;
  this->useAsVehicle = false;
  this->vehicleProps = nullptr;
  idAnimator_VehicleCar::idAnimator_VehicleCar(this: &this->vehicleAnimator);
  return this;
}


// ========================================================================
// __unwind$504199
// EA  : 0x82C8448C
// RVA : 0x00C8448C
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_504199()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$504200
// EA  : 0x82C844B4
// RVA : 0x00C844B4
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_504200()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 5200));
}


// ========================================================================
// ?UpdateMovement@idMoverAttachment@@AAAX_N@Z
// EA  : 0x82C84540
// RVA : 0x00C84540
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverAttachment::UpdateMovement(idMoverAttachment *this, bool applyAnimationDelta)
{
  idEntity *BindMaster; // r28
  int v5; // r31
  const idAnimStack *v6; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r31
  idPhysics *Physics; // r3
  float *v9; // r3
  double v10; // fp31
  double v11; // fp30
  double v12; // fp29
  idPhysics *v13; // r3
  idMat3 *p_deferredAxis; // r11
  char *v15; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  const idVec3 *v18; // r4
  idMoverAttachment *v19; // r3
  idMat3 *p_axis; // r11
  char *v21; // r10
  _DWORD *v22; // r11
  int j; // ctr
  float v24[4]; // [sp+50h] [-180h] BYREF
  idVec3 v25; // [sp+60h] [-170h] BYREF
  float v26[4]; // [sp+70h] [-160h] BYREF
  float v27[4]; // [sp+80h] [-150h] BYREF
  idVec3 v28; // [sp+90h] [-140h] BYREF
  idMat3 v29; // [sp+A0h] [-130h] BYREF
  idMat3 v30; // [sp+D0h] [-100h] BYREF
  char v31; // [sp+FCh] [-D4h] BYREF
  idMat3 v32; // [sp+100h] [-D0h] BYREF
  char v33; // [sp+12Ch] [-A4h] BYREF
  idMat3 v34; // [sp+130h] [-A0h] BYREF
  _BYTE v35[48]; // [sp+160h] [-70h] BYREF

  BindMaster = idEntity::GetBindMaster(this);
  v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v6 = this->GetAnimStack_2(this);
  if ( idAnimator_Channel::IsDone(this: &this->channelAnimator, stack: v6, curTime: v5) )
  {
    if ( BindMaster != nullptr )
    {
      idEntity::BecomeActive(this: BindMaster, flags: this->bindParentThinkFlags);
      *(_BYTE *)&BindMaster->flags &= ~0x20u;
    }
    *(_BYTE *)&this->flags &= ~0x20u;
  }
  else
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    idTreeAnimator::SetRemoveOriginRotation(this: TreeAnimatorFromPresentable, removeRotation: applyAnimationDelta);
    idTreeAnimator::SetRemoveOriginRotation(this: TreeAnimatorFromPresentable, removeRotation: applyAnimationDelta);
    if ( BindMaster != nullptr )
    {
      idTreeAnimator::GetLastOriginDeltas(this: TreeAnimatorFromPresentable, rot: &v34, trans: &v28);
      Physics = idEntity::GetPhysics(this: BindMaster);
      v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v10 = *v9;
      v11 = v9[1];
      v12 = v9[2];
      v13 = idEntity::GetPhysics(this: BindMaster);
      v13->GetAxis(this: v13, a2: 0);
      p_deferredAxis = &TreeAnimatorFromPresentable->deferredAxis;
      if ( !TreeAnimatorFromPresentable->useDeferredPosition )
        p_deferredAxis = &TreeAnimatorFromPresentable->g.axis;
      v15 = &v31;
      p_z = (_DWORD *)&p_deferredAxis[-1].mat[2].z;
      for ( i = 9; i != 0; --i )
      {
        ++p_z;
        v15 += 4;
        *(_DWORD *)v15 = *p_z;
      }
      idMat3::TransposeMultiply(this: &v29, result: &v34, b: &v32);
      BindMaster->SetAxis(this: BindMaster, a2: &v29);
      v18 = (const idVec3 *)v27;
      v19 = (idMoverAttachment *)BindMaster;
      v27[0] = (float)((float)(v29.mat[0].x * v28.x)
                     + (float)((float)(v29.mat[1].x * v28.y) + (float)(v29.mat[2].x * v28.z)))
             + (float)v10;
      v27[1] = (float)((float)(v29.mat[0].y * v28.x)
                     + (float)((float)(v29.mat[1].y * v28.y) + (float)(v29.mat[2].y * v28.z)))
             + (float)v11;
      v27[2] = (float)((float)(v29.mat[0].z * v28.x)
                     + (float)((float)(v29.mat[1].z * v28.y) + (float)(v29.mat[2].z * v28.z)))
             + (float)v12;
    }
    else
    {
      idTreeAnimator::GetLastOriginDeltas(this: TreeAnimatorFromPresentable, rot: &v32, trans: &v25);
      this->GetModelTransform(this, a2: (idVec3 *)v26, a3: (idMat3 *)v35);
      p_axis = &TreeAnimatorFromPresentable->deferredAxis;
      if ( !TreeAnimatorFromPresentable->useDeferredPosition )
        p_axis = &TreeAnimatorFromPresentable->g.axis;
      v21 = &v33;
      v22 = (_DWORD *)&p_axis[-1].mat[2].z;
      for ( j = 9; j != 0; --j )
      {
        ++v22;
        v21 += 4;
        *(_DWORD *)v21 = *v22;
      }
      idMat3::TransposeMultiply(this: &v30, result: &v32, b: &v34);
      this->SetAxis(this, a2: &v30);
      v18 = (const idVec3 *)v24;
      v19 = this;
      v24[0] = (float)((float)(v30.mat[0].x * v25.x)
                     + (float)((float)(v30.mat[1].x * v25.y) + (float)(v30.mat[2].x * v25.z)))
             + v26[0];
      v24[1] = v26[1]
             + (float)((float)(v30.mat[0].y * v25.x)
                     + (float)((float)(v30.mat[1].y * v25.y) + (float)(v30.mat[2].y * v25.z)));
      v24[2] = v26[2]
             + (float)((float)(v30.mat[0].z * v25.x)
                     + (float)((float)(v30.mat[1].z * v25.y) + (float)(v30.mat[2].z * v25.z)));
    }
    idEntity::SetOrigin(this: v19, org: v18);
  }
}


// ========================================================================
// ?PlayAnimation@idMoverAttachment@@QAAXABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@MPAVblendParms_t@@ABVidAtomicString@@2PAVidSplinePath@@M@Z
// EA  : 0x82C84868
// RVA : 0x00C84868
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverAttachment::PlayAnimation(
        idMoverAttachment *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *aliasAnim,
        double animRateScale,
        blendParms_t *blendParms,
        blendParms_t *preAnimationScriptFunction,
        const idAtomicString *postAnimationScriptFunction,
        idSplinePath *splinePath,
        double splineTransitionTime)
{
  int v13; // r29
  const idAnimStack *v14; // r3
  const blendParms_t *v15; // r7
  idEntity *BindMaster; // r3
  idEntity *v17; // r30
  blendParms_t v18; // [sp+50h] [-50h] BYREF

  idSuperScriptSystem::InvokeNamedFunction(this: &gameLocal->superScript, callStr: postAnimationScriptFunction->str);
  if ( aliasAnim->value != 0xFFFF && idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
  {
    blendParms_t::blendParms_t(this: &v18);
    if ( preAnimationScriptFunction == nullptr )
      preAnimationScriptFunction = &v18;
    v13 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v14 = this->GetAnimStack_2(this);
    if ( (unsigned __int8)idAnimator_Channel::PlayAnim(
                            this: &this->channelAnimator,
                            stack: v14,
                            ah: aliasAnim,
                            curTime: v13,
                            rateScale: animRateScale,
                            blendParms: v15,
                            blendOutDurationMS_: preAnimationScriptFunction,
                            leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                            a9: nullptr) != 0 )
    {
      this->currentAnimationHandle = (idHandle<unsigned short,enum invalidAliasHandle_t,65535>)aliasAnim->value;
      this->endOfAnimationScriptFunction.str = (const char *)splinePath->__vftable;
      idEntity::BecomeActive(this, flags: 4);
      *(_BYTE *)&this->flags |= 0x20u;
      BindMaster = idEntity::GetBindMaster(this);
      v17 = BindMaster;
      if ( BindMaster != nullptr )
      {
        this->bindParentThinkFlags = BindMaster->thinkFlags;
        idEntity::BecomeActive(this: BindMaster, flags: 7);
        *(_BYTE *)&v17->flags |= 0x20u;
      }
    }
  }
}


// ========================================================================
// ?ComputeAnimationTranslationDelta@idMoverAttachment@@QAA_NABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@ABVidStr@@HHAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C84998
// RVA : 0x00C84998
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

int __fastcall idMoverAttachment::ComputeAnimationTranslationDelta(
        idMoverAttachment *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *animAlias,
        const idStr *jointName,
        int startFrame,
        int endFrame,
        idVec3 *deltaTrans,
        idMat3 *firstFrameOrientation)
{
  idAnimStack *(__fastcall *GetAnimStack_2)(struct idMoverAttachment *); // r8
  int v14; // r3
  idTreeAnimator *v15; // r28
  int v17; // r29
  __int64 v18; // r8
  double v19; // fp28
  int v20; // r12
  idMD6Blend::configInfo_t *VisualOffset; // r3
  __int64 v22; // r9
  idTreeAnimator *JointIndex; // r3
  idJointMat *v24; // r29
  double v25; // fp31
  double v26; // fp30
  double v27; // fp29
  idMD6Blend::configInfo_t *v28; // r3
  __int64 v29; // r10
  double v30; // fp10
  double v31; // fp9
  _DWORD back_chain[20]; // [sp+0h] [-E0h]
  idJointMat v33; // [sp+50h] [-90h] BYREF

  GetAnimStack_2 = this->GetAnimStack_2;
  deltaTrans->x = 0.0;
  deltaTrans->y = 0.0;
  deltaTrans->z = 0.0;
  firstFrameOrientation->mat[2].z = 1.0;
  firstFrameOrientation->mat[1].y = 1.0;
  firstFrameOrientation->mat[0].x = 1.0;
  firstFrameOrientation->mat[1].z = 0.0;
  firstFrameOrientation->mat[0].z = 0.0;
  firstFrameOrientation->mat[0].y = 0.0;
  firstFrameOrientation->mat[2].y = 0.0;
  firstFrameOrientation->mat[2].x = 0.0;
  firstFrameOrientation->mat[1].x = 0.0;
  v14 = (int)GetAnimStack_2(this);
  v15 = *(idTreeAnimator **)(v14 + 4);
  if ( v15 == nullptr )
    return 0;
  v17 = idTreeAnimator::NumJoints(this: *(idTreeAnimator **)(v14 + 4));
  if ( v17 <= 0 )
    return 0;
  LODWORD(v18) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  HIDWORD(v18) = 3 * v17;
  *(_QWORD *)&v33.mat[2] = v18;
  v19 = (float)v18;
  ((void (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)back_chain + v20) = back_chain[0];
  VisualOffset = idTreeAnimator::GetVisualOffset(this: v15);
  LODWORD(v22) = startFrame;
  LODWORD(v33.mat[3]) = (int)(float)((float)v22 * (float)v19);
  if ( idTreeAnimator::GetSingleAnimFrame(
         this: v15,
         joints: &v33,
         animAlias,
         time: SLODWORD(v33.mat[3]),
         offset: (const idVec3 *)VisualOffset,
         removeOriginOffset: false) == nullptr )
    return 0;
  JointIndex = idTreeAnimator::GetJointIndex(
                 this: (idTreeAnimator *)&v33,
                 result: (idIndex<short,enum invalidJointIndex_t> *)v15,
                 jointName: jointName->data);
  if ( SHIWORD(JointIndex->__vftable) == NULL_JOINT_INDEX.value )
    return 0;
  v24 = &v33 + SHIWORD(JointIndex->__vftable);
  v25 = v24->mat[3];
  v26 = v24->mat[7];
  v27 = v24->mat[11];
  firstFrameOrientation->mat[0].x = v24->mat[0];
  firstFrameOrientation->mat[1].x = v24->mat[1];
  firstFrameOrientation->mat[2].x = v24->mat[2];
  firstFrameOrientation->mat[0].y = v24->mat[4];
  firstFrameOrientation->mat[1].y = v24->mat[5];
  firstFrameOrientation->mat[2].y = v24->mat[6];
  firstFrameOrientation->mat[0].z = v24->mat[8];
  firstFrameOrientation->mat[1].z = v24->mat[9];
  firstFrameOrientation->mat[2].z = v24->mat[10];
  v28 = idTreeAnimator::GetVisualOffset(this: v15);
  LODWORD(v29) = endFrame;
  LODWORD(v33.mat[3]) = (int)(float)((float)v29 * (float)v19);
  if ( idTreeAnimator::GetSingleAnimFrame(
         this: v15,
         joints: &v33,
         animAlias,
         time: SLODWORD(v33.mat[3]),
         offset: (const idVec3 *)v28,
         removeOriginOffset: false) == nullptr )
    return 0;
  v30 = (float)(v24->mat[7] - (float)v26);
  v31 = (float)(v24->mat[11] - (float)v27);
  deltaTrans->x = v24->mat[3] - (float)v25;
  deltaTrans->y = v30;
  deltaTrans->z = v31;
  return 1;
}


// ========================================================================
// ??1idMover@@UAA@XZ
// EA  : 0x82C84C20
// RVA : 0x00C84C20
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::~idMover(idMover *this, int a2, int a3)
{
  int v4; // [sp+50h] [-20h] BYREF

  this->__vftable = (idMover_vtbl *)&idMover::`vftable';
  idEntity::SetPhysics(this, phys: nullptr, a3);
  if ( this->presentable != nullptr )
    idMover::Event_DisableInfluence(this: (idMover *)&v4, result: this);
  idNavigationSpace::DestroySpace(this: &this->navigationSpace.navSpace);
  idNavigationSpace::~idNavigationSpace(this: &this->navigationSpace.navSpace);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->guiTargets);
  idStr::FreeData(this: &this->constraintName);
  idPhysics_Parametric::~idPhysics_Parametric(this: &this->physicsObj);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$505904
// EA  : 0x82C84CB8
// RVA : 0x00C84CB8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_505904()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$505905
// EA  : 0x82C84CE0
// RVA : 0x00C84CE0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_505905()
{
  int v0; // r12

  idPhysics_Parametric::~idPhysics_Parametric(this: (idPhysics_Parametric *)(*(_DWORD *)(v0 - 112 + 132) + 800));
}


// ========================================================================
// __unwind$505906
// EA  : 0x82C84D0C
// RVA : 0x00C84D0C
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_505906()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 2248));
}


// ========================================================================
// __unwind$505907
// EA  : 0x82C84D38
// RVA : 0x00C84D38
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_505907()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 2360));
}


// ========================================================================
// __unwind$505908
// EA  : 0x82C84D64
// RVA : 0x00C84D64
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_505908()
{
  int v0; // r12

  idMover::navSpace_t::~navSpace_t(this: (idMover::navSpace_t *)(*(_DWORD *)(v0 - 112 + 132) + 2376));
}


// ========================================================================
// ?Spawn@idMover@@QAAXXZ
// EA  : 0x82C84D98
// RVA : 0x00C84D98
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::Spawn(idMover *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3
  idAngles *v4; // r3
  idPhysics *v5; // r3
  idClipModel *v6; // r29
  idPhysics *v7; // r3
  const idClipModel *v8; // r3
  idClipModel *v9; // r3
  idClipModel *v10; // r28
  idPhysics *v11; // r3
  idPhysics_Parametric_vtbl *v12; // r27
  int v13; // r3
  idPhysics *v14; // r3
  idPhysics_Parametric_vtbl *v15; // r27
  int v16; // r3
  int v17; // r27
  const idDeclDamage *crushDamage; // r11
  int v19; // r5
  idPresentable *presentable; // r3
  int GameMs; // r3
  int v22; // r3
  int v23; // r5
  idPresentable *v24; // r11
  idRenderModel *model; // r10
  char v26; // r10
  bool v27; // zf
  __int64 v28; // r11
  idPhysics *v29; // r3
  float *v30; // r3
  idPhysics *v31; // r3
  const idSoundShader *v32; // r8
  idPresentable *v33; // r7
  float *v34; // r3
  double v35; // fp7
  idPresentable *v36; // r11
  idRenderModel *v37; // r10
  char v38; // r10
  highlightColor_t highlightColor; // r10
  idRenderModel *v40; // r9
  idPresentable *v41; // r4
  navLayer_t i; // r28
  const idDeclNavigation *DeclByLayer; // r5
  idMat3 v44[3]; // [sp+50h] [-70h] BYREF

  this->move_thread.value = 0;
  this->rotate_thread.value = 0;
  this->stopRotation = false;
  this->lastCommand = MOVER_NONE;
  Physics = idEntity::GetPhysics(this);
  this->dest_position = *Physics->GetOrigin(this: Physics, a2: 0);
  v3 = idEntity::GetPhysics(this);
  v4 = (idAngles *)v3->GetAxis(this: v3, a2: 0);
  this->dest_angles = *idMat3::ToAngles(this: v44, result: v4);
  idAngles::Normalize360(this: &this->dest_angles);
  v5 = idEntity::GetPhysics(this);
  if ( v5->GetNumClipModels(this: v5) <= 0 )
  {
    v10 = nullptr;
  }
  else
  {
    v6 = (idClipModel *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0xD8u,
                          tag: TAG_CLIPMODEL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    LODWORD(v44[0].mat[0].x) = v6;
    if ( v6 != nullptr )
    {
      v7 = idEntity::GetPhysics(this);
      v8 = v7->GetClipModel(this: v7, a2: 0);
      v9 = idClipModel::idClipModel(this: v6, clip: &clientGame->clip, model: v8);
    }
    else
    {
      v9 = nullptr;
    }
    v10 = v9;
  }
  idPhysics::InitPhysics(
    this: &this->physicsObj,
    clip_: &clientGame->clip,
    callbacks_: &this->physicsCallbacks,
    entityNumber_: this->entityNumber);
  ((void (__fastcall *)(idPhysics_Parametric *, idClipModel *, double))this->physicsObj.SetClipModel)(
    a1: &this->physicsObj,
    a2: v10,
    a3: 1.0);
  v11 = idEntity::GetPhysics(this);
  v12 = this->physicsObj.__vftable;
  v13 = (int)v11->GetOrigin(this: v11, a2: 0);
  v12->SetOrigin(this: &this->physicsObj, a2: (const idVec3 *)v13, a3: -1);
  v14 = idEntity::GetPhysics(this);
  v15 = this->physicsObj.__vftable;
  v16 = (int)v14->GetAxis(this: v14, a2: 0);
  v15->SetAxis(this: &this->physicsObj, a2: (const idMat3 *)v16, a3: -1);
  this->physicsObj.SetClipMask(this: &this->physicsObj, a2: 4194305, a3: -1);
  this->physicsObj.SetContents(this: &this->physicsObj, a2: this->solid, a3: -1);
  v17 = 1;
  if ( !this->noPush )
  {
    if ( v10 != nullptr )
    {
      crushDamage = this->crushDamage;
      if ( crushDamage == nullptr || (v19 = 16, !crushDamage->instantRagdoll) )
        v19 = 0;
      idPhysics_Parametric::SetPusher(this: &this->physicsObj, push: &clientGame->push, flags: v19);
      presentable = this->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      presentable->GetPusherInterface(this: presentable)->pushEnabled = true;
    }
    else
    {
      this->noPush = true;
      idGameLocal::MapError(
        this: gameLocal,
        fmt: "idMover::Spawn: mover '%s' has no clip model and noPush is set to false",
        this->name.data);
    }
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idPhysics_Parametric::SetLinearExtrapolation(
    this: &this->physicsObj,
    type: EXTRAPOLATION_NONE,
    currentTime: GameMs,
    duration: (unsigned int)&this->dest_position,
    base: &vec3_origin,
    speed: &vec3_origin);
  v22 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idPhysics_Parametric::SetAngularExtrapolation(
    this: &this->physicsObj,
    type: EXTRAPOLATION_NONE,
    currentTime: v22,
    duration: (unsigned int)&this->dest_angles,
    base: &ang_zero,
    speed: &ang_zero);
  idEntity::SetPhysics(this, phys: &this->physicsObj, a3: v23);
  if ( this->health != 0.0 )
    *(_BYTE *)&this->flags |= 2u;
  v24 = this->presentable;
  if ( v24 == nullptr
    || (model = v24->model, LODWORD(v44[0].mat[0].x) = this->presentable, v27 = model != nullptr, v26 = 1, !v27) )
  {
    v26 = 0;
  }
  if ( v26 != 0 )
  {
    if ( v24 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v24 = this->presentable;
    }
    v24->model->g.castDimShadows = DIMSHADOW_ON;
    idEntity::GetRenderModelFromPresentable(this)->useDeferredPosition = true;
  }
  LODWORD(v28) = this->move_time;
  HIDWORD(v28) = &unk_82390000;
  if ( (int)v28 < 1000 )
  {
    *(_QWORD *)&v44[0].mat[0].x = v28;
    this->move_time = (int)(float)((float)v28 * (float)1000.0);
  }
  LODWORD(v28) = this->acceltime;
  if ( (int)v28 < 1000 )
  {
    *(_QWORD *)&v44[0].mat[0].x = v28;
    this->acceltime = (int)(float)((float)v28 * (float)1000.0);
  }
  LODWORD(v28) = this->deceltime;
  if ( (int)v28 < 1000 )
  {
    *(_QWORD *)&v44[0].mat[0].x = v28;
    this->deceltime = (int)(float)((float)v28 * (float)1000.0);
  }
  v29 = idEntity::GetPhysics(this);
  v30 = (float *)v29->GetOrigin(this: v29, a2: 0);
  LODWORD(v44[0].mat[0].x) = &this->averageModelOrigin;
  this->averageModelOrigin.x = *v30;
  this->averageModelOrigin.y = v30[1];
  this->averageModelOrigin.z = v30[2];
  v31 = idEntity::GetPhysics(this);
  v34 = (float *)v31->GetAxis(this: v31, a2: 0);
  this->averageModelAxis.mat[0].x = *v34;
  this->averageModelAxis.mat[0].y = v34[1];
  this->averageModelAxis.mat[0].z = v34[2];
  LODWORD(v44[0].mat[0].x) = v34 + 3;
  this->averageModelAxis.mat[1].x = v34[3];
  LODWORD(v44[0].mat[0].x) = v34 + 6;
  v35 = v34[4];
  LODWORD(v44[0].mat[0].x) = &this->averageModelAxis.mat[2];
  this->averageModelAxis.mat[1].y = v35;
  this->averageModelAxis.mat[1].z = v34[5];
  this->averageModelAxis.mat[2].x = v34[6];
  this->averageModelAxis.mat[2].y = v34[7];
  this->averageModelAxis.mat[2].z = v34[8];
  v36 = this->presentable;
  if ( v36 == nullptr
    || (v37 = v36->model, LODWORD(v44[0].mat[0].x) = this->presentable, v27 = v37 != nullptr, v38 = 1, !v27) )
  {
    v38 = 0;
  }
  if ( v38 != 0 )
  {
    if ( v36 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v36 = this->presentable;
    }
    highlightColor = this->highlightColor;
    v40 = v36->model;
    v36->highlightColor = highlightColor;
    v40->g.highlightColor = highlightColor;
  }
  v41 = this->presentable;
  if ( v41 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v41 = this->presentable;
  }
  idInfluenceTrailManager::Enable(
    this: &clientGame->influenceTrailManager,
    presentable: v41,
    trail: &this->influence,
    sndFoliage: this->sndFoliage,
    a5: v33,
    a6: v32);
  if ( (gameLocal->GetGameFlags(this: gameLocal) & 2) == 0 && this->navigationSpace.navSpaceLayers != NavMask_None )
  {
    idNavigationSpace::CreateSpace(this: &this->navigationSpace.navSpace);
    for ( i = NAVLAYER_PLAYER; i < NAVLAYER_MAX; ++i )
    {
      if ( (this->navigationSpace.navSpaceLayers & v17) != 0 )
      {
        DeclByLayer = idDeclNavigation::FindDeclByLayer(layer: i);
        if ( DeclByLayer != nullptr )
          idGameLocal::LoadNavigationIntoSpace(
            this: gameLocal,
            space: &this->navigationSpace.navSpace,
            navigation: DeclByLayer,
            entName: this->name.data,
            instanced: false);
      }
      v17 = __ROL4__(v17, 1);
    }
  }
  idMover::UpdateNavigationSpace(this);
}


// ========================================================================
// __unwind$505967
// EA  : 0x82C853F4
// RVA : 0x00C853F4
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_505967()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?Think@idMover@@UAAXXZ
// EA  : 0x82C85420
// RVA : 0x00C85420
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::Think(idMover *this)
{
  idPhysics *Physics; // r3
  int GameMs; // r26
  idPresentable *presentable; // r27
  idInfluenceTrailManager *p_influenceTrailManager; // r28
  const idVec3 *v6; // r3
  const idVec3 *v7; // r3
  float x; // r7
  float y; // r6
  idVec3 *p_averageModelOrigin; // r30
  double v11; // fp29
  double v12; // fp31
  idPhysics *v13; // r3
  float *v14; // r3
  double v15; // fp8
  double v16; // fp7
  double v17; // fp4
  double v18; // fp3
  double v19; // fp10
  double v20; // fp8
  double v23; // fp12
  double v24; // fp12
  double v25; // fp5
  double v26; // fp4
  double v27; // fp2
  float z; // [sp+58h] [-98h]
  idMat3 v29; // [sp+60h] [-90h] BYREF

  Physics = idEntity::GetPhysics(this);
  this->lastOrigin = *Physics->GetOrigin(this: Physics, a2: 0);
  idEntity::Think(this);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  presentable = this->presentable;
  p_influenceTrailManager = &clientGame->influenceTrailManager;
  v6 = this->physicsObj.GetOrigin(this: &this->physicsObj, a2: 0);
  idInfluenceTrailManager::UpdatePosition(
    this: p_influenceTrailManager,
    trail: &presentable->influenceHandle,
    position: v6,
    time: GameMs);
  if ( this->smoothMovement != 0.0 )
  {
    v7 = this->physicsObj.GetOrigin(this: &this->physicsObj, a2: 0);
    x = v7->x;
    y = v7->y;
    p_averageModelOrigin = &this->averageModelOrigin;
    z = v7->z;
    v11 = v7->x;
    v12 = y;
    if ( (float)((float)((float)(x - this->lastOrigin.x) * (float)(x - this->lastOrigin.x))
               + (float)((float)((float)(z - this->lastOrigin.z) * (float)(z - this->lastOrigin.z))
                       + (float)((float)(y - this->lastOrigin.y) * (float)(y - this->lastOrigin.y)))) <= 16384.0 )
    {
      v15 = (float)(this->smoothMovement * this->averageModelOrigin.y);
      v16 = (float)(this->smoothMovement * this->averageModelOrigin.z);
      v17 = (float)(y * (float)((float)1.0 - this->smoothMovement));
      v18 = (float)(z * (float)((float)1.0 - this->smoothMovement));
      this->averageModelOrigin.x = (float)(this->averageModelOrigin.x * this->smoothMovement)
                                 + (float)((float)((float)1.0 - this->smoothMovement) * x);
      this->averageModelOrigin.y = (float)v15 + (float)v17;
      this->averageModelOrigin.z = (float)v16 + (float)v18;
    }
    else
    {
      this->averageModelOrigin.x = x;
      this->averageModelOrigin.y = y;
      this->averageModelOrigin.z = z;
      v13 = idEntity::GetPhysics(this);
      v14 = (float *)v13->GetAxis(this: v13, a2: 0);
      this->averageModelAxis.mat[0].x = *v14;
      this->averageModelAxis.mat[0].y = v14[1];
      this->averageModelAxis.mat[0].z = v14[2];
      this->averageModelAxis.mat[1].x = v14[3];
      this->averageModelAxis.mat[1].y = v14[4];
      this->averageModelAxis.mat[1].z = v14[5];
      this->averageModelAxis.mat[2].x = v14[6];
      this->averageModelAxis.mat[2].y = v14[7];
      this->averageModelAxis.mat[2].z = v14[8];
    }
    v19 = (float)((float)v12 - this->averageModelOrigin.y);
    v20 = (float)(z - this->averageModelOrigin.z);
    _FP2 = (float)((float)((float)((float)((float)v11 - p_averageModelOrigin->x)
                                 * (float)((float)v11 - p_averageModelOrigin->x))
                         + (float)((float)((float)(z - this->averageModelOrigin.z)
                                         * (float)(z - this->averageModelOrigin.z))
                                 + (float)((float)v19 * (float)v19)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f13, f2, f3, f13 }
    v23 = __frsqrte(_FP13);
    v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v23
                                                                                        * (float)((float)((float)((float)((float)v11 - p_averageModelOrigin->x) * (float)((float)v11 - p_averageModelOrigin->x)) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                                                                                                * (float)0.5))
                                                                                * (float)v23)
                                                                        - (float)1.5)
                                                        * (float)v23)
                                                * (float)((float)((float)((float)((float)v11 - p_averageModelOrigin->x)
                                                                        * (float)((float)v11 - p_averageModelOrigin->x))
                                                                + (float)((float)((float)v20 * (float)v20)
                                                                        + (float)((float)v19 * (float)v19)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v23
                                                                                * (float)((float)((float)((float)((float)v11 - p_averageModelOrigin->x) * (float)((float)v11 - p_averageModelOrigin->x))
                                                                                                + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                                                                                        * (float)0.5))
                                                                        * (float)v23)
                                                                - (float)1.5)
                                                * (float)v23))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v23
                                                        * (float)((float)((float)((float)((float)v11
                                                                                        - p_averageModelOrigin->x)
                                                                                * (float)((float)v11
                                                                                        - p_averageModelOrigin->x))
                                                                        + (float)((float)((float)v20 * (float)v20)
                                                                                + (float)((float)v19 * (float)v19)))
                                                                * (float)0.5))
                                                * (float)v23)
                                        - (float)1.5)
                        * (float)v23));
    v25 = (float)((float)-(float)((float)((float)((float)v24
                                                * (float)((float)((float)((float)((float)v11 - p_averageModelOrigin->x)
                                                                        * (float)((float)v11 - p_averageModelOrigin->x))
                                                                + (float)((float)((float)(z - this->averageModelOrigin.z)
                                                                                * (float)(z - this->averageModelOrigin.z))
                                                                        + (float)((float)v19 * (float)v19)))
                                                        * (float)0.5))
                                        * (float)v24)
                                - (float)1.5)
                * (float)v24);
    v26 = (float)((float)((float)-(float)((float)((float)((float)v24
                                                        * (float)((float)((float)((float)((float)v11
                                                                                        - p_averageModelOrigin->x)
                                                                                * (float)((float)v11
                                                                                        - p_averageModelOrigin->x))
                                                                        + (float)((float)((float)v20 * (float)v20)
                                                                                + (float)((float)v19 * (float)v19)))
                                                                * (float)0.5))
                                                * (float)v24)
                                        - (float)1.5)
                        * (float)v24)
                * (float)((float)((float)((float)v11 - p_averageModelOrigin->x)
                                * (float)((float)v11 - p_averageModelOrigin->x))
                        + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))));
    v27 = (float)((float)v19
                * (float)((float)-(float)((float)((float)((float)v24
                                                        * (float)((float)((float)((float)((float)v11
                                                                                        - p_averageModelOrigin->x)
                                                                                * (float)((float)v11
                                                                                        - p_averageModelOrigin->x))
                                                                        + (float)((float)((float)(z
                                                                                                - this->averageModelOrigin.z)
                                                                                        * (float)(z
                                                                                                - this->averageModelOrigin.z))
                                                                                + (float)((float)v19 * (float)v19)))
                                                                * (float)0.5))
                                                * (float)v24)
                                        - (float)1.5)
                        * (float)v24));
    v29.mat[0].x = (float)((float)v11 - p_averageModelOrigin->x)
                 * (float)((float)-(float)((float)((float)((float)v24
                                                         * (float)((float)((float)((float)((float)v11
                                                                                         - p_averageModelOrigin->x)
                                                                                 * (float)((float)v11
                                                                                         - p_averageModelOrigin->x))
                                                                         + (float)((float)((float)(z
                                                                                                 - this->averageModelOrigin.z)
                                                                                         * (float)(z
                                                                                                 - this->averageModelOrigin.z))
                                                                                 + (float)((float)v19 * (float)v19)))
                                                                 * (float)0.5))
                                                 * (float)v24)
                                         - (float)1.5)
                         * (float)v24);
    v29.mat[0].y = v27;
    v29.mat[0].z = (float)v20 * (float)v25;
    if ( v26 > 0.001 )
      this->averageModelAxis = *idVec3::ToMat3(this: (idVec3 *)&v29.mat[1].y, result: &v29);
  }
  idEntity::UpdateVisuals(this);
  idMover::UpdateNavigationSpace(this);
}


// ========================================================================
// ?SetColor@idMover@@UAAXMMM@Z
// EA  : 0x82C85760
// RVA : 0x00C85760
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::SetColor(
        idMover *this,
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
  __int64 v15; // [sp+8h] [-68h]
  __int64 v16; // [sp+10h] [-60h]
  __int64 v17; // [sp+18h] [-58h]
  __int64 v18; // [sp+20h] [-50h]
  __int64 v19; // [sp+28h] [-48h]
  __int64 v20; // [sp+58h] [-18h]

  presentable = this->presentable;
  if ( presentable == nullptr || (v13 = 1, presentable->model == nullptr) )
    v13 = 0;
  if ( v13 != 0 )
  {
    *(float *)&v20 = blue;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    *((float *)&v20 + 1) = 1.0;
    idPresentable::SetParm(
      this: presentable,
      parm: rp->Color,
      v4: v20,
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
// ?SetColor@idMover@@UAAXABVidVec3@@@Z
// EA  : 0x82C85828
// RVA : 0x00C85828
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::SetColor(idMover *this, const idVec3 *color, int a3, int a4, int a5, int a6, int a7, int a8)
{
  idPresentable *presentable; // r3
  char v10; // r11
  idPresentable *v11; // r11
  __int64 v12; // [sp+8h] [-68h]
  __int64 v13; // [sp+10h] [-60h]
  __int64 v14; // [sp+18h] [-58h]
  __int64 v15; // [sp+20h] [-50h]
  __int64 v16; // [sp+28h] [-48h]
  __int64 v17; // [sp+58h] [-18h]

  presentable = this->presentable;
  if ( presentable == nullptr || (v10 = 1, presentable->model == nullptr) )
    v10 = 0;
  if ( v10 != 0 )
  {
    *((float *)&v17 + 1) = 1.0;
    *(float *)&v17 = color->z;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::SetParm(
      this: presentable,
      parm: rp->Color,
      v4: v17,
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
// ?SetColor@idMover@@UAAXABVidVec4@@@Z
// EA  : 0x82C858F8
// RVA : 0x00C858F8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::SetColor(idMover *this, const idVec4 *color, int a3, int a4, int a5, int a6, int a7, int a8)
{
  idPresentable *presentable; // r3
  char v11; // r11
  idPresentable *v12; // r11
  __int64 v13; // [sp+8h] [-68h]
  __int64 v14; // [sp+10h] [-60h]
  __int64 v15; // [sp+18h] [-58h]
  __int64 v16; // [sp+20h] [-50h]
  __int64 v17; // [sp+28h] [-48h]

  presentable = this->presentable;
  if ( presentable == nullptr || (v11 = 1, presentable->model == nullptr) )
    v11 = 0;
  if ( v11 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::SetParm(
      this: presentable,
      parm: rp->Color,
      v4: *(_QWORD *)&color->z,
      a4: a5,
      a5: a6,
      a6: a7,
      a7: a8,
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


// ========================================================================
// ?SetColor@idSplineFollower@@UAAXABVidColor@@@Z
// EA  : 0x82C859B0
// RVA : 0x00C859B0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idSplineFollower::SetColor(
        idMover *this,
        const idColor *color,
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
  __int64 v12; // [sp+8h] [-68h]
  __int64 v13; // [sp+10h] [-60h]
  __int64 v14; // [sp+18h] [-58h]
  __int64 v15; // [sp+20h] [-50h]
  __int64 v16; // [sp+28h] [-48h]
  __int64 v17; // [sp+58h] [-18h]

  presentable = this->presentable;
  if ( presentable == nullptr || (v10 = 1, presentable->model == nullptr) )
    v10 = 0;
  if ( v10 != 0 )
  {
    *(float *)&v17 = color->b;
    *((float *)&v17 + 1) = color->a;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::SetParm(
      this: presentable,
      parm: rp->Color,
      v4: v17,
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
// ?Event_SetCallback@idMover@@AAA?AVeventInt@@XZ
// EA  : 0x82C85A80
// RVA : 0x00C85A80
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_SetCallback(idMover *this, eventInt *result)
{
  int value; // r11
  idHandle<int,enum invalidThreadHandle_t,0> *v5; // r3
  int v6; // r4
  idHandle<int,enum invalidThreadHandle_t,0> *CurThreadHandle; // r3
  _BYTE v9[8]; // [sp+50h] [-20h] BYREF

  value = result[544].value;
  if ( value != 1 || result[526].value != 0 )
  {
    if ( (value == 2 || value == 3) && result[525].value == 0 )
    {
      result[544].value = 0;
      CurThreadHandle = idThreadManager::GetCurThreadHandle(
                          this: (idThreadManager *)v9,
                          result: (idHandle<int,enum invalidThreadHandle_t,0> *)&gameLocal->program.threadManager);
      v6 = 1;
      result[525].value = CurThreadHandle->value;
    }
    else
    {
      v6 = 0;
    }
  }
  else
  {
    result[544].value = 0;
    v5 = idThreadManager::GetCurThreadHandle(
           this: (idThreadManager *)v9,
           result: (idHandle<int,enum invalidThreadHandle_t,0> *)&gameLocal->program.threadManager);
    v6 = 1;
    result[526].value = v5->value;
  }
  eventInt::eventInt((eventInt *)this, i: v6);
  return this;
}


// ========================================================================
// ?Event_RotateXYZ@idMover@@AAA?AVeventVoid@@MMM@Z
// EA  : 0x82C85B60
// RVA : 0x00C85B60
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_RotateXYZ(idMover *this, eventVoid *result, double x, double y, double z)
{
  idAngles v7; // [sp+50h] [-20h] BYREF

  v7.pitch = y;
  v7.yaw = z;
  v7.roll = x;
  idMover::Event_Rotate(this, result, angles: &v7);
  return this;
}


// ========================================================================
// ?Event_RotateOnceXYZ@idMover@@AAA?AVeventVoid@@MMM@Z
// EA  : 0x82C85BA0
// RVA : 0x00C85BA0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_RotateOnceXYZ(idMover *this, eventVoid *result, double x, double y, double z)
{
  idAngles v7; // [sp+50h] [-20h] BYREF

  v7.pitch = y;
  v7.yaw = z;
  v7.roll = x;
  idMover::Event_RotateOnce(this, result, angles: &v7);
  return this;
}


// ========================================================================
// ?Event_EmitSmoke@idMover@@AAA?AVeventVoid@@PBDHMABVidVec3@@@Z
// EA  : 0x82C85BE0
// RVA : 0x00C85BE0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_EmitSmoke(
        idMover *this,
        idEntity *result,
        const char *particle,
        int timeOffsetSecs,
        double diversity,
        const idVec3 *offset,
        float *a7)
{
  const idDeclParticle *v12; // r28
  idPhysics *Physics; // r3
  float *v14; // r3
  double v15; // fp9
  double v16; // fp7
  int v17; // r30
  int GameMsPerFrame; // r31
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v20; // r7
  int v22; // [sp+8h] [-B8h]
  int v23; // [sp+Ch] [-B4h]
  int v24; // [sp+10h] [-B0h]
  int v25; // [sp+14h] [-ACh]
  int v26; // [sp+18h] [-A8h]
  int v27; // [sp+1Ch] [-A4h]
  int v28; // [sp+20h] [-A0h]
  int v29; // [sp+24h] [-9Ch]
  int v30; // [sp+28h] [-98h]
  int v31; // [sp+2Ch] [-94h]
  int v32; // [sp+30h] [-90h]
  int v33; // [sp+34h] [-8Ch]
  int v34; // [sp+38h] [-88h]
  int v35; // [sp+3Ch] [-84h]
  int v36; // [sp+40h] [-80h]
  int v37; // [sp+44h] [-7Ch]
  int v38; // [sp+48h] [-78h]
  int v39; // [sp+4Ch] [-74h]
  int v40; // [sp+50h] [-70h]
  unsigned int v41; // [sp+60h] [-60h] BYREF
  idMat3 v42; // [sp+68h] [-58h] BYREF

  if ( particle != nullptr )
  {
    v12 = (const idDeclParticle *)idDeclInfo::FindWithInheritance(
                                    this: &idDeclParticle::resourceList,
                                    name: particle,
                                    makeDefault: true);
    if ( v12 != nullptr )
    {
      Physics = idEntity::GetPhysics(this: result);
      v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v15 = (float)(v14[2] + a7[2]);
      v16 = (float)(v14[1] + a7[1]);
      v42.mat[0].x = *v14 + *a7;
      v42.mat[0].z = v15;
      v42.mat[0].y = v16;
      v41 = -1;
      v17 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
          + 1000 * timeOffsetSecs;
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
      idRenderModelEffects::AddParticles(
        this: MergeBranch,
        particle: v12,
        systemStartTime: v17,
        gameMsPerFrame: GameMsPerFrame,
        diversity,
        origin: v20,
        axis: &v42,
        velocity: mat3_identity.mat,
        color: &vec3_origin.x,
        a10: v22,
        a11: v23,
        a12: v24,
        a13: v25,
        a14: v26,
        a15: v27,
        a16: v28,
        a17: v29,
        a18: v30,
        a19: v31,
        a20: v32,
        a21: v33,
        a22: v34,
        a23: v35,
        a24: v36,
        a25: v37,
        a26: v38,
        a27: v39,
        a28: v40,
        a29: &v41);
    }
  }
  return this;
}


// ========================================================================
// ?Think@idSplinePath@@UAAXXZ
// EA  : 0x82C85D08
// RVA : 0x00C85D08
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idSplinePath::Think(idSplinePath *this)
{
  idRenderWorld *renderWorld; // r31
  int GameMsPerFrame; // r30
  idCurve_Spline<idVec3> *allocedSpline; // r4
  double v5; // fp28
  double v6; // fp29
  double v7; // fp30
  double v8; // fp31
  int v9; // r24
  int v10; // r26
  idCurve_Spline<idVec3> *v11; // r4
  float *v12; // r11
  double v13; // fp27
  double v14; // fp26
  float *v15; // r3
  double v16; // fp10
  double v17; // fp8
  double v18; // fp7
  __int64 v19; // r11
  int v20; // r28
  double v21; // fp26
  idCurve_Spline<idVec3> *v22; // r4
  double v23; // fp24
  float v24; // [sp+50h] [-1F0h] BYREF
  float v25; // [sp+54h] [-1ECh]
  float v26; // [sp+58h] [-1E8h]
  float v27; // [sp+60h] [-1E0h] BYREF
  float v28; // [sp+64h] [-1DCh]
  float v29; // [sp+68h] [-1D8h]
  unsigned __int64 v30; // [sp+70h] [-1D0h]
  float v31[4]; // [sp+78h] [-1C8h] BYREF
  float v32[4]; // [sp+88h] [-1B8h] BYREF
  float v33[4]; // [sp+98h] [-1A8h] BYREF
  float v34[4]; // [sp+A8h] [-198h] BYREF
  float v35[4]; // [sp+B8h] [-188h] BYREF
  float v36[4]; // [sp+C8h] [-178h] BYREF
  float v37[4]; // [sp+D8h] [-168h] BYREF
  float v38[4]; // [sp+E8h] [-158h] BYREF
  float v39[4]; // [sp+F8h] [-148h] BYREF
  float v40[4]; // [sp+108h] [-138h] BYREF
  float v41[4]; // [sp+118h] [-128h] BYREF
  float v42[4]; // [sp+128h] [-118h] BYREF
  float v43[4]; // [sp+138h] [-108h] BYREF
  float v44[4]; // [sp+148h] [-F8h] BYREF
  float v45[4]; // [sp+158h] [-E8h] BYREF
  float v46[4]; // [sp+168h] [-D8h] BYREF
  float v47[4]; // [sp+178h] [-C8h] BYREF
  float v48[4]; // [sp+188h] [-B8h] BYREF
  idVec3 v49; // [sp+198h] [-A8h] BYREF
  _BYTE v50[80]; // [sp+1A8h] [-98h] BYREF

  if ( (this->thinkFlags & 1) != 0 && g_spline_debug.valueInteger > 0 && this->allocedSpline != nullptr )
  {
    renderWorld = clientGame->renderWorld;
    if ( renderWorld != nullptr )
    {
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      if ( this->allocedSpline->values.num > 0 )
      {
        allocedSpline = this->allocedSpline;
        v30 = __PAIR64__(0x82000000, g_spline_debug.valueInteger);
        v5 = (float)((float)__SPAIR64__(0x82000000, g_spline_debug.valueInteger) * (float)4.0);
        v6 = (float)((float)__SPAIR64__(0x82000000, g_spline_debug.valueInteger) * (float)1.5);
        v7 = (float)((float)((float)__SPAIR64__(0x82000000, g_spline_debug.valueInteger) * (float)4.0) * (float)0.0);
        v8 = (float)((float)((float)__SPAIR64__(0x82000000, g_spline_debug.valueInteger) * (float)1.5) * (float)0.0);
        ((void (__fastcall *)(float *))allocedSpline->GetCurrentValue)(a1: &v24);
        v45[0] = v24 - (float)v5;
        v45[1] = v25 - (float)v7;
        v45[2] = v26 - (float)v7;
        v33[0] = (float)v5 + v24;
        v33[1] = v25 + (float)v7;
        v33[2] = v26 + (float)v7;
        renderWorld->DebugLine(
          this: renderWorld,
          a2: (const idVec4 *)&idColor::colorCyan,
          a3: (const idVec3 *)v33,
          a4: (const idVec3 *)v45,
          a5: GameMsPerFrame,
          a6: false);
        v48[0] = v24 - (float)v7;
        v48[1] = v25 - (float)v5;
        v48[2] = v26 - (float)v7;
        v35[0] = (float)v7 + v24;
        v35[1] = v25 + (float)v5;
        v35[2] = v26 + (float)v7;
        renderWorld->DebugLine(
          this: renderWorld,
          a2: (const idVec4 *)&idColor::colorCyan,
          a3: (const idVec3 *)v35,
          a4: (const idVec3 *)v48,
          a5: GameMsPerFrame,
          a6: false);
        v43[0] = v24 - (float)v7;
        v43[1] = v25 - (float)v7;
        v43[2] = v26 - (float)v5;
        v37[0] = (float)v7 + v24;
        v37[1] = v25 + (float)v7;
        v37[2] = v26 + (float)v5;
        renderWorld->DebugLine(
          this: renderWorld,
          a2: (const idVec4 *)&idColor::colorCyan,
          a3: (const idVec3 *)v37,
          a4: (const idVec3 *)v43,
          a5: GameMsPerFrame,
          a6: false);
        v9 = 1;
        if ( this->allocedSpline->values.num > 1 )
        {
          v10 = 1;
          do
          {
            v11 = this->allocedSpline;
            v12 = &v11->times.list[v10];
            v13 = *(v12 - 1);
            v14 = *v12;
            v15 = (float *)((int (__fastcall *)(_BYTE *, double))v11->GetCurrentValue)(a1: v50, a2: v13);
            v24 = *v15;
            v16 = (float)(v15[1] - (float)v7);
            v25 = v15[1];
            v17 = (float)(v15[2] - (float)v7);
            v18 = (float)(v15[2] + (float)v7);
            v26 = v15[2];
            v47[1] = v16;
            v39[0] = (float)v5 + v24;
            v39[1] = v25 + (float)v7;
            v47[2] = v17;
            v39[2] = v18;
            v47[0] = v24 - (float)v5;
            renderWorld->DebugLine(
              this: renderWorld,
              a2: (const idVec4 *)&idColor::colorCyan,
              a3: (const idVec3 *)v39,
              a4: (const idVec3 *)v47,
              a5: GameMsPerFrame,
              a6: false);
            v41[1] = v25 + (float)v5;
            v41[2] = v26 + (float)v7;
            v31[0] = v24 - (float)v7;
            v31[1] = v25 - (float)v5;
            v31[2] = v26 - (float)v7;
            v41[0] = (float)v7 + v24;
            renderWorld->DebugLine(
              this: renderWorld,
              a2: (const idVec4 *)&idColor::colorCyan,
              a3: (const idVec3 *)v41,
              a4: (const idVec3 *)v31,
              a5: GameMsPerFrame,
              a6: false);
            v32[0] = v24 - (float)v7;
            v32[1] = v25 - (float)v7;
            v32[2] = v26 - (float)v5;
            v34[0] = (float)v7 + v24;
            v34[1] = v25 + (float)v7;
            v34[2] = v26 + (float)v5;
            renderWorld->DebugLine(
              this: renderWorld,
              a2: (const idVec4 *)&idColor::colorCyan,
              a3: (const idVec3 *)v34,
              a4: (const idVec3 *)v32,
              a5: GameMsPerFrame,
              a6: false);
            v20 = 0;
            v21 = (float)((float)((float)v14 - (float)v13) * (float)0.125);
            do
            {
              LODWORD(v19) = v20;
              v22 = this->allocedSpline;
              v30 = v19;
              v23 = (float)((float)((float)v19 * (float)v21) + (float)v13);
              ((void (__fastcall *)(idVec3 *, double))v22->GetCurrentValue)(a1: &v49, a2: v23);
              ((void (__fastcall *)(float *, double))this->allocedSpline->GetCurrentValue)(
                a1: &v27,
                a2: (float)((float)v23 + (float)v21));
              renderWorld->DebugLine(
                this: renderWorld,
                a2: (const idVec4 *)&idColor::colorCyan,
                a3: &v49,
                a4: (const idVec3 *)&v27,
                a5: GameMsPerFrame,
                a6: false);
              if ( v20 > 0 && v20 < 7 )
              {
                v38[2] = v29 + (float)v8;
                v36[2] = v29 - (float)v8;
                v38[0] = v27 + (float)v6;
                v38[1] = v28 + (float)v8;
                v36[0] = v27 - (float)v6;
                v36[1] = v28 - (float)v8;
                renderWorld->DebugLine(
                  this: renderWorld,
                  a2: (const idVec4 *)&idColor::colorBlue,
                  a3: (const idVec3 *)v38,
                  a4: (const idVec3 *)v36,
                  a5: GameMsPerFrame,
                  a6: false);
                v42[2] = v29 + (float)v8;
                v42[1] = v28 + (float)v6;
                v40[0] = v27 - (float)v8;
                v40[1] = v28 - (float)v6;
                v40[2] = v29 - (float)v8;
                v42[0] = v27 + (float)v8;
                renderWorld->DebugLine(
                  this: renderWorld,
                  a2: (const idVec4 *)&idColor::colorBlue,
                  a3: (const idVec3 *)v42,
                  a4: (const idVec3 *)v40,
                  a5: GameMsPerFrame,
                  a6: false);
                v44[2] = v29 - (float)v6;
                v46[0] = v27 + (float)v8;
                v46[1] = v28 + (float)v8;
                v46[2] = v29 + (float)v6;
                v44[0] = v27 - (float)v8;
                v44[1] = v28 - (float)v8;
                renderWorld->DebugLine(
                  this: renderWorld,
                  a2: (const idVec4 *)&idColor::colorBlue,
                  a3: (const idVec3 *)v46,
                  a4: (const idVec3 *)v44,
                  a5: GameMsPerFrame,
                  a6: false);
              }
              ++v20;
            }
            while ( v20 < 8 );
            ++v9;
            ++v10;
          }
          while ( v9 < this->allocedSpline->values.num );
        }
      }
    }
  }
}


// ========================================================================
// ?RemoveControlPoint@idSplinePath@@QAAXH@Z
// EA  : 0x82C86298
// RVA : 0x00C86298
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idSplinePath::RemoveControlPoint(idSplinePath *this, int index)
{
  int num; // r6

  num = this->controlPoints.num;
  if ( index >= num )
    idLib::Warning(
      fmt: "%s - cannot remove invalid index %d (num control points = %d)",
      "idSplinePath::RemoveControlPoint",
      index,
      num);
  else
    idList<idAngles,5>::RemoveIndex(this: (idList<idVec3,116> *)&this->controlPoints, index);
}


// ========================================================================
// ?Spawn@idFuncRotate@@QAAXXZ
// EA  : 0x82C862D0
// RVA : 0x00C862D0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idFuncRotate::Spawn(idFuncRotate *this)
{
  idPhysics *Physics; // r3
  idClipModel *v3; // r30
  idPhysics *v4; // r3
  const idClipModel *v5; // r3
  idClipModel *v6; // r3
  idClipModel *v7; // r27
  idPhysics *v8; // r28
  idPhysics *v9; // r25
  const idMat3 *v10; // r28
  const idVec3 *v11; // r3
  int GameMs; // r3
  int v13; // r3
  int v14; // r5
  idPresentable *presentable; // r11
  char v16; // r10

  Physics = idEntity::GetPhysics(this);
  if ( Physics->GetNumClipModels(this: Physics) <= 0 )
  {
    v7 = nullptr;
  }
  else
  {
    v3 = (idClipModel *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0xD8u,
                          tag: TAG_CLIPMODEL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v4 = idEntity::GetPhysics(this);
      v5 = v4->GetClipModel(this: v4, a2: 0);
      v6 = idClipModel::idClipModel(this: v3, clip: &clientGame->clip, model: v5);
    }
    else
    {
      v6 = nullptr;
    }
    v7 = v6;
  }
  idPhysics::InitPhysics(
    this: &this->physicsObj,
    clip_: &clientGame->clip,
    callbacks_: &this->physicsCallbacks,
    entityNumber_: this->entityNumber);
  ((void (__fastcall *)(idPhysics_Parametric *, idClipModel *, double))this->physicsObj.SetClipModel)(
    a1: &this->physicsObj,
    a2: v7,
    a3: 1.0);
  v8 = idEntity::GetPhysics(this);
  v9 = idEntity::GetPhysics(this);
  v10 = v8->GetAxis(this: v8, a2: 0);
  v11 = v9->GetOrigin(this: v9, a2: 0);
  idPhysics_Parametric::SetWorldOrientation(this: &this->physicsObj, _worldOrigin: v11, _worldAxis: v10);
  this->physicsObj.SetLocalOrigin(this: &this->physicsObj, a2: &vec3_origin, a3: -1);
  this->physicsObj.SetLocalAxis(this: &this->physicsObj, a2: &mat3_identity, a3: -1);
  this->physicsObj.SetClipMask(this: &this->physicsObj, a2: 1, a3: -1);
  this->physicsObj.SetContents(this: &this->physicsObj, a2: this->solid, a3: -1);
  if ( !this->noPush )
  {
    if ( v7 != nullptr )
    {
      idPhysics_Parametric::SetPusher(this: &this->physicsObj, push: &clientGame->push, flags: 0);
    }
    else
    {
      this->noPush = true;
      idGameLocal::MapError(
        this: gameLocal,
        fmt: "idFuncRotate::Spawn: mover '%s' has no clip model and noPush is set to false",
        this->name.data);
    }
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idPhysics_Parametric::SetLinearExtrapolation(
    this: &this->physicsObj,
    type: EXTRAPOLATION_NONE,
    currentTime: GameMs,
    duration: (unsigned int)&vec3_origin,
    base: &vec3_origin,
    speed: &vec3_origin);
  v13 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idPhysics_Parametric::SetAngularExtrapolation(
    this: &this->physicsObj,
    type: EXTRAPOLATION_LINEAR|EXTRAPOLATION_NOSTOP,
    currentTime: v13,
    duration: (unsigned int)&ang_zero,
    base: &this->rotateSpeed,
    speed: &ang_zero);
  idEntity::SetPhysics(this, phys: &this->physicsObj, a3: v14);
  presentable = this->presentable;
  if ( presentable == nullptr || (v16 = 1, presentable->model == nullptr) )
    v16 = 0;
  if ( v16 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->model->g.castDimShadows = DIMSHADOW_ON;
  }
  this->running = true;
}


// ========================================================================
// __unwind$507259_0
// EA  : 0x82C865CC
// RVA : 0x00C865CC
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_507259_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?Spawn@idFuncSwing@@QAAXXZ
// EA  : 0x82C86600
// RVA : 0x00C86600
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idFuncSwing::Spawn(idFuncSwing *this)
{
  idPhysics *Physics; // r3
  idClipModel *v3; // r30
  idPhysics *v4; // r3
  const idClipModel *v5; // r3
  idClipModel *v6; // r3
  idClipModel *v7; // r27
  idPhysics *v8; // r28
  idPhysics *v9; // r25
  const idMat3 *v10; // r28
  const idVec3 *v11; // r3
  int GameMs; // r3
  double v13; // fp8
  double v14; // fp7
  double v15; // fp5
  int v16; // r27
  int v17; // r3
  __int64 v18; // r8
  int v19; // r5
  idPresentable *presentable; // r11
  char v21; // r10
  float v22[22]; // [sp+58h] [-58h] BYREF

  Physics = idEntity::GetPhysics(this);
  if ( Physics->GetNumClipModels(this: Physics) <= 0 )
  {
    v7 = nullptr;
  }
  else
  {
    v3 = (idClipModel *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0xD8u,
                          tag: TAG_CLIPMODEL,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v3 != nullptr )
    {
      v4 = idEntity::GetPhysics(this);
      v5 = v4->GetClipModel(this: v4, a2: 0);
      v6 = idClipModel::idClipModel(this: v3, clip: &clientGame->clip, model: v5);
    }
    else
    {
      v6 = nullptr;
    }
    v7 = v6;
  }
  idPhysics::InitPhysics(
    this: &this->physicsObj,
    clip_: &clientGame->clip,
    callbacks_: &this->physicsCallbacks,
    entityNumber_: this->entityNumber);
  ((void (__fastcall *)(idPhysics_Parametric *, idClipModel *, double))this->physicsObj.SetClipModel)(
    a1: &this->physicsObj,
    a2: v7,
    a3: 1.0);
  v8 = idEntity::GetPhysics(this);
  v9 = idEntity::GetPhysics(this);
  v10 = v8->GetAxis(this: v8, a2: 0);
  v11 = v9->GetOrigin(this: v9, a2: 0);
  idPhysics_Parametric::SetWorldOrientation(this: &this->physicsObj, _worldOrigin: v11, _worldAxis: v10);
  this->physicsObj.SetLocalOrigin(this: &this->physicsObj, a2: &vec3_origin, a3: -1);
  this->physicsObj.SetLocalAxis(this: &this->physicsObj, a2: &mat3_identity, a3: -1);
  this->physicsObj.SetClipMask(this: &this->physicsObj, a2: 1, a3: -1);
  this->physicsObj.SetContents(this: &this->physicsObj, a2: this->solid, a3: -1);
  if ( !this->noPush )
  {
    if ( v7 != nullptr )
    {
      idPhysics_Parametric::SetPusher(this: &this->physicsObj, push: &clientGame->push, flags: 0);
    }
    else
    {
      this->noPush = true;
      idGameLocal::MapError(
        this: gameLocal,
        fmt: "idFuncSwing::Spawn: mover '%s' has no clip model and noPush is set to false",
        this->name.data);
    }
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idPhysics_Parametric::SetLinearExtrapolation(
    this: &this->physicsObj,
    type: EXTRAPOLATION_NONE,
    currentTime: GameMs,
    duration: (unsigned int)&vec3_origin,
    base: &vec3_origin,
    speed: &vec3_origin);
  v13 = (float)(this->swingExtents.yaw * (float)0.5);
  v14 = (float)(this->swingExtents.roll * (float)0.5);
  v15 = (float)((float)1000.0 / this->swingSpeed);
  v22[0] = -(float)(this->swingExtents.pitch * (float)0.5);
  v22[1] = -v13;
  v22[2] = -v14;
  v16 = (int)v15;
  v17 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  HIDWORD(v18) = v16;
  LODWORD(v18) = v22;
  idPhysics_Parametric::SetAngularExtrapolation(
    this: &this->physicsObj,
    type: EXTRAPOLATION_ACCELSINE|EXTRAPOLATION_NOSTOP,
    currentTime: v17,
    duration: v18,
    base: &this->swingExtents,
    speed: &ang_zero);
  idEntity::SetPhysics(this, phys: &this->physicsObj, a3: v19);
  presentable = this->presentable;
  if ( presentable == nullptr || (v21 = 1, presentable->model == nullptr) )
    v21 = 0;
  if ( v21 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->model->g.castDimShadows = DIMSHADOW_ON;
  }
  this->running = true;
}


// ========================================================================
// __unwind$507355
// EA  : 0x82C86954
// RVA : 0x00C86954
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_507355()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 176 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?Spawn@splineMoverModifierAiProps_t@splineMoverModifier_t@@QAAXABU2@@Z
// EA  : 0x82C86980
// RVA : 0x00C86980
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall splineMoverModifier_t::splineMoverModifierAiProps_t::Spawn(
        splineMoverModifier_t::splineMoverModifierAiProps_t *this,
        const splineMoverModifier_t *modifier)
{
  float *p_z; // r10
  float *p_y; // r11
  int v6; // ctr
  idVec3 *p_animationEndOrigin; // r29
  double y; // fp0
  double z; // fp10
  double v10; // fp6
  double v11; // fp5
  double v12; // fp8
  double v13; // fp13
  double v14; // fp13
  double v15; // fp12
  idVec3 v16; // [sp+50h] [-3140h] BYREF
  idVec3 v17; // [sp+60h] [-3130h] BYREF
  idMD6Util::animDelta_t v18; // [sp+70h] [-3120h] BYREF
  trace_t v19; // [sp+A0h] [-30F0h] BYREF
  idMat3 v20; // [sp+120h] [-3070h] BYREF
  idMD6Util::idJointCache v21; // [sp+150h] [-3040h] BYREF

  idMD6Util::idJointCache::idJointCache(this: &v21, webPath: &this->animation, frameNum: -1);
  p_z = &v18.deltaTranslation.z;
  p_y = &mat2_identity.mat[1].y;
  v6 = 9;
  v18.deltaTranslation = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v6;
  }
  while ( v6 != 0 );
  if ( (unsigned __int8)idMD6Util::idJointCache::GetDelta(
                          this: &v21,
                          delta: &v18,
                          jointName: "origin",
                          refJointName: "origin") != 0 )
  {
    p_animationEndOrigin = &this->animationEndOrigin;
    y = modifier->modifierOrigin.y;
    z = modifier->modifierOrigin.z;
    v10 = (float)((float)(modifier->modifierAxis.mat[0].y * v18.deltaTranslation.x)
                + (float)((float)(modifier->modifierAxis.mat[1].y * v18.deltaTranslation.y)
                        + (float)(modifier->modifierAxis.mat[2].y * v18.deltaTranslation.z)));
    v11 = (float)((float)(modifier->modifierAxis.mat[0].z * v18.deltaTranslation.x)
                + (float)((float)(modifier->modifierAxis.mat[1].z * v18.deltaTranslation.y)
                        + (float)(modifier->modifierAxis.mat[2].z * v18.deltaTranslation.z)));
    this->animationEndOrigin.x = modifier->modifierOrigin.x
                               + (float)((float)(modifier->modifierAxis.mat[0].x * v18.deltaTranslation.x)
                                       + (float)((float)(modifier->modifierAxis.mat[1].x * v18.deltaTranslation.y)
                                               + (float)(modifier->modifierAxis.mat[2].x * v18.deltaTranslation.z)));
    this->animationEndOrigin.y = (float)y + (float)v10;
    this->animationEndOrigin.z = (float)z + (float)v11;
    this->animationEndAxis = *idMat3::operator*(this: &v20, result: &modifier->modifierAxis, a: &v18.deltaAxis);
    if ( (*((_BYTE *)this + 36) & 0x20) != 0 )
    {
      v12 = this->animationEndOrigin.z;
      v13 = (float)(this->animationEndOrigin.y + (float)(vec3_up.y * (float)128.0));
      v17.x = (float)(vec3_up.x * (float)128.0) + p_animationEndOrigin->x;
      v17.y = v13;
      v17.z = (float)v12 + (float)(vec3_up.z * (float)128.0);
      v16.x = v17.x - (float)(vec3_up.x * (float)256.0);
      v16.y = (float)v13 - (float)(vec3_up.y * (float)256.0);
      v16.z = v17.z - (float)(vec3_up.z * (float)256.0);
      idClip::TracePoint(
        this: &clientGame->clip,
        result: &v19,
        start: &v17,
        end: &v16,
        clipMask: 106513,
        passEntityNumber: 0x1FFF);
      if ( v19.fraction < 1.0 )
      {
        v14 = v19.endpos.y;
        v15 = v19.endpos.z;
        p_animationEndOrigin->x = v19.endpos.x;
        this->animationEndOrigin.y = v14;
        this->animationEndOrigin.z = v15;
      }
    }
  }
}


// ========================================================================
// ?Spawn@idMoverMM@@QAAXXZ
// EA  : 0x82C86BE0
// RVA : 0x00C86BE0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::Spawn(idMoverMM *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3
  idAngles *v4; // r3
  idAngles *v5; // r3
  idPhysics_ParametricMM *p_physicsObj; // r29
  idClientGame *v7; // r11
  idClipModel *v8; // r25
  idPhysics *v9; // r3
  const idClipModel *v10; // r3
  idClipModel *v11; // r4
  idPhysics *v12; // r3
  int v13; // r3
  idPhysics *v14; // r3
  int v15; // r3
  const idDeclDamage *crushDamage; // r11
  int v17; // r5
  int v18; // r3
  const idMat3 *v19; // r28
  int v20; // r3
  __int64 v21; // r10
  int v22; // r5
  idPresentable *presentable; // r11
  char v24; // r10
  idMat3 v25[3]; // [sp+58h] [-88h] BYREF

  this->stopRotation = false;
  this->lastCommand = MOVER_NONE;
  Physics = idEntity::GetPhysics(this);
  this->dest_position = *Physics->GetOrigin(this: Physics, a2: 0);
  v3 = idEntity::GetPhysics(this);
  v4 = (idAngles *)v3->GetAxis(this: v3, a2: 0);
  v5 = idMat3::ToAngles(this: v25, result: v4);
  p_physicsObj = &this->physicsObj;
  this->dest_angles.pitch = v5->pitch;
  v7 = clientGame;
  this->dest_angles.yaw = v5->yaw;
  this->dest_angles.roll = v5->roll;
  idPhysics::InitPhysics(
    this: &this->physicsObj,
    clip_: &v7->clip,
    callbacks_: &this->physicsCallbacks,
    entityNumber_: this->entityNumber);
  if ( this->clipModelInfo.type != CLIPMODEL_NONE )
  {
    v8 = (idClipModel *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0xD8u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    if ( v8 != nullptr )
    {
      v9 = idEntity::GetPhysics(this);
      v10 = v9->GetClipModel(this: v9, a2: 0);
      v11 = idClipModel::idClipModel(this: v8, clip: &clientGame->clip, model: v10);
    }
    else
    {
      v11 = nullptr;
    }
    ((void (__fastcall *)(idPhysics_ParametricMM *, idClipModel *, double))p_physicsObj->SetClipModel)(
      a1: &this->physicsObj,
      a2: v11,
      a3: 1.0);
  }
  v12 = idEntity::GetPhysics(this);
  v13 = (int)v12->GetOrigin(this: v12, a2: 0);
  p_physicsObj->SetOrigin(this: &this->physicsObj, a2: (const idVec3 *)v13, a3: -1);
  v14 = idEntity::GetPhysics(this);
  v15 = (int)v14->GetAxis(this: v14, a2: 0);
  p_physicsObj->SetAxis(this: &this->physicsObj, a2: (const idMat3 *)v15, a3: -1);
  p_physicsObj->SetContents(this: &this->physicsObj, a2: this->contentsFlags, a3: -1);
  p_physicsObj->SetClipMask(this: &this->physicsObj, a2: 1, a3: -1);
  if ( !this->noPush )
  {
    if ( p_physicsObj->GetClipModel(this: &this->physicsObj, a2: 0) == nullptr )
      idLib::Warning(fmt: "%s: doesn't have a clip model but is set as a pusher( noPush == false )", this->name.data);
    crushDamage = this->crushDamage;
    if ( crushDamage == nullptr || (v17 = 16, !crushDamage->instantRagdoll) )
      v17 = 0;
    idPhysics_ParametricMM::SetPusher(this: &this->physicsObj, push: &clientGame->push, flags: v17);
  }
  v18 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idPhysics_ParametricMM::SetLinearExtrapolation(
    this: &this->physicsObj,
    type: EXTRAPOLATION_NONE,
    currentTime: v18,
    duration: (unsigned int)&this->dest_position,
    base: &vec3_origin,
    speed: &vec3_origin);
  v19 = idAngles::ToMat3(this: (idAngles *)&v25[0].mat[2], result: (idMat3 *)&this->dest_angles);
  v20 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  HIDWORD(v21) = &vec3_origin;
  idPhysics_ParametricMM::SetAngularExtrapolation(
    this: &this->physicsObj,
    type: EXTRAPOLATION_NONE,
    currentTime: v20,
    time: 0,
    duration: 0,
    base: v19,
    vec: v21,
    speed: 0.0);
  idEntity::SetPhysics(this, phys: &this->physicsObj, a3: v22);
  presentable = this->presentable;
  if ( presentable == nullptr || (v24 = 1, presentable->model == nullptr) )
    v24 = 0;
  if ( v24 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->model->g.castDimShadows = DIMSHADOW_ON;
  }
}


// ========================================================================
// __unwind$507600
// EA  : 0x82C86F5C
// RVA : 0x00C86F5C
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall _unwind_507600(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 224 + 80), tag: a2);
}


// ========================================================================
// ?Event_RotateXYZ@idMoverMM@@AAA?AVeventVoid@@MMM@Z
// EA  : 0x82C86F88
// RVA : 0x00C86F88
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_RotateXYZ(idMoverMM *this, eventVoid *result, double x, double y, double z)
{
  idAngles v7; // [sp+50h] [-20h] BYREF

  v7.pitch = y;
  v7.yaw = z;
  v7.roll = x;
  idMoverMM::Event_Rotate(this, result, angles: &v7);
  return this;
}


// ========================================================================
// ?Event_RotateOnceXYZ@idMoverMM@@AAA?AVeventVoid@@MMM@Z
// EA  : 0x82C86FC8
// RVA : 0x00C86FC8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::Event_RotateOnceXYZ(idMoverMM *this, eventVoid *result, double x, double y, double z)
{
  idAngles v7; // [sp+50h] [-20h] BYREF

  v7.pitch = y;
  v7.yaw = z;
  v7.roll = x;
  idMoverMM::Event_RotateOnce(this, result, angles: &v7);
  return this;
}


// ========================================================================
// ?Spawn@idSplinePathMM@@QAAXXZ
// EA  : 0x82C87008
// RVA : 0x00C87008
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idSplinePathMM::Spawn(idSplinePathMM *this)
{
  idPhysics *Physics; // r3
  int v3; // r4
  idPhysics *v4; // r3
  idPresentable *presentable; // r11
  char v6; // r10
  idPresentable *v7; // r11

  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) != 0 )
  {
    Physics = idEntity::GetPhysics(this);
    v3 = 0;
LABEL_6:
    Physics->SetContents(this: Physics, a2: v3, a3: -1);
    goto LABEL_7;
  }
  if ( this->splineGeometry.generateGeometry )
  {
    Physics = idEntity::GetPhysics(this);
    v3 = 1;
    goto LABEL_6;
  }
  v4 = idEntity::GetPhysics(this);
  v4->SetContents(this: v4, a2: 0, a3: -1);
  this->Hide_2(this);
LABEL_7:
  presentable = this->presentable;
  if ( presentable == nullptr || (v6 = 1, presentable->model == nullptr) )
    v6 = 0;
  if ( v6 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    *((_BYTE *)&presentable->model->g + 104) |= 0x20u;
    v7 = this->presentable;
    if ( v7 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v7 = this->presentable;
    }
    v7->Show(this: v7);
  }
  idEventReceiver::PostEventMS(this, ev: &EV_PostSpawn, time: 0);
}


// ========================================================================
// ?Event_GetSplineChild@idSplinePathMM@@QAA?AVeventEntity@@H@Z
// EA  : 0x82C873F8
// RVA : 0x00C873F8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idSplinePathMM *__fastcall idSplinePathMM::Event_GetSplineChild(idSplinePathMM *this, eventEntity *result, int index)
{
  int v4; // r9
  idEntity *v5; // r3
  idEntity *v6; // r4

  v4 = *((_DWORD *)&result[247].value->__vftable + index);
  if ( gameLocal->spawnIds.ptr[v4 & 0x1FFF] == v4 >> 13
    && (v5 = gameLocal->entities.ptr[(int)*(&result[247].value->__vftable + index) & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  eventEntity::eventEntity((eventEntity *)this, e: v6);
  return this;
}


// ========================================================================
// ?Spawn@idMoverAttachment@@QAAXXZ
// EA  : 0x82C87488
// RVA : 0x00C87488
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverAttachment::Spawn(idMoverAttachment *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r29
  idAnimStack *v3; // r3
  idGameTimeManager *v4; // r3
  int entityNumber; // r29
  idClip *p_clip; // r27
  idGameTimeManager *p_gameTimeManager; // r28
  idRenderModel *RenderModelFromPresentable; // r26
  idAnimStack *v9; // r3
  int v10; // r10
  int v11; // [sp+8h] [-B8h]
  int v12; // [sp+Ch] [-B4h]
  int v13; // [sp+10h] [-B0h]
  int v14; // [sp+14h] [-ACh]
  int v15; // [sp+18h] [-A8h]
  int v16; // [sp+1Ch] [-A4h]
  int v17; // [sp+20h] [-A0h]
  int v18; // [sp+24h] [-9Ch]
  idAnimatorParms_Base v19[2]; // [sp+50h] [-70h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    v3 = this->GetAnimStack_2(this);
    idAnimStack::Init(this: v3, treeAnimator: TreeAnimatorFromPresentable);
    v19[0].animStack = this->GetAnimStack_2(this);
    idStr::idStr(this: &v19[0].name, text: "all");
    v19[0].originBlend = ORIGINBLEND_BRANCH;
    v19[0].blendOp = BOP_LERP;
    v19[0].weightGroup = MD6_WEIGHTGROUP_ALL;
    v19[0].alpha = 1.0;
    v19[0].filterGroup = MD6_WEIGHTGROUP_ALL;
    v4 = gameLocal->GetGameTimeManager(this: gameLocal);
    if ( (unsigned __int8)idAnimator_Base::Init(this: &this->channelAnimator, gametimeManager: v4, parms: v19) == 0 )
    {
      idStr::FreeData(this: &v19[0].name);
      return;
    }
    idStr::FreeData(this: &v19[0].name);
  }
  if ( this->useAsVehicle )
  {
    entityNumber = this->entityNumber;
    p_clip = &clientGame->clip;
    p_gameTimeManager = &clientGame->gameTimeManager;
    RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
    v9 = this->GetAnimStack_2(this);
    idAnimator_VehicleCar::InitVehicleAnimator(
      this: &this->vehicleAnimator,
      game: p_gameTimeManager,
      vehicleProps_: this->vehicleProps,
      animStack_: v9,
      renderModel_: RenderModelFromPresentable,
      entityNum_: entityNumber,
      clip_: p_clip,
      a8: v10,
      a9: v11,
      a10: v12,
      a11: v13,
      a12: v14,
      a13: v15,
      a14: v16,
      a15: v17,
      a16: v18);
    idEntity::BecomeActive(this, flags: 4);
  }
}


// ========================================================================
// __unwind$508046
// EA  : 0x82C875D4
// RVA : 0x00C875D4
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_508046()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 192 + 80));
}


// ========================================================================
// ?ManualThink@idMoverAttachment@@QAAXXZ
// EA  : 0x82C87600
// RVA : 0x00C87600
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverAttachment::ManualThink(idMoverAttachment *this)
{
  int v2; // r28
  const idAnimStack *v3; // r3

  idMoverAttachment::UpdateMovement(this, applyAnimationDelta: true);
  if ( this->currentAnimationHandle.value != 0xFFFF )
  {
    v2 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v3 = this->GetAnimStack_2(this);
    if ( (unsigned __int8)idAnimator_Channel::IsAnimPlaying(
                            this: &this->channelAnimator,
                            stack: v3,
                            ah: &this->currentAnimationHandle,
                            curTime: v2) == 0 )
    {
      idSuperScriptSystem::InvokeNamedFunction(
        this: &gameLocal->superScript,
        callStr: this->endOfAnimationScriptFunction.str);
      idAtomicString::Set(this: &this->endOfAnimationScriptFunction, str_: &byte_8200D768);
    }
  }
  idAnimatedEntity::Think(this);
}


// ========================================================================
// ?ComputeAnimationSpeed@idMoverAttachment@@QAAMABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@AAVidMat3@@@Z
// EA  : 0x82C876C0
// RVA : 0x00C876C0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

float __fastcall idMoverAttachment::ComputeAnimationSpeed(
        idMoverAttachment *this,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *animAlias,
        idMat3 *firstFrameOrientation)
{
  BOOL v6; // r30
  double v7; // fp1
  double v8; // fp4
  double v9; // fp3
  double v10; // fp2
  __int64 v12; // [sp+50h] [-70h]
  idVec3 v13; // [sp+58h] [-68h] BYREF
  idStr v14[2]; // [sp+70h] [-50h] BYREF

  idStr::idStr(this: v14, text: "origin");
  v6 = (_cntlzw((unsigned __int8)idMoverAttachment::ComputeAnimationTranslationDelta(
                                   this,
                                   animAlias,
                                   jointName: v14,
                                   startFrame: 0,
                                   endFrame: 1,
                                   deltaTrans: &v13,
                                   firstFrameOrientation))
      & 0x20) != 0;
  idStr::FreeData(this: v14);
  if ( v6 )
  {
    v7 = -1.0;
  }
  else
  {
    v12 = __PAIR64__(&unk_82390000, gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED));
    v8 = (float)(v13.x * (float)((float)1.0 / (float)((float)v12 * (float)0.001)));
    v9 = (float)(v13.z * (float)((float)1.0 / (float)((float)v12 * (float)0.001)));
    v10 = (float)(v13.y * (float)((float)1.0 / (float)((float)v12 * (float)0.001)));
    v7 = __fsqrts((float)((float)((float)v10 * (float)v10)
                        + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8))));
  }
  return *((float *)&v7 + 1);
}


// ========================================================================
// __unwind$508115
// EA  : 0x82C877AC
// RVA : 0x00C877AC
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_508115()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// ??0idMover@@QAA@XZ
// EA  : 0x82C88020
// RVA : 0x00C88020
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::idMover(idMover *this)
{
  float z; // r10
  int *p_soundFlags; // r10
  int v4; // ctr

  idEntity::idEntity(this);
  this->__vftable = (idMover_vtbl *)&idMover::`vftable';
  idPhysics_Parametric::idPhysics_Parametric(this: &this->physicsObj);
  this->soundFlags = 0;
  this->move_thread.value = 0;
  this->rotate_thread.value = 0;
  this->move_speed = 0.0;
  this->health = 0.0;
  this->move_time = 1;
  this->deceltime = 0;
  this->acceltime = 0;
  this->resetPathOnCompletion = true;
  this->stopRotation = false;
  this->useSplineAngles = true;
  this->lastCommand = MOVER_NONE;
  this->crunchSoundTime = 0;
  this->crushDamage = nullptr;
  this->sndCrush = nullptr;
  this->solid = true;
  this->noPush = true;
  this->sndAccel = nullptr;
  this->sndDecel = nullptr;
  this->sndMove = nullptr;
  this->sndFoliage = nullptr;
  this->influence.innerRadius = 32.0;
  this->influence.trailDist = 32.0;
  this->influence.outerRadius = 64.0;
  this->influence.angle = 0.0;
  this->influence.trailFadeInTime = 0.25;
  this->influence.trailFadeOutTime = 2.0;
  this->impaleEntity = false;
  this->impaleDepth = 16.0;
  this->constraintName.allocedAndFlag = 20;
  this->constraintName.data = this->constraintName.baseBuffer;
  this->constraintName.len = 0;
  this->constraintName.baseBuffer[0] = 0;
  this->impaledEntity.spawnId.value = 0x1FFF;
  this->needsReset = false;
  this->savedAFContents = 0;
  this->lastOrigin.x = vec3_origin.x;
  this->lastOrigin.y = vec3_origin.y;
  z = vec3_origin.z;
  this->smoothMovement = 0.0;
  this->lastOrigin.z = z;
  this->averageModelOrigin.x = 0.0;
  this->averageModelOrigin.y = 0.0;
  this->averageModelOrigin.z = 0.0;
  this->highlightColor = HIGHLIGHT_COLOR_NONE;
  this->guiTargets.list = nullptr;
  this->guiTargets.granularity = 0;
  this->guiTargets.memTag = 5;
  this->guiTargets.listStatic = 0;
  this->guiTargets.size = 0;
  this->guiTargets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->guiTargets);
  this->navigationSpace.navSpaceLayers = NavMask_None;
  idNavigationSpace::idNavigationSpace(this: &this->navigationSpace.navSpace);
  this->averageModelAxis.mat[1].z = 0.0;
  this->averageModelAxis.mat[0].z = 0.0;
  this->averageModelAxis.mat[0].y = 0.0;
  this->averageModelAxis.mat[2].y = 0.0;
  this->averageModelAxis.mat[2].z = 1.0;
  this->averageModelAxis.mat[1].y = 1.0;
  this->averageModelAxis.mat[0].x = 1.0;
  this->averageModelAxis.mat[2].x = 0.0;
  this->averageModelAxis.mat[1].x = 0.0;
  this->angle_delta.roll = 0.0;
  this->angle_delta.yaw = 0.0;
  p_soundFlags = &this->soundFlags;
  this->angle_delta.pitch = 0.0;
  this->dest_angles.roll = 0.0;
  v4 = 8;
  this->dest_angles.yaw = 0.0;
  this->dest_angles.pitch = 0.0;
  this->dest_position.z = 0.0;
  this->dest_position.y = 0.0;
  this->dest_position.x = 0.0;
  this->move_delta.z = 0.0;
  this->move_delta.y = 0.0;
  this->move_delta.x = 0.0;
  *(_QWORD *)&this->move.stage = 0x100000000LL;
  *(_QWORD *)&this->move.acceleration = 0x100000000LL;
  *(_QWORD *)&this->move.deceleration = 0x100000000LL;
  *(_QWORD *)&this->move.dir.y = 0x100000000LL;
  do
  {
    *++p_soundFlags = 0;
    --v4;
  }
  while ( v4 != 0 );
  this->clipModelInfo.type = CLIPMODEL_RENDERMODEL;
  idEntity::SetClipReplicationFlags(this, dynamicClipReplication: true, dynamicClipReplicationAxis: true);
  return this;
}


// ========================================================================
// __unwind$509927
// EA  : 0x82C8828C
// RVA : 0x00C8828C
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_509927()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$509928
// EA  : 0x82C882B4
// RVA : 0x00C882B4
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_509928()
{
  int v0; // r12

  idPhysics_Parametric::~idPhysics_Parametric(this: (idPhysics_Parametric *)(*(_DWORD *)(v0 - 144 + 164) + 800));
}


// ========================================================================
// __unwind$509929
// EA  : 0x82C882E0
// RVA : 0x00C882E0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_509929()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 2248));
}


// ========================================================================
// __unwind$509930
// EA  : 0x82C8830C
// RVA : 0x00C8830C
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_509930()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2360));
}


// ========================================================================
// __unwind$509931
// EA  : 0x82C88338
// RVA : 0x00C88338
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_509931()
{
  int v0; // r12

  idMover::navSpace_t::~navSpace_t(this: (idMover::navSpace_t *)(*(_DWORD *)(v0 - 144 + 164) + 2376));
}


// ========================================================================
// ?Event_Crush@idMover@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82C883D0
// RVA : 0x00C883D0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_Crush(idMover *this, idWorldspawn *result, idAI2 *blockingEntity)
{
  float v3; // r9
  float maxTexelDensity; // r7
  float y; // r4
  double v11; // fp3
  double v12; // fp6
  double v13; // fp3
  idActor *v14; // r3
  int v15; // r3
  idBaseHealth *v16; // r3
  int v17; // r3
  const idSoundShader *z_low; // r5
  idAI2 *v19; // r29
  idPhysics *Physics; // r3
  float *v21; // r3
  double v22; // fp30
  double v23; // fp29
  double v24; // fp28
  double v25; // fp12
  double v26; // fp10
  double v27; // fp1
  double z; // fp27
  double v29; // fp26
  double x; // fp25
  idPhysics *v31; // r3
  float *v32; // r3
  idPhysics *v33; // r3
  idRenderWorld_vtbl *v34; // r26
  int v35; // r3
  idPhysics *v36; // r28
  idPhysics *v37; // r26
  float *v38; // r3
  double v39; // fp8
  double v40; // fp7
  idRenderWorld_vtbl *v41; // r28
  int v42; // r3
  idPhysics *v43; // r28
  idPhysics *v44; // r26
  int v45; // r21
  float *v46; // r3
  double v47; // fp12
  double v48; // fp10
  const idVec3 *v49; // r3
  idPresentable *presentable; // r28
  int PlayerGameTime; // r3
  idAI2_vtbl *v52; // r28
  __int64 v53; // r8
  __int64 v54; // r6
  int v55; // r3
  __int64 v56; // r10
  va *v57; // r3
  idStr *v58; // r28
  idIndex<short,enum invalidJointIndex_t> *v59; // r26
  idAnimator_AF *v60; // r3
  int v61; // r26
  idAnimator_AF *v62; // r3
  idPhysics *v63; // r3
  double v64; // fp31
  double v65; // fp30
  double v66; // fp29
  float *v67; // r3
  double v68; // fp10
  double v69; // fp9
  idPhysics *v70; // r28
  idPhysics *v71; // r26
  int *p_physicsObj; // r25
  double v73; // fp31
  double v74; // fp30
  double v75; // fp29
  float *v76; // r3
  double v77; // fp9
  double v78; // fp8
  idPhysics *v79; // r3
  int v80; // r28
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  int v82; // r3
  int v83; // r28
  int v84; // r3
  int v85; // r3
  int v86; // r3
  idPhysics *v87; // r3
  idPhysics *v88; // r3
  char *data; // r29
  const char *v90; // r30
  int GameMs; // r3
  int v93; // [sp+8h] [-1278h]
  int v94; // [sp+Ch] [-1274h]
  int v95; // [sp+10h] [-1270h]
  int v96; // [sp+14h] [-126Ch]
  int v97; // [sp+18h] [-1268h]
  int v98; // [sp+1Ch] [-1264h]
  _BYTE v99[80]; // [sp+50h] [-1230h] BYREF
  int entityNumber; // [sp+A0h] [-11E0h] BYREF
  float v101; // [sp+A8h] [-11D8h]
  float v102; // [sp+ACh] [-11D4h]
  float maxVisibleRange; // [sp+B0h] [-11D0h]
  idVec3 v104; // [sp+B8h] [-11C8h] BYREF
  float v105[4]; // [sp+C8h] [-11B8h] BYREF
  float v106[4]; // [sp+D8h] [-11A8h] BYREF
  idVec3 v107; // [sp+E8h] [-1198h] BYREF
  float v108[4]; // [sp+100h] [-1180h] BYREF
  float v109[4]; // [sp+110h] [-1170h] BYREF
  float v110[8]; // [sp+120h] [-1160h] BYREF
  trace_t v111; // [sp+140h] [-1140h] BYREF
  idStr v112; // [sp+1C0h] [-10C0h] BYREF
  va v113; // [sp+1E0h] [-10A0h] BYREF

  v3 = *((float *)&result[2].renderModelInfo + 1);
  maxTexelDensity = result[2].renderModelInfo.maxTexelDensity;
  maxVisibleRange = result[2].renderModelInfo.maxVisibleRange;
  v101 = v3;
  v102 = maxTexelDensity;
  y = result[2].clipModelInfo.size.y;
  _FP6 = (float)((float)((float)(v101 * v101)
                       + (float)((float)(maxVisibleRange * maxVisibleRange) + (float)(v102 * v102)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f13 }
  v11 = __frsqrte(_FP4);
  v12 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11
                                                                                      * (float)((float)((float)(v101 * v101) + (float)((float)(maxVisibleRange * maxVisibleRange) + (float)(v102 * v102)))
                                                                                              * (float)0.5))
                                                                              * (float)v11)
                                                                      - (float)1.5)
                                                      * (float)v11)
                                              * (float)((float)((float)(v101 * v101)
                                                              + (float)((float)(maxVisibleRange * maxVisibleRange)
                                                                      + (float)(v102 * v102)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v11
                                                                              * (float)((float)((float)(v101 * v101)
                                                                                              + (float)((float)(maxVisibleRange * maxVisibleRange) + (float)(v102 * v102)))
                                                                                      * (float)0.5))
                                                                      * (float)v11)
                                                              - (float)1.5)
                                              * (float)v11))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v11
                                                      * (float)((float)((float)(v101 * v101)
                                                                      + (float)((float)(maxVisibleRange * maxVisibleRange)
                                                                              + (float)(v102 * v102)))
                                                              * (float)0.5))
                                              * (float)v11)
                                      - (float)1.5)
                      * (float)v11));
  v13 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)(v101 * v101) + (float)((float)(maxVisibleRange * maxVisibleRange) + (float)(v102 * v102))) * (float)0.5)) * (float)v11) - (float)1.5)
                                                                                              * (float)v11)
                                                                                      * (float)((float)((float)(v101 * v101) + (float)((float)(maxVisibleRange * maxVisibleRange) + (float)(v102 * v102)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v11 * (float)((float)((float)(v101 * v101) + (float)((float)(maxVisibleRange * maxVisibleRange) + (float)(v102 * v102))) * (float)0.5)) * (float)v11) - (float)1.5)
                                                                                      * (float)v11))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v11
                                                                                              * (float)((float)((float)(v101 * v101) + (float)((float)(maxVisibleRange * maxVisibleRange) + (float)(v102 * v102))) * (float)0.5))
                                                                                      * (float)v11)
                                                                              - (float)1.5)
                                                              * (float)v11))
                                              * (float)((float)((float)(v101 * v101)
                                                              + (float)((float)(maxVisibleRange * maxVisibleRange)
                                                                      + (float)(v102 * v102)))
                                                      * (float)0.5))
                                      * (float)v12)
                              - (float)1.5)
              * (float)v12);
  v101 = v3 * (float)v13;
  v102 = maxTexelDensity * (float)v13;
  maxVisibleRange = maxVisibleRange * (float)v13;
  if ( y != 0.0 )
  {
    if ( blockingEntity == nullptr )
      goto LABEL_17;
    if ( (unsigned __int8)idActor::IsTypeOf(c: blockingEntity) != 0 )
    {
      v14 = idActor::CastTo(c: blockingEntity);
      if ( v14 != nullptr )
      {
        v15 = (int)v14->GetHealthComponent(this: v14);
        if ( v15 != 0 && (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v15 + 88))(a1: v15) == 0 )
          idEntity::StartSoundShader(
            this: result,
            channel: SND_CHANNEL_ANY,
            shader: (const idSoundShader *)LODWORD(result[2].clipModelInfo.size.z),
            soundShaderFlags: (soundShaderFlags_t)0,
            peerMask: 0xFFu);
      }
    }
    if ( ((double (__fastcall *)(idAI2 *, idWorldspawn *, idWorldspawn *, _DWORD, double))blockingEntity->Damage)(
           a1: blockingEntity,
           a2: result,
           a3: result,
           a4: LODWORD(result[2].clipModelInfo.size.y),
           a5: 1.0) > 0.0
      && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) > SLODWORD(result[2].clipModelInfo.size.x)
      && (unsigned __int8)idActor::IsTypeOf(c: blockingEntity) != 0 )
    {
      v16 = blockingEntity->GetHealthComponent_2(this: blockingEntity);
      if ( v16 != nullptr && !v16->IsDead_Impl(this: v16) )
      {
        v17 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        z_low = (const idSoundShader *)LODWORD(result[2].clipModelInfo.size.z);
        LODWORD(result[2].clipModelInfo.size.x) = v17 + 500;
        idEntity::StartSoundShader(
          this: result,
          channel: SND_CHANNEL_ANY,
          shader: z_low,
          soundShaderFlags: (soundShaderFlags_t)0,
          peerMask: 0xFFu);
      }
    }
  }
  if ( blockingEntity != nullptr && blockingEntity->TakesDamage(this: blockingEntity) )
    ((void (__fastcall *)(idAI2 *, idWorldspawn *, idWorldspawn *, _DWORD, double))blockingEntity->Damage)(
      a1: blockingEntity,
      a2: result,
      a3: result,
      a4: LODWORD(result[2].clipModelInfo.size.y),
      a5: 1.0);
LABEL_17:
  if ( HIBYTE(result[2].bindInfo.bindToJoint.data) != 0
    && result[2].bindInfo.bindToTag.baseBuffer[4] == 0
    && blockingEntity != nullptr
    && LODWORD(result[2].clipModelInfo.size.y) != 0
    && (unsigned __int8)idAI2::IsTypeOf(c: blockingEntity) != 0 )
  {
    v19 = idAI2::CastTo(c: blockingEntity);
    if ( v19 != nullptr )
    {
      entityNumber = blockingEntity->entityNumber;
      *(_DWORD *)result[2].bindInfo.bindToTag.baseBuffer = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
      Physics = idEntity::GetPhysics(this: result);
      v21 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v22 = *(float *)&result[2].bindInfo.bindAnim.len;
      v23 = *(float *)&result[2].bindInfo.bindToTag.baseBuffer[16];
      v24 = *(float *)&result[2].bindInfo.bindToTag.baseBuffer[12];
      v25 = (float)(v21[2] - *(float *)&result[2].bindInfo.bindAnim.len);
      v26 = (float)(v21[1] - *(float *)&result[2].bindInfo.bindToTag.baseBuffer[16]);
      v104.x = *v21 - *(float *)&result[2].bindInfo.bindToTag.baseBuffer[12];
      v104.z = v25;
      v104.y = v26;
      v27 = idVec3::NormalizeFast(this: &v104);
      z = v104.z;
      v29 = v104.y;
      x = v104.x;
      if ( g_debugMover.valueInteger != 0 )
      {
        v110[3] = 1.0;
        v110[1] = v23;
        v110[2] = v22;
        v110[0] = v24;
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, int, int, _DWORD, double))clientGame->renderWorld->DebugSphere)(
          a1: clientGame->renderWorld,
          a2: &idColor::colorRed,
          a3: v110,
          a4: 12,
          a5: 10000,
          a6: 0,
          a7: v27);
        v31 = idEntity::GetPhysics(this: result);
        v32 = (float *)v31->GetOrigin(this: v31, a2: 0);
        v108[0] = *v32;
        v108[1] = v32[1];
        v108[2] = v32[2];
        v108[3] = 1.0;
        clientGame->renderWorld->DebugSphere(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorCyan,
          a3: (const idSphere *)v108,
          a4: 12,
          a5: 10000,
          a6: false);
        v33 = idEntity::GetPhysics(this: result);
        v34 = clientGame->renderWorld->__vftable;
        v35 = (int)v33->GetOrigin(this: v33, a2: 0);
        v34->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorYellow,
          a3: (const idVec3 *)&result[2].bindInfo.bindToTag.baseBuffer[12],
          a4: (const idVec3 *)v35,
          a5: 10000,
          a6: false);
        v36 = idEntity::GetPhysics(this: result);
        v37 = idEntity::GetPhysics(this: result);
        v38 = (float *)v36->GetOrigin(this: v36, a2: 0);
        v39 = v38[1];
        v40 = (float)(v38[2] + (float)((float)z * (float)36.0));
        v106[0] = (float)((float)x * (float)36.0) + *v38;
        v106[2] = v40;
        v106[1] = (float)v39 + (float)((float)v29 * (float)36.0);
        v41 = clientGame->renderWorld->__vftable;
        v42 = (int)v37->GetOrigin(this: v37, a2: 0);
        v41->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorRed,
          a3: (const idVec3 *)v42,
          a4: (const idVec3 *)v106,
          a5: 10000,
          a6: false);
      }
      v43 = idEntity::GetPhysics(this: result);
      v44 = idEntity::GetPhysics(this: result);
      v45 = result->entityNumber;
      v46 = (float *)v43->GetOrigin(this: v43, a2: 0);
      v47 = (float)(v46[2] + (float)((float)z * (float)36.0));
      v48 = (float)(v46[1] + (float)((float)v29 * (float)36.0));
      v107.x = (float)((float)x * (float)36.0) + *v46;
      v107.z = v47;
      v107.y = v48;
      v49 = v44->GetOrigin(this: v44, a2: 0);
      idClip::TracePoint(
        this: &clientGame->clip,
        result: &v111,
        start: v49,
        end: &v107,
        clipMask: 8462469,
        passEntityNumber: v45);
      if ( !v19->aiHealth.IsDead_Impl(this: &v19->aiHealth) )
        ((void (__fastcall *)(idAI2 *, idWorldspawn *, idWorldspawn *, _DWORD, double))v19->Damage)(
          a1: v19,
          a2: result,
          a3: result,
          a4: LODWORD(result[2].clipModelInfo.size.y),
          a5: 100.0);
      presentable = v19->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: v19);
        presentable = v19->presentable;
      }
      PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
      idFXManager::StartFX(
        this: &presentable->fxManager,
        org: &v111.endpos,
        axis: &v111.endAxis,
        time: PlayerGameTime,
        startCondition: 109);
      v52 = v19->__vftable;
      memcpy(Dst: v99, Src: &v111.endAxis.mat[2].z, Size: sizeof(v99));
      ((void (__fastcall *)(int *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v52->GetJointIndexFromTrace)(
        a1: &entityNumber,
        a2: LODWORD(v111.fraction),
        a3: LODWORD(v111.endpos.y),
        a4: LODWORD(v111.endAxis.mat[0].x),
        a5: LODWORD(v111.endAxis.mat[0].z),
        a6: LODWORD(v111.endAxis.mat[1].y),
        a7: LODWORD(v111.endAxis.mat[2].x),
        a8: LODWORD(v111.endAxis.mat[2].y));
      if ( v19->GetAF_2(this: v19) != nullptr )
      {
        v55 = (int)v19->GetAF_2(this: v19);
        if ( v55 != -288 )
        {
          HIDWORD(v54) = *(_DWORD *)&result[2].bindInfo.bindToJoint.baseBuffer[4];
          LODWORD(v56) = &v112;
          LODWORD(v110[4]) = &v112;
          HIDWORD(v56) = v55 + 288;
          v57 = va::va(
                  this: &v113,
                  fmt: "%s",
                  a3: v54,
                  a4: v53,
                  a5: v56,
                  a6: v93,
                  a7: v94,
                  a8: v95,
                  a9: v96,
                  a10: v97,
                  a11: v98);
          v58 = idStr::idStr(this: &v112, text: v57);
          v59 = (idIndex<short,enum invalidJointIndex_t> *)HIWORD(entityNumber);
          v60 = v19->GetAF_2(this: v19);
          v61 = idAnimator_AF::BodyForJoint(this: v60, joint: v59);
          v62 = v19->GetAF_2(this: v19);
          idAnimator_AF::AddDynamicBindConstraint(this: v62, bodyIndex: v61, constraintName: v58);
        }
      }
      idEntity::Bind(this: v19, master: result, orientated: true);
      if ( v19->GetAF_2(this: v19) != nullptr && v19->GetAF_2(this: v19) != (idAnimator_AF *)-288 )
      {
        if ( g_debugMover.valueInteger != 0 )
        {
          v63 = idEntity::GetPhysics(this: result);
          v64 = (float)(*(float *)&result[2].bindInfo.bindToJoint.allocedAndFlag * (float)x);
          v65 = (float)((float)v29 * *(float *)&result[2].bindInfo.bindToJoint.allocedAndFlag);
          v66 = (float)((float)z * *(float *)&result[2].bindInfo.bindToJoint.allocedAndFlag);
          v67 = (float *)v63->GetOrigin(this: v63, a2: 0);
          v68 = *v67;
          v69 = (float)(v67[1] + (float)v65);
          v109[2] = v67[2] + (float)v66;
          v109[1] = v69;
          v109[3] = 1.0;
          v109[0] = (float)v64 + (float)v68;
          clientGame->renderWorld->DebugSphere(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorYellow,
            a3: (const idSphere *)v109,
            a4: 12,
            a5: 5000,
            a6: false);
        }
        v70 = idEntity::GetPhysics(this: result);
        v71 = idEntity::GetPhysics(this: result);
        p_physicsObj = (int *)&v19->GetAF_2(this: v19)->physicsObj;
        v73 = (float)(*(float *)&result[2].bindInfo.bindToJoint.allocedAndFlag * (float)x);
        v74 = (float)((float)v29 * *(float *)&result[2].bindInfo.bindToJoint.allocedAndFlag);
        v75 = (float)((float)z * *(float *)&result[2].bindInfo.bindToJoint.allocedAndFlag);
        v76 = (float *)v71->GetOrigin(this: v71, a2: 0);
        v77 = (float)(v76[2] + (float)v75);
        v78 = (float)(v76[1] + (float)v74);
        v105[0] = (float)v73 + *v76;
        v105[2] = v77;
        v79 = v70;
        v105[1] = v78;
        GetAxis = v70->GetAxis;
        v80 = *p_physicsObj;
        v82 = (int)GetAxis(this: v79, a2: 0);
        (*(void (__fastcall **)(int *, int, float *, int, int))(v80 + 272))(
          a1: p_physicsObj,
          a2: 1,
          a3: v105,
          a4: v82,
          a5: 1);
        v83 = 0;
        v84 = (int)v19->GetAF_2(this: v19);
        if ( (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)(v84 + 288)) > 0 )
        {
          do
          {
            v85 = (int)v19->GetAF_2(this: v19);
            (*(void (__fastcall **)(int, _DWORD, int))(*(_DWORD *)(v85 + 288) + 24))(a1: v85 + 288, a2: 0, a3: -1);
            ++v83;
            v86 = (int)v19->GetAF_2(this: v19);
          }
          while ( v83 < (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)(v86 + 288)) );
        }
        result[2].bindInfo.bindToTag.baseBuffer[4] = 1;
        v87 = idEntity::GetPhysics(this: result);
        *(_DWORD *)&result[2].bindInfo.bindToTag.baseBuffer[8] = v87->GetContents(this: v87, a2: -1);
        v88 = idEntity::GetPhysics(this: result);
        v88->SetContents(this: v88, a2: 0, a3: -1);
      }
    }
  }
  if ( g_debugMover.valueInteger != 0 )
  {
    if ( blockingEntity != nullptr )
      data = blockingEntity->name.data;
    else
      data = "<null>";
    v90 = result->name.data;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(fmt: "%d: '%s' blocked by '%s'\n", GameMs, v90, data);
  }
  return this;
}


// ========================================================================
// __unwind$510263
// EA  : 0x82C88DE4
// RVA : 0x00C88DE4
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_510263()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 4736 + 304));
}


// ========================================================================
// ?Event_BreakConstraint@idMover@@AAA?AVeventVoid@@XZ
// EA  : 0x82C88E10
// RVA : 0x00C88E10
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_BreakConstraint(idMover *this, idEntity *result)
{
  int physics; // r10
  idEntity *v5; // r3
  int v6; // r9
  idEntity *v7; // r3
  idEntity *v8; // r3
  int v9; // r9
  idEntity *v10; // r3
  idAI2 *v11; // r3
  idAI2 *v12; // r31
  idPhysics *v13; // r29
  idPhysics *v14; // r27
  int *p_physicsObj; // r26
  int v16; // r30
  int v17; // r29
  int v18; // r3
  int v19; // r30
  int v20; // r3
  int v21; // r3
  idAFBody *Body; // r3
  idAFBody::afBodyFlags_t fl; // r8
  int v24; // r3
  idAnimator_AF *v25; // r3
  int v26; // r3

  physics = (int)result[2].physics;
  if ( gameLocal->spawnIds.ptr[physics & 0x1FFF] == physics >> 13 )
  {
    v5 = gameLocal->entities.ptr[physics & 0x1FFF];
    if ( v5 != nullptr && idEntity::CastTo(c: v5) != nullptr )
    {
      v6 = (int)result[2].physics;
      if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13 && (v7 = gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
        v8 = idEntity::CastTo(c: v7);
      else
        v8 = nullptr;
      if ( (unsigned __int8)idAI2::IsTypeOf(c: v8) != 0 )
      {
        v9 = (int)result[2].physics;
        if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 && (v10 = gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
          v11 = (idAI2 *)idEntity::CastTo(c: v10);
        else
          v11 = nullptr;
        v12 = idAI2::CastTo(c: v11);
        v13 = idEntity::GetPhysics(this: result);
        v14 = idEntity::GetPhysics(this: result);
        p_physicsObj = (int *)&v12->GetAF_2(this: v12)->physicsObj;
        v16 = *p_physicsObj;
        v17 = (int)v13->GetAxis(this: v13, a2: 0);
        v18 = (int)v14->GetOrigin(this: v14, a2: 0);
        (*(void (__fastcall **)(int *, _DWORD, int, int, int))(v16 + 272))(
          a1: p_physicsObj,
          a2: 0,
          a3: v18,
          a4: v17,
          a5: 1);
        v19 = 0;
        v20 = (int)v12->GetAF_2(this: v12);
        if ( (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)(v20 + 288)) > 0 )
        {
          do
          {
            v21 = (int)v12->GetAF_2(this: v12);
            Body = idPhysics_AF::GetBody(this: (idPhysics_AF *)(v21 + 288), id: v19++);
            fl = Body->fl;
            Body->clipMask = 4097;
            Body->fl = (idAFBody::afBodyFlags_t)(*(_BYTE *)&fl | 0x80);
            v24 = (int)v12->GetAF_2(this: v12);
          }
          while ( v19 < (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)(v24 + 288)) );
        }
        v25 = v12->GetAF_2(this: v12);
        idAnimator_AF::RemoveBindConstraints(this: v25);
        v26 = (int)v12->GetAF_2(this: v12);
        (*(void (__fastcall **)(int))(*(_DWORD *)(v26 + 288) + 152))(a1: v26 + 288);
      }
    }
  }
  return this;
}


// ========================================================================
// ?Event_ImpaleFinished@idMover@@AAA?AVeventVoid@@XZ
// EA  : 0x82C89070
// RVA : 0x00C89070
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_ImpaleFinished(idMover *this, idEntity *result)
{
  idPhysics *v4; // r3
  idEntityPtr<idEntity> *p_physics; // r30
  int physics; // r9
  idEntity *v8; // r3
  idEntity *v9; // r3
  idEntity *v10; // r3
  idAI2 *v11; // r3
  idAI2 *v12; // r31
  int v13; // r30
  int v14; // r3
  int v15; // r3
  idAFBody *Body; // r3
  idAFBody::afBodyFlags_t fl; // r8
  int v18; // r3

  if ( *((_BYTE *)&result[2].physics + 4) != 0 )
  {
    p_physics = (idEntityPtr<idEntity> *)&result[2].physics;
    physics = (int)result[2].physics;
    if ( gameLocal->spawnIds.ptr[physics & 0x1FFF] == physics >> 13 )
    {
      v8 = gameLocal->entities.ptr[physics & 0x1FFF];
      if ( v8 != nullptr && idEntity::CastTo(c: v8) != nullptr )
      {
        if ( gameLocal->spawnIds.ptr[p_physics->spawnId.value & 0x1FFF] == p_physics->spawnId.value >> 13
          && (v9 = gameLocal->entities.ptr[p_physics->spawnId.value & 0x1FFF]) != nullptr )
        {
          v10 = idEntity::CastTo(c: v9);
        }
        else
        {
          v10 = nullptr;
        }
        if ( (unsigned __int8)idAI2::IsTypeOf(c: v10) != 0 )
        {
          v11 = (idAI2 *)idEntityPtr<idEntity const>::operator->(this: p_physics);
          v12 = idAI2::CastTo(c: v11);
          v13 = 0;
          v14 = (int)v12->GetAF_2(this: v12);
          if ( (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)(v14 + 288)) > 0 )
          {
            do
            {
              v15 = (int)v12->GetAF_2(this: v12);
              Body = idPhysics_AF::GetBody(this: (idPhysics_AF *)(v15 + 288), id: v13++);
              fl = Body->fl;
              Body->clipMask = 4097;
              Body->fl = (idAFBody::afBodyFlags_t)(*(_BYTE *)&fl | 0x80);
              v18 = (int)v12->GetAF_2(this: v12);
            }
            while ( v13 < (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)(v18 + 288)) );
          }
        }
      }
    }
    return this;
  }
  else
  {
    *((_BYTE *)&result[2].physics + 4) = 1;
    v4 = idEntity::GetPhysics(this: result);
    HIDWORD(result[2].touchTriggersQuery.index) = v4->GetContents(this: v4, a2: -1);
    return this;
  }
}


// ========================================================================
// ??0idSplinePath@@QAA@XZ
// EA  : 0x82C89210
// RVA : 0x00C89210
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idSplinePath *__fastcall idSplinePath::idSplinePath(idSplinePath *this)
{
  idLinkList<idSplinePath> *head; // r3

  idEntity::idEntity(this);
  this->__vftable = (idSplinePath_vtbl *)&idSplinePath::`vftable';
  this->controlPoints.list = nullptr;
  this->controlPoints.granularity = 0;
  this->controlPoints.memTag = 5;
  this->controlPoints.listStatic = 0;
  this->controlPoints.size = 0;
  this->controlPoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->controlPoints);
  this->weightPoints.list = nullptr;
  this->weightPoints.granularity = 0;
  this->weightPoints.memTag = 5;
  this->weightPoints.listStatic = 0;
  this->weightPoints.size = 0;
  this->weightPoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->weightPoints);
  this->controlNode.owner = nullptr;
  this->controlNode.head = &this->controlNode;
  this->controlNode.next = &this->controlNode;
  this->controlNode.prev = &this->controlNode;
  this->anchorStart.spawnId.value = 0x1FFF;
  this->anchorEnd.spawnId.value = 0x1FFF;
  this->splineChildEntities.list = nullptr;
  this->splineChildEntities.granularity = 0;
  this->splineChildEntities.memTag = 5;
  this->splineChildEntities.listStatic = 0;
  this->splineChildEntities.size = 0;
  this->splineChildEntities.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splineChildEntities);
  this->type = CatmullRomSpline;
  this->graphDef = nullptr;
  this->allocedSpline = nullptr;
  this->cachedSplineLength = 0.0;
  head = gameLocal->splinePathEntities.head;
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
  return this;
}


// ========================================================================
// __unwind$510925
// EA  : 0x82C89354
// RVA : 0x00C89354
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_510925()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$510926
// EA  : 0x82C8937C
// RVA : 0x00C8937C
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_510926()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 804));
}


// ========================================================================
// __unwind$510927
// EA  : 0x82C893A8
// RVA : 0x00C893A8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_510927()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 820));
}


// ========================================================================
// __unwind$510928
// EA  : 0x82C893D4
// RVA : 0x00C893D4
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_510928()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                           + 836));
}


// ========================================================================
// ??1idSplinePath@@UAA@XZ
// EA  : 0x82C89408
// RVA : 0x00C89408
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idSplinePath::~idSplinePath(idSplinePath *this)
{
  idLinkList<idSplinePath> *p_controlNode; // r29

  this->__vftable = (idSplinePath_vtbl *)&idSplinePath::`vftable';
  p_controlNode = &this->controlNode;
  this->controlNode.prev->next = this->controlNode.next;
  this->controlNode.next->prev = this->controlNode.prev;
  this->controlNode.next = &this->controlNode;
  this->controlNode.prev = &this->controlNode;
  this->controlNode.head = &this->controlNode;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splineChildEntities);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)p_controlNode);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->weightPoints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->controlPoints);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$511039
// EA  : 0x82C89488
// RVA : 0x00C89488
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_511039()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$511040
// EA  : 0x82C894B0
// RVA : 0x00C894B0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_511040()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 804));
}


// ========================================================================
// __unwind$511041
// EA  : 0x82C894DC
// RVA : 0x00C894DC
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_511041()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 820));
}


// ========================================================================
// __unwind$511042
// EA  : 0x82C89508
// RVA : 0x00C89508
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_511042()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                           + 836));
}


// ========================================================================
// ??0idSplinePathWithOrientation@@QAA@XZ
// EA  : 0x82C89540
// RVA : 0x00C89540
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idSplinePathWithOrientation *__fastcall idSplinePathWithOrientation::idSplinePathWithOrientation(
        idSplinePathWithOrientation *this)
{
  idSplinePath::idSplinePath(this);
  this->__vftable = (idSplinePathWithOrientation_vtbl *)&idSplinePathWithOrientation::`vftable';
  this->controlPointRotations.list = nullptr;
  this->controlPointRotations.granularity = 0;
  this->controlPointRotations.memTag = 5;
  this->controlPointRotations.listStatic = 0;
  this->controlPointRotations.size = 0;
  this->controlPointRotations.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->controlPointRotations);
  this->useSplineForward = true;
  return this;
}


// ========================================================================
// __unwind$511091
// EA  : 0x82C895BC
// RVA : 0x00C895BC
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_511091()
{
  int v0; // r12

  idSplinePath::~idSplinePath(this: *(idSplinePath **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idSplinePathWithOrientation@@UAA@XZ
// EA  : 0x82C895F0
// RVA : 0x00C895F0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idSplinePathWithOrientation::~idSplinePathWithOrientation(idSplinePathWithOrientation *this)
{
  this->__vftable = (idSplinePathWithOrientation_vtbl *)&idSplinePathWithOrientation::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->controlPointRotations);
  idSplinePath::~idSplinePath(this);
}


// ========================================================================
// __unwind$511112
// EA  : 0x82C89644
// RVA : 0x00C89644
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_511112()
{
  int v0; // r12

  idSplinePath::~idSplinePath(this: *(idSplinePath **)(v0 - 112 + 132));
}


// ========================================================================
// ?Compare@idSort_SplineLoc@@QBAHABV?$idEntityPtr@VidEntity@@@@0@Z
// EA  : 0x82C89670
// RVA : 0x00C89670
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

int __fastcall idSort_SplineLoc::Compare(
        idSort_SplineLoc *this,
        const idEntityPtr<idEntity> *a,
        const idEntityPtr<idEntity> *b)
{
  idGameLocal *v4; // r11
  idEntity *v5; // r3
  idEntity *v6; // r3
  idEntity *v7; // r30
  idEntity *v8; // r3
  idEntity *v9; // r31
  float *p_lengthOnSpline; // r30

  v4 = gameLocal;
  if ( gameLocal->spawnIds.ptr[a->spawnId.value & 0x1FFF] == a->spawnId.value >> 13
    && (v5 = gameLocal->entities.ptr[a->spawnId.value & 0x1FFF]) != nullptr )
  {
    v6 = idEntity::CastTo(c: v5);
    v4 = gameLocal;
    v7 = v6;
  }
  else
  {
    v7 = nullptr;
  }
  if ( v4->spawnIds.ptr[b->spawnId.value & 0x1FFF] == b->spawnId.value >> 13
    && (v8 = v4->entities.ptr[b->spawnId.value & 0x1FFF]) != nullptr )
  {
    v9 = idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  p_lengthOnSpline = &v7->GetSplineLocation(this: v7)->lengthOnSpline;
  return (int)(float)(*p_lengthOnSpline - v9->GetSplineLocation(this: v9)->lengthOnSpline);
}


// ========================================================================
// ??1idMoverModifier@@UAA@XZ
// EA  : 0x82C89768
// RVA : 0x00C89768
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverModifier::~idMoverModifier(idMoverModifier *this)
{
  this->__vftable = (idMoverModifier_vtbl *)&idMoverModifier::`vftable';
  splineMoverModifier_t::~splineMoverModifier_t(this: &this->modifier);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$511363
// EA  : 0x82C897BC
// RVA : 0x00C897BC
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_511363()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idMoverMM@@QAA@XZ
// EA  : 0x82C897F0
// RVA : 0x00C897F0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverMM *__fastcall idMoverMM::idMoverMM(idMoverMM *this)
{
  float w; // r11
  int *p_collideClipMask; // r11
  int v4; // ctr

  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idMoverMM_vtbl *)&idMoverMM::`vftable';
  idPhysics_ParametricMM::idPhysics_ParametricMM(this: &this->physicsObj);
  this->soundFlags = 0;
  this->contentsFlags = CONTENTS_SOLID;
  this->move_speed = 0.0;
  this->forwardSpline = true;
  this->move_time = 1;
  this->deceltime = 0;
  this->acceltime = 0;
  this->dest_quat.x = quat_identity.x;
  this->dest_quat.y = quat_identity.y;
  this->dest_quat.z = quat_identity.z;
  w = quat_identity.w;
  this->health = 0.0;
  this->dest_quat.w = w;
  this->spline = nullptr;
  this->splinePath = nullptr;
  this->splineMoverModifiers = nullptr;
  this->useSplineAngles = true;
  this->ignoreSplinePitch = false;
  this->stopRotation = false;
  this->lastCommand = MOVER_NONE;
  this->applyAnimationOffsetOnNextFrame = false;
  this->crunchSoundTime = 0;
  this->crushDamage = nullptr;
  this->sndCrush = nullptr;
  this->noPush = true;
  this->sndAccel = nullptr;
  this->sndDecel = nullptr;
  this->sndMove = nullptr;
  this->sndVolumeInterpolaters.list = nullptr;
  this->sndVolumeInterpolaters.granularity = 0;
  this->sndVolumeInterpolaters.memTag = 5;
  this->sndVolumeInterpolaters.listStatic = 0;
  this->sndVolumeInterpolaters.size = 0;
  this->sndVolumeInterpolaters.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sndVolumeInterpolaters);
  this->sndPitchInterpolaters.list = nullptr;
  this->sndPitchInterpolaters.granularity = 0;
  this->sndPitchInterpolaters.memTag = 5;
  this->sndPitchInterpolaters.listStatic = 0;
  this->sndPitchInterpolaters.size = 0;
  this->sndPitchInterpolaters.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sndPitchInterpolaters);
  this->guiTargets.list = nullptr;
  this->guiTargets.granularity = 0;
  this->guiTargets.memTag = 5;
  this->guiTargets.listStatic = 0;
  this->guiTargets.size = 0;
  this->guiTargets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->guiTargets);
  this->dest_angles.roll = 0.0;
  this->dest_angles.yaw = 0.0;
  this->dest_angles.pitch = 0.0;
  this->dest_position.z = 0.0;
  this->dest_position.y = 0.0;
  this->dest_position.x = 0.0;
  this->move_delta.z = 0.0;
  this->move_delta.y = 0.0;
  p_collideClipMask = &this->physicsObj.collideClipMask;
  this->move_delta.x = 0.0;
  this->initialSpeed = 0.0;
  this->skipInitialForcedModifiers = false;
  this->splineTotalLength = 0.0;
  this->splineModifierIndex = -1;
  this->splineModifierLengthOffset = 0.0;
  v4 = 6;
  this->modifierIgnoreFlags = MOVERMODIFIER_NONE;
  do
  {
    p_collideClipMask += 2;
    *(_QWORD *)p_collideClipMask = 0xFFFFFFFF00000000uLL;
    --v4;
  }
  while ( v4 != 0 );
  p_collideClipMask[2] = 0;
  *(_QWORD *)&this->rot.stage = 0x100000000LL;
  *(_QWORD *)&this->rot.movetime = 0x100000000LL;
  *(_QWORD *)&this->rot.vec.x = 0x100000000LL;
  *(_QWORD *)&this->rot.vec.z = 0x100000000LL;
  this->clipModelInfo.type = CLIPMODEL_RENDERMODEL;
  this->animationOffsetAxis.mat[2].z = 1.0;
  this->animationOffsetAxis.mat[1].y = 1.0;
  this->animationOffsetAxis.mat[0].x = 1.0;
  this->animationOffsetAxis.mat[1].z = 0.0;
  this->animationOffsetAxis.mat[0].z = 0.0;
  this->animationOffsetAxis.mat[0].y = 0.0;
  this->animationOffsetAxis.mat[2].y = 0.0;
  this->animationOffsetAxis.mat[2].x = 0.0;
  this->animationOffsetAxis.mat[1].x = 0.0;
  this->animationOffsetTranslation.z = 0.0;
  this->animationOffsetTranslation.y = 0.0;
  this->animationOffsetTranslation.x = 0.0;
  return this;
}


// ========================================================================
// __unwind$511381
// EA  : 0x82C899FC
// RVA : 0x00C899FC
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_511381()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$511382
// EA  : 0x82C89A24
// RVA : 0x00C89A24
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_511382()
{
  int v0; // r12

  idPhysics_ParametricMM::~idPhysics_ParametricMM(this: (idPhysics_ParametricMM *)(*(_DWORD *)(v0 - 144 + 164) + 5200));
}


// ========================================================================
// __unwind$511383
// EA  : 0x82C89A50
// RVA : 0x00C89A50
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_511383()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 7460));
}


// ========================================================================
// __unwind$511384
// EA  : 0x82C89A7C
// RVA : 0x00C89A7C
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_511384()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 7476));
}


// ========================================================================
// ??1idMoverMM@@UAA@XZ
// EA  : 0x82C89AB0
// RVA : 0x00C89AB0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::~idMoverMM(idMoverMM *this)
{
  this->__vftable = (idMoverMM_vtbl *)&idMoverMM::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->guiTargets);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sndPitchInterpolaters);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sndVolumeInterpolaters);
  idPhysics_ParametricMM::~idPhysics_ParametricMM(this: &this->physicsObj);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$511577
// EA  : 0x82C89B1C
// RVA : 0x00C89B1C
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_511577()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$511578
// EA  : 0x82C89B44
// RVA : 0x00C89B44
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_511578()
{
  int v0; // r12

  idPhysics_ParametricMM::~idPhysics_ParametricMM(this: (idPhysics_ParametricMM *)(*(_DWORD *)(v0 - 112 + 132) + 5200));
}


// ========================================================================
// __unwind$511579
// EA  : 0x82C89B70
// RVA : 0x00C89B70
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_511579()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 7460));
}


// ========================================================================
// __unwind$511580
// EA  : 0x82C89B9C
// RVA : 0x00C89B9C
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_511580()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 7476));
}


// ========================================================================
// ?ModifierIsType@idMoverMM@@IBA_NABUsplineMoverModifier_t@@W4moverModifierFunction_t@@@Z
// EA  : 0x82C89BC8
// RVA : 0x00C89BC8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

int __fastcall idMoverMM::ModifierIsType(idMoverMM *this, const splineMoverModifier_t *mod, moverModifierFunction_t t)
{
  int result; // r3
  char *str; // r11
  char v7; // r11
  bool v8; // zf
  char *v9; // r11
  char v10; // r11

  if ( (t & 0x4000) != 0 && !mod->BlendToAnimSpeed.blendToAnimSpeed
    || (t & 2) != 0 && !mod->Speed.setNewMoveSpeed
    || (t & 4) != 0 && !mod->Orientation.setNewOrientation
    || (t & 0x200) != 0 && !mod->Oscillation.setNewOscillation
    || (t & 8) != 0 && !mod->Offset.setNewOffset && !mod->Offset.setNewOffsetScale )
  {
    return 0;
  }
  if ( (t & 0x10) != 0 )
  {
    str = (char *)mod->Script.scriptFunction.str;
    if ( str == &byte_8200D768 || (v8 = *str != 0, v7 = 0, !v8) )
      v7 = 1;
    if ( v7 != 0 )
    {
      v9 = (char *)mod->Script.notifyData.str;
      if ( v9 == &byte_8200D768 || (v8 = *v9 != 0, v10 = 0, !v8) )
        v10 = 1;
      if ( v10 != 0 )
        return 0;
    }
  }
  if ( (t & 0x20) != 0 && mod->Pause.pauseTime <= 0.0
    || (t & 0x40) != 0 && idEntityPtr<idSplinePath>::operator idSplinePath *(this: &mod->Spline.splinePath) == nullptr
    || (t & 0x80) != 0 && mod->Targets.targets.num <= 0
    || (t & 0x100) != 0 && !mod->Reverse.reverse
    || (t & 0x400) != 0
    && mod->Sound.volume.num <= 0
    && mod->Sound.pitch.num <= 0
    && mod->Sound.stopSounds.num <= 0
    && mod->Sound.newSounds.num <= 0
    || (t & 0x800) != 0 && mod->SpawnEntity.spawnDef == nullptr
    || (t & 0x1000) != 0
    && mod->Animation.animationToPlay.value == 0xFFFF
    && mod->Animation.webAnimation.len <= 0
    && mod->Animation.webViaAnimation.len <= 0
    || (t & 0x2000) != 0 && !mod->VehicleProperties.setVehicleProperties
    || (t & 0x10000) != 0 && (*((_BYTE *)&mod->AiProperties + 36) & 0x80) == 0
    || (t & 0x20000) != 0 && mod->RailEvent.type == RAIL_EVENT_NONE
    || (t & 0x40000) != 0 && idEntityPtr<idEntity const>::operator->(this: &mod->MeleeEvent.meleeTarget) == nullptr )
  {
    return 0;
  }
  if ( (t & 0x80000) == 0 )
    return 1;
  result = 0;
  if ( mod->SwarmEntity.range != 0.0 )
    return 1;
  return result;
}


// ========================================================================
// ?GetNextModifier@idMoverMM@@IBAPBUsplineMoverModifier_t@@W4moverModifierFunction_t@@AAM@Z
// EA  : 0x82C89E78
// RVA : 0x00C89E78
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

const splineMoverModifier_t *__fastcall idMoverMM::GetNextModifier(
        idMoverMM *this,
        moverModifierFunction_t t,
        float *splinePos)
{
  int v6; // r27
  const idList<splineMoverModifier_t,5> *splineMoverModifiers; // r11
  int splineModifierIndex; // r29
  int v9; // r30
  splineMoverModifier_t *list; // r11
  float *p_length; // r31

  v6 = 1;
  if ( !this->forwardSpline )
    v6 = -1;
  splineMoverModifiers = this->splineMoverModifiers;
  splineModifierIndex = this->splineModifierIndex;
  if ( splineMoverModifiers != nullptr )
  {
    v9 = splineModifierIndex;
    while ( splineModifierIndex < splineMoverModifiers->num && splineModifierIndex >= 0 )
    {
      list = splineMoverModifiers->list;
      p_length = &list[v9].length;
      if ( &list[v9] != nullptr && (unsigned __int8)idMoverMM::ModifierIsType(this, mod: &list[v9], t) != 0 )
      {
        *splinePos = *p_length;
        return (const splineMoverModifier_t *)p_length;
      }
      splineMoverModifiers = this->splineMoverModifiers;
      splineModifierIndex += v6;
      v9 += v6;
      if ( splineMoverModifiers == nullptr )
        break;
    }
  }
  if ( v6 <= 0 )
  {
    *splinePos = 0.0;
    return nullptr;
  }
  else
  {
    *splinePos = this->spline->GetLengthForTime(
                   this: this->spline,
                   a2: this->spline->times.list[this->spline->values.num - 1]);
    return nullptr;
  }
}


// ========================================================================
// ?UpdateSound@idMoverMM@@IAAXXZ
// EA  : 0x82C89F78
// RVA : 0x00C89F78
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::UpdateSound(idMoverMM *this, int a2, int a3, int a4, int a5)
{
  __int64 v5; // r10
  int v7; // r29
  int v8; // r30
  double SplineSpeed; // fp31
  double CurrentValue; // fp30
  int value; // r9
  idEntity *v12; // r3
  idEntity *v13; // r4
  idSoundEmitter *BestSoundEmitter; // r3
  int v15; // r28
  int i; // r29
  double v17; // fp1
  double v18; // fp30
  idInterpolate<float> *p_interpolater; // r11
  double v20; // fp0
  double duration; // fp13
  double v22; // fp31
  int v23; // r9
  idEntity *v24; // r3
  idEntity *v25; // r3
  idEntity *v26; // r30
  idSoundEmitter *SoundEmitter; // r3

  LODWORD(v5) = 0x82000000;
  HIDWORD(v5) = this->sndVolumeInterpolaters.num;
  v7 = 0;
  if ( SHIDWORD(v5) > 0 )
  {
    v8 = 0;
    do
    {
      if ( this->sndVolumeInterpolaters.list[v8].interpolater.duration != 0.0 )
      {
        SplineSpeed = idPhysics_ParametricMM::GetSplineSpeed(this: &this->physicsObj, a2, a3, a4, a5, a6: v5);
        CurrentValue = idInterpolate<float>::GetCurrentValue(
                         this: &this->sndVolumeInterpolaters.list[v8].interpolater,
                         time: SplineSpeed);
        value = this->sndVolumeInterpolaters.list[v8].targetEmitter.spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v12 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v13 = idEntity::CastTo(c: v12);
        }
        else
        {
          v13 = nullptr;
        }
        BestSoundEmitter = idMoverMM::GetBestSoundEmitter(this, ent: v13);
        if ( BestSoundEmitter != nullptr )
        {
          BestSoundEmitter->SetVolume(
            this: BestSoundEmitter,
            a2: this->sndVolumeInterpolaters.list[v8].channel,
            a3: CurrentValue);
          if ( g_debugMoverSpeedSoundBindings.valueInteger != 0 )
            idLib::Printf(fmt: "Speed: %f \tVolume: %f \n", SplineSpeed, CurrentValue);
        }
      }
      ++v7;
      ++v8;
    }
    while ( v7 < this->sndVolumeInterpolaters.num );
  }
  v15 = 0;
  if ( this->sndPitchInterpolaters.num > 0 )
  {
    LODWORD(v5) = off_822F0000;
    for ( i = 0; this->sndPitchInterpolaters.list[i].interpolater.duration == 0.0; ++i )
    {
LABEL_34:
      if ( ++v15 >= this->sndPitchInterpolaters.num )
        return;
    }
    v17 = idPhysics_ParametricMM::GetSplineSpeed(this: &this->physicsObj, a2, a3, a4, a5, a6: v5);
    v18 = v17;
    p_interpolater = &this->sndPitchInterpolaters.list[i].interpolater;
    v20 = (float)((float)v17 - p_interpolater->startTime);
    if ( v17 != this->sndPitchInterpolaters.list[i].interpolater.currentTime )
    {
      duration = this->sndPitchInterpolaters.list[i].interpolater.duration;
      this->sndPitchInterpolaters.list[i].interpolater.currentTime = v17;
      if ( duration < 0.0 )
      {
        if ( v20 >= 0.0 )
        {
          p_interpolater->currentValue = p_interpolater->startValue;
          goto LABEL_21;
        }
        if ( v20 > duration )
        {
LABEL_20:
          p_interpolater->currentValue = (float)((float)((float)(p_interpolater->endValue - p_interpolater->startValue)
                                                       / (float)duration)
                                               * (float)v20)
                                       + p_interpolater->startValue;
          goto LABEL_21;
        }
      }
      else
      {
        if ( v20 <= 0.0 )
        {
          p_interpolater->currentValue = p_interpolater->startValue;
          goto LABEL_21;
        }
        if ( v20 < duration )
          goto LABEL_20;
      }
      p_interpolater->currentValue = p_interpolater->endValue;
    }
LABEL_21:
    v22 = p_interpolater->currentValue;
    v23 = this->sndPitchInterpolaters.list[i].targetEmitter.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v23 & 0x1FFF] == v23 >> 13
      && (v24 = gameLocal->entities.ptr[v23 & 0x1FFF]) != nullptr
      && (v25 = idEntity::CastTo(c: v24), v26 = v25, v25 != nullptr)
      && idEntity::GetSoundEmitter(this: v25, alloc: true) != nullptr
      && (SoundEmitter = idEntity::GetSoundEmitter(this: v26, alloc: false)) != nullptr
      || (SoundEmitter = idEntity::GetSoundEmitter(this, alloc: true)) != nullptr )
    {
      SoundEmitter->SetPitch(this: SoundEmitter, a2: this->sndPitchInterpolaters.list[i].channel, a3: v22);
      if ( g_debugMoverSpeedSoundBindings.valueInteger != 0 )
        idLib::Printf(fmt: (const char *)HIDWORD(v18), LODWORD(v18), LODWORD(v22), v18, v22);
    }
    else
    {
      idLib::Warning(fmt: "Unable to get sound emitter for mover: %s", this->name.data);
    }
    goto LABEL_34;
  }
}


// ========================================================================
// ?UpdateMoverAttachments@idMoverMM@@IAAXXZ
// EA  : 0x82C8A290
// RVA : 0x00C8A290
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::UpdateMoverAttachments(idMoverMM *this)
{
  idMoverMM *TeamMaster; // r3
  idMoverAttachment *i; // r31
  int v4; // r11
  char v5; // r11
  bool v6; // zf
  idMoverAttachment *v7; // r3

  TeamMaster = (idMoverMM *)idEntity::GetTeamMaster(this);
  if ( TeamMaster == this )
  {
    for ( i = (idMoverAttachment *)TeamMaster->bindInfo.teamChain;
          i != nullptr;
          i = (idMoverAttachment *)i->bindInfo.teamChain )
    {
      v4 = *(_DWORD *)(i->GetType(this: i) + 36);
      if ( v4 < idMoverAttachment::Type.typeNum || (v6 = v4 <= idMoverAttachment::Type.lastChild, v5 = 1, !v6) )
        v5 = 0;
      if ( v5 != 0 )
      {
        v7 = idMoverAttachment::CastTo(c: i);
        idMoverAttachment::ManualThink(this: v7);
      }
    }
  }
}


// ========================================================================
// ?StartSplineExplicit@idMoverMM@@MAA_NPAV?$idCurve_Spline@VidVec3@@@@_NM@Z
// EA  : 0x82C8A340
// RVA : 0x00C8A340
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

int __fastcall idMoverMM::StartSplineExplicit(
        idMoverMM *this,
        idCurve_Spline<idVec3> *spline,
        char startFromEnd,
        double startTime)
{
  int move_time; // r11
  int acceltime; // r10
  int deceltime; // r9
  int v12; // r9
  soundShaderFlags_t soundFlags; // r6
  double LengthBetweenKnots; // fp1
  __int64 v15; // r5
  bool useSplineAngles; // r26
  idPhysics_ParametricMM *p_physicsObj; // r29
  int v18; // r3
  bool v19; // r6
  int v20; // r3
  __int64 v21; // r10
  int v22; // r8
  int v23; // r7
  int v24; // r6
  const float *v25; // r5
  const float *v26; // r4
  double initialSpeed; // fp2
  __int64 v28; // r10
  int v29; // r8
  int v30; // r7
  int v31; // r6
  const float *v32; // r5
  const float *v33; // r4
  double v34; // fp1
  __int64 v35; // r10
  int v36; // r8
  int v37; // r7
  int v38; // r6
  const float *v39; // r5
  const float *v40; // r4
  const idList<splineMoverModifier_t,5> *v41; // r11
  int v42; // r10
  int splineModifierIndex; // r11
  int v44; // r11
  bool v45; // cr32
  const idList<splineMoverModifier_t,5> *splineMoverModifiers; // r11
  idPhysics_ParametricMM_vtbl *v47; // r31
  int v48; // r27
  int v49; // r3
  idRenderWorld *v50; // r31
  __int64 v51; // r7
  __int64 v52; // [sp+50h] [-50h]

  this->spline = spline;
  this->splinePath = nullptr;
  if ( spline == nullptr )
    return 0;
  move_time = this->move_time;
  if ( move_time == 0 && this->move_speed <= 0.0 )
  {
    idLib::Warning(fmt: "startSpline for '%s' called without a valid move_time or move_speed!", this->name.data);
    return 0;
  }
  acceltime = this->acceltime;
  deceltime = this->deceltime;
  this->lastCommand = MOVER_SPLINE;
  if ( deceltime + acceltime > move_time )
  {
    acceltime = move_time / 2;
    this->acceltime = move_time / 2;
    this->deceltime = move_time - move_time / 2;
  }
  v12 = this->deceltime;
  this->move.acceleration = acceltime;
  this->move.stage = FINISHED_STAGE;
  this->move.movetime = move_time;
  soundFlags = this->soundFlags;
  this->move.deceleration = v12;
  idEntity::StartSoundShader(
    this,
    channel: SND_CHANNEL_BODY,
    shader: this->sndMove,
    soundShaderFlags: soundFlags,
    peerMask: 0xFFu);
  LengthBetweenKnots = idCurve<idVec3>::GetLengthBetweenKnots(this: spline, i0: 0, i1: spline->values.num - 1);
  if ( this->move_time == 0 )
  {
    if ( this->move_speed == 0.0 )
      this->move_speed = 1.0;
    this->move_time = (int)(float)((float)((float)1000.0 / this->move_speed) * (float)LengthBetweenKnots);
  }
  this->splineTotalLength = spline->GetLengthForTime(this: spline, a2: spline->times.list[spline->values.num - 1]);
  HIDWORD(v15) = 1;
  useSplineAngles = this->useSplineAngles;
  p_physicsObj = &this->physicsObj;
  LODWORD(v15) = this->move_time;
  v52 = v15;
  v18 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idPhysics_ParametricMM::SetSpline(
    this: &this->physicsObj,
    spline,
    startTime: v18,
    totalTime: (float)v52,
    useSplineAngles: v19,
    startAtEnd: useSplineAngles,
    startSplineTime: startTime,
    a8: startFromEnd);
  v20 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idPhysics_ParametricMM::SetLinearExtrapolation(
    this: &this->physicsObj,
    type: EXTRAPOLATION_NONE,
    currentTime: v20,
    duration: (unsigned int)&this->dest_position,
    base: &vec3_origin,
    speed: &vec3_origin);
  initialSpeed = this->initialSpeed;
  if ( initialSpeed > 0.0 )
  {
    idPhysics_ParametricMM::SetSplineExplicitSpeed(
      this: &this->physicsObj,
      startSpeed: this->initialSpeed,
      endSpeed: initialSpeed,
      endPos: 0.0,
      a5: v26,
      a6: v25,
      a7: v24,
      a8: v23,
      a9: v22,
      a10: v21);
    if ( startFromEnd != 0 )
    {
      idPhysics_ParametricMM::SetSplineContinue(
        this: &this->physicsObj,
        endPos: 0.0,
        a3: v33,
        a4: v32,
        a5: v31,
        a6: v30,
        a7: v29,
        a8: v28);
      splineMoverModifiers = this->splineMoverModifiers;
      if ( splineMoverModifiers != nullptr )
        v42 = splineMoverModifiers->num - 1;
      else
        v42 = 0;
      v44 = this->splineModifierIndex - 2;
      v45 = v44 < 0;
    }
    else
    {
      v34 = ((double (__fastcall *)(idCurve_Spline<idVec3> *, double))spline->GetLengthForTime)(
              a1: spline,
              a2: spline->times.list[spline->values.num - 1]);
      idPhysics_ParametricMM::SetSplineContinue(
        this: &this->physicsObj,
        endPos: v34,
        a3: v40,
        a4: v39,
        a5: v38,
        a6: v37,
        a7: v36,
        a8: v35);
      v41 = this->splineMoverModifiers;
      if ( v41 != nullptr )
      {
        v42 = v41->num - 1;
        splineModifierIndex = this->splineModifierIndex;
      }
      else
      {
        splineModifierIndex = this->splineModifierIndex;
        v42 = 0;
      }
      v44 = splineModifierIndex + 2;
      v45 = v44 < 0;
    }
    if ( v45 )
    {
      v44 = 0;
    }
    else if ( v44 > v42 )
    {
      v44 = v42;
    }
    this->splineModifierIndex = v44;
  }
  v47 = p_physicsObj->__vftable;
  v48 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v49 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  v47->Evaluate(this: p_physicsObj, a2: v49, a3: v48);
  if ( g_showSwarmSplines.valueInteger != 0 )
  {
    v50 = gameLocal->GetRenderWorld(this: gameLocal);
    LODWORD(v51) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    HIDWORD(v51) = (idRenderWorld)v50->__vftable;
    ((void (__fastcall *)(idRenderWorld *, idColor *, idCurve_Spline<idVec3> *, idRenderWorld_vtbl *, int, int, int, double))v50->DebugSpline)(
      a1: v50,
      a2: &idColor::colorMagenta,
      a3: spline,
      a4: v50->__vftable,
      a5: 1,
      a6: 5000,
      a7: 1,
      a8: (float)((float)v51 * (float)0.001));
  }
  return 1;
}


// ========================================================================
// ?HandleInitialModifiers@idMoverMM@@MAA_NPBV?$idList@UsplineMoverModifier_t@@$04@@@Z
// EA  : 0x82C8A708
// RVA : 0x00C8A708
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

BOOL __fastcall idMoverMM::HandleInitialModifiers(
        idMoverMM *this,
        const idList<splineMoverModifier_t,5> *customModifiers)
{
  const idList<splineMoverModifier_t,5> *p_moverModifiers; // r11
  idSplinePathMM *splinePath; // r11
  bool v5; // zf
  idCurve_Spline<idVec3> *spline; // r3
  char v7; // r10
  bool v8; // r25
  bool v9; // r24
  bool v10; // r23
  double v11; // fp1
  const idList<splineMoverModifier_t,5> *splineMoverModifiers; // r11
  double v13; // fp30
  float *p_length; // r30
  __int64 v15; // r10
  int v16; // r8
  int v17; // r7
  int v18; // r6
  const float *v19; // r5
  const float *v20; // r4
  double v21; // fp3
  idMat3 *v22; // r3
  idQuat *v23; // r3
  double v24; // fp7
  double v25; // fp6
  double v26; // fp4
  idPhysics_ParametricMM_vtbl *v27; // r28
  idMat3 *v28; // r3
  __int64 v29; // r10
  int v30; // r7
  int v31; // r6
  idPhysics_ParametricMM_vtbl *v32; // r27
  idMat3 *v33; // r3
  const idQuat *v34; // r27
  idMat3 *v35; // r3
  __int64 v36; // r10
  int v37; // r7
  int v38; // r6
  float v40[4]; // [sp+50h] [-F0h] BYREF
  idAngles v41; // [sp+60h] [-E0h] BYREF
  idMat3 v42; // [sp+70h] [-D0h] BYREF
  float v43; // [sp+94h] [-ACh]
  float v44; // [sp+98h] [-A8h]
  float v45; // [sp+9Ch] [-A4h]
  idAngles v46; // [sp+A0h] [-A0h] BYREF
  idQuat v47[3]; // [sp+B0h] [-90h] BYREF

  p_moverModifiers = customModifiers;
  if ( customModifiers == nullptr )
  {
    splinePath = this->splinePath;
    v5 = splinePath != nullptr;
    p_moverModifiers = &splinePath->moverModifiers;
    if ( !v5 )
      p_moverModifiers = nullptr;
  }
  this->splineMoverModifiers = p_moverModifiers;
  spline = this->spline;
  v7 = _cntlzw(this->skipInitialForcedModifiers);
  this->splineModifierIndex = 0;
  v8 = (v7 & 0x20) != 0;
  v9 = v8;
  v10 = v8;
  v11 = ((double (__fastcall *)(idCurve_Spline<idVec3> *, double))spline->GetLengthForTime)(
          a1: spline,
          a2: spline->times.list[spline->values.num - 1]);
  splineMoverModifiers = this->splineMoverModifiers;
  v13 = v11;
  if ( splineMoverModifiers != nullptr && splineMoverModifiers->num > 0 )
  {
    p_length = &splineMoverModifiers->list->length;
    if ( splineMoverModifiers->list->length == 0.0 )
    {
      if ( (this->modifierIgnoreFlags & 0x8000) == 0 )
        idPhysics_ParametricMM::ForceSplineRest(this: &this->physicsObj);
      if ( (unsigned __int8)idMoverMM::ModifierIsType(
                              this,
                              mod: (const splineMoverModifier_t *)p_length,
                              t: MOVERMODIFIER_SPEED) != 0 )
      {
        LODWORD(v15) = this->modifierIgnoreFlags & 2;
        if ( (_DWORD)v15 == 0 )
        {
          if ( p_length[19] <= 0.0 )
            v21 = 0.0;
          else
            v21 = v13;
          idPhysics_ParametricMM::SetSplineExplicitSpeed(
            this: &this->physicsObj,
            startSpeed: p_length[19],
            endSpeed: p_length[19],
            endPos: v21,
            a5: v20,
            a6: v19,
            a7: v18,
            a8: v17,
            a9: v16,
            a10: v15);
          v8 = false;
        }
      }
      if ( (unsigned __int8)idMoverMM::ModifierIsType(
                              this,
                              mod: (const splineMoverModifier_t *)p_length,
                              t: MOVERMODIFIER_BLENDTOANIMSPEED) != 0
        && (this->modifierIgnoreFlags & 0x4000) == 0 )
      {
        this->HandleNextMoverModifier_BlendToAnimSpeed(this, a2: &this->physicsObj, a3: 0.0, a4: v13);
      }
      if ( (unsigned __int8)idMoverMM::ModifierIsType(
                              this,
                              mod: (const splineMoverModifier_t *)p_length,
                              t: MOVERMODIFIER_ORIENTATION) != 0
        && (this->modifierIgnoreFlags & 4) == 0 )
      {
        v9 = false;
        if ( *((_BYTE *)p_length + 53) != 0 )
        {
          idAngles::ToQuat(this: (idAngles *)&v42, result: (idQuat *)(p_length + 14));
          v22 = (idMat3 *)((int (__fastcall *)(idAngles *, double))this->spline->GetCurrentFirstDerivative)(
                            a1: &v41,
                            a2: 0.0);
          v23 = (idQuat *)idVec3::ToMat3(this: (idVec3 *)v47, result: v22);
          idMat3::ToQuat(this: (idMat3 *)&v42.mat[2].z, result: v23);
          v24 = -v42.mat[2].z;
          v25 = -v44;
          v26 = -v43;
          v27 = this->physicsObj.__vftable;
          v42.mat[1].y = -(float)((float)(v42.mat[0].y * (float)v25)
                                - (float)((float)(v42.mat[0].x * v45)
                                        + (float)((float)(v42.mat[0].z * (float)v26) + (float)(v42.mat[1].x * (float)v24))));
          v42.mat[1].z = -(float)((float)(v42.mat[0].z * (float)v24)
                                - (float)((float)(v42.mat[0].y * v45)
                                        + (float)((float)(v42.mat[1].x * (float)v26) + (float)((float)v25 * v42.mat[0].x))));
          v42.mat[2].x = -(float)((float)((float)v26 * v42.mat[0].x)
                                - (float)((float)(v42.mat[0].z * v45)
                                        + (float)((float)(v42.mat[1].x * (float)v25) + (float)(v42.mat[0].y * (float)v24))));
          v42.mat[2].y = -(float)((float)(v42.mat[0].z * (float)v25)
                                - (float)-(float)((float)(v42.mat[0].y * (float)v26)
                                                - (float)((float)(v42.mat[1].x * v45)
                                                        - (float)(v42.mat[0].x * (float)v24))));
          v28 = idQuat::ToMat3(this: v47, result: &v42);
          v27->SetAxis(this: &this->physicsObj, a2: v28, a3: -1);
          idPhysics_ParametricMM::SetSplineAngularInterpolation(
            this: &this->physicsObj,
            startQuat: (idMat3 *)&v42.mat[1].y,
            endQuat: (const idQuat *)&v42.mat[1].y,
            endPos: v13,
            a5: v31,
            a6: v30,
            a7: v29);
          idPhysics_ParametricMM::SetUseSplineAngles(this: &this->physicsObj, newUseSplineAngles: true);
          this->useSplineAngles = true;
        }
        else
        {
          v32 = this->physicsObj.__vftable;
          v33 = idAngles::ToMat3(this: (idAngles *)v47, result: (idMat3 *)(p_length + 14));
          v32->SetAxis(this: &this->physicsObj, a2: v33, a3: -1);
          v34 = idAngles::ToQuat(this: &v41, result: (idQuat *)(p_length + 14));
          v35 = (idMat3 *)idAngles::ToQuat(this: &v46, result: (idQuat *)(p_length + 14));
          idPhysics_ParametricMM::SetSplineAngularInterpolation(
            this: &this->physicsObj,
            startQuat: v35,
            endQuat: v34,
            endPos: v13,
            a5: v38,
            a6: v37,
            a7: v36);
          idPhysics_ParametricMM::SetUseSplineAngles(this: &this->physicsObj, newUseSplineAngles: false);
          this->useSplineAngles = false;
        }
      }
      if ( (unsigned __int8)idMoverMM::ModifierIsType(
                              this,
                              mod: (const splineMoverModifier_t *)p_length,
                              t: MOVERMODIFIER_OFFSET) != 0
        && (this->modifierIgnoreFlags & 8) == 0 )
      {
        v10 = false;
        if ( *((_BYTE *)p_length + 80) != 0 )
          ((void (__fastcall *)(_DWORD, _DWORD, _DWORD, double))this->SetSplineOffset)(
            a1: *((_DWORD *)p_length + 21),
            a2: *((_DWORD *)p_length + 22),
            a3: __ROL4__(*((_DWORD *)p_length + 23), 32),
            a4: 0.0);
        if ( *((_BYTE *)p_length + 96) != 0 )
          ((void (__fastcall *)(_DWORD, _DWORD, _DWORD, double))this->SetSplineOffsetScale)(
            a1: *((_DWORD *)p_length + 25),
            a2: *((_DWORD *)p_length + 26),
            a3: __ROL4__(*((_DWORD *)p_length + 27), 32),
            a4: 0.0);
      }
    }
  }
  if ( v9 && (this->modifierIgnoreFlags & 4) == 0 )
    this->HandleNextMoverModifier_Orientation(this, a2: &this->physicsObj, a3: 0.0, a4: v13);
  if ( v8 && (this->modifierIgnoreFlags & 2) == 0 )
  {
    if ( idMoverMM::GetNextModifier(this, t: MOVERMODIFIER_SPEED, splinePos: v40) == nullptr
      && this->initialSpeed == 0.0 )
    {
      idLib::Warning(fmt: "Mover %s has been started with no speed set", this->name.data);
    }
    this->HandleNextMoverModifier_Speed(this, a2: &this->physicsObj, a3: 0.0, a4: v13);
  }
  if ( !v10 || (this->modifierIgnoreFlags & 8) != 0 )
    return (_cntlzw(v8) & 0x20) != 0;
  this->HandleNextMoverModifier_Offset(this, a2: &this->physicsObj, a3: 0.0, a4: v13);
  return (_cntlzw(v8) & 0x20) != 0;
}


// ========================================================================
// ?OnActivate@idMoverMM@@EAAXPAVidEntity@@@Z
// EA  : 0x82C8ABE8
// RVA : 0x00C8ABE8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::OnActivate(idMoverMM *this, idEntity *activator)
{
  int value; // r9
  idEntity *v4; // r3
  idEntity *v5; // r5
  char v6; // [sp+50h] [-20h] BYREF

  ((void (__fastcall *)(idMoverMM *, idEntity *))this->Show)(a1: this, a2: activator);
  if ( this->targets.num > 0
    && (value = this->targets.list->spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
    && (v4 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v5 = idEntity::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  idMoverMM::Event_StartSpline(this: (idMoverMM *)&v6, result: (eventVoid *)this, splineEntity: v5);
}


// ========================================================================
// ?HandleNextMoverModifier_Speed@idMoverMM@@MAAXAAVidPhysics_ParametricMM@@MM@Z
// EA  : 0x82C8AC88
// RVA : 0x00C8AC88
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::HandleNextMoverModifier_Speed(
        idMoverMM *this,
        idPhysics_ParametricMM *physObj,
        double currentSplinePosition,
        double splineTotalLength)
{
  const splineMoverModifier_t *NextModifier; // r29
  __int64 v6; // r10
  int v7; // r8
  int v8; // r7
  int v9; // r6
  const float *v10; // r5
  const float *v11; // r4
  double v12; // fp8
  double v13; // fp7
  double v14; // fp6
  double v15; // fp5
  double v16; // fp4
  double v17; // fp3
  double v18; // fp2
  double v19; // fp1
  double v20; // fp1
  float v21; // [sp+8h] [-78h]
  float v22; // [sp+Ch] [-74h]
  float v23; // [sp+10h] [-70h]
  float v24; // [sp+14h] [-6Ch]
  float v25; // [sp+18h] [-68h]
  float v26; // [sp+1Ch] [-64h]
  float v27; // [sp+20h] [-60h]
  float v28; // [sp+24h] [-5Ch]
  float v29; // [sp+50h] [-30h] BYREF
  const float *v30; // [sp+54h] [-2Ch]

  NextModifier = idMoverMM::GetNextModifier(this, t: MOVERMODIFIER_SPEED, splinePos: &v29);
  if ( NextModifier != nullptr )
  {
    if ( NextModifier->Speed.moveTime <= 0.0 )
    {
      idPhysics_ParametricMM::SetSplineSpeed(
        this: physObj,
        speed: NextModifier->Speed.moveSpeed,
        endPos: v29,
        a4: v11,
        a5: v10,
        a6: v9,
        a7: v8,
        a8: v7,
        a9: v6);
      if ( g_debugMoverModifiers.valueInteger == 0 )
        return;
      idLib::Printf(fmt: "Setting new target speed: %f \n", NextModifier->Speed.moveSpeed);
    }
    else
    {
      v19 = v29;
      v30 = (const float *)(int)(float)(NextModifier->Speed.moveTime * (float)1000.0);
      idPhysics_ParametricMM::SetSplineTimes(
        this: physObj,
        time: v30,
        endPos: v19,
        a4: v10,
        a5: v9,
        a6: v18,
        a7: v17,
        a8: v16,
        a9: v15,
        a10: v14,
        a11: v13,
        a12: v12,
        a13: v8,
        a14: v6,
        a15: v21,
        a16: v22,
        a17: v23,
        a18: v24,
        a19: v25,
        a20: v26,
        a21: v27,
        a22: v28);
      if ( g_debugMoverModifiers.valueInteger == 0 )
        return;
      idLib::Printf(fmt: "Setting new moveTime: %f \n", NextModifier->Speed.moveTime);
    }
  }
  else
  {
    v20 = idPhysics_ParametricMM::SetSplineContinue(
            this: physObj,
            endPos: v29,
            a3: v11,
            a4: v10,
            a5: v9,
            a6: v8,
            a7: v7,
            a8: v6);
    if ( g_debugMoverModifiers.valueInteger == 0 )
      return;
    idLib::Printf(fmt: "Continuing at constant speed to end of spline. \n", v20);
  }
  if ( g_debugMoverModifiers.valueInteger != 0 )
    idPhysics_ParametricMM::PrintDebugSplineInterpolationDebug(this: physObj);
}


// ========================================================================
// ?HandleNextMoverModifier_Offset@idMoverMM@@MAAXAAVidPhysics_ParametricMM@@MM@Z
// EA  : 0x82C8AD98
// RVA : 0x00C8AD98
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::HandleNextMoverModifier_Offset(
        idMoverMM *this,
        idPhysics_ParametricMM *physObj,
        double currentSplinePosition,
        double splineTotalLength)
{
  __int64 v5; // r10
  int v6; // r8
  int v7; // r7
  int v8; // r6
  const splineMoverModifier_t *NextModifier; // r3
  const splineMoverModifier_t *v10; // r31
  double v11; // fp30
  float v12[2]; // [sp+50h] [-30h] BYREF

  NextModifier = idMoverMM::GetNextModifier(this, t: MOVERMODIFIER_OFFSET, splinePos: v12);
  v10 = NextModifier;
  if ( NextModifier != nullptr )
  {
    v11 = v12[0];
    if ( NextModifier->Offset.setNewOffset )
      idPhysics_ParametricMM::SetLocalOffset(
        this: (idPhysics_ParametricMM *)LODWORD(NextModifier->Offset.newOffset.x),
        newOffset: (idVec3 *)LODWORD(NextModifier->Offset.newOffset.y),
        startTime: currentSplinePosition,
        duration: (float)(v12[0] - (float)currentSplinePosition),
        a5: __ROL4__(LODWORD(NextModifier->Offset.newOffset.z), 32),
        a6: v8,
        a7: v7,
        a8: v6,
        a9: v5);
    if ( v10->Offset.setNewOffsetScale )
      idPhysics_ParametricMM::SetLocalScale(
        this: (idPhysics_ParametricMM *)LODWORD(v10->Offset.newOffsetScale.x),
        newScale: (idVec3 *)LODWORD(v10->Offset.newOffsetScale.y),
        startTime: currentSplinePosition,
        duration: (float)((float)v11 - (float)currentSplinePosition),
        a5: __ROL4__(LODWORD(v10->Offset.newOffsetScale.z), 32),
        a6: v8,
        a7: v7,
        a8: v6,
        a9: v5);
  }
}


// ========================================================================
// ?HandleNextMoverModifier_BlendToAnimSpeed@idMoverMM@@MAAXAAVidPhysics_ParametricMM@@MM@Z
// EA  : 0x82C8AE48
// RVA : 0x00C8AE48
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::HandleNextMoverModifier_BlendToAnimSpeed(
        idMoverMM *this,
        idPhysics_ParametricMM *physObj,
        double currentSplinePosition,
        double splineTotalLength)
{
  const splineMoverModifier_t *NextModifier; // r3
  const splineMoverModifier_t *v7; // r30
  int value; // r10
  idEntityPtr<idMoverAttachment> *p_animatedEntity; // r28
  idMoverAttachment *v10; // r3
  const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *p_animationToPlay; // r30
  idMoverAttachment *v12; // r3
  double v13; // fp1
  double v14; // fp30
  double v15; // fp31
  __int64 v16; // r10
  int v17; // r8
  int v18; // r7
  int v19; // r6
  const float *v20; // r5
  const float *v21; // r4
  const idQuat *v22; // r28
  idQuat *v23; // r3
  idMat3 *v24; // r3
  __int64 v25; // r10
  int v26; // r7
  int v27; // r6
  float v28[4]; // [sp+50h] [-A0h] BYREF
  idMat3 v29[2]; // [sp+60h] [-90h] BYREF

  NextModifier = idMoverMM::GetNextModifier(this, t: MOVERMODIFIER_ANIM, splinePos: v28);
  v7 = NextModifier;
  if ( NextModifier != nullptr )
  {
    value = NextModifier->Animation.animatedEntity.spawnId.value;
    p_animatedEntity = &NextModifier->Animation.animatedEntity;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v10 = (idMoverAttachment *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v10 != nullptr && idMoverAttachment::CastTo(c: v10) != nullptr )
      {
        p_animationToPlay = &v7->Animation.animationToPlay;
        if ( p_animationToPlay->value != 0xFFFF )
        {
          v12 = idEntityPtr<idMoverAttachment>::operator->(this: p_animatedEntity);
          v13 = idMoverAttachment::ComputeAnimationSpeed(
                  this: v12,
                  animAlias: p_animationToPlay,
                  firstFrameOrientation: (idMat3 *)&v29[0].mat[2].z);
          v14 = v28[0];
          v15 = v13;
          idPhysics_ParametricMM::SetSplineSpeed(
            this: physObj,
            speed: v13,
            endPos: v28[0],
            a4: v21,
            a5: v20,
            a6: v19,
            a7: v18,
            a8: v17,
            a9: v16);
          v22 = idMat3::ToQuat(this: v29, result: (idQuat *)&v29[0].mat[2].z);
          v23 = (idQuat *)physObj->GetAxis(this: physObj, a2: 0);
          v24 = (idMat3 *)idMat3::ToQuat(this: (idMat3 *)&v29[0].mat[1].y, result: v23);
          idPhysics_ParametricMM::SetSplineAngularInterpolation(
            this: physObj,
            startQuat: v24,
            endQuat: v22,
            endPos: v14,
            a5: v27,
            a6: v26,
            a7: v25);
          idPhysics_ParametricMM::SetUseSplineAngles(this: physObj, newUseSplineAngles: false);
          this->useSplineAngles = false;
          if ( g_debugMoverModifiers.valueInteger == 0 )
            return;
          HIWORD(v28[0]) = (idHandle<unsigned short,enum invalidAliasHandle_t,65535>)p_animationToPlay->value;
          idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
          animation->FindAliasName(
            this: animation,
            a2: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)v28);
          idLib::Printf(fmt: "Setting new target speed to %f from animation %s\n", v15, (const char *)LODWORD(v15));
        }
      }
    }
  }
  if ( g_debugMoverModifiers.valueInteger != 0 )
    idPhysics_ParametricMM::PrintDebugSplineInterpolationDebug(this: physObj);
}


// ========================================================================
// ?HandleMoverModifier_Anim@idMoverMM@@MAAXABUsplineMoverModifier_t@@AAVidPhysics_ParametricMM@@MM@Z
// EA  : 0x82C8AFE8
// RVA : 0x00C8AFE8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::HandleMoverModifier_Anim(
        idMoverMM *this,
        const splineMoverModifier_t *mod,
        idPhysics_ParametricMM *physObj,
        double currentSplinePosition,
        double splineTotalLength)
{
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *p_animationToPlay; // r26
  int value; // r10
  splineMoverModifier_t::splineMoverModifierAnimation_t *p_Animation; // r27
  idMoverAttachment *v10; // r3
  int v11; // r9
  idGameLocal *v12; // r11
  idSplinePath *v13; // r3
  blendParms_t *v14; // r5
  idMoverAttachment *v15; // r3
  idMoverAttachment *v16; // r3
  idMoverAttachment *v17; // r3
  char v18; // r30
  idMoverAttachment *v19; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r30
  idMat3 *p_deferredAxis; // r11
  char *v22; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  double x; // fp12
  double y; // fp11
  double v27; // fp3
  double z; // fp10
  double v29; // fp2
  double v30; // fp1
  double v31; // fp13
  double v32; // fp8
  double v33; // fp5
  double v34; // fp4
  double v35; // fp9
  double v36; // fp7
  double v37; // fp6
  double v38; // fp0
  idVec3 v39; // [sp+58h] [-C8h] BYREF
  blendParms_t v40; // [sp+70h] [-B0h] BYREF
  idStr v41; // [sp+90h] [-90h] BYREF
  idMat3 v42; // [sp+B0h] [-70h] BYREF

  p_animationToPlay = &mod->Animation.animationToPlay;
  if ( mod->Animation.animationToPlay.value != 0xFFFF )
  {
    value = mod->Animation.animatedEntity.spawnId.value;
    p_Animation = &mod->Animation;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v10 = (idMoverAttachment *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v10 != nullptr && idMoverAttachment::CastTo(c: v10) != nullptr )
      {
        blendParms_t::blendParms_t(this: &v40);
        blendParms_t::SetDestStartFrame(this: &v40, frame: 1);
        v11 = mod->Animation.splinePath.spawnId.value;
        v12 = gameLocal;
        if ( gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13 )
        {
          v13 = (idSplinePath *)gameLocal->entities.ptr[v11 & 0x1FFF];
          if ( v13 != nullptr )
          {
            idSplinePath::CastTo(c: v13);
            v12 = gameLocal;
          }
        }
        v14 = (blendParms_t *)v12->spawnIds.ptr[p_Animation->animatedEntity.spawnId.value & 0x1FFF];
        if ( v14 == (blendParms_t *)(p_Animation->animatedEntity.spawnId.value >> 13)
          && (v15 = (idMoverAttachment *)v12->entities.ptr[p_Animation->animatedEntity.spawnId.value & 0x1FFF]) != nullptr )
        {
          v16 = idMoverAttachment::CastTo(c: v15);
        }
        else
        {
          v16 = nullptr;
        }
        idMoverAttachment::PlayAnimation(
          this: v16,
          aliasAnim: p_animationToPlay,
          animRateScale: 1.0,
          blendParms: v14,
          preAnimationScriptFunction: &v40,
          postAnimationScriptFunction: &mod->Animation.preAnimationScriptFunction,
          splinePath: (idSplinePath *)&mod->Animation.postAnimationScriptFunction,
          splineTransitionTime: 1.0);
        idStr::idStr(this: &v41, text: "origin");
        if ( gameLocal->spawnIds.ptr[p_Animation->animatedEntity.spawnId.value & 0x1FFF] == p_Animation->animatedEntity.spawnId.value >> 13 )
        {
          v17 = (idMoverAttachment *)gameLocal->entities.ptr[p_Animation->animatedEntity.spawnId.value & 0x1FFF];
          if ( v17 != nullptr )
            v17 = idMoverAttachment::CastTo(c: v17);
        }
        else
        {
          v17 = nullptr;
        }
        v18 = idMoverAttachment::ComputeAnimationTranslationDelta(
                this: v17,
                animAlias: p_animationToPlay,
                jointName: &v41,
                startFrame: 0,
                endFrame: 1,
                deltaTrans: &v39,
                firstFrameOrientation: &v42);
        idStr::FreeData(this: &v41);
        if ( v18 != 0 )
        {
          v19 = idEntityPtr<idMoverAttachment>::operator->(this: &p_Animation->animatedEntity);
          TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v19);
          idTreeAnimator::SetRemoveOriginRotation(this: TreeAnimatorFromPresentable, removeRotation: true);
          idTreeAnimator::SetRemoveOriginRotation(this: TreeAnimatorFromPresentable, removeRotation: true);
          p_deferredAxis = &TreeAnimatorFromPresentable->deferredAxis;
          if ( !TreeAnimatorFromPresentable->useDeferredPosition )
            p_deferredAxis = &TreeAnimatorFromPresentable->g.axis;
          v22 = &v41.baseBuffer[16];
          p_z = (_DWORD *)&p_deferredAxis[-1].mat[2].z;
          for ( i = 9; i != 0; --i )
          {
            ++p_z;
            v22 += 4;
            *(_DWORD *)v22 = *p_z;
          }
          x = v42.mat[2].x;
          y = v42.mat[2].y;
          v27 = (float)(v42.mat[2].x * v39.z);
          z = v42.mat[2].z;
          v29 = (float)(v42.mat[2].y * v39.z);
          v30 = (float)(v42.mat[2].z * v39.z);
          v31 = v39.y;
          v32 = v42.mat[1].x;
          this->applyAnimationOffsetOnNextFrame = true;
          v33 = v42.mat[1].y;
          v34 = v42.mat[1].z;
          v35 = v42.mat[0].x;
          this->animationOffsetAxis.mat[0].x = v42.mat[0].x;
          v36 = v42.mat[0].y;
          v37 = v42.mat[0].z;
          this->animationOffsetAxis.mat[1].x = v32;
          this->animationOffsetAxis.mat[0].y = v36;
          this->animationOffsetAxis.mat[0].z = v37;
          this->animationOffsetAxis.mat[1].y = v33;
          this->animationOffsetAxis.mat[1].z = v34;
          v38 = v39.x;
          this->animationOffsetAxis.mat[2].x = x;
          this->animationOffsetAxis.mat[2].y = y;
          this->animationOffsetAxis.mat[2].z = z;
          this->animationOffsetTranslation.x = (float)((float)v35 * (float)v38)
                                             + (float)((float)((float)v32 * (float)v31) + (float)v27);
          this->animationOffsetTranslation.y = (float)((float)v36 * (float)v38)
                                             + (float)((float)((float)v33 * (float)v31) + (float)v29);
          this->animationOffsetTranslation.z = (float)((float)v37 * (float)v38)
                                             + (float)((float)((float)v34 * (float)v31) + (float)v30);
        }
      }
    }
  }
}


// ========================================================================
// __unwind$512340
// EA  : 0x82C8B2B4
// RVA : 0x00C8B2B4
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_512340()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 144));
}


// ========================================================================
// ?HandleMoverModifier_Vehicle@idMoverMM@@MAAXABUsplineMoverModifier_t@@AAVidPhysics_ParametricMM@@MM@Z
// EA  : 0x82C8B2E0
// RVA : 0x00C8B2E0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::HandleMoverModifier_Vehicle(
        idMoverMM *this,
        const splineMoverModifier_t *mod,
        idPhysics_ParametricMM *physObj,
        double currentSplinePosition,
        double splineTotalLength)
{
  int value; // r10
  idMoverAttachment *v7; // r3
  int v8; // r9
  idMoverAttachment *v9; // r3
  idMoverAttachment *v10; // r3
  double vehicleSteerAngle; // fp0
  idGameLocal *v12; // r10
  int v13; // r9
  idMoverAttachment *v14; // r3
  idMoverAttachment *v15; // r3
  int v16; // r9
  idMoverAttachment *v17; // r3
  idMoverAttachment *v18; // r3
  int v19; // r9
  idMoverAttachment *v20; // r3
  idMoverAttachment *v21; // r3

  if ( mod->VehicleProperties.setVehicleProperties )
  {
    value = mod->VehicleProperties.vehicleEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v7 = (idMoverAttachment *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v7 != nullptr && idMoverAttachment::CastTo(c: v7) != nullptr )
      {
        v8 = mod->VehicleProperties.vehicleEntity.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13
          && (v9 = (idMoverAttachment *)gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
        {
          v10 = idMoverAttachment::CastTo(c: v9);
        }
        else
        {
          v10 = nullptr;
        }
        vehicleSteerAngle = mod->VehicleProperties.vehicleSteerAngle;
        v12 = gameLocal;
        v10->vehicleAnimator.steerAngle = mod->VehicleProperties.vehicleSteerAngle;
        v10->vehicleAnimator.lastSteerAngle = vehicleSteerAngle;
        v10->vehicleAnimator.newSteerAngle = vehicleSteerAngle;
        v13 = mod->VehicleProperties.vehicleEntity.spawnId.value;
        if ( v12->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13
          && (v14 = (idMoverAttachment *)v12->entities.ptr[v13 & 0x1FFF]) != nullptr )
        {
          v15 = idMoverAttachment::CastTo(c: v14);
        }
        else
        {
          v15 = nullptr;
        }
        v15->vehicleAnimator.accelerating = mod->VehicleProperties.vehicleAccelerate;
        v16 = mod->VehicleProperties.vehicleEntity.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v16 & 0x1FFF] == v16 >> 13
          && (v17 = (idMoverAttachment *)gameLocal->entities.ptr[v16 & 0x1FFF]) != nullptr )
        {
          v18 = idMoverAttachment::CastTo(c: v17);
        }
        else
        {
          v18 = nullptr;
        }
        v18->vehicleAnimator.handBraking = mod->VehicleProperties.vehicleHandBraking;
        v19 = mod->VehicleProperties.vehicleEntity.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v19 & 0x1FFF] == v19 >> 13
          && (v20 = (idMoverAttachment *)gameLocal->entities.ptr[v19 & 0x1FFF]) != nullptr )
        {
          v21 = idMoverAttachment::CastTo(c: v20);
        }
        else
        {
          v21 = nullptr;
        }
        v21->vehicleAnimator.isReversing = mod->VehicleProperties.vehicleIsReversing;
      }
    }
  }
}


// ========================================================================
// ?clearSoundInterpolater@idMoverMM@@AAAXAAV?$idList@UmoverSoundInterpolater_t@idMoverMM@@$04@@W4soundChannel_t@@@Z
// EA  : 0x82C8B4A0
// RVA : 0x00C8B4A0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::clearSoundInterpolater(
        idMoverMM *this,
        idList<idMoverMM::moverSoundInterpolater_t,5> *interpolaters,
        soundChannel_t channel)
{
  int num; // r7
  int v4; // r11
  idMoverMM::moverSoundInterpolater_t *list; // r9
  int v6; // r10
  idMoverMM::moverSoundInterpolater_t *v7; // r8
  idMoverMM::moverSoundInterpolater_t *v8; // r11
  idMoverMM::moverSoundInterpolater_t *v9; // r10
  soundChannel_t *p_channel; // r8
  soundChannel_t *v11; // r7
  int v12; // ctr

  num = interpolaters->num;
  v4 = 0;
  if ( num > 0 )
  {
    list = interpolaters->list;
    v6 = 0;
    v7 = interpolaters->list;
    while ( v7->channel != channel )
    {
      ++v4;
      v7 = &list[++v6];
      if ( v4 >= interpolaters->num )
        return;
    }
    if ( v4 >= 0 && v4 < num )
    {
      interpolaters->num = num - 1;
      if ( v4 != num - 1 )
      {
        v9 = &list[v4];
        v8 = &list[num - 1];
        p_channel = &v8->channel;
        v11 = &v9->channel;
        v12 = 6;
        v9->targetEmitter.spawnId.value = v8->targetEmitter.spawnId.value;
        v9->channel = v8->channel;
        do
        {
          *++v11 = *++p_channel;
          --v12;
        }
        while ( v12 != 0 );
      }
    }
  }
}


// ========================================================================
// ?HandleMoverModifier_Spline@idMoverMM@@MAAXABUsplineMoverModifier_t@@AAVidPhysics_ParametricMM@@MM@Z
// EA  : 0x82C8B548
// RVA : 0x00C8B548
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::HandleMoverModifier_Spline(
        idMoverMM *this,
        const splineMoverModifier_t *mod,
        idPhysics_ParametricMM *physObj,
        double currentSplinePosition,
        double splineTotalLength,
        int a6,
        int a7,
        int a8,
        __int64 a9)
{
  int valueInteger; // r11
  int value; // r9
  idSplinePath *v14; // r3
  idSplinePath *v15; // r3
  int v16; // r9
  idSplinePath *v17; // r3
  idSplinePath *v18; // r3
  idRenderWorld *v19; // r24
  idRenderWorld_vtbl *v20; // r31
  const idBounds *v21; // r3
  double SplineSpeed; // fp1
  int v23; // r9
  double v24; // fp31
  idSplinePath *v25; // r3
  idSplinePath *v26; // r4
  unsigned int v27; // r10
  int v28; // r8
  int v29; // r7
  int v30; // r6
  const float *v31; // r5
  const float *v32; // r4
  double started; // fp1
  int *v34; // r30
  int v35; // r31
  const idBounds *v36; // r3
  _BYTE v37[16]; // [sp+50h] [-60h] BYREF

  valueInteger = g_debugMoverModifiers.valueInteger;
  if ( g_debugMoverModifiers.valueInteger != 0 )
  {
    value = mod->Spline.splinePath.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v14 = (idSplinePath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v15 = idSplinePath::CastTo(c: v14);
    }
    else
    {
      v15 = nullptr;
    }
    idLib::Printf(fmt: "Attaching to new spline: %s resetSpeed: %d \n", v15->name.data, mod->Spline.resetSpeed);
    valueInteger = g_debugMoverModifiers.valueInteger;
  }
  if ( mod->Spline.resetSpeed )
  {
    v16 = mod->Spline.splinePath.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v16 & 0x1FFF] == v16 >> 13
      && (v17 = (idSplinePath *)gameLocal->entities.ptr[v16 & 0x1FFF]) != nullptr )
    {
      v18 = idSplinePath::CastTo(c: v17);
      idMoverMM::Event_StartSpline(this: (idMoverMM *)v37, result: (eventVoid *)this, splineEntity: v18);
    }
    else
    {
      idMoverMM::Event_StartSpline(this: (idMoverMM *)v37, result: (eventVoid *)this, splineEntity: nullptr);
    }
  }
  else
  {
    LODWORD(a9) = allocationCurrent[242];
    if ( valueInteger != 0 )
    {
      v19 = gameLocal->GetRenderWorld(this: gameLocal);
      v20 = v19->__vftable;
      v21 = physObj->GetAbsBounds(this: physObj, a2: -1);
      v20->DebugBounds(
        this: v19,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: v21,
        a4: &vec3_origin,
        a5: 10000,
        a6: false);
    }
    SplineSpeed = idPhysics_ParametricMM::GetSplineSpeed(
                    this: physObj,
                    a2: (int)mod,
                    a3: (int)physObj,
                    a4: a6,
                    a5: a7,
                    a6: a9);
    v23 = mod->Spline.splinePath.spawnId.value;
    v24 = SplineSpeed;
    if ( gameLocal->spawnIds.ptr[v23 & 0x1FFF] == v23 >> 13
      && (v25 = (idSplinePath *)gameLocal->entities.ptr[v23 & 0x1FFF]) != nullptr )
    {
      v26 = idSplinePath::CastTo(c: v25);
    }
    else
    {
      v26 = nullptr;
    }
    if ( this->StartSpline(this, a2: v26, a3: false, a4: -1.0) )
    {
      if ( !this->HandleInitialModifiers(this, a2: nullptr) )
        started = idPhysics_ParametricMM::SetSplineStartSpeed(
                    this: physObj,
                    speed: v24,
                    a3: v32,
                    a4: v31,
                    a5: v30,
                    a6: v29,
                    a7: v28,
                    a8: v27);
      if ( g_debugMoverModifiers.valueInteger != 0 )
      {
        v34 = (int *)((int (__fastcall *)(idGameLocal *, double))gameLocal->GetRenderWorld)(a1: gameLocal, a2: started);
        v35 = *v34;
        v36 = physObj->GetAbsBounds(this: physObj, a2: -1);
        (*(void (__fastcall **)(int *, idColor *, const idBounds *, idVec3 *, int, _DWORD))(v35 + 220))(
          a1: v34,
          a2: &idColor::colorGreen,
          a3: v36,
          a4: &vec3_origin,
          a5: 10000,
          a6: 0);
      }
    }
  }
}


// ========================================================================
// ?HandleMoverModifier_Target@idMoverMM@@MAAXABUsplineMoverModifier_t@@AAVidPhysics_ParametricMM@@MM@Z
// EA  : 0x82C8B7E8
// RVA : 0x00C8B7E8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::HandleMoverModifier_Target(
        idMoverMM *this,
        const splineMoverModifier_t *mod,
        idPhysics_ParametricMM *physObj,
        double currentSplinePosition,
        double splineTotalLength)
{
  int v7; // r27
  int v8; // r31
  idGameLocal *v9; // r11
  int value; // r9
  idEntity *v11; // r3
  idEntity *v12; // r11
  int v13; // r9
  idEntity *v14; // r3
  int v15; // r9
  idEntity *v16; // r3
  idEntity *v17; // r3

  v7 = 0;
  if ( mod->Targets.targets.num > 0 )
  {
    v8 = 0;
    v9 = gameLocal;
    do
    {
      if ( g_debugMoverModifiers.valueInteger != 0 )
      {
        value = mod->Targets.targets.list[v8].spawnId.value;
        if ( v9->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v11 = v9->entities.ptr[value & 0x1FFF]) != nullptr )
          v12 = idEntity::CastTo(c: v11);
        else
          v12 = nullptr;
        idLib::Printf(fmt: "Activating target: %s \n", v12->name.data);
        v9 = gameLocal;
      }
      v13 = mod->Targets.targets.list[v8].spawnId.value;
      if ( v9->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13 )
      {
        v14 = v9->entities.ptr[v13 & 0x1FFF];
        if ( v14 != nullptr )
        {
          if ( idEntity::CastTo(c: v14) != nullptr )
          {
            v15 = mod->Targets.targets.list[v8].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v15 & 0x1FFF] == v15 >> 13
              && (v16 = gameLocal->entities.ptr[v15 & 0x1FFF]) != nullptr )
            {
              v17 = idEntity::CastTo(c: v16);
            }
            else
            {
              v17 = nullptr;
            }
            idEntity::Activate(this: v17, activator: this);
          }
          v9 = gameLocal;
        }
      }
      ++v7;
      ++v8;
    }
    while ( v7 < mod->Targets.targets.num );
  }
}


// ========================================================================
// ?HandleMoverModifier@idMoverMM@@MAAXABUsplineMoverModifier_t@@AAVidPhysics_ParametricMM@@W4moverModifierFunction_t@@MMM_N@Z
// EA  : 0x82C8B940
// RVA : 0x00C8B940
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::HandleMoverModifier(
        idMoverMM *this,
        const splineMoverModifier_t *mod,
        idPhysics_ParametricMM *physObj,
        moverModifierFunction_t ignoreFlags,
        double mark,
        double distTrav,
        double splineL,
        bool editorTest,
        int a9,
        int a10,
        char a11)
{
  idRenderWorld *v19; // r23
  idRenderWorld_vtbl *v20; // r28
  const idBounds *v21; // r3

  if ( g_debugMoverModifiers.valueInteger != 0 )
  {
    idLib::Printf(fmt: "===================================================\n");
    idLib::Printf(
      fmt: "Mover %s HIT modifier[%d]. %f >= %f \n",
      this->name.data,
      this->splineModifierIndex,
      distTrav,
      mark);
    v19 = gameLocal->GetRenderWorld(this: gameLocal);
    v20 = v19->__vftable;
    v21 = physObj->GetAbsBounds(this: physObj, a2: -1);
    v20->DebugBounds(this: v19, a2: (const idVec4 *)&idColor::colorRed, a3: v21, a4: &vec3_origin, a5: 10000, a6: false);
  }
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_BLENDTOANIMSPEED) != 0
    && (ignoreFlags & 0x4000) == 0 )
  {
    this->HandleNextMoverModifier_BlendToAnimSpeed(this, a2: physObj, a3: distTrav, a4: splineL);
  }
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_SPEED) != 0 && (ignoreFlags & 2) == 0 )
    this->HandleNextMoverModifier_Speed(this, a2: physObj, a3: distTrav, a4: splineL);
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_ORIENTATION) != 0
    && (ignoreFlags & 4) == 0 )
  {
    this->HandleNextMoverModifier_Orientation(this, a2: physObj, a3: distTrav, a4: splineL);
  }
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_OFFSET) != 0 && (ignoreFlags & 8) == 0 )
    this->HandleNextMoverModifier_Offset(this, a2: physObj, a3: distTrav, a4: splineL);
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_SCRIPT) != 0
    && a11 == 0
    && (ignoreFlags & 0x10) == 0 )
  {
    this->HandleMoverModifier_Script(this, a2: mod, a3: physObj, a4: distTrav, a5: splineL);
  }
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_SOUND) != 0
    && a11 == 0
    && (ignoreFlags & 0x400) == 0 )
  {
    this->HandleMoverModifier_Sound(this, a2: mod, a3: physObj, a4: distTrav, a5: splineL);
  }
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_SPLINE) != 0 && (ignoreFlags & 0x40) == 0 )
    this->HandleMoverModifier_Spline(this, a2: mod, a3: physObj, a4: distTrav, a5: splineL);
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_PAUSE) != 0 && (ignoreFlags & 0x20) == 0 )
    this->HandleMoverModifier_Pause(this, a2: mod, a3: physObj, a4: distTrav, a5: splineL);
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_TARGET) != 0 && (ignoreFlags & 0x80) == 0 )
    this->HandleMoverModifier_Target(this, a2: mod, a3: physObj, a4: distTrav, a5: splineL);
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_OSCILLATION) != 0
    && (ignoreFlags & 0x200) == 0 )
  {
    this->HandleMoverModifier_Oscillation(this, a2: mod, a3: physObj, a4: distTrav, a5: splineL);
  }
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_REVERSE) != 0
    && (ignoreFlags & 0x100) == 0 )
  {
    this->HandleMoverModifier_Reverse(this, a2: mod, a3: physObj, a4: distTrav, a5: splineL);
  }
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_SPAWN) != 0
    && a11 == 0
    && (ignoreFlags & 0x800) == 0 )
  {
    this->HandleMoverModifier_SpawnEntity(this, a2: mod, a3: physObj, a4: distTrav, a5: splineL);
  }
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_ANIM) != 0 && (ignoreFlags & 0x1000) == 0 )
    this->HandleMoverModifier_Anim(this, a2: mod, a3: physObj, a4: distTrav, a5: splineL);
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_VEHICLE) != 0
    && (ignoreFlags & 0x2000) == 0 )
  {
    this->HandleMoverModifier_Vehicle(this, a2: mod, a3: physObj, a4: distTrav, a5: splineL);
  }
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_AI) != 0 && (ignoreFlags & 0x10000) == 0 )
    this->HandleMoverModifier_Ai(this, a2: mod, a3: physObj, a4: distTrav, a5: splineL);
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_RAILEVENT) != 0
    && (ignoreFlags & 0x20000) == 0 )
  {
    this->HandleMoverModifier_RailEvent(this, a2: mod, a3: physObj, a4: distTrav, a5: splineL);
  }
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_MELEEEVENT) != 0
    && (ignoreFlags & 0x40000) == 0 )
  {
    this->HandleMoverModifier_MeleeEvent(this, a2: mod, a3: physObj, a4: distTrav, a5: splineL);
  }
  if ( (unsigned __int8)idMoverMM::ModifierIsType(this, mod, t: MOVERMODIFIER_SWARMEVENT) != 0
    && (ignoreFlags & 0x80000) == 0 )
  {
    this->HandleMoverModifier_SwarmEvent(this, a2: mod, a3: physObj, a4: distTrav, a5: splineL);
  }
  physObj->Activate(this: physObj);
  if ( g_debugMoverModifiers.valueInteger != 0 )
    idLib::Printf(fmt: "===================================================\n");
}


// ========================================================================
// ?Event_GetNextSplineChild@idSplinePathMM@@QAA?AVeventEntity@@M@Z
// EA  : 0x82C8BFD8
// RVA : 0x00C8BFD8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idSplinePathMM *__fastcall idSplinePathMM::Event_GetNextSplineChild(
        idSplinePathMM *this,
        eventEntity *result,
        double splineLength)
{
  int v6; // r29
  int v7; // r30
  int v8; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3
  int v12; // r9
  idEntity *v13; // r3
  idEntity *v14; // r3

  v6 = 0;
  if ( (int)result[248].value <= 0 )
  {
LABEL_9:
    eventEntity::eventEntity((eventEntity *)this);
    return this;
  }
  else
  {
    v7 = 0;
    while ( 1 )
    {
      v8 = *(int *)((char *)&result[247].value->__vftable + v7);
      if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13 && (v9 = gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
        v10 = idEntity::CastTo(c: v9);
      else
        v10 = nullptr;
      if ( v10->GetSplineLocation(this: v10)->lengthOnSpline > splineLength )
        break;
      ++v6;
      v7 += 4;
      if ( v6 >= (int)result[248].value )
        goto LABEL_9;
    }
    v12 = *((_DWORD *)&result[247].value->__vftable + v6);
    if ( gameLocal->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13
      && (v13 = gameLocal->entities.ptr[(int)*(&result[247].value->__vftable + v6) & 0x1FFF]) != nullptr )
    {
      v14 = idEntity::CastTo(c: v13);
      eventEntity::eventEntity((eventEntity *)this, e: v14);
      return this;
    }
    else
    {
      eventEntity::eventEntity((eventEntity *)this, e: nullptr);
      return this;
    }
  }
}


// ========================================================================
// ?Event_GetClosestSplineChild@idSplinePathMM@@QAA?AVeventEntity@@M@Z
// EA  : 0x82C8C118
// RVA : 0x00C8C118
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idSplinePathMM *__fastcall idSplinePathMM::Event_GetClosestSplineChild(
        idSplinePathMM *this,
        eventEntity *result,
        double splineLength)
{
  idEntity *v6; // r29
  int v7; // r27
  double v8; // fp31
  int v9; // r31
  idGameLocal *v10; // r11
  int v11; // r9
  idEntity *v12; // r3
  idEntity *v13; // r3
  double v14; // fp0
  int v15; // r9
  idEntity *v16; // r3
  idEntity *v17; // r3

  v6 = nullptr;
  v7 = 0;
  v8 = 0.0;
  if ( (int)result[248].value > 0 )
  {
    v9 = 0;
    v10 = gameLocal;
    do
    {
      v11 = *(int *)((char *)&result[247].value->__vftable + v9);
      if ( v10->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13 && (v12 = v10->entities.ptr[v11 & 0x1FFF]) != nullptr )
        v13 = idEntity::CastTo(c: v12);
      else
        v13 = nullptr;
      v14 = __fabs((float)((float)splineLength - v13->GetSplineLocation(this: v13)->lengthOnSpline));
      if ( v6 != nullptr && v14 >= v8 )
      {
        v10 = gameLocal;
      }
      else
      {
        v8 = v14;
        v10 = gameLocal;
        v15 = *(int *)((char *)&result[247].value->__vftable + v9);
        if ( gameLocal->spawnIds.ptr[v15 & 0x1FFF] == v15 >> 13
          && (v16 = gameLocal->entities.ptr[v15 & 0x1FFF]) != nullptr )
        {
          v17 = idEntity::CastTo(c: v16);
          v10 = gameLocal;
          v6 = v17;
        }
        else
        {
          v6 = nullptr;
        }
      }
      ++v7;
      v9 += 4;
    }
    while ( v7 < (int)result[248].value );
  }
  eventEntity::eventEntity((eventEntity *)this, e: v6);
  return this;
}


// ========================================================================
// ?Think@idMoverAttachment@@UAAXXZ
// EA  : 0x82C8C268
// RVA : 0x00C8C268
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverAttachment::Think(idMoverAttachment *this)
{
  idMoverAttachment *BindMaster; // r3

  BindMaster = (idMoverAttachment *)idEntity::GetBindMaster(this);
  if ( BindMaster == nullptr
    || BindMaster == this
    || (unsigned __int8)idClass::IsType(this: BindMaster, superclass: &idMover::Type) == 0 )
  {
    idMoverAttachment::ManualThink(this);
  }
}


// ========================================================================
// ??0splineMoverModifier_t@@QAA@XZ
// EA  : 0x82C8E1A8
// RVA : 0x00C8E1A8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

splineMoverModifier_t *__fastcall splineMoverModifier_t::splineMoverModifier_t(splineMoverModifier_t *this)
{
  int v2; // ctr
  float *p_z; // r11
  float *p_y; // r10
  float *v5; // r6
  float *v6; // r9
  int v7; // ctr

  this->length = 0.0;
  this->modifierOrigin = vec3_origin;
  v2 = 9;
  p_z = &this->modifierOrigin.z;
  p_y = &mat2_identity.mat[1].y;
  do
  {
    *++p_z = *++p_y;
    --v2;
  }
  while ( v2 != 0 );
  this->Orientation.setNewOrientation = false;
  this->Orientation.useSplineAngles = false;
  this->Orientation.newOrientation = ang_zero;
  this->Speed.moveTime = 0.0;
  this->Speed.moveSpeed = 0.0;
  this->Speed.setNewMoveSpeed = false;
  this->Offset.setNewOffset = false;
  this->Offset.newOffset = vec3_origin;
  this->Offset.setNewOffsetScale = false;
  this->Offset.newOffsetScale = vec3_origin;
  splineMoverModifier_t::splineMoverModifierOscillation_t::splineMoverModifierOscillation_t(this: &this->Oscillation);
  this->Pause.pauseTime = 0.0;
  this->Script.scriptFunction.str = &byte_8200D768;
  this->Script.notifyData.str = &byte_8200D768;
  this->Spline.splinePath.spawnId.value = 0x1FFF;
  this->Spline.resetSpeed = false;
  this->Targets.targets.list = nullptr;
  this->Targets.targets.granularity = 0;
  this->Targets.targets.memTag = 5;
  this->Targets.targets.listStatic = 0;
  this->Targets.targets.size = 0;
  this->Targets.targets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->Targets);
  this->Reverse.reverse = false;
  splineMoverModifier_t::splineMoverModifierSound_t::splineMoverModifierSound_t(this: &this->Sound);
  splineMoverModifier_t::splineMoverModifierSpawnEntity::splineMoverModifierSpawnEntity(this: &this->SpawnEntity);
  this->SwarmEntity.range = 0.0;
  this->SwarmEntity.actorClass = ACTORCLASS_MUTANT;
  this->SwarmEntity.time = 0.25;
  this->SwarmEntity.goalRadius = 50.0;
  this->SwarmEntity.goalOffset = 100.0;
  this->Animation.animatedEntity.spawnId.value = 0x1FFF;
  this->Animation.animationToPlay.value = -1;
  this->Animation.webAnimation.data = this->Animation.webAnimation.baseBuffer;
  this->Animation.webAnimation.allocedAndFlag = 20;
  this->Animation.webAnimation.len = 0;
  this->Animation.webAnimation.baseBuffer[0] = 0;
  this->Animation.webViaAnimation.data = this->Animation.webViaAnimation.baseBuffer;
  this->Animation.webViaAnimation.allocedAndFlag = 20;
  this->Animation.webViaAnimation.len = 0;
  this->Animation.webViaAnimation.baseBuffer[0] = 0;
  this->Animation.declToPlayAnimOn = nullptr;
  v5 = &this->AiProperties.animationEndOrigin.z;
  v6 = &mat2_identity.mat[1].y;
  this->Animation.preAnimationScriptFunction.str = &byte_8200D768;
  this->Animation.postAnimationScriptFunction.str = &byte_8200D768;
  this->Animation.splinePath.spawnId.value = 0x1FFF;
  this->Animation.splineTransitionTime = 0.0;
  this->Animation.splineTransitionDelay = 0.0;
  this->VehicleProperties.vehicleEntity.spawnId.value = 0x1FFF;
  this->VehicleProperties.vehicleSteerAngle = 0.0;
  this->VehicleProperties.setVehicleProperties = false;
  this->VehicleProperties.vehicleAccelerate = false;
  v7 = 9;
  this->VehicleProperties.vehicleHandBraking = false;
  this->VehicleProperties.vehicleIsReversing = false;
  this->BlendToAnimSpeed.blendToAnimSpeed = false;
  this->AiProperties.animation.data = this->AiProperties.animation.baseBuffer;
  this->AiProperties.animation.allocedAndFlag = 20;
  this->AiProperties.animation.len = 0;
  this->AiProperties.animation.baseBuffer[0] = 0;
  this->AiProperties.speedScale = 1.0;
  *((_BYTE *)&this->AiProperties + 36) = *((_BYTE *)&this->AiProperties + 36) & 3 | 0x60;
  this->AiProperties.animationEndOrigin = vec3_origin;
  do
  {
    *++v5 = *++v6;
    --v7;
  }
  while ( v7 != 0 );
  this->RailEvent.healthPerSrike = 0.0;
  this->RailEvent.type = RAIL_EVENT_NONE;
  this->RailEvent.anim.allocedAndFlag = 20;
  this->RailEvent.anim.len = 0;
  this->RailEvent.anim.data = this->RailEvent.anim.baseBuffer;
  this->RailEvent.anim.baseBuffer[0] = 0;
  this->RailEvent.viaAnim.data = this->RailEvent.viaAnim.baseBuffer;
  this->RailEvent.viaAnim.allocedAndFlag = 20;
  this->RailEvent.viaAnim.len = 0;
  this->RailEvent.viaAnim.baseBuffer[0] = 0;
  this->RailEvent.windowIndex = 0;
  this->RailEvent.forcedAttackIndex = 0;
  this->MeleeEvent.meleeTarget.spawnId.value = 0x1FFF;
  this->MeleeEvent.meleeIndex = 0;
  this->MeleeEvent.animation.value = -1;
  this->MeleeEvent.splinePath.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// __unwind$517881
// EA  : 0x82C8E4F8
// RVA : 0x00C8E4F8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_517881()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 212));
}


// ========================================================================
// __unwind$517882
// EA  : 0x82C8E524
// RVA : 0x00C8E524
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_517882()
{
  int v0; // r12

  idSurface::~idSurface(this: (splineMoverModifier_t::splineMoverModifierSound_t *)(*(_DWORD *)(v0 - 176 + 196) + 232));
}


// ========================================================================
// ??0idMoverModifier@@QAA@XZ
// EA  : 0x82C8E558
// RVA : 0x00C8E558
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMoverModifier *__fastcall idMoverModifier::idMoverModifier(idMoverModifier *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idMoverModifier_vtbl *)&idMoverModifier::`vftable';
  this->splinePath.spawnId.value = 0x1FFF;
  splineMoverModifier_t::splineMoverModifier_t(this: &this->modifier);
  this->splineForwardDir = vec3_origin;
  this->dirty = false;
  this->controlPointLength = -1.0;
  this->initialized = true;
  this->controlPointOrigin = vec3_origin;
  this->controlPointIndex = 0;
  this->controlPointPCT = 0.0;
  this->controlPointOrigin = vec3_origin;
  this->controlPointOriginNext = vec3_origin;
  return this;
}


// ========================================================================
// __unwind$518752
// EA  : 0x82C8E66C
// RVA : 0x00C8E66C
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_518752()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?DrawDebugMoverModifiers@idMoverMM@@AAAXXZ
// EA  : 0x82C8E758
// RVA : 0x00C8E758
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::DrawDebugMoverModifiers(idMoverMM *this)
{
  idPhysics_ParametricMM *p_physicsObj; // r29
  const idList<splineMoverModifier_t,5> *splineMoverModifiers; // r11
  int v4; // r30
  int v5; // r31
  double length; // fp29
  idCurve_Spline<idVec3> *Spline; // r3
  double TimeForLength; // fp29
  idCurve_Spline<idVec3> *v9; // r3
  idCurve_Spline<idVec3> *v10; // r3
  idRenderWorld *v11; // r24
  idRenderWorld_vtbl *v12; // r28
  idMat3 *v13; // r3
  float v14[4]; // [sp+50h] [-C0h] BYREF
  float v15[4]; // [sp+60h] [-B0h] BYREF
  idMat3 v16; // [sp+70h] [-A0h] BYREF

  if ( g_showMoverMods.valueInteger != 0 )
  {
    p_physicsObj = &this->physicsObj;
    if ( idPhysics_ParametricMM::GetSpline(this: &this->physicsObj) != nullptr )
    {
      splineMoverModifiers = this->splineMoverModifiers;
      if ( splineMoverModifiers != nullptr )
      {
        v4 = 0;
        if ( splineMoverModifiers->num > 0 )
        {
          v5 = 0;
          do
          {
            length = splineMoverModifiers->list[v5].length;
            Spline = idPhysics_ParametricMM::GetSpline(this: p_physicsObj);
            TimeForLength = idCurve<idVec3>::GetTimeForLength(this: Spline, length, epsilon: 0.1);
            v9 = idPhysics_ParametricMM::GetSpline(this: p_physicsObj);
            v9->GetCurrentValue(this: (struct idCurve_Spline<idVec3> *)v14, result: (idVec3 *)v9, a3: TimeForLength);
            v10 = idPhysics_ParametricMM::GetSpline(this: p_physicsObj);
            v10->GetCurrentFirstDerivative(
              this: (struct idCurve_Spline<idVec3> *)&v16,
              result: (idVec3 *)v10,
              a3: TimeForLength);
            v11 = gameLocal->GetRenderWorld(this: gameLocal);
            v15[0] = v14[0];
            v15[1] = v14[1];
            v15[2] = v14[2] + (float)4.0;
            v12 = v11->__vftable;
            v13 = idVec3::ToMat3(this: (idVec3 *)&v16.mat[1].y, result: &v16);
            v12->DebugAxis(
              this: v11,
              a2: (const idVec4 *)&idColor::colorMagenta,
              a3: (const idVec3 *)v15,
              a4: v13,
              a5: 1,
              a6: false);
            splineMoverModifiers = this->splineMoverModifiers;
            ++v4;
            ++v5;
          }
          while ( v4 < splineMoverModifiers->num );
        }
      }
    }
  }
}


// ========================================================================
// ?Think@idMoverMM@@UAAXXZ
// EA  : 0x82C8E8E0
// RVA : 0x00C8E8E0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::Think(idMoverMM *this)
{
  idPhysics *Physics; // r3
  float *v3; // r3
  double v4; // fp7
  double v5; // fp6
  bool v6; // r6
  int v7; // r5
  int v8; // r4
  char flags; // r9
  int v10; // r5
  int v11; // r4
  int v12; // r7
  int v13; // r6
  float v14; // [sp+50h] [-30h]
  float v15; // [sp+54h] [-2Ch]
  float v16; // [sp+58h] [-28h]
  idVec3 v17; // [sp+60h] [-20h] BYREF

  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) != 0 )
  {
    idEntity::BecomeInactive(this, flags: 7);
  }
  else
  {
    idMoverMM::UpdateMoverAttachments(this);
    if ( this->applyAnimationOffsetOnNextFrame )
    {
      Physics = idEntity::GetPhysics(this);
      v3 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v14 = *v3;
      v15 = v3[1];
      v16 = v3[2];
      this->SetAxis(this, a2: &this->animationOffsetAxis);
      v4 = (float)(this->animationOffsetTranslation.y + v15);
      v5 = (float)(this->animationOffsetTranslation.z + v16);
      v17.x = this->animationOffsetTranslation.x + v14;
      v17.y = v4;
      v17.z = v5;
      idEntity::SetOrigin(this, org: &v17);
      idMoverMM::StopSpline(this, a2: v8, a3: v7, a4: v6);
      flags = (char)this->flags;
      this->applyAnimationOffsetOnNextFrame = false;
      *(_BYTE *)&this->flags = flags | 0x20;
      idAnimatedEntity::Think(this);
      v12 = (int)this->flags;
      v13 = v12 & 0xDF;
      *(_BYTE *)&this->flags = v13;
    }
    else
    {
      idAnimatedEntity::Think(this);
    }
    idMoverMM::UpdateSound(this, a2: v11, a3: v10, a4: v13, a5: v12);
    idMoverMM::DrawDebugAxis(this);
    idMoverMM::DrawDebugMoverModifiers(this);
  }
}


// ========================================================================
// ?HandleNextMoverModifier_Orientation@idMoverMM@@MAAXAAVidPhysics_ParametricMM@@MM@Z
// EA  : 0x82C8EA28
// RVA : 0x00C8EA28
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::HandleNextMoverModifier_Orientation(
        idMoverMM *this,
        idPhysics_ParametricMM *physObj,
        double currentSplinePosition,
        double splineTotalLength)
{
  const splineMoverModifier_t *NextModifier; // r3
  idQuat *p_newOrientation; // r4
  idCurve_Spline<idVec3> *spline; // r3
  idCurve_Spline<idVec3>_vtbl *v10; // r29
  double TimeForLength; // fp1
  idMat3 *v12; // r3
  idQuat *v13; // r3
  idCurve_Spline<idVec3> *v14; // r3
  double v15; // fp30
  idCurve_Spline<idVec3>_vtbl *v16; // r29
  double v17; // fp1
  idMat3 *v18; // r3
  idQuat *v19; // r3
  double v20; // fp31
  double v21; // fp29
  double v22; // fp27
  double v23; // fp28
  idQuat *v24; // r3
  idQuat *v25; // r3
  double x; // fp7
  double y; // fp4
  double z; // fp2
  double v29; // fp9
  double v30; // fp5
  double v31; // fp1
  double v32; // fp8
  double v33; // fp6
  double v34; // fp24
  __int64 v35; // r10
  int v36; // r7
  int v37; // r6
  const idQuat *v38; // r29
  idQuat *v39; // r3
  idMat3 *v40; // r3
  double v41; // fp31
  __int64 v42; // r10
  int v43; // r7
  int v44; // r6
  float v45[4]; // [sp+50h] [-110h] BYREF
  idMat3 v46; // [sp+60h] [-100h] BYREF
  float v47; // [sp+84h] [-DCh]
  float v48; // [sp+88h] [-D8h]
  float v49; // [sp+8Ch] [-D4h]
  idQuat v50; // [sp+90h] [-D0h] BYREF
  idAngles v51; // [sp+A0h] [-C0h] BYREF
  float v52; // [sp+ACh] [-B4h]
  idMat3 v53[4]; // [sp+B0h] [-B0h] BYREF

  NextModifier = idMoverMM::GetNextModifier(this, t: MOVERMODIFIER_ORIENTATION, splinePos: v45);
  if ( NextModifier != nullptr )
  {
    p_newOrientation = (idQuat *)&NextModifier->Orientation.newOrientation;
    if ( NextModifier->Orientation.useSplineAngles )
    {
      idAngles::ToQuat(this: &v51, result: p_newOrientation);
      spline = this->spline;
      v10 = spline->__vftable;
      TimeForLength = idCurve<idVec3>::GetTimeForLength(this: spline, length: currentSplinePosition, epsilon: 0.1);
      v12 = (idMat3 *)v10->GetCurrentFirstDerivative(
                        this: (struct idCurve_Spline<idVec3> *)v53,
                        result: (idVec3 *)this->spline,
                        a3: TimeForLength);
      v13 = (idQuat *)idVec3::ToMat3(this: (idVec3 *)&v53[0].mat[2].z, result: v12);
      idMat3::ToQuat(this: (idMat3 *)&v46.mat[2].z, result: v13);
      v14 = this->spline;
      v15 = v45[0];
      v16 = v14->__vftable;
      v17 = idCurve<idVec3>::GetTimeForLength(this: v14, length: v45[0], epsilon: 0.1);
      v18 = (idMat3 *)v16->GetCurrentFirstDerivative(
                        this: (struct idCurve_Spline<idVec3> *)v53,
                        result: (idVec3 *)this->spline,
                        a3: v17);
      v19 = (idQuat *)idVec3::ToMat3(this: (idVec3 *)&v53[0].mat[2].z, result: v18);
      idMat3::ToQuat(this: &v46, result: v19);
      v20 = -v46.mat[2].z;
      v21 = -v47;
      v22 = -v48;
      v23 = v49;
      v24 = (idQuat *)physObj->GetAxis(this: physObj, a2: 0);
      v25 = idMat3::ToQuat(this: v53, result: v24);
      x = v25->x;
      y = v25->y;
      z = v25->z;
      v29 = -v46.mat[0].x;
      v30 = (float)((float)(v25->y * (float)v20) + (float)((float)(v25->z * (float)v23) + (float)(v25->w * (float)v22)));
      v31 = (float)((float)(v25->w * (float)v21) + (float)((float)(v25->y * (float)v23) + (float)(v25->x * (float)v22)));
      v32 = (float)((float)(v25->w * (float)v20) + (float)((float)(v25->z * (float)v21) + (float)(v25->x * (float)v23)));
      v33 = -v46.mat[0].y;
      v34 = -v46.mat[0].z;
      v46.mat[2].y = -(float)((float)(v25->z * (float)v22)
                            - (float)-(float)((float)(v25->y * (float)v21)
                                            - (float)((float)(v25->w * (float)v23) - (float)(v25->x * (float)v20))));
      v46.mat[1].z = -(float)((float)((float)z * (float)v20) - (float)v31);
      v46.mat[1].y = -(float)((float)((float)y * (float)v22) - (float)v32);
      v46.mat[2].x = -(float)((float)((float)x * (float)v21) - (float)v30);
      v50.x = -(float)((float)(v51.yaw * (float)v34)
                     - (float)((float)(v46.mat[1].x * v51.pitch)
                             + (float)((float)(v51.roll * (float)v33) + (float)(v52 * (float)v29))));
      v50.y = -(float)((float)(v51.roll * (float)v29)
                     - (float)((float)((float)v34 * v51.pitch)
                             + (float)((float)(v52 * (float)v33) + (float)(v51.yaw * v46.mat[1].x))));
      v50.w = -(float)((float)(v51.roll * (float)v34)
                     - (float)-(float)((float)(v51.yaw * (float)v33)
                                     - (float)((float)(v52 * v46.mat[1].x) - (float)(v51.pitch * (float)v29))));
      v50.z = -(float)((float)((float)v33 * v51.pitch)
                     - (float)((float)(v51.yaw * (float)v29)
                             + (float)((float)(v52 * (float)v34) + (float)(v51.roll * v46.mat[1].x))));
      idPhysics_ParametricMM::SetSplineAngularInterpolation(
        this: physObj,
        startQuat: (idMat3 *)&v46.mat[1].y,
        endQuat: &v50,
        endPos: v15,
        a5: v37,
        a6: v36,
        a7: v35);
      idPhysics_ParametricMM::SetUseSplineAngles(this: physObj, newUseSplineAngles: true);
      this->useSplineAngles = true;
      if ( g_debugMoverModifiers.valueInteger != 0 )
        idLib::Printf(fmt: "   Lerp Distance: %f. Using Spline Angles \n", v15);
    }
    else
    {
      v38 = idAngles::ToQuat(this: (idAngles *)v53, result: p_newOrientation);
      v39 = (idQuat *)physObj->GetAxis(this: physObj, a2: 0);
      v40 = (idMat3 *)idMat3::ToQuat(this: (idMat3 *)&v53[0].mat[1].y, result: v39);
      v41 = v45[0];
      idPhysics_ParametricMM::SetSplineAngularInterpolation(
        this: physObj,
        startQuat: v40,
        endQuat: v38,
        endPos: v45[0],
        a5: v44,
        a6: v43,
        a7: v42);
      idPhysics_ParametricMM::SetUseSplineAngles(this: physObj, newUseSplineAngles: false);
      this->useSplineAngles = false;
      if ( g_debugMoverModifiers.valueInteger != 0 )
        idLib::Printf(fmt: (const char *)HIDWORD(v41), LODWORD(v41), v41);
    }
  }
}


// ========================================================================
// ??$AllocSplineInternal@VidAngles@@@idSplinePath@@IBAPAV?$idCurve_Spline@VidAngles@@@@ABV?$idList@VidAngles@@$04@@@Z
// EA  : 0x82C8ED20
// RVA : 0x00C8ED20
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idCurve_Spline<idAngles> *__fastcall idSplinePath::AllocSplineInternal<idAngles>(
        idSplinePath *this,
        const idList<idAngles,5> *ctrlPoints)
{
  splinePathType_t type; // r11
  idCurve_CatmullRomSpline<idAngles> *v4; // r3
  idCurve_CatmullRomSpline<idAngles> *v5; // r3
  void *v6; // r30
  idCurve_KochanekBartelsSpline<idAngles> *v7; // r3
  idCurve_KochanekBartelsSpline<idAngles> *v8; // r3
  idCurve_NonUniformBSpline<idAngles> *v9; // r3
  idCurve_NonUniformBSpline<idAngles> *v10; // r3
  idCurve_NURBS<idAngles> *v11; // r3
  idCurve_NURBS<idAngles> *v12; // r3
  idCurve_CubicBezierSpline<idAngles> *v13; // r3
  idCurve_CubicBezierSpline<idAngles> *v14; // r3
  int v15; // r29
  int v16; // r28
  int v17; // r27
  __int64 v18; // r10

  type = this->type;
  if ( (unsigned int)type > NURBS )
    return nullptr;
  switch ( type )
  {
    case KochanekBartelsSpline:
      v7 = (idCurve_KochanekBartelsSpline<idAngles> *)idMem::AllocWithLocation(
                                                        this: &mem,
                                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                        size: 0x64u,
                                                        tag: TAG_SPLINE,
                                                        zeroBuffer: false,
                                                        align: ALIGN_16,
                                                        heap: HEAP_DEFAULTHEAP);
      if ( v7 != nullptr )
        v8 = idCurve_KochanekBartelsSpline<idAngles>::idCurve_KochanekBartelsSpline<idAngles>(this: v7);
      else
        v8 = nullptr;
      v6 = v8;
      break;
    case NonUniformBSpline:
      v9 = (idCurve_NonUniformBSpline<idAngles> *)idMem::AllocWithLocation(
                                                    this: &mem,
                                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                    size: 0x38u,
                                                    tag: TAG_SPLINE,
                                                    zeroBuffer: false,
                                                    align: ALIGN_16,
                                                    heap: HEAP_DEFAULTHEAP);
      if ( v9 != nullptr )
        v10 = idCurve_NonUniformBSpline<idAngles>::idCurve_NonUniformBSpline<idAngles>(this: v9);
      else
        v10 = nullptr;
      v6 = v10;
      break;
    case CubicBezierSpline:
      v13 = (idCurve_CubicBezierSpline<idAngles> *)idMem::AllocWithLocation(
                                                     this: &mem,
                                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                     size: 0x38u,
                                                     tag: TAG_SPLINE,
                                                     zeroBuffer: false,
                                                     align: ALIGN_16,
                                                     heap: HEAP_DEFAULTHEAP);
      if ( v13 != nullptr )
        v14 = idCurve_CubicBezierSpline<idAngles>::idCurve_CubicBezierSpline<idAngles>(this: v13);
      else
        v14 = nullptr;
      v6 = v14;
      break;
    default:
      if ( type != CatmullRomSpline )
      {
        v11 = (idCurve_NURBS<idAngles> *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                           size: 0x48u,
                                           tag: TAG_SPLINE,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
        if ( v11 != nullptr )
          v12 = idCurve_NURBS<idAngles>::idCurve_NURBS<idAngles>(this: v11);
        else
          v12 = nullptr;
        v6 = v12;
      }
      else
      {
        v4 = (idCurve_CatmullRomSpline<idAngles> *)idMem::AllocWithLocation(
                                                     this: &mem,
                                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                     size: 0x34u,
                                                     tag: TAG_SPLINE,
                                                     zeroBuffer: false,
                                                     align: ALIGN_16,
                                                     heap: HEAP_DEFAULTHEAP);
        if ( v4 != nullptr )
          v5 = idCurve_CatmullRomSpline<idAngles>::idCurve_CatmullRomSpline<idAngles>(this: v4);
        else
          v5 = nullptr;
        v6 = v5;
      }
      break;
  }
  (*(void (__fastcall **)(void *, _DWORD))(*(_DWORD *)v6 + 48))(a1: v6, a2: 0);
  v15 = 0;
  v16 = 0;
  if ( ctrlPoints->num > 0 )
  {
    v17 = 0;
    do
    {
      LODWORD(v18) = v16;
      HIDWORD(v18) = *(_DWORD *)v6;
      (*(void (__fastcall **)(void *, double))(*(_DWORD *)v6 + 4))(a1: v6, a2: (float)v18);
      ++v15;
      v17 += 12;
      v16 += 100;
    }
    while ( v15 < ctrlPoints->num );
  }
  return (idCurve_Spline<idAngles> *)v6;
}


// ========================================================================
// __unwind$519104
// EA  : 0x82C8EF48
// RVA : 0x00C8EF48
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_519104()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SPLINE);
}


// ========================================================================
// __unwind$519105
// EA  : 0x82C8EF74
// RVA : 0x00C8EF74
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_519105()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SPLINE);
}


// ========================================================================
// __unwind$519106
// EA  : 0x82C8EFA0
// RVA : 0x00C8EFA0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_519106()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SPLINE);
}


// ========================================================================
// __unwind$519107
// EA  : 0x82C8EFCC
// RVA : 0x00C8EFCC
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_519107()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SPLINE);
}


// ========================================================================
// __unwind$519108
// EA  : 0x82C8EFF8
// RVA : 0x00C8EFF8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_519108()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SPLINE);
}


// ========================================================================
// ?MakeRotationContinuous@idSplinePathWithOrientation@@SAXAAV?$idList@VidAngles@@$04@@0@Z
// EA  : 0x82C90DB0
// RVA : 0x00C90DB0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idSplinePathWithOrientation::MakeRotationContinuous(idList<idAngles,5> *src, idList<idVec3,5> *dst)
{
  int num; // r31
  int size; // r11
  idAngles *list; // r11
  idAngles *v7; // r10
  long double v8; // fp2
  int v9; // r27
  int v10; // r29
  int v11; // r31
  idAngles *v12; // r11
  float yaw; // r8
  float pitch; // r7
  float v15; // r6
  float roll; // r5
  float v17; // r4
  double v18; // fp29
  float *v19; // r30
  double v20; // fp31
  double v21; // fp0
  double v22; // fp13
  idAngles *v23; // r11
  double v24; // fp12
  float v25; // [sp+50h] [-90h] BYREF
  float v26; // [sp+54h] [-8Ch]
  float v27; // [sp+58h] [-88h]
  _DWORD v28[18]; // [sp+60h] [-80h] BYREF

  num = src->num;
  if ( num <= dst->size || (unsigned __int8)idList<idVec3,59>::Resize(this: dst, newsize: src->num) != 0 )
  {
    size = dst->size;
    if ( num < size )
      size = num;
    dst->num = size;
  }
  if ( src->num > 0 )
  {
    list = src->list;
    v7 = (idAngles *)dst->list;
    v7->pitch = src->list->pitch;
    v7->yaw = list->yaw;
    v7->roll = list->roll;
    idAngles::Normalize180(this: (idAngles *)dst->list);
    v9 = 1;
    if ( src->num > 1 )
    {
      v10 = 1;
      do
      {
        v11 = 0;
        v12 = &src->list[v10];
        yaw = v12->yaw;
        pitch = v12[-1].pitch;
        v15 = v12[-1].yaw;
        roll = v12[-1].roll;
        v17 = v12->roll;
        v25 = v12->pitch;
        v26 = yaw;
        *(float *)v28 = pitch;
        *(float *)&v28[1] = v15;
        *(float *)&v28[2] = roll;
        v27 = v17;
        do
        {
          v18 = *(float *)&v28[v11];
          v19 = (float *)((char *)&v25 + v11 * 4);
          v20 = (float)(*(float *)((char *)&v25 + v11 * 4) - *(float *)&v28[v11]);
          if ( v20 >= 360.0 || v20 < 0.0 )
          {
            *(double *)&v8 = (float)((float)(*(float *)((char *)&v25 + v11 * 4) - *(float *)&v28[v11])
                                   * (float)0.0027777778);
            v8 = floor(x: v8);
            v20 = (float)-(float)((float)((float)*(double *)&v8 * (float)360.0) - (float)v20);
          }
          v21 = v20;
          if ( v20 > 180.0 )
            v21 = (float)((float)v20 - (float)360.0);
          ++v11;
          *v19 = (float)v18 + (float)v21;
        }
        while ( v11 < 3 );
        v22 = v27;
        ++v9;
        v23 = (idAngles *)&dst->list[v10];
        v24 = v25;
        ++v10;
        v23->yaw = v26;
        v23->roll = v22;
        v23->pitch = v24;
      }
      while ( v9 < src->num );
    }
  }
}


// ========================================================================
// ?AllocSpline@idSplinePathMM@@QBAPAV?$idCurve_Spline@VidVec3@@@@XZ
// EA  : 0x82C90F58
// RVA : 0x00C90F58
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idCurve_Spline<idVec3> *__fastcall idSplinePathMM::AllocSpline(idSplinePathMM *this)
{
  splinePathType_t type; // r11
  idCurve_CatmullRomSpline<idVec3> *v3; // r3
  idCurve_CatmullRomSpline<idVec3> *v4; // r3
  void *v5; // r30
  idCurve_KochanekBartelsSpline<idVec3> *v6; // r3
  idCurve_KochanekBartelsSpline<idVec3> *v7; // r3
  idCurve_NonUniformBSpline<idVec3> *v8; // r3
  idCurve_NonUniformBSpline<idVec3> *v9; // r3
  idCurve_NURBS<idVec3> *v10; // r3
  idCurve_NURBS<idVec3> *v11; // r3
  idCurve_CubicBezierSpline<idVec3> *v12; // r3
  idCurve_CubicBezierSpline<idVec3> *v13; // r3
  int v14; // r29
  int v15; // r28
  int v16; // r27
  __int64 v17; // r10

  type = this->type;
  if ( (unsigned int)type > NURBS )
    return nullptr;
  switch ( type )
  {
    case KochanekBartelsSpline:
      v6 = (idCurve_KochanekBartelsSpline<idVec3> *)idMem::AllocWithLocation(
                                                      this: &mem,
                                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                      size: 0x64u,
                                                      tag: TAG_NEW,
                                                      zeroBuffer: false,
                                                      align: ALIGN_16,
                                                      heap: HEAP_DEFAULTHEAP);
      if ( v6 != nullptr )
        v7 = idCurve_KochanekBartelsSpline<idVec3>::idCurve_KochanekBartelsSpline<idVec3>(this: v6);
      else
        v7 = nullptr;
      v5 = v7;
      break;
    case NonUniformBSpline:
      v8 = (idCurve_NonUniformBSpline<idVec3> *)idMem::AllocWithLocation(
                                                  this: &mem,
                                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                  size: 0x38u,
                                                  tag: TAG_NEW,
                                                  zeroBuffer: false,
                                                  align: ALIGN_16,
                                                  heap: HEAP_DEFAULTHEAP);
      if ( v8 != nullptr )
        v9 = idCurve_NonUniformBSpline<idVec3>::idCurve_NonUniformBSpline<idVec3>(this: v8);
      else
        v9 = nullptr;
      v5 = v9;
      break;
    case CubicBezierSpline:
      v12 = (idCurve_CubicBezierSpline<idVec3> *)idMem::AllocWithLocation(
                                                   this: &mem,
                                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                   size: 0x38u,
                                                   tag: TAG_NEW,
                                                   zeroBuffer: false,
                                                   align: ALIGN_16,
                                                   heap: HEAP_DEFAULTHEAP);
      if ( v12 != nullptr )
        v13 = idCurve_CubicBezierSpline<idVec3>::idCurve_CubicBezierSpline<idVec3>(this: v12);
      else
        v13 = nullptr;
      v5 = v13;
      break;
    default:
      if ( type != CatmullRomSpline )
      {
        v10 = (idCurve_NURBS<idVec3> *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                         size: 0x48u,
                                         tag: TAG_NEW,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
        if ( v10 != nullptr )
          v11 = idCurve_NURBS<idVec3>::idCurve_NURBS<idVec3>(this: v10);
        else
          v11 = nullptr;
        v5 = v11;
      }
      else
      {
        v3 = (idCurve_CatmullRomSpline<idVec3> *)idMem::AllocWithLocation(
                                                   this: &mem,
                                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                   size: 0x34u,
                                                   tag: TAG_NEW,
                                                   zeroBuffer: false,
                                                   align: ALIGN_16,
                                                   heap: HEAP_DEFAULTHEAP);
        if ( v3 != nullptr )
          v4 = idCurve_CatmullRomSpline<idVec3>::idCurve_CatmullRomSpline<idVec3>(this: v3);
        else
          v4 = nullptr;
        v5 = v4;
      }
      break;
  }
  (*(void (__fastcall **)(void *, _DWORD))(*(_DWORD *)v5 + 48))(a1: v5, a2: 0);
  v14 = 0;
  v15 = 0;
  if ( this->controlPoints.num > 0 )
  {
    v16 = 0;
    do
    {
      LODWORD(v17) = v15;
      HIDWORD(v17) = *(_DWORD *)v5;
      (*(void (__fastcall **)(void *, double))(*(_DWORD *)v5 + 4))(a1: v5, a2: (float)v17);
      ++v14;
      v16 += 12;
      v15 += 100;
    }
    while ( v14 < this->controlPoints.num );
  }
  return (idCurve_Spline<idVec3> *)v5;
}


// ========================================================================
// __unwind$523222
// EA  : 0x82C91180
// RVA : 0x00C91180
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall _unwind_523222(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$523223
// EA  : 0x82C911A8
// RVA : 0x00C911A8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall _unwind_523223(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$523224
// EA  : 0x82C911D0
// RVA : 0x00C911D0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall _unwind_523224(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$523225
// EA  : 0x82C911F8
// RVA : 0x00C911F8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall _unwind_523225(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$523226
// EA  : 0x82C91220
// RVA : 0x00C91220
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall _unwind_523226(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?Event_GetDistanceAlongPath@idSplinePathMM@@QAA?AVeventFloat@@ABVidVec3@@MMM@Z
// EA  : 0x82C91248
// RVA : 0x00C91248
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idSplinePathMM *__fastcall idSplinePathMM::Event_GetDistanceAlongPath(
        idSplinePathMM *this,
        idSplinePathMM *result,
        const idVec3 *worldPos,
        double lastDistance,
        double searchWidth,
        double interval)
{
  double v12; // fp27
  double v13; // fp28
  double TimeForLength; // fp1
  float v20; // [sp+50h] [-70h] BYREF
  float v21; // [sp+54h] [-6Ch]
  float v22; // [sp+58h] [-68h]

  if ( result->allocedSpline == nullptr )
    result->allocedSpline = idSplinePathMM::AllocSpline(this: result);
  v12 = -1.0;
  v13 = -1.0;
  _FP10 = -(float)((float)lastDistance - (float)searchWidth);
  __asm { fsel      f31, f10, f0, f12 }
  _FP8 = (float)(result->cachedSplineLength - (float)((float)((float)searchWidth * (float)2.0) + (float)_FP31));
  __asm { fsel      f30, f8, f9, f11 }
  for ( ; _FP31 < _FP30; _FP31 = (float)((float)_FP31 + (float)interval) )
  {
    TimeForLength = idCurve<idVec3>::GetTimeForLength(this: result->allocedSpline, length: _FP31, epsilon: 0.1);
    ((void (__fastcall *)(float *, double))result->allocedSpline->GetCurrentValue)(a1: &v20, a2: TimeForLength);
    if ( v13 == -1.0
      || (float)((float)((float)(v22 - worldPos->z) * (float)(v22 - worldPos->z))
               + (float)((float)((float)(v20 - worldPos->x) * (float)(v20 - worldPos->x))
                       + (float)((float)(v21 - worldPos->y) * (float)(v21 - worldPos->y)))) < v12 )
    {
      v12 = (float)((float)((float)(v22 - worldPos->z) * (float)(v22 - worldPos->z))
                  + (float)((float)((float)(v20 - worldPos->x) * (float)(v20 - worldPos->x))
                          + (float)((float)(v21 - worldPos->y) * (float)(v21 - worldPos->y))));
      v13 = _FP31;
    }
  }
  eventFloat::eventFloat((eventFloat *)this, f: v13);
  return this;
}


// ========================================================================
// ?Event_GetPositionAlongPath@idSplinePathMM@@QAA?AVeventVector@@M@Z
// EA  : 0x82C91378
// RVA : 0x00C91378
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idSplinePathMM *__fastcall idSplinePathMM::Event_GetPositionAlongPath(
        idSplinePathMM *this,
        idSplinePathMM *result,
        double distance)
{
  double cachedSplineLength; // fp1
  double TimeForLength; // fp1
  const idVec3 *v8; // r3
  _BYTE v10[16]; // [sp+50h] [-30h] BYREF

  if ( result->allocedSpline == nullptr )
    result->allocedSpline = idSplinePathMM::AllocSpline(this: result);
  cachedSplineLength = result->cachedSplineLength;
  if ( distance >= 0.0 )
  {
    if ( distance <= cachedSplineLength )
      cachedSplineLength = distance;
  }
  else
  {
    cachedSplineLength = 0.0;
  }
  TimeForLength = idCurve<idVec3>::GetTimeForLength(
                    this: result->allocedSpline,
                    length: cachedSplineLength,
                    epsilon: 0.1);
  v8 = (const idVec3 *)((int (__fastcall *)(_BYTE *, double))result->allocedSpline->GetCurrentValue)(
                         a1: v10,
                         a2: TimeForLength);
  eventVector::eventVector((eventVector *)this, v: v8);
  return this;
}


// ========================================================================
// ?Event_GetDirectionAlongPath@idSplinePathMM@@QAA?AVeventVector@@M@Z
// EA  : 0x82C91430
// RVA : 0x00C91430
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idSplinePathMM *__fastcall idSplinePathMM::Event_GetDirectionAlongPath(
        idSplinePathMM *this,
        idSplinePathMM *result,
        double distance)
{
  double cachedSplineLength; // fp1
  double TimeForLength; // fp1
  const idVec3 *v8; // r3
  _BYTE v10[16]; // [sp+50h] [-30h] BYREF

  if ( result->allocedSpline == nullptr )
    result->allocedSpline = idSplinePathMM::AllocSpline(this: result);
  cachedSplineLength = result->cachedSplineLength;
  if ( distance >= 0.0 )
  {
    if ( distance <= cachedSplineLength )
      cachedSplineLength = distance;
  }
  else
  {
    cachedSplineLength = 0.0;
  }
  TimeForLength = idCurve<idVec3>::GetTimeForLength(
                    this: result->allocedSpline,
                    length: cachedSplineLength,
                    epsilon: 0.1);
  v8 = (const idVec3 *)((int (__fastcall *)(_BYTE *, double))result->allocedSpline->GetCurrentFirstDerivative)(
                         a1: v10,
                         a2: TimeForLength);
  eventVector::eventVector((eventVector *)this, v: v8);
  return this;
}


// ========================================================================
// ??$AllocSplineInternal@VidVec3@@@idSplinePath@@IBAPAV?$idCurve_Spline@VidVec3@@@@ABV?$idList@VidVec3@@$04@@@Z
// EA  : 0x82C91850
// RVA : 0x00C91850
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idCurve_Spline<idVec3> *__fastcall idSplinePath::AllocSplineInternal<idVec3>(
        idSplinePath *this,
        const idList<idVec3,5> *ctrlPoints)
{
  splinePathType_t type; // r11
  idCurve_CatmullRomSpline<idVec3> *v4; // r3
  idCurve_CatmullRomSpline<idVec3> *v5; // r3
  void *v6; // r30
  idCurve_KochanekBartelsSpline<idVec3> *v7; // r3
  idCurve_KochanekBartelsSpline<idVec3> *v8; // r3
  idCurve_NonUniformBSpline<idVec3> *v9; // r3
  idCurve_NonUniformBSpline<idVec3> *v10; // r3
  idCurve_NURBS<idVec3> *v11; // r3
  idCurve_NURBS<idVec3> *v12; // r3
  idCurve_CubicBezierSpline<idVec3> *v13; // r3
  idCurve_CubicBezierSpline<idVec3> *v14; // r3
  int v15; // r29
  int v16; // r28
  int v17; // r27
  __int64 v18; // r10

  type = this->type;
  if ( (unsigned int)type > NURBS )
    return nullptr;
  switch ( type )
  {
    case KochanekBartelsSpline:
      v7 = (idCurve_KochanekBartelsSpline<idVec3> *)idMem::AllocWithLocation(
                                                      this: &mem,
                                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                      size: 0x64u,
                                                      tag: TAG_SPLINE,
                                                      zeroBuffer: false,
                                                      align: ALIGN_16,
                                                      heap: HEAP_DEFAULTHEAP);
      if ( v7 != nullptr )
        v8 = idCurve_KochanekBartelsSpline<idVec3>::idCurve_KochanekBartelsSpline<idVec3>(this: v7);
      else
        v8 = nullptr;
      v6 = v8;
      break;
    case NonUniformBSpline:
      v9 = (idCurve_NonUniformBSpline<idVec3> *)idMem::AllocWithLocation(
                                                  this: &mem,
                                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                  size: 0x38u,
                                                  tag: TAG_SPLINE,
                                                  zeroBuffer: false,
                                                  align: ALIGN_16,
                                                  heap: HEAP_DEFAULTHEAP);
      if ( v9 != nullptr )
        v10 = idCurve_NonUniformBSpline<idVec3>::idCurve_NonUniformBSpline<idVec3>(this: v9);
      else
        v10 = nullptr;
      v6 = v10;
      break;
    case CubicBezierSpline:
      v13 = (idCurve_CubicBezierSpline<idVec3> *)idMem::AllocWithLocation(
                                                   this: &mem,
                                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                   size: 0x38u,
                                                   tag: TAG_SPLINE,
                                                   zeroBuffer: false,
                                                   align: ALIGN_16,
                                                   heap: HEAP_DEFAULTHEAP);
      if ( v13 != nullptr )
        v14 = idCurve_CubicBezierSpline<idVec3>::idCurve_CubicBezierSpline<idVec3>(this: v13);
      else
        v14 = nullptr;
      v6 = v14;
      break;
    default:
      if ( type != CatmullRomSpline )
      {
        v11 = (idCurve_NURBS<idVec3> *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                         size: 0x48u,
                                         tag: TAG_SPLINE,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
        if ( v11 != nullptr )
          v12 = idCurve_NURBS<idVec3>::idCurve_NURBS<idVec3>(this: v11);
        else
          v12 = nullptr;
        v6 = v12;
      }
      else
      {
        v4 = (idCurve_CatmullRomSpline<idVec3> *)idMem::AllocWithLocation(
                                                   this: &mem,
                                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                   size: 0x34u,
                                                   tag: TAG_SPLINE,
                                                   zeroBuffer: false,
                                                   align: ALIGN_16,
                                                   heap: HEAP_DEFAULTHEAP);
        if ( v4 != nullptr )
          v5 = idCurve_CatmullRomSpline<idVec3>::idCurve_CatmullRomSpline<idVec3>(this: v4);
        else
          v5 = nullptr;
        v6 = v5;
      }
      break;
  }
  (*(void (__fastcall **)(void *, _DWORD))(*(_DWORD *)v6 + 48))(a1: v6, a2: 0);
  v15 = 0;
  v16 = 0;
  if ( ctrlPoints->num > 0 )
  {
    v17 = 0;
    do
    {
      LODWORD(v18) = v16;
      HIDWORD(v18) = *(_DWORD *)v6;
      (*(void (__fastcall **)(void *, double))(*(_DWORD *)v6 + 4))(a1: v6, a2: (float)v18);
      ++v15;
      v17 += 12;
      v16 += 100;
    }
    while ( v15 < ctrlPoints->num );
  }
  return (idCurve_Spline<idVec3> *)v6;
}


// ========================================================================
// __unwind$523664
// EA  : 0x82C91A78
// RVA : 0x00C91A78
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_523664()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SPLINE);
}


// ========================================================================
// __unwind$523665
// EA  : 0x82C91AA4
// RVA : 0x00C91AA4
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_523665()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SPLINE);
}


// ========================================================================
// __unwind$523666
// EA  : 0x82C91AD0
// RVA : 0x00C91AD0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_523666()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SPLINE);
}


// ========================================================================
// __unwind$523667
// EA  : 0x82C91AFC
// RVA : 0x00C91AFC
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_523667()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SPLINE);
}


// ========================================================================
// __unwind$523668
// EA  : 0x82C91B28
// RVA : 0x00C91B28
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_523668()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SPLINE);
}


// ========================================================================
// ?AllocSpline@idSplinePath@@QBAPAV?$idCurve_Spline@VidVec3@@@@XZ
// EA  : 0x82C91B58
// RVA : 0x00C91B58
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idCurve_Spline<idVec3> *__fastcall idSplinePath::AllocSpline(idSplinePath *this)
{
  return idSplinePath::AllocSplineInternal<idVec3>(this, ctrlPoints: &this->controlPoints);
}


// ========================================================================
// ?Spawn@idSplinePathWithOrientation@@QAAXXZ
// EA  : 0x82C91B60
// RVA : 0x00C91B60
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idSplinePathWithOrientation::Spawn(idSplinePathWithOrientation *this)
{
  idSplinePathWithOrientation::MakeRotationContinuous(
    src: &this->controlPointRotations,
    dst: (idList<idVec3,5> *)&this->controlPointRotations);
}


// ========================================================================
// ?StartSpline@idMoverMM@@MAA_NPAVidEntity@@_NM@Z
// EA  : 0x82C91B70
// RVA : 0x00C91B70
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

int __fastcall idMoverMM::StartSpline(
        idMoverMM *this,
        idSplinePathMM *splineEntity,
        char startFromEnd,
        double startTime)
{
  int v8; // r11
  char v9; // r11
  bool v10; // zf
  idCurve_Spline<idVec3> *v11; // r3
  int move_time; // r11
  int acceltime; // r10
  int deceltime; // r9
  int v16; // r9
  soundShaderFlags_t soundFlags; // r6
  double LengthBetweenKnots; // fp1
  __int64 v19; // r5
  bool useSplineAngles; // r27
  int v21; // r3
  bool v22; // r6
  int v23; // r3
  __int64 v24; // r10
  int v25; // r8
  int v26; // r7
  int v27; // r6
  const float *v28; // r5
  const float *v29; // r4
  double initialSpeed; // fp2
  __int64 v31; // r10
  int v32; // r8
  int v33; // r7
  int v34; // r6
  const float *v35; // r5
  const float *v36; // r4
  double v37; // fp1
  __int64 v38; // r10
  int v39; // r8
  int v40; // r7
  int v41; // r6
  const float *v42; // r5
  const float *v43; // r4
  const idList<splineMoverModifier_t,5> *v44; // r11
  int v45; // r10
  int splineModifierIndex; // r11
  int v47; // r11
  bool v48; // cr32
  const idList<splineMoverModifier_t,5> *splineMoverModifiers; // r11
  idRenderWorld *v50; // r30
  __int64 v51; // r7
  __int64 v52; // [sp+50h] [-50h]

  if ( splineEntity == nullptr )
    return 0;
  v8 = *(_DWORD *)(splineEntity->GetType(this: splineEntity) + 36);
  if ( v8 < idSplinePathMM::Type.typeNum || (v10 = v8 <= idSplinePathMM::Type.lastChild, v9 = 1, !v10) )
    v9 = 0;
  if ( v9 == 0 )
    return 0;
  this->splinePath = splineEntity;
  v11 = idSplinePathMM::AllocSpline(this: splineEntity);
  this->spline = v11;
  if ( v11 == nullptr )
    return 0;
  move_time = this->move_time;
  if ( move_time == 0 && this->move_speed <= 0.0 )
  {
    idLib::Warning(fmt: "startSpline for '%s' called without a valid move_time or move_speed!", this->name.data);
    return 0;
  }
  acceltime = this->acceltime;
  deceltime = this->deceltime;
  this->lastCommand = MOVER_SPLINE;
  if ( deceltime + acceltime > move_time )
  {
    acceltime = move_time / 2;
    this->acceltime = move_time / 2;
    this->deceltime = move_time - move_time / 2;
  }
  v16 = this->deceltime;
  this->move.acceleration = acceltime;
  this->move.stage = FINISHED_STAGE;
  this->move.movetime = move_time;
  soundFlags = this->soundFlags;
  this->move.deceleration = v16;
  idEntity::StartSoundShader(
    this,
    channel: SND_CHANNEL_BODY,
    shader: this->sndMove,
    soundShaderFlags: soundFlags,
    peerMask: 0xFFu);
  LengthBetweenKnots = idCurve<idVec3>::GetLengthBetweenKnots(
                         this: this->spline,
                         i0: 0,
                         i1: this->spline->values.num - 1);
  if ( this->move_time == 0 )
  {
    if ( this->move_speed == 0.0 )
      this->move_speed = 1.0;
    this->move_time = (int)(float)((float)((float)1000.0 / this->move_speed) * (float)LengthBetweenKnots);
  }
  this->splineTotalLength = this->spline->GetLengthForTime(
                              this: this->spline,
                              a2: this->spline->times.list[this->spline->values.num - 1]);
  HIDWORD(v19) = 1;
  useSplineAngles = this->useSplineAngles;
  LODWORD(v19) = this->move_time;
  v52 = v19;
  v21 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idPhysics_ParametricMM::SetSpline(
    this: &this->physicsObj,
    spline: this->spline,
    startTime: v21,
    totalTime: (float)v52,
    useSplineAngles: v22,
    startAtEnd: useSplineAngles,
    startSplineTime: startTime,
    a8: startFromEnd);
  v23 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idPhysics_ParametricMM::SetLinearExtrapolation(
    this: &this->physicsObj,
    type: EXTRAPOLATION_NONE,
    currentTime: v23,
    duration: (unsigned int)&this->dest_position,
    base: &vec3_origin,
    speed: &vec3_origin);
  initialSpeed = this->initialSpeed;
  if ( initialSpeed > 0.0 )
  {
    idPhysics_ParametricMM::SetSplineExplicitSpeed(
      this: &this->physicsObj,
      startSpeed: this->initialSpeed,
      endSpeed: initialSpeed,
      endPos: 0.0,
      a5: v29,
      a6: v28,
      a7: v27,
      a8: v26,
      a9: v25,
      a10: v24);
    if ( startFromEnd != 0 )
    {
      idPhysics_ParametricMM::SetSplineContinue(
        this: &this->physicsObj,
        endPos: 0.0,
        a3: v36,
        a4: v35,
        a5: v34,
        a6: v33,
        a7: v32,
        a8: v31);
      splineMoverModifiers = this->splineMoverModifiers;
      if ( splineMoverModifiers != nullptr )
        v45 = splineMoverModifiers->num - 1;
      else
        v45 = 0;
      v47 = this->splineModifierIndex - 2;
      v48 = v47 < 0;
    }
    else
    {
      v37 = ((double (__fastcall *)(idCurve_Spline<idVec3> *, double))this->spline->GetLengthForTime)(
              a1: this->spline,
              a2: this->spline->times.list[this->spline->values.num - 1]);
      idPhysics_ParametricMM::SetSplineContinue(
        this: &this->physicsObj,
        endPos: v37,
        a3: v43,
        a4: v42,
        a5: v41,
        a6: v40,
        a7: v39,
        a8: v38);
      v44 = this->splineMoverModifiers;
      if ( v44 != nullptr )
      {
        v45 = v44->num - 1;
        splineModifierIndex = this->splineModifierIndex;
      }
      else
      {
        splineModifierIndex = this->splineModifierIndex;
        v45 = 0;
      }
      v47 = splineModifierIndex + 2;
      v48 = v47 < 0;
    }
    if ( v48 )
    {
      v47 = 0;
    }
    else if ( v47 > v45 )
    {
      v47 = v45;
    }
    this->splineModifierIndex = v47;
  }
  if ( g_showSwarmSplines.valueInteger != 0 )
  {
    v50 = gameLocal->GetRenderWorld(this: gameLocal);
    LODWORD(v51) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    HIDWORD(v51) = (idRenderWorld)v50->__vftable;
    ((void (__fastcall *)(idRenderWorld *, idColor *, idCurve_Spline<idVec3> *, idRenderWorld_vtbl *, int, int, int, double))v50->DebugSpline)(
      a1: v50,
      a2: &idColor::colorMagenta,
      a3: this->spline,
      a4: v50->__vftable,
      a5: 1,
      a6: 5000,
      a7: 1,
      a8: (float)((float)v51 * (float)0.001));
  }
  return 1;
}


// ========================================================================
// ?Event_StartSpline@idMover@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82C92060
// RVA : 0x00C92060
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idMover *__fastcall idMover::Event_StartSpline(idMover *this, idEntity *result, idSplinePath *splineEntity)
{
  idCurve_Spline<idVec3> *v6; // r30
  __int64 v7; // r7
  int v8; // r5
  int v9; // r4
  __int64 v10; // r10
  int num; // r11
  int v12; // r8
  int size; // r8
  __int64 v14; // r9
  int GameMs; // r3
  int v16; // r11
  int v17; // r10
  double v18; // fp0
  float *v19; // r9
  int v20; // r3
  int v22; // [sp+60h] [-60h]
  const idEventArg *v23; // [sp+68h] [-58h]

  if ( (unsigned __int8)idSplinePath::IsTypeOf(c: splineEntity) != 0 )
  {
    v6 = idSplinePath::AllocSplineInternal<idVec3>(this: splineEntity, ctrlPoints: &splineEntity->controlPoints);
    if ( v6 != nullptr )
    {
      if ( result[2].defaultPhysicsObj.contactPhysicsIds.num == 0 )
        idLib::Warning(fmt: "startSpline for '%s' called without a valid move_time!", result->name.data);
      LODWORD(v10) = *(_DWORD *)&result[2].defaultPhysicsObj.contactPhysicsIds.granularity;
      HIDWORD(v10) = 3;
      num = result[2].defaultPhysicsObj.contactPhysicsIds.num;
      v12 = v10 + result[2].defaultPhysicsObj.contactPhysicsIds.size;
      LODWORD(result[2].defaultPhysicsObj.current.worldOrigin.x) = 3;
      result[2].thinkFlags = 0;
      if ( v12 > num )
      {
        LODWORD(v10) = num / 2;
        *(_DWORD *)&result[2].defaultPhysicsObj.contactPhysicsIds.granularity = num / 2;
        result[2].defaultPhysicsObj.contactPhysicsIds.size = num - num / 2;
      }
      size = result[2].defaultPhysicsObj.contactPhysicsIds.size;
      LODWORD(v7) = num;
      *(_DWORD *)&result[2].bindInfo.bindTag.parentJoint.value = num;
      LODWORD(result[2].bindInfo.bindTag.rot.y) = 3;
      LODWORD(result[2].bindInfo.bindTag.rot.z) = 3;
      LODWORD(result[2].bindInfo.bindTag.rot.w) = v10;
      LODWORD(result[2].dormancy.delay) = size;
      idCurve<idAngles>::MakeUniform(this: v6, totalTime: (float)v7, a3: v9, a4: v8, a5: SHIDWORD(v7), a6: num, a7: v10);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v16 = 0;
      if ( v6->times.num > 0 )
      {
        LODWORD(v14) = GameMs;
        v17 = 0;
        v18 = (float)((float)v14 - *v6->times.list);
        do
        {
          ++v16;
          v19 = &v6->times.list[v17++];
          *v19 = (float)v18 + *v19;
        }
        while ( v16 < v6->times.num );
      }
      v6->changed = true;
      if ( *(int *)&result[2].defaultPhysicsObj.contactPhysicsIds.granularity <= 0 )
      {
        LODWORD(result[2].bindInfo.bindTag.rot.z) = 1;
      }
      else
      {
        result[2].bindInfo.bindTag.rot.z = 0.0;
        idEntity::StartSoundShader(
          this: result,
          channel: SND_CHANNEL_BODY2,
          shader: (const idSoundShader *)LODWORD(result[2].defaultPhysicsObj.current.worldAxis.mat[1].x),
          soundShaderFlags: (soundShaderFlags_t)(result[2].dormancy.endForceTime | 0x400),
          peerMask: 0xFFu);
        idEntity::StartSoundShader(
          this: result,
          channel: SND_CHANNEL_BODY,
          shader: (const idSoundShader *)LODWORD(result[2].defaultPhysicsObj.current.worldAxis.mat[1].z),
          soundShaderFlags: (soundShaderFlags_t)result[2].dormancy.endForceTime,
          peerMask: 0xFFu);
        HIBYTE(v22) = 105;
        idEventReceiver::PostEventMS(this: result, ev: &EV_UpdateMoveSound, time: v22, arg1: v23);
        HIBYTE(v22) = 105;
        idEventReceiver::PostEventMS(
          this: result,
          ev: &EV_UpdateMoveSound,
          time: result[2].defaultPhysicsObj.contactPhysicsIds.num - result[2].defaultPhysicsObj.contactPhysicsIds.size,
          arg1: *(const idEventArg **)(v22 + 8));
      }
      idPhysics_Parametric::SetSpline(
        this: (idPhysics_Parametric *)&result[1],
        spline: v6,
        accelTime: LODWORD(result[2].bindInfo.bindTag.rot.w),
        decelTime: (const float *)LODWORD(result[2].dormancy.delay),
        useSplineAngles: *((_BYTE *)&result[2].defaultPhysicsObj + 70),
        angularSpline: nullptr);
      v20 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idPhysics_Parametric::SetLinearExtrapolation(
        this: (idPhysics_Parametric *)&result[1],
        type: EXTRAPOLATION_NONE,
        currentTime: v20,
        duration: (unsigned int)&result[2].defaultPhysicsObj.callbacks,
        base: &vec3_origin,
        speed: &vec3_origin);
    }
  }
  return this;
}


// ========================================================================
// ?Event_FollowSpline@idMover@@AAA?AVeventVoid@@PAVidEntity@@HH@Z
// EA  : 0x82C922D0
// RVA : 0x00C922D0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idMover *__fastcall idMover::Event_FollowSpline(
        idMover *this,
        idEntity *result,
        idSplinePathWithOrientation *splineEntity,
        int ignoreEntityRotation,
        int followSplineInitialRotation)
{
  idCurve_Spline<idVec3> *v10; // r27
  idCurve<idVec3> *v11; // r28
  __int64 v12; // r7
  int v13; // r5
  int v14; // r4
  idSplinePathWithOrientation *v15; // r3
  idSplinePathWithOrientation *v16; // r30
  char useSplineForward; // r22
  idCurve_Spline<idAngles> *v18; // r3
  __int64 v19; // r10
  int num; // r11
  int v21; // r8
  int size; // r8
  __int64 v23; // r10
  int v24; // r7
  int v25; // r6
  int GameMs; // r3
  float *list; // r5
  int v28; // r4
  int v29; // r11
  double v30; // fp0
  double v31; // fp0
  int v32; // r3
  __int64 v33; // r9
  int v34; // r11
  double v35; // fp0
  int v36; // r10
  double v37; // fp0
  float *v38; // r9
  int v39; // r10
  int v40; // r9
  int v41; // r3
  bool v42; // r7
  int v43; // r3
  double roll; // fp31
  double yaw; // fp29
  double pitch; // fp30
  idAngles *v47; // r3
  idAngles *v48; // r3
  float *v49; // r3
  int v50; // r3
  idAngles *v51; // r8
  __int64 v53; // [sp+50h] [-D0h] BYREF
  float v54; // [sp+60h] [-C0h] BYREF
  float v55; // [sp+64h] [-BCh]
  float v56; // [sp+68h] [-B8h]
  float v57; // [sp+70h] [-B0h] BYREF
  float v58; // [sp+74h] [-ACh]
  float v59; // [sp+78h] [-A8h]
  idVec3 v60[2]; // [sp+80h] [-A0h] BYREF

  if ( (unsigned __int8)idSplinePath::IsTypeOf(c: splineEntity) != 0 )
  {
    v10 = idSplinePath::AllocSplineInternal<idVec3>(this: splineEntity, ctrlPoints: &splineEntity->controlPoints);
    if ( v10 != nullptr )
    {
      v11 = nullptr;
      v15 = idSplinePathWithOrientation::CastTo(c: splineEntity);
      v16 = v15;
      useSplineForward = 1;
      if ( v15 != nullptr )
      {
        v18 = idSplinePath::AllocSplineInternal<idAngles>(this: v15, ctrlPoints: &v15->controlPointRotations);
        useSplineForward = v16->useSplineForward;
        v11 = (idCurve<idVec3> *)v18;
      }
      if ( result[2].defaultPhysicsObj.contactPhysicsIds.num == 0 )
        idLib::Warning(fmt: "startSpline for '%s' called without a valid move_time!", result->name.data);
      LODWORD(v19) = *(_DWORD *)&result[2].defaultPhysicsObj.contactPhysicsIds.granularity;
      HIDWORD(v19) = 3;
      num = result[2].defaultPhysicsObj.contactPhysicsIds.num;
      v21 = v19 + result[2].defaultPhysicsObj.contactPhysicsIds.size;
      LODWORD(result[2].defaultPhysicsObj.current.worldOrigin.x) = 3;
      result[2].thinkFlags = 0;
      if ( v21 > num )
      {
        LODWORD(v19) = num / 2;
        *(_DWORD *)&result[2].defaultPhysicsObj.contactPhysicsIds.granularity = num / 2;
        result[2].defaultPhysicsObj.contactPhysicsIds.size = num - num / 2;
      }
      size = result[2].defaultPhysicsObj.contactPhysicsIds.size;
      LODWORD(v12) = num;
      *(_DWORD *)&result[2].bindInfo.bindTag.parentJoint.value = num;
      LODWORD(result[2].bindInfo.bindTag.rot.y) = 3;
      LODWORD(result[2].bindInfo.bindTag.rot.z) = 3;
      LODWORD(result[2].bindInfo.bindTag.rot.w) = v19;
      LODWORD(result[2].dormancy.delay) = size;
      v53 = v12;
      idCurve<idAngles>::MakeUniform(
        this: v10,
        totalTime: (float)v12,
        a3: v14,
        a4: v13,
        a5: SHIDWORD(v12),
        a6: num,
        a7: v19);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      list = v10->times.list;
      v28 = v10->times.num;
      v29 = 0;
      v30 = *list;
      if ( v28 > 0 )
      {
        HIDWORD(v23) = GameMs;
        LODWORD(v23) = 0;
        v53 = *(__int64 *)((char *)&v23 + 4);
        v31 = (float)((float)*(__int64 *)((char *)&v23 + 4) - (float)v30);
        do
        {
          ++v29;
          HIDWORD(v23) = (char *)v10->times.list + v23;
          LODWORD(v23) = v23 + 4;
          *(float *)HIDWORD(v23) = (float)v31 + *(float *)HIDWORD(v23);
          HIDWORD(v23) = v10->times.num;
        }
        while ( v29 < SHIDWORD(v23) );
      }
      v10->changed = true;
      if ( v11 != nullptr )
      {
        LODWORD(v23) = result[2].defaultPhysicsObj.contactPhysicsIds.num;
        v53 = v23;
        idCurve<idAngles>::MakeUniform(
          this: v11,
          totalTime: (float)v23,
          a3: v28,
          a4: (int)list,
          a5: v25,
          a6: v24,
          a7: v23);
        v32 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        HIDWORD(v33) = v11->times.num;
        v34 = 0;
        v35 = *v11->times.list;
        if ( SHIDWORD(v33) > 0 )
        {
          LODWORD(v33) = v32;
          v36 = 0;
          v53 = v33;
          v37 = (float)((float)v33 - (float)v35);
          do
          {
            ++v34;
            v38 = &v11->times.list[v36++];
            *v38 = (float)v37 + *v38;
          }
          while ( v34 < v11->times.num );
        }
        v11->changed = true;
      }
      if ( *(int *)&result[2].defaultPhysicsObj.contactPhysicsIds.granularity <= 0 )
      {
        LODWORD(result[2].bindInfo.bindTag.rot.z) = 1;
      }
      else
      {
        result[2].bindInfo.bindTag.rot.z = 0.0;
        idEntity::StartSoundShader(
          this: result,
          channel: SND_CHANNEL_BODY2,
          shader: (const idSoundShader *)LODWORD(result[2].defaultPhysicsObj.current.worldAxis.mat[1].x),
          soundShaderFlags: (soundShaderFlags_t)(result[2].dormancy.endForceTime | 0x400),
          peerMask: 0xFFu);
        idEntity::StartSoundShader(
          this: result,
          channel: SND_CHANNEL_BODY,
          shader: (const idSoundShader *)LODWORD(result[2].defaultPhysicsObj.current.worldAxis.mat[1].z),
          soundShaderFlags: (soundShaderFlags_t)result[2].dormancy.endForceTime,
          peerMask: 0xFFu);
        LODWORD(v60[0].y) = 1;
        HIBYTE(v60[0].x) = 105;
        idEventReceiver::PostEventMS(
          this: result,
          ev: &EV_UpdateMoveSound,
          time: SLODWORD(v60[0].x),
          arg1: (const idEventArg *)LODWORD(v60[0].z));
        v39 = result[2].defaultPhysicsObj.contactPhysicsIds.num;
        v40 = result[2].defaultPhysicsObj.contactPhysicsIds.size;
        LODWORD(v60[0].y) = 2;
        HIBYTE(v60[0].x) = 105;
        idEventReceiver::PostEventMS(
          this: result,
          ev: &EV_UpdateMoveSound,
          time: v39 - v40,
          arg1: *(const idEventArg **)(LODWORD(v60[0].x) + 8));
      }
      v41 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idPhysics_Parametric::GetCurrentAngularExtrapolationAngles(
        this: (idPhysics_Parametric *)&v57,
        result: (idAngles *)&result[1],
        time: v41);
      if ( *((_BYTE *)&result[2].defaultPhysicsObj + 70) == 0 || (v42 = true, useSplineForward == 0) )
        v42 = false;
      idPhysics_Parametric::SetSpline(
        this: (idPhysics_Parametric *)&result[1],
        spline: v10,
        accelTime: LODWORD(result[2].bindInfo.bindTag.rot.w),
        decelTime: (const float *)LODWORD(result[2].dormancy.delay),
        useSplineAngles: v42,
        angularSpline: *((_BYTE *)&result[2].defaultPhysicsObj + 70) == 0 ? nullptr : (idCurve_Spline<idAngles> *)v11);
      v43 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idPhysics_Parametric::SetLinearExtrapolation(
        this: (idPhysics_Parametric *)&result[1],
        type: EXTRAPOLATION_NONE,
        currentTime: v43,
        duration: (unsigned int)&result[2].defaultPhysicsObj.callbacks,
        base: &vec3_origin,
        speed: &vec3_origin);
      if ( followSplineInitialRotation != 0 && ignoreEntityRotation != 0
        || *((_BYTE *)&result[2].defaultPhysicsObj + 70) == 0 )
      {
        v50 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v51 = &ang_zero;
      }
      else
      {
        v54 = v57;
        v55 = v58;
        v56 = v59;
        if ( followSplineInitialRotation == 0 )
        {
          roll = 0.0;
          yaw = 0.0;
          pitch = 0.0;
          if ( useSplineForward != 0 )
          {
            v47 = (idAngles *)v10->GetCurrentFirstDerivative(
                                this: (struct idCurve_Spline<idVec3> *)&v53,
                                result: (idVec3 *)v10,
                                a3: *v10->times.list);
            v48 = idVec3::ToAngles(this: v60, result: v47);
            pitch = v48->pitch;
            yaw = v48->yaw;
            roll = v48->roll;
          }
          if ( v11 != nullptr )
          {
            v49 = (float *)v11->GetCurrentFirstDerivative(
                             this: (idCurve<idVec3> *)v60,
                             result: (idVec3 *)v11,
                             a3: *v10->times.list);
            pitch = (float)((float)pitch + *v49);
            yaw = (float)(v49[1] + (float)yaw);
            roll = (float)(v49[2] + (float)roll);
          }
          if ( ignoreEntityRotation != 0 )
          {
            v54 = -pitch;
            v55 = -yaw;
            v56 = -roll;
          }
          else
          {
            v54 = v57 - (float)pitch;
            v55 = v58 - (float)yaw;
            v56 = v59 - (float)roll;
          }
        }
        v50 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v51 = (idAngles *)&v54;
      }
      idPhysics_Parametric::SetAngularExtrapolation(
        this: (idPhysics_Parametric *)&result[1],
        type: EXTRAPOLATION_NONE,
        currentTime: v50,
        duration: (unsigned int)v51,
        base: &ang_zero,
        speed: &ang_zero);
    }
  }
  return this;
}


// ========================================================================
// ?OnActivate@idMover@@EAAXPAVidEntity@@@Z
// EA  : 0x82C927D8
// RVA : 0x00C927D8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMover::OnActivate(idMover *this, idEntity *activator)
{
  char v3; // [sp+50h] [-20h] BYREF

  ((void (__fastcall *)(idMover *, idEntity *))this->Show)(a1: this, a2: activator);
  idMover::Event_StartSpline(this: (idMover *)&v3, result: this, splineEntity: (idSplinePath *)this);
}


// ========================================================================
// ?Spawn@idSplinePath@@QAAXXZ
// EA  : 0x82C92820
// RVA : 0x00C92820
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idSplinePath::Spawn(idSplinePath *this)
{
  idPhysics *Physics; // r3
  int v3; // r10
  int v4; // r9
  int v5; // r8
  int v6; // r7
  int v7; // r6
  int v8; // r5
  idPresentable *presentable; // r11
  idPhysics *v10; // r3
  int v11; // r10
  int v12; // r9
  int v13; // r8
  int v14; // r7
  int v15; // r6
  int v16; // r5
  idPresentable *v17; // r3

  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) != 0 )
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
      a3: v8,
      a4: v7,
      a5: v6,
      a6: v5,
      a7: v4,
      a8: v3);
  }
  else
  {
    v10 = idEntity::GetPhysics(this);
    v10->SetContents(this: v10, a2: 0, a3: -1);
    v17 = this->presentable;
    if ( v17 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v17 = this->presentable;
    }
    idPresentable::SetClipModelContents(this: v17, newContents: 0, a3: v16, a4: v15, a5: v14, a6: v13, a7: v12, a8: v11);
    this->Hide_2(this);
  }
  if ( g_spline_debug.valueInteger > 0 )
  {
    this->allocedSpline = idSplinePath::AllocSplineInternal<idVec3>(this, ctrlPoints: &this->controlPoints);
    idEntity::BecomeActive(this, flags: 1);
  }
}


// ========================================================================
// ??0idSplinePathMM@@QAA@XZ
// EA  : 0x82C92928
// RVA : 0x00C92928
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idSplinePathMM *__fastcall idSplinePathMM::idSplinePathMM(idSplinePathMM *this)
{
  idEntity::idEntity(this);
  this->type = CatmullRomSpline;
  this->__vftable = (idSplinePathMM_vtbl *)&idSplinePathMM::`vftable';
  this->controlPoints.list = nullptr;
  this->controlPoints.granularity = 0;
  this->controlPoints.memTag = 5;
  this->controlPoints.listStatic = 0;
  this->controlPoints.size = 0;
  this->controlPoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->controlPoints);
  this->weightPoints.list = nullptr;
  this->weightPoints.granularity = 0;
  this->weightPoints.memTag = 5;
  this->weightPoints.listStatic = 0;
  this->weightPoints.size = 0;
  this->weightPoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->weightPoints);
  this->controlNode.owner = nullptr;
  this->controlNode.head = &this->controlNode;
  this->controlNode.next = &this->controlNode;
  this->controlNode.prev = &this->controlNode;
  this->moverModifiers.granularity = 0;
  this->moverModifiers.memTag = 5;
  this->moverModifiers.listStatic = 0;
  this->moverModifiers.list = nullptr;
  this->moverModifiers.size = 0;
  this->moverModifiers.num = 0;
  this->moverModifierEntities.list = nullptr;
  this->moverModifierEntities.granularity = 0;
  this->moverModifierEntities.memTag = 5;
  this->moverModifierEntities.listStatic = 0;
  this->moverModifierEntities.size = 0;
  this->moverModifierEntities.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->moverModifierEntities);
  this->moverModifierModels.orientationModModel.len = 0;
  this->moverModifierModels.orientationModModel.allocedAndFlag = 20;
  this->moverModifierModels.orientationModModel.data = this->moverModifierModels.orientationModModel.baseBuffer;
  this->moverModifierModels.orientationModModel.baseBuffer[0] = 0;
  this->moverModifierModels.defaultModModel.allocedAndFlag = 20;
  this->moverModifierModels.defaultModModel.data = this->moverModifierModels.defaultModModel.baseBuffer;
  this->moverModifierModels.defaultModModel.len = 0;
  this->moverModifierModels.defaultModModel.baseBuffer[0] = 0;
  this->graphDef = nullptr;
  this->anchorStart.spawnId.value = 0x1FFF;
  this->anchorEnd.spawnId.value = 0x1FFF;
  this->allocedSpline = nullptr;
  this->cachedSplineLength = 0.0;
  this->splineChildEntities.list = nullptr;
  this->splineChildEntities.granularity = 0;
  this->splineChildEntities.memTag = 5;
  this->splineChildEntities.listStatic = 0;
  this->splineChildEntities.size = 0;
  this->splineChildEntities.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splineChildEntities);
  this->splineGeometry.generateGeometry = false;
  this->splineGeometry.splineSubdivisions = 8;
  this->splineGeometry.sweptSubdivisions = 8;
  this->moverModifierModels.moverScale = 1.0;
  this->splineGeometry.radius = 6.0;
  return this;
}


// ========================================================================
// __unwind$524428
// EA  : 0x82C92AA8
// RVA : 0x00C92AA8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_524428()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$524429
// EA  : 0x82C92AD0
// RVA : 0x00C92AD0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_524429()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 804));
}


// ========================================================================
// __unwind$524430
// EA  : 0x82C92AFC
// RVA : 0x00C92AFC
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_524430()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 820));
}


// ========================================================================
// __unwind$524431
// EA  : 0x82C92B28
// RVA : 0x00C92B28
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_524431()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                           + 852));
}


// ========================================================================
// __unwind$524432
// EA  : 0x82C92B54
// RVA : 0x00C92B54
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_524432()
{
  int v0; // r12

  idList<splineMoverModifier_t,5>::Clear(this: (idList<splineMoverModifier_t,5> *)(*(_DWORD *)(v0 - 128 + 148) + 868));
}


// ========================================================================
// __unwind$524433
// EA  : 0x82C92B80
// RVA : 0x00C92B80
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_524433()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 884));
}


// ========================================================================
// __unwind$524434
// EA  : 0x82C92BAC
// RVA : 0x00C92BAC
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_524434()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(*(_DWORD *)(v0 - 128 + 148) + 900));
}


// ========================================================================
// ??1idSplinePathMM@@UAA@XZ
// EA  : 0x82C92BE0
// RVA : 0x00C92BE0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idSplinePathMM::~idSplinePathMM(idSplinePathMM *this)
{
  idLinkList<idProp_VehiclePickup> *p_controlNode; // r29
  idCurve_Spline<idVec3> *allocedSpline; // r3
  splineMoverModifier_t *list; // r3

  this->__vftable = (idSplinePathMM_vtbl *)&idSplinePathMM::`vftable';
  p_controlNode = (idLinkList<idProp_VehiclePickup> *)&this->controlNode;
  this->controlNode.prev->next = this->controlNode.next;
  this->controlNode.next->prev = this->controlNode.prev;
  this->controlNode.next = &this->controlNode;
  this->controlNode.prev = &this->controlNode;
  this->controlNode.head = &this->controlNode;
  allocedSpline = this->allocedSpline;
  if ( allocedSpline != nullptr )
    ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))allocedSpline->dtr_idCurve<idVec3>)(a1: allocedSpline, a2: 1);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splineChildEntities);
  idKeyValue::~idKeyValue(this: (idXMLAttribute *)&this->moverModifierModels);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->moverModifierEntities);
  if ( this->moverModifiers.listStatic == 0 || this->moverModifiers.listStatic == 2 )
  {
    list = this->moverModifiers.list;
    if ( list != nullptr )
      idListArrayDelete<splineMoverModifier_t>(ptr: list, num: this->moverModifiers.size);
    this->moverModifiers.list = nullptr;
    this->moverModifiers.size = 0;
  }
  this->moverModifiers.num = 0;
  idLinkList<idEvent>::Clear(this: p_controlNode);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->weightPoints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->controlPoints);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$524651
// EA  : 0x82C92CC8
// RVA : 0x00C92CC8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_524651()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$524652
// EA  : 0x82C92CF0
// RVA : 0x00C92CF0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_524652()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 804));
}


// ========================================================================
// __unwind$524653
// EA  : 0x82C92D1C
// RVA : 0x00C92D1C
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_524653()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 820));
}


// ========================================================================
// __unwind$524654
// EA  : 0x82C92D48
// RVA : 0x00C92D48
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_524654()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                           + 852));
}


// ========================================================================
// __unwind$524655
// EA  : 0x82C92D74
// RVA : 0x00C92D74
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_524655()
{
  int v0; // r12

  idList<splineMoverModifier_t,5>::Clear(this: (idList<splineMoverModifier_t,5> *)(*(_DWORD *)(v0 - 128 + 148) + 868));
}


// ========================================================================
// __unwind$524656
// EA  : 0x82C92DA0
// RVA : 0x00C92DA0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_524656()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 884));
}


// ========================================================================
// __unwind$524657
// EA  : 0x82C92DCC
// RVA : 0x00C92DCC
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_524657()
{
  int v0; // r12

  idKeyValue::~idKeyValue(this: (idXMLAttribute *)(*(_DWORD *)(v0 - 128 + 148) + 900));
}


// ========================================================================
// __unwind$524658
// EA  : 0x82C92DF8
// RVA : 0x00C92DF8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_524658()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 988));
}


// ========================================================================
// ?HandleMoverModifier_Sound@idMoverMM@@MAAXABUsplineMoverModifier_t@@AAVidPhysics_ParametricMM@@MM@Z
// EA  : 0x82C93728
// RVA : 0x00C93728
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idMoverMM::HandleMoverModifier_Sound(
        idMoverMM *this,
        const splineMoverModifier_t *mod,
        idPhysics_ParametricMM *physObj,
        double currentSplinePosition,
        double splineTotalLength)
{
  int v8; // r26
  int v9; // r27
  int v10; // r9
  idEntity *v11; // r3
  idEntity *v12; // r3
  idEntity *v13; // r31
  idSoundEmitter *v14; // r28
  splineMoverModifier_t::splineMoverModifierSound_t::splineMoverModifierSound_NewSoundInfo_t *v15; // r11
  const idSoundShader *sound; // r31
  soundChannel_t channel; // r30
  soundShaderFlags_t flags; // r29
  int v19; // r29
  int v20; // r31
  int v21; // r9
  idEntity *v22; // r3
  idEntity *v23; // r3
  idEntity *v24; // r30
  idSoundEmitter *v25; // r30
  int v26; // r26
  int v27; // r28
  int value; // r9
  idEntity *v29; // r3
  idEntity *v30; // r3
  idEntity *v31; // r31
  idSoundEmitter *v32; // r31
  splineMoverModifier_t::splineMoverModifierSound_t::splineMoverModifierSound_NewSoundInfo_Pitch_t *v33; // r11
  double newPitch; // r4
  splineMoverModifier_t::splineMoverModifierSound_t::splineMoverModifierSound_NewSoundInfo_Pitch_t *v35; // r11
  splineMoverModifier_t::splineMoverModifierSound_t::splineMoverModifierSound_NewSoundInfo_Pitch_t *v36; // r6
  int v37; // r8
  char v38; // r5
  int v39; // r31
  int v40; // r11
  idMoverMM::moverSoundInterpolater_t *v41; // r10
  idEntity *v42; // r3
  idEntity *v43; // r3
  splineMoverModifier_t::splineMoverModifierSound_t::splineMoverModifierSound_NewSoundInfo_Pitch_t *v44; // r10
  idMoverMM::moverSoundInterpolater_t *v45; // r11
  double v46; // fp12
  double v47; // fp11
  int v48; // r9
  idEntity *v49; // r3
  idEntity *v50; // r29
  idList<idMoverMM::moverSoundInterpolater_t,5> *p_sndPitchInterpolaters; // r31
  splineMoverModifier_t::splineMoverModifierSound_t::splineMoverModifierSound_NewSoundInfo_Pitch_t *v52; // r30
  int v53; // r11
  int v54; // r10
  idMoverMM::moverSoundInterpolater_t *v55; // r10
  int v56; // r11
  double v57; // fp0
  double v58; // fp12
  int v59; // r20
  __int64 v60; // r10
  int i; // r26
  idEntity *v62; // r3
  idEntity *v63; // r3
  idEntity *v64; // r31
  idSoundEmitter *SoundEmitter; // r29
  splineMoverModifier_t::splineMoverModifierSound_t::splineMoverModifierSound_NewSoundInfo_Volume_t *v66; // r11
  double newVolume; // r4
  splineMoverModifier_t::splineMoverModifierSound_t::splineMoverModifierSound_NewSoundInfo_Volume_t *v68; // r11
  int v69; // r4
  const splineMoverModifier_t *NextModifier; // r3
  const splineMoverModifier_t *v71; // r30
  int v72; // r27
  int v73; // r28
  idEntity *v74; // r3
  idEntity *v75; // r3
  idEntity *v76; // r31
  int v77; // r7
  int v78; // r6
  int v79; // r5
  idEntity *v80; // r3
  idEntity *v81; // r3
  double v82; // fp29
  __int64 v83; // r10
  int v84; // r7
  int v85; // r6
  int v86; // r5
  int v87; // r4
  double v88; // fp1
  splineMoverModifier_t::splineMoverModifierSound_t::splineMoverModifierSound_NewSoundInfo_Volume_t *v89; // r5
  int num; // r7
  char v91; // r4
  int v92; // r31
  int v93; // r11
  idMoverMM::moverSoundInterpolater_t *list; // r10
  idEntity *v95; // r3
  idEntity *v96; // r3
  idMoverMM::moverSoundInterpolater_t *v97; // r11
  double v98; // fp12
  double v99; // fp11
  idEntity *v100; // r3
  idEntity *v101; // r29
  splineMoverModifier_t::splineMoverModifierSound_t::splineMoverModifierSound_NewSoundInfo_Volume_t *v102; // r30
  int v103; // r11
  int size; // r10
  idMoverMM::moverSoundInterpolater_t *v105; // r9
  int v106; // r11
  double minSpeed; // fp0
  double maxSpeed; // fp13
  double v109; // fp12
  float v110[4]; // [sp+50h] [-150h] BYREF
  soundShaderParms_t v111; // [sp+60h] [-140h] BYREF

  v8 = 0;
  if ( mod->Sound.newSounds.num <= 0 )
  {
LABEL_15:
    v19 = 0;
    if ( mod->Sound.stopSounds.num <= 0 )
    {
LABEL_26:
      v26 = 0;
      if ( mod->Sound.pitch.num <= 0 )
      {
LABEL_68:
        v59 = 0;
        if ( mod->Sound.volume.num <= 0 )
          return;
        HIDWORD(v60) = gameLocal;
        for ( i = 0; ; ++i )
        {
          LODWORD(v60) = mod->Sound.volume.list[i].targetEmitter.spawnId.value;
          if ( *(_DWORD *)(4 * ((v60 & 0x1FFF) + 29755) + HIDWORD(v60)) != (int)v60 >> 13
            || (v62 = *(idEntity **)(4 * ((v60 & 0x1FFF) + 21563) + HIDWORD(v60))) == nullptr
            || (v63 = idEntity::CastTo(c: v62), v64 = v63, v63 == nullptr)
            || idEntity::GetSoundEmitter(this: v63, alloc: true) == nullptr
            || (SoundEmitter = idEntity::GetSoundEmitter(this: v64, alloc: false)) == nullptr )
          {
            SoundEmitter = idEntity::GetSoundEmitter(this, alloc: true);
            if ( SoundEmitter == nullptr )
              break;
          }
          v66 = &mod->Sound.volume.list[i];
          if ( v66->setNewVolume )
          {
            idMoverMM::clearSoundInterpolater(this, interpolaters: &this->sndVolumeInterpolaters, channel: v66->channel);
            SoundEmitter->SetVolume(
              this: SoundEmitter,
              a2: mod->Sound.volume.list[i].channel,
              a3: mod->Sound.volume.list[i].newVolume);
            if ( g_debugMoverModifiers.valueInteger != 0 )
            {
              newVolume = mod->Sound.volume.list[i].newVolume;
              idLib::Printf(fmt: (const char *)HIDWORD(newVolume), LODWORD(newVolume));
            }
          }
          v68 = &mod->Sound.volume.list[i];
          if ( v68->fadeToNextVolume )
          {
            NextModifier = idMoverMM::GetNextModifier(this, t: MOVERMODIFIER_SOUND, splinePos: v110);
            v71 = NextModifier;
            if ( NextModifier != nullptr )
            {
              v72 = 0;
              if ( NextModifier->Sound.volume.num > 0 )
              {
                HIDWORD(v60) = gameLocal;
                v73 = 0;
                while ( 1 )
                {
                  LODWORD(v60) = v71->Sound.volume.list[v73].targetEmitter.spawnId.value;
                  if ( *(_DWORD *)(4 * ((v60 & 0x1FFF) + 29755) + HIDWORD(v60)) == (int)v60 >> 13
                    && (v74 = *(idEntity **)(4 * ((v60 & 0x1FFF) + 21563) + HIDWORD(v60))) != nullptr )
                  {
                    v75 = idEntity::CastTo(c: v74);
                    HIDWORD(v60) = gameLocal;
                    v76 = v75;
                  }
                  else
                  {
                    v76 = nullptr;
                  }
                  LODWORD(v60) = mod->Sound.volume.list[i].targetEmitter.spawnId.value;
                  v77 = (v60 & 0x1FFF) + 29755;
                  v78 = 4 * v77;
                  v79 = *(_DWORD *)(4 * v77 + HIDWORD(v60));
                  if ( v79 == (int)v60 >> 13
                    && (LODWORD(v60) = 4 * ((v60 & 0x1FFF) + 21563),
                        (v80 = *(idEntity **)(v60 + HIDWORD(v60))) != nullptr) )
                  {
                    v81 = idEntity::CastTo(c: v80);
                    HIDWORD(v60) = gameLocal;
                  }
                  else
                  {
                    v81 = nullptr;
                  }
                  if ( v76 == v81 )
                    break;
                  ++v72;
                  ++v73;
                  if ( v72 >= v71->Sound.volume.num )
                    goto LABEL_99;
                }
                v82 = idPhysics_ParametricMM::TimeToLength(
                        this: physObj,
                        length: mod->length,
                        a3: v69,
                        a4: v79,
                        a5: v78,
                        a6: v77,
                        a7: v60);
                v88 = idPhysics_ParametricMM::TimeToLength(
                        this: physObj,
                        length: v110[0],
                        a3: v87,
                        a4: v86,
                        a5: v85,
                        a6: v84,
                        a7: v83);
                ((void (__fastcall *)(idSoundEmitter *, soundChannel_t, double, double, double))SoundEmitter->FadeSound)(
                  a1: SoundEmitter,
                  a2: mod->Sound.volume.list[i].channel,
                  a3: v71->Sound.volume.list->newVolume,
                  a4: (float)((float)((float)v88 - (float)v82) * 0.001),
                  a5: 0.0);
              }
            }
          }
          else if ( v68->fadeTime > 0.0 )
          {
            idMoverMM::clearSoundInterpolater(this, interpolaters: &this->sndVolumeInterpolaters, channel: v68->channel);
            ((void (__fastcall *)(idSoundEmitter *, soundChannel_t, double, double, double))SoundEmitter->FadeSound)(
              a1: SoundEmitter,
              a2: mod->Sound.volume.list[i].channel,
              a3: mod->Sound.volume.list[i].fadeTargetVolume,
              a4: mod->Sound.volume.list[i].fadeTime,
              a5: mod->Sound.volume.list[i].fadeDelay);
            if ( g_debugMoverModifiers.valueInteger != 0 )
              idLib::Printf(
                fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(mod->Sound.volume.list[i].fadeTargetVolume)),
                (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(mod->Sound.volume.list[i].fadeTime)),
                mod->Sound.volume.list[i].fadeDelay);
          }
          HIDWORD(v60) = gameLocal;
LABEL_99:
          v89 = &mod->Sound.volume.list[i];
          if ( v89->speedBinding.minValue != 0.0 || v89->speedBinding.maxValue != 0.0 )
          {
            num = this->sndVolumeInterpolaters.num;
            v91 = 0;
            v92 = 0;
            if ( num > 0 )
            {
              v93 = 0;
              list = this->sndVolumeInterpolaters.list;
              while ( list->channel != v89->channel )
              {
                ++v92;
                list = &this->sndVolumeInterpolaters.list[++v93];
                if ( v92 >= num )
                  goto LABEL_114;
              }
              if ( *(_DWORD *)(4 * ((v89->targetEmitter.spawnId.value & 0x1FFF) + 29755) + HIDWORD(v60)) == v89->targetEmitter.spawnId.value >> 13
                && (v95 = *(idEntity **)(4 * ((v89->targetEmitter.spawnId.value & 0x1FFF) + 21563) + HIDWORD(v60))) != nullptr )
              {
                v96 = idEntity::CastTo(c: v95);
              }
              else
              {
                v96 = nullptr;
              }
              LODWORD(v60) = &mod->Sound.volume.list[i];
              v97 = &this->sndVolumeInterpolaters.list[v92];
              v97->channel = *(_DWORD *)(v60 + 4);
              if ( v96 != nullptr )
                v97->targetEmitter.spawnId.value = (gameLocal->spawnIds.ptr[v96->entityNumber] << 13)
                                                 | v96->entityNumber;
              else
                v97->targetEmitter.spawnId.value = 0x1FFF;
              HIDWORD(v60) = gameLocal;
              v98 = (float)(*(float *)(v60 + 32) - (float)1.0);
              v99 = (float)(*(float *)(v60 + 36) - *(float *)(v60 + 32));
              v97->interpolater.startTime = *(float *)(v60 + 32);
              v97->interpolater.duration = v99;
              v91 = 1;
              v97->interpolater.startValue = *(float *)(v60 + 40);
              v97->interpolater.endValue = *(float *)(v60 + 44);
              v97->interpolater.currentTime = v98;
              v97->interpolater.currentValue = *(float *)(v60 + 40);
            }
LABEL_114:
            if ( v91 == 0 )
            {
              LODWORD(v60) = mod->Sound.volume.list[i].targetEmitter.spawnId.value;
              if ( *(_DWORD *)(4 * ((v60 & 0x1FFF) + 29755) + HIDWORD(v60)) == (int)v60 >> 13
                && (v100 = *(idEntity **)(4 * ((v60 & 0x1FFF) + 21563) + HIDWORD(v60))) != nullptr )
              {
                v101 = idEntity::CastTo(c: v100);
              }
              else
              {
                v101 = nullptr;
              }
              v102 = &mod->Sound.volume.list[i];
              idList<idMoverMM::moverSoundInterpolater_t,5>::PreAllocateWithGranularity(
                this: &this->sndVolumeInterpolaters,
                newSize: this->sndVolumeInterpolaters.num + 1);
              v103 = this->sndVolumeInterpolaters.num;
              size = this->sndVolumeInterpolaters.size;
              v105 = this->sndVolumeInterpolaters.list;
              if ( v103 >= size )
              {
                v106 = (int)&v105[size - 1];
              }
              else
              {
                this->sndVolumeInterpolaters.num = v103 + 1;
                v106 = (int)&v105[v103];
              }
              *(_DWORD *)(v106 + 4) = v102->channel;
              if ( v101 != nullptr )
                *(_DWORD *)v106 = (gameLocal->spawnIds.ptr[v101->entityNumber] << 13) | v101->entityNumber;
              else
                *(_DWORD *)v106 = 0x1FFF;
              minSpeed = v102->speedBinding.minSpeed;
              HIDWORD(v60) = gameLocal;
              maxSpeed = v102->speedBinding.maxSpeed;
              v109 = (float)(v102->speedBinding.minSpeed - (float)1.0);
              *(float *)(v106 + 8) = v102->speedBinding.minSpeed;
              *(float *)(v106 + 12) = (float)maxSpeed - (float)minSpeed;
              *(float *)(v106 + 16) = v102->speedBinding.minValue;
              *(float *)(v106 + 20) = v102->speedBinding.maxValue;
              *(float *)(v106 + 24) = v109;
              *(float *)(v106 + 28) = v102->speedBinding.minValue;
            }
          }
          if ( ++v59 >= mod->Sound.volume.num )
            return;
        }
      }
      else
      {
        v27 = 0;
        while ( 1 )
        {
          value = mod->Sound.pitch.list[v27].targetEmitter.spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
            || (v29 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
            || (v30 = idEntity::CastTo(c: v29), v31 = v30, v30 == nullptr)
            || idEntity::GetSoundEmitter(this: v30, alloc: true) == nullptr
            || (v32 = idEntity::GetSoundEmitter(this: v31, alloc: false)) == nullptr )
          {
            v32 = idEntity::GetSoundEmitter(this, alloc: true);
            if ( v32 == nullptr )
              break;
          }
          v33 = &mod->Sound.pitch.list[v27];
          if ( v33->setNewPitch )
          {
            idMoverMM::clearSoundInterpolater(this, interpolaters: &this->sndPitchInterpolaters, channel: v33->channel);
            v32->SetPitch(this: v32, a2: mod->Sound.pitch.list[v27].channel, a3: mod->Sound.pitch.list[v27].newPitch);
            if ( g_debugMoverModifiers.valueInteger != 0 )
            {
              newPitch = mod->Sound.pitch.list[v27].newPitch;
              idLib::Printf(fmt: (const char *)HIDWORD(newPitch), LODWORD(newPitch));
            }
          }
          v35 = &mod->Sound.pitch.list[v27];
          if ( v35->fadeTime > 0.0 )
          {
            idMoverMM::clearSoundInterpolater(this, interpolaters: &this->sndPitchInterpolaters, channel: v35->channel);
            v32->FadePitch(
              this: v32,
              a2: mod->Sound.pitch.list[v27].channel,
              a3: mod->Sound.pitch.list[v27].fadeTargetPitch,
              a4: mod->Sound.pitch.list[v27].fadeTime,
              a5: mod->Sound.pitch.list[v27].fadeDelay);
            if ( g_debugMoverModifiers.valueInteger != 0 )
              idLib::Printf(
                fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(mod->Sound.pitch.list[v27].fadeTargetPitch)),
                (unsigned int)COERCE_UNSIGNED_INT64(mod->Sound.pitch.list[v27].fadeTargetPitch),
                mod->Sound.pitch.list[v27].fadeDelay);
          }
          v36 = &mod->Sound.pitch.list[v27];
          if ( v36->speedBinding.minValue != 0.0 || v36->speedBinding.maxValue != 0.0 )
          {
            v37 = this->sndPitchInterpolaters.num;
            v38 = 0;
            v39 = 0;
            if ( v37 > 0 )
            {
              v40 = 0;
              v41 = this->sndPitchInterpolaters.list;
              while ( v41->channel != v36->channel )
              {
                ++v39;
                v41 = &this->sndPitchInterpolaters.list[++v40];
                if ( v39 >= v37 )
                  goto LABEL_55;
              }
              if ( gameLocal->spawnIds.ptr[v36->targetEmitter.spawnId.value & 0x1FFF] == v36->targetEmitter.spawnId.value >> 13
                && (v42 = gameLocal->entities.ptr[v36->targetEmitter.spawnId.value & 0x1FFF]) != nullptr )
              {
                v43 = idEntity::CastTo(c: v42);
              }
              else
              {
                v43 = nullptr;
              }
              v44 = &mod->Sound.pitch.list[v27];
              v45 = &this->sndPitchInterpolaters.list[v39];
              v45->channel = v44->channel;
              if ( v43 != nullptr )
                v45->targetEmitter.spawnId.value = (gameLocal->spawnIds.ptr[v43->entityNumber] << 13)
                                                 | v43->entityNumber;
              else
                v45->targetEmitter.spawnId.value = 0x1FFF;
              v38 = 1;
              v46 = (float)(v44->speedBinding.minSpeed - (float)1.0);
              v47 = (float)(v44->speedBinding.maxSpeed - v44->speedBinding.minSpeed);
              v45->interpolater.startTime = v44->speedBinding.minSpeed;
              v45->interpolater.duration = v47;
              v45->interpolater.startValue = v44->speedBinding.minValue;
              v45->interpolater.endValue = v44->speedBinding.maxValue;
              v45->interpolater.currentTime = v46;
              v45->interpolater.currentValue = v44->speedBinding.minValue;
            }
LABEL_55:
            if ( v38 == 0 )
            {
              v48 = mod->Sound.pitch.list[v27].targetEmitter.spawnId.value;
              if ( gameLocal->spawnIds.ptr[v48 & 0x1FFF] == v48 >> 13
                && (v49 = gameLocal->entities.ptr[v48 & 0x1FFF]) != nullptr )
              {
                v50 = idEntity::CastTo(c: v49);
              }
              else
              {
                v50 = nullptr;
              }
              p_sndPitchInterpolaters = &this->sndPitchInterpolaters;
              v52 = &mod->Sound.pitch.list[v27];
              idList<idMoverMM::moverSoundInterpolater_t,5>::PreAllocateWithGranularity(
                this: &this->sndPitchInterpolaters,
                newSize: this->sndPitchInterpolaters.num + 1);
              v53 = this->sndPitchInterpolaters.num;
              v54 = this->sndPitchInterpolaters.size;
              if ( v53 >= v54 )
              {
                v56 = (int)&p_sndPitchInterpolaters->list[v54 - 1];
              }
              else
              {
                v55 = p_sndPitchInterpolaters->list;
                this->sndPitchInterpolaters.num = v53 + 1;
                v56 = (int)&v55[v53];
              }
              *(_DWORD *)(v56 + 4) = v52->channel;
              if ( v50 != nullptr )
                *(_DWORD *)v56 = (gameLocal->spawnIds.ptr[v50->entityNumber] << 13) | v50->entityNumber;
              else
                *(_DWORD *)v56 = 0x1FFF;
              v57 = v52->speedBinding.minSpeed;
              v58 = (float)(v52->speedBinding.minSpeed - (float)1.0);
              *(float *)(v56 + 12) = v52->speedBinding.maxSpeed - v52->speedBinding.minSpeed;
              *(float *)(v56 + 8) = v57;
              *(float *)(v56 + 16) = v52->speedBinding.minValue;
              *(float *)(v56 + 20) = v52->speedBinding.maxValue;
              *(float *)(v56 + 24) = v58;
              *(float *)(v56 + 28) = v52->speedBinding.minValue;
            }
          }
          ++v26;
          ++v27;
          if ( v26 >= mod->Sound.pitch.num )
            goto LABEL_68;
        }
      }
    }
    else
    {
      v20 = 0;
      while ( 1 )
      {
        v21 = mod->Sound.stopSounds.list[v20].targetEmitter.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v21 & 0x1FFF] != v21 >> 13
          || (v22 = gameLocal->entities.ptr[v21 & 0x1FFF]) == nullptr
          || (v23 = idEntity::CastTo(c: v22), v24 = v23, v23 == nullptr)
          || idEntity::GetSoundEmitter(this: v23, alloc: true) == nullptr
          || (v25 = idEntity::GetSoundEmitter(this: v24, alloc: false)) == nullptr )
        {
          v25 = idEntity::GetSoundEmitter(this, alloc: true);
          if ( v25 == nullptr )
            break;
        }
        if ( g_debugMoverModifiers.valueInteger != 0 )
          idLib::Printf(fmt: "Stopping sound on channel: %d \n", mod->Sound.stopSounds.list[v20].channel);
        v25->StopSound(this: v25, a2: mod->Sound.stopSounds.list[v20].channel);
        ++v19;
        ++v20;
        if ( v19 >= mod->Sound.stopSounds.num )
          goto LABEL_26;
      }
    }
  }
  else
  {
    v9 = 0;
    while ( 1 )
    {
      v10 = mod->Sound.newSounds.list[v9].targetEmitter.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] != v10 >> 13
        || (v11 = gameLocal->entities.ptr[v10 & 0x1FFF]) == nullptr
        || (v12 = idEntity::CastTo(c: v11), v13 = v12, v12 == nullptr)
        || idEntity::GetSoundEmitter(this: v12, alloc: true) == nullptr
        || (v14 = idEntity::GetSoundEmitter(this: v13, alloc: false)) == nullptr )
      {
        v14 = idEntity::GetSoundEmitter(this, alloc: true);
        if ( v14 == nullptr )
          break;
      }
      v15 = &mod->Sound.newSounds.list[v9];
      sound = v15->sound;
      channel = v15->channel;
      flags = v15->flags;
      if ( sound != nullptr )
      {
        if ( g_debugMoverModifiers.valueInteger != 0 )
          idLib::Printf(fmt: "Playing sound: %s \n", sound->name.str);
        soundShaderParms_t::Clear(this: &v111);
        v111.soundShaderFlags = flags;
        v14->StartSound(this: v14, a2: channel, a3: sound, a4: &v111);
      }
      else
      {
        idLib::Warning(fmt: "Invalid sound tried to play on mover: %s ", this->name.data);
      }
      ++v8;
      ++v9;
      if ( v8 >= mod->Sound.newSounds.num )
        goto LABEL_15;
    }
  }
  idLib::Warning(fmt: "Unable to get sound emitter for mover: %s", this->name.data);
  idLib::Warning(fmt: "Unable to get sound emitter for mover: %s", this->name.data);
}


// ========================================================================
// ?InitMoverModifiers@idSplinePathMM@@AAAXXZ
// EA  : 0x82C94978
// RVA : 0x00C94978
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __fastcall idSplinePathMM::InitMoverModifiers(
        idSplinePathMM *this,
        int a2,
        int a3,
        int a4,
        __int64 a5,
        __int64 a6)
{
  idList<splineMoverModifier_t,5> *p_moverModifiers; // r22
  int v8; // r24
  int v9; // r25
  idEntity *v10; // r3
  int value; // r9
  idEntity *v12; // r3
  idMoverModifier *v13; // r3
  idMoverModifier *v14; // r3
  idMoverModifier *v15; // r30
  idAngles *v16; // r3
  int v17; // r11
  int v18; // r28
  int v19; // r29
  int v20; // r9
  idEntity *v21; // r3
  int v22; // r9
  idEntity *v23; // r3
  idEntity *v24; // r3
  idPhysics *Physics; // r3
  float *v26; // r3
  idPhysics *v27; // r3
  float *v28; // r3
  int v29; // r9
  idEntity *v30; // r3
  idInfoSplineChild *v31; // r3
  idInfoSplineChild *v32; // r3
  idList<idEntityPtr<idEntity>,58> *p_splineChildEntities; // r3
  int v34; // r11
  int v35; // r9
  idEntity *v36; // r3
  idEntity *v37; // r3
  splineMoverModifier_t *list; // r4
  unsigned int num; // r5
  __int64 v40; // r10
  idEntityPtr<idEntity> *v41; // r4
  unsigned int v42; // r5
  int v43; // r29
  int v44; // r28
  int v45; // r30
  idCurve_Spline<idVec3> *v46; // r3
  idCurve_Spline<idVec3> *v47; // r30
  int v48; // r11
  double v49; // fp1
  int v50; // r6
  int v51; // r9
  int v52; // r11
  double length; // fp0
  int v54; // r29
  int v55; // r30
  splineMoverModifier_t *v56; // r11
  const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *p_animationToPlay; // r5
  const idDeclMD6 *declToPlayAnimOn; // r4
  idEntityPtr<idEntity> *v59; // r4
  idEntityPtr<idEntity> v60; // [sp+50h] [-310h] BYREF
  idSort_Quick<idEntityPtr<idEntity>,idSort_SplineLoc> v61; // [sp+54h] [-30Ch] BYREF
  idSort_Quick<splineMoverModifier_t,idSort_MoverModifier> v62; // [sp+58h] [-308h] BYREF
  idMat3 v63; // [sp+60h] [-300h] BYREF
  float v64; // [sp+84h] [-2DCh]
  float v65; // [sp+88h] [-2D8h]
  float v66; // [sp+8Ch] [-2D4h]
  float v67; // [sp+90h] [-2D0h]
  float v68; // [sp+94h] [-2CCh]
  float v69; // [sp+98h] [-2C8h]
  float v70; // [sp+9Ch] [-2C4h]
  float v71; // [sp+A0h] [-2C0h]
  splineMoverModifier_t::splineMoverModifierAiProps_t v72[2]; // [sp+23Ch] [-124h] BYREF

  p_moverModifiers = &this->moverModifiers;
  if ( this->moverModifiers.listStatic == 0 || this->moverModifiers.listStatic == 2 )
  {
    if ( p_moverModifiers->list != nullptr )
      idListArrayDelete<splineMoverModifier_t>(ptr: this->moverModifiers.list, num: this->moverModifiers.size);
    p_moverModifiers->list = nullptr;
    p_moverModifiers->size = 0;
  }
  p_moverModifiers->num = 0;
  v8 = 0;
  if ( this->moverModifierEntities.num > 0 )
  {
    v9 = 0;
    do
    {
      LODWORD(a6) = gameLocal;
      HIDWORD(a6) = this->moverModifierEntities.list[v9].spawnId.value;
      LODWORD(a5) = SHIDWORD(a6) >> 13;
      HIDWORD(a5) = (WORD1(a6) & 0x1FFF) + 29755;
      a4 = 4 * HIDWORD(a5);
      if ( *((_DWORD *)&gameLocal->__vftable + HIDWORD(a5)) == SHIDWORD(a6) >> 13 )
      {
        HIDWORD(a6) = 4 * ((WORD1(a6) & 0x1FFF) + 21563);
        v10 = *(idEntity **)((char *)&gameLocal->__vftable + HIDWORD(a6));
        if ( v10 != nullptr && idEntity::CastTo(c: v10) != nullptr )
        {
          value = this->moverModifierEntities.list[v9].spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v12 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v13 = (idMoverModifier *)idEntity::CastTo(c: v12);
          }
          else
          {
            v13 = nullptr;
          }
          v14 = idMoverModifier::CastTo(c: v13);
          v15 = v14;
          if ( v14 != nullptr )
          {
            if ( v14->modifier.Orientation.setNewOrientation )
            {
              v16 = idMat3::ToAngles(this: &v63, result: (idAngles *)&v14->spawnOrientation);
              v15->modifier.Orientation.newOrientation.pitch = v16->pitch;
              v15->modifier.Orientation.newOrientation.yaw = v16->yaw;
              v60.spawnId.value = (int)&v15->modifier.Orientation.newOrientation;
              v15->modifier.Orientation.newOrientation.roll = v16->roll;
            }
            v18 = 0;
            v60.spawnId.value = v15->targets.num;
            v17 = v60.spawnId.value;
            if ( v60.spawnId.value > 0 )
            {
              v19 = 0;
              do
              {
                v60.spawnId.value = v17;
                if ( v18 < v17 )
                {
                  v20 = v15->targets.list[v19].spawnId.value;
                  if ( gameLocal->spawnIds.ptr[v20 & 0x1FFF] == v20 >> 13 )
                  {
                    v21 = gameLocal->entities.ptr[v20 & 0x1FFF];
                    if ( v21 != nullptr && idEntity::CastTo(c: v21) != nullptr )
                    {
                      if ( v18 < v15->targets.num
                        && (v22 = v15->targets.list[v19].spawnId.value,
                            gameLocal->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13)
                        && (v23 = gameLocal->entities.ptr[v22 & 0x1FFF]) != nullptr
                        && (v24 = idEntity::CastTo(c: v23)) != nullptr )
                      {
                        v60.spawnId.value = v24->entityNumber;
                        v60.spawnId.value |= gameLocal->spawnIds.ptr[v60.spawnId.value] << 13;
                      }
                      else
                      {
                        v60.spawnId.value = 0x1FFF;
                      }
                      idList<idEntityPtr<idEntity>,58>::Append(
                        this: (idList<idEntityPtr<idEntity>,58> *)&v15->modifier.Targets,
                        obj: &v60);
                    }
                  }
                }
                ++v18;
                ++v19;
                v60.spawnId.value = v15->targets.num;
                v17 = v60.spawnId.value;
              }
              while ( v18 < v60.spawnId.value );
            }
            splineMoverModifier_t::splineMoverModifier_t(
              this: (splineMoverModifier_t *)&v63.mat[1].y,
              __that: &v15->modifier);
            Physics = idEntity::GetPhysics(this: v15);
            v26 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
            v63.mat[1].z = *v26;
            v63.mat[2].x = v26[1];
            v63.mat[2].y = v26[2];
            v27 = idEntity::GetPhysics(this: v15);
            v28 = (float *)v27->GetAxis(this: v27, a2: 0);
            v60.spawnId.value = (int)(v28 + 6);
            v63.mat[2].z = *v28;
            v64 = v28[1];
            v65 = v28[2];
            v66 = v28[3];
            v67 = v28[4];
            v68 = v28[5];
            v69 = v28[6];
            v70 = v28[7];
            v71 = v28[8];
            splineMoverModifier_t::splineMoverModifierAiProps_t::Spawn(
              this: v72,
              modifier: (const splineMoverModifier_t *)&v63.mat[1].y);
            idList<splineMoverModifier_t,5>::Append(
              this: p_moverModifiers,
              obj: (const splineMoverModifier_t *)&v63.mat[1].y);
            v15->Remove(this: v15);
            splineMoverModifier_t::~splineMoverModifier_t(this: (splineMoverModifier_t *)&v63.mat[1].y);
          }
          else
          {
            v29 = this->moverModifierEntities.list[v9].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v29 & 0x1FFF] == v29 >> 13
              && (v30 = gameLocal->entities.ptr[v29 & 0x1FFF]) != nullptr )
            {
              v31 = (idInfoSplineChild *)idEntity::CastTo(c: v30);
            }
            else
            {
              v31 = nullptr;
            }
            v32 = idInfoSplineChild::CastTo(c: v31);
            if ( v32 != nullptr )
            {
              HIDWORD(a5) = this->splineChildEntities.num;
              LODWORD(a5) = 0;
              v60.spawnId.value = v32->entityNumber;
              p_splineChildEntities = (idList<idEntityPtr<idEntity>,58> *)&this->splineChildEntities;
              LODWORD(a6) = (gameLocal->spawnIds.ptr[v60.spawnId.value] << 13) | v60.spawnId.value;
              v60.spawnId.value = a6;
              if ( SHIDWORD(a5) <= 0 )
                goto LABEL_42;
              HIDWORD(a6) = p_splineChildEntities->list;
              v34 = 0;
              while ( 1 )
              {
                a4 = *(_DWORD *)(v34 + HIDWORD(a6));
                if ( a4 == (_DWORD)a6 )
                  break;
                LODWORD(a5) = a5 + 1;
                v34 += 4;
                if ( (int)a5 >= SHIDWORD(a5) )
                  goto LABEL_42;
              }
              if ( (int)a5 < 0 )
LABEL_42:
                idList<idEntityPtr<idEntity>,58>::Append(this: p_splineChildEntities, obj: &v60);
            }
            else
            {
              v35 = this->moverModifierEntities.list[v9].spawnId.value;
              if ( gameLocal->spawnIds.ptr[v35 & 0x1FFF] == v35 >> 13
                && (v36 = gameLocal->entities.ptr[v35 & 0x1FFF]) != nullptr )
              {
                v37 = idEntity::CastTo(c: v36);
              }
              else
              {
                v37 = nullptr;
              }
              v37->Remove(this: v37);
            }
          }
        }
      }
      ++v8;
      ++v9;
    }
    while ( v8 < this->moverModifierEntities.num );
  }
  v62.__vftable = (idSort_Quick<splineMoverModifier_t,idSort_MoverModifier>_vtbl *)&idSort_MoverModifier::`vftable';
  list = p_moverModifiers->list;
  if ( p_moverModifiers->list != nullptr )
  {
    num = p_moverModifiers->num;
    v60.spawnId.value = (int)p_moverModifiers->list;
    idSort_Quick<splineMoverModifier_t,idSort_MoverModifier>::Sort(this: &v62, base: list, num, a4, a5, a6);
  }
  LODWORD(v40) = off_822F0000;
  HIDWORD(v40) = &idSort<splineMoverModifier_t>::`vftable';
  v62.__vftable = (idSort_Quick<splineMoverModifier_t,idSort_MoverModifier>_vtbl *)&idSort<splineMoverModifier_t>::`vftable';
  v61.__vftable = (idSort_Quick<idEntityPtr<idEntity>,idSort_SplineLoc>_vtbl *)&idSort_SplineLoc::`vftable';
  v41 = this->splineChildEntities.list;
  if ( v41 != nullptr )
  {
    v42 = this->splineChildEntities.num;
    v60.spawnId.value = (int)this->splineChildEntities.list;
    idSort_Quick<idEntityPtr<idEntity>,idSort_SplineLoc>::Sort(
      this: &v61,
      base: v41,
      num: v42,
      a4,
      a5: SHIDWORD(a5),
      a6: a5,
      a7: v40);
  }
  v43 = this->moverModifiers.num - 2;
  v61.__vftable = (idSort_Quick<idEntityPtr<idEntity>,idSort_SplineLoc>_vtbl *)&idSort<idEntityPtr<idEntity>>::`vftable';
  if ( v43 >= 0 )
  {
    v44 = v43 + 1;
    v45 = v43;
    do
    {
      if ( p_moverModifiers->list[v45].length == p_moverModifiers->list[v45 + 1].length )
        idList<splineMoverModifier_t,5>::RemoveIndex(this: p_moverModifiers, index: v44);
      --v43;
      --v45;
      --v44;
    }
    while ( v43 >= 0 );
  }
  v46 = idSplinePathMM::AllocSpline(this);
  v47 = v46;
  this->cachedSplineLength = 0.0;
  v48 = v46->values.num;
  if ( v48 > 1 )
  {
    v49 = ((double (__fastcall *)(idCurve_Spline<idVec3> *, double))v46->GetLengthForTime)(
            a1: v46,
            a2: v46->times.list[v48 - 1]);
    v50 = this->moverModifiers.num;
    this->cachedSplineLength = v49;
    v51 = 0;
    if ( v50 > 0 )
    {
      v52 = 0;
      do
      {
        length = p_moverModifiers->list[v52].length;
        if ( length >= 0.0 )
        {
          if ( length > this->cachedSplineLength )
            length = this->cachedSplineLength;
        }
        else
        {
          length = 0.0;
        }
        p_moverModifiers->list[v52].length = length;
        ++v51;
        ++v52;
      }
      while ( v51 < this->moverModifiers.num );
    }
  }
  ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))v47->dtr_idCurve<idVec3>)(a1: v47, a2: 1);
  v54 = 0;
  if ( this->moverModifiers.num > 0 )
  {
    v55 = 0;
    do
    {
      v56 = &p_moverModifiers->list[v55];
      p_animationToPlay = &v56->Animation.animationToPlay;
      if ( v56->Animation.animationToPlay.value != 0xFFFF )
      {
        declToPlayAnimOn = v56->Animation.declToPlayAnimOn;
        if ( declToPlayAnimOn != nullptr )
          animation->StrongLoadAlias_2(this: animation, a2: declToPlayAnimOn, a3: p_animationToPlay);
        else
          idLib::Warning(
            fmt: "MoverModifier has animationToPlay specified but no decl to play it on!",
            0,
            p_animationToPlay);
      }
      ++v54;
      ++v55;
    }
    while ( v54 < this->moverModifiers.num );
  }
  if ( this->moverModifierEntities.listStatic == 0 || this->moverModifierEntities.listStatic == 2 )
  {
    v59 = this->moverModifierEntities.list;
    if ( v59 != nullptr )
    {
      v60.spawnId.value = (int)this->moverModifierEntities.list;
      idMem::Free(this: &mem, ptr: v59, align: ALIGN_16);
    }
    this->moverModifierEntities.list = nullptr;
    this->moverModifierEntities.size = 0;
  }
  this->moverModifierEntities.num = 0;
}


// ========================================================================
// __unwind$526634
// EA  : 0x82C95044
// RVA : 0x00C95044
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_526634()
{
  int v0; // r12

  splineMoverModifier_t::~splineMoverModifier_t(this: (splineMoverModifier_t *)(v0 - 864 + 112));
}


// ========================================================================
// __unwind$526635
// EA  : 0x82C9506C
// RVA : 0x00C9506C
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_526635()
{
  int v0; // r12

  idSort_MoverModifier::~idSort_MoverModifier(this: (idSort_MoverModifier *)(v0 - 864 + 88));
}


// ========================================================================
// __unwind$526636
// EA  : 0x82C95094
// RVA : 0x00C95094
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void _unwind_526636()
{
  int v0; // r12

  idSort_SplineLoc::~idSort_SplineLoc(this: (idSort_SplineLoc *)(v0 - 864 + 84));
}


// ========================================================================
// ?Event_PostSpawn@idSplinePathMM@@QAA?AVeventVoid@@XZ
// EA  : 0x82C950C0
// RVA : 0x00C950C0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

idSplinePathMM *__fastcall idSplinePathMM::Event_PostSpawn(
        idSplinePathMM *this,
        idSplinePathMM *result,
        int a3,
        int a4,
        __int64 a5,
        __int64 a6)
{
  idSplinePathMM::InitMoverModifiers(this: result, a2: (int)result, a3, a4, a5, a6);
  return this;
}


// ========================================================================
// `dynamic initializer for 'g_spline_debug''
// EA  : 0x83377C88
// RVA : 0x01377C88
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_spline_debug__()
{
  idCVar::idCVar(
    this: &g_spline_debug,
    name: "g_spline_debug",
    value: "0",
    flags: 2,
    description: "Debug draw spline paths",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_spline_debug__);
}


// ========================================================================
// `dynamic initializer for 'g_debugMoverModifiers''
// EA  : 0x83377CE0
// RVA : 0x01377CE0
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugMoverModifiers__()
{
  idCVar::idCVar(
    this: &g_debugMoverModifiers,
    name: "g_debugMoverModifiers",
    value: "0",
    flags: 1,
    description: "if true, will print debug information on mover modifiers",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugMoverModifiers__);
}


// ========================================================================
// `dynamic initializer for 'g_debugMoverSpeedSoundBindings''
// EA  : 0x83377D38
// RVA : 0x01377D38
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugMoverSpeedSoundBindings__()
{
  idCVar::idCVar(
    this: &g_debugMoverSpeedSoundBindings,
    name: "g_debugMoverSpeedSoundBindings",
    value: "0",
    flags: 1,
    description: "if true, will print debug information on mover modifiers",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugMoverSpeedSoundBindings__);
}


// ========================================================================
// `dynamic initializer for 'g_debugMoverMods''
// EA  : 0x83377D90
// RVA : 0x01377D90
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugMoverMods__()
{
  idCVar::idCVar(
    this: &g_debugMoverMods,
    name: "g_debugMoverMods",
    value: "0",
    flags: 0,
    description: "show information about specified mover modifier.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugMoverMods__);
}


// ========================================================================
// `dynamic initializer for 'g_showMoverMods''
// EA  : 0x83377DE8
// RVA : 0x01377DE8
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showMoverMods__()
{
  idCVar::idCVar(
    this: &g_showMoverMods,
    name: "g_showMoverMods",
    value: "0",
    flags: 0,
    description: "show information about specified mover modifier.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showMoverMods__);
}


// ========================================================================
// `dynamic initializer for 'g_debugShowMoverAttachmentAxis''
// EA  : 0x83377E40
// RVA : 0x01377E40
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugShowMoverAttachmentAxis__()
{
  idCVar::idCVar(
    this: &g_debugShowMoverAttachmentAxis,
    name: "g_debugShowMoverAttachmentAxis",
    value: "0",
    flags: 1,
    description: "show axis for the mover entities",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugShowMoverAttachmentAxis__);
}


// ========================================================================
// `dynamic initializer for 'g_showSwarmSplines''
// EA  : 0x83377E98
// RVA : 0x01377E98
// PDB : w:\tech5\tungsten\game\entities\mover.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showSwarmSplines__()
{
  idCVar::idCVar(
    this: &g_showSwarmSplines,
    name: "g_showSwarmSplines",
    value: "0",
    flags: 1,
    description: "show the splines of swarm mover",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showSwarmSplines__);
}

