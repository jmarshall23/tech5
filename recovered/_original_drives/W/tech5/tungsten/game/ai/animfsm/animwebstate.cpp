
// ========================================================================
// ?AsState@idAnimWebState@@QBA?AV1@PBD@Z
// EA  : 0x82A84F98
// RVA : 0x00A84F98
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

idAnimWebState *__fastcall idAnimWebState::AsState(idAnimWebState *this, idAnimWebState *result, const char *state)
{
  idAtomicString *p_debugState; // r11
  idAnimWebState *v5; // r10
  int i; // ctr
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *owner; // r4
  char v9; // [sp+50h] [-20h] BYREF

  p_debugState = &result[-1].debugState;
  v5 = (idAnimWebState *)((char *)this - 4);
  for ( i = 5; i != 0; --i )
  {
    ++p_debugState;
    v5 = (idAnimWebState *)((char *)v5 + 4);
    v5->owner = (const idDeclAnimWeb *)p_debugState->str;
  }
  owner = (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)result->owner;
  if ( owner != nullptr )
    this->state.value = HIWORD(idDeclAnimWeb::GetStateIndexForName(
                                 this: (idDeclAnimWeb *)&v9,
                                 result: owner,
                                 name: state)->__vftable);
  return this;
}


// ========================================================================
// ??0idAnimWebState@@QAA@XZ
// EA  : 0x82A85000
// RVA : 0x00A85000
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

idAnimWebState *__fastcall idAnimWebState::idAnimWebState(idAnimWebState *this)
{
  this->owner = nullptr;
  this->subweb.value = -1;
  this->state.value = -1;
  this->node.value = -1;
  this->pathConstructed = false;
  this->debugSubweb.str = &byte_8200D768;
  this->debugState.str = &byte_8200D768;
  return this;
}


// ========================================================================
// ?Clear@idAnimWebState@@QAAXXZ
// EA  : 0x82A85038
// RVA : 0x00A85038
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

void __fastcall idAnimWebState::Clear(idAnimWebState *this)
{
  this->subweb.value = -1;
  this->owner = nullptr;
  this->state.value = -1;
  this->node.value = -1;
  this->pathConstructed = false;
  this->debugSubweb.str = &byte_8200D768;
  this->debugState.str = &byte_8200D768;
}


// ========================================================================
// ??8idAnimWebState@@QBA_NABV0@@Z
// EA  : 0x82A85070
// RVA : 0x00A85070
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

int __fastcall idAnimWebState::operator==(idAnimWebState *this, const idAnimWebState *other)
{
  unsigned __int8 v2; // r11

  if ( this->owner != other->owner )
    return 0;
  if ( this->subweb.value != other->subweb.value )
    return 0;
  if ( this->state.value != other->state.value )
    return 0;
  v2 = 1;
  if ( this->node.value != other->node.value )
    return 0;
  return v2;
}


// ========================================================================
// ?UpdateDebugInfo@idAnimWebState@@QAAXPBD0@Z
// EA  : 0x82A850C0
// RVA : 0x00A850C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

void __fastcall idAnimWebState::UpdateDebugInfo(
        idAnimWebState *this,
        const char *defaultSubWebName,
        const char *defaultStateName)
{
  __int16 v5; // r11
  idDeclAnimWebNode *v6; // r11
  const idAtomicString *owner; // r4
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *value; // r5
  const char **SubWebNameAtomic; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v10; // r5
  const idAtomicString *v11; // r4
  idAtomicString v12; // [sp+50h] [-30h] BYREF
  idAtomicString v13; // [sp+54h] [-2Ch] BYREF
  _BYTE v14[16]; // [sp+58h] [-28h] BYREF

  if ( this->owner != nullptr && (v5 = this->node.value) >= 0 )
  {
    if ( v5 == -1 )
      v6 = nullptr;
    else
      v6 = this->owner->nodes.list[v5];
    owner = (const idAtomicString *)this->owner;
    value = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v6->subWebIndex.value;
    this->subweb.value = v6->subWebIndex.value;
    this->state.value = v6->states.stateIndex[0].value;
    SubWebNameAtomic = (const char **)idDeclAnimWeb::GetSubWebNameAtomic(
                                        this: (idDeclAnimWeb *)v14,
                                        result: owner,
                                        index: value);
    v10 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->state.value;
    v11 = (const idAtomicString *)this->owner;
    this->debugSubweb.str = *SubWebNameAtomic;
    this->debugState.str = (const char *)idDeclAnimWeb::GetStateNameAtomic(
                                           this: (idDeclAnimWeb *)v14,
                                           result: v11,
                                           index: v10)->__vftable;
  }
  else
  {
    idAtomicString::Set(this: &v12, str_: defaultSubWebName);
    this->debugSubweb = v12;
    idAtomicString::Set(this: &v13, str_: defaultStateName);
    this->debugState = v13;
  }
}


// ========================================================================
// ?GetAnimPath@idAnimWebState@@QBA?AVidAnimWebPath@@XZ
// EA  : 0x82A851A0
// RVA : 0x00A851A0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

idAnimWebState *__fastcall idAnimWebState::GetAnimPath(idAnimWebState *this, idAnimWebState *result)
{
  char *SubWebName; // r28
  char *StateName; // r3
  idStr v7[2]; // [sp+60h] [-50h] BYREF

  v7[0].allocedAndFlag = 20;
  v7[0].data = v7[0].baseBuffer;
  v7[0].len = 0;
  v7[0].baseBuffer[0] = 0;
  if ( idAnimWebState::Verify(this: result, errorMsg: nullptr) )
  {
    SubWebName = (char *)idDeclAnimWeb::GetSubWebName(
                           this: result->owner,
                           index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)result->subweb.value);
    StateName = (char *)idDeclAnimWeb::GetStateName(
                          this: result->owner,
                          index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)result->state.value);
    idAnimWebPath::SetPath(
      this: (idAnimWebPath *)v7,
      webName: (char *)result->owner->name.str,
      subWebName: SubWebName,
      stateName: StateName);
  }
  else
  {
    idStr::Format(this: v7, fmt: "web/%s/%s", result->debugSubweb.str, result->debugState.str);
  }
  idStr::idStr((idStr *)this, text: v7);
  idStr::FreeData(this: v7);
  return this;
}


// ========================================================================
// __unwind$488941
// EA  : 0x82A85280
// RVA : 0x00A85280
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

void _unwind_488941()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$488942
// EA  : 0x82A852A8
// RVA : 0x00A852A8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

void _unwind_488942()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 176;
  if ( (*(_DWORD *)(v0 - 176 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 196));
  }
}


// ========================================================================
// ?Verify@idAnimWebState@@QBA_NPBD@Z
// EA  : 0x82A852F8
// RVA : 0x00A852F8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

int __fastcall idAnimWebState::Verify(idAnimWebState *this, const char *errorMsg)
{
  const idDeclAnimWeb *owner; // r10
  unsigned __int8 v4; // r11
  int v5; // r30
  int value; // r11
  idDeclAnimWebNode *v7; // r11
  idDeclAnimWebNode::idModelInfo *list; // r11
  idAnimWebState *AnimPath; // r3
  idStr v11[2]; // [sp+50h] [-40h] BYREF

  owner = this->owner;
  if ( this->owner == nullptr
    || (unsigned __int16)this->subweb.value == 0xFFFF
    || (unsigned __int16)this->state.value == 0xFFFF
    || (v4 = 1, (unsigned __int16)this->node.value == 0xFFFF) )
  {
    v4 = 0;
  }
  v5 = v4;
  if ( owner != nullptr )
  {
    value = this->node.value;
    if ( value != -1 )
    {
      v7 = owner->nodes.list[value];
      if ( v7 != nullptr
        && (v7->modelInfo.num <= 0
         || (list = v7->modelInfo.list) == nullptr
         || list->animProps.num <= 0
         || list->animProps.list == nullptr) )
      {
        v5 = 0;
      }
    }
  }
  if ( (_BYTE)v5 == 0 && errorMsg != nullptr )
  {
    AnimPath = idAnimWebState::GetAnimPath(this: (idAnimWebState *)v11, result: this);
    idLib::Warning(fmt: "%s : %s", *(const char **)&AnimPath->subweb.value, errorMsg);
    idStr::FreeData(this: v11);
  }
  return v5;
}


// ========================================================================
// __unwind$489162
// EA  : 0x82A853F0
// RVA : 0x00A853F0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

void _unwind_489162()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ??9idAnimWebState@@QBA_NABV0@@Z
// EA  : 0x82A85418
// RVA : 0x00A85418
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

int __fastcall idAnimWebState::operator!=(idAnimWebState *this, const idAnimWebState *other)
{
  unsigned __int8 v2; // r11

  if ( this->owner != other->owner )
    return 1;
  if ( this->subweb.value != other->subweb.value )
    return 1;
  if ( this->state.value != other->state.value )
    return 1;
  v2 = 0;
  if ( this->node.value != other->node.value )
    return 1;
  return v2;
}


// ========================================================================
// ?GetModel@idAnimWebState@@QBAPBVidDeclMD6@@H@Z
// EA  : 0x82A85468
// RVA : 0x00A85468
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

const idDeclMD6 *__fastcall idAnimWebState::GetModel(idAnimWebState *this, __int16 index)
{
  if ( this->owner != nullptr )
    return this->owner->models.list[index];
  else
    return nullptr;
}


// ========================================================================
// ?GetNumAnims@idAnimWebState@@QBAHPBVidDeclMD6@@@Z
// EA  : 0x82A85490
// RVA : 0x00A85490
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

int __fastcall idAnimWebState::GetNumAnims(idAnimWebState *this, const idDeclMD6 *md6)
{
  int value; // r11
  idDeclAnimWebNode *v5; // r11
  idDeclAnimWebNode::idModelInfo *list; // r11

  if ( (unsigned __int8)idAnimWebState::Verify(this, errorMsg: nullptr) != 0
    && md6 != nullptr
    && (value = this->node.value) != -1
    && (v5 = this->owner->nodes.list[value]) != nullptr
    && v5->modelInfo.num > 0
    && (list = v5->modelInfo.list) != nullptr )
  {
    return list->animProps.num;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?GetAnimByIndex@idAnimWebState@@QBAPBVidMD6Anim@@PBVidDeclMD6@@HH@Z
// EA  : 0x82A85530
// RVA : 0x00A85530
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

const idMD6Anim *__fastcall idAnimWebState::GetAnimByIndex(
        idAnimWebState *this,
        const idDeclMD6 *md6,
        int animIndex,
        __int16 modelIndex)
{
  int value; // r11
  idDeclAnimWebNode *v9; // r10
  int v10; // r11

  if ( (unsigned __int8)idAnimWebState::Verify(this, errorMsg: nullptr) != 0
    && md6 != nullptr
    && (value = this->node.value) != -1
    && (v9 = this->owner->nodes.list[value]) != nullptr
    && modelIndex >= 0
    && modelIndex < v9->modelInfo.num
    && (v10 = (int)&v9->modelInfo.list[modelIndex]) != 0
    && animIndex >= 0
    && animIndex < *(_DWORD *)(v10 + 16) )
  {
    return idMD6AnimProps::SelectAnim(
             this: (idMD6AnimProps *)(*(_DWORD *)(v10 + 12) + 20 * animIndex),
             declMD6: md6,
             index: 0);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetAnimDelta@idAnimWebState@@QBA_NPBVidDeclMD6@@HAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82A85610
// RVA : 0x00A85610
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

int __fastcall idAnimWebState::GetAnimDelta(
        idAnimWebState *this,
        const idDeclMD6 *md6,
        int animIndex,
        idVec3 *deltaPos,
        idMat3 *deltaAxis)
{
  idMD6Anim *AnimByIndex; // r3

  AnimByIndex = idAnimWebState::GetAnimByIndex(this, md6, animIndex, modelIndex: 0);
  if ( AnimByIndex == nullptr )
    return 0;
  idMD6Anim::GetAnimationDelta(this: AnimByIndex, deltaTrans: deltaPos, deltaAxis);
  return 1;
}


// ========================================================================
// ?GetAnimWrapMode@idAnimWebState@@QBA?AW4wrapMode_t@idMD6Leaf@@XZ
// EA  : 0x82A85670
// RVA : 0x00A85670
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

idMD6Leaf::wrapMode_t __fastcall idAnimWebState::GetAnimWrapMode(idAnimWebState *this)
{
  __int16 value; // r11
  idMD6Leaf::wrapMode_t result; // r3
  idDeclAnimWebNode *v4; // r11
  idDeclAnimWebNode::idModelInfo *list; // r11

  value = this->node.value;
  result = WRAP_MAX;
  if ( value >= 0 && value != -1 )
  {
    v4 = this->owner->nodes.list[value];
    if ( v4 != nullptr && v4->modelInfo.num > 0 )
    {
      list = v4->modelInfo.list;
      if ( list != nullptr && list->animProps.num > 0 )
        return list->animProps.list->wrap;
    }
  }
  return result;
}


// ========================================================================
// ?GetFlags@idAnimWebState@@QBAHXZ
// EA  : 0x82A856E0
// RVA : 0x00A856E0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

int __fastcall idAnimWebState::GetFlags(idAnimWebState *this)
{
  __int16 value; // r11

  if ( this->owner == nullptr )
    return 0;
  value = this->node.value;
  if ( value < 0 )
    return 0;
  if ( value == -1 )
    return MEMORY[0xF];
  return this->owner->nodes.list[value]->flags;
}


// ========================================================================
// ?GetCustomFlags@idAnimWebState@@QBAHXZ
// EA  : 0x82A85730
// RVA : 0x00A85730
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

int __fastcall idAnimWebState::GetCustomFlags(idAnimWebState *this)
{
  __int16 value; // r11

  if ( this->owner == nullptr )
    return 0;
  value = this->node.value;
  if ( value < 0 )
    return 0;
  if ( value == -1 )
    return MEMORY[0x10];
  return this->owner->nodes.list[value]->customFlags;
}


// ========================================================================
// ?GetBlendParmsToDestination@idAnimWebState@@QBA_NABV1@AAVblendParms_t@@@Z
// EA  : 0x82A85780
// RVA : 0x00A85780
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

int __fastcall idAnimWebState::GetBlendParmsToDestination(
        idAnimWebState *this,
        idAnimWebState *dest,
        blendParms_t *parms)
{
  const idDeclAnimWebEdge *Edge; // r3
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *p_destSubWebIndex; // r11
  char *p_flags; // r10
  int i; // ctr

  if ( (unsigned __int8)idAnimWebState::Verify(this, errorMsg: nullptr) == 0 )
    return 0;
  if ( (unsigned __int8)idAnimWebState::Verify(this: dest, errorMsg: nullptr) == 0 )
    return 0;
  Edge = idDeclAnimWeb::FindEdge(
           this: this->owner,
           srcNode: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)this->node.value,
           dstNode: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)dest->node.value);
  if ( Edge == nullptr )
    return 0;
  p_destSubWebIndex = &Edge->destSubWebIndex;
  p_flags = &parms[-1].parms.flags;
  for ( i = 5; i != 0; --i )
  {
    p_destSubWebIndex += 2;
    p_flags += 4;
    *(_DWORD *)p_flags = *(_DWORD *)&p_destSubWebIndex->value;
  }
  return 1;
}


// ========================================================================
// ?Init@idAnimWebState@@IAAXPBVidDeclAnimWeb@@PBD1@Z
// EA  : 0x82A85810
// RVA : 0x00A85810
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

void __fastcall idAnimWebState::Init(
        idAnimWebState *this,
        const idDeclAnimWeb *decl,
        const char *_subweb,
        const char *_state)
{
  __int16 *SubWebIndexForName; // r3
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *owner; // r4
  __int16 *StateIndexForName; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *value; // r5
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *v11; // r4
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v12; // r6
  _BYTE v13[2]; // [sp+50h] [-30h] BYREF
  char v14; // [sp+52h] [-2Eh] BYREF

  this->owner = decl;
  this->pathConstructed = false;
  if ( decl != nullptr )
  {
    SubWebIndexForName = (__int16 *)idDeclAnimWeb::GetSubWebIndexForName(
                                      this: (idDeclAnimWeb *)v13,
                                      result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)decl,
                                      subWebName: _subweb);
    owner = (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)this->owner;
    this->subweb.value = *SubWebIndexForName;
    StateIndexForName = (__int16 *)idDeclAnimWeb::GetStateIndexForName(
                                     this: (idDeclAnimWeb *)&v14,
                                     result: owner,
                                     name: _state);
    value = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->subweb.value;
    v11 = (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)this->owner;
    v12 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)*StateIndexForName;
    this->state.value = *StateIndexForName;
    this->node.value = HIWORD(idDeclAnimWeb::FindNodeIndex(
                                this: (idDeclAnimWeb *)v13,
                                result: v11,
                                subWebIndex: value,
                                stateIndex: v12)->__vftable);
  }
  idAnimWebState::UpdateDebugInfo(this, defaultSubWebName: _subweb, defaultStateName: _state);
}


// ========================================================================
// ?Init@idAnimWebState@@IAAXPBVidDeclAnimWeb@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82A858A0
// RVA : 0x00A858A0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

void __fastcall idAnimWebState::Init(
        idAnimWebState *this,
        const idDeclAnimWeb *decl,
        idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *_node)
{
  idDeclAnimWebNode *v3; // r11
  __int16 value; // r9

  this->owner = decl;
  this->pathConstructed = false;
  if ( decl != nullptr && (__int16)_node >= 0 )
  {
    if ( (__int16)_node == -1 )
      v3 = nullptr;
    else
      v3 = decl->nodes.list[(__int16)_node];
    this->subweb.value = v3->subWebIndex.value;
    value = v3->states.stateIndex[0].value;
    this->node.value = (__int16)_node;
    this->state.value = value;
  }
  idAnimWebState::UpdateDebugInfo(this, defaultSubWebName: nullptr, defaultStateName: nullptr);
}


// ========================================================================
// ?GetAnimName@idAnimWebState@@QBA?AVidStr@@XZ
// EA  : 0x82A85908
// RVA : 0x00A85908
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

idAnimWebState *__fastcall idAnimWebState::GetAnimName(idAnimWebState *this, idAnimWebState *result)
{
  const char *SubWebName; // r29
  const char *StateName; // r3
  const char *v6; // r6
  const char *v7; // r5

  idStr::idStr((idStr *)this, text: "<none>");
  if ( (unsigned __int8)idAnimWebState::Verify(this: result, errorMsg: nullptr) != 0 )
  {
    SubWebName = idDeclAnimWeb::GetSubWebName(
                   this: result->owner,
                   index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)result->subweb.value);
    StateName = idDeclAnimWeb::GetStateName(
                  this: result->owner,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)result->state.value);
    if ( StateName != nullptr )
      v6 = StateName;
    else
      v6 = "no st";
    if ( SubWebName != nullptr )
      v7 = SubWebName;
    else
      v7 = "no sw";
    idStr::Format((idStr *)this, fmt: "%s/%s", v7, v6);
  }
  return this;
}


// ========================================================================
// __unwind$490295
// EA  : 0x82A859C0
// RVA : 0x00A859C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

void _unwind_490295()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 128;
  if ( (*(_DWORD *)(v0 - 128 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 148));
  }
}


// ========================================================================
// ??0idAnimWebState_Current@@QAA@PBVidAnimator_AnimWeb@@@Z
// EA  : 0x82A85A08
// RVA : 0x00A85A08
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

idAnimWebState_Current *__fastcall idAnimWebState_Current::idAnimWebState_Current(
        idAnimWebState_Current *this,
        const idAnimator_AnimWeb *web)
{
  const idDeclAnimWeb *decl; // r11
  __int16 value; // r10
  idDeclAnimWebNode *v5; // r8

  this->owner = nullptr;
  this->subweb.value = -1;
  this->state.value = -1;
  this->node.value = -1;
  this->pathConstructed = false;
  this->debugSubweb.str = &byte_8200D768;
  this->debugState.str = &byte_8200D768;
  decl = web->decl;
  value = web->curNodeIndex.value;
  this->owner = decl;
  if ( decl != nullptr && value != -1 )
  {
    v5 = decl->nodes.list[value];
    this->subweb.value = v5->subWebIndex.value;
    this->state.value = v5->states.stateIndex[0].value;
    this->node.value = value;
  }
  idAnimWebState::UpdateDebugInfo(this, defaultSubWebName: nullptr, defaultStateName: nullptr);
  return this;
}


// ========================================================================
// ??0idAnimWebState@@QAA@PBVidDeclAnimWeb@@V?$idIndex@FW4invalidNodeIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82A85AB8
// RVA : 0x00A85AB8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

idAnimWebState *__fastcall idAnimWebState::idAnimWebState(
        idAnimWebState *this,
        const idDeclAnimWeb *decl,
        const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *_node)
{
  idDeclAnimWebNode *v3; // r10

  v3 = nullptr;
  this->owner = nullptr;
  this->subweb.value = -1;
  this->state.value = -1;
  this->node.value = -1;
  this->pathConstructed = false;
  this->debugSubweb.str = &byte_8200D768;
  this->debugState.str = &byte_8200D768;
  this->pathConstructed = false;
  this->owner = decl;
  if ( decl != nullptr && (__int16)_node >= 0 )
  {
    if ( (__int16)_node != -1 )
      v3 = decl->nodes.list[(__int16)_node];
    this->subweb.value = v3->subWebIndex.value;
    this->state.value = v3->states.stateIndex[0].value;
    this->node.value = (__int16)_node;
  }
  idAnimWebState::UpdateDebugInfo(this, defaultSubWebName: nullptr, defaultStateName: nullptr);
  return this;
}


// ========================================================================
// ?VerifyDecl@idAnimWebState@@QBA_NPBVidDeclAnimWeb@@@Z
// EA  : 0x82A85B68
// RVA : 0x00A85B68
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebstate.cpp
// ========================================================================

int __fastcall idAnimWebState::VerifyDecl(idAnimWebState *this, const idDeclAnimWeb *decl)
{
  const char *str; // r6
  const char *v5; // r5
  unsigned __int8 v6; // r30
  idAnimWebState v7; // [sp+50h] [-30h] BYREF

  if ( decl == this->owner )
    return 1;
  str = this->debugState.str;
  v5 = this->debugSubweb.str;
  v6 = 0;
  v7.subweb.value = -1;
  v7.owner = nullptr;
  v7.state.value = -1;
  v7.node.value = -1;
  v7.pathConstructed = false;
  v7.debugSubweb.str = &byte_8200D768;
  v7.debugState.str = &byte_8200D768;
  idAnimWebState::Init(this: &v7, decl, _subweb: v5, _state: str);
  if ( this->owner == v7.owner && this->subweb.value == v7.subweb.value && this->state.value == v7.state.value )
    return this->node.value == v7.node.value;
  return v6;
}

