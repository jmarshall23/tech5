
// ========================================================================
// ??0idDeclCameraTrigger@@QAA@XZ
// EA  : 0x82BBCBA0
// RVA : 0x00BBCBA0
// PDB : w:\tech5\tungsten\game\decls\declcameratrigger.cpp
// ========================================================================

idDeclCameraTrigger *__fastcall idDeclCameraTrigger::idDeclCameraTrigger(idDeclCameraTrigger *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclCameraTrigger_vtbl *)&idDeclCameraTrigger::`vftable';
  this->triggers.granularity = 0;
  this->triggers.memTag = 5;
  this->triggers.listStatic = 0;
  this->triggers.list = nullptr;
  this->triggers.size = 0;
  this->triggers.num = 0;
  return this;
}


// ========================================================================
// __unwind$487311
// EA  : 0x82BBCC10
// RVA : 0x00BBCC10
// PDB : w:\tech5\tungsten\game\decls\declcameratrigger.cpp
// ========================================================================

void _unwind_487311()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idDeclCameraTrigger@@UAA@XZ
// EA  : 0x82BBCC50
// RVA : 0x00BBCC50
// PDB : w:\tech5\tungsten\game\decls\declcameratrigger.cpp
// ========================================================================

void __fastcall idDeclCameraTrigger::~idDeclCameraTrigger(idDeclCameraTrigger *this)
{
  idDeclCameraTrigger::idCameraTriggerParms *list; // r3

  this->__vftable = (idDeclCameraTrigger_vtbl *)&idDeclCameraTrigger::`vftable';
  if ( this->triggers.listStatic == 0 || this->triggers.listStatic == 2 )
  {
    list = this->triggers.list;
    if ( list != nullptr )
      idListArrayDelete<idDeclCameraTrigger::idCameraTriggerParms>(ptr: list, num: this->triggers.size);
    this->triggers.list = nullptr;
    this->triggers.size = 0;
  }
  this->triggers.num = 0;
  idDeclTypeInfo::~idDeclTypeInfo(this: &this->idDeclTypeInfo);
}


// ========================================================================
// __unwind$487345
// EA  : 0x82BBCCBC
// RVA : 0x00BBCCBC
// PDB : w:\tech5\tungsten\game\decls\declcameratrigger.cpp
// ========================================================================

void _unwind_487345()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}

