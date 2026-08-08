
// ========================================================================
// ?EnableStreamFileLog_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826A6260
// RVA : 0x006A6260
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

void __fastcall EnableStreamFileLog_f(const idCmdArgs *args)
{
  streamFileLog.maxEntries = 0x4000;
  streamFileLog.entries = (sflEntry_t *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\engine\\framework\\StreamFileLog.cpp(31) : TAG_PAGEFILECACHE",
                                          size: 0xC0000u,
                                          tag: TAG_PAGEFILECACHE,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
}


// ========================================================================
// ?NoteFrame@idStreamFileLog@@QAAXXZ
// EA  : 0x826A62C8
// RVA : 0x006A62C8
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

void __fastcall idStreamFileLog::NoteFrame(idStreamFileLog *this)
{
  idSysMutex *p_mutex; // r29
  __int64 v3; // r11
  sflEntry_t *entries; // r9
  char *v5; // r30
  __int64 v6; // r3

  if ( this->entries != nullptr )
  {
    p_mutex = &this->mutex;
    Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
    LODWORD(v3) = 0;
    entries = this->entries;
    HIDWORD(v3) = (this->maxEntries - 1) & this->numEntries++;
    HIDWORD(v3) *= 48;
    v5 = (char *)entries + HIDWORD(v3);
    *((_DWORD *)v5 + 2) = 2;
    *((_DWORD *)v5 + 3) = 0;
    *((_DWORD *)v5 + 4) = 0;
    *((_QWORD *)v5 + 3) = v3;
    *((_QWORD *)v5 + 4) = v3;
    *((_DWORD *)v5 + 10) = 0;
    LODWORD(v6) = Sys_Microseconds() >> 32;
    *(_QWORD *)v5 = v6;
    Sys_MutexUnlock(handle: &p_mutex->handle);
  }
}


// ========================================================================
// __unwind$219364
// EA  : 0x826A6360
// RVA : 0x006A6360
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

void _unwind_219364()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 128 + 80));
}


// ========================================================================
// ?NoteCacheLineRequest@idStreamFileLog@@QAAXQBVidFile@@HH@Z
// EA  : 0x826A6390
// RVA : 0x006A6390
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idStreamFileLog::NoteCacheLineRequest(
        idStreamFileLog *this,
        const idFile *const f,
        const int fileLine,
        const int priority)
{
  idSysMutex *p_mutex; // r29
  int numEntries; // r11
  __int64 v10; // r7
  __int64 v11; // r9
  __int64 v12; // r6 OVERLAPPED
  int v13; // r10
  int v14; // r7
  void **p_handle; // r3
  int v16; // r30
  __int64 v17; // r3

  if ( this->entries != nullptr )
  {
    p_mutex = &this->mutex;
    Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
    numEntries = this->numEntries;
    LODWORD(v10) = fileLine;
    LODWORD(v11) = this->maxEntries - 1;
    HIDWORD(v11) = this->entries;
    v12 = v10 << 16;
    v13 = 48 * (HIDWORD(v12) & v11) + HIDWORD(v11);
    if ( *(_DWORD *)(v13 + 8) == 2
      && *(const idFile *const *)(v13 + 16) == f
      && (*(__int64 *)((char *)&v12 - 4) = *(_QWORD *)(v13 + 24), v14 == (_DWORD)v12)
      && *(_DWORD *)(v13 + 40) == priority )
    {
      p_handle = &p_mutex->handle;
    }
    else
    {
      this->numEntries = numEntries + 1;
      HIDWORD(v12) = 2;
      v16 = 48 * (numEntries & v11) + HIDWORD(v11);
      LODWORD(v11) = 0;
      *(_DWORD *)(v16 + 8) = 2;
      *(_DWORD *)(v16 + 12) = 0;
      *(_DWORD *)(v16 + 16) = f;
      *(_QWORD *)(v16 + 24) = v12;
      *(_QWORD *)(v16 + 32) = v11;
      *(_DWORD *)(v16 + 40) = priority;
      LODWORD(v17) = Sys_Microseconds() >> 32;
      *(_QWORD *)v16 = v17;
      p_handle = &p_mutex->handle;
    }
    Sys_MutexUnlock(handle: p_handle);
  }
}


// ========================================================================
// __unwind$219403_0
// EA  : 0x826A648C
// RVA : 0x006A648C
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

void _unwind_219403_0()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 144 + 80));
}


// ========================================================================
// ?BeginIO@idStreamFileLog@@QAAXW4sflDrive_t@@W4sflIO_t@@QBVidFile@@_J3H@Z
// EA  : 0x826A64C0
// RVA : 0x006A64C0
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idStreamFileLog::BeginIO(
        idStreamFileLog *this,
        const sflDrive_t drive,
        sflIO_t io,
        const idFile *const f,
        const __int64 ofs,
        const __int64 len,
        const int priority)
{
  int v7; // r23 OVERLAPPED
  unsigned __int64 v12; // r25 OVERLAPPED
  idSysMutex *p_mutex; // r29
  __int32 v14; // r10
  int v15; // r30
  __int64 v16; // r3

  v7 = HIDWORD(len);
  this->driveState[drive] = io;
  v12 = __PAIR64__(ofs, HIDWORD(ofs));
  if ( this->entries != nullptr )
  {
    p_mutex = &this->mutex;
    Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
    v14 = 4 * (drive + 7);
    *(int *)((char *)&this->numEntries + v14) = (int)&this->entries[(this->maxEntries - 1) & this->numEntries++];
    v15 = *(int *)((char *)&this->numEntries + v14);
    *(_DWORD *)(v15 + 8) = drive;
    *(_DWORD *)(v15 + 12) = io;
    *(_DWORD *)(v15 + 16) = f;
    *(_QWORD *)(v15 + 24) = v12;
    *(_QWORD *)(v15 + 32) = *(unsigned __int64 *)((char *)&v12 + 4);
    *(_DWORD *)(v15 + 40) = v7;
    LODWORD(v16) = Sys_Microseconds() >> 32;
    *(_QWORD *)v15 = v16;
    Sys_MutexUnlock(handle: &p_mutex->handle);
  }
}


// ========================================================================
// __unwind$219451
// EA  : 0x826A6588
// RVA : 0x006A6588
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

void _unwind_219451()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 176 + 80));
}


// ========================================================================
// ?EndIO@idStreamFileLog@@QAAXW4sflDrive_t@@@Z
// EA  : 0x826A65B8
// RVA : 0x006A65B8
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

void __fastcall idStreamFileLog::EndIO(idStreamFileLog *this, const sflDrive_t drive)
{
  __int32 v2; // r27
  int v4; // r8
  idSysMutex *p_mutex; // r28
  sflEntry_t *entries; // r9
  int v7; // r11
  int v8; // ctr
  _QWORD *v9; // r10
  sflEntry_t *v10; // r29
  int *p_priority; // r11
  __int64 v12; // r3

  v2 = 4 * (drive + 7);
  v4 = *(int *)((char *)&this->numEntries + v2);
  this->driveState[drive] = SFL_IDLE;
  if ( v4 != 0 )
  {
    p_mutex = &this->mutex;
    Sys_MutexLock(handle: &this->mutex.handle, blocking: true);
    entries = this->entries;
    v7 = (this->maxEntries - 1) & this->numEntries++;
    v8 = 6;
    v9 = (_QWORD *)(*(int *)((char *)&this->numEntries + v2) - 8);
    v10 = &entries[v7];
    p_priority = &v10[-1].priority;
    do
    {
      ++v9;
      p_priority += 2;
      *(_QWORD *)p_priority = *v9;
      --v8;
    }
    while ( v8 != 0 );
    v10->io = SFL_IDLE;
    LODWORD(v12) = Sys_Microseconds() >> 32;
    v10->microseconds = v12;
    *(int *)((char *)&this->numEntries + v2) = 0;
    Sys_MutexUnlock(handle: &p_mutex->handle);
  }
}


// ========================================================================
// __unwind$219489
// EA  : 0x826A6670
// RVA : 0x006A6670
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

void _unwind_219489()
{
  int v0; // r12

  idScopedCriticalSection::~idScopedCriticalSection(this: (idScopedCriticalSection *)(v0 - 144 + 80));
}


// ========================================================================
// ?Report@idStreamFileLog@@QAAXXZ
// EA  : 0x826A66A0
// RVA : 0x006A66A0
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

void __fastcall idStreamFileLog::Report(idStreamFileLog *this)
{
  unsigned int v2; // r30
  int numEntries; // r5
  int i; // r28
  int v5; // r29
  sflEntry_t *entries; // r8
  int v7; // r7
  sflEntry_t *v8; // r30
  int drive; // r6
  int v10; // r10
  sflEntry_t *v11; // r11
  bool v12; // cr58
  __int64 v13; // r10
  int v14; // r11
  const char *v15; // r3
  __int64 ofs; // r8
  __int64 v17; // r6
  int priority; // r7
  bool v19; // zf
  double v20; // [sp+18h] [-1A8h]
  double v21; // [sp+18h] [-1A8h]
  idStr v22; // [sp+50h] [-170h] BYREF
  __int64 v23; // [sp+70h] [-150h]
  idStr v24; // [sp+80h] [-140h] BYREF
  _QWORD v25[8]; // [sp+A0h] [-120h] BYREF
  idStr v26; // [sp+E0h] [-E0h] BYREF

  if ( this->entries != nullptr )
  {
    v2 = (((unsigned int)(this->numEntries - this->maxEntries) >> 31) - 1) & (this->numEntries - this->maxEntries);
    `eh vector constructor iterator'(
      ptr: v25,
      size: 0x20u,
      count: 5,
      pCtor: (void (__fastcall *)(void *))idZippedFile::idZippedFile,
      pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
    numEntries = this->numEntries;
    for ( i = v2; i < this->numEntries; ++i )
    {
      v5 = 0;
      entries = this->entries;
      v7 = this->maxEntries - 1;
      v8 = &entries[v7 & i];
      drive = v8->drive;
      if ( drive > 1 || v8->io != SFL_IDLE )
        goto LABEL_13;
      v10 = i + 1;
      v11 = nullptr;
      v12 = i + 1 == numEntries;
      if ( i + 1 < numEntries )
      {
        do
        {
          v11 = &entries[v7 & v10];
          if ( v11->drive == drive )
            break;
          ++v10;
        }
        while ( v10 < numEntries );
        v12 = v10 == numEntries;
      }
      if ( v12 || (v5 = LODWORD(v11->microseconds) - LODWORD(v8->microseconds)) >= 1000 )
      {
LABEL_13:
        if ( drive != 2 || v8->f != nullptr )
        {
          idStr::Format(this: &v26, fmt: "                          ");
          v14 = v8->drive;
          if ( v14 > 1 || v8->io != SFL_IDLE )
          {
            v15 = v8->f->GetName(this: v8->f);
            idStr::idStr(this: &v24, text: v15);
            v22.allocedAndFlag = 20;
            v22.data = v22.baseBuffer;
            v22.len = 0;
            v22.baseBuffer[0] = 0;
            idStr::ExtractFileBase(this: &v24, dest: &v22);
            ofs = v8->ofs;
            HIDWORD(ofs) = v8->io;
            v17 = ofs >> 16;
            v19 = HIDWORD(ofs) == 2;
            priority = -1;
            if ( !v19 )
              priority = v8->priority;
            idStr::Format(this: (idStr *)&v25[4 * v8->drive], fmt: "%16s:%5i p%2i", v22.data, (_DWORD)v17, priority);
            idStr::FreeData(this: &v22);
            idStr::FreeData(this: &v24);
          }
          else
          {
            LODWORD(v13) = v5;
            v23 = v13;
            idStr::Format(this: (idStr *)&v25[4 * v14], fmt: "      idle for %4.1fms     ", (double)v13 * 0.001);
          }
          v21 = (float)((float)v8->microseconds * (float)0.001);
          idLib::Printf(fmt: (const char *)HIDWORD(v21), LODWORD(v21), v26.data, LODWORD(v25[0]), LODWORD(v25[4]));
        }
        else
        {
          v20 = (float)((float)v8->microseconds * (float)0.001);
          idLib::Printf(fmt: (const char *)HIDWORD(v20), LODWORD(v20));
        }
      }
      numEntries = this->numEntries;
    }
    `eh vector destructor iterator'(
      ptr: v25,
      size: 0x20u,
      count: 5,
      pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  }
  else
  {
    idLib::Printf(fmt: "StreamFileLog is not enabled\n");
  }
}


// ========================================================================
// __unwind$219559_0
// EA  : 0x826A697C
// RVA : 0x006A697C
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

void _unwind_219559_0()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(v0 - 448 + 160),
    size: 0x20u,
    count: 5,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// __unwind$219560_0
// EA  : 0x826A69B4
// RVA : 0x006A69B4
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

void _unwind_219560_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 128));
}


// ========================================================================
// __unwind$219561
// EA  : 0x826A69DC
// RVA : 0x006A69DC
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

void _unwind_219561()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 80));
}


// ========================================================================
// ?ReportStreamFileLog_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826A6A08
// RVA : 0x006A6A08
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

void __fastcall ReportStreamFileLog_f(const idCmdArgs *args)
{
  idStreamFileLog::Report(this: &streamFileLog);
}


// ========================================================================
// `dynamic initializer for 'streamFileLog''
// EA  : 0x8333CD28
// RVA : 0x0133CD28
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__streamFileLog__()
{
  Sys_MutexCreate(handle: (_RTL_CRITICAL_SECTION **)&streamFileLog.mutex);
  streamFileLog.driveState[0] = SFL_IDLE;
  streamFileLog.driveState[1] = SFL_IDLE;
  streamFileLog.driveState[2] = SFL_IDLE;
  streamFileLog.currentEntry[0] = nullptr;
  streamFileLog.currentEntry[1] = nullptr;
  streamFileLog.currentEntry[2] = nullptr;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__streamFileLog__);
}


// ========================================================================
// `dynamic initializer for 'EnableStreamFileLog_v''
// EA  : 0x8333CD90
// RVA : 0x0133CD90
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__EnableStreamFileLog_v__()
{
  return idCommandLink::idCommandLink(
           this: &EnableStreamFileLog_v,
           cmdName: "EnableStreamFileLog",
           function: EnableStreamFileLog_f,
           description: "Allocate memory for the stream file log",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ReportStreamFileLog_v''
// EA  : 0x8333CDB8
// RVA : 0x0133CDB8
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ReportStreamFileLog_v__()
{
  return idCommandLink::idCommandLink(
           this: &ReportStreamFileLog_v,
           cmdName: "ReportStreamFileLog",
           function: ReportStreamFileLog_f,
           description: "Dump the recorded stream file log information",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TestStreamFileLog_v''
// EA  : 0x8333CDE0
// RVA : 0x0133CDE0
// PDB : w:\tech5\engine\framework\streamfilelog.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestStreamFileLog_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestStreamFileLog_v,
           cmdName: "TestStreamFileLog",
           function: (void (__fastcall *)(const idCmdArgs *))idPhysics_StaticMulti::UpdateTime,
           description: "Flushes all caches and logs the events to bring everything in",
           argCompletion: nullptr);
}

