#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\splines\navsplinepathpos.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15653; PDB kind: struct.
struct navSplinePathNode_t
{
  idVec3 position;
  idStaticList<navSplineLink_t,16> links;
  int index;
  navSplinePathNode_t::navSplineSearch_t search;
};

// IDA Local Type ordinal 15657; PDB kind: struct.
struct navSplinePathNode_t::navSplineSearch_t
{
  float distance;
  navSplinePathNode_t *parent;
  idNavSpline *spline;
};
