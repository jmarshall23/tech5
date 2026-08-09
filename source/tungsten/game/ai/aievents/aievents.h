#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aievents\aievents.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13382; PDB kind: class.
class idAnimEvents
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13383.
  virtual ~idAnimEvents();

  idList<idAnimEvents::animEventInfo_t,28> list;
  idHashIndex hashIndex;
};

// IDA Local Type ordinal 13390; PDB kind: struct.
struct idAnimEvents::animEventInfo_t
{
  idAtomicStringT<enum md6AnimAtomicString_t> animRef;
  idList<idMD6AnimEvent,28> events;
};
