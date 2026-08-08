#include "lib_print.h"

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

namespace {

struct warningInfo_t { const char* type; const char* name; };

std::recursive_mutex printMutex;
idPrintListener* listeners = nullptr;
std::array<warningInfo_t, 32> warningInfo{};
int numWarningInfo = 0;
idLibPrint::fatalErrorHandler_t fatalErrorHandler = nullptr;
const std::thread::id mainThread = std::this_thread::get_id();

std::string RemoveColors(const std::string& source) {
    std::string result;
    result.reserve(source.size());
    for (std::size_t index = 0; index < source.size(); ++index) {
        if (source[index] == '^' && index + 1 < source.size()
            && source[index + 1] >= '0' && source[index + 1] <= '9') {
            ++index;
        } else {
            result.push_back(source[index]);
        }
    }
    return result;
}

std::string Format(const char* format, va_list args) {
    char buffer[4096] = {};
    const int amount = std::vsnprintf(buffer, sizeof(buffer),
        format == nullptr ? "" : format, args);
    if (amount < 0) {
        buffer[sizeof(buffer) - 2] = '\n';
        buffer[sizeof(buffer) - 1] = '\0';
    }
    return buffer;
}

const char* Prefix(const printSeverity_t severity) {
    switch (severity) {
        case SEV_WARNING: return "^3WARNING: ^1";
        case SEV_ERROR: return "^3ERROR: ^1";
        case SEV_FATAL: return "^3FATAL ERROR: ^1";
        default: return "";
    }
}

void ThrowMessage(const printSeverity_t severity, const std::string& message) {
    throw idRecoveredPrintException(RemoveColors(message).c_str(),
        severity == SEV_FATAL);
}

} // namespace

idPrintListener::idPrintListener()
    : next(nullptr), wantColor(true), threadSafe(false),
      minSeverity(SEV_PRINT) {}

idPrintListener::~idPrintListener() { UnRegisterPrintListener(); }

void idPrintListener::RegisterPrintListener() {
    idLibPrint::RegisterPrintListener(this);
}

void idPrintListener::UnRegisterPrintListener() {
    idLibPrint::UnRegisterPrintListener(this);
}

bool idLibPrint::PushWarningInfo(const char* type, const char* name) {
    std::lock_guard<std::recursive_mutex> lock(printMutex);
    if (numWarningInfo >= static_cast<int>(warningInfo.size())) return false;
    warningInfo[static_cast<std::size_t>(numWarningInfo++)] = {type, name};
    return true;
}

void idLibPrint::PopWarningInfo() {
    std::lock_guard<std::recursive_mutex> lock(printMutex);
    if (numWarningInfo > 0) --numWarningInfo;
}

void idLibPrint::RegisterFatalErrorHandler(fatalErrorHandler_t handler) {
    std::lock_guard<std::recursive_mutex> lock(printMutex);
    fatalErrorHandler = handler;
}

void idLibPrint::RegisterPrintListener(idPrintListener* listener) {
    if (listener == nullptr) return;
    std::lock_guard<std::recursive_mutex> lock(printMutex);
    for (idPrintListener* current = listeners; current != nullptr;
            current = current->next) {
        if (current == listener) return;
    }
    listener->next = listeners;
    listeners = listener;
}

void idLibPrint::UnRegisterPrintListener(idPrintListener* listener) {
    if (listener == nullptr) return;
    std::lock_guard<std::recursive_mutex> lock(printMutex);
    idPrintListener** link = &listeners;
    while (*link != nullptr && *link != listener) link = &(*link)->next;
    if (*link == listener) {
        *link = listener->next;
        listener->next = nullptr;
    }
}

void idLibPrint::Dispatch(const printSeverity_t severity, const char* format,
        va_list args) {
    va_list copy;
    va_copy(copy, args);
    std::string message = Prefix(severity);
    message += Format(format, copy);
    va_end(copy);

    std::lock_guard<std::recursive_mutex> lock(printMutex);
    if (severity >= SEV_WARNING) {
        for (int index = numWarningInfo - 1; index >= 0; --index) {
            message += index == numWarningInfo - 1
                ? " ^7while loading " : " ^8from ";
            message += warningInfo[static_cast<std::size_t>(index)].type == nullptr
                ? "" : warningInfo[static_cast<std::size_t>(index)].type;
            message.push_back(' ');
            message += warningInfo[static_cast<std::size_t>(index)].name == nullptr
                ? "" : warningInfo[static_cast<std::size_t>(index)].name;
        }
        message.push_back('\n');
    }

    const bool onMainThread = std::this_thread::get_id() == mainThread;
    bool delivered = false;
    for (idPrintListener* listener = listeners; listener != nullptr;
            listener = listener->next) {
        if (listener->wantColor && severity >= listener->minSeverity
            && (onMainThread || listener->threadSafe)) {
            listener->Print(message.c_str());
            delivered = true;
        }
    }
    const std::string plain = RemoveColors(message);
    for (idPrintListener* listener = listeners; listener != nullptr;
            listener = listener->next) {
        if (!listener->wantColor && severity >= listener->minSeverity
            && (onMainThread || listener->threadSafe)) {
            listener->Print(plain.c_str());
            delivered = true;
        }
    }
    if (!delivered) std::fputs(plain.c_str(), stderr);

    if (severity == SEV_FATAL && fatalErrorHandler != nullptr) {
        fatalErrorHandler(plain.c_str());
    }
    if (severity >= SEV_ERROR) ThrowMessage(severity, message);
}

void idLibPrint::Debugf(const char* format, ...) {
    va_list args; va_start(args, format); Dispatch(SEV_DEBUG, format, args); va_end(args);
}

void idLibPrint::Printf(const char* format, ...) {
    va_list args; va_start(args, format); Dispatch(SEV_PRINT, format, args); va_end(args);
}

void idLibPrint::PrintfIf(const bool condition, const char* format, ...) {
    if (!condition) return;
    va_list args; va_start(args, format); Dispatch(SEV_PRINT, format, args); va_end(args);
}

void idLibPrint::VPrintf(const char* format, va_list args) {
    Dispatch(SEV_PRINT, format, args);
}

void idLibPrint::Warning(const char* format, ...) {
    va_list args; va_start(args, format); Dispatch(SEV_WARNING, format, args); va_end(args);
}

void idLibPrint::WarningIf(const bool condition, const char* format, ...) {
    if (!condition) return;
    va_list args; va_start(args, format); Dispatch(SEV_WARNING, format, args); va_end(args);
}

void idLibPrint::Error(const char* format, ...) {
    va_list args; va_start(args, format); Dispatch(SEV_ERROR, format, args); va_end(args);
    std::terminate();
}

void idLibPrint::FatalError(const char* format, ...) {
    va_list args; va_start(args, format); Dispatch(SEV_FATAL, format, args); va_end(args);
    std::terminate();
}
