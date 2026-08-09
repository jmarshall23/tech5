#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\rageleaderboards.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2954; PDB kind: enum.
enum __bitmask idLeaderboards::state_t : __int32
{
  STATE_DOWNLOADING_FRIENDS = 0x1,
  STATE_DOWNLOAD_IN_FLIGHT = 0x2,
};

// IDA Local Type ordinal 18616; PDB kind: class.
class RageLeaderboardCallback : public idLeaderboardCallback
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18617.
  virtual ~RageLeaderboardCallback();
  virtual void Call();
  virtual idCallback *Clone();

};

// IDA Local Type ordinal 22577; PDB kind: class.
class __declspec(align(8)) idLeaderboards
{
public:
  idSessionLocal *sessionLocal;
  idLeaderboards::state_t state;
  unsigned __int64 friendsXuids[101];
  int numFriends;
  idFriendsEnum *inFlightFriendsEnum;
  idLeaderboardQuery *pendingDownload;
  idList<OverlappedOperation *,5> inFlightStats;
};
