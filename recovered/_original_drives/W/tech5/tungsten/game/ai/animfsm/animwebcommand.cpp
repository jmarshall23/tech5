
// ========================================================================
// ?FireDoneEvent@idAnimWebCmdWaitHandle@@QAAXPAVidEntity@@@Z
// EA  : 0x82A83080
// RVA : 0x00A83080
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void __fastcall idAnimWebCmdWaitHandle::FireDoneEvent(idAnimWebCmdWaitHandle *this, idEntity *ent)
{
  const idEventDef *doneEvent; // r4

  if ( ent != nullptr )
  {
    doneEvent = this->doneEvent;
    if ( doneEvent != nullptr && (*((_BYTE *)this + 149) & 0x80) == 0 )
    {
      idEventReceiver::PostEventMS(this: ent, ev: doneEvent, time: 0);
      *((_BYTE *)this + 149) |= 0x80u;
    }
  }
}


// ========================================================================
// ?Force@idAnimWebCmd@@QAAAAV1@ABVblendParms_t@@@Z
// EA  : 0x82A830E8
// RVA : 0x00A830E8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

idAnimWebCmd *__fastcall idAnimWebCmd::Force(idAnimWebCmd *this, const blendParms_t *bp)
{
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *p_viaWeb; // r10
  char *p_flags; // r11
  int i; // ctr

  p_viaWeb = &this->viaWeb;
  p_flags = &bp[-1].parms.flags;
  this->flags |= 8u;
  for ( i = 5; i != 0; --i )
  {
    p_flags += 4;
    p_viaWeb += 2;
    *(_DWORD *)&p_viaWeb->value = *(_DWORD *)p_flags;
  }
  return this;
}


// ========================================================================
// ?ChangeState@idAnimWebCmd@@QAAAAV1@ABVidAnimWebState@@@Z
// EA  : 0x82A83118
// RVA : 0x00A83118
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

idAnimWebCmd *__fastcall idAnimWebCmd::ChangeState(idAnimWebCmd *this, const idAnimWebState *_dst)
{
  idAtomicString *p_debugState; // r10
  idAtomicString *v3; // r11
  int i; // ctr

  p_debugState = &this->via.debugState;
  v3 = &_dst[-1].debugState;
  this->flags |= 2u;
  for ( i = 5; i != 0; --i )
  {
    ++v3;
    ++p_debugState;
    p_debugState->str = v3->str;
  }
  return this;
}


// ========================================================================
// ?Via@idAnimWebCmd@@QAAAAV1@ABVidAnimWebState@@_N@Z
// EA  : 0x82A83148
// RVA : 0x00A83148
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

idAnimWebCmd *__fastcall idAnimWebCmd::Via(idAnimWebCmd *this, idAnimWebState *_via, bool optional)
{
  unsigned int *p_groupFilter; // r10
  idAtomicString *p_debugState; // r11
  int i; // ctr

  if ( !optional || idAnimWebState::Verify(this: _via, errorMsg: nullptr) )
  {
    p_groupFilter = &this->groupFilter;
    p_debugState = &_via[-1].debugState;
    this->flags |= 4u;
    for ( i = 5; i != 0; --i )
    {
      ++p_debugState;
      *++p_groupFilter = (unsigned int)p_debugState->str;
    }
  }
  return this;
}


// ========================================================================
// ?GetStatusMsg@idAnimWebCmd@@SAPBDW4awCmdStatus_t@@@Z
// EA  : 0x82A831D0
// RVA : 0x00A831D0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

const char *__fastcall idAnimWebCmd::GetStatusMsg(int status)
{
  const enumValueInfo_t *EnumValueInfo; // r3

  EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                    this: typeInfoTools,
                    enumName: "awCmdStatus_t",
                    value: status,
                    defaultIfNotFound: false);
  if ( EnumValueInfo != nullptr )
    return EnumValueInfo->name;
  else
    return "unknown";
}


// ========================================================================
// ?HasActiveWaitHandle@idAnimWebCmdCtx@@QBA_NXZ
// EA  : 0x82A83288
// RVA : 0x00A83288
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

BOOL __fastcall idAnimWebCmdCtx::HasActiveWaitHandle(idAnimWebCmdCtx *this)
{
  idAnimWebCmdWaitHandle *activeWaitHandle; // r11

  activeWaitHandle = this->activeWaitHandle;
  return activeWaitHandle != nullptr && (_cntlzw(activeWaitHandle->status - 8) & 0x20) != 0;
}


// ========================================================================
// ?IsGroupAllowed@idAnimWebCmdCtx@@QBA_NK@Z
// EA  : 0x82A832B0
// RVA : 0x00A832B0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

int __fastcall idAnimWebCmdCtx::IsGroupAllowed(idAnimWebCmdCtx *this, unsigned int _groupBits)
{
  idAnimWebCmdWaitHandle *activeWaitHandle; // r10
  bool v3; // r11

  activeWaitHandle = this->activeWaitHandle;
  if ( activeWaitHandle != nullptr && activeWaitHandle->status == AWCMD_STATUS_WAITING )
  {
    if ( activeWaitHandle->lockMask != 0 || (v3 = false, this->lockedFlags != 0) )
      v3 = true;
  }
  else
  {
    v3 = this->lockedFlags != 0;
  }
  if ( v3 )
    return 0;
  if ( _groupBits == 0x80000000 )
    return 1;
  if ( activeWaitHandle != nullptr && activeWaitHandle->status == AWCMD_STATUS_WAITING )
    return (activeWaitHandle->groupFilter & _groupBits) != 0;
  return (this->groupFilter & _groupBits) != 0;
}


// ========================================================================
// ?Force@idAnimWebCmd@@QAAAAV1@HW4originBlend_t@idMD6Blend@@@Z
// EA  : 0x82A833B8
// RVA : 0x00A833B8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

idAnimWebCmd *__fastcall idAnimWebCmd::Force(
        idAnimWebCmd *this,
        int blendFrames,
        const idMD6Blend::originBlend_t originBlend)
{
  char v5; // r29
  char *v6; // r11
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *p_viaWeb; // r10
  int v8; // ctr
  char v10; // [sp+4Ch] [-44h] BYREF
  blendParms_t v11[3]; // [sp+50h] [-40h] BYREF

  v5 = originBlend;
  blendParms_t::blendParms_t(this: v11);
  v11[0].parms.originBlend = v5;
  blendParms_t::SetDuration(this: v11, frame: blendFrames);
  v6 = &v10;
  p_viaWeb = &this->viaWeb;
  v8 = 5;
  this->flags |= 8u;
  do
  {
    v6 += 4;
    p_viaWeb += 2;
    *(_DWORD *)&p_viaWeb->value = *(_DWORD *)v6;
    --v8;
  }
  while ( v8 != 0 );
  return this;
}


// ========================================================================
// ?ViaSubweb@idAnimWebCmd@@QAAAAV1@PBD@Z
// EA  : 0x82A83420
// RVA : 0x00A83420
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

idAnimWebCmd *__fastcall idAnimWebCmd::ViaSubweb(idAnimWebCmd *this, const char *subweb)
{
  __int16 *SubWebIndexForName; // r3
  __int16 v4; // r9
  idAnimWebCmd *result; // r3
  char v6; // [sp+50h] [-20h] BYREF

  SubWebIndexForName = (__int16 *)idDeclAnimWeb::GetSubWebIndexForName(
                                    this: (idDeclAnimWeb *)&v6,
                                    result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)this->owner->animWeb->decl,
                                    subWebName: subweb);
  v4 = *SubWebIndexForName;
  this->viaWeb.value = *SubWebIndexForName;
  result = this;
  if ( v4 >= 0 )
    this->flags |= 0x20u;
  return result;
}


// ========================================================================
// ??0idAnimEventInfo_t@idAnimWebCmdWaitHandle@@QAA@XZ
// EA  : 0x82A83488
// RVA : 0x00A83488
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

idAnimWebCmdWaitHandle::idAnimEventInfo_t *__fastcall idAnimWebCmdWaitHandle::idAnimEventInfo_t::idAnimEventInfo_t(
        idAnimWebCmdWaitHandle::idAnimEventInfo_t *this)
{
  this->stateIndex.value = -1;
  this->subWebIndex.value = -1;
  this->stateIndex.value = -1;
  this->eventType = ANIMWEB_EVENT_MAX;
  return this;
}


// ========================================================================
// ?Reset@idAnimWebCmd@@QAAAAV1@XZ
// EA  : 0x82A834A8
// RVA : 0x00A834A8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

idAnimWebCmd *__fastcall idAnimWebCmd::Reset(idAnimWebCmd *this)
{
  idAnimWebCmdCtx *owner; // r10
  unsigned int defaultAnimWebCmdGroupFilter; // r11
  idAnimWebState *v4; // r3
  unsigned int *p_groupFilter; // r10
  idAtomicString *p_debugState; // r11
  int i; // ctr
  idAnimWebState *v8; // r3
  idAtomicString *v9; // r10
  idAtomicString *v10; // r11
  int j; // ctr
  blendParms_t *v12; // r3
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *p_viaWeb; // r10
  char *p_flags; // r11
  int k; // ctr
  char v16; // r4
  idAnimWebState v18; // [sp+50h] [-70h] BYREF
  int v19; // [sp+70h] [-50h]
  int v20; // [sp+74h] [-4Ch]
  int v21; // [sp+78h] [-48h]
  animDeltaCorrection_t::input_t v22; // [sp+7Ch] [-44h] BYREF

  owner = this->owner;
  defaultAnimWebCmdGroupFilter = -1;
  this->groups = -1;
  if ( owner != nullptr )
    defaultAnimWebCmdGroupFilter = owner->defaultAnimWebCmdGroupFilter;
  this->groupFilter = defaultAnimWebCmdGroupFilter;
  v4 = idAnimWebState::idAnimWebState(this: &v18);
  p_groupFilter = &this->groupFilter;
  p_debugState = &v4[-1].debugState;
  for ( i = 5; i != 0; --i )
  {
    ++p_debugState;
    *++p_groupFilter = (unsigned int)p_debugState->str;
  }
  v8 = idAnimWebState::idAnimWebState(this: &v18);
  v9 = &this->via.debugState;
  v10 = &v8[-1].debugState;
  for ( j = 5; j != 0; --j )
  {
    ++v10;
    ++v9;
    v9->str = v10->str;
  }
  v12 = blendParms_t::blendParms_t(this: (blendParms_t *)&v18);
  p_viaWeb = &this->viaWeb;
  p_flags = &v12[-1].parms.flags;
  for ( k = 5; k != 0; --k )
  {
    p_flags += 4;
    p_viaWeb += 2;
    *(_DWORD *)&p_viaWeb->value = *(_DWORD *)p_flags;
  }
  v16 = *((_BYTE *)&v22 + 41);
  this->flags = 512;
  this->intrPath = INTR_PATH_YES;
  this->pathResult = AWPATH_OK;
  this->blendEventMask = 0;
  this->doneEvent = nullptr;
  this->intrBlend = INTR_BLEND_NO;
  this->lockMask = 0;
  *((_BYTE *)&v22 + 40) = 0;
  v22.translationCorrectionMaxScale = 0.0;
  v22.rotationMaxScale = 0.0;
  v22.rotationMinScale = 0.0;
  v22.rotationRateMax = 0.0;
  *((_BYTE *)&v22 + 41) = v16 & 3 | 0x40;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22.translationCorrectionPerFrameMax = vec3_origin;
  v22.translationPerFrameMax = vec3_origin;
  this->deltaCorrectParms.correctIdealPoint = IDEALPOINT_NONE;
  this->deltaCorrectParms.correctIdealDir = IDEALDIR_NONE;
  this->deltaCorrectParms.correctGravity = B_FALSE;
  animDeltaCorrection_t::input_t::operator=(this: &this->deltaCorrectParms.parms, __that: &v22);
  this->forceFallbackPathSize = 0;
  return this;
}


// ========================================================================
// ShowDebug
// EA  : 0x82A83630
// RVA : 0x00A83630
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

int __fastcall ShowDebug(idEntity *ent)
{
  int result; // r3
  bool v2; // zf

  if ( awcmd_debug.valueInteger > 0 )
  {
    if ( awcmd_debug.valueInteger == 1 )
    {
      v2 = idGameLocal::GetDebugEntity(this: gameLocal) == ent;
      result = 1;
      if ( v2 )
        return result;
    }
    else if ( awcmd_debug.valueInteger < 3u || awcmd_debug.valueInteger == ent->entityNumber )
    {
      return 1;
    }
  }
  return 0;
}


// ========================================================================
// ?Verify@idAnimWebCmdWaitHandle@@QAA_NXZ
// EA  : 0x82A836C0
// RVA : 0x00A836C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

int __fastcall idAnimWebCmdWaitHandle::Verify(idAnimWebCmdWaitHandle *this)
{
  int value; // r10
  idEntity *v3; // r3
  unsigned __int8 v4; // r11

  value = this->owner.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v3 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v3 == nullptr )
    return 0;
  if ( idEntity::CastTo(c: v3) == nullptr )
    return 0;
  v4 = 1;
  if ( this->status == AWCMD_STATUS_INVALID )
    return 0;
  return v4;
}


// ========================================================================
// ?Init@idAnimWebCmdWaitHandle@@QAAXXZ
// EA  : 0x82A83748
// RVA : 0x00A83748
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void __fastcall idAnimWebCmdWaitHandle::Init(idAnimWebCmdWaitHandle *this)
{
  char v1; // r6

  this->owner.spawnId.value = 0x1FFF;
  this->userString = nullptr;
  this->animEventInfo.subWebIndex.value = -1;
  this->animEventInfo.stateIndex.value = -1;
  this->animEventInfo.eventType = ANIMWEB_EVENT_MAX;
  this->animEventInfoDC.subWebIndex.value = -1;
  this->animEventInfoDC.stateIndex.value = -1;
  this->animEventInfoDC.eventType = ANIMWEB_EVENT_MAX;
  v1 = *((_BYTE *)this + 149) & 0x3F | 0x40;
  this->status = AWCMD_STATUS_INVALID;
  this->doneEvent = nullptr;
  this->groups = -1;
  this->groupFilter = -1;
  this->priority = AWCMD_PRIORITY_LOW;
  this->lockMask = 0;
  this->finishTime = 0;
  this->flags = 0;
  *((_BYTE *)this + 149) = v1;
}


// ========================================================================
// ?GetContext@idAnimWebCmdWaitHandle@@IAAPAVidAnimWebCmdCtx@@XZ
// EA  : 0x82A837B0
// RVA : 0x00A837B0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

const idAnimWebCmdCtx *__fastcall idAnimWebCmdWaitHandle::GetContext(idAnimWebCmdWaitHandle *this)
{
  int value; // r10
  idEntity *v3; // r3
  int v4; // r9
  idEntity *v5; // r3
  idEntity *v6; // r3

  value = this->owner.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return nullptr;
  v3 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v3 == nullptr || idEntity::CastTo(c: v3) == nullptr )
    return nullptr;
  v4 = this->owner.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v4 & 0x1FFF] != v4 >> 13 )
    return (*(const idAnimWebCmdCtx *(**)(void))(MEMORY[0] + 212))();
  v5 = gameLocal->entities.ptr[v4 & 0x1FFF];
  if ( v5 == nullptr )
    return (*(const idAnimWebCmdCtx *(**)(void))(MEMORY[0] + 212))();
  v6 = idEntity::CastTo(c: v5);
  return v6->GetAnimWebCmdCtx(this: v6);
}


// ========================================================================
// ?ReportStatus@idAnimWebCmdWaitHandle@@IAA?AW4awCmdStatus_t@@W42@@Z
// EA  : 0x82A83898
// RVA : 0x00A83898
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

int __fastcall idAnimWebCmdWaitHandle::ReportStatus(idAnimWebCmdWaitHandle *this, int status)
{
  const idAnimWebCmdCtx *Context; // r3
  const idAnimWebCmdCtx *v5; // r29
  const char *userString; // r31
  const char *data; // r29
  const char *StatusMsg; // r3

  Context = idAnimWebCmdWaitHandle::GetContext(this);
  v5 = Context;
  if ( Context != nullptr && (unsigned __int8)ShowDebug(ent: Context->entity) != 0 && awcmd_debugLevel.valueInteger > 0 )
  {
    userString = this->userString;
    if ( userString == nullptr )
      userString = "unknown";
    data = v5->entity->name.data;
    StatusMsg = idAnimWebCmd::GetStatusMsg(status);
    idLib::Printf(fmt: "[%s] : wait status : '%s' : '%s'\n", data, StatusMsg, userString);
  }
  return status;
}


// ========================================================================
// ?GetDebugString@idAnimWebCmdWaitHandle@@QBAXAAVidStr@@0@Z
// EA  : 0x82A83930
// RVA : 0x00A83930
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void __fastcall idAnimWebCmdWaitHandle::GetDebugString(idAnimWebCmdWaitHandle *this, idStr *info, idStr *waitPath)
{
  const char *v6; // r28
  const idAnimWebCmdCtx *Context; // r3
  const char *userString; // r5
  const idAnimWebCmdCtx *v9; // r27
  int value; // r9
  idGameLocal *v11; // r11
  idEntity *v12; // r3
  const char *SubWebName; // r3
  const char *v14; // r31
  int v15; // r9
  idEntity *v16; // r3
  const char *StateName; // r3
  const char *v18; // r6
  const char *v19; // r5

  v6 = "<unknown event>";
  switch ( this->animEventInfo.eventType )
  {
    case ANIMWEB_EVENT_NONE:
    case ANIMWEB_EVENT_MAX:
      v6 = "NONE";
      break;
    case ANIMWEB_EVENT_START_BLEND_IN:
      v6 = "START_BLEND_IN";
      break;
    case ANIMWEB_EVENT_START_BLEND_OUT:
      v6 = "START_BLEND_OUT";
      break;
    case ANIMWEB_EVENT_END_BLEND_IN:
      v6 = "END_BLEND_IN";
      break;
    case ANIMWEB_EVENT_END_BLEND_OUT:
      v6 = "END_BLEND_OUT";
      break;
    case ANIMWEB_EVENT_DEST_START_BLEND_IN:
      v6 = "DEST_START_BLEND_IN";
      break;
    case ANIMWEB_EVENT_DEST_END_BLEND_IN:
      v6 = "DEST_END_BLEND_IN";
      break;
    case ANIMWEB_EVENT_DEST_CLAMPED:
      v6 = "DEST_CLAMPED";
      break;
    default:
      break;
  }
  Context = idAnimWebCmdWaitHandle::GetContext(this);
  userString = this->userString;
  v9 = Context;
  if ( userString == nullptr )
    userString = "<no user str>";
  idStr::Format(this: info, fmt: "%s : %s", userString, v6);
  value = this->owner.spawnId.value;
  v11 = gameLocal;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    goto LABEL_17;
  v12 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v12 == nullptr )
    goto LABEL_17;
  if ( idEntity::CastTo(c: v12) == nullptr )
  {
    v11 = gameLocal;
LABEL_17:
    v14 = "<null>";
    goto LABEL_18;
  }
  SubWebName = idDeclAnimWeb::GetSubWebName(
                 this: v9->animWeb->decl,
                 index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->animEventInfo.subWebIndex.value);
  v11 = gameLocal;
  v14 = SubWebName;
LABEL_18:
  v15 = this->owner.spawnId.value;
  if ( v11->spawnIds.ptr[v15 & 0x1FFF] == v15 >> 13
    && (v16 = v11->entities.ptr[v15 & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v16) != nullptr )
  {
    StateName = idDeclAnimWeb::GetStateName(
                  this: v9->animWeb->decl,
                  index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->animEventInfo.stateIndex.value);
    if ( StateName == nullptr )
    {
LABEL_25:
      v18 = "<no state>";
      goto LABEL_26;
    }
  }
  else
  {
    StateName = "<null>";
  }
  if ( *StateName == 0 )
    goto LABEL_25;
  v18 = StateName;
LABEL_26:
  if ( v14 != nullptr && *v14 != 0 )
    v19 = v14;
  else
    v19 = "<no sw>";
  idStr::Format(this: waitPath, fmt: "%s/%s : %s", v19, v18, v6);
}


// ========================================================================
// ?ReportStatus@idAnimWebCmd@@IAA?AW4awCmdStatus_t@@W42@@Z
// EA  : 0x82A83B70
// RVA : 0x00A83B70
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

int __fastcall idAnimWebCmd::ReportStatus(idAnimWebCmd *this, int status)
{
  unsigned int v4; // r30
  const char *userString; // r11
  const char *v6; // r30
  const char *v7; // r29
  idStr *AnimName; // r3
  idStr *v9; // r3
  const char *SubWebName; // r3
  idAnimWebCmdWaitHandle *activeWaitHandle; // r22
  const char *v12; // r30
  idStr *v13; // r3
  idStr *v14; // r3
  unsigned int groups; // r4
  idAnimWebCmdWaitHandle *v16; // r11
  unsigned int groupFilter; // r4
  const char *v18; // r6
  const enumValueInfo_t *EnumValueInfo; // r3
  const char *name; // r4
  idStr v22; // [sp+60h] [-120h] BYREF
  idStr v23; // [sp+80h] [-100h] BYREF
  idStr v24; // [sp+A0h] [-E0h] BYREF
  idStr v25; // [sp+C0h] [-C0h] BYREF
  idStr v26; // [sp+E0h] [-A0h] BYREF
  idAnimWebState v27[6]; // [sp+100h] [-80h] BYREF

  LOBYTE(v4) = 0;
  if ( (unsigned int)(status + 1) <= 6 )
  {
    if ( status != 0 )
    {
      if ( status == 1 || status == 2 || status == 3 )
        LOBYTE(v4) = (this->flags & 0x400) != 0;
      else
        LOBYTE(v4) = (this->flags & 0x200) != 0;
    }
    else
    {
      v4 = (-awcmd_debugLevel.valueInteger & (unsigned int)~awcmd_debugLevel.valueInteger) >> 31;
    }
  }
  if ( (unsigned __int8)ShowDebug(ent: this->owner->entity) != 0 || (_BYTE)v4 != 0 )
  {
    userString = this->userString;
    if ( userString == nullptr )
      userString = "unknown";
    idLib::Printf(fmt: "[%s] : command : '%s'\n", this->owner->entity->name.data, userString);
    if ( (this->flags & 8) != 0 )
      idLib::Printf(fmt: ".  force\n");
    v6 = "INVALID ";
    if ( (this->flags & 2) != 0 )
    {
      v7 = "INVALID ";
      if ( status != 6 )
        v7 = &byte_8200D768;
      AnimName = idAnimWebState::GetAnimName(this: (idAnimWebState *)&v24, result: (idStr *)&this->dst);
      idLib::Printf(fmt: ".  %schangeState : '%s'\n", v7, AnimName->data);
      idStr::FreeData(this: &v24);
    }
    if ( (this->flags & 4) != 0 )
    {
      if ( status != 7 )
        v6 = &byte_8200D768;
      v9 = idAnimWebState::GetAnimName(this: (idAnimWebState *)&v25, result: (idStr *)&this->via);
      idLib::Printf(fmt: ".  %svia : '%s'\n", v6, v9->data);
      idStr::FreeData(this: &v25);
    }
    if ( (this->flags & 0x20) != 0 )
    {
      SubWebName = idDeclAnimWeb::GetSubWebName(
                     this: this->owner->animWeb->decl,
                     index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->viaWeb.value);
      idLib::Printf(fmt: ".  via subweb : '%s'\n", SubWebName);
    }
    activeWaitHandle = this->owner->activeWaitHandle;
    if ( activeWaitHandle == nullptr || (v12 = activeWaitHandle->userString) == nullptr )
      v12 = &byte_8200D768;
    v13 = (idStr *)idAnimWebState::idAnimWebState(
                     this: v27,
                     decl: this->owner->animWeb->decl,
                     _node: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)this->owner->animWeb->curNodeIndex.value);
    v14 = idAnimWebState::GetAnimName(this: (idAnimWebState *)&v26, result: v13);
    idLib::Printf(fmt: ".  current anim : '%s' : '%s'\n", v14->data, v12);
    idStr::FreeData(this: &v26);
    if ( status == 1 )
    {
      v22.len = 0;
      v22.baseBuffer[0] = 0;
      v22.allocedAndFlag = 20;
      v22.data = v22.baseBuffer;
      v23.allocedAndFlag = 20;
      v23.data = v23.baseBuffer;
      v23.len = 0;
      v23.baseBuffer[0] = 0;
      groups = this->groups;
      if ( groups != 0 )
      {
        if ( groups == -1 )
        {
          idStr::operator=(this: &v22, text: "ALL");
        }
        else
        {
          idTypeInfoTools::GetEnumBitFlags(
            this: typeInfoTools,
            flags: groups,
            enumType: "awAIGroupFilter_t",
            flagNames: &v22,
            delimiter: " ");
          idStr::Replace(this: &v22, old: "AWCMD_GROUP_", nw: &byte_8200D768);
        }
      }
      else
      {
        idStr::operator=(this: &v22, text: "NONE");
      }
      v16 = this->owner->activeWaitHandle;
      if ( v16 != nullptr && v16->status == AWCMD_STATUS_WAITING )
        groupFilter = v16->groupFilter;
      else
        groupFilter = this->owner->groupFilter;
      if ( groupFilter != 0 )
      {
        if ( groupFilter == -1 )
        {
          idStr::operator=(this: &v23, text: "ALL");
        }
        else
        {
          idTypeInfoTools::GetEnumBitFlags(
            this: typeInfoTools,
            flags: groupFilter,
            enumType: "awAIGroupFilter_t",
            flagNames: &v23,
            delimiter: " ");
          idStr::Replace(this: &v23, old: "AWCMD_GROUP_", nw: &byte_8200D768);
        }
      }
      else
      {
        idStr::operator=(this: &v23, text: "NONE");
      }
      if ( activeWaitHandle != nullptr )
        v18 = activeWaitHandle->userString;
      else
        v18 = &byte_8200D768;
      idLib::Printf(fmt: ".  groups '%s', ignored by group filter '%s' (%s)\n", v22.data, v23.data, v18);
      idStr::FreeData(this: &v23);
      idStr::FreeData(this: &v22);
    }
    EnumValueInfo = idTypeInfoTools::FindEnumValueInfo(
                      this: typeInfoTools,
                      enumName: "awCmdStatus_t",
                      value: status,
                      defaultIfNotFound: false);
    if ( EnumValueInfo != nullptr )
      name = EnumValueInfo->name;
    else
      name = "unknown";
    idLib::Printf(fmt: ".  status : '%s'\n", name);
  }
  return status;
}


// ========================================================================
// __unwind$489595
// EA  : 0x82A83F44
// RVA : 0x00A83F44
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void _unwind_489595()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 160));
}


// ========================================================================
// __unwind$489596
// EA  : 0x82A83F6C
// RVA : 0x00A83F6C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void _unwind_489596()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 192));
}


// ========================================================================
// __unwind$489597
// EA  : 0x82A83F94
// RVA : 0x00A83F94
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void _unwind_489597()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 224));
}


// ========================================================================
// __unwind$489598
// EA  : 0x82A83FBC
// RVA : 0x00A83FBC
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void _unwind_489598()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 96));
}


// ========================================================================
// __unwind$489599
// EA  : 0x82A83FE4
// RVA : 0x00A83FE4
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void _unwind_489599()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 128));
}


// ========================================================================
// ?ReleaseWaitHandleForAnim@idAnimWebCmdCtx@@QAA_NPBVidMD6Anim@@@Z
// EA  : 0x82A84088
// RVA : 0x00A84088
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

int __fastcall idAnimWebCmdCtx::ReleaseWaitHandleForAnim(idAnimWebCmdCtx *this, const idMD6Anim *anim)
{
  idAnimWebCmdWaitHandle *activeWaitHandle; // r3
  int v5; // r24
  const idDeclAnimWeb *decl; // r25
  bool v7; // r3
  idAnimWebCmdWaitHandle *v8; // r11
  int v9; // r11
  int v10; // r11
  idDeclAnimWebNode *v11; // r3
  const idDeclAnimWebNode::idModelInfo *ModelInfo; // r3
  const idDeclAnimWebNode::idModelInfo *v13; // r27
  int num; // r11
  int v15; // r29
  int i; // r28
  idMD6AnimProps *v17; // r30
  const idDeclMD6 *BaseModel; // r3
  idStr v20; // [sp+60h] [-90h] BYREF
  idStr v21[3]; // [sp+80h] [-70h] BYREF

  activeWaitHandle = this->activeWaitHandle;
  v5 = 0;
  if ( activeWaitHandle != nullptr )
  {
    if ( anim == nullptr )
    {
_M489979_0:
      idAnimWebCmdWaitHandle::FireDoneEvent(this: activeWaitHandle, ent: this->entity);
      v5 = 1;
      this->activeWaitHandle->status = AWCMD_STATUS_DONE;
      return v5;
    }
    decl = this->animWeb->decl;
    if ( decl != nullptr )
    {
      v7 = idAnimWebState::Verify(this: &activeWaitHandle->via, errorMsg: nullptr);
      v8 = this->activeWaitHandle;
      v9 = (int)(v7 ? &v8->via : &v8->dst);
      v10 = *(__int16 *)(v9 + 8);
      if ( v10 >= 0 )
      {
        v11 = decl->nodes.list[v10];
        if ( v11 != nullptr )
        {
          ModelInfo = idDeclAnimWebNode::FindModelInfo(this: v11, modelIndex: nullptr);
          v13 = ModelInfo;
          if ( ModelInfo != nullptr )
          {
            v15 = 0;
            num = ModelInfo->animProps.num;
            if ( num > 0 )
            {
              for ( i = 0; ; ++i )
              {
                v17 = v15 < 0 || v15 >= num ? nullptr : &v13->animProps.list[i];
                BaseModel = idDeclAnimWeb::GetBaseModel(this: decl);
                if ( idMD6AnimProps::SelectAnim(this: v17, declMD6: BaseModel, index: 0) == anim )
                  break;
                num = v13->animProps.num;
                if ( ++v15 >= num )
                  return v5;
              }
              if ( awcmd_debug.valueInteger > 0 )
              {
                v21[0].len = 0;
                v21[0].baseBuffer[0] = 0;
                v21[0].allocedAndFlag = 20;
                v21[0].data = v21[0].baseBuffer;
                v20.allocedAndFlag = 20;
                v20.data = v20.baseBuffer;
                v20.len = 0;
                v20.baseBuffer[0] = 0;
                idAnimWebCmdWaitHandle::GetDebugString(this: this->activeWaitHandle, info: v21, waitPath: &v20);
                idLib::Printf(
                  fmt: "[%s] : ReleaseWaitHandleForAnim : '%s' / '%s'\n",
                  this->entity->name.data,
                  v20.data,
                  v21[0].data);
                idStr::FreeData(this: &v20);
                idStr::FreeData(this: v21);
              }
              activeWaitHandle = this->activeWaitHandle;
              goto _M489979_0;
            }
          }
        }
      }
    }
  }
  return v5;
}


// ========================================================================
// __unwind$489820
// EA  : 0x82A84248
// RVA : 0x00A84248
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void _unwind_489820()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$489821
// EA  : 0x82A84270
// RVA : 0x00A84270
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void _unwind_489821()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// ??1idAnimWebCmdWaitHandle@@QAA@XZ
// EA  : 0x82A84298
// RVA : 0x00A84298
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void __fastcall idAnimWebCmdWaitHandle::~idAnimWebCmdWaitHandle(idAnimWebCmdWaitHandle *this)
{
  idAnimWebCmdCtx *Context; // r3

  Context = (idAnimWebCmdCtx *)idAnimWebCmdWaitHandle::GetContext(this);
  if ( Context != nullptr && Context->activeWaitHandle == this )
    idAnimWebCmdCtx::SetActiveWaitHandle(this: Context, handle: nullptr);
}


// ========================================================================
// ?UpdateStatus@idAnimWebCmdWaitHandle@@IAA?AW4awCmdStatus_t@@XZ
// EA  : 0x82A842E0
// RVA : 0x00A842E0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

int __fastcall idAnimWebCmdWaitHandle::UpdateStatus(idAnimWebCmdWaitHandle *this)
{
  idAnimWebCmdWaitHandle *v2; // r3
  bool v3; // zf
  int v4; // r4
  const idAnimWebCmdCtx *Context; // r3
  animWebEvent_t eventType; // r4
  idAnimator_AnimWeb *animWeb; // r3

  v3 = (unsigned __int8)idAnimWebCmdWaitHandle::Verify(this) != 0;
  v2 = this;
  if ( v3 )
  {
    Context = idAnimWebCmdWaitHandle::GetContext(this);
    eventType = this->animEventInfo.eventType;
    animWeb = Context->animWeb;
    if ( eventType != ANIMWEB_EVENT_MAX && idAnimator_AnimWeb::IsEventPending(this: animWeb, type: eventType) )
      return 8;
    this->finishTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v4 = 11;
    v2 = this;
  }
  else
  {
    v4 = 4;
  }
  return idAnimWebCmdWaitHandle::ReportStatus(this: v2, status: v4);
}


// ========================================================================
// ?Commit@idAnimWebCmd@@QAA?AW4awCmdStatus_t@@AAVidAnimWebCmdWaitHandle@@W4awCmdPriority_t@@W4awCmdBlendEvent_t@@@Z
// EA  : 0x82A84398
// RVA : 0x00A84398
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

int __fastcall idAnimWebCmd::Commit(
        idAnimWebCmd *this,
        idAnimWebCmdWaitHandle *handle,
        awCmdPriority_t priority,
        unsigned int ev)
{
  int flags; // r11
  idAnimator_AnimWeb *animWeb; // r23
  int v10; // r4
  idAnimWebCmdCtx *owner; // r28
  idAnimWebCmdWaitHandle *activeWaitHandle; // r11
  bool v13; // r11
  idAnimWebCmdWaitHandle *v14; // r11
  bool v15; // r11
  const char *userString; // r11
  idAnimWebState_Current *v17; // r3
  idAtomicString *p_debugState; // r10
  idAtomicString *v19; // r11
  int i; // ctr
  int v21; // r8
  idAnimWebCmdWaitHandle *v22; // r11
  bool v24; // r28
  char *v25; // r11
  int k; // ctr
  const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *v27; // r5
  int v28; // r6
  int forceFallbackPathSize; // r11
  int v30; // r11
  int v31; // r10
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *value; // r5
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v33; // r4
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v34; // r7
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v35; // r6
  awPathResult_t v36; // r3
  awPathResult_t v37; // r3
  int v38; // r11
  int v39; // r3
  int v40; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v41; // r5
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v42; // r4
  int v43; // r11
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v44; // r7
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v45; // r6
  awPathResult_t pathResult; // r11
  BOOL v47; // r7
  idAnimWebCmdWaitHandle::idAnimEventInfo_t *p_animEventInfoDC; // r28
  bool v49; // r7
  char v50; // r5
  idEntity *entity; // r10
  int *p_flags; // r9
  unsigned int *p_groupFilter; // r10
  int v54; // ctr
  idAtomicString *v55; // r9
  idAtomicString *v56; // r10
  int j; // ctr
  const char *v58; // r10
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v59; // r6
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v60; // r5
  animWebEvent_t v61; // r10
  animWebEvent_t v62; // r4
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v63; // r6
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v64; // r5
  idAnimWebPath *AnimPath; // r3
  idAnimWebState *v66; // r3
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v67; // r6
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v68; // r5
  idAnimWebPath *v69; // r3
  int v71; // [sp+8h] [-1B8h]
  int v72; // [sp+Ch] [-1B4h]
  int v73; // [sp+10h] [-1B0h]
  int v74; // [sp+14h] [-1ACh]
  int v75; // [sp+18h] [-1A8h]
  int v76; // [sp+1Ch] [-1A4h]
  int v77; // [sp+20h] [-1A0h]
  idIndex<short,enum invalidUserChannelIndex_t> *v78; // [sp+24h] [-19Ch]
  int v79; // [sp+28h] [-198h]
  int v80; // [sp+2Ch] [-194h]
  int v81; // [sp+30h] [-190h]
  int v82; // [sp+34h] [-18Ch]
  int v83; // [sp+38h] [-188h]
  int v84; // [sp+3Ch] [-184h]
  int v85; // [sp+40h] [-180h]
  int v86; // [sp+44h] [-17Ch]
  int v87; // [sp+48h] [-178h]
  int v88; // [sp+4Ch] [-174h]
  int v89; // [sp+50h] [-170h]
  idStr v90; // [sp+70h] [-150h] BYREF
  idStr v91; // [sp+90h] [-130h] BYREF
  idAnimWebRoute v92; // [sp+B0h] [-110h] BYREF
  idAnimWebState v93; // [sp+100h] [-C0h] BYREF
  idAnimWebState v94; // [sp+120h] [-A0h] BYREF
  idAnimWebState_Current v95[6]; // [sp+140h] [-80h] BYREF

  flags = this->flags;
  animWeb = this->owner->animWeb;
  if ( (flags & 6) == 0 )
    goto LABEL_121;
  if ( (flags & 2) != 0 )
  {
    if ( this->dst.pathConstructed )
      idLib::Warning(fmt: "Dest created with path, may not match user");
    idAnimWebState::VerifyDecl(this: &this->dst, decl: this->owner->animWeb->decl);
    if ( !idAnimWebState::Verify(this: &this->dst, errorMsg: "Invalid dest Anim") )
    {
      v10 = 6;
      return idAnimWebCmd::ReportStatus(this, status: v10);
    }
  }
  if ( (this->flags & 4) != 0 )
  {
    if ( this->via.pathConstructed )
      idLib::Warning(fmt: "Via created with path, may not match user");
    idAnimWebState::VerifyDecl(this: &this->via, decl: this->owner->animWeb->decl);
    if ( !idAnimWebState::Verify(this: &this->via, errorMsg: "Invalid via Anim") )
    {
      v10 = 7;
      return idAnimWebCmd::ReportStatus(this, status: v10);
    }
  }
  owner = this->owner;
  activeWaitHandle = this->owner->activeWaitHandle;
  if ( activeWaitHandle != nullptr && activeWaitHandle->status == AWCMD_STATUS_WAITING )
  {
    if ( activeWaitHandle->lockMask != 0 || (v13 = false, owner->lockedFlags != 0) )
      v13 = true;
  }
  else
  {
    v13 = owner->lockedFlags != 0;
  }
  if ( v13 )
  {
    v10 = 3;
    return idAnimWebCmd::ReportStatus(this, status: v10);
  }
  if ( (unsigned __int8)idAnimWebCmdCtx::IsGroupAllowed(this: owner, _groupBits: this->groups) == 0 )
  {
    v10 = 1;
    return idAnimWebCmd::ReportStatus(this, status: v10);
  }
  if ( !idAnimWebCmdCtx::CheckPriority(this: owner, _priority: priority) )
  {
    v10 = 2;
    return idAnimWebCmd::ReportStatus(this, status: v10);
  }
  v14 = owner->activeWaitHandle;
  v15 = v14 != nullptr && (_cntlzw(v14->status - 8) & 0x20) != 0;
  if ( v15 && awcmd_debug.valueInteger == owner->entity->entityNumber )
  {
    v90.len = 0;
    v90.baseBuffer[0] = 0;
    v90.allocedAndFlag = 20;
    v90.data = v90.baseBuffer;
    v91.allocedAndFlag = 20;
    v91.data = v91.baseBuffer;
    v91.len = 0;
    v91.baseBuffer[0] = 0;
    idTypeInfoTools::GetEnumBitFlags(
      this: typeInfoTools,
      flags: owner->activeWaitHandle->groups,
      enumType: "awAIGroupFilter_t",
      flagNames: &v90,
      delimiter: " ");
    idTypeInfoTools::GetEnumBitFlags(
      this: typeInfoTools,
      flags: this->groups,
      enumType: "awAIGroupFilter_t",
      flagNames: &v91,
      delimiter: " ");
    userString = this->userString;
    if ( userString == nullptr )
      userString = "unknown";
    idLib::Printf(
      fmt: "[%s] : command : '%s' group '%s' INTERRUPTING group '%s'\n",
      this->owner->entity->name.data,
      userString,
      v90.data,
      v91.data);
    idStr::FreeData(this: &v91);
    idStr::FreeData(this: &v90);
  }
  if ( (this->flags & 2) == 0 )
  {
    v17 = idAnimWebState_Current::idAnimWebState_Current(this: v95, web: animWeb);
    p_debugState = &this->via.debugState;
    v19 = &v17[-1].debugState;
    for ( i = 5; i != 0; --i )
    {
      ++v19;
      ++p_debugState;
      p_debugState->str = v19->str;
    }
  }
  v21 = this->flags;
  if ( (v21 & 0x80) == 0 && this->intrPath == INTR_PATH_IMMEDIATE )
  {
    v22 = this->owner->activeWaitHandle;
    if ( v22 != nullptr && (*((_BYTE *)v22 + 149) & 0x40) == 0 )
      this->intrPath = INTR_PATH_YES;
  }
  v24 = (v21 & 8) != 0;
  if ( (v21 & 8) == 0 || (v21 & 0x40) == 0 )
  {
LABEL_57:
    v30 = this->flags;
    v31 = v30 & 4;
    if ( v24 )
    {
      if ( (v30 & 4) != 0 )
      {
        value = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->via.state.value;
        v33 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->via.subweb.value;
        v34 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->dst.state.value;
        v35 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->dst.subweb.value;
        if ( (v30 & 0x20) != 0 )
          v36 = idAnimator_AnimWeb::ForceAndChangeState(
                  this: animWeb,
                  subWebIndex: v33,
                  stateIndex: value,
                  subWebIndex2: v35,
                  stateIndex2: v34,
                  otherSubWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->viaWeb.value,
                  blendParms: &this->blendParms,
                  blendEventMask_: this->blendEventMask);
        else
          v36 = idAnimator_AnimWeb::ForceAndChangeState(
                  this: animWeb,
                  subWebIndex: v33,
                  stateIndex: value,
                  subWebIndex2: v35,
                  stateIndex2: v34,
                  blendParms: &this->blendParms,
                  blendEventMask_: this->blendEventMask);
      }
      else
      {
        v37 = idAnimator_AnimWeb::ForceState(
                this: animWeb,
                subWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->dst.subweb.value,
                stateIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->dst.state.value,
                blendParms: &this->blendParms,
                blendEventMask_: this->blendEventMask);
        this->pathResult = v37;
        if ( v37 != AWPATH_ALREADY_THERE )
          goto LABEL_75;
        v38 = this->flags;
        if ( (v38 & 0x100) != 0 )
        {
          v39 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          idAnimator_AnimWeb::SetCurNode(
            this: animWeb,
            subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->dst.subweb.value,
            stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->dst.state.value,
            curTime: v39);
          this->pathResult = AWPATH_OK;
          goto LABEL_75;
        }
        if ( (v38 & 0x800) == 0 )
        {
LABEL_75:
          pathResult = this->pathResult;
          if ( pathResult == AWPATH_FAILED )
          {
            v10 = 5;
            return idAnimWebCmd::ReportStatus(this, status: v10);
          }
          v47 = (_cntlzw(pathResult - 2) & 0x20) != 0;
          this->alreadyThere = v47;
          handle->owner.spawnId.value = 0x1FFF;
          handle->userString = nullptr;
          handle->animEventInfo.subWebIndex.value = -1;
          handle->animEventInfo.stateIndex.value = -1;
          p_animEventInfoDC = &handle->animEventInfoDC;
          handle->animEventInfo.eventType = ANIMWEB_EVENT_MAX;
          v49 = !v47;
          handle->animEventInfoDC.subWebIndex.value = -1;
          handle->animEventInfoDC.stateIndex.value = -1;
          handle->animEventInfoDC.eventType = ANIMWEB_EVENT_MAX;
          v50 = *((_BYTE *)handle + 149) & 0x3F | 0x40;
          handle->doneEvent = nullptr;
          handle->groups = -1;
          handle->groupFilter = -1;
          handle->priority = AWCMD_PRIORITY_LOW;
          handle->lockMask = 0;
          handle->finishTime = 0;
          handle->flags = 0;
          *((_BYTE *)handle + 149) = v50;
          handle->animEventInfo.subWebIndex.value = -1;
          handle->animEventInfo.stateIndex.value = -1;
          handle->animEventInfo.eventType = ANIMWEB_EVENT_MAX;
          handle->status = AWCMD_STATUS_DONE;
          entity = this->owner->entity;
          if ( entity != nullptr )
            handle->owner.spawnId.value = (gameLocal->spawnIds.ptr[entity->entityNumber] << 13) | entity->entityNumber;
          else
            handle->owner.spawnId.value = 0x1FFF;
          p_flags = &handle->flags;
          p_groupFilter = &this->groupFilter;
          handle->userString = this->userString;
          v54 = 5;
          handle->doneEvent = this->doneEvent;
          handle->groups = this->groups;
          handle->groupFilter = this->groupFilter;
          handle->priority = priority;
          handle->lockMask = this->lockMask;
          do
          {
            *++p_flags = *++p_groupFilter;
            --v54;
          }
          while ( v54 != 0 );
          v55 = &handle->via.debugState;
          v56 = &this->via.debugState;
          for ( j = 5; j != 0; --j )
          {
            ++v56;
            ++v55;
            v55->str = v56->str;
          }
          v58 = handle->userString;
          for ( handle->flags = this->flags; v58 != nullptr; ++v58 )
          {
            if ( *v58 == 0 )
              break;
            if ( *v58 == 92 )
              handle->userString = v58 + 1;
          }
          if ( !v49 || (handle->status = AWCMD_STATUS_WAITING, ev > 8) )
          {
LABEL_111:
            if ( (this->flags & 0x10) != 0 )
            {
              awCmdDeltaCorrect_t::operator=(this: &handle->deltaCorrectParms, __that: &this->deltaCorrectParms);
              if ( (this->flags & 4) != 0 )
              {
                if ( idAnimWebState::GetAnimWrapMode(this: &this->via) == WRAP_CLAMP )
                {
                  v63 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->via.state.value;
                  v64 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->via.subweb.value;
                  handle->animEventInfoDC.eventType = ANIMWEB_EVENT_START_BLEND_IN;
                  handle->animEventInfoDC.stateIndex.value = (__int16)v63;
                  p_animEventInfoDC->subWebIndex.value = (__int16)v64;
                  idAnimator_AnimWeb::SetEvent(
                    this: animWeb,
                    eventType: ANIMWEB_EVENT_START_BLEND_IN,
                    subWebIndex: v64,
                    stateIndex: v63,
                    eventDef: &EV_AnimWeb_StartDeltaCorrection,
                    priority: PRIORITY_LOW);
                  goto LABEL_120;
                }
                AnimPath = idAnimWebState::GetAnimPath(this: &v93, result: (idAnimWebPath *)&this->via);
                idLib::Warning(fmt: "Delta correction unsupported in 'WRAP_REPEAT' in via '%s'", AnimPath->data);
                v66 = &v93;
              }
              else
              {
                if ( idAnimWebState::GetAnimWrapMode(this: &this->dst) == WRAP_CLAMP )
                {
                  v67 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->dst.state.value;
                  v68 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->dst.subweb.value;
                  handle->animEventInfoDC.eventType = ANIMWEB_EVENT_START_BLEND_IN;
                  handle->animEventInfoDC.stateIndex.value = (__int16)v67;
                  p_animEventInfoDC->subWebIndex.value = (__int16)v68;
                  idAnimator_AnimWeb::SetEvent(
                    this: animWeb,
                    eventType: ANIMWEB_EVENT_START_BLEND_IN,
                    subWebIndex: v68,
                    stateIndex: v67,
                    eventDef: &EV_AnimWeb_StartDeltaCorrection,
                    priority: PRIORITY_LOW);
                  goto LABEL_120;
                }
                v69 = idAnimWebState::GetAnimPath(this: &v94, result: (idAnimWebPath *)&this->dst);
                idLib::Warning(fmt: "Delta correction unsupported in 'WRAP_REPEAT' in via '%s'", v69->data);
                v66 = &v94;
              }
              idStr::FreeData(this: (idStr *)v66);
            }
LABEL_120:
            idAnimWebCmdCtx::SetActiveWaitHandle(this: this->owner, handle);
LABEL_121:
            v10 = 0;
            return idAnimWebCmd::ReportStatus(this, status: v10);
          }
          switch ( ev )
          {
            case 0u:
              handle->animEventInfo.eventType = ANIMWEB_EVENT_NONE;
              handle->status = AWCMD_STATUS_DONE;
              goto LABEL_111;
            case 1u:
              v59 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->dst.state.value;
              v61 = ANIMWEB_EVENT_DEST_START_BLEND_IN;
              v60 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->dst.subweb.value;
              v62 = ANIMWEB_EVENT_DEST_START_BLEND_IN;
              break;
            case 2u:
              v59 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->dst.state.value;
              v61 = ANIMWEB_EVENT_DEST_END_BLEND_IN;
              v60 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->dst.subweb.value;
              v62 = ANIMWEB_EVENT_DEST_END_BLEND_IN;
              break;
            case 3u:
              v59 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->dst.state.value;
              v61 = ANIMWEB_EVENT_DEST_CLAMPED;
              v60 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->dst.subweb.value;
              v62 = ANIMWEB_EVENT_DEST_CLAMPED;
              break;
            default:
              switch ( ev )
              {
                case 4u:
                  v59 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->dst.state.value;
                  v60 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->dst.subweb.value;
                  v62 = ANIMWEB_EVENT_NONE;
                  handle->animEventInfo.eventType = ANIMWEB_EVENT_NONE;
                  break;
                case 5u:
                  v59 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->via.state.value;
                  v60 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->via.subweb.value;
                  v62 = ANIMWEB_EVENT_START_BLEND_IN;
                  handle->animEventInfo.eventType = ANIMWEB_EVENT_START_BLEND_IN;
                  break;
                case 6u:
                  v61 = ANIMWEB_EVENT_END_BLEND_IN;
                  v62 = ANIMWEB_EVENT_END_BLEND_IN;
                  goto LABEL_108;
                case 7u:
                  v59 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->via.state.value;
                  v60 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->via.subweb.value;
                  v62 = ANIMWEB_EVENT_START_BLEND_OUT;
                  handle->animEventInfo.eventType = ANIMWEB_EVENT_START_BLEND_OUT;
                  break;
                default:
                  v61 = ANIMWEB_EVENT_END_BLEND_OUT;
                  v62 = ANIMWEB_EVENT_END_BLEND_OUT;
LABEL_108:
                  v60 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->via.subweb.value;
                  v59 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->via.state.value;
                  goto LABEL_109;
              }
LABEL_110:
              handle->animEventInfo.stateIndex.value = (__int16)v59;
              handle->animEventInfo.subWebIndex.value = (__int16)v60;
              idAnimator_AnimWeb::SetEvent(
                this: animWeb,
                eventType: v62,
                subWebIndex: v60,
                stateIndex: v59,
                eventDef: &EV_AnimWeb_Wait,
                priority: PRIORITY_LOW);
              goto LABEL_111;
          }
LABEL_109:
          handle->animEventInfo.eventType = v61;
          goto LABEL_110;
        }
        v40 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        idAnimator_AnimWeb::SetCurNode(
          this: animWeb,
          subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->via.subweb.value,
          stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->via.state.value,
          curTime: v40);
        v36 = idAnimator_AnimWeb::ForceState(
                this: animWeb,
                subWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->dst.subweb.value,
                stateIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->dst.state.value,
                blendParms: &this->blendParms,
                blendEventMask_: this->blendEventMask);
      }
    }
    else
    {
      v41 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->dst.state.value;
      v42 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->dst.subweb.value;
      v43 = v30 & 0x20;
      if ( v31 != 0 )
      {
        v44 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)this->via.state.value;
        v45 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->via.subweb.value;
        if ( v43 != 0 )
          v36 = idAnimator_AnimWeb::ChangeStateVia(
                  this: animWeb,
                  subWebIndex_: v42,
                  stateIndex_: v41,
                  _viaSubWebIndex: v45,
                  _viaStateIndex: v44,
                  _otherSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->viaWeb.value,
                  interruptPath_: this->intrPath,
                  interruptBlend_: this->intrBlend,
                  blendEventMask_: v71,
                  a10: v72,
                  a11: v73,
                  a12: v74,
                  a13: v75,
                  a14: v76,
                  a15: v77,
                  a16: (int)v78,
                  a17: v79,
                  a18: v80,
                  a19: v81,
                  a20: v82,
                  a21: v83,
                  a22: v84,
                  a23: v85,
                  a24: v86,
                  a25: v87,
                  a26: v88,
                  a27: v89,
                  a28: this->blendEventMask);
        else
          v36 = idAnimator_AnimWeb::ChangeStateVia(
                  this: animWeb,
                  subWebIndex_: v42,
                  stateIndex_: v41,
                  _viaSubWebIndex: v45,
                  _viaStateIndex: v44,
                  interruptPath_: this->intrPath,
                  interruptBlend_: this->intrBlend,
                  blendEventMask_: this->blendEventMask);
      }
      else if ( v43 != 0 )
      {
        v36 = idAnimator_AnimWeb::ChangeState(
                this: animWeb,
                subWebIndex: v42,
                stateIndex: v41,
                otherSubWebIndex_: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)this->viaWeb.value,
                interruptPath_: this->intrPath,
                interruptBlend_: this->intrBlend,
                blendEventMask_: this->blendEventMask);
      }
      else
      {
        v36 = idAnimator_AnimWeb::ChangeState(
                this: animWeb,
                subWebIndex: v42,
                stateIndex: v41,
                interruptPath_: this->intrPath,
                interruptBlend_: this->intrBlend,
                blendEventMask_: this->blendEventMask);
      }
    }
    this->pathResult = v36;
    goto LABEL_75;
  }
  v25 = &v91.baseBuffer[18];
  for ( k = 32; k != 0; --k )
  {
    v25 += 2;
    *(_WORD *)v25 = -1;
  }
  v92.num = 0;
  v92.cost = 0x7FFFFFFF;
  if ( (v21 & 4) != 0 )
  {
    v27 = (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)this->via.node.value;
    if ( (v21 & 0x20) != 0 )
    {
      v28 = (unsigned __int16)this->viaWeb.value;
LABEL_53:
      idAnimator_AnimWeb::FindPath(
        this: animWeb,
        startNodeIndex: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)animWeb->curNodeIndex.value,
        destNodeIndex: v27,
        otherSubWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v28,
        path: &v92,
        a6: v21,
        a7: 0x7FFFFFFF,
        a8: v21 & 4,
        a9: v71,
        a10: v72,
        a11: v73,
        a12: v74,
        a13: v75,
        a14: v76,
        a15: v77,
        a16: v78);
      if ( v92.num != 0 )
      {
        forceFallbackPathSize = this->forceFallbackPathSize;
        if ( v92.num < forceFallbackPathSize || forceFallbackPathSize < 0 )
          v24 = false;
      }
      goto LABEL_57;
    }
  }
  else
  {
    v27 = (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)this->dst.node.value;
    if ( (v21 & 0x20) != 0 )
    {
      v28 = (unsigned __int16)this->viaWeb.value;
      goto LABEL_53;
    }
  }
  v28 = -1;
  goto LABEL_53;
}


// ========================================================================
// __unwind$490025
// EA  : 0x82A84CF8
// RVA : 0x00A84CF8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void _unwind_490025()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 112));
}


// ========================================================================
// __unwind$490026
// EA  : 0x82A84D20
// RVA : 0x00A84D20
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void _unwind_490026()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 144));
}


// ========================================================================
// __unwind$490027
// EA  : 0x82A84D48
// RVA : 0x00A84D48
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void _unwind_490027()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 256));
}


// ========================================================================
// __unwind$490028
// EA  : 0x82A84D70
// RVA : 0x00A84D70
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void _unwind_490028()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 448 + 288));
}


// ========================================================================
// ?ProcessEvent@idAnimWebCmdWaitHandle@@IAAXW4awWebEventType_t@@PAVidEntity@@V?$idHandle@FW4invalidAnimWebHandle_t@@$0?0@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82A84DA0
// RVA : 0x00A84DA0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void __fastcall idAnimWebCmdWaitHandle::ProcessEvent(
        idAnimWebCmdWaitHandle *this,
        awWebEventType_t eventType,
        idAI2 *ownerEnt,
        const idHandle<short,enum invalidAnimWebHandle_t,-1> *webHandle,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *swi,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *si)
{
  idAI2 *v10; // r25
  idAnimator_AnimWeb *animWeb; // r26
  idDeclAnimWebNode *v12; // r11
  idDeclAnimWebNode::idModelInfo *list; // r9
  const idMD6Anim **p_anim; // r10
  const idMD6Anim *anim; // r30
  idStr *v16; // r3
  idStr *AnimName; // r3
  awCmdStatus_t updated; // r3
  unsigned __int16 v19; // [sp+50h] [-90h] BYREF
  int num; // [sp+54h] [-8Ch]
  idAnimWebState v21; // [sp+60h] [-80h] BYREF
  idStr v22[3]; // [sp+80h] [-60h] BYREF

  if ( eventType != AWEVT_WAIT )
  {
    if ( eventType == AWEVT_DELTACORRECT )
    {
      v10 = idAI2::CastTo(c: ownerEnt);
      if ( v10 != nullptr )
      {
        animWeb = idAnimWebCmdWaitHandle::GetContext(this)->animWeb;
        idDeclAnimWeb::FindNodeIndex(
          this: (idDeclAnimWeb *)&v19,
          result: (idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)animWeb->decl,
          subWebIndex: swi,
          stateIndex: si);
        if ( (__int16)v19 != -1 )
        {
          v12 = animWeb->decl->nodes.list[(__int16)v19];
          if ( v12 != nullptr )
          {
            if ( v12->modelInfo.num <= 0 )
              list = nullptr;
            else
              list = v12->modelInfo.list;
            p_anim = nullptr;
            num = list->animProps.num;
            if ( num > 0 )
              p_anim = &list->animProps.list->anim;
            anim = *p_anim;
            if ( num <= 0
              || (anim = idAnimWebAI::GetLeafForAnimProps(
                           this: v10->aiVolatile.animation.animWebAnimator.ptr,
                           props: (const idList<idMD6AnimProps,5> *)&list->animProps)->anim) != nullptr )
            {
              animDeltaCorrection_t::input_t::operator=(
                this: &v10->aiVolatile.animation.animFSM.animDeltaCorrection.in,
                __that: &this->deltaCorrectParms.parms);
              idAI2::HandleAnimDeltaCorrection(
                this: v10,
                anim,
                idealPoint: this->deltaCorrectParms.correctIdealPoint,
                idealDir: this->deltaCorrectParms.correctIdealDir,
                correctGravity: this->deltaCorrectParms.correctGravity,
                thisEventNumber: 0);
            }
            else
            {
              v16 = (idStr *)idAnimWebState::idAnimWebState(
                               this: &v21,
                               decl: animWeb->decl,
                               _node: (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)v19);
              AnimName = idAnimWebState::GetAnimName(this: (idAnimWebState *)v22, result: v16);
              idLib::Warning(fmt: "AWEVT_DELTACORRECT: Can't get active anim '%s'", AnimName->data);
              idStr::FreeData(this: v22);
            }
          }
        }
      }
    }
  }
  else
  {
    updated = idAnimWebCmdWaitHandle::UpdateStatus(this);
    this->status = updated;
    if ( updated == AWCMD_STATUS_DONE )
      idAnimWebCmdWaitHandle::FireDoneEvent(this, ent: ownerEnt);
  }
}


// ========================================================================
// __unwind$490594
// EA  : 0x82A84F14
// RVA : 0x00A84F14
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void _unwind_490594()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// ?Commit@idAnimWebCmd@@QAA?AW4awCmdStatus_t@@W4awCmdPriority_t@@W4awCmdBlendEvent_t@@@Z
// EA  : 0x82A84F40
// RVA : 0x00A84F40
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

int __fastcall idAnimWebCmd::Commit(idAnimWebCmd *this, awCmdPriority_t priority, unsigned int ev)
{
  if ( this->owner != nullptr )
    return idAnimWebCmd::Commit(this, handle: &this->owner->defaultWaitHandle, priority, ev);
  else
    return 4;
}


// ========================================================================
// ?ProcessEvent@idAnimWebCmdCtx@@QAAXW4awWebEventType_t@@V?$idHandle@FW4invalidAnimWebHandle_t@@$0?0@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@@Z
// EA  : 0x82A84F68
// RVA : 0x00A84F68
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void __fastcall idAnimWebCmdCtx::ProcessEvent(
        idAnimWebCmdCtx *this,
        awWebEventType_t eventType,
        const idHandle<short,enum invalidAnimWebHandle_t,-1> *webHandle,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *swi,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *si)
{
  idAnimWebCmdWaitHandle *activeWaitHandle; // r3

  activeWaitHandle = this->activeWaitHandle;
  if ( activeWaitHandle != nullptr )
    idAnimWebCmdWaitHandle::ProcessEvent(
      this: activeWaitHandle,
      eventType,
      ownerEnt: (idAI2 *)this->entity,
      webHandle,
      swi,
      si);
}


// ========================================================================
// `dynamic initializer for 'awcmd_debug''
// EA  : 0x83368968
// RVA : 0x01368968
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__awcmd_debug__()
{
  idCVar::idCVar(
    this: &awcmd_debug,
    name: "awcmd_debug",
    value: "0",
    flags: 2,
    description: "debug animweb commands, 1 for all, > 1 for specific entity num",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__awcmd_debug__);
}


// ========================================================================
// `dynamic initializer for 'awcmd_debugLevel''
// EA  : 0x833689C0
// RVA : 0x013689C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__awcmd_debugLevel__()
{
  idCVar::idCVar(
    this: &awcmd_debugLevel,
    name: "awcmd_debugLevel",
    value: "0",
    flags: 2,
    description: "options:\n"
    "    0 - ok'd commands only,\n"
    "    1 - all commands & finished wait handles,\n"
    "    2 - assert on failed commands",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__awcmd_debugLevel__);
}


// ========================================================================
// `dynamic initializer for 'awcmd_disableDeltaCorrection''
// EA  : 0x83368A18
// RVA : 0x01368A18
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__awcmd_disableDeltaCorrection__()
{
  idCVar::idCVar(
    this: &awcmd_disableDeltaCorrection,
    name: "awcmd_disableDeltaCorrection",
    value: "0",
    flags: 1,
    description: "1 = disable all code driven delta correction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__awcmd_disableDeltaCorrection__);
}

