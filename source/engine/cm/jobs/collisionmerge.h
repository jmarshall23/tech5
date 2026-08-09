#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\cm\jobs\collisionmerge.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3237; PDB kind: enum.
enum collisionFeature_t : __int32
{
  COLLISION_FEATURE_INVALID = 0x0,
  COLLISION_FEATURE_VERTEX = 0x1,
  COLLISION_FEATURE_EDGE = 0x2,
  COLLISION_FEATURE_POLYGON = 0x3,
  COLLISION_FEATURE_POLYTOPE = 0x4,
};

// IDA Local Type ordinal 23756; PDB kind: class.
class idCollisionDetectionMerge
{
public:
};

// IDA Local Type ordinal 23757; PDB kind: struct.
struct idCollisionDetectionMerge::MergeContactsResults::__l2::contactGroup_t
{
  const contactInfo_t *contacts[12];
  int numContacts;
};
