#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\effects\influencetrail.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2025; PDB kind: enum.
enum invalidInfluenceTrail_t : __int32
{
  INVALID_INFLUENCE_TRAIL = 0xFFFFFFFF,
};

// IDA Local Type ordinal 13777; PDB kind: class.
#ifndef TUNGSTEN_ID_ENTITY_INFLUENCE_TRAIL_DEFINED
#define TUNGSTEN_ID_ENTITY_INFLUENCE_TRAIL_DEFINED
class idEntityInfluenceTrail
{
public:
  float innerRadius;
  float outerRadius;
  float angle;
  float trailDist;
  float trailFadeInTime;
  float trailFadeOutTime;
};
#endif

// IDA Local Type ordinal 15524; PDB kind: class.
class idInfluenceTrail::idInfluenceSphere
{
public:
  idVec3 center;
  int time;
};

// IDA Local Type ordinal 15526; PDB kind: class.
class idInfluenceTrail
{
public:
  bool active;
  float trailDist;
  float innerRadius;
  float outerRadius;
  float angle;
  int trailFadeInTime;
  int trailFadeOutTime;
  idVec3 position;
  idVec3 lastPosition;
  idList<idInfluenceTrail::idInfluenceSphere,5> trail;
  idPresentable *presentable;
  const idSoundShader *sndFoliage;
};

// IDA Local Type ordinal 15527; PDB kind: class.
class idInfluenceTrailManager : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15528.
  virtual idTypeInfo *GetType();
  virtual ~idInfluenceTrailManager();

  idInfluenceTrail influenceTrails[128];
};

// IDA Local Type ordinal 29177; PDB kind: typedef.
typedef idHandle<int,enum invalidInfluenceTrail_t,-1> idInfluenceTrailHandle;
