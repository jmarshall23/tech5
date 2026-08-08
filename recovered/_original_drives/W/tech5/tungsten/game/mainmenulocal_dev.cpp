
// ========================================================================
// ?UpdateCmds_Dev@idMainMenu@@QAAXXZ
// EA  : 0x82DBDE60
// RVA : 0x00DBDE60
// PDB : w:\tech5\tungsten\game\mainmenulocal_dev.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateCmds_Dev(idMainMenu *this)
{
  idSWFScriptObject *scriptObject; // r29
  idSWFScriptObject *NestedObj; // r28
  idSWFScriptObject *v4; // r3

  scriptObject = this->mainMenu->mainspriteInstance->scriptObject;
  NestedObj = idSWFScriptObject::GetNestedObj(
                this: scriptObject,
                arg1: "devMenu",
                arg2: "btnUp",
                arg3: nullptr,
                arg4: nullptr,
                arg5: nullptr,
                arg6: nullptr);
  v4 = idSWFScriptObject::GetNestedObj(
         this: scriptObject,
         arg1: "devMenu",
         arg2: "btnDown",
         arg3: nullptr,
         arg4: nullptr,
         arg5: nullptr,
         arg6: nullptr);
  idMainMenu::UpdateScrollCmds(this, btnUp: NestedObj, btnDown: v4);
  idMainMenu::UpdateAcceptBackCmds(this);
}


// ========================================================================
// `idMainMenu::UpdateMenu_Dev'::`24'::idSWFScriptFunction_accept::Call
// EA  : 0x82DBDEF0
// RVA : 0x00DBDEF0
// PDB : w:\tech5\tungsten\game\mainmenulocal_dev.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::UpdateMenu_Dev_::_24_::idSWFScriptFunction_accept::Call(
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
    v6 = size->menuIndex[2];
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
// ?HandleMenu_Dev@idMainMenu@@QAAXW4mainMenuTransition_t@@@Z
// EA  : 0x82DBDF90
// RVA : 0x00DBDF90
// PDB : w:\tech5\tungsten\game\mainmenulocal_dev.cpp
// ========================================================================

void __fastcall idMainMenu::HandleMenu_Dev(idMainMenu *this, mainMenuTransition_t type)
{
  const idDeclDevMenuList *devMenuList; // r11
  encounterGroupRole_t *v4; // r30
  __int64 v5; // r8
  __int64 v6; // r10
  __int64 v7; // r6
  va *v8; // r3
  int num; // r11
  int v10; // [sp+8h] [-1078h]
  int v11; // [sp+Ch] [-1074h]
  int v12; // [sp+10h] [-1070h]
  int v13; // [sp+14h] [-106Ch]
  int v14; // [sp+18h] [-1068h]
  int v15; // [sp+1Ch] [-1064h]
  const char *str; // [sp+50h] [-1030h] BYREF
  va v17; // [sp+60h] [-1020h] BYREF

  if ( type != MENU_TRANSITION_ADVANCE )
  {
    if ( type != MENU_TRANSITION_BACK )
      return;
    if ( this->devMapListIndexes.num == 0 )
    {
      this->menuTransition = MENU_TRANSITION_BACK;
      idMainMenu::ClearCmdButtons(this);
      idMainMenu::SetActiveMenu(this, newMenuArea: MENU_ROOT);
      return;
    }
    idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
      this: (idList<idEntityPtr<idEntity>,58> *)&this->devMapListNames,
      index: this->devMapListNames.num - 1);
    num = this->devMapListIndexes.num;
    this->menuIndex[2] = this->devMapListIndexes.list[num - 1];
    idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
      this: (idList<idEntityPtr<idEntity>,58> *)&this->devMapListIndexes,
      index: num - 1);
    goto LABEL_12;
  }
  devMenuList = this->devMenuList;
  if ( devMenuList != nullptr )
  {
    v4 = (encounterGroupRole_t *)&this->menuIndex[2];
    if ( idStr::Cmp(s1: devMenuList->devMenuList.list[this->menuIndex[2]].devMenuDisplayName.data, s2: &byte_8200D768) != 0
      && idStr::Cmp(s1: this->devMenuList->devMenuList.list[*v4].devMenuDisplayName.data, s2: "...") != 0 )
    {
      if ( this->devMenuList->devMenuList.list[*v4].devMenuSubList == nullptr )
      {
        HIDWORD(v6) = "ame: %s\n";
        LODWORD(v6) = &this->devMapListNames.list[this->devMapListNames.num - 1];
        HIDWORD(v7) = *(_DWORD *)v6;
        SLODWORD(v7) = *v4;
        v8 = va::va(
               this: &v17,
               fmt: "loadDevMenuOption %s %d\n",
               a3: v7,
               a4: v5,
               a5: v6,
               a6: v10,
               a7: v11,
               a8: v12,
               a9: v13,
               a10: v14,
               a11: v15);
        cmdSystem->AppendCommandText(this: cmdSystem, a2: v8->buffer);
        return;
      }
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->devMapListIndexes,
        obj: v4);
      str = this->devMenuList->devMenuList.list[*v4].devMenuSubList->name.str;
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->devMapListNames,
        obj: (encounterGroupRole_t *)&str);
      *v4 = ROLE_NONE;
LABEL_12:
      idMainMenu::UpdateMenuDisplay(this, menu: MENU_DEV);
    }
  }
}


// ========================================================================
// ?UpdateMenu_Dev@idMainMenu@@QAAXXZ
// EA  : 0x82DBE158
// RVA : 0x00DBE158
// PDB : w:\tech5\tungsten\game\mainmenulocal_dev.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateMenu_Dev(idMainMenu *this)
{
  const idDeclDevMenuList *v2; // r3
  const idDeclDevMenuList *devMenuList; // r11
  __int64 v4; // r10
  __int64 v5; // r6
  __int64 v6; // r8
  int i; // r22
  va *v8; // r3
  idSWFScriptObject *NestedObj; // r29
  int v10; // r11
  int v11; // r28
  idSWFTextInstance *str; // r30
  idStr *v13; // r3
  idSWFSpriteInstance *v14; // r30
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r6
  idSWFScriptFunction *v18; // r3
  idSWF *mainMenu; // r11
  idSWFScriptFunction *v20; // r4
  idSWFScriptVar *v21; // r3
  int v22; // [sp+8h] [-11E8h]
  int v23; // [sp+Ch] [-11E4h]
  int v24; // [sp+10h] [-11E0h]
  int v25; // [sp+14h] [-11DCh]
  int v26; // [sp+18h] [-11D8h]
  int v27; // [sp+1Ch] [-11D4h]
  int num; // [sp+50h] [-11A0h]
  idSWFScriptVar v29; // [sp+58h] [-1198h] BYREF
  idSWFScriptVar v30; // [sp+60h] [-1190h] BYREF
  idSWFScriptVar v31; // [sp+68h] [-1188h] BYREF
  idSWFScriptObject v32[2]; // [sp+70h] [-1180h] BYREF
  va v33; // [sp+140h] [-10B0h] BYREF

  num = this->devMapListNames.num;
  v32[0].variables.num = (int)this->mainMenu->mainspriteInstance->scriptObject;
  if ( num != 0 )
  {
    v2 = (const idDeclDevMenuList *)idResourceList::Load(
                                      this: &idDeclDevMenuList::resourceList,
                                      name: (char *)this->devMapListNames.list[num - 1],
                                      makeDefault: false,
                                      skipStaleCheck: false);
    if ( v2 != nullptr )
      this->devMenuList = v2;
  }
  devMenuList = this->devMenuList;
  this->numOptions[2] = 0;
  if ( devMenuList != nullptr )
    this->numOptions[2] = devMenuList->devMenuList.num;
  LODWORD(v4) = &unk_82340000;
  HIDWORD(v4) = 0x82000000;
  LODWORD(v6) = allocationCurrent[242];
  LODWORD(v5) = &unk_82340000;
  HIDWORD(v6) = "optionType";
  for ( i = 0; i < 13; ++i )
  {
    HIDWORD(v5) = i;
    v8 = va::va(
           this: &v33,
           fmt: "option%d",
           a3: v5,
           a4: v6,
           a5: v4,
           a6: v22,
           a7: v23,
           a8: v24,
           a9: v25,
           a10: v26,
           a11: v27);
    NestedObj = idSWFScriptObject::GetNestedObj(
                  this: (idSWFScriptObject *)v32[0].variables.num,
                  arg1: "devMenu",
                  arg2: "options",
                  arg3: v8->buffer,
                  arg4: nullptr,
                  arg5: nullptr,
                  arg6: nullptr);
    if ( NestedObj != nullptr )
    {
      v10 = this->menuIndex[2];
      v11 = v10 + i;
      if ( i > 6 )
        v11 = v10 - i + 6;
      if ( v11 < 0 || v11 >= this->numOptions[2] )
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
        v21 = &v30;
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
          v13 = idStr::idStr(
                  this: (idStr *)&v32[0].variablesHash[3],
                  text: this->devMenuList->devMenuList.list[v11].devMenuDisplayName.data);
          idSWFTextInstance::SetText(this: str, val: v13);
          idSWFTextInstance::SetStrokeInfo(this: str, use: true, strength: 0.75, weight: 2.0);
        }
        idSWFScriptObject::Get(
          this: (idSWFScriptObject *)&v32[0].variables.granularity,
          result: NestedObj,
          name: "optionType");
        v14 = idSWFScriptVar::ToSprite(this: (idSWFScriptVar *)&v32[0].variables.granularity);
        if ( v14 != nullptr )
        {
          idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v32[0].variablesHash[11]);
          idSWFParmList::Append(
            this: (idSWFParmList *)&v32[0].variablesHash[11],
            i: (idSWFScriptVar::swfScriptVarValue_t *)1);
          idSWFSpriteInstance::StopFrame(
            this: v14,
            parms: (const idSWFParmList *)&v32[0].variablesHash[11],
            a3: v17,
            a4: v16,
            a5: v15);
          idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v32[0].variablesHash[11]);
        }
        v18 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x14u,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
        if ( v18 != nullptr )
        {
          mainMenu = this->mainMenu;
          v20 = v18;
          v18[3].__vftable = (idSWFScriptFunction_vtbl *)this;
          v18[4].__vftable = (idSWFScriptFunction_vtbl *)v11;
          v18[1].__vftable = nullptr;
          v18->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateMenu_Dev'::`24'::idSWFScriptFunction_accept::`vftable';
          v18[2].__vftable = (idSWFScriptFunction_vtbl *)mainMenu;
        }
        else
        {
          v20 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v32[0].variablesHash[1], nf: v20);
        idSWFScriptObject::Set(this: NestedObj, name: "onPress", value: (idSWFScriptVar *)&v32[0].variablesHash[1]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v32[0].variablesHash[1]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v32[0].variables.granularity);
        v21 = (idSWFScriptVar *)v32;
      }
      idSWFScriptVar::Free(this: v21);
    }
  }
  if ( this->activeMenu == MENU_DEV )
  {
    idStr::operator=(this: &this->btn1Text, text: "#STR_SWF_SELECT");
    idStr::operator=(this: &this->btn2Text, text: "#STR_SWF_BACK");
  }
  idMainMenu::UpdateButtonBar(this);
}


// ========================================================================
// __unwind$488560_0
// EA  : 0x82DBE4D8
// RVA : 0x00DBE4D8
// PDB : w:\tech5\tungsten\game\mainmenulocal_dev.cpp
// ========================================================================

void _unwind_488560_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4592 + 88));
}


// ========================================================================
// __unwind$488561_0
// EA  : 0x82DBE500
// RVA : 0x00DBE500
// PDB : w:\tech5\tungsten\game\mainmenulocal_dev.cpp
// ========================================================================

void _unwind_488561_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4592 + 112));
}


// ========================================================================
// __unwind$488563_0
// EA  : 0x82DBE528
// RVA : 0x00DBE528
// PDB : w:\tech5\tungsten\game\mainmenulocal_dev.cpp
// ========================================================================

void _unwind_488563_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4592 + 128));
}


// ========================================================================
// __unwind$488564_1
// EA  : 0x82DBE550
// RVA : 0x00DBE550
// PDB : w:\tech5\tungsten\game\mainmenulocal_dev.cpp
// ========================================================================

void _unwind_488564_1()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 4592 + 176));
}


// ========================================================================
// __unwind$488566
// EA  : 0x82DBE578
// RVA : 0x00DBE578
// PDB : w:\tech5\tungsten\game\mainmenulocal_dev.cpp
// ========================================================================

void _unwind_488566()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4592 + 136));
}


// ========================================================================
// __unwind$488558_0
// EA  : 0x82DBE5A0
// RVA : 0x00DBE5A0
// PDB : w:\tech5\tungsten\game\mainmenulocal_dev.cpp
// ========================================================================

void _unwind_488558_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4592 + 104));
}


// ========================================================================
// __unwind$488559_0
// EA  : 0x82DBE5C8
// RVA : 0x00DBE5C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_dev.cpp
// ========================================================================

void _unwind_488559_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4592 + 96));
}

