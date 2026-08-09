#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\userchannelexpression.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14060; PDB kind: class.
class idUserChannelExpression::VarId
{
public:
  int index;
};

// IDA Local Type ordinal 14064; PDB kind: class.
class idUserChannelExpression
{
public:
  idRuntimeExpression<idUserChannelExpression::VarId,idUserChannelExpression::VarContext> expr;
};

// IDA Local Type ordinal 21634; PDB kind: class.
class idUserChannelExpression::VarContext
{
public:
  const idDeclMD6 *decl;
  const float *channels;
  int numChannels;
};
