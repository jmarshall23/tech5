#include "sys.h"

#include <string>

namespace {

std::string DiagnosticText(const char* const severity,
        const ssString& message, const ssThreadInfo_t* const threadInfo) {
    std::string text("^1SuperScript ");
    text += severity;
    text += ":^3 ";
    if (threadInfo != nullptr) {
        text += Tungsten_GetSuperScriptObjectFullName(
            threadInfo->spawnId, threadInfo->objectId);
        text += ".";
        text += threadInfo->name;
        text += ": ";
    }
    text += message.c_str();
    text += "^0\n";
    return text;
}

} // namespace

// Retail symbol: ?Warning@@YAXABVssString@@@Z
// EA: 0x82EE8758, RVA: 0x00EE8758
void Warning(const ssString& message) {
    ssThreadInfo_t threadInfo{};
    if (Tungsten_GetSuperScriptThreadInfo(-1, threadInfo)) {
        const std::string text = DiagnosticText("Warning", message, &threadInfo);
        Tungsten_SuperScriptPrint(text.c_str());
        Tungsten_SuperScriptWaitFrame();
    } else {
        const std::string text = DiagnosticText("Warning", message, nullptr);
        Tungsten_SuperScriptPrint(text.c_str());
    }
}

// Retail symbol: ?Error@@YAXABVssString@@@Z
// EA: 0x82EE8858, RVA: 0x00EE8858
void Error(const ssString& message) {
    ssThreadInfo_t threadInfo{};
    if (Tungsten_GetSuperScriptThreadInfo(-1, threadInfo)) {
        const std::string text = DiagnosticText("Error", message, &threadInfo);
        Tungsten_SuperScriptPrint(text.c_str());
        Tungsten_TerminateSuperScriptThread(-1);
    } else {
        const std::string text = DiagnosticText("Error", message, nullptr);
        Tungsten_SuperScriptPrint(text.c_str());
    }
}
