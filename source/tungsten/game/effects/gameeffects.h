#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\effects\gameeffects.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15191; PDB kind: class.
class __declspec(align(4)) idDamageEffect : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15192.
  virtual idTypeInfo *GetType();
  virtual ~idDamageEffect();

  const idDeclParticle *type;
  idDamageEffect *next;
  idVec3 localOrigin;
  idVec3 localNormal;
  int time;
  idIndex<short,enum invalidJointIndex_t> jointNum;
};
