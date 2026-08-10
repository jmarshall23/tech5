#include "framework/consolewatch.h"

#include "idlib/containers/list.h"

namespace {
idList<idConsoleWatch, 5> consoleWatches;
}

void Framework_AddConsoleWatch(const char* expression, const int x,
        const int y) {
    if (expression == nullptr || *expression == '\0') {
        return;
    }
    for (int index = 0; index < consoleWatches.Num(); ++index) {
        if (idStr::Cmp(consoleWatches[index]._watchString.c_str(), expression) == 0) {
            consoleWatches[index]._drawX = x;
            consoleWatches[index]._drawY = y;
            return;
        }
    }
    consoleWatches.Append(idConsoleWatch(expression, x, y));
}

bool Framework_RemoveConsoleWatch(const char* expression) {
    if (expression == nullptr) {
        return false;
    }
    for (int index = 0; index < consoleWatches.Num(); ++index) {
        if (idStr::Cmp(consoleWatches[index]._watchString.c_str(), expression) == 0) {
            return consoleWatches.RemoveIndex(index);
        }
    }
    return false;
}

void Framework_ClearConsoleWatches() {
    consoleWatches.Clear();
}

int Framework_NumConsoleWatches() {
    return consoleWatches.Num();
}

const idConsoleWatch* Framework_GetConsoleWatch(const int index) {
    return index >= 0 && index < consoleWatches.Num() ? &consoleWatches[index]
                                                       : nullptr;
}
