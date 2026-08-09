#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\testentities.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16033; PDB kind: class.
class idEditEntities
{
public:
  int nextSelectTime;
  bool lastSelectResult;
  idList<idSelectedTypeInfo,5> selectableEntityClasses;
  idList<idEntity *,5> selectedEntities;
  bool dragging;
  int dragTime;
  int dragAxis;
  idVec3 lastViewDir;
  idVec3 lastDragPos;
};
