
// ========================================================================
// ?GenerateQueueData@@YAHHH@Z
// EA  : 0x82F7A530
// RVA : 0x00F7A530
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.cpp
// ========================================================================

int __fastcall GenerateQueueData(int x, int iterations)
{
  int i; // ctr
  int v3; // r9
  int v4; // r11
  int v5; // r11
  int v6; // r4

  if ( iterations > 0 )
  {
    for ( i = iterations; i != 0; --i )
    {
      v3 = (x >> 1) & 0x55555555;
      v4 = (((x - v3) >> 2) & 0x33333333) + ((x - v3) & 0x33333333);
      v5 = ((((v4 >> 4) + v4) & 0xF0F0F0F) >> 8) + (((v4 >> 4) + v4) & 0xF0F0F0F);
      v6 = (unsigned __int64)(int)((((16
                                    * ((4 * ((2 * (x & 0xD5555555)) & 0xF3333333 | (x >> 1) & 0x51111111)) & 0xFF0F0F0F
                                     | ((int)((2 * (x & 0xD5555555)) | v3) >> 2) & 0x33030303))
                                   & 0xFFFF00FF
                                   | ((int)((4 * ((2 * (x & 0xD5555555)) & 0xF3333333 | (x >> 1) & 0x51111111))
                                          | ((int)((2 * (x & 0xD5555555)) | v3) >> 2) & 0x33333333) >> 4)
                                   & 0xF0F000F) << 8)
                                 | ((int)((16
                                         * ((4 * ((2 * (x & 0xD5555555)) & 0xF3333333 | (x >> 1) & 0x51111111))
                                          & 0xFF0F0F0F
                                          | ((int)((2 * (x & 0xD5555555)) | v3) >> 2) & 0x33030303))
                                        | ((int)((4 * ((2 * (x & 0xD5555555)) & 0xF3333333 | (x >> 1) & 0x51111111))
                                               | ((int)((2 * (x & 0xD5555555)) | v3) >> 2) & 0x33333333) >> 4)
                                        & 0xF0F0F0F) >> 8)
                                 & 0xFF00FF) >> 16;
      x = (v6
         | (((((16
              * ((4 * ((2 * (x & 0xD5555555)) & 0xF3333333 | (x >> 1) & 0x51111111)) & 0xFF0F0F0F
               | ((int)((2 * (x & 0xD5555555)) | v3) >> 2) & 0x33030303))
             & 0xFFFF00FF
             | ((int)((4 * ((2 * (x & 0xD5555555)) & 0xF3333333 | (x >> 1) & 0x51111111))
                    | ((int)((2 * (x & 0xD5555555)) | v3) >> 2) & 0x33333333) >> 4)
             & 0xF0F000F) << 8)
           | ((int)((16
                   * ((4 * ((2 * (x & 0xD5555555)) & 0xF3333333 | (x >> 1) & 0x51111111)) & 0xFF0F0F0F
                    | ((int)((2 * (x & 0xD5555555)) | v3) >> 2) & 0x33030303))
                  | ((int)((4 * ((2 * (x & 0xD5555555)) & 0xF3333333 | (x >> 1) & 0x51111111))
                         | ((int)((2 * (x & 0xD5555555)) | v3) >> 2) & 0x33333333) >> 4)
                  & 0xF0F0F0F) >> 8)
           & 0xFF00FF) << 16))
        * (((v5 >> 16) + v5) & 0x3F);
    }
  }
  return x;
}


// ========================================================================
// ?Init@?$idQueueProducerTestThread@V?$idLocklessQueueMultiProdCons@UtestObject_t@@$0CAAA@@@@@QAAXHPAVidSysThreadSynchronizer@@PAV?$idLocklessQueueMultiProdCons@UtestObject_t@@$0CAAA@@@@Z
// EA  : 0x82F7A628
// RVA : 0x00F7A628
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.cpp
// ========================================================================

void __fastcall idQueueProducerTestThread<idLocklessQueueMultiProdCons<testObject_t,8192>>::Init(
        idQueueProducerTestThread<idLocklessQueueMultiProdCons<testObject_t,8192> > *this,
        unsigned int threadNum_,
        __int64 queue_)
{
  int v4; // r11
  __int64 v5; // r8
  int v6; // ctr
  __int64 v7; // r10
  va *v8; // r3
  int v9; // [sp+8h] [-1058h]
  int v10; // [sp+Ch] [-1054h]
  int v11; // [sp+10h] [-1050h]
  int v12; // [sp+14h] [-104Ch]
  int v13; // [sp+18h] [-1048h]
  int v14; // [sp+1Ch] [-1044h]
  va v15; // [sp+50h] [-1010h] BYREF

  this->threadNum = threadNum_;
  *(_QWORD *)&this->sync = queue_;
  this->iterations = 256;
  v4 = 0;
  v5 = threadNum_ << 13;
  v6 = 0x2000;
  LODWORD(v7) = &this->iterations;
  do
  {
    HIDWORD(v7) = v5 + v4;
    *(_DWORD *)(v7 + 4) = v5 + v4++;
    LODWORD(v7) = v7 + 8;
    *(_DWORD *)v7 = 0;
    --v6;
  }
  while ( v6 != 0 );
  HIDWORD(queue_) = threadNum_;
  v8 = va::va(
         this: &v15,
         fmt: "producer%02d",
         a3: queue_,
         a4: (unsigned int)v5,
         a5: v7,
         a6: v9,
         a7: v10,
         a8: v11,
         a9: v12,
         a10: v13,
         a11: v14);
  idSysThread::StartThread(this, name_: v8->buffer, core: CORE_ANY, priority: THREAD_NORMAL, stackSize: 0x20000);
}


// ========================================================================
// ?Run@?$idQueueProducerTestThread@V?$idLocklessQueueSingleProdCons@UtestObject_t@@$0CAAA@@@@@UAAHXZ
// EA  : 0x82F7A730
// RVA : 0x00F7A730
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.cpp
// ========================================================================

int __fastcall idQueueProducerTestThread<idLocklessQueueSingleProdCons<testObject_t,8192>>::Run(
        idQueueProducerTestThread<idLocklessQueueSingleProdCons<testObject_t,8192> > *this)
{
  int v2; // r30
  testObject_t *objects; // r29

  idSysThreadSynchronizer::Signal(this: this->sync, threadNum: this->threadNum);
  Sys_SignalWait(handle: &this->sync->signals.list[this->threadNum]->handle, timeout: -1);
  v2 = 0;
  objects = this->objects;
  do
  {
    objects->data = GenerateQueueData(x: v2, iterations: this->iterations);
    idLocklessQueueSingleProdCons<testObject_t,8192>::Add(this: this->queue, element: objects);
    ++v2;
    ++objects;
  }
  while ( v2 < 0x2000 );
  return 0;
}


// ========================================================================
// ?Run@?$idQueueConsumerTestThread@V?$idLocklessQueueSingleProdCons@UtestObject_t@@$0CAAA@@@@@UAAHXZ
// EA  : 0x82F7A7A8
// RVA : 0x00F7A7A8
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.cpp
// ========================================================================

int __fastcall idQueueConsumerTestThread<idLocklessQueueSingleProdCons<testObject_t,8192>>::Run(
        idQueueConsumerTestThread<idLocklessQueueSingleProdCons<testObject_t,8192> > *this)
{
  idLocklessQueueSingleProdCons<testObject_t,8192> *queue; // r10
  _DWORD *p_queueStart; // r11
  int *p_index; // r31
  int v5; // r27
  testObject_t *v6; // r7
  idLocklessQueueSingleProdCons<testObject_t,8192> *v7; // r10
  _DWORD *v8; // r11

  idSysThreadSynchronizer::Signal(this: this->sync, threadNum: this->threadNum);
  Sys_SignalWait(handle: &this->sync->signals.list[this->threadNum]->handle, timeout: -1);
  while ( !this->done )
  {
    queue = this->queue;
    p_queueStart = &queue->queueStart;
    if ( queue->queueStart != queue->queueEnd )
    {
      p_index = &queue->queue[*p_queueStart]->index;
      *p_queueStart = (*p_queueStart + 1) & 0x1FFF;
      __lwsync();
      while ( p_index != nullptr )
      {
        v5 = *p_index;
        p_index[1] |= GenerateQueueData(x: *p_index, iterations: this->iterations);
        v6 = &this->objects[v5];
        v6->index = v5;
        v6->data = p_index[1];
        v7 = this->queue;
        ++this->fetchCount;
        v8 = &v7->queueStart;
        if ( v7->queueStart == v7->queueEnd )
          break;
        p_index = &v7->queue[*v8]->index;
        *v8 = (*v8 + 1) & 0x1FFF;
        __lwsync();
      }
    }
  }
  return 0;
}


// ========================================================================
// ?Run@?$idQueueProducerTestThread@V?$idLocklessQueueMultiProdCons@UtestObject_t@@$0CAAA@@@@@UAAHXZ
// EA  : 0x82F7A8E0
// RVA : 0x00F7A8E0
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.cpp
// ========================================================================

int __fastcall idQueueProducerTestThread<idLocklessQueueMultiProdCons<testObject_t,8192>>::Run(
        idQueueProducerTestThread<idLocklessQueueMultiProdCons<testObject_t,8192> > *this)
{
  int v2; // r30
  testObject_t *objects; // r29

  idSysThreadSynchronizer::Signal(this: this->sync, threadNum: this->threadNum);
  Sys_SignalWait(handle: &this->sync->signals.list[this->threadNum]->handle, timeout: -1);
  v2 = 0;
  objects = this->objects;
  do
  {
    objects->data = GenerateQueueData(x: v2, iterations: this->iterations);
    idLocklessQueueMultiProdCons<testObject_t,8192>::Add(this: this->queue, element: objects);
    ++v2;
    ++objects;
  }
  while ( v2 < 0x2000 );
  return 0;
}


// ========================================================================
// ?Run@?$idQueueConsumerTestThread@V?$idLocklessQueueMultiProdCons@UtestObject_t@@$0CAAA@@@@@UAAHXZ
// EA  : 0x82F7A958
// RVA : 0x00F7A958
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.cpp
// ========================================================================

int __fastcall idQueueConsumerTestThread<idLocklessQueueMultiProdCons<testObject_t,8192>>::Run(
        idQueueConsumerTestThread<idLocklessQueueMultiProdCons<testObject_t,8192> > *this)
{
  testObject_t *i; // r31
  int index; // r29
  testObject_t *v4; // r7
  idLocklessQueueMultiProdCons<testObject_t,8192> *queue; // r3

  idSysThreadSynchronizer::Signal(this: this->sync, threadNum: this->threadNum);
  Sys_SignalWait(handle: &this->sync->signals.list[this->threadNum]->handle, timeout: -1);
  while ( !this->done )
  {
    for ( i = idLocklessQueueMultiProdCons<testObject_t,8192>::Next(this: this->queue);
          i != nullptr;
          i = idLocklessQueueMultiProdCons<testObject_t,8192>::Next(this: queue) )
    {
      index = i->index;
      i->data |= GenerateQueueData(x: i->index, iterations: this->iterations);
      v4 = &this->objects[index];
      v4->index = index;
      v4->data = i->data;
      queue = this->queue;
      ++this->fetchCount;
    }
  }
  return 0;
}


// ========================================================================
// __unwind$112271
// EA  : 0x82F7ADF0
// RVA : 0x00F7ADF0
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.cpp
// ========================================================================

void _unwind_112271()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 + 28176));
}


// ========================================================================
// __unwind$112272
// EA  : 0x82F7AE18
// RVA : 0x00F7AE18
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.cpp
// ========================================================================

void _unwind_112272()
{
  int v0; // r12

  idSaveGameThread::~idSaveGameThread(this: (idCommonLocal::UploadCrashDumps::__l2::idCDWriter *)(v0 + 130960));
}


// ========================================================================
// __unwind$112273
// EA  : 0x82F7AE48
// RVA : 0x00F7AE48
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.cpp
// ========================================================================

void _unwind_112273()
{
  int v0; // r12

  idSaveGameThread::~idSaveGameThread(this: (idCommonLocal::UploadCrashDumps::__l2::idCDWriter *)(v0 + 28208));
}


// ========================================================================
// __unwind$112458
// EA  : 0x82F7B188
// RVA : 0x00F7B188
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.cpp
// ========================================================================

void _unwind_112458()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 + 26800));
}


// ========================================================================
// __unwind$112459
// EA  : 0x82F7B1B0
// RVA : 0x00F7B1B0
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.cpp
// ========================================================================

void _unwind_112459()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(v0 + 589168),
    size: 0x10048u,
    count: 8,
    pDtor: (void (__fastcall *)(void *))idSaveGameThread::~idSaveGameThread);
}


// ========================================================================
// __unwind$112460
// EA  : 0x82F7B1F4
// RVA : 0x00F7B1F4
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.cpp
// ========================================================================

void _unwind_112460()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(v0 + 26832),
    size: 0x54u,
    count: 8,
    pDtor: (void (__fastcall *)(void *))idSaveGameThread::~idSaveGameThread);
}


// ========================================================================
// `dynamic initializer for 'Regression_LocklessQueueSingle_v''
// EA  : 0x83396800
// RVA : 0x01396800
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Regression_LocklessQueueSingle_v__()
{
  return idCommandLink::idCommandLink(
           this: &Regression_LocklessQueueSingle_v,
           cmdName: "Regression_LocklessQueueSingle",
           function: Regression_LocklessQueueSingle_f,
           description: "regression check",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Regression_LocklessQueueMulti_v''
// EA  : 0x83396828
// RVA : 0x01396828
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Regression_LocklessQueueMulti_v__()
{
  return idCommandLink::idCommandLink(
           this: &Regression_LocklessQueueMulti_v,
           cmdName: "Regression_LocklessQueueMulti",
           function: Regression_LocklessQueueMulti_f,
           description: "regression check",
           argCompletion: nullptr);
}

