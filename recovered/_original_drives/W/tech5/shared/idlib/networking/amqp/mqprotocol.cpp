
// ========================================================================
// ?DecodeContentHeader@idMQChannel@@SAPAVidMQContentHeader@@AAVidMQFrame@@@Z
// EA  : 0x82F48520
// RVA : 0x00F48520
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

AMQPBasicProperties *__fastcall idMQChannel::DecodeContentHeader(idMQFrame *frame)
{
  AMQPBasicProperties *v2; // r30
  AMQPBasicProperties *v3; // r3
  unsigned __int64 v4; // r3

  v2 = nullptr;
  if ( (unsigned __int16)idMQFrame::ReadUInt16(this: frame) == 60 )
  {
    v3 = (AMQPBasicProperties *)idMQMethod::operator new(size: 416);
    if ( v3 != nullptr )
      v2 = AMQPBasicProperties::AMQPBasicProperties(this: v3);
    else
      v2 = nullptr;
    if ( v2 != nullptr )
    {
      idMQFrame::ReadUInt16(this: frame);
      LODWORD(v4) = idMQFrame::ReadUInt64(this: frame);
      v2->bodyLength = v4;
      v2->Populate(this: v2, a2: frame);
    }
  }
  return v2;
}


// ========================================================================
// __unwind$119791
// EA  : 0x82F485AC
// RVA : 0x00F485AC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_119791()
{
  int v0; // r12

  idMQContentHeader::operator delete(p: *(idDynamicBlock<unsigned char,60> **)(v0 - 128 + 80));
}


// ========================================================================
// ?ConnectionTuneOk@idMQChannel@@QAAXGIG@Z
// EA  : 0x82F485E0
// RVA : 0x00F485E0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::ConnectionTuneOk(
        idMQChannel *this,
        unsigned __int16 channelMax,
        unsigned int frameMax,
        unsigned __int16 heartbeat)
{
  idMQSession *session; // r3
  _DWORD v6[4]; // [sp+50h] [-50h] BYREF
  idMQCommand v7; // [sp+60h] [-40h] BYREF

  v6[0] = &AMQPConnectionTuneOk::`vftable';
  HIWORD(v6[1]) = channelMax;
  v6[2] = frameMax;
  HIWORD(v6[3]) = heartbeat;
  idMQCommand::idMQCommand(this: &v7);
  session = this->session;
  v7.method = (idMQMethod *)v6;
  idMQSession::SendCommand(this: session, cmd: &v7);
  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)&v7);
}


// ========================================================================
// __unwind$119820
// EA  : 0x82F48650
// RVA : 0x00F48650
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_119820()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: (AMQPConnectionTune *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$119821
// EA  : 0x82F48678
// RVA : 0x00F48678
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_119821()
{
  int v0; // r12

  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)(v0 - 160 + 96));
}


// ========================================================================
// ?_ConnectionCloseOk@idMQChannel@@AAAXXZ
// EA  : 0x82F486A8
// RVA : 0x00F486A8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::_ConnectionCloseOk(idMQChannel *this)
{
  idMQSession *session; // r3
  void **v3; // [sp+50h] [-50h] BYREF
  idMQCommand v4; // [sp+60h] [-40h] BYREF

  v3 = &AMQPConnectionCloseOk::`vftable';
  idMQCommand::idMQCommand(this: &v4);
  session = this->session;
  v4.method = (idMQMethod *)&v3;
  idMQSession::SendCommand(this: session, cmd: &v4);
  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)&v4);
}


// ========================================================================
// __unwind$119862
// EA  : 0x82F4870C
// RVA : 0x00F4870C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_119862()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: (AMQPConnectionTune *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$119863
// EA  : 0x82F48734
// RVA : 0x00F48734
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_119863()
{
  int v0; // r12

  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)(v0 - 160 + 96));
}


// ========================================================================
// ?_ChannelCloseOk@idMQChannel@@AAAXXZ
// EA  : 0x82F48768
// RVA : 0x00F48768
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::_ChannelCloseOk(idMQChannel *this)
{
  idMQSession *session; // r3
  void **v3; // [sp+50h] [-50h] BYREF
  idMQCommand v4; // [sp+60h] [-40h] BYREF

  v3 = &AMQPChannelCloseOk::`vftable';
  idMQCommand::idMQCommand(this: &v4);
  session = this->session;
  v4.method = (idMQMethod *)&v3;
  idMQSession::SendCommand(this: session, cmd: &v4);
  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)&v4);
}


// ========================================================================
// __unwind$119946
// EA  : 0x82F487CC
// RVA : 0x00F487CC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_119946()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: (AMQPConnectionTune *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$119947
// EA  : 0x82F487F4
// RVA : 0x00F487F4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_119947()
{
  int v0; // r12

  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)(v0 - 160 + 96));
}


// ========================================================================
// ?Init@idMQChannel@@QAAXXZ
// EA  : 0x82F4A760
// RVA : 0x00F4A760
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::Init(idMQChannel *this)
{
  this->deferredConnectionStart.filled = false;
  Sys_SignalClear(handle: &this->deferredConnectionStart.signal.handle);
  this->deferredConnectionTune.filled = false;
  Sys_SignalClear(handle: &this->deferredConnectionTune.signal.handle);
  this->deferredConnectionOpenOk.filled = false;
  Sys_SignalClear(handle: &this->deferredConnectionOpenOk.signal.handle);
  this->deferredChannelOpenOk.filled = false;
  Sys_SignalClear(handle: &this->deferredChannelOpenOk.signal.handle);
  this->deferredChannelFlow.filled = false;
  Sys_SignalClear(handle: &this->deferredChannelFlow.signal.handle);
  this->deferredChannelFlowOk.filled = false;
  Sys_SignalClear(handle: &this->deferredChannelFlowOk.signal.handle);
  this->deferredExchangeDeclareOk.filled = false;
  Sys_SignalClear(handle: &this->deferredExchangeDeclareOk.signal.handle);
  this->deferredExchangeDeleteOk.filled = false;
  Sys_SignalClear(handle: &this->deferredExchangeDeleteOk.signal.handle);
  this->deferredQueueDeclareOk.filled = false;
  Sys_SignalClear(handle: &this->deferredQueueDeclareOk.signal.handle);
  this->deferredQueueBindOk.filled = false;
  Sys_SignalClear(handle: &this->deferredQueueBindOk.signal.handle);
  this->deferredQueuePurgeOk.filled = false;
  Sys_SignalClear(handle: &this->deferredQueuePurgeOk.signal.handle);
  this->deferredQueueDeleteOk.filled = false;
  Sys_SignalClear(handle: &this->deferredQueueDeleteOk.signal.handle);
  this->deferredBasicConsumeOk.filled = false;
  Sys_SignalClear(handle: &this->deferredBasicConsumeOk.signal.handle);
  this->deferredBasicCancelOk.filled = false;
  Sys_SignalClear(handle: &this->deferredBasicCancelOk.signal.handle);
  this->deferredBasicGetResultOk.filled = false;
  Sys_SignalClear(handle: &this->deferredBasicGetResultOk.signal.handle);
  this->deferredAMQPBasicRecoverOk.filled = false;
  Sys_SignalClear(handle: &this->deferredAMQPBasicRecoverOk.signal.handle);
}


// ========================================================================
// ?RemoveConsumer@idMQChannel@@AAA_NABVidStr@@@Z
// EA  : 0x82F4A8A0
// RVA : 0x00F4A8A0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

int __fastcall idMQChannel::RemoveConsumer(
        idMQChannel *this,
        const idStr *consumerTag,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v7; // r29
  idList<idMQConsumer *,5> *p_consumers; // r30
  int v9; // r28
  idLayer *Name; // r3
  BOOL v11; // r25
  __int64 v12; // r4
  int num; // r11
  int v15; // r11
  bool v16; // zf
  int v17; // r10
  idMQConsumer **v18; // r9
  int v19; // [sp+8h] [-A8h]
  int v20; // [sp+Ch] [-A4h]
  int v21; // [sp+10h] [-A0h]
  int v22; // [sp+14h] [-9Ch]
  idLayer v23[2]; // [sp+50h] [-60h] BYREF

  v7 = 0;
  if ( this->consumers.num <= 0 )
  {
LABEL_5:
    LODWORD(v12) = consumerTag->data;
    HIDWORD(v12) = "ERROR: AMQP: Unable to find consumer %s for removal.\n";
    idLib::Printf(fmt: v12, a2: a3, a3: a4, a4: a5, a5: v19, a6: v20, a7: v21, a8: v22);
    return 0;
  }
  else
  {
    p_consumers = &this->consumers;
    v9 = 0;
    while ( 1 )
    {
      Name = idLayer::GetName(this: v23, result: (idStr *)p_consumers->list[v9]);
      v11 = (_cntlzw(idStr::Cmp(s1: (const char *)Name->layerDeclName.len, s2: consumerTag->data)) & 0x20) != 0;
      idStr::FreeData(this: (idStr *)v23);
      if ( v11 )
        break;
      ++v7;
      ++v9;
      if ( v7 >= this->consumers.num )
        goto LABEL_5;
    }
    if ( v7 >= 0 )
    {
      num = p_consumers->num;
      if ( v7 < num )
      {
        p_consumers->num = num - 1;
        v16 = v7 >= num - 1;
        v15 = v7;
        if ( !v16 )
        {
          v17 = v7;
          do
          {
            ++v15;
            v18 = &p_consumers->list[v17++];
            *v18 = v18[1];
          }
          while ( v15 < p_consumers->num );
        }
      }
    }
    return 1;
  }
}


// ========================================================================
// __unwind$123444
// EA  : 0x82F4A98C
// RVA : 0x00F4A98C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_123444()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?LookupConsumer@idMQChannel@@AAAPAVidMQConsumer@@ABVidStr@@@Z
// EA  : 0x82F4A9C0
// RVA : 0x00F4A9C0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

idMQConsumer *__fastcall idMQChannel::LookupConsumer(
        idMQChannel *this,
        const idStr *consumerTag,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v7; // r28
  int v8; // r30
  idLayer *Name; // r3
  BOOL v10; // r26
  __int64 v11; // r4
  int v13; // [sp+8h] [-A8h]
  int v14; // [sp+Ch] [-A4h]
  int v15; // [sp+10h] [-A0h]
  int v16; // [sp+14h] [-9Ch]
  idLayer v17[2]; // [sp+50h] [-60h] BYREF

  v7 = 0;
  if ( this->consumers.num <= 0 )
  {
LABEL_5:
    LODWORD(v11) = consumerTag->data;
    HIDWORD(v11) = "ERROR: AMQP: Unable to find consumer %s.\n";
    idLib::Printf(fmt: v11, a2: a3, a3: a4, a4: a5, a5: v13, a6: v14, a7: v15, a8: v16);
    return nullptr;
  }
  else
  {
    v8 = 0;
    while ( 1 )
    {
      Name = idLayer::GetName(this: v17, result: (idStr *)this->consumers.list[v8]);
      v10 = (_cntlzw(idStr::Cmp(s1: (const char *)Name->layerDeclName.len, s2: consumerTag->data)) & 0x20) != 0;
      idStr::FreeData(this: (idStr *)v17);
      if ( v10 )
        return this->consumers.list[v7];
      ++v7;
      ++v8;
      if ( v7 >= this->consumers.num )
        goto LABEL_5;
    }
  }
}


// ========================================================================
// __unwind$123501
// EA  : 0x82F4AA60
// RVA : 0x00F4AA60
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_123501()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?ConnectionClose@idMQChannel@@QAAXGABVidStr@@GG@Z
// EA  : 0x82F4AA90
// RVA : 0x00F4AA90
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::ConnectionClose(
        idMQChannel *this,
        unsigned __int16 replyCode,
        const idStr *replyText,
        unsigned __int16 cId,
        unsigned __int16 mId)
{
  int len; // r30
  idMQSession *session; // r3
  idMQCommand v11; // [sp+50h] [-A0h] BYREF
  AMQPConnectionClose v12[2]; // [sp+80h] [-70h] BYREF

  v12[0].replyText.len = 0;
  v12[0].replyText.baseBuffer[0] = 0;
  v12[0].__vftable = (AMQPConnectionClose_vtbl *)&AMQPConnectionClose::`vftable';
  v12[0].replyText.data = v12[0].replyText.baseBuffer;
  v12[0].replyText.allocedAndFlag = 20;
  v12[0].replyCode = replyCode;
  len = replyText->len;
  idStr::EnsureAlloced(this: &v12[0].replyText, amount: replyText->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v12[0].replyText.data, Src: replyText->data, Size: len);
  v12[0].replyText.data[len] = 0;
  v12[0].replyText.len = len;
  v12[0].cId = cId;
  v12[0].mId = mId;
  idMQCommand::idMQCommand(this: &v11);
  session = this->session;
  v11.method = v12;
  idMQSession::SendCommand(this: session, cmd: &v11);
  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)&v11);
  AMQPConnectionClose::~AMQPConnectionClose(this: v12);
}


// ========================================================================
// __unwind$123547
// EA  : 0x82F4AB58
// RVA : 0x00F4AB58
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_123547()
{
  int v0; // r12

  AMQPConnectionClose::~AMQPConnectionClose(this: (AMQPConnectionClose *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$123548
// EA  : 0x82F4AB80
// RVA : 0x00F4AB80
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_123548()
{
  int v0; // r12

  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)(v0 - 240 + 80));
}


// ========================================================================
// ?ChannelOpen@idMQChannel@@QAAXABVidStr@@@Z
// EA  : 0x82F4ABB0
// RVA : 0x00F4ABB0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::ChannelOpen(idMQChannel *this, const idStr *oob)
{
  idSysMutex *p_protocolWait; // r27
  int len; // r30
  idMQSession *session; // r3
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r4
  int v11; // [sp+8h] [-E8h]
  int v12; // [sp+Ch] [-E4h]
  int v13; // [sp+10h] [-E0h]
  int v14; // [sp+14h] [-DCh]
  AMQPChannelOpen v15; // [sp+60h] [-90h] BYREF
  idMQCommand v16[2]; // [sp+90h] [-60h] BYREF

  p_protocolWait = &this->protocolWait;
  Sys_MutexLock(handle: &this->protocolWait.handle, blocking: true);
  v15.oob.len = 0;
  v15.oob.baseBuffer[0] = 0;
  v15.__vftable = (AMQPChannelOpen_vtbl *)&AMQPChannelOpen::`vftable';
  v15.oob.data = v15.oob.baseBuffer;
  v15.oob.allocedAndFlag = 20;
  len = oob->len;
  idStr::EnsureAlloced(this: &v15.oob, amount: oob->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v15.oob.data, Src: oob->data, Size: len);
  v15.oob.data[len] = 0;
  v15.oob.len = len;
  idMQCommand::idMQCommand(this: v16);
  session = this->session;
  v16[0].method = &v15;
  idMQSession::SendCommand(this: session, cmd: v16);
  LODWORD(v7) = (unsigned __int8)idDeferredResult<AMQPChannelOpenOk>::GetValue(this: (idDeferredResult<AMQPExchangeDeclareOk> *)&this->deferredChannelOpenOk);
  if ( (_DWORD)v7 == 0 )
  {
    HIDWORD(v10) = "ERROR: AMQP: ChannelOpen did not get a response.\n";
    idLib::Printf(fmt: v10, a2: v9, a3: v8, a4: v7, a5: v11, a6: v12, a7: v13, a8: v14);
  }
  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)v16);
  AMQPChannelOpen::~AMQPChannelOpen(this: &v15);
  Sys_MutexUnlock(handle: &p_protocolWait->handle);
}


// ========================================================================
// __unwind$123623
// EA  : 0x82F4ACA0
// RVA : 0x00F4ACA0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_123623()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$123624
// EA  : 0x82F4ACC8
// RVA : 0x00F4ACC8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_123624()
{
  int v0; // r12

  AMQPChannelOpen::~AMQPChannelOpen(this: (AMQPChannelOpen *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$123625
// EA  : 0x82F4ACF0
// RVA : 0x00F4ACF0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_123625()
{
  int v0; // r12

  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)(v0 - 240 + 144));
}


// ========================================================================
// ?_ChannelClose@idMQChannel@@AAAXGABVidStr@@GG@Z
// EA  : 0x82F4AD20
// RVA : 0x00F4AD20
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::_ChannelClose(
        idMQChannel *this,
        unsigned __int16 replyCode,
        const idStr *replyText,
        unsigned __int16 cId,
        unsigned __int16 mId)
{
  int len; // r30
  idMQSession *session; // r3
  idMQCommand v11; // [sp+50h] [-A0h] BYREF
  AMQPChannelClose v12[2]; // [sp+80h] [-70h] BYREF

  v12[0].replyText.len = 0;
  v12[0].replyText.baseBuffer[0] = 0;
  v12[0].__vftable = (AMQPChannelClose_vtbl *)&AMQPChannelClose::`vftable';
  v12[0].replyText.data = v12[0].replyText.baseBuffer;
  v12[0].replyText.allocedAndFlag = 20;
  v12[0].replyCode = replyCode;
  len = replyText->len;
  idStr::EnsureAlloced(this: &v12[0].replyText, amount: replyText->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v12[0].replyText.data, Src: replyText->data, Size: len);
  v12[0].replyText.data[len] = 0;
  v12[0].replyText.len = len;
  v12[0].cId = cId;
  v12[0].mId = mId;
  idMQCommand::idMQCommand(this: &v11);
  session = this->session;
  v11.method = v12;
  idMQSession::SendCommand(this: session, cmd: &v11);
  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)&v11);
  AMQPChannelClose::~AMQPChannelClose(this: v12);
}


// ========================================================================
// __unwind$123790
// EA  : 0x82F4ADE8
// RVA : 0x00F4ADE8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_123790()
{
  int v0; // r12

  AMQPChannelClose::~AMQPChannelClose(this: (AMQPChannelClose *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$123791
// EA  : 0x82F4AE10
// RVA : 0x00F4AE10
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_123791()
{
  int v0; // r12

  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)(v0 - 240 + 80));
}


// ========================================================================
// ?ProcessBasicCancel@idMQChannel@@AAAXABVidStr@@_N@Z
// EA  : 0x82F4AE38
// RVA : 0x00F4AE38
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::ProcessBasicCancel(
        idMQChannel *this,
        const idStr *consumerTag,
        __int64 noWait,
        __int64 a4,
        __int64 a5)
{
  idMQConsumer *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6

  v7 = idMQChannel::LookupConsumer(this, consumerTag, a3: noWait, a4, a5);
  if ( v7 != nullptr )
  {
    v7->ProcessBasicCancel(this: v7, a2: consumerTag);
    idMQChannel::RemoveConsumer(this, consumerTag, a3: v10, a4: v9, a5: v8);
  }
}


// ========================================================================
// ?ProcessBasicCancelOk@idMQChannel@@AAAXABVidStr@@@Z
// EA  : 0x82F4AE98
// RVA : 0x00F4AE98
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::ProcessBasicCancelOk(
        idMQChannel *this,
        const idStr *consumerTag,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  idMQConsumer *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6

  v7 = idMQChannel::LookupConsumer(this, consumerTag, a3, a4, a5);
  if ( v7 != nullptr )
  {
    v7->ProcessBasicCancelOk(this: v7, a2: consumerTag);
    idMQChannel::RemoveConsumer(this, consumerTag, a3: v10, a4: v9, a5: v8);
  }
}


// ========================================================================
// ?ProcessBasicDeliver@idMQChannel@@AAAXABVidStr@@_K_N00PAVAMQPBasicProperties@@ABV?$idList@E$04@@@Z
// EA  : 0x82F4AEF8
// RVA : 0x00F4AEF8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::ProcessBasicDeliver(
        idMQChannel *this,
        const idStr *consumerTag,
        __int64 deliveryTag,
        __int64 exchange,
        __int64 header,
        const idList<unsigned char,5> *body)
{
  int v7; // r30
  int v8; // r29
  int v9; // r28
  int v10; // r27
  int v11; // r26
  int v12; // r25
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  __int64 v16; // r4
  int v17; // [sp+8h] [-88h]
  int v18; // [sp+Ch] [-84h]
  int v19; // [sp+10h] [-80h]
  int v20; // [sp+14h] [-7Ch]

  v7 = HIDWORD(deliveryTag);
  v8 = deliveryTag;
  v9 = HIDWORD(exchange);
  v10 = exchange;
  v11 = HIDWORD(header);
  v12 = header;
  HIDWORD(v16) = idMQChannel::LookupConsumer(this, consumerTag, a3: deliveryTag, a4: exchange, a5: header);
  if ( HIDWORD(v16) != 0 )
    (*(void (__fastcall **)(_DWORD, const idStr *, int, int, int, int, int, int))(*(_DWORD *)HIDWORD(v16) + 16))(
      a1: HIDWORD(v16),
      a2: consumerTag,
      a3: v7,
      a4: v8,
      a5: v9,
      a6: v10,
      a7: v11,
      a8: v12);
  HIDWORD(v16) = "ERROR: AMQP: Was unable to deliver message to a consumer.\n";
  idLib::Printf(fmt: v16, a2: v15, a3: v14, a4: v13, a5: v17, a6: v18, a7: v19, a8: v20);
}


// ========================================================================
// ?Close@idMQChannel@@QAAXXZ
// EA  : 0x82F4B748
// RVA : 0x00F4B748
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::Close(idMQChannel *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  va *v6; // r3
  int v7; // [sp+8h] [-1088h]
  int v8; // [sp+Ch] [-1084h]
  int v9; // [sp+10h] [-1080h]
  int v10; // [sp+14h] [-107Ch]
  int v11; // [sp+18h] [-1078h]
  int v12; // [sp+1Ch] [-1074h]
  idStr v13; // [sp+50h] [-1040h] BYREF
  va v14; // [sp+70h] [-1020h] BYREF

  LODWORD(a5) = &unk_82390000;
  HIDWORD(a3) = this->session->channelNumber;
  v6 = va::va(
         this: &v14,
         fmt: "Channel %d shutting down",
         a3,
         a4,
         a5,
         a6: v7,
         a7: v8,
         a8: v9,
         a9: v10,
         a10: v11,
         a11: v12);
  idStr::idStr(this: &v13, text: v6);
  idMQChannel::_ChannelClose(this, replyCode: 0xC8u, replyText: &v13, cId: 0, mId: 0);
  idStr::FreeData(this: &v13);
}


// ========================================================================
// __unwind$124751
// EA  : 0x82F4B7C4
// RVA : 0x00F4B7C4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_124751()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4240 + 80));
}


// ========================================================================
// ?_BasicPublish@idMQChannel@@AAAXABVidStr@@0_N1ABV?$idList@E$04@@@Z
// EA  : 0x82F4B7F8
// RVA : 0x00F4B7F8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::_BasicPublish(
        idMQChannel *this,
        const idStr *exchange,
        const idStr *routingKey,
        bool mandatory,
        bool immediate,
        const idList<unsigned char,25> *body)
{
  int len; // r29
  int v13; // r29
  AMQPBasicPublish v14; // [sp+50h] [-270h] BYREF
  navSplinePathNode_t v15; // [sp+A0h] [-220h] BYREF

  v14.ticket = 0;
  v14.exchange.len = 0;
  v14.exchange.baseBuffer[0] = 0;
  v14.__vftable = (AMQPBasicPublish_vtbl *)&AMQPBasicPublish::`vftable';
  v14.exchange.data = v14.exchange.baseBuffer;
  v14.routingKey.data = v14.routingKey.baseBuffer;
  v14.routingKey.len = 0;
  v14.routingKey.baseBuffer[0] = 0;
  v14.exchange.allocedAndFlag = 20;
  v14.routingKey.allocedAndFlag = 20;
  AMQPBasicProperties::AMQPBasicProperties(this: (AMQPBasicProperties *)&v15.links.staticList[1].nodeDistance);
  len = exchange->len;
  idStr::EnsureAlloced(this: &v14.exchange, amount: exchange->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v14.exchange.data, Src: exchange->data, Size: len);
  v14.exchange.data[len] = 0;
  v14.exchange.len = len;
  v13 = routingKey->len;
  idStr::EnsureAlloced(this: &v14.routingKey, amount: routingKey->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v14.routingKey.data, Src: routingKey->data, Size: v13);
  v14.routingKey.data[v13] = 0;
  v14.routingKey.len = v13;
  v14.mandatory = mandatory;
  v14.immediate = immediate;
  idMQCommand::idMQCommand(this: (idMQCommand *)&v15);
  LODWORD(v15.position.x) = &v14;
  LODWORD(v15.position.y) = &v15.links.staticList[1].nodeDistance;
  idList<unsigned char,34>::operator=(this: (idList<unsigned char,25> *)&v15.links, other: body);
  idMQSession::SendCommand(this: this->session, cmd: (idMQCommand *)&v15);
  idMQCommand::~idMQCommand(this: &v15);
  AMQPBasicProperties::~AMQPBasicProperties(this: (AMQPBasicProperties *)&v15.links.staticList[1].nodeDistance);
  AMQPBasicPublish::~AMQPBasicPublish(this: &v14);
}


// ========================================================================
// __unwind$125067
// EA  : 0x82F4B940
// RVA : 0x00F4B940
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_125067()
{
  int v0; // r12

  AMQPBasicPublish::~AMQPBasicPublish(this: (AMQPBasicPublish *)(v0 - 704 + 80));
}


// ========================================================================
// __unwind$125068
// EA  : 0x82F4B968
// RVA : 0x00F4B968
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_125068()
{
  int v0; // r12

  AMQPBasicProperties::~AMQPBasicProperties(this: (AMQPBasicProperties *)(v0 - 704 + 208));
}


// ========================================================================
// __unwind$125069
// EA  : 0x82F4B990
// RVA : 0x00F4B990
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_125069()
{
  int v0; // r12

  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)(v0 - 704 + 160));
}


// ========================================================================
// ?ConnectionOpen@idMQChannel@@QAAXAAVidStr@@ABV2@1_N@Z
// EA  : 0x82F4BD40
// RVA : 0x00F4BD40
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::ConnectionOpen(
        idMQChannel *this,
        idStr *knownHosts,
        const idStr *vhost,
        const idStr *capabilities,
        bool insist)
{
  idSysMutex *p_protocolWait; // r25
  int len; // r29
  int v12; // r29
  idMQSession *session; // r3
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  __int64 v17; // r4
  int v18; // r29
  int v19; // [sp+8h] [-148h]
  int v20; // [sp+Ch] [-144h]
  int v21; // [sp+10h] [-140h]
  int v22; // [sp+14h] [-13Ch]
  AMQPConnectionOpen v23; // [sp+50h] [-100h] BYREF
  AMQPConnectionOpenOk v24; // [sp+A0h] [-B0h] BYREF
  idSysMutex *v25; // [sp+C4h] [-8Ch]
  idMQCommand v26[3]; // [sp+D0h] [-80h] BYREF

  p_protocolWait = &this->protocolWait;
  v25 = &this->protocolWait;
  Sys_MutexLock(handle: &this->protocolWait.handle, blocking: true);
  v23.virtualHost.len = 0;
  v23.virtualHost.baseBuffer[0] = 0;
  v23.capabilities.len = 0;
  v23.__vftable = (AMQPConnectionOpen_vtbl *)&AMQPConnectionOpen::`vftable';
  v23.virtualHost.data = v23.virtualHost.baseBuffer;
  v23.capabilities.data = v23.capabilities.baseBuffer;
  v23.capabilities.baseBuffer[0] = 0;
  v23.virtualHost.allocedAndFlag = 20;
  v23.capabilities.allocedAndFlag = 20;
  len = vhost->len;
  idStr::EnsureAlloced(this: &v23.virtualHost, amount: vhost->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v23.virtualHost.data, Src: vhost->data, Size: len);
  v23.virtualHost.data[len] = 0;
  v23.virtualHost.len = len;
  v12 = capabilities->len;
  idStr::EnsureAlloced(this: &v23.capabilities, amount: capabilities->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v23.capabilities.data, Src: capabilities->data, Size: v12);
  v23.capabilities.data[v12] = 0;
  v23.capabilities.len = v12;
  v23.insist = insist;
  idMQCommand::idMQCommand(this: v26);
  session = this->session;
  v26[0].method = &v23;
  idMQSession::SendCommand(this: session, cmd: v26);
  v24.knownHosts.len = 0;
  v24.knownHosts.baseBuffer[0] = 0;
  v24.knownHosts.data = v24.knownHosts.baseBuffer;
  v24.__vftable = (AMQPConnectionOpenOk_vtbl *)&AMQPConnectionOpenOk::`vftable';
  v24.knownHosts.allocedAndFlag = 20;
  if ( (unsigned __int8)idDeferredResult<AMQPConnectionOpenOk>::GetValue(
                          this: &this->deferredConnectionOpenOk,
                          result: &v24) != 0 )
  {
    v18 = v24.knownHosts.len;
    idStr::EnsureAlloced(this: knownHosts, amount: v24.knownHosts.len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: knownHosts->data, Src: v24.knownHosts.data, Size: v18);
    knownHosts->data[v18] = 0;
    knownHosts->len = v18;
  }
  else
  {
    HIDWORD(v17) = "ERROR: AMQP: ConnectionOpen did not get a response.\n";
    idLib::Printf(fmt: v17, a2: v16, a3: v15, a4: v14, a5: v19, a6: v20, a7: v21, a8: v22);
  }
  AMQPConnectionOpenOk::~AMQPConnectionOpenOk(this: &v24);
  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)v26);
  AMQPConnectionOpen::~AMQPConnectionOpen(this: &v23);
  Sys_MutexUnlock(handle: &p_protocolWait->handle);
}


// ========================================================================
// __unwind$125463
// EA  : 0x82F4BF20
// RVA : 0x00F4BF20
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_125463()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 336 + 196));
}


// ========================================================================
// __unwind$125464
// EA  : 0x82F4BF48
// RVA : 0x00F4BF48
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_125464()
{
  int v0; // r12

  AMQPConnectionOpen::~AMQPConnectionOpen(this: (AMQPConnectionOpen *)(v0 - 336 + 80));
}


// ========================================================================
// __unwind$125465
// EA  : 0x82F4BF70
// RVA : 0x00F4BF70
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_125465()
{
  int v0; // r12

  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)(v0 - 336 + 208));
}


// ========================================================================
// __unwind$125466
// EA  : 0x82F4BF98
// RVA : 0x00F4BF98
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_125466()
{
  int v0; // r12

  AMQPConnectionOpenOk::~AMQPConnectionOpenOk(this: (AMQPConnectionOpenOk *)(v0 - 336 + 160));
}


// ========================================================================
// ?BasicPublish@idMQChannel@@QAAXABVidStr@@0ABV?$idList@E$04@@@Z
// EA  : 0x82F4BFC0
// RVA : 0x00F4BFC0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::BasicPublish(
        idMQChannel *this,
        const idStr *exchange,
        const idStr *routingKey,
        const idList<unsigned char,25> *body)
{
  idMQChannel::_BasicPublish(this, exchange, routingKey, mandatory: false, immediate: false, body);
}


// ========================================================================
// ?BasicPublish@idMQChannel@@QAAXABVidStr@@0_N1PAXI@Z
// EA  : 0x82F4BFD8
// RVA : 0x00F4BFD8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::BasicPublish(
        idMQChannel *this,
        const idStr *exchange,
        const idStr *routingKey,
        bool mandatory,
        bool immediate,
        idVehicleState **data,
        int size)
{
  idList<idVehicleState *,5> v7; // [sp+50h] [-20h] BYREF

  v7.size = size;
  v7.num = size;
  v7.granularity = 1;
  v7.list = data;
  v7.memTag = 5;
  v7.listStatic = 1;
  idMQChannel::_BasicPublish(
    this,
    exchange,
    routingKey,
    mandatory,
    immediate,
    body: (const idList<unsigned char,25> *)&v7);
  idList<idThread *,58>::Clear(this: &v7);
}


// ========================================================================
// __unwind$125902
// EA  : 0x82F4C030
// RVA : 0x00F4C030
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_125902()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 112 + 80));
}


// ========================================================================
// ?ProcessBasicGetOk@idMQChannel@@AAAX_K_NABVidStr@@2IPAVAMQPBasicProperties@@ABV?$idList@E$04@@@Z
// EA  : 0x82F4C060
// RVA : 0x00F4C060
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMQChannel::ProcessBasicGetOk(
        idMQChannel *this,
        int a2,
        unsigned __int64 deliveryTag,
        int redelivered,
        const idStr *exchange,
        AMQPBasicProperties *routingKey,
        const idList<unsigned char,25> *messageCount,
        AMQPBasicProperties *header,
        const idList<unsigned char,5> *body)
{
  char v9; // r28
  int v10; // r27
  unsigned __int64 v15; // r30
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  __int64 v19; // r4
  int v20; // [sp+8h] [-108h]
  int v21; // [sp+Ch] [-104h]
  int v22; // [sp+10h] [-100h]
  int v23; // [sp+14h] [-FCh]
  amqpBasicGetResultOk_t v24; // [sp+50h] [-C0h] BYREF

  v15 = *(_QWORD *)(&this - 1);
  v9 = BYTE3(deliveryTag);
  v10 = deliveryTag;
  amqpBasicGetResultOk_t::amqpBasicGetResultOk_t(this: &v24);
  v24.deliveryTag = v15;
  v24.redelivered = v9;
  LODWORD(v15) = *(_DWORD *)v10;
  idStr::EnsureAlloced(this: &v24.exchange, amount: *(_DWORD *)v10 + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v24.exchange.data, Src: *(const void **)(v10 + 4), Size: v15);
  v24.exchange.data[v15] = 0;
  v24.exchange.len = v15;
  LODWORD(v15) = *(_DWORD *)redelivered;
  idStr::EnsureAlloced(
    this: &v24.routingKey,
    amount: *(_DWORD *)redelivered + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: v24.routingKey.data, Src: *(const void **)(redelivered + 4), Size: v15);
  v24.routingKey.data[v15] = 0;
  v24.routingKey.len = v15;
  v24.messageCount = (unsigned int)exchange;
  v24.header = routingKey;
  idList<unsigned char,34>::operator=(this: (idList<unsigned char,25> *)&v24.body, other: messageCount);
  if ( *(_BYTE *)(HIDWORD(v15) + 528) != 0 )
  {
    HIDWORD(v19) = "ERROR: AMQP: Deferred result already filled.\n";
    HIDWORD(v16) = *(unsigned __int8 *)(HIDWORD(v15) + 528);
    idLib::Printf(fmt: v19, a2: v18, a3: v17, a4: v16, a5: v20, a6: v21, a7: v22, a8: v23);
  }
  amqpBasicGetResultOk_t::operator=(this: (amqpBasicGetResultOk_t *)(HIDWORD(v15) + 424), __that: &v24);
  *(_BYTE *)(HIDWORD(v15) + 528) = 1;
  Sys_SignalRaise(handle: (void **)(HIDWORD(v15) + 532));
  amqpBasicGetResultOk_t::~amqpBasicGetResultOk_t(this: &v24);
}


// ========================================================================
// __unwind$126025
// EA  : 0x82F4C168
// RVA : 0x00F4C168
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_126025()
{
  int v0; // r12

  amqpBasicGetResultOk_t::~amqpBasicGetResultOk_t(this: (amqpBasicGetResultOk_t *)(v0 - 272 + 80));
}


// ========================================================================
// ?DecodeMethod@idMQChannel@@SAPAVidMQMethod@@AAVidMQFrame@@@Z
// EA  : 0x82F4D020
// RVA : 0x00F4D020
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

AMQPConnectionStart *__fastcall idMQChannel::DecodeMethod(idMQFrame *frame)
{
  AMQPConnectionStart *started; // r30
  unsigned __int16 UInt16; // r28
  unsigned __int16 v4; // r3
  idDynamicBlock<unsigned char,89> *v5; // r3
  void **v6; // r10
  idDynamicBlock<unsigned char,89> *v7; // r3
  idDynamicBlock<unsigned char,89> *v8; // r3
  AMQPChannelAlert *v9; // r3
  AMQPConnectionStart *v10; // r3
  AMQPConnectionStartOk *v11; // r3
  AMQPConnectionSecure *v12; // r3
  AMQPConnectionSecureOk *v13; // r3
  idDynamicBlock<unsigned char,89> *v14; // r3
  idDynamicBlock<unsigned char,89> *v15; // r3
  idDynamicBlock<unsigned char,89> *v16; // r3
  idDynamicBlock<unsigned char,89> *v17; // r3
  AMQPExchangeDeclare *v18; // r3
  idDynamicBlock<unsigned char,89> *v19; // r3
  idDynamicBlock<unsigned char,89> *v20; // r3
  idDynamicBlock<unsigned char,89> *v21; // r3
  idDynamicBlock<unsigned char,89> *v22; // r3
  idDynamicBlock<unsigned char,89> *v23; // r3
  idDynamicBlock<unsigned char,89> *v24; // r3
  idDynamicBlock<unsigned char,89> *v25; // r3
  idDynamicBlock<unsigned char,89> *v26; // r3
  idDynamicBlock<unsigned char,89> *v27; // r3
  idDynamicBlock<unsigned char,89> *v28; // r3
  idDynamicBlock<unsigned char,89> *v29; // r3
  AMQPQueueDeclare *v30; // r3
  idDynamicBlock<unsigned char,89> *v31; // r3
  AMQPQueueBind *v32; // r3
  idDynamicBlock<unsigned char,89> *v33; // r3
  AMQPQueueUnbind *v34; // r3
  idDynamicBlock<unsigned char,89> *v35; // r3

  started = nullptr;
  UInt16 = idMQFrame::ReadUInt16(this: frame);
  v4 = idMQFrame::ReadUInt16(this: frame);
  if ( UInt16 > 0x28u )
  {
    if ( UInt16 == 50 )
    {
      if ( v4 > 0x1Fu )
      {
        switch ( v4 )
        {
          case '(':
            v35 = idMQMethod::operator new(size: 44);
            if ( v35 != nullptr )
            {
              HIWORD(v35->prev) = 0;
              v35->size = (int)&AMQPQueueDelete::`vftable';
              v35->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)&v35[1].prev;
              v35->next = nullptr;
              v35[1].size = 20;
              HIBYTE(v35[1].prev) = 0;
              started = (AMQPConnectionStart *)v35;
            }
            goto LABEL_152;
          case ')':
            v5 = idMQMethod::operator new(size: 8);
            if ( v5 == nullptr )
              goto LABEL_152;
            v6 = &AMQPQueueDeleteOk::`vftable';
            goto LABEL_151;
          case '2':
            v34 = (AMQPQueueUnbind *)idMQMethod::operator new(size: 152);
            if ( v34 != nullptr )
              started = (AMQPConnectionStart *)AMQPQueueUnbind::AMQPQueueUnbind(this: v34);
            goto LABEL_152;
          case '3':
            v5 = idMQMethod::operator new(size: 4);
            if ( v5 == nullptr )
              goto LABEL_152;
            v6 = &AMQPQueueUnbindOk::`vftable';
            goto LABEL_151;
          default:
            return started;
        }
      }
      if ( v4 != 31 )
      {
        switch ( v4 )
        {
          case 0xAu:
            v30 = (AMQPQueueDeclare *)idMQMethod::operator new(size: 96);
            if ( v30 != nullptr )
              started = (AMQPConnectionStart *)AMQPQueueDeclare::AMQPQueueDeclare(this: v30);
            goto LABEL_152;
          case 0xBu:
            v31 = idMQMethod::operator new(size: 44);
            if ( v31 != nullptr )
            {
              v31->size = (int)&AMQPQueueDeclareOk::`vftable';
              v31->next = v31 + 1;
              v31->prev = nullptr;
              v31->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
              HIBYTE(v31[1].size) = 0;
              started = (AMQPConnectionStart *)v31;
            }
            goto LABEL_152;
          case 0x14u:
            v32 = (AMQPQueueBind *)idMQMethod::operator new(size: 156);
            if ( v32 != nullptr )
              started = (AMQPConnectionStart *)AMQPQueueBind::AMQPQueueBind(this: v32);
            goto LABEL_152;
          case 0x15u:
            v5 = idMQMethod::operator new(size: 4);
            if ( v5 == nullptr )
              goto LABEL_152;
            v6 = &AMQPQueueBindOk::`vftable';
            goto LABEL_151;
          case 0x1Eu:
            v33 = idMQMethod::operator new(size: 44);
            if ( v33 != nullptr )
            {
              HIWORD(v33->prev) = 0;
              v33->size = (int)&AMQPQueuePurge::`vftable';
              v33->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)&v33[1].prev;
              v33->next = nullptr;
              v33[1].size = 20;
              HIBYTE(v33[1].prev) = 0;
              started = (AMQPConnectionStart *)v33;
            }
            goto LABEL_152;
          default:
            return started;
        }
      }
      v5 = idMQMethod::operator new(size: 8);
      if ( v5 == nullptr )
        goto LABEL_152;
      v6 = &AMQPQueuePurgeOk::`vftable';
    }
    else
    {
      if ( UInt16 != 60 )
        return started;
      if ( v4 <= 0x3Cu )
      {
        if ( v4 == 60 )
        {
          v26 = idMQMethod::operator new(size: 120);
          if ( v26 != nullptr )
          {
            v26->size = (int)&AMQPBasicDeliver::`vftable';
            v26->next = v26 + 1;
            v26->prev = nullptr;
            v26->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
            HIBYTE(v26[1].size) = 0;
            v26[3].next = v26 + 4;
            v26[3].node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
            v26[3].prev = nullptr;
            HIBYTE(v26[4].size) = 0;
            v26[5].node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
            v26[5].prev = nullptr;
            v26[5].next = v26 + 6;
            HIBYTE(v26[6].size) = 0;
            started = (AMQPConnectionStart *)v26;
          }
        }
        else if ( v4 > 0x1Eu )
        {
          switch ( v4 )
          {
            case 0x1Fu:
              v25 = idMQMethod::operator new(size: 36);
              if ( v25 != nullptr )
              {
                v25->size = (int)&AMQPBasicCancelOk::`vftable';
                v25->next = v25 + 1;
                v25->prev = nullptr;
                v25->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
                HIBYTE(v25[1].size) = 0;
                started = (AMQPConnectionStart *)v25;
              }
              break;
            case 0x28u:
              v24 = idMQMethod::operator new(size: 76);
              if ( v24 != nullptr )
              {
                HIWORD(v24->prev) = 0;
                v24->size = (int)&AMQPBasicPublish::`vftable';
                v24->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)&v24[1].prev;
                v24->next = nullptr;
                v24[1].size = 20;
                HIBYTE(v24[1].prev) = 0;
                v24[3].size = 20;
                v24[2].next = nullptr;
                v24[2].node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)&v24[3].prev;
                HIBYTE(v24[3].prev) = 0;
                started = (AMQPConnectionStart *)v24;
              }
              break;
            case 0x32u:
              v23 = idMQMethod::operator new(size: 104);
              if ( v23 != nullptr )
              {
                v23->size = (int)&AMQPBasicReturn::`vftable';
                v23->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)&v23[1].prev;
                v23->next = nullptr;
                v23[1].size = 20;
                HIBYTE(v23[1].prev) = 0;
                v23[2].node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)&v23[3].prev;
                v23[3].size = 20;
                v23[2].next = nullptr;
                HIBYTE(v23[3].prev) = 0;
                v23[5].size = 20;
                v23[4].next = nullptr;
                v23[4].node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)&v23[5].prev;
                HIBYTE(v23[5].prev) = 0;
                started = (AMQPConnectionStart *)v23;
              }
              break;
            default:
              return started;
          }
        }
        else
        {
          if ( v4 != 30 )
          {
            switch ( v4 )
            {
              case 0xAu:
                v5 = idMQMethod::operator new(size: 12);
                if ( v5 == nullptr )
                  goto LABEL_152;
                v6 = &AMQPBasicQos::`vftable';
                goto LABEL_151;
              case 0xBu:
                v5 = idMQMethod::operator new(size: 4);
                if ( v5 == nullptr )
                  goto LABEL_152;
                v6 = &AMQPBasicQosOk::`vftable';
                goto LABEL_151;
              case 0x14u:
                v20 = idMQMethod::operator new(size: 76);
                if ( v20 != nullptr )
                {
                  HIWORD(v20->prev) = 0;
                  v20->size = (int)&AMQPBasicConsume::`vftable';
                  v20->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)&v20[1].prev;
                  v20->next = nullptr;
                  v20[1].size = 20;
                  HIBYTE(v20[1].prev) = 0;
                  v20[3].size = 20;
                  v20[2].next = nullptr;
                  v20[2].node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)&v20[3].prev;
                  HIBYTE(v20[3].prev) = 0;
                  started = (AMQPConnectionStart *)v20;
                }
                goto LABEL_152;
              case 0x15u:
                v21 = idMQMethod::operator new(size: 36);
                if ( v21 != nullptr )
                {
                  v21->size = (int)&AMQPBasicConsumeOk::`vftable';
                  v21->next = v21 + 1;
                  v21->prev = nullptr;
                  v21->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
                  HIBYTE(v21[1].size) = 0;
                  started = (AMQPConnectionStart *)v21;
                }
                goto LABEL_152;
              default:
                return started;
            }
          }
          v22 = idMQMethod::operator new(size: 40);
          if ( v22 != nullptr )
          {
            v22->size = (int)&AMQPBasicCancel::`vftable';
            v22->next = v22 + 1;
            v22->prev = nullptr;
            v22->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
            HIBYTE(v22[1].size) = 0;
            started = (AMQPConnectionStart *)v22;
          }
        }
        goto LABEL_152;
      }
      if ( v4 > 0x5Au )
      {
        switch ( v4 )
        {
          case 'd':
            v5 = idMQMethod::operator new(size: 8);
            if ( v5 == nullptr )
              goto LABEL_152;
            v6 = &AMQPBasicRecoverAsync::`vftable';
            break;
          case 'n':
            v5 = idMQMethod::operator new(size: 8);
            if ( v5 == nullptr )
              goto LABEL_152;
            v6 = &AMQPBasicRecover::`vftable';
            break;
          case 'o':
            v5 = idMQMethod::operator new(size: 4);
            if ( v5 == nullptr )
              goto LABEL_152;
            v6 = &AMQPBasicRecoverOk::`vftable';
            break;
          default:
            return started;
        }
      }
      else
      {
        if ( v4 != 90 )
        {
          switch ( v4 )
          {
            case 'F':
              v27 = idMQMethod::operator new(size: 44);
              if ( v27 != nullptr )
              {
                HIWORD(v27->prev) = 0;
                v27->size = (int)&AMQPBasicGet::`vftable';
                v27->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)&v27[1].prev;
                v27->next = nullptr;
                v27[1].size = 20;
                HIBYTE(v27[1].prev) = 0;
                started = (AMQPConnectionStart *)v27;
              }
              goto LABEL_152;
            case 'G':
              v28 = idMQMethod::operator new(size: 88);
              if ( v28 != nullptr )
              {
                v28->size = (int)&AMQPBasicGetOk::`vftable';
                v28[1].next = v28 + 2;
                v28[1].prev = nullptr;
                v28[1].node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
                HIBYTE(v28[2].size) = 0;
                v28[3].node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
                v28[3].prev = nullptr;
                v28[3].next = v28 + 4;
                HIBYTE(v28[4].size) = 0;
                started = (AMQPConnectionStart *)v28;
              }
              goto LABEL_152;
            case 'H':
              v29 = idMQMethod::operator new(size: 36);
              if ( v29 != nullptr )
              {
                v29->size = (int)&AMQPBasicGetEmpty::`vftable';
                v29->next = v29 + 1;
                v29->prev = nullptr;
                v29->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
                HIBYTE(v29[1].size) = 0;
                started = (AMQPConnectionStart *)v29;
              }
              goto LABEL_152;
            case 'P':
              v5 = idMQMethod::operator new(size: 24);
              if ( v5 == nullptr )
                goto LABEL_152;
              v6 = &AMQPBasicAck::`vftable';
              goto LABEL_151;
            default:
              return started;
          }
        }
        v5 = idMQMethod::operator new(size: 24);
        if ( v5 == nullptr )
          goto LABEL_152;
        v6 = &AMQPBasicReject::`vftable';
      }
    }
  }
  else
  {
    switch ( UInt16 )
    {
      case 0x28u:
        switch ( v4 )
        {
          case 0xAu:
            v18 = (AMQPExchangeDeclare *)idMQMethod::operator new(size: 128);
            if ( v18 != nullptr )
              started = (AMQPConnectionStart *)AMQPExchangeDeclare::AMQPExchangeDeclare(this: v18);
            goto LABEL_152;
          case 0xBu:
            v5 = idMQMethod::operator new(size: 4);
            if ( v5 == nullptr )
              goto LABEL_152;
            v6 = &AMQPExchangeDeclareOk::`vftable';
            goto LABEL_151;
          case 0x14u:
            v19 = idMQMethod::operator new(size: 44);
            if ( v19 != nullptr )
            {
              HIWORD(v19->prev) = 0;
              v19->size = (int)&AMQPExchangeDelete::`vftable';
              v19->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)&v19[1].prev;
              v19->next = nullptr;
              v19[1].size = 20;
              HIBYTE(v19[1].prev) = 0;
              started = (AMQPConnectionStart *)v19;
            }
            goto LABEL_152;
          case 0x15u:
            v5 = idMQMethod::operator new(size: 4);
            if ( v5 == nullptr )
              goto LABEL_152;
            v6 = &AMQPExchangeDeleteOk::`vftable';
            goto LABEL_151;
          default:
            return started;
        }
      case 0xAu:
        if ( v4 > 0x1Fu )
        {
          if ( v4 <= 0x32u )
          {
            switch ( v4 )
            {
              case '2':
                v16 = idMQMethod::operator new(size: 68);
                if ( v16 != nullptr )
                {
                  v16->size = (int)&AMQPConnectionRedirect::`vftable';
                  v16->next = v16 + 1;
                  v16->prev = nullptr;
                  v16->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
                  HIBYTE(v16[1].size) = 0;
                  v16[2].node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
                  v16[2].prev = nullptr;
                  v16[2].next = v16 + 3;
                  HIBYTE(v16[3].size) = 0;
                  started = (AMQPConnectionStart *)v16;
                }
                break;
              case '(':
                v15 = idMQMethod::operator new(size: 72);
                if ( v15 != nullptr )
                {
                  v15->size = (int)&AMQPConnectionOpen::`vftable';
                  v15->next = v15 + 1;
                  v15->prev = nullptr;
                  v15->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
                  HIBYTE(v15[1].size) = 0;
                  v15[2].node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
                  v15[2].prev = nullptr;
                  v15[2].next = v15 + 3;
                  HIBYTE(v15[3].size) = 0;
                  started = (AMQPConnectionStart *)v15;
                }
                break;
              case ')':
                v14 = idMQMethod::operator new(size: 36);
                if ( v14 != nullptr )
                {
                  v14->size = (int)&AMQPConnectionOpenOk::`vftable';
                  v14->next = v14 + 1;
                  v14->prev = nullptr;
                  v14->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
                  HIBYTE(v14[1].size) = 0;
                  started = (AMQPConnectionStart *)v14;
                }
                break;
              default:
                return started;
            }
            goto LABEL_152;
          }
          if ( v4 == 60 )
          {
            v17 = idMQMethod::operator new(size: 44);
            if ( v17 != nullptr )
            {
              v17->size = (int)&AMQPConnectionClose::`vftable';
              v17->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)&v17[1].prev;
              v17->next = nullptr;
              v17[1].size = 20;
              HIBYTE(v17[1].prev) = 0;
              started = (AMQPConnectionStart *)v17;
            }
            goto LABEL_152;
          }
          if ( v4 != 61 )
            return started;
          v5 = idMQMethod::operator new(size: 4);
          if ( v5 == nullptr )
            goto LABEL_152;
          v6 = &AMQPConnectionCloseOk::`vftable';
        }
        else
        {
          if ( v4 != 31 )
          {
            switch ( v4 )
            {
              case 0xAu:
                v10 = (AMQPConnectionStart *)idMQMethod::operator new(size: 88);
                if ( v10 != nullptr )
                  started = AMQPConnectionStart::AMQPConnectionStart(this: v10);
                goto LABEL_152;
              case 0xBu:
                v11 = (AMQPConnectionStartOk *)idMQMethod::operator new(size: 132);
                if ( v11 != nullptr )
                  started = (AMQPConnectionStart *)AMQPConnectionStartOk::AMQPConnectionStartOk(this: v11);
                goto LABEL_152;
              case 0x14u:
                v12 = (AMQPConnectionSecure *)idMQMethod::operator new(size: 20);
                if ( v12 != nullptr )
                  started = (AMQPConnectionStart *)AMQPConnectionSecure::AMQPConnectionSecure(this: v12);
                goto LABEL_152;
              case 0x15u:
                v13 = (AMQPConnectionSecureOk *)idMQMethod::operator new(size: 20);
                if ( v13 != nullptr )
                  started = (AMQPConnectionStart *)AMQPConnectionSecureOk::AMQPConnectionSecureOk(this: v13);
                goto LABEL_152;
              case 0x1Eu:
                v5 = idMQMethod::operator new(size: 16);
                if ( v5 == nullptr )
                  goto LABEL_152;
                v6 = &AMQPConnectionTune::`vftable';
                goto LABEL_151;
              default:
                return started;
            }
          }
          v5 = idMQMethod::operator new(size: 16);
          if ( v5 == nullptr )
            goto LABEL_152;
          v6 = &AMQPConnectionTuneOk::`vftable';
        }
        break;
      case 0x14u:
        if ( v4 > 0x15u )
        {
          if ( v4 == 30 )
          {
            v9 = (AMQPChannelAlert *)idMQMethod::operator new(size: 88);
            if ( v9 != nullptr )
              started = (AMQPConnectionStart *)AMQPChannelAlert::AMQPChannelAlert(this: v9);
            goto LABEL_152;
          }
          if ( v4 == 40 )
          {
            v8 = idMQMethod::operator new(size: 44);
            if ( v8 != nullptr )
            {
              v8->size = (int)&AMQPChannelClose::`vftable';
              v8->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)&v8[1].prev;
              v8->next = nullptr;
              v8[1].size = 20;
              HIBYTE(v8[1].prev) = 0;
              started = (AMQPConnectionStart *)v8;
            }
            goto LABEL_152;
          }
          if ( v4 != 41 )
            return started;
          v5 = idMQMethod::operator new(size: 4);
          if ( v5 == nullptr )
            goto LABEL_152;
          v6 = &AMQPChannelCloseOk::`vftable';
        }
        else
        {
          switch ( v4 )
          {
            case 0x15u:
              v5 = idMQMethod::operator new(size: 8);
              if ( v5 == nullptr )
                goto LABEL_152;
              v6 = &AMQPChannelFlowOk::`vftable';
              break;
            case 0xAu:
              v7 = idMQMethod::operator new(size: 36);
              if ( v7 != nullptr )
              {
                v7->size = (int)&AMQPChannelOpen::`vftable';
                v7->next = v7 + 1;
                v7->prev = nullptr;
                v7->node = (idBTreeNode<idDynamicBlock<unsigned char,89>,int> *)20;
                HIBYTE(v7[1].size) = 0;
                started = (AMQPConnectionStart *)v7;
              }
              goto LABEL_152;
            case 0xBu:
              v5 = idMQMethod::operator new(size: 4);
              if ( v5 == nullptr )
                goto LABEL_152;
              v6 = &AMQPChannelOpenOk::`vftable';
              break;
            case 0x14u:
              v5 = idMQMethod::operator new(size: 8);
              if ( v5 == nullptr )
                goto LABEL_152;
              v6 = &AMQPChannelFlow::`vftable';
              break;
            default:
              return started;
          }
        }
        break;
      default:
        return started;
    }
  }
LABEL_151:
  v5->size = (int)v6;
  started = (AMQPConnectionStart *)v5;
LABEL_152:
  if ( started != nullptr )
    started->Populate(this: started, a2: frame);
  return started;
}


// ========================================================================
// __unwind$127267
// EA  : 0x82F4DD64
// RVA : 0x00F4DD64
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_127267()
{
  int v0; // r12

  idMQContentHeader::operator delete(p: *(idDynamicBlock<unsigned char,60> **)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$127252
// EA  : 0x82F4DD8C
// RVA : 0x00F4DD8C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_127252()
{
  int v0; // r12

  idMQContentHeader::operator delete(p: *(idDynamicBlock<unsigned char,60> **)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$127253
// EA  : 0x82F4DDB4
// RVA : 0x00F4DDB4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_127253()
{
  int v0; // r12

  idMQContentHeader::operator delete(p: *(idDynamicBlock<unsigned char,60> **)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$127254
// EA  : 0x82F4DDDC
// RVA : 0x00F4DDDC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_127254()
{
  int v0; // r12

  idMQContentHeader::operator delete(p: *(idDynamicBlock<unsigned char,60> **)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$127255
// EA  : 0x82F4DE04
// RVA : 0x00F4DE04
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_127255()
{
  int v0; // r12

  idMQContentHeader::operator delete(p: *(idDynamicBlock<unsigned char,60> **)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$127270
// EA  : 0x82F4DE2C
// RVA : 0x00F4DE2C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_127270()
{
  int v0; // r12

  idMQContentHeader::operator delete(p: *(idDynamicBlock<unsigned char,60> **)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$127274
// EA  : 0x82F4DE54
// RVA : 0x00F4DE54
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_127274()
{
  int v0; // r12

  idMQContentHeader::operator delete(p: *(idDynamicBlock<unsigned char,60> **)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$127276
// EA  : 0x82F4DE7C
// RVA : 0x00F4DE7C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_127276()
{
  int v0; // r12

  idMQContentHeader::operator delete(p: *(idDynamicBlock<unsigned char,60> **)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$127278
// EA  : 0x82F4DEA4
// RVA : 0x00F4DEA4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_127278()
{
  int v0; // r12

  idMQContentHeader::operator delete(p: *(idDynamicBlock<unsigned char,60> **)(v0 - 128 + 80));
}


// ========================================================================
// ?HandleCommand@idMQChannel@@QAA?AW4MQErrors_t@@AAVidMQCommand@@@Z
// EA  : 0x82F4DED8
// RVA : 0x00F4DED8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

int __fastcall idMQChannel::HandleCommand(idMQChannel *this, idMQCommand *command)
{
  int v4; // r28
  int v5; // r3
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  int v9; // r3
  idMQMethod *v10; // r30
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  int v14; // r3
  idMQMethod *v15; // r30
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  int v19; // r3
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  __int64 v23; // r4
  const AMQPBasicCancelOk *method; // r30
  __int64 v25; // r10
  __int64 v26; // r8
  __int64 v27; // r6
  __int64 v28; // r10
  __int64 v29; // r8
  __int128 v30; // r6
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r6
  unsigned __int64 v34; // r6
  __int64 v35; // r10
  __int64 v36; // r8
  __int64 v37; // r6
  int v38; // r3
  AMQPBasicProperties *v40; // [sp+8h] [-D8h]
  const idList<unsigned char,5> *v41; // [sp+Ch] [-D4h]
  int v42; // [sp+10h] [-D0h]
  int v43; // [sp+14h] [-CCh]
  amqpBasicGetResultOk_t v44; // [sp+50h] [-90h] BYREF

  v4 = 0;
  v5 = command->method->GetClassId(this: command->method);
  if ( v5 > 40 )
  {
    if ( v5 == 50 )
    {
      v38 = command->method->GetMethodId(this: command->method);
      if ( v38 > 31 )
      {
        if ( v38 == 41 )
        {
          idDeferredResult<AMQPQueuePurgeOk>::SetValue(
            this: &this->deferredQueueDeleteOk,
            newValue: (const AMQPQueueDeleteOk *)command->method,
            a3: v37,
            a4: v36,
            a5: v35);
          return v4;
        }
      }
      else
      {
        switch ( v38 )
        {
          case 31:
            idDeferredResult<AMQPQueuePurgeOk>::SetValue(
              this: (idDeferredResult<AMQPQueueDeleteOk> *)&this->deferredQueuePurgeOk,
              newValue: (const AMQPQueueDeleteOk *)command->method,
              a3: v37,
              a4: v36,
              a5: v35);
            return v4;
          case 11:
            idDeferredResult<AMQPQueueDeclareOk>::SetValue(
              this: &this->deferredQueueDeclareOk,
              newValue: (const AMQPQueueDeclareOk *)command->method,
              a3: v37,
              a4: v36,
              a5: v35);
            return v4;
          case 21:
            idDeferredResult<AMQPQueueBindOk>::SetValue(
              this: (idDeferredResult<AMQPBasicRecoverOk> *)&this->deferredQueueBindOk,
              newValue: (const AMQPBasicRecoverOk *)command->method,
              a3: v37,
              a4: v36,
              a5: v35);
            return v4;
          default:
            break;
        }
      }
      return 10;
    }
    if ( v5 == 60 )
    {
      HIDWORD(v23) = command->method->GetMethodId(this: command->method);
      if ( SHIDWORD(v23) > 60 )
      {
        switch ( HIDWORD(v23) )
        {
          case 'G':
            LODWORD(v34) = command->method + 5;
            HIDWORD(v34) = HIBYTE(command->method[4].__vftable);
            idMQChannel::ProcessBasicGetOk(
              this: (idMQChannel *)command->method[2].__vftable,
              a2: (int)command->method[3].__vftable,
              deliveryTag: v34,
              redelivered: (int)&command->method[13],
              exchange: (const idStr *)command->method[21].__vftable,
              routingKey: (AMQPBasicProperties *)command->contentHeader,
              messageCount: (const idList<unsigned char,25> *)&command->contentBody,
              header: v40,
              body: v41);
            break;
          case 'H':
            amqpBasicGetResultOk_t::amqpBasicGetResultOk_t(this: &v44);
            idDeferredResult<amqpBasicGetResultOk_t>::SetValue(
              this: &this->deferredBasicGetResultOk,
              newValue: &v44,
              a3: v33,
              a4: v32,
              a5: v31);
            amqpBasicGetResultOk_t::~amqpBasicGetResultOk_t(this: &v44);
            return 9;
          case 'o':
            idDeferredResult<AMQPQueueBindOk>::SetValue(
              this: &this->deferredAMQPBasicRecoverOk,
              newValue: (const AMQPBasicRecoverOk *)command->method,
              a3: v22,
              a4: v21,
              a5: v20);
            return 9;
          default:
            break;
        }
      }
      else
      {
        if ( HIDWORD(v23) == 60 )
        {
          LODWORD(v28) = &command->contentBody;
          HIDWORD(v28) = command->contentHeader;
          LODWORD(v29) = command->method + 21;
          HIDWORD(v29) = command->method + 13;
          LODWORD(v30) = HIBYTE(command->method[12].__vftable);
          *(_QWORD *)((char *)&v30 + 4) = *(_QWORD *)&command->method[10].__vftable;
          idMQChannel::ProcessBasicDeliver(
            this,
            consumerTag: (const idStr *)command->method[10].__vftable,
            deliveryTag: v30,
            exchange: v29,
            header: v28,
            body: (const idList<unsigned char,5> *)v40);
          return 9;
        }
        if ( SHIDWORD(v23) > 31 )
        {
          if ( HIDWORD(v23) == 50 )
          {
            HIDWORD(v23) = "ERROR: AMQP: idMQChannel::ProcessBasicReturn not currently implemented.\n";
            idLib::Printf(fmt: v23, a2: v22, a3: v21, a4: v20, a5: (int)v40, a6: (int)v41, a7: v42, a8: v43);
            return 9;
          }
        }
        else
        {
          switch ( HIDWORD(v23) )
          {
            case 0x1F:
              method = (const AMQPBasicCancelOk *)command->method;
              idMQChannel::ProcessBasicCancelOk(this, consumerTag: &method->consumerTag, a3: v22, a4: v21, a5: v20);
              idDeferredResult<AMQPBasicConsumeOk>::SetValue(
                this: &this->deferredBasicCancelOk,
                newValue: method,
                a3: v27,
                a4: v26,
                a5: v25);
              return 9;
            case 0x15:
              idDeferredResult<AMQPBasicConsumeOk>::SetValue(
                this: (idDeferredResult<AMQPBasicCancelOk> *)&this->deferredBasicConsumeOk,
                newValue: (const AMQPBasicCancelOk *)command->method,
                a3: v22,
                a4: v21,
                a5: v20);
              return 9;
            case 0x1E:
              HIDWORD(v22) = HIBYTE(command->method[9].__vftable);
              idMQChannel::ProcessBasicCancel(
                this,
                consumerTag: (const idStr *)&command->method[1],
                noWait: v22,
                a4: v21,
                a5: v20);
              return 9;
            default:
              break;
          }
        }
      }
    }
    return 9;
  }
  if ( v5 == 40 )
  {
    v19 = command->method->GetMethodId(this: command->method);
    if ( v19 == 11 )
    {
      idDeferredResult<AMQPQueueBindOk>::SetValue(
        this: (idDeferredResult<AMQPBasicRecoverOk> *)&this->deferredExchangeDeclareOk,
        newValue: (const AMQPBasicRecoverOk *)command->method,
        a3: v18,
        a4: v17,
        a5: v16);
      return v4;
    }
    if ( v19 == 21 )
    {
      idDeferredResult<AMQPQueueBindOk>::SetValue(
        this: (idDeferredResult<AMQPBasicRecoverOk> *)&this->deferredExchangeDeleteOk,
        newValue: (const AMQPBasicRecoverOk *)command->method,
        a3: v18,
        a4: v17,
        a5: v16);
      return v4;
    }
    return 10;
  }
  if ( v5 == 10 )
  {
    v14 = command->method->GetMethodId(this: command->method);
    if ( v14 > 41 )
    {
      if ( v14 == 60 )
      {
        v15 = command->method;
        idMQChannel::_ConnectionCloseOk(this);
        idMQSession::Close(
          this: this->session,
          errorTxt: (const char *)v15[3].__vftable,
          error: MQERROR_SERVER_CLOSED,
          closeOwner: false);
        return v4;
      }
    }
    else
    {
      switch ( v14 )
      {
        case 41:
          idDeferredResult<AMQPBasicConsumeOk>::SetValue(
            this: (idDeferredResult<AMQPBasicCancelOk> *)&this->deferredConnectionOpenOk,
            newValue: (const AMQPBasicCancelOk *)command->method,
            a3: v13,
            a4: v12,
            a5: v11);
          return v4;
        case 10:
          idDeferredResult<AMQPConnectionStart>::SetValue(
            this: &this->deferredConnectionStart,
            newValue: (const AMQPConnectionStart *)command->method,
            a3: v13,
            a4: v12,
            a5: v11);
          return v4;
        case 30:
          idDeferredResult<AMQPConnectionTune>::SetValue(
            this: &this->deferredConnectionTune,
            newValue: (const AMQPConnectionTune *)command->method,
            a3: v13,
            a4: v12,
            a5: v11);
          return v4;
        default:
          break;
      }
    }
    return 10;
  }
  if ( v5 != 20 )
    return 9;
  v9 = command->method->GetMethodId(this: command->method);
  if ( v9 > 21 )
  {
    if ( v9 == 40 )
    {
      v10 = command->method;
      idMQChannel::_ChannelCloseOk(this);
      idMQSession::Close(
        this: this->session,
        errorTxt: (const char *)v10[3].__vftable,
        error: MQERROR_SERVER_CLOSED,
        closeOwner: false);
      return v4;
    }
    if ( v9 == 41 )
    {
      idMQSession::Close(this: this->session);
      return v4;
    }
    return 10;
  }
  if ( v9 == 21 )
  {
    idDeferredResult<AMQPChannelFlow>::SetValue(
      this: &this->deferredChannelFlowOk,
      newValue: (const AMQPChannelFlowOk *)command->method,
      a3: v8,
      a4: v7,
      a5: v6);
    return v4;
  }
  if ( v9 == 11 )
  {
    idDeferredResult<AMQPQueueBindOk>::SetValue(
      this: (idDeferredResult<AMQPBasicRecoverOk> *)&this->deferredChannelOpenOk,
      newValue: (const AMQPBasicRecoverOk *)command->method,
      a3: v8,
      a4: v7,
      a5: v6);
    return v4;
  }
  if ( v9 != 20 )
    return 10;
  idDeferredResult<AMQPChannelFlow>::SetValue(
    this: (idDeferredResult<AMQPChannelFlowOk> *)&this->deferredChannelFlow,
    newValue: (const AMQPChannelFlowOk *)command->method,
    a3: v8,
    a4: v7,
    a5: v6);
  return v4;
}


// ========================================================================
// __unwind$128610
// EA  : 0x82F4E288
// RVA : 0x00F4E288
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_128610()
{
  int v0; // r12

  amqpBasicGetResultOk_t::~amqpBasicGetResultOk_t(this: (amqpBasicGetResultOk_t *)(v0 - 224 + 80));
}


// ========================================================================
// ?ConnectionStartOk@idMQChannel@@QAAXAAVAMQPConnectionTune@@ABVidStr@@ABV?$idList@E$04@@1@Z
// EA  : 0x82F4E2B8
// RVA : 0x00F4E2B8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::ConnectionStartOk(
        idMQChannel *this,
        AMQPConnectionTune *tune,
        const idStr *mechanism,
        const idList<unsigned char,25> *response,
        const idStr *locale)
{
  idSysMutex *p_protocolWait; // r28
  int len; // r30
  int v12; // r30
  idMQSession *session; // r3
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  __int64 v17; // r4
  int v18; // [sp+8h] [-158h]
  int v19; // [sp+Ch] [-154h]
  int v20; // [sp+10h] [-150h]
  int v21; // [sp+14h] [-14Ch]
  idMQCommand v22; // [sp+60h] [-100h] BYREF
  AMQPConnectionStartOk v23; // [sp+90h] [-D0h] BYREF

  p_protocolWait = &this->protocolWait;
  Sys_MutexLock(handle: &this->protocolWait.handle, blocking: true);
  AMQPConnectionStartOk::AMQPConnectionStartOk(this: &v23);
  len = mechanism->len;
  idStr::EnsureAlloced(this: &v23.mechanism, amount: mechanism->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v23.mechanism.data, Src: mechanism->data, Size: len);
  v23.mechanism.data[len] = 0;
  v23.mechanism.len = len;
  idList<unsigned char,34>::operator=(this: (idList<unsigned char,25> *)&v23.response, other: response);
  v12 = locale->len;
  idStr::EnsureAlloced(this: &v23.locale, amount: locale->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v23.locale.data, Src: locale->data, Size: v12);
  v23.locale.data[v12] = 0;
  v23.locale.len = v12;
  idMQCommand::idMQCommand(this: &v22);
  session = this->session;
  v22.method = &v23;
  idMQSession::SendCommand(this: session, cmd: &v22);
  LODWORD(v15) = (unsigned __int8)idDeferredResult<AMQPConnectionTune>::GetValue(
                                    this: &this->deferredConnectionTune,
                                    result: tune);
  if ( (_DWORD)v15 == 0 )
  {
    HIDWORD(v17) = "ERROR: AMQP: ConnectionStartOk did not get a response.\n";
    idLib::Printf(fmt: v17, a2: v16, a3: v15, a4: v14, a5: v18, a6: v19, a7: v20, a8: v21);
  }
  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)&v22);
  AMQPConnectionStartOk::~AMQPConnectionStartOk(this: &v23);
  Sys_MutexUnlock(handle: &p_protocolWait->handle);
}


// ========================================================================
// __unwind$128693
// EA  : 0x82F4E3D0
// RVA : 0x00F4E3D0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_128693()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 352 + 80));
}


// ========================================================================
// __unwind$128694
// EA  : 0x82F4E3F8
// RVA : 0x00F4E3F8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_128694()
{
  int v0; // r12

  AMQPConnectionStartOk::~AMQPConnectionStartOk(this: (AMQPConnectionStartOk *)(v0 - 352 + 144));
}


// ========================================================================
// __unwind$128695
// EA  : 0x82F4E420
// RVA : 0x00F4E420
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_128695()
{
  int v0; // r12

  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)(v0 - 352 + 96));
}


// ========================================================================
// ?_ExchangeDeclare@idMQChannel@@AAAXABVidStr@@0_N1111@Z
// EA  : 0x82F4E450
// RVA : 0x00F4E450
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::_ExchangeDeclare(
        idMQChannel *this,
        const idStr *exchange,
        const idStr *type,
        bool passive,
        bool durable,
        bool autoDelete,
        bool _internal,
        bool noWait)
{
  idSysMutex *p_protocolWait; // r28
  int len; // r30
  int v18; // r30
  idMQSession *session; // r3
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  __int64 v23; // r4
  int v24; // [sp+8h] [-168h]
  int v25; // [sp+Ch] [-164h]
  int v26; // [sp+10h] [-160h]
  int v27; // [sp+14h] [-15Ch]
  AMQPExchangeDeclare v28; // [sp+60h] [-110h] BYREF
  idMQCommand v29[3]; // [sp+E0h] [-90h] BYREF

  p_protocolWait = &this->protocolWait;
  Sys_MutexLock(handle: &this->protocolWait.handle, blocking: true);
  AMQPExchangeDeclare::AMQPExchangeDeclare(this: &v28);
  len = exchange->len;
  idStr::EnsureAlloced(this: &v28.exchange, amount: exchange->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v28.exchange.data, Src: exchange->data, Size: len);
  v28.exchange.data[len] = 0;
  v28.exchange.len = len;
  v18 = type->len;
  idStr::EnsureAlloced(this: &v28.type, amount: type->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: v28.type.data, Src: type->data, Size: v18);
  v28.type.data[v18] = 0;
  v28.type.len = v18;
  v28.passive = passive;
  v28.durable = durable;
  v28.autoDelete = autoDelete;
  v28.isInternal = _internal;
  v28.noWait = noWait;
  idMQCommand::idMQCommand(this: v29);
  session = this->session;
  v29[0].method = &v28;
  idMQSession::SendCommand(this: session, cmd: v29);
  if ( !noWait
    && (unsigned __int8)idDeferredResult<AMQPChannelOpenOk>::GetValue(this: &this->deferredExchangeDeclareOk) == 0 )
  {
    HIDWORD(v23) = "ERROR: AMQP: ExchangeDeclare did not get a response.\n";
    idLib::Printf(fmt: v23, a2: v22, a3: v21, a4: v20, a5: v24, a6: v25, a7: v26, a8: v27);
  }
  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)v29);
  AMQPExchangeDeclare::~AMQPExchangeDeclare(this: &v28);
  Sys_MutexUnlock(handle: &p_protocolWait->handle);
}


// ========================================================================
// __unwind$128764
// EA  : 0x82F4E584
// RVA : 0x00F4E584
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_128764()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 368 + 80));
}


// ========================================================================
// __unwind$128765
// EA  : 0x82F4E5AC
// RVA : 0x00F4E5AC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_128765()
{
  int v0; // r12

  AMQPExchangeDeclare::~AMQPExchangeDeclare(this: (AMQPExchangeDeclare *)(v0 - 368 + 96));
}


// ========================================================================
// __unwind$128766
// EA  : 0x82F4E5D4
// RVA : 0x00F4E5D4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_128766()
{
  int v0; // r12

  idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)(v0 - 368 + 224));
}


// ========================================================================
// ??0idMQChannel@@QAA@PAVidMQSession@@@Z
// EA  : 0x82F4E708
// RVA : 0x00F4E708
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

idMQChannel *__fastcall idMQChannel::idMQChannel(idMQChannel *this, idMQSession *_session)
{
  this->session = _session;
  Sys_MutexCreate(handle: &this->protocolWait.handle);
  idDeferredResult<AMQPConnectionStart>::idDeferredResult<AMQPConnectionStart>(this: &this->deferredConnectionStart);
  idDeferredResult<AMQPConnectionTune>::idDeferredResult<AMQPConnectionTune>(this: &this->deferredConnectionTune);
  idDeferredResult<AMQPConnectionOpenOk>::idDeferredResult<AMQPConnectionOpenOk>(this: &this->deferredConnectionOpenOk);
  idDeferredResult<AMQPChannelOpenOk>::idDeferredResult<AMQPChannelOpenOk>(this: &this->deferredChannelOpenOk);
  idDeferredResult<AMQPChannelFlow>::idDeferredResult<AMQPChannelFlow>(this: &this->deferredChannelFlow);
  idDeferredResult<AMQPChannelFlowOk>::idDeferredResult<AMQPChannelFlowOk>(this: &this->deferredChannelFlowOk);
  idDeferredResult<AMQPExchangeDeclareOk>::idDeferredResult<AMQPExchangeDeclareOk>(this: &this->deferredExchangeDeclareOk);
  idDeferredResult<AMQPExchangeDeleteOk>::idDeferredResult<AMQPExchangeDeleteOk>(this: &this->deferredExchangeDeleteOk);
  idDeferredResult<AMQPQueueDeclareOk>::idDeferredResult<AMQPQueueDeclareOk>(this: &this->deferredQueueDeclareOk);
  idDeferredResult<AMQPQueueBindOk>::idDeferredResult<AMQPQueueBindOk>(this: &this->deferredQueueBindOk);
  idDeferredResult<AMQPQueuePurgeOk>::idDeferredResult<AMQPQueuePurgeOk>(this: &this->deferredQueuePurgeOk);
  idDeferredResult<AMQPQueueDeleteOk>::idDeferredResult<AMQPQueueDeleteOk>(this: &this->deferredQueueDeleteOk);
  idDeferredResult<AMQPBasicConsumeOk>::idDeferredResult<AMQPBasicConsumeOk>(this: &this->deferredBasicConsumeOk);
  idDeferredResult<AMQPBasicCancelOk>::idDeferredResult<AMQPBasicCancelOk>(this: &this->deferredBasicCancelOk);
  idDeferredResult<amqpBasicGetResultOk_t>::idDeferredResult<amqpBasicGetResultOk_t>(this: &this->deferredBasicGetResultOk);
  idDeferredResult<AMQPBasicRecoverOk>::idDeferredResult<AMQPBasicRecoverOk>(this: &this->deferredAMQPBasicRecoverOk);
  this->consumers.list = nullptr;
  this->consumers.granularity = 0;
  this->consumers.memTag = 5;
  this->consumers.listStatic = 0;
  this->consumers.size = 0;
  this->consumers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->consumers);
  return this;
}


// ========================================================================
// __unwind$129078
// EA  : 0x82F4E7F8
// RVA : 0x00F4E7F8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129078()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// __unwind$129079
// EA  : 0x82F4E824
// RVA : 0x00F4E824
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129079()
{
  int v0; // r12

  idDeferredResult<AMQPConnectionStart>::~idDeferredResult<AMQPConnectionStart>(this: (idDeferredResult<AMQPConnectionStart> *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$129080
// EA  : 0x82F4E850
// RVA : 0x00F4E850
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129080()
{
  int v0; // r12

  idDeferredResult<AMQPConnectionTune>::~idDeferredResult<AMQPConnectionTune>(this: (idDeferredResult<AMQPConnectionTune> *)(*(_DWORD *)(v0 - 112 + 132) + 104));
}


// ========================================================================
// __unwind$129081
// EA  : 0x82F4E87C
// RVA : 0x00F4E87C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129081()
{
  int v0; // r12

  idDeferredResult<AMQPConnectionOpenOk>::~idDeferredResult<AMQPConnectionOpenOk>(this: (idDeferredResult<AMQPConnectionOpenOk> *)(*(_DWORD *)(v0 - 112 + 132) + 128));
}


// ========================================================================
// __unwind$129082
// EA  : 0x82F4E8A8
// RVA : 0x00F4E8A8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129082()
{
  int v0; // r12

  idDeferredResult<AMQPExchangeDeleteOk>::~idDeferredResult<AMQPExchangeDeleteOk>(this: (idDeferredResult<AMQPBasicRecoverOk> *)(*(_DWORD *)(v0 - 112 + 132) + 172));
}


// ========================================================================
// __unwind$129083
// EA  : 0x82F4E8D4
// RVA : 0x00F4E8D4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129083()
{
  int v0; // r12

  idDeferredResult<AMQPChannelFlow>::~idDeferredResult<AMQPChannelFlow>(this: (idDeferredResult<AMQPQueueDeleteOk> *)(*(_DWORD *)(v0 - 112 + 132) + 184));
}


// ========================================================================
// __unwind$129084
// EA  : 0x82F4E900
// RVA : 0x00F4E900
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129084()
{
  int v0; // r12

  idDeferredResult<AMQPChannelFlow>::~idDeferredResult<AMQPChannelFlow>(this: (idDeferredResult<AMQPQueueDeleteOk> *)(*(_DWORD *)(v0 - 112 + 132) + 200));
}


// ========================================================================
// __unwind$129085
// EA  : 0x82F4E92C
// RVA : 0x00F4E92C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129085()
{
  int v0; // r12

  idDeferredResult<AMQPExchangeDeleteOk>::~idDeferredResult<AMQPExchangeDeleteOk>(this: (idDeferredResult<AMQPBasicRecoverOk> *)(*(_DWORD *)(v0 - 112 + 132) + 216));
}


// ========================================================================
// __unwind$129086
// EA  : 0x82F4E958
// RVA : 0x00F4E958
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129086()
{
  int v0; // r12

  idDeferredResult<AMQPExchangeDeleteOk>::~idDeferredResult<AMQPExchangeDeleteOk>(this: (idDeferredResult<AMQPBasicRecoverOk> *)(*(_DWORD *)(v0 - 112 + 132) + 228));
}


// ========================================================================
// __unwind$129087
// EA  : 0x82F4E984
// RVA : 0x00F4E984
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129087()
{
  int v0; // r12

  idDeferredResult<AMQPQueueDeclareOk>::~idDeferredResult<AMQPQueueDeclareOk>(this: (idDeferredResult<AMQPQueueDeclareOk> *)(*(_DWORD *)(v0 - 112 + 132) + 240));
}


// ========================================================================
// __unwind$129088
// EA  : 0x82F4E9B0
// RVA : 0x00F4E9B0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129088()
{
  int v0; // r12

  idDeferredResult<AMQPExchangeDeleteOk>::~idDeferredResult<AMQPExchangeDeleteOk>(this: (idDeferredResult<AMQPBasicRecoverOk> *)(*(_DWORD *)(v0 - 112 + 132) + 292));
}


// ========================================================================
// __unwind$129089
// EA  : 0x82F4E9DC
// RVA : 0x00F4E9DC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129089()
{
  int v0; // r12

  idDeferredResult<AMQPChannelFlow>::~idDeferredResult<AMQPChannelFlow>(this: (idDeferredResult<AMQPQueueDeleteOk> *)(*(_DWORD *)(v0 - 112 + 132) + 304));
}


// ========================================================================
// __unwind$129090
// EA  : 0x82F4EA08
// RVA : 0x00F4EA08
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129090()
{
  int v0; // r12

  idDeferredResult<AMQPChannelFlow>::~idDeferredResult<AMQPChannelFlow>(this: (idDeferredResult<AMQPQueueDeleteOk> *)(*(_DWORD *)(v0 - 112 + 132) + 320));
}


// ========================================================================
// __unwind$129091
// EA  : 0x82F4EA34
// RVA : 0x00F4EA34
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129091()
{
  int v0; // r12

  idDeferredResult<AMQPBasicConsumeOk>::~idDeferredResult<AMQPBasicConsumeOk>(this: (idDeferredResult<AMQPBasicConsumeOk> *)(*(_DWORD *)(v0 - 112 + 132) + 336));
}


// ========================================================================
// __unwind$129092
// EA  : 0x82F4EA60
// RVA : 0x00F4EA60
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129092()
{
  int v0; // r12

  idDeferredResult<AMQPBasicCancelOk>::~idDeferredResult<AMQPBasicCancelOk>(this: (idDeferredResult<AMQPBasicCancelOk> *)(*(_DWORD *)(v0 - 112 + 132) + 380));
}


// ========================================================================
// __unwind$129093
// EA  : 0x82F4EA8C
// RVA : 0x00F4EA8C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129093()
{
  int v0; // r12

  idDeferredResult<amqpBasicGetResultOk_t>::~idDeferredResult<amqpBasicGetResultOk_t>(this: (idDeferredResult<amqpBasicGetResultOk_t> *)(*(_DWORD *)(v0 - 112 + 132) + 424));
}


// ========================================================================
// __unwind$129094
// EA  : 0x82F4EAB8
// RVA : 0x00F4EAB8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void _unwind_129094()
{
  int v0; // r12

  idDeferredResult<AMQPExchangeDeleteOk>::~idDeferredResult<AMQPExchangeDeleteOk>(this: (idDeferredResult<AMQPBasicRecoverOk> *)(*(_DWORD *)(v0 - 112 + 132) + 536));
}


// ========================================================================
// ?ExchangeDeclare@idMQChannel@@QAAXABVidStr@@0_N@Z
// EA  : 0x82F4EAE8
// RVA : 0x00F4EAE8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::ExchangeDeclare(idMQChannel *this, const idStr *exchange, const idStr *type, bool durable)
{
  idMQChannel::_ExchangeDeclare(
    this,
    exchange,
    type,
    passive: false,
    durable,
    autoDelete: false,
    _internal: false,
    noWait: false);
}


// ========================================================================
// ?ExchangeDeclare@idMQChannel@@QAAXABVidStr@@0_N1@Z
// EA  : 0x82F4EB00
// RVA : 0x00F4EB00
// PDB : w:\tech5\shared\idlib\networking\amqp\mqprotocol.cpp
// ========================================================================

void __fastcall idMQChannel::ExchangeDeclare(
        idMQChannel *this,
        const idStr *exchange,
        const idStr *type,
        bool durable,
        bool autoDelete)
{
  idMQChannel::_ExchangeDeclare(
    this,
    exchange,
    type,
    passive: false,
    durable,
    autoDelete,
    _internal: false,
    noWait: false);
}

