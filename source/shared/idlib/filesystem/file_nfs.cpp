#include "file_nfs.h"

#include <Windows.h>

#include <algorithm>
#include <cctype>
#include <climits>
#include <cstring>
#include <mutex>
#include <string>
#include <vector>

namespace {

struct MountEntry {
    std::string alias;
    std::wstring root;
    bool readOnly;
};

struct FileState {
    HANDLE handle = INVALID_HANDLE_VALUE;
    std::mutex mutex;
    std::wstring nativePath;
    ~FileState() {
        if (handle != INVALID_HANDLE_VALUE) CloseHandle(handle);
    }
};

std::mutex mountsMutex;
std::vector<MountEntry> mounts;

std::string Lower(std::string text) {
    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {
        return static_cast<char>(std::tolower(c));
    });
    return text;
}

std::wstring Wide(const char* text) {
    if (text == nullptr || *text == 0) return std::wstring();
    int amount = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS,
        text, -1, nullptr, 0);
    UINT codePage = CP_UTF8;
    DWORD flags = MB_ERR_INVALID_CHARS;
    if (amount == 0) {
        codePage = CP_ACP;
        flags = 0;
        amount = MultiByteToWideChar(codePage, flags, text, -1, nullptr, 0);
    }
    if (amount <= 0) return std::wstring();
    std::wstring result(static_cast<std::size_t>(amount), L'\0');
    MultiByteToWideChar(codePage, flags, text, -1, &result[0], amount);
    result.resize(static_cast<std::size_t>(amount - 1));
    return result;
}

std::wstring FullPath(const std::wstring& path) {
    const DWORD required = GetFullPathNameW(path.c_str(), 0, nullptr, nullptr);
    if (required == 0) return std::wstring();
    std::wstring result(static_cast<std::size_t>(required), L'\0');
    const DWORD amount = GetFullPathNameW(path.c_str(), required,
        &result[0], nullptr);
    if (amount == 0 || amount >= required) return std::wstring();
    result.resize(amount);
    while (result.size() > 3
        && (result.back() == L'\\' || result.back() == L'/')) {
        result.pop_back();
    }
    return result;
}

bool PathStartsWith(const std::wstring& path, const std::wstring& root) {
    if (path.size() < root.size()) return false;
    if (_wcsnicmp(path.c_str(), root.c_str(), root.size()) != 0) return false;
    return path.size() == root.size() || path[root.size()] == L'\\'
        || path[root.size()] == L'/';
}

bool Resolve(const char* nfsPath, std::wstring& nativePath,
        bool* readOnly = nullptr, std::string* aliasResult = nullptr) {
    std::string path = nfsPath == nullptr ? "" : nfsPath;
    if (path.size() >= 4 && Lower(path.substr(0, 4)) == "nfs:") {
        path.erase(0, 4);
    }
    std::replace(path.begin(), path.end(), '\\', '/');
    while (!path.empty() && path.front() == '/') path.erase(path.begin());
    const std::size_t slash = path.find('/');
    const std::string alias = Lower(path.substr(0, slash));
    const std::string relative = slash == std::string::npos
        ? std::string() : path.substr(slash + 1);
    if (alias.empty()) return false;

    std::lock_guard<std::mutex> lock(mountsMutex);
    for (const MountEntry& mount : mounts) {
        if (mount.alias != alias) continue;
        std::wstring candidate = mount.root;
        if (!relative.empty()) {
            candidate.push_back(L'\\');
            std::wstring tail = Wide(relative.c_str());
            std::replace(tail.begin(), tail.end(), L'/', L'\\');
            candidate += tail;
        }
        candidate = FullPath(candidate);
        if (candidate.empty() || !PathStartsWith(candidate, mount.root)) {
            return false;
        }
        nativePath = candidate;
        if (readOnly != nullptr) *readOnly = mount.readOnly;
        if (aliasResult != nullptr) *aliasResult = alias;
        return true;
    }
    return false;
}

bool CreateDirectories(const std::wstring& path, const bool includeLast) {
    std::wstring target = path;
    if (!includeLast) {
        const std::size_t slash = target.find_last_of(L"\\/");
        if (slash == std::wstring::npos) return true;
        target.resize(slash);
    }
    const std::size_t rootEnd = target.size() >= 3 && target[1] == L':' ? 3 : 0;
    for (std::size_t index = rootEnd; index <= target.size(); ++index) {
        if (index != target.size() && target[index] != L'\\'
            && target[index] != L'/') continue;
        const std::wstring part = target.substr(0, index);
        if (part.empty()) continue;
        if (!CreateDirectoryW(part.c_str(), nullptr)) {
            const DWORD error = GetLastError();
            if (error != ERROR_ALREADY_EXISTS) return false;
        }
    }
    return true;
}

bool RefreshMetadata(FileState& state, std::uint64_t& size,
        unsigned int& timestamp) {
    LARGE_INTEGER length{};
    FILETIME writeTime{};
    if (!GetFileSizeEx(state.handle, &length)
        || !GetFileTime(state.handle, nullptr, nullptr, &writeTime)) return false;
    size = static_cast<std::uint64_t>(length.QuadPart);
    ULARGE_INTEGER ticks{};
    ticks.LowPart = writeTime.dwLowDateTime;
    ticks.HighPart = writeTime.dwHighDateTime;
    constexpr std::uint64_t epoch = 116444736000000000ULL;
    timestamp = ticks.QuadPart > epoch
        ? static_cast<unsigned int>((ticks.QuadPart - epoch) / 10000000ULL) : 0;
    return true;
}

bool HasExtension(const std::wstring& name, const char* extension) {
    if (extension == nullptr || *extension == 0
        || std::strcmp(extension, "*") == 0) return true;
    const std::wstring suffix = Wide(extension);
    return name.size() >= suffix.size()
        && _wcsicmp(name.c_str() + name.size() - suffix.size(),
            suffix.c_str()) == 0;
}

} // namespace

idFile_Nfs::idFile_Nfs()
    : openRemote(false), fh{},
      fullPath("invalid"), mode(FS_READ), position(0), size(0),
      timeStamp(0), demandSeek(false), nfsClient(nullptr),
      ro(false) {}

idFile_Nfs::~idFile_Nfs() {
    delete reinterpret_cast<FileState*>(nfsClient);
    nfsClient = nullptr;
    openRemote = false;
}

bool idFile_Nfs::Mount(const char* alias, const char* windowsRoot,
        const bool readOnly) {
    std::string normalized = Lower(alias == nullptr ? "" : alias);
    while (!normalized.empty() && normalized.front() == '/') {
        normalized.erase(normalized.begin());
    }
    while (!normalized.empty() && normalized.back() == '/') normalized.pop_back();
    if (normalized.empty() || normalized.find('/') != std::string::npos
        || normalized.find('\\') != std::string::npos) return false;
    const std::wstring root = FullPath(Wide(windowsRoot));
    if (root.empty()) return false;
    const DWORD attributes = GetFileAttributesW(root.c_str());
    if (attributes == INVALID_FILE_ATTRIBUTES
        || (attributes & FILE_ATTRIBUTE_DIRECTORY) == 0) return false;

    std::lock_guard<std::mutex> lock(mountsMutex);
    for (MountEntry& mount : mounts) {
        if (mount.alias == normalized) {
            mount.root = root;
            mount.readOnly = readOnly;
            return true;
        }
    }
    mounts.push_back({normalized, root, readOnly});
    return true;
}

void idFile_Nfs::UnmountAll() {
    std::lock_guard<std::mutex> lock(mountsMutex);
    mounts.clear();
}

bool idFile_Nfs::Open(const char* path, const fsMode_t openMode,
        bool create, const bool createPath) {
    delete reinterpret_cast<FileState*>(nfsClient);
    nfsClient = nullptr;
    openRemote = false;

    std::wstring native;
    bool mountReadOnly = false;
    if (!Resolve(path, native, &mountReadOnly)) return false;
    const bool wantsWrite = openMode == FS_WRITE
        || openMode == FS_READ_WRITE || openMode == FS_APPEND;
    if (mountReadOnly && wantsWrite) return false;
    if (openMode == FS_WRITE || openMode == FS_APPEND) create = true;
    if (createPath && create && !CreateDirectories(native, false)) return false;

    DWORD access = GENERIC_READ;
    DWORD disposition = OPEN_EXISTING;
    if (openMode == FS_WRITE) {
        access = GENERIC_WRITE | GENERIC_READ;
        disposition = CREATE_ALWAYS;
    } else if (openMode == FS_READ_WRITE) {
        access = GENERIC_WRITE | GENERIC_READ;
        disposition = create ? OPEN_ALWAYS : OPEN_EXISTING;
    } else if (openMode == FS_APPEND) {
        access = GENERIC_WRITE | GENERIC_READ;
        disposition = OPEN_ALWAYS;
    }

    FileState* const state = new FileState;
    state->nativePath = native;
    state->handle = CreateFileW(native.c_str(), access,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, nullptr,
        disposition, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (state->handle == INVALID_HANDLE_VALUE) {
        delete state;
        return false;
    }
    nfsClient = reinterpret_cast<idNfsClient*>(state);
    openRemote = true;
    ro = mountReadOnly;
    mode = openMode;
    fullPath = path == nullptr ? "" : path;
    if (!RefreshMetadata(*state, size, timeStamp)) {
        delete state;
        nfsClient = nullptr;
        openRemote = false;
        return false;
    }
    position = openMode == FS_APPEND ? size : 0;
    return true;
}

unsigned int idFile_Nfs::ReadOfs(const std::int64_t offset, void* buffer,
        const unsigned int len) {
    FileState* const state = reinterpret_cast<FileState*>(nfsClient);
    if (state == nullptr || buffer == nullptr || len <= 0 || offset < 0) return 0;
    std::lock_guard<std::mutex> lock(state->mutex);
    LARGE_INTEGER saved{}, target{};
    target.QuadPart = offset;
    if (!SetFilePointerEx(state->handle, {}, &saved, FILE_CURRENT)
        || !SetFilePointerEx(state->handle, target, nullptr, FILE_BEGIN)) return 0;
    DWORD amount = 0;
    const BOOL success = ReadFile(state->handle, buffer,
        static_cast<DWORD>(len), &amount, nullptr);
    SetFilePointerEx(state->handle, saved, nullptr, FILE_BEGIN);
    return success ? static_cast<int>(amount) : 0;
}

unsigned int idFile_Nfs::WriteOfs(const std::int64_t offset,
        const void* buffer, const unsigned int len) {
    FileState* const state = reinterpret_cast<FileState*>(nfsClient);
    if (state == nullptr || ro || buffer == nullptr || len <= 0 || offset < 0) return 0;
    std::lock_guard<std::mutex> lock(state->mutex);
    LARGE_INTEGER saved{}, target{};
    target.QuadPart = offset;
    if (!SetFilePointerEx(state->handle, {}, &saved, FILE_CURRENT)
        || !SetFilePointerEx(state->handle, target, nullptr, FILE_BEGIN)) return 0;
    DWORD amount = 0;
    const BOOL success = WriteFile(state->handle, buffer,
        static_cast<DWORD>(len), &amount, nullptr);
    SetFilePointerEx(state->handle, saved, nullptr, FILE_BEGIN);
    if (success) {
        size = (std::max)(size, static_cast<std::uint64_t>(offset) + amount);
        RefreshMetadata(*state, size, timeStamp);
    }
    return success ? static_cast<int>(amount) : 0;
}

unsigned int idFile_Nfs::Read(void* buffer, const unsigned int len) {
    const unsigned int amount = ReadOfs(
        static_cast<std::int64_t>(position), buffer, len);
    position += static_cast<std::uint64_t>(amount);
    return amount;
}

unsigned int idFile_Nfs::Write(const void* buffer, const unsigned int len) {
    if (mode == FS_APPEND) position = size;
    const unsigned int amount = WriteOfs(
        static_cast<std::int64_t>(position), buffer, len);
    position += static_cast<std::uint64_t>(amount);
    return amount;
}

std::int64_t idFile_Nfs::Length() const {
    return static_cast<std::int64_t>(size);
}

std::int64_t idFile_Nfs::Tell() const {
    return static_cast<std::int64_t>(position);
}

int idFile_Nfs::Seek(const std::int64_t offset, const fsOrigin_t origin) {
    return Seek64(offset, origin);
}

int idFile_Nfs::Seek64(const std::int64_t offset, const fsOrigin_t origin) {
    std::int64_t base = 0;
    if (origin == FS_SEEK_CUR) base = static_cast<std::int64_t>(position);
    else if (origin == FS_SEEK_END) base = static_cast<std::int64_t>(size);
    const std::int64_t next = base + offset;
    if (next < 0) return -1;
    position = static_cast<std::uint64_t>(next);
    demandSeek = true;
    return 0;
}

void idFile_Nfs::SetLength(const unsigned int len) { SetLength64(len); }

bool idFile_Nfs::SetLength64(const std::uint64_t len) {
    FileState* const state = reinterpret_cast<FileState*>(nfsClient);
    if (state == nullptr || ro || len > static_cast<std::uint64_t>(INT64_MAX)) return false;
    std::lock_guard<std::mutex> lock(state->mutex);
    LARGE_INTEGER saved{}, target{};
    target.QuadPart = static_cast<LONGLONG>(len);
    if (!SetFilePointerEx(state->handle, {}, &saved, FILE_CURRENT)
        || !SetFilePointerEx(state->handle, target, nullptr, FILE_BEGIN)
        || !SetEndOfFile(state->handle)) return false;
    SetFilePointerEx(state->handle, saved, nullptr, FILE_BEGIN);
    size = len;
    if (position > size) position = size;
    RefreshMetadata(*state, size, timeStamp);
    return true;
}

void idFile_Nfs::Flush() {
    FileState* const state = reinterpret_cast<FileState*>(nfsClient);
    if (state != nullptr && !ro) FlushFileBuffers(state->handle);
}

void idFile_Nfs::ForceFlush() { Flush(); }

bool idFile_Nfs::CreateOsPath(const char* path) {
    std::wstring native;
    bool readOnly = false;
    return Resolve(path, native, &readOnly) && !readOnly
        && CreateDirectories(native, false);
}

int idFile_Nfs::ListFiles(const char* path, const char* extension,
        idList<idStr>& list) {
    list.Clear();
    std::wstring native;
    if (!Resolve(path, native)) return 0;
    std::wstring query = native;
    if (!query.empty() && query.back() != L'\\') query.push_back(L'\\');
    query.push_back(L'*');
    WIN32_FIND_DATAW data{};
    HANDLE find = FindFirstFileW(query.c_str(), &data);
    if (find == INVALID_HANDLE_VALUE) return 0;
    do {
        const std::wstring name = data.cFileName;
        if (name == L"." || name == L".." || !HasExtension(name, extension)) continue;
        const int amount = WideCharToMultiByte(CP_UTF8, 0, name.c_str(), -1,
            nullptr, 0, nullptr, nullptr);
        if (amount <= 1) continue;
        std::string utf8(static_cast<std::size_t>(amount), '\0');
        WideCharToMultiByte(CP_UTF8, 0, name.c_str(), -1, &utf8[0], amount,
            nullptr, nullptr);
        utf8.resize(static_cast<std::size_t>(amount - 1));
        list.Append(idStr(utf8.c_str()));
    } while (FindNextFileW(find, &data));
    FindClose(find);
    return list.Num();
}

bool idFile_Nfs::RemoveFile(const char* path) {
    std::wstring native;
    bool readOnly = false;
    if (!Resolve(path, native, &readOnly) || readOnly) return false;
    const DWORD attributes = GetFileAttributesW(native.c_str());
    if (attributes == INVALID_FILE_ATTRIBUTES) return false;
    return (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0
        ? RemoveDirectoryW(native.c_str()) != FALSE
        : DeleteFileW(native.c_str()) != FALSE;
}

bool idFile_Nfs::RenameFile(const char* oldPath, const char* newPath) {
    std::wstring oldNative, newNative;
    bool oldReadOnly = false, newReadOnly = false;
    std::string oldAlias, newAlias;
    if (!Resolve(oldPath, oldNative, &oldReadOnly, &oldAlias)
        || !Resolve(newPath, newNative, &newReadOnly, &newAlias)
        || oldReadOnly || newReadOnly || oldAlias != newAlias) return false;
    return MoveFileExW(oldNative.c_str(), newNative.c_str(),
        MOVEFILE_REPLACE_EXISTING | MOVEFILE_COPY_ALLOWED) != FALSE;
}
