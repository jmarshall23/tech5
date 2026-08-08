#pragma once

#include "idlib/containers/recoveredlist.h"

#include <cstdint>

#pragma pack(push, 4)
class idPLog {
public:
    struct treeEntry_t {
        const char* label;
        int depth;
        int numHits;
        std::int64_t totalTicks;
        int parent;
        int firstChild;
        int nextChild;
        bool allocationOccured;
    };

    struct logEntry_t {
        const char* label;
        int parent;
        std::int64_t totalTicks;
    };

    idPLog();

    void Clear();
    void EnsureEntries();
    void SetGroupMask(std::uint64_t mask) { groupMask = mask; }
    void EnableGroups(std::uint64_t mask) { groupMask |= mask; }
    void DisableGroups(std::uint64_t mask) { groupMask &= ~mask; }
    std::uint64_t GetGroupMask() const { return groupMask; }
    bool IsGroupEnabled(std::uint64_t mask) const { return (groupMask & mask) != 0; }

    std::int64_t GetOverHeadTicks();
    void SubtractOverhead();
    float BuildLogData(float thresholdMS = 0.0f,
        std::int64_t adjustByTicks = 0);
    void ShowUniqueEntries(float thresholdMS = 0.0f,
        std::int64_t adjustByTicks = 0);
    void ShowCallGraph(float thresholdMS = 0.0f,
        std::int64_t adjustByTicks = 0);

    int NumLogEntries() const { return logEntries.Num(); }
    int NumTreeEntries() const { return treeEntries.Num(); }
    const logEntry_t& GetLogEntry(int index) const { return logEntries[index]; }

private:
    friend class idPLogScope;

    idRecoveredList<treeEntry_t> treeEntries;
    idRecoveredList<logEntry_t> logEntries;
    int lastEntry;
    int overHeadTicks;
    std::uint64_t groupMask;
};

class idPLogScope {
public:
    idPLogScope(idPLog& log, std::uint64_t groupMask, const char* label);
    ~idPLogScope();
    void End(std::int64_t* totalTicks = nullptr);

private:
    int logIndex;
    idPLog* pLog;
};
#pragma pack(pop)

extern idPLog pLog;

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idPLog::treeEntry_t) == 36,
    "Recovered idPLog tree entry ABI changed");
static_assert(sizeof(idPLog::logEntry_t) == 16,
    "Recovered idPLog log entry ABI changed");
static_assert(sizeof(idPLog) == 48, "Recovered idPLog ABI changed");
static_assert(sizeof(idPLogScope) == 8, "Recovered idPLogScope ABI changed");
#endif
