
// ========================================================================
// ??0idZipBuilder@@QAA@XZ
// EA  : 0x82F1E230
// RVA : 0x00F1E230
// PDB : w:\tech5\shared\idlib\filesystem\zip.h
// ========================================================================

idZipBuilder *__fastcall idZipBuilder::idZipBuilder(idZipBuilder *this)
{
  this->zipFileName.len = 0;
  this->zipFileName.data = this->zipFileName.baseBuffer;
  this->zipFileName.allocedAndFlag = 20;
  this->zipFileName.baseBuffer[0] = 0;
  this->sourceFolderName.allocedAndFlag = 20;
  this->sourceFolderName.len = 0;
  this->sourceFolderName.data = this->sourceFolderName.baseBuffer;
  this->sourceFolderName.baseBuffer[0] = 0;
  this->filterExts.granularity = 0;
  this->filterExts.listStatic = 0;
  this->filterExts.memTag = 5;
  this->filterExts.list = nullptr;
  this->filterExts.size = 0;
  this->filterExts.num = 0;
  this->uncompressedFilterExts.granularity = 0;
  this->uncompressedFilterExts.memTag = 5;
  this->uncompressedFilterExts.listStatic = 0;
  this->uncompressedFilterExts.list = nullptr;
  this->uncompressedFilterExts.size = 0;
  this->uncompressedFilterExts.num = 0;
  return this;
}


// ========================================================================
// __unwind$118144
// EA  : 0x82F1E2C0
// RVA : 0x00F1E2C0
// PDB : w:\tech5\shared\idlib\filesystem\zip.h
// ========================================================================

void _unwind_118144()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 32 + 52));
}


// ========================================================================
// __unwind$118145
// EA  : 0x82F1E2E8
// RVA : 0x00F1E2E8
// PDB : w:\tech5\shared\idlib\filesystem\zip.h
// ========================================================================

void _unwind_118145()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 32 + 52) + 32));
}


// ========================================================================
// __unwind$118146
// EA  : 0x82F1E314
// RVA : 0x00F1E314
// PDB : w:\tech5\shared\idlib\filesystem\zip.h
// ========================================================================

void _unwind_118146()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 32 + 52) + 64));
}


// ========================================================================
// ??1idZipBuilder@@QAA@XZ
// EA  : 0x82F1E348
// RVA : 0x00F1E348
// PDB : w:\tech5\shared\idlib\filesystem\zip.h
// ========================================================================

void __fastcall idZipBuilder::~idZipBuilder(idZipBuilder *this)
{
  idStr *list; // r3
  idStr *v3; // r3

  if ( this->uncompressedFilterExts.listStatic == 0 || this->uncompressedFilterExts.listStatic == 2 )
  {
    list = this->uncompressedFilterExts.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->uncompressedFilterExts.size);
    this->uncompressedFilterExts.list = nullptr;
    this->uncompressedFilterExts.size = 0;
  }
  this->uncompressedFilterExts.num = 0;
  if ( this->filterExts.listStatic == 0 || this->filterExts.listStatic == 2 )
  {
    v3 = this->filterExts.list;
    if ( v3 != nullptr )
      idListArrayDelete<idStr>(ptr: v3, num: this->filterExts.size);
    this->filterExts.list = nullptr;
    this->filterExts.size = 0;
  }
  this->filterExts.num = 0;
  idStr::FreeData(this: &this->sourceFolderName);
  idStr::FreeData(this: &this->zipFileName);
}


// ========================================================================
// __unwind$118244
// EA  : 0x82F1E3E4
// RVA : 0x00F1E3E4
// PDB : w:\tech5\shared\idlib\filesystem\zip.h
// ========================================================================

void _unwind_118244()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$118245
// EA  : 0x82F1E40C
// RVA : 0x00F1E40C
// PDB : w:\tech5\shared\idlib\filesystem\zip.h
// ========================================================================

void _unwind_118245()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}


// ========================================================================
// __unwind$118246
// EA  : 0x82F1E438
// RVA : 0x00F1E438
// PDB : w:\tech5\shared\idlib\filesystem\zip.h
// ========================================================================

void _unwind_118246()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}

