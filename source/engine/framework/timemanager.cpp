#include "framework/timemanager.h"

idTimeManager timeManager;

void idTimeManager::SetGameHz(const int hertz) {
    if (hertz <= 0) {
        return;
    }
    gameHz = hertz;
    gameTimePerFrame = static_cast<int>(1000.0f / static_cast<float>(hertz));
}
