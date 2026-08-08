
// ========================================================================
// int_queue_packet
// EA  : 0x83223F38
// RVA : 0x01223F38
// PDB : w:\tech5\libs\mgrd\src\rd\rd.c
// ========================================================================

void __fastcall int_queue_packet(RD_HEADER *header, unsigned __int16 msg, unsigned int totalsize)
{
  unsigned __int64 v5; // r3
  unsigned __int64 v6; // r8

  header->msg = msg;
  header->payload = totalsize - 24;
  header->threadid = mgthread_getid();
  LODWORD(v5) = mgtimestamp_now();
  LODWORD(v6) = 0;
  header->timestamp = v5;
  HIDWORD(v6) = &rd_state.decoder.buffer[31220];
  header->timedelay = v6;
  mgringbuf_put(ringbuf: &rd_state.outbound, buffer: header, size: totalsize);
}


// ========================================================================
// int_queue_packet_with_timedelay
// EA  : 0x83223FB0
// RVA : 0x01223FB0
// PDB : w:\tech5\libs\mgrd\src\rd\rd.c
// ========================================================================

void __fastcall int_queue_packet_with_timedelay(RD_HEADER *header, unsigned __int16 msg, unsigned int totalsize)
{
  unsigned __int64 v5; // r3
  unsigned __int64 v6; // r8

  header->msg = msg;
  header->payload = totalsize - 24;
  header->threadid = mgthread_getid();
  LODWORD(v5) = mgtimestamp_now();
  LODWORD(v6) = 0;
  header->timestamp = v5;
  HIDWORD(v6) = &rd_state.decoder.buffer[31220];
  header->timedelay = v6;
  mgringbuf_put_with_timedelay(
    ringbuf: &rd_state.outbound,
    buffer: header,
    size: totalsize,
    timedelay: &header->timedelay);
}


// ========================================================================
// rd_msg
// EA  : 0x83224028
// RVA : 0x01224028
// PDB : w:\tech5\libs\mgrd\src\rd\rd.c
// ========================================================================

void __fastcall rd_msg(const char *text)
{
  const char *v1; // r11
  int v2; // r10
  size_t v3; // r31
  RD_HEADER v4; // [sp+50h] [-830h] BYREF
  _BYTE v5[2056]; // [sp+68h] [-818h] BYREF

  if ( rd_state.options[3] != 0 )
  {
    v1 = text;
    do
      v2 = *(unsigned __int8 *)v1++;
    while ( v2 != 0 );
    v3 = v1 - text - 1;
    if ( v3 > 0x800 )
      v3 = 2048;
    memcpy(Dst: v5, Src: text, Size: v3);
    int_queue_packet(header: &v4, msg: 3u, totalsize: v3 + 24);
  }
}


// ========================================================================
// rd_mem_heap_create
// EA  : 0x832240B0
// RVA : 0x012240B0
// PDB : w:\tech5\libs\mgrd\src\rd\rd.c
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall rd_mem_heap_create(
        RD_HEAP *heap,
        RD_HEAP *parent,
        const char *name,
        unsigned int mem,
        unsigned __int64 size)
{
  int v5; // r30 OVERLAPPED
  int v6; // r31 OVERLAPPED
  unsigned __int64 v7; // r10 OVERLAPPED
  int v8; // r11
  RD_HEADER v9; // [sp+50h] [-150h] BYREF
  unsigned __int64 v10; // [sp+68h] [-138h]
  __int64 v11; // [sp+70h] [-130h]
  unsigned __int64 v12; // [sp+78h] [-128h]
  unsigned __int64 v13; // [sp+80h] [-120h]
  char v14[264]; // [sp+88h] [-118h] BYREF

  if ( rd_state.options[2] != 0 )
  {
    v6 = 0;
    v7 = __PAIR64__(&_IMPORT_DESCRIPTOR_xam_xex_20500_0_1861, HIDWORD(heapid));
    LODWORD(size) = heapid + 10;
    v8 = heapid + 1;
    heap->id = size;
    heapid = *(unsigned __int64 *)((char *)&v7 - 4);
    v10 = size;
    if ( parent != nullptr )
      v11 = *(_QWORD *)v7;
    else
      v11 = *(_QWORD *)(&v5 - 1);
    LODWORD(v7) = HIDWORD(size);
    v12 = __PAIR64__(HIDWORD(size), mem);
    v13 = v7;
    strncpy(dest: v14, source: name, count: 0x100u);
    v14[255] = 0;
    int_queue_packet(header: &v9, msg: 0xAu, totalsize: 0x138u);
  }
}


// ========================================================================
// rd_mem_heap_destroy
// EA  : 0x83224160
// RVA : 0x01224160
// PDB : w:\tech5\libs\mgrd\src\rd\rd.c
// ========================================================================

void __fastcall rd_mem_heap_destroy(RD_HEAP *heap)
{
  RD_HEADER v1; // [sp+50h] [-30h] BYREF
  unsigned __int64 id; // [sp+68h] [-18h]

  if ( rd_state.options[2] != 0 )
  {
    id = heap->id;
    int_queue_packet(header: &v1, msg: 0xBu, totalsize: 0x20u);
  }
}


// ========================================================================
// rd_mem_alloc
// EA  : 0x832241A8
// RVA : 0x012241A8
// PDB : w:\tech5\libs\mgrd\src\rd\rd.c
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall rd_mem_alloc(
        RD_HEAP *heap,
        unsigned int ptr,
        unsigned int size,
        unsigned int waste,
        int a5,
        __int64 a6)
{
  RD_STATE *v6; // r30 OVERLAPPED
  int v7; // r31 OVERLAPPED
  unsigned int v8; // r3
  __int64 v9; // r11
  __int64 *v10; // r8
  char *v11; // r9
  __int64 v12; // r7
  unsigned int v13; // r29
  __int64 v14; // r3
  _WORD v15[2]; // [sp+50h] [-860h] BYREF
  int v16; // [sp+54h] [-85Ch]
  __int64 v17; // [sp+58h] [-858h]
  __int64 v18; // [sp+60h] [-850h]
  unsigned __int64 id; // [sp+68h] [-848h]
  unsigned __int64 v20; // [sp+70h] [-840h]
  unsigned __int64 v21; // [sp+78h] [-838h]
  __int64 v22; // [sp+80h] [-830h]
  __int64 v23; // [sp+88h] [-828h] BYREF
  void *v24; // [sp+490h] [-420h] BYREF
  char v25; // [sp+494h] [-41Ch] BYREF

  v6 = &rd_state;
  if ( rd_state.options[2] != 0 )
  {
    v7 = 0;
    id = *(_QWORD *)(&v6 - 1);
    if ( heap != nullptr )
      id = heap->id;
    *(__int64 *)((char *)&a6 - 4) = __PAIR64__(waste, size);
    v23 = *(_QWORD *)(&v6 - 1);
    v20 = __PAIR64__(size, ptr);
    v21 = __PAIR64__(waste, size);
    v22 = a6;
    v8 = rdsys_stack_traceback(buffer: &v24, max: 0x100u);
    LODWORD(v9) = v8;
    if ( v8 != 0 )
    {
      v9 = v8 - 2;
      if ( v8 != 2 )
      {
        v10 = &v23;
        v11 = &v25;
        do
        {
          v11 += 4;
          LODWORD(v12) = *(_DWORD *)v11;
          HIDWORD(v12) = ++HIDWORD(v9);
          *++v10 = v12;
        }
        while ( HIDWORD(v9) < (unsigned int)v9 );
      }
      v23 = v9;
    }
    v15[1] = 12;
    v13 = 8 * (v9 + 8);
    v15[0] = v13 - 24;
    v16 = mgthread_getid();
    LODWORD(v14) = mgtimestamp_now();
    v17 = v14;
    v18 = *(_QWORD *)(&v6 - 1);
    mgringbuf_put(ringbuf: &rd_state.outbound, buffer: v15, size: v13);
  }
}


// ========================================================================
// rd_mem_free
// EA  : 0x83224298
// RVA : 0x01224298
// PDB : w:\tech5\libs\mgrd\src\rd\rd.c
// ========================================================================

void __fastcall rd_mem_free(RD_HEAP *heap, void *ptr)
{
  unsigned __int64 id; // r11
  RD_HEADER v3; // [sp+50h] [-30h] BYREF
  unsigned __int64 v4; // [sp+68h] [-18h]
  unsigned __int64 v5; // [sp+70h] [-10h]

  HIDWORD(id) = &rd_state;
  if ( rd_state.options[2] != 0 )
  {
    LODWORD(id) = 0;
    v4 = id;
    if ( heap != nullptr )
    {
      id = heap->id;
      v4 = heap->id;
    }
    LODWORD(id) = ptr;
    v5 = id;
    int_queue_packet(header: &v3, msg: 0xDu, totalsize: 0x28u);
  }
}


// ========================================================================
// rd_event_oneshot
// EA  : 0x832242F8
// RVA : 0x012242F8
// PDB : w:\tech5\libs\mgrd\src\rd\rd.c
// ========================================================================

void __fastcall rd_event_oneshot(const char *name)
{
  size_t v1; // r31
  const char *v2; // r11
  int v3; // r10
  RD_HEADER v4; // [sp+50h] [-430h] BYREF
  _BYTE v5[1032]; // [sp+68h] [-418h] BYREF

  v1 = 0;
  if ( rd_state.options[4] != 0 )
  {
    if ( name != nullptr )
    {
      v2 = name;
      do
        v3 = *(unsigned __int8 *)v2++;
      while ( v3 != 0 );
      v1 = v2 - name;
      if ( (unsigned int)(v2 - name) > 0x3FE )
        v1 = 1022;
      memcpy(Dst: v5, Src: name, Size: v1);
    }
    v5[v1] = 0;
    int_queue_packet(header: &v4, msg: 6u, totalsize: v1 + 25);
  }
}


// ========================================================================
// rd_event_begin
// EA  : 0x83224398
// RVA : 0x01224398
// PDB : w:\tech5\libs\mgrd\src\rd\rd.c
// ========================================================================

void __fastcall rd_event_begin(const char *name)
{
  size_t v1; // r31
  const char *v2; // r11
  int v3; // r10
  RD_HEADER v4; // [sp+50h] [-430h] BYREF
  _BYTE v5[1032]; // [sp+68h] [-418h] BYREF

  v1 = 0;
  if ( rd_state.options[4] != 0 )
  {
    if ( name != nullptr )
    {
      v2 = name;
      do
        v3 = *(unsigned __int8 *)v2++;
      while ( v3 != 0 );
      v1 = v2 - name;
      if ( (unsigned int)(v2 - name) > 0x3FE )
        v1 = 1022;
      memcpy(Dst: v5, Src: name, Size: v1);
    }
    v5[v1] = 0;
    int_queue_packet_with_timedelay(header: &v4, msg: 4u, totalsize: v1 + 25);
  }
}


// ========================================================================
// rd_event_end
// EA  : 0x83224438
// RVA : 0x01224438
// PDB : w:\tech5\libs\mgrd\src\rd\rd.c
// ========================================================================

void rd_event_end()
{
  RD_HEADER v0; // [sp+50h] [-20h] BYREF

  if ( rd_state.options[4] != 0 )
    int_queue_packet(header: &v0, msg: 5u, totalsize: 0x18u);
}


// ========================================================================
// send_module_infos
// EA  : 0x83224478
// RVA : 0x01224478
// PDB : w:\tech5\libs\mgrd\src\rd\rd.c
// ========================================================================

void __fastcall send_module_infos(RD_STATE *rdstate)
{
  __int64 v1; // r28
  void *v2; // r3
  const char *v3; // r3
  const char *v4; // r25
  char *i; // r3
  __int64 v6; // r11
  char *v7; // r11
  int v8; // r9
  size_t v9; // r31
  void *v10; // r3
  unsigned int v11; // r31
  __int64 v12; // r3
  HRESULT v13; // r3
  __int64 v14; // r3
  PDM_WALK_MODULES v15[4]; // [sp+50h] [-EE0h] BYREF
  _QWORD v16[38]; // [sp+60h] [-ED0h] BYREF
  _DMN_MODLOAD v17; // [sp+190h] [-DA0h] BYREF
  _WORD v18[2]; // [sp+2C0h] [-C70h] BYREF
  int v19; // [sp+2C4h] [-C6Ch]
  __int64 v20; // [sp+2C8h] [-C68h]
  __int64 v21; // [sp+2D0h] [-C60h]
  _BYTE v22[2056]; // [sp+2D8h] [-C58h] BYREF
  char v23[1104]; // [sp+AE0h] [-450h] BYREF

  LODWORD(v1) = 0;
  memset(v16, 0, 24);
  v2 = memset(Dst: &v16[3], Val: 0, Size: 0x110u);
  v3 = (const char *)rdsys_exeimage(a1: v2);
  strncpy(dest: (char *)&v16[5], source: v3, count: 0x100u);
  LOBYTE(v16[36]) = 0;
  v15[0] = nullptr;
  v4 = (const char *)&v16[5];
  for ( i = strstr(str1: (const char *)&v16[5], str2: "\\"); i != nullptr; i = strstr(str1: i + 1, str2: "\\") )
    v4 = i + 1;
  if ( DmWalkLoadedModules(a1: v15, a2: &v17) == 47841280 )
  {
    HIDWORD(v1) = 3;
    do
    {
      if ( stricmp(Str1: v4, Str2: v17.Name) == 0 )
      {
        LODWORD(v6) = v17.BaseAddress;
        v16[4] = v6;
      }
      sprintf_0(string: v23, format: "Module: %s, Base %.8x, Size %.8x\n", v17.Name, v17.BaseAddress, v17.Size);
      if ( rd_state.options[3] != 0 )
      {
        v7 = v23;
        do
          v8 = (unsigned __int8)*v7++;
        while ( v8 != 0 );
        v9 = v7 - v23 - 1;
        if ( v9 > 0x800 )
          v9 = 2048;
        v10 = memcpy(Dst: v22, Src: v23, Size: v9);
        v11 = v9 + 24;
        v18[1] = 3;
        v18[0] = v11 - 24;
        v19 = mgthread_getid(a1: v10);
        LODWORD(v12) = mgtimestamp_now();
        v20 = v12;
        v21 = v1;
        mgringbuf_put(ringbuf: &rd_state.outbound, buffer: v18, size: v11);
      }
    }
    while ( DmWalkLoadedModules(a1: v15, a2: &v17) == 47841280 );
  }
  v13 = DmCloseLoadedModules(a1: v15[0]);
  HIDWORD(v16[0]) = 17825794;
  LODWORD(v16[0]) = mgthread_getid(a1: v13);
  LODWORD(v14) = mgtimestamp_now();
  v16[1] = v14;
  v16[2] = v1;
  mgringbuf_put(ringbuf: &rd_state.outbound, buffer: v16, size: 0x128u);
}


// ========================================================================
// int_rdthread
// EA  : 0x83224640
// RVA : 0x01224640
// PDB : w:\tech5\libs\mgrd\src\rd\rd.c
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall int_rdthread(char *ptr)
{
  _DWORD *v2; // r21
  __int64 v3; // r26
  int *v4; // r23
  char v5; // r3
  int v6; // r28
  int v7; // r29
  void *v8; // r3
  __int64 v9; // r3
  __int64 v10; // r3
  __int64 v11; // r3
  RD_STATE *v12; // r3
  unsigned int v13; // r3
  bool v14; // cr58
  signed int v15; // r5
  RD_HEADER *i; // r3
  __int64 v17; // r11 OVERLAPPED
  _DWORD *v18; // r11
  int j; // ctr
  _BYTE v21[24]; // [sp+50h] [-690h] BYREF
  __int64 v22; // [sp+68h] [-678h]
  __int64 v23; // [sp+70h] [-670h]
  _BYTE v24[512]; // [sp+80h] [-660h] BYREF
  _BYTE v25[1120]; // [sp+280h] [-460h] BYREF

  v2 = ptr + 66632;
  LODWORD(v3) = 0;
  if ( *((_DWORD *)ptr + 16658) == 0 )
  {
    v4 = (int *)(ptr + 66628);
    HIDWORD(v3) = 1;
    do
    {
      v5 = mgsocket_wait(sock: *v4, mask: 5u);
      if ( (v5 & 4) != 0 )
        break;
      if ( (v5 & 1) != 0 )
      {
        v6 = 0;
        v7 = mgsocket_accept(sock: *v4);
        if ( v7 != -1 )
        {
          mgringbuf_reset(ringbuf: (MGRINGBUF *)(ptr + 24));
          *(_WORD *)v21 = 0;
          v8 = memset(Dst: &v21[2], Val: 0, Size: 0x16u);
          v22 = v3;
          v23 = v3;
          LODWORD(v9) = mgtimestamp_frequency(a1: v8);
          v22 = v9;
          LODWORD(v10) = mgtimestamp_now();
          v23 = v10;
          *(_DWORD *)v21 = 1048577;
          *(_DWORD *)&v21[4] = mgthread_getid(a1: v10);
          LODWORD(v11) = mgtimestamp_now();
          *(_QWORD *)&v21[8] = v11;
          *(_QWORD *)&v21[16] = v3;
          mgringbuf_put(ringbuf: &rd_state.outbound, buffer: v21, size: 0x28u);
          send_module_infos(rdstate: v12);
          ++*(_DWORD *)ptr;
          do
          {
            v13 = mgringbuf_get(ringbuf: (MGRINGBUF *)(ptr + 24), buffer: v25, maxsize: 0x400u);
            if ( v13 != 0 )
            {
              v14 = mgsocket_send(sock: v7, data: v25, size: v13) == v13;
            }
            else
            {
              if ( (mgsocket_check(sock: *v4) & 4) != 0 )
              {
LABEL_19:
                v6 = 1;
              }
              else
              {
                while ( (mgsocket_check(sock: v7) & 1) != 0 )
                {
                  v15 = mgsocket_recv(sock: v7, data: v24, size: 0x200u);
                  if ( v15 <= 0 )
                    goto LABEL_19;
                  mgringbuf_put(ringbuf: (MGRINGBUF *)(ptr + 536), buffer: v24, size: v15);
                  for ( i = rd_decoder_fetch(decoder: (RD_DECODER *)(ptr + 1048));
                        i != nullptr;
                        i = rd_decoder_fetch(decoder: (RD_DECODER *)(ptr + 1048)) )
                  {
                    if ( i->msg == 14 )
                    {
                      v17 = *(_QWORD *)&i[1].payload;
                      *(__int64 *)((char *)&v17 + 4) = i[1].timestamp;
                      if ( (_DWORD)v17 != 0 && (unsigned int)v17 < 5 )
                        *(_DWORD *)&ptr[4 * v17 + 4] = HIDWORD(v17);
                    }
                  }
                }
              }
              mgthread_sleep(ms: 10);
              v14 = v6 == 0;
            }
          }
          while ( v14 );
          --*(_DWORD *)ptr;
          mgsocket_close(sock: v7);
          v18 = ptr;
          for ( j = 5; j != 0; --j )
            *++v18 = 0;
        }
      }
    }
    while ( *v2 == 0 );
  }
  *((_DWORD *)ptr + 16659) = 0;
  return 1;
}


// ========================================================================
// rd_init
// EA  : 0x83224878
// RVA : 0x01224878
// PDB : w:\tech5\libs\mgrd\src\rd\rd.c
// ========================================================================

int __fastcall rd_init(char *memory, unsigned int size, char flags)
{
  unsigned int v7; // r30
  RD_STATE *v8; // r11
  int i; // ctr

  memset(Dst: &rd_state, Val: 0, Size: sizeof(rd_state));
  if ( size < 0x2000 )
    return -214;
  v7 = size - 4096;
  mgringbuf_init(ringbuf: &rd_state.outbound, memory, size: v7);
  mgringbuf_init(ringbuf: &rd_state.inbound, memory: &memory[v7], size: 0x1000u);
  rd_decoder_init(decoder: &rd_state.decoder, ringbuf: &rd_state.inbound);
  rd_state.socket = mgsocket_createserver(listenaddr: "9999");
  if ( rd_state.socket == -1 )
    return -230;
  v8 = &rd_state;
  for ( i = 5; i != 0; --i )
  {
    v8 = (RD_STATE *)((char *)v8 + 4);
    v8->clients = 1;
  }
  if ( (flags & 1) != 0 )
    rd_state.options[1] = 0;
  rd_state.thread_running = 1;
  mgthread_create(thread: &rd_state.thread, func: (int (__fastcall *)(void *))int_rdthread, param: &rd_state);
  if ( (flags & 1) != 0 && rd_state.options[1] == 0 )
  {
    do
      mgthread_sleep(ms: 100);
    while ( rd_state.options[1] == 0 );
  }
  return 0;
}

