
// ========================================================================
// ?GetCommandDescription@idCmdSystemLocal@@UAAPBDPBD@Z
// EA  : 0x82EFBF78
// RVA : 0x00EFBF78
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

const char *__fastcall idCmdSystemLocal::GetCommandDescription(idCmdSystemLocal *this, const char *cmdName)
{
  commandDef_s *commands; // r31

  commands = this->commands;
  if ( commands == nullptr )
    return "NOT FOUND";
  while ( idStr::Icmp(s1: cmdName, s2: commands->name) != 0 )
  {
    commands = commands->next;
    if ( commands == nullptr )
      return "NOT FOUND";
  }
  return commands->description;
}


// ========================================================================
// ?CommandExists@idCmdSystemLocal@@UAA_NPBD_N@Z
// EA  : 0x82EFBFE8
// RVA : 0x00EFBFE8
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

int __fastcall idCmdSystemLocal::CommandExists(idCmdSystemLocal *this, const char *cmdName, bool searchForString)
{
  commandDef_s *commands; // r31
  BOOL v5; // r29
  const char *name; // r4

  commands = this->commands;
  if ( commands != nullptr )
  {
    v5 = searchForString;
    do
    {
      name = commands->name;
      if ( v5 )
      {
        if ( idStr::Find(searchIn: cmdName, searchFor: name, casesensitive: false, start: 0, end: -1) != -1 )
          return 1;
      }
      else if ( idStr::Icmp(s1: cmdName, s2: name) == 0 )
      {
        return 1;
      }
      commands = commands->next;
    }
    while ( commands != nullptr );
  }
  return 0;
}


// ========================================================================
// ?Echo_f@idCmdSystemLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82EFC0F8
// RVA : 0x00EFC0F8
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystemLocal::Echo_f(const idCmdArgs *args)
{
  int argc; // r11
  int v3; // r31
  const char **v4; // r30
  const char *v5; // r4

  argc = args->argc;
  v3 = 1;
  if ( args->argc > 1 )
  {
    v4 = (const char **)&args->argv[1];
    do
    {
      if ( v3 < 0 || v3 >= argc )
        v5 = &byte_8200D768;
      else
        v5 = *v4;
      idLib::Printf(fmt: "%s ", v5);
      argc = args->argc;
      ++v3;
      ++v4;
    }
    while ( v3 < args->argc );
  }
  idLib::Printf(fmt: "\n");
}


// ========================================================================
// ?Wait_f@idCmdSystemLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82EFC178
// RVA : 0x00EFC178
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystemLocal::Wait_f(const idCmdArgs *args)
{
  if ( args->argc == 2 )
    cmdSystemLocal.wait = atol(nptr: args->argv[1]);
  else
    cmdSystemLocal.wait = 1;
}


// ========================================================================
// ?Parse_f@idCmdSystemLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82EFC1D8
// RVA : 0x00EFC1D8
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystemLocal::Parse_f(const idCmdArgs *args)
{
  int argc; // r11
  int v3; // r31
  char **argv; // r30
  const char *v5; // r5

  argc = args->argc;
  v3 = 0;
  if ( args->argc > 0 )
  {
    argv = args->argv;
    do
    {
      if ( v3 < 0 || v3 >= argc )
        v5 = &byte_8200D768;
      else
        v5 = *argv;
      idLib::Printf(fmt: "%i: %s\n", v3, v5);
      argc = args->argc;
      ++v3;
      ++argv;
    }
    while ( v3 < args->argc );
  }
}


// ========================================================================
// ?AddCommand@idCmdSystemLocal@@UAAXPBDP6AXABVidCmdArgs@@@Z0P6AXAAVidAutoComplete@@@Z@Z
// EA  : 0x82EFC250
// RVA : 0x00EFC250
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystemLocal::AddCommand(
        idCmdSystemLocal *this,
        const char *cmdName,
        void (__fastcall *function)(const idCmdArgs *),
        const char *description,
        void (__fastcall *argCompletion)(idAutoComplete *))
{
  commandDef_s *commands; // r31
  commandDef_s *v11; // r25

  commands = this->commands;
  if ( commands != nullptr )
  {
    while ( idStr::Cmp(s1: cmdName, s2: commands->name) != 0 )
    {
      commands = commands->next;
      if ( commands == nullptr )
        goto LABEL_4;
    }
    if ( function != commands->function )
      idLib::Printf(fmt: "idCmdSystemLocal::AddCommand: %s already defined\n", cmdName);
  }
  else
  {
LABEL_4:
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    v11 = (commandDef_s *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x14u,
                            tag: TAG_CVAR,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
    idMem::PopHeap(this: &mem);
    v11->name = cmdName;
    v11->function = function;
    v11->argCompletion = argCompletion;
    v11->description = description;
    v11->next = this->commands;
    this->commands = v11;
  }
}


// ========================================================================
// ?ExecuteTokenizedString@idCmdSystemLocal@@QAAXABVidCmdArgs@@@Z
// EA  : 0x82EFC328
// RVA : 0x00EFC328
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystemLocal::ExecuteTokenizedString(idCmdSystemLocal *this, const idCmdArgs *args)
{
  commandDef_s *commands; // r31
  const char *name; // r29
  char *v5; // r3
  void (__fastcall *function)(const idCmdArgs *); // r11

  if ( args->argc != 0 )
  {
    commands = this->commands;
    if ( commands == nullptr )
      goto LABEL_5;
    while ( 1 )
    {
      name = commands->name;
      v5 = idCmdArgs::Argv(this: args, arg: 0);
      if ( idStr::Icmp(s1: v5, s2: name) == 0 )
        break;
      commands = commands->next;
      if ( commands == nullptr )
        goto LABEL_5;
    }
    function = commands->function;
    if ( function != nullptr )
    {
      function(a1: args);
    }
    else
    {
LABEL_5:
      if ( !cvarSystem->Command(this: cvarSystem, a2: args) )
      {
        if ( args->argc <= 0 )
          idLib::Printf(fmt: "Unknown command '%s'\n", &byte_8200D768);
        else
          idLib::Printf(fmt: "Unknown command '%s'\n", args->argv[0]);
      }
    }
  }
}


// ========================================================================
// ?ExecuteCommandText@idCmdSystemLocal@@UAAXPBD@Z
// EA  : 0x82EFC408
// RVA : 0x00EFC408
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystemLocal::ExecuteCommandText(idCmdSystemLocal *this, const char *text)
{
  idCmdArgs v3; // [sp+50h] [-920h] BYREF

  idCmdArgs::TokenizeString(this: &v3, text, keepAsStrings: true);
  idCmdSystemLocal::ExecuteTokenizedString(this, args: &v3);
}


// ========================================================================
// ?ExecuteCommandBuffer@idCmdSystemLocal@@UAAXXZ
// EA  : 0x82EFC448
// RVA : 0x00EFC448
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystemLocal::ExecuteCommandBuffer(idCmdSystemLocal *this)
{
  idStrStatic<32768> *p_textBuffer; // r30
  int wait; // r11
  int v4; // r4
  bool v5; // r5
  bool v6; // r6
  int v7; // r31
  char *data; // r7
  char *v9; // r9
  char v10; // r11
  int v11; // r10
  int v12; // r11
  int i; // r11
  int v14; // r10
  int v15; // r11
  int v16; // r10
  char v17; // r10
  char *v18; // r11
  idCmdArgs v19; // [sp+50h] [-940h] BYREF

  p_textBuffer = &this->textBuffer;
  if ( this->textBuffer.len > 0 )
  {
    while ( 1 )
    {
      wait = this->wait;
      if ( wait != 0 )
        break;
      v4 = 0;
      v5 = false;
      v6 = false;
      v7 = 0;
      if ( p_textBuffer->len > 0 )
      {
        while ( 1 )
        {
          data = this->textBuffer.data;
          v9 = &data[v7];
          v10 = data[v7];
          v11 = v10;
          if ( v10 == 34 )
            ++v4;
          if ( v10 == 47 && v4 == 0 && v7 + 1 < p_textBuffer->len )
          {
            v12 = v9[1];
            v6 = (_cntlzw(v12 - 42) & 0x20) != 0;
            v5 = (_cntlzw(v12 - 47) & 0x20) != 0;
          }
          if ( v5 )
          {
            for ( i = v7; i < p_textBuffer->len; ++i )
            {
              v14 = data[i];
              if ( v14 == 10 )
                break;
              if ( v14 == 13 )
                break;
            }
            v7 = i;
            *v9 = 0;
          }
          else if ( v6 )
          {
            v15 = v7;
            if ( v7 < p_textBuffer->len )
            {
              while ( 1 )
              {
                if ( data[v15] == 42 )
                {
                  v16 = v15 + 1;
                  if ( v15 + 1 < p_textBuffer->len && data[v15 + 1] == 47 )
                    break;
                }
                if ( ++v15 >= p_textBuffer->len )
                {
                  this->textBuffer.data[v7] = 0;
                  v7 = v15;
                  goto LABEL_27;
                }
              }
              ++v15;
              data[v16] = 10;
            }
            this->textBuffer.data[v7] = 0;
            v7 = v15;
          }
          else if ( (v4 & 1) == 0 && v11 == 59 )
          {
            break;
          }
LABEL_27:
          v17 = this->textBuffer.data[v7];
          if ( v17 != 10 && v17 != 13 && ++v7 < p_textBuffer->len )
            continue;
          break;
        }
      }
      if ( v7 < p_textBuffer->len )
        this->textBuffer.data[v7] = 0;
      v19.argc = 0;
      idCmdArgs::TokenizeString(this: &v19, text: this->textBuffer.data, keepAsStrings: true);
      if ( v7 < p_textBuffer->len )
      {
        idStr::Erase(this: p_textBuffer, start: 0, len: v7 + 1);
      }
      else if ( p_textBuffer->allocedAndFlag >= 0 )
      {
        idStr::FreeData(this: p_textBuffer);
        p_textBuffer->allocedAndFlag = 20;
        p_textBuffer->data = p_textBuffer->baseBuffer;
        p_textBuffer->len = 0;
        p_textBuffer->baseBuffer[0] = 0;
      }
      else
      {
        v18 = p_textBuffer->data;
        p_textBuffer->len = 0;
        *v18 = 0;
      }
      idCmdSystemLocal::ExecuteTokenizedString(this, args: &v19);
      if ( p_textBuffer->len <= 0 )
        return;
    }
    this->wait = wait - 1;
  }
}


// ========================================================================
// ?CommandCompletion@idCmdSystemLocal@@UAAXAAVidAutoComplete@@@Z
// EA  : 0x82EFCAC0
// RVA : 0x00EFCAC0
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystemLocal::CommandCompletion(idCmdSystemLocal *this, idAutoComplete *autoComplete)
{
  commandDef_s *commands; // r30
  const char *name; // r28
  char *Arg; // r3
  idStr v6[2]; // [sp+50h] [-50h] BYREF

  commands = this->commands;
  if ( commands != nullptr )
  {
    while ( 1 )
    {
      if ( autoComplete->args.argc == 1 )
      {
        idStr::idStr(this: v6, text: commands->name);
        idAutoComplete::Append(this: autoComplete, suggestion: v6, completingArg: -1);
        idStr::FreeData(this: v6);
      }
      if ( commands->argCompletion != nullptr )
      {
        name = commands->name;
        Arg = idAutoComplete::GetArg(this: autoComplete, n: 0);
        if ( idStr::Icmp(s1: Arg, s2: name) == 0 )
          break;
      }
      commands = commands->next;
      if ( commands == nullptr )
        return;
    }
    commands->argCompletion(a1: autoComplete);
  }
}


// ========================================================================
// __unwind$114111
// EA  : 0x82EFCB64
// RVA : 0x00EFCB64
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114111()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?InsertCommandText@idCmdSystemLocal@@QAAXPBD@Z
// EA  : 0x82EFCC50
// RVA : 0x00EFCC50
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
void __fastcall idCmdSystemLocal::InsertCommandText(idCmdSystemLocal *this, const char *text)
{
  __int64 v2; // r4
  int v3; // r30
  const char *v4; // r28
  const idStr *v5; // r3
  const idStr *v6; // r3
  const idStr *v7; // r3
  char *data; // r4
  size_t v9; // r5
  void *v10; // r3
  idStr v11; // [sp+50h] [-80D0h] BYREF
  idStr v12; // [sp+70h] [-80B0h] BYREF
  idStr v13; // [sp+90h] [-8090h] BYREF
  idStr v14; // [sp+B0h] [-8070h] BYREF
  idStrStatic<32768> v15; // [sp+D0h] [-8050h] BYREF

  v2 = ((__int64 (*)(void))RtlCheckStack12)();
  v11.allocedAndFlag = 20;
  v3 = HIDWORD(v2);
  v11.data = v11.baseBuffer;
  v4 = (const char *)v2;
  v11.baseBuffer[0] = 0;
  idStr::EnsureAlloced(this: &v11, amount: 2, keepold: true, geometricGrowth: false);
  *v11.data = 10;
  v11.data[1] = 0;
  v11.len = 1;
  v5 = idStr::idStr(this: &v13, text: v4);
  v6 = operator+(result: &v12, a: v5, b: &v11);
  v7 = operator+(result: &v14, a: v6, b: (const idStr *)(v3 + 12));
  idStrStatic<32768>::idStrStatic<32768>(this: &v15, text: v7);
  data = v15.data;
  v9 = v15.len + 1;
  v10 = *(void **)(v3 + 16);
  *(_DWORD *)(v3 + 12) = v15.len;
  memcpy(Dst: v10, Src: data, Size: v9);
  idStr::FreeData(this: &v15);
  idStr::FreeData(this: &v14);
  idStr::FreeData(this: &v12);
  idStr::FreeData(this: &v13);
  idStr::FreeData(this: &v11);
}


// ========================================================================
// __unwind$114245
// EA  : 0x82EFCD48
// RVA : 0x00EFCD48
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114245()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 32560));
}


// ========================================================================
// __unwind$114246
// EA  : 0x82EFCD70
// RVA : 0x00EFCD70
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114246()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 32624));
}


// ========================================================================
// __unwind$114247
// EA  : 0x82EFCD98
// RVA : 0x00EFCD98
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114247()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 32592));
}


// ========================================================================
// __unwind$114248
// EA  : 0x82EFCDC0
// RVA : 0x00EFCDC0
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114248()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 + 32656));
}


// ========================================================================
// ?AppendCommandText@idCmdSystemLocal@@UAAXPBD@Z
// EA  : 0x82EFCDE8
// RVA : 0x00EFCDE8
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystemLocal::AppendCommandText(idCmdSystemLocal *this, char *text)
{
  idStr::Append(this: &this->textBuffer, text);
}


// ========================================================================
// ?FindCommands@idCmdSystemLocal@@UAAXPBDAAV?$idList@VidStr@@$04@@@Z
// EA  : 0x82EFCDF8
// RVA : 0x00EFCDF8
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystemLocal::FindCommands(idCmdSystemLocal *this, const char *findText, idList<idStr,5> *cmds)
{
  commandDef_s *i; // r30
  idStr v6[2]; // [sp+50h] [-50h] BYREF

  for ( i = cmdSystemLocal.commands; i != nullptr; i = i->next )
  {
    if ( idStr::Find(searchIn: i->name, searchFor: findText, casesensitive: false, start: 0, end: -1) != -1 )
    {
      idStr::idStr(this: v6, text: i->name);
      idList<idStr,5>::Append(this: cmds, obj: v6);
      idStr::FreeData(this: v6);
    }
  }
}


// ========================================================================
// __unwind$114395
// EA  : 0x82EFCE78
// RVA : 0x00EFCE78
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114395()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?List_f@idCmdSystemLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82EFCEA8
// RVA : 0x00EFCEA8
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystemLocal::List_f(const idCmdArgs *args)
{
  const char *v2; // r3
  int v3; // r8
  int v4; // r7
  int v5; // r6
  __int64 v6; // r10
  commandDef_s *commands; // r30
  encounterGroupRole_t *list; // r26
  int num; // r27
  encounterGroupRole_t *v10; // r29
  int j; // r30
  commandDef_s *i; // [sp+50h] [-80h] BYREF
  idSort_Quick<entityListType_t *,idSort_EntityType> v13; // [sp+54h] [-7Ch] BYREF
  idList<enum encounterGroupRole_t,5> v14; // [sp+60h] [-70h] BYREF
  idStr v15[3]; // [sp+70h] [-60h] BYREF

  v15[0].len = 0;
  v15[0].allocedAndFlag = 20;
  v15[0].data = v15[0].baseBuffer;
  v15[0].baseBuffer[0] = 0;
  memset(&v14, 0, 14);
  *(_WORD *)&v14.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v14);
  if ( args->argc <= 1 )
  {
    idStr::operator=(this: v15, text: &byte_8200D768);
  }
  else
  {
    v2 = idCmdArgs::Args(this: args, start: 1, end: -1, quoteArgs: false, escapeArgs: false);
    idStr::operator=(this: v15, text: v2);
    idStr::Replace(this: v15, old: " ", nw: &byte_8200D768);
  }
  idStr::Replace(this: v15, old: "*", nw: &byte_8200D768);
  LODWORD(v6) = &aAvSsobjectVCom[20];
  HIDWORD(v6) = &cmdSystemLocal;
  commands = cmdSystemLocal.commands;
  for ( i = cmdSystemLocal.commands; commands != nullptr; i = commands )
  {
    if ( v15[0].len <= 0
      || idStr::Find(searchIn: commands->name, searchFor: v15[0].data, casesensitive: false, start: 0, end: -1) != -1 )
    {
      idList<idAnimWebBlendTree *,5>::Append(this: &v14, obj: (encounterGroupRole_t *)&i);
    }
    commands = commands->next;
  }
  v13.__vftable = (idSort_Quick<entityListType_t *,idSort_EntityType>_vtbl *)&idSort_CommandDefPtr::`vftable';
  list = v14.list;
  num = v14.num;
  if ( v14.list != nullptr )
    idSort_Quick<entityListType_t *,idSort_EntityType>::Sort(
      this: &v13,
      base: (entityListType_t **)v14.list,
      num: v14.num,
      a4: v5,
      a5: v4,
      a6: v3,
      a7: v6);
  v13.__vftable = (idSort_Quick<entityListType_t *,idSort_EntityType>_vtbl *)&idSort<commandDef_s const *>::`vftable';
  if ( num > 0 )
  {
    v10 = list - 1;
    for ( j = num; j != 0; --j )
    {
      ++v10;
      idLib::Printf(fmt: "  %-21s %s\n", *(const char **)(*v10 + 4), *(const char **)(*v10 + 16));
    }
  }
  idLib::Printf(fmt: "%i commands\n", num);
  if ( (v14.listStatic == 0 || v14.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  idStr::FreeData(this: v15);
}


// ========================================================================
// __unwind$114421
// EA  : 0x82EFD098
// RVA : 0x00EFD098
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114421()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// __unwind$114422
// EA  : 0x82EFD0C0
// RVA : 0x00EFD0C0
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114422()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$114423
// EA  : 0x82EFD0E8
// RVA : 0x00EFD0E8
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114423()
{
  int v0; // r12

  idSort_CommandDefPtr::~idSort_CommandDefPtr(this: (idSort_CommandDefPtr *)(v0 - 208 + 84));
}


// ========================================================================
// ?Exec_f@idCmdSystemLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82EFD118
// RVA : 0x00EFD118
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystemLocal::Exec_f(const idCmdArgs *args)
{
  int argc; // r11
  bool v3; // cr56
  const char *v4; // r4
  int v5; // r30
  const char *v6; // r4
  unsigned int v7; // r28
  char *v8; // r23
  int v9; // r30
  char v10; // r22
  bool v11; // cr57
  int v12; // r11
  int v13; // r10
  const char **v14; // r29
  const char *v15; // r4
  int v16; // r10
  int v17; // r25
  const char *v18; // r4
  const char *v19; // r11
  unsigned int v20; // r5
  int v21; // r5
  const char *v22; // r11
  unsigned int v23; // r5
  char *data; // r4
  const char *v25; // r4
  char *v26; // [sp+50h] [-14D0h] BYREF
  int v27; // [sp+54h] [-14CCh]
  idStr v28; // [sp+60h] [-14C0h] BYREF
  idFile_Memory v29; // [sp+80h] [-14A0h] BYREF
  idParser v30; // [sp+1D0h] [-1350h] BYREF
  idToken v31; // [sp+460h] [-10C0h] BYREF
  char v32; // [sp+4A8h] [-1078h] BYREF

  argc = args->argc;
  v3 = args->argc < 2;
  v27 = args->argc;
  if ( v3 )
  {
    idLib::Printf(fmt: "USAGE: exec <filename> -s <define>: execute a script file\n");
    idLib::Printf(fmt: "Each token specified after the filename will be treated as a preprocessor define when parsing the file.\n");
    idLib::Printf(fmt: "/s = silent -- no not print \"execing configname\"\n");
    return;
  }
  if ( argc <= 1 )
    v4 = &byte_8200D768;
  else
    v4 = args->argv[1];
  idStr::idStr(this: &v28, text: v4);
  idStr::DefaultFileExtension(this: &v28, extension: ".cfg");
  v5 = fileSystem->ReadFile(this: fileSystem, a2: v28.data, a3: (void **)&v26, a4: nullptr);
  if ( v26 == nullptr )
  {
    if ( args->argc <= 1 )
      v6 = &byte_8200D768;
    else
      v6 = args->argv[1];
    idLib::Printf(fmt: "couldn't exec %s\n", v6);
    goto LABEL_49;
  }
  idParser::idParser(this: &v30, flags: 66192);
  idParser::LoadMemory(this: &v30, ptr: v26, length: v5, name: v28.data);
  v7 = v5 + 1;
  v8 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\csystems\\CmdSystem.cpp(166) : TAG_TEMP",
                 size: v5 + 1,
                 tag: TAG_TEMP,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  if ( v8 != nullptr )
  {
    v9 = 2;
    v10 = 0;
    v11 = args->argc > 2;
    v27 = args->argc;
    if ( v11 && idStr::Icmp(s1: args->argv[2], s2: "-s") == 0 )
    {
      v9 = 3;
      v10 = 1;
    }
    v12 = args->argc;
    v13 = args->argc - 1;
    v27 = args->argc;
    if ( v9 < v13 )
    {
      v14 = (const char **)&args->argv[v9];
      do
      {
        if ( v9 < 0 || v9 >= v12 )
          v15 = &byte_8200D768;
        else
          v15 = *v14;
        idParser::AddDefine(this: &v30, string: v15);
        v12 = args->argc;
        ++v9;
        v16 = args->argc - 1;
        ++v14;
        v27 = args->argc;
      }
      while ( v9 < v16 );
    }
    *v8 = 0;
    idFile_Memory::idFile_Memory(this: &v29, name: "*unknown*");
    v29.__vftable = (idFile_Memory_vtbl *)&idFile_String::`vftable';
    idFile_Memory::SetWritableData(this: &v29, data: v8, length: v7);
    v31.baseBuffer[0] = 0;
    v31.intvalue = 0;
    memset(&v31.whiteSpaceStart_p, 0, 12);
    v17 = 0;
    v31.floatvalue = -3.4028235e38;
    v32 = 0;
    v31.data = &v32;
    v31.len = 0;
    v31.allocedAndFlag = -2147479552;
    if ( !idParser::ReadToken(this: &v30, token: &v31) )
    {
LABEL_43:
      if ( v10 == 0 )
      {
        if ( args->argc <= 1 )
          v25 = &byte_8200D768;
        else
          v25 = args->argv[1];
        idLib::Printf(fmt: "execing %s\n", v25);
      }
      idCmdSystemLocal::InsertCommandText(this: &cmdSystemLocal, text: v8);
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
      fileSystem->FreeFile(this: fileSystem, a2: v26);
      idStr::FreeData(this: &v31);
      idFile_Memory::~idFile_Memory(this: &v29);
      idParser::~idParser(this: &v30);
      goto LABEL_49;
    }
    while ( 1 )
    {
      if ( v17 > 0 )
      {
        if ( v31.linesCrossed != 0 )
        {
          v18 = "\n";
LABEL_29:
          idFile_String::operator+=(this: (idFile_String *)&v29, str: v18);
          goto LABEL_30;
        }
        if ( v31.whiteSpaceEnd_p > v31.whiteSpaceStart_p )
        {
          v18 = " ";
          goto LABEL_29;
        }
      }
LABEL_30:
      if ( v31.type == 1 )
      {
        v19 = "\"";
        v20 = 0;
        do
        {
          ++v19;
          ++v20;
        }
        while ( *v19 != 0 );
        v29.Write(this: &v29, a2: "\"", a3: v20);
        v21 = 0;
        if ( *v31.data != 0 )
        {
          do
            ++v21;
          while ( v31.data[v21] != 0 );
        }
        ((void (__fastcall *)(idFile_Memory *))v29.Write)(a1: &v29);
        v22 = "\"";
        v23 = 0;
        do
        {
          ++v22;
          ++v23;
        }
        while ( *v22 != 0 );
        v29.Write(this: &v29, a2: "\"", a3: v23);
      }
      else
      {
        if ( v31.type == 2 )
        {
          idFile_String::operator+=(this: (idFile_String *)&v29, str: "'");
          idFile_String::operator+=(this: (idFile_String *)&v29, str: v31.data);
          data = "'";
        }
        else
        {
          data = v31.data;
        }
        idFile_String::operator+=(this: (idFile_String *)&v29, str: data);
      }
      ++v17;
      if ( !idParser::ReadToken(this: &v30, token: &v31) )
        goto LABEL_43;
    }
  }
  idParser::~idParser(this: &v30);
LABEL_49:
  idStr::FreeData(this: &v28);
}


// ========================================================================
// __unwind$114605
// EA  : 0x82EFD568
// RVA : 0x00EFD568
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114605()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5408 + 96));
}


// ========================================================================
// __unwind$114606
// EA  : 0x82EFD590
// RVA : 0x00EFD590
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114606()
{
  int v0; // r12

  idParser::~idParser(this: (idParser *)(v0 - 5408 + 464));
}


// ========================================================================
// __unwind$114607
// EA  : 0x82EFD5B8
// RVA : 0x00EFD5B8
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114607()
{
  int v0; // r12

  idFile_String::~idFile_String(this: (idFile_String *)(v0 - 5408 + 128));
}


// ========================================================================
// __unwind$114608
// EA  : 0x82EFD5E0
// RVA : 0x00EFD5E0
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114608()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5408 + 1120));
}


// ========================================================================
// ?Vstr_f@idCmdSystemLocal@@CAXABVidCmdArgs@@@Z
// EA  : 0x82EFD608
// RVA : 0x00EFD608
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystemLocal::Vstr_f(const idCmdArgs *args)
{
  const char *v1; // r3
  __int64 v2; // r8
  __int64 v3; // r6
  __int64 v4; // r10
  va *v5; // r3
  int v6; // [sp+8h] [-1058h]
  int v7; // [sp+Ch] [-1054h]
  int v8; // [sp+10h] [-1050h]
  int v9; // [sp+14h] [-104Ch]
  int v10; // [sp+18h] [-1048h]
  int v11; // [sp+1Ch] [-1044h]
  va v12; // [sp+50h] [-1010h] BYREF

  if ( args->argc == 2 )
  {
    v1 = cvarSystem->GetCVarString(this: cvarSystem, a2: args->argv[1], a3: &byte_8200D768);
    HIDWORD(v2) = &unk_821C0000;
    HIDWORD(v3) = v1;
    v5 = va::va(this: &v12, fmt: "%s\n", a3: v3, a4: v2, a5: v4, a6: v6, a7: v7, a8: v8, a9: v9, a10: v10, a11: v11);
    idStr::Append(this: &cmdSystemLocal.textBuffer, text: v5->buffer);
  }
  else
  {
    idLib::Printf(fmt: "vstr <variablename> : execute a variable command\n");
  }
}


// ========================================================================
// ?Init@idCmdSystemLocal@@UAAXXZ
// EA  : 0x82EFD6A0
// RVA : 0x00EFD6A0
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystemLocal::Init(idCmdSystemLocal *this)
{
  idCommandLink *i; // r30
  idStrStatic<32768> *p_textBuffer; // r31
  char *data; // r10

  this->AddCommand(this, a2: "listCmds", a3: idCmdSystemLocal::List_f, a4: "lists commands", a5: nullptr);
  this->AddCommand(
    this,
    a2: "exec",
    a3: idCmdSystemLocal::Exec_f,
    a4: "executes a config file",
    a5: idCmdSystem::ArgCompletion_ConfigName);
  this->AddCommand(
    this,
    a2: "vstr",
    a3: idCmdSystemLocal::Vstr_f,
    a4: "inserts the current value of a cvar as command text",
    a5: nullptr);
  this->AddCommand(this, a2: "echo", a3: idCmdSystemLocal::Echo_f, a4: "prints text", a5: nullptr);
  this->AddCommand(this, a2: "parse", a3: idCmdSystemLocal::Parse_f, a4: "prints tokenized string", a5: nullptr);
  this->AddCommand(
    this,
    a2: "wait",
    a3: idCmdSystemLocal::Wait_f,
    a4: "delays remaining buffered commands one or more frames",
    a5: nullptr);
  for ( i = CommandLinks(); i != nullptr; i = i->next )
    this->AddCommand(this, a2: i->cmdName_, a3: i->function_, a4: i->description_, a5: i->argCompletion_);
  p_textBuffer = &this->textBuffer;
  if ( p_textBuffer->allocedAndFlag >= 0 )
  {
    idStr::FreeData(this: p_textBuffer);
    p_textBuffer->len = 0;
    p_textBuffer->allocedAndFlag = 20;
    p_textBuffer->data = p_textBuffer->baseBuffer;
    p_textBuffer->baseBuffer[0] = 0;
  }
  else
  {
    data = p_textBuffer->data;
    p_textBuffer->len = 0;
    *data = 0;
  }
}


// ========================================================================
// ?ArgCompletion_MapName@idCmdSystem@@SAXAAVidAutoComplete@@@Z
// EA  : 0x82EFD888
// RVA : 0x00EFD888
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystem::ArgCompletion_MapName(idAutoComplete *autoComplete)
{
  idFile *v2; // r29
  int v3; // r19
  const char *v4; // r4
  char *v5; // r22
  int i; // r21
  fsOrigin_t v7; // r7
  unsigned int v8; // r6
  fsOrigin_t v9; // r7
  unsigned int v10; // r6
  int len; // r11
  unsigned int v12; // [sp+50h] [-4F0h] BYREF
  int v13; // [sp+54h] [-4ECh] BYREF
  int v14; // [sp+58h] [-4E8h] BYREF
  int v15; // [sp+5Ch] [-4E4h] BYREF
  _WORD v16[16]; // [sp+60h] [-4E0h] BYREF
  idStr v17; // [sp+80h] [-4C0h] BYREF
  idStr v18; // [sp+A0h] [-4A0h] BYREF
  int argc; // [sp+C0h] [-480h]
  int v20; // [sp+C4h] [-47Ch] BYREF
  idStr v21; // [sp+D0h] [-470h] BYREF
  char v22; // [sp+F0h] [-450h] BYREF
  idStr v23; // [sp+110h] [-430h] BYREF
  idStr v24; // [sp+130h] [-410h] BYREF
  char v25; // [sp+150h] [-3F0h] BYREF
  idFile_Memory v26; // [sp+250h] [-2F0h] BYREF
  idStr v27; // [sp+3A0h] [-1A0h] BYREF
  char v28; // [sp+3C0h] [-180h] BYREF

  cmdSystem->ArgCompletion_FolderExtension(this: cmdSystem, a2: autoComplete, a3: "maps/", a4: "map", a5: true);
  if ( fileSystem->FileExists(this: fileSystem, a2: "gameresources.resources", a3: false) )
  {
    v2 = fileSystem->OpenFileRead(this: fileSystem, a2: "gameresources.resources", a3: 1, a4: 0);
    if ( v2 != nullptr )
    {
      v3 = 1;
      argc = autoComplete->args.argc;
      if ( argc - 1 >= 1 )
        v3 = argc - 1;
      if ( v3 < 0 || v3 >= argc )
        v4 = &byte_8200D768;
      else
        v4 = autoComplete->args.argv[v3];
      idStr::idStr(this: &v23, text: v4);
      v2->Seek(this: v2, a2: 0, a3: FS_SEEK_SET);
      v15 = 0;
      v2->Read(this: v2, a2: &v15, a3: 4u);
      if ( v15 == 580168653 || v15 == 293862076 )
      {
        v2->Read(this: v2, a2: &v13, a3: 4u);
        v2->Read(this: v2, a2: &v12, a3: 4u);
        v5 = (char *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\csystems\\CmdSystem.cpp(652) : TAG_RESOURCE",
                       size: v12,
                       tag: TAG_RESOURCE,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
        v2->Seek(this: v2, a2: v13, a3: FS_SEEK_SET);
        v2->ReadOfs(this: v2, a2: v13, a3: v5, a4: v12);
        idFile_Memory::idFile_Memory(this: &v26, name: "resourceHeader");
        idFile_Memory::SetReadOnlyData(this: &v26, data: v5, length: v12);
        v26.Read(this: &v26, a2: &v14, a3: 4u);
        v16[15] = 1280;
        memset(&v16[8], 0, 14);
        for ( i = 0; i < v14; ++i )
        {
          v21.baseBuffer[0] = 0;
          v22 = 0;
          v21.data = &v22;
          v21.len = 0;
          v21.allocedAndFlag = -2147483616;
          v27.baseBuffer[0] = 0;
          v28 = 0;
          v27.data = &v28;
          v27.len = 0;
          v27.allocedAndFlag = -2147483392;
          v24.baseBuffer[0] = 0;
          v25 = 0;
          v24.data = &v25;
          v24.len = 0;
          v24.allocedAndFlag = -2147483392;
          v26.Read(this: &v26, a2: &v20, a3: 4u);
          idFile::ReadString(this: &v26, string: &v21);
          idFile::ReadString(this: &v26, string: &v27);
          idFile::ReadString(this: &v26, string: &v24);
          idFile_Memory::Seek(this: &v26, offset: v8, origin: v7);
          v26.Read(this: &v26, a2: v16, a3: 4u);
          idFile_Memory::Seek(this: &v26, offset: v10, origin: v9);
          if ( idStr::Icmpn(s1: v24.data, s2: "maps/", n: 5) != 0 )
          {
            idStr::FreeData(this: &v24);
            idStr::FreeData(this: &v27);
          }
          else
          {
            v18.allocedAndFlag = 20;
            v18.len = 0;
            v18.data = v18.baseBuffer;
            v18.baseBuffer[0] = 0;
            idStr::ExtractFileName(this: &v24, dest: &v18);
            if ( idStr::Icmp(s1: v18.data, s2: "_world.bmodel") != 0 )
            {
              idStr::FreeData(this: &v18);
              idStr::FreeData(this: &v24);
              idStr::FreeData(this: &v27);
            }
            else
            {
              idStr::idStr(this: &v17, text: &v24);
              idStr::StripLeading(this: &v17, string: "maps/");
              len = v23.len;
              if ( v23.len == 0 )
                goto _M115469;
              if ( v23.len >= v17.len )
                len = v17.len;
              if ( idStr::Icmpn(s1: v23.data, s2: v17.data, n: len) != 0 )
              {
                idStr::FreeData(this: &v17);
                idStr::FreeData(this: &v18);
                idStr::FreeData(this: &v24);
                idStr::FreeData(this: &v27);
              }
              else
              {
_M115469:
                idStr::StripFilename(this: &v17);
                idStr::StripTrailing(this: &v17, string: "/");
                idStr::StripTrailing(this: &v17, string: "_combo");
                idStr::StripTrailing(this: &v17, string: "/");
                idAutoComplete::Append(this: autoComplete, suggestion: &v17, completingArg: v3);
                idStr::FreeData(this: &v17);
                idStr::FreeData(this: &v18);
                idStr::FreeData(this: &v24);
                idStr::FreeData(this: &v27);
              }
            }
          }
          idStr::FreeData(this: &v21);
        }
        idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
        idFile_Memory::~idFile_Memory(this: &v26);
      }
      else
      {
        idLib::Warning(fmt: "Resource format has changed, patch auto-completion to match resource format!");
      }
      idStr::FreeData(this: &v23);
    }
  }
}


// ========================================================================
// __unwind$114977
// EA  : 0x82EFDD8C
// RVA : 0x00EFDD8C
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114977()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1344 + 272));
}


// ========================================================================
// __unwind$114978
// EA  : 0x82EFDDB4
// RVA : 0x00EFDDB4
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114978()
{
  int v0; // r12

  idFile_Memory::~idFile_Memory(this: (idFile_Memory *)(v0 - 1344 + 592));
}


// ========================================================================
// __unwind$114979
// EA  : 0x82EFDDDC
// RVA : 0x00EFDDDC
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114979()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 1344 + 112));
}


// ========================================================================
// __unwind$114980
// EA  : 0x82EFDE04
// RVA : 0x00EFDE04
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114980()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1344 + 208));
}


// ========================================================================
// __unwind$114981
// EA  : 0x82EFDE2C
// RVA : 0x00EFDE2C
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114981()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1344 + 928));
}


// ========================================================================
// __unwind$114982
// EA  : 0x82EFDE54
// RVA : 0x00EFDE54
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114982()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1344 + 304));
}


// ========================================================================
// __unwind$114983
// EA  : 0x82EFDE7C
// RVA : 0x00EFDE7C
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114983()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1344 + 160));
}


// ========================================================================
// __unwind$114984
// EA  : 0x82EFDEA4
// RVA : 0x00EFDEA4
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_114984()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1344 + 128));
}


// ========================================================================
// ?ArgCompletion_FolderExtension@idCmdSystemLocal@@UAAXAAVidAutoComplete@@PBD1_N@Z
// EA  : 0x82EFDED8
// RVA : 0x00EFDED8
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __fastcall idCmdSystemLocal::ArgCompletion_FolderExtension(
        idCmdSystemLocal *this,
        idAutoComplete *autoComplete,
        const char *folders,
        const char *extensions,
        bool stripFolder)
{
  int v8; // r21
  const char *v9; // r4
  idStr *list; // r14
  BOOL v11; // r19
  int len; // r5
  idStr *v13; // r29
  size_t v14; // r30
  int v15; // r4
  idFileList *v16; // r28
  idFileList *v17; // r25
  int v18; // r29
  int v19; // r30
  int v20; // r24
  int v21; // r26
  char v22; // r27
  int v23; // r29
  int v24; // r30
  int v25; // r11
  int v26; // r10
  idStr *v27; // r28
  int size; // r30
  idStr *v29; // r29
  int argc; // [sp+50h] [-1A0h]
  int num; // [sp+50h] [-1A0h]
  idList<idStr,5> v32; // [sp+60h] [-190h] BYREF
  idStr v33; // [sp+70h] [-180h] BYREF
  idStr v34; // [sp+90h] [-160h] BYREF
  idStr v35; // [sp+B0h] [-140h] BYREF
  idStr v36; // [sp+D0h] [-120h] BYREF
  idStr v37; // [sp+F0h] [-100h] BYREF
  idStr v38; // [sp+110h] [-E0h] BYREF
  idStr v39[6]; // [sp+130h] [-C0h] BYREF

  argc = autoComplete->args.argc;
  v8 = 1;
  if ( argc - 1 >= 1 )
    v8 = argc - 1;
  if ( v8 < 0 || v8 >= argc )
    v9 = &byte_8200D768;
  else
    v9 = autoComplete->args.argv[v8];
  idStr::idStr(this: &v38, text: v9);
  *(_WORD *)&v32.memTag = 1280;
  memset(&v32, 0, 14);
  idStrListBreakupString(list: &v32, string: folders, separator: 59);
  if ( v32.num > 0 )
  {
    num = v32.num;
    list = v32.list;
    v11 = stripFolder;
    while ( 1 )
    {
      idStr::idStr(this: &v35, text: list);
      v33.len = 0;
      v33.data = v33.baseBuffer;
      v33.allocedAndFlag = 20;
      v33.baseBuffer[0] = 0;
      idStr::ExtractFilePath(this: &v38, dest: &v33);
      if ( v11 || v33.len == 0 )
        break;
      len = v35.len;
      if ( v33.len < v35.len )
        len = v33.len;
      if ( idStr::Icmpn(s1: v33.data, s2: v35.data, n: len) == 0 )
        goto LABEL_22;
      idStr::FreeData(this: &v33);
LABEL_48:
      idStr::FreeData(this: &v35);
      ++list;
      if ( --num == 0 )
        goto LABEL_49;
    }
    v13 = operator+(result: v39, a: &v35, b: &v33);
    v14 = v13->len;
    v15 = v13->len + 1;
    if ( v33.allocedAndFlag >= 0 )
    {
      if ( v15 > (v33.allocedAndFlag & 0x7FFFFFFF) )
        idStr::ReAllocate(this: &v33, amount: v15, keepold: false);
    }
    else if ( v15 > (v33.allocedAndFlag & 0x7FFFFFFF)
           && AssertFailed(
                file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                line: 463,
                expression: "amount <= GetAlloced()",
                inlineBreak: true) )
    {
      __trap();
    }
    memcpy(Dst: v33.data, Src: v13->data, Size: v14);
    v33.data[v14] = 0;
    v33.len = v14;
    idStr::FreeData(this: v39);
LABEL_22:
    idStr::StripLeading(this: &v33, c: 47);
    idStr::StripTrailing(this: &v33, c: 47);
    if ( v33.len == 0 )
      idStr::operator=(this: &v33, text: "/");
    v16 = fileSystem->ListFiles(this: fileSystem, a2: v33.data, a3: extensions, a4: 1, a5: 1);
    v17 = fileSystem->ListFiles(this: fileSystem, a2: v33.data, a3: "/", a4: 1, a5: 1);
    v18 = 0;
    if ( v16->list.num > 0 )
    {
      v19 = 0;
      do
      {
        idStr::idStr(this: &v37, text: v16->list.list[v19].data);
        if ( v11 )
          idStr::StripLeading(this: &v37, string: v35.data);
        idAutoComplete::Append(this: autoComplete, suggestion: &v37, completingArg: v8);
        idStr::FreeData(this: &v37);
        ++v18;
        ++v19;
      }
      while ( v18 < v16->list.num );
    }
    v20 = 0;
    if ( v17->list.num > 0 )
    {
      v21 = 0;
      do
      {
        v22 = 0;
        v23 = 0;
        if ( v16->list.num > 0 )
        {
          v24 = 0;
          do
          {
            idStr::idStr(this: &v36, text: v16->list.list[v24].data);
            idStr::StripFileExtension(this: &v36);
            if ( idStr::Icmp(s1: v36.data, s2: v17->list.list[v21].data) == 0 )
              v22 = 1;
            idStr::FreeData(this: &v36);
            ++v23;
            ++v24;
          }
          while ( v23 < v16->list.num );
        }
        if ( v22 == 0 )
        {
          idStr::idStr(this: &v34, text: v17->list.list[v21].data);
          if ( v11 )
            idStr::StripLeading(this: &v34, string: v35.data);
          v25 = v34.len + 2;
          v26 = v34.allocedAndFlag & 0x7FFFFFFF;
          if ( v34.allocedAndFlag >= 0 )
          {
            if ( v25 > v26 )
              idStr::ReAllocate(this: &v34, amount: (v25 >> 1) + v25, keepold: true);
          }
          else if ( v25 > v26
                 && AssertFailed(
                      file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                      line: 463,
                      expression: "amount <= GetAlloced()",
                      inlineBreak: true) )
          {
            __trap();
          }
          v34.data[v34.len++] = 47;
          v34.data[v34.len] = 0;
          idAutoComplete::Append(this: autoComplete, suggestion: &v34, completingArg: v8);
          idStr::FreeData(this: &v34);
        }
        ++v20;
        ++v21;
      }
      while ( v20 < v17->list.num );
    }
    fileSystem->FreeFileList(this: fileSystem, a2: v16);
    fileSystem->FreeFileList(this: fileSystem, a2: v17);
    idStr::FreeData(this: &v33);
    goto LABEL_48;
  }
LABEL_49:
  if ( v32.listStatic == 0 || v32.listStatic == 2 )
  {
    v27 = v32.list;
    if ( v32.list != nullptr )
    {
      size = v32.size;
      if ( v32.size > 0 )
      {
        v29 = v32.list;
        do
        {
          idStr::FreeData(this: v29);
          --size;
          ++v29;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: v27, align: ALIGN_16);
    }
  }
  idStr::FreeData(this: &v38);
}


// ========================================================================
// __unwind$115597
// EA  : 0x82EFE3DC
// RVA : 0x00EFE3DC
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_115597()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 272));
}


// ========================================================================
// __unwind$115598
// EA  : 0x82EFE404
// RVA : 0x00EFE404
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_115598()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 496 + 96));
}


// ========================================================================
// __unwind$115599
// EA  : 0x82EFE42C
// RVA : 0x00EFE42C
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_115599()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 176));
}


// ========================================================================
// __unwind$115600
// EA  : 0x82EFE454
// RVA : 0x00EFE454
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_115600()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 112));
}


// ========================================================================
// __unwind$115601
// EA  : 0x82EFE47C
// RVA : 0x00EFE47C
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_115601()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 304));
}


// ========================================================================
// __unwind$115602
// EA  : 0x82EFE4A4
// RVA : 0x00EFE4A4
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_115602()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 240));
}


// ========================================================================
// __unwind$115603
// EA  : 0x82EFE4CC
// RVA : 0x00EFE4CC
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_115603()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 208));
}


// ========================================================================
// __unwind$115604
// EA  : 0x82EFE4F4
// RVA : 0x00EFE4F4
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void _unwind_115604()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 144));
}


// ========================================================================
// `dynamic initializer for 'cmdSystemLocal''
// EA  : 0x83394370
// RVA : 0x01394370
// PDB : w:\tech5\shared\idlib\csystems\cmdsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cmdSystemLocal__()
{
  cmdSystemLocal.textBuffer.allocedAndFlag = -2147450880;
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cmdSystemLocal__);
}

