
// ========================================================================
// ?ShowScreen@idMenuScreen_Dev@@UAAXW4mainMenuTransition_t@@@Z
// EA  : 0x82DD8C38
// RVA : 0x00DD8C38
// PDB : w:\tech5\tungsten\game\menus\menuscreen_dev.cpp
// ========================================================================

void __fastcall idMenuScreen_Dev::ShowScreen(idMenuScreen_Dev *this, mainMenuTransition_t transitionType)
{
  idMenuWidget_DevList::GoToFirstMenu(this: this->listWidget);
  idMenuScreen::ShowScreen(this, transitionType);
}


// ========================================================================
// ?Call@DevList_NavigateBack@?A0xc30e331e@@UAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DD8DB0
// RVA : 0x00DD8DB0
// PDB : w:\tech5\tungsten\game\menus\menuscreen_dev.cpp
// ========================================================================

DevList_NavigateBack *__fastcall `anonymous namespace'::DevList_NavigateBack::Call(
        DevList_NavigateBack *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMenuWidget_DevList::NavigateBack(this: (idMenuWidget_DevList *)result[1].type);
  this->__vftable = (idSWFScriptFunction_RefCounted_vtbl *)4;
  return this;
}


// ========================================================================
// ?Initialize@idMenuScreen_Dev@@UAAXXZ
// EA  : 0x82DD8E58
// RVA : 0x00DD8E58
// PDB : w:\tech5\tungsten\game\menus\menuscreen_dev.cpp
// ========================================================================

void __fastcall idMenuScreen_Dev::Initialize(idMenuScreen_Dev *this)
{
  idMenuWidget_DevList *v2; // r3
  idMenuWidget_DevList *v3; // r3
  idMenuWidget_Help *v4; // r3
  idMenuWidget_Help *v5; // r27
  int v6; // r29
  int v7; // r28
  idMenuWidget_CommandBar *v8; // r3
  idMenuWidget *v9; // r26
  idStr *v10; // r29
  idStr *v11; // r29
  char *data; // r25
  int v13; // r28
  idSWFScriptVar *v14; // r27
  int p_ExecuteEvent; // r29
  _DWORD *v16; // r3
  idMenuWidget_DevList *listWidget; // r10
  _DWORD *v18; // r11

  idMenuWidget::SetSpritePath(this, arg1: "devMenu", arg2: nullptr, arg3: nullptr, arg4: nullptr);
  v2 = (idMenuWidget_DevList *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xD8u,
                                 tag: TAG_MENU,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idMenuWidget_DevList::idMenuWidget_DevList(this: v2);
  else
    v3 = nullptr;
  this->listWidget = v3;
  idMenuWidget::SetSpritePath(
    this: v3,
    spritePath_: &this->spritePath,
    arg1: "options",
    arg2: nullptr,
    arg3: nullptr,
    arg4: nullptr);
  this->listWidget->numVisibleOptions = 13;
  this->listWidget->allowWrapping = true;
  this->listWidget->Initialize(this: this->listWidget);
  idMenuWidget::AddChild(this, widget: this->listWidget);
  v4 = (idMenuWidget_Help *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0xF4u,
                              tag: TAG_MENU,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idMenuWidget_Help::idMenuWidget_Help(this: v4);
  else
    v5 = nullptr;
  idMenuWidget::SetSpritePath(
    this: v5,
    spritePath_: &this->listWidget->spritePath,
    arg1: "helpTooltip",
    arg2: nullptr,
    arg3: nullptr,
    arg4: nullptr);
  v6 = 0;
  if ( this->listWidget->children.num > 0 )
  {
    v7 = 0;
    do
    {
      idMenuWidget::RegisterEventObserver(this: this->listWidget->children.list[v7], observer: v5);
      ++v6;
      ++v7;
    }
    while ( v6 < this->listWidget->children.num );
  }
  idMenuWidget::AddChild(this, widget: v5);
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
  v10 = (idStr *)v9[1].__vftable;
  idStr::operator=(this: v10, text: "#STR_SWF_SELECT");
  v11 = v10 + 1;
  v11->len = 6;
  if ( v11->baseBuffer[7] == 0 || v11->baseBuffer[7] == 2 )
  {
    data = v11->data;
    if ( data != nullptr )
    {
      v13 = *(_DWORD *)v11->baseBuffer;
      if ( v13 > 0 )
      {
        v14 = (idSWFScriptVar *)v11->data;
        do
        {
          idSWFScriptVar::Free(this: v14);
          --v13;
          ++v14;
        }
        while ( v13 != 0 );
      }
      idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
    }
    v11->data = nullptr;
    *(_DWORD *)v11->baseBuffer = 0;
  }
  v11->allocedAndFlag = 0;
  p_ExecuteEvent = (int)&v9[1].__vftable[7].ExecuteEvent;
  idStr::operator=(this: (idStr *)p_ExecuteEvent, text: "#STR_SWF_BACK");
  v16 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
          size: 0xCu,
          tag: TAG_SWF,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  if ( v16 != nullptr )
  {
    listWidget = this->listWidget;
    v16[1] = 0;
    v18 = v16;
    *v16 = &`anonymous namespace'::DevList_NavigateBack::`vftable';
    v16[2] = listWidget;
  }
  else
  {
    v18 = nullptr;
  }
  *(_DWORD *)(p_ExecuteEvent + 32) = 1;
  *(_DWORD *)(p_ExecuteEvent + 180) = v18;
  idMenuWidget::AddChild(this, widget: v9);
}


// ========================================================================
// __unwind$488864
// EA  : 0x82DD9134
// RVA : 0x00DD9134
// PDB : w:\tech5\tungsten\game\menus\menuscreen_dev.cpp
// ========================================================================

void _unwind_488864()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488865
// EA  : 0x82DD9160
// RVA : 0x00DD9160
// PDB : w:\tech5\tungsten\game\menus\menuscreen_dev.cpp
// ========================================================================

void _unwind_488865()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$488866
// EA  : 0x82DD918C
// RVA : 0x00DD918C
// PDB : w:\tech5\tungsten\game\menus\menuscreen_dev.cpp
// ========================================================================

void _unwind_488866()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 80), tag: TAG_MENU);
}

