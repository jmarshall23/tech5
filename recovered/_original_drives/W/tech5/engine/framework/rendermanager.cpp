
// ========================================================================
// ?SetScreenViewDef@idRenderManager@@QAAXPBD@Z
// EA  : 0x826927E0
// RVA : 0x006927E0
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __fastcall idRenderManager::SetScreenViewDef(idRenderManager *this, const char *defName)
{
  const screenViewDef_t *v4; // r31

  if ( defName != nullptr && *defName != 0 && (v4 = screenViewDefs, "single" != nullptr) )
  {
    while ( idStr::Icmp(s1: defName, s2: v4->name) != 0 )
    {
      ++v4;
      if ( v4->name == nullptr )
        goto LABEL_6;
    }
    this->currentViewDef = v4 + 1;
  }
  else
  {
LABEL_6:
    this->currentViewDef = &screenViewDefs[1];
  }
}


// ========================================================================
// ?RenderFrame@idRenderManager@@QAAXXZ
// EA  : 0x82692860
// RVA : 0x00692860
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __fastcall idRenderManager::RenderFrame(idRenderManager *this)
{
  unsigned int v2; // r29
  idRenderSystem_vtbl *v3; // r27
  BOOL v4; // r28
  void *v5; // r3

  v2 = (unsigned int)com_editors >> 1;
  v3 = renderSystem->__vftable;
  v4 = (com_editors & 2) != 0;
  v5 = renderSystem->GetGameWindow(this: renderSystem);
  v3->RenderFrame(this: renderSystem, a2: v5, a3: &this->renderFrameInfo, a4: (v2 & 1) == 0, a5: false, a6: v4);
}


// ========================================================================
// ?SetViewDef_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x826928D0
// RVA : 0x006928D0
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __fastcall SetViewDef_f(const idCmdArgs *args)
{
  const screenViewDef_t *v1; // r31
  const char *v2; // r4

  if ( args->argc == 1 )
  {
    v1 = screenViewDefs;
    do
    {
      if ( *v1->name != 0 )
        idLib::Printf(fmt: "%s\n", v1->name);
      ++v1;
    }
    while ( v1[1].name != nullptr );
  }
  else
  {
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    idRenderManager::SetScreenViewDef(this: &renderManager, defName: v2);
  }
}


// ========================================================================
// ?ClearAllGuiModels@idRenderManager@@QAAXXZ
// EA  : 0x82692968
// RVA : 0x00692968
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __fastcall idRenderManager::ClearAllGuiModels(idRenderManager *this)
{
  idRenderModelGui *v2; // r3
  unsigned __int64 v3; // r6
  int v4; // r24
  int v5; // r30
  int v6; // r29
  int v7; // r31
  idScreenView *v8; // r11
  unsigned __int64 v9; // r6

  if ( console->Gui(this: console) != nullptr )
  {
    v2 = console->Gui(this: console);
    idRenderModelGui::Clear(this: v2, bits: v3);
  }
  v4 = 0;
  if ( this->renderFrameInfo.screenViews.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = 0;
      if ( this->renderFrameInfo.screenViews.list[v5].viewGuis.num > 0 )
      {
        v7 = 0;
        v8 = &this->renderFrameInfo.screenViews.list[v5];
        do
        {
          if ( _RTDynamicCast(
                 inptr: v8->viewGuis.list[v7],
                 VfDelta: 0,
                 SrcType: &idRenderModel `RTTI Type Descriptor',
                 TargetType: &idRenderModelGui `RTTI Type Descriptor',
                 isReference: 0) != nullptr )
            idRenderModelGui::Clear(this: (idRenderModelGui *)HIDWORD(defaultExtraGLState), bits: v9);
          ++v6;
          ++v7;
          v8 = &this->renderFrameInfo.screenViews.list[v5];
        }
        while ( v6 < v8->viewGuis.num );
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->renderFrameInfo.screenViews.num );
  }
}


// ========================================================================
// ?RenderFrameAndBeginAutomaticBackgroundSwaps@idRenderManager@@QAAXXZ
// EA  : 0x82692A68
// RVA : 0x00692A68
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __fastcall idRenderManager::RenderFrameAndBeginAutomaticBackgroundSwaps(idRenderManager *this)
{
  idRenderSystem_vtbl *v2; // r29
  void *v3; // r3
  idRenderSystem_vtbl *v4; // r31
  void *v5; // r3

  v2 = renderSystem->__vftable;
  v3 = renderSystem->GetGameWindow(this: renderSystem);
  v2->RenderFrame(this: renderSystem, a2: v3, a3: &this->renderFrameInfo, a4: false, a5: false, a6: false);
  renderSystem->SetLoadingIconInfo(
    this: renderSystem,
    a2: r_dialogIconX.valueFloat,
    a3: r_dialogIconY.valueFloat,
    a4: r_loadingIconSize.valueFloat,
    a5: r_loadingIconSpeed.valueFloat);
  v4 = renderSystem->__vftable;
  v5 = renderSystem->GetGameWindow(this: renderSystem);
  v4->BeginAutomaticBackgroundSwaps(this: renderSystem, a2: v5, a3: true);
}


// ========================================================================
// ?AddGlobalGui@idRenderManager@@AAAXPAVidRenderModelGui@@@Z
// EA  : 0x82692B30
// RVA : 0x00692B30
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __fastcall idRenderManager::AddGlobalGui(idRenderManager *this, idSpawnArea::GeneratedPosition *gui)
{
  int v4; // r27
  int v5; // r29
  int v6; // r28
  idList<idSpawnArea::GeneratedPosition *,5> *p_viewGuis; // r31
  int granularity; // r4
  int size; // r11
  bool v10; // cr58
  signed int v11; // r10
  int v12; // r4
  int v13; // r11
  int num; // r11

  if ( gui != nullptr )
  {
    v4 = 0;
    if ( this->renderFrameInfo.screenViews.num > 0 )
    {
      v5 = 0;
      v6 = 0;
      do
      {
        if ( this->currentViewDef[v6].getsGlobalGuis )
        {
          p_viewGuis = (idList<idSpawnArea::GeneratedPosition *,5> *)&this->renderFrameInfo.screenViews.list[v5].viewGuis;
          if ( p_viewGuis->list != nullptr )
            goto LABEL_9;
          granularity = this->renderFrameInfo.screenViews.list[v5].viewGuis.granularity;
          if ( granularity <= 0 )
            granularity = 1;
          if ( idList<idNavSpline *,5>::Resize(
                 this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->renderFrameInfo.screenViews.list[v5].viewGuis,
                 newsize: granularity) )
          {
LABEL_9:
            size = p_viewGuis->size;
            if ( p_viewGuis->num != size )
              goto LABEL_20;
            if ( forceIdListsToReallocateEveryAppend )
            {
              v10 = !idList<idNavSpline *,5>::Resize(this: p_viewGuis, newsize: size + 1);
            }
            else
            {
              v11 = p_viewGuis->granularity;
              if ( p_viewGuis->granularity != 0 )
              {
                v13 = size + v11;
                __twllei(v11, 0);
                __twlgei(v11 & ~(__ROL4__(v13, 1) - 1), 0xFFFFFFFF);
                v10 = !idList<idNavSpline *,5>::Resize(this: p_viewGuis, newsize: v13 - v13 % v11);
              }
              else
              {
                v12 = 2 * size;
                if ( 2 * size >= size )
                {
                  if ( v12 == 0 )
                    v12 = 1;
                  v10 = !idList<idNavSpline *,5>::Resize(this: p_viewGuis, newsize: v12);
                }
                else
                {
                  v10 = !idList<idNavSpline *,5>::Resize(this: p_viewGuis, newsize: 0x7FFFFFFF);
                }
              }
            }
            if ( !v10 )
            {
LABEL_20:
              num = p_viewGuis->num;
              if ( num < p_viewGuis->size )
              {
                p_viewGuis->list[num] = gui;
                ++p_viewGuis->num;
              }
            }
          }
        }
        ++v4;
        ++v6;
        ++v5;
      }
      while ( v4 < this->renderFrameInfo.screenViews.num );
    }
  }
}


// ========================================================================
// ?AddLocalGui@idRenderManager@@AAAXPAVidRenderModelGui@@H@Z
// EA  : 0x82692CD0
// RVA : 0x00692CD0
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __fastcall idRenderManager::AddLocalGui(idRenderManager *this, idRenderModelGui *gui, int viewIndex)
{
  int v6; // r28
  int v7; // r30
  int v8; // r29
  const screenViewDef_t *v9; // r11
  int playerNum; // r11
  idRenderModelGui *v11; // [sp+50h] [-40h] BYREF

  if ( gui != nullptr )
  {
    v6 = 0;
    if ( this->renderFrameInfo.screenViews.num > 0 )
    {
      v7 = 0;
      v8 = 0;
      do
      {
        v9 = &this->currentViewDef[v8];
        if ( v9->getsLocalGuis )
        {
          playerNum = v9->playerNum;
          if ( playerNum == viewIndex || playerNum == -1 )
          {
            v11 = gui;
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&this->renderFrameInfo.screenViews.list[v7].viewGuis,
              obj: (const encounterGroupRole_t *)&v11);
          }
        }
        ++v6;
        ++v8;
        ++v7;
      }
      while ( v6 < this->renderFrameInfo.screenViews.num );
    }
  }
}


// ========================================================================
// ?Clear@idRenderManager@@QAAXXZ
// EA  : 0x82692DD0
// RVA : 0x00692DD0
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __fastcall idRenderManager::Clear(idRenderManager *this)
{
  char *list; // r3

  if ( this->renderFrameInfo.screenViews.listStatic == 0 || this->renderFrameInfo.screenViews.listStatic == 2 )
  {
    list = (char *)this->renderFrameInfo.screenViews.list;
    if ( this->renderFrameInfo.screenViews.list != nullptr )
      idListArrayDelete<idScreenView>(ptr: list, num: this->renderFrameInfo.screenViews.size);
    this->renderFrameInfo.screenViews.list = nullptr;
    this->renderFrameInfo.screenViews.size = 0;
  }
  this->renderFrameInfo.screenViews.num = 0;
  this->renderFrameInfo.captureFrame = false;
}


// ========================================================================
// ?BuildGuiFrame@idRenderManager@@QAAXPAVidRenderModelGui@@_N@Z
// EA  : 0x82693080
// RVA : 0x00693080
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __fastcall idRenderManager::BuildGuiFrame(
        idRenderManager *this,
        idSpawnArea::GeneratedPosition *baseGui,
        bool loading)
{
  char *list; // r3
  const screenViewDef_t *currentViewDef; // r11
  int v8; // r11
  int v9; // r25
  int v10; // r26
  float *v11; // r30
  int size; // r11
  idScreenView *v13; // r31
  __int64 v14; // r9
  __int64 v15; // r6
  __int64 v16; // r3
  __int64 v17; // r9
  double v18; // fp3
  idRenderModel **v19; // r4
  int v20; // r31
  int v21; // r28
  idRenderModelGui *v22; // r3
  idSpawnArea::GeneratedPosition *v23; // r3
  int v24; // r4
  unsigned __int64 v25; // r6
  idSpawnArea::GeneratedPosition *v26; // r4

  if ( this->renderFrameInfo.screenViews.listStatic == 0 || this->renderFrameInfo.screenViews.listStatic == 2 )
  {
    list = (char *)this->renderFrameInfo.screenViews.list;
    if ( this->renderFrameInfo.screenViews.list != nullptr )
      idListArrayDelete<idScreenView>(ptr: list, num: this->renderFrameInfo.screenViews.size);
    this->renderFrameInfo.screenViews.list = nullptr;
    this->renderFrameInfo.screenViews.size = 0;
  }
  this->renderFrameInfo.screenViews.num = 0;
  this->renderFrameInfo.captureFrame = false;
  if ( renderSystem->GetScanoutHeight(this: renderSystem) == 1470 )
    idRenderManager::SetScreenViewDef(this, defName: "hdmi3d");
  if ( this->renderFrameInfo.screenViews.listStatic == 0 || this->renderFrameInfo.screenViews.listStatic == 2 )
  {
    if ( this->renderFrameInfo.screenViews.list != nullptr )
      idListArrayDelete<idScreenView>(
        ptr: (char *)this->renderFrameInfo.screenViews.list,
        num: this->renderFrameInfo.screenViews.size);
    this->renderFrameInfo.screenViews.list = nullptr;
    this->renderFrameInfo.screenViews.size = 0;
  }
  this->renderFrameInfo.captureFrame = false;
  currentViewDef = this->currentViewDef;
  this->renderFrameInfo.screenViews.num = 0;
  if ( *currentViewDef->name == 0 )
  {
    v8 = 0;
    v9 = 0;
    v10 = 1;
    do
    {
      v11 = (float *)((char *)this->currentViewDef + v8);
      if ( v10 <= this->renderFrameInfo.screenViews.size
        || (unsigned __int8)idList<idScreenView,5>::Resize(this: &this->renderFrameInfo.screenViews, newsize: v10) != 0 )
      {
        size = this->renderFrameInfo.screenViews.size;
        if ( v10 < size )
          size = v10;
        this->renderFrameInfo.screenViews.num = size;
      }
      v13 = &this->renderFrameInfo.screenViews.list[v9];
      LODWORD(v14) = renderSystem->GetScanoutWidth(this: renderSystem);
      v13->screenRect.x1 = (int)(float)((float)v14 * v11[2]);
      LODWORD(v15) = renderSystem->GetScanoutHeight(this: renderSystem);
      v13->screenRect.y1 = (int)(float)((float)v15 * v11[3]);
      LODWORD(v16) = renderSystem->GetScanoutWidth(this: renderSystem);
      v13->screenRect.x2 = (int)(float)((float)((float)v16 * (float)(v11[4] + v11[2])) - (float)1.0);
      LODWORD(v17) = renderSystem->GetScanoutHeight(this: renderSystem);
      v18 = (float)(v11[5] + v11[3]);
      v13->viewIndex = -1;
      v13->usePreviousRendering = false;
      v13->world = nullptr;
      v13->screenRect.y2 = (int)(float)((float)((float)v17 * (float)v18) - (float)1.0);
      if ( v13->viewGuis.listStatic == 0 || v13->viewGuis.listStatic == 2 )
      {
        v19 = v13->viewGuis.list;
        if ( v19 != nullptr )
          idMem::Free(this: &mem, ptr: v19, align: ALIGN_16);
        v13->viewGuis.list = nullptr;
        v13->viewGuis.size = 0;
      }
      v13->viewGuis.num = 0;
      v13->guiOriginOffset = v11[7] * stereoRender_guiOffset.valueFloat;
      ++v10;
      ++v9;
      v8 = 32 * v10 - 32;
    }
    while ( **(_BYTE **)((char *)&this->currentViewDef->name + v8) == 0 );
  }
  idRenderManager::AddGlobalGui(this, gui: baseGui);
  v20 = renderSystem->GetHeight(this: renderSystem);
  v21 = renderSystem->GetWidth(this: renderSystem);
  v22 = console->Gui(this: console);
  idRenderModelGui::SetViewport(this: v22, x: 0, y: 0, width: v21, height: v20);
  console->Draw(this: console, a2: false, a3: true);
  v23 = (idSpawnArea::GeneratedPosition *)console->Gui(this: console);
  idRenderManager::AddGlobalGui(this, gui: v23);
  LODWORD(v25) = 72592;
  if ( commonLocal.dialogGuiModel != nullptr && commonLocal.saveIndicatorGuiModel != nullptr )
  {
    idCommonLocal::RenderDialog(this: &commonLocal, loading);
    idRenderManager::AddGlobalGui(this, gui: (idSpawnArea::GeneratedPosition *)commonLocal.dialogGuiModel);
    idRenderManager::AddGlobalGui(this, gui: (idSpawnArea::GeneratedPosition *)commonLocal.saveIndicatorGuiModel);
  }
  if ( debugMenu != nullptr )
  {
    v26 = (idSpawnArea::GeneratedPosition *)((idRenderModelGui *(__fastcall *)(idDebugMenuLocal *, int, unsigned __int64))debugMenu->Render)(
                                              this: (idDebugMenuLocal *)debugMenu,
                                              a2: v24,
                                              a3: v25);
    if ( v26 != nullptr )
      idRenderManager::AddGlobalGui(this, gui: v26);
  }
  this->renderFrameInfo.captureFrame = true;
}


// ========================================================================
// ?BuildGameFrame@idRenderManager@@QAAXABUgameReturn_t@@AAVidGame@@H@Z
// EA  : 0x82693490
// RVA : 0x00693490
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __fastcall idRenderManager::BuildGameFrame(
        idRenderManager *this,
        const gameReturn_t *gameReturn,
        idGame *game,
        int frameNumber)
{
  idGame *v6; // r28
  int v7; // r27
  int v8; // r26
  _DWORD *v9; // r30
  int i; // r31
  int v11; // r3
  idRenderManager *v12; // r3
  const char *v13; // r4
  const screenViewDef_t *currentViewDef; // r11
  signed int v15; // r20
  int v16; // r11
  int v17; // r26
  int v18; // r27
  float *v19; // r30
  int size; // r11
  idScreenView *v21; // r31
  __int64 v22; // r9
  __int64 v23; // r6
  __int64 v24; // r3
  __int64 v25; // r9
  double v26; // fp3
  int v27; // r11
  idRenderMatrix *v28; // r3
  double y; // fp6
  double z; // fp5
  double v31; // fp3
  double v32; // fp2
  double valueFloat; // fp3
  int localTime; // r11
  idRenderModel **list; // r4
  int v36; // r9
  int v37; // r10
  signed int j; // ctr
  int v39; // r31
  int v40; // r26
  int *v41; // r25
  int v42; // r30
  idRenderModelGui **v43; // r28
  idScreenView *v44; // r27
  idRenderModelGui *v45; // r3
  idSpawnArea::GeneratedPosition *v46; // r3
  int v47; // r31
  int v48; // r30
  idSpawnArea::GeneratedPosition *v49; // r3
  int v50; // r30
  int v51; // r28
  idRenderModelGui *v52; // r3
  idDebugHUD_vtbl *v53; // r30
  idRenderModelGui *v54; // r3
  idLobbyBase *v55; // r3
  idLobbyBase *v56; // r3
  idLobbyBase *v57; // r28
  idLobbyBase_vtbl *v58; // r30
  idRenderModelGui *v59; // r3
  unsigned __int64 v60; // r6
  int v61; // r4
  idSpawnArea::GeneratedPosition *v62; // r3
  idSpawnArea::GeneratedPosition *v63; // r4
  int v64; // [sp+50h] [-F0h]
  idRenderWorld *v65; // [sp+54h] [-ECh]
  __int64 v66; // [sp+78h] [-C8h] BYREF
  _DWORD v67[4]; // [sp+80h] [-C0h] BYREF

  v6 = game;
  v7 = frameNumber;
  v65 = game->GetRenderWorld(this: game);
  memset(v67, 0, sizeof(v67));
  v8 = 0;
  v9 = (_DWORD *)&v66 + 1;
  v64 = 0;
  for ( i = 0; i < 4; ++i )
  {
    v11 = v6->GetPlayerIndexFromInputDevice(this: v6, a2: i);
    if ( v11 >= 0 && gameReturn->players.ptr[v11].valid )
    {
      *++v9 = v11;
      v64 = ++v8;
    }
  }
  if ( renderSystem->GetScanoutHeight(this: renderSystem) == 1470 )
  {
    v12 = this;
    if ( v8 == 2 )
      v13 = "hdmi3dTwoPlayer";
    else
      v13 = "hdmi3d";
    goto LABEL_12;
  }
  if ( v8 == 2 )
  {
    v12 = this;
    v13 = "splitscreen";
LABEL_12:
    idRenderManager::SetScreenViewDef(this: v12, defName: v13);
  }
  if ( this->renderFrameInfo.screenViews.listStatic == 0 || this->renderFrameInfo.screenViews.listStatic == 2 )
  {
    if ( this->renderFrameInfo.screenViews.list != nullptr )
      idListArrayDelete<idScreenView>(
        ptr: (char *)this->renderFrameInfo.screenViews.list,
        num: this->renderFrameInfo.screenViews.size);
    this->renderFrameInfo.screenViews.list = nullptr;
    this->renderFrameInfo.screenViews.size = 0;
  }
  currentViewDef = this->currentViewDef;
  v15 = 0;
  this->renderFrameInfo.screenViews.num = 0;
  this->renderFrameInfo.captureFrame = false;
  if ( *currentViewDef->name == 0 )
  {
    v16 = 0;
    v17 = 0;
    v18 = 1;
    do
    {
      v19 = (float *)((char *)this->currentViewDef + v16);
      if ( v18 <= this->renderFrameInfo.screenViews.size
        || (unsigned __int8)idList<idScreenView,5>::Resize(this: &this->renderFrameInfo.screenViews, newsize: v18) != 0 )
      {
        size = this->renderFrameInfo.screenViews.size;
        if ( v18 < size )
          size = v18;
        this->renderFrameInfo.screenViews.num = size;
      }
      v21 = &this->renderFrameInfo.screenViews.list[v17];
      LODWORD(v22) = renderSystem->GetScanoutWidth(this: renderSystem);
      v21->screenRect.x1 = (int)(float)((float)v22 * v19[2]);
      LODWORD(v23) = renderSystem->GetScanoutHeight(this: renderSystem);
      v21->screenRect.y1 = (int)(float)((float)v23 * v19[3]);
      LODWORD(v24) = renderSystem->GetScanoutWidth(this: renderSystem);
      v21->screenRect.x2 = (int)(float)((float)((float)v24 * (float)(v19[4] + v19[2])) - (float)1.0);
      LODWORD(v25) = renderSystem->GetScanoutHeight(this: renderSystem);
      LODWORD(v66) = v25;
      v26 = (float)(v19[5] + v19[3]);
      v21->usePreviousRendering = false;
      v21->screenRect.y2 = (int)(float)((float)((float)v25 * (float)v26) - (float)1.0);
      v27 = *((_DWORD *)v19 + 1);
      if ( v27 == -1 )
      {
        memset(Dst: &v21->g, Val: 0, Size: sizeof(v21->g));
        v21->world = nullptr;
        v21->viewIndex = 0;
      }
      else
      {
        v21->world = v65;
        v28 = (idRenderMatrix *)renderView_t::operator=(this: &v21->g, __that: &gameReturn->players.ptr[v67[v27]].view);
        if ( v19[7] != 0.0 )
        {
          y = v21->g.vieworg.y;
          z = v21->g.vieworg.z;
          v31 = (float)((float)(v21->g.viewaxis.mat[1].y * v19[7]) * stereoRender_separation.valueFloat);
          v32 = (float)((float)(v21->g.viewaxis.mat[1].z * v19[7]) * stereoRender_separation.valueFloat);
          v21->g.vieworg.x = (float)((float)(v21->g.viewaxis.mat[1].x * v19[7]) * stereoRender_separation.valueFloat)
                           + v21->g.vieworg.x;
          v21->g.vieworg.y = (float)y + (float)v31;
          v21->g.vieworg.z = (float)z + (float)v32;
          if ( v21->g.cramZNear )
            valueFloat = (float)(r_znear.valueFloat * (float)0.25);
          else
            valueFloat = r_znear.valueFloat;
          idRenderMatrix::BuildProjectionFov(
            xFovDegrees: v21->g.fov_x,
            yFovDegrees: v21->g.fov_y,
            zNear: valueFloat,
            zFar: r_zfar.valueFloat,
            xOffset: (float)(v19[7] * stereoRender_screenSeparation.valueFloat),
            yOffset: 0.0,
            out: v28);
          v21->g.useExplicitProjectionMatrix = true;
        }
        localTime = gameReturn->localTime;
        v21->viewIndex = v15++;
        v21->g.renderTime = localTime;
        v6 = game;
      }
      if ( v21->viewGuis.listStatic == 0 || v21->viewGuis.listStatic == 2 )
      {
        list = v21->viewGuis.list;
        if ( list != nullptr )
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        v21->viewGuis.list = nullptr;
        v21->viewGuis.size = 0;
      }
      v21->viewGuis.num = 0;
      v21->guiOriginOffset = v19[7] * stereoRender_guiOffset.valueFloat;
      ++v18;
      ++v17;
      v16 = 32 * v18 - 32;
    }
    while ( **(_BYTE **)((char *)&this->currentViewDef->name + v16) == 0 );
    v7 = frameNumber;
    v8 = v64;
  }
  if ( multiView_fullRender.valueInteger == 0 && v15 > 1 )
  {
    __twllei(v15, 0);
    __twlgei(v15 & ~(__ROL4__(v7, 1) - 1), 0xFFFFFFFF);
    v36 = 0;
    v37 = 0;
    for ( j = v15; j != 0; --j )
    {
      if ( v36 != v7 % v15 )
        this->renderFrameInfo.screenViews.list[v37].usePreviousRendering = true;
      ++v36;
      ++v37;
    }
  }
  v39 = 0;
  if ( v8 > 0 )
  {
    v40 = 0;
    v41 = v67;
    do
    {
      v42 = *v41;
      v43 = (idRenderModelGui **)((char *)gameReturn + 1952 * *v41);
      v44 = &this->renderFrameInfo.screenViews.list[v40];
      idRenderManager::AddLocalGui(this, gui: v43[476], viewIndex: v39);
      if ( com_skipGameRenderView.valueInteger == 0 )
      {
        v45 = game->RenderLocalViewForPlayer(this: game, a2: v42, a3: gameReturn->localTime, a4: &v44->g, a5: v65);
        idRenderManager::AddLocalGui(this, gui: v45, viewIndex: v39);
      }
      idRenderManager::AddLocalGui(this, gui: v43[477], viewIndex: v39);
      idRenderManager::AddLocalGui(this, gui: v43[478], viewIndex: v39++);
      ++v40;
      ++v41;
    }
    while ( v39 < v64 );
    v6 = game;
  }
  v46 = (idSpawnArea::GeneratedPosition *)v6->RenderLocalViewForGame(this: v6, a2: gameReturn->localTime, a3: v65);
  idRenderManager::AddGlobalGui(this, gui: v46);
  v47 = 0;
  if ( gameReturn->debugGuis.num > 0 )
  {
    v48 = 0;
    do
    {
      idRenderManager::AddGlobalGui(this, gui: (idSpawnArea::GeneratedPosition *)gameReturn->debugGuis.list[v48]);
      ++v47;
      ++v48;
    }
    while ( v47 < gameReturn->debugGuis.num );
  }
  v49 = (idSpawnArea::GeneratedPosition *)v6->Shell_Render(this: v6);
  idRenderManager::AddGlobalGui(this, gui: v49);
  if ( commonLocal.dialogGuiModel != nullptr && commonLocal.saveIndicatorGuiModel != nullptr )
  {
    idCommonLocal::RenderDialog(this: &commonLocal, loading: false);
    idRenderManager::AddGlobalGui(this, gui: (idSpawnArea::GeneratedPosition *)commonLocal.dialogGuiModel);
    idRenderManager::AddGlobalGui(this, gui: (idSpawnArea::GeneratedPosition *)commonLocal.saveIndicatorGuiModel);
  }
  console->BeginTimeRange(this: console, a2: RANGE_MAIN, a3: &idColor::colorBlack);
  v50 = renderSystem->GetHeight(this: renderSystem);
  v51 = renderSystem->GetWidth(this: renderSystem);
  v52 = console->Gui(this: console);
  idRenderModelGui::SetViewport(this: v52, x: 0, y: 0, width: v51, height: v50);
  console->Draw(this: console, a2: false, a3: (_cntlzw((unsigned int)v65) & 0x20) != 0);
  v53 = debugHUD->__vftable;
  v54 = console->Gui(this: console);
  v53->Render(this: debugHUD, a2: v54);
  v55 = session->GetActingGameStateLobbyBase(this: session);
  if ( v55->HasActivePeers(this: v55) )
    idCommonLocal::DrawSnapshotMetrics(
      this: &commonLocal,
      draw: (_cntlzw(net_drawDebugHud.valueInteger - 3) & 0x20) != 0);
  if ( net_drawDebugHud.valueInteger == 1 )
  {
    v56 = session->GetActingGameStateLobbyBase(this: session);
    if ( v56->HasActivePeers(this: v56) )
    {
      v57 = session->GetActingGameStateLobbyBase(this: session);
      v58 = v57->__vftable;
      v59 = console->Gui(this: console);
      v58->DrawDebugNetworkHUD(this: v57, a2: v59);
    }
  }
  if ( console->Gui(this: console) != nullptr )
  {
    v62 = (idSpawnArea::GeneratedPosition *)console->Gui(this: console);
    idRenderManager::AddGlobalGui(this, gui: v62);
  }
  if ( debugMenu != nullptr )
  {
    v63 = (idSpawnArea::GeneratedPosition *)((idRenderModelGui *(__fastcall *)(idDebugMenuLocal *, int, unsigned __int64))debugMenu->Render)(
                                              this: (idDebugMenuLocal *)debugMenu,
                                              a2: v61,
                                              a3: v60);
    if ( v63 != nullptr )
      idRenderManager::AddGlobalGui(this, gui: v63);
  }
}


// ========================================================================
// ?UpdateConsole@idRenderManager@@QAAXXZ
// EA  : 0x82693D70
// RVA : 0x00693D70
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __fastcall idRenderManager::UpdateConsole(idRenderManager *this)
{
  idRenderSystem_vtbl *v2; // r29
  void *v3; // r3

  idRenderManager::BuildGuiFrame(this, baseGui: nullptr, loading: false);
  v2 = renderSystem->__vftable;
  v3 = renderSystem->GetGameWindow(this: renderSystem);
  v2->RenderFrame(this: renderSystem, a2: v3, a3: &this->renderFrameInfo, a4: true, a5: false, a6: false);
}


// ========================================================================
// `dynamic initializer for 'renderManager''
// EA  : 0x8333BD58
// RVA : 0x0133BD58
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__renderManager__()
{
  `eh vector constructor iterator'(
    ptr: (char *)renderManager.renderFrameInfo.screenViews.staticList,
    size: 0x7D0u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idScreenView::idScreenView,
    pDtor: (void (__fastcall *)(void *))idScreenView::~idScreenView);
  renderManager.renderFrameInfo.captureFrame = false;
  idRenderManager::SetScreenViewDef(this: &renderManager, defName: "single");
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__renderManager__);
}


// ========================================================================
// __unwind$222919
// EA  : 0x8333BDD4
// RVA : 0x0133BDD4
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void _unwind_222919()
{
  idList<idScreenView,5>::Clear(this: &renderManager.renderFrameInfo.screenViews);
}


// ========================================================================
// __unwind$222915
// EA  : 0x8333BDFC
// RVA : 0x0133BDFC
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void _unwind_222915()
{
  idRenderFrameInfo::~idRenderFrameInfo(this: &renderManager.renderFrameInfo);
}


// ========================================================================
// `dynamic initializer for 'stereoRender_separation''
// EA  : 0x8333BE28
// RVA : 0x0133BE28
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__stereoRender_separation__()
{
  idCVar::idCVar(
    this: &stereoRender_separation,
    name: "stereoRender_separation",
    value: "3",
    flags: 4,
    description: "world units from center to eyes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__stereoRender_separation__);
}


// ========================================================================
// `dynamic initializer for 'stereoRender_screenSeparation''
// EA  : 0x8333BE80
// RVA : 0x0133BE80
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__stereoRender_screenSeparation__()
{
  idCVar::idCVar(
    this: &stereoRender_screenSeparation,
    name: "stereoRender_screenSeparation",
    value: "0.25",
    flags: 4,
    description: "screen units from center to eyes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__stereoRender_screenSeparation__);
}


// ========================================================================
// `dynamic initializer for 'stereoRender_guiOffset''
// EA  : 0x8333BED8
// RVA : 0x0133BED8
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__stereoRender_guiOffset__()
{
  idCVar::idCVar(
    this: &stereoRender_guiOffset,
    name: "stereoRender_guiOffset",
    value: "0.1",
    flags: 4,
    description: "shift guis so they don't appear at infinity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__stereoRender_guiOffset__);
}


// ========================================================================
// `dynamic initializer for 'multiView_fullRender''
// EA  : 0x8333BF30
// RVA : 0x0133BF30
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__multiView_fullRender__()
{
  idCVar::idCVar(
    this: &multiView_fullRender,
    name: "multiView_fullRender",
    value: "0",
    flags: 1,
    description: "0 = alternate frame rendering, 1 = render both each frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__multiView_fullRender__);
}


// ========================================================================
// `dynamic initializer for 'r_loadingIconSize''
// EA  : 0x8333BF88
// RVA : 0x0133BF88
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_loadingIconSize__()
{
  idCVar::idCVar(
    this: &r_loadingIconSize,
    name: "r_loadingIconSize",
    value: "0.1",
    flags: 4,
    description: "size of the loading icon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_loadingIconSize__);
}


// ========================================================================
// `dynamic initializer for 'r_loadingIconSpeed''
// EA  : 0x8333BFE0
// RVA : 0x0133BFE0
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_loadingIconSpeed__()
{
  idCVar::idCVar(
    this: &r_loadingIconSpeed,
    name: "r_loadingIconSpeed",
    value: "0.5",
    flags: 4,
    description: "rotation speed of the loading icon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_loadingIconSpeed__);
}


// ========================================================================
// `dynamic initializer for 'r_dialogIconX''
// EA  : 0x8333C038
// RVA : 0x0133C038
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_dialogIconX__()
{
  idCVar::idCVar(
    this: &r_dialogIconX,
    name: "r_dialogIconX",
    value: "0.0",
    flags: 4,
    description: "horizontal screen fraction at which the loading icon is placed",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_dialogIconX__);
}


// ========================================================================
// `dynamic initializer for 'r_dialogIconY''
// EA  : 0x8333C090
// RVA : 0x0133C090
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_dialogIconY__()
{
  idCVar::idCVar(
    this: &r_dialogIconY,
    name: "r_dialogIconY",
    value: "-0.58",
    flags: 4,
    description: "vertical screen fraction at which the loading icon is placed",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_dialogIconY__);
}


// ========================================================================
// `dynamic initializer for 'SetViewDef_v''
// EA  : 0x8333C0E8
// RVA : 0x0133C0E8
// PDB : w:\tech5\engine\framework\rendermanager.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__SetViewDef_v__()
{
  return idCommandLink::idCommandLink(
           this: &SetViewDef_v,
           cmdName: "SetViewDef",
           function: SetViewDef_f,
           description: "Sets a named screen view definition list",
           argCompletion: nullptr);
}

