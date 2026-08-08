
// ========================================================================
// ??0idLocalReport@@QAA@XZ
// EA  : 0x8289A938
// RVA : 0x0089A938
// PDB : w:\tech5\engine\network\localreport.h
// ========================================================================

idLocalReport *__fastcall idLocalReport::idLocalReport(idLocalReport *this)
{
  this->__vftable = (idLocalReport_vtbl *)&idIssueReport::`vftable';
  this->attachFileName.len = 0;
  this->attachFileName.allocedAndFlag = 20;
  this->attachFileName.data = this->attachFileName.baseBuffer;
  this->attachFileName.baseBuffer[0] = 0;
  this->__vftable = (idLocalReport_vtbl *)&idLocalReport::`vftable';
  this->fileName.data = this->fileName.baseBuffer;
  this->fileName.allocedAndFlag = 20;
  this->fileName.len = 0;
  this->fileName.baseBuffer[0] = 0;
  idStr::operator=(this: &this->fileName, text: &byte_8200D768);
  return this;
}


// ========================================================================
// __unwind$219318
// EA  : 0x8289A9D4
// RVA : 0x0089A9D4
// PDB : w:\tech5\engine\network\localreport.h
// ========================================================================

void _unwind_219318()
{
  int v0; // r12

  idIssueReport::~idIssueReport(this: *(idIssueReport **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$219319
// EA  : 0x8289A9FC
// RVA : 0x0089A9FC
// PDB : w:\tech5\engine\network\localreport.h
// ========================================================================

void _unwind_219319()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// ??1idLocalReport@@UAA@XZ
// EA  : 0x8289AA30
// RVA : 0x0089AA30
// PDB : w:\tech5\engine\network\localreport.h
// ========================================================================

void __fastcall idLocalReport::~idLocalReport(idLocalReport *this)
{
  this->__vftable = (idLocalReport_vtbl *)&idLocalReport::`vftable';
  idStr::FreeData(this: &this->fileName);
  this->__vftable = (idLocalReport_vtbl *)&idIssueReport::`vftable';
  idStr::FreeData(this: &this->attachFileName);
}


// ========================================================================
// __unwind$219397
// EA  : 0x8289AA90
// RVA : 0x0089AA90
// PDB : w:\tech5\engine\network\localreport.h
// ========================================================================

void _unwind_219397()
{
  int v0; // r12

  idIssueReport::~idIssueReport(this: *(idIssueReport **)(v0 - 112 + 132));
}

