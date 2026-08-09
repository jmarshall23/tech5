#pragma once

#include "containers/hashindex.h"
#include "containers/list.h"
#include "text/str.h"

class idFile;
class idLexer;

class idKeyValue {
public:
    const idStr& GetKey() const { return key; }
    const idStr& GetValue() const { return value; }

    idStr key;
    idStr value;
};

class idDict {
public:
    idDict();
    idDict(const idDict& other);
    ~idDict();

    idDict& operator=(const idDict& other);
    int GetNumKeyVals() const { return args.Num(); }
    const idKeyValue* GetKeyVal(int index) const { return &args[index]; }
    const idKeyValue* FindKey(const char* key) const;
    int FindKeyIndex(const char* key) const;
    const char* GetString(const char* key,
        const char* defaultString = "") const {
        const idKeyValue* const kv = FindKey(key);
        return kv == nullptr ? defaultString : kv->value.c_str();
    }
    bool GetInt(const char* key, int defaultValue, int& out) const;
    bool GetFloat(const char* key, float defaultValue, float& out) const;
    bool Set(const char* key, const char* value);
    void Delete(const char* key);
    void Clear();
    unsigned int Checksum() const;
    void Print() const;
    void WriteToIniFile(idFile* file) const;
    bool ReadFromIniFile(idFile* file);
    bool Parse(idLexer& parser, const char* start, const char* end);

    idList<idKeyValue> args;
    idHashIndex argHash;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idKeyValue) == 64, "Recovered idKeyValue ABI changed");
static_assert(sizeof(idDict) == 48, "Recovered idDict ABI changed");
#endif
