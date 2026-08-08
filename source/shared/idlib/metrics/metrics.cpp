#include "metrics.h"

#include "metricsframework.h"

#include <cmath>
#include <cstdio>
#include <cstring>

namespace {

FILE* MetricStream(idMetricFile* metricFile) {
    return metricFile == nullptr ? nullptr
        : static_cast<FILE*>(metricFile->fileHandle);
}

void WriteU32(FILE* stream, const std::uint32_t value) {
    std::fwrite(&value, 1, sizeof(value), stream);
}

void WriteFloat(FILE* stream, const float value) {
    std::fwrite(&value, 1, sizeof(value), stream);
}

void WriteString(FILE* stream, const char* text) {
    const std::uint32_t length = static_cast<std::uint32_t>(std::strlen(text));
    WriteU32(stream, length);
    std::fwrite(text, 1, length, stream);
}

} // namespace

idGaugeMetric::idGaugeMetric(const idStr& shortName, const idStr&)
    : idMetricRecord(shortName), count(0), min(0.0f), max(0.0f), mean(0.0f),
      mean2(0.0f), m2(0.0f), handle(-1), lastPushFrame(0), gameState(-1) {
}

bool idGaugeMetric::CheckPushState() {
    const int pushFrame = metricsFrameworkLocal.GetPushFrame();
    if (pushFrame <= lastPushFrame || count == 0) return false;
    Serialize();
    lastPushFrame = pushFrame;
    count = 0;
    min = max = mean = mean2 = m2 = 0.0f;
    return true;
}

void idGaugeMetric::Log(const float value, const bool skipPush) {
    if (count == 0) min = max = value;
    else {
        if (value < min) min = value;
        if (value > max) max = value;
    }
    const float delta = value - mean;
    ++count;
    mean += delta / static_cast<float>(count);
    m2 += delta * (value - mean);
    mean2 += value * value;
    if (!skipPush) CheckPushState();
}

void idGaugeMetric::WriteHeader(idMetricFile* metricFile) {
    FILE* const stream = MetricStream(metricFile);
    if (stream == nullptr) return;
    idMetricRecord::WriteHeader(metricFile);
    WriteU32(stream, 5);
    const char* const names[] = { "count", "min", "max", "mean", "stdDev" };
    for (int index = 0; index < 5; ++index) {
        WriteString(stream, names[index]);
        WriteU32(stream, index == 0 ? 0u : 1u);
    }
}

void idGaugeMetric::SerializeEntry(idMetricFile* metricFile) {
    FILE* const stream = MetricStream(metricFile);
    if (stream == nullptr) return;
    idMetricRecord::SerializeEntry(metricFile);
    WriteU32(stream, static_cast<std::uint32_t>(count));
    WriteFloat(stream, min);
    WriteFloat(stream, max);
    WriteFloat(stream, mean);
    WriteFloat(stream, count > 0 ? std::sqrt(mean2 / count) : 0.0f);
}

