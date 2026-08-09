#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\lbcache.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16063; PDB kind: class.
class idLBCache
{
public:
  idLBRowBlock rowBlocks[5];
  const leaderboardDefinition_t *def;
  leaderboardFilterMode_t filter;
  const leaderboardDefinition_t *pendingDef;
  leaderboardFilterMode_t pendingFilter;
  bool requestingRows;
  bool loadingNewLeaderboard;
  int numRowsInLeaderboard;
  int entryIndex;
  int rowOffset;
  int localIndex;
  leaderboardDisplayError_t errorCode;
};
