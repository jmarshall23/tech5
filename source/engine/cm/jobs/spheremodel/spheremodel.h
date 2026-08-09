#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\cm\jobs\spheremodel\spheremodel.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 20008; PDB kind: struct.
struct cm_sphereModel_t
{
  unsigned int totalSize;
  unsigned int timeStamp;
  idBounds bounds;
  unsigned int contents;
  unsigned __int16 numModelJoints;
  unsigned __int16 numSpheres;
  unsigned __int16 jointOffset;
  unsigned __int16 offsetXOffset;
  unsigned __int16 offsetYOffset;
  unsigned __int16 offsetZOffset;
  unsigned __int16 radiusOffset;
  unsigned __int16 surfTypeOffset;
};

// IDA Local Type ordinal 20016; PDB kind: struct.
struct cm_sphereModelPtrs_t
{
  unsigned __int8 *joint;
  float *offsetX;
  float *offsetY;
  float *offsetZ;
  float *radius;
  unsigned __int8 *surfType;
};
