
// ========================================================================
// ??1idPLogScope@@QAA@XZ
// EA  : 0x825D5778
// RVA : 0x005D5778
// PDB : w:\tech5\shared\idlib\metrics\plog.h
// ========================================================================

void __fastcall idPLogScope::~idPLogScope(idPLogScope *this)
{
  idPLog::logEntry_t *v2; // r31
  __int128 v3; // r5
  int parent; // r6

  if ( this->logIndex >= 0 )
  {
    v2 = &this->pLog->logEntries.list[this->logIndex];
    *(_QWORD *)((char *)&v3 + 4) = Sys_GetClockTicks();
    parent = v2->parent;
    LODWORD(v3) = DWORD1(v3) - LODWORD(v2->totalTicks);
    v2->totalTicks = v3;
    this->pLog->lastEntry = parent;
    this->logIndex = -1;
  }
}


// ========================================================================
// ??0idPLogScope@@QAA@AAVidPLog@@_KPBD@Z
// EA  : 0x825D91F0
// RVA : 0x005D91F0
// PDB : w:\tech5\shared\idlib\metrics\plog.h
// ========================================================================

idPLogScope *__fastcall idPLogScope::idPLogScope(
        idPLogScope *this,
        idPLog *pl,
        unsigned __int64 gMask,
        const char *label)
{
  const char *v6; // r29
  idPLog::logEntry_t *v7; // r27
  int v8; // r11
  __int64 v9; // r3

  this->pLog = pl;
  this->logIndex = -1;
  v6 = (const char *)gMask;
  if ( (pl->groupMask & HIDWORD(gMask)) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    v7 = idList<idPLog::logEntry_t,44>::Alloc(this: &pl->logEntries);
    idMem::PopHeap(this: &mem);
    v7->label = v6;
    v7->parent = pl->lastEntry;
    v8 = pl->logEntries.num - 1;
    this->logIndex = v8;
    pl->lastEntry = v8;
    LODWORD(v9) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v7->totalTicks = v9;
  }
  return this;
}


// ========================================================================
// ?EnsureEntries@idPLog@@QAAXXZ
// EA  : 0x82F3E6F0
// RVA : 0x00F3E6F0
// PDB : w:\tech5\shared\idlib\metrics\plog.h
// ========================================================================

void __fastcall idPLog::EnsureEntries(idPLog *this)
{
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  if ( this->logEntries.size < 4096 )
    idList<cacheLineStat_t,5>::Resize(this: &this->logEntries, newsize: 4096);
  if ( this->treeEntries.size < 4096 )
    idList<idPLog::treeEntry_t,44>::Resize(this: &this->treeEntries, newsize: 4096);
  idMem::PopHeap(this: &mem);
}

