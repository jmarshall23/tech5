
// ========================================================================
// ?End@idPLogScope@@QAAXPA_J@Z
// EA  : 0x82F3D848
// RVA : 0x00F3D848
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void __fastcall idPLogScope::End(idPLogScope *this, __int64 *totalTicks)
{
  idPLog::logEntry_t *v4; // r31
  __int64 v5; // r11

  if ( this->logIndex >= 0 )
  {
    v4 = &this->pLog->logEntries.list[this->logIndex];
    LODWORD(v5) = ((unsigned __int64)Sys_GetClockTicks() >> 32) - LODWORD(v4->totalTicks);
    v4->totalTicks = v5;
    if ( totalTicks != nullptr )
      *totalTicks = v5;
    this->pLog->lastEntry = v4->parent;
    this->logIndex = -1;
  }
}


// ========================================================================
// GenerateMaskFromArgs
// EA  : 0x82F3D8B0
// RVA : 0x00F3D8B0
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

int __fastcall GenerateMaskFromArgs(const idCmdArgs *args)
{
  __int64 v1; // r25
  int v3; // r27
  int i; // r29
  const char **v5; // r31
  unsigned int v6; // r30
  char *v7; // r3

  LODWORD(v1) = 1;
  v3 = 0;
  for ( i = 1; i < args->argc; ++i )
  {
    v5 = pLogGroupNames;
    v6 = 0;
    while ( 1 )
    {
      HIDWORD(v1) = *v5;
      v7 = idCmdArgs::Argv(this: args, arg: i);
      if ( idStr::Icmp(s1: v7, s2: (const char *)HIDWORD(v1)) == 0 )
        break;
      ++v6;
      ++v5;
      if ( v6 >= 0xC )
        goto LABEL_7;
    }
    v3 |= v1 << v6;
LABEL_7:
    ;
  }
  return v3;
}


// ========================================================================
// plog_disable_f
// EA  : 0x82F3D948
// RVA : 0x00F3D948
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void __fastcall plog_disable_f(__int64 args, __int64 a2, __int64 a3, __int64 a4)
{
  const idCmdArgs *v4; // r31
  const char *v5; // r3
  unsigned __int64 v6; // r11
  int v7; // [sp+8h] [-58h]
  int v8; // [sp+Ch] [-54h]
  int v9; // [sp+10h] [-50h]
  int v10; // [sp+14h] [-4Ch]

  v4 = (const idCmdArgs *)HIDWORD(args);
  if ( (int)*(_DWORD *)HIDWORD(args) >= 2 )
  {
    if ( (int)*(_DWORD *)HIDWORD(args) <= 1 )
      v5 = &byte_8200D768;
    else
      v5 = *(const char **)(HIDWORD(args) + 8);
    if ( idStr::Icmp(s1: v5, s2: "ALL") != 0 )
    {
      *(_QWORD *)(HIDWORD(pLog.groupMask) + offsetof(idPLog, groupMask)) = pLog.groupMask
                                                                         & ((unsigned int)~GenerateMaskFromArgs(args: v4)
                                                                          | 0xFFFFFFFF00000000uLL);
    }
    else
    {
      HIDWORD(v6) = &si_vector_decode_cat_0[184];
      LODWORD(v6) = 0;
      pLog.groupMask = v6;
    }
  }
  else
  {
    HIDWORD(args) = "Usage: plog_disable <group1> [group2] [...]\n";
    idLib::Printf(fmt: args, a2, a3, a4, a5: v7, a6: v8, a7: v9, a8: v10);
  }
}


// ========================================================================
// ArgCompletion_PLogGroups
// EA  : 0x82F3E1B0
// RVA : 0x00F3E1B0
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void __fastcall ArgCompletion_PLogGroups(idAutoComplete *autoComplete)
{
  int v2; // r28
  const char *v3; // r4
  int v4; // r29
  const char **v5; // r30
  int len; // r11
  int argc; // [sp+50h] [-A0h]
  idStr v8; // [sp+60h] [-90h] BYREF
  idStr v9; // [sp+80h] [-70h] BYREF
  idStr v10[2]; // [sp+A0h] [-50h] BYREF

  v2 = 1;
  argc = autoComplete->args.argc;
  if ( argc - 1 >= 1 )
    v2 = argc - 1;
  if ( v2 < 0 || v2 >= argc )
    v3 = &byte_8200D768;
  else
    v3 = autoComplete->args.argv[v2];
  idStr::idStr(this: &v9, text: v3);
  v4 = 12;
  v5 = pLogGroupNames;
  do
  {
    idStr::idStr(this: &v8, text: *v5);
    len = v9.len;
    if ( v9.len == 0 )
      goto LABEL_12;
    if ( v9.len >= v8.len )
      len = v8.len;
    if ( idStr::Icmpn(s1: v8.data, s2: v9.data, n: len) == 0 )
    {
LABEL_12:
      idStr::idStr(this: v10, text: *v5);
      idAutoComplete::Append(this: autoComplete, suggestion: v10, completingArg: v2);
      idStr::FreeData(this: v10);
    }
    idStr::FreeData(this: &v8);
    --v4;
    ++v5;
  }
  while ( v4 != 0 );
  idStr::FreeData(this: &v9);
}


// ========================================================================
// __unwind$113774
// EA  : 0x82F3E2A8
// RVA : 0x00F3E2A8
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void _unwind_113774()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$113775
// EA  : 0x82F3E2D0
// RVA : 0x00F3E2D0
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void _unwind_113775()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$113776
// EA  : 0x82F3E2F8
// RVA : 0x00F3E2F8
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void _unwind_113776()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 160));
}


// ========================================================================
// ?Clear@idPLog@@QAAXXZ
// EA  : 0x82F3E658
// RVA : 0x00F3E658
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void __fastcall idPLog::Clear(idPLog *this)
{
  __int64 v1; // r30
  idList<idPLog::logEntry_t,44> *p_logEntries; // r31
  int v3; // r11

  HIDWORD(v1) = this;
  p_logEntries = &this->logEntries;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  if ( *(int *)(HIDWORD(v1) + 24) >= 1
    || (unsigned __int8)idList<cacheLineStat_t,5>::Resize(
                          this: (idList<idPLog::logEntry_t,44> *)(HIDWORD(v1) + 16),
                          newsize: 1) != 0 )
  {
    v3 = *(_DWORD *)(HIDWORD(v1) + 24);
    if ( v3 > 1 )
      v3 = 1;
    *(_DWORD *)(HIDWORD(v1) + 20) = v3;
  }
  LODWORD(v1) = 0;
  p_logEntries->list->label = rootLabel;
  p_logEntries->list->parent = 0;
  p_logEntries->list->totalTicks = v1;
  idMem::PopHeap(this: &mem);
  *(_DWORD *)(HIDWORD(v1) + 32) = 0;
}


// ========================================================================
// plog_enable_f
// EA  : 0x82F3E778
// RVA : 0x00F3E778
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void __fastcall plog_enable_f(__int64 args, __int64 a2, __int64 a3, __int64 a4)
{
  const idCmdArgs *v4; // r31
  const char *v5; // r3
  int v6; // [sp+8h] [-58h]
  int v7; // [sp+Ch] [-54h]
  int v8; // [sp+10h] [-50h]
  int v9; // [sp+14h] [-4Ch]

  v4 = (const idCmdArgs *)HIDWORD(args);
  if ( (int)*(_DWORD *)HIDWORD(args) >= 2 )
  {
    if ( (int)*(_DWORD *)HIDWORD(args) <= 1 )
      v5 = &byte_8200D768;
    else
      v5 = *(const char **)(HIDWORD(args) + 8);
    if ( idStr::Icmp(s1: v5, s2: "ALL") != 0 )
    {
      GenerateMaskFromArgs(args: v4);
      pLog.groupMask |= HIDWORD(pLog.groupMask);
    }
    else
    {
      pLog.groupMask |= 0xFFFu;
    }
    idPLog::EnsureEntries(this: &pLog);
  }
  else
  {
    HIDWORD(args) = "Usage: plog_enable <group1> [group2] [...]\n";
    idLib::Printf(fmt: args, a2, a3, a4, a5: v6, a6: v7, a7: v8, a8: v9);
  }
}


// ========================================================================
// plog_toggle_f
// EA  : 0x82F3E838
// RVA : 0x00F3E838
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void __fastcall plog_toggle_f(__int64 args, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int groupMask; // r11
  unsigned __int64 v5; // r10
  unsigned __int64 v6; // r11
  unsigned __int64 v7; // r11
  int v8; // [sp+8h] [-58h]
  int v9; // [sp+Ch] [-54h]
  int v10; // [sp+10h] [-50h]
  int v11; // [sp+14h] [-4Ch]

  if ( (int)*(_DWORD *)HIDWORD(args) >= 1 )
  {
    if ( *(_DWORD *)HIDWORD(args) == 1 )
    {
      groupMask = pLog.groupMask;
      if ( LODWORD(pLog.groupMask) != 0 )
      {
        HIDWORD(v5) = allocationCurrent[242];
        LODWORD(v5) = 0;
        pLog.groupMask = v5;
        oldMask = groupMask;
      }
      else
      {
        v6 = oldMask;
        if ( (_DWORD)oldMask == 0 )
          LODWORD(v6) = 4095;
        pLog.groupMask = v6;
        idPLog::EnsureEntries(this: &pLog);
        LODWORD(v7) = 0;
        oldMask = v7;
      }
    }
    else
    {
      GenerateMaskFromArgs(args: (const idCmdArgs *)HIDWORD(args));
      pLog.groupMask ^= HIDWORD(pLog.groupMask);
      idPLog::EnsureEntries(this: &pLog);
    }
  }
  else
  {
    HIDWORD(args) = "Usage: plog_toggle <group1> [group2] [...]\n";
    idLib::Printf(fmt: args, a2, a3, a4, a5: v8, a6: v9, a7: v10, a8: v11);
  }
}


// ========================================================================
// ?GetOverHeadTicks@idPLog@@AAA_JXZ
// EA  : 0x82F3E920
// RVA : 0x00F3E920
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

int __fastcall idPLog::GetOverHeadTicks(idPLog *this)
{
  int i; // r23
  int v4; // r25
  int j; // r26
  idPLog::logEntry_t *v6; // r30
  int v7; // r29
  __int64 v8; // r3
  idPLog::logEntry_t *v9; // r30
  int v10; // r3
  int parent; // r11
  __int64 v12; // r9
  int v13; // r3
  int overHeadTicks; // r11
  int v15; // r10

  if ( this->overHeadTicks >= 0 )
    return this->overHeadTicks;
  overheadLog.groupMask |= 1u;
  idPLog::EnsureEntries(this: &overheadLog);
  for ( i = 4; i != 0; --i )
  {
    v4 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    for ( j = 1000; j != 0; --j )
    {
      if ( (overheadLog.groupMask & 1) != 0 )
      {
        idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
        idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(
          this: &overheadLog.logEntries,
          newSize: overheadLog.logEntries.num + 1);
        if ( overheadLog.logEntries.num >= overheadLog.logEntries.size )
          v6 = &overheadLog.logEntries.list[overheadLog.logEntries.size - 1];
        else
          v6 = &overheadLog.logEntries.list[overheadLog.logEntries.num++];
        idMem::PopHeap(this: &mem);
        v6->label = "overheadLog";
        v6->parent = overheadLog.lastEntry;
        v7 = overheadLog.logEntries.num - 1;
        overheadLog.lastEntry = overheadLog.logEntries.num - 1;
        LODWORD(v8) = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v6->totalTicks = v8;
        if ( v7 >= 0 )
        {
          v9 = &overheadLog.logEntries.list[v7];
          v10 = (unsigned __int64)Sys_GetClockTicks() >> 32;
          parent = v9->parent;
          LODWORD(v12) = v10 - LODWORD(v9->totalTicks);
          v9->totalTicks = v12;
          overheadLog.lastEntry = parent;
        }
      }
    }
    v13 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    overHeadTicks = this->overHeadTicks;
    v15 = v13 - v4;
    if ( overHeadTicks < 0 || v15 < overHeadTicks )
      this->overHeadTicks = v15;
  }
  if ( overheadLog.logEntries.listStatic == 0 || overheadLog.logEntries.listStatic == 2 )
  {
    if ( overheadLog.logEntries.list != nullptr )
      idMem::Free(this: &mem, ptr: overheadLog.logEntries.list, align: ALIGN_16);
    overheadLog.logEntries.list = nullptr;
    overheadLog.logEntries.size = 0;
  }
  overheadLog.logEntries.num = 0;
  this->overHeadTicks /= 1000;
  overheadLog.groupMask = 0x3E800000000LL;
  return this->overHeadTicks;
}


// ========================================================================
// ?SubtractOverhead@idPLog@@AAAXXZ
// EA  : 0x82F3EAD8
// RVA : 0x00F3EAD8
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPLog::SubtractOverhead(idPLog *this)
{
  int v2; // r2 OVERLAPPED
  int v3; // r10
  int v4; // r9
  idPLog::logEntry_t *list; // r11
  int parent; // r5
  int v7; // r3

  idPLog::GetOverHeadTicks(this);
  v3 = 1;
  if ( this->logEntries.num > 1 )
  {
    v4 = 1;
    do
    {
      list = this->logEntries.list;
      ++v3;
      parent = list[v4++].parent;
      v7 = LODWORD(list[parent].totalTicks) - this->overHeadTicks;
      list[parent].totalTicks = *(_QWORD *)(&v2 - 1);
    }
    while ( v3 < this->logEntries.num );
  }
}


// ========================================================================
// ?ShowUniqueEntries@idPLog@@QAAXM_J@Z
// EA  : 0x82F3EB60
// RVA : 0x00F3EB60
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPLog::ShowUniqueEntries(idPLog *this, double thresholdMS, int a3, const __int64 adjustByTicks)
{
  __int64 v4; // r28
  int v7; // r30
  __int64 v8; // r3
  __int64 v9; // r6
  int v10; // r3 OVERLAPPED
  double v11; // fp29
  __int64 v12; // r8 OVERLAPPED
  unsigned __int64 v13; // r6 OVERLAPPED
  int num; // r29
  int v15; // r30
  idPLog::logEntry_t *list; // r24
  int v17; // r11
  const char **p_label; // r10
  bool v19; // cr56
  idPLog::logEntry_t *v20; // r11
  idPLog::logEntry_t *v21; // r11
  const char *label; // r9
  __int64 v23; // r10
  double clockTicks; // fp31
  __int64 v25; // r3
  double v26; // fp27
  __int128 v27; // r4
  __int64 v28; // r6
  __int64 v29; // r10
  __int64 v30; // r8
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r6
  unsigned __int64 groupMask; // r4
  __int64 v35; // r28
  const char **v36; // r30
  __int64 v37; // r4
  bool v38; // zf
  __int64 v39; // r8
  __int64 v40; // r10 OVERLAPPED
  double valueFloat; // fp31
  int *p_parent; // r30
  double v43; // fp1
  __int64 v44; // r6
  __int64 v45; // r4
  __int64 v46; // r7 OVERLAPPED
  int v47; // r3
  __int64 v48; // r10
  __int64 v49; // r11
  __int64 v50; // r10
  int overHeadTicks; // r8
  __int64 v52; // r6
  __int64 v53; // r10
  __int64 v54; // r8
  double v55; // fp31
  __int64 v56; // r3
  __int64 v57; // r6
  __int64 v58; // r10
  __int64 v59; // r8
  int v60; // [sp+8h] [-118h]
  int v61; // [sp+8h] [-118h]
  int v62; // [sp+8h] [-118h]
  int v63; // [sp+8h] [-118h]
  int v64; // [sp+8h] [-118h]
  int v65; // [sp+Ch] [-114h]
  int v66; // [sp+Ch] [-114h]
  int v67; // [sp+Ch] [-114h]
  int v68; // [sp+Ch] [-114h]
  int v69; // [sp+Ch] [-114h]
  int v70; // [sp+10h] [-110h]
  int v71; // [sp+10h] [-110h]
  int v72; // [sp+10h] [-110h]
  int v73; // [sp+10h] [-110h]
  int v74; // [sp+10h] [-110h]
  int v75; // [sp+14h] [-10Ch]
  int v76; // [sp+14h] [-10Ch]
  int v77; // [sp+14h] [-10Ch]
  int v78; // [sp+14h] [-10Ch]
  int v79; // [sp+14h] [-10Ch]
  idSort_Quick<sortedEntry_t,idSort_Unique> v80; // [sp+50h] [-D0h] BYREF
  __int64 v81; // [sp+58h] [-C8h]
  __int64 v82; // [sp+60h] [-C0h]
  idList<idPLog::logEntry_t,44> v83; // [sp+70h] [-B0h] BYREF
  idTimer v84[2]; // [sp+80h] [-A0h] BYREF

  LODWORD(v4) = 0;
  v84[0].clockTicks = v4;
  v7 = HIDWORD(adjustByTicks);
  v84[0].__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  v84[0].state = TS_STARTED;
  LODWORD(v8) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  v84[0].start = v8;
  idPLog::SubtractOverhead(this);
  v10 = Sys_ClockTicksPerSecond();
  v81 = *(_QWORD *)&v10;
  v11 = (float)((float)1000.0 / (float)*(__int64 *)&v10);
  if ( this->logEntries.num <= 2
    || (LODWORD(v9) = LODWORD(this->logEntries.list[1].totalTicks) - v7,
        v81 = v9,
        (float)((float)v9 * (float)((float)1000.0 / (float)*(__int64 *)&v10)) >= thresholdMS) )
  {
    memset(&v83, 0, 14);
    *(_WORD *)&v83.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v83);
    HIDWORD(v4) = 1;
    if ( this->logEntries.num <= 1 )
    {
      num = v83.num;
      list = v83.list;
    }
    else
    {
      num = v83.num;
      v15 = 1;
      list = v83.list;
      do
      {
        v17 = 0;
        if ( num <= 0 )
          goto LABEL_12;
        p_label = &list->label;
        while ( this->logEntries.list[v15].label != *p_label )
        {
          ++v17;
          p_label += 4;
          if ( v17 >= num )
            goto LABEL_12;
        }
        v19 = v17 < num;
        v20 = &list[v17];
        ++v20->parent;
        LODWORD(v12) = *(_DWORD *)(HIDWORD(v20->totalTicks) + 12) + LODWORD(v20->totalTicks);
        v20->totalTicks = v12;
        if ( !v19 )
        {
LABEL_12:
          idList<idPLog::logEntry_t,44>::PreAllocateWithGranularity(this: &v83, newSize: num + 1);
          num = v83.num;
          list = v83.list;
          if ( v83.num >= v83.size )
          {
            v21 = &v83.list[v83.size - 1];
          }
          else
          {
            v21 = &v83.list[v83.num];
            num = ++v83.num;
          }
          label = this->logEntries.list[v15].label;
          v21->parent = 1;
          v21->label = label;
          LODWORD(v12) = &this->logEntries.list[v15];
          *(__int64 *)((char *)&v12 + 4) = *(_QWORD *)(v12 + 8);
          v21->totalTicks = *(__int64 *)((char *)&v12 + 4);
        }
        ++HIDWORD(v4);
        ++v15;
      }
      while ( SHIDWORD(v4) < this->logEntries.num );
    }
    LODWORD(v23) = &idSort_Unique::`vftable';
    v80.__vftable = (idSort_Quick<sortedEntry_t,idSort_Unique>_vtbl *)&idSort_Unique::`vftable';
    HIDWORD(v23) = idSort_Quick<sortedEntry_t,idSort_Unique>::Sort;
    HIDWORD(v13) = num;
    idSort_Quick<sortedEntry_t,idSort_Unique>::Sort(
      this: &v80,
      base: (sortedEntry_t *)list,
      num: v13,
      a4: SHIDWORD(v12),
      a5: v12,
      a6: v23);
    v80.__vftable = (idSort_Quick<sortedEntry_t,idSort_Unique>_vtbl *)&idSort<sortedEntry_t>::`vftable';
    idTimer::Stop(this: v84);
    clockTicks = (float)v84[0].clockTicks;
    LODWORD(v25) = Sys_ClockTicksPerSecond();
    v81 = v25;
    v84[0].clockTicks = v4;
    v84[0].state = TS_STARTED;
    v26 = (float)((float)clockTicks / (float)((float)v25 * (float)0.001));
    *((_QWORD *)&v27 + 1) = Sys_GetClockTicks();
    v84[0].start = *(_QWORD *)((char *)&v27 + 4);
    HIDWORD(v28) = &unk_82390000;
    DWORD2(v27) = "--------------------------------\n";
    idLib::Printf(fmt: v27, a2: v28, a3: v30, a4: v29, a5: v60, a6: v65, a7: v70, a8: v75);
    groupMask = this->groupMask;
    if ( (_DWORD)groupMask != 0 )
    {
      v35 = 0xC00000001LL;
      v36 = pLogGroupNames;
      do
      {
        LODWORD(v31) = v35 & LODWORD(this->groupMask);
        if ( (_DWORD)v31 != 0 )
        {
          HIDWORD(v37) = "[%s] ";
          LODWORD(v37) = *v36;
          idLib::Printf(fmt: v37, a2: v33, a3: v32, a4: v31, a5: v61, a6: v66, a7: v71, a8: v76);
        }
        --HIDWORD(v35);
        ++v36;
        v38 = HIDWORD(v35) != 0;
        v35 *= 2;
      }
      while ( v38 );
      HIDWORD(groupMask) = "\n";
    }
    else
    {
      HIDWORD(groupMask) = "NO ACTIVE GROUPS\n";
    }
    idLib::Printf(fmt: groupMask, a2: v33, a3: v32, a4: v31, a5: v61, a6: v66, a7: v71, a8: v76);
    HIDWORD(v40) = &plog_itemThreshold;
    valueFloat = plog_itemThreshold.valueFloat;
    if ( num > 0 )
    {
      p_parent = &list->parent;
      do
      {
        *(__int64 *)((char *)&v40 - 4) = *(_QWORD *)(p_parent + 1);
        v81 = *(__int64 *)((char *)&v40 - 4);
        v43 = (float)((float)*(__int64 *)((char *)&v40 - 4) * (float)v11);
        if ( valueFloat <= 0.0 || v43 >= valueFloat )
        {
          HIDWORD(v44) = LODWORD(v43);
          HIDWORD(v45) = "%s: %1.2f ms (%dx)\n";
          LODWORD(v45) = *(p_parent - 1);
          LODWORD(v44) = *p_parent;
          idLib::Printf(fmt: v45, a2: v44, a3: v39, a4: v40, a5: v62, a6: v67, a7: v72, a8: v77);
        }
        --num;
        p_parent += 4;
      }
      while ( num != 0 );
    }
    v47 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    HIDWORD(v48) = LODWORD(v84[0].clockTicks) - LODWORD(v84[0].start);
    LODWORD(v48) = v47 + LODWORD(v84[0].clockTicks) - LODWORD(v84[0].start);
    v84[0].clockTicks = v48;
    if ( (float)idTimer::base < 0.0 )
      idTimer::InitBaseClockTicks(this: v84);
    HIDWORD(v49) = HIDWORD(idTimer::base);
    if ( SHIDWORD(idTimer::base) > (int)idTimer::base )
    {
      LODWORD(v49) = HIDWORD(idTimer::base) - idTimer::base;
      v84[0].clockTicks = v49;
    }
    HIDWORD(v50) = this->logEntries.num;
    LODWORD(v50) = &unk_82390000;
    LODWORD(v46) = HIDWORD(v50);
    overHeadTicks = this->overHeadTicks;
    v84[0].state = TS_STOPPED;
    v81 = v46;
    v82 = *(__int64 *)((char *)&v46 - 4);
    idLib::Printf(
      fmt: COERCE__INT64((float)((float)((float)*(__int64 *)((char *)&v46 - 4) * (float)v46) * (float)v11)),
      a2: *(__int64 *)((char *)&v46 + 4),
      a3: *(__int64 *)((char *)&v46 - 4),
      a4: v50,
      a5: v62,
      a6: v67,
      a7: v72,
      a8: v77);
    LODWORD(v52) = &unk_82390000;
    idLib::Printf(
      fmt: __SPAIR64__("%1.2f ms to unique the events\n", LODWORD(v26)),
      a2: v52,
      a3: v54,
      a4: v53,
      a5: v63,
      a6: v68,
      a7: v73,
      a8: v78,
      v26);
    v55 = (float)v84[0].clockTicks;
    LODWORD(v56) = Sys_ClockTicksPerSecond();
    v82 = v56;
    HIDWORD(v57) = &unk_82390000;
    idLib::Printf(
      fmt: COERCE__INT64((float)((float)v55 / (float)((float)v56 * (float)0.001))),
      a2: v57,
      a3: v59,
      a4: v58,
      a5: v64,
      a6: v69,
      a7: v74,
      a8: v79);
    if ( (v83.listStatic == 0 || v83.listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
  else
  {
    idTimer::Stop(this: v84);
  }
}


// ========================================================================
// __unwind$114336
// EA  : 0x82F3EFDC
// RVA : 0x00F3EFDC
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void _unwind_114336()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 288 + 128));
}


// ========================================================================
// __unwind$114337
// EA  : 0x82F3F004
// RVA : 0x00F3F004
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void _unwind_114337()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$114338
// EA  : 0x82F3F02C
// RVA : 0x00F3F02C
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void _unwind_114338()
{
  int v0; // r12

  idSort_Unique::~idSort_Unique(this: (idSort_Unique *)(v0 - 288 + 80));
}


// ========================================================================
// ?BuildLogData@idPLog@@QAAMM_J@Z
// EA  : 0x82F3F060
// RVA : 0x00F3F060
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

float __fastcall idPLog::BuildLogData(idPLog *this, double thresholdMS, int a3, const __int64 adjustByTicks)
{
  __int64 v4; // r25
  int v7; // r29
  __int64 v8; // r3
  __int64 v9; // r3
  double v10; // fp30
  __int64 v11; // r6
  double v12; // fp1
  idPLog::treeEntry_t *list; // r10
  idPLog::logEntry_t *v14; // r8
  __int64 totalTicks; // r7
  int v16; // r11
  int *v17; // r17
  idVehicleState **v18; // r10
  idSpawnArea::GeneratedPosition **v19; // r20
  int size; // r11
  int num; // r29
  char v22; // r3
  idSpawnArea::GeneratedPosition **v23; // r10
  int i; // r11
  signed int v25; // r27
  idSort_Quick<int,idSort_EntryDepthAndTicks>_vtbl *v26; // r28
  int v27; // r11
  int v28; // r29
  char v29; // r3
  int v30; // r10
  int v31; // r11
  idSort_Quick<int,idSort_EntryDepthAndTicks>_vtbl *v32; // r9
  unsigned __int64 v33; // r10
  int *v34; // r21
  int v35; // r23
  int v36; // r28
  int v37; // r24
  int v38; // r22
  int v39; // r26
  __int64 v40; // r7
  idPLog::treeEntry_t *v41; // r4
  int v42; // r29
  int v43; // r11
  _DWORD *v44; // r5
  int v45; // r10
  _DWORD *v46; // r9
  _DWORD *v47; // r8
  int firstChild; // r10
  _DWORD *v49; // r11
  idPLog::treeEntry_t *v50; // r11
  int v51; // r11
  int v52; // r10
  idPLog::treeEntry_t *v53; // r9
  int v54; // r11
  idSpawnArea::GeneratedPosition *v55; // r8
  idPLog::treeEntry_t *v56; // r9
  int nextChild; // r11
  idPLog::treeEntry_t *v58; // r9
  int v59; // r3
  __int64 v60; // r10
  __int64 v61; // r11
  double clockTicks; // fp31
  __int64 v63; // r3
  double v64; // fp31
  idList<idBackgroundLoader::bgrEntry_t,101> v66; // [sp+50h] [-100h] BYREF
  idSort_Quick<int,idSort_EntryDepthAndTicks> v67[4]; // [sp+60h] [-F0h] BYREF
  idList<idSpawnArea::GeneratedPosition *,5> v68; // [sp+70h] [-E0h] BYREF
  idList<idVehicleState *,5> v69; // [sp+80h] [-D0h] BYREF
  idTimer v70; // [sp+90h] [-C0h] BYREF

  LODWORD(v4) = 0;
  v70.clockTicks = v4;
  v7 = HIDWORD(adjustByTicks);
  v70.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
  v70.state = TS_STARTED;
  LODWORD(v8) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  v70.start = v8;
  LODWORD(v9) = Sys_ClockTicksPerSecond();
  *(_QWORD *)&v66.list = v9;
  v10 = (float)((float)1000.0 / (float)v9);
  idPLog::SubtractOverhead(this);
  if ( this->logEntries.num > 2 )
  {
    LODWORD(v11) = LODWORD(this->logEntries.list[1].totalTicks) - v7;
    *(_QWORD *)&v66.list = v11;
    if ( (float)((float)v11 * (float)v10) < thresholdMS )
    {
      idTimer::Stop(this: &v70);
      v12 = -1.0;
      return *((float *)&v12 + 1);
    }
  }
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  idList<idPLog::treeEntry_t,44>::SetNum(this: &this->treeEntries, newNum: 1);
  list = this->treeEntries.list;
  memset(&v69, 0, 14);
  *(_WORD *)&v69.memTag = 1280;
  list->label = rootLabel;
  this->treeEntries.list->depth = 0;
  this->treeEntries.list->numHits = 0;
  this->treeEntries.list->totalTicks = v4;
  this->treeEntries.list->parent = 0;
  this->treeEntries.list->firstChild = 0;
  this->treeEntries.list->nextChild = 0;
  idList<idThread *,58>::Clear(this: &v69);
  idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&v69, newNum: this->logEntries.num - 1);
  v16 = 1;
  v17 = (int *)v69.list;
  if ( this->logEntries.num > 1 )
  {
    v18 = v69.list - 1;
    do
      *++v18 = (idVehicleState *)v16++;
    while ( v16 < this->logEntries.num );
  }
  v19 = nullptr;
  size = 0;
  *(_WORD *)&v68.memTag = 1280;
  memset(&v68, 0, 14);
  num = this->logEntries.num;
  if ( num > 0 )
  {
    v22 = idList<idNavSpline *,5>::Resize(this: &v68, newsize: this->logEntries.num);
    v19 = v68.list;
    if ( v22 == 0 )
      goto LABEL_12;
    size = v68.size;
  }
  v68.num = num;
  if ( num >= size )
    v68.num = size;
LABEL_12:
  HIDWORD(totalTicks) = 0;
  if ( this->logEntries.num > 0 )
  {
    LODWORD(totalTicks) = 0;
    v23 = v19;
    do
    {
      *v23 = (idSpawnArea::GeneratedPosition *)1;
      for ( i = *(int *)((char *)&this->logEntries.list->parent + totalTicks); i != 0; i = this->logEntries.list[i].parent )
      {
        v14 = (idPLog::logEntry_t *)(16 * i);
        *v23 = (idSpawnArea::GeneratedPosition *)((char *)*v23 + 1);
      }
      ++HIDWORD(totalTicks);
      LODWORD(totalTicks) = totalTicks + 16;
      ++v23;
    }
    while ( SHIDWORD(totalTicks) < this->logEntries.num );
  }
  v25 = v69.num;
  if ( plog_sortMode.valueInteger != 1 )
    goto LABEL_30;
  v26 = nullptr;
  v27 = 0;
  *(_WORD *)&v66.memTag = 1280;
  memset(&v66, 0, 14);
  v28 = this->logEntries.num;
  if ( v28 <= 0 )
    goto LABEL_21;
  v29 = idList<idBackgroundLoader::bgrEntry_t,101>::Resize(this: &v66, newsize: this->logEntries.num);
  v26 = (idSort_Quick<int,idSort_EntryDepthAndTicks>_vtbl *)v66.list;
  if ( v29 != 0 )
  {
    v27 = v66.size;
LABEL_21:
    v66.num = v28;
    if ( v28 >= v27 )
      v66.num = v27;
  }
  v30 = 0;
  if ( this->logEntries.num > 0 )
  {
    v31 = 0;
    v32 = v26 - 1;
    do
    {
      ++v30;
      v14 = &this->logEntries.list[v31++];
      totalTicks = v14->totalTicks;
      *++v32 = (idSort_Quick<int,idSort_EntryDepthAndTicks>_vtbl)totalTicks;
      HIDWORD(totalTicks) = this->logEntries.num;
    }
    while ( v30 < SHIDWORD(totalTicks) );
  }
  v67[1].__vftable = (idSort_Quick<int,idSort_EntryDepthAndTicks>_vtbl *)v19;
  v67[2].__vftable = v26;
  LODWORD(v33) = &idSort_EntryDepthAndTicks::`vftable';
  v67[0].__vftable = (idSort_Quick<int,idSort_EntryDepthAndTicks>_vtbl *)&idSort_EntryDepthAndTicks::`vftable';
  HIDWORD(v33) = idSort_Quick<int,idSort_EntryDepthAndTicks>::Sort;
  idSort_Quick<int,idSort_EntryDepthAndTicks>::Sort(
    this: v67,
    base: v17,
    num: v25,
    a4: SHIDWORD(totalTicks),
    a5: totalTicks,
    a6: (int)v14,
    a7: v33);
  v67[0].__vftable = (idSort_Quick<int,idSort_EntryDepthAndTicks>_vtbl *)&idSort<int>::`vftable';
  if ( (v66.listStatic == 0 || v66.listStatic == 2) && v26 != nullptr )
    idMem::Free(this: &mem, ptr: v26, align: ALIGN_16);
LABEL_30:
  if ( v25 > 0 )
  {
    v34 = v17;
    do
    {
      v35 = *v34;
      v36 = 0;
      v37 = *v34;
      v38 = (int)&v19[v37][-1].distanceFromEdge + 3;
      if ( this->treeEntries.num > 0 )
      {
        v39 = 0;
        do
        {
          HIDWORD(v40) = this->treeEntries.list;
          v41 = &this->treeEntries.list[v39];
          if ( v38 == v41->depth )
          {
            LODWORD(v40) = this->logEntries.list;
            v42 = v35;
            v43 = v36;
            v44 = (_DWORD *)(16 * v35 + v40);
            v45 = v44[1];
            if ( v45 != 0 )
            {
              while ( v43 != 0 )
              {
                v46 = (_DWORD *)(16 * v45 + v40);
                v47 = (_DWORD *)(40 * v43 + HIDWORD(v40));
                if ( *v46 != *v47 )
                  break;
                v45 = v46[1];
                v43 = v47[6];
                if ( v45 == 0 )
                  goto LABEL_41;
              }
            }
            else
            {
LABEL_41:
              if ( v43 == 0 )
              {
                firstChild = v41->firstChild;
                if ( firstChild != 0 )
                {
                  while ( 1 )
                  {
                    v49 = (_DWORD *)(40 * firstChild + HIDWORD(v40));
                    if ( *v44 == *v49 )
                      break;
                    firstChild = v49[8];
                    if ( firstChild == 0 )
                      goto LABEL_47;
                  }
                  ++v49[2];
                  v50 = &this->treeEntries.list[firstChild];
                  LODWORD(v40) = LODWORD(this->logEntries.list[v42].totalTicks) + LODWORD(v50->totalTicks);
                  v50->totalTicks = v40;
                }
                else
                {
LABEL_47:
                  idList<idPLog::treeEntry_t,44>::PreAllocateWithGranularity(
                    this: &this->treeEntries,
                    newSize: this->treeEntries.num + 1);
                  v51 = this->treeEntries.num;
                  v52 = this->treeEntries.size;
                  v53 = this->treeEntries.list;
                  if ( v51 >= v52 )
                  {
                    v54 = (int)&v53[v52 - 1];
                  }
                  else
                  {
                    this->treeEntries.num = v51 + 1;
                    v54 = (int)&v53[v51];
                  }
                  *(_DWORD *)v54 = this->logEntries.list[v42].label;
                  v55 = v19[v37];
                  *(_DWORD *)(v54 + 8) = 1;
                  *(_DWORD *)(v54 + 4) = v55;
                  *(_QWORD *)(v54 + 16) = this->logEntries.list[v42].totalTicks;
                  *(_DWORD *)(v54 + 28) = 0;
                  *(_DWORD *)(v54 + 32) = 0;
                  *(_DWORD *)(v54 + 24) = v36;
                  v56 = &this->treeEntries.list[v39];
                  nextChild = v56->firstChild;
                  if ( nextChild != 0 )
                  {
                    do
                    {
                      v58 = &this->treeEntries.list[nextChild];
                      nextChild = v58->nextChild;
                    }
                    while ( nextChild != 0 );
                    v58->nextChild = this->treeEntries.num - 1;
                  }
                  else
                  {
                    v56->firstChild = this->treeEntries.num - 1;
                  }
                }
              }
            }
          }
          ++v36;
          ++v39;
        }
        while ( v36 < this->treeEntries.num );
      }
      --v25;
      ++v34;
    }
    while ( v25 != 0 );
  }
  v59 = (unsigned __int64)Sys_GetClockTicks() >> 32;
  HIDWORD(v60) = 0x82000000;
  LODWORD(v60) = v59 + LODWORD(v70.clockTicks) - LODWORD(v70.start);
  v70.clockTicks = v60;
  if ( (float)idTimer::base < 0.0 )
    idTimer::InitBaseClockTicks(this: &v70);
  HIDWORD(v61) = HIDWORD(idTimer::base);
  if ( SHIDWORD(idTimer::base) > (int)idTimer::base )
  {
    LODWORD(v61) = HIDWORD(idTimer::base) - idTimer::base;
    v70.clockTicks = v61;
  }
  v70.state = TS_STOPPED;
  clockTicks = (float)v70.clockTicks;
  LODWORD(v63) = Sys_ClockTicksPerSecond();
  *(_QWORD *)&v66.list = v63;
  v64 = (float)((float)clockTicks / (float)((float)v63 * (float)0.001));
  if ( (v68.listStatic == 0 || v68.listStatic == 2) && v19 != nullptr )
    idMem::Free(this: &mem, ptr: v19, align: ALIGN_16);
  if ( (v69.listStatic == 0 || v69.listStatic == 2) && v17 != nullptr )
    idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
  v12 = v64;
  return *((float *)&v12 + 1);
}


// ========================================================================
// __unwind$114555
// EA  : 0x82F3F6D0
// RVA : 0x00F3F6D0
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void _unwind_114555()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 336 + 144));
}


// ========================================================================
// __unwind$114556
// EA  : 0x82F3F6F8
// RVA : 0x00F3F6F8
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void _unwind_114556()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 336 + 128));
}


// ========================================================================
// __unwind$114557
// EA  : 0x82F3F720
// RVA : 0x00F3F720
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void _unwind_114557()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 336 + 112));
}


// ========================================================================
// __unwind$114558
// EA  : 0x82F3F748
// RVA : 0x00F3F748
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void _unwind_114558()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 336 + 80));
}


// ========================================================================
// __unwind$114559
// EA  : 0x82F3F770
// RVA : 0x00F3F770
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void _unwind_114559()
{
  int v0; // r12

  idSort_EntryDepthAndTicks::~idSort_EntryDepthAndTicks(this: (idSort_AnimEventSort *)(v0 - 336 + 96));
}


// ========================================================================
// ?ShowCallGraph@idPLog@@QAAXM_J@Z
// EA  : 0x82F3F7A0
// RVA : 0x00F3F7A0
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPLog::ShowCallGraph(idPLog *this, double thresholdMS, int a3, const __int64 adjustByTicks)
{
  __int64 v4; // r21
  int v7; // r30
  __int64 v8; // r3
  __int64 v9; // r6
  double v10; // fp29
  int v11; // r4
  double v12; // fp26
  __int64 v13; // r3
  __int64 v14; // r10
  __int64 v15; // r4
  __int64 v16; // r8
  __int64 v17; // r6
  __int64 v18; // r10
  __int64 v19; // r6
  __int64 v20; // r4
  unsigned __int64 groupMask; // r8
  __int64 v22; // r29
  const char **v23; // r30
  __int64 v24; // r4
  bool v25; // zf
  idPLog::treeEntry_t *list; // r10
  int v27; // r26
  int firstChild; // r30
  double valueFloat; // fp30
  double v30; // fp2
  int v31; // r29
  idPLog::treeEntry_t *v32; // r7
  __int64 totalTicks; // fp0
  int nextChild; // r11
  double v35; // fp1
  double v36; // fp13
  idPLog::treeEntry_t *v37; // r11
  double v38; // fp12
  __int64 v39; // r10 OVERLAPPED
  timingColor_t *v40; // r11
  char color; // r11
  __int64 v42; // r6
  __int64 v43; // r8
  __int64 v44; // r4
  idPLog::treeEntry_t *v45; // r11
  __int64 v46; // r10
  __int128 v47; // r8
  __int64 v48; // r6
  __int64 v49; // r10
  __int64 v50; // r8
  double clockTicks; // fp31
  __int64 v52; // r3
  __int64 v53; // r6
  __int64 v54; // r10
  __int64 v55; // r8
  int v56; // [sp+8h] [-208h]
  int v57; // [sp+8h] [-208h]
  int v58; // [sp+8h] [-208h]
  int v59; // [sp+8h] [-208h]
  int v60; // [sp+8h] [-208h]
  int v61; // [sp+Ch] [-204h]
  int v62; // [sp+Ch] [-204h]
  int v63; // [sp+Ch] [-204h]
  int v64; // [sp+Ch] [-204h]
  int v65; // [sp+Ch] [-204h]
  int v66; // [sp+10h] [-200h]
  int v67; // [sp+10h] [-200h]
  int v68; // [sp+10h] [-200h]
  int v69; // [sp+10h] [-200h]
  int v70; // [sp+10h] [-200h]
  int v71; // [sp+14h] [-1FCh]
  int v72; // [sp+14h] [-1FCh]
  int v73; // [sp+14h] [-1FCh]
  int v74; // [sp+14h] [-1FCh]
  int v75; // [sp+14h] [-1FCh]
  idTimer v76; // [sp+60h] [-1B0h] BYREF
  _DWORD v77[76]; // [sp+80h] [-190h] BYREF

  v7 = HIDWORD(adjustByTicks);
  LODWORD(v8) = Sys_ClockTicksPerSecond();
  HIDWORD(v9) = v7;
  v10 = (float)((float)1000.0 / (float)v8);
  v12 = idPLog::BuildLogData(this, thresholdMS, a3: v11, adjustByTicks: v9);
  if ( v12 >= 0.0 )
  {
    LODWORD(v4) = 0;
    v76.clockTicks = v4;
    v76.__vftable = (idTimer_vtbl *)&idTimer::`vftable';
    v76.state = TS_STARTED;
    LODWORD(v13) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v76.start = v13;
    memset(Dst: v77, Val: 32, Size: 0x100u);
    HIDWORD(v14) = &unk_82390000;
    HIDWORD(v15) = "--------------------------------\n";
    idLib::Printf(fmt: v15, a2: v17, a3: v16, a4: v14, a5: v56, a6: v61, a7: v66, a8: v71);
    groupMask = this->groupMask;
    if ( (_DWORD)groupMask != 0 )
    {
      v22 = 0xC00000001LL;
      v23 = pLogGroupNames;
      do
      {
        LODWORD(v18) = v22 & LODWORD(this->groupMask);
        if ( (_DWORD)v18 != 0 )
        {
          HIDWORD(v24) = "[%s] ";
          LODWORD(v24) = *v23;
          idLib::Printf(fmt: v24, a2: v19, a3: groupMask, a4: v18, a5: v57, a6: v62, a7: v67, a8: v72);
        }
        --HIDWORD(v22);
        ++v23;
        v25 = HIDWORD(v22) != 0;
        v22 *= 2;
      }
      while ( v25 );
      HIDWORD(v20) = "\n";
    }
    else
    {
      HIDWORD(v20) = "NO ACTIVE GROUPS\n";
    }
    idLib::Printf(fmt: v20, a2: v19, a3: groupMask, a4: v18, a5: v57, a6: v62, a7: v67, a8: v72);
    list = this->treeEntries.list;
    v27 = 0;
    firstChild = this->treeEntries.list->firstChild;
    valueFloat = plog_itemThreshold.valueFloat;
    while ( firstChild != 0 )
    {
      v30 = 0.0;
      v31 = firstChild;
      v32 = &list[firstChild];
      totalTicks = v32->totalTicks;
      HIBYTE(v77[v27]) = 0;
      nextChild = v32->firstChild;
      v35 = (float)((float)totalTicks * (float)v10);
      if ( nextChild != 0 && v35 > 0.0099999998 )
      {
        v36 = 0.0;
        do
        {
          v37 = &list[nextChild];
          v38 = (double)v37->totalTicks;
          if ( valueFloat == 0.0 || (float)((float)v38 * (float)v10) >= valueFloat )
            v36 = (float)((float)((float)v38 * (float)v10) + (float)v36);
          nextChild = v37->nextChild;
        }
        while ( nextChild != 0 );
        v30 = (float)((float)((float)v36 / (float)((float)totalTicks * (float)v10)) * (float)100.0);
      }
      if ( valueFloat == 0.0 || v35 >= valueFloat )
      {
        LODWORD(v39) = 3;
        v40 = &timingColors[3];
        while ( (float)((float)v32->totalTicks * (float)v10) < (double)v40->minMS )
        {
          --v40;
          LODWORD(v39) = v39 - 1;
          if ( (int)v40 < (int)timingColors )
          {
            color = 55;
            goto LABEL_24;
          }
        }
        color = timingColors[v39].color;
LABEL_24:
        HIDWORD(v42) = v32->label;
        HIDWORD(v43) = LODWORD(v35);
        HIDWORD(v44) = "%s%s: ^%c %1.2f ms (%dx) (%2.1f%%)\n";
        *(__int64 *)((char *)&v39 + 4) = *(_QWORD *)&v30;
        LODWORD(v42) = color;
        LODWORD(v44) = v77;
        idLib::Printf(fmt: v44, a2: v42, a3: v43, a4: v39, a5: v58, a6: v63, a7: v68, a8: v73);
      }
      list = this->treeEntries.list;
      HIBYTE(v77[v27]) = 32;
      if ( list[v31].firstChild != 0 )
      {
        firstChild = list[v31].firstChild;
        ++v27;
      }
      else
      {
        while ( 1 )
        {
          v45 = &list[firstChild];
          if ( v45->nextChild != 0 )
            break;
          firstChild = v45->parent;
          --v27;
          if ( firstChild == 0 )
            goto LABEL_33;
        }
        firstChild = v45->nextChild;
      }
    }
LABEL_33:
    idTimer::Stop(this: &v76);
    HIDWORD(v46) = this->overHeadTicks;
    LODWORD(v46) = this->logEntries.num;
    *((_QWORD *)&v47 + 1) = v46;
    idLib::Printf(
      fmt: COERCE__INT64((float)((float)((float)*(__int64 *)((char *)&v47 + 4) * (float)v46) * (float)v10)),
      a2: *(__int64 *)&v47,
      a3: v46,
      a4: v46,
      a5: v58,
      a6: v63,
      a7: v68,
      a8: v73);
    LODWORD(v48) = &unk_82390000;
    idLib::Printf(
      fmt: __SPAIR64__("%1.2f ms to build the tree\n", LODWORD(v12)),
      a2: v48,
      a3: v50,
      a4: v49,
      a5: v59,
      a6: v64,
      a7: v69,
      a8: v74,
      v12);
    clockTicks = (float)v76.clockTicks;
    LODWORD(v52) = Sys_ClockTicksPerSecond();
    HIDWORD(v53) = &off_82040000;
    idLib::Printf(
      fmt: COERCE__INT64((float)((float)clockTicks / (float)((float)v52 * (float)0.001))),
      a2: v53,
      a3: v55,
      a4: v54,
      a5: v60,
      a6: v65,
      a7: v70,
      a8: v75);
  }
}


// ========================================================================
// __unwind$115084
// EA  : 0x82F3FB30
// RVA : 0x00F3FB30
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void _unwind_115084()
{
  int v0; // r12

  idTimer::~idTimer(this: (idTimer *)(v0 - 528 + 96));
}


// ========================================================================
// `dynamic initializer for 'plog_itemThreshold''
// EA  : 0x83395F70
// RVA : 0x01395F70
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__plog_itemThreshold__()
{
  idCVar::idCVar(
    this: &plog_itemThreshold,
    name: "plog_itemThreshold",
    value: "0",
    flags: 4,
    description: "only shows individual items that exceed this threshold",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__plog_itemThreshold__);
}


// ========================================================================
// `dynamic initializer for 'plog_sortMode''
// EA  : 0x83395FC8
// RVA : 0x01395FC8
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__plog_sortMode__()
{
  idCVar::idCVar(
    this: &plog_sortMode,
    name: "plog_sortMode",
    value: "0",
    flags: 2,
    description: "sort mode (0 = normal, 1 = sort by time)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__plog_sortMode__);
}


// ========================================================================
// `dynamic initializer for 'pLog''
// EA  : 0x83396028
// RVA : 0x01396028
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pLog__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pLog__);
}


// ========================================================================
// __unwind$115206
// EA  : 0x8339605C
// RVA : 0x0139605C
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void _unwind_115206()
{
  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)&pLog);
}


// ========================================================================
// `dynamic initializer for 'timingColors''
// EA  : 0x83396088
// RVA : 0x01396088
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

int _dynamic_initializer_for__timingColors__()
{
  timingColors[0].idcolor = idColor::colorLtGrey;
  timingColors[1].idcolor = idColor::colorGreen;
  timingColors[2].idcolor = idColor::colorYellow;
  timingColors[3].idcolor = idColor::colorRed;
  return LODWORD(idColor::colorGreen.r);
}


// ========================================================================
// `dynamic initializer for 'overheadLog''
// EA  : 0x83396158
// RVA : 0x01396158
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__overheadLog__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__overheadLog__);
}


// ========================================================================
// __unwind$115331_0
// EA  : 0x8339618C
// RVA : 0x0139618C
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

void _unwind_115331_0()
{
  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)&overheadLog);
}


// ========================================================================
// `dynamic initializer for 'plog_enable''
// EA  : 0x833961B8
// RVA : 0x013961B8
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__plog_enable__()
{
  return idCommandLink::idCommandLink(
           this: &plog_enable,
           cmdName: "plog_enable",
           function: (void (__fastcall *)(const idCmdArgs *))plog_enable_f,
           description: &byte_8200D768,
           argCompletion: ArgCompletion_PLogGroups);
}


// ========================================================================
// `dynamic initializer for 'plog_disable''
// EA  : 0x833961E8
// RVA : 0x013961E8
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__plog_disable__()
{
  return idCommandLink::idCommandLink(
           this: &plog_disable,
           cmdName: "plog_disable",
           function: (void (__fastcall *)(const idCmdArgs *))plog_disable_f,
           description: &byte_8200D768,
           argCompletion: ArgCompletion_PLogGroups);
}


// ========================================================================
// `dynamic initializer for 'plog_toggle''
// EA  : 0x83396218
// RVA : 0x01396218
// PDB : w:\tech5\shared\idlib\metrics\plog.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__plog_toggle__()
{
  return idCommandLink::idCommandLink(
           this: &plog_toggle,
           cmdName: "plog_toggle",
           function: (void (__fastcall *)(const idCmdArgs *))plog_toggle_f,
           description: &byte_8200D768,
           argCompletion: ArgCompletion_PLogGroups);
}

