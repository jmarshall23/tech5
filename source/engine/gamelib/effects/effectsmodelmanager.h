#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effects\effectsmodelmanager.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14034; PDB kind: struct.
struct idEffectsModelManager::fxPrtModel_t
{
  idRenderModelParticle *pmodel;
  const idDeclParticle *pDecl;
};

// IDA Local Type ordinal 14037; PDB kind: class.
class idEffectsModelManager
{
public:
  idStaticList<idEffectsModelManager::fxPrtModel_t,400> fxPrtModels;
  idHashIndex activePrtModelHash;
  idHashIndex inactivePrtModelHash;
};
