
// ========================================================================
// ?Initialize@idMenuScreen_Settings@@UAAXXZ
// EA  : 0x82DD9D00
// RVA : 0x00DD9D00
// PDB : w:\tech5\tungsten\game\menus\menuscreen_settings.cpp
// ========================================================================

void __fastcall idMenuScreen_Settings::Initialize(idMenuScreen_Settings *this)
{
  idMenuWidget *v2; // r3
  idMenuWidget *v3; // r29
  idWidgetAction *v4; // r3
  idSWFParmList *p_parms; // r30
  idWidgetAction *v6; // r3
  idSWFParmList *v7; // r30
  idWidgetAction *v8; // r3
  idWidgetAction *v9; // r30
  idSWFScriptVar *list; // r3
  idWidgetAction *v11; // r3
  idWidgetAction *v12; // r30
  idSWFScriptVar *v13; // r3
  idMenuWidget_Help *v14; // r3
  idMenuWidget_Help *v15; // r27
  idMenuWidget_Button *v16; // r3
  idMenuWidget_Button *v17; // r30
  idMenuWidget_Button *v18; // r3
  idMenuWidget_Button *v19; // r28
  idWidgetAction *v20; // r3
  idSWFParmList *v21; // r30
  idMenuWidget_Button *v22; // r3
  idMenuWidget_Button *v23; // r30
  idMenuWidget_Button *v24; // r3
  idMenuWidget_Button *v25; // r30
  idMenuWidget_CommandBar *v26; // r3
  idMenuWidget *v27; // r29
  idStr *v28; // r30
  idStr *v29; // r30
  idSWFScriptVar *data; // r3
  idStr *p_ExecuteEvent; // r30
  idSWFParmList *p_data; // r30
  int v33; // r11
  idSWFScriptVar v34; // [sp+58h] [-98h] BYREF
  idSWFScriptVar v35; // [sp+60h] [-90h] BYREF
  idSWFScriptVar v36; // [sp+68h] [-88h] BYREF
  idSWFScriptVar v37; // [sp+70h] [-80h] BYREF
  idSWFScriptVar v38; // [sp+78h] [-78h] BYREF
  idSWFScriptVar v39[14]; // [sp+80h] [-70h] BYREF

  idMenuWidget::SetSpritePath(this, arg1: "settingsMenu", arg2: nullptr, arg3: nullptr, arg4: nullptr);
  v2 = (idMenuWidget *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xC4u,
                         tag: TAG_MENU,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v3 = v2;
  if ( v2 != nullptr )
  {
    idMenuWidget::idMenuWidget(this: v2);
    v3[1].__vftable = nullptr;
    v3->__vftable = (idMenuWidget_vtbl *)&idMenuWidget_List::`vftable';
    v3[1].boundSprite = nullptr;
    v3[1].parent = nullptr;
    HIBYTE(v3[1].spritePath.list) = 0;
  }
  else
  {
    v3 = nullptr;
  }
  idMenuWidget::SetSpritePath(
    this: v3,
    spritePath_: &this->spritePath,
    arg1: "options",
    arg2: nullptr,
    arg3: nullptr,
    arg4: nullptr);
  v3[1].__vftable = (idMenuWidget_vtbl *)13;
  HIBYTE(v3[1].spritePath.list) = 1;
  v35.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v35);
  v35.value.i = 1;
  v35.type = SWF_VAR_INTEGER;
  v34.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v34);
  v34.type = SWF_VAR_INTEGER;
  v34.value.i = 2;
  v4 = idMenuWidget::AddEventAction(this: v3, eventType: WIDGET_EVENT_SCROLL_DOWN);
  p_parms = &v4->parms;
  v4->action = WIDGET_ACTION_START_REPEATER;
  if ( v4->parms.listStatic == 0 || v4->parms.listStatic == 2 )
  {
    if ( p_parms->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v4->parms.list, num: v4->parms.size);
    p_parms->list = nullptr;
    p_parms->size = 0;
  }
  p_parms->num = 0;
  idSWFParmList::Append(this: p_parms, other: &v34);
  idSWFParmList::Append(this: p_parms, other: &v35);
  idSWFScriptVar::Free(this: &v34);
  idSWFScriptVar::Free(this: &v35);
  v37.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v37);
  v37.type = SWF_VAR_INTEGER;
  v37.value.i = -1;
  v36.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v36);
  v36.type = SWF_VAR_INTEGER;
  v36.value.i = 2;
  v6 = idMenuWidget::AddEventAction(this: v3, eventType: WIDGET_EVENT_SCROLL_UP);
  v6->action = WIDGET_ACTION_START_REPEATER;
  v7 = &v6->parms;
  if ( v6->parms.listStatic == 0 || v6->parms.listStatic == 2 )
  {
    if ( v7->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v6->parms.list, num: v6->parms.size);
    v7->list = nullptr;
    v7->size = 0;
  }
  v7->num = 0;
  idSWFParmList::Append(this: v7, other: &v36);
  idSWFParmList::Append(this: v7, other: &v37);
  idSWFScriptVar::Free(this: &v36);
  idSWFScriptVar::Free(this: &v37);
  v8 = idMenuWidget::AddEventAction(this: v3, eventType: WIDGET_EVENT_SCROLL_DOWN_RELEASE);
  v8->action = WIDGET_ACTION_STOP_REPEATER;
  v9 = v8;
  if ( v8->parms.listStatic == 0 || v8->parms.listStatic == 2 )
  {
    list = v8->parms.list;
    if ( list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: list, num: v9->parms.size);
    v9->parms.list = nullptr;
    v9->parms.size = 0;
  }
  v9->parms.num = 0;
  v11 = idMenuWidget::AddEventAction(this: v3, eventType: WIDGET_EVENT_SCROLL_UP_RELEASE);
  v11->action = WIDGET_ACTION_STOP_REPEATER;
  v12 = v11;
  if ( v11->parms.listStatic == 0 || v11->parms.listStatic == 2 )
  {
    v13 = v11->parms.list;
    if ( v13 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v13, num: v12->parms.size);
    v12->parms.list = nullptr;
    v12->parms.size = 0;
  }
  v12->parms.num = 0;
  idMenuWidget::AddChild(this, widget: v3);
  v14 = (idMenuWidget_Help *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xF4u,
                               tag: TAG_MENU,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v14 != nullptr )
    v15 = idMenuWidget_Help::idMenuWidget_Help(this: v14);
  else
    v15 = nullptr;
  idMenuWidget::SetSpritePath(
    this: v15,
    spritePath_: &v3->spritePath,
    arg1: "helpTooltip",
    arg2: nullptr,
    arg3: nullptr,
    arg4: nullptr);
  idMenuWidget::AddChild(this, widget: v15);
  v16 = (idMenuWidget_Button *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xFCu,
                                 tag: TAG_MENU,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v16 != nullptr )
    v17 = idMenuWidget_Button::idMenuWidget_Button(this: v16);
  else
    v17 = nullptr;
  idStr::operator=(this: &v17->label, text: "VIDEO");
  idStr::operator=(this: &v17->description, text: "Change your video settings");
  idMenuWidget::RegisterEventObserver(this: v17, observer: v15);
  idMenuWidget::AddChild(this: v3, widget: v17);
  v18 = (idMenuWidget_Button *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xFCu,
                                 tag: TAG_MENU,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v18 != nullptr )
    v19 = idMenuWidget_Button::idMenuWidget_Button(this: v18);
  else
    v19 = nullptr;
  idStr::operator=(this: &v19->label, text: "AUDIO");
  idStr::operator=(this: &v19->description, text: "Change your audio settings");
  v38.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v38);
  v38.type = SWF_VAR_INTEGER;
  v38.value.i = 6;
  v20 = idMenuWidget::AddEventAction(this: v19, eventType: WIDGET_EVENT_PRESS);
  v21 = &v20->parms;
  v20->action = WIDGET_ACTION_GOTO_MENU;
  if ( v20->parms.listStatic == 0 || v20->parms.listStatic == 2 )
  {
    if ( v21->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v20->parms.list, num: v20->parms.size);
    v21->list = nullptr;
    v21->size = 0;
  }
  v21->num = 0;
  idSWFParmList::Append(this: v21, other: &v38);
  idSWFScriptVar::Free(this: &v38);
  idMenuWidget::RegisterEventObserver(this: v19, observer: v15);
  idMenuWidget::AddChild(this: v3, widget: v19);
  v22 = (idMenuWidget_Button *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xFCu,
                                 tag: TAG_MENU,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v22 != nullptr )
    v23 = idMenuWidget_Button::idMenuWidget_Button(this: v22);
  else
    v23 = nullptr;
  idStr::operator=(this: &v23->label, text: "KEYBOARD / MOUSE");
  idStr::operator=(this: &v23->description, text: "Change your keyboard and mouse settings");
  idMenuWidget::RegisterEventObserver(this: v23, observer: v15);
  idMenuWidget::AddChild(this: v3, widget: v23);
  v24 = (idMenuWidget_Button *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xFCu,
                                 tag: TAG_MENU,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v24 != nullptr )
    v25 = idMenuWidget_Button::idMenuWidget_Button(this: v24);
  else
    v25 = nullptr;
  idStr::operator=(this: &v25->label, text: "GAMEPAD");
  idStr::operator=(this: &v25->description, text: "Change your gamepad settings");
  idMenuWidget::RegisterEventObserver(this: v25, observer: v15);
  idMenuWidget::AddChild(this: v3, widget: v25);
  v26 = (idMenuWidget_CommandBar *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x460u,
                                     tag: TAG_MENU,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  if ( v26 != nullptr )
    v27 = idMenuWidget_CommandBar::idMenuWidget_CommandBar(this: v26);
  else
    v27 = nullptr;
  v27[6].children.size = 1;
  idMenuWidget::SetSpritePath(this: v27, arg1: "cmdBar", arg2: nullptr, arg3: nullptr, arg4: nullptr);
  v28 = (idStr *)v27[1].__vftable;
  idStr::operator=(this: v28, text: "#STR_SWF_SELECT");
  v29 = v28 + 1;
  v29->len = 6;
  if ( v29->baseBuffer[7] == 0 || v29->baseBuffer[7] == 2 )
  {
    data = (idSWFScriptVar *)v29->data;
    if ( data != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: data, num: *(_DWORD *)v29->baseBuffer);
    v29->data = nullptr;
    *(_DWORD *)v29->baseBuffer = 0;
  }
  v29->allocedAndFlag = 0;
  p_ExecuteEvent = (idStr *)&v27[1].__vftable[7].ExecuteEvent;
  idStr::operator=(this: p_ExecuteEvent, text: "#STR_SWF_BACK");
  v39[0].type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: v39);
  v39[0].type = SWF_VAR_INTEGER;
  v39[0].value.i = 1;
  p_ExecuteEvent[1].len = 8;
  v33 = (unsigned __int8)p_ExecuteEvent[1].baseBuffer[7];
  p_data = (idSWFParmList *)&p_ExecuteEvent[1].data;
  if ( v33 == 0 || v33 == 2 )
  {
    if ( p_data->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: p_data->list, num: p_data->size);
    p_data->list = nullptr;
    p_data->size = 0;
  }
  p_data->num = 0;
  idSWFParmList::Append(this: p_data, other: v39);
  idSWFScriptVar::Free(this: v39);
  idMenuWidget::AddChild(this, widget: v27);
}


// ========================================================================
// __unwind$488741
// EA  : 0x82DDA39C
// RVA : 0x00DDA39C
// PDB : w:\tech5\tungsten\game\menus\menuscreen_settings.cpp
// ========================================================================

void _unwind_488741()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 240 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488742_0
// EA  : 0x82DDA3C8
// RVA : 0x00DDA3C8
// PDB : w:\tech5\tungsten\game\menus\menuscreen_settings.cpp
// ========================================================================

void _unwind_488742_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$488743
// EA  : 0x82DDA3F0
// RVA : 0x00DDA3F0
// PDB : w:\tech5\tungsten\game\menus\menuscreen_settings.cpp
// ========================================================================

void _unwind_488743()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 88));
}


// ========================================================================
// __unwind$488744
// EA  : 0x82DDA418
// RVA : 0x00DDA418
// PDB : w:\tech5\tungsten\game\menus\menuscreen_settings.cpp
// ========================================================================

void _unwind_488744()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$488745
// EA  : 0x82DDA440
// RVA : 0x00DDA440
// PDB : w:\tech5\tungsten\game\menus\menuscreen_settings.cpp
// ========================================================================

void _unwind_488745()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 104));
}


// ========================================================================
// __unwind$488746
// EA  : 0x82DDA468
// RVA : 0x00DDA468
// PDB : w:\tech5\tungsten\game\menus\menuscreen_settings.cpp
// ========================================================================

void _unwind_488746()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 240 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488747
// EA  : 0x82DDA494
// RVA : 0x00DDA494
// PDB : w:\tech5\tungsten\game\menus\menuscreen_settings.cpp
// ========================================================================

void _unwind_488747()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 240 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488748
// EA  : 0x82DDA4C0
// RVA : 0x00DDA4C0
// PDB : w:\tech5\tungsten\game\menus\menuscreen_settings.cpp
// ========================================================================

void _unwind_488748()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 240 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488749
// EA  : 0x82DDA4EC
// RVA : 0x00DDA4EC
// PDB : w:\tech5\tungsten\game\menus\menuscreen_settings.cpp
// ========================================================================

void _unwind_488749()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 120));
}


// ========================================================================
// __unwind$488750
// EA  : 0x82DDA514
// RVA : 0x00DDA514
// PDB : w:\tech5\tungsten\game\menus\menuscreen_settings.cpp
// ========================================================================

void _unwind_488750()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 240 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488751
// EA  : 0x82DDA540
// RVA : 0x00DDA540
// PDB : w:\tech5\tungsten\game\menus\menuscreen_settings.cpp
// ========================================================================

void _unwind_488751()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 240 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488752
// EA  : 0x82DDA56C
// RVA : 0x00DDA56C
// PDB : w:\tech5\tungsten\game\menus\menuscreen_settings.cpp
// ========================================================================

void _unwind_488752()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 240 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488753
// EA  : 0x82DDA598
// RVA : 0x00DDA598
// PDB : w:\tech5\tungsten\game\menus\menuscreen_settings.cpp
// ========================================================================

void _unwind_488753()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 128));
}

