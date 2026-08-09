#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sound\soundbspfile.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13707; PDB kind: class.
class idSoundBSPFile
{
public:
  idList<idPlane,39> planes;
  idList<idVec3,39> vertices;
  idList<int,39> vertIndex;
  idList<sbspFace_t,39> faces;
  idList<int,39> faceIndex;
  idList<sbspArea_t,39> areas;
  idList<sbspNode_t,39> nodes;
  int numEnvironments;
  int numDoors;
  flatSoundBSP_t flatBSP;
};
