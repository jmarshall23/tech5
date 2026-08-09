#include "file_permanent.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

namespace {
HANDLE FileHandle(const void* handle) {
    return static_cast<HANDLE>(const_cast<void*>(handle));
}
}

idFile_Permanent::idFile_Permanent(const char* relativePath,
        const char* osPath, const fsMode_t fileMode, const bool create)
    : idFile(), name(relativePath), fullPath(osPath), mode(fileMode),
      fileSize(0), sectorSize(1), device(FS_DEVICE_HARD_DISK_DRIVE),
      handle(nullptr) {
    DWORD access = GENERIC_READ;
    DWORD share = FILE_SHARE_READ | FILE_SHARE_WRITE;
    DWORD disposition = OPEN_EXISTING;
    if (mode == FS_WRITE) {
        access = GENERIC_WRITE;
        share = 0;
        disposition = CREATE_ALWAYS;
    } else if (mode == FS_READ_WRITE) {
        access = GENERIC_READ | GENERIC_WRITE;
        disposition = create ? OPEN_ALWAYS : OPEN_EXISTING;
    } else if (mode == FS_APPEND) {
        access = FILE_APPEND_DATA;
        share |= FILE_SHARE_DELETE;
        disposition = OPEN_ALWAYS;
    }
    HANDLE file = CreateFileA(fullPath.c_str(), access,
        share, nullptr, disposition,
        FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE) return;
    handle = file;
    LARGE_INTEGER size;
    if (GetFileSizeEx(file, &size)) fileSize = size.QuadPart;
    if (mode == FS_APPEND) Seek(0, FS_SEEK_END);
}

idFile_Permanent::~idFile_Permanent() {
    if (handle != nullptr) CloseHandle(FileHandle(handle));
    handle = nullptr;
}

unsigned int idFile_Permanent::Read(void* data, const unsigned int length) {
    if (handle == nullptr || data == nullptr) return 0;
    DWORD amount = 0;
    return ReadFile(FileHandle(handle), data, length, &amount, nullptr)
        ? amount : 0;
}

unsigned int idFile_Permanent::Write(const void* data,
        const unsigned int length) {
    if (handle == nullptr || data == nullptr || mode == FS_READ) return 0;
    DWORD amount = 0;
    if (!WriteFile(FileHandle(handle), data, length, &amount, nullptr)) return 0;
    const std::int64_t position = Tell();
    if (position > fileSize) fileSize = position;
    return amount;
}

unsigned int idFile_Permanent::ReadOfs(const std::int64_t offset, void* data,
        const unsigned int length) {
    if (handle == nullptr || offset < 0) return 0;
    OVERLAPPED overlapped = {};
    overlapped.Offset = static_cast<DWORD>(offset);
    overlapped.OffsetHigh = static_cast<DWORD>(
        static_cast<std::uint64_t>(offset) >> 32);
    DWORD amount = 0;
    return ReadFile(FileHandle(handle), data, length, &amount, &overlapped)
        ? amount : 0;
}

unsigned int idFile_Permanent::WriteOfs(const std::int64_t offset,
        const void* data, const unsigned int length) {
    if (handle == nullptr || offset < 0 || mode == FS_READ) return 0;
    OVERLAPPED overlapped = {};
    overlapped.Offset = static_cast<DWORD>(offset);
    overlapped.OffsetHigh = static_cast<DWORD>(
        static_cast<std::uint64_t>(offset) >> 32);
    DWORD amount = 0;
    if (!WriteFile(FileHandle(handle), data, length, &amount, &overlapped)) return 0;
    const std::int64_t end = offset + amount;
    if (end > fileSize) fileSize = end;
    return amount;
}

bool idFile_Permanent::Lock(const std::int64_t offset,
        const unsigned int length, const fsLock_t lock) {
    if (handle == nullptr || offset < 0) return false;
    OVERLAPPED overlapped = {};
    overlapped.Offset = static_cast<DWORD>(offset);
    overlapped.OffsetHigh = static_cast<DWORD>(
        static_cast<std::uint64_t>(offset) >> 32);
    return LockFileEx(FileHandle(handle),
        lock == FS_LOCK_EXCLUSIVE ? LOCKFILE_EXCLUSIVE_LOCK : 0, 0,
        length, 0, &overlapped) != FALSE;
}

bool idFile_Permanent::Unlock(const std::int64_t offset,
        const unsigned int length) {
    if (handle == nullptr || offset < 0) return false;
    OVERLAPPED overlapped = {};
    overlapped.Offset = static_cast<DWORD>(offset);
    overlapped.OffsetHigh = static_cast<DWORD>(
        static_cast<std::uint64_t>(offset) >> 32);
    return UnlockFileEx(FileHandle(handle), 0, length, 0, &overlapped) != FALSE;
}

std::int64_t idFile_Permanent::Length() const {
    return fileSize;
}

void idFile_Permanent::SetLength(const unsigned int length) {
    if (handle == nullptr || mode == FS_READ) return;
    const std::int64_t oldPosition = Tell();
    if (Seek(length, FS_SEEK_SET) == 0 && SetEndOfFile(FileHandle(handle)))
        fileSize = length;
    Seek(oldPosition < fileSize ? oldPosition : fileSize, FS_SEEK_SET);
}

std::int64_t idFile_Permanent::Tell() const {
    if (handle == nullptr) return 0;
    LARGE_INTEGER distance = {}, position = {};
    return SetFilePointerEx(FileHandle(handle), distance, &position, FILE_CURRENT)
        ? position.QuadPart : 0;
}

int idFile_Permanent::Seek(const std::int64_t offset, const fsOrigin_t origin) {
    if (handle == nullptr) return -1;
    DWORD method = FILE_BEGIN;
    if (origin == FS_SEEK_CUR) method = FILE_CURRENT;
    else if (origin == FS_SEEK_END) method = FILE_END;
    LARGE_INTEGER distance;
    distance.QuadPart = offset;
    return SetFilePointerEx(FileHandle(handle), distance, nullptr, method)
        ? 0 : -1;
}

unsigned int idFile_Permanent::Timestamp() const {
    if (handle == nullptr) return 0;
    FILETIME writeTime;
    if (!GetFileTime(FileHandle(handle), nullptr, nullptr, &writeTime)) return 0;
    ULARGE_INTEGER value;
    value.LowPart = writeTime.dwLowDateTime;
    value.HighPart = writeTime.dwHighDateTime;
    const std::uint64_t unixTicks = value.QuadPart > 116444736000000000ULL
        ? value.QuadPart - 116444736000000000ULL : 0;
    return static_cast<unsigned int>(unixTicks / 10000000ULL);
}

void idFile_Permanent::Flush() {
    if (handle != nullptr) FlushFileBuffers(FileHandle(handle));
}

void idFile_Permanent::ForceFlush() {
    Flush();
}
