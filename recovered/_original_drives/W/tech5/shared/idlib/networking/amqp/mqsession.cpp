
// ========================================================================
// ??0idMQSession@@QAA@HPAVidMQConnection@@@Z
// EA  : 0x82F4EB20
// RVA : 0x00F4EB20
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

idMQSession *__fastcall idMQSession::idMQSession(idMQSession *this, int _channelNumber, idMQConnection *_connection)
{
  this->connection = _connection;
  idMQCommandBuilder::idMQCommandBuilder(this: &this->cmdBuilder);
  this->protocol = nullptr;
  idMQCommand::idMQCommand(this: &this->currentCommand);
  this->channelNumber = _channelNumber;
  this->isOpen = false;
  return this;
}


// ========================================================================
// __unwind$117244
// EA  : 0x82F4EB6C
// RVA : 0x00F4EB6C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

void _unwind_117244()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// ?Close@idMQSession@@QAAXXZ
// EA  : 0x82F4EB98
// RVA : 0x00F4EB98
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

void __fastcall idMQSession::Close(idMQSession *this, int a2, __int64 a3, __int64 a4)
{
  idMQConnection *connection; // r11
  __int64 v5; // r10

  connection = this->connection;
  LODWORD(v5) = 0;
  this->isOpen = false;
  if ( !connection->connectionTerminated )
  {
    HIDWORD(v5) = connection->connectionTerminated;
    idMQChannel::Close(this: this->protocol, a2, a3, a4, a5: v5);
  }
}


// ========================================================================
// ?Close@idMQSession@@QAAXPBDW4MQErrors_t@@_N@Z
// EA  : 0x82F4EBC0
// RVA : 0x00F4EBC0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

void __fastcall idMQSession::Close(idMQSession *this, const char *errorTxt, __int64 closeOwner, __int64 a4)
{
  idMQConnection *connection; // r11
  __int64 v5; // r10
  int v8; // r28
  char v9; // r30
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6

  connection = this->connection;
  LODWORD(v5) = 0;
  this->isOpen = false;
  v8 = HIDWORD(closeOwner);
  v9 = closeOwner;
  if ( !connection->connectionTerminated )
  {
    HIDWORD(v5) = connection->connectionTerminated;
    idMQChannel::Close(this: this->protocol, a2: (int)errorTxt, a3: closeOwner, a4, a5: v5);
    if ( v9 != 0 )
    {
      HIDWORD(v12) = v8;
      idMQConnection::Close(this: this->connection, errorTxt, error: v12, a4: v11, a5: v10);
    }
  }
}


// ========================================================================
// ?HandleFrame@idMQSession@@QAAXAAVidMQFrame@@@Z
// EA  : 0x82F4EC20
// RVA : 0x00F4EC20
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

void __fastcall idMQSession::HandleFrame(idMQSession *this, idMQFrame *frame, __int64 a3, __int64 a4, __int64 a5)
{
  idMQCommand *p_currentCommand; // r30
  int v7; // r29
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  va *v11; // r3
  __int64 v12; // r6
  __int64 v13; // r8
  int v14; // [sp+8h] [-1068h]
  int v15; // [sp+Ch] [-1064h]
  int v16; // [sp+10h] [-1060h]
  int v17; // [sp+14h] [-105Ch]
  int v18; // [sp+18h] [-1058h]
  int v19; // [sp+1Ch] [-1054h]
  va v20; // [sp+50h] [-1020h] BYREF

  p_currentCommand = &this->currentCommand;
  HIDWORD(a3) = frame;
  idMQCommandBuilder::HandleFrame(this: &this->cmdBuilder, command: &this->currentCommand, frame: a3, a4, a5);
  if ( this->currentCommand.complete )
  {
    v7 = idMQChannel::HandleCommand(this: this->protocol, command: p_currentCommand);
    idMQCommand::Reset(this: p_currentCommand);
    if ( v7 > 0 )
    {
      HIDWORD(v10) = this->channelNumber;
      v11 = va::va(
              this: &v20,
              fmt: "ERROR: AMQP: Unable to process frame on channel %d.",
              a3: v10,
              a4: v9,
              a5: v8,
              a6: v14,
              a7: v15,
              a8: v16,
              a9: v17,
              a10: v18,
              a11: v19);
      LODWORD(v12) = 0;
      HIDWORD(v12) = v7;
      idMQSession::Close(this, errorTxt: v11->buffer, closeOwner: v12, a4: v13);
    }
  }
}


// ========================================================================
// ?SendCommand@idMQSession@@QAAXAAVidMQCommand@@@Z
// EA  : 0x82F4ECB0
// RVA : 0x00F4ECB0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

void __fastcall idMQSession::SendCommand(idMQSession *this, idMQCommand *cmd)
{
  unsigned __int16 v4; // r3
  int v5; // r10
  int v6; // r9
  int v7; // r8
  int v8; // r7
  int v9; // r6
  int v10; // r5
  unsigned __int16 v11; // r3
  int v12; // r10
  int v13; // r9
  int v14; // r8
  int v15; // r7
  int v16; // r6
  int v17; // r5
  int num; // r28
  unsigned __int16 v19; // r3
  int v20; // r10
  int v21; // r9
  int v22; // r8
  int v23; // r7
  int v24; // r6
  int v25; // r5
  int v26; // r10
  int v27; // r9
  int v28; // r8
  int v29; // r7
  int v30; // r6
  int v31; // r5
  int v32; // r10
  int v33; // r9
  int v34; // r8
  int v35; // r7
  unsigned __int64 v36; // r6
  int v37; // [sp+8h] [-108h]
  int v38; // [sp+8h] [-108h]
  int v39; // [sp+8h] [-108h]
  int v40; // [sp+8h] [-108h]
  __int64 v41; // [sp+8h] [-108h]
  int v42; // [sp+Ch] [-104h]
  int v43; // [sp+Ch] [-104h]
  int v44; // [sp+Ch] [-104h]
  int v45; // [sp+Ch] [-104h]
  int v46; // [sp+10h] [-100h]
  int v47; // [sp+10h] [-100h]
  int v48; // [sp+10h] [-100h]
  int v49; // [sp+10h] [-100h]
  __int64 v50; // [sp+10h] [-100h]
  int v51; // [sp+14h] [-FCh]
  int v52; // [sp+14h] [-FCh]
  int v53; // [sp+14h] [-FCh]
  int v54; // [sp+14h] [-FCh]
  int v55; // [sp+18h] [-F8h]
  int v56; // [sp+18h] [-F8h]
  int v57; // [sp+18h] [-F8h]
  int v58; // [sp+18h] [-F8h]
  __int64 v59; // [sp+18h] [-F8h]
  unsigned __int16 v60; // [sp+1Eh] [-F2h]
  unsigned __int16 v61; // [sp+1Eh] [-F2h]
  unsigned __int16 v62; // [sp+1Eh] [-F2h]
  unsigned __int16 v63; // [sp+1Eh] [-F2h]
  idMQFrame v64; // [sp+50h] [-C0h] BYREF
  idMQFrame v65; // [sp+80h] [-90h] BYREF
  idMQFrame v66[2]; // [sp+B0h] [-60h] BYREF

  idMQFrame::idMQFrame(this: &v64, _type: 1u, _channel: this->channelNumber);
  v4 = cmd->method->GetClassId(this: cmd->method);
  idMQFrame::WriteUInt16(
    this: &v64,
    value: v4,
    a3: v10,
    a4: v9,
    a5: v8,
    a6: v7,
    a7: v6,
    a8: v5,
    a9: v37,
    a10: v42,
    a11: v46,
    a12: v51,
    a13: v55,
    a14: v60);
  v11 = cmd->method->GetMethodId(this: cmd->method);
  idMQFrame::WriteUInt16(
    this: &v64,
    value: v11,
    a3: v17,
    a4: v16,
    a5: v15,
    a6: v14,
    a7: v13,
    a8: v12,
    a9: v38,
    a10: v43,
    a11: v47,
    a12: v52,
    a13: v56,
    a14: v61);
  cmd->method->ToFrame(this: cmd->method, a2: &v64);
  idMQFrame::FinalizeFrame(this: &v64);
  idMQConnection::SendFrame(this: this->connection, frame: &v64);
  if ( cmd->method->HasContent(this: cmd->method) )
  {
    num = cmd->contentBody.num;
    idMQFrame::idMQFrame(this: &v65, _type: 2u, _channel: this->channelNumber);
    v19 = cmd->contentHeader->GetProtocolId(this: cmd->contentHeader);
    idMQFrame::WriteUInt16(
      this: &v65,
      value: v19,
      a3: v25,
      a4: v24,
      a5: v23,
      a6: v22,
      a7: v21,
      a8: v20,
      a9: v39,
      a10: v44,
      a11: v48,
      a12: v53,
      a13: v57,
      a14: v62);
    idMQFrame::WriteUInt16(
      this: &v65,
      value: 0,
      a3: v31,
      a4: v30,
      a5: v29,
      a6: v28,
      a7: v27,
      a8: v26,
      a9: v40,
      a10: v45,
      a11: v49,
      a12: v54,
      a13: v58,
      a14: v63);
    idMQFrame::WriteUInt64(
      this: &v65,
      a2: num,
      value: v36,
      a4: v35,
      a5: v34,
      a6: v33,
      a7: v32,
      a8: v41,
      a9: v50,
      a10: v59);
    cmd->contentHeader->ToFrame(this: cmd->contentHeader, a2: &v65);
    idMQConnection::SendFrame(this: this->connection, frame: &v65);
    idMQFrame::idMQFrame(this: v66, _type: 3u, _channel: this->channelNumber);
    idMQFrame::WriteData(this: v66, ptr: cmd->contentBody.list, length: num);
    idMQConnection::SendFrame(this: this->connection, frame: v66);
    idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)v66);
    idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)&v65);
  }
  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)&v64);
}


// ========================================================================
// __unwind$117375
// EA  : 0x82F4EE2C
// RVA : 0x00F4EE2C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

void _unwind_117375()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$117376
// EA  : 0x82F4EE54
// RVA : 0x00F4EE54
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

void _unwind_117376()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$117377
// EA  : 0x82F4EE7C
// RVA : 0x00F4EE7C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

void _unwind_117377()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 272 + 176));
}


// ========================================================================
// ?Lookup@idMQSessionManager@@QAAPAVidMQSession@@H@Z
// EA  : 0x82F4EEA8
// RVA : 0x00F4EEA8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

idMQSession *__fastcall idMQSessionManager::Lookup(idMQSessionManager *this, int channelNumber)
{
  int num; // r9
  int v3; // r11
  idMQSession **list; // r8
  int i; // r10

  if ( !this->initialized )
    return nullptr;
  num = this->sessionList.num;
  v3 = 0;
  if ( num <= 0 )
    return nullptr;
  list = this->sessionList.list;
  for ( i = 0; list[i] == nullptr || v3 != channelNumber - 1; ++i )
  {
    if ( ++v3 >= num )
      return nullptr;
  }
  return list[v3];
}


// ========================================================================
// ?Init@idMQSession@@QAAX_N@Z
// EA  : 0x82F4EF10
// RVA : 0x00F4EF10
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

void __fastcall idMQSession::Init(idMQSession *this, bool ignoreChannelOpen)
{
  idMQChannel *v4; // r3
  idMQChannel *v5; // r3
  idStr v6[2]; // [sp+60h] [-40h] BYREF

  v4 = (idMQChannel *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 0x238u,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idMQChannel::idMQChannel(this: v4, _session: this);
  else
    v5 = nullptr;
  this->protocol = v5;
  idMQChannel::Init(this: v5);
  if ( !ignoreChannelOpen )
  {
    idStr::idStr(this: v6, text: &byte_8200D768);
    idMQChannel::ChannelOpen(this: this->protocol, oob: v6);
    idStr::FreeData(this: v6);
  }
  this->isOpen = true;
}


// ========================================================================
// __unwind$117569
// EA  : 0x82F4EFC0
// RVA : 0x00F4EFC0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

void __fastcall _unwind_117569(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// __unwind$117570
// EA  : 0x82F4EFE8
// RVA : 0x00F4EFE8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

void _unwind_117570()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// ?Shutdown@idMQSessionManager@@QAAXXZ
// EA  : 0x82F4F010
// RVA : 0x00F4F010
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

void __fastcall idMQSessionManager::Shutdown(idMQSessionManager *this, int a2, __int64 a3, __int64 a4)
{
  int v5; // r29
  int v6; // r31
  idMQSession **list; // r11
  idMQSession *v8; // r10
  idMQSession *v9; // r11
  __int64 v10; // r10
  idMQSession **v11; // r4

  v5 = 0;
  if ( this->sessionList.num > 0 )
  {
    v6 = 0;
    do
    {
      list = this->sessionList.list;
      v8 = list[v6];
      if ( v8 != nullptr )
      {
        v9 = list[v6];
        LODWORD(v10) = v8->connection;
        v9->isOpen = false;
        if ( *(_BYTE *)(v10 + 33) == 0 )
        {
          HIDWORD(v10) = *(unsigned __int8 *)(v10 + 33);
          idMQChannel::Close(this: v9->protocol, a2, a3, a4, a5: v10);
        }
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->sessionList.num );
  }
  if ( this->sessionList.listStatic == 0 || this->sessionList.listStatic == 2 )
  {
    v11 = this->sessionList.list;
    if ( v11 != nullptr )
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    this->sessionList.list = nullptr;
    this->sessionList.size = 0;
  }
  this->sessionList.num = 0;
}


// ========================================================================
// ?CreateSession@idMQSessionManager@@QAAPAVidMQSession@@XZ
// EA  : 0x82F4F0C8
// RVA : 0x00F4F0C8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

idMQSession *__fastcall idMQSessionManager::CreateSession(idMQSessionManager *this)
{
  int v2; // r30
  int i; // r11
  idMQSession *v5; // r3
  idMQSession *v6; // r29
  int num; // [sp+50h] [-30h]

  if ( !this->initialized )
    return nullptr;
  v2 = 0;
  num = this->sessionList.num;
  if ( num <= 0 )
    return nullptr;
  for ( i = 0; this->sessionList.list[i] != nullptr; ++i )
  {
    if ( ++v2 >= num )
      return nullptr;
  }
  v5 = (idMQSession *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 0x50u,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idMQSession::idMQSession(this: v5, _channelNumber: v2 + 1, _connection: this->connection);
  else
    v6 = nullptr;
  this->sessionList.list[v2] = v6;
  idMQSession::Init(this: v6, ignoreChannelOpen: false);
  return v6;
}


// ========================================================================
// __unwind$117658
// EA  : 0x82F4F198
// RVA : 0x00F4F198
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

void __fastcall _unwind_117658(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ??0idMQSessionManager@@QAA@PAVidMQConnection@@@Z
// EA  : 0x82F4F1C0
// RVA : 0x00F4F1C0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

idMQSessionManager *__fastcall idMQSessionManager::idMQSessionManager(
        idMQSessionManager *this,
        idMQConnection *_connection)
{
  this->connection = _connection;
  this->initialized = false;
  this->maxSessions = 0;
  this->sessionList.list = nullptr;
  this->sessionList.granularity = 0;
  this->sessionList.memTag = 5;
  this->sessionList.listStatic = 0;
  this->sessionList.size = 0;
  this->sessionList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sessionList);
  return this;
}


// ========================================================================
// ?Init@idMQSessionManager@@QAAXH@Z
// EA  : 0x82F4F220
// RVA : 0x00F4F220
// PDB : w:\tech5\shared\idlib\networking\amqp\mqsession.cpp
// ========================================================================

void __fastcall idMQSessionManager::Init(idMQSessionManager *this, int _maxSessions)
{
  idList<idMQSession *,5> *p_sessionList; // r30
  int v4; // r11
  int v5; // r10

  if ( !this->initialized )
  {
    if ( _maxSessions <= 0 )
      _maxSessions = 16;
    this->maxSessions = _maxSessions;
    p_sessionList = &this->sessionList;
    idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->sessionList, newNum: _maxSessions);
    v4 = 0;
    if ( this->sessionList.num > 0 )
    {
      v5 = 0;
      do
      {
        ++v4;
        p_sessionList->list[v5++] = nullptr;
      }
      while ( v4 < this->sessionList.num );
    }
    this->initialized = true;
  }
}

