
// ========================================================================
// ??0idVirtualTexturePreloadThread@@QAA@XZ
// EA  : 0x829798D0
// RVA : 0x009798D0
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

idVirtualTexturePreloadThread *__fastcall idVirtualTexturePreloadThread::idVirtualTexturePreloadThread(
        idVirtualTexturePreloadThread *this)
{
  preloadType_t *p_type; // r31
  int v3; // r29

  idSysThread::idSysThread(this);
  this->preloadCommandQueueStart = 0;
  this->preloadCommandQueueEnd = 0;
  this->endCalled = false;
  p_type = &this->preloadCommands[0].type;
  this->__vftable = (idVirtualTexturePreloadThread_vtbl *)&idVirtualTexturePreloadThread::`vftable';
  v3 = 8;
  this->currentHandle = 1;
  this->cancelToTerminate = false;
  do
  {
    memset(Dst: p_type - 1, Val: 0, Size: 0x245Cu);
    *p_type = PRELOAD_INVALID;
    *((_BYTE *)p_type + 9300) = 1;
    --v3;
    p_type += 2327;
  }
  while ( v3 != 0 );
  return this;
}


// ========================================================================
// ?DestroyThread@idVirtualTexturePreloader@@QAAXXZ
// EA  : 0x82979970
// RVA : 0x00979970
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

void __fastcall idVirtualTexturePreloader::DestroyThread(idVirtualTexturePreloader *this)
{
  idVirtualTexturePreloadThread *thread; // r3

  thread = this->thread;
  if ( thread != nullptr )
    ((void (__fastcall *)(idVirtualTexturePreloadThread *, int))thread->dtr_idSysThread)(a1: thread, a2: 1);
  this->thread = nullptr;
}


// ========================================================================
// ?AddCommand@idVirtualTexturePreloadThread@@QAAHW4preloadType_t@@PAVidVirtualTexture@@QBUpreloadMaterial_t@@HH@Z
// EA  : 0x829799E0
// RVA : 0x009799E0
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

int __fastcall idVirtualTexturePreloadThread::AddCommand(
        idVirtualTexturePreloadThread *this,
        idVirtualTexturePreloadThread_vtbl *type,
        idVirtualTexturePreloadThread_vtbl *texture,
        const preloadMaterial_t *materials,
        __int64 minLod)
{
  volatile bool *p_done; // r10
  int v7; // r11
  int result; // r3
  idVirtualTexturePreloadThread_vtbl **v9; // r11
  preloadCommand_t *v10; // r31
  int v11; // r29
  int *p_minLod; // r10
  float *v13; // r9
  double v14; // fp0
  double v15; // fp11
  __int64 v16; // r4
  idVirtualTexturePreloadThread_vtbl **v17; // r9
  int v18; // r8
  int v19; // r9
  float *v20; // r9
  double v21; // fp0
  double v22; // fp11
  __int64 v23; // r4
  idVirtualTexturePreloadThread_vtbl **v24; // r9
  int v25; // r9
  float *v26; // r9
  double v27; // fp0
  double v28; // fp11
  __int64 v29; // r4
  idVirtualTexturePreloadThread_vtbl **v30; // r9
  int v31; // fp2
  int v32; // r9
  float *v33; // r9
  double v34; // fp0
  double v35; // fp11
  __int64 v36; // r4
  idVirtualTexturePreloadThread_vtbl **v37; // r9
  int v38; // r9
  int v39; // ctr
  float *v40; // r10
  double v41; // fp0
  double v42; // fp11
  idVirtualTexturePreloadThread_vtbl **v43; // r10
  idVirtualTexturePreloadThread_vtbl *v44; // r9
  idVirtualTexturePreloadThread_vtbl *v45; // r10
  int v46; // [sp+5Ch] [-84h]
  int v47; // [sp+5Ch] [-84h]
  int v48; // [sp+64h] [-7Ch]
  int v49; // [sp+64h] [-7Ch]
  int v50; // [sp+64h] [-7Ch]
  int v51; // [sp+74h] [-6Ch]
  int v52; // [sp+74h] [-6Ch]
  int v53; // [sp+7Ch] [-64h]
  int v54; // [sp+8Ch] [-54h]

  p_done = &this->preloadCommands[0].done;
  v7 = 0;
  while ( 1 )
  {
    result = *(unsigned __int8 *)p_done;
    if ( *p_done )
      break;
    ++v7;
    p_done += 9308;
    if ( v7 >= 8 )
      return result;
  }
  v9 = (idVirtualTexturePreloadThread_vtbl **)((char *)this + 9308 * v7);
  v10 = (preloadCommand_t *)(v9 + 14);
  if ( v9 == (idVirtualTexturePreloadThread_vtbl **)-56 )
    return 0;
  v11 = 0;
  v10->handle = this->currentHandle++;
  v9[15] = type;
  v9[16] = texture;
  v9[2321] = nullptr;
  v9[2322] = (idVirtualTexturePreloadThread_vtbl *)minLod;
  if ( SHIDWORD(minLod) >= 4 )
  {
    p_minLod = &materials->minLod;
    do
    {
      v13 = (float *)(*(p_minLod - 1) + 248);
      v14 = *v13;
      v15 = *(float *)(*(p_minLod - 1) + 252);
      HIDWORD(v16) = *(_DWORD *)(*(p_minLod - 1) + 256)
                   | *(_DWORD *)(*(p_minLod - 1) + 260)
                   | *(_DWORD *)(*(p_minLod - 1) + 252);
      if ( ((HIDWORD(v16) | *(_DWORD *)v13) & 0x7FFFFFFF) != 0 )
      {
        LODWORD(v16) = texture[85].dtr_idSysThread;
        v17 = &v9[2 * (_DWORD)v9[2321] + 14];
        v46 = (int)(float)((float)v16 * *(float *)(*(p_minLod - 1) + 260));
        v48 = (int)(float)((float)v16 * *(float *)(*(p_minLod - 1) + 256));
        *((_WORD *)v17 + 6) = v48 / 120;
        *((_WORD *)v17 + 7) = v46 / 120;
        *((_WORD *)v17 + 8) = (v48 + (int)(float)((float)v16 * (float)v14)) / 120;
        *((_WORD *)v17 + 9) = (v46 + (int)(float)((float)v16 * (float)v15)) / 120;
        *((_BYTE *)&v9[2321][1025].Run + (_DWORD)(v9 + 14)) = *p_minLod;
        v18 = (int)v9[2322];
        v9[2321] = (idVirtualTexturePreloadThread_vtbl *)((char *)v9[2321] + 1);
        v19 = *p_minLod;
        if ( v18 < *p_minLod )
          v19 = v18;
        v9[2322] = (idVirtualTexturePreloadThread_vtbl *)v19;
      }
      v20 = (float *)(p_minLod[1] + 248);
      v21 = *v20;
      v22 = *(float *)(p_minLod[1] + 252);
      HIDWORD(v23) = *(_DWORD *)(p_minLod[1] + 256) | *(_DWORD *)(p_minLod[1] + 260) | *(_DWORD *)(p_minLod[1] + 252);
      if ( ((HIDWORD(v23) | *(_DWORD *)v20) & 0x7FFFFFFF) != 0 )
      {
        LODWORD(v23) = texture[85].dtr_idSysThread;
        v24 = &v9[2 * (_DWORD)v9[2321] + 14];
        v47 = (int)(float)((float)v23 * *(float *)(p_minLod[1] + 260));
        v49 = (int)(float)((float)v23 * *(float *)(p_minLod[1] + 256));
        *((_WORD *)v24 + 6) = v49 / 120;
        *((_WORD *)v24 + 7) = v47 / 120;
        *((_WORD *)v24 + 8) = (v49 + (int)(float)((float)v23 * (float)v21)) / 120;
        *((_WORD *)v24 + 9) = (v47 + (int)(float)((float)v23 * (float)v22)) / 120;
        *((_BYTE *)&v9[2321][1025].Run + (_DWORD)(v9 + 14)) = p_minLod[2];
        v25 = (int)v9[2322];
        v9[2321] = (idVirtualTexturePreloadThread_vtbl *)((char *)v9[2321] + 1);
        if ( v25 >= p_minLod[2] )
          v25 = p_minLod[2];
        v9[2322] = (idVirtualTexturePreloadThread_vtbl *)v25;
      }
      v26 = (float *)(p_minLod[3] + 248);
      v27 = *v26;
      v28 = *(float *)(p_minLod[3] + 252);
      HIDWORD(v29) = *(_DWORD *)(p_minLod[3] + 256) | *(_DWORD *)(p_minLod[3] + 260) | *(_DWORD *)(p_minLod[3] + 252);
      if ( ((HIDWORD(v29) | *(_DWORD *)v26) & 0x7FFFFFFF) != 0 )
      {
        LODWORD(v29) = texture[85].dtr_idSysThread;
        v30 = &v9[2 * (_DWORD)v9[2321] + 14];
        v31 = (int)(float)((float)v29 * *(float *)(p_minLod[3] + 260));
        v51 = (int)(float)((float)v29 * *(float *)(p_minLod[3] + 256));
        *((_WORD *)v30 + 6) = v51 / 120;
        *((_WORD *)v30 + 7) = v31 / 120;
        *((_WORD *)v30 + 8) = (v51 + (int)(float)((float)v29 * (float)v27)) / 120;
        *((_WORD *)v30 + 9) = (v31 + (int)(float)((float)v29 * (float)v28)) / 120;
        *((_BYTE *)&v9[2321][1025].Run + (_DWORD)(v9 + 14)) = p_minLod[4];
        v32 = (int)v9[2322];
        v9[2321] = (idVirtualTexturePreloadThread_vtbl *)((char *)v9[2321] + 1);
        if ( v32 >= p_minLod[4] )
          v32 = p_minLod[4];
        v9[2322] = (idVirtualTexturePreloadThread_vtbl *)v32;
      }
      v33 = (float *)(p_minLod[5] + 248);
      v34 = *v33;
      v35 = *(float *)(p_minLod[5] + 252);
      HIDWORD(v36) = *(_DWORD *)(p_minLod[5] + 256) | *(_DWORD *)(p_minLod[5] + 260) | *(_DWORD *)(p_minLod[5] + 252);
      if ( ((HIDWORD(v36) | *(_DWORD *)v33) & 0x7FFFFFFF) != 0 )
      {
        LODWORD(v36) = texture[85].dtr_idSysThread;
        v37 = &v9[2 * (_DWORD)v9[2321] + 14];
        v50 = (int)(float)((float)v36 * *(float *)(p_minLod[5] + 256));
        v54 = (int)(float)((float)v36 * *(float *)(p_minLod[5] + 260));
        *((_WORD *)v37 + 6) = v50 / 120;
        *((_WORD *)v37 + 7) = v54 / 120;
        *((_WORD *)v37 + 8) = (v50 + (int)(float)((float)v36 * (float)v34)) / 120;
        *((_WORD *)v37 + 9) = (v54 + (int)(float)((float)v36 * (float)v35)) / 120;
        *((_BYTE *)&v9[2321][1025].Run + (_DWORD)(v9 + 14)) = p_minLod[6];
        v9[2321] = (idVirtualTexturePreloadThread_vtbl *)((char *)v9[2321] + 1);
        v38 = (int)v9[2322];
        if ( v38 >= p_minLod[6] )
          v38 = p_minLod[6];
        v9[2322] = (idVirtualTexturePreloadThread_vtbl *)v38;
      }
      v11 += 4;
      p_minLod += 8;
    }
    while ( v11 < HIDWORD(minLod) - 3 );
  }
  if ( v11 < SHIDWORD(minLod) )
  {
    v39 = HIDWORD(minLod) - v11;
    HIDWORD(minLod) = &materials[v11].minLod;
    do
    {
      v40 = (float *)(*(_DWORD *)(HIDWORD(minLod) - 4) + 248);
      v41 = *v40;
      v42 = *(float *)(*(_DWORD *)(HIDWORD(minLod) - 4) + 252);
      if ( ((*(_DWORD *)(*(_DWORD *)(HIDWORD(minLod) - 4) + 256)
           | *(_DWORD *)(*(_DWORD *)(HIDWORD(minLod) - 4) + 260)
           | *(_DWORD *)(*(_DWORD *)(HIDWORD(minLod) - 4) + 252)
           | *(_DWORD *)v40)
          & 0x7FFFFFFF) != 0 )
      {
        LODWORD(minLod) = texture[85].dtr_idSysThread;
        v43 = &v9[2 * (_DWORD)v9[2321] + 14];
        v53 = (int)(float)((float)minLod * *(float *)(*(_DWORD *)(HIDWORD(minLod) - 4) + 256));
        v52 = (int)(float)((float)minLod * *(float *)(*(_DWORD *)(HIDWORD(minLod) - 4) + 260));
        *((_WORD *)v43 + 7) = v52 / 120;
        *((_WORD *)v43 + 9) = (v52 + (int)(float)((float)minLod * (float)v42)) / 120;
        *((_WORD *)v43 + 6) = v53 / 120;
        *((_WORD *)v43 + 8) = (v53 + (int)(float)((float)minLod * (float)v41)) / 120;
        *((_BYTE *)&v9[2321][1025].Run + (_DWORD)(v9 + 14)) = *(_DWORD *)HIDWORD(minLod);
        v44 = v9[2322];
        v9[2321] = (idVirtualTexturePreloadThread_vtbl *)((char *)v9[2321] + 1);
        v45 = *(idVirtualTexturePreloadThread_vtbl **)HIDWORD(minLod);
        if ( (int)v44 < *(_DWORD *)HIDWORD(minLod) )
          v45 = v44;
        v9[2322] = v45;
      }
      HIDWORD(minLod) += 8;
      --v39;
    }
    while ( v39 != 0 );
  }
  v9[2323] = nullptr;
  memset(Dst: v9 + 2324, Val: 0, Size: 0x40u);
  v10->done = false;
  this->preloadCommandQueue[this->preloadCommandQueueEnd] = v10;
  this->preloadCommandQueueEnd = (this->preloadCommandQueueEnd + 1) & 0xF;
  idSysThread::SignalWork(this);
  return this->currentHandle - 1;
}


// ========================================================================
// ?PrintCommandResult@idVirtualTexturePreloadThread@@ABAXABUpreloadCommand_t@@@Z
// EA  : 0x8297A010
// RVA : 0x0097A010
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

void __fastcall idVirtualTexturePreloadThread::PrintCommandResult(
        idVirtualTexturePreloadThread *this,
        const preloadCommand_t *cmd,
        int a3,
        int a4,
        __int64 a5)
{
  const char *v6; // r5
  double v7; // r4
  int *v8; // r30
  char **p_data; // r31

  if ( cmd->type == PRELOAD_ALL )
    v6 = "PRELOAD_ALL";
  else
    v6 = "PRELOAD_MATERIAL_LIST";
  LODWORD(a5) = cmd->totalTimeMSec;
  v7 = (float)((float)a5 * (float)0.001);
  idLib::Printf(fmt: (const char *)HIDWORD(v7), LODWORD(v7), v6);
  v8 = &cmd->pagesLoaded[1];
  p_data = &virtualTextureSystem.vts[1].baseName.data;
  do
  {
    if ( p_data[73] != nullptr && *v8 != 0 )
      idLib::Printf(fmt: "%4i pages preloaded on %s\n", *v8, *p_data);
    p_data += 312;
    ++v8;
  }
  while ( (int)p_data < (int)&virtualTextureSystem.referencedVTPath[1][28] );
}


// ========================================================================
// ?StopPreloading@idVirtualTexturePreloadThread@@QAAXXZ
// EA  : 0x8297A0D0
// RVA : 0x0097A0D0
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

void __fastcall idVirtualTexturePreloadThread::StopPreloading(idVirtualTexturePreloadThread *this)
{
  volatile bool *p_endCalled; // r30
  __int64 v3; // r10
  preloadType_t *p_type; // r29
  int i; // r23
  const char *v6; // r5
  double v7; // r4
  _DWORD *v8; // r30
  char **p_data; // r31

  p_endCalled = &this->endCalled;
  this->endCalled = true;
  idSysThread::WaitForThread(this);
  HIDWORD(v3) = "olor specular";
  *p_endCalled = false;
  p_type = &this->preloadCommands[0].type;
  for ( i = 8; i != 0; --i )
  {
    if ( *p_type != PRELOAD_INVALID )
    {
      v6 = "PRELOAD_ALL";
      if ( *p_type != PRELOAD_ALL )
        v6 = "PRELOAD_MATERIAL_LIST";
      SLODWORD(v3) = p_type[2308];
      v7 = (float)((float)v3 * (float)0.001);
      idLib::Printf(fmt: (const char *)HIDWORD(v7), LODWORD(v7), v6);
      v8 = p_type + 2310;
      p_data = &virtualTextureSystem.vts[1].baseName.data;
      do
      {
        if ( p_data[73] != nullptr && *v8 != 0 )
          idLib::Printf(fmt: "%4i pages preloaded on %s\n", *v8, *p_data);
        p_data += 312;
        ++v8;
      }
      while ( (int)p_data < (int)&virtualTextureSystem.referencedVTPath[1][28] );
      *p_type = PRELOAD_INVALID;
    }
    p_type += 2327;
  }
}


// ========================================================================
// ?SpawnThread@idVirtualTexturePreloader@@QAAXXZ
// EA  : 0x8297A1E8
// RVA : 0x0097A1E8
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

void __fastcall idVirtualTexturePreloader::SpawnThread(idVirtualTexturePreloader *this)
{
  idVirtualTexturePreloadThread *v2; // r3
  idVirtualTexturePreloadThread *v3; // r3

  v2 = (idVirtualTexturePreloadThread *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                          size: 0x12368u,
                                          tag: TAG_RENDERER,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idVirtualTexturePreloadThread::idVirtualTexturePreloadThread(this: v2);
  else
    v3 = nullptr;
  this->thread = v3;
  idSysThread::StartWorkerThread(
    this: v3,
    name_: "VirtualTexturePreloader",
    core: CORE_1A,
    priority: THREAD_NORMAL,
    stackSize: 0x20000);
}


// ========================================================================
// __unwind$222930_0
// EA  : 0x8297A27C
// RVA : 0x0097A27C
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

void _unwind_222930_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_RENDERER);
}


// ========================================================================
// ?BeginPreloading@idVirtualTexturePreloader@@QAAXXZ
// EA  : 0x8297A2A8
// RVA : 0x0097A2A8
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

void __fastcall idVirtualTexturePreloader::BeginPreloading(idVirtualTexturePreloader *this)
{
  idLib::Printf(fmt: "idVirtualTexturePreloader::BeginPreloading(): signaling background thread to start\n");
  idVirtualTexturePreloadThread::AddCommand(
    this: this->thread,
    type: (idVirtualTexturePreloadThread_vtbl *)1,
    texture: nullptr,
    materials: nullptr,
    minLod: 0);
  this->running = true;
}


// ========================================================================
// ?EndPreloading@idVirtualTexturePreloader@@QAAXXZ
// EA  : 0x8297A300
// RVA : 0x0097A300
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

void __fastcall idVirtualTexturePreloader::EndPreloading(idVirtualTexturePreloader *this)
{
  if ( this->thread != nullptr && this->running )
  {
    idLib::Printf(fmt: "================================================\n");
    idLib::Printf(fmt: "idVirtualTexturePreloader::EndPreloading(): signaling background thread to stop\n");
    idVirtualTexturePreloadThread::StopPreloading(this: this->thread);
    this->running = false;
  }
}


// ========================================================================
// FindLayer
// EA  : 0x8297A368
// RVA : 0x0097A368
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

int __fastcall FindLayer(const idStaticList<idStrStatic<128>,256> *const layers, const char *layerName)
{
  int v4; // r30
  int v5; // r27
  int i; // r31

  if ( layers == nullptr )
    return 0;
  v4 = 0;
  if ( *layerName != 0 )
  {
    do
      ++v4;
    while ( layerName[v4] != 0 );
  }
  v5 = 0;
  if ( layers->num <= 0 )
    return 0;
  for ( i = 0; idStr::Icmpn(s1: layers->list[i].data, s2: layerName, n: v4) != 0; ++i )
  {
    if ( ++v5 >= layers->num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?PreloadIsDone@idVirtualTexturePreloadThread@@QAA_NH@Z
// EA  : 0x8297A408
// RVA : 0x0097A408
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

int __fastcall idVirtualTexturePreloadThread::PreloadIsDone(
        idVirtualTexturePreloadThread *this,
        int handle,
        int a3,
        int a4,
        __int64 a5)
{
  int v5; // r11
  preloadCommand_t *i; // r31

  if ( handle == 0 )
    return 1;
  v5 = 0;
  for ( i = this->preloadCommands; i->handle != handle; ++i )
  {
    if ( ++v5 >= 8 )
      return 1;
  }
  if ( i->done )
    idVirtualTexturePreloadThread::PrintCommandResult(this, cmd: i, a3, a4, a5);
  return i->done;
}


// ========================================================================
// ?MaterialPreloadIsDone@idVirtualTexturePreloader@@QAA_NH@Z
// EA  : 0x8297A488
// RVA : 0x0097A488
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

int __fastcall idVirtualTexturePreloader::MaterialPreloadIsDone(
        idVirtualTexturePreloader *this,
        int handle,
        int a3,
        int a4,
        __int64 a5)
{
  return idVirtualTexturePreloadThread::PreloadIsDone(this: this->thread, handle, a3, a4, a5);
}


// ========================================================================
// AddPreloadMaterials
// EA  : 0x8297A490
// RVA : 0x0097A490
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

void __fastcall AddPreloadMaterials(
        preloadMaterial_t *preloadMaterials,
        int *numPreloadMaterials,
        const char **materialNames,
        int minLod)
{
  const char **v7; // r29
  const idMaterial *v8; // r3

  if ( *materialNames != nullptr )
  {
    v7 = materialNames;
    do
    {
      if ( *numPreloadMaterials >= 1024 )
        break;
      if ( *v7 != nullptr
        && (v8 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                                       this: &idMaterial::resourceList,
                                       name: *v7,
                                       makeDefault: false)) != nullptr )
      {
        preloadMaterials[*numPreloadMaterials].material = v8;
        preloadMaterials[(*numPreloadMaterials)++].minLod = minLod;
      }
      else
      {
        idLib::Printf(fmt: "material %s not found\n", *v7);
      }
      ++v7;
    }
    while ( *v7 != nullptr );
  }
}


// ========================================================================
// ?PreloadVMTRsForMap@idVirtualTexturePreloader@@QAAHQBDQBV?$idStaticList@V?$idStrStatic@$0IA@@@$0BAA@@@PBD@Z
// EA  : 0x8297A540
// RVA : 0x0097A540
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

int __fastcall idVirtualTexturePreloader::PreloadVMTRsForMap(
        idVirtualTexturePreloader *this,
        const char *mapName,
        const idStaticList<idStrStatic<128>,256> *const layers,
        const char *spawnSpot)
{
  int v8; // r6
  const char **v9; // r5
  char Layer; // r3
  char v11; // r3
  __int64 v12; // r8
  int v14[4]; // [sp+50h] [-2040h] BYREF
  preloadMaterial_t v15[6]; // [sp+60h] [-2030h] BYREF

  v14[0] = 0;
  if ( idStr::Icmp(s1: mapName, s2: "game/wasteland1/wasteland1") == 0 )
  {
    if ( (unsigned __int8)FindLayer(layers, layerName: "lay/job/wl1/intro") != 0 )
    {
      AddPreloadMaterials(
        preloadMaterials: v15,
        numPreloadMaterials: v14,
        materialNames: materialNames_InventoryIcons,
        minLod: 0);
      AddPreloadMaterials(
        preloadMaterials: v15,
        numPreloadMaterials: v14,
        materialNames: materialNames_ArkDoor,
        minLod: 0);
      v8 = 0;
      v9 = materialNames_CharacterGhost1;
LABEL_14:
      AddPreloadMaterials(preloadMaterials: v15, numPreloadMaterials: v14, materialNames: v9, minLod: v8);
      goto LABEL_15;
    }
    if ( (unsigned __int8)FindLayer(layers, layerName: "layer/race/") == 0
      && (unsigned __int8)FindLayer(layers, layerName: "lay/veh/dyn/Stanley/") != 0 )
    {
      Layer = FindLayer(layers, layerName: "lay/job/wl1/always");
      v8 = 0;
      v9 = materialNames_InventoryIcons;
      if ( Layer == 0 )
      {
        AddPreloadMaterials(
          preloadMaterials: v15,
          numPreloadMaterials: v14,
          materialNames: materialNames_InventoryIcons,
          minLod: 0);
        AddPreloadMaterials(
          preloadMaterials: v15,
          numPreloadMaterials: v14,
          materialNames: materialNames_WeaponsPlayer,
          minLod: 1);
        v8 = 0;
        v9 = materialNames_CharacterDan;
      }
      goto LABEL_14;
    }
    goto LABEL_15;
  }
  if ( idStr::Icmp(s1: mapName, s2: "game/wasteland2/wasteland2") != 0 )
  {
    if ( idStr::Icmp(s1: mapName, s2: "game/tracks/dusty8") == 0
      || idStr::Icmp(s1: mapName, s2: "game/online/online_meteor") == 0
      || idStr::Icmp(s1: mapName, s2: "game/online/online_prime") == 0
      || idStr::Icmp(s1: mapName, s2: "game/online/online_abandoned") == 0
      || idStr::Icmp(s1: mapName, s2: "game/online/online_haggar") == 0
      || idStr::Icmp(s1: mapName, s2: "game/online/online_triangleland") == 0
      || idStr::Icmp(s1: mapName, s2: "game/online/online_gearhead_valley") == 0 )
    {
      goto LABEL_15;
    }
    if ( idStr::Icmp(s1: mapName, s2: "game/wasteland1/ghost_hideout") == 0 )
    {
      AddPreloadMaterials(
        preloadMaterials: v15,
        numPreloadMaterials: v14,
        materialNames: materialNames_InventoryIcons,
        minLod: 0);
      AddPreloadMaterials(
        preloadMaterials: v15,
        numPreloadMaterials: v14,
        materialNames: materialNames_WeaponsPlayer,
        minLod: 1);
      if ( (unsigned __int8)FindLayer(layers, layerName: "lay/job/ghost/threat") != 0 )
        goto LABEL_15;
      v8 = 0;
      v9 = materialNames_CharacterGhostHideoutDeadGuy;
      goto LABEL_14;
    }
    if ( idStr::Icmp(s1: mapName, s2: "game/wasteland1/wellspring") == 0 )
    {
      AddPreloadMaterials(
        preloadMaterials: v15,
        numPreloadMaterials: v14,
        materialNames: materialNames_InventoryIcons,
        minLod: 0);
      if ( idStr::Icmp(s1: spawnSpot, s2: "player_start_vehicle") != 0 )
        goto LABEL_15;
      AddPreloadMaterials(
        preloadMaterials: v15,
        numPreloadMaterials: v14,
        materialNames: materialNames_CharacterSally,
        minLod: 0);
      AddPreloadMaterials(
        preloadMaterials: v15,
        numPreloadMaterials: v14,
        materialNames: materialNames_StanleyExpress,
        minLod: 0);
      AddPreloadMaterials(
        preloadMaterials: v15,
        numPreloadMaterials: v14,
        materialNames: materialNames_VencorIcons,
        minLod: 0);
      v8 = 0;
      v9 = materialNames_GarageExit;
      goto LABEL_14;
    }
    if ( idStr::Icmp(s1: mapName, s2: "game/wasteland2/subway_town") == 0 )
    {
      AddPreloadMaterials(
        preloadMaterials: v15,
        numPreloadMaterials: v14,
        materialNames: materialNames_InventoryIcons,
        minLod: 0);
      if ( idStr::Icmp(s1: spawnSpot, s2: "player_start_vehicle") != 0 )
        goto LABEL_15;
      AddPreloadMaterials(
        preloadMaterials: v15,
        numPreloadMaterials: v14,
        materialNames: materialNames_VencorIcons,
        minLod: 0);
      v8 = 0;
      v9 = materialNames_GarageExit;
      goto LABEL_14;
    }
    if ( idStr::Icmp(s1: mapName, s2: "game/wasteland1/dam_facility") == 0 )
    {
      AddPreloadMaterials(
        preloadMaterials: v15,
        numPreloadMaterials: v14,
        materialNames: materialNames_InventoryIcons,
        minLod: 0);
      AddPreloadMaterials(
        preloadMaterials: v15,
        numPreloadMaterials: v14,
        materialNames: materialNames_WeaponsPlayer,
        minLod: 1);
      FindLayer(layers, layerName: "lay/job/dam/parts");
      goto LABEL_15;
    }
    if ( idStr::Icmp(s1: mapName, s2: "game/wasteland1/bash_tv") == 0 )
    {
      AddPreloadMaterials(
        preloadMaterials: v15,
        numPreloadMaterials: v14,
        materialNames: materialNames_InventoryIcons,
        minLod: 0);
      AddPreloadMaterials(
        preloadMaterials: v15,
        numPreloadMaterials: v14,
        materialNames: materialNames_WeaponsPlayer,
        minLod: 1);
      if ( (unsigned __int8)FindLayer(layers, layerName: "lay/job/bash/ep1") != 0 )
        goto LABEL_15;
      v8 = 0;
      v9 = materialNames_BashTVMutantTorso;
      goto LABEL_14;
    }
LABEL_13:
    AddPreloadMaterials(
      preloadMaterials: v15,
      numPreloadMaterials: v14,
      materialNames: materialNames_InventoryIcons,
      minLod: 0);
    v8 = 1;
    v9 = materialNames_WeaponsPlayer;
    goto LABEL_14;
  }
  if ( idStr::Icmp(s1: spawnSpot, s2: "qst_player_start_airship") == 0 )
  {
    v8 = 0;
    v9 = materialNames_CharacterMarshall;
    goto LABEL_14;
  }
  if ( (unsigned __int8)FindLayer(layers, layerName: "layer/race/") == 0 )
  {
    v11 = FindLayer(layers, layerName: "lay/job/wl2/always");
    v8 = 0;
    v9 = materialNames_InventoryIcons;
    if ( v11 == 0 )
      goto LABEL_14;
    goto LABEL_13;
  }
LABEL_15:
  LODWORD(v12) = 16;
  HIDWORD(v12) = v14[0];
  return idVirtualTexturePreloadThread::AddCommand(
           this: this->thread,
           type: (idVirtualTexturePreloadThread_vtbl *)2,
           texture: (idVirtualTexturePreloadThread_vtbl *)virtualTextureSystem.vmtrMega,
           materials: v15,
           minLod: v12);
}


// ========================================================================
// ?testPreloader_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x8297AA48
// RVA : 0x0097AA48
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

void __fastcall testPreloader_f(const idCmdArgs *args)
{
  const char *v2; // r3
  bool IsNumeric; // r3
  int argc; // r11
  const char *v5; // r3
  int v6; // r31
  int v7; // r30
  bool v8; // zf
  const char *v9; // r3
  const char **v10; // r5
  __int64 v11; // r8
  int v12; // r30
  __int64 v13; // r8
  int v14; // r6
  int v15; // r5
  __int64 v16; // r8
  int v17; // r6
  int v18; // r5
  int v19; // [sp+50h] [-2040h] BYREF
  _DWORD v20[2]; // [sp+58h] [-2038h] BYREF
  preloadMaterial_t v21[6]; // [sp+60h] [-2030h] BYREF

  if ( args->argc >= 2 )
  {
    idStreamFileCache::ClearMem(this: streamFileCache, releaseProvidedMemory: false);
    idStreamFileCache::ClearHDC(this: streamFileCache);
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    IsNumeric = idStr::IsNumeric(s: v2);
    argc = args->argc;
    if ( IsNumeric )
    {
      if ( argc <= 1 )
        v5 = &byte_8200D768;
      else
        v5 = args->argv[1];
      v6 = atol(nptr: v5);
      idVirtualTexturePreloader::BeginPreloading(this: &virtualTexturePreloader);
      mgthread_sleep(ms: 1000 * v6);
      idVirtualTexturePreloader::EndPreloading(this: &virtualTexturePreloader);
      idStreamFileCache::Stats(this: streamFileCache);
    }
    else
    {
      v7 = 0;
      if ( argc >= 3 )
        v7 = atol(nptr: args->argv[2]);
      v8 = args->argc <= 1;
      v19 = 0;
      if ( v8 )
        v9 = &byte_8200D768;
      else
        v9 = args->argv[1];
      if ( idStr::Icmp(s1: v9, s2: "inventory") != 0 )
      {
        if ( args->argc <= 1 )
          v20[0] = &byte_8200D768;
        else
          v20[0] = args->argv[1];
        v20[1] = 0;
        v10 = (const char **)v20;
      }
      else
      {
        v10 = materialNames_InventoryIcons;
      }
      AddPreloadMaterials(preloadMaterials: v21, numPreloadMaterials: &v19, materialNames: v10, minLod: v7);
      HIDWORD(v11) = v19;
      LODWORD(v11) = 16;
      v12 = idVirtualTexturePreloadThread::AddCommand(
              this: virtualTexturePreloader.thread,
              type: (idVirtualTexturePreloadThread_vtbl *)2,
              texture: (idVirtualTexturePreloadThread_vtbl *)virtualTextureSystem.vmtrMega,
              materials: v21,
              minLod: v11);
      if ( (unsigned __int8)idVirtualTexturePreloadThread::PreloadIsDone(
                              this: virtualTexturePreloader.thread,
                              handle: v12,
                              a3: v15,
                              a4: v14,
                              a5: v13) == 0 )
      {
        do
          mgthread_sleep(ms: 100);
        while ( (unsigned __int8)idVirtualTexturePreloadThread::PreloadIsDone(
                                   this: virtualTexturePreloader.thread,
                                   handle: v12,
                                   a3: v18,
                                   a4: v17,
                                   a5: v16) == 0 );
      }
      idStreamFileCache::Stats(this: streamFileCache);
    }
  }
  else
  {
    idLib::Printf(fmt: "testPreloader <seconds | material>");
  }
}


// ========================================================================
// ?Run@idVirtualTexturePreloadThread@@UAAHXZ
// EA  : 0x8297AD20
// RVA : 0x0097AD20
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

int __fastcall idVirtualTexturePreloadThread::Run(idVirtualTexturePreloadThread *this)
{
  volatile int *p_preloadCommandQueueStart; // r14
  volatile bool *p_endCalled; // r29
  preloadCommand_t *v3; // r23
  idVirtualTexture **v4; // r22
  int v5; // r20
  int v6; // r24
  preloadType_t type; // r11
  signed int v8; // r17
  unsigned __int16 *finerDiskLength; // r25
  _DWORD *v10; // r27
  unsigned __int16 *v11; // r30
  char v12; // r26
  int v13; // r28
  idVirtualTexture **v14; // r29
  idVirtualTexture **v15; // r11
  int v16; // r3
  int v17; // r9
  int v18; // r26
  idVirtualTexture *texture; // r11
  int v20; // r10
  int v21; // r9
  int v22; // r27
  int v23; // r9
  idVirtualTexture **v24; // r30
  _DWORD *v25; // r8
  signed int i; // ctr
  int v27; // r10
  __int64 v28; // r11
  idStreamControlThread_vtbl *v29; // r9
  __int64 v30; // r5
  __int128 v31; // r6
  int v32; // r11
  int minLod; // r11
  int v34; // r3
  unsigned __int16 *v35; // r29
  unsigned int *finerDiskOffset; // r28
  int v37; // r7
  int v38; // r6
  int v39; // r9
  char v40; // r5
  int v41; // r8
  unsigned __int16 *p_x2; // r11
  idVirtualTexture **v43; // r11
  int v44; // r10
  int v45; // r11
  idVirtualTexture **v46; // r8
  int v47; // r3
  int v49; // [sp+8h] [-1D8h]
  pfcRequest_t v50; // [sp+Ch] [-1D4h]
  volatile bool *v51; // [sp+60h] [-180h]
  int v52; // [sp+6Ch] [-174h]
  volatile int *v53; // [sp+74h] [-16Ch]
  volatile int *p_preloadCommandQueueEnd; // [sp+78h] [-168h]
  pageHeader_t v55; // [sp+90h] [-150h] BYREF
  _BYTE v56[64]; // [sp+C0h] [-120h] BYREF
  _DWORD v57[56]; // [sp+100h] [-E0h] BYREF
  idVirtualTexturePreloadThread *v58; // [sp+1F4h] [+14h]

  v58 = this;
  p_preloadCommandQueueStart = &this->preloadCommandQueueStart;
  v53 = &this->preloadCommandQueueStart;
  p_preloadCommandQueueEnd = &this->preloadCommandQueueEnd;
  if ( this->preloadCommandQueueStart != this->preloadCommandQueueEnd )
  {
    p_endCalled = &this->endCalled;
    v51 = &this->endCalled;
    while ( 1 )
    {
      v3 = this->preloadCommandQueue[*p_preloadCommandQueueStart];
      v52 = Sys_Milliseconds();
      v4 = (idVirtualTexture **)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                                  size: 0x30000u,
                                  tag: TAG_TEMP,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
      memset(v56, 0, sizeof(v56));
      v5 = 0;
      v6 = 0;
      memset(v57, 0, 64);
      type = v3->type;
      v8 = 0;
      if ( type == PRELOAD_ALL )
      {
        finerDiskLength = virtualTextureSystem.vts[1].header.subRoot.finerDiskLength;
        v10 = &v56[60];
        do
        {
          v11 = finerDiskLength - 32;
          if ( *((_DWORD *)finerDiskLength + 150) != 0 && *finerDiskLength != 0 )
          {
            v12 = 0;
            v13 = 0;
            if ( v6 > 0 )
            {
              v14 = v4;
              while ( idStr::Icmp(s1: (*v14)->pageFilePath.data, s2: *((const char **)finerDiskLength + 5)) != 0 )
              {
                ++v13;
                v14 += 3;
                if ( v13 >= v6 )
                  goto LABEL_14;
              }
              v12 = 1;
LABEL_14:
              p_endCalled = v51;
            }
            if ( v12 == 0 )
            {
              v15 = &v4[3 * v6];
              v6 = ((_WORD)v6 + 1) & 0x3FFF;
              ++v8;
              *v15 = (idVirtualTexture *)v11;
              v15[1] = *((idVirtualTexture **)v11 + 12);
              *((_WORD *)v15 + 4) = *finerDiskLength;
              *((_WORD *)v15 + 5) = v11[10] - 1;
              v16 = *((_DWORD *)v11 + 164);
              v17 = *(_DWORD *)&v56[4 * v16];
              *++v10 = v16;
              *(_DWORD *)&v56[4 * v16] = v17 + 1;
            }
          }
          finerDiskLength += 624;
        }
        while ( (int)finerDiskLength < (int)&virtualTextureSystem.vtPtrs[15] );
        if ( v8 <= 0 )
        {
LABEL_26:
          v18 = 0;
          goto LABEL_27;
        }
      }
      else
      {
        if ( type != PRELOAD_MATERIAL_LIST )
          goto LABEL_26;
        texture = v3->texture;
        if ( texture == nullptr || texture->header.subRoot.finerDiskLength[0] == 0 )
          goto LABEL_26;
        *v4 = texture;
        v6 = 1;
        v8 = 1;
        v4[1] = (idVirtualTexture *)v3->texture->header.subRoot.finerDiskOffset[0];
        *((_WORD *)v4 + 4) = v3->texture->header.subRoot.finerDiskLength[0];
        *((_WORD *)v4 + 5) = v3->texture->header.numLevels - 1;
        v20 = 4 * v3->texture->pageSource;
        v21 = *(_DWORD *)&v56[v20];
        v57[0] = v3->texture->pageSource;
        *(_DWORD *)&v56[v20] = v21 + 1;
      }
      __twllei(v8, 0);
      if ( 400 / v8 >= 50 )
        v18 = 400 / v8;
      else
        v18 = 50;
LABEL_27:
      while ( !*p_endCalled )
      {
        if ( v58->cancelToTerminate || v5 == v6 )
          break;
        idStreamFileCache::NewFrame(this: streamFileCache);
        v22 = v5;
        do
        {
          if ( *p_endCalled )
            break;
          v23 = 0x7FFFFFFF;
          v24 = &v4[3 * v22];
          if ( v8 > 0 )
          {
            v25 = v57;
            for ( i = v8; i != 0; --i )
            {
              if ( *(_DWORD *)&v56[4 * *v25] != 0 )
              {
                v27 = 4 * (*v25 + 2310);
                if ( *(int *)((char *)&v3->handle + v27) < v23 )
                  v23 = *(int *)((char *)&v3->handle + v27);
              }
              ++v25;
            }
          }
          LODWORD(v28) = *v24;
          if ( v3->pagesLoaded[(*v24)->pageSource] <= v23 + v18 )
          {
            HIDWORD(v28) = *((unsigned __int16 *)v24 + 5);
            v29 = (idStreamControlThread_vtbl *)__ROL4__(HIDWORD(v28), 15);
            HIDWORD(v28) = 64 << (BYTE3(v28) + 4);
            if ( *(_DWORD *)(v28 + 668) == 0
              || (HIDWORD(v30) = *(_DWORD *)(v28 + 668), *((unsigned __int16 *)v24 + 5) < *(int *)(v28 + 672)) )
            {
              HIDWORD(v30) = *(_DWORD *)(v28 + 664);
            }
            LODWORD(v28) = *(_DWORD *)(v28 + 28);
            LODWORD(v30) = v24[1];
            LODWORD(v31) = 40;
            *(_QWORD *)((char *)&v31 + 4) = v28 * v30;
            if ( idStreamFileCache::ReadCachedData(
                   this: streamFileCache,
                   cacheFile: (idFile *)DWORD1(v31),
                   ofs: v31,
                   length: (unsigned __int8 *)&v55,
                   dest: 0,
                   blockingRead: v29,
                   priority: (idStreamControlThread_vtbl *)HIDWORD(v28),
                   persistence: v49,
                   pfc: v50) == 40 )
            {
              pageHeader_t::Swap(this: &v55);
              v32 = 4 * ((*v24)->pageSource + 2310);
              ++*(int *)((char *)&v3->handle + v32);
              minLod = v3->minLod;
              if ( v3->type == PRELOAD_ALL && (*v24)->pageSource == PAGESOURCE_VMTR )
                minLod = (*v24)->header.numLevels - 5;
              if ( v55.level > minLod )
              {
                v34 = 0;
                v35 = v55.finerDiskLength;
                finerDiskOffset = v55.finerDiskOffset;
                do
                {
                  if ( *v35 != 0 )
                  {
                    if ( v3->type != PRELOAD_MATERIAL_LIST )
                      goto LABEL_61;
                    v37 = ((2 * v55.x) & 0x1FFFE | v34 & 1) << (LOBYTE(v55.level) - 1);
                    v38 = ((2 * v55.y) & 0x1FFFE | (v34 >> 1) & 1) << (LOBYTE(v55.level) - 1);
                    v39 = ~((1 << (LOBYTE(v55.level) - 1)) - 1);
                    v40 = 0;
                    v41 = 0;
                    if ( v3->numTextureRects > 0 )
                    {
                      p_x2 = &v3->textureRects[0].x2;
                      while ( v55.level - 1 < v3->textureMinLod[v41]
                           || v37 < (unsigned __int16)(*(p_x2 - 2) & v39)
                           || v38 < (unsigned __int16)(*(p_x2 - 1) & v39)
                           || v37 > (unsigned __int16)(*p_x2 & v39)
                           || v38 > (unsigned __int16)(p_x2[1] & v39) )
                      {
                        ++v41;
                        p_x2 += 4;
                        if ( v41 >= v3->numTextureRects )
                          goto LABEL_60;
                      }
                      v40 = 1;
                    }
LABEL_60:
                    if ( v40 != 0 )
                    {
LABEL_61:
                      if ( ((v6 + 1) & 0x3FFF) == v5 )
                        break;
                      v43 = &v4[3 * v6];
                      v6 = (v6 + 1) & 0x3FFF;
                      *v43 = *v24;
                      v43[1] = (idVirtualTexture *)*finerDiskOffset;
                      *((_WORD *)v43 + 4) = *v35;
                      *((_WORD *)v43 + 5) = *((_WORD *)v24 + 5) - 1;
                      ++*(_DWORD *)&v56[4 * (*v24)->pageSource];
                    }
                  }
                  ++v34;
                  ++finerDiskOffset;
                  ++v35;
                }
                while ( v34 < 4 );
                p_preloadCommandQueueStart = v53;
                p_endCalled = v51;
              }
              v44 = v22;
              --*(_DWORD *)&v56[4 * (*v24)->pageSource];
              if ( v22 != v5 )
              {
                do
                {
                  v45 = ((_WORD)v44 - 1) & 0x3FFF;
                  v46 = &v4[3 * v44];
                  v44 = v45;
                  *v46 = v4[3 * v45];
                  v46[1] = v4[3 * v45 + 1];
                  v46[2] = v4[3 * v45 + 2];
                }
                while ( v45 != v5 );
              }
              v5 = (v5 + 1) & 0x3FFF;
            }
          }
          v22 = (v22 + 1) & 0x3FFF;
        }
        while ( v22 != v6 );
        idStreamFileCache::SignalWork(this: streamFileCache);
        mgthread_sleep(ms: 8);
      }
      v47 = Sys_Milliseconds();
      v3->done = true;
      v3->totalTimeMSec = v47 - v52;
      if ( v4 != nullptr )
        idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
      *p_preloadCommandQueueStart = (*p_preloadCommandQueueStart + 1) & 0xF;
      if ( *p_preloadCommandQueueStart == *p_preloadCommandQueueEnd )
        return 0;
      this = v58;
    }
  }
  return 0;
}


// ========================================================================
// __unwind$223822
// EA  : 0x8297B3D0
// RVA : 0x0097B3D0
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

void _unwind_223822()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 480 + 128));
}


// ========================================================================
// `dynamic initializer for 'virtualTexturePreloader''
// EA  : 0x8335E840
// RVA : 0x0135E840
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__virtualTexturePreloader__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__virtualTexturePreloader__);
}


// ========================================================================
// `dynamic initializer for 'testPreloader_v''
// EA  : 0x8335E850
// RVA : 0x0135E850
// PDB : w:\tech5\engine\renderer\virtualtexturepreloader.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testPreloader_v__()
{
  return idCommandLink::idCommandLink(
           this: &testPreloader_v,
           cmdName: "testPreloader",
           function: testPreloader_f,
           description: &byte_8200D768,
           argCompletion: nullptr);
}

