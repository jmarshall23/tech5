
// ========================================================================
// ?IsShiftDown@idKeyInput@@SA_NH@Z
// EA  : 0x82663CE8
// RVA : 0x00663CE8
// PDB : w:\tech5\engine\framework\keyinput.h
// ========================================================================

int __fastcall idKeyInput::IsShiftDown(int deviceNum)
{
  bool IsDown; // r3
  unsigned __int8 v3; // r11

  if ( idKeyInput::IsDown(deviceNum, keyNum: K_LSHIFT) )
    return 1;
  IsDown = idKeyInput::IsDown(deviceNum, keyNum: K_RSHIFT);
  v3 = 0;
  if ( IsDown )
    return 1;
  return v3;
}


// ========================================================================
// ?IsCtrlDown@idKeyInput@@SA_NH@Z
// EA  : 0x82663D48
// RVA : 0x00663D48
// PDB : w:\tech5\engine\framework\keyinput.h
// ========================================================================

int __fastcall idKeyInput::IsCtrlDown(int deviceNum)
{
  bool IsDown; // r3
  unsigned __int8 v3; // r11

  if ( idKeyInput::IsDown(deviceNum, keyNum: K_LCTRL) )
    return 1;
  IsDown = idKeyInput::IsDown(deviceNum, keyNum: K_RCTRL);
  v3 = 0;
  if ( IsDown )
    return 1;
  return v3;
}

