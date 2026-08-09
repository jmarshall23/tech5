#include "sys_assert.h"

#include "../lib_print.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

bool AssertFailed(const char* file, const int line, const char* expression,
        const bool inlineBreak) {
    idLibPrint::Warning("ASSERTION FAILED! %s(%d): '%s'",
        file == nullptr ? "" : file, line,
        expression == nullptr ? "" : expression);
    if (!inlineBreak && IsDebuggerPresent()) DebugBreak();
    return inlineBreak;
}
