#pragma once

#include "framework/editfield.h"
#include "framework/framework_runtime.h"
#include "idlib/color.h"

#include <cstdint>

class idDebugGraph;
class idOverlayHandle;
class idParallelJobList;
class idRenderModelGui;
class idSnapShot;
struct sysEvent_t;
enum justify_t : int;
enum rangeId_t : int;

class idConsole {
public:
    virtual ~idConsole() = default;
    virtual void Init() = 0;
    virtual void Shutdown() = 0;
    virtual void InitGuiModel() = 0;
    virtual void LoadGraphics() = 0;
    virtual bool ProcessEvent(const sysEvent_t*, bool) = 0;
    virtual bool IsInitialized() const = 0;
    virtual bool IsActive() const = 0;
    virtual void ClearNotifyLines() = 0;
    virtual void ClearEditLine() = 0;
    virtual void Close(bool) = 0;
    virtual void Print(const char*) = 0;
    virtual void Dump(const char*, idStr*) = 0;
    virtual void Draw(bool, bool) = 0;
    virtual bool WasLastFullScreen() const = 0;
    virtual idRenderModelGui* Gui() = 0;
    virtual void PrintOverlay(idOverlayHandle*, justify_t, float, float,
        const char*, ...) = 0;
    virtual void AddTimeRange(rangeId_t, const idColor&,
        std::uint64_t, std::uint64_t) = 0;
    virtual void SetTimeRangeLabel(rangeId_t, const char*) = 0;
    virtual void AddJobListTimeRange(rangeId_t, const idColor&,
        const idParallelJobList*, std::uint64_t) = 0;
    virtual void BeginTimeRange(rangeId_t, const idColor&) = 0;
    virtual idColor GetTimeRangeColor(rangeId_t) const = 0;
    virtual idDebugGraph* CreateGraph(int) = 0;
    virtual void DestroyGraph(idDebugGraph*) = 0;
    virtual void AddSnapObject(const char*, int, int, float) = 0;
    virtual void ClearSnapshots() = 0;
    virtual void AddSnapshots(const idSnapShot*, const idSnapShot*, int,
        int, int, int) = 0;
    virtual void AddPresentableObject(const char*, int, bool) = 0;
    virtual void ClearPresentables() = 0;
    virtual void SetBitmapConsole(unsigned char*, unsigned char*, int,
        int, int) = 0;
    virtual void DrawBitmapConsole() = 0;
    virtual void MarkVBLTime() = 0;
};

class idConsoleLocal : public idConsole {
public:
    idConsoleLocal();
    ~idConsoleLocal() override;
    void Init() override;
    void Shutdown() override;
    void InitGuiModel() override;
    void LoadGraphics() override;
    bool ProcessEvent(const sysEvent_t*, bool) override;
    bool IsInitialized() const override;
    bool IsActive() const override;
    void ClearNotifyLines() override;
    void ClearEditLine() override;
    void Close(bool) override;
    void Print(const char* text) override;
    void Dump(const char* fileName, idStr* output) override;
    void Draw(bool, bool) override;
    bool WasLastFullScreen() const override;
    idRenderModelGui* Gui() override { return gui; }
    void PrintOverlay(idOverlayHandle*, justify_t, float, float,
        const char*, ...) override;
    void AddTimeRange(rangeId_t, const idColor&, std::uint64_t,
        std::uint64_t) override;
    void SetTimeRangeLabel(rangeId_t, const char*) override;
    void AddJobListTimeRange(rangeId_t, const idColor&,
        const idParallelJobList*, std::uint64_t) override;
    void BeginTimeRange(rangeId_t, const idColor&) override;
    idColor GetTimeRangeColor(rangeId_t) const override;
    idDebugGraph* CreateGraph(int bars) override;
    void DestroyGraph(idDebugGraph* graph) override;
    void AddSnapObject(const char*, int, int, float) override;
    void ClearSnapshots() override;
    void AddSnapshots(const idSnapShot*, const idSnapShot*, int, int, int,
        int) override;
    void AddPresentableObject(const char*, int, bool) override;
    void ClearPresentables() override;
    void SetBitmapConsole(unsigned char*, unsigned char*, int, int,
        int) override;
    void DrawBitmapConsole() override;
    void MarkVBLTime() override;

    void Activate(float fraction);
    void Clear();
    void Scroll();
    void Top();

    idRenderModelGui* gui;
    idEditField consoleField;
    bool keyCatching;
    bool initialized;
    bool lastFullscreen;
    unsigned char* bitmapConsoleBuffers[2];
    int bitmapConsoleBytePitch;
    int bitmapConsoleWidth;
    int bitmapConsoleHeight;
    std::uint64_t lastVblMicroseconds;
    std::uint64_t vblIntervalMicroseconds;
};

extern idConsoleLocal consoleLocal;
extern idConsole* console;
