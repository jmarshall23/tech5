#include "cvarsystem.h"

#include "idlib/lib_print.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace {

idCVar* staticVars = nullptr;
bool staticCVarsRegistered = false;

idCVarSystemLocal localCVarSystem;

bool ContainsCaseInsensitive(const char* text, const char* fragment) {
    if (fragment == nullptr || *fragment == '\0') return true;
    if (text == nullptr) return false;
    const std::size_t fragmentLength = std::strlen(fragment);
    for (const char* cursor = text; *cursor != '\0'; ++cursor) {
        std::size_t index = 0;
        while (index < fragmentLength && cursor[index] != '\0'
                && std::tolower(static_cast<unsigned char>(cursor[index]))
                    == std::tolower(static_cast<unsigned char>(fragment[index]))) {
            ++index;
        }
        if (index == fragmentLength) return true;
    }
    return false;
}

idStr JoinArgs(const idCmdArgs& args, const int first) {
    idStr result;
    for (int index = first; index < args.Argc(); ++index) {
        if (index != first) result.Append(' ');
        result.Append(args.Argv(index));
    }
    return result;
}

void FormatInteger(char* buffer, const std::size_t size, const int value) {
    std::snprintf(buffer, size, "%d", value);
}

void FormatFloat(char* buffer, const std::size_t size, const float value) {
    std::snprintf(buffer, size, "%.9g", static_cast<double>(value));
}

} // namespace

idCVarSystem* cvarSystem = &localCVarSystem;

idCVarSystem::~idCVarSystem() = default;

idCVar::idCVar(const char* const name, const char* const value,
        const int flags, const char* const description,
        const valueCompletion_t completion) {
    Init(name, value, flags, description, 1.0f, -1.0f, nullptr,
        completion);
}

idCVar::idCVar(const char* const name, const char* const value,
        const int flags, const char* const description, const float valueMin,
        const float valueMax, const valueCompletion_t completion) {
    Init(name, value, flags, description, valueMin, valueMax, nullptr,
        completion);
}

idCVar::idCVar(const char* const name, const char* const value,
        const int flags, const char* const description,
        const char** const valueStrings, const valueCompletion_t completion) {
    Init(name, value, flags, description, 1.0f, -1.0f, valueStrings,
        completion);
}

void idCVar::Init(const char* const newName, const char* const value,
        const int newFlags, const char* const newDescription,
        const float newValueMin, const float newValueMax,
        const char** const newValueStrings,
        const valueCompletion_t newValueCompletion) {
    name = newName != nullptr ? newName : "";
    resetString = value != nullptr ? value : "";
    description = newDescription != nullptr ? newDescription : "";
    valueStrings = newValueStrings;
    valueCompletion = newValueCompletion;
    valueMin = newValueMin;
    valueMax = newValueMax;
    flags = (newFlags & (CVAR_NOCHEAT | CVAR_INIT | CVAR_ROM | CVAR_ARCHIVE))
        ? ((newFlags & ~CVAR_CHEAT) | CVAR_NOCHEAT)
        : (newFlags | CVAR_CHEAT);
    valueString = resetString;
    valueInteger = 0;
    valueFloat = 0.0f;
    onChange = nullptr;
    next = staticVars;
    staticVars = this;
    UpdateValue();

    // The retail code permits late static registration for DLL-owned CVars.
    if (staticCVarsRegistered) RegisterStaticVars();
}

void idCVar::UpdateValue() {
    if ((flags & CVAR_BOOL) != 0) {
        valueInteger = std::strtol(valueString.c_str(), nullptr, 10) != 0;
        valueFloat = static_cast<float>(valueInteger);
        valueString = valueInteger != 0 ? "1" : "0";
    } else if ((flags & CVAR_INTEGER) != 0) {
        long value = std::strtol(valueString.c_str(), nullptr, 10);
        if (valueMin < valueMax) {
            value = (std::max)(static_cast<long>(valueMin),
                (std::min)(value, static_cast<long>(valueMax)));
        }
        valueInteger = static_cast<int>(value);
        valueFloat = static_cast<float>(valueInteger);
        char buffer[32];
        FormatInteger(buffer, sizeof(buffer), valueInteger);
        valueString = buffer;
    } else if ((flags & CVAR_FLOAT) != 0) {
        float value = std::strtof(valueString.c_str(), nullptr);
        if (!std::isfinite(value)) value = 0.0f;
        if (valueMin < valueMax) {
            value = (std::max)(valueMin, (std::min)(value, valueMax));
        }
        valueFloat = value;
        valueInteger = static_cast<int>(value);
        char buffer[64];
        FormatFloat(buffer, sizeof(buffer), valueFloat);
        valueString = buffer;
    } else if (valueStrings != nullptr && valueStrings[0] != nullptr) {
        valueInteger = 0;
        for (int index = 0; valueStrings[index] != nullptr; ++index) {
            if (idStr::Icmp(valueString.c_str(), valueStrings[index]) == 0) {
                valueInteger = index;
                break;
            }
        }
        valueString = valueStrings[valueInteger];
        valueFloat = static_cast<float>(valueInteger);
    } else {
        valueFloat = valueString.Length() < 32
            ? std::strtof(valueString.c_str(), nullptr) : 0.0f;
        valueInteger = static_cast<int>(valueFloat);
    }
    flags |= CVAR_MODIFIED;
    for (cvarCallback_t* callback = onChange; callback != nullptr;
            callback = callback->next) {
        if (callback->callback != nullptr) callback->callback->Call();
    }
}

void idCVar::Reset() { Set(resetString, true); }

bool idCVar::Set(const char* newValue, const bool force) {
    if (!force && (flags & CVAR_INIT) != 0) {
        idLibPrint::Printf("%s can only be set on the command line\n", name);
        return false;
    }
    if (!force && (flags & CVAR_ROM) != 0) {
        idLibPrint::Printf("%s is read only\n", name);
        return false;
    }
    const char* const value = newValue != nullptr ? newValue : resetString;
    if (idStr::Icmp(valueString.c_str(), value) == 0) return false;
    valueString = value;
    UpdateValue();
    localCVarSystem.SetModifiedFlags(flags);
    flags |= CVAR_MODIFIED2;
    return true;
}

void idCVar::SetString(const char* value, const bool force) {
    Set(value, force);
}

void idCVar::SetBool(const bool value, const bool force) {
    Set(value ? "1" : "0", force);
}

void idCVar::SetInteger(const int value, const bool force) {
    char buffer[32];
    FormatInteger(buffer, sizeof(buffer), value);
    Set(buffer, force);
}

void idCVar::SetFloat(const float value, const bool force) {
    char buffer[64];
    FormatFloat(buffer, sizeof(buffer), value);
    Set(buffer, force);
}

void idCVar::RegisterStaticVars() {
    staticCVarsRegistered = true;
    localCVarSystem.cvars.Clear();
    localCVarSystem.cvarHash.Clear();
    for (idCVar* variable = staticVars; variable != nullptr;
            variable = variable->next) {
        if (localCVarSystem.Find(variable->name) != nullptr) continue;
        const int index = localCVarSystem.cvars.Append(variable);
        if (index >= 0) {
            localCVarSystem.cvarHash.Add(
                localCVarSystem.cvarHash.GenerateKeyForString(
                    variable->name, false), index);
        }
    }
}

idCVarSystemLocal::idCVarSystemLocal()
    : cvars(16), cvarHash(1024, 1024, TAG_CVAR), modifiedFlags(0) {}

idCVarSystemLocal::~idCVarSystemLocal() = default;

idCVar* idCVarSystemLocal::Find(const char* const name) const {
    if (name == nullptr) return nullptr;
    const int key = cvarHash.GenerateKeyForString(name, false);
    for (int index = cvarHash.First(key); index >= 0;
            index = cvarHash.Next(index)) {
        if (index < cvars.Num()
                && idStr::Icmp(cvars[index]->name, name) == 0) {
            return cvars[index];
        }
    }
    return nullptr;
}

bool idCVarSystemLocal::CvarExists(const char* const name,
        const bool searchForCvarString) const {
    if (!searchForCvarString) return Find(name) != nullptr;
    for (int index = 0; index < cvars.Num(); ++index) {
        if (ContainsCaseInsensitive(name, cvars[index]->name)) return true;
    }
    return false;
}

void idCVarSystemLocal::FindCvarsByPrefix(const char* const prefix,
        idList<idCVar*>& found) const {
    const char* const text = prefix != nullptr ? prefix : "";
    const std::size_t length = std::strlen(text);
    for (int index = 0; index < cvars.Num(); ++index) {
        bool matches = true;
        for (std::size_t character = 0; character < length; ++character) {
            if (cvars[index]->name[character] == '\0'
                    || std::tolower(static_cast<unsigned char>(
                        cvars[index]->name[character]))
                    != std::tolower(static_cast<unsigned char>(
                        text[character]))) {
                matches = false;
                break;
            }
        }
        if (matches) found.AddUnique(cvars[index]);
    }
}

void idCVarSystemLocal::SetCVarString(const char* name, const char* value,
        const int) {
    idCVar* const variable = Find(name);
    if (variable != nullptr) variable->Set(value, true);
}

void idCVarSystemLocal::SetCVarBool(const char* name, const bool value,
        const int flags) {
    SetCVarString(name, value ? "1" : "0", flags);
}

void idCVarSystemLocal::SetCVarInteger(const char* name, const int value,
        const int flags) {
    char buffer[32];
    FormatInteger(buffer, sizeof(buffer), value);
    SetCVarString(name, buffer, flags);
}

void idCVarSystemLocal::SetCVarFloat(const char* name, const float value,
        const int flags) {
    char buffer[64];
    FormatFloat(buffer, sizeof(buffer), value);
    SetCVarString(name, buffer, flags);
}

const char* idCVarSystemLocal::GetCVarString(const char* name,
        const char* defaultValue) const {
    const idCVar* const variable = Find(name);
    return variable != nullptr ? variable->GetString() : defaultValue;
}

bool idCVarSystemLocal::GetCVarBool(const char* name,
        const bool defaultValue) const {
    const idCVar* const variable = Find(name);
    return variable != nullptr ? variable->GetBool() : defaultValue;
}

int idCVarSystemLocal::GetCVarInteger(const char* name,
        const int defaultValue) const {
    const idCVar* const variable = Find(name);
    return variable != nullptr ? variable->GetInteger() : defaultValue;
}

float idCVarSystemLocal::GetCVarFloat(const char* name,
        const float defaultValue) const {
    const idCVar* const variable = Find(name);
    return variable != nullptr ? variable->GetFloat() : defaultValue;
}

bool idCVarSystemLocal::Command(const idCmdArgs& args) {
    idCVar* const variable = Find(args.Argv(0));
    if (variable == nullptr) return false;
    if (args.Argc() == 1) {
        idLibPrint::Printf("\"%s\" is:\"%s\"^7 default:\"%s\"\n",
            variable->name, variable->GetString(), variable->resetString);
        if (variable->description != nullptr && *variable->description != '\0') {
            idLibPrint::Printf("^7%s\n", variable->description);
        }
    } else {
        variable->Set(JoinArgs(args, 1).c_str(), false);
    }
    return true;
}

void idCVarSystemLocal::CommandCompletion(idAutoComplete& completion) {
    for (int index = 0; index < cvars.Num(); ++index) {
        completion.Append(idStr(cvars[index]->name));
        if (cvars[index]->valueCompletion != nullptr
                && idStr::Icmp(completion.GetArg(0), cvars[index]->name) == 0) {
            cvars[index]->valueCompletion(completion);
        }
    }
}

void idCVarSystemLocal::SetModifiedFlags(const int flags) {
    modifiedFlags |= flags;
}

void idCVarSystemLocal::ClearModifiedFlags(const int flags) {
    modifiedFlags &= ~flags;
}

void idCVarSystemLocal::ResetFlaggedVariables(const int flags) {
    for (int index = 0; index < cvars.Num(); ++index) {
        if ((cvars[index]->flags & flags) != 0) cvars[index]->Reset();
    }
}

void idCVarSystemLocal::WriteFlaggedVariables(const int flags,
        idFile* const file) const {
    if (file == nullptr) return;
    for (int index = 0; index < cvars.Num(); ++index) {
        const idCVar* const variable = cvars[index];
        if ((variable->flags & flags) != 0
                && idStr::Icmp(variable->GetString(),
                    variable->resetString) != 0) {
            file->Printf("%s \"%s\"\n", variable->name,
                variable->GetString());
        }
    }
}

void idCVarSystemLocal::ReportModifiedCVars() {
    idLibPrint::Printf("Modified CVars:\n");
    for (int index = 0; index < cvars.Num(); ++index) {
        idCVar* const variable = cvars[index];
        if ((variable->flags & CVAR_MODIFIED2) == 0) continue;
        variable->flags &= ~CVAR_MODIFIED2;
        idLibPrint::Printf("Cvar '%s' was modified to '%s'%s\n",
            variable->name, variable->GetString(),
            (variable->flags & CVAR_ARCHIVE) != 0 ? " archived" : "");
    }
}

void idCVarSystemLocal::ClearModifiedCVars() {
    for (int index = 0; index < cvars.Num(); ++index) {
        cvars[index]->flags &= ~CVAR_MODIFIED2;
    }
}

void idCVarSystemLocal::ListCvars(const idCmdArgs& args) {
    const char* const filter = args.Argc() > 1 ? args.Argv(1) : "";
    int count = 0;
    for (int index = 0; index < localCVarSystem.cvars.Num(); ++index) {
        const idCVar* const variable = localCVarSystem.cvars[index];
        if (!ContainsCaseInsensitive(variable->name, filter)) continue;
        idLibPrint::Printf("%-32s \"%s\"\n", variable->name,
            variable->GetString());
        ++count;
    }
    idLibPrint::Printf("%d cvars\n", count);
}
