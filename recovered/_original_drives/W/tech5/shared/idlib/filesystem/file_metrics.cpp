
// ========================================================================
// ?GetFullPath@idFile_Metrics@@UBAPBDXZ
// EA  : 0x82F108C0
// RVA : 0x00F108C0
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

char *__fastcall idFile_Metrics::GetFullPath(idFile_Metrics *this)
{
  char *data; // r28
  const char *v3; // r3
  char *v4; // r30

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  data = this->name.data;
  v3 = Sys_NetAdrToString(a: *(const netadr_t **)idFile_Metrics::tcp.address.ip);
  idStr::Format(this: &this->fullpath, fmt: "metrics://%s/%s", v3, data);
  v4 = this->fullpath.data;
  idMem::PopHeap(this: &mem);
  return v4;
}


// ========================================================================
// __unwind$111564
// EA  : 0x82F10934
// RVA : 0x00F10934
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void _unwind_111564()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 128 + 80));
}


// ========================================================================
// ?WriteToQueue@idFile_Metrics@@CAXPBXH@Z
// EA  : 0x82F10960
// RVA : 0x00F10960
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void __fastcall idFile_Metrics::WriteToQueue(char *buffer, int len)
{
  size_t v3; // r23
  int v4; // r11
  int v5; // r9
  int v6; // r10
  signed int v7; // r26
  signed int i; // r11
  char *v9; // r28
  int v10; // r10
  int v11; // r11
  int v12; // r31
  bool v13; // cr56
  unsigned __int8 *v14; // r9
  int v15; // r31

  v3 = len;
  v4 = idFile_Metrics::pendingIndex;
  v5 = idFile_Metrics::pendingIndex - idFile_Metrics::sendIndex;
  v6 = idFile_Metrics::sendQueueSize;
  if ( idFile_Metrics::pendingIndex - idFile_Metrics::sendIndex <= 0 )
    v5 += idFile_Metrics::sendQueueSize;
  if ( idFile_Metrics::sendQueueSize >= len )
  {
    v14 = idFile_Metrics::sendQueue;
  }
  else
  {
    v7 = idFile_Metrics::sendQueueSize;
    if ( idFile_Metrics::sendQueueSize <= 1024 )
      v7 = 1024;
    for ( i = idFile_Metrics::sendQueueSize - v5 + len; v7 < i; v7 *= 2 )
      ;
    v9 = (char *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\filesystem\\File_Metrics.cpp(98) : TAG_FILE",
                   size: v7,
                   tag: TAG_FILE,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
    idLib::Warning(fmt: "(re)allocate the metrics send buffer (%d -> %d)", idFile_Metrics::sendQueueSize, v7);
    v10 = idFile_Metrics::pendingIndex;
    v11 = idFile_Metrics::sendIndex;
    v12 = 0;
    v13 = idFile_Metrics::sendIndex < idFile_Metrics::pendingIndex;
    if ( idFile_Metrics::sendIndex > idFile_Metrics::pendingIndex )
    {
      memcpy(
        Dst: v9,
        Src: &idFile_Metrics::sendQueue[idFile_Metrics::sendIndex],
        Size: idFile_Metrics::sendQueueSize - idFile_Metrics::sendIndex);
      v10 = idFile_Metrics::pendingIndex;
      v12 = idFile_Metrics::sendQueueSize - idFile_Metrics::sendIndex;
      v11 = 0;
      idFile_Metrics::sendIndex = 0;
      v13 = idFile_Metrics::pendingIndex > 0;
    }
    if ( v13 )
    {
      memcpy(Dst: &v9[v12], Src: idFile_Metrics::sendQueue, Size: v10 - v11);
      v12 += idFile_Metrics::pendingIndex - idFile_Metrics::sendIndex;
    }
    if ( idFile_Metrics::sendQueue != nullptr )
      idMem::Free(this: &mem, ptr: idFile_Metrics::sendQueue, align: ALIGN_16);
    idFile_Metrics::sendQueue = (unsigned __int8 *)v9;
    v14 = (unsigned __int8 *)v9;
    idFile_Metrics::sendQueueSize = v7;
    v6 = v7;
    idFile_Metrics::sendIndex = 0;
    v4 = v12;
    idFile_Metrics::pendingIndex = v12;
  }
  if ( (int)(v4 + v3) > v6 )
  {
    v15 = v6 - v4;
    memcpy(Dst: &v14[v4], Src: buffer, Size: v6 - v4);
    v4 = 0;
    v14 = idFile_Metrics::sendQueue;
    buffer += v15;
    v3 -= v15;
    idFile_Metrics::pendingIndex = 0;
  }
  memcpy(Dst: &v14[v4], Src: buffer, Size: v3);
}


// ========================================================================
// ?BufferedWriteInternal@idFile_Metrics@@CAXAA_NPBXH@Z
// EA  : 0x82F10B10
// RVA : 0x00F10B10
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void __fastcall idFile_Metrics::BufferedWriteInternal(bool *queueTraffic, char *buffer, int len)
{
  int v6; // r3
  int v7; // r31

  if ( *queueTraffic )
  {
    idFile_Metrics::WriteToQueue(buffer, len);
    return;
  }
  v6 = idTCP::Write(this: &idFile_Metrics::tcp, data: buffer, size: len);
  v7 = v6;
  if ( v6 < 0 )
  {
    v7 = 0;
LABEL_5:
    if ( metrics_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "metrics short write %d out of %d\n", v7, len);
    *queueTraffic = true;
    idFile_Metrics::WriteToQueue(buffer: &buffer[v7], len: len - v7);
    return;
  }
  if ( v6 != len )
    goto LABEL_5;
  if ( metrics_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "metrics write %d bytes\n", v6);
}


// ========================================================================
// ?FlushBufferedWrites@idFile_Metrics@@CAXAA_N@Z
// EA  : 0x82F10BE8
// RVA : 0x00F10BE8
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void __fastcall idFile_Metrics::FlushBufferedWrites(bool *queueTraffic)
{
  int v2; // r11
  int v3; // r10
  int v4; // r31
  unsigned int v5; // r3
  int v6; // r30
  int v7; // r30
  unsigned int v8; // r3
  int v9; // r31

  v2 = idFile_Metrics::sendIndex;
  v3 = idFile_Metrics::pendingIndex;
  if ( idFile_Metrics::sendIndex != idFile_Metrics::pendingIndex )
  {
    if ( idFile_Metrics::pendingIndex < idFile_Metrics::sendIndex )
    {
      v4 = idFile_Metrics::sendQueueSize - idFile_Metrics::pendingIndex;
      v5 = idTCP::Write(
             this: &idFile_Metrics::tcp,
             data: &idFile_Metrics::sendQueue[idFile_Metrics::sendIndex],
             size: idFile_Metrics::sendQueueSize - idFile_Metrics::pendingIndex);
      v6 = ((v5 >> 31) - 1) & v5;
      if ( v6 == v4 )
      {
        if ( metrics_verbose.valueInteger != 0 )
          idLib::Printf(fmt: "metrics write %d bytes\n", v6);
        v2 = 0;
        idFile_Metrics::sendIndex = 0;
      }
      else
      {
        if ( metrics_verbose.valueInteger != 0 )
          idLib::Printf(fmt: "send queue short write (buffer wrap) %d out of %d\n", v6, v4);
        idFile_Metrics::sendIndex += v6;
        *queueTraffic = true;
        v2 = idFile_Metrics::sendIndex;
      }
      v3 = idFile_Metrics::pendingIndex;
    }
    v7 = v3 - v2;
    if ( !*queueTraffic && v7 > 0 )
    {
      v8 = idTCP::Write(this: &idFile_Metrics::tcp, data: &idFile_Metrics::sendQueue[v2], size: v7);
      v9 = ((v8 >> 31) - 1) & v8;
      if ( v9 == v7 )
      {
        if ( metrics_verbose.valueInteger != 0 )
          idLib::Printf(fmt: "metrics write %d bytes\n", v9);
        idFile_Metrics::sendIndex = idFile_Metrics::pendingIndex;
      }
      else
      {
        if ( metrics_verbose.valueInteger != 0 )
          idLib::Printf(fmt: "send queue short write %d out of %d\n", v9, v7);
        idFile_Metrics::sendIndex += v9;
        *queueTraffic = true;
      }
    }
  }
}


// ========================================================================
// ??0idFile_Metrics@@QAA@PBD@Z
// EA  : 0x82F10D68
// RVA : 0x00F10D68
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

idFile_Metrics *__fastcall idFile_Metrics::idFile_Metrics(idFile_Metrics *this, const char *_name)
{
  idFile::idFile(this);
  this->__vftable = (idFile_Metrics_vtbl *)&idFile_Metrics::`vftable';
  idStr::idStr(this: &this->name, text: _name);
  this->fullpath.len = 0;
  this->fullpath.allocedAndFlag = 20;
  this->fullpath.data = this->fullpath.baseBuffer;
  this->fullpath.baseBuffer[0] = 0;
  this->bytesSent = 0;
  return this;
}


// ========================================================================
// __unwind$111692
// EA  : 0x82F10DD0
// RVA : 0x00F10DD0
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void _unwind_111692()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 112 + 132));
}


// ========================================================================
// ?WriteInternal@idFile_Metrics@@CAIPBDPBXH@Z
// EA  : 0x82F10E08
// RVA : 0x00F10E08
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idFile_Metrics::WriteInternal(const char *name, char *buffer, int len)
{
  idCVar *v3; // r30 OVERLAPPED
  int valueInteger; // r11
  int v9; // r11
  int v10; // r31
  const char *v11; // r11
  int v12; // r10
  bool v13[16]; // [sp+50h] [-100h] BYREF
  idBitMsg v14; // [sp+60h] [-F0h] BYREF
  _BYTE v15[192]; // [sp+90h] [-C0h] BYREF

  if ( len == 0 )
    return 0;
  if ( idTCP::IsOpen(this: &idFile_Metrics::tcp) )
    goto LABEL_15;
  if ( idFile_Metrics::timeoutWait > (int)Sys_Milliseconds() )
  {
    if ( metrics_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "connection throttle - data loss %d\n", len);
    return 0;
  }
  v3 = &metrics_port;
  if ( idTCP::Connect(
         this: &idFile_Metrics::tcp,
         host: metrics_server.valueString.data,
         port: metrics_port.valueInteger,
         nonBlocking: true,
         silent: false,
         nagle: true) )
  {
    idLib::Printf(
      fmt: "metrics: Connected to %s on port %d\n",
      metrics_server.valueString.data,
      metrics_port.valueInteger);
LABEL_15:
    v10 = 0;
    v13[0] = false;
    idFile_Metrics::retryTime = 0;
    idFile_Metrics::FlushBufferedWrites(queueTraffic: v13);
    memset(&v14.curSize, 0, 18);
    v14.writeData = v15;
    v14.readData = v15;
    v11 = name;
    v14.maxSize = 128;
    v14.tempValue = *(_QWORD *)(&v3 - 1);
    do
      v12 = *(unsigned __int8 *)v11++;
    while ( v12 != 0 );
    idBitMsg::WriteBits(this: &v14, value: v11 - name + len, numBits: 32);
    idBitMsg::WriteString(this: &v14, s: name, maxLength: -1, make7Bit: true);
    idFile_Metrics::BufferedWriteInternal(
      queueTraffic: v13,
      buffer: (char *)v14.readData,
      len: (v14.writeBit != 0) + v14.curSize);
    idFile_Metrics::BufferedWriteInternal(queueTraffic: v13, buffer, len);
    return len;
  }
  valueInteger = idFile_Metrics::retryTime;
  if ( idFile_Metrics::retryTime <= metrics_retryTime.valueInteger )
    valueInteger = metrics_retryTime.valueInteger;
  v9 = 2 * valueInteger;
  idFile_Metrics::retryTime = v9;
  if ( v9 >= metrics_maxRetryTime.valueInteger )
  {
    v9 = metrics_maxRetryTime.valueInteger;
    idFile_Metrics::retryTime = metrics_maxRetryTime.valueInteger;
  }
  idLib::Warning(
    fmt: "Connection to metrics server failed (%s:%d). Retrying in %d seconds",
    metrics_server.valueString.data,
    metrics_port.valueInteger,
    v9 / 1000);
  idFile_Metrics::timeoutWait = Sys_Milliseconds() + idFile_Metrics::retryTime;
  if ( metrics_verbose.valueInteger == 0 )
    return 0;
  idLib::Printf(fmt: "connection throttle - data loss %d\n", len);
  return 0;
}


// ========================================================================
// ?CloseMetricsStream@idFile_Metrics@@CAXPBD@Z
// EA  : 0x82F11050
// RVA : 0x00F11050
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idFile_Metrics::CloseMetricsStream(const char *name)
{
  const char *v1; // r30 OVERLAPPED
  int v2; // r31
  const char *v3; // r11
  int v4; // r10
  bool v5[16]; // [sp+50h] [-160h] BYREF
  idBitMsg v6; // [sp+60h] [-150h] BYREF
  _BYTE v7[264]; // [sp+90h] [-120h] BYREF

  v1 = name;
  if ( idTCP::IsOpen(this: &idFile_Metrics::tcp) )
  {
    if ( metrics_verbose.valueInteger != 0 )
      idLib::Printf(fmt: "METRICS_FILE: Sending close notification for stream %s\n", v1);
    v2 = 0;
    v5[0] = false;
    idFile_Metrics::FlushBufferedWrites(queueTraffic: v5);
    memset(&v6.curSize, 0, 18);
    v6.writeData = v7;
    v6.readData = v7;
    v3 = v1;
    v6.maxSize = 256;
    v6.tempValue = *(_QWORD *)(&v1 - 1);
    do
      v4 = *(unsigned __int8 *)v3++;
    while ( v4 != 0 );
    idBitMsg::WriteBits(this: &v6, value: v3 - v1 - 1 + 15, numBits: 32);
    idBitMsg::WriteString(this: &v6, s: "CONTROL", maxLength: -1, make7Bit: true);
    idBitMsg::WriteString(this: &v6, s: "CLOSE", maxLength: -1, make7Bit: true);
    idBitMsg::WriteString(this: &v6, s: v1, maxLength: -1, make7Bit: true);
    idFile_Metrics::BufferedWriteInternal(
      queueTraffic: v5,
      buffer: (char *)v6.readData,
      len: (v6.writeBit != 0) + v6.curSize);
  }
  else
  {
    idLib::Warning(fmt: "CloseMetricsStream %s: no TCP socket", v1);
  }
}


// ========================================================================
// ?OpenMetricsStream@idFile_Metrics@@SAPAV1@PBD@Z
// EA  : 0x82F111B0
// RVA : 0x00F111B0
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

idFile_Metrics *__fastcall idFile_Metrics::OpenMetricsStream(const char *name)
{
  idFile_Metrics *v2; // r3
  idFile_Metrics *v3; // r29

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v2 = (idFile_Metrics *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x4Cu,
                           tag: TAG_FILE,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idFile_Metrics::idFile_Metrics(this: v2, _name: name);
  else
    v3 = nullptr;
  idMem::PopHeap(this: &mem);
  return v3;
}


// ========================================================================
// __unwind$111880
// EA  : 0x82F11230
// RVA : 0x00F11230
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void _unwind_111880()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 128 + 84));
}


// ========================================================================
// __unwind$111881
// EA  : 0x82F11258
// RVA : 0x00F11258
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void _unwind_111881()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_FILE);
}


// ========================================================================
// ??1idFile_Metrics@@UAA@XZ
// EA  : 0x82F11290
// RVA : 0x00F11290
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void __fastcall idFile_Metrics::~idFile_Metrics(idFile_Metrics *this)
{
  this->__vftable = (idFile_Metrics_vtbl *)&idFile_Metrics::`vftable';
  idFile_Metrics::CloseMetricsStream(name: this->name.data);
  idStr::FreeData(this: &this->fullpath);
  idStr::FreeData(this: &this->name);
  this->__vftable = (idFile_Metrics_vtbl *)&idFile::`vftable';
}


// ========================================================================
// __unwind$111913
// EA  : 0x82F112F8
// RVA : 0x00F112F8
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void _unwind_111913()
{
  int v0; // r12

  idFile::~idFile(this: *(idFile **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$111914_0
// EA  : 0x82F11320
// RVA : 0x00F11320
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void _unwind_111914_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$111915
// EA  : 0x82F1134C
// RVA : 0x00F1134C
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void _unwind_111915()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 40));
}


// ========================================================================
// ?Write@idFile_Metrics@@UAAIPBXI@Z
// EA  : 0x82F11380
// RVA : 0x00F11380
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

int __fastcall idFile_Metrics::Write(idFile_Metrics *this, char *buffer, int len)
{
  int v6; // r30

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v6 = idFile_Metrics::WriteInternal(name: this->name.data, buffer, len);
  idMem::PopHeap(this: &mem);
  return v6;
}


// ========================================================================
// __unwind$111960
// EA  : 0x82F113D8
// RVA : 0x00F113D8
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void _unwind_111960()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 144 + 80));
}


// ========================================================================
// `dynamic initializer for 'metrics_server''
// EA  : 0x83394E80
// RVA : 0x01394E80
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__metrics_server__()
{
  idCVar::idCVar(
    this: &metrics_server,
    name: "metrics_server",
    value: &byte_8200D768,
    flags: 0,
    description: "IP address of the metrics aggregation server",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__metrics_server__);
}


// ========================================================================
// `dynamic initializer for 'metrics_port''
// EA  : 0x83394ED8
// RVA : 0x01394ED8
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__metrics_port__()
{
  idCVar::idCVar(
    this: &metrics_port,
    name: "metrics_port",
    value: "8012",
    flags: 0,
    description: "metrics aggregation server port",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__metrics_port__);
}


// ========================================================================
// `dynamic initializer for 'metrics_retryTime''
// EA  : 0x83394F30
// RVA : 0x01394F30
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__metrics_retryTime__()
{
  idCVar::idCVar(
    this: &metrics_retryTime,
    name: "metrics_retryTime",
    value: "1000",
    flags: 2,
    description: "initial amount of time before the metrics tries to connect to the server again. Grows by two until 30 seconds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__metrics_retryTime__);
}


// ========================================================================
// `dynamic initializer for 'metrics_maxRetryTime''
// EA  : 0x83394F88
// RVA : 0x01394F88
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__metrics_maxRetryTime__()
{
  idCVar::idCVar(
    this: &metrics_maxRetryTime,
    name: "metrics_maxRetryTime",
    value: "60000",
    flags: 2,
    description: "max amount of time before the metrics tries to connect to server again. ",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__metrics_maxRetryTime__);
}


// ========================================================================
// `dynamic initializer for 'metrics_verbose''
// EA  : 0x83394FE0
// RVA : 0x01394FE0
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__metrics_verbose__()
{
  idCVar::idCVar(
    this: &metrics_verbose,
    name: "metrics_verbose",
    value: "0",
    flags: 1,
    description: "Verbose metrics logging",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__metrics_verbose__);
}


// ========================================================================
// `dynamic initializer for 'idFile_Metrics::tcp''
// EA  : 0x83395038
// RVA : 0x01395038
// PDB : w:\tech5\shared\idlib\filesystem\file_metrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idFile_Metrics::tcp__()
{
  idTCP::idTCP(this: &idFile_Metrics::tcp);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idFile_Metrics::tcp__);
}

