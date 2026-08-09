#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\physics\tracemodelrecycler.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14127; PDB kind: class.
class idTraceModelRecycler
{
public:
  idBlockAlloc<idRecycledTraceModel,64,13> allocator;
  idList<idRecycledTraceModel *,13> allocated;
  idList<idRecycledTraceModel *,13> free[3];
};

// IDA Local Type ordinal 14150; PDB kind: struct.
struct idFXModelRecycler::fxPrtModel_t
{
  idRenderModelParticle *pmodel;
  const idDeclParticle *pDecl;
};

// IDA Local Type ordinal 14153; PDB kind: struct.
struct idFXModelRecycler::fxStaticModel_t
{
  idRenderModel *rmodel;
  idAtomicString modelName;
};

// IDA Local Type ordinal 14156; PDB kind: class.
class idFXModelRecycler
{
public:
  idStaticList<idFXModelRecycler::fxPrtModel_t,256> fxPrtModels;
  idHashIndex activePrtModelHash;
  idHashIndex inactivePrtModelHash;
  idStaticList<idFXModelRecycler::fxStaticModel_t,64> fxStaticModels;
  idHashIndex activeStaticModelHash;
  idHashIndex inactiveStaticModelHash;
};
