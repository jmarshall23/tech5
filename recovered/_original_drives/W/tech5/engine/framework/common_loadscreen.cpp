
// ========================================================================
// ?PlayLoadSound@idCommonLocal@@UAAHXZ
// EA  : 0x826573D8
// RVA : 0x006573D8
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

int __fastcall idCommonLocal::PlayLoadSound(idCommonLocal *this)
{
  idSWF **p_loadingGui; // r30
  idSoundWorld *v2; // r3
  idStr *v3; // r3
  int v4; // r30
  idStr v6; // [sp+50h] [-50h] BYREF

  p_loadingGui = &this->loadingGui;
  if ( this->loadingGui != nullptr && soundSystem != nullptr )
  {
    v2 = soundSystem->GetPlayingSoundWorld(this: soundSystem);
    idSWF::AllocateEmitter(this: *p_loadingGui, sndWorld: v2);
    idSWF::GetGlobal(this: (idSWF *)&v6, result: (idSWFScriptVar *)*p_loadingGui, name: "loadingSound");
    if ( v6.len != 3 )
    {
      v3 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v6.baseBuffer[4], result: &v6);
      v4 = idSWF::PlaySound(this: *p_loadingGui, sound: v3->data, channel: SND_CHANNEL_VOICE, blocking: true);
      idStr::FreeData(this: (idStr *)&v6.baseBuffer[4]);
      idSWFScriptVar::Free(this: (idSWFScriptVar *)&v6);
      return v4;
    }
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v6);
  }
  return -1;
}


// ========================================================================
// __unwind$225399
// EA  : 0x826574B0
// RVA : 0x006574B0
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void _unwind_225399()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$225400
// EA  : 0x826574D8
// RVA : 0x006574D8
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void _unwind_225400()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// ?UpdateLevelLoadPacifier@idCommonLocal@@UAAXMW4pacifierState_t@@_N1@Z
// EA  : 0x82657630
// RVA : 0x00657630
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void __fastcall idCommonLocal::UpdateLevelLoadPacifier(
        idCommonLocal *this,
        double fractionComplete,
        pacifierState_t state,
        int force,
        bool updateConsole)
{
  int v9; // r29
  int v10; // r25
  int v11; // r3
  int v12; // r30
  idSWF **p_loadingGui; // r26
  idRenderModelGui **p_guiModel; // r29
  int v15; // r30
  int v16; // r27
  double v17; // fp1
  __int64 v18; // r10
  idRenderModelGui *v19; // r3
  unsigned __int64 v20; // r6
  idLobbyBase *v21; // r3
  idLobbyBase *v22; // r3
  idSWFScriptVar v23; // [sp+50h] [-80h] BYREF
  idSWFScriptVar v24; // [sp+58h] [-78h] BYREF
  idSWFScriptVar v25; // [sp+60h] [-70h] BYREF
  int v27; // [sp+6Ch] [-64h]

  if ( com_newLoadScreen.valueInteger == 0 )
  {
    if ( renderSystem->BinkVideoIsPlaying(this: renderSystem) )
    {
      session->UpdateSignInManager(this: session);
      session->Pump(this: session);
    }
    else
    {
      v9 = !common->IsMultiplayer(this: common) ? 100 : 16;
      v10 = !common->IsMultiplayer(this: common) ? 8000 : 1000;
      v11 = Sys_Milliseconds();
      v12 = v11;
      if ( v11 - this->lastPacifierSessionTime >= v9 )
      {
        this->lastPacifierSessionTime = v11;
        soundSystem->Render(this: soundSystem, a2: false);
        session->UpdateSignInManager(this: session);
        session->Pump(this: session);
        session->ProcessSnapAckQueue(this: session);
      }
      p_loadingGui = &this->loadingGui;
      if ( this->loadingGui != nullptr && (p_guiModel = &this->guiModel, this->guiModel != nullptr) )
      {
        if ( (!this->dialogWingstickActive || updateConsole)
          && (updateConsole || v12 - this->lastPacifierGuiTime >= v10) )
        {
          this->lastPacifierGuiTime = v12;
          if ( v12 - this->lastPacifierTooltipTime >= 8000 )
          {
            this->lastPacifierTooltipTime = v12;
            idSWFScriptVar::idSWFScriptVar(this: &v23, b: true);
            idSWFScriptObject::Set(this: (*p_loadingGui)->globals, name: "nextTooltip", value: &v23);
            idSWFScriptVar::Free(this: &v23);
            if ( com_showMapLoadStatus.valueInteger != 0 )
            {
              idSWFScriptVar::idSWFScriptVar(this: &v24, s: pacifierStateToString[force]);
              idSWFScriptObject::Set(this: (*p_loadingGui)->globals, name: "mapLoadText", value: &v24);
              idSWFScriptVar::Free(this: &v24);
            }
          }
          idSWFScriptVar::idSWFScriptVar(this: &v25, f: (float)((float)fractionComplete * (float)100.0));
          idSWFScriptObject::Set(this: (*p_loadingGui)->globals, name: "mapLoadPercent", value: &v25);
          idSWFScriptVar::Free(this: &v25);
          v15 = renderSystem->GetWidth(this: renderSystem);
          v16 = renderSystem->GetHeight(this: renderSystem);
          idRenderModelGui::SetViewport(this: *p_guiModel, x: 0, y: 0, width: v15, height: v16);
          v17 = ((double (__fastcall *)(idRenderSystem *))renderSystem->GetPixelAspect)(a1: renderSystem);
          LODWORD(v18) = v15;
          v19 = *p_guiModel;
          v27 = (int)(float)((float)v17 * (float)v18);
          idRenderModelGui::SetVirtualSize(this: v19, width: v27, height: v16);
          idRenderModelGui::Clear(this: (idRenderModelGui *)HIDWORD(defaultExtraGLState), bits: v20);
          idSWF::Render(this: *p_loadingGui, gui: *p_guiModel, time: 0, isSplitscreen: false);
          v21 = session->GetActingGameStateLobbyBase(this: session);
          if ( v21->HasActivePeers(this: v21) && net_drawDebugHud.valueInteger != 0 )
          {
            v22 = session->GetActingGameStateLobbyBase(this: session);
            v22->DrawDebugNetworkHUD(this: v22, a2: *p_guiModel);
          }
          idRenderManager::BuildGuiFrame(this: &renderManager, baseGui: *p_guiModel, loading: true);
          idRenderManager::RenderFrameAndBeginAutomaticBackgroundSwaps(this: &renderManager);
        }
      }
      else
      {
        renderSystem->SyncRenderThread(this: renderSystem, a2: false);
      }
    }
  }
}


// ========================================================================
// __unwind$225529
// EA  : 0x82657A40
// RVA : 0x00657A40
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void _unwind_225529()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$225530
// EA  : 0x82657A68
// RVA : 0x00657A68
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void _unwind_225530()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 208 + 88));
}


// ========================================================================
// __unwind$225531
// EA  : 0x82657A90
// RVA : 0x00657A90
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void _unwind_225531()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 208 + 96));
}


// ========================================================================
// ?LoadVirtualTextures@idCommonLocal@@QAAXXZ
// EA  : 0x82657AC0
// RVA : 0x00657AC0
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void __fastcall idCommonLocal::LoadVirtualTextures(idCommonLocal *this)
{
  idSWF **p_loadingGui; // r20
  idRenderModelGui **p_guiModel; // r28
  int v4; // r22
  int v5; // r3
  __int64 v6; // r10
  int v7; // r23
  int v8; // r24
  double v9; // fp31
  double v10; // fp1
  idRenderModelGui *v11; // r3
  unsigned __int64 v12; // r6
  int num; // r18
  encounterGroupRole_t *list; // r17
  idRenderSystem_vtbl *v15; // r25
  idRenderWorld *v16; // r16
  int v17; // r15
  int v18; // r14
  void *v19; // r3
  int v20; // r4
  idLobbyBase *v21; // r3
  int v22; // r3
  __int64 v23; // [sp+70h] [-D0h] BYREF
  idSWFScriptVar v24; // [sp+78h] [-C8h] BYREF
  idList<enum encounterGroupRole_t,5> v25; // [sp+80h] [-C0h] BYREF
  int v26; // [sp+90h] [-B0h] BYREF

  if ( !renderSystem->BinkVideoIsPlaying(this: renderSystem) )
  {
    p_loadingGui = &this->loadingGui;
    if ( this->loadingGui != nullptr && (p_guiModel = &this->guiModel, this->guiModel != nullptr) )
    {
      idSWFScriptVar::idSWFScriptVar(this: &v24, f: 100.0);
      idSWFScriptObject::Set(this: (*p_loadingGui)->globals, name: "mapLoadPercent", value: &v24);
      idSWFScriptVar::Free(this: &v24);
      this->BeginTerminationThread(this);
      v4 = renderSystem->GetWidth(this: renderSystem);
      v5 = renderSystem->GetHeight(this: renderSystem);
      LODWORD(v6) = v4;
      v7 = v5;
      v23 = v6;
      v8 = 3;
      v9 = (float)v6;
      do
      {
        idRenderModelGui::SetViewport(this: *p_guiModel, x: 0, y: 0, width: v4, height: v7);
        v10 = ((double (__fastcall *)(idRenderSystem *))renderSystem->GetPixelAspect)(a1: renderSystem);
        v11 = *p_guiModel;
        LODWORD(v23) = (int)(float)((float)v10 * (float)v9);
        idRenderModelGui::SetVirtualSize(this: v11, width: v23, height: v7);
        idRenderModelGui::Clear(this: *p_guiModel, bits: v12);
        idSWF::Render(this: *p_loadingGui, gui: *p_guiModel, time: 0, isSplitscreen: false);
        v25.num = 0;
        v25.size = 2;
        v25.granularity = 1;
        v25.list = (encounterGroupRole_t *)&v26;
        v25.memTag = 5;
        v25.listStatic = 1;
        HIDWORD(v23) = *p_guiModel;
        idList<idAnimWebBlendTree *,5>::Append(this: &v25, obj: (const encounterGroupRole_t *)&v23);
        if ( this->IsMultiplayer(this) && this->dialogGuiModel != nullptr )
        {
          idCommonLocal::RenderDialog(this, loading: true);
          HIDWORD(v23) = this->dialogGuiModel;
          idList<idAnimWebBlendTree *,5>::Append(this: &v25, obj: (const encounterGroupRole_t *)&v23);
        }
        num = v25.num;
        list = v25.list;
        v15 = renderSystem->__vftable;
        v16 = this->RW(this);
        v17 = renderSystem->GetHeight(this: renderSystem);
        v18 = renderSystem->GetWidth(this: renderSystem);
        v19 = renderSystem->GetGameWindow(this: renderSystem);
        ((void (__fastcall *)(idRenderSystem *, void *, int, int, idRenderWorld *, encounterGroupRole_t *, int, _DWORD))v15->EndFrame)(
          a1: renderSystem,
          a2: v19,
          a3: v18,
          a4: v17,
          a5: v16,
          a6: list,
          a7: num,
          a8: 0);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v25);
        --v8;
      }
      while ( v8 != 0 );
      ((void (__fastcall *)(idCommonLocal *, int, int, int, _DWORD, double))this->UpdateLevelLoadPacifier)(
        a1: this,
        a2: v20,
        a3: 17,
        a4: 1,
        a5: 0,
        a6: 1.0);
      if ( common->IsMultiplayer(this: common) )
      {
        v21 = session->GetActingGameStateLobbyBase(this: session);
        v21->GetMatchParms(this: v21);
      }
      v22 = ((int (*)(void))session->GetTitleStorageInt_2)();
      idVirtualTextureSystem::FinishFeedback(this: &virtualTextureSystem, lockPages: false, maxWaitTimeInSeconds: v22);
      this->EndTerminationThread(this);
    }
    else
    {
      renderSystem->SyncRenderThread(this: renderSystem, a2: false);
    }
  }
}


// ========================================================================
// __unwind$225611
// EA  : 0x82657EB0
// RVA : 0x00657EB0
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void _unwind_225611()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 320 + 120));
}


// ========================================================================
// __unwind$225612
// EA  : 0x82657ED8
// RVA : 0x00657ED8
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void _unwind_225612()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 320 + 128));
}


// ========================================================================
// `idCommonLocal::StartLevelLoad'::`19'::idSWFScriptFunction_RandZeroToNMinusOneTipIndex::Call
// EA  : 0x82657F08
// RVA : 0x00657F08
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idCommonLocal::StartLevelLoad_::_19_::idSWFScriptFunction_RandZeroToNMinusOneTipIndex::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        int a4)
{
  double v6; // fp1
  __int64 v7; // r5
  long double v8; // fp2
  long double v9; // fp2
  idSWFScriptVar::swfScriptVarValue_t v10; // r30

  if ( (_S13_1 & 1) == 0 )
  {
    _S13_1 |= 1u;
    random.seed = Sys_Milliseconds();
  }
  if ( *(_DWORD *)(a4 + 4) == 1 )
  {
    v6 = idSWFScriptVar::ToFloat(this: *(idSWFScriptVar **)a4);
    LODWORD(v7) = ((1664525 * random.seed + 1013904223) >> 10) & 0x7FFF;
    random.seed = 1664525 * random.seed + 1013904223;
    *(double *)&v8 = (float)((float)((float)v7 * (float)v6) * (float)0.000030518509);
    v9 = ceil(x: v8);
    v10.i = (int)(float)((float)*(double *)&v9 - (float)1.0);
    if ( v10.i == 1 )
    {
      if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: "french") == 0 )
        goto LABEL_11;
    }
    else if ( v10.i != 13 )
    {
LABEL_10:
      if ( v10.i > 0 )
      {
LABEL_12:
        result->type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: result);
        result->value = v10;
        goto LABEL_13;
      }
LABEL_11:
      v10.i = 0;
      goto LABEL_12;
    }
    if ( idStr::Icmp(s1: sys_lang.valueString.data, s2: "italian") == 0 )
      goto LABEL_11;
    goto LABEL_10;
  }
  result->type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: result);
  result->value.i = 0;
LABEL_13:
  result->type = SWF_VAR_INTEGER;
  return result;
}


// ========================================================================
// __unwind$225699
// EA  : 0x8265805C
// RVA : 0x0065805C
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void _unwind_225699()
{
  _S13_1 &= ~1u;
}


// ========================================================================
// ?StopLevelLoad@idCommonLocal@@QAAX_N@Z
// EA  : 0x82658080
// RVA : 0x00658080
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void __fastcall idCommonLocal::StopLevelLoad(idCommonLocal *this, bool loadVirtualTextures)
{
  int *p_levelLoadInProgress; // r10
  int levelLoadInProgress; // r11
  idRenderModelGui *guiModel; // r3
  idSWF *loadingGui; // r31

  p_levelLoadInProgress = &this->levelLoadInProgress;
  levelLoadInProgress = this->levelLoadInProgress;
  if ( levelLoadInProgress > 0 )
  {
    if ( com_newLoadScreen.valueInteger != 0 )
    {
      *p_levelLoadInProgress = 0;
    }
    else
    {
      *p_levelLoadInProgress = levelLoadInProgress - 1;
      if ( levelLoadInProgress >= 2 )
      {
        if ( loadVirtualTextures )
          idCommonLocal::LoadVirtualTextures(this);
        guiModel = this->guiModel;
        if ( guiModel != nullptr )
        {
          guiModel->unlinked = true;
          guiModel->deleteOnSync = true;
          idRenderModel::CommitThisFrame(this: guiModel);
          this->guiModel = nullptr;
        }
        loadingGui = this->loadingGui;
        if ( loadingGui != nullptr )
        {
          idSWF::~idSWF(this: this->loadingGui);
          idMem::Free(this: &mem, ptr: loadingGui, align: ALIGN_16);
          this->loadingGui = nullptr;
        }
        if ( (com_editors & 0x800) != 0 )
          this->UpdateTool(this, a2: EDITOR_PARTICLE);
        renderSystem->EndAutomaticBackgroundSwaps(this: renderSystem);
      }
    }
  }
}


// ========================================================================
// ?StartLevelLoad@idCommonLocal@@QAAXABVidStr@@_N@Z
// EA  : 0x82658270
// RVA : 0x00658270
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void __fastcall idCommonLocal::StartLevelLoad(idCommonLocal *this, const idStr *mapName, const bool useVideo)
{
  int *p_levelLoadInProgress; // r30
  idRenderModelGui **p_guiModel; // r30
  idRenderModelGui *guiModel; // r3
  idRenderModelGui *v7; // r3
  idRenderModelGui *v8; // r3
  idSWF **p_loadingGui; // r23
  idSWF *loadingGui; // r30
  idSWF *v11; // r3
  idSWF *v12; // r3
  idSWF *v13; // r3
  idSWF *v14; // r30
  int v15; // r29
  int v16; // r30
  idStaticList<idLoadScreenInfo,16> *p_loadScreenInfo; // r28
  const idStr *p_varName; // r27
  idStaticList<idLoadScreenInfo,16> *v19; // r30
  _DWORD *v20; // r3
  idSWF *v21; // r11
  idSWFScriptVar::swfScriptVarValue_t v22; // r30
  int v23; // r4
  idSWFScriptVar v24; // [sp+58h] [-A8h] BYREF
  idSWFScriptVar v25[2]; // [sp+60h] [-A0h] BYREF
  idList<idLoadScreenInfo,5> v26[9]; // [sp+70h] [-90h] BYREF

  p_levelLoadInProgress = &this->levelLoadInProgress;
  this->levelLoadInProgress = 2;
  if ( com_newLoadScreen.valueInteger != 0 )
  {
    v26[0].memTag = 5;
    v26[0].listStatic = 0;
    memset(v26, 0, 14);
    idLoadScreen::LaunchLoadScreen(
      this: &loadScreen,
      loadScreenName: mapName->data,
      loadScreenInfo: (const idList<idLoadScreenInfo2,5> *)v26);
    *p_levelLoadInProgress = 1;
    idList<idKeyValue,5>::~idList<idKeyValue,5>(this: v26);
    return;
  }
  if ( useVideo )
  {
    idCVar::SetInteger(this: &swf_loadScreenAlternate, newValue: 0, force: true);
    idRenderManager::BuildGuiFrame(this: &renderManager, baseGui: nullptr, loading: true);
    idRenderManager::RenderFrameAndBeginAutomaticBackgroundSwaps(this: &renderManager);
    return;
  }
  p_guiModel = &this->guiModel;
  guiModel = this->guiModel;
  if ( guiModel != nullptr )
  {
    guiModel->unlinked = true;
    guiModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: guiModel);
    *p_guiModel = nullptr;
  }
  v7 = (idRenderModelGui *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xA410u,
                             tag: TAG_GUI_MODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
    v8 = idRenderModelGui::idRenderModelGui(this: v7);
  else
    v8 = nullptr;
  *p_guiModel = v8;
  p_loadingGui = &this->loadingGui;
  loadingGui = this->loadingGui;
  if ( loadingGui == nullptr )
    goto LABEL_13;
  if ( loadingGui->frameRate == 0 )
  {
    idSWF::~idSWF(this: this->loadingGui);
    idMem::Free(this: &mem, ptr: loadingGui, align: ALIGN_16);
LABEL_13:
    v11 = (idSWF *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                     size: 0x27Cu,
                     tag: TAG_SWF,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
    if ( v11 != nullptr )
      v12 = idSWF::idSWF(this: v11, filename_: "tungloading", soundWorld: nullptr, atlasPurgable_: true);
    else
      v12 = nullptr;
    *p_loadingGui = v12;
  }
  if ( idLib::production == PROD_BUILDING || com_production.valueInteger != 0 )
  {
    v13 = (idSWF *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                     size: 0x27Cu,
                     tag: TAG_SWF,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
    v14 = v13 != nullptr
        ? idSWF::idSWF(this: v13, filename_: "tungloading", soundWorld: nullptr, atlasPurgable_: true)
        : nullptr;
    if ( v14 != nullptr )
    {
      idSWF::~idSWF(this: v14);
      idMem::Free(this: &mem, ptr: v14, align: ALIGN_16);
    }
  }
  v15 = 0;
  if ( this->loadScreenInfo.num > 0 )
  {
    v16 = 0;
    p_loadScreenInfo = &this->loadScreenInfo;
    do
    {
      v25[0].type = SWF_VAR_UNDEF;
      p_varName = &p_loadScreenInfo->list[v16].varName;
      idSWFScriptVar::Free(this: v25);
      v25[0].type = SWF_VAR_STRING;
      v25[0].value.i = (int)idSWFScriptString::Alloc(s: p_varName + 1);
      idSWFScriptObject::Set(this: (*p_loadingGui)->globals, name: p_loadScreenInfo->list[v16].varName.data, value: v25);
      idSWFScriptVar::Free(this: v25);
      ++v15;
      ++v16;
    }
    while ( v15 < this->loadScreenInfo.num );
  }
  v19 = &this->loadScreenInfo;
  if ( this->loadScreenInfo.listStatic == 0 || this->loadScreenInfo.listStatic == 2 )
  {
    if ( v19->list != nullptr )
      idListArrayDelete<idTarget_Cvar::keyVal_t>(ptr: &v19->list->varName, num: this->loadScreenInfo.size);
    v19->list = nullptr;
    this->loadScreenInfo.size = 0;
  }
  this->loadScreenInfo.num = 0;
  v20 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
          size: 0xCu,
          tag: TAG_SWF,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  if ( v20 != nullptr )
  {
    v21 = *p_loadingGui;
    v20[1] = 0;
    v22.i = (int)v20;
    *v20 = &`idCommonLocal::StartLevelLoad'::`19'::idSWFScriptFunction_RandZeroToNMinusOneTipIndex::`vftable';
    v20[2] = v21;
  }
  else
  {
    v22.i = 0;
  }
  v24.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v24);
  if ( v22.i != 0 )
  {
    v24.value = v22;
    v24.type = SWF_VAR_FUNCTION;
    (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v22.i + 8))(a1: v22.i);
  }
  else
  {
    v24.type = SWF_VAR_NULL;
  }
  idSWFScriptObject::Set(this: (*p_loadingGui)->globals, name: "rand", value: &v24);
  idSWFScriptVar::Free(this: &v24);
  idSWF::LoadAtlasImage(this: *p_loadingGui, force: true);
  if ( this->IsMultiplayer(this) && this->dialogGuiModel != nullptr && this->dialog != nullptr )
  {
    this->ClearDialogs(this, a2: true);
    session->Pump(this: session);
    idCommonLocal::ShowNextDialog(this, waitForAtlas: true);
  }
  idSWF::Activate(this: *p_loadingGui, b: true);
  ((void (__fastcall *)(idCommonLocal *, int, int, int, _DWORD, double))this->UpdateLevelLoadPacifier)(
    a1: this,
    a2: v23,
    a3: 2,
    a4: 1,
    a5: 0,
    a6: 0.0);
}


// ========================================================================
// __unwind$225886_0
// EA  : 0x82658708
// RVA : 0x00658708
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void _unwind_225886_0()
{
  int v0; // r12

  idList<idKeyValue,5>::~idList<idKeyValue,5>(this: (idList<idLoadScreenInfo,5> *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$225887_0
// EA  : 0x82658730
// RVA : 0x00658730
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void _unwind_225887_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_GUI_MODEL);
}


// ========================================================================
// __unwind$225888
// EA  : 0x8265875C
// RVA : 0x0065875C
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void _unwind_225888()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$225889
// EA  : 0x82658788
// RVA : 0x00658788
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void _unwind_225889()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 256 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$225890
// EA  : 0x826587B4
// RVA : 0x006587B4
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void _unwind_225890()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$225892
// EA  : 0x826587DC
// RVA : 0x006587DC
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void _unwind_225892()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 88));
}


// ========================================================================
// ?SetLoadScreenInfo@idCommonLocal@@UAAXABVidStr@@0@Z
// EA  : 0x82658810
// RVA : 0x00658810
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void __fastcall idCommonLocal::SetLoadScreenInfo(idCommonLocal *this, const idStr *varName, const idStr *value)
{
  int *p_num; // r26
  int v7; // r29
  idStaticList<idLoadScreenInfo,16> *p_loadScreenInfo; // r28
  int v9; // r30
  int num; // r11
  int size; // r10
  idLoadScreenInfo *list; // r9
  idStr *p_varName; // r30
  size_t v14; // r29
  idStr *v15; // r30
  unsigned int allocedAndFlag; // r11
  size_t len; // r29
  int v18; // r4
  int v19; // r11
  bool v20; // zf
  idStr *v21; // r28
  unsigned int v22; // r11
  size_t v23; // r30
  int v24; // r4
  int v25; // r11

  p_num = &this->loadScreenInfo.num;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v7 = 0;
  if ( this->loadScreenInfo.num <= 0 )
  {
LABEL_5:
    idList<idRefMapDef,5>::PreAllocateWithGranularity(
      this: &this->loadScreenInfo,
      newSize: this->loadScreenInfo.num + 1);
    num = this->loadScreenInfo.num;
    size = this->loadScreenInfo.size;
    list = this->loadScreenInfo.list;
    if ( num >= size )
    {
      p_varName = &list[size - 1].varName;
    }
    else
    {
      p_varName = &list[num].varName;
      this->loadScreenInfo.num = num + 1;
    }
    allocedAndFlag = p_varName->allocedAndFlag;
    len = varName->len;
    v18 = varName->len + 1;
    v20 = allocedAndFlag >> 31 == 0;
    v19 = allocedAndFlag & 0x7FFFFFFF;
    if ( v20 )
    {
      if ( v18 > v19 )
        idStr::ReAllocate(this: p_varName, amount: v18, keepold: false);
    }
    else if ( v18 > v19
           && AssertFailed(
                file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                line: 463,
                expression: "amount <= GetAlloced()",
                inlineBreak: true) )
    {
      __trap();
    }
    memcpy(Dst: p_varName->data, Src: varName->data, Size: len);
    v21 = p_varName + 1;
    p_varName->data[len] = 0;
    p_varName->len = len;
    v22 = p_varName[1].allocedAndFlag;
    v23 = value->len;
    v24 = value->len + 1;
    v20 = v22 >> 31 == 0;
    v25 = v22 & 0x7FFFFFFF;
    if ( v20 )
    {
      if ( v24 > v25 )
        idStr::ReAllocate(this: v21, amount: v24, keepold: false);
    }
    else if ( v24 > v25
           && AssertFailed(
                file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                line: 463,
                expression: "amount <= GetAlloced()",
                inlineBreak: true) )
    {
      __trap();
    }
    memcpy(Dst: v21->data, Src: value->data, Size: v23);
    v21->data[v23] = 0;
    v21->len = v23;
  }
  else
  {
    p_loadScreenInfo = &this->loadScreenInfo;
    v9 = 0;
    while ( idStr::Cmp(s1: p_loadScreenInfo->list[v9].varName.data, s2: varName->data) != 0 )
    {
      ++v7;
      ++v9;
      if ( v7 >= *p_num )
        goto LABEL_5;
    }
    v15 = &p_loadScreenInfo->list[v7].varName;
    v14 = value->len;
    idStr::EnsureAlloced(this: v15 + 1, amount: value->len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v15[1].data, Src: value->data, Size: v14);
    v15[1].data[v14] = 0;
    v15[1].len = v14;
  }
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$226107
// EA  : 0x82658A44
// RVA : 0x00658A44
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void _unwind_226107()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 192 + 80));
}


// ========================================================================
// `dynamic initializer for 'com_newLoadScreen''
// EA  : 0x83339BA8
// RVA : 0x01339BA8
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_newLoadScreen__()
{
  idCVar::idCVar(
    this: &com_newLoadScreen,
    name: "com_newLoadScreen",
    value: "0",
    flags: 1,
    description: "Enable new load screen code",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_newLoadScreen__);
}


// ========================================================================
// `dynamic initializer for 'demo_overrideLoadingScreen''
// EA  : 0x83339C00
// RVA : 0x01339C00
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__demo_overrideLoadingScreen__()
{
  idCVar::idCVar(
    this: &demo_overrideLoadingScreen,
    name: "demo_overrideLoadingScreen",
    value: &byte_8200D768,
    flags: 0,
    description: "Name of the loading screen GUI to use when loading a level",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__demo_overrideLoadingScreen__);
}


// ========================================================================
// `dynamic initializer for 'swf_loadScreenAlternate''
// EA  : 0x83339C58
// RVA : 0x01339C58
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_loadScreenAlternate__()
{
  idCVar::idCVar(
    this: &swf_loadScreenAlternate,
    name: "swf_loadScreenAlternate",
    value: "0",
    flags: 2,
    description: "alternate loadscreen to use",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_loadScreenAlternate__);
}


// ========================================================================
// `dynamic initializer for 'com_vdmFinishFeedbackMaxTimeInSeconds''
// EA  : 0x83339CB0
// RVA : 0x01339CB0
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_vdmFinishFeedbackMaxTimeInSeconds__()
{
  idCVar::idCVar(
    this: &com_vdmFinishFeedbackMaxTimeInSeconds,
    name: "com_vdmFinishFeedbackMaxTimeInSeconds",
    value: "3",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_vdmFinishFeedbackMaxTimeInSeconds__);
}


// ========================================================================
// `dynamic initializer for 'com_coopFinishFeedbackMaxTimeInSeconds''
// EA  : 0x83339D08
// RVA : 0x01339D08
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_coopFinishFeedbackMaxTimeInSeconds__()
{
  idCVar::idCVar(
    this: &com_coopFinishFeedbackMaxTimeInSeconds,
    name: "com_coopFinishFeedbackMaxTimeInSeconds",
    value: "5",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_coopFinishFeedbackMaxTimeInSeconds__);
}


// ========================================================================
// `dynamic initializer for 'com_spFinishFeedbackMaxTimeInSeconds''
// EA  : 0x83339D60
// RVA : 0x01339D60
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__com_spFinishFeedbackMaxTimeInSeconds__()
{
  idCVar::idCVar(
    this: &com_spFinishFeedbackMaxTimeInSeconds,
    name: "com_spFinishFeedbackMaxTimeInSeconds",
    value: "5",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__com_spFinishFeedbackMaxTimeInSeconds__);
}


// ========================================================================
// `dynamic initializer for 'swf_connectionNumber''
// EA  : 0x83339DB8
// RVA : 0x01339DB8
// PDB : w:\tech5\engine\framework\common_loadscreen.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_connectionNumber__()
{
  idCVar::idCVar(
    this: &swf_connectionNumber,
    name: "swf_connectionNumber",
    value: "01",
    flags: 0,
    description: "Test",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_connectionNumber__);
}

