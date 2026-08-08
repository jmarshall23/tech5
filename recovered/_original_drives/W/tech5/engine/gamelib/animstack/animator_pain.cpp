
// ========================================================================
// ??0idAnimator_Pain@@QAA@XZ
// EA  : 0x826E8998
// RVA : 0x006E8998
// PDB : w:\tech5\engine\gamelib\animstack\animator_pain.cpp
// ========================================================================

idAnimator_Pain *__fastcall idAnimator_Pain::idAnimator_Pain(idAnimator_Pain *this)
{
  idAnimator_Channel::idAnimator_Channel(this);
  this->__vftable = (idAnimator_Pain_vtbl *)&idAnimator_Pain::`vftable';
  return this;
}


// ========================================================================
// ??1idAnimator_Pain@@UAA@XZ
// EA  : 0x826E89D8
// RVA : 0x006E89D8
// PDB : w:\tech5\engine\gamelib\animstack\animator_pain.cpp
// ========================================================================

void __fastcall idAnimator_Pain::~idAnimator_Pain(idAnimator_Pain *this)
{
  this->__vftable = (idAnimator_Pain_vtbl *)&idAnimator_Pain::`vftable';
  idAnimator_Channel::~idAnimator_Channel(this);
}


// ========================================================================
// ?InternalPostInit@idAnimator_Pain@@UAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826E89E8
// RVA : 0x006E89E8
// PDB : w:\tech5\engine\gamelib\animstack\animator_pain.cpp
// ========================================================================

int __fastcall idAnimator_Pain::InternalPostInit(idAnimator_Pain *this, const idAnimatorParms_Base *parms)
{
  if ( parms->animStack == nullptr )
    return 0;
  idAnimStack::ClearAnimatorFlag(this: parms->animStack, animator: this, flag: ANIMATORFLAG_SERIALIZE);
  return 1;
}


// ========================================================================
// ?PreSerializeInit@idAnimator_Pain@@UAAXPAVidAnimStack@@PAVidClip@@PAVidGameTimeManager@@@Z
// EA  : 0x826E8AB0
// RVA : 0x006E8AB0
// PDB : w:\tech5\engine\gamelib\animstack\animator_pain.cpp
// ========================================================================

void __fastcall idAnimator_Pain::PreSerializeInit(
        idAnimator_Pain *this,
        idAnimStack *animStack_,
        idClip *clip_,
        idGameTimeManager *gametimeManager)
{
  idAnimatorParms_Base v7; // [sp+60h] [-60h] BYREF

  this->serializeProps.animStack = animStack_;
  this->serializeProps.clip = clip_;
  this->gametimeManager.gameTimeManager = gametimeManager;
  v7.animStack = animStack_;
  this->serializeProps.createdThroughSerialization = true;
  idStr::idStr(this: &v7.name, text: "pain");
  memset(&v7.originBlend, 0, 12);
  v7.blendOp = BOP_ADD_RIGHT;
  v7.alpha = 1.0;
  idAnimator_Base::Init(this, gametimeManager, parms: &v7);
  idAnimStack::ClearAnimatorFlag(this: animStack_, animator: this, flag: ANIMATORFLAG_SERIALIZE);
  idStr::FreeData(this: &v7.name);
}


// ========================================================================
// __unwind$245660
// EA  : 0x826E8B50
// RVA : 0x006E8B50
// PDB : w:\tech5\engine\gamelib\animstack\animator_pain.cpp
// ========================================================================

void _unwind_245660()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 192 + 96));
}

