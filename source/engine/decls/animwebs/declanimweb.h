#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\animwebs\declanimweb.h
// Recovered logical types: 18
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1341; PDB kind: enum.
enum idDeclAnimWeb::invalidNodeIndex_t : __int32
{
  INVALID_NODE_INDEX = 0xFFFFFFFF,
};

// IDA Local Type ordinal 2264; PDB kind: enum.
enum idDeclAnimWeb::invalidStateIndex_t : __int32
{
  INVALID_STATE_INDEX = 0xFFFFFFFF,
};

// IDA Local Type ordinal 2266; PDB kind: enum.
enum idDeclAnimWeb::invalidSubWebIndex_t : __int32
{
  INVALID_SUBWEB_INDEX = 0xFFFFFFFF,
};

// IDA Local Type ordinal 2709; PDB kind: enum.
enum idDeclAnimWeb::invalidEdgeIndex_t : __int32
{
  INVALID_EDGE_INDEX = 0xFFFFFFFF,
};

// IDA Local Type ordinal 2710; PDB kind: enum.
enum idDeclAnimWeb::invalidModelIndex_t : __int32
{
  INVALID_MODEL_INDEX = 0xFFFFFFFF,
};

// IDA Local Type ordinal 2711; PDB kind: enum.
enum idDeclAnimWeb::invalidLayerIndex_t : __int32
{
  INVALID_LAYER_INDEX = 0xFFFFFFFF,
};

// IDA Local Type ordinal 2712; PDB kind: enum.
enum idDeclAnimWeb::nodeProps_t : __int32
{
  NP_ANIM = 0x0,
  NP_WRAP = 0x1,
  NP_RATE = 0x2,
  NP_DELTA = 0x3,
  NP_BLENDEQ = 0x4,
  NP_TRANSITION = 0x5,
  NP_MAX = 0x6,
};

// IDA Local Type ordinal 2713; PDB kind: enum.
enum idDeclAnimWeb::subWebBlend_t : __int32
{
  SUBWEBBLEND_USE_SOURCE_NODE = 0x0,
  SUBWEBBLEND_ALWAYS_BLEND_OUT_ANYWHERE = 0x1,
  SUBWEBBLEND_MAX = 0x2,
};

// IDA Local Type ordinal 14265; PDB kind: class.
class __declspec(align(4)) idDeclAnimWebTag
{
public:
  idAtomicString name;
  bool isDefault;
};

// IDA Local Type ordinal 14267; PDB kind: class.
class idDeclAnimWebTagGroup
{
public:
  idAtomicString name;
  idList<idDeclAnimWebTag,32> tagList;
};

// IDA Local Type ordinal 15035; PDB kind: class.
class idDeclAnimWeb::stateList_t
{
public:
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> stateIndex[4];
  unsigned __int16 numStates;
};

// IDA Local Type ordinal 15048; PDB kind: class.
class __declspec(align(2)) idDeclAnimWeb::idSubWebInfo
{
public:
  idList<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,32> nodes;
  idAtomicString name;
  idColor color;
  bool isHub;
  bool isVisible;
  bool used;
};

// IDA Local Type ordinal 15050; PDB kind: class.
class idDeclAnimWeb::idStateInfo
{
public:
  idAtomicString name;
};

// IDA Local Type ordinal 15056; PDB kind: class.
class idDeclAnimWeb::idEdgeCache
{
public:
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> destNodeIndex;
  unsigned __int8 weightScale;
  unsigned __int8 flags;
};

// IDA Local Type ordinal 15058; PDB kind: class.
class idDeclAnimWeb::idNodeCache
{
public:
  unsigned __int16 numEdges;
  unsigned __int8 flags;
  unsigned __int8 pad2;
  unsigned int edgeIndexOffset;
};

// IDA Local Type ordinal 15063; PDB kind: class.
class __declspec(align(4)) idDeclAnimWeb::idLayerInfo
{
public:
  idAtomicString name;
  idList<idAtomicString,5> subWebsOnLayer;
  bool isVisible;
};

// IDA Local Type ordinal 15065; PDB kind: class.
class idDeclAnimWeb::idSettings
{
public:
  idVec3 editPos;
  int gridSize;
  bool snapToGrid;
  bool showGrid;
  bool alwaysShowIntraSubwebLinks;
  bool alwaysShowNodeProps;
  bool showAbbreviatedNodeProps;
  bool showIncomingLinks;
  bool isComposite;
  bool mergeModels;
  bool nodeProps[6];
  int defaultBlendOutWindow;
  int defaultBlendDuration;
  idDeclAnimWeb::subWebBlend_t subWebBlend;
};

// IDA Local Type ordinal 15066; PDB kind: class.
class idDeclAnimWeb : public idDecl
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15067.
  virtual ~idDeclAnimWeb();
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

  idList<idDeclAnimWebNode *,32> nodes;
  idList<idDeclAnimWeb::idSubWebInfo,32> subWebs;
  idList<idDeclAnimWeb::idStateInfo,32> states;
  idList<idDeclMD6 const *,32> models;
  idList<idDeclAnimWebEdge,32> edges;
  idList<idDeclAnimWeb::idEdgeCache,32> edgeCache;
  idList<idDeclAnimWeb::idNodeCache,32> nodeCache;
  idList<idAnimWebScalar,32> scalars;
  idList<idAtomicString,32> editorModels;
  idList<idDeclAnimWeb::idLayerInfo,32> layers;
  idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t> *edgeIndexCache;
  unsigned int edgeIndexCacheSize;
  int changeId;
  bool expandSubWebLinks;
  idDeclAnimWeb::idSettings settings;
};
