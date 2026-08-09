#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effects\ribbonmanager.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14140; PDB kind: struct.
struct idRibbonModelManager::ribbonEffects_t
{
  idStaticList<idRibbon *,16> ribbons;
  int next;
};

// IDA Local Type ordinal 14143; PDB kind: class.
class idRibbonModelManager
{
public:
  idStaticList<idRibbonModelManager::ribbonEffects_t,4> ribbonEffects;
};

// IDA Local Type ordinal 14211; PDB kind: class.
class __declspec(align(4)) idRibbonManager
{
public:
  idRibbon *ribbon;
  const idDeclRibbon *ribbonDecl;
  idRenderModelBeam *beamModel;
  idRibbonModelManager *modelManager;
  bool isInitialized;
};
