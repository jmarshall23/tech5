#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\typeinfo\gametypeinfo.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1034; PDB kind: enum.
enum gameType_t : __int32
{
  GAME_TYPE_UNUSED_DEPRECATED = 0x0,
  GAME_TYPE_COOP = 0x1,
  GAME_TYPE_PVP = 0x2,
};

// IDA Local Type ordinal 22029; PDB kind: class.
class idGuiPageTypeInfo : public idGuiPage
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22030.
  virtual ~idGuiPageTypeInfo();
  virtual bool IsEnabled();
  virtual void SetIsActive(const bool);
  virtual void Update();
  virtual void SetupChildRowLink(const int, const idStr *);
  virtual void InternalRender(idDeviceContext *, const float, const float);
  virtual void InternalRender_2(idEntity *, idDeviceContext *);
  virtual bool InternalHandleEvent(const sysEvent_t *);
  virtual bool WriteTypeInfoObject(idEntity *, idTypeInfoFile *);
  virtual bool ReadTypeInfoObject(idEntity *, idTypeInfoFile *);

  int step;
  int stepMin;
  int itemIndex;
  idStr currentPath;
  idStr currentEditTxt;
};
