
// ========================================================================
// ?IsType@idClass@@QBA_NABVidTypeInfo@@@Z
// EA  : 0x824E2CE0
// RVA : 0x004E2CE0
// PDB : w:\tech5\engine\gamelib\class.h
// ========================================================================

int __fastcall idClass::IsType(idClass *this, const idTypeInfo *superclass)
{
  int v3; // r11
  unsigned __int8 v4; // r11
  bool v5; // zf

  v3 = *(_DWORD *)(this->GetType(this) + 36);
  if ( v3 < superclass->typeNum )
    return 0;
  v5 = v3 <= superclass->lastChild;
  v4 = 1;
  if ( !v5 )
    return 0;
  return v4;
}

