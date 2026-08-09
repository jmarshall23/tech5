#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\script\interpreter.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15108; PDB kind: class.
class idInterpreter
{
public:
  bool doneProcessing;
  bool threadDying;
  bool terminateOnExit;
  bool debug;
  idScriptStack localstack;
  int popParms;
  const idEventDef *multiFrameEvent;
  idEntity *eventEntity;
  idThread *thread;
};
