#include "file.h"

#include <algorithm>
#include <atomic>
#include <cstdlib>
#include <cstring>

namespace {
std::atomic<unsigned int> nextFileId(0);
}

idFile::idFile()
    : uniqID(++nextFileId) {
}

unsigned int idFile::ReadOfs(const std::int64_t offset, void* data,
        const unsigned int length) {
    const std::int64_t position = Tell();
    if (Seek(offset, FS_SEEK_SET) != 0) return 0;
    const unsigned int result = Read(data, length);
    Seek(position, FS_SEEK_SET);
    return result;
}

unsigned int idFile::WriteOfs(const std::int64_t offset, const void* data,
        const unsigned int length) {
    const std::int64_t position = Tell();
    if (Seek(offset, FS_SEEK_SET) != 0) return 0;
    const unsigned int result = Write(data, length);
    Seek(position, FS_SEEK_SET);
    return result;
}

unsigned int idFile::Printf(const char* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const unsigned int result = VPrintf(format, arguments);
    va_end(arguments);
    return result;
}

unsigned int idFile::VPrintf(const char* format, char* arguments) {
    char text[4096];
    const int length = _vsnprintf_s(text, sizeof(text), _TRUNCATE,
        format, arguments);
    return length > 0 ? Write(text, static_cast<unsigned int>(length)) : 0;
}

unsigned int idFile::WriteFloatString(const char* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const unsigned int result = VPrintf(format, arguments);
    va_end(arguments);
    return result;
}

unsigned int idFile::ReadString(idStr& string) {
    std::uint32_t length = 0;
    unsigned int bytes = ReadLittle(length);
    if (length == 0) {
        string.Clear();
        return bytes;
    }
    char* text = static_cast<char*>(std::malloc(length + 1));
    if (text == nullptr) return bytes;
    const unsigned int read = Read(text, length);
    text[read] = '\0';
    string = text;
    std::free(text);
    return bytes + read;
}

unsigned int idFile::WriteString(const idStr& string) {
    return WriteString(string.c_str());
}

unsigned int idFile::WriteString(const char* string) {
    const char* const safeString = string != nullptr ? string : "";
    const std::uint32_t length = static_cast<std::uint32_t>(
        std::strlen(safeString));
    return WriteLittle(length) + Write(safeString, length);
}

idFile_Memory::idFile_Memory()
    : idFile(), name(), mode(FS_WRITE), maxSize(0), fileSize(0), allocated(0),
      timestamp(0), filePtr(nullptr), curPtr(nullptr), ownsData(true) {
}

idFile_Memory::idFile_Memory(const char* fileName)
    : idFile_Memory() {
    name = fileName;
}

idFile_Memory::~idFile_Memory() {
    if (ownsData) std::free(filePtr);
}

void idFile_Memory::SetReadOnlyData(const char* data,
        const unsigned int length) {
    if (ownsData) std::free(filePtr);
    maxSize = fileSize = allocated = length;
    mode = FS_READ;
    filePtr = const_cast<char*>(data);
    curPtr = filePtr;
    ownsData = false;
}

void idFile_Memory::SetWritableData(char* data, const unsigned int length) {
    if (ownsData) std::free(filePtr);
    maxSize = allocated = length;
    fileSize = 0;
    mode = FS_WRITE;
    filePtr = curPtr = data;
    ownsData = false;
}

unsigned int idFile_Memory::Read(void* data, const unsigned int length) {
    if (data == nullptr || filePtr == nullptr || curPtr == nullptr) return 0;
    const unsigned int position = static_cast<unsigned int>(curPtr - filePtr);
    const unsigned int available = position < fileSize ? fileSize - position : 0;
    const unsigned int amount = (std::min)(length, available);
    std::memcpy(data, curPtr, amount);
    curPtr += amount;
    return amount;
}

unsigned int idFile_Memory::Write(const void* data,
        const unsigned int length) {
    if (mode == FS_READ || data == nullptr) return 0;
    unsigned int position = filePtr != nullptr && curPtr != nullptr
        ? static_cast<unsigned int>(curPtr - filePtr)
        : 0;
    if (maxSize != 0 && position + length > maxSize)
        return 0;
    if (position + length > allocated) {
        const unsigned int target = (std::max)(position + length,
            allocated == 0 ? 256u : allocated * 2u);
        const unsigned int oldFileSize = fileSize;
        SetLength(target);
        fileSize = oldFileSize;
        position = curPtr != nullptr ? static_cast<unsigned int>(curPtr - filePtr) : 0;
    }
    std::memcpy(curPtr, data, length);
    curPtr += length;
    fileSize = (std::max)(fileSize, position + length);
    return length;
}

unsigned int idFile_Memory::ReadOfs(const std::int64_t offset, void* data,
        const unsigned int length) {
    if (offset < 0 || static_cast<std::uint64_t>(offset) > fileSize) return 0;
    const unsigned int position = static_cast<unsigned int>(offset);
    const unsigned int amount = (std::min)(length, fileSize - position);
    std::memcpy(data, filePtr + position, amount);
    return amount;
}

unsigned int idFile_Memory::WriteOfs(const std::int64_t offset,
        const void* data, const unsigned int length) {
    if (offset < 0) return 0;
    const std::int64_t oldPosition = Tell();
    if (Seek(offset, FS_SEEK_SET) != 0) return 0;
    const unsigned int result = Write(data, length);
    Seek(oldPosition, FS_SEEK_SET);
    return result;
}

void idFile_Memory::SetLength(const unsigned int length) {
    if (length > allocated) {
        if (maxSize != 0 && length > maxSize) return;
        const std::size_t position = filePtr != nullptr && curPtr != nullptr
            ? static_cast<std::size_t>(curPtr - filePtr)
            : 0;
        char* replacement = static_cast<char*>(std::malloc(length));
        if (replacement == nullptr && length != 0) return;
        if (filePtr != nullptr)
            std::memcpy(replacement, filePtr, (std::min)(fileSize, length));
        if (ownsData) std::free(filePtr);
        filePtr = replacement;
        curPtr = filePtr + (std::min)(position, static_cast<std::size_t>(length));
        allocated = length;
        ownsData = true;
    }
    fileSize = length;
    if (curPtr != nullptr && curPtr > filePtr + fileSize)
        curPtr = filePtr + fileSize;
}

std::int64_t idFile_Memory::Tell() const {
    return filePtr != nullptr && curPtr != nullptr ? curPtr - filePtr : 0;
}

int idFile_Memory::Seek(const std::int64_t offset, const fsOrigin_t origin) {
    std::int64_t target = offset;
    if (origin == FS_SEEK_CUR) target += Tell();
    else if (origin == FS_SEEK_END) target += fileSize;
    if (target < 0 || static_cast<std::uint64_t>(target) > fileSize) return -1;
    curPtr = filePtr + static_cast<std::size_t>(target);
    return 0;
}

void idFile_Memory::Clear(const bool freeMemory) {
    fileSize = 0;
    if (freeMemory && ownsData) {
        std::free(filePtr);
        filePtr = curPtr = nullptr;
        allocated = 0;
    } else {
        curPtr = filePtr;
    }
}

void idFile_Memory::SetMaxLength(const unsigned int length) {
    const unsigned int oldSize = fileSize;
    SetLength(length);
    maxSize = length;
    fileSize = oldSize;
}

void idFile_Memory::MakeReadOnly() {
    mode = FS_READ;
    Seek(0, FS_SEEK_SET);
}

void idFile_Memory::MakeWritable() {
    mode = FS_WRITE;
    Seek(0, FS_SEEK_SET);
}

