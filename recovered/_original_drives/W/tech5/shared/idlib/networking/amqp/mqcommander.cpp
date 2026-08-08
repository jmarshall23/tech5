
// ========================================================================
// ??0idMQCommandBuilder@@QAA@XZ
// EA  : 0x82F40B80
// RVA : 0x00F40B80
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommander.cpp
// ========================================================================

idMQCommandBuilder *__fastcall idMQCommandBuilder::idMQCommandBuilder(idMQCommandBuilder *this)
{
  unsigned __int64 v1; // r11

  LODWORD(v1) = 0;
  this->state = MQ_CMDSTATE_NEED_METHOD;
  this->remainingBytes = v1;
  return this;
}


// ========================================================================
// ?Reset@idMQCommand@@QAAXXZ
// EA  : 0x82F40B90
// RVA : 0x00F40B90
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommander.cpp
// ========================================================================

void __fastcall idMQCommand::Reset(idMQCommand *this)
{
  unsigned __int64 v1; // r30
  idMQMethod *method; // r3
  idMQContentHeader *contentHeader; // r3

  method = this->method;
  LODWORD(v1) = 0;
  this->complete = false;
  if ( method != nullptr )
  {
    ((void (__fastcall *)(idMQMethod *, int))method->dtr_idMQMethod)(a1: method, a2: 1);
    this->method = nullptr;
  }
  contentHeader = this->contentHeader;
  if ( contentHeader != nullptr )
  {
    ((void (__fastcall *)(idMQContentHeader *, int))contentHeader->dtr_idMQContentHeader)(a1: contentHeader, a2: 1);
    this->contentHeader = nullptr;
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contentBody);
  this->remainingBodyBytes = v1;
}


// ========================================================================
// ??0idMQCommand@@QAA@XZ
// EA  : 0x82F40C20
// RVA : 0x00F40C20
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommander.cpp
// ========================================================================

idMQCommand *__fastcall idMQCommand::idMQCommand(idMQCommand *this)
{
  unsigned __int64 v1; // r30

  LODWORD(v1) = 0;
  this->method = nullptr;
  this->contentHeader = nullptr;
  this->complete = false;
  this->contentBody.list = nullptr;
  this->contentBody.granularity = 0;
  this->contentBody.memTag = 5;
  this->contentBody.listStatic = 0;
  this->contentBody.size = 0;
  this->contentBody.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contentBody);
  this->remainingBodyBytes = v1;
  return this;
}


// ========================================================================
// ?HandleFrame@idMQCommandBuilder@@QAA?AW4MQErrors_t@@AAVidMQCommand@@AAVidMQFrame@@@Z
// EA  : 0x82F40DE0
// RVA : 0x00F40DE0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqcommander.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idMQCommandBuilder::HandleFrame(
        idMQCommandBuilder *this,
        idMQCommand *command,
        __int64 frame,
        __int64 a4,
        __int64 a5)
{
  _DWORD *v5; // r3
  int *v6; // r3
  int *v7; // r29
  const char *v9; // r3
  __int64 v11; // r4
  __int64 v12; // r8
  __int64 v13; // r6 OVERLAPPED
  __int64 v14; // r4 OVERLAPPED
  unsigned __int64 v15; // r11 OVERLAPPED
  int v16; // r11
  bool v17; // zf
  __int64 v18; // r4
  idMQContentHeader *v19; // r3
  int v20; // r11
  bool v21; // cr58
  __int64 v22; // r4
  idMQMethod *v23; // r3
  int v24; // [sp+8h] [-68h]
  int v25; // [sp+Ch] [-64h]
  int v26; // [sp+10h] [-60h]
  int v27; // [sp+14h] [-5Ch]

  v7 = v6;
  if ( *v6 != 0 )
  {
    if ( *v5 == 1 )
    {
      LODWORD(v18) = (unsigned __int8)*(_BYTE *)HIDWORD(frame);
      if ( (_DWORD)v18 != 2 )
      {
        HIDWORD(v18) = "ERROR: AMQP: Expected content header frame but got type %d instead.\n";
        idLib::Printf(fmt: v18, a2: frame, a3: a4, a4: a5, a5: v24, a6: v25, a7: v26, a8: v27);
        return 2;
      }
      v19 = idMQChannel::DecodeContentHeader(frame: (idMQFrame *)HIDWORD(frame));
      command->contentHeader = v19;
      v20 = 2;
      if ( LODWORD(v19->bodyLength) == 0 )
        v20 = 3;
      *v7 = v20;
      command->remainingBodyBytes = command->contentHeader->bodyLength;
      v21 = *v7 == 3;
      goto LABEL_20;
    }
    if ( *v5 >= 3u )
    {
      v9 = "ERROR: AMQP: Command builder left in an invalid state.\n";
      idLib::Printf(fmt: *(__int64 *)&command, a2: frame, a3: a4, a4: a5, a5: v24, a6: v25, a7: v26, a8: v27);
      return 1;
    }
    LODWORD(v11) = (unsigned __int8)*(_BYTE *)HIDWORD(frame);
    if ( (_DWORD)v11 != 3 )
    {
      HIDWORD(v11) = "ERROR: AMQP: Expected content body frame but got type %d instead.\n";
      idLib::Printf(fmt: v11, a2: frame, a3: a4, a4: a5, a5: v24, a6: v25, a7: v26, a8: v27);
      return 2;
    }
    idList<unsigned char,5>::Append(
      this: &command->contentBody,
      other: (const idList<unsigned char,5> *)(HIDWORD(frame) + 4));
    *(__int64 *)((char *)&v13 + 4) = command->remainingBodyBytes;
    LODWORD(v15) = HIDWORD(command->remainingBodyBytes);
    if ( (unsigned int)v15 > HIDWORD(v13) )
    {
      HIDWORD(v14) = "ERROR: AMQP: Frame content body size (%d) is larger than the expected amount (%lld).\n";
      idLib::Printf(
        fmt: v14,
        a2: v13,
        a3: v12,
        a4: *(unsigned __int64 *)((char *)&v15 + 4),
        a5: v24,
        a6: v25,
        a7: v26,
        a8: v27);
      return 3;
    }
    LODWORD(v15) = HIDWORD(v13) - v15;
    command->remainingBodyBytes = v15;
    v17 = (_DWORD)v15 != 0;
    v16 = 2;
    if ( !v17 )
      v16 = 3;
  }
  else
  {
    LODWORD(v22) = (unsigned __int8)*(_BYTE *)HIDWORD(frame);
    if ( (_DWORD)v22 != 1 )
    {
      HIDWORD(v22) = "ERROR: AMQP: Expected method frame but got type %d instead.\n";
      idLib::Printf(fmt: v22, a2: frame, a3: a4, a4: a5, a5: v24, a6: v25, a7: v26, a8: v27);
      return 2;
    }
    v23 = idMQChannel::DecodeMethod(frame: (idMQFrame *)HIDWORD(frame));
    command->method = v23;
    v16 = !v23->HasContent(this: v23) ? 3 : 1;
  }
  v21 = v16 == 3;
  *v7 = v16;
LABEL_20:
  if ( v21 )
  {
    command->complete = true;
    *v7 = 0;
    *((_QWORD *)v7 + 1) = 0x100000000LL;
    return 0;
  }
  else
  {
    command->complete = false;
    return 0;
  }
}

