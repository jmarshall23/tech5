
// ========================================================================
// ??1idWidgetAction@@QAA@XZ
// EA  : 0x825AB1D8
// RVA : 0x005AB1D8
// PDB : w:\tech5\tungsten\game\menus\menuwidget.h
// ========================================================================

void __fastcall idWidgetAction::~idWidgetAction(idWidgetAction *this)
{
  idSWFScriptFunction *scriptFunction; // r3

  scriptFunction = this->scriptFunction;
  if ( scriptFunction != nullptr )
    ((void (__fastcall *)(idSWFScriptFunction *, int))scriptFunction->dtr_idSWFScriptFunction)(
      a1: scriptFunction,
      a2: 1);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &this->parms.idStaticList<idSWFScriptVar,16>);
}


// ========================================================================
// __unwind$725568
// EA  : 0x825AB23C
// RVA : 0x005AB23C
// PDB : w:\tech5\tungsten\game\menus\menuwidget.h
// ========================================================================

void _unwind_725568()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??0idWidgetAction@@QAA@XZ
// EA  : 0x825AC640
// RVA : 0x005AC640
// PDB : w:\tech5\tungsten\game\menus\menuwidget.h
// ========================================================================

idWidgetAction *__fastcall idWidgetAction::idWidgetAction(idWidgetAction *this)
{
  this->action = WIDGET_ACTION_NONE;
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &this->parms.idStaticList<idSWFScriptVar,16>);
  this->scriptFunction = nullptr;
  return this;
}


// ========================================================================
// ??1idMenuDataSource@@UAA@XZ
// EA  : 0x82DA2018
// RVA : 0x00DA2018
// PDB : w:\tech5\tungsten\game\menus\menuwidget.h
// ========================================================================

void __fastcall idMenuDataSource::~idMenuDataSource(idMenuDataSource *this)
{
  this->__vftable = (idMenuDataSource_vtbl *)&idMenuDataSource::`vftable';
}


// ========================================================================
// ??8idWidgetAction@@QBA_NABV0@@Z
// EA  : 0x82DA2800
// RVA : 0x00DA2800
// PDB : w:\tech5\tungsten\game\menus\menuwidget.h
// ========================================================================

int __fastcall idWidgetAction::operator==(idWidgetAction *this, const idWidgetAction *otherAction)
{
  int num; // r11
  int v5; // r27
  int i; // r31
  idSWFScriptVar *v7; // r3
  idSWFScriptVar *v8; // r30
  int v9; // r26

  if ( this->action == otherAction->action )
  {
    num = this->parms.num;
    if ( num == otherAction->parms.num )
    {
      v5 = 0;
      if ( num <= 0 )
        return 1;
      for ( i = 0; ; ++i )
      {
        v7 = &otherAction->parms.list[i];
        v8 = &this->parms.list[i];
        if ( v8->type != v7->type )
          break;
        v9 = idSWFScriptVar::ToInteger(this: v7);
        if ( idSWFScriptVar::ToInteger(this: v8) != v9 )
          break;
        if ( ++v5 >= this->parms.num )
          return 1;
      }
    }
  }
  return 0;
}


// ========================================================================
// ?Call@WrapWidgetSWFEvent@idMenuWidget@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DD66D8
// RVA : 0x00DD66D8
// PDB : w:\tech5\tungsten\game\menus\menuwidget.h
// ========================================================================

idMenuWidget::WrapWidgetSWFEvent *__fastcall idMenuWidget::WrapWidgetSWFEvent::Call(
        idMenuWidget::WrapWidgetSWFEvent *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  widgetEvent_t i; // r9
  idWidgetEvent v8; // [sp+60h] [-C0h] BYREF

  i = result[1].value.i;
  v8.arg = result[2].type;
  v8.thisObject = thisObject;
  v8.type = i;
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(
    this: &v8.parms.idStaticList<idSWFScriptVar,16>,
    other: parms);
  idMenuWidget::ReceiveEvent(this: (idMenuWidget *)result[1].type, event: &v8);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v8.parms.idStaticList<idSWFScriptVar,16>);
  this->__vftable = (idMenuWidget::WrapWidgetSWFEvent_vtbl *)4;
  return this;
}


// ========================================================================
// __unwind$489014_1
// EA  : 0x82DD6740
// RVA : 0x00DD6740
// PDB : w:\tech5\tungsten\game\menus\menuwidget.h
// ========================================================================

void _unwind_489014_1()
{
  int v0; // r12

  idWidgetEvent::~idWidgetEvent(this: (idWidgetEvent *)(v0 - 288 + 96));
}


// ========================================================================
// ??0idMenuWidget_Button@@QAA@XZ
// EA  : 0x82DD6AB0
// RVA : 0x00DD6AB0
// PDB : w:\tech5\tungsten\game\menus\menuwidget.h
// ========================================================================

idMenuWidget_Button *__fastcall idMenuWidget_Button::idMenuWidget_Button(idMenuWidget_Button *this)
{
  idMenuWidget::idMenuWidget(this);
  this->__vftable = (idMenuWidget_Button_vtbl *)&idMenuWidget_Button::`vftable';
  this->label.data = this->label.baseBuffer;
  this->label.len = 0;
  this->label.allocedAndFlag = 20;
  this->label.baseBuffer[0] = 0;
  this->description.allocedAndFlag = 20;
  this->description.data = this->description.baseBuffer;
  this->description.len = 0;
  this->description.baseBuffer[0] = 0;
  this->optionType = OPTION_BUTTON_TEXT;
  this->animState = ANIM_STATE_UP;
  return this;
}


// ========================================================================
// ?Set@idWidgetAction@@QAAXW4widgetAction_t@@ABVidSWFScriptVar@@@Z
// EA  : 0x82DD6F10
// RVA : 0x00DD6F10
// PDB : w:\tech5\tungsten\game\menus\menuwidget.h
// ========================================================================

void __fastcall idWidgetAction::Set(idWidgetAction *this, widgetAction_t action_, const idSWFScriptVar *var1)
{
  idSWFParmList *p_parms; // r31

  this->action = action_;
  p_parms = &this->parms;
  if ( this->parms.listStatic == 0 || this->parms.listStatic == 2 )
  {
    if ( p_parms->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: this->parms.list, num: this->parms.size);
    p_parms->list = nullptr;
    p_parms->size = 0;
  }
  p_parms->num = 0;
  idSWFParmList::Append(this: p_parms, other: var1);
}


// ========================================================================
// ??0idMenuWidget_CommandBar@@QAA@XZ
// EA  : 0x82DD75B8
// RVA : 0x00DD75B8
// PDB : w:\tech5\tungsten\game\menus\menuwidget.h
// ========================================================================

idMenuWidget_CommandBar *__fastcall idMenuWidget_CommandBar::idMenuWidget_CommandBar(idMenuWidget_CommandBar *this)
{
  int size; // r11

  idMenuWidget::idMenuWidget(this);
  this->__vftable = (idMenuWidget_CommandBar_vtbl *)&idMenuWidget_CommandBar::`vftable';
  idStaticList<idMenuWidget_CommandBar::buttonInfo_t,5>::idStaticList<idMenuWidget_CommandBar::buttonInfo_t,5>(this: &this->buttons);
  this->alignment = LEFT;
  if ( this->buttons.size >= 5
    || (unsigned __int8)idList<idMenuWidget_CommandBar::buttonInfo_t,5>::Resize(this: &this->buttons, newsize: 5) != 0 )
  {
    size = this->buttons.size;
    if ( size > 5 )
      size = 5;
    this->buttons.num = size;
  }
  return this;
}


// ========================================================================
// __unwind$489301
// EA  : 0x82DD763C
// RVA : 0x00DD763C
// PDB : w:\tech5\tungsten\game\menus\menuwidget.h
// ========================================================================

void _unwind_489301()
{
  int v0; // r12

  idMenuWidget::~idMenuWidget(this: *(idMenuWidget **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489302
// EA  : 0x82DD7664
// RVA : 0x00DD7664
// PDB : w:\tech5\tungsten\game\menus\menuwidget.h
// ========================================================================

void _unwind_489302()
{
  int v0; // r12

  idStaticList<idMenuWidget_CommandBar::buttonInfo_t,5>::~idStaticList<idMenuWidget_CommandBar::buttonInfo_t,5>(this: (idStaticList<idMenuWidget_CommandBar::buttonInfo_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 180));
}


// ========================================================================
// ??0idMenuWidget_DevList@@QAA@XZ
// EA  : 0x82DD8C88
// RVA : 0x00DD8C88
// PDB : w:\tech5\tungsten\game\menus\menuwidget.h
// ========================================================================

idMenuWidget_DevList *__fastcall idMenuWidget_DevList::idMenuWidget_DevList(idMenuWidget_DevList *this)
{
  idMenuWidget::idMenuWidget(this);
  this->numVisibleOptions = 0;
  this->viewOffset = 0;
  this->viewIndex = 0;
  this->allowWrapping = false;
  this->devMenuList = nullptr;
  this->__vftable = (idMenuWidget_DevList_vtbl *)&idMenuWidget_DevList::`vftable';
  this->devMapListInfos.list = nullptr;
  this->devMapListInfos.granularity = 0;
  this->devMapListInfos.memTag = 5;
  this->devMapListInfos.listStatic = 0;
  this->devMapListInfos.size = 0;
  this->devMapListInfos.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->devMapListInfos);
  return this;
}


// ========================================================================
// __unwind$488060
// EA  : 0x82DD8D10
// RVA : 0x00DD8D10
// PDB : w:\tech5\tungsten\game\menus\menuwidget.h
// ========================================================================

void _unwind_488060()
{
  int v0; // r12

  idMenuWidget_List::~idMenuWidget_List(this: *(idMenuScreen **)(v0 - 112 + 132));
}

