
// ========================================================================
// ?GetController@idPresentable@@QBAPAVidPresentablePlayer@@XZ
// EA  : 0x82B51B80
// RVA : 0x00B51B80
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.h
// ========================================================================

idPresentablePlayer *__fastcall idPresentable::GetController(idPresentable *this)
{
  return idPresentablePtr<idPresentablePlayer>::GetPresentable(this: &this->controller);
}


// ========================================================================
// ?UpdateFX@idPresentable@@UAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82B68000
// RVA : 0x00B68000
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.h
// ========================================================================

void __fastcall idPresentable::UpdateFX(idPresentable *this, const idVec3 *origin, const idMat3 *axis)
{
  this->UpdateFX(this, a2: origin, a3: axis, a4: &this->fxManager, a5: 1.0, a6: 0.0);
}


// ========================================================================
// ?UpdateFX@idPresentable@@UAAXMM@Z
// EA  : 0x82B68028
// RVA : 0x00B68028
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.h
// ========================================================================

void __fastcall idPresentable::UpdateFX(
        idPresentable *this,
        double fovScale,
        double depthHack,
        idFXManager *a4,
        int a5)
{
  idPresentable::UpdateFX(this, fovScale, depthHack, fxManager: a4, a5, a6: &this->fxManager);
}


// ========================================================================
// ?ShouldSaveForTimeTrial@idPresentable@@UBA_NXZ
// EA  : 0x82B690C8
// RVA : 0x00B690C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentable.h
// ========================================================================

int __fastcall idPresentable::ShouldSaveForTimeTrial(idPresentable *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_parent; // r29
  int v3; // r31
  idPresentable *v4; // r3

  spawnId = this->parent.spawnId;
  p_parent = &this->parent;
  v3 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || idClientGame::GetPresentableByIndex(this: clientGame, index: v3)->spawnId != p_parent->spawnId )
  {
    return 0;
  }
  v4 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_parent);
  return ((int (__fastcall *)(idPresentable *))v4->ShouldSaveForTimeTrial)(a1: v4);
}

