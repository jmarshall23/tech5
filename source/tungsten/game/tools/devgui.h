#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\tools\devgui.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16505; PDB kind: class.
class idDevGuiPage : public idGuiPage
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16506.
  virtual ~idDevGuiPage();
  virtual bool IsEnabled();
  virtual void SetIsActive(const bool);
  virtual void Update();
  virtual void SetupChildRowLink(const int, const idStr *);
  virtual void InternalRender(idDeviceContext *, const float, const float);
  virtual void InternalRender_2(idEntity *, idDeviceContext *);
  virtual bool InternalHandleEvent(const sysEvent_t *);
  virtual void FlagSelectedRowAsDidActionRow();

  bool renderedOnce;
  int selectedRow;
  int didActionRow;
  int didActionTimer;
  const int DEFAULT_ROW_NUM;
};

// IDA Local Type ordinal 16514; PDB kind: class.
class idDevGui
{
public:
  bool firstDraw;
  bool initialized;
  bool runningTool;
  int postExitSuppressInputTime;
  int selectedColumn;
  float oldGuiScale;
  idList<idDevGuiMainPage *,5> pages;
  idRenderModelGui *guiModel;
};
