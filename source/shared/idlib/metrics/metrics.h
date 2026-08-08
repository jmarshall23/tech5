#pragma once

#include "metricrecord.h"

class idGaugeMetric : public idMetricRecord {
public:
    idGaugeMetric(const idStr& shortName, const idStr& description = idStr());

    bool CheckPushState();
    void Log(float value, bool skipPush = false);
    void WriteHeader(idMetricFile* metricFile) override;
    void SerializeEntry(idMetricFile* metricFile) override;

    int GetCount() const { return count; }
    float GetMin() const { return min; }
    float GetMax() const { return max; }
    float GetMean() const { return mean; }

private:
    int count;
    float min;
    float max;
    float mean;
    float mean2;
    float m2;
    int handle;
    int lastPushFrame;
    int gameState;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idGaugeMetric) == 104,
    "Recovered idGaugeMetric ABI changed");
#endif

