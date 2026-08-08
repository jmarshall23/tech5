#pragma once

#include "idlib/text/str.h"

#include <cstdint>

struct idMetricFile {
    idMetricFile() : fileHandle(nullptr), headerWritten(false), startTime(0) {}
    void WriteFileInfo(const idStr& metricName);

    void* fileHandle;
    bool headerWritten;
    std::uint64_t startTime;
};

class idMetricRecord {
public:
    explicit idMetricRecord(const idStr& recordName);
    virtual ~idMetricRecord() = default;

    virtual void WriteHeader(idMetricFile* metricFile);
    virtual void SerializeEntry(idMetricFile* metricFile);

    void AppendToName(const idStr& suffix);
    void Serialize();
    const idStr& GetName() const { return name; }

protected:
    idStr name;
    idStr baseName;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idMetricFile) == 16, "Recovered idMetricFile ABI changed");
static_assert(sizeof(idMetricRecord) == 68,
    "Recovered idMetricRecord ABI changed");
#endif

