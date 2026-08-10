#include "framework/framework_runtime_internal.h"

#include "framework/debugmenu.h"
#include "framework/fileresource.h"
#include "framework/framework_hooks.h"
#include "framework/sysevent.h"
#include "idlib/text/lexer.h"

#include <algorithm>
#include <cctype>
#include <cmath>

namespace {

unsigned int PackColor(const idVec4& color) {
    const auto channel = [](const float value) {
        return static_cast<unsigned int>(std::lround(
            (std::max)(0.0f, (std::min)(1.0f, value)) * 255.0f));
    };
    return channel(color.x) | (channel(color.y) << 8u)
        | (channel(color.z) << 16u) | (channel(color.w) << 24u);
}

void SetMenuActive(const bool active) {
    tech5Framework::DebugMenuSet("__active", active ? "1" : "0");
}

bool GetMenuActive() {
    idStr value;
    return tech5Framework::DebugMenuGet("__active", value)
        && idStr::Cmp(value.c_str(), "1") == 0;
}

} // namespace

namespace tech5Framework {
void DebugMenuSet(const char* path, const char* value) { if (path == nullptr) return; runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); state.debugMenu[path] = value != nullptr ? value : ""; }
bool DebugMenuGet(const char* path, idStr& value) { if (path == nullptr) return false; runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); const auto found = state.debugMenu.find(path); if (found == state.debugMenu.end()) return false; value = found->second; return true; }
void DebugMenuClear() { runtimeState_t& state = State(); std::lock_guard<std::recursive_mutex> lock(state.mutex); state.debugMenu.clear(); }
} // namespace tech5Framework

idDebugMenuLocal debugMenuLocal;
idDebugMenu* debugMenu = &debugMenuLocal;

idDebugMenuLocal::CEntry::CEntry()
    : valid(true), shortcut(0), color(1.0f, 1.0f, 1.0f, 1.0f) {
}

idDebugMenuLocal::CEntry& idDebugMenuLocal::CEntry::operator=(
    const CEntry& other) {
    if (this != &other) {
        valid = other.valid;
        shortcut = other.shortcut;
        title = other.title;
        description = other.description;
        cmd = other.cmd;
        entityValid = other.entityValid;
        entityDescr = other.entityDescr;
        color = other.color;
    }
    return *this;
}

idDebugMenuLocal::idDebugMenuLocal()
    : modKeyPressed(false), selectedGroup(0), selectedItem(0), startItem(0),
      guiModel(nullptr), font(nullptr) {
}

idDebugMenuLocal::~idDebugMenuLocal() {
    if (guiModel != nullptr && frameworkHooks.destroyGui != nullptr) {
        frameworkHooks.destroyGui(guiModel);
    }
    guiModel = nullptr;
}

bool idDebugMenuLocal::idLexerJSON_ExpectLiteralToken(idLexer& src,
    const char* token) {
    idToken parsed;
    return src.ReadToken(parsed) && idStr::Cmp(parsed.c_str(), token) == 0;
}

bool idDebugMenuLocal::idLexerJSON_ExpectString(idLexer& src,
    const char* string) {
    idToken parsed;
    if (!src.ReadToken(parsed)) {
        return false;
    }
    if (parsed.type != TT_STRING) {
        src.UnreadToken();
        return false;
    }
    return idStr::Cmp(parsed.c_str(), string) == 0;
}

bool idDebugMenuLocal::ReadEntry(idLexer& src, CEntry& entry) {
    idToken key;
    idToken value;
    if (!src.ReadToken(key)) {
        return true;
    }

    for (;;) {
        if (!idLexerJSON_ExpectLiteralToken(src, ":")
            || !src.ReadToken(value)) {
            return false;
        }

        if (idStr::Cmp(key.c_str(), "shortKey") == 0) {
            const unsigned char character = value.Length() == 0
                ? 0 : static_cast<unsigned char>(value[0]);
            entry.shortcut = std::toupper(character);
        } else if (idStr::Cmp(key.c_str(), "title") == 0) {
            entry.title = value;
        } else if (idStr::Cmp(key.c_str(), "cmd") == 0) {
            entry.cmd = value;
        } else if (idStr::Cmp(key.c_str(), "res") == 0) {
            entry.valid = idFileResource::FileExists(value.c_str());
        } else if (idStr::Cmp(key.c_str(), "entityValid") == 0) {
            entry.entityValid = value;
        } else if (idStr::Cmp(key.c_str(), "help") == 0) {
            entry.description = value;
        } else if (idStr::Cmp(key.c_str(), "entityDescr") == 0) {
            entry.entityDescr = value;
        } else {
            src.Warning("DebugMenu loaded unknown key:value pair (\"%s\" : \"%s\")",
                key.c_str(), value.c_str());
        }

        if (!src.ReadToken(key)) {
            return false;
        }
        if (idStr::Cmp(key.c_str(), "}") == 0) {
            return true;
        }
        if (idStr::Cmp(key.c_str(), ",") != 0
            || !src.ReadToken(key)) {
            return false;
        }
    }
}

bool idDebugMenuLocal::ReadEntries(idLexer& src, CGroup& group) {
    group.items.PreAllocate(32);
    idToken token;
    if (!src.ReadToken(token)) {
        return true;
    }
    while (idStr::Cmp(token.c_str(), "]") != 0) {
        if (idStr::Cmp(token.c_str(), "{") != 0) {
            return false;
        }
        CEntry* entry = group.items.Alloc();
        if (entry == nullptr || !ReadEntry(src, *entry)
            || !src.ReadToken(token)) {
            return false;
        }
        if (idStr::Cmp(token.c_str(), "]") == 0) {
            break;
        }
        if (idStr::Cmp(token.c_str(), ",") != 0
            || !src.ReadToken(token)) {
            return false;
        }
    }
    return true;
}

bool idDebugMenuLocal::ReadGroup(idLexer& src) {
    idToken title;
    if (!idLexerJSON_ExpectString(src, "pageName")
        || !idLexerJSON_ExpectLiteralToken(src, ":")
        || !src.ReadToken(title)) {
        return false;
    }

    idToken separator;
    if (!src.ReadToken(separator)) {
        return false;
    }
    if (idStr::Cmp(separator.c_str(), "}") == 0) {
        return true;
    }
    if (idStr::Cmp(separator.c_str(), ",") != 0
        || !idLexerJSON_ExpectString(src, "entries")
        || !idLexerJSON_ExpectLiteralToken(src, ":")
        || !idLexerJSON_ExpectLiteralToken(src, "[")) {
        return false;
    }

    CGroup* group = groups.Alloc();
    if (group == nullptr) {
        return false;
    }
    group->title = title;
    if (!ReadEntries(src, *group)
        || !idLexerJSON_ExpectLiteralToken(src, "}")) {
        groups.RemoveIndex(groups.Num() - 1);
        return false;
    }
    return true;
}

bool idDebugMenuLocal::LoadMenu() {
    groups.ClearFree();
    groups.PreAllocate(8);

    idLexer src(LEXFL_NOSTRINGCONCAT);
    if (!src.LoadFile("debugmenu.txt")) {
        src.Warning("Could not find debugmenu.txt");
        return false;
    }
    if (!idLexerJSON_ExpectLiteralToken(src, "{")) {
        return false;
    }

    idToken separator;
    for (;;) {
        if (!ReadGroup(src)) {
            return false;
        }
        if (!src.ReadToken(separator)
            || idStr::Cmp(separator.c_str(), "}") == 0) {
            return true;
        }
        if (idStr::Cmp(separator.c_str(), ",") != 0
            || !idLexerJSON_ExpectLiteralToken(src, "{")) {
            return false;
        }
    }
}

bool idDebugMenuLocal::Init() {
    modKeyPressed = false;
    selectedGroup = selectedItem = startItem = 0;
    SetMenuActive(false);
    if (guiModel == nullptr && frameworkHooks.createGui != nullptr) {
        guiModel = frameworkHooks.createGui();
    }
    return LoadMenu();
}

bool idDebugMenuLocal::IsActive() {
    return GetMenuActive();
}

bool idDebugMenuLocal::HandleGuiEvent(const sysEvent_t* event) {
    if (event == nullptr || groups.IsEmpty()) {
        return false;
    }
    const sysEvent_t& sev = *event;
    if (sev.evType != SE_KEY) {
        return IsActive();
    }

    if (sev.evValue == 265) {
        modKeyPressed = sev.evValue2 != 0;
    }
    if (sev.evValue2 == 0) {
        return IsActive();
    }
    if ((modKeyPressed && sev.evValue == 264) || sev.evValue == 87) {
        SetMenuActive(sev.evValue == 87 ? !IsActive() : true);
        return true;
    }
    if (!IsActive()) {
        return false;
    }

    CGroup& group = groups[selectedGroup];
    if (sev.evValue >= 'A' && sev.evValue <= 'Z') {
        for (int index = 0; index < group.items.Num(); ++index) {
            if (group.items[index].shortcut == sev.evValue) {
                selectedItem = index;
                break;
            }
        }
        return true;
    }

    switch (sev.evValue) {
    case 1:
    case 257:
        SetMenuActive(false);
        break;
    case 200:
    case 282:
        --selectedItem;
        break;
    case 208:
    case 283:
        ++selectedItem;
        break;
    case 201:
    case 280:
        --selectedGroup;
        selectedItem = startItem = 0;
        break;
    case 209:
    case 281:
        ++selectedGroup;
        selectedItem = startItem = 0;
        break;
    case 28:
    case 256:
        if (selectedItem >= 0 && selectedItem < group.items.Num()) {
            CEntry& entry = group.items[selectedItem];
            if (entry.valid && entry.cmd.Length() != 0) {
                tech5Framework::ExecuteCommand(entry.cmd.c_str());
            }
        }
        break;
    default:
        break;
    }

    if (selectedGroup < 0) {
        selectedGroup = groups.Num() - 1;
    } else if (selectedGroup >= groups.Num()) {
        selectedGroup = 0;
    }
    const int count = groups[selectedGroup].items.Num();
    if (count == 0) {
        selectedItem = 0;
    } else if (selectedItem < 0) {
        selectedItem = count - 1;
    } else if (selectedItem >= count) {
        selectedItem = 0;
    }
    return true;
}

idRenderModelGui* idDebugMenuLocal::Render() {
    if (guiModel == nullptr || groups.IsEmpty() || !IsActive()) {
        return guiModel;
    }
    if (frameworkHooks.drawRect != nullptr) {
        frameworkHooks.drawRect(guiModel, 48.0f, 48.0f, 928.0f, 624.0f,
            0xD0202020u);
    }
    if (frameworkHooks.drawString == nullptr) {
        return guiModel;
    }

    float x = 64.0f;
    for (int index = 0; index < groups.Num(); ++index) {
        frameworkHooks.drawString(guiModel, x, 184.0f,
            groups[index].title.c_str(),
            index == selectedGroup ? 0xFFFFFFFFu : 0xFF909090u, 0.4f);
        x += static_cast<float>(groups[index].title.Length() * 9 + 24);
    }

    const CGroup& group = groups[selectedGroup];
    float y = 232.0f;
    for (int index = startItem; index < group.items.Num(); ++index) {
        const CEntry& entry = group.items[index];
        unsigned int color = entry.valid ? PackColor(entry.color) : 0xFF606060u;
        if (index == selectedItem) {
            if (frameworkHooks.drawRect != nullptr) {
                frameworkHooks.drawRect(guiModel, 60.0f, y - 2.0f,
                    880.0f, 22.0f, 0x604080C0u);
            }
            color = entry.valid ? 0xFFFFFFFFu : 0xFF808080u;
        }
        idStr line;
        if (entry.shortcut != 0) {
            char prefix[5] = { '[', static_cast<char>(entry.shortcut), ']', ' ', 0 };
            line = prefix;
        }
        line.Append(entry.title);
        frameworkHooks.drawString(guiModel, 64.0f, y, line.c_str(), color, 0.4f);
        y += 24.0f;
        if (y > 620.0f) {
            break;
        }
    }
    if (selectedItem >= 0 && selectedItem < group.items.Num()
        && group.items[selectedItem].description.Length() != 0) {
        frameworkHooks.drawString(guiModel, 64.0f, 640.0f,
            group.items[selectedItem].description.c_str(), 0xFFD0D0D0u, 0.4f);
    }
    return guiModel;
}
