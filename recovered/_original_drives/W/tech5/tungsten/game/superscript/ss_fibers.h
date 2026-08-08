
// ========================================================================
// ??0idSSFiber@@QAA@PBDHPAVidSSObject@@@Z
// EA  : 0x82C41CB8
// RVA : 0x00C41CB8
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.h
// ========================================================================

idSSFiber *__fastcall idSSFiber::idSSFiber(idSSFiber *this, const char *name, int fiberId, idSSObject *sso)
{
  idSysFiber::idSysFiber(this, n: name);
  this->object = sso;
  this->id = fiberId;
  this->waitingForFSM = false;
  this->__vftable = (idSSFiber_vtbl *)&idSSFiber::`vftable';
  this->allocations.list = nullptr;
  this->allocations.granularity = 0;
  this->allocations.memTag = 108;
  this->allocations.listStatic = 0;
  this->allocations.size = 0;
  this->allocations.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->allocations);
  return this;
}


// ========================================================================
// __unwind$506197
// EA  : 0x82C41D28
// RVA : 0x00C41D28
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.h
// ========================================================================

void _unwind_506197()
{
  int v0; // r12

  idSysFiber::~idSysFiber(this: *(idSysFiber **)(v0 - 128 + 148));
}


// ========================================================================
// ?Run@?$idSSFiber2@HM@@UAAXXZ
// EA  : 0x82C41D50
// RVA : 0x00C41D50
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.h
// ========================================================================

void __fastcall idSSFiber2<int,float>::Run(idSSFiber2<int,float> *this)
{
  void (__fastcall *function)(idSSObject *, int, float); // r11

  function = (void (__fastcall *)(idSSObject *, int, float))this->function;
  if ( function != nullptr )
    function(a1: this->object, a2: this->parameter1, a3: this->parameter2);
}


// ========================================================================
// ?Run@?$idSSFiber1@H@@UAAXXZ
// EA  : 0x82EAD2F8
// RVA : 0x00EAD2F8
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.h
// ========================================================================

void __fastcall idSSFiber1<int>::Run(idSSFiber1<char const *> *this)
{
  void (__fastcall *function)(idSSObject *, const char *); // r11

  function = this->function;
  if ( function != nullptr )
    function(a1: this->object, a2: this->parameter1);
}

