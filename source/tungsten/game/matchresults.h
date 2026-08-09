#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\matchresults.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3762; PDB kind: typedef.
typedef LONG HRESULT;

// IDA Local Type ordinal 18369; PDB kind: class.
class idMatchResults
{
public:
  int playerId;
  lobbyUserID_t lobbyUserID;
  int xpGained;
  int totalXp;
  int xpToNextLevel;
  int levelsGained;
  int cashGained;
  int score;
  int matchTime;
  idList<idPair<int,int>,5> accoladesEarned;
  idList<int,5> itemsUnlocked;
  int matchMapIndex;
  int matchModeIndex;
  bool shouldShowMatchResults;
  int challengeMode;
  int statValues[7];
  float miles;
  int screenMode;
};
