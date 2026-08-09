#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\console.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17642; PDB kind: class.
class idConsole
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17648.
  virtual ~idConsole();
  virtual void Init();
  virtual void Shutdown();
  virtual void InitGuiModel();
  virtual void LoadGraphics();
  virtual bool ProcessEvent(const sysEvent_t *, bool);
  virtual bool IsInitialized();
  virtual bool IsActive();
  virtual void ClearNotifyLines();
  virtual void ClearEditLine();
  virtual void Close(bool);
  virtual void Print(const char *);
  virtual void Dump(const char *, idStr *);
  virtual void Draw(bool, bool);
  virtual bool WasLastFullScreen();
  virtual idRenderModelGui *Gui();
  virtual void PrintOverlay(idOverlayHandle *, justify_t, float, float, const char *, ...);
  virtual void AddTimeRange(rangeId_t, const idColor *, unsigned __int64, unsigned __int64);
  virtual void SetTimeRangeLabel(rangeId_t, const char *);
  virtual void AddJobListTimeRange(rangeId_t, const idColor *, const idParallelJobList *, const unsigned __int64);
  virtual void BeginTimeRange(const rangeId_t, const idColor *);
  virtual idColor *GetTimeRangeColor(idColor *result, const rangeId_t);
  virtual idDebugGraph *CreateGraph(int);
  virtual void DestroyGraph(idDebugGraph *);
  virtual void AddSnapObject(const char *, int, int, float);
  virtual void ClearSnapshots();
  virtual void AddSnapshots(const idSnapShot *, const idSnapShot *, int, int, int, int);
  virtual void AddPresentableObject(const char *, int, bool);
  virtual void ClearPresentables();
  virtual void SetBitmapConsole(unsigned __int8 *, unsigned __int8 *, int, int, int);
  virtual void DrawBitmapConsole();
  virtual void MarkVBLTime();

};

// IDA Local Type ordinal 23631; PDB kind: class.
class idConsoleLocal : public idConsole, public idPrintListener
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23632.
  virtual ~idConsoleLocal();
  virtual void Init();
  virtual void Shutdown();
  virtual void InitGuiModel();
  virtual void LoadGraphics();
  virtual bool ProcessEvent(const sysEvent_t *, bool);
  virtual bool IsInitialized();
  virtual bool IsActive();
  virtual void ClearNotifyLines();
  virtual void ClearEditLine();
  virtual void Close(bool);
  virtual void Print(const char *);
  virtual void Dump(const char *, idStr *);
  virtual void Draw(bool, bool);
  virtual bool WasLastFullScreen();
  virtual idRenderModelGui *Gui();
  virtual void PrintOverlay(idOverlayHandle *, justify_t, float, float, const char *, ...);
  virtual void AddTimeRange(rangeId_t, const idColor *, unsigned __int64, unsigned __int64);
  virtual void SetTimeRangeLabel(rangeId_t, const char *);
  virtual void AddJobListTimeRange(rangeId_t, const idColor *, const idParallelJobList *, const unsigned __int64);
  virtual void BeginTimeRange(const rangeId_t, const idColor *);
  virtual idColor *GetTimeRangeColor(idColor *result, const rangeId_t);
  virtual idDebugGraph *CreateGraph(int);
  virtual void DestroyGraph(idDebugGraph *);
  virtual void AddSnapObject(const char *, int, int, float);
  virtual void ClearSnapshots();
  virtual void AddSnapshots(const idSnapShot *, const idSnapShot *, int, int, int, int);
  virtual void AddPresentableObject(const char *, int, bool);
  virtual void ClearPresentables();
  virtual void SetBitmapConsole(unsigned __int8 *, unsigned __int8 *, int, int, int);
  virtual void DrawBitmapConsole();
  virtual void MarkVBLTime();

  __int64 lastRangeMicroseconds[39];
  idColor lastRangeColor[39];
  int timeLogFirstFrame;
  idList<unsigned char,5> timeLog;
  bool keyCatching;
  idWarningCollector warningCollector;
  idRenderModelGui *gui;
  idArray<short,65537> text;
  idArray<short *,4096> lines;
  int currentLine;
  int lineOffset;
  int textOffset;
  int displayLine;
  int nextKeyEvent;
  float displayFrac;
  float finalFrac;
  int fracTime;
  bool lastFullscreen;
  bool isInitialized;
  idArray<int,4> times;
  idEditField consoleField;
  unsigned __int8 *bitmapConsoleBuffers[2];
  int bitmapConsoleBytePitch;
  int bitmapConsoleWidth;
  int bitmapConsoleHeight;
  idList<overlayText_t,5> overlayText;
  timeRange_t ranges[512];
  int currentRange;
  idStrBuffer<48> rangeLabel[39];
  idSysMutex mutexRange;
  idDebugGraph *graphFPS;
  idDebugGraph *graphTotalTime;
  idDebugGraph *graphRenderTime;
  idDebugGraph *graphGameTime;
  idDebugGraph *graphGPUTime;
  idStaticList<idDebugGraph *,32> debugGraphs;
  idRunningAverage avgFPS;
  idRunningAverage avgTotalTime;
  idRunningAverage avgRenderTime;
  idRunningAverage avgGameTime;
  idRunningAverage avgGPUTime;
  idList<showSoundDebugInfo_t,5> showSoundDebugInfoList;
  idStaticList<snapObject_t,128> snapObjects;
  float avgBytesChanged;
  int maxSnapObjectString;
  int lastDrawSnapshots;
  idSnapShot snapshots[2];
  int snapshotSeqs[2];
  int snapshotPeerNum;
  bool snapshotsLocked;
  int snapshotsMaxSize;
  idStaticList<presentableObject_t,32> presentableObjects;
  int maxPresentableObjectString;
  int lastDrawPresentables;
  unsigned __int64 lastVblMicroseconds;
  unsigned __int64 vblIntervalMicroseconds;
  unsigned __int64 rangeSyncTime;
};

// IDA Local Type ordinal 23665; PDB kind: struct.
struct idConsoleLocal::DrawSnapshots::__l18::local_t
{
};

// IDA Local Type ordinal 23666; PDB kind: class.
class idConsoleLocal::DrawComSpeeds::__l2::local_t
{
public:
};
