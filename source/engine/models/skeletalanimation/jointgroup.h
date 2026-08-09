#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\jointgroup.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1632; PDB kind: enum.
enum idJointGroup::jointGroup_t : __int32
{
  JOINTGROUP_DAMAGE = 0x0,
  JOINTGROUP_PAIN = 0x1,
  JOINTGROUP_TWITCH = 0x2,
  JOINTGROUP_DEATH = 0x3,
  JOINTGROUP_LIMBLOSS = 0x4,
  JOINTGROUP_HEADTRACKING = 0x5,
  JOINTGROUP_FOCUS = 0x6,
  JOINTGROUP_ORIENTATION = 0x7,
  JOINTGROUP_HITTEST = 0x8,
  JOINTGROUP_EYES = 0x9,
  JOINTGROUP_FEET = 0xA,
  JOINTGROUP_BOUNDS = 0xB,
  JOINTGROUP_MAX = 0xC,
};

// IDA Local Type ordinal 13370; PDB kind: struct.
struct __declspec(align(4)) idJointGroup::jointGroupArgs_t
{
  int surfType;
  bool active;
};

// IDA Local Type ordinal 13372; PDB kind: class.
class idJointGroup
{
public:
  idJointGroup::jointGroup_t type;
  idAtomicString groupName;
  idList<idIndex<short,enum invalidJointIndex_t>,30> joints;
  idList<idVec3,30> jointOffsets;
  idList<float,30> jointScalars;
  idJointGroup::jointGroupArgs_t args;
  idVec3 groupOffset;
  idHandle<int,enum invalidJointGroupHandle,0> handle;
};

// IDA Local Type ordinal 31142; PDB kind: typedef.
typedef idHandle<int,enum invalidJointGroupHandle,0> jointGroupHandle_t;
