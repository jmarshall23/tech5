#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\guis\swf\swf_shapeparser.h
// Recovered logical types: 7
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14901; PDB kind: class.
class idSWFShape
{
public:
  swfRect_t startBounds;
  swfRect_t endBounds;
  idList<idSWFShapeDrawFill,72> fillDraws;
  idList<idSWFShapeDrawLine,72> lineDraws;
};

// IDA Local Type ordinal 21586; PDB kind: struct.
struct idSWFShapeParser::swfSPEdge_t
{
  unsigned __int16 v0;
  unsigned __int16 v1;
  unsigned __int16 cp;
};

// IDA Local Type ordinal 21587; PDB kind: struct.
struct idSWFShapeParser::swfSPMorphEdge_t
{
  idSWFShapeParser::swfSPEdge_t start;
  idSWFShapeParser::swfSPEdge_t end;
};

// IDA Local Type ordinal 21589; PDB kind: struct.
struct idSWFShapeParser::swfSPLineLoop_t
{
  bool hole;
  idList<unsigned short,72> vindex1;
  idList<unsigned short,72> vindex2;
};

// IDA Local Type ordinal 21591; PDB kind: struct.
struct idSWFShapeParser::swfSPDrawFill_t
{
  swfFillStyle_t style;
  idList<idSWFShapeParser::swfSPMorphEdge_t,72> edges;
  idList<idSWFShapeParser::swfSPLineLoop_t,72> loops;
};

// IDA Local Type ordinal 21593; PDB kind: struct.
struct idSWFShapeParser::swfSPDrawLine_t
{
  swfLineStyle_t style;
  idList<idSWFShapeParser::swfSPMorphEdge_t,72> edges;
};

// IDA Local Type ordinal 21595; PDB kind: class.
class idSWFShapeParser
{
public:
  bool extendedCount;
  bool rgba;
  bool morph;
  bool lineStyle2;
  idList<idVec2,72> verts;
  idList<idSWFShapeParser::swfSPDrawFill_t,72> fillDraws;
  idList<idSWFShapeParser::swfSPDrawLine_t,72> lineDraws;
};
