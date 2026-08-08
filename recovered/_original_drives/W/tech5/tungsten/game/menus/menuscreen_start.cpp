
// ========================================================================
// ?Call@UICmd_RegisterUser@?A0x51041a6a@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DDA5C0
// RVA : 0x00DDA5C0
// PDB : w:\tech5\tungsten\game\menus\menuscreen_start.cpp
// ========================================================================

UICmd_RegisterUser *__fastcall `anonymous namespace'::UICmd_RegisterUser::Call(
        UICmd_RegisterUser *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v7; // r29

  if ( parms->num == 1 )
  {
    v7 = idSWFScriptVar::ToInteger(this: parms->list);
    idMainMenu::ClearCmdButtons(this: (idMainMenu *)result[1].type);
    session->signInManager->RegisterLocalUser(this: session->signInManager, a2: v7);
    idMainMenu::SetActiveMenu(this: (idMainMenu *)result[1].type, newMenuArea: MENU_ROOT);
  }
  else
  {
    idLib::Warning(fmt: "No device specified when registering mouse user");
  }
  this->__vftable = (idSWFScriptFunction_RefCounted_vtbl *)4;
  return this;
}


// ========================================================================
// ?ShowScreen@idMenuScreen_Start@@UAAXW4mainMenuTransition_t@@@Z
// EA  : 0x82DDA658
// RVA : 0x00DDA658
// PDB : w:\tech5\tungsten\game\menus\menuscreen_start.cpp
// ========================================================================

void __fastcall idMenuScreen_Start::ShowScreen(idMenuScreen_Start *this, const mainMenuTransition_t transitionType)
{
  if ( idMenuWidget::BindSprite(this, root: gameLocal->mainMenu->mainMenu->mainspriteInstance->scriptObject) )
  {
    idSWFSpriteInstance::PlayFrame(this: this->boundSprite, frameName: "rollOn");
    this->Update(this);
    idMenuWidget::SetFocusIndex(this, index: this->focusIndex);
  }
}


// ========================================================================
// ?HideScreen@idMenuScreen_Start@@UAAXW4mainMenuTransition_t@@@Z
// EA  : 0x82DDA6E0
// RVA : 0x00DDA6E0
// PDB : w:\tech5\tungsten\game\menus\menuscreen_start.cpp
// ========================================================================

void __fastcall idMenuScreen_Start::HideScreen(idMenuScreen_Start *this, const mainMenuTransition_t transitionType)
{
  if ( idMenuWidget::BindSprite(this, root: gameLocal->mainMenu->mainMenu->mainspriteInstance->scriptObject) )
    idSWFSpriteInstance::PlayFrame(this: this->boundSprite, frameName: "rollOff");
}


// ========================================================================
// ?Initialize@idMenuScreen_Start@@UAAXXZ
// EA  : 0x82DDA750
// RVA : 0x00DDA750
// PDB : w:\tech5\tungsten\game\menus\menuscreen_start.cpp
// ========================================================================

void __fastcall idMenuScreen_Start::Initialize(idMenuScreen_Start *this)
{
  idMenuWidget_Button *v2; // r3
  idMenuWidget_Button *v3; // r30
  idSWFScriptFunction *v4; // r3
  idSWFScriptFunction *v5; // r27
  idMainMenu *mainMenu; // r5
  idWidgetAction *v7; // r3
  idMenuWidget_CommandBar *v8; // r3
  idMenuWidget *v9; // r30

  idMenuWidget::SetSpritePath(this, arg1: "startMenu", arg2: nullptr, arg3: nullptr, arg4: nullptr);
  v2 = (idMenuWidget_Button *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xFCu,
                                tag: TAG_MENU,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idMenuWidget_Button::idMenuWidget_Button(this: v2);
  else
    v3 = nullptr;
  idStr::operator=(this: &v3->label, text: "Press Start");
  v4 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xCu,
                                tag: TAG_SWF,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
  {
    v5 = v4;
    mainMenu = gameLocal->mainMenu;
    v4[1].__vftable = nullptr;
    v4->__vftable = (idSWFScriptFunction_vtbl *)&`anonymous namespace'::UICmd_RegisterUser::`vftable';
    v4[2].__vftable = (idSWFScriptFunction_vtbl *)mainMenu;
  }
  else
  {
    v5 = nullptr;
  }
  v7 = idMenuWidget::AddEventAction(this: v3, eventType: WIDGET_EVENT_PRESS);
  v7->scriptFunction = v5;
  v7->action = WIDGET_ACTION_FUNCTION;
  idMenuWidget::SetSpritePath(
    this: v3,
    spritePath_: &this->spritePath,
    arg1: "btnStart",
    arg2: nullptr,
    arg3: nullptr,
    arg4: nullptr);
  idMenuWidget::AddChild(this, widget: v3);
  v8 = (idMenuWidget_CommandBar *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x460u,
                                    tag: TAG_MENU,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  if ( v8 != nullptr )
    v9 = idMenuWidget_CommandBar::idMenuWidget_CommandBar(this: v8);
  else
    v9 = nullptr;
  v9[6].children.size = 1;
  idMenuWidget::SetSpritePath(this: v9, arg1: "cmdBar", arg2: nullptr, arg3: nullptr, arg4: nullptr);
  idMenuWidget::AddChild(this, widget: v9);
}


// ========================================================================
// __unwind$488759
// EA  : 0x82DDA8EC
// RVA : 0x00DDA8EC
// PDB : w:\tech5\tungsten\game\menus\menuscreen_start.cpp
// ========================================================================

void _unwind_488759()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488761
// EA  : 0x82DDA918
// RVA : 0x00DDA918
// PDB : w:\tech5\tungsten\game\menus\menuscreen_start.cpp
// ========================================================================

void _unwind_488761()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_MENU);
}

