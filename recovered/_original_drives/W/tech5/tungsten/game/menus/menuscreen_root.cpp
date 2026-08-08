
// ========================================================================
// ?Initialize@idMenuScreen_Root@@UAAXXZ
// EA  : 0x82DD91C0
// RVA : 0x00DD91C0
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void __fastcall idMenuScreen_Root::Initialize(idMenuScreen_Root *this)
{
  idMenuWidget *v2; // r3
  idMenuWidget *v3; // r30
  idMenuWidget *v4; // r28
  idWidgetAction *v5; // r3
  idSWFParmList *p_parms; // r30
  idWidgetAction *v7; // r3
  idSWFParmList *v8; // r30
  idWidgetAction *v9; // r3
  idWidgetAction *v10; // r30
  idSWFScriptVar *list; // r3
  idWidgetAction *v12; // r3
  idWidgetAction *v13; // r30
  idSWFScriptVar *v14; // r3
  idMenuWidget_Help *v15; // r3
  idMenuWidget_Help *v16; // r26
  idMenuWidget_Button *v17; // r3
  idMenuWidget_Button *v18; // r29
  idWidgetAction *v19; // r3
  idSWFParmList *v20; // r30
  idMenuWidget_Button *v21; // r3
  idMenuWidget_Button *v22; // r30
  idMenuWidget_Button *v23; // r3
  idMenuWidget_Button *v24; // r29
  idWidgetAction *v25; // r3
  idWidgetAction *v26; // r30
  idSWFScriptVar *v27; // r3
  idMenuWidget_Button *v28; // r3
  idMenuWidget_Button *v29; // r29
  idWidgetAction *v30; // r3
  idSWFParmList *v31; // r30
  idMenuWidget_Button *v32; // r3
  idMenuWidget_Button *v33; // r30
  idMenuWidget_Button *v34; // r3
  idMenuWidget_Button *v35; // r29
  idWidgetAction *v36; // r3
  idWidgetAction *v37; // r30
  idSWFScriptVar *v38; // r3
  idMenuWidget_CommandBar *v39; // r3
  idMenuWidget *v40; // r29
  idStr *v41; // r30
  idStr *v42; // r30
  idSWFScriptVar *data; // r3
  idStr *p_ExecuteEvent; // r30
  idSWFParmList *p_data; // r30
  int v46; // r11
  idSWFScriptVar v47; // [sp+58h] [-A8h] BYREF
  idSWFScriptVar v48; // [sp+60h] [-A0h] BYREF
  idSWFScriptVar v49; // [sp+68h] [-98h] BYREF
  idSWFScriptVar v50; // [sp+70h] [-90h] BYREF
  idSWFScriptVar v51; // [sp+78h] [-88h] BYREF
  idSWFScriptVar v52; // [sp+80h] [-80h] BYREF
  idSWFScriptVar v53[15]; // [sp+88h] [-78h] BYREF

  idMenuWidget::SetSpritePath(this, arg1: "mainMenu", arg2: nullptr, arg3: nullptr, arg4: nullptr);
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
    v4 = v3;
    v3->__vftable = (idMenuWidget_vtbl *)&idMenuWidget_List::`vftable';
    v3[1].boundSprite = nullptr;
    v3[1].parent = nullptr;
    HIBYTE(v3[1].spritePath.list) = 0;
  }
  else
  {
    v4 = nullptr;
  }
  idMenuWidget::SetSpritePath(
    this: v4,
    spritePath_: &this->spritePath,
    arg1: "options",
    arg2: nullptr,
    arg3: nullptr,
    arg4: nullptr);
  v4[1].__vftable = (idMenuWidget_vtbl *)13;
  HIBYTE(v4[1].spritePath.list) = 1;
  v48.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v48);
  v48.value.i = 1;
  v48.type = SWF_VAR_INTEGER;
  v47.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v47);
  v47.type = SWF_VAR_INTEGER;
  v47.value.i = 2;
  v5 = idMenuWidget::AddEventAction(this: v4, eventType: WIDGET_EVENT_SCROLL_DOWN);
  p_parms = &v5->parms;
  v5->action = WIDGET_ACTION_START_REPEATER;
  if ( v5->parms.listStatic == 0 || v5->parms.listStatic == 2 )
  {
    if ( p_parms->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v5->parms.list, num: v5->parms.size);
    p_parms->list = nullptr;
    p_parms->size = 0;
  }
  p_parms->num = 0;
  idSWFParmList::Append(this: p_parms, other: &v47);
  idSWFParmList::Append(this: p_parms, other: &v48);
  idSWFScriptVar::Free(this: &v47);
  idSWFScriptVar::Free(this: &v48);
  v50.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v50);
  v50.type = SWF_VAR_INTEGER;
  v50.value.i = -1;
  v49.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v49);
  v49.type = SWF_VAR_INTEGER;
  v49.value.i = 2;
  v7 = idMenuWidget::AddEventAction(this: v4, eventType: WIDGET_EVENT_SCROLL_UP);
  v7->action = WIDGET_ACTION_START_REPEATER;
  v8 = &v7->parms;
  if ( v7->parms.listStatic == 0 || v7->parms.listStatic == 2 )
  {
    if ( v8->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v7->parms.list, num: v7->parms.size);
    v8->list = nullptr;
    v8->size = 0;
  }
  v8->num = 0;
  idSWFParmList::Append(this: v8, other: &v49);
  idSWFParmList::Append(this: v8, other: &v50);
  idSWFScriptVar::Free(this: &v49);
  idSWFScriptVar::Free(this: &v50);
  v9 = idMenuWidget::AddEventAction(this: v4, eventType: WIDGET_EVENT_SCROLL_DOWN_RELEASE);
  v9->action = WIDGET_ACTION_STOP_REPEATER;
  v10 = v9;
  if ( v9->parms.listStatic == 0 || v9->parms.listStatic == 2 )
  {
    list = v9->parms.list;
    if ( list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: list, num: v10->parms.size);
    v10->parms.list = nullptr;
    v10->parms.size = 0;
  }
  v10->parms.num = 0;
  v12 = idMenuWidget::AddEventAction(this: v4, eventType: WIDGET_EVENT_SCROLL_UP_RELEASE);
  v12->action = WIDGET_ACTION_STOP_REPEATER;
  v13 = v12;
  if ( v12->parms.listStatic == 0 || v12->parms.listStatic == 2 )
  {
    v14 = v12->parms.list;
    if ( v14 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v14, num: v13->parms.size);
    v13->parms.list = nullptr;
    v13->parms.size = 0;
  }
  v13->parms.num = 0;
  idMenuWidget::AddChild(this, widget: v4);
  v15 = (idMenuWidget_Help *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xF4u,
                               tag: TAG_MENU,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v15 != nullptr )
    v16 = idMenuWidget_Help::idMenuWidget_Help(this: v15);
  else
    v16 = nullptr;
  idMenuWidget::SetSpritePath(
    this: v16,
    spritePath_: &v4->spritePath,
    arg1: "helpTooltip",
    arg2: nullptr,
    arg3: nullptr,
    arg4: nullptr);
  idMenuWidget::AddChild(this, widget: v16);
  v17 = (idMenuWidget_Button *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xFCu,
                                 tag: TAG_MENU,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v17 != nullptr )
    v18 = idMenuWidget_Button::idMenuWidget_Button(this: v17);
  else
    v18 = nullptr;
  idStr::operator=(this: &v18->label, text: "DEV");
  idStr::operator=(this: &v18->description, text: "Launch into a map (Developers Only)");
  v51.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v51);
  v51.type = SWF_VAR_INTEGER;
  v51.value.i = 2;
  v19 = idMenuWidget::AddEventAction(this: v18, eventType: WIDGET_EVENT_PRESS);
  v20 = &v19->parms;
  v19->action = WIDGET_ACTION_GO_BACK;
  if ( v19->parms.listStatic == 0 || v19->parms.listStatic == 2 )
  {
    if ( v20->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v19->parms.list, num: v19->parms.size);
    v20->list = nullptr;
    v20->size = 0;
  }
  v20->num = 0;
  idSWFParmList::Append(this: v20, other: &v51);
  idSWFScriptVar::Free(this: &v51);
  idMenuWidget::RegisterEventObserver(this: v18, observer: v16);
  idMenuWidget::AddChild(this: v4, widget: v18);
  v21 = (idMenuWidget_Button *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xFCu,
                                 tag: TAG_MENU,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v21 != nullptr )
    v22 = idMenuWidget_Button::idMenuWidget_Button(this: v21);
  else
    v22 = nullptr;
  idStr::operator=(this: &v22->label, text: "CAMPAIGN");
  idStr::operator=(this: &v22->description, text: "View the campaign");
  idMenuWidget::RegisterEventObserver(this: v22, observer: v16);
  idMenuWidget::AddChild(this: v4, widget: v22);
  v23 = (idMenuWidget_Button *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xFCu,
                                 tag: TAG_MENU,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v23 != nullptr )
    v24 = idMenuWidget_Button::idMenuWidget_Button(this: v23);
  else
    v24 = nullptr;
  idStr::operator=(this: &v24->label, text: "MULTIPLAYER");
  idStr::operator=(this: &v24->description, text: "Play against your friends");
  v25 = idMenuWidget::AddEventAction(this: v24, eventType: WIDGET_EVENT_PRESS);
  v26 = v25;
  v25->action = WIDGET_ACTION_LAUNCH_MULTIPLAYER;
  if ( v25->parms.listStatic == 0 || v25->parms.listStatic == 2 )
  {
    v27 = v25->parms.list;
    if ( v27 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v27, num: v26->parms.size);
    v26->parms.list = nullptr;
    v26->parms.size = 0;
  }
  v26->parms.num = 0;
  idMenuWidget::RegisterEventObserver(this: v24, observer: v16);
  idMenuWidget::AddChild(this: v4, widget: v24);
  v28 = (idMenuWidget_Button *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xFCu,
                                 tag: TAG_MENU,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v28 != nullptr )
    v29 = idMenuWidget_Button::idMenuWidget_Button(this: v28);
  else
    v29 = nullptr;
  idStr::operator=(this: &v29->label, text: "SETTINGS");
  idStr::operator=(this: &v29->description, text: "Change the game's settings");
  v52.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v52);
  v52.type = SWF_VAR_INTEGER;
  v52.value.i = 5;
  v30 = idMenuWidget::AddEventAction(this: v29, eventType: WIDGET_EVENT_PRESS);
  v31 = &v30->parms;
  v30->action = WIDGET_ACTION_GOTO_MENU;
  if ( v30->parms.listStatic == 0 || v30->parms.listStatic == 2 )
  {
    if ( v31->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v30->parms.list, num: v30->parms.size);
    v31->list = nullptr;
    v31->size = 0;
  }
  v31->num = 0;
  idSWFParmList::Append(this: v31, other: &v52);
  idSWFScriptVar::Free(this: &v52);
  idMenuWidget::RegisterEventObserver(this: v29, observer: v16);
  idMenuWidget::AddChild(this: v4, widget: v29);
  v32 = (idMenuWidget_Button *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xFCu,
                                 tag: TAG_MENU,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v32 != nullptr )
    v33 = idMenuWidget_Button::idMenuWidget_Button(this: v32);
  else
    v33 = nullptr;
  idStr::operator=(this: &v33->label, text: "EXTRAS");
  idStr::operator=(this: &v33->description, text: "Extra stuff!");
  idMenuWidget::RegisterEventObserver(this: v33, observer: v16);
  idMenuWidget::AddChild(this: v4, widget: v33);
  v34 = (idMenuWidget_Button *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xFCu,
                                 tag: TAG_MENU,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v34 != nullptr )
    v35 = idMenuWidget_Button::idMenuWidget_Button(this: v34);
  else
    v35 = nullptr;
  idStr::operator=(this: &v35->label, text: "EXIT");
  idStr::operator=(this: &v35->description, text: "Quit the game and return to your desktop");
  v36 = idMenuWidget::AddEventAction(this: v35, eventType: WIDGET_EVENT_PRESS);
  v37 = v36;
  v36->action = WIDGET_ACTION_EXIT_GAME;
  if ( v36->parms.listStatic == 0 || v36->parms.listStatic == 2 )
  {
    v38 = v36->parms.list;
    if ( v38 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v38, num: v37->parms.size);
    v37->parms.list = nullptr;
    v37->parms.size = 0;
  }
  v37->parms.num = 0;
  idMenuWidget::RegisterEventObserver(this: v35, observer: v16);
  idMenuWidget::AddChild(this: v4, widget: v35);
  v39 = (idMenuWidget_CommandBar *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x460u,
                                     tag: TAG_MENU,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  if ( v39 != nullptr )
    v40 = idMenuWidget_CommandBar::idMenuWidget_CommandBar(this: v39);
  else
    v40 = nullptr;
  v40[6].children.size = 1;
  idMenuWidget::SetSpritePath(this: v40, arg1: "cmdBar", arg2: nullptr, arg3: nullptr, arg4: nullptr);
  v41 = (idStr *)v40[1].__vftable;
  idStr::operator=(this: v41, text: "#STR_SWF_SELECT");
  v42 = v41 + 1;
  v42->len = 6;
  if ( v42->baseBuffer[7] == 0 || v42->baseBuffer[7] == 2 )
  {
    data = (idSWFScriptVar *)v42->data;
    if ( data != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: data, num: *(_DWORD *)v42->baseBuffer);
    v42->data = nullptr;
    *(_DWORD *)v42->baseBuffer = 0;
  }
  v42->allocedAndFlag = 0;
  p_ExecuteEvent = (idStr *)&v40[1].__vftable[7].ExecuteEvent;
  idStr::operator=(this: p_ExecuteEvent, text: "#STR_SWF_BACK");
  v53[0].type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: v53);
  v53[0].type = SWF_VAR_INTEGER;
  v53[0].value.i = 0;
  p_ExecuteEvent[1].len = 8;
  v46 = (unsigned __int8)p_ExecuteEvent[1].baseBuffer[7];
  p_data = (idSWFParmList *)&p_ExecuteEvent[1].data;
  if ( v46 == 0 || v46 == 2 )
  {
    if ( p_data->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: p_data->list, num: p_data->size);
    p_data->list = nullptr;
    p_data->size = 0;
  }
  p_data->num = 0;
  idSWFParmList::Append(this: p_data, other: v53);
  idSWFScriptVar::Free(this: v53);
  idMenuWidget::AddChild(this, widget: v40);
}


// ========================================================================
// __unwind$488769_1
// EA  : 0x82DD9A54
// RVA : 0x00DD9A54
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488769_1()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488770_1
// EA  : 0x82DD9A80
// RVA : 0x00DD9A80
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488770_1()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$488771_1
// EA  : 0x82DD9AA8
// RVA : 0x00DD9AA8
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488771_1()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 88));
}


// ========================================================================
// __unwind$488772_1
// EA  : 0x82DD9AD0
// RVA : 0x00DD9AD0
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488772_1()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$488773_0
// EA  : 0x82DD9AF8
// RVA : 0x00DD9AF8
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488773_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 104));
}


// ========================================================================
// __unwind$488774_1
// EA  : 0x82DD9B20
// RVA : 0x00DD9B20
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488774_1()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488775_0
// EA  : 0x82DD9B4C
// RVA : 0x00DD9B4C
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488775_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488776_0
// EA  : 0x82DD9B78
// RVA : 0x00DD9B78
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488776_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 120));
}


// ========================================================================
// __unwind$488777_0
// EA  : 0x82DD9BA0
// RVA : 0x00DD9BA0
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488777_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488778_0
// EA  : 0x82DD9BCC
// RVA : 0x00DD9BCC
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488778_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488779_0
// EA  : 0x82DD9BF8
// RVA : 0x00DD9BF8
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488779_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488780_0
// EA  : 0x82DD9C24
// RVA : 0x00DD9C24
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488780_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$488781_2
// EA  : 0x82DD9C4C
// RVA : 0x00DD9C4C
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488781_2()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488782_0
// EA  : 0x82DD9C78
// RVA : 0x00DD9C78
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488782_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488783_0
// EA  : 0x82DD9CA4
// RVA : 0x00DD9CA4
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488783_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488784_0
// EA  : 0x82DD9CD0
// RVA : 0x00DD9CD0
// PDB : w:\tech5\tungsten\game\menus\menuscreen_root.cpp
// ========================================================================

void _unwind_488784_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 136));
}

