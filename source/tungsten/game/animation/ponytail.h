#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\animation\ponytail.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16489; PDB kind: class.
class __declspec(align(4)) idPonytail
{
public:
  const idDeclPonytail *declPonytail;
  idEntityPtr<idEntity> parent;
  idAnimStack animStack;
  idHandle<int,enum invalidAttachment_t,-1> attachmentHandle;
  idAnimator_Ponytail ponytailAnimator;
  bool usingParentAnimStack;
  bool initialized;
};
