#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\renderthread.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 19100; PDB kind: class.
class __declspec(align(4)) idRenderThread : public idSysThread
{
public:
  // Recovered virtual interface; IDA vtable ordinal 19101.
  virtual ~idRenderThread();
  virtual int Run();

  void *hdc;
  renderMode_t renderMode;
  renderMode_t renderModeBeforeSync;
  bool initialized;
};
