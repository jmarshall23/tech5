#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\renderdynamicenv.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22917; PDB kind: struct.
struct renderDynamicEnvParms_t
{
  const renderSettings_t *settings;
  const idRenderView *renderView;
  const idDeclRenderParm *rpEnvBlendMip;
  const idDeclRenderParm *rpAmbientEnvMap;
  const idDeclRenderParm *rpUserEnvMap;
  const idDeclRenderParm *rpColor;
  const idDeclRenderParm *rpEnvSMatrix;
  const idDeclRenderParm *rpEnvTMatrix;
  const idDeclRenderParm *rpEnvRMatrix;
  const idRenderDestination *renderDestDynamicEnv;
  const idImage *imgDynamicEnv;
  const idImage *imgAmbientEnv;
  const idImage *imgUserEnv;
  const idTriangles *unitCubeTris;
  const idDeclRenderProg *progBlend;
  idMat3 envMapRotation;
  envBlend_t *envBlend;
};
