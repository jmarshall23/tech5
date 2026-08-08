
// ========================================================================
// ??1idBehaviorAction@@UAA@XZ
// EA  : 0x82B3A548
// RVA : 0x00B3A548
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorAction::~idBehaviorAction(idBehaviorAction *this)
{
  this->__vftable = (idBehaviorAction_vtbl *)&idBehaviorState::`vftable';
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// ?InternalProcessEvent@idBehaviorState@@MAAXPAVidBot@@HPBVidBehaviorStateEvent@@@Z
// EA  : 0x82B3A558
// RVA : 0x00B3A558
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorState::InternalProcessEvent(idAIFSMLite *this)
{
  this->InternalUpdate(this);
}


// ========================================================================
// ?CheckStateFlag@idBehaviorState@@IBA_NH@Z
// EA  : 0x82B3A568
// RVA : 0x00B3A568
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

BOOL __fastcall idBehaviorState::CheckStateFlag(idBehaviorState *this, const int flag)
{
  return (this->stateFlags & flag) != 0;
}


// ========================================================================
// ?InternalInit@idBehaviorDecorator@@MAAXPAVidBot@@H@Z
// EA  : 0x82B3A580
// RVA : 0x00B3A580
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorDecorator::InternalInit(idBehaviorDecorator *this, idBot *bot, const int curTime)
{
  idBehaviorState *child; // r9

  ((void (__fastcall *)(idBehaviorDecorator *))this->Init)(a1: this);
  child = this->child;
  if ( child != nullptr )
    ((void (*)(void))child->InternalInit)();
}


// ========================================================================
// ?GetDebugString@idBehaviorSelector@@UBAXAAVidStr@@@Z
// EA  : 0x82B3A5D8
// RVA : 0x00B3A5D8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorSelector::GetDebugString(idBehaviorSelector *this, idStr *str)
{
  idBehaviorState *currentState; // r3
  const char *Classname; // r4

  currentState = this->currentState;
  if ( currentState != nullptr )
    Classname = idClass::GetClassname(this: currentState);
  else
    Classname = &byte_8200D768;
  idStr::operator=(this: str, text: Classname);
}


// ========================================================================
// ?GetDebugString@idBehaviorSequence@@UBAXAAVidStr@@@Z
// EA  : 0x82B3A628
// RVA : 0x00B3A628
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorSequence::GetDebugString(idBehaviorSequence *this, idStr *str)
{
  idBehaviorState *currentState; // r3
  const char *Classname; // r4

  currentState = this->currentState;
  if ( currentState != nullptr )
    Classname = idClass::GetClassname(this: currentState);
  else
    Classname = &byte_8200D768;
  idStr::operator=(this: str, text: Classname);
}


// ========================================================================
// ?RootInit@idBehaviorTree@@QAAXPAVidBot@@H@Z
// EA  : 0x82B3A678
// RVA : 0x00B3A678
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorTree::RootInit(idBehaviorTree *this, idBot *bot, int curTime)
{
  this->InternalInit(this, a2: bot, a3: curTime);
}


// ========================================================================
// ??0idBehaviorState@@QAA@XZ
// EA  : 0x82B3A688
// RVA : 0x00B3A688
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

idBehaviorState *__fastcall idBehaviorState::idBehaviorState(idBehaviorState *this)
{
  idEventReceiver::idEventReceiver(this);
  this->stateStartTime = 0;
  this->__vftable = (idBehaviorState_vtbl *)&idBehaviorState::`vftable';
  this->stateFlags = 8;
  this->nextStateUseTime = 0;
  this->lastPriorityUpdateTime = 0;
  this->lastStateUpdateTime = 0;
  this->stateUpdateDelay = 0;
  this->stateUseCooldownTime = 0;
  this->stateFailedUseCooldownTime = 0;
  this->lastStateRunTime = 0;
  this->lastPriority = BEHAVIOR_PRIORITY_NULL;
  this->stateGoalType.flags = 0x80000000;
  return this;
}


// ========================================================================
// ?GetDebugString@idBehaviorState@@MBAXAAVidStr@@@Z
// EA  : 0x82B3A768
// RVA : 0x00B3A768
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorState::GetDebugString(idBehaviorState *this, idStr *str)
{
  idStr::EnsureAlloced(this: str, amount: 1, keepold: true, geometricGrowth: false);
  *str->data = 0;
  str->len = 0;
}


// ========================================================================
// ?InternalEnter@idBehaviorState@@MAAXPAVidBot@@H@Z
// EA  : 0x82B3A7B8
// RVA : 0x00B3A7B8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorState::InternalEnter(idBehaviorState *this, idBot *bot, int curTime)
{
  int stateFlags; // r8

  ((void (__fastcall *)(idBehaviorState *, idBot *))this->Enter)(a1: this, a2: bot);
  stateFlags = this->stateFlags;
  this->stateStartTime = curTime;
  this->stateFlags = stateFlags & 0xFFFFFFEE | 1;
}


// ========================================================================
// ?InternalExit@idBehaviorState@@MAAXPAVidBot@@H@Z
// EA  : 0x82B3A818
// RVA : 0x00B3A818
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorState::InternalExit(idBehaviorState *this, idBot *bot, int curTime)
{
  int stateFlags; // r9
  int stateFailedUseCooldownTime; // r10

  ((void (__fastcall *)(idBehaviorState *, idBot *))this->Exit)(a1: this, a2: bot);
  stateFlags = this->stateFlags;
  this->stateFlags = stateFlags & 0xFFFFFFFA;
  if ( (stateFlags & 0x10) != 0 )
    stateFailedUseCooldownTime = this->stateFailedUseCooldownTime;
  else
    stateFailedUseCooldownTime = this->stateUseCooldownTime;
  this->lastStateRunTime = curTime;
  this->nextStateUseTime = stateFailedUseCooldownTime + curTime;
  this->stateFlags = stateFlags & 0xFFFFFFEA;
}


// ========================================================================
// ?IsUseAble@idBehaviorState@@IBA_NPBVidBot@@@Z
// EA  : 0x82B3A898
// RVA : 0x00B3A898
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

int __fastcall idBehaviorState::IsUseAble(idBehaviorState *this, const idBot *bot)
{
  int result; // r3
  int flags; // r4
  bool v6; // zf

  if ( (this->stateFlags & 8) == 0
    || this->nextStateUseTime > idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
  {
    return 0;
  }
  flags = this->stateGoalType.flags;
  if ( flags < 0 )
    return 1;
  v6 = !idBotGoal::SupportsGoalType(this: &bot->goalTask, goal: flags);
  result = 0;
  if ( !v6 )
    return 1;
  return result;
}


// ========================================================================
// ??0idBehaviorAction@@QAA@XZ
// EA  : 0x82B3A938
// RVA : 0x00B3A938
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

idBehaviorAction *__fastcall idBehaviorAction::idBehaviorAction(idBehaviorAction *this)
{
  idBehaviorState::idBehaviorState(this);
  this->__vftable = (idBehaviorAction_vtbl *)&idBehaviorAction::`vftable';
  return this;
}


// ========================================================================
// ?FindState@idBehaviorComposite@@UAAPAVidBehaviorState@@ABVidTypeInfo@@@Z
// EA  : 0x82B3A978
// RVA : 0x00B3A978
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

idBehaviorComposite *__fastcall idBehaviorComposite::FindState(idBehaviorComposite *this, const idTypeInfo *type)
{
  int v4; // r11
  char v5; // r11
  bool v6; // zf
  idBehaviorComposite *result; // r3
  int v8; // r29
  int i; // r31

  v4 = *(_DWORD *)(this->GetType(this) + 36);
  if ( v4 < type->typeNum || (v6 = v4 <= type->lastChild, v5 = 1, !v6) )
    v5 = 0;
  if ( v5 != 0 )
    return this;
  v8 = 0;
  if ( this->children.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    result = (idBehaviorComposite *)this->children.list[i]->FindState(this: this->children.list[i], a2: type);
    if ( result != nullptr )
      break;
    if ( ++v8 >= this->children.num )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?GetStateIndex@idBehaviorComposite@@UBAHPBVidBehaviorState@@@Z
// EA  : 0x82B3AA30
// RVA : 0x00B3AA30
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

int __fastcall idBehaviorComposite::GetStateIndex(idBehaviorComposite *this, const idBehaviorState *state)
{
  int num; // r8
  int v3; // r10
  int i; // r11

  if ( state == nullptr )
    return -1;
  num = this->children.num;
  v3 = 0;
  if ( num <= 0 )
    return -1;
  for ( i = 0; this->children.list[i] != state; ++i )
  {
    if ( ++v3 >= num )
      return -1;
  }
  return v3;
}


// ========================================================================
// ?IsInterruptable@idBehaviorComposite@@UBA_NXZ
// EA  : 0x82B3AA80
// RVA : 0x00B3AA80
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

int __fastcall idBehaviorComposite::IsInterruptable(idBehaviorComposite *this)
{
  int v2; // r29
  int v3; // r31
  idBehaviorState *v4; // r3
  unsigned __int8 v5; // r11

  v2 = 0;
  if ( this->children.num <= 0 )
  {
LABEL_6:
    if ( (this->stateFlags & 2) != 0 )
      return 0;
    v5 = 1;
    if ( (this->stateFlags & 4) != 0 )
      return 0;
    return v5;
  }
  else
  {
    v3 = 0;
    while ( 1 )
    {
      v4 = this->children.list[v3];
      if ( (v4->stateFlags & 1) != 0 && !v4->IsInterruptable(this: v4) )
        return 0;
      ++v2;
      ++v3;
      if ( v2 >= this->children.num )
        goto LABEL_6;
    }
  }
}


// ========================================================================
// ?HasActiveChildren@idBehaviorComposite@@QBA_NXZ
// EA  : 0x82B3AB28
// RVA : 0x00B3AB28
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

int __fastcall idBehaviorComposite::HasActiveChildren(idBehaviorComposite *this)
{
  int num; // r9
  int result; // r3
  int v4; // r10
  idBehaviorState **list; // r8
  int i; // r11

  num = this->children.num;
  result = 0;
  v4 = 0;
  if ( num > 0 )
  {
    list = this->children.list;
    for ( i = 0; (list[i]->stateFlags & 1) == 0; ++i )
    {
      if ( ++v4 >= num )
        return result;
    }
    return 1;
  }
  return result;
}


// ========================================================================
// ?InternalInit@idBehaviorComposite@@MAAXPAVidBot@@H@Z
// EA  : 0x82B3AB78
// RVA : 0x00B3AB78
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorComposite::InternalInit(idBehaviorComposite *this, idBot *bot, int curTime)
{
  int v6; // r30
  int v7; // r29

  ((void (__fastcall *)(idBehaviorComposite *))this->Init)(a1: this);
  v6 = 0;
  if ( this->children.num > 0 )
  {
    v7 = 0;
    do
    {
      this->children.list[v7]->InternalInit(this: this->children.list[v7], a2: bot, a3: curTime);
      ++v6;
      ++v7;
    }
    while ( v6 < this->children.num );
  }
}


// ========================================================================
// ?InternalProcessEvent@idBehaviorComposite@@MAAXPAVidBot@@HPBVidBehaviorStateEvent@@@Z
// EA  : 0x82B3ABF0
// RVA : 0x00B3ABF0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorComposite::InternalProcessEvent(
        idBehaviorComposite *this,
        idBot *bot,
        int curTime,
        const idBehaviorStateEvent *eventInfo)
{
  int v8; // r30
  int v9; // r29

  ((void (__fastcall *)(idBehaviorComposite *))this->ProcessEvent)(a1: this);
  v8 = 0;
  if ( this->children.num > 0 )
  {
    v9 = 0;
    do
    {
      this->children.list[v9]->InternalProcessEvent(this: this->children.list[v9], a2: bot, a3: curTime, a4: eventInfo);
      ++v8;
      ++v9;
    }
    while ( v8 < this->children.num );
  }
}


// ========================================================================
// ?InternalExit@idBehaviorComposite@@MAAXPAVidBot@@H@Z
// EA  : 0x82B3AC70
// RVA : 0x00B3AC70
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorComposite::InternalExit(idBehaviorComposite *this, idBot *bot, int curTime)
{
  int v6; // r29
  int v7; // r30
  idBehaviorState *v8; // r3
  int stateFlags; // r9
  int stateFailedUseCooldownTime; // r10

  v6 = 0;
  if ( this->children.num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = this->children.list[v7];
      if ( (v8->stateFlags & 1) != 0 )
        v8->InternalExit(this: v8, a2: bot, a3: curTime);
      ++v6;
      ++v7;
    }
    while ( v6 < this->children.num );
  }
  if ( (this->stateFlags & 1) != 0 )
  {
    this->Exit(this, a2: bot, a3: curTime);
    stateFlags = this->stateFlags;
    this->stateFlags = stateFlags & 0xFFFFFFFA;
    if ( (stateFlags & 0x10) != 0 )
      stateFailedUseCooldownTime = this->stateFailedUseCooldownTime;
    else
      stateFailedUseCooldownTime = this->stateUseCooldownTime;
    this->lastStateRunTime = curTime;
    this->nextStateUseTime = stateFailedUseCooldownTime + curTime;
    this->stateFlags = stateFlags & 0xFFFFFFEA;
  }
}


// ========================================================================
// ??0idBehaviorDecorator@@QAA@XZ
// EA  : 0x82B3AD50
// RVA : 0x00B3AD50
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

idBehaviorDecorator *__fastcall idBehaviorDecorator::idBehaviorDecorator(idBehaviorDecorator *this)
{
  idBehaviorState::idBehaviorState(this);
  this->child = nullptr;
  this->__vftable = (idBehaviorDecorator_vtbl *)&idBehaviorDecorator::`vftable';
  return this;
}


// ========================================================================
// ?InternalProcessEvent@idBehaviorDecorator@@MAAXPAVidBot@@HPBVidBehaviorStateEvent@@@Z
// EA  : 0x82B3AD98
// RVA : 0x00B3AD98
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorDecorator::InternalProcessEvent(
        idBehaviorDecorator *this,
        idBot *bot,
        const int curTime,
        const idBehaviorStateEvent *eventInfo)
{
  idBehaviorState *child; // r9

  ((void (__fastcall *)(idBehaviorDecorator *))this->ProcessEvent)(a1: this);
  child = this->child;
  if ( child != nullptr )
    ((void (*)(void))child->InternalProcessEvent)();
}


// ========================================================================
// ?InternalExit@idBehaviorDecorator@@MAAXPAVidBot@@H@Z
// EA  : 0x82B3ADF8
// RVA : 0x00B3ADF8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorDecorator::InternalExit(idBehaviorDecorator *this, idBot *bot, int curTime)
{
  idBehaviorState *child; // r11

  child = this->child;
  if ( child != nullptr && (child->stateFlags & 1) != 0 )
    ((void (__fastcall *)(idBehaviorState *))this->child->InternalExit)(a1: this->child);
  if ( (this->stateFlags & 1) != 0 )
    idBehaviorState::InternalExit(this, bot, curTime);
}


// ========================================================================
// ?GetDebugString@idBehaviorParallel@@UBAXAAVidStr@@@Z
// EA  : 0x82B3AE68
// RVA : 0x00B3AE68
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorParallel::GetDebugString(idBehaviorParallel *this, idStr *str)
{
  int v2; // r5
  int v3; // r11
  int num; // ctr

  v2 = 0;
  if ( this->children.num > 0 )
  {
    v3 = 0;
    num = this->children.num;
    do
    {
      if ( (this->children.list[v3]->stateFlags & 1) != 0 )
        ++v2;
      ++v3;
      --num;
    }
    while ( num != 0 );
  }
  idStr::Format(this: str, fmt: "%d states active", v2);
}


// ========================================================================
// ?InternalEnter@idBehaviorSelector@@MAAXPAVidBot@@H@Z
// EA  : 0x82B3AEB8
// RVA : 0x00B3AEB8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorSelector::InternalEnter(idBehaviorSelector *this, idBot *bot, int curTime)
{
  int stateFlags; // r8
  idBehaviorState *currentState; // r3

  ((void (__fastcall *)(idBehaviorSelector *))this->Enter)(a1: this);
  stateFlags = this->stateFlags;
  this->stateStartTime = curTime;
  currentState = this->currentState;
  this->stateFlags = stateFlags & 0xFFFFFFEE | 1;
  currentState->InternalEnter(this: currentState, a2: bot, a3: curTime);
}


// ========================================================================
// ?InternalExit@idBehaviorSelector@@MAAXPAVidBot@@H@Z
// EA  : 0x82B3AF20
// RVA : 0x00B3AF20
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorSelector::InternalExit(idBehaviorSelector *this, idBot *bot, int curTime)
{
  idBehaviorState *currentState; // r3

  currentState = this->currentState;
  if ( currentState != nullptr && (currentState->stateFlags & 1) != 0 )
    ((void (__fastcall *)(idBehaviorState *))currentState->InternalExit)(a1: currentState);
  this->currentState = nullptr;
  idBehaviorComposite::InternalExit(this, bot, curTime);
}


// ========================================================================
// ?InternalEnter@idBehaviorSequence@@MAAXPAVidBot@@H@Z
// EA  : 0x82B3AF88
// RVA : 0x00B3AF88
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorSequence::InternalEnter(idBehaviorSequence *this, idBot *bot, int curTime)
{
  int stateFlags; // r8
  idBehaviorState *currentState; // r3

  ((void (__fastcall *)(idBehaviorSequence *))this->Enter)(a1: this);
  stateFlags = this->stateFlags;
  this->stateStartTime = curTime;
  currentState = this->currentState;
  this->stateFlags = stateFlags & 0xFFFFFFEE | 1;
  currentState->InternalEnter(this: currentState, a2: bot, a3: curTime);
}


// ========================================================================
// ?InternalExit@idBehaviorSequence@@MAAXPAVidBot@@H@Z
// EA  : 0x82B3AFF0
// RVA : 0x00B3AFF0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorSequence::InternalExit(idBehaviorSequence *this, idBot *bot, int curTime)
{
  idBehaviorState *currentState; // r3

  currentState = this->currentState;
  if ( currentState != nullptr && (currentState->stateFlags & 1) != 0 )
    ((void (__fastcall *)(idBehaviorState *))currentState->InternalExit)(a1: currentState);
  this->currentState = nullptr;
  idBehaviorComposite::InternalExit(this, bot, curTime);
}


// ========================================================================
// ?RootThink@idBehaviorTree@@QAAXPAVidBot@@H@Z
// EA  : 0x82B3B058
// RVA : 0x00B3B058
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorTree::RootThink(idBehaviorTree *this, idBot *bot, int curTime)
{
  int numFramesWithNoActiveChildren; // r11

  this->InternalThink(this, a2: bot, a3: curTime);
  if ( (unsigned __int8)idBehaviorComposite::HasActiveChildren(this) != 0 )
  {
    numFramesWithNoActiveChildren = 0;
  }
  else
  {
    numFramesWithNoActiveChildren = this->numFramesWithNoActiveChildren;
    this->numFramesWithNoActiveChildren = numFramesWithNoActiveChildren + 1;
  }
  this->numFramesWithNoActiveChildren = numFramesWithNoActiveChildren;
}


// ========================================================================
// ?InternalThink@idBehaviorState@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B3B0C0
// RVA : 0x00B3B0C0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

behaviorStatus_t __fastcall idBehaviorState::InternalThink(idBehaviorState *this, idBot *bot, int curTime)
{
  behaviorStatus_t result; // r3
  int stateFlags; // r11
  int v6; // r10

  if ( this->stateUpdateDelay + this->lastStateUpdateTime > curTime )
    return BEHAVIOR_STATUS_RUNNING;
  this->lastStateUpdateTime = curTime;
  result = ((int (__fastcall *)(idBehaviorState *, idBot *))this->Think)(a1: this, a2: bot);
  stateFlags = this->stateFlags;
  v6 = stateFlags | 0x10;
  if ( result != BEHAVIOR_STATUS_ERROR )
    v6 = stateFlags & 0xFFFFFFEF;
  this->stateFlags = v6;
  return result;
}


// ========================================================================
// ?InternalGetPriority@idBehaviorState@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B3B148
// RVA : 0x00B3B148
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

behaviorPriority_t __fastcall idBehaviorState::InternalGetPriority(idBehaviorState *this, idBot *bot, int curTime)
{
  if ( (unsigned __int8)idBehaviorState::IsUseAble(this, bot) == 0 )
    return BEHAVIOR_PRIORITY_NULL;
  if ( ((this->stateFlags & 1) == 0 || this->stateUpdateDelay + this->lastStateUpdateTime <= curTime)
    && this->lastPriorityUpdateTime < curTime )
  {
    this->lastPriorityUpdateTime = curTime;
    this->lastPriority = this->GetPriority(this, a2: bot, a3: curTime);
  }
  return this->lastPriority;
}


// ========================================================================
// ?InternalThink@idBehaviorDecorator@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B3B1E0
// RVA : 0x00B3B1E0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

// attributes: thunk
behaviorStatus_t __fastcall idBehaviorDecorator::InternalThink(idBehaviorDecorator *this, idBot *bot, int curTime)
{
  return idBehaviorState::InternalThink(this, bot, curTime);
}


// ========================================================================
// ?InternalGetPriority@idBehaviorParallel@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B3B1E8
// RVA : 0x00B3B1E8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

behaviorPriority_t __fastcall idBehaviorParallel::InternalGetPriority(
        idBehaviorParallel *this,
        idBot *bot,
        int curTime)
{
  int v6; // r29
  int i; // r31
  behaviorPriority_t result; // r3

  if ( idBehaviorState::InternalGetPriority(this, bot, curTime) == BEHAVIOR_PRIORITY_NULL )
    return BEHAVIOR_PRIORITY_NULL;
  v6 = 0;
  if ( this->children.num <= 0 )
    return BEHAVIOR_PRIORITY_NULL;
  for ( i = 0; ; ++i )
  {
    result = this->children.list[i]->InternalGetPriority(this: this->children.list[i], a2: bot, a3: curTime);
    if ( result > BEHAVIOR_PRIORITY_NULL )
      break;
    if ( ++v6 >= this->children.num )
      return BEHAVIOR_PRIORITY_NULL;
  }
  return result;
}


// ========================================================================
// ?InternalThink@idBehaviorParallel@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B3B268
// RVA : 0x00B3B268
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

int __fastcall idBehaviorParallel::InternalThink(idBehaviorParallel *this, idBot *bot, int curTime)
{
  behaviorStatus_t v6; // r3
  char v7; // r25
  int v8; // r26
  int i; // r27
  idBehaviorState *v10; // r31
  int v11; // r3
  int v12; // r10
  int v13; // r3

  v6 = idBehaviorState::InternalThink(this, bot, curTime);
  if ( v6 == BEHAVIOR_STATUS_ERROR )
    return -1;
  if ( v6 == BEHAVIOR_STATUS_FINISHED )
    return 0;
  v7 = 0;
  v8 = 0;
  if ( this->children.num > 0 )
  {
    for ( i = 0; ; ++i )
    {
      v10 = this->children.list[i];
      v11 = v10->InternalGetPriority(this: v10, a2: bot, a3: curTime);
      v12 = v10->stateFlags & 1;
      if ( v11 > 0 )
        break;
      if ( v12 != 0 )
        goto LABEL_13;
LABEL_14:
      if ( ++v8 >= this->children.num )
        return v7 != 0;
    }
    if ( v12 == 0 )
      v10->InternalEnter(this: v10, a2: bot, a3: curTime);
    v13 = v10->InternalThink(this: v10, a2: bot, a3: curTime);
    if ( v13 < -1 )
      goto LABEL_14;
    if ( v13 > 0 )
    {
      if ( v13 == 1 )
        v7 = 1;
      goto LABEL_14;
    }
LABEL_13:
    v10->InternalExit(this: v10, a2: bot, a3: curTime);
    goto LABEL_14;
  }
  return v7 != 0;
}


// ========================================================================
// ?InternalThink@idBehaviorParallelUntilFail@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B3B3A8
// RVA : 0x00B3B3A8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

int __fastcall idBehaviorParallelUntilFail::InternalThink(idBehaviorParallelUntilFail *this, idBot *bot, int curTime)
{
  behaviorStatus_t v6; // r3
  char v7; // r25
  int v8; // r26
  int i; // r27
  idBehaviorState *v10; // r31
  int v11; // r3
  int v12; // r10
  int v13; // r3

  v6 = idBehaviorState::InternalThink(this, bot, curTime);
  if ( v6 == BEHAVIOR_STATUS_ERROR )
    return -1;
  if ( v6 == BEHAVIOR_STATUS_FINISHED )
    return 0;
  v7 = 0;
  v8 = 0;
  if ( this->children.num > 0 )
  {
    for ( i = 0; ; ++i )
    {
      v10 = this->children.list[i];
      v11 = v10->InternalGetPriority(this: v10, a2: bot, a3: curTime);
      v12 = v10->stateFlags & 1;
      if ( v11 > 0 )
        break;
      if ( v12 != 0 )
        goto LABEL_13;
LABEL_14:
      if ( ++v8 >= this->children.num )
        return v7 != 0;
    }
    if ( v12 == 0 )
      v10->InternalEnter(this: v10, a2: bot, a3: curTime);
    v13 = v10->InternalThink(this: v10, a2: bot, a3: curTime);
    if ( v13 == -1 )
    {
      v10->InternalExit(this: v10, a2: bot, a3: curTime);
      return -1;
    }
    if ( v13 != 0 )
    {
      if ( v13 == 1 )
        v7 = 1;
      goto LABEL_14;
    }
LABEL_13:
    v10->InternalExit(this: v10, a2: bot, a3: curTime);
    goto LABEL_14;
  }
  return v7 != 0;
}


// ========================================================================
// ?InternalGetPriority@idBehaviorSelector@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B3B500
// RVA : 0x00B3B500
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

behaviorPriority_t __fastcall idBehaviorSelector::InternalGetPriority(
        idBehaviorSelector *this,
        idBot *bot,
        int curTime)
{
  behaviorPriority_t result; // r3
  int v7; // r26
  int i; // r29
  idBehaviorState *v9; // r31

  if ( idBehaviorState::InternalGetPriority(this, bot, curTime) == BEHAVIOR_PRIORITY_NULL )
    return BEHAVIOR_PRIORITY_NULL;
  if ( (this->stateFlags & 1) != 0 )
    return this->currentState->InternalGetPriority(this: this->currentState, a2: bot, a3: curTime);
  v7 = 0;
  if ( this->children.num <= 0 )
    return BEHAVIOR_PRIORITY_NULL;
  for ( i = 0; ; ++i )
  {
    v9 = this->children.list[i];
    result = v9->InternalGetPriority(this: v9, a2: bot, a3: curTime);
    if ( result > BEHAVIOR_PRIORITY_NULL )
      break;
    if ( ++v7 >= this->children.num )
      return BEHAVIOR_PRIORITY_NULL;
  }
  this->currentState = v9;
  return result;
}


// ========================================================================
// ?InternalThink@idBehaviorSelector@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B3B5C8
// RVA : 0x00B3B5C8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

int __fastcall idBehaviorSelector::InternalThink(idBehaviorSelector *this, idBot *bot, int curTime)
{
  behaviorStatus_t v6; // r3
  idBehaviorState_vtbl *v7; // r11
  int v8; // r3
  int v9; // r28

  v6 = idBehaviorState::InternalThink(this, bot, curTime);
  if ( v6 == BEHAVIOR_STATUS_ERROR )
  {
    this->currentState->InternalExit(this: this->currentState, a2: bot, a3: curTime);
    return -1;
  }
  else
  {
    v7 = this->currentState->__vftable;
    if ( v6 != BEHAVIOR_STATUS_FINISHED )
    {
      v8 = ((int (*)(void))v7->InternalThink)();
      v9 = v8;
      if ( v8 >= -1 && v8 <= 0 )
        this->currentState->InternalExit(this: this->currentState, a2: bot, a3: curTime);
      return v9;
    }
    else
    {
      ((void (*)(void))v7->InternalExit)();
      return 0;
    }
  }
}


// ========================================================================
// ?InternalGetPriority@idBehaviorSelectorLooping@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B3B688
// RVA : 0x00B3B688
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

behaviorPriority_t __fastcall idBehaviorSelectorLooping::InternalGetPriority(
        idBehaviorSelectorLooping *this,
        idBot *bot,
        int curTime)
{
  idBehaviorState *currentState; // r3
  behaviorPriority_t result; // r3
  int v8; // r28
  int i; // r29
  idBehaviorState *v10; // r31

  if ( idBehaviorState::InternalGetPriority(this, bot, curTime) == BEHAVIOR_PRIORITY_NULL )
    return BEHAVIOR_PRIORITY_NULL;
  if ( (this->stateFlags & 1) != 0 )
  {
    currentState = this->currentState;
    if ( currentState != nullptr )
      return currentState->InternalGetPriority(this: currentState, a2: bot, a3: curTime);
  }
  v8 = 0;
  if ( this->children.num <= 0 )
    return BEHAVIOR_PRIORITY_NULL;
  for ( i = 0; ; ++i )
  {
    v10 = this->children.list[i];
    result = v10->InternalGetPriority(this: v10, a2: bot, a3: curTime);
    if ( result > BEHAVIOR_PRIORITY_NULL )
      break;
    if ( ++v8 >= this->children.num )
      return BEHAVIOR_PRIORITY_NULL;
  }
  this->currentState = v10;
  return result;
}


// ========================================================================
// ?InternalThink@idBehaviorSelectorLooping@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B3B758
// RVA : 0x00B3B758
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

int __fastcall idBehaviorSelectorLooping::InternalThink(idBehaviorSelectorLooping *this, idBot *bot, int curTime)
{
  behaviorStatus_t v6; // r3
  idBehaviorState *currentState; // r3
  int v8; // r25
  idBehaviorState *v9; // r3
  bool v10; // r30
  char v11; // r3
  int v12; // r28
  int v13; // r29
  idBehaviorState *v14; // r30
  int v15; // r29
  int v16; // r30
  idBehaviorState *v17; // r3
  idBehaviorState *v18; // r3
  char v19; // r30
  behaviorStatus_t v20; // r3

  v6 = idBehaviorState::InternalThink(this, bot, curTime);
  if ( v6 == BEHAVIOR_STATUS_ERROR )
    return -1;
  if ( v6 == BEHAVIOR_STATUS_FINISHED )
    return 0;
  currentState = this->currentState;
  v8 = -1;
  if ( currentState != nullptr
    && currentState->InternalGetPriority(this: currentState, a2: bot, a3: curTime) == BEHAVIOR_PRIORITY_NULL )
  {
    v8 = this->GetStateIndex_2(this, a2: this->currentState);
    this->currentState = nullptr;
  }
  v9 = this->currentState;
  v10 = v9 == nullptr || (v9->stateFlags & 0x10) != 0;
  v11 = v9 == nullptr || v9->IsInterruptable(this: v9);
  if ( v11 != 0 || v10 )
  {
    v12 = 0;
    if ( this->children.num > 0 )
    {
      v13 = 0;
      while ( 1 )
      {
        if ( v12 != v8 )
        {
          v14 = this->children.list[v13];
          if ( v14->InternalGetPriority(this: v14, a2: bot, a3: curTime) > BEHAVIOR_PRIORITY_NULL )
            break;
        }
        ++v12;
        ++v13;
        if ( v12 >= this->children.num )
          goto LABEL_21;
      }
      this->currentState = v14;
    }
LABEL_21:
    if ( this->currentState != nullptr )
    {
      v15 = 0;
      if ( this->children.num > 0 )
      {
        v16 = 0;
        do
        {
          v17 = this->children.list[v16];
          if ( v17 != this->currentState && (v17->stateFlags & 1) != 0 )
            v17->InternalExit(this: v17, a2: bot, a3: curTime);
          ++v15;
          ++v16;
        }
        while ( v15 < this->children.num );
      }
    }
  }
  v18 = this->currentState;
  v19 = 0;
  if ( v18 == nullptr )
    return v19 != 0;
  if ( (v18->stateFlags & 1) == 0 )
    v18->InternalEnter(this: v18, a2: bot, a3: curTime);
  v20 = this->currentState->InternalThink(this: this->currentState, a2: bot, a3: curTime);
  if ( v20 == BEHAVIOR_STATUS_ERROR )
  {
    this->currentState->InternalExit(this: this->currentState, a2: bot, a3: curTime);
    return -1;
  }
  if ( v20 != BEHAVIOR_STATUS_FINISHED )
  {
    if ( v20 == BEHAVIOR_STATUS_RUNNING )
      v19 = 1;
    return v19 != 0;
  }
  this->currentState->InternalExit(this: this->currentState, a2: bot, a3: curTime);
  this->currentState = nullptr;
  return 1;
}


// ========================================================================
// ?InternalGetPriority@idBehaviorSelectorBest@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B3B9F0
// RVA : 0x00B3B9F0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

int __fastcall idBehaviorSelectorBest::InternalGetPriority(idBehaviorSelectorBest *this, idBot *bot, int curTime)
{
  idBehaviorState *currentState; // r3
  int v8; // r29
  idBehaviorState *v9; // r24
  int v10; // r27
  int v11; // r28
  idBehaviorState *v12; // r31
  int v13; // r3

  if ( idBehaviorState::InternalGetPriority(this, bot, curTime) == BEHAVIOR_PRIORITY_NULL )
    return 0;
  if ( (this->stateFlags & 1) != 0 )
  {
    currentState = this->currentState;
    if ( currentState != nullptr )
      return currentState->InternalGetPriority(this: currentState, a2: bot, a3: curTime);
  }
  v8 = 0;
  v9 = nullptr;
  v10 = 0;
  if ( this->children.num <= 0 )
    return 0;
  v11 = 0;
  do
  {
    v12 = this->children.list[v11];
    v13 = v12->InternalGetPriority(this: v12, a2: bot, a3: curTime);
    if ( v13 > v8 )
    {
      v8 = v13;
      v9 = v12;
    }
    ++v10;
    ++v11;
  }
  while ( v10 < this->children.num );
  if ( v9 == nullptr )
    return 0;
  this->currentState = v9;
  return v8;
}


// ========================================================================
// ?InternalThink@idBehaviorSelectorBestLooping@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B3BAD8
// RVA : 0x00B3BAD8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

behaviorStatus_t __fastcall idBehaviorSelectorBestLooping::InternalThink(
        idBehaviorSelectorBestLooping *this,
        idBot *bot,
        int curTime)
{
  behaviorStatus_t v6; // r3
  idBehaviorState *currentState; // r3
  int v8; // r24
  idBehaviorState *v9; // r3
  bool v10; // r30
  char v11; // r3
  int v12; // r28
  int v13; // r27
  int v14; // r29
  idBehaviorState *v15; // r30
  int v16; // r3
  int v17; // r29
  int v18; // r30
  idBehaviorState *v19; // r3
  idBehaviorState *v20; // r3
  char v21; // r30
  behaviorStatus_t v22; // r3
  behaviorStatus_t result; // r3

  v6 = idBehaviorState::InternalThink(this, bot, curTime);
  if ( v6 != BEHAVIOR_STATUS_ERROR )
  {
    if ( v6 == BEHAVIOR_STATUS_FINISHED )
      return BEHAVIOR_STATUS_FINISHED;
    currentState = this->currentState;
    v8 = -1;
    if ( currentState != nullptr
      && currentState->InternalGetPriority(this: currentState, a2: bot, a3: curTime) == BEHAVIOR_PRIORITY_NULL )
    {
      v8 = this->GetStateIndex_2(this, a2: this->currentState);
      this->currentState = nullptr;
    }
    v9 = this->currentState;
    v10 = v9 == nullptr || (v9->stateFlags & 0x10) != 0;
    v11 = v9 == nullptr || v9->IsInterruptable(this: v9);
    if ( v11 != 0 || v10 )
    {
      v12 = 0;
      v13 = 0;
      if ( this->children.num > 0 )
      {
        v14 = 0;
        do
        {
          if ( v13 != v8 )
          {
            v15 = this->children.list[v14];
            v16 = v15->InternalGetPriority(this: v15, a2: bot, a3: curTime);
            if ( v16 > v12 )
            {
              v12 = v16;
              this->currentState = v15;
            }
          }
          ++v13;
          ++v14;
        }
        while ( v13 < this->children.num );
      }
      if ( this->currentState != nullptr )
      {
        v17 = 0;
        if ( this->children.num > 0 )
        {
          v18 = 0;
          do
          {
            v19 = this->children.list[v18];
            if ( v19 != this->currentState && (v19->stateFlags & 1) != 0 )
              v19->InternalExit(this: v19, a2: bot, a3: curTime);
            ++v17;
            ++v18;
          }
          while ( v17 < this->children.num );
        }
      }
    }
    v20 = this->currentState;
    v21 = 0;
    if ( v20 == nullptr )
      goto LABEL_33;
    if ( (v20->stateFlags & 1) == 0 )
      v20->InternalEnter(this: v20, a2: bot, a3: curTime);
    v22 = this->currentState->InternalThink(this: this->currentState, a2: bot, a3: curTime);
    if ( v22 != BEHAVIOR_STATUS_ERROR )
    {
      if ( v22 == BEHAVIOR_STATUS_FINISHED )
      {
        this->currentState->InternalExit(this: this->currentState, a2: bot, a3: curTime);
        v21 = 1;
        this->currentState = nullptr;
      }
LABEL_33:
      if ( this->currentState != nullptr )
        return BEHAVIOR_STATUS_RUNNING;
      result = BEHAVIOR_STATUS_FINISHED;
      if ( v21 != 0 )
        return BEHAVIOR_STATUS_RUNNING;
      return result;
    }
  }
  return BEHAVIOR_STATUS_ERROR;
}


// ========================================================================
// ?InternalGetPriority@idBehaviorSequence@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B3BD50
// RVA : 0x00B3BD50
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

behaviorPriority_t __fastcall idBehaviorSequence::InternalGetPriority(
        idBehaviorSequence *this,
        idBot *bot,
        int curTime)
{
  behaviorPriority_t result; // r3
  int v7; // r28
  int v8; // r29
  idBehaviorState *v9; // r31

  if ( idBehaviorState::InternalGetPriority(this, bot, curTime) != BEHAVIOR_PRIORITY_NULL )
  {
    if ( (this->stateFlags & 1) != 0 )
      return this->currentState->InternalGetPriority(this: this->currentState, a2: bot, a3: curTime);
    v7 = 0;
    if ( this->children.num > 0 )
    {
      v8 = 0;
      do
      {
        v9 = this->children.list[v8];
        result = v9->InternalGetPriority(this: v9, a2: bot, a3: curTime);
        if ( result == BEHAVIOR_PRIORITY_NULL )
          break;
        if ( (~v9->stateFlags & 0x20) != 0 )
        {
          this->currentState = v9;
          this->currentStateIndex = v7;
          return result;
        }
        ++v7;
        ++v8;
      }
      while ( v7 < this->children.num );
    }
  }
  return BEHAVIOR_PRIORITY_NULL;
}


// ========================================================================
// ?InternalThink@idBehaviorSequence@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B3BE30
// RVA : 0x00B3BE30
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

int __fastcall idBehaviorSequence::InternalThink(idBehaviorSequence *this, idBot *bot, int curTime)
{
  behaviorStatus_t v6; // r3
  idBehaviorState *currentState; // r3
  behaviorStatus_t v8; // r3
  behaviorStatus_t v9; // r25
  int num; // r8
  int v11; // r28
  int v12; // r29
  idBehaviorState *v13; // r30

  v6 = idBehaviorState::InternalThink(this, bot, curTime);
  if ( v6 != BEHAVIOR_STATUS_ERROR )
  {
    if ( v6 == BEHAVIOR_STATUS_FINISHED )
      return 0;
    currentState = this->currentState;
    if ( currentState == nullptr )
      return 0;
    if ( (currentState->stateFlags & 1) == 0 )
      currentState->InternalEnter(this: currentState, a2: bot, a3: curTime);
    v8 = this->currentState->InternalThink(this: this->currentState, a2: bot, a3: curTime);
    v9 = v8;
    if ( v8 != BEHAVIOR_STATUS_ERROR )
    {
      if ( v8 == BEHAVIOR_STATUS_FINISHED )
      {
        this->currentState->InternalExit(this: this->currentState, a2: bot, a3: curTime);
        num = this->children.num;
        v11 = this->currentStateIndex + 1;
        this->currentState = nullptr;
        if ( v11 < num )
        {
          v12 = v11;
          do
          {
            v13 = this->children.list[v12];
            if ( v13->InternalGetPriority(this: v13, a2: bot, a3: curTime) == BEHAVIOR_PRIORITY_NULL )
              return 0;
            if ( (~v13->stateFlags & 0x20) != 0 )
            {
              this->currentState = v13;
              this->currentStateIndex = v11;
              break;
            }
            ++v11;
            ++v12;
          }
          while ( v11 < this->children.num );
        }
        if ( this->currentState == nullptr )
          return 0;
      }
      return v9;
    }
  }
  return -1;
}


// ========================================================================
// ?InternalGetPriority@idBehaviorSequenceRandom@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B3BF90
// RVA : 0x00B3BF90
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

behaviorPriority_t __fastcall idBehaviorSequenceRandom::InternalGetPriority(
        idBehaviorSequenceRandom *this,
        idBot *bot,
        int curTime)
{
  int v7; // r3
  idBehaviorState **list; // r9
  idBot *v9; // r4
  idBehaviorState *v10; // r30
  int v11; // r29
  int v12; // [sp+50h] [-30h] BYREF

  if ( idBehaviorState::InternalGetPriority(this, bot, curTime) == BEHAVIOR_PRIORITY_NULL )
    return BEHAVIOR_PRIORITY_NULL;
  if ( (this->stateFlags & 1) != 0 )
    return this->currentState->InternalGetPriority(this: this->currentState, a2: bot, a3: curTime);
  v7 = idRandom2::RandomInt(this: &clientGame->random, min: 0, max: this->children.num - 1);
  list = this->children.list;
  v9 = bot;
  v12 = v7;
  v10 = list[v7];
  v11 = v10->InternalGetPriority(this: v10, a2: v9, a3: curTime);
  if ( v11 <= 0 )
    return BEHAVIOR_PRIORITY_NULL;
  this->currentState = v10;
  idList<idEntityPtr<idActor>,5>::RemoveFast(this: &this->runChildren, obj: &v12);
  return v11;
}


// ========================================================================
// ?InternalThink@idBehaviorSequenceRandom@@MAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B3C060
// RVA : 0x00B3C060
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

int __fastcall idBehaviorSequenceRandom::InternalThink(idBehaviorSequenceRandom *this, idBot *bot, int curTime)
{
  behaviorStatus_t v6; // r3
  idBehaviorState *currentState; // r3
  behaviorStatus_t v8; // r3
  int num; // r11
  int v10; // r3
  int v11; // r10
  int v12; // r10
  behaviorPriority_t v13; // r3

  v6 = idBehaviorState::InternalThink(this, bot, curTime);
  if ( v6 != BEHAVIOR_STATUS_ERROR )
  {
    if ( v6 == BEHAVIOR_STATUS_FINISHED )
      return 0;
    currentState = this->currentState;
    if ( currentState == nullptr )
      return 0;
    if ( (currentState->stateFlags & 1) == 0 )
      currentState->InternalEnter(this: currentState, a2: bot, a3: curTime);
    v8 = this->currentState->InternalThink(this: this->currentState, a2: bot, a3: curTime);
    if ( v8 != BEHAVIOR_STATUS_ERROR )
    {
      if ( v8 != BEHAVIOR_STATUS_FINISHED )
        return this->currentState == nullptr ? 0 : v8;
      this->currentState->InternalExit(this: this->currentState, a2: bot, a3: curTime);
      num = this->runChildren.num;
      if ( num <= 0 )
      {
        v8 = BEHAVIOR_STATUS_FINISHED;
        this->currentState = nullptr;
        return this->currentState == nullptr ? 0 : v8;
      }
      v10 = idRandom2::RandomInt(this: &clientGame->random, min: 0, max: num - 1);
      this->currentState = this->children.list[this->runChildren.list[v10]];
      if ( v10 >= 0 )
      {
        v11 = this->runChildren.num;
        if ( v10 < v11 )
        {
          v12 = v11 - 1;
          this->runChildren.num = v12;
          if ( v10 != v12 )
            this->runChildren.list[v10] = this->runChildren.list[v12];
        }
      }
      v13 = this->currentState->GetPriority(this: this->currentState, a2: bot, a3: curTime);
      return this->currentState != nullptr && (-v13 & (unsigned int)~v13) >> 31;
    }
  }
  return -1;
}


// ========================================================================
// ?InternalExit@idBehaviorSequenceRandom@@MAAXPAVidBot@@H@Z
// EA  : 0x82B3C1F8
// RVA : 0x00B3C1F8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorSequenceRandom::InternalExit(idBehaviorSequenceRandom *this, idBot *bot, int curTime)
{
  idBehaviorState *currentState; // r3

  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->runChildren);
  currentState = this->currentState;
  if ( currentState != nullptr && (currentState->stateFlags & 1) != 0 )
    currentState->InternalExit(this: currentState, a2: bot, a3: curTime);
  this->currentState = nullptr;
  idBehaviorComposite::InternalExit(this, bot, curTime);
}


// ========================================================================
// ?DebugRenderGui@idBehaviorState@@MBAXPBVidBot@@AAVidGuiListBox@@H@Z
// EA  : 0x82B3C278
// RVA : 0x00B3C278
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorState::DebugRenderGui(idBehaviorState *this, const idBot *bot, idGuiListBox *gui, int indent)
{
  int i; // r29
  idColor *v8; // r9
  float r; // r8
  float g; // r7
  float b; // r6
  float a; // r5
  const char **v13; // r3
  char *data; // r30
  __int64 v15; // r29
  idGuiListBox *v16; // r3
  idGuiListBox *v17; // r3
  __int64 v18; // r10
  __int64 v19; // r8
  idGuiListBox *v20; // r3
  __int64 v21; // r10
  __int64 v22; // r8
  __int64 v23; // r6
  idColor v24; // [sp+50h] [-C0h] BYREF
  idStr v25; // [sp+60h] [-B0h] BYREF
  idStr v26; // [sp+80h] [-90h] BYREF
  idStr v27[3]; // [sp+A0h] [-70h] BYREF

  v26.len = 0;
  v26.allocedAndFlag = 20;
  v26.data = v26.baseBuffer;
  v26.baseBuffer[0] = 0;
  if ( indent > 0 )
  {
    for ( i = indent; i != 0; --i )
      idStr::Append(this: &v26, text: "  ");
  }
  v24.a = -1.0;
  v24.b = -1.0;
  v24.g = -1.0;
  v24.r = -1.0;
  if ( (unsigned __int8)idBehaviorState::IsUseAble(this, bot) != 0 )
  {
    if ( (this->stateFlags & 1) != 0 )
    {
      v8 = &idColor::colorGreen;
      r = idColor::colorGreen.r;
    }
    else
    {
      v8 = &idColor::colorRed;
      r = idColor::colorRed.r;
    }
  }
  else
  {
    v8 = &idColor::colorBlack;
    r = idColor::colorBlack.r;
  }
  g = v8->g;
  b = v8->b;
  a = v8->a;
  v25.allocedAndFlag = 20;
  v25.len = 0;
  v24.r = r;
  v24.g = g;
  v24.b = b;
  v24.a = a;
  v25.data = v25.baseBuffer;
  v25.baseBuffer[0] = 0;
  this->GetDebugString(this, a2: &v25);
  idStr::StripLeading(this: &v25, string: "idBotBehavior");
  v13 = (const char **)this->GetType(this);
  idStr::idStr(this: v27, text: *v13);
  idStr::StripLeading(this: v27, string: "idBotBehavior");
  data = v25.data;
  v15 = __PAIR64__((unsigned int)v26.data, (unsigned int)v27[0].data);
  v16 = idGuiListBox::Row(this: gui);
  v17 = idGuiListBox::Color(this: v16, color: &v24);
  v20 = idGuiListBox::Printf(this: v17, fmt: "%s%s", a3: v15, a4: v19, a5: v18);
  idGuiListBox::Printf(this: v20, fmt: data, a3: v23, a4: v22, a5: v21);
  idStr::FreeData(this: v27);
  idStr::FreeData(this: &v25);
  idStr::FreeData(this: &v26);
}


// ========================================================================
// __unwind$491310
// EA  : 0x82B3C42C
// RVA : 0x00B3C42C
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void _unwind_491310()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$491311
// EA  : 0x82B3C454
// RVA : 0x00B3C454
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void _unwind_491311()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$491312
// EA  : 0x82B3C47C
// RVA : 0x00B3C47C
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void _unwind_491312()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 160));
}


// ========================================================================
// ??0idBehaviorComposite@@QAA@XZ
// EA  : 0x82B3C4B0
// RVA : 0x00B3C4B0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

idBehaviorComposite *__fastcall idBehaviorComposite::idBehaviorComposite(idBehaviorComposite *this)
{
  idBehaviorState::idBehaviorState(this);
  this->__vftable = (idBehaviorComposite_vtbl *)&idBehaviorComposite::`vftable';
  this->children.list = nullptr;
  this->children.granularity = 0;
  this->children.memTag = 5;
  this->children.listStatic = 0;
  this->children.size = 0;
  this->children.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->children);
  return this;
}


// ========================================================================
// __unwind$491425
// EA  : 0x82B3C524
// RVA : 0x00B3C524
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void _unwind_491425()
{
  int v0; // r12

  idBehaviorAction::~idBehaviorAction(this: *(idBehaviorAction **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idBehaviorComposite@@UAA@XZ
// EA  : 0x82B3C558
// RVA : 0x00B3C558
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorComposite::~idBehaviorComposite(idBehaviorComposite *this)
{
  idList<idBehaviorState *,5> *p_children; // r29

  this->__vftable = (idBehaviorComposite_vtbl *)&idBehaviorComposite::`vftable';
  p_children = &this->children;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->children);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_children);
  this->__vftable = (idBehaviorComposite_vtbl *)&idBehaviorState::`vftable';
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// __unwind$491446
// EA  : 0x82B3C5AC
// RVA : 0x00B3C5AC
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void _unwind_491446()
{
  int v0; // r12

  idBehaviorAction::~idBehaviorAction(this: *(idBehaviorAction **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$491447
// EA  : 0x82B3C5D4
// RVA : 0x00B3C5D4
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void _unwind_491447()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 56));
}


// ========================================================================
// ?DebugRenderGui@idBehaviorComposite@@UBAXPBVidBot@@AAVidGuiListBox@@H@Z
// EA  : 0x82B3C600
// RVA : 0x00B3C600
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorComposite::DebugRenderGui(
        idBehaviorComposite *this,
        const idBot *bot,
        idGuiListBox *gui,
        int indent)
{
  int v8; // r30
  int v9; // r26
  int v10; // r31

  idBehaviorState::DebugRenderGui(this, bot, gui, indent);
  v8 = 0;
  if ( this->children.num > 0 )
  {
    v9 = indent + 1;
    v10 = 0;
    do
    {
      this->children.list[v10]->DebugRenderGui(this: this->children.list[v10], a2: bot, a3: gui, a4: v9);
      ++v8;
      ++v10;
    }
    while ( v8 < this->children.num );
  }
}


// ========================================================================
// ?DebugRenderGui@idBehaviorDecorator@@UBAXPBVidBot@@AAVidGuiListBox@@H@Z
// EA  : 0x82B3C678
// RVA : 0x00B3C678
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorDecorator::DebugRenderGui(
        idBehaviorDecorator *this,
        const idBot *bot,
        idGuiListBox *gui,
        int indent)
{
  idBehaviorState *child; // r11

  idBehaviorState::DebugRenderGui(this, bot, gui, indent);
  child = this->child;
  if ( (child->stateFlags & 1) != 0 )
    ((void (*)(void))child->DebugRenderGui)();
}


// ========================================================================
// ??0idBehaviorParallel@@QAA@XZ
// EA  : 0x82B3C6D8
// RVA : 0x00B3C6D8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

idBehaviorParallel *__fastcall idBehaviorParallel::idBehaviorParallel(idBehaviorParallel *this)
{
  idBehaviorComposite::idBehaviorComposite(this);
  this->__vftable = (idBehaviorParallel_vtbl *)&idBehaviorParallel::`vftable';
  return this;
}


// ========================================================================
// ??0idBehaviorParallelUntilFail@@QAA@XZ
// EA  : 0x82B3C718
// RVA : 0x00B3C718
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

idBehaviorParallelUntilFail *__fastcall idBehaviorParallelUntilFail::idBehaviorParallelUntilFail(
        idBehaviorParallelUntilFail *this)
{
  idBehaviorComposite::idBehaviorComposite(this);
  this->__vftable = (idBehaviorParallelUntilFail_vtbl *)&idBehaviorParallelUntilFail::`vftable';
  return this;
}


// ========================================================================
// ??0idBehaviorSelector@@QAA@XZ
// EA  : 0x82B3C758
// RVA : 0x00B3C758
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

idBehaviorSelector *__fastcall idBehaviorSelector::idBehaviorSelector(idBehaviorSelector *this)
{
  idBehaviorComposite::idBehaviorComposite(this);
  this->currentState = nullptr;
  this->__vftable = (idBehaviorSelector_vtbl *)&idBehaviorSelector::`vftable';
  return this;
}


// ========================================================================
// ??1idBehaviorSelector@@UAA@XZ
// EA  : 0x82B3C7A0
// RVA : 0x00B3C7A0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorSelector::~idBehaviorSelector(idBehaviorSelectorRandom *this)
{
  this->currentState = nullptr;
  this->__vftable = (idBehaviorSelectorRandom_vtbl *)&idBehaviorSelector::`vftable';
  idBehaviorComposite::~idBehaviorComposite(this);
}


// ========================================================================
// ??0idBehaviorSelectorLooping@@QAA@XZ
// EA  : 0x82B3C7B8
// RVA : 0x00B3C7B8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

idBehaviorSelectorLooping *__fastcall idBehaviorSelectorLooping::idBehaviorSelectorLooping(
        idBehaviorSelectorLooping *this)
{
  idBehaviorComposite::idBehaviorComposite(this);
  this->currentState = nullptr;
  this->__vftable = (idBehaviorSelectorLooping_vtbl *)&idBehaviorSelectorLooping::`vftable';
  return this;
}


// ========================================================================
// ??0idBehaviorSelectorBest@@QAA@XZ
// EA  : 0x82B3C800
// RVA : 0x00B3C800
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

idBehaviorSelectorBest *__fastcall idBehaviorSelectorBest::idBehaviorSelectorBest(idBehaviorSelectorBest *this)
{
  idBehaviorComposite::idBehaviorComposite(this);
  this->currentState = nullptr;
  this->__vftable = (idBehaviorSelectorBest_vtbl *)&idBehaviorSelectorBest::`vftable';
  return this;
}


// ========================================================================
// ??0idBehaviorSelectorBestLooping@@QAA@XZ
// EA  : 0x82B3C848
// RVA : 0x00B3C848
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

idBehaviorSelectorBestLooping *__fastcall idBehaviorSelectorBestLooping::idBehaviorSelectorBestLooping(
        idBehaviorSelectorBestLooping *this)
{
  idBehaviorComposite::idBehaviorComposite(this);
  this->currentState = nullptr;
  this->__vftable = (idBehaviorSelectorBestLooping_vtbl *)&idBehaviorSelectorBestLooping::`vftable';
  return this;
}


// ========================================================================
// ??0idBehaviorSelectorRandom@@QAA@XZ
// EA  : 0x82B3C890
// RVA : 0x00B3C890
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

idBehaviorSelectorRandom *__fastcall idBehaviorSelectorRandom::idBehaviorSelectorRandom(idBehaviorSelectorRandom *this)
{
  idBehaviorComposite::idBehaviorComposite(this);
  this->currentState = nullptr;
  this->__vftable = (idBehaviorSelectorRandom_vtbl *)&idBehaviorSelectorRandom::`vftable';
  return this;
}


// ========================================================================
// ?InternalGetPriority@idBehaviorSelectorRandom@@MAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B3C8E0
// RVA : 0x00B3C8E0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

behaviorPriority_t __fastcall idBehaviorSelectorRandom::InternalGetPriority(
        idBehaviorSelectorRandom *this,
        idBot *bot,
        int curTime)
{
  int num; // r11
  int v8; // r30
  int v9; // r11
  signed int v10; // r25
  encounterGroupRole_t *list; // r24
  int v12; // r26
  int v13; // r29
  unsigned int v14; // r7
  int v15; // r5
  idBehaviorState *v16; // r30
  int v17; // r28
  int v18; // [sp+50h] [-A0h] BYREF
  idList<enum encounterGroupRole_t,5> v19[9]; // [sp+60h] [-90h] BYREF

  if ( idBehaviorState::InternalGetPriority(this, bot, curTime) == BEHAVIOR_PRIORITY_NULL )
    return BEHAVIOR_PRIORITY_NULL;
  if ( (this->stateFlags & 1) != 0 )
    return this->currentState->InternalGetPriority(this: this->currentState, a2: bot, a3: curTime);
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)v19);
  num = this->children.num;
  v8 = 0;
  v18 = 0;
  if ( num > 0 )
  {
    do
    {
      idList<idAnimWebBlendTree *,5>::Append(this: v19, obj: (const encounterGroupRole_t *)&v18);
      v9 = this->children.num;
      v18 = ++v8;
    }
    while ( v8 < v9 );
  }
  v10 = v19[0].num;
  if ( v19[0].num <= 0 )
  {
LABEL_17:
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v19);
    return BEHAVIOR_PRIORITY_NULL;
  }
  list = v19[0].list;
  while ( 1 )
  {
    v12 = v10 - 1;
    if ( v10 - 1 > 0 )
    {
      v14 = 1664525 * clientGame->random.seed + 1013904223;
      __twllei(v10, 0);
      clientGame->random.seed = v14;
      v15 = (v14 >> 10) & 0x7FFF;
      v13 = v15 % v10;
      __twlgei(v10 & ~(__ROL4__(v15, 1) - 1), 0xFFFFFFFF);
    }
    else
    {
      v13 = 0;
    }
    v16 = this->children.list[list[v13]];
    v17 = v16->InternalGetPriority(this: v16, a2: bot, a3: curTime);
    if ( v17 > 0 )
      break;
    if ( v13 >= 0 && v13 < v10 )
    {
      --v10;
      v19[0].num = v12;
      if ( v13 != v12 )
        list[v13] = list[v12];
    }
    if ( v10 <= 0 )
      goto LABEL_17;
  }
  this->currentState = v16;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v19);
  return v17;
}


// ========================================================================
// __unwind$491630
// EA  : 0x82B3CA84
// RVA : 0x00B3CA84
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void _unwind_491630()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 96));
}


// ========================================================================
// ??0idBehaviorSequence@@QAA@XZ
// EA  : 0x82B3CAB0
// RVA : 0x00B3CAB0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

idBehaviorSequence *__fastcall idBehaviorSequence::idBehaviorSequence(idBehaviorSequence *this)
{
  idBehaviorComposite::idBehaviorComposite(this);
  this->currentStateIndex = -1;
  this->__vftable = (idBehaviorSequence_vtbl *)&idBehaviorSequence::`vftable';
  this->currentState = nullptr;
  return this;
}


// ========================================================================
// ??1idBehaviorSequence@@UAA@XZ
// EA  : 0x82B3CB00
// RVA : 0x00B3CB00
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorSequence::~idBehaviorSequence(idBehaviorSequence *this)
{
  this->currentState = nullptr;
  this->__vftable = (idBehaviorSequence_vtbl *)&idBehaviorSequence::`vftable';
  idBehaviorComposite::~idBehaviorComposite(this);
}


// ========================================================================
// ??0idBehaviorSequenceRandom@@QAA@XZ
// EA  : 0x82B3CB20
// RVA : 0x00B3CB20
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

idBehaviorSequenceRandom *__fastcall idBehaviorSequenceRandom::idBehaviorSequenceRandom(idBehaviorSequenceRandom *this)
{
  idBehaviorComposite::idBehaviorComposite(this);
  this->currentState = nullptr;
  this->currentStateIndex = -1;
  this->__vftable = (idBehaviorSequenceRandom_vtbl *)&idBehaviorSequenceRandom::`vftable';
  this->runChildren.list = nullptr;
  this->runChildren.granularity = 0;
  this->runChildren.memTag = 5;
  this->runChildren.listStatic = 0;
  this->runChildren.size = 0;
  this->runChildren.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->runChildren);
  return this;
}


// ========================================================================
// __unwind$491715_0
// EA  : 0x82B3CBA0
// RVA : 0x00B3CBA0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void _unwind_491715_0()
{
  int v0; // r12

  idBehaviorSequence::~idBehaviorSequence(this: *(idBehaviorSequence **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idBehaviorSequenceRandom@@UAA@XZ
// EA  : 0x82B3CBD0
// RVA : 0x00B3CBD0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorSequenceRandom::~idBehaviorSequenceRandom(idBehaviorSequenceRandom *this)
{
  this->__vftable = (idBehaviorSequenceRandom_vtbl *)&idBehaviorSequenceRandom::`vftable';
  this->currentState = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->runChildren);
  this->currentState = nullptr;
  this->__vftable = (idBehaviorSequenceRandom_vtbl *)&idBehaviorSequence::`vftable';
  idBehaviorComposite::~idBehaviorComposite(this);
}


// ========================================================================
// __unwind$491740
// EA  : 0x82B3CC24
// RVA : 0x00B3CC24
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void _unwind_491740()
{
  int v0; // r12

  idBehaviorSequence::~idBehaviorSequence(this: *(idBehaviorSequence **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idBehaviorTree@@QAA@XZ
// EA  : 0x82B3CC50
// RVA : 0x00B3CC50
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

idBehaviorTree *__fastcall idBehaviorTree::idBehaviorTree(idBehaviorTree *this)
{
  idBehaviorComposite::idBehaviorComposite(this);
  this->numFramesWithNoActiveChildren = 0;
  this->__vftable = (idBehaviorTree_vtbl *)&idBehaviorTree::`vftable';
  return this;
}


// ========================================================================
// ??1idBehaviorTree@@UAA@XZ
// EA  : 0x82B3CC98
// RVA : 0x00B3CC98
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorTree::~idBehaviorTree(idBehaviorTree *this)
{
  this->__vftable = (idBehaviorTree_vtbl *)&idBehaviorParallel::`vftable';
  idBehaviorComposite::~idBehaviorComposite(this);
}


// ========================================================================
// ?AppendState@idBehaviorComposite@@QAAXPAVidBehaviorTree@@PAVidBehaviorState@@@Z
// EA  : 0x82B3CD08
// RVA : 0x00B3CD08
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviortree.cpp
// ========================================================================

void __fastcall idBehaviorComposite::AppendState(
        idBehaviorComposite *this,
        idBehaviorTree *rootTree,
        idBehaviorState *newState,
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
        int a14,
        int a15,
        idBehaviorState *a16)
{
  a16 = newState;
  if ( newState != nullptr )
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->children,
      obj: (const encounterGroupRole_t *)&a16);
}

