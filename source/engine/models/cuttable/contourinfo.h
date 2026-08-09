#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\cuttable\contourinfo.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15915; PDB kind: class.
class Contour
{
public:
  Contour *next;
  ContourEdge_t *edges;
  idBounds2D bound;
  int numEdges;
};

// IDA Local Type ordinal 15917; PDB kind: struct.
struct ContourNode_t
{
  ContourNode_t *next;
  idVec2i pos;
};
