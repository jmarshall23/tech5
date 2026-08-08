
// ========================================================================
// ?AIMeleeTypeToOverrideAnim@@YA?AW4overrideAnim_t@@W4aiMelee_t@@@Z
// EA  : 0x82D76C18
// RVA : 0x00D76C18
// PDB : w:\tech5\tungsten\game\gametooldefs.cpp
// ========================================================================

int __fastcall AIMeleeTypeToOverrideAnim(const aiMelee_t meleeType)
{
  switch ( meleeType )
  {
    case AIMELEE_FORWARD:
      return 36;
    case AIMELEE_LEFT:
      return 38;
    case AIMELEE_RIGHT:
      return 39;
    case AIMELEE_BACK:
      return 37;
    case AIMELEE_PUNCH:
      return 34;
    case AIMELEE_KICK:
      return 35;
    case AIMELEE_CROUCH_FORWARD:
      return 40;
    case AIMELEE_CROUCH_BACK:
    case AIMELEE_CROUCH_LEFT:
    case AIMELEE_CROUCH_RIGHT:
      return 0;
    case AIMELEE_MEDIUM:
      return 41;
    case AIMELEE_LONG:
      return 42;
    case AIMELEE_RAGE:
      return 46;
    case AIMELEE_MOVING_FORWARD:
      return 43;
    default:
      break;
  }
  return meleeType != AIMELEE_TAKEDOWN ? 0 : 0x2C;
}


// ========================================================================
// `dynamic initializer for 'ACTIONSCRIPT_SELF_TARGET_NAME_LEN''
// EA  : 0x83383B28
// RVA : 0x01383B28
// PDB : w:\tech5\tungsten\game\gametooldefs.cpp
// ========================================================================

void _dynamic_initializer_for__ACTIONSCRIPT_SELF_TARGET_NAME_LEN__()
{
  int v0; // r11

  v0 = 0;
  if ( *ACTIONSCRIPT_SELF_TARGET_NAME != 0 )
  {
    do
      ++v0;
    while ( ACTIONSCRIPT_SELF_TARGET_NAME[v0] != 0 );
  }
  ACTIONSCRIPT_SELF_TARGET_NAME_LEN = v0;
}


// ========================================================================
// `dynamic initializer for 'ACTIONSCRIPT_EXECUTOR_TARGET_NAME_LEN''
// EA  : 0x83383B60
// RVA : 0x01383B60
// PDB : w:\tech5\tungsten\game\gametooldefs.cpp
// ========================================================================

void _dynamic_initializer_for__ACTIONSCRIPT_EXECUTOR_TARGET_NAME_LEN__()
{
  int v0; // r11

  v0 = 0;
  if ( *ACTIONSCRIPT_EXECUTOR_TARGET_NAME != 0 )
  {
    do
      ++v0;
    while ( ACTIONSCRIPT_EXECUTOR_TARGET_NAME[v0] != 0 );
  }
  ACTIONSCRIPT_EXECUTOR_TARGET_NAME_LEN = v0;
}


// ========================================================================
// `dynamic initializer for 'ACTIONSCRIPT_ACTIVATOR_TARGET_NAME_LEN''
// EA  : 0x83383B98
// RVA : 0x01383B98
// PDB : w:\tech5\tungsten\game\gametooldefs.cpp
// ========================================================================

void _dynamic_initializer_for__ACTIONSCRIPT_ACTIVATOR_TARGET_NAME_LEN__()
{
  int v0; // r11

  v0 = 0;
  if ( *ACTIONSCRIPT_ACTIVATOR_TARGET_NAME != 0 )
  {
    do
      ++v0;
    while ( ACTIONSCRIPT_ACTIVATOR_TARGET_NAME[v0] != 0 );
  }
  ACTIONSCRIPT_ACTIVATOR_TARGET_NAME_LEN = v0;
}


// ========================================================================
// `dynamic initializer for 'ACTIONSCRIPT_PLAYER_NAME_LEN''
// EA  : 0x83383BD0
// RVA : 0x01383BD0
// PDB : w:\tech5\tungsten\game\gametooldefs.cpp
// ========================================================================

void _dynamic_initializer_for__ACTIONSCRIPT_PLAYER_NAME_LEN__()
{
  int v0; // r11

  v0 = 0;
  if ( *ACTIONSCRIPT_PLAYER_NAME != 0 )
  {
    do
      ++v0;
    while ( ACTIONSCRIPT_PLAYER_NAME[v0] != 0 );
  }
  ACTIONSCRIPT_PLAYER_NAME_LEN = v0;
}

