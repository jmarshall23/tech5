
// ========================================================================
// ?SetBlackLevel@idRenderSystemLocal@@UAAXM@Z
// EA  : 0x82948A38
// RVA : 0x00948A38
// PDB : w:\tech5\engine\renderer\rendersystem_local.h
// ========================================================================

void __fastcall idRenderSystemLocal::SetBlackLevel(idRenderSystemLocal *this, double blackLevel_)
{
  this->blackLevel[0] = blackLevel_;
}


// ========================================================================
// ?GetScreenAspect@idRenderSystemLocal@@UAAMXZ
// EA  : 0x82948A40
// RVA : 0x00948A40
// PDB : w:\tech5\engine\renderer\rendersystem_local.h
// ========================================================================

float __fastcall idRenderSystemLocal::GetScreenAspect(idRenderSystemLocal *this)
{
  __int64 v2; // r9
  double v3; // fp31
  __int64 v4; // r4
  double v5; // fp1

  LODWORD(v2) = this->GetWidth(this);
  HIDWORD(v2) = this->__vftable;
  v3 = (float)(this->GetPixelAspect(this) * (float)v2);
  HIDWORD(v4) = this->GetHeight(this);
  LODWORD(v4) = HIDWORD(v4);
  v5 = (float)((float)v3 / (float)v4);
  return *((float *)&v5 + 1);
}

