#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\development\cpugen\genmodel.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 21708; PDB kind: class.
class idGenModelSurf
{
public:
  idList<genVert_t,5> verts;
  idList<genTri_t,5> tris;
  idBounds bounds;
  const idMaterial *material;
  const idMaterial *mappingMaterial;
  genModelSurfParms_t parms;
  int materialNum;
  int basePoseVertexMask;
};

// IDA Local Type ordinal 21710; PDB kind: class.
class idGenModel
{
public:
  idStr path;
  unsigned int timestamp;
  idList<idGenModelSurf *,5> surfaces;
  idList<idStr,5> binaryModelNames;
  idBounds bounds;
  idBounds staticBounds;
};

// IDA Local Type ordinal 23777; PDB kind: class.
class idGenGridModel
{
public:
  idList<unsigned short,5> indices;
  idList<idVec3,5> vertices;
  idList<cm_edge_t,5> edges;
  idList<unsigned short,5> polygonEdges;
  idList<cm_polygon_t,5> polygons;
  idList<cm_gridPart_t,5> parts;
  idList<cm_gridNodeBSP_t,5> nodes;
  int numX;
  int numY;
  idVec2i offset;
  int dimension;
};
