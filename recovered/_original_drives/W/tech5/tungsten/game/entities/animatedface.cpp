
// ========================================================================
// ?InternalInitWeb@idAnimWebTesting@@MAAXXZ
// EA  : 0x82BFB868
// RVA : 0x00BFB868
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void __fastcall idAnimWebTesting::InternalInitWeb(idAnimWebTesting *this)
{
  idAnimator_AnimWeb::AddBlendVariable(this, name: "blendBack", scalar: &this->blendBack, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "blendRight", scalar: &this->blendRight, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "blendAngle", scalar: &this->blendAngle, flags: FF_NO_OVERRIDE);
}


// ========================================================================
// ?Think@idTestRollBones@@UAAXXZ
// EA  : 0x82BFB8D8
// RVA : 0x00BFB8D8
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

// attributes: thunk
void __fastcall idTestRollBones::Think(idTestRollBones *this)
{
  idAnimatedEntity::Think(this);
}


// ========================================================================
// ?InternalUpdateScalars@idAnimWebTesting@@MAAXH@Z
// EA  : 0x82BFB8E0
// RVA : 0x00BFB8E0
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void __fastcall idAnimWebTesting::InternalUpdateScalars(idAnimWebTesting *this, const int curTime)
{
  if ( (testWebBlendBack.flags & 0x20000) != 0 )
  {
    testWebBlendBack.flags &= ~0x20000u;
    this->blendBack = testWebBlendBack.valueFloat;
  }
  if ( (testWebBlendRight.flags & 0x20000) != 0 )
  {
    testWebBlendRight.flags &= ~0x20000u;
    this->blendRight = testWebBlendRight.valueFloat;
  }
  if ( (testWebBlendAngle.flags & 0x20000) != 0 )
  {
    testWebBlendAngle.flags &= ~0x20000u;
    this->blendAngle = testWebBlendAngle.valueFloat;
  }
}


// ========================================================================
// ??0idTestAnimWeb@@QAA@XZ
// EA  : 0x82BFB968
// RVA : 0x00BFB968
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

idTestAnimWeb *__fastcall idTestAnimWeb::idTestAnimWeb(idTestAnimWeb *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->animWebDecl = nullptr;
  this->__vftable = (idTestAnimWeb_vtbl *)&idTestAnimWeb::`vftable';
  idAnimator_AnimWeb::idAnimator_AnimWeb(this: &this->animWeb);
  this->animWeb.__vftable = (idAnimWebTesting_vtbl *)&idAnimWebTesting::`vftable';
  return this;
}


// ========================================================================
// __unwind$488041
// EA  : 0x82BFB9D0
// RVA : 0x00BFB9D0
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void _unwind_488041()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?Think@idTestAnimWeb@@UAAXXZ
// EA  : 0x82BFBAD8
// RVA : 0x00BFBAD8
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void __fastcall idTestAnimWeb::Think(idTestAnimWeb *this)
{
  idAnimStack *v2; // r3
  idAnimator_AnimWeb *Animator; // r28
  const char *v4; // r30
  int value; // r11
  idDeclAnimWebNode *v6; // r11
  const char *SubWebName; // r3

  v2 = this->GetAnimStack_2(this);
  Animator = (idAnimator_AnimWeb *)idAnimStack::GetAnimator(this: v2, name: "animwebtest");
  if ( Animator != nullptr
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - lastActionTime > 4000 )
  {
    lastActionTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    if ( bInteract )
      v4 = "walk";
    else
      v4 = "idle";
    value = Animator->curNodeIndex.value;
    if ( value == -1 )
      v6 = nullptr;
    else
      v6 = Animator->decl->nodes.list[value];
    SubWebName = idDeclAnimWeb::GetSubWebName(
                   this: Animator->decl,
                   index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v6->subWebIndex.value);
    idAnimator_AnimWeb::ChangeState(
      this: Animator,
      subWebName: SubWebName,
      stateName: v4,
      interruptPath_: INTR_PATH_YES,
      interruptBlend_: INTR_BLEND_NO,
      blendEventMask_: 0);
    bInteract = (_cntlzw(bInteract) & 0x20) != 0;
  }
  idAnimatedEntity::Think(this);
}


// ========================================================================
// ??0idTestRollBones@@QAA@XZ
// EA  : 0x82BFBBF0
// RVA : 0x00BFBBF0
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

idTestRollBones *__fastcall idTestRollBones::idTestRollBones(idTestRollBones *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->rollBonesDecl = nullptr;
  this->__vftable = (idTestRollBones_vtbl *)&idTestRollBones::`vftable';
  this->nameBaseTrack.allocedAndFlag = 20;
  this->nameBaseTrack.data = this->nameBaseTrack.baseBuffer;
  this->nameBaseTrack.len = 0;
  this->nameBaseTrack.baseBuffer[0] = 0;
  this->useDualQuatSkinning = false;
  this->baseTrackAlias.value = -1;
  idAnimator_Channel::idAnimator_Channel(this: &this->animatorBaseTrack);
  idAnimator_RollBones::idAnimator_RollBones(this: &this->animatorRollBones);
  return this;
}


// ========================================================================
// __unwind$488556
// EA  : 0x82BFBC84
// RVA : 0x00BFBC84
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void _unwind_488556()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488557
// EA  : 0x82BFBCAC
// RVA : 0x00BFBCAC
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void _unwind_488557()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 5204));
}


// ========================================================================
// __unwind$488558
// EA  : 0x82BFBCD8
// RVA : 0x00BFBCD8
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void _unwind_488558()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 5240));
}


// ========================================================================
// ?Spawn@idTestRollBones@@QAAXXZ
// EA  : 0x82BFBE50
// RVA : 0x00BFBE50
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void __fastcall idTestRollBones::Spawn(idTestRollBones *this)
{
  idGameTimeManager *v2; // r3
  char *data; // r27
  idAnimStack *v4; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v5; // r3
  BOOL useDualQuatSkinning; // r9
  idAnimStack *v7; // r3
  idGameTimeManager *v8; // r3
  int GameMs; // r26
  const idAnimStack *v10; // r3
  __int64 v11; // r8
  idAnimStack *v12; // r3
  idGameTimeManager *v13; // r3
  int v14; // [sp+50h] [-F0h] BYREF
  idAnimatorParms_Base v15; // [sp+60h] [-E0h] BYREF
  blendParms_t v16; // [sp+A0h] [-A0h] BYREF
  idAnimatorParms_RollBones v17; // [sp+C0h] [-80h] BYREF

  v15.animStack = this->GetAnimStack_2(this);
  idStr::idStr(this: &v15.name, text: "basetrack");
  memset(&v15.originBlend, 0, 12);
  v15.blendOp = BOP_LERP;
  v15.alpha = 1.0;
  v2 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: &this->animatorBaseTrack, gametimeManager: v2, parms: &v15);
  data = this->nameBaseTrack.data;
  v4 = this->GetAnimStack_2(this);
  v5 = animation->StrongLoadAlias(this: &v14, result: animation, a3: v4->treeAnimator->decl, a4: data);
  useDualQuatSkinning = this->useDualQuatSkinning;
  this->baseTrackAlias = (idHandle<unsigned short,enum invalidAliasHandle_t,65535>)v5->value;
  if ( useDualQuatSkinning )
  {
    v7 = this->GetAnimStack_2(this);
    idTreeAnimator::SetUseDualQuaternion(this: v7->treeAnimator, _useDualQuatSkinning: true);
  }
  blendParms_t::blendParms_t(this: &v16);
  blendParms_t::SetDurationMS(this: &v16, ms: 0);
  v8 = gameLocal->GetGameTimeManager(this: gameLocal);
  GameMs = idGameTimeManager::GetGameMs(this: v8, type: GAMETIME_SCALED);
  v10 = this->GetAnimStack_2(this);
  LODWORD(v11) = &v16;
  idAnimator_Channel::CycleAnim(
    this: &this->animatorBaseTrack,
    stack: v10,
    ah: &this->baseTrackAlias,
    curTime: GameMs,
    rateScale: 1.0,
    leafStarted: v11,
    a7: nullptr);
  if ( this->rollBonesDecl != nullptr )
  {
    v12 = this->GetAnimStack_2(this);
    idAnimatorParms_RollBones::idAnimatorParms_RollBones(
      this: &v17,
      declRollBones_: this->rollBonesDecl,
      animStack_: v12,
      name_: "rollBonesTest",
      alpha_: 1.0);
    v13 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->animatorRollBones, gametimeManager: v13, parms: &v17);
    idStr::FreeData(this: &v17.name);
  }
  idEntity::BecomeActive(this, flags: 5);
  idStr::FreeData(this: &v15.name);
}


// ========================================================================
// __unwind$488673
// EA  : 0x82BFC048
// RVA : 0x00BFC048
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void _unwind_488673()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$488674
// EA  : 0x82BFC070
// RVA : 0x00BFC070
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void _unwind_488674()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 320 + 192));
}


// ========================================================================
// ?InitAnimation@idTestAnimWeb@@QAAXXZ
// EA  : 0x82BFC0A0
// RVA : 0x00BFC0A0
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void __fastcall idTestAnimWeb::InitAnimation(idTestAnimWeb *this)
{
  int GameMs; // r29
  const idDeclAnimWeb *animWebDecl; // r28
  idAnimStack *v4; // r3
  const idDeclAnimWeb *v5; // r10
  idGameTimeManager *v6; // r3
  const char *v7; // [sp+8h] [-128h]
  const char *v8; // [sp+Ch] [-124h]
  int v9; // [sp+10h] [-120h]
  int v10; // [sp+14h] [-11Ch]
  int v11; // [sp+18h] [-118h]
  int v12; // [sp+1Ch] [-114h]
  int v13; // [sp+20h] [-110h]
  int v14; // [sp+24h] [-10Ch]
  int v15; // [sp+28h] [-108h]
  int v16; // [sp+2Ch] [-104h]
  int v17; // [sp+30h] [-100h]
  int v18; // [sp+34h] [-FCh]
  int v19; // [sp+38h] [-F8h]
  int v20; // [sp+3Ch] [-F4h]
  int v21; // [sp+40h] [-F0h]
  int v22; // [sp+44h] [-ECh]
  int v23; // [sp+48h] [-E8h]
  int v24; // [sp+4Ch] [-E4h]
  int v25; // [sp+50h] [-E0h]
  int v26; // [sp+58h] [-D8h]
  int v27; // [sp+60h] [-D0h]
  int v28; // [sp+68h] [-C8h]
  idAnimatorParms_AnimWeb v29; // [sp+70h] [-C0h] BYREF

  if ( this->animWebDecl != nullptr )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    animWebDecl = this->animWebDecl;
    v4 = this->GetAnimStack_2(this);
    idAnimatorParms_AnimWeb::idAnimatorParms_AnimWeb(
      this: &v29,
      animStack_: v4,
      name_: "animwebTest",
      blendOp_: BOP_LERP,
      originBlend_: ORIGINBLEND_BRANCH,
      weightGroup_: MD6_WEIGHTGROUP_ALL,
      filterGroup_: MD6_WEIGHTGROUP_ALL,
      alpha_: 1.0,
      webDecl_: v5,
      initialSubWebName_: v7,
      initialStateName_: v8,
      curTime_: v9,
      a13: v10,
      a14: v11,
      a15: v12,
      a16: v13,
      a17: v14,
      a18: v15,
      a19: v16,
      a20: v17,
      a21: v18,
      a22: v19,
      a23: v20,
      a24: v21,
      a25: v22,
      a26: v23,
      a27: v24,
      a28: v25,
      a29: animWebDecl,
      a30: v26,
      a31: "idleSet",
      a32: v27,
      a33: "idle",
      a34: v28,
      a35: GameMs);
    v6 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->animWeb, gametimeManager: v6, parms: &v29);
    idAnimatorParms_AnimWeb::~idAnimatorParms_AnimWeb(this: &v29);
  }
  idEntity::BecomeActive(this, flags: 5);
}


// ========================================================================
// __unwind$488848_0
// EA  : 0x82BFC184
// RVA : 0x00BFC184
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void _unwind_488848_0()
{
  int v0; // r12

  idAnimatorParms_AnimWeb::~idAnimatorParms_AnimWeb(this: (idAnimatorParms_AnimWeb *)(v0 - 304 + 112));
}


// ========================================================================
// ?Spawn@idTestAnimWeb@@QAAXXZ
// EA  : 0x82BFC1B0
// RVA : 0x00BFC1B0
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

// attributes: thunk
void __fastcall idTestAnimWeb::Spawn(idTestAnimWeb *this)
{
  idTestAnimWeb::InitAnimation(this);
}


// ========================================================================
// `dynamic initializer for 'animatedFaceOffset''
// EA  : 0x83374EC8
// RVA : 0x01374EC8
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__animatedFaceOffset__()
{
  idCVar::idCVar(
    this: &animatedFaceOffset,
    name: "animatedFaceOffset",
    value: "1",
    flags: 2,
    description: "faceoffset",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__animatedFaceOffset__);
}


// ========================================================================
// `dynamic initializer for 'testWebBlendBack''
// EA  : 0x83374F20
// RVA : 0x01374F20
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__testWebBlendBack__()
{
  idCVar::idCVar(
    this: &testWebBlendBack,
    name: "testWebBlendBack",
    value: "0",
    flags: 4,
    description: "blenback val",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__testWebBlendBack__);
}


// ========================================================================
// `dynamic initializer for 'testWebBlendRight''
// EA  : 0x83374F78
// RVA : 0x01374F78
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__testWebBlendRight__()
{
  idCVar::idCVar(
    this: &testWebBlendRight,
    name: "testWebBlendRight",
    value: "0",
    flags: 4,
    description: "blenright val",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__testWebBlendRight__);
}


// ========================================================================
// `dynamic initializer for 'testWebBlendAngle''
// EA  : 0x83374FD0
// RVA : 0x01374FD0
// PDB : w:\tech5\tungsten\game\entities\animatedface.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__testWebBlendAngle__()
{
  idCVar::idCVar(
    this: &testWebBlendAngle,
    name: "testWebBlendAngle",
    value: "0",
    flags: 4,
    description: "blenangle val",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__testWebBlendAngle__);
}

