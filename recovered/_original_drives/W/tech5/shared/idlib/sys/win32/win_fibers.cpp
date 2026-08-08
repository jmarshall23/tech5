
// ========================================================================
// ??1idSysFiber@@UAA@XZ
// EA  : 0x82F824C0
// RVA : 0x00F824C0
// PDB : w:\tech5\shared\idlib\sys\win32\win_fibers.cpp
// ========================================================================

void __fastcall idSysFiber::~idSysFiber(idSysFiber *this)
{
  char *name; // r4

  name = this->name;
  this->__vftable = (idSysFiber_vtbl *)&idSysFiber::`vftable';
  idMem::Free(this: &mem, ptr: name, align: ALIGN_16);
  DeleteFiber(lpFiber: this->fiber);
}


// ========================================================================
// ?Execute@idSysFiber@@QAA_NXZ
// EA  : 0x82F82510
// RVA : 0x00F82510
// PDB : w:\tech5\shared\idlib\sys\win32\win_fibers.cpp
// ========================================================================

BOOL __fastcall idSysFiber::Execute(idSysFiber *this)
{
  if ( this->alive )
  {
    this->parent = GetCurrentFiber();
    SwitchToFiber(lpFiber: this->fiber);
  }
  return this->alive;
}


// ========================================================================
// ?YieldFiber@idSysFiber@@IAAXXZ
// EA  : 0x82F82558
// RVA : 0x00F82558
// PDB : w:\tech5\shared\idlib\sys\win32\win_fibers.cpp
// ========================================================================

void __fastcall idSysFiber::YieldFiber(idSysFiber *this)
{
  SwitchToFiber(lpFiber: this->parent);
}


// ========================================================================
// ?FiberRoutine@idSysFiber@@CAXPAX@Z
// EA  : 0x82F825D0
// RVA : 0x00F825D0
// PDB : w:\tech5\shared\idlib\sys\win32\win_fibers.cpp
// ========================================================================

void __fastcall __noreturn idSysFiber::FiberRoutine(void *data)
{
  void *v2; // r3

  (*(void (__fastcall **)(void *))(*(_DWORD *)data + 4))(a1: data);
  v2 = *((void **)data + 4);
  *((_BYTE *)data + 8) = 0;
  SwitchToFiber(lpFiber: v2);
  while ( 1 )
    SwitchToFiber(lpFiber: *((void **)data + 4));
}


// ========================================================================
// $M113704
// EA  : 0x82F82640
// RVA : 0x00F82640
// PDB : w:\tech5\shared\idlib\sys\win32\win_fibers.cpp
// ========================================================================

void *_M113704()
{
  return &_LN9_15;
}


// ========================================================================
// ??0idSysFiber@@QAA@PBD@Z
// EA  : 0x82F82658
// RVA : 0x00F82658
// PDB : w:\tech5\shared\idlib\sys\win32\win_fibers.cpp
// ========================================================================

idSysFiber *__fastcall idSysFiber::idSysFiber(idSysFiber *this, const char *n)
{
  idSysFiber *LastError; // r31
  const char *v3; // r3
  void *Fiber; // r3
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  int v9; // [sp+8h] [-58h]
  int v10; // [sp+Ch] [-54h]
  int v11; // [sp+10h] [-50h]
  int v12; // [sp+14h] [-4Ch]

  LastError = this;
  this->__vftable = (idSysFiber_vtbl *)&idSysFiber::`vftable';
  if ( n != nullptr )
    v3 = n;
  else
    v3 = &byte_8200D768;
  LastError->name = CopyString(str: v3, tag: TAG_FIBER);
  LastError->alive = true;
  LastError->parent = nullptr;
  Fiber = CreateFiber(
            dwStackSize: 0x20000u,
            lpStartAddress: (void (__fastcall *)(void *))idSysFiber::FiberRoutine,
            lpParameter: LastError);
  LastError->fiber = Fiber;
  if ( Fiber == nullptr )
  {
    LastError = (idSysFiber *)GetLastError();
    Sys_DumpMemory();
    idLib::FatalError(
      fmt: __SPAIR64__("Could not allocate fiber - (%d)", (unsigned int)LastError),
      a2: v7,
      a3: v6,
      a4: v5,
      a5: v9,
      a6: v10,
      a7: v11,
      a8: v12);
  }
  return LastError;
}

