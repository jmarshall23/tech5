
// ========================================================================
// ?SetDataSource@idMenuWidget@@QAAXPAVidMenuDataSource@@H@Z
// EA  : 0x82DDA948
// RVA : 0x00DDA948
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void __fastcall idMenuWidget::SetDataSource(idMenuWidget *this, idMenuDataSource *dataSource_, int fieldIndex)
{
  this->dataSource = dataSource_;
  this->dataSourceFieldIndex = fieldIndex;
}


// ========================================================================
// ?SendEventToObservers@idMenuWidget@@QAAXABVidWidgetEvent@@@Z
// EA  : 0x82DDA958
// RVA : 0x00DDA958
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void __fastcall idMenuWidget::SendEventToObservers(idMenuWidget *this, const idWidgetEvent *event)
{
  int v4; // r30
  int v5; // r29

  v4 = 0;
  if ( this->observers.num > 0 )
  {
    v5 = 0;
    do
    {
      this->observers.list[v5]->ObserveEvent(this: this->observers.list[v5], a2: this, a3: event);
      ++v4;
      ++v5;
    }
    while ( v4 < this->observers.num );
  }
}


// ========================================================================
// ?BindSprite@idMenuWidget@@QAA_NAAVidSWFScriptObject@@@Z
// EA  : 0x82DDA9C0
// RVA : 0x00DDA9C0
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

BOOL __fastcall idMenuWidget::BindSprite(idMenuWidget *this, idSWFScriptObject *root)
{
  int num; // r8
  int v3; // r11
  int v5; // r10
  idStr *list; // r7
  char *v7; // r8
  int v8; // r6
  idStr *v9; // r9
  char *data; // r5
  idSWFSpriteInstance *NestedSprite; // r3
  char v13; // [sp+4Ch] [-34h] BYREF
  const char *v14; // [sp+50h] [-30h]
  const char *v15; // [sp+54h] [-2Ch]
  const char *v16; // [sp+58h] [-28h]
  const char *v17; // [sp+5Ch] [-24h]
  const char *v18; // [sp+60h] [-20h]
  const char *v19; // [sp+64h] [-1Ch]

  num = this->spritePath.num;
  v3 = 0;
  v14 = nullptr;
  v5 = 0;
  v15 = nullptr;
  v16 = nullptr;
  v17 = nullptr;
  v18 = nullptr;
  v19 = nullptr;
  if ( num > 0 )
  {
    list = this->spritePath.list;
    v7 = &v13;
    v8 = this->spritePath.num;
    v9 = list;
    do
    {
      data = v9->data;
      ++v5;
      v9 = &list[++v3];
      v7 += 4;
      *(_DWORD *)v7 = data;
    }
    while ( v5 < v8 );
  }
  NestedSprite = idSWFScriptObject::GetNestedSprite(
                   this: root,
                   arg1: v14,
                   arg2: v15,
                   arg3: v16,
                   arg4: v17,
                   arg5: v18,
                   arg6: v19);
  this->boundSprite = NestedSprite;
  return NestedSprite != nullptr;
}


// ========================================================================
// ?RemoveChild@idMenuWidget@@QAAXPAV1@@Z
// EA  : 0x82DDAA70
// RVA : 0x00DDAA70
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void __fastcall idMenuWidget::RemoveChild(idMenuWidget *this, idMenuWidget *widget)
{
  idList<idEntityPtr<idEntity>,58> *p_children; // r3
  int v4; // r4
  int num; // r10
  int v6; // r11

  p_children = (idList<idEntityPtr<idEntity>,58> *)&this->children;
  v4 = 0;
  num = p_children->num;
  if ( num > 0 )
  {
    v6 = 0;
    while ( (idMenuWidget *)p_children->list[v6].spawnId.value != widget )
    {
      ++v4;
      ++v6;
      if ( v4 >= num )
        goto LABEL_8;
    }
    if ( v4 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_children, index: v4);
  }
LABEL_8:
  widget->parent = nullptr;
}


// ========================================================================
// ?ExecuteEvent@idMenuWidget@@UAA_NABVidWidgetEvent@@@Z
// EA  : 0x82DDAAF0
// RVA : 0x00DDAAF0
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

int __fastcall idMenuWidget::ExecuteEvent(idMenuWidget *this, const idWidgetEvent *event)
{
  int v4; // r11
  idList<idWidgetAction,5> *v5; // r31
  int v6; // r29
  int v7; // r30
  unsigned __int8 v8; // r11

  v4 = this->eventActionLookup.list[event->type];
  if ( v4 == -1 )
  {
    v5 = nullptr;
  }
  else
  {
    v5 = &this->eventActions.list[v4];
    if ( v5 != nullptr )
    {
      v6 = 0;
      if ( v5->num > 0 )
      {
        v7 = 0;
        do
        {
          this->HandleAction(this, a2: &v5->list[v7], a3: event);
          ++v6;
          ++v7;
        }
        while ( v6 < v5->num );
      }
    }
  }
  idMenuWidget::SendEventToObservers(this, event);
  if ( v5 == nullptr )
    return 0;
  v8 = 1;
  if ( v5->num <= 0 )
    return 0;
  return v8;
}


// ========================================================================
// ?AddChild@idMenuWidget@@QAAXPAV1@@Z
// EA  : 0x82DDABB0
// RVA : 0x00DDABB0
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void __fastcall idMenuWidget::AddChild(
        idMenuWidget *this,
        idMenuWidget *widget,
        int a3,
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
        idMenuWidget *a14)
{
  int num; // r9
  idList<enum encounterGroupRole_t,5> *p_children; // r30
  int v18; // r10
  encounterGroupRole_t *list; // r8
  int v20; // r11
  idMenuWidget *parent; // r3

  num = this->children.num;
  a14 = widget;
  p_children = (idList<enum encounterGroupRole_t,5> *)&this->children;
  v18 = 0;
  if ( num <= 0 )
    goto LABEL_8;
  list = p_children->list;
  v20 = 0;
  while ( (idMenuWidget *)list[v20] != widget )
  {
    ++v18;
    ++v20;
    if ( v18 >= num )
      goto LABEL_8;
  }
  if ( v18 < 0 || &list[v18] == nullptr )
  {
LABEL_8:
    parent = widget->parent;
    if ( parent != nullptr )
      idMenuWidget::RemoveChild(this: parent, widget);
    widget->parent = this;
    idList<idAnimWebBlendTree *,5>::Append(this: p_children, obj: (encounterGroupRole_t *)&a14);
  }
}


// ========================================================================
// ?ReceiveEvent@idMenuWidget@@QAAXABVidWidgetEvent@@@Z
// EA  : 0x82DDAC50
// RVA : 0x00DDAC50
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void __fastcall idMenuWidget::ReceiveEvent(idMenuWidget *this, const idWidgetEvent *event)
{
  int v3; // r29
  encounterGroupRole_t *list; // r4
  idMenuWidget *v5; // r30
  int focusIndex; // r11
  int v7; // r29
  int v8; // r30
  idMenuWidget *v9; // [sp+50h] [-90h] BYREF
  idList<enum encounterGroupRole_t,5> v10; // [sp+60h] [-80h] BYREF
  _BYTE v11[112]; // [sp+70h] [-70h] BYREF

  v3 = 16;
  *(_QWORD *)&v10.num = 16;
  list = (encounterGroupRole_t *)v11;
  v10.list = (encounterGroupRole_t *)v11;
  *(_DWORD *)&v10.granularity = 66817;
  v5 = this;
  v9 = this;
  if ( this != nullptr )
  {
    do
    {
      if ( --v3 == 0 )
        break;
      idList<idAnimWebBlendTree *,5>::Append(this: &v10, obj: (encounterGroupRole_t *)&v9);
      focusIndex = v5->focusIndex;
      if ( focusIndex < 0 )
        break;
      if ( focusIndex >= v5->children.num )
        break;
      v5 = v5->children.list[focusIndex];
      v9 = v5;
    }
    while ( v5 != nullptr );
    list = v10.list;
  }
  v7 = v10.num - 1;
  if ( v10.num - 1 >= 0 )
  {
    v8 = v7;
    while ( (*(unsigned __int8 (__fastcall **)(encounterGroupRole_t, const idWidgetEvent *))(*(_DWORD *)list[v8] + 16))(
              a1: list[v8],
              a2: event) == 0 )
    {
      --v7;
      --v8;
      if ( v7 < 0 )
        break;
      list = v10.list;
    }
    list = v10.list;
  }
  if ( (v10.listStatic == 0 || v10.listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
}


// ========================================================================
// __unwind$489786_0
// EA  : 0x82DDAD68
// RVA : 0x00DDAD68
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_489786_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 224 + 96));
}


// ========================================================================
// ?RegisterEventObserver@idMenuWidget@@QAAXPAV1@@Z
// EA  : 0x82DDAD90
// RVA : 0x00DDAD90
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void __fastcall idMenuWidget::RegisterEventObserver(
        idMenuWidget *this,
        idMenuWidget *observer,
        int a3,
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
        idMenuWidget *a14)
{
  idList<enum encounterGroupRole_t,5> *p_observers; // r3
  int v15; // r10
  int num; // r9
  encounterGroupRole_t *list; // r8
  int v18; // r11

  p_observers = (idList<enum encounterGroupRole_t,5> *)&this->observers;
  a14 = observer;
  v15 = 0;
  num = p_observers->num;
  if ( num <= 0 )
    goto LABEL_8;
  list = p_observers->list;
  v18 = 0;
  while ( (idMenuWidget *)list[v18] != observer )
  {
    ++v15;
    ++v18;
    if ( v15 >= num )
      goto LABEL_8;
  }
  if ( v15 < 0 || &list[v15] == nullptr )
LABEL_8:
    idList<idAnimWebBlendTree *,5>::Append(this: p_observers, obj: (encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?SetSpritePath@idMenuWidget@@QAAXPBD000@Z
// EA  : 0x82DDAE18
// RVA : 0x00DDAE18
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void __fastcall idMenuWidget::SetSpritePath(
        idMenuWidget *this,
        const char *arg1,
        const char *arg2,
        const char *arg3,
        const char *arg4)
{
  int listStatic; // r11
  idList<idStr,5> *p_spritePath; // r28
  int v7; // r30
  const char **v8; // r29
  _DWORD v9[4]; // [sp+50h] [-60h] BYREF
  idStr v10[2]; // [sp+60h] [-50h] BYREF

  listStatic = this->spritePath.listStatic;
  p_spritePath = &this->spritePath;
  v9[0] = arg1;
  v7 = 0;
  v9[1] = arg2;
  v9[2] = arg3;
  v9[3] = arg4;
  if ( listStatic == 0 || listStatic == 2 )
  {
    if ( p_spritePath->list != nullptr )
      idListArrayDelete<idStr>(ptr: this->spritePath.list, num: this->spritePath.size);
    p_spritePath->list = nullptr;
    p_spritePath->size = 0;
  }
  v8 = (const char **)v9;
  p_spritePath->num = 0;
  do
  {
    if ( *v8 == nullptr )
      break;
    idStr::idStr(this: v10, text: *v8);
    idList<idStr,5>::Append(this: p_spritePath, obj: v10);
    idStr::FreeData(this: v10);
    ++v7;
    ++v8;
  }
  while ( v7 < 4 );
}


// ========================================================================
// __unwind$489937
// EA  : 0x82DDAEB8
// RVA : 0x00DDAEB8
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_489937()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?SetSpritePath@idMenuWidget@@QAAXABV?$idList@VidStr@@$04@@PBD111@Z
// EA  : 0x82DDAEE8
// RVA : 0x00DDAEE8
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void __fastcall idMenuWidget::SetSpritePath(
        idMenuWidget *this,
        const idList<idStr,5> *spritePath_,
        const char *arg1,
        const char *arg2,
        const char *arg3,
        const char *arg4)
{
  idList<idStr,5> *p_spritePath; // r28
  int v7; // r30
  const char **v8; // r29
  _DWORD v9[4]; // [sp+50h] [-60h] BYREF
  idStr v10[2]; // [sp+60h] [-50h] BYREF

  p_spritePath = &this->spritePath;
  v9[0] = arg1;
  v9[1] = arg2;
  v9[2] = arg3;
  v9[3] = arg4;
  idList<idStr,58>::operator=(this: &this->spritePath, other: spritePath_);
  v7 = 0;
  v8 = (const char **)v9;
  do
  {
    if ( *v8 == nullptr )
      break;
    idStr::idStr(this: v10, text: *v8);
    idList<idStr,5>::Append(this: p_spritePath, obj: v10);
    idStr::FreeData(this: v10);
    ++v7;
    ++v8;
  }
  while ( v7 < 4 );
}


// ========================================================================
// __unwind$489969_0
// EA  : 0x82DDAF5C
// RVA : 0x00DDAF5C
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_489969_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// `idMainMenu::HandleMenu_Root'::`26'::idSWFScriptFunction_DeclineQuit::Call
// EA  : 0x82DDAF88
// RVA : 0x00DDAF88
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::HandleMenu_Root_::_26_::idSWFScriptFunction_DeclineQuit::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu::UpdateButtonBar(this: (idMainMenu *)thisObject->variables.num);
  common->ClearDialog(this: common, a2: GDM_QUIT_GAME, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?SetState@idMenuWidget@@QAAXW4widgetState_t@1@@Z
// EA  : 0x82DDAFE8
// RVA : 0x00DDAFE8
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void __fastcall idMenuWidget::SetState(idMenuWidget *this, idMenuWidget::widgetState_t state)
{
  idSWFSpriteInstance *boundSprite; // r3
  const char *v5; // r4
  idSWFSpriteInstance *v6; // r3

  boundSprite = this->boundSprite;
  if ( boundSprite != nullptr )
  {
    if ( state == WIDGET_STATE_HIDDEN )
    {
      idSWFSpriteInstance::SetVisible(this: boundSprite, visible: false);
LABEL_18:
      this->Update(this);
      goto LABEL_19;
    }
    idSWFSpriteInstance::SetVisible(this: boundSprite, visible: true);
    switch ( state )
    {
      case WIDGET_STATE_DISABLED:
        v5 = "disabled";
        break;
      case WIDGET_STATE_SELECTING:
        v6 = this->boundSprite;
        if ( this->widgetState == WIDGET_STATE_NORMAL )
          v5 = "selecting";
        else
          v5 = "sel_up";
        goto LABEL_17;
      case WIDGET_STATE_SELECTED:
        v5 = "sel_up";
        break;
      case WIDGET_STATE_NORMAL:
        if ( this->widgetState == WIDGET_STATE_SELECTING )
          v5 = "unselecting";
        else
          v5 = "out";
        break;
      default:
        goto LABEL_18;
    }
    v6 = this->boundSprite;
LABEL_17:
    idSWFSpriteInstance::PlayFrame(this: v6, frameName: v5);
    goto LABEL_18;
  }
LABEL_19:
  this->widgetState = state;
}


// ========================================================================
// ?SetFocusIndex@idMenuWidget@@QAAXH@Z
// EA  : 0x82DDB0E8
// RVA : 0x00DDB0E8
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void __fastcall idMenuWidget::SetFocusIndex(idMenuWidget *this, int index)
{
  idSWFScriptVar::swfScriptVarValue_t *focusIndex; // r29
  idSWFScriptVar::swfScriptVarValue_t *v5; // r29
  idStaticList<idSWFScriptVar,16> v6; // [sp+50h] [-200h] BYREF
  idWidgetEvent v7; // [sp+E0h] [-170h] BYREF
  idWidgetEvent v8; // [sp+180h] [-D0h] BYREF

  focusIndex = (idSWFScriptVar::swfScriptVarValue_t *)this->focusIndex;
  this->focusIndex = index;
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v6);
  idSWFParmList::Append(this: (idSWFParmList *)&v6, i: focusIndex);
  idSWFParmList::Append(this: (idSWFParmList *)&v6, i: (idSWFScriptVar::swfScriptVarValue_t *)index);
  if ( focusIndex != (idSWFScriptVar::swfScriptVarValue_t *)index )
  {
    v5 = (idSWFScriptVar::swfScriptVarValue_t *)(4 * (_DWORD)focusIndex);
    if ( (*(idMenuWidget **)((char *)this->children.list + (unsigned int)v5))->widgetState != WIDGET_STATE_HIDDEN )
    {
      v7.arg = 0;
      v7.thisObject = nullptr;
      v7.type = WIDGET_EVENT_FOCUS_OFF;
      idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(
        this: &v7.parms.idStaticList<idSWFScriptVar,16>,
        other: &v6);
      idMenuWidget::ReceiveEvent(this: *(idMenuWidget **)((char *)this->children.list + (unsigned int)v5), event: &v7);
      idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v7.parms.idStaticList<idSWFScriptVar,16>);
    }
  }
  v8.arg = 0;
  v8.thisObject = nullptr;
  v8.type = WIDGET_EVENT_FOCUS_ON;
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(
    this: &v8.parms.idStaticList<idSWFScriptVar,16>,
    other: &v6);
  idMenuWidget::ReceiveEvent(this: this->children.list[index], event: &v8);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v8.parms.idStaticList<idSWFScriptVar,16>);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v6);
}


// ========================================================================
// __unwind$490485
// EA  : 0x82DDB1C8
// RVA : 0x00DDB1C8
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_490485()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 592 + 80));
}


// ========================================================================
// __unwind$490486
// EA  : 0x82DDB1F0
// RVA : 0x00DDB1F0
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_490486()
{
  int v0; // r12

  idWidgetEvent::~idWidgetEvent(this: (idWidgetEvent *)(v0 - 592 + 224));
}


// ========================================================================
// __unwind$490487
// EA  : 0x82DDB218
// RVA : 0x00DDB218
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_490487()
{
  int v0; // r12

  idWidgetEvent::~idWidgetEvent(this: (idWidgetEvent *)(v0 - 592 + 384));
}


// ========================================================================
// ?HandleAction@idMenuWidget@@UAA_NAAVidWidgetAction@@ABVidWidgetEvent@@@Z
// EA  : 0x82DDB248
// RVA : 0x00DDB248
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

int __fastcall idMenuWidget::HandleAction(idMenuWidget *this, idWidgetAction *action, const idWidgetEvent *event)
{
  idMainMenu *mainMenu; // r30
  idSWFScriptFunction *scriptFunction; // r4
  int result; // r3
  idMenuWidget *v9; // r30
  idSWFScriptObject *thisObject; // r11
  int v11; // r3
  char v12; // r11
  mainMenuScreens_t v13; // r3
  int v14; // r3
  char v15; // r11
  mainMenuScreens_t v16; // r3
  widgetAction_t v17; // r3
  idMenuDataSource *dataSource; // r30
  idMenuDataSource_vtbl *v19; // r28
  int dataSourceFieldIndex; // r29
  int v21; // r3
  _DWORD *v22; // r3
  _DWORD *v23; // r30
  _DWORD *v24; // r3
  _DWORD *v25; // r6
  int v26; // r11
  idSWFScriptVar v27[2]; // [sp+70h] [-220h] BYREF
  idWidgetEvent v28; // [sp+80h] [-210h] BYREF
  idWidgetAction v29; // [sp+120h] [-170h] BYREF
  idStaticList<idSWFScriptVar,16> v30; // [sp+1C0h] [-D0h] BYREF

  mainMenu = gameLocal->mainMenu;
  if ( mainMenu == nullptr || mainMenu->mainMenu == nullptr )
    return 0;
  switch ( action->action )
  {
    case WIDGET_ACTION_FUNCTION:
      scriptFunction = action->scriptFunction;
      if ( scriptFunction != nullptr )
      {
        scriptFunction->Call(
          this: (idSWFScriptFunction *)v27,
          result: (idSWFScriptVar *)scriptFunction,
          a3: event->thisObject,
          a4: &event->parms);
        idSWFScriptVar::Free(this: v27);
      }
      result = 1;
      break;
    case WIDGET_ACTION_START_REPEATER:
      idWidgetAction::idWidgetAction(this: &v29);
      v17 = idSWFScriptVar::ToInteger(this: action->parms.list);
      idWidgetAction::Set(this: &v29, action_: v17, var1: (const idSWFScriptVar *)action->parms.list + 1);
      idMainMenu::StartWidgetActionRepeater(this: gameLocal->mainMenu, widget: this, action: &v29, event);
      idWidgetAction::~idWidgetAction(this: &v29);
      result = 1;
      break;
    case WIDGET_ACTION_STOP_REPEATER:
      idMainMenu::ClearWidgetActionRepeater(this: gameLocal->mainMenu);
      result = 1;
      break;
    case WIDGET_ACTION_ADJUST_FIELD:
      dataSource = this->dataSource;
      if ( dataSource != nullptr )
      {
        v19 = dataSource->__vftable;
        dataSourceFieldIndex = this->dataSourceFieldIndex;
        v21 = idSWFScriptVar::ToInteger(this: action->parms.list);
        v19->AdjustField(this: dataSource, a2: dataSourceFieldIndex, a3: v21);
        this->Update(this);
      }
      result = 1;
      break;
    case WIDGET_ACTION_PRESS_FOCUSED:
      v9 = mainMenu->menuScreens[mainMenu->activeMenu];
      if ( v9 != nullptr )
      {
        idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v30);
        thisObject = event->thisObject;
        v28.type = WIDGET_EVENT_PRESS;
        v28.arg = 0;
        v28.thisObject = thisObject;
        idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(
          this: &v28.parms.idStaticList<idSWFScriptVar,16>,
          other: &v30);
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v30);
        idMenuWidget::ReceiveEvent(this: v9, event: &v28);
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v28.parms.idStaticList<idSWFScriptVar,16>);
      }
      result = 1;
      break;
    case WIDGET_ACTION_GOTO_MENU:
      if ( idSWFScriptVar::ToInteger(this: action->parms.list) < 0
        || (v11 = idSWFScriptVar::ToInteger(this: action->parms.list), v12 = 1, v11 >= 7) )
      {
        v12 = 0;
      }
      if ( v12 != 0 )
      {
        mainMenu->menuTransition = MENU_TRANSITION_ADVANCE;
        v13 = idSWFScriptVar::ToInteger(this: action->parms.list);
        idMainMenu::SetActiveMenu(this: mainMenu, newMenuArea: v13);
        idMainMenu::ClearCmdButtons(this: mainMenu);
      }
      result = 1;
      break;
    case WIDGET_ACTION_GO_BACK:
      if ( idSWFScriptVar::ToInteger(this: action->parms.list) <= -1
        || (v14 = idSWFScriptVar::ToInteger(this: action->parms.list), v15 = 1, v14 >= 7) )
      {
        v15 = 0;
      }
      if ( v15 != 0 )
      {
        mainMenu->menuTransition = MENU_TRANSITION_BACK;
        idMainMenu::ClearCmdButtons(this: mainMenu);
        idMainMenu::UpdateButtonBar(this: mainMenu);
        v16 = idSWFScriptVar::ToInteger(this: action->parms.list);
        idMainMenu::ForceActiveMenu(this: mainMenu, newMenuArea: v16);
      }
      result = 1;
      break;
    case WIDGET_ACTION_EXIT_GAME:
      idMainMenu::HideButtonBar(this: gameLocal->mainMenu);
      v22 = idMem::AllocWithLocation(
              this: &mem,
              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
              size: 0xCu,
              tag: TAG_SWF,
              zeroBuffer: false,
              align: ALIGN_16,
              heap: HEAP_DEFAULTHEAP);
      if ( v22 != nullptr )
      {
        v22[2] = mainMenu;
        v22[1] = 0;
        v23 = v22;
        *v22 = &`idMenuWidget::HandleAction'::`31'::DeclineQuit::`vftable';
      }
      else
      {
        v23 = nullptr;
      }
      v24 = idMem::AllocWithLocation(
              this: &mem,
              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
              size: 8u,
              tag: TAG_SWF,
              zeroBuffer: false,
              align: ALIGN_16,
              heap: HEAP_DEFAULTHEAP);
      if ( v24 != nullptr )
      {
        v24[1] = 0;
        v25 = v24;
        *v24 = &`idMenuWidget::HandleAction'::`30'::AcceptQuit::`vftable';
      }
      else
      {
        v25 = nullptr;
      }
      ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
        a1: common,
        a2: 66,
        a3: 3,
        a4: v25,
        a5: v23,
        a6: 0,
        a7: 0,
        a8: 0);
      result = 1;
      break;
    case WIDGET_ACTION_LAUNCH_MULTIPLAYER:
      idMainMenu::ClearCmdButtons(this: gameLocal->mainMenu);
      v26 = 2;
      if ( com_multiplayer.valueInteger == 0 )
        v26 = 1;
      mainMenu->menuRequest = v26;
      result = 1;
      break;
    default:
      return 0;
  }
  return result;
}


// ========================================================================
// __unwind$490616
// EA  : 0x82DDB614
// RVA : 0x00DDB614
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_490616()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 656 + 448));
}


// ========================================================================
// __unwind$490617
// EA  : 0x82DDB63C
// RVA : 0x00DDB63C
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_490617()
{
  int v0; // r12

  idWidgetEvent::~idWidgetEvent(this: (idWidgetEvent *)(v0 - 656 + 128));
}


// ========================================================================
// __unwind$490618
// EA  : 0x82DDB664
// RVA : 0x00DDB664
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_490618()
{
  int v0; // r12

  idWidgetAction::~idWidgetAction(this: (idWidgetAction *)(v0 - 656 + 288));
}


// ========================================================================
// ??0idMenuWidget@@QAA@XZ
// EA  : 0x82DDBA98
// RVA : 0x00DDBA98
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

idMenuWidget *__fastcall idMenuWidget::idMenuWidget(idMenuWidget *this)
{
  int v1; // r29
  int size; // r11
  int i; // r11

  v1 = 0;
  this->boundSprite = nullptr;
  this->__vftable = (idMenuWidget_vtbl *)&idMenuWidget::`vftable';
  this->parent = nullptr;
  this->spritePath.granularity = 0;
  this->spritePath.memTag = 5;
  this->spritePath.listStatic = 0;
  this->spritePath.list = nullptr;
  this->spritePath.size = 0;
  this->spritePath.num = 0;
  this->children.list = nullptr;
  this->children.granularity = 0;
  this->children.memTag = 5;
  this->children.listStatic = 0;
  this->children.size = 0;
  this->children.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->children);
  this->observers.list = nullptr;
  this->observers.granularity = 0;
  this->observers.memTag = 5;
  this->observers.listStatic = 0;
  this->observers.size = 0;
  this->observers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->observers);
  this->eventActions.granularity = 0;
  this->eventActions.memTag = 5;
  this->eventActions.listStatic = 0;
  this->eventActions.list = nullptr;
  this->eventActions.size = 0;
  this->eventActions.num = 0;
  this->eventActionLookup.num = 0;
  this->eventActionLookup.granularity = 1;
  this->eventActionLookup.size = 18;
  this->eventActionLookup.list = this->eventActionLookup.staticList;
  this->eventActionLookup.memTag = 5;
  this->eventActionLookup.listStatic = 1;
  this->dataSource = nullptr;
  this->dataSourceFieldIndex = 0;
  this->focusIndex = 0;
  this->widgetState = WIDGET_STATE_NORMAL;
  if ( this->eventActionLookup.size >= 18
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->eventActionLookup,
                          newsize: 18) != 0 )
  {
    size = this->eventActionLookup.size;
    if ( size > 18 )
      size = 18;
    this->eventActionLookup.num = size;
  }
  for ( i = 0; i < this->eventActionLookup.num; ++v1 )
  {
    ++i;
    this->eventActionLookup.list[v1] = -1;
  }
  return this;
}


// ========================================================================
// __unwind$491064_0
// EA  : 0x82DDBC04
// RVA : 0x00DDBC04
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_491064_0()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 144 + 164) + 12));
}


// ========================================================================
// __unwind$491065_0
// EA  : 0x82DDBC30
// RVA : 0x00DDBC30
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_491065_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 28));
}


// ========================================================================
// __unwind$491066_0
// EA  : 0x82DDBC5C
// RVA : 0x00DDBC5C
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_491066_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 44));
}


// ========================================================================
// __unwind$491067_1
// EA  : 0x82DDBC88
// RVA : 0x00DDBC88
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_491067_1()
{
  int v0; // r12

  idList<idList<idWidgetAction,5>,5>::Clear(this: (idList<idList<idWidgetAction,5>,5> *)(*(_DWORD *)(v0 - 144 + 164) + 60));
}


// ========================================================================
// __unwind$491068_1
// EA  : 0x82DDBCB4
// RVA : 0x00DDBCB4
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_491068_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 76));
}


// ========================================================================
// ??1idMenuWidget@@UAA@XZ
// EA  : 0x82DDBCE8
// RVA : 0x00DDBCE8
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void __fastcall idMenuWidget::~idMenuWidget(idMenuWidget *this)
{
  int v2; // r28
  int v3; // r29
  idMenuWidget *v4; // r3
  idMenuWidget **list; // r4
  int *v6; // r4
  char *v7; // r3
  idMenuWidget **v8; // r4
  idMenuWidget **v9; // r4
  idStr *v10; // r27
  int size; // r29
  idStr *v12; // r28

  this->__vftable = (idMenuWidget_vtbl *)&idMenuWidget::`vftable';
  v2 = 0;
  if ( this->children.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->children.list[v3];
      if ( v4 != nullptr )
        ((void (__fastcall *)(idMenuWidget *, int))v4->dtr_idMenuWidget)(a1: v4, a2: 1);
      ++v2;
      ++v3;
    }
    while ( v2 < this->children.num );
  }
  if ( this->children.listStatic == 0 || this->children.listStatic == 2 )
  {
    list = this->children.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->children.list = nullptr;
    this->children.size = 0;
  }
  this->children.num = 0;
  if ( this->eventActionLookup.listStatic == 0 || this->eventActionLookup.listStatic == 2 )
  {
    v6 = this->eventActionLookup.list;
    if ( v6 != nullptr )
      idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    this->eventActionLookup.list = nullptr;
    this->eventActionLookup.size = 0;
  }
  this->eventActionLookup.num = 0;
  if ( this->eventActions.listStatic == 0 || this->eventActions.listStatic == 2 )
  {
    v7 = (char *)this->eventActions.list;
    if ( v7 != nullptr )
      idListArrayDelete<idList<idWidgetAction,5>>(ptr: v7, num: this->eventActions.size);
    this->eventActions.list = nullptr;
    this->eventActions.size = 0;
  }
  this->eventActions.num = 0;
  if ( this->observers.listStatic == 0 || this->observers.listStatic == 2 )
  {
    v8 = this->observers.list;
    if ( v8 != nullptr )
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    this->observers.list = nullptr;
    this->observers.size = 0;
  }
  this->observers.num = 0;
  if ( this->children.listStatic == 0 || this->children.listStatic == 2 )
  {
    v9 = this->children.list;
    if ( v9 != nullptr )
      idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
    this->children.list = nullptr;
    this->children.size = 0;
  }
  this->children.num = 0;
  if ( this->spritePath.listStatic == 0 || this->spritePath.listStatic == 2 )
  {
    v10 = this->spritePath.list;
    if ( v10 != nullptr )
    {
      size = this->spritePath.size;
      if ( size > 0 )
      {
        v12 = this->spritePath.list;
        do
        {
          idStr::FreeData(this: v12);
          --size;
          ++v12;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    }
    this->spritePath.list = nullptr;
    this->spritePath.size = 0;
  }
  this->spritePath.num = 0;
}


// ========================================================================
// __unwind$491191
// EA  : 0x82DDBEF0
// RVA : 0x00DDBEF0
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_491191()
{
  int v0; // r12

  idList<idStr,99>::~idList<idStr,99>(this: (idList<idStr,5> *)(*(_DWORD *)(v0 - 160 + 180) + 12));
}


// ========================================================================
// __unwind$491192
// EA  : 0x82DDBF1C
// RVA : 0x00DDBF1C
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_491192()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 28));
}


// ========================================================================
// __unwind$491193
// EA  : 0x82DDBF48
// RVA : 0x00DDBF48
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_491193()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 44));
}


// ========================================================================
// __unwind$491194
// EA  : 0x82DDBF74
// RVA : 0x00DDBF74
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_491194()
{
  int v0; // r12

  idList<idList<idWidgetAction,5>,5>::Clear(this: (idList<idList<idWidgetAction,5>,5> *)(*(_DWORD *)(v0 - 160 + 180) + 60));
}


// ========================================================================
// __unwind$491195_1
// EA  : 0x82DDBFA0
// RVA : 0x00DDBFA0
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

void _unwind_491195_1()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 76));
}


// ========================================================================
// ?AddEventAction@idMenuWidget@@QAAAAVidWidgetAction@@W4widgetEvent_t@@@Z
// EA  : 0x82DDC048
// RVA : 0x00DDC048
// PDB : w:\tech5\tungsten\game\menus\menuwidget.cpp
// ========================================================================

idWidgetAction *__fastcall idMenuWidget::AddEventAction(idMenuWidget *this, widgetEvent_t eventType)
{
  int *list; // r11
  widgetEvent_t v3; // r30

  list = this->eventActionLookup.list;
  v3 = eventType;
  if ( list[eventType] == -1 )
  {
    list[v3] = this->eventActions.num;
    idList<idList<idWidgetAction,5>,5>::Alloc(this: &this->eventActions);
  }
  return idList<idWidgetAction,5>::Alloc(this: &this->eventActions.list[this->eventActionLookup.list[v3]]);
}

