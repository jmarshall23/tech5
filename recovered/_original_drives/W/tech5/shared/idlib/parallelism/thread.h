
// ========================================================================
// ??1idSysMutex@@QAA@XZ
// EA  : 0x8265CC40
// RVA : 0x0065CC40
// PDB : w:\tech5\shared\idlib\parallelism\thread.h
// ========================================================================

// attributes: thunk
void __fastcall idSysMutex::~idSysMutex(idSysMutex *this)
{
  Sys_MutexDestroy(handle: &this->handle);
}


// ========================================================================
// ??1idScopedCriticalSection@@QAA@XZ
// EA  : 0x82663C78
// RVA : 0x00663C78
// PDB : w:\tech5\shared\idlib\parallelism\thread.h
// ========================================================================

void __fastcall idScopedCriticalSection::~idScopedCriticalSection(idScopedCriticalSection *this)
{
  Sys_MutexUnlock(handle: &this->mutex->handle);
}


// ========================================================================
// ??1idSysSignal@@QAA@XZ
// EA  : 0x8269DE40
// RVA : 0x0069DE40
// PDB : w:\tech5\shared\idlib\parallelism\thread.h
// ========================================================================

// attributes: thunk
void __fastcall idSysSignal::~idSysSignal(idSysSignal *this)
{
  Sys_SignalDestroy(handle: &this->handle);
}


// ========================================================================
// ?Signal@idSysThreadSynchronizer@@QAAXI@Z
// EA  : 0x82F7A6C0
// RVA : 0x00F7A6C0
// PDB : w:\tech5\shared\idlib\parallelism\thread.h
// ========================================================================

void __fastcall idSysThreadSynchronizer::Signal(idSysThreadSynchronizer *this, unsigned int threadNum)
{
  idSysInterlockedInteger *p_busyCount; // r30
  int v4; // r30
  int v5; // r29

  p_busyCount = &this->busyCount;
  if ( Sys_InterlockedDecrement(value: &this->busyCount.value) == 0 )
  {
    p_busyCount->value = this->signals.num;
    __lwsync();
    v4 = 0;
    if ( this->signals.num > 0 )
    {
      v5 = 0;
      do
      {
        Sys_SignalRaise(handle: &this->signals.list[v5]->handle);
        ++v4;
        ++v5;
      }
      while ( v4 < this->signals.num );
    }
  }
}


// ========================================================================
// ?SetNumThreads@idSysThreadSynchronizer@@QAAXI@Z
// EA  : 0x82F7AAE0
// RVA : 0x00F7AAE0
// PDB : w:\tech5\shared\idlib\parallelism\thread.h
// ========================================================================

void __fastcall idSysThreadSynchronizer::SetNumThreads(idSysThreadSynchronizer *this, int num)
{
  int v4; // r28
  int i; // r29
  void **v6; // r3
  idSysSignal *v7; // r30

  if ( num != this->signals.num )
  {
    idList<idSysSignal *,5>::DeleteContents(this: &this->signals);
    idList<idObstacleBuffers *,5>::SetNum((idList<int,37> *)this, newNum: num);
    if ( num != 0 )
    {
      v4 = 0;
      for ( i = num; i != 0; --i )
      {
        v6 = (void **)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 4u,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
        v7 = (idSysSignal *)v6;
        if ( v6 != nullptr )
          Sys_SignalCreate(handle: v6, manualReset: false);
        else
          v7 = nullptr;
        this->signals.list[v4++] = v7;
      }
    }
    this->busyCount.value = num;
    __lwsync();
  }
}


// ========================================================================
// __unwind$112232
// EA  : 0x82F7AB98
// RVA : 0x00F7AB98
// PDB : w:\tech5\shared\idlib\parallelism\thread.h
// ========================================================================

void __fastcall _unwind_112232(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}

