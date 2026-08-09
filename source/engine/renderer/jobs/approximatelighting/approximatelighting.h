#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\approximatelighting\approximatelighting.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13633; PDB kind: struct.
struct approximateLighting_t
{
  idVec4 primeLightDir;
  idVec4 primeLightColor;
  idVec4 channelLighting[6];
  idVec4 lightingModel;
};

// IDA Local Type ordinal 13635; PDB kind: struct.
struct approximateLightingParms_t
{
  approximateLighting_t *lighting;
  lightContribution_t *contributions;
  const ambientMap_t *ambientMap;
  const shadowMap_t *shadowMap;
  const idRenderLightCommitted **lights;
  int numLights;
  idVec3 samplePoint;
  lightingModel_t lightingModel;
  bool noAmbient;
  bool noApproximateLighting;
  bool privateLightOnly;
  bool unused_padding_byte_1;
  float ambientChannelScale;
  float directChannelScale;
  float primeLightScale;
  float dynamicLightingScale;
  float dimShadowHeightTweak;
};
