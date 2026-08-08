
// ========================================================================
// ??0idSoundSystemLocal@@QAA@XZ
// EA  : 0x82992D38
// RVA : 0x00992D38
// PDB : w:\tech5\engine\sound\soundsystem_local.h
// ========================================================================

idSoundSystemLocal *__fastcall idSoundSystemLocal::idSoundSystemLocal(idSoundSystemLocal *this)
{
  int v2; // ctr
  __int16 *p_granularity; // r11

  this->__vftable = (idSoundSystemLocal_vtbl *)&idSoundSystemLocal::`vftable';
  Sys_MutexCreate(handle: &this->streamBufferMutex.handle);
  this->soundTime = 0;
  this->editorSoundWorld = nullptr;
  this->currentSoundWorld = nullptr;
  this->soundWorlds.size = 32;
  this->soundWorlds.num = 0;
  this->soundWorlds.granularity = 1;
  this->soundWorlds.list = this->soundWorlds.staticList;
  this->soundWorlds.memTag = 5;
  this->soundWorlds.listStatic = 1;
  idSoundHardware_XAudio2::idSoundHardware_XAudio2(this: &this->hardware);
  this->freeStreamBufferContexts.size = 144;
  this->freeStreamBufferContexts.num = 0;
  this->freeStreamBufferContexts.granularity = 1;
  this->freeStreamBufferContexts.list = this->freeStreamBufferContexts.staticList;
  v2 = 144;
  this->freeStreamBufferContexts.memTag = 5;
  this->freeStreamBufferContexts.listStatic = 1;
  this->activeStreamBufferContexts.size = 144;
  this->activeStreamBufferContexts.num = 0;
  this->activeStreamBufferContexts.granularity = 1;
  this->activeStreamBufferContexts.list = this->activeStreamBufferContexts.staticList;
  this->activeStreamBufferContexts.memTag = 5;
  this->activeStreamBufferContexts.listStatic = 1;
  this->bufferContexts.list = this->bufferContexts.staticList;
  p_granularity = &this->bufferContexts.granularity;
  this->bufferContexts.size = 144;
  this->bufferContexts.num = 0;
  this->bufferContexts.granularity = 1;
  this->bufferContexts.memTag = 5;
  this->bufferContexts.listStatic = 1;
  do
  {
    *((_DWORD *)p_granularity + 1) = 0;
    *((_DWORD *)p_granularity + 2) = 0;
    p_granularity += 6;
    *(_DWORD *)p_granularity = 0;
    --v2;
  }
  while ( v2 != 0 );
  this->random.seed = 0;
  this->muted = false;
  this->musicMuted = false;
  this->needsRestart = false;
  this->soundThreadRunning = false;
  this->soundThread = nullptr;
  this->parallelJobList = nullptr;
  return this;
}


// ========================================================================
// __unwind$226452
// EA  : 0x82992E90
// RVA : 0x00992E90
// PDB : w:\tech5\engine\sound\soundsystem_local.h
// ========================================================================

void _unwind_226452()
{
  int v0; // r12

  idSoundSystem::~idSoundSystem(this: *(idSoundSystem **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$226453
// EA  : 0x82992EB8
// RVA : 0x00992EB8
// PDB : w:\tech5\engine\sound\soundsystem_local.h
// ========================================================================

void _unwind_226453()
{
  int v0; // r12

  idSysMutex::~idSysMutex(this: (idSysMutex *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// __unwind$226454
// EA  : 0x82992EE4
// RVA : 0x00992EE4
// PDB : w:\tech5\engine\sound\soundsystem_local.h
// ========================================================================

void _unwind_226454()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 20));
}


// ========================================================================
// ?MuteBackgroundMusic@idSoundSystemLocal@@UAAX_N@Z
// EA  : 0x82992F10
// RVA : 0x00992F10
// PDB : w:\tech5\engine\sound\soundsystem_local.h
// ========================================================================

void __fastcall idSoundSystemLocal::MuteBackgroundMusic(idSoundSystemLocal *this, bool mute)
{
  this->musicMuted = mute;
}


// ========================================================================
// ?SetMute@idSoundSystemLocal@@UAAX_N@Z
// EA  : 0x82992F20
// RVA : 0x00992F20
// PDB : w:\tech5\engine\sound\soundsystem_local.h
// ========================================================================

void __fastcall idSoundSystemLocal::SetMute(idSoundSystemLocal *this, bool mute)
{
  this->muted = mute;
}


// ========================================================================
// ?IsMuted@idSoundSystemLocal@@UAA_NXZ
// EA  : 0x82992F30
// RVA : 0x00992F30
// PDB : w:\tech5\engine\sound\soundsystem_local.h
// ========================================================================

BOOL __fastcall idSoundSystemLocal::IsMuted(idSoundSystemLocal *this)
{
  return this->muted;
}

