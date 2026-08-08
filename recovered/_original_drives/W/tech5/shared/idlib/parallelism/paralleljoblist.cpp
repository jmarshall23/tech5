
// ========================================================================
// ?RegisterJob@@YAXP6AXPAX@ZPBD@Z
// EA  : 0x82F7B230
// RVA : 0x00F7B230
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall RegisterJob(void (__fastcall *function)(void *), const char *name)
{
  int v2; // r10
  registeredJob *v3; // r9
  char v4; // r10
  int v5; // r10

  v2 = 0;
  if ( numRegisteredJobs <= 0 )
  {
LABEL_5:
    v4 = 0;
  }
  else
  {
    v3 = registeredJobs;
    while ( v3->function != function )
    {
      ++v2;
      ++v3;
      if ( v2 >= numRegisteredJobs )
        goto LABEL_5;
    }
    v4 = 1;
  }
  if ( v4 == 0 )
  {
    v5 = numRegisteredJobs++;
    registeredJobs[v5].function = function;
    registeredJobs[v5].name = name;
  }
}


// ========================================================================
// ??0idParallelJobRegistration@@QAA@P6AXPAX@ZPBD@Z
// EA  : 0x82F7B2A0
// RVA : 0x00F7B2A0
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

idParallelJobRegistration *__fastcall idParallelJobRegistration::idParallelJobRegistration(
        idParallelJobRegistration *this,
        void (__fastcall *function)(void *),
        const char *name)
{
  RegisterJob(function, name);
  return this;
}


// ========================================================================
// ?GetTotalProcessingTimeMicroSec@idParallelJobList_Threads@@QBA_KXZ
// EA  : 0x82F7B2D8
// RVA : 0x00F7B2D8
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

int __fastcall idParallelJobList_Threads::GetTotalProcessingTimeMicroSec(idParallelJobList_Threads *this)
{
  int v1; // r10
  int v2; // r7
  int v3; // r8
  int v4; // r9
  unsigned __int64 *p_waitTime; // r11
  int i; // ctr
  unsigned __int64 v7; // r4

  v1 = 0;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  p_waitTime = &this->threadStats.waitTime;
  for ( i = 8; i != 0; --i )
  {
    v7 = p_waitTime[3];
    v1 += *((_DWORD *)p_waitTime + 3);
    p_waitTime += 4;
    v4 += *(_DWORD *)p_waitTime;
    v3 += v7;
    v2 += *((_DWORD *)p_waitTime + 1);
  }
  return v2 + v3 + v4 + v1;
}


// ========================================================================
// ?IsSubmitted@idParallelJobList@@QBA_NXZ
// EA  : 0x82F7B328
// RVA : 0x00F7B328
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

BOOL __fastcall idParallelJobList::IsSubmitted(idParallelJobList *this)
{
  return (_cntlzw(this->jobListThreads->done) & 0x20) != 0;
}


// ========================================================================
// ?GetNumExecutedJobs@idParallelJobList@@QBAIXZ
// EA  : 0x82F7B340
// RVA : 0x00F7B340
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

unsigned int __fastcall idParallelJobList::GetNumExecutedJobs(idParallelJobList *this)
{
  return this->jobListThreads->threadStats.numExecutedJobs;
}


// ========================================================================
// ?GetNumSyncs@idParallelJobList@@QBAIXZ
// EA  : 0x82F7B350
// RVA : 0x00F7B350
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

unsigned int __fastcall idParallelJobList::GetNumSyncs(idParallelJobList *this)
{
  return this->jobListThreads->threadStats.numExecutedSyncs;
}


// ========================================================================
// ?GetSubmitTimeMicroSec@idParallelJobList@@QBA_KXZ
// EA  : 0x82F7B360
// RVA : 0x00F7B360
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned __int64 __fastcall idParallelJobList::GetSubmitTimeMicroSec(idParallelJobList *this)
{
  unsigned __int64 result; // r4 OVERLAPPED

  *(unsigned __int64 *)((char *)&result + 4) = this->jobListThreads->threadStats.submitTime;
  return result;
}


// ========================================================================
// ?GetStartTimeMicroSec@idParallelJobList@@QBA_KXZ
// EA  : 0x82F7B370
// RVA : 0x00F7B370
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned __int64 __fastcall idParallelJobList::GetStartTimeMicroSec(idParallelJobList *this)
{
  unsigned __int64 result; // r4 OVERLAPPED

  *(unsigned __int64 *)((char *)&result + 4) = this->jobListThreads->threadStats.startTime;
  return result;
}


// ========================================================================
// ?GetFinishTimeMicroSec@idParallelJobList@@QBA_KXZ
// EA  : 0x82F7B380
// RVA : 0x00F7B380
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned __int64 __fastcall idParallelJobList::GetFinishTimeMicroSec(idParallelJobList *this)
{
  unsigned __int64 result; // r4 OVERLAPPED

  *(unsigned __int64 *)((char *)&result + 4) = this->jobListThreads->threadStats.endTime;
  return result;
}


// ========================================================================
// ?GetWaitTimeMicroSec@idParallelJobList@@QBA_KXZ
// EA  : 0x82F7B390
// RVA : 0x00F7B390
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned __int64 __fastcall idParallelJobList::GetWaitTimeMicroSec(idParallelJobList *this)
{
  unsigned __int64 result; // r4 OVERLAPPED

  *(unsigned __int64 *)((char *)&result + 4) = this->jobListThreads->threadStats.waitTime;
  return result;
}


// ========================================================================
// ?GetTotalProcessingTimeMicroSec@idParallelJobList@@QBA_KXZ
// EA  : 0x82F7B3A0
// RVA : 0x00F7B3A0
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

int __fastcall idParallelJobList::GetTotalProcessingTimeMicroSec(idParallelJobList *this)
{
  return idParallelJobList_Threads::GetTotalProcessingTimeMicroSec(this: this->jobListThreads);
}


// ========================================================================
// ?GetUnitProcessingTimeMicroSec@idParallelJobList@@QBA_KH@Z
// EA  : 0x82F7B3A8
// RVA : 0x00F7B3A8
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idParallelJobList::GetUnitProcessingTimeMicroSec(idParallelJobList *this, unsigned int unit)
{
  int result; // r3 OVERLAPPED

  if ( unit >= 0x20 )
    return 0;
  *(_QWORD *)&result = this->jobListThreads->threadStats.threadExecTime[unit];
  return result;
}


// ========================================================================
// ?GetUnitWastedTimeMicroSec@idParallelJobList@@QBA_KH@Z
// EA  : 0x82F7B3D8
// RVA : 0x00F7B3D8
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

int __fastcall idParallelJobList::GetUnitWastedTimeMicroSec(idParallelJobList *this, unsigned int unit)
{
  if ( unit >= 0x20 )
    return 0;
  else
    return LODWORD(this->jobListThreads->threadStats.threadTotalTime[unit])
         - LODWORD(this->jobListThreads->threadStats.threadExecTime[unit]);
}


// ========================================================================
// ?Shutdown@idParallelJobManagerLocal@@UAAXXZ
// EA  : 0x82F7B418
// RVA : 0x00F7B418
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idParallelJobManagerLocal::Shutdown(idParallelJobManagerLocal *this)
{
  idJobThread *threads; // r30
  int i; // r31

  threads = this->threads;
  for ( i = 4; i != 0; --i )
    idSysThread::StopThread(this: threads++, wait: true);
}


// ========================================================================
// ?GetNumProcessingUnits@idParallelJobManagerLocal@@UAAHXZ
// EA  : 0x82F7B468
// RVA : 0x00F7B468
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

unsigned int __fastcall idParallelJobManagerLocal::GetNumProcessingUnits(idParallelJobManagerLocal *this)
{
  return this->maxThreads;
}


// ========================================================================
// ?RunJobsInternal@idParallelJobList_Threads@@AAAHIAAUthreadJobListState_t@@_N@Z
// EA  : 0x82F7B4D8
// RVA : 0x00F7B4D8
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idParallelJobList_Threads::RunJobsInternal(
        idParallelJobList_Threads *this,
        unsigned int threadNum,
        threadJobListState_t *state,
        bool singleJob)
{
  unsigned __int64 v8; // r3
  idSysInterlockedInteger *p_currentJob; // r3
  int v10; // r15
  int lastJobIndex; // r9
  int *data; // r11
  int signalIndex; // r11
  int v14; // r3
  int v15; // r11
  int v16; // r11
  int *v17; // r11
  int v18; // r10
  unsigned __int64 v19; // r4
  int v20; // r29
  idParallelJobList_Threads::job_t *v21; // r11
  unsigned __int64 v22; // r4 OVERLAPPED
  unsigned int v23; // r11
  __int32 v24; // r5
  double v25; // fp1
  __int64 v26; // r8
  int nextJobIndex; // r11
  __int64 v28; // r10
  registeredJob *v29; // r11
  __int64 v30; // r6
  unsigned __int64 v31; // r3
  int v32; // [sp+8h] [-F8h]
  int v33; // [sp+Ch] [-F4h]
  int v34; // [sp+10h] [-F0h]
  int v35; // [sp+14h] [-ECh]
  idSysInterlockedInteger *v36; // [sp+50h] [-B0h]

  if ( state->version != this->version.value )
    return 2;
  if ( LODWORD(this->deferredThreadStats.startTime) == 0 )
  {
    LODWORD(v8) = Sys_Microseconds() >> 32;
    this->deferredThreadStats.startTime = v8;
  }
  p_currentJob = &this->currentJob;
  v36 = &this->currentJob;
  v10 = 0;
  while ( 1 )
  {
    if ( state->lastJobIndex < p_currentJob->value )
    {
      do
      {
        lastJobIndex = state->lastJobIndex;
        if ( lastJobIndex >= this->jobList.num )
          break;
        data = (int *)this->jobList.list[lastJobIndex].data;
        if ( data == &idParallelJobList_Threads::JOB_SIGNAL )
        {
          ++state->signalIndex;
        }
        else
        {
          if ( data == &idParallelJobList_Threads::JOB_SYNCHRONIZE )
          {
            signalIndex = state->signalIndex;
            goto LABEL_14;
          }
          if ( data == &idParallelJobList_Threads::JOB_LIST_DONE )
          {
            signalIndex = this->signalJobCount.num;
LABEL_14:
            if ( this->signalJobCount.list[signalIndex - 1].value > 0 )
              return v10 | 4;
          }
        }
        state->lastJobIndex = lastJobIndex + 1;
      }
      while ( lastJobIndex + 1 < p_currentJob->value );
    }
    if ( Sys_InterlockedIncrement(value: &this->fetchLock.value) != 1 )
    {
LABEL_24:
      Sys_InterlockedDecrement(value: &this->fetchLock.value);
      return v10 | 4;
    }
    v14 = Sys_InterlockedIncrement(value: &v36->value);
    v15 = state->lastJobIndex;
    state->nextJobIndex = v14 - 1;
    if ( v15 <= v14 - 1 )
    {
      do
      {
        v16 = state->lastJobIndex;
        if ( v16 >= this->jobList.num )
          break;
        v17 = (int *)this->jobList.list[v16].data;
        if ( v17 == &idParallelJobList_Threads::JOB_SIGNAL )
        {
          ++state->signalIndex;
        }
        else if ( v17 == &idParallelJobList_Threads::JOB_SYNCHRONIZE )
        {
          if ( this->signalJobCount.list[state->signalIndex - 1].value > 0 )
            goto LABEL_23;
        }
        else if ( v17 == &idParallelJobList_Threads::JOB_LIST_DONE )
        {
          if ( this->signalJobCount.list[this->signalJobCount.num - 1].value > 0 )
          {
LABEL_23:
            Sys_InterlockedDecrement(value: &v36->value);
            goto LABEL_24;
          }
          Sys_InterlockedDecrement(value: &this->doneGuards[this->currentDoneGuard].value);
        }
        v18 = state->lastJobIndex + 1;
        state->lastJobIndex = v18;
      }
      while ( v18 <= state->nextJobIndex );
    }
    Sys_InterlockedDecrement(value: &this->fetchLock.value);
    if ( state->nextJobIndex >= this->jobList.num )
      return v10 | 2;
    v19 = Sys_Microseconds();
    v20 = HIDWORD(v19);
    v21 = &this->jobList.list[state->nextJobIndex];
    ((void (__fastcall *)(void *, _DWORD))v21->function)(a1: v21->data, a2: v19);
    this->jobList.list[state->nextJobIndex].executed = 1;
    v22 = Sys_Microseconds();
    v23 = 8 * (threadNum + 18);
    v24 = *(jobListId_t *)((char *)&this->listId + v23) - v20 + HIDWORD(v22);
    *(_QWORD *)(&this->threaded + v23) = *(unsigned __int64 *)((char *)&v22 - 4);
    if ( jobs_longJobMicroSec.valueInteger > 0 )
    {
      HIDWORD(v22) -= v20;
      if ( HIDWORD(v22) > jobs_longJobMicroSec.valueInteger && this->listId != JOBLIST_UTILITY )
      {
        v25 = _u64tod(a1: HIDWORD(v22), a2: v22);
        v26 = (unsigned int)numRegisteredJobs;
        longJobTime = (float)v25 * (float)0.001;
        longJobFunc = this->jobList.list[state->nextJobIndex].function;
        nextJobIndex = state->nextJobIndex;
        HIDWORD(v28) = 2 * nextJobIndex;
        longJobData = this->jobList.list[nextJobIndex].data;
        if ( numRegisteredJobs <= 0 )
        {
LABEL_38:
          HIDWORD(v30) = "unknown";
        }
        else
        {
          v29 = registeredJobs;
          while ( 1 )
          {
            HIDWORD(v28) = v29->function;
            if ( v29->function == this->jobList.list[state->nextJobIndex].function )
              break;
            ++HIDWORD(v26);
            ++v29;
            if ( SHIDWORD(v26) >= (int)v26 )
              goto LABEL_38;
          }
          HIDWORD(v30) = registeredJobs[HIDWORD(v26)].name;
        }
        LODWORD(v28) = 4 * this->listId;
        LODWORD(v30) = *(const char **)((char *)jobNames + v28);
        idLib::Debugf(
          fmt: __SPAIR64__("%1.1f milliseconds for a single '%s' job from job list %s\n", COERCE_UNSIGNED_INT64(longJobTime)),
          a2: v30,
          a3: v26,
          a4: v28,
          a5: v32,
          a6: v33,
          a7: v34,
          a8: v35);
      }
    }
    v10 |= 1u;
    if ( Sys_InterlockedDecrement(value: &this->signalJobCount.list[state->signalIndex].value) == 0
      && state->signalIndex == this->signalJobCount.num - 1 )
    {
      break;
    }
    if ( singleJob )
      return v10;
    p_currentJob = &this->currentJob;
  }
  LODWORD(v31) = Sys_Microseconds() >> 32;
  this->deferredThreadStats.endTime = v31;
  return v10 | 2;
}


// ========================================================================
// ?RunJobs@idParallelJobList_Threads@@QAAHIAAUthreadJobListState_t@@_N@Z
// EA  : 0x82F7B918
// RVA : 0x00F7B918
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

int __fastcall idParallelJobList_Threads::RunJobs(
        idParallelJobList_Threads *this,
        unsigned int threadNum,
        threadJobListState_t *state,
        bool singleJob)
{
  int v8; // r26
  int v9; // r28
  unsigned int v10; // r30
  __int64 v11; // r8

  v8 = Sys_Microseconds() >> 32;
  Sys_InterlockedIncrement(value: &this->numThreadsExecuting.value);
  v9 = idParallelJobList_Threads::RunJobsInternal(this, threadNum, state, singleJob);
  Sys_InterlockedDecrement(value: &this->numThreadsExecuting.value);
  v10 = 8 * (threadNum + 50);
  LODWORD(v11) = (Sys_Microseconds() >> 32) + *(jobListId_t *)((char *)&this->listId + v10) - v8;
  *(_QWORD *)(&this->threaded + v10) = v11;
  return v9;
}


// ========================================================================
// ??0idJobThread@@QAA@XZ
// EA  : 0x82F7B998
// RVA : 0x00F7B998
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

idJobThread *__fastcall idJobThread::idJobThread(idJobThread *this)
{
  idSysThread::idSysThread(this);
  this->firstJobList = 0;
  this->__vftable = (idJobThread_vtbl *)&idJobThread::`vftable';
  this->lastJobList = 0;
  Sys_MutexCreate(handle: &this->addJobMutex.handle);
  this->threadNum = 0;
  return this;
}


// ========================================================================
// __unwind$116405
// EA  : 0x82F7B9E4
// RVA : 0x00F7B9E4
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void _unwind_116405()
{
  int v0; // r12

  idSysThread::~idSysThread(this: *(idSysThread **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idJobThread@@UAA@XZ
// EA  : 0x82F7BA18
// RVA : 0x00F7BA18
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idJobThread::~idJobThread(idJobThread *this)
{
  this->__vftable = (idJobThread_vtbl *)&idJobThread::`vftable';
  Sys_MutexDestroy(handle: &this->addJobMutex.handle);
  idSysThread::~idSysThread(this);
}


// ========================================================================
// __unwind$116427
// EA  : 0x82F7BA6C
// RVA : 0x00F7BA6C
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void _unwind_116427()
{
  int v0; // r12

  idSysThread::~idSysThread(this: *(idSysThread **)(v0 - 112 + 132));
}


// ========================================================================
// ?AddJobList@idJobThread@@QAAXPAVidParallelJobList_Threads@@@Z
// EA  : 0x82F7BA98
// RVA : 0x00F7BA98
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idJobThread::AddJobList(idJobThread *this, idParallelJobList_Threads *jobList)
{
  idSysMutex *p_addJobMutex; // r29

  p_addJobMutex = &this->addJobMutex;
  Sys_MutexLock(handle: &this->addJobMutex.handle, blocking: true);
  while ( this->lastJobList - this->firstJobList >= 0x20 )
    Sys_Yield();
  this->jobLists[this->lastJobList & 0x1F].jobList = jobList;
  *(int *)((char *)&this->jobLists[0].version + ((8 * this->lastJobList++) & 0xF8)) = jobList->version.value;
  Sys_MutexUnlock(handle: &p_addJobMutex->handle);
}


// ========================================================================
// ?Run@idJobThread@@EAAHXZ
// EA  : 0x82F7BB30
// RVA : 0x00F7BB30
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

int __fastcall idJobThread::Run(idJobThread *this)
{
  char *v1; // r11
  int i; // ctr
  int v4; // r24
  int v5; // r22
  char *v6; // r16
  idCVar *v7; // r6
  int v8; // r23
  int *v9; // r17
  int *v10; // r18
  idCVar **v11; // r19
  idParallelJobList_Threads **v12; // r20
  unsigned int firstJobList; // r11
  idCVar *v14; // r5
  idParallelJobList_Threads *jobList; // r4
  int v16; // r25
  int v17; // r8
  int v18; // r7
  _BYTE *v19; // r9
  int k; // ctr
  _DWORD *v21; // r11
  char v22; // r11
  bool v23; // zf
  int v24; // r9
  _BYTE *v25; // r7
  int j; // ctr
  _DWORD *v27; // r11
  char v28; // r11
  bool v29; // r26
  unsigned int threadNum; // r28
  idParallelJobList_Threads *v31; // r31
  int v32; // r14
  char v33; // r26
  int v34; // r29
  __int128 v35; // r5
  int v37; // [sp+4Ch] [-334h] BYREF
  idCVar *v38; // [sp+50h] [-330h] BYREF
  int v39; // [sp+54h] [-32Ch] BYREF
  int v40; // [sp+58h] [-328h] BYREF
  char v41; // [sp+5Ch] [-324h] BYREF
  _BYTE v42[800]; // [sp+60h] [-320h] BYREF

  v1 = &v41;
  for ( i = 32; i != 0; --i )
  {
    *((_DWORD *)v1 + 1) = 0;
    *((_DWORD *)v1 + 2) = -1;
    *((_DWORD *)v1 + 3) = 0;
    *((_DWORD *)v1 + 4) = 0;
    v1 += 20;
    *(_DWORD *)v1 = -1;
  }
  v4 = 0;
  v5 = -1;
  if ( !this->isTerminating )
  {
    v6 = &v41;
    v7 = &jobs_prioritize;
    v8 = -1;
    v9 = &v40;
    v38 = &jobs_prioritize;
    v10 = &v39;
    v11 = &v38;
    v12 = (idParallelJobList_Threads **)&v37;
    while ( 1 )
    {
      if ( v4 < 32 )
      {
        firstJobList = this->firstJobList;
        if ( firstJobList < this->lastJobList )
        {
          v6 += 20;
          *(_DWORD *)v6 = -1;
          v10 += 5;
          *v10 = 0;
          v9 += 5;
          *v9 = 0;
          ++v4;
          ++v8;
          v14 = *(idCVar **)((char *)&this->jobLists[0].version + ((8 * firstJobList) & 0xF8));
          jobList = this->jobLists[firstJobList & 0x1F].jobList;
          this->firstJobList = firstJobList + 1;
          v11 += 5;
          *v11 = v14;
          v12 += 5;
          *v12 = jobList;
        }
      }
      if ( v4 == 0 )
        return 0;
      v16 = 0;
      v17 = 0;
      if ( v5 >= 0 )
      {
        v16 = v5;
        v24 = 0;
        v17 = *(_DWORD *)(*(_DWORD *)&v42[20 * v5] + 8);
        if ( v4 > 0 )
        {
          v25 = v42;
          for ( j = v4; j != 0; --j )
          {
            if ( v24 != v5 && *(_DWORD *)(*(_DWORD *)v25 + 8) >= v17 )
            {
              v27 = *(_DWORD **)(*(_DWORD *)v25 + 28);
              if ( v27 == nullptr || (v23 = *v27 > 0, v28 = 1, !v23) )
                v28 = 0;
              if ( v28 == 0 )
              {
                v17 = *(_DWORD *)(*(_DWORD *)v25 + 8);
                v16 = v24;
              }
            }
            ++v24;
            v25 += 20;
          }
        }
      }
      else
      {
        v18 = 0;
        if ( v4 <= 0 )
          goto LABEL_33;
        v19 = v42;
        for ( k = v4; k != 0; --k )
        {
          if ( *(_DWORD *)(*(_DWORD *)v19 + 8) > v17 )
          {
            v21 = *(_DWORD **)(*(_DWORD *)v19 + 28);
            if ( v21 == nullptr || (v23 = *v21 > 0, v22 = 1, !v23) )
              v22 = 0;
            if ( v22 == 0 )
            {
              v17 = *(_DWORD *)(*(_DWORD *)v19 + 8);
              v16 = v18;
            }
          }
          ++v18;
          v19 += 20;
        }
      }
      if ( v17 == 3 )
      {
        v29 = false;
        goto LABEL_34;
      }
LABEL_33:
      v29 = v7->valueInteger != 0;
LABEL_34:
      threadNum = this->threadNum;
      v31 = *(idParallelJobList_Threads **)&v42[20 * v16];
      v32 = Sys_Microseconds() >> 32;
      Sys_InterlockedIncrement(value: &v31->numThreadsExecuting.value);
      v33 = idParallelJobList_Threads::RunJobsInternal(
              this: v31,
              threadNum,
              state: (threadJobListState_t *)&v42[20 * v16],
              singleJob: v29);
      Sys_InterlockedDecrement(value: &v31->numThreadsExecuting.value);
      v34 = 8 * (threadNum + 50);
      *(_QWORD *)((char *)&v35 + 4) = Sys_Microseconds();
      LODWORD(v35) = DWORD1(v35) + *(jobListId_t *)((char *)&v31->listId + v34) - v32;
      *(_QWORD *)(&v31->threaded + v34) = v35;
      if ( (v33 & 2) != 0 )
      {
        if ( v16 < v8 )
          blkmov(a1: &v42[20 * v16], a2: &v42[20 * v16 + 20], a3: 20 * (v8 - v16));
        v12 -= 5;
        --v4;
        v11 -= 5;
        v10 -= 5;
        v9 -= 5;
        v6 -= 20;
        --v8;
LABEL_38:
        v5 = -1;
        goto LABEL_39;
      }
      if ( (v33 & 4) == 0 )
        goto LABEL_38;
      if ( v16 == v5 && (v33 & 1) == 0 )
        Sys_Yield();
      v5 = v16;
LABEL_39:
      if ( this->isTerminating )
        return 0;
      v7 = v38;
    }
  }
  return 0;
}


// ========================================================================
// ?Init@idParallelJobManagerLocal@@UAAXXZ
// EA  : 0x82F7BE48
// RVA : 0x00F7BE48
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idParallelJobManagerLocal::Init(idParallelJobManagerLocal *this, int a2, __int64 a3)
{
  __int64 v3; // r10
  core_t *v4; // r29
  __int64 v5; // r8
  int v7; // r31
  idJobThread *threads; // r30
  va *v9; // r3
  int v10; // [sp+8h] [-1088h]
  int v11; // [sp+Ch] [-1084h]
  int v12; // [sp+10h] [-1080h]
  int v13; // [sp+14h] [-107Ch]
  int v14; // [sp+18h] [-1078h]
  int v15; // [sp+1Ch] [-1074h]
  _DWORD v16[5]; // [sp+4Ch] [-1044h] BYREF
  va v17; // [sp+60h] [-1030h] BYREF

  v3 = 0x300000002LL;
  v4 = (core_t *)v16;
  v16[1] = 2;
  v5 = 0x500000004LL;
  v16[2] = 3;
  v16[3] = 4;
  v16[4] = 5;
  v7 = 0;
  threads = this->threads;
  do
  {
    threads->threadNum = v7;
    HIDWORD(a3) = v7;
    v9 = va::va(
           this: &v17,
           fmt: "JobListProcessor_%d",
           a3,
           a4: v5,
           a5: v3,
           a6: v10,
           a7: v11,
           a8: v12,
           a9: v13,
           a10: v14,
           a11: v15);
    idSysThread::StartWorkerThread(
      this: threads,
      name_: v9->buffer,
      core: *++v4,
      priority: THREAD_NORMAL,
      stackSize: 0x20000);
    ++v7;
    ++threads;
  }
  while ( v7 < 4 );
  this->maxThreads = jobs_numThreads.valueInteger;
  Sys_CPUCount(
    numLogicalCPUCores: &this->numPhysicalCpuCores,
    numPhysicalCPUCores: &this->numLogicalCpuCores,
    numCPUPackages: &this->numCpuPackages);
}


// ========================================================================
// ?GetNumJobLists@idParallelJobManagerLocal@@UBAHXZ
// EA  : 0x82F7BEF8
// RVA : 0x00F7BEF8
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

int __fastcall idParallelJobManagerLocal::GetNumJobLists(idParallelJobManagerLocal *this)
{
  return this->jobLists.num;
}


// ========================================================================
// ?GetNumFreeJobLists@idParallelJobManagerLocal@@UBAHXZ
// EA  : 0x82F7BF00
// RVA : 0x00F7BF00
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

int __fastcall idParallelJobManagerLocal::GetNumFreeJobLists(idParallelJobManagerLocal *this)
{
  return 32 - this->jobLists.num;
}


// ========================================================================
// ?GetJobList@idParallelJobManagerLocal@@UAAPAVidParallelJobList@@H@Z
// EA  : 0x82F7BF10
// RVA : 0x00F7BF10
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

idParallelJobList *__fastcall idParallelJobManagerLocal::GetJobList(idParallelJobManagerLocal *this, int index)
{
  return this->jobLists.list[index];
}


// ========================================================================
// ?Submit@idParallelJobManagerLocal@@QAAXPAVidParallelJobList_Threads@@H@Z
// EA  : 0x82F7BF20
// RVA : 0x00F7BF20
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idParallelJobManagerLocal::Submit(
        idParallelJobManagerLocal *this,
        idParallelJobList_Threads *jobList,
        int parallelism)
{
  unsigned int valueInteger; // r10
  int maxThreads; // r30
  int value; // r11
  idJobThread *threads; // r31
  threadJobListState_t v8; // [sp+50h] [-40h] BYREF

  if ( (jobs_numThreads.flags & 0x20000) != 0 )
  {
    valueInteger = jobs_numThreads.valueInteger;
    if ( jobs_numThreads.valueInteger >= 0 )
    {
      if ( jobs_numThreads.valueInteger > 4 )
        valueInteger = 4;
    }
    else
    {
      valueInteger = 0;
    }
    this->maxThreads = valueInteger;
    jobs_numThreads.flags &= ~0x20000u;
  }
  if ( parallelism == -1 )
  {
    maxThreads = this->maxThreads;
  }
  else if ( parallelism == -2 )
  {
    maxThreads = this->numLogicalCpuCores;
  }
  else
  {
    if ( parallelism == -3 || parallelism > 4 )
    {
      maxThreads = 4;
      goto LABEL_17;
    }
    maxThreads = parallelism;
  }
  if ( maxThreads <= 0 )
  {
    value = jobList->version.value;
    v8.jobList = nullptr;
    v8.signalIndex = 0;
    v8.lastJobIndex = 0;
    v8.nextJobIndex = -1;
    v8.version = value;
    idParallelJobList_Threads::RunJobs(this: jobList, threadNum: 0, state: &v8, singleJob: false);
    return;
  }
LABEL_17:
  threads = this->threads;
  do
  {
    idJobThread::AddJobList(this: threads, jobList);
    idSysThread::SignalWork(this: threads);
    --maxThreads;
    ++threads;
  }
  while ( maxThreads != 0 );
}


// ========================================================================
// ?SubmitJobList@@YAXPAVidParallelJobList_Threads@@H@Z
// EA  : 0x82F7C088
// RVA : 0x00F7C088
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall SubmitJobList(idParallelJobList_Threads *jobList, int parallelism)
{
  idParallelJobManagerLocal::Submit(this: &parallelJobManagerLocal, jobList, parallelism);
}


// ========================================================================
// ??1idParallelJobManagerLocal@@UAA@XZ
// EA  : 0x82F7C118
// RVA : 0x00F7C118
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idParallelJobManagerLocal::~idParallelJobManagerLocal(idParallelJobManagerLocal *this)
{
  this->__vftable = (idParallelJobManagerLocal_vtbl *)&idParallelJobManagerLocal::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jobLists);
  `eh vector destructor iterator'(
    ptr: this->threads,
    size: 0x148u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idJobThread::~idJobThread);
  this->__vftable = (idParallelJobManagerLocal_vtbl *)&idParallelJobManager::`vftable';
}


// ========================================================================
// __unwind$116959
// EA  : 0x82F7C188
// RVA : 0x00F7C188
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void _unwind_116959()
{
  int v0; // r12

  idParallelJobManager::~idParallelJobManager(this: *(idParallelJobManager **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$116960
// EA  : 0x82F7C1B0
// RVA : 0x00F7C1B0
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void _unwind_116960()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 4),
    size: 0x148u,
    count: 4,
    pDtor: (void (__fastcall *)(void *))idJobThread::~idJobThread);
}


// ========================================================================
// ?AddJob@idParallelJobList_Threads@@QAAXP6AXPAX@Z0@Z
// EA  : 0x82F7C4E8
// RVA : 0x00F7C4E8
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idParallelJobList_Threads::AddJob(
        idParallelJobList_Threads *this,
        void (__fastcall *function)(void *),
        int data)
{
  idList<idParallelJobList_Threads::job_t,96> *p_jobList; // r30
  presentableObject_t *v8; // r3
  __int64 v9; // r6
  __int64 v10; // r10
  __int64 v11; // r8
  int num; // ctr
  registeredJob *v13; // r11
  int v14; // r11
  int v15; // r29
  _DWORD *v16; // r30
  const char **p_name; // r31
  __int64 v18; // r4
  int v19; // r11
  __int64 v20; // r4
  int v21; // [sp+8h] [-298h]
  int v22; // [sp+Ch] [-294h]
  int v23; // [sp+10h] [-290h]
  int v24; // [sp+14h] [-28Ch]
  _DWORD v25[148]; // [sp+50h] [-250h] BYREF

  p_jobList = &this->jobList;
  if ( this->jobList.listStatic != 0 && this->jobList.num >= this->jobList.size )
  {
    memset(Dst: v25, Val: 0, Size: 0x200u);
    LODWORD(v10) = byte_821B0000;
    HIDWORD(v10) = allocationCurrent[242];
    LODWORD(v11) = numRegisteredJobs;
    if ( this->jobList.num > 0 )
    {
      HIDWORD(v11) = 0;
      num = this->jobList.num;
      do
      {
        LODWORD(v10) = 0;
        if ( (int)v11 <= 0 )
        {
LABEL_12:
          HIDWORD(v10) = "unknown";
        }
        else
        {
          v13 = registeredJobs;
          while ( 1 )
          {
            LODWORD(v9) = v13->function;
            if ( v13->function == *(void (__fastcall **)(void *))((char *)&p_jobList->list->function + HIDWORD(v11)) )
              break;
            LODWORD(v10) = v10 + 1;
            ++v13;
            if ( (int)v10 >= (int)v11 )
              goto LABEL_12;
          }
          HIDWORD(v10) = registeredJobs[v10].name;
          LODWORD(v10) = &registeredJobs[0].name;
        }
        v14 = 0;
        if ( (int)v11 > 0 )
        {
          LODWORD(v10) = &registeredJobs[0].name;
          while ( 1 )
          {
            LODWORD(v9) = *(_DWORD *)v10;
            if ( HIDWORD(v10) == *(_DWORD *)v10 )
              break;
            ++v14;
            LODWORD(v10) = v10 + 8;
            if ( v14 >= (int)v11 )
              goto LABEL_20;
          }
          LODWORD(v10) = 4 * v14;
          HIDWORD(v10) = v25[v14] + 1;
          v25[v14] = HIDWORD(v10);
        }
LABEL_20:
        HIDWORD(v11) += 12;
        --num;
      }
      while ( num != 0 );
    }
    v15 = 0;
    if ( (int)v11 > 0 )
    {
      v16 = v25;
      p_name = &registeredJobs[0].name;
      do
      {
        if ( (int)*v16 > 0 )
        {
          HIDWORD(v18) = "Job: %s, # %d";
          LODWORD(v18) = *p_name;
          HIDWORD(v9) = *v16;
          idLib::Printf(fmt: v18, a2: v9, a3: v11, a4: v10, a5: v21, a6: v22, a7: v23, a8: v24);
          LODWORD(v11) = numRegisteredJobs;
        }
        ++v15;
        ++v16;
        p_name += 2;
      }
      while ( v15 < (int)v11 );
    }
    HIDWORD(v9) = this->jobList.num;
    v19 = 0;
    if ( (int)v11 > 0 )
    {
      LODWORD(v10) = registeredJobs;
      do
      {
        HIDWORD(v10) = *(_DWORD *)v10;
        if ( *(void (__fastcall **)(void *))v10 == function )
          goto _LN54_6;
        ++v19;
        LODWORD(v10) = v10 + 8;
      }
      while ( v19 < (int)v11 );
    }
    for ( LODWORD(v20) = "unknown"; ; LODWORD(v20) = registeredJobs[v19].name )
    {
      HIDWORD(v20) = "Can't add job '%s', too many jobs %d";
      idLib::Error(fmt: v20, a2: v9, a3: v11, a4: v10, a5: v21, a6: v22, a7: v23, a8: v24);
_LN54_6:
      LODWORD(v10) = &registeredJobs[0].name;
    }
  }
  v8 = idList<idDataQueue<63,8000>::msgItem_t,5>::Alloc(this: (idList<presentableObject_t,5> *)&this->jobList);
  v8->name = (const char *)function;
  v8->presentableIndex = data;
  *(_DWORD *)&v8->skipReplication = 0;
}


// ========================================================================
// ?Wait@idParallelJobList_Threads@@QAAXXZ
// EA  : 0x82F7C6C8
// RVA : 0x00F7C6C8
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idParallelJobList_Threads::Wait(idParallelJobList_Threads *this)
{
  char v2; // r11
  char v3; // r29
  idList<idSysInterlockedInteger,96> *p_signalJobCount; // r30
  int v5; // r27
  unsigned __int64 v6; // r11

  if ( this->jobList.num <= 0 )
  {
LABEL_15:
    memcpy(Dst: &this->threadStats, Src: &this->deferredThreadStats, Size: sizeof(this->threadStats));
    this->done = true;
    return;
  }
  if ( this->done || (v2 = 1, this->signalJobCount.num <= 0) )
    v2 = 0;
  if ( v2 != 0 )
  {
    v3 = 0;
    p_signalJobCount = &this->signalJobCount;
    v5 = Sys_Microseconds() >> 32;
    if ( this->signalJobCount.list[this->signalJobCount.num - 1].value > 0 )
    {
      v3 = 1;
      do
        Sys_Yield();
      while ( p_signalJobCount->list[this->signalJobCount.num - 1].value > 0 );
    }
    Sys_InterlockedIncrement(value: &this->version.value);
    if ( this->numThreadsExecuting.value > 0 )
    {
      v3 = 1;
      do
        Sys_Yield();
      while ( this->numThreadsExecuting.value > 0 );
    }
    idList<idAnimWebBlendEquation::existingNode_t,5>::SetNum(
      this: (idList<idAAS2DebugAreaModelData::areaTri_t,5> *)&this->jobList,
      newNum: 0);
    idList<idSysInterlockedInteger,96>::SetNum(
      this: (idList<idPresentablePtr<idPresentable>,5> *)&this->signalJobCount,
      newNum: 0);
    this->numSyncs = 0;
    this->lastSignalJob = 0;
    LODWORD(v6) = (Sys_Microseconds() >> 32) - v5;
    if ( v3 == 0 )
      LODWORD(v6) = 0;
    this->deferredThreadStats.waitTime = v6;
    goto LABEL_15;
  }
}


// ========================================================================
// ?TryWait@idParallelJobList_Threads@@QAA_NXZ
// EA  : 0x82F7C7E8
// RVA : 0x00F7C7E8
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

int __fastcall idParallelJobList_Threads::TryWait(idParallelJobList_Threads *this)
{
  if ( this->jobList.num != 0 && this->signalJobCount.list[this->signalJobCount.num - 1].value > 0 )
    return 0;
  idParallelJobList_Threads::Wait(this);
  return 1;
}


// ========================================================================
// ?AddJob@idParallelJobList@@QAAXP6AXPAX@Z0@Z
// EA  : 0x82F7C848
// RVA : 0x00F7C848
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idParallelJobList::AddJob(idParallelJobList *this, void (__fastcall *function)(void *), int data)
{
  idParallelJobList_Threads::AddJob(this: this->jobListThreads, function, data);
}


// ========================================================================
// ?Wait@idParallelJobList@@QAAXXZ
// EA  : 0x82F7C850
// RVA : 0x00F7C850
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idParallelJobList::Wait(idParallelJobList *this)
{
  idParallelJobList_Threads *jobListThreads; // r3

  jobListThreads = this->jobListThreads;
  if ( jobListThreads != nullptr )
    idParallelJobList_Threads::Wait(this: jobListThreads);
}


// ========================================================================
// ?TryWait@idParallelJobList@@QAA_NXZ
// EA  : 0x82F7C868
// RVA : 0x00F7C868
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

int __fastcall idParallelJobList::TryWait(idParallelJobList *this)
{
  idParallelJobList_Threads *jobListThreads; // r11
  int result; // r3

  jobListThreads = this->jobListThreads;
  result = 1;
  if ( jobListThreads != nullptr )
    return idParallelJobList_Threads::TryWait(this: jobListThreads) & 1;
  return result;
}


// ========================================================================
// ?WaitForAllJobLists@idParallelJobManagerLocal@@UAAXXZ
// EA  : 0x82F7C8A0
// RVA : 0x00F7C8A0
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idParallelJobManagerLocal::WaitForAllJobLists(idParallelJobManagerLocal *this)
{
  int v2; // r29
  int v3; // r31
  idParallelJobList_Threads *jobListThreads; // r3

  v2 = 0;
  if ( this->jobLists.num > 0 )
  {
    v3 = 0;
    do
    {
      jobListThreads = this->jobLists.list[v3]->jobListThreads;
      if ( jobListThreads != nullptr )
        idParallelJobList_Threads::Wait(this: jobListThreads);
      ++v2;
      ++v3;
    }
    while ( v2 < this->jobLists.num );
  }
}


// ========================================================================
// ??0idParallelJobList_Threads@@QAA@W4jobListId_t@@W4jobListPriority_t@@II@Z
// EA  : 0x82F7C978
// RVA : 0x00F7C978
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

idParallelJobList_Threads *__fastcall idParallelJobList_Threads::idParallelJobList_Threads(
        idParallelJobList_Threads *this,
        jobListId_t id,
        jobListPriority_t priority,
        unsigned int maxJobs,
        unsigned int maxSyncs)
{
  idList<idAAS2DebugAreaModelData::areaTri_t,5> *p_jobList; // r27
  signed int v9; // r4

  this->listId = id;
  this->listPriority = priority;
  this->hasSignal = false;
  this->threaded = true;
  p_jobList = (idList<idAAS2DebugAreaModelData::areaTri_t,5> *)&this->jobList;
  this->done = true;
  this->numSyncs = 0;
  this->lastSignalJob = 0;
  this->waitForGuard = nullptr;
  this->doneGuards[0].value = 0;
  this->doneGuards[1].value = 0;
  this->doneGuards[2].value = 0;
  this->doneGuards[3].value = 0;
  this->currentDoneGuard = 0;
  this->version.value = 0;
  this->jobList.list = nullptr;
  this->jobList.granularity = 0;
  this->jobList.memTag = 96;
  this->jobList.listStatic = 0;
  this->jobList.size = 0;
  this->jobList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jobList);
  this->signalJobCount.list = nullptr;
  this->signalJobCount.granularity = 0;
  this->signalJobCount.memTag = 96;
  this->signalJobCount.listStatic = 0;
  this->signalJobCount.size = 0;
  this->signalJobCount.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->signalJobCount);
  this->currentJob.value = 0;
  this->fetchLock.value = 0;
  this->numThreadsExecuting.value = 0;
  v9 = 2 * maxSyncs + maxJobs + 1;
  this->maxJobs = maxJobs;
  this->maxSyncs = maxSyncs;
  if ( v9 > this->jobList.size )
    idList<testAlloc_t,5>::Resize(this: p_jobList, newsize: v9);
  p_jobList->listStatic = 2;
  if ( (signed int)(maxSyncs + 1) > this->signalJobCount.size )
    idList<idPresentablePtr<idPresentable>,5>::Resize(
      this: (idList<idSWF::orphanedText_t,72> *)&this->signalJobCount,
      newsize: maxSyncs + 1);
  this->signalJobCount.listStatic = 2;
  memset(Dst: &this->deferredThreadStats, Val: 0, Size: sizeof(this->deferredThreadStats));
  memset(Dst: &this->threadStats, Val: 0, Size: sizeof(this->threadStats));
  return this;
}


// ========================================================================
// __unwind$117254
// EA  : 0x82F7CAD8
// RVA : 0x00F7CAD8
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void _unwind_117254()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 56));
}


// ========================================================================
// __unwind$117255
// EA  : 0x82F7CB04
// RVA : 0x00F7CB04
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void _unwind_117255()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 72));
}


// ========================================================================
// ??1idParallelJobList_Threads@@QAA@XZ
// EA  : 0x82F7CB38
// RVA : 0x00F7CB38
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idParallelJobList_Threads::~idParallelJobList_Threads(idParallelJobList_Threads *this)
{
  idParallelJobList_Threads::Wait(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->signalJobCount);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jobList);
}


// ========================================================================
// __unwind$117350
// EA  : 0x82F7CB84
// RVA : 0x00F7CB84
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void _unwind_117350()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 56));
}


// ========================================================================
// __unwind$117351
// EA  : 0x82F7CBB0
// RVA : 0x00F7CBB0
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void _unwind_117351()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// ?InsertSyncPoint@idParallelJobList_Threads@@QAAXW4jobSyncType_t@@@Z
// EA  : 0x82F7CBE0
// RVA : 0x00F7CBE0
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idParallelJobList_Threads::InsertSyncPoint(idParallelJobList_Threads *this, jobSyncType_t syncType)
{
  presentableObject_t *v3; // r3
  unsigned int v4; // r6
  presentableObject_t *v5; // r3

  if ( syncType == SYNC_SIGNAL )
  {
    if ( this->jobList.num != 0 )
    {
      idList<idSysInterlockedInteger,96>::Alloc(this: &this->signalJobCount);
      this->signalJobCount.list[this->signalJobCount.num - 1].value = this->jobList.num - this->lastSignalJob;
      this->lastSignalJob = this->jobList.num;
      v5 = idList<idDataQueue<63,8000>::msgItem_t,5>::Alloc(this: (idList<presentableObject_t,5> *)&this->jobList);
      v5->name = (const char *)idPhysics_StaticMulti::UpdateTime;
      v5->presentableIndex = (int)&idParallelJobList_Threads::JOB_SIGNAL;
      this->hasSignal = true;
    }
  }
  else if ( syncType == SYNC_SYNCHRONIZE && this->hasSignal )
  {
    v3 = idList<idDataQueue<63,8000>::msgItem_t,5>::Alloc(this: (idList<presentableObject_t,5> *)&this->jobList);
    v3->name = (const char *)idPhysics_StaticMulti::UpdateTime;
    v3->presentableIndex = (int)&idParallelJobList_Threads::JOB_SYNCHRONIZE;
    v4 = this->numSyncs + 1;
    this->hasSignal = false;
    this->numSyncs = v4;
  }
}


// ========================================================================
// ?Submit@idParallelJobList_Threads@@QAAXPAV1@H@Z
// EA  : 0x82F7CCD0
// RVA : 0x00F7CCD0
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idParallelJobList_Threads::Submit(
        idParallelJobList_Threads *this,
        idParallelJobList_Threads *waitForJobList,
        int parallelism)
{
  unsigned __int64 v5; // r30
  unsigned int numSyncs; // r11
  unsigned int v7; // r8
  unsigned __int64 v8; // r3
  int num; // r7
  int v10; // r9
  presentableObject_t *v11; // r3
  int value; // r11
  threadJobListState_t v13; // [sp+50h] [-40h] BYREF

  HIDWORD(v5) = waitForJobList;
  LODWORD(v5) = 0;
  this->done = false;
  this->currentJob.value = 0;
  memset(Dst: &this->deferredThreadStats, Val: 0, Size: sizeof(this->deferredThreadStats));
  numSyncs = this->numSyncs;
  v7 = this->jobList.num - 2 * numSyncs;
  this->deferredThreadStats.numExecutedSyncs = numSyncs;
  this->deferredThreadStats.numExecutedJobs = v7;
  LODWORD(v8) = Sys_Microseconds() >> 32;
  num = this->jobList.num;
  this->deferredThreadStats.submitTime = v8;
  this->deferredThreadStats.startTime = v5;
  this->deferredThreadStats.endTime = v5;
  this->deferredThreadStats.waitTime = v5;
  if ( num != 0 )
  {
    if ( HIDWORD(v5) != 0 )
      this->waitForGuard = (idSysInterlockedInteger *)(4 * (*(_DWORD *)(HIDWORD(v5) + 48) + 8) + HIDWORD(v5));
    else
      this->waitForGuard = nullptr;
    v10 = this->currentDoneGuard + 1;
    this->currentDoneGuard = v10 & 3;
    this->doneGuards[v10 & 3].value = 1;
    idList<idSysInterlockedInteger,96>::Alloc(this: &this->signalJobCount);
    this->signalJobCount.list[this->signalJobCount.num - 1].value = this->jobList.num - this->lastSignalJob;
    v11 = idList<idDataQueue<63,8000>::msgItem_t,5>::Alloc(this: (idList<presentableObject_t,5> *)&this->jobList);
    v11->name = (const char *)idPhysics_StaticMulti::UpdateTime;
    v11->presentableIndex = (int)&idParallelJobList_Threads::JOB_LIST_DONE;
    if ( this->threaded )
    {
      SubmitJobList(jobList: this, parallelism);
    }
    else
    {
      value = this->version.value;
      v13.jobList = nullptr;
      v13.signalIndex = 0;
      v13.lastJobIndex = 0;
      v13.nextJobIndex = -1;
      v13.version = value;
      idParallelJobList_Threads::RunJobs(this, threadNum: 0, state: &v13, singleJob: false);
    }
  }
}


// ========================================================================
// ??0idParallelJobList@@AAA@W4jobListId_t@@W4jobListPriority_t@@IIPBVidColor@@@Z
// EA  : 0x82F7CE28
// RVA : 0x00F7CE28
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

idParallelJobList *__fastcall idParallelJobList::idParallelJobList(
        idParallelJobList *this,
        jobListId_t id,
        jobListPriority_t priority,
        unsigned int maxJobs,
        unsigned int maxSyncs,
        const idColor *color)
{
  idParallelJobList_Threads *v12; // r3
  idParallelJobList_Threads *v13; // r3

  this->jobListSPURS = nullptr;
  v12 = (idParallelJobList_Threads *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x4B8u,
                                       tag: TAG_JOBLIST,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
  if ( v12 != nullptr )
    v13 = idParallelJobList_Threads::idParallelJobList_Threads(this: v12, id, priority, maxJobs, maxSyncs);
  else
    v13 = nullptr;
  this->jobListThreads = v13;
  this->color = color;
  return this;
}


// ========================================================================
// __unwind$117462
// EA  : 0x82F7CEBC
// RVA : 0x00F7CEBC
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void _unwind_117462()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_JOBLIST);
}


// ========================================================================
// ?InsertSyncPoint@idParallelJobList@@QAAXW4jobSyncType_t@@@Z
// EA  : 0x82F7CEE8
// RVA : 0x00F7CEE8
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idParallelJobList::InsertSyncPoint(idParallelJobList *this, jobSyncType_t syncType)
{
  idParallelJobList_Threads::InsertSyncPoint(this: this->jobListThreads, syncType);
}


// ========================================================================
// ?Submit@idParallelJobList@@QAAXPAV1@H@Z
// EA  : 0x82F7CEF0
// RVA : 0x00F7CEF0
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idParallelJobList::Submit(idParallelJobList *this, idParallelJobList *waitForJobList, int parallelism)
{
  idParallelJobList_Threads *jobListThreads; // r4

  if ( waitForJobList != nullptr )
    jobListThreads = waitForJobList->jobListThreads;
  else
    jobListThreads = nullptr;
  idParallelJobList_Threads::Submit(this: this->jobListThreads, waitForJobList: jobListThreads, parallelism);
}


// ========================================================================
// ?AllocJobList@idParallelJobManagerLocal@@UAAPAVidParallelJobList@@W4jobListId_t@@W4jobListPriority_t@@IIPBVidColor@@@Z
// EA  : 0x82F7CF18
// RVA : 0x00F7CF18
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idParallelJobList *__fastcall idParallelJobManagerLocal::AllocJobList(
        idParallelJobManagerLocal *this,
        jobListId_t id,
        jobListPriority_t priority,
        unsigned int maxJobs,
        unsigned int maxSyncs,
        const idColor *color)
{
  int v6; // r3
  int v7; // r11
  int v8; // r29
  __int64 v14; // r10
  int v15; // r3
  __int64 v16; // r8
  __int64 v17; // r6
  idParallelJobList *v18; // r3
  idParallelJobList *v19; // r30
  const char *v20; // r3
  int v22; // [sp+8h] [-98h]
  int v23; // [sp+Ch] [-94h]
  int v24; // [sp+10h] [-90h]
  int v25; // [sp+14h] [-8Ch]
  idParallelJobList *v26; // [sp+50h] [-50h] BYREF

  v7 = *(_DWORD *)(v6 + 1336);
  v8 = v6;
  v26 = (idParallelJobList *)v7;
  HIDWORD(v14) = 0;
  if ( v7 > 0 )
  {
    LODWORD(v16) = *(_DWORD *)(v15 + 1332);
    LODWORD(v14) = 0;
    while ( 1 )
    {
      HIDWORD(v16) = *(_DWORD *)(v14 + v16);
      LODWORD(v17) = *(_DWORD *)(HIDWORD(v16) + 4);
      HIDWORD(v17) = *(_DWORD *)(v17 + 4);
      if ( HIDWORD(v17) == id )
        break;
      ++HIDWORD(v14);
      LODWORD(v14) = v14 + 4;
      if ( SHIDWORD(v14) >= v7 )
        goto LABEL_5;
    }
    v20 = "there already exists a parallel job list with id %d";
    idLib::Error(fmt: *(__int64 *)&id, a2: v17, a3: v16, a4: v14, a5: v22, a6: v23, a7: v24, a8: v25);
    goto _LN33_13;
  }
LABEL_5:
  v18 = (idParallelJobList *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xCu,
                               tag: TAG_JOBLIST,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  v26 = v18;
  if ( v18 == nullptr )
  {
_LN33_13:
    v19 = nullptr;
    goto LABEL_9;
  }
  v19 = idParallelJobList::idParallelJobList(this: v18, id, priority, maxJobs, maxSyncs, color);
LABEL_9:
  v26 = v19;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)(v8 + 1332),
    obj: (encounterGroupRole_t *)&v26);
  return v19;
}


// ========================================================================
// $LN23_6
// EA  : 0x82F7D004
// RVA : 0x00F7D004
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void _LN23_6()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_JOBLIST);
}


// ========================================================================
// ?FreeJobList@idParallelJobManagerLocal@@UAAXPAVidParallelJobList@@@Z
// EA  : 0x82F7D030
// RVA : 0x00F7D030
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __fastcall idParallelJobManagerLocal::FreeJobList(idParallelJobManagerLocal *this, idParallelJobList *jobList)
{
  unsigned int v4; // r30
  idJobThread *threads; // r31
  int num; // r9
  idStaticList<idParallelJobList *,32> *p_jobLists; // r28
  int v8; // r10
  int v9; // r11
  int v10; // r27
  idParallelJobList_Threads *jobListThreads; // r3
  idParallelJobList_Threads **v12; // r30
  idParallelJobList_Threads *v13; // r31
  int v14; // r11
  int v15; // r11

  if ( jobList != nullptr )
  {
    v4 = 0;
    if ( this->maxThreads != 0 )
    {
      threads = this->threads;
      do
      {
        idSysThread::WaitForThread(this: threads);
        ++v4;
        ++threads;
      }
      while ( v4 < this->maxThreads );
    }
    num = this->jobLists.num;
    p_jobLists = &this->jobLists;
    v8 = 0;
    if ( num <= 0 )
    {
LABEL_9:
      v10 = -1;
    }
    else
    {
      v9 = 0;
      while ( p_jobLists->list[v9] != jobList )
      {
        ++v8;
        ++v9;
        if ( v8 >= num )
          goto LABEL_9;
      }
      v10 = v8;
    }
    jobListThreads = p_jobLists->list[v10]->jobListThreads;
    if ( jobListThreads != nullptr )
      idParallelJobList_Threads::Wait(this: jobListThreads);
    v12 = (idParallelJobList_Threads **)p_jobLists->list[v10];
    if ( v12 != nullptr )
    {
      v13 = v12[1];
      if ( v13 != nullptr )
      {
        idParallelJobList_Threads::~idParallelJobList_Threads(this: v12[1]);
        idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
      }
      idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
    }
    if ( v10 >= 0 )
    {
      v14 = this->jobLists.num;
      if ( v10 < v14 )
      {
        v15 = v14 - 1;
        this->jobLists.num = v15;
        if ( v10 != v15 )
          p_jobLists->list[v10] = p_jobLists->list[v15];
      }
    }
  }
}


// ========================================================================
// `dynamic initializer for 'globalSpuLocalStoreMutex''
// EA  : 0x83396850
// RVA : 0x01396850
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__globalSpuLocalStoreMutex__()
{
  Sys_MutexCreate(handle: (_RTL_CRITICAL_SECTION **)&globalSpuLocalStoreMutex);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__globalSpuLocalStoreMutex__);
}


// ========================================================================
// `dynamic initializer for 'jobs_longJobMicroSec''
// EA  : 0x83396888
// RVA : 0x01396888
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__jobs_longJobMicroSec__()
{
  idCVar::idCVar(
    this: &jobs_longJobMicroSec,
    name: "jobs_longJobMicroSec",
    value: "10000",
    flags: 2,
    description: "print a warning for jobs that take more than this number of microseconds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__jobs_longJobMicroSec__);
}


// ========================================================================
// `dynamic initializer for 'jobs_recordLongJobTrace''
// EA  : 0x833968E0
// RVA : 0x013968E0
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__jobs_recordLongJobTrace__()
{
  idCVar::idCVar(
    this: &jobs_recordLongJobTrace,
    name: "jobs_recordLongJobTrace",
    value: "0",
    flags: 1,
    description: "record a PIX trace for jobs that take more than jobs_longJobMicroSec",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__jobs_recordLongJobTrace__);
}


// ========================================================================
// `dynamic initializer for 'jobs_prioritize''
// EA  : 0x83396938
// RVA : 0x01396938
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__jobs_prioritize__()
{
  idCVar::idCVar(
    this: &jobs_prioritize,
    name: "jobs_prioritize",
    value: "1",
    flags: 17,
    description: "prioritize job lists",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__jobs_prioritize__);
}


// ========================================================================
// `dynamic initializer for 'jobs_numThreads''
// EA  : 0x83396990
// RVA : 0x01396990
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__jobs_numThreads__()
{
  idCVar::idCVar(
    this: &jobs_numThreads,
    name: "jobs_numThreads",
    value: "4",
    flags: 18,
    description: "number of threads used to crunch through jobs",
    valueMin: 0.0,
    valueMax: 4.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))off_82010000,
    a9: (int)&unk_82390000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__jobs_numThreads__);
}


// ========================================================================
// `dynamic initializer for 'parallelJobManagerLocal''
// EA  : 0x833969F8
// RVA : 0x013969F8
// PDB : w:\tech5\shared\idlib\parallelism\paralleljoblist.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__parallelJobManagerLocal__()
{
  idParallelJobManagerLocal::idParallelJobManagerLocal(this: &parallelJobManagerLocal);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__parallelJobManagerLocal__);
}

