#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\components\clothcomponent.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15217; PDB kind: class.
class __declspec(align(4)) idClothComponent
{
public:
  const idDeclCloth *clothDecl;
  idDeclEntityDef *gibEntity;
  idAnimatedEntity *animatedEntity;
  idClothSim *clothSim;
  bool isDetached;
};
