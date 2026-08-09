#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\debuggraph.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1355; PDB kind: enum.
enum idDebugGraph::fillMode_t : __int32
{
  GRAPH_LINE = 0x0,
  GRAPH_FILL = 0x1,
  GRAPH_FILL_REVERSE = 0x2,
};

// IDA Local Type ordinal 2620; PDB kind: enum.
enum idDebugGraph::captionPos_t : __int32
{
  CAP_NONE = 0x0,
  CAP_LEFT = 0x1,
  CAP_RIGHT = 0x2,
  CAP_TOP = 0x3,
  CAP_BOTTOM = 0x4,
};

// IDA Local Type ordinal 17644; PDB kind: struct.
struct idDebugGraph::graphPlot_t
{
  float value;
  idColor color;
};

// IDA Local Type ordinal 17647; PDB kind: class.
class idDebugGraph
{
public:
  const idMaterial *white;
  idColor bgColor;
  idColor fontColor;
  idDebugGraph::fillMode_t mode;
  bool sideways;
  float border;
  idVec4 position;
  bool enable;
  bool clamp;
  idStr caption;
  idDebugGraph::captionPos_t capPos;
  idList<idDebugGraph::graphPlot_t,3> bars;
  idList<idDebugGraph::graphPlot_t,3> grid;
  idList<idStr,3> labels;
};
