#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\cover\covercapabilities.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16660; PDB kind: class.
class __declspec(align(4)) idCoverCapabilities : public idCoverActions
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16661.
  virtual ~idCoverCapabilities();
  virtual void Clear();
  virtual bool HasCapability(const idCoverCapabilities *);
  virtual bool HasCapability_2(const idCoverActions *);

  unsigned __int8 : 1;
  __int8 hide : 1;
  __int8 peekOver : 1;
  __int8 peekRight : 1;
  __int8 peekLeft : 1;
  __int8 blindfireOver : 1;
  __int8 blindfireRight : 1;
  __int8 blindfireLeft : 1;
};

// IDA Local Type ordinal 16662; PDB kind: class.
class idAICoverCapabilities
{
public:
  idCoverCapabilities crouchCaps;
  idCoverCapabilities fullCaps;
};
