#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\development\cpugen\radpreview.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23673; PDB kind: class.
class idRadPreview
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23676.
  virtual ~idRadPreview();
  virtual bool Start(idRadPreviewToolIface *, const idStr *);
  virtual void Stop();
  virtual void Update();
  virtual void SignalWorldChanged(int);
  virtual void Pause(bool);
  virtual void Unpause();
  virtual void RebuildGeometry();

};
