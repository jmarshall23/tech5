#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\jobutils.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18060; PDB kind: class.
class idJobUtils
{
public:
  ju_Language_t language;
  idList<idVoiceRecord,5> records;
  idList<idVORecord,5> vos;
  idList<idVoiceRecordMergeVO,5> mergeVOsList;
};
