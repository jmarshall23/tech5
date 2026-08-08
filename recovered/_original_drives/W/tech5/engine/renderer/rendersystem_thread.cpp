
// ========================================================================
// ?SyncRenderThread@idRenderSystemLocal@@UAA_N_N@Z
// EA  : 0x82955D50
// RVA : 0x00955D50
// PDB : w:\tech5\engine\renderer\rendersystem_thread.cpp
// ========================================================================

int __fastcall idRenderSystemLocal::SyncRenderThread(idRenderSystemLocal *this, bool syncGPU)
{
  idRenderThread *renderThread; // r11
  idRenderThread *v6; // r8

  renderThread = this->renderThread;
  if ( renderThread == nullptr )
    return 0;
  renderThread->renderModeBeforeSync = renderThread->renderMode;
  this->renderThread->renderMode = RENDER_MODE_MANUAL;
  if ( this->renderSynced )
  {
    if ( syncGPU )
      GL_Finish();
    return 0;
  }
  idSysThread::WaitForThread(this: this->renderThread);
  v6 = this->renderThread;
  this->renderSynced = true;
  renderSystem->MakeCurrent(this: renderSystem, a2: v6->hdc);
  if ( syncGPU )
    GL_Finish();
  return 1;
}


// ========================================================================
// ?AllowBackgroundSwaps@idRenderSystemLocal@@UAAX_N@Z
// EA  : 0x82955E10
// RVA : 0x00955E10
// PDB : w:\tech5\engine\renderer\rendersystem_thread.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::AllowBackgroundSwaps(idRenderSystemLocal *this, bool allow)
{
  this->allowBackgroundSwaps = allow;
}


// ========================================================================
// ?SetLoadingIconInfo@idRenderSystemLocal@@UAAXMMMM@Z
// EA  : 0x82955E18
// RVA : 0x00955E18
// PDB : w:\tech5\engine\renderer\rendersystem_thread.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::SetLoadingIconInfo(
        idRenderSystemLocal *this,
        double posX,
        double posY,
        double scale,
        double speed)
{
  this->loadingIconPosX = posX;
  this->loadingIconPosY = posY;
  this->loadingIconScale = scale;
  this->loadingIconSpeed = speed;
}


// ========================================================================
// ?Run@idRenderThread@@UAAHXZ
// EA  : 0x82955E30
// RVA : 0x00955E30
// PDB : w:\tech5\engine\renderer\rendersystem_thread.cpp
// ========================================================================

int __fastcall idRenderThread::Run(idRenderThread *this)
{
  if ( this->initialized )
  {
    do
    {
      RD_Syncpoint(name: "idRenderThread::Run loop");
      idRenderSystemLocal::MakeCurrent(this: &tr, handle: this->hdc);
      if ( this->renderMode == RENDER_MODE_BINK
        && (unsigned __int8)idRenderSystemLocal::WaitForNextVideoFrame(this: &tr) == 0 )
      {
        this->renderMode = RENDER_MODE_MANUAL;
      }
      idRenderSystemLocal::RenderFrameInternal(
        this: &tr,
        renderMode: this->renderMode,
        hdc: this->hdc,
        skipSwapBuffers: false,
        resolveDepth: false);
      idRenderSystemLocal::MakeCurrent(this: &tr, handle: nullptr);
    }
    while ( !this->isTerminating && this->renderMode != RENDER_MODE_MANUAL );
    return 0;
  }
  else
  {
    idRenderSystemLocal::InitContext(this: &tr);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&tr);
    renderSystem->MakeCurrent(this: renderSystem, a2: nullptr);
    idRenderModelGui::StartFrame();
    this->initialized = true;
    return 0;
  }
}


// ========================================================================
// ?StartRenderThread@idRenderSystemLocal@@QAAXXZ
// EA  : 0x82955F38
// RVA : 0x00955F38
// PDB : w:\tech5\engine\renderer\rendersystem_thread.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::StartRenderThread(idRenderSystemLocal *this)
{
  idSysThread *v2; // r3
  idSysThread *v3; // r30
  idRenderThread *v4; // r3

  v2 = (idSysThread *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x48u,
                        tag: TAG_RENDERER,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v3 = v2;
  if ( v2 != nullptr )
  {
    idSysThread::idSysThread(this: v2);
    v3[1].name.len = 0;
    v4 = (idRenderThread *)v3;
    v3->__vftable = (idSysThread_vtbl *)&idRenderThread::`vftable';
    v3[1].name.data = nullptr;
    HIBYTE(v3[1].name.allocedAndFlag) = 0;
  }
  else
  {
    v4 = nullptr;
  }
  this->renderThread = v4;
  idSysThread::StartWorkerThread(
    this: v4,
    name_: "Renderer",
    core: CORE_0B,
    priority: THREAD_NORMAL,
    stackSize: 0x20000);
}


// ========================================================================
// __unwind$229081
// EA  : 0x82955FD4
// RVA : 0x00955FD4
// PDB : w:\tech5\engine\renderer\rendersystem_thread.cpp
// ========================================================================

void _unwind_229081()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_RENDERER);
}


// ========================================================================
// ?RestartRenderThread@idRenderSystemLocal@@QAAXPAX@Z
// EA  : 0x82956000
// RVA : 0x00956000
// PDB : w:\tech5\engine\renderer\rendersystem_thread.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::RestartRenderThread(idRenderSystemLocal *this, void *hdc)
{
  renderMode_t renderMode; // r11
  idSysLocal v5; // [sp+50h] [-E0h] BYREF
  int v6; // [sp+54h] [-DCh]
  int v7; // [sp+58h] [-D8h]
  float v8[6]; // [sp+70h] [-C0h] BYREF
  char v9; // [sp+88h] [-A8h]
  bool v10; // [sp+89h] [-A7h]
  _BYTE v11[64]; // [sp+90h] [-A0h] BYREF

  if ( this->renderSynced )
  {
    if ( hdc != nullptr )
      this->renderThread->hdc = hdc;
    this->renderThread->renderMode = this->renderThread->renderModeBeforeSync;
    if ( r_useSMP.valueInteger != 0 )
    {
      this->renderSynced = false;
      renderSystem->MakeCurrent(this: renderSystem, a2: nullptr);
      idSysThread::SignalWork(this: this->renderThread);
    }
    else
    {
      renderSystem->MakeCurrent(this: renderSystem, a2: hdc);
      renderMode = this->renderThread->renderMode;
      if ( renderMode != RENDER_MODE_MANUAL )
      {
        if ( renderMode == RENDER_MODE_BINK )
        {
          if ( (unsigned __int8)idRenderSystemLocal::WaitForNextVideoFrame(this: &tr) != 0 )
          {
            while ( 1 )
            {
              v8[0] = 0.0;
              v8[1] = 1.0;
              v9 = 0;
              v8[2] = 1.0;
              v8[3] = joy_pitchSpeed.valueFloat;
              v8[4] = joy_yawSpeed.valueFloat;
              v10 = in_invertLook.valueInteger != 0;
              v8[5] = m_sensitivity.valueFloat;
              usercmdGen->GetUsercmd(
                this: (idUsercmdGen *)v11,
                result: (usercmd_t *)usercmdGen,
                a3: 0,
                a4: (const inputSettings_t *)v8,
                a5: true,
                a6: 0);
              sys->GenerateEvents(this: sys);
              sys->GetEvent(this: &v5, result: (sysEvent_t *)sys);
              if ( v5.__vftable == (idSysLocal_vtbl *)1 && v7 == 0 && (v6 == 1 || v6 == 258) )
                break;
              sys->ClearEvents(this: sys);
              idRenderSystemLocal::RenderFrameInternal(
                this: &tr,
                renderMode: RENDER_MODE_BINK,
                hdc,
                skipSwapBuffers: false,
                resolveDepth: false);
              if ( (unsigned __int8)idRenderSystemLocal::WaitForNextVideoFrame(this: &tr) == 0 )
              {
                this->renderThread->renderMode = RENDER_MODE_MANUAL;
                return;
              }
            }
            sys->ClearEvents(this: sys);
          }
          this->renderThread->renderMode = RENDER_MODE_MANUAL;
        }
        else if ( renderMode == RENDER_MODE_AUTOMATIC )
        {
          idRenderSystemLocal::RenderFrameInternal(
            this: &tr,
            renderMode: RENDER_MODE_AUTOMATIC,
            hdc,
            skipSwapBuffers: false,
            resolveDepth: false);
          if ( tr.renderingIsReadyForSwapbuffers )
          {
            idRenderSystemLocal::SwapBuffers(this: &tr, hdc, forceVsync: false);
            tr.renderingIsReadyForSwapbuffers = false;
          }
        }
      }
    }
  }
  else
  {
    idLib::Printf(fmt: "RestartRenderThread called and renderer is not synced\n");
  }
}


// ========================================================================
// ?BeginAutomaticBackgroundSwaps@idRenderSystemLocal@@UAAXPAX_N@Z
// EA  : 0x829562B8
// RVA : 0x009562B8
// PDB : w:\tech5\engine\renderer\rendersystem_thread.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::BeginAutomaticBackgroundSwaps(
        idRenderSystemLocal *this,
        void *hdc,
        bool showLoadingIcon)
{
  idRenderThread *renderThread; // r9

  if ( !idLib::headless && this->allowBackgroundSwaps && this->renderThread->renderMode != RENDER_MODE_AUTOMATIC )
  {
    this->SyncRenderThread(this, a2: false);
    renderThread = this->renderThread;
    this->renderLoadingIcon = showLoadingIcon;
    this->automaticBackgroundSwapsEnabled = true;
    renderThread->renderModeBeforeSync = RENDER_MODE_AUTOMATIC;
    idRenderSystemLocal::RestartRenderThread(this, hdc);
  }
}


// ========================================================================
// ?EndAutomaticBackgroundSwaps@idRenderSystemLocal@@UAAXXZ
// EA  : 0x82956338
// RVA : 0x00956338
// PDB : w:\tech5\engine\renderer\rendersystem_thread.cpp
// ========================================================================

void __fastcall idRenderSystemLocal::EndAutomaticBackgroundSwaps(idRenderSystemLocal *this)
{
  idRenderThread *renderThread; // r9

  if ( !idLib::headless )
  {
    this->SyncRenderThread(this, a2: false);
    renderThread = this->renderThread;
    this->automaticBackgroundSwapsEnabled = false;
    this->renderLoadingIcon = false;
    renderThread->renderModeBeforeSync = RENDER_MODE_MANUAL;
  }
}

