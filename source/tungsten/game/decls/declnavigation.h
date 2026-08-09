#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declnavigation.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2070; PDB kind: enum.
enum idDeclNavigation::navCategory_t : __int32
{
  NAVCAT_PLAYER = 0x0,
  NAVCAT_MONSTER = 0x1,
  NAVCAT_VEHICLE = 0x2,
  NAVCAT_MAX = 0x3,
};

// IDA Local Type ordinal 2071; PDB kind: enum.
enum idDeclNavigation::navGenType_t : __int32
{
  NAVGEN_2D_SURFACES = 0x0,
  NAVGEN_3D_VOLUMES = 0x1,
};

// IDA Local Type ordinal 16564; PDB kind: struct.
struct idDeclNavigation::coverSet_t
{
  idNavCoverInfo_t coverLow;
  idNavCoverInfo_t coverMid;
  idNavCoverInfo_t coverHigh;
};

// IDA Local Type ordinal 16565; PDB kind: class.
class idDeclNavigation : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16566.
  virtual ~idDeclNavigation();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();

  idDeclNavigation::navGenType_t navGenType;
  idDeclNavigation::navCategory_t navCategory;
  navLayer_t navLayer;
  idAtomicString fileExtensionNav;
  idAtomicString groupName;
  idAtomicString altGroupName;
  navCustomFlags_t includeSurfaceFlags;
  float voxelSize;
  float agentRadius;
  float agentHeight;
  float agentStepHeight;
  float agentWalkableSlope;
  float agentLedgeRadius;
  float verticalOffsetDist;
  float vertexSnap;
  float customMergeDistance;
  float additionalInwardsSmoothingDist;
  bool useEnhancedTerrainTracking;
  bool tessellateForPathAccuracy;
  int islandsMax;
  float islandsMinSurfaceArea;
  bool islandsLeaveSmallTouchingPortals;
  bool addBrushesAsExclusions;
  bool optimizeForAxisAligned;
  float volumeDistanceTolerance;
  float volumeAngleTolerance;
  bool buildImpNodeSurfaces;
  bool useCollisionModels;
  bool useEntityIslandMetadata;
  bool bakeFlightVolumes;
  idDeclNavigation::coverSet_t cover;
};
