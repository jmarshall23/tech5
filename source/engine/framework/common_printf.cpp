#include "framework/common_local.h"
#include "framework/framework_hooks.h"
#include "framework/framework_runtime_internal.h"

#include "idlib/csystems/cvarsystem.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/lib_print.h"

#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <ctime>

idCVar com_logFile(
    "logFile", "0", CVAR_INTEGER,
    "1 = buffer log, 2 = flush after each print", 0.0f, 2.0f);
idCVar com_logFileName(
    "logFileName", "qconsole.log", 0,
    "name of log file, if empty, qconsole.log will be used");

idCommonLocal::idLogFileWriter::idLogFileWriter()
    : logFile(nullptr), recursing(false) {
    wantColor = false;
    threadSafe = false;
    minSeverity = SEV_PRINT;
}

idCommonLocal::idLogFileWriter::~idLogFileWriter() {
    CloseLogFile();
}

void idCommonLocal::idLogFileWriter::CloseLogFile() {
    if (logFile == nullptr) return;
    com_logFile.SetBool(false, true);
    delete logFile;
    logFile = nullptr;
}

void idCommonLocal::idLogFileWriter::Print(const char* const message) {
    const int mode = com_logFile.GetInteger();
    if (mode == 0 || fileSystem == nullptr || message == nullptr) return;

    const char* requestedName = com_logFileName.GetString();
    if (requestedName == nullptr || *requestedName == '\0') {
        requestedName = "qconsole.log";
    }
    if (logFile != nullptr
            && idStr::Icmp(requestedName, logFile->GetName()) != 0) {
        delete logFile;
        logFile = nullptr;
    }
    if (logFile == nullptr && !recursing) {
        recursing = true;
        logFile = fileSystem->OpenFileReadWrite(
            requestedName, true, FSPATH_SAVE);
        if (logFile != nullptr) logFile->SetLength(0);
        recursing = false;
        if (logFile == nullptr) {
            idLibPrint::FatalError("failed to open log file '%s'\n",
                requestedName);
        }

        std::time_t now = std::time(nullptr);
        std::tm localTime = {};
        char timestamp[64] = {};
        localtime_s(&localTime, &now);
        asctime_s(timestamp, sizeof(timestamp), &localTime);
        idLibPrint::Printf("log file '%s' opened on %s\n",
            requestedName, timestamp);
    }

    logFile->Write(message,
        static_cast<unsigned int>(std::strlen(message)));
    if (mode == 2) logFile->Flush();
}

idCommonLocal::idWarningList::idWarningList()
    : list(0), hash(1024, 1024, TAG_DEBUG), caption() {
    minSeverity = SEV_WARNING;
}

idCommonLocal::idWarningList::~idWarningList() = default;

void idCommonLocal::idWarningList::Print(const char* const message) {
    if (message == nullptr) return;
    const int key = hash.GenerateKeyForString(message, false);
    for (int index = hash.First(key); index >= 0; index = hash.Next(index)) {
        if (index < list.Num()
                && idStr::Icmp(list[index].message.c_str(), message) == 0) {
            ++list[index].count;
            return;
        }
    }

    idUniqueWarning warning;
    warning.message = message;
    warning.count = 1;
    const int index = list.Append(warning);
    if (index >= 0) hash.Add(key, index);
}

idCommonLocal::idRefreshOnPrint::idRefreshOnPrint()
    : cl(nullptr), set(false) {
    wantColor = false;
    threadSafe = false;
    minSeverity = SEV_PRINT;
}

idCommonLocal::idRefreshOnPrint::~idRefreshOnPrint() = default;

void idCommonLocal::idRefreshOnPrint::Print(const char*) {
    if (set && cl != nullptr) cl->UpdateConsoleDisplay(false);
}

void idCommonLocal::SetRefreshOnPrint(const bool enabled) {
    refreshOnPrint.cl = this;
    refreshOnPrint.set = enabled;
    if (frameworkHooks.refreshOnPrint != nullptr) {
        frameworkHooks.refreshOnPrint(enabled);
    }
}

void idCommonLocal::PrintWarnings() {
    idLibPrint::Printf("------------- Warnings ---------------\n");
    idLibPrint::Printf("during %s...\n", warningList.caption.c_str());
    for (int index = 0; index < warningList.list.Num(); ++index) {
        idLibPrint::Printf("%s", warningList.list[index].message.c_str());
    }
    idLibPrint::Printf("%d warnings\n", warningList.list.Num());
    idLibPrint::Printf("--------------------------------------\n");
    ClearWarnings("");
}

void idCommonLocal::DumpWarnings(const char* const fileName) {
    if (fileSystem == nullptr || fileName == nullptr || *fileName == '\0') {
        return;
    }
    idFile* const file = fileSystem->OpenFileWrite(fileName, FSPATH_BASE);
    if (file == nullptr) return;
    for (int index = 0; index < warningList.list.Num(); ++index) {
        const idStr& message = warningList.list[index].message;
        file->Write(message.c_str(),
            static_cast<unsigned int>(message.Length()));
        if (message.Length() == 0
                || message.c_str()[message.Length() - 1] != '\n') {
            const char newline = '\n';
            file->Write(&newline, 1);
        }
    }
    delete file;
}

void idCommonLocal::ClearWarnings(const char* const reason) {
    warningList.caption = reason != nullptr ? reason : "";
    warningList.list.ClearFree();
    warningList.hash.Clear();
}

namespace tech5Framework {
void Print(unsigned int color, const char* format, ...) {
    char text[4096]; va_list args; va_start(args, format);
    std::vsnprintf(text, sizeof(text), format != nullptr ? format : "", args); va_end(args);
    runtimeState_t& state = State();
    { std::lock_guard<std::recursive_mutex> lock(state.mutex);
      state.consoleLines.push_back({++state.consoleSequence, color, idStr(text)});
      while (state.consoleLines.size() > 2048) state.consoleLines.pop_front(); }
    idLibPrint::Printf("%s", text);
}
} // namespace tech5Framework
