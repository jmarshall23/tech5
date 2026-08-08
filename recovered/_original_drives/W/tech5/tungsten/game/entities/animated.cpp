
// ========================================================================
// ?StartCurAnim@idAnimated@@AAAXXZ
// EA  : 0x82BF63F0
// RVA : 0x00BF63F0
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void __fastcall idAnimated::StartCurAnim(idAnimated *this)
{
  idAnimated::anim_t *v2; // r30
  const char *data; // r29
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v5; // r3
  idGameTimeManager *p_gameTimeManager; // r3
  int GameMs; // r30
  const idAnimStack *v8; // r3
  __int64 v9; // r8
  int v10; // r30
  const idAnimStack *v11; // r3
  const blendParms_t *v12; // r7
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v13[8]; // [sp+50h] [-50h] BYREF
  blendParms_t v14[3]; // [sp+60h] [-40h] BYREF

  v2 = &this->animations.list[this->curAnim];
  data = v2->animation.data;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  idDeclMD6::FindAliasHandle(this: (idDeclMD6 *)v13, result: TreeAnimatorFromPresentable->decl, aliasName: data);
  if ( v13[0].value == 0xFFFF )
  {
    v5 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    idLib::Printf(
      fmt: "idAnimated '%s - could not find animation alias '%s' in decl '%s",
      this->name.data,
      v2->animation.data,
      v5->name.str);
  }
  else
  {
    blendParms_t::blendParms_t(this: v14);
    blendParms_t::SetDestStartFrame(this: v14, frame: 0);
    blendParms_t::SetDuration(this: v14, frame: v2->blendDuration);
    p_gameTimeManager = &clientGame->gameTimeManager;
    if ( v2->cycle )
    {
      GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
      v8 = this->GetAnimStack_2(this);
      LODWORD(v9) = v14;
      idAnimator_Channel::CycleAnim(
        this: &this->channelAnimator,
        stack: v8,
        ah: v13,
        curTime: GameMs,
        rateScale: 1.0,
        leafStarted: v9,
        a7: nullptr);
    }
    else
    {
      v10 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
      v11 = this->GetAnimStack_2(this);
      idAnimator_Channel::PlayAnim(
        this: &this->channelAnimator,
        stack: v11,
        ah: v13,
        curTime: v10,
        rateScale: 1.0,
        blendParms: v12,
        blendOutDurationMS_: v14,
        leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
        a9: nullptr);
    }
  }
}


// ========================================================================
// ?OnActivate@idAnimated@@UAAXPAVidEntity@@@Z
// EA  : 0x82BF6540
// RVA : 0x00BF6540
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void __fastcall idAnimated::OnActivate(idAnimated *this, idEntity *activator)
{
  int num; // r10
  int curAnim; // r11

  num = this->animations.num;
  curAnim = this->curAnim;
  if ( curAnim < num )
    this->curAnim = curAnim + 1;
  if ( this->curAnim < num )
    goto LABEL_6;
  if ( this->loopAnimList )
  {
    this->curAnim = 0;
LABEL_6:
    idAnimated::StartCurAnim(this);
    return;
  }
  this->curAnim = num - 1;
  idEntity::BecomeInactive(this, flags: 5);
}


// ========================================================================
// ?Event_Reset@idAnimated@@QAA?AVeventVoid@@XZ
// EA  : 0x82BF6590
// RVA : 0x00BF6590
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

idAnimated *__fastcall idAnimated::Event_Reset(idAnimated *this, idEntity *result)
{
  result[6].dormancy.lastTimeInPlayerPVS = 0;
  idEntity::BecomeActive(this: result, flags: 4);
  return this;
}


// ========================================================================
// ?AnimEvent_VoiceOver@idAnimated@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclVoiceOver@@@Z
// EA  : 0x82BF65D8
// RVA : 0x00BF65D8
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

idAnimated *__fastcall idAnimated::AnimEvent_VoiceOver(
        idAnimated *this,
        idAI2 *result,
        const idMD6Anim *animHandle,
        const idDeclVoiceOver *vo)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v10; // r30

  if ( vo != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
    presentable = result->presentable;
    v10 = TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      presentable = result->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( v10 != nullptr )
      idFaceMgr::StartVoiceOver(
        this: (idFaceMgr *)&result->afProperties.serializeProps.serializedTrees[1],
        owner: result,
        ta: v10,
        vo);
    return this;
  }
  else
  {
    idLib::Warning(fmt: "Invalid voice over decl specified for AnimEvent_VoiceOver");
    return this;
  }
}


// ========================================================================
// ??0idBinaryAnimation@@QAA@XZ
// EA  : 0x82BF6670
// RVA : 0x00BF6670
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

idBinaryAnimation *__fastcall idBinaryAnimation::idBinaryAnimation(idBinaryAnimation *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idBinaryAnimation_vtbl *)&idBinaryAnimation::`vftable';
  this->animation.len = 0;
  this->animation.allocedAndFlag = 20;
  this->animation.data = this->animation.baseBuffer;
  this->animation.baseBuffer[0] = 0;
  this->animationHandle.value = -1;
  idAnimator_Channel::idAnimator_Channel(this: &this->channelAnimator);
  this->totalAnimMilliseconds = 0;
  this->animStartMilliseconds = 0;
  this->megaMorphTable = nullptr;
  return this;
}


// ========================================================================
// __unwind$488640
// EA  : 0x82BF66E8
// RVA : 0x00BF66E8
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _unwind_488640()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$488641
// EA  : 0x82BF6710
// RVA : 0x00BF6710
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _unwind_488641()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 5200));
}


// ========================================================================
// ??1idBinaryAnimation@@UAA@XZ
// EA  : 0x82BF6748
// RVA : 0x00BF6748
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void __fastcall idBinaryAnimation::~idBinaryAnimation(idBinaryAnimation *this)
{
  this->__vftable = (idBinaryAnimation_vtbl *)&idBinaryAnimation::`vftable';
  idAnimator_Channel::~idAnimator_Channel(this: &this->channelAnimator);
  idStr::FreeData(this: &this->animation);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$488942_0
// EA  : 0x82BF67A4
// RVA : 0x00BF67A4
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _unwind_488942_0()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488943
// EA  : 0x82BF67CC
// RVA : 0x00BF67CC
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _unwind_488943()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 5200));
}


// ========================================================================
// ?Think@idBinaryAnimation@@UAAXXZ
// EA  : 0x82BF67F8
// RVA : 0x00BF67F8
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idBinaryAnimation::Think(idBinaryAnimation *this)
{
  int v2; // r29
  __int64 v3; // r4 OVERLAPPED
  double v4; // fp12
  float *v5; // r10
  idDeclTable *megaMorphTable; // r11
  double v7; // fp31
  idPresentable *presentable; // r3
  const idDeclRenderParm *r; // r30
  const idAnimStack *v10; // r3
  float v11; // [sp+50h] [-40h] BYREF
  float v12; // [sp+54h] [-3Ch] BYREF
  float v13; // [sp+58h] [-38h] BYREF
  int v14; // [sp+5Ch] [-34h]

  idAnimatedEntity::UpdateFrameCommands(this);
  idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
  v2 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  LODWORD(v3) = this->totalAnimMilliseconds;
  v14 = v2 - this->animStartMilliseconds;
  HIDWORD(v3) = v14;
  v12 = 0.0;
  v13 = 1.0;
  v4 = (float)((float)*(__int64 *)((char *)&v3 + 4) / (float)v3);
  v11 = (float)*(__int64 *)((char *)&v3 + 4) / (float)v3;
  if ( v4 <= 0.0 )
  {
    v5 = &v12;
  }
  else
  {
    v5 = &v11;
    if ( v4 >= 1.0 )
      v5 = &v13;
  }
  megaMorphTable = this->megaMorphTable;
  v7 = *v5;
  if ( megaMorphTable != nullptr )
    v7 = idLookupTable::TableLookup(this: megaMorphTable->table, time: *v5, fastSearch: v3);
  presentable = this->presentable;
  r = (const idDeclRenderParm *)rpMegatextureMorph.r;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::SetParm(this: presentable, parm: r, scalar: v7);
  v10 = this->GetAnimStack_2(this);
  if ( idAnimator_Channel::IsDone(this: &this->channelAnimator, stack: v10, curTime: v2) )
    idEntity::BecomeInactive(this, flags: 5);
}


// ========================================================================
// ?OnActivate@idBinaryAnimation@@UAAXPAVidEntity@@@Z
// EA  : 0x82BF6950
// RVA : 0x00BF6950
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void __fastcall idBinaryAnimation::OnActivate(idBinaryAnimation *this, idEntity *activator)
{
  int GameMs; // r30
  const idAnimStack *v4; // r3
  const blendParms_t *v5; // r7
  blendParms_t v6[3]; // [sp+50h] [-40h] BYREF

  blendParms_t::blendParms_t(this: v6);
  blendParms_t::SetDestStartFrame(this: v6, frame: 0);
  blendParms_t::SetDuration(this: v6, frame: 0);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v4 = this->GetAnimStack_2(this);
  idAnimator_Channel::PlayAnim(
    this: &this->channelAnimator,
    stack: v4,
    ah: &this->animationHandle,
    curTime: GameMs,
    rateScale: 1.0,
    blendParms: v5,
    blendOutDurationMS_: v6,
    leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
    a9: nullptr);
  this->animStartMilliseconds = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idEntity::BecomeActive(this, flags: 5);
}


// ========================================================================
// ?Spawn@idAnimated@@QAAXXZ
// EA  : 0x82BF6A18
// RVA : 0x00BF6A18
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void __fastcall idAnimated::Spawn(idAnimated *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v4; // r21
  int v5; // r28
  idGameTimeManager *v6; // r3
  int num; // r11
  int v8; // r24
  int v9; // r25
  idAnimated::attachment_t *v10; // r29
  const idDeclEntityDef *entityDef; // r5
  const idAttachment *v12; // r3
  idEntityPtr<idEntity> *p_entity; // r3
  const char *data; // r29
  idEntity *v15; // r3
  idEntity *v16; // r5
  const idDeclMD6 *md6; // r11
  int v18; // r29
  idAnimated::anim_t *v19; // r27
  bool v20; // [sp+Bh] [-125h]
  bool v21; // [sp+Fh] [-121h]
  bool v22; // [sp+13h] [-11Dh]
  bool v23; // [sp+17h] [-119h]
  int v24; // [sp+18h] [-118h]
  int v25; // [sp+1Ch] [-114h]
  int v26; // [sp+20h] [-110h]
  int v27; // [sp+24h] [-10Ch]
  int v28; // [sp+28h] [-108h]
  int v29; // [sp+2Ch] [-104h]
  int v30; // [sp+30h] [-100h]
  int v31; // [sp+34h] [-FCh]
  int v32; // [sp+38h] [-F8h]
  int v33; // [sp+3Ch] [-F4h]
  int v34; // [sp+40h] [-F0h]
  int v35; // [sp+44h] [-ECh]
  int v36; // [sp+48h] [-E8h]
  int v37; // [sp+4Ch] [-E4h]
  int v38; // [sp+50h] [-E0h]
  int v39; // [sp+58h] [-D8h]
  int v40; // [sp+60h] [-D0h]
  int v41; // [sp+68h] [-C8h]
  unsigned __int16 v42; // [sp+70h] [-C0h] BYREF
  idAttachmentCollection v43; // [sp+74h] [-BCh] BYREF
  idAnimatorParms_Base v44[2]; // [sp+90h] [-A0h] BYREF

  this->attachments.parent = this;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v4 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v4 == nullptr )
    idLib::Error(fmt: "Invalid MD6 model on func/animated '%s'", this->name.data);
  v44[0].animStack = this->GetAnimStack_2(this);
  idStr::idStr(this: &v44[0].name, text: "base");
  v5 = 0;
  v44[0].originBlend = ORIGINBLEND_BRANCH;
  v44[0].blendOp = BOP_LERP;
  v44[0].weightGroup = MD6_WEIGHTGROUP_ALL;
  v44[0].alpha = 0.0;
  v44[0].filterGroup = MD6_WEIGHTGROUP_ALL;
  v6 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: &this->channelAnimator, gametimeManager: v6, parms: v44);
  idFaceMgr::Init(
    this: &this->faceMgr,
    owner: this,
    ta: v4,
    mood: MOOD_NONE,
    voiceChannel: SND_CHANNEL_VOICE,
    enableMoodAnimation: true,
    enableLipSyncAnimation: true,
    enableGestureAnimation: true,
    enableEyeTracking: v20,
    useFaceSetupEyeTracking_: v21,
    enableBlinking: v22,
    enableLidDeformation: v23,
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
    a28: 0,
    a29: v39,
    a30: false,
    a31: v40,
    a32: 0,
    a33: v41,
    a34: 0);
  idTreeAnimator::SetOriginDeltaLookAhead(this: v4, lookAhead: true);
  idStr::FreeData(this: &v44[0].name);
  num = this->startingAttachments.num;
  if ( num != 0 )
  {
    v8 = 0;
    if ( num > 0 )
    {
      v9 = 0;
      do
      {
        v10 = &this->startingAttachments.list[v9];
        entityDef = v10->entityDef;
        if ( entityDef != nullptr )
        {
          idAttachmentCollection::AddAttachment(
            this: &v43,
            result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
            entityDef,
            tag: v10->tag.data,
            forceReplicationFlags: -1);
          v12 = idAttachmentCollection::Get(
                  this: &this->attachments,
                  handle: (const idHandle<int,enum invalidAttachment_t,-1> *)&v43);
          if ( v12->handle.value != -1 )
          {
            p_entity = &v12->entity;
            if ( gameLocal->spawnIds.ptr[p_entity->spawnId.value & 0x1FFF] == p_entity->spawnId.value >> 13
              && v10->entityName.len != 0 )
            {
              data = v10->entityName.data;
              v15 = idEntityPtr<idEntity const>::operator->(this: p_entity);
              idEntity::SetName(this: v15, newName: data);
            }
          }
        }
        else if ( v10->entityName.len != 0 )
        {
          v16 = gameLocal->FindEntity(this: gameLocal, a2: v10->entityName.data);
          if ( v16 != nullptr )
            idAttachmentCollection::AddAttachment(
              this: (idAttachmentCollection *)&v43.attachments.num,
              result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
              ent: v16,
              tag: v10->tag.data);
          else
            idLib::Warning(fmt: "Could not find entity '%s' to attach.", v10->entityName.data);
        }
        else
        {
          md6 = v10->md6;
          if ( md6 != nullptr )
          {
            idAttachmentCollection::AddAttachment(
              this: (idAttachmentCollection *)&v43.attachments.size,
              result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
              modelName: md6->name.str,
              tag: v10->tag.data);
          }
          else if ( v10->lwoName.len != 0 )
          {
            idAttachmentCollection::AddAttachment(
              this: (idAttachmentCollection *)&v43.attachments.granularity,
              result: (idHandle<int,enum invalidAttachment_t,-1> *)&this->attachments,
              modelName: v10->lwoName.data,
              tag: v10->tag.data);
          }
          else
          {
            idLib::Warning(fmt: "No valid attachment specified for '%s'", this->name.data);
          }
        }
        ++v8;
        ++v9;
      }
      while ( v8 < this->startingAttachments.num );
    }
  }
  if ( this->animations.num > 0 )
  {
    v18 = 0;
    do
    {
      v19 = &this->animations.list[v18];
      idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v42, result: v4->decl, aliasName: v19->animation.data);
      ++v5;
      ++v18;
      v19->animationHandle.value = v42;
    }
    while ( v5 < this->animations.num );
  }
  idAnimated::StartCurAnim(this);
  idEntity::BecomeActive(this, flags: ((_cntlzw(this->alwaysUpdate) & 0x20) == 0) + 4);
}


// ========================================================================
// $LN123_2
// EA  : 0x82BF6D0C
// RVA : 0x00BF6D0C
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _LN123_2()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 304 + 144));
}


// ========================================================================
// ?Think@idAnimated@@UAAXXZ
// EA  : 0x82BF6D38
// RVA : 0x00BF6D38
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void __fastcall idAnimated::Think(idAnimated *this)
{
  int v2; // r30
  const idAnimStack *v3; // r3
  int curAnim; // r11
  int num; // r10
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r30
  idPhysics *Physics; // r3
  int v10; // r3
  float v11; // r7
  float v12; // r6
  idPhysics *v13; // r3
  int v14; // r3
  char *v15; // r10
  _DWORD *v16; // r11
  int i; // ctr
  idTreeAnimator *v18; // r3
  idPhysics *v19; // r3
  idPhysics *v20; // r3
  idVec3 v21; // [sp+50h] [-A0h] BYREF
  idVec3 v22; // [sp+60h] [-90h] BYREF
  idVec3 v23; // [sp+70h] [-80h] BYREF
  char v24; // [sp+7Ch] [-74h] BYREF
  idMat3 v25; // [sp+80h] [-70h] BYREF
  idMat3 v26; // [sp+B0h] [-40h] BYREF

  idAnimatedEntity::UpdateFrameCommands(this);
  if ( !this->animations.list[this->curAnim].cycle )
  {
    v2 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v3 = this->GetAnimStack_2(this);
    if ( idAnimator_Channel::IsDone(this: &this->channelAnimator, stack: v3, curTime: v2) )
    {
      curAnim = this->curAnim;
      num = this->animations.num;
      if ( curAnim < num )
        this->curAnim = curAnim + 1;
      if ( this->curAnim < num )
        goto LABEL_8;
      if ( this->loopAnimList )
      {
        this->curAnim = 0;
LABEL_8:
        idAnimated::StartCurAnim(this);
        goto LABEL_9;
      }
      this->curAnim = num - 1;
      idEntity::BecomeInactive(this, flags: 5);
    }
  }
LABEL_9:
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v8 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 != nullptr )
  {
    idTreeAnimator::SetRemoveOriginRotation(this: v8, removeRotation: this->applyAnimDelta);
    idTreeAnimator::SetRemoveOriginRotation(this: v8, removeRotation: this->applyAnimDelta);
    if ( this->applyAnimDelta )
    {
      Physics = idEntity::GetPhysics(this);
      v10 = (int)Physics->GetOrigin(this: Physics, a2: 0);
      v11 = *(float *)(v10 + 4);
      v12 = *(float *)(v10 + 8);
      v21.x = *(float *)v10;
      v21.y = v11;
      v21.z = v12;
      v13 = idEntity::GetPhysics(this);
      v14 = (int)v13->GetAxis(this: v13, a2: 0);
      v15 = &v24;
      v16 = (_DWORD *)(v14 - 4);
      for ( i = 9; i != 0; --i )
      {
        ++v16;
        v15 += 4;
        *(_DWORD *)v15 = *v16;
      }
      v22.x = 1.0;
      v22.y = 1.0;
      v22.z = 1.0;
      v18 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
      idTreeAnimator::ApplyOriginDeltas(
        this: v18,
        axis: &v25,
        origin: &v21,
        outAxis: &v26,
        outOrigin: &v23,
        extraScale: &v22);
      v19 = idEntity::GetPhysics(this);
      v19->SetOrigin(this: v19, a2: &v23, a3: -1);
      v20 = idEntity::GetPhysics(this);
      v20->SetAxis(this: v20, a2: &v26, a3: -1);
    }
    idFaceMgr::Update(this: &this->faceMgr, owner: (idAI2 *)this, ta: v8, focusPoint: &vec3_origin);
    idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
    idEntity::UpdateVisuals(this);
  }
  else
  {
    idLib::Warning(fmt: "func/animated '%s' has an invalid model.", this->name.data);
    idEntity::BecomeInactive(this, flags: 5);
  }
}


// ========================================================================
// ?GetBinaryAnimationState@idBinaryAnimation@@QAA_NAAPAVidTreeAnimator@@AAVidStr@@@Z
// EA  : 0x82BF7020
// RVA : 0x00BF7020
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

int __fastcall idBinaryAnimation::GetBinaryAnimationState(
        idBinaryAnimation *this,
        idTreeAnimator **treeAnimator,
        idStr *animName)
{
  idRenderModelInfo *v6; // r3
  int len; // r30

  v6 = this->GetRenderModelInfo(this);
  if ( v6 == nullptr || v6->model == nullptr )
    return 0;
  *treeAnimator = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  len = this->animation.len;
  idStr::EnsureAlloced(this: animName, amount: len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: animName->data, Src: this->animation.data, Size: len);
  animName->data[len] = 0;
  animName->len = len;
  return 1;
}


// ========================================================================
// ?Spawn@idBinaryAnimation@@QAAXXZ
// EA  : 0x82BF70C0
// RVA : 0x00BF70C0
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void __fastcall idBinaryAnimation::Spawn(idBinaryAnimation *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v4; // r26
  idDeclMD6 *decl; // r29
  int numFrames; // r27
  idGameTimeManager *v7; // r3
  char *data; // r28
  const idMD6Anim *v9; // r3
  int v10; // r11
  idMD6AnimData *animData; // r11
  int *v12; // r11
  unsigned __int16 v13; // [sp+50h] [-A0h] BYREF
  unsigned __int16 v14; // [sp+52h] [-9Eh] BYREF
  int v15; // [sp+54h] [-9Ch] BYREF
  int v16; // [sp+58h] [-98h] BYREF
  idList<enum encounterGroupRole_t,5> v17; // [sp+60h] [-90h] BYREF
  idAnimatorParms_Base v18[2]; // [sp+70h] [-80h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v4 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v4 == nullptr )
    idLib::Error(fmt: "Invalid MD6 model on func/binaryAnimation '%s'", this->name.data);
  decl = v4->decl;
  v18[0].animStack = this->GetAnimStack_2(this);
  idStr::idStr(this: &v18[0].name, text: "base");
  numFrames = 0;
  v18[0].originBlend = ORIGINBLEND_BRANCH;
  v18[0].blendOp = BOP_LERP;
  v18[0].weightGroup = MD6_WEIGHTGROUP_ALL;
  v18[0].alpha = 0.0;
  v18[0].filterGroup = MD6_WEIGHTGROUP_ALL;
  v7 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: &this->channelAnimator, gametimeManager: v7, parms: v18);
  animation->RegisterAlias(
    this: (idAnimation *)&v13,
    result: (idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)animation,
    a3: decl,
    a4: this->animation.data);
  if ( v13 == 0xFFFF )
  {
    idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v17);
    idDeclMD6::GetAliases(this: decl, list: &v17, includeParent: true);
    if ( v17.num == 0 )
      idLib::Error(fmt: "Invalid animation on func/binaryAnimation '%s'", this->name.data);
    data = *(char **)*v17.list;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v17);
  }
  else
  {
    data = this->animation.data;
  }
  idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v14, result: v4->decl, aliasName: data);
  this->animationHandle.value = v14;
  v9 = idDeclMD6::AnimForAlias(this: decl, aliasHandle: &this->animationHandle, load: false);
  if ( v9 != nullptr )
  {
    animData = v9->animData;
    if ( animData != nullptr )
      numFrames = animData->numFrames;
    v16 = 1;
    v15 = 1000 * numFrames / 30;
    v12 = &v15;
    if ( v15 <= 1 )
      v12 = &v16;
    v10 = *v12;
  }
  else
  {
    v10 = 1;
  }
  this->totalAnimMilliseconds = v10;
  idTreeAnimator::SetFrameFromAnim(
    this: v4,
    anim: v9,
    frame: 0,
    updateRenderModel: true,
    checkForOriginTranslation: false,
    translationScale: nullptr);
  idStr::FreeData(this: &v18[0].name);
}


// ========================================================================
// $LN65_1
// EA  : 0x82BF72AC
// RVA : 0x00BF72AC
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _LN65_1()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$489567
// EA  : 0x82BF72D4
// RVA : 0x00BF72D4
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _unwind_489567()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 96));
}


// ========================================================================
// ??0idAnimated@@QAA@XZ
// EA  : 0x82BF7370
// RVA : 0x00BF7370
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

idAnimated *__fastcall idAnimated::idAnimated(idAnimated *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idAnimated_vtbl *)&idAnimated::`vftable';
  this->animations.granularity = 0;
  this->animations.memTag = 5;
  this->animations.listStatic = 0;
  this->animations.list = nullptr;
  this->animations.size = 0;
  this->animations.num = 0;
  this->startingAttachments.granularity = 0;
  this->startingAttachments.memTag = 5;
  this->startingAttachments.listStatic = 0;
  this->startingAttachments.list = nullptr;
  this->startingAttachments.size = 0;
  this->startingAttachments.num = 0;
  this->alwaysUpdate = false;
  *(_WORD *)&this->applyAnimDelta = 1;
  idMQBuffer::idMQBuffer(this: &this->attachments);
  this->curAnim = 0;
  idAnimator_Channel::idAnimator_Channel(this: &this->channelAnimator);
  idFaceMgr::idFaceMgr(this: &this->faceMgr);
  return this;
}


// ========================================================================
// __unwind$489821_0
// EA  : 0x82BF7418
// RVA : 0x00BF7418
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _unwind_489821_0()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489822
// EA  : 0x82BF7440
// RVA : 0x00BF7440
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _unwind_489822()
{
  int v0; // r12

  idList<idTarget_TestPlayerState::playerState_Job_t,5>::~idList<idTarget_TestPlayerState::playerState_Job_t,5>(this: (vaiAction_t::throwAttachedItem_t *)(*(_DWORD *)(v0 - 128 + 148) + 5200));
}


// ========================================================================
// __unwind$489823
// EA  : 0x82BF746C
// RVA : 0x00BF746C
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _unwind_489823()
{
  int v0; // r12

  idList<idAnimated::attachment_t,5>::~idList<idAnimated::attachment_t,5>(this: (idList<idAnimated::attachment_t,5> *)(*(_DWORD *)(v0 - 128 + 148) + 5216));
}


// ========================================================================
// __unwind$489824_0
// EA  : 0x82BF7498
// RVA : 0x00BF7498
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _unwind_489824_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5236));
}


// ========================================================================
// __unwind$489825_0
// EA  : 0x82BF74C4
// RVA : 0x00BF74C4
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _unwind_489825_0()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 128 + 148) + 5260));
}


// ========================================================================
// ??1idAnimated@@UAA@XZ
// EA  : 0x82BF7500
// RVA : 0x00BF7500
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void __fastcall idAnimated::~idAnimated(idAnimated *this)
{
  idAnimatedSimple::attachment_t *list; // r3
  idAnimated::anim_t *v3; // r3

  this->__vftable = (idAnimated_vtbl *)&idAnimated::`vftable';
  idFaceMgr::~idFaceMgr(this: &this->faceMgr);
  idAnimator_Channel::~idAnimator_Channel(this: &this->channelAnimator);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->attachments);
  if ( this->startingAttachments.listStatic == 0 || this->startingAttachments.listStatic == 2 )
  {
    list = (idAnimatedSimple::attachment_t *)this->startingAttachments.list;
    if ( list != nullptr )
      idListArrayDelete<idAnimated::attachment_t>(ptr: list, num: this->startingAttachments.size);
    this->startingAttachments.list = nullptr;
    this->startingAttachments.size = 0;
  }
  this->startingAttachments.num = 0;
  if ( this->animations.listStatic == 0 || this->animations.listStatic == 2 )
  {
    v3 = this->animations.list;
    if ( v3 != nullptr )
      idListArrayDelete<subTimingWordData_t>(ptr: &v3->animation, num: this->animations.size);
    this->animations.list = nullptr;
    this->animations.size = 0;
  }
  this->animations.num = 0;
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$489895
// EA  : 0x82BF75B8
// RVA : 0x00BF75B8
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _unwind_489895()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489896
// EA  : 0x82BF75E0
// RVA : 0x00BF75E0
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _unwind_489896()
{
  int v0; // r12

  idList<idTarget_TestPlayerState::playerState_Job_t,5>::~idList<idTarget_TestPlayerState::playerState_Job_t,5>(this: (vaiAction_t::throwAttachedItem_t *)(*(_DWORD *)(v0 - 112 + 132) + 5200));
}


// ========================================================================
// __unwind$489897
// EA  : 0x82BF760C
// RVA : 0x00BF760C
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _unwind_489897()
{
  int v0; // r12

  idList<idAnimated::attachment_t,5>::~idList<idAnimated::attachment_t,5>(this: (idList<idAnimated::attachment_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 5216));
}


// ========================================================================
// __unwind$489898_0
// EA  : 0x82BF7638
// RVA : 0x00BF7638
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _unwind_489898_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 5236));
}


// ========================================================================
// __unwind$489899
// EA  : 0x82BF7664
// RVA : 0x00BF7664
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _unwind_489899()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 5260));
}


// ========================================================================
// `dynamic initializer for 'rpMegatextureMorph''
// EA  : 0x83374DA0
// RVA : 0x01374DA0
// PDB : w:\tech5\tungsten\game\entities\animated.cpp
// ========================================================================

void _dynamic_initializer_for__rpMegatextureMorph__()
{
  rpMegatextureMorph.next = idBaseCodeResource::codeResourceList;
  idBaseCodeResource::codeResourceList = (idBaseCodeResource *)&rpMegatextureMorph;
}

