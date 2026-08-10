#pragma once

#include "framework/framework_runtime.h"

#include <deque>
#include <map>
#include <mutex>
#include <string>

namespace tech5Framework {

struct runtimeState_t {
    std::recursive_mutex mutex;
    lifecycle_t lifecycle = lifecycle_t::stopped;
    sessionState_t session = sessionState_t::idle;
    std::uint64_t frame = 0;
    int milliseconds = 0;
    std::string commandLine;
    std::map<std::string, commandFunction_t> commands;
    std::deque<dialog_t> dialogs;
    std::map<std::string, int> dialogIntValues;
    bool dialogActive = false;
    bool saveIndicatorRequested = false;
    int saveIndicatorClearTime = 0;
    float loadProgress = 0.0f;
    idStr loadPhase;
    std::deque<networkMessage_t> networkMessages;
    std::deque<consoleLine_t> consoleLines;
    std::uint64_t consoleSequence = 0;
    std::map<std::string, idStr> debugHUD;
    std::map<std::string, idStr> debugMenu;
    std::vector<playtestEvent_t> playtestEvents;
    std::map<int, userCommand_t> userCommands;
};

runtimeState_t& State();

} // namespace tech5Framework
