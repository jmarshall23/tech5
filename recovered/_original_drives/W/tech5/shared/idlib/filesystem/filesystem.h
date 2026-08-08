
// ========================================================================
// ??1idFileSystem@@UAA@XZ
// EA  : 0x82F09F48
// RVA : 0x00F09F48
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.h
// ========================================================================

void __fastcall idFileSystem::~idFileSystem(idFileSystem *this)
{
  this->__vftable = (idFileSystem_vtbl *)&idFileSystem::`vftable';
}


// ========================================================================
// ??0idFileList@@QAA@XZ
// EA  : 0x82F0D600
// RVA : 0x00F0D600
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.h
// ========================================================================

idFileList *__fastcall idFileList::idFileList(idFileList *this)
{
  this->basePath.len = 0;
  this->basePath.data = this->basePath.baseBuffer;
  this->basePath.allocedAndFlag = 20;
  this->basePath.baseBuffer[0] = 0;
  this->list.granularity = 0;
  this->list.listStatic = 0;
  this->list.memTag = 48;
  this->list.list = nullptr;
  this->list.size = 0;
  this->list.num = 0;
  return this;
}


// ========================================================================
// __unwind$123655
// EA  : 0x82F0D658
// RVA : 0x00F0D658
// PDB : w:\tech5\shared\idlib\filesystem\filesystem.h
// ========================================================================

void _unwind_123655()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 32 + 52));
}

