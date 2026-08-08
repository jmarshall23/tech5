
// ========================================================================
// ?DrawKeyLegend@idDevGui@@QAAXAAVidDeviceContext@@@Z
// EA  : 0x82EAEF00
// RVA : 0x00EAEF00
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGui::DrawKeyLegend(idDevGui *this, idDeviceContext *context)
{
  idGuiListBox *v3; // r3
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  idGuiListBox *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  idGuiListBox *v11; // r3
  __int64 v12; // r8
  __int64 v13; // r10
  __int64 v14; // r6
  idGuiListBox *v15; // r3
  __int64 v16; // r8
  __int64 v17; // r10
  __int64 v18; // r6
  idGuiListBox *v19; // r3
  __int64 v20; // r6
  __int64 v21; // r10
  __int64 v22; // r8
  idGuiListBox *v23; // r3
  __int64 v24; // r6
  __int64 v25; // r10
  __int64 v26; // r8
  idGuiListBox *v27; // r3
  __int64 v28; // r10
  __int64 v29; // r8
  __int64 v30; // r6
  idGuiListBox *v31; // r3
  __int64 v32; // r10
  __int64 v33; // r8
  __int64 v34; // r6
  idGuiListBox *v35; // r3
  __int64 v36; // r10
  __int64 v37; // r8
  __int64 v38; // r6
  idGuiListBox *v39; // r3
  __int64 v40; // r10
  __int64 v41; // r8
  __int64 v42; // r6
  idGuiListBox *v43; // r3
  __int64 v44; // r8
  __int64 v45; // r10
  __int64 v46; // r6
  idGuiListBox *v47; // r3
  __int64 v48; // r8
  __int64 v49; // r10
  __int64 v50; // r6
  idGuiListBox *v51; // r3
  __int64 v52; // r6
  __int64 v53; // r10
  __int64 v54; // r8
  idGuiListBox *v55; // r3
  __int64 v56; // r6
  __int64 v57; // r10
  __int64 v58; // r8
  idGuiListBox *v59; // r3
  __int64 v60; // r10
  __int64 v61; // r8
  __int64 v62; // r6
  idGuiListBox *v63; // r3
  __int64 v64; // r10
  __int64 v65; // r8
  __int64 v66; // r6
  idGuiListBox *v67; // r3
  __int64 v68; // r10
  __int64 v69; // r8
  __int64 v70; // r6
  idGuiListBox *v71; // r3
  __int64 v72; // r10
  __int64 v73; // r8
  __int64 v74; // r6
  idGuiListBox *v75; // r3
  __int64 v76; // r10
  __int64 v77; // r8
  __int64 v78; // r6
  idGuiListBox *v79; // r3
  __int64 v80; // r8
  __int64 v81; // r10
  __int64 v82; // r6
  idGuiListBox *v83; // r3
  __int64 v84; // r8
  __int64 v85; // r10
  __int64 v86; // r6
  idGuiListBox *v87; // r3
  __int64 v88; // r6
  __int64 v89; // r10
  __int64 v90; // r8
  idGuiListBox v91; // [sp+50h] [-D0h] BYREF

  idGuiListBox::idGuiListBox(this: &v91);
  idGuiListBox::BackGroundColor(this: &v91, color: &keyLegendBackground);
  idSoundSystemLocal::SetEditorSoundWorld(this: (idSoundSystemLocal *)&v91, soundWorld: nullptr);
  v3 = idGuiListBox::Row(this: &v91);
  LODWORD(v4) = "plode - unlink clip";
  idGuiListBox::Printf(this: v3, fmt: "DevGUI Key Legend:", a3: v6, a4: v5, a5: v4);
  v7 = idGuiListBox::Row(this: &v91);
  HIDWORD(v8) = "plode - unlink clip";
  idGuiListBox::Printf(
    this: v7,
    fmt: "ESC(PC) / B(Xbox) / O(PS3)                 = Exit DevGUI",
    a3: v10,
    a4: v9,
    a5: v8);
  v11 = idGuiListBox::Row(this: &v91);
  LODWORD(v12) = "plode - unlink clip";
  idGuiListBox::Printf(this: v11, fmt: "---NAVIGATION KEYS:---", a3: v14, a4: v12, a5: v13);
  v15 = idGuiListBox::Row(this: &v91);
  HIDWORD(v16) = "plode - unlink clip";
  idGuiListBox::Printf(
    this: v15,
    fmt: "TAB(PC) / Left Bumper(Xbox + PS3)          = Move To Next Column",
    a3: v18,
    a4: v16,
    a5: v17);
  v19 = idGuiListBox::Row(this: &v91);
  LODWORD(v20) = "plode - unlink clip";
  idGuiListBox::Printf(
    this: v19,
    fmt: "BACKSPACE(PC) / Right Bumper(Xbox + PS3)   = Move To Previous Column",
    a3: v20,
    a4: v22,
    a5: v21);
  v23 = idGuiListBox::Row(this: &v91);
  HIDWORD(v24) = "plode - unlink clip";
  idGuiListBox::Printf(
    this: v23,
    fmt: "ARROWS/KP_ARROWS(PC) / D-Pad(Xbox + PS3)   = Move To Up/Down/Left/Right Row",
    a3: v24,
    a4: v26,
    a5: v25);
  v27 = idGuiListBox::Row(this: &v91);
  idGuiListBox::Printf(this: v27, fmt: "---ACTION KEYS:---", a3: v30, a4: v29, a5: v28);
  v31 = idGuiListBox::Row(this: &v91);
  idGuiListBox::Printf(
    this: v31,
    fmt: "ENTER(PC) / A(Xbox) / X(PS3)               = Execute Currently Selected Row",
    a3: v34,
    a4: v33,
    a5: v32);
  v35 = idGuiListBox::Row(this: &v91);
  LODWORD(v36) = "plode - unlink clip";
  idGuiListBox::Printf(
    this: v35,
    fmt: "PGUP(PC) / Y(Xbox) / Triangle(PS3)         = Increment Currently Selected Row's Value",
    a3: v38,
    a4: v37,
    a5: v36);
  v39 = idGuiListBox::Row(this: &v91);
  HIDWORD(v40) = "plode - unlink clip";
  idGuiListBox::Printf(
    this: v39,
    fmt: "PGDN(PC) / X(Xbox) / Square(PS3)           = Decrement Currently Selected Row's Value",
    a3: v42,
    a4: v41,
    a5: v40);
  v43 = idGuiListBox::Row(this: &v91);
  LODWORD(v44) = "ncy\\RenderModelTransparency.cpp(245) : TAG_TRANSPARENCY";
  idGuiListBox::Printf(
    this: v43,
    fmt: "---------------------------------------------------------------------------",
    a3: v46,
    a4: v44,
    a5: v45);
  v47 = idGuiListBox::Row(this: &v91);
  HIDWORD(v48) = "plode - unlink clip";
  idGuiListBox::Printf(this: v47, fmt: "DevGUI Icon Legend:", a3: v50, a4: v48, a5: v49);
  v51 = idGuiListBox::Row(this: &v91);
  LODWORD(v52) = "plode - unlink clip";
  idGuiListBox::Printf(
    this: v51,
    fmt: "+/-    = Hit PGUP/PGDN(PC) or X/Y(Xbox) or Square/Triangle(PS3) To Change Values",
    a3: v52,
    a4: v54,
    a5: v53);
  v55 = idGuiListBox::Row(this: &v91);
  HIDWORD(v56) = "plode - unlink clip";
  idGuiListBox::Printf(
    this: v55,
    fmt: "+o-    = Hold PGUP/PGDN(PC) or X/Y(Xbox) or Square/Triangle(PS3) To Change Values",
    a3: v56,
    a4: v58,
    a5: v57);
  v59 = idGuiListBox::Row(this: &v91);
  idGuiListBox::Printf(
    this: v59,
    fmt: "<->    = Move Arrows(PC) or D-Pad(Xbox/PS3) LEFT/RIGHT To Select Options",
    a3: v62,
    a4: v61,
    a5: v60);
  v63 = idGuiListBox::Row(this: &v91);
  idGuiListBox::Printf(
    this: v63,
    fmt: ">>>    = Move RIGHT Arrow(PC) or RIGHT D-Pad(Xbox/PS3) To Open Child Menu",
    a3: v66,
    a4: v65,
    a5: v64);
  v67 = idGuiListBox::Row(this: &v91);
  LODWORD(v68) = "plode - unlink clip";
  idGuiListBox::Printf(
    this: v67,
    fmt: "[x]    = If 'x' In Middle Of Parentheses - Option Is ON, Else Is OFF",
    a3: v70,
    a4: v69,
    a5: v68);
  v71 = idGuiListBox::Row(this: &v91);
  HIDWORD(v72) = "plode - unlink clip";
  idGuiListBox::Printf(
    this: v71,
    fmt: "xxx    = You have hit either the min or the max value allowed for that cvar",
    a3: v74,
    a4: v73,
    a5: v72);
  v75 = idGuiListBox::Row(this: &v91);
  idGuiListBox::Printf(
    this: v75,
    fmt: "---------------------------------------------------------------------------",
    a3: v78,
    a4: v77,
    a5: v76);
  v79 = idGuiListBox::Row(this: &v91);
  LODWORD(v80) = "plode - unlink clip";
  idGuiListBox::Printf(this: v79, fmt: "DevGUI General Info:", a3: v82, a4: v80, a5: v81);
  v83 = idGuiListBox::Row(this: &v91);
  HIDWORD(v84) = "plode - unlink clip";
  idGuiListBox::Printf(this: v83, fmt: "The Currently Selected Line Is Green.", a3: v86, a4: v84, a5: v85);
  v87 = idGuiListBox::Row(this: &v91);
  LODWORD(v88) = "plode - unlink clip";
  idGuiListBox::Printf(
    this: v87,
    fmt: "When An 'Action Key' Is Pressed, And The Action Is Valid, The Selected Line Will Flash Red",
    a3: v88,
    a4: v90,
    a5: v89);
  idGuiListBox::Render(this: &v91, page: nullptr, context, hAlign: 1u, vAlign: 1u, nextTo: nullptr);
  idGuiListBox::~idGuiListBox(this: &v91);
}


// ========================================================================
// __unwind$489644
// EA  : 0x82EAF11C
// RVA : 0x00EAF11C
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_489644()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 288 + 80));
}


// ========================================================================
// ?CallBack_ClearButtonDown@idDevGui@@SAX_N@Z
// EA  : 0x82EAF148
// RVA : 0x00EAF148
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGui::CallBack_ClearButtonDown(bool hadError)
{
  idDevGui::buttonDown = false;
  idDevGui::hadButtonDownError = hadError;
}


// ========================================================================
// ?CallBack_HadButtonError@idDevGui@@SAX_N@Z
// EA  : 0x82EAF160
// RVA : 0x00EAF160
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGui::CallBack_HadButtonError(bool hadError)
{
  idDevGui::hadButtonDownError = hadError;
}


// ========================================================================
// ??1idDevGuiPage@@UAA@XZ
// EA  : 0x82EAF170
// RVA : 0x00EAF170
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiPage::~idDevGuiPage(idDevGuiPage *this)
{
  this->__vftable = (idDevGuiPage_vtbl *)&idDevGuiPage::`vftable';
  idGuiPage::~idGuiPage(this);
}


// ========================================================================
// ?SetIsActive@idDevGuiPage@@UAAX_N@Z
// EA  : 0x82EAF180
// RVA : 0x00EAF180
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiPage::SetIsActive(idDevGuiPage *this, bool active)
{
  this->isActive = active;
  if ( !active )
    this->selectedRow = this->DEFAULT_ROW_NUM;
}


// ========================================================================
// ?DisconnectFromGame_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EAF1A0
// RVA : 0x00EAF1A0
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall DisconnectFromGame_f(const idCmdArgs *args)
{
  idCVar::SetInteger(this: &devgui, newValue: 0, force: true);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: "disconnect");
}


// ========================================================================
// ?ThirdPersonReset_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EAF1F0
// RVA : 0x00EAF1F0
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall ThirdPersonReset_f(const idCmdArgs *args, bool a2)
{
  bool v2; // r4
  bool v3; // r4

  idCVar::SetFloat(this: &pm_thirdPersonRange, newValue: 140.0, force: a2);
  idCVar::SetFloat(this: &pm_thirdPersonHeight, newValue: 0.0, force: v2);
  idCVar::SetFloat(this: &pm_thirdPersonAngle, newValue: 0.0, force: v3);
  idCVar::SetBool(this: &pm_thirdPersonClip, newValue: true, force: true);
}


// ========================================================================
// ?ShowBotPerformanceInfo_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EAF270
// RVA : 0x00EAF270
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall ShowBotPerformanceInfo_f(const idCmdArgs *args)
{
  idCVar::SetInteger(this: &devgui, newValue: 0, force: true);
  idCVar::SetInteger(this: &plog_mode, newValue: 1, force: true);
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "plog_toggle BOTS");
  cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "activateConsole .29");
}


// ========================================================================
// ?ShouldRun@idDevGui@@QAA_NXZ
// EA  : 0x82EAF370
// RVA : 0x00EAF370
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

int __fastcall idDevGui::ShouldRun(idDevGui *this)
{
  unsigned int v2; // r29
  idPlayer *DebugPlayer; // r31
  idPresentable *presentable; // r3
  bool v5; // zf
  int v6; // r11
  char v7; // r9
  int v8; // r3
  bool v9; // r31
  idLobbyBase *v10; // r3
  int v11; // r3

  v2 = (unsigned __int8)(!this->initialized - 1) & ((-devgui.valueInteger & (unsigned int)~devgui.valueInteger) >> 31);
  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr )
  {
    v5 = this->postExitSuppressInputTime <= idGameTimeManager::GetGameMs(
                                              this: &clientGame->gameTimeManager,
                                              type: GAMETIME_SCALED);
    presentable = DebugPlayer->presentable;
    if ( v5 )
    {
      if ( presentable != nullptr )
        v8 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v8 = 0;
      v6 = v8 + 47032;
      v7 = *(_BYTE *)(v8 + 47032) & 0xEF;
    }
    else if ( presentable != nullptr )
    {
      v6 = (int)presentable->GetPlayerInterface_2(this: presentable) + 47032;
      v7 = *(_BYTE *)v6 | 0x10;
    }
    else
    {
      v6 = 47032;
      v7 = MEMORY[0xB7B8] | 0x10;
    }
    *(_BYTE *)v6 = v7;
  }
  else
  {
    LOBYTE(v2) = 0;
  }
  v9 = common->IsClient(this: common);
  v10 = session->GetActingGameStateLobbyBase(this: session);
  v11 = v10->GetNumConnectedPeers(this: v10);
  if ( v9 || v11 > 0 )
    LOBYTE(v2) = 0;
  if ( (_BYTE)v2 != 0 )
    return 1;
  idCVar::SetInteger(this: &devgui, newValue: 0, force: true);
  return 0;
}


// ========================================================================
// ?HandleEvent@idDevGui@@QAA_NPBUsysEvent_t@@@Z
// EA  : 0x82EAF500
// RVA : 0x00EAF500
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

int __fastcall idDevGui::HandleEvent(idDevGui *this, const drawSurf_t *event)
{
  int v4; // r31
  int v6; // r11
  int num; // r11
  int v8; // r10
  int selectedColumn; // r11
  int v10; // r11
  idDevGuiMainPage *v11; // r11

  if ( (unsigned __int8)idDevGui::ShouldRun(this) == 0 || LODWORD(event->sort) != 1 )
    return 0;
  v4 = *(_DWORD *)&event->isWorld;
  if ( (unsigned __int8)idGuiKeyUtils::IsKeyDecrementAction(actionKey: v4) != 0
    || (unsigned __int8)idGuiKeyUtils::IsKeyIncrementAction(actionKey: v4) != 0 )
  {
    idDevGui::buttonDown = event->model != nullptr;
  }
  else
  {
    idDevGui::buttonDown = false;
    if ( event->model == nullptr )
      return 0;
  }
  if ( v4 <= 257 )
  {
    if ( v4 == 257 || v4 == 1 )
    {
      this->postExitSuppressInputTime = idGameTimeManager::GetGameMs(
                                          this: &clientGame->gameTimeManager,
                                          type: GAMETIME_SCALED)
                                      + 350;
      idCVar::SetInteger(this: &devgui, newValue: 0, force: true);
      return 1;
    }
    if ( v4 != 14 )
    {
      if ( v4 != 15 )
        goto LABEL_20;
      goto LABEL_17;
    }
LABEL_18:
    v6 = this->selectedColumn - 1;
    goto LABEL_19;
  }
  if ( v4 == 260 )
    goto LABEL_18;
  if ( v4 == 261 )
  {
LABEL_17:
    v6 = this->selectedColumn + 1;
LABEL_19:
    this->selectedColumn = v6;
  }
LABEL_20:
  num = this->pages.num;
  if ( num > 0 )
  {
    v8 = num - 1;
    selectedColumn = this->selectedColumn;
    if ( selectedColumn >= 0 )
      v10 = __CFADD__(v8 - selectedColumn, selectedColumn ^ 0x80000000) ? 0 : selectedColumn;
    else
      v10 = v8;
    this->selectedColumn = v10;
    v11 = this->pages.list[v10];
    if ( v11 != nullptr )
      idGuiPage::HandleEvent(this: v11, event);
  }
  return 1;
}


// ========================================================================
// ?RenderPages@idDevGui@@AAAXAAVidDeviceContext@@@Z
// EA  : 0x82EAF688
// RVA : 0x00EAF688
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGui::RenderPages(idDevGui *this, idDeviceContext *context)
{
  int num; // r11
  int v5; // r29
  int v6; // r31
  idDevGuiMainPage **list; // r11
  int selectedColumn; // r10
  idDevGuiMainPage **v9; // r6
  float v10; // [sp+50h] [-60h] BYREF
  float v11; // [sp+54h] [-5Ch] BYREF

  num = this->pages.num;
  v5 = 0;
  v10 = 0.0;
  v11 = 0.0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      list = this->pages.list;
      if ( list[v6] != nullptr )
      {
        selectedColumn = this->selectedColumn;
        v10 = v10 + 5.0;
        list[v6]->SetIsActive(this: list[v6], a2: (_cntlzw(v5 - selectedColumn) & 0x20) != 0);
        if ( idDevGui::buttonDown && !idDevGui::hadButtonDownError )
          this->pages.list[v6]->FlagSelectedRowAsDidActionRow(this: this->pages.list[v6]);
        this->pages.list[v6]->Update(this: this->pages.list[v6]);
        idGuiPage::Render(this: this->pages.list[v6], context, xPos: v10, yPos: 0.0);
        idGuiPage::GetRenderedPostion(this: this->pages.list[v6], xPos: &v10, yPos: &v11);
        v9 = this->pages.list;
        if ( v9[v6]->isActive )
        {
          v9[v6]->childrenSetup = true;
          this->pages.list[v6]->renderedOnce = true;
        }
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->pages.num );
  }
}


// ========================================================================
// ??0idDevGuiListBox@@QAA@MMPAVidDevGuiPage@@@Z
// EA  : 0x82EAF7D8
// RVA : 0x00EAF7D8
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idDevGuiListBox *__fastcall idDevGuiListBox::idDevGuiListBox(
        idDevGuiListBox *this,
        double x,
        double y,
        idDevGuiPage *page,
        int a5,
        int a6)
{
  idGuiListBox::idGuiListBox(this);
  this->parent = (idDevGuiPage *)a6;
  this->__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  if ( a6 != 0 )
  {
    this->borderWidth = 3.0;
    this->dividerWidth = 0.5;
    this->borderColor = idColor::colorWhite;
    this->dividerColor = idColor::colorWhite;
    idGuiListBox::BackGroundColor(this, color: &devGUIColorBackground);
    idGuiListBox::SetRenderPosition(this, xPos: x, yPos: y);
    idSoundSystemLocal::SetEditorSoundWorld((idSoundSystemLocal *)this, soundWorld: *(idSoundWorldLocal **)(a6 + 68));
    idGuiListBox::DidActionRow(this, actionRow: *(_DWORD *)(a6 + 72));
    this->skipMaxColumnSizeCheck = true;
    idBotMoveState::MoveToGoalCmd_SetStance(this, maxRows: 64);
  }
  return this;
}


// ========================================================================
// __unwind$490241
// EA  : 0x82EAF8E8
// RVA : 0x00EAF8E8
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_490241()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: *(idGuiListBox **)(v0 - 128 + 148));
}


// ========================================================================
// ?Update@idDevGuiPage@@UAAXXZ
// EA  : 0x82EAF910
// RVA : 0x00EAF910
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiPage::Update(idDevGuiPage *this)
{
  if ( this->didActionTimer > -1
    && this->didActionTimer < idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
  {
    this->didActionRow = -1;
    this->didActionTimer = -1;
  }
  if ( g_stopTime.valueInteger != 0 )
    this->didActionTimer -= idGameTimeManager::GetGameMsPerFrame(
                              this: &clientGame->gameTimeManager,
                              type: GAMETIME_SCALED);
}


// ========================================================================
// ?FlagSelectedRowAsDidActionRow@idDevGuiPage@@UAAXXZ
// EA  : 0x82EAF998
// RVA : 0x00EAF998
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiPage::FlagSelectedRowAsDidActionRow(idDevGuiPage *this)
{
  this->didActionRow = this->selectedRow;
  this->didActionTimer = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + 300;
}


// ========================================================================
// ?FlagSelectedRowAsDidActionRow@idDevGuiMainPage@@UAAXXZ
// EA  : 0x82EAF9E8
// RVA : 0x00EAF9E8
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage::FlagSelectedRowAsDidActionRow(idDevGuiMainPage *this)
{
  int v1; // r9
  int v2; // r11
  idDevGuiMainPage::childPages_t *list; // r8

  if ( this->childActive )
  {
    v1 = 0;
    if ( this->childPages.num > 0 )
    {
      v2 = 0;
      list = this->childPages.list;
      while ( this->selectedRow != list[v2].rowNum || list[v2].childPage == nullptr )
      {
        ++v1;
        ++v2;
        if ( v1 >= this->childPages.num )
          return;
      }
      list[v1].childPage->FlagSelectedRowAsDidActionRow(this: list[v1].childPage);
    }
  }
  else
  {
    this->didActionRow = this->selectedRow;
    this->didActionTimer = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + 300;
  }
}


// ========================================================================
// ?RenderChildPages@idDevGuiMainPage@@QAAXAAVidDeviceContext@@@Z
// EA  : 0x82EAFAD8
// RVA : 0x00EAFAD8
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage::RenderChildPages(idDevGuiMainPage *this, idDeviceContext *context)
{
  int num; // r6
  int v5; // r9
  double renderX; // fp31
  double v7; // fp30
  int v8; // r11
  idDevGuiMainPage::childPages_t *list; // r8
  int v10; // r30

  if ( this->childActive && this->isActive )
  {
    num = this->childPages.num;
    v5 = 0;
    renderX = this->renderX;
    v7 = (float)(this->renderY * (float)0.5);
    if ( num > 0 )
    {
      v8 = 0;
      list = this->childPages.list;
      while ( this->selectedRow != list[v8].rowNum || list[v8].childPage == nullptr )
      {
        ++v5;
        ++v8;
        if ( v5 >= num )
          return;
      }
      v10 = v5;
      list[v5].childPage->Update(this: list[v5].childPage);
      idGuiPage::Render(
        this: this->childPages.list[v10].childPage,
        context,
        xPos: (float)((float)renderX + 5.0),
        yPos: v7);
      this->childPages.list[v10].childPage->renderedOnce = true;
    }
  }
}


// ========================================================================
// ?ChildHandleEvent@idDevGuiMainPage@@QAA_NPBUsysEvent_t@@@Z
// EA  : 0x82EAFBE0
// RVA : 0x00EAFBE0
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

int __fastcall idDevGuiMainPage::ChildHandleEvent(idDevGuiMainPage *this, const drawSurf_t *event)
{
  int num; // r6
  int v5; // r9
  int v6; // r11
  idDevGuiMainPage::childPages_t *list; // r8
  int v9; // r31

  num = this->childPages.num;
  v5 = 0;
  if ( num > 0 )
  {
    v6 = 0;
    list = this->childPages.list;
    while ( this->selectedRow != list[v6].rowNum || list[v6].childPage == nullptr )
    {
      ++v5;
      ++v6;
      if ( v5 >= num )
        return 0;
    }
    v9 = v5;
    list[v5].childPage->InternalHandleEvent(this: list[v5].childPage, a2: (const sysEvent_t *)event);
    idGuiPage::AppendEvent(this: this->childPages.list[v9].childPage, event);
  }
  return 0;
}


// ========================================================================
// ?SetupChildRowLink@idDevGuiMainPage@@UAAXHABVidStr@@@Z
// EA  : 0x82EAFC88
// RVA : 0x00EAFC88
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage::SetupChildRowLink(idDevGuiMainPage *this, int rowNum, const idStr *childName)
{
  int v6; // r29
  int v7; // r30

  if ( !this->childrenSetup )
  {
    v6 = 0;
    if ( this->childPages.num <= 0 )
    {
LABEL_6:
      idLib::Warning(
        fmt: "idDevGuiMainPage::SetupChildRowLink - No Child With Name %s Found! Tell a programmer!",
        childName->data);
    }
    else
    {
      v7 = 0;
      while ( idStr::Icmp(s1: this->childPages.list[v7].childPage->pageName.data, s2: childName->data) != 0 )
      {
        ++v6;
        ++v7;
        if ( v6 >= this->childPages.num )
          goto LABEL_6;
      }
      this->childPages.list[v6].rowNum = rowNum;
    }
  }
}


// ========================================================================
// ?SetChildIsActive@idDevGuiMainPage@@QAAX_N@Z
// EA  : 0x82EAFD20
// RVA : 0x00EAFD20
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage::SetChildIsActive(idDevGuiMainPage *this, BOOL active)
{
  int v4; // r29
  int v5; // r30
  idDevGuiMainPage::childPages_t *v6; // r11

  v4 = 0;
  if ( this->childPages.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->childPages.list[v5];
      if ( v6->rowNum == this->selectedRow )
        v6->childPage->SetIsActive(this: v6->childPage, a2: active);
      ++v4;
      ++v5;
    }
    while ( v4 < this->childPages.num );
  }
}


// ========================================================================
// ?InternalHandleEvent@idDevGuiChildPage@@UAA_NPBUsysEvent_t@@@Z
// EA  : 0x82EAFD98
// RVA : 0x00EAFD98
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

int __fastcall idDevGuiChildPage::InternalHandleEvent(idDevGuiChildPage *this, const sysEvent_t *event)
{
  int evValue; // r30

  evValue = event->evValue;
  if ( (unsigned __int8)idGuiKeyUtils::IsKeyUpAction(actionKey: evValue) != 0 )
  {
    --this->selectedRow;
    return 1;
  }
  else if ( (unsigned __int8)idGuiKeyUtils::IsKeyDownAction(actionKey: evValue) != 0 )
  {
    ++this->selectedRow;
    return 1;
  }
  else
  {
    if ( (unsigned __int8)idGuiKeyUtils::IsKeyEnterAction(actionKey: evValue) != 0 )
      this->FlagSelectedRowAsDidActionRow(this);
    return 0;
  }
}


// ========================================================================
// ?DisplayVirtualTextureInfo_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EAFE48
// RVA : 0x00EAFE48
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall DisplayVirtualTextureInfo_f(const idCmdArgs *args)
{
  if ( vt_showStats.valueInteger != 0 )
  {
    idCVar::SetBool(this: &vt_showStats, newValue: false, force: true);
    idCVar::SetBool(this: &vt_showPageColors, newValue: false, force: true);
  }
  else
  {
    idCVar::SetBool(this: &vt_showStats, newValue: true, force: true);
    idCVar::SetBool(this: &vt_showPageColors, newValue: true, force: true);
    idCVar::SetString(this: &vt_pageImageSizeUnique, newValue: "8192", force: true);
    idCVar::SetString(this: &vt_pageImageSizeUniqueDiffuseOnly, newValue: "8192", force: true);
    idCVar::SetString(this: &vt_pageImageSizeUniqueDiffuseOnly2, newValue: "8192", force: true);
    cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "vt_restart");
    cmdSystem->ExecuteCommandText(this: cmdSystem, a2: "restartMap");
  }
}


// ========================================================================
// ?RenderBotAAS_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EAFF50
// RVA : 0x00EAFF50
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall RenderBotAAS_f(const idCmdArgs *args)
{
  int v1; // r4

  idCVar::SetString(this: &aas_test, newValue: "aas_monster32", force: true);
  v1 = 0;
  if ( aas_showAreas.valueInteger <= 0 )
    v1 = 386;
  idCVar::SetInteger(this: &aas_showAreas, newValue: v1, force: true);
}


// ========================================================================
// ?RenderWallEdges_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EAFFA8
// RVA : 0x00EAFFA8
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall RenderWallEdges_f(const idCmdArgs *args)
{
  idCVar::SetString(this: &aas_test, newValue: "aas_monster32", force: true);
  idCVar::SetInteger(this: &aas_showWallEdges, newValue: aas_showWallEdges.valueInteger <= 0, force: true);
}


// ========================================================================
// ?DrawDevGUI@idDevGui@@QAAPAVidRenderModelGui@@XZ
// EA  : 0x82EB0008
// RVA : 0x00EB0008
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idRenderModelGui *__fastcall idDevGui::DrawDevGUI(idDevGui *this)
{
  bool v2; // r4
  double oldGuiScale; // fp1
  bool v5; // r4
  int v6; // r7
  unsigned __int64 v7; // r6
  idPlayer *DebugPlayer; // r3
  idPlayer *v9; // r29
  idPresentable *presentable; // r3
  int v11; // r3
  idPresentable *v12; // r3
  idPresentablePlayer *v13; // r3
  idRenderModelGui *v14; // r3
  idRenderModelGui *v15; // r3
  unsigned int v16; // r29
  unsigned int v17; // r3
  int v18; // r10
  int v19; // r9
  int v20; // r8
  int v21; // r7
  int v22; // r5
  int v23; // r4
  idDeviceContext v24; // [sp+60h] [-540h] BYREF

  if ( (unsigned __int8)idDevGui::ShouldRun(this) != 0 )
  {
    if ( this->firstDraw )
    {
      this->firstDraw = false;
      this->oldGuiScale = aigui_scale.valueFloat;
      idCVar::SetFloat(this: &aigui_scale, newValue: 0.44999999, force: v2);
    }
    if ( common->IsToolActive(this: common) && !this->runningTool )
    {
      this->runningTool = true;
      idCVar::SetFloat(this: &aigui_scale, newValue: 0.40000001, force: v5);
    }
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    v9 = DebugPlayer;
    if ( DebugPlayer != nullptr )
    {
      presentable = DebugPlayer->presentable;
      if ( presentable != nullptr )
        v11 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v11 = 0;
      *(_BYTE *)(v11 + 47032) |= 0x10u;
      v12 = v9->presentable;
      if ( v12 != nullptr )
        v13 = v12->GetPlayerInterface_2(this: v12);
      else
        v13 = nullptr;
      idPresentablePlayer::AddInhibitFlags(this: v13, flags: UCMD_INHIBIT_BUTTONS_ONCE|UCMD_INHIBIT_MOVEMENT_ONCE);
    }
    if ( this->guiModel == nullptr )
    {
      v14 = (idRenderModelGui *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0xA410u,
                                  tag: TAG_GUI_MODEL,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
      if ( v14 != nullptr )
        v15 = idRenderModelGui::idRenderModelGui(this: v14);
      else
        v15 = nullptr;
      this->guiModel = v15;
    }
    idRenderModelGui::Clear(
      this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
      a2: defaultExtraGLState,
      bits: v7,
      a4: v6);
    v16 = renderSystem->GetHeight(this: renderSystem);
    v17 = renderSystem->GetWidth(this: renderSystem);
    idRenderModelGui::SetViewport(this: this->guiModel, x: 0, y: 0, width: v17, height: v16);
    idRenderModelGui::SetupMonospaceFont(
      this: this->guiModel,
      drawWidth: 10.0,
      a3: v23,
      a4: v22,
      a5: 0x82000000,
      a6: v21,
      a7: v20,
      a8: v19,
      a9: v18);
    idDeviceContext::idDeviceContext(this: &v24, guiModel: this->guiModel);
    idDeviceContext::SetFont(this: &v24, font: (const idFont *)monospaceFont.r);
    idDevGui::RenderPages(this, context: &v24);
    if ( devgui.valueInteger > 1 )
      idDevGui::DrawKeyLegend(this, context: &v24);
    return this->guiModel;
  }
  else
  {
    if ( !this->firstDraw )
    {
      oldGuiScale = this->oldGuiScale;
      this->firstDraw = true;
      idCVar::SetFloat(this: &aigui_scale, newValue: oldGuiScale, force: v2);
    }
    return nullptr;
  }
}


// ========================================================================
// __unwind$490739_0
// EA  : 0x82EB0274
// RVA : 0x00EB0274
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_490739_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1440 + 80), tag: TAG_GUI_MODEL);
}


// ========================================================================
// ??0idDevGuiPage@@QAA@HPBD@Z
// EA  : 0x82EB02A8
// RVA : 0x00EB02A8
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idDevGuiPage *__fastcall idDevGuiPage::idDevGuiPage(idDevGuiPage *this, int defaultRow, const char *name)
{
  idStr v6[2]; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: v6, text: name);
  idGuiPage::idGuiPage(this, name: v6);
  idStr::FreeData(this: v6);
  this->DEFAULT_ROW_NUM = defaultRow;
  this->renderedOnce = false;
  this->selectedRow = 0;
  this->__vftable = (idDevGuiPage_vtbl *)&idDevGuiPage::`vftable';
  this->didActionRow = -1;
  this->didActionTimer = -1;
  return this;
}


// ========================================================================
// __unwind$490821_0
// EA  : 0x82EB0318
// RVA : 0x00EB0318
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_490821_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$490822_0
// EA  : 0x82EB0340
// RVA : 0x00EB0340
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_490822_0()
{
  int v0; // r12

  idGuiPage::~idGuiPage(this: *(idGuiPage **)(v0 - 144 + 164));
}


// ========================================================================
// ?FreeChildPages@idDevGuiMainPage@@IAAXXZ
// EA  : 0x82EB0368
// RVA : 0x00EB0368
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage::FreeChildPages(idDevGuiMainPage *this)
{
  int v2; // r29
  int v3; // r30
  idDevGuiChildPage *childPage; // r3
  idDevGuiMainPage::childPages_t *v5; // r11
  idDevGuiMainPage::childPages_t *list; // r4

  v2 = 0;
  if ( this->childPages.num > 0 )
  {
    v3 = 0;
    do
    {
      childPage = this->childPages.list[v3].childPage;
      if ( childPage != nullptr )
        ((void (__fastcall *)(idDevGuiChildPage *, int))childPage->dtr_idGuiPage)(a1: childPage, a2: 1);
      ++v2;
      v5 = &this->childPages.list[v3++];
      v5->childPage = nullptr;
    }
    while ( v2 < this->childPages.num );
  }
  if ( this->childPages.listStatic == 0 || this->childPages.listStatic == 2 )
  {
    list = this->childPages.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->childPages.list = nullptr;
    this->childPages.size = 0;
  }
  this->childPages.num = 0;
}


// ========================================================================
// ?InternalHandleEvent@idDevGuiMainPage@@UAA_NPBUsysEvent_t@@@Z
// EA  : 0x82EB0420
// RVA : 0x00EB0420
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

int __fastcall idDevGuiMainPage::InternalHandleEvent(idDevGuiMainPage *this, const drawSurf_t *event)
{
  int v4; // r29
  int v5; // r10
  int v6; // r11
  char v7; // r11
  int v9; // r10
  int v10; // r11
  char v11; // r11

  if ( this->childrenSetup )
  {
    v4 = *(_DWORD *)&event->isWorld;
    if ( (unsigned __int8)idGuiKeyUtils::IsKeyRightAction(actionKey: v4) != 0 )
    {
      v5 = 0;
      if ( this->childPages.num <= 0 )
      {
LABEL_7:
        v7 = 0;
      }
      else
      {
        v6 = 0;
        while ( this->childPages.list[v6].rowNum != this->selectedRow )
        {
          ++v5;
          ++v6;
          if ( v5 >= this->childPages.num )
            goto LABEL_7;
        }
        v7 = 1;
      }
      if ( v7 != 0 )
      {
        this->childActive = true;
        return 1;
      }
    }
    if ( (unsigned __int8)idGuiKeyUtils::IsKeyLeftAction(actionKey: v4) != 0 && this->childActive )
    {
      this->childActive = false;
      idDevGuiMainPage::SetChildIsActive(this, active: false);
      return 1;
    }
    if ( this->childActive )
    {
      idDevGuiMainPage::ChildHandleEvent(this, event);
    }
    else
    {
      if ( (unsigned __int8)idGuiKeyUtils::IsKeyUpAction(actionKey: v4) != 0 )
      {
        --this->selectedRow;
        return 1;
      }
      if ( (unsigned __int8)idGuiKeyUtils::IsKeyDownAction(actionKey: v4) != 0 )
      {
        ++this->selectedRow;
        return 1;
      }
      v9 = 0;
      if ( this->childPages.num <= 0 )
      {
LABEL_23:
        v11 = 0;
      }
      else
      {
        v10 = 0;
        while ( this->childPages.list[v10].rowNum != this->selectedRow )
        {
          ++v9;
          ++v10;
          if ( v9 >= this->childPages.num )
            goto LABEL_23;
        }
        v11 = 1;
      }
      if ( v11 == 0 && (unsigned __int8)idGuiKeyUtils::IsKeyEnterAction(actionKey: v4) != 0 )
      {
        this->FlagSelectedRowAsDidActionRow(this);
        return 0;
      }
    }
  }
  return 0;
}


// ========================================================================
// ?SetIsActive@idDevGuiMainPage@@UAAX_N@Z
// EA  : 0x82EB0608
// RVA : 0x00EB0608
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage::SetIsActive(idDevGuiMainPage *this, bool active)
{
  int DEFAULT_ROW_NUM; // r10

  this->isActive = active;
  if ( !active )
  {
    DEFAULT_ROW_NUM = this->DEFAULT_ROW_NUM;
    this->childActive = false;
    this->selectedRow = DEFAULT_ROW_NUM;
    idDevGuiMainPage::SetChildIsActive(this, active: false);
  }
}


// ========================================================================
// ?InternalRender@idDevGuiMainPage_Main@@EAAXAAVidDeviceContext@@MM@Z
// EA  : 0x82EB0638
// RVA : 0x00EB0638
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage_Main::InternalRender(
        idDevGuiMainPage_Main *this,
        idDevGuiPage *context,
        double xPos,
        double yPos,
        int a5)
{
  idGuiListBox *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  bool v11; // r27
  idGuiListBox *v12; // r3
  __int64 v13; // r8
  __int64 v14; // r10
  __int64 v15; // r6
  idGuiListBox *v16; // r3
  char v17; // r29
  idGuiListBox *v18; // r3
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  idGuiListBox *v22; // r3
  idGuiListBox *v23; // r3
  char v24; // r29
  idGuiListBox *v25; // r3
  __int64 v26; // r6
  __int64 v27; // r10
  __int64 v28; // r8
  idGuiListBox *v29; // r3
  idGuiListBox *v30; // r3
  char v31; // r29
  idGuiListBox *v32; // r3
  __int64 v33; // r8
  __int64 v34; // r10
  __int64 v35; // r6
  idGuiListBox *v36; // r3
  idGuiListBox *v37; // r3
  idGuiListBox *v38; // r3
  __int64 v39; // r6
  __int64 v40; // r10
  __int64 v41; // r8
  idGuiListBox *v42; // r3
  __int64 v43; // r10
  __int64 v44; // r8
  __int64 v45; // r6
  idGuiListBox *v46; // r3
  int selectedRow; // r11
  double v48; // fp9
  idStr v49; // [sp+50h] [-110h] BYREF
  idDevGuiListBox v50; // [sp+70h] [-F0h] BYREF

  idDevGuiListBox::idDevGuiListBox(this: &v50, x: xPos, y: yPos, page: context, a5, a6: (int)this);
  v7 = idGuiListBox::Row(this: &v50);
  idGuiListBox::Printf(this: v7, fmt: "- MAIN -", a3: v10, a4: v9, a5: v8);
  if ( this->isActive )
  {
    v11 = (_cntlzw(this->renderedOnce) & 0x20) != 0;
    v12 = idGuiListBox::Row(this: &v50);
    LODWORD(v13) = "plode - unlink clip";
    v16 = idGuiListBox::Printf(this: v12, fmt: "Disconnect", a3: v15, a4: v13, a5: v14);
    idGuiListBox::Command(this: v16, commandName: "DisconnectFromGame", verifyCmdName: v11);
    v17 = con_noPrint.valueInteger != 0;
    v18 = idGuiListBox::Row(this: &v50);
    v22 = idGuiListBox::Printf(this: v18, fmt: "Con No Print", a3: v21, a4: v20, a5: v19);
    v23 = idGuiListBox::Command(this: v22, commandName: "toggle con_noPrint", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v23, checked: v17);
    v24 = g_showEntityInfo.valueInteger != 0;
    v25 = idGuiListBox::Row(this: &v50);
    LODWORD(v26) = "plode - unlink clip";
    v29 = idGuiListBox::Printf(this: v25, fmt: "Show Entity Info", a3: v26, a4: v28, a5: v27);
    v30 = idGuiListBox::Command(this: v29, commandName: "toggle g_showEntityInfo 0 1", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v30, checked: v24);
    v31 = g_showEntityWarnings.valueInteger != 0;
    v32 = idGuiListBox::Row(this: &v50);
    LODWORD(v33) = "plode - unlink clip";
    v36 = idGuiListBox::Printf(this: v32, fmt: "Show Entity Warnings", a3: v35, a4: v33, a5: v34);
    v37 = idGuiListBox::Command(this: v36, commandName: "toggle g_showEntityWarnings 0 1", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v37, checked: v31);
    idStr::idStr(this: &v49, text: "Time_Scale");
    v38 = idGuiListBox::Row(this: &v50);
    HIDWORD(v39) = "plode - unlink clip";
    v42 = idGuiListBox::Printf(this: v38, fmt: "Time Control", a3: v39, a4: v41, a5: v40);
    v46 = idGuiListBox::Printf(this: v42, fmt: " ", a3: v45, a4: v44, a5: v43);
    idGuiListBox::SetChildWindow(this: v46, childName: &v49, page: this);
    idStr::FreeData(this: &v49);
  }
  selectedRow = this->selectedRow;
  if ( selectedRow >= this->DEFAULT_ROW_NUM )
  {
    if ( selectedRow > v50.rows.num - 1 )
      selectedRow = this->DEFAULT_ROW_NUM;
  }
  else
  {
    selectedRow = v50.rows.num - 1;
  }
  this->selectedRow = selectedRow;
  idGuiListBox::Render(
    this: &v50,
    page: v50.parent,
    (idDeviceContext *)context,
    hAlign: 3u,
    vAlign: 3u,
    nextTo: nullptr);
  v48 = (float)(v50.renderHeight + v50.renderY);
  this->renderX = v50.renderWidth + v50.renderX;
  this->renderY = v48;
  idDevGuiMainPage::RenderChildPages(this, (idDeviceContext *)context);
  v50.__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  idGuiListBox::~idGuiListBox(this: &v50);
}


// ========================================================================
// __unwind$490984_0
// EA  : 0x82EB0844
// RVA : 0x00EB0844
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_490984_0()
{
  int v0; // r12

  idDevGuiListBox::~idDevGuiListBox(this: (idDevGuiListBox *)(v0 - 352 + 112));
}


// ========================================================================
// __unwind$490985_0
// EA  : 0x82EB086C
// RVA : 0x00EB086C
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_490985_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 80));
}


// ========================================================================
// ?InternalRender@idDevGuiChildPage_TimeScale@@EAAXAAVidDeviceContext@@MM@Z
// EA  : 0x82EB08A0
// RVA : 0x00EB08A0
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiChildPage_TimeScale::InternalRender(
        idDevGuiChildPage_TimeScale *this,
        idDevGuiPage *context,
        double xPos,
        double yPos,
        int a5)
{
  bool v7; // r27
  idGuiListBox *v8; // r3
  __int64 v9; // r8
  __int64 v10; // r10
  __int64 v11; // r6
  idGuiListBox *v12; // r3
  idGuiListBox *v13; // r3
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  idGuiListBox *v17; // r3
  idGuiListBox *v18; // r3
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  idGuiListBox *v22; // r3
  char v23; // r29
  idGuiListBox *v24; // r3
  __int64 v25; // r6
  __int64 v26; // r10
  __int64 v27; // r8
  idGuiListBox *v28; // r3
  idGuiListBox *v29; // r3
  idGuiListBox *v30; // r3
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r6
  idGuiListBox *v34; // r3
  int selectedRow; // r11
  idDevGuiListBox v36; // [sp+50h] [-F0h] BYREF

  idDevGuiListBox::idDevGuiListBox(this: &v36, x: xPos, y: yPos, page: context, a5, a6: (int)this);
  v7 = (_cntlzw(this->renderedOnce) & 0x20) != 0;
  v8 = idGuiListBox::Row(this: &v36);
  LODWORD(v9) = "plode - unlink clip";
  v12 = idGuiListBox::Printf(this: v8, fmt: "Slow Time", a3: v11, a4: v9, a5: v10);
  idGuiListBox::Command(this: v12, commandName: "timescale .1", verifyCmdName: v7);
  v13 = idGuiListBox::Row(this: &v36);
  LODWORD(v14) = "plode - unlink clip";
  v17 = idGuiListBox::Printf(this: v13, fmt: "Normal Time", a3: v14, a4: v16, a5: v15);
  idGuiListBox::Command(this: v17, commandName: "timescale 1", verifyCmdName: v7);
  v18 = idGuiListBox::Row(this: &v36);
  v22 = idGuiListBox::Printf(this: v18, fmt: "Fast Time", a3: v21, a4: v20, a5: v19);
  idGuiListBox::Command(this: v22, commandName: "timescale 5", verifyCmdName: v7);
  v23 = g_stopTime.valueInteger != 0;
  v24 = idGuiListBox::Row(this: &v36);
  LODWORD(v25) = "plode - unlink clip";
  v28 = idGuiListBox::Printf(this: v24, fmt: "Stop Time", a3: v25, a4: v27, a5: v26);
  v29 = idGuiListBox::Command(this: v28, commandName: "toggle g_stopTime", verifyCmdName: v7);
  idGuiListBox::DrawCheckMark(this: v29, checked: v23);
  v30 = idGuiListBox::Row(this: &v36);
  v34 = idGuiListBox::Printf(this: v30, fmt: "Advance Time One Frame When Stopped", a3: v33, a4: v32, a5: v31);
  idGuiListBox::Command(this: v34, commandName: "g_runFrames 1", verifyCmdName: v7);
  selectedRow = this->selectedRow;
  if ( selectedRow >= this->DEFAULT_ROW_NUM )
  {
    if ( selectedRow > v36.rows.num - 1 )
      selectedRow = this->DEFAULT_ROW_NUM;
  }
  else
  {
    selectedRow = v36.rows.num - 1;
  }
  this->selectedRow = selectedRow;
  idGuiListBox::Render(
    this: &v36,
    page: v36.parent,
    (idDeviceContext *)context,
    hAlign: 3u,
    vAlign: 3u,
    nextTo: nullptr);
  v36.__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  idGuiListBox::~idGuiListBox(this: &v36);
}


// ========================================================================
// __unwind$491069_0
// EA  : 0x82EB0A08
// RVA : 0x00EB0A08
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_491069_0()
{
  int v0; // r12

  idDevGuiListBox::~idDevGuiListBox(this: (idDevGuiListBox *)(v0 - 320 + 80));
}


// ========================================================================
// ?InternalRender@idDevGuiMainPage_Player@@EAAXAAVidDeviceContext@@MM@Z
// EA  : 0x82EB0A38
// RVA : 0x00EB0A38
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage_Player::InternalRender(
        idDevGuiMainPage_Player *this,
        idDevGuiPage *context,
        double xPos,
        double yPos,
        int a5)
{
  idGuiListBox *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  idPlayer *DebugPlayer; // r29
  bool v12; // r26
  idGuiListBox *v13; // r3
  __int64 v14; // r8
  __int64 v15; // r10
  __int64 v16; // r6
  idGuiListBox *v17; // r3
  __int64 v18; // r6
  __int64 v19; // r10
  __int64 v20; // r8
  idGuiListBox *v21; // r3
  __int64 v22; // r6
  __int64 v23; // r10
  __int64 v24; // r8
  va *v25; // r28
  idGuiListBox *v26; // r3
  __int64 v27; // r10
  __int64 v28; // r8
  __int64 v29; // r6
  idGuiListBox *v30; // r3
  idGuiListBox *v31; // r3
  __int64 v32; // r8
  __int64 v33; // r10
  __int64 v34; // r6
  idGuiListBox *v35; // r3
  idGuiListBox *v36; // r3
  idGuiListBox *v37; // r3
  __int64 v38; // r10
  __int64 v39; // r8
  __int64 v40; // r6
  idGuiListBox *v41; // r3
  idGuiListBox *v42; // r3
  idGuiListBox *v43; // r3
  __int64 v44; // r8
  __int64 v45; // r10
  __int64 v46; // r6
  idGuiListBox *v47; // r3
  idGuiListBox *v48; // r3
  idGuiListBox *v49; // r3
  __int64 v50; // r10
  __int64 v51; // r8
  __int64 v52; // r6
  idGuiListBox *v53; // r3
  idGuiListBox *v54; // r3
  bool Noclip; // r29
  idGuiListBox *v56; // r3
  __int64 v57; // r10
  __int64 v58; // r8
  __int64 v59; // r6
  idGuiListBox *v60; // r3
  idGuiListBox *v61; // r3
  __int64 v62; // r8
  __int128 v63; // r6
  __int64 v64; // r10
  va *v65; // r29
  idGuiListBox *v66; // r3
  __int64 v67; // r10
  __int64 v68; // r8
  __int64 v69; // r6
  idGuiListBox *v70; // r3
  __int64 v71; // r10
  __int64 v72; // r8
  __int64 v73; // r6
  idGuiListBox *v74; // r3
  int v75; // r7
  bool v76; // r6
  int v77; // r28
  idGuiListBox *v78; // r3
  __int64 v79; // r10
  __int64 v80; // r8
  __int64 v81; // r6
  idGuiListBox *v82; // r3
  idGuiListBox *v83; // r3
  __int64 v84; // r8
  __int64 v85; // r10
  __int64 v86; // r6
  int selectedRow; // r11
  double v88; // fp9
  int v89; // [sp+8h] [-1198h]
  int v90; // [sp+8h] [-1198h]
  int v91; // [sp+Ch] [-1194h]
  int v92; // [sp+Ch] [-1194h]
  int v93; // [sp+10h] [-1190h]
  int v94; // [sp+10h] [-1190h]
  int v95; // [sp+14h] [-118Ch]
  int v96; // [sp+14h] [-118Ch]
  int v97; // [sp+18h] [-1188h]
  int v98; // [sp+18h] [-1188h]
  int v99; // [sp+1Ch] [-1184h]
  int v100; // [sp+1Ch] [-1184h]
  const char *v101[5]; // [sp+50h] [-1150h] BYREF
  int v102; // [sp+64h] [-113Ch]
  idDevGuiListBox v103; // [sp+70h] [-1130h] BYREF
  idStr v104; // [sp+130h] [-1070h] BYREF
  va v105; // [sp+150h] [-1050h] BYREF

  idDevGuiListBox::idDevGuiListBox(this: &v103, x: xPos, y: yPos, page: context, a5, a6: (int)this);
  v7 = idGuiListBox::Row(this: &v103);
  idGuiListBox::Printf(this: v7, fmt: "- PLAYER -", a3: v10, a4: v9, a5: v8);
  if ( this->isActive )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    if ( DebugPlayer == nullptr )
      goto LABEL_9;
    v12 = (_cntlzw(this->renderedOnce) & 0x20) != 0;
    idStr::idStr(this: &v104, text: "Third_Person");
    v13 = idGuiListBox::Row(this: &v103);
    HIDWORD(v14) = "plode - unlink clip";
    v17 = idGuiListBox::Printf(this: v13, fmt: "3rd Person Cmds", a3: v16, a4: v14, a5: v15);
    LODWORD(v18) = byte_821B0000;
    v21 = idGuiListBox::Printf(this: v17, fmt: " ", a3: v18, a4: v20, a5: v19);
    idGuiListBox::SetChildWindow(this: v21, childName: &v104, page: this);
    idStr::FreeData(this: &v104);
    HIDWORD(v22) = DebugPlayer->entityNumber;
    v25 = va::va(
            this: &v105,
            fmt: "killPlayer %d",
            a3: v22,
            a4: v24,
            a5: v23,
            a6: v89,
            a7: v91,
            a8: v93,
            a9: v95,
            a10: v97,
            a11: v99);
    v26 = idGuiListBox::Row(this: &v103);
    v30 = idGuiListBox::Printf(this: v26, fmt: "Suicide", a3: v29, a4: v28, a5: v27);
    idGuiListBox::Command(this: v30, commandName: v25->buffer, verifyCmdName: v12);
    LOBYTE(v25) = g_showHud.valueInteger != 0;
    v31 = idGuiListBox::Row(this: &v103);
    HIDWORD(v32) = "plode - unlink clip";
    v35 = idGuiListBox::Printf(this: v31, fmt: "Show Hud", a3: v34, a4: v32, a5: v33);
    v36 = idGuiListBox::Command(this: v35, commandName: "toggle g_showHud 0 1", verifyCmdName: v12);
    idGuiListBox::DrawCheckMark(this: v36, checked: (char)v25);
    LOBYTE(v25) = hands_show.valueInteger != 0;
    v37 = idGuiListBox::Row(this: &v103);
    HIDWORD(v38) = "plode - unlink clip";
    v41 = idGuiListBox::Printf(this: v37, fmt: "Show Hands", a3: v40, a4: v39, a5: v38);
    v42 = idGuiListBox::Command(this: v41, commandName: "toggle hands_show", verifyCmdName: v12);
    idGuiListBox::DrawCheckMark(this: v42, checked: (char)v25);
    LOBYTE(v25) = idPlayer::GetGodMode(this: DebugPlayer);
    v43 = idGuiListBox::Row(this: &v103);
    HIDWORD(v44) = "plode - unlink clip";
    v47 = idGuiListBox::Printf(this: v43, fmt: "God Mode", a3: v46, a4: v44, a5: v45);
    v48 = idGuiListBox::Command(this: v47, commandName: "god", verifyCmdName: v12);
    idGuiListBox::DrawCheckMark(this: v48, checked: (char)v25);
    LOBYTE(v25) = (*((_BYTE *)DebugPlayer + 12824) & 0x10) != 0;
    v49 = idGuiListBox::Row(this: &v103);
    v53 = idGuiListBox::Printf(this: v49, fmt: "No Player Death", a3: v52, a4: v51, a5: v50);
    v54 = idGuiListBox::Command(this: v53, commandName: "NoPlayerDeath", verifyCmdName: v12);
    idGuiListBox::DrawCheckMark(this: v54, checked: (char)v25);
    Noclip = idPlayer::GetNoclip(this: DebugPlayer);
    v56 = idGuiListBox::Row(this: &v103);
    LODWORD(v57) = "plode - unlink clip";
    v60 = idGuiListBox::Printf(this: v56, fmt: "No Clip", a3: v59, a4: v58, a5: v57);
    v61 = idGuiListBox::Command(this: v60, commandName: "noclip", verifyCmdName: v12);
    idGuiListBox::DrawCheckMark(this: v61, checked: Noclip);
    LODWORD(v62) = &idEventDef::eventDefList[3154];
    HIDWORD(v62) = "plode - unlink clip";
    LODWORD(v63) = &g_damageScale;
    *(double *)((char *)&v63 + 4) = g_damageScale.valueFloat;
    v65 = va::va(
            this: &v105,
            fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(g_damageScale.valueFloat)),
            a3: v63,
            a4: v62,
            a5: v64,
            a6: v90,
            a7: v92,
            a8: v94,
            a9: v96,
            a10: v98,
            a11: v100);
    v66 = idGuiListBox::Row(this: &v103);
    v70 = idGuiListBox::Printf(this: v66, fmt: v65->buffer, a3: v69, a4: v68, a5: v67);
    v74 = idGuiListBox::Printf(this: v70, fmt: " ", a3: v73, a4: v72, a5: v71);
    idGuiListBox::ChangeCvar(
      this: v74,
      cvarName: "g_damageScale",
      minValue: 1.0,
      maxValue: 10.0,
      delta: 0.5,
      callBack: (void (__fastcall *)(const bool))0x82000000,
      canHoldToAdvance: v76,
      a8: v75,
      a9: (int)idDevGui::CallBack_ClearButtonDown,
      a10: 0);
    v101[0] = "None";
    v101[1] = "Dist To Ent";
    v101[2] = "Dist To Surface";
    v102 = (int)(float)(g_showCrosshairInfo.valueMax + (float)1.0);
    v77 = v102;
    v78 = idGuiListBox::Row(this: &v103);
    HIDWORD(v79) = "plode - unlink clip";
    v82 = idGuiListBox::Printf(this: v78, fmt: "Show CrossHair Info: ", a3: v81, a4: v80, a5: v79);
    v83 = idGuiListBox::ComboBoxCvar(this: v82, cvar: &g_showCrosshairInfo, items: v101, numItems: v77);
    LODWORD(v84) = "plode - unlink clip";
    idGuiListBox::Printf(this: v83, fmt: "<->", a3: v86, a4: v84, a5: v85);
  }
  selectedRow = this->selectedRow;
  if ( selectedRow >= this->DEFAULT_ROW_NUM )
  {
    if ( selectedRow > v103.rows.num - 1 )
      selectedRow = this->DEFAULT_ROW_NUM;
  }
  else
  {
    selectedRow = v103.rows.num - 1;
  }
  this->selectedRow = selectedRow;
  idGuiListBox::Render(
    this: &v103,
    page: v103.parent,
    (idDeviceContext *)context,
    hAlign: 3u,
    vAlign: 3u,
    nextTo: nullptr);
  v88 = (float)(v103.renderHeight + v103.renderY);
  this->renderX = v103.renderWidth + v103.renderX;
  this->renderY = v88;
  idDevGuiMainPage::RenderChildPages(this, (idDeviceContext *)context);
LABEL_9:
  v103.__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  idGuiListBox::~idGuiListBox(this: &v103);
}


// ========================================================================
// __unwind$491123_0
// EA  : 0x82EB0DCC
// RVA : 0x00EB0DCC
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_491123_0()
{
  int v0; // r12

  idDevGuiListBox::~idDevGuiListBox(this: (idDevGuiListBox *)(v0 - 4512 + 112));
}


// ========================================================================
// __unwind$491124_0
// EA  : 0x82EB0DF4
// RVA : 0x00EB0DF4
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_491124_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4512 + 304));
}


// ========================================================================
// ?InternalRender@idDevGuiChildPage_ThirdPerson@@EAAXAAVidDeviceContext@@MM@Z
// EA  : 0x82EB0E28
// RVA : 0x00EB0E28
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiChildPage_ThirdPerson::InternalRender(
        idDevGuiChildPage_ThirdPerson *this,
        idDevGuiPage *context,
        double xPos,
        double yPos,
        int a5)
{
  bool v7; // r27
  idGuiListBox *v8; // r3
  __int64 v9; // r8
  __int64 v10; // r10
  __int64 v11; // r6
  idGuiListBox *v12; // r3
  __int128 v13; // r6
  __int64 v14; // r10
  __int64 v15; // r8
  va *v16; // r29
  idGuiListBox *v17; // r3
  __int64 v18; // r10
  __int64 v19; // r8
  __int64 v20; // r6
  idGuiListBox *v21; // r3
  __int64 v22; // r10
  __int64 v23; // r8
  __int64 v24; // r6
  idGuiListBox *v25; // r3
  __int128 v26; // r6
  __int64 v27; // r10
  __int64 v28; // r8
  va *v29; // r26
  idGuiListBox *v30; // r3
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r6
  idGuiListBox *v34; // r3
  __int64 v35; // r10
  __int64 v36; // r8
  __int64 v37; // r6
  idGuiListBox *v38; // r3
  bool v39; // r6
  void (__fastcall *v40)(const bool); // r5
  __int128 v41; // r6
  __int64 v42; // r10
  __int64 v43; // r8
  va *v44; // r26
  idGuiListBox *v45; // r3
  __int64 v46; // r10
  __int64 v47; // r8
  __int64 v48; // r6
  idGuiListBox *v49; // r3
  __int64 v50; // r10
  __int64 v51; // r8
  __int64 v52; // r6
  idGuiListBox *v53; // r3
  bool v54; // r6
  void (__fastcall *v55)(const bool); // r5
  idGuiListBox *v56; // r3
  __int64 v57; // r10
  __int64 v58; // r8
  __int64 v59; // r6
  idGuiListBox *v60; // r3
  idGuiListBox *v61; // r3
  idGuiListBox *v62; // r3
  __int64 v63; // r8
  __int64 v64; // r10
  __int64 v65; // r6
  idGuiListBox *v66; // r3
  int selectedRow; // r11
  int v68; // [sp+8h] [-1148h]
  int v69; // [sp+8h] [-1148h]
  int v70; // [sp+8h] [-1148h]
  int v71; // [sp+Ch] [-1144h]
  int v72; // [sp+Ch] [-1144h]
  int v73; // [sp+Ch] [-1144h]
  int v74; // [sp+10h] [-1140h]
  int v75; // [sp+10h] [-1140h]
  int v76; // [sp+10h] [-1140h]
  int v77; // [sp+14h] [-113Ch]
  int v78; // [sp+14h] [-113Ch]
  int v79; // [sp+14h] [-113Ch]
  int v80; // [sp+18h] [-1138h]
  int v81; // [sp+18h] [-1138h]
  int v82; // [sp+18h] [-1138h]
  int v83; // [sp+1Ch] [-1134h]
  int v84; // [sp+1Ch] [-1134h]
  int v85; // [sp+1Ch] [-1134h]
  idDevGuiListBox v86; // [sp+50h] [-1100h] BYREF
  va v87; // [sp+110h] [-1040h] BYREF

  idDevGuiListBox::idDevGuiListBox(this: &v86, x: xPos, y: yPos, page: context, a5, a6: (int)this);
  v7 = (_cntlzw(this->renderedOnce) & 0x20) != 0;
  v8 = idGuiListBox::Row(this: &v86);
  LODWORD(v9) = "plode - unlink clip";
  v12 = idGuiListBox::Printf(this: v8, fmt: "3rd Person", a3: v11, a4: v9, a5: v10);
  idGuiListBox::Command(this: v12, commandName: "toggle pm_thirdPerson", verifyCmdName: v7);
  LODWORD(v13) = &idEventDef::eventDefList[3154];
  *(double *)((char *)&v13 + 4) = pm_thirdPersonRange.valueFloat;
  v16 = va::va(
          this: &v87,
          fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(pm_thirdPersonRange.valueFloat)),
          a3: v13,
          a4: v15,
          a5: v14,
          a6: v68,
          a7: v71,
          a8: v74,
          a9: v77,
          a10: v80,
          a11: v83);
  v17 = idGuiListBox::Row(this: &v86);
  v21 = idGuiListBox::Printf(this: v17, fmt: v16->buffer, a3: v20, a4: v19, a5: v18);
  LODWORD(v22) = byte_821B0000;
  v25 = idGuiListBox::Printf(this: v21, fmt: " ", a3: v24, a4: v23, a5: v22);
  idGuiListBox::ChangeCvar(
    this: v25,
    cvarName: "pm_thirdPersonRange",
    minValue: 64.0,
    maxValue: 1024.0,
    delta: 10.0,
    callBack: (void (__fastcall *)(const bool))sub_82EB0000,
    canHoldToAdvance: (const bool)"WriteBoundedFloatBase",
    a8: 0x82000000,
    a9: (int)idDevGui::CallBack_HadButtonError,
    a10: 1);
  *(double *)((char *)&v26 + 4) = pm_thirdPersonHeight.valueFloat;
  v29 = va::va(
          this: &v87,
          fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(pm_thirdPersonHeight.valueFloat)),
          a3: v26,
          a4: v28,
          a5: v27,
          a6: v69,
          a7: v72,
          a8: v75,
          a9: v78,
          a10: v81,
          a11: v84);
  v30 = idGuiListBox::Row(this: &v86);
  v34 = idGuiListBox::Printf(this: v30, fmt: v29->buffer, a3: v33, a4: v32, a5: v31);
  v38 = idGuiListBox::Printf(this: v34, fmt: " ", a3: v37, a4: v36, a5: v35);
  idGuiListBox::ChangeCvar(
    this: v38,
    cvarName: "pm_thirdPersonHeight",
    minValue: -1024.0,
    maxValue: 1024.0,
    delta: 1.0,
    callBack: v40,
    canHoldToAdvance: v39,
    a8: 0x82000000,
    a9: (int)idDevGui::CallBack_HadButtonError,
    a10: 1);
  LODWORD(v41) = &idEventDef::eventDefList[3154];
  *(double *)((char *)&v41 + 4) = pm_thirdPersonAngle.valueFloat;
  v44 = va::va(
          this: &v87,
          fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(pm_thirdPersonAngle.valueFloat)),
          a3: v41,
          a4: v43,
          a5: v42,
          a6: v70,
          a7: v73,
          a8: v76,
          a9: v79,
          a10: v82,
          a11: v85);
  v45 = idGuiListBox::Row(this: &v86);
  v49 = idGuiListBox::Printf(this: v45, fmt: v44->buffer, a3: v48, a4: v47, a5: v46);
  v53 = idGuiListBox::Printf(this: v49, fmt: " ", a3: v52, a4: v51, a5: v50);
  idGuiListBox::ChangeCvar(
    this: v53,
    cvarName: "pm_thirdPersonAngle",
    minValue: -180.0,
    maxValue: 180.0,
    delta: 1.0,
    callBack: v55,
    canHoldToAdvance: v54,
    a8: (int)sub_82EB0000,
    a9: (int)idDevGui::CallBack_HadButtonError,
    a10: 1);
  LOBYTE(v16) = pm_thirdPersonClip.valueInteger != 0;
  v56 = idGuiListBox::Row(this: &v86);
  v60 = idGuiListBox::Printf(this: v56, fmt: "3rd Person NoClip", a3: v59, a4: v58, a5: v57);
  v61 = idGuiListBox::Command(this: v60, commandName: "toggle pm_thirdPersonClip", verifyCmdName: v7);
  idGuiListBox::DrawCheckMark(this: v61, checked: (_cntlzw((unsigned __int8)v16) & 0x20) != 0);
  v62 = idGuiListBox::Row(this: &v86);
  HIDWORD(v63) = "plode - unlink clip";
  v66 = idGuiListBox::Printf(this: v62, fmt: "3rd Person Reset All", a3: v65, a4: v63, a5: v64);
  idGuiListBox::Command(this: v66, commandName: "ThirdPersonReset", verifyCmdName: v7);
  selectedRow = this->selectedRow;
  if ( selectedRow >= this->DEFAULT_ROW_NUM )
  {
    if ( selectedRow > v86.rows.num - 1 )
      selectedRow = this->DEFAULT_ROW_NUM;
  }
  else
  {
    selectedRow = v86.rows.num - 1;
  }
  this->selectedRow = selectedRow;
  idGuiListBox::Render(
    this: &v86,
    page: v86.parent,
    (idDeviceContext *)context,
    hAlign: 3u,
    vAlign: 3u,
    nextTo: nullptr);
  v86.__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  idGuiListBox::~idGuiListBox(this: &v86);
}


// ========================================================================
// __unwind$491240
// EA  : 0x82EB10B4
// RVA : 0x00EB10B4
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_491240()
{
  int v0; // r12

  idDevGuiListBox::~idDevGuiListBox(this: (idDevGuiListBox *)(v0 - 4432 + 80));
}


// ========================================================================
// ?InternalRender@idDevGuiMainPage_Weapon@@EAAXAAVidDeviceContext@@MM@Z
// EA  : 0x82EB10E8
// RVA : 0x00EB10E8
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage_Weapon::InternalRender(
        idDevGuiMainPage_Weapon *this,
        idDevGuiPage *context,
        double xPos,
        double yPos,
        int a5)
{
  idGuiListBox *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  bool v11; // r27
  char v12; // r29
  idGuiListBox *v13; // r3
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  idGuiListBox *v17; // r3
  idGuiListBox *v18; // r3
  idGuiListBox *v19; // r3
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  idGuiListBox *v23; // r3
  char v24; // r29
  idGuiListBox *v25; // r3
  __int64 v26; // r6
  __int64 v27; // r10
  __int64 v28; // r8
  idGuiListBox *v29; // r3
  idGuiListBox *v30; // r3
  unsigned int v31; // r29
  idGuiListBox *v32; // r3
  __int64 v33; // r8
  __int64 v34; // r10
  __int64 v35; // r6
  idGuiListBox *v36; // r3
  idGuiListBox *v37; // r3
  int selectedRow; // r11
  double v39; // fp9
  idDevGuiListBox v40; // [sp+50h] [-F0h] BYREF

  idDevGuiListBox::idDevGuiListBox(this: &v40, x: xPos, y: yPos, page: context, a5, a6: (int)this);
  v7 = idGuiListBox::Row(this: &v40);
  idGuiListBox::Printf(this: v7, fmt: "- WEAPON -", a3: v10, a4: v9, a5: v8);
  if ( this->isActive )
  {
    v11 = (_cntlzw(this->renderedOnce) & 0x20) != 0;
    v12 = g_infiniteAmmo.valueInteger != 0;
    v13 = idGuiListBox::Row(this: &v40);
    HIDWORD(v14) = "plode - unlink clip";
    v17 = idGuiListBox::Printf(this: v13, fmt: "Infinite Ammo", a3: v14, a4: v16, a5: v15);
    v18 = idGuiListBox::Command(this: v17, commandName: "toggle g_infiniteAmmo", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v18, checked: v12);
    v19 = idGuiListBox::Row(this: &v40);
    v23 = idGuiListBox::Printf(this: v19, fmt: "Give Grenades", a3: v22, a4: v21, a5: v20);
    idGuiListBox::Command(this: v23, commandName: "give throwable/player/grenade", verifyCmdName: v11);
    v24 = g_debugWeapon.valueInteger != 0;
    v25 = idGuiListBox::Row(this: &v40);
    LODWORD(v26) = "plode - unlink clip";
    v29 = idGuiListBox::Printf(this: v25, fmt: "Show Weapon Traces", a3: v26, a4: v28, a5: v27);
    v30 = idGuiListBox::Command(this: v29, commandName: "toggle g_debugWeapon", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v30, checked: v24);
    v31 = (-g_showSpread.valueInteger & (unsigned int)~g_showSpread.valueInteger) >> 31;
    v32 = idGuiListBox::Row(this: &v40);
    HIDWORD(v33) = "plode - unlink clip";
    v36 = idGuiListBox::Printf(this: v32, fmt: "Show Weapon Spread", a3: v35, a4: v33, a5: v34);
    v37 = idGuiListBox::Command(this: v36, commandName: "toggle g_showSpread 0 2", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v37, checked: v31);
  }
  selectedRow = this->selectedRow;
  if ( selectedRow >= this->DEFAULT_ROW_NUM )
  {
    if ( selectedRow > v40.rows.num - 1 )
      selectedRow = this->DEFAULT_ROW_NUM;
  }
  else
  {
    selectedRow = v40.rows.num - 1;
  }
  this->selectedRow = selectedRow;
  idGuiListBox::Render(
    this: &v40,
    page: v40.parent,
    (idDeviceContext *)context,
    hAlign: 3u,
    vAlign: 3u,
    nextTo: nullptr);
  v39 = (float)(v40.renderHeight + v40.renderY);
  this->renderX = v40.renderWidth + v40.renderX;
  this->renderY = v39;
  idDevGuiMainPage::RenderChildPages(this, (idDeviceContext *)context);
  v40.__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  idGuiListBox::~idGuiListBox(this: &v40);
}


// ========================================================================
// __unwind$491329
// EA  : 0x82EB12B4
// RVA : 0x00EB12B4
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_491329()
{
  int v0; // r12

  idDevGuiListBox::~idDevGuiListBox(this: (idDevGuiListBox *)(v0 - 320 + 80));
}


// ========================================================================
// ?InternalRender@idDevGuiMainPage_Render@@EAAXAAVidDeviceContext@@MM@Z
// EA  : 0x82EB12E8
// RVA : 0x00EB12E8
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage_Render::InternalRender(
        idDevGuiMainPage_Render *this,
        idDevGuiPage *context,
        double xPos,
        double yPos,
        int a5)
{
  idGuiListBox *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  bool v11; // r27
  idGuiListBox *v12; // r3
  __int64 v13; // r8
  __int64 v14; // r10
  __int64 v15; // r6
  idGuiListBox *v16; // r3
  char v17; // r29
  idGuiListBox *v18; // r3
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  idGuiListBox *v22; // r3
  idGuiListBox *v23; // r3
  char v24; // r29
  idGuiListBox *v25; // r3
  __int64 v26; // r6
  __int64 v27; // r10
  __int64 v28; // r8
  idGuiListBox *v29; // r3
  idGuiListBox *v30; // r3
  char v31; // r29
  idGuiListBox *v32; // r3
  __int64 v33; // r8
  __int64 v34; // r10
  __int64 v35; // r6
  idGuiListBox *v36; // r3
  idGuiListBox *v37; // r3
  char v38; // r29
  idGuiListBox *v39; // r3
  __int64 v40; // r10
  __int64 v41; // r8
  __int64 v42; // r6
  idGuiListBox *v43; // r3
  idGuiListBox *v44; // r3
  unsigned int v45; // r29
  idGuiListBox *v46; // r3
  __int64 v47; // r6
  __int64 v48; // r10
  __int64 v49; // r8
  idGuiListBox *v50; // r3
  idGuiListBox *v51; // r3
  idGuiListBox *v52; // r3
  __int64 v53; // r8
  __int64 v54; // r10
  __int64 v55; // r6
  idGuiListBox *v56; // r3
  idGuiListBox *v57; // r3
  idGuiListBox *v58; // r3
  __int64 v59; // r10
  __int64 v60; // r8
  __int64 v61; // r6
  idGuiListBox *v62; // r3
  idGuiListBox *v63; // r3
  unsigned int v64; // r29
  idGuiListBox *v65; // r3
  __int64 v66; // r6
  __int64 v67; // r10
  __int64 v68; // r8
  idGuiListBox *v69; // r3
  idGuiListBox *v70; // r3
  unsigned int v71; // r29
  idGuiListBox *v72; // r3
  __int64 v73; // r8
  __int64 v74; // r10
  __int64 v75; // r6
  idGuiListBox *v76; // r3
  idGuiListBox *v77; // r3
  idGuiListBox *v78; // r3
  __int64 v79; // r10
  __int64 v80; // r8
  __int64 v81; // r6
  idGuiListBox *v82; // r3
  idGuiListBox *v83; // r3
  idGuiListBox *v84; // r3
  __int64 v85; // r10
  __int64 v86; // r8
  __int64 v87; // r6
  idGuiListBox *v88; // r3
  idGuiListBox *v89; // r3
  idGuiListBox *v90; // r3
  __int64 v91; // r10
  __int64 v92; // r8
  __int64 v93; // r6
  idGuiListBox *v94; // r3
  __int64 v95; // r8
  __int64 v96; // r10
  __int64 v97; // r6
  idGuiListBox *v98; // r3
  int selectedRow; // r11
  double v100; // fp9
  idDevGuiListBox v101; // [sp+50h] [-110h] BYREF
  idStr v102[2]; // [sp+110h] [-50h] BYREF

  idDevGuiListBox::idDevGuiListBox(this: &v101, x: xPos, y: yPos, page: context, a5, a6: (int)this);
  v7 = idGuiListBox::Row(this: &v101);
  idGuiListBox::Printf(this: v7, fmt: "- RENDER -", a3: v10, a4: v9, a5: v8);
  if ( this->isActive )
  {
    v11 = (_cntlzw(this->renderedOnce) & 0x20) != 0;
    v12 = idGuiListBox::Row(this: &v101);
    LODWORD(v13) = "plode - unlink clip";
    v16 = idGuiListBox::Printf(this: v12, fmt: "Simple Shade", a3: v15, a4: v13, a5: v14);
    idGuiListBox::Command(this: v16, commandName: "simpleshade", verifyCmdName: v11);
    v17 = r_skipWorld.valueInteger != 0;
    v18 = idGuiListBox::Row(this: &v101);
    v22 = idGuiListBox::Printf(this: v18, fmt: "Skip World", a3: v21, a4: v20, a5: v19);
    v23 = idGuiListBox::Command(this: v22, commandName: "toggle r_skipWorld", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v23, checked: v17);
    v24 = r_showSurfaceInfo.valueInteger != 0;
    v25 = idGuiListBox::Row(this: &v101);
    LODWORD(v26) = "plode - unlink clip";
    v29 = idGuiListBox::Printf(this: v25, fmt: "Show Surface Info", a3: v26, a4: v28, a5: v27);
    v30 = idGuiListBox::Command(this: v29, commandName: "toggle r_showSurfaceInfo", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v30, checked: v24);
    v31 = r_skipPostProcess.valueInteger != 0;
    v32 = idGuiListBox::Row(this: &v101);
    LODWORD(v33) = "plode - unlink clip";
    v36 = idGuiListBox::Printf(this: v32, fmt: "Skip Post Process", a3: v35, a4: v33, a5: v34);
    v37 = idGuiListBox::Command(this: v36, commandName: "toggle r_skipPostProcess", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v37, checked: v31);
    v38 = r_showAmbientLighting.valueInteger != 0;
    v39 = idGuiListBox::Row(this: &v101);
    v43 = idGuiListBox::Printf(this: v39, fmt: "Show Ambient Light", a3: v42, a4: v41, a5: v40);
    v44 = idGuiListBox::Command(this: v43, commandName: "toggle r_showAmbientLighting", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v44, checked: v38);
    v45 = (-r_showTris.valueInteger & (unsigned int)~r_showTris.valueInteger) >> 31;
    v46 = idGuiListBox::Row(this: &v101);
    HIDWORD(v47) = "plode - unlink clip";
    v50 = idGuiListBox::Printf(this: v46, fmt: "Show Tris", a3: v47, a4: v49, a5: v48);
    v51 = idGuiListBox::Command(this: v50, commandName: "toggle r_showTris 0 4", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v51, checked: v45);
    LOBYTE(v45) = r_showTrace.valueInteger != 0;
    v52 = idGuiListBox::Row(this: &v101);
    LODWORD(v53) = "plode - unlink clip";
    v56 = idGuiListBox::Printf(this: v52, fmt: "Show Trace", a3: v55, a4: v53, a5: v54);
    v57 = idGuiListBox::Command(this: v56, commandName: "toggle r_showTrace", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v57, checked: v45);
    LOBYTE(v45) = g_showCollisionWorld.valueInteger != 0;
    v58 = idGuiListBox::Row(this: &v101);
    v62 = idGuiListBox::Printf(this: v58, fmt: "Show Collision World", a3: v61, a4: v60, a5: v59);
    v63 = idGuiListBox::Command(this: v62, commandName: "toggle g_showCollisionWorld", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v63, checked: v45);
    v64 = (-g_showCollisionModels.valueInteger & (unsigned int)~g_showCollisionModels.valueInteger) >> 31;
    v65 = idGuiListBox::Row(this: &v101);
    HIDWORD(v66) = "plode - unlink clip";
    v69 = idGuiListBox::Printf(this: v65, fmt: "Show Collision Models", a3: v66, a4: v68, a5: v67);
    v70 = idGuiListBox::Command(this: v69, commandName: "toggle g_showCollisionModels 0 1", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v70, checked: v64);
    v71 = (-g_showCollisionSurfaces.valueInteger & (unsigned int)~g_showCollisionSurfaces.valueInteger) >> 31;
    v72 = idGuiListBox::Row(this: &v101);
    HIDWORD(v73) = "plode - unlink clip";
    v76 = idGuiListBox::Printf(this: v72, fmt: "Show Collision Surfaces", a3: v75, a4: v73, a5: v74);
    v77 = idGuiListBox::Command(this: v76, commandName: "toggle g_showCollisionSurfaces 0 1", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v77, checked: v71);
    LOBYTE(v71) = r_showDuplicateTriangles.valueInteger != 0;
    v78 = idGuiListBox::Row(this: &v101);
    HIDWORD(v79) = "plode - unlink clip";
    v82 = idGuiListBox::Printf(this: v78, fmt: "Show Dup Triangles", a3: v81, a4: v80, a5: v79);
    v83 = idGuiListBox::Command(this: v82, commandName: "toggle r_showDuplicateTriangles", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v83, checked: v71);
    LOBYTE(v71) = r_showCracks.valueInteger != 0;
    v84 = idGuiListBox::Row(this: &v101);
    v88 = idGuiListBox::Printf(this: v84, fmt: "Show Cracks", a3: v87, a4: v86, a5: v85);
    v89 = idGuiListBox::Command(this: v88, commandName: "toggle r_showCracks", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v89, checked: v71);
    idStr::idStr(this: v102, text: "Render_Reload");
    v90 = idGuiListBox::Row(this: &v101);
    HIDWORD(v91) = "plode - unlink clip";
    v94 = idGuiListBox::Printf(this: v90, fmt: "Reload Cmds", a3: v93, a4: v92, a5: v91);
    LODWORD(v95) = byte_821B0000;
    v98 = idGuiListBox::Printf(this: v94, fmt: " ", a3: v97, a4: v95, a5: v96);
    idGuiListBox::SetChildWindow(this: v98, childName: v102, page: this);
    idStr::FreeData(this: v102);
  }
  selectedRow = this->selectedRow;
  if ( selectedRow >= this->DEFAULT_ROW_NUM )
  {
    if ( selectedRow > v101.rows.num - 1 )
      selectedRow = this->DEFAULT_ROW_NUM;
  }
  else
  {
    selectedRow = v101.rows.num - 1;
  }
  this->selectedRow = selectedRow;
  idGuiListBox::Render(
    this: &v101,
    page: v101.parent,
    (idDeviceContext *)context,
    hAlign: 3u,
    vAlign: 3u,
    nextTo: nullptr);
  v100 = (float)(v101.renderHeight + v101.renderY);
  this->renderX = v101.renderWidth + v101.renderX;
  this->renderY = v100;
  idDevGuiMainPage::RenderChildPages(this, (idDeviceContext *)context);
  v101.__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  idGuiListBox::~idGuiListBox(this: &v101);
}


// ========================================================================
// __unwind$491470_0
// EA  : 0x82EB1700
// RVA : 0x00EB1700
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_491470_0()
{
  int v0; // r12

  idDevGuiListBox::~idDevGuiListBox(this: (idDevGuiListBox *)(v0 - 352 + 80));
}


// ========================================================================
// __unwind$491471
// EA  : 0x82EB1728
// RVA : 0x00EB1728
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_491471()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 272));
}


// ========================================================================
// ?InternalRender@idDevGuiChildPage_Reload@@EAAXAAVidDeviceContext@@MM@Z
// EA  : 0x82EB1758
// RVA : 0x00EB1758
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiChildPage_Reload::InternalRender(
        idDevGuiChildPage_Reload *this,
        idDevGuiPage *context,
        double xPos,
        double yPos,
        int a5)
{
  bool v7; // r28
  idGuiListBox *v8; // r3
  __int64 v9; // r8
  __int64 v10; // r10
  __int64 v11; // r6
  idGuiListBox *v12; // r3
  idGuiListBox *v13; // r3
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  idGuiListBox *v17; // r3
  idGuiListBox *v18; // r3
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  idGuiListBox *v22; // r3
  idGuiListBox *v23; // r3
  __int64 v24; // r10
  __int64 v25; // r8
  __int64 v26; // r6
  idGuiListBox *v27; // r3
  idGuiListBox *v28; // r3
  __int64 v29; // r8
  __int64 v30; // r10
  __int64 v31; // r6
  idGuiListBox *v32; // r3
  int selectedRow; // r11
  idDevGuiListBox v34; // [sp+50h] [-E0h] BYREF

  idDevGuiListBox::idDevGuiListBox(this: &v34, x: xPos, y: yPos, page: context, a5, a6: (int)this);
  v7 = (_cntlzw(this->renderedOnce) & 0x20) != 0;
  v8 = idGuiListBox::Row(this: &v34);
  LODWORD(v9) = "plode - unlink clip";
  v12 = idGuiListBox::Printf(this: v8, fmt: "Reload Models", a3: v11, a4: v9, a5: v10);
  idGuiListBox::Command(this: v12, commandName: "reloadModels", verifyCmdName: v7);
  v13 = idGuiListBox::Row(this: &v34);
  LODWORD(v14) = "plode - unlink clip";
  v17 = idGuiListBox::Printf(this: v13, fmt: "Reload Decls", a3: v14, a4: v16, a5: v15);
  idGuiListBox::Command(this: v17, commandName: "reloadDecls", verifyCmdName: v7);
  v18 = idGuiListBox::Row(this: &v34);
  v22 = idGuiListBox::Printf(this: v18, fmt: "Reload VMTR", a3: v21, a4: v20, a5: v19);
  idGuiListBox::Command(this: v22, commandName: "reloadVirtualMaterials", verifyCmdName: v7);
  v23 = idGuiListBox::Row(this: &v34);
  HIDWORD(v24) = "plode - unlink clip";
  v27 = idGuiListBox::Printf(this: v23, fmt: "Reload Images", a3: v26, a4: v25, a5: v24);
  idGuiListBox::Command(this: v27, commandName: "reloadImages", verifyCmdName: v7);
  v28 = idGuiListBox::Row(this: &v34);
  HIDWORD(v29) = "plode - unlink clip";
  v32 = idGuiListBox::Printf(this: v28, fmt: "Reload Surface", a3: v31, a4: v29, a5: v30);
  idGuiListBox::Command(this: v32, commandName: "reloadSurface", verifyCmdName: v7);
  selectedRow = this->selectedRow;
  if ( selectedRow >= this->DEFAULT_ROW_NUM )
  {
    if ( selectedRow > v34.rows.num - 1 )
      selectedRow = this->DEFAULT_ROW_NUM;
  }
  else
  {
    selectedRow = v34.rows.num - 1;
  }
  this->selectedRow = selectedRow;
  idGuiListBox::Render(
    this: &v34,
    page: v34.parent,
    (idDeviceContext *)context,
    hAlign: 3u,
    vAlign: 3u,
    nextTo: nullptr);
  v34.__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  idGuiListBox::~idGuiListBox(this: &v34);
}


// ========================================================================
// __unwind$491587_0
// EA  : 0x82EB18A4
// RVA : 0x00EB18A4
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_491587_0()
{
  int v0; // r12

  idDevGuiListBox::~idDevGuiListBox(this: (idDevGuiListBox *)(v0 - 304 + 80));
}


// ========================================================================
// ?InternalRender@idDevGuiMainPage_Design@@EAAXAAVidDeviceContext@@MM@Z
// EA  : 0x82EB18D8
// RVA : 0x00EB18D8
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage_Design::InternalRender(
        idDevGuiMainPage_Design *this,
        idDevGuiPage *context,
        double xPos,
        double yPos,
        int a5)
{
  idGuiListBox *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  bool v11; // r27
  unsigned int v12; // r29
  idGuiListBox *v13; // r3
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  idGuiListBox *v17; // r3
  idGuiListBox *v18; // r3
  unsigned int v19; // r29
  idGuiListBox *v20; // r3
  __int64 v21; // r6
  __int64 v22; // r10
  __int64 v23; // r8
  idGuiListBox *v24; // r3
  idGuiListBox *v25; // r3
  idGuiListBox *v26; // r3
  __int64 v27; // r10
  __int64 v28; // r8
  __int64 v29; // r6
  idGuiListBox *v30; // r3
  idGuiListBox *v31; // r3
  __int64 v32; // r6
  __int64 v33; // r10
  __int64 v34; // r8
  idGuiListBox *v35; // r3
  idGuiListBox *v36; // r3
  int selectedRow; // r11
  double v38; // fp9
  idDevGuiListBox v39; // [sp+50h] [-F0h] BYREF

  idDevGuiListBox::idDevGuiListBox(this: &v39, x: xPos, y: yPos, page: context, a5, a6: (int)this);
  v7 = idGuiListBox::Row(this: &v39);
  idGuiListBox::Printf(this: v7, fmt: "- DESIGN -", a3: v10, a4: v9, a5: v8);
  if ( this->isActive )
  {
    v11 = (_cntlzw(this->renderedOnce) & 0x20) != 0;
    v12 = (-g_spawnDebugLevel.valueInteger & (unsigned int)~g_spawnDebugLevel.valueInteger) >> 31;
    v13 = idGuiListBox::Row(this: &v39);
    v17 = idGuiListBox::Printf(this: v13, fmt: "Show Spawns", a3: v16, a4: v15, a5: v14);
    v18 = idGuiListBox::Command(this: v17, commandName: "toggle g_spawnDebugLevel 0 2", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v18, checked: v12);
    v19 = (-mp_spawnDebugNodeTimeout.valueInteger & (unsigned int)~mp_spawnDebugNodeTimeout.valueInteger) >> 31;
    v20 = idGuiListBox::Row(this: &v39);
    LODWORD(v21) = "plode - unlink clip";
    v24 = idGuiListBox::Printf(this: v20, fmt: "Cycle Thru Spawns", a3: v21, a4: v23, a5: v22);
    v25 = idGuiListBox::Command(this: v24, commandName: "toggle mp_spawnDebugNodeTimeout 0 3", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v25, checked: v19);
    v26 = idGuiListBox::Row(this: &v39);
    v30 = idGuiListBox::Printf(this: v26, fmt: "Show VT Info - Check Console", a3: v29, a4: v28, a5: v27);
    idGuiListBox::Command(this: v30, commandName: "vt_info", verifyCmdName: v11);
    LOBYTE(v19) = vt_showStats.valueInteger != 0;
    v31 = idGuiListBox::Row(this: &v39);
    LODWORD(v32) = "plode - unlink clip";
    v35 = idGuiListBox::Printf(this: v31, fmt: "Show VT Stats - Map Will Restart To Turn On", a3: v32, a4: v34, a5: v33);
    v36 = idGuiListBox::Command(this: v35, commandName: "DisplayVirtualTextureInfo", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v36, checked: v19);
  }
  selectedRow = this->selectedRow;
  if ( selectedRow >= this->DEFAULT_ROW_NUM )
  {
    if ( selectedRow > v39.rows.num - 1 )
      selectedRow = this->DEFAULT_ROW_NUM;
  }
  else
  {
    selectedRow = v39.rows.num - 1;
  }
  this->selectedRow = selectedRow;
  idGuiListBox::Render(
    this: &v39,
    page: v39.parent,
    (idDeviceContext *)context,
    hAlign: 3u,
    vAlign: 3u,
    nextTo: nullptr);
  v38 = (float)(v39.renderHeight + v39.renderY);
  this->renderX = v39.renderWidth + v39.renderX;
  this->renderY = v38;
  idDevGuiMainPage::RenderChildPages(this, (idDeviceContext *)context);
  v39.__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  idGuiListBox::~idGuiListBox(this: &v39);
}


// ========================================================================
// __unwind$491638
// EA  : 0x82EB1AA8
// RVA : 0x00EB1AA8
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_491638()
{
  int v0; // r12

  idDevGuiListBox::~idDevGuiListBox(this: (idDevGuiListBox *)(v0 - 320 + 80));
}


// ========================================================================
// ?InternalRender@idDevGuiMainPage_Sound@@EAAXAAVidDeviceContext@@MM@Z
// EA  : 0x82EB1AD8
// RVA : 0x00EB1AD8
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage_Sound::InternalRender(
        idDevGuiMainPage_Sound *this,
        idDevGuiPage *context,
        double xPos,
        double yPos,
        int a5)
{
  idGuiListBox *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  bool v11; // r28
  unsigned int v12; // r27
  idGuiListBox *v13; // r3
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  idGuiListBox *v17; // r3
  idGuiListBox *v18; // r3
  int selectedRow; // r11
  double v20; // fp9
  idDevGuiListBox v21; // [sp+50h] [-F0h] BYREF

  idDevGuiListBox::idDevGuiListBox(this: &v21, x: xPos, y: yPos, page: context, a5, a6: (int)this);
  v7 = idGuiListBox::Row(this: &v21);
  idGuiListBox::Printf(this: v7, fmt: "- SOUND -", a3: v10, a4: v9, a5: v8);
  if ( this->isActive )
  {
    v11 = (_cntlzw(this->renderedOnce) & 0x20) != 0;
    v12 = (-s_showSounds.valueInteger & (unsigned int)~s_showSounds.valueInteger) >> 31;
    v13 = idGuiListBox::Row(this: &v21);
    v17 = idGuiListBox::Printf(this: v13, fmt: "Show Sounds", a3: v16, a4: v15, a5: v14);
    v18 = idGuiListBox::Command(this: v17, commandName: "toggle s_showSounds", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v18, checked: v12);
  }
  selectedRow = this->selectedRow;
  if ( selectedRow >= this->DEFAULT_ROW_NUM )
  {
    if ( selectedRow > v21.rows.num - 1 )
      selectedRow = this->DEFAULT_ROW_NUM;
  }
  else
  {
    selectedRow = v21.rows.num - 1;
  }
  this->selectedRow = selectedRow;
  idGuiListBox::Render(
    this: &v21,
    page: v21.parent,
    (idDeviceContext *)context,
    hAlign: 3u,
    vAlign: 3u,
    nextTo: nullptr);
  v20 = (float)(v21.renderHeight + v21.renderY);
  this->renderX = v21.renderWidth + v21.renderX;
  this->renderY = v20;
  idDevGuiMainPage::RenderChildPages(this, (idDeviceContext *)context);
  v21.__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  idGuiListBox::~idGuiListBox(this: &v21);
}


// ========================================================================
// __unwind$491715_1
// EA  : 0x82EB1C00
// RVA : 0x00EB1C00
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_491715_1()
{
  int v0; // r12

  idDevGuiListBox::~idDevGuiListBox(this: (idDevGuiListBox *)(v0 - 320 + 80));
}


// ========================================================================
// ?InternalRender@idDevGuiMainPage_QA@@EAAXAAVidDeviceContext@@MM@Z
// EA  : 0x82EB1C30
// RVA : 0x00EB1C30
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage_QA::InternalRender(
        idDevGuiMainPage_QA *this,
        idDevGuiPage *context,
        double xPos,
        double yPos,
        int a5)
{
  idGuiListBox *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  bool v11; // r28
  unsigned int v12; // r27
  idGuiListBox *v13; // r3
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  idGuiListBox *v17; // r3
  idGuiListBox *v18; // r3
  idGuiListBox *v19; // r3
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  idGuiListBox *v23; // r3
  int selectedRow; // r11
  double v25; // fp9
  idDevGuiListBox v26; // [sp+50h] [-F0h] BYREF

  idDevGuiListBox::idDevGuiListBox(this: &v26, x: xPos, y: yPos, page: context, a5, a6: (int)this);
  v7 = idGuiListBox::Row(this: &v26);
  idGuiListBox::Printf(this: v7, fmt: "- QA -", a3: v10, a4: v9, a5: v8);
  if ( this->isActive )
  {
    v11 = (_cntlzw(this->renderedOnce) & 0x20) != 0;
    v12 = (-r_showSkel.valueInteger & (unsigned int)~r_showSkel.valueInteger) >> 31;
    v13 = idGuiListBox::Row(this: &v26);
    v17 = idGuiListBox::Printf(this: v13, fmt: "Show Skeleton", a3: v16, a4: v15, a5: v14);
    v18 = idGuiListBox::Command(this: v17, commandName: "toggle r_showSkel 0 1 2", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v18, checked: v12);
    v19 = idGuiListBox::Row(this: &v26);
    LODWORD(v20) = &unk_82270000;
    v23 = idGuiListBox::Printf(this: v19, fmt: "ScreenShot", a3: v22, a4: v21, a5: v20);
    idGuiListBox::Command(this: v23, commandName: "screenshot", verifyCmdName: v11);
  }
  selectedRow = this->selectedRow;
  if ( selectedRow >= this->DEFAULT_ROW_NUM )
  {
    if ( selectedRow > v26.rows.num - 1 )
      selectedRow = this->DEFAULT_ROW_NUM;
  }
  else
  {
    selectedRow = v26.rows.num - 1;
  }
  this->selectedRow = selectedRow;
  idGuiListBox::Render(
    this: &v26,
    page: v26.parent,
    (idDeviceContext *)context,
    hAlign: 3u,
    vAlign: 3u,
    nextTo: nullptr);
  v25 = (float)(v26.renderHeight + v26.renderY);
  this->renderX = v26.renderWidth + v26.renderX;
  this->renderY = v25;
  idDevGuiMainPage::RenderChildPages(this, (idDeviceContext *)context);
  v26.__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  idGuiListBox::~idGuiListBox(this: &v26);
}


// ========================================================================
// __unwind$491784
// EA  : 0x82EB1D7C
// RVA : 0x00EB1D7C
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_491784()
{
  int v0; // r12

  idDevGuiListBox::~idDevGuiListBox(this: (idDevGuiListBox *)(v0 - 320 + 80));
}


// ========================================================================
// ?InternalRender@idDevGuiMainPage_Performance@@EAAXAAVidDeviceContext@@MM@Z
// EA  : 0x82EB1DB0
// RVA : 0x00EB1DB0
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage_Performance::InternalRender(
        idDevGuiMainPage_Performance *this,
        idDevGuiPage *context,
        double xPos,
        double yPos,
        int a5)
{
  idGuiListBox *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  bool v11; // r28
  unsigned int v12; // r27
  idGuiListBox *v13; // r3
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  idGuiListBox *v17; // r3
  idGuiListBox *v18; // r3
  unsigned int v19; // r27
  idGuiListBox *v20; // r3
  __int64 v21; // r6
  __int64 v22; // r10
  __int64 v23; // r8
  idGuiListBox *v24; // r3
  idGuiListBox *v25; // r3
  unsigned int v26; // r27
  idGuiListBox *v27; // r3
  __int64 v28; // r8
  __int64 v29; // r10
  __int64 v30; // r6
  idGuiListBox *v31; // r3
  idGuiListBox *v32; // r3
  int selectedRow; // r11
  double v34; // fp9
  idDevGuiListBox v35; // [sp+50h] [-F0h] BYREF

  idDevGuiListBox::idDevGuiListBox(this: &v35, x: xPos, y: yPos, page: context, a5, a6: (int)this);
  v7 = idGuiListBox::Row(this: &v35);
  idGuiListBox::Printf(this: v7, fmt: "- PERFORMANCE -", a3: v10, a4: v9, a5: v8);
  if ( this->isActive )
  {
    v11 = (_cntlzw(this->renderedOnce) & 0x20) != 0;
    v12 = (-g_showThinks.valueInteger & (unsigned int)~g_showThinks.valueInteger) >> 31;
    v13 = idGuiListBox::Row(this: &v35);
    v17 = idGuiListBox::Printf(this: v13, fmt: "Show Ent Thinks", a3: v16, a4: v15, a5: v14);
    v18 = idGuiListBox::Command(this: v17, commandName: "toggle g_showThinks 0 1", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v18, checked: v12);
    v19 = (-com_showMemoryUsage.valueInteger & (unsigned int)~com_showMemoryUsage.valueInteger) >> 31;
    v20 = idGuiListBox::Row(this: &v35);
    LODWORD(v21) = "plode - unlink clip";
    v24 = idGuiListBox::Printf(this: v20, fmt: "Show Performance Info", a3: v21, a4: v23, a5: v22);
    v25 = idGuiListBox::Command(this: v24, commandName: "toggle com_showMemoryUsage 0 2", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v25, checked: v19);
    v26 = (-com_speeds.valueInteger & (unsigned int)~com_speeds.valueInteger) >> 31;
    v27 = idGuiListBox::Row(this: &v35);
    HIDWORD(v28) = "plode - unlink clip";
    v31 = idGuiListBox::Printf(this: v27, fmt: "Show Com Speeds", a3: v30, a4: v28, a5: v29);
    v32 = idGuiListBox::Command(this: v31, commandName: "toggle com_speeds 0 3", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v32, checked: v26);
  }
  selectedRow = this->selectedRow;
  if ( selectedRow >= this->DEFAULT_ROW_NUM )
  {
    if ( selectedRow > v35.rows.num - 1 )
      selectedRow = this->DEFAULT_ROW_NUM;
  }
  else
  {
    selectedRow = v35.rows.num - 1;
  }
  this->selectedRow = selectedRow;
  idGuiListBox::Render(
    this: &v35,
    page: v35.parent,
    (idDeviceContext *)context,
    hAlign: 3u,
    vAlign: 3u,
    nextTo: nullptr);
  v34 = (float)(v35.renderHeight + v35.renderY);
  this->renderX = v35.renderWidth + v35.renderX;
  this->renderY = v34;
  idDevGuiMainPage::RenderChildPages(this, (idDeviceContext *)context);
  v35.__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  idGuiListBox::~idGuiListBox(this: &v35);
}


// ========================================================================
// __unwind$491857_0
// EA  : 0x82EB1F60
// RVA : 0x00EB1F60
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_491857_0()
{
  int v0; // r12

  idDevGuiListBox::~idDevGuiListBox(this: (idDevGuiListBox *)(v0 - 320 + 80));
}


// ========================================================================
// ?InternalRender@idDevGuiChildPage_SpawnAI@@EAAXAAVidDeviceContext@@MM@Z
// EA  : 0x82EB1F90
// RVA : 0x00EB1F90
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiChildPage_SpawnAI::InternalRender(
        idDevGuiChildPage_SpawnAI *this,
        idDevGuiPage *context,
        double xPos,
        double yPos,
        int a5)
{
  bool v7; // r28
  idGuiListBox *v8; // r3
  __int64 v9; // r8
  __int64 v10; // r10
  __int64 v11; // r6
  idGuiListBox *v12; // r3
  idGuiListBox *v13; // r3
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  idGuiListBox *v17; // r3
  idGuiListBox *v18; // r3
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  idGuiListBox *v22; // r3
  idGuiListBox *v23; // r3
  __int64 v24; // r10
  __int64 v25; // r8
  __int64 v26; // r6
  idGuiListBox *v27; // r3
  idGuiListBox *v28; // r3
  __int64 v29; // r8
  __int64 v30; // r10
  __int64 v31; // r6
  idGuiListBox *v32; // r3
  idGuiListBox *v33; // r3
  __int64 v34; // r6
  __int64 v35; // r10
  __int64 v36; // r8
  idGuiListBox *v37; // r3
  idGuiListBox *v38; // r3
  __int64 v39; // r10
  __int64 v40; // r8
  __int64 v41; // r6
  idGuiListBox *v42; // r3
  int selectedRow; // r11
  idDevGuiListBox v44; // [sp+50h] [-E0h] BYREF

  idDevGuiListBox::idDevGuiListBox(this: &v44, x: xPos, y: yPos, page: context, a5, a6: (int)this);
  v7 = (_cntlzw(this->renderedOnce) & 0x20) != 0;
  v8 = idGuiListBox::Row(this: &v44);
  LODWORD(v9) = "plode - unlink clip";
  v12 = idGuiListBox::Printf(this: v8, fmt: "Spawn Imp", a3: v11, a4: v9, a5: v10);
  idGuiListBox::Command(this: v12, commandName: "spawnMPAI mp/ai/demon/imp/default", verifyCmdName: v7);
  v13 = idGuiListBox::Row(this: &v44);
  LODWORD(v14) = "plode - unlink clip";
  v17 = idGuiListBox::Printf(this: v13, fmt: "Spawn Tick", a3: v14, a4: v16, a5: v15);
  idGuiListBox::Command(this: v17, commandName: "spawnMPAI mp/ai/demon/tick/default", verifyCmdName: v7);
  v18 = idGuiListBox::Row(this: &v44);
  v22 = idGuiListBox::Printf(this: v18, fmt: "Spawn Dark Angel", a3: v21, a4: v20, a5: v19);
  idGuiListBox::Command(this: v22, commandName: "spawnMPAI mp/ai/demon/darkangel/default", verifyCmdName: v7);
  v23 = idGuiListBox::Row(this: &v44);
  HIDWORD(v24) = "plode - unlink clip";
  v27 = idGuiListBox::Printf(this: v23, fmt: "Spawn Hell Knight", a3: v26, a4: v25, a5: v24);
  idGuiListBox::Command(this: v27, commandName: "spawnMPAI mp/ai/demon/hellknight/default", verifyCmdName: v7);
  v28 = idGuiListBox::Row(this: &v44);
  HIDWORD(v29) = "plode - unlink clip";
  v32 = idGuiListBox::Printf(this: v28, fmt: "Spawn CacoDemon", a3: v31, a4: v29, a5: v30);
  idGuiListBox::Command(this: v32, commandName: "spawnMPAI mp/ai/demon/cacodemon/default", verifyCmdName: v7);
  v33 = idGuiListBox::Row(this: &v44);
  HIDWORD(v34) = "plode - unlink clip";
  v37 = idGuiListBox::Printf(this: v33, fmt: "Spawn CacoDemon Sentry", a3: v34, a4: v36, a5: v35);
  idGuiListBox::Command(this: v37, commandName: "spawnMPAI mp/sentry/cacodemon", verifyCmdName: v7);
  v38 = idGuiListBox::Row(this: &v44);
  v42 = idGuiListBox::Printf(this: v38, fmt: "Remove AI", a3: v41, a4: v40, a5: v39);
  idGuiListBox::Command(this: v42, commandName: "killMonsters", verifyCmdName: v7);
  selectedRow = this->selectedRow;
  if ( selectedRow >= this->DEFAULT_ROW_NUM )
  {
    if ( selectedRow > v44.rows.num - 1 )
      selectedRow = this->DEFAULT_ROW_NUM;
  }
  else
  {
    selectedRow = v44.rows.num - 1;
  }
  this->selectedRow = selectedRow;
  idGuiListBox::Render(
    this: &v44,
    page: v44.parent,
    (idDeviceContext *)context,
    hAlign: 3u,
    vAlign: 3u,
    nextTo: nullptr);
  v44.__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  idGuiListBox::~idGuiListBox(this: &v44);
}


// ========================================================================
// __unwind$491932_0
// EA  : 0x82EB2124
// RVA : 0x00EB2124
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_491932_0()
{
  int v0; // r12

  idDevGuiListBox::~idDevGuiListBox(this: (idDevGuiListBox *)(v0 - 304 + 80));
}


// ========================================================================
// ?InternalRender@idDevGuiMainPage_Bot@@EAAXAAVidDeviceContext@@MM@Z
// EA  : 0x82EB2158
// RVA : 0x00EB2158
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage_Bot::InternalRender(
        idDevGuiMainPage_Bot *this,
        idDevGuiPage *context,
        double xPos,
        double yPos,
        int a5)
{
  idGuiListBox *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  bool v11; // r27
  idGuiListBox *v12; // r3
  __int64 v13; // r8
  __int64 v14; // r10
  __int64 v15; // r6
  idGuiListBox *v16; // r3
  char v17; // r30
  idGuiListBox *v18; // r3
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  idGuiListBox *v22; // r3
  idGuiListBox *v23; // r3
  idGuiListBox *v24; // r3
  __int64 v25; // r10
  __int64 v26; // r8
  __int64 v27; // r6
  idGuiListBox *v28; // r3
  char v29; // r30
  idGuiListBox *v30; // r3
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r6
  idGuiListBox *v34; // r3
  idGuiListBox *v35; // r3
  char v36; // r30
  idGuiListBox *v37; // r3
  __int64 v38; // r8
  __int64 v39; // r10
  __int64 v40; // r6
  idGuiListBox *v41; // r3
  idGuiListBox *v42; // r3
  char v43; // r30
  idGuiListBox *v44; // r3
  __int64 v45; // r10
  __int64 v46; // r8
  __int64 v47; // r6
  idGuiListBox *v48; // r3
  idGuiListBox *v49; // r3
  char v50; // r30
  idGuiListBox *v51; // r3
  __int64 v52; // r10
  __int64 v53; // r8
  __int64 v54; // r6
  idGuiListBox *v55; // r3
  idGuiListBox *v56; // r3
  char v57; // r30
  idGuiListBox *v58; // r3
  __int64 v59; // r8
  __int64 v60; // r10
  __int64 v61; // r6
  idGuiListBox *v62; // r3
  idGuiListBox *v63; // r3
  char v64; // r30
  idGuiListBox *v65; // r3
  __int64 v66; // r10
  __int64 v67; // r8
  __int64 v68; // r6
  idGuiListBox *v69; // r3
  idGuiListBox *v70; // r3
  char v71; // r30
  idGuiListBox *v72; // r3
  __int64 v73; // r10
  __int64 v74; // r8
  __int64 v75; // r6
  idGuiListBox *v76; // r3
  idGuiListBox *v77; // r3
  idGuiListBox *v78; // r3
  __int64 v79; // r10
  __int64 v80; // r8
  __int64 v81; // r6
  idGuiListBox *v82; // r3
  idGuiListBox *v83; // r3
  __int64 v84; // r8
  __int64 v85; // r10
  __int64 v86; // r6
  idGuiListBox *v87; // r3
  idGuiListBox *v88; // r3
  __int64 v89; // r6
  __int64 v90; // r10
  __int64 v91; // r8
  idGuiListBox *v92; // r3
  unsigned int v93; // r30
  idGuiListBox *v94; // r3
  __int64 v95; // r8
  __int64 v96; // r10
  __int64 v97; // r6
  idGuiListBox *v98; // r3
  idGuiListBox *v99; // r3
  idGuiListBox *v100; // r3
  __int64 v101; // r6
  __int64 v102; // r10
  __int64 v103; // r8
  idGuiListBox *v104; // r3
  int v105; // r26
  idGuiListBox *v106; // r3
  __int64 v107; // r10
  __int64 v108; // r8
  __int64 v109; // r6
  idGuiListBox *v110; // r3
  idGuiListBox *v111; // r3
  __int64 v112; // r10
  __int64 v113; // r8
  __int64 v114; // r6
  idGuiListBox *v115; // r3
  __int64 v116; // r6
  __int64 v117; // r10
  __int64 v118; // r8
  idGuiListBox *v119; // r3
  idGuiListBox *v120; // r3
  idGuiListBox *v121; // r3
  __int64 v122; // r8
  __int64 v123; // r10
  __int64 v124; // r6
  idGuiListBox *v125; // r3
  idGuiListBox *v126; // r3
  int selectedRow; // r11
  double v128; // fp9
  const char *v129[5]; // [sp+50h] [-110h] BYREF
  int v130; // [sp+64h] [-FCh]
  idDevGuiListBox v131; // [sp+70h] [-F0h] BYREF

  idDevGuiListBox::idDevGuiListBox(this: &v131, x: xPos, y: yPos, page: context, a5, a6: (int)this);
  v7 = idGuiListBox::Row(this: &v131);
  idGuiListBox::Printf(this: v7, fmt: "- BOT -", a3: v10, a4: v9, a5: v8);
  if ( this->isActive )
  {
    v11 = (_cntlzw(this->renderedOnce) & 0x20) != 0;
    v12 = idGuiListBox::Row(this: &v131);
    LODWORD(v13) = "plode - unlink clip";
    v16 = idGuiListBox::Printf(this: v12, fmt: "Spawn Bot", a3: v15, a4: v13, a5: v14);
    idGuiListBox::Command(this: v16, commandName: "bot_add 1", verifyCmdName: v11);
    v17 = bot_pause.valueInteger != 0;
    v18 = idGuiListBox::Row(this: &v131);
    v22 = idGuiListBox::Printf(this: v18, fmt: "Pause Bots", a3: v21, a4: v20, a5: v19);
    v23 = idGuiListBox::Command(this: v22, commandName: "toggle bot_pause 0 1", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v23, checked: v17);
    v24 = idGuiListBox::Row(this: &v131);
    HIDWORD(v25) = "plode - unlink clip";
    v28 = idGuiListBox::Printf(this: v24, fmt: "Remove Bots", a3: v27, a4: v26, a5: v25);
    idGuiListBox::Command(this: v28, commandName: "bot_remove", verifyCmdName: v11);
    v29 = bot_allowWeapons.valueInteger != 0;
    v30 = idGuiListBox::Row(this: &v131);
    v34 = idGuiListBox::Printf(this: v30, fmt: "Allow Weapons", a3: v33, a4: v32, a5: v31);
    v35 = idGuiListBox::Command(this: v34, commandName: "toggle bot_allowWeapons 0 1", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v35, checked: v29);
    v36 = bot_freezeMovement.valueInteger != 0;
    v37 = idGuiListBox::Row(this: &v131);
    HIDWORD(v38) = "plode - unlink clip";
    v41 = idGuiListBox::Printf(this: v37, fmt: "Freeze Movement", a3: v40, a4: v38, a5: v39);
    v42 = idGuiListBox::Command(this: v41, commandName: "toggle bot_freezeMovement 0 1", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v42, checked: v36);
    v43 = bot_followPlayer.valueInteger != 0;
    v44 = idGuiListBox::Row(this: &v131);
    HIDWORD(v45) = "plode - unlink clip";
    v48 = idGuiListBox::Printf(this: v44, fmt: "Follow Player", a3: v47, a4: v46, a5: v45);
    v49 = idGuiListBox::Command(this: v48, commandName: "toggle bot_followPlayer 0 1", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v49, checked: v43);
    v50 = bot_drawBounds.valueInteger != 0;
    v51 = idGuiListBox::Row(this: &v131);
    v55 = idGuiListBox::Printf(this: v51, fmt: "Draw Bounds", a3: v54, a4: v53, a5: v52);
    v56 = idGuiListBox::Command(this: v55, commandName: "toggle bot_drawBounds 0 1", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v56, checked: v50);
    v57 = bot_drawHealth.valueInteger != 0;
    v58 = idGuiListBox::Row(this: &v131);
    HIDWORD(v59) = "plode - unlink clip";
    v62 = idGuiListBox::Printf(this: v58, fmt: "Draw Health", a3: v61, a4: v59, a5: v60);
    v63 = idGuiListBox::Command(this: v62, commandName: "toggle bot_drawHealth 0 1", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v63, checked: v57);
    v64 = bot_trackPlayer.valueInteger != 0;
    v65 = idGuiListBox::Row(this: &v131);
    HIDWORD(v66) = "plode - unlink clip";
    v69 = idGuiListBox::Printf(this: v65, fmt: "Look At Player", a3: v68, a4: v67, a5: v66);
    v70 = idGuiListBox::Command(this: v69, commandName: "toggle bot_trackPlayer 0 1", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v70, checked: v64);
    v71 = bot_allowJumping.valueInteger != 0;
    v72 = idGuiListBox::Row(this: &v131);
    v76 = idGuiListBox::Printf(this: v72, fmt: "Allow Jumping", a3: v75, a4: v74, a5: v73);
    v77 = idGuiListBox::Command(this: v76, commandName: "toggle bot_allowJumping 0 1", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v77, checked: v71);
    v78 = idGuiListBox::Row(this: &v131);
    LODWORD(v79) = "plode - unlink clip";
    v82 = idGuiListBox::Printf(this: v78, fmt: "Show Bot Performance", a3: v81, a4: v80, a5: v79);
    idGuiListBox::Command(this: v82, commandName: "ShowBotPerformanceInfo", verifyCmdName: v11);
    v83 = idGuiListBox::Row(this: &v131);
    LODWORD(v84) = "plode - unlink clip";
    v87 = idGuiListBox::Printf(this: v83, fmt: "Teleport Friendly Bot To Crosshair", a3: v86, a4: v84, a5: v85);
    idGuiListBox::Command(this: v87, commandName: "TeleportBotToCrosshair 1", verifyCmdName: v11);
    v88 = idGuiListBox::Row(this: &v131);
    LODWORD(v89) = "plode - unlink clip";
    v92 = idGuiListBox::Printf(this: v88, fmt: "Teleport Enemy Bot To Crosshair", a3: v89, a4: v91, a5: v90);
    idGuiListBox::Command(this: v92, commandName: "TeleportBotToCrosshair 0", verifyCmdName: v11);
    v93 = (-bot_showPath.valueInteger & (unsigned int)~bot_showPath.valueInteger) >> 31;
    v94 = idGuiListBox::Row(this: &v131);
    HIDWORD(v95) = "plode - unlink clip";
    v98 = idGuiListBox::Printf(this: v94, fmt: "Show Path", a3: v97, a4: v95, a5: v96);
    v99 = idGuiListBox::Command(this: v98, commandName: "toggle bot_showPath -1 1", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v99, checked: v93);
    v100 = idGuiListBox::Row(this: &v131);
    HIDWORD(v101) = "plode - unlink clip";
    v104 = idGuiListBox::Printf(this: v100, fmt: "Set Debug Bot", a3: v101, a4: v103, a5: v102);
    idGuiListBox::Command(this: v104, commandName: "setBotDebugEntity", verifyCmdName: v11);
    v129[0] = "Off";
    v129[1] = "Bot Info";
    v129[2] = "World State Debug";
    v129[3] = "Behavior Tree Debug";
    v130 = (int)(float)(botGUI.valueMax + (float)1.0);
    v105 = v130;
    v106 = idGuiListBox::Row(this: &v131);
    LODWORD(v107) = "plode - unlink clip";
    v110 = idGuiListBox::Printf(this: v106, fmt: "Bot Debug GUI: ", a3: v109, a4: v108, a5: v107);
    v111 = idGuiListBox::ComboBoxCvar(this: v110, cvar: &botGUI, items: v129, numItems: v105);
    HIDWORD(v112) = "plode - unlink clip";
    idGuiListBox::Printf(this: v111, fmt: "<->", a3: v114, a4: v113, a5: v112);
    LOBYTE(v93) = aas_showAreas.valueInteger != 0;
    v115 = idGuiListBox::Row(this: &v131);
    HIDWORD(v116) = "plode - unlink clip";
    v119 = idGuiListBox::Printf(this: v115, fmt: "Draw Bot AAS", a3: v116, a4: v118, a5: v117);
    v120 = idGuiListBox::Command(this: v119, commandName: "RenderBotAAS", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v120, checked: v93);
    LOBYTE(v93) = aas_showWallEdges.valueInteger != 0;
    v121 = idGuiListBox::Row(this: &v131);
    LODWORD(v122) = "plode - unlink clip";
    v125 = idGuiListBox::Printf(this: v121, fmt: "Draw Bot AAS Wall Edges", a3: v124, a4: v122, a5: v123);
    v126 = idGuiListBox::Command(this: v125, commandName: "RenderWallEdges", verifyCmdName: v11);
    idGuiListBox::DrawCheckMark(this: v126, checked: v93);
  }
  selectedRow = this->selectedRow;
  if ( selectedRow >= this->DEFAULT_ROW_NUM )
  {
    if ( selectedRow > v131.rows.num - 1 )
      selectedRow = this->DEFAULT_ROW_NUM;
  }
  else
  {
    selectedRow = v131.rows.num - 1;
  }
  this->selectedRow = selectedRow;
  idGuiListBox::Render(
    this: &v131,
    page: v131.parent,
    (idDeviceContext *)context,
    hAlign: 3u,
    vAlign: 3u,
    nextTo: nullptr);
  v128 = (float)(v131.renderHeight + v131.renderY);
  this->renderX = v131.renderWidth + v131.renderX;
  this->renderY = v128;
  idDevGuiMainPage::RenderChildPages(this, (idDeviceContext *)context);
  v131.__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  idGuiListBox::~idGuiListBox(this: &v131);
}


// ========================================================================
// __unwind$491981
// EA  : 0x82EB265C
// RVA : 0x00EB265C
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_491981()
{
  int v0; // r12

  idDevGuiListBox::~idDevGuiListBox(this: (idDevGuiListBox *)(v0 - 352 + 112));
}


// ========================================================================
// ?setBotDebugEntity_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EB2688
// RVA : 0x00EB2688
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall setBotDebugEntity_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v2; // r30
  idPresentable *presentable; // r3
  int v4; // r3
  idPresentable *v5; // r11
  const idVec3 *v6; // r31
  float *v7; // r3
  double z; // fp13
  double x; // fp11
  int entityNumber; // r8
  double v11; // fp6
  double v12; // fp5
  idGameLocal *v13; // r3
  idEntity *v14; // r31
  idPlayer *v15; // r3
  idVec3 v16; // [sp+50h] [-B0h] BYREF
  trace_t v17; // [sp+60h] [-A0h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v2 = DebugPlayer;
  if ( DebugPlayer != nullptr )
  {
    presentable = DebugPlayer->presentable;
    if ( presentable != nullptr )
      v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v4 = 0;
    v5 = v2->presentable;
    v6 = (const idVec3 *)(v4 + 46532);
    if ( v5 != nullptr )
      v7 = (float *)v5->GetPlayerInterface_2(this: v2->presentable);
    else
      v7 = nullptr;
    z = v6->z;
    x = v6->x;
    entityNumber = v2->entityNumber;
    v11 = (float)(v7[11638] * (float)8192.0);
    v12 = (float)(v7[11636] * (float)8192.0);
    v16.y = v6->y + (float)(v7[11637] * (float)8192.0);
    v16.z = (float)z + (float)v11;
    v16.x = (float)x + (float)v12;
    idClip::TracePoint(
      this: &clientGame->clip,
      result: &v17,
      start: v6,
      end: &v16,
      clipMask: 8462469,
      passEntityNumber: entityNumber);
    if ( v17.c.entityNum <= 0x1FFDu )
    {
      v13 = gameLocal;
      v14 = gameLocal->entities.ptr[v17.c.entityNum];
      if ( v14 == nullptr )
      {
LABEL_14:
        idGameLocal::BotSystems_SetBotDebugEntity(this: v13, entity: nullptr);
        idLib::Printf(fmt: "Cleared bot debug target.\n");
        return;
      }
      v15 = idPlayer::CastTo(c: (idPlayer *)gameLocal->entities.ptr[v17.c.entityNum]);
      if ( v15 != nullptr && idPlayer::IsBot(this: v15) )
      {
        idGameLocal::BotSystems_SetBotDebugEntity(this: gameLocal, entity: v14);
        idLib::Printf(fmt: "Selected entity '%s' as bot debug target.\n", v14->name.data);
        return;
      }
    }
    v13 = gameLocal;
    goto LABEL_14;
  }
}


// ========================================================================
// ?GetDebugAI@@YAPAVidAI2@@XZ
// EA  : 0x82EB2870
// RVA : 0x00EB2870
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idAI2 *__fastcall GetDebugAI()
{
  int value; // r9
  idEntity *v1; // r3
  idAI2 *v2; // r3
  idAI2 *result; // r3
  idPhysics *Physics; // r3
  int v5; // r3
  idGameLocal *v6; // r11
  float *v7; // r25
  idEntity *v8; // r26
  double v9; // fp31
  int num; // r29
  int v11; // r30
  int v12; // r9
  idAI2 *v13; // r3
  unsigned __int8 *v14; // r3
  unsigned __int8 *v15; // r31
  idPhysics *v16; // r3
  float *v17; // r3
  double v18; // fp10
  double v19; // fp6

  value = gameLocal->debugEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v1 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v2 = (idAI2 *)idEntity::CastTo(c: v1);
  }
  else
  {
    v2 = nullptr;
  }
  result = idAI2::CastTo(c: v2);
  if ( result == nullptr )
  {
    result = (idAI2 *)idGameLocal::GetDebugPlayer(this: gameLocal);
    if ( result != nullptr )
    {
      Physics = idEntity::GetPhysics(this: result);
      v5 = (int)Physics->GetOrigin(this: Physics, a2: 0);
      v6 = gameLocal;
      v7 = (float *)v5;
      v8 = nullptr;
      v9 = 1.0e30;
      if ( gameLocal->activeAI.num > 0 )
      {
        num = gameLocal->activeAI.num;
        v11 = 0;
        do
        {
          v12 = v6->activeAI.list[v11].spawnId.value;
          if ( v6->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13 )
          {
            v13 = (idAI2 *)v6->entities.ptr[v12 & 0x1FFF];
            if ( v13 != nullptr )
            {
              v14 = (unsigned __int8 *)idAI2::CastTo(c: v13);
              v15 = v14;
              if ( v14 != nullptr
                && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v14) == 0
                && (*(unsigned __int8 (__fastcall **)(unsigned __int8 *))(*(_DWORD *)v15 + 508))(a1: v15) == 0
                && (v15[93] & 0x80) == 0
                && (*(unsigned __int8 (__fastcall **)(unsigned __int8 *))(*(_DWORD *)v15 + 512))(a1: v15) == 0 )
              {
                v16 = idEntity::GetPhysics(this: (idEntity *)v15);
                v17 = (float *)v16->GetOrigin(this: v16, a2: 0);
                v18 = (float)(v17[1] - v7[1]);
                v19 = (float)(v17[2] - v7[2]);
                if ( (float)((float)((float)v19 * (float)v19)
                           + (float)((float)((float)(*v17 - *v7) * (float)(*v17 - *v7))
                                   + (float)((float)v18 * (float)v18))) < v9 )
                {
                  v9 = (float)((float)((float)v19 * (float)v19)
                             + (float)((float)((float)(*v17 - *v7) * (float)(*v17 - *v7))
                                     + (float)((float)v18 * (float)v18)));
                  v8 = (idEntity *)v15;
                }
              }
              v6 = gameLocal;
            }
          }
          --num;
          ++v11;
        }
        while ( num != 0 );
      }
      idGameLocal::SetDebugEntity(this: v6, ent: v8);
      return (idAI2 *)v8;
    }
  }
  return result;
}


// ========================================================================
// ??0idDevGui@@QAA@XZ
// EA  : 0x82EB2A80
// RVA : 0x00EB2A80
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idDevGui *__fastcall idDevGui::idDevGui(idDevGui *this)
{
  this->initialized = false;
  this->firstDraw = true;
  this->oldGuiScale = 0.0;
  this->runningTool = false;
  this->postExitSuppressInputTime = 0;
  this->selectedColumn = 0;
  this->pages.list = nullptr;
  this->pages.granularity = 0;
  this->pages.memTag = 5;
  this->pages.listStatic = 0;
  this->pages.size = 0;
  this->pages.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pages);
  this->guiModel = nullptr;
  return this;
}


// ========================================================================
// ?Shutdown@idDevGui@@QAAXXZ
// EA  : 0x82EB2B08
// RVA : 0x00EB2B08
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGui::Shutdown(idDevGui *this)
{
  idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->pages);
}


// ========================================================================
// ??0idDevGuiMainPage@@QAA@XZ
// EA  : 0x82EB2B18
// RVA : 0x00EB2B18
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idDevGuiMainPage *__fastcall idDevGuiMainPage::idDevGuiMainPage(idDevGuiMainPage *this)
{
  idDevGuiPage::idDevGuiPage(this, defaultRow: 1, name: &byte_8200D768);
  this->childActive = false;
  this->__vftable = (idDevGuiMainPage_vtbl *)&idDevGuiMainPage::`vftable';
  this->childrenSetup = false;
  this->childPages.list = nullptr;
  this->childPages.granularity = 0;
  this->childPages.memTag = 5;
  this->childPages.listStatic = 0;
  this->childPages.size = 0;
  this->childPages.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->childPages);
  this->selectedRow = this->DEFAULT_ROW_NUM;
  return this;
}


// ========================================================================
// __unwind$492784_0
// EA  : 0x82EB2BA8
// RVA : 0x00EB2BA8
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_492784_0()
{
  int v0; // r12

  idDevGuiPage::~idDevGuiPage(this: *(idDevGuiPage **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idDevGuiMainPage@@UAA@XZ
// EA  : 0x82EB2BE0
// RVA : 0x00EB2BE0
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage::~idDevGuiMainPage(idDevGuiMainPage *this)
{
  this->__vftable = (idDevGuiMainPage_vtbl *)&idDevGuiMainPage::`vftable';
  idDevGuiMainPage::FreeChildPages(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->childPages);
  this->__vftable = (idDevGuiMainPage_vtbl *)&idDevGuiPage::`vftable';
  idGuiPage::~idGuiPage(this);
}


// ========================================================================
// __unwind$492807
// EA  : 0x82EB2C44
// RVA : 0x00EB2C44
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_492807()
{
  int v0; // r12

  idDevGuiPage::~idDevGuiPage(this: *(idDevGuiPage **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$492808_0
// EA  : 0x82EB2C6C
// RVA : 0x00EB2C6C
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_492808_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 88));
}


// ========================================================================
// ?InternalRender@idDevGuiMainPage_AI@@EAAXAAVidDeviceContext@@MM@Z
// EA  : 0x82EB2CA0
// RVA : 0x00EB2CA0
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGuiMainPage_AI::InternalRender(
        idDevGuiMainPage_AI *this,
        idDevGuiPage *context,
        double xPos,
        double yPos,
        int a5)
{
  idGuiListBox *v7; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  idPlayer *DebugPlayer; // r28
  idAI2 *DebugAI; // r3
  int entityNumber; // r30
  bool v14; // r26
  idGuiListBox *v15; // r3
  __int64 v16; // r8
  __int64 v17; // r10
  __int64 v18; // r6
  idGuiListBox *v19; // r3
  __int64 v20; // r6
  __int64 v21; // r10
  __int64 v22; // r8
  idGuiListBox *v23; // r3
  char v24; // r28
  idGuiListBox *v25; // r3
  __int64 v26; // r10
  __int64 v27; // r8
  __int64 v28; // r6
  idGuiListBox *v29; // r3
  idGuiListBox *v30; // r3
  bool v31; // r28
  idGuiListBox *v32; // r3
  __int64 v33; // r8
  __int64 v34; // r10
  __int64 v35; // r6
  idGuiListBox *v36; // r3
  idGuiListBox *v37; // r3
  char v38; // r28
  idGuiListBox *v39; // r3
  __int64 v40; // r8
  __int64 v41; // r10
  __int64 v42; // r6
  idGuiListBox *v43; // r3
  idGuiListBox *v44; // r3
  __int64 v45; // r6
  __int64 v46; // r10
  int v47; // r28
  __int64 v48; // r8
  va *v49; // r25
  idGuiListBox *v50; // r3
  __int64 v51; // r8
  __int64 v52; // r10
  __int64 v53; // r6
  idGuiListBox *v54; // r3
  idGuiListBox *v55; // r3
  __int64 v56; // r6
  __int64 v57; // r10
  __int64 v58; // r8
  char v59; // r30
  va *v60; // r28
  idGuiListBox *v61; // r3
  __int64 v62; // r6
  __int64 v63; // r10
  __int64 v64; // r8
  idGuiListBox *v65; // r3
  idGuiListBox *v66; // r3
  idGuiListBox *v67; // r3
  __int64 v68; // r10
  __int64 v69; // r8
  __int64 v70; // r6
  idGuiListBox *v71; // r3
  idGuiListBox *v72; // r3
  __int64 v73; // r10
  __int64 v74; // r8
  __int64 v75; // r6
  idGuiListBox *v76; // r3
  __int64 v77; // r8
  __int64 v78; // r10
  __int64 v79; // r6
  idGuiListBox *v80; // r3
  idGuiListBox *v81; // r3
  __int64 v82; // r6
  __int64 v83; // r10
  __int64 v84; // r8
  idGuiListBox *v85; // r3
  idGuiListBox *v86; // r3
  __int64 v87; // r10
  __int64 v88; // r8
  __int64 v89; // r6
  idGuiListBox *v90; // r3
  int selectedRow; // r11
  double v92; // fp9
  int v93; // [sp+8h] [-1178h]
  int v94; // [sp+8h] [-1178h]
  int v95; // [sp+Ch] [-1174h]
  int v96; // [sp+Ch] [-1174h]
  int v97; // [sp+10h] [-1170h]
  int v98; // [sp+10h] [-1170h]
  int v99; // [sp+14h] [-116Ch]
  int v100; // [sp+14h] [-116Ch]
  int v101; // [sp+18h] [-1168h]
  int v102; // [sp+18h] [-1168h]
  int v103; // [sp+1Ch] [-1164h]
  int v104; // [sp+1Ch] [-1164h]
  idDevGuiListBox v105; // [sp+60h] [-1120h] BYREF
  idStr v106; // [sp+120h] [-1060h] BYREF
  va v107; // [sp+140h] [-1040h] BYREF

  idDevGuiListBox::idDevGuiListBox(this: &v105, x: xPos, y: yPos, page: context, a5, a6: (int)this);
  v7 = idGuiListBox::Row(this: &v105);
  idGuiListBox::Printf(this: v7, fmt: "- AI -", a3: v10, a4: v9, a5: v8);
  if ( this->isActive )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    if ( DebugPlayer == nullptr )
      goto LABEL_12;
    DebugAI = GetDebugAI();
    if ( DebugAI != nullptr )
      entityNumber = DebugAI->entityNumber;
    else
      entityNumber = -1;
    v14 = (_cntlzw(this->renderedOnce) & 0x20) != 0;
    idStr::idStr(this: &v106, text: "Spawn_AI");
    v15 = idGuiListBox::Row(this: &v105);
    HIDWORD(v16) = "plode - unlink clip";
    v19 = idGuiListBox::Printf(this: v15, fmt: "Spawn AI", a3: v18, a4: v16, a5: v17);
    LODWORD(v20) = byte_821B0000;
    v23 = idGuiListBox::Printf(this: v19, fmt: " ", a3: v20, a4: v22, a5: v21);
    idGuiListBox::SetChildWindow(this: v23, childName: &v106, page: this);
    idStr::FreeData(this: &v106);
    v24 = (*((_BYTE *)DebugPlayer + 12824) & 8) != 0;
    v25 = idGuiListBox::Row(this: &v105);
    v29 = idGuiListBox::Printf(this: v25, fmt: "No Target", a3: v28, a4: v27, a5: v26);
    v30 = idGuiListBox::Command(this: v29, commandName: "notarget", verifyCmdName: v14);
    idGuiListBox::DrawCheckMark(this: v30, checked: v24);
    v31 = ai_enable.valueInteger != 0;
    v32 = idGuiListBox::Row(this: &v105);
    HIDWORD(v33) = "plode - unlink clip";
    v36 = idGuiListBox::Printf(this: v32, fmt: "Pause AI", a3: v35, a4: v33, a5: v34);
    v37 = idGuiListBox::Command(this: v36, commandName: "toggle ai_enable", verifyCmdName: v14);
    idGuiListBox::DrawCheckMark(this: v37, checked: (_cntlzw(v31) & 0x20) != 0);
    v38 = ai_debugMove.valueInteger != 0;
    v39 = idGuiListBox::Row(this: &v105);
    LODWORD(v40) = "plode - unlink clip";
    v43 = idGuiListBox::Printf(this: v39, fmt: "Show AI Path", a3: v42, a4: v40, a5: v41);
    v44 = idGuiListBox::Command(this: v43, commandName: "toggle ai_debugMove", verifyCmdName: v14);
    idGuiListBox::DrawCheckMark(this: v44, checked: v38);
    LODWORD(v45) = &ai_useTurnTransitions.valueString.baseBuffer[12];
    HIDWORD(v45) = entityNumber;
    LODWORD(v46) = -ai_animWebDebug.valueInteger;
    HIDWORD(v46) = -ai_animWebDebug.valueInteger & ~ai_animWebDebug.valueInteger;
    v47 = HIDWORD(v46) >> 31;
    v49 = va::va(
            this: &v107,
            fmt: "toggle ai_animWebDebug 0 %d",
            a3: v45,
            a4: v48,
            a5: v46,
            a6: v93,
            a7: v95,
            a8: v97,
            a9: v99,
            a10: v101,
            a11: v103);
    v50 = idGuiListBox::Row(this: &v105);
    LODWORD(v51) = "plode - unlink clip";
    v54 = idGuiListBox::Printf(this: v50, fmt: "Show AI AnimWeb", a3: v53, a4: v51, a5: v52);
    v55 = idGuiListBox::Command(this: v54, commandName: v49->buffer, verifyCmdName: v14);
    idGuiListBox::DrawCheckMark(this: v55, checked: v47);
    HIDWORD(v56) = entityNumber;
    LODWORD(v57) = g_showBlendTree.valueInteger;
    HIDWORD(v57) = -1 - g_showBlendTree.valueInteger;
    LODWORD(v58) = g_showBlendTree.valueInteger;
    HIDWORD(v58) = (unsigned int)g_showBlendTree.valueInteger >> 31;
    LODWORD(v56) = ((unsigned int)g_showBlendTree.valueInteger >> 31) + 1;
    v59 = v56 & 1;
    v60 = va::va(
            this: &v107,
            fmt: "toggle g_showBlendTree -1 %d",
            a3: v56,
            a4: v58,
            a5: v57,
            a6: v94,
            a7: v96,
            a8: v98,
            a9: v100,
            a10: v102,
            a11: v104);
    v61 = idGuiListBox::Row(this: &v105);
    HIDWORD(v62) = "plode - unlink clip";
    v65 = idGuiListBox::Printf(this: v61, fmt: "Show AI BlendTree", a3: v62, a4: v64, a5: v63);
    v66 = idGuiListBox::Command(this: v65, commandName: v60->buffer, verifyCmdName: v14);
    idGuiListBox::DrawCheckMark(this: v66, checked: v59);
    v67 = idGuiListBox::Row(this: &v105);
    v71 = idGuiListBox::Printf(this: v67, fmt: "Show NavMesh: ", a3: v70, a4: v69, a5: v68);
    v72 = idGuiListBox::ComboBoxCvar(this: v71, cvar: &np_drawLayer, items: navLayerNames, numItems: 8);
    HIDWORD(v73) = "plode - unlink clip";
    idGuiListBox::Printf(this: v72, fmt: "<->", a3: v75, a4: v74, a5: v73);
    v76 = idGuiListBox::Row(this: &v105);
    LODWORD(v77) = "plode - unlink clip";
    v80 = idGuiListBox::Printf(this: v76, fmt: "Set Debug AI", a3: v79, a4: v77, a5: v78);
    idGuiListBox::Command(this: v80, commandName: "selectDebugEntity", verifyCmdName: v14);
    v81 = idGuiListBox::Row(this: &v105);
    LODWORD(v82) = "plode - unlink clip";
    v85 = idGuiListBox::Printf(this: v81, fmt: "Teleport Debug AI to crosshair", a3: v82, a4: v84, a5: v83);
    idGuiListBox::Command(this: v85, commandName: "TeleportDebugAI", verifyCmdName: v14);
    v86 = idGuiListBox::Row(this: &v105);
    v90 = idGuiListBox::Printf(this: v86, fmt: "AI Gui", a3: v89, a4: v88, a5: v87);
    idGuiListBox::Command(this: v90, commandName: "toggle aigui 0 2 4 9", verifyCmdName: v14);
  }
  selectedRow = this->selectedRow;
  if ( selectedRow >= this->DEFAULT_ROW_NUM )
  {
    if ( selectedRow > v105.rows.num - 1 )
      selectedRow = this->DEFAULT_ROW_NUM;
  }
  else
  {
    selectedRow = v105.rows.num - 1;
  }
  this->selectedRow = selectedRow;
  idGuiListBox::Render(
    this: &v105,
    page: v105.parent,
    (idDeviceContext *)context,
    hAlign: 3u,
    vAlign: 3u,
    nextTo: nullptr);
  v92 = (float)(v105.renderHeight + v105.renderY);
  this->renderX = v105.renderWidth + v105.renderX;
  this->renderY = v92;
  idDevGuiMainPage::RenderChildPages(this, (idDeviceContext *)context);
LABEL_12:
  v105.__vftable = (idDevGuiListBox_vtbl *)&idDevGuiListBox::`vftable';
  idGuiListBox::~idGuiListBox(this: &v105);
}


// ========================================================================
// __unwind$492868
// EA  : 0x82EB3020
// RVA : 0x00EB3020
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_492868()
{
  int v0; // r12

  idDevGuiListBox::~idDevGuiListBox(this: (idDevGuiListBox *)(v0 - 4480 + 96));
}


// ========================================================================
// __unwind$492869
// EA  : 0x82EB3048
// RVA : 0x00EB3048
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_492869()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4480 + 288));
}


// ========================================================================
// ?TeleportDebugAI_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EB3070
// RVA : 0x00EB3070
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall TeleportDebugAI_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r29
  int value; // r8
  idEntity *v3; // r3
  idAI2 *v4; // r3
  idAI2 *DebugAI; // r30
  idPresentable *presentable; // r3
  int v7; // r3
  idPresentable *v8; // r11
  const idVec3 *v9; // r31
  float *v10; // r3
  double z; // fp13
  double x; // fp11
  int entityNumber; // r8
  double v14; // fp6
  double v15; // fp5
  double v16; // fp8
  double v17; // fp7
  idAI2_vtbl *v18; // r31
  idAngles *v19; // r3
  float v20[2]; // [sp+50h] [-E0h] BYREF
  float v21; // [sp+58h] [-D8h]
  idVec3 v22; // [sp+60h] [-D0h] BYREF
  idAngles v23; // [sp+70h] [-C0h] BYREF
  idVec3 v24; // [sp+80h] [-B0h] BYREF
  trace_t v25; // [sp+90h] [-A0h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr )
  {
    value = gameLocal->debugEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v4 = (idAI2 *)idEntity::CastTo(c: v3);
    }
    else
    {
      v4 = nullptr;
    }
    DebugAI = idAI2::CastTo(c: v4);
    if ( DebugAI != nullptr || (DebugAI = GetDebugAI()) != nullptr )
    {
      presentable = DebugPlayer->presentable;
      if ( presentable != nullptr )
        v7 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v7 = 0;
      v8 = DebugPlayer->presentable;
      v9 = (const idVec3 *)(v7 + 46532);
      if ( v8 != nullptr )
        v10 = (float *)v8->GetPlayerInterface_2(this: DebugPlayer->presentable);
      else
        v10 = nullptr;
      z = v9->z;
      x = v9->x;
      entityNumber = DebugPlayer->entityNumber;
      v14 = (float)(v10[11638] * (float)8192.0);
      v15 = (float)(v10[11636] * (float)8192.0);
      v22.y = v9->y + (float)(v10[11637] * (float)8192.0);
      v22.z = (float)z + (float)v14;
      v22.x = (float)x + (float)v15;
      idClip::TracePoint(
        this: &clientGame->clip,
        result: &v25,
        start: v9,
        end: &v22,
        clipMask: 106513,
        passEntityNumber: entityNumber);
      v20[0] = v25.endpos.x;
      v21 = v25.endpos.z + (float)1.0;
      v20[1] = v25.endpos.y;
      v16 = (float)(v25.endpos.y - v9->y);
      v17 = (float)(v21 - v9->z);
      v23.pitch = v25.endpos.x - v9->x;
      v23.roll = v17;
      v23.yaw = v16;
      v18 = DebugAI->__vftable;
      v19 = idVec3::ToAngles(this: &v24, result: &v23);
      v18->Teleport(this: DebugAI, a2: (const idVec3 *)v20, a3: v19);
    }
    else
    {
      idLib::Warning(fmt: "TeleportDebugAI: no valid AI!");
    }
  }
  else
  {
    idLib::Warning(fmt: "TeleportDebugAI: no valid player!");
  }
}


// ========================================================================
// ?TeleportBotToCrosshair_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82EB3268
// RVA : 0x00EB3268
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall TeleportBotToCrosshair_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r25
  int v3; // r3
  idGameLocal *v4; // r11
  int v5; // r26
  char v6; // r23
  int v7; // r29
  int num; // r27
  int v9; // r31
  int value; // r9
  idPlayer *v11; // r3
  idPlayer *v12; // r3
  idPlayer *v13; // r30
  gameTeam_t Team; // r22
  gameTeam_t v15; // r21
  idGameChallenge *ChallengeEntity; // r3
  int IsHostile; // r11
  idPresentable *presentable; // r3
  int v19; // r3
  idPresentable *v20; // r11
  const idVec3 *v21; // r31
  float *v22; // r3
  double z; // fp13
  double x; // fp11
  int entityNumber; // r8
  double v26; // fp6
  double v27; // fp5
  double v28; // fp8
  double v29; // fp7
  idPlayer_vtbl *v30; // r31
  idAngles *v31; // r3
  float v32[2]; // [sp+50h] [-120h] BYREF
  float v33; // [sp+58h] [-118h]
  idVec3 v34; // [sp+60h] [-110h] BYREF
  idAngles v35; // [sp+70h] [-100h] BYREF
  idVec3 v36; // [sp+80h] [-F0h] BYREF
  trace_t v37; // [sp+90h] [-E0h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer == nullptr )
  {
    idLib::Warning(fmt: "TeleportBotToCrosshair: no valid player!");
    return;
  }
  if ( args->argc != 2 )
  {
    idLib::Warning(fmt: "TeleportBotToCrosshair: invalid number of parameters - should be: 'TeleportBotToCrosshair <0|1>' ");
    return;
  }
  v3 = atol(nptr: args->argv[1]);
  v4 = gameLocal;
  v5 = v3;
  v6 = 0;
  v7 = 0;
  num = gameLocal->playerEntities.num;
  if ( num <= 0 )
    goto LABEL_25;
  v9 = 0;
  while ( 1 )
  {
    value = v4->playerEntities.list[v9].spawnId.value;
    if ( v4->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
      goto LABEL_18;
    v11 = (idPlayer *)v4->entities.ptr[value & 0x1FFF];
    if ( v11 != nullptr )
    {
      v12 = idPlayer::CastTo(c: v11);
      v13 = v12;
      if ( v12 != nullptr && v12 != DebugPlayer && !v12->IsDead(this: v12) && idPlayer::IsBot(this: v13) )
      {
        Team = idEntity::GetTeam(this: v13);
        v15 = idEntity::GetTeam(this: DebugPlayer);
        ChallengeEntity = idGameLocal::GetChallengeEntity(this: gameLocal);
        IsHostile = (unsigned __int8)idGameChallenge::IsHostile(this: ChallengeEntity, team1: v15, team2: Team);
        if ( v5 != 0 )
        {
          if ( IsHostile == 0 )
            break;
          goto LABEL_17;
        }
        if ( IsHostile != 0 )
          break;
      }
LABEL_17:
      v4 = gameLocal;
    }
LABEL_18:
    ++v7;
    ++v9;
    if ( v7 >= num )
      goto LABEL_25;
  }
  presentable = DebugPlayer->presentable;
  v6 = 1;
  if ( presentable != nullptr )
    v19 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v19 = 0;
  v20 = DebugPlayer->presentable;
  v21 = (const idVec3 *)(v19 + 46532);
  if ( v20 != nullptr )
    v22 = (float *)v20->GetPlayerInterface_2(this: DebugPlayer->presentable);
  else
    v22 = nullptr;
  z = v21->z;
  x = v21->x;
  entityNumber = DebugPlayer->entityNumber;
  v26 = (float)(v22[11638] * (float)8192.0);
  v27 = (float)(v22[11636] * (float)8192.0);
  v34.y = v21->y + (float)(v22[11637] * (float)8192.0);
  v34.z = (float)z + (float)v26;
  v34.x = (float)x + (float)v27;
  idClip::TracePoint(
    this: &clientGame->clip,
    result: &v37,
    start: v21,
    end: &v34,
    clipMask: 107529,
    passEntityNumber: entityNumber);
  v32[0] = v37.endpos.x;
  v33 = v37.endpos.z + (float)1.0;
  v32[1] = v37.endpos.y;
  v28 = (float)(v37.endpos.y - v21->y);
  v29 = (float)(v33 - v21->z);
  v35.pitch = v37.endpos.x - v21->x;
  v35.roll = v29;
  v35.yaw = v28;
  v30 = v13->__vftable;
  v31 = idVec3::ToAngles(this: &v36, result: &v35);
  v30->Teleport(this: v13, a2: (const idVec3 *)v32, a3: v31);
LABEL_25:
  if ( v6 == 0 )
    idLib::Warning(fmt: "TeleportBotToCrosshair: no bot found to teleport!");
}


// ========================================================================
// ??1idDevGui@@QAA@XZ
// EA  : 0x82EB3830
// RVA : 0x00EB3830
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGui::~idDevGui(idDevGui *this)
{
  idList<idVehicleState *,5> *p_pages; // r30

  p_pages = (idList<idVehicleState *,5> *)&this->pages;
  idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->pages);
  idList<idThread *,58>::Clear(this: p_pages);
}


// ========================================================================
// __unwind$493454
// EA  : 0x82EB3878
// RVA : 0x00EB3878
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_493454()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// ??0idDevGuiMainPage_Main@@QAA@XZ
// EA  : 0x82EB3C60
// RVA : 0x00EB3C60
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idDevGuiMainPage_Main *__fastcall idDevGuiMainPage_Main::idDevGuiMainPage_Main(idDevGuiMainPage_Main *this)
{
  idDevGuiPage *v2; // r3
  idDevGuiChildPage *v3; // r30
  int DEFAULT_ROW_NUM; // r8
  idDevGuiMainPage::childPages_t *v5; // r3

  idDevGuiMainPage::idDevGuiMainPage(this);
  this->__vftable = (idDevGuiMainPage_Main_vtbl *)&idDevGuiMainPage_Main::`vftable';
  v2 = (idDevGuiPage *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x54u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v3 = (idDevGuiChildPage *)v2;
  if ( v2 != nullptr )
  {
    idDevGuiPage::idDevGuiPage(this: v2, defaultRow: 0, name: "Time_Scale");
    DEFAULT_ROW_NUM = v3->DEFAULT_ROW_NUM;
    v3->__vftable = (idDevGuiChildPage_vtbl *)&idDevGuiChildPage_TimeScale::`vftable';
    v3->selectedRow = DEFAULT_ROW_NUM;
  }
  else
  {
    v3 = nullptr;
  }
  v5 = idList<idDevGuiMainPage::childPages_t,5>::Alloc(this: &this->childPages);
  v5->childPage = v3;
  v5->rowNum = -1;
  return this;
}


// ========================================================================
// __unwind$493588_0
// EA  : 0x82EB3D0C
// RVA : 0x00EB3D0C
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_493588_0()
{
  int v0; // r12

  idDevGuiMainPage::~idDevGuiMainPage(this: *(idDevGuiMainPage **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$493589_2
// EA  : 0x82EB3D34
// RVA : 0x00EB3D34
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall _unwind_493589_2(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ??0idDevGuiMainPage_Player@@QAA@XZ
// EA  : 0x82EB3D68
// RVA : 0x00EB3D68
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idDevGuiMainPage_Player *__fastcall idDevGuiMainPage_Player::idDevGuiMainPage_Player(idDevGuiMainPage_Player *this)
{
  idDevGuiPage *v2; // r3
  idDevGuiChildPage *v3; // r30
  int DEFAULT_ROW_NUM; // r8
  idDevGuiMainPage::childPages_t *v5; // r3
  idDevGuiPage *v6; // r3
  idDevGuiChildPage *v7; // r30
  int v8; // r8
  idDevGuiMainPage::childPages_t *v9; // r3

  idDevGuiMainPage::idDevGuiMainPage(this);
  this->__vftable = (idDevGuiMainPage_Player_vtbl *)&idDevGuiMainPage_Player::`vftable';
  v2 = (idDevGuiPage *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x54u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v3 = (idDevGuiChildPage *)v2;
  if ( v2 != nullptr )
  {
    idDevGuiPage::idDevGuiPage(this: v2, defaultRow: 0, name: "Third_Person");
    DEFAULT_ROW_NUM = v3->DEFAULT_ROW_NUM;
    v3->__vftable = (idDevGuiChildPage_vtbl *)&idDevGuiChildPage_ThirdPerson::`vftable';
    v3->selectedRow = DEFAULT_ROW_NUM;
  }
  else
  {
    v3 = nullptr;
  }
  v5 = idList<idDevGuiMainPage::childPages_t,5>::Alloc(this: &this->childPages);
  v5->rowNum = -1;
  v5->childPage = v3;
  v6 = (idDevGuiPage *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x54u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v7 = (idDevGuiChildPage *)v6;
  if ( v6 != nullptr )
  {
    idDevGuiPage::idDevGuiPage(this: v6, defaultRow: 0, name: "Set_Team");
    v8 = v7->DEFAULT_ROW_NUM;
    v7->__vftable = (idDevGuiChildPage_vtbl *)&idDevGuiChildPage_SetTeam::`vftable';
    v7->selectedRow = v8;
  }
  else
  {
    v7 = nullptr;
  }
  v9 = idList<idDevGuiMainPage::childPages_t,5>::Alloc(this: &this->childPages);
  v9->rowNum = -1;
  v9->childPage = v7;
  return this;
}


// ========================================================================
// __unwind$493636_0
// EA  : 0x82EB3E90
// RVA : 0x00EB3E90
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_493636_0()
{
  int v0; // r12

  idDevGuiMainPage::~idDevGuiMainPage(this: *(idDevGuiMainPage **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$493637_0
// EA  : 0x82EB3EB8
// RVA : 0x00EB3EB8
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall _unwind_493637_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// __unwind$493638_0
// EA  : 0x82EB3EE0
// RVA : 0x00EB3EE0
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall _unwind_493638_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 160 + 80), tag: a2);
}


// ========================================================================
// ??0idDevGuiMainPage_Render@@QAA@XZ
// EA  : 0x82EB3F10
// RVA : 0x00EB3F10
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idDevGuiMainPage_Render *__fastcall idDevGuiMainPage_Render::idDevGuiMainPage_Render(idDevGuiMainPage_Render *this)
{
  idDevGuiPage *v2; // r3
  idDevGuiChildPage *v3; // r30
  int DEFAULT_ROW_NUM; // r8
  idDevGuiMainPage::childPages_t *v5; // r3

  idDevGuiMainPage::idDevGuiMainPage(this);
  this->__vftable = (idDevGuiMainPage_Render_vtbl *)&idDevGuiMainPage_Render::`vftable';
  v2 = (idDevGuiPage *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x54u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v3 = (idDevGuiChildPage *)v2;
  if ( v2 != nullptr )
  {
    idDevGuiPage::idDevGuiPage(this: v2, defaultRow: 0, name: "Render_Reload");
    DEFAULT_ROW_NUM = v3->DEFAULT_ROW_NUM;
    v3->__vftable = (idDevGuiChildPage_vtbl *)&idDevGuiChildPage_Reload::`vftable';
    v3->selectedRow = DEFAULT_ROW_NUM;
  }
  else
  {
    v3 = nullptr;
  }
  v5 = idList<idDevGuiMainPage::childPages_t,5>::Alloc(this: &this->childPages);
  v5->childPage = v3;
  v5->rowNum = -1;
  return this;
}


// ========================================================================
// __unwind$493704
// EA  : 0x82EB3FBC
// RVA : 0x00EB3FBC
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_493704()
{
  int v0; // r12

  idDevGuiMainPage::~idDevGuiMainPage(this: *(idDevGuiMainPage **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$493705_0
// EA  : 0x82EB3FE4
// RVA : 0x00EB3FE4
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall _unwind_493705_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ??0idDevGuiMainPage_AI@@QAA@XZ
// EA  : 0x82EB4018
// RVA : 0x00EB4018
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idDevGuiMainPage_AI *__fastcall idDevGuiMainPage_AI::idDevGuiMainPage_AI(idDevGuiMainPage_AI *this)
{
  idDevGuiPage *v2; // r3
  idDevGuiChildPage *v3; // r30
  int DEFAULT_ROW_NUM; // r8
  idDevGuiMainPage::childPages_t *v5; // r3

  idDevGuiMainPage::idDevGuiMainPage(this);
  this->__vftable = (idDevGuiMainPage_AI_vtbl *)&idDevGuiMainPage_AI::`vftable';
  v2 = (idDevGuiPage *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x54u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  v3 = (idDevGuiChildPage *)v2;
  if ( v2 != nullptr )
  {
    idDevGuiPage::idDevGuiPage(this: v2, defaultRow: 0, name: "Spawn_AI");
    DEFAULT_ROW_NUM = v3->DEFAULT_ROW_NUM;
    v3->__vftable = (idDevGuiChildPage_vtbl *)&idDevGuiChildPage_SpawnAI::`vftable';
    v3->selectedRow = DEFAULT_ROW_NUM;
  }
  else
  {
    v3 = nullptr;
  }
  v5 = idList<idDevGuiMainPage::childPages_t,5>::Alloc(this: &this->childPages);
  v5->childPage = v3;
  v5->rowNum = -1;
  return this;
}


// ========================================================================
// __unwind$493748
// EA  : 0x82EB40C4
// RVA : 0x00EB40C4
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void _unwind_493748()
{
  int v0; // r12

  idDevGuiMainPage::~idDevGuiMainPage(this: *(idDevGuiMainPage **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$493749
// EA  : 0x82EB40EC
// RVA : 0x00EB40EC
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall _unwind_493749(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?Init@idDevGui@@QAAXXZ
// EA  : 0x82EB4120
// RVA : 0x00EB4120
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall idDevGui::Init(idDevGui *this)
{
  idDevGuiMainPage_Main *v2; // r3
  idDevGuiMainPage_Main *v3; // r3
  idList<enum encounterGroupRole_t,5> *p_pages; // r28
  idDevGuiMainPage_AI *v5; // r3
  idDevGuiMainPage_AI *v6; // r3
  idDevGuiMainPage *v7; // r3
  _DWORD *v8; // r27
  encounterGroupRole_t v9; // r11
  idDevGuiMainPage_Player *v10; // r3
  idDevGuiMainPage_Player *v11; // r3
  idDevGuiMainPage *v12; // r3
  _DWORD *v13; // r27
  encounterGroupRole_t v14; // r11
  idDevGuiMainPage_Render *v15; // r3
  idDevGuiMainPage_Render *v16; // r3
  idDevGuiMainPage *v17; // r3
  _DWORD *v18; // r27
  encounterGroupRole_t v19; // r11
  idDevGuiMainPage *v20; // r3
  _DWORD *v21; // r27
  encounterGroupRole_t v22; // r11
  idDevGuiMainPage *v23; // r3
  _DWORD *v24; // r27
  encounterGroupRole_t v25; // r11
  idDevGuiMainPage *v26; // r3
  _DWORD *v27; // r30
  encounterGroupRole_t v28; // r11
  bool v29; // r4
  encounterGroupRole_t v30[16]; // [sp+50h] [-40h] BYREF

  if ( this->initialized )
  {
    idLib::Warning(fmt: "Trying to Init DevGUI when its already Init!");
  }
  else
  {
    this->initialized = true;
    v2 = (idDevGuiMainPage_Main *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                    size: 0x68u,
                                    tag: TAG_NEW,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
    v30[0] = (encounterGroupRole_t)v2;
    if ( v2 != nullptr )
      v3 = idDevGuiMainPage_Main::idDevGuiMainPage_Main(this: v2);
    else
      v3 = nullptr;
    v30[0] = (encounterGroupRole_t)v3;
    p_pages = (idList<enum encounterGroupRole_t,5> *)&this->pages;
    idList<idAnimWebBlendTree *,5>::Append(this: p_pages, obj: v30);
    v5 = (idDevGuiMainPage_AI *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                  size: 0x68u,
                                  tag: TAG_NEW,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
    v30[0] = (encounterGroupRole_t)v5;
    if ( v5 != nullptr )
      v6 = idDevGuiMainPage_AI::idDevGuiMainPage_AI(this: v5);
    else
      v6 = nullptr;
    v30[0] = (encounterGroupRole_t)v6;
    idList<idAnimWebBlendTree *,5>::Append(this: p_pages, obj: v30);
    v7 = (idDevGuiMainPage *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                               size: 0x68u,
                               tag: TAG_NEW,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    v8 = &v7->__vftable;
    v30[0] = (encounterGroupRole_t)v7;
    if ( v7 != nullptr )
    {
      idDevGuiMainPage::idDevGuiMainPage(this: v7);
      v9 = (encounterGroupRole_t)v8;
      *v8 = &idDevGuiMainPage_Bot::`vftable';
    }
    else
    {
      v9 = ROLE_NONE;
    }
    v30[0] = v9;
    idList<idAnimWebBlendTree *,5>::Append(this: p_pages, obj: v30);
    v10 = (idDevGuiMainPage_Player *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                       size: 0x68u,
                                       tag: TAG_NEW,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
    v30[0] = (encounterGroupRole_t)v10;
    if ( v10 != nullptr )
      v11 = idDevGuiMainPage_Player::idDevGuiMainPage_Player(this: v10);
    else
      v11 = nullptr;
    v30[0] = (encounterGroupRole_t)v11;
    idList<idAnimWebBlendTree *,5>::Append(this: p_pages, obj: v30);
    v12 = (idDevGuiMainPage *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x68u,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    v13 = &v12->__vftable;
    v30[0] = (encounterGroupRole_t)v12;
    if ( v12 != nullptr )
    {
      idDevGuiMainPage::idDevGuiMainPage(this: v12);
      v14 = (encounterGroupRole_t)v13;
      *v13 = &idDevGuiMainPage_Weapon::`vftable';
    }
    else
    {
      v14 = ROLE_NONE;
    }
    v30[0] = v14;
    idList<idAnimWebBlendTree *,5>::Append(this: p_pages, obj: v30);
    v15 = (idDevGuiMainPage_Render *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                       size: 0x68u,
                                       tag: TAG_NEW,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
    v30[0] = (encounterGroupRole_t)v15;
    if ( v15 != nullptr )
      v16 = idDevGuiMainPage_Render::idDevGuiMainPage_Render(this: v15);
    else
      v16 = nullptr;
    v30[0] = (encounterGroupRole_t)v16;
    idList<idAnimWebBlendTree *,5>::Append(this: p_pages, obj: v30);
    v17 = (idDevGuiMainPage *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x68u,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    v18 = &v17->__vftable;
    v30[0] = (encounterGroupRole_t)v17;
    if ( v17 != nullptr )
    {
      idDevGuiMainPage::idDevGuiMainPage(this: v17);
      v19 = (encounterGroupRole_t)v18;
      *v18 = &idDevGuiMainPage_Design::`vftable';
    }
    else
    {
      v19 = ROLE_NONE;
    }
    v30[0] = v19;
    idList<idAnimWebBlendTree *,5>::Append(this: p_pages, obj: v30);
    v20 = (idDevGuiMainPage *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x68u,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    v21 = &v20->__vftable;
    v30[0] = (encounterGroupRole_t)v20;
    if ( v20 != nullptr )
    {
      idDevGuiMainPage::idDevGuiMainPage(this: v20);
      v22 = (encounterGroupRole_t)v21;
      *v21 = &idDevGuiMainPage_Sound::`vftable';
    }
    else
    {
      v22 = ROLE_NONE;
    }
    v30[0] = v22;
    idList<idAnimWebBlendTree *,5>::Append(this: p_pages, obj: v30);
    v23 = (idDevGuiMainPage *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x68u,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    v24 = &v23->__vftable;
    v30[0] = (encounterGroupRole_t)v23;
    if ( v23 != nullptr )
    {
      idDevGuiMainPage::idDevGuiMainPage(this: v23);
      v25 = (encounterGroupRole_t)v24;
      *v24 = &idDevGuiMainPage_QA::`vftable';
    }
    else
    {
      v25 = ROLE_NONE;
    }
    v30[0] = v25;
    idList<idAnimWebBlendTree *,5>::Append(this: p_pages, obj: v30);
    v26 = (idDevGuiMainPage *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x68u,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    v27 = &v26->__vftable;
    v30[0] = (encounterGroupRole_t)v26;
    if ( v26 != nullptr )
    {
      idDevGuiMainPage::idDevGuiMainPage(this: v26);
      v28 = (encounterGroupRole_t)v27;
      *v27 = &idDevGuiMainPage_Performance::`vftable';
    }
    else
    {
      v28 = ROLE_NONE;
    }
    v30[0] = v28;
    idList<idAnimWebBlendTree *,5>::Append(this: p_pages, obj: v30);
    idCVar::SetFloat(this: &np_viewDistance, newValue: 768.0, force: v29);
  }
}


// ========================================================================
// __unwind$493838
// EA  : 0x82EB44D4
// RVA : 0x00EB44D4
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall _unwind_493838(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$493839
// EA  : 0x82EB44FC
// RVA : 0x00EB44FC
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall _unwind_493839(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$493840
// EA  : 0x82EB4524
// RVA : 0x00EB4524
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall _unwind_493840(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$493841_0
// EA  : 0x82EB454C
// RVA : 0x00EB454C
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall _unwind_493841_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$493842_1
// EA  : 0x82EB4574
// RVA : 0x00EB4574
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall _unwind_493842_1(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$493843
// EA  : 0x82EB459C
// RVA : 0x00EB459C
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall _unwind_493843(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$493844
// EA  : 0x82EB45C4
// RVA : 0x00EB45C4
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall _unwind_493844(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$493845
// EA  : 0x82EB45EC
// RVA : 0x00EB45EC
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall _unwind_493845(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$493846
// EA  : 0x82EB4614
// RVA : 0x00EB4614
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall _unwind_493846(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$493847
// EA  : 0x82EB463C
// RVA : 0x00EB463C
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __fastcall _unwind_493847(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// `dynamic initializer for 'devgui''
// EA  : 0x83392D38
// RVA : 0x01392D38
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__devgui__()
{
  idCVar::idCVar(
    this: &devgui,
    name: "devgui",
    value: "0",
    flags: 2,
    description: "0 = disable DevGUI, 1 = enable DevGUI, 2 = enable DevGUI with key legend",
    valueMin: 0.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"plode - unlink clip",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__devgui__);
}


// ========================================================================
// `dynamic initializer for 'DisplayVirtualTextureInfo_v''
// EA  : 0x83392DA0
// RVA : 0x01392DA0
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__DisplayVirtualTextureInfo_v__()
{
  return idCommandLink::idCommandLink(
           this: &DisplayVirtualTextureInfo_v,
           cmdName: "DisplayVirtualTextureInfo",
           function: DisplayVirtualTextureInfo_f,
           description: "Display Info About Virtual Textures In The Current Map",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TeleportDebugAI_v''
// EA  : 0x83392DC8
// RVA : 0x01392DC8
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TeleportDebugAI_v__()
{
  return idCommandLink::idCommandLink(
           this: &TeleportDebugAI_v,
           cmdName: "TeleportDebugAI",
           function: TeleportDebugAI_f,
           description: "Teleport currently selected debug AI to player's crosshair point",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'DisconnectFromGame_v''
// EA  : 0x83392DF0
// RVA : 0x01392DF0
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__DisconnectFromGame_v__()
{
  return idCommandLink::idCommandLink(
           this: &DisconnectFromGame_v,
           cmdName: "DisconnectFromGame",
           function: DisconnectFromGame_f,
           description: "Disconnect from game thru the DevGUI",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ThirdPersonReset_v''
// EA  : 0x83392E18
// RVA : 0x01392E18
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ThirdPersonReset_v__()
{
  return idCommandLink::idCommandLink(
           this: &ThirdPersonReset_v,
           cmdName: "ThirdPersonReset",
           function: (void (__fastcall *)(const idCmdArgs *))ThirdPersonReset_f,
           description: "Reset all 3rd person values to their default",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'SetTeamDevGui_v''
// EA  : 0x83392E40
// RVA : 0x01392E40
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__SetTeamDevGui_v__()
{
  return idCommandLink::idCommandLink(
           this: &SetTeamDevGui_v,
           cmdName: "SetTeamDevGui",
           function: (void (__fastcall *)(const idCmdArgs *))idPhysics_StaticMulti::UpdateTime,
           description: "Sets the team from the devgui interface",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'TeleportBotToCrosshair_v''
// EA  : 0x83392E68
// RVA : 0x01392E68
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TeleportBotToCrosshair_v__()
{
  return idCommandLink::idCommandLink(
           this: &TeleportBotToCrosshair_v,
           cmdName: "TeleportBotToCrosshair",
           function: TeleportBotToCrosshair_f,
           description: "Teleport a bot to the player's crosshair.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ShowBotPerformanceInfo_v''
// EA  : 0x83392E90
// RVA : 0x01392E90
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ShowBotPerformanceInfo_v__()
{
  return idCommandLink::idCommandLink(
           this: &ShowBotPerformanceInfo_v,
           cmdName: "ShowBotPerformanceInfo",
           function: ShowBotPerformanceInfo_f,
           description: "Show the plog info about bots.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'RenderBotAAS_v''
// EA  : 0x83392EB8
// RVA : 0x01392EB8
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__RenderBotAAS_v__()
{
  return idCommandLink::idCommandLink(
           this: &RenderBotAAS_v,
           cmdName: "RenderBotAAS",
           function: RenderBotAAS_f,
           description: "Draw the bots AAS in the map.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'RenderWallEdges_v''
// EA  : 0x83392EE0
// RVA : 0x01392EE0
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__RenderWallEdges_v__()
{
  return idCommandLink::idCommandLink(
           this: &RenderWallEdges_v,
           cmdName: "RenderWallEdges",
           function: RenderWallEdges_f,
           description: "Draw the wall edges for the bots AAS in the map.",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'setBotDebugEntity_v''
// EA  : 0x83392F08
// RVA : 0x01392F08
// PDB : w:\tech5\tungsten\game\tools\devgui.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__setBotDebugEntity_v__()
{
  return idCommandLink::idCommandLink(
           this: &setBotDebugEntity_v,
           cmdName: "setBotDebugEntity",
           function: setBotDebugEntity_f,
           description: "sets the debug bot entity to the entity currently in the player's crosshairs",
           argCompletion: nullptr);
}

