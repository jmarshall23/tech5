#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\cover\coverquery.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 20503; PDB kind: class.
class idCoverQuery
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20506.
  virtual ~idCoverQuery();
  virtual void InternalPreScore();
  virtual void InternalSetupTarget(const idCoverQuery::coverTarget_t *);
  virtual float InternalScoreCover(const idCoverQuery::coverCache_t *);

  idAI2 *ai;
  idCoverQuery::coverTarget_t target;
  idAICover excludeCover;
  int debugLevel;
  int queryFlags;
  int minTravelTimeIndex;
  float minTravelTime;
  int maxTravelTimeIndex;
  float maxTravelTime;
  float travelTimeRange;
  idAASPosition aiaiPos;
  idAASPosition aivcPos;
  idList<idCoverQuery::coverCache_t,5> relevantCover;
};

// IDA Local Type ordinal 20504; PDB kind: struct.
const struct idCoverQuery::coverTarget_t
{
  idSpawnId spawnId;
  idVec3 origin;
  idVec3 eyePoint;
  idAASPosition aiPos;
  idAASPosition vcPos;
  int confirmedTime;
};

// IDA Local Type ordinal 20505; PDB kind: struct.
const struct idCoverQuery::coverCache_t
{
  int index;
  idAASPosition aiPos;
  idAASPosition vcPos;
  int vcAreaNum;
  idVec3 delta;
  float linearDistance;
  float travelTime;
  float score;
};
