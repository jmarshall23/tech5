#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\debugmenu.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 21805; PDB kind: class.
class idDebugMenu
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21806.
  virtual ~idDebugMenu();
  virtual bool Init();
  virtual bool IsActive();
  virtual bool HandleGuiEvent(const sysEvent_t *);
  virtual idRenderModelGui *Render();

};

// IDA Local Type ordinal 23605; PDB kind: struct.
struct idDebugMenuLocal::CEntry
{
  bool valid;
  int shortcut;
  idStr title;
  idStr description;
  idStr cmd;
  idStr entityValid;
  idStr entityDescr;
  idVec4 color;
};

// IDA Local Type ordinal 23607; PDB kind: class.
class idDebugMenuLocal::CGroup
{
public:
  idStr title;
  idList<idDebugMenuLocal::CEntry,3> items;
};

// IDA Local Type ordinal 23609; PDB kind: class.
class idDebugMenuLocal : public idDebugMenu
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23610.
  virtual ~idDebugMenuLocal();
  virtual bool Init();
  virtual bool IsActive();
  virtual bool HandleGuiEvent(const sysEvent_t *);
  virtual idRenderModelGui *Render();

  bool modKeyPressed;
  int selectedGroup;
  int selectedItem;
  int startItem;
  idRenderModelGui *guiModel;
  const idFont *font;
  idList<idDebugMenuLocal::CGroup,3> groups;
};
