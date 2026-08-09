#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sound\soundsystem.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18506; PDB kind: class.
class idSoundSystem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18507.
  virtual ~idSoundSystem();
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

};
