
// ========================================================================
// ?SetVolumeAdjustment@idSoundEmitterLocal@@UAAXM@Z
// EA  : 0x8298ED60
// RVA : 0x0098ED60
// PDB : w:\tech5\engine\sound\soundemitter_local.h
// ========================================================================

void __fastcall idSoundEmitterLocal::SetVolumeAdjustment(idSoundEmitterLocal *this, double adjust)
{
  this->volumeAdjustment = adjust;
}


// ========================================================================
// ?ClearVolumeAdjustment@idSoundEmitterLocal@@UAAXXZ
// EA  : 0x8298ED68
// RVA : 0x0098ED68
// PDB : w:\tech5\engine\sound\soundemitter_local.h
// ========================================================================

void __fastcall idSoundEmitterLocal::ClearVolumeAdjustment(idSoundEmitterLocal *this)
{
  this->volumeAdjustment = 0.0;
}


// ========================================================================
// ?SetDebugName@idSoundEmitterLocal@@UAAXPBD@Z
// EA  : 0x8298ED78
// RVA : 0x0098ED78
// PDB : w:\tech5\engine\sound\soundemitter_local.h
// ========================================================================

void __fastcall idSoundEmitterLocal::SetDebugName(idSoundEmitterLocal *this, const char *debugName_)
{
  this->debugName = debugName_;
}


// ========================================================================
// ?GetDebugName@idSoundEmitterLocal@@UBAPBDXZ
// EA  : 0x8298ED80
// RVA : 0x0098ED80
// PDB : w:\tech5\engine\sound\soundemitter_local.h
// ========================================================================

const idDeclEntityDef *__fastcall idSoundEmitterLocal::GetDebugName(idDeclEntityDef *this)
{
  return this->listedParent;
}


// ========================================================================
// ?GetPosition@idSoundEmitterLocal@@UBAABVidVec3@@XZ
// EA  : 0x8298ED88
// RVA : 0x0098ED88
// PDB : w:\tech5\engine\sound\soundemitter_local.h
// ========================================================================

const idVec3 *__fastcall idSoundEmitterLocal::GetPosition(idSoundEmitterLocal *this)
{
  return &this->origin;
}

