#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\cm\jobs\polygonmodel\polygonmodel.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 20007; PDB kind: struct.
struct cm_polygonModel_t
{
  int numModelTreeNodes;
  int numSubModels;
  cm_modelTreeNode_t *modelTreeNodes;
  cm_subModel_t *subModels;
  volatile char *subModelState;
};
