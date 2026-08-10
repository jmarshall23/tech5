#include "framework/resourcemanager_background.h"

#include "framework/resource.h"

#include <algorithm>
#include <cstring>

idBGLRingBuffer::idBGLRingBuffer(const int bufferSize)
    : buffer(bufferSize > 0 ? new unsigned char[bufferSize] : nullptr),
      size(std::max(0, bufferSize)), tail(0), commitHead(0),
      cancelToTerminate(false), freeSignal(false), lastFreeSignalTail(0),
      dataSignal(false), lastDataSignalHead(0), freeWaituS(0), numFreeWaits(0),
      dataWaituS(0), numDataWaits(0) {
}

idBGLRingBuffer::~idBGLRingBuffer() { delete[] buffer; }

std::int64_t idBGLRingBuffer::CheckSpaceAndWait(const std::int64_t length,
        const int alignment) {
    if (length < 0 || length > size) return -1;
    const std::int64_t aligned = (commitHead + alignment - 1) & ~(alignment - 1);
    if (aligned + length - tail > size) {
        ++numFreeWaits;
        return -1;
    }
    commitHead = aligned + length;
    return aligned;
}

void idBGLRingBuffer::Free(const std::int64_t offset, const int length) {
    tail = std::max(tail, offset + length);
    lastFreeSignalTail = tail;
    freeSignal.Raise();
}

unsigned int idBGLRingBuffer::ReadOfs(std::int64_t offset, void* data,
        unsigned int length) {
    if (buffer == nullptr || data == nullptr || offset < tail
            || offset + length > commitHead) return 0;
    unsigned char* output = static_cast<unsigned char*>(data);
    for (unsigned int index = 0; index < length; ++index)
        output[index] = buffer[(offset + index) % size];
    return length;
}

void idBGLRingBuffer::WriteOfs(std::int64_t offset, const void* data,
        unsigned int length) {
    if (buffer == nullptr || data == nullptr || offset < 0) return;
    const unsigned char* input = static_cast<const unsigned char*>(data);
    for (unsigned int index = 0; index < length; ++index)
        buffer[(offset + index) % size] = input[index];
    commitHead = std::max(commitHead, offset + length);
    lastDataSignalHead = commitHead;
    dataSignal.Raise();
}

idFile_RingBuffer::idFile_RingBuffer(const char* fileName,
        idBGLRingBuffer* ring, const std::int64_t offset, const int length)
    : ringBuffer(ring), name(fileName), fileSize(std::max(0, length)),
      baseOffset(offset), currOffset(0) {
}

idFile_RingBuffer::~idFile_RingBuffer() = default;
const char* idFile_RingBuffer::GetName() const { return name.c_str(); }

unsigned int idFile_RingBuffer::Read(void* data, const unsigned int length) {
    const unsigned int amount = std::min(length,
        fileSize - static_cast<unsigned int>(currOffset));
    const unsigned int read = ringBuffer != nullptr
        ? ringBuffer->ReadOfs(baseOffset + currOffset, data, amount) : 0;
    currOffset += read;
    return read;
}

std::int64_t idFile_RingBuffer::Length() const { return fileSize; }
std::int64_t idFile_RingBuffer::Tell() const { return currOffset; }

int idFile_RingBuffer::Seek(const std::int64_t offset, const fsOrigin_t origin) {
    std::int64_t target = offset;
    if (origin == FS_SEEK_CUR) target += currOffset;
    else if (origin == FS_SEEK_END) target += fileSize;
    if (target < 0 || target > fileSize) return -1;
    currOffset = target;
    return 0;
}

idBackgroundLoader::idBackgroundLoader()
    : resourceFile(nullptr), fileTable(nullptr), readIndex(0),
      decompressIndex(0), returnedIndex(0), cancelToTerminate(false),
      entryStartedSignal(false), decompressBuffer(nullptr) {
}

idBackgroundLoader::~idBackgroundLoader() { EndBackgroundLoads(); }

void idBackgroundLoader::BeginBackgroundLoads(idFile& source,
        const idList<idResourceFileEntry, 99>& entries) {
    EndBackgroundLoads();
    resourceFile = &source;
    fileTable = &entries;
    bgrEntries.SetNum(entries.Num());
    decompressBuffer = new idBGLRingBuffer(8 * 1024 * 1024);
    for (int index = 0; index < entries.Num(); ++index) {
        const idResourceFileEntry& entry = entries[index];
        const std::int64_t offset = decompressBuffer->CheckSpaceAndWait(
            entry.uncompressedLength, 16);
        bgrEntries[index].ringBufferOffset = offset;
        if (offset < 0) continue;
        unsigned char* compressed = new unsigned char[entry.compressedLength];
        const unsigned int read = source.ReadOfs(entry.offset, compressed,
            entry.compressedLength);
        decompressBuffer->WriteOfs(offset, compressed,
            std::min<unsigned int>(read, entry.uncompressedLength));
        delete[] compressed;
        readIndex = decompressIndex = index + 1;
    }
}

void idBackgroundLoader::EndBackgroundLoads() {
    cancelToTerminate = true;
    delete decompressBuffer; decompressBuffer = nullptr;
    resourceFile = nullptr; fileTable = nullptr; bgrEntries.Clear();
    readIndex = decompressIndex = returnedIndex = 0;
}

idFile* idBackgroundLoader::GetFile(const char* resourceName) {
    if (fileTable == nullptr || decompressBuffer == nullptr) return nullptr;
    for (int index = 0; index < fileTable->Num(); ++index) {
        const idResourceFileEntry& entry = (*fileTable)[index];
        if (idStr::Icmp(entry.resourceName.c_str(), resourceName) == 0) {
            returnedIndex = index + 1;
            return new idFile_RingBuffer(resourceName, decompressBuffer,
                bgrEntries[index].ringBufferOffset, entry.uncompressedLength);
        }
    }
    return nullptr;
}

void idBackgroundLoader::SkipPastResource(const idResource* resource) {
    if (resource == nullptr || fileTable == nullptr) return;
    for (int index = returnedIndex; index < fileTable->Num(); ++index)
        if (idStr::Icmp((*fileTable)[index].resourceName.c_str(), resource->GetName()) == 0)
            returnedIndex = index + 1;
}

void idBackgroundLoader::SpawnThreads() { cancelToTerminate = false; }
void idBackgroundLoader::DestroyThreads() { cancelToTerminate = true; }
