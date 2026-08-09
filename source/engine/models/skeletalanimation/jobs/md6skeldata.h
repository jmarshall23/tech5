#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\jobs\md6skeldata.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13359; PDB kind: class.
class idMD6SkelData
{
public:
  unsigned __int16 size;
  unsigned __int16 numJoints;
  unsigned __int16 numUserChannels;
  idHandle<unsigned short,enum invalidCrc_t,65535> parentTblCrc;
  unsigned __int16 basePoseOffset;
  unsigned __int16 inverseBasePoseOffset;
  unsigned __int16 inverseBasePoseQuatOffset;
  unsigned __int16 parentTblOffset;
  unsigned __int16 jointHandleTblOffset;
  unsigned __int16 userChannelHandleTblOffset;
  unsigned __int16 jointWeightOffsets[8];
  unsigned __int16 userWeightOffsets[8];
  unsigned __int8 pad[12];
};
