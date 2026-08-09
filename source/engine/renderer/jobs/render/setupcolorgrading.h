#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\setupcolorgrading.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22913; PDB kind: struct.
struct setupColorGradingParms_t
{
  const idDeclRenderParm *rpCGShadow;
  const idDeclRenderParm *rpCGMidtone;
  const idDeclRenderParm *rpCGHighlight;
  const idDeclRenderParm *rpCGColorDodgeBlend;
  const idDeclRenderParm *rpCGColorBurnBlend;
  const idDeclRenderParm *rpCGColorMultiplyBlend;
  const idDeclRenderParm *rpCGColorScreenBlend;
  const idDeclRenderParm *rpCGBlackLevel;
  const idDeclRenderParm *rpColorGradingLUT;
  idImage *imageLUT;
};
