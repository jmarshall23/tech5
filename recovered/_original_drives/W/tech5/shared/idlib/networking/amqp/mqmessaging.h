
// ========================================================================
// ??0AMQPConnectionStart@@QAA@XZ
// EA  : 0x82F42208
// RVA : 0x00F42208
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

AMQPConnectionStart *__fastcall AMQPConnectionStart::AMQPConnectionStart(AMQPConnectionStart *this)
{
  this->__vftable = (AMQPConnectionStart_vtbl *)&AMQPConnectionStart::`vftable';
  idDict::idDict(this: &this->serverProperties);
  this->mechanisms.list = nullptr;
  this->mechanisms.granularity = 0;
  this->mechanisms.memTag = 5;
  this->mechanisms.listStatic = 0;
  this->mechanisms.size = 0;
  this->mechanisms.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->mechanisms);
  this->locales.list = nullptr;
  this->locales.granularity = 0;
  this->locales.memTag = 5;
  this->locales.listStatic = 0;
  this->locales.size = 0;
  this->locales.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->locales);
  return this;
}


// ========================================================================
// __unwind$118541
// EA  : 0x82F42288
// RVA : 0x00F42288
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_118541()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$118542
// EA  : 0x82F422B0
// RVA : 0x00F422B0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_118542()
{
  int v0; // r12

  idDict::~idDict(this: (idDict *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$118543
// EA  : 0x82F422DC
// RVA : 0x00F422DC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_118543()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 56));
}


// ========================================================================
// ??1AMQPConnectionStart@@UAA@XZ
// EA  : 0x82F42310
// RVA : 0x00F42310
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPConnectionStart::~AMQPConnectionStart(AMQPConnectionStart *this)
{
  this->__vftable = (AMQPConnectionStart_vtbl *)&AMQPConnectionStart::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->locales);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->mechanisms);
  idDict::~idDict(this: &this->serverProperties);
  this->__vftable = (AMQPConnectionStart_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$118590
// EA  : 0x82F42378
// RVA : 0x00F42378
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_118590()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$118591
// EA  : 0x82F423A0
// RVA : 0x00F423A0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_118591()
{
  int v0; // r12

  idDict::~idDict(this: (idDict *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$118592
// EA  : 0x82F423CC
// RVA : 0x00F423CC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_118592()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 56));
}


// ========================================================================
// ?GetMethodId@AMQPConnectionCloseOk@@UBA?BHXZ
// EA  : 0x82F48490
// RVA : 0x00F48490
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPConnectionCloseOk::GetMethodId(AMQPConnectionCloseOk *this)
{
  return 61;
}


// ========================================================================
// ?GetMethodId@AMQPQueueUnbindOk@@UBA?BHXZ
// EA  : 0x82F484E0
// RVA : 0x00F484E0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPQueueUnbindOk::GetMethodId(AMQPQueueUnbindOk *this)
{
  return 51;
}


// ========================================================================
// ??1AMQPQueueDeleteOk@@UAA@XZ
// EA  : 0x82F484E8
// RVA : 0x00F484E8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPQueueDeleteOk::~AMQPQueueDeleteOk(AMQPConnectionTune *this)
{
  this->__vftable = (AMQPConnectionTune_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// ?GetMethodId@AMQPBasicReject@@UBA?BHXZ
// EA  : 0x82F484F8
// RVA : 0x00F484F8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPBasicReject::GetMethodId(AMQPBasicReject *this)
{
  return 90;
}


// ========================================================================
// ?GetStackPriority@idAnimator_RollBones@@UBA?AW4priority_t@idAnimator_Base@@XZ
// EA  : 0x82F48500
// RVA : 0x00F48500
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall idAnimator_RollBones::GetStackPriority(idDeclInfoTemplate<idDeclRenderParm> *this)
{
  return 100;
}


// ========================================================================
// ?GetMethodId@AMQPBasicRecover@@UBA?BHXZ
// EA  : 0x82F48508
// RVA : 0x00F48508
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPBasicRecover::GetMethodId(AMQPBasicRecover *this)
{
  return 110;
}


// ========================================================================
// ?GetMethodId@AMQPBasicRecoverOk@@UBA?BHXZ
// EA  : 0x82F48510
// RVA : 0x00F48510
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPBasicRecoverOk::GetMethodId(AMQPBasicRecoverOk *this)
{
  return 111;
}


// ========================================================================
// ??1AMQPConnectionOpen@@UAA@XZ
// EA  : 0x82F48828
// RVA : 0x00F48828
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPConnectionOpen::~AMQPConnectionOpen(AMQPConnectionOpen *this)
{
  this->__vftable = (AMQPConnectionOpen_vtbl *)&AMQPConnectionOpen::`vftable';
  idStr::FreeData(this: &this->capabilities);
  idStr::FreeData(this: &this->virtualHost);
  this->__vftable = (AMQPConnectionOpen_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$120351
// EA  : 0x82F48888
// RVA : 0x00F48888
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_120351()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$120352
// EA  : 0x82F488B0
// RVA : 0x00F488B0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_120352()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ?GetMethodId@AMQPQueueDeleteOk@@UBA?BHXZ
// EA  : 0x82F48930
// RVA : 0x00F48930
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPQueueDeleteOk::GetMethodId(idClientGameMsg_HitScanHit *this)
{
  return 41;
}


// ========================================================================
// ??1AMQPConnectionOpenOk@@UAA@XZ
// EA  : 0x82F48940
// RVA : 0x00F48940
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPConnectionOpenOk::~AMQPConnectionOpenOk(AMQPConnectionOpenOk *this)
{
  this->__vftable = (AMQPConnectionOpenOk_vtbl *)&AMQPConnectionOpenOk::`vftable';
  idStr::FreeData(this: &this->knownHosts);
  this->__vftable = (AMQPConnectionOpenOk_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$120428
// EA  : 0x82F48998
// RVA : 0x00F48998
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_120428()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??1AMQPConnectionRedirect@@UAA@XZ
// EA  : 0x82F48A18
// RVA : 0x00F48A18
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPConnectionRedirect::~AMQPConnectionRedirect(AMQPConnectionRedirect *this)
{
  this->__vftable = (AMQPConnectionRedirect_vtbl *)&AMQPConnectionRedirect::`vftable';
  idStr::FreeData(this: &this->knownHosts);
  idStr::FreeData(this: &this->host);
  this->__vftable = (AMQPConnectionRedirect_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$120520
// EA  : 0x82F48A78
// RVA : 0x00F48A78
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_120520()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$120521
// EA  : 0x82F48AA0
// RVA : 0x00F48AA0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_120521()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??1AMQPConnectionClose@@UAA@XZ
// EA  : 0x82F48B28
// RVA : 0x00F48B28
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPConnectionClose::~AMQPConnectionClose(AMQPConnectionClose *this)
{
  this->__vftable = (AMQPConnectionClose_vtbl *)&AMQPConnectionClose::`vftable';
  idStr::FreeData(this: &this->replyText);
  this->__vftable = (AMQPConnectionClose_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$120597
// EA  : 0x82F48B80
// RVA : 0x00F48B80
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_120597()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??1AMQPChannelOpen@@UAA@XZ
// EA  : 0x82F48C00
// RVA : 0x00F48C00
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPChannelOpen::~AMQPChannelOpen(AMQPChannelOpen *this)
{
  this->__vftable = (AMQPChannelOpen_vtbl *)&AMQPChannelOpen::`vftable';
  idStr::FreeData(this: &this->oob);
  this->__vftable = (AMQPChannelOpen_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$120665
// EA  : 0x82F48C58
// RVA : 0x00F48C58
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_120665()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??1AMQPChannelClose@@UAA@XZ
// EA  : 0x82F48CD8
// RVA : 0x00F48CD8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPChannelClose::~AMQPChannelClose(AMQPChannelClose *this)
{
  this->__vftable = (AMQPChannelClose_vtbl *)&AMQPChannelClose::`vftable';
  idStr::FreeData(this: &this->replyText);
  this->__vftable = (AMQPChannelClose_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$120733
// EA  : 0x82F48D30
// RVA : 0x00F48D30
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_120733()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??1AMQPExchangeDelete@@UAA@XZ
// EA  : 0x82F48DB0
// RVA : 0x00F48DB0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPExchangeDelete::~AMQPExchangeDelete(AMQPExchangeDelete *this)
{
  this->__vftable = (AMQPExchangeDelete_vtbl *)&AMQPExchangeDelete::`vftable';
  idStr::FreeData(this: &this->exchange);
  this->__vftable = (AMQPExchangeDelete_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$120801
// EA  : 0x82F48E08
// RVA : 0x00F48E08
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_120801()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??1AMQPQueueDeclareOk@@UAA@XZ
// EA  : 0x82F48E88
// RVA : 0x00F48E88
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPQueueDeclareOk::~AMQPQueueDeclareOk(AMQPQueueDeclareOk *this)
{
  this->__vftable = (AMQPQueueDeclareOk_vtbl *)&AMQPQueueDeclareOk::`vftable';
  idStr::FreeData(this: &this->queue);
  this->__vftable = (AMQPQueueDeclareOk_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$120869
// EA  : 0x82F48EE0
// RVA : 0x00F48EE0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_120869()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??1AMQPQueuePurge@@UAA@XZ
// EA  : 0x82F48F60
// RVA : 0x00F48F60
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPQueuePurge::~AMQPQueuePurge(AMQPQueuePurge *this)
{
  this->__vftable = (AMQPQueuePurge_vtbl *)&AMQPQueuePurge::`vftable';
  idStr::FreeData(this: &this->queue);
  this->__vftable = (AMQPQueuePurge_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$120937
// EA  : 0x82F48FB8
// RVA : 0x00F48FB8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_120937()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??1AMQPQueueDelete@@UAA@XZ
// EA  : 0x82F49038
// RVA : 0x00F49038
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPQueueDelete::~AMQPQueueDelete(AMQPQueueDelete *this)
{
  this->__vftable = (AMQPQueueDelete_vtbl *)&AMQPQueueDelete::`vftable';
  idStr::FreeData(this: &this->queue);
  this->__vftable = (AMQPQueueDelete_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$121005
// EA  : 0x82F49090
// RVA : 0x00F49090
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121005()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??1AMQPBasicConsume@@UAA@XZ
// EA  : 0x82F49110
// RVA : 0x00F49110
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPBasicConsume::~AMQPBasicConsume(AMQPBasicConsume *this)
{
  this->__vftable = (AMQPBasicConsume_vtbl *)&AMQPBasicConsume::`vftable';
  idStr::FreeData(this: &this->consumerTag);
  idStr::FreeData(this: &this->queue);
  this->__vftable = (AMQPBasicConsume_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$121097
// EA  : 0x82F49170
// RVA : 0x00F49170
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121097()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$121098
// EA  : 0x82F49198
// RVA : 0x00F49198
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121098()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ??1AMQPBasicConsumeOk@@UAA@XZ
// EA  : 0x82F49220
// RVA : 0x00F49220
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPBasicConsumeOk::~AMQPBasicConsumeOk(AMQPBasicConsumeOk *this)
{
  this->__vftable = (AMQPBasicConsumeOk_vtbl *)&AMQPBasicConsumeOk::`vftable';
  idStr::FreeData(this: &this->consumerTag);
  this->__vftable = (AMQPBasicConsumeOk_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$121174
// EA  : 0x82F49278
// RVA : 0x00F49278
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121174()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??1AMQPBasicCancel@@UAA@XZ
// EA  : 0x82F492F8
// RVA : 0x00F492F8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPBasicCancel::~AMQPBasicCancel(AMQPBasicCancel *this)
{
  this->__vftable = (AMQPBasicCancel_vtbl *)&AMQPBasicCancel::`vftable';
  idStr::FreeData(this: &this->consumerTag);
  this->__vftable = (AMQPBasicCancel_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$121242
// EA  : 0x82F49350
// RVA : 0x00F49350
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121242()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetMethodId@AMQPConnectionTuneOk@@UBA?BHXZ
// EA  : 0x82F493C8
// RVA : 0x00F493C8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPConnectionTuneOk::GetMethodId(idCamera *this)
{
  return 31;
}


// ========================================================================
// ??1AMQPBasicCancelOk@@UAA@XZ
// EA  : 0x82F493D8
// RVA : 0x00F493D8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPBasicCancelOk::~AMQPBasicCancelOk(AMQPBasicCancelOk *this)
{
  this->__vftable = (AMQPBasicCancelOk_vtbl *)&AMQPBasicCancelOk::`vftable';
  idStr::FreeData(this: &this->consumerTag);
  this->__vftable = (AMQPBasicCancelOk_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$121310
// EA  : 0x82F49430
// RVA : 0x00F49430
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121310()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??1AMQPBasicPublish@@UAA@XZ
// EA  : 0x82F494B0
// RVA : 0x00F494B0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPBasicPublish::~AMQPBasicPublish(AMQPBasicPublish *this)
{
  this->__vftable = (AMQPBasicPublish_vtbl *)&AMQPBasicPublish::`vftable';
  idStr::FreeData(this: &this->routingKey);
  idStr::FreeData(this: &this->exchange);
  this->__vftable = (AMQPBasicPublish_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$121402
// EA  : 0x82F49510
// RVA : 0x00F49510
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121402()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$121403
// EA  : 0x82F49538
// RVA : 0x00F49538
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121403()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ??1AMQPBasicReturn@@UAA@XZ
// EA  : 0x82F495C0
// RVA : 0x00F495C0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPBasicReturn::~AMQPBasicReturn(AMQPBasicReturn *this)
{
  this->__vftable = (AMQPBasicReturn_vtbl *)&AMQPBasicReturn::`vftable';
  idStr::FreeData(this: &this->routingKey);
  idStr::FreeData(this: &this->exchange);
  idStr::FreeData(this: &this->replyText);
  this->__vftable = (AMQPBasicReturn_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$121527
// EA  : 0x82F49628
// RVA : 0x00F49628
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121527()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$121528
// EA  : 0x82F49650
// RVA : 0x00F49650
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121528()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$121529
// EA  : 0x82F4967C
// RVA : 0x00F4967C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121529()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 40));
}


// ========================================================================
// ??1AMQPBasicDeliver@@UAA@XZ
// EA  : 0x82F49700
// RVA : 0x00F49700
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPBasicDeliver::~AMQPBasicDeliver(AMQPBasicDeliver *this)
{
  this->__vftable = (AMQPBasicDeliver_vtbl *)&AMQPBasicDeliver::`vftable';
  idStr::FreeData(this: &this->routingKey);
  idStr::FreeData(this: &this->exchange);
  idStr::FreeData(this: &this->consumerTag);
  this->__vftable = (AMQPBasicDeliver_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$121661
// EA  : 0x82F49768
// RVA : 0x00F49768
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121661()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$121662
// EA  : 0x82F49790
// RVA : 0x00F49790
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121662()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$121663
// EA  : 0x82F497BC
// RVA : 0x00F497BC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121663()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 52));
}


// ========================================================================
// ?GetMethodId@AMQPBasicGet@@UBA?BHXZ
// EA  : 0x82F49838
// RVA : 0x00F49838
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPBasicGet::GetMethodId(AMQPBasicGet *this)
{
  return 70;
}


// ========================================================================
// ??1AMQPBasicGet@@UAA@XZ
// EA  : 0x82F49848
// RVA : 0x00F49848
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPBasicGet::~AMQPBasicGet(AMQPBasicGet *this)
{
  this->__vftable = (AMQPBasicGet_vtbl *)&AMQPBasicGet::`vftable';
  idStr::FreeData(this: &this->queue);
  this->__vftable = (AMQPBasicGet_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$121747
// EA  : 0x82F498A0
// RVA : 0x00F498A0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121747()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetMethodId@AMQPBasicGetOk@@UBA?BHXZ
// EA  : 0x82F49918
// RVA : 0x00F49918
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPBasicGetOk::GetMethodId(AMQPBasicGetOk *this)
{
  return 71;
}


// ========================================================================
// ??1AMQPBasicGetOk@@UAA@XZ
// EA  : 0x82F49928
// RVA : 0x00F49928
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPBasicGetOk::~AMQPBasicGetOk(AMQPBasicGetOk *this)
{
  this->__vftable = (AMQPBasicGetOk_vtbl *)&AMQPBasicGetOk::`vftable';
  idStr::FreeData(this: &this->routingKey);
  idStr::FreeData(this: &this->exchange);
  this->__vftable = (AMQPBasicGetOk_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$121839
// EA  : 0x82F49988
// RVA : 0x00F49988
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121839()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$121840
// EA  : 0x82F499B0
// RVA : 0x00F499B0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121840()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 20));
}


// ========================================================================
// ?GetClassId@AMQPBasicCancelOk@@UBA?BHXZ
// EA  : 0x82F49A30
// RVA : 0x00F49A30
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPBasicCancelOk::GetClassId(idTypedResourceList<idMorphVertices> *this)
{
  return 60;
}


// ========================================================================
// ?GetMethodId@AMQPBasicGetEmpty@@UBA?BHXZ
// EA  : 0x82F49A38
// RVA : 0x00F49A38
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPBasicGetEmpty::GetMethodId(idTypedResourceList<idAAS2DebugAreaModel> *this)
{
  return 72;
}


// ========================================================================
// ??1AMQPBasicGetEmpty@@UAA@XZ
// EA  : 0x82F49A48
// RVA : 0x00F49A48
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPBasicGetEmpty::~AMQPBasicGetEmpty(AMQPBasicGetEmpty *this)
{
  this->__vftable = (AMQPBasicGetEmpty_vtbl *)&AMQPBasicGetEmpty::`vftable';
  idStr::FreeData(this: &this->clusterId);
  this->__vftable = (AMQPBasicGetEmpty_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$121916
// EA  : 0x82F49AA0
// RVA : 0x00F49AA0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_121916()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??0AMQPConnectionSecure@@QAA@XZ
// EA  : 0x82F4B2A8
// RVA : 0x00F4B2A8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

AMQPConnectionSecure *__fastcall AMQPConnectionSecure::AMQPConnectionSecure(AMQPConnectionSecure *this)
{
  this->__vftable = (AMQPConnectionSecure_vtbl *)&AMQPConnectionSecure::`vftable';
  this->challenge.list = nullptr;
  this->challenge.granularity = 0;
  this->challenge.memTag = 5;
  this->challenge.listStatic = 0;
  this->challenge.size = 0;
  this->challenge.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->challenge);
  return this;
}


// ========================================================================
// __unwind$124521
// EA  : 0x82F4B318
// RVA : 0x00F4B318
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_124521()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??1AMQPConnectionSecure@@UAA@XZ
// EA  : 0x82F4B348
// RVA : 0x00F4B348
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPConnectionSecure::~AMQPConnectionSecure(AMQPConnectionSecure *this)
{
  this->__vftable = (AMQPConnectionSecure_vtbl *)&AMQPConnectionSecure::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->challenge);
  this->__vftable = (AMQPConnectionSecure_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$124553
// EA  : 0x82F4B3A0
// RVA : 0x00F4B3A0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_124553()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??0AMQPConnectionSecureOk@@QAA@XZ
// EA  : 0x82F4B420
// RVA : 0x00F4B420
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

AMQPConnectionSecureOk *__fastcall AMQPConnectionSecureOk::AMQPConnectionSecureOk(AMQPConnectionSecureOk *this)
{
  this->__vftable = (AMQPConnectionSecureOk_vtbl *)&AMQPConnectionSecureOk::`vftable';
  this->response.list = nullptr;
  this->response.granularity = 0;
  this->response.memTag = 5;
  this->response.listStatic = 0;
  this->response.size = 0;
  this->response.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->response);
  return this;
}


// ========================================================================
// __unwind$124583
// EA  : 0x82F4B490
// RVA : 0x00F4B490
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_124583()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetType@idPresentableArmorPiece@@UBA?AW4presentableType_t@@XZ
// EA  : 0x82F4B4B8
// RVA : 0x00F4B4B8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall idPresentableArmorPiece::GetType(idPresentableArmorPiece *this)
{
  return 21;
}


// ========================================================================
// ??1AMQPConnectionSecureOk@@UAA@XZ
// EA  : 0x82F4B4C8
// RVA : 0x00F4B4C8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPConnectionSecureOk::~AMQPConnectionSecureOk(AMQPConnectionSecureOk *this)
{
  this->__vftable = (AMQPConnectionSecureOk_vtbl *)&AMQPConnectionSecureOk::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->response);
  this->__vftable = (AMQPConnectionSecureOk_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$124615
// EA  : 0x82F4B520
// RVA : 0x00F4B520
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_124615()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// ??0AMQPConnectionStartOk@@QAA@XZ
// EA  : 0x82F4C198
// RVA : 0x00F4C198
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

AMQPConnectionStartOk *__fastcall AMQPConnectionStartOk::AMQPConnectionStartOk(AMQPConnectionStartOk *this)
{
  this->__vftable = (AMQPConnectionStartOk_vtbl *)&AMQPConnectionStartOk::`vftable';
  idDict::idDict(this: &this->clientProperties);
  this->mechanism.len = 0;
  this->mechanism.allocedAndFlag = 20;
  this->mechanism.data = this->mechanism.baseBuffer;
  this->mechanism.baseBuffer[0] = 0;
  this->response.list = nullptr;
  this->response.granularity = 0;
  this->response.memTag = 5;
  this->response.listStatic = 0;
  this->response.size = 0;
  this->response.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->response);
  this->locale.allocedAndFlag = 20;
  this->locale.len = 0;
  this->locale.data = this->locale.baseBuffer;
  this->locale.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// __unwind$126258
// EA  : 0x82F4C22C
// RVA : 0x00F4C22C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126258()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$126259
// EA  : 0x82F4C254
// RVA : 0x00F4C254
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126259()
{
  int v0; // r12

  idDict::~idDict(this: (idDict *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$126260
// EA  : 0x82F4C280
// RVA : 0x00F4C280
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126260()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 52));
}


// ========================================================================
// ?GetMethodId@AMQPBasicQosOk@@UBA?BHXZ
// EA  : 0x82F4C2B0
// RVA : 0x00F4C2B0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPBasicQosOk::GetMethodId(AMQPConnectionStartOk *this)
{
  return 11;
}


// ========================================================================
// ??1AMQPConnectionStartOk@@UAA@XZ
// EA  : 0x82F4C2C0
// RVA : 0x00F4C2C0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPConnectionStartOk::~AMQPConnectionStartOk(AMQPConnectionStartOk *this)
{
  this->__vftable = (AMQPConnectionStartOk_vtbl *)&AMQPConnectionStartOk::`vftable';
  idStr::FreeData(this: &this->locale);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->response);
  idStr::FreeData(this: &this->mechanism);
  idDict::~idDict(this: &this->clientProperties);
  this->__vftable = (AMQPConnectionStartOk_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$126349
// EA  : 0x82F4C330
// RVA : 0x00F4C330
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126349()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$126350
// EA  : 0x82F4C358
// RVA : 0x00F4C358
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126350()
{
  int v0; // r12

  idDict::~idDict(this: (idDict *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$126351
// EA  : 0x82F4C384
// RVA : 0x00F4C384
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126351()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 52));
}


// ========================================================================
// __unwind$126352
// EA  : 0x82F4C3B0
// RVA : 0x00F4C3B0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126352()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 84));
}


// ========================================================================
// ??0AMQPChannelAlert@@QAA@XZ
// EA  : 0x82F4C438
// RVA : 0x00F4C438
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

AMQPChannelAlert *__fastcall AMQPChannelAlert::AMQPChannelAlert(AMQPChannelAlert *this)
{
  this->__vftable = (AMQPChannelAlert_vtbl *)&AMQPChannelAlert::`vftable';
  this->replyText.len = 0;
  this->replyText.allocedAndFlag = 20;
  this->replyText.data = this->replyText.baseBuffer;
  this->replyText.baseBuffer[0] = 0;
  idDict::idDict(this: &this->details);
  return this;
}


// ========================================================================
// __unwind$126403
// EA  : 0x82F4C4A8
// RVA : 0x00F4C4A8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126403()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$126404
// EA  : 0x82F4C4D0
// RVA : 0x00F4C4D0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126404()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ?GetMethodId@AMQPConnectionTune@@UBA?BHXZ
// EA  : 0x82F4C500
// RVA : 0x00F4C500
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPConnectionTune::GetMethodId(idPresentableSpectatorCamera *this)
{
  return 30;
}


// ========================================================================
// ??1AMQPChannelAlert@@UAA@XZ
// EA  : 0x82F4C510
// RVA : 0x00F4C510
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPChannelAlert::~AMQPChannelAlert(AMQPChannelAlert *this)
{
  this->__vftable = (AMQPChannelAlert_vtbl *)&AMQPChannelAlert::`vftable';
  idDict::~idDict(this: &this->details);
  idStr::FreeData(this: &this->replyText);
  this->__vftable = (AMQPChannelAlert_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$126459
// EA  : 0x82F4C570
// RVA : 0x00F4C570
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126459()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$126460
// EA  : 0x82F4C598
// RVA : 0x00F4C598
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126460()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ??0AMQPExchangeDeclare@@QAA@XZ
// EA  : 0x82F4C620
// RVA : 0x00F4C620
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

AMQPExchangeDeclare *__fastcall AMQPExchangeDeclare::AMQPExchangeDeclare(AMQPExchangeDeclare *this)
{
  this->ticket = 0;
  this->__vftable = (AMQPExchangeDeclare_vtbl *)&AMQPExchangeDeclare::`vftable';
  this->exchange.allocedAndFlag = 20;
  this->exchange.data = this->exchange.baseBuffer;
  this->exchange.len = 0;
  this->exchange.baseBuffer[0] = 0;
  this->type.allocedAndFlag = 20;
  this->type.len = 0;
  this->type.data = this->type.baseBuffer;
  this->type.baseBuffer[0] = 0;
  idDict::idDict(this: &this->arguments);
  return this;
}


// ========================================================================
// __unwind$126495
// EA  : 0x82F4C6AC
// RVA : 0x00F4C6AC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126495()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$126496
// EA  : 0x82F4C6D4
// RVA : 0x00F4C6D4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126496()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$126497
// EA  : 0x82F4C700
// RVA : 0x00F4C700
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126497()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 40));
}


// ========================================================================
// ?GetMethodId@AMQPConnectionOpen@@UBA?BHXZ
// EA  : 0x82F4C730
// RVA : 0x00F4C730
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPConnectionOpen::GetMethodId(idTypedResourceList<idInGameVideoFile> *this)
{
  return 40;
}


// ========================================================================
// ??1AMQPExchangeDeclare@@UAA@XZ
// EA  : 0x82F4C740
// RVA : 0x00F4C740
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPExchangeDeclare::~AMQPExchangeDeclare(AMQPExchangeDeclare *this)
{
  this->__vftable = (AMQPExchangeDeclare_vtbl *)&AMQPExchangeDeclare::`vftable';
  idDict::~idDict(this: &this->arguments);
  idStr::FreeData(this: &this->type);
  idStr::FreeData(this: &this->exchange);
  this->__vftable = (AMQPExchangeDeclare_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$126579
// EA  : 0x82F4C7A8
// RVA : 0x00F4C7A8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126579()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$126580
// EA  : 0x82F4C7D0
// RVA : 0x00F4C7D0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126580()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$126581
// EA  : 0x82F4C7FC
// RVA : 0x00F4C7FC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126581()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 40));
}


// ========================================================================
// ??0AMQPQueueDeclare@@QAA@XZ
// EA  : 0x82F4C880
// RVA : 0x00F4C880
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

AMQPQueueDeclare *__fastcall AMQPQueueDeclare::AMQPQueueDeclare(AMQPQueueDeclare *this)
{
  this->ticket = 0;
  this->__vftable = (AMQPQueueDeclare_vtbl *)&AMQPQueueDeclare::`vftable';
  this->queue.allocedAndFlag = 20;
  this->queue.data = this->queue.baseBuffer;
  this->queue.len = 0;
  this->queue.baseBuffer[0] = 0;
  idDict::idDict(this: &this->arguments);
  return this;
}


// ========================================================================
// __unwind$126624
// EA  : 0x82F4C8F4
// RVA : 0x00F4C8F4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126624()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$126625_0
// EA  : 0x82F4C91C
// RVA : 0x00F4C91C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126625_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ?GetClassId@AMQPConnectionTuneOk@@UBA?BHXZ
// EA  : 0x82F4C948
// RVA : 0x00F4C948
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPConnectionTuneOk::GetClassId(idPresentableProjectile_Grenade *this)
{
  return 10;
}


// ========================================================================
// ??1AMQPQueueDeclare@@UAA@XZ
// EA  : 0x82F4C958
// RVA : 0x00F4C958
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPQueueDeclare::~AMQPQueueDeclare(AMQPQueueDeclare *this)
{
  this->__vftable = (AMQPQueueDeclare_vtbl *)&AMQPQueueDeclare::`vftable';
  idDict::~idDict(this: &this->arguments);
  idStr::FreeData(this: &this->queue);
  this->__vftable = (AMQPQueueDeclare_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$126680
// EA  : 0x82F4C9B8
// RVA : 0x00F4C9B8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126680()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$126681
// EA  : 0x82F4C9E0
// RVA : 0x00F4C9E0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126681()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ??0AMQPQueueBind@@QAA@XZ
// EA  : 0x82F4CA68
// RVA : 0x00F4CA68
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

AMQPQueueBind *__fastcall AMQPQueueBind::AMQPQueueBind(AMQPQueueBind *this)
{
  this->ticket = 0;
  this->__vftable = (AMQPQueueBind_vtbl *)&AMQPQueueBind::`vftable';
  this->queue.allocedAndFlag = 20;
  this->queue.data = this->queue.baseBuffer;
  this->queue.len = 0;
  this->queue.baseBuffer[0] = 0;
  this->exchange.allocedAndFlag = 20;
  this->exchange.len = 0;
  this->exchange.data = this->exchange.baseBuffer;
  this->exchange.baseBuffer[0] = 0;
  this->routingKey.allocedAndFlag = 20;
  this->routingKey.len = 0;
  this->routingKey.data = this->routingKey.baseBuffer;
  this->routingKey.baseBuffer[0] = 0;
  idDict::idDict(this: &this->arguments);
  return this;
}


// ========================================================================
// __unwind$126716
// EA  : 0x82F4CB0C
// RVA : 0x00F4CB0C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126716()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$126717
// EA  : 0x82F4CB34
// RVA : 0x00F4CB34
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126717()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$126718
// EA  : 0x82F4CB60
// RVA : 0x00F4CB60
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126718()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 40));
}


// ========================================================================
// __unwind$126719
// EA  : 0x82F4CB8C
// RVA : 0x00F4CB8C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126719()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// ?GetClassId@AMQPQueuePurge@@UBA?BHXZ
// EA  : 0x82F4CBB8
// RVA : 0x00F4CBB8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall AMQPQueuePurge::GetClassId(idClientGameMsg_ActorModifier *this)
{
  return 50;
}


// ========================================================================
// ?GetMethodId@AMQPConnectionSecure@@UBA?BHXZ
// EA  : 0x82F4CBC0
// RVA : 0x00F4CBC0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

unsigned int __fastcall AMQPConnectionSecure::GetMethodId(idViseme_Simple *this)
{
  return 20;
}


// ========================================================================
// ?StartArbitration@idLobbyBackend360@@UAA_NXZ
// EA  : 0x82F4CBC8
// RVA : 0x00F4CBC8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

int __fastcall idLobbyBackend360::StartArbitration(_exception *pexcept)
{
  return 0;
}


// ========================================================================
// ??1AMQPQueueBind@@UAA@XZ
// EA  : 0x82F4CBD8
// RVA : 0x00F4CBD8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPQueueBind::~AMQPQueueBind(AMQPQueueBind *this)
{
  this->__vftable = (AMQPQueueBind_vtbl *)&AMQPQueueBind::`vftable';
  idDict::~idDict(this: &this->arguments);
  idStr::FreeData(this: &this->routingKey);
  idStr::FreeData(this: &this->exchange);
  idStr::FreeData(this: &this->queue);
  this->__vftable = (AMQPQueueBind_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$126828
// EA  : 0x82F4CC48
// RVA : 0x00F4CC48
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126828()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$126829
// EA  : 0x82F4CC70
// RVA : 0x00F4CC70
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126829()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$126830
// EA  : 0x82F4CC9C
// RVA : 0x00F4CC9C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126830()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 40));
}


// ========================================================================
// __unwind$126831
// EA  : 0x82F4CCC8
// RVA : 0x00F4CCC8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126831()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// ??0AMQPQueueUnbind@@QAA@XZ
// EA  : 0x82F4CD50
// RVA : 0x00F4CD50
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

AMQPQueueUnbind *__fastcall AMQPQueueUnbind::AMQPQueueUnbind(AMQPQueueUnbind *this)
{
  this->ticket = 0;
  this->__vftable = (AMQPQueueUnbind_vtbl *)&AMQPQueueUnbind::`vftable';
  this->queue.allocedAndFlag = 20;
  this->queue.data = this->queue.baseBuffer;
  this->queue.len = 0;
  this->queue.baseBuffer[0] = 0;
  this->exchange.allocedAndFlag = 20;
  this->exchange.len = 0;
  this->exchange.data = this->exchange.baseBuffer;
  this->exchange.baseBuffer[0] = 0;
  this->routingKey.allocedAndFlag = 20;
  this->routingKey.len = 0;
  this->routingKey.data = this->routingKey.baseBuffer;
  this->routingKey.baseBuffer[0] = 0;
  idDict::idDict(this: &this->arguments);
  return this;
}


// ========================================================================
// __unwind$126882
// EA  : 0x82F4CDF4
// RVA : 0x00F4CDF4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126882()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$126883
// EA  : 0x82F4CE1C
// RVA : 0x00F4CE1C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126883()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$126884
// EA  : 0x82F4CE48
// RVA : 0x00F4CE48
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126884()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 40));
}


// ========================================================================
// __unwind$126885_0
// EA  : 0x82F4CE74
// RVA : 0x00F4CE74
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126885_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}


// ========================================================================
// ??1AMQPQueueUnbind@@UAA@XZ
// EA  : 0x82F4CEA8
// RVA : 0x00F4CEA8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void __fastcall AMQPQueueUnbind::~AMQPQueueUnbind(AMQPQueueUnbind *this)
{
  this->__vftable = (AMQPQueueUnbind_vtbl *)&AMQPQueueUnbind::`vftable';
  idDict::~idDict(this: &this->arguments);
  idStr::FreeData(this: &this->routingKey);
  idStr::FreeData(this: &this->exchange);
  idStr::FreeData(this: &this->queue);
  this->__vftable = (AMQPQueueUnbind_vtbl *)&idMQMethod::`vftable';
}


// ========================================================================
// __unwind$126994
// EA  : 0x82F4CF18
// RVA : 0x00F4CF18
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126994()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: *(AMQPConnectionTune **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$126995
// EA  : 0x82F4CF40
// RVA : 0x00F4CF40
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126995()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$126996
// EA  : 0x82F4CF6C
// RVA : 0x00F4CF6C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126996()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 40));
}


// ========================================================================
// __unwind$126997
// EA  : 0x82F4CF98
// RVA : 0x00F4CF98
// PDB : w:\tech5\shared\idlib\networking\amqp\mqmessaging.h
// ========================================================================

void _unwind_126997()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 72));
}

