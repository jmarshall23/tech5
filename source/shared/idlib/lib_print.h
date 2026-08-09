#pragma once

#include <cstdarg>
#include <stdexcept>

enum printSeverity_t {
    SEV_DEBUG = 0,
    SEV_PRINT = 1,
    SEV_WARNING = 2,
    SEV_ERROR = 3,
    SEV_FATAL = 4
};

class idPrintListener {
public:
    idPrintListener();
    virtual ~idPrintListener();
    virtual void Print(const char* text) = 0;

    void RegisterPrintListener();
    void UnRegisterPrintListener();

    idPrintListener* next;
    bool wantColor;
    bool threadSafe;
    printSeverity_t minSeverity;
};

class idRecoveredPrintException : public std::runtime_error {
public:
    idRecoveredPrintException(const char* message, bool fatal)
        : std::runtime_error(message == nullptr ? "" : message),
          fatalError(fatal) {}
    bool IsFatal() const { return fatalError; }
private:
    bool fatalError;
};

// Recovered listener/context side of the idLib print interface. The common
// Printf/Warning/Error entry points share this PC implementation.
class idLibPrint {
public:
    using fatalErrorHandler_t = void (*)(const char*);

    static bool PushWarningInfo(const char* type, const char* name);
    static void PopWarningInfo();
    static void RegisterFatalErrorHandler(fatalErrorHandler_t handler);

    static void Debugf(const char* format, ...);
    static void Printf(const char* format, ...);
    static void PrintfIf(bool condition, const char* format, ...);
    static void VPrintf(const char* format, va_list args);
    static void Warning(const char* format, ...);
    static void WarningIf(bool condition, const char* format, ...);
    [[noreturn]] static void Error(const char* format, ...);
    [[noreturn]] static void FatalError(const char* format, ...);

    static void Dispatch(printSeverity_t severity, const char* format,
        va_list args);
    static void RegisterPrintListener(idPrintListener* listener);
    static void UnRegisterPrintListener(idPrintListener* listener);
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idPrintListener) == 16,
    "Recovered idPrintListener layout changed");
#endif
