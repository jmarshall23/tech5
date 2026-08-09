#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\cm\collisionmodelbuilder.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23795; PDB kind: class.
class idCollisionModelBuilder::idStaticModelGeometry
{
public:
  const idStaticModel *staticModel;
  const idMapModel *mapModel;
  const idRenderModel *renderModel;
  idList<int,13> primitiveGroupNumbers;
  idVec3 origin;
  idMat3 axis;
  idVec3 scale;
  const idMaterial *overrideClipMaterial;
};

// IDA Local Type ordinal 23797; PDB kind: class.
class idCollisionModelBuilder
{
public:
};

// IDA Local Type ordinal 23798; PDB kind: class.
class idCollisionModelBuilder::idCollisionModelGeometry
{
public:
  idCollisionModelLocal *collisionModel;
  idStr modelName;
  unsigned int fileTime;
  bool isWorldEntity;
  bool isStreamed;
  bool isStreamArea;
  bool allowDiscrete;
  idVec3 streamVolumeOrigin;
  idMat3 streamVolumeAxis;
  idList<idCollisionModelBuilder::idStaticModelGeometry,13> models;
};
