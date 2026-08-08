
// ========================================================================
// ?GetArg@idAutoComplete@@QBAPBDH@Z
// EA  : 0x82624600
// RVA : 0x00624600
// PDB : w:\tech5\shared\idlib\csystems\autocomplete.h
// ========================================================================

char *__fastcall idAutoComplete::GetArg(idAutoComplete *this, int n)
{
  idCmdArgs *p_args; // r11

  p_args = &this->args;
  if ( n < 0 || n >= p_args->argc )
    return &byte_8200D768;
  else
    return p_args->argv[n];
}


// ========================================================================
// ?Clear@idAutoComplete@@QAAXXZ
// EA  : 0x82676B18
// RVA : 0x00676B18
// PDB : w:\tech5\shared\idlib\csystems\autocomplete.h
// ========================================================================

void __fastcall idAutoComplete::Clear(idAutoComplete *this)
{
  idStr *list; // r3

  this->matchLength = 0;
  this->currentIndex = -1;
  this->args.argc = 0;
  if ( this->suggestions.listStatic == 0 || this->suggestions.listStatic == 2 )
  {
    list = this->suggestions.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->suggestions.size);
    this->suggestions.list = nullptr;
    this->suggestions.size = 0;
  }
  this->suggestions.num = 0;
}

