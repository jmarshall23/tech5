#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\transparency\jobs\influencespherecull.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13544; PDB kind: struct.
struct influenceSphereCullParms_t
{
  float nearDist;
  float farDist;
  idVec2 fov;
  idVec3 viewOrg;
  idVec3 viewFwd;
  idVec3 viewLeft;
  idVec3 viewUp;
  const influenceSphere_t *influenceSpheres;
  int numInfluenceSpheres;
  visibleInfluenceSpheres_t *visibleInfluenceSpheres;
};
