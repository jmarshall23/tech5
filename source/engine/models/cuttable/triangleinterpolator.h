#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\cuttable\triangleinterpolator.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15899; PDB kind: struct.
struct idTriangleInterpolator::Triangle_t
{
  idVec2 xy;
  idVec2 st[2];
  idVec2 st0[2];
  idVec2 st1[2];
  idVec2 v0;
  idVec2 v1;
  float d00;
  float d01;
  float d11;
  float invDenom;
  float invArea;
  unsigned int c0;
  unsigned int c1;
  unsigned int c2;
};

// IDA Local Type ordinal 15901; PDB kind: class.
class __declspec(align(16)) idTriangleInterpolator
{
public:
  idList<idTriangleInterpolator::Triangle_t,5> triangles;
  idDrawVert refVert;
  idVec3 refNormal;
  idVec3 refLeft;
  idVec3 refDown;
};
