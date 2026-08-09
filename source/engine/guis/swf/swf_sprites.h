#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\guis\swf\swf_sprites.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14779; PDB kind: struct.
struct idSWFSprite::swfFrameLabel_t
{
  idAtomicString frameLabel;
  unsigned int frameNum;
};

// IDA Local Type ordinal 14782; PDB kind: struct.
struct idSWFSprite::swfSpriteCommand_t
{
  swfTag_t tag;
  idSWFBitStream stream;
};

// IDA Local Type ordinal 14785; PDB kind: class.
class idSWFSprite
{
public:
  idSWF *swf;
  unsigned __int16 frameCount;
  idList<unsigned int,72> frameOffsets;
  idList<idSWFSprite::swfFrameLabel_t,72> frameLabels;
  idList<idSWFSprite::swfSpriteCommand_t,72> commands;
  idList<idSWFBitStream,72> doInitActions;
  unsigned __int8 *commandBuffer;
};
