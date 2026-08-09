#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\renderlog.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 19083; PDB kind: struct.
struct idRenderLog::logStats_t
{
  unsigned __int64 startTiming;
  int startDraws;
  int startIndexes;
};

// IDA Local Type ordinal 19084; PDB kind: class.
class __declspec(align(8)) idRenderLog
{
public:
  int activeLevel;
  renderLogIndentLabel_t indentLabel[20];
  char indentString[80];
  int indentLevel;
  renderLogMainBlock_t lastMainBlock;
  _iobuf *logFile;
  unsigned __int64 frameStartTime;
  unsigned __int64 closeBlockTime;
  idRenderLog::logStats_t logStats[20];
  int logLevel;
};
