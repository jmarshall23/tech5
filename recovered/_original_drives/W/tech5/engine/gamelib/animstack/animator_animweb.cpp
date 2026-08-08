
// ========================================================================
// ?InternalGetMergeBranch@idAnimator_AnimWeb@@MBAPBVidMD6Branch@@XZ
// EA  : 0x826D0910
// RVA : 0x006D0910
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

const idMD6Branch *__fastcall idAnimator_AnimWeb::InternalGetMergeBranch(idAnimator_AnimWeb *this)
{
  return this->mergeBranch;
}


// ========================================================================
// ?DebugPrint@idAnimator_AnimWeb@@IBAXPBDZZ
// EA  : 0x826D0918
// RVA : 0x006D0918
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idAnimator_AnimWeb::DebugPrint(
        idAnimator_AnimWeb *this,
        const char *fmt,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        ...)
{
  __int64 v11; // [sp+80h] [+20h] BYREF
  va_list va; // [sp+80h] [+20h]
  __int64 v13; // [sp+88h] [+28h]
  __int64 v14; // [sp+90h] [+30h]
  __int64 v15; // [sp+98h] [+38h]
  __int64 v16; // [sp+A0h] [+40h]
  __int64 v17; // [sp+A8h] [+48h]
  va_list va1; // [sp+B0h] [+50h] BYREF

  va_start(va1, a11);
  va_start(va, a11);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v11 = *(__int64 *)((char *)&a3 + 4);
  v13 = a3;
  v14 = *(__int64 *)((char *)&a4 + 4);
  v15 = a4;
  v16 = *(__int64 *)((char *)&a5 + 4);
  v17 = a5;
  if ( this->debug )
    idLib::VPrintf(fmt, args: va);
}


// ========================================================================
// ?ClearEvent@idAnimator_AnimWeb@@QAAXW4animWebEvent_t@@@Z
// EA  : 0x826D0978
// RVA : 0x006D0978
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::ClearEvent(idAnimator_AnimWeb *this, animWebEvent_t eventType)
{
  this->eventHandler.ClearEvent(this: &this->eventHandler, a2: eventType);
}


// ========================================================================
// ?ClearEvents@idAnimator_AnimWeb@@QAAXXZ
// EA  : 0x826D0990
// RVA : 0x006D0990
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::ClearEvents(idAnimator_AnimWeb *this)
{
  this->eventHandler.ClearEvents(this: &this->eventHandler);
}


// ========================================================================
// ?IsEventPending@idAnimator_AnimWeb@@QBA_NW4animWebEvent_t@@@Z
// EA  : 0x826D09A8
// RVA : 0x006D09A8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

BOOL __fastcall idAnimator_AnimWeb::IsEventPending(idAnimator_AnimWeb *this, animWebEvent_t type)
{
  return this->eventHandler.IsEventPending(this: &this->eventHandler, a2: type);
}


// ========================================================================
// ?IsAnyEventPending@idAnimator_AnimWeb@@QBA_NXZ
// EA  : 0x826D09C0
// RVA : 0x006D09C0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

BOOL __fastcall idAnimator_AnimWeb::IsAnyEventPending(idAnimator_AnimWeb *this)
{
  return this->eventHandler.IsAnyEventPending(this: &this->eventHandler);
}


// ========================================================================
// ?GetDestWebPath@idAnimator_AnimWeb@@QBA?AVidAnimWebPath@@_N@Z
// EA  : 0x826D0D50
// RVA : 0x006D0D50
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

idAnimator_AnimWeb *__fastcall idAnimator_AnimWeb::GetDestWebPath(
        idAnimator_AnimWeb *this,
        idAnimWebPath *result,
        bool includeWebName)
{
  const char *v5; // r4

  if ( includeWebName )
    v5 = *(const char **)(result[1].allocedAndFlag + 8);
  else
    v5 = &byte_8200D768;
  idAnimWebPath::idAnimWebPath(
    (idAnimWebPath *)this,
    webName: v5,
    subWebName: *(const char **)&result[10].baseBuffer[8],
    stateName: *(const char **)&result[10].baseBuffer[4]);
  return this;
}


// ========================================================================
// ?SetEvent@idAnimator_AnimWeb@@QAAXW4animWebEvent_t@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@ABVidEventDef@@W4priority_t@idAnimWebEvent@@@Z
// EA  : 0x826D0DB0
// RVA : 0x006D0DB0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::SetEvent(
        idAnimator_AnimWeb *this,
        animWebEvent_t eventType,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex,
        const idEventDef *eventDef,
        idAnimWebEvent::priority_t priority)
{
  this->eventHandler.SetEvent(
    this: &this->eventHandler,
    a2: this,
    a3: subWebIndex,
    a4: stateIndex,
    a5: eventType,
    a6: eventDef->eventnum,
    a7: priority);
}


// ========================================================================
// ?TriggerEvent@idAnimator_AnimWeb@@QAAXPBVidDeclAnimWebNode@@W4animWebEvent_t@@ABVidAnimWebEvent@@H@Z
// EA  : 0x826D0DD8
// RVA : 0x006D0DD8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::TriggerEvent(
        idAnimator_AnimWeb *this,
        const idDeclAnimWebNode *node,
        animWebEvent_t eventType,
        const idAnimWebEvent *event,
        int eventParm)
{
  idAnimator_AnimWeb_vtbl *v5; // r27
  int eventNum; // r26
  const idHandle<short,enum invalidAnimWebHandle_t,-1> *v11; // r3

  v5 = this->__vftable;
  eventNum = event->eventNum;
  v11 = this->GetHandle(this);
  v5->InternalTriggerEvent(this, a2: node, a3: eventType, a4: v11, a5: eventNum, a6: eventParm);
}


// ========================================================================
// ?GetBlendTree@idModelAnimState@idAnimator_AnimWeb@@QBAPBVidAnimWebBlendTree@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x826D0E38
// RVA : 0x006D0E38
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

const idAnimWebBlendTree *__fastcall idAnimator_AnimWeb::idModelAnimState::GetBlendTree(
        idAnimator_AnimWeb::idModelAnimState *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nodeIndex)
{
  int num; // r7
  int v3; // r10
  idAnimWebBlendTree **list; // r9
  int i; // r11

  num = this->blendTreeCache.num;
  v3 = 0;
  if ( num <= 0 )
    return nullptr;
  list = this->blendTreeCache.list;
  for ( i = 0; list[i]->nodeIndex.value != (__int16)nodeIndex; ++i )
  {
    if ( ++v3 >= num )
      return nullptr;
  }
  return list[v3];
}


// ========================================================================
// ?GetBlendTree@idModelAnimState@idAnimator_AnimWeb@@QAAPAVidAnimWebBlendTree@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x826D0E90
// RVA : 0x006D0E90
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

// attributes: thunk
idAnimWebBlendTree *__fastcall idAnimator_AnimWeb::idModelAnimState::GetBlendTree(
        idAnimator_AnimWeb::idModelAnimState *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nodeIndex)
{
  return (idAnimWebBlendTree *)?GetBlendTree@idModelAnimState@idAnimator_AnimWeb@@QBAPBVidAnimWebBlendTree@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@@Z(
                                 this,
                                 nodeIndex);
}


// ========================================================================
// ?FreeBlendTree@idModelAnimState@idAnimator_AnimWeb@@QBAXABV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x826D0E98
// RVA : 0x006D0E98
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::idModelAnimState::FreeBlendTree(
        idAnimator_AnimWeb::idModelAnimState *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *forNodeIndex)
{
  int num; // r8
  int v3; // r31
  idStaticList<idAnimWebBlendTree *,8> *p_blendTreeCache; // r29
  idAnimWebBlendTree **list; // r10
  int i; // r11
  idAnimWebBlendTree *v7; // r30
  int v8; // r11
  int v9; // r11

  num = this->blendTreeCache.num;
  v3 = 0;
  if ( num > 0 )
  {
    p_blendTreeCache = &this->blendTreeCache;
    list = this->blendTreeCache.list;
    for ( i = 0; list[i]->nodeIndex.value != forNodeIndex->value; ++i )
    {
      if ( ++v3 >= num )
        return;
    }
    if ( v3 >= 0 )
    {
      v7 = list[v3];
      if ( v7 != nullptr )
      {
        idAnimWebBlendTree::~idAnimWebBlendTree(this: list[v3]);
        idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
      }
      v8 = p_blendTreeCache->num;
      if ( v3 < v8 )
      {
        v9 = v8 - 1;
        p_blendTreeCache->num = v9;
        if ( v3 != v9 )
          p_blendTreeCache->list[v3] = p_blendTreeCache->list[v9];
      }
    }
  }
}


// ========================================================================
// ?DecomposeAnimRef@idAnimator_AnimWeb@@QBA_NPBDAAVidStr@@1@Z
// EA  : 0x826D0F68
// RVA : 0x006D0F68
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::DecomposeAnimRef(
        idAnimator_AnimWeb *this,
        const char *animRef,
        idStr *subWebName,
        idStr *stateName)
{
  int v7; // r30
  idStr v9[2]; // [sp+50h] [-50h] BYREF

  v9[0].len = 0;
  v9[0].allocedAndFlag = 20;
  v9[0].data = v9[0].baseBuffer;
  v9[0].baseBuffer[0] = 0;
  idAnimWebPath::SplitPath(path: animRef, webName: v9, subWebName, stateName);
  v7 = ((int (__fastcall *)(idAnimator_AnimWeb *, idStr *, idStr *))this->InternalRemapNames)(
         a1: this,
         a2: subWebName,
         a3: stateName);
  idStr::FreeData(this: v9);
  return v7;
}


// ========================================================================
// __unwind$252449
// EA  : 0x826D0FE0
// RVA : 0x006D0FE0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_252449()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?InternalIsContributing@idAnimator_AnimWeb@@MBA_NXZ
// EA  : 0x826D1428
// RVA : 0x006D1428
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::InternalIsContributing(idAnimator_AnimWeb *this)
{
  idMD6Node *tree; // r3
  int result; // r3
  bool IsValid; // zf

  tree = this->modelAnimStates.list->tree;
  if ( tree == nullptr )
    return 0;
  IsValid = idMD6Node::IsValid(this: tree);
  result = 1;
  if ( !IsValid )
    return 0;
  return result;
}


// ========================================================================
// ?InternalUpdateBlendEvents@idAnimator_AnimWeb@@EAAXPBVidAnimStack@@HH@Z
// EA  : 0x826D1470
// RVA : 0x006D1470
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::InternalUpdateBlendEvents(
        idAnimator_AnimWeb *this,
        const idAnimStack *stack,
        int curTime,
        int ticksPerSec)
{
  const idDeclAnimWeb *decl; // r3
  int value; // r11
  idDeclAnimWebNode *v9; // r26
  int v10; // r23
  int v11; // r25
  const idDeclAnimWeb *v12; // r3
  int v13; // r28
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *v14; // r27
  unsigned __int16 *v15; // r30

  decl = this->decl;
  if ( decl != nullptr && this->blendEventMask != 0 )
  {
    value = this->curNodeIndex.value;
    if ( value != -1 )
    {
      v9 = decl->nodes.list[value];
      if ( v9 != nullptr )
      {
        idDeclAnimWeb::GetSubWebName(
          this: decl,
          index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v9->subWebIndex.value);
        idDeclAnimWeb::GetStateName(
          this: this->decl,
          index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v9->states.stateIndex[0].value);
        v10 = 0;
        if ( v9->edges.num > 0 )
        {
          v11 = 0;
          do
          {
            v12 = this->decl;
            v13 = v9->edges.list[v11].value;
            v14 = (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)v12->edgeCache.list[v13].destNodeIndex.value;
            if ( (__int16)v14 != -1 )
            {
              v15 = (unsigned __int16 *)v12->nodes.list[(__int16)v14];
              if ( v15 != nullptr && (v15[8] & this->blendEventMask) != 0 )
              {
                idDeclAnimWeb::GetSubWebName(
                  this: v12,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v15[1]);
                idDeclAnimWeb::GetStateName(
                  this: this->decl,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v15[2]);
                if ( &this->decl->edges.list[v13] != nullptr
                  && ((unsigned __int8 (__fastcall *)(idAnimator_AnimWeb *, _DWORD, idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *, int, int, blendParms_t *, _DWORD, _DWORD))this->InternalShouldStartNextNode)(
                       a1: this,
                       a2: (unsigned __int16)this->curNodeIndex.value,
                       a3: v14,
                       a4: curTime,
                       a5: ticksPerSec,
                       a6: &this->decl->edges.list[v13].blendParms,
                       a7: 0,
                       a8: 0) != 0 )
                {
                  this->InternalTriggerBlendEvent(
                    this,
                    a2: v15[8],
                    a3: nullptr,
                    a4: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)this->curNodeIndex.value,
                    a5: v14,
                    a6: curTime);
                }
              }
            }
            ++v10;
            ++v11;
          }
          while ( v10 < v9->edges.num );
        }
      }
    }
  }
}


// ========================================================================
// ?CacheCurNode@idAnimator_AnimWeb@@AAAXXZ
// EA  : 0x826D15F0
// RVA : 0x006D15F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::CacheCurNode(idAnimator_AnimWeb *this)
{
  __int16 value; // r11
  const idDeclAnimWeb *decl; // r3
  idDeclAnimWebNode *v4; // r30
  const char *StateName; // r3
  const char *SubWebName; // r4

  value = this->curNodeIndex.value;
  if ( value >= 0 && (decl = this->decl) != nullptr && value != -1 && (v4 = decl->nodes.list[value]) != nullptr )
  {
    StateName = idDeclAnimWeb::GetStateName(
                  this: decl,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v4->states.stateIndex[0].value);
    idAtomicString::Set(this: &this->curNodeStateName, str_: StateName);
    SubWebName = idDeclAnimWeb::GetSubWebName(
                   this: this->decl,
                   index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v4->subWebIndex.value);
  }
  else
  {
    idAtomicString::Set(this: &this->curNodeStateName, str_: &byte_8200D768);
    SubWebName = &byte_8200D768;
  }
  idAtomicString::Set(this: &this->curNodeSubWebName, str_: SubWebName);
}


// ========================================================================
// ?CacheDestNode@idAnimator_AnimWeb@@AAAXXZ
// EA  : 0x826D16A8
// RVA : 0x006D16A8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::CacheDestNode(idAnimator_AnimWeb *this)
{
  int num; // r11
  int v3; // r11
  __int16 value; // r10
  __int16 v5; // r27
  const idDeclAnimWeb *decl; // r3
  idDeclAnimWebNode *v7; // r27
  const char *StateName; // r3
  const char *SubWebName; // r3

  num = this->curPath.num;
  if ( num <= 0 )
  {
    value = -1;
  }
  else
  {
    v3 = (__int16)(num - 1);
    if ( v3 < 0 || v3 >= this->curPath.num )
      value = -1;
    else
      value = this->curPath.path[v3].value;
  }
  v5 = value;
  idAtomicString::Set(this: &this->destNodeStateName, str_: &byte_8200D768);
  idAtomicString::Set(this: &this->destNodeSubWebName, str_: &byte_8200D768);
  decl = this->decl;
  if ( decl != nullptr && v5 >= 0 )
  {
    if ( v5 == -1 || (v7 = decl->nodes.list[v5]) == nullptr )
    {
      idAtomicString::Set(this: &this->destNodeStateName, str_: &byte_8200D768);
      idAtomicString::Set(this: &this->destNodeSubWebName, str_: &byte_8200D768);
    }
    else
    {
      StateName = idDeclAnimWeb::GetStateName(
                    this: decl,
                    index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v7->states.stateIndex[0].value);
      idAtomicString::Set(this: &this->destNodeStateName, str_: StateName);
      SubWebName = idDeclAnimWeb::GetSubWebName(
                     this: this->decl,
                     index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v7->subWebIndex.value);
      idAtomicString::Set(this: &this->destNodeSubWebName, str_: SubWebName);
    }
  }
}


// ========================================================================
// ?GetCurEdgeInfo@idAnimator_AnimWeb@@QBA_NAAV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@AAV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@AAVblendParms_t@@@Z
// EA  : 0x826D17B8
// RVA : 0x006D17B8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::GetCurEdgeInfo(
        idAnimator_AnimWeb *this,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *swi,
        idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *ni,
        blendParms_t *bp)
{
  __int16 value; // r10
  int curEdgeIndex; // r9
  const idDeclAnimWeb *decl; // r11
  idAnimator_AnimWeb::forcedEdge_t *p_forcedEdge; // r11
  char *p_flags; // r10
  int v9; // ctr
  idDeclAnimWebNode *v11; // r10
  int v12; // r8
  char *v13; // r9
  int v14; // ctr
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *p_destSubWebIndex; // r11

  value = this->curEdgeNodeIndex.value;
  if ( value >= 0 )
  {
    curEdgeIndex = this->curEdgeIndex;
    if ( curEdgeIndex >= 0 )
    {
      decl = this->decl;
      if ( decl != nullptr )
      {
        if ( curEdgeIndex == 0x7FFF )
        {
          p_forcedEdge = &this->forcedEdge;
          p_flags = &bp[-1].parms.flags;
          swi->value = (__int16)this->forcedEdge.destSubWebIndex;
          v9 = 5;
          ni->value = (__int16)this->forcedEdge.destNodeIndex;
          do
          {
            p_forcedEdge = (idAnimator_AnimWeb::forcedEdge_t *)((char *)p_forcedEdge + 4);
            p_flags += 4;
            *(_DWORD *)p_flags = *(_DWORD *)&p_forcedEdge->destNodeIndex.value;
            --v9;
          }
          while ( v9 != 0 );
          return 1;
        }
        if ( value != -1 )
        {
          v11 = decl->nodes.list[value];
          if ( v11 != nullptr && v11->edges.num > 0 )
          {
            v12 = v11->edges.list[curEdgeIndex].value;
            if ( v12 >= 0 )
            {
              v13 = &bp[-1].parms.flags;
              v14 = 5;
              swi->value = (__int16)decl->edges.list[v12].destSubWebIndex;
              p_destSubWebIndex = &this->decl->edges.list[v12].destSubWebIndex;
              do
              {
                p_destSubWebIndex += 2;
                v13 += 4;
                *(_DWORD *)v13 = *(_DWORD *)&p_destSubWebIndex->value;
                --v14;
              }
              while ( v14 != 0 );
              ni->value = (__int16)this->decl->edgeCache.list[v12].destNodeIndex;
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ?GetCurSubWebName@idAnimator_AnimWeb@@QBAPBDXZ
// EA  : 0x826D18C8
// RVA : 0x006D18C8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

char *__fastcall idAnimator_AnimWeb::GetCurSubWebName(idAnimator_AnimWeb *this)
{
  const idDeclAnimWeb *decl; // r10
  int value; // r11
  idDeclAnimWebNode *v3; // r11

  decl = this->decl;
  if ( decl != nullptr && (value = this->curNodeIndex.value) != -1 && (v3 = decl->nodes.list[value]) != nullptr )
    return (char *)idDeclAnimWeb::GetSubWebName(
                     this: this->decl,
                     index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v3->subWebIndex.value);
  else
    return &byte_8200D768;
}


// ========================================================================
// ?GetCurSubWebIndex@idAnimator_AnimWeb@@QBA?AV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@XZ
// EA  : 0x826D1938
// RVA : 0x006D1938
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

idAnimator_AnimWeb *__fastcall idAnimator_AnimWeb::GetCurSubWebIndex(
        idAnimator_AnimWeb *this,
        idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *result)
{
  int v2; // r10
  __int16 value; // r11
  int v4; // r11

  v2 = *(_DWORD *)&result[20].value;
  if ( v2 != 0 && (value = result[40].value) >= 0 && (v4 = *(_DWORD *)(4 * value + *(_DWORD *)(v2 + 56))) != 0 )
    HIWORD(this->__vftable) = *(_WORD *)(v4 + 2);
  else
    HIWORD(this->__vftable) = -1;
  return this;
}


// ========================================================================
// ?GetCurStateName@idAnimator_AnimWeb@@QBAPBDXZ
// EA  : 0x826D1990
// RVA : 0x006D1990
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

const char *__fastcall idAnimator_AnimWeb::GetCurStateName(idAnimator_AnimWeb *this)
{
  const idDeclAnimWeb *decl; // r10
  int value; // r11
  idDeclAnimWebNode *v3; // r11

  decl = this->decl;
  if ( decl != nullptr && (value = this->curNodeIndex.value) != -1 && (v3 = decl->nodes.list[value]) != nullptr )
    return idDeclAnimWeb::GetStateName(
             this: this->decl,
             index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v3->states.stateIndex[0].value);
  else
    return "<NULL>";
}


// ========================================================================
// ?GetCurWebPath@idAnimator_AnimWeb@@QBA?AVidAnimWebPath@@_N@Z
// EA  : 0x826D1A00
// RVA : 0x006D1A00
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

idAnimator_AnimWeb *__fastcall idAnimator_AnimWeb::GetCurWebPath(
        idAnimator_AnimWeb *this,
        idAnimator_AnimWeb *result,
        bool includeWebName)
{
  const char *str; // r30
  const char *CurStateName; // r28
  char *CurSubWebName; // r3

  if ( includeWebName )
    str = result->decl->name.str;
  else
    str = &byte_8200D768;
  CurStateName = idAnimator_AnimWeb::GetCurStateName(this: result);
  CurSubWebName = idAnimator_AnimWeb::GetCurSubWebName(this: result);
  idAnimWebPath::idAnimWebPath((idAnimWebPath *)this, webName: str, subWebName: CurSubWebName, stateName: CurStateName);
  return this;
}


// ========================================================================
// ?GetCurStateIndex@idAnimator_AnimWeb@@QBA?AV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@XZ
// EA  : 0x826D1A68
// RVA : 0x006D1A68
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

idAnimator_AnimWeb *__fastcall idAnimator_AnimWeb::GetCurStateIndex(
        idAnimator_AnimWeb *this,
        idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *result)
{
  int v2; // r10
  __int16 value; // r11
  int v4; // r11

  v2 = *(_DWORD *)&result[20].value;
  if ( v2 != 0 && (value = result[40].value) >= 0 && (v4 = *(_DWORD *)(4 * value + *(_DWORD *)(v2 + 56))) != 0 )
    HIWORD(this->__vftable) = *(_WORD *)(v4 + 4);
  else
    HIWORD(this->__vftable) = -1;
  return this;
}


// ========================================================================
// ?GetNodeTotalMovement@idAnimator_AnimWeb@@QBA_NV?$idIndex@FW4invalidModelIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@AAVidVec3@@AAVidQuat@@@Z
// EA  : 0x826D1AC0
// RVA : 0x006D1AC0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::GetNodeTotalMovement(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *modelIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *swi,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *si,
        idVec3 *translation,
        idQuat *rotation)
{
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *decl; // r4
  unsigned __int16 v11; // r29
  const idAnimWebBlendTree *BlendTree; // r3
  int num; // r6
  int v14; // r9
  int v15; // r11
  const idMD6LeafPlay *v16; // r10
  const idMD6Anim *anim; // r8
  idDeclAnimWebNode *v18; // r3
  const idDeclMD6 *v19; // r26
  const idDeclAnimWebNode::idModelInfo *ModelInfo; // r3
  idList<idMD6AnimProps,32> *p_animProps; // r30
  int v22; // r29
  int v23; // r31
  idMD6AnimProps *v24; // r10
  const idMD6Alias *v25; // r3
  idResource *Existing; // r3
  idMD6AnimData *animData; // r9
  idVec3 *v28; // r11
  idVec3 *v29; // r10
  idQuat *v30; // r31
  double v31; // fp7
  double v32; // fp6
  idQuat *v33; // r4
  idQuat *v34; // r11
  idQuat *v35; // r3
  double v36; // fp13
  double v38; // fp12
  double v39; // fp11
  double v40; // fp10
  double v41; // fp7
  double v42; // fp4
  double v43; // fp3
  double v44; // fp2
  double v45; // fp1
  int trackedMemory; // r11
  idQuat *v47; // r31
  double v48; // fp8
  idQuat *v49; // r4
  double v50; // fp6
  idQuat *v51; // r11
  idQuat *v52; // r3
  double x; // fp0
  double z; // fp12
  double y; // fp11
  double v56; // fp9
  double v57; // fp4
  double v58; // fp3
  double v59; // fp2
  double v60; // fp1
  unsigned __int16 v61; // [sp+50h] [-70h] BYREF
  unsigned __int16 v62[7]; // [sp+52h] [-6Eh] BYREF
  idQuat v63[6]; // [sp+60h] [-60h] BYREF

  decl = (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this->decl;
  if ( decl == nullptr )
    return 0;
  idDeclAnimWeb::FindNodeIndex(this: (idDeclAnimWeb *)&v61, result: decl, subWebIndex: swi, stateIndex: si);
  v11 = v61;
  BlendTree = idAnimator_AnimWeb::idModelAnimState::GetBlendTree(
                this: &this->modelAnimStates.list[(__int16)modelIndex],
                nodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v61);
  if ( BlendTree == nullptr || (num = BlendTree->leaves.num, v14 = 0, num <= 0) )
  {
LABEL_8:
    if ( (__int16)v11 != -1 )
    {
      v18 = this->decl->nodes.list[(__int16)v11];
      if ( v18 != nullptr )
      {
        v19 = this->modelDecls.list[(__int16)modelIndex];
        if ( v19 != nullptr )
        {
          ModelInfo = idDeclAnimWebNode::FindModelInfo(this: v18, modelIndex);
          if ( ModelInfo != nullptr )
          {
            p_animProps = &ModelInfo->animProps;
            v22 = 0;
            if ( ModelInfo->animProps.num > 0 )
            {
              v23 = 0;
              do
              {
                v24 = &p_animProps->list[v23];
                if ( v24->aliasHandle.value == 0xFFFF )
                {
                  Existing = &v24->anim->idResource;
                }
                else
                {
                  v62[0] = v24->aliasHandle.value;
                  v25 = animation->StrongLoadAlias_2(this: animation, a2: v19, a3: v62);
                  if ( v25 == nullptr )
                    goto LABEL_26;
                  Existing = idResourceList::FindExisting(
                               this: &idMD6Anim::resourceList,
                               name: (char *)v25->animRefs.list->str,
                               skipStaleCheck: true);
                }
                if ( Existing != nullptr )
                {
                  trackedMemory = Existing[1].trackedMemory;
                  if ( trackedMemory != 0 && (*(_WORD *)(trackedMemory + 6) & 1) == 0 )
                  {
                    v47 = &quat_identity;
                    v48 = (float)(*(float *)(trackedMemory + 120) - *(float *)(trackedMemory + 72));
                    v49 = &quat_identity;
                    v50 = (float)(*(float *)(trackedMemory + 116) - *(float *)(trackedMemory + 68));
                    translation->x = *(float *)(trackedMemory + 112) - *(float *)(trackedMemory + 64);
                    translation->z = v48;
                    translation->y = v50;
                    v51 = (idQuat *)Existing[1].trackedMemory;
                    if ( v51 != nullptr )
                    {
                      v49 = v51 + 2;
                      v47 = v51 + 5;
                    }
                    v52 = idQuat::Inverse(this: v63, result: v49);
                    x = v47->x;
                    z = v47->z;
                    y = v47->y;
                    v56 = v52->x;
                    v57 = v52->z;
                    v58 = (float)((float)(v47->w * v52->z) + (float)((float)(v52->y * v47->x) + (float)(v47->z * v52->w)));
                    v59 = (float)((float)(v52->w * v47->y) + (float)((float)(v47->z * v52->x) + (float)(v52->y * v47->w)));
                    v60 = (float)-(float)((float)(v52->y * v47->y)
                                        - (float)((float)(v47->w * v52->w) - (float)(v52->x * v47->x)));
                    rotation->x = -(float)((float)(v47->z * v52->y)
                                         - (float)((float)(v47->y * v52->z)
                                                 + (float)((float)(v52->x * v47->w) + (float)(v47->x * v52->w))));
                    rotation->z = -(float)((float)((float)v56 * (float)y) - (float)v58);
                    rotation->y = -(float)((float)((float)x * (float)v57) - (float)v59);
                    rotation->w = -(float)((float)((float)z * (float)v57) - (float)v60);
                    return 1;
                  }
                }
LABEL_26:
                ++v22;
                ++v23;
              }
              while ( v22 < p_animProps->num );
            }
          }
        }
      }
    }
    return 0;
  }
  v15 = 0;
  while ( 1 )
  {
    v16 = BlendTree->leaves.list[v15];
    if ( v16 != nullptr )
    {
      anim = v16->anim;
      if ( (anim->animData->flags & 1) == 0 )
        break;
    }
    ++v14;
    ++v15;
    if ( v14 >= num )
      goto LABEL_8;
  }
  animData = anim->animData;
  v28 = &vec3_origin;
  v29 = &vec3_origin;
  if ( animData != nullptr )
  {
    v29 = (idVec3 *)&animData->startDelta[8];
    v28 = (idVec3 *)&animData->endDelta[8];
  }
  v30 = &quat_identity;
  v31 = (float)(v28->y - v29->y);
  v32 = (float)(v28->z - v29->z);
  translation->x = v28->x - v29->x;
  translation->y = v31;
  v33 = &quat_identity;
  translation->z = v32;
  v34 = (idQuat *)anim->animData;
  if ( v34 != nullptr )
  {
    v33 = v34 + 2;
    v30 = v34 + 5;
  }
  v35 = idQuat::Inverse(this: v63, result: v33);
  v36 = v30->x;
  v38 = v30->y;
  v39 = v30->z;
  v40 = v35->x;
  v41 = v35->y;
  v42 = v35->z;
  v43 = (float)((float)(v35->x * v30->w) + (float)((float)(v30->y * v35->z) + (float)(v30->x * v35->w)));
  v44 = (float)((float)(v35->w * v30->y) + (float)((float)(v30->z * v35->x) + (float)(v35->y * v30->w)));
  v45 = (float)((float)(v30->z * v35->w) + (float)((float)(v30->w * v35->z) + (float)(v35->y * v30->x)));
  rotation->w = -(float)((float)(v30->z * v35->z)
                       - (float)-(float)((float)(v35->y * v30->y)
                                       - (float)((float)(v35->w * v30->w) - (float)(v30->x * v35->x))));
  rotation->x = -(float)((float)((float)v39 * (float)v41) - (float)v43);
  rotation->y = -(float)((float)((float)v36 * (float)v42) - (float)v44);
  rotation->z = -(float)((float)((float)v40 * (float)v38) - (float)v45);
  return 1;
}


// ========================================================================
// ?Update@idModelAnimState@idAnimator_AnimWeb@@QAAXH@Z
// EA  : 0x826D1E40
// RVA : 0x006D1E40
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::idModelAnimState::Update(
        idAnimator_AnimWeb::idModelAnimState *this,
        const int curTime)
{
  idMD6Node *tree; // r29
  int type; // r11
  char v5; // r11
  bool v6; // zf
  idMD6Branch *v7; // r11

  tree = this->tree;
  if ( this->tree != nullptr )
  {
    type = tree->type;
    if ( tree->type == 0 || type == 3 || type == 4 || (v6 = type != 5, v5 = 0, !v6) )
      v5 = 1;
    if ( v5 != 0 && this->blending && idMD6Branch::IsBlendFinished(this: (idMD6Branch *)this->tree) )
    {
      v7 = this->branches[0];
      this->blending = false;
      this->tree = *(idMD6Node **)&tree[8].type;
      v7->left = nullptr;
      this->branches[0]->right = nullptr;
      this->branches[1]->left = nullptr;
      this->branches[1]->right = nullptr;
    }
  }
}


// ========================================================================
// ?Free@idModelAnimState@idAnimator_AnimWeb@@QAAXPAV2@@Z
// EA  : 0x826D1EF0
// RVA : 0x006D1EF0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::idModelAnimState::Free(
        idAnimator_AnimWeb::idModelAnimState *this,
        idAnimator_AnimWeb *web)
{
  idMD6Branch **branches; // r31
  int i; // r30
  int v6; // r28
  int v7; // r30
  idAnimWebBlendTree **list; // r11
  idAnimWebBlendTree *v9; // r31
  idAnimWebBlendTree **v10; // r4

  branches = this->branches;
  for ( i = 2; i != 0; --i )
  {
    if ( *branches != nullptr )
    {
      ((void (__fastcall *)(idMD6Allocator *))web->md6Allocator->Free)(a1: web->md6Allocator);
      *branches = nullptr;
    }
    ++branches;
  }
  v6 = 0;
  if ( this->blendTreeCache.num > 0 )
  {
    v7 = 0;
    do
    {
      list = this->blendTreeCache.list;
      v9 = list[v7];
      if ( v9 != nullptr )
      {
        idAnimWebBlendTree::~idAnimWebBlendTree(this: list[v7]);
        idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->blendTreeCache.num );
  }
  if ( this->blendTreeCache.listStatic == 0 || this->blendTreeCache.listStatic == 2 )
  {
    v10 = this->blendTreeCache.list;
    if ( v10 != nullptr )
      idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    this->blendTreeCache.list = nullptr;
    this->blendTreeCache.size = 0;
  }
  this->blendTreeCache.num = 0;
  this->tree = nullptr;
  this->blending = false;
}


// ========================================================================
// ?BeginNodePlaying@idModelAnimState@idAnimator_AnimWeb@@QAA_NPAV2@PBVidModelInfo@idDeclAnimWebNode@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@HH@Z
// EA  : 0x826D1FE0
// RVA : 0x006D1FE0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

idAnimWebBlendTree *__fastcall idAnimator_AnimWeb::idModelAnimState::BeginNodePlaying(
        idAnimator_AnimWeb::idModelAnimState *this,
        idAnimator_AnimWeb *web,
        const idDeclAnimWebNode::idModelInfo *modelInfo,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nodeIndex,
        int curTime,
        int ticksPerSec)
{
  __int16 v9; // r28
  idAnimWebBlendTree *result; // r3
  idMD6Node **p_tree; // r29
  idMD6Node *v14; // r9
  int recentNodeStart; // r11
  int v16; // r4

  v9 = (__int16)nodeIndex;
  if ( modelInfo != nullptr )
  {
    result = (idAnimWebBlendTree *)idAnimator_AnimWeb::idModelAnimState::GetBlendTree(this, nodeIndex);
    p_tree = &result->tree;
    if ( result != nullptr )
    {
      idAnimWebBlendTree::BeginPlaying(
        this: result,
        web,
        animProps: modelInfo->animProps.list,
        numAnimProps: modelInfo->animProps.num,
        curTime,
        ticksPerSec);
      v14 = *p_tree;
      recentNodeStart = this->recentNodeStart;
      this->blending = false;
      this->tree = v14;
      this->recentNodes[recentNodeStart].value = v9;
      v16 = (__int16)(this->recentNodeStart + 1);
      this->recentNodeStart = v16;
      if ( v16 >= 3 )
        this->recentNodeStart = 0;
      return (idAnimWebBlendTree *)1;
    }
  }
  else
  {
    this->tree = nullptr;
    this->blending = false;
    return (idAnimWebBlendTree *)1;
  }
  return result;
}


// ========================================================================
// ?SetDestFrame@idModelAnimState@idAnimator_AnimWeb@@QBAXPAVidMD6Node@@ABVblendParms_t@@HHAAIAAH@Z
// EA  : 0x826D20B0
// RVA : 0x006D20B0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::idModelAnimState::SetDestFrame(
        idAnimator_AnimWeb::idModelAnimState *this,
        idMD6LeafPlay *node,
        blendParms_t *bp,
        int curTime,
        int ticksPerSec,
        unsigned int *retLongestAnimLen,
        int *retDestFrame)
{
  int type; // r10
  char v15; // r11
  unsigned int v16; // r10
  const idMD6Anim *anim; // r9
  unsigned int AnimLength; // r3
  __int64 v19; // r7
  idMD6AnimData *animData; // r8
  __int64 v21; // r5
  unsigned __int16 v22; // [sp+50h] [-50h] BYREF
  __int16 v23[3]; // [sp+52h] [-4Eh] BYREF
  __int64 v24; // [sp+58h] [-48h]

  while ( 1 )
  {
    while ( 1 )
    {
      type = node->type;
      if ( node->type == 0 || type == 3 || type == 4 || (v15 = 0, type == 5) )
        v15 = 1;
      if ( v15 == 0 )
        break;
      idAnimator_AnimWeb::idModelAnimState::SetDestFrame(
        this,
        node: (idMD6Node *)node->anim,
        bp,
        curTime,
        ticksPerSec,
        retLongestAnimLen,
        retDestFrame);
      node = *(idMD6LeafPlay **)&node->weightGroup;
    }
    if ( type != 6 )
      break;
    v16 = *(_DWORD *)&node->weightGroup;
    if ( v16 == 0 )
      return;
    anim = node->anim;
    if ( *(idMD6Anim_vtbl **)((char *)&anim->__vftable
                            + ((4
                              * (((__PAIR64__(v16 >> 31, HIWORD(node[3].rateScale)) - v16) >> 32)
                               & HIWORD(node[3].rateScale)))
                             & 0x3FFFC)) == nullptr )
      return;
    node = *(idMD6LeafPlay **)((char *)&anim->__vftable
                             + ((4
                               * (((__PAIR64__(v16 >> 31, HIWORD(node[3].rateScale)) - v16) >> 32)
                                & HIWORD(node[3].rateScale)))
                              & 0x3FFFC));
  }
  if ( type == 2 )
  {
    blendParms_t::GetDestFrames(this: bp, anim: node->anim, firstFrame: (__int16 *)&v22, duration_: v23);
    idMD6LeafPlay::SetFrame(this: node, gameTime: curTime, ticksPerSec, targetFrame: v22);
    AnimLength = idMD6LeafPlay::GetAnimLength(this: node, ticksPerSec, applyRateScale: true);
    if ( AnimLength > *retLongestAnimLen )
    {
      *retDestFrame = (__int16)v22;
      *retLongestAnimLen = AnimLength;
    }
  }
  else if ( type == 1 )
  {
    blendParms_t::GetDestFrames(this: bp, anim: node->anim, firstFrame: (__int16 *)&v22, duration_: v23);
    LODWORD(v19) = (__int16)v22;
    animData = node->anim->animData;
    v24 = v19;
    LODWORD(v21) = animData->numFrames;
    *(float *)&node[2].anim = (float)v19 / (float)v21;
  }
}


// ========================================================================
// ?UsesAnyScalarIndices@idAnimator_AnimWeb@@QBA_NABV?$idList@H$04@@@Z
// EA  : 0x826D2270
// RVA : 0x006D2270
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::UsesAnyScalarIndices(idAnimator_AnimWeb *this, const idList<int,5> *testScalars)
{
  int v4; // r29
  int i; // r30
  int v6; // r10
  idAnimator_AnimWeb::idModelAnimState *v7; // r11
  int num; // r8
  idAnimWebBlendTree **list; // r7
  int v10; // r11
  idAnimWebBlendTree *v11; // r3
  idAnimator_AnimWeb::idModelAnimState *v12; // r3
  int v13; // r11
  int value; // r4
  idAnimWebBlendTree *BlendTree; // r3

  v4 = 0;
  if ( this->modelAnimStates.num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v6 = 0;
    v7 = &this->modelAnimStates.list[i];
    num = v7->blendTreeCache.num;
    if ( num > 0 )
    {
      list = v7->blendTreeCache.list;
      v10 = 0;
      while ( list[v10]->nodeIndex.value != this->curNodeIndex.value )
      {
        ++v6;
        ++v10;
        if ( v6 >= num )
          goto LABEL_18;
      }
      v11 = list[v6];
      if ( v11 != nullptr )
      {
        if ( idAnimWebBlendTree::UsesAnyScalarIndices(this: v11, web: this, testScalars) )
          break;
        v12 = &this->modelAnimStates.list[i];
        if ( v12->blending )
        {
          v13 = (__int16)(this->pathIndex + 1);
          if ( v13 < 0 || v13 >= this->curPath.num )
            value = -1;
          else
            value = (unsigned __int16)this->curPath.path[v13].value;
          if ( (__int16)value != this->curNodeIndex.value )
          {
            BlendTree = (idAnimWebBlendTree *)idAnimator_AnimWeb::idModelAnimState::GetBlendTree(
                                                this: v12,
                                                nodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)value);
            if ( BlendTree != nullptr
              && idAnimWebBlendTree::UsesAnyScalarIndices(this: BlendTree, web: this, testScalars) )
            {
              break;
            }
          }
        }
      }
    }
LABEL_18:
    if ( ++v4 >= this->modelAnimStates.num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?Free@idAnimator_AnimWeb@@QAAXXZ
// EA  : 0x826D23C0
// RVA : 0x006D23C0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::Free(idAnimator_AnimWeb *this)
{
  int v2; // r29
  int v3; // r30

  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scalars);
  v2 = 0;
  if ( this->modelAnimStates.num > 0 )
  {
    v3 = 0;
    do
    {
      idAnimator_AnimWeb::idModelAnimState::Free(this: &this->modelAnimStates.list[v3], web: this);
      ++v2;
      ++v3;
    }
    while ( v2 < this->modelAnimStates.num );
  }
  this->destStateIndices.numStates = 0;
  this->nodeStartFrame = 0;
  this->decl = nullptr;
  this->curEdgeNodeIndex.value = -1;
  this->curEdgeIndex = -1;
  this->destSubWebIndex.value = -1;
  this->pathIndex = -1;
  this->nodeStartTime = -1;
  this->prevNodeStartTime = -1;
  this->curNodeIndex.value = -1;
  this->prevNodeIndex.value = -1;
  this->curPath.cost = 0x7FFFFFFF;
  this->curPath.num = 0;
  this->forcedEdge.destNodeIndex.value = -1;
  this->forcedEdge.destSubWebIndex.value = -1;
  this->handle.value = -1;
  idAnimator_AnimWeb::CacheCurNode(this);
  idAnimator_AnimWeb::CacheDestNode(this);
}


// ========================================================================
// ?ForceState@idAnimator_AnimWeb@@QAA?AW4awPathResult_t@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@ABVblendParms_t@@H@Z
// EA  : 0x826D2478
// RVA : 0x006D2478
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::ForceState(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex_,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex_,
        const blendParms_t *blendParms,
        int blendEventMask_)
{
  const idDeclAnimWeb *decl; // r3
  int v10; // r30
  const char **p_str; // r28
  const char *str; // r31
  const char *StateName; // r3
  const idDeclAnimWeb *v15; // r3
  const char *v16; // r31
  const char *v17; // r30
  const char *SubWebName; // r3
  idAnimator_AnimWeb::forcedEdge_t *p_forcedEdge; // r10
  char *p_flags; // r11
  int i; // ctr
  BOOL clearEventsOnStateChanges; // r8
  __int16 v23; // [sp+50h] [-40h] BYREF

  decl = this->decl;
  if ( decl == nullptr )
    return 0;
  v10 = (__int16)stateIndex_;
  this->curEdgeNodeIndex.value = this->curNodeIndex.value;
  if ( (__int16)stateIndex_ < 0
    || (__int16)stateIndex_ >= decl->states.num
    || (p_str = &decl->states.list[(__int16)stateIndex_].name.str) == nullptr )
  {
    str = decl->name.str;
    StateName = idDeclAnimWeb::GetStateName(this: decl, index: stateIndex_);
    idLib::Warning(fmt: "Id %d, '%s', is not a valid destination state in web %s", v10, StateName, str);
    return 0;
  }
  idDeclAnimWeb::FindNodeIndex(
    this: (idDeclAnimWeb *)&v23,
    result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)decl,
    subWebIndex: subWebIndex_,
    stateIndex: stateIndex_);
  if ( v23 >= 0 )
  {
    if ( v23 == this->curNodeIndex.value )
    {
      this->destSubWebIndex.value = -1;
      this->destStateIndices.numStates = 0;
      this->viaStateIndices.numStates = 0;
      this->viaSubWebIndex.value = -1;
      this->otherSubWebIndex.value = -1;
      this->curEdgeNodeIndex.value = -1;
      this->curEdgeIndex = -1;
      this->curPath.cost = 0x7FFFFFFF;
      this->curPath.num = 0;
      this->pathIndex = -1;
      this->forcedEdge.destNodeIndex.value = -1;
      this->forcedEdge.destSubWebIndex.value = -1;
      return 2;
    }
    else
    {
      this->forcedEdge.destNodeIndex.value = v23;
      this->blendEventMask = blendEventMask_;
      p_forcedEdge = &this->forcedEdge;
      this->forcedEdge.destSubWebIndex.value = (__int16)subWebIndex_;
      p_flags = &blendParms[-1].parms.flags;
      for ( i = 5; i != 0; --i )
      {
        p_flags += 4;
        p_forcedEdge = (idAnimator_AnimWeb::forcedEdge_t *)((char *)p_forcedEdge + 4);
        *(_DWORD *)&p_forcedEdge->destNodeIndex.value = *(_DWORD *)p_flags;
      }
      clearEventsOnStateChanges = this->clearEventsOnStateChanges;
      this->destStateIndices.numStates = 0;
      this->destSubWebIndex.value = -1;
      this->viaStateIndices.numStates = 0;
      this->viaSubWebIndex.value = -1;
      this->otherSubWebIndex.value = -1;
      this->interruptPath = INTR_PATH_YES;
      this->interruptBlend = INTR_BLEND_YES;
      this->skipForcedEdgeAutoPath = false;
      if ( clearEventsOnStateChanges )
        this->eventHandler.ClearEvents(this: &this->eventHandler);
      return 1;
    }
  }
  else
  {
    v15 = this->decl;
    v16 = *p_str;
    v17 = v15->name.str;
    SubWebName = idDeclAnimWeb::GetSubWebName(this: v15, index: subWebIndex_);
    idLib::Warning(fmt: "(%s) Sub-web '%s' does not contain a node with state '%s'", v17, SubWebName, v16);
    return 0;
  }
}


// ========================================================================
// ?ForceState@idAnimator_AnimWeb@@QAA?AW4awPathResult_t@@PBD0ABVblendParms_t@@H@Z
// EA  : 0x826D2640
// RVA : 0x006D2640
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::ForceState(
        idAnimator_AnimWeb *this,
        const char *subWebName,
        const char *stateName,
        const blendParms_t *blendParms,
        int blendEventMask_)
{
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *decl; // r4
  __int16 v12; // [sp+50h] [-40h] BYREF
  __int16 v13; // [sp+52h] [-3Eh] BYREF

  decl = (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->decl;
  if ( decl == nullptr )
    return 0;
  idDeclAnimWeb::GetSubWebIndexForName(this: (idDeclAnimWeb *)&v12, result: decl, subWebName);
  if ( v12 < 0 )
  {
    idLib::Warning(
      fmt: "idAnimator_AnimWeb::ForceState - animWeb '%s' does not have a sub-web '%s'",
      this->decl->name.str,
      subWebName);
    return 0;
  }
  idDeclAnimWeb::GetStateIndexForName(
    this: (idDeclAnimWeb *)&v13,
    result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->decl,
    name: stateName);
  if ( v13 >= 0 )
    return idAnimator_AnimWeb::ForceState(
             this,
             subWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v12,
             stateIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v13,
             blendParms,
             blendEventMask_);
  idLib::Warning(
    fmt: "idAnimator_AnimWeb::ForceState - animWeb '%s' does not have a state '%s'",
    this->decl->name.str,
    stateName);
  return 0;
}


// ========================================================================
// ?InternalShutdown@idAnimator_AnimWeb@@MAAXPAVidAnimStack@@@Z
// EA  : 0x826D2710
// RVA : 0x006D2710
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::InternalShutdown(idAnimator_AnimWeb *this, idAnimStack *stack)
{
  if ( this->mergeBranch != nullptr )
  {
    ((void (__fastcall *)(idMD6BlockAlloc *))stack->md6Allocator.Free)(a1: &stack->md6Allocator);
    this->mergeBranch = nullptr;
  }
  idAnimator_AnimWeb::Free(this);
}


// ========================================================================
// ?SelectRandomBlendVals@idAnimator_AnimWeb@@AAAXPBVidDeclAnimWebNode@@0@Z
// EA  : 0x826D2778
// RVA : 0x006D2778
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAnimator_AnimWeb::SelectRandomBlendVals(
        idAnimator_AnimWeb *this,
        const idDeclAnimWebNode *curNode,
        const idDeclAnimWebNode *nextNode)
{
  int v6; // r2 OVERLAPPED
  int v7; // r27
  int v8; // r30
  int v9; // r9
  idAnimator_AnimWeb::idModelAnimState *v10; // r11
  int num; // r10
  idAnimWebBlendTree **list; // r8
  int v13; // r11
  idAnimWebBlendTree *v14; // r3
  idAnimWebBlendTree *BlendTree; // r3
  int *v16; // r4
  int *v17; // r28
  int v18; // ctr
  int v19; // r8
  int *v20; // r5
  int v21; // r10
  int *v22; // r11
  unsigned int v23; // r9
  int v24; // r3
  __int64 v25; // r11
  int v26; // r3
  int v27; // r9
  int v28; // r30
  int v29; // r8
  signed int v30; // r11
  __int64 v31; // r10
  unsigned int seed; // r10
  unsigned int v33; // r10
  int v34; // r5
  __int64 v35; // r9
  double v36; // fp11
  int v37; // r4
  idList<int,5> v38; // [sp+60h] [-70h] BYREF
  idList<int,5> v39[6]; // [sp+70h] [-60h] BYREF

  if ( nextNode != nullptr )
  {
    if ( (_S13_8 & 1) == 0 )
    {
      _S13_8 |= 1u;
      random_1.seed = Sys_Milliseconds();
    }
    if ( curNode != nullptr )
    {
      idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)v39);
      idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v38);
      v7 = 0;
      if ( this->modelAnimStates.num > 0 )
      {
        v8 = 0;
        do
        {
          v9 = 0;
          v10 = &this->modelAnimStates.list[v8];
          num = v10->blendTreeCache.num;
          if ( num > 0 )
          {
            list = v10->blendTreeCache.list;
            v13 = 0;
            while ( list[v13]->nodeIndex.value != curNode->nodeIndex.value )
            {
              ++v9;
              ++v13;
              if ( v9 >= num )
                goto LABEL_15;
            }
            v14 = list[v9];
            if ( v14 != nullptr )
            {
              idAnimWebBlendTree::GetUsedScalarIndices(
                this: v14,
                web: this,
                usedScalars: v39,
                minIndex: this->firstRandomScalarIndex,
                maxIndex: this->firstRandomScalarIndex + 7);
              BlendTree = (idAnimWebBlendTree *)idAnimator_AnimWeb::idModelAnimState::GetBlendTree(
                                                  this: &this->modelAnimStates.list[v8],
                                                  nodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)nextNode->nodeIndex.value);
              if ( BlendTree != nullptr )
                idAnimWebBlendTree::GetUsedScalarIndices(
                  this: BlendTree,
                  web: this,
                  usedScalars: &v38,
                  minIndex: this->firstRandomScalarIndex,
                  maxIndex: this->firstRandomScalarIndex + 7);
            }
          }
LABEL_15:
          ++v7;
          ++v8;
        }
        while ( v7 < this->modelAnimStates.num );
      }
      v16 = v39[0].list;
      v17 = v38.list;
      if ( v38.num > 0 )
      {
        v18 = v38.num;
        v19 = v39[0].num;
        v20 = v38.list;
        do
        {
          v21 = 0;
          if ( v19 <= 0 )
            goto LABEL_24;
          v22 = v16;
          while ( *v22 != *v20 )
          {
            ++v21;
            ++v22;
            if ( v21 >= v19 )
              goto LABEL_24;
          }
          if ( v21 < 0 )
          {
LABEL_24:
            v23 = *v20 - this->firstRandomScalarIndex;
            if ( v23 <= 6 )
            {
              LODWORD(v25) = v23 + 1;
              HIDWORD(v25) = random_1;
              __twllei(v23 + 1, 0);
              HIDWORD(v25) = 1664525 * HIDWORD(v25) + 1013904223;
              v24 = (HIDWORD(v25) >> 10) & 0x7FFF;
              random_1.seed = HIDWORD(v25);
              HIDWORD(v25) = v24 % (int)(v23 + 1);
              __twlgei((v23 + 1) & ~(__ROL4__(v24, 1) - 1), 0xFFFFFFFF);
              v26 = HIDWORD(v25);
              v27 = 4 * (v23 + 123);
              if ( (float)*(__int64 *)(&v6 - 1) == *(float *)((char *)&this->__vftable + v27) )
              {
                __twllei(v25, 0);
                v28 = (HIDWORD(v25) + 1) / (int)v25 * v25;
                LODWORD(v25) = v25 & ~(__ROL4__(HIDWORD(v25) + 1, 1) - 1);
                HIDWORD(v25) = HIDWORD(v25) + 1 - v28;
                __twlgei(v25, 0xFFFFFFFF);
              }
              LODWORD(v25) = HIDWORD(v25);
              *(float *)((char *)&this->__vftable + v27) = (float)v25;
            }
          }
          ++v20;
          --v18;
        }
        while ( v18 != 0 );
      }
      if ( v38.listStatic == 0 || v38.listStatic == 2 )
      {
        if ( v17 != nullptr )
        {
          idMem::Free(this: &mem, ptr: v17, align: ALIGN_16);
          v16 = v39[0].list;
        }
        v38.list = nullptr;
        v38.size = 0;
      }
      v38.num = 0;
      if ( (v39[0].listStatic == 0 || v39[0].listStatic == 2) && v16 != nullptr )
        idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
    }
    else
    {
      v29 = 1;
      do
      {
        v30 = v29 + 1;
        if ( v29 == -1 )
        {
          LODWORD(v31) = 0;
        }
        else
        {
          seed = random_1.seed;
          __twllei(v30, 0);
          v33 = 1664525 * seed + 1013904223;
          v34 = (v33 >> 10) & 0x7FFF;
          random_1.seed = v33;
          LODWORD(v31) = v34 % v30;
          __twlgei(v30 & ~(__ROL4__(v34, 1) - 1), 0xFFFFFFFF);
        }
        LODWORD(v35) = v31;
        HIDWORD(v35) = v29 + 122;
        v36 = (float)v35;
        HIDWORD(v31) = 4 * HIDWORD(v35);
        if ( v36 == *((float *)&this->__vftable + HIDWORD(v35)) )
        {
          __twllei(v30, 0);
          v37 = __ROL4__(v31 + 1, 1) - 1;
          LODWORD(v31) = ((int)v31 + 1) % v30;
          __twlgei(v30 & ~v37, 0xFFFFFFFF);
        }
        v29 = v30;
        *(float *)((char *)&this->__vftable + HIDWORD(v31)) = (float)v31;
      }
      while ( v30 < 8 );
    }
  }
}


// ========================================================================
// __unwind$256481
// EA  : 0x826D2B30
// RVA : 0x006D2B30
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_256481()
{
  _S13_8 &= ~1u;
}


// ========================================================================
// __unwind$256482
// EA  : 0x826D2B50
// RVA : 0x006D2B50
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_256482()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 112));
}


// ========================================================================
// __unwind$256483
// EA  : 0x826D2B78
// RVA : 0x006D2B78
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_256483()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}


// ========================================================================
// ?FindFirstLeaf@idAnimator_AnimWeb@@ABAPBVidMD6Leaf@@PBVidMD6Node@@H_N@Z
// EA  : 0x826D2BA0
// RVA : 0x006D2BA0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

idMD6LeafPlay *__fastcall idAnimator_AnimWeb::FindFirstLeaf(
        idAnimator_AnimWeb *this,
        const idMD6Node *tree,
        int curTime,
        const bool stillPlaying)
{
  int v6; // r29
  idMD6LeafPlay **v7; // r30
  idMD6LeafPlay *v8; // r31
  int type; // r11
  char v10; // r11
  bool v11; // zf
  int v12; // r11
  unsigned int v13; // r11
  const idMD6Anim *anim; // r9
  const idMD6Node *v16; // [sp+50h] [-C0h] BYREF

  v16 = tree;
  v6 = 0;
  v7 = (idMD6LeafPlay **)&v16;
  do
  {
    v8 = *v7;
    type = (*v7)->type;
    if ( (*v7)->type == 0 || type == 3 || type == 4 || (v11 = type != 5, v10 = 0, !v11) )
      v10 = 1;
    if ( v10 != 0 )
    {
      --v6;
      --v7;
      if ( v8->anim != nullptr && (!stillPlaying || !idMD6Branch::IsBlendFinished(this: (idMD6Branch *)v8)) )
      {
        ++v6;
        *++v7 = (idMD6LeafPlay *)v8->anim;
      }
      if ( *(_DWORD *)&v8->weightGroup != 0 && (!stillPlaying || !idMD6Branch::IsBlendFinished(this: (idMD6Branch *)v8)) )
      {
        ++v6;
        *++v7 = *(idMD6LeafPlay **)&v8->weightGroup;
      }
    }
    else
    {
      v12 = v8->type;
      if ( v12 == 6 )
      {
        v13 = *(_DWORD *)&v8->weightGroup;
        --v6;
        --v7;
        if ( v13 != 0 )
        {
          anim = v8->anim;
          if ( *(idMD6Anim_vtbl **)((char *)&anim->__vftable
                                  + ((4
                                    * (((__PAIR64__(v13 >> 31, HIWORD(v8[3].rateScale)) - v13) >> 32)
                                     & HIWORD(v8[3].rateScale)))
                                   & 0x3FFFC)) != nullptr )
          {
            ++v6;
            *++v7 = *(idMD6LeafPlay **)((char *)&anim->__vftable
                                      + ((4
                                        * (((__PAIR64__(v13 >> 31, HIWORD(v8[3].rateScale)) - v13) >> 32)
                                         & HIWORD(v8[3].rateScale)))
                                       & 0x3FFFC));
          }
        }
      }
      else
      {
        if ( v12 == 2 )
        {
          if ( idMD6LeafPlay::IsPlaying(
                 this: *v7,
                 gameTime: curTime,
                 ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz) )
          {
            return v8;
          }
        }
        else if ( v12 != 1 )
        {
          return nullptr;
        }
        if ( !stillPlaying )
          return v8;
      }
    }
  }
  while ( v6 >= 0 );
  return nullptr;
}


// ========================================================================
// ?FindLeafWithMatchingAnim@idAnimator_AnimWeb@@ABAPBVidMD6Leaf@@PBVidMD6Node@@HPBVidMD6Anim@@_N@Z
// EA  : 0x826D2D68
// RVA : 0x006D2D68
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

idMD6LeafPlay *__fastcall idAnimator_AnimWeb::FindLeafWithMatchingAnim(
        idAnimator_AnimWeb *this,
        const idMD6Node *tree,
        int curTime,
        const idMD6Anim *anim,
        const bool stillPlaying)
{
  int v8; // r29
  idMD6LeafPlay *v9; // r27
  idMD6LeafPlay **v10; // r30
  idMD6LeafPlay *v11; // r31
  int type; // r11
  char v13; // r11
  bool v14; // zf
  int v15; // r11
  unsigned int v16; // r11
  const idMD6Anim *v17; // r9
  const idMD6Node *v19; // [sp+50h] [-D0h] BYREF

  v19 = tree;
  v8 = 0;
  v9 = nullptr;
  v10 = (idMD6LeafPlay **)&v19;
  do
  {
    v11 = *v10;
    type = (*v10)->type;
    if ( (*v10)->type == 0 || type == 3 || type == 4 || (v14 = type != 5, v13 = 0, !v14) )
      v13 = 1;
    if ( v13 != 0 )
    {
      --v8;
      --v10;
      if ( v11->anim != nullptr && (!stillPlaying || !idMD6Branch::IsBlendFinished(this: (idMD6Branch *)v11)) )
      {
        ++v8;
        *++v10 = (idMD6LeafPlay *)v11->anim;
      }
      if ( *(_DWORD *)&v11->weightGroup != 0
        && (!stillPlaying || !idMD6Branch::IsBlendFinished(this: (idMD6Branch *)v11)) )
      {
        ++v8;
        *++v10 = *(idMD6LeafPlay **)&v11->weightGroup;
      }
      continue;
    }
    v15 = v11->type;
    if ( v15 == 6 )
    {
      v16 = *(_DWORD *)&v11->weightGroup;
      --v8;
      --v10;
      if ( v16 != 0 )
      {
        v17 = v11->anim;
        if ( *(idMD6Anim_vtbl **)((char *)&v17->__vftable
                                + ((4
                                  * (((__PAIR64__(v16 >> 31, HIWORD(v11[3].rateScale)) - v16) >> 32)
                                   & HIWORD(v11[3].rateScale)))
                                 & 0x3FFFC)) != nullptr )
        {
          ++v8;
          *++v10 = *(idMD6LeafPlay **)((char *)&v17->__vftable
                                     + ((4
                                       * (((__PAIR64__(v16 >> 31, HIWORD(v11[3].rateScale)) - v16) >> 32)
                                        & HIWORD(v11[3].rateScale)))
                                      & 0x3FFFC));
        }
      }
      continue;
    }
    if ( v15 != 2 )
    {
      if ( v15 != 1 )
        return v9;
LABEL_24:
      if ( stillPlaying )
        goto LABEL_27;
      goto LABEL_25;
    }
    if ( !idMD6LeafPlay::IsPlaying(
            this: *v10,
            gameTime: curTime,
            ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz) )
      goto LABEL_24;
LABEL_25:
    if ( v11->anim == anim )
      v9 = v11;
LABEL_27:
    --v10;
    --v8;
    if ( v9 != nullptr )
      return v9;
  }
  while ( v8 >= 0 );
  return v9;
}


// ========================================================================
// ?BeginNodesPlaying@idAnimator_AnimWeb@@QAAXV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@H@Z
// EA  : 0x826D2F58
// RVA : 0x006D2F58
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::BeginNodesPlaying(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nodeIndex,
        int curTime)
{
  const idDeclAnimWeb *decl; // r10
  idDeclAnimWebNode *v7; // r24
  int v8; // r27
  int i; // r28
  const idDeclAnimWebNode::idModelInfo *ModelInfo; // r5
  idStr v11[3]; // [sp+50h] [-70h] BYREF

  decl = this->decl;
  if ( decl != nullptr )
  {
    v7 = (__int16)nodeIndex == -1 ? nullptr : decl->nodes.list[(__int16)nodeIndex];
    v8 = 0;
    if ( this->modelAnimStates.num > 0 )
    {
      for ( i = 0; ; ++i )
      {
        ModelInfo = idDeclAnimWebNode::FindModelInfo(
                      this: v7,
                      modelIndex: (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)(__int16)v8);
        if ( ModelInfo != nullptr )
          goto _LN63_0;
        if ( v8 == 0 )
          break;
LABEL_11:
        if ( ++v8 >= this->modelAnimStates.num )
          return;
      }
      v11[0].len = 0;
      v11[0].baseBuffer[0] = 0;
      v11[0].allocedAndFlag = 20;
      v11[0].data = v11[0].baseBuffer;
      idDeclAnimWebNode::GetName(this: v7, web: this->decl, name: v11);
      idLib::Error(fmt: "animWeb node '%s' missing modelinfo.", v11[0].data);
_LN63_0:
      idAnimator_AnimWeb::idModelAnimState::BeginNodePlaying(
        this: &this->modelAnimStates.list[i],
        web: this,
        modelInfo: ModelInfo,
        nodeIndex,
        curTime,
        ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz);
      goto LABEL_11;
    }
  }
}


// ========================================================================
// $M257217
// EA  : 0x826D3058
// RVA : 0x006D3058
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _M257217()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?GetNodeAnimLength@idAnimator_AnimWeb@@QBA_NHV?$idIndex@FW4invalidModelIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@W4wrapMode_t@idMD6Leaf@@_NAAUanimInfo_t@1@@Z
// EA  : 0x826D3088
// RVA : 0x006D3088
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

BOOL __fastcall idAnimator_AnimWeb::GetNodeAnimLength(
        idAnimator_AnimWeb *this,
        int curTime,
        const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *modelIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nodeIndex,
        idMD6Leaf::wrapMode_t wrapMode,
        bool ignoreAdditive,
        idAnimator_AnimWeb::animInfo_t *animInfo)
{
  __int16 v10; // r29
  int v14; // r30
  idAnimWebBlendTree *BlendTree; // r3
  idDeclAnimWebNode *v17; // r19
  const idDeclMD6 *v18; // r22
  const idDeclAnimWebNode::idModelInfo *ModelInfo; // r3
  idList<idMD6AnimProps,32> *p_animProps; // r28
  int v21; // r30
  int v22; // r25
  int v23; // r29
  idMD6AnimProps *v24; // r10
  const idMD6Alias *v25; // r3
  idResource *Existing; // r3
  int v27; // r10
  signed int v28; // r11
  int v29; // r8
  int v30; // r11
  int v31; // r11
  __int16 v32; // [sp+50h] [-B0h] BYREF
  _WORD *trackedMemory; // [sp+54h] [-ACh]
  idStr v34[5]; // [sp+60h] [-A0h] BYREF

  v10 = (__int16)nodeIndex;
  if ( this->decl == nullptr )
    return false;
  v14 = (__int16)modelIndex;
  BlendTree = (idAnimWebBlendTree *)idAnimator_AnimWeb::idModelAnimState::GetBlendTree(
                                      this: &this->modelAnimStates.list[(__int16)modelIndex],
                                      nodeIndex);
  if ( BlendTree != nullptr )
    return idAnimWebBlendTree::GetAnimLength(
             this: BlendTree,
             curTime,
             ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
             wrapMode,
             ignoreAdditive,
             curFrame: &animInfo->curFrame,
             numFrames: &animInfo->numFrames,
             frameRate: &animInfo->frameRate);
  animInfo->curFrame = 0;
  if ( v10 == -1 )
    return false;
  v17 = this->decl->nodes.list[v10];
  if ( v17 == nullptr )
    return false;
  v18 = this->modelDecls.list[v14];
  if ( v18 == nullptr )
    return false;
  ModelInfo = idDeclAnimWebNode::FindModelInfo(this: v17, modelIndex);
  if ( ModelInfo == nullptr )
    return false;
  p_animProps = &ModelInfo->animProps;
  v21 = -1;
  v22 = 0;
  if ( ModelInfo->animProps.num <= 0 )
    goto LABEL_27;
  v23 = 0;
  do
  {
    v24 = &p_animProps->list[v23];
    if ( wrapMode == WRAP_MAX || v24->wrap == wrapMode )
    {
      HIWORD(trackedMemory) = v24->aliasHandle.value;
      if ( HIWORD(trackedMemory) == 0xFFFF )
      {
        Existing = &v24->anim->idResource;
      }
      else
      {
        v32 = HIWORD(trackedMemory);
        v25 = animation->StrongLoadAlias_2(this: animation, a2: v18, a3: &v32);
        if ( v25 == nullptr )
          goto LABEL_25;
        Existing = idResourceList::FindExisting(
                     this: &idMD6Anim::resourceList,
                     name: (char *)v25->animRefs.list->str,
                     skipStaleCheck: true);
      }
      if ( Existing != nullptr )
      {
        trackedMemory = (_WORD *)Existing[1].trackedMemory;
        if ( trackedMemory != nullptr && (!ignoreAdditive || (trackedMemory[3] & 1) == 0) )
        {
          v27 = (unsigned __int16)trackedMemory[4];
          v28 = (unsigned __int16)trackedMemory[5];
          v29 = 1000 * v27 / v28;
          __twllei(v28, 0);
          __twlgei(v28 & ~(__ROL4__(1000 * v27, 1) - 1), 0xFFFFFFFF);
          if ( v29 > v21 )
          {
            animInfo->numFrames = (unsigned __int16)trackedMemory[4];
            v30 = Existing[1].trackedMemory;
            if ( v30 != 0 )
              v31 = *(unsigned __int16 *)(v30 + 10);
            else
              v31 = 30;
            animInfo->frameRate = v31;
            v21 = v29;
          }
        }
      }
    }
LABEL_25:
    ++v22;
    ++v23;
  }
  while ( v22 < p_animProps->num );
  if ( v21 < 0 )
  {
LABEL_27:
    v34[0].len = 0;
    v34[0].baseBuffer[0] = 0;
    v34[0].allocedAndFlag = 20;
    v34[0].data = v34[0].baseBuffer;
    idDeclAnimWebNode::GetName(this: v17, web: this->decl, name: v34);
    idLib::Warning(
      fmt: "idAnimator_AnimWeb::GetNodeAnimLength - no valid animations at node '%s' in web '%s'",
      v34[0].data,
      this->decl->name.str);
    idStr::FreeData(this: v34);
    return false;
  }
  return true;
}


// ========================================================================
// __unwind$257234
// EA  : 0x826D3330
// RVA : 0x006D3330
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_257234()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// ?GetNodeAnimLength@idAnimator_AnimWeb@@QBA_NHV?$idIndex@FW4invalidModelIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@W4wrapMode_t@idMD6Leaf@@_NAAUanimInfo_t@1@@Z
// EA  : 0x826D3358
// RVA : 0x006D3358
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

BOOL __fastcall idAnimator_AnimWeb::GetNodeAnimLength(
        idAnimator_AnimWeb *this,
        int curTime,
        const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *modelIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *swi,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *si,
        idMD6Leaf::wrapMode_t wrapMode,
        bool ignoreAdditive,
        idAnimator_AnimWeb::animInfo_t *animInfo)
{
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *decl; // r4
  unsigned __int16 v16; // [sp+50h] [-40h] BYREF

  decl = (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this->decl;
  if ( decl == nullptr )
    return false;
  idDeclAnimWeb::FindNodeIndex(this: (idDeclAnimWeb *)&v16, result: decl, subWebIndex: swi, stateIndex: si);
  return idAnimator_AnimWeb::GetNodeAnimLength(
           this,
           curTime,
           modelIndex,
           nodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v16,
           wrapMode,
           ignoreAdditive,
           animInfo);
}


// ========================================================================
// ??1idModelAnimState@idAnimator_AnimWeb@@QAA@XZ
// EA  : 0x826D33D8
// RVA : 0x006D33D8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::idModelAnimState::~idModelAnimState(idAnimator_AnimWeb::idModelAnimState *this)
{
  int v2; // r27
  int v3; // r29
  idAnimWebBlendTree *v4; // r10
  idAnimWebBlendTree *v5; // r28
  idAnimWebBlendTree **list; // r4
  idAnimWebBlendTree **v7; // r4

  v2 = 0;
  if ( this->blendTreeCache.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->blendTreeCache.list[v3];
      if ( v4 != nullptr )
      {
        v5 = this->blendTreeCache.list[v3];
        idAnimWebBlendTree::~idAnimWebBlendTree(this: v4);
        idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
        this->blendTreeCache.list[v3] = nullptr;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->blendTreeCache.num );
  }
  if ( this->blendTreeCache.listStatic == 0 || this->blendTreeCache.listStatic == 2 )
  {
    list = this->blendTreeCache.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->blendTreeCache.list = nullptr;
    this->blendTreeCache.size = 0;
  }
  this->blendTreeCache.num = 0;
  if ( this->blendTreeCache.listStatic == 0 || this->blendTreeCache.listStatic == 2 )
  {
    v7 = this->blendTreeCache.list;
    if ( v7 != nullptr )
      idMem::Free(this: &mem, ptr: v7, align: ALIGN_16);
    this->blendTreeCache.list = nullptr;
    this->blendTreeCache.size = 0;
  }
  this->blendTreeCache.num = 0;
}


// ========================================================================
// __unwind$257505
// EA  : 0x826D34E0
// RVA : 0x006D34E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_257505()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 12));
}


// ========================================================================
// ?StartBlend@idModelAnimState@idAnimator_AnimWeb@@QAAXPAV2@PBVidModelInfo@idDeclAnimWebNode@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@2ABVblendParms_t@@HHAAIAAH@Z
// EA  : 0x826D3510
// RVA : 0x006D3510
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::idModelAnimState::StartBlend(
        idAnimator_AnimWeb::idModelAnimState *this,
        idAnimator_AnimWeb *web,
        const idDeclAnimWebNode::idModelInfo *modelInfo,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *curNodeIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nextNodeIndex,
        blendParms_t *bp,
        int curTime,
        int ticksPerSec,
        unsigned int *retLongestAnimLen,
        int *retDestFrame,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        unsigned int *a28,
        int a29,
        int *a30)
{
  idMD6Branch *tree; // r27
  idMD6Branch *v37; // r11
  idMD6Branch *v38; // r23
  const idAnimWebBlendTree *BlendTree; // r30
  idMD6LeafPlay **v40; // r3
  idMD6Node *v41; // r28
  idMD6LeafPlay *v42; // r30
  __int64 v43; // r8
  int v44; // r5
  int v45; // r4
  __int64 v46; // r8
  int v47; // r5
  int v48; // r4
  __int64 v49; // r8

  *a28 = 0;
  *a30 = 0;
  tree = (idMD6Branch *)this->tree;
  v37 = this->branches[0];
  if ( this->tree == v37 )
    v38 = this->branches[1];
  else
    v38 = this->branches[0];
  if ( v38 == v37 )
    v37 = this->branches[1];
  if ( v37->left == v38 )
    v37->left = v38->right;
  if ( (unsigned __int8)idAnimator_AnimWeb::idModelAnimState::BeginNodePlaying(
                          this,
                          web,
                          modelInfo,
                          nodeIndex: nextNodeIndex,
                          curTime,
                          ticksPerSec) != 0 )
  {
    BlendTree = idAnimator_AnimWeb::idModelAnimState::GetBlendTree(this, nodeIndex: curNodeIndex);
    v40 = (idMD6LeafPlay **)idAnimator_AnimWeb::idModelAnimState::GetBlendTree(this, nodeIndex: nextNodeIndex);
    if ( BlendTree != nullptr )
    {
      if ( v40 != nullptr )
      {
        v41 = BlendTree->tree;
        v42 = *v40;
        if ( tree == this->branches[0] || tree == this->branches[1] )
          v41 = tree;
        idAnimator_AnimWeb::idModelAnimState::SetDestFrame(
          this,
          node: *v40,
          bp,
          curTime,
          ticksPerSec,
          retLongestAnimLen: a28,
          retDestFrame: a30);
        if ( (__int16)blendParms_t::GetDurationMS(this: bp, a2: v45, a3: v44, a4: v43) <= 0 )
        {
          idMD6Branch::Init(
            this: v38,
            left: v41,
            right: v42,
            op: BOP_LERP,
            originBlend: (const idMD6Blend::originBlend_t)bp->parms.originBlend,
            startAlpha: 1.0,
            targetAlpha: 1.0,
            alphaRate: 0.0,
            filterGroup: (const md6WeightGroup_t)v46,
            blendType: (const idMD6Branch::blendType_t)0x82000000);
        }
        else
        {
          LODWORD(v49) = (__int16)blendParms_t::GetDurationMS(this: bp, a2: v48, a3: v47, a4: v46);
          idMD6Branch::Init(
            this: v38,
            left: v41,
            right: v42,
            op: BOP_LERP,
            originBlend: (const idMD6Blend::originBlend_t)bp->parms.originBlend,
            startAlpha: 0.0,
            targetAlpha: 1.0,
            alphaRate: (float)((float)1000.0 / (float)v49),
            filterGroup: (const md6WeightGroup_t)v49,
            blendType: (const idMD6Branch::blendType_t)(unsigned __int8)bp->parms.blendType);
        }
        this->tree = v38;
        this->blending = true;
      }
      else
      {
        this->tree = BlendTree->tree;
      }
    }
    else
    {
      this->tree = *v40;
    }
  }
}


// ========================================================================
// ?InternalShouldStartNextNode@idAnimator_AnimWeb@@MAA_NV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@0HHABVblendParms_t@@V?$idIndex@FW4invalidModelIndex_t@idDeclAnimWeb@@@@_NPAW4animWebEvent_t@@@Z
// EA  : 0x826D3888
// RVA : 0x006D3888
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::InternalShouldStartNextNode(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *curNodeIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nextNodeIndex,
        int curTime,
        int ticksPerSec,
        blendParms_t *bp,
        idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *modelIndex,
        const bool showWarnings,
        animWebEvent_t *outEventToSignal,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        _DWORD *a28)
{
  idDeclAnimWebNode *v34; // r20
  idDeclAnimWebNode *v35; // r21
  int v36; // r27
  const idAnimWebBlendTree *BlendTree; // r28
  idAnimWebBlendTree *v38; // r29
  const idMD6Anim *destAnim; // r26
  idMD6LeafPlay *LeafWithMatchingAnim; // r25
  idMD6LeafPlay *FirstLeaf; // r3
  int type; // r11
  char v43; // r11
  bool v44; // zf
  const idMD6Node *tree; // r4
  idMD6LeafPlay *v46; // r29
  idMD6LeafPlay *v47; // r3
  int v48; // r11
  char v49; // r11
  __int64 v50; // r9
  int v51; // r11
  int Frame; // r28
  idMD6LeafPlay *v53; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v54; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v55; // r28
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v56; // r27
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v57; // r26
  const char *v58; // r25
  idGameTimeManager *gameTimeManager; // r23
  idGameTimeManager *v60; // r3
  unsigned int v61; // r23
  unsigned int v62; // r21
  __int64 v63; // r20
  int v64; // r3
  signed int frameRate; // r29
  idMD6AnimData *animData; // r11
  int GameHz; // r3
  int v69; // r8
  const idMD6Anim *anim; // r11
  const idDeclAnimWeb *v71; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v72; // r29
  const char *v73; // r28
  const char *v74; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v75; // r4
  const char *v76; // r29
  const char *v77; // r5
  idMD6AnimData *v78; // r11
  int numFrames; // r11
  double v80; // fp0
  const idDeclAnimWeb *v81; // r3
  double v82; // fp31
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v83; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v84; // r28
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v85; // r27
  idGameTimeManager *v86; // r26
  const char *v87; // r25
  idGameTimeManager *v88; // r3
  unsigned int v89; // r26
  unsigned int v90; // r22
  __int64 v91; // r21
  int v92; // r3
  const idDeclAnimWeb *v93; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v94; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v95; // r28
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v96; // r27
  const char *v97; // r26
  idGameTimeManager *v98; // r25
  const char *v99; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v100; // r4
  const char *v101; // r29
  const char *SubWebName; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v103; // r4
  const char *v104; // r28
  const char *v105; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v106; // r4
  const char *v107; // r27
  const char *v108; // r30
  int v109; // r3
  const idDeclAnimWeb *v110; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v111; // r29
  const char *v112; // r28
  const char *v113; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v114; // r4
  const char *v115; // r29
  const char *v116; // r5
  const idDeclAnimWeb *decl; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *value; // r29
  const char *str; // r28
  const char *StateName; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v121; // r4
  const char *v122; // r29
  const char *v123; // r5
  int v124; // [sp+8h] [-218h]
  int v125; // [sp+Ch] [-214h]
  int v126; // [sp+10h] [-210h]
  int v127; // [sp+14h] [-20Ch]
  int v128; // [sp+18h] [-208h]
  int v129; // [sp+1Ch] [-204h]
  __int16 v130; // [sp+C0h] [-160h] BYREF
  __int16 v131; // [sp+C2h] [-15Eh] BYREF
  __int16 v132; // [sp+C4h] [-15Ch] BYREF
  __int64 v133; // [sp+C8h] [-158h] BYREF
  idStr v134; // [sp+D0h] [-150h] BYREF
  idStr v135; // [sp+F0h] [-130h] BYREF
  idStr v136; // [sp+110h] [-110h] BYREF
  idStr v137; // [sp+130h] [-F0h] BYREF
  idStr v138; // [sp+150h] [-D0h] BYREF
  idStr v139; // [sp+170h] [-B0h] BYREF

  if ( this->decl == nullptr )
    return 0;
  if ( a28 != nullptr )
    *a28 = -1;
  if ( (__int16)curNodeIndex == -1 )
    v34 = nullptr;
  else
    v34 = this->decl->nodes.list[(__int16)curNodeIndex];
  if ( (__int16)nextNodeIndex == -1 )
    v35 = nullptr;
  else
    v35 = this->decl->nodes.list[(__int16)nextNodeIndex];
  v36 = (__int16)modelIndex;
  HIDWORD(v133) = &this->modelAnimStates.list[(__int16)modelIndex];
  BlendTree = idAnimator_AnimWeb::idModelAnimState::GetBlendTree(
                this: (idAnimator_AnimWeb::idModelAnimState *)HIDWORD(v133),
                nodeIndex: curNodeIndex);
  v38 = (idAnimWebBlendTree *)idAnimator_AnimWeb::idModelAnimState::GetBlendTree(
                                this: (idAnimator_AnimWeb::idModelAnimState *)HIDWORD(v133),
                                nodeIndex: nextNodeIndex);
  if ( BlendTree == nullptr )
  {
    v138.len = 0;
    v138.baseBuffer[0] = 0;
    v138.allocedAndFlag = 20;
    v138.data = v138.baseBuffer;
    idDeclAnimWebNode::GetName(this: v34, web: this->decl, name: &v138);
    idLib::Error(
      fmt: "Warning: node '%s' in animWeb '%s' is missing cur blend tree for model '%s'.",
      v138.data,
      this->decl->name.str,
      this->decl->models.list[v36]->name.str);
  }
  if ( v38 == nullptr )
  {
    v139.len = 0;
    v139.baseBuffer[0] = 0;
    v139.allocedAndFlag = 20;
    v139.data = v139.baseBuffer;
    idDeclAnimWebNode::GetName(this: v35, web: this->decl, name: &v139);
    idLib::Error(
      fmt: "Warning: node '%s' in animWeb '%s' is missing next blend tree for model '%s'.",
      v139.data,
      this->decl->name.str,
      this->decl->models.list[v36]->name.str);
  }
  destAnim = bp->parms.destAnim;
  if ( bp->parms.srcAnim != nullptr )
  {
    LeafWithMatchingAnim = idAnimator_AnimWeb::FindLeafWithMatchingAnim(
                             this,
                             tree: BlendTree->tree,
                             curTime,
                             anim: bp->parms.srcAnim,
                             stillPlaying: false);
  }
  else
  {
    FirstLeaf = idAnimator_AnimWeb::FindFirstLeaf(this, tree: BlendTree->tree, curTime, stillPlaying: false);
    LeafWithMatchingAnim = FirstLeaf;
    if ( FirstLeaf == nullptr )
      goto LABEL_62;
    type = FirstLeaf->type;
    if ( type == 1 || (v44 = type != 2, v43 = 0, !v44) )
      v43 = 1;
    if ( v43 == 0 )
    {
LABEL_62:
      decl = this->decl;
      value = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v34->states.stateIndex[0].value;
      str = decl->name.str;
      StateName = idDeclAnimWeb::GetStateName(
                    this: decl,
                    index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v35->states.stateIndex[0].value);
      v121 = value;
      v122 = StateName;
      v123 = idDeclAnimWeb::GetStateName(this: this->decl, index: v121);
      idLib::Warning(
        fmt: "animWeb '%s': no explicit animations defined in blend from node '%s' to node '%s', but src node has no leaves.",
        str,
        v123,
        v122);
      return 0;
    }
  }
  idAnimWebBlendTree::CopyScalars(this: v38, web: this, curTime, ticksPerSec, fieldFlags: 3u);
  idTreeAnimator::UpdateTree(
    model: this->decl->models.list[v36]->model,
    timeMSec: curTime,
    ticksPerSec,
    node: v38->tree);
  tree = v38->tree;
  if ( destAnim != nullptr )
  {
    v46 = idAnimator_AnimWeb::FindLeafWithMatchingAnim(this, tree, curTime, anim: destAnim, stillPlaying: false);
  }
  else
  {
    v47 = idAnimator_AnimWeb::FindFirstLeaf(this, tree, curTime, stillPlaying: false);
    v46 = v47;
    if ( v47 == nullptr )
      goto LABEL_61;
    v48 = v47->type;
    if ( v48 == 1 || (v44 = v48 != 2, v49 = 0, !v44) )
      v49 = 1;
    if ( v49 == 0 )
    {
LABEL_61:
      v110 = this->decl;
      v111 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v34->states.stateIndex[0].value;
      v112 = v110->name.str;
      v113 = idDeclAnimWeb::GetStateName(
               this: v110,
               index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v35->states.stateIndex[0].value);
      v114 = v111;
      v115 = v113;
      v116 = idDeclAnimWeb::GetStateName(this: this->decl, index: v114);
      idLib::Warning(
        fmt: "animWeb '%s': no explicit animations defined in blend from node '%s' to node '%s', but dest node has no leaves.",
        v112,
        v116,
        v115);
      return 0;
    }
  }
  if ( LeafWithMatchingAnim != nullptr && v46 != nullptr )
  {
    blendParms_t::GetSourceFrames(this: bp, anim: LeafWithMatchingAnim->anim, firstFrame: &v130, lastFrame: &v131);
    v51 = LeafWithMatchingAnim->type;
    if ( v51 == 2 )
    {
      Frame = idMD6LeafPlay::GetFrame(
                this: LeafWithMatchingAnim,
                gameTime: curTime,
                ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz);
      if ( Frame >= v130 && Frame <= v131 )
      {
        blendParms_t::GetDestFrames(this: bp, anim: v46->anim, firstFrame: (__int16 *)&v133, duration_: &v132);
        v53 = LeafWithMatchingAnim;
        v54 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v35->states.stateIndex[0].value;
        v55 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v35->subWebIndex.value;
        v56 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v34->states.stateIndex[0].value;
        v57 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v34->subWebIndex.value;
        v58 = this->decl->name.str;
        gameTimeManager = this->gametimeManager.gameTimeManager;
        idMD6LeafPlay::GetFrame(
          this: v53,
          gameTime: curTime,
          ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz);
        idDeclAnimWeb::GetStateName(this: this->decl, index: v54);
        idDeclAnimWeb::GetSubWebName(this: this->decl, index: v55);
        idDeclAnimWeb::GetStateName(this: this->decl, index: v56);
        idDeclAnimWeb::GetSubWebName(this: this->decl, index: v57);
        v60 = gameTimeManager;
        v61 = v132;
        v62 = SHIWORD(v133);
        LODWORD(v63) = v131;
        HIDWORD(v63) = v130;
        v64 = idAccolade::Count(this: v60);
        idAnimator_AnimWeb::DebugPrint(
          this,
          fmt: "(%d) animweb '%s': found blend (sff:%d, slf:%d df:%d d:%d) from '%s/%s' to '%s/%s', curFrame %d at time %d\n",
          a3: __SPAIR64__(v64, (unsigned int)v58),
          a4: v63,
          a5: __SPAIR64__(v62, v61),
          a6: v124,
          a7: v125,
          a8: v126,
          a9: v127,
          a10: v128,
          a11: v129);
        return 1;
      }
      if ( a28 != nullptr )
      {
        frameRate = 30;
        animData = LeafWithMatchingAnim->anim->animData;
        if ( animData != nullptr )
          frameRate = animData->frameRate;
        GameHz = idGameTimeManager::GetGameHz(this: this->gametimeManager.gameTimeManager, type: GAMETIME_SCALED);
        v69 = v130 * GameHz;
        __twllei(frameRate, 0);
        __twllei(frameRate, 0);
        __twlgei(frameRate & ~(__ROL4__(v69, 1) - 1), 0xFFFFFFFF);
        __twlgei(frameRate & ~(__ROL4__(GameHz * Frame, 1) - 1), 0xFFFFFFFF);
        if ( GameHz * Frame / frameRate - v69 / frameRate == 1 )
          *a28 = 7;
      }
      if ( showWarnings && LeafWithMatchingAnim->wrapMode == 0 && Frame > v131 )
      {
        v136.allocedAndFlag = 20;
        v136.len = 0;
        v136.data = v136.baseBuffer;
        v136.baseBuffer[0] = 0;
        idDeclAnimWebNode::GetName(this: v34, web: this->decl, name: &v136);
        v137.allocedAndFlag = 20;
        v137.data = v137.baseBuffer;
        v137.len = 0;
        v137.baseBuffer[0] = 0;
        idDeclAnimWebNode::GetName(this: v35, web: this->decl, name: &v137);
        idLib::Warning(
          fmt: "animWeb '%s': clamped anim '%s' is at frame %d and already past the src blend window (%d,%d) to '%s'",
          this->decl->name.str,
          v136.data,
          Frame,
          v130,
          v131,
          v137.data);
        idStr::FreeData(this: &v137);
        idStr::FreeData(this: &v136);
      }
      anim = LeafWithMatchingAnim->anim;
      if ( anim != nullptr )
      {
        v78 = anim->animData;
        if ( LeafWithMatchingAnim->wrapMode == 1 )
        {
          if ( v78 != nullptr )
            numFrames = v78->numFrames - 1;
          else
            numFrames = -1;
        }
        else if ( v78 != nullptr )
        {
          numFrames = v78->numFrames;
        }
        else
        {
          numFrames = 0;
        }
        if ( v130 >= numFrames )
        {
          v135.allocedAndFlag = 20;
          v135.len = 0;
          v135.data = v135.baseBuffer;
          v135.baseBuffer[0] = 0;
          idDeclAnimWebNode::GetName(this: v34, web: this->decl, name: &v135);
          v134.allocedAndFlag = 20;
          v134.data = v134.baseBuffer;
          v134.len = 0;
          v134.baseBuffer[0] = 0;
          idDeclAnimWebNode::GetName(this: v35, web: this->decl, name: &v134);
          idLib::Warning(
            fmt: "animWeb '%s': blend from '%s' to '%s' is out of range",
            this->decl->name.str,
            v135.data,
            v134.data);
          if ( !idMD6LeafPlay::IsPlaying(
                  this: LeafWithMatchingAnim,
                  gameTime: curTime,
                  ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz) )
          {
            idStr::FreeData(this: &v134);
            idStr::FreeData(this: &v135);
            return 1;
          }
          idStr::FreeData(this: &v134);
          idStr::FreeData(this: &v135);
        }
      }
      else
      {
        v71 = this->decl;
        v72 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v34->states.stateIndex[0].value;
        v73 = v71->name.str;
        v74 = idDeclAnimWeb::GetStateName(
                this: v71,
                index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v35->states.stateIndex[0].value);
        v75 = v72;
        v76 = v74;
        v77 = idDeclAnimWeb::GetStateName(this: this->decl, index: v75);
        idLib::Warning(
          fmt: "animWeb '%s': trying to blend from '%s' to '%s', but source leaf has no animation.",
          v73,
          v77,
          v76);
      }
    }
    else if ( v51 == 1 )
    {
      v80 = *(float *)&LeafWithMatchingAnim[2].anim;
      LODWORD(v50) = v130;
      v133 = v50;
      if ( v80 >= (float)v50 )
      {
        LODWORD(v50) = v131;
        v133 = v50;
        if ( v80 <= (float)v50 )
        {
          blendParms_t::GetDestFrames(this: bp, anim: v46->anim, firstFrame: &v132, duration_: (__int16 *)&v133);
          v81 = this->decl;
          v82 = *(float *)&LeafWithMatchingAnim[2].anim;
          v83 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v35->subWebIndex.value;
          v84 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v34->states.stateIndex[0].value;
          v85 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v34->subWebIndex.value;
          v86 = this->gametimeManager.gameTimeManager;
          v87 = v81->name.str;
          idDeclAnimWeb::GetStateName(
            this: v81,
            index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v35->states.stateIndex[0].value);
          idDeclAnimWeb::GetSubWebName(this: this->decl, index: v83);
          idDeclAnimWeb::GetStateName(this: this->decl, index: v84);
          idDeclAnimWeb::GetSubWebName(this: this->decl, index: v85);
          v88 = v86;
          v89 = SHIWORD(v133);
          v90 = v132;
          LODWORD(v91) = v131;
          HIDWORD(v91) = v130;
          v92 = idAccolade::Count(this: v88);
          idAnimator_AnimWeb::DebugPrint(
            this,
            fmt: "(%d) animweb '%s': found blend (sff:%d, slf:%d df:%d d:%d) from '%s/%s' to '%s/%s', curFrame %f at time %d\n",
            a3: __SPAIR64__(v92, (unsigned int)v87),
            a4: v91,
            a5: __SPAIR64__(v90, v89),
            a6: v124,
            a7: v125,
            a8: v126,
            a9: v127,
            a10: v128,
            a11: v129,
            v82);
          return 1;
        }
      }
    }
  }
  else
  {
    v93 = this->decl;
    v94 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v35->subWebIndex.value;
    v95 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v34->states.stateIndex[0].value;
    v96 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v34->subWebIndex.value;
    v97 = v93->name.str;
    v98 = this->gametimeManager.gameTimeManager;
    v99 = idDeclAnimWeb::GetStateName(
            this: v93,
            index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v35->states.stateIndex[0].value);
    v100 = v94;
    v101 = v99;
    SubWebName = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v100);
    v103 = v95;
    v104 = SubWebName;
    v105 = idDeclAnimWeb::GetStateName(this: this->decl, index: v103);
    v106 = v96;
    v107 = v105;
    v108 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v106);
    v109 = idAccolade::Count(this: v98);
    idLib::Warning(
      fmt: "(%d) animweb '%s': could not find blend from '%s:%s' to '%s:%s', at time %d",
      v109,
      v97,
      v108,
      v107,
      v104,
      v101,
      curTime);
  }
  return 0;
}


// ========================================================================
// $LN401
// EA  : 0x826D4140
// RVA : 0x006D4140
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _LN401()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 336));
}


// ========================================================================
// __unwind$257930
// EA  : 0x826D4168
// RVA : 0x006D4168
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_257930()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 368));
}


// ========================================================================
// __unwind$257931
// EA  : 0x826D4190
// RVA : 0x006D4190
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_257931()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 272));
}


// ========================================================================
// __unwind$257932
// EA  : 0x826D41B8
// RVA : 0x006D41B8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_257932()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 304));
}


// ========================================================================
// __unwind$257933
// EA  : 0x826D41E0
// RVA : 0x006D41E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_257933()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 240));
}


// ========================================================================
// __unwind$257934
// EA  : 0x826D4208
// RVA : 0x006D4208
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_257934()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 208));
}


// ========================================================================
// ?InternalStartBlend@idAnimator_AnimWeb@@MAAXPBVidDeclAnimWebNode@@0H@Z
// EA  : 0x826D4230
// RVA : 0x006D4230
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

// attributes: thunk
void __fastcall idAnimator_AnimWeb::InternalStartBlend(
        idAnimator_AnimWeb *this,
        const idDeclAnimWebNode *curNode,
        const idDeclAnimWebNode *nextNode,
        const int curTime)
{
  idAnimator_AnimWeb::SelectRandomBlendVals(this, curNode, nextNode);
}


// ========================================================================
// ?GetNodeAnimLength@idAnimator_AnimWeb@@QBA_NHV?$idIndex@FW4invalidModelIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@AAUanimInfo_t@1@@Z
// EA  : 0x826D4238
// RVA : 0x006D4238
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

BOOL __fastcall idAnimator_AnimWeb::GetNodeAnimLength(
        idAnimator_AnimWeb *this,
        int curTime,
        const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *modelIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nodeIndex,
        idAnimator_AnimWeb::animInfo_t *animInfo)
{
  return idAnimator_AnimWeb::GetNodeAnimLength(
           this,
           curTime,
           modelIndex,
           nodeIndex,
           wrapMode: WRAP_MAX,
           ignoreAdditive: false,
           animInfo);
}


// ========================================================================
// ??0idModelAnimState@idAnimator_AnimWeb@@QAA@XZ
// EA  : 0x826D4248
// RVA : 0x006D4248
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

idAnimator_AnimWeb::idModelAnimState *__fastcall idAnimator_AnimWeb::idModelAnimState::idModelAnimState(
        idAnimator_AnimWeb::idModelAnimState *this)
{
  this->tree = nullptr;
  this->blendTreeCache.num = 0;
  this->blendTreeCache.list = this->blendTreeCache.staticList;
  this->blendTreeCache.granularity = 1;
  this->blendTreeCache.size = 8;
  this->blendTreeCache.memTag = 5;
  this->blendTreeCache.listStatic = 1;
  this->recentNodes[0].value = -1;
  this->recentNodes[1].value = -1;
  this->recentNodes[2].value = -1;
  this->blending = false;
  this->branches[0] = nullptr;
  this->branches[1] = nullptr;
  this->recentNodes[0].value = -1;
  this->recentNodes[1].value = -1;
  this->recentNodeStart = 0;
  return this;
}


// ========================================================================
// ?AllocBlendTree@idModelAnimState@idAnimator_AnimWeb@@QBAPAVidAnimWebBlendTree@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@0@Z
// EA  : 0x826D42B8
// RVA : 0x006D42B8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

idAnimWebBlendTree *__fastcall idAnimator_AnimWeb::idModelAnimState::AllocBlendTree(
        idAnimator_AnimWeb::idModelAnimState *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *forNodeIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *keepNodeIndex)
{
  int num; // r27
  int v6; // r21
  int v7; // r26
  int v8; // r20
  int v9; // r29
  idAnimWebBlendTree **list; // r23
  int v11; // r25
  idAnimWebBlendTree **v12; // r28
  idAnimWebBlendTree *v13; // r10
  __int16 v14; // r11
  int v15; // r3
  __int16 recentNodeStart; // r10
  char v17; // r4
  int v18; // r8
  idAnimWebBlendTree *v20; // r3
  idAnimWebBlendTree *v21; // r27
  idAnimWebBlendTree **v22; // r11
  idAnimWebBlendTree *v23; // r29
  idAnimWebBlendTree *v24; // [sp+50h] [-70h] BYREF

  num = this->blendTreeCache.num;
  v6 = -1;
  v7 = 0x7FFFFFFF;
  v8 = -1;
  v24 = (idAnimWebBlendTree *)num;
  v9 = 0;
  if ( num > 0 )
  {
    list = this->blendTreeCache.list;
    v11 = (__int16)forNodeIndex;
    v12 = list;
    do
    {
      v13 = *v12;
      HIWORD(v24) = (*v12)->nodeIndex.value;
      v14 = HIWORD(v24);
      if ( SHIWORD(v24) == v11 )
        v6 = v9;
      if ( SHIWORD(v24) != (__int16)keepNodeIndex )
      {
        v24 = (idAnimWebBlendTree *)v13->leaves.num;
        v15 = (int)v24;
        if ( (int)v24 < v7 )
        {
          recentNodeStart = this->recentNodeStart;
          v17 = 0;
          v18 = 0;
          HIWORD(v24) = v14;
          while ( this->recentNodes[(recentNodeStart + v18) % 3].value != v14 )
          {
            if ( ++v18 >= 3 )
              goto LABEL_12;
          }
          v17 = 1;
LABEL_12:
          if ( v17 == 0 )
          {
            v7 = v15;
            v8 = v9;
          }
        }
      }
      ++v9;
      ++v12;
    }
    while ( v9 < num );
    if ( v6 >= 0 )
      return list[v6];
  }
  v20 = (idAnimWebBlendTree *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x2Cu,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v24 = v20;
  if ( v20 != nullptr )
    v21 = idAnimWebBlendTree::idAnimWebBlendTree(this: v20, _nodeIndex: forNodeIndex);
  else
    v21 = nullptr;
  v24 = v21;
  if ( v21 == nullptr )
    return nullptr;
  if ( this->blendTreeCache.num == this->blendTreeCache.size )
  {
    v22 = this->blendTreeCache.list;
    v23 = v22[v8];
    if ( v23 != nullptr )
    {
      idAnimWebBlendTree::~idAnimWebBlendTree(this: v22[v8]);
      idMem::Free(this: &mem, ptr: v23, align: ALIGN_16);
    }
    this->blendTreeCache.list[v8] = v21;
  }
  else
  {
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->blendTreeCache,
      obj: (const encounterGroupRole_t *)&v24);
  }
  return v21;
}


// ========================================================================
// __unwind$258866
// EA  : 0x826D44A0
// RVA : 0x006D44A0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall _unwind_258866(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 192 + 80), tag: a2);
}


// ========================================================================
// ?AllocBlendTrees@idAnimator_AnimWeb@@IAAPAVidAnimWebBlendTree@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@0@Z
// EA  : 0x826D44D0
// RVA : 0x006D44D0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

idAnimWebBlendTree *__fastcall idAnimator_AnimWeb::AllocBlendTrees(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *forNodeIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *keepNodeIndex,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> a14)
{
  int v14; // r22
  idDeclAnimWebNode *v15; // r20
  const idDeclAnimWeb *decl; // r11
  idAnimWebBlendTree *v21; // r18
  int i; // r27
  const idDeclAnimWebNode::idModelInfo *ModelInfo; // r29
  idAnimator_AnimWeb::idModelAnimState *v24; // r28
  idAnimWebBlendTree *v25; // r3
  const idDeclAnimWebNode::idModelInfo *v26; // r8
  const char *str; // r7
  idDeclAnimWebNode *v28; // r29
  idStr v29[5]; // [sp+50h] [-A0h] BYREF

  decl = this->decl;
  a14.value = (__int16)forNodeIndex;
  if ( decl == nullptr )
    return nullptr;
  v21 = nullptr;
  if ( (__int16)forNodeIndex == -1 || (v14 = (__int16)forNodeIndex, (v15 = decl->nodes.list[v14]) == nullptr) )
    idLib::Error(fmt: "Node with index %d was not found in animweb '%s'", (__int16)forNodeIndex, decl->name.str);
  for ( i = 0; i < this->modelAnimStates.num; ++i )
  {
    ModelInfo = idDeclAnimWebNode::FindModelInfo(
                  this: v15,
                  modelIndex: (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)(__int16)i);
    if ( ModelInfo != nullptr )
    {
      v24 = &this->modelAnimStates.list[i];
      if ( idAnimator_AnimWeb::idModelAnimState::GetBlendTree(this: v24, nodeIndex: forNodeIndex) == nullptr )
      {
        v25 = idAnimator_AnimWeb::idModelAnimState::AllocBlendTree(this: v24, forNodeIndex, keepNodeIndex);
        if ( i == 0 )
          v21 = v25;
        v26 = ModelInfo;
        str = ModelInfo->blendEq.str;
        v28 = this->decl->nodes.list[v14];
        if ( !idAnimWebBlendTree::Init(
                this: v25,
                web: this,
                node: v28,
                modelIndex: (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)(__int16)i,
                blendEq: str,
                modelInfo: v26,
                ticksPerSec: 960) )
        {
          idAnimator_AnimWeb::idModelAnimState::FreeBlendTree(this: v24, forNodeIndex: &a14);
          v29[0].allocedAndFlag = 20;
          v29[0].data = v29[0].baseBuffer;
          v29[0].len = 0;
          v29[0].baseBuffer[0] = 0;
          idDeclAnimWebNode::GetName(this: v28, web: this->decl, name: v29);
          idLib::Warning(fmt: "Failed to initialize node '%s' in animWeb '%s'", v29[0].data, this->decl->name.str);
          idStr::FreeData(this: v29);
        }
      }
    }
  }
  return v21;
}


// ========================================================================
// $LN72
// EA  : 0x826D4654
// RVA : 0x006D4654
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _LN72()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// ?SetCurNode@idAnimator_AnimWeb@@QAAXV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@H@Z
// EA  : 0x826D4758
// RVA : 0x006D4758
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::SetCurNode(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nodeIndex,
        int curTime,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  int v8; // r27
  int num; // r11
  int v13; // r11
  bool v14; // zf
  int v15; // r10
  idAnimator_AnimWeb::idModelAnimState *v16; // r9
  int v17; // r29
  int value; // r11
  const idDeclAnimWebNode *v19; // r5
  idDeclAnimWebNode *v20; // r28
  double v21; // fp0
  int v22; // [sp+8h] [-88h]
  int v23; // [sp+Ch] [-84h]
  int v24; // [sp+10h] [-80h]
  int v25; // [sp+14h] [-7Ch]
  int v26; // [sp+18h] [-78h]
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *v27; // [sp+1Ch] [-74h]

  v8 = (__int16)nodeIndex;
  this->prevNodeIndex.value = -1;
  this->curEdgeNodeIndex.value = -1;
  this->curEdgeIndex = -1;
  if ( (__int16)nodeIndex >= 0 )
  {
    this->curNodeIndex.value = (__int16)nodeIndex;
    idAnimator_AnimWeb::AllocBlendTrees(
      this,
      forNodeIndex: nodeIndex,
      keepNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)0xFFFFFFFF,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9: v22,
      a10: v23,
      a11: v24,
      a12: v25,
      a13: v26,
      a14: v27);
    v17 = 0;
    value = this->curNodeIndex.value;
    if ( value == -1 )
      v19 = nullptr;
    else
      v19 = this->decl->nodes.list[value];
    this->InternalStartBlend(this, a2: nullptr, a3: v19, a4: curTime);
    idAnimator_AnimWeb::BeginNodesPlaying(this, nodeIndex, curTime);
    this->destStateIndices.numStates = 0;
    this->destSubWebIndex.value = -1;
    if ( v8 != -1 )
    {
      v20 = this->decl->nodes.list[v8];
      if ( v20 != nullptr )
      {
        if ( this->modelAnimStates.num > 0 )
        {
          do
            this->InternalSetAnimDelta(
              this,
              a2: (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)(__int16)v17++,
              a3: this->decl->nodes.list[v8]);
          while ( v17 < this->modelAnimStates.num );
        }
        if ( (v20->flags & 0x10) != 0 )
          v21 = 0.0;
        else
          v21 = 1.0;
        this->mergeBranch->targetAlpha = v21;
        this->mergeBranch->currentAlpha = v21;
      }
    }
    goto LABEL_17;
  }
  num = this->modelAnimStates.num;
  this->curNodeIndex.value = -1;
  this->destStateIndices.numStates = 0;
  this->destSubWebIndex.value = -1;
  v14 = num <= 0;
  v13 = 0;
  if ( v14 )
  {
LABEL_17:
    idAnimator_AnimWeb::CacheCurNode(this);
    return;
  }
  v15 = 0;
  do
  {
    ++v13;
    v16 = &this->modelAnimStates.list[v15++];
    v16->tree = nullptr;
    v16->blending = false;
  }
  while ( v13 < this->modelAnimStates.num );
  idAnimator_AnimWeb::CacheCurNode(this);
}


// ========================================================================
// ?SetCurNode@idAnimator_AnimWeb@@QAAXV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@H@Z
// EA  : 0x826D4900
// RVA : 0x006D4900
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::SetCurNode(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex,
        int curTime)
{
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r7
  int v10; // r6
  unsigned __int16 v11; // [sp+50h] [-20h] BYREF

  if ( this->decl != nullptr )
  {
    idDeclAnimWeb::FindNodeIndex(
      this: (idDeclAnimWeb *)&v11,
      result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this->decl,
      subWebIndex,
      stateIndex);
    idAnimator_AnimWeb::SetCurNode(
      this,
      nodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v11,
      curTime,
      a4: v10,
      a5: v9,
      a6: v8,
      a7: v7,
      a8: v6);
  }
}


// ========================================================================
// ?AddBlendVariable@idAnimator_AnimWeb@@QAAHPBDPAMW4fieldFlag_t@idAnimWebScalarPair@@@Z
// EA  : 0x826D4968
// RVA : 0x006D4968
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::AddBlendVariable(
        idAnimator_AnimWeb *this,
        const char *name,
        float *scalar,
        idAnimWebScalarPair::fieldFlag_t flags)
{
  int v8; // r31
  int v9; // r29
  idList<idAnimWebScalar,33> *p_scalars; // r31
  int num; // r11
  int size; // r10
  idAnimWebScalar *list; // r10
  idAnimWebScalar *v14; // r3
  idAnimWebScalar *v15; // r3
  char v16; // r11
  unsigned __int8 v17; // r11

  v8 = 0;
  if ( this->scalars.num <= 0 )
  {
LABEL_5:
    p_scalars = &this->scalars;
    idList<idAnimWebScalar,5>::PreAllocateWithGranularity(
      this: (idList<idAnimWebScalar,5> *)&this->scalars,
      newSize: this->scalars.num + 1);
    num = this->scalars.num;
    size = this->scalars.size;
    if ( num >= size )
    {
      v14 = &p_scalars->list[size - 1];
    }
    else
    {
      list = p_scalars->list;
      this->scalars.num = num + 1;
      v14 = &list[num];
    }
    idAnimWebScalar::Init(this: v14, name_: name, flags_: flags, scalar);
    return this->scalars.num - 1;
  }
  else
  {
    v9 = 0;
    while ( idStr::Cmp(s1: this->scalars.list[v9].name.str, s2: name) != 0 )
    {
      ++v8;
      ++v9;
      if ( v8 >= this->scalars.num )
        goto LABEL_5;
    }
    v15 = &this->scalars.list[v8];
    if ( (unsigned __int16)v15->scalarIndex < 0x8000u || (v16 = 0, v15->scalarPtr != nullptr) )
      v16 = 1;
    if ( v16 != 0 )
      idLib::Error(fmt: "idAnimator_AnimWeb::AddBlendVariable: %s already added", name);
    if ( flags != FF_NO_OVERRIDE )
      v17 = flags;
    else
      v17 = v15->flags;
    idAnimWebScalar::Init(this: v15, name_: name, flags_: v17, scalar);
    return v8;
  }
}


// ========================================================================
// ?InternalInitWeb@idAnimator_AnimWeb@@MAAXXZ
// EA  : 0x826D4AC0
// RVA : 0x006D4AC0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::InternalInitWeb(idAnimator_AnimWeb *this)
{
  int v2; // r26
  int v3; // r31
  int v4; // r30
  int num; // r11
  int size; // r10
  idAnimWebScalar *list; // r9
  idAnimWebScalar *v8; // r3
  idAnimWebScalar *v9; // r3
  char v10; // r11
  int v11; // r6
  const char *v12; // r5
  const char *v13; // r4
  idAnimator_AnimWeb *v14; // r3
  _DWORD v15[24]; // [sp+50h] [-60h] BYREF

  v15[1] = "_random2";
  v15[2] = "_random3";
  v15[3] = "_random4";
  v15[4] = "_random5";
  v15[5] = "_random6";
  v15[6] = "_random7";
  v15[7] = "_random8";
  v2 = 1;
  v15[0] = 0;
  while ( 1 )
  {
    if ( v2 != 1 )
    {
      idAnimator_AnimWeb::AddBlendVariable(
        this,
        name: (const char *)v15[v2],
        scalar: &this->randomBlendVals[v2],
        flags: FF_NO_OVERRIDE);
      goto LABEL_17;
    }
    v3 = 0;
    if ( this->scalars.num <= 0 )
    {
LABEL_7:
      idList<idAnimWebScalar,5>::PreAllocateWithGranularity(
        this: (idList<idAnimWebScalar,5> *)&this->scalars,
        newSize: this->scalars.num + 1);
      num = this->scalars.num;
      size = this->scalars.size;
      list = this->scalars.list;
      if ( num >= size )
      {
        v8 = &list[size - 1];
      }
      else
      {
        this->scalars.num = num + 1;
        v8 = &list[num];
      }
      idAnimWebScalar::Init(this: v8, name_: "_random2", flags_: 0, scalar: &this->randomBlendVals[1]);
      this->firstRandomScalarIndex = this->scalars.num - 1;
      goto LABEL_17;
    }
    v4 = 0;
    while ( idStr::Cmp(s1: this->scalars.list[v4].name.str, s2: "_random2") != 0 )
    {
      ++v3;
      ++v4;
      if ( v3 >= this->scalars.num )
        goto LABEL_7;
    }
    v9 = &this->scalars.list[v3];
    if ( (unsigned __int16)v9->scalarIndex < 0x8000u || (v10 = 0, v9->scalarPtr != nullptr) )
      v10 = 1;
    if ( v10 != 0 )
      break;
    idAnimWebScalar::Init(this: v9, name_: "_random2", flags_: v9->flags, scalar: &this->randomBlendVals[1]);
    this->firstRandomScalarIndex = v3;
LABEL_17:
    if ( ++v2 >= 8 )
      return;
  }
  idLib::Error(fmt: "idAnimator_AnimWeb::AddBlendVariable: %s already added", "_random2");
  idAnimator_AnimWeb::Reset(this: v14, initialSubWebName: v13, initialStateName: v12, curTime: v11);
}


// ========================================================================
// ?Reset@idAnimator_AnimWeb@@QAAXPBD0H@Z
// EA  : 0x826D4C90
// RVA : 0x006D4C90
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::Reset(
        idAnimator_AnimWeb *this,
        const char *initialSubWebName,
        const char *initialStateName,
        int curTime)
{
  int v7; // r10
  int v8; // r9
  int v9; // r8
  int v10; // r7
  int v11; // r6
  int v12; // r4
  int v13; // r5
  unsigned __int16 v14; // [sp+50h] [-30h] BYREF

  if ( this->decl != nullptr )
  {
    idDeclAnimWeb::GetNodeIndexForName(
      this: (idDeclAnimWeb *)&v14,
      result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->decl,
      subWebName: initialSubWebName,
      stateName: initialStateName);
    v12 = v14;
    if ( (v14 & 0x8000u) != 0 )
    {
      idLib::Warning(fmt: "(%s) Initial node '%s' does not exist!", this->decl->name.str, initialStateName);
      v12 = -1;
      v13 = 0;
    }
    else
    {
      v13 = curTime;
    }
    idAnimator_AnimWeb::SetCurNode(
      this,
      nodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v12,
      curTime: v13,
      a4: v11,
      a5: v10,
      a6: v9,
      a7: v8,
      a8: v7);
    this->eventHandler.ClearEvents(this: &this->eventHandler);
  }
}


// ========================================================================
// ?SetDecl@idModelAnimState@idAnimator_AnimWeb@@QAAXPBVidDeclAnimWeb@@PAV2@V?$idIndex@FW4invalidModelIndex_t@idDeclAnimWeb@@@@H@Z
// EA  : 0x826D4D30
// RVA : 0x006D4D30
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::idModelAnimState::SetDecl(
        idAnimator_AnimWeb::idModelAnimState *this,
        const idDeclAnimWeb *decl,
        idAnimator_AnimWeb *web,
        const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *modelIndex,
        const int ticksPerSec)
{
  unsigned __int64 v9; // r6
  const char *v10; // r7
  int i; // r30
  int v12; // r20
  int v13; // r21
  int value; // r11
  idDeclAnimWeb::idSubWebInfo *v15; // r26
  int v16; // r24
  int v17; // r25
  int v18; // r11
  idDeclAnimWebNode *v19; // r3
  const idDeclAnimWebNode::idModelInfo *ModelInfo; // r3
  idList<idMD6AnimProps,32> *p_animProps; // r29
  int v22; // r28
  int v23; // r30
  idMD6AnimProps *v24; // r11
  int v25; // r9
  int v26; // r25
  const idDeclMD6 *j; // r27
  idDeclAnimWebNode *v28; // r3
  const idDeclAnimWebNode::idModelInfo *v29; // r3
  idList<idMD6AnimProps,32> *v30; // r29
  int v31; // r28
  int v32; // r30
  idMD6AnimProps *v33; // r11
  int v34; // r9
  idPLog *pLog; // r29
  idPLog::logEntry_t *v36; // r30
  int v37; // r3
  __int64 totalTicks; // r11
  __int64 v39; // r9
  __int16 v40; // [sp+50h] [-90h] BYREF
  _WORD v41[3]; // [sp+52h] [-8Eh] BYREF
  idPLogScope v42; // [sp+58h] [-88h] BYREF

  RD_EventBegin(name: "idAnimator_AnimWeb::idModelAnimState::SetDeclWithLayers");
  LODWORD(v9) = "idAnimator_AnimWeb::idModelAnimState::SetDeclWithLayers";
  HIDWORD(v9) = 2;
  idPLogScope::idPLogScope(this: &v42, pl: &::pLog, gMask: v9, label: v10);
  idAnimator_AnimWeb::idModelAnimState::Free(this, web);
  for ( i = 2; i != 0; --i )
  {
    this = (idAnimator_AnimWeb::idModelAnimState *)((char *)this + 4);
    this->tree = web->md6Allocator->Alloc(this: web->md6Allocator, a2: 0);
  }
  if ( decl->layers.num != 0 )
  {
    v12 = 0;
    if ( web->initialActiveSubWebs.num > 0 )
    {
      v13 = 0;
      do
      {
        value = web->initialActiveSubWebs.list[v13].value;
        if ( value >= 0 && value < decl->subWebs.num )
        {
          v15 = &decl->subWebs.list[value];
          if ( v15 != nullptr )
          {
            v16 = 0;
            if ( v15->nodes.num > 0 )
            {
              v17 = 0;
              do
              {
                v18 = v15->nodes.list[v17].value;
                if ( v18 != -1 )
                {
                  v19 = decl->nodes.list[v18];
                  if ( v19 != nullptr )
                  {
                    ModelInfo = idDeclAnimWebNode::FindModelInfo(this: v19, modelIndex);
                    if ( ModelInfo != nullptr )
                    {
                      p_animProps = &ModelInfo->animProps;
                      v22 = 0;
                      if ( ModelInfo->animProps.num > 0 )
                      {
                        v23 = 0;
                        do
                        {
                          v24 = &p_animProps->list[v23];
                          *(_DWORD *)&v41[1] = v24;
                          v25 = v24->aliasHandle.value;
                          if ( v25 != 0xFFFF )
                          {
                            *(_DWORD *)&v41[1] = v24;
                            v40 = v25;
                            animation->StrongLoadAlias_2(
                              this: animation,
                              a2: web->modelDecls.list[(__int16)modelIndex],
                              a3: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)&v40);
                          }
                          ++v22;
                          ++v23;
                        }
                        while ( v22 < p_animProps->num );
                      }
                    }
                  }
                }
                ++v16;
                ++v17;
              }
              while ( v16 < v15->nodes.num );
            }
          }
        }
        ++v12;
        ++v13;
      }
      while ( v12 < web->initialActiveSubWebs.num );
    }
  }
  else
  {
    v26 = 0;
    for ( j = web->modelDecls.list[(__int16)modelIndex]; v26 < decl->nodes.num; ++v26 )
    {
      if ( (__int16)v26 != -1 )
      {
        v28 = decl->nodes.list[(__int16)v26];
        if ( v28 != nullptr )
        {
          v29 = idDeclAnimWebNode::FindModelInfo(this: v28, modelIndex);
          if ( v29 != nullptr )
          {
            v30 = &v29->animProps;
            v31 = 0;
            if ( v29->animProps.num > 0 )
            {
              v32 = 0;
              do
              {
                v33 = &v30->list[v32];
                *(_DWORD *)&v41[1] = v33;
                v34 = v33->aliasHandle.value;
                if ( v34 != 0xFFFF )
                {
                  *(_DWORD *)&v41[1] = v33;
                  v41[0] = v34;
                  animation->StrongLoadAlias_2(
                    this: animation,
                    a2: j,
                    a3: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)v41);
                }
                ++v31;
                ++v32;
              }
              while ( v31 < v30->num );
            }
          }
        }
      }
    }
  }
  if ( v42.logIndex >= 0 )
  {
    pLog = v42.pLog;
    v36 = &v42.pLog->logEntries.list[v42.logIndex];
    v37 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v36->totalTicks;
    HIDWORD(totalTicks) = v36->parent;
    LODWORD(v39) = v37 - totalTicks;
    v36->totalTicks = v39;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$259719
// EA  : 0x826D500C
// RVA : 0x006D500C
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_259719()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$259720
// EA  : 0x826D5034
// RVA : 0x006D5034
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_259720()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 88));
}


// ========================================================================
// ??0idAnimator_AnimWeb@@QAA@XZ
// EA  : 0x826D58F8
// RVA : 0x006D58F8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

idAnimator_AnimWeb *__fastcall idAnimator_AnimWeb::idAnimator_AnimWeb(idAnimator_AnimWeb *this)
{
  int v2; // ctr
  __int16 *v3; // r9
  char *p_flags; // r10
  int i; // ctr

  idAnimator_Base::idAnimator_Base(this);
  this->decl = nullptr;
  this->__vftable = (idAnimator_AnimWeb_vtbl *)&idAnimator_AnimWeb::`vftable';
  this->md6Allocator = nullptr;
  this->initialActiveSubWebs.list = nullptr;
  this->initialActiveSubWebs.granularity = 0;
  this->initialActiveSubWebs.memTag = 5;
  this->initialActiveSubWebs.listStatic = 0;
  this->initialActiveSubWebs.size = 0;
  this->initialActiveSubWebs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->initialActiveSubWebs);
  this->modelAnimStates.granularity = 0;
  this->modelAnimStates.memTag = 33;
  this->modelAnimStates.listStatic = 0;
  this->modelAnimStates.list = nullptr;
  this->modelAnimStates.size = 0;
  this->modelAnimStates.num = 0;
  this->curNodeIndex.value = -1;
  this->prevNodeIndex.value = -1;
  this->destSubWebIndex.value = -1;
  this->destStateIndices.stateIndex[0].value = -1;
  this->destStateIndices.stateIndex[1].value = -1;
  this->destStateIndices.stateIndex[2].value = -1;
  this->destStateIndices.stateIndex[3].value = -1;
  this->destStateIndices.numStates = 0;
  this->viaSubWebIndex.value = -1;
  this->viaStateIndices.stateIndex[0].value = -1;
  this->viaStateIndices.stateIndex[1].value = -1;
  this->viaStateIndices.stateIndex[2].value = -1;
  this->viaStateIndices.stateIndex[3].value = -1;
  this->viaStateIndices.numStates = 0;
  this->otherSubWebIndex.value = -1;
  this->curEdgeNodeIndex.value = -1;
  this->curEdgeIndex = -1;
  this->pathableSubWebNodeLists.size = 16;
  this->pathableSubWebNodeLists.num = 0;
  this->pathableSubWebNodeLists.granularity = 1;
  this->pathableSubWebNodeLists.list = this->pathableSubWebNodeLists.staticList;
  this->pathableSubWebNodeLists.memTag = 5;
  this->pathableSubWebNodeLists.listStatic = 1;
  this->pathIndex = -1;
  v2 = 32;
  v3 = &this->pathIndex + 1;
  do
  {
    *++v3 = -1;
    --v2;
  }
  while ( v2 != 0 );
  this->curPath.num = 0;
  this->curPath.cost = 0x7FFFFFFF;
  this->interruptPath = INTR_PATH_NO;
  this->interruptBlend = INTR_BLEND_NO;
  this->nodeStartTime = -1;
  this->prevNodeStartTime = -1;
  this->nodeStartFrame = 0;
  this->scalars.list = nullptr;
  this->scalars.granularity = 0;
  this->scalars.memTag = 33;
  this->scalars.listStatic = 0;
  this->scalars.size = 0;
  this->scalars.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scalars);
  this->scalarMem.floats = nullptr;
  this->scalarMem.num = 0;
  this->firstRandomScalarIndex = 0;
  this->blendEventMask = 0;
  this->declChangeId = -1;
  this->curNodeStateName.str = &byte_8200D768;
  this->curNodeSubWebName.str = &byte_8200D768;
  this->destNodeStateName.str = &byte_8200D768;
  this->destNodeSubWebName.str = &byte_8200D768;
  this->handle.value = -1;
  idAnimWebEventHandler_Zion::idAnimWebEventHandler_Zion(this: &this->eventHandler);
  this->clearEventsOnStateChanges = true;
  this->skipFlags = 2;
  this->requiredFlags = 0;
  this->forcedEdge.destNodeIndex.value = -1;
  this->forcedEdge.destSubWebIndex.value = -1;
  blendParms_t::blendParms_t(this: &this->forcedEdge.blendParms);
  this->mergeBranch = nullptr;
  idAnimator_ChannelWeight::idAnimator_ChannelWeight(this: &this->channelWeightAnimator);
  this->modelDecls.list = nullptr;
  this->modelDecls.granularity = 0;
  this->modelDecls.memTag = 33;
  this->modelDecls.listStatic = 0;
  this->modelDecls.size = 0;
  this->modelDecls.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->modelDecls);
  this->error = ANIMWEB_ERROR_NONE;
  this->debug = false;
  p_flags = &this->forcedEdge.blendParms.parms.flags;
  this->forceAnimDeltaModeOnBlendStart = false;
  this->skipForcedEdgeAutoPath = false;
  for ( i = 8; i != 0; --i )
  {
    p_flags += 4;
    *(_DWORD *)p_flags = 0;
  }
  memset(Dst: this->pathableSubWebNodeLists.list, Val: 0, Size: 4 * this->pathableSubWebNodeLists.size);
  return this;
}


// ========================================================================
// __unwind$260486
// EA  : 0x826D5BA0
// RVA : 0x006D5BA0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260486()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$260487
// EA  : 0x826D5BC8
// RVA : 0x006D5BC8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260487()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 48));
}


// ========================================================================
// __unwind$260488
// EA  : 0x826D5BF4
// RVA : 0x006D5BF4
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260488()
{
  int v0; // r12

  idList<idAnimator_AnimWeb::idModelAnimState,33>::Clear(this: (idList<idAnimator_AnimWeb::idModelAnimState,33> *)(*(_DWORD *)(v0 - 176 + 196) + 64));
}


// ========================================================================
// __unwind$260489
// EA  : 0x826D5C20
// RVA : 0x006D5C20
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260489()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 116));
}


// ========================================================================
// __unwind$260490
// EA  : 0x826D5C4C
// RVA : 0x006D5C4C
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260490()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 292));
}


// ========================================================================
// __unwind$260491
// EA  : 0x826D5C78
// RVA : 0x006D5C78
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260491()
{
  int v0; // r12

  idScalarMemBlock::~idScalarMemBlock(this: (idScalarMemBlock *)(*(_DWORD *)(v0 - 176 + 196) + 308));
}


// ========================================================================
// __unwind$260492
// EA  : 0x826D5CA4
// RVA : 0x006D5CA4
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260492()
{
  int v0; // r12

  idAnimator_ChannelWeight::~idAnimator_ChannelWeight(this: (idAnimator_ChannelWeight *)(*(_DWORD *)(v0 - 176 + 196)
                                                                                       + 524));
}


// ========================================================================
// ??1idAnimator_AnimWeb@@UAA@XZ
// EA  : 0x826D5CE0
// RVA : 0x006D5CE0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::~idAnimator_AnimWeb(idAnimator_AnimWeb *this)
{
  idAnimator_AnimWeb::idModelAnimState *list; // r3

  this->__vftable = (idAnimator_AnimWeb_vtbl *)&idAnimator_AnimWeb::`vftable';
  idAnimator_AnimWeb::Free(this);
  this->md6Allocator = nullptr;
  this->mergeBranch = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->modelDecls);
  idAnimator_ChannelWeight::~idAnimator_ChannelWeight(this: &this->channelWeightAnimator);
  idScalarMemBlock::Free(this: &this->scalarMem);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scalars);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pathableSubWebNodeLists);
  if ( this->modelAnimStates.listStatic == 0 || this->modelAnimStates.listStatic == 2 )
  {
    list = this->modelAnimStates.list;
    if ( list != nullptr )
      idListArrayDelete<idAnimator_AnimWeb::idModelAnimState>(ptr: list, num: this->modelAnimStates.size);
    this->modelAnimStates.list = nullptr;
    this->modelAnimStates.size = 0;
  }
  this->modelAnimStates.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->initialActiveSubWebs);
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// __unwind$260787
// EA  : 0x826D5D88
// RVA : 0x006D5D88
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260787()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$260788
// EA  : 0x826D5DB0
// RVA : 0x006D5DB0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260788()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 48));
}


// ========================================================================
// __unwind$260789
// EA  : 0x826D5DDC
// RVA : 0x006D5DDC
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260789()
{
  int v0; // r12

  idList<idAnimator_AnimWeb::idModelAnimState,33>::Clear(this: (idList<idAnimator_AnimWeb::idModelAnimState,33> *)(*(_DWORD *)(v0 - 112 + 132) + 64));
}


// ========================================================================
// __unwind$260790
// EA  : 0x826D5E08
// RVA : 0x006D5E08
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260790()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 116));
}


// ========================================================================
// __unwind$260791
// EA  : 0x826D5E34
// RVA : 0x006D5E34
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260791()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 292));
}


// ========================================================================
// __unwind$260792
// EA  : 0x826D5E60
// RVA : 0x006D5E60
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260792()
{
  int v0; // r12

  idScalarMemBlock::~idScalarMemBlock(this: (idScalarMemBlock *)(*(_DWORD *)(v0 - 112 + 132) + 308));
}


// ========================================================================
// __unwind$260793
// EA  : 0x826D5E8C
// RVA : 0x006D5E8C
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260793()
{
  int v0; // r12

  idAnimator_ChannelWeight::~idAnimator_ChannelWeight(this: (idAnimator_ChannelWeight *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                       + 524));
}


// ========================================================================
// __unwind$260794
// EA  : 0x826D5EB8
// RVA : 0x006D5EB8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260794()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 624));
}


// ========================================================================
// ?FindPath@idAnimator_AnimWeb@@QBA_NV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@2AAVidAnimWebRoute@@@Z
// EA  : 0x826D5EF0
// RVA : 0x006D5EF0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::FindPath(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *startNodeIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *destStateIndex_,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *destSubWebIndex_,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *otherSubWebIndex,
        idAnimWebRoute *path)
{
  idDeclAnimWebNode *v12; // r11
  unsigned __int64 v13; // r6
  const char *v14; // r7
  int v16; // r3
  idDeclAnimWebNode *v17; // r11
  int v18; // r29
  __int16 i; // r28
  const idDeclAnimWeb *decl; // r10
  int v21; // r10
  int skipFlags; // r28
  int requiredFlags; // r26
  int v24; // r12
  unsigned __int64 v25; // r6
  const char *v26; // r7
  int v27; // r29
  char ShortestPaths; // r26
  int v29; // r28
  idPLogScope v30; // r11
  __int64 v31; // r3
  double v32; // fp31
  idDeclAnimWebNode *v33; // r28
  const idDeclAnimWeb *v34; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *value; // r25
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v36; // r28
  const char *str; // r21
  const char *StateName; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v39; // r4
  const char *v40; // r20
  const char *SubWebName; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v42; // r4
  const char *v43; // r25
  const char *v44; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v45; // r4
  const char *v46; // r28
  const char *v47; // r3
  unsigned __int64 v48; // r6
  const char *v49; // r7
  int v50; // r26
  int v51; // r25
  int v52; // r28
  double v53; // fp31
  char *v54; // r29
  int v55; // r27
  int v56; // r29
  int *v57; // r28
  __int64 v58; // r10
  int v59; // r11
  idPLog *v60; // r29
  idPLog::logEntry_t *v61; // r30
  int v62; // r3
  __int64 v63; // r11
  __int64 v64; // r9
  idPLog *v65; // r29
  idPLog::logEntry_t *v66; // r30
  int v67; // r3
  __int64 v68; // r11
  __int64 v69; // r9
  idPLog *pLog; // r29
  idPLog::logEntry_t *v71; // r30
  int v72; // r3
  __int64 totalTicks; // r11
  __int64 v74; // r9
  idPLog *v75; // r29
  idPLog::logEntry_t *v76; // r30
  int v77; // r3
  __int64 v78; // r11
  __int64 v79; // r9
  int back_chain[8]; // [sp+0h] [-450h]
  double v81; // [sp+20h] [-430h]
  int v82; // [sp+28h] [-428h]
  int v83; // [sp+2Ch] [-424h]
  int v84; // [sp+30h] [-420h]
  int v85; // [sp+34h] [-41Ch]
  int v86; // [sp+38h] [-418h]
  int v87; // [sp+3Ch] [-414h]
  int v88; // [sp+40h] [-410h]
  int v89; // [sp+44h] [-40Ch]
  int v90; // [sp+48h] [-408h]
  int v91; // [sp+4Ch] [-404h]
  int v92; // [sp+50h] [-400h]
  idList<idVehicleState *,5> v93; // [sp+60h] [-3F0h] BYREF
  _BYTE v94[16]; // [sp+70h] [-3E0h] BYREF
  idPLogScope v95[38]; // [sp+80h] [-3D0h] BYREF
  _BYTE v96[524]; // [sp+1B4h] [-29Ch] BYREF

  if ( this->decl == nullptr )
    return 0;
  if ( anim_autoWebTrace.valueInteger != 0 )
  {
    v95[22].logIndex = 0;
    HIBYTE(v95[23].pLog) = 0;
    v95[23].logIndex = 20;
    v95[22].pLog = (idPLog *)&v95[23].pLog;
    v95[15].logIndex = 20;
    v95[14].pLog = (idPLog *)&v95[15].pLog;
    v95[14].logIndex = 0;
    HIBYTE(v95[15].pLog) = 0;
    v95[9].logIndex = 20;
    v95[8].pLog = (idPLog *)&v95[9].pLog;
    v95[8].logIndex = 0;
    HIBYTE(v95[9].pLog) = 0;
    idAnimWebPath::SplitPath(
      path: anim_sourcePath.valueString.data,
      webName: (idStr *)&v95[22],
      subWebName: (idStr *)&v95[14],
      stateName: (idStr *)&v95[8]);
    v95[19].logIndex = 20;
    v95[18].logIndex = 0;
    v95[18].pLog = (idPLog *)&v95[19].pLog;
    HIBYTE(v95[19].pLog) = 0;
    v95[27].logIndex = 20;
    v95[26].pLog = (idPLog *)&v95[27].pLog;
    v95[26].logIndex = 0;
    HIBYTE(v95[27].pLog) = 0;
    idAnimWebPath::SplitPath(
      path: anim_destPath.valueString.data,
      webName: (idStr *)&v95[22],
      subWebName: (idStr *)&v95[18],
      stateName: (idStr *)&v95[26]);
    idDeclAnimWeb::GetSubWebIndexForName(
      this: (idDeclAnimWeb *)&v95[2],
      result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->decl,
      subWebName: (const char *)v95[14].pLog);
    idDeclAnimWeb::GetStateIndexForName(
      this: (idDeclAnimWeb *)((char *)&v95[0].logIndex + 2),
      result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->decl,
      name: (const char *)v95[8].pLog);
    idDeclAnimWeb::GetSubWebIndexForName(
      this: (idDeclAnimWeb *)&v95[0].pLog,
      result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->decl,
      subWebName: (const char *)v95[18].pLog);
    idDeclAnimWeb::GetStateIndexForName(
      this: (idDeclAnimWeb *)v95,
      result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->decl,
      name: (const char *)v95[26].pLog);
    if ( (__int16)startNodeIndex == -1 )
      v12 = nullptr;
    else
      v12 = this->decl->nodes.list[(__int16)startNodeIndex];
    if ( v12->subWebIndex.value == SHIWORD(v95[2].logIndex)
      && v12->states.stateIndex[0].value == SLOWORD(v95[0].logIndex)
      && (__int16)destSubWebIndex_ == SHIWORD(v95[0].pLog)
      && (__int16)destStateIndex_ == SHIWORD(v95[0].logIndex) )
    {
      idCVar::SetBool(this: &anim_webTrace, newValue: true, force: true);
      idCVar::SetBool(this: &anim_autoWebTrace, newValue: false, force: true);
    }
    idStr::FreeData(this: (idStr *)&v95[26]);
    idStr::FreeData(this: (idStr *)&v95[18]);
    idStr::FreeData(this: (idStr *)&v95[8]);
    idStr::FreeData(this: (idStr *)&v95[14]);
    idStr::FreeData(this: (idStr *)&v95[22]);
  }
  RD_EventBegin(name: "idAnimator_AnimWeb::FindPath");
  LODWORD(v13) = "idAnimator_AnimWeb::FindPath";
  HIDWORD(v13) = 2;
  idPLogScope::idPLogScope(this: &v95[4], pl: &::pLog, gMask: v13, label: v14);
  memset(v94, 255, sizeof(v94));
  *(_QWORD *)&v93.num = 8;
  v93.list = (idVehicleState **)v94;
  *(_DWORD *)&v93.granularity = 66817;
  idDeclAnimWeb::FindNodeIndices(
    this: this->decl,
    subWebIndex: destSubWebIndex_,
    stateIndex: destStateIndex_,
    nodeIndices: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v93);
  if ( (__int16)startNodeIndex < 0 )
  {
    idList<idThread *,58>::Clear(this: &v93);
    idPLogScope::~idPLogScope(this: &v95[4]);
    RD_EventEnd();
    return 0;
  }
  v95[5].logIndex = -1;
  v16 = idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->pathableSubWebNodeLists, newNum: 0);
  if ( (__int16)startNodeIndex == -1 )
    v17 = nullptr;
  else
    v17 = this->decl->nodes.list[(__int16)startNodeIndex];
  v18 = 0;
  for ( i = v17->subWebIndex.value; v18 < this->decl->subWebs.num; ++v18 )
  {
    decl = this->decl;
    if ( (v18 & 0x8000u) != 0 || (__int16)v18 >= decl->subWebs.num )
      v21 = 0;
    else
      v21 = (int)&decl->subWebs.list[(__int16)v18];
    if ( *(_BYTE *)(v21 + 36) != 0
      || i == (__int16)v18
      || (__int16)destSubWebIndex_ == (__int16)v18
      || (__int16)otherSubWebIndex == (__int16)v18 )
    {
      v95[3].logIndex = v21;
      v16 = idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&this->pathableSubWebNodeLists,
              obj: (const encounterGroupRole_t *)&v95[3]);
    }
  }
  skipFlags = this->skipFlags;
  requiredFlags = this->requiredFlags;
  this->skipFlags = 0;
  this->requiredFlags = 0;
  ((void (__fastcall *)(int))RtlCheckStack12)(a1: v16);
  *(int *)((char *)back_chain + v24) = back_chain[0];
  RD_EventBegin(name: "idDijkstra::FindShortestPaths");
  LODWORD(v25) = "idDijkstra::FindShortestPaths";
  HIDWORD(v25) = 2;
  idPLogScope::idPLogScope(this: &v95[1], pl: &::pLog, gMask: v25, label: v26);
  v27 = (unsigned __int64)Sys_GetClockTicks() >> 32;
  ShortestPaths = idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute>::FindShortestPaths(
                    this: (idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute> *)&v95[5],
                    nodeHolder: this,
                    startNode: startNodeIndex,
                    destNodes: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v93.list,
                    numDestNodes: v93.num,
                    edges: this->decl->edgeCache.list,
                    scratchBuff: (djScratch_t *)&v93,
                    skipFlags,
                    requiredFlags: back_chain[2],
                    a10: back_chain[3],
                    a11: back_chain[4],
                    a12: back_chain[5],
                    a13: back_chain[6],
                    a14: back_chain[7],
                    a15: SHIDWORD(v81),
                    a16: SLODWORD(v81),
                    a17: v82,
                    a18: v83,
                    a19: v84,
                    a20: v85,
                    a21: v86,
                    a22: v87,
                    a23: v88,
                    a24: v89,
                    a25: v90,
                    a26: v91,
                    a27: v92,
                    a28: requiredFlags);
  v29 = (unsigned __int64)Sys_GetClockTicks() >> 32;
  if ( anim_webTrace.valueInteger != 0 )
    idCVar::SetBool(this: &anim_webTrace, newValue: false, force: true);
  v30.pLog = (idPLog *)(v29 - v27);
  v95[3] = v30;
  LODWORD(v31) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
  v95[6] = (idPLogScope)v31;
  v32 = (float)((float)(__int64)v95[3] / (float)((float)v31 * (float)0.001));
  if ( v32 > anim_webTimeThreshold.valueFloat )
  {
    if ( (__int16)startNodeIndex == -1 )
      v33 = nullptr;
    else
      v33 = this->decl->nodes.list[(__int16)startNodeIndex];
    if ( (__int16)otherSubWebIndex >= 0 )
      idDeclAnimWeb::GetSubWebName(this: this->decl, index: otherSubWebIndex);
    v34 = this->decl;
    value = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v33->states.stateIndex[0].value;
    v36 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v33->subWebIndex.value;
    str = v34->name.str;
    StateName = idDeclAnimWeb::GetStateName(this: v34, index: destStateIndex_);
    v39 = destSubWebIndex_;
    v40 = StateName;
    SubWebName = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v39);
    v42 = value;
    v43 = SubWebName;
    v44 = idDeclAnimWeb::GetStateName(this: this->decl, index: v42);
    v45 = v36;
    v46 = v44;
    v47 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v45);
    v81 = v32;
    idLib::Printf(
      fmt: "animWeb '%s' - slow path (%.8f ms) from '%s:%s' to '%s:%s' other '%s'\n",
      str,
      v32,
      (const char *)LODWORD(v32),
      v47,
      v46,
      v43,
      v40);
  }
  if ( ShortestPaths != 0 )
  {
    idPLogScope::~idPLogScope(this: &v95[1]);
    RD_EventEnd();
    RD_EventBegin(name: "idAnimator_AnimWeb::FindPath - TracePaths");
    LODWORD(v48) = "idAnimator_AnimWeb::FindPath - TracePaths";
    HIDWORD(v48) = 2;
    idPLogScope::idPLogScope(this: &v95[1], pl: &::pLog, gMask: v48, label: v49);
    v50 = -1;
    v51 = 0;
    v52 = 7;
    v53 = 3.4028235e38;
    v54 = v96;
    do
    {
      `vector constructor iterator'(
        __t: v54 - 68,
        __s: 2u,
        __n: 32,
        __f: (void *(__fastcall *)(void *))idAnimator_TrackerBase::GetReferenceJointOverride);
      *((_DWORD *)v54 - 1) = 0;
      *(_DWORD *)v54 = 0x7FFFFFFF;
      --v52;
      v54 += 72;
    }
    while ( v52 >= 0 );
    v55 = 0;
    if ( v93.num <= 0 )
      goto LABEL_50;
    v56 = 0;
    v57 = (int *)v96;
    do
    {
      v95[3].logIndex = (int)v93.list + v56;
      HIDWORD(v58) = (unsigned __int8)idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute>::TracePath(
                                        this: (idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute> *)&v95[5],
                                        nodeHolder: this,
                                        startNode: startNodeIndex,
                                        destNode: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)*(unsigned __int16 *)((char *)v93.list + v56),
                                        scratchBuff: (const djScratch_t *)&v93,
                                        path: (idAnimWebRoute *)(v57 - 17));
      if ( HIDWORD(v58) != 0 )
      {
        v59 = *v57;
        v95[3].logIndex = *v57;
        LODWORD(v58) = v95[3].logIndex;
        v95[6] = (idPLogScope)v58;
        if ( (float)v58 < v53 )
        {
          LODWORD(v58) = v59;
          v95[3].logIndex = v59;
          v50 = v51;
          v95[12] = (idPLogScope)v58;
          v53 = (float)v58;
        }
        ++v51;
        v57 += 18;
      }
      ++v55;
      v56 += 2;
    }
    while ( v55 < v93.num );
    if ( v50 >= 0 )
    {
      idAnimWebRoute::AppendPath(this: path, other: (const idAnimWebRoute *)&v95[9 * v50 + 30]);
      if ( v95[1].logIndex >= 0 )
      {
        pLog = v95[1].pLog;
        v71 = &v95[1].pLog->logEntries.list[v95[1].logIndex];
        v72 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        totalTicks = v71->totalTicks;
        HIDWORD(totalTicks) = v71->parent;
        LODWORD(v74) = v72 - totalTicks;
        v71->totalTicks = v74;
        pLog->lastEntry = HIDWORD(totalTicks);
      }
      RD_EventEnd();
      if ( v93.listStatic == 0 || v93.listStatic == 2 )
      {
        if ( v93.list != nullptr )
          idMem::Free(this: &mem, ptr: v93.list, align: ALIGN_16);
        v93.list = nullptr;
        v93.size = 0;
      }
      v93.num = 0;
      if ( v95[4].logIndex >= 0 )
      {
        v75 = v95[4].pLog;
        v76 = &v95[4].pLog->logEntries.list[v95[4].logIndex];
        v77 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v78 = v76->totalTicks;
        HIDWORD(v78) = v76->parent;
        LODWORD(v79) = v77 - v78;
        v76->totalTicks = v79;
        v75->lastEntry = HIDWORD(v78);
      }
      RD_EventEnd();
      return 1;
    }
    else
    {
LABEL_50:
      if ( v95[1].logIndex >= 0 )
      {
        v60 = v95[1].pLog;
        v61 = &v95[1].pLog->logEntries.list[v95[1].logIndex];
        v62 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v63 = v61->totalTicks;
        HIDWORD(v63) = v61->parent;
        LODWORD(v64) = v62 - v63;
        v61->totalTicks = v64;
        v60->lastEntry = HIDWORD(v63);
      }
      RD_EventEnd();
      if ( v93.listStatic == 0 || v93.listStatic == 2 )
      {
        if ( v93.list != nullptr )
          idMem::Free(this: &mem, ptr: v93.list, align: ALIGN_16);
        v93.list = nullptr;
        v93.size = 0;
      }
      v93.num = 0;
      if ( v95[4].logIndex >= 0 )
      {
        v65 = v95[4].pLog;
        v66 = &v95[4].pLog->logEntries.list[v95[4].logIndex];
        v67 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v68 = v66->totalTicks;
        HIDWORD(v68) = v66->parent;
        LODWORD(v69) = v67 - v68;
        v66->totalTicks = v69;
        v65->lastEntry = HIDWORD(v68);
      }
      RD_EventEnd();
      return 0;
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v95[1]);
    RD_EventEnd();
    idList<idThread *,58>::Clear(this: &v93);
    idPLogScope::~idPLogScope(this: &v95[4]);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$260898
// EA  : 0x826D6728
// RVA : 0x006D6728
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260898()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1104 + 304));
}


// ========================================================================
// __unwind$260899
// EA  : 0x826D6750
// RVA : 0x006D6750
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260899()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1104 + 240));
}


// ========================================================================
// __unwind$260900
// EA  : 0x826D6778
// RVA : 0x006D6778
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260900()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1104 + 192));
}


// ========================================================================
// __unwind$260901
// EA  : 0x826D67A0
// RVA : 0x006D67A0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260901()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1104 + 272));
}


// ========================================================================
// __unwind$260902
// EA  : 0x826D67C8
// RVA : 0x006D67C8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260902()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1104 + 336));
}


// ========================================================================
// __unwind$260903
// EA  : 0x826D67F0
// RVA : 0x006D67F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260903()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1104 + 944));
}


// ========================================================================
// __unwind$260904
// EA  : 0x826D6818
// RVA : 0x006D6818
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260904()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1104 + 160));
}


// ========================================================================
// __unwind$260905
// EA  : 0x826D6840
// RVA : 0x006D6840
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260905()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1104 + 96));
}


// ========================================================================
// __unwind$260906
// EA  : 0x826D6868
// RVA : 0x006D6868
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260906()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1104 + 945));
}


// ========================================================================
// __unwind$260907
// EA  : 0x826D6890
// RVA : 0x006D6890
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260907()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1104 + 136));
}


// ========================================================================
// __unwind$260908
// EA  : 0x826D68B8
// RVA : 0x006D68B8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260908()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1104 + 946));
}


// ========================================================================
// __unwind$260909
// EA  : 0x826D68E0
// RVA : 0x006D68E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_260909()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1104 + 136));
}


// ========================================================================
// ?FindPath@idAnimator_AnimWeb@@QBA_NV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@ABVstateList_t@idDeclAnimWeb@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@2AAVidAnimWebRoute@@@Z
// EA  : 0x826D6910
// RVA : 0x006D6910
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::FindPath(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *startNodeIndex,
        const idDeclAnimWeb::stateList_t *destStateIndices_,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *destSubWebIndex_,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *otherSubWebIndex,
        idAnimWebRoute *path)
{
  idDeclAnimWebNode *v12; // r11
  unsigned __int64 v13; // r6
  const char *v14; // r7
  int v15; // r24
  int v16; // r3
  idDeclAnimWebNode *v17; // r11
  int v18; // r29
  __int16 i; // r27
  const idDeclAnimWeb *decl; // r10
  int v21; // r10
  unsigned __int8 skipFlags; // r28
  unsigned __int8 requiredFlags; // r27
  int v24; // r12
  int v25; // r25
  __int64 v26; // r3
  int v27; // r29
  char ShortestPaths; // r27
  int v29; // r28
  idPLogScope v30; // r11
  __int64 v31; // r3
  double v32; // fp31
  idDeclAnimWebNode *v33; // r11
  const idDeclAnimWeb *v34; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *value; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v36; // r28
  const char *str; // r21
  const char *StateName; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v39; // r4
  const char *v40; // r18
  const char *SubWebName; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v42; // r4
  const char *v43; // r29
  const char *v44; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v45; // r4
  const char *v46; // r28
  const char *v47; // r3
  idPLog::logEntry_t *v48; // r30
  int v49; // r3
  int parent; // r11
  __int64 v51; // r9
  idPLog *pLog; // r29
  idPLog::logEntry_t *v53; // r30
  int v54; // r3
  __int64 totalTicks; // r11
  __int64 v56; // r9
  idPLog::logEntry_t *v58; // r29
  int v59; // r3
  int v60; // r11
  __int64 v61; // r9
  unsigned __int64 v62; // r6
  const char *v63; // r7
  int v64; // r26
  int v65; // r28
  char *v66; // r29
  double v67; // fp31
  int v68; // r27
  int v69; // r29
  int *v70; // r28
  __int64 v71; // r10
  int v72; // r11
  idPLog *v73; // r29
  idPLog::logEntry_t *v74; // r30
  int v75; // r3
  __int64 v76; // r11
  __int64 v77; // r9
  idPLog *v78; // r29
  idPLog::logEntry_t *v79; // r30
  int v80; // r3
  __int64 v81; // r11
  __int64 v82; // r9
  idPLog *v83; // r29
  idPLog::logEntry_t *v84; // r30
  int v85; // r3
  __int64 v86; // r11
  __int64 v87; // r9
  idPLog *v88; // r29
  idPLog::logEntry_t *v89; // r30
  int v90; // r3
  __int64 v91; // r11
  __int64 v92; // r9
  int back_chain[8]; // [sp+0h] [-460h]
  double v94; // [sp+20h] [-440h]
  int v95; // [sp+28h] [-438h]
  int v96; // [sp+2Ch] [-434h]
  int v97; // [sp+30h] [-430h]
  int v98; // [sp+34h] [-42Ch]
  int v99; // [sp+38h] [-428h]
  int v100; // [sp+3Ch] [-424h]
  int v101; // [sp+40h] [-420h]
  int v102; // [sp+44h] [-41Ch]
  int v103; // [sp+48h] [-418h]
  int v104; // [sp+4Ch] [-414h]
  int v105; // [sp+50h] [-410h]
  _QWORD v106[2]; // [sp+60h] [-400h] BYREF
  idList<idIndex<short,enum invalidUserChannelIndex_t>,5> v107; // [sp+70h] [-3F0h] BYREF
  _BYTE v108[16]; // [sp+80h] [-3E0h] BYREF
  idPLogScope v109[36]; // [sp+90h] [-3D0h] BYREF
  _BYTE v110[524]; // [sp+1B4h] [-2ACh] BYREF

  if ( this->decl == nullptr )
    return 0;
  if ( anim_autoWebTrace.valueInteger != 0 )
  {
    v109[20].logIndex = 0;
    HIBYTE(v109[21].pLog) = 0;
    v109[21].logIndex = 20;
    v109[20].pLog = (idPLog *)&v109[21].pLog;
    v109[13].logIndex = 20;
    v109[12].pLog = (idPLog *)&v109[13].pLog;
    v109[12].logIndex = 0;
    HIBYTE(v109[13].pLog) = 0;
    v109[7].logIndex = 20;
    v109[6].pLog = (idPLog *)&v109[7].pLog;
    v109[6].logIndex = 0;
    HIBYTE(v109[7].pLog) = 0;
    idAnimWebPath::SplitPath(
      path: anim_sourcePath.valueString.data,
      webName: (idStr *)&v109[20],
      subWebName: (idStr *)&v109[12],
      stateName: (idStr *)&v109[6]);
    v109[17].logIndex = 20;
    v109[16].logIndex = 0;
    v109[16].pLog = (idPLog *)&v109[17].pLog;
    HIBYTE(v109[17].pLog) = 0;
    v109[25].logIndex = 20;
    v109[24].pLog = (idPLog *)&v109[25].pLog;
    v109[24].logIndex = 0;
    HIBYTE(v109[25].pLog) = 0;
    idAnimWebPath::SplitPath(
      path: anim_destPath.valueString.data,
      webName: (idStr *)&v109[20],
      subWebName: (idStr *)&v109[16],
      stateName: (idStr *)&v109[24]);
    idDeclAnimWeb::GetSubWebIndexForName(
      this: (idDeclAnimWeb *)((char *)&v109[1].logIndex + 2),
      result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->decl,
      subWebName: (const char *)v109[12].pLog);
    idDeclAnimWeb::GetStateIndexForName(
      this: (idDeclAnimWeb *)&v109[1],
      result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->decl,
      name: (const char *)v109[6].pLog);
    idDeclAnimWeb::GetSubWebIndexForName(
      this: (idDeclAnimWeb *)&v109[0].pLog,
      result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->decl,
      subWebName: (const char *)v109[16].pLog);
    idDeclAnimWeb::GetStateIndexForName(
      this: (idDeclAnimWeb *)((char *)&v109[0].pLog + 2),
      result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->decl,
      name: (const char *)v109[24].pLog);
    if ( (__int16)startNodeIndex == -1 )
      v12 = nullptr;
    else
      v12 = this->decl->nodes.list[(__int16)startNodeIndex];
    if ( v12->subWebIndex.value == SLOWORD(v109[1].logIndex)
      && v12->states.stateIndex[0].value == SHIWORD(v109[1].logIndex)
      && (__int16)destSubWebIndex_ == SHIWORD(v109[0].pLog)
      && destStateIndices_->stateIndex[0].value == SLOWORD(v109[0].pLog) )
    {
      idCVar::SetBool(this: &anim_webTrace, newValue: true, force: true);
      idCVar::SetBool(this: &anim_autoWebTrace, newValue: false, force: true);
    }
    idStr::FreeData(this: (idStr *)&v109[24]);
    idStr::FreeData(this: (idStr *)&v109[16]);
    idStr::FreeData(this: (idStr *)&v109[6]);
    idStr::FreeData(this: (idStr *)&v109[12]);
    idStr::FreeData(this: (idStr *)&v109[20]);
  }
  RD_EventBegin(name: "idAnimator_AnimWeb::FindPath2");
  LODWORD(v13) = "idAnimator_AnimWeb::FindPath2";
  HIDWORD(v13) = 2;
  idPLogScope::idPLogScope(this: &v109[3], pl: &::pLog, gMask: v13, label: v14);
  v15 = -1;
  memset(v108, 255, sizeof(v108));
  *(_QWORD *)&v107.num = 8;
  v107.list = (idIndex<short,enum invalidUserChannelIndex_t> *)v108;
  *(_DWORD *)&v107.granularity = 66817;
  idDeclAnimWeb::FindNodeIndices(
    this: (idDeclAnimWeb *)v109,
    result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this->decl,
    subWebIndex: destSubWebIndex_,
    stateIndices: destStateIndices_,
    nodeIndices: &v107);
  v109[0].logIndex = -1;
  v16 = idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->pathableSubWebNodeLists, newNum: 0);
  if ( (__int16)startNodeIndex == -1 )
    v17 = nullptr;
  else
    v17 = this->decl->nodes.list[(__int16)startNodeIndex];
  v18 = 0;
  for ( i = v17->subWebIndex.value; v18 < this->decl->subWebs.num; ++v18 )
  {
    decl = this->decl;
    if ( (v18 & 0x8000u) != 0 || (__int16)v18 >= decl->subWebs.num )
      v21 = 0;
    else
      v21 = (int)&decl->subWebs.list[(__int16)v18];
    if ( *(_BYTE *)(v21 + 36) != 0
      || i == (__int16)v18
      || (__int16)destSubWebIndex_ == (__int16)v18
      || (__int16)otherSubWebIndex == (__int16)v18 )
    {
      HIDWORD(v106[0]) = v21;
      v16 = idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&this->pathableSubWebNodeLists,
              obj: (const encounterGroupRole_t *)v106);
    }
  }
  skipFlags = this->skipFlags;
  requiredFlags = this->requiredFlags;
  this->skipFlags = 0;
  this->requiredFlags = 0;
  ((void (__fastcall *)(int))RtlCheckStack12)(a1: v16);
  *(int *)((char *)back_chain + v24) = back_chain[0];
  RD_EventBegin(name: "idAnimator_AnimWeb::FindPath2 - find path");
  v25 = -1;
  v109[2].pLog = &::pLog;
  v109[2].logIndex = -1;
  if ( (::pLog.groupMask & 2) != 0 )
  {
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    HIDWORD(v106[0]) = idList<idPLog::logEntry_t,44>::Alloc(this: &::pLog.logEntries);
    idMem::PopHeap(this: &mem);
    *(_DWORD *)HIDWORD(v106[0]) = "idAnimator_AnimWeb::FindPath2 - find path";
    *(_DWORD *)(HIDWORD(v106[0]) + 4) = ::pLog.lastEntry;
    v25 = ::pLog.logEntries.num - 1;
    ::pLog.lastEntry = ::pLog.logEntries.num - 1;
    v109[2].logIndex = ::pLog.logEntries.num - 1;
    LODWORD(v26) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    *(_QWORD *)(HIDWORD(v106[0]) + 8) = v26;
  }
  v27 = (unsigned __int64)Sys_GetClockTicks() >> 32;
  ShortestPaths = idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute>::FindShortestPaths(
                    this: (idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute> *)v109,
                    nodeHolder: this,
                    startNode: startNodeIndex,
                    destNodes: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v107.list,
                    numDestNodes: v107.num,
                    edges: this->decl->edgeCache.list,
                    scratchBuff: (djScratch_t *)v106,
                    skipFlags,
                    requiredFlags: back_chain[2],
                    a10: back_chain[3],
                    a11: back_chain[4],
                    a12: back_chain[5],
                    a13: back_chain[6],
                    a14: back_chain[7],
                    a15: SHIDWORD(v94),
                    a16: SLODWORD(v94),
                    a17: v95,
                    a18: v96,
                    a19: v97,
                    a20: v98,
                    a21: v99,
                    a22: v100,
                    a23: v101,
                    a24: v102,
                    a25: v103,
                    a26: v104,
                    a27: v105,
                    a28: requiredFlags);
  v29 = (unsigned __int64)Sys_GetClockTicks() >> 32;
  if ( anim_webTrace.valueInteger != 0 )
    idCVar::SetBool(this: &anim_webTrace, newValue: false, force: true);
  v30.pLog = (idPLog *)(v29 - v27);
  v109[4] = v30;
  LODWORD(v31) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
  v106[0] = v31;
  v32 = (float)((float)(__int64)v109[4] / (float)((float)v31 * (float)0.001));
  if ( v32 > anim_webTimeThreshold.valueFloat )
  {
    if ( (__int16)startNodeIndex == -1 )
      v33 = nullptr;
    else
      v33 = this->decl->nodes.list[(__int16)startNodeIndex];
    v34 = this->decl;
    value = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v33->states.stateIndex[0].value;
    v36 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v33->subWebIndex.value;
    str = v34->name.str;
    idDeclAnimWeb::GetSubWebName(this: v34, index: otherSubWebIndex);
    StateName = idDeclAnimWeb::GetStateName(
                  this: this->decl,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)destStateIndices_->stateIndex[0].value);
    v39 = destSubWebIndex_;
    v40 = StateName;
    SubWebName = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v39);
    v42 = value;
    v43 = SubWebName;
    v44 = idDeclAnimWeb::GetStateName(this: this->decl, index: v42);
    v45 = v36;
    v46 = v44;
    v47 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v45);
    v94 = v32;
    idLib::Printf(
      fmt: "animWeb '%s' - slow path (%.8f ms) from '%s:%s' to '%s:%s' other '%s'\n",
      str,
      v32,
      (const char *)LODWORD(v32),
      v47,
      v46,
      v43,
      v40);
  }
  if ( ShortestPaths == 0 )
  {
    if ( v25 >= 0 )
    {
      v48 = &::pLog.logEntries.list[v25];
      v49 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      parent = v48->parent;
      LODWORD(v51) = v49 - LODWORD(v48->totalTicks);
      v48->totalTicks = v51;
      ::pLog.lastEntry = parent;
    }
    RD_EventEnd();
    if ( v107.listStatic == 0 || v107.listStatic == 2 )
    {
      if ( v107.list != nullptr )
        idMem::Free(this: &mem, ptr: v107.list, align: ALIGN_16);
      v107.list = nullptr;
      v107.size = 0;
    }
    v107.num = 0;
    if ( v109[3].logIndex >= 0 )
    {
      pLog = v109[3].pLog;
      v53 = &v109[3].pLog->logEntries.list[v109[3].logIndex];
      v54 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v53->totalTicks;
      HIDWORD(totalTicks) = v53->parent;
      LODWORD(v56) = v54 - totalTicks;
      v53->totalTicks = v56;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
    RD_EventEnd();
    return 0;
  }
  if ( v25 >= 0 )
  {
    v58 = &::pLog.logEntries.list[v25];
    v59 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v60 = v58->parent;
    LODWORD(v61) = v59 - LODWORD(v58->totalTicks);
    v58->totalTicks = v61;
    ::pLog.lastEntry = v60;
  }
  RD_EventEnd();
  RD_EventBegin(name: "idAnimator_AnimWeb::FindPath2 - trace paths");
  LODWORD(v62) = "idAnimator_AnimWeb::FindPath2 - trace paths";
  HIDWORD(v62) = 2;
  idPLogScope::idPLogScope(this: &v109[2], pl: &::pLog, gMask: v62, label: v63);
  v64 = 0;
  v65 = 7;
  v66 = v110;
  v67 = 3.4028235e38;
  do
  {
    `vector constructor iterator'(
      __t: v66 - 68,
      __s: 2u,
      __n: 32,
      __f: (void *(__fastcall *)(void *))idAnimator_TrackerBase::GetReferenceJointOverride);
    *((_DWORD *)v66 - 1) = 0;
    *(_DWORD *)v66 = 0x7FFFFFFF;
    --v65;
    v66 += 72;
  }
  while ( v65 >= 0 );
  v68 = 0;
  if ( v107.num <= 0 )
    goto LABEL_59;
  v69 = 0;
  v70 = (int *)v110;
  do
  {
    HIDWORD(v106[0]) = &v107.list[v69];
    HIDWORD(v71) = (unsigned __int8)idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute>::TracePath(
                                      this: (idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute> *)v109,
                                      nodeHolder: this,
                                      startNode: startNodeIndex,
                                      destNode: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)v107.list[v69].value,
                                      scratchBuff: (const djScratch_t *)v106,
                                      path: (idAnimWebRoute *)(v70 - 17));
    if ( HIDWORD(v71) != 0 )
    {
      v72 = *v70;
      HIDWORD(v106[0]) = *v70;
      LODWORD(v71) = HIDWORD(v106[0]);
      v109[4] = (idPLogScope)v71;
      if ( (float)v71 < v67 )
      {
        LODWORD(v71) = v72;
        HIDWORD(v106[0]) = v72;
        v15 = v64;
        v109[10] = (idPLogScope)v71;
        v67 = (float)v71;
      }
      ++v64;
      v70 += 18;
    }
    ++v68;
    ++v69;
  }
  while ( v68 < v107.num );
  if ( v15 >= 0 )
  {
    idAnimWebRoute::AppendPath(this: path, other: (const idAnimWebRoute *)&v109[9 * v15 + 28]);
    if ( v109[2].logIndex >= 0 )
    {
      v83 = v109[2].pLog;
      v84 = &v109[2].pLog->logEntries.list[v109[2].logIndex];
      v85 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v86 = v84->totalTicks;
      HIDWORD(v86) = v84->parent;
      LODWORD(v87) = v85 - v86;
      v84->totalTicks = v87;
      v83->lastEntry = HIDWORD(v86);
    }
    RD_EventEnd();
    if ( v107.listStatic == 0 || v107.listStatic == 2 )
    {
      if ( v107.list != nullptr )
        idMem::Free(this: &mem, ptr: v107.list, align: ALIGN_16);
      v107.list = nullptr;
      v107.size = 0;
    }
    v107.num = 0;
    if ( v109[3].logIndex >= 0 )
    {
      v88 = v109[3].pLog;
      v89 = &v109[3].pLog->logEntries.list[v109[3].logIndex];
      v90 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v91 = v89->totalTicks;
      HIDWORD(v91) = v89->parent;
      LODWORD(v92) = v90 - v91;
      v89->totalTicks = v92;
      v88->lastEntry = HIDWORD(v91);
    }
    RD_EventEnd();
    return 1;
  }
  else
  {
LABEL_59:
    if ( v109[2].logIndex >= 0 )
    {
      v73 = v109[2].pLog;
      v74 = &v109[2].pLog->logEntries.list[v109[2].logIndex];
      v75 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v76 = v74->totalTicks;
      HIDWORD(v76) = v74->parent;
      LODWORD(v77) = v75 - v76;
      v74->totalTicks = v77;
      v73->lastEntry = HIDWORD(v76);
    }
    RD_EventEnd();
    if ( v107.listStatic == 0 || v107.listStatic == 2 )
    {
      if ( v107.list != nullptr )
        idMem::Free(this: &mem, ptr: v107.list, align: ALIGN_16);
      v107.list = nullptr;
      v107.size = 0;
    }
    v107.num = 0;
    if ( v109[3].logIndex >= 0 )
    {
      v78 = v109[3].pLog;
      v79 = &v109[3].pLog->logEntries.list[v109[3].logIndex];
      v80 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      v81 = v79->totalTicks;
      HIDWORD(v81) = v79->parent;
      LODWORD(v82) = v80 - v81;
      v79->totalTicks = v82;
      v78->lastEntry = HIDWORD(v81);
    }
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$261724
// EA  : 0x826D7218
// RVA : 0x006D7218
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_261724()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1120 + 304));
}


// ========================================================================
// __unwind$261725
// EA  : 0x826D7240
// RVA : 0x006D7240
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_261725()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1120 + 240));
}


// ========================================================================
// __unwind$261726
// EA  : 0x826D7268
// RVA : 0x006D7268
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_261726()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1120 + 192));
}


// ========================================================================
// __unwind$261727
// EA  : 0x826D7290
// RVA : 0x006D7290
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_261727()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1120 + 272));
}


// ========================================================================
// __unwind$261728
// EA  : 0x826D72B8
// RVA : 0x006D72B8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_261728()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1120 + 336));
}


// ========================================================================
// __unwind$261729
// EA  : 0x826D72E0
// RVA : 0x006D72E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_261729()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1120 + 944));
}


// ========================================================================
// __unwind$261730
// EA  : 0x826D7308
// RVA : 0x006D7308
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_261730()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1120 + 168));
}


// ========================================================================
// __unwind$261731
// EA  : 0x826D7330
// RVA : 0x006D7330
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_261731()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1120 + 112));
}


// ========================================================================
// __unwind$261732
// EA  : 0x826D7358
// RVA : 0x006D7358
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_261732()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1120 + 945));
}


// ========================================================================
// __unwind$261733
// EA  : 0x826D7380
// RVA : 0x006D7380
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_261733()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1120 + 160));
}


// ========================================================================
// __unwind$261734
// EA  : 0x826D73A8
// RVA : 0x006D73A8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_261734()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1120 + 946));
}


// ========================================================================
// __unwind$261735
// EA  : 0x826D73D0
// RVA : 0x006D73D0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_261735()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1120 + 160));
}


// ========================================================================
// ?FindPath@idAnimator_AnimWeb@@QBA_NV?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@0V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@AAVidAnimWebRoute@@@Z
// EA  : 0x826D7400
// RVA : 0x006D7400
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::FindPath(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *startNodeIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *destNodeIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *otherSubWebIndex,
        idAnimWebRoute *path,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        idIndex<short,enum invalidUserChannelIndex_t> a16)
{
  __int16 v18; // r27
  __int16 v19; // r24
  idDeclAnimWebNode *v21; // r10
  idDeclAnimWebNode *v22; // r11
  unsigned __int64 v23; // r6
  const char *v24; // r7
  int v25; // r26
  int v26; // r20
  idDeclAnimWebNode *v27; // r11
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *value; // r21
  int v29; // r3
  idDeclAnimWebNode *v30; // r11
  int v31; // r29
  __int16 i; // r28
  const idDeclAnimWeb *decl; // r10
  int v34; // r10
  int skipFlags; // r28
  int requiredFlags; // r27
  int v37; // r12
  unsigned __int64 v38; // r6
  const char *v39; // r7
  int v40; // r29
  char ShortestPaths; // r27
  int v42; // r28
  idPLogScope v43; // r11
  __int64 v44; // r3
  double v45; // fp31
  idDeclAnimWebNode *v46; // r10
  idDeclAnimWebNode *v47; // r11
  const idDeclAnimWeb *v48; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v49; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v50; // r28
  const char *str; // r25
  const char *StateName; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v53; // r4
  const char *v54; // r21
  const char *SubWebName; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v56; // r4
  const char *v57; // r29
  const char *v58; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v59; // r4
  const char *v60; // r28
  const char *v61; // r3
  unsigned __int64 v62; // r6
  const char *v63; // r7
  int v64; // r25
  int v65; // r28
  char *v66; // r29
  double v67; // fp31
  int v68; // r27
  int v69; // r29
  int *v70; // r28
  __int64 v71; // r10
  int v72; // r11
  idPLog *v73; // r29
  idPLog::logEntry_t *v74; // r30
  int v75; // r3
  __int64 v76; // r11
  __int64 v77; // r9
  idPLog *v78; // r29
  idPLog::logEntry_t *v79; // r30
  int v80; // r3
  __int64 v81; // r11
  __int64 v82; // r9
  idPLog *pLog; // r29
  idPLog::logEntry_t *v84; // r30
  int v85; // r3
  __int64 totalTicks; // r11
  __int64 v87; // r9
  idPLog *v88; // r29
  idPLog::logEntry_t *v89; // r30
  int v90; // r3
  __int64 v91; // r11
  __int64 v92; // r9
  int back_chain[8]; // [sp+0h] [-440h]
  double v95; // [sp+20h] [-420h]
  int v96; // [sp+28h] [-418h]
  int v97; // [sp+2Ch] [-414h]
  int v98; // [sp+30h] [-410h]
  int v99; // [sp+34h] [-40Ch]
  int v100; // [sp+38h] [-408h]
  int v101; // [sp+3Ch] [-404h]
  int v102; // [sp+40h] [-400h]
  int v103; // [sp+44h] [-3FCh]
  int v104; // [sp+48h] [-3F8h]
  int v105; // [sp+4Ch] [-3F4h]
  int v106; // [sp+50h] [-3F0h]
  idList<idVehicleState *,5> v107; // [sp+60h] [-3E0h] BYREF
  _BYTE v108[16]; // [sp+70h] [-3D0h] BYREF
  idPLogScope v109[38]; // [sp+80h] [-3C0h] BYREF
  _BYTE v110[516]; // [sp+1B4h] [-28Ch] BYREF

  a16.value = (__int16)destNodeIndex;
  v18 = (__int16)destNodeIndex;
  v19 = (__int16)otherSubWebIndex;
  if ( anim_autoWebTrace.valueInteger != 0 )
  {
    v109[22].logIndex = 0;
    HIBYTE(v109[23].pLog) = 0;
    v109[23].logIndex = 20;
    v109[22].pLog = (idPLog *)&v109[23].pLog;
    v109[15].logIndex = 20;
    v109[14].pLog = (idPLog *)&v109[15].pLog;
    v109[14].logIndex = 0;
    HIBYTE(v109[15].pLog) = 0;
    v109[9].logIndex = 20;
    v109[8].pLog = (idPLog *)&v109[9].pLog;
    v109[8].logIndex = 0;
    HIBYTE(v109[9].pLog) = 0;
    idAnimWebPath::SplitPath(
      path: anim_sourcePath.valueString.data,
      webName: (idStr *)&v109[22],
      subWebName: (idStr *)&v109[14],
      stateName: (idStr *)&v109[8]);
    v109[19].logIndex = 20;
    v109[18].logIndex = 0;
    v109[18].pLog = (idPLog *)&v109[19].pLog;
    HIBYTE(v109[19].pLog) = 0;
    v109[27].logIndex = 20;
    v109[26].pLog = (idPLog *)&v109[27].pLog;
    v109[26].logIndex = 0;
    HIBYTE(v109[27].pLog) = 0;
    idAnimWebPath::SplitPath(
      path: anim_destPath.valueString.data,
      webName: (idStr *)&v109[22],
      subWebName: (idStr *)&v109[18],
      stateName: (idStr *)&v109[26]);
    idDeclAnimWeb::GetSubWebIndexForName(
      this: (idDeclAnimWeb *)&v109[2],
      result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->decl,
      subWebName: (const char *)v109[14].pLog);
    idDeclAnimWeb::GetStateIndexForName(
      this: (idDeclAnimWeb *)((char *)&v109[0].logIndex + 2),
      result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->decl,
      name: (const char *)v109[8].pLog);
    idDeclAnimWeb::GetSubWebIndexForName(
      this: (idDeclAnimWeb *)&v109[0].pLog,
      result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->decl,
      subWebName: (const char *)v109[18].pLog);
    idDeclAnimWeb::GetStateIndexForName(
      this: (idDeclAnimWeb *)v109,
      result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->decl,
      name: (const char *)v109[26].pLog);
    if ( (__int16)startNodeIndex == -1 )
      v21 = nullptr;
    else
      v21 = this->decl->nodes.list[(__int16)startNodeIndex];
    if ( v18 == -1 )
      v22 = nullptr;
    else
      v22 = this->decl->nodes.list[v18];
    if ( v21->subWebIndex.value == SHIWORD(v109[2].logIndex)
      && v21->states.stateIndex[0].value == SLOWORD(v109[0].logIndex)
      && v22->subWebIndex.value == SHIWORD(v109[0].pLog)
      && v22->states.stateIndex[0].value == SHIWORD(v109[0].logIndex) )
    {
      idCVar::SetBool(this: &anim_webTrace, newValue: true, force: true);
      idCVar::SetBool(this: &anim_autoWebTrace, newValue: false, force: true);
    }
    idStr::FreeData(this: (idStr *)&v109[26]);
    idStr::FreeData(this: (idStr *)&v109[18]);
    idStr::FreeData(this: (idStr *)&v109[8]);
    idStr::FreeData(this: (idStr *)&v109[14]);
    idStr::FreeData(this: (idStr *)&v109[22]);
  }
  RD_EventBegin(name: "idAnimator_AnimWeb::FindPath");
  LODWORD(v23) = "idAnimator_AnimWeb::FindPath";
  HIDWORD(v23) = 2;
  idPLogScope::idPLogScope(this: &v109[4], pl: &::pLog, gMask: v23, label: v24);
  v25 = -1;
  memset(v108, 255, sizeof(v108));
  *(_QWORD *)&v107.num = 8;
  v107.list = (idVehicleState **)v108;
  *(_DWORD *)&v107.granularity = 66817;
  idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
    this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&v107,
    obj: &a16);
  if ( (__int16)startNodeIndex < 0 || (v26 = v18, v18 < 0) )
  {
    idList<idThread *,58>::Clear(this: &v107);
    idPLogScope::~idPLogScope(this: &v109[4]);
    goto LABEL_76;
  }
  v109[5].logIndex = -1;
  if ( v18 == -1 )
    v27 = nullptr;
  else
    v27 = this->decl->nodes.list[v18];
  value = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v27->subWebIndex.value;
  v29 = idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->pathableSubWebNodeLists, newNum: 0);
  if ( (__int16)startNodeIndex == -1 )
    v30 = nullptr;
  else
    v30 = this->decl->nodes.list[(__int16)startNodeIndex];
  v31 = 0;
  for ( i = v30->subWebIndex.value; v31 < this->decl->subWebs.num; ++v31 )
  {
    decl = this->decl;
    if ( (v31 & 0x8000u) != 0 || (__int16)v31 >= decl->subWebs.num )
      v34 = 0;
    else
      v34 = (int)&decl->subWebs.list[(__int16)v31];
    if ( *(_BYTE *)(v34 + 36) != 0 || i == (__int16)v31 || (__int16)value == (__int16)v31 || v19 == (__int16)v31 )
    {
      v109[3].logIndex = v34;
      v29 = idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&this->pathableSubWebNodeLists,
              obj: (const encounterGroupRole_t *)&v109[3]);
    }
  }
  skipFlags = this->skipFlags;
  requiredFlags = this->requiredFlags;
  this->skipFlags = 0;
  this->requiredFlags = 0;
  ((void (__fastcall *)(int))RtlCheckStack12)(a1: v29);
  *(int *)((char *)back_chain + v37) = back_chain[0];
  RD_EventBegin(name: "idDijkstra::FindShortestPaths");
  LODWORD(v38) = "idDijkstra::FindShortestPaths";
  HIDWORD(v38) = 2;
  idPLogScope::idPLogScope(this: &v109[1], pl: &::pLog, gMask: v38, label: v39);
  v40 = (unsigned __int64)Sys_GetClockTicks() >> 32;
  ShortestPaths = idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute>::FindShortestPaths(
                    this: (idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute> *)&v109[5],
                    nodeHolder: this,
                    startNode: startNodeIndex,
                    destNodes: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v107.list,
                    numDestNodes: v107.num,
                    edges: this->decl->edgeCache.list,
                    scratchBuff: (djScratch_t *)&v107,
                    skipFlags,
                    requiredFlags: back_chain[2],
                    a10: back_chain[3],
                    a11: back_chain[4],
                    a12: back_chain[5],
                    a13: back_chain[6],
                    a14: back_chain[7],
                    a15: SHIDWORD(v95),
                    a16: SLODWORD(v95),
                    a17: v96,
                    a18: v97,
                    a19: v98,
                    a20: v99,
                    a21: v100,
                    a22: v101,
                    a23: v102,
                    a24: v103,
                    a25: v104,
                    a26: v105,
                    a27: v106,
                    a28: requiredFlags);
  v42 = (unsigned __int64)Sys_GetClockTicks() >> 32;
  if ( anim_webTrace.valueInteger != 0 )
    idCVar::SetBool(this: &anim_webTrace, newValue: false, force: true);
  v43.pLog = (idPLog *)(v42 - v40);
  v109[3] = v43;
  LODWORD(v44) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
  v109[6] = (idPLogScope)v44;
  v45 = (float)((float)(__int64)v109[3] / (float)((float)v44 * (float)0.001));
  if ( v45 > anim_webTimeThreshold.valueFloat )
  {
    if ( (__int16)startNodeIndex == -1 )
      v46 = nullptr;
    else
      v46 = this->decl->nodes.list[(__int16)startNodeIndex];
    if ( v26 == -1 )
      v47 = nullptr;
    else
      v47 = this->decl->nodes.list[v26];
    v48 = this->decl;
    v49 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v46->states.stateIndex[0].value;
    v50 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v46->subWebIndex.value;
    str = v48->name.str;
    StateName = idDeclAnimWeb::GetStateName(
                  this: v48,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v47->states.stateIndex[0].value);
    v53 = value;
    v54 = StateName;
    SubWebName = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v53);
    v56 = v49;
    v57 = SubWebName;
    v58 = idDeclAnimWeb::GetStateName(this: this->decl, index: v56);
    v59 = v50;
    v60 = v58;
    v61 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v59);
    v95 = v45;
    idLib::Printf(
      fmt: "animWeb '%s' - slow path (%.8f ms) from '%s:%s' to '%s:%s' other '%s'\n",
      str,
      v45,
      (const char *)LODWORD(v45),
      v61,
      v60,
      v57,
      v54);
  }
  if ( ShortestPaths == 0 )
  {
    idPLogScope::~idPLogScope(this: &v109[1]);
    RD_EventEnd();
    idList<idThread *,58>::Clear(this: &v107);
    idPLogScope::~idPLogScope(this: &v109[4]);
LABEL_76:
    RD_EventEnd();
    return 0;
  }
  idPLogScope::~idPLogScope(this: &v109[1]);
  RD_EventEnd();
  RD_EventBegin(name: "idAnimator_AnimWeb::FindPath - TracePaths");
  LODWORD(v62) = "idAnimator_AnimWeb::FindPath - TracePaths";
  HIDWORD(v62) = 2;
  idPLogScope::idPLogScope(this: &v109[1], pl: &::pLog, gMask: v62, label: v63);
  v64 = 0;
  v65 = 7;
  v66 = v110;
  v67 = 3.4028235e38;
  do
  {
    `vector constructor iterator'(
      __t: v66 - 68,
      __s: 2u,
      __n: 32,
      __f: (void *(__fastcall *)(void *))idAnimator_TrackerBase::GetReferenceJointOverride);
    *((_DWORD *)v66 - 1) = 0;
    *(_DWORD *)v66 = 0x7FFFFFFF;
    --v65;
    v66 += 72;
  }
  while ( v65 >= 0 );
  v68 = 0;
  if ( v107.num > 0 )
  {
    v69 = 0;
    v70 = (int *)v110;
    do
    {
      v109[3].logIndex = (int)v107.list + v69;
      HIDWORD(v71) = (unsigned __int8)idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute>::TracePath(
                                        this: (idDijkstra<idAnimator_AnimWeb,idDeclAnimWeb::idNodeCache,idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,idDeclAnimWeb::idEdgeCache,idAnimWebRoute> *)&v109[5],
                                        nodeHolder: this,
                                        startNode: startNodeIndex,
                                        destNode: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)*(unsigned __int16 *)((char *)v107.list + v69),
                                        scratchBuff: (const djScratch_t *)&v107,
                                        path: (idAnimWebRoute *)(v70 - 17));
      if ( HIDWORD(v71) != 0 )
      {
        v72 = *v70;
        v109[3].logIndex = *v70;
        LODWORD(v71) = v109[3].logIndex;
        v109[6] = (idPLogScope)v71;
        if ( (float)v71 < v67 )
        {
          LODWORD(v71) = v72;
          v109[3].logIndex = v72;
          v25 = v64;
          v109[12] = (idPLogScope)v71;
          v67 = (float)v71;
        }
        ++v64;
        v70 += 18;
      }
      ++v68;
      v69 += 2;
    }
    while ( v68 < v107.num );
    if ( v25 >= 0 )
    {
      idAnimWebRoute::AppendPath(this: path, other: (const idAnimWebRoute *)&v109[9 * v25 + 30]);
      if ( v109[1].logIndex >= 0 )
      {
        pLog = v109[1].pLog;
        v84 = &v109[1].pLog->logEntries.list[v109[1].logIndex];
        v85 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        totalTicks = v84->totalTicks;
        HIDWORD(totalTicks) = v84->parent;
        LODWORD(v87) = v85 - totalTicks;
        v84->totalTicks = v87;
        pLog->lastEntry = HIDWORD(totalTicks);
      }
      RD_EventEnd();
      if ( v107.listStatic == 0 || v107.listStatic == 2 )
      {
        if ( v107.list != nullptr )
          idMem::Free(this: &mem, ptr: v107.list, align: ALIGN_16);
        v107.list = nullptr;
        v107.size = 0;
      }
      v107.num = 0;
      if ( v109[4].logIndex >= 0 )
      {
        v88 = v109[4].pLog;
        v89 = &v109[4].pLog->logEntries.list[v109[4].logIndex];
        v90 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v91 = v89->totalTicks;
        HIDWORD(v91) = v89->parent;
        LODWORD(v92) = v90 - v91;
        v89->totalTicks = v92;
        v88->lastEntry = HIDWORD(v91);
      }
      RD_EventEnd();
      return 1;
    }
  }
  if ( v109[1].logIndex >= 0 )
  {
    v73 = v109[1].pLog;
    v74 = &v109[1].pLog->logEntries.list[v109[1].logIndex];
    v75 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v76 = v74->totalTicks;
    HIDWORD(v76) = v74->parent;
    LODWORD(v77) = v75 - v76;
    v74->totalTicks = v77;
    v73->lastEntry = HIDWORD(v76);
  }
  RD_EventEnd();
  if ( v107.listStatic == 0 || v107.listStatic == 2 )
  {
    if ( v107.list != nullptr )
      idMem::Free(this: &mem, ptr: v107.list, align: ALIGN_16);
    v107.list = nullptr;
    v107.size = 0;
  }
  v107.num = 0;
  if ( v109[4].logIndex >= 0 )
  {
    v78 = v109[4].pLog;
    v79 = &v109[4].pLog->logEntries.list[v109[4].logIndex];
    v80 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v81 = v79->totalTicks;
    HIDWORD(v81) = v79->parent;
    LODWORD(v82) = v80 - v81;
    v79->totalTicks = v82;
    v78->lastEntry = HIDWORD(v81);
  }
  goto LABEL_76;
}


// ========================================================================
// __unwind$262617
// EA  : 0x826D7C6C
// RVA : 0x006D7C6C
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_262617()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1088 + 304));
}


// ========================================================================
// __unwind$262618
// EA  : 0x826D7C94
// RVA : 0x006D7C94
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_262618()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1088 + 240));
}


// ========================================================================
// __unwind$262619
// EA  : 0x826D7CBC
// RVA : 0x006D7CBC
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_262619()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1088 + 192));
}


// ========================================================================
// __unwind$262620
// EA  : 0x826D7CE4
// RVA : 0x006D7CE4
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_262620()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1088 + 272));
}


// ========================================================================
// __unwind$262621
// EA  : 0x826D7D0C
// RVA : 0x006D7D0C
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_262621()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1088 + 336));
}


// ========================================================================
// __unwind$262622
// EA  : 0x826D7D34
// RVA : 0x006D7D34
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_262622()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1088 + 944));
}


// ========================================================================
// __unwind$262623
// EA  : 0x826D7D5C
// RVA : 0x006D7D5C
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_262623()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1088 + 160));
}


// ========================================================================
// __unwind$262624
// EA  : 0x826D7D84
// RVA : 0x006D7D84
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_262624()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1088 + 96));
}


// ========================================================================
// __unwind$262625
// EA  : 0x826D7DAC
// RVA : 0x006D7DAC
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_262625()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1088 + 945));
}


// ========================================================================
// __unwind$262626
// EA  : 0x826D7DD4
// RVA : 0x006D7DD4
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_262626()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1088 + 136));
}


// ========================================================================
// __unwind$262627
// EA  : 0x826D7DFC
// RVA : 0x006D7DFC
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_262627()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1088 + 946));
}


// ========================================================================
// __unwind$262628
// EA  : 0x826D7E24
// RVA : 0x006D7E24
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_262628()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1088 + 136));
}


// ========================================================================
// ?StartPath@idAnimator_AnimWeb@@QAAXH@Z
// EA  : 0x826D7E58
// RVA : 0x006D7E58
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::StartPath(idAnimator_AnimWeb *this, const int curTime)
{
  unsigned __int64 v3; // r6
  const char *v4; // r7
  _WORD *v5; // r10
  const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *value; // r23
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *p_destSubWebIndex; // r11
  int i; // ctr
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v9; // r27
  idAnimWebRoute *p_curPath; // r29
  unsigned __int8 v11; // r28
  int v12; // r8
  int v13; // r22
  unsigned __int64 v14; // r6
  const char *v15; // r7
  char v16; // r3
  int v17; // r11
  unsigned __int64 v18; // r6
  const char *v19; // r7
  idDeclAnimWebNode *v20; // r11
  const idDeclAnimWeb *v21; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v22; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v23; // r26
  const char *v24; // r25
  const char *v25; // r28
  const char *v26; // r23
  const char *v27; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v28; // r4
  const char *v29; // r27
  const char *v30; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v31; // r4
  const char *v32; // r29
  const char *v33; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v34; // r4
  const char *v35; // r26
  const char *v36; // r3
  char Path; // r3
  int num; // r11
  unsigned __int64 v39; // r6
  const char *v40; // r7
  idDeclAnimWebNode *v41; // r11
  const idDeclAnimWeb *decl; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v43; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v44; // r26
  const char *str; // r28
  const char *StateName; // r25
  const char *SubWebName; // r24
  const char *v48; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v49; // r4
  const char *v50; // r27
  const char *v51; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v52; // r4
  const char *v53; // r29
  const char *v54; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v55; // r4
  const char *v56; // r26
  const char *v57; // r3
  unsigned __int64 v58; // r6
  const char *v59; // r7
  idDeclAnimWebNode *v60; // r11
  const idDeclAnimWeb *v61; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v62; // r28
  const char *v63; // r26
  const char *v64; // r25
  const char *v65; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v66; // r4
  const char *v67; // r27
  const char *v68; // r29
  const char *v69; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v70; // r4
  const char *v71; // r28
  const char *v72; // r3
  const char *v73; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v74; // r4
  const char *v75; // r27
  const char *v76; // r29
  const char *v77; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v78; // r4
  const char *v79; // r28
  const char *v80; // r3
  idDeclAnimWebNode *v81; // r11
  const idDeclAnimWeb *v82; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v83; // r28
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v84; // r26
  idGameTimeManager *gameTimeManager; // r19
  const char *v86; // r18
  const char *v87; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v88; // r4
  const char *v89; // r27
  const char *v90; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v91; // r4
  const char *v92; // r28
  const char *v93; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v94; // r4
  const char *v95; // r26
  const char *v96; // r15
  int v97; // r3
  const idDeclAnimWeb *v98; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v99; // r28
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v100; // r26
  idGameTimeManager *v101; // r19
  const char *v102; // r18
  const char *v103; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v104; // r4
  const char *v105; // r27
  const char *v106; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v107; // r4
  const char *v108; // r28
  const char *v109; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v110; // r4
  const char *v111; // r26
  const char *v112; // r17
  int v113; // r3
  int j; // r28
  __int16 v115; // r11
  idDeclAnimWebNode *v116; // r11
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v117; // r26
  const char *v118; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v119; // r4
  const char *v120; // r26
  const char *v121; // r3
  __int64 v122; // r8
  __int64 v123; // r10
  int v124; // r11
  __int16 v125; // r11
  int v126; // r5
  idDeclAnimWebNode *v127; // r11
  int v128; // r7
  idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *list; // r9
  int v130; // r11
  char v131; // r11
  idPLog *v132; // r29
  idPLog::logEntry_t *v133; // r30
  int v134; // r3
  __int64 v135; // r11
  __int64 v136; // r9
  idPLog *pLog; // r29
  idPLog::logEntry_t *v138; // r30
  int v139; // r3
  __int64 totalTicks; // r11
  __int64 v141; // r9
  const char *v142; // [sp+8h] [-168h]
  int v143; // [sp+8h] [-168h]
  int v144; // [sp+Ch] [-164h]
  int v145; // [sp+Ch] [-164h]
  int v146; // [sp+10h] [-160h]
  int v147; // [sp+10h] [-160h]
  int v148; // [sp+14h] [-15Ch]
  int v149; // [sp+14h] [-15Ch]
  int v150; // [sp+18h] [-158h]
  int v151; // [sp+18h] [-158h]
  int v152; // [sp+1Ch] [-154h]
  int v153; // [sp+1Ch] [-154h]
  unsigned __int16 v154; // [sp+B0h] [-C0h]
  unsigned __int16 v155; // [sp+B0h] [-C0h]
  unsigned __int16 v156; // [sp+B0h] [-C0h]
  int v157; // [sp+B0h] [-C0h]
  idPLogScope v158; // [sp+B8h] [-B8h] BYREF
  idPLogScope v159; // [sp+C0h] [-B0h] BYREF
  idDeclAnimWeb::stateList_t v160[16]; // [sp+C8h] [-A8h] BYREF

  RD_EventBegin(name: "idAnimator_AnimWeb::StartPath");
  LODWORD(v3) = "idAnimator_AnimWeb::StartPath";
  HIDWORD(v3) = 2;
  idPLogScope::idPLogScope(this: &v158, pl: &::pLog, gMask: v3, label: v4);
  if ( this->curNodeIndex.value < 0 )
  {
    idPLogScope::~idPLogScope(this: &v158);
    goto LABEL_86;
  }
  v5 = (_WORD *)&v159.pLog + 1;
  value = (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)this->curNodeIndex.value;
  p_destSubWebIndex = &this->destSubWebIndex;
  for ( i = 5; i != 0; --i )
  {
    ++p_destSubWebIndex;
    *++v5 = p_destSubWebIndex->value;
  }
  v9 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value;
  this->destSubWebIndex.value = -1;
  this->destStateIndices.numStates = 0;
  this->curEdgeNodeIndex.value = -1;
  p_curPath = &this->curPath;
  this->curEdgeIndex = -1;
  v11 = 1;
  this->curPath.cost = 0x7FFFFFFF;
  this->curPath.num = 0;
  if ( (unsigned __int16)this->forcedEdge.destNodeIndex.value < 0x8000u )
  {
    this->curEdgeNodeIndex.value = (__int16)value;
    this->curEdgeIndex = 0x7FFF;
    p_curPath->path[this->curPath.num].value = (__int16)value;
    v12 = this->curPath.num + 1;
    this->curPath.num = v12;
    p_curPath->path[v12].value = this->forcedEdge.destNodeIndex.value;
    ++this->curPath.num;
    this->curPath.cost = 1;
    this->pathIndex = 0;
    idAnimator_AnimWeb::CacheDestNode(this);
    if ( v160[0].numStates != 0 )
      value = (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)this->forcedEdge.destNodeIndex.value;
    else
      v11 = 0;
  }
  v13 = v11;
  if ( v11 != 0 )
  {
    RD_EventBegin(name: "idAnimator_AnimWeb::InternalStartPath");
    LODWORD(v14) = "idAnimator_AnimWeb::InternalStartPath";
    HIDWORD(v14) = 2;
    idPLogScope::idPLogScope(this: &v159, pl: &::pLog, gMask: v14, label: v15);
    this->InternalStartPath(this);
    idPLogScope::~idPLogScope(this: &v159);
    RD_EventEnd();
    if ( this->viaStateIndices.numStates != 0 && (unsigned __int16)this->viaSubWebIndex.value < 0x8000u )
    {
      if ( (unsigned __int16)this->otherSubWebIndex.value >= 0x8000u )
      {
        Path = idAnimator_AnimWeb::FindPath(
                 this,
                 startNodeIndex: value,
                 destStateIndices_: &this->viaStateIndices,
                 destSubWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->viaSubWebIndex.value,
                 otherSubWebIndex: v9,
                 path: &this->curPath);
        if ( Path != 0 )
        {
          num = this->curPath.num;
          if ( num > 0 )
            v155 = p_curPath->path[num - 1].value;
          else
            v155 = -1;
          Path = idAnimator_AnimWeb::FindPath(
                   this,
                   startNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v155,
                   destStateIndices_: v160,
                   destSubWebIndex_: v9,
                   otherSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->viaSubWebIndex.value,
                   path: &this->curPath);
        }
        if ( Path == 0 )
        {
          RD_EventBegin(name: "idAnimator_AnimWeb::StartPath - warning1");
          LODWORD(v39) = "idAnimator_AnimWeb::StartPath - warning1";
          HIDWORD(v39) = 2;
          idPLogScope::idPLogScope(this: &v159, pl: &::pLog, gMask: v39, label: v40);
          if ( (__int16)value == -1 )
            v41 = nullptr;
          else
            v41 = this->decl->nodes.list[(__int16)value];
          decl = this->decl;
          v43 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v41->states.stateIndex[0].value;
          v44 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v41->subWebIndex.value;
          str = decl->name.str;
          StateName = idDeclAnimWeb::GetStateName(
                        this: decl,
                        index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->viaStateIndices.stateIndex[0].value);
          SubWebName = idDeclAnimWeb::GetSubWebName(
                         this: this->decl,
                         index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->viaSubWebIndex.value);
          v48 = idDeclAnimWeb::GetStateName(
                  this: this->decl,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v160[0].stateIndex[0].value);
          v49 = v9;
          v50 = v48;
          v51 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v49);
          v52 = v43;
          v53 = v51;
          v54 = idDeclAnimWeb::GetStateName(this: this->decl, index: v52);
          v55 = v44;
          v56 = v54;
          v57 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v55);
          idLib::Warning(
            fmt: "animweb '%s' could not find path from state '%s::%s' to desired state '%s::%s' through state '%s::%s.",
            str,
            v57,
            v56,
            v53,
            v50,
            SubWebName,
            StateName);
          this->error = ANIMWEB_ERROR_NOPATH;
          idPLogScope::~idPLogScope(this: &v159);
          RD_EventEnd();
          idPLogScope::~idPLogScope(this: &v158);
          goto LABEL_86;
        }
      }
      else
      {
        v16 = idAnimator_AnimWeb::FindPath(
                this,
                startNodeIndex: value,
                destStateIndices_: &this->viaStateIndices,
                destSubWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->viaSubWebIndex.value,
                otherSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->otherSubWebIndex.value,
                path: &this->curPath);
        if ( v16 != 0 )
        {
          v17 = this->curPath.num;
          if ( v17 > 0 )
            v154 = p_curPath->path[v17 - 1].value;
          else
            v154 = -1;
          v16 = idAnimator_AnimWeb::FindPath(
                  this,
                  startNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v154,
                  destStateIndices_: v160,
                  destSubWebIndex_: v9,
                  otherSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->otherSubWebIndex.value,
                  path: &this->curPath);
        }
        if ( v16 == 0 )
        {
          RD_EventBegin(name: "idAnimator_AnimWeb::StartPath - warning1");
          LODWORD(v18) = "idAnimator_AnimWeb::StartPath - warning1";
          HIDWORD(v18) = 2;
          idPLogScope::idPLogScope(this: &v159, pl: &::pLog, gMask: v18, label: v19);
          if ( (__int16)value == -1 )
            v20 = nullptr;
          else
            v20 = this->decl->nodes.list[(__int16)value];
          v21 = this->decl;
          v22 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v20->states.stateIndex[0].value;
          v23 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v20->subWebIndex.value;
          v24 = v21->name.str;
          idDeclAnimWeb::GetSubWebName(
            this: v21,
            index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->otherSubWebIndex.value);
          v25 = idDeclAnimWeb::GetStateName(
                  this: this->decl,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->viaStateIndices.stateIndex[0].value);
          v26 = idDeclAnimWeb::GetSubWebName(
                  this: this->decl,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->viaSubWebIndex.value);
          v27 = idDeclAnimWeb::GetStateName(
                  this: this->decl,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v160[0].stateIndex[0].value);
          v28 = v9;
          v29 = v27;
          v30 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v28);
          v31 = v22;
          v32 = v30;
          v33 = idDeclAnimWeb::GetStateName(this: this->decl, index: v31);
          v34 = v23;
          v35 = v33;
          v36 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v34);
          idLib::Warning(
            fmt: "animweb '%s' could not find path from state '%s::%s' to desired state '%s::%s' through state '%s::%s using o"
            "ther subweb '%s'.",
            v24,
            v36,
            v35,
            v32,
            v29,
            v26,
            v25,
            v142);
          this->error = ANIMWEB_ERROR_NOPATH;
          idPLogScope::~idPLogScope(this: &v159);
          RD_EventEnd();
          idPLogScope::~idPLogScope(this: &v158);
          goto LABEL_86;
        }
      }
    }
    else if ( (unsigned __int8)idAnimator_AnimWeb::FindPath(
                                 this,
                                 startNodeIndex: value,
                                 destStateIndices_: v160,
                                 destSubWebIndex_: v9,
                                 otherSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->otherSubWebIndex.value,
                                 path: &this->curPath) == 0 )
    {
      RD_EventBegin(name: "idAnimator_AnimWeb::StartPath - warning2");
      LODWORD(v58) = "idAnimator_AnimWeb::StartPath - warning2";
      HIDWORD(v58) = 2;
      idPLogScope::idPLogScope(this: &v159, pl: &::pLog, gMask: v58, label: v59);
      if ( (__int16)value == -1 )
        v60 = nullptr;
      else
        v60 = this->decl->nodes.list[(__int16)value];
      v156 = v60->states.stateIndex[0].value;
      if ( v160[0].stateIndex[0].value == (__int16)v156 && (__int16)v9 == v60->subWebIndex.value )
      {
        idPLogScope::~idPLogScope(this: &v159);
        RD_EventEnd();
        idPLogScope::~idPLogScope(this: &v158);
      }
      else
      {
        v61 = this->decl;
        v62 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v60->subWebIndex.value;
        v63 = v61->name.str;
        if ( (unsigned __int16)this->otherSubWebIndex.value >= 0x8000u )
        {
          v73 = idDeclAnimWeb::GetStateName(
                  this: v61,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v160[0].stateIndex[0].value);
          v74 = v9;
          v75 = v73;
          v76 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v74);
          v77 = idDeclAnimWeb::GetStateName(
                  this: this->decl,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v156);
          v78 = v62;
          v79 = v77;
          v80 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v78);
          idLib::Warning(
            fmt: "animweb '%s' could not find path from state '%s::%s' to desired state '%s::%s'.",
            v63,
            v80,
            v79,
            v76,
            v75);
        }
        else
        {
          v64 = idDeclAnimWeb::GetSubWebName(
                  this: v61,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->otherSubWebIndex.value);
          v65 = idDeclAnimWeb::GetStateName(
                  this: this->decl,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v160[0].stateIndex[0].value);
          v66 = v9;
          v67 = v65;
          v68 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v66);
          v69 = idDeclAnimWeb::GetStateName(
                  this: this->decl,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v156);
          v70 = v62;
          v71 = v69;
          v72 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v70);
          idLib::Warning(
            fmt: "animweb '%s' could not find path from state '%s::%s' to desired state '%s::%s' through other subweb '%s'.",
            v63,
            v72,
            v71,
            v68,
            v67,
            v64);
        }
        this->error = ANIMWEB_ERROR_NOPATH;
        idPLogScope::~idPLogScope(this: &v159);
        RD_EventEnd();
        idPLogScope::~idPLogScope(this: &v158);
      }
      goto LABEL_86;
    }
    this->pathIndex = 0;
    idAnimator_AnimWeb::CacheDestNode(this);
  }
  if ( this->debug )
  {
    v81 = (__int16)value == -1 ? nullptr : this->decl->nodes.list[(__int16)value];
    if ( this->viaStateIndices.numStates != 0 && (unsigned __int16)this->viaSubWebIndex.value < 0x8000u )
    {
      v82 = this->decl;
      v83 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v81->states.stateIndex[0].value;
      v84 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v81->subWebIndex.value;
      gameTimeManager = this->gametimeManager.gameTimeManager;
      v86 = v82->name.str;
      idDeclAnimWeb::GetStateName(
        this: v82,
        index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->viaStateIndices.stateIndex[0].value);
      idDeclAnimWeb::GetSubWebName(
        this: this->decl,
        index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->viaSubWebIndex.value);
      v87 = idDeclAnimWeb::GetStateName(
              this: this->decl,
              index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v160[0].stateIndex[0].value);
      v88 = v9;
      v89 = v87;
      v90 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v88);
      v91 = v83;
      v92 = v90;
      v93 = idDeclAnimWeb::GetStateName(this: this->decl, index: v91);
      v94 = v84;
      v95 = v93;
      v96 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v94);
      v97 = idAccolade::Count(this: gameTimeManager);
      idAnimator_AnimWeb::DebugPrint(
        this,
        fmt: "(%d) animWeb '%s', path from '%s::%s' to '%s::%s' through '%s::%s' at time %d:\n",
        a3: __SPAIR64__(v97, (unsigned int)v86),
        a4: __SPAIR64__((unsigned int)v96, (unsigned int)v95),
        a5: __SPAIR64__((unsigned int)v92, (unsigned int)v89),
        a6: (int)v142,
        a7: v144,
        a8: v146,
        a9: v148,
        a10: v150,
        a11: v152);
    }
    else
    {
      v98 = this->decl;
      v99 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v81->states.stateIndex[0].value;
      v100 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v81->subWebIndex.value;
      v101 = this->gametimeManager.gameTimeManager;
      v102 = v98->name.str;
      v103 = idDeclAnimWeb::GetStateName(
               this: v98,
               index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v160[0].stateIndex[0].value);
      v104 = v9;
      v105 = v103;
      v106 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v104);
      v107 = v99;
      v108 = v106;
      v109 = idDeclAnimWeb::GetStateName(this: this->decl, index: v107);
      v110 = v100;
      v111 = v109;
      v112 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v110);
      v113 = idAccolade::Count(this: v101);
      idAnimator_AnimWeb::DebugPrint(
        this,
        fmt: "(%d) animWeb '%s', path from '%s::%s' to '%s::%s' at time %d:\n",
        a3: __SPAIR64__(v113, (unsigned int)v102),
        a4: __SPAIR64__((unsigned int)v112, (unsigned int)v111),
        a5: __SPAIR64__((unsigned int)v108, (unsigned int)v105),
        a6: (int)v142,
        a7: v144,
        a8: v146,
        a9: v148,
        a10: v150,
        a11: v152);
    }
    for ( j = 0; j < this->curPath.num; ++j )
    {
      if ( (j & 0x8000u) != 0 || (__int16)j >= this->curPath.num )
        v115 = -1;
      else
        v115 = p_curPath->path[(__int16)j].value;
      if ( v115 == -1 )
        v116 = nullptr;
      else
        v116 = this->decl->nodes.list[v115];
      v117 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v116->subWebIndex.value;
      v118 = idDeclAnimWeb::GetStateName(
               this: this->decl,
               index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v116->states.stateIndex[0].value);
      v119 = v117;
      v120 = v118;
      v121 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v119);
      HIDWORD(v122) = v120;
      idAnimator_AnimWeb::DebugPrint(
        this,
        fmt: "  %d: %s::%s\n",
        a3: __SPAIR64__(j, (unsigned int)v121),
        a4: v122,
        a5: v123,
        a6: v143,
        a7: v145,
        a8: v147,
        a9: v149,
        a10: v151,
        a11: v153);
    }
  }
  if ( v13 == 0 )
    goto LABEL_84;
  v124 = (__int16)(this->pathIndex + 1);
  if ( v124 < 0 || v124 >= this->curPath.num )
    v125 = -1;
  else
    v125 = p_curPath->path[v124].value;
  v126 = v125;
  if ( this->curEdgeIndex != 0x7FFF )
  {
    v127 = (__int16)value == -1 ? nullptr : this->decl->nodes.list[(__int16)value];
    v128 = 0;
    v157 = v127->edges.num;
    if ( v157 > 0 )
    {
      list = v127->edges.list;
      v130 = 0;
      while ( this->decl->edgeCache.list[list[v130].value].destNodeIndex.value != v126 )
      {
        ++v128;
        ++v130;
        if ( v128 >= v157 )
          goto LABEL_77;
      }
      this->curEdgeNodeIndex.value = (__int16)value;
      this->curEdgeIndex = v128;
    }
  }
LABEL_77:
  if ( (unsigned __int16)this->curEdgeNodeIndex.value >= 0x8000u
    || (v131 = 1, (unsigned __int16)this->curEdgeIndex >= 0x8000u) )
  {
    v131 = 0;
  }
  if ( v131 != 0 )
  {
LABEL_84:
    if ( v158.logIndex >= 0 )
    {
      pLog = v158.pLog;
      v138 = &v158.pLog->logEntries.list[v158.logIndex];
      v139 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v138->totalTicks;
      HIDWORD(totalTicks) = v138->parent;
      LODWORD(v141) = v139 - totalTicks;
      v138->totalTicks = v141;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  else if ( v158.logIndex >= 0 )
  {
    v132 = v158.pLog;
    v133 = &v158.pLog->logEntries.list[v158.logIndex];
    v134 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    v135 = v133->totalTicks;
    HIDWORD(v135) = v133->parent;
    LODWORD(v136) = v134 - v135;
    v133->totalTicks = v136;
    v132->lastEntry = HIDWORD(v135);
  }
LABEL_86:
  RD_EventEnd();
}


// ========================================================================
// __unwind$263540
// EA  : 0x826D886C
// RVA : 0x006D886C
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_263540()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 368 + 210));
}


// ========================================================================
// __unwind$263541
// EA  : 0x826D8894
// RVA : 0x006D8894
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_263541()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 368 + 184));
}


// ========================================================================
// __unwind$263542
// EA  : 0x826D88BC
// RVA : 0x006D88BC
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_263542()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 368 + 211));
}


// ========================================================================
// __unwind$263543
// EA  : 0x826D88E4
// RVA : 0x006D88E4
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_263543()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 368 + 192));
}


// ========================================================================
// __unwind$263544
// EA  : 0x826D890C
// RVA : 0x006D890C
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_263544()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 368 + 212));
}


// ========================================================================
// __unwind$263545
// EA  : 0x826D8934
// RVA : 0x006D8934
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_263545()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 368 + 192));
}


// ========================================================================
// __unwind$263546
// EA  : 0x826D895C
// RVA : 0x006D895C
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_263546()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 368 + 213));
}


// ========================================================================
// __unwind$263547
// EA  : 0x826D8984
// RVA : 0x006D8984
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_263547()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 368 + 192));
}


// ========================================================================
// __unwind$263548
// EA  : 0x826D89AC
// RVA : 0x006D89AC
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_263548()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 368 + 214));
}


// ========================================================================
// __unwind$263549
// EA  : 0x826D89D4
// RVA : 0x006D89D4
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_263549()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 368 + 192));
}


// ========================================================================
// ?SetDecl@idAnimator_AnimWeb@@QAAXPBVidDeclAnimWeb@@PBVidDeclMD6@@@Z
// EA  : 0x826D8A08
// RVA : 0x006D8A08
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::SetDecl(
        idAnimator_AnimWeb *this,
        const idDeclAnimWeb *decl_,
        const idDeclMD6 *declMD6Model0)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idList<idAnimator_AnimWeb::idModelAnimState,33> *p_modelAnimStates; // r27
  int v9; // r30
  int num; // r4
  const idDeclAnimWeb *decl; // r11
  int v12; // r28
  int size; // r11
  idList<idDeclMD6 const *,33> *p_modelDecls; // r26
  int v15; // r4
  const idDeclAnimWeb *v16; // r11
  int v17; // r28
  int v18; // r11
  const idDeclAnimWeb *v19; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v21; // r30
  int v22; // r3
  __int64 totalTicks; // r11
  __int64 v24; // r9
  idPLogScope v25; // [sp+58h] [-58h] BYREF

  RD_EventBegin(name: "idAnimator_AnimWeb::SetDecl");
  LODWORD(v6) = "idAnimator_AnimWeb::SetDecl";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: &v25, pl: &::pLog, gMask: v6, label: v7);
  this->decl = decl_;
  p_modelAnimStates = &this->modelAnimStates;
  v9 = 0;
  if ( this->modelAnimStates.listStatic == 0 || this->modelAnimStates.listStatic == 2 )
  {
    if ( p_modelAnimStates->list != nullptr )
      idListArrayDelete<idAnimator_AnimWeb::idModelAnimState>(
        ptr: p_modelAnimStates->list,
        num: this->modelAnimStates.size);
    p_modelAnimStates->list = nullptr;
    this->modelAnimStates.size = 0;
  }
  this->modelAnimStates.num = 0;
  num = this->decl->models.num;
  if ( num > this->modelAnimStates.size )
    idList<idAnimator_AnimWeb::idModelAnimState,33>::Resize(this: &this->modelAnimStates, newsize: num);
  decl = this->decl;
  v12 = decl->models.num;
  if ( v12 <= this->modelAnimStates.size
    || (unsigned __int8)idList<idAnimator_AnimWeb::idModelAnimState,33>::Resize(
                          this: &this->modelAnimStates,
                          newsize: decl->models.num) != 0 )
  {
    size = this->modelAnimStates.size;
    if ( v12 < size )
      size = v12;
    this->modelAnimStates.num = size;
  }
  p_modelDecls = &this->modelDecls;
  v15 = this->decl->models.num;
  if ( v15 > this->modelDecls.size )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->modelDecls, newsize: v15);
  v16 = this->decl;
  v17 = v16->models.num;
  if ( v17 <= this->modelDecls.size
    || idList<idNavSpline *,5>::Resize(
         this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->modelDecls,
         newsize: v16->models.num) )
  {
    v18 = this->modelDecls.size;
    if ( v17 < v18 )
      v18 = v17;
    this->modelDecls.num = v18;
  }
  if ( this->modelAnimStates.num > 0 )
  {
    do
    {
      p_modelDecls->list[v9] = this->decl->models.list[(__int16)v9];
      if ( v9 == 0 && declMD6Model0 != nullptr )
        *p_modelDecls->list = declMD6Model0;
      idAnimator_AnimWeb::idModelAnimState::SetDecl(
        this: &p_modelAnimStates->list[v9],
        decl: this->decl,
        web: this,
        modelIndex: (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)(__int16)v9,
        ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz);
      ++v9;
    }
    while ( v9 < this->modelAnimStates.num );
  }
  idList<idAnimWebScalar,32>::Resize(this: (idList<idAnimWebScalar,5> *)&this->scalars, newsize: this->scalars.num);
  v19 = this->decl;
  this->declChangeId = v19->changeId;
  if ( v19->nodes.num <= 0 )
    idLib::Error(fmt: "AnimWeb '%s' has no nodes. It may be defaulted.", v19->name.str);
  if ( v25.logIndex >= 0 )
  {
    pLog = v25.pLog;
    v21 = &v25.pLog->logEntries.list[v25.logIndex];
    v22 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v21->totalTicks;
    HIDWORD(totalTicks) = v21->parent;
    LODWORD(v24) = v22 - totalTicks;
    v21->totalTicks = v24;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// $LN110
// EA  : 0x826D8C48
// RVA : 0x006D8C48
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _LN110()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$264244
// EA  : 0x826D8C70
// RVA : 0x006D8C70
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_264244()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// ?InitWeb@idAnimator_AnimWeb@@QAAXABVidAnimatorParms_AnimWeb@@@Z
// EA  : 0x826D8CA0
// RVA : 0x006D8CA0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::InitWeb(idAnimator_AnimWeb *this, const idAnimatorParms_AnimWeb *parms)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  __int16 v6; // r8
  const idDeclMD6 *decl; // r27
  idAnimWebEventHandler_Zion_vtbl *v8; // r10
  idList<idAnimWebScalar,32> *Scalars; // r3
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r4
  int curTime; // r5
  unsigned __int16 v17; // [sp+50h] [-50h] BYREF
  idPLogScope v18[9]; // [sp+58h] [-48h] BYREF

  RD_EventBegin(name: "idAnimator_AnimWeb::InitWeb");
  LODWORD(v4) = "idAnimator_AnimWeb::InitWeb";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: v18, pl: &pLog, gMask: v4, label: v5);
  idAnimator_AnimWeb::Free(this);
  v6 = idAnimator_AnimWeb::curAnimWebHandle;
  decl = parms->animStack->treeAnimator->decl;
  ++idAnimator_AnimWeb::curAnimWebHandle;
  this->handle.value = v6;
  if ( (unsigned __int16)idAnimator_AnimWeb::curAnimWebHandle == 0xFFFF )
    idAnimator_AnimWeb::curAnimWebHandle = 0;
  v8 = this->eventHandler.__vftable;
  this->md6Allocator = &parms->animStack->md6Allocator;
  v8->ClearEvents(this: &this->eventHandler);
  Scalars = idDeclAnimWeb::GetScalars(this: parms->webDecl);
  idList<idAnimWebScalar,5>::operator=(this: &this->scalars, other: (const idList<idAnimWebScalar,33> *)Scalars);
  this->InternalInitWeb(this);
  idAnimWebBlendEquation::AllocateUndeclaredScalars(
    scalars: (idList<idAnimWebScalar,5> *)&this->scalars,
    block: &this->scalarMem);
  idAnimator_AnimWeb::SetDecl(this, decl_: parms->webDecl, declMD6Model0: decl);
  idDeclAnimWeb::GetNodeIndexForName(
    this: (idDeclAnimWeb *)&v17,
    result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->decl,
    subWebName: parms->initialSubWebName.data,
    stateName: parms->initialStateName.data);
  v15 = v17;
  if ( (v17 & 0x8000u) != 0 )
  {
    idLib::Warning(
      fmt: "(%s) Initial node '%s/%s' does not exist!",
      this->decl->name.str,
      parms->initialSubWebName.data,
      parms->initialStateName.data);
    v15 = -1;
    curTime = 0;
  }
  else
  {
    curTime = parms->curTime;
  }
  idAnimator_AnimWeb::SetCurNode(
    this,
    nodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v15,
    curTime,
    a4: v14,
    a5: v13,
    a6: v12,
    a7: v11,
    a8: v10);
  this->md6Allocator->Condense(this: this->md6Allocator);
  idPLogScope::~idPLogScope(this: v18);
  RD_EventEnd();
}


// ========================================================================
// __unwind$264491
// EA  : 0x826D8E0C
// RVA : 0x006D8E0C
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_264491()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$264492
// EA  : 0x826D8E34
// RVA : 0x006D8E34
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_264492()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}


// ========================================================================
// ?ChangeState@idAnimator_AnimWeb@@QAA?AW4awPathResult_t@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@W4interruptPath_t@@W4interruptBlend_t@@H@Z
// EA  : 0x826D8E68
// RVA : 0x006D8E68
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::ChangeState(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex,
        interruptPath_t interruptPath_,
        interruptBlend_t interruptBlend_,
        int blendEventMask_)
{
  const idDeclAnimWeb *decl; // r3
  __int16 v9; // r28
  int v13; // r29
  const char **p_str; // r27
  const char *str; // r30
  const char *StateName; // r3
  const idDeclAnimWeb *v18; // r3
  const char *v19; // r30
  const char *v20; // r29
  const char *v21; // r3
  idDeclAnimWebNode *v22; // r27
  BOOL clearEventsOnStateChanges; // r10
  _WORD *v24; // r11
  int i; // ctr
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *value; // r6
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v27; // r5
  const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *v28; // r4
  int v29; // r11
  idDeclAnimWebNode *v30; // r3
  idDeclAnimWebNode *v31; // r29
  __int64 v32; // r8
  __int64 v33; // r10
  __int64 v34; // r6
  va *v35; // r3
  int v36; // r11
  const idDeclAnimWeb *v37; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v38; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v39; // r28
  const char *v40; // r27
  const char *v41; // r26
  const char *SubWebName; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v43; // r4
  const char *v44; // r29
  const char *v45; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v46; // r4
  const char *v47; // r28
  const char *v48; // r3
  int v49; // [sp+8h] [-1138h]
  int v50; // [sp+Ch] [-1134h]
  int v51; // [sp+10h] [-1130h]
  int v52; // [sp+14h] [-112Ch]
  int v53; // [sp+18h] [-1128h]
  int v54; // [sp+1Ch] [-1124h]
  idDeclAnimWeb v55[15]; // [sp+50h] [-10F0h] BYREF

  decl = this->decl;
  v9 = (__int16)stateIndex;
  if ( decl == nullptr )
    return 0;
  v13 = (__int16)stateIndex;
  if ( (__int16)stateIndex < 0
    || (__int16)stateIndex >= decl->states.num
    || (p_str = &decl->states.list[(__int16)stateIndex].name.str) == nullptr )
  {
    str = decl->name.str;
    StateName = idDeclAnimWeb::GetStateName(this: decl, index: stateIndex);
    idLib::Warning(fmt: "Id %d, '%s', is not a valid destination state in web %s", v13, StateName, str);
    return 0;
  }
  idDeclAnimWeb::FindNodeIndex(
    this: v55,
    result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)decl,
    subWebIndex,
    stateIndex);
  if ( SHIWORD(v55[0].__vftable) >= 0 )
  {
    v22 = nullptr;
    if ( SHIWORD(v55[0].__vftable) == this->curNodeIndex.value )
    {
      this->destSubWebIndex.value = -1;
      this->destStateIndices.numStates = 0;
      this->viaStateIndices.numStates = 0;
      this->viaSubWebIndex.value = -1;
      this->otherSubWebIndex.value = -1;
      this->curEdgeNodeIndex.value = -1;
      this->curEdgeIndex = -1;
      this->curPath.cost = 0x7FFFFFFF;
      this->curPath.num = 0;
      this->pathIndex = -1;
      this->forcedEdge.destNodeIndex.value = -1;
      this->forcedEdge.destSubWebIndex.value = -1;
      v55[0].__vftable = (idDeclAnimWeb_vtbl *)&this->curPath;
      return 2;
    }
    else
    {
      this->blendEventMask = blendEventMask_;
      this->interruptPath = interruptPath_;
      this->interruptBlend = interruptBlend_;
      this->destStateIndices.numStates = 1;
      this->destStateIndices.stateIndex[0].value = v9;
      clearEventsOnStateChanges = this->clearEventsOnStateChanges;
      this->destSubWebIndex.value = (__int16)subWebIndex;
      this->viaStateIndices.numStates = 0;
      this->viaSubWebIndex.value = -1;
      this->otherSubWebIndex.value = -1;
      this->forcedEdge.destNodeIndex.value = -1;
      this->forcedEdge.destSubWebIndex.value = -1;
      if ( clearEventsOnStateChanges )
        this->eventHandler.ClearEvents(this: &this->eventHandler);
      if ( anim_verifyPaths.valueInteger > 0 )
      {
        v24 = (_WORD *)&v55[0].subWebs.num + 1;
        for ( i = 32; i != 0; --i )
          *++v24 = -1;
        v55[0].edgeCache.size = 0;
        value = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value;
        v27 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->destStateIndices.stateIndex[0].value;
        v28 = (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)this->curNodeIndex.value;
        *(_DWORD *)&v55[0].edgeCache.granularity = 0x7FFFFFFF;
        if ( (unsigned __int8)idAnimator_AnimWeb::FindPath(
                                this,
                                startNodeIndex: v28,
                                destStateIndex_: v27,
                                destSubWebIndex_: value,
                                otherSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)0xFFFFFFFF,
                                path: (idAnimWebRoute *)&v55[0].subWebs.size) == 0 )
        {
          v29 = this->curNodeIndex.value;
          v30 = v29 == -1 ? nullptr : this->decl->nodes.list[v29];
          v31 = SHIWORD(v55[0].__vftable) == -1 ? nullptr : this->decl->nodes.list[SHIWORD(v55[0].__vftable)];
          if ( v30 != nullptr && v31 != nullptr )
          {
            v55[0].resourceListPtr = nullptr;
            HIBYTE(v55[0].staleCount) = 0;
            v55[0].networkID = 20;
            v55[0].resourceError = (const char *)&v55[0].staleCount;
            idDeclAnimWebNode::GetName(this: v30, web: this->decl, name: (idStr *)&v55[0].resourceListPtr);
            v55[0].nodes.list = (idDeclAnimWebNode **)20;
            v55[0].declSource = (idDeclSource *)&v55[0].nodes.num;
            *(_DWORD *)&v55[0].programaticallyDefined = 0;
            HIBYTE(v55[0].nodes.num) = 0;
            idDeclAnimWebNode::GetName(this: v31, web: this->decl, name: (idStr *)&v55[0].programaticallyDefined);
            LODWORD(v32) = this->decl;
            HIDWORD(v33) = "_AI_OBSTACLE";
            HIDWORD(v32) = v55[0].declSource;
            LODWORD(v34) = v55[0].resourceError;
            HIDWORD(v34) = *(_DWORD *)(v32 + 8);
            v35 = va::va(
                    this: (va *)&v55[0].nodeCache.size,
                    fmt: "('%s') No path exists from '%s' to '%s'",
                    a3: v34,
                    a4: v32,
                    a5: v33,
                    a6: v49,
                    a7: v50,
                    a8: v51,
                    a9: v52,
                    a10: v53,
                    a11: v54);
            idLib::Warning(fmt: v35->buffer);
            idStr::FreeData(this: (idStr *)&v55[0].programaticallyDefined);
            idStr::FreeData(this: (idStr *)&v55[0].resourceListPtr);
          }
        }
      }
      if ( this->debug )
      {
        v36 = this->curNodeIndex.value;
        if ( v36 != -1 )
          v22 = this->decl->nodes.list[v36];
        v37 = this->decl;
        v38 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v22->states.stateIndex[0].value;
        v39 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v22->subWebIndex.value;
        v40 = v37->name.str;
        v41 = idDeclAnimWeb::GetStateName(
                this: v37,
                index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->destStateIndices.stateIndex[0].value);
        SubWebName = idDeclAnimWeb::GetSubWebName(
                       this: this->decl,
                       index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value);
        v43 = v38;
        v44 = SubWebName;
        v45 = idDeclAnimWeb::GetStateName(this: this->decl, index: v43);
        v46 = v39;
        v47 = v45;
        v48 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v46);
        idLib::Printf(fmt: "('%s') ChangeState from %s/%s to %s/%s\n", v40, v48, v47, v44, v41);
      }
      return 1;
    }
  }
  else
  {
    v18 = this->decl;
    v19 = *p_str;
    v20 = v18->name.str;
    v21 = idDeclAnimWeb::GetSubWebName(this: v18, index: subWebIndex);
    idLib::Warning(fmt: "Sub-web '%s' does not contain a node with state '%s'. %s", v21, v19, v20);
    return 0;
  }
}


// ========================================================================
// __unwind$264585
// EA  : 0x826D91E0
// RVA : 0x006D91E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_264585()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4416 + 96));
}


// ========================================================================
// __unwind$264586
// EA  : 0x826D9208
// RVA : 0x006D9208
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_264586()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4416 + 128));
}


// ========================================================================
// ?ChangeState@idAnimator_AnimWeb@@QAA?AW4awPathResult_t@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@0W4interruptPath_t@@W4interruptBlend_t@@H@Z
// EA  : 0x826D9238
// RVA : 0x006D9238
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::ChangeState(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *otherSubWebIndex_,
        interruptPath_t interruptPath_,
        interruptBlend_t interruptBlend_,
        int blendEventMask_)
{
  int v7; // r29
  const idDeclAnimWeb *decl; // r3
  __int16 v11; // r28
  const char **p_str; // r26
  const char *v17; // r30
  const char *v18; // r3
  const idDeclAnimWeb *v20; // r3
  const char *v21; // r30
  const char *v22; // r29
  const char *v23; // r3
  const char *v24; // r3
  idDeclAnimWebNode *v25; // r26
  BOOL clearEventsOnStateChanges; // r10
  _WORD *v27; // r11
  int i; // ctr
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *value; // r7
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v30; // r6
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v31; // r5
  int v32; // r11
  idDeclAnimWebNode *v33; // r3
  idDeclAnimWebNode *v34; // r29
  __int64 v35; // r8
  __int64 v36; // r10
  __int64 v37; // r6
  va *v38; // r3
  int v39; // r11
  const idDeclAnimWeb *v40; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v41; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v42; // r28
  const char *str; // r27
  const char *StateName; // r26
  const char *SubWebName; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v46; // r4
  const char *v47; // r29
  const char *v48; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v49; // r4
  const char *v50; // r28
  const char *v51; // r3
  int v52; // [sp+8h] [-1148h]
  int v53; // [sp+Ch] [-1144h]
  int v54; // [sp+10h] [-1140h]
  int v55; // [sp+14h] [-113Ch]
  int v56; // [sp+18h] [-1138h]
  int v57; // [sp+1Ch] [-1134h]
  idDeclAnimWeb v58[15]; // [sp+50h] [-1100h] BYREF

  v7 = (__int16)stateIndex;
  decl = this->decl;
  v11 = (__int16)stateIndex;
  if ( (__int16)stateIndex >= 0
    && (__int16)stateIndex < decl->states.num
    && (p_str = &decl->states.list[(__int16)stateIndex].name.str) != nullptr )
  {
    idDeclAnimWeb::FindNodeIndex(
      this: v58,
      result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)decl,
      subWebIndex,
      stateIndex);
    if ( SHIWORD(v58[0].__vftable) >= 0 )
    {
      if ( (__int16)otherSubWebIndex_ >= 0 )
      {
        v25 = nullptr;
        if ( SHIWORD(v58[0].__vftable) == this->curNodeIndex.value )
        {
          this->destSubWebIndex.value = -1;
          this->destStateIndices.numStates = 0;
          this->viaStateIndices.numStates = 0;
          this->viaSubWebIndex.value = -1;
          this->otherSubWebIndex.value = -1;
          this->curEdgeNodeIndex.value = -1;
          this->curEdgeIndex = -1;
          this->curPath.cost = 0x7FFFFFFF;
          this->curPath.num = 0;
          this->pathIndex = -1;
          this->forcedEdge.destNodeIndex.value = -1;
          this->forcedEdge.destSubWebIndex.value = -1;
          v58[0].__vftable = (idDeclAnimWeb_vtbl *)&this->curPath;
          return 2;
        }
        else
        {
          this->blendEventMask = blendEventMask_;
          this->interruptPath = interruptPath_;
          this->interruptBlend = interruptBlend_;
          this->destStateIndices.numStates = 1;
          this->destStateIndices.stateIndex[0].value = v11;
          clearEventsOnStateChanges = this->clearEventsOnStateChanges;
          this->destSubWebIndex.value = (__int16)subWebIndex;
          this->viaStateIndices.numStates = 0;
          this->viaSubWebIndex.value = -1;
          this->otherSubWebIndex.value = (__int16)otherSubWebIndex_;
          this->forcedEdge.destNodeIndex.value = -1;
          this->forcedEdge.destSubWebIndex.value = -1;
          if ( clearEventsOnStateChanges )
            this->eventHandler.ClearEvents(this: &this->eventHandler);
          if ( anim_verifyPaths.valueInteger > 0 )
          {
            v27 = (_WORD *)&v58[0].subWebs.num + 1;
            for ( i = 32; i != 0; --i )
              *++v27 = -1;
            v58[0].edgeCache.size = 0;
            value = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->otherSubWebIndex.value;
            v30 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value;
            v31 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->destStateIndices.stateIndex[0].value;
            *(_DWORD *)&v58[0].edgeCache.granularity = 0x7FFFFFFF;
            if ( (unsigned __int8)idAnimator_AnimWeb::FindPath(
                                    this,
                                    startNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)this->curNodeIndex.value,
                                    destStateIndex_: v31,
                                    destSubWebIndex_: v30,
                                    otherSubWebIndex: value,
                                    path: (idAnimWebRoute *)&v58[0].subWebs.size) == 0 )
            {
              v32 = this->curNodeIndex.value;
              v33 = v32 == -1 ? nullptr : this->decl->nodes.list[v32];
              v34 = SHIWORD(v58[0].__vftable) == -1 ? nullptr : this->decl->nodes.list[SHIWORD(v58[0].__vftable)];
              if ( v33 != nullptr && v34 != nullptr )
              {
                v58[0].resourceListPtr = nullptr;
                HIBYTE(v58[0].staleCount) = 0;
                v58[0].networkID = 20;
                v58[0].resourceError = (const char *)&v58[0].staleCount;
                idDeclAnimWebNode::GetName(this: v33, web: this->decl, name: (idStr *)&v58[0].resourceListPtr);
                v58[0].nodes.list = (idDeclAnimWebNode **)20;
                v58[0].declSource = (idDeclSource *)&v58[0].nodes.num;
                *(_DWORD *)&v58[0].programaticallyDefined = 0;
                HIBYTE(v58[0].nodes.num) = 0;
                idDeclAnimWebNode::GetName(this: v34, web: this->decl, name: (idStr *)&v58[0].programaticallyDefined);
                LODWORD(v35) = this->decl;
                HIDWORD(v36) = "_AI_OBSTACLE";
                HIDWORD(v35) = v58[0].declSource;
                LODWORD(v37) = v58[0].resourceError;
                HIDWORD(v37) = *(_DWORD *)(v35 + 8);
                v38 = va::va(
                        this: (va *)&v58[0].nodeCache.size,
                        fmt: "(%s) No path exists from '%s' to '%s'",
                        a3: v37,
                        a4: v35,
                        a5: v36,
                        a6: v52,
                        a7: v53,
                        a8: v54,
                        a9: v55,
                        a10: v56,
                        a11: v57);
                idLib::Warning(fmt: v38->buffer);
                idStr::FreeData(this: (idStr *)&v58[0].programaticallyDefined);
                idStr::FreeData(this: (idStr *)&v58[0].resourceListPtr);
              }
            }
          }
          if ( this->debug )
          {
            v39 = this->curNodeIndex.value;
            if ( v39 != -1 )
              v25 = this->decl->nodes.list[v39];
            v40 = this->decl;
            v41 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v25->states.stateIndex[0].value;
            v42 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v25->subWebIndex.value;
            str = v40->name.str;
            StateName = idDeclAnimWeb::GetStateName(
                          this: v40,
                          index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->destStateIndices.stateIndex[0].value);
            SubWebName = idDeclAnimWeb::GetSubWebName(
                           this: this->decl,
                           index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value);
            v46 = v41;
            v47 = SubWebName;
            v48 = idDeclAnimWeb::GetStateName(this: this->decl, index: v46);
            v49 = v42;
            v50 = v48;
            v51 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v49);
            idLib::Printf(fmt: "animWeb '%s' ChangeState from %s/%s to %s/%s\n", str, v51, v50, v47, StateName);
          }
          return 1;
        }
      }
      else
      {
        v24 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: otherSubWebIndex_);
        idLib::Warning(fmt: "Sub-web '%s' is not a valid other subweb ", v24);
        return 0;
      }
    }
    else
    {
      v20 = this->decl;
      v21 = *p_str;
      v22 = v20->name.str;
      v23 = idDeclAnimWeb::GetSubWebName(this: v20, index: subWebIndex);
      idLib::Warning(fmt: "Sub-web '%s' does not contain a node with state '%s'. %s", v23, v21, v22);
      return 0;
    }
  }
  else
  {
    v17 = decl->name.str;
    v18 = idDeclAnimWeb::GetStateName(this: decl, index: stateIndex);
    idLib::Warning(fmt: "Id %d, '%s', is not a valid destination state in web %s", v7, v18, v17);
    return 0;
  }
}


// ========================================================================
// __unwind$264949
// EA  : 0x826D95D8
// RVA : 0x006D95D8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_264949()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4432 + 96));
}


// ========================================================================
// __unwind$264950
// EA  : 0x826D9600
// RVA : 0x006D9600
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_264950()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4432 + 128));
}


// ========================================================================
// ?ChangeStateVia@idAnimator_AnimWeb@@QAA?AW4awPathResult_t@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@01W4interruptPath_t@@W4interruptBlend_t@@H@Z
// EA  : 0x826D9630
// RVA : 0x006D9630
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::ChangeStateVia(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex_,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex_,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *_viaSubWebIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *_viaStateIndex,
        interruptPath_t interruptPath_,
        interruptBlend_t interruptBlend_,
        int blendEventMask_)
{
  const idDeclAnimWeb *decl; // r3
  __int16 v13; // r26
  int value; // r11
  idDeclAnimWebNode *v18; // r11
  __int16 v19; // r10
  __int16 v20; // r11
  const char **p_str; // r23
  const char *str; // r30
  const char *StateName; // r3
  const char **v25; // r28
  const char *v26; // r30
  const char *v27; // r3
  const idDeclAnimWeb *v28; // r3
  const char *v29; // r30
  const char *v30; // r29
  const char *v31; // r3
  const idDeclAnimWeb *v32; // r3
  const char *v33; // r30
  const char *v34; // r29
  const char *v35; // r3
  BOOL clearEventsOnStateChanges; // r11
  _WORD *v37; // r11
  int i; // ctr
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v39; // r7
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v40; // r6
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v41; // r5
  char Path; // r29
  char v43; // r3
  char v44; // r24
  int v45; // r11
  idDeclAnimWebNode *v46; // r3
  idDeclAnimWebNode *v47; // r27
  idDeclAnimWebNode *v48; // r28
  __int64 v49; // r6
  va *v50; // r3
  __int64 v51; // r10
  __int64 v52; // r6
  int v53; // r11
  idDeclAnimWebNode *v54; // r11
  const idDeclAnimWeb *v55; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v56; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v57; // r28
  const char *v58; // r27
  const char *v59; // r26
  const char *SubWebName; // r25
  const char *v61; // r24
  const char *v62; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v63; // r4
  const char *v64; // r29
  const char *v65; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v66; // r4
  const char *v67; // r28
  const char *v68; // r3
  int v69; // [sp+8h] [-1188h]
  int v70; // [sp+Ch] [-1184h]
  int v71; // [sp+10h] [-1180h]
  int v72; // [sp+14h] [-117Ch]
  int v73; // [sp+18h] [-1178h]
  int v74; // [sp+1Ch] [-1174h]
  idDeclAnimWeb v75; // [sp+60h] [-1130h] BYREF

  decl = this->decl;
  v13 = (__int16)_viaStateIndex;
  if ( decl == nullptr )
    return 0;
  value = this->curNodeIndex.value;
  if ( value != -1 )
  {
    v18 = decl->nodes.list[value];
    if ( v18 != nullptr )
    {
      v19 = v18->subWebIndex.value;
      v20 = v18->states.stateIndex[0].value;
      if ( v19 == (__int16)_viaSubWebIndex && v20 == (__int16)_viaStateIndex )
        return idAnimator_AnimWeb::ChangeState(
                 this,
                 subWebIndex: subWebIndex_,
                 stateIndex: stateIndex_,
                 interruptPath_,
                 interruptBlend_,
                 blendEventMask_);
    }
  }
  if ( (__int16)stateIndex_ < 0
    || (__int16)stateIndex_ >= decl->states.num
    || (p_str = &decl->states.list[(__int16)stateIndex_].name.str) == nullptr )
  {
    str = decl->name.str;
    StateName = idDeclAnimWeb::GetStateName(this: decl, index: stateIndex_);
    idLib::Warning(fmt: "Id %d, '%s', is not a valid destination state in web %s", (__int16)stateIndex_, StateName, str);
    return 0;
  }
  if ( (__int16)_viaStateIndex >= 0
    && (__int16)_viaStateIndex < decl->states.num
    && (v25 = &decl->states.list[(__int16)_viaStateIndex].name.str) != nullptr )
  {
    idDeclAnimWeb::FindNodeIndex(
      this: &v75,
      result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)decl,
      subWebIndex: _viaSubWebIndex,
      stateIndex: _viaStateIndex);
    if ( SHIWORD(v75.__vftable) >= 0 )
    {
      idDeclAnimWeb::FindNodeIndex(
        this: (idDeclAnimWeb *)((char *)&v75.__vftable + 2),
        result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this->decl,
        subWebIndex: subWebIndex_,
        stateIndex: stateIndex_);
      if ( SLOWORD(v75.__vftable) >= 0 )
      {
        this->blendEventMask = blendEventMask_;
        this->destStateIndices.numStates = 1;
        this->destStateIndices.stateIndex[0].value = (__int16)stateIndex_;
        this->viaStateIndices.numStates = 1;
        this->destSubWebIndex.value = (__int16)subWebIndex_;
        this->viaStateIndices.stateIndex[0].value = v13;
        clearEventsOnStateChanges = this->clearEventsOnStateChanges;
        this->viaSubWebIndex.value = (__int16)_viaSubWebIndex;
        this->interruptPath = interruptPath_;
        this->interruptBlend = interruptBlend_;
        this->otherSubWebIndex.value = -1;
        this->forcedEdge.destNodeIndex.value = -1;
        this->forcedEdge.destSubWebIndex.value = -1;
        if ( clearEventsOnStateChanges )
          this->eventHandler.ClearEvents(this: &this->eventHandler);
        if ( anim_verifyPaths.valueInteger > 0 )
        {
          v37 = (_WORD *)&v75.models.num + 1;
          for ( i = 32; i != 0; --i )
            *++v37 = -1;
          v75.scalars.size = 0;
          v39 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value;
          v40 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->viaSubWebIndex.value;
          v41 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->viaStateIndices.stateIndex[0].value;
          *(_DWORD *)&v75.scalars.granularity = 0x7FFFFFFF;
          Path = idAnimator_AnimWeb::FindPath(
                   this,
                   startNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)this->curNodeIndex.value,
                   destStateIndex_: v41,
                   destSubWebIndex_: v40,
                   otherSubWebIndex: v39,
                   path: (idAnimWebRoute *)&v75.models.size);
          v43 = idAnimator_AnimWeb::FindPath(
                  this,
                  startNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)HIWORD(v75.__vftable),
                  destStateIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->destStateIndices.stateIndex[0].value,
                  destSubWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value,
                  otherSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)0xFFFFFFFF,
                  path: (idAnimWebRoute *)&v75.models.size);
          v44 = v43;
          if ( Path == 0 || v43 == 0 )
          {
            v45 = this->curNodeIndex.value;
            v46 = v45 == -1 ? nullptr : this->decl->nodes.list[v45];
            v47 = SHIWORD(v75.__vftable) == -1 ? nullptr : this->decl->nodes.list[SHIWORD(v75.__vftable)];
            v48 = SLOWORD(v75.__vftable) == -1 ? nullptr : this->decl->nodes.list[SLOWORD(v75.__vftable)];
            if ( v46 != nullptr && v47 != nullptr && v48 != nullptr )
            {
              *(_DWORD *)&v75.programaticallyDefined = 0;
              HIBYTE(v75.nodes.num) = 0;
              v75.nodes.list = (idDeclAnimWebNode **)20;
              v75.declSource = (idDeclSource *)&v75.nodes.num;
              idDeclAnimWebNode::GetName(this: v46, web: this->decl, name: (idStr *)&v75.programaticallyDefined);
              v75.networkID = 20;
              v75.resourceError = (const char *)&v75.staleCount;
              v75.resourceListPtr = nullptr;
              HIBYTE(v75.staleCount) = 0;
              idDeclAnimWebNode::GetName(this: v47, web: this->decl, name: (idStr *)&v75.resourceListPtr);
              v75.states.list = (idDeclAnimWeb::idStateInfo *)20;
              *(_DWORD *)&v75.subWebs.granularity = &v75.states.num;
              v75.subWebs.size = 0;
              HIBYTE(v75.states.num) = 0;
              idDeclAnimWebNode::GetName(this: v48, web: this->decl, name: (idStr *)&v75.subWebs.size);
              if ( Path != 0 || v44 != 0 )
              {
                LODWORD(v51) = v75.resourceError;
                if ( Path != 0 )
                  LODWORD(v51) = *(_DWORD *)&v75.subWebs.granularity;
                LODWORD(v52) = v75.declSource;
                HIDWORD(v51) = v75.declSource;
                if ( Path != 0 )
                  HIDWORD(v51) = v75.resourceError;
                HIDWORD(v52) = this->decl->name.str;
                v50 = va::va(
                        this: (va *)&v75.editorModels.size,
                        fmt: "(%s) No path (%s -> %s -> %s) exists from '%s' to '%s'",
                        a3: v52,
                        a4: __SPAIR64__((unsigned int)v75.resourceError, *(unsigned int *)&v75.subWebs.granularity),
                        a5: v51,
                        a6: v69,
                        a7: v70,
                        a8: v71,
                        a9: v72,
                        a10: v73,
                        a11: v74);
              }
              else
              {
                LODWORD(v49) = v75.declSource;
                HIDWORD(v49) = this->decl->name.str;
                v50 = va::va(
                        this: (va *)&v75.editorModels.size,
                        fmt: "(%s) No path (%s -> %s -> %s) exists from '%s' to '%s' or '%s' to '%s'",
                        a3: v49,
                        a4: __SPAIR64__((unsigned int)v75.resourceError, *(unsigned int *)&v75.subWebs.granularity),
                        a5: __SPAIR64__((unsigned int)v75.declSource, (unsigned int)v75.resourceError),
                        a6: v69,
                        a7: v70,
                        a8: v71,
                        a9: v72,
                        a10: v73,
                        a11: v74);
              }
              idLib::Warning(fmt: v50->buffer);
              idStr::FreeData(this: (idStr *)&v75.subWebs.size);
              idStr::FreeData(this: (idStr *)&v75.resourceListPtr);
              idStr::FreeData(this: (idStr *)&v75.programaticallyDefined);
            }
          }
        }
        if ( this->debug )
        {
          v53 = this->curNodeIndex.value;
          if ( v53 == -1 )
            v54 = nullptr;
          else
            v54 = this->decl->nodes.list[v53];
          v55 = this->decl;
          v56 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v54->states.stateIndex[0].value;
          v57 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v54->subWebIndex.value;
          v58 = v55->name.str;
          v59 = idDeclAnimWeb::GetStateName(
                  this: v55,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->viaStateIndices.stateIndex[0].value);
          SubWebName = idDeclAnimWeb::GetSubWebName(
                         this: this->decl,
                         index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->viaSubWebIndex.value);
          v61 = idDeclAnimWeb::GetStateName(
                  this: this->decl,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->destStateIndices.stateIndex[0].value);
          v62 = idDeclAnimWeb::GetSubWebName(
                  this: this->decl,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value);
          v63 = v56;
          v64 = v62;
          v65 = idDeclAnimWeb::GetStateName(this: this->decl, index: v63);
          v66 = v57;
          v67 = v65;
          v68 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v66);
          idLib::Printf(
            fmt: "animWeb '%s' ChangeStateVia from %s/%s to %s/%s, thru %s/%s\n",
            v58,
            v68,
            v67,
            v64,
            v61,
            SubWebName,
            v59);
        }
        return 1;
      }
      else
      {
        v32 = this->decl;
        v33 = *p_str;
        v34 = v32->name.str;
        v35 = idDeclAnimWeb::GetSubWebName(this: v32, index: subWebIndex_);
        idLib::Warning(fmt: "(%s) Sub-web '%s' does not contain a node with state '%s'", v34, v35, v33);
        return 0;
      }
    }
    else
    {
      v28 = this->decl;
      v29 = *v25;
      v30 = v28->name.str;
      v31 = idDeclAnimWeb::GetSubWebName(this: v28, index: _viaSubWebIndex);
      idLib::Warning(fmt: "(%s) Sub-web '%s' does not contain a node with state '%s'", v30, v31, v29);
      return 0;
    }
  }
  else
  {
    v26 = decl->name.str;
    v27 = idDeclAnimWeb::GetStateName(this: decl, index: _viaStateIndex);
    idLib::Warning(fmt: "Id %d, '%s', is not a valid destination state in web %s", v13, v27, v26);
    return 0;
  }
}


// ========================================================================
// __unwind$265756
// EA  : 0x826D9B9C
// RVA : 0x006D9B9C
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_265756()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4496 + 144));
}


// ========================================================================
// __unwind$265757
// EA  : 0x826D9BC4
// RVA : 0x006D9BC4
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_265757()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4496 + 112));
}


// ========================================================================
// __unwind$265758
// EA  : 0x826D9BEC
// RVA : 0x006D9BEC
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_265758()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4496 + 176));
}


// ========================================================================
// ?ChangeStateVia@idAnimator_AnimWeb@@QAA?AW4awPathResult_t@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@010W4interruptPath_t@@W4interruptBlend_t@@H@Z
// EA  : 0x826D9C20
// RVA : 0x006D9C20
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::ChangeStateVia(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex_,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex_,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *_viaSubWebIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *_viaStateIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *_otherSubWebIndex,
        interruptPath_t interruptPath_,
        interruptBlend_t interruptBlend_,
        int blendEventMask_,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  int value; // r11
  __int16 v33; // r26
  __int16 v34; // r20
  idDeclAnimWebNode *v37; // r11
  __int16 v38; // r10
  __int16 v39; // r11
  const idDeclAnimWeb *decl; // r3
  const char **v42; // r23
  const char *v43; // r30
  const char *v44; // r3
  const char **p_str; // r28
  const char *v46; // r30
  const char *v47; // r3
  const idDeclAnimWeb *v48; // r3
  const char *v49; // r30
  const char *v50; // r29
  const char *v51; // r3
  const idDeclAnimWeb *v52; // r3
  const char *v53; // r30
  const char *v54; // r29
  const char *v55; // r3
  BOOL clearEventsOnStateChanges; // r9
  _WORD *v57; // r11
  int i; // ctr
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v59; // r7
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v60; // r6
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v61; // r5
  char Path; // r29
  char v63; // r3
  char v64; // r24
  int v65; // r11
  idDeclAnimWebNode *v66; // r3
  idDeclAnimWebNode *v67; // r27
  idDeclAnimWebNode *v68; // r28
  __int64 v69; // r6
  va *v70; // r3
  __int64 v71; // r10
  __int64 v72; // r6
  int v73; // r11
  idDeclAnimWebNode *v74; // r11
  const idDeclAnimWeb *v75; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v76; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v77; // r28
  const char *str; // r27
  const char *StateName; // r26
  const char *SubWebName; // r25
  const char *v81; // r24
  const char *v82; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v83; // r4
  const char *v84; // r29
  const char *v85; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v86; // r4
  const char *v87; // r28
  const char *v88; // r3
  int v89; // [sp+8h] [-1188h]
  int v90; // [sp+Ch] [-1184h]
  int v91; // [sp+10h] [-1180h]
  int v92; // [sp+14h] [-117Ch]
  int v93; // [sp+18h] [-1178h]
  int v94; // [sp+1Ch] [-1174h]
  idDeclAnimWeb v95; // [sp+60h] [-1130h] BYREF

  value = this->curNodeIndex.value;
  v33 = (__int16)_viaStateIndex;
  v34 = (__int16)_otherSubWebIndex;
  if ( value != -1 )
  {
    v37 = this->decl->nodes.list[value];
    if ( v37 != nullptr )
    {
      v38 = v37->subWebIndex.value;
      v39 = v37->states.stateIndex[0].value;
      if ( v38 == (__int16)_viaSubWebIndex && v39 == (__int16)_viaStateIndex )
        return idAnimator_AnimWeb::ChangeState(
                 this,
                 subWebIndex: subWebIndex_,
                 stateIndex: stateIndex_,
                 interruptPath_,
                 interruptBlend_,
                 blendEventMask_: a28);
    }
  }
  decl = this->decl;
  if ( (__int16)stateIndex_ >= 0
    && (__int16)stateIndex_ < decl->states.num
    && (v42 = &decl->states.list[(__int16)stateIndex_].name.str) != nullptr )
  {
    if ( (__int16)_viaStateIndex >= 0
      && (__int16)_viaStateIndex < decl->states.num
      && (p_str = &decl->states.list[(__int16)_viaStateIndex].name.str) != nullptr )
    {
      idDeclAnimWeb::FindNodeIndex(
        this: &v95,
        result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this->decl,
        subWebIndex: _viaSubWebIndex,
        stateIndex: _viaStateIndex);
      if ( SHIWORD(v95.__vftable) >= 0 )
      {
        idDeclAnimWeb::FindNodeIndex(
          this: (idDeclAnimWeb *)((char *)&v95.__vftable + 2),
          result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this->decl,
          subWebIndex: subWebIndex_,
          stateIndex: stateIndex_);
        if ( SLOWORD(v95.__vftable) >= 0 )
        {
          this->destStateIndices.numStates = 1;
          this->blendEventMask = a28;
          this->destStateIndices.stateIndex[0].value = (__int16)stateIndex_;
          this->destSubWebIndex.value = (__int16)subWebIndex_;
          this->viaStateIndices.numStates = 1;
          this->viaStateIndices.stateIndex[0].value = v33;
          clearEventsOnStateChanges = this->clearEventsOnStateChanges;
          this->viaSubWebIndex.value = (__int16)_viaSubWebIndex;
          this->interruptPath = interruptPath_;
          this->interruptBlend = interruptBlend_;
          this->otherSubWebIndex.value = v34;
          this->forcedEdge.destNodeIndex.value = -1;
          this->forcedEdge.destSubWebIndex.value = -1;
          if ( clearEventsOnStateChanges )
            this->eventHandler.ClearEvents(this: &this->eventHandler);
          if ( anim_verifyPaths.valueInteger > 0 )
          {
            v57 = (_WORD *)&v95.models.num + 1;
            for ( i = 32; i != 0; --i )
              *++v57 = -1;
            v95.scalars.size = 0;
            v59 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->otherSubWebIndex.value;
            v60 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->viaSubWebIndex.value;
            v61 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->viaStateIndices.stateIndex[0].value;
            *(_DWORD *)&v95.scalars.granularity = 0x7FFFFFFF;
            Path = idAnimator_AnimWeb::FindPath(
                     this,
                     startNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)this->curNodeIndex.value,
                     destStateIndex_: v61,
                     destSubWebIndex_: v60,
                     otherSubWebIndex: v59,
                     path: (idAnimWebRoute *)&v95.models.size);
            v63 = idAnimator_AnimWeb::FindPath(
                    this,
                    startNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)HIWORD(v95.__vftable),
                    destStateIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->destStateIndices.stateIndex[0].value,
                    destSubWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value,
                    otherSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->otherSubWebIndex.value,
                    path: (idAnimWebRoute *)&v95.models.size);
            v64 = v63;
            if ( Path == 0 || v63 == 0 )
            {
              v65 = this->curNodeIndex.value;
              v66 = v65 == -1 ? nullptr : this->decl->nodes.list[v65];
              v67 = SHIWORD(v95.__vftable) == -1 ? nullptr : this->decl->nodes.list[SHIWORD(v95.__vftable)];
              v68 = SLOWORD(v95.__vftable) == -1 ? nullptr : this->decl->nodes.list[SLOWORD(v95.__vftable)];
              if ( v66 != nullptr && v67 != nullptr && v68 != nullptr )
              {
                *(_DWORD *)&v95.programaticallyDefined = 0;
                HIBYTE(v95.nodes.num) = 0;
                v95.nodes.list = (idDeclAnimWebNode **)20;
                v95.declSource = (idDeclSource *)&v95.nodes.num;
                idDeclAnimWebNode::GetName(this: v66, web: this->decl, name: (idStr *)&v95.programaticallyDefined);
                v95.networkID = 20;
                v95.resourceError = (const char *)&v95.staleCount;
                v95.resourceListPtr = nullptr;
                HIBYTE(v95.staleCount) = 0;
                idDeclAnimWebNode::GetName(this: v67, web: this->decl, name: (idStr *)&v95.resourceListPtr);
                v95.states.list = (idDeclAnimWeb::idStateInfo *)20;
                *(_DWORD *)&v95.subWebs.granularity = &v95.states.num;
                v95.subWebs.size = 0;
                HIBYTE(v95.states.num) = 0;
                idDeclAnimWebNode::GetName(this: v68, web: this->decl, name: (idStr *)&v95.subWebs.size);
                if ( Path != 0 || v64 != 0 )
                {
                  LODWORD(v71) = v95.resourceError;
                  if ( Path != 0 )
                    LODWORD(v71) = *(_DWORD *)&v95.subWebs.granularity;
                  LODWORD(v72) = v95.declSource;
                  HIDWORD(v71) = v95.declSource;
                  if ( Path != 0 )
                    HIDWORD(v71) = v95.resourceError;
                  HIDWORD(v72) = this->decl->name.str;
                  v70 = va::va(
                          this: (va *)&v95.editorModels.size,
                          fmt: "(%s) No path (%s -> %s -> %s) exists from '%s' to '%s'",
                          a3: v72,
                          a4: __SPAIR64__((unsigned int)v95.resourceError, *(unsigned int *)&v95.subWebs.granularity),
                          a5: v71,
                          a6: v89,
                          a7: v90,
                          a8: v91,
                          a9: v92,
                          a10: v93,
                          a11: v94);
                }
                else
                {
                  LODWORD(v69) = v95.declSource;
                  HIDWORD(v69) = this->decl->name.str;
                  v70 = va::va(
                          this: (va *)&v95.editorModels.size,
                          fmt: "(%s) No path (%s -> %s -> %s) exists from '%s' to '%s' or '%s' to '%s'",
                          a3: v69,
                          a4: __SPAIR64__((unsigned int)v95.resourceError, *(unsigned int *)&v95.subWebs.granularity),
                          a5: __SPAIR64__((unsigned int)v95.declSource, (unsigned int)v95.resourceError),
                          a6: v89,
                          a7: v90,
                          a8: v91,
                          a9: v92,
                          a10: v93,
                          a11: v94);
                }
                idLib::Warning(fmt: v70->buffer);
                idStr::FreeData(this: (idStr *)&v95.subWebs.size);
                idStr::FreeData(this: (idStr *)&v95.resourceListPtr);
                idStr::FreeData(this: (idStr *)&v95.programaticallyDefined);
              }
            }
          }
          if ( this->debug )
          {
            v73 = this->curNodeIndex.value;
            if ( v73 == -1 )
              v74 = nullptr;
            else
              v74 = this->decl->nodes.list[v73];
            v75 = this->decl;
            v76 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v74->states.stateIndex[0].value;
            v77 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v74->subWebIndex.value;
            str = v75->name.str;
            StateName = idDeclAnimWeb::GetStateName(
                          this: v75,
                          index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->viaStateIndices.stateIndex[0].value);
            SubWebName = idDeclAnimWeb::GetSubWebName(
                           this: this->decl,
                           index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->viaSubWebIndex.value);
            v81 = idDeclAnimWeb::GetStateName(
                    this: this->decl,
                    index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->destStateIndices.stateIndex[0].value);
            v82 = idDeclAnimWeb::GetSubWebName(
                    this: this->decl,
                    index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value);
            v83 = v76;
            v84 = v82;
            v85 = idDeclAnimWeb::GetStateName(this: this->decl, index: v83);
            v86 = v77;
            v87 = v85;
            v88 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v86);
            idLib::Printf(
              fmt: "animWeb '%s' ChangeStateVia from %s/%s to %s/%s, thru %s/%s\n",
              str,
              v88,
              v87,
              v84,
              v81,
              SubWebName,
              StateName);
          }
          return 1;
        }
        else
        {
          v52 = this->decl;
          v53 = *v42;
          v54 = v52->name.str;
          v55 = idDeclAnimWeb::GetSubWebName(this: v52, index: subWebIndex_);
          idLib::Warning(fmt: "(%s) Sub-web '%s' does not contain a node with state '%s'", v54, v55, v53);
          return 0;
        }
      }
      else
      {
        v48 = this->decl;
        v49 = *p_str;
        v50 = v48->name.str;
        v51 = idDeclAnimWeb::GetSubWebName(this: v48, index: _viaSubWebIndex);
        idLib::Warning(fmt: "(%s) Sub-web '%s' does not contain a node with state '%s'", v50, v51, v49);
        return 0;
      }
    }
    else
    {
      v46 = decl->name.str;
      v47 = idDeclAnimWeb::GetStateName(this: decl, index: _viaStateIndex);
      idLib::Warning(fmt: "Id %d, '%s', is not a valid destination state in web %s", v33, v47, v46);
      return 0;
    }
  }
  else
  {
    v43 = decl->name.str;
    v44 = idDeclAnimWeb::GetStateName(this: decl, index: stateIndex_);
    idLib::Warning(fmt: "Id %d, '%s', is not a valid destination state in web %s", (__int16)stateIndex_, v44, v43);
    return 0;
  }
}


// ========================================================================
// __unwind$266299
// EA  : 0x826DA184
// RVA : 0x006DA184
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_266299()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4496 + 144));
}


// ========================================================================
// __unwind$266300
// EA  : 0x826DA1AC
// RVA : 0x006DA1AC
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_266300()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4496 + 112));
}


// ========================================================================
// __unwind$266301
// EA  : 0x826DA1D4
// RVA : 0x006DA1D4
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_266301()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4496 + 176));
}


// ========================================================================
// ?ForceAndChangeState@idAnimator_AnimWeb@@QAA?AW4awPathResult_t@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@01ABVblendParms_t@@H@Z
// EA  : 0x826DA208
// RVA : 0x006DA208
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::ForceAndChangeState(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex2,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex2,
        const blendParms_t *blendParms,
        int blendEventMask_)
{
  const idDeclAnimWeb *decl; // r3
  __int16 v9; // r27
  int v14; // r29
  const char **p_str; // r28
  const char *str; // r30
  const char *StateName; // r3
  const idDeclAnimWeb *v19; // r3
  const char *v20; // r30
  const char *v21; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *value; // r4
  const char *v23; // r29
  const char *v24; // r30
  const char *SubWebName; // r3
  __int16 v26; // r8
  idAnimator_AnimWeb::forcedEdge_t *p_forcedEdge; // r10
  char *p_flags; // r11
  int i; // ctr
  BOOL clearEventsOnStateChanges; // r10
  _WORD *v31; // r11
  int j; // ctr
  __int16 v33; // r11
  int v34; // r11
  idDeclAnimWebNode *v35; // r3
  idDeclAnimWebNode *v36; // r29
  __int64 v37; // r8
  __int64 v38; // r10
  __int64 v39; // r6
  va *v40; // r3
  int v41; // [sp+8h] [-1138h]
  int v42; // [sp+Ch] [-1134h]
  int v43; // [sp+10h] [-1130h]
  int v44; // [sp+14h] [-112Ch]
  int v45; // [sp+18h] [-1128h]
  int v46; // [sp+1Ch] [-1124h]
  idDeclAnimWeb v47[15]; // [sp+50h] [-10F0h] BYREF

  decl = this->decl;
  v9 = (__int16)subWebIndex;
  if ( decl == nullptr )
    return 0;
  v14 = (__int16)stateIndex;
  this->curEdgeNodeIndex.value = this->curNodeIndex.value;
  if ( (__int16)stateIndex < 0
    || (__int16)stateIndex >= decl->states.num
    || (p_str = &decl->states.list[(__int16)stateIndex].name.str) == nullptr )
  {
    str = decl->name.str;
    StateName = idDeclAnimWeb::GetStateName(this: decl, index: stateIndex);
    idLib::Warning(fmt: "Id %d, '%s', is not a valid via state in web %s", v14, StateName, str);
    return 0;
  }
  idDeclAnimWeb::FindNodeIndex(
    this: (idDeclAnimWeb *)((char *)&v47[0].__vftable + 2),
    result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)decl,
    subWebIndex,
    stateIndex);
  v19 = this->decl;
  if ( SLOWORD(v47[0].__vftable) < 0 )
    goto LABEL_14;
  if ( (__int16)stateIndex2 < 0
    || (__int16)stateIndex2 >= v19->states.num
    || (p_str = &v19->states.list[(__int16)stateIndex2].name.str) == nullptr )
  {
    v20 = v19->name.str;
    v21 = idDeclAnimWeb::GetStateName(this: v19, index: stateIndex2);
    idLib::Warning(fmt: "Id %d, '%s', is not a valid destination state in web %s", (__int16)stateIndex2, v21, v20);
    return 0;
  }
  idDeclAnimWeb::FindNodeIndex(
    this: (idDeclAnimWeb *)&v47[0].trackedMemory,
    result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this->decl,
    subWebIndex: subWebIndex2,
    stateIndex: stateIndex2);
  if ( v47[0].trackedMemory < 0 )
  {
    v19 = this->decl;
LABEL_14:
    value = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value;
    v23 = *p_str;
    v24 = v19->name.str;
    SubWebName = idDeclAnimWeb::GetSubWebName(this: v19, index: value);
    idLib::Warning(fmt: "(%s) Sub-web '%s' does not contain a node with state '%s'", v24, SubWebName, v23);
    return 0;
  }
  v26 = (__int16)v47[0].__vftable;
  this->blendEventMask = blendEventMask_;
  p_forcedEdge = &this->forcedEdge;
  this->forcedEdge.destSubWebIndex.value = v9;
  p_flags = &blendParms[-1].parms.flags;
  this->forcedEdge.destNodeIndex.value = v26;
  for ( i = 5; i != 0; --i )
  {
    p_flags += 4;
    p_forcedEdge = (idAnimator_AnimWeb::forcedEdge_t *)((char *)p_forcedEdge + 4);
    *(_DWORD *)&p_forcedEdge->destNodeIndex.value = *(_DWORD *)p_flags;
  }
  this->destStateIndices.numStates = 1;
  this->destStateIndices.stateIndex[0].value = (__int16)stateIndex2;
  clearEventsOnStateChanges = this->clearEventsOnStateChanges;
  this->destSubWebIndex.value = (__int16)subWebIndex2;
  this->viaStateIndices.numStates = 0;
  this->viaSubWebIndex.value = -1;
  this->otherSubWebIndex.value = -1;
  this->interruptPath = INTR_PATH_YES;
  this->interruptBlend = INTR_BLEND_YES;
  this->skipForcedEdgeAutoPath = false;
  if ( clearEventsOnStateChanges )
    this->eventHandler.ClearEvents(this: &this->eventHandler);
  if ( anim_verifyPaths.valueInteger > 0 )
  {
    idDeclAnimWeb::FindNodeIndex(
      this: v47,
      result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this->decl,
      subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value,
      stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->destStateIndices.stateIndex[0].value);
    v31 = (_WORD *)&v47[0].subWebs.num + 1;
    for ( j = 32; j != 0; --j )
      *++v31 = -1;
    v33 = this->forcedEdge.destNodeIndex.value;
    v47[0].edgeCache.size = 0;
    *(_DWORD *)&v47[0].edgeCache.granularity = 0x7FFFFFFF;
    if ( SHIWORD(v47[0].__vftable) != v33
      && (unsigned __int8)idAnimator_AnimWeb::FindPath(
                            this,
                            startNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)v33,
                            destStateIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->destStateIndices.stateIndex[0].value,
                            destSubWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value,
                            otherSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)0xFFFFFFFF,
                            path: (idAnimWebRoute *)&v47[0].subWebs.size) == 0 )
    {
      v34 = this->curNodeIndex.value;
      if ( v34 == -1 )
        v35 = nullptr;
      else
        v35 = this->decl->nodes.list[v34];
      if ( SHIWORD(v47[0].__vftable) == -1 )
        v36 = nullptr;
      else
        v36 = this->decl->nodes.list[SHIWORD(v47[0].__vftable)];
      if ( v35 != nullptr && v36 != nullptr )
      {
        *(_DWORD *)&v47[0].programaticallyDefined = 0;
        HIBYTE(v47[0].nodes.num) = 0;
        v47[0].nodes.list = (idDeclAnimWebNode **)20;
        v47[0].declSource = (idDeclSource *)&v47[0].nodes.num;
        idDeclAnimWebNode::GetName(this: v35, web: this->decl, name: (idStr *)&v47[0].programaticallyDefined);
        v47[0].networkID = 20;
        v47[0].resourceError = (const char *)&v47[0].staleCount;
        v47[0].resourceListPtr = nullptr;
        HIBYTE(v47[0].staleCount) = 0;
        idDeclAnimWebNode::GetName(this: v36, web: this->decl, name: (idStr *)&v47[0].resourceListPtr);
        LODWORD(v37) = this->decl;
        HIDWORD(v38) = "_AI_OBSTACLE";
        HIDWORD(v37) = v47[0].resourceError;
        LODWORD(v39) = v47[0].declSource;
        HIDWORD(v39) = *(_DWORD *)(v37 + 8);
        v40 = va::va(
                this: (va *)&v47[0].nodeCache.size,
                fmt: "(%s) No path exists from '%s' to '%s'",
                a3: v39,
                a4: v37,
                a5: v38,
                a6: v41,
                a7: v42,
                a8: v43,
                a9: v44,
                a10: v45,
                a11: v46);
        idLib::Warning(fmt: v40->buffer);
        idStr::FreeData(this: (idStr *)&v47[0].resourceListPtr);
        idStr::FreeData(this: (idStr *)&v47[0].programaticallyDefined);
      }
    }
  }
  return 1;
}


// ========================================================================
// __unwind$267393
// EA  : 0x826DA56C
// RVA : 0x006DA56C
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_267393()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4416 + 128));
}


// ========================================================================
// __unwind$267394
// EA  : 0x826DA594
// RVA : 0x006DA594
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_267394()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4416 + 96));
}


// ========================================================================
// ?ForceAndChangeState@idAnimator_AnimWeb@@QAA?AW4awPathResult_t@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@010ABVblendParms_t@@H@Z
// EA  : 0x826DA5C8
// RVA : 0x006DA5C8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::ForceAndChangeState(
        idAnimator_AnimWeb *this,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex2,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex2,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *otherSubWebIndex_,
        const blendParms_t *blendParms,
        int blendEventMask_)
{
  __int16 value; // r11
  int v10; // r29
  const idDeclAnimWeb *decl; // r3
  __int16 v12; // r27
  __int16 v15; // r22
  const char **p_str; // r28
  const char *str; // r30
  const char *StateName; // r3
  const idDeclAnimWeb *v22; // r3
  const char *v23; // r30
  const char *v24; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v25; // r4
  const char *v26; // r29
  const char *v27; // r30
  const char *SubWebName; // r3
  __int16 v29; // r8
  idAnimator_AnimWeb::forcedEdge_t *p_forcedEdge; // r10
  char *p_flags; // r11
  int i; // ctr
  BOOL clearEventsOnStateChanges; // r10
  _WORD *v34; // r11
  int j; // ctr
  __int16 v36; // r11
  int v37; // r11
  idDeclAnimWebNode *v38; // r3
  idDeclAnimWebNode *v39; // r28
  __int64 v40; // r8
  __int64 v41; // r10
  __int64 v42; // r6
  va *v43; // r3
  int v44; // [sp+8h] [-1148h]
  int v45; // [sp+Ch] [-1144h]
  int v46; // [sp+10h] [-1140h]
  int v47; // [sp+14h] [-113Ch]
  int v48; // [sp+18h] [-1138h]
  int v49; // [sp+1Ch] [-1134h]
  idDeclAnimWeb v50[15]; // [sp+50h] [-1100h] BYREF

  value = this->curNodeIndex.value;
  v10 = (__int16)stateIndex;
  decl = this->decl;
  v12 = (__int16)subWebIndex;
  v15 = (__int16)otherSubWebIndex_;
  this->curEdgeNodeIndex.value = value;
  if ( (__int16)stateIndex < 0
    || (__int16)stateIndex >= decl->states.num
    || (p_str = &decl->states.list[(__int16)stateIndex].name.str) == nullptr )
  {
    str = decl->name.str;
    StateName = idDeclAnimWeb::GetStateName(this: decl, index: stateIndex);
    idLib::Warning(fmt: "Id %d, '%s', is not a valid via state in web %s", v10, StateName, str);
    return 0;
  }
  idDeclAnimWeb::FindNodeIndex(
    this: (idDeclAnimWeb *)((char *)&v50[0].__vftable + 2),
    result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)decl,
    subWebIndex,
    stateIndex);
  v22 = this->decl;
  if ( SLOWORD(v50[0].__vftable) < 0 )
    goto LABEL_12;
  if ( (__int16)stateIndex2 < 0
    || (__int16)stateIndex2 >= v22->states.num
    || (p_str = &v22->states.list[(__int16)stateIndex2].name.str) == nullptr )
  {
    v23 = v22->name.str;
    v24 = idDeclAnimWeb::GetStateName(this: v22, index: stateIndex2);
    idLib::Warning(fmt: "Id %d, '%s', is not a valid destination state in web %s", (__int16)stateIndex2, v24, v23);
    return 0;
  }
  idDeclAnimWeb::FindNodeIndex(
    this: (idDeclAnimWeb *)&v50[0].trackedMemory,
    result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this->decl,
    subWebIndex: subWebIndex2,
    stateIndex: stateIndex2);
  if ( v50[0].trackedMemory < 0 )
  {
    v22 = this->decl;
LABEL_12:
    v25 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value;
    v26 = *p_str;
    v27 = v22->name.str;
    SubWebName = idDeclAnimWeb::GetSubWebName(this: v22, index: v25);
    idLib::Warning(fmt: "(%s) Sub-web '%s' does not contain a node with state '%s'", v27, SubWebName, v26);
    return 0;
  }
  v29 = (__int16)v50[0].__vftable;
  this->blendEventMask = blendEventMask_;
  p_forcedEdge = &this->forcedEdge;
  this->forcedEdge.destSubWebIndex.value = v12;
  p_flags = &blendParms[-1].parms.flags;
  this->forcedEdge.destNodeIndex.value = v29;
  for ( i = 5; i != 0; --i )
  {
    p_flags += 4;
    p_forcedEdge = (idAnimator_AnimWeb::forcedEdge_t *)((char *)p_forcedEdge + 4);
    *(_DWORD *)&p_forcedEdge->destNodeIndex.value = *(_DWORD *)p_flags;
  }
  this->destStateIndices.numStates = 1;
  this->destStateIndices.stateIndex[0].value = (__int16)stateIndex2;
  clearEventsOnStateChanges = this->clearEventsOnStateChanges;
  this->destSubWebIndex.value = (__int16)subWebIndex2;
  this->viaStateIndices.numStates = 0;
  this->viaSubWebIndex.value = -1;
  this->otherSubWebIndex.value = v15;
  this->interruptPath = INTR_PATH_YES;
  this->interruptBlend = INTR_BLEND_YES;
  this->skipForcedEdgeAutoPath = false;
  if ( clearEventsOnStateChanges )
    this->eventHandler.ClearEvents(this: &this->eventHandler);
  if ( anim_verifyPaths.valueInteger > 0 )
  {
    idDeclAnimWeb::FindNodeIndex(
      this: v50,
      result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this->decl,
      subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value,
      stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->destStateIndices.stateIndex[0].value);
    v34 = (_WORD *)&v50[0].subWebs.num + 1;
    for ( j = 32; j != 0; --j )
      *++v34 = -1;
    v36 = this->forcedEdge.destNodeIndex.value;
    v50[0].edgeCache.size = 0;
    *(_DWORD *)&v50[0].edgeCache.granularity = 0x7FFFFFFF;
    if ( SHIWORD(v50[0].__vftable) != v36
      && (unsigned __int8)idAnimator_AnimWeb::FindPath(
                            this,
                            startNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)v36,
                            destStateIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->destStateIndices.stateIndex[0].value,
                            destSubWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->destSubWebIndex.value,
                            otherSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->otherSubWebIndex.value,
                            path: (idAnimWebRoute *)&v50[0].subWebs.size) == 0 )
    {
      v37 = this->curNodeIndex.value;
      if ( v37 == -1 )
        v38 = nullptr;
      else
        v38 = this->decl->nodes.list[v37];
      if ( SHIWORD(v50[0].__vftable) == -1 )
        v39 = nullptr;
      else
        v39 = this->decl->nodes.list[SHIWORD(v50[0].__vftable)];
      if ( v38 != nullptr && v39 != nullptr )
      {
        *(_DWORD *)&v50[0].programaticallyDefined = 0;
        HIBYTE(v50[0].nodes.num) = 0;
        v50[0].nodes.list = (idDeclAnimWebNode **)20;
        v50[0].declSource = (idDeclSource *)&v50[0].nodes.num;
        idDeclAnimWebNode::GetName(this: v38, web: this->decl, name: (idStr *)&v50[0].programaticallyDefined);
        v50[0].networkID = 20;
        v50[0].resourceError = (const char *)&v50[0].staleCount;
        v50[0].resourceListPtr = nullptr;
        HIBYTE(v50[0].staleCount) = 0;
        idDeclAnimWebNode::GetName(this: v39, web: this->decl, name: (idStr *)&v50[0].resourceListPtr);
        LODWORD(v40) = this->decl;
        HIDWORD(v41) = "_AI_OBSTACLE";
        HIDWORD(v40) = v50[0].resourceError;
        LODWORD(v42) = v50[0].declSource;
        HIDWORD(v42) = *(_DWORD *)(v40 + 8);
        v43 = va::va(
                this: (va *)&v50[0].nodeCache.size,
                fmt: "(%s) No path exists from '%s' to '%s'",
                a3: v42,
                a4: v40,
                a5: v41,
                a6: v44,
                a7: v45,
                a8: v46,
                a9: v47,
                a10: v48,
                a11: v49);
        idLib::Warning(fmt: v43->buffer);
        idStr::FreeData(this: (idStr *)&v50[0].resourceListPtr);
        idStr::FreeData(this: (idStr *)&v50[0].programaticallyDefined);
      }
    }
  }
  return 1;
}


// ========================================================================
// __unwind$267782
// EA  : 0x826DA928
// RVA : 0x006DA928
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_267782()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4432 + 128));
}


// ========================================================================
// __unwind$267783
// EA  : 0x826DA950
// RVA : 0x006DA950
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_267783()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4432 + 96));
}


// ========================================================================
// ?InternalInit@idAnimator_AnimWeb@@MAA_NABVidAnimatorParms_Base@@@Z
// EA  : 0x826DA978
// RVA : 0x006DA978
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::InternalInit(idAnimator_AnimWeb *this, const idAnimatorParms_AnimWeb *parms)
{
  this->mergeBranch = (idMD6Branch *)parms->animStack->md6Allocator.Alloc(this: &parms->animStack->md6Allocator, a2: 0);
  idAnimator_AnimWeb::InitWeb(this, parms);
  return 1;
}


// ========================================================================
// ?ChangeState@idAnimator_AnimWeb@@QAA?AW4awPathResult_t@@PBDV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@W4interruptPath_t@@W4interruptBlend_t@@H@Z
// EA  : 0x826DA9E0
// RVA : 0x006DA9E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::ChangeState(
        idAnimator_AnimWeb *this,
        const char *subWebName,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex,
        interruptPath_t interruptPath_,
        interruptBlend_t interruptBlend_,
        int blendEventMask_)
{
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *decl; // r4
  __int16 v14; // [sp+50h] [-40h] BYREF

  decl = (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->decl;
  if ( decl == nullptr )
    return 0;
  idDeclAnimWeb::GetSubWebIndexForName(this: (idDeclAnimWeb *)&v14, result: decl, subWebName);
  if ( v14 < 0 )
  {
    idLib::Warning(
      fmt: "idAnimator_AnimWeb::ChangeState - animWeb '%s' does not have a sub-web '%s'",
      this->decl->name.str,
      subWebName);
    return 0;
  }
  return idAnimator_AnimWeb::ChangeState(
           this,
           subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v14,
           stateIndex,
           interruptPath_,
           interruptBlend_,
           blendEventMask_);
}


// ========================================================================
// ?ChangeStateVia@idAnimator_AnimWeb@@QAA?AW4awPathResult_t@@PBDV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@01W4interruptPath_t@@W4interruptBlend_t@@H@Z
// EA  : 0x826DAA70
// RVA : 0x006DAA70
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::ChangeStateVia(
        idAnimator_AnimWeb *this,
        const char *subWebName,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex_,
        const char *viaSubWebName,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *_viaStateIndex,
        interruptPath_t interruptPath_,
        interruptBlend_t interruptBlend_,
        int blendEventMask_)
{
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *decl; // r4
  __int16 v18; // [sp+50h] [-50h] BYREF
  __int16 v19; // [sp+52h] [-4Eh] BYREF

  decl = (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->decl;
  if ( decl == nullptr )
    return 0;
  idDeclAnimWeb::GetSubWebIndexForName(this: (idDeclAnimWeb *)&v18, result: decl, subWebName);
  if ( v18 < 0 )
  {
    idLib::Warning(
      fmt: "idAnimator_AnimWeb::ChangeStateVia - animWeb '%s' does not have a sub-web '%s'",
      this->decl->name.str,
      subWebName);
    return 0;
  }
  idDeclAnimWeb::GetSubWebIndexForName(
    this: (idDeclAnimWeb *)&v19,
    result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->decl,
    subWebName: viaSubWebName);
  if ( v19 >= 0 )
    return idAnimator_AnimWeb::ChangeStateVia(
             this,
             subWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v18,
             stateIndex_,
             _viaSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v19,
             _viaStateIndex,
             interruptPath_,
             interruptBlend_,
             blendEventMask_);
  idLib::Warning(
    fmt: "idAnimator_AnimWeb::ChangeStateVia - animWeb '%s' does not have a sub-web '%s'",
    this->decl->name.str,
    viaSubWebName);
  return 0;
}


// ========================================================================
// ?Reinitialize@idAnimator_AnimWeb@@AAAXH@Z
// EA  : 0x826DAB58
// RVA : 0x006DAB58
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::Reinitialize(idAnimator_AnimWeb *this, int curTime)
{
  int v4; // r10
  int v5; // r9
  int v6; // r8
  int v7; // r7
  int v8; // r6
  char *str; // r3
  int v10; // r3
  char v11; // r11
  idDeclAnimWebNode *v12; // r11
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *value; // r27
  const char *SubWebName; // r3
  __int16 v15; // [sp+50h] [-40h] BYREF
  __int16 v16; // [sp+52h] [-3Eh] BYREF

  idAnimator_AnimWeb::SetDecl(this, decl_: this->decl, declMD6Model0: nullptr);
  idDeclAnimWeb::GetNodeIndexForName(
    this: (idDeclAnimWeb *)&v15,
    result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->decl,
    subWebName: this->curNodeSubWebName.str,
    stateName: this->curNodeStateName.str);
  if ( v15 >= 0 )
  {
    idAnimator_AnimWeb::SetCurNode(
      this,
      nodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)v15,
      curTime,
      a4: v8,
      a5: v7,
      a6: v6,
      a7: v5,
      a8: v4);
    str = (char *)this->destNodeStateName.str;
    if ( str == &byte_8200D768 || (v10 = idStr::Cmp(s1: str, s2: &byte_8200D768), v11 = 1, v10 == 0) )
      v11 = 0;
    if ( v11 != 0 )
    {
      idDeclAnimWeb::GetNodeIndexForName(
        this: (idDeclAnimWeb *)&v16,
        result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->decl,
        subWebName: this->destNodeSubWebName.str,
        stateName: this->destNodeStateName.str);
      if ( v16 >= 0 )
      {
        if ( v16 == -1 )
          v12 = nullptr;
        else
          v12 = this->decl->nodes.list[v16];
        value = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v12->states.stateIndex[0].value;
        SubWebName = idDeclAnimWeb::GetSubWebName(
                       this: this->decl,
                       index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v12->subWebIndex.value);
        idAnimator_AnimWeb::ChangeState(
          this,
          subWebName: SubWebName,
          stateIndex: value,
          interruptPath_: INTR_PATH_YES,
          interruptBlend_: INTR_BLEND_YES,
          blendEventMask_: 0);
      }
    }
  }
  else
  {
    idAnimator_AnimWeb::SetCurNode(
      this,
      nodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)0xFFFFFFFF,
      curTime: 0,
      a4: v8,
      a5: v7,
      a6: v6,
      a7: v5,
      a8: v4);
  }
}


// ========================================================================
// ?ChangeState@idAnimator_AnimWeb@@QAA?AW4awPathResult_t@@PBD0W4interruptPath_t@@W4interruptBlend_t@@H@Z
// EA  : 0x826DAC78
// RVA : 0x006DAC78
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::ChangeState(
        idAnimator_AnimWeb *this,
        const char *subWebName,
        const char *stateName,
        interruptPath_t interruptPath_,
        interruptBlend_t interruptBlend_,
        int blendEventMask_)
{
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *decl; // r4
  __int16 v14; // [sp+50h] [-40h] BYREF

  decl = (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->decl;
  if ( decl == nullptr )
    return 0;
  idDeclAnimWeb::GetStateIndexForName(this: (idDeclAnimWeb *)&v14, result: decl, name: stateName);
  if ( v14 < 0 )
  {
    idLib::Warning(
      fmt: "idAnimator_AnimWeb::ChangeState - animWeb '%s' does not have a state '%s'",
      this->decl->name.str,
      stateName);
    return 0;
  }
  return idAnimator_AnimWeb::ChangeState(
           this,
           subWebName,
           stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v14,
           interruptPath_,
           interruptBlend_,
           blendEventMask_);
}


// ========================================================================
// ?ChangeStateVia@idAnimator_AnimWeb@@QAA?AW4awPathResult_t@@PBD000W4interruptPath_t@@W4interruptBlend_t@@H@Z
// EA  : 0x826DAD08
// RVA : 0x006DAD08
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

int __fastcall idAnimator_AnimWeb::ChangeStateVia(
        idAnimator_AnimWeb *this,
        const char *subWebName,
        const char *stateName,
        const char *viaSubWebName,
        const char *viaStateName,
        interruptPath_t interruptPath_,
        interruptBlend_t interruptBlend_,
        int blendEventMask_)
{
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *decl; // r4
  __int16 v18; // [sp+50h] [-50h] BYREF
  __int16 v19; // [sp+52h] [-4Eh] BYREF

  decl = (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->decl;
  if ( decl == nullptr )
    return 0;
  idDeclAnimWeb::GetStateIndexForName(this: (idDeclAnimWeb *)&v18, result: decl, name: stateName);
  if ( v18 < 0 )
  {
    idLib::Warning(
      fmt: "idAnimator_AnimWeb::ChangeStateVia - animWeb '%s' does not have a state '%s'",
      this->decl->name.str,
      stateName);
    return 0;
  }
  idDeclAnimWeb::GetStateIndexForName(
    this: (idDeclAnimWeb *)&v19,
    result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->decl,
    name: viaStateName);
  if ( v19 >= 0 )
    return idAnimator_AnimWeb::ChangeStateVia(
             this,
             subWebName,
             stateIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v18,
             viaSubWebName,
             _viaStateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v19,
             interruptPath_,
             interruptBlend_,
             blendEventMask_);
  idLib::Warning(
    fmt: "idAnimator_AnimWeb::ChangeStateVia - animWeb '%s' does not have a state '%s'",
    this->decl->name.str,
    viaStateName);
  return 0;
}


// ========================================================================
// ?Update@idAnimator_AnimWeb@@IAAXHH@Z
// EA  : 0x826DADF0
// RVA : 0x006DADF0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::Update(idAnimator_AnimWeb *this, int curTime, int ticksPerSec)
{
  char v6; // r10
  char v7; // r22
  int v8; // r23
  __int16 value; // r8
  int v10; // r9
  int v11; // r26
  idAnimator_AnimWeb::idModelAnimState *v12; // r11
  int v13; // r10
  idAnimWebBlendTree **list; // r7
  int v15; // r11
  idAnimWebBlendTree *v16; // r6
  idAnimWebBlendTree *v17; // r3
  int v18; // r9
  __int16 v19; // r7
  idAnimator_AnimWeb::idModelAnimState *v20; // r11
  int v21; // r10
  idAnimWebBlendTree **v22; // r8
  int v23; // r11
  idAnimWebBlendTree *v24; // r6
  idAnimWebBlendTree *v25; // r24
  int v26; // r11
  __int16 v27; // r7
  int v28; // r10
  idAnimator_AnimWeb::idModelAnimState *v29; // r11
  int v30; // r8
  idAnimWebBlendTree **v31; // r9
  int v32; // r11
  idAnimWebBlendTree *v33; // r6
  idAnimWebBlendTree *v34; // r3
  idAnimator_AnimWeb::idModelAnimState *v35; // r29
  int v36; // r28
  int PreviousGameMs; // r27
  int GameMs; // r3
  idMD6Branch *tree; // r11
  int type; // r10
  char v41; // r10
  bool v42; // zf
  idAnimator_AnimWeb::idModelAnimState *v43; // r3
  BOOL blending; // r29
  int v45; // r11
  const idDeclAnimWebNode *v46; // r28
  int v47; // r11
  const idDeclAnimWebNode *v48; // r27
  int v49; // r11
  const idDeclAnimWebNode *v50; // r25
  char v51; // r26
  int num; // r27
  int v53; // r28
  int v54; // r29
  idMD6LeafPlay *v55; // r3
  char v57; // r11
  const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *v58; // r4
  const idAnimWebBlendTree *BlendTree; // r3
  idMD6LeafPlay *FirstLeaf; // r3
  idMD6LeafPlay *v61; // r29
  signed int frameRate; // r27
  idMD6AnimData *animData; // r11
  int GameHz; // r28
  int FrameTime; // r3
  idMD6AnimData *v66; // r11
  int v67; // r10
  unsigned int v68; // r3
  int numFrames; // r11
  int v70; // r9
  int v71; // r11
  const idDeclAnimWebNode *v72; // r5
  interruptBlend_t interruptBlend; // r11
  int v74; // r7
  int v75; // r8
  idAnimator_AnimWeb::idModelAnimState *v76; // r9
  idMD6Node *v77; // r11
  int v78; // r10
  char v79; // r10
  idMD6Node *v80; // r10
  __int16 pathIndex; // r10
  char v82; // r27
  char v83; // r24
  int v84; // r26
  char v85; // r25
  __int16 v86; // r29
  __int16 v87; // r11
  const idDeclAnimWebNode *v88; // r5
  int v89; // r11
  const idDeclAnimWebNode *v90; // r4
  awCheckPathResult_t v91; // r3
  __int16 v92; // r29
  __int16 v93; // r4
  idDeclAnimWebNode *v94; // r9
  int v95; // r11
  __int16 v96; // r11
  int v97; // r6
  int v98; // r8
  idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *v99; // r9
  int v100; // r11
  idAnimWebRoute *p_curPath; // r21
  int v102; // r11
  int v103; // r22
  const idDeclAnimWeb *decl; // r10
  int v105; // r9
  int v106; // r8
  int v107; // r7
  int v108; // r6
  int *v109; // r11
  idAnimator_AnimWeb::forcedEdge_t *p_forcedEdge; // r10
  int i; // ctr
  __int16 v112; // r11
  int v113; // r11
  interruptPath_t interruptPath; // r10
  int v115; // r11
  idDeclAnimWebNode *v116; // r25
  int v117; // r11
  idDeclAnimWebNode *v118; // r5
  const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *v119; // r23
  idDeclAnimWebNode *v120; // r26
  int v121; // r24
  int v122; // r28
  const idDeclAnimWebNode::idModelInfo *ModelInfo; // r5
  idAnimator_AnimWeb_vtbl *v124; // r11
  __int16 v125; // r10
  int nodeStartTime; // r9
  int v127; // r8
  idDeclAnimWebNode *v128; // r10
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v129; // r4
  idDeclAnimWebNode *v130; // r10
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v131; // r28
  idDeclAnimWebNode *v132; // r9
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v133; // r29
  idDeclAnimWebNode *v134; // r11
  const idDeclAnimWeb *v135; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v136; // r27
  idGameTimeManager *gameTimeManager; // r25
  const char *str; // r24
  const char *StateName; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v140; // r4
  const char *v141; // r28
  const char *SubWebName; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v143; // r4
  const char *v144; // r29
  const char *v145; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v146; // r4
  const char *v147; // r27
  const char *v148; // r23
  int v149; // r3
  __int16 v150; // r10
  __int64 v151; // r8
  int v152; // r5
  int v153; // r4
  __int64 v154; // r10
  __int64 v155; // r8
  int v156; // r5
  int v157; // r4
  __int64 v158; // r7
  double v159; // fp13
  idMD6Branch *mergeBranch; // r8
  int v161; // r28
  int v162; // r29
  int v163; // r9
  __int16 v164; // r7
  idAnimator_AnimWeb::idModelAnimState *v165; // r11
  int v166; // r10
  idAnimWebBlendTree **v167; // r8
  int v168; // r11
  idAnimWebBlendTree *v169; // r6
  idAnimWebBlendTree *v170; // r3
  __int16 v171; // r11
  int v172; // r11
  __int16 v173; // r11
  int v174; // r28
  __int16 v175; // r5
  const idDeclAnimWeb *v176; // r4
  idDeclAnimWebNode *v177; // r3
  int v178; // r7
  int v179; // r11
  char v180; // r11
  idDeclAnimWebNode *v181; // r3
  int v182; // [sp+8h] [-1D8h]
  unsigned int *v183; // [sp+8h] [-1D8h]
  int v184; // [sp+Ch] [-1D4h]
  int *v185; // [sp+Ch] [-1D4h]
  int v186; // [sp+10h] [-1D0h]
  int v187; // [sp+10h] [-1D0h]
  int v188; // [sp+14h] [-1CCh]
  int v189; // [sp+14h] [-1CCh]
  int v190; // [sp+18h] [-1C8h]
  int v191; // [sp+18h] [-1C8h]
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *v192; // [sp+1Ch] [-1C4h]
  int v193; // [sp+1Ch] [-1C4h]
  int v194; // [sp+20h] [-1C0h]
  int v195; // [sp+24h] [-1BCh]
  int v196; // [sp+28h] [-1B8h]
  int v197; // [sp+2Ch] [-1B4h]
  int v198; // [sp+30h] [-1B0h]
  int v199; // [sp+34h] [-1ACh]
  int v200; // [sp+38h] [-1A8h]
  int v201; // [sp+3Ch] [-1A4h]
  int v202; // [sp+40h] [-1A0h]
  int v203; // [sp+44h] [-19Ch]
  int v204; // [sp+48h] [-198h]
  int v205; // [sp+4Ch] [-194h]
  int v206; // [sp+50h] [-190h]
  int v207; // [sp+58h] [-188h]
  __int64 v208; // [sp+A0h] [-140h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> v209; // [sp+A8h] [-138h] BYREF
  int v210; // [sp+ACh] [-134h]
  int v211; // [sp+B0h] [-130h] BYREF
  unsigned int v212; // [sp+B4h] [-12Ch] BYREF
  int v213; // [sp+BCh] [-124h] BYREF
  blendParms_t v214; // [sp+C0h] [-120h] BYREF
  idStr v215; // [sp+E0h] [-100h] BYREF
  idStr v216; // [sp+100h] [-E0h] BYREF
  idStr v217; // [sp+120h] [-C0h] BYREF

  if ( this->declChangeId != this->decl->changeId )
    idAnimator_AnimWeb::Reinitialize(this, curTime);
  this->InternalUpdateScalars(this, a2: curTime);
  if ( (unsigned __int16)this->curEdgeNodeIndex.value >= 0x8000u
    || (v6 = 1, (unsigned __int16)this->curEdgeIndex >= 0x8000u) )
  {
    v6 = 0;
  }
  v7 = v6;
  v8 = 0;
  if ( this->modelAnimStates.num > 0 )
  {
    while ( 1 )
    {
      value = this->prevNodeIndex.value;
      v10 = 0;
      v11 = v8;
      v12 = &this->modelAnimStates.list[v8];
      HIDWORD(v208) = v12->blendTreeCache.num;
      v13 = HIDWORD(v208);
      if ( SHIDWORD(v208) > 0 )
      {
        list = v12->blendTreeCache.list;
        v15 = 0;
        while ( 1 )
        {
          v16 = list[v15];
          HIDWORD(v208) = &list[v15];
          if ( v16->nodeIndex.value == value )
            break;
          ++v10;
          ++v15;
          if ( v10 >= v13 )
            goto LABEL_14;
        }
        v17 = list[v10];
        if ( v17 != nullptr )
          idAnimWebBlendTree::PreBlendTree(
            this: v17,
            web: this,
            curTime,
            ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz);
      }
LABEL_14:
      v18 = 0;
      v19 = this->curNodeIndex.value;
      v20 = &this->modelAnimStates.list[v11];
      HIDWORD(v208) = v20->blendTreeCache.num;
      v21 = HIDWORD(v208);
      if ( SHIDWORD(v208) <= 0 )
      {
LABEL_18:
        v25 = nullptr;
      }
      else
      {
        v22 = v20->blendTreeCache.list;
        v23 = 0;
        while ( 1 )
        {
          v24 = v22[v23];
          HIDWORD(v208) = &v22[v23];
          if ( v24->nodeIndex.value == v19 )
            break;
          ++v18;
          ++v23;
          if ( v18 >= v21 )
            goto LABEL_18;
        }
        v25 = v22[v18];
        if ( v25 != nullptr )
          idAnimWebBlendTree::PreBlendTree(
            this: v22[v18],
            web: this,
            curTime,
            ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz);
      }
      if ( v7 != 0 )
      {
        v26 = (__int16)(this->pathIndex + 1);
        if ( v26 < 0 || v26 >= this->curPath.num )
          v27 = -1;
        else
          v27 = this->curPath.path[v26].value;
        v28 = 0;
        v29 = &this->modelAnimStates.list[v11];
        HIDWORD(v208) = v29->blendTreeCache.num;
        v30 = HIDWORD(v208);
        if ( SHIDWORD(v208) > 0 )
        {
          v31 = v29->blendTreeCache.list;
          v32 = 0;
          while ( 1 )
          {
            v33 = v31[v32];
            HIDWORD(v208) = &v31[v32];
            if ( v33->nodeIndex.value == v27 )
              break;
            ++v28;
            ++v32;
            if ( v28 >= v30 )
              goto LABEL_33;
          }
          v34 = v31[v28];
          if ( v34 != nullptr )
            idAnimWebBlendTree::PreBlendTree(
              this: v34,
              web: this,
              curTime,
              ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz);
        }
LABEL_33:
        if ( idMD6Branch::IsBlendFinished(this: this->mergeBranch) && this->mergeBranch->targetAlpha == 0.0 )
        {
          v35 = this->modelAnimStates.list;
          v36 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
          HIDWORD(v208) = this->gametimeManager.gameTimeManager;
          PreviousGameMs = idGameTimeManager::GetPreviousGameMs(
                             this: (idGameTimeManager *)HIDWORD(v208),
                             type: GAMETIME_SCALED);
          GameMs = idGameTimeManager::GetGameMs(this: (idGameTimeManager *)HIDWORD(v208), type: GAMETIME_SCALED);
          tree = (idMD6Branch *)v35[v11].tree;
          if ( tree != nullptr )
          {
            type = tree->type;
            HIDWORD(v208) = v35[v11].tree;
            if ( type == 0 || type == 3 || type == 4 || (v42 = type != 5, v41 = 0, !v42) )
              v41 = 1;
            if ( v41 != 0 )
            {
              HIDWORD(v208) = tree;
              idMD6Branch::UpdateCurrentAlpha(
                this: tree,
                timeMSec: GameMs,
                lastTimeMSec: PreviousGameMs,
                ticksPerSec: v36);
            }
          }
        }
      }
      v43 = &this->modelAnimStates.list[v11];
      blending = v43->blending;
      idAnimator_AnimWeb::idModelAnimState::Update(this: v43, curTime);
      if ( blending && !this->modelAnimStates.list[v11].blending )
        break;
      if ( v8 == 0 )
        goto LABEL_57;
LABEL_73:
      if ( ++v8 >= this->modelAnimStates.num )
        goto LABEL_74;
    }
    v45 = this->curNodeIndex.value;
    if ( v45 == -1 )
    {
      v46 = nullptr;
    }
    else
    {
      v46 = this->decl->nodes.list[v45];
      if ( v46 != nullptr )
        this->InternalSetAnimDelta(
          this,
          a2: (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)(__int16)v8,
          a3: v46);
    }
    if ( v8 != 0 )
      goto LABEL_73;
    v47 = this->prevNodeIndex.value;
    if ( v47 == -1 )
      v48 = nullptr;
    else
      v48 = this->decl->nodes.list[v47];
    this->eventHandler.TriggerEventType(
      this: &this->eventHandler,
      a2: this,
      a3: v48,
      a4: ANIMWEB_EVENT_END_BLEND_OUT,
      a5: -1);
    this->eventHandler.TriggerEventType(
      this: &this->eventHandler,
      a2: this,
      a3: v46,
      a4: ANIMWEB_EVENT_END_BLEND_IN,
      a5: -1);
    if ( this->pathIndex == this->curPath.num - 1 )
      this->eventHandler.TriggerEventType(
        this: &this->eventHandler,
        a2: this,
        a3: v46,
        a4: ANIMWEB_EVENT_DEST_END_BLEND_IN,
        a5: -1);
    this->InternalFinishBlend(this, a2: v48, a3: v46, a4: curTime);
LABEL_57:
    if ( (unsigned __int8)idAnimator_AnimWeb::IsTransitioning(this) == 0 )
    {
      v49 = this->curNodeIndex.value;
      if ( v49 == -1 )
        v50 = nullptr;
      else
        v50 = this->decl->nodes.list[v49];
      v51 = 1;
      if ( v25 != nullptr )
        num = v25->leaves.num;
      else
        num = 0;
      v53 = 0;
      if ( num > 0 )
      {
        v54 = 0;
        do
        {
          if ( v51 == 0 )
            break;
          v55 = (idMD6LeafPlay *)v25->leaves.list[v54];
          if ( v55->wrapMode != 0
            || idMD6LeafPlay::IsPlaying(
                 this: v55,
                 gameTime: curTime,
                 ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz) )
          {
            v51 = 0;
          }
          ++v53;
          ++v54;
        }
        while ( v53 < num );
      }
      if ( v51 != 0 )
        this->eventHandler.TriggerEventType(
          this: &this->eventHandler,
          a2: this,
          a3: v50,
          a4: ANIMWEB_EVENT_DEST_CLAMPED,
          a5: -1);
    }
    goto LABEL_73;
  }
LABEL_74:
  if ( (v7 == 0 || this->interruptPath > INTR_PATH_NO)
    && (this->destStateIndices.numStates != 0
     || !this->skipForcedEdgeAutoPath && (unsigned __int16)this->forcedEdge.destNodeIndex.value < 0x8000u) )
  {
    idAnimator_AnimWeb::StartPath(this, curTime);
  }
  if ( (unsigned __int16)this->curEdgeNodeIndex.value >= 0x8000u
    || (v57 = 1, (unsigned __int16)this->curEdgeIndex >= 0x8000u) )
  {
    v57 = 0;
  }
  if ( v57 == 0 )
  {
    v58 = (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)this->curNodeIndex.value;
    if ( (__int16)v58 >= 0 && this->decl->nodes.list[(__int16)v58] != nullptr )
    {
      BlendTree = idAnimator_AnimWeb::idModelAnimState::GetBlendTree(this: this->modelAnimStates.list, nodeIndex: v58);
      if ( BlendTree != nullptr )
      {
        FirstLeaf = idAnimator_AnimWeb::FindFirstLeaf(this, tree: BlendTree->tree, curTime, stillPlaying: false);
        v61 = FirstLeaf;
        if ( FirstLeaf != nullptr && FirstLeaf->type == 2 )
        {
          frameRate = 30;
          animData = FirstLeaf->anim->animData;
          if ( animData != nullptr )
            frameRate = animData->frameRate;
          GameHz = idGameTimeManager::GetGameHz(this: this->gametimeManager.gameTimeManager, type: GAMETIME_SCALED);
          FrameTime = idMD6LeafPlay::GetFrameTime(this: v61, gameTime: curTime);
          v66 = v61->anim->animData;
          v67 = FrameTime * GameHz / (timeManager.gameTimePerFrame.value * timeManager.gameHz);
          v68 = (timeManager.gameTimePerFrame.value * timeManager.gameHz) & ~(__ROL4__(FrameTime * GameHz, 1) - 1);
          __twllei(timeManager.gameTimePerFrame.value * timeManager.gameHz, 0);
          __twlgei(v68, 0xFFFFFFFF);
          if ( v66 != nullptr )
            numFrames = v66->numFrames;
          else
            numFrames = 0;
          __twllei(frameRate, 0);
          v70 = (numFrames - 1) * GameHz;
          __twlgei(frameRate & ~(__ROL4__(v70, 1) - 1), 0xFFFFFFFF);
          if ( v70 / frameRate - v67 == 1 )
          {
            v71 = this->curNodeIndex.value;
            if ( v71 == -1 )
              v72 = nullptr;
            else
              v72 = this->decl->nodes.list[v71];
            this->eventHandler.TriggerEventType(
              this: &this->eventHandler,
              a2: this,
              a3: v72,
              a4: ANIMWEB_EVENT_CLAMP_NEXT_FRAME,
              a5: -1);
          }
        }
      }
    }
    return;
  }
  if ( this->modelAnimStates.list->blending )
  {
    interruptBlend = this->interruptBlend;
    if ( interruptBlend == INTR_BLEND_NO )
      return;
    if ( interruptBlend < INTR_BLEND_MULTI )
    {
      v74 = 0;
      if ( this->modelAnimStates.num > 0 )
      {
        v75 = 0;
        do
        {
          v76 = &this->modelAnimStates.list[v75];
          v77 = v76->tree;
          if ( v76->tree != nullptr )
          {
            v78 = v77->type;
            HIDWORD(v208) = v76->tree;
            if ( v78 == 0 || v78 == 3 || v78 == 4 || (v42 = v78 != 5, v79 = 0, !v42) )
              v79 = 1;
            if ( v79 != 0 )
            {
              v76->blending = false;
              v80 = *(idMD6Node **)&v77[8].type;
              HIDWORD(v208) = v77;
              v76->tree = v80;
            }
          }
          ++v74;
          ++v75;
        }
        while ( v74 < this->modelAnimStates.num );
      }
    }
  }
  pathIndex = this->pathIndex;
  v82 = 0;
  v83 = 0;
  v84 = pathIndex;
  v85 = 0;
  if ( pathIndex < this->curPath.num - 1 )
  {
    v86 = pathIndex + 1;
    while ( 1 )
    {
      v87 = v86 < 0 || v86 >= this->curPath.num ? -1 : this->curPath.path[v86].value;
      v88 = v87 == -1 ? nullptr : this->decl->nodes.list[v87];
      v89 = this->curNodeIndex.value;
      v90 = v89 == -1 ? nullptr : this->decl->nodes.list[v89];
      v91 = this->CheckNextNode(this, a2: v90, a3: v88);
      if ( v91 == CHECKPATH_WAIT )
        break;
      if ( v91 != CHECKPATH_OK )
      {
        if ( v91 == CHECKPATH_INVALID_NODE )
        {
          ++v84;
          ++v86;
          v82 = 1;
        }
        if ( v84 < this->curPath.num - 1 )
          continue;
      }
      goto LABEL_135;
    }
    v85 = 1;
  }
LABEL_135:
  v92 = -1;
  if ( v82 != 0 )
  {
    HIWORD(v208) = this->curNodeIndex.value;
    v93 = HIWORD(v208);
    if ( SHIWORD(v208) == -1 )
      v94 = nullptr;
    else
      v94 = this->decl->nodes.list[SHIWORD(v208)];
    v95 = (__int16)(v84 + 1);
    if ( v95 < 0 || v95 >= this->curPath.num )
      v96 = -1;
    else
      v96 = this->curPath.path[v95].value;
    v92 = v96;
    v97 = 0;
    HIDWORD(v208) = v94->edges.num;
    if ( SHIDWORD(v208) > 0 )
    {
      v98 = v96;
      v99 = v94->edges.list;
      v100 = 0;
      while ( this->decl->edgeCache.list[v99[v100].value].destNodeIndex.value != v98 )
      {
        ++v97;
        ++v100;
        if ( v97 >= SHIDWORD(v208) )
          goto LABEL_149;
      }
      this->curEdgeNodeIndex.value = v93;
      v83 = 1;
      this->curEdgeIndex = v97;
    }
LABEL_149:
    if ( v83 != 0 )
      this->pathIndex = v84;
  }
  if ( v85 == 0 )
  {
    p_curPath = &this->curPath;
    v102 = (__int16)(this->pathIndex + 1);
    if ( v102 < 0 || v102 >= this->curPath.num )
      v103 = -1;
    else
      v103 = (unsigned __int16)p_curPath->path[v102].value;
    HIWORD(v208) = -1;
    v209.value = -1;
    blendParms_t::blendParms_t(this: &v214);
    if ( (unsigned __int8)idAnimator_AnimWeb::GetCurEdgeInfo(
                            this,
                            swi: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)&v208,
                            ni: &v209,
                            bp: &v214) != 0 )
    {
      if ( v82 != 0 && v83 == 0 && v92 != -1 )
      {
        decl = this->decl;
        v105 = 4 * v92;
        v106 = *(int *)((char *)decl->nodes.list + v105);
        if ( v106 != 0 )
        {
          v109 = &v213;
          p_forcedEdge = &this->forcedEdge;
          for ( i = 5; i != 0; --i )
          {
            ++v109;
            p_forcedEdge = (idAnimator_AnimWeb::forcedEdge_t *)((char *)p_forcedEdge + 4);
            *(_DWORD *)&p_forcedEdge->destNodeIndex.value = *v109;
          }
          v112 = *(_WORD *)(v106 + 2);
          this->forcedEdge.destNodeIndex.value = v92;
          this->curEdgeIndex = 0x7FFF;
          this->skipForcedEdgeAutoPath = true;
          this->forcedEdge.destSubWebIndex.value = v112;
          if ( (unsigned __int8)idAnimator_AnimWeb::GetCurEdgeInfo(
                                  this,
                                  swi: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)&v208,
                                  ni: &v209,
                                  bp: &v214) == 0 )
            return;
          decl = (const idDeclAnimWeb *)(__int16)v84;
          v105 = (__int16)v84 + 1;
          this->pathIndex = v84;
          if ( (v105 & 0x8000u) != 0 || (decl = (const idDeclAnimWeb *)this->curPath.num, (__int16)v105 >= (int)decl) )
            v113 = -1;
          else
            v113 = (unsigned __int16)p_curPath->path[(__int16)v105].value;
          v103 = v113;
        }
      }
      idAnimator_AnimWeb::AllocBlendTrees(
        this,
        forNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v103,
        keepNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)this->curNodeIndex.value,
        a4: v108,
        a5: v107,
        a6: v106,
        a7: v105,
        a8: (int)decl,
        a9: v182,
        a10: v184,
        a11: v186,
        a12: v188,
        a13: v190,
        a14: v192);
      interruptPath = this->interruptPath;
      v210 = 9;
      if ( interruptPath == INTR_PATH_IMMEDIATE )
      {
        this->interruptPath = INTR_PATH_YES;
      }
      else if ( ((unsigned __int8 (__fastcall *)(idAnimator_AnimWeb *, _DWORD, int, int, int, blendParms_t *, _DWORD, int))this->InternalShouldStartNextNode)(
                  a1: this,
                  a2: (unsigned __int16)this->curNodeIndex.value,
                  a3: v103,
                  a4: curTime,
                  a5: ticksPerSec,
                  a6: &v214,
                  a7: 0,
                  a8: 1) == 0 )
      {
        if ( v210 != -1 )
        {
          v117 = this->curNodeIndex.value;
          if ( v117 == -1 )
            v118 = nullptr;
          else
            v118 = this->decl->nodes.list[v117];
          ((void (__fastcall *)(idAnimWebEventHandler_Zion *, idAnimator_AnimWeb *, idDeclAnimWebNode *))this->eventHandler.TriggerEventType)(
            a1: &this->eventHandler,
            a2: this,
            a3: v118);
        }
        return;
      }
      v115 = this->curNodeIndex.value;
      if ( v115 == -1 )
        v116 = nullptr;
      else
        v116 = this->decl->nodes.list[v115];
      v119 = (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)v209.value;
      if ( v209.value == -1 )
        v120 = nullptr;
      else
        v120 = this->decl->nodes.list[v209.value];
      this->eventHandler.TriggerEventType(
        this: &this->eventHandler,
        a2: this,
        a3: v116,
        a4: ANIMWEB_EVENT_START_BLEND_OUT,
        a5: -1);
      v212 = 0;
      v211 = 0;
      this->eventHandler.TriggerEventType(
        this: &this->eventHandler,
        a2: this,
        a3: v120,
        a4: ANIMWEB_EVENT_START_BLEND_IN,
        a5: 0);
      if ( this->pathIndex + 1 == this->curPath.num - 1 )
        this->eventHandler.TriggerEventType(
          this: &this->eventHandler,
          a2: this,
          a3: v120,
          a4: ANIMWEB_EVENT_DEST_START_BLEND_IN,
          a5: -1);
      this->interruptBlend = INTR_BLEND_NO;
      this->InternalStartBlend(this, a2: v116, a3: v120, a4: curTime);
      v121 = 0;
      if ( this->modelAnimStates.num > 0 )
      {
        v122 = 0;
        while ( 1 )
        {
          HIWORD(v208) = v121;
          ModelInfo = idDeclAnimWebNode::FindModelInfo(
                        this: v120,
                        modelIndex: (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)(__int16)v121);
          if ( ModelInfo != nullptr )
            goto _LN884;
          if ( v121 == 0 )
            break;
LABEL_193:
          ++v121;
          ++v122;
          if ( v121 >= this->modelAnimStates.num )
            goto LABEL_194;
        }
        v215.len = 0;
        v215.baseBuffer[0] = 0;
        v215.allocedAndFlag = 20;
        v215.data = v215.baseBuffer;
        idDeclAnimWebNode::GetName(this: v116, web: this->decl, name: &v215);
        idLib::Error(fmt: "animWeb node '%s' missing modelinfo.", v215.data);
_LN884:
        idAnimator_AnimWeb::idModelAnimState::StartBlend(
          this: &this->modelAnimStates.list[v122],
          web: this,
          modelInfo: ModelInfo,
          curNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)this->curNodeIndex.value,
          nextNodeIndex: v119,
          bp: &v214,
          curTime,
          ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz,
          retLongestAnimLen: v183,
          retDestFrame: v185,
          a11: v187,
          a12: v189,
          a13: v191,
          a14: v193,
          a15: v194,
          a16: v195,
          a17: v196,
          a18: v197,
          a19: v198,
          a20: v199,
          a21: v200,
          a22: v201,
          a23: v202,
          a24: v203,
          a25: v204,
          a26: v205,
          a27: v206,
          a28: &v212,
          a29: v207,
          a30: &v211);
        if ( v120->animDelta >= (unsigned int)v116->animDelta || this->forceAnimDeltaModeOnBlendStart )
        {
          this->forceAnimDeltaModeOnBlendStart = false;
          v124 = this->__vftable;
          HIWORD(v208) = v121;
          v124->InternalSetAnimDelta(
            this,
            a2: (const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *)(__int16)v121,
            a3: v120);
        }
        goto LABEL_193;
      }
LABEL_194:
      v125 = this->pathIndex;
      nodeStartTime = this->nodeStartTime;
      v127 = v211;
      this->nodeStartTime = curTime;
      this->pathIndex = v125 + 1;
      this->prevNodeStartTime = nodeStartTime;
      this->nodeStartFrame = v127;
      if ( (__int16)v103 == -1 )
        v128 = nullptr;
      else
        v128 = this->decl->nodes.list[(__int16)v103];
      v129 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v128->states.stateIndex[0].value;
      if ( (__int16)v103 == -1 )
        v130 = nullptr;
      else
        v130 = this->decl->nodes.list[(__int16)v103];
      v131 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v130->subWebIndex.value;
      HIWORD(v208) = this->curNodeIndex.value;
      if ( SHIWORD(v208) == -1 )
        v132 = nullptr;
      else
        v132 = this->decl->nodes.list[SHIWORD(v208)];
      v133 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v132->states.stateIndex[0].value;
      if ( SHIWORD(v208) == -1 )
        v134 = nullptr;
      else
        v134 = this->decl->nodes.list[SHIWORD(v208)];
      v135 = this->decl;
      v136 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v134->subWebIndex.value;
      gameTimeManager = this->gametimeManager.gameTimeManager;
      str = v135->name.str;
      StateName = idDeclAnimWeb::GetStateName(this: v135, index: v129);
      v140 = v131;
      v141 = StateName;
      SubWebName = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v140);
      v143 = v133;
      v144 = SubWebName;
      v145 = idDeclAnimWeb::GetStateName(this: this->decl, index: v143);
      v146 = v136;
      v147 = v145;
      v148 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v146);
      v149 = idAccolade::Count(this: gameTimeManager);
      idAnimator_AnimWeb::DebugPrint(
        this,
        fmt: "(%d) animWeb '%s': blending state '%s/%s' to new state '%s/%s' at time %d\n",
        a3: __SPAIR64__(v149, (unsigned int)str),
        a4: __SPAIR64__((unsigned int)v148, (unsigned int)v147),
        a5: __SPAIR64__((unsigned int)v144, (unsigned int)v141),
        a6: (int)v183,
        a7: (int)v185,
        a8: v187,
        a9: v189,
        a10: v191,
        a11: v193);
      v150 = this->curNodeIndex.value;
      this->curNodeIndex.value = v103;
      this->prevNodeIndex.value = v150;
      idAnimator_AnimWeb::CacheCurNode(this);
      HIDWORD(v154) = (__int16)blendParms_t::GetDurationMS(this: &v214, a2: v153, a3: v152, a4: v151);
      if ( SHIDWORD(v154) <= 0 )
      {
        if ( (v120->flags & 0x10) != 0 )
        {
          this->mergeBranch->targetAlpha = 0.0;
          this->mergeBranch->currentAlpha = 0.0;
        }
        else
        {
          this->mergeBranch->targetAlpha = 1.0;
          this->mergeBranch->currentAlpha = 1.0;
        }
      }
      else
      {
        LODWORD(v154) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
        v208 = v154;
        LODWORD(v158) = (__int16)blendParms_t::GetDurationMS(this: &v214, a2: v157, a3: v156, a4: v155);
        v159 = (double)v208;
        mergeBranch = this->mergeBranch;
        v208 = v158;
        mergeBranch->alphaRate = (float)v159 / (float)v158;
        if ( (v120->flags & 0x10) != 0 )
          this->mergeBranch->targetAlpha = 0.0;
        else
          this->mergeBranch->targetAlpha = 1.0;
      }
      v161 = 0;
      if ( this->modelAnimStates.num > 0 )
      {
        v162 = 0;
        do
        {
          v163 = 0;
          v164 = this->curNodeIndex.value;
          v165 = &this->modelAnimStates.list[v162];
          HIDWORD(v208) = v165->blendTreeCache.num;
          v166 = HIDWORD(v208);
          if ( SHIDWORD(v208) > 0 )
          {
            v167 = v165->blendTreeCache.list;
            v168 = 0;
            while ( 1 )
            {
              v169 = v167[v168];
              HIDWORD(v208) = &v167[v168];
              if ( v169->nodeIndex.value == v164 )
                break;
              ++v163;
              ++v168;
              if ( v163 >= v166 )
                goto LABEL_222;
            }
            v170 = v167[v163];
            if ( v170 != nullptr )
              idAnimWebBlendTree::PreBlendTree(
                this: v170,
                web: this,
                curTime,
                ticksPerSec: timeManager.gameTimePerFrame.value * timeManager.gameHz);
          }
LABEL_222:
          ++v161;
          ++v162;
        }
        while ( v161 < this->modelAnimStates.num );
      }
      v171 = this->pathIndex;
      this->forcedEdge.destNodeIndex.value = -1;
      this->forcedEdge.destSubWebIndex.value = -1;
      v172 = (__int16)(v171 + 1);
      if ( v172 < 0 || v172 >= this->curPath.num )
        v173 = -1;
      else
        v173 = p_curPath->path[v172].value;
      v174 = v173;
      this->curEdgeNodeIndex.value = -1;
      this->curEdgeIndex = -1;
      if ( v173 >= 0 )
      {
        HIWORD(v208) = this->curNodeIndex.value;
        v175 = HIWORD(v208);
        if ( SHIWORD(v208) == -1 || (v176 = this->decl, (v177 = v176->nodes.list[SHIWORD(v208)]) == nullptr) )
          idLib::Error(fmt: "animWeb '%s': Current node is node valid.", this->decl->name.str);
        v178 = 0;
        HIDWORD(v208) = v177->edges.num;
        if ( SHIDWORD(v208) > 0 )
        {
          v179 = 0;
          while ( v176->edgeCache.list[v177->edges.list[v179].value].destNodeIndex.value != v174 )
          {
            ++v178;
            ++v179;
            if ( v178 >= SHIDWORD(v208) )
              goto LABEL_238;
          }
          this->curEdgeNodeIndex.value = v175;
          this->curEdgeIndex = v178;
        }
LABEL_238:
        if ( (unsigned __int16)this->curEdgeNodeIndex.value >= 0x8000u
          || (v180 = 1, (unsigned __int16)this->curEdgeIndex >= 0x8000u) )
        {
          v180 = 0;
        }
        if ( v180 == 0 )
        {
          v217.len = 0;
          v217.baseBuffer[0] = 0;
          v217.allocedAndFlag = 20;
          v217.data = v217.baseBuffer;
          idDeclAnimWebNode::GetName(this: v177, web: v176, name: &v217);
          v216.allocedAndFlag = 20;
          v216.data = v216.baseBuffer;
          v216.len = 0;
          v216.baseBuffer[0] = 0;
          if ( v174 == -1 )
            v181 = nullptr;
          else
            v181 = this->decl->nodes.list[v174];
          idDeclAnimWebNode::GetName(this: v181, web: this->decl, name: &v216);
          idLib::Error(
            fmt: "No edge was found from node '%s' to '%s' while traversing the animWeb '%s'",
            v217.data,
            v216.data,
            this->decl->name.str);
        }
        this->InternalUpdate(this, a2: curTime);
      }
      else
      {
        this->curPath.num = 0;
        this->curPath.cost = 0x7FFFFFFF;
        this->pathIndex = -1;
        this->forcedEdge.destNodeIndex.value = -1;
        this->forcedEdge.destSubWebIndex.value = -1;
      }
    }
  }
}


// ========================================================================
// $LN866
// EA  : 0x826DC084
// RVA : 0x006DC084
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _LN866()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 224));
}


// ========================================================================
// __unwind$268319
// EA  : 0x826DC0AC
// RVA : 0x006DC0AC
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_268319()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 288));
}


// ========================================================================
// __unwind$268320
// EA  : 0x826DC0D4
// RVA : 0x006DC0D4
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_268320()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 256));
}


// ========================================================================
// ?InternalPreBlendTree@idAnimator_AnimWeb@@MAAXPBVidAnimStack@@HH@Z
// EA  : 0x826DC108
// RVA : 0x006DC108
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __fastcall idAnimator_AnimWeb::InternalPreBlendTree(
        idAnimator_AnimWeb *this,
        const idAnimStack *stack,
        int curTime,
        int ticksPerSec)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  idPLogScope v10[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idAnimator_AnimWeb::InternalPreBlendTree");
  LODWORD(v8) = "idAnimator_AnimWeb::InternalPreBlendTree";
  HIDWORD(v8) = 2;
  idPLogScope::idPLogScope(this: v10, pl: &pLog, gMask: v8, label: v9);
  this->InternalUpdateBlendEvents(this, a2: stack, a3: curTime, a4: ticksPerSec);
  idAnimator_AnimWeb::Update(this, curTime, ticksPerSec);
  if ( this->mergeBranch != nullptr )
  {
    this->mergeBranch->right = this->modelAnimStates.list->tree;
    this->mergeBranch->left = nullptr;
  }
  idPLogScope::~idPLogScope(this: v10);
  RD_EventEnd();
}


// ========================================================================
// __unwind$270292
// EA  : 0x826DC1C8
// RVA : 0x006DC1C8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_270292()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$270293
// EA  : 0x826DC1F0
// RVA : 0x006DC1F0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void _unwind_270293()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// `dynamic initializer for 'anim_autoWebTrace''
// EA  : 0x8333ED70
// RVA : 0x0133ED70
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_autoWebTrace__()
{
  idCVar::idCVar(
    this: &anim_autoWebTrace,
    name: "anim_autoWebTrace",
    value: "0",
    flags: 0,
    description: "1 = automatically perform a PIX trace when the source and dest paths match",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_autoWebTrace__);
}


// ========================================================================
// `dynamic initializer for 'anim_sourcePath''
// EA  : 0x8333EDC8
// RVA : 0x0133EDC8
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_sourcePath__()
{
  idCVar::idCVar(
    this: &anim_sourcePath,
    name: "anim_sourcePath",
    value: "hands_relaxed/idle",
    flags: 0,
    description: "source path for anim web timing trace",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_sourcePath__);
}


// ========================================================================
// `dynamic initializer for 'anim_destPath''
// EA  : 0x8333EE20
// RVA : 0x0133EE20
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_destPath__()
{
  idCVar::idCVar(
    this: &anim_destPath,
    name: "anim_destPath",
    value: "hands_actionScript/lean_over_rail",
    flags: 0,
    description: "dest path for anim web timing trace",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_destPath__);
}


// ========================================================================
// `dynamic initializer for 'anim_verifyPaths''
// EA  : 0x8333EE78
// RVA : 0x0133EE78
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_verifyPaths__()
{
  idCVar::idCVar(
    this: &anim_verifyPaths,
    name: "anim_verifyPaths",
    value: "0",
    flags: 4,
    description: "1 = verify paths for every change state at time of request\n, 2 = verify and assert on invalid paths",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_verifyPaths__);
}


// ========================================================================
// `dynamic initializer for 'anim_webTimeThreshold''
// EA  : 0x8333EED0
// RVA : 0x0133EED0
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_webTimeThreshold__()
{
  idCVar::idCVar(
    this: &anim_webTimeThreshold,
    name: "anim_webTimeThreshold",
    value: "1.0",
    flags: 4,
    description: "warn if a path exceeds this threshold",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_webTimeThreshold__);
}


// ========================================================================
// `dynamic initializer for 'anim_webTrace''
// EA  : 0x8333EF28
// RVA : 0x0133EF28
// PDB : w:\tech5\engine\gamelib\animstack\animator_animweb.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__anim_webTrace__()
{
  idCVar::idCVar(
    this: &anim_webTrace,
    name: "anim_webTrace",
    value: "0",
    flags: 1,
    description: "set to true to trace the next animWeb path.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__anim_webTrace__);
}

