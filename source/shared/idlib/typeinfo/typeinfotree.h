#pragma once

#include "../math/vector.h"
#include "idlib/typeinfo/typeinfoobject.h"

#include <new>

class idTypeInfoFile;
struct idTypeInfoSettings;

struct idTypeInfoNode {
    idStr type;
    idStr ops;
    idStr name;
    idStr value;
    idStr comment;
    idTypeInfoNode* next;
    idTypeInfoNode* children;
    idTypeInfoNode* parent;
    bool skip;
    bool diff;
};

struct idTypeInfoPath {
    explicit idTypeInfoPath(const char* pathName = "")
        : name(pathName), next(nullptr) {}
    ~idTypeInfoPath() { delete next; }

    idStr name;
    idTypeInfoPath* next;
};

template<class type>
class idTypeInfoNodeList {
public:
    explicit idTypeInfoNodeList(int listGranularity = 16)
        : list(nullptr), num(0), size(0),
          granularity(static_cast<short>(listGranularity)), memTag(5),
          listStatic(0) {}
    ~idTypeInfoNodeList() { delete[] list; }

    int Append(const type& value) {
        if (num == size) {
            const int newSize = size == 0 ? granularity : size + granularity;
            type* const replacement = new (std::nothrow) type[newSize];
            if (replacement == nullptr) return -1;
            for (int index = 0; index < num; ++index) replacement[index] = list[index];
            delete[] list;
            list = replacement;
            size = newSize;
        }
        list[num] = value;
        return num++;
    }
    void Clear() { num = 0; }
    int Num() const { return num; }
    type& operator[](int index) { return list[index]; }
    const type& operator[](int index) const { return list[index]; }

private:
    type* list;
    int num;
    int size;
    short granularity;
    unsigned char memTag;
    unsigned char listStatic;
};

class idTypeInfoTree {
public:
    idTypeInfoTree();
    idTypeInfoTree(const char* text, int length);
    ~idTypeInfoTree();

    void Clear();
    idTypeInfoNode* SetRoot(const char* type, const char* name,
        const char* value = "", const char* ops = "",
        const char* comment = "");
    idTypeInfoNode* InsertNode(const char* type, const char* ops,
        const char* name, const char* value, const char* comment,
        idTypeInfoNode* parentNode, idTypeInfoNode* nodeAfter = nullptr);
    idTypeInfoNode* FindAndOverwriteNode(const char* type, const char* ops,
        const char* name, const char* value, const char* comment,
        idTypeInfoNode* parentNode);

    idTypeInfoNode* FindPath(idTypeInfoNode* startNode, const char* path) const;
    idTypeInfoNode* CreatePath(const char* path,
        const idTypeInfoTools* tools = nullptr);
    void GetPath(const idTypeInfoNode* baseNode, const idTypeInfoNode* node,
        idStr& path) const;

    void Diff(const idTypeInfoTree& other);
    void Write(idTypeInfoFile& file, bool onlyDiff = false) const;
    void Parse(idTypeInfoFile& file);
    void ParseOverwrite(idTypeInfoFile& file);
    void ForceRootDifferent(bool set);
    bool IsSkipped(const char* path) const;
    bool GetInt(const char* path, int& value) const;
    bool GetStr(const char* path, idStr& value) const;
    bool SetStr(const char* path, const char* value);
    bool GetBool(const char* path, bool& value) const;
    bool GetVec3(const char* path, idVec3& value) const;
    bool SetVec3(const char* path, const idVec3& value);
    bool GetMat3(const char* path, idMat3& value) const;
    bool SetMat3(const char* path, const idMat3& value);
    bool GetStrType(const char* path, idStr& value) const;
    bool SetStrType(const char* path, const char* value);
    void GetTypes(const char* type, const char* ops,
        idTypeInfoNodeList<idTypeInfoNode*>& nodes) const;
    void RemoveOutOfBoundsMembers();

    idTypeInfoNode* GetRoot() const { return root; }

private:
    struct recoveredBlockAllocator_t {
        void* blocks;
        void* free;
        int total;
        int active;
        bool allowAllocs;
        bool clearAllocs;
    };

    static idTypeInfoPath* ParsePath(const char* path);
    static idTypeInfoNode* FindPath(idTypeInfoNode* baseNode,
        const idTypeInfoPath* path);
    static bool EqualNoCase(const char* left, const char* right,
        int prefixLength = -1);
    static void MarkDifferent(idTypeInfoNode* node);
    static idTypeInfoNode* FindMatchingLeaf(const idTypeInfoTree& tree,
        const idTypeInfoNode* node);
    void Diff_r(const idTypeInfoTree& other, idTypeInfoNode* node);
    void WriteType_r(idTypeInfoFile& file, idTypeInfoNode* node,
        bool onlyDiff) const;
    idTypeInfoNode* ReadType_r(idTypeInfoFile& file,
        idTypeInfoNode* parentNode, bool overwrite);
    void FreeTree_r(idTypeInfoNode* node);
    void GetTypes_r(idTypeInfoNode* node, const char* type, const char* ops,
        idTypeInfoNodeList<idTypeInfoNode*>& nodes) const;
    void RemoveOutOfBoundsMembers_r(idTypeInfoNode* node);

    idTypeInfoNode* root;
    recoveredBlockAllocator_t nodeBlockAlloc;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idTypeInfoNode) == 176,
    "Recovered idTypeInfoNode ABI changed");
static_assert(sizeof(idTypeInfoPath) == 36,
    "Recovered idTypeInfoPath ABI changed");
static_assert(sizeof(idTypeInfoNodeList<idTypeInfoNode*>) == 16,
    "Recovered type-info node list ABI changed");
static_assert(sizeof(idTypeInfoTree) == 24,
    "Recovered idTypeInfoTree ABI changed");
#endif
