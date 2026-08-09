#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aibehaviors.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16692; PDB kind: class.
class idAIBehaviors : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16693.
  virtual idTypeInfo *GetType();
  virtual ~idAIBehaviors();

  const idDeclAIBehavior *decl;
  const idDeclAIBehaviorVO *declBehaviorVo;
  const idDeclAIBehaviorVOChains *declBehaviorVoChains;
  const idDeclAIBehaviorEvents *declBehaviorEvents;
  const idDeclTrackingParms *aimTrackingParms;
  const idDeclTrackingParms *lookTrackingParms;
  float avoidRadius;
};
