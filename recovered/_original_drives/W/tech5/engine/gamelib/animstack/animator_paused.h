
// ========================================================================
// ??0idAnimatorParms_Pause@@QAA@PBVidMD6Anim@@MMPAVidAnimStack@@PBDW4blendOp_t@idMD6Blend@@W4originBlend_t@4@W4md6WeightGroup_t@@5M@Z
// EA  : 0x82BD8448
// RVA : 0x00BD8448
// PDB : w:\tech5\engine\gamelib\animstack\animator_paused.h
// ========================================================================

idAnimatorParms_Pause *__fastcall idAnimatorParms_Pause::idAnimatorParms_Pause(
        idAnimatorParms_Pause *this,
        const idMD6Anim *anim_,
        double startFrame_,
        double normalizedStartFrame_,
        idAnimStack *animStack_,
        const char *name_,
        idAnimStack *blendOp_,
        const char *originBlend_,
        idMD6Blend::blendOp_t weightGroup_,
        idMD6Blend::originBlend_t filterGroup_,
        double alpha_,
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
        md6WeightGroup_t a31,
        int a32,
        md6WeightGroup_t a33)
{
  this->animStack = blendOp_;
  idStr::idStr(this: &this->name, text: originBlend_);
  this->alpha = alpha_;
  this->startFrame = startFrame_;
  this->blendOp = weightGroup_;
  this->normalizedStartFrame = normalizedStartFrame_;
  this->originBlend = filterGroup_;
  this->anim = anim_;
  this->weightGroup = a31;
  this->filterGroup = a33;
  return this;
}

