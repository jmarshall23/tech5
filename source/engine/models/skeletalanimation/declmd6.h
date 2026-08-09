#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\declmd6.h
// Recovered logical types: 7
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1999; PDB kind: enum.
enum idDeclMD6::modelCaps_t : __int32
{
  MODELCAP_LIPSYNC = 0x1,
  MODELCAP_FACESETUP = 0x2,
  MODELCAP_MOODS = 0x4,
  MODELCAP_GESTURES = 0x8,
};

// IDA Local Type ordinal 2934; PDB kind: enum.
enum idDeclMD6::userPropEx_t : __int32
{
  USERPROPEX_NONE = 0x0,
  USERPROPEX_DECL_START = 0x1,
  USERPROPEX_DECL_RENDERPROG = 0x1,
  USERPROPEX_DECL_AF = 0x2,
  USERPROPEX_DECL_ENTITYDEF = 0x3,
  USERPROPEX_DECL_MATERIAL = 0x4,
  USERPROPEX_DECL_PARTICLES = 0x5,
  USERPROPEX_DECL_CLOTH = 0x6,
  USERPROPEX_DECL_SOUNDSHADER = 0x7,
  USERPROPEX_DECL_MD6DEF = 0x8,
  USERPROPEX_DECL_SKIN = 0x9,
  USERPROPEX_DECL_TABLE = 0xA,
  USERPROPEX_DECL_ENV = 0xB,
  USERPROPEX_DECL_FX = 0xC,
  USERPROPEX_DECL_VOICEOVER = 0xD,
  USERPROPEX_DECL_ANIMWEB = 0xE,
  USERPROPEX_DECL_VISEMESET = 0xF,
  USERPROPEX_DECL_BREAKABLE = 0x10,
  USERPROPEX_DECL_RIBBON = 0x11,
  USERPROPEX_DECL_FLARE = 0x12,
  USERPROPEX_DECL_END = 0x13,
};

// IDA Local Type ordinal 13313; PDB kind: class.
class idDeclMD6 : public idDecl
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13422.
  virtual ~idDeclMD6();
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
  virtual void Write(idFile_String *, const char *);

  idMD6Blend::configInfo_t *config;
  const idMD6Model *model;
  idStr parent;
  const idDeclMD6 *parentDecl;
  idList<idDeclMD6::includeDecl_t,5> declsToIncludeAnimDataFrom;
  idBounds referenceBounds;
  int numLoadErrors;
  idJointGroupCollection jointGroupCollection;
  idPropsCollection props;
  idAnimEvents animEvents;
  idEyeInfoCollection eyeInfoCollection;
  idList<idVarArgs<6>,19> userProps;
  idList<idMD6Alias,19> aliases;
  idHashIndex aliasHash;
  unsigned __int16 curAliasHandle;
  idList<idDeclMD6::idHeadTrackGroup,5> headTrackGroups;
  idList<idPair<idStr,idList<int,19> >,19> meshKitGroups[3];
  idStr meshKitDefault[3];
  idMorphVertices *morphVertices;
  idList<idMorphDef,115> morphDefList;
  bool calcRefBoundsFromJoints;
  idList<idStr,5> wrinkleMapRegionExpressions;
  float attachmentOverrideScale;
  int modelCaps;
  int userChannelWeightGroupOverride;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> baseUserChannelAlias;
  idList<idHandle<unsigned short,enum invalidAliasHandle_t,65535>,19> userChannelToAnimationAliasMap;
  idList<idPair<idIndex<short,enum invalidUserChannelIndex_t>,idHandle<unsigned short,enum invalidAliasHandle_t,65535> >,19> userChannelToAnimationAliasOverrides;
};

// IDA Local Type ordinal 13364; PDB kind: struct.
struct __declspec(align(4)) idDeclMD6::includeDecl_t
{
  const idDeclMD6 *includeDecl;
  bool isOriginalInclude;
};

// IDA Local Type ordinal 13403; PDB kind: class.
class idDeclMD6::idHeadTrackJoint
{
public:
  idIndex<short,enum invalidJointIndex_t> jointIdx;
  float pitchScale;
  float yawScale;
};

// IDA Local Type ordinal 13405; PDB kind: class.
class idDeclMD6::idHeadTrackGroup
{
public:
  idAtomicString name;
  idList<idDeclMD6::idHeadTrackJoint,5> trackJoints;
  idIndex<short,enum invalidJointIndex_t> focusJointIdx;
  idIndex<short,enum invalidJointIndex_t> orientationJointIdx;
  int blendTime;
};

// IDA Local Type ordinal 22460; PDB kind: struct.
struct idDeclMD6::animEventData_t
{
  const idDeclMD6 *definingDecl;
  const idAnimEvents::animEventInfo_t *info;
};
