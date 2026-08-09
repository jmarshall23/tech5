#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\md6blockalloc.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14278; PDB kind: class.
class idMD6BlockAlloc : public idMD6Allocator
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14279.
  virtual ~idMD6BlockAlloc();
  virtual idMD6Node *Alloc(const idMD6Node::nodeType_t);
  virtual void Free(idMD6Node *);
  virtual void Condense();
  virtual unsigned int Size();
  virtual int NumNodes();
  virtual idMD6Node *NodeForIndex(const int);
  virtual const idMD6Node *NodeForIndex_2(const int);

  idBlockAlloc<idMD6LeafPlay,32,18> playLeaves;
  idBlockAlloc<idMD6LeafPause,4,18> pauseLeaves;
  idBlockAlloc<idMD6Branch,16,18> branches;
  idBlockAlloc<idMD6BlendBranch,16,18> blendBranches;
  idBlockAlloc<idMD6BlendAdditiveBranch,16,18> blendAdditiveBranches;
  idBlockAlloc<idMD6FusionBranch,16,18> fusionBranches;
  idBlockAlloc<idMD6BestLeaf,16,18> bestLeaves;
  idBlockAlloc<idMD6TagFilter,16,18> tagFilters;
  idList<idMD6Node *,18> nodes;
  idList<idMD6Node *,18> nodesToDelete;
};
