
// ========================================================================
// ?ShowScreen@idMenuScreen_AudioSettings@@UAAXW4mainMenuTransition_t@@@Z
// EA  : 0x82DD69F8
// RVA : 0x00DD69F8
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void __fastcall idMenuScreen_AudioSettings::ShowScreen(
        idMenuScreen_AudioSettings *this,
        mainMenuTransition_t transitionType)
{
  this->audioData.LoadData(this: &this->audioData);
  idMenuScreen::ShowScreen(this, transitionType);
}


// ========================================================================
// ?HideScreen@idMenuScreen_AudioSettings@@UAAXW4mainMenuTransition_t@@@Z
// EA  : 0x82DD6A50
// RVA : 0x00DD6A50
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void __fastcall idMenuScreen_AudioSettings::HideScreen(
        idMenuScreen_AudioSettings *this,
        mainMenuTransition_t transitionType)
{
  idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings *p_audioData; // r31

  p_audioData = &this->audioData;
  if ( this->audioData.IsDataChanged(this: &this->audioData) )
    p_audioData->CommitData(this: p_audioData);
  idMenuScreen::HideScreen(this, transitionType);
}


// ========================================================================
// ?IsDataChanged@idMenuDataSource_AudioSettings@idMenuScreen_AudioSettings@@UBA_NXZ
// EA  : 0x82DD6C58
// RVA : 0x00DD6C58
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

int __fastcall idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings::IsDataChanged(
        idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings *this)
{
  int v2; // r28
  int i; // r31
  idSWFScriptVar *v4; // r29
  int v5; // r26

  v2 = 0;
  if ( this->fields.num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v4 = &this->fields.list[i];
    v5 = idSWFScriptVar::ToInteger(this: &this->originalFields.list[i]);
    if ( idSWFScriptVar::ToInteger(this: v4) != v5 )
      break;
    if ( ++v2 >= this->fields.num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?AdjustField@idMenuDataSource_AudioSettings@idMenuScreen_AudioSettings@@UAAXHH@Z
// EA  : 0x82DD6D38
// RVA : 0x00DD6D38
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void __fastcall idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings::AdjustField(
        idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings *this,
        int fieldIndex,
        unsigned int adjustAmount,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  idSWFScriptVar *list; // r11
  idSWFScriptVar *v10; // r31
  bool v11; // r30
  int v12; // r31
  double v13; // fp1
  double v14; // fp31
  double v15; // fp0
  idSWFScriptVar *v16; // r31

  list = this->fields.list;
  if ( fieldIndex == 4 )
  {
    v10 = list + 4;
    v11 = (_cntlzw((unsigned __int8)idSWFScriptVar::ToBool(this: list + 4)) & 0x20) != 0;
    idSWFScriptVar::Free(this: v10);
    v10->value.b = v11;
    v10->type = SWF_VAR_BOOL;
  }
  else
  {
    v12 = fieldIndex;
    v13 = idSWFScriptVar::ToFloat(this: &list[fieldIndex], a2: fieldIndex, a3: adjustAmount, a4, a5, a6, a7);
    v14 = 0.0;
    v15 = (float)((float)v13 + (float)__SPAIR64__(0x82000000, adjustAmount));
    if ( v15 >= 0.0 )
    {
      v14 = 100.0;
      if ( v15 <= 100.0 )
        v14 = (float)((float)v13 + (float)__SPAIR64__(0x82000000, adjustAmount));
    }
    v16 = &this->fields.list[v12];
    idSWFScriptVar::Free(this: v16);
    v16->value.f = v14;
    v16->type = SWF_VAR_FLOAT;
  }
}


// ========================================================================
// ?CommitData@idMenuDataSource_AudioSettings@idMenuScreen_AudioSettings@@UAAXXZ
// EA  : 0x82DD6E08
// RVA : 0x00DD6E08
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void __fastcall idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings::CommitData(
        idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings *this)
{
  idPlayerProfileGame *v2; // r30
  __int64 v3; // r10
  int v4; // r8
  int v5; // r7
  int v6; // r6
  int v7; // r5
  int v8; // r4
  idStaticList<idSWFScriptVar,5> *p_fields; // r29
  double v10; // fp1
  __int64 v11; // r10
  int v12; // r8
  int v13; // r7
  int v14; // r6
  int v15; // r5
  int v16; // r4
  double v17; // fp1
  __int64 v18; // r10
  int v19; // r8
  int v20; // r7
  int v21; // r6
  int v22; // r5
  int v23; // r4
  double v24; // fp1
  __int64 v25; // r10
  int v26; // r8
  int v27; // r7
  int v28; // r6
  int v29; // r5
  int v30; // r4
  double v31; // fp1
  idStaticList<idSWFScriptVar,5> *p_originalFields; // r31
  idSWFScriptVar *staticList; // r30
  int v34; // r29
  int i; // r31

  v2 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v2 != nullptr )
  {
    p_fields = &this->fields;
    v10 = idSWFScriptVar::ToFloat(this: this->fields.list, a2: v8, a3: v7, a4: v6, a5: v5, a6: v4, a7: v3);
    idPlayerProfileGame::SetMasterVolume(this: v2, val: (float)((float)v10 * (float)0.0099999998));
    v17 = idSWFScriptVar::ToFloat(this: this->fields.list + 1, a2: v16, a3: v15, a4: v14, a5: v13, a6: v12, a7: v11);
    idPlayerProfileGame::SetMusicVolume(this: v2, val: (float)((float)v17 * (float)0.0099999998));
    v24 = idSWFScriptVar::ToFloat(this: this->fields.list + 2, a2: v23, a3: v22, a4: v21, a5: v20, a6: v19, a7: v18);
    idPlayerProfileGame::SetVoiceVolume(this: v2, val: (float)((float)v24 * (float)0.0099999998));
    v31 = idSWFScriptVar::ToFloat(this: this->fields.list + 3, a2: v30, a3: v29, a4: v28, a5: v27, a6: v26, a7: v25);
    idPlayerProfileGame::SetAmbientVolume(this: v2, val: (float)((float)v31 * (float)0.0099999998));
    v2->useSubtitles = idSWFScriptVar::ToBool(this: this->fields.list + 4);
    idMainMenu::SaveSettings(this: gameLocal->mainMenu);
    p_originalFields = &this->originalFields;
    idList<idSWFScriptVar,5>::operator=(this: p_originalFields, other: p_fields);
    staticList = p_originalFields->staticList;
    v34 = (char *)p_fields - (char *)p_originalFields;
    for ( i = 5; i != 0; --i )
    {
      idSWFScriptVar::operator=(this: staticList, other: (idSWFScriptVar *)((char *)staticList + v34));
      ++staticList;
    }
  }
}


// ========================================================================
// ?LoadData@idMenuDataSource_AudioSettings@idMenuScreen_AudioSettings@@UAAXXZ
// EA  : 0x82DD6F78
// RVA : 0x00DD6F78
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void __fastcall idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings::LoadData(
        idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings *this)
{
  idPlayerProfileGame *v2; // r3
  idPlayerProfileGame *v3; // r30
  idSWFScriptVar *list; // r29
  idStaticList<idSWFScriptVar,5> *p_fields; // r27
  double v6; // fp30
  idSWFScriptVar *v7; // r29
  double v8; // fp30
  idSWFScriptVar *v9; // r29
  double v10; // fp30
  idSWFScriptVar *v11; // r29
  double v12; // fp31
  idSWFScriptVar *v13; // r30
  idStaticList<idSWFScriptVar,5> *p_originalFields; // r31
  idSWFScriptVar *staticList; // r30
  int v16; // r29
  int i; // r31

  v2 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  v3 = v2;
  if ( v2 != nullptr )
  {
    list = this->fields.list;
    p_fields = &this->fields;
    v6 = (float)(idPlayerProfileGame::GetMasterVolume(this: v2) * (float)100.0);
    idSWFScriptVar::Free(this: list);
    list->value.f = v6;
    list->type = SWF_VAR_FLOAT;
    v7 = this->fields.list + 1;
    v8 = (float)(idPlayerProfileGame::GetMusicVolume(this: v3) * (float)100.0);
    idSWFScriptVar::Free(this: v7);
    v7->value.f = v8;
    v7->type = SWF_VAR_FLOAT;
    v9 = this->fields.list + 2;
    v10 = (float)(idPlayerProfileGame::GetVoiceVolume(this: v3) * (float)100.0);
    idSWFScriptVar::Free(this: v9);
    v9->value.f = v10;
    v9->type = SWF_VAR_FLOAT;
    v11 = this->fields.list + 3;
    v12 = (float)(idPlayerProfileGame::GetAmbientVolume(this: v3) * (float)100.0);
    idSWFScriptVar::Free(this: v11);
    v11->value.f = v12;
    v11->type = SWF_VAR_FLOAT;
    LOBYTE(v11) = v3->useSubtitles;
    v13 = this->fields.list + 4;
    idSWFScriptVar::Free(this: v13);
    v13->value.b = (char)v11;
    p_originalFields = &this->originalFields;
    v13->type = SWF_VAR_BOOL;
    idList<idSWFScriptVar,5>::operator=(this: p_originalFields, other: p_fields);
    staticList = p_originalFields->staticList;
    v16 = (char *)p_fields - (char *)p_originalFields;
    for ( i = 5; i != 0; --i )
    {
      idSWFScriptVar::operator=(this: staticList, other: (idSWFScriptVar *)((char *)staticList + v16));
      ++staticList;
    }
  }
}


// ========================================================================
// ??0idMenuDataSource_AudioSettings@idMenuScreen_AudioSettings@@QAA@XZ
// EA  : 0x82DD7168
// RVA : 0x00DD7168
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings *__fastcall idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings::idMenuDataSource_AudioSettings(
        idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings *this)
{
  idStaticList<idSWFScriptVar,5> *p_fields; // r30
  int size; // r11
  int v4; // r11

  p_fields = &this->fields;
  this->__vftable = (idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings_vtbl *)&idMenuScreen_AudioSettings::idMenuDataSource_AudioSettings::`vftable';
  idStaticList<idSWFScriptVar,5>::idStaticList<idSWFScriptVar,5>(this: &this->fields);
  idStaticList<idSWFScriptVar,5>::idStaticList<idSWFScriptVar,5>(this: &this->originalFields);
  if ( this->fields.size >= 5 || (unsigned __int8)idList<idSWFScriptVar,72>::Resize(this: p_fields, newsize: 5) != 0 )
  {
    size = p_fields->size;
    if ( size > 5 )
      size = 5;
    p_fields->num = size;
  }
  if ( this->originalFields.size >= 5
    || (unsigned __int8)idList<idSWFScriptVar,72>::Resize(this: &this->originalFields, newsize: 5) != 0 )
  {
    v4 = this->originalFields.size;
    if ( v4 > 5 )
      v4 = 5;
    this->originalFields.num = v4;
  }
  return this;
}


// ========================================================================
// __unwind$488802
// EA  : 0x82DD7224
// RVA : 0x00DD7224
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_488802()
{
  int v0; // r12

  idMenuDataSource::~idMenuDataSource(this: *(idMenuDataSource **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$488803
// EA  : 0x82DD724C
// RVA : 0x00DD724C
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_488803()
{
  int v0; // r12

  idStaticList<idSWFScriptVar,5>::~idStaticList<idSWFScriptVar,5>(this: (idStaticList<idSWFScriptVar,5> *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$488804
// EA  : 0x82DD7278
// RVA : 0x00DD7278
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_488804()
{
  int v0; // r12

  idStaticList<idSWFScriptVar,5>::~idStaticList<idSWFScriptVar,5>(this: (idStaticList<idSWFScriptVar,5> *)(*(_DWORD *)(v0 - 128 + 148) + 60));
}


// ========================================================================
// ?Initialize@idMenuScreen_AudioSettings@@UAAXXZ
// EA  : 0x82DD7770
// RVA : 0x00DD7770
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void __fastcall idMenuScreen_AudioSettings::Initialize(idMenuScreen_AudioSettings *this)
{
  idMenuWidget *v2; // r3
  idMenuWidget *v3; // r30
  idMenuWidget *v4; // r21
  idWidgetAction *v5; // r3
  idSWFParmList *p_parms; // r28
  idWidgetAction *v7; // r3
  idSWFParmList *v8; // r28
  idWidgetAction *v9; // r3
  idWidgetAction *v10; // r28
  idSWFScriptVar *list; // r3
  idWidgetAction *v12; // r3
  idWidgetAction *v13; // r28
  idSWFScriptVar *v14; // r3
  idMenuWidget_Help *v15; // r3
  idMenuWidget_Help *v16; // r20
  idMenuWidget_Button *v17; // r3
  idMenuWidget_Button *v18; // r28
  idWidgetAction *v19; // r3
  idSWFParmList *v20; // r27
  idWidgetAction *v21; // r3
  idSWFParmList *v22; // r27
  idWidgetAction *v23; // r3
  idWidgetAction *v24; // r27
  idSWFScriptVar *v25; // r3
  idWidgetAction *v26; // r3
  idWidgetAction *v27; // r27
  idSWFScriptVar *v28; // r3
  idMenuWidget_Button *v29; // r3
  idMenuWidget_Button *v30; // r28
  idWidgetAction *v31; // r3
  idSWFParmList *v32; // r27
  idWidgetAction *v33; // r3
  idSWFParmList *v34; // r27
  idWidgetAction *v35; // r3
  idWidgetAction *v36; // r27
  idSWFScriptVar *v37; // r3
  idWidgetAction *v38; // r3
  idWidgetAction *v39; // r27
  idSWFScriptVar *v40; // r3
  idMenuWidget_Button *v41; // r3
  idMenuWidget_Button *v42; // r28
  idWidgetAction *v43; // r3
  idSWFParmList *v44; // r27
  idWidgetAction *v45; // r3
  idSWFParmList *v46; // r27
  idWidgetAction *v47; // r3
  idWidgetAction *v48; // r27
  idSWFScriptVar *v49; // r3
  idWidgetAction *v50; // r3
  idWidgetAction *v51; // r27
  idSWFScriptVar *v52; // r3
  idMenuWidget_Button *v53; // r3
  idMenuWidget_Button *v54; // r28
  idWidgetAction *v55; // r3
  idSWFParmList *v56; // r27
  idWidgetAction *v57; // r3
  idSWFParmList *v58; // r27
  idWidgetAction *v59; // r3
  idWidgetAction *v60; // r27
  idSWFScriptVar *v61; // r3
  idWidgetAction *v62; // r3
  idWidgetAction *v63; // r27
  idSWFScriptVar *v64; // r3
  idMenuWidget_Button *v65; // r3
  idMenuWidget_Button *v66; // r28
  idWidgetAction *v67; // r3
  idSWFParmList *v68; // r27
  idWidgetAction *v69; // r3
  idSWFParmList *v70; // r27
  idWidgetAction *v71; // r3
  idWidgetAction *v72; // r27
  idSWFScriptVar *v73; // r3
  idWidgetAction *v74; // r3
  idWidgetAction *v75; // r27
  idSWFScriptVar *v76; // r3
  idMenuWidget_CommandBar *v77; // r3
  idMenuWidget *v78; // r27
  int p_ExecuteEvent; // r28
  idSWFScriptVar **v80; // r30
  idSWFScriptVar v81; // [sp+58h] [-168h] BYREF
  idSWFScriptVar v82; // [sp+60h] [-160h] BYREF
  idSWFScriptVar v83; // [sp+68h] [-158h] BYREF
  idSWFScriptVar v84; // [sp+70h] [-150h] BYREF
  idSWFScriptVar v85; // [sp+78h] [-148h] BYREF
  idSWFScriptVar v86; // [sp+80h] [-140h] BYREF
  idSWFScriptVar v87; // [sp+88h] [-138h] BYREF
  idSWFScriptVar v88; // [sp+90h] [-130h] BYREF
  idSWFScriptVar v89; // [sp+98h] [-128h] BYREF
  idSWFScriptVar v90; // [sp+A0h] [-120h] BYREF
  idSWFScriptVar v91; // [sp+A8h] [-118h] BYREF
  idSWFScriptVar v92; // [sp+B0h] [-110h] BYREF
  idSWFScriptVar v93; // [sp+B8h] [-108h] BYREF
  idSWFScriptVar v94; // [sp+C0h] [-100h] BYREF
  idSWFScriptVar v95; // [sp+C8h] [-F8h] BYREF
  idSWFScriptVar v96; // [sp+D0h] [-F0h] BYREF
  idSWFScriptVar v97; // [sp+D8h] [-E8h] BYREF
  idSWFScriptVar v98; // [sp+E0h] [-E0h] BYREF
  idSWFScriptVar v99; // [sp+E8h] [-D8h] BYREF
  idSWFScriptVar v100; // [sp+F0h] [-D0h] BYREF
  idSWFScriptVar v101; // [sp+F8h] [-C8h] BYREF
  idSWFScriptVar v102; // [sp+100h] [-C0h] BYREF
  idSWFScriptVar v103; // [sp+108h] [-B8h] BYREF
  idSWFScriptVar v104; // [sp+110h] [-B0h] BYREF
  idSWFScriptVar v105[21]; // [sp+118h] [-A8h] BYREF

  idMenuWidget::SetSpritePath(this, arg1: "audioMenu", arg2: nullptr, arg3: nullptr, arg4: nullptr);
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
  v94.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v94);
  v94.value.i = 1;
  v94.type = SWF_VAR_INTEGER;
  v102.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v102);
  v102.type = SWF_VAR_INTEGER;
  v102.value.i = 2;
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
  idSWFParmList::Append(this: p_parms, other: &v102);
  idSWFParmList::Append(this: p_parms, other: &v94);
  idSWFScriptVar::Free(this: &v102);
  idSWFScriptVar::Free(this: &v94);
  v100.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v100);
  v100.type = SWF_VAR_INTEGER;
  v100.value.i = -1;
  v84.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v84);
  v84.type = SWF_VAR_INTEGER;
  v84.value.i = 2;
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
  idSWFParmList::Append(this: v8, other: &v84);
  idSWFParmList::Append(this: v8, other: &v100);
  idSWFScriptVar::Free(this: &v84);
  idSWFScriptVar::Free(this: &v100);
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
  v18->optionType = OPTION_SLIDER_BAR;
  idStr::operator=(this: &v18->label, text: "MASTER");
  idStr::operator=(this: &v18->description, text: "Master volume");
  idMenuWidget::SetDataSource(this: v18, dataSource_: &this->audioData, fieldIndex: 0);
  v96.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v96);
  v96.type = SWF_VAR_INTEGER;
  v96.value.i = -5;
  v86.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v86);
  v86.type = SWF_VAR_INTEGER;
  v86.value.i = 5;
  v19 = idMenuWidget::AddEventAction(this: v18, eventType: WIDGET_EVENT_SCROLL_LEFT);
  v19->action = WIDGET_ACTION_START_REPEATER;
  v20 = &v19->parms;
  if ( v19->parms.listStatic == 0 || v19->parms.listStatic == 2 )
  {
    if ( v20->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v19->parms.list, num: v19->parms.size);
    v20->list = nullptr;
    v20->size = 0;
  }
  v20->num = 0;
  idSWFParmList::Append(this: v20, other: &v86);
  idSWFParmList::Append(this: v20, other: &v96);
  idSWFScriptVar::Free(this: &v86);
  idSWFScriptVar::Free(this: &v96);
  v104.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v104);
  v104.type = SWF_VAR_INTEGER;
  v104.value.i = 5;
  v88.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v88);
  v88.type = SWF_VAR_INTEGER;
  v88.value.i = 5;
  v21 = idMenuWidget::AddEventAction(this: v18, eventType: WIDGET_EVENT_SCROLL_RIGHT);
  v21->action = WIDGET_ACTION_START_REPEATER;
  v22 = &v21->parms;
  if ( v21->parms.listStatic == 0 || v21->parms.listStatic == 2 )
  {
    if ( v22->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v21->parms.list, num: v21->parms.size);
    v22->list = nullptr;
    v22->size = 0;
  }
  v22->num = 0;
  idSWFParmList::Append(this: v22, other: &v88);
  idSWFParmList::Append(this: v22, other: &v104);
  idSWFScriptVar::Free(this: &v88);
  idSWFScriptVar::Free(this: &v104);
  v23 = idMenuWidget::AddEventAction(this: v18, eventType: WIDGET_EVENT_SCROLL_LEFT_RELEASE);
  v23->action = WIDGET_ACTION_STOP_REPEATER;
  v24 = v23;
  if ( v23->parms.listStatic == 0 || v23->parms.listStatic == 2 )
  {
    v25 = v23->parms.list;
    if ( v25 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v25, num: v24->parms.size);
    v24->parms.list = nullptr;
    v24->parms.size = 0;
  }
  v24->parms.num = 0;
  v26 = idMenuWidget::AddEventAction(this: v18, eventType: WIDGET_EVENT_SCROLL_RIGHT_RELEASE);
  v26->action = WIDGET_ACTION_STOP_REPEATER;
  v27 = v26;
  if ( v26->parms.listStatic == 0 || v26->parms.listStatic == 2 )
  {
    v28 = v26->parms.list;
    if ( v28 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v28, num: v27->parms.size);
    v27->parms.list = nullptr;
    v27->parms.size = 0;
  }
  v27->parms.num = 0;
  idMenuWidget::RegisterEventObserver(this: v18, observer: v16);
  idMenuWidget::AddChild(this: v4, widget: v18);
  v29 = (idMenuWidget_Button *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xFCu,
                                 tag: TAG_MENU,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v29 != nullptr )
    v30 = idMenuWidget_Button::idMenuWidget_Button(this: v29);
  else
    v30 = nullptr;
  v30->optionType = OPTION_SLIDER_BAR;
  idStr::operator=(this: &v30->label, text: "MUSIC");
  idStr::operator=(this: &v30->description, text: "Music volume");
  idMenuWidget::SetDataSource(this: v30, dataSource_: &this->audioData, fieldIndex: 1);
  v98.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v98);
  v98.type = SWF_VAR_INTEGER;
  v98.value.i = -5;
  v90.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v90);
  v90.type = SWF_VAR_INTEGER;
  v90.value.i = 5;
  v31 = idMenuWidget::AddEventAction(this: v30, eventType: WIDGET_EVENT_SCROLL_LEFT);
  v31->action = WIDGET_ACTION_START_REPEATER;
  v32 = &v31->parms;
  if ( v31->parms.listStatic == 0 || v31->parms.listStatic == 2 )
  {
    if ( v32->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v31->parms.list, num: v31->parms.size);
    v32->list = nullptr;
    v32->size = 0;
  }
  v32->num = 0;
  idSWFParmList::Append(this: v32, other: &v90);
  idSWFParmList::Append(this: v32, other: &v98);
  idSWFScriptVar::Free(this: &v90);
  idSWFScriptVar::Free(this: &v98);
  v81.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v81);
  v81.type = SWF_VAR_INTEGER;
  v81.value.i = 5;
  v92.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v92);
  v92.type = SWF_VAR_INTEGER;
  v92.value.i = 5;
  v33 = idMenuWidget::AddEventAction(this: v30, eventType: WIDGET_EVENT_SCROLL_RIGHT);
  v33->action = WIDGET_ACTION_START_REPEATER;
  v34 = &v33->parms;
  if ( v33->parms.listStatic == 0 || v33->parms.listStatic == 2 )
  {
    if ( v34->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v33->parms.list, num: v33->parms.size);
    v34->list = nullptr;
    v34->size = 0;
  }
  v34->num = 0;
  idSWFParmList::Append(this: v34, other: &v92);
  idSWFParmList::Append(this: v34, other: &v81);
  idSWFScriptVar::Free(this: &v92);
  idSWFScriptVar::Free(this: &v81);
  v35 = idMenuWidget::AddEventAction(this: v30, eventType: WIDGET_EVENT_SCROLL_LEFT_RELEASE);
  v35->action = WIDGET_ACTION_STOP_REPEATER;
  v36 = v35;
  if ( v35->parms.listStatic == 0 || v35->parms.listStatic == 2 )
  {
    v37 = v35->parms.list;
    if ( v37 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v37, num: v36->parms.size);
    v36->parms.list = nullptr;
    v36->parms.size = 0;
  }
  v36->parms.num = 0;
  v38 = idMenuWidget::AddEventAction(this: v30, eventType: WIDGET_EVENT_SCROLL_RIGHT_RELEASE);
  v38->action = WIDGET_ACTION_STOP_REPEATER;
  v39 = v38;
  if ( v38->parms.listStatic == 0 || v38->parms.listStatic == 2 )
  {
    v40 = v38->parms.list;
    if ( v40 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v40, num: v39->parms.size);
    v39->parms.list = nullptr;
    v39->parms.size = 0;
  }
  v39->parms.num = 0;
  idMenuWidget::RegisterEventObserver(this: v30, observer: v16);
  idMenuWidget::AddChild(this: v4, widget: v30);
  v41 = (idMenuWidget_Button *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xFCu,
                                 tag: TAG_MENU,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v41 != nullptr )
    v42 = idMenuWidget_Button::idMenuWidget_Button(this: v41);
  else
    v42 = nullptr;
  v42->optionType = OPTION_SLIDER_BAR;
  idStr::operator=(this: &v42->label, text: "VOICE");
  idStr::operator=(this: &v42->description, text: "Voice volume");
  idMenuWidget::SetDataSource(this: v42, dataSource_: &this->audioData, fieldIndex: 2);
  v83.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v83);
  v83.type = SWF_VAR_INTEGER;
  v83.value.i = -5;
  v82.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v82);
  v82.type = SWF_VAR_INTEGER;
  v82.value.i = 5;
  v43 = idMenuWidget::AddEventAction(this: v42, eventType: WIDGET_EVENT_SCROLL_LEFT);
  v43->action = WIDGET_ACTION_START_REPEATER;
  v44 = &v43->parms;
  if ( v43->parms.listStatic == 0 || v43->parms.listStatic == 2 )
  {
    if ( v44->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v43->parms.list, num: v43->parms.size);
    v44->list = nullptr;
    v44->size = 0;
  }
  v44->num = 0;
  idSWFParmList::Append(this: v44, other: &v82);
  idSWFParmList::Append(this: v44, other: &v83);
  idSWFScriptVar::Free(this: &v82);
  idSWFScriptVar::Free(this: &v83);
  v87.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v87);
  v87.type = SWF_VAR_INTEGER;
  v87.value.i = 5;
  v85.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v85);
  v85.type = SWF_VAR_INTEGER;
  v85.value.i = 5;
  v45 = idMenuWidget::AddEventAction(this: v42, eventType: WIDGET_EVENT_SCROLL_RIGHT);
  v45->action = WIDGET_ACTION_START_REPEATER;
  v46 = &v45->parms;
  if ( v45->parms.listStatic == 0 || v45->parms.listStatic == 2 )
  {
    if ( v46->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v45->parms.list, num: v45->parms.size);
    v46->list = nullptr;
    v46->size = 0;
  }
  v46->num = 0;
  idSWFParmList::Append(this: v46, other: &v85);
  idSWFParmList::Append(this: v46, other: &v87);
  idSWFScriptVar::Free(this: &v85);
  idSWFScriptVar::Free(this: &v87);
  v47 = idMenuWidget::AddEventAction(this: v42, eventType: WIDGET_EVENT_SCROLL_LEFT_RELEASE);
  v47->action = WIDGET_ACTION_STOP_REPEATER;
  v48 = v47;
  if ( v47->parms.listStatic == 0 || v47->parms.listStatic == 2 )
  {
    v49 = v47->parms.list;
    if ( v49 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v49, num: v48->parms.size);
    v48->parms.list = nullptr;
    v48->parms.size = 0;
  }
  v48->parms.num = 0;
  v50 = idMenuWidget::AddEventAction(this: v42, eventType: WIDGET_EVENT_SCROLL_RIGHT_RELEASE);
  v50->action = WIDGET_ACTION_STOP_REPEATER;
  v51 = v50;
  if ( v50->parms.listStatic == 0 || v50->parms.listStatic == 2 )
  {
    v52 = v50->parms.list;
    if ( v52 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v52, num: v51->parms.size);
    v51->parms.list = nullptr;
    v51->parms.size = 0;
  }
  v51->parms.num = 0;
  idMenuWidget::RegisterEventObserver(this: v42, observer: v16);
  idMenuWidget::AddChild(this: v4, widget: v42);
  v53 = (idMenuWidget_Button *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xFCu,
                                 tag: TAG_MENU,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v53 != nullptr )
    v54 = idMenuWidget_Button::idMenuWidget_Button(this: v53);
  else
    v54 = nullptr;
  v54->optionType = OPTION_SLIDER_BAR;
  idStr::operator=(this: &v54->label, text: "AMBIENT");
  idStr::operator=(this: &v54->description, text: "Ambient volume");
  idMenuWidget::SetDataSource(this: v54, dataSource_: &this->audioData, fieldIndex: 3);
  v91.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v91);
  v91.type = SWF_VAR_INTEGER;
  v91.value.i = -5;
  v89.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v89);
  v89.type = SWF_VAR_INTEGER;
  v89.value.i = 5;
  v55 = idMenuWidget::AddEventAction(this: v54, eventType: WIDGET_EVENT_SCROLL_LEFT);
  v55->action = WIDGET_ACTION_START_REPEATER;
  v56 = &v55->parms;
  if ( v55->parms.listStatic == 0 || v55->parms.listStatic == 2 )
  {
    if ( v56->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v55->parms.list, num: v55->parms.size);
    v56->list = nullptr;
    v56->size = 0;
  }
  v56->num = 0;
  idSWFParmList::Append(this: v56, other: &v89);
  idSWFParmList::Append(this: v56, other: &v91);
  idSWFScriptVar::Free(this: &v89);
  idSWFScriptVar::Free(this: &v91);
  v95.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v95);
  v95.type = SWF_VAR_INTEGER;
  v95.value.i = 5;
  v93.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v93);
  v93.type = SWF_VAR_INTEGER;
  v93.value.i = 5;
  v57 = idMenuWidget::AddEventAction(this: v54, eventType: WIDGET_EVENT_SCROLL_RIGHT);
  v57->action = WIDGET_ACTION_START_REPEATER;
  v58 = &v57->parms;
  if ( v57->parms.listStatic == 0 || v57->parms.listStatic == 2 )
  {
    if ( v58->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v57->parms.list, num: v57->parms.size);
    v58->list = nullptr;
    v58->size = 0;
  }
  v58->num = 0;
  idSWFParmList::Append(this: v58, other: &v93);
  idSWFParmList::Append(this: v58, other: &v95);
  idSWFScriptVar::Free(this: &v93);
  idSWFScriptVar::Free(this: &v95);
  v59 = idMenuWidget::AddEventAction(this: v54, eventType: WIDGET_EVENT_SCROLL_LEFT_RELEASE);
  v59->action = WIDGET_ACTION_STOP_REPEATER;
  v60 = v59;
  if ( v59->parms.listStatic == 0 || v59->parms.listStatic == 2 )
  {
    v61 = v59->parms.list;
    if ( v61 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v61, num: v60->parms.size);
    v60->parms.list = nullptr;
    v60->parms.size = 0;
  }
  v60->parms.num = 0;
  v62 = idMenuWidget::AddEventAction(this: v54, eventType: WIDGET_EVENT_SCROLL_RIGHT_RELEASE);
  v62->action = WIDGET_ACTION_STOP_REPEATER;
  v63 = v62;
  if ( v62->parms.listStatic == 0 || v62->parms.listStatic == 2 )
  {
    v64 = v62->parms.list;
    if ( v64 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v64, num: v63->parms.size);
    v63->parms.list = nullptr;
    v63->parms.size = 0;
  }
  v63->parms.num = 0;
  idMenuWidget::RegisterEventObserver(this: v54, observer: v16);
  idMenuWidget::AddChild(this: v4, widget: v54);
  v65 = (idMenuWidget_Button *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                 size: 0xFCu,
                                 tag: TAG_MENU,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
  if ( v65 != nullptr )
    v66 = idMenuWidget_Button::idMenuWidget_Button(this: v65);
  else
    v66 = nullptr;
  v66->optionType = OPTION_SLIDER_TEXT;
  idStr::operator=(this: &v66->label, text: "SUBTITLES");
  idStr::operator=(this: &v66->description, text: "Subtitles on or off?");
  idMenuWidget::SetDataSource(this: v66, dataSource_: &this->audioData, fieldIndex: 4);
  v99.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v99);
  v99.type = SWF_VAR_INTEGER;
  v99.value.i = -1;
  v97.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v97);
  v97.type = SWF_VAR_INTEGER;
  v97.value.i = 5;
  v67 = idMenuWidget::AddEventAction(this: v66, eventType: WIDGET_EVENT_SCROLL_LEFT);
  v67->action = WIDGET_ACTION_START_REPEATER;
  v68 = &v67->parms;
  if ( v67->parms.listStatic == 0 || v67->parms.listStatic == 2 )
  {
    if ( v68->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v67->parms.list, num: v67->parms.size);
    v68->list = nullptr;
    v68->size = 0;
  }
  v68->num = 0;
  idSWFParmList::Append(this: v68, other: &v97);
  idSWFParmList::Append(this: v68, other: &v99);
  idSWFScriptVar::Free(this: &v97);
  idSWFScriptVar::Free(this: &v99);
  v103.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v103);
  v103.type = SWF_VAR_INTEGER;
  v103.value.i = 1;
  v101.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v101);
  v101.type = SWF_VAR_INTEGER;
  v101.value.i = 5;
  v69 = idMenuWidget::AddEventAction(this: v66, eventType: WIDGET_EVENT_SCROLL_RIGHT);
  v69->action = WIDGET_ACTION_START_REPEATER;
  v70 = &v69->parms;
  if ( v69->parms.listStatic == 0 || v69->parms.listStatic == 2 )
  {
    if ( v70->list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v69->parms.list, num: v69->parms.size);
    v70->list = nullptr;
    v70->size = 0;
  }
  v70->num = 0;
  idSWFParmList::Append(this: v70, other: &v101);
  idSWFParmList::Append(this: v70, other: &v103);
  idSWFScriptVar::Free(this: &v101);
  idSWFScriptVar::Free(this: &v103);
  v71 = idMenuWidget::AddEventAction(this: v66, eventType: WIDGET_EVENT_SCROLL_LEFT_RELEASE);
  v71->action = WIDGET_ACTION_STOP_REPEATER;
  v72 = v71;
  if ( v71->parms.listStatic == 0 || v71->parms.listStatic == 2 )
  {
    v73 = v71->parms.list;
    if ( v73 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v73, num: v72->parms.size);
    v72->parms.list = nullptr;
    v72->parms.size = 0;
  }
  v72->parms.num = 0;
  v74 = idMenuWidget::AddEventAction(this: v66, eventType: WIDGET_EVENT_SCROLL_RIGHT_RELEASE);
  v74->action = WIDGET_ACTION_STOP_REPEATER;
  v75 = v74;
  if ( v74->parms.listStatic == 0 || v74->parms.listStatic == 2 )
  {
    v76 = v74->parms.list;
    if ( v76 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v76, num: v75->parms.size);
    v75->parms.list = nullptr;
    v75->parms.size = 0;
  }
  v75->parms.num = 0;
  idMenuWidget::RegisterEventObserver(this: v66, observer: v16);
  idMenuWidget::AddChild(this: v4, widget: v66);
  v77 = (idMenuWidget_CommandBar *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x460u,
                                     tag: TAG_MENU,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
  if ( v77 != nullptr )
    v78 = idMenuWidget_CommandBar::idMenuWidget_CommandBar(this: v77);
  else
    v78 = nullptr;
  v78[6].children.size = 1;
  idMenuWidget::SetSpritePath(this: v78, arg1: "cmdBar", arg2: nullptr, arg3: nullptr, arg4: nullptr);
  p_ExecuteEvent = (int)&v78[1].__vftable[7].ExecuteEvent;
  idStr::operator=(this: (idStr *)p_ExecuteEvent, text: "#STR_SWF_BACK");
  v105[0].type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: v105);
  v105[0].type = SWF_VAR_INTEGER;
  v105[0].value.i = 5;
  *(_DWORD *)(p_ExecuteEvent + 32) = 8;
  v80 = (idSWFScriptVar **)(p_ExecuteEvent + 36);
  if ( *(_BYTE *)(p_ExecuteEvent + 51) == 0 || *(_BYTE *)(p_ExecuteEvent + 51) == 2 )
  {
    if ( *v80 != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: *v80, num: *(_DWORD *)(p_ExecuteEvent + 44));
    *v80 = nullptr;
    *(_DWORD *)(p_ExecuteEvent + 44) = 0;
  }
  *(_DWORD *)(p_ExecuteEvent + 40) = 0;
  idSWFParmList::Append(this: (idSWFParmList *)(p_ExecuteEvent + 36), other: v105);
  idSWFScriptVar::Free(this: v105);
  idMenuWidget::AddChild(this, widget: v78);
}


// ========================================================================
// __unwind$489429
// EA  : 0x82DD86F0
// RVA : 0x00DD86F0
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489429()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 448 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$489430
// EA  : 0x82DD871C
// RVA : 0x00DD871C
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489430()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 192));
}


// ========================================================================
// __unwind$489431
// EA  : 0x82DD8744
// RVA : 0x00DD8744
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489431()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 256));
}


// ========================================================================
// __unwind$489432
// EA  : 0x82DD876C
// RVA : 0x00DD876C
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489432()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 240));
}


// ========================================================================
// __unwind$489433
// EA  : 0x82DD8794
// RVA : 0x00DD8794
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489433()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 112));
}


// ========================================================================
// __unwind$489434
// EA  : 0x82DD87BC
// RVA : 0x00DD87BC
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489434()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 448 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$489435_0
// EA  : 0x82DD87E8
// RVA : 0x00DD87E8
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489435_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 448 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$489436_0
// EA  : 0x82DD8814
// RVA : 0x00DD8814
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489436_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 208));
}


// ========================================================================
// __unwind$489437_1
// EA  : 0x82DD883C
// RVA : 0x00DD883C
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489437_1()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 128));
}


// ========================================================================
// __unwind$489438_0
// EA  : 0x82DD8864
// RVA : 0x00DD8864
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489438_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 272));
}


// ========================================================================
// __unwind$489439_0
// EA  : 0x82DD888C
// RVA : 0x00DD888C
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489439_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 144));
}


// ========================================================================
// __unwind$489440
// EA  : 0x82DD88B4
// RVA : 0x00DD88B4
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489440()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 448 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$489441
// EA  : 0x82DD88E0
// RVA : 0x00DD88E0
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489441()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 224));
}


// ========================================================================
// __unwind$489442
// EA  : 0x82DD8908
// RVA : 0x00DD8908
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489442()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 160));
}


// ========================================================================
// __unwind$489443
// EA  : 0x82DD8930
// RVA : 0x00DD8930
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489443()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 88));
}


// ========================================================================
// __unwind$489444
// EA  : 0x82DD8958
// RVA : 0x00DD8958
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489444()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 176));
}


// ========================================================================
// __unwind$489445
// EA  : 0x82DD8980
// RVA : 0x00DD8980
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489445()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 448 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$489446
// EA  : 0x82DD89AC
// RVA : 0x00DD89AC
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489446()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 104));
}


// ========================================================================
// __unwind$489447
// EA  : 0x82DD89D4
// RVA : 0x00DD89D4
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489447()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 96));
}


// ========================================================================
// __unwind$489448
// EA  : 0x82DD89FC
// RVA : 0x00DD89FC
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489448()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 136));
}


// ========================================================================
// __unwind$489449
// EA  : 0x82DD8A24
// RVA : 0x00DD8A24
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489449()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 120));
}


// ========================================================================
// __unwind$489450
// EA  : 0x82DD8A4C
// RVA : 0x00DD8A4C
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489450()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 448 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$489451
// EA  : 0x82DD8A78
// RVA : 0x00DD8A78
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489451()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 168));
}


// ========================================================================
// __unwind$489452
// EA  : 0x82DD8AA0
// RVA : 0x00DD8AA0
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489452()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 152));
}


// ========================================================================
// __unwind$489453
// EA  : 0x82DD8AC8
// RVA : 0x00DD8AC8
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489453()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 200));
}


// ========================================================================
// __unwind$489454
// EA  : 0x82DD8AF0
// RVA : 0x00DD8AF0
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489454()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 184));
}


// ========================================================================
// __unwind$489455
// EA  : 0x82DD8B18
// RVA : 0x00DD8B18
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489455()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 448 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$489456
// EA  : 0x82DD8B44
// RVA : 0x00DD8B44
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489456()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 232));
}


// ========================================================================
// __unwind$489457
// EA  : 0x82DD8B6C
// RVA : 0x00DD8B6C
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489457()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 216));
}


// ========================================================================
// __unwind$489458
// EA  : 0x82DD8B94
// RVA : 0x00DD8B94
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489458()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 264));
}


// ========================================================================
// __unwind$489459
// EA  : 0x82DD8BBC
// RVA : 0x00DD8BBC
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489459()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 248));
}


// ========================================================================
// __unwind$489460
// EA  : 0x82DD8BE4
// RVA : 0x00DD8BE4
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489460()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 448 + 80), tag: TAG_MENU);
}


// ========================================================================
// __unwind$489461
// EA  : 0x82DD8C10
// RVA : 0x00DD8C10
// PDB : w:\tech5\tungsten\game\menus\menuscreen_audiosettings.cpp
// ========================================================================

void _unwind_489461()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 448 + 280));
}

