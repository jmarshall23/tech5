
// ========================================================================
// Cmd_ConUnwatch_f
// EA  : 0x826702C0
// RVA : 0x006702C0
// PDB : w:\tech5\engine\framework\consolewatch.cpp
// ========================================================================

void __fastcall Cmd_ConUnwatch_f(const idCmdArgs *args)
{
  const char *v1; // r28
  const char *v2; // r11
  const char *v3; // r10
  int v4; // r9
  int v5; // r9
  bool v6; // zf
  int v7; // r29
  int i; // r31

  if ( args->argc >= 1 )
  {
    if ( args->argc <= 1 )
      v1 = &byte_8200D768;
    else
      v1 = args->argv[1];
    v2 = v1;
    v3 = "all";
    do
    {
      v4 = *(unsigned __int8 *)v2;
      v6 = v4 == 0;
      v5 = v4 - *(unsigned __int8 *)v3;
      if ( v6 )
        break;
      ++v2;
      ++v3;
    }
    while ( v5 == 0 );
    if ( v5 != 0 )
    {
      v7 = 0;
      if ( cwatchList.num > 0 )
      {
        for ( i = 0; idStr::Cmp(s1: cwatchList.list[i]._watchString.data, s2: v1) != 0; ++i )
        {
          if ( ++v7 >= cwatchList.num )
            return;
        }
        if ( v7 >= 0 )
          idList<idConsoleWatch,5>::RemoveIndex(this: &cwatchList, index: v7);
      }
    }
    else
    {
      idList<idTarget_TestPlayerState::playerState_Job_t,5>::~idList<idTarget_TestPlayerState::playerState_Job_t,5>(this: (vaiAction_t::throwAttachedItem_t *)&cwatchList);
    }
  }
}


// ========================================================================
// Cmd_ConWatch_f
// EA  : 0x82670530
// RVA : 0x00670530
// PDB : w:\tech5\engine\framework\consolewatch.cpp
// ========================================================================

void __fastcall Cmd_ConWatch_f(const idCmdArgs *args)
{
  const char *v2; // r4
  const char *v3; // r3
  const char *v4; // r3
  int v5; // r30
  int v6; // r28
  idConsoleWatch *v7; // r30
  size_t len; // r29
  idConsoleWatch v9[2]; // [sp+60h] [-60h] BYREF

  v9[0]._watchString.len = 0;
  v9[0]._watchString.baseBuffer[0] = 0;
  v9[0]._watchString.allocedAndFlag = 20;
  v9[0]._watchString.data = v9[0]._watchString.baseBuffer;
  v9[0]._drawX = -1;
  v9[0]._drawY = -1;
  if ( args->argc <= 1 )
    v2 = &byte_8200D768;
  else
    v2 = args->argv[1];
  idStr::operator=(this: &v9[0]._watchString, text: v2);
  if ( args->argc >= 3 )
  {
    if ( args->argc <= 2 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[2];
    v9[0]._drawX = atol(nptr: v3);
  }
  if ( args->argc >= 4 )
  {
    if ( args->argc <= 3 )
      v4 = &byte_8200D768;
    else
      v4 = args->argv[3];
    v9[0]._drawY = atol(nptr: v4);
  }
  v5 = 0;
  if ( cwatchList.num <= 0 )
  {
LABEL_18:
    idList<idConsoleWatch,5>::Append(this: &cwatchList, obj: v9);
  }
  else
  {
    v6 = 0;
    while ( idStr::Cmp(s1: cwatchList.list[v6]._watchString.data, s2: v9[0]._watchString.data) != 0 )
    {
      ++v5;
      ++v6;
      if ( v5 >= cwatchList.num )
        goto LABEL_18;
    }
    v7 = &cwatchList.list[v5];
    len = v9[0]._watchString.len;
    idStr::EnsureAlloced(
      this: &v7->_watchString,
      amount: v9[0]._watchString.len + 1,
      keepold: false,
      geometricGrowth: false);
    memcpy(Dst: v7->_watchString.data, Src: v9[0]._watchString.data, Size: len);
    v7->_watchString.data[len] = 0;
    v7->_watchString.len = len;
    v7->_drawX = v9[0]._drawX;
    v7->_drawY = v9[0]._drawY;
  }
  idStr::FreeData(this: &v9[0]._watchString);
}


// ========================================================================
// __unwind$219791_0
// EA  : 0x826706B4
// RVA : 0x006706B4
// PDB : w:\tech5\engine\framework\consolewatch.cpp
// ========================================================================

void _unwind_219791_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// `dynamic initializer for 'cwatchList''
// EA  : 0x8333B678
// RVA : 0x0133B678
// PDB : w:\tech5\engine\framework\consolewatch.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cwatchList__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cwatchList__);
}


// ========================================================================
// `dynamic initializer for 'cwatchResultTextList''
// EA  : 0x8333B688
// RVA : 0x0133B688
// PDB : w:\tech5\engine\framework\consolewatch.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cwatchResultTextList__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cwatchResultTextList__);
}


// ========================================================================
// `dynamic initializer for 'cwatch''
// EA  : 0x8333B698
// RVA : 0x0133B698
// PDB : w:\tech5\engine\framework\consolewatch.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__cwatch__()
{
  return idCommandLink::idCommandLink(
           this: &cwatch,
           cmdName: "con_watch",
           function: Cmd_ConWatch_f,
           description: "adds a new console watch - displays per frame results of console var/function printed output",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'cunwatch''
// EA  : 0x8333B6C0
// RVA : 0x0133B6C0
// PDB : w:\tech5\engine\framework\consolewatch.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__cunwatch__()
{
  return idCommandLink::idCommandLink(
           this: &cunwatch,
           cmdName: "con_unwatch",
           function: Cmd_ConUnwatch_f,
           description: "removes the specified console watch. Specify 'all' to remove all watches.",
           argCompletion: nullptr);
}

