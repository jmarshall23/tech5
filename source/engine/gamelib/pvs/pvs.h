#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\pvs\pvs.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14174; PDB kind: class.
class __declspec(align(4)) idPVS
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14175.
  virtual ~idPVS();

  idPVS::header_t header;
  idStr pvsName;
  unsigned __int8 *dataStart;
  idPlane *planes;
  idVec3 *vertices;
  pvsNode_t *nodes;
  pvsPortal_t *portals;
  pvsArea_t *areas;
  int *areaOffsets;
  unsigned __int8 *areaPVS;
  pvsCurrent_t currentPVS[8];
  bool bare;
};

// IDA Local Type ordinal 14176; PDB kind: struct.
struct idPVS::header_t
{
  int magic;
  int numPlanes;
  int numVertices;
  int numNodes;
  int numPortals;
  int numAreas;
  int numPVSBytes;
};
