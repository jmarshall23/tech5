
// ========================================================================
// ?PreSerializeInit@idAnimator_Base@@UAAXPAVidAnimStack@@PAVidClip@@PAVidGameTimeManager@@@Z
// EA  : 0x826CC460
// RVA : 0x006CC460
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.h
// ========================================================================

void __fastcall idAnimator_Base::PreSerializeInit(
        idAnimator_Base *this,
        idAnimStack *animStack_,
        idClip *clip_,
        idGameTimeManager *gametimeManager)
{
  this->serializeProps.animStack = animStack_;
  this->serializeProps.clip = clip_;
  this->gametimeManager.gameTimeManager = gametimeManager;
  this->serializeProps.createdThroughSerialization = true;
}


// ========================================================================
// ?PreBlendSnapshot@idAnimator_JointMod@@UAAXPAVidAnimStack@@HHM@Z
// EA  : 0x826E81F0
// RVA : 0x006E81F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_base.h
// ========================================================================

void __fastcall idAnimator_JointMod::PreBlendSnapshot(
        idAnimator_JointMod *this,
        idAnimStack *stack,
        int curTime,
        int ticksPerSec,
        double fraction)
{
  if ( this->InternalGetMergeBranch_2(this) != nullptr )
    this->InternalGetMergeBranch_2(this)->left = nullptr;
  this->InternalPreBlendTree(this, a2: stack, a3: curTime, a4: ticksPerSec);
}

