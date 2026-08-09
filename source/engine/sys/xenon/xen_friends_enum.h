#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sys\xenon\xen_friends_enum.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22504; PDB kind: class.
class idFriendsEnum : public OverlappedOperation
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22505.
  virtual ~idFriendsEnum();
  virtual void OnCompleted();
  virtual void OnFailed();

  void *resultsEnum;
  unsigned __int8 *resultsBuffer;
};
