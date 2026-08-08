
// ========================================================================
// ?Shutdown@idFocusInfo@@QAAXPAVidAnimatedEntity@@@Z
// EA  : 0x82A9C058
// RVA : 0x00A9C058
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::Shutdown(idFocusInfo *this, idAnimatedEntity *owner)
{
  int *p_defaultHeadTrackGroup; // r30
  int i; // r31
  idAnimator_Base *v5; // r29
  idAnimStack *v6; // r3

  if ( this->fociType <= (unsigned int)AIFOCI_LOOK )
  {
    p_defaultHeadTrackGroup = &this->defaultHeadTrackGroup;
    for ( i = 2; i != 0; --i )
    {
      v5 = (idAnimator_Base *)*++p_defaultHeadTrackGroup;
      v6 = owner->GetAnimStack_2(this: owner);
      idAnimator_Base::Shutdown(this: v5, stack: v6);
    }
  }
}


// ========================================================================
// ?SetConstraints@idFocusInfo@@QAAXABVidRotationTrackerRange@@@Z
// EA  : 0x82A9C0B8
// RVA : 0x00A9C0B8
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::SetConstraints(idFocusInfo *this, const idRotationTrackerRange *constraints)
{
  if ( this->animators[0] != nullptr && this->animators[1] != nullptr )
    idRotationTracker::SetConstraints(this: &this->aimTracker, constraints);
}


// ========================================================================
// ?AddWeaponFireKickback@idFocusInfo@@QAAXPBVidAnimatedEntity@@PBVidWeapon@@@Z
// EA  : 0x82A9C0E0
// RVA : 0x00A9C0E0
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::AddWeaponFireKickback(idFocusInfo *this, idAI2 *owner, const idWeapon *weapon)
{
  idAI2 *v5; // r3

  v5 = idAI2::CastTo(c: owner);
  idWanderingAim::AddWeaponFireKickbackImpulse(this: &this->wanderingAim, ai: v5, weapon);
}


// ========================================================================
// ?SetEnableTracking@idFocusInfo@@QAAXPBVidAnimatedEntity@@_N@Z
// EA  : 0x82A9C130
// RVA : 0x00A9C130
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::SetEnableTracking(idFocusInfo *this, const idAnimatedEntity *owner, bool enable)
{
  this->enableTracking = enable;
}


// ========================================================================
// ?SetSuppressTracking@idFocusInfo@@QAAXPBVidAnimatedEntity@@_N@Z
// EA  : 0x82A9C138
// RVA : 0x00A9C138
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::SetSuppressTracking(idFocusInfo *this, const idAnimatedEntity *owner, bool suppress)
{
  this->suppressTracking = suppress;
}


// ========================================================================
// ?SetDeclTrackingParms@idFocusInfo@@QAAXPBVidDeclTrackingParms@@@Z
// EA  : 0x82A9C140
// RVA : 0x00A9C140
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::SetDeclTrackingParms(idFocusInfo *this, const idDeclTrackingParms *decl)
{
  if ( decl != nullptr )
    this->declTrackingParms = decl;
}


// ========================================================================
// ?SetTrackingParmsIndex@idFocusInfo@@QAAXH@Z
// EA  : 0x82A9C150
// RVA : 0x00A9C150
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::SetTrackingParmsIndex(idFocusInfo *this, int idx)
{
  this->trackingParmsIndex = idx;
}


// ========================================================================
// ??1idFocusInfo@@QAA@XZ
// EA  : 0x82A9C168
// RVA : 0x00A9C168
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::~idFocusInfo(idFocusInfo *this)
{
  idAnimator_TrackerBase **animators; // r30
  int i; // r29

  animators = this->animators;
  for ( i = 2; i != 0; --i )
  {
    if ( *animators != nullptr )
    {
      ((void (__fastcall *)(idAnimator_TrackerBase *, int))(*animators)->dtr_idAnimator_Base)(a1: *animators, a2: 1);
      *animators = nullptr;
    }
    ++animators;
  }
  idRotationTracker::~idRotationTracker(this: &this->aimTracker);
}


// ========================================================================
// __unwind$488448_0
// EA  : 0x82A9C1D0
// RVA : 0x00A9C1D0
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void _unwind_488448_0()
{
  int v0; // r12

  idAimTracker::~idAimTracker(this: (idAimTracker *)(*(_DWORD *)(v0 - 144 + 164) + 100));
}


// ========================================================================
// ?SetTempFocusPoint@idFocusInfo@@QAAXPAVidAnimatedEntity@@ABVidVec3@@W4aiFocus_t@@@Z
// EA  : 0x82A9C200
// RVA : 0x00A9C200
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::SetTempFocusPoint(
        idFocusInfo *this,
        idAnimatedEntity *owner,
        const idVec3 *focusPoint,
        aiFocus_t _focusType)
{
  if ( this->animators[0] != nullptr && this->animators[1] != nullptr )
  {
    this->idealFocusPoint = *focusPoint;
    this->focusType = _focusType;
  }
}


// ========================================================================
// ?SetLockTracking@idFocusInfo@@QAAX_N@Z
// EA  : 0x82A9C238
// RVA : 0x00A9C238
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::SetLockTracking(idFocusInfo *this, bool lock)
{
  idAnimator_TrackerBase *v2; // r11
  idAnimator_TrackerBase *v3; // r11

  this->lockTracking = lock;
  v2 = this->animators[0];
  if ( v2 != nullptr )
    *((_BYTE *)v2 + 180) = (4 * lock) & 4 | *((_BYTE *)v2 + 180) & 0xFB;
  v3 = this->animators[1];
  if ( v3 != nullptr )
    *((_BYTE *)v3 + 180) = (4 * lock) & 4 | *((_BYTE *)v3 + 180) & 0xFB;
}


// ========================================================================
// ?Init@idFocusInfo@@QAAXPAVidAnimatedEntity@@W4aiFoci_t@@@Z
// EA  : 0x82A9C380
// RVA : 0x00A9C380
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::Init(idFocusInfo *this, idAnimatedEntity *owner, aiFoci_t fociType_)
{
  idAnimator_TorsoTracker *v5; // r3
  idAnimator_TorsoTracker *v6; // r11
  idAnimator_TorsoTracker *v7; // r3
  idAnimator_TorsoTracker *v8; // r11
  idAnimStack *v9; // r3
  idGameTimeManager *v10; // r3
  idAnimStack *v11; // r3
  bool v12; // r9
  idGameTimeManager *v13; // r3
  idStr *p_name; // r3
  idAnimator_TorsoTracker *v15; // r3
  idAnimator_TorsoTracker *v16; // r11
  idAnimator_TorsoTracker *v17; // r3
  idAnimator_TorsoTracker *v18; // r11
  idAnimStack *v19; // r3
  idGameTimeManager *v20; // r3
  idAnimStack *v21; // r3
  bool v22; // r9
  idGameTimeManager *v23; // r3
  idAnimatorParms_TrackerBase v24; // [sp+60h] [-140h] BYREF
  idAnimatorParms_TrackerBase v25; // [sp+A0h] [-100h] BYREF
  idAnimatorParms_TrackerBase v26; // [sp+E0h] [-C0h] BYREF
  idAnimatorParms_TrackerBase v27; // [sp+120h] [-80h] BYREF

  this->fociType = fociType_;
  if ( fociType_ != AIFOCI_AIM )
  {
    if ( fociType_ != AIFOCI_LOOK )
      return;
    v15 = (idAnimator_TorsoTracker *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                       size: 0xBCu,
                                       tag: TAG_NEW,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
    if ( v15 != nullptr )
      v16 = idAnimator_TorsoTracker::idAnimator_TorsoTracker(this: v15);
    else
      v16 = nullptr;
    this->animators[0] = v16;
    v17 = (idAnimator_TorsoTracker *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                       size: 0xBCu,
                                       tag: TAG_NEW,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
    if ( v17 != nullptr )
      v18 = idAnimator_TorsoTracker::idAnimator_TorsoTracker(this: v17);
    else
      v18 = nullptr;
    this->animators[1] = v18;
    v19 = owner->GetAnimStack_2(this: owner);
    idAnimatorParms_TrackerBase::idAnimatorParms_TrackerBase(
      this: &v27,
      animStack_: v19,
      name_: "head_track_1",
      originBlend_: ORIGINBLEND_BRANCH,
      weightGroup_: MD6_WEIGHTGROUP_ALL,
      filterGroup_: MD6_WEIGHTGROUP_ALL,
      alpha_: 0.0,
      projectReferenceOrientation_: 0x82000000,
      a9: false);
    v20 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: this->animators[0], gametimeManager: v20, parms: &v27);
    v21 = owner->GetAnimStack_2(this: owner);
    idAnimatorParms_TrackerBase::idAnimatorParms_TrackerBase(
      this: &v25,
      animStack_: v21,
      name_: "head_track_2",
      originBlend_: ORIGINBLEND_BRANCH,
      weightGroup_: MD6_WEIGHTGROUP_ALL,
      filterGroup_: MD6_WEIGHTGROUP_ALL,
      alpha_: 0.0,
      projectReferenceOrientation_: v22,
      a9: false);
    v23 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: this->animators[1], gametimeManager: v23, parms: &v25);
    idStr::FreeData(this: &v25.name);
    p_name = &v27.name;
  }
  else
  {
    v5 = (idAnimator_TorsoTracker *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                      size: 0xBCu,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
    if ( v5 != nullptr )
      v6 = idAnimator_TorsoTracker::idAnimator_TorsoTracker(this: v5);
    else
      v6 = nullptr;
    this->animators[0] = v6;
    v7 = (idAnimator_TorsoTracker *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                      size: 0xBCu,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
    if ( v7 != nullptr )
      v8 = idAnimator_TorsoTracker::idAnimator_TorsoTracker(this: v7);
    else
      v8 = nullptr;
    this->animators[1] = v8;
    v9 = owner->GetAnimStack_2(this: owner);
    idAnimatorParms_TrackerBase::idAnimatorParms_TrackerBase(
      this: &v24,
      animStack_: v9,
      name_: "torso_track_1",
      originBlend_: ORIGINBLEND_BRANCH,
      weightGroup_: MD6_WEIGHTGROUP_ALL,
      filterGroup_: MD6_WEIGHTGROUP_ALL,
      alpha_: 0.0,
      projectReferenceOrientation_: 0x82000000,
      a9: true);
    v10 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: this->animators[0], gametimeManager: v10, parms: &v24);
    v11 = owner->GetAnimStack_2(this: owner);
    idAnimatorParms_TrackerBase::idAnimatorParms_TrackerBase(
      this: &v26,
      animStack_: v11,
      name_: "torso_track_2",
      originBlend_: ORIGINBLEND_BRANCH,
      weightGroup_: MD6_WEIGHTGROUP_ALL,
      filterGroup_: MD6_WEIGHTGROUP_ALL,
      alpha_: 0.0,
      projectReferenceOrientation_: v12,
      a9: true);
    v13 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: this->animators[1], gametimeManager: v13, parms: &v26);
    idStr::FreeData(this: &v26.name);
    p_name = &v24.name;
  }
  idStr::FreeData(this: p_name);
}


// ========================================================================
// __unwind$488843
// EA  : 0x82A9C694
// RVA : 0x00A9C694
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall _unwind_488843(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 416 + 80), tag: a2);
}


// ========================================================================
// __unwind$488844
// EA  : 0x82A9C6BC
// RVA : 0x00A9C6BC
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall _unwind_488844(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 416 + 80), tag: a2);
}


// ========================================================================
// __unwind$488845
// EA  : 0x82A9C6E4
// RVA : 0x00A9C6E4
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void _unwind_488845()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 416 + 96));
}


// ========================================================================
// __unwind$488846
// EA  : 0x82A9C70C
// RVA : 0x00A9C70C
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void _unwind_488846()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 416 + 224));
}


// ========================================================================
// __unwind$488847
// EA  : 0x82A9C734
// RVA : 0x00A9C734
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall _unwind_488847(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 416 + 80), tag: a2);
}


// ========================================================================
// __unwind$488848
// EA  : 0x82A9C75C
// RVA : 0x00A9C75C
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall _unwind_488848(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 416 + 80), tag: a2);
}


// ========================================================================
// __unwind$488849
// EA  : 0x82A9C784
// RVA : 0x00A9C784
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void _unwind_488849()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 416 + 288));
}


// ========================================================================
// __unwind$488850
// EA  : 0x82A9C7AC
// RVA : 0x00A9C7AC
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void _unwind_488850()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 416 + 160));
}


// ========================================================================
// ?GetCurHeadTrackGroup@idFocusInfo@@QBAPBVidHeadTrackGroup@idDeclMD6@@PBVidAnimatedEntity@@@Z
// EA  : 0x82A9C7D8
// RVA : 0x00A9C7D8
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

const idDeclMD6::idHeadTrackGroup *__fastcall idFocusInfo::GetCurHeadTrackGroup(
        idFocusInfo *this,
        idAnimatedEntity *owner)
{
  int trackGroupIndex; // r30
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v6; // r29
  const idDeclMD6 *decl; // r11
  idTreeAnimator *v9; // r3
  idPresentable *v10; // r11
  idTreeAnimator *v11; // r30
  const idDeclMD6 *v12; // r11

  if ( this->animators[0] != nullptr && this->animators[1] != nullptr )
  {
    trackGroupIndex = this->animators[this->curAnimatorIndex]->trackGroupIndex;
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: owner);
    presentable = owner->presentable;
    v6 = TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: owner);
      presentable = owner->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    decl = v6->decl;
    if ( trackGroupIndex >= 0 && trackGroupIndex < decl->headTrackGroups.num )
      return &decl->headTrackGroups.list[trackGroupIndex];
  }
  else
  {
    v9 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: owner);
    v10 = owner->presentable;
    v11 = v9;
    if ( v10 == nullptr )
    {
      idEntity::InitPresentableInternal(this: owner);
      v10 = owner->presentable;
    }
    idPresentable::UpdateModelTransform(this: v10);
    v12 = v11->decl;
    if ( v12->headTrackGroups.num > 0 )
      return v12->headTrackGroups.list;
  }
  return nullptr;
}


// ========================================================================
// ?SwapTrackers@idFocusInfo@@AAAXPBVidAnimatedEntity@@H@Z
// EA  : 0x82A9C8C8
// RVA : 0x00A9C8C8
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::SwapTrackers(idFocusInfo *this, idAnimatedEntity *owner, int blendTime)
{
  int v5; // r28
  int trackGroupIndex; // r30
  idTreeAnimator *TreeAnimatorFromPresentable; // r28
  idPresentable *presentable; // r3
  const idDeclMD6 *decl; // r11
  int GameMs; // r26
  idAnimator_TrackerBase *v11; // r25
  const idAnimStack *v12; // r3
  int v13; // r30
  idAnimator_TrackerBase *v14; // r31
  const idAnimStack *v15; // r3

  v5 = blendTime;
  if ( blendTime < 0 )
  {
    trackGroupIndex = this->animators[this->curAnimatorIndex]->trackGroupIndex;
    if ( trackGroupIndex < 0 )
    {
      v5 = 500;
    }
    else
    {
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: owner);
      presentable = owner->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: owner);
        presentable = owner->presentable;
      }
      idPresentable::UpdateModelTransform(this: presentable);
      decl = TreeAnimatorFromPresentable->decl;
      if ( trackGroupIndex >= decl->headTrackGroups.num )
        v5 = MEMORY[0x18];
      else
        v5 = decl->headTrackGroups.list[trackGroupIndex].blendTime;
    }
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v11 = this->animators[this->curAnimatorIndex];
  v12 = owner->GetAnimStack(this: owner);
  idAnimator_Base::End(this: v11, stack: v12, curTime: GameMs, blendDurationMS: v5, reset: true);
  this->curAnimatorIndex = (_cntlzw(this->curAnimatorIndex) & 0x20) != 0;
  v13 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v14 = this->animators[this->curAnimatorIndex];
  v15 = owner->GetAnimStack(this: owner);
  idAnimator_Base::Start(this: v14, stack: v15, curTime: v13, blendDurationMS: v5, reset: true);
}


// ========================================================================
// ?SetReferenceJointOverride@idFocusInfo@@QAAXPBVidAnimatedEntity@@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82A9CA28
// RVA : 0x00A9CA28
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::SetReferenceJointOverride(
        idFocusInfo *this,
        idAnimatedEntity *owner,
        const idIndex<short,enum invalidJointIndex_t> *ji)
{
  idAnimatedEntity *v6; // r4
  int trackGroupIndex; // r29
  idAnimator_TrackerBase *v8; // r3
  char v9; // [sp+50h] [-30h] BYREF

  if ( *(__int16 *)((int (__fastcall *)(char *))this->animators[this->curAnimatorIndex]->GetReferenceJointOverride)(a1: &v9) != (__int16)ji )
  {
    v6 = owner;
    trackGroupIndex = this->animators[this->curAnimatorIndex]->trackGroupIndex;
    idFocusInfo::SwapTrackers(this, owner: v6, blendTime: -1);
    this->animators[this->curAnimatorIndex]->trackGroupIndex = trackGroupIndex;
    v8 = this->animators[this->curAnimatorIndex];
    v8->SetReferenceJointOverride(this: v8, a2: ji);
  }
}


// ========================================================================
// ??0idFocusInfo@@QAA@XZ
// EA  : 0x82A9CAE0
// RVA : 0x00A9CAE0
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

idFocusInfo *__fastcall idFocusInfo::idFocusInfo(idFocusInfo *this)
{
  int *p_curAnimatorIndex; // r10
  int v3; // ctr
  float *p_y; // r11

  this->wanderingAim.error = vec3_origin;
  this->wanderingAim.lastTime = -1;
  this->wanderingAim.convergeTime = 0;
  this->focusEntity.spawnId.value = 0x1FFF;
  this->aimPoint = AIMPOINT_HEAD;
  this->declTrackingParms = nullptr;
  this->trackingParmsIndex = -1;
  this->focusTimeout = -1;
  this->idealFocusPoint = vec3_origin;
  this->curFocusPoint = vec3_origin;
  this->offset = vec3_origin;
  this->explicitOffset = vec3_origin;
  this->explicitOffsetAngles = ang_zero;
  idAimTracker::idAimTracker(this: &this->aimTracker);
  this->focusType = AIFOCUS_NOTHING;
  this->defaultHeadTrackGroup = -1;
  this->curAnimatorIndex = 1;
  this->fociType = AIFOCI_MAX;
  p_curAnimatorIndex = &this->curAnimatorIndex;
  v3 = 9;
  p_y = &mat2_identity.mat[1].y;
  do
  {
    *++p_curAnimatorIndex = *(_DWORD *)++p_y;
    --v3;
  }
  while ( v3 != 0 );
  this->enableTracking = true;
  this->suppressTracking = false;
  this->keepFocusInView = false;
  this->hasExplicitFocusPoint = false;
  this->lockTracking = false;
  this->animators[0] = nullptr;
  this->animators[1] = nullptr;
  return this;
}


// ========================================================================
// ?SetExplicitFocusPoint@idFocusInfo@@QAAXPAVidAnimatedEntity@@ABVidVec3@@_NHW4aiFocus_t@@@Z
// EA  : 0x82A9CC38
// RVA : 0x00A9CC38
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::SetExplicitFocusPoint(
        idFocusInfo *this,
        idAnimatedEntity *owner,
        const idVec3 *focusPoint,
        bool _keepFocusInView,
        const int duration,
        aiFocus_t _focusType)
{
  if ( this->animators[0] != nullptr && this->animators[1] != nullptr )
  {
    this->idealFocusPoint = *focusPoint;
    this->hasExplicitFocusPoint = true;
    this->focusEntity.spawnId.value = 0x1FFF;
    this->keepFocusInView = _keepFocusInView;
    this->aimPoint = AIMPOINT_HEAD;
    this->focusType = _focusType;
    if ( duration == -1 )
      this->focusTimeout = -1;
    else
      this->focusTimeout = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                         + duration;
  }
}


// ========================================================================
// ?Clear@idFocusInfo@@QAAXPAVidAnimatedEntity@@@Z
// EA  : 0x82A9CCF0
// RVA : 0x00A9CCF0
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::Clear(idFocusInfo *this, idAnimatedEntity *owner)
{
  this->hasExplicitFocusPoint = false;
  this->focusEntity.spawnId.value = 0x1FFF;
  this->keepFocusInView = false;
  this->aimPoint = AIMPOINT_EYELEVEL;
  this->focusTimeout = -1;
  this->focusType = AIFOCUS_NOTHING;
  this->offset = vec3_origin;
}


// ========================================================================
// ?BlendOut@idFocusInfo@@AAAXPBVidAnimatedEntity@@H@Z
// EA  : 0x82A9CD40
// RVA : 0x00A9CD40
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::BlendOut(idFocusInfo *this, idAnimatedEntity *owner, int blendTime)
{
  int v5; // r29
  int GameMs; // r28
  idAnimator_TrackerBase *v7; // r31
  const idAnimStack *v8; // r3

  v5 = blendTime;
  if ( this->animators[0] != nullptr && this->animators[1] != nullptr )
  {
    if ( blendTime < 0 )
      v5 = idFocusInfo::GetCurHeadTrackGroup(this, owner)->blendTime;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v7 = this->animators[this->curAnimatorIndex];
    v8 = owner->GetAnimStack(this: owner);
    idAnimator_Base::End(this: v7, stack: v8, curTime: GameMs, blendDurationMS: v5, reset: false);
  }
}


// ========================================================================
// ?BlendIn@idFocusInfo@@AAAXPBVidAnimatedEntity@@H@Z
// EA  : 0x82A9CDE0
// RVA : 0x00A9CDE0
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::BlendIn(idFocusInfo *this, idAnimatedEntity *owner, int blendTime)
{
  int v5; // r29
  int GameMs; // r28
  idAnimator_TrackerBase *v7; // r31
  const idAnimStack *v8; // r3

  v5 = blendTime;
  if ( this->animators[0] != nullptr && this->animators[1] != nullptr )
  {
    if ( blendTime < 0 )
      v5 = idFocusInfo::GetCurHeadTrackGroup(this, owner)->blendTime;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v7 = this->animators[this->curAnimatorIndex];
    v8 = owner->GetAnimStack(this: owner);
    idAnimator_Base::Start(this: v7, stack: v8, curTime: GameMs, blendDurationMS: v5, reset: false);
  }
}


// ========================================================================
// ?ShowTrackingInfo@idFocusInfo@@ABAXPBVidAnimatedEntity@@PBDABVidVec3@@2@Z
// EA  : 0x82A9CE88
// RVA : 0x00A9CE88
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::ShowTrackingInfo(
        idFocusInfo *this,
        idAnimatedEntity *owner,
        const char *name,
        const idVec3 *eyePos,
        const idVec3 *offset)
{
  const idDeclMD6::idHeadTrackGroup *CurHeadTrackGroup; // r3
  int value; // r10
  const idDeclMD6::idHeadTrackGroup *v12; // r21
  idEntity *v13; // r3
  idEntity *v14; // r28
  int v15; // r24
  const char *data; // r28
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  va *v21; // r3
  double v22; // fp11
  double v23; // fp7
  idRenderWorld *v24; // r3
  double y; // fp5
  double x; // fp4
  double z; // fp3
  double v28; // fp2
  __int64 v29; // fp1
  va *v30; // r3
  idRenderWorld *v31; // r3
  __int64 v32; // r10
  __int64 v33; // r8
  const idDeclTrackingParms *declTrackingParms; // r11
  __int64 v35; // r6
  va *v36; // r3
  idRenderWorld *v37; // r3
  int v38; // [sp+8h] [-2118h]
  int v39; // [sp+8h] [-2118h]
  int v40; // [sp+8h] [-2118h]
  int v41; // [sp+Ch] [-2114h]
  int v42; // [sp+Ch] [-2114h]
  int v43; // [sp+Ch] [-2114h]
  int v44; // [sp+10h] [-2110h]
  int v45; // [sp+10h] [-2110h]
  int v46; // [sp+10h] [-2110h]
  int v47; // [sp+14h] [-210Ch]
  int v48; // [sp+14h] [-210Ch]
  int v49; // [sp+14h] [-210Ch]
  int v50; // [sp+18h] [-2108h]
  int v51; // [sp+18h] [-2108h]
  int v52; // [sp+18h] [-2108h]
  int v53; // [sp+1Ch] [-2104h]
  int v54; // [sp+1Ch] [-2104h]
  int v55; // [sp+1Ch] [-2104h]
  double v56; // [sp+30h] [-20F0h]
  _DWORD v57[2]; // [sp+70h] [-20B0h] BYREF
  float v58[2]; // [sp+78h] [-20A8h] BYREF
  float v59; // [sp+80h] [-20A0h]
  idStr v60; // [sp+90h] [-2090h] BYREF
  va v61; // [sp+B0h] [-2070h] BYREF
  va v62; // [sp+10B0h] [-1070h] BYREF

  CurHeadTrackGroup = idFocusInfo::GetCurHeadTrackGroup(this, owner);
  value = this->focusEntity.spawnId.value;
  v57[0] = &this->focusEntity;
  v12 = CurHeadTrackGroup;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v13 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v14 = idEntity::CastTo(c: v13);
  }
  else
  {
    v14 = nullptr;
  }
  v15 = -1;
  if ( v12 != nullptr )
    v15 = (unsigned __int16)v12->orientationJointIdx.value;
  if ( *(unsigned __int16 *)((int (__fastcall *)(_DWORD *))this->animators[this->curAnimatorIndex]->GetReferenceJointOverride)(a1: v57) < 0x8000u )
    v15 = *(unsigned __int16 *)((int (__fastcall *)(_DWORD *))this->animators[this->curAnimatorIndex]->GetReferenceJointOverride)(a1: v57);
  if ( v14 != nullptr )
    data = v14->name.data;
  else
    data = "none";
  if ( (v15 & 0x8000u) != 0 )
  {
    HIDWORD(v18) = "none";
  }
  else
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: owner);
    HIDWORD(v18) = idDeclMD6::GetJointName(
                     this: TreeAnimatorFromPresentable->decl,
                     idx: (const idIndex<short,enum invalidJointIndex_t> *)v15);
  }
  if ( v12 != nullptr )
    LODWORD(v19) = v12->name.str;
  else
    LODWORD(v19) = "none";
  v56 = this->aimTracker.maxYaw.value;
  HIDWORD(v19) = LODWORD(v56);
  LODWORD(v20) = this->curAnimatorIndex;
  LODWORD(v18) = data;
  HIDWORD(v20) = name;
  v21 = va::va(
          this: &v61,
          fmt: "%s: cur( %d ) max( %.1f ) htg( %s ) ref( %s ) t( %s )",
          a3: v20,
          a4: v19,
          a5: v18,
          a6: v38,
          a7: v41,
          a8: v44,
          a9: v47,
          a10: v50,
          a11: v53);
  idStr::idStr(this: &v60, text: v21);
  v22 = (float)(eyePos->z + offset->z);
  v23 = (float)(eyePos->y + offset->y);
  v58[0] = eyePos->x + offset->x;
  v59 = v22;
  v58[1] = v23;
  v24 = common->RW(this: common);
  ((void (__fastcall *)(idRenderWorld *, char *, float *, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))v24->DebugText)(
    a1: v24,
    a2: v60.data,
    a3: v58,
    a4: v24->__vftable,
    a5: &idColor::colorWhite,
    a6: 1,
    a7: 1,
    a8: 0,
    a9: 0.050000001);
  y = this->explicitOffset.y;
  x = this->explicitOffset.x;
  z = this->offset.z;
  v28 = this->offset.y;
  v57[0] = &this->offset;
  *(double *)&v29 = this->offset.x;
  v57[0] = HIDWORD(v28);
  v59 = v59 - (float)2.0;
  v30 = va::va(
          this: &v62,
          fmt: "%s: ofs( %.1f %.1f %.1f ) eofs( %.1f %.1f %.1f ) eofsa( %.1f %.1f %.1f )",
          a3: v29,
          a4: __SPAIR64__(LODWORD(v28), LODWORD(z)),
          a5: __SPAIR64__(LODWORD(x), LODWORD(y)),
          a6: v39,
          a7: v42,
          a8: v45,
          a9: v48,
          a10: v51,
          a11: v54);
  idStr::operator=(this: &v60, text: v30);
  v31 = common->RW(this: common);
  ((void (__fastcall *)(idRenderWorld *, char *, float *, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))v31->DebugText)(
    a1: v31,
    a2: v60.data,
    a3: v58,
    a4: v31->__vftable,
    a5: &idColor::colorWhite,
    a6: 1,
    a7: 1,
    a8: 0,
    a9: 0.050000001);
  declTrackingParms = this->declTrackingParms;
  v59 = v59 - (float)2.0;
  if ( declTrackingParms != nullptr )
    LODWORD(v35) = declTrackingParms->name.str;
  else
    LODWORD(v35) = "NULL";
  HIDWORD(v33) = this->trackingParmsIndex;
  HIDWORD(v35) = name;
  v36 = va::va(
          this: &v62,
          fmt: "%s: decl( %s ) idx: %d ",
          a3: v35,
          a4: v33,
          a5: v32,
          a6: v40,
          a7: v43,
          a8: v46,
          a9: v49,
          a10: v52,
          a11: v55);
  idStr::operator=(this: &v60, text: v36);
  v37 = common->RW(this: common);
  ((void (__fastcall *)(idRenderWorld *, char *, float *, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))v37->DebugText)(
    a1: v37,
    a2: v60.data,
    a3: v58,
    a4: v37->__vftable,
    a5: &idColor::colorWhite,
    a6: 1,
    a7: 1,
    a8: 0,
    a9: 0.050000001);
  idStr::FreeData(this: &v60);
}


// ========================================================================
// __unwind$489690
// EA  : 0x82A9D250
// RVA : 0x00A9D250
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void _unwind_489690()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8480 + 144));
}


// ========================================================================
// ?SetCurHeadTrackGroup@idFocusInfo@@QAAXPBVidAnimatedEntity@@H@Z
// EA  : 0x82A9D278
// RVA : 0x00A9D278
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::SetCurHeadTrackGroup(idFocusInfo *this, idAnimatedEntity *owner, int trackGroupIndex)
{
  idAnimator_TrackerBase *v4; // r3
  idMD6Branch *v7; // r30
  idMD6Branch *v8; // r29
  idAnimator_TrackerBase *v9; // r3

  v4 = this->animators[0];
  if ( v4 != nullptr
    && this->animators[1] != nullptr
    && this->animators[this->curAnimatorIndex]->trackGroupIndex != trackGroupIndex )
  {
    if ( !test
      || (v7 = v4->InternalGetMergeBranch_2(this: v4),
          v8 = this->animators[1]->InternalGetMergeBranch_2(this: this->animators[1]),
          v7 == nullptr)
      || (unsigned __int8)idMD6Branch::IsBlendFinished(this: v7) != 0
      || v8 == nullptr
      || (unsigned __int8)idMD6Branch::IsBlendFinished(this: v8) != 0 )
    {
      idFocusInfo::SwapTrackers(this, owner, blendTime: -1);
      v9 = this->animators[this->curAnimatorIndex];
      v9->SetReferenceJointOverride(this: v9, a2: (const idIndex<short,enum invalidJointIndex_t> *)-1);
      this->animators[this->curAnimatorIndex]->trackGroupIndex = trackGroupIndex;
    }
  }
}


// ========================================================================
// ?SetFocusEntity@idFocusInfo@@QAAXPAVidAnimatedEntity@@PBVidEntity@@_NW4aimPoint_t@@H@Z
// EA  : 0x82A9D390
// RVA : 0x00A9D390
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::SetFocusEntity(
        idFocusInfo *this,
        idAnimatedEntity *owner,
        idAnimatedEntity *_ent,
        bool _keepFocusInView,
        aimPoint_t _aimPoint,
        const int duration)
{
  idEntityPtr<idEntity const > *p_focusEntity; // r30
  idEntity *v9; // r3

  if ( this->animators[0] != nullptr && this->animators[1] != nullptr )
  {
    if ( _ent == owner )
    {
      idLib::Warning(fmt: "idFocusInfo::SetFocusEntity - AI '%s' told to focus on itself!", owner->name.data);
      this->hasExplicitFocusPoint = false;
      this->focusEntity.spawnId.value = 0x1FFF;
      this->keepFocusInView = false;
      this->aimPoint = AIMPOINT_EYELEVEL;
      this->focusTimeout = -1;
      this->focusType = AIFOCUS_NOTHING;
      this->offset = vec3_origin;
    }
    else
    {
      p_focusEntity = &this->focusEntity;
      this->hasExplicitFocusPoint = false;
      if ( _ent != nullptr )
        p_focusEntity->spawnId.value = (gameLocal->spawnIds.ptr[_ent->entityNumber] << 13) | _ent->entityNumber;
      else
        p_focusEntity->spawnId.value = 0x1FFF;
      this->keepFocusInView = _keepFocusInView;
      this->aimPoint = _aimPoint;
      this->focusType = AIFOCUS_ENTITY;
      if ( idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&this->focusEntity) != nullptr )
      {
        v9 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&this->focusEntity);
        v9->GetAimPoint(this: v9, a2: this->aimPoint, a3: &this->idealFocusPoint);
      }
      if ( duration == -1 )
        this->focusTimeout = -1;
      else
        this->focusTimeout = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                           + duration;
    }
  }
}


// ========================================================================
// ?Update@idFocusInfo@@QAAXPBVidAnimatedEntity@@PBVidAnimator_TrackerBase@@@Z
// EA  : 0x82A9D4F0
// RVA : 0x00A9D4F0
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __fastcall idFocusInfo::Update(idFocusInfo *this, idAI2 *owner, const idAnimator_TrackerBase *parentTracker)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idAI2 *v8; // r3
  idAI2 *v9; // r19
  idAnimator_TrackerBase *v10; // r3
  idMD6Branch *v11; // r29
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v14; // r29
  float y; // r6
  float z; // r5
  int v17; // r8
  BOOL lockTracking; // r4
  idAnimator_TrackerBase *v19; // r28
  aiFoci_t fociType; // r10
  int trackingParmsIndex; // r11
  idCVar *v22; // r9
  const idDeclTrackingParms *declTrackingParms; // r9
  trackingParms_t *list; // r9
  idAnimator_TrackerBase_vtbl *v25; // r8
  float *p_kickScale; // r11
  void (__fastcall *GetWorldSpaceFrameOfReference)(idAnimator_TrackerBase *, const idAnimator_TrackerBase *, const idTreeAnimator *, idVec3 *, idMat3 *); // ctr
  idMat3 *v28; // r3
  idMat3 *p_wsReferenceAxis; // r29
  double v30; // fp5
  double v31; // fp2
  idPhysics *Physics; // r3
  idBounds *v33; // r3
  double RadiusXY; // fp1
  idPhysics *v35; // r3
  const idVec3 *v36; // r3
  double v37; // fp31
  double v38; // fp13
  double v39; // fp12
  float v40; // r9
  float v41; // r7
  idVec3 *v42; // r7
  double v43; // fp13
  double v44; // fp12
  int v45; // r27
  int valueInteger; // r11
  __int64 v47; // r9
  aiFoci_t v48; // r7
  double v49; // fp7
  double v50; // fp6
  double v51; // fp5
  double v52; // fp4
  double v53; // fp0
  double v54; // fp7
  double v55; // fp6
  double v56; // fp4
  double v57; // fp3
  idRenderWorld *v58; // r3
  aiFoci_t v59; // r6
  idWeapon *EquippedWeapon; // r4
  aiFoci_t v61; // r11
  const char *v62; // r5
  idVec3 v63; // [sp+50h] [-250h] BYREF
  idVec3 v64; // [sp+60h] [-240h] BYREF
  idTypesafeNumber<float,enum DegreesUnique_t> v65; // [sp+6Ch] [-234h] BYREF
  idVec3 v66; // [sp+70h] [-230h] BYREF
  idVec3 v67; // [sp+80h] [-220h] BYREF
  __int64 v68; // [sp+90h] [-210h] BYREF
  idPLogScope v69; // [sp+98h] [-208h] BYREF
  float x; // [sp+A0h] [-200h] BYREF
  float v71; // [sp+A4h] [-1FCh]
  float v72; // [sp+A8h] [-1F8h]
  idRotationTrackerRange v73; // [sp+B0h] [-1F0h] BYREF
  idTypesafeNumber<float,enum DegreesUnique_t> v74; // [sp+C0h] [-1E0h] BYREF
  idTypesafeNumber<float,enum DegreesUnique_t> v75; // [sp+C4h] [-1DCh] BYREF
  idVec3 v76; // [sp+C8h] [-1D8h] BYREF
  idVec3 v77; // [sp+D8h] [-1C8h] BYREF
  float v78[6]; // [sp+F0h] [-1B0h] BYREF
  float v79[6]; // [sp+108h] [-198h] BYREF
  idColor v80; // [sp+120h] [-180h] BYREF
  idColor v81; // [sp+130h] [-170h] BYREF
  idMat3 v82; // [sp+140h] [-160h] BYREF
  int v83; // [sp+168h] [-138h] BYREF
  idMat3 v84; // [sp+180h] [-120h] BYREF
  int v85; // [sp+1B0h] [-F0h] BYREF
  idMat3 v86[2]; // [sp+1E0h] [-C0h] BYREF

  RD_EventBegin(name: "idFocusInfo::Update");
  LODWORD(v6) = "idFocusInfo::Update";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: &v69, pl: &pLog, gMask: v6, label: v7);
  if ( this->animators[0] == nullptr || this->animators[1] == nullptr )
    goto _M490607;
  v8 = idAI2::CastTo(c: owner);
  v9 = v8;
  if ( v8 != nullptr
    && (v8->IsDead(this: v8) || v9->IsDying(this: v9))
    && v9->aiVolatile.death.goreComponent.goredPiecesInUse.num > 0 )
  {
    goto _M490607;
  }
  v10 = this->animators[this->curAnimatorIndex];
  v11 = v10->InternalGetMergeBranch_2(this: v10);
  if ( (unsigned __int8)idFocusInfo::HasFocus(this) != 0 && this->enableTracking && !this->suppressTracking )
  {
    if ( v11->currentAlpha < 1.0 && (unsigned __int8)idMD6Branch::IsBlendingIn(this: v11) == 0 )
      idFocusInfo::BlendIn(this, owner, blendTime: -1);
  }
  else if ( v11->currentAlpha > 0.0 && (unsigned __int8)idMD6Branch::IsBlendingOut(this: v11) == 0 )
  {
    idFocusInfo::BlendOut(this, owner, blendTime: -1);
  }
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: owner);
  presentable = owner->presentable;
  v14 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: owner);
    presentable = owner->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( this->declTrackingParms == nullptr )
    goto _M490607;
  v73.minYaw = 0.0;
  v73.maxYaw = 0.0;
  v73.minPitch = 0.0;
  v73.maxPitch = 0.0;
  idRotationTracker::GetConstraints(this: &this->aimTracker, range: &v73);
  y = this->offset.y;
  z = this->offset.z;
  v17 = 4 * (this->curAnimatorIndex + 54);
  lockTracking = this->lockTracking;
  v66.x = this->offset.x;
  v66.y = y;
  v66.z = z;
  v19 = *(idAnimator_TrackerBase **)((char *)&this->wanderingAim.error.x + v17);
  if ( !lockTracking )
  {
    fociType = this->fociType;
    trackingParmsIndex = this->trackingParmsIndex;
    if ( fociType != AIFOCI_AIM )
    {
      if ( fociType != AIFOCI_LOOK )
      {
LABEL_27:
        declTrackingParms = this->declTrackingParms;
        if ( trackingParmsIndex >= 0 )
        {
          if ( trackingParmsIndex > declTrackingParms->parms.num - 1 )
            trackingParmsIndex = declTrackingParms->parms.num - 1;
        }
        else
        {
          trackingParmsIndex = 0;
        }
        list = declTrackingParms->parms.list;
        v25 = v19->__vftable;
        HIDWORD(v68) = &this->aimTracker.curParms;
        p_kickScale = &list[trackingParmsIndex].kickScale;
        GetWorldSpaceFrameOfReference = v25->GetWorldSpaceFrameOfReference;
        this->aimTracker.curParms.kickScale = *p_kickScale;
        this->aimTracker.curParms.rate.value = p_kickScale[1];
        this->aimTracker.curParms.acceleration.value = p_kickScale[2];
        this->aimTracker.curParms.deceleration.value = p_kickScale[3];
        this->aimTracker.curParms.springMass = p_kickScale[4];
        this->aimTracker.curParms.springTightness = p_kickScale[5];
        this->aimTracker.curParms.springDampen = p_kickScale[6];
        this->aimTracker.curParms.springMaxSpeed = p_kickScale[7];
        this->aimTracker.curParms.springRestLength = p_kickScale[8];
        this->aimTracker.curParms.springMaxLength = p_kickScale[9];
        GetWorldSpaceFrameOfReference(this: v19, a2: parentTracker, a3: v14, a4: &v64, a5: (idMat3 *)&v85);
        v19->GetModelSpaceFrameOfReference(this: v19, a2: parentTracker, a3: v14, a4: (idVec3 *)&v83, a5: &v84);
        v28 = idMat3::operator*(this: v86, result: &v84, a: &v14->g.axis);
        this->wsReferenceAxis.mat[0].x = v28->mat[0].x;
        p_wsReferenceAxis = &this->wsReferenceAxis;
        this->wsReferenceAxis.mat[0].y = v28->mat[0].y;
        this->wsReferenceAxis.mat[0].z = v28->mat[0].z;
        LODWORD(v65.value) = (idTypesafeNumber<float,enum DegreesUnique_t>)&v28->mat[1];
        this->wsReferenceAxis.mat[1].x = v28->mat[1].x;
        LODWORD(v65.value) = (idTypesafeNumber<float,enum DegreesUnique_t>)&this->wsReferenceAxis.mat[1];
        this->wsReferenceAxis.mat[1].y = v28->mat[1].y;
        LODWORD(v65.value) = (idTypesafeNumber<float,enum DegreesUnique_t>)&this->wsReferenceAxis.mat[2];
        this->wsReferenceAxis.mat[1].z = v28->mat[1].z;
        this->wsReferenceAxis.mat[2] = v28->mat[2];
        v30 = (float)(this->idealFocusPoint.z - v64.z);
        v31 = (float)(this->idealFocusPoint.y - v64.y);
        v63.x = this->idealFocusPoint.x - v64.x;
        v63.y = v31;
        v63.z = v30;
        Physics = idEntity::GetPhysics(this: owner);
        v33 = (idBounds *)Physics->GetBounds(this: Physics, a2: -1);
        RadiusXY = idBounds::GetRadiusXY(this: v33);
        if ( this->fociType == AIFOCI_AIM
          && (float)((float)(v63.x * v63.x) + (float)((float)(v63.z * v63.z) + (float)(v63.y * v63.y))) < (double)(float)((float)((float)RadiusXY * (float)1.5) * (float)((float)RadiusXY * (float)1.5)) )
        {
          v35 = idEntity::GetPhysics(this: owner);
          v36 = v35->GetGravityNormal(this: v35);
          idVec3::ProjectOntoPlane(this: &v63, normal: v36, overBounce: 1.0);
          v66.z = 0.0;
          v66.y = 0.0;
          v66.x = 0.0;
        }
        v37 = idVec3::NormalizeFast(this: &v63);
        if ( v37 < 0.000099999997 )
        {
          v37 = 32.0;
          v38 = this->wsReferenceAxis.mat[0].y;
          v39 = this->wsReferenceAxis.mat[0].z;
          v63.x = p_wsReferenceAxis->mat[0].x;
          v63.y = v38;
          v63.z = v39;
        }
        if ( v9 != nullptr && this->fociType == AIFOCI_AIM )
        {
          v40 = this->idealFocusPoint.y;
          v41 = this->idealFocusPoint.z;
          x = this->idealFocusPoint.x;
          v71 = v40;
          v72 = v41;
          if ( ai_useWanderingAim.valueInteger != 0 && idAI2::GetEffectiveAccuracy(this: v9) != ACCURACY_PERFECT )
            idWanderingAim::Update(
              this: &this->wanderingAim,
              ai: v9,
              eyePos: &v64,
              dirToTarget: &v63,
              distToTarget: v37,
              newFocusPoint: v42,
              showDebug: (const bool)&x);
          v63.x = x - v64.x;
          v63.z = v72 - v64.z;
          v63.y = v71 - v64.y;
          v37 = idVec3::NormalizeFast(this: &v63);
          if ( v37 < 0.0000099999997 )
          {
            v37 = 32.0;
            v43 = this->wsReferenceAxis.mat[0].y;
            v44 = this->wsReferenceAxis.mat[0].z;
            v63.x = p_wsReferenceAxis->mat[0].x;
            v63.y = v43;
            v63.z = v44;
          }
        }
        v45 = 0;
        valueInteger = ai_debugAimRotationTracker.valueInteger;
        if ( ai_debugAimRotationTracker.valueInteger != 0 && this->fociType == AIFOCI_AIM
          || (valueInteger = ai_debugLookRotationTracker.valueInteger, ai_debugLookRotationTracker.valueInteger != 0)
          && this->fociType == AIFOCI_LOOK )
        {
          v45 = valueInteger;
        }
        LODWORD(v47) = gameLocal->GetGameHz(this: gameLocal, a2: GAMETIME_SCALED);
        HIDWORD(v47) = this->aimTracker.__vftable;
        v48 = this->fociType;
        v68 = v47;
        (*(void (__fastcall **)(idAimTracker *, idVec3 *, idMat3 *, idVec3 *, aiFoci_t, bool, int, double))(HIDWORD(v47) + 4))(
          a1: &this->aimTracker,
          a2: &v64,
          a3: &this->wsReferenceAxis,
          a4: &v63,
          a5: v48,
          a6: (_cntlzw(v48) & 0x20) != 0,
          a7: v45,
          a8: (float)((float)v47 * (float)0.001));
        idRotationTracker::GetWorldSpaceDir(this: &this->aimTracker, refAxis: &this->wsReferenceAxis, wsDir: &v77);
        v49 = (float)(v77.z * (float)v37);
        v50 = (float)(v77.y * (float)v37);
        v51 = v64.z;
        v52 = v64.y;
        this->curFocusPoint.x = (float)(v77.x * (float)v37) + v64.x;
        this->curFocusPoint.z = (float)v51 + (float)v49;
        this->curFocusPoint.y = (float)v52 + (float)v50;
        goto LABEL_49;
      }
      v22 = &ai_lookRate;
    }
    else
    {
      v22 = &ai_accuracy;
    }
    if ( v22->valueInteger >= 0 )
      trackingParmsIndex = v22->valueInteger;
    goto LABEL_27;
  }
LABEL_49:
  v53 = this->curFocusPoint.z;
  v54 = (float)(this->curFocusPoint.y + v66.y);
  v55 = (float)(v66.x + this->curFocusPoint.x);
  HIDWORD(v68) = &this->explicitOffset;
  v56 = this->explicitOffset.y;
  v57 = this->explicitOffset.x;
  v76.z = this->explicitOffset.z + (float)((float)v53 + v66.z);
  v76.y = (float)v56 + (float)v54;
  v76.x = (float)v55 + (float)v57;
  if ( idAnimator_Base::IsContributing(this: v19) )
  {
    v65.value = v73.maxYaw;
    v74.value = v73.minYaw;
    v75.value = v73.maxPitch;
    *(float *)&v68 = v73.minPitch;
    idAnimator_TrackerBase::Update(
      this: v19,
      parentTracker_: parentTracker,
      focusPoint_: &v76,
      offsetAngles_: &this->explicitOffsetAngles,
      pitchUp: (const idTypesafeNumber<float,enum DegreesUnique_t> *)&v68,
      pitchDown: &v75,
      yawRight: &v74,
      yawLeft: &v65);
  }
  if ( ai_debugLevel.valueInteger > 0 )
  {
    if ( ai_debugAim.valueInteger >= 2 && this->fociType == AIFOCI_AIM
      || ai_debugLook.valueInteger >= 2 && this->fociType == AIFOCI_LOOK )
    {
      v58 = gameLocal->GetRenderWorld(this: gameLocal);
      ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, idVec3 *, double))v58->DebugArrow)(
        a1: v58,
        a2: &idColor::colorOrange,
        a3: &v64,
        a4: &v76,
        a5: 2.0);
      v78[3] = 8.0;
      v78[4] = 8.0;
      v59 = this->fociType;
      v78[5] = 8.0;
      v67 = v64;
      v78[0] = -8.0;
      v78[1] = -8.0;
      v78[2] = -8.0;
      if ( v59 != AIFOCI_AIM )
      {
        v81 = idColor::colorMagenta;
        v80 = idColor::colorPink;
      }
      else
      {
        v81 = idColor::colorOrange;
        v80 = idColor::colorYellow;
        if ( v9 != nullptr )
        {
          EquippedWeapon = idActor::GetEquippedWeapon(this: v9, slot: EQUIP_RIGHT_HAND);
          if ( EquippedWeapon != nullptr )
          {
            idAI2::GetMuzzlePoint(this: v9, weapon: EquippedWeapon, muzzlePos: &v67, muzzleAxis: &v82);
            v79[1] = v67.y + (float)(v82.mat[0].y * (float)32.0);
            v79[2] = v67.z + (float)(v82.mat[0].z * (float)32.0);
            v79[0] = v67.x + (float)(v82.mat[0].x * (float)32.0);
            ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
              a1: clientGame->renderWorld,
              a2: &idColor::colorRed,
              a3: &v67,
              a4: v79,
              a5: 5.0);
          }
        }
      }
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&v81,
        a3: &v67,
        a4: &this->idealFocusPoint,
        a5: 1,
        a6: true);
      clientGame->renderWorld->DebugBounds(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&v81,
        a3: (const idBounds *)v78,
        a4: &this->idealFocusPoint,
        a5: 0,
        a6: true);
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&v80,
        a3: &v67,
        a4: &this->curFocusPoint,
        a5: 1,
        a6: true);
      clientGame->renderWorld->DebugBounds(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&v80,
        a3: (const idBounds *)v78,
        a4: &this->curFocusPoint,
        a5: 0,
        a6: true);
    }
    if ( ai_debugTracking.valueInteger > 0 )
    {
      v61 = this->fociType;
      if ( v61 == AIFOCI_AIM )
      {
        v66.z = 8.0;
        v62 = "aim";
        goto LABEL_67;
      }
      if ( v61 == AIFOCI_LOOK )
      {
        v66.z = 2.0;
        v62 = "look";
LABEL_67:
        v66.x = 0.0;
        v66.y = 0.0;
        idFocusInfo::ShowTrackingInfo(this, owner, name: v62, eyePos: &v64, offset: &v66);
      }
    }
  }
_M490607:
  idPLogScope::~idPLogScope(this: &v69);
  RD_EventEnd();
}


// ========================================================================
// __unwind$490160
// EA  : 0x82A9DFF4
// RVA : 0x00A9DFF4
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void _unwind_490160()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 672 + 516));
}


// ========================================================================
// __unwind$490161
// EA  : 0x82A9E01C
// RVA : 0x00A9E01C
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void _unwind_490161()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 672 + 152));
}


// ========================================================================
// `dynamic initializer for 'ai_debugAimRotationTracker''
// EA  : 0x833691E8
// RVA : 0x013691E8
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugAimRotationTracker__()
{
  idCVar::idCVar(
    this: &ai_debugAimRotationTracker,
    name: "ai_debugAimRotationTracker",
    value: "0",
    flags: 2,
    description: "set to 1 to show debugging output for the aim focus idRotationTracker",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugAimRotationTracker__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugLookRotationTracker''
// EA  : 0x83369240
// RVA : 0x01369240
// PDB : w:\tech5\tungsten\game\ai\focusinfo.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugLookRotationTracker__()
{
  idCVar::idCVar(
    this: &ai_debugLookRotationTracker,
    name: "ai_debugLookRotationTracker",
    value: "0",
    flags: 2,
    description: "set to 1 to show debugging output for the look focus idRotationTracker",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugLookRotationTracker__);
}

