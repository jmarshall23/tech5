#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effects\gamelibeffects.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14163; PDB kind: class.
class __declspec(align(4)) idGameLibEffects
{
public:
  idRenderModelEffects *effectsModel;
  idRenderModelDecal *decalModel;
  idRenderModelBeam *beamModel;
  idEffectsModelManager effectsModelManager;
  idDeferredDecalManager deferredDecalManager;
  idRibbonModelManager ribbonModelManager;
  idWeaponTraceManager weaponTraceManager;
  idFXModelRecycler fxModelRecycler;
  idImpactManager weaponImpactManager;
  idImpactManager impactManager;
  bool initialized;
};
