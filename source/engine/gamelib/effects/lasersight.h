#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\effects\lasersight.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13817; PDB kind: struct.
struct laserSightInfo_t
{
  const idMaterial *laserBeamMtr;
  const idMaterial *laserDotMtr;
  float laserBeamHeight;
  float laserDotSize;
  float laserDotDepth;
  float laserDotMinSizeScale;
  float laserDotMaxSizeScale;
  bool laserDotQuad;
  float fadeIn;
  float fadeOut;
};

// IDA Local Type ordinal 14739; PDB kind: class.
class idLaserSight
{
public:
  bool initialized;
  bool hidden;
  idLaserBeam laserBeam;
  idLaserEndPoint laserEndPoint;
  idRenderModelBeam *beamEffects;
  idRenderModelDecal *decalEffects;
  float fadeInDuration;
  float fadeOutDuration;
};
