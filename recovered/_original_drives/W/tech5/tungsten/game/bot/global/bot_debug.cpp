
// ========================================================================
// ?InternalRender@idBotWorldDebugGui@@EAAXPAVidEntity@@AAVidDeviceContext@@@Z
// EA  : 0x82B478B8
// RVA : 0x00B478B8
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void __fastcall idBotWorldDebugGui::InternalRender(
        idBotWorldDebugGui *this,
        idPlayer *debugEnt,
        idDeviceContext *context)
{
  idPlayer *v5; // r28
  idGuiListBox v6; // [sp+50h] [-E0h] BYREF

  v5 = idPlayer::CastTo(c: debugEnt);
  idGuiListBox::idGuiListBox(this: &v6);
  idSoundSystemLocal::SetEditorSoundWorld(this: (idSoundSystemLocal *)&v6, soundWorld: nullptr);
  idPlayer::UpdateBotGUI(this: v5, infoList: &v6, debugType: BOT_DEBUG_GUI_TYPE_WORLD);
  idGuiListBox::Render(this: &v6, page: this, context, hAlign: 0, vAlign: 1u, nextTo: nullptr);
  idGuiListBox::~idGuiListBox(this: &v6);
}


// ========================================================================
// __unwind$487703
// EA  : 0x82B4792C
// RVA : 0x00B4792C
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void _unwind_487703()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 304 + 80));
}


// ========================================================================
// ?InternalRender@idBotBehaviorTreeDebugGui@@EAAXPAVidEntity@@AAVidDeviceContext@@@Z
// EA  : 0x82B47960
// RVA : 0x00B47960
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void __fastcall idBotBehaviorTreeDebugGui::InternalRender(
        idBotBehaviorTreeDebugGui *this,
        idPlayer *debugEnt,
        idDeviceContext *context)
{
  idPlayer *v5; // r28
  idGuiListBox v6; // [sp+50h] [-E0h] BYREF

  v5 = idPlayer::CastTo(c: debugEnt);
  idGuiListBox::idGuiListBox(this: &v6);
  idSoundSystemLocal::SetEditorSoundWorld(this: (idSoundSystemLocal *)&v6, soundWorld: nullptr);
  idPlayer::UpdateBotGUI(this: v5, infoList: &v6, debugType: BOT_DEBUG_GUI_TYPE_BEHAVIOR);
  idGuiListBox::Render(this: &v6, page: this, context, hAlign: 0, vAlign: 0, nextTo: nullptr);
  idGuiListBox::~idGuiListBox(this: &v6);
}


// ========================================================================
// __unwind$487726
// EA  : 0x82B479D4
// RVA : 0x00B479D4
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void _unwind_487726()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 304 + 80));
}


// ========================================================================
// ?HandleEvent@idBotGUI@@QAA_NPBUsysEvent_t@@@Z
// EA  : 0x82B47A00
// RVA : 0x00B47A00
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

int __fastcall idBotGUI::HandleEvent(idBotGUI *this, const drawSurf_t *event)
{
  int v4; // r4
  int valueMax; // r4
  idGuiPage **list; // r10

  if ( botGUI.valueInteger == 0 )
    return 0;
  if ( LODWORD(event->sort) == 1 )
  {
    switch ( *(_DWORD *)&event->isWorld )
    {
      case 'G':
        v4 = 7;
        goto LABEL_14;
      case 'H':
        v4 = 8;
        goto LABEL_14;
      case 'I':
        v4 = 9;
        goto LABEL_14;
      case 'K':
        v4 = 4;
        goto LABEL_14;
      case 'L':
        v4 = 5;
        goto LABEL_14;
      case 'M':
        v4 = 6;
        goto LABEL_14;
      case 'O':
        v4 = 1;
        goto LABEL_14;
      case 'P':
        v4 = 2;
        goto LABEL_14;
      case 'Q':
        v4 = 3;
        goto LABEL_14;
      case 'R':
        v4 = 0;
LABEL_14:
        idCVar::SetInteger(this: &botGUI, newValue: v4, force: true);
        break;
      default:
        break;
    }
  }
  valueMax = (int)botGUI.valueMax;
  if ( botGUI.valueInteger >= (int)botGUI.valueMin )
  {
    if ( botGUI.valueInteger <= valueMax )
      valueMax = botGUI.valueInteger;
  }
  else
  {
    valueMax = (int)botGUI.valueMin;
  }
  idCVar::SetInteger(this: &botGUI, newValue: valueMax, force: true);
  if ( botGUI.valueInteger > 0
    && botGUI.valueInteger < this->pages.num
    && (list = this->pages.list)[botGUI.valueInteger] != nullptr )
  {
    return idGuiPage::HandleEvent(this: list[botGUI.valueInteger], event);
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?ShouldRender@idBotGUI@@AAA_NXZ
// EA  : 0x82B47B80
// RVA : 0x00B47B80
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

int __fastcall idBotGUI::ShouldRender(idBotGUI *this)
{
  unsigned int v1; // r30
  unsigned int v2; // r30
  bool v3; // r29
  idLobbyBase *v4; // r3
  int v5; // r3

  v1 = (unsigned __int8)(!this->initialized - 1) & ((-botGUI.valueInteger & (unsigned int)~botGUI.valueInteger) >> 31);
  v2 = idGameLocal::GetDebugPlayer(this: gameLocal) == nullptr ? 0 : v1;
  v3 = common->IsClient(this: common);
  v4 = session->GetActingGameStateLobbyBase(this: session);
  v5 = v4->GetNumConnectedPeers(this: v4);
  if ( v3 || v5 > 0 )
    LOBYTE(v2) = 0;
  if ( (_BYTE)v2 != 0 )
    return 1;
  idCVar::SetInteger(this: &botGUI, newValue: 0, force: true);
  return 0;
}


// ========================================================================
// ?RenderBaseGUI@idBotGUI@@AAAXAAVidDeviceContext@@@Z
// EA  : 0x82B47C68
// RVA : 0x00B47C68
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void __fastcall idBotGUI::RenderBaseGUI(idBotGUI *this, idDeviceContext *context)
{
  int v4; // r30
  int v5; // r29
  idGuiPage *v6; // r10
  const char *data; // r25
  idGuiListBox *v8; // r3
  __int64 v9; // r6
  __int64 v10; // r10
  __int64 v11; // r8
  idGuiListBox *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r8
  __int64 v15; // r6
  idGuiListBox v16; // [sp+60h] [-F0h] BYREF

  idGuiListBox::idGuiListBox(this: &v16);
  idSoundSystemLocal::SetEditorSoundWorld(
    this: (idSoundSystemLocal *)&v16,
    soundWorld: (idSoundWorldLocal *)(botGUI.valueInteger - 1));
  v4 = 0;
  if ( this->pages.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = this->pages.list[v5];
      if ( v6 != nullptr )
      {
        data = v6->pageName.data;
        v8 = idGuiListBox::Row(this: &v16);
        HIDWORD(v9) = v4;
        v12 = idGuiListBox::Printf(this: v8, fmt: "KP %d - ", a3: v9, a4: v11, a5: v10);
        idGuiListBox::Printf(this: v12, fmt: data, a3: v15, a4: v14, a5: v13);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->pages.num );
  }
  idGuiListBox::Render(this: &v16, page: nullptr, context, hAlign: 1u, vAlign: 2u, nextTo: nullptr);
  idGuiListBox::~idGuiListBox(this: &v16);
}


// ========================================================================
// __unwind$487957
// EA  : 0x82B47D38
// RVA : 0x00B47D38
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void _unwind_487957()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 336 + 96));
}


// ========================================================================
// ?InternalRender@idBotHudGui@@EAAXPAVidEntity@@AAVidDeviceContext@@@Z
// EA  : 0x82B47D68
// RVA : 0x00B47D68
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void __fastcall idBotHudGui::InternalRender(idBotHudGui *this, idPlayer *debugEnt, idDeviceContext *context)
{
  idPlayer *v5; // r30
  idGuiListBox *v6; // r3
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  idGuiListBox *v10; // r3
  __int64 v11; // r10
  __int64 v12; // r8
  __int64 v13; // r6
  idLobbyBase *v14; // r3
  idPresentable *presentable; // r11
  idLobbyBase *v16; // r29
  lobbyUserID_t *v17; // r4
  idLobbyBase_vtbl *v18; // r28
  lobbyUserID_t *LobbyUserID; // r3
  int v20; // r29
  idGuiListBox *v21; // r3
  __int64 v22; // r10
  __int64 v23; // r8
  __int64 v24; // r6
  idGuiListBox *v25; // r3
  __int64 v26; // r8
  __int64 v27; // r6
  __int64 v28; // r10
  int entityNumber; // r29
  idGuiListBox *v30; // r3
  __int64 v31; // r8
  __int64 v32; // r10
  __int64 v33; // r6
  idGuiListBox *v34; // r3
  __int64 v35; // r6
  __int64 v36; // r10
  __int64 v37; // r8
  double v38; // fp31
  idGuiListBox *v39; // r3
  __int64 v40; // r10
  __int64 v41; // r8
  __int64 v42; // r6
  idGuiListBox *v43; // r3
  __int64 v44; // r6
  __int64 v45; // r10
  __int64 v46; // r8
  idPhysics *Physics; // r3
  idAngles *v48; // r3
  const char *v49; // r29
  idGuiListBox *v50; // r3
  __int64 v51; // r8
  __int64 v52; // r10
  __int64 v53; // r6
  idGuiListBox *v54; // r3
  __int64 v55; // r6
  __int64 v56; // r10
  __int64 v57; // r8
  int v58; // [sp+50h] [-100h] BYREF
  idGuiListBox v59; // [sp+60h] [-F0h] BYREF

  v5 = idPlayer::CastTo(c: debugEnt);
  idGuiListBox::idGuiListBox(this: &v59);
  idSoundSystemLocal::SetEditorSoundWorld(this: (idSoundSystemLocal *)&v59, soundWorld: nullptr);
  v6 = idGuiListBox::Row(this: &v59);
  v10 = idGuiListBox::Printf(this: v6, fmt: "- BOT INFO -", a3: v9, a4: v8, a5: v7);
  LODWORD(v11) = "Could not find AI state, idVS_ds_Car_Chase! ";
  idGuiListBox::Printf(this: v10, fmt: "--------------------------------", a3: v13, a4: v12, a5: v11);
  v14 = session->GetActingGameStateLobbyBase(this: session);
  presentable = v5->presentable;
  v16 = v14;
  if ( presentable != nullptr )
    v17 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: v5->presentable);
  else
    v17 = nullptr;
  v18 = v16->__vftable;
  LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v58, result: v17);
  v20 = (int)v18->GetLobbyUserName(
               this: (idLobbyBase *)LobbyUserID->localUserHandle.handle,
               a2: *(lobbyUserID_t **)&LobbyUserID->lobbyType);
  v21 = idGuiListBox::Row(this: &v59);
  HIDWORD(v22) = &off_822B0000;
  v25 = idGuiListBox::Printf(this: v21, fmt: "Name: ", a3: v24, a4: v23, a5: v22);
  LODWORD(v26) = byte_821B0000;
  HIDWORD(v27) = v20;
  idGuiListBox::Printf(this: v25, fmt: "%s", a3: v27, a4: v26, a5: v28);
  entityNumber = v5->entityNumber;
  v30 = idGuiListBox::Row(this: &v59);
  HIDWORD(v31) = &off_822B0000;
  v34 = idGuiListBox::Printf(this: v30, fmt: "Number: ", a3: v33, a4: v31, a5: v32);
  LODWORD(v35) = 0x82000000;
  HIDWORD(v35) = entityNumber;
  idGuiListBox::Printf(this: v34, fmt: "%d", a3: v35, a4: v37, a5: v36);
  v38 = ((double (__fastcall *)(idTungstenHealth *))v5->playerHealth.GetTotalCurHealth_Impl)(a1: &v5->playerHealth);
  v39 = idGuiListBox::Row(this: &v59);
  v43 = idGuiListBox::Printf(this: v39, fmt: "Health: ", a3: v42, a4: v41, a5: v40);
  HIDWORD(v44) = LODWORD(v38);
  LODWORD(v45) = "ound traces";
  idGuiListBox::Printf(this: v43, fmt: "%.2f", a3: v44, a4: v46, a5: v45, v38);
  Physics = idEntity::GetPhysics(this: v5);
  v48 = (idAngles *)Physics->GetOrigin(this: Physics, a2: 0);
  v49 = idVec3::ToString(this: v48, precision: 1);
  v50 = idGuiListBox::Row(this: &v59);
  HIDWORD(v51) = &off_822B0000;
  v54 = idGuiListBox::Printf(this: v50, fmt: "Position: ", a3: v53, a4: v51, a5: v52);
  HIDWORD(v55) = v49;
  idGuiListBox::Printf(this: v54, fmt: "%s", a3: v55, a4: v57, a5: v56);
  idPlayer::UpdateBotGUI(this: v5, infoList: &v59, debugType: BOT_DEBUG_GUI_TYPE_HUD);
  idGuiListBox::Render(this: &v59, page: this, context, hAlign: 0, vAlign: 0, nextTo: nullptr);
  idGuiListBox::~idGuiListBox(this: &v59);
}


// ========================================================================
// __unwind$488003
// EA  : 0x82B47F50
// RVA : 0x00B47F50
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void _unwind_488003()
{
  int v0; // r12

  idGuiListBox::~idGuiListBox(this: (idGuiListBox *)(v0 - 336 + 96));
}


// ========================================================================
// ??0idBotHudGui@@QAA@XZ
// EA  : 0x82B47F80
// RVA : 0x00B47F80
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

idBotHudGui *__fastcall idBotHudGui::idBotHudGui(idBotHudGui *this)
{
  idStr v3; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "Bot Info");
  idGuiPage::idGuiPage(this, name: &v3);
  idStr::FreeData(this: &v3);
  this->__vftable = (idBotHudGui_vtbl *)&idBotHudGui::`vftable';
  return this;
}


// ========================================================================
// __unwind$488131
// EA  : 0x82B47FEC
// RVA : 0x00B47FEC
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void _unwind_488131()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$488132
// EA  : 0x82B48014
// RVA : 0x00B48014
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void _unwind_488132()
{
  int v0; // r12

  idGuiPage::~idGuiPage(this: *(idGuiPage **)(v0 - 144 + 164));
}


// ========================================================================
// ??0idBotWorldDebugGui@@QAA@XZ
// EA  : 0x82B480B0
// RVA : 0x00B480B0
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

idBotWorldDebugGui *__fastcall idBotWorldDebugGui::idBotWorldDebugGui(idBotWorldDebugGui *this)
{
  idStr v3; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "Bot World State");
  idGuiPage::idGuiPage(this, name: &v3);
  idStr::FreeData(this: &v3);
  this->__vftable = (idBotWorldDebugGui_vtbl *)&idBotWorldDebugGui::`vftable';
  return this;
}


// ========================================================================
// __unwind$488186
// EA  : 0x82B4811C
// RVA : 0x00B4811C
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void _unwind_488186()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$488187
// EA  : 0x82B48144
// RVA : 0x00B48144
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void _unwind_488187()
{
  int v0; // r12

  idGuiPage::~idGuiPage(this: *(idGuiPage **)(v0 - 144 + 164));
}


// ========================================================================
// ??0idBotBehaviorTreeDebugGui@@QAA@XZ
// EA  : 0x82B481E0
// RVA : 0x00B481E0
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

idBotBehaviorTreeDebugGui *__fastcall idBotBehaviorTreeDebugGui::idBotBehaviorTreeDebugGui(
        idBotBehaviorTreeDebugGui *this)
{
  idStr v3; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "Bot Behavior Debug");
  idGuiPage::idGuiPage(this, name: &v3);
  idStr::FreeData(this: &v3);
  this->__vftable = (idBotBehaviorTreeDebugGui_vtbl *)&idBotBehaviorTreeDebugGui::`vftable';
  return this;
}


// ========================================================================
// __unwind$488231
// EA  : 0x82B4824C
// RVA : 0x00B4824C
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void _unwind_488231()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$488232
// EA  : 0x82B48274
// RVA : 0x00B48274
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void _unwind_488232()
{
  int v0; // r12

  idGuiPage::~idGuiPage(this: *(idGuiPage **)(v0 - 144 + 164));
}


// ========================================================================
// ??0idBotGUI@@QAA@XZ
// EA  : 0x82B48308
// RVA : 0x00B48308
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

idBotGUI *__fastcall idBotGUI::idBotGUI(idBotGUI *this)
{
  this->initialized = false;
  this->firstDraw = true;
  this->oldGuiTextScale = 0.0;
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
// ??1idBotGUI@@QAA@XZ
// EA  : 0x82B48388
// RVA : 0x00B48388
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void __fastcall idBotGUI::~idBotGUI(idBotGUI *this)
{
  idRenderModelGui *guiModel; // r3

  guiModel = this->guiModel;
  if ( guiModel != nullptr )
  {
    guiModel->unlinked = true;
    guiModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: guiModel);
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pages);
}


// ========================================================================
// __unwind$488411
// EA  : 0x82B483E8
// RVA : 0x00B483E8
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void _unwind_488411()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ?FindBotDebugEntity@idBotGUI@@AAAXXZ
// EA  : 0x82B48418
// RVA : 0x00B48418
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void __fastcall idBotGUI::FindBotDebugEntity(idBotGUI *this)
{
  idPlayer *DebugPlayer; // r22
  idGameLocal *v2; // r11
  int num; // r10
  idEntity *v4; // r23
  double v5; // fp31
  int v6; // r27
  int v7; // r28
  int value; // r9
  idPlayer *v9; // r3
  idPlayer *v10; // r31
  idLobbyBase *v11; // r3
  idPresentable *presentable; // r11
  idLobbyBase *v13; // r30
  lobbyUserID_t *v14; // r4
  idLobbyBase_vtbl *v15; // r29
  lobbyUserID_t *LobbyUserID; // r3
  idPhysics *Physics; // r3
  float *v18; // r30
  idPhysics *v19; // r3
  float *v20; // r3
  double v21; // fp10
  double v22; // fp6
  char v23; // [sp+50h] [-70h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr )
  {
    v2 = gameLocal;
    num = gameLocal->botEntities.num;
    if ( num != 0 )
    {
      v4 = nullptr;
      v5 = 1.0e30;
      if ( num > 0 )
      {
        v6 = gameLocal->botEntities.num;
        v7 = 0;
        do
        {
          value = v2->botEntities.list[v7].spawnId.value;
          if ( v2->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
          {
            v9 = (idPlayer *)v2->entities.ptr[value & 0x1FFF];
            if ( v9 != nullptr )
            {
              v10 = idPlayer::CastTo(c: v9);
              if ( v10 != nullptr )
              {
                v11 = session->GetActingGameStateLobbyBase(this: session);
                presentable = v10->presentable;
                v13 = v11;
                if ( presentable != nullptr )
                  v14 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: v10->presentable);
                else
                  v14 = nullptr;
                v15 = v13->__vftable;
                LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v23, result: v14);
                if ( v15->IsLobbyUserValid(
                       this: (idLobbyBase *)LobbyUserID->localUserHandle.handle,
                       a2: *(lobbyUserID_t **)&LobbyUserID->lobbyType) )
                {
                  Physics = idEntity::GetPhysics(this: DebugPlayer);
                  v18 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
                  v19 = idEntity::GetPhysics(this: v10);
                  v20 = (float *)v19->GetOrigin(this: v19, a2: 0);
                  v21 = (float)(v20[1] - v18[1]);
                  v22 = (float)(v20[2] - v18[2]);
                  if ( (float)((float)((float)v22 * (float)v22)
                             + (float)((float)((float)(*v20 - *v18) * (float)(*v20 - *v18))
                                     + (float)((float)v21 * (float)v21))) < v5 )
                  {
                    v5 = (float)((float)((float)v22 * (float)v22)
                               + (float)((float)((float)(*v20 - *v18) * (float)(*v20 - *v18))
                                       + (float)((float)v21 * (float)v21)));
                    v4 = v10;
                  }
                }
              }
              v2 = gameLocal;
            }
          }
          --v6;
          ++v7;
        }
        while ( v6 != 0 );
      }
      idGameLocal::BotSystems_SetBotDebugEntity(this: v2, entity: v4);
    }
  }
}


// ========================================================================
// ?DrawGUI@idBotGUI@@QAAPAVidRenderModelGui@@PAVidEntity@@@Z
// EA  : 0x82B485E8
// RVA : 0x00B485E8
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

idRenderModelGui *__fastcall idBotGUI::DrawGUI(idBotGUI *this, idPlayer *ent)
{
  idPlayer *v5; // r30
  idLobbyBase *v6; // r3
  idPresentable *presentable; // r11
  idLobbyBase *v8; // r30
  lobbyUserID_t *v9; // r4
  idLobbyBase_vtbl *v10; // r29
  lobbyUserID_t *LobbyUserID; // r3
  idPhysics *Physics; // r29
  idPhysics *v13; // r26
  idRenderWorld *v14; // r25
  idPhysics *v15; // r3
  int v16; // r24
  idRenderWorld_vtbl *v17; // r30
  int v18; // r29
  int v19; // r3
  unsigned __int64 v20; // r6
  bool v21; // r4
  BOOL firstDraw; // r7
  unsigned int v23; // r30
  unsigned int v24; // r3
  int v25; // r10
  int v26; // r9
  int v27; // r8
  int v28; // r7
  int v29; // r5
  int v30; // r4
  idGuiPage **list; // r10
  double oldGuiTextScale; // fp1
  char v33; // [sp+50h] [-570h] BYREF
  idDeviceContext v34; // [sp+60h] [-560h] BYREF

  if ( devgui.valueInteger > 0 )
  {
    this->firstDraw = true;
    return nullptr;
  }
  if ( botGUI.valueInteger != 0 && (unsigned __int8)idBotGUI::ShouldRender(this) != 0 )
  {
    if ( ent != nullptr )
    {
      v5 = idPlayer::CastTo(c: ent);
      if ( v5 != nullptr )
      {
        v6 = session->GetActingGameStateLobbyBase(this: session);
        presentable = v5->presentable;
        v8 = v6;
        v9 = presentable != nullptr ? (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable) : nullptr;
        v10 = v8->__vftable;
        LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v33, result: v9);
        if ( v10->IsLobbyUserValid(
               this: (idLobbyBase *)LobbyUserID->localUserHandle.handle,
               a2: *(lobbyUserID_t **)&LobbyUserID->lobbyType) )
        {
          Physics = idEntity::GetPhysics(this: ent);
          v13 = idEntity::GetPhysics(this: ent);
          v14 = gameLocal->GetRenderWorld(this: gameLocal);
          v15 = idEntity::GetPhysics(this: ent);
          v16 = (int)v15->GetOrigin(this: v15, a2: 0);
          v17 = v14->__vftable;
          v18 = (int)Physics->GetAxis(this: Physics, a2: 0);
          v19 = (int)v13->GetBounds(this: v13, a2: -1);
          v17->DebugOrientedBounds(
            this: v14,
            a2: (const idVec4 *)&idColor::colorGreen,
            a3: (const idBounds *)v19,
            a4: (const idVec3 *)v16,
            a5: (const idMat3 *)v18,
            a6: 0,
            a7: false);
          firstDraw = this->firstDraw;
          if ( this->firstDraw )
          {
            this->firstDraw = false;
            this->oldGuiTextScale = aigui_scale.valueFloat;
            idCVar::SetFloat(this: &aigui_scale, newValue: 0.34999999, force: v21);
          }
          idRenderModelGui::Clear(
            this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
            a2: defaultExtraGLState,
            bits: v20,
            a4: firstDraw);
          v23 = renderSystem->GetHeight(this: renderSystem);
          v24 = renderSystem->GetWidth(this: renderSystem);
          idRenderModelGui::SetViewport(this: this->guiModel, x: 0, y: 0, width: v24, height: v23);
          idRenderModelGui::SetupMonospaceFont(
            this: this->guiModel,
            drawWidth: 10.0,
            a3: v30,
            a4: v29,
            a5: 0x82000000,
            a6: v28,
            a7: v27,
            a8: v26,
            a9: v25);
          idDeviceContext::idDeviceContext(this: &v34, guiModel: this->guiModel);
          idDeviceContext::SetFont(this: &v34, font: (const idFont *)monospaceFont.r);
          idBotGUI::RenderBaseGUI(this, context: &v34);
          if ( botGUI.valueInteger >= 0 && botGUI.valueInteger < this->pages.num )
          {
            list = this->pages.list;
            if ( list[botGUI.valueInteger] != nullptr )
              idGuiPage::Render(this: list[botGUI.valueInteger], debugEnt: ent, context: &v34);
          }
          return this->guiModel;
        }
      }
      idGameLocal::BotSystems_SetBotDebugEntity(this: gameLocal, entity: nullptr);
    }
    idBotGUI::FindBotDebugEntity(this);
    return nullptr;
  }
  if ( !this->firstDraw )
  {
    oldGuiTextScale = this->oldGuiTextScale;
    this->firstDraw = true;
    idCVar::SetFloat(this: &aigui_scale, newValue: oldGuiTextScale, force: (const bool)ent);
  }
  return nullptr;
}


// ========================================================================
// ?Init@idBotGUI@@QAAXXZ
// EA  : 0x82B48910
// RVA : 0x00B48910
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void __fastcall idBotGUI::Init(idBotGUI *this)
{
  idBotHudGui *v2; // r3
  idBotHudGui *v3; // r3
  idBotWorldDebugGui *v4; // r3
  idBotWorldDebugGui *v5; // r3
  idBotBehaviorTreeDebugGui *v6; // r3
  idBotBehaviorTreeDebugGui *v7; // r3
  idRenderModelGui *v8; // r3
  idRenderModelGui *v9; // r3
  encounterGroupRole_t v10[16]; // [sp+50h] [-40h] BYREF

  if ( this->initialized )
  {
    idLib::Warning(fmt: "Trying to Init idBotGUI when its already Init!");
  }
  else
  {
    this->initialized = true;
    v10[0] = ROLE_NONE;
    idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->pages, obj: v10);
    v2 = (idBotHudGui *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x40u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    v10[0] = (encounterGroupRole_t)v2;
    if ( v2 != nullptr )
      v3 = idBotHudGui::idBotHudGui(this: v2);
    else
      v3 = nullptr;
    v10[0] = (encounterGroupRole_t)v3;
    idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->pages, obj: v10);
    v4 = (idBotWorldDebugGui *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                 size: 0x40u,
                                 tag: TAG_NEW,
                                 zeroBuffer: false,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
    v10[0] = (encounterGroupRole_t)v4;
    if ( v4 != nullptr )
      v5 = idBotWorldDebugGui::idBotWorldDebugGui(this: v4);
    else
      v5 = nullptr;
    v10[0] = (encounterGroupRole_t)v5;
    idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->pages, obj: v10);
    v6 = (idBotBehaviorTreeDebugGui *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                        size: 0x40u,
                                        tag: TAG_NEW,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
    v10[0] = (encounterGroupRole_t)v6;
    if ( v6 != nullptr )
      v7 = idBotBehaviorTreeDebugGui::idBotBehaviorTreeDebugGui(this: v6);
    else
      v7 = nullptr;
    v10[0] = (encounterGroupRole_t)v7;
    idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->pages, obj: v10);
    v8 = (idRenderModelGui *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xA410u,
                               tag: TAG_GUI_MODEL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    v10[0] = (encounterGroupRole_t)v8;
    if ( v8 != nullptr )
      v9 = idRenderModelGui::idRenderModelGui(this: v8);
    else
      v9 = nullptr;
    this->guiModel = v9;
  }
}


// ========================================================================
// __unwind$488657
// EA  : 0x82B48A94
// RVA : 0x00B48A94
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void __fastcall _unwind_488657(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$488658
// EA  : 0x82B48ABC
// RVA : 0x00B48ABC
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void __fastcall _unwind_488658(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$488659
// EA  : 0x82B48AE4
// RVA : 0x00B48AE4
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void __fastcall _unwind_488659(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 144 + 80), tag: a2);
}


// ========================================================================
// __unwind$488660_0
// EA  : 0x82B48B0C
// RVA : 0x00B48B0C
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void _unwind_488660_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_GUI_MODEL);
}


// ========================================================================
// `dynamic initializer for 'botGUI''
// EA  : 0x8336CEC8
// RVA : 0x0136CEC8
// PDB : w:\tech5\tungsten\game\bot\global\bot_debug.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__botGUI__()
{
  idCVar::idCVar(
    this: &botGUI,
    name: "botGUI",
    value: "0",
    flags: 2,
    description: "0 = no Bot debug GUI, 1-3 = Bot Info Debug Page",
    valueMin: 0.0,
    valueMax: 3.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)&off_822B0000,
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__botGUI__);
}

