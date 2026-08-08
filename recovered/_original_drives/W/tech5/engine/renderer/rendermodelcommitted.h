
// ========================================================================
// ?CastsDimShadows@idRenderModelCommitted@@QBA_NXZ
// EA  : 0x82944BF0
// RVA : 0x00944BF0
// PDB : w:\tech5\engine\renderer\rendermodelcommitted.h
// ========================================================================

BOOL __fastcall idRenderModelCommitted::CastsDimShadows(idRenderModelCommitted *this)
{
  char v1; // r11

  if ( (*((_BYTE *)this + 1416) & 8) == 0 || (v1 = 1, (*((_BYTE *)&this->r + 105) & 0x80) != 0) )
    v1 = 0;
  return v1 != 0 && this->r.castDimShadows != DIMSHADOW_OFF;
}

