#pragma once

#include "metricrecord.h"

class idMetricsFramework {
public:
    class MachineInfo : public idMetricRecord {
    public:
        MachineInfo();
        void WriteHeader(idMetricFile* metricFile) override;
        void SerializeEntry(idMetricFile* metricFile) override;
    };

    idMetricsFramework();
    ~idMetricsFramework();

    std::uint64_t GetCurrentSystemTime() const;
    int GetPushFrame();
    void MetricsRecord();
    void MetricsStop();
    idMetricFile* GetFileHandle(const idStr& filename);
    bool IsRecording() const { return isRecording; }
    void SetOutputDirectory(const char* directory);
    void SetHeartbeatMilliseconds(int milliseconds);

private:
    void OpenMetricFile(const idStr& filename, idMetricFile& metricFile);

    std::uint64_t currentPushTime;
    std::uint64_t currentWriteTime;
    int currentPushFrame;
    int lastCheckedPushFrame;
    int currentState;
    int baseHandle;
    bool isRecording;

    struct recoveredHashTable_t {
        void** heads;
        int tableSize;
        int numEntries;
        int tableSizeMask;
    } fileTable;
    idMetricFile stateStream;
};

extern idMetricsFramework metricsFrameworkLocal;

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idMetricsFramework::MachineInfo) == 68,
    "Recovered MachineInfo ABI changed");
static_assert(sizeof(idMetricsFramework) == 72,
    "Recovered idMetricsFramework ABI changed");
#endif

