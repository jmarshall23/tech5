#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\md6skel.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3100; PDB kind: enum.
enum idMD6Skel::GetJointList::__l2::jointOp_t : __int32
{
  JOINTOP_INCLUDE_CHILDREN = 0x1,
  JOINTOP_SUBTRACT = 0x2,
};

// IDA Local Type ordinal 13360; PDB kind: class.
class idMD6Skel : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13361.
  virtual ~idMD6Skel();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  const idMD6Anim *defaultAnim;
  idMD6SkelData *data;
  unsigned int timestamp;
  idHandle<unsigned short,enum invalidJointConversionHandle_t,65535> jointConversion;
  idHandle<unsigned short,enum invalidCrc_t,65535> jointConversionChecksum;
};
