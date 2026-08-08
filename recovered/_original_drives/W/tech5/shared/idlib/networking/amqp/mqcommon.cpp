
// ========================================================================
// ??0idMQTCP@@QAA@XZ
// EA  : 0x82F40F98
// RVA : 0x00F40F98
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

idMQTCP *__fastcall idMQTCP::idMQTCP(idMQTCP *this)
{
  idTCP::idTCP(this: &this->tcp);
  return this;
}


// ========================================================================
// ??1idMQTCP@@QAA@XZ
// EA  : 0x82F40FC8
// RVA : 0x00F40FC8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

// attributes: thunk
void __fastcall idMQTCP::~idMQTCP(idSMTP *this)
{
  idTCP::~idTCP(this: &this->tcp);
}


// ========================================================================
// ?Connect@idMQTCP@@QAA_NPBDG_N1@Z
// EA  : 0x82F40FD0
// RVA : 0x00F40FD0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

BOOL __fastcall idMQTCP::Connect(idMQTCP *this, const char *host, unsigned __int16 port, bool nonBlocking, bool silent)
{
  return idTCP::Connect(this: &this->tcp, host, port, nonBlocking, silent, nagle: false);
}


// ========================================================================
// ?Close@idMQTCP@@QAAXXZ
// EA  : 0x82F40FD8
// RVA : 0x00F40FD8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

// attributes: thunk
void __fastcall idMQTCP::Close(idMQTCP *this)
{
  idTCP::Close(this: &this->tcp);
}


// ========================================================================
// ?IsOpen@idMQTCP@@QBA_NXZ
// EA  : 0x82F40FE0
// RVA : 0x00F40FE0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

// attributes: thunk
BOOL __fastcall idMQTCP::IsOpen(idMQTCP *this)
{
  return idTCP::IsOpen(this: &this->tcp);
}


// ========================================================================
// ?Read@idMQTCP@@QAAHPAXH_NH@Z
// EA  : 0x82F40FE8
// RVA : 0x00F40FE8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

int __fastcall idMQTCP::Read(idMQTCP *this, void *data, int size, bool blocking, int timeoutMS)
{
  if ( blocking )
    return idTCP::ReadBlocking(this: &this->tcp, data, size, timeoutMS);
  else
    return idTCP::Read(this: &this->tcp, data, size);
}


// ========================================================================
// ?Write@idMQTCP@@QAAHPBXH_NH@Z
// EA  : 0x82F41000
// RVA : 0x00F41000
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

int __fastcall idMQTCP::Write(idMQTCP *this, const void *data, int size, bool blocking, int timeoutMS)
{
  if ( blocking )
    return idTCP::WriteBlocking(this: &this->tcp, data, size, timeoutMS);
  else
    return idTCP::Write(this: &this->tcp, data, size);
}


// ========================================================================
// ?ReadByte@idMQTCP@@QAAHAAE_NH@Z
// EA  : 0x82F41018
// RVA : 0x00F41018
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

int __fastcall idMQTCP::ReadByte(idMQTCP *this, unsigned __int8 *data, bool blocking, int timeoutMS)
{
  if ( blocking )
    return idTCP::ReadBlocking(this: &this->tcp, data, size: 1, timeoutMS);
  else
    return idTCP::Read(this: &this->tcp, data, size: 1);
}


// ========================================================================
// ?ReadUInt16@idMQTCP@@QAAHAAG_NH@Z
// EA  : 0x82F41030
// RVA : 0x00F41030
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

int __fastcall idMQTCP::ReadUInt16(idMQTCP *this, unsigned __int16 *data, bool blocking, int timeoutMS)
{
  if ( blocking )
    return idTCP::ReadBlocking(this: &this->tcp, data, size: 2, timeoutMS);
  else
    return idTCP::Read(this: &this->tcp, data, size: 2);
}


// ========================================================================
// ?ReadUInt32@idMQTCP@@QAAHAAI_NH@Z
// EA  : 0x82F41048
// RVA : 0x00F41048
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

int __fastcall idMQTCP::ReadUInt32(idMQTCP *this, unsigned int *data, bool blocking, int timeoutMS)
{
  if ( blocking )
    return idTCP::ReadBlocking(this: &this->tcp, data, size: 4, timeoutMS);
  else
    return idTCP::Read(this: &this->tcp, data, size: 4);
}


// ========================================================================
// ?Clear@idMQBuffer@@QAAXXZ
// EA  : 0x82F41060
// RVA : 0x00F41060
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __fastcall idMQBuffer::Clear(idMQBuffer *this)
{
  this->readPos = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
}


// ========================================================================
// ??0idMQBuffer@@QAA@XZ
// EA  : 0x82F41180
// RVA : 0x00F41180
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

idAttachmentCollection *__fastcall idMQBuffer::idMQBuffer(idAttachmentCollection *this)
{
  this->attachments.list = nullptr;
  this->attachments.granularity = 0;
  this->attachments.memTag = 5;
  this->attachments.listStatic = 0;
  this->attachments.size = 0;
  this->attachments.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->parent = nullptr;
  return this;
}


// ========================================================================
// ?WriteData@idMQBuffer@@QAAXPBXH@Z
// EA  : 0x82F41380
// RVA : 0x00F41380
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __fastcall idMQBuffer::WriteData(idMQBuffer *this, const void *ptr, size_t length)
{
  int num; // r28
  int v6; // r30
  int size; // r11

  num = this->body.num;
  v6 = num + length;
  idList<unsigned char,5>::PreAllocateWithGranularity(this: &this->body, newSize: num + length);
  if ( v6 <= this->body.size
    || (unsigned __int8)idList<unsigned char,25>::Resize((idList<unsigned char,37> *)this, newsize: v6) != 0 )
  {
    size = this->body.size;
    if ( v6 < size )
      size = v6;
    this->body.num = size;
  }
  memcpy(Dst: &this->body.list[num], Src: ptr, Size: length);
}


// ========================================================================
// ?WriteUInt16@idMQBuffer@@QAAXG_N@Z
// EA  : 0x82F41470
// RVA : 0x00F41470
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __fastcall idMQBuffer::WriteUInt16(
        idMQBuffer *this,
        unsigned __int16 value,
        bool endianCorrect,
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
        unsigned __int16 a14)
{
  a14 = value;
  idMQBuffer::WriteData(this, ptr: &a14, length: 2u);
}


// ========================================================================
// ?WriteUInt32@idMQBuffer@@QAAXI_N@Z
// EA  : 0x82F414A0
// RVA : 0x00F414A0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __fastcall idMQBuffer::WriteUInt32(
        idMQBuffer *this,
        unsigned int value,
        bool endianCorrect,
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
        unsigned int a14)
{
  a14 = value;
  idMQBuffer::WriteData(this, ptr: &a14, length: 4u);
}


// ========================================================================
// ??3idMQContentHeader@@SAXPAX@Z
// EA  : 0x82F41770
// RVA : 0x00F41770
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __fastcall idMQContentHeader::operator delete(idDynamicBlock<unsigned char,60> *p)
{
  ++mqAllocator.numFrees;
  if ( p != nullptr )
  {
    --mqAllocator.numUsedBlocks;
    mqAllocator.usedBlockMemory -= abs32(p[-1].size);
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      this: (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)&mqAllocator,
      block: p - 1);
  }
}


// ========================================================================
// ??2idMQMethod@@SAPAXI@Z
// EA  : 0x82F41880
// RVA : 0x00F41880
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

idDynamicBlock<unsigned char,89> *__fastcall idMQMethod::operator new(signed int size)
{
  return idDynamicBlockAlloc<unsigned char,1024,16,89>::Alloc(this: &mqAllocator, num: size);
}


// ========================================================================
// `dynamic initializer for 'mq_user''
// EA  : 0x833962C0
// RVA : 0x013962C0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mq_user__()
{
  idCVar::idCVar(
    this: &mq_user,
    name: "mq_user",
    value: "guest",
    flags: 0,
    description: "credible user account",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mq_user__);
}


// ========================================================================
// `dynamic initializer for 'mq_pw''
// EA  : 0x83396318
// RVA : 0x01396318
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mq_pw__()
{
  idCVar::idCVar(
    this: &mq_pw,
    name: "mq_pw",
    value: "guest",
    flags: 0,
    description: "credible user password",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mq_pw__);
}


// ========================================================================
// `dynamic initializer for 'mq_host''
// EA  : 0x83396370
// RVA : 0x01396370
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mq_host__()
{
  idCVar::idCVar(
    this: &mq_host,
    name: "mq_host",
    value: "localhost",
    flags: 0,
    description: "host address of the AMQP server ... preferrably RabbitMQ",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mq_host__);
}


// ========================================================================
// `dynamic initializer for 'mq_port''
// EA  : 0x833963C8
// RVA : 0x013963C8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mq_port__()
{
  idCVar::idCVar(
    this: &mq_port,
    name: "mq_port",
    value: "5672",
    flags: 2,
    description: "port for AMQP server",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mq_port__);
}


// ========================================================================
// `dynamic initializer for 'mq_vhost''
// EA  : 0x83396420
// RVA : 0x01396420
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mq_vhost__()
{
  idCVar::idCVar(
    this: &mq_vhost,
    name: "mq_vhost",
    value: "/",
    flags: 0,
    description: "default vhost for connection",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mq_vhost__);
}


// ========================================================================
// `dynamic initializer for 'mq_maxRetries''
// EA  : 0x83396478
// RVA : 0x01396478
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mq_maxRetries__()
{
  idCVar::idCVar(
    this: &mq_maxRetries,
    name: "mq_maxRetries",
    value: "9",
    flags: 2,
    description: "Number of attempts AMQP library will make to connect to a server.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mq_maxRetries__);
}


// ========================================================================
// `dynamic initializer for 'mq_retryInterval''
// EA  : 0x833964D0
// RVA : 0x013964D0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mq_retryInterval__()
{
  idCVar::idCVar(
    this: &mq_retryInterval,
    name: "mq_retryInterval",
    value: "20000",
    flags: 2,
    description: "Base interval at which AMQP library tries to reconnect to a server.  Multiplied by mq_maxRetries.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mq_retryInterval__);
}


// ========================================================================
// `dynamic initializer for 'mq_verbose''
// EA  : 0x83396528
// RVA : 0x01396528
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mq_verbose__()
{
  idCVar::idCVar(
    this: &mq_verbose,
    name: "mq_verbose",
    value: "0",
    flags: 1,
    description: "Control AMQP library and client(s) chattiness.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mq_verbose__);
}


// ========================================================================
// `dynamic initializer for 'mq_graphiteReportRate''
// EA  : 0x83396580
// RVA : 0x01396580
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mq_graphiteReportRate__()
{
  idCVar::idCVar(
    this: &mq_graphiteReportRate,
    name: "mq_graphiteReportRate",
    value: "10",
    flags: 2,
    description: "Increment in seconds to report stats to graphite.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mq_graphiteReportRate__);
}


// ========================================================================
// `dynamic initializer for 'mq_commonReportRate''
// EA  : 0x833965D8
// RVA : 0x013965D8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mq_commonReportRate__()
{
  idCVar::idCVar(
    this: &mq_commonReportRate,
    name: "mq_commonReportRate",
    value: "10",
    flags: 2,
    description: "Increment in seconds to report stats over amqp.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mq_commonReportRate__);
}


// ========================================================================
// `dynamic initializer for 'mqAllocator''
// EA  : 0x83396630
// RVA : 0x01396630
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mqAllocator__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mqAllocator__);
}

