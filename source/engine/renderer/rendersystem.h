#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\rendersystem.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17560; PDB kind: class.
class idRenderSystem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17566.
  virtual ~idRenderSystem();
  virtual void Init();
  virtual void Init2();
  virtual void Shutdown();
  virtual idRenderWorld *AllocRenderWorld(const char *, bool);
  virtual void RenderFrame(void *const, const idRenderFrameInfo *, const bool, const bool, const bool);
  virtual void EndFrame(void *, int, int, idRenderWorld *, idRenderModel **, int, bool, bool, bool, int);
  virtual void ToolEndFrame(void *, int, int, idRenderWorld *, const renderView_t *, idRenderModel *, int);
  virtual int FrameNumber();
  virtual bool SyncRenderThread(bool);
  virtual void BeginBinkVideo(void *, const char *const, const videoFlags_t, idRenderVideoOverlay *);
  virtual bool BinkVideoIsLoaded();
  virtual bool BinkVideoIsPlaying();
  virtual void FreeBinkVideo();
  virtual void AllowBackgroundSwaps(bool);
  virtual void BeginAutomaticBackgroundSwaps(void *, bool);
  virtual void EndAutomaticBackgroundSwaps();
  virtual void SetLoadingIconInfo(float, float, float, float);
  virtual void RegenerateReferences();
  virtual void InhibitEndFrameRendering(int);
  virtual bool IsEndFrameRenderingInhibited();
  virtual int GetNumRenderWorlds();
  virtual idRenderWorld *RenderWorldForIndex(int);
  virtual int GetNextRenderView(idRenderWorld *const);
  virtual int GetNumMonitors();
  virtual void GetMonitorSize(int, int *, int *);
  virtual int GetCurrentMonitor();
  virtual bool GPUTranscodeAvailable();
  virtual void EnableGPUTranscode(bool);
  virtual bool GPUTranscodeIsEnabled();
  virtual bool SwapTearAvailable();
  virtual void ClearOutOfMemory();
  virtual bool CheckOutOfMemory();
  virtual void *GetGameWindow();
  virtual void Restart();
  virtual void SwapBuffers(void *, bool);
  virtual void SetBlackLevel(const float);
  virtual void SetGamma(unsigned __int16 *, unsigned __int16 *, unsigned __int16 *);
  virtual bool MakeCurrent(void *);
  virtual int GetWidth();
  virtual int GetHeight();
  virtual float GetPixelAspect();
  virtual float GetScreenAspect();
  virtual int GetScanoutWidth();
  virtual int GetScanoutHeight();
  virtual stereoRenderMode_t GetStereoRenderMode();
  virtual int GetNumMultisamples();
  virtual int GetMaxSupportedMultisamples();
  virtual bool IgnoreSizeMessages();
  virtual void WindowSizeDragged(int, int);
  virtual bool WindowChangeMultisamples(const int);
  virtual bool EnumerateModes(int, int *, int *, int *);
  virtual void (__fastcall *ExtensionPointer(const char *))();
  virtual void SetPixelFormat(void *);
  virtual void ShowGameWindow();
  virtual void HideGameWindow();
  virtual bool IsFullscreen();
  virtual void GoWindowed();
  virtual void GoFullScreen();
  virtual void SetStudioMode(bool);

};
