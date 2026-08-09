#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\aas2\deferredviscache.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17280; PDB kind: class.
class __declspec(align(4)) idDeferredVisCache
{
public:
  idList<idDeferredVisQuery *,106> hashTable;
  idList<idClipQuery,106> clipQueries;
  int curClipQueryIdx;
  deferredVisList_t leastRecentlyUsedList;
  deferredVisList_t priorityList;
  idClip *clip;
  idDeferredVisQuery *queryList;
  idDeferredVisQuery *queryPool;
  int expiredIndex;
  int numFrames;
  int numCreatedThisFrame;
  int numBumped;
  int numQueriesIssued;
  int totalQueriesIssued;
  int numPurged;
  int numExpired;
  int numCacheHits;
  int totalCacheHits;
  int maxCreatedInAFrame;
  int recentNumFrames;
  int recentTotalCacheHits;
  int recentTotalQueriesIssued;
  float recentCacheHitRatio;
  float recentAvgHitRatio;
  bool initialized;
  bool alreadyWarned;
};
