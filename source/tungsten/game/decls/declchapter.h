#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declchapter.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1783; PDB kind: enum.
enum idDeclChapter::chapterType_t : __int32
{
  CHAPTERTYPE_CAMPAIGN = 0x0,
  CHAPTERTYPE_SIDEMISSION = 0x1,
  MAX_TYPES = 0x2,
};

// IDA Local Type ordinal 16086; PDB kind: class.
class idDeclChapter : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16087.
  virtual ~idDeclChapter();
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

  int sortId;
  idStrId displayName;
  idStrId lockedName;
  idDeclChapter::chapterType_t type;
  idVec2 offset;
  idStr sideMap;
  idList<idChapterVariation,5> variations;
};
