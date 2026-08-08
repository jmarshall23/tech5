
// ========================================================================
// ??0amqpEndpoint_t@@QAA@XZ
// EA  : 0x82894998
// RVA : 0x00894998
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

amqpEndpoint_t *__fastcall amqpEndpoint_t::amqpEndpoint_t(amqpEndpoint_t *this)
{
  idStr::idStr(this: &this->host, text: "localhost");
  this->port = 5672;
  idStr::idStr(this: &this->username, text: "guest");
  idStr::idStr(this: &this->password, text: "guest");
  idStr::idStr(this: &this->vhost, text: "/");
  this->channelMax = 0;
  this->frameMax = 0;
  this->heartbeat = 0;
  this->nonBlocking = true;
  this->silent = true;
  this->minorVersion = 0;
  this->majorVersion = 8;
  return this;
}


// ========================================================================
// __unwind$263365
// EA  : 0x82894A28
// RVA : 0x00894A28
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_263365()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$263366
// EA  : 0x82894A50
// RVA : 0x00894A50
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_263366()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// __unwind$263367
// EA  : 0x82894A7C
// RVA : 0x00894A7C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_263367()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 68));
}


// ========================================================================
// ?GetValue@?$idDeferredResult@VAMQPConnectionStart@@@@QAA_NAAVAMQPConnectionStart@@@Z
// EA  : 0x82F41E68
// RVA : 0x00F41E68
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

int __fastcall idDeferredResult<AMQPConnectionStart>::GetValue(
        idDeferredResult<AMQPConnectionStart> *this,
        AMQPConnectionStart *result)
{
  if ( !Sys_SignalWait(handle: &this->signal.handle, timeout: 5000) || !this->filled )
    return 0;
  AMQPConnectionStart::operator=(this: result, __that: &this->value);
  this->filled = false;
  return 1;
}


// ========================================================================
// ??1idMQContentHeader@@UAA@XZ
// EA  : 0x82F43D20
// RVA : 0x00F43D20
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void __fastcall idMQContentHeader::~idMQContentHeader(idMQContentHeader *this)
{
  this->__vftable = (idMQContentHeader_vtbl *)&idMQContentHeader::`vftable';
}


// ========================================================================
// ??0?$idDeferredResult@VAMQPConnectionTune@@@@QAA@XZ
// EA  : 0x82F49B20
// RVA : 0x00F49B20
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<AMQPConnectionTune> *__fastcall idDeferredResult<AMQPConnectionTune>::idDeferredResult<AMQPConnectionTune>(
        idDeferredResult<AMQPConnectionTune> *this)
{
  this->value.__vftable = (AMQPConnectionTune_vtbl *)&AMQPConnectionTune::`vftable';
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$121988
// EA  : 0x82F49B7C
// RVA : 0x00F49B7C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_121988()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??1?$idDeferredResult@VAMQPConnectionTune@@@@QAA@XZ
// EA  : 0x82F49BB0
// RVA : 0x00F49BB0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void __fastcall idDeferredResult<AMQPConnectionTune>::~idDeferredResult<AMQPConnectionTune>(
        idDeferredResult<AMQPConnectionTune> *this)
{
  Sys_SignalDestroy(handle: &this->signal.handle);
  this->value.__vftable = (AMQPConnectionTune_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$122017
// EA  : 0x82F49BFC
// RVA : 0x00F49BFC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122017()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idDeferredResult@VAMQPConnectionOpenOk@@@@QAA@XZ
// EA  : 0x82F49C30
// RVA : 0x00F49C30
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<AMQPConnectionOpenOk> *__fastcall idDeferredResult<AMQPConnectionOpenOk>::idDeferredResult<AMQPConnectionOpenOk>(
        idDeferredResult<AMQPConnectionOpenOk> *this)
{
  this->value.__vftable = (AMQPConnectionOpenOk_vtbl *)&AMQPConnectionOpenOk::`vftable';
  this->value.knownHosts.len = 0;
  this->value.knownHosts.allocedAndFlag = 20;
  this->value.knownHosts.data = this->value.knownHosts.baseBuffer;
  this->value.knownHosts.baseBuffer[0] = 0;
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$122045
// EA  : 0x82F49CA8
// RVA : 0x00F49CA8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122045()
{
  int v0; // r12

  AMQPConnectionOpenOk::~AMQPConnectionOpenOk(this: *(AMQPConnectionOpenOk **)(v0 - 112 + 132));
}


// ========================================================================
// ??1?$idDeferredResult@VAMQPConnectionOpenOk@@@@QAA@XZ
// EA  : 0x82F49CD8
// RVA : 0x00F49CD8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void __fastcall idDeferredResult<AMQPConnectionOpenOk>::~idDeferredResult<AMQPConnectionOpenOk>(
        idDeferredResult<AMQPConnectionOpenOk> *this)
{
  Sys_SignalDestroy(handle: &this->signal.handle);
  AMQPConnectionOpenOk::~AMQPConnectionOpenOk(this: &this->value);
}


// ========================================================================
// __unwind$122105
// EA  : 0x82F49D20
// RVA : 0x00F49D20
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122105()
{
  int v0; // r12

  AMQPConnectionOpenOk::~AMQPConnectionOpenOk(this: *(AMQPConnectionOpenOk **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idDeferredResult@VAMQPChannelOpenOk@@@@QAA@XZ
// EA  : 0x82F49D50
// RVA : 0x00F49D50
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<AMQPChannelOpenOk> *__fastcall idDeferredResult<AMQPChannelOpenOk>::idDeferredResult<AMQPChannelOpenOk>(
        idDeferredResult<AMQPChannelOpenOk> *this)
{
  this->value.__vftable = (AMQPChannelOpenOk_vtbl *)&AMQPChannelOpenOk::`vftable';
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$122126
// EA  : 0x82F49DAC
// RVA : 0x00F49DAC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122126()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idDeferredResult@VAMQPChannelFlow@@@@QAA@XZ
// EA  : 0x82F49DE0
// RVA : 0x00F49DE0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<AMQPChannelFlow> *__fastcall idDeferredResult<AMQPChannelFlow>::idDeferredResult<AMQPChannelFlow>(
        idDeferredResult<AMQPChannelFlow> *this)
{
  this->value.__vftable = (AMQPChannelFlow_vtbl *)&AMQPChannelFlow::`vftable';
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$122183
// EA  : 0x82F49E3C
// RVA : 0x00F49E3C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122183()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idDeferredResult@VAMQPChannelFlowOk@@@@QAA@XZ
// EA  : 0x82F49E70
// RVA : 0x00F49E70
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<AMQPChannelFlowOk> *__fastcall idDeferredResult<AMQPChannelFlowOk>::idDeferredResult<AMQPChannelFlowOk>(
        idDeferredResult<AMQPChannelFlowOk> *this)
{
  this->value.__vftable = (AMQPChannelFlowOk_vtbl *)&AMQPChannelFlowOk::`vftable';
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$122240
// EA  : 0x82F49ECC
// RVA : 0x00F49ECC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122240()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??1?$idDeferredResult@VAMQPChannelFlow@@@@QAA@XZ
// EA  : 0x82F49F00
// RVA : 0x00F49F00
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void __fastcall idDeferredResult<AMQPChannelFlow>::~idDeferredResult<AMQPChannelFlow>(
        idDeferredResult<AMQPQueueDeleteOk> *this)
{
  Sys_SignalDestroy(handle: &this->signal.handle);
  this->value.__vftable = (AMQPQueueDeleteOk_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$122635
// EA  : 0x82F49F4C
// RVA : 0x00F49F4C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122635()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idDeferredResult@VAMQPExchangeDeclareOk@@@@QAA@XZ
// EA  : 0x82F49F80
// RVA : 0x00F49F80
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<AMQPExchangeDeclareOk> *__fastcall idDeferredResult<AMQPExchangeDeclareOk>::idDeferredResult<AMQPExchangeDeclareOk>(
        idDeferredResult<AMQPExchangeDeclareOk> *this)
{
  this->value.__vftable = (AMQPExchangeDeclareOk_vtbl *)&AMQPExchangeDeclareOk::`vftable';
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$122297_0
// EA  : 0x82F49FDC
// RVA : 0x00F49FDC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122297_0()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idDeferredResult@VAMQPExchangeDeleteOk@@@@QAA@XZ
// EA  : 0x82F4A010
// RVA : 0x00F4A010
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<AMQPExchangeDeleteOk> *__fastcall idDeferredResult<AMQPExchangeDeleteOk>::idDeferredResult<AMQPExchangeDeleteOk>(
        idDeferredResult<AMQPExchangeDeleteOk> *this)
{
  this->value.__vftable = (AMQPExchangeDeleteOk_vtbl *)&AMQPExchangeDeleteOk::`vftable';
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$122354
// EA  : 0x82F4A06C
// RVA : 0x00F4A06C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122354()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??1?$idDeferredResult@VAMQPExchangeDeleteOk@@@@QAA@XZ
// EA  : 0x82F4A0A0
// RVA : 0x00F4A0A0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void __fastcall idDeferredResult<AMQPExchangeDeleteOk>::~idDeferredResult<AMQPExchangeDeleteOk>(
        idDeferredResult<AMQPBasicRecoverOk> *this)
{
  Sys_SignalDestroy(handle: &this->signal.handle);
  this->value.__vftable = (AMQPBasicRecoverOk_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$122854
// EA  : 0x82F4A0EC
// RVA : 0x00F4A0EC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122854()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idDeferredResult@VAMQPQueueDeclareOk@@@@QAA@XZ
// EA  : 0x82F4A120
// RVA : 0x00F4A120
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<AMQPQueueDeclareOk> *__fastcall idDeferredResult<AMQPQueueDeclareOk>::idDeferredResult<AMQPQueueDeclareOk>(
        idDeferredResult<AMQPQueueDeclareOk> *this)
{
  this->value.__vftable = (AMQPQueueDeclareOk_vtbl *)&AMQPQueueDeclareOk::`vftable';
  this->value.queue.len = 0;
  this->value.queue.allocedAndFlag = 20;
  this->value.queue.data = this->value.queue.baseBuffer;
  this->value.queue.baseBuffer[0] = 0;
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$122411
// EA  : 0x82F4A198
// RVA : 0x00F4A198
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122411()
{
  int v0; // r12

  AMQPQueueDeclareOk::~AMQPQueueDeclareOk(this: *(AMQPQueueDeclareOk **)(v0 - 112 + 132));
}


// ========================================================================
// ??1?$idDeferredResult@VAMQPQueueDeclareOk@@@@QAA@XZ
// EA  : 0x82F4A1C8
// RVA : 0x00F4A1C8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void __fastcall idDeferredResult<AMQPQueueDeclareOk>::~idDeferredResult<AMQPQueueDeclareOk>(
        idDeferredResult<AMQPQueueDeclareOk> *this)
{
  Sys_SignalDestroy(handle: &this->signal.handle);
  AMQPQueueDeclareOk::~AMQPQueueDeclareOk(this: &this->value);
}


// ========================================================================
// __unwind$122471
// EA  : 0x82F4A210
// RVA : 0x00F4A210
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122471()
{
  int v0; // r12

  AMQPQueueDeclareOk::~AMQPQueueDeclareOk(this: *(AMQPQueueDeclareOk **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idDeferredResult@VAMQPQueueBindOk@@@@QAA@XZ
// EA  : 0x82F4A240
// RVA : 0x00F4A240
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<AMQPQueueBindOk> *__fastcall idDeferredResult<AMQPQueueBindOk>::idDeferredResult<AMQPQueueBindOk>(
        idDeferredResult<AMQPQueueBindOk> *this)
{
  this->value.__vftable = (AMQPQueueBindOk_vtbl *)&AMQPQueueBindOk::`vftable';
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$122492
// EA  : 0x82F4A29C
// RVA : 0x00F4A29C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122492()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idDeferredResult@VAMQPQueuePurgeOk@@@@QAA@XZ
// EA  : 0x82F4A2D0
// RVA : 0x00F4A2D0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<AMQPQueuePurgeOk> *__fastcall idDeferredResult<AMQPQueuePurgeOk>::idDeferredResult<AMQPQueuePurgeOk>(
        idDeferredResult<AMQPQueuePurgeOk> *this)
{
  this->value.__vftable = (AMQPQueuePurgeOk_vtbl *)&AMQPQueuePurgeOk::`vftable';
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$122549
// EA  : 0x82F4A32C
// RVA : 0x00F4A32C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122549()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idDeferredResult@VAMQPQueueDeleteOk@@@@QAA@XZ
// EA  : 0x82F4A360
// RVA : 0x00F4A360
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<AMQPQueueDeleteOk> *__fastcall idDeferredResult<AMQPQueueDeleteOk>::idDeferredResult<AMQPQueueDeleteOk>(
        idDeferredResult<AMQPQueueDeleteOk> *this)
{
  this->value.__vftable = (AMQPQueueDeleteOk_vtbl *)&AMQPQueueDeleteOk::`vftable';
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$122606
// EA  : 0x82F4A3BC
// RVA : 0x00F4A3BC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122606()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idDeferredResult@VAMQPBasicConsumeOk@@@@QAA@XZ
// EA  : 0x82F4A3F0
// RVA : 0x00F4A3F0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<AMQPBasicConsumeOk> *__fastcall idDeferredResult<AMQPBasicConsumeOk>::idDeferredResult<AMQPBasicConsumeOk>(
        idDeferredResult<AMQPBasicConsumeOk> *this)
{
  this->value.__vftable = (AMQPBasicConsumeOk_vtbl *)&AMQPBasicConsumeOk::`vftable';
  this->value.consumerTag.len = 0;
  this->value.consumerTag.allocedAndFlag = 20;
  this->value.consumerTag.data = this->value.consumerTag.baseBuffer;
  this->value.consumerTag.baseBuffer[0] = 0;
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$122663
// EA  : 0x82F4A468
// RVA : 0x00F4A468
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122663()
{
  int v0; // r12

  AMQPBasicConsumeOk::~AMQPBasicConsumeOk(this: *(AMQPBasicConsumeOk **)(v0 - 112 + 132));
}


// ========================================================================
// ??1?$idDeferredResult@VAMQPBasicConsumeOk@@@@QAA@XZ
// EA  : 0x82F4A498
// RVA : 0x00F4A498
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void __fastcall idDeferredResult<AMQPBasicConsumeOk>::~idDeferredResult<AMQPBasicConsumeOk>(
        idDeferredResult<AMQPBasicConsumeOk> *this)
{
  Sys_SignalDestroy(handle: &this->signal.handle);
  AMQPBasicConsumeOk::~AMQPBasicConsumeOk(this: &this->value);
}


// ========================================================================
// __unwind$122723
// EA  : 0x82F4A4E0
// RVA : 0x00F4A4E0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122723()
{
  int v0; // r12

  AMQPBasicConsumeOk::~AMQPBasicConsumeOk(this: *(AMQPBasicConsumeOk **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idDeferredResult@VAMQPBasicCancelOk@@@@QAA@XZ
// EA  : 0x82F4A510
// RVA : 0x00F4A510
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<AMQPBasicCancelOk> *__fastcall idDeferredResult<AMQPBasicCancelOk>::idDeferredResult<AMQPBasicCancelOk>(
        idDeferredResult<AMQPBasicCancelOk> *this)
{
  this->value.__vftable = (AMQPBasicCancelOk_vtbl *)&AMQPBasicCancelOk::`vftable';
  this->value.consumerTag.len = 0;
  this->value.consumerTag.allocedAndFlag = 20;
  this->value.consumerTag.data = this->value.consumerTag.baseBuffer;
  this->value.consumerTag.baseBuffer[0] = 0;
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$122744
// EA  : 0x82F4A588
// RVA : 0x00F4A588
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122744()
{
  int v0; // r12

  AMQPBasicCancelOk::~AMQPBasicCancelOk(this: *(AMQPBasicCancelOk **)(v0 - 112 + 132));
}


// ========================================================================
// ??1?$idDeferredResult@VAMQPBasicCancelOk@@@@QAA@XZ
// EA  : 0x82F4A5B8
// RVA : 0x00F4A5B8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void __fastcall idDeferredResult<AMQPBasicCancelOk>::~idDeferredResult<AMQPBasicCancelOk>(
        idDeferredResult<AMQPBasicCancelOk> *this)
{
  Sys_SignalDestroy(handle: &this->signal.handle);
  AMQPBasicCancelOk::~AMQPBasicCancelOk(this: &this->value);
}


// ========================================================================
// __unwind$122804
// EA  : 0x82F4A600
// RVA : 0x00F4A600
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122804()
{
  int v0; // r12

  AMQPBasicCancelOk::~AMQPBasicCancelOk(this: *(AMQPBasicCancelOk **)(v0 - 112 + 132));
}


// ========================================================================
// ??0?$idDeferredResult@VAMQPBasicRecoverOk@@@@QAA@XZ
// EA  : 0x82F4A630
// RVA : 0x00F4A630
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<AMQPBasicRecoverOk> *__fastcall idDeferredResult<AMQPBasicRecoverOk>::idDeferredResult<AMQPBasicRecoverOk>(
        idDeferredResult<AMQPBasicRecoverOk> *this)
{
  this->value.__vftable = (AMQPBasicRecoverOk_vtbl *)&AMQPBasicRecoverOk::`vftable';
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$122825
// EA  : 0x82F4A68C
// RVA : 0x00F4A68C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_122825()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetValue@?$idDeferredResult@VAMQPChannelOpenOk@@@@QAA_NXZ
// EA  : 0x82F4A6B8
// RVA : 0x00F4A6B8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

int __fastcall idDeferredResult<AMQPChannelOpenOk>::GetValue(idDeferredResult<AMQPExchangeDeclareOk> *this)
{
  if ( !Sys_SignalWait(handle: &this->signal.handle, timeout: 5000) || !this->filled )
    return 0;
  this->filled = false;
  return 1;
}


// ========================================================================
// ?SetValue@?$idDeferredResult@VAMQPConnectionTune@@@@QAAXABVAMQPConnectionTune@@@Z
// EA  : 0x82F4AF70
// RVA : 0x00F4AF70
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeferredResult<AMQPConnectionTune>::SetValue(
        idDeferredResult<AMQPConnectionTune> *this,
        const AMQPConnectionTune *newValue,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v5; // r3
  int v6; // r31
  const char *v8; // r3
  int v9; // [sp+8h] [-68h]
  int v10; // [sp+Ch] [-64h]
  int v11; // [sp+10h] [-60h]
  int v12; // [sp+14h] [-5Ch]

  v6 = v5;
  if ( *(_BYTE *)(v5 + 16) != 0 )
  {
    v8 = "ERROR: AMQP: Deferred result already filled.\n";
    idLib::Printf(fmt: *(__int64 *)&newValue, a2: a3, a3: a4, a4: a5, a5: v9, a6: v10, a7: v11, a8: v12);
  }
  *(_WORD *)(v6 + 4) = newValue->channelMax;
  *(_DWORD *)(v6 + 8) = newValue->frameMax;
  *(_WORD *)(v6 + 12) = newValue->heartbeat;
  *(_BYTE *)(v6 + 16) = 1;
  Sys_SignalRaise(handle: (void **)(v6 + 20));
}


// ========================================================================
// ?GetValue@?$idDeferredResult@VAMQPConnectionTune@@@@QAA_NAAVAMQPConnectionTune@@@Z
// EA  : 0x82F4AFE8
// RVA : 0x00F4AFE8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

int __fastcall idDeferredResult<AMQPConnectionTune>::GetValue(
        idDeferredResult<AMQPConnectionTune> *this,
        AMQPConnectionTune *result)
{
  if ( !Sys_SignalWait(handle: &this->signal.handle, timeout: 5000) || !this->filled )
    return 0;
  result->channelMax = this->value.channelMax;
  result->frameMax = this->value.frameMax;
  result->heartbeat = this->value.heartbeat;
  this->filled = false;
  return 1;
}


// ========================================================================
// ?SetValue@?$idDeferredResult@VAMQPChannelFlow@@@@QAAXABVAMQPChannelFlow@@@Z
// EA  : 0x82F4B070
// RVA : 0x00F4B070
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeferredResult<AMQPChannelFlow>::SetValue(
        idDeferredResult<AMQPChannelFlowOk> *this,
        const AMQPChannelFlowOk *newValue,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v5; // r3
  int v6; // r31
  const char *v8; // r3
  bool active; // r11
  int v10; // [sp+8h] [-68h]
  int v11; // [sp+Ch] [-64h]
  int v12; // [sp+10h] [-60h]
  int v13; // [sp+14h] [-5Ch]

  v6 = v5;
  if ( *(_BYTE *)(v5 + 8) != 0 )
  {
    v8 = "ERROR: AMQP: Deferred result already filled.\n";
    idLib::Printf(fmt: *(__int64 *)&newValue, a2: a3, a3: a4, a4: a5, a5: v10, a6: v11, a7: v12, a8: v13);
  }
  active = newValue->active;
  *(_BYTE *)(v6 + 8) = 1;
  *(_BYTE *)(v6 + 4) = active;
  Sys_SignalRaise(handle: (void **)(v6 + 12));
}


// ========================================================================
// ?SetValue@?$idDeferredResult@VAMQPQueueBindOk@@@@QAAXABVAMQPQueueBindOk@@@Z
// EA  : 0x82F4B0D8
// RVA : 0x00F4B0D8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeferredResult<AMQPQueueBindOk>::SetValue(
        idDeferredResult<AMQPBasicRecoverOk> *this,
        const AMQPBasicRecoverOk *newValue,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v5; // r3
  int v6; // r31
  const char *v7; // r3
  int v8; // [sp+8h] [-58h]
  int v9; // [sp+Ch] [-54h]
  int v10; // [sp+10h] [-50h]
  int v11; // [sp+14h] [-4Ch]

  v6 = v5;
  if ( *(_BYTE *)(v5 + 4) != 0 )
  {
    v7 = "ERROR: AMQP: Deferred result already filled.\n";
    idLib::Printf(fmt: *(__int64 *)&newValue, a2: a3, a3: a4, a4: a5, a5: v8, a6: v9, a7: v10, a8: v11);
  }
  *(_BYTE *)(v6 + 4) = 1;
  Sys_SignalRaise(handle: (void **)(v6 + 8));
}


// ========================================================================
// ?SetValue@?$idDeferredResult@VAMQPQueuePurgeOk@@@@QAAXABVAMQPQueuePurgeOk@@@Z
// EA  : 0x82F4B128
// RVA : 0x00F4B128
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeferredResult<AMQPQueuePurgeOk>::SetValue(
        idDeferredResult<AMQPQueueDeleteOk> *this,
        const AMQPQueueDeleteOk *newValue,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v5; // r3
  int v6; // r31
  const char *v8; // r3
  unsigned int messageCount; // r11
  int v10; // [sp+8h] [-68h]
  int v11; // [sp+Ch] [-64h]
  int v12; // [sp+10h] [-60h]
  int v13; // [sp+14h] [-5Ch]

  v6 = v5;
  if ( *(_BYTE *)(v5 + 8) != 0 )
  {
    v8 = "ERROR: AMQP: Deferred result already filled.\n";
    idLib::Printf(fmt: *(__int64 *)&newValue, a2: a3, a3: a4, a4: a5, a5: v10, a6: v11, a7: v12, a8: v13);
  }
  messageCount = newValue->messageCount;
  *(_BYTE *)(v6 + 8) = 1;
  *(_DWORD *)(v6 + 4) = messageCount;
  Sys_SignalRaise(handle: (void **)(v6 + 12));
}


// ========================================================================
// ??0?$idDeferredResult@UamqpBasicGetResultOk_t@@@@QAA@XZ
// EA  : 0x82F4B9C0
// RVA : 0x00F4B9C0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<amqpBasicGetResultOk_t> *__fastcall idDeferredResult<amqpBasicGetResultOk_t>::idDeferredResult<amqpBasicGetResultOk_t>(
        idDeferredResult<amqpBasicGetResultOk_t> *this)
{
  amqpBasicGetResultOk_t::amqpBasicGetResultOk_t(this: &this->value);
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$125190
// EA  : 0x82F4BA14
// RVA : 0x00F4BA14
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_125190()
{
  int v0; // r12

  amqpBasicGetResultOk_t::~amqpBasicGetResultOk_t(this: *(amqpBasicGetResultOk_t **)(v0 - 112 + 132));
}


// ========================================================================
// ??1?$idDeferredResult@UamqpBasicGetResultOk_t@@@@QAA@XZ
// EA  : 0x82F4BA48
// RVA : 0x00F4BA48
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void __fastcall idDeferredResult<amqpBasicGetResultOk_t>::~idDeferredResult<amqpBasicGetResultOk_t>(
        idDeferredResult<amqpBasicGetResultOk_t> *this)
{
  Sys_SignalDestroy(handle: &this->signal.handle);
  amqpBasicGetResultOk_t::~amqpBasicGetResultOk_t(this: &this->value);
}


// ========================================================================
// __unwind$125211
// EA  : 0x82F4BA90
// RVA : 0x00F4BA90
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_125211()
{
  int v0; // r12

  amqpBasicGetResultOk_t::~amqpBasicGetResultOk_t(this: *(amqpBasicGetResultOk_t **)(v0 - 112 + 132));
}


// ========================================================================
// ?SetValue@?$idDeferredResult@VAMQPConnectionStart@@@@QAAXABVAMQPConnectionStart@@@Z
// EA  : 0x82F4BAB8
// RVA : 0x00F4BAB8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeferredResult<AMQPConnectionStart>::SetValue(
        idDeferredResult<AMQPConnectionStart> *this,
        const AMQPConnectionStart *newValue,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v5; // r3
  int v6; // r31
  const char *v8; // r3
  int v9; // [sp+8h] [-68h]
  int v10; // [sp+Ch] [-64h]
  int v11; // [sp+10h] [-60h]
  int v12; // [sp+14h] [-5Ch]

  v6 = v5;
  if ( *(_BYTE *)(v5 + 88) != 0 )
  {
    v8 = "ERROR: AMQP: Deferred result already filled.\n";
    idLib::Printf(fmt: *(__int64 *)&newValue, a2: a3, a3: a4, a4: a5, a5: v9, a6: v10, a7: v11, a8: v12);
  }
  *(_BYTE *)(v6 + 4) = newValue->versionMajor;
  *(_BYTE *)(v6 + 5) = newValue->versionMinor;
  idDict::operator=(this: (idDict *)(v6 + 8), other: &newValue->serverProperties);
  idList<unsigned char,34>::operator=(
    this: (idList<unsigned char,25> *)(v6 + 56),
    other: (const idList<unsigned char,25> *)&newValue->mechanisms);
  idList<unsigned char,34>::operator=(
    this: (idList<unsigned char,25> *)(v6 + 72),
    other: (const idList<unsigned char,25> *)&newValue->locales);
  *(_BYTE *)(v6 + 88) = 1;
  Sys_SignalRaise(handle: (void **)(v6 + 92));
}


// ========================================================================
// ?GetValue@?$idDeferredResult@VAMQPConnectionOpenOk@@@@QAA_NAAVAMQPConnectionOpenOk@@@Z
// EA  : 0x82F4BB48
// RVA : 0x00F4BB48
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

int __fastcall idDeferredResult<AMQPConnectionOpenOk>::GetValue(
        idDeferredResult<AMQPConnectionOpenOk> *this,
        AMQPConnectionOpenOk *result)
{
  if ( !Sys_SignalWait(handle: &this->signal.handle, timeout: 5000) || !this->filled )
    return 0;
  AMQPConnectionOpenOk::operator=(this: result, __that: &this->value);
  this->filled = false;
  return 1;
}


// ========================================================================
// ?SetValue@?$idDeferredResult@VAMQPQueueDeclareOk@@@@QAAXABVAMQPQueueDeclareOk@@@Z
// EA  : 0x82F4BBC0
// RVA : 0x00F4BBC0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeferredResult<AMQPQueueDeclareOk>::SetValue(
        idDeferredResult<AMQPQueueDeclareOk> *this,
        const AMQPQueueDeclareOk *newValue,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v5; // r3
  int v6; // r31
  const char *v8; // r3
  size_t len; // r30
  int v10; // [sp+8h] [-68h]
  int v11; // [sp+Ch] [-64h]
  int v12; // [sp+10h] [-60h]
  int v13; // [sp+14h] [-5Ch]

  v6 = v5;
  if ( *(_BYTE *)(v5 + 44) != 0 )
  {
    v8 = "ERROR: AMQP: Deferred result already filled.\n";
    idLib::Printf(fmt: *(__int64 *)&newValue, a2: a3, a3: a4, a4: a5, a5: v10, a6: v11, a7: v12, a8: v13);
  }
  len = newValue->queue.len;
  idStr::EnsureAlloced(this: (idStr *)(v6 + 4), amount: len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: *(void **)(v6 + 8), Src: newValue->queue.data, Size: len);
  *(_BYTE *)(*(_DWORD *)(v6 + 8) + len) = 0;
  *(_DWORD *)(v6 + 4) = len;
  *(_DWORD *)(v6 + 36) = newValue->messageCount;
  *(_DWORD *)(v6 + 40) = newValue->consumerCount;
  *(_BYTE *)(v6 + 44) = 1;
  Sys_SignalRaise(handle: (void **)(v6 + 48));
}


// ========================================================================
// ?SetValue@?$idDeferredResult@VAMQPBasicConsumeOk@@@@QAAXABVAMQPBasicConsumeOk@@@Z
// EA  : 0x82F4BC50
// RVA : 0x00F4BC50
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeferredResult<AMQPBasicConsumeOk>::SetValue(
        idDeferredResult<AMQPBasicCancelOk> *this,
        const AMQPBasicCancelOk *newValue,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v5; // r3
  int v6; // r31
  const char *v8; // r3
  size_t len; // r30
  int v10; // [sp+8h] [-68h]
  int v11; // [sp+Ch] [-64h]
  int v12; // [sp+10h] [-60h]
  int v13; // [sp+14h] [-5Ch]

  v6 = v5;
  if ( *(_BYTE *)(v5 + 36) != 0 )
  {
    v8 = "ERROR: AMQP: Deferred result already filled.\n";
    idLib::Printf(fmt: *(__int64 *)&newValue, a2: a3, a3: a4, a4: a5, a5: v10, a6: v11, a7: v12, a8: v13);
  }
  len = newValue->consumerTag.len;
  idStr::EnsureAlloced(this: (idStr *)(v6 + 4), amount: len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: *(void **)(v6 + 8), Src: newValue->consumerTag.data, Size: len);
  *(_BYTE *)(*(_DWORD *)(v6 + 8) + len) = 0;
  *(_DWORD *)(v6 + 4) = len;
  *(_BYTE *)(v6 + 36) = 1;
  Sys_SignalRaise(handle: (void **)(v6 + 40));
}


// ========================================================================
// ?SetValue@?$idDeferredResult@UamqpBasicGetResultOk_t@@@@QAAXABUamqpBasicGetResultOk_t@@@Z
// EA  : 0x82F4BCD0
// RVA : 0x00F4BCD0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idDeferredResult<amqpBasicGetResultOk_t>::SetValue(
        idDeferredResult<amqpBasicGetResultOk_t> *this,
        const amqpBasicGetResultOk_t *newValue,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v5; // r3
  int v6; // r31
  const char *v8; // r3
  int v9; // [sp+8h] [-68h]
  int v10; // [sp+Ch] [-64h]
  int v11; // [sp+10h] [-60h]
  int v12; // [sp+14h] [-5Ch]

  v6 = v5;
  if ( *(_BYTE *)(v5 + 104) != 0 )
  {
    v8 = "ERROR: AMQP: Deferred result already filled.\n";
    idLib::Printf(fmt: *(__int64 *)&newValue, a2: a3, a3: a4, a4: a5, a5: v9, a6: v10, a7: v11, a8: v12);
  }
  amqpBasicGetResultOk_t::operator=(this: (amqpBasicGetResultOk_t *)v6, __that: newValue);
  *(_BYTE *)(v6 + 104) = 1;
  Sys_SignalRaise(handle: (void **)(v6 + 108));
}


// ========================================================================
// ??0?$idDeferredResult@VAMQPConnectionStart@@@@QAA@XZ
// EA  : 0x82F4E608
// RVA : 0x00F4E608
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

idDeferredResult<AMQPConnectionStart> *__fastcall idDeferredResult<AMQPConnectionStart>::idDeferredResult<AMQPConnectionStart>(
        idDeferredResult<AMQPConnectionStart> *this)
{
  AMQPConnectionStart::AMQPConnectionStart(this: &this->value);
  this->filled = false;
  Sys_SignalCreate(handle: &this->signal.handle, manualReset: false);
  return this;
}


// ========================================================================
// __unwind$129036
// EA  : 0x82F4E65C
// RVA : 0x00F4E65C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_129036()
{
  int v0; // r12

  AMQPConnectionStart::~AMQPConnectionStart(this: *(AMQPConnectionStart **)(v0 - 112 + 132));
}


// ========================================================================
// ??1?$idDeferredResult@VAMQPConnectionStart@@@@QAA@XZ
// EA  : 0x82F4E690
// RVA : 0x00F4E690
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void __fastcall idDeferredResult<AMQPConnectionStart>::~idDeferredResult<AMQPConnectionStart>(
        idDeferredResult<AMQPConnectionStart> *this)
{
  Sys_SignalDestroy(handle: &this->signal.handle);
  AMQPConnectionStart::~AMQPConnectionStart(this: &this->value);
}


// ========================================================================
// __unwind$129057
// EA  : 0x82F4E6D8
// RVA : 0x00F4E6D8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommon.h
// ========================================================================

void _unwind_129057()
{
  int v0; // r12

  AMQPConnectionStart::~AMQPConnectionStart(this: *(AMQPConnectionStart **)(v0 - 112 + 132));
}

