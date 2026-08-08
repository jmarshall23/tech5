
// ========================================================================
// ?CloseLogFile@idLogFileWriter@idCommonLocal@@QAAXXZ
// EA  : 0x8265BE80
// RVA : 0x0065BE80
// PDB : w:\tech5\engine\framework\common_printf.cpp
// ========================================================================

void __fastcall idCommonLocal::idLogFileWriter::CloseLogFile(idCommonLocal::idLogFileWriter *this)
{
  idFile *logFile; // r3

  if ( this->logFile != nullptr )
  {
    idCVar::SetBool(this: &com_logFile, newValue: false, force: true);
    logFile = this->logFile;
    if ( logFile != nullptr )
      ((void (__fastcall *)(idFile *, int))logFile->dtr_idFile)(a1: logFile, a2: 1);
    this->logFile = nullptr;
  }
}


// ========================================================================
// ?SetRefreshOnPrint@idCommonLocal@@UAAX_N@Z
// EA  : 0x8265BEF0
// RVA : 0x0065BEF0
// PDB : w:\tech5\engine\framework\common_printf.cpp
// ========================================================================

void __fastcall idCommonLocal::SetRefreshOnPrint(idCommonLocal *this, bool set)
{
  this->refreshOnPrint.cl = this;
  this->refreshOnPrint.set = set;
}


// ========================================================================
// ?Print@idRefreshOnPrint@idCommonLocal@@UAAXPBD@Z
// EA  : 0x8265BF00
// RVA : 0x0065BF00
// PDB : w:\tech5\engine\framework\common_printf.cpp
// ========================================================================

void __fastcall idCommonLocal::idRefreshOnPrint::Print(idCommonLocal::idRefreshOnPrint *this, const char *msg)
{
  idCommonLocal *cl; // r11

  if ( this->set )
  {
    cl = this->cl;
    if ( cl != nullptr )
      ((void (*)(void))cl->UpdateConsoleDisplay)();
  }
}


// ========================================================================
// ?Print@idLogFileWriter@idCommonLocal@@UAAXPBD@Z
// EA  : 0x8265BF38
// RVA : 0x0065BF38
// PDB : w:\tech5\engine\framework\common_printf.cpp
// ========================================================================

void __fastcall idCommonLocal::idLogFileWriter::Print(idCommonLocal::idLogFileWriter *this, const char *msg)
{
  int valueInteger; // r25
  char *data; // r28
  idFile *logFile; // r3
  const char *v7; // r3
  idFile *v8; // r3
  bool v9; // r29
  idFile *v10; // r3
  const tm *v11; // r3
  const char *v12; // r3
  idFile *v13; // r3
  unsigned int v14; // r5
  __int64 v15[10]; // [sp+50h] [-50h] BYREF

  valueInteger = com_logFile.valueInteger;
  if ( com_logFile.valueInteger != 0 )
  {
    data = com_logFileName.valueString.data;
    if ( *com_logFileName.valueString.data == 0 )
      data = "qconsole.log";
    logFile = this->logFile;
    if ( logFile != nullptr )
    {
      v7 = logFile->GetName(this: logFile);
      if ( idStr::Icmp(s1: data, s2: v7) != 0 )
      {
        v8 = this->logFile;
        if ( v8 != nullptr )
          ((void (__fastcall *)(idFile *, int))v8->dtr_idFile)(a1: v8, a2: 1);
        this->logFile = nullptr;
      }
    }
    if ( this->logFile == nullptr && !this->recursing )
    {
      this->recursing = true;
      v9 = fs_readOnly.valueInteger != 0;
      idCVar::SetBool(this: &fs_readOnly, newValue: false, force: true);
      idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      this->logFile = fileSystem->OpenFileReadWrite(this: fileSystem, a2: data, a3: 1, a4: 2);
      idMem::PopHeap(this: &mem);
      v10 = this->logFile;
      if ( v10 == nullptr )
        idLib::FatalError(fmt: "failed to open log file '%s'\n", data);
      v10->SetLength(this: v10, a2: 0);
      this->recursing = false;
      idCVar::SetBool(this: &fs_readOnly, newValue: v9, force: true);
      time64(timeptr: v15);
      v11 = localtime64(ptime: v15);
      v12 = asctime(tb: v11);
      idLib::Printf(fmt: "log file '%s' opened on %s\n", data, v12);
    }
    v13 = this->logFile;
    if ( v13 != nullptr )
    {
      v14 = 0;
      if ( *msg != 0 )
      {
        do
          ++v14;
        while ( msg[v14] != 0 );
      }
      v13->Write(this: v13, a2: msg, a3: v14);
      if ( valueInteger == 2 )
        this->logFile->Flush(this: this->logFile);
    }
  }
}


// ========================================================================
// ?PrintWarnings@idCommonLocal@@UAAXXZ
// EA  : 0x8265C130
// RVA : 0x0065C130
// PDB : w:\tech5\engine\framework\common_printf.cpp
// ========================================================================

void __fastcall idCommonLocal::PrintWarnings(idCommonLocal *this)
{
  int num; // r4
  int v3; // r31
  int v4; // r30

  idLib::Printf(fmt: "------------- Warnings ---------------\n");
  idLib::Printf(fmt: "during %s...\n", this->warningList.caption.data);
  num = this->warningList.list.num;
  v3 = 0;
  if ( num > 0 )
  {
    v4 = 0;
    do
    {
      idLib::Printf(fmt: "%s", this->warningList.list.list[v4].message.data);
      num = this->warningList.list.num;
      ++v3;
      ++v4;
    }
    while ( v3 < num );
  }
  idLib::Printf(fmt: "%d warnings\n", num);
  idLib::Printf(fmt: "--------------------------------------\n");
  this->ClearWarnings(this, a2: &byte_8200D768);
}


// ========================================================================
// ?DumpWarnings@idCommonLocal@@QAAXPBD@Z
// EA  : 0x8265C1E0
// RVA : 0x0065C1E0
// PDB : w:\tech5\engine\framework\common_printf.cpp
// ========================================================================

void __fastcall idCommonLocal::DumpWarnings(idCommonLocal *this, const char *fileName)
{
  int v3; // r29
  int v4; // r26
  int v5; // r28
  idUniqueWarning *v6; // r11
  char *data; // r31
  int len; // r30
  char v9; // [sp+50h] [-50h] BYREF

  v3 = ((int (__fastcall *)(idFileSystem *, const char *, int, __int32))fileSystem->OpenFileWrite)(
         a1: fileSystem,
         a2: fileName,
         a3: idLib::production != PROD_PRODUCTION ? 0 : 2,
         a4: idLib::production - 3);
  if ( v3 != 0 )
  {
    v4 = 0;
    if ( this->warningList.list.num > 0 )
    {
      v5 = 0;
      do
      {
        v6 = &this->warningList.list.list[v5];
        data = v6->message.data;
        len = v6->message.len;
        (*(void (__fastcall **)(int, char *, int))(*(_DWORD *)v3 + 16))(a1: v3, a2: data, a3: v6->message.len);
        if ( data[len - 1] != 10 )
        {
          v9 = 10;
          (*(void (__fastcall **)(int, char *, int))(*(_DWORD *)v3 + 16))(a1: v3, a2: &v9, a3: 1);
        }
        ++v4;
        ++v5;
      }
      while ( v4 < this->warningList.list.num );
    }
    (**(void (__fastcall ***)(int, int))v3)(a1: v3, a2: 1);
  }
}


// ========================================================================
// ?ClearWarnings@idCommonLocal@@UAAXPBD@Z
// EA  : 0x8265C540
// RVA : 0x0065C540
// PDB : w:\tech5\engine\framework\common_printf.cpp
// ========================================================================

void __fastcall idCommonLocal::ClearWarnings(idCommonLocal *this, const char *reason)
{
  char *data; // r4
  size_t v5; // r5
  char *v6; // r3
  idUniqueWarning *list; // r3
  idStrStatic<128> v8; // [sp+50h] [-C0h] BYREF

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  idStrStatic<128>::idStrStatic<128>(this: &v8, text: reason);
  data = v8.data;
  v5 = v8.len + 1;
  v6 = this->warningList.caption.data;
  this->warningList.caption.len = v8.len;
  memcpy(Dst: v6, Src: data, Size: v5);
  idStr::FreeData(this: &v8);
  if ( this->warningList.list.listStatic == 0 || this->warningList.list.listStatic == 2 )
  {
    list = this->warningList.list.list;
    if ( list != nullptr )
      idListArrayDelete<idProgram::idFileInfo>(ptr: &list->message, num: this->warningList.list.size);
    this->warningList.list.list = nullptr;
    this->warningList.list.size = 0;
  }
  this->warningList.list.num = 0;
  idHashIndex::Clear(this: &this->warningList.hash);
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// ?Print@idWarningList@idCommonLocal@@UAAXPBD@Z
// EA  : 0x8265C5F0
// RVA : 0x0065C5F0
// PDB : w:\tech5\engine\framework\common_printf.cpp
// ========================================================================

void __fastcall idCommonLocal::idWarningList::Print(idCommonLocal::idWarningList *this, const char *msg)
{
  idHashIndex *p_hash; // r29
  int KeyForString; // r25
  int v6; // r30
  int v7; // r30
  int indexSize; // r11
  int v9; // r6
  idUniqueWarning v10[3]; // [sp+50h] [-70h] BYREF

  p_hash = &this->hash;
  KeyForString = idHashIndex::GenerateKeyForString(this: &this->hash, string: msg, caseSensitive: false);
  v6 = this->hash.hash[this->hash.lookupMask & this->hash.hashMask & KeyForString];
  if ( v6 == -1 )
  {
LABEL_4:
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    idStr::idStr(this: &v10[0].message, text: msg);
    v10[0].count = 1;
    v7 = idList<idGroupState,5>::Append(this: &this->list, obj: v10);
    idStr::FreeData(this: &v10[0].message);
    indexSize = p_hash->indexSize;
    if ( p_hash->hash == idHashIndex::INVALID_INDEX )
    {
      if ( v7 >= indexSize )
        indexSize = v7 + 1;
      idHashIndex::Allocate(this: p_hash, newHashSize: p_hash->hashSize, newIndexSize: indexSize);
    }
    else if ( v7 >= indexSize )
    {
      idHashIndex::ResizeIndex(this: p_hash, newIndexSize: v7 + 1);
    }
    v9 = p_hash->hashMask & KeyForString;
    p_hash->indexChain[v7] = p_hash->hash[v9];
    p_hash->hash[v9] = v7;
    idMem::PopHeap(this: &mem);
  }
  else
  {
    while ( idStr::Icmp(s1: this->list.list[v6].message.data, s2: msg) != 0 )
    {
      v6 = p_hash->indexChain[p_hash->lookupMask & v6];
      if ( v6 == -1 )
        goto LABEL_4;
    }
    ++this->list.list[v6].count;
  }
}


// ========================================================================
// __unwind$221750
// EA  : 0x8265C764
// RVA : 0x0065C764
// PDB : w:\tech5\engine\framework\common_printf.cpp
// ========================================================================

void _unwind_221750()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// `dynamic initializer for 'com_logFile''
// EA  : 0x8333A020
// RVA : 0x0133A020
// PDB : w:\tech5\engine\framework\common_printf.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_logFile__()
{
  idCVar::idCVar(
    this: &com_logFile,
    name: "logFile",
    value: "0",
    flags: 0,
    description: "1 = buffer log, 2 = flush after each print",
    valueMin: 0.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))&unk_821D0000,
    a9: (int)&loc_82660000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,2>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_logFile__);
}


// ========================================================================
// `dynamic initializer for 'com_logFileName''
// EA  : 0x8333A088
// RVA : 0x0133A088
// PDB : w:\tech5\engine\framework\common_printf.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_logFileName__()
{
  idCVar::idCVar(
    this: &com_logFileName,
    name: "logFileName",
    value: "qconsole.log",
    flags: 0,
    description: "name of log file, if empty, qconsole.log will be used",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_logFileName__);
}

