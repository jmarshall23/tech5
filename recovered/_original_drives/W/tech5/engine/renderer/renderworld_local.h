
// ========================================================================
// ?SetBinaryModelState@idRenderWorldLocal@@UAAXPBD_N@Z
// EA  : 0x8295D528
// RVA : 0x0095D528
// PDB : w:\tech5\engine\renderer\renderworld_local.h
// ========================================================================

void __fastcall idRenderWorldLocal::SetBinaryModelState(
        idRenderWorldLocal *this,
        const char *binaryModelName,
        bool isVisible)
{
  idRenderWorldLocal::SetBinaryModelState_Internal(this, binaryModelName, isVisible, makingDefinition: false);
}


// ========================================================================
// ?GetStatePreprocessor@XGRAPHICS@@YAPAU_SP_STATE_PREPROCESSOR@1@PAX@Z
// EA  : 0x8295D530
// RVA : 0x0095D530
// PDB : w:\tech5\engine\renderer\renderworld_local.h
// ========================================================================

XGRAPHICS::_SP_STATE_PREPROCESSOR *__fastcall XGRAPHICS::GetStatePreprocessor(_DWORD *hSSMDev)
{
  return (XGRAPHICS::_SP_STATE_PREPROCESSOR *)hSSMDev[27];
}


// ========================================================================
// ?IsComboMap@idRenderWorldLocal@@UBA_NXZ
// EA  : 0x8295D538
// RVA : 0x0095D538
// PDB : w:\tech5\engine\renderer\renderworld_local.h
// ========================================================================

BOOL __fastcall idRenderWorldLocal::IsComboMap(idRenderWorldLocal *this)
{
  return this->isComboMap;
}


// ========================================================================
// ?HasGlobalShadows@idRenderWorldLocal@@UBA_NXZ
// EA  : 0x8295D540
// RVA : 0x0095D540
// PDB : w:\tech5\engine\renderer\renderworld_local.h
// ========================================================================

int __fastcall idRenderWorldLocal::HasGlobalShadows(idRenderWorldLocal *this)
{
  idGlobalShadows *p_globalShadows; // r31
  const shadowMap_t *ShadowMap; // r3
  unsigned __int8 v3; // r11

  p_globalShadows = &this->globalShadows;
  if ( idGlobalShadows::GetShadowMap(this: &this->globalShadows) == nullptr )
    return 0;
  ShadowMap = idGlobalShadows::GetShadowMap(this: p_globalShadows);
  v3 = 1;
  if ( ShadowMap->map == nullptr )
    return 0;
  return v3;
}


// ========================================================================
// ?GetNumRenderModels@idRenderWorldLocal@@UBAHXZ
// EA  : 0x8295D598
// RVA : 0x0095D598
// PDB : w:\tech5\engine\renderer\renderworld_local.h
// ========================================================================

int __fastcall idRenderWorldLocal::GetNumRenderModels(idRenderWorldLocal *this)
{
  return this->renderModels.num;
}


// ========================================================================
// ?GetNumRenderLights@idRenderWorldLocal@@UBAHXZ
// EA  : 0x8295D5A0
// RVA : 0x0095D5A0
// PDB : w:\tech5\engine\renderer\renderworld_local.h
// ========================================================================

int __fastcall idRenderWorldLocal::GetNumRenderLights(idRenderWorldLocal *this)
{
  return this->renderLights.num;
}


// ========================================================================
// ?GetNumMegatextures@idRenderWorldLocal@@UBAHXZ
// EA  : 0x8295D5A8
// RVA : 0x0095D5A8
// PDB : w:\tech5\engine\renderer\renderworld_local.h
// ========================================================================

int __fastcall idRenderWorldLocal::GetNumMegatextures(idRenderWorldLocal *this)
{
  return this->megaTextures.num;
}

