#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\animstack\animweb\animwebblendtree.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15072; PDB kind: class.
class idAnimWebBlendTree
{
public:
  idMD6Node *tree;
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> nodeIndex;
  __int16 modelIndex;
  idAnimator_AnimWeb *web;
  idList<idAnimWebScalarPair,33> scalarPairs;
  idList<idMD6LeafPlay const *,33> leaves;
};
