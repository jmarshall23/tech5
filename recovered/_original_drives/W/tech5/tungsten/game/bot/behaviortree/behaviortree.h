
// ========================================================================
// ?InhibitButtons@idCamera@@UBAHXZ
// EA  : 0x82541518
// RVA : 0x00541518
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.h
// ========================================================================

int __fastcall idCamera::InhibitButtons(idCamera *this)
{
  return -1;
}


// ========================================================================
// ?IsInterruptable@idBehaviorState@@MBA_NXZ
// EA  : 0x82541520
// RVA : 0x00541520
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.h
// ========================================================================

int __fastcall idBehaviorState::IsInterruptable(idBehaviorState *this)
{
  bool v2; // r3
  unsigned __int8 v3; // r11

  if ( idBehaviorState::CheckStateFlag(this, flag: 2) )
    return 0;
  v2 = idBehaviorState::CheckStateFlag(this, flag: 4);
  v3 = 1;
  if ( v2 )
    return 0;
  return v3;
}

