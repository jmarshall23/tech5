#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\entityanimrecorder.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1937; PDB kind: enum.
enum idEntityAnimRecorder::blockType_t : __int32
{
  ENTITY_BLOCK = 0x3,
  ENTITY_HEADER_BLOCK = 0x4,
  ENTITY_END_BLOCK = 0x5,
};

// IDA Local Type ordinal 19923; PDB kind: class.
class idEntityAnimRecorder : public idAnimRecorder
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19924.
  virtual void Serialize(int *, idGameTimeManager *, const bool);
  virtual void Stop();
  virtual void ReadFrames(int);
  virtual ~idEntityAnimRecorder();
  virtual void WriteHeaderBlock();
  virtual bool ReadHeaderBlock();

  idQuat orientation;
  idVec3 position;
  int activeEntityNumber;
  idEntity *activeEntity;
};
