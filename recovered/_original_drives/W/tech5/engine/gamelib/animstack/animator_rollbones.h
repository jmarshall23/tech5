
// ========================================================================
// ??0idAnimatorParms_RollBones@@QAA@PBVidDeclRollBones@@PAVidAnimStack@@PBDM@Z
// EA  : 0x829F5D08
// RVA : 0x009F5D08
// PDB : w:\tech5\engine\gamelib\animstack\animator_rollbones.h
// ========================================================================

idAnimatorParms_RollBones *__fastcall idAnimatorParms_RollBones::idAnimatorParms_RollBones(
        idAnimatorParms_RollBones *this,
        const idDeclRollBones *declRollBones_,
        idAnimStack *animStack_,
        const char *name_,
        double alpha_)
{
  this->animStack = animStack_;
  idStr::idStr(this: &this->name, text: name_);
  this->alpha = alpha_;
  this->blendOp = BOP_REF_LERP;
  this->originBlend = ORIGINBLEND_BRANCH;
  this->weightGroup = MD6_WEIGHTGROUP_TORSO;
  this->filterGroup = MD6_WEIGHTGROUP_ALL;
  this->declRollBones = declRollBones_;
  return this;
}

