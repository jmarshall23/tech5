#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\splines\navsplinegraph.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15675; PDB kind: class.
class idNavSplineGraph : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15676.
  virtual idTypeInfo *GetType();
  virtual ~idNavSplineGraph();

  idStaticList<navSplinePathNode_t,180> nodes;
  idList<navSplinePathNode_t,5> nodes_BuildGame;
  navSplinePathNode_t tempNode[2];
  navSplineType_t navSplineType;
};
