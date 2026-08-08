
// ========================================================================
// ?FinalizeReadPresence@idMQFrame@@QAAXXZ
// EA  : 0x82F42958
// RVA : 0x00F42958
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMQFrame::FinalizeReadPresence(
        idMQFrame *this,
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

  LODWORD(a5) = this->readPresenceBuffer & 1;
  if ( (_DWORD)a5 != 0 )
  {
    HIDWORD(v9) = "ERROR: AMQP:: idMQFrame::ReadPropertyPresence: There were additional presence flags?\n";
    idLib::Printf(fmt: v9, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?Close@idMQFrameHandler@@QAAXXZ
// EA  : 0x82F42978
// RVA : 0x00F42978
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrameHandler::Close(idMQFrameHandler *this)
{
  idMQTCP::Close(this: &this->tcp);
}


// ========================================================================
// ?ReadData@idMQFrame@@QAAXPAXH@Z
// EA  : 0x82F42980
// RVA : 0x00F42980
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::ReadData(idMQFrame *this, void *ptr, size_t length)
{
  if ( this->resetReadBitBuffer )
  {
    this->readBitBuffer = 0;
    this->readBitMask = 256;
  }
  memcpy(Dst: ptr, Src: &this->data.list[this->readPos], Size: length);
  this->readPos += length;
}


// ========================================================================
// ?WriteToStream@idMQFrame@@QAAHAAVidMQTCP@@@Z
// EA  : 0x82F42A00
// RVA : 0x00F42A00
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

int __fastcall idMQFrame::WriteToStream(idMQFrame *this, idMQTCP *tcp)
{
  unsigned int num; // r28
  int v5; // r10
  int v6; // r9
  int v7; // r8
  int v8; // r7
  int v9; // r6
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v16; // [sp+8h] [-98h]
  int v17; // [sp+8h] [-98h]
  int v18; // [sp+Ch] [-94h]
  int v19; // [sp+Ch] [-94h]
  int v20; // [sp+10h] [-90h]
  int v21; // [sp+10h] [-90h]
  int v22; // [sp+14h] [-8Ch]
  int v23; // [sp+14h] [-8Ch]
  int v24; // [sp+18h] [-88h]
  int v25; // [sp+18h] [-88h]
  unsigned int v26; // [sp+1Ch] [-84h]
  unsigned __int16 v27; // [sp+1Eh] [-82h]
  char v28; // [sp+50h] [-50h] BYREF
  idStaticList<idVehicleState *,4> v29[2]; // [sp+60h] [-40h] BYREF

  idMQBuffer::idMQBuffer(this: (idAttachmentCollection *)v29);
  num = this->data.num;
  v28 = -50;
  idMQBuffer::WriteData(this: (idMQBuffer *)v29, ptr: this, length: 1u);
  idMQBuffer::WriteUInt16(
    this: (idMQBuffer *)v29,
    value: this->channel,
    endianCorrect: true,
    a4: v9,
    a5: v8,
    a6: v7,
    a7: v6,
    a8: v5,
    a9: v16,
    a10: v18,
    a11: v20,
    a12: v22,
    a13: v24,
    a14: v27);
  idMQBuffer::WriteUInt32(
    this: (idMQBuffer *)v29,
    value: num,
    endianCorrect: true,
    a4: v14,
    a5: v13,
    a6: v12,
    a7: v11,
    a8: v10,
    a9: v17,
    a10: v19,
    a11: v21,
    a12: v23,
    a13: v25,
    a14: v26);
  idMQBuffer::WriteData(this: (idMQBuffer *)v29, ptr: this->data.list, length: num);
  idMQBuffer::WriteData(this: (idMQBuffer *)v29, ptr: &v28, length: 1u);
  if ( idMQTCP::Write(this: tcp, data: v29[0].list, size: v29[0].num, blocking: true, timeoutMS: 5000) == num )
  {
    idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: v29);
    return 1;
  }
  else
  {
    idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: v29);
    return -1;
  }
}


// ========================================================================
// __unwind$117617
// EA  : 0x82F42AC0
// RVA : 0x00F42AC0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void _unwind_117617()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 160 + 96));
}


// ========================================================================
// ??1idMQFrameHandler@@QAA@XZ
// EA  : 0x82F42AF0
// RVA : 0x00F42AF0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrameHandler::~idMQFrameHandler(idMQFrameHandler *this)
{
  idMQTCP *p_tcp; // r29

  p_tcp = &this->tcp;
  idMQTCP::Close(this: &this->tcp);
  idMQTCP::~idMQTCP(this: (idSMTP *)p_tcp);
  Sys_MutexDestroy(handle: &this->writeLock.handle);
  Sys_MutexDestroy(handle: &this->readLock.handle);
  amqpEndpoint_t::~amqpEndpoint_t(this: &this->endpoint);
}


// ========================================================================
// __unwind$117715
// EA  : 0x82F42B3C
// RVA : 0x00F42B3C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void _unwind_117715()
{
  int v0; // r12

  amqpEndpoint_t::~amqpEndpoint_t(this: *(amqpEndpoint_t **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$117716
// EA  : 0x82F42B64
// RVA : 0x00F42B64
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void _unwind_117716()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 148));
}


// ========================================================================
// __unwind$117717
// EA  : 0x82F42B90
// RVA : 0x00F42B90
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void _unwind_117717()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 152));
}


// ========================================================================
// __unwind$117718
// EA  : 0x82F42BBC
// RVA : 0x00F42BBC
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void _unwind_117718()
{
  int v0; // r12

  idMQTCP::~idMQTCP(this: (idSMTP *)(*(_DWORD *)(v0 - 112 + 132) + 156));
}


// ========================================================================
// ?Connect@idMQFrameHandler@@QAA_NXZ
// EA  : 0x82F42BE8
// RVA : 0x00F42BE8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

BOOL __fastcall idMQFrameHandler::Connect(idMQFrameHandler *this)
{
  return idMQTCP::Connect(
           this: &this->tcp,
           host: this->endpoint.host.data,
           port: this->endpoint.port,
           nonBlocking: this->endpoint.nonBlocking,
           silent: this->endpoint.silent);
}


// ========================================================================
// ?SendFrame@idMQFrameHandler@@QAAHAAVidMQFrame@@@Z
// EA  : 0x82F42C10
// RVA : 0x00F42C10
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

int __fastcall idMQFrameHandler::SendFrame(idMQFrameHandler *this, idMQFrame *frame)
{
  idSysMutex *p_writeLock; // r30
  int v5; // r29

  p_writeLock = &this->writeLock;
  Sys_MutexLock(handle: &this->writeLock.handle, blocking: true);
  v5 = idMQFrame::WriteToStream(this: frame, tcp: &this->tcp);
  Sys_MutexUnlock(handle: &p_writeLock->handle);
  return v5;
}


// ========================================================================
// __unwind$117769
// EA  : 0x82F42C60
// RVA : 0x00F42C60
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void _unwind_117769()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?Clear@idMQFrame@@QAAXXZ
// EA  : 0x82F42C88
// RVA : 0x00F42C88
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::Clear(idMQFrame *this)
{
  this->locked = false;
  this->readPos = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->data);
  if ( this->resetReadBitBuffer )
  {
    this->readBitBuffer = 0;
    this->readBitMask = 256;
  }
  this->flushWriteBitBuffer = false;
  this->writeBitBuffer = 0;
  this->writeBitMask = 1;
  this->readPresenceBuffer = 1;
  this->readPresencePosition = 15;
  this->writePresenceBuffer = 0;
  this->writePresencePosition = 0;
}


// ========================================================================
// ?ReadByte@idMQFrame@@QAAEXZ
// EA  : 0x82F42D08
// RVA : 0x00F42D08
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

int __fastcall idMQFrame::ReadByte(idMQFrame *this)
{
  int readPos; // r11
  unsigned __int8 v2; // r7

  if ( this->resetReadBitBuffer )
  {
    this->readBitBuffer = 0;
    this->readBitMask = 256;
    this->readBitBuffer = 0;
    this->readBitMask = 256;
  }
  readPos = this->readPos;
  v2 = this->data.list[readPos];
  this->readPos = readPos + 1;
  return v2;
}


// ========================================================================
// ?ReadShortString@idMQFrame@@QAA?AVidStr@@XZ
// EA  : 0x82F42D50
// RVA : 0x00F42D50
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

idMQFrame *__fastcall idMQFrame::ReadShortString(idMQFrame *this, idStr *result)
{
  int v3; // r11
  unsigned __int8 v4; // r7
  size_t v5; // r30
  int v7; // r12
  idMQFrame *v8; // r4
  _DWORD back_chain[20]; // [sp+0h] [-90h]
  char v10[64]; // [sp+50h] [-40h] BYREF

  if ( result->baseBuffer[13] != 0 )
  {
    result->baseBuffer[14] = 0;
    *(_DWORD *)&result->baseBuffer[16] = 256;
    result->baseBuffer[14] = 0;
    *(_DWORD *)&result->baseBuffer[16] = 256;
    result->baseBuffer[14] = 0;
    *(_DWORD *)&result->baseBuffer[16] = 256;
  }
  v3 = *(_DWORD *)&result->baseBuffer[8];
  v4 = result->data[v3];
  *(_DWORD *)&result->baseBuffer[8] = v3 + 1;
  v10[0] = v4;
  v5 = v4;
  if ( v4 != 0 )
  {
    ((void (*)(void))RtlCheckStack12)();
    *(_DWORD *)((char *)back_chain + v7) = back_chain[0];
    idMQFrame::ReadData(this: v8, ptr: v10, length: v5);
    v10[v5] = 0;
    idStr::idStr((idStr *)this, text: v10);
  }
  else
  {
    idStr::idStr((idStr *)this, text: &byte_8200D768);
  }
  return this;
}


// ========================================================================
// ?ReadUInt16@idMQFrame@@QAAGXZ
// EA  : 0x82F42E20
// RVA : 0x00F42E20
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

int __fastcall idMQFrame::ReadUInt16(idMQFrame *this)
{
  int readPos; // r11
  int v2; // r8
  unsigned __int8 *v3; // r11
  unsigned __int8 v4; // r7
  unsigned __int8 v5; // r6
  unsigned __int16 back_chain; // [sp+0h] [-10h]

  if ( this->resetReadBitBuffer )
  {
    this->readBitBuffer = 0;
    this->readBitMask = 256;
    this->readBitBuffer = 0;
    this->readBitMask = 256;
  }
  readPos = this->readPos;
  v2 = readPos + 2;
  v3 = &this->data.list[readPos];
  v4 = *v3;
  v5 = v3[1];
  this->readPos = v2;
  HIBYTE(back_chain) = v4;
  LOBYTE(back_chain) = v5;
  return back_chain;
}


// ========================================================================
// ?ReadUInt32@idMQFrame@@QAAIXZ
// EA  : 0x82F42E78
// RVA : 0x00F42E78
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

int __fastcall idMQFrame::ReadUInt32(idMQFrame *this)
{
  int readPos; // r11
  int v2; // r8
  unsigned __int8 *v3; // r11
  unsigned __int8 v4; // r7
  unsigned __int8 v5; // r6
  unsigned __int8 v6; // r5
  unsigned __int8 v7; // r4
  int back_chain; // [sp+0h] [-10h]

  if ( this->resetReadBitBuffer )
  {
    this->readBitBuffer = 0;
    this->readBitMask = 256;
    this->readBitBuffer = 0;
    this->readBitMask = 256;
  }
  readPos = this->readPos;
  v2 = readPos + 4;
  v3 = &this->data.list[readPos];
  v4 = *v3;
  v5 = v3[1];
  v6 = v3[2];
  v7 = v3[3];
  this->readPos = v2;
  HIBYTE(back_chain) = v4;
  BYTE1(back_chain) = v5;
  BYTE2(back_chain) = v6;
  LOBYTE(back_chain) = v7;
  return back_chain;
}


// ========================================================================
// ?ReadUInt64@idMQFrame@@QAA_KXZ
// EA  : 0x82F42EE0
// RVA : 0x00F42EE0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

int __fastcall idMQFrame::ReadUInt64(idMQFrame *this)
{
  int readPos; // r7
  char *v3; // r9
  unsigned __int8 *v4; // r10
  int i; // ctr
  int result; // r3
  char v7; // [sp+1h] [-11h] BYREF
  __int64 v8; // [sp+2h] [-10h]

  if ( this->resetReadBitBuffer )
  {
    this->readBitBuffer = 0;
    this->readBitMask = 256;
    this->readBitBuffer = 0;
    this->readBitMask = 256;
  }
  readPos = this->readPos;
  v3 = &v7;
  v4 = &this->data.list[readPos - 1];
  for ( i = 8; i != 0; --i )
    *++v3 = *++v4;
  result = v8;
  this->readPos = readPos + 8;
  return result;
}


// ========================================================================
// ?ReadBool@idMQFrame@@QAA_NXZ
// EA  : 0x82F42F40
// RVA : 0x00F42F40
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

BOOL __fastcall idMQFrame::ReadBool(idMQFrame *this)
{
  unsigned int readBitMask; // r11
  int readPos; // r11
  unsigned __int8 v3; // r6
  unsigned int v4; // r11
  int readBitBuffer; // r10

  readBitMask = this->readBitMask;
  this->resetReadBitBuffer = false;
  if ( readBitMask > 0x80 )
  {
    readPos = this->readPos;
    v3 = this->data.list[readPos];
    this->readPos = readPos + 1;
    this->readBitMask = 1;
    this->readBitBuffer = v3;
  }
  v4 = this->readBitMask;
  readBitBuffer = this->readBitBuffer;
  this->resetReadBitBuffer = true;
  this->readBitMask = 2 * v4;
  return (readBitBuffer & v4) != 0;
}


// ========================================================================
// ?ReadPropertyPresence@idMQFrame@@QAA_NXZ
// EA  : 0x82F42FA8
// RVA : 0x00F42FA8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
BOOL __fastcall idMQFrame::ReadPropertyPresence(idMQFrame *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // r4
  int readPos; // r11
  int v8; // r7
  unsigned __int8 *v9; // r11
  unsigned __int8 v10; // r6
  unsigned __int8 v11; // r5
  unsigned __int16 readPresencePosition; // r11
  int v13; // r5
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+10h] [-60h]
  int v18; // [sp+14h] [-5Ch]
  unsigned __int16 v19; // [sp+50h] [-20h]

  if ( this->readPresencePosition == 15 )
  {
    LODWORD(a5) = this->readPresenceBuffer & 1;
    if ( (_DWORD)a5 == 0 )
    {
      HIDWORD(v6) = "ERROR: AMQP:: idMQFrame::ReadPropertyPresence: Unable to read additional property presences.\n";
      idLib::Printf(fmt: v6, a2: a3, a3: a4, a4: a5, a5: v15, a6: v16, a7: v17, a8: v18);
    }
    if ( this->resetReadBitBuffer )
    {
      this->readBitBuffer = 0;
      this->readBitMask = 256;
      this->readBitBuffer = 0;
      this->readBitMask = 256;
    }
    readPos = this->readPos;
    v8 = readPos + 2;
    v9 = &this->data.list[readPos];
    v10 = *v9;
    v11 = v9[1];
    this->readPos = v8;
    this->readPresencePosition = 0;
    HIBYTE(v19) = v10;
    LOBYTE(v19) = v11;
    this->readPresenceBuffer = v19;
  }
  readPresencePosition = this->readPresencePosition;
  v13 = this->readPresenceBuffer & (1 << (15 - readPresencePosition));
  this->readPresencePosition = readPresencePosition + 1;
  return v13 != 0;
}


// ========================================================================
// ?ReadTable@idMQFrame@@QAAXAAVidDict@@@Z
// EA  : 0x82F43078
// RVA : 0x00F43078
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::ReadTable(idMQFrame *this, idDict *dict)
{
  if ( this->resetReadBitBuffer )
  {
    this->readBitBuffer = 0;
    this->readBitMask = 256;
    this->readBitBuffer = 0;
    this->readBitMask = 256;
    this->readBitBuffer = 0;
    this->readBitMask = 256;
  }
  this->readPos += *(_DWORD *)&this->data.list[this->readPos] + 4;
}


// ========================================================================
// ??0idMQFrame@@QAA@XZ
// EA  : 0x82F43208
// RVA : 0x00F43208
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

idMQFrame *__fastcall idMQFrame::idMQFrame(idMQFrame *this)
{
  this->data.list = nullptr;
  this->data.granularity = 0;
  this->data.memTag = 5;
  this->data.listStatic = 0;
  this->data.size = 0;
  this->data.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->data);
  this->resetReadBitBuffer = true;
  idMQFrame::Clear(this);
  return this;
}


// ========================================================================
// __unwind$118316
// EA  : 0x82F4327C
// RVA : 0x00F4327C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void _unwind_118316()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??0idMQFrame@@QAA@EG@Z
// EA  : 0x82F432B0
// RVA : 0x00F432B0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

idMQFrame *__fastcall idMQFrame::idMQFrame(idMQFrame *this, unsigned __int8 _type, unsigned __int16 _channel)
{
  this->type = _type;
  this->channel = _channel;
  this->data.list = nullptr;
  this->data.granularity = 0;
  this->data.memTag = 5;
  this->data.listStatic = 0;
  this->data.size = 0;
  this->data.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->data);
  this->resetReadBitBuffer = true;
  idMQFrame::Clear(this);
  return this;
}


// ========================================================================
// __unwind$118336
// EA  : 0x82F4332C
// RVA : 0x00F4332C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void _unwind_118336()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??0idMQFrameHandler@@QAA@ABUamqpEndpoint_t@@@Z
// EA  : 0x82F43360
// RVA : 0x00F43360
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

idMQFrameHandler *__fastcall idMQFrameHandler::idMQFrameHandler(
        idMQFrameHandler *this,
        const amqpEndpoint_t *_endpoint)
{
  amqpEndpoint_t::amqpEndpoint_t(this: &this->endpoint, __that: _endpoint);
  Sys_MutexCreate(handle: &this->readLock.handle);
  Sys_MutexCreate(handle: &this->writeLock.handle);
  idMQTCP::idMQTCP(this: &this->tcp);
  return this;
}


// ========================================================================
// __unwind$118373
// EA  : 0x82F433B8
// RVA : 0x00F433B8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void _unwind_118373()
{
  int v0; // r12

  amqpEndpoint_t::~amqpEndpoint_t(this: *(amqpEndpoint_t **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$118374
// EA  : 0x82F433E0
// RVA : 0x00F433E0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void _unwind_118374()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 148));
}


// ========================================================================
// __unwind$118375
// EA  : 0x82F4340C
// RVA : 0x00F4340C
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void _unwind_118375()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 112 + 132) + 152));
}


// ========================================================================
// ?ReadString@idMQFrame@@QAAXAAV?$idList@E$04@@@Z
// EA  : 0x82F43438
// RVA : 0x00F43438
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::ReadString(idMQFrame *this, idList<unsigned char,37> *str)
{
  int readPos; // r11
  int v5; // r8
  unsigned __int8 *v6; // r11
  unsigned __int8 v7; // r7
  unsigned __int8 v8; // r6
  unsigned __int8 v9; // r5
  unsigned __int8 v10; // r4
  int size; // r11
  unsigned int i; // r11
  unsigned __int8 *v13; // r10
  int v14; // [sp+50h] [-40h]

  if ( this->resetReadBitBuffer )
  {
    this->readBitBuffer = 0;
    this->readBitMask = 256;
    this->readBitBuffer = 0;
    this->readBitMask = 256;
    this->readBitBuffer = 0;
    this->readBitMask = 256;
  }
  readPos = this->readPos;
  v5 = readPos + 4;
  v6 = &this->data.list[readPos];
  v7 = *v6;
  v8 = v6[1];
  v9 = v6[2];
  v10 = v6[3];
  this->readPos = v5;
  HIBYTE(v14) = v7;
  BYTE1(v14) = v8;
  BYTE2(v14) = v9;
  LOBYTE(v14) = v10;
  if ( v14 <= str->size || (unsigned __int8)idList<unsigned char,25>::Resize(this: str, newsize: v14) != 0 )
  {
    size = str->size;
    if ( v14 < size )
      size = v14;
    str->num = size;
  }
  for ( i = 0; i < v14; ++this->readPos )
  {
    v13 = &str->list[i];
    if ( this->resetReadBitBuffer )
    {
      this->readBitBuffer = 0;
      this->readBitMask = 256;
    }
    ++i;
    *v13 = this->data.list[this->readPos];
  }
}


// ========================================================================
// ?WriteData@idMQFrame@@QAAXPBXH@Z
// EA  : 0x82F43548
// RVA : 0x00F43548
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::WriteData(idMQFrame *this, const void *ptr, size_t length)
{
  int num; // r28
  idList<unsigned char,5> *p_data; // r31
  signed int size; // r11

  idMQFrame::FlushWriteBitBuffer(this);
  num = this->data.num;
  p_data = &this->data;
  idList<unsigned char,5>::PreAllocateWithGranularity(this: p_data, newSize: num + length);
  if ( (signed int)(num + length) <= p_data->size
    || (unsigned __int8)idList<unsigned char,25>::Resize(
                          this: (idList<unsigned char,37> *)p_data,
                          newsize: num + length) != 0 )
  {
    size = p_data->size;
    if ( (int)(num + length) < size )
      size = num + length;
    p_data->num = size;
  }
  memcpy(Dst: &p_data->list[num], Src: ptr, Size: length);
}


// ========================================================================
// ?ReadFromStream@idMQFrame@@QAAHAAVidMQTCP@@@Z
// EA  : 0x82F435D0
// RVA : 0x00F435D0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

int __fastcall idMQFrame::ReadFromStream(idMQFrame *this, idMQTCP *tcp)
{
  int result; // r3
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r4
  __int64 v8; // r6
  int v9; // [sp+8h] [-68h]
  int v10; // [sp+Ch] [-64h]
  int v11; // [sp+10h] [-60h]
  int v12; // [sp+14h] [-5Ch]
  _BYTE v13[4]; // [sp+50h] [-20h] BYREF
  int v14; // [sp+54h] [-1Ch] BYREF

  v14 = 0;
  result = idMQTCP::ReadByte(this: tcp, data: &this->type, blocking: true, timeoutMS: 5000);
  if ( result == 1 )
  {
    if ( this->type == 65 )
    {
      return 0;
    }
    else
    {
      result = idMQTCP::ReadUInt16(this: tcp, data: &this->channel, blocking: true, timeoutMS: 5000);
      if ( result == 2 )
      {
        result = idMQTCP::ReadUInt32(this: tcp, data: (unsigned int *)&v14, blocking: true, timeoutMS: 5000);
        if ( result == 4 )
        {
          idList<unsigned char,19>::SetNum(this: (idList<unsigned char,37> *)&this->data, newNum: v14);
          HIDWORD(v7) = idMQTCP::Read(this: tcp, data: this->data.list, size: v14, blocking: true, timeoutMS: 5000);
          LODWORD(v7) = v14;
          HIDWORD(v8) = HIDWORD(v7);
          if ( HIDWORD(v7) == v14 )
          {
            result = idMQTCP::Read(this: tcp, data: v13, size: 1, blocking: false, timeoutMS: 5000);
            if ( result == 1 )
            {
              result = -1;
              if ( v13[0] == 206 )
                return 1;
            }
          }
          else
          {
            HIDWORD(v7) = "AMQP: Frame was too short expected=%d, received=%d\n";
            idLib::Printf(fmt: v7, a2: v8, a3: v6, a4: v5, a5: v9, a6: v10, a7: v11, a8: v12);
            return -1;
          }
        }
      }
    }
  }
  return result;
}


// ========================================================================
// ?ReadFrame@idMQFrameHandler@@QAAHAAVidMQFrame@@@Z
// EA  : 0x82F436F8
// RVA : 0x00F436F8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

int __fastcall idMQFrameHandler::ReadFrame(idMQFrameHandler *this, idMQFrame *frame)
{
  idSysMutex *p_readLock; // r30
  int v5; // r29

  p_readLock = &this->readLock;
  Sys_MutexLock(handle: &this->readLock.handle, blocking: true);
  v5 = idMQFrame::ReadFromStream(this: frame, tcp: &this->tcp);
  Sys_MutexUnlock(handle: &p_readLock->handle);
  return v5;
}


// ========================================================================
// __unwind$118643
// EA  : 0x82F43748
// RVA : 0x00F43748
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void _unwind_118643()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?WriteByte@idMQFrame@@QAAXE@Z
// EA  : 0x82F43770
// RVA : 0x00F43770
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::WriteByte(
        idMQFrame *this,
        unsigned __int8 value,
        int a3,
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
        unsigned __int8 a14)
{
  a14 = value;
  idMQFrame::FlushWriteBitBuffer(this);
  idMQFrame::WriteData(this, ptr: &a14, length: 1u);
}


// ========================================================================
// ?FlushWriteBitBuffer@idMQFrame@@QAAXXZ
// EA  : 0x82F437B0
// RVA : 0x00F437B0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::FlushWriteBitBuffer(idMQFrame *this)
{
  unsigned __int8 writeBitBuffer; // r11
  unsigned __int8 v3[8]; // [sp+50h] [-20h] BYREF

  if ( this->flushWriteBitBuffer )
  {
    writeBitBuffer = this->writeBitBuffer;
    this->flushWriteBitBuffer = false;
    v3[0] = writeBitBuffer;
    idMQFrame::FlushWriteBitBuffer(this);
    idMQFrame::WriteData(this, ptr: v3, length: 1u);
    this->flushWriteBitBuffer = false;
    this->writeBitBuffer = 0;
    this->writeBitMask = 1;
  }
}


// ========================================================================
// ?FinalizeFrame@idMQFrame@@QAAXXZ
// EA  : 0x82F43820
// RVA : 0x00F43820
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::FinalizeFrame(idMQFrame *this)
{
  this->locked = true;
  idMQFrame::FlushWriteBitBuffer(this);
}


// ========================================================================
// ?WriteShortString@idMQFrame@@QAAXABVidStr@@@Z
// EA  : 0x82F43830
// RVA : 0x00F43830
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::WriteShortString(idMQFrame *this, const idStr *value)
{
  size_t len; // r30
  char v5; // [sp+50h] [-30h] BYREF

  idMQFrame::FlushWriteBitBuffer(this);
  len = value->len;
  v5 = value->len;
  idMQFrame::FlushWriteBitBuffer(this);
  idMQFrame::WriteData(this, ptr: &v5, length: 1u);
  if ( len != 0 )
    idMQFrame::WriteData(this, ptr: value->data, length: len);
}


// ========================================================================
// ?WriteUInt16@idMQFrame@@QAAXG@Z
// EA  : 0x82F43888
// RVA : 0x00F43888
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::WriteUInt16(
        idMQFrame *this,
        unsigned __int16 value,
        int a3,
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
  idMQFrame::FlushWriteBitBuffer(this);
  idMQFrame::WriteData(this, ptr: &a14, length: 2u);
}


// ========================================================================
// ?WriteUInt32@idMQFrame@@QAAXI@Z
// EA  : 0x82F438C8
// RVA : 0x00F438C8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::WriteUInt32(
        idMQFrame *this,
        unsigned int value,
        int a3,
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
  idMQFrame::FlushWriteBitBuffer(this);
  idMQFrame::WriteData(this, ptr: &a14, length: 4u);
}


// ========================================================================
// ?WriteUInt64@idMQFrame@@QAAX_K@Z
// EA  : 0x82F43908
// RVA : 0x00F43908
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idMQFrame::WriteUInt64(
        idMQFrame *this,
        int a2,
        const unsigned __int64 value,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  a10 = *(_QWORD *)(&this - 1);
  idMQFrame::FlushWriteBitBuffer(this);
  idMQFrame::WriteData(this, ptr: &a10, length: 8u);
}


// ========================================================================
// ?WriteBool@idMQFrame@@QAAX_N@Z
// EA  : 0x82F43948
// RVA : 0x00F43948
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::WriteBool(idMQFrame *this, bool value)
{
  unsigned int v4; // r9

  if ( this->writeBitMask > 0x80 )
    idMQFrame::FlushWriteBitBuffer(this);
  if ( value )
    this->writeBitBuffer |= this->writeBitMask;
  v4 = 2 * this->writeBitMask;
  this->flushWriteBitBuffer = true;
  this->writeBitMask = v4;
}


// ========================================================================
// ?WritePropertyPresence@idMQFrame@@QAAX_N@Z
// EA  : 0x82F439C0
// RVA : 0x00F439C0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::WritePropertyPresence(idMQFrame *this, bool exists)
{
  _WORD v4[4]; // [sp+50h] [-20h] BYREF

  if ( this->writePresencePosition == 15 )
  {
    v4[0] = this->writePresenceBuffer | 1;
    idMQFrame::FlushWriteBitBuffer(this);
    idMQFrame::WriteData(this, ptr: v4, length: 2u);
    this->writePresenceBuffer = 0;
    this->writePresencePosition = 0;
  }
  if ( exists )
    this->writePresenceBuffer |= 1 << (15 - this->writePresencePosition);
  ++this->writePresencePosition;
}


// ========================================================================
// ?WriteTable@idMQFrame@@QAAXAAVidDict@@@Z
// EA  : 0x82F43A60
// RVA : 0x00F43A60
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::WriteTable(idMQFrame *this, idDict *dict)
{
  _DWORD v3[4]; // [sp+50h] [-20h] BYREF

  idMQFrame::FlushWriteBitBuffer(this);
  v3[0] = 0;
  idMQFrame::FlushWriteBitBuffer(this);
  idMQFrame::WriteData(this, ptr: v3, length: 4u);
}


// ========================================================================
// ?SendHeader@idMQFrameHandler@@QAA_NXZ
// EA  : 0x82F43AB8
// RVA : 0x00F43AB8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

BOOL __fastcall idMQFrameHandler::SendHeader(idMQFrameHandler *this)
{
  BOOL v2; // r30
  _BYTE v4[16]; // [sp+50h] [-60h] BYREF
  idMQFrame v5; // [sp+60h] [-50h] BYREF

  idMQFrame::idMQFrame(this: &v5);
  idMQFrame::WriteData(this: &v5, ptr: "AMQP", length: 4u);
  v4[0] = 1;
  idMQFrame::FlushWriteBitBuffer(this: &v5);
  idMQFrame::WriteData(this: &v5, ptr: v4, length: 1u);
  v4[0] = 1;
  idMQFrame::FlushWriteBitBuffer(this: &v5);
  idMQFrame::WriteData(this: &v5, ptr: v4, length: 1u);
  v4[0] = this->endpoint.majorVersion;
  idMQFrame::FlushWriteBitBuffer(this: &v5);
  idMQFrame::WriteData(this: &v5, ptr: v4, length: 1u);
  v4[0] = this->endpoint.minorVersion;
  idMQFrame::FlushWriteBitBuffer(this: &v5);
  idMQFrame::WriteData(this: &v5, ptr: v4, length: 1u);
  v2 = (_cntlzw(
          v5.data.num
        - idMQTCP::Write(this: &this->tcp, data: v5.data.list, size: v5.data.num, blocking: true, timeoutMS: 5000))
      & 0x20) != 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v5.data);
  return v2;
}


// ========================================================================
// __unwind$118800
// EA  : 0x82F43BA0
// RVA : 0x00F43BA0
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void _unwind_118800()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 176 + 96));
}


// ========================================================================
// ?FinalizeWritePresence@idMQFrame@@QAAXXZ
// EA  : 0x82F43BC8
// RVA : 0x00F43BC8
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::FinalizeWritePresence(idMQFrame *this)
{
  unsigned __int16 v2[8]; // [sp+50h] [-20h] BYREF

  v2[0] = this->writePresenceBuffer;
  idMQFrame::FlushWriteBitBuffer(this);
  idMQFrame::WriteData(this, ptr: v2, length: 2u);
  this->writePresenceBuffer = 0;
  this->writePresencePosition = 0;
}


// ========================================================================
// ?WriteString@idMQFrame@@QAAXABV?$idList@E$04@@@Z
// EA  : 0x82F43C18
// RVA : 0x00F43C18
// PDB : w:\tech5\shared\idlib\networking\amqp\mqframing.cpp
// ========================================================================

void __fastcall idMQFrame::WriteString(idMQFrame *this, const idList<unsigned char,5> *str)
{
  unsigned int v4; // r25
  unsigned int i; // r28
  unsigned __int8 *v6; // r26
  int v7; // r27
  int size; // r11
  unsigned __int8 v9[4]; // [sp+50h] [-60h] BYREF
  int num; // [sp+54h] [-5Ch] BYREF

  idMQFrame::FlushWriteBitBuffer(this);
  num = str->num;
  v4 = num;
  idMQFrame::FlushWriteBitBuffer(this);
  idMQFrame::WriteData(this, ptr: &num, length: 4u);
  if ( v4 != 0 )
  {
    for ( i = 0; i < v4; ++i )
    {
      v6 = &str->list[i];
      if ( this->flushWriteBitBuffer )
      {
        this->flushWriteBitBuffer = false;
        v9[0] = this->writeBitBuffer;
        idMQFrame::FlushWriteBitBuffer(this);
        idMQFrame::WriteData(this, ptr: v9, length: 1u);
        this->flushWriteBitBuffer = false;
        this->writeBitBuffer = 0;
        this->writeBitMask = 1;
      }
      v7 = this->data.num;
      idList<unsigned char,5>::PreAllocateWithGranularity(this: &this->data, newSize: v7 + 1);
      if ( v7 + 1 <= this->data.size
        || (unsigned __int8)idList<unsigned char,25>::Resize(
                              this: (idList<unsigned char,37> *)&this->data,
                              newsize: v7 + 1) != 0 )
      {
        size = this->data.size;
        if ( v7 + 1 < size )
          size = v7 + 1;
        this->data.num = size;
      }
      this->data.list[v7] = *v6;
    }
  }
}

