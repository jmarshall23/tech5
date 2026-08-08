
// ========================================================================
// ?StartMessageSystem@idMQGraphiteClient@@UAAXXZ
// EA  : 0x82F3FC00
// RVA : 0x00F3FC00
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void __fastcall idMQGraphiteClient::StartMessageSystem(idMQGraphiteClient *this)
{
  idMQClientThread::StartThread(this, threadName: "AMQP Client >> Server");
}


// ========================================================================
// ?OnThreadTerminate@idMQGraphiteClient@@EAAXXZ
// EA  : 0x82F3FC10
// RVA : 0x00F3FC10
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMQGraphiteClient::OnThreadTerminate(
        idMQGraphiteClient *this,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  __int64 v9; // r4

  HIDWORD(v9) = "idMQGraphiteClient::OnThreadTerminate \n";
  idLib::Printf(fmt: v9, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
}


// ========================================================================
// ?TestMQBitBuffer_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F3FC28
// RVA : 0x00F3FC28
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void __fastcall TestMQBitBuffer_f(const idCmdArgs *args)
{
  __int64 v1; // r4
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  bool v5; // r29
  int i; // r30
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r4
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  int j; // r30
  __int64 v15; // r4
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  __int64 v22; // r4
  int v23; // [sp+8h] [-A8h]
  int v24; // [sp+8h] [-A8h]
  int v25; // [sp+8h] [-A8h]
  int v26; // [sp+Ch] [-A4h]
  int v27; // [sp+Ch] [-A4h]
  int v28; // [sp+Ch] [-A4h]
  int v29; // [sp+10h] [-A0h]
  int v30; // [sp+10h] [-A0h]
  int v31; // [sp+10h] [-A0h]
  int v32; // [sp+14h] [-9Ch]
  int v33; // [sp+14h] [-9Ch]
  int v34; // [sp+14h] [-9Ch]
  idMQFrame v35[2]; // [sp+50h] [-60h] BYREF

  idMQFrame::idMQFrame(this: v35);
  HIDWORD(v1) = "------------\nStarting Writes\n------------\n";
  idLib::Printf(fmt: v1, a2: v4, a3: v3, a4: v2, a5: v23, a6: v26, a7: v29, a8: v32);
  v5 = true;
  for ( i = 16; i != 0; --i )
  {
    idMQFrame::WriteBool(this: v35, value: v5);
    idLib::Printf(fmt: __SPAIR64__("<< %d\n", v5), a2: v9, a3: v8, a4: v7, a5: v24, a6: v27, a7: v30, a8: v33);
    v5 = (_cntlzw(v5) & 0x20) != 0;
  }
  idMQFrame::FlushWriteBitBuffer(this: v35);
  HIDWORD(v10) = "------------\nStarting Reads\n------------\n";
  idLib::Printf(fmt: v10, a2: v13, a3: v12, a4: v11, a5: v24, a6: v27, a7: v30, a8: v33);
  for ( j = 16; j != 0; --j )
  {
    LODWORD(v15) = idMQFrame::ReadBool(this: v35);
    HIDWORD(v15) = ">> %d\n";
    idLib::Printf(fmt: v15, a2: v18, a3: v17, a4: v16, a5: v25, a6: v28, a7: v31, a8: v34);
  }
  HIDWORD(v22) = "Done\n";
  idLib::Printf(fmt: v22, a2: v21, a3: v20, a4: v19, a5: v25, a6: v28, a7: v31, a8: v34);
  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)v35);
}


// ========================================================================
// __unwind$117526
// EA  : 0x82F3FCE4
// RVA : 0x00F3FCE4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_117526()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 176 + 80));
}


// ========================================================================
// ?TestMQPresenceBuffer_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F3FD18
// RVA : 0x00F3FD18
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void __fastcall TestMQPresenceBuffer_f(const idCmdArgs *args)
{
  __int64 v1; // r4
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  bool v5; // r29
  int i; // r30
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r4
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  int j; // r30
  __int64 v15; // r4
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  __int64 v19; // r4
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  int v23; // [sp+8h] [-A8h]
  int v24; // [sp+8h] [-A8h]
  int v25; // [sp+8h] [-A8h]
  int v26; // [sp+Ch] [-A4h]
  int v27; // [sp+Ch] [-A4h]
  int v28; // [sp+Ch] [-A4h]
  int v29; // [sp+10h] [-A0h]
  int v30; // [sp+10h] [-A0h]
  int v31; // [sp+10h] [-A0h]
  int v32; // [sp+14h] [-9Ch]
  int v33; // [sp+14h] [-9Ch]
  int v34; // [sp+14h] [-9Ch]
  idMQFrame v35[2]; // [sp+50h] [-60h] BYREF

  idMQFrame::idMQFrame(this: v35);
  HIDWORD(v1) = "------------\nStarting Writes\n------------\n";
  idLib::Printf(fmt: v1, a2: v4, a3: v3, a4: v2, a5: v23, a6: v26, a7: v29, a8: v32);
  v5 = true;
  for ( i = 25; i != 0; --i )
  {
    idMQFrame::WritePropertyPresence(this: v35, exists: v5);
    idLib::Printf(fmt: __SPAIR64__("<< %d\n", v5), a2: v9, a3: v8, a4: v7, a5: v24, a6: v27, a7: v30, a8: v33);
    v5 = (_cntlzw(v5) & 0x20) != 0;
  }
  idMQFrame::FinalizeWritePresence(this: v35);
  HIDWORD(v10) = "------------\nStarting Reads\n------------\n";
  idLib::Printf(fmt: v10, a2: v13, a3: v12, a4: v11, a5: v24, a6: v27, a7: v30, a8: v33);
  for ( j = 25; j != 0; --j )
  {
    LODWORD(v15) = idMQFrame::ReadPropertyPresence(this: v35);
    HIDWORD(v15) = ">> %d\n";
    idLib::Printf(fmt: v15, a2: v18, a3: v17, a4: v16, a5: v25, a6: v28, a7: v31, a8: v34);
  }
  idMQFrame::FinalizeReadPresence(this: v35);
  HIDWORD(v19) = "Done\n";
  idLib::Printf(fmt: v19, a2: v22, a3: v21, a4: v20, a5: v25, a6: v28, a7: v31, a8: v34);
  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)v35);
}


// ========================================================================
// __unwind$117551
// EA  : 0x82F3FDDC
// RVA : 0x00F3FDDC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_117551()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 176 + 80));
}


// ========================================================================
// ?PreRun@idMQGraphiteClient@@EAAXXZ
// EA  : 0x82F3FF30
// RVA : 0x00F3FF30
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void __fastcall idMQGraphiteClient::PreRun(idMQGraphiteClient *this)
{
  int valueInteger; // r29
  idStr v3[2]; // [sp+50h] [-40h] BYREF

  this->channel = idMQConnection::GetChannel(this: &this->connection);
  idStr::idStr(this: v3, text: "topic");
  idMQChannel::ExchangeDeclare(
    this: this->channel,
    exchange: &this->exchange,
    type: v3,
    durable: true,
    autoDelete: false);
  idStr::FreeData(this: v3);
  valueInteger = mq_graphiteReportRate.valueInteger;
  this->reportTime = Sys_Milliseconds() + 1000 * valueInteger;
}


// ========================================================================
// __unwind$117936
// EA  : 0x82F3FFA4
// RVA : 0x00F3FFA4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_117936()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ??0idMQGraphiteClient@@QAA@ABVidStr@@0@Z
// EA  : 0x82F3FFD8
// RVA : 0x00F3FFD8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

idMQGraphiteClient *__fastcall idMQGraphiteClient::idMQGraphiteClient(
        idMQGraphiteClient *this,
        const idStr *_exchange,
        const idStr *_prefix)
{
  idMQClientThread::idMQClientThread(this);
  this->reportTime = 0;
  this->__vftable = (idMQGraphiteClient_vtbl *)&idMQGraphiteClient::`vftable';
  this->channel = nullptr;
  this->outgoingEvents.list = nullptr;
  this->outgoingEvents.granularity = 0;
  this->outgoingEvents.memTag = 5;
  this->outgoingEvents.listStatic = 0;
  this->outgoingEvents.size = 0;
  this->outgoingEvents.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->outgoingEvents);
  idStr::idStr(this: &this->exchange, text: _exchange);
  idStr::idStr(this: &this->prefix, text: _prefix);
  Sys_MutexCreate(handle: &this->threadMutex.handle);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->outgoingEvents);
  return this;
}


// ========================================================================
// __unwind$117975
// EA  : 0x82F40074
// RVA : 0x00F40074
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_117975()
{
  int v0; // r12

  idMQClientThread::~idMQClientThread(this: *(idMQClientThread **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$117976
// EA  : 0x82F4009C
// RVA : 0x00F4009C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_117976()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 80));
}


// ========================================================================
// __unwind$117977
// EA  : 0x82F400C8
// RVA : 0x00F400C8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_117977()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 96));
}


// ========================================================================
// __unwind$117978
// EA  : 0x82F400F4
// RVA : 0x00F400F4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_117978()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 128));
}


// ========================================================================
// __unwind$117979
// EA  : 0x82F40120
// RVA : 0x00F40120
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_117979()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 144 + 164) + 160));
}


// ========================================================================
// ??1idMQGraphiteClient@@UAA@XZ
// EA  : 0x82F40158
// RVA : 0x00F40158
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void __fastcall idMQGraphiteClient::~idMQGraphiteClient(idMQGraphiteClient *this)
{
  this->__vftable = (idMQGraphiteClient_vtbl *)&idMQGraphiteClient::`vftable';
  idMQClientThread::StopThread(this, waitForStop: true);
  Sys_MutexDestroy(handle: &this->threadMutex.handle);
  idStr::FreeData(this: &this->prefix);
  idStr::FreeData(this: &this->exchange);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->outgoingEvents);
  idMQClientThread::~idMQClientThread(this);
}


// ========================================================================
// __unwind$118024
// EA  : 0x82F401CC
// RVA : 0x00F401CC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_118024()
{
  int v0; // r12

  idMQClientThread::~idMQClientThread(this: *(idMQClientThread **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$118025
// EA  : 0x82F401F4
// RVA : 0x00F401F4
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_118025()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 80));
}


// ========================================================================
// __unwind$118026
// EA  : 0x82F40220
// RVA : 0x00F40220
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_118026()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 96));
}


// ========================================================================
// __unwind$118027
// EA  : 0x82F4024C
// RVA : 0x00F4024C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_118027()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 128));
}


// ========================================================================
// __unwind$118028
// EA  : 0x82F40278
// RVA : 0x00F40278
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_118028()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 160));
}


// ========================================================================
// ?ThreadSlice@idMQGraphiteClient@@EAAXXZ
// EA  : 0x82F402B0
// RVA : 0x00F402B0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void __fastcall idMQGraphiteClient::ThreadSlice(idMQGraphiteClient *this)
{
  int v2; // r22
  int *p_count; // r25
  int num; // r14
  __int64 v5; // r10
  double v6; // fp31
  double v7; // fp30
  double v8; // fp10
  double v9; // fp29
  __int64 v10; // r10
  __int64 v11; // r4
  __int64 v12; // r8
  __int64 v13; // r6
  __int64 v14; // r10
  int v15; // r27
  __int64 v16; // r8
  __int64 v17; // r6
  va *v18; // r3
  va *v19; // r29
  size_t i; // r30
  int v21; // r4
  int v22; // r11
  __int64 v23; // r10
  __int64 v24; // r8
  __int64 v25; // r6
  __int64 v26; // r8
  __int64 v27; // r6
  __int64 v28; // r4
  int valueInteger; // r30
  int v30; // [sp+8h] [-1178h]
  int v31; // [sp+8h] [-1178h]
  int v32; // [sp+8h] [-1178h]
  int v33; // [sp+Ch] [-1174h]
  int v34; // [sp+Ch] [-1174h]
  int v35; // [sp+Ch] [-1174h]
  int v36; // [sp+10h] [-1170h]
  int v37; // [sp+10h] [-1170h]
  int v38; // [sp+10h] [-1170h]
  int v39; // [sp+14h] [-116Ch]
  int v40; // [sp+14h] [-116Ch]
  int v41; // [sp+14h] [-116Ch]
  int v42; // [sp+18h] [-1168h]
  int v43; // [sp+1Ch] [-1164h]
  double v44; // [sp+38h] [-1148h]
  idList<idMQGraphiteClient::graphiteEvent_t,5> v45; // [sp+50h] [-1130h] BYREF
  idStr v46; // [sp+60h] [-1120h] BYREF
  float v47[4]; // [sp+80h] [-1100h] BYREF
  __int64 v48; // [sp+90h] [-10F0h]
  _DWORD v49[6]; // [sp+98h] [-10E8h] BYREF
  idStaticList<idVehicleState *,4> v50; // [sp+B0h] [-10D0h] BYREF
  va v51; // [sp+D0h] [-10B0h] BYREF

  if ( this->reportTime < (signed int)Sys_Milliseconds() )
  {
    memset(&v45, 0, 14);
    *(_WORD *)&v45.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v45);
    HIDWORD(v48) = &this->threadMutex;
    Sys_MutexLock(handle: &this->threadMutex.handle, blocking: true);
    idList<idMQGraphiteClient::graphiteEvent_t,5>::operator=(this: &v45, other: &this->outgoingEvents);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->outgoingEvents);
    Sys_MutexUnlock(handle: &this->threadMutex.handle);
    v2 = (unsigned __int64)time64(timeptr: nullptr) >> 32;
    if ( v45.num > 0 )
    {
      v49[0] = "rate";
      p_count = &v45.list->count;
      v49[1] = "avg";
      num = v45.num;
      v49[2] = "std";
      HIDWORD(v5) = byte_821B0000;
      do
      {
        v6 = *((float *)p_count + 1);
        LODWORD(v5) = *p_count;
        v7 = *((float *)p_count + 2);
        v8 = (float)(*((float *)p_count + 3) / (float)v5);
        v48 = v5;
        v9 = __fsqrts(v8);
        idMQBuffer::idMQBuffer(this: (idAttachmentCollection *)&v50);
        HIDWORD(v10) = v46.baseBuffer;
        v46.allocedAndFlag = 20;
        v46.len = 0;
        v46.data = v46.baseBuffer;
        v46.baseBuffer[0] = 0;
        HIDWORD(v11) = "----------------\n";
        idLib::Printf(fmt: v11, a2: v13, a3: v12, a4: v10, a5: v30, a6: v33, a7: v36, a8: v39);
        v47[0] = v6;
        v47[1] = v7;
        v15 = 0;
        v47[2] = v9;
        do
        {
          v44 = v47[v15];
          LODWORD(v16) = LODWORD(v44);
          LODWORD(v17) = *(p_count - 1);
          HIDWORD(v14) = v2;
          HIDWORD(v17) = this->prefix.data;
          HIDWORD(v16) = v49[v15];
          v18 = va::va(
                  this: &v51,
                  fmt: "%s.%s.%s %g %lld",
                  a3: v17,
                  a4: v16,
                  a5: v14,
                  a6: v31,
                  a7: v34,
                  a8: v37,
                  a9: v40,
                  a10: v42,
                  a11: v43);
          v19 = v18;
          for ( i = 0; v18->buffer[i] != 0; ++i )
            ;
          v21 = i + 1;
          v22 = v46.allocedAndFlag & 0x7FFFFFFF;
          if ( v46.allocedAndFlag >= 0 )
          {
            if ( v21 > v22 )
              idStr::ReAllocate(this: &v46, amount: v21, keepold: false);
          }
          else if ( v21 > v22
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          memcpy(Dst: v46.data, Src: v19, Size: i);
          v46.data[i] = 0;
          v46.len = i;
          idMQBuffer::WriteData(this: (idMQBuffer *)&v50, ptr: v46.data, length: i);
          idMQChannel::BasicPublish(
            this: this->channel,
            exchange: &this->exchange,
            routingKey: &this->prefix,
            body: (const idList<unsigned char,5> *)&v50);
          idLib::Printf(
            fmt: __SPAIR64__("%s\n", (unsigned int)v46.data),
            a2: v25,
            a3: v24,
            a4: v23,
            a5: v32,
            a6: v35,
            a7: v38,
            a8: v41);
          idMQBuffer::Clear(this: (idMQBuffer *)&v50);
          LODWORD(v14) = v46.allocedAndFlag;
          HIDWORD(v14) = (unsigned int)v46.allocedAndFlag >> 31;
          if ( v46.allocedAndFlag >= 0 )
          {
            idStr::FreeData(this: &v46);
            v46.allocedAndFlag = 20;
            v46.data = v46.baseBuffer;
            v46.len = 0;
            v46.baseBuffer[0] = 0;
          }
          else
          {
            v46.len = 0;
            *v46.data = 0;
          }
          ++v15;
        }
        while ( v15 < 3 );
        HIDWORD(v28) = "\n";
        idLib::Printf(fmt: v28, a2: v27, a3: v26, a4: v14, a5: v31, a6: v34, a7: v37, a8: v40);
        idStr::FreeData(this: &v46);
        idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: &v50);
        --num;
        p_count += 5;
      }
      while ( num != 0 );
    }
    valueInteger = mq_graphiteReportRate.valueInteger;
    this->reportTime = Sys_Milliseconds() + 1000 * valueInteger;
    if ( (v45.listStatic == 0 || v45.listStatic == 2) && v45.list != nullptr )
      idMem::Free(this: &mem, ptr: v45.list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$118081
// EA  : 0x82F405F8
// RVA : 0x00F405F8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_118081()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4480 + 80));
}


// ========================================================================
// __unwind$118082
// EA  : 0x82F40620
// RVA : 0x00F40620
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_118082()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 4480 + 144));
}


// ========================================================================
// __unwind$118083
// EA  : 0x82F40648
// RVA : 0x00F40648
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_118083()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 4480 + 176));
}


// ========================================================================
// __unwind$118084
// EA  : 0x82F40670
// RVA : 0x00F40670
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_118084()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 96));
}


// ========================================================================
// ?LogEvent@idMQGraphiteClient@@QAAXABVidStr@@M@Z
// EA  : 0x82F40888
// RVA : 0x00F40888
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void __fastcall idMQGraphiteClient::LogEvent(idMQGraphiteClient *this, const idStr *eventName, double duration)
{
  int v6; // r30
  int v7; // r29
  __int64 v8; // r7
  char *data; // r11
  idMQGraphiteClient::graphiteEvent_t *v10; // r10
  cm_buildMaterial_t v11; // [sp+60h] [-50h] BYREF

  v6 = 0;
  if ( this->outgoingEvents.num <= 0 )
  {
LABEL_5:
    data = eventName->data;
    *(float *)&v11.surfaceType = duration;
    *(float *)&v11.checkCount = duration;
    v11.surfaceFlags = 1;
    *(float *)&v11.index = (float)duration * (float)duration;
    v11.contentFlags = (int)data;
    idList<sourceSurface_t,59>::Append(this: (idList<cm_buildMaterial_t,13> *)&this->outgoingEvents, obj: &v11);
  }
  else
  {
    v7 = 0;
    while ( idStr::Icmp(s1: this->outgoingEvents.list[v7].eventName, s2: eventName->data) != 0 )
    {
      ++v6;
      ++v7;
      if ( v6 >= this->outgoingEvents.num )
        goto LABEL_5;
    }
    this->outgoingEvents.list[v6].duration = (float)duration + this->outgoingEvents.list[v6].duration;
    ++this->outgoingEvents.list[v6].count;
    v10 = &this->outgoingEvents.list[v6];
    LODWORD(v8) = v10->count;
    v10->mean = (float)((float)((float)duration - v10->mean) / (float)v8) + v10->mean;
    this->outgoingEvents.list[v6].mean2 = (float)((float)duration * (float)duration)
                                        + this->outgoingEvents.list[v6].mean2;
  }
}


// ========================================================================
// ?DemoGraphiteMQ_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F409B8
// RVA : 0x00F409B8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall DemoGraphiteMQ_f(const idCmdArgs *args)
{
  unsigned int v1; // r28
  int v2; // r30
  __int64 v3; // r11
  unsigned int v4; // r3
  __int128 v5; // r10
  __int64 v6; // r6 OVERLAPPED
  int v7; // [sp+8h] [-188h]
  int v8; // [sp+Ch] [-184h]
  int v9; // [sp+10h] [-180h]
  int v10; // [sp+14h] [-17Ch]
  idStr v11; // [sp+60h] [-130h] BYREF
  idStr v12; // [sp+80h] [-110h] BYREF
  idStr v13; // [sp+A0h] [-F0h] BYREF
  idMQGraphiteClient v14; // [sp+C0h] [-D0h] BYREF

  v1 = Sys_Milliseconds();
  idStr::idStr(this: &v12, text: "graphite");
  idStr::idStr(this: &v11, text: "host.MOCK01.tech5.sputnik");
  idStr::idStr(this: &v13, text: "launch");
  v2 = 1;
  idMQGraphiteClient::idMQGraphiteClient(this: &v14, _exchange: &v12, _prefix: &v11);
  idMQClientThread::StartThread(this: &v14, threadName: "AMQP Client >> Server");
  while ( (int)Sys_Milliseconds() < (int)(v1 + 60000) )
  {
    LODWORD(v3) = v2;
    idMQGraphiteClient::LogEvent(this: &v14, eventName: &v13, duration: (float)v3);
    ++v2;
    mgthread_sleep(ms: 2000);
  }
  idMQClientThread::StopThread(this: &v14, waitForStop: true);
  v4 = Sys_Milliseconds();
  LODWORD(v5) = &off_82040000;
  DWORD2(v5) = v4 - v1;
  DWORD1(v5) = &unk_82390000;
  idLib::Printf(
    fmt: COERCE__INT64((float)((float)*(__int64 *)((char *)&v5 + 4) * (float)0.001)),
    a2: v6,
    a3: *(__int64 *)&v5,
    a4: v5,
    a5: v7,
    a6: v8,
    a7: v9,
    a8: v10);
  idMQGraphiteClient::~idMQGraphiteClient(this: &v14);
  idStr::FreeData(this: &v13);
  idStr::FreeData(this: &v11);
  idStr::FreeData(this: &v12);
}


// ========================================================================
// __unwind$118420
// EA  : 0x82F40AE0
// RVA : 0x00F40AE0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_118420()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 128));
}


// ========================================================================
// __unwind$118421
// EA  : 0x82F40B08
// RVA : 0x00F40B08
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_118421()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 96));
}


// ========================================================================
// __unwind$118422
// EA  : 0x82F40B30
// RVA : 0x00F40B30
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_118422()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 160));
}


// ========================================================================
// __unwind$118423
// EA  : 0x82F40B58
// RVA : 0x00F40B58
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

void _unwind_118423()
{
  int v0; // r12

  idMQGraphiteClient::~idMQGraphiteClient(this: (idMQGraphiteClient *)(v0 - 400 + 192));
}


// ========================================================================
// `dynamic initializer for 'TestMQBitBuffer_v''
// EA  : 0x83396248
// RVA : 0x01396248
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestMQBitBuffer_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestMQBitBuffer_v,
           cmdName: "TestMQBitBuffer",
           function: TestMQBitBuffer_f,
           description: "Tests AMQP Frame bit buffer writing and reading",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestMQPresenceBuffer_v''
// EA  : 0x83396270
// RVA : 0x01396270
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestMQPresenceBuffer_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestMQPresenceBuffer_v,
           cmdName: "TestMQPresenceBuffer",
           function: TestMQPresenceBuffer_f,
           description: "Tests AMQP Frame property presence buffer writing and reading",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'DemoGraphiteMQ_v''
// EA  : 0x83396298
// RVA : 0x01396298
// PDB : w:\tech5\shared\idlib\networking\amqp\mqclient.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__DemoGraphiteMQ_v__()
{
  return idCommandLink::idCommandLink(
           this: &DemoGraphiteMQ_v,
           cmdName: "DemoGraphiteMQ",
           function: DemoGraphiteMQ_f,
           description: "Demonstrates a simple amqp client which submits a single metric to graphite.",
           argCompletion: nullptr);
}

