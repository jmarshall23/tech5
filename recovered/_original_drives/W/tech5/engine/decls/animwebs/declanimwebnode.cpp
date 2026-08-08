
// ========================================================================
// ?MatchStates@idDeclAnimWebNode@@QBAHABVstateList_t@idDeclAnimWeb@@@Z
// EA  : 0x82606200
// RVA : 0x00606200
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

int __fastcall idDeclAnimWebNode::MatchStates(idDeclAnimWebNode *this, const idDeclAnimWeb::stateList_t *stateIndices)
{
  int numStates; // r10
  int result; // r3
  idDeclAnimWeb::stateList_t *p_states; // r7
  int i; // ctr
  int v7; // r10
  const idDeclAnimWeb::stateList_t *v8; // r11

  numStates = this->states.numStates;
  result = 0;
  if ( numStates != 0 )
  {
    p_states = &this->states;
    for ( i = numStates; i != 0; --i )
    {
      v7 = 0;
      if ( stateIndices->numStates != 0 )
      {
        v8 = stateIndices;
        while ( p_states->stateIndex[0].value != v8->stateIndex[0].value )
        {
          ++v7;
          v8 = (const idDeclAnimWeb::stateList_t *)((char *)v8 + 2);
          if ( v7 >= stateIndices->numStates )
            goto LABEL_9;
        }
        ++result;
      }
LABEL_9:
      p_states = (idDeclAnimWeb::stateList_t *)((char *)p_states + 2);
    }
  }
  return result;
}


// ========================================================================
// ?GetPath@idDeclAnimWebNode@@QBAXPBVidDeclAnimWeb@@AAVidAnimWebPath@@@Z
// EA  : 0x82606270
// RVA : 0x00606270
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall idDeclAnimWebNode::GetPath(idDeclAnimWebNode *this, const idDeclAnimWeb *web, idAnimWebPath *path)
{
  const char *str; // r28
  const char *StateName; // r27
  const char *SubWebName; // r3

  str = web->name.str;
  StateName = idDeclAnimWeb::GetStateName(
                this: web,
                index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->states.stateIndex[0].value);
  SubWebName = idDeclAnimWeb::GetSubWebName(
                 this: web,
                 index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->subWebIndex.value);
  idAnimWebPath::SetPath(this: path, webName: str, subWebName: SubWebName, stateName: StateName);
}


// ========================================================================
// ?GetStateName@idDeclAnimWebNode@@QBAXPBVidDeclAnimWeb@@AAVidStr@@@Z
// EA  : 0x826062C8
// RVA : 0x006062C8
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall idDeclAnimWebNode::GetStateName(idDeclAnimWebNode *this, const idDeclAnimWeb *web, idStr *name)
{
  const char *StateName; // r3

  StateName = idDeclAnimWeb::GetStateName(
                this: web,
                index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->states.stateIndex[0].value);
  idStr::operator=(this: name, text: StateName);
}


// ========================================================================
// ?GetStateName@idDeclAnimWebNode@@QBAXPBVidDeclAnimWeb@@HAAVidStr@@@Z
// EA  : 0x82606310
// RVA : 0x00606310
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall idDeclAnimWebNode::GetStateName(
        idDeclAnimWebNode *this,
        const idDeclAnimWeb *web,
        const int idx,
        idStr *name)
{
  const char *StateName; // r3

  StateName = idDeclAnimWeb::GetStateName(
                this: web,
                index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->states.stateIndex[idx].value);
  idStr::operator=(this: name, text: StateName);
}


// ========================================================================
// ?FindModelInfo@idDeclAnimWebNode@@QBAPBVidModelInfo@1@V?$idIndex@FW4invalidModelIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82606360
// RVA : 0x00606360
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

const idDeclAnimWebNode::idModelInfo *__fastcall idDeclAnimWebNode::FindModelInfo(
        idDeclAnimWebNode *this,
        const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *modelIndex)
{
  int num; // r7
  int v3; // r10
  int v4; // r11
  __int16 v5; // r11

  num = this->modelInfo.num;
  v3 = 0;
  if ( num <= 0 )
  {
LABEL_5:
    v5 = -1;
  }
  else
  {
    v4 = 0;
    while ( this->modelInfo.list[v4].modelIndex.value != (__int16)modelIndex )
    {
      ++v3;
      ++v4;
      if ( v3 >= num )
        goto LABEL_5;
    }
    v5 = v3;
  }
  if ( v5 < 0 )
    return nullptr;
  else
    return &this->modelInfo.list[v5];
}


// ========================================================================
// ?Compare@idSort_EdgeDestName@@QBAHABV?$idIndex@FW4invalidEdgeIndex_t@idDeclAnimWeb@@@@0@Z
// EA  : 0x82606560
// RVA : 0x00606560
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

int __fastcall idSort_EdgeDestName::Compare(
        idSort_EdgeDestName *this,
        const idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *ei1,
        const idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *ei2)
{
  __int16 value; // r7
  const idDeclAnimWeb *decl; // r3
  int v7; // r4
  idDeclAnimWebNode *v8; // r30
  idDeclAnimWebEdge *list; // r11
  idDeclAnimWebEdge *v10; // r26
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v11; // r27
  __int16 v12; // r5
  idDeclAnimWebNode *v13; // r11
  const char *StateName; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v15; // r4
  const char *v16; // r27
  const char *SubWebName; // r3
  const char *v18; // r6
  const idDeclAnimWeb *v19; // r3
  int v20; // r9
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v21; // r28
  __int16 v22; // r8
  const char *v23; // r30
  const char *v24; // r3
  const char *v25; // r6
  char *data; // r10
  char *v27; // r11
  int v28; // r30
  idStr v30; // [sp+60h] [-90h] BYREF
  idStr v31[3]; // [sp+80h] [-70h] BYREF

  value = ei1->value;
  decl = this->decl;
  v7 = ei2->value;
  v8 = nullptr;
  list = decl->edges.list;
  v31[0].allocedAndFlag = 20;
  v31[0].data = v31[0].baseBuffer;
  v31[0].len = 0;
  v10 = &list[v7];
  v31[0].baseBuffer[0] = 0;
  v11 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)list[value].destSubWebIndex.value;
  v12 = decl->edgeCache.list[value].destNodeIndex.value;
  if ( v12 < 0 )
  {
    SubWebName = idDeclAnimWeb::GetSubWebName(this: decl, index: v11);
    v18 = &byte_8200D768;
  }
  else
  {
    if ( v12 == -1 )
      v13 = nullptr;
    else
      v13 = decl->nodes.list[v12];
    StateName = idDeclAnimWeb::GetStateName(
                  this: decl,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v13->states.stateIndex[0].value);
    v15 = v11;
    v16 = StateName;
    SubWebName = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v15);
    v18 = v16;
  }
  idAnimWebPath::SetPath(this: (idAnimWebPath *)v31, webName: nullptr, subWebName: SubWebName, stateName: v18);
  v30.allocedAndFlag = 20;
  v30.len = 0;
  v30.data = v30.baseBuffer;
  v30.baseBuffer[0] = 0;
  v19 = this->decl;
  v20 = ei2->value;
  v21 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v10->destSubWebIndex.value;
  v22 = v19->edgeCache.list[v20].destNodeIndex.value;
  if ( v22 < 0 )
  {
    v24 = idDeclAnimWeb::GetSubWebName(this: v19, index: v21);
    v25 = &byte_8200D768;
  }
  else
  {
    if ( v22 != -1 )
      v8 = v19->nodes.list[v22];
    v23 = idDeclAnimWeb::GetStateName(
            this: v19,
            index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v8->states.stateIndex[0].value);
    v24 = idDeclAnimWeb::GetSubWebName(this: this->decl, index: v21);
    v25 = v23;
  }
  idAnimWebPath::SetPath(this: (idAnimWebPath *)&v30, webName: nullptr, subWebName: v24, stateName: v25);
  data = v30.data;
  v27 = v31[0].data;
  do
  {
    v28 = (unsigned __int8)*v27 - (unsigned __int8)*data;
    if ( *v27 == 0 )
      break;
    ++v27;
    ++data;
  }
  while ( v28 == 0 );
  idStr::FreeData(this: &v30);
  idStr::FreeData(this: v31);
  return v28;
}


// ========================================================================
// __unwind$224599
// EA  : 0x82606724
// RVA : 0x00606724
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_224599()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$224600
// EA  : 0x8260674C
// RVA : 0x0060674C
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_224600()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// ?IsLooping@idDeclAnimWebNode@@QBA_NXZ
// EA  : 0x82606778
// RVA : 0x00606778
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

int __fastcall idDeclAnimWebNode::IsLooping(idDeclAnimWebNode *this)
{
  int num; // r4
  int v2; // r5
  idList<idMD6AnimProps,32> *i; // r6
  int v4; // r7
  int v5; // r10
  int v6; // r11
  idMD6AnimProps *list; // r8
  char v8; // r11

  num = this->modelInfo.num;
  v2 = 0;
  if ( num <= 0 )
    return 0;
  for ( i = &this->modelInfo.list->animProps; ; i = (idList<idMD6AnimProps,32> *)((char *)i + 36) )
  {
    v4 = i->num;
    v5 = 0;
    if ( v4 <= 0 )
    {
LABEL_7:
      v8 = 0;
    }
    else
    {
      v6 = 0;
      list = i->list;
      while ( list->wrap != WRAP_REPEAT )
      {
        ++v5;
        list = &i->list[++v6];
        if ( v5 >= v4 )
          goto LABEL_7;
      }
      v8 = 1;
    }
    if ( v8 != 0 )
      break;
    if ( ++v2 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?FixUpAnimVars@idModelInfo@idDeclAnimWebNode@@AAAXPBVidDeclMD6@@@Z
// EA  : 0x82606810
// RVA : 0x00606810
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall idDeclAnimWebNode::idModelInfo::FixUpAnimVars(
        idDeclAnimWebNode::idModelInfo *this,
        const idDeclMD6 *declMD6)
{
  __int64 v3; // r10
  __int64 v4; // r8
  __int64 v5; // r6
  int v6; // r30
  int v7; // r28
  va *v8; // r3
  idMD6AnimProps *v9; // r11
  int value; // r9
  const char *str; // r5
  const idMD6Anim *anim; // r11
  int v13; // [sp+8h] [-10D8h]
  int v14; // [sp+Ch] [-10D4h]
  int v15; // [sp+10h] [-10D0h]
  int v16; // [sp+14h] [-10CCh]
  int v17; // [sp+18h] [-10C8h]
  int v18; // [sp+1Ch] [-10C4h]
  _DWORD v19[4]; // [sp+50h] [-1090h] BYREF
  idStr v20; // [sp+60h] [-1080h] BYREF
  idStr v21; // [sp+80h] [-1060h] BYREF
  va v22; // [sp+A0h] [-1040h] BYREF

  idStr::idStr(this: &v20, text: this->blendEq.str);
  v6 = 0;
  if ( this->animProps.num > 0 )
  {
    v7 = 0;
    do
    {
      HIDWORD(v5) = v6;
      v8 = va::va(
             this: &v22,
             fmt: "anim%d",
             a3: v5,
             a4: v4,
             a5: v3,
             a6: v13,
             a7: v14,
             a8: v15,
             a9: v16,
             a10: v17,
             a11: v18);
      idStr::idStr(this: &v21, text: v8);
      v9 = &this->animProps.list[v7];
      v19[1] = v9;
      value = v9->aliasHandle.value;
      if ( value == 0xFFFF )
      {
        anim = v9->anim;
        v19[1] = anim;
        if ( anim == nullptr )
          goto LABEL_8;
        str = anim->name.str;
        v19[1] = anim;
        if ( str == nullptr )
          goto LABEL_8;
      }
      else
      {
        v19[1] = v9;
        HIWORD(v19[0]) = value;
        str = animation->FindAliasName(this: animation, a2: v19);
      }
      idStr::Replace(this: &v20, old: v21.data, nw: str);
LABEL_8:
      idStr::FreeData(this: &v21);
      ++v6;
      ++v7;
    }
    while ( v6 < this->animProps.num );
  }
  idAtomicString::Set(this: &this->blendEqFixed, str_: v20.data);
  idStr::FreeData(this: &v20);
}


// ========================================================================
// __unwind$224960
// EA  : 0x82606918
// RVA : 0x00606918
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_224960()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 96));
}


// ========================================================================
// __unwind$224961
// EA  : 0x82606940
// RVA : 0x00606940
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_224961()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4320 + 128));
}


// ========================================================================
// ?Size@idDeclAnimWebNode@@QBAIXZ
// EA  : 0x82606968
// RVA : 0x00606968
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

int __fastcall idDeclAnimWebNode::Size(idDeclAnimWebNode *this)
{
  return 2 * (18 * this->modelInfo.size + this->edges.size + 32);
}


// ========================================================================
// ?NumAnims@idDeclAnimWebNode@@QBAHV?$idIndex@FW4invalidModelIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82606990
// RVA : 0x00606990
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

const idDeclAnimWebNode::idModelInfo *__fastcall idDeclAnimWebNode::NumAnims(
        idDeclAnimWebNode *this,
        const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *modelIndex)
{
  const idDeclAnimWebNode::idModelInfo *result; // r3

  result = idDeclAnimWebNode::FindModelInfo(this, modelIndex);
  if ( result != nullptr )
    return (const idDeclAnimWebNode::idModelInfo *)result->animProps.num;
  return result;
}


// ========================================================================
// ?GetAnim@idDeclAnimWebNode@@QBAPBVidMD6Anim@@V?$idIndex@FW4invalidModelIndex_t@idDeclAnimWeb@@@@H@Z
// EA  : 0x826069D0
// RVA : 0x006069D0
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

const idDeclAnimWebNode::idModelInfo *__fastcall idDeclAnimWebNode::GetAnim(
        idDeclAnimWebNode *this,
        const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *modelIndex,
        int animIndex)
{
  const idDeclAnimWebNode::idModelInfo *result; // r3
  idMD6AnimProps *v5; // r11

  result = idDeclAnimWebNode::FindModelInfo(this, modelIndex);
  if ( result != nullptr )
  {
    if ( animIndex < 0 || animIndex >= result->animProps.num )
      v5 = nullptr;
    else
      v5 = &result->animProps.list[animIndex];
    return (const idDeclAnimWebNode::idModelInfo *)v5->anim;
  }
  return result;
}


// ========================================================================
// ?GetName@idDeclAnimWebNode@@QBAXPBVidDeclAnimWeb@@AAVidStr@@@Z
// EA  : 0x82606DA0
// RVA : 0x00606DA0
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall idDeclAnimWebNode::GetName(idDeclAnimWebNode *this, const idDeclAnimWeb *web, idStr *name)
{
  const char *SubWebName; // r3
  int v7; // r30
  idDeclAnimWeb::stateList_t *p_states; // r29
  unsigned int allocedAndFlag; // r10
  int v10; // r11
  int v11; // r10
  bool v12; // zf
  char *data; // r9
  int v14; // r11
  char *StateName; // r3

  SubWebName = idDeclAnimWeb::GetSubWebName(
                 this: web,
                 index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->subWebIndex.value);
  idStr::operator=(this: name, text: SubWebName);
  v7 = 0;
  if ( this->states.numStates != 0 )
  {
    p_states = &this->states;
    do
    {
      allocedAndFlag = name->allocedAndFlag;
      v10 = name->len + 2;
      v12 = allocedAndFlag >> 31 == 0;
      v11 = allocedAndFlag & 0x7FFFFFFF;
      if ( v12 )
      {
        if ( v10 > v11 )
          idStr::ReAllocate(this: name, amount: (v10 >> 1) + v10, keepold: true);
      }
      else if ( v10 > v11
             && AssertFailed(
                  file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                  line: 463,
                  expression: "amount <= GetAlloced()",
                  inlineBreak: true) )
      {
        __trap();
      }
      name->data[name->len] = 47;
      data = name->data;
      v14 = name->len + 1;
      name->len = v14;
      data[v14] = 0;
      StateName = (char *)idDeclAnimWeb::GetStateName(
                            this: web,
                            index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)p_states->stateIndex[0].value);
      idStr::Append(this: name, text: StateName);
      ++v7;
      p_states = (idDeclAnimWeb::stateList_t *)((char *)p_states + 2);
    }
    while ( v7 < this->states.numStates );
  }
}


// ========================================================================
// ??0idModelInfo@idDeclAnimWebNode@@QAA@XZ
// EA  : 0x82606EB8
// RVA : 0x00606EB8
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

idDeclAnimWebNode::idModelInfo *__fastcall idDeclAnimWebNode::idModelInfo::idModelInfo(
        idDeclAnimWebNode::idModelInfo *this)
{
  this->modelIndex.value = -1;
  this->blendEq.str = &byte_8200D768;
  this->blendEqFixed.str = &byte_8200D768;
  this->animProps.list = nullptr;
  this->animProps.granularity = 0;
  this->animProps.memTag = 32;
  this->animProps.listStatic = 0;
  this->animProps.size = 0;
  this->animProps.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animProps);
  this->coordinates = nullptr;
  this->tagGroups = nullptr;
  return this;
}


// ========================================================================
// ?SetNumCoordinateDimensions@idModelInfo@idDeclAnimWebNode@@QAAXH@Z
// EA  : 0x82606F40
// RVA : 0x00606F40
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall idDeclAnimWebNode::idModelInfo::SetNumCoordinateDimensions(
        idDeclAnimWebNode::idModelInfo *this,
        const int numDimensions)
{
  idList<float,32> *v4; // r30
  idList<float,32> *v5; // r3
  idList<float,32> *v6; // r3
  idList<float,32> *v7; // r3
  idList<float,32> *coordinates; // r3
  int v9; // r4
  float v10; // [sp+50h] [-30h] BYREF

  if ( numDimensions > 0 )
  {
    if ( this->coordinates == nullptr )
    {
      *(float *)&v6 = COERCE_FLOAT(
                        idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x10u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP));
      v10 = *(float *)&v6;
      if ( *(float *)&v6 == 0.0 )
        v7 = nullptr;
      else
        v7 = idList<float,32>::idList<float,32>(this: v6);
      this->coordinates = v7;
    }
    coordinates = this->coordinates;
    v9 = this->animProps.num * numDimensions;
    v10 = 0.0;
    idList<float,17>::SetNum(this: coordinates, newNum: v9, initValue: &v10);
  }
  else
  {
    v4 = this->coordinates;
    if ( *(float *)&v4 != 0.0 )
    {
      v5 = this->coordinates;
      v10 = *(float *)&v4;
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v5);
      idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
      this->coordinates = nullptr;
    }
  }
}


// ========================================================================
// __unwind$225781
// EA  : 0x82607010
// RVA : 0x00607010
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall _unwind_225781(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?CreateSubWebEdges@idDeclAnimWebNode@@QAAXPAVidDeclAnimWeb@@@Z
// EA  : 0x82607350
// RVA : 0x00607350
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall idDeclAnimWebNode::CreateSubWebEdges(
        idDeclAnimWebNode *this,
        idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *decl)
{
  int num; // r10
  int v5; // r29
  int v6; // r10
  int v7; // r11
  encounterGroupRole_t *list; // r18
  int v9; // r19
  idList<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,32> *p_edges; // r27
  encounterGroupRole_t *v11; // r23
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *p_destSubWebIndex; // r4
  idDeclAnimWeb::idSubWebInfo *v13; // r6
  idDeclAnimWeb::idEdgeCache *v14; // r9
  int v15; // ctr
  __int16 value; // r5
  int v17; // r8
  idDeclAnimWebEdge *v18; // r11
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v19; // r5
  idDeclAnimWeb::idSubWebInfo *v20; // r28
  idDeclAnimWeb::idEdgeCache v21; // r24
  int v22; // r25
  int v23; // r26
  int v24; // r5
  __int16 *p_value; // r11
  __int16 v26; // r29
  int v27; // r11
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v28; // r9
  int v29; // ctr
  idDeclAnimWebEdge *v30; // r11
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v31; // r10
  idDeclAnimWeb::idEdgeCache *v32; // r10
  int v33; // r11
  idIndex<short,enum invalidUserChannelIndex_t> v34; // [sp+50h] [-C0h] BYREF
  encounterGroupRole_t v35[3]; // [sp+54h] [-BCh] BYREF
  idList<enum encounterGroupRole_t,5> v36; // [sp+60h] [-B0h] BYREF
  idDeclAnimWebEdge v37[5]; // [sp+70h] [-A0h] BYREF

  memset(&v36, 0, 14);
  *(_WORD *)&v36.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v36);
  num = this->edges.num;
  v5 = 0;
  v35[0] = ROLE_NONE;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      if ( *(unsigned __int16 *)(4 * this->edges.list[v6].value + *(_DWORD *)&decl[68].value) >= 0x8000u )
        idList<idAnimWebBlendTree *,5>::Append(this: &v36, obj: v35);
      v7 = this->edges.num;
      v35[0] = ++v5;
      v6 = v5;
    }
    while ( v5 < v7 );
  }
  list = v36.list;
  if ( v36.num > 0 )
  {
    v9 = v36.num;
    p_edges = &this->edges;
    v11 = v36.list;
    do
    {
      p_destSubWebIndex = &v37[0].destSubWebIndex;
      v13 = *(idDeclAnimWeb::idSubWebInfo **)&decl[36].value;
      v14 = *(idDeclAnimWeb::idEdgeCache **)&decl[68].value;
      v15 = 5;
      value = p_edges->list[*v11].value;
      v17 = value;
      v18 = (idDeclAnimWebEdge *)(32 * value + *(_DWORD *)&decl[60].value);
      HIWORD(v35[0]) = value;
      v19 = &v18->destSubWebIndex;
      v20 = &v13[v18->destSubWebIndex.value];
      v14[v17].destNodeIndex.value = v20->nodes.list->value;
      v37[0].__vftable = (idDeclAnimWebEdge_vtbl *)&idDeclAnimWebEdge::`vftable';
      v37[0].destSubWebIndex.value = v18->destSubWebIndex.value;
      do
      {
        v19 += 2;
        p_destSubWebIndex += 2;
        *(_DWORD *)&p_destSubWebIndex->value = *(_DWORD *)&v19->value;
        --v15;
      }
      while ( v15 != 0 );
      v37[0].customFlags = v18->customFlags;
      v21 = v14[v17];
      v22 = 1;
      if ( v20->nodes.num > 1 )
      {
        v23 = 1;
        do
        {
          v24 = 0;
          p_value = &v20->nodes.list->value;
          v35[0] = (encounterGroupRole_t)this->edges.num;
          v26 = p_value[v23];
          if ( v35[0] > ROLE_NONE )
          {
            v27 = 0;
            do
            {
              if ( *(__int16 *)(4 * p_edges->list[v27].value + *(_DWORD *)&decl[68].value) == v26 )
                break;
              ++v24;
              ++v27;
            }
            while ( v24 < v35[0] );
          }
          if ( v24 >= v35[0] )
          {
            idDeclAnimWeb::AllocEdge(this: (idDeclAnimWeb *)&v34, result: decl);
            idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
              this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&this->edges,
              obj: &v34);
            v28 = &v37[0].destSubWebIndex;
            v29 = 5;
            v30 = (idDeclAnimWebEdge *)(32 * v34.value + *(_DWORD *)&decl[60].value);
            v31 = &v30->destSubWebIndex;
            v30->destSubWebIndex.value = v37[0].destSubWebIndex.value;
            do
            {
              v28 += 2;
              v31 += 2;
              *(_DWORD *)&v31->value = *(_DWORD *)&v28->value;
              --v29;
            }
            while ( v29 != 0 );
            v30->customFlags = v37[0].customFlags;
            v32 = *(idDeclAnimWeb::idEdgeCache **)&decl[68].value;
            v33 = v34.value;
            v32[v33] = v21;
            v32[v33].destNodeIndex.value = v26;
          }
          ++v22;
          ++v23;
        }
        while ( v22 < v20->nodes.num );
      }
      idDeclAnimWebEdge::~idDeclAnimWebEdge(this: v37);
      --v9;
      ++v11;
    }
    while ( v9 != 0 );
  }
  if ( (v36.listStatic == 0 || v36.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
}


// ========================================================================
// __unwind$226847
// EA  : 0x826075E8
// RVA : 0x006075E8
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_226847()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$226848
// EA  : 0x82607610
// RVA : 0x00607610
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_226848()
{
  int v0; // r12

  idDeclAnimWebEdge::~idDeclAnimWebEdge(this: (idDeclAnimWebEdge *)(v0 - 272 + 112));
}


// ========================================================================
// ?Write@idModelInfo@idDeclAnimWebNode@@QBAXPBVidDeclAnimWeb@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@PBVidDeclMD6@@AAVidFile_String@@PBD@Z
// EA  : 0x82607640
// RVA : 0x00607640
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall idDeclAnimWebNode::idModelInfo::Write(
        idDeclAnimWebNode::idModelInfo *this,
        const idDeclAnimWeb *decl,
        __int64 modelDef,
        __int64 indent,
        __int64 a5)
{
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v7; // r22
  idFile_String *v8; // r21
  unsigned int v9; // r20
  va *v10; // r3
  __int64 v11; // r10
  __int64 v12; // r6
  __int64 v13; // r8
  va *v14; // r3
  __int64 v15; // r8
  __int64 v16; // r6
  __int64 v17; // r10
  va *v18; // r3
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  idList<idDeclAnimWebTagGroup,32> *tagGroups; // r11
  int num; // r11
  int v24; // r25
  int v25; // r26
  idList<idDeclAnimWebTagGroup,32> *v26; // r11
  idDeclAnimWebTagGroup *v27; // r29
  __int64 v28; // r6
  va *v29; // r3
  unsigned int i; // r5
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r6
  int v34; // r30
  int v35; // r28
  __int64 v36; // r6
  idDeclAnimWebTag *v37; // r11
  __int64 v38; // r10
  va *v39; // r3
  unsigned int j; // r5
  va *v41; // r3
  unsigned int k; // r5
  va *v43; // r3
  unsigned int m; // r5
  const char *SubWebName; // r3
  __int64 v46; // r10
  __int64 v47; // r8
  __int64 v48; // r6
  char v49; // r27
  int v50; // r30
  int v51; // r28
  char **p_data; // r29
  const idDeclMD6 *v53; // r26
  idDeclAnimWebNode::idModelInfo *v54; // r28
  const char *v55; // r25
  char *v56; // r24
  int v57; // r22
  int v58; // r27
  va *v59; // r3
  unsigned int n; // r5
  idMD6AnimProps *v61; // r3
  const char *v62; // r3
  __int64 v63; // r10
  __int64 v64; // r8
  va *v65; // r3
  unsigned int jj; // r5
  __int64 v67; // r10
  __int64 v68; // r8
  const idMD6Anim *v69; // r3
  const char *str; // r4
  const idMD6Skel *skeleton; // r11
  const idMD6Anim *defaultAnim; // r11
  __int64 v73; // r10
  __int64 v74; // r8
  __int64 v75; // r6
  va *v76; // r3
  va *v77; // r4
  unsigned int ii; // r5
  __int64 v79; // r6
  const idMD6Skel *v80; // r10
  va *v81; // r3
  __int64 v82; // r6
  va *v83; // r3
  unsigned int kk; // r5
  __int64 v85; // r10
  __int64 v86; // r8
  double rate; // fp0
  va *v88; // r3
  unsigned int mm; // r5
  unsigned int tags; // r23
  char v91; // r26
  __int64 v92; // r10
  __int64 v93; // r8
  int v94; // r3
  int v95; // r25
  int nn; // r24
  idList<idDeclAnimWebTagGroup,32> *v97; // r11
  idDeclAnimWebTagGroup *v98; // r27
  int v99; // r11
  int v100; // r28
  int v101; // r30
  int v102; // r29
  va *v103; // r3
  unsigned int i1; // r5
  __int64 v105; // r10
  __int64 v106; // r8
  __int64 v107; // r6
  int v108; // r3
  idList<float,32> *coordinates; // r11
  int v110; // r29
  char v111; // r11
  idList<float,32> *v112; // r11
  float *v113; // r30
  va *v114; // r3
  unsigned int i2; // r5
  __int64 v116; // r10
  __int64 v117; // r8
  __int64 v118; // r6
  float *v119; // r30
  int v120; // r29
  va *v121; // r3
  unsigned int i3; // r5
  const char *v123; // r11
  unsigned int v124; // r5
  va *v125; // r3
  unsigned int i4; // r5
  va *v127; // r3
  unsigned int i5; // r5
  __int64 v129; // r10
  __int64 v130; // r6
  __int64 v131; // r8
  va *v132; // r3
  unsigned int i6; // r5
  idStr *list; // r28
  int size; // r30
  idStr *v136; // r29
  int v137; // [sp+8h] [-1288h]
  int v138; // [sp+8h] [-1288h]
  int v139; // [sp+8h] [-1288h]
  int v140; // [sp+8h] [-1288h]
  int v141; // [sp+8h] [-1288h]
  int v142; // [sp+8h] [-1288h]
  int v143; // [sp+8h] [-1288h]
  int v144; // [sp+8h] [-1288h]
  int v145; // [sp+8h] [-1288h]
  int v146; // [sp+8h] [-1288h]
  int v147; // [sp+Ch] [-1284h]
  int v148; // [sp+Ch] [-1284h]
  int v149; // [sp+Ch] [-1284h]
  int v150; // [sp+Ch] [-1284h]
  int v151; // [sp+Ch] [-1284h]
  int v152; // [sp+Ch] [-1284h]
  int v153; // [sp+Ch] [-1284h]
  int v154; // [sp+Ch] [-1284h]
  int v155; // [sp+Ch] [-1284h]
  int v156; // [sp+Ch] [-1284h]
  int v157; // [sp+10h] [-1280h]
  int v158; // [sp+10h] [-1280h]
  int v159; // [sp+10h] [-1280h]
  int v160; // [sp+10h] [-1280h]
  int v161; // [sp+10h] [-1280h]
  int v162; // [sp+10h] [-1280h]
  int v163; // [sp+10h] [-1280h]
  int v164; // [sp+10h] [-1280h]
  int v165; // [sp+10h] [-1280h]
  int v166; // [sp+10h] [-1280h]
  int v167; // [sp+14h] [-127Ch]
  int v168; // [sp+14h] [-127Ch]
  int v169; // [sp+14h] [-127Ch]
  int v170; // [sp+14h] [-127Ch]
  int v171; // [sp+14h] [-127Ch]
  int v172; // [sp+14h] [-127Ch]
  int v173; // [sp+14h] [-127Ch]
  int v174; // [sp+14h] [-127Ch]
  int v175; // [sp+14h] [-127Ch]
  int v176; // [sp+14h] [-127Ch]
  int v177; // [sp+18h] [-1278h]
  int v178; // [sp+18h] [-1278h]
  int v179; // [sp+18h] [-1278h]
  int v180; // [sp+18h] [-1278h]
  int v181; // [sp+18h] [-1278h]
  int v182; // [sp+18h] [-1278h]
  int v183; // [sp+18h] [-1278h]
  int v184; // [sp+18h] [-1278h]
  int v185; // [sp+18h] [-1278h]
  int v186; // [sp+18h] [-1278h]
  int v187; // [sp+1Ch] [-1274h]
  int v188; // [sp+1Ch] [-1274h]
  int v189; // [sp+1Ch] [-1274h]
  int v190; // [sp+1Ch] [-1274h]
  int v191; // [sp+1Ch] [-1274h]
  int v192; // [sp+1Ch] [-1274h]
  int v193; // [sp+1Ch] [-1274h]
  int v194; // [sp+1Ch] [-1274h]
  int v195; // [sp+1Ch] [-1274h]
  int v196; // [sp+1Ch] [-1274h]
  double v197; // [sp+20h] [-1270h]
  const idMD6Anim *anim; // [sp+50h] [-1240h]
  int v199; // [sp+54h] [-123Ch]
  unsigned __int16 value; // [sp+58h] [-1238h] BYREF
  const char *v201; // [sp+5Ch] [-1234h]
  idList<idStr,5> v202; // [sp+60h] [-1230h] BYREF
  const char *v203; // [sp+70h] [-1220h]
  char *v204; // [sp+74h] [-121Ch]
  const char *v205; // [sp+78h] [-1218h]
  const char *v206; // [sp+7Ch] [-1214h]
  const char *v207; // [sp+80h] [-1210h]
  const char *v208; // [sp+84h] [-120Ch]
  const char *v209; // [sp+88h] [-1208h]
  idStr v210; // [sp+90h] [-1200h] BYREF
  idStr v211; // [sp+B0h] [-11E0h] BYREF
  idStr v212; // [sp+D0h] [-11C0h] BYREF
  _BYTE v213[256]; // [sp+F0h] [-11A0h] BYREF
  va v214; // [sp+1F0h] [-10A0h] BYREF
  const idDeclMD6 *v216; // [sp+12BCh] [+2Ch]

  v216 = (const idDeclMD6 *)modelDef;
  v7 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)HIDWORD(modelDef);
  v8 = (idFile_String *)HIDWORD(indent);
  HIDWORD(modelDef) = indent;
  v9 = indent;
  v10 = va::va(
          this: &v214,
          fmt: "%stree {\n",
          a3: modelDef,
          a4: indent,
          a5,
          a6: v137,
          a7: v147,
          a8: v157,
          a9: v167,
          a10: v177,
          a11: v187);
  idFile_String::operator+=(this: v8, str: v10->buffer);
  HIDWORD(v11) = (unsigned __int16)this->modelIndex.value;
  LODWORD(v11) = &unk_821B0000;
  HIDWORD(v12) = v9;
  LODWORD(v12) = SWORD1(v11);
  v14 = va::va(
          this: &v214,
          fmt: "%s\tmodelIndex %d\n",
          a3: v12,
          a4: v13,
          a5: v11,
          a6: v138,
          a7: v148,
          a8: v158,
          a9: v168,
          a10: v178,
          a11: v188);
  idFile_String::operator+=(this: v8, str: v14->buffer);
  LODWORD(v15) = &unk_821B0000;
  HIDWORD(v16) = v9;
  LODWORD(v16) = this->blendEq.str;
  v18 = va::va(
          this: &v214,
          fmt: "%s\tblendEq \"%s\"\n",
          a3: v16,
          a4: v15,
          a5: v17,
          a6: v139,
          a7: v149,
          a8: v159,
          a9: v169,
          a10: v179,
          a11: v189);
  idFile_String::operator+=(this: v8, str: v18->buffer);
  tagGroups = this->tagGroups;
  if ( tagGroups != nullptr )
    num = tagGroups->num;
  else
    num = 0;
  LODWORD(v19) = &unk_821B0000;
  v206 = "%s\t}\n";
  if ( num > 0 )
  {
    v24 = num;
    LODWORD(v19) = &unk_821B0000;
    v25 = 0;
    do
    {
      v26 = this->tagGroups;
      if ( v26 != nullptr )
      {
        LODWORD(v19) = v26->list;
        v27 = &v26->list[v25];
        v201 = (const char *)this->tagGroups;
      }
      else
      {
        v27 = nullptr;
      }
      LODWORD(v28) = v27->name.str;
      HIDWORD(v28) = v9;
      v29 = va::va(
              this: &v214,
              fmt: "%s\ttagGroup \"%s\" {\n",
              a3: v28,
              a4: v20,
              a5: v19,
              a6: v140,
              a7: v150,
              a8: v160,
              a9: v170,
              a10: v180,
              a11: v190);
      for ( i = 0; v29->buffer[i] != 0; ++i )
        ;
      v8->Write(this: v8, a2: v29, a3: i);
      if ( v27->tagList.num > 0 )
      {
        v34 = 0;
        v35 = v27->tagList.num;
        do
        {
          HIDWORD(v36) = v9;
          v37 = &v27->tagList.list[v34];
          LODWORD(v38) = v37->isDefault;
          LODWORD(v36) = v37->name.str;
          HIDWORD(v38) = v38 - 1;
          HIDWORD(v32) = v38 != 0;
          v39 = va::va(
                  this: &v214,
                  fmt: "%s\t\ttag \"%s\" %i\n",
                  a3: v36,
                  a4: v32,
                  a5: v38,
                  a6: v141,
                  a7: v151,
                  a8: v161,
                  a9: v171,
                  a10: v181,
                  a11: v191);
          for ( j = 0; v39->buffer[j] != 0; ++j )
            ;
          v8->Write(this: v8, a2: v39, a3: j);
          --v35;
          ++v34;
        }
        while ( v35 != 0 );
      }
      HIDWORD(v33) = v9;
      v41 = va::va(
              this: &v214,
              fmt: "%s\t}\n",
              a3: v33,
              a4: v32,
              a5: v31,
              a6: v141,
              a7: v151,
              a8: v161,
              a9: v171,
              a10: v181,
              a11: v191);
      for ( k = 0; v41->buffer[k] != 0; ++k )
        ;
      v8->Write(this: v8, a2: v41, a3: k);
      --v24;
      ++v25;
    }
    while ( v24 != 0 );
  }
  HIDWORD(v21) = v9;
  v43 = va::va(
          this: &v214,
          fmt: "%s\tanims {\n",
          a3: v21,
          a4: v20,
          a5: v19,
          a6: v140,
          a7: v150,
          a8: v160,
          a9: v170,
          a10: v180,
          a11: v190);
  for ( m = 0; v43->buffer[m] != 0; ++m )
    ;
  v8->Write(this: v8, a2: v43, a3: m);
  SubWebName = idDeclAnimWeb::GetSubWebName(this: decl, index: v7);
  idStr::idStr(this: &v211, text: SubWebName);
  *(_WORD *)&v202.memTag = 1280;
  memset(&v202, 0, 14);
  idStrListBreakupString(list: &v202, string: animweb_skipWritingSubWebAnims.valueString.data, separator: 59);
  v49 = 0;
  v50 = 0;
  v51 = v202.num;
  if ( v202.num > 0 )
  {
    p_data = &v202.list->data;
    while ( idStr::Icmp(s1: *p_data, s2: v211.data) != 0 )
    {
      ++v50;
      p_data += 8;
      if ( v50 >= v51 )
        goto LABEL_27;
    }
    v49 = 1;
  }
LABEL_27:
  if ( v49 == 0 )
  {
    v199 = 0;
    LODWORD(v46) = this->animProps.num;
    if ( (int)v46 > 0 )
    {
      v53 = v216;
      v54 = this;
      v55 = " )\n";
      v208 = "%s\t\talias {\n";
      v207 = " )\n";
      LODWORD(v46) = "%s\t\t\tcoordinate ( %g";
      LODWORD(v47) = "%s\t\t\ttags %s\n";
      HIDWORD(v46) = &unk_821B0000;
      v209 = "%s\t\t\tcoordinate ( %g";
      LODWORD(v48) = &unk_821B0000;
      v205 = "%s\t\t\ttags %s\n";
      HIDWORD(v47) = "%s\t\t\trate %g\n";
      v56 = &byte_8200D768;
      v201 = "%s\t\t}\n";
      v57 = 0;
      v203 = "%s\t\t\trate %g\n";
      v58 = 0;
      v204 = &byte_8200D768;
      do
      {
        HIDWORD(v48) = v9;
        v59 = va::va(
                this: &v214,
                fmt: v208,
                a3: v48,
                a4: v47,
                a5: v46,
                a6: v142,
                a7: v152,
                a8: v162,
                a9: v172,
                a10: v182,
                a11: v192);
        for ( n = 0; v59->buffer[n] != 0; ++n )
          ;
        v8->Write(this: v8, a2: v59, a3: n);
        v61 = &v54->animProps.list[v57];
        value = v61->aliasHandle.value;
        if ( value == 0xFFFF )
        {
          v69 = idMD6AnimProps::SelectAnim(this: v61, declMD6: v53, index: 0);
          if ( v69 != nullptr )
            str = v69->name.str;
          else
            str = v56;
          skeleton = v53->model->skeleton;
          if ( skeleton != nullptr )
            defaultAnim = skeleton->defaultAnim;
          else
            defaultAnim = nullptr;
          if ( v69 == defaultAnim )
            str = idMD6Model::DEFAULT_ANIM_NAME;
          HIDWORD(v73) = fileSystem->OSPathToRelativePath(this: fileSystem, a2: str, a3: v213, a4: 256);
          if ( HIDWORD(v73) != 0 )
          {
            LODWORD(v75) = v213;
            HIDWORD(v75) = v9;
            v76 = va::va(
                    this: &v214,
                    fmt: "%s\t\t\tname \"%s\"\n",
                    a3: v75,
                    a4: v74,
                    a5: v73,
                    a6: v143,
                    a7: v153,
                    a8: v163,
                    a9: v173,
                    a10: v183,
                    a11: v193);
            v77 = v76;
            for ( ii = 0; v76->buffer[ii] != 0; ++ii )
              ;
          }
          else
          {
            anim = v54->animProps.list[v57].anim;
            if ( anim != nullptr )
              LODWORD(v79) = anim->name.str;
            else
              LODWORD(v79) = v56;
            v80 = v53->model->skeleton;
            if ( v80 != nullptr )
              LODWORD(v73) = v80->defaultAnim;
            else
              LODWORD(v73) = 0;
            if ( anim == (const idMD6Anim *)v73 )
              LODWORD(v79) = idMD6Model::DEFAULT_ANIM_NAME;
            HIDWORD(v79) = v9;
            v81 = va::va(
                    this: &v214,
                    fmt: "%s\t\t\tname \"%s\"\n",
                    a3: v79,
                    a4: v74,
                    a5: v73,
                    a6: v143,
                    a7: v153,
                    a8: v163,
                    a9: v173,
                    a10: v183,
                    a11: v193);
            v77 = v81;
            for ( ii = 0; v81->buffer[ii] != 0; ++ii )
              ;
          }
          v8->Write(this: v8, a2: v77, a3: ii);
        }
        else
        {
          v62 = animation->FindAliasName(this: animation, a2: &value);
          idStr::idStr(this: &v212, text: v62);
          v65 = va::va(
                  this: &v214,
                  fmt: "%s\t\t\tname \"%s\"\n",
                  a3: __SPAIR64__(v9, (unsigned int)v212.data),
                  a4: v64,
                  a5: v63,
                  a6: v143,
                  a7: v153,
                  a8: v163,
                  a9: v173,
                  a10: v183,
                  a11: v193);
          for ( jj = 0; v65->buffer[jj] != 0; ++jj )
            ;
          v8->Write(this: v8, a2: v65, a3: jj);
          idStr::FreeData(this: &v212);
        }
        HIDWORD(v82) = v9;
        LODWORD(v67) = 4 * v54->animProps.list[v57].wrap;
        LODWORD(v82) = *(const char **)((char *)idMD6Leaf::wrapModeNames + v67);
        v83 = va::va(
                this: &v214,
                fmt: "%s\t\t\twrap %s\n",
                a3: v82,
                a4: v68,
                a5: v67,
                a6: v144,
                a7: v154,
                a8: v164,
                a9: v174,
                a10: v184,
                a11: v194);
        for ( kk = 0; v83->buffer[kk] != 0; ++kk )
          ;
        v8->Write(this: v8, a2: v83, a3: kk);
        rate = v54->animProps.list[v57].rate;
        if ( rate != 1.0 )
        {
          v88 = va::va(
                  this: &v214,
                  fmt: v203,
                  a3: __SPAIR64__(v9, LODWORD(rate)),
                  a4: v86,
                  a5: v85,
                  a6: v145,
                  a7: v155,
                  a8: v165,
                  a9: v175,
                  a10: v185,
                  a11: v195,
                  rate);
          for ( mm = 0; v88->buffer[mm] != 0; ++mm )
            ;
          v8->Write(this: v8, a2: v88, a3: mm);
        }
        tags = v54->animProps.list[v57].tags;
        if ( tags != 0 )
        {
          v210.len = 0;
          v210.baseBuffer[0] = 0;
          v210.allocedAndFlag = 20;
          v210.data = v210.baseBuffer;
          v91 = 0;
          v94 = idDeclAnimWebNode::idModelInfo::NumTagGroups(this: v54);
          if ( v94 > 0 )
          {
            v95 = 0;
            for ( nn = v94; nn != 0; --nn )
            {
              v97 = this->tagGroups;
              if ( v97 != nullptr )
                v98 = &v97->list[v95];
              else
                v98 = nullptr;
              v99 = v98->tagList.num;
              LODWORD(v92) = 1;
              v100 = __ROL4__(1, v91);
              if ( v99 > 0 )
              {
                v101 = 0;
                v102 = v98->tagList.num;
                v91 += v99;
                do
                {
                  if ( (v100 & tags) != 0 )
                  {
                    idStr::Append(this: &v210, text: (char *)v98->tagList.list[v101].name.str);
                    idStr::Append(this: &v210, text: " ");
                  }
                  --v102;
                  v100 = __ROL4__(v100, 1);
                  ++v101;
                }
                while ( v102 != 0 );
              }
              ++v95;
            }
            v55 = v207;
            v56 = v204;
            v58 = v199;
            v54 = this;
          }
          v103 = va::va(
                   this: &v214,
                   fmt: v205,
                   a3: __SPAIR64__(v9, (unsigned int)v210.data),
                   a4: v93,
                   a5: v92,
                   a6: v145,
                   a7: v155,
                   a8: v165,
                   a9: v175,
                   a10: v185,
                   a11: v195);
          for ( i1 = 0; v103->buffer[i1] != 0; ++i1 )
            ;
          v8->Write(this: v8, a2: v103, a3: i1);
          idStr::FreeData(this: &v210);
          v53 = v216;
        }
        v108 = idDeclAnimWebNode::idModelInfo::NumCoordinateDimensions(this: v54);
        coordinates = v54->coordinates;
        v110 = v108;
        if ( coordinates == nullptr || coordinates->num <= 0 || (v111 = 1, v54->animProps.num <= 0) )
          v111 = 0;
        if ( v111 != 0 )
        {
          v112 = v54->coordinates;
          HIDWORD(v105) = v54->animProps.num;
          __twllei(HIDWORD(v105), 0);
          LODWORD(v106) = v112->num;
          LODWORD(v105) = v112->list;
          HIDWORD(v106) = (int)v106 / SHIDWORD(v105);
          LODWORD(v107) = (int)v106 / SHIDWORD(v105) * v58;
          v113 = &v112->list[v107];
          __twlgei(HIDWORD(v105) & ~(__ROL4__(v106, 1) - 1), 0xFFFFFFFF);
          if ( v113 != nullptr && v108 > 0 )
          {
            v114 = va::va(
                     this: &v214,
                     fmt: v209,
                     a3: COERCE__INT64(*v113),
                     a4: v106,
                     a5: v105,
                     a6: v145,
                     a7: v155,
                     a8: v165,
                     a9: v175,
                     a10: v185,
                     a11: v195);
            for ( i2 = 0; v114->buffer[i2] != 0; ++i2 )
              ;
            v8->Write(this: v8, a2: v114, a3: i2);
            if ( v110 > 1 )
            {
              v119 = v113 + 1;
              v120 = v110 - 1;
              do
              {
                v197 = *v119;
                HIDWORD(v118) = LODWORD(v197);
                v121 = va::va(
                         this: &v214,
                         fmt: (const char *)HIDWORD(v197),
                         a3: v118,
                         a4: v117,
                         a5: v116,
                         a6: v145,
                         a7: v155,
                         a8: v165,
                         a9: v175,
                         a10: v185,
                         a11: v195);
                for ( i3 = 0; v121->buffer[i3] != 0; ++i3 )
                  ;
                v8->Write(this: v8, a2: v121, a3: i3);
                --v120;
                ++v119;
              }
              while ( v120 != 0 );
            }
            v123 = v55;
            v124 = 0;
            do
            {
              ++v123;
              ++v124;
            }
            while ( *v123 != 0 );
            v8->Write(this: v8, a2: v55, a3: v124);
          }
        }
        HIDWORD(v107) = v9;
        v125 = va::va(
                 this: &v214,
                 fmt: v201,
                 a3: v107,
                 a4: v106,
                 a5: v105,
                 a6: v145,
                 a7: v155,
                 a8: v165,
                 a9: v175,
                 a10: v185,
                 a11: v195);
        for ( i4 = 0; v125->buffer[i4] != 0; ++i4 )
          ;
        v8->Write(this: v8, a2: v125, a3: i4);
        HIDWORD(v46) = v54->animProps.num;
        ++v58;
        ++v57;
        v199 = v58;
      }
      while ( v58 < SHIDWORD(v46) );
    }
  }
  HIDWORD(v48) = v9;
  v127 = va::va(
           this: &v214,
           fmt: v206,
           a3: v48,
           a4: v47,
           a5: v46,
           a6: v142,
           a7: v152,
           a8: v162,
           a9: v172,
           a10: v182,
           a11: v192);
  for ( i5 = 0; v127->buffer[i5] != 0; ++i5 )
    ;
  v8->Write(this: v8, a2: v127, a3: i5);
  HIDWORD(v129) = &unk_821B0000;
  HIDWORD(v130) = v9;
  v132 = va::va(
           this: &v214,
           fmt: "%s}\n",
           a3: v130,
           a4: v131,
           a5: v129,
           a6: v146,
           a7: v156,
           a8: v166,
           a9: v176,
           a10: v186,
           a11: v196);
  for ( i6 = 0; v132->buffer[i6] != 0; ++i6 )
    ;
  v8->Write(this: v8, a2: v132, a3: i6);
  if ( v202.listStatic == 0 || v202.listStatic == 2 )
  {
    list = v202.list;
    if ( v202.list != nullptr )
    {
      size = v202.size;
      if ( v202.size > 0 )
      {
        v136 = v202.list;
        do
        {
          idStr::FreeData(this: v136);
          --size;
          ++v136;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
  }
  idStr::FreeData(this: &v211);
}


// ========================================================================
// __unwind$227168
// EA  : 0x8260810C
// RVA : 0x0060810C
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_227168()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4752 + 176));
}


// ========================================================================
// __unwind$227169
// EA  : 0x82608134
// RVA : 0x00608134
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_227169()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(v0 - 4752 + 96));
}


// ========================================================================
// __unwind$227170
// EA  : 0x8260815C
// RVA : 0x0060815C
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_227170()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4752 + 208));
}


// ========================================================================
// __unwind$227171
// EA  : 0x82608184
// RVA : 0x00608184
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_227171()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4752 + 144));
}


// ========================================================================
// ?Write@idDeclAnimWebNode@@QBAXPBVidDeclAnimWeb@@AAVidFile_String@@PBD@Z
// EA  : 0x82608308
// RVA : 0x00608308
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall idDeclAnimWebNode::Write(
        idDeclAnimWebNode *this,
        const idDeclAnimWeb *decl,
        __int64 indent,
        __int64 a4,
        __int64 a5)
{
  idFile_String *v7; // r28
  unsigned int v8; // r24
  va *v9; // r3
  __int64 v10; // r10
  __int64 v11; // r6
  __int64 v12; // r8
  va *v13; // r3
  int v14; // r29
  idDeclAnimWeb::stateList_t *p_states; // r30
  __int64 v16; // r6
  __int64 v17; // r10
  __int64 v18; // r8
  va *v19; // r3
  unsigned int i; // r5
  int v21; // r5
  const char *v22; // r11
  __int64 v23; // r10
  __int64 v24; // r6
  __int64 v25; // r8
  va *v26; // r3
  unsigned int j; // r5
  __int64 v28; // r10
  __int64 v29; // r8
  __int64 v30; // r6
  va *v31; // r3
  unsigned int k; // r5
  const char *v33; // r3
  __int64 v34; // r10
  __int64 v35; // r8
  va *v36; // r3
  unsigned int m; // r5
  __int64 v38; // r6
  __int64 v39; // r10
  __int64 v40; // r8
  va *v41; // r3
  unsigned int n; // r5
  va *v43; // r3
  unsigned int ii; // r5
  va *v45; // r3
  unsigned int jj; // r5
  va *v47; // r3
  unsigned int kk; // r5
  va *v49; // r3
  unsigned int mm; // r5
  int customFlags; // r4
  __int64 v52; // r10
  __int64 v53; // r8
  va *v54; // r4
  unsigned int nn; // r5
  va *v56; // r3
  unsigned int i1; // r5
  __int64 v58; // r10
  __int64 v59; // r6
  __int64 v60; // r8
  va *v61; // r3
  unsigned int i2; // r5
  __int64 v63; // r8
  __int64 v64; // r6
  __int64 v65; // r10
  int v66; // r30
  int v67; // r29
  idDeclAnimWebNode::idModelInfo *v68; // r3
  __int64 v69; // r10
  __int64 v70; // r6
  va *v71; // r3
  unsigned int i3; // r5
  __int64 v73; // r8
  __int64 v74; // r6
  __int64 v75; // r10
  idIndex<short,enum invalidUserChannelIndex_t> *list; // r27
  int size; // r11
  int num; // r30
  char v79; // r3
  int v80; // r11
  __int64 v81; // r10
  va *v82; // r3
  unsigned int i4; // r5
  __int64 v84; // r8
  __int64 v85; // r6
  __int64 v86; // r10
  int v87; // r30
  idIndex<short,enum invalidUserChannelIndex_t> *v88; // r29
  __int64 v89; // r10
  __int64 v90; // r6
  int value; // r6
  idDeclAnimWebEdge *v92; // r3
  va *v93; // r3
  unsigned int i5; // r5
  __int64 v95; // r10
  __int64 v96; // r6
  __int64 v97; // r8
  va *v98; // r3
  unsigned int i6; // r5
  int v100; // [sp+8h] [-2108h]
  int v101; // [sp+8h] [-2108h]
  int v102; // [sp+8h] [-2108h]
  int v103; // [sp+8h] [-2108h]
  int v104; // [sp+8h] [-2108h]
  int v105; // [sp+8h] [-2108h]
  int v106; // [sp+8h] [-2108h]
  int v107; // [sp+8h] [-2108h]
  int v108; // [sp+8h] [-2108h]
  int v109; // [sp+8h] [-2108h]
  int v110; // [sp+8h] [-2108h]
  int v111; // [sp+Ch] [-2104h]
  int v112; // [sp+Ch] [-2104h]
  int v113; // [sp+Ch] [-2104h]
  int v114; // [sp+Ch] [-2104h]
  int v115; // [sp+Ch] [-2104h]
  int v116; // [sp+Ch] [-2104h]
  int v117; // [sp+Ch] [-2104h]
  int v118; // [sp+Ch] [-2104h]
  int v119; // [sp+Ch] [-2104h]
  int v120; // [sp+Ch] [-2104h]
  int v121; // [sp+Ch] [-2104h]
  int v122; // [sp+10h] [-2100h]
  int v123; // [sp+10h] [-2100h]
  int v124; // [sp+10h] [-2100h]
  int v125; // [sp+10h] [-2100h]
  int v126; // [sp+10h] [-2100h]
  int v127; // [sp+10h] [-2100h]
  int v128; // [sp+10h] [-2100h]
  int v129; // [sp+10h] [-2100h]
  int v130; // [sp+10h] [-2100h]
  int v131; // [sp+10h] [-2100h]
  int v132; // [sp+10h] [-2100h]
  int v133; // [sp+14h] [-20FCh]
  int v134; // [sp+14h] [-20FCh]
  int v135; // [sp+14h] [-20FCh]
  int v136; // [sp+14h] [-20FCh]
  int v137; // [sp+14h] [-20FCh]
  int v138; // [sp+14h] [-20FCh]
  int v139; // [sp+14h] [-20FCh]
  int v140; // [sp+14h] [-20FCh]
  int v141; // [sp+14h] [-20FCh]
  int v142; // [sp+14h] [-20FCh]
  int v143; // [sp+14h] [-20FCh]
  int v144; // [sp+18h] [-20F8h]
  int v145; // [sp+18h] [-20F8h]
  int v146; // [sp+18h] [-20F8h]
  int v147; // [sp+18h] [-20F8h]
  int v148; // [sp+18h] [-20F8h]
  int v149; // [sp+18h] [-20F8h]
  int v150; // [sp+18h] [-20F8h]
  int v151; // [sp+18h] [-20F8h]
  int v152; // [sp+18h] [-20F8h]
  int v153; // [sp+18h] [-20F8h]
  int v154; // [sp+18h] [-20F8h]
  int v155; // [sp+1Ch] [-20F4h]
  int v156; // [sp+1Ch] [-20F4h]
  int v157; // [sp+1Ch] [-20F4h]
  int v158; // [sp+1Ch] [-20F4h]
  int v159; // [sp+1Ch] [-20F4h]
  int v160; // [sp+1Ch] [-20F4h]
  int v161; // [sp+1Ch] [-20F4h]
  int v162; // [sp+1Ch] [-20F4h]
  int v163; // [sp+1Ch] [-20F4h]
  int v164; // [sp+1Ch] [-20F4h]
  int v165; // [sp+1Ch] [-20F4h]
  idList<idIndex<short,enum invalidUserChannelIndex_t>,5> v166; // [sp+50h] [-20C0h] BYREF
  idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,idSort_EdgeDestName> v167[4]; // [sp+60h] [-20B0h] BYREF
  idStr v168; // [sp+70h] [-20A0h] BYREF
  idStr v169; // [sp+90h] [-2080h] BYREF
  va v170; // [sp+B0h] [-2060h] BYREF
  va v171; // [sp+10B0h] [-1060h] BYREF

  v7 = (idFile_String *)HIDWORD(indent);
  HIDWORD(indent) = indent;
  v8 = indent;
  v9 = va::va(
         this: &v171,
         fmt: "%s\t\t",
         a3: indent,
         a4,
         a5,
         a6: v100,
         a7: v111,
         a8: v122,
         a9: v133,
         a10: v144,
         a11: v155);
  idStr::idStr(this: &v169, text: v9);
  LODWORD(v10) = &unk_821B0000;
  HIDWORD(v11) = v8;
  v13 = va::va(
          this: &v170,
          fmt: "%snode ",
          a3: v11,
          a4: v12,
          a5: v10,
          a6: v101,
          a7: v112,
          a8: v123,
          a9: v134,
          a10: v145,
          a11: v156);
  idFile_String::operator+=(this: v7, str: v13->buffer);
  v14 = 0;
  if ( this->states.numStates != 0 )
  {
    p_states = &this->states;
    do
    {
      HIDWORD(v16) = idDeclAnimWeb::GetStateName(
                       this: decl,
                       index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)p_states->stateIndex[0].value);
      v19 = va::va(
              this: &v170,
              fmt: "\"%s\" ",
              a3: v16,
              a4: v18,
              a5: v17,
              a6: v102,
              a7: v113,
              a8: v124,
              a9: v135,
              a10: v146,
              a11: v157);
      for ( i = 0; v19->buffer[i] != 0; ++i )
        ;
      v7->Write(this: v7, a2: v19, a3: i);
      ++v14;
      p_states = (idDeclAnimWeb::stateList_t *)((char *)p_states + 2);
    }
    while ( v14 < this->states.numStates );
  }
  v21 = 0;
  v22 = "{\n";
  do
  {
    ++v22;
    ++v21;
  }
  while ( *v22 != 0 );
  ((void (__fastcall *)(idFile_String *))v7->Write)(a1: v7);
  HIDWORD(v23) = &unk_821B0000;
  HIDWORD(v24) = v8;
  v26 = va::va(
          this: &v170,
          fmt: "%s\tprops {\n",
          a3: v24,
          a4: v25,
          a5: v23,
          a6: v102,
          a7: v113,
          a8: v124,
          a9: v135,
          a10: v146,
          a11: v157);
  for ( j = 0; v26->buffer[j] != 0; ++j )
    ;
  v7->Write(this: v7, a2: v26, a3: j);
  HIDWORD(v28) = &consoleFont[21088];
  LODWORD(v29) = &unk_821B0000;
  HIDWORD(v29) = idDeclAnimWebNode::animDeltaNames;
  HIDWORD(v30) = v8;
  LODWORD(v30) = *(const char **)((char *)idDeclAnimWebNode::animDeltaNames + __ROL4__(this->animDelta, 2));
  v31 = va::va(
          this: &v170,
          fmt: "%s\t\tdelta %s\n",
          a3: v30,
          a4: v29,
          a5: v28,
          a6: v103,
          a7: v114,
          a8: v125,
          a9: v136,
          a10: v147,
          a11: v158);
  for ( k = 0; v31->buffer[k] != 0; ++k )
    ;
  v7->Write(this: v7, a2: v31, a3: k);
  v33 = idVec3::ToString(this: (idAngles *)&this->settings, precision: 2);
  HIDWORD(v34) = &unk_821B0000;
  v36 = va::va(
          this: &v170,
          fmt: "%s\t\tpos ( %s )\n",
          a3: __SPAIR64__(v8, (unsigned int)v33),
          a4: v35,
          a5: v34,
          a6: v104,
          a7: v115,
          a8: v126,
          a9: v137,
          a10: v148,
          a11: v159);
  for ( m = 0; v36->buffer[m] != 0; ++m )
    ;
  v7->Write(this: v7, a2: v36, a3: m);
  HIDWORD(v39) = this->flags;
  LODWORD(v40) = BYTE3(v39) & 1;
  if ( (v39 & 0x100000000LL) != 0 )
  {
    HIDWORD(v38) = v8;
    v41 = va::va(
            this: &v170,
            fmt: "%s\t\tstartTransition\n",
            a3: v38,
            a4: v40,
            a5: v39,
            a6: v105,
            a7: v116,
            a8: v127,
            a9: v138,
            a10: v149,
            a11: v160);
    for ( n = 0; v41->buffer[n] != 0; ++n )
      ;
    v7->Write(this: v7, a2: v41, a3: n);
  }
  if ( (this->flags & 2) != 0 )
  {
    HIDWORD(v38) = v8;
    LODWORD(v39) = this->flags & 2;
    v43 = va::va(
            this: &v170,
            fmt: "%s\t\tstopTransition\n",
            a3: v38,
            a4: v40,
            a5: v39,
            a6: v105,
            a7: v116,
            a8: v127,
            a9: v138,
            a10: v149,
            a11: v160);
    for ( ii = 0; v43->buffer[ii] != 0; ++ii )
      ;
    v7->Write(this: v7, a2: v43, a3: ii);
  }
  if ( (this->flags & 4) != 0 )
  {
    HIDWORD(v38) = v8;
    LODWORD(v39) = this->flags & 4;
    v45 = va::va(
            this: &v170,
            fmt: "%s\t\tstepTransition\n",
            a3: v38,
            a4: v40,
            a5: v39,
            a6: v105,
            a7: v116,
            a8: v127,
            a9: v138,
            a10: v149,
            a11: v160);
    for ( jj = 0; v45->buffer[jj] != 0; ++jj )
      ;
    v7->Write(this: v7, a2: v45, a3: jj);
  }
  if ( (this->flags & 8) != 0 )
  {
    HIDWORD(v38) = v8;
    LODWORD(v39) = this->flags & 8;
    v47 = va::va(
            this: &v170,
            fmt: "%s\t\tturnTransition\n",
            a3: v38,
            a4: v40,
            a5: v39,
            a6: v105,
            a7: v116,
            a8: v127,
            a9: v138,
            a10: v149,
            a11: v160);
    for ( kk = 0; v47->buffer[kk] != 0; ++kk )
      ;
    v7->Write(this: v7, a2: v47, a3: kk);
  }
  LODWORD(v39) = this->flags & 0x40;
  if ( (this->flags & 0x40) != 0 )
  {
    HIDWORD(v38) = v8;
    v49 = va::va(
            this: &v170,
            fmt: "%s\t\tgenericTransition\n",
            a3: v38,
            a4: v40,
            a5: v39,
            a6: v105,
            a7: v116,
            a8: v127,
            a9: v138,
            a10: v149,
            a11: v160);
    for ( mm = 0; v49->buffer[mm] != 0; ++mm )
      ;
    v7->Write(this: v7, a2: v49, a3: mm);
  }
  customFlags = this->customFlags;
  if ( this->customFlags != 0 )
  {
    v168.len = 0;
    v168.baseBuffer[0] = 0;
    v168.allocedAndFlag = 20;
    v168.data = v168.baseBuffer;
    idTypeInfoTools::GetEnumBitFlags(
      this: typeInfoTools,
      flags: customFlags,
      enumType: "animWebNodeCustomFlag_t",
      flagNames: &v168,
      delimiter: " ");
    v54 = va::va(
            this: &v170,
            fmt: "%s\t\tcustomFlags %s\n",
            a3: __SPAIR64__(v8, (unsigned int)v168.data),
            a4: v53,
            a5: v52,
            a6: v105,
            a7: v116,
            a8: v127,
            a9: v138,
            a10: v149,
            a11: v160);
    for ( nn = 0; v54->buffer[nn] != 0; ++nn )
      ;
    v7->Write(this: v7, a2: v54, a3: nn);
    idStr::FreeData(this: &v168);
  }
  HIDWORD(v38) = v8;
  v56 = va::va(
          this: &v170,
          fmt: "%s\t}\n",
          a3: v38,
          a4: v40,
          a5: v39,
          a6: v105,
          a7: v116,
          a8: v127,
          a9: v138,
          a10: v149,
          a11: v160);
  for ( i1 = 0; v56->buffer[i1] != 0; ++i1 )
    ;
  v7->Write(this: v7, a2: v56, a3: i1);
  HIDWORD(v58) = &unk_821B0000;
  HIDWORD(v59) = v8;
  v61 = va::va(
          this: &v170,
          fmt: "%s\tblendTrees {\n",
          a3: v59,
          a4: v60,
          a5: v58,
          a6: v106,
          a7: v117,
          a8: v128,
          a9: v139,
          a10: v150,
          a11: v161);
  for ( i2 = 0; v61->buffer[i2] != 0; ++i2 )
    ;
  v7->Write(this: v7, a2: v61, a3: i2);
  HIDWORD(v65) = this->modelInfo.num;
  v66 = 0;
  if ( SHIDWORD(v65) > 0 )
  {
    v67 = 0;
    do
    {
      v68 = &this->modelInfo.list[v67];
      if ( v68->animProps.num > 0 )
      {
        HIDWORD(v69) = (__int16)v66;
        LODWORD(v69) = decl->models.list;
        HIDWORD(v70) = (unsigned __int16)this->subWebIndex.value;
        LODWORD(v70) = *(_DWORD *)(4 * (__int16)v66 + v69);
        idDeclAnimWebNode::idModelInfo::Write(
          this: v68,
          decl,
          modelDef: v70,
          indent: __SPAIR64__((unsigned int)v7, (unsigned int)v169.data),
          a5: v69);
      }
      ++v66;
      ++v67;
    }
    while ( v66 < this->modelInfo.num );
  }
  HIDWORD(v64) = v8;
  v71 = va::va(
          this: &v170,
          fmt: "%s\t}\n",
          a3: v64,
          a4: v63,
          a5: v65,
          a6: v107,
          a7: v118,
          a8: v129,
          a9: v140,
          a10: v151,
          a11: v162);
  for ( i3 = 0; v71->buffer[i3] != 0; ++i3 )
    ;
  v7->Write(this: v7, a2: v71, a3: i3);
  HIDWORD(v75) = 5;
  list = nullptr;
  *(_WORD *)&v166.memTag = 1280;
  size = 0;
  memset(&v166, 0, 14);
  num = this->edges.num;
  if ( num > 0 )
  {
    v79 = idList<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,5>::Resize(this: &v166, newsize: this->edges.num);
    list = v166.list;
    if ( v79 == 0 )
      goto LABEL_54;
    size = v166.size;
  }
  v166.num = num;
  if ( num >= size )
    v166.num = size;
LABEL_54:
  LODWORD(v75) = 0;
  if ( this->edges.num > 0 )
  {
    v80 = 0;
    do
    {
      HIDWORD(v75) = this->edges.list;
      LODWORD(v75) = v75 + 1;
      LODWORD(v73) = *(unsigned __int16 *)(HIDWORD(v75) + v80 * 2);
      list[v80++].value = v73;
      HIDWORD(v73) = this->edges.num;
    }
    while ( (int)v75 < SHIDWORD(v73) );
  }
  v167[1].__vftable = (idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,idSort_EdgeDestName>_vtbl *)decl;
  v167[2].__vftable = (idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,idSort_EdgeDestName>_vtbl *)this;
  v167[0].__vftable = (idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,idSort_EdgeDestName>_vtbl *)&idSort_EdgeDestName::`vftable';
  if ( list != nullptr )
    idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,idSort_EdgeDestName>::Sort(
      this: v167,
      base: (idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *)list,
      num: v166.num,
      a4: v74,
      a5: SHIDWORD(v73),
      a6: v73,
      a7: v75);
  LODWORD(v81) = &unk_821B0000;
  HIDWORD(v81) = &idSort<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>>::`vftable';
  v167[0].__vftable = (idSort_Quick<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,idSort_EdgeDestName>_vtbl *)&idSort<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>>::`vftable';
  HIDWORD(v74) = v8;
  v82 = va::va(
          this: &v170,
          fmt: "%s\tedges {\n",
          a3: v74,
          a4: v73,
          a5: v81,
          a6: v108,
          a7: v119,
          a8: v130,
          a9: v141,
          a10: v152,
          a11: v163);
  for ( i4 = 0; v82->buffer[i4] != 0; ++i4 )
    ;
  v7->Write(this: v7, a2: v82, a3: i4);
  HIDWORD(v86) = this->edges.num;
  v87 = 0;
  if ( SHIDWORD(v86) > 0 )
  {
    v88 = list - 1;
    do
    {
      ++v88;
      LODWORD(v89) = decl->edges.list;
      HIDWORD(v90) = this;
      value = v88->value;
      HIDWORD(v89) = decl->edgeCache.list;
      v92 = (idDeclAnimWebEdge *)(32 * value + v89);
      LODWORD(v90) = 4 * value + HIDWORD(v89);
      idDeclAnimWebEdge::Write(
        this: v92,
        decl,
        edgeCache: v90,
        indent: __SPAIR64__((unsigned int)v7, (unsigned int)v169.data),
        a5: v89);
      ++v87;
    }
    while ( v87 < this->edges.num );
  }
  HIDWORD(v85) = v8;
  v93 = va::va(
          this: &v170,
          fmt: "%s\t}\n",
          a3: v85,
          a4: v84,
          a5: v86,
          a6: v109,
          a7: v120,
          a8: v131,
          a9: v142,
          a10: v153,
          a11: v164);
  for ( i5 = 0; v93->buffer[i5] != 0; ++i5 )
    ;
  v7->Write(this: v7, a2: v93, a3: i5);
  HIDWORD(v95) = &unk_821B0000;
  HIDWORD(v96) = v8;
  v98 = va::va(
          this: &v170,
          fmt: "%s}\n",
          a3: v96,
          a4: v97,
          a5: v95,
          a6: v110,
          a7: v121,
          a8: v132,
          a9: v143,
          a10: v154,
          a11: v165);
  for ( i6 = 0; v98->buffer[i6] != 0; ++i6 )
    ;
  v7->Write(this: v7, a2: v98, a3: i6);
  if ( (v166.listStatic == 0 || v166.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  idStr::FreeData(this: &v169);
}


// ========================================================================
// __unwind$228423
// EA  : 0x82608B2C
// RVA : 0x00608B2C
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_228423()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8464 + 144));
}


// ========================================================================
// __unwind$228424
// EA  : 0x82608B54
// RVA : 0x00608B54
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_228424()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 8464 + 112));
}


// ========================================================================
// __unwind$228425
// EA  : 0x82608B7C
// RVA : 0x00608B7C
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_228425()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 8464 + 80));
}


// ========================================================================
// __unwind$228426
// EA  : 0x82608BA4
// RVA : 0x00608BA4
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_228426()
{
  int v0; // r12

  idSort_EdgeDestName::~idSort_EdgeDestName(this: (idSort_EdgeDestName *)(v0 - 8464 + 96));
}


// ========================================================================
// ?AddTagGroup@idModelInfo@idDeclAnimWebNode@@QAAXXZ
// EA  : 0x82608EB8
// RVA : 0x00608EB8
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall idDeclAnimWebNode::idModelInfo::AddTagGroup(idDeclAnimWebNode::idModelInfo *this)
{
  idList<idDeclAnimWebTagGroup,32> *v2; // r3
  idList<idDeclAnimWebTagGroup,32> *v3; // r11
  idDeclAnimWebTagGroup v4[3]; // [sp+50h] [-40h] BYREF

  if ( this->tagGroups == nullptr )
  {
    v2 = (idList<idDeclAnimWebTagGroup,32> *)idMem::AllocWithLocation(
                                               this: &mem,
                                               location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                               size: 0x10u,
                                               tag: TAG_NEW,
                                               zeroBuffer: false,
                                               align: ALIGN_16,
                                               heap: HEAP_DEFAULTHEAP);
    if ( v2 != nullptr )
    {
      v2->granularity = 0;
      v3 = v2;
      v2->memTag = 32;
      v2->listStatic = 0;
      v2->list = nullptr;
      v2->size = 0;
      v2->num = 0;
    }
    else
    {
      v3 = nullptr;
    }
    this->tagGroups = v3;
  }
  idAtomicString::Set(this: &v4[0].name, str_: "TagGroup");
  v4[0].tagList.list = nullptr;
  v4[0].tagList.granularity = 0;
  v4[0].tagList.memTag = 32;
  v4[0].tagList.listStatic = 0;
  v4[0].tagList.size = 0;
  v4[0].tagList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v4[0].tagList);
  idList<idDeclAnimWebTagGroup,32>::Append(this: this->tagGroups, obj: v4);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v4[0].tagList);
}


// ========================================================================
// __unwind$229314
// EA  : 0x82608F84
// RVA : 0x00608F84
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall _unwind_229314(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 100), tag: a2);
}


// ========================================================================
// __unwind$229315
// EA  : 0x82608FAC
// RVA : 0x00608FAC
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_229315()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 144 + 80));
}


// ========================================================================
// ?Parse@idModelInfo@idDeclAnimWebNode@@QAAXPAVidDeclAnimWeb@@PAV2@AAVidParser@@@Z
// EA  : 0x82608FE0
// RVA : 0x00608FE0
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall idDeclAnimWebNode::idModelInfo::Parse(
        idDeclAnimWebNode::idModelInfo *this,
        idDeclAnimWeb *decl,
        idDeclAnimWebNode *node,
        idParser *src)
{
  int changeId; // r11
  char *str; // r11
  char v9; // r11
  bool v10; // zf
  const idMD6Model *model; // r6
  idList<idDeclAnimWebTagGroup,32> *tagGroups; // r11
  int v13; // r11
  int v14; // r28
  int v15; // r30
  unsigned int intvalue; // r11
  idMD6AnimProps *v17; // r3
  idMD6AnimProps *v18; // r20
  bool v19; // r30
  const idMD6Anim *defaultAnim; // r4
  const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *value; // r4
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v22; // r3
  unsigned int v23; // r21
  char v24; // r23
  int v25; // r22
  int v26; // r24
  int v27; // r26
  int v28; // r25
  idList<idDeclAnimWebTagGroup,32> *v29; // r11
  idDeclAnimWebTagGroup *v30; // r27
  int num; // r28
  int v32; // r29
  int v33; // r30
  double v34; // fp31
  int v35; // r10
  int v36; // r9
  int v37; // r8
  int v38; // r7
  int v39; // r6
  int v40; // r5
  int v41; // r4
  int v42; // r3
  unsigned __int16 v43; // [sp+50h] [-3D0h] BYREF
  bool v44; // [sp+52h] [-3CEh]
  idToken v45; // [sp+60h] [-3C0h] BYREF
  float v46; // [sp+A8h] [-378h] BYREF
  const char *v47; // [sp+ACh] [-374h]
  const char *v48; // [sp+B0h] [-370h]
  const char *v49; // [sp+B4h] [-36Ch]
  const idMD6Model *v50; // [sp+B8h] [-368h]
  const char *v51; // [sp+BCh] [-364h]
  const idDeclMD6 *v52; // [sp+C0h] [-360h]
  const char *v53; // [sp+C4h] [-35Ch]
  const char *v54; // [sp+C8h] [-358h]
  const char *v55; // [sp+CCh] [-354h]
  const char *v56; // [sp+D0h] [-350h]
  const char *v57; // [sp+D4h] [-34Ch]
  const char *v58; // [sp+D8h] [-348h]
  const char *v59; // [sp+DCh] [-344h]
  const char *v60; // [sp+E0h] [-340h]
  const char *v61; // [sp+E4h] [-33Ch]
  const char *v62; // [sp+E8h] [-338h]
  const char *v63; // [sp+ECh] [-334h]
  int v64; // [sp+F0h] [-330h] BYREF
  idTypedResourceList<idMD6Anim> *v65; // [sp+F4h] [-32Ch]
  const char *v66; // [sp+F8h] [-328h]
  idDeclAnimWebTag v67[2]; // [sp+100h] [-320h] BYREF
  idList<idVehicleState *,5> v68; // [sp+110h] [-310h] BYREF
  int v69; // [sp+120h] [-300h] BYREF
  idStr v70; // [sp+140h] [-2E0h] BYREF
  idStr v71; // [sp+160h] [-2C0h] BYREF
  idToken v72; // [sp+180h] [-2A0h] BYREF
  idStr v73; // [sp+1D0h] [-250h] BYREF
  int v74; // [sp+204h] [-21Ch]
  float v75; // [sp+208h] [-218h]
  int v76; // [sp+20Ch] [-214h]
  int v77; // [sp+210h] [-210h]
  int v78; // [sp+214h] [-20Ch]
  idToken v79; // [sp+220h] [-200h] BYREF
  char v80; // [sp+268h] [-1B8h] BYREF

  changeId = decl->changeId;
  v45.len = 0;
  decl->changeId = changeId + 1;
  v45.floatvalue = -3.4028235e38;
  v45.data = v45.baseBuffer;
  v45.allocedAndFlag = 20;
  v45.baseBuffer[0] = 0;
  v45.intvalue = 0;
  memset(&v45.whiteSpaceStart_p, 0, 12);
  idParser::ExpectTokenString(this: src, string: "tree");
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v45);
  if ( idParser::PeekTokenString(this: src, string: "modelIndex") != 0 )
  {
    idParser::ExpectTokenString(this: src, string: "modelIndex");
    this->modelIndex.value = idParser::ParseInt(this: src);
  }
  else
  {
    this->modelIndex.value = 0;
  }
  idParser::ExpectTokenString(this: src, string: "blendEq");
  idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v45);
  idAtomicString::Set(this: &this->blendEq, str_: v45.data);
  str = (char *)this->blendEq.str;
  if ( str == &byte_8200D768 || (v10 = *str != 0, v9 = 0, !v10) )
    v9 = 1;
  if ( v9 != 0 )
    idAtomicString::Set(this: &this->blendEq, str_: "anim0");
  model = decl->models.list[this->modelIndex.value]->model;
  v52 = decl->models.list[this->modelIndex.value];
  v50 = model;
  while ( idParser::CheckTokenString(this: src, string: "tagGroup") != 0 )
  {
    idDeclAnimWebNode::idModelInfo::AddTagGroup(this);
    tagGroups = this->tagGroups;
    if ( tagGroups != nullptr )
    {
      v13 = (int)&tagGroups->list[tagGroups->num];
      v47 = (const char *)this->tagGroups;
      v14 = v13 - 20;
    }
    else
    {
      v14 = 0;
    }
    idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v45);
    idAtomicString::Set(this: (idAtomicString *)v14, str_: v45.data);
    idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v45);
    for ( ; idParser::CheckTokenString(this: src, string: "tag") != 0; *(_BYTE *)(v15 + 4) = intvalue != 0 )
    {
      idAtomicString::Set(this: &v67[0].name, str_: "Tag");
      v67[0].isDefault = false;
      idList<idDeclAnimWebTag,32>::Append(this: (idList<idDeclAnimWebTag,32> *)(v14 + 4), obj: v67);
      v15 = 8 * *(_DWORD *)(v14 + 8) + *(_DWORD *)(v14 + 4) - 8;
      idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v45);
      idAtomicString::Set(this: (idAtomicString *)v15, str_: v45.data);
      idParser::ExpectTokenType(this: src, type: 3, subtype: 1, token: &v45);
      if ( v45.type == 3 )
      {
        if ( (v45.subtype & 0x10000) == 0 )
          idToken::NumberValue(this: &v45);
        intvalue = v45.intvalue;
      }
      else
      {
        intvalue = 0;
      }
    }
    idParser::ExpectTokenType(this: src, type: 5, subtype: 47, token: &v45);
  }
  idParser::ExpectTokenString(this: src, string: "anims");
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v45);
  if ( idParser::ReadToken(this: src, token: &v45) )
  {
    v47 = "Unknown token '%s' in 'alias' block.";
    v60 = "repeat";
    v55 = "Unknown token '%s'";
    v51 = ",";
    v49 = "-";
    v59 = "wrap";
    v65 = &idMD6Anim::resourceList;
    v61 = ")";
    v66 = "coordinate";
    v48 = "Unknown tag '%s'";
    v58 = "tags";
    v62 = "rate";
    v56 = "Unknown wrap mode '%s'";
    v54 = "clamp";
    v63 = "node";
    v57 = "name";
    v53 = "alias";
    while ( v45.type != 5 || v45.subtype != 47 )
    {
      if ( idStr::Cmp(s1: v45.data, s2: v53) != 0 )
      {
        idParser::Error(this: src, str: v47, v45.data);
      }
      else
      {
        idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: &v45);
        idParser::ExpectTokenString(this: src, string: v57);
        v79.floatvalue = -3.4028235e38;
        v79.baseBuffer[0] = 0;
        v79.intvalue = 0;
        memset(&v79.whiteSpaceStart_p, 0, 12);
        v80 = 0;
        v79.data = &v80;
        v79.len = 0;
        v79.allocedAndFlag = -2147483392;
        idParser::ExpectTokenType(this: src, type: 1, subtype: 0, token: &v79);
        idStr::BackSlashesToSlashes(this: &v79);
        v17 = idList<idMD6AnimProps,32>::Alloc(this: &this->animProps);
        v75 = -3.4028235e38;
        v73.data = v73.baseBuffer;
        v18 = v17;
        v73.allocedAndFlag = 20;
        v73.len = 0;
        v73.baseBuffer[0] = 0;
        v74 = 0;
        v76 = 0;
        v77 = 0;
        v78 = 0;
        idStr::ExtractFileExtension(this: &v79, dest: &v73);
        if ( idStr::Icmp(s1: v73.data, s2: "md6anim") != 0 )
        {
          if ( v73.len != 0 )
          {
            v71.allocedAndFlag = 20;
            v71.len = 0;
            v71.data = v71.baseBuffer;
            v71.baseBuffer[0] = 0;
            idDeclAnimWebNode::GetName(this: node, web: decl, name: &v71);
            idLib::Error(
              fmt: "Anim web '%s', node '%s' - alias '%s is invalid.  Alias names must not have extensions!",
              decl->name.str,
              v71.data,
              v79.data);
            _LN396(a1: v42, a2: v41, a3: v40, a4: v39, a5: v38, a6: v37, a7: v36, a8: v35);
            return;
          }
          animation->FindAliasHandle(
            this: (idAnimation *)&v43,
            result: (idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)animation,
            a3: v52,
            a4: v79.data);
          value = (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)v43;
          if ( v43 == 0xFFFF )
          {
            v22 = animation->RegisterAlias(this: &v64, result: animation, a3: 0, a4: v79.data);
            value = (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)v22->value;
            v43 = v22->value;
          }
          idMD6AnimProps::SetAliasHandle(this: v18, handle: value);
        }
        else
        {
          v70.allocedAndFlag = 20;
          v70.len = 0;
          v70.data = v70.baseBuffer;
          v70.baseBuffer[0] = 0;
          idDeclAnimWebNode::GetName(this: node, web: decl, name: &v70);
          v19 = idLib::PushWarningInfo(type: v63, name: v70.data);
          v44 = v19;
          if ( idStr::Cmp(s1: v79.data, s2: idMD6Model::DEFAULT_ANIM_NAME) != 0 )
          {
            defaultAnim = (const idMD6Anim *)idResourceList::Load(
                                               this: v65,
                                               name: v79.data,
                                               makeDefault: true,
                                               skipStaleCheck: false);
          }
          else if ( v50 != nullptr )
          {
            defaultAnim = v50->skeleton->defaultAnim;
          }
          else
          {
            defaultAnim = nullptr;
          }
          idMD6AnimProps::SetAnim(this: v18, anim_: defaultAnim);
          if ( v19 )
            idLib::PopWarningInfo();
          idStr::FreeData(this: &v70);
        }
        while ( idParser::ReadToken(this: src, token: &v45) )
        {
          if ( v45.type == 5 && v45.subtype == 47 )
            break;
          if ( idStr::Cmp(s1: v45.data, s2: v59) != 0 )
          {
            if ( idStr::Cmp(s1: v45.data, s2: v62) != 0 )
            {
              if ( idStr::Cmp(s1: v45.data, s2: v58) != 0 )
              {
                if ( idStr::Cmp(s1: v45.data, s2: v66) != 0 )
                {
                  idParser::Error(this: src, str: v55, v45.data);
                }
                else
                {
                  idParser::ExpectTokenString(this: src, string: "(");
                  v68.num = 0;
                  v68.granularity = 1;
                  v68.size = 6;
                  v68.list = (idVehicleState **)&v69;
                  v68.memTag = 5;
                  v68.listStatic = 1;
                  v34 = 1.0;
                  while ( idParser::ReadToken(this: src, token: &v45) )
                  {
                    if ( idStr::Cmp(s1: v45.data, s2: v61) == 0 )
                      break;
                    if ( idStr::Cmp(s1: v45.data, s2: v49) != 0 )
                    {
                      if ( idStr::Cmp(s1: v45.data, s2: v51) != 0 )
                      {
                        v46 = idToken::GetFloatValue(this: &v45) * (float)v34;
                        idList<float,13>::Append(this: (idList<float,13> *)&v68, obj: &v46);
                        v34 = 1.0;
                      }
                    }
                    else
                    {
                      v34 = -1.0;
                    }
                  }
                  idDeclAnimWebNode::idModelInfo::SetNumCoordinateDimensions(this, numDimensions: v68.num);
                  idDeclAnimWebNode::idModelInfo::SetCoordinate(
                    this,
                    propIndex: this->animProps.num - 1,
                    value: (const idList<float,5> *)&v68);
                  idList<idThread *,58>::Clear(this: &v68);
                }
              }
              else
              {
                v72.floatvalue = -3.4028235e38;
                v72.allocedAndFlag = 20;
                v23 = 0;
                v72.data = v72.baseBuffer;
                v72.len = 0;
                v72.baseBuffer[0] = 0;
                v72.intvalue = 0;
                memset(&v72.whiteSpaceStart_p, 0, 12);
                while ( idParser::ReadTokenOnLine(this: src, token: &v72) != 0 )
                {
                  v24 = 0;
                  v25 = idDeclAnimWebNode::idModelInfo::NumTagGroups(this);
                  v26 = 0;
                  v27 = 1;
                  if ( v25 > 0 )
                  {
                    v28 = 0;
                    do
                    {
                      if ( v24 != 0 )
                        break;
                      v29 = this->tagGroups;
                      if ( v29 != nullptr )
                      {
                        v30 = &v29->list[v28];
                        v46 = *(float *)&this->tagGroups;
                      }
                      else
                      {
                        v30 = nullptr;
                      }
                      num = v30->tagList.num;
                      v32 = 0;
                      if ( num > 0 )
                      {
                        v33 = 0;
                        while ( idStr::Cmp(s1: v30->tagList.list[v33].name.str, s2: v72.data) != 0 )
                        {
                          ++v32;
                          v27 = __ROL4__(v27, 1);
                          ++v33;
                          if ( v32 >= num )
                            goto LABEL_66;
                        }
                        v23 |= v27;
                        v24 = 1;
                      }
LABEL_66:
                      ++v26;
                      ++v28;
                    }
                    while ( v26 < v25 );
                  }
                  if ( v24 == 0 )
                    idLib::Warning(fmt: v48, v72.data);
                }
                v18->tags = v23;
                idStr::FreeData(this: &v72);
              }
            }
            else
            {
              v18->rate = idParser::ParseFloat(this: src, errorFlag: nullptr);
            }
          }
          else
          {
            idParser::ExpectTokenType(this: src, type: 4, subtype: 0, token: &v45);
            if ( idStr::Cmp(s1: v45.data, s2: idMD6Leaf::wrapModeNames[0]) != 0
              && idStr::Cmp(s1: v45.data, s2: v54) != 0 )
            {
              if ( idStr::Cmp(s1: v45.data, s2: idMD6Leaf::wrapModeNames[1]) != 0
                && idStr::Cmp(s1: v45.data, s2: v60) != 0 )
              {
                idParser::Error(this: src, str: v56, v45.data);
              }
              else
              {
                v18->wrap = WRAP_REPEAT;
              }
            }
            else
            {
              v18->wrap = WRAP_CLAMP;
            }
          }
        }
        idStr::FreeData(this: &v73);
        idStr::FreeData(this: &v79);
      }
      if ( !idParser::ReadToken(this: src, token: &v45) )
        break;
    }
  }
  idParser::ExpectTokenType(this: src, type: 5, subtype: 47, token: &v45);
  idList<idMD6AnimProps,32>::Resize(this: &this->animProps, newsize: this->animProps.num);
  idDeclAnimWebNode::idModelInfo::FixUpAnimVars(this, declMD6: decl->models.list[this->modelIndex.value]);
  idStr::FreeData(this: &v45);
}


// ========================================================================
// $LN396
// EA  : 0x82609A44
// RVA : 0x00609A44
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _LN396()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1056 + 96));
}


// ========================================================================
// __unwind$229432
// EA  : 0x82609A6C
// RVA : 0x00609A6C
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_229432()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1056 + 544));
}


// ========================================================================
// __unwind$229433
// EA  : 0x82609A94
// RVA : 0x00609A94
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_229433()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1056 + 464));
}


// ========================================================================
// __unwind$229434
// EA  : 0x82609ABC
// RVA : 0x00609ABC
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_229434()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1056 + 320));
}


// ========================================================================
// __unwind$229435
// EA  : 0x82609AE4
// RVA : 0x00609AE4
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_229435()
{
  int v0; // r12

  idWarningInfo::~idWarningInfo(this: (idWarningInfo *)(v0 - 1056 + 82));
}


// ========================================================================
// __unwind$229437
// EA  : 0x82609B0C
// RVA : 0x00609B0C
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_229437()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1056 + 384));
}


// ========================================================================
// __unwind$229438
// EA  : 0x82609B34
// RVA : 0x00609B34
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_229438()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1056 + 272));
}


// ========================================================================
// __unwind$229436
// EA  : 0x82609B5C
// RVA : 0x00609B5C
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_229436()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1056 + 352));
}


// ========================================================================
// ?UpdateTagGroupsList@idModelInfo@idDeclAnimWebNode@@QAAXH@Z
// EA  : 0x82609B90
// RVA : 0x00609B90
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall idDeclAnimWebNode::idModelInfo::UpdateTagGroupsList(
        idDeclAnimWebNode::idModelInfo *this,
        const int numTagGroups)
{
  idList<idDeclAnimWebTagGroup,32> *tagGroups; // r3
  idList<idDeclAnimWebTagGroup,32> *v4; // r3
  idList<idDeclAnimWebTagGroup,32> *v5; // r10

  if ( numTagGroups > 0 )
  {
    if ( this->tagGroups == nullptr )
    {
      v4 = (idList<idDeclAnimWebTagGroup,32> *)idMem::AllocWithLocation(
                                                 this: &mem,
                                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                                 size: 0x10u,
                                                 tag: TAG_NEW,
                                                 zeroBuffer: false,
                                                 align: ALIGN_16,
                                                 heap: HEAP_DEFAULTHEAP);
      if ( v4 != nullptr )
      {
        v4->granularity = 0;
        v5 = v4;
        v4->memTag = 32;
        v4->listStatic = 0;
        v4->list = nullptr;
        v4->size = 0;
        v4->num = 0;
      }
      else
      {
        v5 = nullptr;
      }
      this->tagGroups = v5;
    }
  }
  else
  {
    tagGroups = this->tagGroups;
    if ( tagGroups != nullptr )
    {
      idList<idDeclAnimWebTagGroup,32>::`scalar deleting destructor'(this: tagGroups, a2: 1);
      this->tagGroups = nullptr;
    }
  }
}


// ========================================================================
// __unwind$230143
// EA  : 0x82609C5C
// RVA : 0x00609C5C
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall _unwind_230143(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 112 + 84), tag: a2);
}


// ========================================================================
// ?CopyTagGroups@idModelInfo@idDeclAnimWebNode@@QAAXABV12@@Z
// EA  : 0x82609C88
// RVA : 0x00609C88
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall idDeclAnimWebNode::idModelInfo::CopyTagGroups(
        idDeclAnimWebNode::idModelInfo *this,
        const idDeclAnimWebNode::idModelInfo *other)
{
  idList<idDeclAnimWebTagGroup,32> *tagGroups; // r11
  int num; // r29
  int v6; // ctr
  int v7; // r11

  tagGroups = other->tagGroups;
  if ( tagGroups != nullptr )
    num = tagGroups->num;
  else
    num = 0;
  idDeclAnimWebNode::idModelInfo::UpdateTagGroupsList(this, numTagGroups: num);
  if ( num > 0 )
  {
    idList<idDeclAnimWebTagGroup,32>::operator=(this: this->tagGroups, other: other->tagGroups);
    if ( this->animProps.num > 0 )
    {
      v6 = this->animProps.num;
      v7 = 0;
      do
      {
        this->animProps.list[v7].tags = other->animProps.list[v7].tags;
        ++v7;
        --v6;
      }
      while ( v6 != 0 );
    }
  }
}


// ========================================================================
// ??0idDeclAnimWebNode@@QAA@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x8260A090
// RVA : 0x0060A090
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

idDeclAnimWebNode *__fastcall idDeclAnimWebNode::idDeclAnimWebNode(
        idDeclAnimWebNode *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nodeIndex_,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex_,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *stateIndex_)
{
  __int16 v5; // r27
  __int16 v6; // r26
  __int16 v7; // r25

  this->nodeIndex.value = -1;
  this->subWebIndex.value = -1;
  this->states.stateIndex[0].value = -1;
  this->states.stateIndex[1].value = -1;
  v5 = (__int16)nodeIndex_;
  this->states.stateIndex[2].value = -1;
  v6 = (__int16)subWebIndex_;
  this->states.stateIndex[3].value = -1;
  this->states.numStates = 0;
  v7 = (__int16)stateIndex_;
  this->animDelta = 0;
  this->flags = 0;
  this->customFlags = 0;
  this->edges.list = nullptr;
  this->edges.granularity = 0;
  this->edges.memTag = 32;
  this->edges.listStatic = 0;
  this->edges.size = 0;
  this->edges.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edges);
  this->modelInfo.granularity = 0;
  this->modelInfo.memTag = 32;
  this->modelInfo.listStatic = 0;
  this->modelInfo.list = nullptr;
  this->modelInfo.size = 0;
  this->modelInfo.num = 0;
  this->nodeIndex.value = v5;
  this->subWebIndex.value = v6;
  this->states.numStates = 1;
  this->states.stateIndex[0].value = v7;
  this->settings.pos = vec3_origin;
  return this;
}


// ========================================================================
// __unwind$230531
// EA  : 0x8260A17C
// RVA : 0x0060A17C
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_230531()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 20));
}


// ========================================================================
// ??0idDeclAnimWebNode@@QAA@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@ABVstateList_t@idDeclAnimWeb@@@Z
// EA  : 0x8260A1B0
// RVA : 0x0060A1B0
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

idDeclAnimWebNode *__fastcall idDeclAnimWebNode::idDeclAnimWebNode(
        idDeclAnimWebNode *this,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *nodeIndex_,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *subWebIndex_,
        const idDeclAnimWeb::stateList_t *stateIndices)
{
  idDeclAnimWeb::stateList_t *p_states; // r28
  __int16 v6; // r25
  __int16 v7; // r24
  unsigned __int16 *p_numStates; // r10
  unsigned __int16 *v10; // r9
  int v11; // ctr

  this->nodeIndex.value = -1;
  this->subWebIndex.value = -1;
  p_states = &this->states;
  this->states.stateIndex[0].value = -1;
  this->states.stateIndex[1].value = -1;
  v6 = (__int16)nodeIndex_;
  this->states.stateIndex[2].value = -1;
  v7 = (__int16)subWebIndex_;
  this->states.stateIndex[3].value = -1;
  this->states.numStates = 0;
  this->animDelta = 0;
  this->flags = 0;
  this->customFlags = 0;
  this->edges.list = nullptr;
  this->edges.granularity = 0;
  this->edges.memTag = 32;
  this->edges.listStatic = 0;
  this->edges.size = 0;
  this->edges.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edges);
  this->modelInfo.granularity = 0;
  this->modelInfo.memTag = 32;
  p_numStates = &stateIndices[-1].numStates;
  this->modelInfo.listStatic = 0;
  v10 = &p_states[-1].numStates;
  this->modelInfo.list = nullptr;
  this->modelInfo.size = 0;
  v11 = 5;
  this->modelInfo.num = 0;
  this->nodeIndex.value = v6;
  this->subWebIndex.value = v7;
  do
  {
    *++v10 = *++p_numStates;
    --v11;
  }
  while ( v11 != 0 );
  this->settings.pos = vec3_origin;
  return this;
}


// ========================================================================
// __unwind$230621
// EA  : 0x8260A2AC
// RVA : 0x0060A2AC
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_230621()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 20));
}


// ========================================================================
// ??1idDeclAnimWebNode@@QAA@XZ
// EA  : 0x8260A2E0
// RVA : 0x0060A2E0
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall idDeclAnimWebNode::~idDeclAnimWebNode(idDeclAnimWebNode *this)
{
  idList<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,32> *p_edges; // r29
  char *list; // r3

  p_edges = &this->edges;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edges);
  if ( this->modelInfo.listStatic == 0 || this->modelInfo.listStatic == 2 )
  {
    list = (char *)this->modelInfo.list;
    if ( list != nullptr )
      idListArrayDelete<idDeclAnimWebNode::idModelInfo>(ptr: list, num: this->modelInfo.size);
    this->modelInfo.list = nullptr;
    this->modelInfo.size = 0;
  }
  this->modelInfo.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_edges);
}


// ========================================================================
// __unwind$230704
// EA  : 0x8260A34C
// RVA : 0x0060A34C
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_230704()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 20));
}


// ========================================================================
// __unwind$230705
// EA  : 0x8260A378
// RVA : 0x0060A378
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_230705()
{
  int v0; // r12

  idList<idDeclAnimWebNode::idModelInfo,32>::Clear(this: (idList<idDeclAnimWebNode::idModelInfo,32> *)(*(_DWORD *)(v0 - 128 + 148) + 36));
}


// ========================================================================
// ?AddModelInfo@idDeclAnimWebNode@@QAAXABVidModelInfo@1@V?$idIndex@FW4invalidModelIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x8260A3A8
// RVA : 0x0060A3A8
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __fastcall idDeclAnimWebNode::AddModelInfo(
        idDeclAnimWebNode *this,
        const idDeclAnimWebNode::idModelInfo *info,
        const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t> *modelIndex)
{
  int num; // r7
  __int16 v4; // r29
  int v5; // r10
  int v6; // r11
  __int16 v7; // r30
  idList<idDeclAnimWebNode::idModelInfo,32> *p_modelInfo; // r31

  num = this->modelInfo.num;
  v4 = (__int16)modelIndex;
  v5 = 0;
  if ( num <= 0 )
  {
LABEL_5:
    v7 = -1;
  }
  else
  {
    v6 = 0;
    while ( this->modelInfo.list[v6].modelIndex.value != (__int16)modelIndex )
    {
      ++v5;
      ++v6;
      if ( v5 >= num )
        goto LABEL_5;
    }
    v7 = v5;
  }
  p_modelInfo = &this->modelInfo;
  if ( v7 < 0 )
    v7 = idList<idDeclAnimWebNode::idModelInfo,32>::Append(this: &this->modelInfo, obj: info);
  else
    idDeclAnimWebNode::idModelInfo::operator=(this: &this->modelInfo.list[v7], other: info);
  p_modelInfo->list[v7].modelIndex.value = v4;
}


// ========================================================================
// ?Parse@idDeclAnimWebNode@@QAA_NPAVidDeclAnimWeb@@AAVidParser@@@Z
// EA  : 0x8260A460
// RVA : 0x0060A460
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

int __fastcall idDeclAnimWebNode::Parse(idDeclAnimWebNode *this, idDeclAnimWeb *decl, idParser *src)
{
  int changeId; // r11
  idList<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,32> *p_edges; // r25
  idDeclAnimWeb *v6; // r26
  const char **v8; // r30
  unsigned __int8 v9; // r29
  unsigned __int8 v10; // r10
  const enumTypeInfo_t *EnumInfo; // r3
  const enumTypeInfo_t *v12; // r30
  const enumValueInfo_t *EnumValueInfo; // r3
  idList<idDeclAnimWebNode::idModelInfo,32> *p_modelInfo; // r30
  int num; // r11
  int size; // r10
  idDeclAnimWebNode::idModelInfo *list; // r10
  idDeclAnimWebNode::idModelInfo *v18; // r3
  __int16 *p_granularity; // r9
  int v20; // ctr
  int v21; // r11
  _DWORD *v22; // r10
  idDeclAnimWeb v24; // [sp+50h] [-180h] BYREF

  changeId = decl->changeId;
  p_edges = &this->edges;
  v24.states.num = (int)&this->edges;
  decl->changeId = changeId + 1;
  v6 = decl;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->edges);
  v24.resourceListPtr = nullptr;
  v24.resourceError = (const char *)&v24.staleCount;
  v24.networkID = 20;
  *(float *)&v24.subWebs.list = -3.4028235e38;
  HIBYTE(v24.staleCount) = 0;
  *(_DWORD *)&v24.nodes.granularity = 0;
  memset(&v24.subWebs.num, 0, 12);
  idParser::ExpectTokenString(this: src, string: "props");
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: (idToken *)&v24.resourceListPtr);
  if ( idParser::ReadToken(this: src, token: (idToken *)&v24.resourceListPtr) )
  {
    v24.models.list = (const idDeclMD6 **)"turnTransition";
    v24.models.num = (int)"transition";
    v24.states.list = (idDeclAnimWeb::idStateInfo *)"stepTransition";
    v24.states.size = (int)"stopTransition";
    *(_DWORD *)&v24.states.granularity = "startTransition";
    v24.__vftable = (idDeclAnimWeb_vtbl *)"delta";
    while ( 1 )
    {
      if ( *(_DWORD *)&v24.programaticallyDefined == 5 && v24.declSource == (idDeclSource *)47 )
      {
LABEL_43:
        v6 = decl;
        p_edges = (idList<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,32> *)v24.states.num;
        break;
      }
      if ( idStr::Cmp(s1: v24.resourceError, s2: (const char *)v24.__vftable) == 0 )
      {
        idParser::ReadToken(this: src, token: (idToken *)&v24.resourceListPtr);
        v8 = idDeclAnimWebNode::animDeltaNames;
        v9 = 0;
        this->animDelta = 8;
        while ( idStr::Icmp(s1: *v8, s2: v24.resourceError) != 0 )
        {
          ++v8;
          ++v9;
          if ( (int)v8 >= (int)&dword_835A98D4 )
            goto LABEL_11;
        }
        this->animDelta = v9;
LABEL_11:
        if ( this->animDelta == 8 )
          idParser::Error(
            this: src,
            str: "Unknown animDelta value '%s' in anim web '%s'.",
            v24.resourceError,
            decl->name.str);
        goto LABEL_42;
      }
      if ( idStr::Cmp(s1: v24.resourceError, s2: *(const char **)&v24.states.granularity) != 0
        && idStr::Cmp(s1: v24.resourceError, s2: (const char *)v24.models.num) != 0 )
      {
        if ( idStr::Cmp(s1: v24.resourceError, s2: (const char *)v24.states.size) != 0 )
        {
          if ( idStr::Cmp(s1: v24.resourceError, s2: (const char *)v24.states.list) != 0 )
          {
            if ( idStr::Cmp(s1: v24.resourceError, s2: (const char *)v24.models.list) != 0 )
            {
              if ( idStr::Cmp(s1: v24.resourceError, s2: "blendOutNode") != 0 )
              {
                if ( idStr::Cmp(s1: v24.resourceError, s2: "additiveCamera") != 0 )
                {
                  if ( idStr::Cmp(s1: v24.resourceError, s2: "hide") != 0 )
                  {
                    if ( idStr::Cmp(s1: v24.resourceError, s2: "genericTransition") != 0 )
                    {
                      if ( idStr::Cmp(s1: v24.resourceError, s2: "customFlags") != 0 )
                      {
                        if ( idStr::Cmp(s1: v24.resourceError, s2: "pos") != 0 )
                          idParser::Error(
                            this: src,
                            str: "Unknown token '%s' in anim web node 'props' block.",
                            v24.resourceError);
                        else
                          idParser::Parse1DMatrix(this: src, x: 3, m: &this->settings.pos.x);
                      }
                      else
                      {
                        EnumInfo = idTypeInfoTools::FindEnumInfo(
                                     this: typeInfoTools,
                                     typeName: "animWebNodeCustomFlag_t");
                        *(float *)&v24.scalars.list = -3.4028235e38;
                        *(_DWORD *)&v24.models.granularity = &v24.edges.num;
                        v12 = EnumInfo;
                        v24.edges.list = (idDeclAnimWebEdge *)20;
                        v24.models.size = 0;
                        HIBYTE(v24.edges.num) = 0;
                        *(_DWORD *)&v24.nodeCache.granularity = 0;
                        memset(&v24.scalars.num, 0, 12);
                        while ( idParser::ReadTokenOnLine(this: src, token: (idToken *)&v24.models.size) != 0 )
                        {
                          if ( v12 != nullptr )
                          {
                            EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                                              this: typeInfoTools,
                                              enumInfo: v12,
                                              name: *(const char **)&v24.models.granularity,
                                              defaultIfNotFound: false);
                            if ( EnumValueInfo != nullptr )
                              this->customFlags |= EnumValueInfo->value;
                            else
                              idLib::Warning(
                                fmt: "unrecognized custom flag '%s'",
                                *(const char **)&v24.models.granularity);
                          }
                        }
                        idStr::FreeData(this: (idStr *)&v24.models.size);
                      }
                      goto LABEL_42;
                    }
                    v10 = this->flags | 0x40;
                  }
                  else
                  {
                    v10 = this->flags | 0x80;
                  }
                }
                else
                {
                  v10 = this->flags | 0x20;
                }
              }
              else
              {
                v10 = this->flags | 0x10;
              }
            }
            else
            {
              v10 = this->flags | 8;
            }
          }
          else
          {
            v10 = this->flags | 4;
          }
        }
        else
        {
          v10 = this->flags | 2;
        }
      }
      else
      {
        v10 = this->flags | 1;
      }
      this->flags = v10;
LABEL_42:
      if ( !idParser::ReadToken(this: src, token: (idToken *)&v24.resourceListPtr) )
        goto LABEL_43;
    }
  }
  idParser::ExpectTokenString(this: src, string: "blendTrees");
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: (idToken *)&v24.resourceListPtr);
  if ( idParser::PeekTokenString(this: src, string: "tree") != 0 )
  {
    p_modelInfo = &this->modelInfo;
    do
    {
      idList<idDeclAnimWebNode::idModelInfo,32>::PreAllocateWithGranularity(
        this: &this->modelInfo,
        newSize: this->modelInfo.num + 1);
      num = this->modelInfo.num;
      size = this->modelInfo.size;
      if ( num >= size )
      {
        v18 = &p_modelInfo->list[size - 1];
      }
      else
      {
        list = p_modelInfo->list;
        this->modelInfo.num = num + 1;
        v18 = &list[num];
      }
      idDeclAnimWebNode::idModelInfo::Parse(this: v18, decl: v6, node: this, src);
    }
    while ( idParser::PeekTokenString(this: src, string: "tree") != 0 );
  }
  idList<idDeclAnimWebNode::idModelInfo,32>::Resize(this: &this->modelInfo, newsize: this->modelInfo.num);
  idParser::ExpectTokenType(this: src, type: 5, subtype: 47, token: (idToken *)&v24.resourceListPtr);
  idParser::ExpectTokenString(this: src, string: "edges");
  idParser::ExpectTokenType(this: src, type: 5, subtype: 46, token: (idToken *)&v24.resourceListPtr);
  while ( idParser::ReadToken(this: src, token: (idToken *)&v24.resourceListPtr) )
  {
    if ( *(_DWORD *)&v24.programaticallyDefined == 5 && v24.declSource == (idDeclSource *)47 )
      break;
    if ( idStr::Cmp(s1: v24.resourceError, s2: "edge") != 0 )
    {
      idParser::Error(this: src, str: "Unknown token '%s' in 'edges' block.", v24.resourceError);
    }
    else
    {
      v24.trackedMemory = -61440;
      idDeclAnimWebEdge::idDeclAnimWebEdge(this: (idDeclAnimWebEdge *)&v24.editorModels.size);
      idDeclAnimWebEdge::Parse(
        this: (idDeclAnimWebEdge *)&v24.editorModels.size,
        decl: v6,
        node: this,
        edgeCache: (idDeclAnimWeb::idEdgeCache *)&v24.trackedMemory,
        src);
      idDeclAnimWeb::AllocEdge(this: &v24, result: (idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *)v6);
      idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
        this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)p_edges,
        obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v24);
      p_granularity = &v24.editorModels.granularity;
      v20 = 5;
      v21 = (int)&v6->edges.list[SHIWORD(v24.__vftable)];
      v22 = (_DWORD *)(v21 + 4);
      *(_WORD *)(v21 + 4) = v24.editorModels.granularity;
      do
      {
        p_granularity += 2;
        *++v22 = *(_DWORD *)p_granularity;
        --v20;
      }
      while ( v20 != 0 );
      *(_WORD *)(v21 + 28) = HIWORD(v24.edgeIndexCacheSize);
      v6->edgeCache.list[SHIWORD(v24.__vftable)] = (idDeclAnimWeb::idEdgeCache)v24.trackedMemory;
      idDeclAnimWebEdge::~idDeclAnimWebEdge(this: (idDeclAnimWebEdge *)&v24.editorModels.size);
    }
  }
  idList<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,5>::Resize(
    this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)p_edges,
    newsize: p_edges->num);
  idParser::ExpectTokenType(this: src, type: 5, subtype: 47, token: (idToken *)&v24.resourceListPtr);
  idStr::FreeData(this: (idStr *)&v24.resourceListPtr);
  return 1;
}


// ========================================================================
// __unwind$230837
// EA  : 0x8260AAF4
// RVA : 0x0060AAF4
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_230837()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 96));
}


// ========================================================================
// __unwind$230838
// EA  : 0x8260AB1C
// RVA : 0x0060AB1C
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_230838()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 464 + 192));
}


// ========================================================================
// __unwind$230839
// EA  : 0x8260AB44
// RVA : 0x0060AB44
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void _unwind_230839()
{
  int v0; // r12

  idDeclAnimWebEdge::~idDeclAnimWebEdge(this: (idDeclAnimWebEdge *)(v0 - 464 + 272));
}


// ========================================================================
// `dynamic initializer for 'animweb_skipWritingSubWebAnims''
// EA  : 0x83336560
// RVA : 0x01336560
// PDB : w:\tech5\engine\decls\animwebs\declanimwebnode.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__animweb_skipWritingSubWebAnims__()
{
  idCVar::idCVar(
    this: &animweb_skipWritingSubWebAnims,
    name: "animweb_skipWritingSubWebAnims",
    value: &byte_8200D768,
    flags: 0,
    description: "semi-colon delimited list of subwebs that won't have their anims saved.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__animweb_skipWritingSubWebAnims__);
}

