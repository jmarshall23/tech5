
// ========================================================================
// ?AddRef@idSWFScriptFunction_Script@@UAAXXZ
// EA  : 0x8264DA80
// RVA : 0x0064DA80
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

void __fastcall idSWFScriptFunction_Script::AddRef(idSWFScriptFunction_RefCounted *this)
{
  ++this->refCount;
}


// ========================================================================
// ?Release@idSWFScriptFunction_RefCounted@@UAAXXZ
// EA  : 0x8264DA90
// RVA : 0x0064DA90
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

void __fastcall idSWFScriptFunction_RefCounted::Release(idSWFScriptFunction_RefCounted *this)
{
  int v1; // r11

  v1 = this->refCount - 1;
  this->refCount = v1;
  if ( v1 <= 0 )
    ((void (__fastcall *)(idSWFScriptFunction_RefCounted *, int))this->dtr_idSWFScriptFunction)(a1: this, a2: 1);
}


// ========================================================================
// ??1idSWFConstantPool@@QAA@XZ
// EA  : 0x82784F80
// RVA : 0x00784F80
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

void __fastcall idSWFConstantPool::~idSWFConstantPool(idSWFConstantPool *this)
{
  idSWFConstantPool::Clear(this);
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// __unwind$222171
// EA  : 0x82784FC4
// RVA : 0x00784FC4
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

void _unwind_222171()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// ?AllocParameters@idSWFScriptFunction_Script@@QAAXH@Z
// EA  : 0x82785250
// RVA : 0x00785250
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

void __fastcall idSWFScriptFunction_Script::AllocParameters(idSWFScriptFunction_Script *this, int numParms)
{
  idList<idSWFScriptFunction_Script::parmInfo_t,72> *p_parameters; // r30
  int size; // r11

  p_parameters = &this->parameters;
  if ( numParms <= this->parameters.size
    || idList<idDeclMD6::includeDecl_t,5>::Resize(
         this: (idList<idSkinMapping,46> *)&this->parameters,
         newsize: numParms) )
  {
    size = p_parameters->size;
    if ( numParms < size )
      size = numParms;
    p_parameters->num = size;
  }
}


// ========================================================================
// ?Release@idSWFScriptFunction_Script@@UAAXXZ
// EA  : 0x827858E0
// RVA : 0x007858E0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

void __fastcall idSWFScriptFunction_Script::Release(idSWFScriptFunction_Script *this)
{
  int v1; // r11

  v1 = this->refCount - 1;
  this->refCount = v1;
  if ( v1 == 0 )
    ((void (__fastcall *)(idSWFScriptFunction_Script *, int))this->dtr_idSWFScriptFunction)(a1: this, a2: 1);
}


// ========================================================================
// ?GetFullPath@idFile_SaveGamePipelined@@UBAPBDXZ
// EA  : 0x82785908
// RVA : 0x00785908
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

int __fastcall idFile_SaveGamePipelined::GetFullPath(XGRAPHICS::IRInst *this)
{
  return this->num_inputs;
}


// ========================================================================
// ?SetPrototype@idSWFScriptFunction_Script@@UAAXPAVidSWFScriptObject@@@Z
// EA  : 0x82785910
// RVA : 0x00785910
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

void __fastcall idSWFScriptFunction_Script::SetPrototype(
        idSWFScriptFunction_Script *this,
        idSWFScriptObject *_prototype)
{
  ++_prototype->refCount;
  this->prototype = _prototype;
}


// ========================================================================
// ?Pop@idSWFStack@@QAAXH@Z
// EA  : 0x827859A0
// RVA : 0x007859A0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

void __fastcall idSWFStack::Pop(idSWFStack *this, int n)
{
  int num; // r11
  int v4; // r31
  int size; // r11

  num = this->num;
  v4 = num - n;
  if ( num - n <= this->size
    || (unsigned __int8)idList<idSWFScriptVar,72>::Resize((idList<idSWFScriptVar,5> *)this, newsize: num - n) != 0 )
  {
    size = this->size;
    if ( v4 < size )
      size = v4;
    this->num = size;
  }
}


// ========================================================================
// ??0idSWFScriptFunction_Script@@QAA@XZ
// EA  : 0x82785A18
// RVA : 0x00785A18
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

idSWFScriptFunction_Script *__fastcall idSWFScriptFunction_Script::idSWFScriptFunction_Script(
        idSWFScriptFunction_Script *this)
{
  int size; // r11

  this->flags = 0;
  this->refCount = 1;
  this->__vftable = (idSWFScriptFunction_Script_vtbl *)&idSWFScriptFunction_Script::`vftable';
  this->data = nullptr;
  this->length = 0;
  this->prototype = nullptr;
  this->defaultSprite = nullptr;
  this->scope.size = 19;
  this->scope.num = 0;
  this->scope.granularity = 1;
  this->scope.list = this->scope.staticList;
  this->scope.memTag = 5;
  this->scope.listStatic = 1;
  this->constants.pool.list = nullptr;
  this->constants.pool.granularity = 0;
  this->constants.pool.memTag = 72;
  this->constants.pool.listStatic = 0;
  this->constants.pool.size = 0;
  this->constants.pool.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constants);
  this->registers.granularity = 0;
  this->registers.memTag = 72;
  this->registers.listStatic = 0;
  this->registers.list = nullptr;
  this->registers.size = 0;
  this->registers.num = 0;
  this->parameters.list = nullptr;
  this->parameters.granularity = 0;
  this->parameters.memTag = 72;
  this->parameters.listStatic = 0;
  this->parameters.size = 0;
  this->parameters.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->parameters);
  if ( this->registers.size >= 4
    || (unsigned __int8)idList<idSWFScriptVar,72>::Resize(
                          this: (idList<idSWFScriptVar,5> *)&this->registers,
                          newsize: 4) != 0 )
  {
    size = this->registers.size;
    if ( size > 4 )
      size = 4;
    this->registers.num = size;
  }
  return this;
}


// ========================================================================
// __unwind$223235
// EA  : 0x82785B30
// RVA : 0x00785B30
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

void _unwind_223235()
{
  int v0; // r12

  idMainMenu::idSWFScriptFunction_setUseVibrate::~idSWFScriptFunction_setUseVibrate(this: *(idSWFScriptFunction_RefCounted **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$223236
// EA  : 0x82785B58
// RVA : 0x00785B58
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

void _unwind_223236()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 28));
}


// ========================================================================
// __unwind$223237
// EA  : 0x82785B84
// RVA : 0x00785B84
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

void _unwind_223237()
{
  int v0; // r12

  idSWFConstantPool::~idSWFConstantPool(this: (idSWFConstantPool *)(*(_DWORD *)(v0 - 144 + 164) + 120));
}


// ========================================================================
// __unwind$223238
// EA  : 0x82785BB0
// RVA : 0x00785BB0
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

void _unwind_223238()
{
  int v0; // r12

  idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: (idList<idSWFScriptVar,5> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                         + 136));
}


// ========================================================================
// __unwind$223239
// EA  : 0x82785BDC
// RVA : 0x00785BDC
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

void _unwind_223239()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 152));
}


// ========================================================================
// ?Alloc@idSWFScriptFunction_Script@@SAPAV1@XZ
// EA  : 0x82785C10
// RVA : 0x00785C10
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

idSWFScriptFunction_Script *__fastcall idSWFScriptFunction_Script::Alloc()
{
  idSWFScriptFunction_Script *v0; // r3

  v0 = (idSWFScriptFunction_Script *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0xA8u,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
  if ( v0 != nullptr )
    return idSWFScriptFunction_Script::idSWFScriptFunction_Script(this: v0);
  else
    return nullptr;
}


// ========================================================================
// __unwind$223339
// EA  : 0x82785C78
// RVA : 0x00785C78
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

void _unwind_223339()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_SWF);
}


// ========================================================================
// ?AllocRegisters@idSWFScriptFunction_Script@@QAAXH@Z
// EA  : 0x82785CA8
// RVA : 0x00785CA8
// PDB : w:\tech5\engine\guis\swf\swf_scriptfunction.h
// ========================================================================

void __fastcall idSWFScriptFunction_Script::AllocRegisters(idSWFScriptFunction_Script *this, int numRegs)
{
  idList<idSWFScriptVar,72> *p_registers; // r30
  int size; // r11

  p_registers = &this->registers;
  if ( numRegs <= this->registers.size
    || (unsigned __int8)idList<idSWFScriptVar,72>::Resize(
                          this: (idList<idSWFScriptVar,5> *)&this->registers,
                          newsize: numRegs) != 0 )
  {
    size = p_registers->size;
    if ( numRegs < size )
      size = numRegs;
    p_registers->num = size;
  }
}

