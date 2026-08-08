
// ========================================================================
// ?InitTagNamesTable@@YAXXZ
// EA  : 0x82F802C0
// RVA : 0x00F802C0
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

void __fastcall InitTagNamesTable()
{
  void (__fastcall **p_argCompletion)(idAutoComplete *); // r10
  int i; // ctr

  if ( tagNames[0] == nullptr )
  {
    p_argCompletion = &testRuntimeExpression_v.argCompletion_;
    for ( i = 256; i != 0; --i )
      *++p_argCompletion = (void (__fastcall *)(idAutoComplete *))"<BAD TAG NAME>";
    tagNames[0] = "UNSET";
    tagNames[1] = "STATIC_EXE";
    tagNames[2] = "RESOURCE_GRAPH";
    tagNames[3] = "DEBUG";
    tagNames[4] = "NEW";
    tagNames[5] = "IDLIST";
    tagNames[6] = "TEMP";
    tagNames[7] = "STRING";
    tagNames[8] = "ATOMIC_STRING";
    tagNames[9] = "BITARRAY";
    tagNames[10] = "MATH";
    tagNames[12] = "COMPILER";
    tagNames[11] = "LEXER";
    tagNames[13] = "COLLISION";
    tagNames[14] = "COLLISION_QUERY";
    tagNames[31] = "ANIMATION_DEBUG";
    tagNames[17] = "MD6_MISC";
    tagNames[32] = "DECL_ANIMWEB";
    tagNames[33] = "ANIMWEB";
    tagNames[34] = "IMAGE";
    tagNames[35] = "SOUND";
    tagNames[15] = "CLIPMODEL";
    tagNames[16] = "MORPH";
    tagNames[36] = "VIRTUALTEXTURE";
    tagNames[22] = "MD6_JOINTCACHE";
    tagNames[26] = "MD6_JOINTMODS";
    tagNames[37] = "AAS";
    tagNames[23] = "MD6_MESHES";
    tagNames[27] = "MD6_COLLISION";
    tagNames[39] = "SOUND_BSP";
    tagNames[28] = "MD6_ANIMEVENTS";
    tagNames[24] = "MD6_JOINTBUFFERS";
    tagNames[25] = "MD6_BLENDSTACK";
    tagNames[40] = (const char *)-2110177628;
    tagNames[38] = "SOUND";
    tagNames[29] = "MD6_PHASE_TRACK";
    tagNames[41] = (const char *)-2110177644;
    tagNames[60] = "LWO";
    tagNames[18] = "MD6_NODES";
    tagNames[19] = "MD6";
    tagNames[20] = "MD6_ANIMS";
    tagNames[21] = "MD6_LIPSYNC";
    tagNames[30] = "ANIMATION";
    tagNames[42] = "SOUND_MULTISTREAM";
    tagNames[61] = "RENDERWORLD";
    tagNames[43] = (const char *)-2110177684;
    tagNames[44] = (const char *)-2110177692;
    tagNames[63] = "AI_GAMESTATE";
    tagNames[46] = "DECL";
    tagNames[47] = "DECLTEXT";
    tagNames[64] = "EVENTS";
    tagNames[66] = "VOICETRACK_EVENTS";
    tagNames[62] = "RENDERER";
    tagNames[49] = "CVAR";
    tagNames[45] = (const char *)-2110177704;
    tagNames[67] = "VOICETRACK_FRAMEREFS";
    tagNames[69] = "VISEMESET_VISEMES";
    tagNames[50] = "PAGEFILECACHE";
    tagNames[52] = "PRESENTABLE";
    tagNames[65] = "VOICEOVER";
    tagNames[70] = "VISEMESET_PHONEMES";
    tagNames[48] = "FILE";
    tagNames[72] = "SWF";
    tagNames[53] = "FOLIAGE";
    tagNames[55] = (const char *)&unk_82397D84;
    tagNames[68] = "VOICETRACK_PHONEMES";
    tagNames[73] = "GUI";
    tagNames[51] = "IDCLASS";
    tagNames[75] = "FUNC_CALLBACK";
    tagNames[56] = "ut string";
    tagNames[54] = "WATER";
    tagNames[71] = "AF";
    tagNames[76] = "MENU";
    tagNames[78] = "HASHINDEX";
    tagNames[74] = "GUI_MODEL";
    tagNames[79] = "PARTICLE";
    tagNames[77] = "GAME";
    tagNames[57] = "NETWORKING";
    tagNames[58] = "SCRIPT";
    tagNames[59] = "FXPHYSICS";
    tagNames[80] = "EFFECT_PARTICLE";
    tagNames[81] = "CLOTH";
    tagNames[82] = "ANIMTAGS";
    tagNames[83] = "IK";
    tagNames[84] = "STATICMODEL";
    tagNames[85] = "RENDERMODEL";
    tagNames[86] = "DXBUFFER";
    tagNames[87] = "TOOLS";
    tagNames[88] = "CLOUD";
    tagNames[89] = "AMQP";
    tagNames[90] = "RENDERPROG";
    tagNames[91] = "HASHTABLE";
    tagNames[92] = "AI_FSM";
    tagNames[94] = "AI_SEARCH";
    tagNames[93] = "AI_VISCACHE";
    tagNames[95] = "AI_OBSTACLE";
    tagNames[97] = "TRANSPARENCY";
    tagNames[96] = "JOBLIST";
    tagNames[99] = "RESOURCE";
    tagNames[98] = "DETAIL";
    tagNames[101] = "RESOURCE_BGL";
    tagNames[102] = "AI_COMBATANIM";
    tagNames[100] = "FILE_RESOURCE";
    tagNames[103] = "RESOURCE_BGL_OVERSIZE";
    tagNames[104] = "RESOURCE_MGR";
    tagNames[105] = "PVS";
    tagNames[106] = "DEFERRED_VIS";
    tagNames[107] = "FIBER";
    tagNames[108] = "SUPERSCRIPT";
    tagNames[109] = "FX";
    tagNames[110] = "SAVEGAMES";
    tagNames[111] = "AI_TRANSITIONS";
    tagNames[112] = "AI_FSM";
    tagNames[113] = "AI_COMBATANIM";
    tagNames[114] = "JOBLIST";
    tagNames[115] = "DETAIL";
    tagNames[125] = "DXOBJECT";
    tagNames[128] = "D3D";
    tagNames[116] = "TABLE";
    tagNames[118] = "NAVPOWER";
    tagNames[120] = "SPLINE";
    tagNames[121] = "BINK";
    tagNames[122] = "FONTS";
    tagNames[123] = "EVENT_LISTENER";
    tagNames[117] = "VIDEO";
    tagNames[124] = "PHYSICAL_BLOCK";
    tagNames[129] = "D3DX";
    tagNames[130] = "XAUDIO";
    tagNames[131] = "XAPI";
    tagNames[132] = "XACT";
    tagNames[133] = "XBOXKERNEL";
    tagNames[134] = "XBDM";
    tagNames[135] = "XGRAPHICS";
    tagNames[119] = "LANGDICT";
    tagNames[136] = "XONLINE";
    tagNames[137] = "XVOICE";
    tagNames[138] = "XHV";
    tagNames[140] = "LANGDICT";
    tagNames[139] = "USB";
    tagNames[141] = (const char *)&unk_823976C0;
    tagNames[142] = "XUI";
    tagNames[143] = "XASYNC";
    tagNames[144] = "XCAM";
    tagNames[145] = "XVIS";
    tagNames[146] = "XIME";
    tagNames[147] = "XFILECACHE";
    tagNames[148] = "XRN";
    tagNames[151] = "XAUDIO2";
  }
}


// ========================================================================
// ?GetMemTagName@@YAPBDH@Z
// EA  : 0x82F80F38
// RVA : 0x00F80F38
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

const char *__fastcall GetMemTagName(const int tagNum)
{
  InitTagNamesTable();
  return tagNames[tagNum];
}


// ========================================================================
// ?listMemTags_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F80F78
// RVA : 0x00F80F78
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

void __fastcall listMemTags_f(const idCmdArgs *args)
{
  __int64 v1; // r8
  __int64 v2; // r6
  __int64 v3; // r10
  unsigned int v4; // r30
  const char **v5; // r31
  int v6; // [sp+8h] [-78h]
  int v7; // [sp+Ch] [-74h]
  int v8; // [sp+10h] [-70h]
  int v9; // [sp+14h] [-6Ch]

  InitTagNamesTable();
  LODWORD(v3) = &unk_82390000;
  v4 = 0;
  v5 = tagNames;
  do
  {
    if ( *v5 != "<BAD TAG NAME>" )
    {
      HIDWORD(v2) = *v5;
      idLib::Printf(fmt: __SPAIR64__("%3i %s\n", v4), a2: v2, a3: v1, a4: v3, a5: v6, a6: v7, a7: v8, a8: v9);
    }
    ++v5;
    ++v4;
  }
  while ( (int)v5 < (int)&mem );
}


// ========================================================================
// ?Print@overlayAllocator_t@@QAAXXZ
// EA  : 0x82F80FE0
// RVA : 0x00F80FE0
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall overlayAllocator_t::Print(overlayAllocator_t *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // r4
  __int64 v6; // r10
  __int64 v7; // r8
  int v8; // r30
  unsigned __int8 **p_base; // r31
  __int64 v10; // r6
  __int64 v11; // r4
  int v12; // [sp+8h] [-78h]
  int v13; // [sp+8h] [-78h]
  int v14; // [sp+Ch] [-74h]
  int v15; // [sp+Ch] [-74h]
  int v16; // [sp+10h] [-70h]
  int v17; // [sp+10h] [-70h]
  int v18; // [sp+14h] [-6Ch]
  int v19; // [sp+14h] [-6Ch]

  HIDWORD(v5) = "Overlay Block\n";
  idLib::Printf(fmt: v5, a2: a3, a3: a4, a4: a5, a5: v12, a6: v14, a7: v16, a8: v18);
  v8 = 0;
  if ( oa.numOverlayBlocks > 0 )
  {
    LODWORD(v6) = ", AI_HEALTH_HITPOINTS >";
    p_base = &oa.blocks[0].base;
    do
    {
      HIDWORD(v7) = p_base - 8;
      if ( *((_BYTE *)p_base - 32) == 0 )
        HIDWORD(v7) = "FREE";
      LODWORD(v10) = p_base[1];
      HIDWORD(v11) = "0x%08x - 0x%08x : %9i %s\n";
      LODWORD(v11) = *p_base;
      HIDWORD(v10) = &(*p_base)[v10];
      idLib::Printf(fmt: v11, a2: v10, a3: v7, a4: v6, a5: v13, a6: v15, a7: v17, a8: v19);
      ++v8;
      p_base += 10;
    }
    while ( v8 < oa.numOverlayBlocks );
  }
}


// ========================================================================
// ?BytesCurrentlyAllocated@idMem@@QAAHXZ
// EA  : 0x82F81068
// RVA : 0x00F81068
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

// attributes: thunk
unsigned int __fastcall idMem::BytesCurrentlyAllocated(idMem *this)
{
  return Sys_GetMemoryUsage();
}


// ========================================================================
// ?ResetMapHeap@idMem@@QAAXXZ
// EA  : 0x82F81070
// RVA : 0x00F81070
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

void __fastcall idMem::ResetMapHeap(idMem *this)
{
  idMemLocal::ResetMapHeap(this: &memLocal);
}


// ========================================================================
// ?PushHeap@idMem@@QAAXW4heapType_t@@@Z
// EA  : 0x82F81080
// RVA : 0x00F81080
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

void __fastcall idMem::PushHeap(idMem *this, heapType_t heapType)
{
  idMemLocal::PushHeap(this: &memLocal, heapType);
}


// ========================================================================
// ?PopHeap@idMem@@QAAXXZ
// EA  : 0x82F81090
// RVA : 0x00F81090
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

void __fastcall idMem::PopHeap(idMem *this)
{
  idMemLocal::PopHeap(this: &memLocal);
}


// ========================================================================
// ?InitMapHeap@idMem@@QAAXXZ
// EA  : 0x82F810A0
// RVA : 0x00F810A0
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

void __fastcall idMem::InitMapHeap(idMem *this)
{
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&memLocal);
}


// ========================================================================
// ?IsGlobalHeap@idMem@@QBA_NXZ
// EA  : 0x82F810B0
// RVA : 0x00F810B0
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

int __fastcall idMem::IsGlobalHeap(idMem *this)
{
  unsigned __int8 v1; // r11

  if ( memLocal.mapHeap == nullptr )
    return 1;
  v1 = 0;
  if ( memLocal.currentHeap != memLocal.mapHeap )
    return 1;
  return v1;
}


// ========================================================================
// ?AllocWithLocation@idMemLocal@@QAAPAXPBDIW4memTag_t@@_NW4align_t@@W4heapType_t@@@Z
// EA  : 0x82F810E0
// RVA : 0x00F810E0
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

void *__fastcall idMemLocal::AllocWithLocation(
        idMemLocal *this,
        const char *location,
        unsigned int size,
        memTag_t tag,
        bool zeroBuffer,
        align_t align,
        heapType_t heap)
{
  unsigned int v9; // r29
  void *i; // r31
  unsigned __int8 (*oomCallback)(void); // r11
  unsigned int v16; // r11
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  int v21; // [sp+8h] [-98h]
  int v22; // [sp+Ch] [-94h]
  int v23; // [sp+10h] [-90h]
  int v24; // [sp+14h] [-8Ch]

  v9 = size;
  if ( align == ALIGN_128 )
    v9 = size + 128;
  for ( i = Sys_Alloc(size: v9, tag, align, overrideHeap: heap);
        i == nullptr;
        i = Sys_Alloc(size: v9, tag, align, overrideHeap: heap) )
  {
    oomCallback = (unsigned __int8 (*)(void))this->oomCallback;
    if ( oomCallback == nullptr || oomCallback() == 0 )
    {
      Sys_DumpMemory();
      if ( Sys_AllocWillUseMapHeap() )
        LODWORD(v20) = ", (mapheap)";
      else
        LODWORD(v20) = &byte_8200D768;
      HIDWORD(v20) = v9;
      idLib::FatalError(
        fmt: __SPAIR64__("AllocWithLocation( %s, size: %i%s) failed", (unsigned int)location),
        a2: v20,
        a3: v19,
        a4: v18,
        a5: v21,
        a6: v22,
        a7: v23,
        a8: v24);
      JUMPOUT(0x82F81224);
    }
  }
  ++this->numAllocs;
  if ( zeroBuffer )
    memset(Dst: i, Val: 0, Size: v9);
  if ( align == ALIGN_128 )
  {
    v16 = ((unsigned int)i + 143) & 0xFFFFFF80;
    *(_DWORD *)(v16 - 16) = v16 - (_DWORD)i;
    *(_DWORD *)(v16 - 12) = 305419896;
    i = (void *)v16;
    *(_DWORD *)(v16 - 8) = -2023406815;
    *(_DWORD *)(v16 - 4) = 1431655765;
  }
  return i;
}


// ========================================================================
// ?reportMemoryAllocations_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F81228
// RVA : 0x00F81228
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

void __fastcall reportMemoryAllocations_f(
        __int64 args,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  HIDWORD(args) = "The exe must be recompiled with TRACK_MEMORY_ALLOCATION_LOCATIONS set to 1 or 2\n";
  idLib::Printf(fmt: args, a2, a3, a4, a5, a6, a7, a8);
}


// ========================================================================
// ?Init@overlayAllocator_t@@QAAXPAXH@Z
// EA  : 0x82F81238
// RVA : 0x00F81238
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

void __fastcall overlayAllocator_t::Init(overlayAllocator_t *this, unsigned __int8 *base, __int64 numBytes, __int64 a4)
{
  __int64 v4; // r10
  int v7; // r28
  int v8; // [sp+8h] [-78h]
  int v9; // [sp+Ch] [-74h]
  int v10; // [sp+10h] [-70h]
  int v11; // [sp+14h] [-6Ch]

  LODWORD(v4) = &unk_821C0000;
  HIDWORD(v4) = &unk_82390000;
  v7 = HIDWORD(numBytes);
  idLib::Printf(
    fmt: COERCE__INT64((float)((float)__SPAIR64__(&unk_821C0000, HIDWORD(numBytes)) * (float)0.00000095367432)),
    a2: numBytes,
    a3: a4,
    a4: v4,
    a5: v8,
    a6: v9,
    a7: v10,
    a8: v11);
  Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
  this->blocks[0].base = base;
  this->numOverlayBlocks = 1;
  this->blocks[0].numBytes = v7;
  this->blocks[0].name[0] = 0;
  Sys_MutexUnlock(handle: &this->mutex.handle);
}


// ========================================================================
// ?AllocWithLocation@idMem@@QAAPAXPBDIW4memTag_t@@_NW4align_t@@W4heapType_t@@@Z
// EA  : 0x82F812C0
// RVA : 0x00F812C0
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

void *__fastcall idMem::AllocWithLocation(
        idMem *this,
        const char *location,
        unsigned int size,
        memTag_t tag,
        bool zeroBuffer,
        align_t align,
        heapType_t heap)
{
  return idMemLocal::AllocWithLocation(this: &memLocal, location, size, tag, zeroBuffer, align, heap);
}


// ========================================================================
// ?Free@idMem@@QAAXPAXW4align_t@@@Z
// EA  : 0x82F812D0
// RVA : 0x00F812D0
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

void __fastcall idMem::Free(idMem *this, _DWORD *ptr, align_t align)
{
  char *v3; // r3

  v3 = (char *)ptr;
  if ( ptr != nullptr )
  {
    if ( align == ALIGN_128 )
      v3 = (char *)ptr - *(ptr - 4);
    Sys_Free(ptr: v3);
  }
}


// ========================================================================
// ?SetOutOfMemoryCallback@idMem@@QAAXP6A_NXZ@Z
// EA  : 0x82F812F8
// RVA : 0x00F812F8
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

void __fastcall idMem::SetOutOfMemoryCallback(idMem *this, bool (__fastcall *func)())
{
  memLocal.oomCallback = func;
}


// ========================================================================
// ?GetOutOfMemoryCallback@idMem@@QAAP6A_NXZXZ
// EA  : 0x82F81308
// RVA : 0x00F81308
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

bool (__fastcall *__fastcall idMem::GetOutOfMemoryCallback(idMem *this))()
{
  return memLocal.oomCallback;
}


// ========================================================================
// ?WriteMemoryReport@idMem@@QAAXPBD0@Z
// EA  : 0x82F81318
// RVA : 0x00F81318
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

void __fastcall idMem::WriteMemoryReport(idMem *this, const char *mapName, const char *version)
{
  Sys_WriteMemoryReport(mapName, version);
}


// ========================================================================
// ?sys_dumpMemory_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F81328
// RVA : 0x00F81328
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

// attributes: thunk
void __fastcall sys_dumpMemory_f(const idCmdArgs *args)
{
  Sys_DumpMemory();
}


// ========================================================================
// ?sys_testAllocPerf_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82F81330
// RVA : 0x00F81330
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall sys_testAllocPerf_f(const idCmdArgs *args)
{
  int v1; // r30
  int *v2; // r26
  int i; // r31
  int v4; // r22
  unsigned __int64 v5; // r4
  double v6; // fp1
  __int128 v7; // r5 OVERLAPPED
  int v8; // r6
  __int64 v9; // r10
  __int64 v10; // r8
  void **v11; // r31
  int j; // r30
  int v13; // [sp+8h] [-2B8h]
  int v14; // [sp+Ch] [-2B4h]
  int v15; // [sp+10h] [-2B0h]
  int v16; // [sp+14h] [-2ACh]
  int v17; // [sp+4Ch] [-274h] BYREF
  _DWORD v18[130]; // [sp+50h] [-270h] BYREF

  v1 = 0;
  memset(v18, 0, 512);
  v2 = &v17;
  for ( i = 0; i < 128; ++i )
  {
    v1 = 1103515245 * v1 + 12345;
    v4 = Sys_Microseconds() >> 32;
    *++v2 = (int)idMemLocal::AllocWithLocation(
                   this: &memLocal,
                   location: "w:\\tech5\\shared\\idlib\\sys\\sys_alloc.cpp(783) : TAG_TEMP",
                   size: ((v1 >> 16) & 0x7FFFu) % 0x4001 + 49152,
                   tag: TAG_TEMP,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
    v5 = Sys_Microseconds();
    v6 = _u64tod(a1: HIDWORD(v5) - v4, a2: v5);
    DWORD1(v7) = "%3d: %1.1f msec to allocate %d kB\n";
    v8 = (int)(((v1 >> 16) & 0x7FFFu) % 0x4001 + 49152) >> 10;
    *((double *)&v7 + 1) = (float)((float)v6 * (float)0.001);
    idLib::Printf(
      fmt: *(__int64 *)((char *)&v7 + 4),
      a2: *(__int64 *)((char *)&v7 - 4),
      a3: v10,
      a4: v9,
      a5: v13,
      a6: v14,
      a7: v15,
      a8: v16);
  }
  v11 = (void **)v18;
  for ( j = 128; j != 0; --j )
  {
    if ( *v11 != nullptr )
      Sys_Free(ptr: *v11);
    ++v11;
  }
}


// ========================================================================
// `dynamic initializer for 'oa''
// EA  : 0x83396A58
// RVA : 0x01396A58
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__oa__()
{
  Sys_MutexCreate(handle: (_RTL_CRITICAL_SECTION **)&oa.mutex);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__oa__);
}


// ========================================================================
// `dynamic initializer for 'memLocal''
// EA  : 0x83396A90
// RVA : 0x01396A90
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__memLocal__()
{
  Sys_MutexCreate(handle: (_RTL_CRITICAL_SECTION **)&memLocal.idMemMutex);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__memLocal__);
}


// ========================================================================
// `dynamic initializer for 'listMemTags_v''
// EA  : 0x83396AC8
// RVA : 0x01396AC8
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__listMemTags_v__()
{
  return idCommandLink::idCommandLink(
           this: &listMemTags_v,
           cmdName: "listMemTags",
           function: listMemTags_f,
           description: "lists the TAG_* names for each numeric value",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'reportMemoryAllocations_v''
// EA  : 0x83396AF0
// RVA : 0x01396AF0
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__reportMemoryAllocations_v__()
{
  return idCommandLink::idCommandLink(
           this: &reportMemoryAllocations_v,
           cmdName: "reportMemoryAllocations",
           function: (void (__fastcall *)(const idCmdArgs *))reportMemoryAllocations_f,
           description: "Reports on all the current memory allocations",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'sys_dumpMemory_v''
// EA  : 0x83396B18
// RVA : 0x01396B18
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__sys_dumpMemory_v__()
{
  return idCommandLink::idCommandLink(
           this: &sys_dumpMemory_v,
           cmdName: "sys_dumpMemory",
           function: sys_dumpMemory_f,
           description: "Walks the heap and reports stats",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'sys_testAllocPerf_v''
// EA  : 0x83396B40
// RVA : 0x01396B40
// PDB : w:\tech5\shared\idlib\sys\sys_alloc.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__sys_testAllocPerf_v__()
{
  return idCommandLink::idCommandLink(
           this: &sys_testAllocPerf_v,
           cmdName: "sys_testAllocPerf",
           function: sys_testAllocPerf_f,
           description: "Test allocation performance",
           argCompletion: nullptr);
}

