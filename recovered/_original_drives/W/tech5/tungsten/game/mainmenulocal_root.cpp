
// ========================================================================
// ?UpdateCmds_Root@idMainMenu@@QAAXXZ
// EA  : 0x82DD4398
// RVA : 0x00DD4398
// PDB : w:\tech5\tungsten\game\mainmenulocal_root.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateCmds_Root(idMainMenu *this)
{
  idSWFScriptObject *scriptObject; // r29
  idSWFScriptObject *NestedObj; // r28
  idSWFScriptObject *v4; // r3

  scriptObject = this->mainMenu->mainspriteInstance->scriptObject;
  NestedObj = idSWFScriptObject::GetNestedObj(
                this: scriptObject,
                arg1: "mainMenu",
                arg2: "btnUp",
                arg3: nullptr,
                arg4: nullptr,
                arg5: nullptr,
                arg6: nullptr);
  v4 = idSWFScriptObject::GetNestedObj(
         this: scriptObject,
         arg1: "mainMenu",
         arg2: "btnDown",
         arg3: nullptr,
         arg4: nullptr,
         arg5: nullptr,
         arg6: nullptr);
  idMainMenu::UpdateScrollCmds(this, btnUp: NestedObj, btnDown: v4);
  idMainMenu::UpdateAcceptBackCmds(this);
}


// ========================================================================
// `idMainMenu::UpdateMenu_Root'::`21'::idSWFScriptFunction_accept::Call
// EA  : 0x82DD4428
// RVA : 0x00DD4428
// PDB : w:\tech5\tungsten\game\mainmenulocal_root.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::UpdateMenu_Root_::_21_::idSWFScriptFunction_accept::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *size; // r3
  int v6; // r10
  int v7; // r9
  int v8; // r10
  int v9; // r8
  bool v10; // r4

  size = (idMainMenu *)thisObject->variables.size;
  if ( !size->scrollingMenu )
  {
    v6 = size->menuIndex[1];
    v7 = *(_DWORD *)&thisObject->variables.granularity;
    if ( v6 != v7 )
    {
      v8 = v7 - v6;
      if ( v8 <= 0 )
      {
        if ( v8 >= 0 )
          goto LABEL_9;
        v9 = v8 + 1;
        v10 = true;
      }
      else
      {
        v9 = v8 - 1;
        v10 = false;
      }
      *(_DWORD *)(thisObject->variables.size + 428) = v9;
      idMainMenu::ScrollActiveScreen(this: (idMainMenu *)thisObject->variables.size, up: v10, fast: true);
      goto LABEL_9;
    }
    idMainMenu::HandleMenuSelection(this: size, type: MENU_TRANSITION_ADVANCE);
  }
LABEL_9:
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?HandleMenu_Root@idMainMenu@@QAAXW4mainMenuTransition_t@@@Z
// EA  : 0x82DD44C8
// RVA : 0x00DD44C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_root.cpp
// ========================================================================

void __fastcall idMainMenu::HandleMenu_Root(idMainMenu *this, mainMenuTransition_t type)
{
  int v4; // r11
  idList<char const *,5> *p_devMapListNames; // r30
  int valueInteger; // r11
  _DWORD *v7; // r3
  _DWORD *v8; // r27
  _DWORD *v9; // r3
  _DWORD *v10; // r6
  const char *v11; // [sp+70h] [-40h] BYREF

  if ( type != MENU_TRANSITION_ADVANCE )
  {
    if ( type == MENU_TRANSITION_BACK )
    {
      idMainMenu::ClearCmdButtons(this);
      idMainMenu::UpdateButtonBar(this);
      idMainMenu::ForceActiveMenu(this, newMenuArea: MENU_START);
      idMainMenu::ForceMenuArea(this, newMenuArea: MENU_PRESS_START);
    }
    goto LABEL_20;
  }
  v4 = this->menuIndex[1];
  switch ( v4 )
  {
    case 0:
      p_devMapListNames = &this->devMapListNames;
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->devMapListNames);
      v11 = "devmenuoption/main";
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)p_devMapListNames,
        obj: (encounterGroupRole_t *)&v11);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->devMapListIndexes);
      this->devMenuList = nullptr;
      this->devMenuDepth = 0;
      idMainMenu::SetActiveMenu(this, newMenuArea: MENU_DEV);
      idMainMenu::ClearCmdButtons(this);
      this->menuTransition = MENU_TRANSITION_ADVANCE;
      return;
    case 2:
      idMainMenu::ClearCmdButtons(this);
      valueInteger = com_multiplayer.valueInteger;
      this->menuTransition = MENU_TRANSITION_ADVANCE;
      if ( valueInteger != 0 )
        this->menuRequest = MENU_SWITCH_SP;
      else
        this->menuRequest = MENU_SWITCH_MP;
      return;
    case 3:
      idMainMenu::SetActiveMenu(this, newMenuArea: MENU_SETTINGS);
      idMainMenu::ClearCmdButtons(this);
      this->menuTransition = MENU_TRANSITION_ADVANCE;
      return;
    default:
      break;
  }
  if ( v4 != 5 )
  {
LABEL_20:
    this->menuTransition = type;
    return;
  }
  idMainMenu::HideButtonBar(this);
  v7 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
         size: 0xCu,
         tag: TAG_SWF,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
  {
    v7[2] = this;
    v7[1] = 0;
    v8 = v7;
    *v7 = &`idMainMenu::HandleMenu_Root'::`26'::idSWFScriptFunction_DeclineQuit::`vftable';
  }
  else
  {
    v8 = nullptr;
  }
  v9 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
         size: 8u,
         tag: TAG_SWF,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v9 != nullptr )
  {
    v9[1] = 0;
    v10 = v9;
    *v9 = &`idMainMenu::HandleMenu_Root'::`25'::idSWFScriptFunction_AcceptQuit::`vftable';
  }
  else
  {
    v10 = nullptr;
  }
  ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
    a1: common,
    a2: 66,
    a3: 3,
    a4: v10,
    a5: v8,
    a6: 0,
    a7: 0,
    a8: 0);
  this->menuTransition = MENU_TRANSITION_ADVANCE;
}


// ========================================================================
// ?UpdateMenu_Root@idMainMenu@@QAAXXZ
// EA  : 0x82DD46F8
// RVA : 0x00DD46F8
// PDB : w:\tech5\tungsten\game\mainmenulocal_root.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateMenu_Root(idMainMenu *this)
{
  __int64 v2; // r10
  __int64 v3; // r6
  __int64 v4; // r8
  int v5; // r23
  va *v6; // r3
  idSWFScriptObject *NestedObj; // r30
  int v8; // r11
  int v9; // r28
  idSWFTextInstance *str; // r29
  idStr *v11; // r3
  idSWFSpriteInstance *v12; // r29
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  idSWFScriptFunction *v16; // r3
  idSWF *mainMenu; // r11
  idSWFScriptFunction *v18; // r4
  idSWFScriptVar *v19; // r3
  int v20; // [sp+8h] [-1208h]
  int v21; // [sp+Ch] [-1204h]
  int v22; // [sp+10h] [-1200h]
  int v23; // [sp+14h] [-11FCh]
  int v24; // [sp+18h] [-11F8h]
  int v25; // [sp+1Ch] [-11F4h]
  idSWFScriptVar v26; // [sp+50h] [-11C0h] BYREF
  idSWFScriptVar v27; // [sp+58h] [-11B8h] BYREF
  idSWFScriptVar v28; // [sp+60h] [-11B0h] BYREF
  idSWFScriptObject v29; // [sp+68h] [-11A8h] BYREF
  idStaticList<idSWFScriptVar,16> v30; // [sp+D0h] [-1140h] BYREF
  va v31; // [sp+160h] [-10B0h] BYREF

  HIDWORD(v3) = this->mainMenu->mainspriteInstance;
  v29.variablesHash[6] = (int)"CAMPAIGN";
  v29.variablesHash[7] = (int)"MULTIPLAYER";
  v29.variablesHash[8] = (int)"SETTINGS";
  v29.variablesHash[9] = (int)"EXTRAS";
  v29.variablesHash[10] = (int)"EXIT";
  v29.variables.size = *(_DWORD *)(HIDWORD(v3) + 40);
  v29.variablesHash[5] = (int)"DEV";
  LODWORD(v2) = 0x82000000;
  HIDWORD(v2) = allocationCurrent[242];
  this->numOptions[1] = 6;
  HIDWORD(v4) = &unk_82340000;
  LODWORD(v3) = &unk_821F0000;
  LODWORD(v4) = "optionType";
  v5 = 0;
  v29.variables.num = (int)"optionType";
  do
  {
    HIDWORD(v3) = v5;
    v6 = va::va(
           this: &v31,
           fmt: "option%d",
           a3: v3,
           a4: v4,
           a5: v2,
           a6: v20,
           a7: v21,
           a8: v22,
           a9: v23,
           a10: v24,
           a11: v25);
    NestedObj = idSWFScriptObject::GetNestedObj(
                  this: (idSWFScriptObject *)v29.variables.size,
                  arg1: "mainMenu",
                  arg2: "options",
                  arg3: v6->buffer,
                  arg4: nullptr,
                  arg5: nullptr,
                  arg6: nullptr);
    if ( NestedObj != nullptr )
    {
      v8 = this->menuIndex[1];
      v9 = v8 + v5;
      if ( v5 > 6 )
        v9 = v8 - v5 + 6;
      if ( v9 < 0 || v9 >= this->numOptions[1] )
      {
        v28.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v28);
        v28.type = SWF_VAR_INTEGER;
        v28.value.i = 0;
        idSWFScriptObject::Set(this: NestedObj, name: "_visible", value: &v28);
        idSWFScriptVar::Free(this: &v28);
        v27.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v27);
        v27.type = SWF_VAR_INTEGER;
        v27.value.i = 0;
        idSWFScriptObject::Set(this: NestedObj, name: "onPress", value: &v27);
        v19 = &v27;
      }
      else
      {
        v26.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v26);
        v26.type = SWF_VAR_INTEGER;
        v26.value.i = 1;
        idSWFScriptObject::Set(this: NestedObj, name: "_visible", value: &v26);
        idSWFScriptVar::Free(this: &v26);
        idSWFScriptObject::Get(this: &v29, result: NestedObj, name: "txtOption");
        if ( v29.refCount == 8 )
        {
          if ( v29.variables.list[3].hashNext == 3 )
            str = (idSWFTextInstance *)v29.variables.list[3].name.str;
          else
            str = nullptr;
          v11 = idStr::idStr(this: (idStr *)&v29.variablesHash[13], text: (const char *)v29.variablesHash[v9 + 5]);
          idSWFTextInstance::SetText(this: str, val: v11);
          idSWFTextInstance::SetStrokeInfo(this: str, use: true, strength: 0.75, weight: 2.0);
        }
        idSWFScriptObject::Get(
          this: (idSWFScriptObject *)&v29.variables.granularity,
          result: NestedObj,
          name: (char *)v29.variables.num);
        v12 = idSWFScriptVar::ToSprite(this: (idSWFScriptVar *)&v29.variables.granularity);
        if ( v12 != nullptr )
        {
          idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v30);
          idSWFParmList::Append(this: (idSWFParmList *)&v30, i: (idSWFScriptVar::swfScriptVarValue_t *)1);
          idSWFSpriteInstance::StopFrame(this: v12, parms: (const idSWFParmList *)&v30, a3: v15, a4: v14, a5: v13);
          idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v30);
        }
        v16 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x14u,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
        if ( v16 != nullptr )
        {
          mainMenu = this->mainMenu;
          v18 = v16;
          v16[3].__vftable = (idSWFScriptFunction_vtbl *)this;
          v16[4].__vftable = (idSWFScriptFunction_vtbl *)v9;
          v16[1].__vftable = nullptr;
          v16->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateMenu_Root'::`21'::idSWFScriptFunction_accept::`vftable';
          v16[2].__vftable = (idSWFScriptFunction_vtbl *)mainMenu;
        }
        else
        {
          v18 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v29.variablesHash[1], nf: v18);
        idSWFScriptObject::Set(this: NestedObj, name: "onPress", value: (idSWFScriptVar *)&v29.variablesHash[1]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v29.variablesHash[1]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v29.variables.granularity);
        v19 = (idSWFScriptVar *)&v29;
      }
      idSWFScriptVar::Free(this: v19);
    }
    ++v5;
  }
  while ( v5 < 13 );
  if ( this->activeMenu == MENU_ROOT )
  {
    idStr::operator=(this: &this->btn1Text, text: "#STR_SWF_SELECT");
    idStr::operator=(this: &this->btn2Text, text: "#STR_SWF_BACK");
  }
  idMainMenu::UpdateButtonBar(this);
}


// ========================================================================
// __unwind$488550_0
// EA  : 0x82DD4A5C
// RVA : 0x00DD4A5C
// PDB : w:\tech5\tungsten\game\mainmenulocal_root.cpp
// ========================================================================

void _unwind_488550_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4624 + 80));
}


// ========================================================================
// __unwind$488551_0
// EA  : 0x82DD4A84
// RVA : 0x00DD4A84
// PDB : w:\tech5\tungsten\game\mainmenulocal_root.cpp
// ========================================================================

void _unwind_488551_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4624 + 104));
}


// ========================================================================
// __unwind$488553_0
// EA  : 0x82DD4AAC
// RVA : 0x00DD4AAC
// PDB : w:\tech5\tungsten\game\mainmenulocal_root.cpp
// ========================================================================

void _unwind_488553_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4624 + 120));
}


// ========================================================================
// __unwind$488554_0
// EA  : 0x82DD4AD4
// RVA : 0x00DD4AD4
// PDB : w:\tech5\tungsten\game\mainmenulocal_root.cpp
// ========================================================================

void _unwind_488554_0()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 4624 + 208));
}


// ========================================================================
// __unwind$488556_0
// EA  : 0x82DD4AFC
// RVA : 0x00DD4AFC
// PDB : w:\tech5\tungsten\game\mainmenulocal_root.cpp
// ========================================================================

void _unwind_488556_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4624 + 128));
}


// ========================================================================
// __unwind$488548
// EA  : 0x82DD4B24
// RVA : 0x00DD4B24
// PDB : w:\tech5\tungsten\game\mainmenulocal_root.cpp
// ========================================================================

void _unwind_488548()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4624 + 96));
}


// ========================================================================
// __unwind$488549_0
// EA  : 0x82DD4B4C
// RVA : 0x00DD4B4C
// PDB : w:\tech5\tungsten\game\mainmenulocal_root.cpp
// ========================================================================

void _unwind_488549_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4624 + 88));
}

