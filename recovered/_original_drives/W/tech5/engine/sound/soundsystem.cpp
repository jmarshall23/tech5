
// ========================================================================
// ?ArgCompletion_SoundName@@YAXAAVidAutoComplete@@@Z
// EA  : 0x82991358
// RVA : 0x00991358
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall ArgCompletion_SoundName(idAutoComplete *autoComplete)
{
  declManager->ArgCompletion_DeclName(this: declManager, a2: autoComplete, a3: &idSoundShader::resourceList);
  cmdSystem->ArgCompletion_FolderExtension(this: cmdSystem, a2: autoComplete, a3: "sound/", a4: "wav", a5: false);
}


// ========================================================================
// ?Shutdown@idSoundSystemLocal@@UAAXXZ
// EA  : 0x829913D8
// RVA : 0x009913D8
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundSystemLocal::Shutdown(idSoundSystemLocal *this)
{
  idParallelJobList **p_parallelJobList; // r30
  idParallelJobList *parallelJobList; // r3
  idSoundThread **p_soundThread; // r31
  idParallelJobList *v5; // r4

  p_parallelJobList = &this->parallelJobList;
  this->WaitForSoundThread(this);
  parallelJobList = this->parallelJobList;
  if ( parallelJobList != nullptr )
    idParallelJobList::Wait(this: parallelJobList);
  this->StopAllSounds(this);
  idSoundHardware_XAudio2::Shutdown(this: &this->hardware);
  this->FreeStreamBuffers(this);
  p_soundThread = &this->soundThread;
  if ( *p_soundThread != nullptr )
    ((void (__fastcall *)(idSoundThread *, int))(*p_soundThread)->dtr_idSysThread)(a1: *p_soundThread, a2: 1);
  v5 = *p_parallelJobList;
  *p_soundThread = nullptr;
  if ( v5 != nullptr )
  {
    ((void (__fastcall *)(idParallelJobManager *))parallelJobManager->FreeJobList)(a1: parallelJobManager);
    *p_parallelJobList = nullptr;
  }
}


// ========================================================================
// ?SetPlayingSoundWorld@idSoundSystemLocal@@UAAXPAVidSoundWorld@@@Z
// EA  : 0x829914A0
// RVA : 0x009914A0
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundSystemLocal::SetPlayingSoundWorld(idSoundSystemLocal *this, idSoundWorldLocal *soundWorld)
{
  idSoundWorldLocal *currentSoundWorld; // r11

  currentSoundWorld = this->currentSoundWorld;
  if ( currentSoundWorld != soundWorld )
  {
    this->currentSoundWorld = soundWorld;
    if ( currentSoundWorld != nullptr )
      idSoundWorldLocal::Update(this: currentSoundWorld);
  }
}


// ========================================================================
// ?SetEditorSoundWorld@idSoundSystemLocal@@UAAXPAVidSoundWorld@@@Z
// EA  : 0x829914C8
// RVA : 0x009914C8
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundSystemLocal::SetEditorSoundWorld(idSoundSystemLocal *this, idSoundWorldLocal *soundWorld)
{
  this->editorSoundWorld = soundWorld;
}


// ========================================================================
// ?WaitForSoundThread@idSoundSystemLocal@@UAAXXZ
// EA  : 0x829914D0
// RVA : 0x009914D0
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundSystemLocal::WaitForSoundThread(idSoundSystemLocal *this)
{
  idSoundThread *soundThread; // r3

  soundThread = this->soundThread;
  if ( soundThread != nullptr )
  {
    idSysThread::WaitForThread(this: soundThread);
    this->soundThreadRunning = false;
  }
}


// ========================================================================
// ?GetNumSpeakers@idSoundSystemLocal@@UBAHXZ
// EA  : 0x82991520
// RVA : 0x00991520
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

int __fastcall idSoundSystemLocal::GetNumSpeakers(idSoundSystemLocal *this)
{
  return idSoundVoice_Base::dstChannels;
}


// ========================================================================
// ?GetSpeakerMask@idSoundSystemLocal@@UBAHXZ
// EA  : 0x82991530
// RVA : 0x00991530
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

int __fastcall idSoundSystemLocal::GetSpeakerMask(idSoundSystemLocal *this)
{
  return idSoundVoice_Base::dstMask;
}


// ========================================================================
// ?AllocateVoice@idSoundSystemLocal@@QAAPAVidSoundVoice@@PBVidSoundSample@@ABV?$idList@PAVidSoundSample@@$04@@@Z
// EA  : 0x82991540
// RVA : 0x00991540
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

idSoundVoice *__fastcall idSoundSystemLocal::AllocateVoice(
        idSoundSystemLocal *this,
        const idSoundSample *sample,
        const idList<idSoundSample *,5> *samples)
{
  return idSoundHardware_XAudio2::AllocateVoice(this: &this->hardware, sample, samples);
}


// ========================================================================
// ?FreeVoice@idSoundSystemLocal@@QAAXPAVidSoundVoice@@@Z
// EA  : 0x82991548
// RVA : 0x00991548
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundSystemLocal::FreeVoice(idSoundSystemLocal *this, idSoundVoice *voice)
{
  idSoundHardware_XAudio2::FreeVoice(this: &this->hardware, voice);
}


// ========================================================================
// ?Render@idSoundThread@@QBAXXZ
// EA  : 0x829915E0
// RVA : 0x009915E0
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundThread::Render(idSoundThread *this)
{
  if ( soundSystemLocal.currentSoundWorld != nullptr )
    idSoundWorldLocal::Update(this: soundSystemLocal.currentSoundWorld);
  idSoundHardware_XAudio2::Update(this: &soundSystemLocal.hardware);
  soundSystemLocal.soundTime = Sys_Milliseconds();
}


// ========================================================================
// ?Restart@idSoundSystemLocal@@QAAXXZ
// EA  : 0x82991630
// RVA : 0x00991630
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundSystemLocal::Restart(idSoundSystemLocal *this)
{
  int v2; // r23
  int v3; // r24
  int v4; // r26
  idSoundWorldLocal *v5; // r27
  int v6; // r28
  int v7; // r31
  idSoundEmitterLocal *v8; // r29
  int v9; // r30

  this->WaitForSoundThread(this);
  session->ShutdownSoundRelatedSystems(this: session);
  v2 = 0;
  if ( this->soundWorlds.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = 0;
      v5 = this->soundWorlds.list[v3];
      if ( v5->emitters.num > 0 )
      {
        v6 = 0;
        do
        {
          v7 = 0;
          v8 = v5->emitters.list[v6];
          if ( v8->channels.num > 0 )
          {
            v9 = 0;
            do
            {
              idSoundChannel::Mute(this: v8->channels.list[v9]);
              ++v7;
              ++v9;
            }
            while ( v7 < v8->channels.num );
          }
          ++v4;
          ++v6;
        }
        while ( v4 < v5->emitters.num );
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->soundWorlds.num );
  }
  idSoundHardware_XAudio2::Shutdown(this: &this->hardware);
  if ( s_noSound.valueInteger == 0 )
    idSoundHardware_XAudio2::Init(this: &this->hardware);
  this->InitStreamBuffers(this);
  session->InitializeSoundRelatedSystems(this: session);
}


// ========================================================================
// ?Render@idSoundSystemLocal@@UAAX_N@Z
// EA  : 0x82991758
// RVA : 0x00991758
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundSystemLocal::Render(idSoundSystemLocal *this, bool threaded)
{
  idSoundThread **p_soundThread; // r30
  idSoundThread *v5; // r3

  p_soundThread = &this->soundThread;
  if ( this->soundThread != nullptr )
  {
    this->WaitForSoundThread(this);
    if ( s_noSound.valueInteger == 0 && !idLib::headless )
    {
      if ( this->needsRestart )
      {
        this->needsRestart = false;
        idSoundSystemLocal::Restart(this);
      }
      if ( threaded && s_useSoundThread.valueInteger != 0 )
      {
        v5 = *p_soundThread;
        this->soundThreadRunning = true;
        idSysThread::SignalWork(this: v5);
      }
      else
      {
        idSoundThread::Render(this: *p_soundThread);
      }
    }
  }
}


// ========================================================================
// ?OnReloadSound@idSoundSystemLocal@@UAAXPBVidDecl@@@Z
// EA  : 0x82991828
// RVA : 0x00991828
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundSystemLocal::OnReloadSound(idSoundSystemLocal *this, const idDecl *sound)
{
  int v4; // r31
  int v5; // r30

  v4 = 0;
  if ( this->soundWorlds.num > 0 )
  {
    v5 = 0;
    do
    {
      idSoundWorldLocal::OnReloadSound(this: this->soundWorlds.list[v5], shader: sound);
      ++v4;
      ++v5;
    }
    while ( v4 < this->soundWorlds.num );
  }
}


// ========================================================================
// ?StopAllSounds@idSoundSystemLocal@@UAAXXZ
// EA  : 0x82991880
// RVA : 0x00991880
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundSystemLocal::StopAllSounds(idSoundSystemLocal *this)
{
  int v2; // r29
  int v3; // r31
  idSoundWorldLocal *v4; // r3

  v2 = 0;
  if ( this->soundWorlds.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->soundWorlds.list[v3];
      if ( v4 != nullptr )
        v4->StopAllSounds(this: v4);
      ++v2;
      ++v3;
    }
    while ( v2 < this->soundWorlds.num );
  }
  idSoundHardware_XAudio2::Update(this: &this->hardware);
}


// ========================================================================
// ?StopVoicesWithSample@idSoundSystemLocal@@QAAXQBVidSoundSample@@@Z
// EA  : 0x829918E8
// RVA : 0x009918E8
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundSystemLocal::StopVoicesWithSample(idSoundSystemLocal *this, const idSoundSample *const sample)
{
  int v4; // r22
  int v5; // r24
  idSoundWorldLocal *v6; // r27
  int v7; // r26
  int v8; // r28
  idSoundEmitterLocal *v9; // r30
  int v10; // r29
  int v11; // r31
  idSoundChannel *v12; // r3

  v4 = 0;
  if ( this->soundWorlds.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = this->soundWorlds.list[v5];
      if ( v6 != nullptr )
      {
        v7 = 0;
        if ( v6->emitters.num > 0 )
        {
          v8 = 0;
          do
          {
            v9 = v6->emitters.list[v8];
            if ( v9 != nullptr )
            {
              v10 = 0;
              if ( v9->channels.num > 0 )
              {
                v11 = 0;
                do
                {
                  v12 = v9->channels.list[v11];
                  if ( v12->sample == sample )
                    idSoundChannel::Mute(this: v12);
                  ++v10;
                  ++v11;
                }
                while ( v10 < v9->channels.num );
              }
            }
            ++v7;
            ++v8;
          }
          while ( v7 < v6->emitters.num );
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->soundWorlds.num );
  }
}


// ========================================================================
// ?Run@idSoundThread@@UAAHXZ
// EA  : 0x829919C0
// RVA : 0x009919C0
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

int __fastcall idSoundThread::Run(idSoundThread *this)
{
  _BYTE v3[16]; // [sp+50h] [-40h] BYREF
  rangeId_t v4; // [sp+60h] [-30h]

  ((void (__fastcall *)(_BYTE *))console->GetTimeRangeColor)(a1: v3);
  v4 = RANGE_RENDER;
  console->BeginTimeRange(this: console, a2: RANGE_RENDER, a3: &idColor::colorPurple);
  if ( !this->initialized )
    this->initialized = true;
  if ( soundSystemLocal.currentSoundWorld != nullptr )
    idSoundWorldLocal::Update(this: soundSystemLocal.currentSoundWorld);
  idSoundHardware_XAudio2::Update(this: &soundSystemLocal.hardware);
  soundSystemLocal.soundTime = Sys_Milliseconds();
  console->BeginTimeRange(this: console, a2: v4, a3: (const idColor *)v3);
  return 0;
}


// ========================================================================
// __unwind$225401
// EA  : 0x82991A7C
// RVA : 0x00991A7C
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void _unwind_225401()
{
  int v0; // r12

  idScopedConsoleTimeRange::~idScopedConsoleTimeRange(this: (idScopedConsoleTimeRange *)(v0 - 144 + 80));
}


// ========================================================================
// ?TestSound_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82991AA8
// RVA : 0x00991AA8
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall TestSound_f(const idCmdArgs *args)
{
  idSoundWorldLocal *currentSoundWorld; // r11
  const char *v2; // r4
  const idDecl *v3; // r3

  if ( args->argc == 2 )
  {
    currentSoundWorld = soundSystemLocal.currentSoundWorld;
    if ( soundSystemLocal.currentSoundWorld != nullptr )
    {
      v2 = args->argv[1];
      if ( v2 != nullptr )
      {
        v3 = idDeclInfo::FindWithInheritance(this: &idSoundShader::resourceList, name: v2, makeDefault: true);
        currentSoundWorld = soundSystemLocal.currentSoundWorld;
        v2 = (const char *)v3;
      }
      currentSoundWorld->PlayGlobalShaderDirectly(
        this: currentSoundWorld,
        a2: (const idSoundShader *)v2,
        a3: SND_CHANNEL_ANY,
        a4: 0.0);
    }
  }
  else
  {
    idLib::Printf(fmt: "Usage: testSound <file>\n");
  }
}


// ========================================================================
// ?testWorldSound_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82991B50
// RVA : 0x00991B50
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall testWorldSound_f(const idCmdArgs *args)
{
  int argc; // r11
  int v3; // r3
  double v4; // fp0
  int i; // r24
  __int128 v6; // r7
  int v7; // r3
  unsigned int v8; // r11
  bool v9; // cr57
  char *v10; // r3
  char *v11; // r4
  float v12; // [sp+70h] [-60h] BYREF
  float v13; // [sp+74h] [-5Ch]
  float v14; // [sp+78h] [-58h]

  argc = args->argc;
  if ( args->argc >= 2 )
  {
    v3 = 1;
    if ( argc > 3 )
      v3 = atol(nptr: args->argv[3]);
    if ( v3 > 0 )
    {
      v4 = 0.000030518509;
      for ( i = v3; i != 0; --i )
      {
        DWORD2(v6) = 37776;
        v7 = 0;
        HIDWORD(v6) = 1664525 * soundSystemLocal.random.seed;
        LODWORD(v6) = ((1664525 * soundSystemLocal.random.seed + 1013904223) >> 10) & 0x7FFF;
        v8 = 1664525 * (1664525 * soundSystemLocal.random.seed + 1013904223) + 1013904223;
        DWORD1(v6) = (v8 >> 10) & 0x7FFF;
        v14 = (float)(__int64)v6 * (float)v4;
        soundSystemLocal.random.seed = 1664525 * v8 + 1013904223;
        DWORD2(v6) = ((1664525 * v8 + 1013904223) >> 10) & 0x7FFF;
        v9 = args->argc > 2;
        v13 = (float)*(__int64 *)&v6 * (float)v4;
        v12 = (float)*(__int64 *)((char *)&v6 + 4) * (float)v4;
        if ( v9 )
        {
          v10 = idCmdArgs::Argv(this: args, arg: 2);
          v7 = atol(nptr: v10);
          v4 = 0.000030518509;
        }
        v12 = v12 * (float)__SPAIR64__((unsigned int)soundSystemLocal.currentSoundWorld, v7);
        v13 = v13 * (float)__SPAIR64__((unsigned int)soundSystemLocal.currentSoundWorld, v7);
        v14 = v14 * (float)__SPAIR64__((unsigned int)soundSystemLocal.currentSoundWorld, v7);
        if ( soundSystemLocal.currentSoundWorld != nullptr )
        {
          v11 = idCmdArgs::Argv(this: args, arg: 1);
          if ( v11 != nullptr )
            v11 = (char *)idDeclInfo::FindWithInheritance(
                            this: &idSoundShader::resourceList,
                            name: v11,
                            makeDefault: true);
          soundSystemLocal.currentSoundWorld->PlayPositionedShaderDirectly(
            this: soundSystemLocal.currentSoundWorld,
            a2: (const idSoundShader *)v11,
            a3: (const idVec3 *)&v12,
            a4: &mat3_identity,
            a5: 0.0);
          v4 = 0.000030518509;
        }
      }
    }
  }
  else
  {
    idLib::Printf(fmt: "Usage: testWorldSound <file> randomBounds\n");
  }
}


// ========================================================================
// ?TestSWChannelList_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82991D40
// RVA : 0x00991D40
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall TestSWChannelList_f(const idCmdArgs *args)
{
  int v1; // r30
  idResource *v2; // r3
  idResource *nextOnHashChain; // r11
  idResource *v4; // r22
  idAtomicString *p_name; // r31
  const char *str; // r11
  int v7; // r21
  _DWORD *j; // r31
  int v9; // r26
  int v10; // r25
  int v11; // r23
  int v12; // r3
  int v13; // r11
  int k; // r23
  int v15; // r25
  int v16; // r26
  int v17; // r27
  idSoundWorldLocal *currentSoundWorld; // r3
  idSoundEmitterLocal *v19; // r31
  int v20; // r28
  int v21; // r29
  const idSoundShader *soundShader; // r11
  const char *v23; // r30
  idSoundChannel **v24; // r11
  int startTime; // r16
  soundChannel_t logicalChannel; // r15
  const char *v27; // r14
  int v28; // r3
  int i; // [sp+50h] [-B0h]

  v1 = 0;
  for ( i = 0; v1 < idSoundShader::resourceList.num; i = v1 )
  {
    v2 = idResourceList::Index(this: &idSoundShader::resourceList, index: v1);
    nextOnHashChain = v2[7].nextOnHashChain;
    v4 = v2;
    p_name = &v2[7].name;
    if ( nextOnHashChain != nullptr
      && nextOnHashChain != (idResource *)p_name->str
      && nextOnHashChain->nextOnHashChain != nullptr )
    {
      idLib::Printf(fmt: "Shader %s\n", v2->name.str);
      str = p_name[1].str;
      v7 = 0;
      if ( str != nullptr && str != p_name->str )
      {
        for ( j = *((_DWORD **)str + 3); j != nullptr; j = *(_DWORD **)(v13 + 12) )
        {
          v9 = j[1];
          v10 = j[3];
          v11 = *(_DWORD *)(j[42] + 8);
          v12 = (**(int (__fastcall ***)(_DWORD))*j)(a1: *j);
          idLib::Printf(fmt: "    %d. Emitter[%d]->Channel[%d]: %s (%d)\n", v7, v12, v10, v11, v9);
          v13 = j[59];
          ++v7;
          if ( v13 == 0 )
            break;
          if ( v13 == j[58] )
            break;
        }
      }
      idLib::Printf(fmt: "\n");
      for ( k = 0; k < 2; ++k )
      {
        v15 = 0;
        v16 = 0;
        if ( soundSystemLocal.currentSoundWorld->NumEmitters(this: soundSystemLocal.currentSoundWorld) > 0 )
        {
          v17 = 0;
          do
          {
            currentSoundWorld = soundSystemLocal.currentSoundWorld;
            v19 = soundSystemLocal.currentSoundWorld->emitters.list[v17];
            if ( v19 != nullptr )
            {
              v20 = 0;
              if ( v19->channels.num > 0 )
              {
                v21 = 0;
                do
                {
                  soundShader = v19->channels.list[v21]->soundShader;
                  if ( soundShader != nullptr )
                  {
                    if ( soundShader == (const idSoundShader *)v4 )
                      ++v15;
                    if ( k > 0 )
                    {
                      v23 = "^2";
                      if ( soundShader != (const idSoundShader *)v4 )
                        v23 = "^8";
                      v24 = &v19->channels.list[v21];
                      startTime = (*v24)->startTime;
                      logicalChannel = (*v24)->logicalChannel;
                      v27 = (*v24)->sample->name.str;
                      v28 = v19->Index(this: v19);
                      idLib::Printf(
                        fmt: "    %sEmitter[%d]->Channel[%d]: %s (%d)\n",
                        v23,
                        v28,
                        logicalChannel,
                        v27,
                        startTime);
                    }
                  }
                  ++v20;
                  ++v21;
                }
                while ( v20 < v19->channels.num );
                currentSoundWorld = soundSystemLocal.currentSoundWorld;
              }
            }
            ++v16;
            ++v17;
          }
          while ( v16 < currentSoundWorld->NumEmitters(this: currentSoundWorld) );
          v1 = i;
        }
        if ( v15 == v7 )
          break;
        if ( k > 0 )
          break;
        idLib::Warning(fmt: "Channel listing FAILED. NumInList: %d, numObserved: %d", v7, v15);
      }
      idLib::Printf(fmt: "\n");
    }
    ++v1;
  }
}


// ========================================================================
// ?RestartSound_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82992010
// RVA : 0x00992010
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall RestartSound_f(const idCmdArgs *args)
{
  idSoundSystemLocal::Restart(this: &soundSystemLocal);
}


// ========================================================================
// ?Init@idSoundSystemLocal@@UAAXXZ
// EA  : 0x82992028
// RVA : 0x00992028
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundSystemLocal::Init(idSoundSystemLocal *this)
{
  int v2; // r3
  idSysThread *v3; // r3
  idSoundThread *v4; // r29
  idSoundThread *v5; // r3

  idLib::Printf(fmt: "----- Initializing Sound System ------\n");
  v2 = Sys_Milliseconds();
  this->soundTime = v2;
  this->random.seed = v2;
  v3 = (idSysThread *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 0x3Cu,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  v4 = (idSoundThread *)v3;
  if ( v3 != nullptr )
  {
    idSysThread::idSysThread(this: v3);
    v4->initialized = false;
    v5 = v4;
    v4->__vftable = (idSoundThread_vtbl *)&idSoundThread::`vftable';
  }
  else
  {
    v5 = nullptr;
  }
  this->soundThread = v5;
  idSysThread::StartWorkerThread(
    this: v5,
    name_: "SoundThread",
    core: CORE_0B,
    priority: THREAD_NORMAL,
    stackSize: 0x20000);
  this->parallelJobList = parallelJobManager->AllocJobList(
                            this: parallelJobManager,
                            a2: 8,
                            a3: 2,
                            a4: 1024,
                            a5: 2,
                            a6: &idColor::colorPurple);
  if ( idLib::production >= PROD_PRODUCTION )
    idCVar::SetBool(this: &s_useCompression, newValue: true, force: true);
  if ( s_noSound.valueInteger == 0 && !idLib::headless )
  {
    idSoundHardware_XAudio2::Init(this: &this->hardware);
    this->InitStreamBuffers(this);
  }
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "testSound",
    a3: TestSound_f,
    a4: "tests a sound",
    a5: ArgCompletion_SoundName);
  cmdSystem->AddCommand(this: cmdSystem, a2: "s_restart", a3: RestartSound_f, a4: "restart sound system", a5: nullptr);
  speakerPositions[2].x = 0.0;
  speakerPositions[2].y = 0.0;
  speakerPositions[3].x = 0.0;
  speakerPositions[3].y = 0.0;
  speakerPositions[8].y = 0.0;
  speakerPositions[9].x = 0.0;
  speakerPositions[10].x = 0.0;
  speakerPositions[0].x = 0.70710677;
  speakerPositions[0].y = 0.70710677;
  speakerPositions[1].x = 0.70710677;
  speakerPositions[1].y = -0.70710677;
  speakerPositions[4].x = -0.70710677;
  speakerPositions[4].y = 0.70710677;
  speakerPositions[5].x = -0.70710677;
  speakerPositions[5].y = -0.70710677;
  speakerPositions[6].x = 0.9238795;
  speakerPositions[6].y = 0.38268343;
  speakerPositions[7].x = 0.9238795;
  speakerPositions[7].y = -0.38268343;
  speakerPositions[8].x = -1.0;
  speakerPositions[10].y = -1.0;
  speakerPositions[9].y = 1.0;
  idLib::Printf(fmt: "sound system initialized.\n");
  idLib::Printf(fmt: "--------------------------------------\n");
}


// ========================================================================
// __unwind$225658
// EA  : 0x829922AC
// RVA : 0x009922AC
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall _unwind_225658(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?FreeStreamBuffers@idSoundSystemLocal@@UAAXXZ
// EA  : 0x829922D8
// RVA : 0x009922D8
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundSystemLocal::FreeStreamBuffers(idSoundSystemLocal *this)
{
  idSysMutex *p_streamBufferMutex; // r24
  int v3; // r30
  int v4; // r31
  idStaticList<idSoundSystemLocal::bufferContext_t,144> *p_bufferContexts; // r31
  idStaticList<idSoundSystemLocal::bufferContext_t *,144> *p_freeStreamBufferContexts; // r30
  idStaticList<idSoundSystemLocal::bufferContext_t *,144> *p_activeStreamBufferContexts; // r31

  if ( s_usePinning.valueInteger == 0 )
  {
    p_streamBufferMutex = &this->streamBufferMutex;
    Sys_MutexLock(handle: &this->streamBufferMutex.handle, blocking: true);
    v3 = 0;
    if ( this->bufferContexts.num > 0 )
    {
      v4 = 0;
      do
      {
        XMemFree(pAddress: this->bufferContexts.list[v4].buffer, dwAllocAttributes: 0xAB290000);
        ++v3;
        ++v4;
      }
      while ( v3 < this->bufferContexts.num );
    }
    p_bufferContexts = &this->bufferContexts;
    if ( this->bufferContexts.listStatic == 0 || this->bufferContexts.listStatic == 2 )
    {
      if ( p_bufferContexts->list != nullptr )
        idMem::Free(this: &mem, ptr: p_bufferContexts->list, align: ALIGN_16);
      p_bufferContexts->list = nullptr;
      this->bufferContexts.size = 0;
    }
    this->bufferContexts.num = 0;
    p_freeStreamBufferContexts = &this->freeStreamBufferContexts;
    if ( this->freeStreamBufferContexts.listStatic == 0 || this->freeStreamBufferContexts.listStatic == 2 )
    {
      if ( p_freeStreamBufferContexts->list != nullptr )
        idMem::Free(this: &mem, ptr: p_freeStreamBufferContexts->list, align: ALIGN_16);
      p_freeStreamBufferContexts->list = nullptr;
      this->freeStreamBufferContexts.size = 0;
    }
    this->freeStreamBufferContexts.num = 0;
    p_activeStreamBufferContexts = &this->activeStreamBufferContexts;
    if ( this->activeStreamBufferContexts.listStatic == 0 || this->activeStreamBufferContexts.listStatic == 2 )
    {
      if ( p_activeStreamBufferContexts->list != nullptr )
        idMem::Free(this: &mem, ptr: p_activeStreamBufferContexts->list, align: ALIGN_16);
      p_activeStreamBufferContexts->list = nullptr;
      this->activeStreamBufferContexts.size = 0;
    }
    this->activeStreamBufferContexts.num = 0;
    Sys_MutexUnlock(handle: &p_streamBufferMutex->handle);
  }
}


// ========================================================================
// ?FreeSoundWorld@idSoundSystemLocal@@UAAXPAVidSoundWorld@@@Z
// EA  : 0x82992438
// RVA : 0x00992438
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundSystemLocal::FreeSoundWorld(idSoundSystemLocal *this, idMapChangeListener *sw)
{
  idMapChangeListener *v3; // [sp+50h] [-20h] BYREF

  v3 = sw;
  idList<void *,108>::RemoveFast(this: (idList<idMapChangeListener *,5> *)&this->soundWorlds, obj: &v3);
  if ( sw != nullptr )
    sw->MapLoaded(this: sw, a2: (idMapFile *)1);
}


// ========================================================================
// ?InitStreamBuffers@idSoundSystemLocal@@UAAXXZ
// EA  : 0x82992678
// RVA : 0x00992678
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundSystemLocal::InitStreamBuffers(idSoundSystemLocal *this)
{
  idSysMutex *p_streamBufferMutex; // r24
  char v3; // r4
  unsigned int v4; // r28
  idStaticList<idSoundSystemLocal::bufferContext_t,144> *p_bufferContexts; // r30
  int v6; // r31
  idList<enum encounterGroupRole_t,5> *p_freeStreamBufferContexts; // r29
  void *v8; // r3
  int v9; // r30
  int v10; // r31
  idSoundSystemLocal::bufferContext_t *v11; // [sp+50h] [-50h] BYREF

  if ( s_usePinning.valueInteger == 0 )
  {
    p_streamBufferMutex = &this->streamBufferMutex;
    Sys_MutexLock(handle: &this->streamBufferMutex.handle, blocking: true);
    v3 = _cntlzw(this->bufferContexts.num);
    v4 = s_streamBufferSizeK.valueInteger << 10;
    if ( s_useStreaming.valueInteger != 0 )
    {
      if ( (v3 & 0x20) != 0 )
      {
        p_bufferContexts = &this->bufferContexts;
        idList<idSoundSystemLocal::bufferContext_t,5>::SetNum(this: &this->bufferContexts, newNum: 144);
        v6 = 0;
        p_freeStreamBufferContexts = (idList<enum encounterGroupRole_t,5> *)&this->freeStreamBufferContexts;
        do
        {
          v8 = XMemAlloc(dwSize: v4, dwAllocAttributes: 0xAB290000);
          p_bufferContexts->list[v6].voice = nullptr;
          p_bufferContexts->list[v6].buffer = v8;
          v11 = &p_bufferContexts->list[v6];
          idList<idAnimWebBlendTree *,5>::Append(
            this: p_freeStreamBufferContexts,
            obj: (const encounterGroupRole_t *)&v11);
          ++v6;
        }
        while ( v6 < 144 );
        Sys_MutexUnlock(handle: &p_streamBufferMutex->handle);
      }
      else
      {
        v9 = 0;
        if ( this->activeStreamBufferContexts.num > 0 )
        {
          v10 = 0;
          do
          {
            idList<idAnimWebBlendTree *,5>::Append(
              this: (idList<enum encounterGroupRole_t,5> *)&this->freeStreamBufferContexts,
              obj: (const encounterGroupRole_t *)&this->activeStreamBufferContexts.list[v10]);
            ++v9;
            ++v10;
          }
          while ( v9 < this->activeStreamBufferContexts.num );
        }
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activeStreamBufferContexts);
        Sys_MutexUnlock(handle: &p_streamBufferMutex->handle);
      }
    }
    else
    {
      if ( (v3 & 0x20) == 0 )
        this->FreeStreamBuffers(this);
      Sys_MutexUnlock(handle: &p_streamBufferMutex->handle);
    }
  }
}


// ========================================================================
// ?ObtainStreamBufferContext@idSoundSystemLocal@@QAAPAUbufferContext_t@1@XZ
// EA  : 0x82992808
// RVA : 0x00992808
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

idSoundSystemLocal::bufferContext_t *__fastcall idSoundSystemLocal::ObtainStreamBufferContext(idSoundSystemLocal *this)
{
  idSoundSystemLocal::bufferContext_t *v3; // r30
  int num; // r10
  idSoundSystemLocal::bufferContext_t *v5; // [sp+50h] [-30h] BYREF

  if ( s_usePinning.valueInteger != 0 )
    return nullptr;
  v3 = nullptr;
  Sys_MutexLock(handle: &this->streamBufferMutex.handle, blocking: true);
  num = this->freeStreamBufferContexts.num;
  if ( num != 0 )
  {
    v3 = this->freeStreamBufferContexts.list[num - 1];
    v5 = v3;
    idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)&this->freeStreamBufferContexts, newNum: num - 1);
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->activeStreamBufferContexts,
      obj: (const encounterGroupRole_t *)&v5);
  }
  Sys_MutexUnlock(handle: &this->streamBufferMutex.handle);
  return v3;
}


// ========================================================================
// ?ReleaseStreamBufferContext@idSoundSystemLocal@@QAAXPAUbufferContext_t@1@@Z
// EA  : 0x829928B0
// RVA : 0x009928B0
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __fastcall idSoundSystemLocal::ReleaseStreamBufferContext(
        idSoundSystemLocal *this,
        idMapChangeListener *bufferContext,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idMapChangeListener *a14)
{
  idSysMutex *p_streamBufferMutex; // r30

  a14 = bufferContext;
  if ( s_usePinning.valueInteger == 0 )
  {
    p_streamBufferMutex = &this->streamBufferMutex;
    Sys_MutexLock(handle: &this->streamBufferMutex.handle, blocking: true);
    if ( idList<void *,108>::RemoveFast(
           this: (idList<idMapChangeListener *,5> *)&this->activeStreamBufferContexts,
           obj: &a14) )
    {
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->freeStreamBufferContexts,
        obj: (const encounterGroupRole_t *)&a14);
    }
    else
    {
      idLib::Printf(fmt: "ReleaseStreamBuffer( 0x%p ) not on active list\n", bufferContext);
    }
    Sys_MutexUnlock(handle: &p_streamBufferMutex->handle);
  }
}


// ========================================================================
// ?AllocSoundWorld@idSoundSystemLocal@@UAAPAVidSoundWorld@@PBDPAVidRenderWorld@@@Z
// EA  : 0x82992950
// RVA : 0x00992950
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

idSoundWorldLocal *__fastcall idSoundSystemLocal::AllocSoundWorld(
        idSoundSystemLocal *this,
        const char *mapName,
        idRenderWorld *rw)
{
  idSoundWorldLocal *v6; // r3
  idSoundWorldLocal *v7; // r30
  idSoundWorldLocal *v9; // [sp+50h] [-40h] BYREF

  v6 = (idSoundWorldLocal *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x730u,
                              tag: TAG_SOUND,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  v9 = v6;
  if ( v6 != nullptr )
    v7 = idSoundWorldLocal::idSoundWorldLocal(this: v6);
  else
    v7 = nullptr;
  v9 = v7;
  idSoundWorldLocal::LoadMap(this: v7, mapName);
  v7->renderWorld = rw;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->soundWorlds,
    obj: (const encounterGroupRole_t *)&v9);
  return v7;
}


// ========================================================================
// __unwind$226221_0
// EA  : 0x829929DC
// RVA : 0x009929DC
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void _unwind_226221_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SOUND);
}


// ========================================================================
// `dynamic initializer for 's_noSound''
// EA  : 0x833608C8
// RVA : 0x013608C8
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_noSound__()
{
  idCVar::idCVar(
    this: &s_noSound,
    name: "s_noSound",
    value: "0",
    flags: 1,
    description: "returns NULL for all sounds loaded and does not update the sound rendering",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_noSound__);
}


// ========================================================================
// `dynamic initializer for 's_drawSounds''
// EA  : 0x83360920
// RVA : 0x01360920
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_drawSounds__()
{
  idCVar::idCVar(
    this: &s_drawSounds,
    name: "s_drawSounds",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueMin: 0.0,
    valueMax: 2.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))off_82010000,
    a9: (int)&loc_82660000,
    a10: (void (__fastcall *)(idAutoComplete *))idCmdSystem::ArgCompletion_Integer<0,2>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_drawSounds__);
}


// ========================================================================
// `dynamic initializer for 's_volume_dB''
// EA  : 0x83360988
// RVA : 0x01360988
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_volume_dB__()
{
  idCVar::idCVar(
    this: &s_volume_dB,
    name: "s_volume_dB",
    value: "0",
    flags: 4,
    description: "volume in dB",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_volume_dB__);
}


// ========================================================================
// `dynamic initializer for 's_useCompression''
// EA  : 0x833609E0
// RVA : 0x013609E0
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_useCompression__()
{
  idCVar::idCVar(
    this: &s_useCompression,
    name: "s_useCompression",
    value: "1",
    flags: 1,
    description: "Use compressed sound files (mp3/xma)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_useCompression__);
}


// ========================================================================
// `dynamic initializer for 's_playDefaultSound''
// EA  : 0x83360A38
// RVA : 0x01360A38
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_playDefaultSound__()
{
  idCVar::idCVar(
    this: &s_playDefaultSound,
    name: "s_playDefaultSound",
    value: "0",
    flags: 1,
    description: "play a beep for missing sounds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_playDefaultSound__);
}


// ========================================================================
// `dynamic initializer for 's_useStreaming''
// EA  : 0x83360A90
// RVA : 0x01360A90
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_useStreaming__()
{
  idCVar::idCVar(
    this: &s_useStreaming,
    name: "s_useStreaming",
    value: "1",
    flags: 2,
    description: "Enable sound streaming (requires s_useCompression)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_useStreaming__);
}


// ========================================================================
// `dynamic initializer for 's_useSoundThread''
// EA  : 0x83360AE8
// RVA : 0x01360AE8
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_useSoundThread__()
{
  idCVar::idCVar(
    this: &s_useSoundThread,
    name: "s_useSoundThread",
    value: "1",
    flags: 1,
    description: "Enable the sound thread",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_useSoundThread__);
}


// ========================================================================
// `dynamic initializer for 's_usePinning''
// EA  : 0x83360B40
// RVA : 0x01360B40
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_usePinning__()
{
  idCVar::idCVar(
    this: &s_usePinning,
    name: "s_usePinning",
    value: "0",
    flags: 1,
    description: "Use pinned cache lines for sample memory, only valid in production builds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_usePinning__);
}


// ========================================================================
// `dynamic initializer for 's_maxSamples''
// EA  : 0x83360B98
// RVA : 0x01360B98
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_maxSamples__()
{
  idCVar::idCVar(
    this: &s_maxSamples,
    name: "s_maxSamples",
    value: "0",
    flags: 2,
    description: "Max number of samples loaded per shader",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_maxSamples__);
}


// ========================================================================
// `dynamic initializer for 's_streamBufferSizeK''
// EA  : 0x83360BF0
// RVA : 0x01360BF0
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_streamBufferSizeK__()
{
  idCVar::idCVar(
    this: &s_streamBufferSizeK,
    name: "s_streamBufferSizeK",
    value: "32",
    flags: 2,
    description: "Size (in kb) of the temporary streaming buffers",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_streamBufferSizeK__);
}


// ========================================================================
// `dynamic initializer for 'soundSystemLocal''
// EA  : 0x83360C48
// RVA : 0x01360C48
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__soundSystemLocal__()
{
  idSoundSystemLocal::idSoundSystemLocal(this: &soundSystemLocal);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__soundSystemLocal__);
}


// ========================================================================
// `dynamic initializer for 'testWorldSound_v''
// EA  : 0x83360C80
// RVA : 0x01360C80
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__testWorldSound_v__()
{
  return idCommandLink::idCommandLink(
           this: &testWorldSound_v,
           cmdName: "testWorldSound",
           function: testWorldSound_f,
           description: "Play random postition sound",
           argCompletion: idDeclManager::ArgCompletion_Decl<idSoundShader>);
}


// ========================================================================
// `dynamic initializer for 'TestSWChannelList_v''
// EA  : 0x83360CB0
// RVA : 0x01360CB0
// PDB : w:\tech5\engine\sound\soundsystem.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestSWChannelList_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestSWChannelList_v,
           cmdName: "TestSWChannelList",
           function: TestSWChannelList_f,
           description: "Tests linked list of channels playing each shader",
           argCompletion: nullptr);
}

