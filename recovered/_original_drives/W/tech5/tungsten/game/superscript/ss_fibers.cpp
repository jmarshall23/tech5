
// ========================================================================
// ?IsWaitingForFSM@idSSFiber@@QAA_NXZ
// EA  : 0x82EAB1A8
// RVA : 0x00EAB1A8
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.cpp
// ========================================================================

BOOL __fastcall idSSFiber::IsWaitingForFSM(idSSFiber *this)
{
  return this->waitingForFSM;
}


// ========================================================================
// ?ListFibers@idSuperScriptSystem@@QAAXXZ
// EA  : 0x82EAB1B0
// RVA : 0x00EAB1B0
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::ListFibers(idSuperScriptSystem *this)
{
  int v2; // r21
  int v3; // r24
  int v4; // r26
  idSSFiber **list; // r11
  idSSFiber *v6; // r10
  _DWORD *v7; // r31
  idSSObject *object; // r11
  const char *v9; // r29
  idGameLocal_vtbl *v10; // r30
  int v11; // r3
  int v12; // r3
  int v13; // r3
  const char *v14; // r30
  int v15; // r31
  const char *v16; // r3

  v2 = 0;
  v3 = 0;
  if ( this->fibers.num > 0 )
  {
    v4 = 0;
    do
    {
      list = this->fibers.list;
      v6 = list[v4];
      if ( v6 != nullptr )
      {
        v7 = &list[v4]->__vftable;
        object = v6->object;
        if ( object != nullptr )
        {
          v9 = "<null>";
          v10 = gameLocal->__vftable;
          v11 = ((int (*)(void))object->_getEntity)();
          v12 = (int)v10->GetEntityForSpawnId_2(this: gameLocal, a2: v11);
          if ( v12 != 0 )
            v9 = *(const char **)(v12 + 16);
          v13 = v7[5];
          v14 = (const char *)v7[1];
          v15 = v7[6];
          v16 = (const char *)(*(int (__fastcall **)(int))(*(_DWORD *)v13 + 92))(a1: v13);
          idLib::Printf(fmt: "%d: %s.%s.%s\n", v15, v9, v16, v14);
        }
        else
        {
          idLib::Printf(fmt: "%d: ^1Invalid Thread Named %s^0\n", v6->id, v6->name);
        }
        ++v2;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->fibers.num );
  }
  idLib::Printf(fmt: "%d active fibers\n", v2);
}


// ========================================================================
// ?listFibers_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EAB2D0
// RVA : 0x00EAB2D0
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.cpp
// ========================================================================

void __fastcall listFibers_f(const idCmdArgs *args)
{
  idSuperScriptSystem::ListFibers(this: &gameLocal->superScript);
}


// ========================================================================
// ?ExecuteFiber@idSuperScriptSystem@@AAA_NPAVidSSFiber@@@Z
// EA  : 0x82EAB2F0
// RVA : 0x00EAB2F0
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.cpp
// ========================================================================

BOOL __fastcall idSuperScriptSystem::ExecuteFiber(idSuperScriptSystem *this, idSSFiber *fiber)
{
  idSuperScript *superScriptInterface; // r29
  idSSFiber *currentFiber; // r26
  BOOL v7; // r28
  int v8; // [sp+54h] [-3Ch]

  superScriptInterface = this->superScriptInterface;
  if ( superScriptInterface == nullptr )
    return false;
  v8 = (int)superScriptInterface->Lock(this: this->superScriptInterface, a2: this);
  currentFiber = this->currentFiber;
  this->currentFiber = fiber;
  v7 = idSysFiber::Execute(this: fiber);
  this->currentFiber = currentFiber;
  superScriptInterface->Lock(this: superScriptInterface, a2: (idGameSuperInterface *)v8);
  return v7;
}


// ========================================================================
// __unwind$487539
// EA  : 0x82EAB37C
// RVA : 0x00EAB37C
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.cpp
// ========================================================================

void _unwind_487539()
{
  int v0; // r12

  idSSLock::~idSSLock(this: (idSSLock *)(v0 - 144 + 80));
}


// ========================================================================
// ?RunFibers@idSuperScriptSystem@@QAAXXZ
// EA  : 0x82EAB3A8
// RVA : 0x00EAB3A8
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.cpp
// ========================================================================

void __fastcall idSuperScriptSystem::RunFibers(idSuperScriptSystem *this)
{
  int num; // r10
  int v3; // r29
  int v4; // r31
  idSSFiber **list; // r11
  idSSFiber *v6; // r3
  int v7; // r11
  idList<idSSFiber *,108> *p_fibers; // r8
  int v9; // r9
  int v10; // r10
  int v11; // r10

  num = this->fibers.num;
  v3 = 0;
  if ( num > 0 )
  {
    v4 = 0;
    do
    {
      list = this->fibers.list;
      if ( list[v4] != nullptr && !idSuperScriptSystem::ExecuteFiber(this, fiber: list[v4]) )
      {
        v6 = this->fibers.list[v4];
        if ( v6 != nullptr )
          ((void (__fastcall *)(idSSFiber *, int))v6->dtr_idSysFiber)(a1: v6, a2: 1);
        this->fibers.list[v4] = nullptr;
      }
      num = this->fibers.num;
      ++v3;
      ++v4;
    }
    while ( v3 < num );
  }
  v7 = 0;
  if ( num > 0 )
  {
    p_fibers = &this->fibers;
    v9 = 0;
    do
    {
      if ( p_fibers->list[v9] == nullptr )
      {
        if ( v7 >= 0 )
        {
          v10 = this->fibers.num;
          if ( v7 < v10 )
          {
            v11 = v10 - 1;
            this->fibers.num = v11;
            if ( v7 != v11 )
              p_fibers->list[v9] = p_fibers->list[v11];
          }
        }
        --v7;
        --v9;
      }
      ++v7;
      ++v9;
    }
    while ( v7 < this->fibers.num );
  }
}


// ========================================================================
// ?Free@idSSFiber@@QAAXPAX@Z
// EA  : 0x82EAB4B8
// RVA : 0x00EAB4B8
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.cpp
// ========================================================================

void __fastcall idSSFiber::Free(
        idSSFiber *this,
        idMapChangeListener *data,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idMapChangeListener *a14)
{
  a14 = data;
  idList<void *,108>::RemoveFast(this: (idList<idMapChangeListener *,5> *)&this->allocations, obj: &a14);
  idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
}


// ========================================================================
// ??1idSSFiber@@UAA@XZ
// EA  : 0x82EAB510
// RVA : 0x00EAB510
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.cpp
// ========================================================================

void __fastcall idSSFiber::~idSSFiber(idSSFiber *this)
{
  int v2; // r29
  int v3; // r28
  void **list; // r4
  void **v5; // r4

  this->__vftable = (idSSFiber_vtbl *)&idSSFiber::`vftable';
  v2 = 0;
  if ( this->allocations.num > 0 )
  {
    v3 = 0;
    do
    {
      idMem::Free(this: &mem, ptr: this->allocations.list[v3], align: ALIGN_16);
      ++v2;
      ++v3;
    }
    while ( v2 < this->allocations.num );
  }
  if ( this->allocations.listStatic == 0 || this->allocations.listStatic == 2 )
  {
    list = this->allocations.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->allocations.list = nullptr;
    this->allocations.size = 0;
  }
  this->allocations.num = 0;
  if ( this->allocations.listStatic == 0 || this->allocations.listStatic == 2 )
  {
    v5 = this->allocations.list;
    if ( v5 != nullptr )
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    this->allocations.list = nullptr;
    this->allocations.size = 0;
  }
  this->allocations.num = 0;
  idSysFiber::~idSysFiber(this);
}


// ========================================================================
// __unwind$487716
// EA  : 0x82EAB604
// RVA : 0x00EAB604
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.cpp
// ========================================================================

void _unwind_487716()
{
  int v0; // r12

  idSysFiber::~idSysFiber(this: *(idSysFiber **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$487717_0
// EA  : 0x82EAB62C
// RVA : 0x00EAB62C
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.cpp
// ========================================================================

void _unwind_487717_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 32));
}


// ========================================================================
// ?Allocate@idSSFiber@@QAAPAXH@Z
// EA  : 0x82EAB658
// RVA : 0x00EAB658
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.cpp
// ========================================================================

void *__fastcall idSSFiber::Allocate(idSSFiber *this, unsigned int len)
{
  void *v3; // r31
  void *v5; // [sp+50h] [-20h] BYREF

  v5 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\tungsten\\game\\superscript\\ss_fibers.cpp(28) : TAG_SUPERSCRIPT",
         size: len,
         tag: TAG_SUPERSCRIPT,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  v3 = v5;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->allocations,
    obj: (encounterGroupRole_t *)&v5);
  return v3;
}


// ========================================================================
// `dynamic initializer for 'listFibers_v''
// EA  : 0x83392D10
// RVA : 0x01392D10
// PDB : w:\tech5\tungsten\game\superscript\ss_fibers.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__listFibers_v__()
{
  return idCommandLink::idCommandLink(
           this: &listFibers_v,
           cmdName: "listFibers",
           function: listFibers_f,
           description: "Lists the fibers in the script system",
           argCompletion: nullptr);
}

