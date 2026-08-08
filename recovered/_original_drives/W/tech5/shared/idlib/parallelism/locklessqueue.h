
// ========================================================================
// ?Add@?$idLocklessQueueSingleProdCons@UtestObject_t@@$0CAAA@@@QAAXPAUtestObject_t@@@Z
// EA  : 0x82F7A300
// RVA : 0x00F7A300
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.h
// ========================================================================

void __fastcall idLocklessQueueSingleProdCons<testObject_t,8192>::Add(
        idLocklessQueueSingleProdCons<testObject_t,8192> *this,
        testObject_t *element)
{
  volatile int *p_queueEnd; // r31
  volatile int *p_queueStart; // r30

  p_queueEnd = &this->queueEnd;
  p_queueStart = &this->queueStart;
  if ( (((this->queueEnd + 1) ^ this->queueStart) & 0x1FFF) == 0 )
  {
    do
      Sys_Yield();
    while ( (((*p_queueEnd + 1) ^ *p_queueStart) & 0x1FFF) == 0 );
  }
  this->queue[*p_queueEnd] = element;
  __lwsync();
  *p_queueEnd = (*p_queueEnd + 1) & 0x1FFF;
}


// ========================================================================
// ?Add@?$idLocklessQueueMultiProdCons@UtestObject_t@@$0CAAA@@@QAAXPAUtestObject_t@@@Z
// EA  : 0x82F7A388
// RVA : 0x00F7A388
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.h
// ========================================================================

void __fastcall idLocklessQueueMultiProdCons<testObject_t,8192>::Add(
        idLocklessQueueMultiProdCons<testObject_t,8192> *this,
        testObject_t *element)
{
  void **p_queueAlloced; // r28
  volatile int *p_queueFetched; // r30
  void *v6; // r31
  int v7; // r5
  volatile int *p_queueEnd; // r30
  volatile int queueEnd; // r31

  p_queueAlloced = (void **)&this->queueAlloced;
  p_queueFetched = &this->queueFetched;
  do
  {
    while ( 1 )
    {
      v6 = *p_queueAlloced;
      v7 = (int)*p_queueAlloced + 1;
      if ( ((*p_queueFetched ^ v7) & 0x1FFF) != 0 )
        break;
      Sys_Yield();
    }
  }
  while ( Sys_InterlockedCompareExchange(ptr: p_queueAlloced, comparand: *p_queueAlloced, exchange: (void *)v7) != v6 );
  p_queueEnd = &this->queueEnd;
  *(testObject_t **)((char *)this->queue + ((4 * (_DWORD)v6) & 0x7FFC)) = element;
  queueEnd = this->queueEnd;
  if ( *(testObject_t **)((char *)this->queue + ((4 * queueEnd) & 0x7FFC)) != nullptr )
  {
    do
    {
      if ( *(void **)p_queueEnd == *p_queueAlloced )
        break;
      if ( Sys_InterlockedCompareExchange(
             ptr: (void **)&this->queueEnd,
             comparand: (void *)queueEnd,
             exchange: (void *)(queueEnd + 1)) != (void *)queueEnd )
        break;
      queueEnd = *p_queueEnd;
    }
    while ( *(testObject_t **)((char *)this->queue + ((4 * *p_queueEnd) & 0x7FFC)) != nullptr );
  }
}


// ========================================================================
// ?Next@?$idLocklessQueueMultiProdCons@UtestObject_t@@$0CAAA@@@QAAPAUtestObject_t@@XZ
// EA  : 0x82F7A450
// RVA : 0x00F7A450
// PDB : w:\tech5\shared\idlib\parallelism\locklessqueue.h
// ========================================================================

testObject_t *__fastcall idLocklessQueueMultiProdCons<testObject_t,8192>::Next(
        idLocklessQueueMultiProdCons<testObject_t,8192> *this)
{
  void **p_queueStart; // r28
  volatile int *p_queueEnd; // r29
  volatile int queueStart; // r31
  int v6; // r11
  volatile int *p_queueFetched; // r31
  int v8; // r27
  volatile int queueFetched; // r29

  p_queueStart = (void **)&this->queueStart;
  p_queueEnd = &this->queueEnd;
  queueStart = this->queueStart;
  if ( queueStart == this->queueEnd )
    return nullptr;
  while ( Sys_InterlockedCompareExchange(
            ptr: p_queueStart,
            comparand: (void *)queueStart,
            exchange: (void *)(queueStart + 1)) != (void *)queueStart )
  {
    queueStart = (volatile int)*p_queueStart;
    if ( *p_queueStart == *(void **)p_queueEnd )
      return nullptr;
  }
  v6 = (4 * queueStart) & 0x7FFC;
  p_queueFetched = &this->queueFetched;
  v8 = *(int *)((char *)this->queue + v6);
  *(testObject_t **)((char *)this->queue + v6) = nullptr;
  queueFetched = this->queueFetched;
  if ( *(testObject_t **)((char *)this->queue + ((4 * queueFetched) & 0x7FFC)) == nullptr )
  {
    do
    {
      if ( *(void **)p_queueFetched == *p_queueStart )
        break;
      if ( Sys_InterlockedCompareExchange(
             ptr: (void **)&this->queueFetched,
             comparand: (void *)queueFetched,
             exchange: (void *)(queueFetched + 1)) != (void *)queueFetched )
        break;
      queueFetched = *p_queueFetched;
    }
    while ( *(testObject_t **)((char *)this->queue + ((4 * *p_queueFetched) & 0x7FFC)) == nullptr );
  }
  return (testObject_t *)v8;
}

