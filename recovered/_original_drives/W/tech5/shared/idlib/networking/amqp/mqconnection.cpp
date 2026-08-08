
// ========================================================================
// ?GetChannel@idMQConnection@@QAAPAVidMQChannel@@XZ
// EA  : 0x82F41890
// RVA : 0x00F41890
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

idMQChannel *__fastcall idMQConnection::GetChannel(idMQConnection *this)
{
  idMQSession *Session; // r3

  Session = idMQSessionManager::CreateSession(this: this->sessionManager);
  if ( Session != nullptr )
    return Session->protocol;
  else
    return nullptr;
}


// ========================================================================
// ?SendFrame@idMQConnection@@QAAXAAVidMQFrame@@@Z
// EA  : 0x82F418E8
// RVA : 0x00F418E8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void __fastcall idMQConnection::SendFrame(idMQConnection *this, idMQFrame *frame)
{
  idMQFrameHandler::SendFrame(this: this->framer, frame);
}


// ========================================================================
// ?Init@idMQConnection@@QAAXAAUamqpEndpoint_t@@@Z
// EA  : 0x82F418F8
// RVA : 0x00F418F8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void __fastcall idMQConnection::Init(idMQConnection *this, amqpEndpoint_t *_endpoint)
{
  idMQFrameHandler *v4; // r3
  idMQFrameHandler *v5; // r3
  idMQSessionManager *v6; // r3
  idMQSessionManager *v7; // r3
  idMQSession *v8; // r3
  idMQSession *v9; // r3

  v4 = (idMQFrameHandler *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0xB0u,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idMQFrameHandler::idMQFrameHandler(this: v4, _endpoint);
  else
    v5 = nullptr;
  this->framer = v5;
  v6 = (idMQSessionManager *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                               size: 0x1Cu,
                               tag: TAG_NEW,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v6 != nullptr )
    v7 = idMQSessionManager::idMQSessionManager(this: v6, _connection: this);
  else
    v7 = nullptr;
  this->sessionManager = v7;
  v8 = (idMQSession *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 0x50u,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v8 != nullptr )
    v9 = idMQSession::idMQSession(this: v8, _channelNumber: 0, _connection: this);
  else
    v9 = nullptr;
  this->sessionZero = v9;
  idMQSession::Init(this: v9, ignoreChannelOpen: true);
}


// ========================================================================
// __unwind$117688
// EA  : 0x82F419F4
// RVA : 0x00F419F4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void __fastcall _unwind_117688(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$117689
// EA  : 0x82F41A1C
// RVA : 0x00F41A1C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void __fastcall _unwind_117689(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$117690
// EA  : 0x82F41A44
// RVA : 0x00F41A44
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void __fastcall _unwind_117690(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// ?Close@idMQConnection@@QAAXAAUamqpShutdownReason_t@@@Z
// EA  : 0x82F41A78
// RVA : 0x00F41A78
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void __fastcall idMQConnection::Close(idMQConnection *this, amqpShutdownReason_t *reason)
{
  signed int v3; // r29
  idStr v4[2]; // [sp+50h] [-40h] BYREF

  if ( !this->isClosing )
  {
    this->terminateConnection = true;
    this->isClosing = true;
    idStr::idStr(this: v4, text: "AMQP Client closing connection.");
    idMQChannel::ConnectionClose(this: this->sessionZero->protocol, replyCode: 0xC8u, replyText: v4, cId: 0, mId: 0);
    idStr::FreeData(this: v4);
    v3 = Sys_Milliseconds() + 5000;
    if ( !this->connectionTerminated )
    {
      while ( (int)Sys_Milliseconds() <= v3 && !this->connectionTerminated )
        ;
    }
    this->isClosing = false;
  }
}


// ========================================================================
// __unwind$118052
// EA  : 0x82F41B14
// RVA : 0x00F41B14
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118052()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?Close@idMQConnection@@QAAXXZ
// EA  : 0x82F41BB0
// RVA : 0x00F41BB0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void __fastcall idMQConnection::Close(idMQConnection *this)
{
  idMQConnection::Close(this, reason: &this->shutdownReason);
}


// ========================================================================
// ?Close@idMQConnection@@QAAXPBDW4MQErrors_t@@@Z
// EA  : 0x82F41BB8
// RVA : 0x00F41BB8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMQConnection::Close(
        idMQConnection *this,
        const char *errorTxt,
        __int64 error,
        __int64 a4,
        __int64 a5)
{
  int v5; // r3
  idMQConnection *v6; // r31
  const char *v7; // r3
  int v8; // [sp+8h] [-58h]
  int v9; // [sp+Ch] [-54h]
  int v10; // [sp+10h] [-50h]
  int v11; // [sp+14h] [-4Ch]

  *(_DWORD *)(v5 + 52) = errorTxt;
  *(_DWORD *)(v5 + 48) = HIDWORD(error);
  v6 = (idMQConnection *)v5;
  v7 = "%s\n";
  idLib::Printf(fmt: *(__int64 *)&errorTxt, a2: error, a3: a4, a4: a5, a5: v8, a6: v9, a7: v10, a8: v11);
  idMQConnection::Close(this: v6, reason: &v6->shutdownReason);
}


// ========================================================================
// ?MessageThread@idMQConnection@@AAAXXZ
// EA  : 0x82F41C08
// RVA : 0x00F41C08
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void __fastcall idMQConnection::MessageThread(idMQConnection *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r4
  idMQSession *sessionZero; // r3
  va *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  __int64 v14; // r4
  __int64 v15; // r4
  int v16; // [sp+8h] [-10C8h]
  int v17; // [sp+8h] [-10C8h]
  int v18; // [sp+Ch] [-10C4h]
  int v19; // [sp+Ch] [-10C4h]
  int v20; // [sp+10h] [-10C0h]
  int v21; // [sp+10h] [-10C0h]
  int v22; // [sp+14h] [-10BCh]
  int v23; // [sp+14h] [-10BCh]
  int v24; // [sp+18h] [-10B8h]
  int v25; // [sp+1Ch] [-10B4h]
  idMQFrame v26; // [sp+50h] [-1080h] BYREF
  va v27; // [sp+80h] [-1050h] BYREF

  while ( !this->terminateConnection )
  {
    idMQFrame::idMQFrame(this: &v26);
    HIDWORD(v5) = idMQFrameHandler::ReadFrame(this: this->framer, frame: &v26);
    if ( v5 >= 0 )
    {
      if ( HIDWORD(v5) == 0 )
        goto LABEL_17;
      LODWORD(v2) = v26.type;
      if ( v26.type == 8 )
        goto LABEL_17;
      if ( v26.channel != 0 )
      {
        if ( this->terminateConnection )
          goto LABEL_12;
        sessionZero = idMQSessionManager::Lookup(this: this->sessionManager, channelNumber: v26.channel);
      }
      else
      {
        sessionZero = this->sessionZero;
      }
      if ( sessionZero == nullptr )
      {
LABEL_12:
        HIDWORD(v4) = v26.channel;
        v7 = va::va(
               this: &v27,
               fmt: "ERROR: AMQP: Session %d was not found to handle frame. Exiting\n",
               a3: v4,
               a4: v3,
               a5: v2,
               a6: v16,
               a7: v18,
               a8: v20,
               a9: v22,
               a10: v24,
               a11: v25);
        LODWORD(v8) = v7;
        this->shutdownReason.error = MQERROR_SESSION_NOT_FOUND;
        this->shutdownReason.replyText = (const char *)v7;
        idLib::Printf(
          fmt: __SPAIR64__("%s\n", (unsigned int)v7),
          a2: v10,
          a3: v9,
          a4: v8,
          a5: v17,
          a6: v19,
          a7: v21,
          a8: v23);
        idMQConnection::Close(this, reason: &this->shutdownReason);
        goto LABEL_13;
      }
      idMQSession::HandleFrame(this: sessionZero, frame: &v26);
    }
    else
    {
      this->terminateConnection = true;
      HIDWORD(v5) = "ERROR: AMQP:: stream broken: rv < 0\n";
      idLib::Printf(fmt: v5, a2: v4, a3: v3, a4: v2, a5: v16, a6: v18, a7: v20, a8: v22);
    }
LABEL_13:
    if ( !idMQTCP::IsOpen(this: &this->framer->tcp) || this->terminateConnection )
    {
      if ( idMQTCP::IsOpen(this: &this->framer->tcp) )
      {
        HIDWORD(v14) = "AMQP: Connection is terminating\n";
        idLib::Printf(fmt: v14, a2: v13, a3: v12, a4: v11, a5: v16, a6: v18, a7: v20, a8: v22);
        idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)&v26);
        break;
      }
      this->shutdownReason.replyText = "ERROR: AMQP: stream broken: closed";
      LODWORD(v15) = "ERROR: AMQP: stream broken: closed";
      this->shutdownReason.error = MQERROR_STREAM_ERROR;
      HIDWORD(v15) = "%s\n";
      idLib::Printf(fmt: v15, a2: v13, a3: v12, a4: v11, a5: v16, a6: v18, a7: v20, a8: v22);
      idMQConnection::Close(this, reason: &this->shutdownReason);
    }
LABEL_17:
    idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)&v26);
  }
  idMQFrameHandler::Close(this: this->framer);
  idMQSessionManager::Shutdown(this: this->sessionManager);
  this->connectionTerminated = true;
}


// ========================================================================
// __unwind$118136
// EA  : 0x82F41DB4
// RVA : 0x00F41DB4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118136()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 4304 + 80));
}


// ========================================================================
// ?StaticThread@idMQConnection@@CAXPAX@Z
// EA  : 0x82F41DE0
// RVA : 0x00F41DE0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

// attributes: thunk
void __fastcall idMQConnection::StaticThread(idMQConnection *v)
{
  idMQConnection::MessageThread(this: v);
}


// ========================================================================
// ?CreateThread@idMQConnection@@AAAXXZ
// EA  : 0x82F41DE8
// RVA : 0x00F41DE8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void __fastcall idMQConnection::CreateThread(idMQConnection *this)
{
  unsigned int threadHandle; // r3

  threadHandle = this->threadHandle;
  if ( threadHandle != 0 )
  {
    this->terminateConnection = true;
    Sys_JoinThread(threadHandle);
    this->threadHandle = 0;
  }
  this->terminateConnection = false;
  this->threadHandle = Sys_CreateThread(
                         function: (unsigned int (__fastcall *)(void *))idMQConnection::StaticThread,
                         parms: this,
                         priority: THREAD_BELOW_NORMAL,
                         name: "AMQP Client << Server",
                         core: CORE_ANY,
                         stackSize: 0x20000,
                         suspended: false);
}


// ========================================================================
// StrTokenize
// EA  : 0x82F41EE8
// RVA : 0x00F41EE8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void __fastcall StrTokenize(idStr *str, idList<idStr,5> *tokens, char delim)
{
  int v6; // r29
  int v7; // r27
  int v8; // r26
  const idStr *v9; // r3
  int v10; // r27
  int v11; // r26
  const idStr *v12; // r3
  const idStr *v13; // r3
  idStr v14; // [sp+50h] [-A0h] BYREF
  idStr v15; // [sp+70h] [-80h] BYREF
  idStr v16[3]; // [sp+90h] [-60h] BYREF

  v6 = 0;
  if ( tokens->listStatic == 0 || tokens->listStatic == 2 )
  {
    if ( tokens->list != nullptr )
      idListArrayDelete<idStr>(ptr: tokens->list, num: tokens->size);
    tokens->list = nullptr;
    tokens->size = 0;
  }
  tokens->num = 0;
  v7 = idStr::CountChar(str: str->data, c: delim);
  if ( v7 > 0 )
  {
    v8 = idStr::Find(str: str->data, c: delim, start: 0, end: str->len);
    v9 = idStr::Left(this: &v14, result: str, len: v8);
    idList<idStr,5>::Append(this: tokens, obj: v9);
    idStr::FreeData(this: &v14);
    if ( v7 > 1 )
    {
      v10 = v7 - 1;
      do
      {
        v11 = v8 + 1;
        v6 = idStr::Find(str: str->data, c: delim, start: v11, end: str->len);
        v12 = idStr::Mid(this: &v15, result: str, start: v11, len: v6);
        idList<idStr,5>::Append(this: tokens, obj: v12);
        idStr::FreeData(this: &v15);
        --v10;
        v8 = v6;
      }
      while ( v10 != 0 );
    }
    v13 = idStr::Right(this: v16, result: str, len: v6 + 1);
    idList<idStr,5>::Append(this: tokens, obj: v13);
    idStr::FreeData(this: v16);
  }
  else
  {
    idList<idStr,5>::Append(this: tokens, obj: str);
  }
}


// ========================================================================
// __unwind$118302
// EA  : 0x82F42028
// RVA : 0x00F42028
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118302()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$118303
// EA  : 0x82F42050
// RVA : 0x00F42050
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118303()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$118304
// EA  : 0x82F42078
// RVA : 0x00F42078
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118304()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// ??0idMQConnection@@QAA@XZ
// EA  : 0x82F420A0
// RVA : 0x00F420A0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

idMQConnection *__fastcall idMQConnection::idMQConnection(idMQConnection *this)
{
  this->frameMaxSize = 0;
  this->knownHosts.granularity = 0;
  this->knownHosts.memTag = 5;
  this->knownHosts.listStatic = 0;
  this->knownHosts.list = nullptr;
  this->knownHosts.size = 0;
  this->knownHosts.num = 0;
  *(_WORD *)&this->terminateConnection = 1;
  this->framer = nullptr;
  this->sessionManager = nullptr;
  this->sessionZero = nullptr;
  this->isClosing = false;
  this->threadHandle = 0;
  this->shutdownReason.replyText = "AMQP: Toodleloo!";
  this->shutdownReason.replyCode = 0;
  this->shutdownReason.cId = 0;
  this->shutdownReason.mId = 0;
  this->shutdownReason.error = MQERROR_NONE;
  return this;
}


// ========================================================================
// ??1idMQConnection@@QAA@XZ
// EA  : 0x82F42110
// RVA : 0x00F42110
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void __fastcall idMQConnection::~idMQConnection(idMQConnection *this)
{
  idMQSessionManager *sessionManager; // r29
  idMQFrameHandler *framer; // r3
  idMQFrameHandler *v4; // r29
  idStr *list; // r3

  sessionManager = this->sessionManager;
  if ( sessionManager != nullptr )
  {
    idMQCommand::~idMQCommand(this: (navSplinePathNode_t *)this->sessionManager);
    idMem::Free(this: &mem, ptr: sessionManager, align: ALIGN_16);
    this->sessionManager = nullptr;
  }
  framer = this->framer;
  if ( framer != nullptr )
  {
    idMQFrameHandler::Close(this: framer);
    v4 = this->framer;
    if ( v4 != nullptr )
    {
      idMQFrameHandler::~idMQFrameHandler(this: this->framer);
      idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
    }
    this->framer = nullptr;
  }
  if ( this->knownHosts.listStatic == 0 || this->knownHosts.listStatic == 2 )
  {
    list = this->knownHosts.list;
    if ( list != nullptr )
      idListArrayDelete<idStr>(ptr: list, num: this->knownHosts.size);
    this->knownHosts.list = nullptr;
    this->knownHosts.size = 0;
  }
  this->knownHosts.num = 0;
}


// ========================================================================
// __unwind$118396
// EA  : 0x82F421D4
// RVA : 0x00F421D4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118396()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 144 + 164) + 4));
}


// ========================================================================
// ?OpenCommunications@idMQConnection@@AAA_NXZ
// EA  : 0x82F42450
// RVA : 0x00F42450
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

int __fastcall idMQConnection::OpenCommunications(idMQConnection *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r4
  __int64 v8; // r8
  va *v9; // r3
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r8
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r4
  int v17; // r11
  int i; // ctr
  unsigned int frameMax; // r5
  idMQSession *sessionZero; // r10
  unsigned __int16 heartbeat; // r6
  unsigned __int16 channelMax; // r4
  int v23; // [sp+8h] [-11C8h]
  int v24; // [sp+8h] [-11C8h]
  int v25; // [sp+Ch] [-11C4h]
  int v26; // [sp+Ch] [-11C4h]
  int v27; // [sp+10h] [-11C0h]
  int v28; // [sp+10h] [-11C0h]
  int v29; // [sp+14h] [-11BCh]
  int v30; // [sp+14h] [-11BCh]
  int v31; // [sp+18h] [-11B8h]
  int v32; // [sp+1Ch] [-11B4h]
  idList<idStr,5> v33; // [sp+50h] [-1180h] BYREF
  AMQPConnectionTune v34; // [sp+60h] [-1170h] BYREF
  idList<idDeclVehicleUpgrade const *,5> v35; // [sp+70h] [-1160h] BYREF
  idStr v36; // [sp+80h] [-1150h] BYREF
  idStr v37; // [sp+A0h] [-1130h] BYREF
  AMQPConnectionStart v38; // [sp+C0h] [-1110h] BYREF
  idStr v39; // [sp+120h] [-10B0h] BYREF
  idStr v40; // [sp+140h] [-1090h] BYREF
  idStr v41; // [sp+160h] [-1070h] BYREF
  idStr v42; // [sp+180h] [-1050h] BYREF
  va v43; // [sp+1A0h] [-1030h] BYREF

  if ( !idMQFrameHandler::SendHeader(this: this->framer) )
    return 0;
  AMQPConnectionStart::AMQPConnectionStart(this: &v38);
  LODWORD(v2) = (unsigned __int8)idDeferredResult<AMQPConnectionStart>::GetValue(
                                   this: &this->sessionZero->protocol->deferredConnectionStart,
                                   result: &v38);
  if ( (_DWORD)v2 == 0 )
  {
    LODWORD(v5) = 6;
    LODWORD(v6) = "ERROR: AMQP: Unable to get ConnectionStart details.";
    this->shutdownReason.error = MQERROR_CONNECTION_START;
    HIDWORD(v5) = &unk_821C0000;
    this->shutdownReason.replyText = "ERROR: AMQP: Unable to get ConnectionStart details.";
    HIDWORD(v6) = "%s\n";
    idLib::Printf(fmt: v6, a2: v4, a3: v3, a4: v5, a5: v23, a6: v25, a7: v27, a8: v29);
    idMQConnection::Close(this, reason: &this->shutdownReason);
    AMQPConnectionStart::~AMQPConnectionStart(this: &v38);
    return 0;
  }
  HIDWORD(v8) = v38.versionMajor;
  if ( v38.versionMajor == 8 || (LODWORD(v8) = v38.versionMinor, v38.versionMinor == 0) )
  {
    *(_WORD *)&v33.memTag = 1280;
    memset(&v33, 0, 14);
    v36.len = 0;
    v36.data = v36.baseBuffer;
    v36.allocedAndFlag = 20;
    v36.baseBuffer[0] = 0;
    idStr::CopyRange(this: &v36, text: (const char *)v38.mechanisms.list, start: 0, end: v38.mechanisms.num);
    StrTokenize(str: &v36, tokens: &v33, delim: 32);
    if ( v33.num > 0 )
    {
      idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v35);
      idList<unsigned char,19>::SetNum(this: (idList<unsigned char,37> *)&v35, newNum: 12);
      v17 = 0;
      for ( i = 12; i != 0; --i )
      {
        *((_BYTE *)v35.list + v17) = byte_82389ED8[v17];
        ++v17;
      }
      v34.__vftable = (AMQPConnectionTune_vtbl *)&AMQPConnectionTune::`vftable';
      idStr::idStr(this: &v41, text: "en_US");
      idStr::idStr(this: &v39, text: "PLAIN");
      idMQChannel::ConnectionStartOk(
        this: this->sessionZero->protocol,
        tune: &v34,
        mechanism: &v39,
        response: (const idList<unsigned char,5> *)&v35,
        locale: &v41);
      idStr::FreeData(this: &v39);
      idStr::FreeData(this: &v41);
      idMQSessionManager::Init(this: this->sessionManager, _maxSessions: v34.channelMax);
      frameMax = v34.frameMax;
      sessionZero = this->sessionZero;
      heartbeat = v34.heartbeat;
      channelMax = v34.channelMax;
      this->frameMaxSize = v34.frameMax;
      idMQChannel::ConnectionTuneOk(this: sessionZero->protocol, channelMax, frameMax, heartbeat);
      v37.allocedAndFlag = 20;
      v37.len = 0;
      v37.data = v37.baseBuffer;
      v37.baseBuffer[0] = 0;
      idStr::idStr(this: &v40, text: &byte_8200D768);
      idStr::idStr(this: &v42, text: "/");
      idMQChannel::ConnectionOpen(
        this: this->sessionZero->protocol,
        knownHosts: &v37,
        vhost: &v42,
        capabilities: &v40,
        insist: false);
      idStr::FreeData(this: &v42);
      idStr::FreeData(this: &v40);
      StrTokenize(str: &v37, tokens: &this->knownHosts, delim: 32);
      idStr::FreeData(this: &v37);
      v34.__vftable = (AMQPConnectionTune_vtbl *)&idMQMethod::`vftable';
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v35);
      idStr::FreeData(this: &v36);
      idList<idStr,99>::~idList<idStr,99>(this: &v33);
      AMQPConnectionStart::~AMQPConnectionStart(this: &v38);
      return 1;
    }
    else
    {
      LODWORD(v15) = 8;
      LODWORD(v16) = "ERROR: AMQP: Problem parsing auth mechanisms or none provided by server.";
      this->shutdownReason.error = MQERROR_AUTH_FAILED;
      HIDWORD(v15) = &unk_821C0000;
      this->shutdownReason.replyText = "ERROR: AMQP: Problem parsing auth mechanisms or none provided by server.";
      HIDWORD(v16) = "%s\n";
      idLib::Printf(fmt: v16, a2: v14, a3: v13, a4: v15, a5: v23, a6: v25, a7: v27, a8: v29);
      idMQConnection::Close(this, reason: &this->shutdownReason);
      idStr::FreeData(this: &v36);
      idList<idStr,99>::~idList<idStr,99>(this: &v33);
      AMQPConnectionStart::~AMQPConnectionStart(this: &v38);
      return 0;
    }
  }
  else
  {
    v9 = va::va(
           this: &v43,
           fmt: "ERROR: AMQP: Protocol version mismatch. Requested %d.%d but got %d.%d",
           a3: 0x800000000LL,
           a4: v8,
           a5: v2,
           a6: v23,
           a7: v25,
           a8: v27,
           a9: v29,
           a10: v31,
           a11: v32);
    LODWORD(v10) = 7;
    this->shutdownReason.replyText = (const char *)v9;
    HIDWORD(v10) = &unk_821C0000;
    this->shutdownReason.error = MQERROR_BAD_SPEC_VERSION;
    idLib::Printf(
      fmt: __SPAIR64__("%s\n", (unsigned int)v9),
      a2: v12,
      a3: v11,
      a4: v10,
      a5: v24,
      a6: v26,
      a7: v28,
      a8: v30);
    idMQConnection::Close(this, reason: &this->shutdownReason);
    AMQPConnectionStart::~AMQPConnectionStart(this: &v38);
    return 0;
  }
}


// ========================================================================
// __unwind$118644
// EA  : 0x82F42768
// RVA : 0x00F42768
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118644()
{
  int v0; // r12

  AMQPConnectionStart::~AMQPConnectionStart(this: (AMQPConnectionStart *)(v0 - 4560 + 192));
}


// ========================================================================
// __unwind$118645
// EA  : 0x82F42790
// RVA : 0x00F42790
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118645()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 4560 + 80));
}


// ========================================================================
// __unwind$118646
// EA  : 0x82F427B8
// RVA : 0x00F427B8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118646()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 128));
}


// ========================================================================
// __unwind$118647
// EA  : 0x82F427E0
// RVA : 0x00F427E0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118647()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4560 + 112));
}


// ========================================================================
// __unwind$118648
// EA  : 0x82F42808
// RVA : 0x00F42808
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118648()
{
  int v0; // r12

  AMQPQueueDeleteOk::~AMQPQueueDeleteOk(this: (AMQPConnectionTune *)(v0 - 4560 + 96));
}


// ========================================================================
// __unwind$118649
// EA  : 0x82F42830
// RVA : 0x00F42830
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118649()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 352));
}


// ========================================================================
// __unwind$118650
// EA  : 0x82F42858
// RVA : 0x00F42858
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118650()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 288));
}


// ========================================================================
// __unwind$118651
// EA  : 0x82F42880
// RVA : 0x00F42880
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118651()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 160));
}


// ========================================================================
// __unwind$118652
// EA  : 0x82F428A8
// RVA : 0x00F428A8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118652()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 320));
}


// ========================================================================
// __unwind$118653
// EA  : 0x82F428D0
// RVA : 0x00F428D0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

void _unwind_118653()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4560 + 384));
}


// ========================================================================
// ?Connect@idMQConnection@@QAA_NXZ
// EA  : 0x82F428F8
// RVA : 0x00F428F8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqconnection.cpp
// ========================================================================

int __fastcall idMQConnection::Connect(idMQConnection *this)
{
  int result; // r3

  result = idMQFrameHandler::Connect(this: this->framer);
  if ( (_BYTE)result != 0 )
  {
    idMQConnection::CreateThread(this);
    result = idMQConnection::OpenCommunications(this);
    if ( (_BYTE)result != 0 )
      this->connectionTerminated = false;
  }
  return result;
}

