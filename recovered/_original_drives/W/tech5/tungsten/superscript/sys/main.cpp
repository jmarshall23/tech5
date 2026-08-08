
// ========================================================================
// ?Lock@idSuperScriptLocal@@UAAPAVidGameSuperInterface@@PAV2@@Z
// EA  : 0x82EECF38
// RVA : 0x00EECF38
// PDB : w:\tech5\tungsten\superscript\sys\main.cpp
// ========================================================================

idGameSuperInterface *__fastcall idSuperScriptLocal::Lock(idSuperScriptLocal *this, idGameSuperInterface *gsi)
{
  idGameSuperInterface *result; // r3

  result = gameInterface;
  gameInterface = gsi;
  return result;
}


// ========================================================================
// ?RegisterCVars@idSuperScriptLocal@@UAAXXZ
// EA  : 0x82EECF48
// RVA : 0x00EECF48
// PDB : w:\tech5\tungsten\superscript\sys\main.cpp
// ========================================================================

// attributes: thunk
void __fastcall idSuperScriptLocal::RegisterCVars(idSuperScriptLocal *this)
{
  cvar_::RegisterStaticCVars();
}


// ========================================================================
// ?GetSuperScriptAPI@@YAPAVidSuperScript@@H@Z
// EA  : 0x82EECF50
// RVA : 0x00EECF50
// PDB : w:\tech5\tungsten\superscript\sys\main.cpp
// ========================================================================

idSuperScriptLocal *__fastcall GetSuperScriptAPI(int version)
{
  return version != 1 ? nullptr : &superScriptLocal;
}


// ========================================================================
// `dynamic initializer for 'superScriptLocal''
// EA  : 0x83393E20
// RVA : 0x01393E20
// PDB : w:\tech5\tungsten\superscript\sys\main.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__superScriptLocal__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__superScriptLocal__);
}

