
// ========================================================================
// ?CommitAudioSettings@idMainMenu@@QAAXXZ
// EA  : 0x82DBC830
// RVA : 0x00DBC830
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void __fastcall idMainMenu::CommitAudioSettings(idMainMenu *this)
{
  double audioMasterVolume; // fp30
  idPlayerProfileGame *v3; // r3
  double audioMusicVolume; // fp30
  idPlayerProfileGame *v5; // r3
  double audioVoiceVolume; // fp30
  idPlayerProfileGame *v7; // r3
  double audioAmbientVolume; // fp30
  idPlayerProfileGame *v9; // r3
  idPlayerProfile *v10; // r3
  bool v11; // r11

  audioMasterVolume = this->audioMasterVolume;
  v3 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v3 != nullptr )
    idPlayerProfileGame::SetMasterVolume(this: v3, val: (float)((float)audioMasterVolume * (float)0.0099999998));
  audioMusicVolume = this->audioMusicVolume;
  v5 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v5 != nullptr )
    idPlayerProfileGame::SetMusicVolume(this: v5, val: (float)((float)audioMusicVolume * (float)0.0099999998));
  audioVoiceVolume = this->audioVoiceVolume;
  v7 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v7 != nullptr )
    idPlayerProfileGame::SetVoiceVolume(this: v7, val: (float)((float)audioVoiceVolume * (float)0.0099999998));
  audioAmbientVolume = this->audioAmbientVolume;
  v9 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v9 != nullptr )
    idPlayerProfileGame::SetAmbientVolume(this: v9, val: (float)((float)audioAmbientVolume * (float)0.0099999998));
  v10 = common->GetProfileFromMasterLocalUser(this: common);
  if ( v10 != nullptr )
    HIBYTE(v10[1].__vftable) = this->audioSubtitles;
  if ( this->audioMasterVolume == this->audioMasterVolume_Restore )
  {
    if ( this->audioMusicVolume == this->audioMusicVolume_Restore )
      v11 = this->audioAmbientVolume != this->audioAmbientVolume_Restore
         || this->audioVoiceVolume != this->audioVoiceVolume_Restore
         || this->audioSubtitles_Restore != this->audioSubtitles;
    else
      v11 = true;
  }
  else
  {
    v11 = true;
  }
  if ( v11 )
    idMainMenu::SaveSettings(this);
}


// ========================================================================
// ?InitializeAudioValues@idMainMenu@@QAAXXZ
// EA  : 0x82DBC9C8
// RVA : 0x00DBC9C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void __fastcall idMainMenu::InitializeAudioValues(idMainMenu *this)
{
  idPlayerProfileGame *v2; // r3
  double v3; // fp0
  idPlayerProfileGame *v4; // r3
  double v5; // fp0
  idPlayerProfileGame *v6; // r3
  double v7; // fp0
  idPlayerProfileGame *v8; // r3
  double v9; // fp0
  idPlayerProfile *v10; // r3
  char v11; // r11
  double audioMasterVolume; // fp0
  double audioMusicVolume; // fp13
  double audioVoiceVolume; // fp12
  double audioAmbientVolume; // fp11

  v2 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v2 != nullptr )
    v3 = (float)(idPlayerProfileGame::GetMasterVolume(this: v2) * (float)100.0);
  else
    v3 = 0.0;
  this->audioMasterVolume = v3;
  v4 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v4 != nullptr )
    v5 = (float)(idPlayerProfileGame::GetMusicVolume(this: v4) * (float)100.0);
  else
    v5 = 0.0;
  this->audioMusicVolume = v5;
  v6 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v6 != nullptr )
    v7 = (float)(idPlayerProfileGame::GetVoiceVolume(this: v6) * (float)100.0);
  else
    v7 = 0.0;
  this->audioVoiceVolume = v7;
  v8 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v8 != nullptr )
    v9 = (float)(idPlayerProfileGame::GetAmbientVolume(this: v8) * (float)100.0);
  else
    v9 = 0.0;
  this->audioAmbientVolume = v9;
  v10 = common->GetProfileFromMasterLocalUser(this: common);
  if ( v10 != nullptr )
    v11 = HIBYTE(v10[1].__vftable);
  else
    v11 = 0;
  audioMasterVolume = this->audioMasterVolume;
  this->audioSubtitles = v11;
  audioMusicVolume = this->audioMusicVolume;
  this->audioSubtitles_Restore = v11;
  audioVoiceVolume = this->audioVoiceVolume;
  audioAmbientVolume = this->audioAmbientVolume;
  this->audioMasterVolume_Restore = audioMasterVolume;
  this->audioMusicVolume_Restore = audioMusicVolume;
  this->audioVoiceVolume_Restore = audioVoiceVolume;
  this->audioAmbientVolume_Restore = audioAmbientVolume;
}


// ========================================================================
// ?HandleMenu_Audio@idMainMenu@@QAAXW4mainMenuTransition_t@@@Z
// EA  : 0x82DBCB30
// RVA : 0x00DBCB30
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void __fastcall idMainMenu::HandleMenu_Audio(idMainMenu *this, mainMenuTransition_t type)
{
  if ( type == MENU_TRANSITION_BACK )
  {
    this->menuTransition = MENU_TRANSITION_BACK;
    idMainMenu::CommitAudioSettings(this);
    idMainMenu::ClearCmdButtons(this);
    idMainMenu::UpdateButtonBar(this);
    idMainMenu::SetActiveMenu(this, newMenuArea: MENU_SETTINGS);
  }
}


// ========================================================================
// `idMainMenu::UpdateMenu_Audio'::`18'::idSWFScriptFunction_accept::Call
// EA  : 0x82DBCB90
// RVA : 0x00DBCB90
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::UpdateMenu_Audio_::_18_::idSWFScriptFunction_accept::Call(
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
    v6 = size->menuIndex[6];
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
// ?UpdateAdjustmentCmds@idMainMenu@@QAAXPBD@Z
// EA  : 0x82DBCC38
// RVA : 0x00DBCC38
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateAdjustmentCmds(idMainMenu *this, const char *menuName)
{
  idSWFScriptObject *NestedObj; // r4
  idSWFScriptObject *v4; // r29
  int v5; // r11
  int *v6; // r3
  idSWFScriptFunction *v7; // r3
  idSWFScriptFunction *v8; // r4
  idSWFScriptFunction *v9; // r3
  idSWFScriptFunction *v10; // r4
  int *v11; // r3
  idSWFScriptFunction *v12; // r3
  idSWFScriptFunction *v13; // r4
  idSWFScriptFunction *v14; // r3
  idSWFScriptFunction *v15; // r4
  idSWFScriptFunction *v16; // r3
  idSWF *mainMenu; // r11
  idSWFScriptFunction *v18; // r4
  idSWFScriptFunction *v19; // r3
  idSWF *v20; // r11
  idSWFScriptFunction *v21; // r4
  idSWFScriptObject v22; // [sp+50h] [-A0h] BYREF

  NestedObj = idSWFScriptObject::GetNestedObj(
                this: this->mainMenu->mainspriteInstance->scriptObject,
                arg1: menuName,
                arg2: "options",
                arg3: "option0",
                arg4: "optionType",
                arg5: nullptr,
                arg6: nullptr);
  if ( NestedObj != nullptr )
  {
    v4 = nullptr;
    v5 = this->optionTypes.list[this->menuIndex[this->activeMenu]];
    if ( v5 == 1 )
    {
      idSWFScriptObject::Get(this: (idSWFScriptObject *)&v22.variablesHash[1], result: NestedObj, name: "slider");
      if ( v22.variablesHash[1] == 8 )
        v4 = (idSWFScriptObject *)v22.variablesHash[2];
      v6 = &v22.variablesHash[1];
    }
    else
    {
      if ( v5 != 2 )
        return;
      idSWFScriptObject::Get(this: (idSWFScriptObject *)&v22.variablesHash[3], result: NestedObj, name: "txtInfo");
      if ( v22.variablesHash[3] == 8 )
        v4 = (idSWFScriptObject *)v22.variablesHash[4];
      v6 = &v22.variablesHash[3];
    }
    idSWFScriptVar::Free(this: (idSWFScriptVar *)v6);
    if ( v4 != nullptr )
    {
      idSWFScriptObject::Get(this: (idSWFScriptObject *)&v22.variables.num, result: v4, name: "btnLess");
      idSWFScriptObject::Get(this: &v22, result: v4, name: "btnMore");
      if ( v22.variables.num == 8 && v22.refCount == 8 )
      {
        if ( this->activeMenu == MENU_AUDIO )
        {
          if ( this->menuIndex[6] >= 4 )
          {
            v12 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                           size: 0x14u,
                                           tag: TAG_SWF,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
            if ( v12 != nullptr )
            {
              v12[2].__vftable = (idSWFScriptFunction_vtbl *)this;
              v12->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateAdjustmentCmds'::`25'::idSWFScriptFunction_adjustSetting::`vftable';
              v13 = v12;
              v12[1].__vftable = nullptr;
              HIBYTE(v12[3].__vftable) = 1;
              v12[4].__vftable = (idSWFScriptFunction_vtbl *)4;
            }
            else
            {
              v13 = nullptr;
            }
            idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v22.variablesHash[9], nf: v13);
            idSWFScriptObject::Set(
              this: (idSWFScriptObject *)v22.variables.size,
              name: "onPress",
              value: (idSWFScriptVar *)&v22.variablesHash[9]);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v22.variablesHash[9]);
            v14 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                           this: &mem,
                                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                           size: 0x14u,
                                           tag: TAG_SWF,
                                           zeroBuffer: false,
                                           align: ALIGN_16,
                                           heap: HEAP_DEFAULTHEAP);
            if ( v14 != nullptr )
            {
              v14[2].__vftable = (idSWFScriptFunction_vtbl *)this;
              v15 = v14;
              v14->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateAdjustmentCmds'::`25'::idSWFScriptFunction_adjustSetting::`vftable';
              v14[1].__vftable = nullptr;
              HIBYTE(v14[3].__vftable) = 0;
              v14[4].__vftable = (idSWFScriptFunction_vtbl *)4;
            }
            else
            {
              v15 = nullptr;
            }
            idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v22.variablesHash[11], nf: v15);
            idSWFScriptObject::Set(
              this: (idSWFScriptObject *)v22.variables.list,
              name: "onPress",
              value: (idSWFScriptVar *)&v22.variablesHash[11]);
            v11 = &v22.variablesHash[11];
          }
          else
          {
            v7 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                          size: 0x14u,
                                          tag: TAG_SWF,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
            if ( v7 != nullptr )
            {
              v7[2].__vftable = (idSWFScriptFunction_vtbl *)this;
              v7->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateAdjustmentCmds'::`25'::idSWFScriptFunction_adjustSetting::`vftable';
              v8 = v7;
              v7[1].__vftable = nullptr;
              HIBYTE(v7[3].__vftable) = 1;
              v7[4].__vftable = (idSWFScriptFunction_vtbl *)2;
            }
            else
            {
              v8 = nullptr;
            }
            idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v22.variablesHash[5], nf: v8);
            idSWFScriptObject::Set(
              this: (idSWFScriptObject *)v22.variables.size,
              name: "onPress",
              value: (idSWFScriptVar *)&v22.variablesHash[5]);
            idSWFScriptVar::Free(this: (idSWFScriptVar *)&v22.variablesHash[5]);
            v9 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                          size: 0x14u,
                                          tag: TAG_SWF,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
            if ( v9 != nullptr )
            {
              v9[2].__vftable = (idSWFScriptFunction_vtbl *)this;
              v10 = v9;
              v9->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateAdjustmentCmds'::`25'::idSWFScriptFunction_adjustSetting::`vftable';
              v9[1].__vftable = nullptr;
              HIBYTE(v9[3].__vftable) = 0;
              v9[4].__vftable = (idSWFScriptFunction_vtbl *)2;
            }
            else
            {
              v10 = nullptr;
            }
            idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v22.variablesHash[7], nf: v10);
            idSWFScriptObject::Set(
              this: (idSWFScriptObject *)v22.variables.list,
              name: "onPress",
              value: (idSWFScriptVar *)&v22.variablesHash[7]);
            v11 = &v22.variablesHash[7];
          }
          idSWFScriptVar::Free(this: (idSWFScriptVar *)v11);
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
          mainMenu = this->mainMenu;
          v18 = v16;
          v16[3].__vftable = (idSWFScriptFunction_vtbl *)this;
          v16[1].__vftable = nullptr;
          v16->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateAdjustmentCmds'::`26'::idSWFScriptFunction_release::`vftable';
          v16[2].__vftable = (idSWFScriptFunction_vtbl *)mainMenu;
        }
        else
        {
          v18 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v22.variablesHash[13], nf: v18);
        idSWFScriptObject::Set(
          this: (idSWFScriptObject *)v22.variables.size,
          name: "onRelease",
          value: (idSWFScriptVar *)&v22.variablesHash[13]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v22.variablesHash[13]);
        v19 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x10u,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
        if ( v19 != nullptr )
        {
          v20 = this->mainMenu;
          v21 = v19;
          v19[3].__vftable = (idSWFScriptFunction_vtbl *)this;
          v19[1].__vftable = nullptr;
          v19->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateAdjustmentCmds'::`26'::idSWFScriptFunction_release::`vftable';
          v19[2].__vftable = (idSWFScriptFunction_vtbl *)v20;
        }
        else
        {
          v21 = nullptr;
        }
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v22.variablesHash[15], nf: v21);
        idSWFScriptObject::Set(
          this: (idSWFScriptObject *)v22.variables.list,
          name: "onRelease",
          value: (idSWFScriptVar *)&v22.variablesHash[15]);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v22.variablesHash[15]);
        idSWF::GetGlobal(
          this: (idSWF *)&v22.variables.granularity,
          result: (idSWFScriptVar *)this->mainMenu,
          name: "shortcutKeys");
        if ( *(_DWORD *)&v22.variables.granularity == 8 )
        {
          idSWFScriptObject::Set(
            this: (idSWFScriptObject *)v22.variablesHash[0],
            name: "STICK1_RIGHT",
            value: (idSWFScriptVar *)&v22);
          idSWFScriptObject::Set(
            this: (idSWFScriptObject *)v22.variablesHash[0],
            name: "RIGHT",
            value: (idSWFScriptVar *)&v22);
          idSWFScriptObject::Set(
            this: (idSWFScriptObject *)v22.variablesHash[0],
            name: "STICK1_LEFT",
            value: (idSWFScriptVar *)&v22.variables.num);
          idSWFScriptObject::Set(
            this: (idSWFScriptObject *)v22.variablesHash[0],
            name: "LEFT",
            value: (idSWFScriptVar *)&v22.variables.num);
        }
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v22.variables.granularity);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v22);
      }
      else
      {
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v22);
      }
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v22.variables.num);
    }
  }
}


// ========================================================================
// __unwind$488893
// EA  : 0x82DBD0C8
// RVA : 0x00DBD0C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_488893()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 88));
}


// ========================================================================
// __unwind$488894
// EA  : 0x82DBD0F0
// RVA : 0x00DBD0F0
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_488894()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$488896_0
// EA  : 0x82DBD118
// RVA : 0x00DBD118
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_488896_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 120));
}


// ========================================================================
// __unwind$488898
// EA  : 0x82DBD140
// RVA : 0x00DBD140
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_488898()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$488900
// EA  : 0x82DBD168
// RVA : 0x00DBD168
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_488900()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 136));
}


// ========================================================================
// __unwind$488902
// EA  : 0x82DBD190
// RVA : 0x00DBD190
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_488902()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 144));
}


// ========================================================================
// __unwind$488904
// EA  : 0x82DBD1B8
// RVA : 0x00DBD1B8
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_488904()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 152));
}


// ========================================================================
// __unwind$488906
// EA  : 0x82DBD1E0
// RVA : 0x00DBD1E0
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_488906()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 160));
}


// ========================================================================
// __unwind$488907
// EA  : 0x82DBD208
// RVA : 0x00DBD208
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_488907()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 96));
}


// ========================================================================
// `idMainMenu::UpdateAdjustmentCmds'::`24'::idSWFScriptFunction_onEnterFrame::Call
// EA  : 0x82DBD230
// RVA : 0x00DBD230
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::UpdateAdjustmentCmds_::_24_::idSWFScriptFunction_onEnterFrame::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *num; // r3

  num = (idMainMenu *)thisObject->variables.num;
  if ( HIBYTE(thisObject->variablesHash[0]) != 0 )
  {
    if ( num != nullptr )
      idMainMenu::SetScrollSpeed(this: num, index: *(_DWORD *)&thisObject->variables.granularity);
    HIBYTE(thisObject->variablesHash[0]) = 0;
    result->type = SWF_VAR_UNDEF;
    return result;
  }
  else
  {
    if ( num != nullptr && (unsigned __int8)idMainMenu::CanScrollMenu(this: num) != 0 )
      idMainMenu::AdjustSetting(this: (idMainMenu *)thisObject->variables.num, less: HIBYTE(thisObject->variables.size));
    result->type = SWF_VAR_UNDEF;
    return result;
  }
}


// ========================================================================
// `idMainMenu::UpdateAdjustmentCmds'::`25'::idSWFScriptFunction_adjustSetting::Call
// EA  : 0x82DBD2C0
// RVA : 0x00DBD2C0
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::UpdateAdjustmentCmds_::_25_::idSWFScriptFunction_adjustSetting::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *num; // r3
  idSWFScriptObject *ActiveMenu; // r28
  idSWFScriptFunction *v7; // r3
  idSWFScriptFunction_vtbl *v8; // r11
  char size_high; // r9
  int v10; // r7
  idSWFScriptFunction *v11; // r4
  idSWFScriptVar v13[8]; // [sp+50h] [-40h] BYREF

  num = (idMainMenu *)thisObject->variables.num;
  v13[0].type = SWF_VAR_STRINGID;
  if ( num != nullptr )
  {
    idMainMenu::SetScrollSpeed(this: num, index: -1);
    idMainMenu::CanScrollMenu(this: (idMainMenu *)thisObject->variables.num);
    idMainMenu::AdjustSetting(this: (idMainMenu *)thisObject->variables.num, less: HIBYTE(thisObject->variables.size));
    ActiveMenu = idMainMenu::GetActiveMenu(this: (idMainMenu *)thisObject->variables.num);
    if ( ActiveMenu != nullptr )
    {
      v7 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x18u,
                                    tag: TAG_SWF,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
      if ( v7 != nullptr )
      {
        v8 = *(idSWFScriptFunction_vtbl **)&thisObject->variables.granularity;
        size_high = HIBYTE(thisObject->variables.size);
        v10 = thisObject->variables.num;
        v7[1].__vftable = nullptr;
        v11 = v7;
        v7->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateAdjustmentCmds'::`24'::idSWFScriptFunction_onEnterFrame::`vftable';
        v7[4].__vftable = v8;
        HIBYTE(v7[3].__vftable) = size_high;
        v7[2].__vftable = (idSWFScriptFunction_vtbl *)v10;
        HIBYTE(v7[5].__vftable) = 1;
      }
      else
      {
        v11 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: v13, nf: v11);
      idSWFScriptObject::Set(this: ActiveMenu, name: "onEnterFrame", value: v13);
      idSWFScriptVar::Free(this: v13);
    }
  }
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// __unwind$489223
// EA  : 0x82DBD3C0
// RVA : 0x00DBD3C0
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_489223()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 144 + 80));
}


// ========================================================================
// ?UpdateCmds_Audio@idMainMenu@@QAAXXZ
// EA  : 0x82DBD3E8
// RVA : 0x00DBD3E8
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateCmds_Audio(idMainMenu *this)
{
  idSWFScriptObject *scriptObject; // r29
  idSWFScriptObject *NestedObj; // r28
  idSWFScriptObject *v4; // r3

  scriptObject = this->mainMenu->mainspriteInstance->scriptObject;
  NestedObj = idSWFScriptObject::GetNestedObj(
                this: scriptObject,
                arg1: "audioMenu",
                arg2: "btnUp",
                arg3: nullptr,
                arg4: nullptr,
                arg5: nullptr,
                arg6: nullptr);
  v4 = idSWFScriptObject::GetNestedObj(
         this: scriptObject,
         arg1: "audioMenu",
         arg2: "btnDown",
         arg3: nullptr,
         arg4: nullptr,
         arg5: nullptr,
         arg6: nullptr);
  idMainMenu::UpdateScrollCmds(this, btnUp: NestedObj, btnDown: v4);
  idMainMenu::UpdateAcceptBackCmds(this);
  idMainMenu::UpdateAdjustmentCmds(this, menuName: "audioMenu");
}


// ========================================================================
// `idMainMenu::UpdateAdjustmentCmds'::`26'::idSWFScriptFunction_release::Call
// EA  : 0x82DBD490
// RVA : 0x00DBD490
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::UpdateAdjustmentCmds_::_26_::idSWFScriptFunction_release::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int num; // r11
  idSWFScriptObject *ActiveMenu; // r30
  idSWFScriptVar v7[8]; // [sp+50h] [-40h] BYREF

  num = thisObject->variables.num;
  v7[0].type = SWF_VAR_STRINGID;
  if ( num != 0 )
  {
    ActiveMenu = idMainMenu::GetActiveMenu(this: (idMainMenu *)thisObject->variables.size);
    if ( ActiveMenu != nullptr )
    {
      v7[0].type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: v7);
      v7[0].value.i = 0;
      v7[0].type = SWF_VAR_INTEGER;
      idSWFScriptObject::Set(this: ActiveMenu, name: "onEnterFrame", value: v7);
      idSWFScriptVar::Free(this: v7);
    }
  }
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// __unwind$489345_0
// EA  : 0x82DBD514
// RVA : 0x00DBD514
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_489345_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 144 + 80));
}


// ========================================================================
// ?DisplayAudioValues@idMainMenu@@QAAXH_N0@Z
// EA  : 0x82DBD548
// RVA : 0x00DBD548
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void __fastcall idMainMenu::DisplayAudioValues(idMainMenu *this, int index, __int64 set, __int64 a4)
{
  idSWFScriptVar::swfScriptVarValue_t v4; // r29
  bool audioSubtitles; // r28
  __int64 v6; // r11
  idSWFScriptVar::swfScriptVarValue_t v7; // r11
  int v8; // r11
  __int64 v9; // r10
  idSWFScriptObject *v10; // r30
  va *v11; // r3
  idSWFSpriteInstance *NestedSprite; // r30
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  int v16; // r11
  __int64 v17; // r10
  idSWFScriptObject *v18; // r30
  va *v19; // r3
  idSWFScriptObject *NestedObj; // r30
  idSWFScriptVar *v21; // r3
  idSWFTextInstance *text; // r3
  int v23; // [sp+8h] [-1118h]
  int v24; // [sp+Ch] [-1114h]
  int v25; // [sp+10h] [-1110h]
  int v26; // [sp+14h] [-110Ch]
  int v27; // [sp+18h] [-1108h]
  int v28; // [sp+1Ch] [-1104h]
  __int64 v29; // [sp+50h] [-10D0h] BYREF
  idSWFScriptVar v30; // [sp+58h] [-10C8h] BYREF
  idStaticList<idSWFScriptVar,16> v31; // [sp+60h] [-10C0h] BYREF
  va v32; // [sp+F0h] [-1030h] BYREF

  v4.i = 0;
  audioSubtitles = false;
  if ( index != 0 )
  {
    switch ( index )
    {
      case 1:
        LODWORD(v29) = (int)this->audioMusicVolume;
        v4.i = v29;
        break;
      case 2:
        LODWORD(v29) = (int)this->audioVoiceVolume;
        v4.i = v29;
        break;
      case 3:
        LODWORD(v29) = (int)this->audioAmbientVolume;
        v4.i = v29;
        break;
      case 4:
        audioSubtitles = this->audioSubtitles;
        break;
      default:
        break;
    }
  }
  else
  {
    LODWORD(v29) = (int)this->audioMasterVolume;
    v4.i = v29;
  }
  HIDWORD(v6) = 4 * index;
  LODWORD(v6) = this->optionTypes.list[index];
  if ( (_DWORD)v6 == 1 )
  {
    if ( (_BYTE)set == 0 )
    {
LABEL_26:
      LODWORD(v9) = this->mainMenu;
      v8 = this->menuIndex[6];
      HIDWORD(v9) = *(_DWORD *)(v9 + 64);
      v10 = *(idSWFScriptObject **)(HIDWORD(v9) + 40);
      if ( index >= v8 )
        HIDWORD(set) = index - v8;
      else
        HIDWORD(set) = v8 - index + 6;
      v11 = va::va(
              this: &v32,
              fmt: "option%d",
              a3: set,
              a4,
              a5: v9,
              a6: v23,
              a7: v24,
              a8: v25,
              a9: v26,
              a10: v27,
              a11: v28);
      NestedSprite = idSWFScriptObject::GetNestedSprite(
                       this: v10,
                       arg1: "audioMenu",
                       arg2: "options",
                       arg3: v11->buffer,
                       arg4: "optionType",
                       arg5: "slider",
                       arg6: "bar");
      if ( NestedSprite != nullptr )
      {
        idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v31);
        idSWFParmList::Append(this: (idSWFParmList *)&v31, i: (idSWFScriptVar::swfScriptVarValue_t *)(v4.i + 1));
        idSWFSpriteInstance::StopFrame(
          this: NestedSprite,
          parms: (const idSWFParmList *)&v31,
          a3: v15,
          a4: v14,
          a5: v13);
        idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v31);
      }
      return;
    }
    if ( BYTE3(set) != 0 )
    {
      v7.i = v4.i - 1;
      if ( v4.i - 1 < 0 )
        goto LABEL_18;
    }
    else
    {
      v7.i = v4.i + 1;
      if ( v4.i + 1 > 100 )
        goto LABEL_18;
    }
    v4.f = v7.f;
LABEL_18:
    if ( index != 0 )
    {
      switch ( index )
      {
        case 1:
          LODWORD(v6) = v4;
          v29 = v6;
          this->audioMusicVolume = (float)v6;
          break;
        case 2:
          LODWORD(v6) = v4;
          v29 = v6;
          this->audioVoiceVolume = (float)v6;
          break;
        case 3:
          LODWORD(v6) = v4;
          v29 = v6;
          this->audioAmbientVolume = (float)v6;
          break;
        default:
          break;
      }
    }
    else
    {
      LODWORD(v6) = v4;
      v29 = v6;
      this->audioMasterVolume = (float)v6;
    }
    goto LABEL_26;
  }
  if ( (_DWORD)v6 == 2 )
  {
    if ( (_BYTE)set != 0 )
    {
      if ( index == 4 )
        this->audioSubtitles = (_cntlzw(this->audioSubtitles) & 0x20) != 0;
      audioSubtitles = (_cntlzw(audioSubtitles) & 0x20) != 0;
    }
    v16 = this->menuIndex[6];
    if ( index >= v16 )
      HIDWORD(set) = index - v16;
    else
      HIDWORD(set) = v16 - index + 6;
    LODWORD(v17) = &unk_82340000;
    HIDWORD(v17) = this->mainMenu->mainspriteInstance;
    v18 = *(idSWFScriptObject **)(HIDWORD(v17) + 40);
    v19 = va::va(
            this: &v32,
            fmt: "option%d",
            a3: set,
            a4,
            a5: v17,
            a6: v23,
            a7: v24,
            a8: v25,
            a9: v26,
            a10: v27,
            a11: v28);
    NestedObj = idSWFScriptObject::GetNestedObj(
                  this: v18,
                  arg1: "audioMenu",
                  arg2: "options",
                  arg3: v19->buffer,
                  arg4: "optionType",
                  arg5: "txtInfo",
                  arg6: "txtVal");
    if ( NestedObj != nullptr )
    {
      if ( audioSubtitles )
      {
        idSWFScriptVar::idSWFScriptVar(this: &v30, s: "ENABLED");
        idSWFScriptObject::Set(this: NestedObj, name: "text", value: &v30);
        v21 = &v30;
      }
      else
      {
        idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v29, s: "DISABLED");
        idSWFScriptObject::Set(this: NestedObj, name: "text", value: (idSWFScriptVar *)&v29);
        v21 = (idSWFScriptVar *)&v29;
      }
      idSWFScriptVar::Free(this: v21);
      if ( NestedObj->objectType == SWF_OBJECT_TEXT )
      {
        text = NestedObj->data.text;
        if ( text != nullptr )
          idSWFTextInstance::SetStrokeInfo(this: text, use: true, strength: 2.0, weight: 0.75);
      }
    }
  }
}


// ========================================================================
// __unwind$489470
// EA  : 0x82DBD8A4
// RVA : 0x00DBD8A4
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_489470()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 4384 + 96));
}


// ========================================================================
// __unwind$489471_0
// EA  : 0x82DBD8CC
// RVA : 0x00DBD8CC
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_489471_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4384 + 88));
}


// ========================================================================
// __unwind$489472_0
// EA  : 0x82DBD8F4
// RVA : 0x00DBD8F4
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_489472_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4384 + 80));
}


// ========================================================================
// ?UpdateMenu_Audio@idMainMenu@@QAAXXZ
// EA  : 0x82DBD928
// RVA : 0x00DBD928
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateMenu_Audio(idMainMenu *this)
{
  idList<int,5> *p_optionTypes; // r20
  idSWFSpriteInstance *mainspriteInstance; // r5
  int scriptObject; // r9
  __int64 v5; // r6
  __int64 v6; // r10
  __int64 v7; // r8
  int v8; // r23
  va *v9; // r3
  idSWFScriptObject *NestedObj; // r28
  int v11; // r11
  int v12; // r30
  __int64 v13; // r8
  double TextLength; // fp31
  idSWFTextInstance *str; // r29
  idStr *v16; // r3
  __int64 v17; // r10
  int v18; // r8
  int v19; // r7
  int v20; // r6
  int v21; // r5
  int v22; // r4
  idSWFScriptFunction *v23; // r3
  idSWF *mainMenu; // r11
  idSWFScriptFunction *v25; // r4
  idSWFSpriteInstance *v26; // r29
  int v27; // r30
  __int64 v28; // r10
  __int64 v29; // r8
  __int64 v30; // r6
  int v31; // r11
  int v32; // [sp+8h] [-1218h]
  int v33; // [sp+Ch] [-1214h]
  int v34; // [sp+10h] [-1210h]
  int v35; // [sp+14h] [-120Ch]
  int v36; // [sp+18h] [-1208h]
  int v37; // [sp+1Ch] [-1204h]
  idMem *v38[2]; // [sp+50h] [-11D0h] BYREF
  idSWFScriptVar v39; // [sp+58h] [-11C8h] BYREF
  idSWFScriptVar v40; // [sp+60h] [-11C0h] BYREF
  idSWFScriptVar v41; // [sp+68h] [-11B8h] BYREF
  idSWFScriptObject v42; // [sp+70h] [-11B0h] BYREF
  idStaticList<idSWFScriptVar,16> v43; // [sp+D0h] [-1150h] BYREF
  va v44; // [sp+160h] [-10C0h] BYREF

  p_optionTypes = &this->optionTypes;
  mainspriteInstance = this->mainMenu->mainspriteInstance;
  v42.variablesHash[4] = (int)"MUSIC";
  scriptObject = (int)mainspriteInstance->scriptObject;
  v42.variablesHash[3] = (int)"MASTER";
  v42.variablesHash[5] = (int)"VOICE";
  v42.variablesHash[6] = (int)"AMBIENT";
  v42.variablesHash[7] = (int)"SUBTITLES";
  v42.variables.num = scriptObject;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->optionTypes);
  v38[0] = (idMem *)1;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)p_optionTypes,
    obj: (encounterGroupRole_t *)v38);
  v38[0] = (idMem *)1;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)p_optionTypes,
    obj: (encounterGroupRole_t *)v38);
  v38[0] = (idMem *)1;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)p_optionTypes,
    obj: (encounterGroupRole_t *)v38);
  v38[0] = (idMem *)1;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)p_optionTypes,
    obj: (encounterGroupRole_t *)v38);
  v38[0] = (idMem *)2;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)p_optionTypes,
    obj: (encounterGroupRole_t *)v38);
  this->numOptions[6] = 5;
  LODWORD(v6) = 0x82000000;
  HIDWORD(v7) = &unk_82340000;
  LODWORD(v5) = &unk_821F0000;
  HIDWORD(v6) = &mem;
  LODWORD(v7) = "optionType";
  v8 = 0;
  v38[0] = &mem;
  v42.variables.size = (int)"optionType";
  do
  {
    HIDWORD(v5) = v8;
    v9 = va::va(
           this: &v44,
           fmt: "option%d",
           a3: v5,
           a4: v7,
           a5: v6,
           a6: v32,
           a7: v33,
           a8: v34,
           a9: v35,
           a10: v36,
           a11: v37);
    NestedObj = idSWFScriptObject::GetNestedObj(
                  this: (idSWFScriptObject *)v42.variables.num,
                  arg1: "audioMenu",
                  arg2: "options",
                  arg3: v9->buffer,
                  arg4: nullptr,
                  arg5: nullptr,
                  arg6: nullptr);
    if ( NestedObj != nullptr )
    {
      v11 = this->menuIndex[6];
      v12 = v11 + v8;
      if ( v8 > 6 )
        v12 = v11 - v8 + 6;
      if ( v12 < 0 || v12 >= this->numOptions[6] )
      {
        v40.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v40);
        v40.type = SWF_VAR_INTEGER;
        v40.value.i = 0;
        idSWFScriptObject::Set(this: NestedObj, name: "_visible", value: &v40);
        idSWFScriptVar::Free(this: &v40);
        v41.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v41);
        v41.type = SWF_VAR_INTEGER;
        v41.value.i = 0;
        idSWFScriptObject::Set(this: NestedObj, name: "onPress", value: &v41);
        idSWFScriptVar::Free(this: &v41);
      }
      else
      {
        v39.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v39);
        v39.type = SWF_VAR_INTEGER;
        v39.value.i = 1;
        idSWFScriptObject::Set(this: NestedObj, name: "_visible", value: &v39);
        idSWFScriptVar::Free(this: &v39);
        idMainMenu::DisplayAudioValues(this, index: v12, set: 0, a4: v13);
        TextLength = 0.0;
        idSWFScriptObject::Get(this: &v42, result: NestedObj, name: "txtOption");
        if ( v42.refCount == 8 )
        {
          if ( v42.variables.list[3].hashNext == 3 )
            str = (idSWFTextInstance *)v42.variables.list[3].name.str;
          else
            str = nullptr;
          v16 = idStr::idStr(this: (idStr *)&v42.variablesHash[11], text: (const char *)v42.variablesHash[v12 + 3]);
          idSWFTextInstance::SetText(this: str, val: v16);
          idSWFTextInstance::SetStrokeInfo(this: str, use: true, strength: 0.75, weight: 2.0);
          TextLength = idSWFTextInstance::GetTextLength(this: str, a2: v22, a3: v21, a4: v20, a5: v19, a6: v18, a7: v17);
          v23 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                         this: v38[0],
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                         size: 0x14u,
                                         tag: TAG_SWF,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
          if ( v23 != nullptr )
          {
            mainMenu = this->mainMenu;
            v25 = v23;
            v23[3].__vftable = (idSWFScriptFunction_vtbl *)this;
            v23[4].__vftable = (idSWFScriptFunction_vtbl *)v12;
            v23[1].__vftable = nullptr;
            v23->__vftable = (idSWFScriptFunction_vtbl *)&`idMainMenu::UpdateMenu_Audio'::`18'::idSWFScriptFunction_accept::`vftable';
            v23[2].__vftable = (idSWFScriptFunction_vtbl *)mainMenu;
          }
          else
          {
            v25 = nullptr;
          }
          idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v42.variablesHash[1], nf: v25);
          idSWFScriptObject::Set(
            this: (idSWFScriptObject *)v42.variables.list,
            name: "onPress",
            value: (idSWFScriptVar *)&v42.variablesHash[1]);
          idSWFScriptVar::Free(this: (idSWFScriptVar *)&v42.variablesHash[1]);
        }
        idSWFScriptObject::Get(
          this: (idSWFScriptObject *)&v42.variables.granularity,
          result: NestedObj,
          name: (char *)v42.variables.size);
        v26 = idSWFScriptVar::ToSprite(this: (idSWFScriptVar *)&v42.variables.granularity);
        if ( v26 != nullptr )
        {
          idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v43);
          v27 = v12;
          idSWFParmList::Append(
            this: (idSWFParmList *)&v43,
            i: (idSWFScriptVar::swfScriptVarValue_t *)(p_optionTypes->list[v27] + 1));
          idSWFSpriteInstance::StopFrame(this: v26, parms: (const idSWFParmList *)&v43, a3: v30, a4: v29, a5: v28);
          v31 = p_optionTypes->list[v27];
          if ( v31 == 1 || v31 == 2 )
            idSWFSpriteInstance::SetXPos(this: v26, xPos: (float)((float)-TextLength - (float)5.0));
          idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v43);
        }
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v42.variables.granularity);
        idSWFScriptVar::Free(this: (idSWFScriptVar *)&v42);
      }
    }
    ++v8;
  }
  while ( v8 < 13 );
  if ( this->activeMenu == MENU_AUDIO )
    idStr::operator=(this: &this->btn2Text, text: "#STR_SWF_BACK");
  idMainMenu::UpdateButtonBar(this);
}


// ========================================================================
// __unwind$489579
// EA  : 0x82DBDD48
// RVA : 0x00DBDD48
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_489579()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4640 + 88));
}


// ========================================================================
// __unwind$489580_0
// EA  : 0x82DBDD70
// RVA : 0x00DBDD70
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_489580_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4640 + 112));
}


// ========================================================================
// __unwind$489583_0
// EA  : 0x82DBDD98
// RVA : 0x00DBDD98
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_489583_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4640 + 136));
}


// ========================================================================
// __unwind$489584_1
// EA  : 0x82DBDDC0
// RVA : 0x00DBDDC0
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_489584_1()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4640 + 128));
}


// ========================================================================
// __unwind$489585_1
// EA  : 0x82DBDDE8
// RVA : 0x00DBDDE8
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_489585_1()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 4640 + 208));
}


// ========================================================================
// __unwind$489577
// EA  : 0x82DBDE10
// RVA : 0x00DBDE10
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_489577()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4640 + 96));
}


// ========================================================================
// __unwind$489578
// EA  : 0x82DBDE38
// RVA : 0x00DBDE38
// PDB : w:\tech5\tungsten\game\mainmenulocal_audio.cpp
// ========================================================================

void _unwind_489578()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4640 + 104));
}

