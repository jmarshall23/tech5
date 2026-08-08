
// ========================================================================
// ?ClearEvent@idAnimWebEventHandler_Zion@@UAAXW4animWebEvent_t@@@Z
// EA  : 0x826F87C0
// RVA : 0x006F87C0
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebeventhandler.cpp
// ========================================================================

void __fastcall idAnimWebEventHandler_Zion::ClearEvent(
        idAnimWebEventHandler_Zion *this,
        const animWebEvent_t eventType)
{
  this->events[eventType].eventNum = -1;
}


// ========================================================================
// ?ClearEvents@idAnimWebEventHandler_Zion@@UAAXXZ
// EA  : 0x826F87E0
// RVA : 0x006F87E0
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebeventhandler.cpp
// ========================================================================

void __fastcall idAnimWebEventHandler_Zion::ClearEvents(idAnimWebEventHandler_Zion *this)
{
  this->events[0].eventNum = -1;
  this->events[1].eventNum = -1;
  this->events[2].eventNum = -1;
  this->events[3].eventNum = -1;
  this->events[4].eventNum = -1;
  this->events[5].eventNum = -1;
  this->events[6].eventNum = -1;
  this->events[7].eventNum = -1;
  this->events[8].eventNum = -1;
}


// ========================================================================
// ?SetEvent@idAnimWebEventHandler_Zion@@UAAXABVidAnimator_AnimWeb@@V?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@V?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@W4animWebEvent_t@@HW4priority_t@idAnimWebEvent@@@Z
// EA  : 0x826F8810
// RVA : 0x006F8810
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebeventhandler.cpp
// ========================================================================

void __fastcall idAnimWebEventHandler_Zion::SetEvent(
        idAnimWebEventHandler_Zion *this,
        const idAnimator_AnimWeb *web,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *swi,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *si,
        int eventType,
        const int eventNum,
        int priority)
{
  char *v10; // r11
  idGame *v13; // r26
  idGame *v14; // r25
  idDeclAnimWeb *v15; // r27
  idTypeInfoTools *v16; // r3
  const char *v17; // r31
  idTypeInfoTools *v18; // r3
  const char *v19; // r30
  const char *v20; // r28
  const char *v21; // r4
  idGame *v22; // r26
  idGame *v23; // r25
  idDeclAnimWeb *decl; // r27
  idTypeInfoTools *v25; // r3
  const char *EnumName; // r31
  idTypeInfoTools *v27; // r3
  const char *v28; // r30
  const char *StateName; // r28
  const char *SubWebName; // r4

  v10 = (char *)this + 12 * eventType;
  if ( *((_DWORD *)v10 + 3) > priority )
  {
    if ( animweb_debugEventHandler.valueInteger != 0 )
    {
      v22 = common->Game(this: common);
      v23 = common->Game(this: common);
      decl = web->decl;
      v25 = (idTypeInfoTools *)v22->GetTypeInfoTools(this: v22);
      EnumName = idTypeInfoTools::GetEnumName(
                   this: v25,
                   enumTypeName: "idAnimWebEvent::priority_t",
                   enumValue: priority,
                   defaultValue: "<unknown>");
      v27 = (idTypeInfoTools *)v23->GetTypeInfoTools(this: v23);
      v28 = idTypeInfoTools::GetEnumName(
              this: v27,
              enumTypeName: "animWebEvent_t",
              enumValue: eventType,
              defaultValue: "<unknown>");
      StateName = idDeclAnimWeb::GetStateName(this: decl, index: si);
      SubWebName = idDeclAnimWeb::GetSubWebName(this: decl, index: swi);
      idLib::Printf(
        fmt: "Ignored anim web web event '%s/%s', type %s, priority %s.\n",
        SubWebName,
        StateName,
        v28,
        EnumName);
    }
  }
  else
  {
    *((_WORD *)v10 + 2) = (_WORD)swi;
    *((_WORD *)v10 + 3) = (_WORD)si;
    *((_DWORD *)v10 + 3) = priority;
    *((_DWORD *)v10 + 2) = eventNum;
    if ( animweb_debugEventHandler.valueInteger != 0 )
    {
      v13 = common->Game(this: common);
      v14 = common->Game(this: common);
      v15 = web->decl;
      v16 = (idTypeInfoTools *)v13->GetTypeInfoTools(this: v13);
      v17 = idTypeInfoTools::GetEnumName(
              this: v16,
              enumTypeName: "idAnimWebEvent::priority_t",
              enumValue: priority,
              defaultValue: "<unknown>");
      v18 = (idTypeInfoTools *)v14->GetTypeInfoTools(this: v14);
      v19 = idTypeInfoTools::GetEnumName(
              this: v18,
              enumTypeName: "animWebEvent_t",
              enumValue: eventType,
              defaultValue: "<unknown>");
      v20 = idDeclAnimWeb::GetStateName(this: v15, index: si);
      v21 = idDeclAnimWeb::GetSubWebName(this: v15, index: swi);
      idLib::Printf(fmt: "Added anim web web event '%s/%s', type %s, priority %s.\n", v21, v20, v19, v17);
    }
  }
}


// ========================================================================
// ?TriggerEventType@idAnimWebEventHandler_Zion@@UAAXAAVidAnimator_AnimWeb@@PBVidDeclAnimWebNode@@W4animWebEvent_t@@H@Z
// EA  : 0x826F8A28
// RVA : 0x006F8A28
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebeventhandler.cpp
// ========================================================================

void __fastcall idAnimWebEventHandler_Zion::TriggerEventType(
        idAnimWebEventHandler_Zion *this,
        idAnimator_AnimWeb *web,
        const idDeclAnimWebNode *node,
        __int32 eventType,
        int eventParm)
{
  char *v7; // r11
  const idAnimWebEvent *v8; // r31
  idGame *v9; // r3
  idDeclAnimWeb *decl; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *value; // r28
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v12; // r27
  idTypeInfoTools *v13; // r3
  const char *EnumName; // r30
  const char *StateName; // r28
  const char *SubWebName; // r3

  if ( node != nullptr )
  {
    v7 = (char *)this + 12 * eventType;
    v8 = (const idAnimWebEvent *)(v7 + 4);
    if ( *((int *)v7 + 2) >= 0
      && node->subWebIndex.value == v8->swi.value
      && node->states.stateIndex[0].value == *((__int16 *)v7 + 3) )
    {
      idAnimator_AnimWeb::TriggerEvent(this: web, node, (animWebEvent_t)eventType, event: v8, eventParm);
      if ( animweb_debugEventHandler.valueInteger != 0 )
      {
        v9 = common->Game(this: common);
        decl = web->decl;
        value = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v8->si.value;
        v12 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v8->swi.value;
        v13 = (idTypeInfoTools *)v9->GetTypeInfoTools(this: v9);
        EnumName = idTypeInfoTools::GetEnumName(
                     this: v13,
                     enumTypeName: "animWebEvent_t",
                     enumValue: eventType,
                     defaultValue: "<unknown>");
        StateName = idDeclAnimWeb::GetStateName(this: decl, index: value);
        SubWebName = idDeclAnimWeb::GetSubWebName(this: decl, index: v12);
        idLib::Printf(fmt: "Triggered anim web web event '%s/%s', type %s.\n", SubWebName, StateName, EnumName);
      }
      v8->eventNum = -1;
    }
  }
}


// ========================================================================
// ?IsEventPending@idAnimWebEventHandler_Zion@@UBA_NW4animWebEvent_t@@@Z
// EA  : 0x826F8B50
// RVA : 0x006F8B50
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebeventhandler.cpp
// ========================================================================

BOOL __fastcall idAnimWebEventHandler_Zion::IsEventPending(
        idAnimWebEventHandler_Zion *this,
        const animWebEvent_t eventType)
{
  return this->events[eventType].eventNum >= 0;
}


// ========================================================================
// ?IsAnyEventPending@idAnimWebEventHandler_Zion@@UBA_NXZ
// EA  : 0x826F8B70
// RVA : 0x006F8B70
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebeventhandler.cpp
// ========================================================================

int __fastcall idAnimWebEventHandler_Zion::IsAnyEventPending(idAnimWebEventHandler_Zion *this)
{
  int v1; // r11
  int *i; // r10

  v1 = 0;
  for ( i = &this->events[0].eventNum; *i < 0; i += 3 )
  {
    if ( ++v1 >= 9 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ??0idAnimWebEventHandler_Zion@@QAA@XZ
// EA  : 0x826F8BA8
// RVA : 0x006F8BA8
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebeventhandler.cpp
// ========================================================================

idAnimWebEventHandler_Zion *__fastcall idAnimWebEventHandler_Zion::idAnimWebEventHandler_Zion(
        idAnimWebEventHandler_Zion *this)
{
  this->__vftable = (idAnimWebEventHandler_Zion_vtbl *)&idAnimWebEventHandler_Zion::`vftable';
  this->events[0].swi.value = -1;
  this->events[0].si.value = -1;
  this->events[0].eventNum = -1;
  this->events[0].priority = PRIORITY_LOW;
  this->events[1].swi.value = -1;
  this->events[1].si.value = -1;
  this->events[1].eventNum = -1;
  this->events[1].priority = PRIORITY_LOW;
  this->events[2].swi.value = -1;
  this->events[2].si.value = -1;
  this->events[2].eventNum = -1;
  this->events[2].priority = PRIORITY_LOW;
  this->events[3].swi.value = -1;
  this->events[3].si.value = -1;
  this->events[3].eventNum = -1;
  this->events[3].priority = PRIORITY_LOW;
  this->events[4].swi.value = -1;
  this->events[4].si.value = -1;
  this->events[4].eventNum = -1;
  this->events[4].priority = PRIORITY_LOW;
  this->events[5].swi.value = -1;
  this->events[5].si.value = -1;
  this->events[5].eventNum = -1;
  this->events[5].priority = PRIORITY_LOW;
  this->events[6].swi.value = -1;
  this->events[6].si.value = -1;
  this->events[6].eventNum = -1;
  this->events[6].priority = PRIORITY_LOW;
  this->events[7].swi.value = -1;
  this->events[7].si.value = -1;
  this->events[7].eventNum = -1;
  this->events[7].priority = PRIORITY_LOW;
  this->events[8].swi.value = -1;
  this->events[8].si.value = -1;
  this->events[8].eventNum = -1;
  this->events[8].priority = PRIORITY_LOW;
  return this;
}


// ========================================================================
// `dynamic initializer for 'animweb_debugEventHandler''
// EA  : 0x8333F450
// RVA : 0x0133F450
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebeventhandler.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__animweb_debugEventHandler__()
{
  idCVar::idCVar(
    this: &animweb_debugEventHandler,
    name: "animweb_debugEventHandler",
    value: "0",
    flags: 1,
    description: "1 = show debug info for he animweb event handler",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__animweb_debugEventHandler__);
}

