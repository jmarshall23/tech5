
// ========================================================================
// ??0idFile_SaveGame@@QAA@PBDH@Z
// EA  : 0x829BAA40
// RVA : 0x009BAA40
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.h
// ========================================================================

idFile_SaveGame *__fastcall idFile_SaveGame::idFile_SaveGame(idFile_SaveGame *this, const char *name_, int type_)
{
  idFile_Memory::idFile_Memory(this, name: name_);
  this->type = type_;
  this->error = false;
  this->__vftable = (idFile_SaveGame_vtbl *)&idFile_SaveGame::`vftable';
  return this;
}


// ========================================================================
// ?SetLength@idFile_SaveGamePipelined@@UAAXI@Z
// EA  : 0x82F1C648
// RVA : 0x00F1C648
// PDB : w:\tech5\shared\idlib\filesystem\file_savegame.h
// ========================================================================

void __fastcall idFile_SaveGamePipelined::SetLength(idFile_SaveGamePipelined *this, unsigned int len)
{
  this->compressedLength = len;
}

