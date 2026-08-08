
// ========================================================================
// ?HandleMenu_Settings@idMainMenu@@QAAXW4mainMenuTransition_t@@@Z
// EA  : 0x82DD4B78
// RVA : 0x00DD4B78
// PDB : w:\tech5\tungsten\game\mainmenulocal_settings.cpp
// ========================================================================

void __fastcall idMainMenu::HandleMenu_Settings(idMainMenu *this, mainMenuTransition_t type)
{
  mainMenuScreens_t v4; // r4

  if ( type != MENU_TRANSITION_ADVANCE )
  {
    if ( type == MENU_TRANSITION_BACK )
    {
      idMainMenu::ClearCmdButtons(this);
      idMainMenu::UpdateButtonBar(this);
      v4 = MENU_ROOT;
      goto LABEL_6;
    }
  }
  else if ( this->menuIndex[5] == 1 )
  {
    idMainMenu::ClearCmdButtons(this);
    idMainMenu::UpdateButtonBar(this);
    idMainMenu::InitializeAudioValues(this);
    v4 = MENU_AUDIO;
LABEL_6:
    idMainMenu::SetActiveMenu(this, newMenuArea: v4);
  }
  this->menuTransition = type;
}


// ========================================================================
// ?UpdateCmds_Settings@idMainMenu@@QAAXXZ
// EA  : 0x82DD4C08
// RVA : 0x00DD4C08
// PDB : w:\tech5\tungsten\game\mainmenulocal_settings.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateCmds_Settings(idMainMenu *this)
{
  idSWFScriptObject *scriptObject; // r29
  idSWFScriptObject *NestedObj; // r28
  idSWFScriptObject *v4; // r3

  scriptObject = this->mainMenu->mainspriteInstance->scriptObject;
  NestedObj = idSWFScriptObject::GetNestedObj(
                this: scriptObject,
                arg1: "settingsMenu",
                arg2: "btnUp",
                arg3: nullptr,
                arg4: nullptr,
                arg5: nullptr,
                arg6: nullptr);
  v4 = idSWFScriptObject::GetNestedObj(
         this: scriptObject,
         arg1: "settingsMenu",
         arg2: "btnDown",
         arg3: nullptr,
         arg4: nullptr,
         arg5: nullptr,
         arg6: nullptr);
  idMainMenu::UpdateScrollCmds(this, btnUp: NestedObj, btnDown: v4);
  idMainMenu::UpdateAcceptBackCmds(this);
}


// ========================================================================
// `idMainMenu::UpdateMenu_Settings'::`21'::idSWFScriptFunction_accept::Call
// EA  : 0x82DD4C98
// RVA : 0x00DD4C98
// PDB : w:\tech5\tungsten\game\mainmenulocal_settings.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::UpdateMenu_Settings_::_21_::idSWFScriptFunction_accept::Call(
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
    v6 = size->menuIndex[5];
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
// ?UpdateMenu_Settings@idMainMenu@@QAAXXZ
// EA  : 0x82DD4D40
// RVA : 0x00DD4D40
// PDB : w:\tech5\tungsten\game\mainmenulocal_settings.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateMenu_Settings(idMainMenu *this)
{
  idSWF *mainMenu; // r11
  idSWFSpriteInstance *mainspriteInstance; // r6
  int scriptObject; // r10
  __int64 v5; // r10
  __int64 v6; // r6
  __int64 v7; // r8
  int v8; // r23
  va *v9; // r3
  idSWFScriptObject *NestedObj; // r30
  int v11; // r11
  int v12; // r28
  idSWFTextInstance *str; // r29
  idStr *v14; // r3
  idSWFSpriteInstance *v15; // r29
  __int64 v16; // r10
  __int64 v17; // r8
  __int64 v18; // r6
  idSWFScriptFunction *v19; // r3
  idSWF *v20; // r11
  idSWFScriptFunction *v21; // r4
  idSWFScriptVar *v22; // r3
  int v23; // [sp+8h] [-11F8h]
  int v24; // [sp+Ch] [-11F4h]
  int v25; // [sp+10h] [-11F0h]
  int v26; // [sp+14h] [-11ECh]
  int v27; // [sp+18h] [-11E8h]
  int v28; // [sp+1Ch] [-11E4h]
  idSWFScriptVar v29; // [sp+50h] [-11B0h] BYREF
  idSWFScriptVar v30; // [sp+58h] [-11A8h] BYREF
  idSWFScriptVar v31; // [sp+60h] [-11A0h] BYREF
  idSWFScriptObject v32[2]; // [sp+68h] [-1198h] BYREF
  va v33; // [sp+150h] [-10B0h] BYREF

  mainMenu = this->mainMenu;
  v32[0].variablesHash[5] = (int)"VIDEO";
  mainspriteInstance = mainMenu->mainspriteInstance;
  v32[0].variablesHash[8] = (int)"GAMEPAD";
  scriptObject = (int)mainspriteInstance->scriptObject;
  v32[0].variablesHash[6] = (int)"AUDIO";
  v32[0].variablesHash[7] = (int)"KEYBOARD / MOUSE";
  this->numOptions[5] = 4;
  v32[0].variables.size = scriptObject;
  LODWORD(v5) = 0x82000000;
  HIDWORD(v5) = allocationCurrent[242];
  HIDWORD(v7) = &unk_82340000;
  LODWORD(v6) = &unk_821F0000;
  LODWORD(v7) = "optionType";
  v8 = 0;
  v32[0].variables.num = (int)"optionType";
  do
  {
    HIDWORD(v6) = v8;
    v9 = va::va(
           this: &v33,
           fmt: "option%d",
           a3: v6,
           a4: v7,
           a5: v5,
           a6: v23,
           a7: v24,
           a8: v25,
           a9: v26,
           a10: v27,
           a11: v28);
    NestedObj = idSWFScriptObject::GetNestedObj(
                  this: (idSWFScriptObject *)v32[0].variables.size,
                  arg1: "settingsMenu",
                  arg2: "options",
                  arg3: v9->buffer,
                  arg4: nullptr,
                  arg5: nullptr,
                  arg6: nullptr);
    if ( NestedObj != nullptr )
    {
      v11 = this->menuIndex[5];
      v12 = v11 + v8;
      if ( v8 > 6 )
        v12 = v11 - v8 + 6;
      if ( v12 < 0 || v12 >= this->numOptions[5] )
      {
        v31.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v31);
        v31.type = SWF_VAR_INTEGER;
        v31.value.i = 0;
        idSWFScriptObject::Set(this: NestedObj, name: "_visible", value: &v31);
        idSWFScriptVar::Free(this: &v31);
        v30.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v30);
        v30.type = SWF_VAR_INTEGER;
        v30.value.i = 0;
        idSWFScriptObject::Set(this: NestedObj, name: "onPress", value: &v30);
        v22 = &v30;
      }
      else
      {
        v29.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v29);
        v29.type = SWF_VAR_INTEGER;
        v29.value.i = 1;
        idSWFScriptObject::Set(this: NestedObj, name: "_visible", value: &v29);
        idSWFScriptVar::Free(this: &v29);
        idSWFScriptObject::Get(this: v32, result: NestedObj, name: "txtOption");
        if ( v32[0].refCount == 8 )
        {
          if ( v32[0].variables.list[3].hashNext == 3 )
            str = (idSWFTextInstance *)v32[0].variables.list[3].name.str;
          else
            str = nullptr;
          v14 = idStr::idStr(this: (idStr *)&v32[0].variablesHash[9], text: (const char *)v32[0].variablesHash[v12 + 5]);
          idSWFTextInstance::SetText(this: str, val: v14);
          idSWFTextInstance::SetStrokeInfo(this: str, use: true, strength: 0.75, weight: 2.0);
        }
        idSWFScriptObject::Get(
          this: (idSWFScriptObject *)&v32[0].variables.granularity,
          result: NestedObj,
          name: (char *)v32[0].variables.num);
        v15 = idSWFScriptVar::ToSprite(this: (idSWFScriptVar *)&v32[0].variables.granularity);
        if ( v15 != nullptr )
        {
          idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v32[0].objectType);
          idSWFParmList::Append(this: (idSWFParmList *)&v32[0].objectType, i: (idSWFScriptVar::swfScriptVarValue_t *)1);
          idSWFSpriteInstance::StopFrame(
            this: v15,
            parms: (const idSWFParmList *)&v32[0].objectType,
            a3: v18,
            a4: v17,
            a5: v16);
          idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v32[0].objectType);
        }
        v19 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x14u,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
        if ( v19 != nullptr )
        {
          v20 = this->mainMenu;
          v21 = v19;
          v19[3].__vftable = (idSWFScriptFunction_vtbl *)this;
          v19[4].__vftable = (idSWFScriptFunction_vtbl *)v12;
          v19[1].__vftable = nullptr;
          v19->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateMenu_Settings'::`21'::idSWFScriptFunction_accept::`vftable';
          v19[2].__vftable = (idSWFScriptFunction_vtbl *)v20;
        }
        else
        {
          v21 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v32[0].variablesHash[1], nf: v21);
        idSWFScriptObject::Set(this: NestedObj, name: "onPress", value: (idSWFScriptVar *)&v32[0].variablesHash[1]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v32[0].variablesHash[1]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v32[0].variables.granularity);
        v22 = (idSWFScriptVar *)v32;
      }
      idSWFScriptVar::Free(this: v22);
    }
    ++v8;
  }
  while ( v8 < 13 );
  if ( this->activeMenu == MENU_SETTINGS )
  {
    idStr::operator=(this: &this->btn1Text, text: "#STR_SWF_SELECT");
    idStr::operator=(this: &this->btn2Text, text: "#STR_SWF_BACK");
  }
  idMainMenu::UpdateButtonBar(this);
}


// ========================================================================
// __unwind$487996
// EA  : 0x82DD508C
// RVA : 0x00DD508C
// PDB : w:\tech5\tungsten\game\mainmenulocal_settings.cpp
// ========================================================================

void _unwind_487996()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4608 + 80));
}


// ========================================================================
// __unwind$487997_0
// EA  : 0x82DD50B4
// RVA : 0x00DD50B4
// PDB : w:\tech5\tungsten\game\mainmenulocal_settings.cpp
// ========================================================================

void _unwind_487997_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4608 + 104));
}


// ========================================================================
// __unwind$487999_0
// EA  : 0x82DD50DC
// RVA : 0x00DD50DC
// PDB : w:\tech5\tungsten\game\mainmenulocal_settings.cpp
// ========================================================================

void _unwind_487999_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4608 + 120));
}


// ========================================================================
// __unwind$488000
// EA  : 0x82DD5104
// RVA : 0x00DD5104
// PDB : w:\tech5\tungsten\game\mainmenulocal_settings.cpp
// ========================================================================

void _unwind_488000()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 4608 + 192));
}


// ========================================================================
// __unwind$488002
// EA  : 0x82DD512C
// RVA : 0x00DD512C
// PDB : w:\tech5\tungsten\game\mainmenulocal_settings.cpp
// ========================================================================

void _unwind_488002()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4608 + 128));
}


// ========================================================================
// __unwind$487994_1
// EA  : 0x82DD5154
// RVA : 0x00DD5154
// PDB : w:\tech5\tungsten\game\mainmenulocal_settings.cpp
// ========================================================================

void _unwind_487994_1()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4608 + 96));
}


// ========================================================================
// __unwind$487995_1
// EA  : 0x82DD517C
// RVA : 0x00DD517C
// PDB : w:\tech5\tungsten\game\mainmenulocal_settings.cpp
// ========================================================================

void _unwind_487995_1()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4608 + 88));
}

