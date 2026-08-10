#include "framework/streamfilecache.h"

#include "framework/framework_runtime_internal.h"
#include "framework/streamfilelog.h"
#include "idlib/csystems/cvarsystem.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/lib_print.h"

#include <algorithm>
#include <chrono>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <unordered_map>
#include <vector>

namespace {

constexpr std::size_t CACHE_LINE_SIZE = 0x10000;
constexpr std::size_t NO_PROVIDED_SLOT =
    (std::numeric_limits<std::size_t>::max)();

idCVar fc_maxCacheMemoryMB(
    "fc_maxCacheMemoryMB", "64", CVAR_INTEGER,
    "Maximum cache size in megabytes", 1.0f, 96.0f);
idCVar fc_useHdc(
    "fc_useHdc", "1", CVAR_INTEGER,
    "1 = enable hard disk cache, 2 = force hard disk cache");
idCVar fc_checkHdcTimestamps(
    "fc_checkHdcTimestamps", "0", CVAR_BOOL,
    "If zero, don't clear the hard disk cache when timestamps are dirty");
idCVar fc_verifyCacheReadData(
    "fc_verifyCacheReadData", "0", CVAR_BOOL,
    "Compare every cache read with an actual ReadOfs");

struct cacheKey_t {
    const idFile* file;
    unsigned int fileID;
    int fileLine;

    bool operator==(const cacheKey_t& rhs) const {
        return file == rhs.file && fileID == rhs.fileID
            && fileLine == rhs.fileLine;
    }
};

struct cacheKeyHash_t {
    std::size_t operator()(const cacheKey_t& key) const {
        std::size_t value = reinterpret_cast<std::size_t>(key.file);
        value ^= static_cast<std::size_t>(key.fileID) * 0x9E3779B1u;
        value ^= static_cast<std::size_t>(key.fileLine) * 0x85EBCA6Bu;
        return value;
    }
};

struct cacheLine_t {
    std::vector<unsigned char> allocatedData;
    std::size_t providedSlot = NO_PROVIDED_SLOT;
    unsigned int validLength = 0;
    unsigned int lastFrame = 0;
    int priority = 0;
    int persistence = 0;
};

struct cacheState_t {
    void* providedMemory = nullptr;
    std::int64_t providedLength = 0;
    std::vector<unsigned char> providedSlotsUsed;
    std::int64_t allocated = 0;
    unsigned int frame = 0;
    unsigned long long hits = 0;
    unsigned long long misses = 0;
    unsigned long long bytesRead = 0;
    unsigned long long signals = 0;
    unsigned long long textureRequests = 0;
    unsigned long long soundRequests = 0;
    std::unordered_map<void*, std::size_t> ownedBlocks;
    std::unordered_map<cacheKey_t, cacheLine_t, cacheKeyHash_t> lines;
};

std::unordered_map<const idStreamFileCache*, cacheState_t> cacheStates;
idStreamFileCache streamFileCacheLocal;

std::int64_t CacheLimitBytes() {
    return static_cast<std::int64_t>((std::max)(1,
        fc_maxCacheMemoryMB.GetInteger())) * 1024 * 1024;
}

std::int64_t CacheBytes(const cacheState_t& state) {
    return static_cast<std::int64_t>(state.lines.size())
        * static_cast<std::int64_t>(CACHE_LINE_SIZE);
}

unsigned char* LineData(cacheState_t& state, cacheLine_t& line) {
    if (line.providedSlot != NO_PROVIDED_SLOT) {
        return static_cast<unsigned char*>(state.providedMemory)
            + line.providedSlot * CACHE_LINE_SIZE;
    }
    return line.allocatedData.empty() ? nullptr : line.allocatedData.data();
}

void ReleaseLineStorage(cacheState_t& state, cacheLine_t& line) {
    if (line.providedSlot != NO_PROVIDED_SLOT
            && line.providedSlot < state.providedSlotsUsed.size()) {
        state.providedSlotsUsed[line.providedSlot] = 0;
    }
}

bool EvictOneLine(cacheState_t& state) {
    if (state.lines.empty()) return false;
    auto victim = state.lines.begin();
    for (auto candidate = state.lines.begin(); candidate != state.lines.end();
            ++candidate) {
        if (candidate->second.persistence < victim->second.persistence
                || (candidate->second.persistence
                        == victim->second.persistence
                    && candidate->second.lastFrame
                        < victim->second.lastFrame)) {
            victim = candidate;
        }
    }
    ReleaseLineStorage(state, victim->second);
    state.lines.erase(victim);
    return true;
}

std::size_t ClaimProvidedSlot(cacheState_t& state) {
    for (std::size_t index = 0; index < state.providedSlotsUsed.size();
            ++index) {
        if (state.providedSlotsUsed[index] == 0) {
            state.providedSlotsUsed[index] = 1;
            return index;
        }
    }
    return NO_PROVIDED_SLOT;
}

cacheLine_t* LoadCacheLine(cacheState_t& state, idFile& file,
        const int fileLine, const int priority, const int persistence) {
    const cacheKey_t key = { &file, file.uniqID, fileLine };
    const auto existing = state.lines.find(key);
    if (existing != state.lines.end()) {
        ++state.hits;
        existing->second.lastFrame = state.frame;
        existing->second.priority = (std::max)(existing->second.priority,
            priority);
        existing->second.persistence = (std::max)(
            existing->second.persistence, persistence);
        return &existing->second;
    }

    ++state.misses;
    while (CacheBytes(state) + static_cast<std::int64_t>(CACHE_LINE_SIZE)
            > CacheLimitBytes()) {
        if (!EvictOneLine(state)) return nullptr;
    }

    cacheLine_t line;
    line.lastFrame = state.frame;
    line.priority = priority;
    line.persistence = persistence;
    line.providedSlot = ClaimProvidedSlot(state);
    if (line.providedSlot == NO_PROVIDED_SLOT) {
        try {
            line.allocatedData.resize(CACHE_LINE_SIZE);
        } catch (...) {
            return nullptr;
        }
    }

    unsigned char* const lineData = LineData(state, line);
    const std::int64_t lineOffset =
        static_cast<std::int64_t>(fileLine) * CACHE_LINE_SIZE;
    const std::int64_t fileLength = file.Length();
    if (lineData == nullptr || lineOffset < 0
            || (fileLength > 0 && lineOffset >= fileLength)) {
        ReleaseLineStorage(state, line);
        return nullptr;
    }

    unsigned int readLength = static_cast<unsigned int>(CACHE_LINE_SIZE);
    if (fileLength > 0) {
        readLength = static_cast<unsigned int>((std::min<std::int64_t>)(
            CACHE_LINE_SIZE, fileLength - lineOffset));
    }
    streamFileLog.NoteCacheLineRequest(file, fileLine, priority);
    const sflDrive_t drive = file.GetDevice()
            == FS_DEVICE_OPTICAL_DISK_DRIVE
        ? SFL_OPTICAL_DRIVE : SFL_HARD_DRIVE;
    streamFileLog.BeginIO(drive, SFL_READ, file, lineOffset, readLength,
        priority);
    line.validLength = file.ReadOfs(lineOffset, lineData, readLength);
    streamFileLog.EndIO(drive);
    state.bytesRead += line.validLength;
    if (line.validLength == 0) {
        ReleaseLineStorage(state, line);
        return nullptr;
    }

    const auto inserted = state.lines.emplace(key, std::move(line));
    return &inserted.first->second;
}

void ClearCacheLines(cacheState_t& state) {
    for (auto& line : state.lines) ReleaseLineStorage(state, line.second);
    state.lines.clear();
    std::fill(state.providedSlotsUsed.begin(),
        state.providedSlotsUsed.end(), 0);
}

int PositiveArg(const std::vector<idStr>& args, const std::size_t index,
        const int fallback) {
    if (index >= args.size()) return fallback;
    const int value = std::atoi(args[index].c_str());
    return value > 0 ? value : fallback;
}

void TestCacheDrive(const std::vector<idStr>& args) {
    if (fileSystem == nullptr || streamFileCache == nullptr) {
        idLibPrint::Warning("fc_testCacheDrive: filesystem is not initialized");
        return;
    }
    const int numFiles = PositiveArg(args, 1, 1);
    const int blocksPerFile = PositiveArg(args, 2, 128);
    idLibPrint::Printf("%4d files\n%4d blocks per file\n%4d kB block size\n",
        numFiles, blocksPerFile, static_cast<int>(CACHE_LINE_SIZE / 1024));
    if (args.size() > 3) {
        idLibPrint::Printf("fc_testCacheDrive: cluster/cache-size arguments "
            "are console-only and are ignored on PC\n");
    }

    streamFileCache->Flush();
    std::vector<unsigned char> block(CACHE_LINE_SIZE, 0);
    std::vector<idFile*> files(static_cast<std::size_t>(numFiles), nullptr);
    for (int index = 0; index < numFiles; ++index) {
        char name[64];
        std::snprintf(name, sizeof(name), "test%d.bin", index);
        files[index] = fileSystem->OpenFileReadWrite(name, true, FSPATH_CACHE);
        if (files[index] == nullptr) {
            idLibPrint::Warning("fc_testCacheDrive: couldn't open %s", name);
            continue;
        }
        files[index]->SetLength(static_cast<unsigned int>(blocksPerFile)
            * static_cast<unsigned int>(CACHE_LINE_SIZE));
        for (int line = 0; line < blocksPerFile; ++line) {
            files[index]->WriteOfs(
                static_cast<std::int64_t>(line) * CACHE_LINE_SIZE,
                block.data(), static_cast<unsigned int>(CACHE_LINE_SIZE));
        }
        files[index]->Flush();
    }

    unsigned int randomState = 0;
    unsigned long long totalMicros = 0;
    unsigned long long minMicros =
        (std::numeric_limits<unsigned long long>::max)();
    unsigned long long maxMicros = 0;
    int completedReads = 0;
    const int totalBlocks = numFiles * blocksPerFile;
    for (int iteration = 0; iteration < 1000 && totalBlocks > 0;
            ++iteration) {
        randomState = 1103515245u * randomState + 12345u;
        const int selected = static_cast<int>((randomState >> 16) & 0x7FFFu)
            % totalBlocks;
        idFile* const file = files[selected / blocksPerFile];
        if (file == nullptr) continue;
        const int line = selected % blocksPerFile;
        const auto begin = std::chrono::high_resolution_clock::now();
        const unsigned int read = file->ReadOfs(
            static_cast<std::int64_t>(line) * CACHE_LINE_SIZE,
            block.data(), static_cast<unsigned int>(CACHE_LINE_SIZE));
        const auto end = std::chrono::high_resolution_clock::now();
        if (read != CACHE_LINE_SIZE) {
            idLibPrint::Warning("fc_testCacheDrive: failed to read line");
            continue;
        }
        const unsigned long long micros = static_cast<unsigned long long>(
            std::chrono::duration_cast<std::chrono::microseconds>(end - begin)
                .count());
        totalMicros += micros;
        minMicros = (std::min)(minMicros, micros);
        maxMicros = (std::max)(maxMicros, micros);
        ++completedReads;
    }
    for (int index = 0; index < numFiles; ++index) {
        delete files[index];
        char name[64];
        std::snprintf(name, sizeof(name), "test%d.bin", index);
        fileSystem->RemoveFile(name, FSPATH_CACHE);
    }
    if (completedReads > 0) {
        idLibPrint::Printf("cache drive: %d reads, %llu us avg, %llu min, "
            "%llu max\n", completedReads, totalMicros / completedReads,
            minMicros, maxMicros);
    }
    streamFileCache->ClearHDC();
}

} // namespace

idStreamFileCache* streamFileCache = &streamFileCacheLocal;

idStreamFileCache::idStreamFileCache()
    : controlThread(nullptr), cancelToTerminate(false) {
}

idStreamFileCache::~idStreamFileCache() {
    Shutdown();
}

void idStreamFileCache::Init() {
    interfaceMutex.Lock();
    cancelToTerminate = false;
    cacheStates[this];
    interfaceMutex.Unlock();
}

void idStreamFileCache::Shutdown() {
    interfaceMutex.Lock();
    cancelToTerminate = true;
    const auto found = cacheStates.find(this);
    if (found != cacheStates.end()) {
        ClearCacheLines(found->second);
        for (const auto& block : found->second.ownedBlocks) {
            std::free(block.first);
        }
        cacheStates.erase(found);
    }
    controlThread = nullptr;
    interfaceMutex.Unlock();
}

void idStreamFileCache::Flush() {
    // All PC requests complete synchronously before the interface lock is
    // released, so acquiring it is the equivalent of WaitForCompletion.
    interfaceMutex.Lock();
    interfaceMutex.Unlock();
}

void idStreamFileCache::NewFrame() {
    interfaceMutex.Lock();
    ++cacheStates[this].frame;
    streamFileLog.NoteFrame();
    interfaceMutex.Unlock();
}

void idStreamFileCache::ServiceBink(fsDevice_t) {
    SignalWork();
}

std::int64_t idStreamFileCache::GetCurrentUsageLimit() const {
    const auto found = cacheStates.find(this);
    if (found != cacheStates.end() && found->second.providedLength > 0) {
        return (std::min)(found->second.providedLength, CacheLimitBytes());
    }
    return CacheLimitBytes();
}

void idStreamFileCache::Stats() {
    interfaceMutex.Lock();
    const cacheState_t& state = cacheStates[this];
    const unsigned long long requests = state.hits + state.misses;
    const unsigned long long hitPercent = requests == 0
        ? 0 : state.hits * 100 / requests;
    idLibPrint::Printf("stream cache:\n");
    idLibPrint::Printf("%8u cache lines (%lld / %lld bytes)\n",
        static_cast<unsigned int>(state.lines.size()), CacheBytes(state),
        CacheLimitBytes());
    idLibPrint::Printf("%8llu hits (%llu%%), %llu misses\n", state.hits,
        hitPercent, state.misses);
    idLibPrint::Printf("%8llu source bytes read\n", state.bytesRead);
    idLibPrint::Printf("%8llu texture requests, %llu sound requests\n",
        state.textureRequests, state.soundRequests);
    idLibPrint::Printf("%8lld uncached bytes, %u frame, %llu signals\n",
        state.allocated, state.frame, state.signals);
    interfaceMutex.Unlock();
}

void idStreamFileCache::SignalWork() {
    interfaceMutex.Lock();
    ++cacheStates[this].signals;
    interfaceMutex.Unlock();
}

void idStreamFileCache::UncachedBackgroundRead(idFile* const file,
        const std::int64_t offset, const int length, void** const destination,
        memTag_t, volatile bool* const completionFlag) {
    if (completionFlag != nullptr) *completionFlag = false;
    if (destination == nullptr) {
        if (completionFlag != nullptr) *completionFlag = true;
        return;
    }
    *destination = nullptr;
    if (file == nullptr || offset < 0 || length <= 0) {
        if (completionFlag != nullptr) *completionFlag = true;
        return;
    }

    void* memory = std::malloc(static_cast<std::size_t>(length));
    if (memory != nullptr) {
        const sflDrive_t drive = file->GetDevice()
                == FS_DEVICE_OPTICAL_DISK_DRIVE
            ? SFL_OPTICAL_DRIVE : SFL_HARD_DRIVE;
        streamFileLog.BeginIO(drive, SFL_READ, *file, offset, length, 0);
        const unsigned int read = file->ReadOfs(offset, memory,
            static_cast<unsigned int>(length));
        streamFileLog.EndIO(drive);
        if (read != static_cast<unsigned int>(length)) {
            std::free(memory);
            memory = nullptr;
        } else {
            interfaceMutex.Lock();
            cacheState_t& state = cacheStates[this];
            state.ownedBlocks[memory] = static_cast<std::size_t>(length);
            state.allocated += length;
            interfaceMutex.Unlock();
        }
    }
    *destination = memory;
    if (completionFlag != nullptr) *completionFlag = true;
}

void idStreamFileCache::BatchUncachedBackgroundRead(idFile* const file,
        const std::int64_t* const offsets, const int* const lengths,
        void*** const destinations, const memTag_t tag,
        volatile bool** const completionFlags, const int count) {
    if (offsets == nullptr || lengths == nullptr || destinations == nullptr
            || count <= 0) {
        return;
    }
    for (int index = 0; index < count; ++index) {
        UncachedBackgroundRead(file, offsets[index], lengths[index],
            destinations[index], tag,
            completionFlags != nullptr ? completionFlags[index] : nullptr);
    }
}

unsigned int idStreamFileCache::UncachedScheduledRead(idFile& file,
        const std::int64_t offset, void* const destination, const int length) {
    if (offset < 0 || destination == nullptr || length <= 0) return 0;
    const sflDrive_t drive = file.GetDevice() == FS_DEVICE_OPTICAL_DISK_DRIVE
        ? SFL_OPTICAL_DRIVE : SFL_HARD_DRIVE;
    streamFileLog.BeginIO(drive, SFL_READ, file, offset, length, 0);
    const unsigned int read = file.ReadOfs(offset, destination,
        static_cast<unsigned int>(length));
    streamFileLog.EndIO(drive);
    return read;
}

void idStreamFileCache::BatchFreeMemory(void** const pointers,
        const int count) {
    interfaceMutex.Lock();
    cacheState_t& state = cacheStates[this];
    for (int index = 0; pointers != nullptr && index < count; ++index) {
        const auto found = state.ownedBlocks.find(pointers[index]);
        if (found != state.ownedBlocks.end()) {
            state.allocated -= static_cast<std::int64_t>(found->second);
            std::free(found->first);
            state.ownedBlocks.erase(found);
            pointers[index] = nullptr;
        }
    }
    interfaceMutex.Unlock();
}

void idStreamFileCache::ProvideCacheMemory(void* const memory,
        const std::int64_t length) {
    interfaceMutex.Lock();
    cacheState_t& state = cacheStates[this];
    ClearCacheLines(state);
    state.providedMemory = memory;
    state.providedLength = memory == nullptr
        ? 0 : (std::max<std::int64_t>)(0, length);
    state.providedSlotsUsed.assign(static_cast<std::size_t>(
        state.providedLength / CACHE_LINE_SIZE), 0);
    interfaceMutex.Unlock();
}

bool idStreamFileCache::OutOfMemoryCallback() {
    interfaceMutex.Lock();
    cacheState_t& state = cacheStates[this];
    if (EvictOneLine(state)) {
        interfaceMutex.Unlock();
        return true;
    }
    if (state.ownedBlocks.empty()) {
        interfaceMutex.Unlock();
        return false;
    }
    const auto block = state.ownedBlocks.begin();
    state.allocated -= static_cast<std::int64_t>(block->second);
    std::free(block->first);
    state.ownedBlocks.erase(block);
    interfaceMutex.Unlock();
    return true;
}

int idStreamFileCache::GetAvailableMemory() const {
    const auto found = cacheStates.find(this);
    const std::int64_t used = found == cacheStates.end()
        ? 0 : CacheBytes(found->second);
    const std::int64_t available = (std::max<std::int64_t>)(0,
        CacheLimitBytes() - used);
    return static_cast<int>((std::min<std::int64_t>)(available, INT_MAX));
}

void idStreamFileCache::InitHDC() {
    // The Xenon HDC mirrored optical-disc cache lines onto its utility drive.
    // PC files are already backed by the operating-system file cache.
}

void idStreamFileCache::ClearMem(const bool releaseProvidedMemory) {
    interfaceMutex.Lock();
    cacheState_t& state = cacheStates[this];
    ClearCacheLines(state);
    for (const auto& block : state.ownedBlocks) std::free(block.first);
    state.ownedBlocks.clear();
    state.allocated = 0;
    state.hits = state.misses = state.bytesRead = 0;
    state.textureRequests = state.soundRequests = 0;
    if (releaseProvidedMemory) {
        state.providedMemory = nullptr;
        state.providedLength = 0;
        state.providedSlotsUsed.clear();
    }
    interfaceMutex.Unlock();
}

void idStreamFileCache::ClearHDC() {
    ClearMem(false);
    InitHDC();
}

int idStreamFileCache::ReadCachedData(idFile* const file,
        const std::int64_t offset, const int length, void* const destination,
        bool, const int priority, const int persistence,
        const pfcRequest_t requestType) {
    if (file == nullptr || destination == nullptr) return 0;
    if (offset < 0) {
        idLibPrint::Warning(
            "idStreamFileCache::ReadCachedData: ofs = %lld for %s", offset,
            file->GetFullPath());
        return 0;
    }
    if (length <= 0) {
        idLibPrint::Warning(
            "idStreamFileCache::ReadCachedData: length = %d for %s", length,
            file->GetFullPath());
        return 0;
    }
    const std::int64_t lastOffset = offset + length - 1;
    if (lastOffset < offset || lastOffset / CACHE_LINE_SIZE > INT_MAX) {
        idLibPrint::Warning(
            "idStreamFileCache::ReadCachedData: range is too large for %s",
            file->GetFullPath());
        return 0;
    }

    interfaceMutex.Lock();
    cacheState_t& state = cacheStates[this];
    if (requestType == PFC_SOUND) ++state.soundRequests;
    else ++state.textureRequests;
    int copied = 0;
    while (copied < length) {
        const std::int64_t sourceOffset = offset + copied;
        const int fileLine = static_cast<int>(sourceOffset / CACHE_LINE_SIZE);
        const unsigned int lineOffset = static_cast<unsigned int>(
            sourceOffset % CACHE_LINE_SIZE);
        cacheLine_t* const line = LoadCacheLine(state, *file, fileLine,
            priority, persistence);
        if (line == nullptr || lineOffset >= line->validLength) {
            interfaceMutex.Unlock();
            return 0;
        }
        const int copyLength = (std::min)(length - copied,
            static_cast<int>(line->validLength - lineOffset));
        std::memcpy(static_cast<unsigned char*>(destination) + copied,
            LineData(state, *line) + lineOffset,
            static_cast<std::size_t>(copyLength));
        copied += copyLength;
    }

    if (fc_verifyCacheReadData.GetBool()) {
        std::vector<unsigned char> verification(static_cast<std::size_t>(length));
        const unsigned int read = file->ReadOfs(offset, verification.data(),
            static_cast<unsigned int>(length));
        if (read != static_cast<unsigned int>(length)
                || std::memcmp(destination, verification.data(),
                    static_cast<std::size_t>(length)) != 0) {
            interfaceMutex.Unlock();
            idLibPrint::Error(
                "idStreamFileCache::ReadCachedData: data compare failed");
            return 0;
        }
    }
    interfaceMutex.Unlock();
    return length;
}

void idStreamFileCache::BatchRequestCacheLines(
        const cacheLineRequest_t* const requests, const int count) {
    if (requests == nullptr || count <= 0) return;
    interfaceMutex.Lock();
    cacheState_t& state = cacheStates[this];
    for (int index = 0; index < count; ++index) {
        const cacheLineRequest_t& request = requests[index];
        if (request.file != nullptr && request.fileLine >= 0) {
            LoadCacheLine(state, *request.file, request.fileLine,
                request.priority, request.persistence);
        }
    }
    interfaceMutex.Unlock();
}

void RegisterStreamFileCacheCommands() {
    tech5Framework::RegisterCommand("fc_stats",
        [](const std::vector<idStr>&) { streamFileCache->Stats(); });
    tech5Framework::RegisterCommand("fc_clearMem",
        [](const std::vector<idStr>&) {
            streamFileCache->ClearMem(false);
        });
    tech5Framework::RegisterCommand("fc_clearHDC",
        [](const std::vector<idStr>&) { streamFileCache->ClearHDC(); });
    tech5Framework::RegisterCommand("fc_testCacheDrive", TestCacheDrive);
}
