#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\lobbycontroller.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1469; PDB kind: enum.
enum idLobbyController::skipVoteState_t : __int32
{
  SKIPVOTE_NONE = 0x0,
  SKIPVOTE_STARTED = 0x1,
  SKIPVOTE_PASSED = 0x2,
};

// IDA Local Type ordinal 1480; PDB kind: enum.
enum idLobbyController::state_t : __int32
{
  INTERMISSION = 0x1,
  FINAL_COUNTDOWN = 0x2,
  IN_GAME = 0x3,
};

// IDA Local Type ordinal 16068; PDB kind: class.
class __declspec(align(4)) idLobbyController::idCountdown
{
public:
  int intervalMs;
  int startMs;
  int pauseStartMs;
  int pauseAccumulationMs;
  bool isPaused;
};

// IDA Local Type ordinal 16070; PDB kind: class.
class __declspec(align(4)) idLobbyController
{
public:
  idLobbyController::state_t state;
  idLobbyController::idCountdown intermissionCountdown;
  idLobbyController::idCountdown finalCountdown;
  int nextPeerUpdateMs;
  idMainMenu *mainMenu;
  int serverRemainingSecUntilLaunch;
  int skipVotes;
  int skipVotesNeeded;
  int votePerPeer;
  int numPlayers;
  idLobbyController::skipVoteState_t skipVoteState;
  bool didVote;
};
