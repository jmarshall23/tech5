#pragma once

#include "idlib/text/str.h"

#include <new>

enum scFileType_t {
    SCT_TEXT = 0,
    SCT_BINARY,
    SCT_SYMLINK,
    SCT_APPLE,
    SCT_RESOURCE,
    SCT_UNICODE,
    SCT_UTF16,
    SCT_NONE
};

enum scFileStatus_t {
    SCF_NOTMANAGED = 0,
    SCF_NOTIMPORTED,
    SCF_CHECKEDOUT,
    SCF_CHECKEDOUT_PLUS,
    SCF_CHECKEDOUT_BYOTHER,
    SCF_CHECKEDOUT_BYOTHER_EXCLUSIVE,
    SCF_CHECKEDIN
};

template<class type, int tag = 5>
class idSourceControlList {
public:
    explicit idSourceControlList(int listGranularity = 16)
        : list(nullptr), num(0), size(0),
          granularity(static_cast<short>(listGranularity > 0
              ? listGranularity : 16)), memTag(tag), listStatic(0) {}

    idSourceControlList(const idSourceControlList& other)
        : idSourceControlList(other.granularity) {
        EnsureCapacity(other.num);
        for (int index = 0; index < other.num; ++index) Append(other[index]);
    }

    ~idSourceControlList() { delete[] list; }

    idSourceControlList& operator=(const idSourceControlList& other) {
        if (this == &other) return *this;
        Clear();
        granularity = other.granularity;
        EnsureCapacity(other.num);
        for (int index = 0; index < other.num; ++index) Append(other[index]);
        return *this;
    }

    int Append(const type& value) {
        if (!EnsureCapacity(num + 1)) return -1;
        list[num] = value;
        return num++;
    }

    void Clear() { num = 0; }
    int Num() const { return num; }
    type& operator[](int index) { return list[index]; }
    const type& operator[](int index) const { return list[index]; }

private:
    bool EnsureCapacity(int amount) {
        if (amount <= size) return true;
        int newSize = size == 0 ? granularity : size;
        while (newSize < amount) newSize += granularity;
        type* const replacement = new (std::nothrow) type[newSize];
        if (replacement == nullptr) return false;
        for (int index = 0; index < num; ++index) replacement[index] = list[index];
        delete[] list;
        list = replacement;
        size = newSize;
        return true;
    }

    type* list;
    int num;
    int size;
    short granularity;
    unsigned char memTag;
    unsigned char listStatic;
};

using idSourceControlFileList = idSourceControlList<idStr, 5>;

class idSourceControl {
public:
    struct idSourceControlWorkspace {
        idStr name;
        idStr lastAccessTime;
        idStr owner;
        idStr host;
    };
    using workspaceList_t = idSourceControlList<idSourceControlWorkspace, 5>;

    virtual ~idSourceControl() = default;
    virtual bool Init() { return false; }
    virtual void Shutdown() {}
    virtual void SetSilentCheckOut(bool) {}
    virtual bool GetSilentCheckOut() const { return false; }
    virtual void SetSilentCheckIn(bool) {}
    virtual bool GetSilentCheckIn() const { return false; }
    virtual bool IsConnected() const { return false; }
    virtual bool IsInitialized() const { return false; }
    virtual int CheckOut(const idSourceControlFileList&) { return 0; }
    virtual int UndoCheckOut(const idSourceControlFileList&) { return 0; }
    virtual int Import(const idSourceControlFileList&, bool, bool,
        scFileType_t) { return 0; }
    virtual int GetLatest(const idSourceControlFileList&, bool) { return 0; }
    virtual int CheckIn(const idSourceControlFileList&, const idStr&,
        bool) { return 0; }
    virtual int Delete(const idSourceControlFileList&) { return 0; }
    virtual int UpdateFolder(const char*) { return 0; }
    virtual scFileStatus_t GetFileStatus(const idStr&) {
        return SCF_NOTMANAGED;
    }
    virtual bool GetFileVersion(const idStr&, int&, int&) { return false; }
    virtual int GetNumCheckOutUsers(const idStr&) { return 0; }
    virtual void GetCheckOutUser(const idStr&, int, char* output,
        int outputSize) {
        if (output != nullptr && outputSize > 0) output[0] = '\0';
    }
    virtual void GetUsernameForFileVersion(const idStr&, int,
        idStr& output) { output.Clear(); }
    virtual void GetCurrentWorkspace(idSourceControlWorkspace& output) {
        output = idSourceControlWorkspace();
    }
    virtual void GetAvailableWorkspaces(workspaceList_t& output) {
        output.Clear();
    }
    virtual void SetWorkspace(const char*) {}
    virtual void SetWorkspace(idSourceControlWorkspace&) {}
    virtual bool IsWorkspaceValid() { return false; }
    virtual idStr GetUsername() { return idStr(); }

    int CheckOut(const idStr& file) {
        idSourceControlFileList files(1);
        files.Append(file);
        return CheckOut(files);
    }

    int Import(const idStr& file, bool keepCheckedOut, bool submit,
            scFileType_t fileType) {
        idSourceControlFileList files(1);
        files.Append(file);
        return Import(files, keepCheckedOut, submit, fileType);
    }

    int GetLatest(const idStr& file, bool force) {
        idSourceControlFileList files(1);
        files.Append(file);
        return GetLatest(files, force);
    }

    int Delete(const idStr& file) {
        idSourceControlFileList files(1);
        files.Append(file);
        return Delete(files);
    }
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idSourceControlFileList) == 16,
    "Recovered source-control list ABI changed");
static_assert(sizeof(idSourceControl::idSourceControlWorkspace) == 128,
    "Recovered source-control workspace ABI changed");
static_assert(sizeof(idSourceControl) == 4,
    "Recovered idSourceControl ABI changed");
#endif
