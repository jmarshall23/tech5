
// ========================================================================
// ??0idHandsBobCycleSingleCycleData_t@@QAA@XZ
// EA  : 0x82BD1F70
// RVA : 0x00BD1F70
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

idHandsBobCycleSingleCycleData_t *__fastcall idHandsBobCycleSingleCycleData_t::idHandsBobCycleSingleCycleData_t(
        idHandsBobCycleSingleCycleData_t *this)
{
  this->enable = true;
  this->cyclesPerSec = 1.0;
  this->cyclesPerSecMin = 0.1;
  this->targetAlpha = 0.5;
  this->alphaRate = 15.0;
  this->attackBias = 0.0;
  idStr::idStr(this: &this->state_right, text: &byte_8200D768);
  idStr::idStr(this: &this->state_left, text: &byte_8200D768);
  this->state_secs = 0.0;
  this->maxPlayerSpeed = 0.0;
  this->bobType = BOBTYPE_IDLE;
  this->animRate = 1.0;
  return this;
}


// ========================================================================
// __unwind$499335
// EA  : 0x82BD201C
// RVA : 0x00BD201C
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

void _unwind_499335()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 24));
}


// ========================================================================
// ??0idDeclHandsBobCycle@@QAA@XZ
// EA  : 0x82BD2050
// RVA : 0x00BD2050
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

idDeclHandsBobCycle *__fastcall idDeclHandsBobCycle::idDeclHandsBobCycle(idDeclHandsBobCycle *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this);
  this->__vftable = (idDeclHandsBobCycle_vtbl *)&idDeclHandsBobCycle::`vftable';
  idAtomicString::Set(this: &this->subweb, str_: &byte_8200D768);
  idHandsBobCycleSingleCycleData_t::idHandsBobCycleSingleCycleData_t(this: &this->idleData);
  idHandsBobCycleSingleCycleData_t::idHandsBobCycleSingleCycleData_t(this: &this->runData);
  idHandsBobCycleSingleCycleData_t::idHandsBobCycleSingleCycleData_t(this: &this->sprintData);
  idHandsBobCycleSingleCycleData_t::idHandsBobCycleSingleCycleData_t(this: &this->crouchData);
  idHandsBobCycleSingleCycleData_t::idHandsBobCycleSingleCycleData_t(this: &this->zoomData);
  idHandsBobCycleSingleCycleData_t::idHandsBobCycleSingleCycleData_t(this: &this->pdaData);
  this->scaleAlphaWithSpeed = true;
  this->hasSprint = true;
  this->inited = false;
  return this;
}


// ========================================================================
// __unwind$499356
// EA  : 0x82BD20F0
// RVA : 0x00BD20F0
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

void _unwind_499356()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$499357
// EA  : 0x82BD2118
// RVA : 0x00BD2118
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

void _unwind_499357()
{
  int v0; // r12

  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: (idHandsBobCycleSingleCycleData_t *)(*(_DWORD *)(v0 - 112 + 132) + 68));
}


// ========================================================================
// __unwind$499358
// EA  : 0x82BD2144
// RVA : 0x00BD2144
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

void _unwind_499358()
{
  int v0; // r12

  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: (idHandsBobCycleSingleCycleData_t *)(*(_DWORD *)(v0 - 112 + 132) + 172));
}


// ========================================================================
// __unwind$499359
// EA  : 0x82BD2170
// RVA : 0x00BD2170
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

void _unwind_499359()
{
  int v0; // r12

  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: (idHandsBobCycleSingleCycleData_t *)(*(_DWORD *)(v0 - 112 + 132) + 276));
}


// ========================================================================
// __unwind$499360
// EA  : 0x82BD219C
// RVA : 0x00BD219C
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

void _unwind_499360()
{
  int v0; // r12

  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: (idHandsBobCycleSingleCycleData_t *)(*(_DWORD *)(v0 - 112 + 132) + 380));
}


// ========================================================================
// __unwind$499361
// EA  : 0x82BD21C8
// RVA : 0x00BD21C8
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

void _unwind_499361()
{
  int v0; // r12

  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: (idHandsBobCycleSingleCycleData_t *)(*(_DWORD *)(v0 - 112 + 132) + 484));
}


// ========================================================================
// ?GetDeclInfo@idDeclHandsBobCycle@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BD21F8
// RVA : 0x00BD21F8
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

idDeclInfoTemplate<idDeclHandsBobCycle> *__fastcall idDeclHandsBobCycle::GetDeclInfo(idDeclHandsBobCycle *this)
{
  return &idDeclHandsBobCycle::resourceList;
}


// ========================================================================
// ??1idDeclHandsBobCycle@@UAA@XZ
// EA  : 0x82BD2210
// RVA : 0x00BD2210
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

void __fastcall idDeclHandsBobCycle::~idDeclHandsBobCycle(idDeclHandsBobCycle *this)
{
  this->__vftable = (idDeclHandsBobCycle_vtbl *)&idDeclHandsBobCycle::`vftable';
  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: &this->pdaData);
  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: &this->zoomData);
  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: &this->crouchData);
  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: &this->sprintData);
  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: &this->runData);
  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: &this->idleData);
  idDeclTypeInfo::~idDeclTypeInfo(this);
}


// ========================================================================
// __unwind$499409
// EA  : 0x82BD228C
// RVA : 0x00BD228C
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

void _unwind_499409()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$499410
// EA  : 0x82BD22B4
// RVA : 0x00BD22B4
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

void _unwind_499410()
{
  int v0; // r12

  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: (idHandsBobCycleSingleCycleData_t *)(*(_DWORD *)(v0 - 112 + 132) + 68));
}


// ========================================================================
// __unwind$499411
// EA  : 0x82BD22E0
// RVA : 0x00BD22E0
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

void _unwind_499411()
{
  int v0; // r12

  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: (idHandsBobCycleSingleCycleData_t *)(*(_DWORD *)(v0 - 112 + 132) + 172));
}


// ========================================================================
// __unwind$499412
// EA  : 0x82BD230C
// RVA : 0x00BD230C
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

void _unwind_499412()
{
  int v0; // r12

  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: (idHandsBobCycleSingleCycleData_t *)(*(_DWORD *)(v0 - 112 + 132) + 276));
}


// ========================================================================
// __unwind$499413
// EA  : 0x82BD2338
// RVA : 0x00BD2338
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

void _unwind_499413()
{
  int v0; // r12

  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: (idHandsBobCycleSingleCycleData_t *)(*(_DWORD *)(v0 - 112 + 132) + 380));
}


// ========================================================================
// __unwind$499414
// EA  : 0x82BD2364
// RVA : 0x00BD2364
// PDB : w:\tech5\tungsten\game\decls\declhandsbobcycle.h
// ========================================================================

void _unwind_499414()
{
  int v0; // r12

  idHandsBobCycleSingleCycleData_t::~idHandsBobCycleSingleCycleData_t(this: (idHandsBobCycleSingleCycleData_t *)(*(_DWORD *)(v0 - 112 + 132) + 484));
}

