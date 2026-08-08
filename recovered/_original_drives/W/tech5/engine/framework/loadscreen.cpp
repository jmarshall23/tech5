
// ========================================================================
// ?Run@idLoadScreenThread@@UAAHXZ
// EA  : 0x8267A1B8
// RVA : 0x0067A1B8
// PDB : w:\tech5\engine\framework\loadscreen.cpp
// ========================================================================

int __fastcall idLoadScreenThread::Run(idLoadScreenThread *this)
{
  int v3; // r30
  unsigned __int64 v4; // r6
  int v5; // r3

  if ( this->initialized )
  {
    this->isRunning = true;
    while ( !this->stopRunning )
    {
      v3 = Sys_Milliseconds();
      idRenderModelGui::Clear(this: loadScreen.guiModel, bits: v4);
      v5 = Sys_Milliseconds();
      idSWF::Render(this: loadScreen.loadingGui, gui: loadScreen.guiModel, time: v5, isSplitscreen: false);
      idRenderManager::BuildGuiFrame(this: &renderManager, baseGui: loadScreen.guiModel, loading: false);
      idRenderManager::RenderFrame(this: &renderManager);
      while ( Sys_Milliseconds() - v3 < 6 )
        mgthread_sleep(ms: 1);
    }
    this->stopRunning = false;
    this->isRunning = false;
    return 0;
  }
  else
  {
    this->initialized = true;
    return 0;
  }
}


// ========================================================================
// ?Shutdown@idLoadScreen@@QAAXXZ
// EA  : 0x8267A2A8
// RVA : 0x0067A2A8
// PDB : w:\tech5\engine\framework\loadscreen.cpp
// ========================================================================

void __fastcall idLoadScreen::Shutdown(idLoadScreen *this)
{
  idLoadScreenThread *thread; // r3

  thread = this->thread;
  if ( thread != nullptr )
    ((void (__fastcall *)(idLoadScreenThread *, int))thread->dtr_idSysThread)(a1: thread, a2: 1);
}


// ========================================================================
// ?Init@idLoadScreen@@QAAXXZ
// EA  : 0x8267A2D8
// RVA : 0x0067A2D8
// PDB : w:\tech5\engine\framework\loadscreen.cpp
// ========================================================================

void __fastcall idLoadScreen::Init(idLoadScreen *this)
{
  idSysThread *v2; // r3
  idLoadScreenThread *v3; // r30
  idLoadScreenThread *v4; // r3
  idRenderSystem_vtbl *v5; // r29
  void *v6; // r3

  v2 = (idSysThread *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 0x3Cu,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v3 = (idLoadScreenThread *)v2;
  if ( v2 != nullptr )
  {
    idSysThread::idSysThread(this: v2);
    v3->stopRunning = false;
    v4 = v3;
    v3->__vftable = (idLoadScreenThread_vtbl *)&idLoadScreenThread::`vftable';
    v3->initialized = false;
    v3->isRunning = false;
  }
  else
  {
    v4 = nullptr;
  }
  this->thread = v4;
  idSysThread::StartWorkerThread(
    this: v4,
    name_: "LoadScreen",
    core: CORE_1A,
    priority: THREAD_NORMAL,
    stackSize: 0x20000);
  if ( r_useSMP.valueInteger != 0 )
  {
    renderSystem->MakeCurrent(this: renderSystem, a2: nullptr);
    idSysThread::SignalWork(this: this->thread);
    idSysThread::WaitForThread(this: this->thread);
    v5 = renderSystem->__vftable;
    v6 = renderSystem->GetGameWindow(this: renderSystem);
    v5->MakeCurrent(this: renderSystem, a2: v6);
  }
}


// ========================================================================
// __unwind$219586
// EA  : 0x8267A3DC
// RVA : 0x0067A3DC
// PDB : w:\tech5\engine\framework\loadscreen.cpp
// ========================================================================

void __fastcall _unwind_219586(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?LevelLoadCompleted@idLoadScreen@@QAAXABUgameReturn_t@@@Z
// EA  : 0x8267A408
// RVA : 0x0067A408
// PDB : w:\tech5\engine\framework\loadscreen.cpp
// ========================================================================

void __fastcall idLoadScreen::LevelLoadCompleted(idLoadScreen *this, const gameReturn_t *gameRet)
{
  idRenderModelGui *guiModel; // r3
  idSWF *loadingGui; // r30

  idLib::Printf(fmt: "idLoadScreen::LevelLoadCompleted()\n");
  if ( r_useSMP.valueInteger != 0 )
  {
    this->thread->stopRunning = true;
    idSysThread::WaitForThread(this: this->thread);
    renderSystem->SyncRenderThread(this: renderSystem, a2: false);
  }
  guiModel = this->guiModel;
  if ( guiModel != nullptr )
    ((void (__fastcall *)(idRenderModelGui *, int))guiModel->dtr_idRenderModel)(a1: guiModel, a2: 1);
  loadingGui = this->loadingGui;
  this->guiModel = nullptr;
  if ( loadingGui != nullptr )
  {
    idSWF::~idSWF(this: loadingGui);
    idMem::Free(this: &mem, ptr: loadingGui, align: ALIGN_16);
  }
  this->loadingGui = nullptr;
}


// ========================================================================
// ?LaunchLoadScreen@idLoadScreen@@QAAXPBDABV?$idList@VidLoadScreenInfo2@@$04@@@Z
// EA  : 0x8267A4D0
// RVA : 0x0067A4D0
// PDB : w:\tech5\engine\framework\loadscreen.cpp
// ========================================================================

void __fastcall idLoadScreen::LaunchLoadScreen(
        idLoadScreen *this,
        const char *loadScreenName,
        const idList<idLoadScreenInfo2,5> *loadScreenInfo)
{
  idSWF *loadingGui; // r30
  idRenderModelGui *guiModel; // r3
  idRenderModelGui *v8; // r3
  idRenderModelGui *v9; // r3
  idSWF *v10; // r3
  idSWF *v11; // r3
  int v12; // r29
  int v13; // r30
  idLoadScreenInfo2 *v14; // r27
  unsigned __int64 v15; // r6
  int v16; // r3
  idSWFScriptVar v17[11]; // [sp+58h] [-58h] BYREF

  loadingGui = this->loadingGui;
  if ( loadingGui != nullptr )
  {
    idSWF::~idSWF(this: this->loadingGui);
    idMem::Free(this: &mem, ptr: loadingGui, align: ALIGN_16);
  }
  guiModel = this->guiModel;
  if ( guiModel != nullptr )
    ((void (__fastcall *)(idRenderModelGui *, int))guiModel->dtr_idRenderModel)(a1: guiModel, a2: 1);
  idLib::Printf(fmt: "idLoadScreen::LaunchLoadScreen( \"%s\" )\n", loadScreenName);
  v8 = (idRenderModelGui *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                             size: 0xA410u,
                             tag: TAG_NEW,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  if ( v8 != nullptr )
    v9 = idRenderModelGui::idRenderModelGui(this: v8);
  else
    v9 = nullptr;
  this->guiModel = v9;
  v10 = (idSWF *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                   size: 0x27Cu,
                   tag: TAG_SWF,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  if ( v10 != nullptr )
    v11 = idSWF::idSWF(this: v10, filename_: "loading/default", soundWorld: nullptr, atlasPurgable_: true);
  else
    v11 = nullptr;
  this->loadingGui = v11;
  v12 = 0;
  if ( loadScreenInfo->num > 0 )
  {
    v13 = 0;
    do
    {
      v17[0].type = SWF_VAR_UNDEF;
      v14 = &loadScreenInfo->list[v13];
      idSWFScriptVar::Free(this: v17);
      v17[0].type = SWF_VAR_STRING;
      v17[0].value.i = (int)idSWFScriptString::Alloc(s: &v14->value);
      idSWFScriptObject::Set(this: this->loadingGui->globals, name: loadScreenInfo->list[v13].varName.data, value: v17);
      idSWFScriptVar::Free(this: v17);
      ++v12;
      ++v13;
    }
    while ( v12 < loadScreenInfo->num );
  }
  idSWF::LoadAtlasImage(this: this->loadingGui, force: true);
  idSWF::Activate(this: this->loadingGui, b: true);
  if ( r_useSMP.valueInteger != 0 )
  {
    idSysThread::SignalWork(this: this->thread);
  }
  else
  {
    idRenderModelGui::Clear(this: loadScreen.guiModel, bits: v15);
    v16 = Sys_Milliseconds();
    idSWF::Render(this: loadScreen.loadingGui, gui: loadScreen.guiModel, time: v16, isSplitscreen: false);
    idRenderManager::BuildGuiFrame(this: &renderManager, baseGui: loadScreen.guiModel, loading: false);
    idRenderManager::RenderFrame(this: &renderManager);
  }
}


// ========================================================================
// __unwind$219866
// EA  : 0x8267A6F4
// RVA : 0x0067A6F4
// PDB : w:\tech5\engine\framework\loadscreen.cpp
// ========================================================================

void __fastcall _unwind_219866(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 176 + 80), tag: a2);
}


// ========================================================================
// __unwind$219867
// EA  : 0x8267A71C
// RVA : 0x0067A71C
// PDB : w:\tech5\engine\framework\loadscreen.cpp
// ========================================================================

void _unwind_219867()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 176 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$219868
// EA  : 0x8267A748
// RVA : 0x0067A748
// PDB : w:\tech5\engine\framework\loadscreen.cpp
// ========================================================================

void _unwind_219868()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 88));
}

