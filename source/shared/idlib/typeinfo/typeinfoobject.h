#pragma once

#include "idlib/text/str.h"

#include <cstddef>
#include <cstdint>
#include <new>

class idTypeInfoFile;

struct constantInfo_t {
    const char* type;
    const char* name;
    const char* value;
};

struct enumValueInfo_t {
    const char* name;
    int value;
};

struct enumTypeInfo_t {
    const char* name;
    int flags;
    const enumValueInfo_t* values;
};

struct classVariableInfo_t {
    const char* type;
    const char* ops;
    const char* name;
    int offset;
    int size;
    int flags;
    const char* comment;
    int (*get)(void*);
    void (*set)(void*, int);
    void* (*reallocate)(void*, int, int, int, bool);
};

struct classMetaDataInfo_t { const char* metaData; };

struct classTypeInfo_t {
    const char* name;
    const char* superType;
    int size;
    const void* typeId;
    const classVariableInfo_t* templateParms;
    const classVariableInfo_t* variables;
    const classMetaDataInfo_t* metaData;
};

struct typedefInfo_t {
    const char* name;
    const char* type;
    const char* ops;
    int size;
};

struct functionPointerInfo_t { const char* name; void* ptr; };

struct typeInfo_t {
    constantInfo_t* constants;
    int numConstants;
    enumTypeInfo_t* enums;
    int numEnums;
    classTypeInfo_t* classes;
    int numClasses;
    typedefInfo_t* typedefs;
    int numTypedefs;
    functionPointerInfo_t* functionPointers;
    int numFunctionPointers;
    unsigned int superScriptVersion;
};

class idTypeInfoTools {
public:
    explicit idTypeInfoTools(const typeInfo_t* info = nullptr)
        : typeInfo(info), enumHash{}, classHash{}, enumObject{}, enumPointer{},
          classObject{}, classPointer{}, editDepth(0), designDepth(0),
          defDepth(0), warnings{} {}
    ~idTypeInfoTools();
    idTypeInfoTools(const idTypeInfoTools&) = delete;
    idTypeInfoTools& operator=(const idTypeInfoTools&) = delete;

    struct resolvedPath_t {
        void* pointer;
        const char* type;
        const char* ops;
    };

    bool ResolvePath(const char* rootType, void* rootObject, const char* path,
        resolvedPath_t& result) const;
    bool GetPointerForPath(const char* rootType, const char* path,
        void** objectPointer) const;
    const classTypeInfo_t* FindClassInfo(const char* name) const;
    const classVariableInfo_t* FindClassVariableInfo(
        const classTypeInfo_t* classInfo, const char* name) const;

    void Init(const typeInfo_t* info);
    void Shutdown();
    void ClearWarnings() const;
    void AddWarning(const char* format, ...) const;
    int GetWarningCount() const;
    const char* GetWarning(int index) const;

    static bool IsUninitializedType(const char* type, const char* ops);
    int FindEnumIndex(const char* typeName) const;
    const enumTypeInfo_t* FindEnumInfo(const char* typeName) const;
    const enumValueInfo_t* FindEnumValueInfo(const enumTypeInfo_t* enumInfo,
        const char* name, bool defaultIfNotFound = false) const;
    const enumValueInfo_t* FindEnumValueInfo(const enumTypeInfo_t* enumInfo,
        int value) const;
    const enumValueInfo_t* FindEnumValueInfo(const char* enumName, int value,
        bool defaultIfNotFound = false) const;
    const char* FindEnumValueName(const char* enumTypeName, int value) const;
    int FindEnumValue(const char* enumTypeName, const char* name,
        int defaultValue = 0) const;
    const char* GetEnumName(const char* enumTypeName, int enumValue,
        const char* defaultValue = "unknown") const;
    bool GetEnumBitFlags(int flags, const char* enumTypeName,
        idStr& values, const char* separator = " | ") const;

    int FindClassIndex(const char* typeName) const;
    int FindTypeDefIndex(const char* typeName) const;
    int SizeForType(const char* type, const char* ops = "") const;
    bool IsSubclassOf(const char* className, const char* superClassName) const;
    const char* GetVariableNameFromOffset(const char* className,
        int offset) const;
    const char* GetVariableTypeFromOffset(const char* className,
        int offset) const;
    const char* GetVariableOpsFromOffset(const char* className,
        int offset) const;
    bool GetTypeForPath(const char* rootType, const char* path,
        char* type, int typeSize, char* ops, int opsSize) const;

    void WriteObject(idTypeInfoFile& file, const char* type,
        const char* ops, const char* name, void* object) const;
    void ReadObject(idTypeInfoFile& file, const char* type,
        const char* ops, const char* name, void* object) const;
    bool WriteObjectVariable(idTypeInfoFile& file, const char* rootType,
        void* object, const char* path) const;

    class stringList_t {
    public:
        stringList_t() : list(nullptr), num(0), size(0), granularity(16),
            memTag(5), listStatic(0) {}
        ~stringList_t() { delete[] list; }
        int Append(const idStr& value) {
            if (num == size) {
                const int newSize = size == 0 ? granularity : size + granularity;
                idStr* replacement = new (std::nothrow) idStr[newSize];
                if (replacement == nullptr) return -1;
                for (int i = 0; i < num; ++i) replacement[i] = list[i];
                delete[] list;
                list = replacement;
                size = newSize;
            }
            list[num] = value;
            return num++;
        }
        void Clear() { num = 0; }
        int Num() const { return num; }
        idStr& operator[](int index) { return list[index]; }
        const idStr& operator[](int index) const { return list[index]; }
    private:
        idStr* list;
        int num;
        int size;
        short granularity;
        unsigned char memTag;
        unsigned char listStatic;
    };

    void FindClassVariablePathsForType(const classTypeInfo_t* classInfo,
        const char* type, const char* ops, stringList_t& paths) const;
    void FindClassVariablePathsForTypeIncludingInherited(
        const classTypeInfo_t* classInfo, const char* type, const char* ops,
        stringList_t& paths) const;
    void FindClassVariablePathsForTemplateType(
        const classTypeInfo_t* classInfo, const char* templateType,
        const char* argumentType, stringList_t& paths,
        stringList_t& argumentOps) const;

    const typeInfo_t* typeInfo;

private:
    struct opaqueList_t {
        void* list;
        int num;
        int size;
        short granularity;
        unsigned char memTag;
        unsigned char listStatic;
    };

    bool WriteValue(idTypeInfoFile& file, const char* type, const char* ops,
        const char* name, void* object, bool writeName) const;
    bool ReadValue(idTypeInfoFile& file, const char* type, const char* ops,
        const char* name, void* object, bool expectName) const;
    void CollectPaths(const classTypeInfo_t* classInfo, const char* prefix,
        const char* type, const char* ops, bool includeInherited,
        stringList_t& paths) const;

    std::uint32_t enumHash[8];
    std::uint32_t classHash[8];
    opaqueList_t enumObject;
    opaqueList_t enumPointer;
    opaqueList_t classObject;
    opaqueList_t classPointer;
    int editDepth;
    int designDepth;
    int defDepth;
    opaqueList_t warnings;
};

struct idPathTypeInfo {
    idPathTypeInfo()
        : type(), ops(), name(), arrayIndex(-1), flags(0), objectPtr(nullptr),
          size(0), get(nullptr), set(nullptr), editDepth(0), designDepth(0),
          defDepth(0), metaData{} {}
    idStr type;
    idStr ops;
    idStr name;
    int arrayIndex;
    int flags;
    unsigned char* objectPtr;
    int size;
    int (*get)(void*);
    void (*set)(void*, int);
    int editDepth;
    int designDepth;
    int defDepth;
    std::uint32_t metaData[4];
};

struct idTypeInfoVariable {
    idTypeInfoVariable(const char* typeName = "", const char* typeOps = "",
            const char* variablePath = "")
        : type(typeName), ops(typeOps), path(variablePath) {}
    const char* type;
    const char* ops;
    const char* path;
};

struct idTypeInfoVariable_bool : idTypeInfoVariable {
    using idTypeInfoVariable::idTypeInfoVariable;
};
struct idTypeInfoVariable_int : idTypeInfoVariable {
    using idTypeInfoVariable::idTypeInfoVariable;
};
struct idTypeInfoVariable_float : idTypeInfoVariable {
    using idTypeInfoVariable::idTypeInfoVariable;
};
struct idTypeInfoVariable_StrPtr : idTypeInfoVariable {
    using idTypeInfoVariable::idTypeInfoVariable;
};

struct idTypeInfoVariableTemplate : idTypeInfoVariable {
    idTypeInfoVariableTemplate(const char* typeName = "",
            const char* typeOps = "", const char* variablePath = "",
            const char* argumentType = "", const char* argumentOps = "")
        : idTypeInfoVariable(typeName, typeOps, variablePath),
          argType(argumentType), argOps(argumentOps) {}
    const char* argType;
    const char* argOps;
};

struct idTypeInfoVariable_idList : idTypeInfoVariableTemplate {
    using idTypeInfoVariableTemplate::idTypeInfoVariableTemplate;
};
struct idTypeInfoVariable_enum : idTypeInfoVariable {
    using idTypeInfoVariable::idTypeInfoVariable;
};
struct idTypeInfoVariable_idStr : idTypeInfoVariable {
    using idTypeInfoVariable::idTypeInfoVariable;
};

class idTypeInfoObject {
public:
    idTypeInfoObject(void* objectPointer, const char* objectTypeName,
        const idTypeInfoTools* tools);

    bool GetBool(const idTypeInfoVariable_bool& variable, bool& value) const;
    bool GetInt(const idTypeInfoVariable_int& variable, int& value) const;
    bool GetFloat(const idTypeInfoVariable_float& variable, float& value) const;
    bool GetStrPtrType(const idTypeInfoVariable_StrPtr& variable, idStr& value,
        bool resolvePointers = true) const;
    bool GetTypeInfoObjectForListElement(
        const idTypeInfoVariable_idList& variable, int index,
        idTypeInfoObject& object) const;
    bool GetStrType(const char* type, const char* ops, const char* path,
        idStr& value, bool resolvePointers = true) const;
    bool GetValueText(const char* path, idStr& text) const;
    bool GetStr(const idTypeInfoVariable_idStr& variable, idStr& value) const;
    bool GetListNum(const idTypeInfoVariable_idList& variable, int& num) const;

    void* GetObjectPointer() const { return objectPtr; }
    const char* GetObjectType() const { return objectType.c_str(); }
    bool IsModified() const { return modified; }
    void SetModified(bool value = true) { modified = value; }

private:
    static void GetVariableName(const char* path, idStr& name,
        int& arrayIndex);
    bool Resolve(const char* path, idTypeInfoTools::resolvedPath_t& result) const;

    void* objectPtr;
    idStr objectType;
    const idTypeInfoTools* ti;
    bool modified;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(classVariableInfo_t) == 40,
    "Recovered classVariableInfo_t ABI changed");
static_assert(sizeof(classTypeInfo_t) == 28,
    "Recovered classTypeInfo_t ABI changed");
static_assert(sizeof(typeInfo_t) == 44, "Recovered typeInfo_t ABI changed");
static_assert(sizeof(idTypeInfoVariable) == 12,
    "Recovered idTypeInfoVariable ABI changed");
static_assert(sizeof(idTypeInfoVariableTemplate) == 20,
    "Recovered template variable ABI changed");
static_assert(sizeof(idTypeInfoObject) == 44,
    "Recovered idTypeInfoObject ABI changed");
static_assert(sizeof(idTypeInfoTools::stringList_t) == 16,
    "Recovered type-info string list ABI changed");
static_assert(sizeof(idTypeInfoTools) == 160,
    "Recovered idTypeInfoTools ABI changed");
static_assert(sizeof(idPathTypeInfo) == 148,
    "Recovered idPathTypeInfo ABI changed");
#endif
