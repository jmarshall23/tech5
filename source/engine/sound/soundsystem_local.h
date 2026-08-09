#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sound\soundsystem_local.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22685; PDB kind: struct.
struct idSoundSystemLocal::bufferContext_t
{
  idSoundVoice_XAudio2 *voice;
  void *buffer;
  unsigned int sampleRate;
};

// IDA Local Type ordinal 22692; PDB kind: class.
class idSoundSystemLocal : public idSoundSystem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22693.
  virtual ~idSoundSystemLocal();
  virtual void Init();
  virtual void Shutdown();
  virtual idSoundWorld *AllocSoundWorld(const char *, idRenderWorld *);
  virtual void FreeSoundWorld(idSoundWorld *);
  virtual void SetPlayingSoundWorld(idSoundWorld *);
  virtual idSoundWorld *GetPlayingSoundWorld();
  virtual void SetEditorSoundWorld(idSoundWorld *);
  virtual idSoundWorld *GetEditorSoundWorld();
  virtual void Render(bool);
  virtual void WaitForSoundThread();
  virtual void MuteBackgroundMusic(bool);
  virtual void SetMute(bool);
  virtual bool IsMuted();
  virtual void OnReloadSound(const idDecl *);
  virtual void StopAllSounds();
  virtual void InitStreamBuffers();
  virtual void FreeStreamBuffers();
  virtual void *GetIXAudio2();
  virtual int GetNumSpeakers();
  virtual int GetSpeakerMask();

  idSysMutex streamBufferMutex;
  int soundTime;
  idSoundWorldLocal *editorSoundWorld;
  idSoundWorldLocal *currentSoundWorld;
  idStaticList<idSoundWorldLocal *,32> soundWorlds;
  idSoundHardware hardware;
  idStaticList<idSoundSystemLocal::bufferContext_t *,144> freeStreamBufferContexts;
  idStaticList<idSoundSystemLocal::bufferContext_t *,144> activeStreamBufferContexts;
  idStaticList<idSoundSystemLocal::bufferContext_t,144> bufferContexts;
  idRandom2 random;
  bool muted;
  bool musicMuted;
  bool needsRestart;
  bool soundThreadRunning;
  idSoundThread *soundThread;
  idParallelJobList *parallelJobList;
};
