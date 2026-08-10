#include "framework/streamfilelog.h"
#include "framework/framework_runtime.h"

#include "idlib/filesystem/file.h"
#include "idlib/lib_print.h"

#include <algorithm>
#include <chrono>

namespace {
std::int64_t Microseconds() {
    return std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count();
}
}

idStreamFileLog streamFileLog;

idStreamFileLog::idStreamFileLog()
    : numEntries(0), maxEntries(0), entries(nullptr),
      driveState{SFL_IDLE, SFL_IDLE, SFL_IDLE},
      currentEntry{nullptr, nullptr, nullptr} {
}

idStreamFileLog::~idStreamFileLog() {
    Disable();
}

void idStreamFileLog::Enable(const int entryCapacity) {
    mutex.Lock();
    delete[] entries;
    maxEntries = (std::max)(0, entryCapacity);
    entries = maxEntries > 0 ? new sflEntry_t[maxEntries]() : nullptr;
    numEntries = 0;
    for (int index = 0; index < SFL_NUM_DRIVES; ++index) {
        driveState[index] = SFL_IDLE;
        currentEntry[index] = nullptr;
    }
    mutex.Unlock();
}

void idStreamFileLog::Disable() {
    mutex.Lock();
    delete[] entries;
    entries = nullptr;
    numEntries = 0;
    maxEntries = 0;
    mutex.Unlock();
}

void idStreamFileLog::NoteFrame() {
    if (entries == nullptr || maxEntries <= 0) return;
    mutex.Lock();
    sflEntry_t& entry = entries[numEntries++ % maxEntries];
    entry = {Microseconds(), SFL_CONTROL, SFL_WRITE, nullptr, 0, 0, 0};
    mutex.Unlock();
}

void idStreamFileLog::NoteCacheLineRequest(const idFile& file,
        const int fileLine, const int priority) {
    if (entries == nullptr || maxEntries <= 0) return;
    mutex.Lock();
    sflEntry_t& entry = entries[numEntries++ % maxEntries];
    entry = {Microseconds(), SFL_CONTROL, SFL_READ, &file,
        fileLine, 0, priority};
    mutex.Unlock();
}

void idStreamFileLog::BeginIO(const sflDrive_t drive, const sflIO_t io,
        const idFile& file, const std::int64_t offset,
        const std::int64_t length, const int priority) {
    if (drive < 0 || drive >= SFL_NUM_DRIVES) return;
    mutex.Lock();
    driveState[drive] = io;
    if (entries != nullptr && maxEntries > 0) {
        sflEntry_t& entry = entries[numEntries++ % maxEntries];
        entry = {Microseconds(), drive, io, &file, offset, length, priority};
        currentEntry[drive] = &entry;
    }
    mutex.Unlock();
}

void idStreamFileLog::EndIO(const sflDrive_t drive) {
    if (drive < 0 || drive >= SFL_NUM_DRIVES) return;
    mutex.Lock();
    if (currentEntry[drive] != nullptr) {
        currentEntry[drive]->length = Microseconds()
            - currentEntry[drive]->microseconds;
    }
    currentEntry[drive] = nullptr;
    driveState[drive] = SFL_IDLE;
    mutex.Unlock();
}

void idStreamFileLog::Report() const {
    const int count = (std::min)(numEntries, maxEntries);
    idLibPrint::Printf("stream file log: %d retained entries (%d total)\n",
        count, numEntries);
    for (int index = 0; index < count; ++index) {
        const sflEntry_t& entry = entries[index];
        idLibPrint::Printf("%lld drive=%d io=%d file=%s ofs=%lld len=%lld priority=%d\n",
            entry.microseconds, entry.drive, entry.io,
            entry.file != nullptr ? entry.file->GetName() : "<frame>",
            entry.offset, entry.length, entry.priority);
    }
}

void RegisterStreamFileLogCommands() {
    tech5Framework::RegisterCommand("enableStreamFileLog",
        [](const std::vector<idStr>& args) {
            int capacity = 0x4000;
            if (args.size() > 1) {
                capacity = (std::max)(1, std::atoi(args[1].c_str()));
            }
            streamFileLog.Enable(capacity);
        });
    tech5Framework::RegisterCommand("reportStreamFileLog",
        [](const std::vector<idStr>&) { streamFileLog.Report(); });
}
