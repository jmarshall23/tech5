
// ========================================================================
// ??0idPresentableCollisionTrigger@@QAA@PAVidEntity@@PAVidRenderModel@@HPBVidDeclFX@@@Z
// EA  : 0x82B6DE18
// RVA : 0x00B6DE18
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablecollisiontrigger.cpp
// ========================================================================

idPresentableCollisionTrigger *__fastcall idPresentableCollisionTrigger::idPresentableCollisionTrigger(
        idPresentableCollisionTrigger *this,
        idEntity *e,
        idTreeAnimator *renderModel_,
        int entityNumber_,
        const idDeclFX *fxDecl_)
{
  idPresentable::idPresentable(this, e, renderModel_, entityNumber_, fxDecl_);
  this->__vftable = (idPresentableCollisionTrigger_vtbl *)&idPresentableCollisionTrigger::`vftable';
  this->targetPresentable.spawnId = 0;
  this->triggered = false;
  return this;
}


// ========================================================================
// ?Serialize@idPresentableCollisionTrigger@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B6DE60
// RVA : 0x00B6DE60
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablecollisiontrigger.cpp
// ========================================================================

void __fastcall idPresentableCollisionTrigger::Serialize(idPresentableCollisionTrigger *this, idSerializer *ser)
{
  idBitMsg *msg; // r3

  idPresentable::Serialize(this, ser);
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->targetPresentable.spawnId, numBits: 32);
  else
    this->targetPresentable.spawnId = idBitMsg::ReadBits(this: msg, numBits: 32);
}


// ========================================================================
// ?PredictTouch@idPresentableCollisionTrigger@@QAAXPAVidPresentablePlayer@@@Z
// EA  : 0x82B6DEC8
// RVA : 0x00B6DEC8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablecollisiontrigger.cpp
// ========================================================================

void __fastcall idPresentableCollisionTrigger::PredictTouch(
        idPresentableCollisionTrigger *this,
        idPresentablePlayer *player)
{
  idPresentablePtr<idPresentable> *p_targetPresentable; // r31
  idPresentable *v3; // r3

  if ( !this->triggered && player != nullptr )
  {
    p_targetPresentable = &this->targetPresentable;
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &this->targetPresentable) != nullptr )
    {
      v3 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_targetPresentable);
      idPresentable::ClientOverrideClipContents(this: v3, newContents: 1);
    }
  }
}

