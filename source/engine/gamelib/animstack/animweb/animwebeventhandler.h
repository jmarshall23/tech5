#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\animstack\animweb\animwebeventhandler.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1362; PDB kind: enum.
enum animWebEvent_t : __int32
{
  ANIMWEB_EVENT_NONE = 0xFFFFFFFF,
  ANIMWEB_EVENT_START_BLEND_IN = 0x0,
  ANIMWEB_EVENT_START_BLEND_OUT = 0x1,
  ANIMWEB_EVENT_END_BLEND_IN = 0x2,
  ANIMWEB_EVENT_END_BLEND_OUT = 0x3,
  ANIMWEB_EVENT_DEST_START_BLEND_IN = 0x4,
  ANIMWEB_EVENT_DEST_END_BLEND_IN = 0x5,
  ANIMWEB_EVENT_DEST_CLAMPED = 0x6,
  ANIMWEB_EVENT_BLEND_NEXT_FRAME = 0x7,
  ANIMWEB_EVENT_CLAMP_NEXT_FRAME = 0x8,
  ANIMWEB_EVENT_MAX = 0x9,
};

// IDA Local Type ordinal 1694; PDB kind: enum.
enum idAnimWebEvent::priority_t : __int32
{
  PRIORITY_LOW = 0x0,
  PRIORITY_MISC = 0x0,
  PRIORITY_DEATH = 0x1,
  PRIORITY_MAX = 0x2,
};

// IDA Local Type ordinal 15082; PDB kind: class.
class idAnimWebEventHandler
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15083.
  virtual void ClearEvent(const animWebEvent_t);
  virtual void ClearEvents();
  virtual void SetEvent(const idAnimator_AnimWeb *, const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>, const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t>, const animWebEvent_t, const int, const idAnimWebEvent::priority_t);
  virtual void TriggerEventType(idAnimator_AnimWeb *, const idDeclAnimWebNode *, const animWebEvent_t, const int);
  virtual bool IsEventPending(const animWebEvent_t);
  virtual bool IsAnyEventPending();

};

// IDA Local Type ordinal 15084; PDB kind: class.
class idAnimWebEvent
{
public:
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> swi;
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> si;
  int eventNum;
  idAnimWebEvent::priority_t priority;
};

// IDA Local Type ordinal 15086; PDB kind: class.
class idAnimWebEventHandler_Zion : public idAnimWebEventHandler
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15085.
  virtual void ClearEvent(const animWebEvent_t);
  virtual void ClearEvents();
  virtual void SetEvent(const idAnimator_AnimWeb *, const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>, const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t>, const animWebEvent_t, const int, const idAnimWebEvent::priority_t);
  virtual void TriggerEventType(idAnimator_AnimWeb *, const idDeclAnimWebNode *, const animWebEvent_t, const int);
  virtual bool IsEventPending(const animWebEvent_t);
  virtual bool IsAnyEventPending();

  idAnimWebEvent events[9];
};
