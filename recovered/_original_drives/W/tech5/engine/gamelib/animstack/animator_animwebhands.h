
// ========================================================================
// ??0idAnimator_AnimWebHands@@QAA@XZ
// EA  : 0x826F2728
// RVA : 0x006F2728
// PDB : w:\tech5\engine\gamelib\animstack\animator_animwebhands.h
// ========================================================================

idAnimator_AnimWebHands *__fastcall idAnimator_AnimWebHands::idAnimator_AnimWebHands(idAnimator_AnimWebHands *this)
{
  idAnimator_AnimWeb::idAnimator_AnimWeb(this);
  this->__vftable = (idAnimator_AnimWebHands_vtbl *)&idAnimator_AnimWebHands::`vftable';
  this->punchSelector = 0.0;
  this->throwSelector = 0.0;
  this->idleSelector = 0.0;
  this->meleeReturnSelector = 0.0;
  this->zoomSelector = 0.0;
  this->weaponCondition = 0.0;
  this->variationIndex = 0.0;
  this->previousVariationIndex = 0.0;
  this->weaponAnimVarIndex = 0.0;
  this->attackVariation = 0.0;
  return this;
}


// ========================================================================
// ?InternalInitWeb@idAnimator_AnimWebHands@@UAAXXZ
// EA  : 0x826F2798
// RVA : 0x006F2798
// PDB : w:\tech5\engine\gamelib\animstack\animator_animwebhands.h
// ========================================================================

void __fastcall idAnimator_AnimWebHands::InternalInitWeb(idAnimator_AnimWebHands *this)
{
  idAnimator_AnimWeb::InternalInitWeb(this);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "punchSelector", scalar: &this->punchSelector, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "throwSelector", scalar: &this->throwSelector, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "idleSelector", scalar: &this->idleSelector, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "meleeReturnSelector",
    scalar: &this->meleeReturnSelector,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(this, name: "zoomSelector", scalar: &this->zoomSelector, flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "weaponCondition",
    scalar: &this->weaponCondition,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "variationIndex",
    scalar: &this->variationIndex,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "previousVariationIndex",
    scalar: &this->previousVariationIndex,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "weaponAnimVarIndex",
    scalar: &this->weaponAnimVarIndex,
    flags: FF_NO_OVERRIDE);
  idAnimator_AnimWeb::AddBlendVariable(
    this,
    name: "attackVariation",
    scalar: &this->attackVariation,
    flags: FF_NO_OVERRIDE);
}


// ========================================================================
// ?SerializeSnapshot@idAnimator_AnimWebHands@@UAAXAAVidSerializer@@@Z
// EA  : 0x826F3138
// RVA : 0x006F3138
// PDB : w:\tech5\engine\gamelib\animstack\animator_animwebhands.h
// ========================================================================

void __fastcall idAnimator_AnimWebHands::SerializeSnapshot(idAnimator_AnimWebHands *this, idSerializer *ser)
{
  if ( this->GetSerializeType(this) != STYPE_GENERIC )
  {
    idSerializer::Serialize(this: ser, value: &this->punchSelector);
    idSerializer::Serialize(this: ser, value: &this->throwSelector);
    idSerializer::Serialize(this: ser, value: &this->idleSelector);
    idSerializer::Serialize(this: ser, value: &this->meleeReturnSelector);
    idSerializer::Serialize(this: ser, value: &this->zoomSelector);
    idSerializer::Serialize(this: ser, value: &this->weaponCondition);
    idSerializer::Serialize(this: ser, value: &this->variationIndex);
    idSerializer::Serialize(this: ser, value: &this->previousVariationIndex);
    idSerializer::Serialize(this: ser, value: &this->weaponAnimVarIndex);
    idSerializer::Serialize(this: ser, value: &this->attackVariation);
  }
}

