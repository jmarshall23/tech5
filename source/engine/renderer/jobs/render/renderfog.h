#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\renderfog.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22924; PDB kind: struct.
struct renderFogParms_t
{
  const renderSettings_t *settings;
  const idRenderView *renderView;
  const idDeclRenderProg *progGlobalFog;
  const idTriangles *unitSquareTris;
};
