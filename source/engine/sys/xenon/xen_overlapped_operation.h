#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sys\xenon\xen_overlapped_operation.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22502; PDB kind: class.
class OverlappedOperation
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22503.
  virtual ~OverlappedOperation();
  virtual void OnCompleted();
  virtual void OnFailed();

  _XOVERLAPPED overlapped;
};
