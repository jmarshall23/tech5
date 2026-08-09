#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\voiceovers\voicetrack_events.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13892; PDB kind: class.
class __declspec(align(2)) idVoiceEvent
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13894.
  virtual ~idVoiceEvent();
  virtual const char *GetName();
  virtual float GetWeight(const int, const int);
  virtual bool IsInstantaneous();
  virtual bool IsWithinInterval(const int, const int);
  virtual void Write(const idVoiceTrack *, idFile_String *);
  virtual void Parse(idVoiceTrack *, idLexer *);
  virtual bool WriteBinary(idFile *);
  virtual bool LoadBinary(idFile *);
  virtual unsigned int Memory();

  int startMS;
  __int16 durationMS;
  unsigned __int8 eventType;
};
