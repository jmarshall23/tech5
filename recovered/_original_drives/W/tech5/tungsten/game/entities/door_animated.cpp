
// ========================================================================
// ?SetLocked@idDoor_Animated@@UAAX_NPAVidEntity@@@Z
// EA  : 0x82C20630
// RVA : 0x00C20630
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void __fastcall idDoor_Animated::SetLocked(idDoor_Animated *this, bool lock, idEntity *user)
{
  if ( this->locked != lock )
  {
    this->locked = lock;
    if ( !lock )
    {
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY,
        shader: this->unlock_sound,
        soundShaderFlags: 0,
        peerMask: 0xFFu);
      if ( this->IsClosed(this) && this->opensWhenUnlocked )
        this->Use(this, a2: user, a3: USABLE_DOOR);
    }
    this->UpdateAASAreas(this);
  }
}


// ========================================================================
// ?IsOpen@idDoor_Animated@@UBA_NXZ
// EA  : 0x82C206F0
// RVA : 0x00C206F0
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

BOOL __fastcall idDoor_Animated::IsOpen(idDoor_Animated *this)
{
  return (_cntlzw(this->state - 4) & 0x20) != 0;
}


// ========================================================================
// ?IsClosed@idDoor_Animated@@UBA_NXZ
// EA  : 0x82C20708
// RVA : 0x00C20708
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

BOOL __fastcall idDoor_Animated::IsClosed(idDoor_Animated *this)
{
  return (_cntlzw(this->state - 2) & 0x20) != 0;
}


// ========================================================================
// ?GetUsableState@idDoor_Animated@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82C20720
// RVA : 0x00C20720
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

int __fastcall idDoor_Animated::GetUsableState(idDoor_Animated *this)
{
  int numMaxOpens; // r11

  if ( this->playing )
    return 0;
  if ( this->IsOpen(this) && this->playerUsable && this->playerCanClose )
    return this->closeAnimHandle.value == 65535 ? 0 : 7;
  if ( this->IsClosed(this)
    && this->playerUsable
    && ((numMaxOpens = this->numMaxOpens) == -1 || this->openCount < numMaxOpens) )
  {
    return this->openAnimHandle.value == 65535 ? 0 : 7;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?GetJointIndexFromTrace@idDoor_Animated@@UAA?AV?$idIndex@FW4invalidJointIndex_t@@@@Utrace_t@@@Z
// EA  : 0x82C20830
// RVA : 0x00C20830
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

idDoor_Animated *__fastcall idDoor_Animated::GetJointIndexFromTrace(
        idDoor_Animated *this,
        idIndex<short,enum invalidJointIndex_t> *result,
        trace_t *trace,
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
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43)
{
  int v43; // r7
  int v44; // r10
  int v45; // r8
  int v46; // r11
  int v47; // r9
  int v48; // r9

  v43 = *(_DWORD *)&result[2770].value;
  v44 = 0;
  if ( v43 <= 0 )
  {
LABEL_6:
    HIWORD(this->__vftable) = NULL_JOINT_INDEX;
  }
  else
  {
    v45 = *(_DWORD *)&result[2768].value;
    v46 = 0;
    v47 = v45;
    while ( 1 )
    {
      v48 = *(_DWORD *)(v47 + 40);
      if ( v48 != 0 && a43 == *(_DWORD *)(v48 + 1212) )
        break;
      ++v44;
      v46 += 44;
      v47 = v46 + v45;
      if ( v44 >= v43 )
        goto LABEL_6;
    }
    HIWORD(this->__vftable) = *(_WORD *)(44 * v44 + v45 + 38);
  }
  return this;
}


// ========================================================================
// ?Use@idDoor_Animated@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C208B8
// RVA : 0x00C208B8
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

int __fastcall idDoor_Animated::Use(idDoor_Animated *this, idDoor_Animated *user, const usableState_t usable)
{
  idPresentable *presentable; // r3
  idDoor_Animated_vtbl *v6; // r10
  unsigned __int16 value; // r11
  idPhysics *Physics; // r27
  int GameMs; // r26
  idPhysics *v10; // r3
  idAIEventManager *p_aiEventManager; // r27
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v13; // r3
  int v14; // r30
  const idAnimStack *v15; // r3
  const blendParms_t *v16; // r7
  idDoor_Animated_vtbl *v17; // r8
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v19; // [sp+50h] [-60h] BYREF
  idAIEventManager v20; // [sp+54h] [-5Ch] BYREF

  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) == nullptr )
    return 0;
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( this->playing )
    return 0;
  if ( this->IsLockedForEntity(this, a2: user, a3: 0.0)
    || this->IsOpen(this) && (unsigned __int8)idActor::IsTypeOf(c: user) != 0 && !this->playerCanClose )
  {
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_BODY,
      shader: this->locked_sound,
      soundShaderFlags: 0,
      peerMask: 0xFFu);
    return 0;
  }
  v6 = this->__vftable;
  v19.value = -1;
  if ( v6->IsClosed(this) )
  {
    value = this->openAnimHandle.value;
  }
  else
  {
    if ( !this->IsOpen(this) )
      goto LABEL_14;
    value = this->closeAnimHandle.value;
  }
  v19.value = value;
LABEL_14:
  Physics = idEntity::GetPhysics(this);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v10 = Physics;
  GetOrigin = Physics->GetOrigin;
  p_aiEventManager = &gameLocal->aiEventManager;
  v13 = GetOrigin(this: v10, a2: 0);
  idAIEventManager::AddEvent(
    this: &v20,
    result: p_aiEventManager,
    eventDecl: this->motionEventDecl,
    curTime: GameMs,
    originator: this,
    instigator: user,
    origin: v13,
    delay: 1000);
  if ( v19.value == 0xFFFF )
    return 0;
  blendParms_t::blendParms_t(this: (blendParms_t *)&v20.eventList.granularity);
  v14 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v15 = this->GetAnimStack_2(this);
  idAnimator_Channel::PlayAnim(
    this: &this->doorAnimator,
    stack: v15,
    ah: &v19,
    curTime: v14,
    rateScale: 1.0,
    blendParms: v16,
    blendOutDurationMS_: (blendParms_t *)&v20.eventList.granularity,
    leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
    a9: nullptr);
  idEntity::BecomeActive(this, flags: 4);
  idEntity::BecomeActive(this, flags: 1);
  v17 = this->__vftable;
  this->playing = true;
  if ( v17->IsOpen(this) )
  {
    idDoor_Base::SetDoorState(this, activator: user, s: DOOR_CLOSING);
    return 1;
  }
  else
  {
    idDoor_Base::SetDoorState(this, activator: user, s: DOOR_OPENING);
    if ( user != this )
      ++this->openCount;
    if ( this->triggerTargetsOnOpen )
      this->ActivateTargets(this, a2: user);
    if ( this->forceUnusableWhenOpened )
      this->forcedUnusable = true;
    return 1;
  }
}


// ========================================================================
// ?Hide@idDoor_Animated@@UAAXXZ
// EA  : 0x82C20B80
// RVA : 0x00C20B80
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void __fastcall idDoor_Animated::Hide(idDoor_Animated *this)
{
  int v2; // r29
  int v3; // r31
  idPresentableDoorAnimated *presentable; // r3
  idPhysics *Physics; // r3

  idEntity::Hide(this);
  idEntity::BecomeInactive(this, flags: 7);
  v2 = 0;
  if ( this->collisionParts.num > 0 )
  {
    v3 = 0;
    do
    {
      presentable = this->collisionParts.list[v3].presentable;
      presentable->Hide(this: presentable, a2: true);
      idPresentableDoorAnimated::UnlinkCollision(this: (idPresentableAnimatedPhysics *)this->collisionParts.list[v3].presentable);
      ++v2;
      ++v3;
    }
    while ( v2 < this->collisionParts.num );
  }
  Physics = idEntity::GetPhysics(this);
  Physics->UnlinkClip(this: Physics);
}


// ========================================================================
// ?Show@idDoor_Animated@@UAAXXZ
// EA  : 0x82C20C18
// RVA : 0x00C20C18
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void __fastcall idDoor_Animated::Show(idDoor_Animated *this)
{
  int v2; // r29
  int v3; // r31
  idPresentableDoorAnimated *presentable; // r3
  idPhysics *Physics; // r3

  idEntity::Show(this);
  idEntity::BecomeActive(this, flags: 4);
  v2 = 0;
  if ( this->collisionParts.num > 0 )
  {
    v3 = 0;
    do
    {
      presentable = this->collisionParts.list[v3].presentable;
      presentable->Show(this: presentable);
      idPresentableAnimatedPhysics::LinkCollision(this: (idPresentableAnimatedPhysics *)this->collisionParts.list[v3].presentable);
      ++v2;
      ++v3;
    }
    while ( v2 < this->collisionParts.num );
  }
  Physics = idEntity::GetPhysics(this);
  Physics->LinkClip(this: Physics);
}


// ========================================================================
// ?UpdateCollisionParts@idDoor_Animated@@AAAXAAVidBounds@@_N@Z
// EA  : 0x82C20D28
// RVA : 0x00C20D28
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void __fastcall idDoor_Animated::UpdateCollisionParts(idDoor_Animated *this, idBounds *bounds, bool push)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r20
  idPresentable *presentable; // r3
  int v8; // r25
  int v9; // r24
  idDoor_AnimatedPiece *v10; // r11
  idPresentableDoorAnimated *v11; // r31
  int value; // r28
  double v13; // fp1
  float *v14; // r3
  double v16; // fp1
  double v17; // fp0
  double v18; // fp13
  double v19; // fp12
  double v20; // fp9
  const char *EntityDefName; // r3
  float *v33; // r10
  idPresentable *v34; // r11
  float *v35; // r3
  double y; // fp10
  double z; // fp9
  double x; // fp8
  double v40; // fp7
  double v41; // fp4
  idVec3 v53; // [sp+50h] [-130h] BYREF
  idMat3 v54; // [sp+60h] [-120h] BYREF
  trace_t v55; // [sp+90h] [-F0h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    v8 = 0;
    bounds->b[0].z = 1.0e30;
    bounds->b[0].y = 1.0e30;
    bounds->b[0].x = 1.0e30;
    bounds->b[1].z = -1.0e30;
    bounds->b[1].y = -1.0e30;
    bounds->b[1].x = -1.0e30;
    if ( this->collisionParts.num > 0 )
    {
      v9 = 0;
      do
      {
        v10 = &this->collisionParts.list[v9];
        v11 = v10->presentable;
        if ( v11 != nullptr )
        {
          value = v10->jointIndex.value;
          if ( value < 0 )
          {
            EntityDefName = idEntity::GetEntityDefName(this);
            idLib::Warning(
              fmt: "idDoor_Animated::UpdateCollisionParts piece %d of entity %s at invalid joint %d",
              v8,
              EntityDefName,
              value);
            v33 = (float *)this->presentable;
            if ( v33 == nullptr )
            {
              idEntity::InitPresentableInternal(this);
              v33 = (float *)this->presentable;
            }
            v11->axis.mat[0].x = v33[33];
            v11->axis.mat[0].y = v33[34];
            v11->axis.mat[0].z = v33[35];
            v11->axis.mat[1].x = v33[36];
            v11->axis.mat[1].y = v33[37];
            v11->axis.mat[1].z = v33[38];
            v11->axis.mat[2].x = v33[39];
            v11->axis.mat[2].y = v33[40];
            v11->axis.mat[2].z = v33[41];
            v34 = this->presentable;
            if ( v34 == nullptr )
            {
              idEntity::InitPresentableInternal(this);
              v34 = this->presentable;
            }
            v11->origin.x = v34->origin.x;
            v11->origin.y = v34->origin.y;
            v11->origin.z = v34->origin.z;
            v11->Present(this: v11);
            v35 = (float *)v11->physicsObj.GetAbsBounds(this: &v11->physicsObj, a2: -1);
            _FP5 = (float)(bounds->b[0].x - *v35);
            y = bounds->b[0].y;
            z = bounds->b[0].z;
            x = bounds->b[1].x;
            v40 = bounds->b[1].y;
            v41 = bounds->b[1].z;
            __asm { fsel      f3, f5, f6, f11 }
            bounds->b[0].x = _FP3;
            _FP1 = (float)((float)y - v35[1]);
            __asm { fsel      f0, f1, f2, f10 }
            bounds->b[0].y = _FP0;
            _FP12 = (float)((float)z - v35[2]);
            __asm { fsel      f11, f12, f13, f9 }
            bounds->b[0].z = _FP11;
            _FP9 = (float)(v35[3] - (float)x);
            __asm { fsel      f8, f9, f10, f8 }
            bounds->b[1].x = _FP8;
            _FP5 = (float)(v35[4] - (float)v40);
            __asm { fsel      f3, f5, f6, f7 }
            bounds->b[1].y = _FP3;
            _FP1 = (float)(v35[5] - (float)v41);
            __asm { fsel      f0, f1, f2, f4 }
            bounds->b[1].z = _FP0;
          }
          else if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceAttachmentTransform(
                                       this: TreeAnimatorFromPresentable,
                                       jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v10->jointIndex.value,
                                       translationOffset: &vec3_origin,
                                       rotationOffset: (idMat3 *)&quat_identity,
                                       origin: &v53,
                                       axis: &v54) != 0 )
          {
            if ( push )
            {
              idPush::InitSavingPushedPhysicsObjectState(this: &clientGame->push);
              v13 = idPush::ClipPush(
                      this: &clientGame->push,
                      results: &v55,
                      pusher: &v11->physicsObj,
                      flags: this->pushFlags,
                      oldOrigin: &v11->origin,
                      oldAxis: &v11->axis,
                      newOrigin: &v53,
                      newAxis: &v54);
            }
            v11->axis = v54;
            v11->origin = v53;
            ((void (__fastcall *)(idPresentableDoorAnimated *, double))v11->Present)(a1: v11, a2: v13);
            v14 = (float *)v11->physicsObj.GetAbsBounds(this: &v11->physicsObj, a2: -1);
            _FP10 = (float)(bounds->b[0].x - *v14);
            v16 = bounds->b[0].y;
            v17 = bounds->b[0].z;
            v18 = bounds->b[1].x;
            v19 = bounds->b[1].y;
            v20 = bounds->b[1].z;
            __asm { fsel      f8, f10, f11, f2 }
            bounds->b[0].x = _FP8;
            _FP6 = (float)((float)v16 - v14[1]);
            __asm { fsel      f5, f6, f7, f1 }
            bounds->b[0].y = _FP5;
            _FP3 = (float)((float)v17 - v14[2]);
            __asm { fsel      f2, f3, f4, f0 }
            bounds->b[0].z = _FP2;
            _FP0 = (float)(v14[3] - (float)v18);
            __asm { fsel      f13, f0, f1, f13 }
            bounds->b[1].x = _FP13;
            _FP10 = (float)(v14[4] - (float)v19);
            __asm { fsel      f8, f10, f11, f12 }
            bounds->b[1].y = _FP8;
            _FP6 = (float)(v14[5] - (float)v20);
            __asm { fsel      f5, f6, f7, f9 }
            bounds->b[1].z = _FP5;
          }
        }
        ++v8;
        ++v9;
      }
      while ( v8 < this->collisionParts.num );
    }
  }
}


// ========================================================================
// ?CanClose@idDoor_Animated@@EBA_N_N@Z
// EA  : 0x82C210E0
// RVA : 0x00C210E0
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

int __fastcall idDoor_Animated::CanClose(idDoor_Animated *this, bool testingForUse)
{
  unsigned __int64 index; // r11
  idGatherQuery *p_canCloseQuery; // r31
  char v5; // r11
  bool v6; // zf
  int GatheredEntities; // r29
  int v8; // r30
  int *i; // r31
  idPhysics *Physics; // r3
  const idBounds *v12; // r3
  char v13; // [sp+50h] [-A0h] BYREF
  idBounds v14; // [sp+60h] [-90h] BYREF
  int v15[28]; // [sp+80h] [-70h] BYREF

  if ( !this->testForActorsWhenClosing )
    return 1;
  index = this->canCloseQuery.index;
  p_canCloseQuery = &this->canCloseQuery;
  if ( (unsigned int)index < LODWORD(clientGame->clip.gatherQueryFirstSubmittedIndex)
    || (v6 = (unsigned int)index <= LODWORD(clientGame->clip.gatherQueryLastSubmittedIndex), v5 = 1, !v6) )
  {
    v5 = 0;
  }
  if ( v5 != 0 )
  {
    GatheredEntities = idClip::GetGatheredEntities(
                         this: &clientGame->clip,
                         query: p_canCloseQuery,
                         entityList: v15,
                         maxCount: 16);
    v8 = 0;
    if ( GatheredEntities > 0 )
    {
      for ( i = v15; (unsigned __int8)idActor::IsTypeOf(c: gameLocal->entities.ptr[*i]) == 0; ++i )
      {
        if ( ++v8 >= GatheredEntities )
          return 1;
      }
      return 0;
    }
    return 1;
  }
  Physics = idEntity::GetPhysics(this);
  v12 = Physics->GetAbsBounds(this: Physics, a2: -1);
  idBounds::operator+(this: &v14, result: &this->bounds, a: v12);
  v14.b[0].x = v14.b[0].x - g_doorClosingRange.valueFloat;
  v14.b[0].y = v14.b[0].y - g_doorClosingRange.valueFloat;
  v14.b[0].z = v14.b[0].z - g_doorClosingRange.valueFloat;
  v14.b[1].x = g_doorClosingRange.valueFloat + v14.b[1].x;
  v14.b[1].y = g_doorClosingRange.valueFloat + v14.b[1].y;
  v14.b[1].z = g_doorClosingRange.valueFloat + v14.b[1].z;
  p_canCloseQuery->index = *(unsigned __int64 *)&idClip::GatherTouchingBounds(
                                                   this: (idClip *)&v13,
                                                   result: (idGatherQuery *)&clientGame->clip,
                                                   bounds: &v14,
                                                   clipMask: 33792,
                                                   passEntityNumber: -1,
                                                   userName: "w:\\tech5\\tungsten\\game\\entities\\Door_Animated.cpp(468) : Touching Bounds")->world;
  return 0;
}


// ========================================================================
// ?Think@idDoor_Animated@@UAAXXZ
// EA  : 0x82C21278
// RVA : 0x00C21278
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void __fastcall idDoor_Animated::Think(idDoor_Animated *this)
{
  idPresentable *presentable; // r3
  int GameMs; // r29
  const idAnimStack *v4; // r3
  idDoor_Base::doorState_t state; // r11
  idDoor_Base::doorState_t v6; // r11
  idBounds v7[2]; // [sp+50h] [-40h] BYREF

  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    idAnimatedEntity::UpdateFrameCommands(this);
    if ( this->playing )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v4 = this->GetAnimStack_2(this);
      if ( idAnimator_Channel::IsDone(this: &this->doorAnimator, stack: v4, curTime: GameMs) )
      {
        state = this->state;
        this->playing = false;
        if ( state == DOOR_CLOSING )
        {
          idDoor_Base::SetDoorState(this, activator: this, s: DOOR_CLOSED);
        }
        else if ( state == DOOR_OPENING )
        {
          idDoor_Base::SetDoorState(this, activator: this, s: DOOR_OPENED);
          if ( this->msUntilClose >= 0 )
            this->autoCloseTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + this->msUntilClose;
        }
      }
    }
    if ( this->msUntilClose >= 0
      && this->state == DOOR_OPENED
      && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) >= this->autoCloseTime )
    {
      this->Use(this, a2: this, a3: USABLE_DOOR);
    }
    idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
    this->UpdateFX(this);
    idDoor_Animated::UpdateCollisionParts(this, bounds: v7, push: true);
    idDoor_Base::UpdateState(this);
    v6 = this->state;
    if ( v6 == DOOR_CLOSED || v6 == DOOR_BROKEN || this->msUntilClose < 0 && v6 == DOOR_OPENED )
      idEntity::BecomeInactive(this, flags: 7);
  }
}


// ========================================================================
// ?Spawn@idDoor_Animated@@QAAXXZ
// EA  : 0x82C21458
// RVA : 0x00C21458
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void __fastcall idDoor_Animated::Spawn(idDoor_Animated *this)
{
  idGameTimeManager *v2; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r24
  int v4; // r27
  int v5; // r29
  idPresentableDoorAnimated *v6; // r3
  idPresentableDoorAnimated *v7; // r3
  idDoor_AnimatedPiece *v8; // r28
  const char *Classname; // r3
  int presentable; // r9
  int v11; // r10
  int v12; // r7
  double y; // fp13
  double z; // fp12
  double x; // fp11
  double v16; // fp10
  double v17; // fp9
  char *data; // r5
  int v19; // [sp+8h] [-118h]
  int v20; // [sp+Ch] [-114h]
  int v21; // [sp+10h] [-110h]
  int v22; // [sp+14h] [-10Ch]
  int v23; // [sp+18h] [-108h]
  idPresentable *v24; // [sp+1Ch] [-104h]
  unsigned __int16 v25; // [sp+50h] [-D0h] BYREF
  unsigned __int16 v26; // [sp+52h] [-CEh] BYREF
  unsigned __int16 v27; // [sp+54h] [-CCh] BYREF
  unsigned __int16 v28; // [sp+56h] [-CAh] BYREF
  int v29; // [sp+58h] [-C8h] BYREF
  idVec3 *v30; // [sp+5Ch] [-C4h]
  idBounds v31; // [sp+60h] [-C0h] BYREF
  idAnimatorParms_Base v32[2]; // [sp+80h] [-A0h] BYREF

  idDoor_Base::SetDoorState(this, activator: this, s: DOOR_CLOSED);
  v32[0].animStack = this->GetAnimStack_2(this);
  idStr::idStr(this: &v32[0].name, text: "all");
  v32[0].originBlend = ORIGINBLEND_BRANCH;
  v32[0].weightGroup = MD6_WEIGHTGROUP_ALL;
  v32[0].filterGroup = MD6_WEIGHTGROUP_ALL;
  v32[0].alpha = 1.0;
  v32[0].blendOp = BOP_LERP;
  v2 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: &this->doorAnimator, gametimeManager: v2, parms: v32);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  v4 = 0;
  if ( this->collisionParts.num > 0 )
  {
    v5 = 0;
    do
    {
      if ( idStr::Cmp(s1: this->collisionParts.list[v5].joint.data, s2: &byte_8200D768) != 0
        && TreeAnimatorFromPresentable != nullptr )
      {
        v30 = (idVec3 *)&this->collisionParts.list[v5];
        LOWORD(v30[3].x) = HIWORD(idTreeAnimator::GetJointIndex(
                                    this: (idTreeAnimator *)&v29,
                                    result: (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable,
                                    jointName: (const char *)LODWORD(v30->z))->__vftable);
      }
      else
      {
        this->collisionParts.list[v5].jointIndex.value = -1;
      }
      v6 = (idPresentableDoorAnimated *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                          size: 0x568u,
                                          tag: TAG_PRESENTABLE,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
      v30 = (idVec3 *)v6;
      if ( v6 != nullptr )
        v7 = idPresentableDoorAnimated::idPresentableDoorAnimated(
               this: v6,
               door: this,
               piece: &this->collisionParts.list[v5]);
      else
        v7 = nullptr;
      this->collisionParts.list[v5].presentable = v7;
      idPresentable::SetEntityNumber(this: this->collisionParts.list[v5].presentable, value: 0x1FFF);
      v8 = &this->collisionParts.list[v5];
      Classname = idClass::GetClassname(this);
      presentable = (int)v8->presentable;
      *(_DWORD *)(presentable + 1088) = Classname;
      idClientGame::AddPresentable(
        this: clientGame,
        presentable: this->collisionParts.list[v5].presentable,
        index: -1,
        skipReplication: false,
        a5: v12,
        a6: (int)&this->collisionParts.list[v5],
        a7: presentable,
        a8: v11,
        a9: v19,
        a10: v20,
        a11: v21,
        a12: v22,
        a13: v23,
        a14: v24);
      ++v4;
      ++v5;
    }
    while ( v4 < this->collisionParts.num );
  }
  idEntity::BecomeActive(this, flags: 4);
  idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
  idDoor_Animated::UpdateCollisionParts(this, bounds: &v31, push: false);
  y = v31.b[0].y;
  z = v31.b[0].z;
  x = v31.b[1].x;
  v30 = &this->bounds.b[1];
  this->bounds.b[0].x = v31.b[0].x;
  v16 = v31.b[1].y;
  this->bounds.b[0].y = y;
  this->bounds.b[0].z = z;
  this->bounds.b[1].x = x;
  v17 = v31.b[1].z;
  this->bounds.b[1].y = v16;
  this->bounds.b[1].z = v17;
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    idDeclMD6::StrongLoadAlias(
      this: (idDeclMD6 *)&v25,
      result: TreeAnimatorFromPresentable->decl,
      aliasName: this->openAnim.data);
    data = this->closeAnim.data;
    this->openAnimHandle.value = v25;
    idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v26, result: TreeAnimatorFromPresentable->decl, aliasName: data);
    this->closeAnimHandle.value = v26;
    if ( idStr::Cmp(s1: this->lockAnim.data, s2: &byte_8200D768) != 0 )
    {
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v27,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: this->lockAnim.data);
      this->lockAnimHandle.value = v27;
    }
    if ( idStr::Cmp(s1: this->unlockAnim.data, s2: &byte_8200D768) != 0 )
    {
      idDeclMD6::StrongLoadAlias(
        this: (idDeclMD6 *)&v28,
        result: TreeAnimatorFromPresentable->decl,
        aliasName: this->unlockAnim.data);
      this->unlockAnimHandle.value = v28;
    }
    if ( this->openAnimHandle.value == 0xFFFF )
      idLib::Warning(fmt: "Animated door %s had a bad openAnimHandle. Door will not be openable.", this->name.data);
    if ( this->closeAnimHandle.value == 0xFFFF )
      idLib::Warning(fmt: "Animated door %s had a bad closeAnimHandle. Door will not be closable.", this->name.data);
  }
  else
  {
    idLib::Warning(
      fmt: "idDoor_Animated '%s' does not have a valid animator and won'r function properly",
      this->name.data);
  }
  idStr::FreeData(this: &v32[0].name);
}


// ========================================================================
// __unwind$489420
// EA  : 0x82C2177C
// RVA : 0x00C2177C
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_489420()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 288 + 128));
}


// ========================================================================
// __unwind$489421_0
// EA  : 0x82C217A4
// RVA : 0x00C217A4
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_489421_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 288 + 92), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ??0idDoor_Animated@@QAA@XZ
// EA  : 0x82C21840
// RVA : 0x00C21840
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

idDoor_Animated *__fastcall idDoor_Animated::idDoor_Animated(idDoor_Animated *this)
{
  idDoor_Base::idDoor_Base(this);
  this->__vftable = (idDoor_Animated_vtbl *)&idDoor_Animated::`vftable';
  idAnimator_Channel::idAnimator_Channel(this: &this->doorAnimator);
  this->pushFlags = 40;
  idStr::idStr(this: &this->openAnim, text: "open");
  idStr::idStr(this: &this->closeAnim, text: "close");
  idStr::idStr(this: &this->lockAnim, text: "lock");
  idStr::idStr(this: &this->unlockAnim, text: "unlock");
  this->triggerTargetsOnOpen = false;
  this->msUntilClose = -1;
  this->numMaxOpens = -1;
  this->playerCanClose = true;
  this->collisionParts.granularity = 0;
  this->collisionParts.memTag = 5;
  this->collisionParts.listStatic = 0;
  this->collisionParts.list = nullptr;
  this->collisionParts.size = 0;
  this->collisionParts.num = 0;
  this->testForActorsWhenClosing = false;
  this->autoCloseTime = 0;
  this->playing = false;
  this->openCount = 0;
  this->openAnimHandle.value = -1;
  this->closeAnimHandle.value = -1;
  this->lockAnimHandle.value = -1;
  this->unlockAnimHandle.value = -1;
  this->canCloseQuery.index = 0xFFFF00000000LL;
  return this;
}


// ========================================================================
// __unwind$489713
// EA  : 0x82C21970
// RVA : 0x00C21970
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_489713()
{
  int v0; // r12

  idDoor_Base::~idDoor_Base(this: *(idDoor_Base **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489714_0
// EA  : 0x82C21998
// RVA : 0x00C21998
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_489714_0()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 5296));
}


// ========================================================================
// __unwind$489715_3
// EA  : 0x82C219C4
// RVA : 0x00C219C4
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_489715_3()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 5396));
}


// ========================================================================
// __unwind$489716_0
// EA  : 0x82C219F0
// RVA : 0x00C219F0
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_489716_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 5428));
}


// ========================================================================
// __unwind$489717_0
// EA  : 0x82C21A1C
// RVA : 0x00C21A1C
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_489717_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 5460));
}


// ========================================================================
// __unwind$489718_0
// EA  : 0x82C21A48
// RVA : 0x00C21A48
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_489718_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 5492));
}


// ========================================================================
// ??1idDoor_Animated@@UAA@XZ
// EA  : 0x82C21A80
// RVA : 0x00C21A80
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void __fastcall idDoor_Animated::~idDoor_Animated(idDoor_Animated *this)
{
  int v2; // r28
  int v3; // r29
  idPresentableDoorAnimated *presentable; // r3
  idDoor_AnimatedPiece *list; // r27
  int size; // r29
  idStr *p_joint; // r28
  idEntityPtr<idEntity> *v8; // r4

  this->__vftable = (idDoor_Animated_vtbl *)&idDoor_Animated::`vftable';
  v2 = 0;
  if ( this->collisionParts.num > 0 )
  {
    v3 = 0;
    do
    {
      presentable = this->collisionParts.list[v3].presentable;
      if ( presentable != nullptr )
      {
        idPresentable::Delete(this: presentable);
        this->collisionParts.list[v3].presentable = nullptr;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->collisionParts.num );
  }
  if ( this->collisionParts.listStatic == 0 || this->collisionParts.listStatic == 2 )
  {
    list = this->collisionParts.list;
    if ( list != nullptr )
    {
      size = this->collisionParts.size;
      if ( size > 0 )
      {
        p_joint = &list->joint;
        do
        {
          idStr::FreeData(this: p_joint);
          --size;
          p_joint = (idStr *)((char *)p_joint + 44);
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    this->collisionParts.list = nullptr;
    this->collisionParts.size = 0;
  }
  this->collisionParts.num = 0;
  idStr::FreeData(this: &this->unlockAnim);
  idStr::FreeData(this: &this->lockAnim);
  idStr::FreeData(this: &this->closeAnim);
  idStr::FreeData(this: &this->openAnim);
  idAnimator_Channel::~idAnimator_Channel(this: &this->doorAnimator);
  if ( this->linked.listStatic == 0 || this->linked.listStatic == 2 )
  {
    v8 = this->linked.list;
    if ( v8 != nullptr )
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    this->linked.list = nullptr;
    this->linked.size = 0;
  }
  this->linked.num = 0;
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$490032_0
// EA  : 0x82C21BD0
// RVA : 0x00C21BD0
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_490032_0()
{
  int v0; // r12

  idDoor_Base::~idDoor_Base(this: *(idDoor_Base **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$490033
// EA  : 0x82C21BF8
// RVA : 0x00C21BF8
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_490033()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 160 + 180) + 5296));
}


// ========================================================================
// __unwind$490034
// EA  : 0x82C21C24
// RVA : 0x00C21C24
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_490034()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 5396));
}


// ========================================================================
// __unwind$490035
// EA  : 0x82C21C50
// RVA : 0x00C21C50
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_490035()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 5428));
}


// ========================================================================
// __unwind$490036
// EA  : 0x82C21C7C
// RVA : 0x00C21C7C
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_490036()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 5460));
}


// ========================================================================
// __unwind$490037
// EA  : 0x82C21CA8
// RVA : 0x00C21CA8
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_490037()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 5492));
}


// ========================================================================
// __unwind$490038
// EA  : 0x82C21CD4
// RVA : 0x00C21CD4
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_490038()
{
  int v0; // r12

  idList<idDoor_AnimatedPiece,5>::~idList<idDoor_AnimatedPiece,5>(this: (idList<idDoor_AnimatedPiece,5> *)(*(_DWORD *)(v0 - 160 + 180) + 5536));
}


// ========================================================================
// __unwind$490168
// EA  : 0x82C21D00
// RVA : 0x00C21D00
// PDB : w:\tech5\tungsten\game\entities\door_animated.cpp
// ========================================================================

void _unwind_490168()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 160 + 180));
}

