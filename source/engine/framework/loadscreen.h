#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\loadscreen.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22496; PDB kind: class.
class idLoadScreenInfo
{
public:
  idStr varName;
  idStr value;
};

// IDA Local Type ordinal 23597; PDB kind: class.
class __declspec(align(2)) idLoadScreenThread : public idSysThread
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23598.
  virtual ~idLoadScreenThread();
  virtual int Run();

  bool initialized;
  volatile bool stopRunning;
  volatile bool isRunning;
};

// IDA Local Type ordinal 23599; PDB kind: class.
class idLoadScreen
{
public:
  idLoadScreenThread *thread;
  idSWF *loadingGui;
  idRenderModelGui *guiModel;
};

// IDA Local Type ordinal 23600; PDB kind: class.
class idLoadScreenInfo2
{
public:
  idStr varName;
  idStr value;
};
