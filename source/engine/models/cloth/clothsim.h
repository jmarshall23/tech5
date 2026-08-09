#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\cloth\clothsim.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15216; PDB kind: class.
class idClothSim
{
public:
  const idDeclCloth *clothDecl;
  int width;
  int height;
  float hSpacing;
  float vSpacing;
  idVec3 origin;
  idMat3 axis;
  idVec3 windDirection;
  idVec3 gravity;
  int numIterations;
  float timeDelta;
  idClothParticle *cloth;
  int numClothParticles;
  int currentDeferred;
  idBounds *clothBoundsFromJob;
  idBounds clothBounds;
  clothParms_t *clothParms;
  bool isRect;
  idList<idClothSpring,81> springs;
  idList<idSphere,81> permanentCollisionSpheres;
  idList<idSphere,81> temporaryCollisionSpheres[2];
  idList<clothWeaponTrace_t,81> weaponTraces[2];
  idPlane collisionPlane[2];
};
