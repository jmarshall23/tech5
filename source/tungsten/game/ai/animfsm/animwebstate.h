#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\animfsm\animwebstate.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15099; PDB kind: class.
class idAnimWebState
{
public:
  const idDeclAnimWeb *owner;
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> subweb;
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> state;
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> node;
  bool pathConstructed;
  idAtomicString debugSubweb;
  idAtomicString debugState;
};

// IDA Local Type ordinal 21384; PDB kind: class.
class idAnimWebState_Current : public idAnimWebState
{
public:
};
