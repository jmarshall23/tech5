
// ========================================================================
// ?clearHistory_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8266FA68
// RVA : 0x0066FA68
// PDB : w:\tech5\engine\framework\consolehistory.cpp
// ========================================================================

void __fastcall clearHistory_f(const idCmdArgs *args)
{
  consoleHistory.upPoint = 0;
  consoleHistory.downPoint = 0;
  consoleHistory.returnLine = 0;
  consoleHistory.numHistory = 0;
}


// ========================================================================
// ?AddToHistory@idConsoleHistory@@QAAXPBD_N@Z
// EA  : 0x8266FA98
// RVA : 0x0066FA98
// PDB : w:\tech5\engine\framework\consolehistory.cpp
// ========================================================================

void __fastcall idConsoleHistory::AddToHistory(idConsoleHistory *this, const char *line, bool writeHistoryFile)
{
  const char *v6; // r10
  int i; // r11
  int numHistory; // r11
  idFile *v9; // r29
  int v10; // r11
  int v11; // r30

  if ( line != nullptr )
  {
    v6 = line;
    for ( i = *line; *v6 != 0; i = *++v6 )
    {
      if ( i > 32 )
        break;
    }
    if ( *v6 != 0 )
    {
      if ( idStr::Icmp(
             s1: *(const char **)((char *)&this->historyLines.ptr[0].data + ((32 * (this->numHistory - 1)) & 0x7E0)),
             s2: line) != 0 )
      {
        numHistory = this->numHistory;
        this->downPoint = numHistory + 1;
        this->upPoint = numHistory;
        this->returnLine = numHistory;
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
        idStr::operator=(
          this: (idStr *)((char *)this->historyLines.ptr + ((32 * this->numHistory) & 0x7E0)),
          text: line);
        idMem::PopHeap(this: &mem);
        ++this->numHistory;
        if ( writeHistoryFile )
        {
          v9 = fileSystem->OpenFileWrite(this: fileSystem, a2: HISTORY_FILE_NAME, a3: 0);
          if ( v9 != nullptr )
          {
            v10 = this->numHistory;
            v11 = v10 - 64;
            if ( v10 - 64 < v10 )
            {
              do
              {
                if ( v11 >= 0 )
                  v9->Printf(
                    this: v9,
                    a2: "%s\n",
                    *(char **)((char *)&this->historyLines.ptr[0].data + ((32 * v11) & 0x7E0)));
                ++v11;
              }
              while ( v11 < this->numHistory );
            }
            ((void (__fastcall *)(idFile *, int))v9->dtr_idFile)(a1: v9, a2: 1);
          }
        }
      }
      else if ( idStr::Icmp(
                  s1: *(const char **)((char *)&this->historyLines.ptr[0].data + ((32 * this->returnLine) & 0x7E0)),
                  s2: line) == 0 )
      {
        this->upPoint = this->returnLine;
      }
    }
  }
}


// ========================================================================
// ?LoadHistoryFile@idConsoleHistory@@QAAXXZ
// EA  : 0x8266FC58
// RVA : 0x0066FC58
// PDB : w:\tech5\engine\framework\consolehistory.cpp
// ========================================================================

void __fastcall idConsoleHistory::LoadHistoryFile(idConsoleHistory *this)
{
  idStr v2; // [sp+50h] [-D0h] BYREF
  idLexer v3; // [sp+70h] [-B0h] BYREF

  idLexer::idLexer(this: &v3, flags_: 0);
  if ( idLexer::LoadFile(this: &v3, filename_: HISTORY_FILE_NAME, OSPath: false) )
  {
    v2.len = 0;
    v2.allocedAndFlag = 20;
    v2.data = v2.baseBuffer;
    v2.baseBuffer[0] = 0;
    idLexer::ParseCompleteLine(this: &v3, out: &v2);
    while ( v2.len != 0 )
    {
      idStr::StripTrailingWhitespace(this: &v2);
      idConsoleHistory::AddToHistory(this, line: v2.data, writeHistoryFile: false);
      idStr::FreeData(this: &v2);
      v2.allocedAndFlag = 20;
      v2.data = v2.baseBuffer;
      v2.len = 0;
      v2.baseBuffer[0] = 0;
      idLexer::ParseCompleteLine(this: &v3, out: &v2);
    }
    idStr::FreeData(this: &v2);
  }
  idLexer::~idLexer(this: &v3);
}


// ========================================================================
// __unwind$219402
// EA  : 0x8266FD30
// RVA : 0x0066FD30
// PDB : w:\tech5\engine\framework\consolehistory.cpp
// ========================================================================

void _unwind_219402()
{
  int v0; // r12

  idLexer::~idLexer(this: (idLexer *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$219403
// EA  : 0x8266FD58
// RVA : 0x0066FD58
// PDB : w:\tech5\engine\framework\consolehistory.cpp
// ========================================================================

void _unwind_219403()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 80));
}


// ========================================================================
// ?PrintHistory@idConsoleHistory@@QAAXXZ
// EA  : 0x8266FD80
// RVA : 0x0066FD80
// PDB : w:\tech5\engine\framework\consolehistory.cpp
// ========================================================================

void __fastcall idConsoleHistory::PrintHistory(idConsoleHistory *this)
{
  int numHistory; // r11
  int v3; // r31
  char v4; // r8
  char v5; // r9
  char v6; // r10

  numHistory = this->numHistory;
  v3 = numHistory - 64;
  if ( numHistory - 64 < numHistory )
  {
    do
    {
      if ( v3 >= 0 )
      {
        v4 = 82;
        if ( v3 != this->returnLine )
          v4 = 32;
        v5 = 68;
        if ( v3 != this->downPoint )
          v5 = 32;
        v6 = 85;
        if ( v3 != this->upPoint )
          v6 = 32;
        idLib::Printf(
          fmt: "%c%c%c%4i: %s\n",
          v6,
          v5,
          v4,
          v3,
          *(const char **)((char *)&this->historyLines.ptr[0].data + ((32 * v3) & 0x7E0)));
      }
      ++v3;
    }
    while ( v3 < this->numHistory );
  }
}


// ========================================================================
// ?history_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8266FE28
// RVA : 0x0066FE28
// PDB : w:\tech5\engine\framework\consolehistory.cpp
// ========================================================================

void __fastcall history_f(const idCmdArgs *args)
{
  idConsoleHistory::PrintHistory(this: &consoleHistory);
}


// ========================================================================
// ?RetrieveFromHistory@idConsoleHistory@@QAA?AVidStr@@_N@Z
// EA  : 0x8266FE38
// RVA : 0x0066FE38
// PDB : w:\tech5\engine\framework\consolehistory.cpp
// ========================================================================

idConsoleHistory *__fastcall idConsoleHistory::RetrieveFromHistory(
        idConsoleHistory *this,
        idStr *result,
        bool backward)
{
  int v3; // r10
  int len; // r11

  v3 = *(_DWORD *)result->baseBuffer;
  if ( v3 == 0 )
    goto LABEL_2;
  if ( backward )
  {
    len = result->len;
    if ( result->len >= v3 - 64 && len >= 0 )
    {
      result->data = (char *)(len + 1);
      result->len = len - 1;
LABEL_9:
      result->allocedAndFlag = len;
      idStr::idStr((idStr *)this, text: (const idStr *)&result->baseBuffer[((32 * len) & 0x7E0) + 4]);
      return this;
    }
  }
  else
  {
    len = (int)result->data;
    if ( len < v3 )
    {
      result->len = len - 1;
      result->data = (char *)(len + 1);
      goto LABEL_9;
    }
  }
LABEL_2:
  idStr::idStr((idStr *)this, text: &byte_8200D768);
  return this;
}


// ========================================================================
// `dynamic initializer for 'consoleHistory''
// EA  : 0x8333B5A8
// RVA : 0x0133B5A8
// PDB : w:\tech5\engine\framework\consolehistory.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__consoleHistory__()
{
  `eh vector constructor iterator'(
    ptr: (char *)&consoleHistory.historyLines,
    size: 0x20u,
    count: 64,
    pCtor: (void (__fastcall *)(void *))idZippedFile::idZippedFile,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  consoleHistory.upPoint = 0;
  consoleHistory.downPoint = 0;
  consoleHistory.returnLine = 0;
  consoleHistory.numHistory = 0;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__consoleHistory__);
}


// ========================================================================
// `dynamic initializer for 'history_v''
// EA  : 0x8333B628
// RVA : 0x0133B628
// PDB : w:\tech5\engine\framework\consolehistory.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__history_v__()
{
  return idCommandLink::idCommandLink(
           this: &history_v,
           cmdName: "history",
           function: history_f,
           description: "Displays the console command history",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'clearHistory_v''
// EA  : 0x8333B650
// RVA : 0x0133B650
// PDB : w:\tech5\engine\framework\consolehistory.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__clearHistory_v__()
{
  return idCommandLink::idCommandLink(
           this: &clearHistory_v,
           cmdName: "clearHistory",
           function: clearHistory_f,
           description: "Clears the console history",
           argCompletion: nullptr);
}

