#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\decltypeinfograph.h
// Recovered logical types: 14
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18745; PDB kind: class.
class idTypeInfoGraphItem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18746.
  virtual ~idTypeInfoGraphItem();
  virtual idColor *GetColor(idColor *result);
  virtual void GetDisplayName(idStr *);

  idAtomicString name;
  idAtomicString className;
};

// IDA Local Type ordinal 18747; PDB kind: class.
class idTypeInfoSubGraph : public idTypeInfoGraphItem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18748.
  virtual ~idTypeInfoSubGraph();
  virtual idColor *GetColor(idColor *result);
  virtual void GetDisplayName(idStr *);

  idList<int,5> subnodes;
  idVec2 position;
};

// IDA Local Type ordinal 18755; PDB kind: class.
class idTypeInfoGraphNode : public idTypeInfoGraphItem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18756.
  virtual ~idTypeInfoGraphNode();
  virtual idColor *GetColor(idColor *result);
  virtual void GetDisplayName(idStr *);
  virtual void GetInfo(idStr *, bool *);

  idVec2 position;
};

// IDA Local Type ordinal 18761; PDB kind: class.
class idTypeInfoGraphLink : public idTypeInfoGraphItem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18762.
  virtual ~idTypeInfoGraphLink();
  virtual idColor *GetColor(idColor *result);
  virtual void GetDisplayName(idStr *);

  int startNodeIndex;
  int endNodeIndex;
};

// IDA Local Type ordinal 20163; PDB kind: class.
class idDeclTypeInfoGraph : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20175.
  virtual ~idDeclTypeInfoGraph();
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
  virtual idGraphItemFactory<idTypeInfoSubGraph> *GetMySubGraphFactory();
  virtual idGraphItemFactory<idTypeInfoGraphNode> *GetMyGraphNodeFactory();
  virtual idGraphItemFactory<idTypeInfoGraphLink> *GetMyGraphLinkFactory();
  virtual bool CanCreateSubGraphs();
  virtual bool CanCreateNodesOutsideOfSubGraphs();
  virtual bool AllowMultipleLinksBetweenNodes();
  virtual bool AllowLinkBetweenNodes(int, int);
  virtual void OnDeclParsed();
  virtual void OnCreateLink(idTypeInfoGraphLink *);
  virtual void OnDeleteLink(idTypeInfoGraphLink *);
  virtual idColor *GetSubGraphColor(idColor *result, const idTypeInfoSubGraph *);
  virtual idColor *GetNodeColor(idColor *result, const idTypeInfoGraphNode *);
  virtual idColor *GetLinkColor(idColor *result, const idTypeInfoGraphLink *);
  virtual void GetNodeInfo(const idTypeInfoGraphNode *, idStr *, bool *);
  virtual void GetMainContextMenuItems(idList<idDeclTypeInfoGraph::idContextMenuItemMain,5> *);
  virtual void GetSubGraphContextMenuItems(const idList<idTypeInfoSubGraph *,5> *, struct idList<idDeclTypeInfoGraph::idContextMenuItemSubGraph,5> *);
  virtual void GetNodeContextMenuItems(const idList<idTypeInfoGraphNode *,5> *, struct idList<idDeclTypeInfoGraph::idContextMenuItemNode,5> *);
  virtual void GetLinkContextMenuItems(const idList<idTypeInfoGraphLink *,5> *, idList<idDeclTypeInfoGraph::idContextMenuItemLink,5> *);

  idList<idTypeInfoSubGraph *,5> subGraphs;
  idList<idTypeInfoGraphNode *,5> nodes;
  idList<idTypeInfoGraphLink *,5> links;
};

// IDA Local Type ordinal 20164; PDB kind: class.
class __declspec(align(4)) idDeclTypeInfoGraph::idContextMenuItemBase
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20165.
  virtual ~idContextMenuItemBase();

  idStr description;
  bool isEnabled;
  bool isChecked;
};

// IDA Local Type ordinal 20166; PDB kind: class.
class idDeclTypeInfoGraph::idContextMenuItemMain : public idDeclTypeInfoGraph::idContextMenuItemBase
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20167.
  virtual ~idContextMenuItemMain();

  void (__fastcall *callback)(idDeclTypeInfoGraph *);
};

// IDA Local Type ordinal 20172; PDB kind: class.
class idDeclTypeInfoGraph::idContextMenuItemLink : public idDeclTypeInfoGraph::idContextMenuItemBase
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20173.
  virtual ~idContextMenuItemLink();

  void (__fastcall *callback)(idDeclTypeInfoGraph *, const idList<idTypeInfoGraphLink *,5> *);
};

// IDA Local Type ordinal 20176; PDB kind: class.
class idDeclTypeInfoGraphTest : public idDeclTypeInfoGraph
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20177.
  virtual ~idDeclTypeInfoGraphTest();
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
  virtual idGraphItemFactory<idTypeInfoSubGraph> *GetMySubGraphFactory();
  virtual idGraphItemFactory<idTypeInfoGraphNode> *GetMyGraphNodeFactory();
  virtual idGraphItemFactory<idTypeInfoGraphLink> *GetMyGraphLinkFactory();
  virtual bool CanCreateSubGraphs();
  virtual bool CanCreateNodesOutsideOfSubGraphs();
  virtual bool AllowMultipleLinksBetweenNodes();
  virtual bool AllowLinkBetweenNodes(int, int);
  virtual void OnDeclParsed();
  virtual void OnCreateLink(idTypeInfoGraphLink *);
  virtual void OnDeleteLink(idTypeInfoGraphLink *);
  virtual idColor *GetSubGraphColor(idColor *result, const idTypeInfoSubGraph *);
  virtual idColor *GetNodeColor(idColor *result, const idTypeInfoGraphNode *);
  virtual idColor *GetLinkColor(idColor *result, const idTypeInfoGraphLink *);
  virtual void GetNodeInfo(const idTypeInfoGraphNode *, idStr *, bool *);
  virtual void GetMainContextMenuItems(idList<idDeclTypeInfoGraph::idContextMenuItemMain,5> *);
  virtual void GetSubGraphContextMenuItems(const idList<idTypeInfoSubGraph *,5> *, struct idList<idDeclTypeInfoGraph::idContextMenuItemSubGraph,5> *);
  virtual void GetNodeContextMenuItems(const idList<idTypeInfoGraphNode *,5> *, struct idList<idDeclTypeInfoGraph::idContextMenuItemNode,5> *);
  virtual void GetLinkContextMenuItems(const idList<idTypeInfoGraphLink *,5> *, idList<idDeclTypeInfoGraph::idContextMenuItemLink,5> *);
  virtual bool HighlightDeadEndNodes();
  virtual void SetHighlightDeadEndNodes(bool);

  bool highlightDeadEndNodes;
  bool someOtherBool;
  idDeclFX *fxDecl;
};

// IDA Local Type ordinal 20205; PDB kind: class.
class idDeclTypeInfoGraphSingleType<idTypeInfoSubGraphTest,idTypeInfoGraphNodeTest,idTypeInfoGraphLinkTest> : public idDeclTypeInfoGraph
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20206.
  virtual ~idDeclTypeInfoGraphSingleType();
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
  virtual idGraphItemFactory<idTypeInfoSubGraph> *GetMySubGraphFactory();
  virtual idGraphItemFactory<idTypeInfoGraphNode> *GetMyGraphNodeFactory();
  virtual idGraphItemFactory<idTypeInfoGraphLink> *GetMyGraphLinkFactory();
  virtual bool CanCreateSubGraphs();
  virtual bool CanCreateNodesOutsideOfSubGraphs();
  virtual bool AllowMultipleLinksBetweenNodes();
  virtual bool AllowLinkBetweenNodes(int, int);
  virtual void OnDeclParsed();
  virtual void OnCreateLink(idTypeInfoGraphLink *);
  virtual void OnDeleteLink(idTypeInfoGraphLink *);
  virtual idColor *GetSubGraphColor(idColor *result, const idTypeInfoSubGraph *);
  virtual idColor *GetNodeColor(idColor *result, const idTypeInfoGraphNode *);
  virtual idColor *GetLinkColor(idColor *result, const idTypeInfoGraphLink *);
  virtual void GetNodeInfo(const idTypeInfoGraphNode *, idStr *, bool *);
  virtual void GetMainContextMenuItems(idList<idDeclTypeInfoGraph::idContextMenuItemMain,5> *);
  virtual void GetSubGraphContextMenuItems(const idList<idTypeInfoSubGraph *,5> *, struct idList<idDeclTypeInfoGraph::idContextMenuItemSubGraph,5> *);
  virtual void GetNodeContextMenuItems(const idList<idTypeInfoGraphNode *,5> *, struct idList<idDeclTypeInfoGraph::idContextMenuItemNode,5> *);
  virtual void GetLinkContextMenuItems(const idList<idTypeInfoGraphLink *,5> *, idList<idDeclTypeInfoGraph::idContextMenuItemLink,5> *);

};

// IDA Local Type ordinal 20207; PDB kind: class.
class idDeclTypeInfoGraphSingleTypeTest : public idDeclTypeInfoGraphSingleType<idTypeInfoSubGraphTest,idTypeInfoGraphNodeTest,idTypeInfoGraphLinkTest>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20208.
  virtual ~idDeclTypeInfoGraphSingleTypeTest();
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
  virtual idGraphItemFactory<idTypeInfoSubGraph> *GetMySubGraphFactory();
  virtual idGraphItemFactory<idTypeInfoGraphNode> *GetMyGraphNodeFactory();
  virtual idGraphItemFactory<idTypeInfoGraphLink> *GetMyGraphLinkFactory();
  virtual bool CanCreateSubGraphs();
  virtual bool CanCreateNodesOutsideOfSubGraphs();
  virtual bool AllowMultipleLinksBetweenNodes();
  virtual bool AllowLinkBetweenNodes(int, int);
  virtual void OnDeclParsed();
  virtual void OnCreateLink(idTypeInfoGraphLink *);
  virtual void OnDeleteLink(idTypeInfoGraphLink *);
  virtual idColor *GetSubGraphColor(idColor *result, const idTypeInfoSubGraph *);
  virtual idColor *GetNodeColor(idColor *result, const idTypeInfoGraphNode *);
  virtual idColor *GetLinkColor(idColor *result, const idTypeInfoGraphLink *);
  virtual void GetNodeInfo(const idTypeInfoGraphNode *, idStr *, bool *);
  virtual void GetMainContextMenuItems(idList<idDeclTypeInfoGraph::idContextMenuItemMain,5> *);
  virtual void GetSubGraphContextMenuItems(const idList<idTypeInfoSubGraph *,5> *, struct idList<idDeclTypeInfoGraph::idContextMenuItemSubGraph,5> *);
  virtual void GetNodeContextMenuItems(const idList<idTypeInfoGraphNode *,5> *, struct idList<idDeclTypeInfoGraph::idContextMenuItemNode,5> *);
  virtual void GetLinkContextMenuItems(const idList<idTypeInfoGraphLink *,5> *, idList<idDeclTypeInfoGraph::idContextMenuItemLink,5> *);

};

// IDA Local Type ordinal 21769; PDB kind: class.
class idDeclTypeInfoGraph::idContextMenuItemSubGraph : public idDeclTypeInfoGraph::idContextMenuItemBase
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21770.
  virtual ~idContextMenuItemSubGraph();

  void (__fastcall *callback)(idDeclTypeInfoGraph *, const idList<idTypeInfoSubGraph *,5> *);
};

// IDA Local Type ordinal 21771; PDB kind: class.
class idDeclTypeInfoGraph::idContextMenuItemNode : public idDeclTypeInfoGraph::idContextMenuItemBase
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21772.
  virtual ~idContextMenuItemNode();

  void (__fastcall *callback)(idDeclTypeInfoGraph *, const idList<idTypeInfoGraphNode *,5> *);
};

// IDA Local Type ordinal 21775; PDB kind: class.
class idDeclTypeInfoGraph::idSort_NodeIndex : public idSort_Quick<int,idDeclTypeInfoGraph::idSort_NodeIndex>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21776.
  virtual ~idSort_NodeIndex();
  virtual void Sort(int *, unsigned int);

};
