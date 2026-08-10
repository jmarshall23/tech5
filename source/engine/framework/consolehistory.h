#pragma once

#include "idlib/containers/array.h"
#include "idlib/text/str.h"

class idConsoleHistory {
public:
    static constexpr int MAX_HISTORY = 64;

    idConsoleHistory();
    void Clear();
    void AddToHistory(const char* line, bool writeHistoryFile);
    void LoadHistoryFile();
    void PrintHistory() const;
    idStr RetrieveFromHistory(bool retrieveUp);

    int upPoint;
    int downPoint;
    int returnLine;
    int numHistory;
    idArray<idStr, MAX_HISTORY> historyLines;
};

extern idConsoleHistory consoleHistory;

void RegisterConsoleHistoryCommands();
