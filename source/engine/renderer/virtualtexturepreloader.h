#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\virtualtexturepreloader.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22774; PDB kind: class.
class __declspec(align(4)) idVirtualTexturePreloadThread : public idSysThread
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22775.
  virtual ~idVirtualTexturePreloadThread();
  virtual int Run();

  preloadCommand_t preloadCommands[8];
  preloadCommand_t *preloadCommandQueue[16];
  volatile int preloadCommandQueueStart;
  volatile int preloadCommandQueueEnd;
  int currentHandle;
  volatile bool endCalled;
  volatile bool cancelToTerminate;
};

// IDA Local Type ordinal 22776; PDB kind: class.
class __declspec(align(4)) idVirtualTexturePreloader
{
public:
  idVirtualTexturePreloadThread *thread;
  bool running;
};
