#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\renderpostprocess.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22929; PDB kind: struct.
struct renderPostProcessParms_t
{
  const renderSettings_t *settings;
  const idRenderView *renderView;
  const idDeclRenderParm *rpViewColor;
  const idDeclRenderParm *rpGlareMap;
  const idDeclRenderParm *rpAdaptiveGlareMap;
  const idDeclRenderParm *rpAdaptiveGlareLuminance;
  const idDeclRenderParm *rpDistortionMap;
  const idDeclRenderParm *rpDepthOfField;
  const idDeclRenderParm *rpDepthOfField2;
  const idDeclRenderProg *progPostProcess;
  const idImage *imgViewColor;
  const idImage *imgGlare;
  const idImage *imgAdaptiveGlare;
  const idImage *imgAdaptiveGlareLuminance;
  const idImage *imgBlack;
  const idImage *imgDistortion;
  const idTriangles *unitSquareTris;
};
