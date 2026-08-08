
// ========================================================================
// ?StopMessageSystem@idMQGraphiteClient@@UAAXXZ
// EA  : 0x82EF4B30
// RVA : 0x00EF4B30
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void __fastcall idMQGraphiteClient::StopMessageSystem(idAnalysisClient *this)
{
  idMQClientThread::StopThread(this, waitForStop: true);
}


// ========================================================================
// ?OnThreadTerminate@idAnalysisClient@@EAAXXZ
// EA  : 0x82EF4B38
// RVA : 0x00EF4B38
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void __fastcall idAnalysisClient::OnThreadTerminate(idAnalysisClient *this)
{
  idLib::Printf(fmt: "idAnalysisClient::OnThreadTerminate \n");
}


// ========================================================================
// ??1idAnalysisClient@@UAA@XZ
// EA  : 0x82EF50B0
// RVA : 0x00EF50B0
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void __fastcall idAnalysisClient::~idAnalysisClient(idAnalysisClient *this)
{
  this->__vftable = (idAnalysisClient_vtbl *)&idAnalysisClient::`vftable';
  idMQClientThread::StopThread(this, waitForStop: true);
  Sys_MutexDestroy(handle: &this->viewNoteMutex.handle);
  Sys_MutexDestroy(handle: &this->mapLoadMutex.handle);
  Sys_MutexDestroy(handle: &this->assertMutex.handle);
  idStr::FreeData(this: &this->currentMap);
  idMQClientThread::~idMQClientThread(this);
}


// ========================================================================
// __unwind$159910
// EA  : 0x82EF5124
// RVA : 0x00EF5124
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_159910()
{
  int v0; // r12

  idMQClientThread::~idMQClientThread(this: *(idMQClientThread **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$159911
// EA  : 0x82EF514C
// RVA : 0x00EF514C
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_159911()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 80));
}


// ========================================================================
// __unwind$159912
// EA  : 0x82EF5178
// RVA : 0x00EF5178
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_159912()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 1136));
}


// ========================================================================
// __unwind$159913
// EA  : 0x82EF51A4
// RVA : 0x00EF51A4
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_159913()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 1140));
}


// ========================================================================
// __unwind$159914
// EA  : 0x82EF51D0
// RVA : 0x00EF51D0
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_159914()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 1144));
}


// ========================================================================
// ?StartMessageSystem@idAnalysisClient@@UAAXXZ
// EA  : 0x82EF5200
// RVA : 0x00EF5200
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void __fastcall idAnalysisClient::StartMessageSystem(idAnalysisClient *this)
{
  if ( mq_enable.valueInteger != 0 )
    idMQClientThread::StartThread(this, threadName: "AMQP idAnalysisClient >> Server");
}


// ========================================================================
// ??0idAnalysisClient@@QAA@XZ
// EA  : 0x82EF5380
// RVA : 0x00EF5380
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

idAnalysisClient *__fastcall idAnalysisClient::idAnalysisClient(idAnalysisClient *this)
{
  idMQClientThread::idMQClientThread(this);
  this->reportTime = 0;
  this->__vftable = (idAnalysisClient_vtbl *)&idAnalysisClient::`vftable';
  this->currentMap.allocedAndFlag = 20;
  this->currentMap.baseBuffer[0] = 0;
  this->currentMap.data = this->currentMap.buffer;
  this->currentMap.buffer[0] = 0;
  this->currentMap.len = 0;
  this->currentMap.allocedAndFlag = -2147482624;
  Sys_MutexCreate(handle: &this->assertMutex.handle);
  Sys_MutexCreate(handle: &this->mapLoadMutex.handle);
  Sys_MutexCreate(handle: &this->viewNoteMutex.handle);
  return this;
}


// ========================================================================
// __unwind$160532
// EA  : 0x82EF5418
// RVA : 0x00EF5418
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_160532()
{
  int v0; // r12

  idMQClientThread::~idMQClientThread(this: *(idMQClientThread **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$160533
// EA  : 0x82EF5440
// RVA : 0x00EF5440
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_160533()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 80));
}


// ========================================================================
// __unwind$160534
// EA  : 0x82EF546C
// RVA : 0x00EF546C
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_160534()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 1136));
}


// ========================================================================
// __unwind$160535
// EA  : 0x82EF5498
// RVA : 0x00EF5498
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_160535()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 1140));
}


// ========================================================================
// ?SetCurrentMap@idAnalysisClient@@QAAXPBD@Z
// EA  : 0x82EF5528
// RVA : 0x00EF5528
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void __fastcall idAnalysisClient::SetCurrentMap(idAnalysisClient *this, const char *mapName)
{
  char *data; // r4
  size_t v4; // r5
  char *v5; // r3
  idStrStatic<1024> v6; // [sp+50h] [-430h] BYREF

  idStrStatic<1024>::idStrStatic<1024>(this: &v6, text: mapName);
  data = v6.data;
  v4 = v6.len + 1;
  v5 = this->currentMap.data;
  this->currentMap.len = v6.len;
  memcpy(Dst: v5, Src: data, Size: v4);
  idStr::FreeData(this: &v6);
}


// ========================================================================
// ?PreRun@idAnalysisClient@@EAAXXZ
// EA  : 0x82EF5580
// RVA : 0x00EF5580
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void __fastcall idAnalysisClient::PreRun(idAnalysisClient *this)
{
  int valueInteger; // r29
  idStr v3; // [sp+50h] [-60h] BYREF
  idStr v4[2]; // [sp+70h] [-40h] BYREF

  this->channel = idMQConnection::GetChannel(this: &this->connection);
  idStr::idStr(this: v4, text: "topic");
  idStr::idStr(this: &v3, text: "idtech5");
  idMQChannel::ExchangeDeclare(this: this->channel, exchange: &v3, type: v4, durable: true, autoDelete: false);
  idStr::FreeData(this: &v3);
  idStr::FreeData(this: v4);
  valueInteger = mq_analysisReportRate.valueInteger;
  this->reportTime = Sys_Milliseconds() + 1000 * valueInteger;
}


// ========================================================================
// __unwind$160669
// EA  : 0x82EF560C
// RVA : 0x00EF560C
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_160669()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$160670
// EA  : 0x82EF5634
// RVA : 0x00EF5634
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_160670()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?PublishEvent@@YAXAAVLogEvent@idreports@@PBDW4LogEvent_Severity@2@1AAVMessageLite@protobuf@google@@1PAVidMQChannel@@1@Z
// EA  : 0x82EF6520
// RVA : 0x00EF6520
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void __fastcall PublishEvent(
        idreports::LogEvent *logEvent,
        const char *timestamp,
        int severity,
        const char *message,
        google::protobuf::MessageLite *outgoing,
        const char *messageType,
        idMQChannel *channel,
        const char *routingKey)
{
  unsigned int v16; // r8
  signed int v17; // r3
  idDynamicBlock<unsigned char,6> *v18; // r27
  size_t v19; // r3
  int v20; // r3
  size_t v21; // r3
  signed int v22; // r3
  idDynamicBlock<unsigned char,6> *v23; // r28
  size_t v24; // r3
  int v25; // r3
  unsigned int v26; // r3
  int numFrees; // r11
  idStr v28; // [sp+60h] [-90h] BYREF
  idStr v29[3]; // [sp+80h] [-70h] BYREF

  logEvent->Clear(this: logEvent);
  idreports::LogEvent::set_timestamp(this: logEvent, value: timestamp);
  v16 = logEvent->_has_bits_[0];
  logEvent->severity_ = severity;
  logEvent->_has_bits_[0] = v16 | 2;
  idreports::LogEvent::set_message(this: logEvent, value: message);
  idreports::LogEvent::set_datatype(this: logEvent, value: messageType);
  v17 = outgoing->ByteSize(this: outgoing);
  v18 = idDynamicBlockAlloc<unsigned char,102400,16,6>::Alloc(this: &analysisAllocator, num: v17);
  v19 = outgoing->ByteSize(this: outgoing);
  memset(Dst: v18, Val: 0, Size: v19);
  v20 = outgoing->ByteSize(this: outgoing);
  google::protobuf::MessageLite::SerializePartialToArray(this: outgoing, data: v18, size: v20);
  v21 = outgoing->ByteSize(this: outgoing);
  idreports::LogEvent::set_data(this: logEvent, value: (const char *)v18, size: v21);
  v22 = logEvent->ByteSize(this: logEvent);
  v23 = idDynamicBlockAlloc<unsigned char,102400,16,6>::Alloc(this: &analysisAllocator, num: v22);
  v24 = logEvent->ByteSize(this: logEvent);
  memset(Dst: v23, Val: 0, Size: v24);
  v25 = logEvent->ByteSize(this: logEvent);
  google::protobuf::MessageLite::SerializePartialToArray(this: logEvent, data: v23, size: v25);
  if ( channel != nullptr )
  {
    idStr::idStr(this: v29, text: routingKey);
    idStr::idStr(this: &v28, text: "idtech5");
    v26 = logEvent->ByteSize(this: logEvent);
    idMQChannel::BasicPublish(
      this: channel,
      exchange: &v28,
      routingKey: v29,
      mandatory: false,
      immediate: false,
      data: v23,
      size: v26);
    idStr::FreeData(this: &v28);
    idStr::FreeData(this: v29);
  }
  numFrees = ++analysisAllocator.numFrees;
  if ( v23 != nullptr )
  {
    --analysisAllocator.numUsedBlocks;
    analysisAllocator.usedBlockMemory -= abs32(v23[-1].size);
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      this: (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)&analysisAllocator,
      block: (idDynamicBlock<unsigned char,60> *)&v23[-1]);
    numFrees = analysisAllocator.numFrees;
  }
  analysisAllocator.numFrees = numFrees + 1;
  if ( v18 != nullptr )
  {
    --analysisAllocator.numUsedBlocks;
    analysisAllocator.usedBlockMemory -= abs32(v18[-1].size);
    idDynamicBlockAlloc<unsigned char,1048576,16,60>::FreeInternal(
      this: (idDynamicBlockAlloc<unsigned char,1048576,16,60> *)&analysisAllocator,
      block: (idDynamicBlock<unsigned char,60> *)&v18[-1]);
  }
  logEvent->Clear(this: logEvent);
}


// ========================================================================
// __unwind$167075
// EA  : 0x82EF67B4
// RVA : 0x00EF67B4
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_167075()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$167076
// EA  : 0x82EF67DC
// RVA : 0x00EF67DC
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_167076()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// ?ThreadSlice@idAnalysisClient@@EAAXXZ
// EA  : 0x82EF6810
// RVA : 0x00EF6810
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void __fastcall idAnalysisClient::ThreadSlice(idAnalysisClient *this)
{
  __int64 v2; // r8
  __int64 v3; // r6
  int num; // r29
  assertEvent_t *list; // r22
  __int64 v6; // r10
  idreports::AssertReport *p_message; // r30
  va *v8; // r3
  int v9; // r29
  mapLoadEvent_t *v10; // r23
  __int64 v11; // r10
  std::string **p_username; // r30
  _DWORD *v13; // r11
  __int64 v14; // r6
  va *v15; // r3
  int v16; // r29
  viewNoteEvent_t *v17; // r24
  __int64 v18; // r10
  std::string **v19; // r30
  std::string *Ptr; // r11
  __int64 v21; // r6
  va *v22; // r3
  int valueInteger; // r30
  int size; // r30
  idreports::ViewNoteReport *v25; // r29
  int v26; // r30
  idreports::MapReport *v27; // r29
  int v28; // r30
  idreports::AssertReport *v29; // r29
  int v30; // [sp+8h] [-1158h]
  int v31; // [sp+Ch] [-1154h]
  int v32; // [sp+10h] [-1150h]
  int v33; // [sp+14h] [-114Ch]
  int v34; // [sp+18h] [-1148h]
  int v35; // [sp+1Ch] [-1144h]
  idList<mapLoadEvent_t,5> v36; // [sp+60h] [-1100h] BYREF
  idList<assertEvent_t,5> v37; // [sp+70h] [-10F0h] BYREF
  idList<viewNoteEvent_t,5> v38; // [sp+80h] [-10E0h] BYREF
  idreports::LogEvent v39; // [sp+90h] [-10D0h] BYREF
  va v40; // [sp+100h] [-1060h] BYREF

  if ( this->reportTime < (signed int)Sys_Milliseconds() )
  {
    *(_WORD *)&v37.memTag = 1280;
    memset(&v37, 0, 14);
    *(_WORD *)&v36.memTag = 1280;
    memset(&v36, 0, 14);
    *(_WORD *)&v38.memTag = 1280;
    memset(&v38, 0, 14);
    Sys_MutexLock(handle: &this->assertMutex.handle, blocking: true);
    idList<assertEvent_t,5>::operator=(this: &v37, other: &outgoingAsserts);
    idList<assertEvent_t,5>::Clear(this: &outgoingAsserts);
    Sys_MutexUnlock(handle: &this->assertMutex.handle);
    Sys_MutexLock(handle: &this->mapLoadMutex.handle, blocking: true);
    idList<mapLoadEvent_t,5>::operator=(this: &v36, other: &outgoingMapLoads);
    idList<mapLoadEvent_t,5>::Clear(this: &outgoingMapLoads);
    Sys_MutexUnlock(handle: &this->mapLoadMutex.handle);
    Sys_MutexLock(handle: &this->viewNoteMutex.handle, blocking: true);
    idList<viewNoteEvent_t,5>::operator=(this: &v38, other: &outgoingViewNotes);
    idList<viewNoteEvent_t,5>::Clear(this: &outgoingViewNotes);
    Sys_MutexUnlock(handle: &this->viewNoteMutex.handle);
    idreports::LogEvent::LogEvent(this: &v39);
    list = v37.list;
    num = v37.num;
    if ( v37.num > 0 )
    {
      LODWORD(v6) = &unk_82380000;
      HIDWORD(v6) = &unk_82380000;
      p_message = &v37.list->message;
      do
      {
        HIDWORD(v3) = p_message->mapname_;
        if ( *(_DWORD *)(HIDWORD(v3) + 20) >= 0x10u )
          HIDWORD(v3) = *(_DWORD *)HIDWORD(v3);
        v8 = va::va(
               this: &v40,
               fmt: "Hit an assert in %s",
               a3: v3,
               a4: v2,
               a5: v6,
               a6: v30,
               a7: v31,
               a8: v32,
               a9: v33,
               a10: v34,
               a11: v35);
        PublishEvent(
          logEvent: &v39,
          timestamp: (const char *)p_message[-1]._has_bits_[0],
          severity: 50,
          message: v8->buffer,
          outgoing: p_message,
          messageType: "AssertReport",
          channel: this->channel,
          routingKey: "idtech5.events.assert_report");
        --num;
        p_message = (idreports::AssertReport *)((char *)p_message + 36);
      }
      while ( num != 0 );
    }
    v9 = v36.num;
    v10 = v36.list;
    if ( v36.num > 0 )
    {
      HIDWORD(v11) = &unk_82380000;
      p_username = &v36.list->message.username_;
      do
      {
        v13 = *(p_username - 1);
        if ( v13[5] >= 0x10u )
          v13 = (_DWORD *)*v13;
        HIDWORD(v14) = *p_username;
        LODWORD(v11) = (*p_username)->_Myres;
        if ( (unsigned int)v11 >= 0x10 )
          HIDWORD(v14) = *(_DWORD *)HIDWORD(v14);
        LODWORD(v14) = v13;
        v15 = va::va(
                this: &v40,
                fmt: "%s loaded the map %s",
                a3: v14,
                a4: v2,
                a5: v11,
                a6: v30,
                a7: v31,
                a8: v32,
                a9: v33,
                a10: v34,
                a11: v35);
        PublishEvent(
          logEvent: &v39,
          timestamp: (*(p_username - 3))->_Bx._Buf,
          severity: 40,
          message: v15->buffer,
          outgoing: (google::protobuf::MessageLite *)p_username - 2,
          messageType: "MapReport",
          channel: this->channel,
          routingKey: "idtech5.events.map_load");
        --v9;
        p_username += 20;
      }
      while ( v9 != 0 );
    }
    v16 = v38.num;
    v17 = v38.list;
    if ( v38.num > 0 )
    {
      HIDWORD(v18) = &unk_82380000;
      v19 = &v38.list->message.username_;
      do
      {
        Ptr = v19[14];
        if ( Ptr->_Myres >= 0x10 )
          Ptr = (std::string *)Ptr->_Bx._Ptr;
        HIDWORD(v21) = *v19;
        LODWORD(v18) = (*v19)->_Myres;
        if ( (unsigned int)v18 >= 0x10 )
          HIDWORD(v21) = *(_DWORD *)HIDWORD(v21);
        LODWORD(v21) = Ptr;
        v22 = va::va(
                this: &v40,
                fmt: "%s published a viewnote for %s",
                a3: v21,
                a4: v2,
                a5: v18,
                a6: v30,
                a7: v31,
                a8: v32,
                a9: v33,
                a10: v34,
                a11: v35);
        PublishEvent(
          logEvent: &v39,
          timestamp: (*(v19 - 3))->_Bx._Buf,
          severity: 20,
          message: v22->buffer,
          outgoing: (google::protobuf::MessageLite *)v19 - 2,
          messageType: "ViewNoteReport",
          channel: this->channel,
          routingKey: "idtech5.events.viewnote");
        --v16;
        v19 += 23;
      }
      while ( v16 != 0 );
    }
    valueInteger = mq_analysisReportRate.valueInteger;
    this->reportTime = Sys_Milliseconds() + 1000 * valueInteger;
    idreports::LogEvent::~LogEvent(this: &v39);
    if ( (v38.listStatic == 0 || v38.listStatic == 2) && v17 != nullptr )
    {
      size = v38.size;
      if ( v38.size > 0 )
      {
        v25 = &v17->message;
        do
        {
          idreports::ViewNoteReport::~ViewNoteReport(this: v25);
          --size;
          v25 = (idreports::ViewNoteReport *)((char *)v25 + 92);
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
    }
    if ( (v36.listStatic == 0 || v36.listStatic == 2) && v10 != nullptr )
    {
      v26 = v36.size;
      if ( v36.size > 0 )
      {
        v27 = &v10->message;
        do
        {
          idreports::MapReport::~MapReport(this: v27);
          --v26;
          v27 = (idreports::MapReport *)((char *)v27 + 80);
        }
        while ( v26 != 0 );
      }
      idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    }
    if ( (v37.listStatic == 0 || v37.listStatic == 2) && list != nullptr )
    {
      v28 = v37.size;
      if ( v37.size > 0 )
      {
        v29 = &list->message;
        do
        {
          idreports::AssertReport::~AssertReport(this: v29);
          --v28;
          v29 = (idreports::AssertReport *)((char *)v29 + 36);
        }
        while ( v28 != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
  }
  mgthread_sleep(ms: 250);
}


// ========================================================================
// __unwind$167153
// EA  : 0x82EF6C08
// RVA : 0x00EF6C08
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_167153()
{
  int v0; // r12

  idList<assertEvent_t,5>::Clear(this: (idList<assertEvent_t,5> *)(v0 - 4448 + 112));
}


// ========================================================================
// __unwind$167154
// EA  : 0x82EF6C30
// RVA : 0x00EF6C30
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_167154()
{
  int v0; // r12

  idList<mapLoadEvent_t,5>::Clear(this: (idList<mapLoadEvent_t,5> *)(v0 - 4448 + 96));
}


// ========================================================================
// __unwind$167155
// EA  : 0x82EF6C58
// RVA : 0x00EF6C58
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_167155()
{
  int v0; // r12

  idList<viewNoteEvent_t,5>::Clear(this: (idList<viewNoteEvent_t,5> *)(v0 - 4448 + 128));
}


// ========================================================================
// __unwind$167156
// EA  : 0x82EF6C80
// RVA : 0x00EF6C80
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_167156()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 4448 + 80));
}


// ========================================================================
// __unwind$167157
// EA  : 0x82EF6CA8
// RVA : 0x00EF6CA8
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_167157()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 4448 + 80));
}


// ========================================================================
// __unwind$167158
// EA  : 0x82EF6CD0
// RVA : 0x00EF6CD0
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_167158()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 4448 + 80));
}


// ========================================================================
// __unwind$167159
// EA  : 0x82EF6CF8
// RVA : 0x00EF6CF8
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_167159()
{
  int v0; // r12

  idreports::LogEvent::~LogEvent(this: (idreports::LogEvent *)(v0 - 4448 + 144));
}


// ========================================================================
// `dynamic initializer for 'mq_analysisReportRate''
// EA  : 0x83393F08
// RVA : 0x01393F08
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mq_analysisReportRate__()
{
  idCVar::idCVar(
    this: &mq_analysisReportRate,
    name: "mq_analysisReportRate",
    value: "1",
    flags: 2,
    description: "Control the rate at which asserts and map stats get reported.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mq_analysisReportRate__);
}


// ========================================================================
// `dynamic initializer for 'mq_enable''
// EA  : 0x83393F60
// RVA : 0x01393F60
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mq_enable__()
{
  idCVar::idCVar(
    this: &mq_enable,
    name: "mq_enable",
    value: "0",
    flags: 1,
    description: "Enables the analysis client",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mq_enable__);
}


// ========================================================================
// `dynamic initializer for 'analysisClient''
// EA  : 0x83393FB8
// RVA : 0x01393FB8
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__analysisClient__()
{
  idAnalysisClient::idAnalysisClient(this: &analysisClient);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__analysisClient__);
}


// ========================================================================
// `dynamic initializer for 'analysisAllocator''
// EA  : 0x83393FF0
// RVA : 0x01393FF0
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__analysisAllocator__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__analysisAllocator__);
}


// ========================================================================
// `dynamic initializer for 'outgoingAsserts''
// EA  : 0x83394008
// RVA : 0x01394008
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__outgoingAsserts__()
{
  `eh vector constructor iterator'(
    ptr: (char *)outgoingAsserts.staticList,
    size: 0x24u,
    count: 50,
    pCtor: (void (__fastcall *)(void *))assertEvent_t::assertEvent_t,
    pDtor: (void (__fastcall *)(void *))assertEvent_t::~assertEvent_t);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__outgoingAsserts__);
}


// ========================================================================
// __unwind$167740
// EA  : 0x83394064
// RVA : 0x01394064
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_167740()
{
  idList<assertEvent_t,5>::Clear(this: &outgoingAsserts);
}


// ========================================================================
// `dynamic initializer for 'outgoingMapLoads''
// EA  : 0x83394098
// RVA : 0x01394098
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__outgoingMapLoads__()
{
  `eh vector constructor iterator'(
    ptr: (char *)outgoingMapLoads.staticList,
    size: 0x50u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))mapLoadEvent_t::mapLoadEvent_t,
    pDtor: (void (__fastcall *)(void *))mapLoadEvent_t::~mapLoadEvent_t);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__outgoingMapLoads__);
}


// ========================================================================
// __unwind$167765
// EA  : 0x833940F4
// RVA : 0x013940F4
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_167765()
{
  idList<mapLoadEvent_t,5>::Clear(this: &outgoingMapLoads);
}


// ========================================================================
// `dynamic initializer for 'outgoingViewNotes''
// EA  : 0x83394128
// RVA : 0x01394128
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__outgoingViewNotes__()
{
  `eh vector constructor iterator'(
    ptr: (char *)outgoingViewNotes.staticList,
    size: 0x5Cu,
    count: 2,
    pCtor: (void (__fastcall *)(void *))viewNoteEvent_t::viewNoteEvent_t,
    pDtor: (void (__fastcall *)(void *))viewNoteEvent_t::~viewNoteEvent_t);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__outgoingViewNotes__);
}


// ========================================================================
// __unwind$167790
// EA  : 0x83394184
// RVA : 0x01394184
// PDB : w:\tech5\shared\idlib\analysisclient.cpp
// ========================================================================

void _unwind_167790()
{
  idList<viewNoteEvent_t,5>::Clear(this: &outgoingViewNotes);
}

