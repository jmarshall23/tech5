#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\libs\navpower\include\bfxnavigator.h
// Recovered logical types: 7
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2332; PDB kind: enum.
enum idNpNavigator::idAdvanceInfo::posType_t : __int32
{
  POS_SURFACE = 0x0,
  POS_LINK = 0x1,
  POS_GOAL = 0x2,
};

// IDA Local Type ordinal 18243; PDB kind: struct.
struct __declspec(align(4)) idNpNavigator::idNextCornerParms
{
  float pathDistance;
  bool addCornerAtEveryArea;
};

// IDA Local Type ordinal 18244; PDB kind: struct.
struct __declspec(align(4)) idNpNavigator::idNpAdvanceSpec
{
  float distAhead;
  bool stopAtLink;
};

// IDA Local Type ordinal 18245; PDB kind: struct.
struct __declspec(align(4)) idNpNavigator::idAdvanceInfo
{
  idNpNavigator::idAdvanceInfo::posType_t advancePosType;
  idVec3 advancePos;
  float advanceDistance;
  idNpAreaHandle advanceArea;
  idNpLink advanceLink;
  idNpMover::idLinkUseParms linkInfo;
  bool linkBackWards;
};

// IDA Local Type ordinal 18246; PDB kind: struct.
struct __declspec(align(4)) idNpNavigator::idPosDirectionInfo
{
  idVec3 endPos;
  idNpAreaHandle endArea;
  bool endOnEdge;
};

// IDA Local Type ordinal 18247; PDB kind: struct.
struct idNpNavigator::idNavWedge
{
  float angleStart;
  float angleEnd;
};

// IDA Local Type ordinal 18248; PDB kind: class.
class idNpNavigator
{
public:
  idNpNavigatorImpl *impl;
};
