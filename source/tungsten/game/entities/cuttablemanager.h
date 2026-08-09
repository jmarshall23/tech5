#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\cuttablemanager.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17367; PDB kind: class.
class idCuttableManager
{
public:
  idList<cuttableInfo_t,5> infoCuttables;
  idList<idStr,5> nameCuttables;
  idList<idVertexBuffer *,5> vertexBuffers;
  idList<idVertexBuffer *,5> stBuffers;
  idList<idIndexBuffer *,5> indexBuffers;
  idEffectPhysicsCuttable effectPhysics;
  int freeBuffer;
};
