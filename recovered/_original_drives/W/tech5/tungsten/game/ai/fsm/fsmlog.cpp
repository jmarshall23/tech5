
// ========================================================================
// ?FromLast@idFSMLog@@QBAPBVidFSMLogEntry@@H@Z
// EA  : 0x82AB4620
// RVA : 0x00AB4620
// PDB : w:\tech5\tungsten\game\ai\fsm\fsmlog.cpp
// ========================================================================

const idFSMLogEntry *__fastcall idFSMLog::FromLast(idFSMLog *this, signed int i)
{
  signed int maxSize; // r11
  int num; // r10
  int v4; // r10
  unsigned int v6; // r9
  int v7; // r4

  maxSize = this->maxSize;
  num = this->list.num;
  if ( num >= maxSize )
  {
    if ( i > maxSize )
      return nullptr;
    v6 = maxSize & ~(__ROL4__(i, 1) - 1);
    v7 = this->first - i % maxSize;
    __twllei(maxSize, 0);
    v4 = v7 - 1;
    __twlgei(v6, 0xFFFFFFFF);
    if ( v7 - 1 < 0 )
      v4 += maxSize;
  }
  else
  {
    v4 = num - i - 1;
    if ( v4 < 0 )
      return nullptr;
  }
  return &this->list.list[v4];
}


// ========================================================================
// ??0idFSMLog@@QAA@H@Z
// EA  : 0x82AB4690
// RVA : 0x00AB4690
// PDB : w:\tech5\tungsten\game\ai\fsm\fsmlog.cpp
// ========================================================================

idFSMLog *__fastcall idFSMLog::idFSMLog(idFSMLog *this, int maxSize)
{
  this->list.list = nullptr;
  this->list.granularity = 0;
  this->list.memTag = 5;
  this->list.listStatic = 0;
  this->list.size = 0;
  this->list.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->maxSize = maxSize;
  this->first = 0;
  return this;
}


// ========================================================================
// ??1idFSMLog@@QAA@XZ
// EA  : 0x82AB46E8
// RVA : 0x00AB46E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsmlog.cpp
// ========================================================================

void __fastcall idFSMLog::~idFSMLog(idFSMLog *this)
{
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->first = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$487429
// EA  : 0x82AB4734
// RVA : 0x00AB4734
// PDB : w:\tech5\tungsten\game\ai\fsm\fsmlog.cpp
// ========================================================================

void _unwind_487429()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// ?Alloc@idFSMLog@@QAAAAVidFSMLogEntry@@XZ
// EA  : 0x82AB4968
// RVA : 0x00AB4968
// PDB : w:\tech5\tungsten\game\ai\fsm\fsmlog.cpp
// ========================================================================

idFSMLogEntry *__fastcall idFSMLog::Alloc(idFSMLog *this)
{
  int num; // r9
  int first; // r10

  num = this->list.num;
  if ( num < this->maxSize )
    return idList<idFSMLogEntry,5>::Alloc(this: &this->list);
  first = this->first;
  this->first = first + 1;
  if ( first + 1 >= num )
    this->first = 0;
  return &this->list.list[first];
}

