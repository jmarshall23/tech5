
// ========================================================================
// ??0idPonytailSegment@@QAA@ABVidVec3@@ABVidConeConstraint_Quat@@@Z
// EA  : 0x826E8ED8
// RVA : 0x006E8ED8
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.h
// ========================================================================

idPonytailSegment *__fastcall idPonytailSegment::idPonytailSegment(
        idPonytailSegment *this,
        const idVec3 *origin_,
        const idConeConstraint_Quat *ccq)
{
  this->localOrigin = vec3_origin;
  this->localAxis = quat_identity;
  this->origin = *origin_;
  idConeConstraint_Quat::idConeConstraint_Quat(this: &this->coneConstraintQ, other: ccq);
  this->len = 1.0;
  return this;
}


// ========================================================================
// ??0idAnimatorParms_Ponytail@@QAA@PAVidAnimStack@@PBDW4blendOp_t@idMD6Blend@@W4originBlend_t@3@W4md6WeightGroup_t@@4MPBVidDeclPonytail@@PAVidTreeAnimator@@@Z
// EA  : 0x82B35E80
// RVA : 0x00B35E80
// PDB : w:\tech5\engine\gamelib\animstack\animator_ponytail.h
// ========================================================================

idAnimatorParms_Ponytail *__fastcall idAnimatorParms_Ponytail::idAnimatorParms_Ponytail(
        idAnimatorParms_Ponytail *this,
        idAnimStack *animStack_,
        const char *name_,
        idMD6Blend::blendOp_t blendOp_,
        idMD6Blend::originBlend_t originBlend_,
        md6WeightGroup_t weightGroup_,
        md6WeightGroup_t filterGroup_,
        double alpha_,
        const idDeclPonytail *declPonytail_,
        idTreeAnimator *parentAnimator_,
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
        const idDeclPonytail *a29,
        int a30,
        idTreeAnimator *a31)
{
  this->animStack = animStack_;
  idStr::idStr(this: &this->name, text: name_);
  this->alpha = alpha_;
  this->blendOp = blendOp_;
  this->originBlend = originBlend_;
  this->weightGroup = weightGroup_;
  this->filterGroup = filterGroup_;
  this->declPonytail = a29;
  this->parentAnimator = a31;
  return this;
}

