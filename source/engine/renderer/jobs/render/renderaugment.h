#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\renderaugment.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22926; PDB kind: struct.
struct renderAugmentParms_t
{
  const renderSettings_t *settings;
  const idRenderView *renderView;
  const idRenderModelCommitted **viewAugmentModels;
  int numViewAugmentModels;
  const idDeclRenderProg *progColorParmOnly;
  const idRenderDestination *renderDestDefault;
  const idRenderDestination *renderDestAugment;
};

// IDA Local Type ordinal 23652; PDB kind: class.
class idRenderBumpClient
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23653.
  virtual void Start();
  virtual void Stop();
  virtual void QueueScanLine(const int);
  virtual void GetCompletedScanLines(struct idList<idCloudRenderBumpCmd,5> *);
  virtual void UpdateParms(const idRbParms *);

};
