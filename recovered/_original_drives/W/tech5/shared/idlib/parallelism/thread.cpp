
// ========================================================================
// ??0idSysThread@@QAA@XZ
// EA  : 0x82F7D170
// RVA : 0x00F7D170
// PDB : w:\tech5\shared\idlib\parallelism\thread.cpp
// ========================================================================

idSysThread *__fastcall idSysThread::idSysThread(idSysThread *this)
{
  this->__vftable = (idSysThread_vtbl *)&idSysThread::`vftable';
  this->name.len = 0;
  this->name.allocedAndFlag = 20;
  this->name.data = this->name.baseBuffer;
  this->name.baseBuffer[0] = 0;
  this->isTerminating = false;
  this->threadHandle = 0;
  this->isWorker = false;
  this->isRunning = false;
  this->moreWorkToDo = false;
  Sys_SignalCreate(handle: &this->signalWorkerDone.handle, manualReset: true);
  Sys_SignalCreate(handle: &this->signalMoreWorkToDo.handle, manualReset: false);
  Sys_MutexCreate(handle: &this->signalMutex.handle);
  return this;
}


// ========================================================================
// __unwind$111630
// EA  : 0x82F7D20C
// RVA : 0x00F7D20C
// PDB : w:\tech5\shared\idlib\parallelism\thread.cpp
// ========================================================================

void _unwind_111630()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$111631
// EA  : 0x82F7D238
// RVA : 0x00F7D238
// PDB : w:\tech5\shared\idlib\parallelism\thread.cpp
// ========================================================================

void _unwind_111631()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 112 + 132) + 44));
}


// ========================================================================
// __unwind$111632
// EA  : 0x82F7D264
// RVA : 0x00F7D264
// PDB : w:\tech5\shared\idlib\parallelism\thread.cpp
// ========================================================================

void _unwind_111632()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 112 + 132) + 48));
}


// ========================================================================
// ?WaitForThread@idSysThread@@QAAXXZ
// EA  : 0x82F7D290
// RVA : 0x00F7D290
// PDB : w:\tech5\shared\idlib\parallelism\thread.cpp
// ========================================================================

void __fastcall idSysThread::WaitForThread(idSysThread *this)
{
  if ( this->isWorker )
  {
    Sys_SignalWait(handle: &this->signalWorkerDone.handle, timeout: -1);
  }
  else if ( this->isRunning )
  {
    Sys_JoinThread(threadHandle: this->threadHandle);
    this->threadHandle = 0;
  }
}


// ========================================================================
// ?SignalWork@idSysThread@@QAAXXZ
// EA  : 0x82F7D300
// RVA : 0x00F7D300
// PDB : w:\tech5\shared\idlib\parallelism\thread.cpp
// ========================================================================

void __fastcall idSysThread::SignalWork(idSysThread *this)
{
  idSysMutex *p_signalMutex; // r30

  if ( this->isWorker )
  {
    p_signalMutex = &this->signalMutex;
    Sys_MutexLock(handle: &this->signalMutex.handle, blocking: true);
    this->moreWorkToDo = true;
    Sys_SignalClear(handle: &this->signalWorkerDone.handle);
    Sys_SignalRaise(handle: &this->signalMoreWorkToDo.handle);
    Sys_MutexUnlock(handle: &p_signalMutex->handle);
  }
}


// ========================================================================
// ?ThreadProc@idSysThread@@CAHPAV1@@Z
// EA  : 0x82F7D370
// RVA : 0x00F7D370
// PDB : w:\tech5\shared\idlib\parallelism\thread.cpp
// ========================================================================

int __fastcall idSysThread::ThreadProc(idSysThread *thread)
{
  int v2; // r27
  idSysMutex *p_signalMutex; // r30
  idSysSignal *p_signalMoreWorkToDo; // r29
  int result; // r3

  v2 = 0;
  if ( thread->isWorker )
  {
    p_signalMutex = &thread->signalMutex;
    p_signalMoreWorkToDo = &thread->signalMoreWorkToDo;
    while ( 1 )
    {
      while ( 1 )
      {
        Sys_MutexLock(handle: &p_signalMutex->handle, blocking: true);
        if ( thread->moreWorkToDo )
          break;
        Sys_SignalRaise(handle: &thread->signalWorkerDone.handle);
        Sys_MutexUnlock(handle: &p_signalMutex->handle);
        Sys_SignalWait(handle: &p_signalMoreWorkToDo->handle, timeout: -1);
      }
      thread->moreWorkToDo = false;
      Sys_SignalClear(handle: &p_signalMoreWorkToDo->handle);
      Sys_MutexUnlock(handle: &p_signalMutex->handle);
      if ( thread->isTerminating )
        break;
      v2 = thread->Run(this: thread);
    }
    Sys_SignalRaise(handle: &thread->signalWorkerDone.handle);
    thread->isRunning = false;
    return v2;
  }
  else
  {
    result = thread->Run(this: thread);
    thread->isRunning = false;
  }
  return result;
}


// ========================================================================
// ?StartThread@idSysThread@@QAA_NPBDW4core_t@@W4xthreadPriority@@H@Z
// EA  : 0x82F7D450
// RVA : 0x00F7D450
// PDB : w:\tech5\shared\idlib\parallelism\thread.cpp
// ========================================================================

int __fastcall idSysThread::StartThread(
        idSysThread *this,
        const char *name_,
        core_t core,
        xthreadPriority priority,
        int stackSize)
{
  unsigned int threadHandle; // r3

  if ( this->isRunning )
    return 0;
  idStr::operator=(this: &this->name, text: name_);
  threadHandle = this->threadHandle;
  this->isTerminating = false;
  if ( threadHandle != 0 )
  {
    Sys_JoinThread(threadHandle);
    this->threadHandle = 0;
  }
  this->threadHandle = Sys_CreateThread(
                         function: (unsigned int (__fastcall *)(void *))idSysThread::ThreadProc,
                         parms: this,
                         priority,
                         name: this->name.data,
                         core,
                         stackSize,
                         suspended: false);
  this->isRunning = true;
  return 1;
}


// ========================================================================
// ?StartWorkerThread@idSysThread@@QAA_NPBDW4core_t@@W4xthreadPriority@@H@Z
// EA  : 0x82F7D4E8
// RVA : 0x00F7D4E8
// PDB : w:\tech5\shared\idlib\parallelism\thread.cpp
// ========================================================================

int __fastcall idSysThread::StartWorkerThread(
        idSysThread *this,
        const char *name_,
        core_t core,
        xthreadPriority priority,
        int stackSize)
{
  int started; // r30

  if ( this->isRunning )
    return 0;
  this->isWorker = true;
  started = idSysThread::StartThread(this, name_, core, priority, stackSize);
  Sys_SignalWait(handle: &this->signalWorkerDone.handle, timeout: -1);
  return started;
}


// ========================================================================
// ?StopThread@idSysThread@@QAAX_N@Z
// EA  : 0x82F7D550
// RVA : 0x00F7D550
// PDB : w:\tech5\shared\idlib\parallelism\thread.cpp
// ========================================================================

void __fastcall idSysThread::StopThread(idSysThread *this, bool wait)
{
  idSysMutex *p_signalMutex; // r30

  if ( this->isRunning )
  {
    if ( this->isWorker )
    {
      p_signalMutex = &this->signalMutex;
      Sys_MutexLock(handle: &this->signalMutex.handle, blocking: true);
      this->moreWorkToDo = true;
      Sys_SignalClear(handle: &this->signalWorkerDone.handle);
      this->isTerminating = true;
      Sys_SignalRaise(handle: &this->signalMoreWorkToDo.handle);
      Sys_MutexUnlock(handle: &p_signalMutex->handle);
    }
    else
    {
      this->isTerminating = true;
    }
    if ( wait )
      idSysThread::WaitForThread(this);
  }
}


// ========================================================================
// ??1idSysThread@@UAA@XZ
// EA  : 0x82F7D5E0
// RVA : 0x00F7D5E0
// PDB : w:\tech5\shared\idlib\parallelism\thread.cpp
// ========================================================================

void __fastcall idSysThread::~idSysThread(idSysThread *this)
{
  unsigned int threadHandle; // r3

  this->__vftable = (idSysThread_vtbl *)&idSysThread::`vftable';
  idSysThread::StopThread(this, wait: true);
  threadHandle = this->threadHandle;
  if ( threadHandle != 0 )
  {
    Sys_JoinThread(threadHandle);
    this->threadHandle = 0;
  }
  Sys_MutexDestroy(handle: &this->signalMutex.handle);
  Sys_SignalDestroy(handle: &this->signalMoreWorkToDo.handle);
  Sys_SignalDestroy(handle: &this->signalWorkerDone.handle);
  idStr::FreeData(this: &this->name);
}


// ========================================================================
// __unwind$112009
// EA  : 0x82F7D664
// RVA : 0x00F7D664
// PDB : w:\tech5\shared\idlib\parallelism\thread.cpp
// ========================================================================

void _unwind_112009()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$112010
// EA  : 0x82F7D690
// RVA : 0x00F7D690
// PDB : w:\tech5\shared\idlib\parallelism\thread.cpp
// ========================================================================

void _unwind_112010()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 112 + 132) + 44));
}


// ========================================================================
// __unwind$112011
// EA  : 0x82F7D6BC
// RVA : 0x00F7D6BC
// PDB : w:\tech5\shared\idlib\parallelism\thread.cpp
// ========================================================================

void _unwind_112011()
{
  int v0; // r12

  idSysSignal::~idSysSignal(this: (idSysSignal *)(*(_DWORD *)(v0 - 112 + 132) + 48));
}


// ========================================================================
// __unwind$112012
// EA  : 0x82F7D6E8
// RVA : 0x00F7D6E8
// PDB : w:\tech5\shared\idlib\parallelism\thread.cpp
// ========================================================================

void _unwind_112012()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 52));
}

