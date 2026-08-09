#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\navpower\navpower.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18282; PDB kind: class.
class idGuiNavPower : public idGuiPage
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18283.
  virtual ~idGuiNavPower();
  virtual bool IsEnabled();
  virtual void SetIsActive(const bool);
  virtual void Update();
  virtual void SetupChildRowLink(const int, const idStr *);
  virtual void InternalRender(idDeviceContext *, const float, const float);
  virtual void InternalRender_2(idEntity *, idDeviceContext *);
  virtual bool InternalHandleEvent(const sysEvent_t *);

  int selectedRow;
  int selectedPane;
};
