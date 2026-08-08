
// ========================================================================
// ??0idDeclEmblem@@QAA@XZ
// EA  : 0x82BBDBA0
// RVA : 0x00BBDBA0
// PDB : w:\tech5\tungsten\game\decls\declemblems.cpp
// ========================================================================

idDeclEmblem *__fastcall idDeclEmblem::idDeclEmblem(idDeclEmblem *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->icon = nullptr;
  this->__vftable = (idDeclEmblem_vtbl *)&idDeclEmblem::`vftable';
  this->requirements.list = nullptr;
  this->requirements.granularity = 0;
  this->requirements.memTag = 5;
  this->requirements.listStatic = 0;
  this->requirements.size = 0;
  this->requirements.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->requirements);
  this->category = EMBLEM_COOP;
  this->allEventsRequired = true;
  this->unlockDescription.index = -1;
  return this;
}


// ========================================================================
// __unwind$488096_0
// EA  : 0x82BBDC1C
// RVA : 0x00BBDC1C
// PDB : w:\tech5\tungsten\game\decls\declemblems.cpp
// ========================================================================

void _unwind_488096_0()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idDeclEmblem@@UAA@XZ
// EA  : 0x82BBDC60
// RVA : 0x00BBDC60
// PDB : w:\tech5\tungsten\game\decls\declemblems.cpp
// ========================================================================

void __fastcall idDeclEmblem::~idDeclEmblem(idDeclEmblem *this)
{
  this->__vftable = (idDeclEmblem_vtbl *)&idDeclEmblem::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->requirements);
  idDeclTypeInfo::~idDeclTypeInfo(this);
}


// ========================================================================
// __unwind$488128_0
// EA  : 0x82BBDCB4
// RVA : 0x00BBDCB4
// PDB : w:\tech5\tungsten\game\decls\declemblems.cpp
// ========================================================================

void _unwind_488128_0()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// `dynamic initializer for 'idDeclEmblem::orderedList''
// EA  : 0x833723A0
// RVA : 0x013723A0
// PDB : w:\tech5\tungsten\game\decls\declemblems.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idDeclEmblem::orderedList__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idDeclEmblem::orderedList__);
}

