#include "framework/consolehistory.h"
#include "framework/framework_runtime.h"

#include "idlib/filesystem/filesystem.h"
#include "idlib/lib_print.h"

#include <algorithm>
#include <cctype>
#include <cstring>

namespace {
constexpr const char* HISTORY_FILE_NAME = "consoleHistory.txt";

bool HasVisibleText(const char* text) {
    if (text == nullptr) {
        return false;
    }
    while (*text != '\0') {
        if (std::isspace(static_cast<unsigned char>(*text)) == 0) {
            return true;
        }
        ++text;
    }
    return false;
}
}

idConsoleHistory consoleHistory;

idConsoleHistory::idConsoleHistory() {
    Clear();
}

void idConsoleHistory::Clear() {
    upPoint = 0;
    downPoint = 0;
    returnLine = 0;
    numHistory = 0;
    for (idStr& line : historyLines) {
        line.Clear();
    }
}

void idConsoleHistory::AddToHistory(const char* line,
        const bool writeHistoryFile) {
    if (!HasVisibleText(line)) {
        return;
    }
    if (numHistory > 0 && idStr::Icmp(
            historyLines[(numHistory - 1) % MAX_HISTORY].c_str(), line) == 0) {
        upPoint = returnLine;
        return;
    }

    historyLines[numHistory % MAX_HISTORY] = line;
    ++numHistory;
    upPoint = numHistory - 1;
    downPoint = numHistory;
    returnLine = numHistory;

    if (!writeHistoryFile || fileSystem == nullptr) {
        return;
    }
    idFile* output = fileSystem->OpenFileWrite(HISTORY_FILE_NAME, FSPATH_SAVE);
    if (output == nullptr) {
        return;
    }
    const int first = std::max(0, numHistory - MAX_HISTORY);
    for (int index = first; index < numHistory; ++index) {
        output->Printf("%s\n", historyLines[index % MAX_HISTORY].c_str());
    }
    delete output;
}

void idConsoleHistory::LoadHistoryFile() {
    if (fileSystem == nullptr) {
        return;
    }
    void* data = nullptr;
    const int length = fileSystem->ReadFile(HISTORY_FILE_NAME, &data);
    if (length <= 0 || data == nullptr) {
        return;
    }
    Clear();
    const char* begin = static_cast<const char*>(data);
    const char* end = begin + length;
    const char* line = begin;
    while (line < end) {
        const char* newline = static_cast<const char*>(
            std::memchr(line, '\n', static_cast<std::size_t>(end - line)));
        const char* lineEnd = newline != nullptr ? newline : end;
        idStr value;
        for (const char* cursor = line; cursor < lineEnd && *cursor != '\r'; ++cursor) {
            value.Append(*cursor);
        }
        AddToHistory(value.c_str(), false);
        line = newline != nullptr ? newline + 1 : end;
    }
    fileSystem->FreeFile(data);
}

void idConsoleHistory::PrintHistory() const {
    const int first = std::max(0, numHistory - MAX_HISTORY);
    for (int index = first; index < numHistory; ++index) {
        idLibPrint::Printf("%4d: %s\n", index,
            historyLines[index % MAX_HISTORY].c_str());
    }
}

idStr idConsoleHistory::RetrieveFromHistory(const bool retrieveUp) {
    if (numHistory <= 0) {
        return idStr();
    }
    const int first = std::max(0, numHistory - MAX_HISTORY);
    if (retrieveUp) {
        upPoint = std::max(first, upPoint - 1);
        downPoint = upPoint + 1;
        return historyLines[upPoint % MAX_HISTORY];
    }
    downPoint = std::min(numHistory, downPoint + 1);
    upPoint = std::max(first, downPoint - 1);
    return downPoint == numHistory ? idStr()
                                   : historyLines[downPoint % MAX_HISTORY];
}

void RegisterConsoleHistoryCommands() {
    tech5Framework::RegisterCommand("clearHistory",
        [](const std::vector<idStr>&) { consoleHistory.Clear(); });
}
