#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\cm\collisionqueryjobmanager.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23766; PDB kind: class.
class idCollisionQueryJobManager
{
public:
  idQueryData *queryData;
  queryResults_t *dummyQueryResults;
  int queryFrameNumber;
  int stalledFrameNumber;
  unsigned __int64 firstWaitTime;
  int numJobGroups;
  jobGroup_t *jobGroups;
  idParallelJobList *jobList;
  failedQuery_t failedQuery;
  profile_t threadProfile[8];
  profile_t translationProfile;
  profile_t rotationProfile;
  profile_t contentsProfile;
  profile_t contactsProfile;
  profile_t clipProfile;
};
