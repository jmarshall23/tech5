
// ========================================================================
// ?GetTotalNumberOfOptions@idMenuWidget_DevList@@UBAHXZ
// EA  : 0x82DDD658
// RVA : 0x00DDD658
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

int __fastcall idMenuWidget_DevList::GetTotalNumberOfOptions(idMenuWidget_DevList *this)
{
  const idDeclDevMenuList *devMenuList; // r11
  int result; // r3

  devMenuList = this->devMenuList;
  result = 0;
  if ( devMenuList != nullptr )
    return devMenuList->devMenuList.num;
  return result;
}


// ========================================================================
// ?Initialize@idMenuWidget_DevList@@UAAXXZ
// EA  : 0x82DDD7C0
// RVA : 0x00DDD7C0
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

void __fastcall idMenuWidget_DevList::Initialize(idMenuWidget_DevList *this)
{
  idWidgetAction *v2; // r3
  idSWFParmList *p_parms; // r30
  idWidgetAction *v4; // r3
  idSWFParmList *v5; // r30
  idWidgetAction *v6; // r3
  idWidgetAction *v7; // r30
  idSWFScriptVar *list; // r3
  idWidgetAction *v9; // r3
  idWidgetAction *v10; // r30
  idSWFScriptVar *v11; // r3
  idSWFScriptFunction_vtbl *v12; // r25
  idMenuWidget *v13; // r3
  idMenuWidget *v14; // r30
  idMenuWidget *v15; // r28
  idSWFScriptFunction *v16; // r3
  idSWFScriptFunction *v17; // r30
  idWidgetAction *v18; // r3
  int v19; // r10
  int v20; // r9
  int v21; // r8
  int v22; // r7
  int v23; // r6
  int v24; // r5
  int v25; // [sp+8h] [-D8h]
  int v26; // [sp+Ch] [-D4h]
  int v27; // [sp+10h] [-D0h]
  int v28; // [sp+14h] [-CCh]
  int v29; // [sp+18h] [-C8h]
  idMenuWidget *v30; // [sp+1Ch] [-C4h]
  idSWFScriptVar v31; // [sp+58h] [-88h] BYREF
  idSWFScriptVar v32; // [sp+60h] [-80h] BYREF
  idSWFScriptVar v33; // [sp+68h] [-78h] BYREF
  idSWFScriptVar v34[14]; // [sp+70h] [-70h] BYREF

  v32.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v32);
  v32.type = SWF_VAR_INTEGER;
  v32.value.i = 1;
  v31.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v31);
  v31.type = SWF_VAR_INTEGER;
  v31.value.i = 2;
  v2 = idMenuWidget::AddEventAction(this, eventType: WIDGET_EVENT_SCROLL_DOWN);
  v2->action = WIDGET_ACTION_START_REPEATER;
  p_parms = &v2->parms;
  if ( v2->parms.listStatic == 0 || v2->parms.listStatic == 2 )
  {
    if ( p_parms->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v2->parms.list, num: v2->parms.size);
    p_parms->list = nullptr;
    p_parms->size = 0;
  }
  p_parms->num = 0;
  idSWFParmList::Append(this: p_parms, other: &v31);
  idSWFParmList::Append(this: p_parms, other: &v32);
  idSWFScriptVar::Free(this: &v31);
  idSWFScriptVar::Free(this: &v32);
  v34[0].type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: v34);
  v34[0].type = SWF_VAR_INTEGER;
  v34[0].value.i = -1;
  v33.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v33);
  v33.type = SWF_VAR_INTEGER;
  v33.value.i = 2;
  v4 = idMenuWidget::AddEventAction(this, eventType: WIDGET_EVENT_SCROLL_UP);
  v4->action = WIDGET_ACTION_START_REPEATER;
  v5 = &v4->parms;
  if ( v4->parms.listStatic == 0 || v4->parms.listStatic == 2 )
  {
    if ( v5->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v4->parms.list, num: v4->parms.size);
    v5->list = nullptr;
    v5->size = 0;
  }
  v5->num = 0;
  idSWFParmList::Append(this: v5, other: &v33);
  idSWFParmList::Append(this: v5, other: v34);
  idSWFScriptVar::Free(this: &v33);
  idSWFScriptVar::Free(this: v34);
  v6 = idMenuWidget::AddEventAction(this, eventType: WIDGET_EVENT_SCROLL_DOWN_RELEASE);
  v6->action = WIDGET_ACTION_STOP_REPEATER;
  v7 = v6;
  if ( v6->parms.listStatic == 0 || v6->parms.listStatic == 2 )
  {
    list = v6->parms.list;
    if ( list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: list, num: v7->parms.size);
    v7->parms.list = nullptr;
    v7->parms.size = 0;
  }
  v7->parms.num = 0;
  v9 = idMenuWidget::AddEventAction(this, eventType: WIDGET_EVENT_SCROLL_UP_RELEASE);
  v9->action = WIDGET_ACTION_STOP_REPEATER;
  v10 = v9;
  if ( v9->parms.listStatic == 0 || v9->parms.listStatic == 2 )
  {
    v11 = v9->parms.list;
    if ( v11 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v11, num: v10->parms.size);
    v10->parms.list = nullptr;
    v10->parms.size = 0;
  }
  v10->parms.num = 0;
  v12 = nullptr;
  while ( this->children.num < this->numVisibleOptions )
  {
    v13 = (idMenuWidget *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0xFCu,
                            tag: TAG_MENU,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
    v14 = v13;
    if ( v13 != nullptr )
    {
      idMenuWidget::idMenuWidget(this: v13);
      v14->__vftable = (idMenuWidget_vtbl *)&idMenuWidget_Button::`vftable';
      v14[1].parent = (idMenuWidget *)20;
      v14[1].__vftable = nullptr;
      v15 = v14;
      v14[1].boundSprite = (idSWFSpriteInstance *)&v14[1].spritePath;
      HIBYTE(v14[1].spritePath.list) = 0;
      *(_DWORD *)&v14[1].children.granularity = 20;
      v14[1].children.size = (int)&v14[1].observers;
      v14[1].children.num = 0;
      HIBYTE(v14[1].observers.list) = 0;
      v14[1].eventActions.num = 0;
      v14[1].eventActions.size = 0;
    }
    else
    {
      v15 = nullptr;
    }
    v16 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x10u,
                                   tag: TAG_SWF,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
    if ( v16 != nullptr )
    {
      v16[3].__vftable = v12;
      v17 = v16;
      v16[2].__vftable = (idSWFScriptFunction_vtbl *)this;
      v12 = (idSWFScriptFunction_vtbl *)((char *)v12 + 1);
      v16[1].__vftable = nullptr;
      v16->__vftable = (idSWFScriptFunction_vtbl *)&`anonymous namespace'::DevList_NavigateForward::`vftable';
    }
    else
    {
      v17 = nullptr;
    }
    v18 = idMenuWidget::AddEventAction(this: v15, eventType: WIDGET_EVENT_PRESS);
    v18->action = WIDGET_ACTION_FUNCTION;
    v18->scriptFunction = v17;
    idMenuWidget::AddChild(
      this,
      widget: v15,
      a3: v24,
      a4: v23,
      a5: v22,
      a6: v21,
      a7: v20,
      a8: v19,
      a9: v25,
      a10: v26,
      a11: v27,
      a12: v28,
      a13: v29,
      a14: v30);
  }
}


// ========================================================================
// __unwind$488398
// EA  : 0x82DDDAE8
// RVA : 0x00DDDAE8
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

void _unwind_488398()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$488399_0
// EA  : 0x82DDDB10
// RVA : 0x00DDDB10
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

void _unwind_488399_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 224 + 88));
}


// ========================================================================
// __unwind$488400_0
// EA  : 0x82DDDB38
// RVA : 0x00DDDB38
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

void _unwind_488400_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 224 + 112));
}


// ========================================================================
// __unwind$488401_0
// EA  : 0x82DDDB60
// RVA : 0x00DDDB60
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

void _unwind_488401_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 224 + 104));
}


// ========================================================================
// __unwind$488402
// EA  : 0x82DDDB88
// RVA : 0x00DDDB88
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

void _unwind_488402()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 224 + 80), tag: TAG_MENU);
}


// ========================================================================
// ?RecalculateDevMenu@idMenuWidget_DevList@@QAAXXZ
// EA  : 0x82DDDBC0
// RVA : 0x00DDDBC0
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

void __fastcall idMenuWidget_DevList::RecalculateDevMenu(idMenuWidget_DevList *this)
{
  const idDeclDevMenuList *v2; // r3
  __int64 v3; // r10
  int v4; // r28
  __int64 v5; // r8
  __int64 v6; // r6
  idSWFScriptObject *v7; // r24
  int v8; // r27
  idMenuWidget *v9; // r30
  va *v10; // r3
  idSWFSpriteInstance *boundSprite; // r30
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  int v15; // [sp+8h] [-1138h]
  int v16; // [sp+Ch] [-1134h]
  int v17; // [sp+10h] [-1130h]
  int v18; // [sp+14h] [-112Ch]
  int v19; // [sp+18h] [-1128h]
  int v20; // [sp+1Ch] [-1124h]
  int num; // [sp+50h] [-10F0h]
  idStaticList<idSWFScriptVar,16> v22; // [sp+60h] [-10E0h] BYREF
  va v23; // [sp+F0h] [-1050h] BYREF

  num = this->devMapListInfos.num;
  if ( num > 0 )
  {
    v2 = (const idDeclDevMenuList *)idResourceList::Load(
                                      this: &idDeclDevMenuList::resourceList,
                                      name: (char *)this->devMapListInfos.list[num - 1].name,
                                      makeDefault: false,
                                      skipStaleCheck: false);
    if ( v2 != nullptr )
      this->devMenuList = v2;
  }
  LODWORD(v3) = this->children.num;
  HIDWORD(v3) = 1376256;
  v4 = 0;
  LODWORD(v5) = 1391488;
  HIDWORD(v5) = gameLocal->mainMenu;
  LODWORD(v6) = *(_DWORD *)(HIDWORD(v5) + 668);
  v7 = *(idSWFScriptObject **)(*(_DWORD *)(v6 + 64) + 40);
  if ( (int)v3 > 0 )
  {
    v8 = 0;
    do
    {
      HIDWORD(v6) = v4;
      v9 = this->children.list[v8];
      v10 = va::va(
              this: &v23,
              fmt: "option%d",
              a3: v6,
              a4: v5,
              a5: v3,
              a6: v15,
              a7: v16,
              a8: v17,
              a9: v18,
              a10: v19,
              a11: v20);
      idMenuWidget::SetSpritePath(
        this: v9,
        spritePath_: &this->spritePath,
        arg1: v10->buffer,
        arg2: nullptr,
        arg3: nullptr,
        arg4: nullptr);
      LODWORD(v3) = idMenuWidget::BindSprite(this: v9, root: v7);
      if ( (_DWORD)v3 != 0 )
      {
        idMenuWidget::SetState(this: v9, state: WIDGET_STATE_NORMAL);
        boundSprite = v9->boundSprite;
        idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v22);
        idSWFParmList::Append(this: (idSWFParmList *)&v22, i: (idSWFScriptVar::swfScriptVarValue_t *)1);
        idSWFSpriteInstance::StopFrame(this: boundSprite, parms: (const idSWFParmList *)&v22, a3: v14, a4: v13, a5: v12);
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v22);
      }
      ++v4;
      ++v8;
    }
    while ( v4 < this->children.num );
  }
}


// ========================================================================
// __unwind$488908
// EA  : 0x82DDDD00
// RVA : 0x00DDDD00
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

void _unwind_488908()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 4416 + 96));
}


// ========================================================================
// ?GoToFirstMenu@idMenuWidget_DevList@@QAAXXZ
// EA  : 0x82DDDD28
// RVA : 0x00DDDD28
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

void __fastcall idMenuWidget_DevList::GoToFirstMenu(idMenuWidget_DevList *this)
{
  idList<idGameLocal::delayedUse_t,5> *p_devMapListInfos; // r30

  p_devMapListInfos = (idList<idGameLocal::delayedUse_t,5> *)&this->devMapListInfos;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->devMapListInfos);
  idList<idGameLocal::delayedUse_t,5>::Alloc(this: p_devMapListInfos)->activator.value = (int)"devmenuoption/main";
  this->devMenuList = nullptr;
  idMenuWidget_DevList::RecalculateDevMenu(this);
}


// ========================================================================
// ?NavigateForward@idMenuWidget_DevList@@QAAXH@Z
// EA  : 0x82DDDD88
// RVA : 0x00DDDD88
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

void __fastcall idMenuWidget_DevList::NavigateForward(idMenuWidget_DevList *this, const int optionIndex)
{
  const idDeclDevMenuList *devMenuList; // r11
  int v4; // r29
  int v5; // r30
  __int64 v6; // r8
  idGameLocal::delayedUse_t *v7; // r3
  idMenuWidget_DevList_vtbl *v8; // r5
  __int64 v9; // r10
  __int64 v10; // r6
  va *v11; // r3
  int v12; // [sp+8h] [-1068h]
  int v13; // [sp+Ch] [-1064h]
  int v14; // [sp+10h] [-1060h]
  int v15; // [sp+14h] [-105Ch]
  int v16; // [sp+18h] [-1058h]
  int v17; // [sp+1Ch] [-1054h]
  va v18; // [sp+50h] [-1020h] BYREF

  devMenuList = this->devMenuList;
  if ( devMenuList != nullptr )
  {
    v4 = optionIndex + this->viewOffset;
    v5 = (int)&devMenuList->devMenuList.list[v4];
    if ( *(_DWORD *)v5 != 0 && idStr::Cmp(s1: *(const char **)(v5 + 4), s2: "...") != 0 )
    {
      if ( *(_DWORD *)(v5 + 32) != 0 )
      {
        v7 = idList<idGameLocal::delayedUse_t,5>::Alloc(this: (idList<idGameLocal::delayedUse_t,5> *)&this->devMapListInfos);
        v7->activator.value = *(_DWORD *)(*(_DWORD *)(v5 + 32) + 8);
        v7->usable.value = this->focusIndex;
        v7->usableState = this->viewIndex;
        v7->addedFrame = this->viewOffset;
        idMenuWidget_DevList::RecalculateDevMenu(this);
        v8 = this->__vftable;
        this->viewIndex = 0;
        this->viewOffset = 0;
        v8->Update(this);
        idMenuWidget::SetState(this: *this->children.list, state: WIDGET_STATE_SELECTED);
        this->focusIndex = 0;
        idMenuWidget::SetFocusIndex(this, index: 0);
        idMainMenu::ClearWidgetActionRepeater(this: gameLocal->mainMenu);
      }
      else
      {
        HIDWORD(v9) = "ame: %s\n";
        LODWORD(v10) = v4;
        LODWORD(v9) = &this->devMapListInfos.list[this->devMapListInfos.num - 1];
        HIDWORD(v10) = *(_DWORD *)v9;
        v11 = va::va(
                this: &v18,
                fmt: "loadDevMenuOption %s %d\n",
                a3: v10,
                a4: v6,
                a5: v9,
                a6: v12,
                a7: v13,
                a8: v14,
                a9: v15,
                a10: v16,
                a11: v17);
        cmdSystem->AppendCommandText(this: cmdSystem, a2: v11->buffer);
      }
    }
  }
}


// ========================================================================
// ?NavigateBack@idMenuWidget_DevList@@QAAXXZ
// EA  : 0x82DDDEE0
// RVA : 0x00DDDEE0
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

void __fastcall idMenuWidget_DevList::NavigateBack(idMenuWidget_DevList *this)
{
  idMenuWidget_DevList::indexInfo_t *v2; // r10
  const char *name; // r6
  int focusIndex; // r5
  int viewIndex; // r11
  int viewOffset; // r10
  int v7; // r8
  idMenuWidget_DevList_vtbl *v8; // r7
  int v9; // r29
  idSWFScriptVar v10[2]; // [sp+50h] [-210h] BYREF
  const char *v11; // [sp+60h] [-200h]
  int v12; // [sp+64h] [-1FCh]
  int v13; // [sp+68h] [-1F8h]
  int v14; // [sp+6Ch] [-1F4h]
  idWidgetAction v15; // [sp+70h] [-1F0h] BYREF
  _DWORD v16[3]; // [sp+110h] [-150h] BYREF
  idStaticList<idSWFScriptVar,16> v17; // [sp+11Ch] [-144h] BYREF
  idStaticList<idSWFScriptVar,16> v18; // [sp+1B0h] [-B0h] BYREF

  v10[0].type = this->devMapListInfos.num;
  if ( v10[0].type == SWF_VAR_STRING )
  {
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v18);
    v16[1] = 0;
    v16[0] = 16;
    v16[2] = 0;
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v17, other: &v18);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v18);
    v15.action = WIDGET_ACTION_NONE;
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v15.parms.idStaticList<idSWFScriptVar,16>);
    v15.scriptFunction = nullptr;
    v10[0].type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: v10);
    v10[0].type = SWF_VAR_INTEGER;
    v10[0].value.i = 1;
    v15.action = WIDGET_ACTION_GO_BACK;
    if ( v15.parms.listStatic == 0 || v15.parms.listStatic == 2 )
    {
      if ( v15.parms.list != nullptr )
        idListArrayDelete<idSWFScriptVar>(ptr: v15.parms.list, num: v15.parms.size);
      v15.parms.list = nullptr;
      v15.parms.size = 0;
    }
    v15.parms.num = 0;
    idSWFParmList::Append(this: &v15.parms, other: v10);
    idSWFScriptVar::Free(this: v10);
    this->HandleAction(this, a2: &v15, a3: (const idWidgetEvent *)v16);
    idWidgetAction::~idWidgetAction(this: &v15);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v17);
  }
  else
  {
    v2 = &this->devMapListInfos.list[v10[0].type];
    name = v2[-1].name;
    focusIndex = v2[-1].focusIndex;
    viewIndex = v2[-1].viewIndex;
    viewOffset = v2[-1].viewOffset;
    v11 = name;
    v12 = focusIndex;
    v13 = viewIndex;
    v14 = viewOffset;
    idList<idMenuWidget_DevList::indexInfo_t,5>::RemoveIndex(
      this: (idList<parmValue_t,56> *)&this->devMapListInfos,
      index: v10[0].type - 1);
    idMenuWidget_DevList::RecalculateDevMenu(this);
    v7 = v14;
    v8 = this->__vftable;
    this->viewIndex = v13;
    this->viewOffset = v7;
    v8->Update(this);
    v9 = v12;
    idMenuWidget::SetState(this: this->children.list[v12], state: WIDGET_STATE_SELECTED);
    this->focusIndex = v12;
    idMenuWidget::SetFocusIndex(this, index: v9);
    idMainMenu::ClearWidgetActionRepeater(this: gameLocal->mainMenu);
  }
}


// ========================================================================
// __unwind$489041
// EA  : 0x82DDE09C
// RVA : 0x00DDE09C
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

void _unwind_489041()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 608 + 432));
}


// ========================================================================
// __unwind$489042
// EA  : 0x82DDE0C4
// RVA : 0x00DDE0C4
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

void _unwind_489042()
{
  int v0; // r12

  idWidgetEvent::~idWidgetEvent(this: (idWidgetEvent *)(v0 - 608 + 272));
}


// ========================================================================
// __unwind$489043
// EA  : 0x82DDE0EC
// RVA : 0x00DDE0EC
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

void _unwind_489043()
{
  int v0; // r12

  idWidgetAction::~idWidgetAction(this: (idWidgetAction *)(v0 - 608 + 112));
}


// ========================================================================
// __unwind$489044
// EA  : 0x82DDE114
// RVA : 0x00DDE114
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

void _unwind_489044()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 608 + 80));
}


// ========================================================================
// ?Call@DevList_NavigateForward@?A0xdfbe4ea7@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DDE140
// RVA : 0x00DDE140
// PDB : w:\tech5\tungsten\game\menus\menuwidget_devlist.cpp
// ========================================================================

DevList_NavigateForward *__fastcall `anonymous namespace'::DevList_NavigateForward::Call(
        DevList_NavigateForward *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMenuWidget_DevList::NavigateForward(this: (idMenuWidget_DevList *)result[1].type, optionIndex: result[1].value.i);
  this->__vftable = (idSWFScriptFunction_RefCounted_vtbl *)4;
  return this;
}

