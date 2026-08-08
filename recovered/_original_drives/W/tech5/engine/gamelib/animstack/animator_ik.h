
// ========================================================================
// ?GetStackPriority@idAnimator_VehicleCar@@UBA?AW4priority_t@idAnimator_Base@@XZ
// EA  : 0x826E28E8
// RVA : 0x006E28E8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.h
// ========================================================================

int __fastcall idAnimator_VehicleCar::GetStackPriority(idAnimator_IK *this)
{
  return 99;
}


// ========================================================================
// ?GetActionFlags@idAction_PlayVoiceOver@@UBAHXZ
// EA  : 0x826E28F0
// RVA : 0x006E28F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.h
// ========================================================================

int __fastcall idAction_PlayVoiceOver::GetActionFlags(XGRAPHICS::IRTrinary *this)
{
  return 3;
}


// ========================================================================
// ??0idAnimatorParms_WalkIK@@QAA@PBVidDeclWalkIK@@HPAVidClip@@PAVidClipModel@@HABVidVec3@@PAVidAnimStack@@PBDM@Z
// EA  : 0x826E31F0
// RVA : 0x006E31F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.h
// ========================================================================

idAnimatorParms_WalkIK *__fastcall idAnimatorParms_WalkIK::idAnimatorParms_WalkIK(
        idAnimatorParms_WalkIK *this,
        const idDeclWalkIK *declWalkIK_,
        int entityNum_,
        idClip *clip_,
        idClipModel *clipModel_,
        int clipMask_,
        const idVec3 *upNormal_,
        idAnimStack *animStack_,
        double alpha_,
        const char *name_,
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
        const char *a29)
{
  this->animStack = animStack_;
  idStr::idStr(this: &this->name, text: a29);
  this->alpha = alpha_;
  this->declWalkIK = declWalkIK_;
  this->originBlend = ORIGINBLEND_BRANCH;
  this->blendOp = BOP_REF_LERP;
  this->weightGroup = MD6_WEIGHTGROUP_ALL;
  this->filterGroup = MD6_WEIGHTGROUP_ALL;
  this->entityNum = entityNum_;
  this->clipMask = clipMask_;
  this->clip = clip_;
  this->clipModel = clipModel_;
  this->upNormal = *upNormal_;
  return this;
}


// ========================================================================
// ??0idAnimatorParms_ReachIK@@QAA@PBVidDeclReachIK@@HPAVidClip@@PAVidAnimStack@@PBDM@Z
// EA  : 0x826E3288
// RVA : 0x006E3288
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.h
// ========================================================================

idAnimatorParms_ReachIK *__fastcall idAnimatorParms_ReachIK::idAnimatorParms_ReachIK(
        idAnimatorParms_ReachIK *this,
        const idDeclReachIK *declReachIK_,
        int entityNum_,
        idClip *clip_,
        idAnimStack *animStack_,
        const char *name_,
        double alpha_)
{
  this->animStack = animStack_;
  idStr::idStr(this: &this->name, text: name_);
  this->alpha = alpha_;
  this->originBlend = ORIGINBLEND_BRANCH;
  this->blendOp = BOP_REF_LERP;
  this->weightGroup = MD6_WEIGHTGROUP_ALL;
  this->filterGroup = MD6_WEIGHTGROUP_ALL;
  this->declReachIK = declReachIK_;
  this->entityNum = entityNum_;
  this->clip = clip_;
  return this;
}


// ========================================================================
// ?GetType@idPresentableActor@@UBA?AW4presentableType_t@@XZ
// EA  : 0x826E40F0
// RVA : 0x006E40F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_ik.h
// ========================================================================

int __fastcall idPresentableActor::GetType(idAAS2Local *this)
{
  return 7;
}

