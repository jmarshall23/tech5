
// ========================================================================
// ??0idPresentableCuttable@@QAA@PAVidEntity@@PAVidRenderModel@@@Z
// EA  : 0x82B6DF28
// RVA : 0x00B6DF28
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablecuttable.cpp
// ========================================================================

idPresentableCuttable *__fastcall idPresentableCuttable::idPresentableCuttable(
        idPresentableCuttable *this,
        idEntity *entity,
        idTreeAnimator *renderModel)
{
  idPresentable::idPresentable(this, e: entity, renderModel_: renderModel, entityNumber_: 0x1FFF, fxDecl_: nullptr);
  this->__vftable = (idPresentableCuttable_vtbl *)&idPresentableCuttable::`vftable';
  return this;
}

