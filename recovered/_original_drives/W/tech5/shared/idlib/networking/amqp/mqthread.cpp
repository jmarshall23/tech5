
// ========================================================================
// ??0idMQClientThread@@QAA@XZ
// EA  : 0x82F4F2B8
// RVA : 0x00F4F2B8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqthread.cpp
// ========================================================================

idMQClientThread *__fastcall idMQClientThread::idMQClientThread(idMQClientThread *this)
{
  this->signalQuit = false;
  this->__vftable = (idMQClientThread_vtbl *)&idMQClientThread::`vftable';
  this->handle = 0;
  this->terminated = true;
  idMQConnection::idMQConnection(this: &this->connection);
  this->retryTime = 0;
  return this;
}


// ========================================================================
// ??1idMQClientThread@@UAA@XZ
// EA  : 0x82F4F318
// RVA : 0x00F4F318
// PDB : w:\tech5\shared\idlib\networking\amqp\mqthread.cpp
// ========================================================================

void __fastcall idMQClientThread::~idMQClientThread(idMQClientThread *this)
{
  this->__vftable = (idMQClientThread_vtbl *)&idMQClientThread::`vftable';
  idMQConnection::~idMQConnection(this: &this->connection);
}


// ========================================================================
// ?StopThread@idMQClientThread@@QAAX_N@Z
// EA  : 0x82F4F330
// RVA : 0x00F4F330
// PDB : w:\tech5\shared\idlib\networking\amqp\mqthread.cpp
// ========================================================================

void __fastcall idMQClientThread::StopThread(idMQClientThread *this, bool waitForStop)
{
  unsigned int handle; // r3

  this->signalQuit = true;
  if ( waitForStop )
  {
    handle = this->handle;
    if ( handle != 0 )
    {
      Sys_JoinThread(threadHandle: handle);
      this->handle = 0;
    }
  }
}


// ========================================================================
// ?Connect@idMQClientThread@@KAXPAV1@@Z
// EA  : 0x82F4F400
// RVA : 0x00F4F400
// PDB : w:\tech5\shared\idlib\networking\amqp\mqthread.cpp
// ========================================================================

void __fastcall idMQClientThread::Connect(idMQClientThread *thread)
{
  int valueInteger; // r27
  int v3; // r23
  int v4; // r29
  int v5; // r28
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  __int64 v9; // r6
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  int v15; // [sp+8h] [-138h]
  int v16; // [sp+Ch] [-134h]
  int v17; // [sp+10h] [-130h]
  int v18; // [sp+14h] [-12Ch]
  amqpEndpoint_t v19; // [sp+50h] [-F0h] BYREF

  amqpEndpoint_t::amqpEndpoint_t(this: &v19);
  idStr::operator=(this: &v19.host, text: mq_host.valueString.data);
  v19.port = mq_port.valueInteger;
  idStr::operator=(this: &v19.username, text: mq_user.valueString.data);
  idStr::operator=(this: &v19.password, text: mq_pw.valueString.data);
  idStr::operator=(this: &v19.vhost, text: mq_vhost.valueString.data);
  valueInteger = mq_maxRetries.valueInteger;
  v3 = mq_retryInterval.valueInteger;
  idMQConnection::Init(this: &thread->connection, _endpoint: &v19);
  v4 = 1;
  if ( !thread->signalQuit )
  {
    v5 = v3;
    while ( thread->connection.connectionTerminated )
    {
      if ( thread->retryTime <= (signed int)Sys_Milliseconds() || v4 <= 1 )
      {
        if ( (unsigned __int8)idMQConnection::Connect(this: &thread->connection) != 0 )
        {
          LODWORD(v6) = &unk_82390000;
          HIDWORD(v8) = v19.port;
          idLib::Printf(
            fmt: __SPAIR64__("AMQP Now connected to %s:%d.  Beginning operations.\n", (unsigned int)v19.host.data),
            a2: v8,
            a3: v7,
            a4: v6,
            a5: v15,
            a6: v16,
            a7: v17,
            a8: v18);
          thread->retryTime = 0;
          break;
        }
        thread->retryTime = Sys_Milliseconds() + v5;
        HIDWORD(v9) = v5 / 1000;
        idLib::Printf(
          fmt: __SPAIR64__("AMQP Connection attempt %d failed.  Retrying in %d seconds.\n", v4),
          a2: v9,
          a3: v11,
          a4: v10,
          a5: v15,
          a6: v16,
          a7: v17,
          a8: v18);
        if ( v4 > valueInteger )
        {
          idLib::Printf(
            fmt: __SPAIR64__("AMQP All %d connection attempts failed. Shutting down.\n", valueInteger),
            a2: v14,
            a3: v13,
            a4: v12,
            a5: v15,
            a6: v16,
            a7: v17,
            a8: v18);
          idMQConnection::Close(this: &thread->connection);
          thread->signalQuit = true;
          break;
        }
        ++v4;
        v5 += v3;
      }
      else
      {
        mgthread_sleep(ms: 1000);
      }
      if ( thread->signalQuit )
        break;
    }
  }
  amqpEndpoint_t::~amqpEndpoint_t(this: &v19);
}


// ========================================================================
// __unwind$117228
// EA  : 0x82F4F594
// RVA : 0x00F4F594
// PDB : w:\tech5\shared\idlib\networking\amqp\mqthread.cpp
// ========================================================================

void _unwind_117228()
{
  int v0; // r12

  amqpEndpoint_t::~amqpEndpoint_t(this: (amqpEndpoint_t *)(v0 - 320 + 80));
}


// ========================================================================
// ?Thread@idMQClientThread@@KAXPAX@Z
// EA  : 0x82F4F5C0
// RVA : 0x00F4F5C0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqthread.cpp
// ========================================================================

void __fastcall idMQClientThread::Thread(idMQClientThread *v)
{
  idMQClientThread::Connect(thread: v);
  if ( !v->signalQuit )
    v->PreRun(this: v);
  do
  {
    v->ThreadSlice(this: v);
    if ( v->connection.connectionTerminated )
      idMQClientThread::Connect(thread: v);
  }
  while ( !v->signalQuit );
  idMQConnection::Close(this: &v->connection);
}


// ========================================================================
// ?StartThread@idMQClientThread@@QAAXPBD@Z
// EA  : 0x82F4F648
// RVA : 0x00F4F648
// PDB : w:\tech5\shared\idlib\networking\amqp\mqthread.cpp
// ========================================================================

void __fastcall idMQClientThread::StartThread(idMQClientThread *this, const char *threadName)
{
  this->signalQuit = false;
  this->terminated = false;
  this->handle = Sys_CreateThread(
                   function: (unsigned int (__fastcall *)(void *))idMQClientThread::Thread,
                   parms: this,
                   priority: THREAD_LOWEST,
                   name: threadName,
                   core: CORE_ANY,
                   stackSize: 0x20000,
                   suspended: false);
}

