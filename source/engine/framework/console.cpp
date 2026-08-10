#include "framework/framework_runtime_internal.h"

#include "framework/console.h"
#include "framework/consolehistory.h"
#include "framework/debuggraph.h"
#include "framework/framework_hooks.h"
#include "framework/sysevent.h"
#include "idlib/filesystem/filesystem.h"

#include <algorithm>
#include <array>
#include <cstdarg>
#include <cstdio>
#include <mutex>
#include <vector>

namespace {

struct consoleRange_t {
    idColor color = idColor::colorWhite;
    std::uint64_t start = 0;
    std::uint64_t end = 0;
    idStr label;
};

struct consoleSnapshotObject_t {
    idStr name;
    int bytesTotal;
    int bytesChanged;
    float milliseconds;
};

struct consolePresentable_t {
    idStr name;
    int index;
    bool skipReplication;
};

struct consoleRecoveredState_t {
    std::recursive_mutex mutex;
    std::array<consoleRange_t, 39> ranges;
    std::vector<idDebugGraph*> graphs;
    std::vector<consoleSnapshotObject_t> snapshotObjects;
    std::vector<consolePresentable_t> presentables;
    int displayOffset = 0;
};

consoleRecoveredState_t& ConsoleState() {
    static consoleRecoveredState_t state;
    return state;
}

int RangeIndex(const rangeId_t id) {
    const int index = static_cast<int>(id);
    return index >= 0 && index < 39 ? index : -1;
}

std::uint64_t MicrosecondsNow() {
    return frameworkHooks.milliseconds != nullptr
        ? static_cast<std::uint64_t>(frameworkHooks.milliseconds()) * 1000u
        : 0;
}

} // namespace

namespace tech5Framework {
std::vector<consoleLine_t> ConsoleSnapshot() { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); return {state.consoleLines.begin(), state.consoleLines.end()}; }
void ClearConsole() { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); state.consoleLines.clear(); }
} // namespace tech5Framework

idConsoleLocal consoleLocal;
idConsole* console = &consoleLocal;

idConsoleLocal::idConsoleLocal()
    : gui(nullptr), keyCatching(false), initialized(false),
      lastFullscreen(false), bitmapConsoleBuffers{}, bitmapConsoleBytePitch(0),
      bitmapConsoleWidth(0), bitmapConsoleHeight(0), lastVblMicroseconds(0),
      vblIntervalMicroseconds(0) {
}

idConsoleLocal::~idConsoleLocal() {
    Shutdown();
}

void idConsoleLocal::Init() {
    initialized = true;
    consoleField.Clear();
}

void idConsoleLocal::Shutdown() {
    if (!initialized) return;
    consoleRecoveredState_t& state = ConsoleState();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    for (idDebugGraph* graph : state.graphs) delete graph;
    state.graphs.clear();
    state.snapshotObjects.clear();
    state.presentables.clear();
    state.displayOffset = 0;
    if (gui != nullptr && frameworkHooks.destroyGui != nullptr) {
        frameworkHooks.destroyGui(gui);
    }
    gui = nullptr;
    tech5Framework::ClearConsole();
    initialized = false;
    keyCatching = false;
}

void idConsoleLocal::InitGuiModel() {
    if (gui == nullptr && frameworkHooks.createGui != nullptr) {
        gui = frameworkHooks.createGui();
    }
}

void idConsoleLocal::LoadGraphics() {
    InitGuiModel();
}

bool idConsoleLocal::ProcessEvent(const sysEvent_t* const event,
        const bool forceAccept) {
    if (event == nullptr) return false;
    const sysEvent_t& sev = *event;
    if (sev.evType == SE_KEY && sev.evValue == 41) {
        if (sev.evValue2 != 0) {
            consoleField.ClearAutoComplete();
            if (IsActive()) Close(true);
            else {
                consoleField.Clear();
                Activate(0.5f);
            }
        }
        return true;
    }
    if (!forceAccept && !IsActive()) return false;
    if (sev.evType == SE_CHAR) {
        consoleField.CharEvent(sev.evValue);
        return true;
    }
    if (sev.evType != SE_KEY || sev.evValue2 == 0) return sev.evType == SE_KEY;

    switch (sev.evValue) {
    case 28:
    case 256:
        if (consoleField.AcceptAutoComplete()) return true;
        if (*consoleField.GetBuffer() != '\0') {
            Print("]");
            Print(consoleField.GetBuffer());
            Print("\n");
            tech5Framework::ExecuteCommand(consoleField.GetBuffer());
            consoleHistory.AddToHistory(consoleField.GetBuffer(), true);
            consoleField.Clear();
        }
        return true;
    case 200:
    case 282:
        consoleField.SetBuffer(
            consoleHistory.RetrieveFromHistory(true).c_str());
        return true;
    case 208:
    case 283:
        consoleField.SetBuffer(
            consoleHistory.RetrieveFromHistory(false).c_str());
        return true;
    case 201:
    case 280:
        Scroll();
        return true;
    case 209:
    case 281:
        ConsoleState().displayOffset =
            (std::max)(0, ConsoleState().displayOffset - 2);
        return true;
    default:
        consoleField.KeyDownEvent(sev.evValue);
        return true;
    }
}

bool idConsoleLocal::IsInitialized() const { return initialized; }
bool idConsoleLocal::IsActive() const { return keyCatching; }
void idConsoleLocal::ClearNotifyLines() { tech5Framework::ClearConsole(); }
void idConsoleLocal::ClearEditLine() { consoleField.Clear(); }

void idConsoleLocal::Close(const bool clearLine) {
    keyCatching = false;
    if (clearLine) consoleField.Clear();
}

void idConsoleLocal::Print(const char* const text) {
    tech5Framework::Print(0xFFFFFFFFu, "%s", text != nullptr ? text : "");
}

void idConsoleLocal::Dump(const char* const fileName, idStr* output) {
    idStr contents;
    for (const tech5Framework::consoleLine_t& line : tech5Framework::ConsoleSnapshot()) {
        contents.Append(line.text);
        contents.Append('\n');
    }
    if (output != nullptr) {
        *output = contents;
    }
    if (fileName != nullptr && *fileName != '\0' && fileSystem != nullptr) {
        fileSystem->WriteFile(fileName, contents.c_str(), contents.Length(),
            FSPATH_BASE);
    }
}

void idConsoleLocal::Draw(const bool forceFullScreen, bool) {
    lastFullscreen = forceFullScreen;
    consoleRecoveredState_t& state = ConsoleState();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    for (idDebugGraph* graph : state.graphs) {
        if (graph != nullptr) graph->Render(gui);
    }
    const std::vector<tech5Framework::consoleLine_t> lines =
        tech5Framework::ConsoleSnapshot();
    if (gui != nullptr && frameworkHooks.drawString != nullptr) {
        const int visibleLines = forceFullScreen || keyCatching ? 28 : 5;
        const int end = (std::max)(0,
            static_cast<int>(lines.size()) - state.displayOffset);
        const int begin = (std::max)(0, end - visibleLines);
        if ((forceFullScreen || keyCatching)
            && frameworkHooks.drawRect != nullptr) {
            frameworkHooks.drawRect(gui, 0.0f, 0.0f, 1024.0f, 560.0f,
                0xD0101010u);
        }
        float y = forceFullScreen || keyCatching ? 16.0f : 8.0f;
        for (int index = begin; index < end; ++index) {
            frameworkHooks.drawString(gui, 8.0f, y,
                lines[index].text.c_str(), lines[index].color, 0.75f);
            y += 18.0f;
        }
        if (forceFullScreen || keyCatching) {
            consoleField.Draw(gui, 8, 532, 1000, true);
        }
    }
    tech5Framework::DrawDebugHUD(gui);
}

bool idConsoleLocal::WasLastFullScreen() const { return lastFullscreen; }

void idConsoleLocal::PrintOverlay(idOverlayHandle*, justify_t, float, float,
        const char* const format, ...) {
    if (format == nullptr) return;
    char text[2048];
    va_list arguments;
    va_start(arguments, format);
    std::vsnprintf(text, sizeof(text), format, arguments);
    va_end(arguments);
    text[sizeof(text) - 1] = '\0';
    Print(text);
}

void idConsoleLocal::AddTimeRange(const rangeId_t id,
        const idColor& color, const std::uint64_t start,
        const std::uint64_t end) {
    const int index = RangeIndex(id);
    if (index < 0) return;
    consoleRecoveredState_t& state = ConsoleState();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    state.ranges[index].color = color;
    state.ranges[index].start = start;
    state.ranges[index].end = (std::max)(start, end);
}

void idConsoleLocal::SetTimeRangeLabel(const rangeId_t id,
        const char* const label) {
    const int index = RangeIndex(id);
    if (index < 0) return;
    consoleRecoveredState_t& state = ConsoleState();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    state.ranges[index].label = label != nullptr ? label : "";
}

void idConsoleLocal::AddJobListTimeRange(const rangeId_t id,
        const idColor& color, const idParallelJobList*,
        const std::uint64_t baseTime) {
    // Job timing is owned by the parallel-job implementation. Preserve the
    // range marker until that owner exposes its individual execution spans.
    AddTimeRange(id, color, baseTime, baseTime);
}

void idConsoleLocal::BeginTimeRange(const rangeId_t id,
        const idColor& color) {
    AddTimeRange(id, color, MicrosecondsNow(), MicrosecondsNow());
}

idColor idConsoleLocal::GetTimeRangeColor(const rangeId_t id) const {
    const int index = RangeIndex(id);
    if (index < 0) return idColor::colorWhite;
    consoleRecoveredState_t& state = ConsoleState();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    return state.ranges[index].color;
}

idDebugGraph* idConsoleLocal::CreateGraph(const int bars) {
    idDebugGraph* const graph = new idDebugGraph(bars);
    consoleRecoveredState_t& state = ConsoleState();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    state.graphs.push_back(graph);
    return graph;
}

void idConsoleLocal::DestroyGraph(idDebugGraph* const graph) {
    consoleRecoveredState_t& state = ConsoleState();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    const auto found = std::find(state.graphs.begin(), state.graphs.end(), graph);
    if (found != state.graphs.end()) state.graphs.erase(found);
    delete graph;
}

void idConsoleLocal::AddSnapObject(const char* const name,
        const int bytesTotal, const int bytesChanged,
        const float milliseconds) {
    consoleSnapshotObject_t object;
    object.name = name != nullptr ? name : "";
    object.bytesTotal = bytesTotal;
    object.bytesChanged = bytesChanged;
    object.milliseconds = milliseconds;
    consoleRecoveredState_t& state = ConsoleState();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    state.snapshotObjects.push_back(object);
}

void idConsoleLocal::ClearSnapshots() {
    consoleRecoveredState_t& state = ConsoleState();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    state.snapshotObjects.clear();
}

void idConsoleLocal::AddSnapshots(const idSnapShot*, const idSnapShot*,
        int, int, int, int) {
    // Snapshot decoding remains with the networking owner; explicit objects
    // are collected through AddSnapObject as in the recovered implementation.
}

void idConsoleLocal::AddPresentableObject(const char* const name,
        const int index, const bool skipReplication) {
    consolePresentable_t object;
    object.name = name != nullptr ? name : "";
    object.index = index;
    object.skipReplication = skipReplication;
    consoleRecoveredState_t& state = ConsoleState();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    state.presentables.push_back(object);
}

void idConsoleLocal::ClearPresentables() {
    consoleRecoveredState_t& state = ConsoleState();
    std::lock_guard<std::recursive_mutex> lock(state.mutex);
    state.presentables.clear();
}

void idConsoleLocal::SetBitmapConsole(unsigned char* const first,
        unsigned char* const second, const int bytePitch, const int width,
        const int height) {
    bitmapConsoleBuffers[0] = first;
    bitmapConsoleBuffers[1] = second;
    bitmapConsoleBytePitch = bytePitch;
    bitmapConsoleWidth = width;
    bitmapConsoleHeight = height;
}

void idConsoleLocal::DrawBitmapConsole() {
    // The renderer consumes these buffers directly after SetBitmapConsole.
}

void idConsoleLocal::MarkVBLTime() {
    const std::uint64_t now = MicrosecondsNow();
    if (lastVblMicroseconds != 0 && now >= lastVblMicroseconds) {
        vblIntervalMicroseconds = now - lastVblMicroseconds;
    }
    lastVblMicroseconds = now;
}

void idConsoleLocal::Activate(const float fraction) {
    keyCatching = fraction > 0.0f;
}

void idConsoleLocal::Clear() {
    tech5Framework::ClearConsole();
    ConsoleState().displayOffset = 0;
}
void idConsoleLocal::Scroll() {
    const int count = static_cast<int>(tech5Framework::ConsoleSnapshot().size());
    ConsoleState().displayOffset =
        (std::min)(count, ConsoleState().displayOffset + 2);
}
void idConsoleLocal::Top() {
    ConsoleState().displayOffset =
        static_cast<int>(tech5Framework::ConsoleSnapshot().size());
}
