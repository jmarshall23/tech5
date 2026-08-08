
// ========================================================================
// ?Argv@idCmdArgs@@QBAPBDH@Z
// EA  : 0x825D3DF0
// RVA : 0x005D3DF0
// PDB : w:\tech5\shared\idlib\text\cmdargs.h
// ========================================================================

char *__fastcall idCmdArgs::Argv(idCmdArgs *this, int arg)
{
  if ( arg < 0 || arg >= this->argc )
    return &byte_8200D768;
  else
    return this->argv[arg];
}

