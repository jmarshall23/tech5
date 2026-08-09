#pragma once

#include "blockalloc.h"
#include "containers/hashindex.h"
#include "containers/list.h"

class idLangKeyValue {
public:
    char* key;
    char* value;
};

class idLangDict {
public:
    idLangDict();
    ~idLangDict();

    static bool IsStringId(const char* string);
    bool Load(const unsigned char* buffer, int bufferLength, const char* name);
    bool Save(const char* fileName);
    void Clear();
    bool SetString(const char* key, const char* value);
    bool DeleteString(int index);
    void AddKeyVal(const char* key, const char* value);
    const idLangKeyValue* GetKeyVal(int index) const;
    int GetNumKeyVals() const { return keyVals.Num(); }

    static const char* KEY_PREFIX;
    static int KEY_PREFIX_LEN;

    idDynamicBlockAlloc<char, 102400, 16, TAG_LANGDICT> blockAlloc;
    idList<idLangKeyValue, TAG_LANGDICT> keyVals;
    idHashIndex keyIndex;

private:
    int FindStringIndex(const char* string) const;
    const char* FindString_r(const char* string, int& depth) const;

    friend class idStrId;
    friend class idLocalization;
};

class idStrId {
public:
    idStrId() : index(-1) {}
    explicit idStrId(const char* key) : index(-1) { Set(key); }

    void Set(const char* key);
    const char* GetKey() const;
    const char* GetLocalizedString() const;
    int GetIndex() const { return index; }
    bool IsValid() const { return index >= 0; }

    int index;
};

class idLocalization {
public:
    static bool LoadDictionary(const unsigned char* data, int dataLength,
        const char* fileName);
    static const char* GetString(const char* string);
    static const char* FindString(const char* string);

    static idLangDict languageDict;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idLangKeyValue) == 8,
    "Recovered idLangKeyValue ABI changed");
static_assert(sizeof(idStrId) == 4, "Recovered idStrId ABI changed");
#endif
