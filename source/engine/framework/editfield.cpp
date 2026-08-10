#include "framework/editfield.h"

#include "framework/framework_hooks.h"

#include <algorithm>
#include <string>

namespace {
constexpr int KEY_BACKSPACE = 8;
constexpr int KEY_TAB = 9;
constexpr int KEY_ENTER = 13;
constexpr int KEY_INSERT = 45;
constexpr int KEY_DELETE = 46;
constexpr int KEY_LEFT = 37;
constexpr int KEY_RIGHT = 39;
constexpr int KEY_HOME = 36;
constexpr int KEY_END = 35;
}

idEditField::idEditField()
    : overstrikeMode(false), cursor(0), scroll(0), widthInChars(0) {
}

idEditField::~idEditField() = default;

void idEditField::Draw(idRenderModelGui* const gui, const int x, const int y,
        const int width, const bool showCursor) const {
    if (frameworkHooks.drawString == nullptr) {
        return;
    }
    const int visibleChars = std::max(1, width / 8);
    const int first = std::max(0, std::min(scroll, buffer.Length()));
    std::string visible(buffer.c_str() + first);
    if (static_cast<int>(visible.size()) > visibleChars) {
        visible.resize(static_cast<std::size_t>(visibleChars));
    }
    frameworkHooks.drawString(gui, static_cast<float>(x),
        static_cast<float>(y), visible.c_str(), 0xFFFFFFFFu, 1.0f);
    if (showCursor && frameworkHooks.drawRect != nullptr) {
        const float cursorX = static_cast<float>(x + (cursor - first) * 8);
        frameworkHooks.drawRect(gui, cursorX, static_cast<float>(y),
            overstrikeMode ? 8.0f : 1.0f, 16.0f, 0xFFFFFFFFu);
    }
}

void idEditField::Clear() {
    buffer.Clear();
    cursor = 0;
    scroll = 0;
    autoComplete.Clear();
}

void idEditField::ClearAutoComplete() {
    autoComplete.Clear();
}

bool idEditField::AcceptAutoComplete() {
    if (autoComplete.GetNumSuggestions() <= 0) {
        return false;
    }
    SetBuffer(autoComplete.GetSuggestion(0).c_str());
    autoComplete.Clear();
    return true;
}

void idEditField::AutoComplete(const bool reverse) {
    if (autoComplete.GetNumSuggestions() <= 0) {
        return;
    }
    const int index = reverse ? autoComplete.GetNumSuggestions() - 1 : 0;
    SetBuffer(autoComplete.GetSuggestion(index).c_str());
}

void idEditField::CharEvent(const int character) {
    if (character == KEY_BACKSPACE) {
        if (cursor > 0) {
            std::string value(buffer.c_str());
            value.erase(static_cast<std::size_t>(--cursor), 1);
            buffer = value.c_str();
        }
        return;
    }
    if (character < 32 || character > 126) {
        return;
    }
    std::string value(buffer.c_str());
    if (overstrikeMode && cursor < static_cast<int>(value.size())) {
        value[static_cast<std::size_t>(cursor)] = static_cast<char>(character);
    } else {
        value.insert(value.begin() + cursor, static_cast<char>(character));
    }
    ++cursor;
    buffer = value.c_str();
    autoComplete.Clear();
}

void idEditField::Paste() {
    if (frameworkHooks.clipboard == nullptr) {
        return;
    }
    const char* text = frameworkHooks.clipboard();
    while (text != nullptr && *text != '\0') {
        CharEvent(static_cast<unsigned char>(*text++));
    }
}

void idEditField::SetBuffer(const char* const text) {
    buffer = text != nullptr ? text : "";
    cursor = buffer.Length();
    scroll = 0;
    autoComplete.Clear();
}

bool idEditField::KeyDownEvent(const int key) {
    switch (key) {
    case KEY_TAB: return AcceptAutoComplete();
    case KEY_INSERT: overstrikeMode = !overstrikeMode; return true;
    case KEY_LEFT: cursor = std::max(0, cursor - 1); return true;
    case KEY_RIGHT: cursor = std::min(buffer.Length(), cursor + 1); return true;
    case KEY_HOME: cursor = 0; return true;
    case KEY_END: cursor = buffer.Length(); return true;
    case KEY_DELETE:
        if (cursor < buffer.Length()) {
            std::string value(buffer.c_str());
            value.erase(static_cast<std::size_t>(cursor), 1);
            buffer = value.c_str();
        }
        return true;
    case KEY_ENTER: return true;
    default: return false;
    }
}
