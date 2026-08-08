#include "typeinfoobject.h"
#include "typeinfofile.h"

#ifdef strcmp
#undef strcmp
#endif
#ifdef snprintf
#undef snprintf
#endif
#ifdef vsnprintf
#undef vsnprintf
#endif

#include <algorithm>
#include <cctype>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

namespace {

std::mutex warningMutex;
std::unordered_map<const idTypeInfoTools*, std::vector<std::string>> warningLists;

std::string CleanType(const char* source) {
    const char* cursor = source == nullptr ? "" : source;
    while (std::isspace(static_cast<unsigned char>(*cursor))) ++cursor;
    if (std::strncmp(cursor, "const ", 6) == 0) cursor += 6;
    std::string result;
    while (*cursor != 0 && *cursor != '*' && *cursor != '&') {
        result.push_back(*cursor++);
    }
    while (!result.empty()
            && std::isspace(static_cast<unsigned char>(result.back()))) {
        result.pop_back();
    }
    return result;
}

bool HasPointer(const char* type, const char* ops) {
    return (type != nullptr && std::strchr(type, '*') != nullptr)
        || (ops != nullptr && std::strchr(ops, '*') != nullptr);
}

int ArrayCount(const char* ops, std::string* stripped = nullptr) {
    std::string value = ops == nullptr ? "" : ops;
    const std::size_t close = value.rfind(']');
    const std::size_t open = value.rfind('[');
    if (open == std::string::npos || close != value.size() - 1 || open >= close) {
        if (stripped != nullptr) *stripped = value;
        return 1;
    }
    char* end = nullptr;
    const long count = std::strtol(value.c_str() + open + 1, &end, 10);
    if (end == value.c_str() + open + 1 || *end != ']') {
        if (stripped != nullptr) *stripped = value;
        return 1;
    }
    if (stripped != nullptr) *stripped = value.substr(0, open);
    return count > 0 ? static_cast<int>(count) : 0;
}

bool TemplateParts(const char* type, std::string& container,
        std::string& argument) {
    const std::string text = type == nullptr ? "" : type;
    const std::size_t open = text.find('<');
    const std::size_t close = text.rfind('>');
    if (open == std::string::npos || close == std::string::npos || open >= close) {
        return false;
    }
    container = text.substr(0, open);
    argument = text.substr(open + 1, close - open - 1);
    const std::size_t comma = argument.find(',');
    if (comma != std::string::npos) argument.resize(comma);
    while (!argument.empty()
        && std::isspace(static_cast<unsigned char>(argument.back()))) {
        argument.pop_back();
    }
    while (!argument.empty()
        && std::isspace(static_cast<unsigned char>(argument.front()))) {
        argument.erase(argument.begin());
    }
    return !container.empty() && !argument.empty();
}

void CopyText(char* destination, const int capacity, const char* source) {
    if (destination == nullptr || capacity <= 0) return;
    std::strncpy(destination, source == nullptr ? "" : source,
        static_cast<std::size_t>(capacity - 1));
    destination[capacity - 1] = 0;
}

const classVariableInfo_t* VariableAtOffset(const idTypeInfoTools& tools,
        const classTypeInfo_t* info, const int offset) {
    for (const classTypeInfo_t* current = info; current != nullptr;) {
        if (current->variables != nullptr) {
            for (const classVariableInfo_t* variable = current->variables;
                    variable->name != nullptr; ++variable) {
                if (offset >= variable->offset
                    && offset < variable->offset + variable->size) return variable;
            }
        }
        current = current->superType != nullptr && *current->superType != 0
            ? tools.FindClassInfo(current->superType) : nullptr;
    }
    return nullptr;
}

} // namespace

idTypeInfoTools::~idTypeInfoTools() { Shutdown(); }

void idTypeInfoTools::Init(const typeInfo_t* info) {
    Shutdown();
    typeInfo = info;
}

void idTypeInfoTools::Shutdown() {
    ClearWarnings();
    typeInfo = nullptr;
    std::memset(enumHash, 0, sizeof(enumHash));
    std::memset(classHash, 0, sizeof(classHash));
    enumObject = {};
    enumPointer = {};
    classObject = {};
    classPointer = {};
    editDepth = designDepth = defDepth = 0;
    warnings = {};
}

void idTypeInfoTools::ClearWarnings() const {
    std::lock_guard<std::mutex> lock(warningMutex);
    warningLists.erase(this);
}

void idTypeInfoTools::AddWarning(const char* format, ...) const {
    char buffer[2048] = {};
    va_list args;
    va_start(args, format);
    std::vsnprintf(buffer, sizeof(buffer), format == nullptr ? "" : format, args);
    va_end(args);
    std::lock_guard<std::mutex> lock(warningMutex);
    warningLists[this].push_back(buffer);
}

int idTypeInfoTools::GetWarningCount() const {
    std::lock_guard<std::mutex> lock(warningMutex);
    const auto found = warningLists.find(this);
    return found == warningLists.end() ? 0
        : static_cast<int>(found->second.size());
}

const char* idTypeInfoTools::GetWarning(const int index) const {
    std::lock_guard<std::mutex> lock(warningMutex);
    const auto found = warningLists.find(this);
    if (found == warningLists.end() || index < 0
        || index >= static_cast<int>(found->second.size())) return "";
    return found->second[static_cast<std::size_t>(index)].c_str();
}

bool idTypeInfoTools::IsUninitializedType(const char* type, const char* ops) {
    if (HasPointer(type, ops)) return true;
    static const char* const types[] = {
        "idLinkList", "idList", "idHashIndex", "idStr", "idStrList",
        "idDynamicBlockAlloc", "idBlockAlloc", "idVecX", "idMatX", nullptr
    };
    const std::string clean = CleanType(type);
    for (int index = 0; types[index] != nullptr; ++index) {
        if (clean == types[index]
            || clean.compare(0, std::strlen(types[index]), types[index]) == 0) {
            return true;
        }
    }
    return false;
}

int idTypeInfoTools::FindEnumIndex(const char* typeName) const {
    if (typeInfo == nullptr || typeName == nullptr) return -1;
    for (int index = 0; index < typeInfo->numEnums; ++index) {
        if (typeInfo->enums[index].name != nullptr
            && std::strcmp(typeInfo->enums[index].name, typeName) == 0) return index;
    }
    return -1;
}

const enumTypeInfo_t* idTypeInfoTools::FindEnumInfo(const char* typeName) const {
    const int index = FindEnumIndex(typeName);
    return index < 0 ? nullptr : &typeInfo->enums[index];
}

const enumValueInfo_t* idTypeInfoTools::FindEnumValueInfo(
        const enumTypeInfo_t* enumInfo, const char* name,
        const bool defaultIfNotFound) const {
    if (enumInfo == nullptr || enumInfo->values == nullptr) return nullptr;
    const enumValueInfo_t* first = enumInfo->values;
    for (const enumValueInfo_t* value = first; value->name != nullptr; ++value) {
        if (name != nullptr && std::strcmp(value->name, name) == 0) return value;
    }
    return defaultIfNotFound ? first : nullptr;
}

const enumValueInfo_t* idTypeInfoTools::FindEnumValueInfo(
        const enumTypeInfo_t* enumInfo, const int expected) const {
    if (enumInfo == nullptr || enumInfo->values == nullptr) return nullptr;
    for (const enumValueInfo_t* value = enumInfo->values;
            value->name != nullptr; ++value) {
        if (value->value == expected) return value;
    }
    return nullptr;
}

const enumValueInfo_t* idTypeInfoTools::FindEnumValueInfo(
        const char* enumName, const int value,
        const bool defaultIfNotFound) const {
    const enumTypeInfo_t* const info = FindEnumInfo(enumName);
    const enumValueInfo_t* const found = FindEnumValueInfo(info, value);
    return found != nullptr || !defaultIfNotFound ? found
        : info != nullptr ? info->values : nullptr;
}

const char* idTypeInfoTools::FindEnumValueName(const char* enumTypeName,
        const int value) const {
    const enumValueInfo_t* const info = FindEnumValueInfo(enumTypeName, value);
    return info == nullptr || info->name == nullptr ? "unknown" : info->name;
}

int idTypeInfoTools::FindEnumValue(const char* enumTypeName, const char* name,
        const int defaultValue) const {
    const enumValueInfo_t* const value = FindEnumValueInfo(
        FindEnumInfo(enumTypeName), name, false);
    return value == nullptr ? defaultValue : value->value;
}

const char* idTypeInfoTools::GetEnumName(const char* enumTypeName,
        const int enumValue, const char* defaultValue) const {
    const enumValueInfo_t* const value = FindEnumValueInfo(
        FindEnumInfo(enumTypeName), enumValue);
    return value == nullptr || value->name == nullptr ? defaultValue : value->name;
}

bool idTypeInfoTools::GetEnumBitFlags(const int flags,
        const char* enumTypeName, idStr& values, const char* separator) const {
    const enumTypeInfo_t* const info = FindEnumInfo(enumTypeName);
    if (info == nullptr || info->values == nullptr) return false;
    values.Clear();
    for (const enumValueInfo_t* value = info->values; value->name != nullptr;
            ++value) {
        if (value->value != 0 && (flags & value->value) == value->value) {
            if (values.Length() != 0) values.Append(separator == nullptr ? " | " : separator);
            values.Append(value->name);
        }
    }
    return values.Length() != 0 || flags == 0;
}

int idTypeInfoTools::FindClassIndex(const char* typeName) const {
    const classTypeInfo_t* const info = FindClassInfo(typeName);
    return info == nullptr || typeInfo == nullptr ? -1
        : static_cast<int>(info - typeInfo->classes);
}

int idTypeInfoTools::FindTypeDefIndex(const char* typeName) const {
    if (typeInfo == nullptr || typeName == nullptr) return -1;
    for (int index = 0; index < typeInfo->numTypedefs; ++index) {
        if (typeInfo->typedefs[index].name != nullptr
            && std::strcmp(typeInfo->typedefs[index].name, typeName) == 0) return index;
    }
    return -1;
}

int idTypeInfoTools::SizeForType(const char* type, const char* ops) const {
    std::string strippedOps;
    const int count = ArrayCount(ops, &strippedOps);
    if (HasPointer(type, strippedOps.c_str())) return 4 * count;
    const std::string clean = CleanType(type);
    if (clean == "bool" || clean == "char" || clean == "unsigned char") return count;
    if (clean == "short" || clean == "unsigned short" || clean == "wchar_t") return 2 * count;
    if (clean == "int" || clean == "unsigned int" || clean == "long"
        || clean == "unsigned long" || clean == "float" || clean == "size_t") return 4 * count;
    if (clean == "double") return 8 * count;
    if (clean == "idStr") return static_cast<int>(sizeof(idStr)) * count;
    const int typeDef = FindTypeDefIndex(clean.c_str());
    if (typeDef >= 0) return typeInfo->typedefs[typeDef].size * count;
    if (FindEnumInfo(clean.c_str()) != nullptr) return 4 * count;
    const classTypeInfo_t* const classInfo = FindClassInfo(clean.c_str());
    return classInfo == nullptr ? -1 : classInfo->size * count;
}

bool idTypeInfoTools::IsSubclassOf(const char* className,
        const char* superClassName) const {
    for (const classTypeInfo_t* info = FindClassInfo(className); info != nullptr;) {
        if (std::strcmp(info->name, superClassName == nullptr ? "" : superClassName) == 0) return true;
        info = info->superType != nullptr && *info->superType != 0
            ? FindClassInfo(info->superType) : nullptr;
    }
    return false;
}

const char* idTypeInfoTools::GetVariableNameFromOffset(const char* className,
        const int offset) const {
    const classVariableInfo_t* const variable = VariableAtOffset(
        *this, FindClassInfo(className), offset);
    return variable == nullptr ? "" : variable->name;
}

const char* idTypeInfoTools::GetVariableTypeFromOffset(const char* className,
        const int offset) const {
    const classVariableInfo_t* const variable = VariableAtOffset(
        *this, FindClassInfo(className), offset);
    return variable == nullptr ? "" : variable->type;
}

const char* idTypeInfoTools::GetVariableOpsFromOffset(const char* className,
        const int offset) const {
    const classVariableInfo_t* const variable = VariableAtOffset(
        *this, FindClassInfo(className), offset);
    return variable == nullptr ? "" : variable->ops;
}

bool idTypeInfoTools::GetTypeForPath(const char* rootType, const char* path,
        char* outputType, const int typeSize, char* outputOps,
        const int opsSize) const {
    const classTypeInfo_t* current = FindClassInfo(rootType);
    const char* cursor = path == nullptr ? "" : path;
    const classVariableInfo_t* variable = nullptr;
    while (*cursor != 0 && current != nullptr) {
        char name[256] = {};
        int length = 0;
        while (*cursor != 0 && *cursor != '.' && *cursor != '['
            && length < static_cast<int>(sizeof(name) - 1)) name[length++] = *cursor++;
        variable = FindClassVariableInfo(current, name);
        if (variable == nullptr) return false;
        if (*cursor == '[') {
            while (*cursor != 0 && *cursor != ']') ++cursor;
            if (*cursor == ']') ++cursor;
            std::string container, argument;
            current = TemplateParts(variable->type, container, argument)
                ? FindClassInfo(argument.c_str()) : FindClassInfo(variable->type);
        } else {
            current = FindClassInfo(variable->type);
        }
        if (*cursor == '.') ++cursor;
        else if (*cursor != 0) return false;
    }
    if (variable == nullptr) return false;
    CopyText(outputType, typeSize, variable->type);
    CopyText(outputOps, opsSize, variable->ops);
    return true;
}

bool idTypeInfoTools::WriteValue(idTypeInfoFile& file, const char* type,
        const char* ops, const char* name, void* object,
        const bool writeName) const {
    const std::string clean = CleanType(type);
    std::string elementOps;
    const int arrayCount = ArrayCount(ops, &elementOps);
    if (arrayCount != 1 || (ops != nullptr && std::strchr(ops, '[') != nullptr)) {
        if (writeName) file.WriteType(type, ops, name);
        file.WriteOpeningBrace();
        const int elementSize = SizeForType(type, elementOps.c_str());
        if (elementSize <= 0) { file.WriteClosingBrace(); return false; }
        for (int index = 0; index < arrayCount; ++index) {
            file.WriteArrayElementType(type, elementOps.c_str(),
                name == nullptr ? "item" : name, index);
            WriteValue(file, type, elementOps.c_str(), name,
                static_cast<unsigned char*>(object) + index * elementSize,
                false);
        }
        file.WriteClosingBrace();
        return true;
    }
    if (writeName) file.WriteType(type, ops, name);
    if (HasPointer(type, ops)) {
        void* const target = object == nullptr ? nullptr : *static_cast<void**>(object);
        if (target == nullptr) { file.WriteNullPointer(); return true; }
        return WriteValue(file, type, "", name, target, false);
    }
    if (object == nullptr) { file.WriteUnknown(); return false; }
    if (clean == "bool") file.WriteBool(*static_cast<bool*>(object));
    else if (clean == "char") file.WriteChar(*static_cast<char*>(object));
    else if (clean == "unsigned char") file.WriteUnsignedChar(*static_cast<unsigned char*>(object));
    else if (clean == "wchar_t") file.WriteWChar(*static_cast<wchar_t*>(object));
    else if (clean == "short") file.WriteShort(*static_cast<short*>(object));
    else if (clean == "unsigned short") file.WriteUnsignedShort(*static_cast<unsigned short*>(object));
    else if (clean == "unsigned int" || clean == "unsigned long" || clean == "size_t") file.WriteUnsignedLong(*static_cast<unsigned long*>(object));
    else if (clean == "int" || clean == "long") file.WriteInt(*static_cast<int*>(object));
    else if (clean == "float") file.WriteFloat(*static_cast<float*>(object));
    else if (clean == "double") file.WriteDouble(*static_cast<double*>(object));
    else if (clean == "idStr") file.WriteStr(static_cast<idStr*>(object)->c_str());
    else if (FindEnumInfo(clean.c_str()) != nullptr) file.WriteInt(*static_cast<int*>(object));
    else {
        const classTypeInfo_t* const classInfo = FindClassInfo(clean.c_str());
        if (classInfo == nullptr) {
            file.WriteUnknown();
            AddWarning("Unknown type '%s' while writing '%s'", type, name);
            return false;
        }
        file.WriteOpeningBrace();
        std::vector<const classTypeInfo_t*> hierarchy;
        for (const classTypeInfo_t* current = classInfo; current != nullptr;
                current = current->superType != nullptr && *current->superType != 0
                    ? FindClassInfo(current->superType) : nullptr) hierarchy.push_back(current);
        for (auto level = hierarchy.rbegin(); level != hierarchy.rend(); ++level) {
            if ((*level)->variables == nullptr) continue;
            for (const classVariableInfo_t* variable = (*level)->variables;
                    variable->name != nullptr; ++variable) {
                WriteValue(file, variable->type, variable->ops, variable->name,
                    static_cast<unsigned char*>(object) + variable->offset, true);
                file.WriteComment(variable->comment);
            }
        }
        file.WriteClosingBrace();
    }
    return true;
}

bool idTypeInfoTools::ReadValue(idTypeInfoFile& file, const char* type,
        const char* ops, const char* name, void* object,
        const bool expectName) const {
    if (expectName && !file.ExpectType(type, ops, name)) return false;
    const std::string clean = CleanType(type);
    std::string elementOps;
    const int arrayCount = ArrayCount(ops, &elementOps);
    if (arrayCount != 1 || (ops != nullptr && std::strchr(ops, '[') != nullptr)) {
        file.ReadOpeningBrace();
        const int elementSize = SizeForType(type, elementOps.c_str());
        if (elementSize <= 0) { file.ReadUnknown(); return false; }
        for (int index = 0; index < arrayCount; ++index) {
            int readIndex = -1;
            if (!file.ExpectArrayElementType(type, elementOps.c_str(),
                    name == nullptr ? "item" : name, readIndex)
                    || readIndex != index) return false;
            ReadValue(file, type, elementOps.c_str(), name,
                static_cast<unsigned char*>(object) + index * elementSize,
                false);
        }
        file.ReadClosingBrace();
        return true;
    }
    if (HasPointer(type, ops)) {
        if (file.CheckNullPointer()) {
            if (object != nullptr) *static_cast<void**>(object) = nullptr;
            return true;
        }
        void* target = object == nullptr ? nullptr : *static_cast<void**>(object);
        if (target == nullptr) { file.ReadUnknown(); return false; }
        return ReadValue(file, type, "", name, target, false);
    }
    if (object == nullptr) { file.ReadUnknown(); return false; }
    if (clean == "bool") file.ReadBool(*static_cast<bool*>(object));
    else if (clean == "char") file.ReadChar(*static_cast<char*>(object));
    else if (clean == "unsigned char") file.ReadUnsignedChar(*static_cast<unsigned char*>(object));
    else if (clean == "wchar_t") file.ReadWChar(*static_cast<wchar_t*>(object));
    else if (clean == "short") file.ReadShort(*static_cast<short*>(object));
    else if (clean == "unsigned short") file.ReadUnsignedShort(*static_cast<unsigned short*>(object));
    else if (clean == "unsigned int" || clean == "unsigned long" || clean == "size_t") file.ReadUnsignedLong(*static_cast<unsigned long*>(object));
    else if (clean == "int" || clean == "long") file.ReadInt(*static_cast<int*>(object));
    else if (clean == "float") file.ReadFloat(*static_cast<float*>(object));
    else if (clean == "double") file.ReadDouble(*static_cast<double*>(object));
    else if (clean == "idStr") file.ReadStr(*static_cast<idStr*>(object));
    else if (FindEnumInfo(clean.c_str()) != nullptr) file.ReadInt(*static_cast<int*>(object));
    else {
        const classTypeInfo_t* const classInfo = FindClassInfo(clean.c_str());
        if (classInfo == nullptr) { file.ReadUnknown(); return false; }
        file.ReadOpeningBrace();
        std::vector<const classTypeInfo_t*> hierarchy;
        for (const classTypeInfo_t* current = classInfo; current != nullptr;
                current = current->superType != nullptr && *current->superType != 0
                    ? FindClassInfo(current->superType) : nullptr) hierarchy.push_back(current);
        for (auto level = hierarchy.rbegin(); level != hierarchy.rend(); ++level) {
            if ((*level)->variables == nullptr) continue;
            for (const classVariableInfo_t* variable = (*level)->variables;
                    variable->name != nullptr; ++variable) {
                ReadValue(file, variable->type, variable->ops, variable->name,
                    static_cast<unsigned char*>(object) + variable->offset, true);
            }
        }
        file.ReadClosingBrace();
    }
    return true;
}

void idTypeInfoTools::WriteObject(idTypeInfoFile& file, const char* type,
        const char* ops, const char* name, void* object) const {
    WriteValue(file, type, ops, name, object, true);
}

void idTypeInfoTools::ReadObject(idTypeInfoFile& file, const char* type,
        const char* ops, const char* name, void* object) const {
    ReadValue(file, type, ops, name, object, true);
}

bool idTypeInfoTools::WriteObjectVariable(idTypeInfoFile& file,
        const char* rootType, void* object, const char* path) const {
    resolvedPath_t resolved{};
    if (!ResolvePath(rootType, object, path, resolved)) return false;
    const char* name = std::strrchr(path == nullptr ? "" : path, '.');
    name = name == nullptr ? path : name + 1;
    return WriteValue(file, resolved.type, resolved.ops, name,
        resolved.pointer, true);
}

void idTypeInfoTools::CollectPaths(const classTypeInfo_t* classInfo,
        const char* prefix, const char* type, const char* ops,
        const bool includeInherited, stringList_t& paths) const {
    if (classInfo == nullptr) return;
    if (includeInherited && classInfo->superType != nullptr
        && *classInfo->superType != 0) {
        CollectPaths(FindClassInfo(classInfo->superType), prefix, type, ops,
            true, paths);
    }
    if (classInfo->variables == nullptr) return;
    for (const classVariableInfo_t* variable = classInfo->variables;
            variable->name != nullptr; ++variable) {
        std::string path = prefix == nullptr ? "" : prefix;
        if (!path.empty()) path.push_back('.');
        path += variable->name;
        if (std::strcmp(variable->type, type == nullptr ? "" : type) == 0
            && std::strcmp(variable->ops == nullptr ? "" : variable->ops,
                ops == nullptr ? "" : ops) == 0) paths.Append(idStr(path.c_str()));
        const classTypeInfo_t* nested = FindClassInfo(variable->type);
        if (nested != nullptr && !HasPointer(variable->type, variable->ops)) {
            CollectPaths(nested, path.c_str(), type, ops, true, paths);
        }
    }
}

void idTypeInfoTools::FindClassVariablePathsForType(
        const classTypeInfo_t* classInfo, const char* type, const char* ops,
        stringList_t& paths) const {
    paths.Clear();
    CollectPaths(classInfo, "", type, ops, false, paths);
}

void idTypeInfoTools::FindClassVariablePathsForTypeIncludingInherited(
        const classTypeInfo_t* classInfo, const char* type, const char* ops,
        stringList_t& paths) const {
    paths.Clear();
    CollectPaths(classInfo, "", type, ops, true, paths);
}

void idTypeInfoTools::FindClassVariablePathsForTemplateType(
        const classTypeInfo_t* classInfo, const char* templateType,
        const char* argumentType, stringList_t& paths,
        stringList_t& argumentOps) const {
    paths.Clear();
    argumentOps.Clear();
    if (classInfo == nullptr || classInfo->variables == nullptr) return;
    for (const classVariableInfo_t* variable = classInfo->variables;
            variable->name != nullptr; ++variable) {
        std::string container, argument;
        if (TemplateParts(variable->type, container, argument)
            && container == (templateType == nullptr ? "" : templateType)
            && argument == (argumentType == nullptr ? "" : argumentType)) {
            paths.Append(idStr(variable->name));
            argumentOps.Append(idStr(variable->ops == nullptr ? "" : variable->ops));
        }
    }
}
