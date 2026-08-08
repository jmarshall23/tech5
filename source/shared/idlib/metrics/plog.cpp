#include "plog.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

#include <algorithm>
#include <cstdio>
#include <cstring>

namespace {

std::int64_t ClockTicks() {
    LARGE_INTEGER counter = {};
    QueryPerformanceCounter(&counter);
    return counter.QuadPart;
}

double TicksPerMillisecond() {
    static double value = 0.0;
    if (value == 0.0) {
        LARGE_INTEGER frequency = {};
        QueryPerformanceFrequency(&frequency);
        value = static_cast<double>(frequency.QuadPart) / 1000.0;
    }
    return value;
}

float TicksToMilliseconds(const std::int64_t ticks) {
    return static_cast<float>(static_cast<double>(ticks) / TicksPerMillisecond());
}

} // namespace

idPLog pLog;

idPLog::idPLog()
    : treeEntries(64), logEntries(64), lastEntry(0), overHeadTicks(-1),
      groupMask(0) {
    Clear();
}

void idPLog::Clear() {
    treeEntries.Clear();
    logEntries.Clear();
    logEntry_t* const root = logEntries.Alloc();
    if (root != nullptr) {
        root->label = "root";
        root->parent = 0;
        root->totalTicks = 0;
    }
    lastEntry = 0;
}

void idPLog::EnsureEntries() {
    logEntries.Reserve(4096);
    treeEntries.Reserve(4096);
}

std::int64_t idPLog::GetOverHeadTicks() {
    if (overHeadTicks >= 0) return overHeadTicks;
    std::int64_t best = INT64_MAX;
    for (int pass = 0; pass < 4; ++pass) {
        const std::int64_t start = ClockTicks();
        for (int index = 0; index < 1000; ++index) {
            const std::int64_t end = ClockTicks();
            (void)end;
        }
        best = std::min(best, ClockTicks() - start);
    }
    overHeadTicks = static_cast<int>(best / 1000);
    return overHeadTicks;
}

void idPLog::SubtractOverhead() {
    const std::int64_t overhead = GetOverHeadTicks();
    for (int index = 1; index < logEntries.Num(); ++index) {
        const int parent = logEntries[index].parent;
        if (parent >= 0 && parent < logEntries.Num()) {
            logEntries[parent].totalTicks = std::max<std::int64_t>(0,
                logEntries[parent].totalTicks - overhead);
        }
    }
}

float idPLog::BuildLogData(const float thresholdMS,
        const std::int64_t adjustByTicks) {
    treeEntries.Clear();
    treeEntry_t* const root = treeEntries.Alloc();
    if (root == nullptr) return 0.0f;
    root->label = "root";
    root->depth = 0;
    root->numHits = 1;
    root->parent = -1;
    root->firstChild = -1;
    root->nextChild = -1;

    for (int index = 1; index < logEntries.Num(); ++index) {
        const logEntry_t& source = logEntries[index];
        int treeParent = 0;
        if (source.parent > 0 && source.parent < index) {
            const char* const parentLabel = logEntries[source.parent].label;
            for (int candidate = treeEntries.Num() - 1; candidate > 0; --candidate) {
                if (treeEntries[candidate].label == parentLabel
                        || std::strcmp(treeEntries[candidate].label, parentLabel) == 0) {
                    treeParent = candidate;
                    break;
                }
            }
        }

        int destination = -1;
        for (int candidate = 1; candidate < treeEntries.Num(); ++candidate) {
            if (treeEntries[candidate].parent == treeParent
                    && (treeEntries[candidate].label == source.label
                        || std::strcmp(treeEntries[candidate].label, source.label) == 0)) {
                destination = candidate;
                break;
            }
        }
        if (destination < 0) {
            treeEntry_t* const entry = treeEntries.Alloc();
            if (entry == nullptr) break;
            destination = treeEntries.Num() - 1;
            entry->label = source.label;
            entry->depth = treeEntries[treeParent].depth + 1;
            entry->parent = treeParent;
            entry->firstChild = -1;
            entry->nextChild = treeEntries[treeParent].firstChild;
            treeEntries[treeParent].firstChild = destination;
        }
        treeEntry_t& entry = treeEntries[destination];
        const std::int64_t adjusted = std::max<std::int64_t>(0,
            source.totalTicks - adjustByTicks);
        entry.totalTicks += adjusted;
        ++entry.numHits;
        root->totalTicks += adjusted;
    }

    if (thresholdMS > 0.0f) {
        // Keep the recovered table intact; the threshold only controls output.
    }
    return TicksToMilliseconds(root->totalTicks);
}

void idPLog::ShowUniqueEntries(const float thresholdMS,
        const std::int64_t adjustByTicks) {
    BuildLogData(thresholdMS, adjustByTicks);
    for (int index = 1; index < treeEntries.Num(); ++index) {
        const treeEntry_t& entry = treeEntries[index];
        const float milliseconds = TicksToMilliseconds(entry.totalTicks);
        if (milliseconds >= thresholdMS) {
            std::printf("%-40s %6d %10.3f ms\n", entry.label,
                entry.numHits, milliseconds);
        }
    }
}

void idPLog::ShowCallGraph(const float thresholdMS,
        const std::int64_t adjustByTicks) {
    BuildLogData(thresholdMS, adjustByTicks);
    for (int index = 1; index < treeEntries.Num(); ++index) {
        const treeEntry_t& entry = treeEntries[index];
        const float milliseconds = TicksToMilliseconds(entry.totalTicks);
        if (milliseconds >= thresholdMS) {
            std::printf("%*s%s: %.3f ms (%d)\n", entry.depth * 2, "",
                entry.label, milliseconds, entry.numHits);
        }
    }
}

idPLogScope::idPLogScope(idPLog& log, const std::uint64_t mask,
        const char* label)
    : logIndex(-1), pLog(&log) {
    if (!log.IsGroupEnabled(mask)) return;
    idPLog::logEntry_t* const entry = log.logEntries.Alloc();
    if (entry == nullptr) return;
    entry->label = label == nullptr ? "<unnamed>" : label;
    entry->parent = log.lastEntry;
    entry->totalTicks = ClockTicks();
    logIndex = log.logEntries.Num() - 1;
    log.lastEntry = logIndex;
}

idPLogScope::~idPLogScope() {
    End();
}

void idPLogScope::End(std::int64_t* totalTicks) {
    if (logIndex < 0 || pLog == nullptr) return;
    idPLog::logEntry_t& entry = pLog->logEntries[logIndex];
    entry.totalTicks = ClockTicks() - entry.totalTicks;
    if (totalTicks != nullptr) *totalTicks = entry.totalTicks;
    pLog->lastEntry = entry.parent;
    logIndex = -1;
}
