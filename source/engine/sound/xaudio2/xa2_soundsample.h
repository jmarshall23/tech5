#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sound\xaudio2\xa2_soundsample.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13507; PDB kind: class.
class idSoundSample : public idSoundSample_XAudio2
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13508.
  virtual ~idSoundSample();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

};
