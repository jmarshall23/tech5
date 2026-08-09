#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\md6mesh.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13340; PDB kind: struct.
struct idMD6Mesh::vert_t
{
  idVec3 xyz;
  idVec2 st;
  idVec3 normal;
  idVec4 tangent;
  unsigned __int8 weights[4];
  unsigned __int8 jointIdxs[4];
};

// IDA Local Type ordinal 13343; PDB kind: struct.
struct idMD6Mesh::stset_t
{
  unsigned __int8 slot;
  idList<idVec2,5> st;
  idVertexBuffer *vb;
};

// IDA Local Type ordinal 13346; PDB kind: class.
class idMD6Mesh
{
public:
  idStr name;
  const idMaterial *material;
  bool discrete;
  bool allowSkinRemapping;
  int numTexCoordSets;
  idBounds bounds;
  int numVerts;
  int numTris;
  int jointOffset;
  int numJoints;
  int hashST;
  idList<unsigned char,5> morphMap;
  idTriangles *tris;
  idList<skinRemap_t,5> skinRemaps;
  idList<idMD6Mesh::vert_t,19> vertexes;
  idList<idMD6Mesh::stset_t,19> stSets;
  idList<unsigned short,19> indexes;
};
