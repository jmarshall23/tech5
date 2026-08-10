#include "framework/framework_runtime_internal.h"

#include "framework/framework_hooks.h"
#include "framework/debughud.h"

#include <algorithm>
#include <cstdarg>
#include <cstdio>
#include <cstring>

namespace {

unsigned int PackDebugColor(const idColor& color) {
    auto channel = [](const float value) {
        const float clamped = value < 0.0f ? 0.0f : value > 1.0f ? 1.0f : value;
        return static_cast<unsigned int>(clamped * 255.0f + 0.5f);
    };
    return channel(color.r) | (channel(color.g) << 8)
        | (channel(color.b) << 16) | (channel(color.a) << 24);
}

} // namespace

namespace tech5Framework {
void SetDebugHUDValue(const char* name, const char* value) { if (name == nullptr) return; runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); state.debugHUD[name] = value != nullptr ? value : ""; }
void DrawDebugHUD(idRenderModelGui* gui) { if (frameworkHooks.drawString == nullptr) return; runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); float y = 8.0f; for (const auto& row : state.debugHUD) { idStr text(row.first.c_str()); text.Append(": "); text.Append(row.second); frameworkHooks.drawString(gui, 8.0f, y, text.c_str(), 0xFFFFFFFFu, 0.8f); y += 14.0f; } }
void ClearDebugHUD() { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); state.debugHUD.clear(); }
} // namespace tech5Framework

idDebugHUDLocal::idDebugHUDLocal()
    : curColor(1.0f, 1.0f, 1.0f, 1.0f), curScale(1.0f), curX(0), curY(0),
      startX(0), alignRight(false), white(nullptr) {
}

idDebugHUDLocal debugHUDLocal;
idDebugHUD* debugHUD = &debugHUDLocal;

void idDebugHUDLocal::Render(idRenderModelGui* gui) {
    if (frameworkHooks.drawString != nullptr) {
        auto drawList = [gui](const idList<debugText_t, 5>& list) {
            for (int index = 0; index < list.Num(); ++index) {
                const debugText_t& item = list[index];
                if ((item.flags & DTFL_BACKGROUNDCOLOR) != 0
                    && frameworkHooks.drawRect != nullptr) {
                    frameworkHooks.drawRect(gui, static_cast<float>(item.x),
                        static_cast<float>(item.y),
                        static_cast<float>((std::max)(item.len, 1))
                            * 8.0f * item.scale,
                        12.0f * item.scale,
                        PackDebugColor(item.backgroundColor));
                }
                frameworkHooks.drawString(gui, static_cast<float>(item.x),
                    static_cast<float>(item.y), item.text.c_str(),
                    PackDebugColor(item.color), item.scale);
            }
        };
        drawList(persistentText);
        drawList(debugText);
    }
    tech5Framework::DrawDebugHUD(gui);
}

void idDebugHUDLocal::Frame() { debugText.Clear(); }

void idDebugHUDLocal::Clear(bool persistent) {
    debugText.Clear();
    if (persistent) persistentText.Clear();
    tech5Framework::ClearDebugHUD();
}

void idDebugHUDLocal::Printf(const char* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    AppendFormatted(debugText, curX, curY, curColor,
        idColor(0.0f, 0.0f, 0.0f, 0.0f), curScale,
        alignRight ? DTFL_RIGHTALIGN : 0, format, arguments);
    va_end(arguments);
    ++curY;
}

void idDebugHUDLocal::AppendFormatted(idList<debugText_t, 5>& destination,
        const int x, const int y, const idColor& color,
        const idColor& background, const float scale, const int flags,
        const char* const format, va_list arguments) {
    char text[2048];
    std::vsnprintf(text, sizeof(text), format != nullptr ? format : "",
        arguments);
    text[sizeof(text) - 1] = '\0';
    debugText_t item = {idStr(text), static_cast<int>(std::strlen(text)), x,
        y, color, flags, scale, background};
    destination.Append(item);
    idStr key;
    key.Format("%d:%d", x, y);
    tech5Framework::SetDebugHUDValue(key.c_str(), text);
}

void idDebugHUDLocal::VPrintf(const int x, const int y,
        const char* const format, va_list arguments) {
    AppendFormatted(debugText, x, y, curColor,
        idColor(0.0f, 0.0f, 0.0f, 0.0f), curScale,
        alignRight ? DTFL_RIGHTALIGN : 0, format, arguments);
}

void idDebugHUDLocal::Printf(const int x, const int y,
        const char* const format, ...) {
    va_list arguments; va_start(arguments, format);
    VPrintf(x, y, format, arguments);
    va_end(arguments);
}

void idDebugHUDLocal::VPrintf(const int x, const int y,
        const idColor& color, const idColor& background,
        const char* const format, va_list arguments) {
    AppendFormatted(debugText, x, y, color, background, curScale,
        (alignRight ? DTFL_RIGHTALIGN : 0) | DTFL_COLOR
            | DTFL_BACKGROUNDCOLOR,
        format, arguments);
}

void idDebugHUDLocal::Printf(const int x, const int y,
        const idColor& color, const idColor& background,
        const char* const format, ...) {
    va_list arguments; va_start(arguments, format);
    VPrintf(x, y, color, background, format, arguments);
    va_end(arguments);
}

void idDebugHUDLocal::VPrintf(const int x, const int y,
        const idColor& color, const char* const format, va_list arguments) {
    AppendFormatted(debugText, x, y, color,
        idColor(0.0f, 0.0f, 0.0f, 0.0f), curScale,
        (alignRight ? DTFL_RIGHTALIGN : 0) | DTFL_COLOR,
        format, arguments);
}

void idDebugHUDLocal::Printf(const int x, const int y,
        const idColor& color, const char* const format, ...) {
    va_list arguments; va_start(arguments, format);
    VPrintf(x, y, color, format, arguments);
    va_end(arguments);
}

void idDebugHUDLocal::Printf(const int x, const int y,
        const idColor& color, const float scale, const char* const format,
        ...) {
    va_list arguments; va_start(arguments, format);
    AppendFormatted(debugText, x, y, color,
        idColor(0.0f, 0.0f, 0.0f, 0.0f), scale,
        (alignRight ? DTFL_RIGHTALIGN : 0) | DTFL_COLOR | DTFL_SCALE,
        format, arguments);
    va_end(arguments);
}

void idDebugHUDLocal::VPrintf(const int x, const int y,
        const idColor& color, const float scale, const int flags,
        const char* const format, va_list arguments) {
    AppendFormatted(debugText, x, y, color,
        idColor(0.0f, 0.0f, 0.0f, 0.0f), scale,
        flags | DTFL_COLOR | DTFL_SCALE, format, arguments);
}

void idDebugHUDLocal::Printf(const int x, const int y,
        const idColor& color, const idColor& background, const float scale,
        const char* const format, ...) {
    va_list arguments; va_start(arguments, format);
    AppendFormatted(debugText, x, y, color, background, scale,
        (alignRight ? DTFL_RIGHTALIGN : 0) | DTFL_COLOR | DTFL_SCALE
            | DTFL_BACKGROUNDCOLOR,
        format, arguments);
    va_end(arguments);
}

void idDebugHUDLocal::VPrintf(const int x, const int y,
        const idColor& color, const idColor& background, const float scale,
        const int flags, const char* const format, va_list arguments) {
    AppendFormatted(debugText, x, y, color, background, scale,
        flags | DTFL_COLOR | DTFL_SCALE | DTFL_BACKGROUNDCOLOR,
        format, arguments);
}

void idDebugHUDLocal::AddPersistentText(const int x, const int y,
        const idColor& color, const float scale, const char* const format,
        ...) {
    va_list arguments; va_start(arguments, format);
    AppendFormatted(persistentText, x, y, color,
        idColor(0.0f, 0.0f, 0.0f, 0.0f), scale,
        DTFL_PERSIST | DTFL_COLOR | DTFL_SCALE
            | (alignRight ? DTFL_RIGHTALIGN : 0),
        format, arguments);
    va_end(arguments);
}

void idDebugHUDLocal::RemovePersistentText(const int x, const int y) {
    for (int index = persistentText.Num() - 1; index >= 0; --index) {
        if (persistentText[index].x == x && persistentText[index].y == y) {
            persistentText.RemoveIndex(index);
        }
    }
}

void idDebugHUDLocal::SetLeftAlign() { alignRight = false; }
void idDebugHUDLocal::SetRightAlign() { alignRight = true; }
void idDebugHUDLocal::SetTextPosition(const int x, const int y) {
    curX = startX = x;
    curY = y;
}
void idDebugHUDLocal::SetTextScale(const float scale) { curScale = scale; }
void idDebugHUDLocal::SetTextColor(const idColor& color) { curColor = color; }
