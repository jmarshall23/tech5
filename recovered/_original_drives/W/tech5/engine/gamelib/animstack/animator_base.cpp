
// ========================================================================
// ??1idAnimator_Base@@UAA@XZ
// EA  : 0x826DC218
// RVA : 0x006DC218
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

void __fastcall idAnimator_Base::~idAnimator_Base(idAnimator_Base *this)
{
  this->__vftable = (idAnimator_Base_vtbl *)&idAnimator_Base::`vftable';
}


// ========================================================================
// ?InternalPostInit@idAnimator_Base@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826DC228
// RVA : 0x006DC228
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

int __fastcall idAnimator_Base::InternalPostInit(idAnimator_Base *this, const idAnimatorParms_Base *parms)
{
  if ( parms->animStack == nullptr )
    return 0;
  idAnimStack::SetAnimatorFlag(this: parms->animStack, animator: this, flag: ANIMATORFLAG_SERIALIZE);
  return 1;
}


// ========================================================================
// ?Shutdown@idAnimator_Base@@QAAXPAVidAnimStack@@@Z
// EA  : 0x826DC278
// RVA : 0x006DC278
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

void __fastcall idAnimator_Base::Shutdown(idAnimator_Base *this, idAnimStack *stack)
{
  ((void (__fastcall *)(idAnimator_Base *))this->InternalShutdown)(a1: this);
  idAnimStack::ClearAnimatorFlag(this: stack, animator: this, flag: ANIMATORFLAG_INITIALIZED);
  idAnimStack::RemoveAnimator(this: stack, animator: this);
}


// ========================================================================
// ?IsInitialized@idAnimator_Base@@QBA_NPAVidAnimStack@@@Z
// EA  : 0x826DC2D8
// RVA : 0x006DC2D8
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

BOOL __fastcall idAnimator_Base::IsInitialized(idAnimator_Base *this, idAnimStack *animStack)
{
  return animStack != nullptr
      && idAnimStack::IsAnimatorFlagSet(this: animStack, animator: this, flag: ANIMATORFLAG_INITIALIZED);
}


// ========================================================================
// ?IsEnabled@idAnimator_Base@@QBA_NPAVidAnimStack@@@Z
// EA  : 0x826DC300
// RVA : 0x006DC300
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

BOOL __fastcall idAnimator_Base::IsEnabled(idAnimator_Base *this, idAnimStack *animStack)
{
  return animStack != nullptr
      && idAnimStack::IsAnimatorFlagSet(this: animStack, animator: this, flag: ANIMATORFLAG_ENABLED);
}


// ========================================================================
// ?SetEnabled@idAnimator_Base@@QAAXPAVidAnimStack@@_N@Z
// EA  : 0x826DC328
// RVA : 0x006DC328
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

void __fastcall idAnimator_Base::SetEnabled(idAnimator_Base *this, idAnimStack *animStack, const bool enabled)
{
  if ( enabled )
    idAnimStack::SetAnimatorFlag(this: animStack, animator: this, flag: ANIMATORFLAG_ENABLED);
  else
    idAnimStack::ClearAnimatorFlag(this: animStack, animator: this, flag: ANIMATORFLAG_ENABLED);
}


// ========================================================================
// ??0idAnimator_Base@@QAA@XZ
// EA  : 0x826DC350
// RVA : 0x006DC350
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

idAnimator_Base *__fastcall idAnimator_Base::idAnimator_Base(idAnimator_Base *this)
{
  this->__vftable = (idAnimator_Base_vtbl *)&idAnimator_Base::`vftable';
  this->gametimeManager.gameTimeManager = nullptr;
  this->weightGroup = MD6_WEIGHTGROUP_ALL;
  this->filterGroup = MD6_WEIGHTGROUP_ALL;
  this->serializeProps.serializedTrees[0] = nullptr;
  this->serializeProps.serializedTrees[1] = nullptr;
  this->serializeProps.animStack = nullptr;
  this->serializeProps.clip = nullptr;
  this->serializeProps.createdThroughSerialization = false;
  this->initialized = false;
  return this;
}


// ========================================================================
// ?Init@idAnimator_Base@@QAA_NPAVidGameTimeManager@@ABVidAnimatorParms_Base@@@Z
// EA  : 0x826DC3E0
// RVA : 0x006DC3E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

int __fastcall idAnimator_Base::Init(
        idAnimator_Base *this,
        idGameTimeManager *gametimeManager,
        const idAnimatorParms_Base *parms)
{
  idAnimator_Base_vtbl *v6; // r11
  __int64 v8; // r8
  idMD6Branch *v9; // r3
  __int64 v10; // r10
  __int64 v11; // r6
  idAnimator_Base_vtbl *v12; // r10
  int v13; // [sp+8h] [-1068h]
  int v14; // [sp+Ch] [-1064h]
  int v15; // [sp+10h] [-1060h]
  int v16; // [sp+14h] [-105Ch]
  int v17; // [sp+18h] [-1058h]
  int v18; // [sp+1Ch] [-1054h]
  va v19; // [sp+50h] [-1020h] BYREF

  if ( idAnimStack::GetAnimatorIndex(this: parms->animStack, animator: this) >= 0 && this->initialized )
    idLib::Error(fmt: "Attempted to add idAnimator %s twice.", parms->name.data);
  this->gametimeManager.gameTimeManager = gametimeManager;
  v6 = this->__vftable;
  this->weightGroup = parms->weightGroup;
  this->filterGroup = parms->filterGroup;
  if ( !v6->InternalInit(this, a2: parms) )
    return 0;
  v9 = this->InternalGetMergeBranch_2(this);
  if ( v9 != nullptr )
  {
    HIDWORD(v10) = 0x82000000;
    LODWORD(v8) = "_AI_OBSTACLE";
    v9->op = parms->blendOp;
    LODWORD(v11) = parms->originBlend;
    v9->originBlend = v11;
    v9->currentAlpha = parms->alpha;
    v9->targetAlpha = parms->alpha;
    v9->alphaRate = 0.0;
    LODWORD(v10) = parms->filterGroup;
    v9->filterGroup = v10;
    HIDWORD(v11) = parms->name.data;
    va::va(
      this: &v19,
      fmt: "%s_merge",
      a3: v11,
      a4: v8,
      a5: v10,
      a6: v13,
      a7: v14,
      a8: v15,
      a9: v16,
      a10: v17,
      a11: v18);
  }
  idAnimStack::AddAnimator(this: parms->animStack, animator: this);
  idAnimStack::SetAnimatorFlag(this: parms->animStack, animator: this, flag: ANIMATORFLAG_INITIALIZED);
  idAnimStack::SetAnimatorFlag(this: parms->animStack, animator: this, flag: ANIMATORFLAG_ENABLED);
  v12 = this->__vftable;
  this->initialized = true;
  return ((int (__fastcall *)(idAnimator_Base *, const idAnimatorParms_Base *))v12->InternalPostInit)(
           a1: this,
           a2: parms);
}


// ========================================================================
// ?Blend@idAnimator_Base@@QAAXPBVidAnimStack@@HMH_N@Z
// EA  : 0x826DC530
// RVA : 0x006DC530
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

void __fastcall idAnimator_Base::Blend(
        idAnimator_Base *this,
        const idAnimStack *stack,
        int curTime,
        double targetAlpha,
        const int blendDurationMS,
        int reset,
        char a7)
{
  idMD6Branch *v13; // r31
  idGameTimeManager *gameTimeManager; // r4
  bool IsBlendingOut; // r3
  __int64 v16; // r11
  double v17; // fp13
  idAnimator_Base_vtbl *v18; // r10
  int v19; // [sp+50h] [-50h] BYREF
  __int64 v20; // [sp+58h] [-48h] BYREF

  v13 = this->InternalGetMergeBranch_2(this);
  HIDWORD(v20) = reset;
  gameTimeManager = this->gametimeManager.gameTimeManager;
  v13->targetAlpha = targetAlpha;
  idGameTimeManager::ConvertTimeRealToGame(
    this: (idGameTimeManager *)&v19,
    result: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)gameTimeManager,
    ms: (idTypesafeNumber<int,enum millisecondUnique_t> *)&v20);
  if ( targetAlpha <= v13->currentAlpha )
    IsBlendingOut = idMD6Branch::IsBlendingOut(this: v13);
  else
    IsBlendingOut = idMD6Branch::IsBlendingIn(this: v13);
  LODWORD(v16) = v19;
  if ( v19 <= 0 )
  {
    v13->currentAlpha = targetAlpha;
    v13->alphaRate = 0.0;
  }
  else if ( a7 != 0 || !IsBlendingOut )
  {
    v17 = (float)((float)targetAlpha - v13->currentAlpha);
    HIDWORD(v16) = &unk_82150000;
    v20 = v16;
    v13->alphaRate = (float)__fabs(v17) * (float)((float)1000.0 / (float)v16);
  }
  v18 = this->__vftable;
  HIDWORD(v20) = v19;
  ((void (__fastcall *)(idAnimator_Base *, const idAnimStack *, const int, double))v18->InternalBlend)(
    a1: this,
    a2: stack,
    a3: curTime,
    a4: targetAlpha);
}


// ========================================================================
// ?IsContributing@idAnimator_Base@@QBA_NXZ
// EA  : 0x826DC648
// RVA : 0x006DC648
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

BOOL __fastcall idAnimator_Base::IsContributing(idAnimator_Base *this)
{
  const idMD6Branch *v2; // r3
  idMD6Branch *v3; // r31
  idMD6Node *right; // r3

  v2 = this->InternalGetMergeBranch(this);
  v3 = (idMD6Branch *)v2;
  return v2 != nullptr
      && (right = v2->right) != nullptr
      && idMD6Node::IsValid(this: right)
      && (v3->currentAlpha > 0.0 || !idMD6Branch::IsBlendFinished(this: v3))
      && this->InternalIsContributing(this);
}


// ========================================================================
// ?GetFilterGroup@idAnimator_Base@@QBA?AW4md6WeightGroup_t@@XZ
// EA  : 0x826DC6F8
// RVA : 0x006DC6F8
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

md6WeightGroup_t __fastcall idAnimator_Base::GetFilterGroup(idAnimator_Base *this)
{
  return this->InternalGetMergeBranch(this)->filterGroup;
}


// ========================================================================
// ?GetAlpha@idAnimator_Base@@QBAMXZ
// EA  : 0x826DC728
// RVA : 0x006DC728
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

float __fastcall idAnimator_Base::GetAlpha(idAnimator_Base *this)
{
  double currentAlpha; // fp1

  currentAlpha = this->InternalGetMergeBranch(this)->currentAlpha;
  return *((float *)&currentAlpha + 1);
}


// ========================================================================
// ?SetAlpha@idAnimator_Base@@QAAXM@Z
// EA  : 0x826DC758
// RVA : 0x006DC758
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

void __fastcall idAnimator_Base::SetAlpha(idAnimator_Base *this, double alpha)
{
  this->InternalGetMergeBranch_2(this)->currentAlpha = alpha;
}


// ========================================================================
// ?Pause@idAnimator_Base@@QAAXPBVidAnimStack@@V?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x826DC798
// RVA : 0x006DC798
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

void __fastcall idAnimator_Base::Pause(
        idAnimator_Base *this,
        const idAnimStack *stack,
        const idTypesafeNumber<int,enum gameTimeUnique_t> *curTime)
{
  idAnimator_Base_vtbl *v3; // r10
  int value; // [sp+50h] [-10h] BYREF

  v3 = this->__vftable;
  value = curTime->value;
  v3->InternalPause(this, a2: stack, a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&value);
}


// ========================================================================
// ?Unpause@idAnimator_Base@@QAAXPBVidAnimStack@@V?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x826DC7D0
// RVA : 0x006DC7D0
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

void __fastcall idAnimator_Base::Unpause(
        idAnimator_Base *this,
        const idAnimStack *stack,
        const idTypesafeNumber<int,enum gameTimeUnique_t> *curTime)
{
  idAnimator_Base_vtbl *v3; // r10
  int value; // [sp+50h] [-10h] BYREF

  v3 = this->__vftable;
  value = curTime->value;
  v3->InternalUnpause(this, a2: stack, a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&value);
}


// ========================================================================
// ?Start@idAnimator_Base@@QAAXPBVidAnimStack@@HH_N@Z
// EA  : 0x826DC808
// RVA : 0x006DC808
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

void __fastcall idAnimator_Base::Start(
        idAnimator_Base *this,
        const idAnimStack *stack,
        int curTime,
        const int blendDurationMS,
        const bool reset)
{
  idMD6Branch *v10; // r3
  idMD6Branch *v11; // r30
  __int64 v12; // r5
  double currentAlpha; // fp13
  __int64 v14; // r7
  idAnimator_Base_vtbl *v15; // r10
  int v16; // [sp+50h] [-40h] BYREF
  _QWORD v17[7]; // [sp+58h] [-38h] BYREF

  v10 = this->InternalGetMergeBranch_2(this);
  HIDWORD(v17[0]) = blendDurationMS;
  v11 = v10;
  idGameTimeManager::ConvertTimeRealToGame(
    this: (idGameTimeManager *)&v16,
    result: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)this->gametimeManager.gameTimeManager,
    ms: (idTypesafeNumber<int,enum millisecondUnique_t> *)v17);
  if ( v16 <= 0 )
  {
    v11->currentAlpha = 1.0;
    v11->targetAlpha = 1.0;
    v11->alphaRate = 0.0;
  }
  else if ( reset || !idMD6Branch::IsBlendingIn(this: v11) )
  {
    currentAlpha = v11->currentAlpha;
    v11->targetAlpha = 1.0;
    HIDWORD(v14) = v16;
    LODWORD(v14) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
    LODWORD(v12) = v16;
    v17[0] = v12;
    v11->alphaRate = (float)((float)1.0 - (float)currentAlpha) * (float)((float)v14 / (float)v12);
  }
  v15 = this->__vftable;
  HIDWORD(v17[0]) = v16;
  v15->InternalStart(this, a2: stack, a3: curTime, a4: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)v17);
}


// ========================================================================
// ?End@idAnimator_Base@@QAAXPBVidAnimStack@@HH_N@Z
// EA  : 0x826DC930
// RVA : 0x006DC930
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.cpp
// ========================================================================

void __fastcall idAnimator_Base::End(
        idAnimator_Base *this,
        const idAnimStack *stack,
        int curTime,
        const int blendDurationMS,
        const bool reset)
{
  idMD6Branch *v10; // r3
  idMD6Branch *v11; // r30
  __int64 v12; // r8
  __int64 v13; // r6
  double v14; // fp6
  idAnimator_Base_vtbl *v15; // r10
  int v16; // [sp+50h] [-50h] BYREF
  _QWORD v17[2]; // [sp+58h] [-48h] BYREF

  if ( this->initialized )
  {
    v10 = this->InternalGetMergeBranch_2(this);
    HIDWORD(v17[0]) = blendDurationMS;
    v11 = v10;
    v10->targetAlpha = 0.0;
    idGameTimeManager::ConvertTimeRealToGame(
      this: (idGameTimeManager *)&v16,
      result: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)this->gametimeManager.gameTimeManager,
      ms: (idTypesafeNumber<int,enum millisecondUnique_t> *)v17);
    if ( v16 <= 0 )
    {
      v11->alphaRate = 0.0;
      v11->currentAlpha = 0.0;
    }
    else if ( reset || !idMD6Branch::IsBlendingOut(this: v11) )
    {
      LODWORD(v12) = v16;
      LODWORD(v13) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
      v14 = (float)((float)((float)v13 / (float)v12) * v11->currentAlpha);
      v17[0] = v13;
      v11->alphaRate = v14;
    }
    v15 = this->__vftable;
    HIDWORD(v17[0]) = v16;
    v15->InternalEnd(this, a2: stack, a3: curTime, a4: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)v17);
  }
}

