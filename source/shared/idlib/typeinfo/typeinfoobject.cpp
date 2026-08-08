#include "typeinfoobject.h"

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace {

struct listLayout_t {
    void* list;
    int num;
    int size;
    short granularity;
    unsigned char memTag;
    unsigned char listStatic;
};

void CopyTypeName(const char* source, char* destination, const int capacity) {
    int out = 0;
    const char* cursor = source == nullptr ? "" : source;
    while (std::isspace(static_cast<unsigned char>(*cursor))) ++cursor;
    if (std::strncmp(cursor, "const ", 6) == 0) cursor += 6;
    while (*cursor != '\0' && *cursor != '*' && *cursor != '&'
            && !std::isspace(static_cast<unsigned char>(*cursor))
            && out + 1 < capacity) {
        destination[out++] = *cursor++;
    }
    destination[out] = '\0';
}

bool TemplateArgument(const char* type, char* argument, const int capacity) {
    if (type == nullptr) return false;
    const char* begin = std::strchr(type, '<');
    const char* end = std::strrchr(type, '>');
    if (begin == nullptr || end == nullptr || begin >= end) return false;
    ++begin;
    while (begin < end && std::isspace(static_cast<unsigned char>(*begin))) ++begin;
    int out = 0;
    while (begin < end && *begin != ',' && out + 1 < capacity) {
        argument[out++] = *begin++;
    }
    while (out > 0 && std::isspace(static_cast<unsigned char>(argument[out - 1]))) {
        --out;
    }
    argument[out] = '\0';
    return out > 0;
}

bool IsPointerType(const char* type, const char* ops) {
    return (type != nullptr && std::strchr(type, '*') != nullptr)
        || (ops != nullptr && std::strchr(ops, '*') != nullptr);
}

int FixedArrayCount(const char* ops) {
    if (ops == nullptr) return 0;
    const char* begin = std::strchr(ops, '[');
    if (begin == nullptr) return 0;
    char* end = nullptr;
    const long count = std::strtol(begin + 1, &end, 10);
    return end != begin + 1 && end != nullptr && *end == ']' && count > 0
        ? static_cast<int>(count) : 0;
}

} // namespace

const classTypeInfo_t* idTypeInfoTools::FindClassInfo(const char* name) const {
    if (typeInfo == nullptr || name == nullptr) return nullptr;
    char cleanName[256] = {};
    CopyTypeName(name, cleanName, sizeof(cleanName));
    for (int index = 0; index < typeInfo->numClasses; ++index) {
        const classTypeInfo_t& info = typeInfo->classes[index];
        if (info.name != nullptr && std::strcmp(info.name, cleanName) == 0) {
            return &info;
        }
    }
    return nullptr;
}

const classVariableInfo_t* idTypeInfoTools::FindClassVariableInfo(
        const classTypeInfo_t* classInfo, const char* name) const {
    for (const classTypeInfo_t* current = classInfo; current != nullptr;) {
        if (current->variables != nullptr) {
            for (const classVariableInfo_t* variable = current->variables;
                    variable->name != nullptr; ++variable) {
                if (std::strcmp(variable->name, name) == 0) return variable;
            }
        }
        current = current->superType == nullptr || *current->superType == '\0'
            ? nullptr : FindClassInfo(current->superType);
    }
    return nullptr;
}

bool idTypeInfoTools::ResolvePath(const char* rootType, void* rootObject,
        const char* path, resolvedPath_t& result) const {
    static thread_local char resolvedElementType[256];
    result = {};
    if (rootObject == nullptr || path == nullptr) return false;
    const classTypeInfo_t* currentClass = FindClassInfo(rootType);
    if (currentClass == nullptr) return false;
    unsigned char* currentObject = static_cast<unsigned char*>(rootObject);
    const char* cursor = path;

    while (*cursor != '\0') {
        char memberName[256] = {};
        int memberLength = 0;
        while (*cursor != '\0' && *cursor != '.' && *cursor != '['
                && memberLength + 1 < static_cast<int>(sizeof(memberName))) {
            memberName[memberLength++] = *cursor++;
        }
        memberName[memberLength] = '\0';
        if (memberLength == 0) return false;

        const classVariableInfo_t* variable =
            FindClassVariableInfo(currentClass, memberName);
        if (variable == nullptr) return false;
        unsigned char* valuePointer = currentObject + variable->offset;
        const char* valueType = variable->type;
        const char* valueOps = variable->ops;

        if (*cursor == '[') {
            char* indexEnd = nullptr;
            const long index = std::strtol(cursor + 1, &indexEnd, 10);
            if (indexEnd == cursor + 1 || indexEnd == nullptr || *indexEnd != ']'
                    || index < 0) return false;
            cursor = indexEnd + 1;
            char elementType[256] = {};
            if (TemplateArgument(valueType, elementType, sizeof(elementType))) {
                const listLayout_t* const list =
                    reinterpret_cast<const listLayout_t*>(valuePointer);
                if (list->list == nullptr || index >= list->num) return false;
                const int elementSize = SizeForType(elementType, "");
                if (elementSize <= 0) return false;
                valuePointer = static_cast<unsigned char*>(list->list)
                    + index * elementSize;
                std::strncpy(resolvedElementType, elementType,
                    sizeof(resolvedElementType) - 1);
                resolvedElementType[sizeof(resolvedElementType) - 1] = '\0';
                valueType = resolvedElementType;
                valueOps = "";
                currentClass = FindClassInfo(valueType);
            } else {
                const int arrayCount = FixedArrayCount(valueOps);
                const int elementSize = SizeForType(valueType, "");
                if (arrayCount <= 0 || index >= arrayCount || elementSize <= 0) {
                    return false;
                }
                valuePointer += index * elementSize;
                valueOps = "";
                currentClass = FindClassInfo(valueType);
            }
        } else {
            if (IsPointerType(valueType, valueOps)) {
                valuePointer = *reinterpret_cast<unsigned char**>(valuePointer);
                if (valuePointer == nullptr) return false;
            }
            currentClass = FindClassInfo(valueType);
        }

        if (*cursor == '.') {
            ++cursor;
            if (currentClass == nullptr) return false;
            currentObject = valuePointer;
            continue;
        }
        if (*cursor != '\0') return false;
        result.pointer = valuePointer;
        result.type = valueType;
        result.ops = valueOps;
        return true;
    }
    return false;
}

bool idTypeInfoTools::GetPointerForPath(const char* rootType, const char* path,
        void** objectPointer) const {
    if (objectPointer == nullptr || *objectPointer == nullptr) return false;
    resolvedPath_t result = {};
    if (!ResolvePath(rootType, *objectPointer, path, result)) return false;
    *objectPointer = result.pointer;
    return true;
}

idTypeInfoObject::idTypeInfoObject(void* objectPointer,
        const char* objectTypeName, const idTypeInfoTools* tools)
    : objectPtr(objectPointer), objectType(objectTypeName), ti(tools),
      modified(false) {
}

void idTypeInfoObject::GetVariableName(const char* path, idStr& name,
        int& arrayIndex) {
    const char* const safePath = path == nullptr ? "" : path;
    const char* begin = std::strrchr(safePath, '.');
    begin = begin == nullptr ? safePath : begin + 1;
    name = begin;
    arrayIndex = -1;
    const char* bracket = std::strrchr(begin, '[');
    const std::size_t length = std::strlen(begin);
    if (bracket != nullptr && length > 0 && begin[length - 1] == ']') {
        arrayIndex = std::atoi(bracket + 1);
        char text[256] = {};
        const std::size_t baseLength = static_cast<std::size_t>(bracket - begin);
        const std::size_t amount = baseLength < sizeof(text) - 1
            ? baseLength : sizeof(text) - 1;
        std::memcpy(text, begin, amount);
        name = text;
    }
}

bool idTypeInfoObject::Resolve(const char* path,
        idTypeInfoTools::resolvedPath_t& result) const {
    return ti != nullptr && ti->ResolvePath(objectType.c_str(), objectPtr,
        path, result);
}

bool idTypeInfoObject::GetBool(const idTypeInfoVariable_bool& variable,
        bool& value) const {
    idTypeInfoTools::resolvedPath_t resolved = {};
    if (!Resolve(variable.path, resolved) || resolved.pointer == nullptr) return false;
    value = *static_cast<const bool*>(resolved.pointer);
    return true;
}

bool idTypeInfoObject::GetInt(const idTypeInfoVariable_int& variable,
        int& value) const {
    idTypeInfoTools::resolvedPath_t resolved = {};
    if (!Resolve(variable.path, resolved) || resolved.pointer == nullptr) return false;
    value = *static_cast<const int*>(resolved.pointer);
    return true;
}

bool idTypeInfoObject::GetFloat(const idTypeInfoVariable_float& variable,
        float& value) const {
    idTypeInfoTools::resolvedPath_t resolved = {};
    if (!Resolve(variable.path, resolved) || resolved.pointer == nullptr) return false;
    value = *static_cast<const float*>(resolved.pointer);
    return true;
}

bool idTypeInfoObject::GetStrPtrType(
        const idTypeInfoVariable_StrPtr& variable, idStr& value,
        const bool resolvePointers) const {
    idTypeInfoTools::resolvedPath_t resolved = {};
    if (!Resolve(variable.path, resolved)) return false;
    if (resolved.pointer == nullptr) {
        value.Clear();
        return true;
    }
    if (!resolvePointers) {
        char address[32] = {};
        std::snprintf(address, sizeof(address), "%p", resolved.pointer);
        value = address;
        return true;
    }
    value = static_cast<const char*>(resolved.pointer);
    return true;
}

bool idTypeInfoObject::GetTypeInfoObjectForListElement(
        const idTypeInfoVariable_idList& variable, const int index,
        idTypeInfoObject& object) const {
    char path[1024] = {};
    std::snprintf(path, sizeof(path), "%s[%d]", variable.path, index);
    void* pointer = objectPtr;
    if (ti == nullptr || !ti->GetPointerForPath(objectType.c_str(), path,
            &pointer)) return false;
    object.objectPtr = pointer;
    object.objectType = variable.argType;
    object.ti = ti;
    object.modified = false;
    return true;
}

bool idTypeInfoObject::GetStrType(const char*, const char*, const char* path,
        idStr& value, const bool resolvePointers) const {
    idTypeInfoTools::resolvedPath_t resolved = {};
    if (!Resolve(path, resolved)) return false;
    if (resolved.type != nullptr && std::strcmp(resolved.type, "idStr") == 0) {
        value = *static_cast<const idStr*>(resolved.pointer);
        return true;
    }
    if (resolved.type != nullptr && IsPointerType(resolved.type, resolved.ops)) {
        if (!resolvePointers) {
            char address[32] = {};
            std::snprintf(address, sizeof(address), "%p", resolved.pointer);
            value = address;
        } else {
            value = resolved.pointer == nullptr ? ""
                : static_cast<const char*>(resolved.pointer);
        }
        return true;
    }
    value = resolved.pointer == nullptr ? ""
        : static_cast<const char*>(resolved.pointer);
    return true;
}

bool idTypeInfoObject::GetValueText(const char* path, idStr& text) const {
    idTypeInfoTools::resolvedPath_t resolved = {};
    if (!Resolve(path, resolved) || resolved.pointer == nullptr) return false;
    char value[256] = {};
    if (resolved.type != nullptr && std::strcmp(resolved.type, "bool") == 0) {
        std::strcpy(value, *static_cast<const bool*>(resolved.pointer)
            ? "true" : "false");
    } else if (resolved.type != nullptr
            && (std::strcmp(resolved.type, "int") == 0
                || std::strcmp(resolved.type, "unsigned int") == 0)) {
        std::snprintf(value, sizeof(value), "%d",
            *static_cast<const int*>(resolved.pointer));
    } else if (resolved.type != nullptr
            && std::strcmp(resolved.type, "float") == 0) {
        std::snprintf(value, sizeof(value), "%.9g",
            *static_cast<const float*>(resolved.pointer));
    } else if (resolved.type != nullptr
            && std::strcmp(resolved.type, "idStr") == 0) {
        text = static_cast<const idStr*>(resolved.pointer)->c_str();
        return true;
    } else {
        std::snprintf(value, sizeof(value), "%p", resolved.pointer);
    }
    text = value;
    return true;
}

bool idTypeInfoObject::GetStr(const idTypeInfoVariable_idStr& variable,
        idStr& value) const {
    return GetStrType(variable.type, "", variable.path, value, true);
}

bool idTypeInfoObject::GetListNum(const idTypeInfoVariable_idList& variable,
        int& num) const {
    idTypeInfoTools::resolvedPath_t resolved = {};
    if (!Resolve(variable.path, resolved) || resolved.pointer == nullptr) return false;
    num = reinterpret_cast<const listLayout_t*>(resolved.pointer)->num;
    return true;
}
