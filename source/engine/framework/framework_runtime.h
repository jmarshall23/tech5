#pragma once

#include "framework/dialog.h"
#include "idlib/text/str.h"

#include <cstdint>
#include <functional>
#include <vector>

class idRenderModelGui;

namespace tech5Framework {

enum class lifecycle_t { stopped, initializing, running, terminating };
enum class sessionState_t { idle, loading, active, paused, disconnecting };

using dialog_t = idDialogInfo;

struct networkMessage_t {
    int peer;
    int type;
    std::vector<unsigned char> payload;
};

struct consoleLine_t {
    std::uint64_t sequence;
    unsigned int color;
    idStr text;
};

struct playtestEvent_t {
    std::uint64_t microseconds;
    idStr category;
    idStr name;
    float values[4];
};

struct userCommand_t {
    int deviceNum;
    int sequence;
    int buttons;
    float forwardMove;
    float rightMove;
    float yaw;
    float pitch;
};

using commandFunction_t = std::function<void(const std::vector<idStr>&)>;

void Init(const char* commandLine);
void Shutdown();
lifecycle_t Lifecycle();
std::uint64_t FrameNumber();
void RunFrame(int milliseconds);

bool RegisterCommand(const char* name, commandFunction_t function);
bool ExecuteCommand(const char* commandLine);
void ClearCommands();

void QueueDialog(const dialog_t& dialog);
bool PopDialog(dialog_t& dialog);
void ClearDialogs(bool force = true);
bool ClearDialog(int message);
bool HasDialog(int message, bool* isActive = nullptr);
bool IsDialogActive();
bool IsDialogPausing();
bool RespondToDialog(int responseIndex);
void RenderDialogs(bool loading);

void SetLoadProgress(float progress, const char* phase);
float LoadProgress();
const char* LoadPhase();

void QueueNetworkMessage(const networkMessage_t& message);
bool PopNetworkMessage(networkMessage_t& message);
void ClearNetworkMessages();

void SetSessionState(sessionState_t state);
sessionState_t SessionState();

void Print(unsigned int color, const char* format, ...);
std::vector<consoleLine_t> ConsoleSnapshot();
void ClearConsole();

void SetDebugHUDValue(const char* name, const char* value);
void DrawDebugHUD(idRenderModelGui* gui);
void ClearDebugHUD();

void DebugMenuSet(const char* path, const char* value);
bool DebugMenuGet(const char* path, idStr& value);
void DebugMenuClear();

void RecordPlaytestEvent(const playtestEvent_t& event);
std::vector<playtestEvent_t> PlaytestSnapshot();
void ClearPlaytestEvents();
idStr BuildPlaytestReport();

void SubmitUserCommand(const userCommand_t& command);
bool GetUserCommand(int deviceNum, userCommand_t& command);
void ClearUserCommands();

void RenderFrame();

} // namespace tech5Framework
